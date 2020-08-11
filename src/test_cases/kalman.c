#include "../survive_imu.h"
#include "test_case.h"
#include <math.h>
#include <minimal_opencv.h>
#include <stdio.h>
#include <stdlib.h>

#include "../generated/survive_imu.generated.h"
#include "malloc.h"

static void rot_predict_quat(FLT t, const survive_kalman_state_t *k, const CvMat *f_in, CvMat *f_out) {
	(void)k;

	const FLT *rot = CV_FLT_PTR(f_in);
	const FLT *vel = CV_FLT_PTR(f_in) + 4;
	copy3d(CV_FLT_PTR(f_out) + 4, vel);

	survive_apply_ang_velocity(CV_FLT_PTR(f_out), vel, t, rot);
}

static void rot_f_quat(FLT t, FLT *F, const struct CvMat *x) {
	(void)x;

	// assert(fabs(t) < .1 && t >= 0);
	if (fabs(t) > .11)
		t = .11;

	// fprintf(stderr, "F eval: %f " SurvivePose_format "\n", t, SURVIVE_POSE_EXPAND(*(SurvivePose*)x->data.db));
	gen_imu_rot_f_jac_imu_rot(F, t, CV_FLT_PTR(x));

	for (int j = 0; j < 49; j++) {
		assert(!isnan(F[j]));
	}
}

static const double two_pi = 2.0 * 3.14159265358979323846;

static double CDF(double x, double sigma) {
	if (sigma == 0)
		return (x) == 0.0 ? 0.5 : 0.;
	return (1. + erf((x) / sigma / sqrt(2.))) / 2.;
}

// https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform
static double generateGaussianNoise(double mu, double sigma) {
	static const double epsilon = 0.0000001;

	static double z1;
	static bool generate;
	generate = !generate;

	if (!generate)
		return z1 * sigma + mu;

	double u1, u2;
	do {
		u1 = rand() * (1.0 / RAND_MAX);
		u2 = rand() * (1.0 / RAND_MAX);
	} while (u1 <= epsilon);

	double z0;
	z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
	z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
	return z0 * sigma + mu;
}

static SurvivePose randomMovement(const SurvivePose *start, FLT pvariance, FLT rvariance) {
	SurvivePose rtn = *start;
	for (int i = 0; i < 3; i++)
		rtn.Pos[i] += generateGaussianNoise(0, pvariance);
	for (int i = 0; i < 4; i++)
		rtn.Rot[i] += generateGaussianNoise(0, rvariance);

	return rtn;
}

static SurviveVelocity randomVelocity(FLT pvariance, FLT rvariance) {
	SurviveVelocity rtn = {0};
	for (int i = 0; i < 3; i++)
		rtn.Pos[i] += generateGaussianNoise(0, pvariance);
	for (int i = 0; i < 3; i++)
		rtn.AxisAngleRot[i] += generateGaussianNoise(0, rvariance);

	return rtn;
}

static void survive_apply_velocity(SurvivePose *p_1, FLT t, const SurvivePose *p_0, const SurviveVelocity *vel) {
	LinmathVec3d posDisplacement;
	scale3d(posDisplacement, vel->Pos, t);

	add3d(p_1->Pos, p_0->Pos, posDisplacement);

	survive_apply_ang_velocity(p_1->Rot, vel->AxisAngleRot, t, p_0->Rot);
}

int TestKalmanIntegratePose(FLT pvariance, FLT rot_variance) {
	SurviveIMUTracker kpose = { 0 };
	SurviveObject so = {.timebase_hz = 48000000};
	survive_imu_tracker_init(&kpose, &so);
	SurvivePose pose = LinmathPose_Identity;

	srand(42);

	const FLT mvariance = 0.5;
	const FLT rot_movement = 0.01;

	LinmathVec3d pos_variance = {pvariance, pvariance, pvariance};

	SurviveVelocity vel = randomVelocity(mvariance, rot_movement);
	LinmathQuat qq;
	quatfromaxisanglemag(qq, vel.AxisAngleRot);

	survive_timecode time = 0;
	survive_timecode ticks_per_second = 4800000;
	for (int i = 0; i < 100; i++) {
		time += ticks_per_second;

		survive_apply_velocity(&pose, ticks_per_second / (FLT)so.timebase_hz, &pose, &vel);

		SurvivePose obs = randomMovement(&pose, 0 * pvariance, 0 * rot_variance);

		FLT variance[2] = {pvariance, rot_variance};
		survive_imu_tracker_integrate_observation(time, &kpose, &obs, variance);

		SurvivePose estimate;
		SurviveVelocity estimate_v = survive_imu_velocity(&kpose);
		survive_imu_tracker_predict(&kpose, time, &estimate);

		printf("Observation " SurvivePose_format "\n", SURVIVE_POSE_EXPAND(obs));
		printf("Actual      " SurvivePose_format " " SurviveVel_format "\n", SURVIVE_POSE_EXPAND(pose),
			   SURVIVE_VELOCITY_EXPAND(vel));
		printf("Estimate    " SurvivePose_format " " SurviveVel_format "\n\n", SURVIVE_POSE_EXPAND(estimate),
			   SURVIVE_VELOCITY_EXPAND(estimate_v));

		double acceptable_cdf = CDF(-3, pvariance);
		for (int i = 0; i < 3; i++) {
			double cdf = fabs(0.5 - CDF(fabs(estimate.Pos[i] - pose.Pos[i] + 10000), pvariance));
			// printf("CDF %f %f\n", cdf, acceptable_cdf);
			ASSERT_GT(cdf, acceptable_cdf);
		}
	}

	survive_imu_tracker_free(&kpose);

	return 0;
}
/*
TEST(Kalman, Exact) {
	const FLT pvariance = 0.0000000001;
	const FLT rot_variance = 0.01;
	return TestKalmanIntegratePose(pvariance, rot_variance);
}

TEST(Kalman, Inexact) {
	const FLT pvariance = 1.;
	const FLT rot_variance = 0.01;
	return TestKalmanIntegratePose(pvariance, rot_variance);
}
*/
#include "string.h"

static void pos_f(FLT t, FLT *F, const struct CvMat *x) {
	(void)x;
	t = 1;
	FLT f[36] = {
		1, 0, 0, t, 0, 0, 0, 1, 0, 0, t, 0, 0, 0, 1, 0, 0, t, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
	};
	memcpy(F, f, sizeof(f));
}

void meas_model(FLT t, struct CvMat *Z, const struct CvMat *x_t, const FLT *s) {
	FLT *_h_x = CV_FLT_PTR(Z);
	FLT *xt = CV_FLT_PTR(x_t);

	LinmathPoint3d d;

	sub3d(d, xt, s);
	// fprintf(stderr, Point3_format "\n", LINMATH_VEC3_EXPAND(d));
	_h_x[0] = atan2(d[0], d[1]);
	_h_x[1] = atan2(d[2], sqrt(d[0] * d[0] + d[1] * d[1]));
	_h_x[2] = norm3d(d);
}

static inline void mat_eye(CvMat *m, FLT v) {
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			CV_FLT_PTR(m)[j * m->cols + i] = i == j ? v : 0.;
		}
	}
}

void map_to_obs(void *user, FLT t, const struct CvMat *Z, const struct CvMat *x_t, struct CvMat *yhat,
				struct CvMat *H_k) {

	const FLT *s = (FLT *)user;
	CREATE_STACK_MAT(h_x_t, 3, 1);
	meas_model(t, &h_x_t, x_t, s);

	CREATE_STACK_MAT(Id, 3, 3);
	mat_eye(&Id, 1);
	cvGEMM(&Id, Z, 1., &h_x_t, -1, yhat, 0);

	FLT *xt = CV_FLT_PTR(x_t);
	LinmathPoint3d d;
	sub3d(d, xt, s);

	FLT *H = CV_FLT_PTR(H_k);
	FLT x = d[0], y = d[1], z = d[2];
	FLT n2 = (x * x + y * y + z * z);
	FLT n = sqrtf(n2);

	memset(H, 0, sizeof(FLT) * 3 * 6);
	H[0] = y / (x * x + y * y);
	H[1] = -x / (x * x + y * y);
	H[2] = 0;
	H[6] = -x * z / n2 / sqrtf(x * x + y * y);
	H[7] = -y * z / n2 / sqrtf(x * x + y * y);
	H[8] = 1. / sqrtf(x * x + y * y);
	H[12] = x / n;
	H[13] = y / n;
	H[14] = z / n;
}

static inline void mat_eye_diag(CvMat *m, const FLT *v) {
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			CV_FLT_PTR(m)[j * m->cols + i] = i == j ? v[i] : 0.;
		}
	}
}

// https://www.intechopen.com/books/introduction-and-implementations-of-the-kalman-filter/introduction-to-kalman-filter-and-its-applications
TEST(Kalman, ExampleExtended) {
	// survive_kalman_set_logging_level(1000);

	survive_kalman_state_t position;

	FLT pos_Q_per_sec[36] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 25,
	};
	FLT P_init[6] = {1, 1, 1, 0, 0, 0};

	survive_kalman_state_init(&position, 6, pos_f, pos_Q_per_sec, 0, 0);
	CvMat P = cvMat(6, 6, SURVIVE_CV_F, position.info.P);
	mat_eye_diag(&P, P_init);

	FLT _F[36];
	pos_f(1, _F, 0);
	CvMat F = cvMat(6, 6, SURVIVE_CV_F, _F);

	FLT _true_state[] = {9, -12, 0, -1, -2, 0};
	CvMat true_state = cvMat(6, 1, SURVIVE_CV_F, _true_state);

	FLT _init_state[] = {10, -10, 0, -1, -2, 0};
	memcpy(position.state, _init_state, sizeof(_true_state));

	position.state[0] += generateGaussianNoise(0, 1);
	position.state[1] += generateGaussianNoise(0, 1);

	FLT meas_s[] = {.002, .002, .002};
	CREATE_STACK_MAT(Z, 3, 1);

	for (int i = 1; i < 21; i++) {
		LinmathPoint3d sensor = {20 + 20 * cos(2. * LINMATHPI / 30 * (i)), 20 + 20 * sin(2. * LINMATHPI / 30 * (i)),
								 50};

		meas_model(i, &Z, &true_state, sensor);

		fprintf(stderr, "z_true " Point3_format "\n", LINMATH_VEC3_EXPAND(_Z));

		for (int j = 0; j < 3; j++) {
			_Z[j] += generateGaussianNoise(0, meas_s[j]);
		}

		FLT R[] = {.0004, .0004, 1};
		survive_kalman_predict_update_state_extended(i, &position, &Z, R, map_to_obs, sensor);

		fprintf(stderr, "Guess  " SurviveVel_format "\n", SURVIVE_VELOCITY_EXPAND(*(SurviveVelocity *)position.state));
		fprintf(stderr, "GT     " SurviveVel_format "\n", SURVIVE_VELOCITY_EXPAND(*(SurviveVelocity *)_true_state));
		fprintf(stderr, "Sensor " Point3_format "\n", LINMATH_VEC3_EXPAND(sensor));

		FLT _next_state[6];
		CvMat next_state = cvMat(6, 1, SURVIVE_CV_F, _next_state);
		// SURVIVE_LOCAL_ONLY void cvGEMM(const CvMat *src1, const CvMat *src2, double alpha, const CvMat *src3, double
		// beta,
		cvGEMM(&F, &true_state, 1, 0, 0, &next_state, 0);
		memcpy(_true_state, _next_state, sizeof(_true_state));
	}

	survive_kalman_state_free(&position);
	return 0;
}

TEST(Kalman, AngleQuat) {
	// survive_kalman_set_logging_level(1000);
	survive_kalman_state_t rotation;

	FLT av = 1e0, vv = 1e0;
	FLT pos_Q_per_sec[49] = {
		av, 0, 0, 0, 0, 0, 0, 0,  av, 0, 0, 0, 0, 0, 0, 0,	av, 0, 0, 0, 0, 0, 0, 0,  av,
		0,	0, 0, 0, 0, 0, 0, vv, 0,  0, 0, 0, 0, 0, 0, vv, 0,	0, 0, 0, 0, 0, 0, vv,
	};

	extern void rot_f_quat(FLT t, FLT * F, const struct CvMat *x);
	extern void rot_predict_quat(FLT t, const survive_kalman_state_t *k, const CvMat *f_in, CvMat *f_out);
	survive_kalman_state_init(&rotation, 7, rot_f_quat, pos_Q_per_sec, 0, 0);
	rotation.info.Predict_fn = rot_predict_quat;

	FLT P_init[] = {1, 1, 1, 1, 1, 1, 1};
	survive_kalman_set_P(&rotation, P_init);

	CREATE_STACK_MAT(true_state, 7, 1);
	FLT true_state_init[7] = {1, 0, 0, 0, 1, 1, -1};
	memcpy(_true_state, true_state_init, sizeof(true_state_init));
	memcpy(rotation.state, true_state_init, sizeof(true_state_init));

	CREATE_STACK_MAT(Z, 4, 1);

	FLT _H[] = {
		1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	};
	CvMat H = cvMat(4, 7, SURVIVE_CV_F, _H);

	for (int i = 1; i < 100; i++) {
		FLT t = i * .1;

		FLT rv = .0;
		FLT R[] = {rv, rv, rv, rv};
		memcpy(_Z, _true_state, sizeof(4) * sizeof(FLT));
		for (int j = 0; j < 4; j++) {
			_Z[j] += generateGaussianNoise(0, R[j]);
		}
		quatnormalize(_Z, _Z);
		survive_kalman_predict_update_state(t, &rotation, &Z, &H, R);
		quatnormalize(rotation.state, rotation.state);
		fprintf(stderr, "Guess  " SurvivePose_format "\n", SURVIVE_POSE_EXPAND(*(SurvivePose *)rotation.state));
		fprintf(stderr, "GT     " SurvivePose_format "\n", SURVIVE_POSE_EXPAND(*(SurvivePose *)_true_state));

		rot_predict_quat(.1, 0, &true_state, &true_state);
	}

	survive_kalman_state_free(&rotation);
	return 0;
}
