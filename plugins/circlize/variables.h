typedef struct
{
	double circlize_hole;
	double VVAR4_PI;

} Variables;

#define _USE_MATH_DEFINES
#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

// Set the name of this plugin
APO_PLUGIN("circlize");

// Define the Variables
APO_VARIABLES(
	VAR_REAL(circlize_hole, 0.0)
);
