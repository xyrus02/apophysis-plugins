#define io_pre

typedef struct {
	double x;
	double y;
	double z;
} double3;
typedef struct {
	double x;
	double y;
	double z;
	double c;
} double4;

#define fo_mul_x pre_falloff3_mul_x
#define fo_mul_y pre_falloff3_mul_y
#define fo_mul_z pre_falloff3_mul_z
#define fo_mul_c pre_falloff3_mul_c

#define fo_c_x pre_falloff3_center_x
#define fo_c_y pre_falloff3_center_y
#define fo_c_z pre_falloff3_center_z

#define fo_blur_strength pre_falloff3_blur_strength
#define fo_blur_shape pre_falloff3_blur_shape
#define fo_blur_type pre_falloff3_blur_type

#define fo_min_distance pre_falloff3_min_distance
#define fo_inv_distance pre_falloff3_invert_distance

#define fo_alpha pre_falloff3_alpha

typedef struct {
	int pre_falloff3_blur_type;
	int pre_falloff3_blur_shape;
	double pre_falloff3_blur_strength;

	double pre_falloff3_min_distance;
	int pre_falloff3_invert_distance;

	double pre_falloff3_mul_x;
	double pre_falloff3_mul_y;
	double pre_falloff3_mul_z;
	double pre_falloff3_mul_c;

	double pre_falloff3_center_x;
	double pre_falloff3_center_y;
	double pre_falloff3_center_z;

	double pre_falloff3_alpha;

	double4 mul;
	double3 center;

	double d, r_max, alpha;
	int invert, type, shape;
} Variables;

#define _USE_MATH_DEFINES
#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

#define bt_gaussian 0
#define bt_radial   1
#define bt_log		2

#define bs_circle	0
#define bs_square   1

APO_PLUGIN("pre_falloff3");
APO_VARIABLES(
	VAR_INTEGER_RANGE(pre_falloff3_blur_type, 0, 3, 0),
	VAR_INTEGER_RANGE(pre_falloff3_blur_shape, 0, 1, 0),
	VAR_REAL_RANGE(pre_falloff3_blur_strength, EPS, DBL_MAX, 1.0),

	VAR_REAL_RANGE(pre_falloff3_min_distance, 0.0, DBL_MAX, 0.5),
	VAR_INTEGER_RANGE(pre_falloff3_invert_distance, 0, 1, 0),
	
	VAR_REAL_RANGE(pre_falloff3_mul_x, 0.0, 1.0, 1.0),
	VAR_REAL_RANGE(pre_falloff3_mul_y, 0.0, 1.0, 1.0),
	VAR_REAL_RANGE(pre_falloff3_mul_z, 0.0, 1.0, 0.0),
	VAR_REAL_RANGE(pre_falloff3_mul_c, 0.0, 1.0, 0.0),

	VAR_REAL(pre_falloff3_center_x, 0.0),
	VAR_REAL(pre_falloff3_center_y, 0.0),
	VAR_REAL(pre_falloff3_center_z, 0.0),

	VAR_REAL(pre_falloff3_alpha, 0.0),
);
