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
    double murl2_c;
    int murl2_power;

    double p2, invp, invp2, vp;
} Variables;

#include "apoplugin.h"

// Set the name of this plugin
APO_PLUGIN("murl2");


// Define the Variables
APO_VARIABLES(
    VAR_REAL_RANGE(murl2_c, -1.0, 1.0, 0.0),
    VAR_INTEGER_NONZERO(murl2_power, 1),
);

// You must call the argument "vp".
int PluginVarPrepare(Variation* vp)
{
    VAR(p2) = VAR(murl2_power) / 2.0;
    VAR(invp) = 1.0 / VAR(murl2_power); // (2/p)/2
    VAR(invp2) = 2.0 / VAR(murl2_power);

    if (VAR(murl2_c) == -1) VAR(vp) = 0; else
    VAR(vp) = VVAR * pow(VAR(murl2_c) + 1, 2.0 / VAR(murl2_power));

    // Always return TRUE.
    return TRUE;
}

// You must call the argument "vp".
int PluginVarCalc(Variation* vp)
{
    double sina, cosa;
    fsincos(atan2(FTy, FTx) * VAR(murl2_power), &sina, &cosa);
    double r = VAR(murl2_c) * pow(sqr(FTx) + sqr(FTy), VAR(p2));

    double re = r*cosa + 1;
    double im = r*sina;

    r = pow(sqr(re) + sqr(im), VAR(invp));
    fsincos(atan2(im, re) * VAR(invp2), &sina, &cosa);
    re = r * cosa;
    im = r * sina;

    double r1 = VAR(vp) / sqr(r); //(sqr(re) + sqr(im));

    FPx += r1 * (FTx*re + FTy*im);
    FPy += r1 * (FTy*re - FTx*im);

    return TRUE;
}
