#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct kpp_request {scalar_t__ src; int /*<<< orphan*/  dst_len; int /*<<< orphan*/  dst; int /*<<< orphan*/  src_len; } ;
struct dh_ctx {void* p; void* g; void* xa; void* q; } ;
struct dh {int p_size; int q_size; int g_size; int key_size; scalar_t__ key; scalar_t__ g; scalar_t__ q; scalar_t__ p; } ;
struct crypto_kpp {int dummy; } ;
typedef  void* MPI ;

/* Variables and functions */
 int EBADMSG ; 
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ crypto_dh_decode_key (void const*,unsigned int,struct dh*) ; 
 struct crypto_kpp* crypto_kpp_reqtfm (struct kpp_request*) ; 
 int crypto_register_kpp (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  crypto_unregister_kpp (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dh ; 
 struct dh_ctx* kpp_tfm_ctx (struct crypto_kpp*) ; 
 int /*<<< orphan*/  memset (struct dh_ctx*,int /*<<< orphan*/ ,int) ; 
 void* mpi_alloc (int /*<<< orphan*/ ) ; 
 scalar_t__ mpi_cmp (void*,void*) ; 
 int mpi_cmp_ui (void*,int) ; 
 int /*<<< orphan*/  mpi_free (void*) ; 
 unsigned int mpi_get_size (void*) ; 
 int mpi_powm (void*,void*,void*,void*) ; 
 void* mpi_read_raw_data (scalar_t__,int) ; 
 void* mpi_read_raw_from_sgl (scalar_t__,int /*<<< orphan*/ ) ; 
 int mpi_write_to_sgl (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void dh_clear_ctx(struct dh_ctx *ctx)
{
	mpi_free(ctx->p);
	mpi_free(ctx->q);
	mpi_free(ctx->g);
	mpi_free(ctx->xa);
	memset(ctx, 0, sizeof(*ctx));
}

__attribute__((used)) static int _compute_val(const struct dh_ctx *ctx, MPI base, MPI val)
{
	/* val = base^xa mod p */
	return mpi_powm(val, base, ctx->xa, ctx->p);
}

__attribute__((used)) static inline struct dh_ctx *dh_get_ctx(struct crypto_kpp *tfm)
{
	return kpp_tfm_ctx(tfm);
}

__attribute__((used)) static int dh_check_params_length(unsigned int p_len)
{
	return (p_len < 1536) ? -EINVAL : 0;
}

__attribute__((used)) static int dh_set_params(struct dh_ctx *ctx, struct dh *params)
{
	if (dh_check_params_length(params->p_size << 3))
		return -EINVAL;

	ctx->p = mpi_read_raw_data(params->p, params->p_size);
	if (!ctx->p)
		return -EINVAL;

	if (params->q && params->q_size) {
		ctx->q = mpi_read_raw_data(params->q, params->q_size);
		if (!ctx->q)
			return -EINVAL;
	}

	ctx->g = mpi_read_raw_data(params->g, params->g_size);
	if (!ctx->g)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int dh_set_secret(struct crypto_kpp *tfm, const void *buf,
			 unsigned int len)
{
	struct dh_ctx *ctx = dh_get_ctx(tfm);
	struct dh params;

	/* Free the old MPI key if any */
	dh_clear_ctx(ctx);

	if (crypto_dh_decode_key(buf, len, &params) < 0)
		goto err_clear_ctx;

	if (dh_set_params(ctx, &params) < 0)
		goto err_clear_ctx;

	ctx->xa = mpi_read_raw_data(params.key, params.key_size);
	if (!ctx->xa)
		goto err_clear_ctx;

	return 0;

err_clear_ctx:
	dh_clear_ctx(ctx);
	return -EINVAL;
}

__attribute__((used)) static int dh_is_pubkey_valid(struct dh_ctx *ctx, MPI y)
{
	if (unlikely(!ctx->p))
		return -EINVAL;

	/*
	 * Step 1: Verify that 2 <= y <= p - 2.
	 *
	 * The upper limit check is actually y < p instead of y < p - 1
	 * as the mpi_sub_ui function is yet missing.
	 */
	if (mpi_cmp_ui(y, 1) < 1 || mpi_cmp(y, ctx->p) >= 0)
		return -EINVAL;

	/* Step 2: Verify that 1 = y^q mod p */
	if (ctx->q) {
		MPI val = mpi_alloc(0);
		int ret;

		if (!val)
			return -ENOMEM;

		ret = mpi_powm(val, y, ctx->q, ctx->p);

		if (ret) {
			mpi_free(val);
			return ret;
		}

		ret = mpi_cmp_ui(val, 1);

		mpi_free(val);

		if (ret != 0)
			return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int dh_compute_value(struct kpp_request *req)
{
	struct crypto_kpp *tfm = crypto_kpp_reqtfm(req);
	struct dh_ctx *ctx = dh_get_ctx(tfm);
	MPI base, val = mpi_alloc(0);
	int ret = 0;
	int sign;

	if (!val)
		return -ENOMEM;

	if (unlikely(!ctx->xa)) {
		ret = -EINVAL;
		goto err_free_val;
	}

	if (req->src) {
		base = mpi_read_raw_from_sgl(req->src, req->src_len);
		if (!base) {
			ret = -EINVAL;
			goto err_free_val;
		}
		ret = dh_is_pubkey_valid(ctx, base);
		if (ret)
			goto err_free_base;
	} else {
		base = ctx->g;
	}

	ret = _compute_val(ctx, base, val);
	if (ret)
		goto err_free_base;

	ret = mpi_write_to_sgl(val, req->dst, req->dst_len, &sign);
	if (ret)
		goto err_free_base;

	if (sign < 0)
		ret = -EBADMSG;
err_free_base:
	if (req->src)
		mpi_free(base);
err_free_val:
	mpi_free(val);
	return ret;
}

__attribute__((used)) static unsigned int dh_max_size(struct crypto_kpp *tfm)
{
	struct dh_ctx *ctx = dh_get_ctx(tfm);

	return mpi_get_size(ctx->p);
}

__attribute__((used)) static void dh_exit_tfm(struct crypto_kpp *tfm)
{
	struct dh_ctx *ctx = dh_get_ctx(tfm);

	dh_clear_ctx(ctx);
}

__attribute__((used)) static int dh_init(void)
{
	return crypto_register_kpp(&dh);
}

__attribute__((used)) static void dh_exit(void)
{
	crypto_unregister_kpp(&dh);
}

