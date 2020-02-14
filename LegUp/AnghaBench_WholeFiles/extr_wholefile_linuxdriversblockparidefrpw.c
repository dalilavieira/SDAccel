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
struct TYPE_12__ {int mode; int saved_r0; int saved_r2; int delay; int private; int port; int /*<<< orphan*/  device; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  FRPW_VERSION ; 
 int /*<<< orphan*/  cec4 ; 
 int* cont_map ; 
 int j44 (int,int) ; 
 int /*<<< orphan*/  printk (char*,int,...) ; 
 void* r0 () ; 
 int r1 () ; 
 void* r2 () ; 
 char r4 () ; 
 int /*<<< orphan*/  r4l () ; 
 int /*<<< orphan*/  r4w () ; 
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

__attribute__((used)) static int frpw_read_regr( PIA *pi, int cont, int regr )

{	int	h,l,r;

	r = regr + cont_map[cont];

	w2(4);
	w0(r); cec4;
	w2(6); l = r1();
	w2(4); h = r1();
	w2(4); 

	return j44(l,h);

}

__attribute__((used)) static void frpw_write_regr( PIA *pi, int cont, int regr, int val)

{	int r;

        r = regr + cont_map[cont];

	w2(4); w0(r); cec4; 
	w0(val);
	w2(5);w2(7);w2(5);w2(4);
}

__attribute__((used)) static void frpw_read_block_int( PIA *pi, char * buf, int count, int regr )

{       int     h, l, k, ph;

        switch(pi->mode) {

        case 0: w2(4); w0(regr); cec4;
                for (k=0;k<count;k++) {
                        w2(6); l = r1();
                        w2(4); h = r1();
                        buf[k] = j44(l,h);
                }
                w2(4);
                break;

        case 1: ph = 2;
                w2(4); w0(regr + 0xc0); cec4;
                w0(0xff);
                for (k=0;k<count;k++) {
                        w2(0xa4 + ph); 
                        buf[k] = r0();
                        ph = 2 - ph;
                } 
                w2(0xac); w2(0xa4); w2(4);
                break;

        case 2: w2(4); w0(regr + 0x80); cec4;
                for (k=0;k<count;k++) buf[k] = r4();
                w2(0xac); w2(0xa4);
                w2(4);
                break;

	case 3: w2(4); w0(regr + 0x80); cec4;
		for (k=0;k<count-2;k++) buf[k] = r4();
		w2(0xac); w2(0xa4);
		buf[count-2] = r4();
		buf[count-1] = r4();
		w2(4);
		break;

	case 4: w2(4); w0(regr + 0x80); cec4;
                for (k=0;k<(count/2)-1;k++) ((u16 *)buf)[k] = r4w();
                w2(0xac); w2(0xa4);
                buf[count-2] = r4();
                buf[count-1] = r4();
                w2(4);
                break;

	case 5: w2(4); w0(regr + 0x80); cec4;
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

__attribute__((used)) static void frpw_read_block( PIA *pi, char * buf, int count)

{	frpw_read_block_int(pi,buf,count,0x08);
}

__attribute__((used)) static void frpw_write_block( PIA *pi, char * buf, int count )
 
{	int	k;

	switch(pi->mode) {

	case 0:
	case 1:
	case 2: w2(4); w0(8); cec4; w2(5);
        	for (k=0;k<count;k++) {
			w0(buf[k]);
			w2(7);w2(5);
		}
		w2(4);
		break;

	case 3: w2(4); w0(0xc8); cec4; w2(5);
		for (k=0;k<count;k++) w4(buf[k]);
		w2(4);
		break;

        case 4: w2(4); w0(0xc8); cec4; w2(5);
                for (k=0;k<count/2;k++) w4w(((u16 *)buf)[k]);
                w2(4);
                break;

        case 5: w2(4); w0(0xc8); cec4; w2(5);
                for (k=0;k<count/4;k++) w4l(((u32 *)buf)[k]);
                w2(4);
                break;
	}
}

__attribute__((used)) static void frpw_connect ( PIA *pi  )

{       pi->saved_r0 = r0();
        pi->saved_r2 = r2();
	w2(4);
}

__attribute__((used)) static void frpw_disconnect ( PIA *pi )

{       w2(4); w0(0x20); cec4;
	w0(pi->saved_r0);
        w2(pi->saved_r2);
}

__attribute__((used)) static int frpw_test_pnp ( PIA *pi )

/*  returns chip_type:   0 = Xilinx, 1 = ASIC   */

{	int olddelay, a, b;

#ifdef FRPW_HARD_RESET
        w0(0); w2(8); udelay(50); w2(0xc);   /* parallel bus reset */
        mdelay(1500);
#endif

	olddelay = pi->delay;
	pi->delay = 10;

	pi->saved_r0 = r0();
        pi->saved_r2 = r2();
	
	w2(4); w0(4); w2(6); w2(7);
	a = r1() & 0xff; w2(4); b = r1() & 0xff;
	w2(0xc); w2(0xe); w2(4);

	pi->delay = olddelay;
        w0(pi->saved_r0);
        w2(pi->saved_r2);

	return ((~a&0x40) && (b&0x40));
}

__attribute__((used)) static int frpw_test_proto( PIA *pi, char * scratch, int verbose )

{       int     j, k, r;
	int	e[2] = {0,0};

	if ((pi->private>>1) != pi->port)
	   pi->private = frpw_test_pnp(pi) + 2*pi->port;

	if (((pi->private%2) == 0) && (pi->mode > 2)) {
	   if (verbose) 
		printk("%s: frpw: Xilinx does not support mode %d\n",
			pi->device, pi->mode);
	   return 1;
	}

	if (((pi->private%2) == 1) && (pi->mode == 2)) {
	   if (verbose)
		printk("%s: frpw: ASIC does not support mode 2\n",
			pi->device);
	   return 1;
	}

	frpw_connect(pi);
	for (j=0;j<2;j++) {
                frpw_write_regr(pi,0,6,0xa0+j*0x10);
                for (k=0;k<256;k++) {
                        frpw_write_regr(pi,0,2,k^0xaa);
                        frpw_write_regr(pi,0,3,k^0x55);
                        if (frpw_read_regr(pi,0,2) != (k^0xaa)) e[j]++;
                        }
                }
	frpw_disconnect(pi);

	frpw_connect(pi);
        frpw_read_block_int(pi,scratch,512,0x10);
        r = 0;
        for (k=0;k<128;k++) if (scratch[k] != k) r++;
	frpw_disconnect(pi);

        if (verbose)  {
            printk("%s: frpw: port 0x%x, chip %ld, mode %d, test=(%d,%d,%d)\n",
                   pi->device,pi->port,(pi->private%2),pi->mode,e[0],e[1],r);
        }

        return (r || (e[0] && e[1]));
}

__attribute__((used)) static void frpw_log_adapter( PIA *pi, char * scratch, int verbose )

{       char    *mode_string[6] = {"4-bit","8-bit","EPP",
				   "EPP-8","EPP-16","EPP-32"};

        printk("%s: frpw %s, Freecom (%s) adapter at 0x%x, ", pi->device,
		FRPW_VERSION,((pi->private%2) == 0)?"Xilinx":"ASIC",pi->port);
        printk("mode %d (%s), delay %d\n",pi->mode,
		mode_string[pi->mode],pi->delay);

}

