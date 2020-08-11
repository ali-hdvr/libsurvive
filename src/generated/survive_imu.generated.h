#pragma once
#include "common.h"
/** Applying function <function quatrotatevector at 0x7fe08d8e2290> */
static inline void gen_quatrotatevector(FLT *out, const FLT *q, const FLT *pt) {
	const GEN_FLT obj_qw = q[0];
	const GEN_FLT obj_qi = q[1];
	const GEN_FLT obj_qj = q[2];
	const GEN_FLT obj_qk = q[3];
	const GEN_FLT pt_x = pt[0];
	const GEN_FLT pt_y = pt[1];
	const GEN_FLT pt_z = pt[2];
	const GEN_FLT x0 = (pt_x * obj_qk) + (-1 * pt_z * obj_qi) + (pt_y * obj_qw);
	const GEN_FLT x1 = (pt_y * obj_qi) + (-1 * pt_x * obj_qj) + (pt_z * obj_qw);
	const GEN_FLT x2 = (pt_z * obj_qj) + (-1 * pt_y * obj_qk) + (pt_x * obj_qw);
	out[0] = pt_x + (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk)));
	out[1] = pt_y + (2 * ((x2 * obj_qk) + (-1 * x1 * obj_qi)));
	out[2] = pt_z + (2 * ((x0 * obj_qi) + (-1 * x2 * obj_qj)));
}

// Jacobian of quatrotatevector wrt [obj_qw, obj_qi, obj_qj, obj_qk]
static inline void gen_quatrotatevector_jac_q(FLT *out, const FLT *q, const FLT *pt) {
	const GEN_FLT obj_qw = q[0];
	const GEN_FLT obj_qi = q[1];
	const GEN_FLT obj_qj = q[2];
	const GEN_FLT obj_qk = q[3];
	const GEN_FLT pt_x = pt[0];
	const GEN_FLT pt_y = pt[1];
	const GEN_FLT pt_z = pt[2];
	const GEN_FLT x0 = 2 * pt_y;
	const GEN_FLT x1 = x0 * obj_qk;
	const GEN_FLT x2 = 2 * pt_z;
	const GEN_FLT x3 = x2 * obj_qj;
	const GEN_FLT x4 = x2 * obj_qk;
	const GEN_FLT x5 = x0 * obj_qj;
	const GEN_FLT x6 = 2 * obj_qi;
	const GEN_FLT x7 = x6 * pt_y;
	const GEN_FLT x8 = pt_x * obj_qj;
	const GEN_FLT x9 = 2 * obj_qw;
	const GEN_FLT x10 = x9 * pt_z;
	const GEN_FLT x11 = pt_x * obj_qk;
	const GEN_FLT x12 = x6 * pt_z;
	const GEN_FLT x13 = x9 * pt_y;
	const GEN_FLT x14 = 2 * x11;
	const GEN_FLT x15 = 4 * pt_y;
	const GEN_FLT x16 = 2 * x8;
	const GEN_FLT x17 = x6 * pt_x;
	const GEN_FLT x18 = x9 * pt_x;
	const GEN_FLT x19 = 4 * pt_z;
	out[0] = x3 + (-1 * x1);
	out[1] = x5 + x4;
	out[2] = x10 + (-4 * x8) + x7;
	out[3] = (-1 * x13) + x12 + (-4 * x11);
	out[4] = x14 + (-1 * x12);
	out[5] = (-1 * x10) + x16 + (-1 * x15 * obj_qi);
	out[6] = x4 + x17;
	out[7] = x18 + (-1 * x15 * obj_qk) + x3;
	out[8] = x7 + (-1 * x16);
	out[9] = x13 + (-1 * x19 * obj_qi) + x14;
	out[10] = (-1 * x18) + x1 + (-1 * x19 * obj_qj);
	out[11] = x17 + x5;
}

// Jacobian of quatrotatevector wrt [pt_x, pt_y, pt_z]
static inline void gen_quatrotatevector_jac_pt(FLT *out, const FLT *q, const FLT *pt) {
	const GEN_FLT obj_qw = q[0];
	const GEN_FLT obj_qi = q[1];
	const GEN_FLT obj_qj = q[2];
	const GEN_FLT obj_qk = q[3];
	const GEN_FLT pt_x = pt[0];
	const GEN_FLT pt_y = pt[1];
	const GEN_FLT pt_z = pt[2];
	const GEN_FLT x0 = -2 * (obj_qk * obj_qk);
	const GEN_FLT x1 = 1 + (-2 * (obj_qj * obj_qj));
	const GEN_FLT x2 = 2 * obj_qw;
	const GEN_FLT x3 = x2 * obj_qk;
	const GEN_FLT x4 = 2 * obj_qi;
	const GEN_FLT x5 = x4 * obj_qj;
	const GEN_FLT x6 = x4 * obj_qk;
	const GEN_FLT x7 = x2 * obj_qj;
	const GEN_FLT x8 = -2 * (obj_qi * obj_qi);
	const GEN_FLT x9 = x2 * obj_qi;
	const GEN_FLT x10 = 2 * obj_qk * obj_qj;
	out[0] = x1 + x0;
	out[1] = x5 + (-1 * x3);
	out[2] = x7 + x6;
	out[3] = x3 + x5;
	out[4] = 1 + x0 + x8;
	out[5] = x10 + (-1 * x9);
	out[6] = x6 + (-1 * x7);
	out[7] = x9 + x10;
	out[8] = x1 + x8;
}

/** Applying function <function imu_rot_f at 0x7fe0bbb1e050> */
static inline void gen_imu_rot_f(FLT *out, const FLT time, const FLT *imu_rot) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT x0 = time * time;
	const GEN_FLT x1 = x0 * (aa_z * aa_z);
	const GEN_FLT x2 =
		(1e-20 < (((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x))))
			? sqrt(((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x)))
			: 1e-10;
	const GEN_FLT x3 = 0.5 * x2;
	const GEN_FLT x4 = sin(x3);
	const GEN_FLT x5 = (1. / (x2 * x2)) * (x4 * x4);
	const GEN_FLT x6 = x0 * (aa_y * aa_y);
	const GEN_FLT x7 = x0 * (aa_x * aa_x);
	const GEN_FLT x8 = cos(x3);
	const GEN_FLT x9 = 1. / sqrt((x8 * x8) + (x5 * x7) + (x6 * x5) + (x1 * x5));
	const GEN_FLT x10 = (1. / x2) * x4 * x9 * time;
	const GEN_FLT x11 = x10 * aa_z;
	const GEN_FLT x12 = x10 * aa_y;
	const GEN_FLT x13 = x10 * aa_x;
	const GEN_FLT x14 = x8 * x9;
	out[0] = (x14 * obj_qw) + (-1 * x13 * obj_qi) + (-1 * x12 * obj_qj) + (-1 * x11 * obj_qk);
	out[1] = (x14 * obj_qi) + (x13 * obj_qw) + (x12 * obj_qk) + (-1 * x11 * obj_qj);
	out[2] = (x14 * obj_qj) + (-1 * x13 * obj_qk) + (x12 * obj_qw) + (x11 * obj_qi);
	out[3] = (x14 * obj_qk) + (x13 * obj_qj) + (-1 * x12 * obj_qi) + (x11 * obj_qw);
	out[4] = aa_x;
	out[5] = aa_y;
	out[6] = aa_z;
}

// Jacobian of imu_rot_f wrt [time]
static inline void gen_imu_rot_f_jac_time(FLT *out, const FLT time, const FLT *imu_rot) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT x0 =
		(1e-20 < (((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x))))
			? sqrt(((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x)))
			: 1e-10;
	const GEN_FLT x1 = 0.5 * x0;
	const GEN_FLT x2 = cos(x1);
	const GEN_FLT x3 = time * time;
	const GEN_FLT x4 = aa_z * aa_z;
	const GEN_FLT x5 = x4 * x3;
	const GEN_FLT x6 = sin(x1);
	const GEN_FLT x7 = x6 * x6;
	const GEN_FLT x8 = 1. / (x0 * x0);
	const GEN_FLT x9 = x8 * x7;
	const GEN_FLT x10 = aa_y * aa_y;
	const GEN_FLT x11 = x3 * x10;
	const GEN_FLT x12 = aa_x * aa_x;
	const GEN_FLT x13 = x3 * x12;
	const GEN_FLT x14 = (x2 * x2) + (x9 * x13) + (x9 * x11) + (x5 * x9);
	const GEN_FLT x15 =
		(1e-20 < (((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x))))
			? (1.0 / 2.0 * ((2 * time * (aa_x * aa_x)) + (2 * time * (aa_y * aa_y)) + (2 * time * (aa_z * aa_z))) *
			   (1. / sqrt(((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) +
						  ((time * time) * (aa_x * aa_x)))))
			: 0;
	const GEN_FLT x16 = x6 * x15;
	const GEN_FLT x17 = 1.0 * x2 * x16;
	const GEN_FLT x18 = x8 * x17;
	const GEN_FLT x19 = 2 * time;
	const GEN_FLT x20 = x10 * x19;
	const GEN_FLT x21 = 2 * (1. / (x0 * x0 * x0)) * x7 * x15;
	const GEN_FLT x22 = x12 * x19;
	const GEN_FLT x23 = x4 * x19;
	const GEN_FLT x24 = 1.0 / 2.0 * (1. / (x14 * sqrt(x14))) *
						((x5 * x18) + (-1 * x21 * x13) + (x9 * x22) + (x9 * x23) + (-1 * x21 * x11) + (-1 * x17) +
						 (x11 * x18) + (-1 * x5 * x21) + (x9 * x20) + (x13 * x18));
	const GEN_FLT x25 = x2 * x24;
	const GEN_FLT x26 = 0.5 * x16;
	const GEN_FLT x27 = 1. / sqrt(x14);
	const GEN_FLT x28 = x27 * obj_qw;
	const GEN_FLT x29 = x27 * obj_qi;
	const GEN_FLT x30 = 1. / x0;
	const GEN_FLT x31 = x6 * x30;
	const GEN_FLT x32 = x31 * aa_x;
	const GEN_FLT x33 = 0.5 * x2 * x30 * x15;
	const GEN_FLT x34 = x33 * time;
	const GEN_FLT x35 = x34 * x29;
	const GEN_FLT x36 = x8 * x16;
	const GEN_FLT x37 = x27 * obj_qk;
	const GEN_FLT x38 = x37 * time;
	const GEN_FLT x39 = x38 * aa_z;
	const GEN_FLT x40 = x27 * obj_qj;
	const GEN_FLT x41 = x31 * aa_y;
	const GEN_FLT x42 = x31 * aa_z;
	const GEN_FLT x43 = x36 * aa_y;
	const GEN_FLT x44 = x43 * time;
	const GEN_FLT x45 = x24 * time;
	const GEN_FLT x46 = x45 * x32;
	const GEN_FLT x47 = x40 * x34;
	const GEN_FLT x48 = x42 * x45;
	const GEN_FLT x49 = x41 * x45;
	const GEN_FLT x50 = x36 * time;
	const GEN_FLT x51 = x50 * aa_x;
	const GEN_FLT x52 = x50 * aa_z;
	const GEN_FLT x53 = x34 * x28;
	const GEN_FLT x54 = x38 * aa_x;
	out[0] = (x51 * x29) + (-1 * x25 * obj_qw) + (-1 * x28 * x26) + (-1 * x32 * x29) + (x40 * x44) + (-1 * x35 * aa_x) +
			 (x48 * obj_qk) + (-1 * x47 * aa_y) + (x36 * x39) + (-1 * x33 * x39) + (-1 * x40 * x41) + (x49 * obj_qj) +
			 (-1 * x42 * x37) + (x46 * obj_qi);
	out[1] = (-1 * x40 * x42) + (x53 * aa_x) + (-1 * x51 * x28) + (-1 * x25 * obj_qi) + (-1 * x29 * x26) + (x52 * x40) +
			 (-1 * x47 * aa_z) + (-1 * x43 * x38) + (-1 * x49 * obj_qk) + (-1 * x46 * obj_qw) + (x41 * x37) +
			 (x32 * x28) + (x48 * obj_qj) + (x33 * x38 * aa_y);
	out[2] = (x54 * x36) + (x41 * x28) + (-1 * x40 * x26) + (-1 * x32 * x37) + (x42 * x29) + (-1 * x54 * x33) +
			 (x53 * aa_y) + (-1 * x48 * obj_qi) + (x35 * aa_z) + (x46 * obj_qk) + (-1 * x44 * x28) +
			 (-1 * x25 * obj_qj) + (-1 * x49 * obj_qw) + (-1 * x52 * x29);
	out[3] = (x47 * aa_x) + (-1 * x51 * x40) + (-1 * x46 * obj_qj) + (x42 * x28) + (-1 * x25 * obj_qk) + (x44 * x29) +
			 (-1 * x37 * x26) + (-1 * x48 * obj_qw) + (-1 * x52 * x28) + (x53 * aa_z) + (-1 * x35 * aa_y) +
			 (-1 * x41 * x29) + (x40 * x32) + (x49 * obj_qi);
	out[4] = 0;
	out[5] = 0;
	out[6] = 0;
}

// Jacobian of imu_rot_f wrt [obj_qw, obj_qi, obj_qj, obj_qk, aa_x, aa_y, aa_z]
static inline void gen_imu_rot_f_jac_imu_rot(FLT *out, const FLT time, const FLT *imu_rot) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT x0 = time * time;
	const GEN_FLT x1 = x0 * (aa_z * aa_z);
	const GEN_FLT x2 =
		(1e-20 < (((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x))))
			? sqrt(((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x)))
			: 1e-10;
	const GEN_FLT x3 = 0.5 * x2;
	const GEN_FLT x4 = sin(x3);
	const GEN_FLT x5 = x4 * x4;
	const GEN_FLT x6 = 1. / (x2 * x2);
	const GEN_FLT x7 = x6 * x5;
	const GEN_FLT x8 = x0 * (aa_y * aa_y);
	const GEN_FLT x9 = x0 * (aa_x * aa_x);
	const GEN_FLT x10 = cos(x3);
	const GEN_FLT x11 = (x10 * x10) + (x7 * x9) + (x8 * x7) + (x1 * x7);
	const GEN_FLT x12 = 1. / sqrt(x11);
	const GEN_FLT x13 = x12 * x10;
	const GEN_FLT x14 =
		(1e-20 < (((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x))))
			? 0
			: 0;
	const GEN_FLT x15 = 1.0 * x10;
	const GEN_FLT x16 = x4 * x15;
	const GEN_FLT x17 = x14 * x16;
	const GEN_FLT x18 = x6 * x9;
	const GEN_FLT x19 = x6 * x8;
	const GEN_FLT x20 = 2 * (1. / (x2 * x2 * x2)) * x5;
	const GEN_FLT x21 = x8 * x20;
	const GEN_FLT x22 = x9 * x20;
	const GEN_FLT x23 = x1 * x6;
	const GEN_FLT x24 = x1 * x20;
	const GEN_FLT x25 =
		(-1 * x24 * x14) + (x23 * x17) + (-1 * x22 * x14) + (-1 * x21 * x14) + (x19 * x17) + (x18 * x17) + (-1 * x17);
	const GEN_FLT x26 = 1.0 / 2.0 * (1. / (x11 * sqrt(x11)));
	const GEN_FLT x27 = x26 * x10;
	const GEN_FLT x28 = x27 * obj_qw;
	const GEN_FLT x29 = x4 * x12;
	const GEN_FLT x30 = x6 * time;
	const GEN_FLT x31 = x30 * x29;
	const GEN_FLT x32 = x31 * aa_z;
	const GEN_FLT x33 = x14 * obj_qk;
	const GEN_FLT x34 = (1. / x2) * time;
	const GEN_FLT x35 = x34 * aa_z;
	const GEN_FLT x36 = 0.5 * obj_qk;
	const GEN_FLT x37 = x36 * x13;
	const GEN_FLT x38 = x35 * x37;
	const GEN_FLT x39 = x14 * obj_qj;
	const GEN_FLT x40 = 0.5 * x13;
	const GEN_FLT x41 = x40 * x34;
	const GEN_FLT x42 = x41 * aa_y;
	const GEN_FLT x43 = x4 * x26;
	const GEN_FLT x44 = x43 * x25;
	const GEN_FLT x45 = x34 * aa_y;
	const GEN_FLT x46 = x44 * x45;
	const GEN_FLT x47 = x44 * obj_qk;
	const GEN_FLT x48 = x31 * aa_y;
	const GEN_FLT x49 = x31 * aa_x;
	const GEN_FLT x50 = x49 * x14;
	const GEN_FLT x51 = x34 * aa_x;
	const GEN_FLT x52 = x51 * obj_qi;
	const GEN_FLT x53 = x40 * x14;
	const GEN_FLT x54 = 0.5 * x29;
	const GEN_FLT x55 = x54 * x14;
	const GEN_FLT x56 = (-1 * x25 * x28) + (x32 * x33) + (x52 * x44) + (-1 * x55 * obj_qw) + (-1 * x42 * x39) +
						(x46 * obj_qj) + (-1 * x53 * x52) + (-1 * x38 * x14) + (x47 * x35) + (x48 * x39) +
						(x50 * obj_qi);
	const GEN_FLT x57 = x51 * x29;
	const GEN_FLT x58 = x40 * x39;
	const GEN_FLT x59 = x35 * obj_qj;
	const GEN_FLT x60 = x25 * x27;
	const GEN_FLT x61 = x14 * aa_y;
	const GEN_FLT x62 = x34 * x37;
	const GEN_FLT x63 = x51 * obj_qw;
	const GEN_FLT x64 = (x59 * x44) + (-1 * x58 * x35) + (x32 * x39) + (x61 * x62) + (-1 * x63 * x44) +
						(-1 * x48 * x33) + (-1 * x60 * obj_qi) + (-1 * x50 * obj_qw) + (-1 * x45 * x47) + (x63 * x53) +
						(-1 * x55 * obj_qi);
	const GEN_FLT x65 = x34 * x29;
	const GEN_FLT x66 = x65 * aa_y;
	const GEN_FLT x67 = aa_z * obj_qi;
	const GEN_FLT x68 = x67 * x31;
	const GEN_FLT x69 = x67 * x41;
	const GEN_FLT x70 = x67 * x34;
	const GEN_FLT x71 = x34 * obj_qw;
	const GEN_FLT x72 = x71 * x40;
	const GEN_FLT x73 = x31 * obj_qw;
	const GEN_FLT x74 = x71 * aa_y;
	const GEN_FLT x75 = x51 * x37;
	const GEN_FLT x76 = (-1 * x55 * obj_qj) + (-1 * x60 * obj_qj) + (-1 * x75 * x14) + (x51 * x47) + (-1 * x68 * x14) +
						(-1 * x70 * x44) + (x72 * x61) + (x69 * x14) + (-1 * x74 * x44) + (-1 * x73 * x61) +
						(x49 * x33);
	const GEN_FLT x77 = x65 * aa_z;
	const GEN_FLT x78 = x71 * aa_z;
	const GEN_FLT x79 = x61 * obj_qi;
	const GEN_FLT x80 = x73 * aa_z;
	const GEN_FLT x81 = x51 * obj_qj;
	const GEN_FLT x82 = (-1 * x55 * obj_qk) + (-1 * x78 * x44) + (x79 * x31) + (x51 * x58) + (x46 * obj_qi) +
						(-1 * x80 * x14) + (-1 * x79 * x41) + (x78 * x53) + (-1 * x60 * obj_qk) + (-1 * x81 * x44) +
						(-1 * x49 * x39);
	const GEN_FLT x83 = -1 * x57;
	const GEN_FLT x84 = -1 * x66;
	const GEN_FLT x85 = -1 * x77;
	const GEN_FLT x86 = 2 * x0 * x7;
	const GEN_FLT x87 =
		(1e-20 < (((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x))))
			? ((time * time) * aa_x *
			   (1. / sqrt(((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) +
						  ((time * time) * (aa_x * aa_x)))))
			: 0;
	const GEN_FLT x88 = x87 * x16;
	const GEN_FLT x89 = (-1 * x87 * x24) + (-1 * x88) + (x88 * x23) + (x88 * x18) + (x88 * x19) + (-1 * x87 * x21) +
						(-1 * x87 * x22) + (x86 * aa_x);
	const GEN_FLT x90 = x89 * x43;
	const GEN_FLT x91 = x87 * obj_qk;
	const GEN_FLT x92 = x87 * x54;
	const GEN_FLT x93 = x35 * obj_qk;
	const GEN_FLT x94 = x87 * obj_qj;
	const GEN_FLT x95 = x87 * obj_qi;
	const GEN_FLT x96 = x51 * x40;
	const GEN_FLT x97 = x90 * x45;
	const GEN_FLT x98 = x87 * x49;
	const GEN_FLT x99 = x65 * obj_qi;
	const GEN_FLT x100 = -1 * x99;
	const GEN_FLT x101 = x87 * x40;
	const GEN_FLT x102 = x89 * x27;
	const GEN_FLT x103 = x54 * obj_qi;
	const GEN_FLT x104 = x45 * x37;
	const GEN_FLT x105 = x65 * obj_qw;
	const GEN_FLT x106 = x87 * x73;
	const GEN_FLT x107 = x65 * obj_qk;
	const GEN_FLT x108 = -1 * x107;
	const GEN_FLT x109 = x51 * x90;
	const GEN_FLT x110 = x65 * obj_qj;
	const GEN_FLT x111 =
		(1e-20 < (((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x))))
			? ((time * time) * aa_y *
			   (1. / sqrt(((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) +
						  ((time * time) * (aa_x * aa_x)))))
			: 0;
	const GEN_FLT x112 = x54 * x111;
	const GEN_FLT x113 = x32 * x111;
	const GEN_FLT x114 = x16 * x111;
	const GEN_FLT x115 = (-1 * x24 * x111) + (x23 * x114) + (x19 * x114) + (-1 * x21 * x111) + (x86 * aa_y) +
						 (-1 * x22 * x111) + (x18 * x114) + (-1 * x114);
	const GEN_FLT x116 = x43 * x115;
	const GEN_FLT x117 = x111 * aa_y;
	const GEN_FLT x118 = x31 * x117;
	const GEN_FLT x119 = x40 * x111;
	const GEN_FLT x120 = x27 * x115;
	const GEN_FLT x121 = x41 * x117;
	const GEN_FLT x122 = x45 * x116;
	const GEN_FLT x123 = -1 * x110;
	const GEN_FLT x124 = x49 * x111;
	const GEN_FLT x125 = x51 * x116;
	const GEN_FLT x126 =
		(1e-20 < (((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) + ((time * time) * (aa_x * aa_x))))
			? ((time * time) * aa_z *
			   (1. / sqrt(((time * time) * (aa_z * aa_z)) + ((time * time) * (aa_y * aa_y)) +
						  ((time * time) * (aa_x * aa_x)))))
			: 0;
	const GEN_FLT x127 = x4 * x126;
	const GEN_FLT x128 = x12 * x127;
	const GEN_FLT x129 = 0.5 * x128;
	const GEN_FLT x130 = x30 * x128;
	const GEN_FLT x131 = x130 * obj_qk;
	const GEN_FLT x132 = x42 * x126;
	const GEN_FLT x133 = x40 * x126;
	const GEN_FLT x134 = x15 * x127;
	const GEN_FLT x135 = x6 * x134;
	const GEN_FLT x136 = (-1 * x24 * x126) + (x8 * x135) + (x1 * x135) + (x86 * aa_z) + (-1 * x21 * x126) +
						 (x9 * x135) + (-1 * x22 * x126) + (-1 * x134);
	const GEN_FLT x137 = x43 * x136;
	const GEN_FLT x138 = x130 * obj_qj;
	const GEN_FLT x139 = x130 * obj_qi;
	const GEN_FLT x140 = x45 * x137;
	const GEN_FLT x141 = x27 * x136;
	const GEN_FLT x142 = x130 * obj_qw;
	const GEN_FLT x143 = x51 * x137;
	out[0] = x56 + x13;
	out[1] = x64 + x57;
	out[2] = x76 + x66;
	out[3] = x82 + x77;
	out[4] = 0;
	out[5] = 0;
	out[6] = 0;
	out[7] = x56 + x83;
	out[8] = x64 + x13;
	out[9] = x76 + x77;
	out[10] = x82 + x84;
	out[11] = 0;
	out[12] = 0;
	out[13] = 0;
	out[14] = x56 + x84;
	out[15] = x64 + x85;
	out[16] = x76 + x13;
	out[17] = x82 + x57;
	out[18] = 0;
	out[19] = 0;
	out[20] = 0;
	out[21] = x56 + x85;
	out[22] = x64 + x66;
	out[23] = x76 + x83;
	out[24] = x82 + x13;
	out[25] = 0;
	out[26] = 0;
	out[27] = 0;
	out[28] = x100 + (-1 * x87 * x38) + (-1 * x89 * x28) + (x52 * x90) + (-1 * x94 * x42) + (x91 * x32) +
			  (x98 * obj_qi) + (-1 * x92 * obj_qw) + (x97 * obj_qj) + (x93 * x90) + (x94 * x48) + (-1 * x96 * x95);
	out[29] = x105 + (-1 * x102 * obj_qi) + (x63 * x101) + (x87 * x104) + (-1 * x91 * x48) + (-1 * x94 * x40 * x35) +
			  (-1 * x97 * obj_qk) + (-1 * x63 * x90) + (x94 * x32) + (x59 * x90) + (-1 * x87 * x103) +
			  (-1 * x98 * obj_qw);
	out[30] = (x109 * obj_qk) + (-1 * x92 * obj_qj) + (-1 * x102 * obj_qj) + (-1 * x74 * x90) + (-1 * x87 * x68) +
			  (x74 * x101) + (x70 * x101) + (-1 * x70 * x90) + (-1 * x87 * x75) + (-1 * x106 * aa_y) + x108 +
			  (x98 * obj_qk);
	out[31] = (x96 * x94) + (-1 * x109 * obj_qj) + x110 + (-1 * x92 * obj_qk) + (-1 * x102 * obj_qk) +
			  (-1 * x106 * aa_z) + (-1 * x78 * x90) + (x95 * x48) + (-1 * x95 * x42) + (x97 * obj_qi) + (x78 * x101) +
			  (-1 * x98 * obj_qj);
	out[32] = 1;
	out[33] = 0;
	out[34] = 0;
	out[35] = x123 + (-1 * x112 * obj_qw) + (-1 * x38 * x111) + (x118 * obj_qj) + (-1 * x120 * obj_qw) +
			  (x124 * obj_qi) + (x93 * x116) + (-1 * x52 * x119) + (x52 * x116) + (x113 * obj_qk) + (x122 * obj_qj) +
			  (-1 * x121 * obj_qj);
	out[36] = x107 + (-1 * x120 * obj_qi) + (-1 * x103 * x111) + (-1 * x63 * x116) + (-1 * x59 * x119) + (x63 * x119) +
			  (-1 * x124 * obj_qw) + (x62 * x117) + (x59 * x116) + (-1 * x118 * obj_qk) + (x113 * obj_qj) +
			  (-1 * x122 * obj_qk);
	out[37] = (x124 * obj_qk) + (-1 * x120 * obj_qj) + (x69 * x111) + (-1 * x73 * x117) + (-1 * x112 * obj_qj) +
			  (-1 * x68 * x111) + (x72 * x117) + (-1 * x70 * x116) + (-1 * x75 * x111) + (x125 * obj_qk) +
			  (-1 * x74 * x116) + x105;
	out[38] = (x72 * x111 * aa_z) + (-1 * x121 * obj_qi) + (-1 * x112 * obj_qk) + (-1 * x124 * obj_qj) +
			  (-1 * x80 * x111) + (-1 * x78 * x116) + (x122 * obj_qi) + (x118 * obj_qi) + (-1 * x125 * obj_qj) +
			  (x81 * x119) + (-1 * x120 * obj_qk) + x100;
	out[39] = 0;
	out[40] = 1;
	out[41] = 0;
	out[42] = (x140 * obj_qj) + (x139 * aa_x) + (-1 * x129 * obj_qw) + (x138 * aa_y) + (x93 * x137) +
			  (-1 * x132 * obj_qj) + (-1 * x52 * x133) + (-1 * x38 * x126) + x108 + (x131 * aa_z) + (x52 * x137) +
			  (-1 * x28 * x136);
	out[43] = (-1 * x142 * aa_x) + (-1 * x141 * obj_qi) + (-1 * x129 * obj_qi) + (x104 * x126) + (x138 * aa_z) +
			  (-1 * x140 * obj_qk) + (-1 * x63 * x137) + (x63 * x133) + (-1 * x59 * x133) + (-1 * x131 * aa_y) +
			  (x59 * x137) + x123;
	out[44] = (-1 * x75 * x126) + (-1 * x141 * obj_qj) + (-1 * x129 * obj_qj) + (-1 * x74 * x137) + (x69 * x126) +
			  (x131 * aa_x) + (-1 * x142 * aa_y) + (x74 * x133) + (-1 * x67 * x130) + (-1 * x70 * x137) + x99 +
			  (x143 * obj_qk);
	out[45] = (-1 * x143 * obj_qj) + (-1 * x36 * x128) + (x78 * x133) + (-1 * x142 * aa_z) + (x81 * x133) +
			  (-1 * x141 * obj_qk) + x105 + (-1 * x138 * aa_x) + (x139 * aa_y) + (-1 * x132 * obj_qi) +
			  (-1 * x78 * x137) + (x140 * obj_qi);
	out[46] = 0;
	out[47] = 0;
	out[48] = 1;
}

/** Applying function <function imu_rot_f_aa at 0x7fe08d8e48c0> */
static inline void gen_imu_rot_f_aa(FLT *out, const FLT time, const FLT *imu_rot_aa) {
	const GEN_FLT aa_x = imu_rot_aa[0];
	const GEN_FLT aa_y = imu_rot_aa[1];
	const GEN_FLT aa_z = imu_rot_aa[2];
	const GEN_FLT lh_qi = imu_rot_aa[3];
	const GEN_FLT lh_qj = imu_rot_aa[4];
	const GEN_FLT lh_qk = imu_rot_aa[5];
	const GEN_FLT x0 = (1e-20 < ((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x)))
						   ? sqrt((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x))
						   : 1e-10;
	const GEN_FLT x1 = 0.5 * x0;
	const GEN_FLT x2 = sin(x1);
	const GEN_FLT x3 = (1. / x0) * x2;
	const GEN_FLT x4 = (1e-20 < (((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								 ((time * time) * (lh_qi * lh_qi))))
						   ? sqrt(((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								  ((time * time) * (lh_qi * lh_qi)))
						   : 1e-10;
	const GEN_FLT x5 = 0.5 * x4;
	const GEN_FLT x6 = sin(x5);
	const GEN_FLT x7 = aa_z * aa_z;
	const GEN_FLT x8 = (1. / (x0 * x0)) * (x2 * x2);
	const GEN_FLT x9 = aa_y * aa_y;
	const GEN_FLT x10 = aa_x * aa_x;
	const GEN_FLT x11 = cos(x1);
	const GEN_FLT x12 = time * time;
	const GEN_FLT x13 = x12 * (lh_qk * lh_qk);
	const GEN_FLT x14 = (1. / (x4 * x4)) * (x6 * x6);
	const GEN_FLT x15 = x12 * (lh_qj * lh_qj);
	const GEN_FLT x16 = x12 * (lh_qi * lh_qi);
	const GEN_FLT x17 = cos(x5);
	const GEN_FLT x18 = (1. / sqrt((x11 * x11) + (x8 * x10) + (x8 * x9) + (x8 * x7))) *
						(1. / sqrt((x17 * x17) + (x14 * x16) + (x15 * x14) + (x14 * x13)));
	const GEN_FLT x19 = (1. / x4) * x6 * x18 * time;
	const GEN_FLT x20 = x3 * x19;
	const GEN_FLT x21 = x20 * lh_qj;
	const GEN_FLT x22 = x11 * x19;
	const GEN_FLT x23 = x20 * lh_qk;
	const GEN_FLT x24 = x18 * x17;
	const GEN_FLT x25 = x3 * x24;
	const GEN_FLT x26 = (x25 * aa_x) + (-1 * x23 * aa_y) + (x22 * lh_qi) + (x21 * aa_z);
	const GEN_FLT x27 = x20 * lh_qi;
	const GEN_FLT x28 = (x22 * lh_qj) + (x25 * aa_y) + (-1 * x27 * aa_z) + (x23 * aa_x);
	const GEN_FLT x29 = (x24 * x11) + (-1 * x27 * aa_x) + (-1 * x21 * aa_y) + (-1 * x23 * aa_z);
	const GEN_FLT x30 = 1e-10 + (x29 * x29) + (x26 * x26) + (x28 * x28);
	const GEN_FLT x31 = 2 * (1. / x30) * atan2(x30, x29);
	out[0] = x31 * x26;
	out[1] = x31 * x28;
	out[2] = x31 * ((x25 * aa_z) + (x27 * aa_y) + (-1 * x21 * aa_x) + (x22 * lh_qk));
	out[3] = lh_qi;
	out[4] = lh_qj;
	out[5] = lh_qk;
}

// Jacobian of imu_rot_f_aa wrt [time]
static inline void gen_imu_rot_f_aa_jac_time(FLT *out, const FLT time, const FLT *imu_rot_aa) {
	const GEN_FLT aa_x = imu_rot_aa[0];
	const GEN_FLT aa_y = imu_rot_aa[1];
	const GEN_FLT aa_z = imu_rot_aa[2];
	const GEN_FLT lh_qi = imu_rot_aa[3];
	const GEN_FLT lh_qj = imu_rot_aa[4];
	const GEN_FLT lh_qk = imu_rot_aa[5];
	const GEN_FLT x0 = aa_z * aa_z;
	const GEN_FLT x1 = (1e-20 < ((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x)))
						   ? sqrt((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x))
						   : 1e-10;
	const GEN_FLT x2 = 1. / (x1 * x1);
	const GEN_FLT x3 = 0.5 * x1;
	const GEN_FLT x4 = sin(x3);
	const GEN_FLT x5 = x4 * x4;
	const GEN_FLT x6 = x2 * x5;
	const GEN_FLT x7 = aa_y * aa_y;
	const GEN_FLT x8 = aa_x * aa_x;
	const GEN_FLT x9 = cos(x3);
	const GEN_FLT x10 = (x9 * x9) + (x6 * x8) + (x6 * x7) + (x0 * x6);
	const GEN_FLT x11 = 1. / sqrt(x10);
	const GEN_FLT x12 = time * time;
	const GEN_FLT x13 = lh_qk * lh_qk;
	const GEN_FLT x14 = x13 * x12;
	const GEN_FLT x15 = (1e-20 < (((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								  ((time * time) * (lh_qi * lh_qi))))
							? sqrt(((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								   ((time * time) * (lh_qi * lh_qi)))
							: 1e-10;
	const GEN_FLT x16 = 1. / (x15 * x15);
	const GEN_FLT x17 = 0.5 * x15;
	const GEN_FLT x18 = sin(x17);
	const GEN_FLT x19 = x18 * x18;
	const GEN_FLT x20 = x19 * x16;
	const GEN_FLT x21 = lh_qj * lh_qj;
	const GEN_FLT x22 = x21 * x12;
	const GEN_FLT x23 = lh_qi * lh_qi;
	const GEN_FLT x24 = x23 * x12;
	const GEN_FLT x25 = cos(x17);
	const GEN_FLT x26 = (x24 * x20) + (x22 * x20) + (x25 * x25) + (x20 * x14);
	const GEN_FLT x27 = 1. / sqrt(x26);
	const GEN_FLT x28 = x27 * x11;
	const GEN_FLT x29 = 1. / x1;
	const GEN_FLT x30 = x4 * x29;
	const GEN_FLT x31 = x30 * x28;
	const GEN_FLT x32 = x31 * aa_z;
	const GEN_FLT x33 = 1. / x15;
	const GEN_FLT x34 = x33 * x18;
	const GEN_FLT x35 = x34 * lh_qj;
	const GEN_FLT x36 = x32 * x35;
	const GEN_FLT x37 = x9 * x28;
	const GEN_FLT x38 = x37 * lh_qi;
	const GEN_FLT x39 = x34 * x38;
	const GEN_FLT x40 = x39 * time;
	const GEN_FLT x41 = x33 * lh_qk;
	const GEN_FLT x42 = x41 * x18;
	const GEN_FLT x43 = x31 * aa_y;
	const GEN_FLT x44 = x42 * x43;
	const GEN_FLT x45 = x25 * x28;
	const GEN_FLT x46 = x29 * aa_x;
	const GEN_FLT x47 = x4 * x46;
	const GEN_FLT x48 = x45 * x47;
	const GEN_FLT x49 = x48 + (-1 * x44 * time) + x40 + (x36 * time);
	const GEN_FLT x50 =
		(1e-20 <
		 (((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) + ((time * time) * (lh_qi * lh_qi))))
			? (1.0 / 2.0 *
			   ((2 * time * (lh_qi * lh_qi)) + (2 * time * (lh_qj * lh_qj)) + (2 * time * (lh_qk * lh_qk))) *
			   (1. / sqrt(((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
						  ((time * time) * (lh_qi * lh_qi)))))
			: 0;
	const GEN_FLT x51 = x50 * x18;
	const GEN_FLT x52 = 0.5 * x51;
	const GEN_FLT x53 = x47 * x28;
	const GEN_FLT x54 = 2 * time;
	const GEN_FLT x55 = x54 * x23;
	const GEN_FLT x56 = 2 * x50 * (1. / (x15 * x15 * x15)) * x19;
	const GEN_FLT x57 = 1.0 * x51 * x25;
	const GEN_FLT x58 = x57 * x16;
	const GEN_FLT x59 = x54 * x13;
	const GEN_FLT x60 = x54 * x21;
	const GEN_FLT x61 = (1. / (x26 * sqrt(x26))) * x11 *
						((x58 * x14) + (x59 * x20) + (-1 * x56 * x14) + (x58 * x22) + (-1 * x57) + (x58 * x24) +
						 (x60 * x20) + (-1 * x56 * x22) + (-1 * x56 * x24) + (x55 * x20));
	const GEN_FLT x62 = 1.0 / 2.0 * x25;
	const GEN_FLT x63 = x62 * x47;
	const GEN_FLT x64 = (1e-20 < ((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x))) ? 0 : 0;
	const GEN_FLT x65 = x4 * x64;
	const GEN_FLT x66 = x65 * x45;
	const GEN_FLT x67 = x2 * x66;
	const GEN_FLT x68 = x34 * lh_qi;
	const GEN_FLT x69 = x68 * time;
	const GEN_FLT x70 = 1.0 * x9 * x65;
	const GEN_FLT x71 = 2 * (1. / (x1 * x1 * x1)) * x5 * x64;
	const GEN_FLT x72 = x2 * x70;
	const GEN_FLT x73 =
		x27 * (1. / (x10 * sqrt(x10))) *
		((x0 * x72) + (-1 * x0 * x71) + (-1 * x7 * x71) + (x8 * x72) + (x7 * x72) + (-1 * x8 * x71) + (-1 * x70));
	const GEN_FLT x74 = 1.0 / 2.0 * x9;
	const GEN_FLT x75 = x73 * x74;
	const GEN_FLT x76 = x33 * lh_qj;
	const GEN_FLT x77 = x45 * x30;
	const GEN_FLT x78 = x77 * aa_z;
	const GEN_FLT x79 = x50 * time;
	const GEN_FLT x80 = 0.5 * x79;
	const GEN_FLT x81 = x80 * x78;
	const GEN_FLT x82 = x51 * x16 * time;
	const GEN_FLT x83 = x35 * time;
	const GEN_FLT x84 = x65 * x28;
	const GEN_FLT x85 = x2 * x84;
	const GEN_FLT x86 = x85 * aa_z;
	const GEN_FLT x87 = x82 * lh_qj;
	const GEN_FLT x88 = 1.0 / 2.0 * x83;
	const GEN_FLT x89 = x88 * aa_z;
	const GEN_FLT x90 = x73 * x30;
	const GEN_FLT x91 = x61 * x30;
	const GEN_FLT x92 = 0.5 * x84;
	const GEN_FLT x93 = x9 * x25;
	const GEN_FLT x94 = x93 * x28;
	const GEN_FLT x95 = 0.5 * x94;
	const GEN_FLT x96 = x79 * x95;
	const GEN_FLT x97 = x96 * x33;
	const GEN_FLT x98 = x42 * time;
	const GEN_FLT x99 = x85 * aa_y;
	const GEN_FLT x100 = x74 * x61;
	const GEN_FLT x101 = x82 * lh_qk;
	const GEN_FLT x102 = x42 * x37;
	const GEN_FLT x103 = time * x102;
	const GEN_FLT x104 = 0.5 * x64;
	const GEN_FLT x105 = x29 * x104;
	const GEN_FLT x106 = x103 * x105;
	const GEN_FLT x107 = x37 * lh_qj;
	const GEN_FLT x108 = x34 * x107;
	const GEN_FLT x109 = time * x108;
	const GEN_FLT x110 = x105 * aa_z;
	const GEN_FLT x111 = 1.0 / 2.0 * x98;
	const GEN_FLT x112 = x90 * aa_y;
	const GEN_FLT x113 = x77 * aa_y;
	const GEN_FLT x114 = x80 * x113;
	const GEN_FLT x115 = x91 * aa_y;
	const GEN_FLT x116 = x64 * x95;
	const GEN_FLT x117 =
		2 * ((x46 * x116) + (x111 * x115) + (x81 * x76) + (x99 * x98) + (-1 * x73 * x63) + (-1 * x87 * x32) +
			 (-1 * x67 * aa_x) + x39 + (-1 * x83 * x86) + (-1 * x44) + (x111 * x112) + (-1 * x41 * x114) +
			 (-1 * x69 * x92) + x36 + (-1 * x53 * x52) + (-1 * x106 * aa_y) + (-1 * x75 * x69) + (-1 * x89 * x90) +
			 (x43 * x101) + (-1 * x82 * x38) + (x97 * lh_qi) + (-1 * x63 * x61) + (x109 * x110) + (-1 * x89 * x91) +
			 (-1 * x69 * x100));
	const GEN_FLT x118 = 1.0 / 2.0 * x93;
	const GEN_FLT x119 = x42 * x32;
	const GEN_FLT x120 = x111 * aa_z;
	const GEN_FLT x121 = x105 * aa_y;
	const GEN_FLT x122 = x46 * x104;
	const GEN_FLT x123 = x80 * x48;
	const GEN_FLT x124 = x33 * lh_qi;
	const GEN_FLT x125 = 1.0 / 2.0 * x69;
	const GEN_FLT x126 = x47 * x125;
	const GEN_FLT x127 = x85 * x69;
	const GEN_FLT x128 = x43 * x35;
	const GEN_FLT x129 = x82 * lh_qi;
	const GEN_FLT x130 = x68 * x53;
	const GEN_FLT x131 = (-1 * x128) + (-1 * x106 * aa_z) + (-1 * x81 * x41) + (x32 * x101) + (-0.5 * x66) +
						 (x127 * aa_x) + (x83 * x99) + (-1 * x109 * x121) + (x90 * x120) + (-1 * x73 * x118) +
						 (-1 * x52 * x37) + (-1 * x130) + (-1 * x119) + (x87 * x43) + (-1 * x40 * x122) + (x53 * x129) +
						 (-1 * x124 * x123) + (x86 * x98) + (x73 * x126) + (x91 * x120) + (x61 * x126) + (x88 * x115) +
						 (-1 * x76 * x114) + (-1 * x61 * x118) + (x88 * x112);
	const GEN_FLT x132 = x94 + (-1 * time * x130) + (-1 * time * x128) + (-1 * time * x119);
	const GEN_FLT x133 = x53 * x42;
	const GEN_FLT x134 = x68 * x32;
	const GEN_FLT x135 = x113 + x109 + (-1 * time * x134) + (time * x133);
	const GEN_FLT x136 = x29 * x116;
	const GEN_FLT x137 = x69 * aa_z;
	const GEN_FLT x138 = 1.0 / 2.0 * x137;
	const GEN_FLT x139 = x47 * x111;
	const GEN_FLT x140 = x62 * x30;
	const GEN_FLT x141 = x61 * x140;
	const GEN_FLT x142 = x85 * aa_x;
	const GEN_FLT x143 = x73 * x140;
	const GEN_FLT x144 =
		2 *
		((-1 * x82 * x107) + (x97 * lh_qj) + x133 + (x85 * x137) + (-1 * x73 * x139) + x108 + (-1 * x134) +
		 (-1 * x81 * x124) + (x103 * x122) + (-1 * x83 * x100) + (-1 * x53 * x101) + (-1 * x61 * x139) + (x90 * x138) +
		 (-1 * x67 * aa_y) + (-1 * x143 * aa_y) + (-1 * x52 * x43) + (x91 * x138) + (-1 * x83 * x75) + (x136 * aa_y) +
		 (x32 * x129) + (x41 * x123) + (-1 * x98 * x142) + (-1 * x40 * x110) + (-1 * x141 * aa_y) + (-1 * x83 * x92));
	const GEN_FLT x145 = (2 * x131 * x132) + (x135 * x144) + (x49 * x117);
	const GEN_FLT x146 = x132 * x132;
	const GEN_FLT x147 = 1e-10 + x146 + (x49 * x49) + (x135 * x135);
	const GEN_FLT x148 = atan2(x147, x132);
	const GEN_FLT x149 = x147 * x147;
	const GEN_FLT x150 = x145 * x148 * (1. / x149);
	const GEN_FLT x151 = 2 * x150;
	const GEN_FLT x152 = 1. / x147;
	const GEN_FLT x153 = (1. / (x146 + x149)) * x146 * x152 * ((-1 * x131 * (1. / x146) * x147) + ((1. / x132) * x145));
	const GEN_FLT x154 = 2 * x153;
	const GEN_FLT x155 = x148 * x152;
	const GEN_FLT x156 = 2 * x135;
	const GEN_FLT x157 = x53 * x35;
	const GEN_FLT x158 = x68 * x43;
	const GEN_FLT x159 = x78 + (time * x158) + (-1 * time * x157) + x103;
	const GEN_FLT x160 = x88 * x47;
	out[0] = (x117 * x155) + (x49 * x154) + (-1 * x49 * x151);
	out[1] = (x144 * x155) + (x153 * x156) + (-1 * x150 * x156);
	out[2] = (2 * x155 *
			  ((x136 * aa_z) + (-1 * x141 * aa_z) + x158 + (-1 * x37 * x101) + (-1 * x67 * aa_z) + (-1 * x92 * x98) +
			   (x73 * x160) + (x61 * x160) + (-1 * x109 * x122) + (-1 * x127 * aa_y) + x102 + (x83 * x142) +
			   (-1 * x52 * x32) + (-1 * x143 * aa_z) + (x96 * x41) + (-1 * x115 * x125) + (-1 * x76 * x123) +
			   (-1 * x112 * x125) + (x87 * x53) + (-1 * x98 * x100) + (x40 * x121) + (x114 * x124) + (-1 * x75 * x98) +
			   (-1 * x157) + (-1 * x43 * x129))) +
			 (x154 * x159) + (-1 * x151 * x159);
	out[3] = 0;
	out[4] = 0;
	out[5] = 0;
}

// Jacobian of imu_rot_f_aa wrt [aa_x, aa_y, aa_z, lh_qi, lh_qj, lh_qk]
static inline void gen_imu_rot_f_aa_jac_imu_rot_aa(FLT *out, const FLT time, const FLT *imu_rot_aa) {
	const GEN_FLT aa_x = imu_rot_aa[0];
	const GEN_FLT aa_y = imu_rot_aa[1];
	const GEN_FLT aa_z = imu_rot_aa[2];
	const GEN_FLT lh_qi = imu_rot_aa[3];
	const GEN_FLT lh_qj = imu_rot_aa[4];
	const GEN_FLT lh_qk = imu_rot_aa[5];
	const GEN_FLT x0 = (1e-20 < (((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								 ((time * time) * (lh_qi * lh_qi))))
						   ? sqrt(((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								  ((time * time) * (lh_qi * lh_qi)))
						   : 1e-10;
	const GEN_FLT x1 = (1. / x0) * time;
	const GEN_FLT x2 = aa_z * aa_z;
	const GEN_FLT x3 = (1e-20 < ((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x)))
						   ? sqrt((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x))
						   : 1e-10;
	const GEN_FLT x4 = 1. / (x3 * x3);
	const GEN_FLT x5 = 0.5 * x3;
	const GEN_FLT x6 = sin(x5);
	const GEN_FLT x7 = x6 * x6;
	const GEN_FLT x8 = x4 * x7;
	const GEN_FLT x9 = aa_y * aa_y;
	const GEN_FLT x10 = aa_x * aa_x;
	const GEN_FLT x11 = cos(x5);
	const GEN_FLT x12 = (x11 * x11) + (x8 * x10) + (x8 * x9) + (x2 * x8);
	const GEN_FLT x13 = 1. / sqrt(x12);
	const GEN_FLT x14 = 0.5 * x0;
	const GEN_FLT x15 = sin(x14);
	const GEN_FLT x16 = x15 * x13;
	const GEN_FLT x17 = time * time;
	const GEN_FLT x18 = x17 * (lh_qk * lh_qk);
	const GEN_FLT x19 = 1. / (x0 * x0);
	const GEN_FLT x20 = x15 * x15;
	const GEN_FLT x21 = x20 * x19;
	const GEN_FLT x22 = x17 * (lh_qj * lh_qj);
	const GEN_FLT x23 = x17 * (lh_qi * lh_qi);
	const GEN_FLT x24 = cos(x14);
	const GEN_FLT x25 = (x23 * x21) + (x22 * x21) + (x24 * x24) + (x21 * x18);
	const GEN_FLT x26 = 1. / sqrt(x25);
	const GEN_FLT x27 = 1. / x3;
	const GEN_FLT x28 = x6 * x27;
	const GEN_FLT x29 = x28 * x26;
	const GEN_FLT x30 = x29 * x16;
	const GEN_FLT x31 = x1 * x30;
	const GEN_FLT x32 = x31 * lh_qi;
	const GEN_FLT x33 = -1 * x32;
	const GEN_FLT x34 = (1e-20 < ((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x)))
							? (aa_x * (1. / sqrt((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x))))
							: 0;
	const GEN_FLT x35 = x6 * x34;
	const GEN_FLT x36 = x1 * lh_qj;
	const GEN_FLT x37 = x36 * x16;
	const GEN_FLT x38 = x4 * x26;
	const GEN_FLT x39 = x38 * x37;
	const GEN_FLT x40 = x39 * aa_y;
	const GEN_FLT x41 = 1.0 * x11;
	const GEN_FLT x42 = x6 * x41;
	const GEN_FLT x43 = x42 * x34;
	const GEN_FLT x44 = 2 * x8;
	const GEN_FLT x45 = x4 * x10;
	const GEN_FLT x46 = 2 * (1. / (x3 * x3 * x3)) * x7;
	const GEN_FLT x47 = x46 * x10;
	const GEN_FLT x48 = x9 * x46;
	const GEN_FLT x49 = x4 * x9;
	const GEN_FLT x50 = x2 * x46;
	const GEN_FLT x51 = x2 * x4;
	const GEN_FLT x52 = (x51 * x43) + (-1 * x50 * x34) + (-1 * x47 * x34) + (x43 * x45) + (x43 * x49) +
						(-1 * x48 * x34) + (x44 * aa_x) + (-1 * x43);
	const GEN_FLT x53 = x29 * aa_y;
	const GEN_FLT x54 = 1.0 / 2.0 * (1. / (x12 * sqrt(x12)));
	const GEN_FLT x55 = x54 * x15;
	const GEN_FLT x56 = x55 * x36;
	const GEN_FLT x57 = x53 * x56;
	const GEN_FLT x58 = x26 * x11;
	const GEN_FLT x59 = x54 * x24;
	const GEN_FLT x60 = x58 * x59;
	const GEN_FLT x61 = 0.5 * aa_y;
	const GEN_FLT x62 = x58 * x16;
	const GEN_FLT x63 = x1 * x62;
	const GEN_FLT x64 = x63 * lh_qj;
	const GEN_FLT x65 = x64 * x27;
	const GEN_FLT x66 = x61 * x65;
	const GEN_FLT x67 = x29 * aa_x;
	const GEN_FLT x68 = x1 * lh_qi;
	const GEN_FLT x69 = x52 * x55;
	const GEN_FLT x70 = x68 * x69;
	const GEN_FLT x71 = 0.5 * aa_z;
	const GEN_FLT x72 = x63 * lh_qk;
	const GEN_FLT x73 = x72 * x27;
	const GEN_FLT x74 = x71 * x73;
	const GEN_FLT x75 = x28 * aa_z;
	const GEN_FLT x76 = x75 * x26;
	const GEN_FLT x77 = x1 * lh_qk;
	const GEN_FLT x78 = x77 * x69;
	const GEN_FLT x79 = x1 * x16;
	const GEN_FLT x80 = x79 * lh_qk;
	const GEN_FLT x81 = x80 * x38;
	const GEN_FLT x82 = x81 * x35;
	const GEN_FLT x83 = x79 * lh_qi;
	const GEN_FLT x84 = x83 * x38;
	const GEN_FLT x85 = x35 * aa_x;
	const GEN_FLT x86 = x63 * lh_qi;
	const GEN_FLT x87 = x86 * x27;
	const GEN_FLT x88 = 0.5 * aa_x;
	const GEN_FLT x89 = x88 * x34;
	const GEN_FLT x90 = x24 * x13;
	const GEN_FLT x91 = x90 * x26;
	const GEN_FLT x92 = 0.5 * x91;
	const GEN_FLT x93 = x6 * x92;
	const GEN_FLT x94 = x28 * aa_y;
	const GEN_FLT x95 = (1e-20 < (((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								  ((time * time) * (lh_qi * lh_qi))))
							? 0
							: 0;
	const GEN_FLT x96 = 1.0 * x24;
	const GEN_FLT x97 = x96 * x15;
	const GEN_FLT x98 = x97 * x95;
	const GEN_FLT x99 = 2 * (1. / (x0 * x0 * x0)) * x20;
	const GEN_FLT x100 = x99 * x22;
	const GEN_FLT x101 = x23 * x19;
	const GEN_FLT x102 = x22 * x19;
	const GEN_FLT x103 = x99 * x23;
	const GEN_FLT x104 = x99 * x18;
	const GEN_FLT x105 = x19 * x18;
	const GEN_FLT x106 = (-1 * x95 * x104) + (-1 * x95 * x103) + (x98 * x102) + (x98 * x101) + (-1 * x95 * x100) +
						 (x98 * x105) + (-1 * x98);
	const GEN_FLT x107 = 1.0 / 2.0 * (1. / (x25 * sqrt(x25)));
	const GEN_FLT x108 = x107 * x106;
	const GEN_FLT x109 = x94 * x108;
	const GEN_FLT x110 = 0.5 * x62;
	const GEN_FLT x111 = x91 * x28;
	const GEN_FLT x112 = x111 * aa_z;
	const GEN_FLT x113 = 0.5 * x95;
	const GEN_FLT x114 = x77 * x113;
	const GEN_FLT x115 = x19 * time;
	const GEN_FLT x116 = x115 * lh_qk;
	const GEN_FLT x117 = x76 * x16;
	const GEN_FLT x118 = x95 * x117;
	const GEN_FLT x119 = x111 * aa_y;
	const GEN_FLT x120 = x36 * x113;
	const GEN_FLT x121 = x80 * x107;
	const GEN_FLT x122 = x75 * x121;
	const GEN_FLT x123 = x30 * aa_y;
	const GEN_FLT x124 = x115 * lh_qj;
	const GEN_FLT x125 = x95 * x124;
	const GEN_FLT x126 = x90 * x107;
	const GEN_FLT x127 = x11 * x126;
	const GEN_FLT x128 = x28 * aa_x;
	const GEN_FLT x129 = x83 * x108;
	const GEN_FLT x130 = x111 * aa_x;
	const GEN_FLT x131 = x68 * x130;
	const GEN_FLT x132 = x67 * x16;
	const GEN_FLT x133 = x95 * x132;
	const GEN_FLT x134 = x115 * lh_qi;
	const GEN_FLT x135 = (x133 * x134) + (-1 * x95 * x110) + (x118 * x116) + (x106 * x122) + (-1 * x113 * x131) +
						 (x123 * x125) + (x37 * x109) + (-1 * x106 * x127) + (-1 * x112 * x114) + (-1 * x119 * x120) +
						 (x128 * x129);
	const GEN_FLT x136 = (-1 * x93 * x34) + (-1 * x60 * x52) + x33 + (x40 * x35) + (-1 * x89 * x87) + (-1 * x74 * x34) +
						 (x52 * x57) + x135 + (-1 * x66 * x34) + (x70 * x67) + (x78 * x76) + (x82 * aa_z) + (x84 * x85);
	const GEN_FLT x137 = x79 * x76;
	const GEN_FLT x138 = x30 * x36;
	const GEN_FLT x139 = x79 * x67;
	const GEN_FLT x140 = x58 * x90;
	const GEN_FLT x141 = x140 + (-1 * x139 * lh_qi) + (-1 * x138 * aa_y) + (-1 * x137 * lh_qk);
	const GEN_FLT x142 = 2 * x141;
	const GEN_FLT x143 = x58 * x55;
	const GEN_FLT x144 = x68 * x143;
	const GEN_FLT x145 = x39 * aa_z;
	const GEN_FLT x146 = x67 * x59;
	const GEN_FLT x147 = 0.5 * x26;
	const GEN_FLT x148 = x83 * x147;
	const GEN_FLT x149 = x71 * x65;
	const GEN_FLT x150 = x73 * x61;
	const GEN_FLT x151 = x27 * x140;
	const GEN_FLT x152 = x34 * x151;
	const GEN_FLT x153 = x4 * x91;
	const GEN_FLT x154 = x6 * x153;
	const GEN_FLT x155 = x154 * aa_x;
	const GEN_FLT x156 = x36 * x112;
	const GEN_FLT x157 = x95 * x30;
	const GEN_FLT x158 = x75 * x37;
	const GEN_FLT x159 = x94 * x121;
	const GEN_FLT x160 = x62 * x115;
	const GEN_FLT x161 = x160 * lh_qi;
	const GEN_FLT x162 = x11 * x107;
	const GEN_FLT x163 = x106 * x162;
	const GEN_FLT x164 = 0.5 * x140;
	const GEN_FLT x165 = x68 * x164;
	const GEN_FLT x166 = x116 * x123;
	const GEN_FLT x167 = x106 * x126;
	const GEN_FLT x168 = (x113 * x156) + (-1 * x88 * x157) + (-1 * x117 * x125) + (x95 * x166) + (-1 * x108 * x158) +
						 (x95 * x165) + (-1 * x128 * x167) + (x106 * x159) + (-1 * x95 * x161) + (-1 * x83 * x163) +
						 (-1 * x119 * x114);
	const GEN_FLT x169 = (-1 * x34 * x155) + (-1 * x76 * x52 * x56) + x111 + (-1 * x52 * x144) + (-1 * x35 * x145) +
						 (-1 * x35 * x148) + (-1 * x52 * x146) + (x34 * x149) + x168 + (-1 * x34 * x150) +
						 (x82 * aa_y) + (x88 * x152) + (x78 * x53);
	const GEN_FLT x170 = x1 * x123;
	const GEN_FLT x171 = x130 + (-1 * x170 * lh_qk) + x86 + (x76 * x37);
	const GEN_FLT x172 = 2 * x171;
	const GEN_FLT x173 = x87 * x71;
	const GEN_FLT x174 = x31 * lh_qk;
	const GEN_FLT x175 = x53 * x59;
	const GEN_FLT x176 = x34 * x154;
	const GEN_FLT x177 = x84 * aa_z;
	const GEN_FLT x178 = x37 * x147;
	const GEN_FLT x179 = x6 * x178;
	const GEN_FLT x180 = x36 * x143;
	const GEN_FLT x181 = x121 * x128;
	const GEN_FLT x182 = x77 * x130;
	const GEN_FLT x183 = x68 * x112;
	const GEN_FLT x184 = x36 * x164;
	const GEN_FLT x185 = x160 * lh_qj;
	const GEN_FLT x186 = x94 * x126;
	const GEN_FLT x187 = (x75 * x129) + (-1 * x116 * x133) + (-1 * x61 * x157) + (-1 * x106 * x181) +
						 (-1 * x37 * x163) + (x113 * x182) + (-1 * x113 * x183) + (x95 * x184) + (-1 * x95 * x185) +
						 (x118 * x134) + (-1 * x106 * x186);
	const GEN_FLT x188 = x187 + (x61 * x152) + (x70 * x76) + (-1 * x82 * aa_x) + (-1 * x52 * x175) + x174 +
						 (x89 * x73) + (-1 * x78 * x67) + (-1 * x34 * x179) + (-1 * x176 * aa_y) + (-1 * x34 * x173) +
						 (x35 * x177) + (-1 * x52 * x180);
	const GEN_FLT x189 = x119 + x64 + (-1 * x137 * lh_qi) + (x139 * lh_qk);
	const GEN_FLT x190 = 2 * x189;
	const GEN_FLT x191 = (x188 * x190) + (x169 * x172) + (x136 * x142);
	const GEN_FLT x192 = x141 * x141;
	const GEN_FLT x193 = 1e-10 + x192 + (x171 * x171) + (x189 * x189);
	const GEN_FLT x194 = atan2(x193, x141);
	const GEN_FLT x195 = x193 * x193;
	const GEN_FLT x196 = 1. / x195;
	const GEN_FLT x197 = x196 * x194;
	const GEN_FLT x198 = x172 * x197;
	const GEN_FLT x199 = 1. / x141;
	const GEN_FLT x200 = (1. / x192) * x193;
	const GEN_FLT x201 = (-1 * x200 * x136) + (x191 * x199);
	const GEN_FLT x202 = 1. / x193;
	const GEN_FLT x203 = (1. / (x192 + x195)) * x202 * x192;
	const GEN_FLT x204 = x203 * x172;
	const GEN_FLT x205 = 2 * x194;
	const GEN_FLT x206 = x202 * x205;
	const GEN_FLT x207 = -1 * x138;
	const GEN_FLT x208 = (1e-20 < ((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x)))
							 ? (aa_y * (1. / sqrt((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x))))
							 : 0;
	const GEN_FLT x209 = x42 * x208;
	const GEN_FLT x210 = x46 * x208;
	const GEN_FLT x211 = (-1 * x2 * x210) + (x49 * x209) + (-1 * x9 * x210) + (x51 * x209) + (x45 * x209) +
						 (x44 * aa_y) + (-1 * x47 * x208) + (-1 * x209);
	const GEN_FLT x212 = x88 * x208;
	const GEN_FLT x213 = x6 * x208;
	const GEN_FLT x214 = x81 * x213;
	const GEN_FLT x215 = x68 * x55;
	const GEN_FLT x216 = x67 * x215;
	const GEN_FLT x217 = x213 * aa_x;
	const GEN_FLT x218 = x76 * x211;
	const GEN_FLT x219 = x77 * x55;
	const GEN_FLT x220 = x135 + (-1 * x93 * x208) + (x219 * x218) + x207 + (x84 * x217) + (x57 * x211) +
						 (-1 * x87 * x212) + (-1 * x74 * x208) + (x40 * x213) + (x214 * aa_z) + (-1 * x66 * x208) +
						 (x211 * x216) + (-1 * x60 * x211);
	const GEN_FLT x221 = -1 * x174;
	const GEN_FLT x222 = x53 * x211;
	const GEN_FLT x223 = x59 * x211;
	const GEN_FLT x224 = x208 * x151;
	const GEN_FLT x225 = x211 * x143;
	const GEN_FLT x226 = x168 + (-1 * x208 * x150) + x221 + (-1 * x213 * x148) + (x219 * x222) + (-1 * x67 * x223) +
						 (x214 * aa_y) + (-1 * x213 * x145) + (-1 * x56 * x218) + (-1 * x68 * x225) + (x208 * x149) +
						 (x88 * x224) + (-1 * x208 * x155);
	const GEN_FLT x227 = x67 * x219;
	const GEN_FLT x228 = x84 * x213;
	const GEN_FLT x229 = x208 * x154;
	const GEN_FLT x230 = x111 + (-1 * x208 * x173) + (x218 * x215) + (x228 * aa_z) + (-1 * x53 * x223) + (x61 * x224) +
						 (-1 * x211 * x227) + (-1 * x229 * aa_y) + (x73 * x212) + (-1 * x214 * aa_x) +
						 (-1 * x36 * x225) + x187 + (-1 * x208 * x179);
	const GEN_FLT x231 = (x230 * x190) + (x226 * x172) + (x220 * x142);
	const GEN_FLT x232 = (-1 * x200 * x220) + (x231 * x199);
	const GEN_FLT x233 = (1e-20 < ((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x)))
							 ? (aa_z * (1. / sqrt((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x))))
							 : 0;
	const GEN_FLT x234 = x6 * x233;
	const GEN_FLT x235 = x81 * x234;
	const GEN_FLT x236 = x42 * x233;
	const GEN_FLT x237 = (x51 * x236) + (-1 * x50 * x233) + (-1 * x47 * x233) + (x44 * aa_z) + (x49 * x236) +
						 (-1 * x48 * x233) + (x45 * x236) + (-1 * x236);
	const GEN_FLT x238 = x76 * x237;
	const GEN_FLT x239 = x233 * aa_x;
	const GEN_FLT x240 = x6 * x239;
	const GEN_FLT x241 = 0.5 * x239;
	const GEN_FLT x242 = x135 + (-1 * x60 * x237) + (-1 * x87 * x241) + x221 + (x235 * aa_z) + (x219 * x238) +
						 (-1 * x66 * x233) + (x84 * x240) + (-1 * x74 * x233) + (x57 * x237) + (x40 * x234) +
						 (-1 * x93 * x233) + (x216 * x237);
	const GEN_FLT x243 = x53 * x219;
	const GEN_FLT x244 = x61 * x233;
	const GEN_FLT x245 = x237 * x143;
	const GEN_FLT x246 = x168 + (-1 * x239 * x154) + (-1 * x237 * x146) + (-1 * x234 * x148) + (-1 * x234 * x145) +
						 (x235 * aa_y) + (-1 * x68 * x245) + (x237 * x243) + (x241 * x151) + (-1 * x56 * x238) +
						 (x233 * x149) + (-1 * x73 * x244) + x138;
	const GEN_FLT x247 = x233 * x151;
	const GEN_FLT x248 = x233 * x154;
	const GEN_FLT x249 = x187 + (-1 * x248 * aa_y) + (-1 * x36 * x245) + (x61 * x247) + (x73 * x241) +
						 (-1 * x237 * x175) + (x234 * x177) + (x215 * x238) + (-1 * x237 * x227) + (-1 * x81 * x240) +
						 x33 + (-1 * x233 * x173) + (-1 * x234 * x178);
	const GEN_FLT x250 = (x249 * x190) + (x246 * x172) + (x242 * x142);
	const GEN_FLT x251 = (-1 * x200 * x242) + (x250 * x199);
	const GEN_FLT x252 = -1 * x139;
	const GEN_FLT x253 = (1e-20 < (((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								   ((time * time) * (lh_qi * lh_qi))))
							 ? ((time * time) * lh_qi *
								(1. / sqrt(((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
										   ((time * time) * (lh_qi * lh_qi)))))
							 : 0;
	const GEN_FLT x254 = 0.5 * x253;
	const GEN_FLT x255 = x253 * x117;
	const GEN_FLT x256 = x36 * x254;
	const GEN_FLT x257 = x77 * x112;
	const GEN_FLT x258 = x37 * x107;
	const GEN_FLT x259 = 2 * x21 * x17;
	const GEN_FLT x260 = x97 * x253;
	const GEN_FLT x261 = (x260 * x105) + (x260 * x102) + (-1 * x260) + (-1 * x253 * x100) + (x260 * x101) +
						 (-1 * x253 * x104) + (-1 * x253 * x103) + (x259 * lh_qi);
	const GEN_FLT x262 = x94 * x261;
	const GEN_FLT x263 = x253 * x132;
	const GEN_FLT x264 = x75 * x261;
	const GEN_FLT x265 = x83 * x107;
	const GEN_FLT x266 = x261 * x128;
	const GEN_FLT x267 = (1e-20 < ((aa_z * aa_z) + (aa_y * aa_y) + (aa_x * aa_x))) ? 0 : 0;
	const GEN_FLT x268 = x6 * x267;
	const GEN_FLT x269 = x41 * x268;
	const GEN_FLT x270 = x46 * x267;
	const GEN_FLT x271 = x4 * x269;
	const GEN_FLT x272 = (x2 * x271) + (x9 * x271) + (-1 * x9 * x270) + (-1 * x2 * x270) + (x45 * x269) +
						 (-1 * x47 * x267) + (-1 * x269);
	const GEN_FLT x273 = x56 * x272;
	const GEN_FLT x274 = x38 * x268;
	const GEN_FLT x275 = x37 * x274;
	const GEN_FLT x276 = x76 * x272;
	const GEN_FLT x277 = x81 * x268;
	const GEN_FLT x278 = x71 * x267;
	const GEN_FLT x279 = x88 * x267;
	const GEN_FLT x280 = x83 * x274;
	const GEN_FLT x281 = (-1 * x60 * x272) + (x53 * x273) + (x275 * aa_y) + (-1 * x66 * x267) + (-1 * x92 * x268) +
						 (-1 * x87 * x279) + (x219 * x276) + (-1 * x73 * x278) + (x280 * aa_x) + (x277 * aa_z) +
						 (x216 * x272);
	const GEN_FLT x282 = x281 + (-1 * x254 * x131) + (x253 * x124 * x123) + (-1 * x254 * x257) + (x263 * x134) + x252 +
						 (-1 * x256 * x119) + (-1 * x261 * x127) + (x262 * x258) + (-1 * x62 * x254) + (x255 * x116) +
						 (x264 * x121) + (x266 * x265);
	const GEN_FLT x283 = x77 * x119;
	const GEN_FLT x284 = x254 * x140;
	const GEN_FLT x285 = x261 * x162;
	const GEN_FLT x286 = x16 * x254;
	const GEN_FLT x287 = x264 * x107;
	const GEN_FLT x288 = x261 * x126;
	const GEN_FLT x289 = x268 * x147;
	const GEN_FLT x290 = x267 * x151;
	const GEN_FLT x291 = x61 * x267;
	const GEN_FLT x292 = x268 * x153;
	const GEN_FLT x293 = x59 * x272;
	const GEN_FLT x294 = (-1 * x83 * x289) + (-1 * x272 * x144) + (-1 * x76 * x273) + (-1 * x73 * x291) +
						 (-1 * x275 * aa_z) + (-1 * x292 * aa_x) + (x277 * aa_y) + (-1 * x67 * x293) + (x267 * x149) +
						 (x88 * x290) + (x272 * x243);
	const GEN_FLT x295 = x294 + (-1 * x288 * x128) + x63 + (-1 * x253 * x161) + (-1 * x67 * x286) + (x253 * x166) +
						 (-1 * x37 * x287) + (-1 * x283 * x254) + (x261 * x159) + (-1 * x255 * x124) + (x256 * x112) +
						 (x68 * x284) + (-1 * x83 * x285);
	const GEN_FLT x296 = -1 * x137;
	const GEN_FLT x297 = (x215 * x276) + (-1 * x87 * x278) + (x73 * x279) + (-1 * x53 * x293) + (-1 * x272 * x180) +
						 (-1 * x272 * x227) + (-1 * x292 * aa_y) + (x61 * x290) + (-1 * x277 * aa_x) + (x280 * aa_z) +
						 (-1 * x268 * x178);
	const GEN_FLT x298 = x297 + (-1 * x253 * x185) + (-1 * x37 * x285) + (-1 * x254 * x123) + (x83 * x287) +
						 (-1 * x261 * x186) + (x254 * x182) + (x255 * x134) + x296 + (-1 * x263 * x116) +
						 (-1 * x254 * x183) + (-1 * x261 * x181) + (x36 * x284);
	const GEN_FLT x299 = (x298 * x190) + (x295 * x172) + (x282 * x142);
	const GEN_FLT x300 = (-1 * x200 * x282) + (x299 * x199);
	const GEN_FLT x301 = x299 * x196;
	const GEN_FLT x302 = x301 * x194;
	const GEN_FLT x303 = (1e-20 < (((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								   ((time * time) * (lh_qi * lh_qi))))
							 ? ((time * time) * lh_qj *
								(1. / sqrt(((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
										   ((time * time) * (lh_qi * lh_qi)))))
							 : 0;
	const GEN_FLT x304 = x303 * x116;
	const GEN_FLT x305 = 0.5 * x303;
	const GEN_FLT x306 = x97 * x303;
	const GEN_FLT x307 = x99 * x303;
	const GEN_FLT x308 = x19 * x306;
	const GEN_FLT x309 = (-1 * x303 * x104) + (x22 * x308) + (x23 * x308) + (x259 * lh_qj) + (x306 * x105) +
						 (-1 * x23 * x307) + (-1 * x22 * x307) + (-1 * x306);
	const GEN_FLT x310 = x305 * x119;
	const GEN_FLT x311 = x303 * x115;
	const GEN_FLT x312 = x311 * x123;
	const GEN_FLT x313 = -1 * x170;
	const GEN_FLT x314 = x309 * x128;
	const GEN_FLT x315 = x311 * lh_qi;
	const GEN_FLT x316 = x281 + (-1 * x305 * x131) + (x304 * x117) + (-1 * x257 * x305) + (-1 * x303 * x110) +
						 (x309 * x122) + (x94 * x258 * x309) + (x312 * lh_qj) + (x265 * x314) + (x315 * x132) +
						 (-1 * x309 * x127) + (-1 * x36 * x310) + x313;
	const GEN_FLT x317 = x311 * lh_qj;
	const GEN_FLT x318 = x309 * x107;
	const GEN_FLT x319 = x309 * x162;
	const GEN_FLT x320 = x309 * x126;
	const GEN_FLT x321 = x30 * x303;
	const GEN_FLT x322 = x294 + (x309 * x159) + x137 + (-1 * x77 * x310) + (-1 * x88 * x321) + (x303 * x165) +
						 (-1 * x317 * x117) + (-1 * x318 * x158) + (x305 * x156) + (-1 * x83 * x319) +
						 (-1 * x303 * x161) + (-1 * x320 * x128) + (x303 * x166);
	const GEN_FLT x323 = x83 * x318;
	const GEN_FLT x324 = x297 + (-1 * x61 * x321) + (x75 * x323) + (-1 * x304 * x132) + (x305 * x182) +
						 (-1 * x305 * x183) + (x315 * x117) + (-1 * x37 * x319) + (-1 * x94 * x320) + (x303 * x184) +
						 x63 + (-1 * x314 * x121) + (-1 * x303 * x185);
	const GEN_FLT x325 = (x324 * x190) + (x322 * x172) + (x316 * x142);
	const GEN_FLT x326 = (-1 * x200 * x316) + (x325 * x199);
	const GEN_FLT x327 = (1e-20 < (((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
								   ((time * time) * (lh_qi * lh_qi))))
							 ? ((time * time) * lh_qk *
								(1. / sqrt(((time * time) * (lh_qk * lh_qk)) + ((time * time) * (lh_qj * lh_qj)) +
										   ((time * time) * (lh_qi * lh_qi)))))
							 : 0;
	const GEN_FLT x328 = x15 * x327;
	const GEN_FLT x329 = x13 * x328;
	const GEN_FLT x330 = x58 * x329;
	const GEN_FLT x331 = x67 * x329;
	const GEN_FLT x332 = x76 * x329;
	const GEN_FLT x333 = 0.5 * x327;
	const GEN_FLT x334 = x96 * x328;
	const GEN_FLT x335 = (x334 * x102) + (x259 * lh_qk) + (x334 * x105) + (-1 * x327 * x104) + (-1 * x327 * x100) +
						 (-1 * x334) + (x334 * x101) + (-1 * x327 * x103);
	const GEN_FLT x336 = x335 * x107;
	const GEN_FLT x337 = x36 * x333;
	const GEN_FLT x338 = x329 * x124;
	const GEN_FLT x339 = x83 * x336;
	const GEN_FLT x340 = x281 + (-1 * x335 * x127) + (-0.5 * x330) + (x53 * x338) + (x331 * x134) + (-1 * x333 * x131) +
						 (x335 * x122) + x296 + (-1 * x257 * x333) + (x94 * x37 * x336) + (x339 * x128) +
						 (x332 * x116) + (-1 * x337 * x119);
	const GEN_FLT x341 = x29 * x329;
	const GEN_FLT x342 = x335 * x126;
	const GEN_FLT x343 = x53 * x329;
	const GEN_FLT x344 = x335 * x162;
	const GEN_FLT x345 = x330 * x115;
	const GEN_FLT x346 = x327 * x164;
	const GEN_FLT x347 = x294 + (x335 * x159) + (-1 * x283 * x333) + (-1 * x332 * x124) + (-1 * x88 * x341) +
						 (-1 * x336 * x158) + (x343 * x116) + (-1 * x83 * x344) + x313 + (-1 * x342 * x128) +
						 (-1 * x345 * lh_qi) + (x337 * x112) + (x68 * x346);
	const GEN_FLT x348 = x297 + (-1 * x333 * x183) + (-1 * x61 * x341) + (x75 * x339) + (x332 * x134) + x139 +
						 (x333 * x182) + (x36 * x346) + (-1 * x331 * x116) + (-1 * x37 * x344) + (-1 * x335 * x186) +
						 (-1 * x335 * x181) + (-1 * x345 * lh_qj);
	const GEN_FLT x349 = (x348 * x190) + (x347 * x172) + (x340 * x142);
	const GEN_FLT x350 = (-1 * x200 * x340) + (x349 * x199);
	const GEN_FLT x351 = x190 * x197;
	const GEN_FLT x352 = x203 * x190;
	const GEN_FLT x353 = x112 + (x170 * lh_qi) + (-1 * x67 * x37) + x72;
	const GEN_FLT x354 = x205 * x353;
	const GEN_FLT x355 = x354 * x196;
	const GEN_FLT x356 = 2 * x203 * x353;
	const GEN_FLT x357 = x76 * x59;
	const GEN_FLT x358 = x67 * x56;
	const GEN_FLT x359 = x87 * x61;
	const GEN_FLT x360 = x80 * x147;
	const GEN_FLT x361 = x84 * aa_y;
	const GEN_FLT x362 = x77 * x143;
	const GEN_FLT x363 = x71 * x30;
	const GEN_FLT x364 = x37 * x128;
	const GEN_FLT x365 = x160 * lh_qk;
	const GEN_FLT x366 = x77 * x164;
	const GEN_FLT x367 = x68 * x119;
	const GEN_FLT x368 = x123 * x134;
	const GEN_FLT x369 = (-1 * x75 * x167) + (-1 * x95 * x363) + (-1 * x120 * x130) + (-1 * x83 * x109) +
						 (x364 * x108) + (-1 * x95 * x365) + (x95 * x366) + (-1 * x80 * x163) + (x124 * x133) +
						 (x367 * x113) + (-1 * x95 * x368);
	const GEN_FLT x370 = x53 * x215;
	const GEN_FLT x371 = (-1 * x76 * x293) + (x67 * x273) + (-1 * x272 * x362) + (-1 * x280 * aa_y) +
						 (-1 * x80 * x289) + (x71 * x290) + (x275 * aa_x) + (-1 * x292 * aa_z) + (-1 * x65 * x279) +
						 (x87 * x291) + (-1 * x272 * x370);
	out[0] = (x206 * x169) + (x201 * x204) + (-1 * x191 * x198);
	out[1] = (x206 * x226) + (x232 * x204) + (-1 * x231 * x198);
	out[2] = (x206 * x246) + (x204 * x251) + (-1 * x250 * x198);
	out[3] = (x206 * x295) + (-1 * x302 * x172) + (x204 * x300);
	out[4] = (x206 * x322) + (x204 * x326) + (-1 * x325 * x198);
	out[5] = (x206 * x347) + (x204 * x350) + (-1 * x349 * x198);
	out[6] = (x206 * x188) + (x201 * x352) + (-1 * x351 * x191);
	out[7] = (x230 * x206) + (x232 * x352) + (-1 * x231 * x351);
	out[8] = (x206 * x249) + (x251 * x352) + (-1 * x250 * x351);
	out[9] = (x206 * x298) + (x352 * x300) + (-1 * x302 * x190);
	out[10] = (x206 * x324) + (x352 * x326) + (-1 * x351 * x325);
	out[11] = (x206 * x348) + (x350 * x352) + (-1 * x351 * x349);
	out[12] = (x206 * (x369 + (-1 * x89 * x65) + (-1 * x52 * x362) + x207 + (-1 * x35 * x360) + (x71 * x152) +
					   (-1 * x52 * x357) + (x85 * x39) + (-1 * x35 * x361) + (-1 * x176 * aa_z) + (-1 * x70 * x53) +
					   (x52 * x358) + (x34 * x359))) +
			  (x201 * x356) + (-1 * x355 * x191);
	out[13] = (x232 * x356) +
			  (x206 * ((-1 * x229 * aa_z) + (-1 * x213 * x360) + (-1 * x76 * x223) + (x208 * x359) + (x211 * x358) +
					   (-1 * x65 * x212) + (-1 * x77 * x225) + (-1 * x215 * x222) + (-1 * x228 * aa_y) + (x71 * x224) +
					   x369 + (x39 * x217) + x32)) +
			  (-1 * x231 * x355);
	out[14] = (x206 * (x369 + (x87 * x244) + x111 + (-1 * x237 * x357) + (-1 * x234 * x360) + (x237 * x358) +
					   (x71 * x247) + (-1 * x237 * x370) + (-1 * x248 * aa_z) + (-1 * x65 * x241) + (x39 * x240) +
					   (-1 * x77 * x245) + (-1 * x234 * x361))) +
			  (x251 * x356) + (-1 * x250 * x355);
	out[15] = (x206 * ((-1 * x256 * x130) + x371 + (-1 * x253 * x368) + (x254 * x367) + (-1 * x253 * x365) +
					   (x266 * x258) + (x77 * x284) + (-1 * x80 * x285) + (x263 * x124) + (-1 * x265 * x262) +
					   (-1 * x76 * x286) + (-1 * x75 * x288) + x170)) +
			  (x356 * x300) + (-1 * x354 * x301);
	out[16] = (x206 * ((-1 * x365 * x303) + (x367 * x305) + x371 + (-1 * x363 * x303) + (-1 * x75 * x320) +
					   (-1 * x312 * lh_qi) + (-1 * x80 * x319) + (-1 * x94 * x323) + (x317 * x132) +
					   (-1 * x36 * x305 * x130) + (x258 * x314) + x252 + (x366 * x303))) +
			  (x356 * x326) + (-1 * x355 * x325);
	out[17] = (x206 * (x371 + (-1 * x75 * x342) + (x77 * x346) + x63 + (-1 * x345 * lh_qk) + (-1 * x71 * x341) +
					   (-1 * x337 * x130) + (x364 * x336) + (-1 * x80 * x344) + (x367 * x333) + (-1 * x94 * x339) +
					   (-1 * x343 * x134) + (x67 * x338))) +
			  (x350 * x356) + (-1 * x355 * x349);
	out[18] = 0;
	out[19] = 0;
	out[20] = 0;
	out[21] = 1;
	out[22] = 0;
	out[23] = 0;
	out[24] = 0;
	out[25] = 0;
	out[26] = 0;
	out[27] = 0;
	out[28] = 1;
	out[29] = 0;
	out[30] = 0;
	out[31] = 0;
	out[32] = 0;
	out[33] = 0;
	out[34] = 0;
	out[35] = 1;
}

/** Applying function <function imu_correct_up at 0x7fe08bb29170> */
static inline void gen_imu_correct_up(FLT *out, const FLT mu, const FLT *imu_rot, const FLT *up_in_obj) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT obj_up_x = up_in_obj[0];
	const GEN_FLT obj_up_y = up_in_obj[1];
	const GEN_FLT obj_up_z = up_in_obj[2];
	const GEN_FLT x0 = (obj_qk * obj_up_x) + (-1 * obj_qi * obj_up_z) + (obj_qw * obj_up_y);
	const GEN_FLT x1 = (obj_qi * obj_up_y) + (obj_qw * obj_up_z) + (-1 * obj_qj * obj_up_x);
	const GEN_FLT x2 = obj_up_x + (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk)));
	const GEN_FLT x3 = x2 * x2;
	const GEN_FLT x4 = (obj_qj * obj_up_z) + (-1 * obj_qk * obj_up_y) + (obj_qw * obj_up_x);
	const GEN_FLT x5 = obj_up_y + (2 * ((x4 * obj_qk) + (-1 * x1 * obj_qi)));
	const GEN_FLT x6 = x5 * x5;
	const GEN_FLT x7 = atan2(sqrt(x3 + x6), obj_up_z + (2 * ((x0 * obj_qi) + (-1 * x4 * obj_qj))));
	const GEN_FLT x8 = 0.25 * (mu * mu) * (x7 * x7);
	const GEN_FLT x9 = x3 * x8;
	const GEN_FLT x10 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? sqrt(
				  (0.25 * (mu * mu) *
				   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					 obj_up_x) *
					((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					 obj_up_x)) *
				   (atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z) *
					atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z))) +
				  (0.25 * (mu * mu) *
				   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					 obj_up_y) *
					((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					 obj_up_y)) *
				   (atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z) *
					atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z))))
			: 1e-10;
	const GEN_FLT x11 = 0.5 * x10;
	const GEN_FLT x12 = sin(x11);
	const GEN_FLT x13 = (x12 * x12) * (1. / (x10 * x10));
	const GEN_FLT x14 = x6 * x8;
	const GEN_FLT x15 = cos(x11);
	const GEN_FLT x16 = 1. / sqrt((x15 * x15) + (x14 * x13) + (x9 * x13));
	const GEN_FLT x17 = 0.5 * mu * x7 * x12 * (1. / x10) * x16;
	const GEN_FLT x18 = x2 * x17;
	const GEN_FLT x19 = x5 * x17;
	const GEN_FLT x20 = x15 * x16;
	out[0] = (x20 * obj_qw) + (-1 * x19 * obj_qi) + (x18 * obj_qj);
	out[1] = (x20 * obj_qi) + (x19 * obj_qw) + (-1 * x18 * obj_qk);
	out[2] = (x20 * obj_qj) + (-1 * x19 * obj_qk) + (-1 * x18 * obj_qw);
	out[3] = (x20 * obj_qk) + (x19 * obj_qj) + (x18 * obj_qi);
	out[4] = aa_x;
	out[5] = aa_y;
	out[6] = aa_z;
}

// Jacobian of imu_correct_up wrt [mu]
static inline void gen_imu_correct_up_jac_mu(FLT *out, const FLT mu, const FLT *imu_rot, const FLT *up_in_obj) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT obj_up_x = up_in_obj[0];
	const GEN_FLT obj_up_y = up_in_obj[1];
	const GEN_FLT obj_up_z = up_in_obj[2];
	const GEN_FLT x0 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? (1.0 / 2.0 *
			   ((0.5 * mu *
				 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y) *
				  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y)) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * mu *
				 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x) *
				  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x)) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)))) *
			   (1. /
				sqrt(
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x) *
					  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))) +
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y) *
					  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))))))
			: 0;
	const GEN_FLT x1 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? sqrt(
				  (0.25 * (mu * mu) *
				   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					 obj_up_x) *
					((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					 obj_up_x)) *
				   (atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z) *
					atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z))) +
				  (0.25 * (mu * mu) *
				   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					 obj_up_y) *
					((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					 obj_up_y)) *
				   (atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z) *
					atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z))))
			: 1e-10;
	const GEN_FLT x2 = 0.5 * x1;
	const GEN_FLT x3 = sin(x2);
	const GEN_FLT x4 = x0 * x3;
	const GEN_FLT x5 = mu * mu;
	const GEN_FLT x6 = 0.25 * x5;
	const GEN_FLT x7 = (obj_qi * obj_up_y) + (obj_qw * obj_up_z) + (-1 * obj_qj * obj_up_x);
	const GEN_FLT x8 = (obj_qj * obj_up_z) + (-1 * obj_qk * obj_up_y) + (obj_qw * obj_up_x);
	const GEN_FLT x9 = obj_up_y + (2 * ((x8 * obj_qk) + (-1 * x7 * obj_qi)));
	const GEN_FLT x10 = x9 * x9;
	const GEN_FLT x11 = (obj_qk * obj_up_x) + (-1 * obj_qi * obj_up_z) + (obj_qw * obj_up_y);
	const GEN_FLT x12 = obj_up_x + (2 * ((x7 * obj_qj) + (-1 * x11 * obj_qk)));
	const GEN_FLT x13 = x12 * x12;
	const GEN_FLT x14 = atan2(sqrt(x13 + x10), obj_up_z + (2 * ((x11 * obj_qi) + (-1 * x8 * obj_qj))));
	const GEN_FLT x15 = x14 * x14;
	const GEN_FLT x16 = x15 * x13;
	const GEN_FLT x17 = x6 * x16;
	const GEN_FLT x18 = 1. / (x1 * x1);
	const GEN_FLT x19 = x3 * x3;
	const GEN_FLT x20 = x19 * x18;
	const GEN_FLT x21 = x15 * x10;
	const GEN_FLT x22 = x6 * x21;
	const GEN_FLT x23 = cos(x2);
	const GEN_FLT x24 = (x23 * x23) + (x22 * x20) + (x20 * x17);
	const GEN_FLT x25 = 1. / sqrt(x24);
	const GEN_FLT x26 = 0.5 * x25;
	const GEN_FLT x27 = x4 * x26;
	const GEN_FLT x28 = 1. / x1;
	const GEN_FLT x29 = x3 * x28;
	const GEN_FLT x30 = x29 * x26;
	const GEN_FLT x31 = x9 * x14;
	const GEN_FLT x32 = x30 * x31;
	const GEN_FLT x33 = 0.5 * mu;
	const GEN_FLT x34 = x4 * x33 * x25 * x18;
	const GEN_FLT x35 = x31 * x34;
	const GEN_FLT x36 = x23 * obj_qi;
	const GEN_FLT x37 = 0.25 * mu;
	const GEN_FLT x38 = x0 * x36 * x37 * x25 * x28;
	const GEN_FLT x39 = x4 * x23;
	const GEN_FLT x40 = x33 * x16;
	const GEN_FLT x41 = x33 * x21;
	const GEN_FLT x42 = x39 * x18;
	const GEN_FLT x43 = 0.5 * x0 * (1. / (x1 * x1 * x1)) * x5 * x19;
	const GEN_FLT x44 = (1. / (x24 * sqrt(x24))) * ((x42 * x17) + (-1 * x43 * x21) + (-1 * x43 * x16) + (x42 * x22) +
													(x41 * x20) + (x40 * x20) + (-1.0 * x39));
	const GEN_FLT x45 = 1.0 / 2.0 * x44;
	const GEN_FLT x46 = x45 * x23;
	const GEN_FLT x47 = x44 * x29;
	const GEN_FLT x48 = x47 * x37;
	const GEN_FLT x49 = x48 * x31;
	const GEN_FLT x50 = x14 * x12;
	const GEN_FLT x51 = x50 * obj_qj;
	const GEN_FLT x52 = x51 * x37;
	const GEN_FLT x53 = x0 * x25 * x23 * x28;
	const GEN_FLT x54 = x50 * x30;
	const GEN_FLT x55 = x50 * obj_qk;
	const GEN_FLT x56 = x53 * x37;
	const GEN_FLT x57 = x56 * x31;
	const GEN_FLT x58 = x50 * obj_qw;
	const GEN_FLT x59 = x50 * obj_qi;
	out[0] = (-1 * x51 * x34) + (x49 * obj_qi) + (x53 * x52) + (-1 * x46 * obj_qw) + (-1 * x31 * x38) +
			 (-1 * x52 * x47) + (x35 * obj_qi) + (-1 * x32 * obj_qi) + (x51 * x30) + (-1 * x27 * obj_qw);
	out[1] = (x55 * x48) + (-1 * x56 * x55) + (x55 * x34) + (-1 * x54 * obj_qk) + (-1 * x35 * obj_qw) +
			 (-1 * x49 * obj_qw) + (x32 * obj_qw) + (-1 * x27 * obj_qi) + (x57 * obj_qw) + (-1 * x45 * x36);
	out[2] = (-1 * x27 * obj_qj) + (x49 * obj_qk) + (-1 * x54 * obj_qw) + (-1 * x57 * obj_qk) + (x35 * obj_qk) +
			 (-1 * x58 * x56) + (x58 * x48) + (-1 * x32 * obj_qk) + (x58 * x34) + (-1 * x46 * obj_qj);
	out[3] = (-1 * x59 * x34) + (x32 * obj_qj) + (x54 * obj_qi) + (x50 * x38) + (-1 * x35 * obj_qj) + (-1 * x59 * x48) +
			 (-1 * x49 * obj_qj) + (x57 * obj_qj) + (-1 * x27 * obj_qk) + (-1 * x46 * obj_qk);
	out[4] = 0;
	out[5] = 0;
	out[6] = 0;
}

// Jacobian of imu_correct_up wrt [obj_qw, obj_qi, obj_qj, obj_qk, aa_x, aa_y, aa_z]
static inline void gen_imu_correct_up_jac_imu_rot(FLT *out, const FLT mu, const FLT *imu_rot, const FLT *up_in_obj) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT obj_up_x = up_in_obj[0];
	const GEN_FLT obj_up_y = up_in_obj[1];
	const GEN_FLT obj_up_z = up_in_obj[2];
	const GEN_FLT x0 = obj_qw * obj_up_y;
	const GEN_FLT x1 = obj_qi * obj_up_z;
	const GEN_FLT x2 = obj_qk * obj_up_x;
	const GEN_FLT x3 = x2 + (-1 * x1) + x0;
	const GEN_FLT x4 = obj_qj * obj_up_x;
	const GEN_FLT x5 = obj_qw * obj_up_z;
	const GEN_FLT x6 = obj_qi * obj_up_y;
	const GEN_FLT x7 = x6 + x5 + (-1 * x4);
	const GEN_FLT x8 = obj_up_x + (2 * ((x7 * obj_qj) + (-1 * x3 * obj_qk)));
	const GEN_FLT x9 = x8 * x8;
	const GEN_FLT x10 = mu * mu;
	const GEN_FLT x11 = obj_qw * obj_up_x;
	const GEN_FLT x12 = obj_qk * obj_up_y;
	const GEN_FLT x13 = obj_qj * obj_up_z;
	const GEN_FLT x14 = x13 + (-1 * x12) + x11;
	const GEN_FLT x15 = obj_up_y + (2 * ((x14 * obj_qk) + (-1 * x7 * obj_qi)));
	const GEN_FLT x16 = x15 * x15;
	const GEN_FLT x17 = x9 + x16;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = obj_up_z + (2 * ((x3 * obj_qi) + (-1 * x14 * obj_qj)));
	const GEN_FLT x20 = atan2(x18, x19);
	const GEN_FLT x21 = (x20 * x20) * x10;
	const GEN_FLT x22 = 0.25 * x21;
	const GEN_FLT x23 = x9 * x22;
	const GEN_FLT x24 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? sqrt(
				  (0.25 * (mu * mu) *
				   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					 obj_up_x) *
					((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					 obj_up_x)) *
				   (atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z) *
					atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z))) +
				  (0.25 * (mu * mu) *
				   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					 obj_up_y) *
					((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					 obj_up_y)) *
				   (atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z) *
					atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z))))
			: 1e-10;
	const GEN_FLT x25 = 1. / (x24 * x24);
	const GEN_FLT x26 = 0.5 * x24;
	const GEN_FLT x27 = sin(x26);
	const GEN_FLT x28 = x27 * x27;
	const GEN_FLT x29 = x25 * x28;
	const GEN_FLT x30 = x22 * x16;
	const GEN_FLT x31 = cos(x26);
	const GEN_FLT x32 = (x31 * x31) + (x30 * x29) + (x23 * x29);
	const GEN_FLT x33 = 1. / sqrt(x32);
	const GEN_FLT x34 = x31 * x33;
	const GEN_FLT x35 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? (1.0 / 2.0 *
			   (1. /
				sqrt(
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x) *
					  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))) +
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y) *
					  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))))) *
			   ((0.5 * ((-2 * obj_qi * obj_up_z) + (2 * obj_qk * obj_up_x)) * (mu * mu) *
				 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				  obj_up_y) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y) *
				  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y)) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 ((1.0 / 2.0 *
				   ((2 * ((-2 * obj_qk * obj_up_y) + (2 * obj_qj * obj_up_z)) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 * ((-2 * obj_qi * obj_up_z) + (2 * obj_qk * obj_up_x)) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y))) *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 * ((-2 * obj_qj * obj_up_x) + (2 * obj_qi * obj_up_y)) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				(0.5 * ((-2 * obj_qk * obj_up_y) + (2 * obj_qj * obj_up_z)) * (mu * mu) *
				 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				  obj_up_x) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x) *
				  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x)) *
				 ((1.0 / 2.0 *
				   ((2 * ((-2 * obj_qk * obj_up_y) + (2 * obj_qj * obj_up_z)) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 * ((-2 * obj_qi * obj_up_z) + (2 * obj_qk * obj_up_x)) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y))) *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 * ((-2 * obj_qj * obj_up_x) + (2 * obj_qi * obj_up_y)) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))))))
			: 0;
	const GEN_FLT x36 = 1.0 * x31;
	const GEN_FLT x37 = x36 * x27;
	const GEN_FLT x38 = 2 * x12;
	const GEN_FLT x39 = 2 * x13;
	const GEN_FLT x40 = x39 + (-1 * x38);
	const GEN_FLT x41 = 2 * x8;
	const GEN_FLT x42 = 2 * x1;
	const GEN_FLT x43 = 2 * x2;
	const GEN_FLT x44 = x43 + (-1 * x42);
	const GEN_FLT x45 = 2 * x15;
	const GEN_FLT x46 = 1.0 / 2.0 * (1. / x19) * (1. / x18);
	const GEN_FLT x47 = 2 * x4;
	const GEN_FLT x48 = 2 * x6;
	const GEN_FLT x49 = x19 * x19;
	const GEN_FLT x50 = (1. / x49) * x18;
	const GEN_FLT x51 = (-1 * (x48 + (-1 * x47)) * x50) + (((x44 * x45) + (x40 * x41)) * x46);
	const GEN_FLT x52 = (1. / (x17 + x49)) * x49;
	const GEN_FLT x53 = 0.5 * x20 * x10;
	const GEN_FLT x54 = x53 * x16;
	const GEN_FLT x55 = x54 * x52;
	const GEN_FLT x56 = x51 * x55;
	const GEN_FLT x57 = 0.5 * x21;
	const GEN_FLT x58 = x57 * (1. / (x24 * x24 * x24)) * x28;
	const GEN_FLT x59 = x58 * x16;
	const GEN_FLT x60 = x8 * x57;
	const GEN_FLT x61 = x60 * x40;
	const GEN_FLT x62 = x57 * x15;
	const GEN_FLT x63 = x62 * x44;
	const GEN_FLT x64 = x9 * x53;
	const GEN_FLT x65 = x64 * x52;
	const GEN_FLT x66 = x65 * x51;
	const GEN_FLT x67 = x9 * x58;
	const GEN_FLT x68 = x35 * x27;
	const GEN_FLT x69 = x31 * x25;
	const GEN_FLT x70 = x69 * x30;
	const GEN_FLT x71 = x69 * x23;
	const GEN_FLT x72 = (x71 * x68) + (x70 * x68) + (-1 * x67 * x35) + (x63 * x29) + (-1 * x59 * x35) + (x56 * x29) +
						(x66 * x29) + (x61 * x29) + (-1 * x35 * x37);
	const GEN_FLT x73 = 1.0 / 2.0 * x31;
	const GEN_FLT x74 = x73 * x72;
	const GEN_FLT x75 = 1. / (x32 * sqrt(x32));
	const GEN_FLT x76 = x75 * obj_qw;
	const GEN_FLT x77 = 1. / x24;
	const GEN_FLT x78 = x77 * x34;
	const GEN_FLT x79 = mu * x20;
	const GEN_FLT x80 = x8 * x79;
	const GEN_FLT x81 = 0.25 * x80;
	const GEN_FLT x82 = x81 * x78;
	const GEN_FLT x83 = x82 * x35;
	const GEN_FLT x84 = 0.5 * x33;
	const GEN_FLT x85 = x84 * obj_qj;
	const GEN_FLT x86 = x85 * x68;
	const GEN_FLT x87 = x80 * x25;
	const GEN_FLT x88 = x79 * x15;
	const GEN_FLT x89 = 0.25 * x88;
	const GEN_FLT x90 = x89 * x78;
	const GEN_FLT x91 = x90 * obj_qi;
	const GEN_FLT x92 = x75 * obj_qj;
	const GEN_FLT x93 = x77 * x27;
	const GEN_FLT x94 = x81 * x93;
	const GEN_FLT x95 = x92 * x94;
	const GEN_FLT x96 = x79 * x93;
	const GEN_FLT x97 = x85 * x96;
	const GEN_FLT x98 = x84 * obj_qi;
	const GEN_FLT x99 = mu * x93;
	const GEN_FLT x100 = x52 * x99;
	const GEN_FLT x101 = x15 * x100;
	const GEN_FLT x102 = x51 * x101;
	const GEN_FLT x103 = x8 * x100;
	const GEN_FLT x104 = x51 * x103;
	const GEN_FLT x105 = x68 * x98;
	const GEN_FLT x106 = x88 * x25;
	const GEN_FLT x107 = x75 * obj_qi;
	const GEN_FLT x108 = x89 * x93;
	const GEN_FLT x109 = x72 * x108;
	const GEN_FLT x110 = x84 * obj_qw;
	const GEN_FLT x111 = x68 * x110;
	const GEN_FLT x112 = x98 * x96;
	const GEN_FLT x113 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? (1.0 / 2.0 *
			   (1. /
				sqrt(
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x) *
					  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))) +
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y) *
					  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))))) *
			   ((0.5 * (mu * mu) *
				 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				  obj_up_y) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				 ((-4 * obj_qi * obj_up_y) + (-2 * obj_qw * obj_up_z) + (2 * obj_qj * obj_up_x))) +
				(0.5 * ((2 * obj_qk * obj_up_z) + (2 * obj_qj * obj_up_y)) * (mu * mu) *
				 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				  obj_up_x) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y) *
				  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y)) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 ((1.0 / 2.0 *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   ((2 * ((2 * obj_qk * obj_up_z) + (2 * obj_qj * obj_up_y)) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y) *
					 ((-4 * obj_qi * obj_up_y) + (-2 * obj_qw * obj_up_z) + (2 * obj_qj * obj_up_x)))) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   ((2 * obj_qk * obj_up_x) + (-4 * obj_qi * obj_up_z) + (2 * obj_qw * obj_up_y)) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x) *
				  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x)) *
				 ((1.0 / 2.0 *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   ((2 * ((2 * obj_qk * obj_up_z) + (2 * obj_qj * obj_up_y)) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y) *
					 ((-4 * obj_qi * obj_up_y) + (-2 * obj_qw * obj_up_z) + (2 * obj_qj * obj_up_x)))) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   ((2 * obj_qk * obj_up_x) + (-4 * obj_qi * obj_up_z) + (2 * obj_qw * obj_up_y)) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))))))
			: 0;
	const GEN_FLT x114 = x27 * x113;
	const GEN_FLT x115 = 2 * x5;
	const GEN_FLT x116 = x47 + (-1 * x115) + (-4 * x6);
	const GEN_FLT x117 = x62 * x116;
	const GEN_FLT x118 = 2 * obj_qk * obj_up_z;
	const GEN_FLT x119 = 2 * obj_qj * obj_up_y;
	const GEN_FLT x120 = x119 + x118;
	const GEN_FLT x121 = x60 * x120;
	const GEN_FLT x122 = 2 * x0;
	const GEN_FLT x123 = x52 * ((-1 * x50 * ((-4 * x1) + x122 + x43)) + (((x45 * x116) + (x41 * x120)) * x46));
	const GEN_FLT x124 = x64 * x123;
	const GEN_FLT x125 = x54 * x123;
	const GEN_FLT x126 = (-1 * x67 * x113) + (x71 * x114) + (x29 * x125) + (-1 * x59 * x113) + (x29 * x121) +
						 (x70 * x114) + (x29 * x124) + (x29 * x117) + (-1 * x36 * x114);
	const GEN_FLT x127 = x73 * x126;
	const GEN_FLT x128 = x110 * x114;
	const GEN_FLT x129 = x82 * obj_qj;
	const GEN_FLT x130 = x85 * x114;
	const GEN_FLT x131 = x8 * x99;
	const GEN_FLT x132 = x123 * x131;
	const GEN_FLT x133 = x94 * x126;
	const GEN_FLT x134 = x84 * x93;
	const GEN_FLT x135 = x88 * x134;
	const GEN_FLT x136 = -1 * x135;
	const GEN_FLT x137 = x98 * x114;
	const GEN_FLT x138 = x98 * x123;
	const GEN_FLT x139 = x99 * x15;
	const GEN_FLT x140 = x107 * x126;
	const GEN_FLT x141 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? (1.0 / 2.0 *
			   (1. /
				sqrt(
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x) *
					  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))) +
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y) *
					  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))))) *
			   ((0.5 * ((2 * obj_qi * obj_up_x) + (2 * obj_qk * obj_up_z)) * (mu * mu) *
				 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				  obj_up_y) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y) *
				  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y)) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 ((1.0 / 2.0 *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))) *
				   ((2 *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x) *
					 ((2 * obj_qi * obj_up_y) + (2 * obj_qw * obj_up_z) + (-4 * obj_qj * obj_up_x))) +
					(2 * ((2 * obj_qi * obj_up_x) + (2 * obj_qk * obj_up_z)) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y)))) +
				  (-1 *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   ((-4 * obj_qj * obj_up_z) + (2 * obj_qk * obj_up_y) + (-2 * obj_qw * obj_up_x)) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				(0.5 * (mu * mu) *
				 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				  obj_up_x) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				 ((2 * obj_qi * obj_up_y) + (2 * obj_qw * obj_up_z) + (-4 * obj_qj * obj_up_x))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x) *
				  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 ((1.0 / 2.0 *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))) *
				   ((2 *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x) *
					 ((2 * obj_qi * obj_up_y) + (2 * obj_qw * obj_up_z) + (-4 * obj_qj * obj_up_x))) +
					(2 * ((2 * obj_qi * obj_up_x) + (2 * obj_qk * obj_up_z)) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y)))) +
				  (-1 *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   ((-4 * obj_qj * obj_up_z) + (2 * obj_qk * obj_up_y) + (-2 * obj_qw * obj_up_x)) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))))))
			: 0;
	const GEN_FLT x142 = x27 * x141;
	const GEN_FLT x143 = x110 * x142;
	const GEN_FLT x144 = (-4 * x4) + x115 + x48;
	const GEN_FLT x145 = 2 * obj_qi * obj_up_x;
	const GEN_FLT x146 = x118 + x145;
	const GEN_FLT x147 = 2 * x11;
	const GEN_FLT x148 = (-1 * x50 * ((-1 * x147) + x38 + (-4 * x13))) + (((x45 * x146) + (x41 * x144)) * x46);
	const GEN_FLT x149 = x103 * x148;
	const GEN_FLT x150 = x55 * x148;
	const GEN_FLT x151 = x60 * x144;
	const GEN_FLT x152 = x62 * x146;
	const GEN_FLT x153 = x65 * x148;
	const GEN_FLT x154 = (x29 * x152) + (x70 * x142) + (x29 * x153) + (x71 * x142) + (-1 * x59 * x141) + (x29 * x151) +
						 (x29 * x150) + (-1 * x67 * x141) + (-1 * x37 * x141);
	const GEN_FLT x155 = x73 * x154;
	const GEN_FLT x156 = x85 * x142;
	const GEN_FLT x157 = x96 * x146;
	const GEN_FLT x158 = x80 * x134;
	const GEN_FLT x159 = x98 * x142;
	const GEN_FLT x160 = x98 * x148;
	const GEN_FLT x161 = x82 * x141;
	const GEN_FLT x162 = x108 * x154;
	const GEN_FLT x163 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? (1.0 / 2.0 *
			   (1. /
				sqrt(
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x) *
					  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))) +
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y) *
					  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))))) *
			   ((0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y) *
				  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y)) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 ((1.0 / 2.0 *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))) *
				   ((2 *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x) *
					 ((-4 * obj_qk * obj_up_x) + (2 * obj_qi * obj_up_z) + (-2 * obj_qw * obj_up_y))) +
					(2 *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y) *
					 ((2 * obj_qj * obj_up_z) + (-4 * obj_qk * obj_up_y) + (2 * obj_qw * obj_up_x))))) +
				  (-1 * ((2 * obj_qj * obj_up_y) + (2 * obj_qi * obj_up_x)) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				(0.5 * (mu * mu) *
				 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				  obj_up_y) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				 ((2 * obj_qj * obj_up_z) + (-4 * obj_qk * obj_up_y) + (2 * obj_qw * obj_up_x))) +
				(0.5 * (mu * mu) *
				 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				  obj_up_x) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				 ((-4 * obj_qk * obj_up_x) + (2 * obj_qi * obj_up_z) + (-2 * obj_qw * obj_up_y))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x) *
				  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 ((1.0 / 2.0 *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))) *
				   ((2 *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x) *
					 ((-4 * obj_qk * obj_up_x) + (2 * obj_qi * obj_up_z) + (-2 * obj_qw * obj_up_y))) +
					(2 *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y) *
					 ((2 * obj_qj * obj_up_z) + (-4 * obj_qk * obj_up_y) + (2 * obj_qw * obj_up_x))))) +
				  (-1 * ((2 * obj_qj * obj_up_y) + (2 * obj_qi * obj_up_x)) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))))))
			: 0;
	const GEN_FLT x164 = x27 * x163;
	const GEN_FLT x165 = x110 * x164;
	const GEN_FLT x166 = x85 * x164;
	const GEN_FLT x167 = (-1 * x122) + x42 + (-4 * x2);
	const GEN_FLT x168 = x147 + (-4 * x12) + x39;
	const GEN_FLT x169 = x52 * ((-1 * (x145 + x119) * x50) + (((x45 * x168) + (x41 * x167)) * x46));
	const GEN_FLT x170 = x169 * x131;
	const GEN_FLT x171 = x62 * x168;
	const GEN_FLT x172 = x60 * x167;
	const GEN_FLT x173 = x64 * x169;
	const GEN_FLT x174 = x54 * x169;
	const GEN_FLT x175 = (x71 * x164) + (x29 * x174) + (-1 * x67 * x163) + (x29 * x173) + (-1 * x37 * x163) +
						 (x29 * x172) + (x70 * x164) + (-1 * x59 * x163) + (x29 * x171);
	const GEN_FLT x176 = x94 * x175;
	const GEN_FLT x177 = x73 * x175;
	const GEN_FLT x178 = x98 * x164;
	const GEN_FLT x179 = x169 * x139;
	const GEN_FLT x180 = x82 * x163;
	const GEN_FLT x181 = x108 * x175;
	const GEN_FLT x182 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? 0
			: 0;
	const GEN_FLT x183 = x27 * x182;
	const GEN_FLT x184 = (x71 * x183) + (-1 * x67 * x182) + (x70 * x183) + (-1 * x37 * x182) + (-1 * x59 * x182);
	const GEN_FLT x185 = x73 * x184;
	const GEN_FLT x186 = x110 * x183;
	const GEN_FLT x187 = x98 * x183;
	const GEN_FLT x188 = x85 * x183;
	const GEN_FLT x189 = (-1 * x91 * x182) + (x129 * x182) + (-1 * x95 * x184) + (x106 * x187) + (x108 * x107 * x184) +
						 (-1 * x87 * x188) + (-1 * x186) + (-1 * x76 * x185);
	const GEN_FLT x190 = x96 * x110;
	const GEN_FLT x191 = x84 * obj_qk;
	const GEN_FLT x192 = x68 * x191;
	const GEN_FLT x193 = x75 * obj_qk;
	const GEN_FLT x194 = x90 * obj_qw;
	const GEN_FLT x195 = x96 * x191;
	const GEN_FLT x196 = x73 * x107;
	const GEN_FLT x197 = x114 * x191;
	const GEN_FLT x198 = x108 * x126;
	const GEN_FLT x199 = x82 * obj_qk;
	const GEN_FLT x200 = x123 * x139;
	const GEN_FLT x201 = x191 * x142;
	const GEN_FLT x202 = x193 * x154;
	const GEN_FLT x203 = x110 * x148;
	const GEN_FLT x204 = x164 * x191;
	const GEN_FLT x205 = -1 * x158;
	const GEN_FLT x206 = x76 * x184;
	const GEN_FLT x207 = x182 * obj_qw;
	const GEN_FLT x208 = x184 * x193;
	const GEN_FLT x209 = x183 * x191;
	const GEN_FLT x210 = (x90 * x207) + (x87 * x209) + (x94 * x208) + (-1 * x106 * x186) + (-1 * x182 * x199) +
						 (-1 * x206 * x108) + (-1 * x187) + (-1 * x107 * x185);
	const GEN_FLT x211 = x76 * x94;
	const GEN_FLT x212 = x90 * obj_qk;
	const GEN_FLT x213 = x82 * x113;
	const GEN_FLT x214 = x101 * x148;
	const GEN_FLT x215 = (x87 * x186) + (x94 * x206) + (x209 * x106) + (-1 * x212 * x182) + (x208 * x108) +
						 (-1 * x82 * x207) + (-1 * x188) + (-1 * x92 * x185);
	const GEN_FLT x216 = x94 * x107;
	const GEN_FLT x217 = x90 * obj_qj;
	const GEN_FLT x218 = x92 * x108;
	const GEN_FLT x219 = (x82 * x182 * obj_qi) + (-1 * x87 * x187) + (-1 * x185 * x193) + (-1 * x216 * x184) +
						 (x217 * x182) + (-1 * x106 * x188) + (-1 * x209) + (-1 * x218 * x184);
	out[0] = (-1 * x44 * x112) + (x109 * x107) + x34 + (-1 * x86 * x87) + (-1 * x74 * x76) + (x83 * obj_qj) +
			 (-1 * x91 * x35) + (-1 * x72 * x95) + (x97 * x40) + (-1 * x111) + (-1 * x98 * x102) + (x85 * x104) +
			 (x105 * x106);
	out[1] = (-1 * x138 * x139) + (x106 * x137) + (x108 * x140) + (-1 * x76 * x127) + (-1 * x128) + (-1 * x87 * x130) +
			 (-1 * x112 * x116) + (-1 * x91 * x113) + x136 + (x113 * x129) + (x85 * x132) + (-1 * x92 * x133) +
			 (x97 * x120);
	out[2] = (x97 * x144) + (-1 * x143) + (-1 * x95 * x154) + (-1 * x87 * x156) + (x107 * x162) + (x85 * x149) +
			 (-1 * x76 * x155) + (-1 * x98 * x157) + x158 + (-1 * x101 * x160) + (x161 * obj_qj) + (-1 * x91 * x141) +
			 (x106 * x159);
	out[3] = (x107 * x181) + (x180 * obj_qj) + (-1 * x87 * x166) + (-1 * x91 * x163) + (-1 * x92 * x176) +
			 (x106 * x178) + (-1 * x76 * x177) + (-1 * x112 * x168) + (x85 * x170) + (x97 * x167) + (-1 * x165) +
			 (-1 * x98 * x179);
	out[4] = x189;
	out[5] = x189;
	out[6] = x189;
	out[7] = x135 + (-1 * x76 * x109) + (-1 * x74 * x107) + (x102 * x110) + (-1 * x40 * x195) + (x72 * x94 * x193) +
			 (-1 * x83 * obj_qk) + (-1 * x105) + (x44 * x190) + (x87 * x192) + (-1 * x104 * x191) + (-1 * x106 * x111) +
			 (x35 * x194);
	out[8] = (x116 * x190) + (-1 * x106 * x128) + (x200 * x110) + x34 + (-1 * x126 * x196) + (-1 * x137) +
			 (x87 * x197) + (x193 * x133) + (-1 * x76 * x198) + (-1 * x113 * x199) + (-1 * x191 * x132) +
			 (x113 * x194) + (-1 * x120 * x195);
	out[9] = (x203 * x101) + (-1 * x196 * x154) + (-1 * x159) + (-1 * x161 * obj_qk) + (-1 * x106 * x143) +
			 (-1 * x76 * x162) + (x87 * x201) + (x110 * x157) + (-1 * x195 * x144) + (-1 * x191 * x149) + (x94 * x202) +
			 (x194 * x141);
	out[10] = (-1 * x106 * x165) + (x176 * x193) + (x163 * x194) + (-1 * x175 * x196) + (x168 * x190) + (x87 * x204) +
			  (-1 * x167 * x195) + (-1 * x76 * x181) + (-1 * x180 * obj_qk) + x205 + (-1 * x178) + (x110 * x179) +
			  (-1 * x170 * x191);
	out[11] = x210;
	out[12] = x210;
	out[13] = x210;
	out[14] = (-1 * x35 * x212) + (x72 * x211) + (-1 * x83 * obj_qw) + (-1 * x74 * x92) + (-1 * x102 * x191) + x205 +
			  (-1 * x86) + (x109 * x193) + (x87 * x111) + (-1 * x40 * x190) + (-1 * x104 * x110) + (-1 * x44 * x195) +
			  (x106 * x192);
	out[15] = (x198 * x193) + (-1 * x213 * obj_qw) + (-1 * x92 * x127) + (-1 * x130) + (-1 * x110 * x132) +
			  (-1 * x200 * x191) + (-1 * x120 * x190) + (x106 * x197) + (-1 * x116 * x195) + (x87 * x128) +
			  (x76 * x133) + (-1 * x212 * x113);
	out[16] = (x202 * x108) + (-1 * x214 * x191) + (-1 * x92 * x155) + x34 + (-1 * x191 * x157) + (-1 * x156) +
			  (x211 * x154) + (x87 * x143) + (-1 * x203 * x103) + (-1 * x190 * x144) + (-1 * x161 * obj_qw) +
			  (-1 * x212 * x141) + (x201 * x106);
	out[17] = (x181 * x193) + (x204 * x106) + (-1 * x92 * x177) + (-1 * x110 * x170) + (-1 * x167 * x190) +
			  (-1 * x166) + (-1 * x168 * x195) + (x87 * x165) + (-1 * x180 * obj_qw) + (-1 * x179 * x191) +
			  (x76 * x176) + (-1 * x212 * x163) + x136;
	out[18] = x215;
	out[19] = x215;
	out[20] = x215;
	out[21] = (x97 * x44) + (-1 * x74 * x193) + (-1 * x192) + (x98 * x104) + (-1 * x72 * x216) + (-1 * x92 * x109) +
			  (-1 * x87 * x105) + (x83 * obj_qi) + (x40 * x112) + (x85 * x102) + (x35 * x217) + (-1 * x86 * x106);
	out[22] = (-1 * x106 * x130) + (-1 * x218 * x126) + (-1 * x197) + (x131 * x138) + (x97 * x116) + (x213 * obj_qi) +
			  (x85 * x200) + (-1 * x87 * x137) + (-1 * x94 * x140) + (x217 * x113) + x158 + (x112 * x120) +
			  (-1 * x127 * x193);
	out[23] = (x217 * x141) + (-1 * x87 * x159) + (x85 * x157) + (x103 * x160) + (x85 * x214) + (x161 * obj_qi) +
			  (-1 * x73 * x202) + (-1 * x106 * x156) + x135 + (-1 * x216 * x154) + (x112 * x144) + (-1 * x201) +
			  (-1 * x218 * x154);
	out[24] = (-1 * x106 * x166) + (-1 * x218 * x175) + x34 + (x97 * x168) + (-1 * x177 * x193) + (x98 * x170) +
			  (-1 * x204) + (x217 * x163) + (-1 * x87 * x178) + (x85 * x179) + (x180 * obj_qi) + (x112 * x167) +
			  (-1 * x216 * x175);
	out[25] = x219;
	out[26] = x219;
	out[27] = x219;
	out[28] = 0;
	out[29] = 0;
	out[30] = 0;
	out[31] = 0;
	out[32] = 1;
	out[33] = 0;
	out[34] = 0;
	out[35] = 0;
	out[36] = 0;
	out[37] = 0;
	out[38] = 0;
	out[39] = 0;
	out[40] = 1;
	out[41] = 0;
	out[42] = 0;
	out[43] = 0;
	out[44] = 0;
	out[45] = 0;
	out[46] = 0;
	out[47] = 0;
	out[48] = 1;
}

// Jacobian of imu_correct_up wrt [obj_up_x, obj_up_y, obj_up_z]
static inline void gen_imu_correct_up_jac_up_in_obj(FLT *out, const FLT mu, const FLT *imu_rot, const FLT *up_in_obj) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT obj_up_x = up_in_obj[0];
	const GEN_FLT obj_up_y = up_in_obj[1];
	const GEN_FLT obj_up_z = up_in_obj[2];
	const GEN_FLT x0 = 2 * obj_qj;
	const GEN_FLT x1 = x0 * obj_qi;
	const GEN_FLT x2 = 2 * obj_qk;
	const GEN_FLT x3 = x2 * obj_qw;
	const GEN_FLT x4 = x3 + x1;
	const GEN_FLT x5 = (obj_qi * obj_up_y) + (obj_qw * obj_up_z) + (-1 * obj_qj * obj_up_x);
	const GEN_FLT x6 = (obj_qj * obj_up_z) + (-1 * obj_qk * obj_up_y) + (obj_qw * obj_up_x);
	const GEN_FLT x7 = obj_up_y + (2 * ((x6 * obj_qk) + (-1 * x5 * obj_qi)));
	const GEN_FLT x8 = mu * mu;
	const GEN_FLT x9 = x7 * x7;
	const GEN_FLT x10 = (obj_qk * obj_up_x) + (-1 * obj_qi * obj_up_z) + (obj_qw * obj_up_y);
	const GEN_FLT x11 = obj_up_x + (2 * ((x5 * obj_qj) + (-1 * x10 * obj_qk)));
	const GEN_FLT x12 = x11 * x11;
	const GEN_FLT x13 = x12 + x9;
	const GEN_FLT x14 = sqrt(x13);
	const GEN_FLT x15 = obj_up_z + (2 * ((x10 * obj_qi) + (-1 * x6 * obj_qj)));
	const GEN_FLT x16 = atan2(x14, x15);
	const GEN_FLT x17 = x8 * (x16 * x16);
	const GEN_FLT x18 = 0.5 * x17;
	const GEN_FLT x19 = x7 * x18;
	const GEN_FLT x20 = x4 * x19;
	const GEN_FLT x21 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? sqrt(
				  (0.25 * (mu * mu) *
				   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					 obj_up_x) *
					((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					 obj_up_x)) *
				   (atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z) *
					atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z))) +
				  (0.25 * (mu * mu) *
				   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					 obj_up_y) *
					((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					 obj_up_y)) *
				   (atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z) *
					atan2(
						sqrt(
							(((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
						(2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							  (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							obj_up_z))))
			: 1e-10;
	const GEN_FLT x22 = 1. / (x21 * x21);
	const GEN_FLT x23 = 0.5 * x21;
	const GEN_FLT x24 = sin(x23);
	const GEN_FLT x25 = x24 * x24;
	const GEN_FLT x26 = x25 * x22;
	const GEN_FLT x27 = -2 * (obj_qk * obj_qk);
	const GEN_FLT x28 = -2 * (obj_qj * obj_qj);
	const GEN_FLT x29 = 1 + x28 + x27;
	const GEN_FLT x30 = 2 * x11;
	const GEN_FLT x31 = 2 * x7;
	const GEN_FLT x32 = 1.0 / 2.0 * (1. / x15) * (1. / x14);
	const GEN_FLT x33 = x0 * obj_qw;
	const GEN_FLT x34 = x2 * obj_qi;
	const GEN_FLT x35 = x15 * x15;
	const GEN_FLT x36 = (1. / x35) * x14;
	const GEN_FLT x37 = (-1 * (x34 + (-1 * x33)) * x36) + (x32 * ((x4 * x31) + (x30 * x29)));
	const GEN_FLT x38 = (1. / (x13 + x35)) * x35;
	const GEN_FLT x39 = 0.5 * x8 * x16;
	const GEN_FLT x40 = x9 * x39;
	const GEN_FLT x41 = x40 * x38;
	const GEN_FLT x42 = x41 * x37;
	const GEN_FLT x43 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? (1.0 / 2.0 *
			   (1. /
				sqrt(
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x) *
					  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))) +
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y) *
					  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))))) *
			   ((0.5 * ((2 * obj_qj * obj_qi) + (2 * obj_qw * obj_qk)) * (mu * mu) *
				 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				  obj_up_y) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * (mu * mu) *
				 ((1.0 / 2.0 *
				   ((2 * (1 + (-2 * (obj_qk * obj_qk)) + (-2 * (obj_qj * obj_qj))) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 * ((2 * obj_qj * obj_qi) + (2 * obj_qw * obj_qk)) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y))) *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 * ((-2 * obj_qw * obj_qj) + (2 * obj_qk * obj_qi)) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y) *
				  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y)) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				(0.5 * (1 + (-2 * (obj_qk * obj_qk)) + (-2 * (obj_qj * obj_qj))) * (mu * mu) *
				 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				  obj_up_x) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * (mu * mu) *
				 ((1.0 / 2.0 *
				   ((2 * (1 + (-2 * (obj_qk * obj_qk)) + (-2 * (obj_qj * obj_qj))) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 * ((2 * obj_qj * obj_qi) + (2 * obj_qw * obj_qk)) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y))) *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 * ((-2 * obj_qw * obj_qj) + (2 * obj_qk * obj_qi)) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x) *
				  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))))))
			: 0;
	const GEN_FLT x44 = x43 * x24;
	const GEN_FLT x45 = 0.25 * x17;
	const GEN_FLT x46 = x9 * x45;
	const GEN_FLT x47 = cos(x23);
	const GEN_FLT x48 = x47 * x22;
	const GEN_FLT x49 = x46 * x48;
	const GEN_FLT x50 = x11 * x18;
	const GEN_FLT x51 = x50 * x29;
	const GEN_FLT x52 = x25 * (1. / (x21 * x21 * x21)) * x18;
	const GEN_FLT x53 = x9 * x52;
	const GEN_FLT x54 = x39 * x12;
	const GEN_FLT x55 = x54 * x38;
	const GEN_FLT x56 = x55 * x37;
	const GEN_FLT x57 = x45 * x12;
	const GEN_FLT x58 = x57 * x48;
	const GEN_FLT x59 = 1.0 * x47;
	const GEN_FLT x60 = x52 * x12;
	const GEN_FLT x61 = (-1 * x60 * x43) + (x58 * x44) + (x56 * x26) + (-1 * x59 * x44) + (-1 * x53 * x43) +
						(x51 * x26) + (x44 * x49) + (x42 * x26) + (x20 * x26);
	const GEN_FLT x62 = (x47 * x47) + (x46 * x26) + (x57 * x26);
	const GEN_FLT x63 = 1. / (x62 * sqrt(x62));
	const GEN_FLT x64 = 1.0 / 2.0 * x47;
	const GEN_FLT x65 = x63 * x64;
	const GEN_FLT x66 = x61 * x65;
	const GEN_FLT x67 = 1. / sqrt(x62);
	const GEN_FLT x68 = 0.5 * x67;
	const GEN_FLT x69 = x68 * x44;
	const GEN_FLT x70 = x69 * obj_qw;
	const GEN_FLT x71 = x69 * obj_qj;
	const GEN_FLT x72 = mu * x16;
	const GEN_FLT x73 = x72 * x22;
	const GEN_FLT x74 = x73 * x11;
	const GEN_FLT x75 = x68 * obj_qi;
	const GEN_FLT x76 = x75 * x44;
	const GEN_FLT x77 = x7 * x73;
	const GEN_FLT x78 = 1. / x21;
	const GEN_FLT x79 = x72 * x78;
	const GEN_FLT x80 = x79 * x24;
	const GEN_FLT x81 = x80 * x63;
	const GEN_FLT x82 = x81 * x61;
	const GEN_FLT x83 = 0.25 * x7;
	const GEN_FLT x84 = x83 * obj_qi;
	const GEN_FLT x85 = x79 * x67 * x47;
	const GEN_FLT x86 = x85 * x43;
	const GEN_FLT x87 = 0.25 * x11;
	const GEN_FLT x88 = x87 * obj_qj;
	const GEN_FLT x89 = x80 * x68;
	const GEN_FLT x90 = x89 * obj_qj;
	const GEN_FLT x91 = mu * x78 * x24;
	const GEN_FLT x92 = x7 * x91;
	const GEN_FLT x93 = x75 * x92;
	const GEN_FLT x94 = x38 * x37;
	const GEN_FLT x95 = x68 * obj_qj;
	const GEN_FLT x96 = x91 * x11;
	const GEN_FLT x97 = x96 * x38;
	const GEN_FLT x98 = x97 * x37;
	const GEN_FLT x99 = x80 * x75;
	const GEN_FLT x100 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? (1.0 / 2.0 *
			   (1. /
				sqrt(
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x) *
					  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))) +
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y) *
					  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))))) *
			   ((0.5 * (1 + (-2 * (obj_qi * obj_qi)) + (-2 * (obj_qk * obj_qk))) * (mu * mu) *
				 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				  obj_up_y) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y) *
				  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y)) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 ((1.0 / 2.0 *
				   ((2 * ((-2 * obj_qw * obj_qk) + (2 * obj_qj * obj_qi)) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 * (1 + (-2 * (obj_qi * obj_qi)) + (-2 * (obj_qk * obj_qk))) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y))) *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 * ((2 * obj_qk * obj_qj) + (2 * obj_qw * obj_qi)) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				(0.5 * ((-2 * obj_qw * obj_qk) + (2 * obj_qj * obj_qi)) * (mu * mu) *
				 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				  obj_up_x) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x) *
				  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 ((1.0 / 2.0 *
				   ((2 * ((-2 * obj_qw * obj_qk) + (2 * obj_qj * obj_qi)) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 * (1 + (-2 * (obj_qi * obj_qi)) + (-2 * (obj_qk * obj_qk))) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y))) *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 * ((2 * obj_qk * obj_qj) + (2 * obj_qw * obj_qi)) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))))))
			: 0;
	const GEN_FLT x101 = x24 * x100;
	const GEN_FLT x102 = x68 * x101;
	const GEN_FLT x103 = x102 * obj_qw;
	const GEN_FLT x104 = x85 * x100;
	const GEN_FLT x105 = x1 + (-1 * x3);
	const GEN_FLT x106 = 1 + (-2 * (obj_qi * obj_qi));
	const GEN_FLT x107 = x106 + x27;
	const GEN_FLT x108 = x2 * obj_qj;
	const GEN_FLT x109 = 2 * obj_qw * obj_qi;
	const GEN_FLT x110 = (-1 * (x109 + x108) * x36) + (((x31 * x107) + (x30 * x105)) * x32);
	const GEN_FLT x111 = x97 * x110;
	const GEN_FLT x112 = x19 * x107;
	const GEN_FLT x113 = x41 * x110;
	const GEN_FLT x114 = x59 * x24;
	const GEN_FLT x115 = x50 * x105;
	const GEN_FLT x116 = x55 * x110;
	const GEN_FLT x117 = (x58 * x101) + (x26 * x116) + (x26 * x115) + (-1 * x53 * x100) + (x26 * x113) +
						 (-1 * x60 * x100) + (x49 * x101) + (-1 * x100 * x114) + (x26 * x112);
	const GEN_FLT x118 = x65 * x117;
	const GEN_FLT x119 = x81 * x117;
	const GEN_FLT x120 = x75 * x101;
	const GEN_FLT x121 = x38 * x110;
	const GEN_FLT x122 = x80 * x105;
	const GEN_FLT x123 = x68 * x122;
	const GEN_FLT x124 = x102 * obj_qj;
	const GEN_FLT x125 =
		(1e-20 <
		 ((0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x) *
			((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
				   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
			 obj_up_x)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) +
		  (0.25 * (mu * mu) *
		   (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y) *
			((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
				   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
			 obj_up_y)) *
		   (atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
			atan2(sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y) *
						((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						 obj_up_y)) +
					   (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x) *
						((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						 obj_up_x))),
				  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z)))))
			? (1.0 / 2.0 *
			   (1. /
				sqrt(
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x) *
					  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					   obj_up_x)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))) +
					(0.25 * (mu * mu) *
					 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y) *
					  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					   obj_up_y)) *
					 (atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z) *
					  atan2(
						  sqrt((((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y) *
								((2 *
								  ((-1 * obj_qi *
									((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
								 obj_up_y)) +
							   (((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x) *
								((2 *
								  ((-1 * obj_qk *
									((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
								 obj_up_x))),
						  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
							  obj_up_z))))) *
			   ((0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y) *
				  ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						 (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				   obj_up_y)) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 ((1.0 / 2.0 *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   ((2 * ((2 * obj_qk * obj_qi) + (2 * obj_qw * obj_qj)) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 * ((-2 * obj_qw * obj_qi) + (2 * obj_qk * obj_qj)) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y))) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 * (1 + (-2 * (obj_qj * obj_qj)) + (-2 * (obj_qi * obj_qi))) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				(0.5 * ((2 * obj_qk * obj_qi) + (2 * obj_qw * obj_qj)) * (mu * mu) *
				 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				  obj_up_x) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * ((-2 * obj_qw * obj_qi) + (2 * obj_qk * obj_qj)) * (mu * mu) *
				 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
						(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
				  obj_up_y) *
				 (atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
				  atan2(
					  sqrt((((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y) *
							((2 *
							  ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							   (obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							 obj_up_y)) +
						   (((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x) *
							((2 *
							  ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							   (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							 obj_up_x))),
					  (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z))) +
				(0.5 * (mu * mu) *
				 (((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z) *
				  ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
						 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
				   obj_up_z)) *
				 (((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x) *
				  ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
						 (obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
				   obj_up_x)) *
				 atan2(sqrt((((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y) *
							 ((2 *
							   ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
							  obj_up_y)) +
							(((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x) *
							 ((2 *
							   ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
							  obj_up_x))),
					   (2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							 (obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						   obj_up_z) *
				 ((1.0 / 2.0 *
				   (1. / ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) *
				   ((2 * ((2 * obj_qk * obj_qi) + (2 * obj_qw * obj_qj)) *
					 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
							(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
					  obj_up_x)) +
					(2 * ((-2 * obj_qw * obj_qi) + (2 * obj_qk * obj_qj)) *
					 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
							(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
					  obj_up_y))) *
				   (1. /
					sqrt(
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) +
				  (-1 * (1 + (-2 * (obj_qj * obj_qj)) + (-2 * (obj_qi * obj_qi))) *
				   (1. /
					(((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z) *
					 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
							(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
					  obj_up_z))) *
				   sqrt((((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x))))) *
				 (1. / ((((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z) *
						 ((2 * ((-1 * obj_qj * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))) +
								(obj_qi * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))))) +
						  obj_up_z)) +
						(((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y) *
						 ((2 * ((-1 * obj_qi * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))) +
								(obj_qk * ((obj_qw * obj_up_x) + (-1 * obj_qk * obj_up_y) + (obj_qj * obj_up_z))))) +
						  obj_up_y)) +
						(((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x) *
						 ((2 * ((-1 * obj_qk * ((obj_qw * obj_up_y) + (-1 * obj_qi * obj_up_z) + (obj_qk * obj_up_x))) +
								(obj_qj * ((-1 * obj_qj * obj_up_x) + (obj_qw * obj_up_z) + (obj_qi * obj_up_y))))) +
						  obj_up_x)))))))
			: 0;
	const GEN_FLT x126 = x24 * x125;
	const GEN_FLT x127 = x68 * x126;
	const GEN_FLT x128 = x127 * obj_qw;
	const GEN_FLT x129 = x33 + x34;
	const GEN_FLT x130 = x108 + (-1 * x109);
	const GEN_FLT x131 = x38 * ((-1 * x36 * (x106 + x28)) + (((x31 * x130) + (x30 * x129)) * x32));
	const GEN_FLT x132 = x19 * x130;
	const GEN_FLT x133 = x40 * x131;
	const GEN_FLT x134 = x50 * x129;
	const GEN_FLT x135 = x54 * x131;
	const GEN_FLT x136 = (-1 * x60 * x125) + (x49 * x126) + (-1 * x114 * x125) + (x26 * x134) + (x58 * x126) +
						 (x26 * x135) + (x26 * x133) + (-1 * x53 * x125) + (x26 * x132);
	const GEN_FLT x137 = x65 * x136;
	const GEN_FLT x138 = x127 * obj_qj;
	const GEN_FLT x139 = x85 * x125;
	const GEN_FLT x140 = x83 * x139;
	const GEN_FLT x141 = x96 * x131;
	const GEN_FLT x142 = x81 * x136;
	const GEN_FLT x143 = x75 * x126;
	const GEN_FLT x144 = x87 * obj_qk;
	const GEN_FLT x145 = x69 * obj_qk;
	const GEN_FLT x146 = x63 * obj_qk;
	const GEN_FLT x147 = x80 * x146;
	const GEN_FLT x148 = x87 * x147;
	const GEN_FLT x149 = x68 * obj_qw;
	const GEN_FLT x150 = x92 * x149;
	const GEN_FLT x151 = x68 * obj_qk;
	const GEN_FLT x152 = x80 * x151;
	const GEN_FLT x153 = x83 * obj_qw;
	const GEN_FLT x154 = x89 * obj_qw;
	const GEN_FLT x155 = x102 * obj_qk;
	const GEN_FLT x156 = x127 * obj_qk;
	const GEN_FLT x157 = x136 * x146;
	const GEN_FLT x158 = x80 * x157;
	const GEN_FLT x159 = x87 * obj_qw;
	const GEN_FLT x160 = x83 * obj_qk;
	const GEN_FLT x161 = x92 * x151;
	const GEN_FLT x162 = x83 * x147;
	const GEN_FLT x163 = x87 * obj_qi;
	const GEN_FLT x164 = x64 * x146;
	const GEN_FLT x165 = x83 * obj_qj;
	const GEN_FLT x166 = x92 * x95;
	out[0] = (-1 * x4 * x99) + (x98 * x95) + (-1 * x66 * obj_qw) + (-1 * x70) + (x90 * x29) + (x77 * x76) +
			 (x88 * x86) + (-1 * x71 * x74) + (-1 * x82 * x88) + (-1 * x84 * x86) + (x82 * x84) + (-1 * x93 * x94);
	out[1] = (-1 * x84 * x104) + (-1 * x103) + (x84 * x119) + (x88 * x104) + (-1 * x118 * obj_qw) + (x77 * x120) +
			 (-1 * x93 * x121) + (x123 * obj_qj) + (-1 * x99 * x107) + (x95 * x111) + (-1 * x88 * x119) +
			 (-1 * x74 * x124);
	out[2] = (-1 * x99 * x130) + (-1 * x128) + (-1 * x88 * x142) + (x90 * x129) + (-1 * x137 * obj_qw) +
			 (-1 * x74 * x138) + (-1 * x140 * obj_qi) + (x84 * x142) + (x88 * x139) + (-1 * x93 * x131) + (x95 * x141) +
			 (x77 * x143);
	out[3] = (x4 * x154) + (x86 * x153) + (-1 * x76) + (-1 * x66 * obj_qi) + (x74 * x145) + (x61 * x148) +
			 (-1 * x86 * x144) + (x94 * x150) + (-1 * x29 * x152) + (-1 * x70 * x77) + (-1 * x98 * x151) +
			 (-1 * x82 * x153);
	out[4] = (x121 * x150) + (-1 * x118 * obj_qi) + (x104 * x153) + (-1 * x120) + (-1 * x104 * x144) + (x117 * x148) +
			 (-1 * x119 * x153) + (-1 * x122 * x151) + (-1 * x77 * x103) + (x107 * x154) + (x74 * x155) +
			 (-1 * x111 * x151);
	out[5] = (x130 * x154) + (-1 * x77 * x128) + (x87 * x158) + (-1 * x143) + (x131 * x150) + (-1 * x142 * x153) +
			 (-1 * x141 * x151) + (-1 * x137 * obj_qi) + (-1 * x129 * x152) + (x74 * x156) + (x139 * x153) +
			 (-1 * x139 * x144);
	out[6] = (x61 * x162) + (-1 * x66 * obj_qj) + (-1 * x86 * x159) + (-1 * x86 * x160) + (-1 * x71) +
			 (-1 * x94 * x161) + (-1 * x4 * x152) + (x70 * x74) + (-1 * x98 * x149) + (-1 * x29 * x154) + (x82 * x159) +
			 (x77 * x145);
	out[7] = (-1 * x107 * x152) + (x117 * x162) + (-1 * x118 * obj_qj) + (-1 * x104 * x160) + (-1 * x104 * x159) +
			 (-1 * x123 * obj_qw) + (x77 * x155) + (x74 * x103) + (x119 * x159) + (-1 * x111 * x149) +
			 (-1 * x121 * x161) + (-1 * x124);
	out[8] = (x83 * x158) + (-1 * x140 * obj_qk) + (-1 * x138) + (-1 * x137 * obj_qj) + (-1 * x139 * x159) +
			 (-1 * x130 * x152) + (x74 * x128) + (x142 * x159) + (x77 * x156) + (-1 * x141 * x149) +
			 (-1 * x129 * x154) + (-1 * x161 * x131);
	out[9] = (x4 * x90) + (-1 * x82 * x163) + (-1 * x82 * x165) + (-1 * x74 * x76) + (x99 * x29) + (-1 * x71 * x77) +
			 (-1 * x61 * x164) + (-1 * x145) + (x75 * x98) + (x86 * x165) + (x86 * x163) + (x94 * x166);
	out[10] = (x90 * x107) + (-1 * x119 * x165) + (-1 * x117 * x164) + (x104 * x163) + (-1 * x119 * x163) +
			  (x75 * x111) + (x121 * x166) + (x75 * x122) + (-1 * x77 * x124) + (-1 * x74 * x120) + (-1 * x155) +
			  (x104 * x165);
	out[11] = (-1 * x156) + (-1 * x165 * x142) + (-1 * x64 * x157) + (-1 * x74 * x143) + (x99 * x129) +
			  (-1 * x163 * x142) + (x140 * obj_qj) + (x163 * x139) + (x90 * x130) + (x75 * x141) + (-1 * x77 * x138) +
			  (x166 * x131);
	out[12] = 0;
	out[13] = 0;
	out[14] = 0;
	out[15] = 0;
	out[16] = 0;
	out[17] = 0;
	out[18] = 0;
	out[19] = 0;
	out[20] = 0;
}

/** Applying function <function imu_predict_up at 0x7fe08bb11f80> */
static inline void gen_imu_predict_up(FLT *out, const FLT *imu_rot) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT x0 = obj_qj * obj_qj;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = 1. / ((obj_qw * obj_qw) + (obj_qk * obj_qk) + x1 + x0);
	const GEN_FLT x3 = x2 * obj_qk;
	const GEN_FLT x4 = x2 * obj_qw;
	out[0] = 2 * ((-1 * x4 * obj_qj) + (x3 * obj_qi));
	out[1] = 2 * ((x3 * obj_qj) + (x4 * obj_qi));
	out[2] = 1 + (2 * ((-1 * x2 * x1) + (-1 * x0 * x2)));
}

// Jacobian of imu_predict_up wrt [obj_qw, obj_qi, obj_qj, obj_qk, aa_x, aa_y, aa_z]
static inline void gen_imu_predict_up_jac_imu_rot(FLT *out, const FLT *imu_rot) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT x0 = obj_qw * obj_qw;
	const GEN_FLT x1 = obj_qj * obj_qj;
	const GEN_FLT x2 = obj_qi * obj_qi;
	const GEN_FLT x3 = obj_qk * obj_qk;
	const GEN_FLT x4 = x0 + x3 + x2 + x1;
	const GEN_FLT x5 = 1. / (x4 * x4);
	const GEN_FLT x6 = 2 * x5;
	const GEN_FLT x7 = x6 * obj_qj;
	const GEN_FLT x8 = 1. / x4;
	const GEN_FLT x9 = x8 * obj_qj;
	const GEN_FLT x10 = x6 * obj_qk;
	const GEN_FLT x11 = obj_qw * obj_qi;
	const GEN_FLT x12 = -1 * x11 * x10;
	const GEN_FLT x13 = x7 * x11;
	const GEN_FLT x14 = x8 * obj_qk;
	const GEN_FLT x15 = x8 * obj_qw;
	const GEN_FLT x16 = x6 * obj_qw;
	const GEN_FLT x17 = x7 * obj_qk;
	const GEN_FLT x18 = -1 * x17 * obj_qi;
	const GEN_FLT x19 = x17 * obj_qw;
	const GEN_FLT x20 = x6 * obj_qi;
	const GEN_FLT x21 = x8 * obj_qi;
	const GEN_FLT x22 = 4 * x5;
	const GEN_FLT x23 = x1 * x22;
	const GEN_FLT x24 = x2 * x22;
	out[0] = 2 * (x12 + (-1 * x9) + (x0 * x7));
	out[1] = 2 * (x14 + (-1 * x2 * x10) + x13);
	out[2] = 2 * (x18 + (x1 * x16) + (-1 * x15));
	out[3] = 2 * (x21 + (-1 * x3 * x20) + x19);
	out[4] = 0;
	out[5] = 0;
	out[6] = 0;
	out[7] = 2 * (x21 + (-1 * x0 * x20) + (-1 * x19));
	out[8] = 2 * (x15 + (-1 * x2 * x16) + x18);
	out[9] = 2 * ((-1 * x13) + x14 + (-1 * x1 * x10));
	out[10] = 2 * (x12 + x9 + (-1 * x3 * x7));
	out[11] = 0;
	out[12] = 0;
	out[13] = 0;
	out[14] = (x24 * obj_qw) + (x23 * obj_qw);
	out[15] = (x22 * (obj_qi * obj_qi * obj_qi)) + (-4 * x21) + (x23 * obj_qi);
	out[16] = (x24 * obj_qj) + (x22 * (obj_qj * obj_qj * obj_qj)) + (-4 * x9);
	out[17] = (x24 * obj_qk) + (x23 * obj_qk);
	out[18] = 0;
	out[19] = 0;
	out[20] = 0;
}

/** Applying function <function quatrotateabout at 0x7fe08d8e2170> */
static inline void gen_quatrotateabout(FLT *out, const FLT *q1, const FLT *q2) {
	const GEN_FLT obj_qw = q1[0];
	const GEN_FLT obj_qi = q1[1];
	const GEN_FLT obj_qj = q1[2];
	const GEN_FLT obj_qk = q1[3];
	const GEN_FLT q1_w = q2[0];
	const GEN_FLT q1_x = q2[1];
	const GEN_FLT q1_y = q2[2];
	const GEN_FLT q1_z = q2[3];

	out[0] = (q1_w * obj_qw) + (-1 * q1_x * obj_qi) + (-1 * q1_y * obj_qj) + (-1 * q1_z * obj_qk);
	out[1] = (q1_x * obj_qw) + (q1_w * obj_qi) + (q1_z * obj_qj) + (-1 * q1_y * obj_qk);
	out[2] = (q1_y * obj_qw) + (-1 * q1_z * obj_qi) + (q1_x * obj_qk) + (q1_w * obj_qj);
	out[3] = (q1_z * obj_qw) + (q1_y * obj_qi) + (-1 * q1_x * obj_qj) + (q1_w * obj_qk);
}

// Jacobian of quatrotateabout wrt [obj_qw, obj_qi, obj_qj, obj_qk]
static inline void gen_quatrotateabout_jac_q1(FLT *out, const FLT *q1, const FLT *q2) {
	const GEN_FLT obj_qw = q1[0];
	const GEN_FLT obj_qi = q1[1];
	const GEN_FLT obj_qj = q1[2];
	const GEN_FLT obj_qk = q1[3];
	const GEN_FLT q1_w = q2[0];
	const GEN_FLT q1_x = q2[1];
	const GEN_FLT q1_y = q2[2];
	const GEN_FLT q1_z = q2[3];
	const GEN_FLT x0 = -1 * q1_x;
	const GEN_FLT x1 = -1 * q1_y;
	const GEN_FLT x2 = -1 * q1_z;
	out[0] = q1_w;
	out[1] = x0;
	out[2] = x1;
	out[3] = x2;
	out[4] = q1_x;
	out[5] = q1_w;
	out[6] = q1_z;
	out[7] = x1;
	out[8] = q1_y;
	out[9] = x2;
	out[10] = q1_w;
	out[11] = q1_x;
	out[12] = q1_z;
	out[13] = q1_y;
	out[14] = x0;
	out[15] = q1_w;
}

// Jacobian of quatrotateabout wrt [q1_w, q1_x, q1_y, q1_z]
static inline void gen_quatrotateabout_jac_q2(FLT *out, const FLT *q1, const FLT *q2) {
	const GEN_FLT obj_qw = q1[0];
	const GEN_FLT obj_qi = q1[1];
	const GEN_FLT obj_qj = q1[2];
	const GEN_FLT obj_qk = q1[3];
	const GEN_FLT q1_w = q2[0];
	const GEN_FLT q1_x = q2[1];
	const GEN_FLT q1_y = q2[2];
	const GEN_FLT q1_z = q2[3];
	const GEN_FLT x0 = -1 * obj_qi;
	const GEN_FLT x1 = -1 * obj_qj;
	const GEN_FLT x2 = -1 * obj_qk;
	out[0] = obj_qw;
	out[1] = x0;
	out[2] = x1;
	out[3] = x2;
	out[4] = obj_qi;
	out[5] = obj_qw;
	out[6] = x2;
	out[7] = obj_qj;
	out[8] = obj_qj;
	out[9] = obj_qk;
	out[10] = obj_qw;
	out[11] = x0;
	out[12] = obj_qk;
	out[13] = x1;
	out[14] = obj_qi;
	out[15] = obj_qw;
}

/** Applying function <function imu_predict at 0x7fe08bb290e0> */
static inline void gen_imu_predict(FLT *out, const FLT *imu_rot) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT x0 = obj_qj * obj_qj;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = (obj_qw * obj_qw) + (obj_qk * obj_qk) + x1 + x0;
	const GEN_FLT x3 = 1. / x2;
	const GEN_FLT x4 = x3 * obj_qk;
	const GEN_FLT x5 = x3 * obj_qw;
	const GEN_FLT x6 = 1. / sqrt(x2);
	const GEN_FLT x7 = x6 * aa_y;
	const GEN_FLT x8 = x6 * obj_qi;
	const GEN_FLT x9 = x6 * obj_qk;
	const GEN_FLT x10 = (x8 * aa_z) + (-1 * x9 * aa_x) + (x7 * obj_qw);
	const GEN_FLT x11 = x6 * obj_qw;
	const GEN_FLT x12 = x6 * obj_qj;
	const GEN_FLT x13 = x6 * ((x12 * aa_x) + (-1 * x7 * obj_qi) + (x11 * aa_z));
	const GEN_FLT x14 = (-1 * x12 * aa_z) + (x7 * obj_qk) + (x11 * aa_x);
	out[0] = 2 * ((-1 * x5 * obj_qj) + (x4 * obj_qi));
	out[1] = 2 * ((x4 * obj_qj) + (x5 * obj_qi));
	out[2] = 1 + (2 * ((-1 * x1 * x3) + (-1 * x0 * x3)));
	out[3] = aa_x + (2 * ((-1 * x13 * obj_qj) + (x9 * x10)));
	out[4] = aa_y + (2 * ((-1 * x9 * x14) + (x13 * obj_qi)));
	out[5] = aa_z + (2 * ((-1 * x8 * x10) + (x14 * x12)));
}

// Jacobian of imu_predict wrt [obj_qw, obj_qi, obj_qj, obj_qk, aa_x, aa_y, aa_z]
static inline void gen_imu_predict_jac_imu_rot(FLT *out, const FLT *imu_rot) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT x0 = obj_qw * obj_qw;
	const GEN_FLT x1 = obj_qj * obj_qj;
	const GEN_FLT x2 = obj_qi * obj_qi;
	const GEN_FLT x3 = obj_qk * obj_qk;
	const GEN_FLT x4 = x0 + x3 + x2 + x1;
	const GEN_FLT x5 = 1. / (x4 * x4);
	const GEN_FLT x6 = 2 * x5;
	const GEN_FLT x7 = x0 * x6;
	const GEN_FLT x8 = 1. / x4;
	const GEN_FLT x9 = x8 * obj_qj;
	const GEN_FLT x10 = 2 * obj_qk;
	const GEN_FLT x11 = x5 * x10;
	const GEN_FLT x12 = x11 * obj_qw;
	const GEN_FLT x13 = -1 * x12 * obj_qi;
	const GEN_FLT x14 = 2 * obj_qw;
	const GEN_FLT x15 = x5 * x14;
	const GEN_FLT x16 = obj_qj * obj_qi;
	const GEN_FLT x17 = x15 * x16;
	const GEN_FLT x18 = x8 * obj_qk;
	const GEN_FLT x19 = x8 * obj_qw;
	const GEN_FLT x20 = -1 * x11 * x16;
	const GEN_FLT x21 = x12 * obj_qj;
	const GEN_FLT x22 = x3 * x6;
	const GEN_FLT x23 = x8 * obj_qi;
	const GEN_FLT x24 = 4 * x5;
	const GEN_FLT x25 = x1 * x24;
	const GEN_FLT x26 = x2 * x24;
	const GEN_FLT x27 = 1. / (x4 * sqrt(x4));
	const GEN_FLT x28 = x27 * aa_x;
	const GEN_FLT x29 = obj_qw * obj_qk;
	const GEN_FLT x30 = x28 * x29;
	const GEN_FLT x31 = x27 * aa_z;
	const GEN_FLT x32 = x31 * obj_qw;
	const GEN_FLT x33 = -1 * x32 * obj_qi;
	const GEN_FLT x34 = x27 * aa_y;
	const GEN_FLT x35 = 1. / sqrt(x4);
	const GEN_FLT x36 = x35 * aa_y;
	const GEN_FLT x37 = x33 + x36 + (-1 * x0 * x34) + x30;
	const GEN_FLT x38 = 2 * x35;
	const GEN_FLT x39 = x38 * obj_qk;
	const GEN_FLT x40 = x27 * x10;
	const GEN_FLT x41 = x35 * aa_z;
	const GEN_FLT x42 = x35 * aa_x;
	const GEN_FLT x43 = (-1 * x42 * obj_qk) + (x41 * obj_qi) + (x36 * obj_qw);
	const GEN_FLT x44 = x43 * obj_qw;
	const GEN_FLT x45 = x34 * obj_qw;
	const GEN_FLT x46 = x45 * obj_qi;
	const GEN_FLT x47 = x28 * obj_qj;
	const GEN_FLT x48 = -1 * x47 * obj_qw;
	const GEN_FLT x49 = x41 + (-1 * x0 * x31) + x48 + x46;
	const GEN_FLT x50 = x38 * obj_qj;
	const GEN_FLT x51 = 2 * x27;
	const GEN_FLT x52 = x51 * obj_qj;
	const GEN_FLT x53 = (-1 * x36 * obj_qi) + (x42 * obj_qj) + (x41 * obj_qw);
	const GEN_FLT x54 = x53 * obj_qw;
	const GEN_FLT x55 = x28 * obj_qi;
	const GEN_FLT x56 = x41 + (-1 * x2 * x31) + (-1 * x46) + (x55 * obj_qk);
	const GEN_FLT x57 = x40 * obj_qi;
	const GEN_FLT x58 = x57 * x43;
	const GEN_FLT x59 = x33 + (x2 * x34) + (-1 * x47 * obj_qi) + (-1 * x36);
	const GEN_FLT x60 = x51 * x16;
	const GEN_FLT x61 = x60 * x53;
	const GEN_FLT x62 = x47 * obj_qk;
	const GEN_FLT x63 = x31 * x16;
	const GEN_FLT x64 = x38 * ((-1 * x45 * obj_qj) + (-1 * x63) + x62);
	const GEN_FLT x65 = x40 * obj_qj;
	const GEN_FLT x66 = x32 * obj_qj;
	const GEN_FLT x67 = (-1 * x66) + x42 + (-1 * x1 * x28) + (x34 * x16);
	const GEN_FLT x68 = x53 * x38;
	const GEN_FLT x69 = x1 * x51;
	const GEN_FLT x70 = x31 * obj_qk;
	const GEN_FLT x71 = -1 * x34 * x29;
	const GEN_FLT x72 = x71 + (-1 * x70 * obj_qi) + (-1 * x42) + (x3 * x28);
	const GEN_FLT x73 = x43 * x38;
	const GEN_FLT x74 = x3 * x51;
	const GEN_FLT x75 = x34 * obj_qk;
	const GEN_FLT x76 = x75 * obj_qi;
	const GEN_FLT x77 = x38 * ((-1 * x31 * x29) + (-1 * x62) + x76);
	const GEN_FLT x78 = 2 * x8;
	const GEN_FLT x79 = -1 * x1 * x78;
	const GEN_FLT x80 = 1 + (-1 * x3 * x78);
	const GEN_FLT x81 = x10 * x19;
	const GEN_FLT x82 = 2 * x23;
	const GEN_FLT x83 = x82 * obj_qj;
	const GEN_FLT x84 = x23 * x10;
	const GEN_FLT x85 = x9 * x14;
	const GEN_FLT x86 = x38 * obj_qi;
	const GEN_FLT x87 = x51 * obj_qi;
	const GEN_FLT x88 = x42 + (-1 * x0 * x28) + x71 + x66;
	const GEN_FLT x89 = (-1 * x41 * obj_qj) + (x36 * obj_qk) + (x42 * obj_qw);
	const GEN_FLT x90 = x89 * obj_qw;
	const GEN_FLT x91 = x2 * x51;
	const GEN_FLT x92 = x38 * ((-1 * x55 * obj_qw) + x63 + (-1 * x76));
	const GEN_FLT x93 = x48 + (-1 * x41) + (-1 * x75 * obj_qj) + (x1 * x31);
	const GEN_FLT x94 = x89 * x65;
	const GEN_FLT x95 = x89 * x38;
	const GEN_FLT x96 = (-1 * x30) + x36 + (-1 * x3 * x34) + (x70 * obj_qj);
	const GEN_FLT x97 = -1 * x2 * x78;
	const GEN_FLT x98 = x82 * obj_qw;
	const GEN_FLT x99 = x9 * x10;
	out[0] = 2 * (x13 + (-1 * x9) + (x7 * obj_qj));
	out[1] = 2 * (x18 + (-1 * x2 * x11) + x17);
	out[2] = 2 * (x20 + (x1 * x15) + (-1 * x19));
	out[3] = 2 * (x23 + (-1 * x22 * obj_qi) + x21);
	out[4] = 0;
	out[5] = 0;
	out[6] = 0;
	out[7] = 2 * (x23 + (-1 * x7 * obj_qi) + (-1 * x21));
	out[8] = 2 * (x19 + (-1 * x2 * x15) + x20);
	out[9] = 2 * ((-1 * x17) + x18 + (-1 * x1 * x11));
	out[10] = 2 * (x13 + x9 + (-1 * x22 * obj_qj));
	out[11] = 0;
	out[12] = 0;
	out[13] = 0;
	out[14] = (x26 * obj_qw) + (x25 * obj_qw);
	out[15] = (x24 * (obj_qi * obj_qi * obj_qi)) + (-4 * x23) + (x25 * obj_qi);
	out[16] = (x26 * obj_qj) + (x24 * (obj_qj * obj_qj * obj_qj)) + (-4 * x9);
	out[17] = (x26 * obj_qk) + (x25 * obj_qk);
	out[18] = 0;
	out[19] = 0;
	out[20] = 0;
	out[21] = (x54 * x52) + (-1 * x50 * x49) + (-1 * x40 * x44) + (x37 * x39);
	out[22] = x61 + (-1 * x58) + (-1 * x50 * x59) + (x56 * x39);
	out[23] = (x69 * x53) + (-1 * x67 * x50) + (-1 * x65 * x43) + (-1 * x68) + (x64 * obj_qk);
	out[24] = (x65 * x53) + x73 + (-1 * x77 * obj_qj) + (-1 * x74 * x43) + (x72 * x39);
	out[25] = x80 + x79;
	out[26] = x83 + x81;
	out[27] = (-1 * x85) + x84;
	out[28] = (x90 * x40) + (-1 * x88 * x39) + (-1 * x87 * x54) + (x86 * x49);
	out[29] = (-1 * x92 * obj_qk) + (x89 * x57) + (-1 * x53 * x91) + x68 + (x86 * x59);
	out[30] = x94 + (-1 * x93 * x39) + (-1 * x61) + (x86 * x67);
	out[31] = (-1 * x96 * x39) + (x89 * x74) + (-1 * x53 * x57) + (-1 * x95) + (x77 * obj_qi);
	out[32] = (-1 * x81) + x83;
	out[33] = x80 + x97;
	out[34] = x99 + x98;
	out[35] = (x87 * x44) + (-1 * x86 * x37) + (-1 * x52 * x90) + (x88 * x50);
	out[36] = (-1 * x73) + (-1 * x86 * x56) + (x91 * x43) + (-1 * x89 * x60) + (x92 * obj_qj);
	out[37] = (-1 * x64 * obj_qi) + (-1 * x89 * x69) + x95 + (x60 * x43) + (x50 * x93);
	out[38] = x58 + (-1 * x86 * x72) + (-1 * x94) + (x50 * x96);
	out[39] = x84 + x85;
	out[40] = (-1 * x98) + x99;
	out[41] = 1 + x97 + x79;
}

/** Applying function <function imu_predict_gyro at 0x7fe08bb29050> */
static inline void gen_imu_predict_gyro(FLT *out, const FLT *imu_rot) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT x0 = 1. / sqrt((obj_qw * obj_qw) + (obj_qk * obj_qk) + (obj_qi * obj_qi) + (obj_qj * obj_qj));
	const GEN_FLT x1 = x0 * aa_y;
	const GEN_FLT x2 = x0 * aa_z;
	const GEN_FLT x3 = x0 * aa_x;
	const GEN_FLT x4 = x0 * ((-1 * x3 * obj_qk) + (x2 * obj_qi) + (x1 * obj_qw));
	const GEN_FLT x5 = x0 * ((-1 * x1 * obj_qi) + (x3 * obj_qj) + (x2 * obj_qw));
	const GEN_FLT x6 = x0 * ((-1 * x2 * obj_qj) + (x1 * obj_qk) + (x3 * obj_qw));
	out[0] = aa_x + (2 * ((-1 * x5 * obj_qj) + (x4 * obj_qk)));
	out[1] = aa_y + (2 * ((-1 * x6 * obj_qk) + (x5 * obj_qi)));
	out[2] = aa_z + (2 * ((-1 * x4 * obj_qi) + (x6 * obj_qj)));
}

// Jacobian of imu_predict_gyro wrt [obj_qw, obj_qi, obj_qj, obj_qk, aa_x, aa_y, aa_z]
static inline void gen_imu_predict_gyro_jac_imu_rot(FLT *out, const FLT *imu_rot) {
	const GEN_FLT obj_qw = imu_rot[0];
	const GEN_FLT obj_qi = imu_rot[1];
	const GEN_FLT obj_qj = imu_rot[2];
	const GEN_FLT obj_qk = imu_rot[3];
	const GEN_FLT aa_x = imu_rot[4];
	const GEN_FLT aa_y = imu_rot[5];
	const GEN_FLT aa_z = imu_rot[6];
	const GEN_FLT x0 = obj_qj * obj_qj;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qk * obj_qk;
	const GEN_FLT x3 = obj_qw * obj_qw;
	const GEN_FLT x4 = x3 + x2 + x1 + x0;
	const GEN_FLT x5 = 1. / (x4 * sqrt(x4));
	const GEN_FLT x6 = x5 * aa_x;
	const GEN_FLT x7 = x6 * obj_qw;
	const GEN_FLT x8 = x7 * obj_qk;
	const GEN_FLT x9 = x5 * aa_z;
	const GEN_FLT x10 = x9 * obj_qw;
	const GEN_FLT x11 = -1 * x10 * obj_qi;
	const GEN_FLT x12 = x5 * aa_y;
	const GEN_FLT x13 = 1. / sqrt(x4);
	const GEN_FLT x14 = x13 * aa_y;
	const GEN_FLT x15 = x14 + (-1 * x3 * x12) + x11 + x8;
	const GEN_FLT x16 = 2 * x13;
	const GEN_FLT x17 = x16 * obj_qk;
	const GEN_FLT x18 = x13 * aa_z;
	const GEN_FLT x19 = x13 * aa_x;
	const GEN_FLT x20 = (-1 * x19 * obj_qk) + (x18 * obj_qi) + (x14 * obj_qw);
	const GEN_FLT x21 = 2 * x5;
	const GEN_FLT x22 = x21 * obj_qw;
	const GEN_FLT x23 = x22 * x20;
	const GEN_FLT x24 = x12 * obj_qw;
	const GEN_FLT x25 = x24 * obj_qi;
	const GEN_FLT x26 = x6 * obj_qj;
	const GEN_FLT x27 = -1 * x26 * obj_qw;
	const GEN_FLT x28 = x18 + (-1 * x3 * x9) + x27 + x25;
	const GEN_FLT x29 = x16 * obj_qj;
	const GEN_FLT x30 = (-1 * x14 * obj_qi) + (x19 * obj_qj) + (x18 * obj_qw);
	const GEN_FLT x31 = x30 * x21;
	const GEN_FLT x32 = x31 * obj_qw;
	const GEN_FLT x33 = obj_qk * obj_qi;
	const GEN_FLT x34 = (-1 * x25) + x18 + (-1 * x1 * x9) + (x6 * x33);
	const GEN_FLT x35 = x20 * x21;
	const GEN_FLT x36 = x33 * x35;
	const GEN_FLT x37 = x11 + (x1 * x12) + (-1 * x26 * obj_qi) + (-1 * x14);
	const GEN_FLT x38 = obj_qj * obj_qi;
	const GEN_FLT x39 = x31 * x38;
	const GEN_FLT x40 = x26 * obj_qk;
	const GEN_FLT x41 = x9 * x38;
	const GEN_FLT x42 = x16 * ((-1 * x24 * obj_qj) + (-1 * x41) + x40);
	const GEN_FLT x43 = obj_qk * obj_qj;
	const GEN_FLT x44 = x10 * obj_qj;
	const GEN_FLT x45 = (-1 * x44) + x19 + (-1 * x0 * x6) + (x38 * x12);
	const GEN_FLT x46 = x30 * x16;
	const GEN_FLT x47 = x0 * x21;
	const GEN_FLT x48 = -1 * x24 * obj_qk;
	const GEN_FLT x49 = x48 + (-1 * x9 * x33) + (-1 * x19) + (x2 * x6);
	const GEN_FLT x50 = x20 * x16;
	const GEN_FLT x51 = x2 * x21;
	const GEN_FLT x52 = x33 * x12;
	const GEN_FLT x53 = x16 * ((-1 * x10 * obj_qk) + (-1 * x40) + x52);
	const GEN_FLT x54 = 2 * (1. / x4);
	const GEN_FLT x55 = -1 * x0 * x54;
	const GEN_FLT x56 = 1 + (-1 * x2 * x54);
	const GEN_FLT x57 = x54 * obj_qk;
	const GEN_FLT x58 = x57 * obj_qw;
	const GEN_FLT x59 = x54 * x38;
	const GEN_FLT x60 = x57 * obj_qi;
	const GEN_FLT x61 = x54 * obj_qw;
	const GEN_FLT x62 = x61 * obj_qj;
	const GEN_FLT x63 = x16 * obj_qi;
	const GEN_FLT x64 = x19 + (-1 * x3 * x6) + x48 + x44;
	const GEN_FLT x65 = (x14 * obj_qk) + (-1 * x18 * obj_qj) + (x19 * obj_qw);
	const GEN_FLT x66 = x65 * x22;
	const GEN_FLT x67 = x1 * x21;
	const GEN_FLT x68 = x16 * ((-1 * x7 * obj_qi) + x41 + (-1 * x52));
	const GEN_FLT x69 = x65 * x21;
	const GEN_FLT x70 = x27 + (-1 * x43 * x12) + (-1 * x18) + (x0 * x9);
	const GEN_FLT x71 = x69 * x43;
	const GEN_FLT x72 = x65 * x16;
	const GEN_FLT x73 = x16 * ((-1 * x8) + x14 + (-1 * x2 * x12) + (x9 * x43));
	const GEN_FLT x74 = -1 * x1 * x54;
	const GEN_FLT x75 = x61 * obj_qi;
	const GEN_FLT x76 = x57 * obj_qj;
	const GEN_FLT x77 = x38 * x21;
	out[0] = (-1 * x28 * x29) + (-1 * x23 * obj_qk) + (x32 * obj_qj) + (x15 * x17);
	out[1] = x39 + (-1 * x37 * x29) + (-1 * x36) + (x34 * x17);
	out[2] = (x47 * x30) + (-1 * x46) + (-1 * x45 * x29) + (-1 * x43 * x35) + (x42 * obj_qk);
	out[3] = (x43 * x31) + (-1 * x53 * obj_qj) + (-1 * x51 * x20) + x50 + (x49 * x17);
	out[4] = x56 + x55;
	out[5] = x59 + x58;
	out[6] = (-1 * x62) + x60;
	out[7] = (x66 * obj_qk) + (-1 * x64 * x17) + (-1 * x32 * obj_qi) + (x63 * x28);
	out[8] = (x69 * x33) + (-1 * x68 * obj_qk) + x46 + (-1 * x67 * x30) + (x63 * x37);
	out[9] = (-1 * x70 * x17) + (-1 * x39) + x71 + (x63 * x45);
	out[10] = (x65 * x51) + (-1 * x73 * obj_qk) + (-1 * x31 * x33) + (-1 * x72) + (x53 * obj_qi);
	out[11] = (-1 * x58) + x59;
	out[12] = x56 + x74;
	out[13] = x76 + x75;
	out[14] = (x23 * obj_qi) + (-1 * x63 * x15) + (-1 * x66 * obj_qj) + (x64 * x29);
	out[15] = (-1 * x50) + (-1 * x63 * x34) + (x67 * x20) + (-1 * x77 * x65) + (x68 * obj_qj);
	out[16] = (-1 * x42 * obj_qi) + (-1 * x65 * x47) + x72 + (x77 * x20) + (x70 * x29);
	out[17] = x36 + (-1 * x71) + (-1 * x63 * x49) + (x73 * obj_qj);
	out[18] = x60 + x62;
	out[19] = (-1 * x75) + x76;
	out[20] = 1 + x74 + x55;
}
