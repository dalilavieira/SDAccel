#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_10__ {int mode; int saved_r0; int saved_r2; int delay; int device; int port; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  CCP (int) ; 
 char* ON26_VERSION ; 
 int /*<<< orphan*/  P1 ; 
 int /*<<< orphan*/  P2 ; 
 int RESET_WAIT ; 
 int j44 (int,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  printk (char*,int,...) ; 
 void* r0 () ; 
 int r1 () ; 
 void* r2 () ; 
 void* r4 () ; 
 int /*<<< orphan*/  r4l () ; 
 int /*<<< orphan*/  r4w () ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  w0 (int) ; 
 int /*<<< orphan*/  w2 (int) ; 
 int /*<<< orphan*/  w3 (int) ; 
 int /*<<< orphan*/  w4 (int) ; 
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

__attribute__((used)) static int on26_read_regr( PIA *pi, int cont, int regr )

{       int     a, b, r;

	r = (regr<<2) + 1 + cont;

        switch (pi->mode)  {

        case 0: w0(1); P1; w0(r); P2; w0(0); P1; 
		w2(6); a = r1(); w2(4);
		w2(6); b = r1(); w2(4);
		w2(6); w2(4); w2(6); w2(4);
                return j44(a,b);

        case 1: w0(1); P1; w0(r); P2; w0(0); P1;
		w2(0x26); a = r0(); w2(4); w2(0x26); w2(4);
                return a;

	case 2:
	case 3:
        case 4: w3(1); w3(1); w2(5); w4(r); w2(4);
		w3(0); w3(0); w2(0x24); a = r4(); w2(4);
		w2(0x24); (void)r4(); w2(4);
                return a;

        }
        return -1;
}

__attribute__((used)) static void on26_write_regr( PIA *pi, int cont, int regr, int val )

{       int  r;

        r = (regr<<2) + 1 + cont;

        switch (pi->mode)  {

        case 0:
        case 1: w0(1); P1; w0(r); P2; w0(0); P1;
		w0(val); P2; w0(val); P2;
		break;

	case 2:
	case 3:
        case 4: w3(1); w3(1); w2(5); w4(r); w2(4);
		w3(0); w3(0); 
		w2(5); w4(val); w2(4);
		w2(5); w4(val); w2(4);
                break;
        }
}

__attribute__((used)) static void on26_connect ( PIA *pi )

{       int	x;

	pi->saved_r0 = r0();
        pi->saved_r2 = r2();

        CCP(0x20);
	x = 8; if (pi->mode) x = 9;

	w0(2); P1; w0(8); P2;
	w0(2); P1; w0(x); P2;
}

__attribute__((used)) static void on26_disconnect ( PIA *pi )

{       if (pi->mode >= 2) { w3(4); w3(4); w3(4); w3(4); }
	              else { w0(4); P1; w0(4); P1; }
	CCP(0x30);
        w0(pi->saved_r0);
        w2(pi->saved_r2);
}

__attribute__((used)) static int on26_test_port( PIA *pi)  /* hard reset */

{       int     i, m, d, x=0, y=0;

        pi->saved_r0 = r0();
        pi->saved_r2 = r2();

        d = pi->delay;
        m = pi->mode;
        pi->delay = 5;
        pi->mode = 0;

        w2(0xc);

        CCP(0x30); CCP(0); 

        w0(0xfe);w0(0xaa);w0(0x55);w0(0);w0(0xff);
        i = ((r1() & 0xf0) << 4); w0(0x87);
        i |= (r1() & 0xf0); w0(0x78);
        w0(0x20);w2(4);w2(5);
        i |= ((r1() & 0xf0) >> 4);
        w2(4);w0(0xff);

        if (i == 0xb5f) {

            w0(2); P1; w0(0);   P2;
            w0(3); P1; w0(0);   P2;
            w0(2); P1; w0(8);   P2; udelay(100);
            w0(2); P1; w0(0xa); P2; udelay(100);
            w0(2); P1; w0(8);   P2; udelay(1000);
            
            on26_write_regr(pi,0,6,0xa0);

            for (i=0;i<RESET_WAIT;i++) {
                on26_write_regr(pi,0,6,0xa0);
                x = on26_read_regr(pi,0,7);
                on26_write_regr(pi,0,6,0xb0);
                y = on26_read_regr(pi,0,7);
                if (!((x&0x80)||(y&0x80))) break;
                mdelay(100);
            }

	    if (i == RESET_WAIT) 
		printk("on26: Device reset failed (%x,%x)\n",x,y);

            w0(4); P1; w0(4); P1;
        }

        CCP(0x30);

        pi->delay = d;
        pi->mode = m;
        w0(pi->saved_r0);
        w2(pi->saved_r2);

        return 5;
}

__attribute__((used)) static void on26_read_block( PIA *pi, char * buf, int count )

{       int     k, a, b;

        switch (pi->mode) {

        case 0: w0(1); P1; w0(1); P2; w0(2); P1; w0(0x18); P2; w0(0); P1;
		udelay(10);
		for (k=0;k<count;k++) {
                        w2(6); a = r1();
                        w2(4); b = r1();
                        buf[k] = j44(a,b);
                }
		w0(2); P1; w0(8); P2; 
                break;

        case 1: w0(1); P1; w0(1); P2; w0(2); P1; w0(0x19); P2; w0(0); P1;
		udelay(10);
                for (k=0;k<count/2;k++) {
                        w2(0x26); buf[2*k] = r0();  
			w2(0x24); buf[2*k+1] = r0();
                }
                w0(2); P1; w0(9); P2;
                break;

        case 2: w3(1); w3(1); w2(5); w4(1); w2(4);
		w3(0); w3(0); w2(0x24);
		udelay(10);
                for (k=0;k<count;k++) buf[k] = r4();
                w2(4);
                break;

        case 3: w3(1); w3(1); w2(5); w4(1); w2(4);
                w3(0); w3(0); w2(0x24);
                udelay(10);
                for (k=0;k<count/2;k++) ((u16 *)buf)[k] = r4w();
                w2(4);
                break;

        case 4: w3(1); w3(1); w2(5); w4(1); w2(4);
                w3(0); w3(0); w2(0x24);
                udelay(10);
                for (k=0;k<count/4;k++) ((u32 *)buf)[k] = r4l();
                w2(4);
                break;

        }
}

__attribute__((used)) static void on26_write_block( PIA *pi, char * buf, int count )

{       int	k;

        switch (pi->mode) {

        case 0: 
        case 1: w0(1); P1; w0(1); P2; 
		w0(2); P1; w0(0x18+pi->mode); P2; w0(0); P1;
		udelay(10);
		for (k=0;k<count/2;k++) {
                        w2(5); w0(buf[2*k]); 
			w2(7); w0(buf[2*k+1]);
                }
                w2(5); w2(4);
		w0(2); P1; w0(8+pi->mode); P2;
                break;

        case 2: w3(1); w3(1); w2(5); w4(1); w2(4);
		w3(0); w3(0); w2(0xc5);
		udelay(10);
                for (k=0;k<count;k++) w4(buf[k]);
		w2(0xc4);
                break;

        case 3: w3(1); w3(1); w2(5); w4(1); w2(4);
                w3(0); w3(0); w2(0xc5);
                udelay(10);
                for (k=0;k<count/2;k++) w4w(((u16 *)buf)[k]);
                w2(0xc4);
                break;

        case 4: w3(1); w3(1); w2(5); w4(1); w2(4);
                w3(0); w3(0); w2(0xc5);
                udelay(10);
                for (k=0;k<count/4;k++) w4l(((u32 *)buf)[k]);
                w2(0xc4);
                break;

        }

}

__attribute__((used)) static void on26_log_adapter( PIA *pi, char * scratch, int verbose )

{       char    *mode_string[5] = {"4-bit","8-bit","EPP-8",
				   "EPP-16","EPP-32"};

        printk("%s: on26 %s, OnSpec 90c26 at 0x%x, ",
                pi->device,ON26_VERSION,pi->port);
        printk("mode %d (%s), delay %d\n",pi->mode,
		mode_string[pi->mode],pi->delay);

}

