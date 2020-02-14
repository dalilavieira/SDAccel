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
struct sha1_state {unsigned int count; } ;
typedef  int /*<<< orphan*/  sha1_block_fn ;

/* Variables and functions */
 unsigned int SHA1_BLOCK_SIZE ; 
 int /*<<< orphan*/  kernel_neon_begin () ; 
 int /*<<< orphan*/  kernel_neon_end () ; 
 int /*<<< orphan*/  may_use_simd () ; 
 int /*<<< orphan*/  sha1_base_do_finalize (struct shash_desc*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sha1_base_do_update (struct shash_desc*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *) ; 
 int sha1_base_finish (struct shash_desc*,int /*<<< orphan*/ *) ; 
 int sha1_finup_arm (struct shash_desc*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *) ; 
 scalar_t__ sha1_transform_neon ; 
 int sha1_update_arm (struct shash_desc*,int /*<<< orphan*/  const*,unsigned int) ; 
 struct sha1_state* shash_desc_ctx (struct shash_desc*) ; 

__attribute__((used)) static int sha1_neon_update(struct shash_desc *desc, const u8 *data,
			  unsigned int len)
{
	struct sha1_state *sctx = shash_desc_ctx(desc);

	if (!may_use_simd() ||
	    (sctx->count % SHA1_BLOCK_SIZE) + len < SHA1_BLOCK_SIZE)
		return sha1_update_arm(desc, data, len);

	kernel_neon_begin();
	sha1_base_do_update(desc, data, len,
			    (sha1_block_fn *)sha1_transform_neon);
	kernel_neon_end();

	return 0;
}

__attribute__((used)) static int sha1_neon_finup(struct shash_desc *desc, const u8 *data,
			   unsigned int len, u8 *out)
{
	if (!may_use_simd())
		return sha1_finup_arm(desc, data, len, out);

	kernel_neon_begin();
	if (len)
		sha1_base_do_update(desc, data, len,
				    (sha1_block_fn *)sha1_transform_neon);
	sha1_base_do_finalize(desc, (sha1_block_fn *)sha1_transform_neon);
	kernel_neon_end();

	return sha1_base_finish(desc, out);
}

__attribute__((used)) static int sha1_neon_final(struct shash_desc *desc, u8 *out)
{
	return sha1_neon_finup(desc, NULL, 0, out);
}

