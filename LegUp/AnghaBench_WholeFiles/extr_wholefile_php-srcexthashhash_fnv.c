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
typedef  int /*<<< orphan*/  zend_object ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  php_hashcontext_object ;

/* Variables and functions */
 int /*<<< orphan*/  PHP_FNV_32_PRIME ; 
 int /*<<< orphan*/  PHP_FNV_64_PRIME ; 

__attribute__((used)) static inline php_hashcontext_object *php_hashcontext_from_object(zend_object *obj) {
	return ((php_hashcontext_object*)(obj + 1)) - 1;
}

__attribute__((used)) static inline void php_hash_bin2hex(char *out, const unsigned char *in, size_t in_len)
{
	static const char hexits[17] = "0123456789abcdef";
	size_t i;

	for(i = 0; i < in_len; i++) {
		out[i * 2]       = hexits[in[i] >> 4];
		out[(i * 2) + 1] = hexits[in[i] &  0x0F];
	}
}

__attribute__((used)) static uint32_t
fnv_32_buf(void *buf, size_t len, uint32_t hval, int alternate)
{
	unsigned char *bp = (unsigned char *)buf;   /* start of buffer */
	unsigned char *be = bp + len;	   /* beyond end of buffer */

	/*
	 * FNV-1 hash each octet in the buffer
	 */
	if (alternate == 0) {
		while (bp < be) {
			/* multiply by the 32 bit FNV magic prime mod 2^32 */
			hval *= PHP_FNV_32_PRIME;

			/* xor the bottom with the current octet */
			hval ^= (uint32_t)*bp++;
		}
	} else {
		while (bp < be) {
			/* xor the bottom with the current octet */
			hval ^= (uint32_t)*bp++;

			/* multiply by the 32 bit FNV magic prime mod 2^32 */
			hval *= PHP_FNV_32_PRIME;
		}
	}

	/* return our new hash value */
	return hval;
}

__attribute__((used)) static uint64_t
fnv_64_buf(void *buf, size_t len, uint64_t hval, int alternate)
{
	unsigned char *bp = (unsigned char *)buf;   /* start of buffer */
	unsigned char *be = bp + len;	   /* beyond end of buffer */

	/*
	 * FNV-1 hash each octet of the buffer
	 */

	if (alternate == 0) {
		while (bp < be) {
			/* multiply by the 64 bit FNV magic prime mod 2^64 */
			hval *= PHP_FNV_64_PRIME;

			/* xor the bottom with the current octet */
			hval ^= (uint64_t)*bp++;
		}
	 } else {
		while (bp < be) {
			/* xor the bottom with the current octet */
			hval ^= (uint64_t)*bp++;

			/* multiply by the 64 bit FNV magic prime mod 2^64 */
			hval *= PHP_FNV_64_PRIME;
		 }
	}

	/* return our new hash value */
	return hval;
}

