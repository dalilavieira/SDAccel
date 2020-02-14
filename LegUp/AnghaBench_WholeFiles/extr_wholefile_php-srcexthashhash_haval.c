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
 int F1 (int,int,int,int,int,int,int) ; 
 int F2 (int,int,int,int,int,int,int) ; 
 int F3 (int,int,int,int,int,int,int) ; 
 int F4 (int,int,int,int,int,int,int) ; 
 int F5 (int,int,int,int,int,int,int) ; 
 size_t* I2 ; 
 size_t* I3 ; 
 size_t* I4 ; 
 size_t* I5 ; 
 int* K2 ; 
 int* K3 ; 
 int* K4 ; 
 int* K5 ; 
 size_t* M0 ; 
 size_t* M1 ; 
 size_t* M2 ; 
 size_t* M3 ; 
 size_t* M4 ; 
 size_t* M5 ; 
 size_t* M6 ; 
 size_t* M7 ; 
 int ROTR (int,int) ; 
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

__attribute__((used)) static void Encode(unsigned char *output, uint32_t *input, unsigned int len)
{
	unsigned int i, j;

	for (i = 0, j = 0; j < len; i++, j += 4) {
		output[j] = (unsigned char) (input[i] & 0xff);
		output[j + 1] = (unsigned char) ((input[i] >> 8) & 0xff);
		output[j + 2] = (unsigned char) ((input[i] >> 16) & 0xff);
		output[j + 3] = (unsigned char) ((input[i] >> 24) & 0xff);
	}
}

__attribute__((used)) static void Decode(uint32_t *output, const unsigned char *input, unsigned int len)
{
	unsigned int i, j;

	for (i = 0, j = 0; j < len; i++, j += 4) {
		output[i] = ((uint32_t) input[j]) | (((uint32_t) input[j + 1]) << 8) |
			(((uint32_t) input[j + 2]) << 16) | (((uint32_t) input[j + 3]) << 24);
	}
}

__attribute__((used)) static void PHP_3HAVALTransform(uint32_t state[8], const unsigned char block[128])
{
	uint32_t E[8];
	uint32_t x[32];
	int i;

	Decode(x, block, 128);

	for(i = 0; i < 8; i++) {
		E[i] = state[i];
	}

	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F1(E[M1[i]],E[M0[i]],E[M3[i]],E[M5[i]],E[M6[i]],E[M2[i]],E[M4[i]]),7) + ROTR(E[M7[i]],11) + x[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F2(E[M4[i]],E[M2[i]],E[M1[i]],E[M0[i]],E[M5[i]],E[M3[i]],E[M6[i]]),7) + ROTR(E[M7[i]],11) + x[I2[i]] + K2[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F3(E[M6[i]],E[M1[i]],E[M2[i]],E[M3[i]],E[M4[i]],E[M5[i]],E[M0[i]]),7) + ROTR(E[M7[i]],11) + x[I3[i]] + K3[i];
	}

	/* Update digest */
	for(i = 0; i < 8; i++) {
		state[i] += E[i];
	}

	/* Zeroize sensitive information. */
	ZEND_SECURE_ZERO((unsigned char*) x, sizeof(x));
}

__attribute__((used)) static void PHP_4HAVALTransform(uint32_t state[8], const unsigned char block[128])
{
	uint32_t E[8];
	uint32_t x[32];
	int i;

	Decode(x, block, 128);

	for(i = 0; i < 8; i++) {
		E[i] = state[i];
	}

	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F1(E[M2[i]],E[M6[i]],E[M1[i]],E[M4[i]],E[M5[i]],E[M3[i]],E[M0[i]]),7) + ROTR(E[M7[i]],11) + x[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F2(E[M3[i]],E[M5[i]],E[M2[i]],E[M0[i]],E[M1[i]],E[M6[i]],E[M4[i]]),7) + ROTR(E[M7[i]],11) + x[I2[i]] + K2[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F3(E[M1[i]],E[M4[i]],E[M3[i]],E[M6[i]],E[M0[i]],E[M2[i]],E[M5[i]]),7) + ROTR(E[M7[i]],11) + x[I3[i]] + K3[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F4(E[M6[i]],E[M4[i]],E[M0[i]],E[M5[i]],E[M2[i]],E[M1[i]],E[M3[i]]),7) + ROTR(E[M7[i]],11) + x[I4[i]] + K4[i];
	}

	/* Update digest */
	for(i = 0; i < 8; i++) {
		state[i] += E[i];
	}

	/* Zeroize sensitive information. */
	ZEND_SECURE_ZERO((unsigned char*) x, sizeof(x));
}

__attribute__((used)) static void PHP_5HAVALTransform(uint32_t state[8], const unsigned char block[128])
{
	uint32_t E[8];
	uint32_t x[32];
	int i;

	Decode(x, block, 128);

	for(i = 0; i < 8; i++) {
		E[i] = state[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F1(E[M3[i]],E[M4[i]],E[M1[i]],E[M0[i]],E[M5[i]],E[M2[i]],E[M6[i]]),7) + ROTR(E[M7[i]],11) + x[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F2(E[M6[i]],E[M2[i]],E[M1[i]],E[M0[i]],E[M3[i]],E[M4[i]],E[M5[i]]),7) + ROTR(E[M7[i]],11) + x[I2[i]] + K2[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F3(E[M2[i]],E[M6[i]],E[M0[i]],E[M4[i]],E[M3[i]],E[M1[i]],E[M5[i]]),7) + ROTR(E[M7[i]],11) + x[I3[i]] + K3[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F4(E[M1[i]],E[M5[i]],E[M3[i]],E[M2[i]],E[M0[i]],E[M4[i]],E[M6[i]]),7) + ROTR(E[M7[i]],11) + x[I4[i]] + K4[i];
	}
	for(i = 0; i < 32; i++) {
		E[7 - (i % 8)] = ROTR(F5(E[M2[i]],E[M5[i]],E[M0[i]],E[M6[i]],E[M4[i]],E[M3[i]],E[M1[i]]),7) + ROTR(E[M7[i]],11) + x[I5[i]] + K5[i];
	}

	/* Update digest */
	for(i = 0; i < 8; i++) {
		state[i] += E[i];
	}

	/* Zeroize sensitive information. */
	ZEND_SECURE_ZERO((unsigned char*) x, sizeof(x));
}

