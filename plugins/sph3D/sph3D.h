/*
    Apophysis Plugin: x-sph3D

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

int PluginVarCalc(Variation* vp)
{
	const double epsilon = 10.000e-30;

	const double x = *vp->pFTx;
	const double y = *vp->pFTy;
	const double z = *vp->pFTz;

	const double xx = vp->var.sph3D_x * x;
	const double yy = vp->var.sph3D_y * y;
	const double zz = vp->var.sph3D_z * z;

	const double r = vp->vvar / (xx * xx + yy * yy + zz * zz + epsilon);

	*vp->pFPx += x * r;
	*vp->pFPy += y * r;
	*vp->pFPz += z * r;

    return 1;
}