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
typedef  int /*<<< orphan*/  u32 ;
struct sk_buff {int dummy; } ;
struct seq_file {int dummy; } ;
struct crypto_alg {unsigned int cra_ctxsize; int cra_flags; int /*<<< orphan*/ * cra_type; int /*<<< orphan*/  (* cra_destroy ) (struct crypto_alg*) ;int /*<<< orphan*/  cra_refcnt; } ;
struct kpp_alg {int (* init ) (struct crypto_kpp*) ;struct crypto_alg base; int /*<<< orphan*/  (* exit ) (struct crypto_kpp*) ;} ;
struct crypto_tfm {int dummy; } ;
struct crypto_template {int /*<<< orphan*/  module; } ;
struct TYPE_2__ {void (* exit ) (struct crypto_tfm*) ;} ;
struct crypto_kpp {TYPE_1__ base; } ;

/* Variables and functions */
 int CRYPTO_ALG_DEAD ; 
 int CRYPTO_ALG_DYING ; 
 int CRYPTO_ALG_LARVAL ; 
 int CRYPTO_ALG_TYPE_KPP ; 
 int CRYPTO_ALG_TYPE_MASK ; 
 int ENOSYS ; 
 struct crypto_kpp* __crypto_kpp_tfm (struct crypto_tfm*) ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,unsigned long,void*) ; 
 struct crypto_kpp* crypto_alloc_tfm (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_chain ; 
 struct kpp_alg* crypto_kpp_alg (struct crypto_kpp*) ; 
 int /*<<< orphan*/  crypto_kpp_type ; 
 int crypto_register_alg (struct crypto_alg*) ; 
 int /*<<< orphan*/  crypto_unregister_alg (struct crypto_alg*) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
 int /*<<< orphan*/  stub1 (struct crypto_alg*) ; 
 int /*<<< orphan*/  stub2 (struct crypto_kpp*) ; 
 int stub3 (struct crypto_kpp*) ; 
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

__attribute__((used)) static int crypto_kpp_report(struct sk_buff *skb, struct crypto_alg *alg)
{
	return -ENOSYS;
}

__attribute__((used)) static void crypto_kpp_show(struct seq_file *m, struct crypto_alg *alg)
{
	seq_puts(m, "type         : kpp\n");
}

__attribute__((used)) static void crypto_kpp_exit_tfm(struct crypto_tfm *tfm)
{
	struct crypto_kpp *kpp = __crypto_kpp_tfm(tfm);
	struct kpp_alg *alg = crypto_kpp_alg(kpp);

	alg->exit(kpp);
}

__attribute__((used)) static int crypto_kpp_init_tfm(struct crypto_tfm *tfm)
{
	struct crypto_kpp *kpp = __crypto_kpp_tfm(tfm);
	struct kpp_alg *alg = crypto_kpp_alg(kpp);

	if (alg->exit)
		kpp->base.exit = crypto_kpp_exit_tfm;

	if (alg->init)
		return alg->init(kpp);

	return 0;
}

struct crypto_kpp *crypto_alloc_kpp(const char *alg_name, u32 type, u32 mask)
{
	return crypto_alloc_tfm(alg_name, &crypto_kpp_type, type, mask);
}

__attribute__((used)) static void kpp_prepare_alg(struct kpp_alg *alg)
{
	struct crypto_alg *base = &alg->base;

	base->cra_type = &crypto_kpp_type;
	base->cra_flags &= ~CRYPTO_ALG_TYPE_MASK;
	base->cra_flags |= CRYPTO_ALG_TYPE_KPP;
}

int crypto_register_kpp(struct kpp_alg *alg)
{
	struct crypto_alg *base = &alg->base;

	kpp_prepare_alg(alg);
	return crypto_register_alg(base);
}

void crypto_unregister_kpp(struct kpp_alg *alg)
{
	crypto_unregister_alg(&alg->base);
}

