#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  void* real ;
struct TYPE_7__ {int dec_enc; } ;
struct TYPE_6__ {double outscale; } ;
struct TYPE_8__ {double lastscale; unsigned char* conv16to8_buf; unsigned char* conv16to8; void* err; TYPE_2__ af; void** decwin; TYPE_1__ p; } ;
typedef  TYPE_3__ mpg123_handle ;

/* Variables and functions */
 void* DOUBLE_TO_REAL (double) ; 
#define  MPG123_ENC_ALAW_8 131 
#define  MPG123_ENC_SIGNED_8 130 
#define  MPG123_ENC_ULAW_8 129 
#define  MPG123_ENC_UNSIGNED_8 128 
 void* MPG123_ERR_16TO8TABLE ; 
 double M_PI ; 
 scalar_t__ NOQUIET ; 
 double cos (double) ; 
 int /*<<< orphan*/  debug (char*) ; 
 int /*<<< orphan*/  debug1 (char*,double) ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  error2 (char*,int,int) ; 
 scalar_t__* intwinbase ; 
 double log (double) ; 
 scalar_t__ malloc (int) ; 
 void*** pnts ; 

void prepare_decode_tables()
{
#if !defined(REAL_IS_FIXED) || !defined(PRECALC_TABLES)
  int i,k,kr,divv;
  real *costab;

  for(i=0;i<5;i++)
  {
    kr=0x10>>i; divv=0x40>>i;
    costab = pnts[i];
    for(k=0;k<kr;k++)
      costab[k] = DOUBLE_TO_REAL(1.0 / (2.0 * cos(M_PI * ((double) k * 2.0 + 1.0) / (double) divv)));
  }
#endif
}

void make_decode_tables(mpg123_handle *fr)
{
	int i,j;
	int idx = 0;
	double scaleval;
#ifdef REAL_IS_FIXED
	real scaleval_long;
#endif
	/* Scale is always based on 1.0 . */
	scaleval = -0.5*(fr->lastscale < 0 ? fr->p.outscale : fr->lastscale);
	debug1("decode tables with scaleval %g", scaleval);
#ifdef REAL_IS_FIXED
	scaleval_long = DOUBLE_TO_REAL_15(scaleval);
	debug1("decode table with fixed scaleval %li", (long)scaleval_long);
	if(scaleval_long > 28618 || scaleval_long < -28618)
	{
		/* TODO: Limit the scaleval itself or limit the multiplication afterwards?
		   The former basically disables significant amplification for fixed-point
		   decoders, but avoids (possibly subtle) distortion. */
		/* This would limit the amplification instead:
		   scaleval_long = scaleval_long < 0 ? -28618 : 28618; */
		if(NOQUIET) warning("Desired amplification may introduce distortion.");
	}
#endif
	for(i=0,j=0;i<256;i++,j++,idx+=32)
	{
		if(idx < 512+16)
#ifdef REAL_IS_FIXED
		fr->decwin[idx+16] = fr->decwin[idx] =
			REAL_SCALE_WINDOW(sat_mul32(intwinbase[j],scaleval_long));
#else
		fr->decwin[idx+16] = fr->decwin[idx] = DOUBLE_TO_REAL((double) intwinbase[j] * scaleval);
#endif

		if(i % 32 == 31)
		idx -= 1023;
		if(i % 64 == 63)
#ifdef REAL_IS_FIXED
		scaleval_long = - scaleval_long;
#else
		scaleval = - scaleval;
#endif
	}

	for( /* i=256 */ ;i<512;i++,j--,idx+=32)
	{
		if(idx < 512+16)
#ifdef REAL_IS_FIXED
		fr->decwin[idx+16] = fr->decwin[idx] =
			REAL_SCALE_WINDOW(sat_mul32(intwinbase[j],scaleval_long));
#else
		fr->decwin[idx+16] = fr->decwin[idx] = DOUBLE_TO_REAL((double) intwinbase[j] * scaleval);
#endif

		if(i % 32 == 31)
		idx -= 1023;
		if(i % 64 == 63)
#ifdef REAL_IS_FIXED
		scaleval_long = - scaleval_long;
#else
		scaleval = - scaleval;
#endif
	}
#if defined(OPT_X86_64) || defined(OPT_ALTIVEC) || defined(OPT_SSE) || defined(OPT_SSE_VINTAGE) || defined(OPT_ARM) || defined(OPT_NEON) || defined(OPT_NEON64) || defined(OPT_AVX)
	if(  fr->cpu_opts.type == x86_64
	  || fr->cpu_opts.type == altivec
	  || fr->cpu_opts.type == sse
	  || fr->cpu_opts.type == sse_vintage
	  || fr->cpu_opts.type == arm
	  || fr->cpu_opts.type == neon
	  || fr->cpu_opts.type == neon64
	  || fr->cpu_opts.type == avx )
	{ /* for float SSE / AltiVec / ARM decoder */
		for(i=512; i<512+32; i++)
		{
			fr->decwin[i] = (i&1) ? fr->decwin[i] : 0;
		}
		for(i=0; i<512; i++)
		{
			fr->decwin[512+32+i] = -fr->decwin[511-i];
		}
#if defined(OPT_NEON) || defined(OPT_NEON64)
		if(fr->cpu_opts.type == neon || fr->cpu_opts.type == neon64)
		{
			for(i=0; i<512; i+=2)
			{
				fr->decwin[i] = -fr->decwin[i];
			}
		}
#endif
	}
#endif
	debug("decode tables done");
}

int make_conv16to8_table(mpg123_handle *fr)
{
  int i;
	int mode = fr->af.dec_enc;

  /*
   * ????: 8.0 is right but on SB cards '2.0' is a better value ???
   */
  const double mul = 8.0;

  if(!fr->conv16to8_buf){
    fr->conv16to8_buf = (unsigned char *) malloc(8192);
    if(!fr->conv16to8_buf) {
      fr->err = MPG123_ERR_16TO8TABLE;
      if(NOQUIET) error("Can't allocate 16 to 8 converter table!");
      return -1;
    }
    fr->conv16to8 = fr->conv16to8_buf + 4096;
  }

	switch(mode)
	{
	case MPG123_ENC_ULAW_8:
	{
		double m=127.0 / log(256.0);
		int c1;

		for(i=-4096;i<4096;i++)
		{
			/* dunno whether this is a valid transformation rule ?!?!? */
			if(i < 0)
			c1 = 127 - (int) (log( 1.0 - 255.0 * (double) i*mul / 32768.0 ) * m);
			else
			c1 = 255 - (int) (log( 1.0 + 255.0 * (double) i*mul / 32768.0 ) * m);
			if(c1 < 0 || c1 > 255)
			{
				if(NOQUIET) error2("Converror %d %d",i,c1);
				return -1;
			}
			if(c1 == 0)
			c1 = 2;
			fr->conv16to8[i] = (unsigned char) c1;
		}
	}
	break;
	case MPG123_ENC_SIGNED_8:
		for(i=-4096;i<4096;i++)
		fr->conv16to8[i] = i>>5;
	break;
	case MPG123_ENC_UNSIGNED_8:
		for(i=-4096;i<4096;i++)
		fr->conv16to8[i] = (i>>5)+128;
	break;
	case MPG123_ENC_ALAW_8:
	{
		/*
			Let's believe Wikipedia (http://en.wikipedia.org/wiki/G.711) that this
			is the correct table:

			s0000000wxyza... 	n000wxyz  [0-31] -> [0-15]
			s0000001wxyza... 	n001wxyz  [32-63] -> [16-31]
			s000001wxyzab... 	n010wxyz  [64-127] -> [32-47]
			s00001wxyzabc... 	n011wxyz  [128-255] -> [48-63]
			s0001wxyzabcd... 	n100wxyz  [256-511] -> [64-79]
			s001wxyzabcde... 	n101wxyz  [512-1023] -> [80-95]
			s01wxyzabcdef... 	n110wxyz  [1024-2047] -> [96-111]
			s1wxyzabcdefg... 	n111wxyz  [2048-4095] -> [112-127]

			Let's extend to -4096, too.
			Also, bytes are xored with 0x55 for transmission.

			Since it sounds OK, I assume it is fine;-)
		*/
		for(i=0; i<64; ++i)
		fr->conv16to8[i] = ((unsigned int)i)>>1;
		for(i=64; i<128; ++i)
		fr->conv16to8[i] = ((((unsigned int)i)>>2) & 0xf) | (2<<4);
		for(i=128; i<256; ++i)
		fr->conv16to8[i] = ((((unsigned int)i)>>3) & 0xf) | (3<<4);
		for(i=256; i<512; ++i)
		fr->conv16to8[i] = ((((unsigned int)i)>>4) & 0xf) | (4<<4);
		for(i=512; i<1024; ++i)
		fr->conv16to8[i] = ((((unsigned int)i)>>5) & 0xf) | (5<<4);
		for(i=1024; i<2048; ++i)
		fr->conv16to8[i] = ((((unsigned int)i)>>6) & 0xf) | (6<<4);
		for(i=2048; i<4096; ++i)
		fr->conv16to8[i] = ((((unsigned int)i)>>7) & 0xf) | (7<<4);

		for(i=-4095; i<0; ++i)
		fr->conv16to8[i] = fr->conv16to8[-i] | 0x80;

		fr->conv16to8[-4096] = fr->conv16to8[-4095];

		for(i=-4096;i<4096;i++)
		{
			/* fr->conv16to8[i] = - i>>5; */
			/* fprintf(stderr, "table %i %i\n", i<<AUSHIFT, fr->conv16to8[i]); */
			fr->conv16to8[i] ^= 0x55;
		}
	}
	break;
	default:
		fr->err = MPG123_ERR_16TO8TABLE;
		if(NOQUIET) error("Unknown 8 bit encoding choice.");
		return -1;
	break;
	}

	return 0;
}

