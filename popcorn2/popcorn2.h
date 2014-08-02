/*
    Apophysis Plugin

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
    double popcorn2_x;
    double popcorn2_y;
    double popcorn2_c;
} Variables;

#include "apoplugin.h"

// Set the name of this plugin
APO_PLUGIN("popcorn2");

// Define the Variables
APO_VARIABLES(
    VAR_REAL(popcorn2_x, 0.1),
    VAR_REAL(popcorn2_y, 0.1),
    VAR_REAL(popcorn2_c, 3.0)
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
    FPx += VVAR * (FTx + VAR(popcorn2_x) * sin(tan(VAR(popcorn2_c)*FTy)));
    FPy += VVAR * (FTy + VAR(popcorn2_y) * sin(tan(VAR(popcorn2_c)*FTx)));

    return TRUE;
}
