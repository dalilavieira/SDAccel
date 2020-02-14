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
struct crypto_tfm {TYPE_2__* __crt_alg; } ;
struct crypto_template {int /*<<< orphan*/  module; } ;
struct crypto_scomp {int dummy; } ;
struct crypto_alg {unsigned int cra_ctxsize; int cra_flags; int /*<<< orphan*/ * cra_type; int /*<<< orphan*/  (* cra_destroy ) (struct crypto_alg*) ;int /*<<< orphan*/  cra_refcnt; } ;
struct TYPE_3__ {void (* exit ) (struct crypto_tfm*) ;} ;
struct crypto_acomp {int /*<<< orphan*/  (* dst_free ) (int /*<<< orphan*/ *) ;TYPE_1__ base; int /*<<< orphan*/  reqsize; int /*<<< orphan*/  decompress; int /*<<< orphan*/  compress; } ;
struct acomp_req {int flags; int /*<<< orphan*/ * dst; } ;
struct acomp_alg {int (* init ) (struct crypto_acomp*) ;struct crypto_alg base; int /*<<< orphan*/  (* exit ) (struct crypto_acomp*) ;int /*<<< orphan*/  reqsize; int /*<<< orphan*/  (* dst_free ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  decompress; int /*<<< orphan*/  compress; } ;
struct TYPE_4__ {int /*<<< orphan*/ * cra_type; } ;

/* Variables and functions */
 int CRYPTO_ACOMP_ALLOC_OUTPUT ; 
 int CRYPTO_ALG_DEAD ; 
 int CRYPTO_ALG_DYING ; 
 int CRYPTO_ALG_LARVAL ; 
 int CRYPTO_ALG_TYPE_ACOMPRESS ; 
 int CRYPTO_ALG_TYPE_MASK ; 
 int ENOSYS ; 
 struct acomp_req* __acomp_request_alloc (struct crypto_acomp*) ; 
 int /*<<< orphan*/  __acomp_request_free (struct acomp_req*) ; 
 struct crypto_acomp* __crypto_acomp_tfm (struct crypto_tfm*) ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,unsigned long,void*) ; 
 struct acomp_alg* crypto_acomp_alg (struct crypto_acomp*) ; 
 struct crypto_acomp* crypto_acomp_reqtfm (struct acomp_req*) ; 
 struct acomp_req* crypto_acomp_scomp_alloc_ctx (struct acomp_req*) ; 
 int /*<<< orphan*/  crypto_acomp_scomp_free_ctx (struct acomp_req*) ; 
 struct crypto_tfm* crypto_acomp_tfm (struct crypto_acomp*) ; 
 int /*<<< orphan*/  crypto_acomp_type ; 
 int crypto_alg_extsize (struct crypto_alg*) ; 
 struct crypto_acomp* crypto_alloc_tfm (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_chain ; 
 int crypto_init_scomp_ops_async (struct crypto_tfm*) ; 
 int crypto_register_alg (struct crypto_alg*) ; 
 int crypto_unregister_alg (struct crypto_alg*) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
 int /*<<< orphan*/  stub1 (struct crypto_alg*) ; 
 int /*<<< orphan*/  stub2 (struct crypto_acomp*) ; 
 int stub3 (struct crypto_acomp*) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ *) ; 
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

__attribute__((used)) static int crypto_acomp_report(struct sk_buff *skb, struct crypto_alg *alg)
{
	return -ENOSYS;
}

__attribute__((used)) static void crypto_acomp_show(struct seq_file *m, struct crypto_alg *alg)
{
	seq_puts(m, "type         : acomp\n");
}

__attribute__((used)) static void crypto_acomp_exit_tfm(struct crypto_tfm *tfm)
{
	struct crypto_acomp *acomp = __crypto_acomp_tfm(tfm);
	struct acomp_alg *alg = crypto_acomp_alg(acomp);

	alg->exit(acomp);
}

__attribute__((used)) static int crypto_acomp_init_tfm(struct crypto_tfm *tfm)
{
	struct crypto_acomp *acomp = __crypto_acomp_tfm(tfm);
	struct acomp_alg *alg = crypto_acomp_alg(acomp);

	if (tfm->__crt_alg->cra_type != &crypto_acomp_type)
		return crypto_init_scomp_ops_async(tfm);

	acomp->compress = alg->compress;
	acomp->decompress = alg->decompress;
	acomp->dst_free = alg->dst_free;
	acomp->reqsize = alg->reqsize;

	if (alg->exit)
		acomp->base.exit = crypto_acomp_exit_tfm;

	if (alg->init)
		return alg->init(acomp);

	return 0;
}

__attribute__((used)) static unsigned int crypto_acomp_extsize(struct crypto_alg *alg)
{
	int extsize = crypto_alg_extsize(alg);

	if (alg->cra_type != &crypto_acomp_type)
		extsize += sizeof(struct crypto_scomp *);

	return extsize;
}

struct crypto_acomp *crypto_alloc_acomp(const char *alg_name, u32 type,
					u32 mask)
{
	return crypto_alloc_tfm(alg_name, &crypto_acomp_type, type, mask);
}

struct acomp_req *acomp_request_alloc(struct crypto_acomp *acomp)
{
	struct crypto_tfm *tfm = crypto_acomp_tfm(acomp);
	struct acomp_req *req;

	req = __acomp_request_alloc(acomp);
	if (req && (tfm->__crt_alg->cra_type != &crypto_acomp_type))
		return crypto_acomp_scomp_alloc_ctx(req);

	return req;
}

void acomp_request_free(struct acomp_req *req)
{
	struct crypto_acomp *acomp = crypto_acomp_reqtfm(req);
	struct crypto_tfm *tfm = crypto_acomp_tfm(acomp);

	if (tfm->__crt_alg->cra_type != &crypto_acomp_type)
		crypto_acomp_scomp_free_ctx(req);

	if (req->flags & CRYPTO_ACOMP_ALLOC_OUTPUT) {
		acomp->dst_free(req->dst);
		req->dst = NULL;
	}

	__acomp_request_free(req);
}

int crypto_register_acomp(struct acomp_alg *alg)
{
	struct crypto_alg *base = &alg->base;

	base->cra_type = &crypto_acomp_type;
	base->cra_flags &= ~CRYPTO_ALG_TYPE_MASK;
	base->cra_flags |= CRYPTO_ALG_TYPE_ACOMPRESS;

	return crypto_register_alg(base);
}

int crypto_unregister_acomp(struct acomp_alg *alg)
{
	return crypto_unregister_alg(&alg->base);
}

int crypto_register_acomps(struct acomp_alg *algs, int count)
{
	int i, ret;

	for (i = 0; i < count; i++) {
		ret = crypto_register_acomp(&algs[i]);
		if (ret)
			goto err;
	}

	return 0;

err:
	for (--i; i >= 0; --i)
		crypto_unregister_acomp(&algs[i]);

	return ret;
}

void crypto_unregister_acomps(struct acomp_alg *algs, int count)
{
	int i;

	for (i = count - 1; i >= 0; --i)
		crypto_unregister_acomp(&algs[i]);
}

