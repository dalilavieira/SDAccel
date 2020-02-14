#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  const u8 ;
typedef  int u64 ;
typedef  int u32 ;
struct TYPE_8__ {int /*<<< orphan*/  const* addr; } ;
struct TYPE_9__ {TYPE_3__ virt; } ;
struct TYPE_6__ {int /*<<< orphan*/  const* addr; } ;
struct TYPE_7__ {TYPE_1__ virt; } ;
struct skcipher_walk {unsigned int nbytes; int /*<<< orphan*/  const* iv; TYPE_4__ dst; TYPE_2__ src; } ;
struct skcipher_request {int dummy; } ;
struct des3_ede_x86_ctx {int* enc_expkey; int* dec_expkey; } ;
struct crypto_tfm {int /*<<< orphan*/  crt_flags; } ;
struct crypto_skcipher {struct crypto_tfm base; } ;
typedef  int __be64 ;
struct TYPE_10__ {scalar_t__ x86_vendor; int x86; } ;

/* Variables and functions */
 int DES3_EDE_BLOCK_SIZE ; 
 int DES3_EDE_EXPKEY_WORDS ; 
 scalar_t__ X86_VENDOR_INTEL ; 
 int __des3_ede_setkey (int*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,unsigned int) ; 
 int be64_to_cpu (int) ; 
 TYPE_5__ boot_cpu_data ; 
 int cpu_to_be64 (int) ; 
 int /*<<< orphan*/  crypto_inc (int /*<<< orphan*/  const*,int) ; 
 struct des3_ede_x86_ctx* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 struct crypto_skcipher* crypto_skcipher_reqtfm (struct skcipher_request*) ; 
 struct des3_ede_x86_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  crypto_xor_cpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  des3_ede_x86_64_crypt_blk (int const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  des3_ede_x86_64_crypt_blk_3way (int const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int ror32 (int,int) ; 
 int skcipher_walk_done (struct skcipher_walk*,unsigned int) ; 
 int skcipher_walk_virt (struct skcipher_walk*,struct skcipher_request*,int) ; 

__attribute__((used)) static inline void des3_ede_enc_blk(struct des3_ede_x86_ctx *ctx, u8 *dst,
				    const u8 *src)
{
	u32 *enc_ctx = ctx->enc_expkey;

	des3_ede_x86_64_crypt_blk(enc_ctx, dst, src);
}

__attribute__((used)) static inline void des3_ede_dec_blk(struct des3_ede_x86_ctx *ctx, u8 *dst,
				    const u8 *src)
{
	u32 *dec_ctx = ctx->dec_expkey;

	des3_ede_x86_64_crypt_blk(dec_ctx, dst, src);
}

__attribute__((used)) static inline void des3_ede_enc_blk_3way(struct des3_ede_x86_ctx *ctx, u8 *dst,
					 const u8 *src)
{
	u32 *enc_ctx = ctx->enc_expkey;

	des3_ede_x86_64_crypt_blk_3way(enc_ctx, dst, src);
}

__attribute__((used)) static inline void des3_ede_dec_blk_3way(struct des3_ede_x86_ctx *ctx, u8 *dst,
					 const u8 *src)
{
	u32 *dec_ctx = ctx->dec_expkey;

	des3_ede_x86_64_crypt_blk_3way(dec_ctx, dst, src);
}

__attribute__((used)) static void des3_ede_x86_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
	des3_ede_enc_blk(crypto_tfm_ctx(tfm), dst, src);
}

__attribute__((used)) static void des3_ede_x86_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
	des3_ede_dec_blk(crypto_tfm_ctx(tfm), dst, src);
}

__attribute__((used)) static int ecb_crypt(struct skcipher_request *req, const u32 *expkey)
{
	const unsigned int bsize = DES3_EDE_BLOCK_SIZE;
	struct skcipher_walk walk;
	unsigned int nbytes;
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while ((nbytes = walk.nbytes)) {
		u8 *wsrc = walk.src.virt.addr;
		u8 *wdst = walk.dst.virt.addr;

		/* Process four block batch */
		if (nbytes >= bsize * 3) {
			do {
				des3_ede_x86_64_crypt_blk_3way(expkey, wdst,
							       wsrc);

				wsrc += bsize * 3;
				wdst += bsize * 3;
				nbytes -= bsize * 3;
			} while (nbytes >= bsize * 3);

			if (nbytes < bsize)
				goto done;
		}

		/* Handle leftovers */
		do {
			des3_ede_x86_64_crypt_blk(expkey, wdst, wsrc);

			wsrc += bsize;
			wdst += bsize;
			nbytes -= bsize;
		} while (nbytes >= bsize);

done:
		err = skcipher_walk_done(&walk, nbytes);
	}

	return err;
}

__attribute__((used)) static int ecb_encrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct des3_ede_x86_ctx *ctx = crypto_skcipher_ctx(tfm);

	return ecb_crypt(req, ctx->enc_expkey);
}

__attribute__((used)) static int ecb_decrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct des3_ede_x86_ctx *ctx = crypto_skcipher_ctx(tfm);

	return ecb_crypt(req, ctx->dec_expkey);
}

__attribute__((used)) static unsigned int __cbc_encrypt(struct des3_ede_x86_ctx *ctx,
				  struct skcipher_walk *walk)
{
	unsigned int bsize = DES3_EDE_BLOCK_SIZE;
	unsigned int nbytes = walk->nbytes;
	u64 *src = (u64 *)walk->src.virt.addr;
	u64 *dst = (u64 *)walk->dst.virt.addr;
	u64 *iv = (u64 *)walk->iv;

	do {
		*dst = *src ^ *iv;
		des3_ede_enc_blk(ctx, (u8 *)dst, (u8 *)dst);
		iv = dst;

		src += 1;
		dst += 1;
		nbytes -= bsize;
	} while (nbytes >= bsize);

	*(u64 *)walk->iv = *iv;
	return nbytes;
}

__attribute__((used)) static int cbc_encrypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct des3_ede_x86_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct skcipher_walk walk;
	unsigned int nbytes;
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while ((nbytes = walk.nbytes)) {
		nbytes = __cbc_encrypt(ctx, &walk);
		err = skcipher_walk_done(&walk, nbytes);
	}

	return err;
}

__attribute__((used)) static unsigned int __cbc_decrypt(struct des3_ede_x86_ctx *ctx,
				  struct skcipher_walk *walk)
{
	unsigned int bsize = DES3_EDE_BLOCK_SIZE;
	unsigned int nbytes = walk->nbytes;
	u64 *src = (u64 *)walk->src.virt.addr;
	u64 *dst = (u64 *)walk->dst.virt.addr;
	u64 ivs[3 - 1];
	u64 last_iv;

	/* Start of the last block. */
	src += nbytes / bsize - 1;
	dst += nbytes / bsize - 1;

	last_iv = *src;

	/* Process four block batch */
	if (nbytes >= bsize * 3) {
		do {
			nbytes -= bsize * 3 - bsize;
			src -= 3 - 1;
			dst -= 3 - 1;

			ivs[0] = src[0];
			ivs[1] = src[1];

			des3_ede_dec_blk_3way(ctx, (u8 *)dst, (u8 *)src);

			dst[1] ^= ivs[0];
			dst[2] ^= ivs[1];

			nbytes -= bsize;
			if (nbytes < bsize)
				goto done;

			*dst ^= *(src - 1);
			src -= 1;
			dst -= 1;
		} while (nbytes >= bsize * 3);
	}

	/* Handle leftovers */
	for (;;) {
		des3_ede_dec_blk(ctx, (u8 *)dst, (u8 *)src);

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
	struct des3_ede_x86_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct skcipher_walk walk;
	unsigned int nbytes;
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while ((nbytes = walk.nbytes)) {
		nbytes = __cbc_decrypt(ctx, &walk);
		err = skcipher_walk_done(&walk, nbytes);
	}

	return err;
}

__attribute__((used)) static void ctr_crypt_final(struct des3_ede_x86_ctx *ctx,
			    struct skcipher_walk *walk)
{
	u8 *ctrblk = walk->iv;
	u8 keystream[DES3_EDE_BLOCK_SIZE];
	u8 *src = walk->src.virt.addr;
	u8 *dst = walk->dst.virt.addr;
	unsigned int nbytes = walk->nbytes;

	des3_ede_enc_blk(ctx, keystream, ctrblk);
	crypto_xor_cpy(dst, keystream, src, nbytes);

	crypto_inc(ctrblk, DES3_EDE_BLOCK_SIZE);
}

__attribute__((used)) static unsigned int __ctr_crypt(struct des3_ede_x86_ctx *ctx,
				struct skcipher_walk *walk)
{
	unsigned int bsize = DES3_EDE_BLOCK_SIZE;
	unsigned int nbytes = walk->nbytes;
	__be64 *src = (__be64 *)walk->src.virt.addr;
	__be64 *dst = (__be64 *)walk->dst.virt.addr;
	u64 ctrblk = be64_to_cpu(*(__be64 *)walk->iv);
	__be64 ctrblocks[3];

	/* Process four block batch */
	if (nbytes >= bsize * 3) {
		do {
			/* create ctrblks for parallel encrypt */
			ctrblocks[0] = cpu_to_be64(ctrblk++);
			ctrblocks[1] = cpu_to_be64(ctrblk++);
			ctrblocks[2] = cpu_to_be64(ctrblk++);

			des3_ede_enc_blk_3way(ctx, (u8 *)ctrblocks,
					      (u8 *)ctrblocks);

			dst[0] = src[0] ^ ctrblocks[0];
			dst[1] = src[1] ^ ctrblocks[1];
			dst[2] = src[2] ^ ctrblocks[2];

			src += 3;
			dst += 3;
		} while ((nbytes -= bsize * 3) >= bsize * 3);

		if (nbytes < bsize)
			goto done;
	}

	/* Handle leftovers */
	do {
		ctrblocks[0] = cpu_to_be64(ctrblk++);

		des3_ede_enc_blk(ctx, (u8 *)ctrblocks, (u8 *)ctrblocks);

		dst[0] = src[0] ^ ctrblocks[0];

		src += 1;
		dst += 1;
	} while ((nbytes -= bsize) >= bsize);

done:
	*(__be64 *)walk->iv = cpu_to_be64(ctrblk);
	return nbytes;
}

__attribute__((used)) static int ctr_crypt(struct skcipher_request *req)
{
	struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
	struct des3_ede_x86_ctx *ctx = crypto_skcipher_ctx(tfm);
	struct skcipher_walk walk;
	unsigned int nbytes;
	int err;

	err = skcipher_walk_virt(&walk, req, false);

	while ((nbytes = walk.nbytes) >= DES3_EDE_BLOCK_SIZE) {
		nbytes = __ctr_crypt(ctx, &walk);
		err = skcipher_walk_done(&walk, nbytes);
	}

	if (nbytes) {
		ctr_crypt_final(ctx, &walk);
		err = skcipher_walk_done(&walk, 0);
	}

	return err;
}

__attribute__((used)) static int des3_ede_x86_setkey(struct crypto_tfm *tfm, const u8 *key,
			       unsigned int keylen)
{
	struct des3_ede_x86_ctx *ctx = crypto_tfm_ctx(tfm);
	u32 i, j, tmp;
	int err;

	/* Generate encryption context using generic implementation. */
	err = __des3_ede_setkey(ctx->enc_expkey, &tfm->crt_flags, key, keylen);
	if (err < 0)
		return err;

	/* Fix encryption context for this implementation and form decryption
	 * context. */
	j = DES3_EDE_EXPKEY_WORDS - 2;
	for (i = 0; i < DES3_EDE_EXPKEY_WORDS; i += 2, j -= 2) {
		tmp = ror32(ctx->enc_expkey[i + 1], 4);
		ctx->enc_expkey[i + 1] = tmp;

		ctx->dec_expkey[j + 0] = ctx->enc_expkey[i + 0];
		ctx->dec_expkey[j + 1] = tmp;
	}

	return 0;
}

__attribute__((used)) static int des3_ede_x86_setkey_skcipher(struct crypto_skcipher *tfm,
					const u8 *key,
					unsigned int keylen)
{
	return des3_ede_x86_setkey(&tfm->base, key, keylen);
}

__attribute__((used)) static bool is_blacklisted_cpu(void)
{
	if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
		return false;

	if (boot_cpu_data.x86 == 0x0f) {
		/*
		 * On Pentium 4, des3_ede-x86_64 is slower than generic C
		 * implementation because use of 64bit rotates (which are really
		 * slow on P4). Therefore blacklist P4s.
		 */
		return true;
	}

	return false;
}

