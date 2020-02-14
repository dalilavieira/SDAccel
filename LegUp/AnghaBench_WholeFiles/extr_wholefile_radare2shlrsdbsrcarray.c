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
typedef  scalar_t__ ut64 ;
typedef  int ut32 ;
typedef  scalar_t__ off_t ;
struct TYPE_7__ {int key_len; int value_len; scalar_t__ value; scalar_t__ key; } ;
struct TYPE_8__ {TYPE_1__ base; } ;
typedef  TYPE_2__ SdbKv ;

/* Variables and functions */
 char SDB_RS ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int lseek (int,scalar_t__,int /*<<< orphan*/ ) ; 
 char* strchr (char const*,char) ; 

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

__attribute__((used)) static const char *Aindexof(const char *str, int idx) {
	int len = 0;
	const char *n, *p = str;
	for (len = 0; ; len++) {
		if (len == idx) {
			return p;
		}
		if (!(n = strchr (p, SDB_RS))) {
			break;
		}
		p = n + 1;
	}
	return NULL;
}

__attribute__((used)) static int astrcmp(const char *a, const char *b) {
	register char va = *a;
	register char vb = *b;
	for (;;) {
		if (va == '\0' || va == SDB_RS) {
			if (vb == '\0' || vb == SDB_RS) {
				return 0;
			}
			return -1;
		}
		if (vb == '\0' || vb == SDB_RS) {
			return 1;
		}
		if (va != vb) {
			return (va > vb) ? 1 : -1;
		}
		va = *(++a);
		vb = *(++b);
	}
}

__attribute__((used)) static inline int cstring_cmp(const void *a, const void *b) { 
	const char **va = (const char **)a;
	const char **vb = (const char **)b;
	return astrcmp (*va, *vb);
}

__attribute__((used)) static inline int int_cmp(const void *a, const void *b) { 
	const ut64 va = *(const ut64 *)a;
	const ut64 vb = *(const ut64 *)b;
	if (va > vb) {
		return 1;
	}
	if (va < vb) {
		return -1;
	}
	return 0;
}

