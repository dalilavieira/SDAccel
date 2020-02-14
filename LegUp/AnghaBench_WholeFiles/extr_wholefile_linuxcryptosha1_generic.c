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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  temp ;
struct shash_desc {int dummy; } ;
struct sha1_state {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  SHA1_BLOCK_SIZE ; 
 int SHA_WORKSPACE_WORDS ; 
 int /*<<< orphan*/  memzero_explicit (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sha1_base_do_finalize (struct shash_desc*,void (*) (struct sha1_state*,int /*<<< orphan*/  const*,int)) ; 
 int sha1_base_do_update (struct shash_desc*,int /*<<< orphan*/  const*,unsigned int,void (*) (struct sha1_state*,int /*<<< orphan*/  const*,int)) ; 
 int sha1_base_finish (struct shash_desc*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sha_transform (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sha1_generic_block_fn(struct sha1_state *sst, u8 const *src,
				  int blocks)
{
	u32 temp[SHA_WORKSPACE_WORDS];

	while (blocks--) {
		sha_transform(sst->state, src, temp);
		src += SHA1_BLOCK_SIZE;
	}
	memzero_explicit(temp, sizeof(temp));
}

int crypto_sha1_update(struct shash_desc *desc, const u8 *data,
		       unsigned int len)
{
	return sha1_base_do_update(desc, data, len, sha1_generic_block_fn);
}

__attribute__((used)) static int sha1_final(struct shash_desc *desc, u8 *out)
{
	sha1_base_do_finalize(desc, sha1_generic_block_fn);
	return sha1_base_finish(desc, out);
}

int crypto_sha1_finup(struct shash_desc *desc, const u8 *data,
		      unsigned int len, u8 *out)
{
	sha1_base_do_update(desc, data, len, sha1_generic_block_fn);
	return sha1_final(desc, out);
}

