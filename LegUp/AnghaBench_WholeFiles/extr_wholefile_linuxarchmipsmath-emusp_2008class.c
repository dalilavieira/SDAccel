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
union ieee754sp {int sign; int bexp; unsigned int mant; } ;
typedef  int /*<<< orphan*/  s64 ;
struct TYPE_2__ {unsigned int rm; unsigned int cx; unsigned int sx; unsigned int const mx; scalar_t__ nan2008; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMPXSP ; 
 int /*<<< orphan*/  EXPLODEXSP ; 
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
 int SP_EBIAS ; 
 int SP_EMAX ; 
 int SP_EMIN ; 
 unsigned int SP_FBITS ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_1__ ieee754_csr ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int xc ; 
 int /*<<< orphan*/  xs ; 

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

int ieee754sp_2008class(union ieee754sp x)
{
	COMPXSP;

	EXPLODEXSP;

	/*
	 * 10 bit mask as follows:
	 *
	 * bit0 = SNAN
	 * bit1 = QNAN
	 * bit2 = -INF
	 * bit3 = -NORM
	 * bit4 = -DNORM
	 * bit5 = -ZERO
	 * bit6 = INF
	 * bit7 = NORM
	 * bit8 = DNORM
	 * bit9 = ZERO
	 */

	switch(xc) {
	case IEEE754_CLASS_SNAN:
		return 0x01;
	case IEEE754_CLASS_QNAN:
		return 0x02;
	case IEEE754_CLASS_INF:
		return 0x04 << (xs ? 0 : 4);
	case IEEE754_CLASS_NORM:
		return 0x08 << (xs ? 0 : 4);
	case IEEE754_CLASS_DNORM:
		return 0x10 << (xs ? 0 : 4);
	case IEEE754_CLASS_ZERO:
		return 0x20 << (xs ? 0 : 4);
	default:
		pr_err("Unknown class: %d\n", xc);
		return 0;
	}
}

