typedef struct
{
	double blur_circle_hole;
	double VVAR4_PI;

} Variables;

#define _USE_MATH_DEFINES
const double M_PI3_4 = 2.35619449;
const double M_PI_4  = 0.785398163;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

// Set the name of this plugin
APO_PLUGIN("blur_circle");

// Define the Variables
APO_VARIABLES(
	VAR_REAL(blur_circle_hole, 0.0)
);