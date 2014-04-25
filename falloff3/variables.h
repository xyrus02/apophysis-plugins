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
	double falloff3_scatter;
	double falloff3_mindist;

	double falloff3_mul_x;
	double falloff3_mul_y;
	double falloff3_mul_z;
	double falloff3_mul_c;

	double falloff3_x0;
	double falloff3_y0;
	double falloff3_z0;

	int falloff3_invert;
	int falloff3_type;

	double4 mul;
	double3 center;
	double d, r_max;
	int invert, type;
} Variables;

#define _USE_MATH_DEFINES
#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("falloff3");
APO_VARIABLES(
	VAR_REAL_RANGE(falloff3_scatter, EPS, DBL_MAX, 1.0),
	VAR_REAL_RANGE(falloff3_mindist, 0.0, DBL_MAX, 0.5),
	
	VAR_REAL_RANGE(falloff3_mul_x, 0.0, 1.0, 1.0),
	VAR_REAL_RANGE(falloff3_mul_y, 0.0, 1.0, 1.0),
	VAR_REAL_RANGE(falloff3_mul_z, 0.0, 1.0, 0.0),
	VAR_REAL_RANGE(falloff3_mul_c, 0.0, 1.0, 0.0),

	VAR_REAL(falloff3_x0, 0.0),
	VAR_REAL(falloff3_y0, 0.0),
	VAR_REAL(falloff3_z0, 0.0),

	VAR_INTEGER_RANGE(falloff3_invert, 0, 1, 0),
	VAR_INTEGER_RANGE(falloff3_type, 0, 2, 0),
);
