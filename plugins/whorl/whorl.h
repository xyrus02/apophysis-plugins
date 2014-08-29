/*
    Apophysis Plugin

    Copyright (C) 2007-2009 Michael Faber

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
    double whorl_inside;
    double whorl_outside;
} Variables;

#include "apoplugin.h"

// Set the name of this plugin
APO_PLUGIN("whorl");

// Define the Variables
APO_VARIABLES(
    VAR_REAL(whorl_inside, 1.0),
    VAR_REAL(whorl_outside, 1.0)
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
	double a, r;
	double sina, cosa;

	r = sqrt(FTx*FTx + FTy*FTy);
	
	if(r < VVAR)
	{
         a = atan2(FTy, FTx) + VAR(whorl_inside)/(VVAR - r);
    }
    else
    {
         a = atan2(FTy, FTx) + VAR(whorl_outside)/(VVAR - r);
    }
    fsincos(a, &sina, &cosa);
    FPx += VVAR*r*cosa;
    FPy += VVAR*r*sina;

    return TRUE;
}

