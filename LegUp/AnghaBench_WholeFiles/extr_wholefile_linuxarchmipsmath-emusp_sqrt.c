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
union ieee754sp {int sign; int bexp; unsigned int mant; int bits; } ;
typedef  int /*<<< orphan*/  s64 ;
struct TYPE_2__ {unsigned int rm; unsigned int cx; unsigned int sx; unsigned int const mx; scalar_t__ nan2008; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMPXSP ; 
 int /*<<< orphan*/  EXPLODEXSP ; 
 int /*<<< orphan*/  FLUSHXSP ; 
#define  FPU_CSR_RN 135 
#define  FPU_CSR_RU 134 
#define  IEEE754_CLASS_DNORM 133 
#define  IEEE754_CLASS_INF 132 
#define  IEEE754_CLASS_NORM 131 
#define  IEEE754_CLASS_QNAN 130 
#define  IEEE754_CLASS_SNAN 129 
#define  IEEE754_CLASS_ZERO 128 
 unsigned int IEEE754_INEXACT ; 
 unsigned int IEEE754_INVALID_OPERATION ; 
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
 union ieee754sp ieee754sp_indef () ; 
 union ieee754sp ieee754sp_nanxcpt (union ieee754sp) ; 
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

union ieee754sp ieee754sp_sqrt(union ieee754sp x)
{
	int ix, s, q, m, t, i;
	unsigned int r;
	COMPXSP;

	/* take care of Inf and NaN */

	EXPLODEXSP;
	ieee754_clearcx();
	FLUSHXSP;

	/* x == INF or NAN? */
	switch (xc) {
	case IEEE754_CLASS_SNAN:
		return ieee754sp_nanxcpt(x);

	case IEEE754_CLASS_QNAN:
		/* sqrt(Nan) = Nan */
		return x;

	case IEEE754_CLASS_ZERO:
		/* sqrt(0) = 0 */
		return x;

	case IEEE754_CLASS_INF:
		if (xs) {
			/* sqrt(-Inf) = Nan */
			ieee754_setcx(IEEE754_INVALID_OPERATION);
			return ieee754sp_indef();
		}
		/* sqrt(+Inf) = Inf */
		return x;

	case IEEE754_CLASS_DNORM:
	case IEEE754_CLASS_NORM:
		if (xs) {
			/* sqrt(-x) = Nan */
			ieee754_setcx(IEEE754_INVALID_OPERATION);
			return ieee754sp_indef();
		}
		break;
	}

	ix = x.bits;

	/* normalize x */
	m = (ix >> 23);
	if (m == 0) {		/* subnormal x */
		for (i = 0; (ix & 0x00800000) == 0; i++)
			ix <<= 1;
		m -= i - 1;
	}
	m -= 127;		/* unbias exponent */
	ix = (ix & 0x007fffff) | 0x00800000;
	if (m & 1)		/* odd m, double x to make it even */
		ix += ix;
	m >>= 1;		/* m = [m/2] */

	/* generate sqrt(x) bit by bit */
	ix += ix;
	s = 0;
	q = 0;			/* q = sqrt(x) */
	r = 0x01000000;		/* r = moving bit from right to left */

	while (r != 0) {
		t = s + r;
		if (t <= ix) {
			s = t + r;
			ix -= t;
			q += r;
		}
		ix += ix;
		r >>= 1;
	}

	if (ix != 0) {
		ieee754_setcx(IEEE754_INEXACT);
		switch (ieee754_csr.rm) {
		case FPU_CSR_RU:
			q += 2;
			break;
		case FPU_CSR_RN:
			q += (q & 1);
			break;
		}
	}
	ix = (q >> 1) + 0x3f000000;
	ix += (m << 23);
	x.bits = ix;
	return x;
}

