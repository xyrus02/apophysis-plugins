typedef struct
{
	double sph3D_x;
	double sph3D_y;
    double sph3D_z;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("sph3D");
APO_VARIABLES(
	VAR_REAL(sph3D_x, 1.0),
	VAR_REAL(sph3D_y, 1.0),
	VAR_REAL(sph3D_z, 1.0),
);
