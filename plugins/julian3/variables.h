typedef struct
{
    int julian3_power;
	double julian3_dist;

	double julian3_real;
	double julian3_imag;

	int j3_absn;
	double j3_cn;
	double j3_vvar2;

} Variables;

#define _USE_MATH_DEFINEs
#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("julian3");
APO_VARIABLES(
	VAR_INTEGER_NONZERO(julian3_power, 2),
	VAR_REAL(julian3_dist, 1.0),

	VAR_REAL(julian3_real, 0.0),
	VAR_REAL(julian3_imag, 0.0),
);

#define power vp->var.julian3_power
#define dist  vp->var.julian3_dist

#define absn  vp->var.j3_absn
#define cn    vp->var.j3_cn
#define vvar  vp->vvar
#define vvar2 vp->var.j3_vvar2

#define rea   1
#define ima   0
#define reb   0
#define imb   0
#define rec   vp->var.julian3_real
#define imc   vp->var.julian3_imag
#define red   1
#define imd   0
