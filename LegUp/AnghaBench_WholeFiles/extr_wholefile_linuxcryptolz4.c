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
struct lz4_ctx {void* lz4_comp_mem; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_scomp {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 void* ERR_PTR (int) ; 
 scalar_t__ IS_ERR (void*) ; 
 int /*<<< orphan*/  LZ4_MEM_COMPRESS ; 
 int LZ4_compress_default (int /*<<< orphan*/  const*,int /*<<< orphan*/ *,unsigned int,unsigned int,void*) ; 
 int LZ4_decompress_safe (int /*<<< orphan*/  const*,int /*<<< orphan*/ *,unsigned int,unsigned int) ; 
 struct lz4_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  vfree (void*) ; 
 void* vmalloc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *lz4_alloc_ctx(struct crypto_scomp *tfm)
{
	void *ctx;

	ctx = vmalloc(LZ4_MEM_COMPRESS);
	if (!ctx)
		return ERR_PTR(-ENOMEM);

	return ctx;
}

__attribute__((used)) static int lz4_init(struct crypto_tfm *tfm)
{
	struct lz4_ctx *ctx = crypto_tfm_ctx(tfm);

	ctx->lz4_comp_mem = lz4_alloc_ctx(NULL);
	if (IS_ERR(ctx->lz4_comp_mem))
		return -ENOMEM;

	return 0;
}

__attribute__((used)) static void lz4_free_ctx(struct crypto_scomp *tfm, void *ctx)
{
	vfree(ctx);
}

__attribute__((used)) static void lz4_exit(struct crypto_tfm *tfm)
{
	struct lz4_ctx *ctx = crypto_tfm_ctx(tfm);

	lz4_free_ctx(NULL, ctx->lz4_comp_mem);
}

__attribute__((used)) static int __lz4_compress_crypto(const u8 *src, unsigned int slen,
				 u8 *dst, unsigned int *dlen, void *ctx)
{
	int out_len = LZ4_compress_default(src, dst,
		slen, *dlen, ctx);

	if (!out_len)
		return -EINVAL;

	*dlen = out_len;
	return 0;
}

__attribute__((used)) static int lz4_scompress(struct crypto_scomp *tfm, const u8 *src,
			 unsigned int slen, u8 *dst, unsigned int *dlen,
			 void *ctx)
{
	return __lz4_compress_crypto(src, slen, dst, dlen, ctx);
}

__attribute__((used)) static int lz4_compress_crypto(struct crypto_tfm *tfm, const u8 *src,
			       unsigned int slen, u8 *dst, unsigned int *dlen)
{
	struct lz4_ctx *ctx = crypto_tfm_ctx(tfm);

	return __lz4_compress_crypto(src, slen, dst, dlen, ctx->lz4_comp_mem);
}

__attribute__((used)) static int __lz4_decompress_crypto(const u8 *src, unsigned int slen,
				   u8 *dst, unsigned int *dlen, void *ctx)
{
	int out_len = LZ4_decompress_safe(src, dst, slen, *dlen);

	if (out_len < 0)
		return -EINVAL;

	*dlen = out_len;
	return 0;
}

__attribute__((used)) static int lz4_sdecompress(struct crypto_scomp *tfm, const u8 *src,
			   unsigned int slen, u8 *dst, unsigned int *dlen,
			   void *ctx)
{
	return __lz4_decompress_crypto(src, slen, dst, dlen, NULL);
}

__attribute__((used)) static int lz4_decompress_crypto(struct crypto_tfm *tfm, const u8 *src,
				 unsigned int slen, u8 *dst,
				 unsigned int *dlen)
{
	return __lz4_decompress_crypto(src, slen, dst, dlen, NULL);
}

