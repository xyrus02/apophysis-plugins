typedef struct
{
    double post_stun_power;
	double post_stun_power_abs;

	double post_stun_r_min;
	double post_stun_r_max;

	double post_stun_threshold_min;
	double post_stun_threshold_max;

	double post_stun_w1;
	double post_stun_w2;
	double post_stun_w3;

} Variables;

#define _USE_MATH_DEFINES

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("post_stun");
APO_VARIABLES(
	VAR_REAL_RANGE(post_stun_power, 0.0, 10e100, 1.0),
	VAR_REAL_RANGE(post_stun_r_min, 0.0, 10e100, 0.0),
	VAR_REAL_RANGE(post_stun_r_max, 0.0, 10e100, 1.0)
);

#define power VAR(post_stun_power_abs)

#define threshold_min VAR(post_stun_threshold_min)
#define threshold_max VAR(post_stun_threshold_max)

#define w1 VAR(post_stun_w1)
#define w2 VAR(post_stun_w2)
#define w3 VAR(post_stun_w3)
