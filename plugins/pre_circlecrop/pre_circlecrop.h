/*
    Apophysis Plugin: pre_circlecrop

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
    vp->var.pre_cA = max(-1.0, min(vp->var.pre_circlecrop_scatter_area, 1.0));
    return 1;
}
int PluginVarCalc(Variation* vp)
{
    const double x0 = vp->var.pre_circlecrop_x;
    const double y0 = vp->var.pre_circlecrop_y;
    const double cr = vp->var.pre_circlecrop_radius;
    const double ca = vp->var.pre_cA;
    const double vv = vp->vvar;

    double xi = *vp->pFTx; xi -= x0;
    double yi = *vp->pFTy; yi -= y0;

    double* xo = vp->pFTx;
    double* yo = vp->pFTy;

    const double rad = sqrt(xi * xi + yi * yi);
    const double ang = atan2(yi, xi);
    const double rdc = cr + (random01() * 0.5 * ca);

    const int esc = rad > cr;
    const int cr0 = vp->var.pre_circlecrop_zero;

    double s, c; fsincos(ang, &s, &c);

    if ( cr0 &&  esc) { *xo = *yo = 0; return 1; }
    if ( cr0 && !esc) { *xo = vv * xi + x0; *yo = vv * yi + y0; return 1; }
    if (!cr0 &&  esc) { *xo = vv * rdc * c + x0; *yo = vv * rdc * s + y0; return 1; }
    if (!cr0 && !esc) { *xo = vv * xi + x0; *yo = vv * yi + y0; return 1; }

    return 0; // error
}
