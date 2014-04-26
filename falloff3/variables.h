#ifdef io_pre
	#define fo_key "pre_falloff3"

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
#else 
	#ifdef io_post
		#define fo_key "post_falloff3"

		#define fo_mul_x post_falloff3_mul_x
		#define fo_mul_y post_falloff3_mul_y
		#define fo_mul_z post_falloff3_mul_z
		#define fo_mul_c post_falloff3_mul_c

		#define fo_c_x post_falloff3_center_x
		#define fo_c_y post_falloff3_center_y
		#define fo_c_z post_falloff3_center_z

		#define fo_blur_strength post_falloff3_blur_strength
		#define fo_blur_shape post_falloff3_blur_shape
		#define fo_blur_type post_falloff3_blur_type

		#define fo_min_distance post_falloff3_min_distance
		#define fo_inv_distance post_falloff3_invert_distance

		#define fo_alpha post_falloff3_alpha
	#else
		#define fo_key "falloff3"

		#define fo_mul_x falloff3_mul_x
		#define fo_mul_y falloff3_mul_y
		#define fo_mul_z falloff3_mul_z
		#define fo_mul_c falloff3_mul_c

		#define fo_c_x falloff3_center_x
		#define fo_c_y falloff3_center_y
		#define fo_c_z falloff3_center_z

		#define fo_blur_strength falloff3_blur_strength
		#define fo_blur_shape falloff3_blur_shape
		#define fo_blur_type falloff3_blur_type

		#define fo_min_distance falloff3_min_distance
		#define fo_inv_distance falloff3_invert_distance

		#define fo_alpha falloff3_alpha
	#endif
#endif

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
	int fo_blur_type;
	int fo_blur_shape;
	double fo_blur_strength;

	double fo_min_distance;
	int fo_inv_distance;

	double fo_mul_x;
	double fo_mul_y;
	double fo_mul_z;
	double fo_mul_c;

	double fo_c_x;
	double fo_c_y;
	double fo_c_z;

	double fo_alpha;

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

APO_PLUGIN(fo_key);
APO_VARIABLES(
	VAR_INTEGER_RANGE(fo_blur_type, 0, 3, 0),
	VAR_INTEGER_RANGE(fo_blur_shape, 0, 1, 0),
	VAR_REAL_RANGE(fo_blur_strength, EPS, DBL_MAX, 1.0),

	VAR_REAL_RANGE(fo_min_distance, 0.0, DBL_MAX, 0.5),
	VAR_INTEGER_RANGE(fo_inv_distance, 0, 1, 0),
	
	VAR_REAL_RANGE(fo_mul_x, 0.0, 1.0, 1.0),
	VAR_REAL_RANGE(fo_mul_y, 0.0, 1.0, 1.0),
	VAR_REAL_RANGE(fo_mul_z, 0.0, 1.0, 0.0),
	VAR_REAL_RANGE(fo_mul_c, 0.0, 1.0, 0.0),

	VAR_REAL(fo_c_x, 0.0),
	VAR_REAL(fo_c_y, 0.0),
	VAR_REAL(fo_c_z, 0.0),

	VAR_REAL(fo_alpha, 0.0),
);
