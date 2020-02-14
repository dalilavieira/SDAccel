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
typedef  int /*<<< orphan*/  u8 ;
struct lzo_ctx {void* lzo_comp_mem; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_scomp {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 void* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (void*) ; 
 int /*<<< orphan*/  LZO1X_MEM_COMPRESS ; 
 int LZO_E_OK ; 
 struct lzo_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  kvfree (void*) ; 
 void* kvmalloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int lzo1x_1_compress (int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,size_t*,void*) ; 
 int lzo1x_decompress_safe (int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,size_t*) ; 

__attribute__((used)) static void *lzo_alloc_ctx(struct crypto_scomp *tfm)
{
	void *ctx;

	ctx = kvmalloc(LZO1X_MEM_COMPRESS, GFP_KERNEL);
	if (!ctx)
		return ERR_PTR(-ENOMEM);

	return ctx;
}

__attribute__((used)) static int lzo_init(struct crypto_tfm *tfm)
{
	struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);

	ctx->lzo_comp_mem = lzo_alloc_ctx(NULL);
	if (IS_ERR(ctx->lzo_comp_mem))
		return -ENOMEM;

	return 0;
}

__attribute__((used)) static void lzo_free_ctx(struct crypto_scomp *tfm, void *ctx)
{
	kvfree(ctx);
}

__attribute__((used)) static void lzo_exit(struct crypto_tfm *tfm)
{
	struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);

	lzo_free_ctx(NULL, ctx->lzo_comp_mem);
}

__attribute__((used)) static int __lzo_compress(const u8 *src, unsigned int slen,
			  u8 *dst, unsigned int *dlen, void *ctx)
{
	size_t tmp_len = *dlen; /* size_t(ulong) <-> uint on 64 bit */
	int err;

	err = lzo1x_1_compress(src, slen, dst, &tmp_len, ctx);

	if (err != LZO_E_OK)
		return -EINVAL;

	*dlen = tmp_len;
	return 0;
}

__attribute__((used)) static int lzo_compress(struct crypto_tfm *tfm, const u8 *src,
			unsigned int slen, u8 *dst, unsigned int *dlen)
{
	struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);

	return __lzo_compress(src, slen, dst, dlen, ctx->lzo_comp_mem);
}

__attribute__((used)) static int lzo_scompress(struct crypto_scomp *tfm, const u8 *src,
			 unsigned int slen, u8 *dst, unsigned int *dlen,
			 void *ctx)
{
	return __lzo_compress(src, slen, dst, dlen, ctx);
}

__attribute__((used)) static int __lzo_decompress(const u8 *src, unsigned int slen,
			    u8 *dst, unsigned int *dlen)
{
	int err;
	size_t tmp_len = *dlen; /* size_t(ulong) <-> uint on 64 bit */

	err = lzo1x_decompress_safe(src, slen, dst, &tmp_len);

	if (err != LZO_E_OK)
		return -EINVAL;

	*dlen = tmp_len;
	return 0;
}

__attribute__((used)) static int lzo_decompress(struct crypto_tfm *tfm, const u8 *src,
			  unsigned int slen, u8 *dst, unsigned int *dlen)
{
	return __lzo_decompress(src, slen, dst, dlen);
}

__attribute__((used)) static int lzo_sdecompress(struct crypto_scomp *tfm, const u8 *src,
			   unsigned int slen, u8 *dst, unsigned int *dlen,
			   void *ctx)
{
	return __lzo_decompress(src, slen, dst, dlen);
}

