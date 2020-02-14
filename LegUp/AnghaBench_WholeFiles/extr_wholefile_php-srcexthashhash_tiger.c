#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zend_object ;
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  php_hashcontext_object ;
struct TYPE_4__ {int passed; int length; int* buffer; int* state; int /*<<< orphan*/  passes; } ;
typedef  TYPE_1__ PHP_TIGER_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  tiger_compress (int /*<<< orphan*/ ,int*,int*) ; 

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

__attribute__((used)) static inline void TigerFinalize(PHP_TIGER_CTX *context)
{
	context->passed += (uint64_t) context->length << 3;

	context->buffer[context->length++] = 0x1;
	if (context->length % 8) {
		memset(&context->buffer[context->length], 0, 8-context->length%8);
		context->length += 8-context->length%8;
	}

	if (context->length > 56) {
		memset(&context->buffer[context->length], 0, 64 - context->length);
		tiger_compress(context->passes, ((uint64_t *) context->buffer), context->state);
		memset(context->buffer, 0, 56);
	} else {
		memset(&context->buffer[context->length], 0, 56 - context->length);
	}

#ifndef WORDS_BIGENDIAN
	memcpy(&context->buffer[56], &context->passed, sizeof(uint64_t));
#else
	context->buffer[56] = (unsigned char) (context->passed & 0xff);
	context->buffer[57] = (unsigned char) ((context->passed >> 8) & 0xff);
	context->buffer[58] = (unsigned char) ((context->passed >> 16) & 0xff);
	context->buffer[59] = (unsigned char) ((context->passed >> 24) & 0xff);
	context->buffer[60] = (unsigned char) ((context->passed >> 32) & 0xff);
	context->buffer[61] = (unsigned char) ((context->passed >> 40) & 0xff);
	context->buffer[62] = (unsigned char) ((context->passed >> 48) & 0xff);
	context->buffer[63] = (unsigned char) ((context->passed >> 56) & 0xff);
#endif
	tiger_compress(context->passes, ((uint64_t *) context->buffer), context->state);
}

__attribute__((used)) static inline void TigerDigest(unsigned char *digest_str, unsigned int digest_len, PHP_TIGER_CTX *context)
{
	unsigned int i;

	for (i = 0; i < digest_len; ++i) {
		digest_str[i] = (unsigned char) ((context->state[i/8] >> (8 * (i%8))) & 0xff);
	}
}

