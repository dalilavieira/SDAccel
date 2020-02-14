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
typedef  int /*<<< orphan*/  v ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  u ;
typedef  int /*<<< orphan*/  php_hashcontext_object ;
struct TYPE_4__ {int* state; int /*<<< orphan*/ * tables; } ;
typedef  TYPE_1__ PHP_GOST_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  PASS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SHIFT12 (int*,int*,int*) ; 
 int /*<<< orphan*/  SHIFT16 (int*,int*,int*) ; 
 int /*<<< orphan*/  SHIFT61 (int*,int*) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 

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

__attribute__((used)) static inline void Gost(PHP_GOST_CTX *context, uint32_t data[8])
{
	int i;
	uint32_t l, r, t, key[8], u[8], v[8], w[8], s[8], *h = context->state, *m = data;

	memcpy(u, context->state, sizeof(u));
	memcpy(v, data, sizeof(v));

	for (i = 0; i < 8; i += 2) {
		PASS(*context->tables);
	}
	SHIFT12(u, m, s);
	SHIFT16(h, v, u);
	SHIFT61(h, v);
}

__attribute__((used)) static inline void GostTransform(PHP_GOST_CTX *context, const unsigned char input[32])
{
	int i, j;
	uint32_t data[8], temp = 0;

	for (i = 0, j = 0; i < 8; ++i, j += 4) {
		data[i] =	((uint32_t) input[j]) | (((uint32_t) input[j + 1]) << 8) |
					(((uint32_t) input[j + 2]) << 16) | (((uint32_t) input[j + 3]) << 24);
		context->state[i + 8] += data[i] + temp;
		temp = context->state[i + 8] < data[i] ? 1 : (context->state[i + 8] == data[i] ? temp : 0);
	}

	Gost(context, data);
}

