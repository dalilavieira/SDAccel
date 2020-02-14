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
typedef  int /*<<< orphan*/  zend_object ;
typedef  int /*<<< orphan*/  x ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  php_hashcontext_object ;

/* Variables and functions */
 int F0 (int,int,int) ; 
 int F1 (int,int,int) ; 
 int F2 (int,int,int) ; 
 int F3 (int,int,int) ; 
 int F4 (int,int,int) ; 
 int K (int) ; 
 int KK (int) ; 
 int KK160 (int) ; 
 size_t* R ; 
 int ROL (int,int) ; 
 int ROLS (int,int) ; 
 int ROLSS (int,int) ; 
 size_t* RR ; 
 int /*<<< orphan*/  ZEND_SECURE_ZERO (int*,int) ; 

__attribute__((used)) static inline php_hashcontext_object *php_hashcontext_from_object(zend_object *obj) {
	return ((php_hashcontext_object*)(obj + 1)) - 1;
}

__attribute__((used)) static inline void php_hash_bin2hex(char *out, const unsigned char *in, size_t in_len)
{
	static const char hexits[17] = "0123456789abcdef";
	size_t i;

	for(i = 0; i < in_len; i++) {
		out[i * 2]       = hexits[in[i] >> 4];
		out[(i * 2) + 1] = hexits[in[i] &  0x0F];
	}
}

__attribute__((used)) static void RIPEMDDecode(uint32_t *output, const unsigned char *input, unsigned int len)
{
	unsigned int i, j;

	for (i = 0, j = 0; j < len; i++, j += 4)
		output[i] = ((uint32_t) input[j + 0]) | (((uint32_t) input[j + 1]) << 8) |
			(((uint32_t) input[j + 2]) << 16) | (((uint32_t) input[j + 3]) << 24);
}

__attribute__((used)) static void RIPEMD128Transform(uint32_t state[4], const unsigned char block[64])
{
	uint32_t a  = state[0], b  = state[1], c  = state[2], d  = state[3];
	uint32_t aa = state[0], bb = state[1], cc = state[2], dd = state[3];
	uint32_t tmp, x[16];
	int j;

	RIPEMDDecode(x, block, 64);

	for(j = 0; j < 16; j++) {
		tmp = ROLS( j, a  + F0(b,  c,  d)  + x[R[j]]  + K(j));
		a = d; d = c; c = b; b = tmp;
		tmp = ROLSS(j, aa + F3(bb, cc, dd) + x[RR[j]] + KK(j));
		aa = dd; dd = cc; cc = bb; bb = tmp;
	}

	for(j = 16; j < 32; j++) {
		tmp = ROLS( j, a  + F1(b,  c,  d)  + x[R[j]]  + K(j));
		a = d; d = c; c = b; b = tmp;
		tmp = ROLSS(j, aa + F2(bb, cc, dd) + x[RR[j]] + KK(j));
		aa = dd; dd = cc; cc = bb; bb = tmp;
	}

	for(j = 32; j < 48; j++) {
		tmp = ROLS( j, a  + F2(b,  c,  d)  + x[R[j]]  + K(j));
		a = d; d = c; c = b; b = tmp;
		tmp = ROLSS(j, aa + F1(bb, cc, dd) + x[RR[j]] + KK(j));
		aa = dd; dd = cc; cc = bb; bb = tmp;
	}

	for(j = 48; j < 64; j++) {
		tmp = ROLS( j, a  + F3(b,  c,  d)  + x[R[j]]  + K(j));
		a = d; d = c; c = b; b = tmp;
		tmp = ROLSS(j, aa + F0(bb, cc, dd) + x[RR[j]] + KK(j));
		aa = dd; dd = cc; cc = bb; bb = tmp;
	}

	tmp = state[1] + c + dd;
	state[1] = state[2] + d + aa;
	state[2] = state[3] + a + bb;
	state[3] = state[0] + b + cc;
	state[0] = tmp;

	tmp = 0;
	ZEND_SECURE_ZERO(x, sizeof(x));
}

__attribute__((used)) static void RIPEMD256Transform(uint32_t state[8], const unsigned char block[64])
{
	uint32_t a  = state[0], b  = state[1], c  = state[2], d  = state[3];
	uint32_t aa = state[4], bb = state[5], cc = state[6], dd = state[7];
	uint32_t tmp, x[16];
	int j;

	RIPEMDDecode(x, block, 64);

	for(j = 0; j < 16; j++) {
		tmp = ROLS( j, a  + F0(b,  c,  d)  + x[R[j]]  + K(j));
		a = d; d = c; c = b; b = tmp;
		tmp = ROLSS(j, aa + F3(bb, cc, dd) + x[RR[j]] + KK(j));
		aa = dd; dd = cc; cc = bb; bb = tmp;
	}
	tmp = a; a = aa; aa = tmp;

	for(j = 16; j < 32; j++) {
		tmp = ROLS( j, a  + F1(b,  c,  d)  + x[R[j]]  + K(j));
		a = d; d = c; c = b; b = tmp;
		tmp = ROLSS(j, aa + F2(bb, cc, dd) + x[RR[j]] + KK(j));
		aa = dd; dd = cc; cc = bb; bb = tmp;
	}
	tmp = b; b = bb; bb = tmp;

	for(j = 32; j < 48; j++) {
		tmp = ROLS( j, a  + F2(b,  c,  d)  + x[R[j]]  + K(j));
		a = d; d = c; c = b; b = tmp;
		tmp = ROLSS(j, aa + F1(bb, cc, dd) + x[RR[j]] + KK(j));
		aa = dd; dd = cc; cc = bb; bb = tmp;
	}
	tmp = c; c = cc; cc = tmp;

	for(j = 48; j < 64; j++) {
		tmp = ROLS( j, a  + F3(b,  c,  d)  + x[R[j]]  + K(j));
		a = d; d = c; c = b; b = tmp;
		tmp = ROLSS(j, aa + F0(bb, cc, dd) + x[RR[j]] + KK(j));
		aa = dd; dd = cc; cc = bb; bb = tmp;
	}
	tmp = d; d = dd; dd = tmp;

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += aa;
	state[5] += bb;
	state[6] += cc;
	state[7] += dd;

	tmp = 0;
	ZEND_SECURE_ZERO(x, sizeof(x));
}

__attribute__((used)) static void RIPEMD160Transform(uint32_t state[5], const unsigned char block[64])
{
	uint32_t a  = state[0], b  = state[1], c  = state[2], d  = state[3], e  = state[4];
	uint32_t aa = state[0], bb = state[1], cc = state[2], dd = state[3], ee = state[4];
	uint32_t tmp, x[16];
	int j;

	RIPEMDDecode(x, block, 64);

	for(j = 0; j < 16; j++) {
		tmp = ROLS( j, a  + F0(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F4(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}

	for(j = 16; j < 32; j++) {
		tmp = ROLS( j, a  + F1(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F3(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}

	for(j = 32; j < 48; j++) {
		tmp = ROLS( j, a  + F2(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F2(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}

	for(j = 48; j < 64; j++) {
		tmp = ROLS( j, a  + F3(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F1(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}

	for(j = 64; j < 80; j++) {
		tmp = ROLS( j, a  + F4(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F0(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}

	tmp = state[1] + c + dd;
	state[1] = state[2] + d + ee;
	state[2] = state[3] + e + aa;
	state[3] = state[4] + a + bb;
	state[4] = state[0] + b + cc;
	state[0] = tmp;

	tmp = 0;
	ZEND_SECURE_ZERO(x, sizeof(x));
}

__attribute__((used)) static void RIPEMD320Transform(uint32_t state[10], const unsigned char block[64])
{
	uint32_t a  = state[0], b  = state[1], c  = state[2], d  = state[3], e  = state[4];
	uint32_t aa = state[5], bb = state[6], cc = state[7], dd = state[8], ee = state[9];
	uint32_t tmp, x[16];
	int j;

	RIPEMDDecode(x, block, 64);

	for(j = 0; j < 16; j++) {
		tmp = ROLS( j, a  + F0(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F4(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}
	tmp = b; b = bb; bb = tmp;

	for(j = 16; j < 32; j++) {
		tmp = ROLS( j, a  + F1(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F3(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}
	tmp = d; d = dd; dd = tmp;

	for(j = 32; j < 48; j++) {
		tmp = ROLS( j, a  + F2(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F2(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}
	tmp = a; a = aa; aa = tmp;

	for(j = 48; j < 64; j++) {
		tmp = ROLS( j, a  + F3(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F1(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}
	tmp = c; c = cc; cc = tmp;

	for(j = 64; j < 80; j++) {
		tmp = ROLS( j, a  + F4(b,  c,  d)  + x[R[j]]  + K(j)) + e;
		a = e; e = d; d = ROL(10, c); c = b; b = tmp;
		tmp = ROLSS(j, aa + F0(bb, cc, dd) + x[RR[j]] + KK160(j)) + ee;
		aa = ee; ee = dd; dd = ROL(10, cc); cc = bb; bb = tmp;
	}
	tmp = e; e = ee; ee = tmp;

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;
	state[5] += aa;
	state[6] += bb;
	state[7] += cc;
	state[8] += dd;
	state[9] += ee;

	tmp = 0;
	ZEND_SECURE_ZERO(x, sizeof(x));
}

__attribute__((used)) static void RIPEMDEncode(unsigned char *output, uint32_t *input, unsigned int len)
{
	unsigned int i, j;

	for (i = 0, j = 0; j < len; i++, j += 4) {
		output[j + 3] = (unsigned char) ((input[i] >> 24) & 0xff);
		output[j + 2] = (unsigned char) ((input[i] >> 16) & 0xff);
		output[j + 1] = (unsigned char) ((input[i] >> 8) & 0xff);
		output[j + 0] = (unsigned char) (input[i] & 0xff);
	}
}

