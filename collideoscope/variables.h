typedef struct
{
    double collideoscope_a;
    int collideoscope_num;
    double ka;
    double kn_pi;
    double ka_kn;
    double pi_kn;
} Variables;


#define _USE_MATH_DEFINES
#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("collideoscope");

// Define the Variables
APO_VARIABLES(
    VAR_REAL_CYCLE(collideoscope_a, 0.0, 1.0, 0.0),
    VAR_INTEGER_RANGE(collideoscope_num, 1, INT_MAX, 1)
);