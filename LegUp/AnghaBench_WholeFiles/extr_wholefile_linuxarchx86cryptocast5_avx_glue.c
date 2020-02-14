#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  const u8 ;
typedef  int u64 ;
struct TYPE_5__ {int /*<<< orphan*/  const* addr; } ;
struct TYPE_6__ {TYPE_1__ virt; } ;
struct TYPE_7__ {int /*<<< orphan*/  const* addr; } ;
struct TYPE_8__ {TYPE_3__ virt; } ;
struct skcipher_walk {unsigned int nbytes; int /*<<< orphan*/  const* iv; TYPE_2__ dst; TYPE_4__ src; } ;
struct skcipher_request {int dummy; } ;
struct crypto_skcipher {int /*<<< orphan*/  base; } ;
struct cast5_ctx {int dummy; } ;
typedef  int /*<<< orphan*/  __be64 ;

/* Variables and functions */
 int CAST5_BLOCK_SIZE ; 
 unsigned int const CAST5_PARALLEL_BLOCKS ; 
 void __cast5_decrypt (struct cast5_ctx*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 void __cast5_encrypt (struct cast5_ctx*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  be64_add_cpu (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  cast5_cbc_dec_16way (struct cast5_ctx*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  cast5_ctr_16way (struct cast5_ctx*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 void cast5_ecb_dec_16way (struct cast5_ctx*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 void cast5_ecb_enc_16way (struct cast5_ctx*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int cast5_setkey (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  crypto_inc (int /*<<< orphan*/  const*,int) ; 
 struct cast5_ctx* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 struct crypto_skcipher* crypto_skcipher_reqtfm (struct skcipher_request*) ; 
 int /*<<< orphan*/  crypto_xor_cpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,unsigned int) ; 
 int glue_fpu_begin (int,unsigned int const,struct skcipher_walk*,int,unsigned int) ; 
 void glue_fpu_end (int) ; 
 int skcipher_walk_done (struct skcipher_walk*,unsigned int) ; 
 int skcipher_walk_virt (struct skcipher_walk*,struct skcipher_request*,int) ; 

__attribute__((used)) static int cast5_setkey_skcipher(struct crypto_skcipher *tfm, const u8 *key,
				 unsigned int keylen)
{
	return cast5_setkey(&tfm->base, key, keylen);
}

__attribute__((used)) static inline bool cast5_fpu_begin(bool fpu_enabled, struct skcipher_walk *walk,
				   unsigned int nbytes)
{
	return glue_fpu_begin(CAST5_BLOCK_SIZE, CAST5_PARALLEL_BLOCKS,
			      walk, fpu_enabled, nbytes);
}

__attribute__((used)) static inline void cast5_fpu_end(bool fpu_enabled)
{
	return glue_fpu_end(fpu_enabled);
}

__attribute__((used)) static int ecb_crypt(struct skcipher_request *req, bool enc)
{
	bool fpu_enabled = false;
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct cast5_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct skcipher_walk walk;
	const unsigned int bsize = CAST5_BLOCK_SIZE;
	unsigned int nbytes;
	void (*fn)(struct cast5_ctx *ctx, u8 *dst, const u8 *src);
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while ((nbytes = walk.nbytes)) {
		u8 *wsrc = walk.src.virt.addr;
		u8 *wdst = walk.dst.virt.addr;

		fpu_enabled = cast5_fpu_begin(fpu_enabled, &walk, nbytes);

		/* Process multi-block batch */
		if (nbytes >= bsize * CAST5_PARALLEL_BLOCKS) {
			fn = (enc) ? cast5_ecb_enc_16way : cast5_ecb_dec_16way;
			do {
				fn(ctx, wdst, wsrc);

				wsrc += bsize * CAST5_PARALLEL_BLOCKS;
				wdst += bsize * CAST5_PARALLEL_BLOCKS;
				nbytes -= bsize * CAST5_PARALLEL_BLOCKS;
			} while (nbytes >= bsize * CAST5_PARALLEL_BLOCKS);

			if (nbytes < bsize)
				goto done;
		}

		fn = (enc) ? __cast5_encrypt : __cast5_decrypt;

		/* Handle leftovers */
		do {
			fn(ctx, wdst, wsrc);

			wsrc += bsize;
			wdst += bsize;
			nbytes -= bsize;
		} while (nbytes >= bsize);

done:
		err = skcipher_walk_done(&walk, nbytes);
	}

	cast5_fpu_end(fpu_enabled);
	return err;
}

__attribute__((used)) static int ecb_encrypt(struct skcipher_request *req)
{
	return ecb_crypt(req, true);
}

__attribute__((used)) static int ecb_decrypt(struct skcipher_request *req)
{
	return ecb_crypt(req, false);
}

__attribute__((used)) static int cbc_encrypt(struct skcipher_request *req)
{
	const unsigned int bsize = CAST5_BLOCK_SIZE;
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct cast5_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct skcipher_walk walk;
	unsigned int nbytes;
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while ((nbytes = walk.nbytes)) {
		u64 *src = (u64 *)walk.src.virt.addr;
		u64 *dst = (u64 *)walk.dst.virt.addr;
		u64 *iv = (u64 *)walk.iv;

		do {
			*dst = *src ^ *iv;
			__cast5_encrypt(ctx, (u8 *)dst, (u8 *)dst);
			iv = dst;
			src++;
			dst++;
			nbytes -= bsize;
		} while (nbytes >= bsize);

		*(u64 *)walk.iv = *iv;
		err = skcipher_walk_done(&walk, nbytes);
	}

	return err;
}

__attribute__((used)) static unsigned int __cbc_decrypt(struct cast5_ctx *ctx,
				  struct skcipher_walk *walk)
{
	const unsigned int bsize = CAST5_BLOCK_SIZE;
	unsigned int nbytes = walk->nbytes;
	u64 *src = (u64 *)walk->src.virt.addr;
	u64 *dst = (u64 *)walk->dst.virt.addr;
	u64 last_iv;

	/* Start of the last block. */
	src += nbytes / bsize - 1;
	dst += nbytes / bsize - 1;

	last_iv = *src;

	/* Process multi-block batch */
	if (nbytes >= bsize * CAST5_PARALLEL_BLOCKS) {
		do {
			nbytes -= bsize * (CAST5_PARALLEL_BLOCKS - 1);
			src -= CAST5_PARALLEL_BLOCKS - 1;
			dst -= CAST5_PARALLEL_BLOCKS - 1;

			cast5_cbc_dec_16way(ctx, (u8 *)dst, (u8 *)src);

			nbytes -= bsize;
			if (nbytes < bsize)
				goto done;

			*dst ^= *(src - 1);
			src -= 1;
			dst -= 1;
		} while (nbytes >= bsize * CAST5_PARALLEL_BLOCKS);
	}

	/* Handle leftovers */
	for (;;) {
		__cast5_decrypt(ctx, (u8 *)dst, (u8 *)src);

		nbytes -= bsize;
		if (nbytes < bsize)
			break;

		*dst ^= *(src - 1);
		src -= 1;
		dst -= 1;
	}

done:
	*dst ^= *(u64 *)walk->iv;
	*(u64 *)walk->iv = last_iv;

	return nbytes;
}

__attribute__((used)) static int cbc_decrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct cast5_ctx *ctx = crypto_skcipher_ctx(tfm);
	bool fpu_enabled = false;
	struct skcipher_walk walk;
	unsigned int nbytes;
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while ((nbytes = walk.nbytes)) {
		fpu_enabled = cast5_fpu_begin(fpu_enabled, &walk, nbytes);
		nbytes = __cbc_decrypt(ctx, &walk);
		err = skcipher_walk_done(&walk, nbytes);
	}

	cast5_fpu_end(fpu_enabled);
	return err;
}

__attribute__((used)) static void ctr_crypt_final(struct skcipher_walk *walk, struct cast5_ctx *ctx)
{
	u8 *ctrblk = walk->iv;
	u8 keystream[CAST5_BLOCK_SIZE];
	u8 *src = walk->src.virt.addr;
	u8 *dst = walk->dst.virt.addr;
	unsigned int nbytes = walk->nbytes;

	__cast5_encrypt(ctx, keystream, ctrblk);
	crypto_xor_cpy(dst, keystream, src, nbytes);

	crypto_inc(ctrblk, CAST5_BLOCK_SIZE);
}

__attribute__((used)) static unsigned int __ctr_crypt(struct skcipher_walk *walk,
				struct cast5_ctx *ctx)
{
	const unsigned int bsize = CAST5_BLOCK_SIZE;
	unsigned int nbytes = walk->nbytes;
	u64 *src = (u64 *)walk->src.virt.addr;
	u64 *dst = (u64 *)walk->dst.virt.addr;

	/* Process multi-block batch */
	if (nbytes >= bsize * CAST5_PARALLEL_BLOCKS) {
		do {
			cast5_ctr_16way(ctx, (u8 *)dst, (u8 *)src,
					(__be64 *)walk->iv);

			src += CAST5_PARALLEL_BLOCKS;
			dst += CAST5_PARALLEL_BLOCKS;
			nbytes -= bsize * CAST5_PARALLEL_BLOCKS;
		} while (nbytes >= bsize * CAST5_PARALLEL_BLOCKS);

		if (nbytes < bsize)
			goto done;
	}

	/* Handle leftovers */
	do {
		u64 ctrblk;

		if (dst != src)
			*dst = *src;

		ctrblk = *(u64 *)walk->iv;
		be64_add_cpu((__be64 *)walk->iv, 1);

		__cast5_encrypt(ctx, (u8 *)&ctrblk, (u8 *)&ctrblk);
		*dst ^= ctrblk;

		src += 1;
		dst += 1;
		nbytes -= bsize;
	} while (nbytes >= bsize);

done:
	return nbytes;
}

__attribute__((used)) static int ctr_crypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct cast5_ctx *ctx = crypto_skcipher_ctx(tfm);
	bool fpu_enabled = false;
	struct skcipher_walk walk;
	unsigned int nbytes;
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while ((nbytes = walk.nbytes) >= CAST5_BLOCK_SIZE) {
		fpu_enabled = cast5_fpu_begin(fpu_enabled, &walk, nbytes);
		nbytes = __ctr_crypt(&walk, ctx);
		err = skcipher_walk_done(&walk, nbytes);
	}

	cast5_fpu_end(fpu_enabled);

	if (walk.nbytes) {
		ctr_crypt_final(&walk, ctx);
		err = skcipher_walk_done(&walk, 0);
	}

	return err;
}

