#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  long off_t ;
struct TYPE_11__ {long rate; } ;
struct TYPE_12__ {unsigned long ntom_step; unsigned long* ntom_val; long num; long spf; void* err; TYPE_1__ af; } ;
typedef  TYPE_2__ mpg123_handle ;

/* Variables and functions */
 void* MPG123_BAD_RATE ; 
 scalar_t__ NOQUIET ; 
 scalar_t__ NTOM_MAX ; 
 long NTOM_MAX_FREQ ; 
 long NTOM_MUL ; 
 scalar_t__ VERBOSE2 ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  error3 (char*,scalar_t__,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,long,long) ; 
 long frame_freq (TYPE_2__*) ; 
 unsigned long ntom_val (TYPE_2__*,long) ; 
 int /*<<< orphan*/  stderr ; 

int synth_ntom_set_step(mpg123_handle *fr)
{
	long m,n;
	m = frame_freq(fr);
	n = fr->af.rate;
	if(VERBOSE2)
		fprintf(stderr,"Init rate converter: %ld->%ld\n",m,n);

	if(n > NTOM_MAX_FREQ || m > NTOM_MAX_FREQ || m <= 0 || n <= 0) {
		if(NOQUIET) error("NtoM converter: illegal rates");
		fr->err = MPG123_BAD_RATE;
		return -1;
	}

	n *= NTOM_MUL;
	fr->ntom_step = (unsigned long) n / m;

	if(fr->ntom_step > (unsigned long)NTOM_MAX*NTOM_MUL) {
		if(NOQUIET) error3("max. 1:%i conversion allowed (%lu vs %lu)!", NTOM_MAX, fr->ntom_step, (unsigned long)8*NTOM_MUL);
		fr->err = MPG123_BAD_RATE;
		return -1;
	}

	fr->ntom_val[0] = fr->ntom_val[1] = ntom_val(fr, fr->num);
	return 0;
}

unsigned long ntom_val(mpg123_handle *fr, off_t frame)
{
	off_t ntm;
#ifdef SAFE_NTOM /* Carry out the loop, without the threatening integer overflow. */
	off_t f;
	ntm = NTOM_MUL>>1; /* for frame 0 */
	for(f=0; f<frame; ++f)   /* for frame > 0 */
	{
		ntm += fr->spf*fr->ntom_step;
		ntm -= (ntm/NTOM_MUL)*NTOM_MUL;
	}
#else /* Just make one computation with overall sample offset. */
	ntm  = (NTOM_MUL>>1) + fr->spf*frame*fr->ntom_step;
	ntm -= (ntm/NTOM_MUL)*NTOM_MUL;
#endif
	return (unsigned long) ntm;
}

void ntom_set_ntom(mpg123_handle *fr, off_t num)
{
	fr->ntom_val[1] = fr->ntom_val[0] = ntom_val(fr, num);
}

off_t ntom_frame_outsamples(mpg123_handle *fr)
{
	/* The do this before decoding the separate channels, so there is only one common ntom value. */
	int ntm = fr->ntom_val[0];
	ntm += fr->spf*fr->ntom_step;
	return ntm/NTOM_MUL;
}

off_t ntom_frmouts(mpg123_handle *fr, off_t frame)
{
#ifdef SAFE_NTOM
	off_t f;
#endif
	off_t soff = 0;
	off_t ntm = ntom_val(fr,0);
#ifdef SAFE_NTOM
	if(frame <= 0) return 0;
	for(f=0; f<frame; ++f)
	{
		ntm  += fr->spf*fr->ntom_step;
		soff += ntm/NTOM_MUL;
		ntm  -= (ntm/NTOM_MUL)*NTOM_MUL;
	}
#else
	soff = (ntm + frame*(off_t)fr->spf*(off_t)fr->ntom_step)/(off_t)NTOM_MUL;
#endif
	return soff;
}

off_t ntom_ins2outs(mpg123_handle *fr, off_t ins)
{
	off_t soff = 0;
	off_t ntm = ntom_val(fr,0);
#ifdef SAFE_NTOM
	{
		off_t block = fr->spf;
		if(ins <= 0) return 0;
		do
		{
			off_t nowblock = ins > block ? block : ins;
			ntm  += nowblock*fr->ntom_step;
			soff += ntm/NTOM_MUL;
			ntm  -= (ntm/NTOM_MUL)*NTOM_MUL;
			ins -= nowblock;
		} while(ins > 0);
	}
#else
	/* Beware of overflows: when off_t is 32bits, the multiplication blows too easily.
	   Of course, it blows for 64bits, too, in theory, but that's for _really_ large files. */
	soff = ((off_t)ntm + (off_t)ins*(off_t)fr->ntom_step)/(off_t)NTOM_MUL;
#endif
	return soff;
}

off_t ntom_frameoff(mpg123_handle *fr, off_t soff)
{
	off_t ioff = 0; /* frames or samples */
	off_t ntm = ntom_val(fr,0);
#ifdef SAFE_NTOM
	if(soff <= 0) return 0;
	for(ioff=0; 1; ++ioff)
	{
		ntm  += fr->spf*fr->ntom_step;
		if(ntm/NTOM_MUL > soff) break;
		soff -= ntm/NTOM_MUL;
		ntm  -= (ntm/NTOM_MUL)*NTOM_MUL;
	}
	return ioff;
#else
	ioff = (soff*(off_t)NTOM_MUL-ntm)/(off_t)fr->ntom_step;
	return ioff/(off_t)fr->spf;
#endif
}

