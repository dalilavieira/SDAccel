#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int ut32 ;
typedef  scalar_t__ off_t ;
struct TYPE_7__ {int key_len; int value_len; scalar_t__ value; scalar_t__ key; } ;
struct TYPE_8__ {TYPE_1__ base; } ;
typedef  TYPE_2__ SdbKv ;

/* Variables and functions */
 int /*<<< orphan*/  SEEK_SET ; 
 char* cb64 ; 
 int* cd64 ; 
 int lseek (int,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int seek_set(int fd, off_t pos) {
	return ((fd == -1) || (lseek (fd, (off_t) pos, SEEK_SET) == -1))? 0:1;
}

__attribute__((used)) static inline void ut32_pack(char s[4], ut32 u) {
	s[0] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	s[3] = u >> 8;
}

__attribute__((used)) static inline void ut32_pack_big(char s[4], ut32 u) {
	s[3] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	s[0] = u >> 8;
}

__attribute__((used)) static inline void ut32_unpack(char s[4], ut32 *u) {
	ut32 result = 0;
	result = (ut8) s[3];
	result <<= 8;
	result += (ut8) s[2];
	result <<= 8;
	result += (ut8) s[1];
	result <<= 8;
	result += (ut8) s[0];
	*u = result;
}

__attribute__((used)) static inline char *sdbkv_key(const SdbKv *kv) {
	return (char *)kv->base.key;
}

__attribute__((used)) static inline char *sdbkv_value(const SdbKv *kv) {
	return (char *)kv->base.value;
}

__attribute__((used)) static inline ut32 sdbkv_key_len(const SdbKv *kv) {
	return kv->base.key_len;
}

__attribute__((used)) static inline ut32 sdbkv_value_len(const SdbKv *kv) {
	return kv->base.value_len;
}

__attribute__((used)) static void sdb_b64_encode(const ut8 in[3], char out[4], int len) {
	if (len < 1) {
		return;
	}
	out[0] = cb64[ in[0] >> 2 ];
	out[1] = cb64[ ((in[0] & 0x03) << 4) | ((len>1)?((in[1] & 0xf0) >> 4):0) ];
	out[2] = (len > 1 ? cb64[ ((in[1] & 0x0f) << 2) | (len > 2 ? ((in[2] & 0xc0) >> 6) : 0) ] : '=');
	out[3] = (len > 2 ? cb64[ in[2] & 0x3f ] : '=');
}

__attribute__((used)) static int sdb_b64_decode(const char in[4], ut8 out[3]) {
	int len = 3;
	ut8 i, v[4] = {0};
	for (i = 0; i < 4; i++) {
		if (in[i] < '+' || in[i] > 'z') {
			return -1;
		}
		v[i] = cd64[in[i] - '+'];
		if (v[i] == '$') {
			len = i ? i - 1: -1;
			break;
		}
		v[i] -= 62;
	}
	out[0] = v[0] << 2 | v[1] >> 4;
	out[1] = v[1] << 4 | v[2] >> 2;
	out[2] = ((v[2] << 6) & 0xc0) | v[3];
	return len;
}

