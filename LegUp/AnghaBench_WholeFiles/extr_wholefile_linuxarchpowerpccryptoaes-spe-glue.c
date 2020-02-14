#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct scatterlist {int dummy; } ;
struct ppc_xts_ctx {int rounds; int /*<<< orphan*/  key_dec; int /*<<< orphan*/ * key_twk; int /*<<< orphan*/ * key_enc; } ;
struct ppc_aes_ctx {int rounds; int /*<<< orphan*/ * key_enc; int /*<<< orphan*/  key_dec; } ;
struct crypto_tfm {int /*<<< orphan*/  crt_flags; } ;
struct TYPE_7__ {int /*<<< orphan*/  addr; } ;
struct TYPE_8__ {TYPE_3__ virt; } ;
struct TYPE_5__ {int /*<<< orphan*/  addr; } ;
struct TYPE_6__ {TYPE_1__ virt; } ;
struct blkcipher_walk {unsigned int nbytes; int /*<<< orphan*/  iv; TYPE_4__ src; TYPE_2__ dst; } ;
struct blkcipher_desc {int /*<<< orphan*/  flags; int /*<<< orphan*/  tfm; } ;

/* Variables and functions */
 int AES_BLOCK_SIZE ; 
#define  AES_KEYSIZE_128 130 
#define  AES_KEYSIZE_192 129 
#define  AES_KEYSIZE_256 128 
 int /*<<< orphan*/  CRYPTO_TFM_REQ_MAY_SLEEP ; 
 int /*<<< orphan*/  CRYPTO_TFM_RES_BAD_KEY_LEN ; 
 int EINVAL ; 
 unsigned int MAX_BYTES ; 
 int blkcipher_walk_done (struct blkcipher_desc*,struct blkcipher_walk*,unsigned int) ; 
 int /*<<< orphan*/  blkcipher_walk_init (struct blkcipher_walk*,struct scatterlist*,struct scatterlist*,unsigned int) ; 
 int blkcipher_walk_virt (struct blkcipher_desc*,struct blkcipher_walk*) ; 
 int blkcipher_walk_virt_block (struct blkcipher_desc*,struct blkcipher_walk*,int) ; 
 void* crypto_blkcipher_ctx (int /*<<< orphan*/ ) ; 
 void* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  disable_kernel_spe () ; 
 int /*<<< orphan*/  enable_kernel_spe () ; 
 int /*<<< orphan*/  ppc_crypt_ctr (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ppc_decrypt_aes (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ppc_decrypt_cbc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ppc_decrypt_ecb (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned int) ; 
 int /*<<< orphan*/  ppc_decrypt_xts (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ppc_encrypt_aes (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ppc_encrypt_cbc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ppc_encrypt_ecb (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,unsigned int) ; 
 int /*<<< orphan*/  ppc_encrypt_xts (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ppc_expand_key_128 (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ppc_expand_key_192 (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ppc_expand_key_256 (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ppc_generate_decrypt_key (int /*<<< orphan*/ ,int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int xts_check_key (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int) ; 

__attribute__((used)) static void spe_begin(void)
{
	/* disable preemption and save users SPE registers if required */
	preempt_disable();
	enable_kernel_spe();
}

__attribute__((used)) static void spe_end(void)
{
	disable_kernel_spe();
	/* reenable preemption */
	preempt_enable();
}

__attribute__((used)) static int ppc_aes_setkey(struct crypto_tfm *tfm, const u8 *in_key,
		unsigned int key_len)
{
	struct ppc_aes_ctx *ctx = crypto_tfm_ctx(tfm);

	if (key_len != AES_KEYSIZE_128 &&
	    key_len != AES_KEYSIZE_192 &&
	    key_len != AES_KEYSIZE_256) {
		tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
		return -EINVAL;
	}

	switch (key_len) {
	case AES_KEYSIZE_128:
		ctx->rounds = 4;
		ppc_expand_key_128(ctx->key_enc, in_key);
		break;
	case AES_KEYSIZE_192:
		ctx->rounds = 5;
		ppc_expand_key_192(ctx->key_enc, in_key);
		break;
	case AES_KEYSIZE_256:
		ctx->rounds = 6;
		ppc_expand_key_256(ctx->key_enc, in_key);
		break;
	}

	ppc_generate_decrypt_key(ctx->key_dec, ctx->key_enc, key_len);

	return 0;
}

__attribute__((used)) static int ppc_xts_setkey(struct crypto_tfm *tfm, const u8 *in_key,
		   unsigned int key_len)
{
	struct ppc_xts_ctx *ctx = crypto_tfm_ctx(tfm);
	int err;

	err = xts_check_key(tfm, in_key, key_len);
	if (err)
		return err;

	key_len >>= 1;

	if (key_len != AES_KEYSIZE_128 &&
	    key_len != AES_KEYSIZE_192 &&
	    key_len != AES_KEYSIZE_256) {
		tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
		return -EINVAL;
	}

	switch (key_len) {
	case AES_KEYSIZE_128:
		ctx->rounds = 4;
		ppc_expand_key_128(ctx->key_enc, in_key);
		ppc_expand_key_128(ctx->key_twk, in_key + AES_KEYSIZE_128);
		break;
	case AES_KEYSIZE_192:
		ctx->rounds = 5;
		ppc_expand_key_192(ctx->key_enc, in_key);
		ppc_expand_key_192(ctx->key_twk, in_key + AES_KEYSIZE_192);
		break;
	case AES_KEYSIZE_256:
		ctx->rounds = 6;
		ppc_expand_key_256(ctx->key_enc, in_key);
		ppc_expand_key_256(ctx->key_twk, in_key + AES_KEYSIZE_256);
		break;
	}

	ppc_generate_decrypt_key(ctx->key_dec, ctx->key_enc, key_len);

	return 0;
}

__attribute__((used)) static void ppc_aes_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
	struct ppc_aes_ctx *ctx = crypto_tfm_ctx(tfm);

	spe_begin();
	ppc_encrypt_aes(out, in, ctx->key_enc, ctx->rounds);
	spe_end();
}

__attribute__((used)) static void ppc_aes_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
	struct ppc_aes_ctx *ctx = crypto_tfm_ctx(tfm);

	spe_begin();
	ppc_decrypt_aes(out, in, ctx->key_dec, ctx->rounds);
	spe_end();
}

__attribute__((used)) static int ppc_ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
			   struct scatterlist *src, unsigned int nbytes)
{
	struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	unsigned int ubytes;
	int err;

	desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		ubytes = nbytes > MAX_BYTES ?
			 nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
		nbytes -= ubytes;

		spe_begin();
		ppc_encrypt_ecb(walk.dst.virt.addr, walk.src.virt.addr,
				ctx->key_enc, ctx->rounds, nbytes);
		spe_end();

		err = blkcipher_walk_done(desc, &walk, ubytes);
	}

	return err;
}

__attribute__((used)) static int ppc_ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
			   struct scatterlist *src, unsigned int nbytes)
{
	struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	unsigned int ubytes;
	int err;

	desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		ubytes = nbytes > MAX_BYTES ?
			 nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
		nbytes -= ubytes;

		spe_begin();
		ppc_decrypt_ecb(walk.dst.virt.addr, walk.src.virt.addr,
				ctx->key_dec, ctx->rounds, nbytes);
		spe_end();

		err = blkcipher_walk_done(desc, &walk, ubytes);
	}

	return err;
}

__attribute__((used)) static int ppc_cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
			   struct scatterlist *src, unsigned int nbytes)
{
	struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	unsigned int ubytes;
	int err;

	desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		ubytes = nbytes > MAX_BYTES ?
			 nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
		nbytes -= ubytes;

		spe_begin();
		ppc_encrypt_cbc(walk.dst.virt.addr, walk.src.virt.addr,
				ctx->key_enc, ctx->rounds, nbytes, walk.iv);
		spe_end();

		err = blkcipher_walk_done(desc, &walk, ubytes);
	}

	return err;
}

__attribute__((used)) static int ppc_cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
			   struct scatterlist *src, unsigned int nbytes)
{
	struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	unsigned int ubytes;
	int err;

	desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		ubytes = nbytes > MAX_BYTES ?
			 nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
		nbytes -= ubytes;

		spe_begin();
		ppc_decrypt_cbc(walk.dst.virt.addr, walk.src.virt.addr,
				ctx->key_dec, ctx->rounds, nbytes, walk.iv);
		spe_end();

		err = blkcipher_walk_done(desc, &walk, ubytes);
	}

	return err;
}

__attribute__((used)) static int ppc_ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
			 struct scatterlist *src, unsigned int nbytes)
{
	struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	unsigned int pbytes, ubytes;
	int err;

	desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt_block(desc, &walk, AES_BLOCK_SIZE);

	while ((pbytes = walk.nbytes)) {
		pbytes = pbytes > MAX_BYTES ? MAX_BYTES : pbytes;
		pbytes = pbytes == nbytes ?
			 nbytes : pbytes & ~(AES_BLOCK_SIZE - 1);
		ubytes = walk.nbytes - pbytes;

		spe_begin();
		ppc_crypt_ctr(walk.dst.virt.addr, walk.src.virt.addr,
			      ctx->key_enc, ctx->rounds, pbytes , walk.iv);
		spe_end();

		nbytes -= pbytes;
		err = blkcipher_walk_done(desc, &walk, ubytes);
	}

	return err;
}

__attribute__((used)) static int ppc_xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
			   struct scatterlist *src, unsigned int nbytes)
{
	struct ppc_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	unsigned int ubytes;
	int err;
	u32 *twk;

	desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);
	twk = ctx->key_twk;

	while ((nbytes = walk.nbytes)) {
		ubytes = nbytes > MAX_BYTES ?
			 nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
		nbytes -= ubytes;

		spe_begin();
		ppc_encrypt_xts(walk.dst.virt.addr, walk.src.virt.addr,
				ctx->key_enc, ctx->rounds, nbytes, walk.iv, twk);
		spe_end();

		twk = NULL;
		err = blkcipher_walk_done(desc, &walk, ubytes);
	}

	return err;
}

__attribute__((used)) static int ppc_xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
			   struct scatterlist *src, unsigned int nbytes)
{
	struct ppc_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	unsigned int ubytes;
	int err;
	u32 *twk;

	desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);
	twk = ctx->key_twk;

	while ((nbytes = walk.nbytes)) {
		ubytes = nbytes > MAX_BYTES ?
			 nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
		nbytes -= ubytes;

		spe_begin();
		ppc_decrypt_xts(walk.dst.virt.addr, walk.src.virt.addr,
				ctx->key_dec, ctx->rounds, nbytes, walk.iv, twk);
		spe_end();

		twk = NULL;
		err = blkcipher_walk_done(desc, &walk, ubytes);
	}

	return err;
}

