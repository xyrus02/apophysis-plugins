/*
    Apophysis Plugin: pre_curl

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
	vp->var.c1 = vp->var.pre_curl_c1;
	vp->var.c2 = vp->var.pre_curl_c2;
	vp->var.c2x2 = 2 * vp->var.c2;
    return 1;
}

int PluginVarCalc(Variation* vp)
{
	const double x = *(vp->pFTx);
	const double y = *(vp->pFTy);
	
	const double re = 1 + vp->var.c1 * x + vp->var.c2 * (x * x - y * y);
	const double im =     vp->var.c1 * y + vp->var.c2x2 * x * y;
	
	const double r = vp->vvar / (re * re + im * im);
	
	*(vp->pFTx) = (x * re + y * im) * r;
	*(vp->pFTy) = (y * re - x * im) * r;
	
    return 1;
}