#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int type; int length; unsigned char* data; } ;
typedef  int /*<<< orphan*/  BIO ;
typedef  TYPE_1__ ASN1_INTEGER ;
typedef  TYPE_1__ ASN1_ENUMERATED ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_F_A2I_ASN1_INTEGER ; 
 int /*<<< orphan*/  ASN1_R_NON_HEX_CHARACTERS ; 
 int /*<<< orphan*/  ASN1_R_ODD_NUMBER_OF_CHARS ; 
 int /*<<< orphan*/  ASN1_R_SHORT_LINE ; 
 int /*<<< orphan*/  ASN1err (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int BIO_gets (int /*<<< orphan*/ *,char*,int) ; 
 int BIO_write (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 unsigned char* OPENSSL_clear_realloc (unsigned char*,int,int) ; 
 int /*<<< orphan*/  OPENSSL_free (unsigned char*) ; 
 int OPENSSL_hexchar2int (unsigned char) ; 
 int V_ASN1_INTEGER ; 
 int V_ASN1_NEG ; 
 int /*<<< orphan*/  ossl_isxdigit (char) ; 

int i2a_ASN1_INTEGER(BIO *bp, const ASN1_INTEGER *a)
{
    int i, n = 0;
    static const char *h = "0123456789ABCDEF";
    char buf[2];

    if (a == NULL)
        return 0;

    if (a->type & V_ASN1_NEG) {
        if (BIO_write(bp, "-", 1) != 1)
            goto err;
        n = 1;
    }

    if (a->length == 0) {
        if (BIO_write(bp, "00", 2) != 2)
            goto err;
        n += 2;
    } else {
        for (i = 0; i < a->length; i++) {
            if ((i != 0) && (i % 35 == 0)) {
                if (BIO_write(bp, "\\\n", 2) != 2)
                    goto err;
                n += 2;
            }
            buf[0] = h[((unsigned char)a->data[i] >> 4) & 0x0f];
            buf[1] = h[((unsigned char)a->data[i]) & 0x0f];
            if (BIO_write(bp, buf, 2) != 2)
                goto err;
            n += 2;
        }
    }
    return n;
 err:
    return -1;
}

int a2i_ASN1_INTEGER(BIO *bp, ASN1_INTEGER *bs, char *buf, int size)
{
    int i, j, k, m, n, again, bufsize;
    unsigned char *s = NULL, *sp;
    unsigned char *bufp;
    int num = 0, slen = 0, first = 1;

    bs->type = V_ASN1_INTEGER;

    bufsize = BIO_gets(bp, buf, size);
    for (;;) {
        if (bufsize < 1)
            goto err;
        i = bufsize;
        if (buf[i - 1] == '\n')
            buf[--i] = '\0';
        if (i == 0)
            goto err;
        if (buf[i - 1] == '\r')
            buf[--i] = '\0';
        if (i == 0)
            goto err;
        again = (buf[i - 1] == '\\');

        for (j = 0; j < i; j++) {
            if (!ossl_isxdigit(buf[j]))
            {
                i = j;
                break;
            }
        }
        buf[i] = '\0';
        /*
         * We have now cleared all the crap off the end of the line
         */
        if (i < 2)
            goto err;

        bufp = (unsigned char *)buf;
        if (first) {
            first = 0;
            if ((bufp[0] == '0') && (bufp[1] == '0')) {
                bufp += 2;
                i -= 2;
            }
        }
        k = 0;
        i -= again;
        if (i % 2 != 0) {
            ASN1err(ASN1_F_A2I_ASN1_INTEGER, ASN1_R_ODD_NUMBER_OF_CHARS);
            OPENSSL_free(s);
            return 0;
        }
        i /= 2;
        if (num + i > slen) {
            sp = OPENSSL_clear_realloc(s, slen, num + i * 2);
            if (sp == NULL) {
                ASN1err(ASN1_F_A2I_ASN1_INTEGER, ERR_R_MALLOC_FAILURE);
                OPENSSL_free(s);
                return 0;
            }
            s = sp;
            slen = num + i * 2;
        }
        for (j = 0; j < i; j++, k += 2) {
            for (n = 0; n < 2; n++) {
                m = OPENSSL_hexchar2int(bufp[k + n]);
                if (m < 0) {
                    ASN1err(ASN1_F_A2I_ASN1_INTEGER,
                            ASN1_R_NON_HEX_CHARACTERS);
                    goto err;
                }
                s[num + j] <<= 4;
                s[num + j] |= m;
            }
        }
        num += i;
        if (again)
            bufsize = BIO_gets(bp, buf, size);
        else
            break;
    }
    bs->length = num;
    bs->data = s;
    return 1;
 err:
    ASN1err(ASN1_F_A2I_ASN1_INTEGER, ASN1_R_SHORT_LINE);
    OPENSSL_free(s);
    return 0;
}

int i2a_ASN1_ENUMERATED(BIO *bp, const ASN1_ENUMERATED *a)
{
    return i2a_ASN1_INTEGER(bp, a);
}

int a2i_ASN1_ENUMERATED(BIO *bp, ASN1_ENUMERATED *bs, char *buf, int size)
{
    int rv = a2i_ASN1_INTEGER(bp, bs, buf, size);
    if (rv == 1)
        bs->type = V_ASN1_INTEGER | (bs->type & V_ASN1_NEG);
    return rv;
}

