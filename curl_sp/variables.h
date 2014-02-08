typedef struct
{
	double curl_sp_pow;
	double curl_sp_c1;
	double curl_sp_c2;
	double curl_sp_sx;
	double curl_sp_sy;
	double curl_sp_dc;
	double c2_x2, dc_adjust;
	double power_inv;
} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("curl_sp");
APO_VARIABLES(
	VAR_REAL(curl_sp_pow, 1.0),
	VAR_REAL(curl_sp_c1, 0.0),
	VAR_REAL(curl_sp_c2, 0.0),
	VAR_REAL(curl_sp_sx, 0.0),
	VAR_REAL(curl_sp_sy, 0.0),
	VAR_REAL(curl_sp_dc, 0.0)
);
