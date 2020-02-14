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
struct utf8_table {int cmask; int cval; long lmask; long lval; int shift; } ;
struct nls_table {int /*<<< orphan*/  owner; scalar_t__ alias; scalar_t__ charset; struct nls_table* next; } ;
typedef  int __u8 ;
typedef  int __u16 ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENAMETOOLONG ; 
 int* charset2uni ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nls_lock ; 
 unsigned char** page_uni2charset ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcmp (scalar_t__,char*) ; 
 struct nls_table* tables ; 
 int /*<<< orphan*/  try_module_get (int /*<<< orphan*/ ) ; 
 struct utf8_table* utf8_table ; 

int
utf8_mbtowc(wchar_t *p, const __u8 *s, int n)
{
    long l;
    int c0, c, nc;
    struct utf8_table *t;

    nc = 0;
    c0 = *s;
    l = c0;
    for (t = utf8_table; t->cmask; t++) {
        nc++;
        if ((c0 & t->cmask) == t->cval) {
            l &= t->lmask;
            if (l < t->lval)
                return -1;
            *p = (wchar_t)l;
            return nc;
        }
        if (n <= nc)
            return -1;
        s++;
        c = (*s ^ 0x80) & 0xFF;
        if (c & 0xC0)
            return -1;
        l = (l << 6) | c;
    }
    return -1;
}

int
utf8_mbstowcs(wchar_t *pwcs, const __u8 *s, int n)
{
    __u16 *op;
    const __u8 *ip;
    int size;

    op = pwcs;
    ip = s;
    while (*ip && n > 0) {
        if (*ip & 0x80) {
            size = utf8_mbtowc(op, ip, n);
            if (size == -1) {
                /* Ignore character and move on */
                ip++;
                n--;
            } else {
                op++;
                ip += size;
                n -= size;
            }
        } else {
            *op++ = *ip++;
            n--;
        }
    }
    return (int)(op - pwcs);
}

int
utf8_wctomb(__u8 *s, wchar_t wc, int maxlen)
{
    long l;
    int c, nc;
    struct utf8_table *t;

    if (s == 0)
        return 0;

    l = wc;
    nc = 0;
    for (t = utf8_table; t->cmask && maxlen; t++, maxlen--) {
        nc++;
        if (l <= t->lmask) {
            c = t->shift;
            *s = (__u8)(t->cval | (l >> c));
            while (c > 0) {
                c -= 6;
                s++;
                *s = 0x80 | (__u8)((l >> c) & 0x3F);
            }
            return nc;
        }
    }
    return -1;
}

int
utf8_wcstombs(__u8 *s, const wchar_t *pwcs, int maxlen)
{
    const __u16 *ip;
    __u8 *op;
    int size;

    op = s;
    ip = pwcs;
    while (*ip && maxlen > 0) {
        if (*ip > 0x7f) {
            size = utf8_wctomb(op, *ip, maxlen);
            if (size == -1) {
                /* Ignore character and move on */
                maxlen--;
            } else {
                op += size;
                maxlen -= size;
            }
        } else {
            *op++ = (__u8) *ip;
        }
        ip++;
    }
    return (int)(op - s);
}

int register_nls(struct nls_table * nls)
{
    struct nls_table ** tmp = &tables;

    if (!nls)
        return -EINVAL;
    if (nls->next)
        return -EBUSY;

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
    struct nls_table *nls;
#ifdef CONFIG_KMOD
    int ret;
#endif

    nls = find_nls(charset);
    if (nls)
        return nls;

#ifdef CONFIG_KMOD
    ret = request_module("nls_%s", charset);
    if (ret != 0) {
        printk("Unable to load NLS charset %s\n", charset);
        return NULL;
    }
    nls = find_nls(charset);
#endif
    return nls;
}

void unload_nls(struct nls_table *nls)
{
    module_put(nls->owner);
}

__attribute__((used)) static int uni2char(wchar_t uni, unsigned char *out, int boundlen)
{
    unsigned char *uni2charset;
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

