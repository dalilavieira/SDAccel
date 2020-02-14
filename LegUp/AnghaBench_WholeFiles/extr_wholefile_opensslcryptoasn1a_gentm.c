#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  time_t ;
struct tm {int dummy; } ;
struct TYPE_16__ {scalar_t__ type; unsigned char* data; scalar_t__ flags; int /*<<< orphan*/  length; } ;
typedef  int /*<<< orphan*/  BIO ;
typedef  TYPE_1__ ASN1_GENERALIZEDTIME ;

/* Variables and functions */
 TYPE_1__* ASN1_GENERALIZEDTIME_adj (TYPE_1__*,int /*<<< orphan*/ ,int,long) ; 
 int /*<<< orphan*/  ASN1_STRING_copy (TYPE_1__*,TYPE_1__*) ; 
 int ASN1_TIME_print (int /*<<< orphan*/ *,TYPE_1__ const*) ; 
 struct tm* OPENSSL_gmtime (int /*<<< orphan*/ *,struct tm*) ; 
 int /*<<< orphan*/  OPENSSL_gmtime_adj (struct tm*,int,long) ; 
 scalar_t__ V_ASN1_GENERALIZEDTIME ; 
 TYPE_1__* asn1_time_from_tm (TYPE_1__*,struct tm*,scalar_t__) ; 
 int asn1_time_to_tm (struct tm*,TYPE_1__ const*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

int asn1_generalizedtime_to_tm(struct tm *tm, const ASN1_GENERALIZEDTIME *d)
{
    /* wrapper around asn1_time_to_tm */
    if (d->type != V_ASN1_GENERALIZEDTIME)
        return 0;
    return asn1_time_to_tm(tm, d);
}

int ASN1_GENERALIZEDTIME_check(const ASN1_GENERALIZEDTIME *d)
{
    return asn1_generalizedtime_to_tm(NULL, d);
}

int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s, const char *str)
{
    ASN1_GENERALIZEDTIME t;

    t.type = V_ASN1_GENERALIZEDTIME;
    t.length = strlen(str);
    t.data = (unsigned char *)str;
    t.flags = 0;

    if (!ASN1_GENERALIZEDTIME_check(&t))
        return 0;

    if (s != NULL && !ASN1_STRING_copy(s, &t))
        return 0;

    return 1;
}

ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_set(ASN1_GENERALIZEDTIME *s,
                                               time_t t)
{
    return ASN1_GENERALIZEDTIME_adj(s, t, 0, 0);
}

ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_adj(ASN1_GENERALIZEDTIME *s,
                                               time_t t, int offset_day,
                                               long offset_sec)
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

    return asn1_time_from_tm(s, ts, V_ASN1_GENERALIZEDTIME);
}

int ASN1_GENERALIZEDTIME_print(BIO *bp, const ASN1_GENERALIZEDTIME *tm)
{
    if (tm->type != V_ASN1_GENERALIZEDTIME)
        return 0;
    return ASN1_TIME_print(bp, tm);
}

