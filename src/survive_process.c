//<>< (C) 2016 C. N. Lohr, FULLY Under MIT/x11 License.
//All MIT/x11 Licensed Code in this file may be relicensed freely under the GPL or LGPL licenses.

#include "survive_cal.h"
#include "survive_config.h"
#include "survive_default_devices.h"
#include "survive_playback.h"
#include <assert.h>
#include <survive.h>

#include "string.h"
#include "survive_str.h"

//XXX TODO: Once data is avialble in the context, use the stuff here to handle converting from time codes to
//proper angles, then from there perform the rest of the solution. 

#define TIMECENTER_TICKS (48000000/240) //for now.

void survive_ootx_behavior(SurviveObject *so, int8_t bsd_idx, int8_t lh_version, bool ootx);

void survive_default_light_process( SurviveObject * so, int sensor_id, int acode, int timeinsweep, uint32_t timecode, uint32_t length, uint32_t lh)
{
	lh = survive_get_bsd_idx(so->ctx, lh);

	survive_notify_gen1(so, "Lightcap called");

	SurviveContext * ctx = so->ctx;
	int base_station = lh;
	int axis = acode & 1;

	if (sensor_id == -1 || sensor_id == -2) {
		uint8_t dbit = (acode & 2) >> 1;
		survive_ootx_behavior(so, lh, ctx->lh_version, dbit);
	}

	if (ctx->calptr && ctx->bsd[lh].OOTXSet) {
		survive_cal_light( so, sensor_id, acode, timeinsweep, timecode, length, lh);
	}

	survive_recording_light_process(so, sensor_id, acode, timeinsweep, timecode, length, lh);

	//We don't use sync times, yet.
	if (sensor_id <= -1) {
		if (so->PoserFn) {
			PoserDataLightGen1 l = {
				.common =
					{
						.hdr =
							{
								.pt = POSERDATA_SYNC,
								.timecode = SurviveSensorActivations_long_timecode_light(&so->activations, timecode),
							},
						.sensor_id = sensor_id,
						.angle = 0,
						.lh = lh,
					},
				.acode = acode,
				.length = length,
			};
			so->PoserFn(so, (PoserData *)&l);
		}
		return;
	}

	if (base_station > NUM_GEN1_LIGHTHOUSES)
		return;

	//No loner need sync information past this point.
	if( sensor_id < 0 ) return;

	if (timeinsweep > 2 * TIMECENTER_TICKS) {
		SV_WARN("Disambiguator gave invalid timeinsweep %s %u", so->codename, timeinsweep);
		return;
	}

	int centered_timeinsweep = (timeinsweep - TIMECENTER_TICKS);
	FLT angle = centered_timeinsweep * (1. / TIMECENTER_TICKS * 3.14159265359 / 2.0);
	assert(angle >= -LINMATHPI && angle <= LINMATHPI);

	FLT length_sec = length / (FLT)so->timebase_hz;
	ctx->angleproc( so, sensor_id, acode, timecode, length_sec, angle, lh);
}


void survive_default_angle_process( SurviveObject * so, int sensor_id, int acode, uint32_t timecode, FLT length, FLT angle, uint32_t lh)
{
	survive_notify_gen1(so, "Default angle called");
	SurviveContext *ctx = so->ctx;

	PoserDataLightGen1 l = {
		.common =
			{
				.hdr =
					{
						.pt = POSERDATA_LIGHT,
						.timecode = SurviveSensorActivations_long_timecode_light(&so->activations, timecode),
					},
				.sensor_id = sensor_id,
				.angle = angle,
				.lh = lh,
			},
		.acode = acode,
		.length = length,
	};

	// Simulate the use of only one lighthouse in playback mode.
	if (lh < ctx->activeLighthouses)
		SurviveSensorActivations_add(&so->activations, &l);

	survive_recording_angle_process(so, sensor_id, acode, timecode, length, angle, lh);

	if (ctx->calptr) {
		survive_cal_angle(so, sensor_id, acode, timecode, length, angle, lh);
	}
	if (so->PoserFn) {
		so->PoserFn( so, (PoserData *)&l );
	}
}

void survive_default_lightcap_process(SurviveObject *so, const LightcapElement *le) {
	survive_notify_gen1(so, "Lightcap called");
}

void survive_default_button_process(SurviveObject * so, uint8_t eventType, uint8_t buttonId, uint8_t axis1Id, uint16_t axis1Val, uint8_t axis2Id, uint16_t axis2Val)
{
}

void survive_default_pose_process(SurviveObject *so, uint32_t timecode, SurvivePose *pose) {
	so->OutPose = *pose;
	so->OutPose_timecode = timecode;
	survive_recording_raw_pose_process(so, timecode, pose);
}
void survive_default_velocity_process(SurviveObject *so, uint32_t timecode, const SurviveVelocity *velocity) {
	survive_recording_velocity_process(so, timecode, velocity);
	so->velocity = *velocity;
	so->velocity_timecode = timecode;
}

void survive_default_external_velocity_process(SurviveContext *ctx, const char *name, const SurviveVelocity *vel) {
	survive_recording_external_velocity_process(ctx, name, vel);
}
void survive_default_external_pose_process(SurviveContext *ctx, const char *name, const SurvivePose *pose) {
	survive_recording_external_pose_process(ctx, name, pose);
}

void survive_default_lighthouse_pose_process(SurviveContext *ctx, uint8_t lighthouse, SurvivePose *lighthouse_pose,
											 SurvivePose *object_pose) {
	if (lighthouse_pose) {
		ctx->bsd[lighthouse].Pose = *lighthouse_pose;
		ctx->bsd[lighthouse].PositionSet = 1;
	} else {
		ctx->bsd[lighthouse].PositionSet = 0;
	}

	config_set_lighthouse(ctx->lh_config, &ctx->bsd[lighthouse], lighthouse);
	config_save(ctx, survive_configs(ctx, "configfile", SC_GET, "config.json"));

	survive_recording_lighthouse_process(ctx, lighthouse, lighthouse_pose, object_pose);
	SV_INFO("Position found for LH %d(%08x)", lighthouse, ctx->bsd[lighthouse].BaseStationID);
}

int survive_default_config_process(SurviveObject *so, char *ct0conf, int len) {
	survive_recording_config_process(so, ct0conf, len);
	so->conf = ct0conf;
	so->conf_cnt = len;

	if (survive_configi(so->ctx, "serialize-device-config", SC_GET, 0) != 0) {
		char raw_fname[128];
		sprintf(raw_fname, "%s_config.json", so->codename);
		FILE *f = fopen(raw_fname, "w");
		fwrite(ct0conf, len, 1, f);
		fclose(f);
	}

	return survive_load_htc_config_format(so, ct0conf, len);
}

SURVIVE_EXPORT char *survive_export_config(SurviveObject *so) {
	cstring str = {0};
	str_append(&str, "{\n");
	str_append(&str, "    \"device_class\": \"generic_tracker\",\n");
	str_append(&str, "    \"imu\": {\n");
	str_append_printf(&str, "        \"acc_bias\": [ %f, %f, %f], \n", LINMATH_VEC3_EXPAND(so->acc_bias));
	str_append_printf(&str, "        \"acc_scale\": [ %f, %f, %f], \n", LINMATH_VEC3_EXPAND(so->acc_scale));
	str_append_printf(&str, "        \"gyro_bias\": [ %f, %f, %f], \n", LINMATH_VEC3_EXPAND(so->gyro_bias));
	str_append_printf(&str, "        \"gyro_scale\": [ %f, %f, %f], \n", LINMATH_VEC3_EXPAND(so->gyro_scale));
	str_append_printf(&str, "        \"position\": [ %f, %f, %f], \n", LINMATH_VEC3_EXPAND(so->imu2trackref.Pos));
	str_append(&str, "    }\n");
	str_append(&str, "    \"lighthouse_config\": {\n");
	str_append(&str, "        \"channelMap\": [\n");
	if (so->channel_map) {
		for (int i = 0; i < so->sensor_ct; i++) {
			str_append_printf(&str, "            %d,\n", so->channel_map[i]);
		}
	} else {
		for (int i = 0; i < so->sensor_ct; i++) {
			str_append_printf(&str, "            %d,\n", i);
		}
	}
	str_append(&str, "        ],\n");
	str_append(&str, "        \"modelNormals\": [\n");
	for (int i = 0; i < so->sensor_ct; i++) {
		str_append_printf(&str, "            [  %f, %f, %f ], \n", LINMATH_VEC3_EXPAND(so->sensor_normals + i * 3));
	}
	str_append(&str, "        ],\n");
	str_append(&str, "        \"modelPoints\": [\n");
	for (int i = 0; i < so->sensor_ct; i++) {
		str_append_printf(&str, "            [ %f, %f, %f ], \n", LINMATH_VEC3_EXPAND(so->sensor_locations + i * 3));
	}
	str_append(&str, "        ]\n");
	str_append(&str, "    }\n");
	str_append(&str, "}\n");

	return str.d;
}

// https://github.com/ValveSoftware/openvr/wiki/ImuSample_t
static void calibrate_acc(SurviveObject *so, FLT *agm) {
	agm[0] -= so->acc_bias[0];
	agm[1] -= so->acc_bias[1];
	agm[2] -= so->acc_bias[2];

	agm[0] *= so->acc_scale[0];
	agm[1] *= so->acc_scale[1];
	agm[2] *= so->acc_scale[2];
}

static void calibrate_gyro(SurviveObject *so, FLT *agm) {
	agm[0] -= so->gyro_bias[0];
	agm[1] -= so->gyro_bias[1];
	agm[2] -= so->gyro_bias[2];

	agm[0] *= so->gyro_scale[0];
	agm[1] *= so->gyro_scale[1];
	agm[2] *= so->gyro_scale[2];
}

void survive_default_raw_imu_process(SurviveObject *so, int mask, FLT *accelgyromag, uint32_t timecode, int id) {
	SurviveContext *ctx = so->ctx;

	FLT agm[9] = {0};
	memcpy(agm, accelgyromag, sizeof(FLT) * 9);

	calibrate_acc(so, agm);
	calibrate_gyro(so, agm + 3);

	static FLT accum[3] = {0};
	static survive_timecode start = 0;
	static uint32_t cnt = 0.;

	survive_timecode stationary_time = SurviveSensorActivations_stationary_time(&so->activations);
	FLT n = norm3d(agm);

	if (stationary_time > so->timebase_hz / 2 && n > .95 && n < 1.05) {
		scale3d(so->acc_scale, so->acc_scale, 1. / n);

		FLT gerr = norm3d(accelgyromag + 3);
		/*
		FLT gcorrect[3];
		scale3d(gcorrect, accelgyromag + 3, .1);
		scale3d(so->gyro_bias, so->gyro_bias, .9);
		add3d(so->gyro_bias, so->gyro_bias, gcorrect);
*/
		if (norm3d(accum) != 0.) {
			survive_timecode end = timecode;
			FLT seconds = (end - start) / (FLT)so->timebase_hz;
			scale3d(accum, accum, 1. / (FLT)cnt * seconds);
			// SV_VERBOSE(100, "%s accum %fsec " Point3_format, so->codename, seconds, LINMATH_VEC3_EXPAND(accum));
		}
		scale3d(accum, accum, 0);
		cnt = 0;
		start = timecode;
		// SV_VERBOSE(200, "%s acc adjust %f %f gyro %f " Point3_format, so->codename, n, 1. / n, gerr,
		// LINMATH_VEC3_EXPAND(so->gyro_bias));
	} else {
		add3d(accum, agm + 3, accum);
		cnt++;
	}

	survive_recording_raw_imu_process(so, mask, accelgyromag, timecode, id);

	so->ctx->imuproc(so, 3, agm, timecode, id);
}
void survive_default_imu_process( SurviveObject * so, int mask, FLT * accelgyromag, uint32_t timecode, int id )
{
	PoserDataIMU imu = {
		.hdr =
			{
				.pt = POSERDATA_IMU,
				.timecode = SurviveSensorActivations_long_timecode_imu(&so->activations, timecode),
			},
		.datamask = mask,
		.accel = {accelgyromag[0], accelgyromag[1], accelgyromag[2]},
		.gyro = {accelgyromag[3], accelgyromag[4], accelgyromag[5]},
		.mag = {accelgyromag[6], accelgyromag[7], accelgyromag[8]},
	};

	SurviveSensorActivations_add_imu(&so->activations, &imu);

	if (so->PoserFn) {
		so->PoserFn( so, (PoserData *)&imu );
	}

	survive_recording_imu_process(so, mask, accelgyromag, timecode, id);
}

