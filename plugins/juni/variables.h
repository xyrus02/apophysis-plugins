typedef struct
{
    int juni_power;
	double juni_stretch;
	int juni_invert;

	int j3_absn;
	double j3_cn;

} Variables;

#define _USE_MATH_DEFINEs
#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("juni");
APO_VARIABLES(
	VAR_INTEGER_NONZERO(juni_power, 2),
	VAR_INTEGER_RANGE(juni_invert, 0, 1, 0),
	VAR_REAL(juni_stretch, 1.0),
);

#define power   vp->var.juni_power
#define stretch vp->var.juni_stretch
#define inv     vp->var.juni_invert
#define absn    vp->var.j3_absn
#define cn      vp->var.j3_cn
#define vvar    vp->vvar
