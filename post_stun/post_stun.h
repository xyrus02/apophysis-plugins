/*
    Apophysis Plugin: post_stun

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#define mind(a,b) ((a<b)?a:b)
#define maxd(a,b) ((a>b)?a:b)

int PluginVarPrepare(Variation* vp)
{
	power = fabs(vp->var.post_stun_power);

	threshold_min = mind(vp->var.post_stun_r_min, vp->var.post_stun_r_max);
	threshold_max = maxd(vp->var.post_stun_r_min, vp->var.post_stun_r_max);
	
	w3 = 3 * vp->vvar;
	w1 = w3 / M_PI;
	w2 = 0.5 * w1;

    return 1;
}

int PluginVarCalc(Variation* vp)
{
	double x = *(vp->pFPx);
	double y = *(vp->pFPy);
	double z = *(vp->pFPz);

	const double radius_square = x * x + y * y;
	if (radius_square > threshold_min)
	{
		const double radius = sqrt(radius_square);
		const double rand = random01();

		double radius_offset = radius + fabs(power * radius * rand);
		double radius_offset_square = radius_offset * radius_offset;
		double radius_mul = (radius_offset_square > threshold_max) ? 
			radius_offset_square : 
			radius_square;

		double multiplicator = (1.0 / radius_mul - 1.0);
		
		x *= multiplicator;
		y *= multiplicator;
	}

	*vp->pFPx = w1 * atan2(x, y);
	*vp->pFPy = w2 * log(x * x + y * y);
	*vp->pFPz = w3 * z;
/*
	FPx = vp->vvar * x;
	FPy = vp->vvar * y;
	FPz = vp->vvar * z;
*/

    return 1;
}