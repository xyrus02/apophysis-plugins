/*
    Apophysis Plugin

    Copyright (C) 2007-2012 Joel Faber
    Copyright (C) 2007-2012 Michael Faber

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

// Must define this structure before we include apoplugin.h
typedef struct
{
	double circlize2_hole;

} Variables;

#include "apoplugin.h"

// Set the name of this plugin
APO_PLUGIN("circlize2");

// Define the Variables
APO_VARIABLES(
	VAR_REAL(circlize2_hole, 0.0)
);

// You must call the argument "vp".
int PluginVarPrepare(Variation* vp)
{
    // Always return TRUE.
    return TRUE;
}

// You must call the argument "vp".
int PluginVarCalc(Variation* vp)
{
    double absx = fabs(FTx);
    double absy = fabs(FTy);
    double side;
    double perimeter;
    double r, sina, cosa;

    if (absx >= absy)
    {
        if (FTx >= absy)
        {
            perimeter = absx + FTy;
        }
        else
        {
            perimeter = 5.0 * absx - FTy;
        }

        side = absx;
    }
    else
    {
        if (FTy >= absx)
        {
            perimeter = 3.0 * absy - FTx;
        }
        else
        {
            perimeter = 7.0 * absy + FTx;
        }

        side = absy;
    }

    r = VVAR * (side + VAR(circlize2_hole));
    fsincos(M_PI_4 * perimeter / side - M_PI_4, &sina, &cosa);

    FPx += r * cosa;
	FPy += r * sina;

	return TRUE;
}
