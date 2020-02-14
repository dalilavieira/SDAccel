#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  X509_SIG ;
struct TYPE_8__ {int /*<<< orphan*/  const* shkeybag; int /*<<< orphan*/  const* keybag; } ;
struct TYPE_9__ {TYPE_1__ value; int /*<<< orphan*/  type; int /*<<< orphan*/  attrib; } ;
typedef  int /*<<< orphan*/  PKCS8_PRIV_KEY_INFO ;
typedef  TYPE_2__ PKCS12_SAFEBAG ;
typedef  int /*<<< orphan*/  const ASN1_TYPE ;

/* Variables and functions */
 scalar_t__ NID_keyBag ; 
 scalar_t__ NID_pkcs8ShroudedKeyBag ; 
 scalar_t__ OBJ_obj2nid (int /*<<< orphan*/ ) ; 
 scalar_t__ PKCS12_SAFEBAG_get_nid (TYPE_2__ const*) ; 
 int /*<<< orphan*/  const* PKCS12_get_attr_gen (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PKCS8_pkey_get0_attrs (int /*<<< orphan*/ *) ; 

ASN1_TYPE *PKCS12_get_attr(const PKCS12_SAFEBAG *bag, int attr_nid)
{
    return PKCS12_get_attr_gen(bag->attrib, attr_nid);
}

const ASN1_TYPE *PKCS12_SAFEBAG_get0_attr(const PKCS12_SAFEBAG *bag,
                                          int attr_nid)
{
    return PKCS12_get_attr_gen(bag->attrib, attr_nid);
}

ASN1_TYPE *PKCS8_get_attr(PKCS8_PRIV_KEY_INFO *p8, int attr_nid)
{
    return PKCS12_get_attr_gen(PKCS8_pkey_get0_attrs(p8), attr_nid);
}

const PKCS8_PRIV_KEY_INFO *PKCS12_SAFEBAG_get0_p8inf(const PKCS12_SAFEBAG *bag)
{
    if (PKCS12_SAFEBAG_get_nid(bag) != NID_keyBag)
        return NULL;
    return bag->value.keybag;
}

const X509_SIG *PKCS12_SAFEBAG_get0_pkcs8(const PKCS12_SAFEBAG *bag)
{
    if (OBJ_obj2nid(bag->type) != NID_pkcs8ShroudedKeyBag)
        return NULL;
    return bag->value.shkeybag;
}

