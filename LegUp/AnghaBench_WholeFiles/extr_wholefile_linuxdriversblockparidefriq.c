#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_12__ {int mode; int saved_r0; int saved_r2; int device; int private; int /*<<< orphan*/  delay; int /*<<< orphan*/  port; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  CMD (int) ; 
 char* FRIQ_VERSION ; 
 int* cont_map ; 
 int j44 (int,int) ; 
 int /*<<< orphan*/  printk (char*,int,char*,int,...) ; 
 void* r0 () ; 
 int r1 () ; 
 int r2 () ; 
 char r4 () ; 
 int /*<<< orphan*/  r4l () ; 
 int /*<<< orphan*/  r4w () ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  w0 (int) ; 
 int /*<<< orphan*/  w2 (int) ; 
 int /*<<< orphan*/  w4 (char) ; 
 int /*<<< orphan*/  w4l (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  w4w (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u16 pi_swab16( char *b, int k)

{ 	union { u16 u; char t[2]; } r;

	r.t[0]=b[2*k+1]; r.t[1]=b[2*k];
        return r.u;
}

__attribute__((used)) static inline u32 pi_swab32( char *b, int k)

{ 	union { u32 u; char f[4]; } r;

	r.f[0]=b[4*k+1]; r.f[1]=b[4*k];
	r.f[2]=b[4*k+3]; r.f[3]=b[4*k+2];
        return r.u;
}

__attribute__((used)) static int friq_read_regr( PIA *pi, int cont, int regr )

{	int	h,l,r;

	r = regr + cont_map[cont];

	CMD(r);
	w2(6); l = r1();
	w2(4); h = r1();
	w2(4); 

	return j44(l,h);

}

__attribute__((used)) static void friq_write_regr( PIA *pi, int cont, int regr, int val)

{	int r;

        r = regr + cont_map[cont];

	CMD(r);
	w0(val);
	w2(5);w2(7);w2(5);w2(4);
}

__attribute__((used)) static void friq_read_block_int( PIA *pi, char * buf, int count, int regr )

{       int     h, l, k, ph;

        switch(pi->mode) {

        case 0: CMD(regr); 
                for (k=0;k<count;k++) {
                        w2(6); l = r1();
                        w2(4); h = r1();
                        buf[k] = j44(l,h);
                }
                w2(4);
                break;

        case 1: ph = 2;
                CMD(regr+0xc0); 
                w0(0xff);
                for (k=0;k<count;k++) {
                        w2(0xa4 + ph); 
                        buf[k] = r0();
                        ph = 2 - ph;
                } 
                w2(0xac); w2(0xa4); w2(4);
                break;

	case 2: CMD(regr+0x80);
		for (k=0;k<count-2;k++) buf[k] = r4();
		w2(0xac); w2(0xa4);
		buf[count-2] = r4();
		buf[count-1] = r4();
		w2(4);
		break;

	case 3: CMD(regr+0x80);
                for (k=0;k<(count/2)-1;k++) ((u16 *)buf)[k] = r4w();
                w2(0xac); w2(0xa4);
                buf[count-2] = r4();
                buf[count-1] = r4();
                w2(4);
                break;

	case 4: CMD(regr+0x80);
                for (k=0;k<(count/4)-1;k++) ((u32 *)buf)[k] = r4l();
                buf[count-4] = r4();
                buf[count-3] = r4();
                w2(0xac); w2(0xa4);
                buf[count-2] = r4();
                buf[count-1] = r4();
                w2(4);
                break;

        }
}

__attribute__((used)) static void friq_read_block( PIA *pi, char * buf, int count)

{	friq_read_block_int(pi,buf,count,0x08);
}

__attribute__((used)) static void friq_write_block( PIA *pi, char * buf, int count )
 
{	int	k;

	switch(pi->mode) {

	case 0:
	case 1: CMD(8); w2(5);
        	for (k=0;k<count;k++) {
			w0(buf[k]);
			w2(7);w2(5);
		}
		w2(4);
		break;

	case 2: CMD(0xc8); w2(5);
		for (k=0;k<count;k++) w4(buf[k]);
		w2(4);
		break;

        case 3: CMD(0xc8); w2(5);
                for (k=0;k<count/2;k++) w4w(((u16 *)buf)[k]);
                w2(4);
                break;

        case 4: CMD(0xc8); w2(5);
                for (k=0;k<count/4;k++) w4l(((u32 *)buf)[k]);
                w2(4);
                break;
	}
}

__attribute__((used)) static void friq_connect ( PIA *pi  )

{       pi->saved_r0 = r0();
        pi->saved_r2 = r2();
	w2(4);
}

__attribute__((used)) static void friq_disconnect ( PIA *pi )

{       CMD(0x20);
	w0(pi->saved_r0);
        w2(pi->saved_r2);
}

__attribute__((used)) static int friq_test_proto( PIA *pi, char * scratch, int verbose )

{       int     j, k, r;
	int	e[2] = {0,0};

	pi->saved_r0 = r0();	
	w0(0xff); udelay(20); CMD(0x3d); /* turn the power on */
	udelay(500);
	w0(pi->saved_r0);

	friq_connect(pi);
	for (j=0;j<2;j++) {
                friq_write_regr(pi,0,6,0xa0+j*0x10);
                for (k=0;k<256;k++) {
                        friq_write_regr(pi,0,2,k^0xaa);
                        friq_write_regr(pi,0,3,k^0x55);
                        if (friq_read_regr(pi,0,2) != (k^0xaa)) e[j]++;
                        }
                }
	friq_disconnect(pi);

	friq_connect(pi);
        friq_read_block_int(pi,scratch,512,0x10);
        r = 0;
        for (k=0;k<128;k++) if (scratch[k] != k) r++;
	friq_disconnect(pi);

        if (verbose)  {
            printk("%s: friq: port 0x%x, mode %d, test=(%d,%d,%d)\n",
                   pi->device,pi->port,pi->mode,e[0],e[1],r);
        }

        return (r || (e[0] && e[1]));
}

__attribute__((used)) static void friq_log_adapter( PIA *pi, char * scratch, int verbose )

{       char    *mode_string[6] = {"4-bit","8-bit",
				   "EPP-8","EPP-16","EPP-32"};

        printk("%s: friq %s, Freecom IQ ASIC-2 adapter at 0x%x, ", pi->device,
		FRIQ_VERSION,pi->port);
        printk("mode %d (%s), delay %d\n",pi->mode,
		mode_string[pi->mode],pi->delay);

	pi->private = 1;
	friq_connect(pi);
	CMD(0x9e);  		/* disable sleep timer */
	friq_disconnect(pi);

}

__attribute__((used)) static void friq_release_proto( PIA *pi)
{
	if (pi->private) {		/* turn off the power */
		friq_connect(pi);
		CMD(0x1d); CMD(0x1e);
		friq_disconnect(pi);
		pi->private = 0;
	}
}

