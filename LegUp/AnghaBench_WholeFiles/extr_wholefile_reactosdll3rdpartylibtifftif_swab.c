#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  size_t uint8 ;
typedef  int /*<<< orphan*/  uint64 ;
typedef  int /*<<< orphan*/  uint32 ;
typedef  int /*<<< orphan*/  uint16 ;
typedef  int tmsize_t ;

/* Variables and functions */
 unsigned char const* TIFFBitRevTable ; 
 unsigned char const* TIFFNoBitRevTable ; 
 int /*<<< orphan*/  assert (int) ; 

void
TIFFSwabShort(uint16* wp)
{
	register unsigned char* cp = (unsigned char*) wp;
	unsigned char t;
	assert(sizeof(uint16)==2);
	t = cp[1]; cp[1] = cp[0]; cp[0] = t;
}

void
TIFFSwabLong(uint32* lp)
{
	register unsigned char* cp = (unsigned char*) lp;
	unsigned char t;
	assert(sizeof(uint32)==4);
	t = cp[3]; cp[3] = cp[0]; cp[0] = t;
	t = cp[2]; cp[2] = cp[1]; cp[1] = t;
}

void
TIFFSwabLong8(uint64* lp)
{
	register unsigned char* cp = (unsigned char*) lp;
	unsigned char t;
	assert(sizeof(uint64)==8);
	t = cp[7]; cp[7] = cp[0]; cp[0] = t;
	t = cp[6]; cp[6] = cp[1]; cp[1] = t;
	t = cp[5]; cp[5] = cp[2]; cp[2] = t;
	t = cp[4]; cp[4] = cp[3]; cp[3] = t;
}

void
TIFFSwabArrayOfShort(register uint16* wp, tmsize_t n)
{
	register unsigned char* cp;
	register unsigned char t;
	assert(sizeof(uint16)==2);
	/* XXX unroll loop some */
	while (n-- > 0) {
		cp = (unsigned char*) wp;
		t = cp[1]; cp[1] = cp[0]; cp[0] = t;
		wp++;
	}
}

void
TIFFSwabArrayOfTriples(register uint8* tp, tmsize_t n)
{
	unsigned char* cp;
	unsigned char t;

	/* XXX unroll loop some */
	while (n-- > 0) {
		cp = (unsigned char*) tp;
		t = cp[2]; cp[2] = cp[0]; cp[0] = t;
		tp += 3;
	}
}

void
TIFFSwabArrayOfLong(register uint32* lp, tmsize_t n)
{
	register unsigned char *cp;
	register unsigned char t;
	assert(sizeof(uint32)==4);
	/* XXX unroll loop some */
	while (n-- > 0) {
		cp = (unsigned char *)lp;
		t = cp[3]; cp[3] = cp[0]; cp[0] = t;
		t = cp[2]; cp[2] = cp[1]; cp[1] = t;
		lp++;
	}
}

void
TIFFSwabArrayOfLong8(register uint64* lp, tmsize_t n)
{
	register unsigned char *cp;
	register unsigned char t;
	assert(sizeof(uint64)==8);
	/* XXX unroll loop some */
	while (n-- > 0) {
		cp = (unsigned char *)lp;
		t = cp[7]; cp[7] = cp[0]; cp[0] = t;
		t = cp[6]; cp[6] = cp[1]; cp[1] = t;
		t = cp[5]; cp[5] = cp[2]; cp[2] = t;
		t = cp[4]; cp[4] = cp[3]; cp[3] = t;
		lp++;
	}
}

void
TIFFSwabFloat(float* fp)
{
	register unsigned char* cp = (unsigned char*) fp;
	unsigned char t;
	assert(sizeof(float)==4);
	t = cp[3]; cp[3] = cp[0]; cp[0] = t;
	t = cp[2]; cp[2] = cp[1]; cp[1] = t;
}

void
TIFFSwabArrayOfFloat(register float* fp, tmsize_t n)
{
	register unsigned char *cp;
	register unsigned char t;
	assert(sizeof(float)==4);
	/* XXX unroll loop some */
	while (n-- > 0) {
		cp = (unsigned char *)fp;
		t = cp[3]; cp[3] = cp[0]; cp[0] = t;
		t = cp[2]; cp[2] = cp[1]; cp[1] = t;
		fp++;
	}
}

void
TIFFSwabDouble(double *dp)
{
	register unsigned char* cp = (unsigned char*) dp;
	unsigned char t;
	assert(sizeof(double)==8);
	t = cp[7]; cp[7] = cp[0]; cp[0] = t;
	t = cp[6]; cp[6] = cp[1]; cp[1] = t;
	t = cp[5]; cp[5] = cp[2]; cp[2] = t;
	t = cp[4]; cp[4] = cp[3]; cp[3] = t;
}

void
TIFFSwabArrayOfDouble(double* dp, tmsize_t n)
{
	register unsigned char *cp;
	register unsigned char t;
	assert(sizeof(double)==8);
	/* XXX unroll loop some */
	while (n-- > 0) {
		cp = (unsigned char *)dp;
		t = cp[7]; cp[7] = cp[0]; cp[0] = t;
		t = cp[6]; cp[6] = cp[1]; cp[1] = t;
		t = cp[5]; cp[5] = cp[2]; cp[2] = t;
		t = cp[4]; cp[4] = cp[3]; cp[3] = t;
		dp++;
	}
}

const unsigned char*
TIFFGetBitRevTable(int reversed)
{
	return (reversed ? TIFFBitRevTable : TIFFNoBitRevTable);
}

void
TIFFReverseBits(uint8* cp, tmsize_t n)  
{
	for (; n > 8; n -= 8) {
		cp[0] = TIFFBitRevTable[cp[0]];
		cp[1] = TIFFBitRevTable[cp[1]];
		cp[2] = TIFFBitRevTable[cp[2]];
		cp[3] = TIFFBitRevTable[cp[3]];
		cp[4] = TIFFBitRevTable[cp[4]];
		cp[5] = TIFFBitRevTable[cp[5]];
		cp[6] = TIFFBitRevTable[cp[6]];
		cp[7] = TIFFBitRevTable[cp[7]];
		cp += 8;
	}
	while (n-- > 0) {
		*cp = TIFFBitRevTable[*cp];
		cp++;
	}
}

