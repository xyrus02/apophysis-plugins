
typedef struct
{
    double post_circlecrop_radius, post_circlecrop_x, post_circlecrop_y, post_circlecrop_scatter_area;
    double post_cA; int post_circlecrop_zero;
} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

APO_PLUGIN("post_circlecrop");
APO_VARIABLES(
    VAR_REAL(post_circlecrop_radius, 1.0),
    VAR_REAL(post_circlecrop_x, 0.0),
    VAR_REAL(post_circlecrop_y, 0.0),
    VAR_REAL(post_circlecrop_scatter_area, 0.0),
    VAR_INTEGER_RANGE(post_circlecrop_zero, 0, 1, 0)
);
