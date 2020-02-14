#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  const u8 ;
struct TYPE_10__ {int /*<<< orphan*/  const* addr; } ;
struct TYPE_11__ {TYPE_4__ virt; } ;
struct TYPE_8__ {int /*<<< orphan*/  const* addr; } ;
struct TYPE_9__ {TYPE_2__ virt; } ;
struct skcipher_walk {unsigned int nbytes; unsigned int total; unsigned int stride; int /*<<< orphan*/  const* iv; TYPE_5__ src; TYPE_3__ dst; } ;
struct skcipher_request {int dummy; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_skcipher {int dummy; } ;
struct crypto_aes_ctx {int /*<<< orphan*/  key_enc; } ;
struct TYPE_7__ {int rounds; int /*<<< orphan*/  const* rk; } ;
struct aesbs_xts_ctx {TYPE_1__ key; void* tweak_tfm; } ;
struct aesbs_ctx {int rounds; int /*<<< orphan*/  const* rk; } ;
struct TYPE_12__ {int rounds; int /*<<< orphan*/  const* rk; } ;
struct aesbs_cbc_ctx {void* enc_tfm; TYPE_6__ key; } ;

/* Variables and functions */
 unsigned int AES_BLOCK_SIZE ; 
 int ARRAY_SIZE (scalar_t__*) ; 
 int PTR_ERR_OR_ZERO (void*) ; 
 scalar_t__* aes_algs ; 
 scalar_t__* aes_simd_algs ; 
 int /*<<< orphan*/  aesbs_cbc_decrypt (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int,unsigned int,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  aesbs_convert_key (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  aesbs_ctr_encrypt (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int,unsigned int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 void aesbs_ecb_decrypt (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int,int) ; 
 void aesbs_ecb_encrypt (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int,int) ; 
 void aesbs_xts_decrypt (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int,int,int /*<<< orphan*/  const*) ; 
 void aesbs_xts_encrypt (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int,int,int /*<<< orphan*/  const*) ; 
 int crypto_aes_expand_key (struct crypto_aes_ctx*,int /*<<< orphan*/  const*,unsigned int) ; 
 void* crypto_alloc_cipher (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int crypto_cbc_encrypt_walk (struct skcipher_request*,void (*) (struct crypto_skcipher*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*)) ; 
 int /*<<< orphan*/  crypto_cipher_encrypt_one (void*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int crypto_cipher_setkey (void*,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  crypto_free_cipher (void*) ; 
 void* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 struct crypto_skcipher* crypto_skcipher_reqtfm (struct skcipher_request*) ; 
 void* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  crypto_unregister_skciphers (scalar_t__*,int) ; 
 int /*<<< orphan*/  crypto_xor_cpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  kernel_neon_begin () ; 
 int /*<<< orphan*/  kernel_neon_end () ; 
 unsigned int round_down (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  simd_skcipher_free (scalar_t__) ; 
 int skcipher_walk_done (struct skcipher_walk*,unsigned int) ; 
 int skcipher_walk_virt (struct skcipher_walk*,struct skcipher_request*,int) ; 
 int xts_verify_key (struct crypto_skcipher*,int /*<<< orphan*/  const*,unsigned int) ; 

__attribute__((used)) static int aesbs_setkey(struct crypto_skcipher *tfm, const u8 *in_key,
			unsigned int key_len)
{
	struct aesbs_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct crypto_aes_ctx rk;
	int err;

	err = crypto_aes_expand_key(&rk, in_key, key_len);
	if (err)
		return err;

	ctx->rounds = 6 + key_len / 4;

	kernel_neon_begin();
	aesbs_convert_key(ctx->rk, rk.key_enc, ctx->rounds);
	kernel_neon_end();

	return 0;
}

__attribute__((used)) static int __ecb_crypt(struct skcipher_request *req,
		       void (*fn)(u8 out[], u8 const in[], u8 const rk[],
				  int rounds, int blocks))
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct aesbs_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct skcipher_walk walk;
	int err;

	err = skcipher_walk_virt(&walk, req, true);

	kernel_neon_begin();
	while (walk.nbytes >= AES_BLOCK_SIZE) {
		unsigned int blocks = walk.nbytes / AES_BLOCK_SIZE;

		if (walk.nbytes < walk.total)
			blocks = round_down(blocks,
					    walk.stride / AES_BLOCK_SIZE);

		fn(walk.dst.virt.addr, walk.src.virt.addr, ctx->rk,
		   ctx->rounds, blocks);
		err = skcipher_walk_done(&walk,
					 walk.nbytes - blocks * AES_BLOCK_SIZE);
	}
	kernel_neon_end();

	return err;
}

__attribute__((used)) static int ecb_encrypt(struct skcipher_request *req)
{
	return __ecb_crypt(req, aesbs_ecb_encrypt);
}

__attribute__((used)) static int ecb_decrypt(struct skcipher_request *req)
{
	return __ecb_crypt(req, aesbs_ecb_decrypt);
}

__attribute__((used)) static int aesbs_cbc_setkey(struct crypto_skcipher *tfm, const u8 *in_key,
			    unsigned int key_len)
{
	struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct crypto_aes_ctx rk;
	int err;

	err = crypto_aes_expand_key(&rk, in_key, key_len);
	if (err)
		return err;

	ctx->key.rounds = 6 + key_len / 4;

	kernel_neon_begin();
	aesbs_convert_key(ctx->key.rk, rk.key_enc, ctx->key.rounds);
	kernel_neon_end();

	return crypto_cipher_setkey(ctx->enc_tfm, in_key, key_len);
}

__attribute__((used)) static void cbc_encrypt_one(struct crypto_skcipher *tfm, const u8 *src, u8 *dst)
{
	struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);

	crypto_cipher_encrypt_one(ctx->enc_tfm, dst, src);
}

__attribute__((used)) static int cbc_encrypt(struct skcipher_request *req)
{
	return crypto_cbc_encrypt_walk(req, cbc_encrypt_one);
}

__attribute__((used)) static int cbc_decrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct aesbs_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct skcipher_walk walk;
	int err;

	err = skcipher_walk_virt(&walk, req, true);

	kernel_neon_begin();
	while (walk.nbytes >= AES_BLOCK_SIZE) {
		unsigned int blocks = walk.nbytes / AES_BLOCK_SIZE;

		if (walk.nbytes < walk.total)
			blocks = round_down(blocks,
					    walk.stride / AES_BLOCK_SIZE);

		aesbs_cbc_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
				  ctx->key.rk, ctx->key.rounds, blocks,
				  walk.iv);
		err = skcipher_walk_done(&walk,
					 walk.nbytes - blocks * AES_BLOCK_SIZE);
	}
	kernel_neon_end();

	return err;
}

__attribute__((used)) static int cbc_init(struct crypto_tfm *tfm)
{
	struct aesbs_cbc_ctx *ctx = crypto_tfm_ctx(tfm);

	ctx->enc_tfm = crypto_alloc_cipher("aes", 0, 0);

	return PTR_ERR_OR_ZERO(ctx->enc_tfm);
}

__attribute__((used)) static void cbc_exit(struct crypto_tfm *tfm)
{
	struct aesbs_cbc_ctx *ctx = crypto_tfm_ctx(tfm);

	crypto_free_cipher(ctx->enc_tfm);
}

__attribute__((used)) static int ctr_encrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct aesbs_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct skcipher_walk walk;
	u8 buf[AES_BLOCK_SIZE];
	int err;

	err = skcipher_walk_virt(&walk, req, true);

	kernel_neon_begin();
	while (walk.nbytes > 0) {
		unsigned int blocks = walk.nbytes / AES_BLOCK_SIZE;
		u8 *final = (walk.total % AES_BLOCK_SIZE) ? buf : NULL;

		if (walk.nbytes < walk.total) {
			blocks = round_down(blocks,
					    walk.stride / AES_BLOCK_SIZE);
			final = NULL;
		}

		aesbs_ctr_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
				  ctx->rk, ctx->rounds, blocks, walk.iv, final);

		if (final) {
			u8 *dst = walk.dst.virt.addr + blocks * AES_BLOCK_SIZE;
			u8 *src = walk.src.virt.addr + blocks * AES_BLOCK_SIZE;

			crypto_xor_cpy(dst, src, final,
				       walk.total % AES_BLOCK_SIZE);

			err = skcipher_walk_done(&walk, 0);
			break;
		}
		err = skcipher_walk_done(&walk,
					 walk.nbytes - blocks * AES_BLOCK_SIZE);
	}
	kernel_neon_end();

	return err;
}

__attribute__((used)) static int aesbs_xts_setkey(struct crypto_skcipher *tfm, const u8 *in_key,
			    unsigned int key_len)
{
	struct aesbs_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
	int err;

	err = xts_verify_key(tfm, in_key, key_len);
	if (err)
		return err;

	key_len /= 2;
	err = crypto_cipher_setkey(ctx->tweak_tfm, in_key + key_len, key_len);
	if (err)
		return err;

	return aesbs_setkey(tfm, in_key, key_len);
}

__attribute__((used)) static int xts_init(struct crypto_tfm *tfm)
{
	struct aesbs_xts_ctx *ctx = crypto_tfm_ctx(tfm);

	ctx->tweak_tfm = crypto_alloc_cipher("aes", 0, 0);

	return PTR_ERR_OR_ZERO(ctx->tweak_tfm);
}

__attribute__((used)) static void xts_exit(struct crypto_tfm *tfm)
{
	struct aesbs_xts_ctx *ctx = crypto_tfm_ctx(tfm);

	crypto_free_cipher(ctx->tweak_tfm);
}

__attribute__((used)) static int __xts_crypt(struct skcipher_request *req,
		       void (*fn)(u8 out[], u8 const in[], u8 const rk[],
				  int rounds, int blocks, u8 iv[]))
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct aesbs_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct skcipher_walk walk;
	int err;

	err = skcipher_walk_virt(&walk, req, true);

	crypto_cipher_encrypt_one(ctx->tweak_tfm, walk.iv, walk.iv);

	kernel_neon_begin();
	while (walk.nbytes >= AES_BLOCK_SIZE) {
		unsigned int blocks = walk.nbytes / AES_BLOCK_SIZE;

		if (walk.nbytes < walk.total)
			blocks = round_down(blocks,
					    walk.stride / AES_BLOCK_SIZE);

		fn(walk.dst.virt.addr, walk.src.virt.addr, ctx->key.rk,
		   ctx->key.rounds, blocks, walk.iv);
		err = skcipher_walk_done(&walk,
					 walk.nbytes - blocks * AES_BLOCK_SIZE);
	}
	kernel_neon_end();

	return err;
}

__attribute__((used)) static int xts_encrypt(struct skcipher_request *req)
{
	return __xts_crypt(req, aesbs_xts_encrypt);
}

__attribute__((used)) static int xts_decrypt(struct skcipher_request *req)
{
	return __xts_crypt(req, aesbs_xts_decrypt);
}

__attribute__((used)) static void aes_exit(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(aes_simd_algs); i++)
		if (aes_simd_algs[i])
			simd_skcipher_free(aes_simd_algs[i]);

	crypto_unregister_skciphers(aes_algs, ARRAY_SIZE(aes_algs));
}

