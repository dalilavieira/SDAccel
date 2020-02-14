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
typedef  int /*<<< orphan*/  ASN1_OCTET_STRING ;

/* Variables and functions */
 int ASN1_STRING_cmp (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * ASN1_STRING_dup (int /*<<< orphan*/  const*) ; 
 int ASN1_STRING_set (int /*<<< orphan*/ *,unsigned char const*,int) ; 

ASN1_OCTET_STRING *ASN1_OCTET_STRING_dup(const ASN1_OCTET_STRING *x)
{
    return ASN1_STRING_dup(x);
}

int ASN1_OCTET_STRING_cmp(const ASN1_OCTET_STRING *a,
                          const ASN1_OCTET_STRING *b)
{
    return ASN1_STRING_cmp(a, b);
}

int ASN1_OCTET_STRING_set(ASN1_OCTET_STRING *x, const unsigned char *d,
                          int len)
{
    return ASN1_STRING_set(x, d, len);
}

