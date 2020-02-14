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
struct TYPE_10__ {int mode; int saved_r0; int saved_r2; int device; int /*<<< orphan*/  delay; int /*<<< orphan*/  port; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 char* EPIA_VERSION ; 
 int RR (int) ; 
 int /*<<< orphan*/  WR (int,int) ; 
 scalar_t__* cont_map ; 
 int j44 (int,int) ; 
 int j53 (int,int) ; 
 int /*<<< orphan*/  printk (char*,int,char*,int,...) ; 
 void* r0 () ; 
 int r1 () ; 
 void* r2 () ; 
 void* r4 () ; 
 int /*<<< orphan*/  r4l () ; 
 int /*<<< orphan*/  r4w () ; 
 int /*<<< orphan*/  w0 (int) ; 
 int /*<<< orphan*/  w2 (int) ; 
 int /*<<< orphan*/  w3 (int) ; 
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

__attribute__((used)) static int epia_read_regr( PIA *pi, int cont, int regr )

{       int     a, b, r;

	regr += cont_map[cont];

        switch (pi->mode)  {

        case 0: r = regr^0x39;
                w0(r); w2(1); w2(3); w0(r);
                a = r1(); w2(1); b = r1(); w2(4);
                return j44(a,b);

        case 1: r = regr^0x31;
                w0(r); w2(1); w0(r&0x37); 
                w2(3); w2(5); w0(r|0xf0);
                a = r1(); b = r2(); w2(4);
                return j53(a,b);

        case 2: r = regr^0x29;
                w0(r); w2(1); w2(0X21); w2(0x23); 
                a = r0(); w2(4);
                return a;

	case 3:
	case 4:
        case 5: w3(regr); w2(0x24); a = r4(); w2(4);
                return a;

        }
        return -1;
}

__attribute__((used)) static void epia_write_regr( PIA *pi, int cont, int regr, int val)

{       int  r;

	regr += cont_map[cont];

        switch (pi->mode)  {

        case 0:
        case 1:
        case 2: r = regr^0x19;
                w0(r); w2(1); w0(val); w2(3); w2(4);
                break;

	case 3:
	case 4:
        case 5: r = regr^0x40;
                w3(r); w4(val); w2(4);
                break;
        }
}

__attribute__((used)) static void epia_connect ( PIA *pi  )

{       pi->saved_r0 = r0();
        pi->saved_r2 = r2();

        w2(4); w0(0xa0); w0(0x50); w0(0xc0); w0(0x30); w0(0xa0); w0(0);
        w2(1); w2(4);
        if (pi->mode >= 3) { 
                w0(0xa); w2(1); w2(4); w0(0x82); w2(4); w2(0xc); w2(4);
                w2(0x24); w2(0x26); w2(4);
        }
        WR(0x86,8);  
}

__attribute__((used)) static void epia_disconnect ( PIA *pi )

{       /* WR(0x84,0x10); */
        w0(pi->saved_r0);
        w2(1); w2(4);
        w0(pi->saved_r0);
        w2(pi->saved_r2);
}

__attribute__((used)) static void epia_read_block( PIA *pi, char * buf, int count )

{       int     k, ph, a, b;

        switch (pi->mode) {

        case 0: w0(0x81); w2(1); w2(3); w0(0xc1);
                ph = 1;
                for (k=0;k<count;k++) {
                        w2(2+ph); a = r1();
                        w2(4+ph); b = r1();
                        buf[k] = j44(a,b);
                        ph = 1 - ph;
                } 
                w0(0); w2(4);
                break;

        case 1: w0(0x91); w2(1); w0(0x10); w2(3); 
                w0(0x51); w2(5); w0(0xd1); 
                ph = 1;
                for (k=0;k<count;k++) {
                        w2(4+ph);
                        a = r1(); b = r2();
                        buf[k] = j53(a,b);
                        ph = 1 - ph;
                }
                w0(0); w2(4);
                break;

        case 2: w0(0x89); w2(1); w2(0x23); w2(0x21); 
                ph = 1;
                for (k=0;k<count;k++) {
                        w2(0x24+ph);
                        buf[k] = r0();
                        ph = 1 - ph;
                }
                w2(6); w2(4);
                break;

        case 3: if (count > 512) WR(0x84,3);
		w3(0); w2(0x24);
                for (k=0;k<count;k++) buf[k] = r4();
                w2(4); WR(0x84,0);
                break;

        case 4: if (count > 512) WR(0x84,3);
		w3(0); w2(0x24);
		for (k=0;k<count/2;k++) ((u16 *)buf)[k] = r4w();
                w2(4); WR(0x84,0);
                break;

        case 5: if (count > 512) WR(0x84,3);
		w3(0); w2(0x24);
                for (k=0;k<count/4;k++) ((u32 *)buf)[k] = r4l();
                w2(4); WR(0x84,0);
                break;

        }
}

__attribute__((used)) static void epia_write_block( PIA *pi, char * buf, int count )

{       int     ph, k, last, d;

        switch (pi->mode) {

        case 0:
        case 1:
        case 2: w0(0xa1); w2(1); w2(3); w2(1); w2(5);
                ph = 0;  last = 0x8000;
                for (k=0;k<count;k++) {
                        d = buf[k];
                        if (d != last) { last = d; w0(d); }
                        w2(4+ph);
                        ph = 1 - ph;
                }
                w2(7); w2(4);
                break;

        case 3: if (count < 512) WR(0x84,1);
		w3(0x40);
                for (k=0;k<count;k++) w4(buf[k]);
		if (count < 512) WR(0x84,0);
                break;

        case 4: if (count < 512) WR(0x84,1);
		w3(0x40);
                for (k=0;k<count/2;k++) w4w(((u16 *)buf)[k]);
		if (count < 512) WR(0x84,0);
                break;

        case 5: if (count < 512) WR(0x84,1);
		w3(0x40);
                for (k=0;k<count/4;k++) w4l(((u32 *)buf)[k]);
		if (count < 512) WR(0x84,0);
                break;

        }

}

__attribute__((used)) static int epia_test_proto( PIA *pi, char * scratch, int verbose )

{       int     j, k, f;
	int	e[2] = {0,0};

        epia_connect(pi);
        for (j=0;j<2;j++) {
            WR(6,0xa0+j*0x10);
            for (k=0;k<256;k++) {
                WR(2,k^0xaa);
                WR(3,k^0x55);
                if (RR(2) != (k^0xaa)) e[j]++;
                }
	    WR(2,1); WR(3,1);
            }
        epia_disconnect(pi);

        f = 0;
        epia_connect(pi);
        WR(0x84,8);
        epia_read_block(pi,scratch,512);
        for (k=0;k<256;k++) {
            if ((scratch[2*k] & 0xff) != ((k+1) & 0xff)) f++;
            if ((scratch[2*k+1] & 0xff) != ((-2-k) & 0xff)) f++;
        }
        WR(0x84,0);
        epia_disconnect(pi);

        if (verbose)  {
            printk("%s: epia: port 0x%x, mode %d, test=(%d,%d,%d)\n",
                   pi->device,pi->port,pi->mode,e[0],e[1],f);
        }
        
        return (e[0] && e[1]) || f;

}

__attribute__((used)) static void epia_log_adapter( PIA *pi, char * scratch, int verbose )

{       char    *mode_string[6] = {"4-bit","5/3","8-bit",
				   "EPP-8","EPP-16","EPP-32"};

        printk("%s: epia %s, Shuttle EPIA at 0x%x, ",
                pi->device,EPIA_VERSION,pi->port);
        printk("mode %d (%s), delay %d\n",pi->mode,
		mode_string[pi->mode],pi->delay);

}

