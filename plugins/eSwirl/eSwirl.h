/*
    Apophysis Plugin

    Copyright (C) 2007-2012 Michael Faber
    Copyright (C) 2007-2012 Joel Faber

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
    return TRUE; // Always return TRUE.
}

// Taking the square root of numbers close to zero is dangerous.  If x is negative
// due to floating point errors we get NaN results.
inline double sqrt_safe(double x)
{
    if (x <= 0.0)
        return 0.0;
    return sqrt(x);
}

inline double acosh(double x)
{
	return log(x + sqrt(x*x - 1));
}

// You must call the argument "vp".
int PluginVarCalc(Variation* vp)
{
	double tmp = FTy * FTy + FTx * FTx + 1.0;
	double tmp2 = 2.0 * FTx;
	double xmax = (sqrt_safe(tmp + tmp2) + sqrt_safe(tmp - tmp2)) * 0.5;
	if(xmax < 1.0)
 		xmax = 1.0;
	double sinhmu, coshmu, sinnu, cosnu;
	
	double mu = acosh(xmax ); //  mu > 0
	double t = FTx / xmax;
	if(t > 1.0)
		t = 1.0;
	else if( t < -1.0)
		t = -1.0;

	double nu = acos(t); // -Pi < nu < Pi
	if (FTy < 0)
        nu *= -1.0;
	
	nu = nu + mu * VAR(eSwirl_out) + VAR(eSwirl_in) / mu;

	sinhcosh(mu, &sinhmu, &coshmu);
	fsincos(nu, &sinnu, &cosnu);
	FPx += VVAR * coshmu * cosnu;
	FPy += VVAR * sinhmu * sinnu;
	
    return TRUE;
}
