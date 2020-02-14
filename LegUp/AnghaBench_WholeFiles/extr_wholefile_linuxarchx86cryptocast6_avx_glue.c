#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u128 ;
struct skcipher_request {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  crt_flags; } ;
struct crypto_skcipher {TYPE_1__ base; } ;
struct cast6_xts_ctx {int /*<<< orphan*/  crypt_ctx; int /*<<< orphan*/  tweak_ctx; } ;
typedef  int /*<<< orphan*/  le128 ;
typedef  int /*<<< orphan*/  be128 ;

/* Variables and functions */
 int /*<<< orphan*/  GLUE_FUNC_CAST (int /*<<< orphan*/  (*) (void*,int /*<<< orphan*/ *,int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  XTS_TWEAK_CAST (int /*<<< orphan*/  (*) (void*,int /*<<< orphan*/ *,int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  __cast6_decrypt (void*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __cast6_encrypt (void*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int __cast6_setkey (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cast6_ctr ; 
 int /*<<< orphan*/  cast6_dec ; 
 int /*<<< orphan*/  cast6_dec_cbc ; 
 int /*<<< orphan*/  cast6_dec_xts ; 
 int /*<<< orphan*/  cast6_enc ; 
 int /*<<< orphan*/  cast6_enc_xts ; 
 int cast6_setkey (TYPE_1__*,int /*<<< orphan*/  const*,unsigned int) ; 
 struct cast6_xts_ctx* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 struct crypto_skcipher* crypto_skcipher_reqtfm (struct skcipher_request*) ; 
 int glue_cbc_decrypt_req_128bit (int /*<<< orphan*/ *,struct skcipher_request*) ; 
 int glue_cbc_encrypt_req_128bit (int /*<<< orphan*/ ,struct skcipher_request*) ; 
 int glue_ctr_req_128bit (int /*<<< orphan*/ *,struct skcipher_request*) ; 
 int glue_ecb_req_128bit (int /*<<< orphan*/ *,struct skcipher_request*) ; 
 int /*<<< orphan*/  glue_xts_crypt_128bit_one (void*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int glue_xts_req_128bit (int /*<<< orphan*/ *,struct skcipher_request*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  le128_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  le128_to_be128 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  u128_xor (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int xts_verify_key (struct crypto_skcipher*,int /*<<< orphan*/  const*,unsigned int) ; 

__attribute__((used)) static int cast6_setkey_skcipher(struct crypto_skcipher *tfm,
				 const u8 *key, unsigned int keylen)
{
	return cast6_setkey(&tfm->base, key, keylen);
}

__attribute__((used)) static void cast6_xts_enc(void *ctx, u128 *dst, const u128 *src, le128 *iv)
{
	glue_xts_crypt_128bit_one(ctx, dst, src, iv,
				  GLUE_FUNC_CAST(__cast6_encrypt));
}

__attribute__((used)) static void cast6_xts_dec(void *ctx, u128 *dst, const u128 *src, le128 *iv)
{
	glue_xts_crypt_128bit_one(ctx, dst, src, iv,
				  GLUE_FUNC_CAST(__cast6_decrypt));
}

__attribute__((used)) static void cast6_crypt_ctr(void *ctx, u128 *dst, const u128 *src, le128 *iv)
{
	be128 ctrblk;

	le128_to_be128(&ctrblk, iv);
	le128_inc(iv);

	__cast6_encrypt(ctx, (u8 *)&ctrblk, (u8 *)&ctrblk);
	u128_xor(dst, src, (u128 *)&ctrblk);
}

__attribute__((used)) static int ecb_encrypt(struct skcipher_request *req)
{
	return glue_ecb_req_128bit(&cast6_enc, req);
}

__attribute__((used)) static int ecb_decrypt(struct skcipher_request *req)
{
	return glue_ecb_req_128bit(&cast6_dec, req);
}

__attribute__((used)) static int cbc_encrypt(struct skcipher_request *req)
{
	return glue_cbc_encrypt_req_128bit(GLUE_FUNC_CAST(__cast6_encrypt),
					   req);
}

__attribute__((used)) static int cbc_decrypt(struct skcipher_request *req)
{
	return glue_cbc_decrypt_req_128bit(&cast6_dec_cbc, req);
}

__attribute__((used)) static int ctr_crypt(struct skcipher_request *req)
{
	return glue_ctr_req_128bit(&cast6_ctr, req);
}

__attribute__((used)) static int xts_cast6_setkey(struct crypto_skcipher *tfm, const u8 *key,
			    unsigned int keylen)
{
	struct cast6_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
	u32 *flags = &tfm->base.crt_flags;
	int err;

	err = xts_verify_key(tfm, key, keylen);
	if (err)
		return err;

	/* first half of xts-key is for crypt */
	err = __cast6_setkey(&ctx->crypt_ctx, key, keylen / 2, flags);
	if (err)
		return err;

	/* second half of xts-key is for tweak */
	return __cast6_setkey(&ctx->tweak_ctx, key + keylen / 2, keylen / 2,
			      flags);
}

__attribute__((used)) static int xts_encrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct cast6_xts_ctx *ctx = crypto_skcipher_ctx(tfm);

	return glue_xts_req_128bit(&cast6_enc_xts, req,
				   XTS_TWEAK_CAST(__cast6_encrypt),
				   &ctx->tweak_ctx, &ctx->crypt_ctx);
}

__attribute__((used)) static int xts_decrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct cast6_xts_ctx *ctx = crypto_skcipher_ctx(tfm);

	return glue_xts_req_128bit(&cast6_dec_xts, req,
				   XTS_TWEAK_CAST(__cast6_encrypt),
				   &ctx->tweak_ctx, &ctx->crypt_ctx);
}

