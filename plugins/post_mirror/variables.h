typedef struct
{
    int post_mirror_xaxis;
	int post_mirror_yaxis;
	int post_mirror_zaxis;

	double post_mirror_pos;
	double post_mirror_pos2;
} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("post_mirror");
APO_VARIABLES(
	VAR_INTEGER_RANGE(post_mirror_xaxis, 0, 1, 1),
	VAR_INTEGER_RANGE(post_mirror_yaxis, 0, 1, 0),
	VAR_REAL(post_mirror_pos, 0.0)
);

#define ax	   VAR(post_mirror_xaxis)
#define ay	   VAR(post_mirror_yaxis)

#define pos	   VAR(post_mirror_pos)
#define pos2   VAR(post_mirror_pos2)

#define e 1e100
#define r ( rand() & 1 )
