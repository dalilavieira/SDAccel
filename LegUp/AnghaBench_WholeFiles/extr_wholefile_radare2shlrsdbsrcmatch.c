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
 int SDB_LIKE_BASE64 ; 
 int SDB_LIKE_END ; 
 int SDB_LIKE_ICASE ; 
 int SDB_LIKE_START ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  free (char*) ; 
 int lseek (int,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ sdb_decode (char const*,int*) ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 
 void* strlen (char const*) ; 
 int /*<<< orphan*/  strncmp (char const*,char const*,int const) ; 
 scalar_t__ tolower (int const) ; 

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

__attribute__((used)) static inline int haveSuffix(const char *glob, int glob_len, const char *sfx) {
	const int sfx_len = strlen (sfx);
	return (glob_len>sfx_len && !strcmp (glob+glob_len-sfx_len, sfx));
}

__attribute__((used)) static inline int havePrefix(const char *glob, int glob_len, const char *pfx) {
	const int pfx_len = strlen (pfx);
	return (pfx_len<glob_len && !strncmp (glob, pfx, pfx_len));
}

__attribute__((used)) static inline int mycmp(const char *a, const char *b, int n, int any) {
	int i, j;
	for (i = j = 0; a[i] && b[j] && j < n; i++) {
		if (tolower ((const ut8)a[i]) == tolower ((const ut8)b[j])) {
			j++;
		} else {
			if (!any) {
				return 0;
			}
			j = 0;
		}
	}
	return any? j != n: 1;
}

__attribute__((used)) static inline int strstr2(const char *a, const char *b, int n) {
	int i, j;
	for (i = j = 0; a[i] && b[j] && j < n; i++) {
		if (a[i] == b[j]) {
			j++;
		} else {
			j = 0;
		}
	}
	return j == n;
}

__attribute__((used)) static inline bool compareString(const char *a, const char *b, int blen, int flags) {
	const int start = flags & SDB_LIKE_START;
	const int end = flags & SDB_LIKE_END;
	char *aa = NULL;
	int alen;
	bool ret = false;
	if (!a || !b || blen < 0) {
		return 0;
	}
	if (flags & SDB_LIKE_BASE64) {
		aa = (char*)sdb_decode (a, &alen);
		if (!aa) {
			return 0;
		}
		a = (const char *)aa;
	} else {
		alen = strlen (a);
	}
	if (blen <= alen) {
		if (flags & SDB_LIKE_ICASE) {
			if (start && end) ret = (alen==blen && !mycmp (a, b, blen, 0));
			else if (start) ret = !mycmp (a, b, blen, 0);
			else if (end) ret = !mycmp (a+(alen-blen), b, blen, 0);
			else ret = !mycmp (a, b, blen, 1);
		} else {
			if (start && end) ret = (alen==blen && !strncmp (a, b, blen));
			else if (start) ret = !strncmp (a, b, blen);
			else if (end) ret = !strncmp (a+(alen-blen), b, blen);
			else ret = strstr2 (a, b, blen);
		}
	}
	free (aa);
	return ret;
}

