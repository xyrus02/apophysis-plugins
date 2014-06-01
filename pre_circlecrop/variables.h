
typedef struct
{
    double pre_circlecrop_radius, pre_circlecrop_x, pre_circlecrop_y, pre_circlecrop_scatter_area;
    double pre_cA; int pre_circlecrop_zero;
} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

APO_PLUGIN("pre_circlecrop");
APO_VARIABLES(
    VAR_REAL(pre_circlecrop_radius, 1.0),
    VAR_REAL(pre_circlecrop_x, 0.0),
    VAR_REAL(pre_circlecrop_y, 0.0),
    VAR_REAL(pre_circlecrop_scatter_area, 0.0),
    VAR_INTEGER_RANGE(pre_circlecrop_zero, 0, 1, 0)
);
