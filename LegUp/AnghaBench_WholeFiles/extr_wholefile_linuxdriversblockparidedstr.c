#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_9__ {int mode; char saved_r0; int saved_r2; int device; int /*<<< orphan*/  delay; int /*<<< orphan*/  port; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  CCP (int) ; 
 char* DSTR_VERSION ; 
 int /*<<< orphan*/  P1 ; 
 int /*<<< orphan*/  P2 ; 
 int /*<<< orphan*/  P3 ; 
 int* cont_map ; 
 int j44 (int,int) ; 
 int /*<<< orphan*/  printk (char*,int,char*,int /*<<< orphan*/ ) ; 
 void* r0 () ; 
 int r1 () ; 
 int r2 () ; 
 void* r4 () ; 
 int /*<<< orphan*/  r4l () ; 
 int /*<<< orphan*/  r4w () ; 
 int /*<<< orphan*/  w0 (char) ; 
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

__attribute__((used)) static int dstr_read_regr( PIA *pi, int cont, int regr )

{       int     a, b, r;

        r = regr + cont_map[cont];

	w0(0x81); P1;
	if (pi->mode) { w0(0x11); } else { w0(1); }
	P2; w0(r); P1;

        switch (pi->mode)  {

        case 0: w2(6); a = r1(); w2(4); w2(6); b = r1(); w2(4);
                return j44(a,b);

        case 1: w0(0); w2(0x26); a = r0(); w2(4);
                return a;

	case 2:
	case 3:
        case 4: w2(0x24); a = r4(); w2(4);
                return a;

        }
        return -1;
}

__attribute__((used)) static void dstr_write_regr(  PIA *pi, int cont, int regr, int val )

{       int  r;

        r = regr + cont_map[cont];

	w0(0x81); P1; 
	if (pi->mode >= 2) { w0(0x11); } else { w0(1); }
	P2; w0(r); P1;
	
        switch (pi->mode)  {

        case 0:
        case 1: w0(val); w2(5); w2(7); w2(5); w2(4);
		break;

	case 2:
	case 3:
        case 4: w4(val); 
                break;
        }
}

__attribute__((used)) static void dstr_connect ( PIA *pi  )

{       pi->saved_r0 = r0();
        pi->saved_r2 = r2();
        w2(4); CCP(0xe0); w0(0xff);
}

__attribute__((used)) static void dstr_disconnect ( PIA *pi )

{       CCP(0x30);
        w0(pi->saved_r0);
        w2(pi->saved_r2);
}

__attribute__((used)) static void dstr_read_block( PIA *pi, char * buf, int count )

{       int     k, a, b;

        w0(0x81); P1;
        if (pi->mode) { w0(0x19); } else { w0(9); }
	P2; w0(0x82); P1; P3; w0(0x20); P1;

        switch (pi->mode) {

        case 0: for (k=0;k<count;k++) {
                        w2(6); a = r1(); w2(4);
                        w2(6); b = r1(); w2(4);
                        buf[k] = j44(a,b);
                } 
                break;

        case 1: w0(0);
                for (k=0;k<count;k++) {
                        w2(0x26); buf[k] = r0(); w2(0x24);
                }
                w2(4);
                break;

        case 2: w2(0x24); 
                for (k=0;k<count;k++) buf[k] = r4();
                w2(4);
                break;

        case 3: w2(0x24); 
                for (k=0;k<count/2;k++) ((u16 *)buf)[k] = r4w();
                w2(4);
                break;

        case 4: w2(0x24); 
                for (k=0;k<count/4;k++) ((u32 *)buf)[k] = r4l();
                w2(4);
                break;

        }
}

__attribute__((used)) static void dstr_write_block( PIA *pi, char * buf, int count )

{       int	k;

        w0(0x81); P1;
        if (pi->mode) { w0(0x19); } else { w0(9); }
        P2; w0(0x82); P1; P3; w0(0x20); P1;

        switch (pi->mode) {

        case 0:
        case 1: for (k=0;k<count;k++) {
                        w2(5); w0(buf[k]); w2(7);
                }
                w2(5); w2(4);
                break;

        case 2: w2(0xc5);
                for (k=0;k<count;k++) w4(buf[k]);
		w2(0xc4);
                break;

        case 3: w2(0xc5);
                for (k=0;k<count/2;k++) w4w(((u16 *)buf)[k]);
                w2(0xc4);
                break;

        case 4: w2(0xc5);
                for (k=0;k<count/4;k++) w4l(((u32 *)buf)[k]);
                w2(0xc4);
                break;

        }
}

__attribute__((used)) static void dstr_log_adapter( PIA *pi, char * scratch, int verbose )

{       char    *mode_string[5] = {"4-bit","8-bit","EPP-8",
				   "EPP-16","EPP-32"};

        printk("%s: dstr %s, DataStor EP2000 at 0x%x, ",
                pi->device,DSTR_VERSION,pi->port);
        printk("mode %d (%s), delay %d\n",pi->mode,
		mode_string[pi->mode],pi->delay);

}

