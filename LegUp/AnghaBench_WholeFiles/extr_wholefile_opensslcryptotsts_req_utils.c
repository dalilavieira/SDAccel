#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  X509_ALGOR ;
struct TYPE_23__ {int /*<<< orphan*/ * hashed_msg; int /*<<< orphan*/ * hash_algo; } ;
struct TYPE_22__ {int cert_req; int /*<<< orphan*/  const* nonce; int /*<<< orphan*/  const* policy_id; TYPE_2__* msg_imprint; int /*<<< orphan*/  version; } ;
typedef  TYPE_1__ TS_REQ ;
typedef  TYPE_2__ TS_MSG_IMPRINT ;
typedef  int /*<<< orphan*/  ASN1_OCTET_STRING ;
typedef  int /*<<< orphan*/  const ASN1_OBJECT ;
typedef  int /*<<< orphan*/  const ASN1_INTEGER ;

/* Variables and functions */
 int /*<<< orphan*/  const* ASN1_INTEGER_dup (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ASN1_INTEGER_free (int /*<<< orphan*/  const*) ; 
 long ASN1_INTEGER_get (int /*<<< orphan*/ ) ; 
 int ASN1_INTEGER_set (int /*<<< orphan*/ ,long) ; 
 int /*<<< orphan*/  ASN1_OBJECT_free (int /*<<< orphan*/  const*) ; 
 int ASN1_OCTET_STRING_set (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  const* OBJ_dup (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  TS_F_TS_MSG_IMPRINT_SET_ALGO ; 
 int /*<<< orphan*/  TS_F_TS_REQ_SET_MSG_IMPRINT ; 
 int /*<<< orphan*/  TS_F_TS_REQ_SET_NONCE ; 
 int /*<<< orphan*/  TS_F_TS_REQ_SET_POLICY_ID ; 
 TYPE_2__* TS_MSG_IMPRINT_dup (TYPE_2__*) ; 
 int /*<<< orphan*/  TS_MSG_IMPRINT_free (TYPE_2__*) ; 
 int /*<<< orphan*/  TSerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * X509_ALGOR_dup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  X509_ALGOR_free (int /*<<< orphan*/ *) ; 

int TS_REQ_set_version(TS_REQ *a, long version)
{
    return ASN1_INTEGER_set(a->version, version);
}

long TS_REQ_get_version(const TS_REQ *a)
{
    return ASN1_INTEGER_get(a->version);
}

int TS_REQ_set_msg_imprint(TS_REQ *a, TS_MSG_IMPRINT *msg_imprint)
{
    TS_MSG_IMPRINT *new_msg_imprint;

    if (a->msg_imprint == msg_imprint)
        return 1;
    new_msg_imprint = TS_MSG_IMPRINT_dup(msg_imprint);
    if (new_msg_imprint == NULL) {
        TSerr(TS_F_TS_REQ_SET_MSG_IMPRINT, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    TS_MSG_IMPRINT_free(a->msg_imprint);
    a->msg_imprint = new_msg_imprint;
    return 1;
}

TS_MSG_IMPRINT *TS_REQ_get_msg_imprint(TS_REQ *a)
{
    return a->msg_imprint;
}

int TS_MSG_IMPRINT_set_algo(TS_MSG_IMPRINT *a, X509_ALGOR *alg)
{
    X509_ALGOR *new_alg;

    if (a->hash_algo == alg)
        return 1;
    new_alg = X509_ALGOR_dup(alg);
    if (new_alg == NULL) {
        TSerr(TS_F_TS_MSG_IMPRINT_SET_ALGO, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    X509_ALGOR_free(a->hash_algo);
    a->hash_algo = new_alg;
    return 1;
}

X509_ALGOR *TS_MSG_IMPRINT_get_algo(TS_MSG_IMPRINT *a)
{
    return a->hash_algo;
}

int TS_MSG_IMPRINT_set_msg(TS_MSG_IMPRINT *a, unsigned char *d, int len)
{
    return ASN1_OCTET_STRING_set(a->hashed_msg, d, len);
}

ASN1_OCTET_STRING *TS_MSG_IMPRINT_get_msg(TS_MSG_IMPRINT *a)
{
    return a->hashed_msg;
}

int TS_REQ_set_policy_id(TS_REQ *a, const ASN1_OBJECT *policy)
{
    ASN1_OBJECT *new_policy;

    if (a->policy_id == policy)
        return 1;
    new_policy = OBJ_dup(policy);
    if (new_policy == NULL) {
        TSerr(TS_F_TS_REQ_SET_POLICY_ID, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    ASN1_OBJECT_free(a->policy_id);
    a->policy_id = new_policy;
    return 1;
}

ASN1_OBJECT *TS_REQ_get_policy_id(TS_REQ *a)
{
    return a->policy_id;
}

int TS_REQ_set_nonce(TS_REQ *a, const ASN1_INTEGER *nonce)
{
    ASN1_INTEGER *new_nonce;

    if (a->nonce == nonce)
        return 1;
    new_nonce = ASN1_INTEGER_dup(nonce);
    if (new_nonce == NULL) {
        TSerr(TS_F_TS_REQ_SET_NONCE, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    ASN1_INTEGER_free(a->nonce);
    a->nonce = new_nonce;
    return 1;
}

const ASN1_INTEGER *TS_REQ_get_nonce(const TS_REQ *a)
{
    return a->nonce;
}

int TS_REQ_set_cert_req(TS_REQ *a, int cert_req)
{
    a->cert_req = cert_req ? 0xFF : 0x00;
    return 1;
}

int TS_REQ_get_cert_req(const TS_REQ *a)
{
    return a->cert_req ? 1 : 0;
}

