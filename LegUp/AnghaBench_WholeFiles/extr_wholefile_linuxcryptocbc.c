#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct skcipher_walk {scalar_t__ nbytes; } ;
struct skcipher_request {int dummy; } ;
struct TYPE_5__ {int cra_ctxsize; int /*<<< orphan*/  cra_alignmask; int /*<<< orphan*/  cra_blocksize; int /*<<< orphan*/  cra_priority; } ;
struct TYPE_6__ {int (* init ) (struct crypto_skcipher*) ;void (* exit ) (struct crypto_skcipher*) ;int (* setkey ) (struct crypto_skcipher*,int /*<<< orphan*/  const*,unsigned int) ;int (* encrypt ) (struct skcipher_request*) ;int (* decrypt ) (struct skcipher_request*) ;TYPE_2__ base; int /*<<< orphan*/  max_keysize; int /*<<< orphan*/  min_keysize; int /*<<< orphan*/  ivsize; } ;
struct skcipher_instance {void (* free ) (struct skcipher_instance*) ;TYPE_3__ alg; } ;
struct rtattr {int dummy; } ;
struct crypto_template {int dummy; } ;
struct crypto_spawn {int dummy; } ;
struct crypto_skcipher {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  cia_max_keysize; int /*<<< orphan*/  cia_min_keysize; } ;
struct crypto_cipher {TYPE_1__ cra_cipher; int /*<<< orphan*/  cra_blocksize; int /*<<< orphan*/  cra_alignmask; int /*<<< orphan*/  cra_priority; int /*<<< orphan*/  mask; int /*<<< orphan*/  type; } ;
struct crypto_cbc_ctx {struct crypto_cipher* child; } ;
struct crypto_attr_type {TYPE_1__ cra_cipher; int /*<<< orphan*/  cra_blocksize; int /*<<< orphan*/  cra_alignmask; int /*<<< orphan*/  cra_priority; int /*<<< orphan*/  mask; int /*<<< orphan*/  type; } ;
struct crypto_alg {TYPE_1__ cra_cipher; int /*<<< orphan*/  cra_blocksize; int /*<<< orphan*/  cra_alignmask; int /*<<< orphan*/  cra_priority; int /*<<< orphan*/  mask; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_ALG_NEED_FALLBACK ; 
 int /*<<< orphan*/  CRYPTO_ALG_TYPE_CIPHER ; 
 int CRYPTO_ALG_TYPE_MASK ; 
 int /*<<< orphan*/  CRYPTO_ALG_TYPE_SKCIPHER ; 
 int CRYPTO_TFM_REQ_MASK ; 
 int CRYPTO_TFM_RES_MASK ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct crypto_cipher*) ; 
 int PTR_ERR (struct crypto_cipher*) ; 
 int crypto_cbc_decrypt_blocks (struct skcipher_walk*,struct crypto_skcipher*,void (*) (struct crypto_skcipher*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *)) ; 
 int crypto_cbc_encrypt_walk (struct skcipher_request*,void (*) (struct crypto_skcipher*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *)) ; 
 int crypto_check_attr_type (struct rtattr**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_cipher_clear_flags (struct crypto_cipher*,int) ; 
 int /*<<< orphan*/  crypto_cipher_decrypt_one (struct crypto_cipher*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
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
 struct crypto_cbc_ctx* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 int crypto_skcipher_get_flags (struct crypto_skcipher*) ; 
 struct crypto_skcipher* crypto_skcipher_reqtfm (struct skcipher_request*) ; 
 int /*<<< orphan*/  crypto_skcipher_set_flags (struct crypto_skcipher*,int) ; 
 struct crypto_cipher* crypto_spawn_cipher (struct crypto_spawn*) ; 
 int /*<<< orphan*/  is_power_of_2 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct skcipher_instance*) ; 
 struct skcipher_instance* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct skcipher_instance* skcipher_alg_instance (struct crypto_skcipher*) ; 
 int /*<<< orphan*/  skcipher_crypto_instance (struct skcipher_instance*) ; 
 struct crypto_spawn* skcipher_instance_ctx (struct skcipher_instance*) ; 
 int skcipher_register_instance (struct crypto_template*,struct skcipher_instance*) ; 
 int skcipher_walk_done (struct skcipher_walk*,int) ; 
 int skcipher_walk_virt (struct skcipher_walk*,struct skcipher_request*,int) ; 

__attribute__((used)) static int crypto_cbc_setkey(struct crypto_skcipher *parent, const u8 *key,
			     unsigned int keylen)
{
	struct crypto_cbc_ctx *ctx = crypto_skcipher_ctx(parent);
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

__attribute__((used)) static inline void crypto_cbc_encrypt_one(struct crypto_skcipher *tfm,
					  const u8 *src, u8 *dst)
{
	struct crypto_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);

	crypto_cipher_encrypt_one(ctx->child, dst, src);
}

__attribute__((used)) static int crypto_cbc_encrypt(struct skcipher_request *req)
{
	return crypto_cbc_encrypt_walk(req, crypto_cbc_encrypt_one);
}

__attribute__((used)) static inline void crypto_cbc_decrypt_one(struct crypto_skcipher *tfm,
					  const u8 *src, u8 *dst)
{
	struct crypto_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);

	crypto_cipher_decrypt_one(ctx->child, dst, src);
}

__attribute__((used)) static int crypto_cbc_decrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct skcipher_walk walk;
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while (walk.nbytes) {
		err = crypto_cbc_decrypt_blocks(&walk, tfm,
						crypto_cbc_decrypt_one);
		err = skcipher_walk_done(&walk, err);
	}

	return err;
}

__attribute__((used)) static int crypto_cbc_init_tfm(struct crypto_skcipher *tfm)
{
	struct skcipher_instance *inst = skcipher_alg_instance(tfm);
	struct crypto_spawn *spawn = skcipher_instance_ctx(inst);
	struct crypto_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct crypto_cipher *cipher;

	cipher = crypto_spawn_cipher(spawn);
	if (IS_ERR(cipher))
		return PTR_ERR(cipher);

	ctx->child = cipher;
	return 0;
}

__attribute__((used)) static void crypto_cbc_exit_tfm(struct crypto_skcipher *tfm)
{
	struct crypto_cbc_ctx *ctx = crypto_skcipher_ctx(tfm);

	crypto_free_cipher(ctx->child);
}

__attribute__((used)) static void crypto_cbc_free(struct skcipher_instance *inst)
{
	crypto_drop_skcipher(skcipher_instance_ctx(inst));
	kfree(inst);
}

__attribute__((used)) static int crypto_cbc_create(struct crypto_template *tmpl, struct rtattr **tb)
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

	err = crypto_inst_setname(skcipher_crypto_instance(inst), "cbc", alg);
	if (err)
		goto err_drop_spawn;

	err = -EINVAL;
	if (!is_power_of_2(alg->cra_blocksize))
		goto err_drop_spawn;

	inst->alg.base.cra_priority = alg->cra_priority;
	inst->alg.base.cra_blocksize = alg->cra_blocksize;
	inst->alg.base.cra_alignmask = alg->cra_alignmask;

	inst->alg.ivsize = alg->cra_blocksize;
	inst->alg.min_keysize = alg->cra_cipher.cia_min_keysize;
	inst->alg.max_keysize = alg->cra_cipher.cia_max_keysize;

	inst->alg.base.cra_ctxsize = sizeof(struct crypto_cbc_ctx);

	inst->alg.init = crypto_cbc_init_tfm;
	inst->alg.exit = crypto_cbc_exit_tfm;

	inst->alg.setkey = crypto_cbc_setkey;
	inst->alg.encrypt = crypto_cbc_encrypt;
	inst->alg.decrypt = crypto_cbc_decrypt;

	inst->free = crypto_cbc_free;

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

