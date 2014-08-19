/*
    Apophysis Plugin: julian3

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
	cn = (dist / (double)power - 1) / 2.0;

    return 1;
}

inline void mobius_transform(Variation* vp, const double x, const double y, double* pX, double* pY)
{
	const double u_real = rea * x - ima * y + reb;
	const double u_imag = rea * y + ima * x + imb;

	const double v_real = rec * x - imc * y + red;
	const double v_imag = rec * y + imc * x + imd;

	const double denominator = 1 / (v_real * v_real + v_imag * v_imag);

	*pX = (u_real * v_real + u_imag * v_imag) * denominator;
	*pY = (u_imag * v_real - u_real * v_imag) * denominator;
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

	double mobx, moby; mobius_transform(vp, x_in, y_in, &mobx, &moby);

	const double xx = vp->a * mobx + vp->b * moby + vp->e;
	const double yy = vp->c * mobx + vp->d * moby + vp->f;

	const double theta = (int)(random01() * (double)absn);

	const double alpha = (atan2(yy, xx) + M_2PI * theta) / (double)power;
	const double gamma = r * sqrt(r2);

	double sina, cosa; fsincos(alpha, &sina, &cosa);

	*vp->pFPx += gamma * cosa;
	*vp->pFPy += gamma * sina;

    return 1;
}