#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {size_t num; int pad_type; int* h; int* hh; unsigned char* data; } ;
typedef  TYPE_1__ MDC2_CTX ;
typedef  int /*<<< orphan*/  DES_key_schedule ;
typedef  int DES_LONG ;

/* Variables and functions */
 int /*<<< orphan*/  DES_encrypt1 (int*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  DES_set_key_unchecked (int**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DES_set_odd_parity (int**) ; 
 size_t MDC2_BLOCK ; 
 int /*<<< orphan*/  c2l (unsigned char const*,int) ; 
 int /*<<< orphan*/  l2c (int,unsigned char*) ; 
static  void mdc2_body (TYPE_1__*,unsigned char const*,size_t) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,...) ; 
 int /*<<< orphan*/  memset (int*,int,size_t) ; 

int MDC2_Init(MDC2_CTX *c)
{
    c->num = 0;
    c->pad_type = 1;
    memset(&(c->h[0]), 0x52, MDC2_BLOCK);
    memset(&(c->hh[0]), 0x25, MDC2_BLOCK);
    return 1;
}

int MDC2_Update(MDC2_CTX *c, const unsigned char *in, size_t len)
{
    size_t i, j;

    i = c->num;
    if (i != 0) {
        if (len < MDC2_BLOCK - i) {
            /* partial block */
            memcpy(&(c->data[i]), in, len);
            c->num += (int)len;
            return 1;
        } else {
            /* filled one */
            j = MDC2_BLOCK - i;
            memcpy(&(c->data[i]), in, j);
            len -= j;
            in += j;
            c->num = 0;
            mdc2_body(c, &(c->data[0]), MDC2_BLOCK);
        }
    }
    i = len & ~((size_t)MDC2_BLOCK - 1);
    if (i > 0)
        mdc2_body(c, in, i);
    j = len - i;
    if (j > 0) {
        memcpy(&(c->data[0]), &(in[i]), j);
        c->num = (int)j;
    }
    return 1;
}

__attribute__((used)) static void mdc2_body(MDC2_CTX *c, const unsigned char *in, size_t len)
{
    register DES_LONG tin0, tin1;
    register DES_LONG ttin0, ttin1;
    DES_LONG d[2], dd[2];
    DES_key_schedule k;
    unsigned char *p;
    size_t i;

    for (i = 0; i < len; i += 8) {
        c2l(in, tin0);
        d[0] = dd[0] = tin0;
        c2l(in, tin1);
        d[1] = dd[1] = tin1;
        c->h[0] = (c->h[0] & 0x9f) | 0x40;
        c->hh[0] = (c->hh[0] & 0x9f) | 0x20;

        DES_set_odd_parity(&c->h);
        DES_set_key_unchecked(&c->h, &k);
        DES_encrypt1(d, &k, 1);

        DES_set_odd_parity(&c->hh);
        DES_set_key_unchecked(&c->hh, &k);
        DES_encrypt1(dd, &k, 1);

        ttin0 = tin0 ^ dd[0];
        ttin1 = tin1 ^ dd[1];
        tin0 ^= d[0];
        tin1 ^= d[1];

        p = c->h;
        l2c(tin0, p);
        l2c(ttin1, p);
        p = c->hh;
        l2c(ttin0, p);
        l2c(tin1, p);
    }
}

int MDC2_Final(unsigned char *md, MDC2_CTX *c)
{
    unsigned int i;
    int j;

    i = c->num;
    j = c->pad_type;
    if ((i > 0) || (j == 2)) {
        if (j == 2)
            c->data[i++] = 0x80;
        memset(&(c->data[i]), 0, MDC2_BLOCK - i);
        mdc2_body(c, c->data, MDC2_BLOCK);
    }
    memcpy(md, (char *)c->h, MDC2_BLOCK);
    memcpy(&(md[MDC2_BLOCK]), (char *)c->hh, MDC2_BLOCK);
    return 1;
}

