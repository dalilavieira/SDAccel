#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int ut32 ;
typedef  scalar_t__ off_t ;
struct TYPE_10__ {int key_len; int value_len; void* value; void* key; } ;
struct TYPE_9__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_11__ {TYPE_2__ base; scalar_t__ expire; TYPE_1__ member_0; } ;
typedef  TYPE_3__ SdbKv ;
typedef  int /*<<< orphan*/  HtPPKv ;
typedef  int /*<<< orphan*/  HtPP ;

/* Variables and functions */
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  free (void*) ; 
 int ht_pp_insert_kv (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int lseek (int,scalar_t__,int /*<<< orphan*/ ) ; 
 void* strdup (void*) ; 
 void* strlen (void*) ; 

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

void sdbkv_fini(SdbKv *kv) {
	free (kv->base.key);
	free (kv->base.value);
}

__attribute__((used)) static bool sdb_ht_internal_insert(HtPP* ht, const char* key,
				    const char* value, bool update) {
	if (!ht || !key || !value) {
		return false;
	}
	SdbKv kvp = {{ 0 }};
	kvp.base.key = strdup ((void *)key);
	if (!kvp.base.key) {
		goto err;
	}
	kvp.base.value = strdup ((void *)value);
	if (!kvp.base.value) {
		goto err;
	}
	kvp.base.key_len = strlen (kvp.base.key);
	kvp.base.value_len = strlen (kvp.base.value);
	kvp.expire = 0;
	return ht_pp_insert_kv (ht, (HtPPKv*)&kvp, update);

 err:
	free (kvp.base.key);
	free (kvp.base.value);
	return false;
}

