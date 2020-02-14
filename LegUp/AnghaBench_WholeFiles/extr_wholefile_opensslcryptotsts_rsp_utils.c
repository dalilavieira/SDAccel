#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_43__   TYPE_3__ ;
typedef  struct TYPE_42__   TYPE_2__ ;
typedef  struct TYPE_41__   TYPE_1__ ;

/* Type definitions */
struct TYPE_43__ {int /*<<< orphan*/  const* micros; int /*<<< orphan*/  const* millis; int /*<<< orphan*/  const* seconds; } ;
struct TYPE_42__ {TYPE_1__* tst_info; int /*<<< orphan*/ * token; int /*<<< orphan*/ * status_info; } ;
struct TYPE_41__ {int ordering; int /*<<< orphan*/ * tsa; int /*<<< orphan*/  const* nonce; TYPE_3__* accuracy; int /*<<< orphan*/  const* time; int /*<<< orphan*/  const* serial; int /*<<< orphan*/ * msg_imprint; int /*<<< orphan*/ * policy_id; int /*<<< orphan*/  version; } ;
typedef  TYPE_1__ TS_TST_INFO ;
typedef  int /*<<< orphan*/  TS_STATUS_INFO ;
typedef  TYPE_2__ TS_RESP ;
typedef  int /*<<< orphan*/  TS_MSG_IMPRINT ;
typedef  TYPE_3__ TS_ACCURACY ;
typedef  int /*<<< orphan*/  PKCS7 ;
typedef  int /*<<< orphan*/  GENERAL_NAME ;
typedef  int /*<<< orphan*/  ASN1_OBJECT ;
typedef  int /*<<< orphan*/  const ASN1_INTEGER ;
typedef  int /*<<< orphan*/  const ASN1_GENERALIZEDTIME ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_GENERALIZEDTIME_free (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* ASN1_INTEGER_dup (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ASN1_INTEGER_free (int /*<<< orphan*/  const*) ; 
 long ASN1_INTEGER_get (int /*<<< orphan*/ ) ; 
 int ASN1_INTEGER_set (int /*<<< orphan*/ ,long) ; 
 int /*<<< orphan*/  ASN1_OBJECT_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* ASN1_STRING_dup (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/ * GENERAL_NAME_dup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GENERAL_NAME_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * OBJ_dup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PKCS7_free (int /*<<< orphan*/ *) ; 
 TYPE_3__* TS_ACCURACY_dup (TYPE_3__*) ; 
 int /*<<< orphan*/  TS_ACCURACY_free (TYPE_3__*) ; 
 int /*<<< orphan*/  TS_F_TS_ACCURACY_SET_MICROS ; 
 int /*<<< orphan*/  TS_F_TS_ACCURACY_SET_MILLIS ; 
 int /*<<< orphan*/  TS_F_TS_ACCURACY_SET_SECONDS ; 
 int /*<<< orphan*/  TS_F_TS_RESP_SET_STATUS_INFO ; 
 int /*<<< orphan*/  TS_F_TS_TST_INFO_SET_ACCURACY ; 
 int /*<<< orphan*/  TS_F_TS_TST_INFO_SET_MSG_IMPRINT ; 
 int /*<<< orphan*/  TS_F_TS_TST_INFO_SET_NONCE ; 
 int /*<<< orphan*/  TS_F_TS_TST_INFO_SET_POLICY_ID ; 
 int /*<<< orphan*/  TS_F_TS_TST_INFO_SET_SERIAL ; 
 int /*<<< orphan*/  TS_F_TS_TST_INFO_SET_TIME ; 
 int /*<<< orphan*/  TS_F_TS_TST_INFO_SET_TSA ; 
 int /*<<< orphan*/ * TS_MSG_IMPRINT_dup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TS_MSG_IMPRINT_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * TS_STATUS_INFO_dup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TS_STATUS_INFO_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TS_TST_INFO_free (TYPE_1__*) ; 
 int /*<<< orphan*/  TSerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int TS_RESP_set_status_info(TS_RESP *a, TS_STATUS_INFO *status_info)
{
    TS_STATUS_INFO *new_status_info;

    if (a->status_info == status_info)
        return 1;
    new_status_info = TS_STATUS_INFO_dup(status_info);
    if (new_status_info == NULL) {
        TSerr(TS_F_TS_RESP_SET_STATUS_INFO, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    TS_STATUS_INFO_free(a->status_info);
    a->status_info = new_status_info;

    return 1;
}

TS_STATUS_INFO *TS_RESP_get_status_info(TS_RESP *a)
{
    return a->status_info;
}

void TS_RESP_set_tst_info(TS_RESP *a, PKCS7 *p7, TS_TST_INFO *tst_info)
{
    PKCS7_free(a->token);
    a->token = p7;
    TS_TST_INFO_free(a->tst_info);
    a->tst_info = tst_info;
}

PKCS7 *TS_RESP_get_token(TS_RESP *a)
{
    return a->token;
}

TS_TST_INFO *TS_RESP_get_tst_info(TS_RESP *a)
{
    return a->tst_info;
}

int TS_TST_INFO_set_version(TS_TST_INFO *a, long version)
{
    return ASN1_INTEGER_set(a->version, version);
}

long TS_TST_INFO_get_version(const TS_TST_INFO *a)
{
    return ASN1_INTEGER_get(a->version);
}

int TS_TST_INFO_set_policy_id(TS_TST_INFO *a, ASN1_OBJECT *policy)
{
    ASN1_OBJECT *new_policy;

    if (a->policy_id == policy)
        return 1;
    new_policy = OBJ_dup(policy);
    if (new_policy == NULL) {
        TSerr(TS_F_TS_TST_INFO_SET_POLICY_ID, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    ASN1_OBJECT_free(a->policy_id);
    a->policy_id = new_policy;
    return 1;
}

ASN1_OBJECT *TS_TST_INFO_get_policy_id(TS_TST_INFO *a)
{
    return a->policy_id;
}

int TS_TST_INFO_set_msg_imprint(TS_TST_INFO *a, TS_MSG_IMPRINT *msg_imprint)
{
    TS_MSG_IMPRINT *new_msg_imprint;

    if (a->msg_imprint == msg_imprint)
        return 1;
    new_msg_imprint = TS_MSG_IMPRINT_dup(msg_imprint);
    if (new_msg_imprint == NULL) {
        TSerr(TS_F_TS_TST_INFO_SET_MSG_IMPRINT, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    TS_MSG_IMPRINT_free(a->msg_imprint);
    a->msg_imprint = new_msg_imprint;
    return 1;
}

TS_MSG_IMPRINT *TS_TST_INFO_get_msg_imprint(TS_TST_INFO *a)
{
    return a->msg_imprint;
}

int TS_TST_INFO_set_serial(TS_TST_INFO *a, const ASN1_INTEGER *serial)
{
    ASN1_INTEGER *new_serial;

    if (a->serial == serial)
        return 1;
    new_serial = ASN1_INTEGER_dup(serial);
    if (new_serial == NULL) {
        TSerr(TS_F_TS_TST_INFO_SET_SERIAL, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    ASN1_INTEGER_free(a->serial);
    a->serial = new_serial;
    return 1;
}

const ASN1_INTEGER *TS_TST_INFO_get_serial(const TS_TST_INFO *a)
{
    return a->serial;
}

int TS_TST_INFO_set_time(TS_TST_INFO *a, const ASN1_GENERALIZEDTIME *gtime)
{
    ASN1_GENERALIZEDTIME *new_time;

    if (a->time == gtime)
        return 1;
    new_time = ASN1_STRING_dup(gtime);
    if (new_time == NULL) {
        TSerr(TS_F_TS_TST_INFO_SET_TIME, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    ASN1_GENERALIZEDTIME_free(a->time);
    a->time = new_time;
    return 1;
}

const ASN1_GENERALIZEDTIME *TS_TST_INFO_get_time(const TS_TST_INFO *a)
{
    return a->time;
}

int TS_TST_INFO_set_accuracy(TS_TST_INFO *a, TS_ACCURACY *accuracy)
{
    TS_ACCURACY *new_accuracy;

    if (a->accuracy == accuracy)
        return 1;
    new_accuracy = TS_ACCURACY_dup(accuracy);
    if (new_accuracy == NULL) {
        TSerr(TS_F_TS_TST_INFO_SET_ACCURACY, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    TS_ACCURACY_free(a->accuracy);
    a->accuracy = new_accuracy;
    return 1;
}

TS_ACCURACY *TS_TST_INFO_get_accuracy(TS_TST_INFO *a)
{
    return a->accuracy;
}

int TS_ACCURACY_set_seconds(TS_ACCURACY *a, const ASN1_INTEGER *seconds)
{
    ASN1_INTEGER *new_seconds;

    if (a->seconds == seconds)
        return 1;
    new_seconds = ASN1_INTEGER_dup(seconds);
    if (new_seconds == NULL) {
        TSerr(TS_F_TS_ACCURACY_SET_SECONDS, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    ASN1_INTEGER_free(a->seconds);
    a->seconds = new_seconds;
    return 1;
}

const ASN1_INTEGER *TS_ACCURACY_get_seconds(const TS_ACCURACY *a)
{
    return a->seconds;
}

int TS_ACCURACY_set_millis(TS_ACCURACY *a, const ASN1_INTEGER *millis)
{
    ASN1_INTEGER *new_millis = NULL;

    if (a->millis == millis)
        return 1;
    if (millis != NULL) {
        new_millis = ASN1_INTEGER_dup(millis);
        if (new_millis == NULL) {
            TSerr(TS_F_TS_ACCURACY_SET_MILLIS, ERR_R_MALLOC_FAILURE);
            return 0;
        }
    }
    ASN1_INTEGER_free(a->millis);
    a->millis = new_millis;
    return 1;
}

const ASN1_INTEGER *TS_ACCURACY_get_millis(const TS_ACCURACY *a)
{
    return a->millis;
}

int TS_ACCURACY_set_micros(TS_ACCURACY *a, const ASN1_INTEGER *micros)
{
    ASN1_INTEGER *new_micros = NULL;

    if (a->micros == micros)
        return 1;
    if (micros != NULL) {
        new_micros = ASN1_INTEGER_dup(micros);
        if (new_micros == NULL) {
            TSerr(TS_F_TS_ACCURACY_SET_MICROS, ERR_R_MALLOC_FAILURE);
            return 0;
        }
    }
    ASN1_INTEGER_free(a->micros);
    a->micros = new_micros;
    return 1;
}

const ASN1_INTEGER *TS_ACCURACY_get_micros(const TS_ACCURACY *a)
{
    return a->micros;
}

int TS_TST_INFO_set_ordering(TS_TST_INFO *a, int ordering)
{
    a->ordering = ordering ? 0xFF : 0x00;
    return 1;
}

int TS_TST_INFO_get_ordering(const TS_TST_INFO *a)
{
    return a->ordering ? 1 : 0;
}

int TS_TST_INFO_set_nonce(TS_TST_INFO *a, const ASN1_INTEGER *nonce)
{
    ASN1_INTEGER *new_nonce;

    if (a->nonce == nonce)
        return 1;
    new_nonce = ASN1_INTEGER_dup(nonce);
    if (new_nonce == NULL) {
        TSerr(TS_F_TS_TST_INFO_SET_NONCE, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    ASN1_INTEGER_free(a->nonce);
    a->nonce = new_nonce;
    return 1;
}

const ASN1_INTEGER *TS_TST_INFO_get_nonce(const TS_TST_INFO *a)
{
    return a->nonce;
}

int TS_TST_INFO_set_tsa(TS_TST_INFO *a, GENERAL_NAME *tsa)
{
    GENERAL_NAME *new_tsa;

    if (a->tsa == tsa)
        return 1;
    new_tsa = GENERAL_NAME_dup(tsa);
    if (new_tsa == NULL) {
        TSerr(TS_F_TS_TST_INFO_SET_TSA, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    GENERAL_NAME_free(a->tsa);
    a->tsa = new_tsa;
    return 1;
}

GENERAL_NAME *TS_TST_INFO_get_tsa(TS_TST_INFO *a)
{
    return a->tsa;
}

