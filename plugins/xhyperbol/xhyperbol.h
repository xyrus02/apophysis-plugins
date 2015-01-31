/*
    Apophysis Plugin: xhyperbol

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

#define epsilon 10e-300

int PluginVarPrepare(Variation* vp)
{
    return 1;
}

inline double flip(const double amount, const double x, const double y) 
{
	return amount / (sqr(x) + sqr(y) + epsilon);
}

int PluginVarCalc(Variation* vp)
{
	const double r = flip(1, FTx, FTy);
	
	const double x = FTx * r;
	const double y = FTy * r;

	const double real = m00 * x + m01 * y + m20;
	const double imag = m10 * x + m11 * y + m21;
    const double alpha = atan2(imag, real) + M_2PI;

	double s = 0.0, c = 0.0;
	fsincos(alpha, &s, &c);

	const double rsq = sqr(real) + sqr(imag);

	const double xout = rsq * c;
	const double yout = rsq * s;

	const double rinv = flip(VVAR, xout, yout);

    FPx = xout * rinv;
    FPy = yout * rinv;

    return 1;
}
