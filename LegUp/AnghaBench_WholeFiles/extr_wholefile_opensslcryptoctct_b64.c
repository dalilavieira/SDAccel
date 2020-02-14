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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  ct_log_entry_type_t ;
typedef  int /*<<< orphan*/  SCT ;
typedef  int /*<<< orphan*/  EVP_PKEY ;
typedef  int /*<<< orphan*/  CTLOG ;

/* Variables and functions */
 int /*<<< orphan*/ * CTLOG_new (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  CT_F_CTLOG_NEW_FROM_BASE64 ; 
 int /*<<< orphan*/  CT_F_CT_BASE64_DECODE ; 
 int /*<<< orphan*/  CT_F_SCT_NEW_FROM_BASE64 ; 
 int /*<<< orphan*/  CT_R_BASE64_DECODE_ERROR ; 
 int /*<<< orphan*/  CT_R_LOG_CONF_INVALID_KEY ; 
 int /*<<< orphan*/  CT_R_SCT_UNSUPPORTED_VERSION ; 
 int /*<<< orphan*/  CTerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  ERR_R_PASSED_INVALID_ARGUMENT ; 
 int EVP_DecodeBlock (unsigned char*,unsigned char*,size_t) ; 
 int /*<<< orphan*/  EVP_PKEY_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OPENSSL_free (unsigned char*) ; 
 unsigned char* OPENSSL_malloc (int) ; 
 int /*<<< orphan*/  SCT_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * SCT_new () ; 
 int /*<<< orphan*/  SCT_set0_extensions (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int /*<<< orphan*/  SCT_set0_log_id (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int /*<<< orphan*/  SCT_set_log_entry_type (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SCT_set_timestamp (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SCT_set_version (int /*<<< orphan*/ *,unsigned char) ; 
 int /*<<< orphan*/  X509_R_BASE64_DECODE_ERROR ; 
 int /*<<< orphan*/ * d2i_PUBKEY (int /*<<< orphan*/ *,unsigned char const**,int) ; 
 scalar_t__ o2i_SCT_signature (int /*<<< orphan*/ *,unsigned char const**,int) ; 
 size_t strlen (char const*) ; 

__attribute__((used)) static int ct_base64_decode(const char *in, unsigned char **out)
{
    size_t inlen = strlen(in);
    int outlen, i;
    unsigned char *outbuf = NULL;

    if (inlen == 0) {
        *out = NULL;
        return 0;
    }

    outlen = (inlen / 4) * 3;
    outbuf = OPENSSL_malloc(outlen);
    if (outbuf == NULL) {
        CTerr(CT_F_CT_BASE64_DECODE, ERR_R_MALLOC_FAILURE);
        goto err;
    }

    outlen = EVP_DecodeBlock(outbuf, (unsigned char *)in, inlen);
    if (outlen < 0) {
        CTerr(CT_F_CT_BASE64_DECODE, CT_R_BASE64_DECODE_ERROR);
        goto err;
    }

    /* Subtract padding bytes from |outlen|.  Any more than 2 is malformed. */
    i = 0;
    while (in[--inlen] == '=') {
        --outlen;
        if (++i > 2)
            goto err;
    }

    *out = outbuf;
    return outlen;
err:
    OPENSSL_free(outbuf);
    return -1;
}

SCT *SCT_new_from_base64(unsigned char version, const char *logid_base64,
                         ct_log_entry_type_t entry_type, uint64_t timestamp,
                         const char *extensions_base64,
                         const char *signature_base64)
{
    SCT *sct = SCT_new();
    unsigned char *dec = NULL;
    const unsigned char* p = NULL;
    int declen;

    if (sct == NULL) {
        CTerr(CT_F_SCT_NEW_FROM_BASE64, ERR_R_MALLOC_FAILURE);
        return NULL;
    }

    /*
     * RFC6962 section 4.1 says we "MUST NOT expect this to be 0", but we
     * can only construct SCT versions that have been defined.
     */
    if (!SCT_set_version(sct, version)) {
        CTerr(CT_F_SCT_NEW_FROM_BASE64, CT_R_SCT_UNSUPPORTED_VERSION);
        goto err;
    }

    declen = ct_base64_decode(logid_base64, &dec);
    if (declen < 0) {
        CTerr(CT_F_SCT_NEW_FROM_BASE64, X509_R_BASE64_DECODE_ERROR);
        goto err;
    }
    if (!SCT_set0_log_id(sct, dec, declen))
        goto err;
    dec = NULL;

    declen = ct_base64_decode(extensions_base64, &dec);
    if (declen < 0) {
        CTerr(CT_F_SCT_NEW_FROM_BASE64, X509_R_BASE64_DECODE_ERROR);
        goto err;
    }
    SCT_set0_extensions(sct, dec, declen);
    dec = NULL;

    declen = ct_base64_decode(signature_base64, &dec);
    if (declen < 0) {
        CTerr(CT_F_SCT_NEW_FROM_BASE64, X509_R_BASE64_DECODE_ERROR);
        goto err;
    }

    p = dec;
    if (o2i_SCT_signature(sct, &p, declen) <= 0)
        goto err;
    OPENSSL_free(dec);
    dec = NULL;

    SCT_set_timestamp(sct, timestamp);

    if (!SCT_set_log_entry_type(sct, entry_type))
        goto err;

    return sct;

 err:
    OPENSSL_free(dec);
    SCT_free(sct);
    return NULL;
}

int CTLOG_new_from_base64(CTLOG **ct_log, const char *pkey_base64, const char *name)
{
    unsigned char *pkey_der = NULL;
    int pkey_der_len;
    const unsigned char *p;
    EVP_PKEY *pkey = NULL;

    if (ct_log == NULL) {
        CTerr(CT_F_CTLOG_NEW_FROM_BASE64, ERR_R_PASSED_INVALID_ARGUMENT);
        return 0;
    }

    pkey_der_len = ct_base64_decode(pkey_base64, &pkey_der);
    if (pkey_der_len < 0) {
        CTerr(CT_F_CTLOG_NEW_FROM_BASE64, CT_R_LOG_CONF_INVALID_KEY);
        return 0;
    }

    p = pkey_der;
    pkey = d2i_PUBKEY(NULL, &p, pkey_der_len);
    OPENSSL_free(pkey_der);
    if (pkey == NULL) {
        CTerr(CT_F_CTLOG_NEW_FROM_BASE64, CT_R_LOG_CONF_INVALID_KEY);
        return 0;
    }

    *ct_log = CTLOG_new(pkey, name);
    if (*ct_log == NULL) {
        EVP_PKEY_free(pkey);
        return 0;
    }

    return 1;
}

