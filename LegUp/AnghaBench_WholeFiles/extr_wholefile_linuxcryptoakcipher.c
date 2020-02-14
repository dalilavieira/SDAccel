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
typedef  int /*<<< orphan*/  u32 ;
struct sk_buff {int dummy; } ;
struct seq_file {int dummy; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_template {int /*<<< orphan*/  module; } ;
struct crypto_instance {int dummy; } ;
struct crypto_alg {unsigned int cra_ctxsize; int cra_flags; int /*<<< orphan*/ * cra_type; int /*<<< orphan*/  (* cra_destroy ) (struct crypto_alg*) ;int /*<<< orphan*/  cra_refcnt; } ;
struct TYPE_4__ {int /*<<< orphan*/ * frontend; } ;
struct crypto_akcipher_spawn {TYPE_2__ base; } ;
struct TYPE_3__ {void (* exit ) (struct crypto_tfm*) ;} ;
struct crypto_akcipher {TYPE_1__ base; } ;
struct akcipher_alg {int (* init ) (struct crypto_akcipher*) ;struct crypto_alg base; int /*<<< orphan*/  (* exit ) (struct crypto_akcipher*) ;} ;
struct akcipher_instance {struct akcipher_alg alg; int /*<<< orphan*/  (* free ) (struct akcipher_instance*) ;} ;

/* Variables and functions */
 int CRYPTO_ALG_DEAD ; 
 int CRYPTO_ALG_DYING ; 
 int CRYPTO_ALG_LARVAL ; 
 int CRYPTO_ALG_TYPE_AKCIPHER ; 
 int CRYPTO_ALG_TYPE_MASK ; 
 int ENOSYS ; 
 struct crypto_akcipher* __crypto_akcipher_tfm (struct crypto_tfm*) ; 
 int /*<<< orphan*/  akcipher_crypto_instance (struct akcipher_instance*) ; 
 struct akcipher_instance* akcipher_instance (struct crypto_instance*) ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,unsigned long,void*) ; 
 struct akcipher_alg* crypto_akcipher_alg (struct crypto_akcipher*) ; 
 int /*<<< orphan*/  crypto_akcipher_type ; 
 struct crypto_akcipher* crypto_alloc_tfm (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_chain ; 
 int crypto_grab_spawn (TYPE_2__*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int crypto_register_alg (struct crypto_alg*) ; 
 int crypto_register_instance (struct crypto_template*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_unregister_alg (struct crypto_alg*) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
 int /*<<< orphan*/  stub1 (struct crypto_alg*) ; 
 int /*<<< orphan*/  stub2 (struct crypto_akcipher*) ; 
 int stub3 (struct crypto_akcipher*) ; 
 int /*<<< orphan*/  stub4 (struct akcipher_instance*) ; 
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

__attribute__((used)) static int crypto_akcipher_report(struct sk_buff *skb, struct crypto_alg *alg)
{
	return -ENOSYS;
}

__attribute__((used)) static void crypto_akcipher_show(struct seq_file *m, struct crypto_alg *alg)
{
	seq_puts(m, "type         : akcipher\n");
}

__attribute__((used)) static void crypto_akcipher_exit_tfm(struct crypto_tfm *tfm)
{
	struct crypto_akcipher *akcipher = __crypto_akcipher_tfm(tfm);
	struct akcipher_alg *alg = crypto_akcipher_alg(akcipher);

	alg->exit(akcipher);
}

__attribute__((used)) static int crypto_akcipher_init_tfm(struct crypto_tfm *tfm)
{
	struct crypto_akcipher *akcipher = __crypto_akcipher_tfm(tfm);
	struct akcipher_alg *alg = crypto_akcipher_alg(akcipher);

	if (alg->exit)
		akcipher->base.exit = crypto_akcipher_exit_tfm;

	if (alg->init)
		return alg->init(akcipher);

	return 0;
}

__attribute__((used)) static void crypto_akcipher_free_instance(struct crypto_instance *inst)
{
	struct akcipher_instance *akcipher = akcipher_instance(inst);

	akcipher->free(akcipher);
}

int crypto_grab_akcipher(struct crypto_akcipher_spawn *spawn, const char *name,
			 u32 type, u32 mask)
{
	spawn->base.frontend = &crypto_akcipher_type;
	return crypto_grab_spawn(&spawn->base, name, type, mask);
}

struct crypto_akcipher *crypto_alloc_akcipher(const char *alg_name, u32 type,
					      u32 mask)
{
	return crypto_alloc_tfm(alg_name, &crypto_akcipher_type, type, mask);
}

__attribute__((used)) static void akcipher_prepare_alg(struct akcipher_alg *alg)
{
	struct crypto_alg *base = &alg->base;

	base->cra_type = &crypto_akcipher_type;
	base->cra_flags &= ~CRYPTO_ALG_TYPE_MASK;
	base->cra_flags |= CRYPTO_ALG_TYPE_AKCIPHER;
}

int crypto_register_akcipher(struct akcipher_alg *alg)
{
	struct crypto_alg *base = &alg->base;

	akcipher_prepare_alg(alg);
	return crypto_register_alg(base);
}

void crypto_unregister_akcipher(struct akcipher_alg *alg)
{
	crypto_unregister_alg(&alg->base);
}

int akcipher_register_instance(struct crypto_template *tmpl,
			       struct akcipher_instance *inst)
{
	akcipher_prepare_alg(&inst->alg);
	return crypto_register_instance(tmpl, akcipher_crypto_instance(inst));
}

