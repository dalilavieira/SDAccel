#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  time_t ;
struct tm {int dummy; } ;
struct TYPE_17__ {scalar_t__ type; unsigned char* data; scalar_t__ flags; int /*<<< orphan*/  length; } ;
typedef  int /*<<< orphan*/  BIO ;
typedef  TYPE_1__ ASN1_UTCTIME ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_STRING_copy (TYPE_1__*,TYPE_1__*) ; 
 int ASN1_TIME_print (int /*<<< orphan*/ *,TYPE_1__ const*) ; 
 TYPE_1__* ASN1_UTCTIME_adj (TYPE_1__*,int /*<<< orphan*/ ,int,long) ; 
 struct tm* OPENSSL_gmtime (int /*<<< orphan*/ *,struct tm*) ; 
 int /*<<< orphan*/  OPENSSL_gmtime_adj (struct tm*,int,long) ; 
 int /*<<< orphan*/  OPENSSL_gmtime_diff (int*,int*,struct tm*,struct tm*) ; 
 scalar_t__ V_ASN1_UTCTIME ; 
 TYPE_1__* asn1_time_from_tm (TYPE_1__*,struct tm*,scalar_t__) ; 
 int asn1_time_to_tm (struct tm*,TYPE_1__ const*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

int asn1_utctime_to_tm(struct tm *tm, const ASN1_UTCTIME *d)
{
    /* wrapper around asn1_time_to_tm */
    if (d->type != V_ASN1_UTCTIME)
        return 0;
    return asn1_time_to_tm(tm, d);
}

int ASN1_UTCTIME_check(const ASN1_UTCTIME *d)
{
    return asn1_utctime_to_tm(NULL, d);
}

int ASN1_UTCTIME_set_string(ASN1_UTCTIME *s, const char *str)
{
    ASN1_UTCTIME t;

    t.type = V_ASN1_UTCTIME;
    t.length = strlen(str);
    t.data = (unsigned char *)str;
    t.flags = 0;

    if (!ASN1_UTCTIME_check(&t))
        return 0;

    if (s != NULL && !ASN1_STRING_copy(s, &t))
        return 0;

    return 1;
}

ASN1_UTCTIME *ASN1_UTCTIME_set(ASN1_UTCTIME *s, time_t t)
{
    return ASN1_UTCTIME_adj(s, t, 0, 0);
}

ASN1_UTCTIME *ASN1_UTCTIME_adj(ASN1_UTCTIME *s, time_t t,
                               int offset_day, long offset_sec)
{
    struct tm *ts;
    struct tm data;

    ts = OPENSSL_gmtime(&t, &data);
    if (ts == NULL)
        return NULL;

    if (offset_day || offset_sec) {
        if (!OPENSSL_gmtime_adj(ts, offset_day, offset_sec))
            return NULL;
    }

    return asn1_time_from_tm(s, ts, V_ASN1_UTCTIME);
}

int ASN1_UTCTIME_cmp_time_t(const ASN1_UTCTIME *s, time_t t)
{
    struct tm stm, ttm;
    int day, sec;

    if (!asn1_utctime_to_tm(&stm, s))
        return -2;

    if (OPENSSL_gmtime(&t, &ttm) == NULL)
        return -2;

    if (!OPENSSL_gmtime_diff(&day, &sec, &ttm, &stm))
        return -2;

    if (day > 0 || sec > 0)
        return 1;
    if (day < 0 || sec < 0)
        return -1;
    return 0;
}

int ASN1_UTCTIME_print(BIO *bp, const ASN1_UTCTIME *tm)
{
    if (tm->type != V_ASN1_UTCTIME)
        return 0;
    return ASN1_TIME_print(bp, tm);
}

