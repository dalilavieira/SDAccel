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
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  php_hashcontext_object ;

/* Variables and functions */
 int SHA256_F0 (int,int,int) ; 
 int SHA256_F1 (int,int,int) ; 
 int SHA256_F2 (int) ; 
 int SHA256_F3 (int) ; 
 int SHA256_F4 (int) ; 
 int SHA256_F5 (int) ; 
 int* SHA256_K ; 
 int SHA512_F0 (int,int,int) ; 
 int SHA512_F1 (int,int,int) ; 
 int SHA512_F2 (int) ; 
 int SHA512_F3 (int) ; 
 int SHA512_F4 (int) ; 
 int SHA512_F5 (int) ; 
 int* SHA512_K ; 
 int /*<<< orphan*/  ZEND_SECURE_ZERO (unsigned char*,int) ; 

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

__attribute__((used)) static void SHAEncode32(unsigned char *output, uint32_t *input, unsigned int len)
{
	unsigned int i, j;

	for (i = 0, j = 0; j < len; i++, j += 4) {
		output[j] = (unsigned char) ((input[i] >> 24) & 0xff);
		output[j + 1] = (unsigned char) ((input[i] >> 16) & 0xff);
		output[j + 2] = (unsigned char) ((input[i] >> 8) & 0xff);
		output[j + 3] = (unsigned char) (input[i] & 0xff);
	}
}

__attribute__((used)) static void SHADecode32(uint32_t *output, const unsigned char *input, unsigned int len)
{
	unsigned int i, j;

	for (i = 0, j = 0; j < len; i++, j += 4)
		output[i] = ((uint32_t) input[j + 3]) | (((uint32_t) input[j + 2]) << 8) |
			(((uint32_t) input[j + 1]) << 16) | (((uint32_t) input[j]) << 24);
}

__attribute__((used)) static void SHA256Transform(uint32_t state[8], const unsigned char block[64])
{
	uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
	uint32_t e = state[4], f = state[5], g = state[6], h = state[7];
	uint32_t x[16], T1, T2, W[64];
	int i;

	SHADecode32(x, block, 64);

	/* Schedule */
	for(i = 0; i < 16; i++) {
		W[i] = x[i];
	}
	for(i = 16; i < 64; i++) {
		W[i] = SHA256_F5(W[i-2]) + W[i-7] + SHA256_F4(W[i-15]) + W[i-16];
	}

	for (i = 0; i < 64; i++) {
		T1 = h + SHA256_F3(e) + SHA256_F0(e,f,g) + SHA256_K[i] + W[i];
		T2 = SHA256_F2(a) + SHA256_F1(a,b,c);
		h = g; g = f; f = e; e = d + T1;
		d = c; c = b; b = a; a = T1 + T2;
	}

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;
	state[5] += f;
	state[6] += g;
	state[7] += h;

	/* Zeroize sensitive information. */
	ZEND_SECURE_ZERO((unsigned char*) x, sizeof(x));
}

__attribute__((used)) static void SHAEncode64(unsigned char *output, uint64_t *input, unsigned int len)
{
	unsigned int i, j;

	for (i = 0, j = 0; j < len; i++, j += 8) {
		output[j] = (unsigned char) ((input[i] >> 56) & 0xff);
		output[j + 1] = (unsigned char) ((input[i] >> 48) & 0xff);
		output[j + 2] = (unsigned char) ((input[i] >> 40) & 0xff);
		output[j + 3] = (unsigned char) ((input[i] >> 32) & 0xff);
		output[j + 4] = (unsigned char) ((input[i] >> 24) & 0xff);
		output[j + 5] = (unsigned char) ((input[i] >> 16) & 0xff);
		output[j + 6] = (unsigned char) ((input[i] >> 8) & 0xff);
		output[j + 7] = (unsigned char) (input[i] & 0xff);
	}
}

__attribute__((used)) static void SHADecode64(uint64_t *output, const unsigned char *input, unsigned int len)
{
	unsigned int i, j;

	for (i = 0, j = 0; j < len; i++, j += 8)
		output[i] =
			((uint64_t) input[j + 7]) | (((uint64_t) input[j + 6]) << 8) |
			(((uint64_t) input[j + 5]) << 16) | (((uint64_t) input[j + 4]) << 24) |
			(((uint64_t) input[j + 3]) << 32) | (((uint64_t) input[j + 2]) << 40) |
			(((uint64_t) input[j + 1]) << 48) | (((uint64_t) input[j]) << 56);
}

__attribute__((used)) static void SHA512Transform(uint64_t state[8], const unsigned char block[128])
{
	uint64_t a = state[0], b = state[1], c = state[2], d = state[3];
	uint64_t e = state[4], f = state[5], g = state[6], h = state[7];
	uint64_t x[16], T1, T2, W[80];
	int i;

	SHADecode64(x, block, 128);

	/* Schedule */
	for(i = 0; i < 16; i++) {
		W[i] = x[i];
	}
	for(i = 16; i < 80; i++) {
		W[i] = SHA512_F5(W[i-2]) + W[i-7] + SHA512_F4(W[i-15]) + W[i-16];
	}

	for (i = 0; i < 80; i++) {
		T1 = h + SHA512_F3(e) + SHA512_F0(e,f,g) + SHA512_K[i] + W[i];
		T2 = SHA512_F2(a) + SHA512_F1(a,b,c);
		h = g; g = f; f = e; e = d + T1;
		d = c; c = b; b = a; a = T1 + T2;
	}

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;
	state[5] += f;
	state[6] += g;
	state[7] += h;

	/* Zeroize sensitive information. */
	ZEND_SECURE_ZERO((unsigned char*) x, sizeof(x));
}

