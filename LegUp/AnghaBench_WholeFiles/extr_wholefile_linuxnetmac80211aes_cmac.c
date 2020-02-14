#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct crypto_shash {int dummy; } ;
struct TYPE_6__ {struct crypto_shash* tfm; } ;

/* Variables and functions */
 scalar_t__ AAD_LEN ; 
 int AES_BLOCK_SIZE ; 
 scalar_t__ CMAC_TLEN ; 
 scalar_t__ CMAC_TLEN_256 ; 
 int /*<<< orphan*/  IS_ERR (struct crypto_shash*) ; 
 int /*<<< orphan*/  SHASH_DESC_ON_STACK (TYPE_1__*,struct crypto_shash*) ; 
 struct crypto_shash* crypto_alloc_shash (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_free_shash (struct crypto_shash*) ; 
 int /*<<< orphan*/  crypto_shash_finup (TYPE_1__*,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  crypto_shash_init (TYPE_1__*) ; 
 int /*<<< orphan*/  crypto_shash_setkey (struct crypto_shash*,int /*<<< orphan*/  const*,size_t) ; 
 int /*<<< orphan*/  crypto_shash_update (TYPE_1__*,int /*<<< orphan*/  const*,scalar_t__) ; 
 TYPE_1__* desc ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  zero ; 

void ieee80211_aes_cmac(struct crypto_shash *tfm, const u8 *aad,
			const u8 *data, size_t data_len, u8 *mic)
{
	SHASH_DESC_ON_STACK(desc, tfm);
	u8 out[AES_BLOCK_SIZE];

	desc->tfm = tfm;

	crypto_shash_init(desc);
	crypto_shash_update(desc, aad, AAD_LEN);
	crypto_shash_update(desc, data, data_len - CMAC_TLEN);
	crypto_shash_finup(desc, zero, CMAC_TLEN, out);

	memcpy(mic, out, CMAC_TLEN);
}

void ieee80211_aes_cmac_256(struct crypto_shash *tfm, const u8 *aad,
			    const u8 *data, size_t data_len, u8 *mic)
{
	SHASH_DESC_ON_STACK(desc, tfm);

	desc->tfm = tfm;

	crypto_shash_init(desc);
	crypto_shash_update(desc, aad, AAD_LEN);
	crypto_shash_update(desc, data, data_len - CMAC_TLEN_256);
	crypto_shash_finup(desc, zero, CMAC_TLEN_256, mic);
}

struct crypto_shash *ieee80211_aes_cmac_key_setup(const u8 key[],
						  size_t key_len)
{
	struct crypto_shash *tfm;

	tfm = crypto_alloc_shash("cmac(aes)", 0, 0);
	if (!IS_ERR(tfm))
		crypto_shash_setkey(tfm, key, key_len);

	return tfm;
}

void ieee80211_aes_cmac_key_free(struct crypto_shash *tfm)
{
	crypto_free_shash(tfm);
}

