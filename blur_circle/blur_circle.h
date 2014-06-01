/*
    Apophysis Plugin: blur_circle

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

// You must call the argument "vp".
int PluginVarPrepare(Variation* vp)
{
	VAR(VVAR4_PI) = VVAR * 4.0 / M_PI;
    // Always return TRUE.
    return TRUE;
}

// You must call the argument "vp".
int PluginVarCalc(Variation* vp)
{
    double x = 2.0 * random01() - 1.0;
    double y = 2.0 * random01() - 1.0;
	double ps;
	double s;
	double absx = fabs(x);
	double absy = fabs(y);
	double r;
	double sina, cosa;
	double a = atan2(y, x);

	if (absx > absy)
		s = absx;
	else
		s = absy;

	if (a < -M_PI3_4)
		ps = absy;
	else if (a < -M_PI_4)
		ps = 2.0 * s + x;
	else if (a < M_PI_4)
		ps = 4.0 * s + y;
	else if (a < M_PI3_4)
		ps = 6.0 * s - x;
	else
		ps = 8.0 * s - y;

	r = VAR(VVAR4_PI) * s + VAR(blur_circle_hole);
	fsincos( M_PI_4 * ps / s - M_PI, &sina, &cosa);

	FPx += r * cosa;
	FPy += r * sina;

	return TRUE;

}