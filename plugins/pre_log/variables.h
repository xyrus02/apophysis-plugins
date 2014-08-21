typedef struct
{
	double pre_log_base;
	double denom;
} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

#define LOG_BASE_DEF 2.71828182845905

APO_PLUGIN("pre_log");
APO_VARIABLES(
	VAR_REAL(pre_log_base, LOG_BASE_DEF)
);