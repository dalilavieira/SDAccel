#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_44__   TYPE_9__ ;
typedef  struct TYPE_43__   TYPE_8__ ;
typedef  struct TYPE_42__   TYPE_7__ ;
typedef  struct TYPE_41__   TYPE_6__ ;
typedef  struct TYPE_40__   TYPE_5__ ;
typedef  struct TYPE_39__   TYPE_4__ ;
typedef  struct TYPE_38__   TYPE_3__ ;
typedef  struct TYPE_37__   TYPE_2__ ;
typedef  struct TYPE_36__   TYPE_1__ ;
typedef  struct TYPE_35__   TYPE_17__ ;
typedef  struct TYPE_34__   TYPE_16__ ;
typedef  struct TYPE_33__   TYPE_15__ ;
typedef  struct TYPE_32__   TYPE_14__ ;
typedef  struct TYPE_31__   TYPE_13__ ;
typedef  struct TYPE_30__   TYPE_12__ ;
typedef  struct TYPE_29__   TYPE_11__ ;
typedef  struct TYPE_28__   TYPE_10__ ;

/* Type definitions */
struct TYPE_36__ {int /*<<< orphan*/ * byKey; int /*<<< orphan*/  byName; } ;
struct TYPE_44__ {int type; TYPE_1__ value; } ;
struct TYPE_43__ {scalar_t__ responseStatus; TYPE_11__* responseBytes; } ;
struct TYPE_42__ {scalar_t__ revocationReason; scalar_t__ revocationTime; } ;
struct TYPE_41__ {int /*<<< orphan*/  certs; int /*<<< orphan*/  signature; int /*<<< orphan*/  signatureAlgorithm; } ;
struct TYPE_40__ {int /*<<< orphan*/  singleExtensions; scalar_t__ nextUpdate; scalar_t__ thisUpdate; TYPE_15__* certStatus; TYPE_16__* certId; } ;
struct TYPE_39__ {long t; char const* m; long member_0; char* member_1; } ;
struct TYPE_38__ {int /*<<< orphan*/  algorithm; } ;
struct TYPE_37__ {TYPE_7__* revoked; } ;
struct TYPE_28__ {int /*<<< orphan*/  responseExtensions; int /*<<< orphan*/  responses; scalar_t__ producedAt; TYPE_9__ responderId; int /*<<< orphan*/  version; } ;
struct TYPE_35__ {int /*<<< orphan*/  certs; int /*<<< orphan*/  signature; int /*<<< orphan*/  signatureAlgorithm; TYPE_10__ tbsResponseData; } ;
struct TYPE_34__ {int /*<<< orphan*/  serialNumber; int /*<<< orphan*/  issuerKeyHash; int /*<<< orphan*/  issuerNameHash; TYPE_3__ hashAlgorithm; } ;
struct TYPE_33__ {long type; TYPE_2__ value; } ;
struct TYPE_32__ {int /*<<< orphan*/  singleRequestExtensions; TYPE_16__* reqCert; } ;
struct TYPE_31__ {int /*<<< orphan*/  requestExtensions; int /*<<< orphan*/  requestList; int /*<<< orphan*/ * requestorName; int /*<<< orphan*/  version; } ;
struct TYPE_30__ {TYPE_6__* optionalSignature; TYPE_13__ tbsRequest; } ;
struct TYPE_29__ {int /*<<< orphan*/  responseType; } ;
typedef  TYPE_4__ OCSP_TBLSTR ;
typedef  TYPE_5__ OCSP_SINGLERESP ;
typedef  TYPE_6__ OCSP_SIGNATURE ;
typedef  TYPE_7__ OCSP_REVOKEDINFO ;
typedef  TYPE_8__ OCSP_RESPONSE ;
typedef  TYPE_9__ OCSP_RESPID ;
typedef  TYPE_10__ OCSP_RESPDATA ;
typedef  TYPE_11__ OCSP_RESPBYTES ;
typedef  TYPE_12__ OCSP_REQUEST ;
typedef  TYPE_13__ OCSP_REQINFO ;
typedef  TYPE_14__ OCSP_ONEREQ ;
typedef  TYPE_15__ OCSP_CERTSTATUS ;
typedef  TYPE_16__ OCSP_CERTID ;
typedef  TYPE_17__ OCSP_BASICRESP ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 long ASN1_ENUMERATED_get (scalar_t__) ; 
 int /*<<< orphan*/  ASN1_GENERALIZEDTIME_print (int /*<<< orphan*/ *,scalar_t__) ; 
 long ASN1_INTEGER_get (int /*<<< orphan*/ ) ; 
 scalar_t__ BIO_printf (int /*<<< orphan*/ *,char*,...) ; 
 scalar_t__ BIO_puts (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ BIO_write (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  GENERAL_NAME_print (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ NID_id_pkix_OCSP_basic ; 
 scalar_t__ OBJ_obj2nid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OCSP_BASICRESP_free (TYPE_17__*) ; 
#define  OCSP_RESPONSE_STATUS_INTERNALERROR 146 
#define  OCSP_RESPONSE_STATUS_MALFORMEDREQUEST 145 
#define  OCSP_RESPONSE_STATUS_SIGREQUIRED 144 
#define  OCSP_RESPONSE_STATUS_SUCCESSFUL 143 
#define  OCSP_RESPONSE_STATUS_TRYLATER 142 
#define  OCSP_RESPONSE_STATUS_UNAUTHORIZED 141 
#define  OCSP_REVOKED_STATUS_AFFILIATIONCHANGED 140 
#define  OCSP_REVOKED_STATUS_CACOMPROMISE 139 
#define  OCSP_REVOKED_STATUS_CERTIFICATEHOLD 138 
#define  OCSP_REVOKED_STATUS_CESSATIONOFOPERATION 137 
#define  OCSP_REVOKED_STATUS_KEYCOMPROMISE 136 
#define  OCSP_REVOKED_STATUS_REMOVEFROMCRL 135 
#define  OCSP_REVOKED_STATUS_SUPERSEDED 134 
#define  OCSP_REVOKED_STATUS_UNSPECIFIED 133 
 TYPE_17__* OCSP_response_get1_basic (TYPE_8__*) ; 
 int /*<<< orphan*/  PEM_write_bio_X509 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
#define  V_OCSP_CERTSTATUS_GOOD 132 
#define  V_OCSP_CERTSTATUS_REVOKED 131 
#define  V_OCSP_CERTSTATUS_UNKNOWN 130 
#define  V_OCSP_RESPID_KEY 129 
#define  V_OCSP_RESPID_NAME 128 
 int /*<<< orphan*/  X509V3_extensions_print (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,unsigned long,int) ; 
 int /*<<< orphan*/  X509_NAME_print_ex (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  X509_print (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ X509_signature_print (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XN_FLAG_ONELINE ; 
 int /*<<< orphan*/  i2a_ASN1_INTEGER (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ i2a_ASN1_OBJECT (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2a_ASN1_STRING (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int sk_OCSP_ONEREQ_num (int /*<<< orphan*/ ) ; 
 TYPE_14__* sk_OCSP_ONEREQ_value (int /*<<< orphan*/ ,int) ; 
 int sk_OCSP_SINGLERESP_num (int /*<<< orphan*/ ) ; 
 TYPE_5__* sk_OCSP_SINGLERESP_value (int /*<<< orphan*/ ,int) ; 
 int sk_X509_num (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sk_X509_value (int /*<<< orphan*/ ,int) ; 
 char const* table2string (long,TYPE_4__ const*) ; 

__attribute__((used)) static int ocsp_certid_print(BIO *bp, OCSP_CERTID *a, int indent)
{
    BIO_printf(bp, "%*sCertificate ID:\n", indent, "");
    indent += 2;
    BIO_printf(bp, "%*sHash Algorithm: ", indent, "");
    i2a_ASN1_OBJECT(bp, a->hashAlgorithm.algorithm);
    BIO_printf(bp, "\n%*sIssuer Name Hash: ", indent, "");
    i2a_ASN1_STRING(bp, &a->issuerNameHash, 0);
    BIO_printf(bp, "\n%*sIssuer Key Hash: ", indent, "");
    i2a_ASN1_STRING(bp, &a->issuerKeyHash, 0);
    BIO_printf(bp, "\n%*sSerial Number: ", indent, "");
    i2a_ASN1_INTEGER(bp, &a->serialNumber);
    BIO_printf(bp, "\n");
    return 1;
}

__attribute__((used)) static const char *do_table2string(long s, const OCSP_TBLSTR *ts, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++, ts++)
        if (ts->t == s)
            return ts->m;
    return "(UNKNOWN)";
}

const char *OCSP_response_status_str(long s)
{
    static const OCSP_TBLSTR rstat_tbl[] = {
        {OCSP_RESPONSE_STATUS_SUCCESSFUL, "successful"},
        {OCSP_RESPONSE_STATUS_MALFORMEDREQUEST, "malformedrequest"},
        {OCSP_RESPONSE_STATUS_INTERNALERROR, "internalerror"},
        {OCSP_RESPONSE_STATUS_TRYLATER, "trylater"},
        {OCSP_RESPONSE_STATUS_SIGREQUIRED, "sigrequired"},
        {OCSP_RESPONSE_STATUS_UNAUTHORIZED, "unauthorized"}
    };
    return table2string(s, rstat_tbl);
}

const char *OCSP_cert_status_str(long s)
{
    static const OCSP_TBLSTR cstat_tbl[] = {
        {V_OCSP_CERTSTATUS_GOOD, "good"},
        {V_OCSP_CERTSTATUS_REVOKED, "revoked"},
        {V_OCSP_CERTSTATUS_UNKNOWN, "unknown"}
    };
    return table2string(s, cstat_tbl);
}

const char *OCSP_crl_reason_str(long s)
{
    static const OCSP_TBLSTR reason_tbl[] = {
        {OCSP_REVOKED_STATUS_UNSPECIFIED, "unspecified"},
        {OCSP_REVOKED_STATUS_KEYCOMPROMISE, "keyCompromise"},
        {OCSP_REVOKED_STATUS_CACOMPROMISE, "cACompromise"},
        {OCSP_REVOKED_STATUS_AFFILIATIONCHANGED, "affiliationChanged"},
        {OCSP_REVOKED_STATUS_SUPERSEDED, "superseded"},
        {OCSP_REVOKED_STATUS_CESSATIONOFOPERATION, "cessationOfOperation"},
        {OCSP_REVOKED_STATUS_CERTIFICATEHOLD, "certificateHold"},
        {OCSP_REVOKED_STATUS_REMOVEFROMCRL, "removeFromCRL"}
    };
    return table2string(s, reason_tbl);
}

int OCSP_REQUEST_print(BIO *bp, OCSP_REQUEST *o, unsigned long flags)
{
    int i;
    long l;
    OCSP_CERTID *cid = NULL;
    OCSP_ONEREQ *one = NULL;
    OCSP_REQINFO *inf = &o->tbsRequest;
    OCSP_SIGNATURE *sig = o->optionalSignature;

    if (BIO_write(bp, "OCSP Request Data:\n", 19) <= 0)
        goto err;
    l = ASN1_INTEGER_get(inf->version);
    if (BIO_printf(bp, "    Version: %lu (0x%lx)", l + 1, l) <= 0)
        goto err;
    if (inf->requestorName != NULL) {
        if (BIO_write(bp, "\n    Requestor Name: ", 21) <= 0)
            goto err;
        GENERAL_NAME_print(bp, inf->requestorName);
    }
    if (BIO_write(bp, "\n    Requestor List:\n", 21) <= 0)
        goto err;
    for (i = 0; i < sk_OCSP_ONEREQ_num(inf->requestList); i++) {
        one = sk_OCSP_ONEREQ_value(inf->requestList, i);
        cid = one->reqCert;
        ocsp_certid_print(bp, cid, 8);
        if (!X509V3_extensions_print(bp,
                                     "Request Single Extensions",
                                     one->singleRequestExtensions, flags, 8))
            goto err;
    }
    if (!X509V3_extensions_print(bp, "Request Extensions",
                                 inf->requestExtensions, flags, 4))
        goto err;
    if (sig) {
        X509_signature_print(bp, &sig->signatureAlgorithm, sig->signature);
        for (i = 0; i < sk_X509_num(sig->certs); i++) {
            X509_print(bp, sk_X509_value(sig->certs, i));
            PEM_write_bio_X509(bp, sk_X509_value(sig->certs, i));
        }
    }
    return 1;
 err:
    return 0;
}

int OCSP_RESPONSE_print(BIO *bp, OCSP_RESPONSE *o, unsigned long flags)
{
    int i, ret = 0;
    long l;
    OCSP_CERTID *cid = NULL;
    OCSP_BASICRESP *br = NULL;
    OCSP_RESPID *rid = NULL;
    OCSP_RESPDATA *rd = NULL;
    OCSP_CERTSTATUS *cst = NULL;
    OCSP_REVOKEDINFO *rev = NULL;
    OCSP_SINGLERESP *single = NULL;
    OCSP_RESPBYTES *rb = o->responseBytes;

    if (BIO_puts(bp, "OCSP Response Data:\n") <= 0)
        goto err;
    l = ASN1_ENUMERATED_get(o->responseStatus);
    if (BIO_printf(bp, "    OCSP Response Status: %s (0x%lx)\n",
                   OCSP_response_status_str(l), l) <= 0)
        goto err;
    if (rb == NULL)
        return 1;
    if (BIO_puts(bp, "    Response Type: ") <= 0)
        goto err;
    if (i2a_ASN1_OBJECT(bp, rb->responseType) <= 0)
        goto err;
    if (OBJ_obj2nid(rb->responseType) != NID_id_pkix_OCSP_basic) {
        BIO_puts(bp, " (unknown response type)\n");
        return 1;
    }

    if ((br = OCSP_response_get1_basic(o)) == NULL)
        goto err;
    rd = &br->tbsResponseData;
    l = ASN1_INTEGER_get(rd->version);
    if (BIO_printf(bp, "\n    Version: %lu (0x%lx)\n", l + 1, l) <= 0)
        goto err;
    if (BIO_puts(bp, "    Responder Id: ") <= 0)
        goto err;

    rid = &rd->responderId;
    switch (rid->type) {
    case V_OCSP_RESPID_NAME:
        X509_NAME_print_ex(bp, rid->value.byName, 0, XN_FLAG_ONELINE);
        break;
    case V_OCSP_RESPID_KEY:
        i2a_ASN1_STRING(bp, rid->value.byKey, 0);
        break;
    }

    if (BIO_printf(bp, "\n    Produced At: ") <= 0)
        goto err;
    if (!ASN1_GENERALIZEDTIME_print(bp, rd->producedAt))
        goto err;
    if (BIO_printf(bp, "\n    Responses:\n") <= 0)
        goto err;
    for (i = 0; i < sk_OCSP_SINGLERESP_num(rd->responses); i++) {
        if (!sk_OCSP_SINGLERESP_value(rd->responses, i))
            continue;
        single = sk_OCSP_SINGLERESP_value(rd->responses, i);
        cid = single->certId;
        if (ocsp_certid_print(bp, cid, 4) <= 0)
            goto err;
        cst = single->certStatus;
        if (BIO_printf(bp, "    Cert Status: %s",
                       OCSP_cert_status_str(cst->type)) <= 0)
            goto err;
        if (cst->type == V_OCSP_CERTSTATUS_REVOKED) {
            rev = cst->value.revoked;
            if (BIO_printf(bp, "\n    Revocation Time: ") <= 0)
                goto err;
            if (!ASN1_GENERALIZEDTIME_print(bp, rev->revocationTime))
                goto err;
            if (rev->revocationReason) {
                l = ASN1_ENUMERATED_get(rev->revocationReason);
                if (BIO_printf(bp,
                               "\n    Revocation Reason: %s (0x%lx)",
                               OCSP_crl_reason_str(l), l) <= 0)
                    goto err;
            }
        }
        if (BIO_printf(bp, "\n    This Update: ") <= 0)
            goto err;
        if (!ASN1_GENERALIZEDTIME_print(bp, single->thisUpdate))
            goto err;
        if (single->nextUpdate) {
            if (BIO_printf(bp, "\n    Next Update: ") <= 0)
                goto err;
            if (!ASN1_GENERALIZEDTIME_print(bp, single->nextUpdate))
                goto err;
        }
        if (BIO_write(bp, "\n", 1) <= 0)
            goto err;
        if (!X509V3_extensions_print(bp,
                                     "Response Single Extensions",
                                     single->singleExtensions, flags, 8))
            goto err;
        if (BIO_write(bp, "\n", 1) <= 0)
            goto err;
    }
    if (!X509V3_extensions_print(bp, "Response Extensions",
                                 rd->responseExtensions, flags, 4))
        goto err;
    if (X509_signature_print(bp, &br->signatureAlgorithm, br->signature) <= 0)
        goto err;

    for (i = 0; i < sk_X509_num(br->certs); i++) {
        X509_print(bp, sk_X509_value(br->certs, i));
        PEM_write_bio_X509(bp, sk_X509_value(br->certs, i));
    }

    ret = 1;
 err:
    OCSP_BASICRESP_free(br);
    return ret;
}

