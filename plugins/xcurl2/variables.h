typedef struct
{
    double xcurl2_c1, xcurl2_c2, xcurl2_c3;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("xcurl2");
APO_VARIABLES(
	VAR_REAL(xcurl2_c1, 0.0),
	VAR_REAL(xcurl2_c2, 0.0),
	VAR_REAL(xcurl2_c3, 0.0)
);
