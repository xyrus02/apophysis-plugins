typedef struct
{
    double <%NAME%>_real;
	double <%NAME%>_real_range;
	double <%NAME%>_real_cycle;

	int <%NAME%>_integer;
	int <%NAME%>_integer_range;
	int <%NAME%>_integer_nonzero;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("<%NAME%>");
APO_VARIABLES(
	VAR_REAL(<%NAME%>_real, /* default: */ 0.0),
	VAR_REAL_RANGE(<%NAME%>_real_range, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	VAR_REAL_CYCLE(<%NAME%>_real_cycle, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	
	VAR_INTEGER(<%NAME%>_integer, /* default: */ 0),
	VAR_INTEGER_RANGE(<%NAME%>_integer_range, /* min: */ -1, /* max: */ 1, /* default: */ 0),
	VAR_INTEGER_NONZERO(<%NAME%>_integer_nonzero, /* default: */ 1),
);
