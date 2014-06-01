typedef struct
{
	double eSwirl_in;
	double eSwirl_out;
} Variables;

#define _USE_MATH_DEFINES
#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif
#include <cmath>

// Set the name of this plugin
APO_PLUGIN("eSwirl");

// Define the Variables
APO_VARIABLES(
	VAR_REAL(eSwirl_in, 0.0),
	VAR_REAL(eSwirl_out, 0.0)
);