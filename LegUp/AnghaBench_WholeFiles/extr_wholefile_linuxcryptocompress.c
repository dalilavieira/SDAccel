#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct compress_tfm {int (* cot_compress ) (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,unsigned int*) ;int (* cot_decompress ) (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,unsigned int*) ;} ;
struct crypto_tfm {struct compress_tfm crt_compress; TYPE_2__* __crt_alg; } ;
struct crypto_template {int /*<<< orphan*/  module; } ;
struct crypto_alg {unsigned int cra_ctxsize; int cra_flags; int /*<<< orphan*/  (* cra_destroy ) (struct crypto_alg*) ;int /*<<< orphan*/  cra_refcnt; } ;
struct TYPE_3__ {int (* coa_compress ) (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,unsigned int*) ;int (* coa_decompress ) (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,unsigned int*) ;} ;
struct TYPE_4__ {TYPE_1__ cra_compress; } ;

/* Variables and functions */
 int CRYPTO_ALG_DEAD ; 
 int CRYPTO_ALG_DYING ; 
 int CRYPTO_ALG_LARVAL ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,unsigned long,void*) ; 
 int /*<<< orphan*/  crypto_chain ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct crypto_alg*) ; 
 int stub2 (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,unsigned int*) ; 
 int stub3 (struct crypto_tfm*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,unsigned int*) ; 
 int try_module_get (int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static int crypto_compress(struct crypto_tfm *tfm,
                            const u8 *src, unsigned int slen,
                            u8 *dst, unsigned int *dlen)
{
	return tfm->__crt_alg->cra_compress.coa_compress(tfm, src, slen, dst,
	                                                 dlen);
}

__attribute__((used)) static int crypto_decompress(struct crypto_tfm *tfm,
                             const u8 *src, unsigned int slen,
                             u8 *dst, unsigned int *dlen)
{
	return tfm->__crt_alg->cra_compress.coa_decompress(tfm, src, slen, dst,
	                                                   dlen);
}

int crypto_init_compress_ops(struct crypto_tfm *tfm)
{
	struct compress_tfm *ops = &tfm->crt_compress;

	ops->cot_compress = crypto_compress;
	ops->cot_decompress = crypto_decompress;

	return 0;
}

