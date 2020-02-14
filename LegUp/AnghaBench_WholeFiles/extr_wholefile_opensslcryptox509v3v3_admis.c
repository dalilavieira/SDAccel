#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct v3_ext_method {int dummy; } ;
typedef  int /*<<< orphan*/  objbuf ;
struct TYPE_18__ {int /*<<< orphan*/  professionInfos; int /*<<< orphan*/ * namingAuthority; int /*<<< orphan*/  const* admissionAuthority; } ;
struct TYPE_17__ {int /*<<< orphan*/  const* admissionAuthority; int /*<<< orphan*/  contentsOfAdmissions; } ;
struct TYPE_16__ {int /*<<< orphan*/  const* namingAuthorityText; int /*<<< orphan*/  const* namingAuthorityUrl; int /*<<< orphan*/  const* namingAuthorityId; } ;
struct TYPE_15__ {int /*<<< orphan*/ * professionOIDs; int /*<<< orphan*/ * professionItems; int /*<<< orphan*/ * namingAuthority; int /*<<< orphan*/  const* registrationNumber; } ;
typedef  TYPE_1__ PROFESSION_INFO ;
typedef  TYPE_2__ NAMING_AUTHORITY ;
typedef  int /*<<< orphan*/  const GENERAL_NAME ;
typedef  int /*<<< orphan*/  BIO ;
typedef  int /*<<< orphan*/  const ASN1_STRING ;
typedef  int /*<<< orphan*/  const ASN1_OBJECT ;
typedef  int /*<<< orphan*/  const ASN1_IA5STRING ;
typedef  TYPE_3__ ADMISSION_SYNTAX ;
typedef  TYPE_4__ ADMISSIONS ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_IA5STRING_free (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ASN1_OBJECT_free (int /*<<< orphan*/  const*) ; 
 scalar_t__ ASN1_STRING_print (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 scalar_t__ BIO_printf (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  GENERAL_NAME_free (int /*<<< orphan*/  const*) ; 
 scalar_t__ GENERAL_NAME_print (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 char* OBJ_nid2ln (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OBJ_obj2nid (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  OBJ_obj2txt (char*,int,int /*<<< orphan*/  const*,int) ; 
 int sk_ADMISSIONS_num (int /*<<< orphan*/ ) ; 
 TYPE_4__* sk_ADMISSIONS_value (int /*<<< orphan*/ ,int) ; 
 int sk_ASN1_OBJECT_num (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* sk_ASN1_OBJECT_value (int /*<<< orphan*/ *,int) ; 
 int sk_ASN1_STRING_num (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* sk_ASN1_STRING_value (int /*<<< orphan*/ *,int) ; 
 int sk_PROFESSION_INFO_num (int /*<<< orphan*/ ) ; 
 TYPE_1__* sk_PROFESSION_INFO_value (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int i2r_NAMING_AUTHORITY(const struct v3_ext_method *method, void *in,
                                BIO *bp, int ind)
{
    NAMING_AUTHORITY * namingAuthority = (NAMING_AUTHORITY*) in;

    if (namingAuthority == NULL)
        return 0;

    if (namingAuthority->namingAuthorityId == NULL
        && namingAuthority->namingAuthorityText == NULL
        && namingAuthority->namingAuthorityUrl == NULL)
        return 0;

    if (BIO_printf(bp, "%*snamingAuthority: ", ind, "") <= 0)
        goto err;

    if (namingAuthority->namingAuthorityId != NULL) {
        char objbuf[128];
        const char *ln = OBJ_nid2ln(OBJ_obj2nid(namingAuthority->namingAuthorityId));

        if (BIO_printf(bp, "%*s  admissionAuthorityId: ", ind, "") <= 0)
            goto err;

        OBJ_obj2txt(objbuf, sizeof(objbuf), namingAuthority->namingAuthorityId, 1);

        if (BIO_printf(bp, "%s%s%s%s\n", ln ? ln : "",
                       ln ? " (" : "", objbuf, ln ? ")" : "") <= 0)
            goto err;
    }
    if (namingAuthority->namingAuthorityText != NULL) {
        if (BIO_printf(bp, "%*s  namingAuthorityText: ", ind, "") <= 0
            || ASN1_STRING_print(bp, namingAuthority->namingAuthorityText) <= 0
            || BIO_printf(bp, "\n") <= 0)
            goto err;
    }
    if (namingAuthority->namingAuthorityUrl != NULL ) {
        if (BIO_printf(bp, "%*s  namingAuthorityUrl: ", ind, "") <= 0
            || ASN1_STRING_print(bp, namingAuthority->namingAuthorityUrl) <= 0
            || BIO_printf(bp, "\n") <= 0)
            goto err;
    }
    return 1;

err:
    return 0;
}

__attribute__((used)) static int i2r_ADMISSION_SYNTAX(const struct v3_ext_method *method, void *in,
                                BIO *bp, int ind)
{
    ADMISSION_SYNTAX * admission = (ADMISSION_SYNTAX *)in;
    int i, j, k;

    if (admission->admissionAuthority != NULL) {
        if (BIO_printf(bp, "%*sadmissionAuthority:\n", ind, "") <= 0
            || BIO_printf(bp, "%*s  ", ind, "") <= 0
            || GENERAL_NAME_print(bp, admission->admissionAuthority) <= 0
            || BIO_printf(bp, "\n") <= 0)
            goto err;
    }

    for (i = 0; i < sk_ADMISSIONS_num(admission->contentsOfAdmissions); i++) {
        ADMISSIONS* entry = sk_ADMISSIONS_value(admission->contentsOfAdmissions, i);

        if (BIO_printf(bp, "%*sEntry %0d:\n", ind, "", 1 + i) <= 0) goto err;

        if (entry->admissionAuthority != NULL) {
            if (BIO_printf(bp, "%*s  admissionAuthority:\n", ind, "") <= 0
                || BIO_printf(bp, "%*s    ", ind, "") <= 0
                || GENERAL_NAME_print(bp, entry->admissionAuthority) <= 0
                || BIO_printf(bp, "\n") <= 0)
                goto err;
        }

        if (entry->namingAuthority != NULL) {
            if (i2r_NAMING_AUTHORITY(method, entry->namingAuthority, bp, ind) <= 0)
                goto err;
        }

        for (j = 0; j < sk_PROFESSION_INFO_num(entry->professionInfos); j++) {
            PROFESSION_INFO* pinfo = sk_PROFESSION_INFO_value(entry->professionInfos, j);

            if (BIO_printf(bp, "%*s  Profession Info Entry %0d:\n", ind, "", 1 + j) <= 0)
                goto err;

            if (pinfo->registrationNumber != NULL) {
                if (BIO_printf(bp, "%*s    registrationNumber: ", ind, "") <= 0
                    || ASN1_STRING_print(bp, pinfo->registrationNumber) <= 0
                    || BIO_printf(bp, "\n") <= 0)
                    goto err;
            }

            if (pinfo->namingAuthority != NULL) {
                if (i2r_NAMING_AUTHORITY(method, pinfo->namingAuthority, bp, ind + 2) <= 0)
                    goto err;
            }

            if (pinfo->professionItems != NULL) {

                if (BIO_printf(bp, "%*s    Info Entries:\n", ind, "") <= 0)
                    goto err;
                for (k = 0; k < sk_ASN1_STRING_num(pinfo->professionItems); k++) {
                    ASN1_STRING* val = sk_ASN1_STRING_value(pinfo->professionItems, k);

                    if (BIO_printf(bp, "%*s      ", ind, "") <= 0
                        || ASN1_STRING_print(bp, val) <= 0
                        || BIO_printf(bp, "\n") <= 0)
                        goto err;
                }
            }

            if (pinfo->professionOIDs != NULL) {
                if (BIO_printf(bp, "%*s    Profession OIDs:\n", ind, "") <= 0)
                    goto err;
                for (k = 0; k < sk_ASN1_OBJECT_num(pinfo->professionOIDs); k++) {
                    ASN1_OBJECT* obj = sk_ASN1_OBJECT_value(pinfo->professionOIDs, k);
                    const char *ln = OBJ_nid2ln(OBJ_obj2nid(obj));
                    char objbuf[128];

                    OBJ_obj2txt(objbuf, sizeof(objbuf), obj, 1);
                    if (BIO_printf(bp, "%*s      %s%s%s%s\n", ind, "",
                                   ln ? ln : "", ln ? " (" : "",
                                   objbuf, ln ? ")" : "") <= 0)
                        goto err;
                }
            }
        }
    }
    return 1;

err:
    return -1;
}

const ASN1_OBJECT *NAMING_AUTHORITY_get0_authorityId(const NAMING_AUTHORITY *n)
{
    return n->namingAuthorityId;
}

void NAMING_AUTHORITY_set0_authorityId(NAMING_AUTHORITY *n, ASN1_OBJECT* id)
{
    ASN1_OBJECT_free(n->namingAuthorityId);
    n->namingAuthorityId = id;
}

const ASN1_IA5STRING *NAMING_AUTHORITY_get0_authorityURL(
    const NAMING_AUTHORITY *n)
{
    return n->namingAuthorityUrl;
}

void NAMING_AUTHORITY_set0_authorityURL(NAMING_AUTHORITY *n, ASN1_IA5STRING* u)
{
    ASN1_IA5STRING_free(n->namingAuthorityUrl);
    n->namingAuthorityUrl = u;
}

const ASN1_STRING *NAMING_AUTHORITY_get0_authorityText(
    const NAMING_AUTHORITY *n)
{
    return n->namingAuthorityText;
}

void NAMING_AUTHORITY_set0_authorityText(NAMING_AUTHORITY *n, ASN1_STRING* t)
{
    ASN1_IA5STRING_free(n->namingAuthorityText);
    n->namingAuthorityText = t;
}

const GENERAL_NAME *ADMISSION_SYNTAX_get0_admissionAuthority(const ADMISSION_SYNTAX *as)
{
    return as->admissionAuthority;
}

void ADMISSION_SYNTAX_set0_admissionAuthority(ADMISSION_SYNTAX *as,
                                              GENERAL_NAME *aa)
{
    GENERAL_NAME_free(as->admissionAuthority);
    as->admissionAuthority = aa;
}

