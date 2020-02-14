#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u64 ;
struct TYPE_9__ {int flags; } ;
struct skcipher_request {int cryptlen; int /*<<< orphan*/  dst; int /*<<< orphan*/  src; int /*<<< orphan*/  const* iv; TYPE_1__ base; } ;
struct TYPE_11__ {int ctxl; int /*<<< orphan*/  arg; } ;
struct TYPE_12__ {TYPE_3__ s; scalar_t__ value; } ;
struct TYPE_10__ {scalar_t__ param3; void* param2; scalar_t__ param1; void* param0; } ;
struct se_crypto_request {int flags; uintptr_t ctx_handle; int ivsize; int /*<<< orphan*/  dst; int /*<<< orphan*/  src; int /*<<< orphan*/  iv; TYPE_4__ ctrl; TYPE_2__ gph; int /*<<< orphan*/  opcode; int /*<<< orphan*/  gfp; } ;
struct nitrox_kcrypt_request {struct skcipher_request* skreq; struct nitrox_crypto_ctx* nctx; struct se_crypto_request creq; } ;
struct nitrox_device {int /*<<< orphan*/  status; scalar_t__ bar_addr; } ;
struct TYPE_13__ {uintptr_t ctx_handle; struct flexi_crypto_context* fctx; } ;
struct nitrox_crypto_ctx {TYPE_5__ u; int /*<<< orphan*/ * ndev; struct crypto_ctx_hdr* chdr; } ;
struct nitrox_cipher {int value; scalar_t__ name; } ;
struct TYPE_15__ {int /*<<< orphan*/  key2; int /*<<< orphan*/  key; } ;
struct TYPE_16__ {int /*<<< orphan*/  iv; TYPE_7__ u; } ;
struct TYPE_14__ {int cipher_type; int aes_keylen; int /*<<< orphan*/  iv_source; } ;
struct flexi_crypto_context {TYPE_8__ crypto; TYPE_8__ auth; TYPE_6__ w0; scalar_t__ flags; } ;
struct ctx_hdr {int dummy; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_skcipher {int dummy; } ;
struct crypto_keys {int dummy; } ;
struct crypto_ctx_hdr {scalar_t__ vaddr; } ;
struct auth_keys {int dummy; } ;
typedef  enum flexi_cipher { ____Placeholder_flexi_cipher } flexi_cipher ;

/* Variables and functions */
#define  AES_KEYSIZE_128 130 
#define  AES_KEYSIZE_192 129 
#define  AES_KEYSIZE_256 128 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int CIPHER_INVALID ; 
 int CRYPTO_TFM_REQ_MAY_SLEEP ; 
 int /*<<< orphan*/  CRYPTO_TFM_RES_BAD_KEY_LEN ; 
 unsigned int CTR_RFC3686_NONCE_SIZE ; 
 int /*<<< orphan*/  DECRYPT ; 
 unsigned int DES3_EDE_KEY_SIZE ; 
 int EINVAL ; 
 int /*<<< orphan*/  ENCRYPT ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FLEXI_CRYPTO_ENCRYPT_HMAC ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IV_FROM_DPTR ; 
 int /*<<< orphan*/  NITROX_READY ; 
 void* cpu_to_be16 (int) ; 
 scalar_t__ cpu_to_be64 (scalar_t__) ; 
 struct crypto_ctx_hdr* crypto_alloc_context (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  crypto_free_context (void*) ; 
 int crypto_register_skciphers (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct nitrox_crypto_ctx* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 int crypto_skcipher_ivsize (struct crypto_skcipher*) ; 
 scalar_t__ crypto_skcipher_reqsize (struct crypto_skcipher*) ; 
 struct crypto_skcipher* crypto_skcipher_reqtfm (struct skcipher_request*) ; 
 int /*<<< orphan*/  crypto_skcipher_set_flags (struct crypto_skcipher*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_skcipher_set_reqsize (struct crypto_skcipher*,scalar_t__) ; 
 struct crypto_tfm* crypto_skcipher_tfm (struct crypto_skcipher*) ; 
 char* crypto_tfm_alg_name (struct crypto_tfm*) ; 
 struct nitrox_crypto_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  crypto_unregister_skciphers (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct nitrox_cipher* flexi_cipher_table ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  memset (TYPE_8__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * nitrox_get_first_device () ; 
 int nitrox_process_se_request (int /*<<< orphan*/ *,struct se_crypto_request*,void (*) (struct skcipher_request*,int),struct skcipher_request*) ; 
 int /*<<< orphan*/  nitrox_put_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nitrox_skciphers ; 
 int /*<<< orphan*/  pr_err (char*,char const*) ; 
 int /*<<< orphan*/  pr_err_ratelimited (char*,int) ; 
 scalar_t__ readq (scalar_t__) ; 
 int /*<<< orphan*/  skcipher_request_complete (struct skcipher_request*,int) ; 
 struct nitrox_kcrypt_request* skcipher_request_ctx (struct skcipher_request*) ; 
 int /*<<< orphan*/  strcmp (scalar_t__,char const*) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writeq (scalar_t__,scalar_t__) ; 
 int xts_check_key (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int) ; 

__attribute__((used)) static inline u64 nitrox_read_csr(struct nitrox_device *ndev, u64 offset)
{
	return readq(ndev->bar_addr + offset);
}

__attribute__((used)) static inline void nitrox_write_csr(struct nitrox_device *ndev, u64 offset,
				    u64 value)
{
	writeq(value, (ndev->bar_addr + offset));
}

__attribute__((used)) static inline int nitrox_ready(struct nitrox_device *ndev)
{
	return test_bit(NITROX_READY, &ndev->status);
}

__attribute__((used)) static enum flexi_cipher flexi_cipher_type(const char *name)
{
	const struct nitrox_cipher *cipher = flexi_cipher_table;

	while (cipher->name) {
		if (!strcmp(cipher->name, name))
			break;
		cipher++;
	}
	return cipher->value;
}

__attribute__((used)) static int flexi_aes_keylen(int keylen)
{
	int aes_keylen;

	switch (keylen) {
	case AES_KEYSIZE_128:
		aes_keylen = 1;
		break;
	case AES_KEYSIZE_192:
		aes_keylen = 2;
		break;
	case AES_KEYSIZE_256:
		aes_keylen = 3;
		break;
	default:
		aes_keylen = -EINVAL;
		break;
	}
	return aes_keylen;
}

__attribute__((used)) static int nitrox_skcipher_init(struct crypto_skcipher *tfm)
{
	struct nitrox_crypto_ctx *nctx = crypto_skcipher_ctx(tfm);
	struct crypto_ctx_hdr *chdr;

	/* get the first device */
	nctx->ndev = nitrox_get_first_device();
	if (!nctx->ndev)
		return -ENODEV;

	/* allocate nitrox crypto context */
	chdr = crypto_alloc_context(nctx->ndev);
	if (!chdr) {
		nitrox_put_device(nctx->ndev);
		return -ENOMEM;
	}
	nctx->chdr = chdr;
	nctx->u.ctx_handle = (uintptr_t)((u8 *)chdr->vaddr +
					 sizeof(struct ctx_hdr));
	crypto_skcipher_set_reqsize(tfm, crypto_skcipher_reqsize(tfm) +
				    sizeof(struct nitrox_kcrypt_request));
	return 0;
}

__attribute__((used)) static void nitrox_skcipher_exit(struct crypto_skcipher *tfm)
{
	struct nitrox_crypto_ctx *nctx = crypto_skcipher_ctx(tfm);

	/* free the nitrox crypto context */
	if (nctx->u.ctx_handle) {
		struct flexi_crypto_context *fctx = nctx->u.fctx;

		memset(&fctx->crypto, 0, sizeof(struct crypto_keys));
		memset(&fctx->auth, 0, sizeof(struct auth_keys));
		crypto_free_context((void *)nctx->chdr);
	}
	nitrox_put_device(nctx->ndev);

	nctx->u.ctx_handle = 0;
	nctx->ndev = NULL;
}

__attribute__((used)) static inline int nitrox_skcipher_setkey(struct crypto_skcipher *cipher,
					 int aes_keylen, const u8 *key,
					 unsigned int keylen)
{
	struct crypto_tfm *tfm = crypto_skcipher_tfm(cipher);
	struct nitrox_crypto_ctx *nctx = crypto_tfm_ctx(tfm);
	struct flexi_crypto_context *fctx;
	enum flexi_cipher cipher_type;
	const char *name;

	name = crypto_tfm_alg_name(tfm);
	cipher_type = flexi_cipher_type(name);
	if (unlikely(cipher_type == CIPHER_INVALID)) {
		pr_err("unsupported cipher: %s\n", name);
		return -EINVAL;
	}

	/* fill crypto context */
	fctx = nctx->u.fctx;
	fctx->flags = 0;
	fctx->w0.cipher_type = cipher_type;
	fctx->w0.aes_keylen = aes_keylen;
	fctx->w0.iv_source = IV_FROM_DPTR;
	fctx->flags = cpu_to_be64(*(u64 *)&fctx->w0);
	/* copy the key to context */
	memcpy(fctx->crypto.u.key, key, keylen);

	return 0;
}

__attribute__((used)) static int nitrox_aes_setkey(struct crypto_skcipher *cipher, const u8 *key,
			     unsigned int keylen)
{
	int aes_keylen;

	aes_keylen = flexi_aes_keylen(keylen);
	if (aes_keylen < 0) {
		crypto_skcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
		return -EINVAL;
	}
	return nitrox_skcipher_setkey(cipher, aes_keylen, key, keylen);
}

__attribute__((used)) static void nitrox_skcipher_callback(struct skcipher_request *skreq,
				     int err)
{
	if (err) {
		pr_err_ratelimited("request failed status 0x%0x\n", err);
		err = -EINVAL;
	}
	skcipher_request_complete(skreq, err);
}

__attribute__((used)) static int nitrox_skcipher_crypt(struct skcipher_request *skreq, bool enc)
{
	struct crypto_skcipher *cipher = crypto_skcipher_reqtfm(skreq);
	struct nitrox_crypto_ctx *nctx = crypto_skcipher_ctx(cipher);
	struct nitrox_kcrypt_request *nkreq = skcipher_request_ctx(skreq);
	int ivsize = crypto_skcipher_ivsize(cipher);
	struct se_crypto_request *creq;

	creq = &nkreq->creq;
	creq->flags = skreq->base.flags;
	creq->gfp = (skreq->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP) ?
		     GFP_KERNEL : GFP_ATOMIC;

	/* fill the request */
	creq->ctrl.value = 0;
	creq->opcode = FLEXI_CRYPTO_ENCRYPT_HMAC;
	creq->ctrl.s.arg = (enc ? ENCRYPT : DECRYPT);
	/* param0: length of the data to be encrypted */
	creq->gph.param0 = cpu_to_be16(skreq->cryptlen);
	creq->gph.param1 = 0;
	/* param2: encryption data offset */
	creq->gph.param2 = cpu_to_be16(ivsize);
	creq->gph.param3 = 0;

	creq->ctx_handle = nctx->u.ctx_handle;
	creq->ctrl.s.ctxl = sizeof(struct flexi_crypto_context);

	/* copy the iv */
	memcpy(creq->iv, skreq->iv, ivsize);
	creq->ivsize = ivsize;
	creq->src = skreq->src;
	creq->dst = skreq->dst;

	nkreq->nctx = nctx;
	nkreq->skreq = skreq;

	/* send the crypto request */
	return nitrox_process_se_request(nctx->ndev, creq,
					 nitrox_skcipher_callback, skreq);
}

__attribute__((used)) static int nitrox_aes_encrypt(struct skcipher_request *skreq)
{
	return nitrox_skcipher_crypt(skreq, true);
}

__attribute__((used)) static int nitrox_aes_decrypt(struct skcipher_request *skreq)
{
	return nitrox_skcipher_crypt(skreq, false);
}

__attribute__((used)) static int nitrox_3des_setkey(struct crypto_skcipher *cipher,
			      const u8 *key, unsigned int keylen)
{
	if (keylen != DES3_EDE_KEY_SIZE) {
		crypto_skcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
		return -EINVAL;
	}

	return nitrox_skcipher_setkey(cipher, 0, key, keylen);
}

__attribute__((used)) static int nitrox_3des_encrypt(struct skcipher_request *skreq)
{
	return nitrox_skcipher_crypt(skreq, true);
}

__attribute__((used)) static int nitrox_3des_decrypt(struct skcipher_request *skreq)
{
	return nitrox_skcipher_crypt(skreq, false);
}

__attribute__((used)) static int nitrox_aes_xts_setkey(struct crypto_skcipher *cipher,
				 const u8 *key, unsigned int keylen)
{
	struct crypto_tfm *tfm = crypto_skcipher_tfm(cipher);
	struct nitrox_crypto_ctx *nctx = crypto_tfm_ctx(tfm);
	struct flexi_crypto_context *fctx;
	int aes_keylen, ret;

	ret = xts_check_key(tfm, key, keylen);
	if (ret)
		return ret;

	keylen /= 2;

	aes_keylen = flexi_aes_keylen(keylen);
	if (aes_keylen < 0) {
		crypto_skcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
		return -EINVAL;
	}

	fctx = nctx->u.fctx;
	/* copy KEY2 */
	memcpy(fctx->auth.u.key2, (key + keylen), keylen);

	return nitrox_skcipher_setkey(cipher, aes_keylen, key, keylen);
}

__attribute__((used)) static int nitrox_aes_ctr_rfc3686_setkey(struct crypto_skcipher *cipher,
					 const u8 *key, unsigned int keylen)
{
	struct crypto_tfm *tfm = crypto_skcipher_tfm(cipher);
	struct nitrox_crypto_ctx *nctx = crypto_tfm_ctx(tfm);
	struct flexi_crypto_context *fctx;
	int aes_keylen;

	if (keylen < CTR_RFC3686_NONCE_SIZE)
		return -EINVAL;

	fctx = nctx->u.fctx;

	memcpy(fctx->crypto.iv, key + (keylen - CTR_RFC3686_NONCE_SIZE),
	       CTR_RFC3686_NONCE_SIZE);

	keylen -= CTR_RFC3686_NONCE_SIZE;

	aes_keylen = flexi_aes_keylen(keylen);
	if (aes_keylen < 0) {
		crypto_skcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
		return -EINVAL;
	}
	return nitrox_skcipher_setkey(cipher, aes_keylen, key, keylen);
}

int nitrox_crypto_register(void)
{
	return crypto_register_skciphers(nitrox_skciphers,
					 ARRAY_SIZE(nitrox_skciphers));
}

void nitrox_crypto_unregister(void)
{
	crypto_unregister_skciphers(nitrox_skciphers,
				    ARRAY_SIZE(nitrox_skciphers));
}

