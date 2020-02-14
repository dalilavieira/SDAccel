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
struct TYPE_2__ {unsigned int rm; unsigned int cx; unsigned int sx; int nan2008; unsigned int const mx; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMPXSP ; 
 int /*<<< orphan*/  EXPLODEXSP ; 
 int IEEE754_CLASS_SNAN ; 
 int INT_MAX ; 
 int INT_MIN ; 
 int /*<<< orphan*/  S64_MAX ; 
 int /*<<< orphan*/  S64_MIN ; 
 int SPBEXP (union ieee754sp) ; 
 int SPMANT (union ieee754sp) ; 
 int SP_EBIAS ; 
 int SP_EMAX ; 
 int SP_EMIN ; 
 unsigned int SP_FBITS ; 
 int SP_MBIT (unsigned int) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_1__ ieee754_csr ; 
 int xc ; 

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

int ieee754sp_class(union ieee754sp x)
{
	COMPXSP;
	EXPLODEXSP;
	return xc;
}

__attribute__((used)) static inline int ieee754sp_isnan(union ieee754sp x)
{
	return ieee754_class_nan(ieee754sp_class(x));
}

__attribute__((used)) static inline int ieee754sp_issnan(union ieee754sp x)
{
	int qbit;

	assert(ieee754sp_isnan(x));
	qbit = (SPMANT(x) & SP_MBIT(SP_FBITS - 1)) == SP_MBIT(SP_FBITS - 1);
	return ieee754_csr.nan2008 ^ qbit;
}

