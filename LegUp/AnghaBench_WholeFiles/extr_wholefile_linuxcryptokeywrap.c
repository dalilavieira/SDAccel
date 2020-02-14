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
typedef  int u64 ;
struct scatterlist {unsigned int length; } ;
struct scatter_walk {int dummy; } ;
struct rtattr {int dummy; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_spawn {int dummy; } ;
struct crypto_kw_ctx {struct crypto_instance* child; } ;
struct crypto_kw_block {int /*<<< orphan*/  A; int /*<<< orphan*/  R; } ;
struct TYPE_5__ {unsigned int ivsize; int (* setkey ) (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int) ;int (* encrypt ) (struct blkcipher_desc*,struct scatterlist*,struct scatterlist*,unsigned int) ;int (* decrypt ) (struct blkcipher_desc*,struct scatterlist*,struct scatterlist*,unsigned int) ;int /*<<< orphan*/  max_keysize; int /*<<< orphan*/  min_keysize; } ;
struct TYPE_6__ {unsigned int cra_blocksize; int cra_ctxsize; int (* cra_init ) (struct crypto_tfm*) ;void (* cra_exit ) (struct crypto_tfm*) ;TYPE_2__ cra_blkcipher; int /*<<< orphan*/ * cra_type; scalar_t__ cra_alignmask; int /*<<< orphan*/  cra_priority; int /*<<< orphan*/  cra_flags; } ;
struct TYPE_4__ {int /*<<< orphan*/  cia_max_keysize; int /*<<< orphan*/  cia_min_keysize; } ;
struct crypto_instance {int cra_blocksize; TYPE_3__ alg; TYPE_1__ cra_cipher; int /*<<< orphan*/  cra_priority; } ;
struct crypto_cipher {int cra_blocksize; TYPE_3__ alg; TYPE_1__ cra_cipher; int /*<<< orphan*/  cra_priority; } ;
struct crypto_blkcipher {int dummy; } ;
struct crypto_alg {int cra_blocksize; TYPE_3__ alg; TYPE_1__ cra_cipher; int /*<<< orphan*/  cra_priority; } ;
struct blkcipher_desc {int /*<<< orphan*/ * info; struct crypto_blkcipher* tfm; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  CRYPTO_ALG_TYPE_BLKCIPHER ; 
 int /*<<< orphan*/  CRYPTO_ALG_TYPE_CIPHER ; 
 int /*<<< orphan*/  CRYPTO_ALG_TYPE_MASK ; 
 int CRYPTO_TFM_REQ_MASK ; 
 int CRYPTO_TFM_RES_MASK ; 
 int EBADMSG ; 
 int EINVAL ; 
 struct crypto_instance* ERR_CAST (struct crypto_instance*) ; 
 struct crypto_instance* ERR_PTR (int) ; 
 scalar_t__ IS_ERR (struct crypto_instance*) ; 
 int PTR_ERR (struct crypto_instance*) ; 
 unsigned int SEMIBSIZE ; 
 int /*<<< orphan*/  cpu_to_be64 (int) ; 
 struct crypto_instance* crypto_alloc_instance (char*,struct crypto_instance*) ; 
 struct crypto_kw_ctx* crypto_blkcipher_ctx (struct crypto_blkcipher*) ; 
 int /*<<< orphan*/  crypto_blkcipher_type ; 
 int crypto_check_attr_type (struct rtattr**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_cipher_clear_flags (struct crypto_instance*,int) ; 
 int /*<<< orphan*/  crypto_cipher_decrypt_one (struct crypto_instance*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  crypto_cipher_encrypt_one (struct crypto_instance*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int crypto_cipher_get_flags (struct crypto_instance*) ; 
 int /*<<< orphan*/  crypto_cipher_set_flags (struct crypto_instance*,int) ; 
 int crypto_cipher_setkey (struct crypto_instance*,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  crypto_drop_spawn (struct crypto_spawn*) ; 
 int /*<<< orphan*/  crypto_free_cipher (struct crypto_instance*) ; 
 struct crypto_instance* crypto_get_attr_alg (struct rtattr**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct crypto_spawn* crypto_instance_ctx (struct crypto_instance*) ; 
 int /*<<< orphan*/  crypto_mod_put (struct crypto_instance*) ; 
 struct crypto_instance* crypto_spawn_cipher (struct crypto_spawn*) ; 
 struct crypto_instance* crypto_tfm_alg_instance (struct crypto_tfm*) ; 
 struct crypto_kw_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int crypto_tfm_get_flags (struct crypto_tfm*) ; 
 int /*<<< orphan*/  crypto_tfm_set_flags (struct crypto_tfm*,int) ; 
 int /*<<< orphan*/  kfree (struct crypto_instance*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  memzero_explicit (struct crypto_kw_block*,int) ; 
 int /*<<< orphan*/  scatterwalk_advance (struct scatter_walk*,unsigned int) ; 
 int /*<<< orphan*/  scatterwalk_copychunks (int /*<<< orphan*/ *,struct scatter_walk*,unsigned int,int) ; 
 int /*<<< orphan*/  scatterwalk_start (struct scatter_walk*,struct scatterlist*) ; 
 struct scatterlist* sg_next (struct scatterlist*) ; 

__attribute__((used)) static void crypto_kw_scatterlist_ff(struct scatter_walk *walk,
				     struct scatterlist *sg,
				     unsigned int end)
{
	unsigned int skip = 0;

	/* The caller should only operate on full SEMIBLOCKs. */
	BUG_ON(end < SEMIBSIZE);

	skip = end - SEMIBSIZE;
	while (sg) {
		if (sg->length > skip) {
			scatterwalk_start(walk, sg);
			scatterwalk_advance(walk, skip);
			break;
		} else
			skip -= sg->length;

		sg = sg_next(sg);
	}
}

__attribute__((used)) static int crypto_kw_decrypt(struct blkcipher_desc *desc,
			     struct scatterlist *dst, struct scatterlist *src,
			     unsigned int nbytes)
{
	struct crypto_blkcipher *tfm = desc->tfm;
	struct crypto_kw_ctx *ctx = crypto_blkcipher_ctx(tfm);
	struct crypto_cipher *child = ctx->child;
	struct crypto_kw_block block;
	struct scatterlist *lsrc, *ldst;
	u64 t = 6 * ((nbytes) >> 3);
	unsigned int i;
	int ret = 0;

	/*
	 * Require at least 2 semiblocks (note, the 3rd semiblock that is
	 * required by SP800-38F is the IV.
	 */
	if (nbytes < (2 * SEMIBSIZE) || nbytes % SEMIBSIZE)
		return -EINVAL;

	/* Place the IV into block A */
	memcpy(&block.A, desc->info, SEMIBSIZE);

	/*
	 * src scatterlist is read-only. dst scatterlist is r/w. During the
	 * first loop, lsrc points to src and ldst to dst. For any
	 * subsequent round, the code operates on dst only.
	 */
	lsrc = src;
	ldst = dst;

	for (i = 0; i < 6; i++) {
		struct scatter_walk src_walk, dst_walk;
		unsigned int tmp_nbytes = nbytes;

		while (tmp_nbytes) {
			/* move pointer by tmp_nbytes in the SGL */
			crypto_kw_scatterlist_ff(&src_walk, lsrc, tmp_nbytes);
			/* get the source block */
			scatterwalk_copychunks(&block.R, &src_walk, SEMIBSIZE,
					       false);

			/* perform KW operation: modify IV with counter */
			block.A ^= cpu_to_be64(t);
			t--;
			/* perform KW operation: decrypt block */
			crypto_cipher_decrypt_one(child, (u8*)&block,
						  (u8*)&block);

			/* move pointer by tmp_nbytes in the SGL */
			crypto_kw_scatterlist_ff(&dst_walk, ldst, tmp_nbytes);
			/* Copy block->R into place */
			scatterwalk_copychunks(&block.R, &dst_walk, SEMIBSIZE,
					       true);

			tmp_nbytes -= SEMIBSIZE;
		}

		/* we now start to operate on the dst SGL only */
		lsrc = dst;
		ldst = dst;
	}

	/* Perform authentication check */
	if (block.A != cpu_to_be64(0xa6a6a6a6a6a6a6a6ULL))
		ret = -EBADMSG;

	memzero_explicit(&block, sizeof(struct crypto_kw_block));

	return ret;
}

__attribute__((used)) static int crypto_kw_encrypt(struct blkcipher_desc *desc,
			     struct scatterlist *dst, struct scatterlist *src,
			     unsigned int nbytes)
{
	struct crypto_blkcipher *tfm = desc->tfm;
	struct crypto_kw_ctx *ctx = crypto_blkcipher_ctx(tfm);
	struct crypto_cipher *child = ctx->child;
	struct crypto_kw_block block;
	struct scatterlist *lsrc, *ldst;
	u64 t = 1;
	unsigned int i;

	/*
	 * Require at least 2 semiblocks (note, the 3rd semiblock that is
	 * required by SP800-38F is the IV that occupies the first semiblock.
	 * This means that the dst memory must be one semiblock larger than src.
	 * Also ensure that the given data is aligned to semiblock.
	 */
	if (nbytes < (2 * SEMIBSIZE) || nbytes % SEMIBSIZE)
		return -EINVAL;

	/*
	 * Place the predefined IV into block A -- for encrypt, the caller
	 * does not need to provide an IV, but he needs to fetch the final IV.
	 */
	block.A = cpu_to_be64(0xa6a6a6a6a6a6a6a6ULL);

	/*
	 * src scatterlist is read-only. dst scatterlist is r/w. During the
	 * first loop, lsrc points to src and ldst to dst. For any
	 * subsequent round, the code operates on dst only.
	 */
	lsrc = src;
	ldst = dst;

	for (i = 0; i < 6; i++) {
		struct scatter_walk src_walk, dst_walk;
		unsigned int tmp_nbytes = nbytes;

		scatterwalk_start(&src_walk, lsrc);
		scatterwalk_start(&dst_walk, ldst);

		while (tmp_nbytes) {
			/* get the source block */
			scatterwalk_copychunks(&block.R, &src_walk, SEMIBSIZE,
					       false);

			/* perform KW operation: encrypt block */
			crypto_cipher_encrypt_one(child, (u8 *)&block,
						  (u8 *)&block);
			/* perform KW operation: modify IV with counter */
			block.A ^= cpu_to_be64(t);
			t++;

			/* Copy block->R into place */
			scatterwalk_copychunks(&block.R, &dst_walk, SEMIBSIZE,
					       true);

			tmp_nbytes -= SEMIBSIZE;
		}

		/* we now start to operate on the dst SGL only */
		lsrc = dst;
		ldst = dst;
	}

	/* establish the IV for the caller to pick up */
	memcpy(desc->info, &block.A, SEMIBSIZE);

	memzero_explicit(&block, sizeof(struct crypto_kw_block));

	return 0;
}

__attribute__((used)) static int crypto_kw_setkey(struct crypto_tfm *parent, const u8 *key,
			    unsigned int keylen)
{
	struct crypto_kw_ctx *ctx = crypto_tfm_ctx(parent);
	struct crypto_cipher *child = ctx->child;
	int err;

	crypto_cipher_clear_flags(child, CRYPTO_TFM_REQ_MASK);
	crypto_cipher_set_flags(child, crypto_tfm_get_flags(parent) &
				       CRYPTO_TFM_REQ_MASK);
	err = crypto_cipher_setkey(child, key, keylen);
	crypto_tfm_set_flags(parent, crypto_cipher_get_flags(child) &
				     CRYPTO_TFM_RES_MASK);
	return err;
}

__attribute__((used)) static int crypto_kw_init_tfm(struct crypto_tfm *tfm)
{
	struct crypto_instance *inst = crypto_tfm_alg_instance(tfm);
	struct crypto_spawn *spawn = crypto_instance_ctx(inst);
	struct crypto_kw_ctx *ctx = crypto_tfm_ctx(tfm);
	struct crypto_cipher *cipher;

	cipher = crypto_spawn_cipher(spawn);
	if (IS_ERR(cipher))
		return PTR_ERR(cipher);

	ctx->child = cipher;
	return 0;
}

__attribute__((used)) static void crypto_kw_exit_tfm(struct crypto_tfm *tfm)
{
	struct crypto_kw_ctx *ctx = crypto_tfm_ctx(tfm);

	crypto_free_cipher(ctx->child);
}

__attribute__((used)) static struct crypto_instance *crypto_kw_alloc(struct rtattr **tb)
{
	struct crypto_instance *inst = NULL;
	struct crypto_alg *alg = NULL;
	int err;

	err = crypto_check_attr_type(tb, CRYPTO_ALG_TYPE_BLKCIPHER);
	if (err)
		return ERR_PTR(err);

	alg = crypto_get_attr_alg(tb, CRYPTO_ALG_TYPE_CIPHER,
				  CRYPTO_ALG_TYPE_MASK);
	if (IS_ERR(alg))
		return ERR_CAST(alg);

	inst = ERR_PTR(-EINVAL);
	/* Section 5.1 requirement for KW */
	if (alg->cra_blocksize != sizeof(struct crypto_kw_block))
		goto err;

	inst = crypto_alloc_instance("kw", alg);
	if (IS_ERR(inst))
		goto err;

	inst->alg.cra_flags = CRYPTO_ALG_TYPE_BLKCIPHER;
	inst->alg.cra_priority = alg->cra_priority;
	inst->alg.cra_blocksize = SEMIBSIZE;
	inst->alg.cra_alignmask = 0;
	inst->alg.cra_type = &crypto_blkcipher_type;
	inst->alg.cra_blkcipher.ivsize = SEMIBSIZE;
	inst->alg.cra_blkcipher.min_keysize = alg->cra_cipher.cia_min_keysize;
	inst->alg.cra_blkcipher.max_keysize = alg->cra_cipher.cia_max_keysize;

	inst->alg.cra_ctxsize = sizeof(struct crypto_kw_ctx);

	inst->alg.cra_init = crypto_kw_init_tfm;
	inst->alg.cra_exit = crypto_kw_exit_tfm;

	inst->alg.cra_blkcipher.setkey = crypto_kw_setkey;
	inst->alg.cra_blkcipher.encrypt = crypto_kw_encrypt;
	inst->alg.cra_blkcipher.decrypt = crypto_kw_decrypt;

err:
	crypto_mod_put(alg);
	return inst;
}

__attribute__((used)) static void crypto_kw_free(struct crypto_instance *inst)
{
	crypto_drop_spawn(crypto_instance_ctx(inst));
	kfree(inst);
}

