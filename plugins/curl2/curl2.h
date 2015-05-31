/*
    Apophysis Plugin: curl2
	Concepted and written by Georg Kiehne / Xyrus-Worx

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

inline double cube(const double x) 
{ 
	return x*x*x; 
}

int PluginVarPrepare(Variation* vp)
{
	cc2 = 2 * c2;
	cc3 = 3 * c3;
	
    return 1;
}

int PluginVarCalc(Variation* vp)
{
	const double x = x_in, x2 = sqr(x_in), x3 = cube(x_in);
	const double y = y_in, y2 = sqr(y_in), y3 = cube(y_in);
	
	const double re = 
		  c3 * x3 - cc3 *  x * y2 
		+ c2 * x2 -  c2 * y2 
		+ c1 *  x 
		+ 1.0;
		
	const double im = 
		   c3 * x2 * y - c3 * y3 
		+ cc2 *  x * y 
		+  c1 *  y;
		  
	const double r = VVAR / (sqr(re) + sqr(im));
	
	SET(x_out, (x_in * re + y_in * im) * r);
	SET(y_out, (y_in * re - x_in * im) * r);
	
	#if defined(set_z)
		SET(z_out, (VVAR * z_in));
	#endif
	
	return 1;
}