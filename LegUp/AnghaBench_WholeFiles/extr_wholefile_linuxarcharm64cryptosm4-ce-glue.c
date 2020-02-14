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
struct crypto_tfm {int dummy; } ;
struct crypto_sm4_ctx {int /*<<< orphan*/  rkey_dec; int /*<<< orphan*/  rkey_enc; } ;

/* Variables and functions */
 int /*<<< orphan*/  crypto_sm4_decrypt (struct crypto_tfm*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  crypto_sm4_encrypt (struct crypto_tfm*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 struct crypto_sm4_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  kernel_neon_begin () ; 
 int /*<<< orphan*/  kernel_neon_end () ; 
 int /*<<< orphan*/  may_use_simd () ; 
 int /*<<< orphan*/  sm4_ce_do_crypt (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static void sm4_ce_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
	const struct crypto_sm4_ctx *ctx = crypto_tfm_ctx(tfm);

	if (!may_use_simd()) {
		crypto_sm4_encrypt(tfm, out, in);
	} else {
		kernel_neon_begin();
		sm4_ce_do_crypt(ctx->rkey_enc, out, in);
		kernel_neon_end();
	}
}

__attribute__((used)) static void sm4_ce_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
	const struct crypto_sm4_ctx *ctx = crypto_tfm_ctx(tfm);

	if (!may_use_simd()) {
		crypto_sm4_decrypt(tfm, out, in);
	} else {
		kernel_neon_begin();
		sm4_ce_do_crypt(ctx->rkey_dec, out, in);
		kernel_neon_end();
	}
}

