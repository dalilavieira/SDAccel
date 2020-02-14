#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ut8 ;
struct TYPE_6__ {unsigned int* W; unsigned int* H; int lenW; int sizeHi; int sizeLo; } ;
typedef  TYPE_1__ R_SHA_CTX ;

/* Variables and functions */
 unsigned int SHA_ROT (unsigned int,int) ; 

__attribute__((used)) static void shaHashBlock(R_SHA_CTX *ctx) {
	int t;
	unsigned int A, B, C, D, E, TEMP;

	for (t = 16; t <= 79; t++) {
		ctx->W[t] =
			SHA_ROT (ctx->W[t - 3] ^ ctx->W[t - 8] ^ ctx->W[t - 14] ^ ctx->W[t - 16], 1);
	}

	A = ctx->H[0];
	B = ctx->H[1];
	C = ctx->H[2];
	D = ctx->H[3];
	E = ctx->H[4];

	for (t = 0; t <= 19; t++) {
		TEMP = SHA_ROT (A, 5) + (((C ^ D) & B) ^ D) + E + ctx->W[t] + 0x5a827999;
		E = D; D = C; C = SHA_ROT (B, 30); B = A; A = TEMP;
	}
	for (t = 20; t <= 39; t++) {
		TEMP = SHA_ROT (A, 5) + (B ^ C ^ D) + E + ctx->W[t] + 0x6ed9eba1;
		E = D; D = C; C = SHA_ROT (B, 30); B = A; A = TEMP;
	}
	for (t = 40; t <= 59; t++) {
		TEMP = SHA_ROT (A, 5) + ((B & C) | (D & (B | C))) + E + ctx->W[t] + 0x8f1bbcdc;
		E = D; D = C; C = SHA_ROT (B, 30); B = A; A = TEMP;
	}
	for (t = 60; t <= 79; t++) {
		TEMP = SHA_ROT (A, 5) + (B ^ C ^ D) + E + ctx->W[t] + 0xca62c1d6;
		E = D; D = C; C = SHA_ROT (B, 30); B = A; A = TEMP;
	}

	ctx->H[0] += A;
	ctx->H[1] += B;
	ctx->H[2] += C;
	ctx->H[3] += D;
	ctx->H[4] += E;
}

void SHA1_Init(R_SHA_CTX *ctx) {
	int i;

	ctx->lenW = 0;
	ctx->sizeHi = ctx->sizeLo = 0;

	// Initialize H with the magic constants (see FIPS180 for constants)
	ctx->H[0] = 0x67452301;
	ctx->H[1] = 0xefcdab89;
	ctx->H[2] = 0x98badcfe;
	ctx->H[3] = 0x10325476;
	ctx->H[4] = 0xc3d2e1f0;

	for (i = 0; i < 80; i++) {
		ctx->W[i] = 0;
	}
}

void SHA1_Update(R_SHA_CTX *ctx, const void *_dataIn, int len) {
	const ut8 *dataIn = _dataIn;
	int i;

	// Read the data into W and process blocks as they get full
	for (i = 0; i < len; i++) {
		ctx->W[ctx->lenW / 4] <<= 8;
		ctx->W[ctx->lenW / 4] |= (unsigned int) dataIn[i];
		if ((++ctx->lenW) % 64 == 0) {
			shaHashBlock (ctx);
			ctx->lenW = 0;
		}
		ctx->sizeLo += 8;
		ctx->sizeHi += (ctx->sizeLo < 8);
	}
}

void SHA1_Final(ut8 hashout[20], R_SHA_CTX *ctx) {
	ut8 pad0x80 = 0x80;
	ut8 pad0x00 = 0x00;
	ut8 padlen[8];
	int i;

	/* Pad with a binary 1 (e.g. 0x80), then zeroes, then length */
	padlen[0] = (ut8) ((ctx->sizeHi >> 24) & 255);
	padlen[1] = (ut8) ((ctx->sizeHi >> 16) & 255);
	padlen[2] = (ut8) ((ctx->sizeHi >> 8) & 255);
	padlen[3] = (ut8) ((ctx->sizeHi >> 0) & 255);
	padlen[4] = (ut8) ((ctx->sizeLo >> 24) & 255);
	padlen[5] = (ut8) ((ctx->sizeLo >> 16) & 255);
	padlen[6] = (ut8) ((ctx->sizeLo >> 8) & 255);
	padlen[7] = (ut8) ((ctx->sizeLo >> 0) & 255);

	SHA1_Update (ctx, &pad0x80, 1);
	while (ctx->lenW != 56) {
		SHA1_Update (ctx, &pad0x00, 1);
	}
	SHA1_Update (ctx, padlen, 8);

	/* Output hash */
	for (i = 0; i < 20; i++) {
		hashout[i] = (ut8) (ctx->H[i / 4] >> 24);
		ctx->H[i / 4] <<= 8;
	}

	/* Re-initialize the context (also zeroizes contents) */
	SHA1_Init (ctx);
}

