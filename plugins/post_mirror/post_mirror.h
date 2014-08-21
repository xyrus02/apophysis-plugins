/*
    Apophysis Plugin: post_mirror

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
	pos2 = 2 * pos;
	return 1;
}

inline void crop   (double* p, double t) { *p = *p <= t ? *p : e; }
inline void mirror (double* p, const double t, const double tt) { *p = r ? tt - *p : *p; }

int PluginVarCalc(Variation* vp)
{
	if (ax && !ay) 
	{  
		crop(vp->pFPx, pos);
		mirror(vp->pFPx, pos, pos2); 
	}
	else if (!ax && ay) 
	{ 
		crop(vp->pFPy, pos); 
		mirror(vp->pFPy, pos, pos2); 
	}
	else if (ax && ay)
	{
		if (*vp->pFPx > pos || *vp->pFPy > pos)
		{
			*vp->pFPx = e;
			*vp->pFPy = e;
		}

		mirror(vp->pFPx, pos, pos2); 
		mirror(vp->pFPy, pos, pos2); 
	}

    return 1;
}