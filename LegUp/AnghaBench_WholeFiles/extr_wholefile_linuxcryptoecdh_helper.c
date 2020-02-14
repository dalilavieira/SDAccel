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
typedef  void u8 ;
struct kpp_secret {scalar_t__ type; unsigned int len; } ;
struct ecdh {unsigned int key_size; void* key; int /*<<< orphan*/  curve_id; } ;
typedef  int /*<<< orphan*/  secret ;

/* Variables and functions */
 scalar_t__ CRYPTO_KPP_SECRET_TYPE_ECDH ; 
 unsigned int ECDH_KPP_SECRET_MIN_SIZE ; 
 int EINVAL ; 
 int /*<<< orphan*/  memcpy (void*,void const*,size_t) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline u8 *ecdh_pack_data(void *dst, const void *src, size_t sz)
{
	memcpy(dst, src, sz);
	return dst + sz;
}

__attribute__((used)) static inline const u8 *ecdh_unpack_data(void *dst, const void *src, size_t sz)
{
	memcpy(dst, src, sz);
	return src + sz;
}

unsigned int crypto_ecdh_key_len(const struct ecdh *params)
{
	return ECDH_KPP_SECRET_MIN_SIZE + params->key_size;
}

int crypto_ecdh_encode_key(char *buf, unsigned int len,
			   const struct ecdh *params)
{
	u8 *ptr = buf;
	struct kpp_secret secret = {
		.type = CRYPTO_KPP_SECRET_TYPE_ECDH,
		.len = len
	};

	if (unlikely(!buf))
		return -EINVAL;

	if (len != crypto_ecdh_key_len(params))
		return -EINVAL;

	ptr = ecdh_pack_data(ptr, &secret, sizeof(secret));
	ptr = ecdh_pack_data(ptr, &params->curve_id, sizeof(params->curve_id));
	ptr = ecdh_pack_data(ptr, &params->key_size, sizeof(params->key_size));
	ecdh_pack_data(ptr, params->key, params->key_size);

	return 0;
}

int crypto_ecdh_decode_key(const char *buf, unsigned int len,
			   struct ecdh *params)
{
	const u8 *ptr = buf;
	struct kpp_secret secret;

	if (unlikely(!buf || len < ECDH_KPP_SECRET_MIN_SIZE))
		return -EINVAL;

	ptr = ecdh_unpack_data(&secret, ptr, sizeof(secret));
	if (secret.type != CRYPTO_KPP_SECRET_TYPE_ECDH)
		return -EINVAL;

	ptr = ecdh_unpack_data(&params->curve_id, ptr, sizeof(params->curve_id));
	ptr = ecdh_unpack_data(&params->key_size, ptr, sizeof(params->key_size));
	if (secret.len != crypto_ecdh_key_len(params))
		return -EINVAL;

	/* Don't allocate memory. Set pointer to data
	 * within the given buffer
	 */
	params->key = (void *)ptr;

	return 0;
}

