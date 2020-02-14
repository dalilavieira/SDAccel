#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int length; int flags; int* data; int /*<<< orphan*/  type; } ;
typedef  TYPE_1__ ASN1_BIT_STRING ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_BIT_STRING_free (TYPE_1__*) ; 
 TYPE_1__* ASN1_BIT_STRING_new () ; 
 int /*<<< orphan*/  ASN1_F_ASN1_BIT_STRING_SET_BIT ; 
 int /*<<< orphan*/  ASN1_F_C2I_ASN1_BIT_STRING ; 
 int ASN1_R_INVALID_BIT_STRING_BITS_LEFT ; 
 int ASN1_R_STRING_TOO_LONG ; 
 int ASN1_R_STRING_TOO_SHORT ; 
 int ASN1_STRING_FLAG_BITS_LEFT ; 
 int ASN1_STRING_set (TYPE_1__*,unsigned char*,int) ; 
 int /*<<< orphan*/  ASN1err (int /*<<< orphan*/ ,int) ; 
 int ERR_R_MALLOC_FAILURE ; 
 long INT_MAX ; 
 unsigned char* OPENSSL_clear_realloc (unsigned char*,int,int) ; 
 int /*<<< orphan*/  OPENSSL_free (unsigned char*) ; 
 unsigned char* OPENSSL_malloc (int) ; 
 int /*<<< orphan*/  V_ASN1_BIT_STRING ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char const*,int) ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 

int ASN1_BIT_STRING_set(ASN1_BIT_STRING *x, unsigned char *d, int len)
{
    return ASN1_STRING_set(x, d, len);
}

int i2c_ASN1_BIT_STRING(ASN1_BIT_STRING *a, unsigned char **pp)
{
    int ret, j, bits, len;
    unsigned char *p, *d;

    if (a == NULL)
        return 0;

    len = a->length;

    if (len > 0) {
        if (a->flags & ASN1_STRING_FLAG_BITS_LEFT) {
            bits = (int)a->flags & 0x07;
        } else {
            for (; len > 0; len--) {
                if (a->data[len - 1])
                    break;
            }
            j = a->data[len - 1];
            if (j & 0x01)
                bits = 0;
            else if (j & 0x02)
                bits = 1;
            else if (j & 0x04)
                bits = 2;
            else if (j & 0x08)
                bits = 3;
            else if (j & 0x10)
                bits = 4;
            else if (j & 0x20)
                bits = 5;
            else if (j & 0x40)
                bits = 6;
            else if (j & 0x80)
                bits = 7;
            else
                bits = 0;       /* should not happen */
        }
    } else
        bits = 0;

    ret = 1 + len;
    if (pp == NULL)
        return ret;

    p = *pp;

    *(p++) = (unsigned char)bits;
    d = a->data;
    if (len > 0) {
        memcpy(p, d, len);
        p += len;
        p[-1] &= (0xff << bits);
    }
    *pp = p;
    return ret;
}

ASN1_BIT_STRING *c2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a,
                                     const unsigned char **pp, long len)
{
    ASN1_BIT_STRING *ret = NULL;
    const unsigned char *p;
    unsigned char *s;
    int i;

    if (len < 1) {
        i = ASN1_R_STRING_TOO_SHORT;
        goto err;
    }

    if (len > INT_MAX) {
        i = ASN1_R_STRING_TOO_LONG;
        goto err;
    }

    if ((a == NULL) || ((*a) == NULL)) {
        if ((ret = ASN1_BIT_STRING_new()) == NULL)
            return NULL;
    } else
        ret = (*a);

    p = *pp;
    i = *(p++);
    if (i > 7) {
        i = ASN1_R_INVALID_BIT_STRING_BITS_LEFT;
        goto err;
    }
    /*
     * We do this to preserve the settings.  If we modify the settings, via
     * the _set_bit function, we will recalculate on output
     */
    ret->flags &= ~(ASN1_STRING_FLAG_BITS_LEFT | 0x07); /* clear */
    ret->flags |= (ASN1_STRING_FLAG_BITS_LEFT | i); /* set */

    if (len-- > 1) {            /* using one because of the bits left byte */
        s = OPENSSL_malloc((int)len);
        if (s == NULL) {
            i = ERR_R_MALLOC_FAILURE;
            goto err;
        }
        memcpy(s, p, (int)len);
        s[len - 1] &= (0xff << i);
        p += len;
    } else
        s = NULL;

    ret->length = (int)len;
    OPENSSL_free(ret->data);
    ret->data = s;
    ret->type = V_ASN1_BIT_STRING;
    if (a != NULL)
        (*a) = ret;
    *pp = p;
    return ret;
 err:
    ASN1err(ASN1_F_C2I_ASN1_BIT_STRING, i);
    if ((a == NULL) || (*a != ret))
        ASN1_BIT_STRING_free(ret);
    return NULL;
}

int ASN1_BIT_STRING_set_bit(ASN1_BIT_STRING *a, int n, int value)
{
    int w, v, iv;
    unsigned char *c;

    w = n / 8;
    v = 1 << (7 - (n & 0x07));
    iv = ~v;
    if (!value)
        v = 0;

    if (a == NULL)
        return 0;

    a->flags &= ~(ASN1_STRING_FLAG_BITS_LEFT | 0x07); /* clear, set on write */

    if ((a->length < (w + 1)) || (a->data == NULL)) {
        if (!value)
            return 1;         /* Don't need to set */
        c = OPENSSL_clear_realloc(a->data, a->length, w + 1);
        if (c == NULL) {
            ASN1err(ASN1_F_ASN1_BIT_STRING_SET_BIT, ERR_R_MALLOC_FAILURE);
            return 0;
        }
        if (w + 1 - a->length > 0)
            memset(c + a->length, 0, w + 1 - a->length);
        a->data = c;
        a->length = w + 1;
    }
    a->data[w] = ((a->data[w]) & iv) | v;
    while ((a->length > 0) && (a->data[a->length - 1] == 0))
        a->length--;
    return 1;
}

int ASN1_BIT_STRING_get_bit(const ASN1_BIT_STRING *a, int n)
{
    int w, v;

    w = n / 8;
    v = 1 << (7 - (n & 0x07));
    if ((a == NULL) || (a->length < (w + 1)) || (a->data == NULL))
        return 0;
    return ((a->data[w] & v) != 0);
}

int ASN1_BIT_STRING_check(const ASN1_BIT_STRING *a,
                          const unsigned char *flags, int flags_len)
{
    int i, ok;
    /* Check if there is one bit set at all. */
    if (!a || !a->data)
        return 1;

    /*
     * Check each byte of the internal representation of the bit string.
     */
    ok = 1;
    for (i = 0; i < a->length && ok; ++i) {
        unsigned char mask = i < flags_len ? ~flags[i] : 0xff;
        /* We are done if there is an unneeded bit set. */
        ok = (a->data[i] & mask) == 0;
    }
    return ok;
}

