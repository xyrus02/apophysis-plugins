/*
    Apophysis Plugin: juni

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
	absn = (int)fabs((double)power);
	cn = (stretch / (double)power - 1) / 2.0;

    return 1;
}

int PluginVarCalc(Variation* vp)
{
	const double x_in = *vp->pFTx;
	const double y_in = *vp->pFTy;
	const double z_in = *vp->pFTz;

	const double zz = z_in / (double)absn;

	const double r2 = x_in * x_in + y_in * y_in;
	const double r  = vvar * pow(r2 + zz * zz, cn);

	*vp->pFPz += r * zz;

	if (
		((r2 > (vvar * vvar) || r2 == 0) && !inv) || 
		((r2 < (vvar * vvar) && r2 != 0) &&  inv)
	) {
		*vp->pFPx += vvar * *vp->pFTx;
		*vp->pFPy += vvar * *vp->pFTy;

		return 1;
	}

	const double xx = vp->a * x_in + vp->b * y_in + vp->e;
	const double yy = vp->c * x_in + vp->d * y_in + vp->f;

	const double theta = (int)(random01() * (double)absn);

	const double alpha = (atan2(yy, xx) + M_2PI * theta) / (double)power;
	const double gamma = r * sqrt(r2);

	double sina, cosa; fsincos(alpha, &sina, &cosa);

	*vp->pFPx += gamma * cosa;
	*vp->pFPy += gamma * sina;

    return 1;
}