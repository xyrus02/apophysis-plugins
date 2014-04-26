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

typedef struct {
	int falloff3_blur_type;
	int falloff3_blur_shape;
	double falloff3_blur_strength;

	double falloff3_min_distance;
	int falloff3_invert_distance;

	double falloff3_mul_x;
	double falloff3_mul_y;
	double falloff3_mul_z;
	double falloff3_mul_c;

	double falloff3_center_x;
	double falloff3_center_y;
	double falloff3_center_z;

	double falloff3_alpha;

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

APO_PLUGIN("falloff3");
APO_VARIABLES(
	VAR_INTEGER_RANGE(falloff3_blur_type, 0, 3, 0),
	VAR_INTEGER_RANGE(falloff3_blur_shape, 0, 1, 0),
	VAR_REAL_RANGE(falloff3_blur_strength, EPS, DBL_MAX, 1.0),

	VAR_REAL_RANGE(falloff3_min_distance, 0.0, DBL_MAX, 0.5),
	VAR_INTEGER_RANGE(falloff3_invert_distance, 0, 1, 0),
	
	VAR_REAL_RANGE(falloff3_mul_x, 0.0, 1.0, 1.0),
	VAR_REAL_RANGE(falloff3_mul_y, 0.0, 1.0, 1.0),
	VAR_REAL_RANGE(falloff3_mul_z, 0.0, 1.0, 0.0),
	VAR_REAL_RANGE(falloff3_mul_c, 0.0, 1.0, 0.0),

	VAR_REAL(falloff3_center_x, 0.0),
	VAR_REAL(falloff3_center_y, 0.0),
	VAR_REAL(falloff3_center_z, 0.0),

	VAR_REAL(falloff3_alpha, 0.0),
);
