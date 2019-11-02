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
    double post_murl_c;
    int post_murl_power;

    double c, p2, vp;
} Variables;

#include "apoplugin.h"

// Set the name of this plugin
APO_PLUGIN("post_murl");


// Define the Variables
APO_VARIABLES(
    VAR_REAL(post_murl_c, 0.0),
    VAR_INTEGER_RANGE(post_murl_power, 2, 0x7fffffff, 2),
);

// You must call the argument "vp".
int PluginVarPrepare(Variation* vp)
{
    if (VAR(post_murl_power) != 1)
        VAR(c) = VAR(post_murl_c) / (VAR(post_murl_power) - 1);
    else
        VAR(c) = VAR(post_murl_c);

    VAR(p2) = VAR(post_murl_power) / 2.0;
    VAR(vp) = VVAR * (VAR(c) + 1);

    // Always return TRUE.
    return TRUE;
}

// You must call the argument "vp".
int PluginVarCalc(Variation* vp)
{
    double sina, cosa;
    fsincos(atan2(FPy, FPx) * VAR(post_murl_power), &sina, &cosa);
    double r = VAR(c) * pow(sqr(FPx) + sqr(FPy), VAR(p2));

    double re = r * cosa + 1;
    double im = r * sina;

    double r1 = VAR(vp) / (sqr(re) + sqr(im));

    double fpx = FPx;
    FPx = r1 * (fpx*re + FPy*im);
    FPy = r1 * (FPy*re - fpx*im);

    return TRUE;
}
