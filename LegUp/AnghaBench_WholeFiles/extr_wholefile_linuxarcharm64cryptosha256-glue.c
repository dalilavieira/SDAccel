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
struct shash_desc {int dummy; } ;
struct sha256_state {unsigned int count; } ;
typedef  int /*<<< orphan*/  sha256_block_fn ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_PREEMPT ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 unsigned int SHA256_BLOCK_SIZE ; 
 int /*<<< orphan*/  kernel_neon_begin () ; 
 int /*<<< orphan*/  kernel_neon_end () ; 
 int /*<<< orphan*/  may_use_simd () ; 
 int /*<<< orphan*/  sha256_base_do_finalize (struct shash_desc*,int /*<<< orphan*/ *) ; 
 int sha256_base_do_update (struct shash_desc*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *) ; 
 int sha256_base_finish (struct shash_desc*,int /*<<< orphan*/ *) ; 
 scalar_t__ sha256_block_data_order ; 
 scalar_t__ sha256_block_neon ; 
 struct sha256_state* shash_desc_ctx (struct shash_desc*) ; 

__attribute__((used)) static int sha256_update(struct shash_desc *desc, const u8 *data,
			 unsigned int len)
{
	return sha256_base_do_update(desc, data, len,
				(sha256_block_fn *)sha256_block_data_order);
}

__attribute__((used)) static int sha256_finup(struct shash_desc *desc, const u8 *data,
			unsigned int len, u8 *out)
{
	if (len)
		sha256_base_do_update(desc, data, len,
				(sha256_block_fn *)sha256_block_data_order);
	sha256_base_do_finalize(desc,
				(sha256_block_fn *)sha256_block_data_order);

	return sha256_base_finish(desc, out);
}

__attribute__((used)) static int sha256_final(struct shash_desc *desc, u8 *out)
{
	return sha256_finup(desc, NULL, 0, out);
}

__attribute__((used)) static int sha256_update_neon(struct shash_desc *desc, const u8 *data,
			      unsigned int len)
{
	struct sha256_state *sctx = shash_desc_ctx(desc);

	if (!may_use_simd())
		return sha256_base_do_update(desc, data, len,
				(sha256_block_fn *)sha256_block_data_order);

	while (len > 0) {
		unsigned int chunk = len;

		/*
		 * Don't hog the CPU for the entire time it takes to process all
		 * input when running on a preemptible kernel, but process the
		 * data block by block instead.
		 */
		if (IS_ENABLED(CONFIG_PREEMPT) &&
		    chunk + sctx->count % SHA256_BLOCK_SIZE > SHA256_BLOCK_SIZE)
			chunk = SHA256_BLOCK_SIZE -
				sctx->count % SHA256_BLOCK_SIZE;

		kernel_neon_begin();
		sha256_base_do_update(desc, data, chunk,
				      (sha256_block_fn *)sha256_block_neon);
		kernel_neon_end();
		data += chunk;
		len -= chunk;
	}
	return 0;
}

__attribute__((used)) static int sha256_finup_neon(struct shash_desc *desc, const u8 *data,
			     unsigned int len, u8 *out)
{
	if (!may_use_simd()) {
		if (len)
			sha256_base_do_update(desc, data, len,
				(sha256_block_fn *)sha256_block_data_order);
		sha256_base_do_finalize(desc,
				(sha256_block_fn *)sha256_block_data_order);
	} else {
		if (len)
			sha256_update_neon(desc, data, len);
		kernel_neon_begin();
		sha256_base_do_finalize(desc,
				(sha256_block_fn *)sha256_block_neon);
		kernel_neon_end();
	}
	return sha256_base_finish(desc, out);
}

__attribute__((used)) static int sha256_final_neon(struct shash_desc *desc, u8 *out)
{
	return sha256_finup_neon(desc, NULL, 0, out);
}

