typedef struct
{
    double falloff3_real;
	double falloff3_real_range;
	double falloff3_real_cycle;

	int falloff3_integer;
	int falloff3_integer_range;
	int falloff3_integer_nonzero;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("falloff3");
APO_VARIABLES(
	VAR_REAL(falloff3_real, /* default: */ 0.0),
	VAR_REAL_RANGE(falloff3_real_range, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	VAR_REAL_CYCLE(falloff3_real_cycle, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	
	VAR_INTEGER(falloff3_integer, /* default: */ 0),
	VAR_INTEGER_RANGE(falloff3_integer_range, /* min: */ -1, /* max: */ 1, /* default: */ 0),
	VAR_INTEGER_NONZERO(falloff3_integer_nonzero, /* default: */ 1),
);
