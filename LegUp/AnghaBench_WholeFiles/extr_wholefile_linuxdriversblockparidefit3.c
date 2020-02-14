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
struct TYPE_9__ {int mode; int saved_r0; int saved_r2; int /*<<< orphan*/  delay; int /*<<< orphan*/  port; int /*<<< orphan*/  device; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  FIT3_VERSION ; 
 int j44 (int,int) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,int /*<<< orphan*/ ) ; 
 void* r0 () ; 
 int r1 () ; 
 int r2 () ; 
 void* r4 () ; 
 int /*<<< orphan*/  w0 (int) ; 
 int /*<<< orphan*/  w2 (int) ; 
 int /*<<< orphan*/  w4 (char) ; 

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

__attribute__((used)) static void  fit3_write_regr( PIA *pi, int cont, int regr, int val)

{	if (cont == 1) return;

	switch (pi->mode) {

	case 0:
	case 1: w2(0xc); w0(regr); w2(0x8); w2(0xc); 
		w0(val); w2(0xd); 
		w0(0);   w2(0xc);
		break;

	case 2: w2(0xc); w0(regr); w2(0x8); w2(0xc);
		w4(val); w4(0);
		w2(0xc);
		break;

	}
}

__attribute__((used)) static int fit3_read_regr( PIA *pi, int cont, int regr )

{	int  a, b;

	if (cont) {
	  if (regr != 6) return 0xff;
	  regr = 7;
	} 

	switch (pi->mode) {

	case 0: w2(0xc); w0(regr + 0x10); w2(0x8); w2(0xc);
		w2(0xd); a = r1();
		w2(0xf); b = r1(); 
		w2(0xc);
		return j44(a,b);

	case 1: w2(0xc); w0(regr + 0x90); w2(0x8); w2(0xc);
		w2(0xec); w2(0xee); w2(0xef); a = r0(); 
		w2(0xc);
		return a;

	case 2: w2(0xc); w0(regr + 0x90); w2(0x8); w2(0xc); 
		w2(0xec); 
		a = r4(); b = r4(); 
		w2(0xc);
		return a;

	}
	return -1; 

}

__attribute__((used)) static void fit3_read_block( PIA *pi, char * buf, int count )

{	int  k, a, b, c, d;

	switch (pi->mode) {

	case 0: w2(0xc); w0(0x10); w2(0x8); w2(0xc);
		for (k=0;k<count/2;k++) {
		    w2(0xd); a = r1();
		    w2(0xf); b = r1();
		    w2(0xc); c = r1();
		    w2(0xe); d = r1();
		    buf[2*k  ] = j44(a,b);
		    buf[2*k+1] = j44(c,d);
		}
		w2(0xc);
		break;

	case 1: w2(0xc); w0(0x90); w2(0x8); w2(0xc); 
		w2(0xec); w2(0xee);
		for (k=0;k<count/2;k++) {
		    w2(0xef); a = r0();
		    w2(0xee); b = r0();
                    buf[2*k  ] = a;
                    buf[2*k+1] = b;
		}
		w2(0xec); 
		w2(0xc);
		break;

	case 2: w2(0xc); w0(0x90); w2(0x8); w2(0xc); 
                w2(0xec);
		for (k=0;k<count;k++) buf[k] = r4();
                w2(0xc);
		break;

	}
}

__attribute__((used)) static void fit3_write_block( PIA *pi, char * buf, int count )

{	int k;

        switch (pi->mode) {

	case 0:
        case 1: w2(0xc); w0(0); w2(0x8); w2(0xc);
                for (k=0;k<count/2;k++) {
 		    w0(buf[2*k  ]); w2(0xd);
 		    w0(buf[2*k+1]); w2(0xc);
		}
		break;

        case 2: w2(0xc); w0(0); w2(0x8); w2(0xc); 
                for (k=0;k<count;k++) w4(buf[k]);
                w2(0xc);
		break;
	}
}

__attribute__((used)) static void fit3_connect ( PIA *pi  )

{       pi->saved_r0 = r0();
        pi->saved_r2 = r2();
	w2(0xc); w0(0); w2(0xa);
	if (pi->mode == 2) { 
		w2(0xc); w0(0x9); w2(0x8); w2(0xc); 
		}
}

__attribute__((used)) static void fit3_disconnect ( PIA *pi )

{       w2(0xc); w0(0xa); w2(0x8); w2(0xc);
	w0(pi->saved_r0);
        w2(pi->saved_r2);
}

__attribute__((used)) static void fit3_log_adapter( PIA *pi, char * scratch, int verbose )

{       char    *mode_string[3] = {"4-bit","8-bit","EPP"};

	printk("%s: fit3 %s, FIT 3000 adapter at 0x%x, "
	       "mode %d (%s), delay %d\n",
                pi->device,FIT3_VERSION,pi->port,
		pi->mode,mode_string[pi->mode],pi->delay);

}

