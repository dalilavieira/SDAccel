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
 char* ON20_VERSION ; 
 int j44 (int,int) ; 
 int /*<<< orphan*/  op (int) ; 
 int /*<<< orphan*/  printk (char*,int,char*,int /*<<< orphan*/ ) ; 
 void* r0 () ; 
 int r1 () ; 
 int r2 () ; 
 int /*<<< orphan*/  vl (int) ; 
 int /*<<< orphan*/  w0 (char) ; 
 int /*<<< orphan*/  w2 (int) ; 

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

__attribute__((used)) static int on20_read_regr( PIA *pi, int cont, int regr )

{	int h,l, r ;

        r = (regr<<2) + 1 + cont;

        op(1); vl(r); op(0);

	switch (pi->mode)  {

        case 0:  w2(4); w2(6); l = r1();
                 w2(4); w2(6); h = r1();
                 w2(4); w2(6); w2(4); w2(6); w2(4);
		 return j44(l,h);

	case 1:  w2(4); w2(0x26); r = r0(); 
                 w2(4); w2(0x26); w2(4);
		 return r;

	}
	return -1;
}

__attribute__((used)) static void on20_write_regr( PIA *pi, int cont, int regr, int val )

{	int r;

	r = (regr<<2) + 1 + cont;

	op(1); vl(r); 
	op(0); vl(val); 
	op(0); vl(val);
}

__attribute__((used)) static void on20_connect ( PIA *pi)

{	pi->saved_r0 = r0();
        pi->saved_r2 = r2();

	w2(4);w0(0);w2(0xc);w2(4);w2(6);w2(4);w2(6);w2(4); 
	if (pi->mode) { op(2); vl(8); op(2); vl(9); }
	       else   { op(2); vl(0); op(2); vl(8); }
}

__attribute__((used)) static void on20_disconnect ( PIA *pi )

{	w2(4);w0(7);w2(4);w2(0xc);w2(4);
        w0(pi->saved_r0);
        w2(pi->saved_r2);
}

__attribute__((used)) static void on20_read_block( PIA *pi, char * buf, int count )

{	int     k, l, h; 

	op(1); vl(1); op(0);

	for (k=0;k<count;k++) 
	    if (pi->mode) {
		w2(4); w2(0x26); buf[k] = r0();
	    } else {
		w2(6); l = r1(); w2(4);
		w2(6); h = r1(); w2(4);
		buf[k] = j44(l,h);
	    }
	w2(4);
}

__attribute__((used)) static void on20_write_block(  PIA *pi, char * buf, int count )

{	int	k;

	op(1); vl(1); op(0);

	for (k=0;k<count;k++) { w2(5); w0(buf[k]); w2(7); }
	w2(4);
}

__attribute__((used)) static void on20_log_adapter( PIA *pi, char * scratch, int verbose )

{       char    *mode_string[2] = {"4-bit","8-bit"};

        printk("%s: on20 %s, OnSpec 90c20 at 0x%x, ",
                pi->device,ON20_VERSION,pi->port);
        printk("mode %d (%s), delay %d\n",pi->mode,
		mode_string[pi->mode],pi->delay);

}

