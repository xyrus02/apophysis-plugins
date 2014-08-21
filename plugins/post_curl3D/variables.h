typedef struct
{
    double post_curl3D_cx;
	double post_curl3D_cy;
	double post_curl3D_cz;

	double _cx, _cy, _cz,
		   cx2, cy2, cz2,
		   c2x, c2y, c2z,
		   c_2;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("post_curl3D");
APO_VARIABLES(
	VAR_REAL(post_curl3D_cx, 0.0),
	VAR_REAL(post_curl3D_cy, 0.0),
	VAR_REAL(post_curl3D_cz, 0.0)
);
