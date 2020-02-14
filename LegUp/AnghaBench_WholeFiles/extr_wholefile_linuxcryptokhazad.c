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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u64 ;
struct khazad_ctx {int* E; int* D; } ;
struct crypto_tfm {int dummy; } ;
typedef  scalar_t__ state ;
typedef  int /*<<< orphan*/  __be64 ;
typedef  int /*<<< orphan*/  __be32 ;
typedef  scalar_t__ K1 ;

/* Variables and functions */
 int KHAZAD_ROUNDS ; 
 int* T0 ; 
 int* T1 ; 
 int* T2 ; 
 int* T3 ; 
 int* T4 ; 
 int* T5 ; 
 int* T6 ; 
 int* T7 ; 
 int be32_to_cpu (int /*<<< orphan*/  const) ; 
 int const be64_to_cpu (int /*<<< orphan*/  const) ; 
 int* c ; 
 int /*<<< orphan*/  cpu_to_be64 (int) ; 
 struct khazad_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 

__attribute__((used)) static int khazad_setkey(struct crypto_tfm *tfm, const u8 *in_key,
			 unsigned int key_len)
{
	struct khazad_ctx *ctx = crypto_tfm_ctx(tfm);
	const __be32 *key = (const __be32 *)in_key;
	int r;
	const u64 *S = T7;
	u64 K2, K1;

	/* key is supposed to be 32-bit aligned */
	K2 = ((u64)be32_to_cpu(key[0]) << 32) | be32_to_cpu(key[1]);
	K1 = ((u64)be32_to_cpu(key[2]) << 32) | be32_to_cpu(key[3]);

	/* setup the encrypt key */
	for (r = 0; r <= KHAZAD_ROUNDS; r++) {
		ctx->E[r] = T0[(int)(K1 >> 56)       ] ^
			    T1[(int)(K1 >> 48) & 0xff] ^
			    T2[(int)(K1 >> 40) & 0xff] ^
			    T3[(int)(K1 >> 32) & 0xff] ^
			    T4[(int)(K1 >> 24) & 0xff] ^
			    T5[(int)(K1 >> 16) & 0xff] ^
			    T6[(int)(K1 >>  8) & 0xff] ^
			    T7[(int)(K1      ) & 0xff] ^
			    c[r] ^ K2;
		K2 = K1; 
		K1 = ctx->E[r];
	}
	/* Setup the decrypt key */
	ctx->D[0] = ctx->E[KHAZAD_ROUNDS];
	for (r = 1; r < KHAZAD_ROUNDS; r++) {
		K1 = ctx->E[KHAZAD_ROUNDS - r];
		ctx->D[r] = T0[(int)S[(int)(K1 >> 56)       ] & 0xff] ^
			    T1[(int)S[(int)(K1 >> 48) & 0xff] & 0xff] ^
			    T2[(int)S[(int)(K1 >> 40) & 0xff] & 0xff] ^
			    T3[(int)S[(int)(K1 >> 32) & 0xff] & 0xff] ^
			    T4[(int)S[(int)(K1 >> 24) & 0xff] & 0xff] ^
			    T5[(int)S[(int)(K1 >> 16) & 0xff] & 0xff] ^
			    T6[(int)S[(int)(K1 >>  8) & 0xff] & 0xff] ^
			    T7[(int)S[(int)(K1      ) & 0xff] & 0xff];
	}
	ctx->D[KHAZAD_ROUNDS] = ctx->E[0];

	return 0;

}

__attribute__((used)) static void khazad_crypt(const u64 roundKey[KHAZAD_ROUNDS + 1],
		u8 *ciphertext, const u8 *plaintext)
{
	const __be64 *src = (const __be64 *)plaintext;
	__be64 *dst = (__be64 *)ciphertext;
	int r;
	u64 state;

	state = be64_to_cpu(*src) ^ roundKey[0];

	for (r = 1; r < KHAZAD_ROUNDS; r++) {
		state = T0[(int)(state >> 56)       ] ^
			T1[(int)(state >> 48) & 0xff] ^
			T2[(int)(state >> 40) & 0xff] ^
			T3[(int)(state >> 32) & 0xff] ^
			T4[(int)(state >> 24) & 0xff] ^
			T5[(int)(state >> 16) & 0xff] ^
			T6[(int)(state >>  8) & 0xff] ^
			T7[(int)(state      ) & 0xff] ^
			roundKey[r];
    	}

	state = (T0[(int)(state >> 56)       ] & 0xff00000000000000ULL) ^
		(T1[(int)(state >> 48) & 0xff] & 0x00ff000000000000ULL) ^
		(T2[(int)(state >> 40) & 0xff] & 0x0000ff0000000000ULL) ^
		(T3[(int)(state >> 32) & 0xff] & 0x000000ff00000000ULL) ^
		(T4[(int)(state >> 24) & 0xff] & 0x00000000ff000000ULL) ^
		(T5[(int)(state >> 16) & 0xff] & 0x0000000000ff0000ULL) ^
		(T6[(int)(state >>  8) & 0xff] & 0x000000000000ff00ULL) ^
		(T7[(int)(state      ) & 0xff] & 0x00000000000000ffULL) ^
		roundKey[KHAZAD_ROUNDS];

	*dst = cpu_to_be64(state);
}

__attribute__((used)) static void khazad_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
	struct khazad_ctx *ctx = crypto_tfm_ctx(tfm);
	khazad_crypt(ctx->E, dst, src);
}

__attribute__((used)) static void khazad_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
	struct khazad_ctx *ctx = crypto_tfm_ctx(tfm);
	khazad_crypt(ctx->D, dst, src);
}

