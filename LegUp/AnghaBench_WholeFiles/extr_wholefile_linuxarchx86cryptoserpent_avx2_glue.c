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
struct skcipher_request {int dummy; } ;
struct serpent_xts_ctx {int /*<<< orphan*/  crypt_ctx; int /*<<< orphan*/  tweak_ctx; } ;
struct crypto_skcipher {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GLUE_FUNC_CAST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XTS_TWEAK_CAST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __serpent_encrypt ; 
 int __serpent_setkey (struct serpent_xts_ctx*,int /*<<< orphan*/  const*,unsigned int) ; 
 struct serpent_xts_ctx* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 struct crypto_skcipher* crypto_skcipher_reqtfm (struct skcipher_request*) ; 
 int glue_cbc_decrypt_req_128bit (int /*<<< orphan*/ *,struct skcipher_request*) ; 
 int glue_cbc_encrypt_req_128bit (int /*<<< orphan*/ ,struct skcipher_request*) ; 
 int glue_ctr_req_128bit (int /*<<< orphan*/ *,struct skcipher_request*) ; 
 int glue_ecb_req_128bit (int /*<<< orphan*/ *,struct skcipher_request*) ; 
 int glue_xts_req_128bit (int /*<<< orphan*/ *,struct skcipher_request*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  serpent_ctr ; 
 int /*<<< orphan*/  serpent_dec ; 
 int /*<<< orphan*/  serpent_dec_cbc ; 
 int /*<<< orphan*/  serpent_dec_xts ; 
 int /*<<< orphan*/  serpent_enc ; 
 int /*<<< orphan*/  serpent_enc_xts ; 

__attribute__((used)) static int serpent_setkey_skcipher(struct crypto_skcipher *tfm,
				   const u8 *key, unsigned int keylen)
{
	return __serpent_setkey(crypto_skcipher_ctx(tfm), key, keylen);
}

__attribute__((used)) static int ecb_encrypt(struct skcipher_request *req)
{
	return glue_ecb_req_128bit(&serpent_enc, req);
}

__attribute__((used)) static int ecb_decrypt(struct skcipher_request *req)
{
	return glue_ecb_req_128bit(&serpent_dec, req);
}

__attribute__((used)) static int cbc_encrypt(struct skcipher_request *req)
{
	return glue_cbc_encrypt_req_128bit(GLUE_FUNC_CAST(__serpent_encrypt),
					   req);
}

__attribute__((used)) static int cbc_decrypt(struct skcipher_request *req)
{
	return glue_cbc_decrypt_req_128bit(&serpent_dec_cbc, req);
}

__attribute__((used)) static int ctr_crypt(struct skcipher_request *req)
{
	return glue_ctr_req_128bit(&serpent_ctr, req);
}

__attribute__((used)) static int xts_encrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct serpent_xts_ctx *ctx = crypto_skcipher_ctx(tfm);

	return glue_xts_req_128bit(&serpent_enc_xts, req,
				   XTS_TWEAK_CAST(__serpent_encrypt),
				   &ctx->tweak_ctx, &ctx->crypt_ctx);
}

__attribute__((used)) static int xts_decrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct serpent_xts_ctx *ctx = crypto_skcipher_ctx(tfm);

	return glue_xts_req_128bit(&serpent_dec_xts, req,
				   XTS_TWEAK_CAST(__serpent_encrypt),
				   &ctx->tweak_ctx, &ctx->crypt_ctx);
}

