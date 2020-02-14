#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int x; int y; } ;
typedef  TYPE_1__ FT_Vector ;
typedef  int FT_UInt32 ;
typedef  int FT_Int ;
typedef  int FT_Fixed ;
typedef  int FT_Angle ;

/* Variables and functions */
 scalar_t__ FT_ANGLE_PI ; 
 int FT_ANGLE_PI2 ; 
 int FT_PAD_ROUND (int,int) ; 
 int FT_TRIG_MAX_ITERS ; 
 int FT_TRIG_SCALE ; 
 int* ft_trig_arctan_table ; 

__attribute__((used)) static FT_Fixed
  ft_trig_downscale( FT_Fixed  val )
  {
    FT_Fixed   s;
    FT_UInt32  v1, v2, k1, k2, hi, lo1, lo2, lo3;


    s   = val;
    val = ( val >= 0 ) ? val : -val;

    v1 = (FT_UInt32)val >> 16;
    v2 = (FT_UInt32)(val & 0xFFFFL);

    k1 = (FT_UInt32)FT_TRIG_SCALE >> 16;       /* constant */
    k2 = (FT_UInt32)(FT_TRIG_SCALE & 0xFFFFL);   /* constant */

    hi   = k1 * v1;
    lo1  = k1 * v2 + k2 * v1;       /* can't overflow */

    lo2  = ( k2 * v2 ) >> 16;
    lo3  = ( lo1 >= lo2 ) ? lo1 : lo2;
    lo1 += lo2;

    hi  += lo1 >> 16;
    if ( lo1 < lo3 )
      hi += (FT_UInt32)0x10000UL;

    val  = (FT_Fixed)hi;

    return ( s >= 0 ) ? val : -val;
  }

__attribute__((used)) static FT_Int
  ft_trig_prenorm( FT_Vector*  vec )
  {
    FT_Fixed  x, y, z;
    FT_Int    shift;


    x = vec->x;
    y = vec->y;

    z     = ( ( x >= 0 ) ? x : - x ) | ( (y >= 0) ? y : -y );
    shift = 0;

#if 1
    /* determine msb bit index in `shift' */
    if ( z >= ( 1L << 16 ) )
    {
      z     >>= 16;
      shift  += 16;
    }
    if ( z >= ( 1L << 8 ) )
    {
      z     >>= 8;
      shift  += 8;
    }
    if ( z >= ( 1L << 4 ) )
    {
      z     >>= 4;
      shift  += 4;
    }
    if ( z >= ( 1L << 2 ) )
    {
      z     >>= 2;
      shift  += 2;
    }
    if ( z >= ( 1L << 1 ) )
    {
      z    >>= 1;
      shift += 1;
    }

    if ( shift <= 27 )
    {
      shift  = 27 - shift;
      vec->x = x << shift;
      vec->y = y << shift;
    }
    else
    {
      shift -= 27;
      vec->x = x >> shift;
      vec->y = y >> shift;
      shift  = -shift;
    }

#else /* 0 */

    if ( z < ( 1L << 27 ) )
    {
      do
      {
        shift++;
        z <<= 1;
      } while ( z < ( 1L << 27 ) );
      vec->x = x << shift;
      vec->y = y << shift;
    }
    else if ( z > ( 1L << 28 ) )
    {
      do
      {
        shift++;
        z >>= 1;
      } while ( z > ( 1L << 28 ) );

      vec->x = x >> shift;
      vec->y = y >> shift;
      shift  = -shift;
    }

#endif /* 0 */

    return shift;
  }

__attribute__((used)) static void
  ft_trig_pseudo_rotate( FT_Vector*  vec,
                         FT_Angle    theta )
  {
    FT_Int           i;
    FT_Fixed         x, y, xtemp;
    const FT_Fixed  *arctanptr;


    x = vec->x;
    y = vec->y;

    /* Get angle between -90 and 90 degrees */
    while ( theta <= -FT_ANGLE_PI2 )
    {
      x = -x;
      y = -y;
      theta += FT_ANGLE_PI;
    }

    while ( theta > FT_ANGLE_PI2 )
    {
      x = -x;
      y = -y;
      theta -= FT_ANGLE_PI;
    }

    /* Initial pseudorotation, with left shift */
    arctanptr = ft_trig_arctan_table;

    if ( theta < 0 )
    {
      xtemp  = x + ( y << 1 );
      y      = y - ( x << 1 );
      x      = xtemp;
      theta += *arctanptr++;
    }
    else
    {
      xtemp  = x - ( y << 1 );
      y      = y + ( x << 1 );
      x      = xtemp;
      theta -= *arctanptr++;
    }

    /* Subsequent pseudorotations, with right shifts */
    i = 0;
    do
    {
      if ( theta < 0 )
      {
        xtemp  = x + ( y >> i );
        y      = y - ( x >> i );
        x      = xtemp;
        theta += *arctanptr++;
      }
      else
      {
        xtemp  = x - ( y >> i );
        y      = y + ( x >> i );
        x      = xtemp;
        theta -= *arctanptr++;
      }
    } while ( ++i < FT_TRIG_MAX_ITERS );

    vec->x = x;
    vec->y = y;
  }

__attribute__((used)) static void
  ft_trig_pseudo_polarize( FT_Vector*  vec )
  {
    FT_Fixed         theta;
    FT_Fixed         yi, i;
    FT_Fixed         x, y;
    const FT_Fixed  *arctanptr;


    x = vec->x;
    y = vec->y;

    /* Get the vector into the right half plane */
    theta = 0;
    if ( x < 0 )
    {
      x = -x;
      y = -y;
      theta = 2 * FT_ANGLE_PI2;
    }

    if ( y > 0 )
      theta = - theta;

    arctanptr = ft_trig_arctan_table;

    if ( y < 0 )
    {
      /* Rotate positive */
      yi     = y + ( x << 1 );
      x      = x - ( y << 1 );
      y      = yi;
      theta -= *arctanptr++;  /* Subtract angle */
    }
    else
    {
      /* Rotate negative */
      yi     = y - ( x << 1 );
      x      = x + ( y << 1 );
      y      = yi;
      theta += *arctanptr++;  /* Add angle */
    }

    i = 0;
    do
    {
      if ( y < 0 )
      {
        /* Rotate positive */
        yi     = y + ( x >> i );
        x      = x - ( y >> i );
        y      = yi;
        theta -= *arctanptr++;
      }
      else
      {
        /* Rotate negative */
        yi     = y - ( x >> i );
        x      = x + ( y >> i );
        y      = yi;
        theta += *arctanptr++;
      }
    } while ( ++i < FT_TRIG_MAX_ITERS );

    /* round theta */
    if ( theta >= 0 )
      theta = FT_PAD_ROUND( theta, 32 );
    else
      theta = -FT_PAD_ROUND( -theta, 32 );

    vec->x = x;
    vec->y = theta;
  }

