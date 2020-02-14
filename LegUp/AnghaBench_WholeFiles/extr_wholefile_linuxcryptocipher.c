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
typedef  int /*<<< orphan*/  const u8 ;
struct cipher_tfm {int (* cit_setkey ) (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int) ;void (* cit_encrypt_one ) (struct crypto_tfm*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ;void (* cit_decrypt_one ) (struct crypto_tfm*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ;} ;
struct crypto_tfm {TYPE_1__* __crt_alg; struct cipher_tfm crt_cipher; int /*<<< orphan*/  crt_flags; } ;
struct crypto_template {int /*<<< orphan*/  module; } ;
struct crypto_alg {unsigned int cra_ctxsize; int cra_flags; int /*<<< orphan*/  (* cra_destroy ) (struct crypto_alg*) ;int /*<<< orphan*/  cra_refcnt; } ;
struct cipher_alg {int (* cia_setkey ) (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int) ;unsigned int cia_min_keysize; unsigned int cia_max_keysize; void (* cia_encrypt ) (struct crypto_tfm*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ;void (* cia_decrypt ) (struct crypto_tfm*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ;} ;
struct TYPE_2__ {struct cipher_alg cra_cipher; } ;

/* Variables and functions */
 scalar_t__ ALIGN (unsigned long,unsigned long) ; 
 int CRYPTO_ALG_DEAD ; 
 int CRYPTO_ALG_DYING ; 
 int CRYPTO_ALG_LARVAL ; 
 int /*<<< orphan*/  CRYPTO_TFM_RES_BAD_KEY_LEN ; 
 int /*<<< orphan*/  CRYPTO_TFM_RES_MASK ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int MAX_CIPHER_ALIGNMASK ; 
 int MAX_CIPHER_BLOCKSIZE ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,unsigned long,void*) ; 
 int /*<<< orphan*/  crypto_chain ; 
 unsigned long crypto_tfm_alg_alignmask (struct crypto_tfm*) ; 
 unsigned int crypto_tfm_alg_blocksize (struct crypto_tfm*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* kmalloc (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct crypto_alg*) ; 
 int stub2 (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int) ; 
 int stub3 (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int) ; 
 void stub4 (struct crypto_tfm*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 void stub5 (struct crypto_tfm*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int try_module_get (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (unsigned long) ; 

__attribute__((used)) static inline void crypto_init_proc(void)
{ }

__attribute__((used)) static inline void crypto_exit_proc(void)
{ }

__attribute__((used)) static inline unsigned int crypto_cipher_ctxsize(struct crypto_alg *alg)
{
	return alg->cra_ctxsize;
}

__attribute__((used)) static inline unsigned int crypto_compress_ctxsize(struct crypto_alg *alg)
{
	return alg->cra_ctxsize;
}

__attribute__((used)) static inline struct crypto_alg *crypto_alg_get(struct crypto_alg *alg)
{
	refcount_inc(&alg->cra_refcnt);
	return alg;
}

__attribute__((used)) static inline void crypto_alg_put(struct crypto_alg *alg)
{
	if (refcount_dec_and_test(&alg->cra_refcnt) && alg->cra_destroy)
		alg->cra_destroy(alg);
}

__attribute__((used)) static inline int crypto_tmpl_get(struct crypto_template *tmpl)
{
	return try_module_get(tmpl->module);
}

__attribute__((used)) static inline void crypto_tmpl_put(struct crypto_template *tmpl)
{
	module_put(tmpl->module);
}

__attribute__((used)) static inline int crypto_is_larval(struct crypto_alg *alg)
{
	return alg->cra_flags & CRYPTO_ALG_LARVAL;
}

__attribute__((used)) static inline int crypto_is_dead(struct crypto_alg *alg)
{
	return alg->cra_flags & CRYPTO_ALG_DEAD;
}

__attribute__((used)) static inline int crypto_is_moribund(struct crypto_alg *alg)
{
	return alg->cra_flags & (CRYPTO_ALG_DEAD | CRYPTO_ALG_DYING);
}

__attribute__((used)) static inline void crypto_notify(unsigned long val, void *v)
{
	blocking_notifier_call_chain(&crypto_chain, val, v);
}

__attribute__((used)) static int setkey_unaligned(struct crypto_tfm *tfm, const u8 *key,
			    unsigned int keylen)
{
	struct cipher_alg *cia = &tfm->__crt_alg->cra_cipher;
	unsigned long alignmask = crypto_tfm_alg_alignmask(tfm);
	int ret;
	u8 *buffer, *alignbuffer;
	unsigned long absize;

	absize = keylen + alignmask;
	buffer = kmalloc(absize, GFP_ATOMIC);
	if (!buffer)
		return -ENOMEM;

	alignbuffer = (u8 *)ALIGN((unsigned long)buffer, alignmask + 1);
	memcpy(alignbuffer, key, keylen);
	ret = cia->cia_setkey(tfm, alignbuffer, keylen);
	memset(alignbuffer, 0, keylen);
	kfree(buffer);
	return ret;

}

__attribute__((used)) static int setkey(struct crypto_tfm *tfm, const u8 *key, unsigned int keylen)
{
	struct cipher_alg *cia = &tfm->__crt_alg->cra_cipher;
	unsigned long alignmask = crypto_tfm_alg_alignmask(tfm);

	tfm->crt_flags &= ~CRYPTO_TFM_RES_MASK;
	if (keylen < cia->cia_min_keysize || keylen > cia->cia_max_keysize) {
		tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
		return -EINVAL;
	}

	if ((unsigned long)key & alignmask)
		return setkey_unaligned(tfm, key, keylen);

	return cia->cia_setkey(tfm, key, keylen);
}

__attribute__((used)) static void cipher_crypt_unaligned(void (*fn)(struct crypto_tfm *, u8 *,
					      const u8 *),
				   struct crypto_tfm *tfm,
				   u8 *dst, const u8 *src)
{
	unsigned long alignmask = crypto_tfm_alg_alignmask(tfm);
	unsigned int size = crypto_tfm_alg_blocksize(tfm);
	u8 buffer[MAX_CIPHER_BLOCKSIZE + MAX_CIPHER_ALIGNMASK];
	u8 *tmp = (u8 *)ALIGN((unsigned long)buffer, alignmask + 1);

	memcpy(tmp, src, size);
	fn(tfm, tmp, tmp);
	memcpy(dst, tmp, size);
}

__attribute__((used)) static void cipher_encrypt_unaligned(struct crypto_tfm *tfm,
				     u8 *dst, const u8 *src)
{
	unsigned long alignmask = crypto_tfm_alg_alignmask(tfm);
	struct cipher_alg *cipher = &tfm->__crt_alg->cra_cipher;

	if (unlikely(((unsigned long)dst | (unsigned long)src) & alignmask)) {
		cipher_crypt_unaligned(cipher->cia_encrypt, tfm, dst, src);
		return;
	}

	cipher->cia_encrypt(tfm, dst, src);
}

__attribute__((used)) static void cipher_decrypt_unaligned(struct crypto_tfm *tfm,
				     u8 *dst, const u8 *src)
{
	unsigned long alignmask = crypto_tfm_alg_alignmask(tfm);
	struct cipher_alg *cipher = &tfm->__crt_alg->cra_cipher;

	if (unlikely(((unsigned long)dst | (unsigned long)src) & alignmask)) {
		cipher_crypt_unaligned(cipher->cia_decrypt, tfm, dst, src);
		return;
	}

	cipher->cia_decrypt(tfm, dst, src);
}

int crypto_init_cipher_ops(struct crypto_tfm *tfm)
{
	struct cipher_tfm *ops = &tfm->crt_cipher;
	struct cipher_alg *cipher = &tfm->__crt_alg->cra_cipher;

	ops->cit_setkey = setkey;
	ops->cit_encrypt_one = crypto_tfm_alg_alignmask(tfm) ?
		cipher_encrypt_unaligned : cipher->cia_encrypt;
	ops->cit_decrypt_one = crypto_tfm_alg_alignmask(tfm) ?
		cipher_decrypt_unaligned : cipher->cia_decrypt;

	return 0;
}

