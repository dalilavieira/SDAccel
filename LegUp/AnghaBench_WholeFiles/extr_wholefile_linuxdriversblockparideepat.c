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
struct TYPE_10__ {int mode; int saved_r0; int saved_r2; int /*<<< orphan*/  delay; int /*<<< orphan*/  port; int /*<<< orphan*/  device; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  CPP (int) ; 
 int /*<<< orphan*/  EPAT_VERSION ; 
 int RR (int) ; 
 int RRi (int) ; 
 int /*<<< orphan*/  WR (int,int) ; 
 int /*<<< orphan*/  WRi (int,int) ; 
 int* cont_map ; 
 scalar_t__ epatc8 ; 
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

__attribute__((used)) static void epat_write_regr( PIA *pi, int cont, int regr, int val)

{	int r;

	r = regr + cont_map[cont];

	switch (pi->mode) {

	case 0:
	case 1:
	case 2:	w0(0x60+r); w2(1); w0(val); w2(4);
		break;

	case 3:
	case 4:
	case 5: w3(0x40+r); w4(val);
		break;

	}
}

__attribute__((used)) static int epat_read_regr( PIA *pi, int cont, int regr )

{	int  a, b, r;

	r = regr + cont_map[cont];

	switch (pi->mode) {

	case 0:	w0(r); w2(1); w2(3); 
		a = r1(); w2(4); b = r1();
		return j44(a,b);

	case 1: w0(0x40+r); w2(1); w2(4);
		a = r1(); b = r2(); w0(0xff);
		return j53(a,b);

	case 2: w0(0x20+r); w2(1); w2(0x25);
		a = r0(); w2(4);
		return a;

	case 3:
	case 4:
	case 5: w3(r); w2(0x24); a = r4(); w2(4);
		return a;

	}
	return -1;	/* never gets here */
}

__attribute__((used)) static void epat_read_block( PIA *pi, char * buf, int count )

{	int  k, ph, a, b;

	switch (pi->mode) {

	case 0:	w0(7); w2(1); w2(3); w0(0xff);
		ph = 0;
		for(k=0;k<count;k++) {
			if (k == count-1) w0(0xfd);
			w2(6+ph); a = r1();
			if (a & 8) b = a; 
			  else { w2(4+ph); b = r1(); }
			buf[k] = j44(a,b);
			ph =  1 - ph;
		}
		w0(0); w2(4);
		break;

	case 1: w0(0x47); w2(1); w2(5); w0(0xff);
		ph = 0;
		for(k=0;k<count;k++) {
			if (k == count-1) w0(0xfd); 
			w2(4+ph);
			a = r1(); b = r2();
			buf[k] = j53(a,b);
			ph = 1 - ph;
		}
		w0(0); w2(4);
		break;

	case 2: w0(0x27); w2(1); w2(0x25); w0(0);
		ph = 0;
		for(k=0;k<count-1;k++) {
			w2(0x24+ph);
			buf[k] = r0();
			ph = 1 - ph;
		}
		w2(0x26); w2(0x27); buf[count-1] = r0(); 
		w2(0x25); w2(4);
		break;

	case 3: w3(0x80); w2(0x24);
		for(k=0;k<count-1;k++) buf[k] = r4();
		w2(4); w3(0xa0); w2(0x24); buf[count-1] = r4();
		w2(4);
		break;

	case 4: w3(0x80); w2(0x24);
		for(k=0;k<(count/2)-1;k++) ((u16 *)buf)[k] = r4w();
		buf[count-2] = r4();
		w2(4); w3(0xa0); w2(0x24); buf[count-1] = r4();
		w2(4);
		break;

	case 5: w3(0x80); w2(0x24);
		for(k=0;k<(count/4)-1;k++) ((u32 *)buf)[k] = r4l();
		for(k=count-4;k<count-1;k++) buf[k] = r4();
		w2(4); w3(0xa0); w2(0x24); buf[count-1] = r4();
		w2(4);
		break;

	}
}

__attribute__((used)) static void epat_write_block( PIA *pi, char * buf, int count )   

{	int ph, k;

	switch (pi->mode) {

	case 0:
	case 1:
	case 2: w0(0x67); w2(1); w2(5);
		ph = 0;
		for(k=0;k<count;k++) {
		  	w0(buf[k]);
			w2(4+ph);
			ph = 1 - ph;
		}
		w2(7); w2(4);
		break;

	case 3: w3(0xc0); 
		for(k=0;k<count;k++) w4(buf[k]);
		w2(4);
		break;

	case 4: w3(0xc0); 
		for(k=0;k<(count/2);k++) w4w(((u16 *)buf)[k]);
		w2(4);
		break;

	case 5: w3(0xc0); 
		for(k=0;k<(count/4);k++) w4l(((u32 *)buf)[k]);
		w2(4);
		break;

	}
}

__attribute__((used)) static void epat_connect ( PIA *pi )

{       pi->saved_r0 = r0();
        pi->saved_r2 = r2();

 	/* Initialize the chip */
	CPP(0);

	if (epatc8) {
		CPP(0x40);CPP(0xe0);
		w0(0);w2(1);w2(4);
		WR(0x8,0x12);WR(0xc,0x14);WR(0x12,0x10);
		WR(0xe,0xf);WR(0xf,4);
		/* WR(0xe,0xa);WR(0xf,4); */
		WR(0xe,0xd);WR(0xf,0);
		/* CPP(0x30); */
	}

        /* Connect to the chip */
	CPP(0xe0);
        w0(0);w2(1);w2(4); /* Idle into SPP */
        if (pi->mode >= 3) {
          w0(0);w2(1);w2(4);w2(0xc);
          /* Request EPP */
          w0(0x40);w2(6);w2(7);w2(4);w2(0xc);w2(4);
        }

	if (!epatc8) {
		WR(8,0x10); WR(0xc,0x14); WR(0xa,0x38); WR(0x12,0x10);
	}
}

__attribute__((used)) static void epat_disconnect (PIA *pi)
{	CPP(0x30);
	w0(pi->saved_r0);
	w2(pi->saved_r2);
}

__attribute__((used)) static int epat_test_proto( PIA *pi, char * scratch, int verbose )

{       int     k, j, f, cc;
	int	e[2] = {0,0};

        epat_connect(pi);
	cc = RR(0xd);
	epat_disconnect(pi);

	epat_connect(pi);
	for (j=0;j<2;j++) {
  	    WRi(6,0xa0+j*0x10);
            for (k=0;k<256;k++) {
                WRi(2,k^0xaa);
                WRi(3,k^0x55);
                if (RRi(2) != (k^0xaa)) e[j]++;
                }
	    }
        epat_disconnect(pi);

        f = 0;
        epat_connect(pi);
        WR(0x13,1); WR(0x13,0); WR(0xa,0x11);
        epat_read_block(pi,scratch,512);
	
        for (k=0;k<256;k++) {
            if ((scratch[2*k] & 0xff) != k) f++;
            if ((scratch[2*k+1] & 0xff) != (0xff-k)) f++;
        }
        epat_disconnect(pi);

        if (verbose)  {
            printk("%s: epat: port 0x%x, mode %d, ccr %x, test=(%d,%d,%d)\n",
		   pi->device,pi->port,pi->mode,cc,e[0],e[1],f);
	}
	
        return (e[0] && e[1]) || f;
}

__attribute__((used)) static void epat_log_adapter( PIA *pi, char * scratch, int verbose )

{	int	ver;
        char    *mode_string[6] = 
		   {"4-bit","5/3","8-bit","EPP-8","EPP-16","EPP-32"};

	epat_connect(pi);
	WR(0xa,0x38);		/* read the version code */
        ver = RR(0xb);
        epat_disconnect(pi);

	printk("%s: epat %s, Shuttle EPAT chip %x at 0x%x, ",
		pi->device,EPAT_VERSION,ver,pi->port);
	printk("mode %d (%s), delay %d\n",pi->mode,
		mode_string[pi->mode],pi->delay);

}

