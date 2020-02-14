#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int boolean; int /*<<< orphan*/ * sequence; int /*<<< orphan*/ * ptr; int /*<<< orphan*/  object; } ;
struct TYPE_13__ {scalar_t__ type; TYPE_1__ value; } ;
typedef  int /*<<< orphan*/  ASN1_VALUE ;
typedef  TYPE_2__ ASN1_TYPE ;
typedef  int /*<<< orphan*/  ASN1_STRING ;
typedef  int /*<<< orphan*/  ASN1_OCTET_STRING ;
typedef  int /*<<< orphan*/  ASN1_OBJECT ;
typedef  int /*<<< orphan*/  ASN1_ITEM ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_OCTET_STRING_free (int /*<<< orphan*/ *) ; 
 int ASN1_STRING_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ASN1_STRING_dup (void const*) ; 
 TYPE_2__* ASN1_TYPE_new () ; 
 int /*<<< orphan*/ * ASN1_item_pack (void*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 void* ASN1_item_unpack (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int OBJ_cmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * OBJ_dup (void const*) ; 
#define  V_ASN1_BIT_STRING 150 
#define  V_ASN1_BMPSTRING 149 
#define  V_ASN1_BOOLEAN 148 
#define  V_ASN1_ENUMERATED 147 
#define  V_ASN1_GENERALIZEDTIME 146 
#define  V_ASN1_GENERALSTRING 145 
#define  V_ASN1_GRAPHICSTRING 144 
#define  V_ASN1_IA5STRING 143 
#define  V_ASN1_INTEGER 142 
#define  V_ASN1_NULL 141 
#define  V_ASN1_NUMERICSTRING 140 
#define  V_ASN1_OBJECT 139 
#define  V_ASN1_OCTET_STRING 138 
#define  V_ASN1_OTHER 137 
#define  V_ASN1_PRINTABLESTRING 136 
#define  V_ASN1_SEQUENCE 135 
#define  V_ASN1_SET 134 
#define  V_ASN1_T61STRING 133 
#define  V_ASN1_UNIVERSALSTRING 132 
#define  V_ASN1_UTCTIME 131 
#define  V_ASN1_UTF8STRING 130 
#define  V_ASN1_VIDEOTEXSTRING 129 
#define  V_ASN1_VISIBLESTRING 128 
 int /*<<< orphan*/  asn1_primitive_free (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int ASN1_TYPE_get(const ASN1_TYPE *a)
{
    if ((a->value.ptr != NULL) || (a->type == V_ASN1_NULL))
        return a->type;
    else
        return 0;
}

void ASN1_TYPE_set(ASN1_TYPE *a, int type, void *value)
{
    if (a->value.ptr != NULL) {
        ASN1_TYPE **tmp_a = &a;
        asn1_primitive_free((ASN1_VALUE **)tmp_a, NULL, 0);
    }
    a->type = type;
    if (type == V_ASN1_BOOLEAN)
        a->value.boolean = value ? 0xff : 0;
    else
        a->value.ptr = value;
}

int ASN1_TYPE_set1(ASN1_TYPE *a, int type, const void *value)
{
    if (!value || (type == V_ASN1_BOOLEAN)) {
        void *p = (void *)value;
        ASN1_TYPE_set(a, type, p);
    } else if (type == V_ASN1_OBJECT) {
        ASN1_OBJECT *odup;
        odup = OBJ_dup(value);
        if (!odup)
            return 0;
        ASN1_TYPE_set(a, type, odup);
    } else {
        ASN1_STRING *sdup;
        sdup = ASN1_STRING_dup(value);
        if (!sdup)
            return 0;
        ASN1_TYPE_set(a, type, sdup);
    }
    return 1;
}

int ASN1_TYPE_cmp(const ASN1_TYPE *a, const ASN1_TYPE *b)
{
    int result = -1;

    if (!a || !b || a->type != b->type)
        return -1;

    switch (a->type) {
    case V_ASN1_OBJECT:
        result = OBJ_cmp(a->value.object, b->value.object);
        break;
    case V_ASN1_BOOLEAN:
        result = a->value.boolean - b->value.boolean;
        break;
    case V_ASN1_NULL:
        result = 0;             /* They do not have content. */
        break;
    case V_ASN1_INTEGER:
    case V_ASN1_ENUMERATED:
    case V_ASN1_BIT_STRING:
    case V_ASN1_OCTET_STRING:
    case V_ASN1_SEQUENCE:
    case V_ASN1_SET:
    case V_ASN1_NUMERICSTRING:
    case V_ASN1_PRINTABLESTRING:
    case V_ASN1_T61STRING:
    case V_ASN1_VIDEOTEXSTRING:
    case V_ASN1_IA5STRING:
    case V_ASN1_UTCTIME:
    case V_ASN1_GENERALIZEDTIME:
    case V_ASN1_GRAPHICSTRING:
    case V_ASN1_VISIBLESTRING:
    case V_ASN1_GENERALSTRING:
    case V_ASN1_UNIVERSALSTRING:
    case V_ASN1_BMPSTRING:
    case V_ASN1_UTF8STRING:
    case V_ASN1_OTHER:
    default:
        result = ASN1_STRING_cmp((ASN1_STRING *)a->value.ptr,
                                 (ASN1_STRING *)b->value.ptr);
        break;
    }

    return result;
}

ASN1_TYPE *ASN1_TYPE_pack_sequence(const ASN1_ITEM *it, void *s, ASN1_TYPE **t)
{
    ASN1_OCTET_STRING *oct;
    ASN1_TYPE *rt;

    oct = ASN1_item_pack(s, it, NULL);
    if (oct == NULL)
        return NULL;

    if (t && *t) {
        rt = *t;
    } else {
        rt = ASN1_TYPE_new();
        if (rt == NULL) {
            ASN1_OCTET_STRING_free(oct);
            return NULL;
        }
        if (t)
            *t = rt;
    }
    ASN1_TYPE_set(rt, V_ASN1_SEQUENCE, oct);
    return rt;
}

void *ASN1_TYPE_unpack_sequence(const ASN1_ITEM *it, const ASN1_TYPE *t)
{
    if (t == NULL || t->type != V_ASN1_SEQUENCE || t->value.sequence == NULL)
        return NULL;
    return ASN1_item_unpack(t->value.sequence, it);
}

