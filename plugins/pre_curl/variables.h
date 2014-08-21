typedef struct
{
    double pre_curl_c1;
	double pre_curl_c2;
	double c1, c2, c2x2;
} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("pre_curl");
APO_VARIABLES(
	VAR_REAL(pre_curl_c1, 0.0),
	VAR_REAL(pre_curl_c2, 0.0)
);
