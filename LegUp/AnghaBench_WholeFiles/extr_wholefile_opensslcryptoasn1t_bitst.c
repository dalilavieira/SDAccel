#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {char* lname; int bitnum; char* sname; } ;
typedef  TYPE_1__ BIT_STRING_BITNAME ;
typedef  int /*<<< orphan*/  BIO ;
typedef  int /*<<< orphan*/  ASN1_BIT_STRING ;

/* Variables and functions */
 scalar_t__ ASN1_BIT_STRING_get_bit (int /*<<< orphan*/ *,int) ; 
 int ASN1_BIT_STRING_num_asc (char const*,TYPE_1__*) ; 
 int /*<<< orphan*/  ASN1_BIT_STRING_set_bit (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  BIO_printf (int /*<<< orphan*/ *,char*,int,char*) ; 
 int /*<<< orphan*/  BIO_puts (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ strcmp (char*,char const*) ; 

int ASN1_BIT_STRING_name_print(BIO *out, ASN1_BIT_STRING *bs,
                               BIT_STRING_BITNAME *tbl, int indent)
{
    BIT_STRING_BITNAME *bnam;
    char first = 1;
    BIO_printf(out, "%*s", indent, "");
    for (bnam = tbl; bnam->lname; bnam++) {
        if (ASN1_BIT_STRING_get_bit(bs, bnam->bitnum)) {
            if (!first)
                BIO_puts(out, ", ");
            BIO_puts(out, bnam->lname);
            first = 0;
        }
    }
    BIO_puts(out, "\n");
    return 1;
}

int ASN1_BIT_STRING_set_asc(ASN1_BIT_STRING *bs, const char *name, int value,
                            BIT_STRING_BITNAME *tbl)
{
    int bitnum;
    bitnum = ASN1_BIT_STRING_num_asc(name, tbl);
    if (bitnum < 0)
        return 0;
    if (bs) {
        if (!ASN1_BIT_STRING_set_bit(bs, bitnum, value))
            return 0;
    }
    return 1;
}

int ASN1_BIT_STRING_num_asc(const char *name, BIT_STRING_BITNAME *tbl)
{
    BIT_STRING_BITNAME *bnam;
    for (bnam = tbl; bnam->lname; bnam++) {
        if ((strcmp(bnam->sname, name) == 0)
            || (strcmp(bnam->lname, name) == 0))
            return bnam->bitnum;
    }
    return -1;
}

