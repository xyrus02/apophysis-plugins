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
    
    Based on the "bwraps7" plugin for Apophysis written by slobo777
    --> http://slobo777.deviantart.com/art/Bubble-Wrap-WIP-Plugin-112370125
    
    Pre- and post-variants implemented by Georg Kiehne
    --> http://xyrus02.deviantart.com/
    
    If you find any bugs / nags - keep them :)
*/

//#define pre_bwraps
//#define post_bwraps

#ifdef pre_bwraps
  #define N_PLUGIN     "pre_bwraps"
  #define N_CELLSIZE    pre_bwraps_cellsize
  #define N_SPACE       pre_bwraps_space
  #define N_GAIN        pre_bwraps_gain
  #define N_INNERTWIST  pre_bwraps_inner_twist
  #define N_OUTERTWIST  pre_bwraps_outer_twist
  #define N_G2          pre_bwraps_g2
  #define N_R2          pre_bwraps_r2
  #define N_RFACTOR     pre_bwraps_rfactor
#else
#ifdef post_bwraps
  #define N_PLUGIN     "post_bwraps"
  #define N_CELLSIZE    post_bwraps_cellsize
  #define N_SPACE       post_bwraps_space
  #define N_GAIN        post_bwraps_gain
  #define N_INNERTWIST  post_bwraps_inner_twist
  #define N_OUTERTWIST  post_bwraps_outer_twist
  #define N_G2          post_bwraps_g2
  #define N_R2          post_bwraps_r2
  #define N_RFACTOR     post_bwraps_rfactor
#else
  #define N_PLUGIN     "bwraps"
  #define N_CELLSIZE    bwraps_cellsize
  #define N_SPACE       bwraps_space
  #define N_GAIN        bwraps_gain
  #define N_INNERTWIST  bwraps_inner_twist
  #define N_OUTERTWIST  bwraps_outer_twist
  #define N_G2          bwraps_g2
  #define N_R2          bwraps_r2
  #define N_RFACTOR     bwraps_rfactor
#endif
#endif

typedef struct {
  double N_CELLSIZE, N_SPACE, N_GAIN, 
         N_INNERTWIST, N_OUTERTWIST;
  double N_G2, N_R2, N_RFACTOR;
} Variables;

#include "apoplugin.h"

APO_PLUGIN(N_PLUGIN);

#ifdef pre_bwraps
  APO_VARIABLES(
    VAR_REAL(pre_bwraps_cellsize, 1.0),
    VAR_REAL(pre_bwraps_space, 0.0),
    VAR_REAL(pre_bwraps_gain, 2.0),
    VAR_REAL(pre_bwraps_inner_twist, 0.0),
    VAR_REAL(pre_bwraps_outer_twist, 0.0)
  );

  #define N_PLUGIN     "pre_bwraps"
  #define N_CELLSIZE    pre_bwraps_cellsize
  #define N_SPACE       pre_bwraps_space
  #define N_GAIN        pre_bwraps_gain
  #define N_INNERTWIST  pre_bwraps_inner_twist
  #define N_OUTERTWIST  pre_bwraps_outer_twist
  #define N_G2          pre_bwraps_g2
  #define N_R2          pre_bwraps_r2
  #define N_RFACTOR     pre_bwraps_rfactor
#else
#ifdef post_bwraps
  APO_VARIABLES(
    VAR_REAL(post_bwraps_cellsize, 1.0),
    VAR_REAL(post_bwraps_space, 0.0),
    VAR_REAL(post_bwraps_gain, 2.0),
    VAR_REAL(post_bwraps_inner_twist, 0.0),
    VAR_REAL(post_bwraps_outer_twist, 0.0)
  );

  #define N_PLUGIN     "post_bwraps"
  #define N_CELLSIZE    post_bwraps_cellsize
  #define N_SPACE       post_bwraps_space
  #define N_GAIN        post_bwraps_gain
  #define N_INNERTWIST  post_bwraps_inner_twist
  #define N_OUTERTWIST  post_bwraps_outer_twist
  #define N_G2          post_bwraps_g2
  #define N_R2          post_bwraps_r2
  #define N_RFACTOR     post_bwraps_rfactor
#else
  APO_VARIABLES(
    VAR_REAL(bwraps_cellsize, 1.0),
    VAR_REAL(bwraps_space, 0.0),
    VAR_REAL(bwraps_gain, 2.0),
    VAR_REAL(bwraps_inner_twist, 0.0),
    VAR_REAL(bwraps_outer_twist, 0.0)
  );
  
  #define N_PLUGIN     "bwraps"
  #define N_CELLSIZE    bwraps_cellsize
  #define N_SPACE       bwraps_space
  #define N_GAIN        bwraps_gain
  #define N_INNERTWIST  bwraps_inner_twist
  #define N_OUTERTWIST  bwraps_outer_twist
  #define N_G2          bwraps_g2
  #define N_R2          bwraps_r2
  #define N_RFACTOR     bwraps_rfactor
#endif
#endif

int PluginVarPrepare(Variation* vp)
{
	double radius = 0.5 * ( VAR(N_CELLSIZE) / ( 1.0 + VAR(N_SPACE) * VAR(N_SPACE) ) );
	
	// N_G2 is multiplier for radius
	VAR(N_G2) = sqr(VAR(N_GAIN) )/ VAR(N_CELLSIZE) + 1.0e-6;
	// Start max_bubble as maximum x or y value before applying bubble
	double max_bubble = VAR(N_G2) * radius;
	
	// Values greater than 2.0 "recurve" round the back of the bubble
    if ( max_bubble > 2.0 ) max_bubble = 1.0;
    // Expand smaller bubble to fill the space
    else max_bubble *= 1.0 / ( (max_bubble * max_bubble)/4.0 + 1.0);

	VAR(N_R2) = radius * radius;
	VAR(N_RFACTOR) =  radius / max_bubble;

    return TRUE; 
}
int PluginVarCalc(Variation* vp)
{
    double Vx, Vy; // V is "global" vector,
	double Cx, Cy; // C is "cell centre" vector
	double Lx, Ly; // L is "local" bubble vector
	double r, theta, s, c;

    #ifdef pre_bwraps
	  Vx = FTx;
      Vy = FTy;
	#else
    #ifdef post_bwraps
      Vx = FPx;
      Vy = FPy;
    #else
   	  Vx = FTx;
      Vy = FTy;  
    #endif
    #endif
    

	if ( VAR(N_CELLSIZE) == 0.0 )
	{
		// Linear if cells are too small
		#ifdef pre_bwraps
    	  FTx = VVAR * Vx;
          FTy = VVAR * Vy;  
    	#else
        #ifdef post_bwraps
          FPx = VVAR * Vx;
          FPy = VVAR * Vy;
        #else
       	  FPx += VVAR * Vx;
    	  FPy += VVAR * Vy;      
        #endif
        #endif
		
		return TRUE;
	}

	Cx = ( floor( Vx / VAR(N_CELLSIZE) ) + 0.5 ) * VAR(N_CELLSIZE);
	Cy = ( floor( Vy / VAR(N_CELLSIZE) ) + 0.5 ) * VAR(N_CELLSIZE);

	Lx = Vx - Cx;
	Ly = Vy - Cy;

	if ( ( Lx * Lx + Ly * Ly ) > VAR(N_R2) )
	{
		// Linear if outside the bubble
		#ifdef pre_bwraps
    	  FTx = VVAR * Vx;
          FTy = VVAR * Vy;  
    	#else
        #ifdef post_bwraps
          FPx = VVAR * Vx;
          FPy = VVAR * Vy;
        #else
       	  FPx += VVAR * Vx;
    	  FPy += VVAR * Vy;      
        #endif
        #endif
		return TRUE;
	}

	// Bubble distortion on local coordinates:
	Lx *= VAR(N_G2);
	Ly *= VAR(N_G2);
	r = VAR(N_RFACTOR) / ( (Lx * Lx + Ly * Ly)/4.0 + 1.0);
	Lx *= r;
	Ly *= r;
 
 	// Spin around the center:
    r = (Lx * Lx + Ly * Ly) / VAR(N_R2);  // r should be 0.0 - 1.0
    theta = VAR(N_INNERTWIST) * ( 1.0 - r ) + VAR(N_OUTERTWIST) * r;
    fsincos( theta, &s, &c );
    
    // Add rotated local vectors direct to center (avoids use of temp storage)
    Vx = Cx + c * Lx + s * Ly;
    Vy = Cy - s * Lx + c * Ly;
   	
	#ifdef pre_bwraps
	  FTx = VVAR * Vx;
      FTy = VVAR * Vy;  
	#else
    #ifdef post_bwraps
      FPx = VVAR * Vx;
      FPy = VVAR * Vy;
    #else
   	  FPx += VVAR * Vx;
	  FPy += VVAR * Vy;      
    #endif
    #endif

	return TRUE;
}
