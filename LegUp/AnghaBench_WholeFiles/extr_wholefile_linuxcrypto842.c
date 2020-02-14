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
struct crypto_tfm {int dummy; } ;
struct crypto_scomp {int dummy; } ;
struct crypto842_ctx {void* wmem; } ;

/* Variables and functions */
 int ENOMEM ; 
 void* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (void*) ; 
 int /*<<< orphan*/  SW842_MEM_COMPRESS ; 
 struct crypto842_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  kfree (void*) ; 
 void* kmalloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sw842_compress (int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,unsigned int*,void*) ; 
 int sw842_decompress (int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,unsigned int*) ; 

__attribute__((used)) static void *crypto842_alloc_ctx(struct crypto_scomp *tfm)
{
	void *ctx;

	ctx = kmalloc(SW842_MEM_COMPRESS, GFP_KERNEL);
	if (!ctx)
		return ERR_PTR(-ENOMEM);

	return ctx;
}

__attribute__((used)) static int crypto842_init(struct crypto_tfm *tfm)
{
	struct crypto842_ctx *ctx = crypto_tfm_ctx(tfm);

	ctx->wmem = crypto842_alloc_ctx(NULL);
	if (IS_ERR(ctx->wmem))
		return -ENOMEM;

	return 0;
}

__attribute__((used)) static void crypto842_free_ctx(struct crypto_scomp *tfm, void *ctx)
{
	kfree(ctx);
}

__attribute__((used)) static void crypto842_exit(struct crypto_tfm *tfm)
{
	struct crypto842_ctx *ctx = crypto_tfm_ctx(tfm);

	crypto842_free_ctx(NULL, ctx->wmem);
}

__attribute__((used)) static int crypto842_compress(struct crypto_tfm *tfm,
			      const u8 *src, unsigned int slen,
			      u8 *dst, unsigned int *dlen)
{
	struct crypto842_ctx *ctx = crypto_tfm_ctx(tfm);

	return sw842_compress(src, slen, dst, dlen, ctx->wmem);
}

__attribute__((used)) static int crypto842_scompress(struct crypto_scomp *tfm,
			       const u8 *src, unsigned int slen,
			       u8 *dst, unsigned int *dlen, void *ctx)
{
	return sw842_compress(src, slen, dst, dlen, ctx);
}

__attribute__((used)) static int crypto842_decompress(struct crypto_tfm *tfm,
				const u8 *src, unsigned int slen,
				u8 *dst, unsigned int *dlen)
{
	return sw842_decompress(src, slen, dst, dlen);
}

__attribute__((used)) static int crypto842_sdecompress(struct crypto_scomp *tfm,
				 const u8 *src, unsigned int slen,
				 u8 *dst, unsigned int *dlen, void *ctx)
{
	return sw842_decompress(src, slen, dst, dlen);
}

