#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
union ieee754sp {int sign; int bexp; unsigned int mant; scalar_t__ bits; } ;
union ieee754dp {int sign; int bexp; int mant; int bits; } ;
typedef  int u64 ;
typedef  int /*<<< orphan*/  s64 ;
struct TYPE_2__ {unsigned int rm; unsigned int cx; unsigned int sx; unsigned int const mx; scalar_t__ nan2008; } ;

/* Variables and functions */
 int DPBEXP (union ieee754dp) ; 
 int DPMANT (union ieee754dp) ; 
 int /*<<< orphan*/  DPSIGN (union ieee754dp) ; 
 int DP_EBIAS ; 
 int DP_EMAX ; 
 int DP_EMIN ; 
 int DP_FBITS ; 
 int DP_MBIT (int) ; 
#define  IEEE754_CLASS_DNORM 133 
#define  IEEE754_CLASS_INF 132 
#define  IEEE754_CLASS_NORM 131 
#define  IEEE754_CLASS_QNAN 130 
#define  IEEE754_CLASS_SNAN 129 
#define  IEEE754_CLASS_ZERO 128 
 int INT_MAX ; 
 int INT_MIN ; 
 int /*<<< orphan*/  S64_MAX ; 
 int /*<<< orphan*/  S64_MIN ; 
 int SPBEXP (union ieee754sp) ; 
 int SPMANT (union ieee754sp) ; 
 int /*<<< orphan*/  SPSIGN (union ieee754sp) ; 
 int SP_EBIAS ; 
 int SP_EMAX ; 
 int SP_EMIN ; 
 unsigned int SP_FBITS ; 
 int SP_MBIT (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_1__ ieee754_csr ; 
 int ieee754dp_class (union ieee754dp) ; 
 int ieee754sp_class (union ieee754sp) ; 
 int /*<<< orphan*/  printk (char*,...) ; 

__attribute__((used)) static inline unsigned int ieee754_getrm(void)
{
	return (ieee754_csr.rm);
}

__attribute__((used)) static inline unsigned int ieee754_setrm(unsigned int rm)
{
	return (ieee754_csr.rm = rm);
}

__attribute__((used)) static inline unsigned int ieee754_getcx(void)
{
	return (ieee754_csr.cx);
}

__attribute__((used)) static inline int ieee754_cxtest(unsigned int n)
{
	return (ieee754_csr.cx & n);
}

__attribute__((used)) static inline unsigned int ieee754_getsx(void)
{
	return (ieee754_csr.sx);
}

__attribute__((used)) static inline unsigned int ieee754_clrsx(void)
{
	return (ieee754_csr.sx = 0);
}

__attribute__((used)) static inline int ieee754_sxtest(unsigned int n)
{
	return (ieee754_csr.sx & n);
}

__attribute__((used)) static inline int ieee754si_indef(void)
{
	return ieee754_csr.nan2008 ? 0 : INT_MAX;
}

__attribute__((used)) static inline s64 ieee754di_indef(void)
{
	return ieee754_csr.nan2008 ? 0 : S64_MAX;
}

__attribute__((used)) static inline int ieee754si_overflow(int xs)
{
	return ieee754_csr.nan2008 && xs ? INT_MIN : INT_MAX;
}

__attribute__((used)) static inline s64 ieee754di_overflow(int xs)
{
	return ieee754_csr.nan2008 && xs ? S64_MIN : S64_MAX;
}

__attribute__((used)) static inline void ieee754_clearcx(void)
{
	ieee754_csr.cx = 0;
}

__attribute__((used)) static inline void ieee754_setcx(const unsigned int flags)
{
	ieee754_csr.cx |= flags;
	ieee754_csr.sx |= flags;
}

__attribute__((used)) static inline int ieee754_setandtestcx(const unsigned int x)
{
	ieee754_setcx(x);

	return ieee754_csr.mx & x;
}

__attribute__((used)) static inline int ieee754_class_nan(int xc)
{
	return xc >= IEEE754_CLASS_SNAN;
}

__attribute__((used)) static inline int ieee754sp_finite(union ieee754sp x)
{
	return SPBEXP(x) != SP_EMAX + 1 + SP_EBIAS;
}

__attribute__((used)) static inline union ieee754sp buildsp(int s, int bx, unsigned int m)
{
	union ieee754sp r;

	assert((s) == 0 || (s) == 1);
	assert((bx) >= SP_EMIN - 1 + SP_EBIAS
	       && (bx) <= SP_EMAX + 1 + SP_EBIAS);
	assert(((m) >> SP_FBITS) == 0);

	r.sign = s;
	r.bexp = bx;
	r.mant = m;

	return r;
}

__attribute__((used)) static inline int ieee754dp_finite(union ieee754dp x)
{
	return DPBEXP(x) != DP_EMAX + 1 + DP_EBIAS;
}

__attribute__((used)) static inline union ieee754dp builddp(int s, int bx, u64 m)
{
	union ieee754dp r;

	assert((s) == 0 || (s) == 1);
	assert((bx) >= DP_EMIN - 1 + DP_EBIAS
	       && (bx) <= DP_EMAX + 1 + DP_EBIAS);
	assert(((m) >> DP_FBITS) == 0);

	r.sign = s;
	r.bexp = bx;
	r.mant = m;

	return r;
}

union ieee754dp ieee754dp_dump(char *m, union ieee754dp x)
{
	int i;

	printk("%s", m);
	printk("<%08x,%08x>\n", (unsigned) (x.bits >> 32),
	       (unsigned) x.bits);
	printk("\t=");
	switch (ieee754dp_class(x)) {
	case IEEE754_CLASS_QNAN:
	case IEEE754_CLASS_SNAN:
		printk("Nan %c", DPSIGN(x) ? '-' : '+');
		for (i = DP_FBITS - 1; i >= 0; i--)
			printk("%c", DPMANT(x) & DP_MBIT(i) ? '1' : '0');
		break;
	case IEEE754_CLASS_INF:
		printk("%cInfinity", DPSIGN(x) ? '-' : '+');
		break;
	case IEEE754_CLASS_ZERO:
		printk("%cZero", DPSIGN(x) ? '-' : '+');
		break;
	case IEEE754_CLASS_DNORM:
		printk("%c0.", DPSIGN(x) ? '-' : '+');
		for (i = DP_FBITS - 1; i >= 0; i--)
			printk("%c", DPMANT(x) & DP_MBIT(i) ? '1' : '0');
		printk("e%d", DPBEXP(x) - DP_EBIAS);
		break;
	case IEEE754_CLASS_NORM:
		printk("%c1.", DPSIGN(x) ? '-' : '+');
		for (i = DP_FBITS - 1; i >= 0; i--)
			printk("%c", DPMANT(x) & DP_MBIT(i) ? '1' : '0');
		printk("e%d", DPBEXP(x) - DP_EBIAS);
		break;
	default:
		printk("Illegal/Unknown IEEE754 value class");
	}
	printk("\n");
	return x;
}

union ieee754sp ieee754sp_dump(char *m, union ieee754sp x)
{
	int i;

	printk("%s=", m);
	printk("<%08x>\n", (unsigned) x.bits);
	printk("\t=");
	switch (ieee754sp_class(x)) {
	case IEEE754_CLASS_QNAN:
	case IEEE754_CLASS_SNAN:
		printk("Nan %c", SPSIGN(x) ? '-' : '+');
		for (i = SP_FBITS - 1; i >= 0; i--)
			printk("%c", SPMANT(x) & SP_MBIT(i) ? '1' : '0');
		break;
	case IEEE754_CLASS_INF:
		printk("%cInfinity", SPSIGN(x) ? '-' : '+');
		break;
	case IEEE754_CLASS_ZERO:
		printk("%cZero", SPSIGN(x) ? '-' : '+');
		break;
	case IEEE754_CLASS_DNORM:
		printk("%c0.", SPSIGN(x) ? '-' : '+');
		for (i = SP_FBITS - 1; i >= 0; i--)
			printk("%c", SPMANT(x) & SP_MBIT(i) ? '1' : '0');
		printk("e%d", SPBEXP(x) - SP_EBIAS);
		break;
	case IEEE754_CLASS_NORM:
		printk("%c1.", SPSIGN(x) ? '-' : '+');
		for (i = SP_FBITS - 1; i >= 0; i--)
			printk("%c", SPMANT(x) & SP_MBIT(i) ? '1' : '0');
		printk("e%d", SPBEXP(x) - SP_EBIAS);
		break;
	default:
		printk("Illegal/Unknown IEEE754 value class");
	}
	printk("\n");
	return x;
}

