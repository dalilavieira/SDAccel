#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_9__ ;
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct scatterlist {int dummy; } ;
struct TYPE_14__ {int /*<<< orphan*/  processed_byte_count; } ;
struct TYPE_12__ {int const* cv; } ;
struct TYPE_11__ {int* key; int /*<<< orphan*/  iv; } ;
struct TYPE_10__ {int /*<<< orphan*/  mode; } ;
struct TYPE_13__ {TYPE_3__ aes_cbc; TYPE_2__ aes_ctr; TYPE_1__ hdr; } ;
struct nx_csbcpb {TYPE_5__ csb; TYPE_4__ cpb; } ;
struct TYPE_16__ {int* nonce; } ;
struct TYPE_17__ {TYPE_7__ ctr; } ;
struct TYPE_18__ {int /*<<< orphan*/  outlen; int /*<<< orphan*/  inlen; } ;
struct nx_crypto_ctx {TYPE_8__ priv; int /*<<< orphan*/  lock; TYPE_6__* stats; TYPE_9__ op; struct nx_csbcpb* csbcpb; int /*<<< orphan*/ * props; int /*<<< orphan*/ * ap; } ;
struct crypto_tfm {int dummy; } ;
struct blkcipher_desc {int flags; int* info; int /*<<< orphan*/  tfm; } ;
struct TYPE_15__ {int /*<<< orphan*/  aes_bytes; int /*<<< orphan*/  aes_ops; } ;

/* Variables and functions */
 unsigned int AES_BLOCK_SIZE ; 
#define  AES_KEYSIZE_128 130 
#define  AES_KEYSIZE_192 129 
#define  AES_KEYSIZE_256 128 
 int CRYPTO_TFM_REQ_MAY_SLEEP ; 
 unsigned int CTR_RFC3686_IV_SIZE ; 
 unsigned int CTR_RFC3686_NONCE_SIZE ; 
 int EINVAL ; 
 int /*<<< orphan*/  HCOP_FC_AES ; 
 int /*<<< orphan*/  NX_CPB_SET_KEY_SIZE (struct nx_csbcpb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NX_KS_AES_128 ; 
 int /*<<< orphan*/  NX_KS_AES_192 ; 
 int /*<<< orphan*/  NX_KS_AES_256 ; 
 int /*<<< orphan*/  NX_MODE_AES_CTR ; 
 size_t NX_PROPS_AES_128 ; 
 size_t NX_PROPS_AES_192 ; 
 size_t NX_PROPS_AES_256 ; 
 int /*<<< orphan*/  atomic64_add (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 struct nx_crypto_ctx* crypto_blkcipher_ctx (int /*<<< orphan*/ ) ; 
 struct nx_crypto_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  memcpy (int*,int const*,unsigned int) ; 
 int nx_build_sg_lists (struct nx_crypto_ctx*,struct blkcipher_desc*,struct scatterlist*,struct scatterlist*,unsigned int*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nx_ctx_init (struct nx_crypto_ctx*,int /*<<< orphan*/ ) ; 
 int nx_hcall_sync (struct nx_crypto_ctx*,TYPE_9__*,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int ctr_aes_nx_set_key(struct crypto_tfm *tfm,
			      const u8          *in_key,
			      unsigned int       key_len)
{
	struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(tfm);
	struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;

	nx_ctx_init(nx_ctx, HCOP_FC_AES);

	switch (key_len) {
	case AES_KEYSIZE_128:
		NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_128);
		nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_128];
		break;
	case AES_KEYSIZE_192:
		NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_192);
		nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_192];
		break;
	case AES_KEYSIZE_256:
		NX_CPB_SET_KEY_SIZE(csbcpb, NX_KS_AES_256);
		nx_ctx->ap = &nx_ctx->props[NX_PROPS_AES_256];
		break;
	default:
		return -EINVAL;
	}

	csbcpb->cpb.hdr.mode = NX_MODE_AES_CTR;
	memcpy(csbcpb->cpb.aes_ctr.key, in_key, key_len);

	return 0;
}

__attribute__((used)) static int ctr3686_aes_nx_set_key(struct crypto_tfm *tfm,
				  const u8          *in_key,
				  unsigned int       key_len)
{
	struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(tfm);

	if (key_len < CTR_RFC3686_NONCE_SIZE)
		return -EINVAL;

	memcpy(nx_ctx->priv.ctr.nonce,
	       in_key + key_len - CTR_RFC3686_NONCE_SIZE,
	       CTR_RFC3686_NONCE_SIZE);

	key_len -= CTR_RFC3686_NONCE_SIZE;

	return ctr_aes_nx_set_key(tfm, in_key, key_len);
}

__attribute__((used)) static int ctr_aes_nx_crypt(struct blkcipher_desc *desc,
			    struct scatterlist    *dst,
			    struct scatterlist    *src,
			    unsigned int           nbytes)
{
	struct nx_crypto_ctx *nx_ctx = crypto_blkcipher_ctx(desc->tfm);
	struct nx_csbcpb *csbcpb = nx_ctx->csbcpb;
	unsigned long irq_flags;
	unsigned int processed = 0, to_process;
	int rc;

	spin_lock_irqsave(&nx_ctx->lock, irq_flags);

	do {
		to_process = nbytes - processed;

		rc = nx_build_sg_lists(nx_ctx, desc, dst, src, &to_process,
				       processed, csbcpb->cpb.aes_ctr.iv);
		if (rc)
			goto out;

		if (!nx_ctx->op.inlen || !nx_ctx->op.outlen) {
			rc = -EINVAL;
			goto out;
		}

		rc = nx_hcall_sync(nx_ctx, &nx_ctx->op,
				   desc->flags & CRYPTO_TFM_REQ_MAY_SLEEP);
		if (rc)
			goto out;

		memcpy(desc->info, csbcpb->cpb.aes_cbc.cv, AES_BLOCK_SIZE);

		atomic_inc(&(nx_ctx->stats->aes_ops));
		atomic64_add(csbcpb->csb.processed_byte_count,
			     &(nx_ctx->stats->aes_bytes));

		processed += to_process;
	} while (processed < nbytes);
out:
	spin_unlock_irqrestore(&nx_ctx->lock, irq_flags);
	return rc;
}

__attribute__((used)) static int ctr3686_aes_nx_crypt(struct blkcipher_desc *desc,
				struct scatterlist    *dst,
				struct scatterlist    *src,
				unsigned int           nbytes)
{
	struct nx_crypto_ctx *nx_ctx = crypto_blkcipher_ctx(desc->tfm);
	u8 iv[16];

	memcpy(iv, nx_ctx->priv.ctr.nonce, CTR_RFC3686_IV_SIZE);
	memcpy(iv + CTR_RFC3686_NONCE_SIZE,
	       desc->info, CTR_RFC3686_IV_SIZE);
	iv[12] = iv[13] = iv[14] = 0;
	iv[15] = 1;

	desc->info = iv;

	return ctr_aes_nx_crypt(desc, dst, src, nbytes);
}

