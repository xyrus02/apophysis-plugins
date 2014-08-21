#define APO_NOVARIABLES
#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	typedef struct
	{
	} Variables;
	#include "apoplugin.h"
#endif

APO_PLUGIN("petal");