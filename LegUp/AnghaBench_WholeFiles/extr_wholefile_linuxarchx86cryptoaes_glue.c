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
struct crypto_aes_ctx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  aes_dec_blk (struct crypto_aes_ctx*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  aes_enc_blk (struct crypto_aes_ctx*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 struct crypto_aes_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 

void crypto_aes_encrypt_x86(struct crypto_aes_ctx *ctx, u8 *dst, const u8 *src)
{
	aes_enc_blk(ctx, dst, src);
}

void crypto_aes_decrypt_x86(struct crypto_aes_ctx *ctx, u8 *dst, const u8 *src)
{
	aes_dec_blk(ctx, dst, src);
}

__attribute__((used)) static void aes_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
	aes_enc_blk(crypto_tfm_ctx(tfm), dst, src);
}

__attribute__((used)) static void aes_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
	aes_dec_blk(crypto_tfm_ctx(tfm), dst, src);
}

