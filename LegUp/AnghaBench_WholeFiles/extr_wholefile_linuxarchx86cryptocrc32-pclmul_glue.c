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
typedef  scalar_t__ u32 ;
struct shash_desc {struct crypto_shash* tfm; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_shash {int dummy; } ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_TFM_RES_BAD_KEY_LEN ; 
 int EINVAL ; 
 int /*<<< orphan*/  cpu_to_le32 (scalar_t__) ; 
 int /*<<< orphan*/  cpu_to_le32p (scalar_t__*) ; 
 scalar_t__ crc32_pclmul_le (scalar_t__,int /*<<< orphan*/  const*,unsigned int) ; 
 scalar_t__* crypto_shash_ctx (struct crypto_shash*) ; 
 int /*<<< orphan*/  crypto_shash_set_flags (struct crypto_shash*,int /*<<< orphan*/ ) ; 
 scalar_t__* crypto_tfm_ctx (struct crypto_tfm*) ; 
 scalar_t__ le32_to_cpup (int /*<<< orphan*/ *) ; 
 scalar_t__* shash_desc_ctx (struct shash_desc*) ; 

__attribute__((used)) static int crc32_pclmul_cra_init(struct crypto_tfm *tfm)
{
	u32 *key = crypto_tfm_ctx(tfm);

	*key = 0;

	return 0;
}

__attribute__((used)) static int crc32_pclmul_setkey(struct crypto_shash *hash, const u8 *key,
			unsigned int keylen)
{
	u32 *mctx = crypto_shash_ctx(hash);

	if (keylen != sizeof(u32)) {
		crypto_shash_set_flags(hash, CRYPTO_TFM_RES_BAD_KEY_LEN);
		return -EINVAL;
	}
	*mctx = le32_to_cpup((__le32 *)key);
	return 0;
}

__attribute__((used)) static int crc32_pclmul_init(struct shash_desc *desc)
{
	u32 *mctx = crypto_shash_ctx(desc->tfm);
	u32 *crcp = shash_desc_ctx(desc);

	*crcp = *mctx;

	return 0;
}

__attribute__((used)) static int crc32_pclmul_update(struct shash_desc *desc, const u8 *data,
			       unsigned int len)
{
	u32 *crcp = shash_desc_ctx(desc);

	*crcp = crc32_pclmul_le(*crcp, data, len);
	return 0;
}

__attribute__((used)) static int __crc32_pclmul_finup(u32 *crcp, const u8 *data, unsigned int len,
				u8 *out)
{
	*(__le32 *)out = cpu_to_le32(crc32_pclmul_le(*crcp, data, len));
	return 0;
}

__attribute__((used)) static int crc32_pclmul_finup(struct shash_desc *desc, const u8 *data,
			      unsigned int len, u8 *out)
{
	return __crc32_pclmul_finup(shash_desc_ctx(desc), data, len, out);
}

__attribute__((used)) static int crc32_pclmul_final(struct shash_desc *desc, u8 *out)
{
	u32 *crcp = shash_desc_ctx(desc);

	*(__le32 *)out = cpu_to_le32p(crcp);
	return 0;
}

__attribute__((used)) static int crc32_pclmul_digest(struct shash_desc *desc, const u8 *data,
			       unsigned int len, u8 *out)
{
	return __crc32_pclmul_finup(crypto_shash_ctx(desc->tfm), data, len,
				    out);
}

