typedef struct
{
    double xhyperbol_m00, xhyperbol_m01;
	double xhyperbol_m10, xhyperbol_m11;
	double xhyperbol_m20, xhyperbol_m21;
} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("xhyperbol");
APO_VARIABLES(
	VAR_REAL(xhyperbol_m00, /* default: */ 1.0),
	VAR_REAL(xhyperbol_m01, /* default: */ 0.0),
	VAR_REAL(xhyperbol_m10, /* default: */ 0.0),
	VAR_REAL(xhyperbol_m11, /* default: */ 1.0),
	VAR_REAL(xhyperbol_m20, /* default: */ 0.0),
	VAR_REAL(xhyperbol_m21, /* default: */ 0.0)
);

#define m00 vp->var.xhyperbol_m00
#define m01 vp->var.xhyperbol_m01
#define m10 vp->var.xhyperbol_m10
#define m11 vp->var.xhyperbol_m11
#define m20 vp->var.xhyperbol_m20
#define m21 vp->var.xhyperbol_m21
