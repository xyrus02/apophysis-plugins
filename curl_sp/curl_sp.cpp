/*
    Apophysis Plugin: curl_sp

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

#include "curl_sp.h"

int PluginVarPrepare(Variation* vp)
{
	c2_x2     = 2.0 * c2;
	dc_adjust = 0.1 * dc;
	power_inv = 1.0 / zeps(power);

	if (power == 0) 
	{
		power = EPS;
	}

    return 1;
}

int PluginVarCalc(Variation* vp)
{
	const double x = powq4c(tx, power);
	const double y = powq4c(ty, power);
	const double z = powq4c(tz, power);

	const double d = sqr(x) - sqr(y);

	const double re = spread(c1 * x + c2    * d,     sx) + 1.0;
	const double im = spread(c1 * y + c2_x2 * x * y, sy);

	const double c = powq4c(sqr(re) + sqr(im), power_inv);
	const double r = vp->vvar / c;

	px += (x * re + y * im) * r;
	py += (y * re - x * im) * r;
	pz += (z * vv         ) / c;

	color = range(0, color + dc_adjust * c, 1);

    return 1;
}