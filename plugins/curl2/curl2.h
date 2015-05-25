/*
    Apophysis Plugin: curl2

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

int PluginVarPrepare(Variation* vp)
{
    return 1;
}

inline double cub(const double x) { return x * x * x; }

int PluginVarCalc(Variation* vp)
{
	// z³ = x³ + 3x²iy + -3x - i

	const double re = 1 + 
		VAR(curl2_c1) * (FTx) + 
		VAR(curl2_c2) * (sqr(FTx) - sqr(FTy)) +
		VAR(curl2_c3) * (cub(FTx) - 3 * FTx);
		
	const double im = 
		VAR(curl2_c1) * (FTy) +
		VAR(curl2_c2) * (2 * FTx * FTy) +
		VAR(curl2_c3) * (3 * FTx * FTy - 1);
		
	const double r = VVAR / (sqr(re) + sqr(im));
	
	FPx += (FTx * re + FTy * im) * r;
	FPy += (FTy * re + FTx * im) * r;
	FPz += VVAR * FTz;

    return 1;
}