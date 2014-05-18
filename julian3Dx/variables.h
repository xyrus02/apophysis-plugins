typedef struct
{
	int julian3Dx_power;
	double julian3Dx_dist;

	double julian3Dx_a;
	double julian3Dx_b;
	double julian3Dx_c;
	double julian3Dx_d;
	double julian3Dx_e;
	double julian3Dx_f;

	double julian3Dx_abs_power;
	double julian3Dx_coeff_power;

} Variables;

#define _USE_MATH_DEFINES
#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("julian3Dx");
APO_VARIABLES(
	VAR_INTEGER_NONZERO(julian3Dx_power, 2),
	VAR_REAL(julian3Dx_dist, 1),

	VAR_REAL(julian3Dx_a, 1),
	VAR_REAL(julian3Dx_b, 0),
	VAR_REAL(julian3Dx_c, 0),
	VAR_REAL(julian3Dx_d, 1),
	VAR_REAL(julian3Dx_e, 0),
	VAR_REAL(julian3Dx_f, 0)
);

#define power (vp->var.julian3Dx_power)
#define dist (vp->var.julian3Dx_dist)

#define c00 (vp->var.julian3Dx_a)
#define c01 (vp->var.julian3Dx_b)
#define c10 (vp->var.julian3Dx_c)
#define c11 (vp->var.julian3Dx_d)
#define c20 (vp->var.julian3Dx_e)
#define c21 (vp->var.julian3Dx_f)

#define x_in (*(vp->pFTx))
#define y_in (*(vp->pFTy))
#define z_in (*(vp->pFTz))

#define x_out (*(vp->pFPx))
#define y_out (*(vp->pFPy))
#define z_out (*(vp->pFPz))

#define absN (vp->var.julian3Dx_abs_power)
#define cN (vp->var.julian3Dx_coeff_power)

