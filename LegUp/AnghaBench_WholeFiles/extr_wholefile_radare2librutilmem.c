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
typedef  int ut8 ;

/* Variables and functions */
 int /*<<< orphan*/  R_BIT_SET (int*,int) ; 
 int /*<<< orphan*/  R_BIT_UNSET (int*,int) ; 

__attribute__((used)) static char readbit(const ut8 *src, int bitoffset) {
	const int wholeBytes = bitoffset / 8;
	const int remainingBits = bitoffset % 8;
	// return (src[wholeBytes] >> remainingBits) & 1;
	return (src[wholeBytes] & 1<< remainingBits);
}

__attribute__((used)) static void writebit (ut8 *dst, int i, bool c) {
	int byte = i / 8;
	int bit = (i % 8);
// eprintf ("Write %d %d = %d\n", byte, bit, c);
dst += byte;
	if (c) {
		//dst[byte] |= (1 << bit);
		R_BIT_SET (dst , bit);
	} else {
		//dst[byte] &= (1 << bit);
		R_BIT_UNSET (dst , bit);
	}
}

