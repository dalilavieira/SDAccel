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
typedef  int /*<<< orphan*/  time_t ;
struct tm {size_t tm_mon; int tm_year; int /*<<< orphan*/  tm_sec; int /*<<< orphan*/  tm_min; int /*<<< orphan*/  tm_hour; int /*<<< orphan*/  tm_mday; } ;
struct TYPE_12__ {int length; scalar_t__ type; scalar_t__ data; } ;
typedef  int /*<<< orphan*/  BIO ;
typedef  TYPE_1__ const ASN1_TIME ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_TIME_diff (int*,int*,TYPE_1__ const*,TYPE_1__ const*) ; 
 int /*<<< orphan*/  ASN1_TIME_to_tm (TYPE_1__ const*,struct tm*) ; 
 scalar_t__ BIO_printf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,...) ; 
 int /*<<< orphan*/  BIO_write (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  OPENSSL_gmtime (int /*<<< orphan*/ *,struct tm*) ; 
 int /*<<< orphan*/  OPENSSL_gmtime_diff (int*,int*,struct tm*,struct tm*) ; 
 scalar_t__ V_ASN1_GENERALIZEDTIME ; 
 int /*<<< orphan*/  V_ASN1_UNDEF ; 
 int /*<<< orphan*/ * _asn1_mon ; 
 int /*<<< orphan*/ * asn1_time_from_tm (TYPE_1__ const*,struct tm*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  asn1_time_to_tm (struct tm*,TYPE_1__ const*) ; 
 scalar_t__ ossl_isdigit (char) ; 

int ASN1_TIME_print(BIO *bp, const ASN1_TIME *tm)
{
    char *v;
    int gmt = 0, l;
    struct tm stm;

    if (!asn1_time_to_tm(&stm, tm)) {
        /* asn1_time_to_tm will check the time type */
        goto err;
    }

    l = tm->length;
    v = (char *)tm->data;
    if (v[l - 1] == 'Z')
        gmt = 1;

    if (tm->type == V_ASN1_GENERALIZEDTIME) {
        char *f = NULL;
        int f_len = 0;

        /*
         * Try to parse fractional seconds. '14' is the place of
         * 'fraction point' in a GeneralizedTime string.
         */
        if (tm->length > 15 && v[14] == '.') {
            f = &v[14];
            f_len = 1;
            while (14 + f_len < l && ossl_isdigit(f[f_len]))
                ++f_len;
        }

        return BIO_printf(bp, "%s %2d %02d:%02d:%02d%.*s %d%s",
                          _asn1_mon[stm.tm_mon], stm.tm_mday, stm.tm_hour,
                          stm.tm_min, stm.tm_sec, f_len, f, stm.tm_year + 1900,
                          (gmt ? " GMT" : "")) > 0;
    } else {
        return BIO_printf(bp, "%s %2d %02d:%02d:%02d %d%s",
                          _asn1_mon[stm.tm_mon], stm.tm_mday, stm.tm_hour,
                          stm.tm_min, stm.tm_sec, stm.tm_year + 1900,
                          (gmt ? " GMT" : "")) > 0;
    }
 err:
    BIO_write(bp, "Bad time value", 14);
    return 0;
}

int ASN1_TIME_cmp_time_t(const ASN1_TIME *s, time_t t)
{
    struct tm stm, ttm;
    int day, sec;

    if (!ASN1_TIME_to_tm(s, &stm))
        return -2;

    if (!OPENSSL_gmtime(&t, &ttm))
        return -2;

    if (!OPENSSL_gmtime_diff(&day, &sec, &ttm, &stm))
        return -2;

    if (day > 0 || sec > 0)
        return 1;
    if (day < 0 || sec < 0)
        return -1;
    return 0;
}

int ASN1_TIME_normalize(ASN1_TIME *t)
{
    struct tm tm;

    if (!ASN1_TIME_to_tm(t, &tm))
        return 0;

    return asn1_time_from_tm(t, &tm, V_ASN1_UNDEF) != NULL;
}

int ASN1_TIME_compare(const ASN1_TIME *a, const ASN1_TIME *b)
{
    int day, sec;

    if (!ASN1_TIME_diff(&day, &sec, b, a))
        return -2;
    if (day > 0 || sec > 0)
        return 1;
    if (day < 0 || sec < 0)
        return -1;
    return 0;
}

