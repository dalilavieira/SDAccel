#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zend_object ;
typedef  int /*<<< orphan*/  php_hashcontext_object ;
struct TYPE_2__ {int /*<<< orphan*/  hashinstance; } ;
typedef  TYPE_1__ PHP_SHA3_CTX ;
typedef  int /*<<< orphan*/  Keccak_HashInstance ;

/* Variables and functions */
 int SUCCESS ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

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

__attribute__((used)) static int hash_sha3_copy(const void *ops, void *orig_context, void *dest_context)
{
	PHP_SHA3_CTX* orig = (PHP_SHA3_CTX*)orig_context;
	PHP_SHA3_CTX* dest = (PHP_SHA3_CTX*)dest_context;
	memcpy(dest->hashinstance, orig->hashinstance, sizeof(Keccak_HashInstance));
	return SUCCESS;
}

