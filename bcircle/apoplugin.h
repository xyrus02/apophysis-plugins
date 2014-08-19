#define _USE_MATH_DEFINES
#ifdef _APOMSVC
	#ifdef APO_NOVARIABLES
		#include "apoplugin_msvc_novar.h"
	#else
		#include "apoplugin_msvc_var.h"
	#endif
#else
	#include "apoplugin_classic.h"
#endif
