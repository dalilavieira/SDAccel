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
union ieee754dp {int sign; int bexp; int mant; } ;
typedef  int u64 ;
typedef  int /*<<< orphan*/  s64 ;
struct TYPE_2__ {unsigned int rm; unsigned int cx; unsigned int sx; unsigned int const mx; scalar_t__ nan2008; } ;

/* Variables and functions */
 int DPBEXP (union ieee754dp) ; 
 int DP_EBIAS ; 
 int DP_EMAX ; 
 int DP_EMIN ; 
 int DP_FBITS ; 
 int DP_HIDDEN_BIT ; 
 int IEEE754_CLASS_SNAN ; 
 int INT_MAX ; 
 int INT_MIN ; 
 int /*<<< orphan*/  S64_MAX ; 
 int /*<<< orphan*/  S64_MIN ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_1__ ieee754_csr ; 
 union ieee754dp ieee754dp_one (int) ; 
 union ieee754dp ieee754dp_ten (int) ; 
 union ieee754dp ieee754dp_zero (int /*<<< orphan*/ ) ; 

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

union ieee754dp ieee754dp_fint(int x)
{
	u64 xm;
	int xe;
	int xs;

	ieee754_clearcx();

	if (x == 0)
		return ieee754dp_zero(0);
	if (x == 1 || x == -1)
		return ieee754dp_one(x < 0);
	if (x == 10 || x == -10)
		return ieee754dp_ten(x < 0);

	xs = (x < 0);
	if (xs) {
		if (x == (1 << 31))
			xm = ((unsigned) 1 << 31);	/* max neg can't be safely negated */
		else
			xm = -x;
	} else {
		xm = x;
	}

	/* normalize - result can never be inexact or overflow */
	xe = DP_FBITS;
	while ((xm >> DP_FBITS) == 0) {
		xm <<= 1;
		xe--;
	}
	return builddp(xs, xe + DP_EBIAS, xm & ~DP_HIDDEN_BIT);
}

