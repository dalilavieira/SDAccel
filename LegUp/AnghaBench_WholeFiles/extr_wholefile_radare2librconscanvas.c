#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tmp ;
struct TYPE_7__ {int attrslen; char* attr; TYPE_1__* attrs; int /*<<< orphan*/  color; } ;
struct TYPE_6__ {int loc; char const* a; } ;
typedef  TYPE_2__ RConsCanvas ;

/* Variables and functions */
 int R_MIN (int,int) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int const) ; 
 char* r_str_const (char*) ; 

__attribute__((used)) static bool _is_ansi_seq(const char *s) {
	return s && s[0] == 033 && s[1] == '[';
}

__attribute__((used)) static int _get_piece(const char *p, char *chr) {
	const char *q = p;
	if (!p) {
		return 0;
	}
	while (p && *p && *p != '\n' && ! _is_ansi_seq (p)) {
		p++;
	}
	if (chr) {
		*chr = *p;
	}
	return p - q;
}

__attribute__((used)) static const char **attr_at(RConsCanvas *c, int loc) {
	int i, j, delta;
	if (!c->color || c->attrslen == 0) {
		return NULL;
	}
	j = c->attrslen / 2;
	delta = c->attrslen / 2;
	for (i = 0; i < (c->attrslen); i++) {
		delta /= 2;
		if (delta == 0) {
			delta = 1;
		}
		if (c->attrs[j].loc == loc) {
			return &c->attrs[j].a;
		}
		if (c->attrs[j].loc < loc) {
			j += delta;
			if (j >= c->attrslen) {
				break;
			}
			if (c->attrs[j].loc > loc && delta == 1) {
				break;
			}
		} else if (c->attrs[j].loc > loc) {
			j -= delta;
			if (j <= 0) {
				break;
			}
			if (c->attrs[j].loc < loc && delta == 1) {
				break;
			}
		}
	}
	return NULL;
}

__attribute__((used)) static void stamp_attr(RConsCanvas *c, int loc, int length) {
	if (!c->color) {
		return;
	}
	int i;
	const char **s;
	s = attr_at (c, loc);

	if (s) {
#if 0
		if (*s != 0 && strlen (*s) > 2 && *(*s + 2) == '0') {
			if (strlen (c->attr) == 5 && *(c->attr + 2) != '0') {
				char tmp[9];
				memcpy (tmp, c->attr, 2);
				strcpy (tmp + 2, "0;");
				memcpy (tmp + 4, c->attr + 2, 3);
				tmp[8] = 0;
				c->attr = r_str_const (tmp);
			}
		}
#endif
		*s = c->attr;
	} else {
		for (i = c->attrslen; i > 0 && loc < c->attrs[i - 1].loc; i--) {
			c->attrs[i] = c->attrs[i - 1];
		}
		c->attrs[i].loc = loc;
		c->attrs[i].a = c->attr;
		c->attrslen++;
	}

	for (i = 1; i < length; i++) {
		s = attr_at (c, loc + i);
		if (s) {
			*s = 0;
		}
	}
}

__attribute__((used)) static const char *set_attr(RConsCanvas *c, const char *s) {
	if (!c || !s) {
		return NULL;
	}
	const char *p = s;

	while (_is_ansi_seq (p)) {
		p += 2;
		while (*p && *p != 'J' && *p != 'm' && *p != 'H') {
			p++;
		}
		p++;
	}

	if (p != s) {
		char tmp[256];
		const int slen = R_MIN (p - s, sizeof (tmp) - 1);
		if (slen > 0) {
			memcpy (tmp, s, slen);
			tmp[slen] = 0;
			// could be faster
			c->attr = r_str_const (tmp);
		}
	}
	return p;
}

