typedef struct
{
    double curl2_c1, curl2_c2, curl2_c3;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("curl2");
APO_VARIABLES(
	VAR_REAL(curl2_c1, 0.0),
	VAR_REAL(curl2_c2, 0.0),
	VAR_REAL(curl2_c3, 0.0)
);
