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
typedef  int wchar_t ;
typedef  int unicode_t ;
typedef  int u8 ;
typedef  int u16 ;
struct utf8_table {int cmask; int cval; unsigned long lmask; unsigned long lval; int shift; } ;
struct nls_table {struct module* owner; scalar_t__ alias; scalar_t__ charset; struct nls_table* next; } ;
struct module {int dummy; } ;
typedef  enum utf16_endian { ____Placeholder_utf16_endian } utf16_endian ;

/* Variables and functions */
 char* CONFIG_NLS_DEFAULT ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENAMETOOLONG ; 
 int PLANE_SIZE ; 
 int SURROGATE_BITS ; 
 unsigned long SURROGATE_LOW ; 
 unsigned long SURROGATE_MASK ; 
 unsigned long SURROGATE_PAIR ; 
 unsigned long UNICODE_MAX ; 
#define  UTF16_BIG_ENDIAN 129 
#define  UTF16_LITTLE_ENDIAN 128 
 unsigned long __be16_to_cpu (unsigned int) ; 
 int __cpu_to_be16 (unsigned int) ; 
 int __cpu_to_le16 (unsigned int) ; 
 unsigned long __le16_to_cpu (unsigned int) ; 
 int* charset2uni ; 
 struct nls_table default_table ; 
 int /*<<< orphan*/  module_put (struct module*) ; 
 int /*<<< orphan*/  nls_lock ; 
 unsigned char** page_uni2charset ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcmp (scalar_t__,char*) ; 
 struct nls_table* tables ; 
 int /*<<< orphan*/  try_module_get (struct module*) ; 
 struct nls_table* try_then_request_module (struct nls_table*,char*,char*) ; 
 struct utf8_table* utf8_table ; 

int utf8_to_utf32(const u8 *s, int inlen, unicode_t *pu)
{
	unsigned long l;
	int c0, c, nc;
	const struct utf8_table *t;
  
	nc = 0;
	c0 = *s;
	l = c0;
	for (t = utf8_table; t->cmask; t++) {
		nc++;
		if ((c0 & t->cmask) == t->cval) {
			l &= t->lmask;
			if (l < t->lval || l > UNICODE_MAX ||
					(l & SURROGATE_MASK) == SURROGATE_PAIR)
				return -1;
			*pu = (unicode_t) l;
			return nc;
		}
		if (inlen <= nc)
			return -1;
		s++;
		c = (*s ^ 0x80) & 0xFF;
		if (c & 0xC0)
			return -1;
		l = (l << 6) | c;
	}
	return -1;
}

int utf32_to_utf8(unicode_t u, u8 *s, int maxout)
{
	unsigned long l;
	int c, nc;
	const struct utf8_table *t;

	if (!s)
		return 0;

	l = u;
	if (l > UNICODE_MAX || (l & SURROGATE_MASK) == SURROGATE_PAIR)
		return -1;

	nc = 0;
	for (t = utf8_table; t->cmask && maxout; t++, maxout--) {
		nc++;
		if (l <= t->lmask) {
			c = t->shift;
			*s = (u8) (t->cval | (l >> c));
			while (c > 0) {
				c -= 6;
				s++;
				*s = (u8) (0x80 | ((l >> c) & 0x3F));
			}
			return nc;
		}
	}
	return -1;
}

__attribute__((used)) static inline void put_utf16(wchar_t *s, unsigned c, enum utf16_endian endian)
{
	switch (endian) {
	default:
		*s = (wchar_t) c;
		break;
	case UTF16_LITTLE_ENDIAN:
		*s = __cpu_to_le16(c);
		break;
	case UTF16_BIG_ENDIAN:
		*s = __cpu_to_be16(c);
		break;
	}
}

int utf8s_to_utf16s(const u8 *s, int inlen, enum utf16_endian endian,
		wchar_t *pwcs, int maxout)
{
	u16 *op;
	int size;
	unicode_t u;

	op = pwcs;
	while (inlen > 0 && maxout > 0 && *s) {
		if (*s & 0x80) {
			size = utf8_to_utf32(s, inlen, &u);
			if (size < 0)
				return -EINVAL;
			s += size;
			inlen -= size;

			if (u >= PLANE_SIZE) {
				if (maxout < 2)
					break;
				u -= PLANE_SIZE;
				put_utf16(op++, SURROGATE_PAIR |
						((u >> 10) & SURROGATE_BITS),
						endian);
				put_utf16(op++, SURROGATE_PAIR |
						SURROGATE_LOW |
						(u & SURROGATE_BITS),
						endian);
				maxout -= 2;
			} else {
				put_utf16(op++, u, endian);
				maxout--;
			}
		} else {
			put_utf16(op++, *s++, endian);
			inlen--;
			maxout--;
		}
	}
	return op - pwcs;
}

__attribute__((used)) static inline unsigned long get_utf16(unsigned c, enum utf16_endian endian)
{
	switch (endian) {
	default:
		return c;
	case UTF16_LITTLE_ENDIAN:
		return __le16_to_cpu(c);
	case UTF16_BIG_ENDIAN:
		return __be16_to_cpu(c);
	}
}

int utf16s_to_utf8s(const wchar_t *pwcs, int inlen, enum utf16_endian endian,
		u8 *s, int maxout)
{
	u8 *op;
	int size;
	unsigned long u, v;

	op = s;
	while (inlen > 0 && maxout > 0) {
		u = get_utf16(*pwcs, endian);
		if (!u)
			break;
		pwcs++;
		inlen--;
		if (u > 0x7f) {
			if ((u & SURROGATE_MASK) == SURROGATE_PAIR) {
				if (u & SURROGATE_LOW) {
					/* Ignore character and move on */
					continue;
				}
				if (inlen <= 0)
					break;
				v = get_utf16(*pwcs, endian);
				if ((v & SURROGATE_MASK) != SURROGATE_PAIR ||
						!(v & SURROGATE_LOW)) {
					/* Ignore character and move on */
					continue;
				}
				u = PLANE_SIZE + ((u & SURROGATE_BITS) << 10)
						+ (v & SURROGATE_BITS);
				pwcs++;
				inlen--;
			}
			size = utf32_to_utf8(u, op, maxout);
			if (size == -1) {
				/* Ignore character and move on */
			} else {
				op += size;
				maxout -= size;
			}
		} else {
			*op++ = (u8) u;
			maxout--;
		}
	}
	return op - s;
}

int __register_nls(struct nls_table *nls, struct module *owner)
{
	struct nls_table ** tmp = &tables;

	if (nls->next)
		return -EBUSY;

	nls->owner = owner;
	spin_lock(&nls_lock);
	while (*tmp) {
		if (nls == *tmp) {
			spin_unlock(&nls_lock);
			return -EBUSY;
		}
		tmp = &(*tmp)->next;
	}
	nls->next = tables;
	tables = nls;
	spin_unlock(&nls_lock);
	return 0;	
}

int unregister_nls(struct nls_table * nls)
{
	struct nls_table ** tmp = &tables;

	spin_lock(&nls_lock);
	while (*tmp) {
		if (nls == *tmp) {
			*tmp = nls->next;
			spin_unlock(&nls_lock);
			return 0;
		}
		tmp = &(*tmp)->next;
	}
	spin_unlock(&nls_lock);
	return -EINVAL;
}

__attribute__((used)) static struct nls_table *find_nls(char *charset)
{
	struct nls_table *nls;
	spin_lock(&nls_lock);
	for (nls = tables; nls; nls = nls->next) {
		if (!strcmp(nls->charset, charset))
			break;
		if (nls->alias && !strcmp(nls->alias, charset))
			break;
	}
	if (nls && !try_module_get(nls->owner))
		nls = NULL;
	spin_unlock(&nls_lock);
	return nls;
}

struct nls_table *load_nls(char *charset)
{
	return try_then_request_module(find_nls(charset), "nls_%s", charset);
}

void unload_nls(struct nls_table *nls)
{
	if (nls)
		module_put(nls->owner);
}

__attribute__((used)) static int uni2char(wchar_t uni, unsigned char *out, int boundlen)
{
	const unsigned char *uni2charset;
	unsigned char cl = uni & 0x00ff;
	unsigned char ch = (uni & 0xff00) >> 8;

	if (boundlen <= 0)
		return -ENAMETOOLONG;

	uni2charset = page_uni2charset[ch];
	if (uni2charset && uni2charset[cl])
		out[0] = uni2charset[cl];
	else
		return -EINVAL;
	return 1;
}

__attribute__((used)) static int char2uni(const unsigned char *rawstring, int boundlen, wchar_t *uni)
{
	*uni = charset2uni[*rawstring];
	if (*uni == 0x0000)
		return -EINVAL;
	return 1;
}

struct nls_table *load_nls_default(void)
{
	struct nls_table *default_nls;
	
	default_nls = load_nls(CONFIG_NLS_DEFAULT);
	if (default_nls != NULL)
		return default_nls;
	else
		return &default_table;
}

