#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zend_object ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  php_hashcontext_object ;
struct TYPE_3__ {unsigned char* state; } ;
typedef  TYPE_1__ PHP_SNEFRU_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  ZEND_SECURE_ZERO (int*,int) ; 
 int /*<<< orphan*/  round (int,int,int,int const*) ; 
 int** tables ; 

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

__attribute__((used)) static inline void Snefru(uint32_t input[16])
{
	static int shifts[4] = {16, 8, 16, 24};
	int b, index, rshift, lshift;
	const uint32_t *t0,*t1;
	uint32_t SBE,B00,B01,B02,B03,B04,B05,B06,B07,B08,B09,B10,B11,B12,B13,B14,B15;

	B00 = input[0];
	B01 = input[1];
	B02 = input[2];
	B03 = input[3];
	B04 = input[4];
	B05 = input[5];
	B06 = input[6];
	B07 = input[7];
	B08 = input[8];
	B09 = input[9];
	B10 = input[10];
	B11 = input[11];
	B12 = input[12];
	B13 = input[13];
	B14 = input[14];
	B15 = input[15];

	for (index = 0; index < 8; index++) {
		t0 = tables[2*index+0];
		t1 = tables[2*index+1];
		for (b = 0; b < 4; b++) {
			round(B15, B00, B01, t0);
			round(B00, B01, B02, t0);
			round(B01, B02, B03, t1);
			round(B02, B03, B04, t1);
			round(B03, B04, B05, t0);
			round(B04, B05, B06, t0);
			round(B05, B06, B07, t1);
			round(B06, B07, B08, t1);
			round(B07, B08, B09, t0);
			round(B08, B09, B10, t0);
			round(B09, B10, B11, t1);
			round(B10, B11, B12, t1);
			round(B11, B12, B13, t0);
			round(B12, B13, B14, t0);
			round(B13, B14, B15, t1);
			round(B14, B15, B00, t1);

			rshift = shifts[b];
			lshift = 32-rshift;

			B00 = (B00 >> rshift) | (B00 << lshift);
			B01 = (B01 >> rshift) | (B01 << lshift);
			B02 = (B02 >> rshift) | (B02 << lshift);
			B03 = (B03 >> rshift) | (B03 << lshift);
			B04 = (B04 >> rshift) | (B04 << lshift);
			B05 = (B05 >> rshift) | (B05 << lshift);
			B06 = (B06 >> rshift) | (B06 << lshift);
			B07 = (B07 >> rshift) | (B07 << lshift);
			B08 = (B08 >> rshift) | (B08 << lshift);
			B09 = (B09 >> rshift) | (B09 << lshift);
			B10 = (B10 >> rshift) | (B10 << lshift);
			B11 = (B11 >> rshift) | (B11 << lshift);
			B12 = (B12 >> rshift) | (B12 << lshift);
			B13 = (B13 >> rshift) | (B13 << lshift);
			B14 = (B14 >> rshift) | (B14 << lshift);
			B15 = (B15 >> rshift) | (B15 << lshift);
		}
	}
	input[0] ^= B15;
	input[1] ^= B14;
	input[2] ^= B13;
	input[3] ^= B12;
	input[4] ^= B11;
	input[5] ^= B10;
	input[6] ^= B09;
	input[7] ^= B08;
#if DBG_SNEFRU
	ph(input);
#endif
}

__attribute__((used)) static inline void SnefruTransform(PHP_SNEFRU_CTX *context, const unsigned char input[32])
{
	int i, j;

	for (i = 0, j = 0; i < 32; i += 4, ++j) {
		context->state[8+j] =	((input[i] & 0xff) << 24) | ((input[i+1] & 0xff) << 16) |
								((input[i+2] & 0xff) << 8) | (input[i+3] & 0xff);
	}
	Snefru(context->state);
	ZEND_SECURE_ZERO(&context->state[8], sizeof(uint32_t) * 8);
}

