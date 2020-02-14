#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct TYPE_11__ {scalar_t__ addr; } ;
struct TYPE_12__ {TYPE_4__ virt; } ;
struct TYPE_13__ {scalar_t__ addr; } ;
struct TYPE_14__ {TYPE_6__ virt; } ;
struct skcipher_walk {unsigned int nbytes; TYPE_5__ dst; TYPE_7__ src; int /*<<< orphan*/ * iv; } ;
struct skcipher_request {int dummy; } ;
struct TYPE_9__ {int cra_blocksize; int cra_ctxsize; int /*<<< orphan*/  cra_alignmask; int /*<<< orphan*/  cra_priority; } ;
struct TYPE_10__ {int (* init ) (struct crypto_skcipher*) ;void (* exit ) (struct crypto_skcipher*) ;int (* setkey ) (struct crypto_skcipher*,int /*<<< orphan*/  const*,unsigned int) ;int (* encrypt ) (struct skcipher_request*) ;int (* decrypt ) (struct skcipher_request*) ;TYPE_2__ base; int /*<<< orphan*/  max_keysize; int /*<<< orphan*/  min_keysize; int /*<<< orphan*/  ivsize; int /*<<< orphan*/  chunksize; } ;
struct skcipher_instance {void (* free ) (struct skcipher_instance*) ;TYPE_3__ alg; } ;
struct rtattr {int dummy; } ;
struct crypto_template {int dummy; } ;
struct crypto_spawn {int dummy; } ;
struct crypto_skcipher {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  cia_max_keysize; int /*<<< orphan*/  cia_min_keysize; } ;
struct crypto_cipher {TYPE_1__ cra_cipher; int /*<<< orphan*/  cra_blocksize; int /*<<< orphan*/  cra_alignmask; int /*<<< orphan*/  cra_priority; int /*<<< orphan*/  mask; int /*<<< orphan*/  type; } ;
struct crypto_cfb_ctx {struct crypto_cipher* child; } ;
struct crypto_attr_type {TYPE_1__ cra_cipher; int /*<<< orphan*/  cra_blocksize; int /*<<< orphan*/  cra_alignmask; int /*<<< orphan*/  cra_priority; int /*<<< orphan*/  mask; int /*<<< orphan*/  type; } ;
struct crypto_alg {TYPE_1__ cra_cipher; int /*<<< orphan*/  cra_blocksize; int /*<<< orphan*/  cra_alignmask; int /*<<< orphan*/  cra_priority; int /*<<< orphan*/  mask; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_ALG_NEED_FALLBACK ; 
 int /*<<< orphan*/  CRYPTO_ALG_TYPE_CIPHER ; 
 int CRYPTO_ALG_TYPE_MASK ; 
 int /*<<< orphan*/  CRYPTO_ALG_TYPE_SKCIPHER ; 
 int CRYPTO_TFM_REQ_MASK ; 
 int CRYPTO_TFM_RES_MASK ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct crypto_cipher*) ; 
 int MAX_CIPHER_ALIGNMASK ; 
 int MAX_CIPHER_BLOCKSIZE ; 
 int /*<<< orphan*/ * PTR_ALIGN (int /*<<< orphan*/ *,unsigned long const) ; 
 int PTR_ERR (struct crypto_cipher*) ; 
 int crypto_check_attr_type (struct rtattr**,int /*<<< orphan*/ ) ; 
 unsigned int crypto_cipher_blocksize (struct crypto_cipher*) ; 
 int /*<<< orphan*/  crypto_cipher_clear_flags (struct crypto_cipher*,int) ; 
 int /*<<< orphan*/  crypto_cipher_encrypt_one (struct crypto_cipher*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int crypto_cipher_get_flags (struct crypto_cipher*) ; 
 int /*<<< orphan*/  crypto_cipher_set_flags (struct crypto_cipher*,int) ; 
 int crypto_cipher_setkey (struct crypto_cipher*,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  crypto_drop_skcipher (struct crypto_spawn*) ; 
 int /*<<< orphan*/  crypto_drop_spawn (struct crypto_spawn*) ; 
 int /*<<< orphan*/  crypto_free_cipher (struct crypto_cipher*) ; 
 struct crypto_cipher* crypto_get_attr_alg (struct rtattr**,int /*<<< orphan*/ ,int) ; 
 struct crypto_cipher* crypto_get_attr_type (struct rtattr**) ; 
 int crypto_init_spawn (struct crypto_spawn*,struct crypto_cipher*,int /*<<< orphan*/ ,int) ; 
 int crypto_inst_setname (int /*<<< orphan*/ ,char*,struct crypto_cipher*) ; 
 int /*<<< orphan*/  crypto_mod_put (struct crypto_cipher*) ; 
 int crypto_requires_off (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned long crypto_skcipher_alignmask (struct crypto_skcipher*) ; 
 struct crypto_cfb_ctx* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 int crypto_skcipher_get_flags (struct crypto_skcipher*) ; 
 struct crypto_skcipher* crypto_skcipher_reqtfm (struct skcipher_request*) ; 
 int /*<<< orphan*/  crypto_skcipher_set_flags (struct crypto_skcipher*,int) ; 
 struct crypto_cipher* crypto_spawn_cipher (struct crypto_spawn*) ; 
 int /*<<< orphan*/  crypto_xor (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int const) ; 
 int /*<<< orphan*/  crypto_xor_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  kfree (struct skcipher_instance*) ; 
 struct skcipher_instance* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ * const,int /*<<< orphan*/ *,unsigned int const) ; 
 struct skcipher_instance* skcipher_alg_instance (struct crypto_skcipher*) ; 
 int /*<<< orphan*/  skcipher_crypto_instance (struct skcipher_instance*) ; 
 struct crypto_spawn* skcipher_instance_ctx (struct skcipher_instance*) ; 
 int skcipher_register_instance (struct crypto_template*,struct skcipher_instance*) ; 
 int skcipher_walk_done (struct skcipher_walk*,int) ; 
 int skcipher_walk_virt (struct skcipher_walk*,struct skcipher_request*,int) ; 

__attribute__((used)) static unsigned int crypto_cfb_bsize(struct crypto_skcipher *tfm)
{
	struct crypto_cfb_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct crypto_cipher *child = ctx->child;

	return crypto_cipher_blocksize(child);
}

__attribute__((used)) static void crypto_cfb_encrypt_one(struct crypto_skcipher *tfm,
					  const u8 *src, u8 *dst)
{
	struct crypto_cfb_ctx *ctx = crypto_skcipher_ctx(tfm);

	crypto_cipher_encrypt_one(ctx->child, dst, src);
}

__attribute__((used)) static void crypto_cfb_final(struct skcipher_walk *walk,
			     struct crypto_skcipher *tfm)
{
	const unsigned long alignmask = crypto_skcipher_alignmask(tfm);
	u8 tmp[MAX_CIPHER_BLOCKSIZE + MAX_CIPHER_ALIGNMASK];
	u8 *stream = PTR_ALIGN(tmp + 0, alignmask + 1);
	u8 *src = walk->src.virt.addr;
	u8 *dst = walk->dst.virt.addr;
	u8 *iv = walk->iv;
	unsigned int nbytes = walk->nbytes;

	crypto_cfb_encrypt_one(tfm, iv, stream);
	crypto_xor_cpy(dst, stream, src, nbytes);
}

__attribute__((used)) static int crypto_cfb_encrypt_segment(struct skcipher_walk *walk,
				      struct crypto_skcipher *tfm)
{
	const unsigned int bsize = crypto_cfb_bsize(tfm);
	unsigned int nbytes = walk->nbytes;
	u8 *src = walk->src.virt.addr;
	u8 *dst = walk->dst.virt.addr;
	u8 *iv = walk->iv;

	do {
		crypto_cfb_encrypt_one(tfm, iv, dst);
		crypto_xor(dst, src, bsize);
		iv = dst;

		src += bsize;
		dst += bsize;
	} while ((nbytes -= bsize) >= bsize);

	memcpy(walk->iv, iv, bsize);

	return nbytes;
}

__attribute__((used)) static int crypto_cfb_encrypt_inplace(struct skcipher_walk *walk,
				      struct crypto_skcipher *tfm)
{
	const unsigned int bsize = crypto_cfb_bsize(tfm);
	unsigned int nbytes = walk->nbytes;
	u8 *src = walk->src.virt.addr;
	u8 *iv = walk->iv;
	u8 tmp[MAX_CIPHER_BLOCKSIZE];

	do {
		crypto_cfb_encrypt_one(tfm, iv, tmp);
		crypto_xor(src, tmp, bsize);
		iv = src;

		src += bsize;
	} while ((nbytes -= bsize) >= bsize);

	memcpy(walk->iv, iv, bsize);

	return nbytes;
}

__attribute__((used)) static int crypto_cfb_encrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct skcipher_walk walk;
	unsigned int bsize = crypto_cfb_bsize(tfm);
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while (walk.nbytes >= bsize) {
		if (walk.src.virt.addr == walk.dst.virt.addr)
			err = crypto_cfb_encrypt_inplace(&walk, tfm);
		else
			err = crypto_cfb_encrypt_segment(&walk, tfm);
		err = skcipher_walk_done(&walk, err);
	}

	if (walk.nbytes) {
		crypto_cfb_final(&walk, tfm);
		err = skcipher_walk_done(&walk, 0);
	}

	return err;
}

__attribute__((used)) static int crypto_cfb_decrypt_segment(struct skcipher_walk *walk,
				      struct crypto_skcipher *tfm)
{
	const unsigned int bsize = crypto_cfb_bsize(tfm);
	unsigned int nbytes = walk->nbytes;
	u8 *src = walk->src.virt.addr;
	u8 *dst = walk->dst.virt.addr;
	u8 *iv = walk->iv;

	do {
		crypto_cfb_encrypt_one(tfm, iv, dst);
		crypto_xor(dst, src, bsize);
		iv = src;

		src += bsize;
		dst += bsize;
	} while ((nbytes -= bsize) >= bsize);

	memcpy(walk->iv, iv, bsize);

	return nbytes;
}

__attribute__((used)) static int crypto_cfb_decrypt_inplace(struct skcipher_walk *walk,
				      struct crypto_skcipher *tfm)
{
	const unsigned int bsize = crypto_cfb_bsize(tfm);
	unsigned int nbytes = walk->nbytes;
	u8 *src = walk->src.virt.addr;
	u8 * const iv = walk->iv;
	u8 tmp[MAX_CIPHER_BLOCKSIZE];

	do {
		crypto_cfb_encrypt_one(tfm, iv, tmp);
		memcpy(iv, src, bsize);
		crypto_xor(src, tmp, bsize);
		src += bsize;
	} while ((nbytes -= bsize) >= bsize);

	return nbytes;
}

__attribute__((used)) static int crypto_cfb_decrypt_blocks(struct skcipher_walk *walk,
				     struct crypto_skcipher *tfm)
{
	if (walk->src.virt.addr == walk->dst.virt.addr)
		return crypto_cfb_decrypt_inplace(walk, tfm);
	else
		return crypto_cfb_decrypt_segment(walk, tfm);
}

__attribute__((used)) static int crypto_cfb_setkey(struct crypto_skcipher *parent, const u8 *key,
			     unsigned int keylen)
{
	struct crypto_cfb_ctx *ctx = crypto_skcipher_ctx(parent);
	struct crypto_cipher *child = ctx->child;
	int err;

	crypto_cipher_clear_flags(child, CRYPTO_TFM_REQ_MASK);
	crypto_cipher_set_flags(child, crypto_skcipher_get_flags(parent) &
				       CRYPTO_TFM_REQ_MASK);
	err = crypto_cipher_setkey(child, key, keylen);
	crypto_skcipher_set_flags(parent, crypto_cipher_get_flags(child) &
					  CRYPTO_TFM_RES_MASK);
	return err;
}

__attribute__((used)) static int crypto_cfb_decrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct skcipher_walk walk;
	const unsigned int bsize = crypto_cfb_bsize(tfm);
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while (walk.nbytes >= bsize) {
		err = crypto_cfb_decrypt_blocks(&walk, tfm);
		err = skcipher_walk_done(&walk, err);
	}

	if (walk.nbytes) {
		crypto_cfb_final(&walk, tfm);
		err = skcipher_walk_done(&walk, 0);
	}

	return err;
}

__attribute__((used)) static int crypto_cfb_init_tfm(struct crypto_skcipher *tfm)
{
	struct skcipher_instance *inst = skcipher_alg_instance(tfm);
	struct crypto_spawn *spawn = skcipher_instance_ctx(inst);
	struct crypto_cfb_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct crypto_cipher *cipher;

	cipher = crypto_spawn_cipher(spawn);
	if (IS_ERR(cipher))
		return PTR_ERR(cipher);

	ctx->child = cipher;
	return 0;
}

__attribute__((used)) static void crypto_cfb_exit_tfm(struct crypto_skcipher *tfm)
{
	struct crypto_cfb_ctx *ctx = crypto_skcipher_ctx(tfm);

	crypto_free_cipher(ctx->child);
}

__attribute__((used)) static void crypto_cfb_free(struct skcipher_instance *inst)
{
	crypto_drop_skcipher(skcipher_instance_ctx(inst));
	kfree(inst);
}

__attribute__((used)) static int crypto_cfb_create(struct crypto_template *tmpl, struct rtattr **tb)
{
	struct skcipher_instance *inst;
	struct crypto_attr_type *algt;
	struct crypto_spawn *spawn;
	struct crypto_alg *alg;
	u32 mask;
	int err;

	err = crypto_check_attr_type(tb, CRYPTO_ALG_TYPE_SKCIPHER);
	if (err)
		return err;

	inst = kzalloc(sizeof(*inst) + sizeof(*spawn), GFP_KERNEL);
	if (!inst)
		return -ENOMEM;

	algt = crypto_get_attr_type(tb);
	err = PTR_ERR(algt);
	if (IS_ERR(algt))
		goto err_free_inst;

	mask = CRYPTO_ALG_TYPE_MASK |
		crypto_requires_off(algt->type, algt->mask,
				    CRYPTO_ALG_NEED_FALLBACK);

	alg = crypto_get_attr_alg(tb, CRYPTO_ALG_TYPE_CIPHER, mask);
	err = PTR_ERR(alg);
	if (IS_ERR(alg))
		goto err_free_inst;

	spawn = skcipher_instance_ctx(inst);
	err = crypto_init_spawn(spawn, alg, skcipher_crypto_instance(inst),
				CRYPTO_ALG_TYPE_MASK);
	if (err)
		goto err_put_alg;

	err = crypto_inst_setname(skcipher_crypto_instance(inst), "cfb", alg);
	if (err)
		goto err_drop_spawn;

	inst->alg.base.cra_priority = alg->cra_priority;
	/* we're a stream cipher independend of the crypto cra_blocksize */
	inst->alg.base.cra_blocksize = 1;
	inst->alg.base.cra_alignmask = alg->cra_alignmask;

	/*
	 * To simplify the implementation, configure the skcipher walk to only
	 * give a partial block at the very end, never earlier.
	 */
	inst->alg.chunksize = alg->cra_blocksize;

	inst->alg.ivsize = alg->cra_blocksize;
	inst->alg.min_keysize = alg->cra_cipher.cia_min_keysize;
	inst->alg.max_keysize = alg->cra_cipher.cia_max_keysize;

	inst->alg.base.cra_ctxsize = sizeof(struct crypto_cfb_ctx);

	inst->alg.init = crypto_cfb_init_tfm;
	inst->alg.exit = crypto_cfb_exit_tfm;

	inst->alg.setkey = crypto_cfb_setkey;
	inst->alg.encrypt = crypto_cfb_encrypt;
	inst->alg.decrypt = crypto_cfb_decrypt;

	inst->free = crypto_cfb_free;

	err = skcipher_register_instance(tmpl, inst);
	if (err)
		goto err_drop_spawn;
	crypto_mod_put(alg);

out:
	return err;

err_drop_spawn:
	crypto_drop_spawn(spawn);
err_put_alg:
	crypto_mod_put(alg);
err_free_inst:
	kfree(inst);
	goto out;
}

