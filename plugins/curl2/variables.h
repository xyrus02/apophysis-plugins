typedef struct
{
    double curl2_c1, curl2_c2, curl2_c3;
	double c3x3, c2x2;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

#define set_z

#define x_in FTx
#define y_in FTy
#define z_in FTz

#define x_out FPx
#define y_out FPy
#define z_out FPz

#define SET(a,b) a += b

#define c1 VAR(curl2_c1)
#define c2 VAR(curl2_c2)
#define c3 VAR(curl2_c3)

#define cc2 VAR(c2x2)
#define cc3 VAR(c3x3)

APO_PLUGIN("curl2");
APO_VARIABLES(
	VAR_REAL(curl2_c1, 0.0),
	VAR_REAL(curl2_c2, 0.0),
	VAR_REAL(curl2_c3, 0.0)
);
