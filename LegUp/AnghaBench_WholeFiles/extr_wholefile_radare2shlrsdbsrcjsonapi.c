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
typedef  int ut8 ;
typedef  int ut32 ;
typedef  scalar_t__ off_t ;
struct TYPE_4__ {char* p; int f; int t; } ;
typedef  TYPE_1__ Rangstr ;

/* Variables and functions */
 int /*<<< orphan*/  SEEK_SET ; 
 TYPE_1__ json_get (char const*,char const*) ; 
 int lseek (int,scalar_t__,int /*<<< orphan*/ ) ; 
 char* malloc (int) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int) ; 
 char* rangstr_dup (TYPE_1__*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int strlen (char const*) ; 

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

char *api_json_get (const char *s, const char *p) {
	Rangstr rs = json_get (s, p);
	return rangstr_dup (&rs);
}

char *api_json_set (const char *s, const char *k, const char *v) {
	const char *beg[3];
	const char *end[3];
	int idx, len[3];
	char *str = NULL;
	Rangstr rs = json_get (s, k);
	if (!rs.p) {
		return NULL;
	}
#define WLEN(x) (int)(size_t)(end[x]-beg[x])

	beg[0] = s;
	end[0] = rs.p + rs.f;
	len[0] = WLEN (0);

	beg[1] = v;
	end[1] = v + strlen (v);
	len[1] = WLEN (1);

	beg[2] = rs.p + rs.t;
	end[2] = s + strlen (s);
	len[2] = WLEN (2);

	str = malloc (len[0]+len[1]+len[2]+1);
	if (!str) {
		return NULL;
	}
	idx = len[0];
	memcpy (str, beg[0], idx);
	memcpy (str+idx, beg[1], len[1]);
	idx += len[1];
	memcpy (str+idx, beg[2], len[2]);
	str[idx+len[2]] = 0;
	return str;
}

char *api_json_seti (const char *s, const char *k, int a) {
	char str[64];
	sprintf (str, "%d", a);
	return api_json_set (s, k, str);
}

