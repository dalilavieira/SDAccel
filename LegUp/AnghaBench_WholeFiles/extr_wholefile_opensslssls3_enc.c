#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_9__ ;
typedef  struct TYPE_28__   TYPE_7__ ;
typedef  struct TYPE_27__   TYPE_6__ ;
typedef  struct TYPE_26__   TYPE_5__ ;
typedef  struct TYPE_25__   TYPE_4__ ;
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  smd ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_29__ {unsigned char* master_key; unsigned int master_key_length; TYPE_2__* cipher; } ;
struct TYPE_24__ {unsigned char* key_block; size_t key_block_length; TYPE_6__* new_compression; int /*<<< orphan*/  const* new_hash; int /*<<< orphan*/  const* new_sym_enc; } ;
struct TYPE_25__ {unsigned char* server_random; unsigned char* client_random; unsigned char* read_mac_secret; unsigned char* write_mac_secret; int need_empty_fragments; int /*<<< orphan*/ * handshake_dgst; int /*<<< orphan*/ * handshake_buffer; TYPE_3__ tmp; } ;
struct TYPE_22__ {int /*<<< orphan*/  enc_write_state; } ;
struct TYPE_28__ {int options; TYPE_5__* ctx; TYPE_4__ s3; TYPE_9__* session; TYPE_1__ statem; int /*<<< orphan*/  rlayer; int /*<<< orphan*/ * compress; int /*<<< orphan*/  write_hash; int /*<<< orphan*/ * enc_write_ctx; int /*<<< orphan*/ * expand; int /*<<< orphan*/  read_hash; int /*<<< orphan*/ * enc_read_ctx; } ;
struct TYPE_27__ {int /*<<< orphan*/ * method; } ;
struct TYPE_26__ {int /*<<< orphan*/  const* md5; int /*<<< orphan*/  const* sha1; } ;
struct TYPE_23__ {scalar_t__ algorithm_enc; } ;
typedef  TYPE_6__ SSL_COMP ;
typedef  TYPE_7__ SSL ;
typedef  int /*<<< orphan*/  EVP_MD_CTX ;
typedef  int /*<<< orphan*/  const EVP_MD ;
typedef  int /*<<< orphan*/  EVP_CIPHER_CTX ;
typedef  int /*<<< orphan*/  const EVP_CIPHER ;
typedef  int /*<<< orphan*/  COMP_METHOD ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_CLOSE ; 
 int /*<<< orphan*/  BIO_free (int /*<<< orphan*/ *) ; 
 long BIO_get_mem_data (int /*<<< orphan*/ *,void**) ; 
 int /*<<< orphan*/ * BIO_new (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_s_mem () ; 
 int /*<<< orphan*/  BIO_set_close (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int BIO_write (int /*<<< orphan*/ *,void*,int) ; 
 int /*<<< orphan*/  COMP_CTX_free (int /*<<< orphan*/ *) ; 
 void* COMP_CTX_new (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ENC_WRITE_STATE_INVALID ; 
 int /*<<< orphan*/  ENC_WRITE_STATE_VALID ; 
 int /*<<< orphan*/  ERR_R_INTERNAL_ERROR ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 void* EVP_CIPHER_CTX_new () ; 
 int /*<<< orphan*/  EVP_CIPHER_CTX_reset (int /*<<< orphan*/ *) ; 
 int EVP_CIPHER_iv_length (int /*<<< orphan*/  const*) ; 
 int EVP_CIPHER_key_length (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  EVP_CTRL_SSL3_MASTER_SECRET ; 
 int /*<<< orphan*/  EVP_CipherInit_ex (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,unsigned char*,unsigned char*,int) ; 
 scalar_t__ EVP_DigestFinal_ex (int /*<<< orphan*/ *,unsigned char*,unsigned int*) ; 
 scalar_t__ EVP_DigestInit_ex (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 scalar_t__ EVP_DigestUpdate (int /*<<< orphan*/ *,...) ; 
 int EVP_MAX_MD_SIZE ; 
 int /*<<< orphan*/  EVP_MD_CTX_FLAG_NON_FIPS_ALLOW ; 
 int /*<<< orphan*/  EVP_MD_CTX_copy_ex (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ EVP_MD_CTX_ctrl (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,unsigned char*) ; 
 int /*<<< orphan*/  EVP_MD_CTX_free (int /*<<< orphan*/ *) ; 
 void* EVP_MD_CTX_new () ; 
 int /*<<< orphan*/  EVP_MD_CTX_set_flags (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int EVP_MD_CTX_size (int /*<<< orphan*/ *) ; 
 scalar_t__ EVP_MD_CTX_type (int /*<<< orphan*/ *) ; 
 int EVP_MD_size (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* EVP_md5 () ; 
 int /*<<< orphan*/  const* EVP_sha1 () ; 
 size_t INT_MAX ; 
 scalar_t__ MD5_DIGEST_LENGTH ; 
 scalar_t__ NID_md5_sha1 ; 
 int /*<<< orphan*/  OPENSSL_cleanse (unsigned char*,int) ; 
 int /*<<< orphan*/  OPENSSL_clear_free (unsigned char*,int) ; 
 unsigned char* OPENSSL_malloc (int) ; 
 int /*<<< orphan*/  RECORD_LAYER_reset_read_sequence (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RECORD_LAYER_reset_write_sequence (int /*<<< orphan*/ *) ; 
 int SHA_DIGEST_LENGTH ; 
 int SSL3_AD_BAD_CERTIFICATE ; 
 int SSL3_AD_BAD_RECORD_MAC ; 
 int SSL3_AD_CERTIFICATE_EXPIRED ; 
 int SSL3_AD_CERTIFICATE_REVOKED ; 
 int SSL3_AD_CERTIFICATE_UNKNOWN ; 
 int SSL3_AD_CLOSE_NOTIFY ; 
 int SSL3_AD_DECOMPRESSION_FAILURE ; 
 int SSL3_AD_HANDSHAKE_FAILURE ; 
 int SSL3_AD_ILLEGAL_PARAMETER ; 
 int SSL3_AD_NO_CERTIFICATE ; 
 int SSL3_AD_UNEXPECTED_MESSAGE ; 
 int SSL3_AD_UNSUPPORTED_CERTIFICATE ; 
 int SSL3_CC_READ ; 
 int SSL3_CC_WRITE ; 
 int SSL3_CHANGE_CIPHER_CLIENT_WRITE ; 
 int SSL3_CHANGE_CIPHER_SERVER_READ ; 
 unsigned int SSL3_RANDOM_SIZE ; 
#define  SSL_AD_ACCESS_DENIED 160 
#define  SSL_AD_BAD_CERTIFICATE 159 
#define  SSL_AD_BAD_CERTIFICATE_HASH_VALUE 158 
#define  SSL_AD_BAD_CERTIFICATE_STATUS_RESPONSE 157 
#define  SSL_AD_BAD_RECORD_MAC 156 
#define  SSL_AD_CERTIFICATE_EXPIRED 155 
#define  SSL_AD_CERTIFICATE_REQUIRED 154 
#define  SSL_AD_CERTIFICATE_REVOKED 153 
#define  SSL_AD_CERTIFICATE_UNKNOWN 152 
#define  SSL_AD_CERTIFICATE_UNOBTAINABLE 151 
#define  SSL_AD_CLOSE_NOTIFY 150 
#define  SSL_AD_DECODE_ERROR 149 
#define  SSL_AD_DECOMPRESSION_FAILURE 148 
#define  SSL_AD_DECRYPTION_FAILED 147 
#define  SSL_AD_DECRYPT_ERROR 146 
#define  SSL_AD_EXPORT_RESTRICTION 145 
#define  SSL_AD_HANDSHAKE_FAILURE 144 
#define  SSL_AD_ILLEGAL_PARAMETER 143 
#define  SSL_AD_INAPPROPRIATE_FALLBACK 142 
#define  SSL_AD_INSUFFICIENT_SECURITY 141 
#define  SSL_AD_INTERNAL_ERROR 140 
#define  SSL_AD_NO_APPLICATION_PROTOCOL 139 
#define  SSL_AD_NO_CERTIFICATE 138 
#define  SSL_AD_NO_RENEGOTIATION 137 
#define  SSL_AD_PROTOCOL_VERSION 136 
#define  SSL_AD_RECORD_OVERFLOW 135 
#define  SSL_AD_UNEXPECTED_MESSAGE 134 
#define  SSL_AD_UNKNOWN_CA 133 
#define  SSL_AD_UNKNOWN_PSK_IDENTITY 132 
#define  SSL_AD_UNRECOGNIZED_NAME 131 
#define  SSL_AD_UNSUPPORTED_CERTIFICATE 130 
#define  SSL_AD_UNSUPPORTED_EXTENSION 129 
#define  SSL_AD_USER_CANCELLED 128 
 int /*<<< orphan*/  SSL_F_SSL3_CHANGE_CIPHER_STATE ; 
 int /*<<< orphan*/  SSL_F_SSL3_DIGEST_CACHED_RECORDS ; 
 int /*<<< orphan*/  SSL_F_SSL3_FINAL_FINISH_MAC ; 
 int /*<<< orphan*/  SSL_F_SSL3_FINISH_MAC ; 
 int /*<<< orphan*/  SSL_F_SSL3_GENERATE_KEY_BLOCK ; 
 int /*<<< orphan*/  SSL_F_SSL3_GENERATE_MASTER_SECRET ; 
 int /*<<< orphan*/  SSL_F_SSL3_INIT_FINISHED_MAC ; 
 int /*<<< orphan*/  SSL_F_SSL3_SETUP_KEY_BLOCK ; 
 int SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS ; 
 scalar_t__ SSL_RC4 ; 
 int /*<<< orphan*/  SSL_R_BAD_HANDSHAKE_LENGTH ; 
 int /*<<< orphan*/  SSL_R_CIPHER_OR_HASH_UNAVAILABLE ; 
 int /*<<< orphan*/  SSL_R_COMPRESSION_LIBRARY_ERROR ; 
 int /*<<< orphan*/  SSL_R_NO_REQUIRED_DIGEST ; 
 int /*<<< orphan*/  SSL_R_OVERFLOW_ERROR ; 
 scalar_t__ SSL_eNULL ; 
 int /*<<< orphan*/  SSLfatal (TYPE_7__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int TLS1_AD_INAPPROPRIATE_FALLBACK ; 
 int TLS1_AD_NO_APPLICATION_PROTOCOL ; 
 int TLS1_AD_UNKNOWN_PSK_IDENTITY ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,size_t) ; 
 int /*<<< orphan*/  ossl_assert (int /*<<< orphan*/ ) ; 
 void ssl3_cleanup_key_block (TYPE_7__*) ; 
 void ssl3_free_digest_list (TYPE_7__*) ; 
 int /*<<< orphan*/  ssl_cipher_get_evp (TYPE_9__*,int /*<<< orphan*/  const**,int /*<<< orphan*/  const**,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_6__**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  const* ssl_handshake_md (TYPE_7__*) ; 
 int /*<<< orphan*/ * ssl_replace_hash (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 unsigned int strlen (char const*) ; 

__attribute__((used)) static int ssl3_generate_key_block(SSL *s, unsigned char *km, int num)
{
    EVP_MD_CTX *m5;
    EVP_MD_CTX *s1;
    unsigned char buf[16], smd[SHA_DIGEST_LENGTH];
    unsigned char c = 'A';
    unsigned int i, j, k;
    int ret = 0;

#ifdef CHARSET_EBCDIC
    c = os_toascii[c];          /* 'A' in ASCII */
#endif
    k = 0;
    m5 = EVP_MD_CTX_new();
    s1 = EVP_MD_CTX_new();
    if (m5 == NULL || s1 == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_GENERATE_KEY_BLOCK,
                 ERR_R_MALLOC_FAILURE);
        goto err;
    }
    EVP_MD_CTX_set_flags(m5, EVP_MD_CTX_FLAG_NON_FIPS_ALLOW);
    for (i = 0; (int)i < num; i += MD5_DIGEST_LENGTH) {
        k++;
        if (k > sizeof(buf)) {
            /* bug: 'buf' is too small for this ciphersuite */
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_GENERATE_KEY_BLOCK,
                     ERR_R_INTERNAL_ERROR);
            goto err;
        }

        for (j = 0; j < k; j++)
            buf[j] = c;
        c++;
        if (!EVP_DigestInit_ex(s1, EVP_sha1(), NULL)
            || !EVP_DigestUpdate(s1, buf, k)
            || !EVP_DigestUpdate(s1, s->session->master_key,
                                 s->session->master_key_length)
            || !EVP_DigestUpdate(s1, s->s3.server_random, SSL3_RANDOM_SIZE)
            || !EVP_DigestUpdate(s1, s->s3.client_random, SSL3_RANDOM_SIZE)
            || !EVP_DigestFinal_ex(s1, smd, NULL)
            || !EVP_DigestInit_ex(m5, EVP_md5(), NULL)
            || !EVP_DigestUpdate(m5, s->session->master_key,
                                 s->session->master_key_length)
            || !EVP_DigestUpdate(m5, smd, SHA_DIGEST_LENGTH)) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_GENERATE_KEY_BLOCK,
                     ERR_R_INTERNAL_ERROR);
            goto err;
        }
        if ((int)(i + MD5_DIGEST_LENGTH) > num) {
            if (!EVP_DigestFinal_ex(m5, smd, NULL)) {
                SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                         SSL_F_SSL3_GENERATE_KEY_BLOCK, ERR_R_INTERNAL_ERROR);
                goto err;
            }
            memcpy(km, smd, (num - i));
        } else {
            if (!EVP_DigestFinal_ex(m5, km, NULL)) {
                SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                         SSL_F_SSL3_GENERATE_KEY_BLOCK, ERR_R_INTERNAL_ERROR);
                goto err;
            }
        }

        km += MD5_DIGEST_LENGTH;
    }
    OPENSSL_cleanse(smd, sizeof(smd));
    ret = 1;
 err:
    EVP_MD_CTX_free(m5);
    EVP_MD_CTX_free(s1);
    return ret;
}

int ssl3_change_cipher_state(SSL *s, int which)
{
    unsigned char *p, *mac_secret;
    unsigned char *ms, *key, *iv;
    EVP_CIPHER_CTX *dd;
    const EVP_CIPHER *c;
#ifndef OPENSSL_NO_COMP
    COMP_METHOD *comp;
#endif
    const EVP_MD *m;
    int mdi;
    size_t n, i, j, k, cl;
    int reuse_dd = 0;

    c = s->s3.tmp.new_sym_enc;
    m = s->s3.tmp.new_hash;
    /* m == NULL will lead to a crash later */
    if (!ossl_assert(m != NULL)) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_CHANGE_CIPHER_STATE,
                 ERR_R_INTERNAL_ERROR);
        goto err;
    }
#ifndef OPENSSL_NO_COMP
    if (s->s3.tmp.new_compression == NULL)
        comp = NULL;
    else
        comp = s->s3.tmp.new_compression->method;
#endif

    if (which & SSL3_CC_READ) {
        if (s->enc_read_ctx != NULL) {
            reuse_dd = 1;
        } else if ((s->enc_read_ctx = EVP_CIPHER_CTX_new()) == NULL) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_CHANGE_CIPHER_STATE,
                     ERR_R_MALLOC_FAILURE);
            goto err;
        } else {
            /*
             * make sure it's initialised in case we exit later with an error
             */
            EVP_CIPHER_CTX_reset(s->enc_read_ctx);
        }
        dd = s->enc_read_ctx;

        if (ssl_replace_hash(&s->read_hash, m) == NULL) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_CHANGE_CIPHER_STATE,
                     ERR_R_INTERNAL_ERROR);
            goto err;
        }
#ifndef OPENSSL_NO_COMP
        /* COMPRESS */
        COMP_CTX_free(s->expand);
        s->expand = NULL;
        if (comp != NULL) {
            s->expand = COMP_CTX_new(comp);
            if (s->expand == NULL) {
                SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                         SSL_F_SSL3_CHANGE_CIPHER_STATE,
                         SSL_R_COMPRESSION_LIBRARY_ERROR);
                goto err;
            }
        }
#endif
        RECORD_LAYER_reset_read_sequence(&s->rlayer);
        mac_secret = &(s->s3.read_mac_secret[0]);
    } else {
        s->statem.enc_write_state = ENC_WRITE_STATE_INVALID;
        if (s->enc_write_ctx != NULL) {
            reuse_dd = 1;
        } else if ((s->enc_write_ctx = EVP_CIPHER_CTX_new()) == NULL) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_CHANGE_CIPHER_STATE,
                     ERR_R_MALLOC_FAILURE);
            goto err;
        } else {
            /*
             * make sure it's initialised in case we exit later with an error
             */
            EVP_CIPHER_CTX_reset(s->enc_write_ctx);
        }
        dd = s->enc_write_ctx;
        if (ssl_replace_hash(&s->write_hash, m) == NULL) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_CHANGE_CIPHER_STATE,
                     ERR_R_MALLOC_FAILURE);
            goto err;
        }
#ifndef OPENSSL_NO_COMP
        /* COMPRESS */
        COMP_CTX_free(s->compress);
        s->compress = NULL;
        if (comp != NULL) {
            s->compress = COMP_CTX_new(comp);
            if (s->compress == NULL) {
                SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                         SSL_F_SSL3_CHANGE_CIPHER_STATE,
                         SSL_R_COMPRESSION_LIBRARY_ERROR);
                goto err;
            }
        }
#endif
        RECORD_LAYER_reset_write_sequence(&s->rlayer);
        mac_secret = &(s->s3.write_mac_secret[0]);
    }

    if (reuse_dd)
        EVP_CIPHER_CTX_reset(dd);

    p = s->s3.tmp.key_block;
    mdi = EVP_MD_size(m);
    if (mdi < 0) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_CHANGE_CIPHER_STATE,
                 ERR_R_INTERNAL_ERROR);
        goto err;
    }
    i = mdi;
    cl = EVP_CIPHER_key_length(c);
    j = cl;
    k = EVP_CIPHER_iv_length(c);
    if ((which == SSL3_CHANGE_CIPHER_CLIENT_WRITE) ||
        (which == SSL3_CHANGE_CIPHER_SERVER_READ)) {
        ms = &(p[0]);
        n = i + i;
        key = &(p[n]);
        n += j + j;
        iv = &(p[n]);
        n += k + k;
    } else {
        n = i;
        ms = &(p[n]);
        n += i + j;
        key = &(p[n]);
        n += j + k;
        iv = &(p[n]);
        n += k;
    }

    if (n > s->s3.tmp.key_block_length) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_CHANGE_CIPHER_STATE,
                 ERR_R_INTERNAL_ERROR);
        goto err;
    }

    memcpy(mac_secret, ms, i);

    if (!EVP_CipherInit_ex(dd, c, NULL, key, iv, (which & SSL3_CC_WRITE))) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_CHANGE_CIPHER_STATE,
                 ERR_R_INTERNAL_ERROR);
        goto err;
    }

    s->statem.enc_write_state = ENC_WRITE_STATE_VALID;
    return 1;
 err:
    return 0;
}

int ssl3_setup_key_block(SSL *s)
{
    unsigned char *p;
    const EVP_CIPHER *c;
    const EVP_MD *hash;
    int num;
    int ret = 0;
    SSL_COMP *comp;

    if (s->s3.tmp.key_block_length != 0)
        return 1;

    if (!ssl_cipher_get_evp(s->session, &c, &hash, NULL, NULL, &comp, 0)) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_SETUP_KEY_BLOCK,
                 SSL_R_CIPHER_OR_HASH_UNAVAILABLE);
        return 0;
    }

    s->s3.tmp.new_sym_enc = c;
    s->s3.tmp.new_hash = hash;
#ifdef OPENSSL_NO_COMP
    s->s3.tmp.new_compression = NULL;
#else
    s->s3.tmp.new_compression = comp;
#endif

    num = EVP_MD_size(hash);
    if (num < 0)
        return 0;

    num = EVP_CIPHER_key_length(c) + num + EVP_CIPHER_iv_length(c);
    num *= 2;

    ssl3_cleanup_key_block(s);

    if ((p = OPENSSL_malloc(num)) == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_SETUP_KEY_BLOCK,
                 ERR_R_MALLOC_FAILURE);
        return 0;
    }

    s->s3.tmp.key_block_length = num;
    s->s3.tmp.key_block = p;

    /* Calls SSLfatal() as required */
    ret = ssl3_generate_key_block(s, p, num);

    if (!(s->options & SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS)) {
        /*
         * enable vulnerability countermeasure for CBC ciphers with known-IV
         * problem (http://www.openssl.org/~bodo/tls-cbc.txt)
         */
        s->s3.need_empty_fragments = 1;

        if (s->session->cipher != NULL) {
            if (s->session->cipher->algorithm_enc == SSL_eNULL)
                s->s3.need_empty_fragments = 0;

#ifndef OPENSSL_NO_RC4
            if (s->session->cipher->algorithm_enc == SSL_RC4)
                s->s3.need_empty_fragments = 0;
#endif
        }
    }

    return ret;
}

void ssl3_cleanup_key_block(SSL *s)
{
    OPENSSL_clear_free(s->s3.tmp.key_block, s->s3.tmp.key_block_length);
    s->s3.tmp.key_block = NULL;
    s->s3.tmp.key_block_length = 0;
}

int ssl3_init_finished_mac(SSL *s)
{
    BIO *buf = BIO_new(BIO_s_mem());

    if (buf == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_INIT_FINISHED_MAC,
                 ERR_R_MALLOC_FAILURE);
        return 0;
    }
    ssl3_free_digest_list(s);
    s->s3.handshake_buffer = buf;
    (void)BIO_set_close(s->s3.handshake_buffer, BIO_CLOSE);
    return 1;
}

void ssl3_free_digest_list(SSL *s)
{
    BIO_free(s->s3.handshake_buffer);
    s->s3.handshake_buffer = NULL;
    EVP_MD_CTX_free(s->s3.handshake_dgst);
    s->s3.handshake_dgst = NULL;
}

int ssl3_finish_mac(SSL *s, const unsigned char *buf, size_t len)
{
    int ret;

    if (s->s3.handshake_dgst == NULL) {
        /* Note: this writes to a memory BIO so a failure is a fatal error */
        if (len > INT_MAX) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_FINISH_MAC,
                     SSL_R_OVERFLOW_ERROR);
            return 0;
        }
        ret = BIO_write(s->s3.handshake_buffer, (void *)buf, (int)len);
        if (ret <= 0 || ret != (int)len) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_FINISH_MAC,
                     ERR_R_INTERNAL_ERROR);
            return 0;
        }
    } else {
        ret = EVP_DigestUpdate(s->s3.handshake_dgst, buf, len);
        if (!ret) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_FINISH_MAC,
                     ERR_R_INTERNAL_ERROR);
            return 0;
        }
    }
    return 1;
}

int ssl3_digest_cached_records(SSL *s, int keep)
{
    const EVP_MD *md;
    long hdatalen;
    void *hdata;

    if (s->s3.handshake_dgst == NULL) {
        hdatalen = BIO_get_mem_data(s->s3.handshake_buffer, &hdata);
        if (hdatalen <= 0) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_DIGEST_CACHED_RECORDS,
                     SSL_R_BAD_HANDSHAKE_LENGTH);
            return 0;
        }

        s->s3.handshake_dgst = EVP_MD_CTX_new();
        if (s->s3.handshake_dgst == NULL) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_DIGEST_CACHED_RECORDS,
                     ERR_R_MALLOC_FAILURE);
            return 0;
        }

        md = ssl_handshake_md(s);
        if (md == NULL || !EVP_DigestInit_ex(s->s3.handshake_dgst, md, NULL)
            || !EVP_DigestUpdate(s->s3.handshake_dgst, hdata, hdatalen)) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_DIGEST_CACHED_RECORDS,
                     ERR_R_INTERNAL_ERROR);
            return 0;
        }
    }
    if (keep == 0) {
        BIO_free(s->s3.handshake_buffer);
        s->s3.handshake_buffer = NULL;
    }

    return 1;
}

size_t ssl3_final_finish_mac(SSL *s, const char *sender, size_t len,
                             unsigned char *p)
{
    int ret;
    EVP_MD_CTX *ctx = NULL;

    if (!ssl3_digest_cached_records(s, 0)) {
        /* SSLfatal() already called */
        return 0;
    }

    if (EVP_MD_CTX_type(s->s3.handshake_dgst) != NID_md5_sha1) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_FINAL_FINISH_MAC,
                 SSL_R_NO_REQUIRED_DIGEST);
        return 0;
    }

    ctx = EVP_MD_CTX_new();
    if (ctx == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_FINAL_FINISH_MAC,
                 ERR_R_MALLOC_FAILURE);
        return 0;
    }
    if (!EVP_MD_CTX_copy_ex(ctx, s->s3.handshake_dgst)) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_FINAL_FINISH_MAC,
                 ERR_R_INTERNAL_ERROR);
        ret = 0;
        goto err;
    }

    ret = EVP_MD_CTX_size(ctx);
    if (ret < 0) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_FINAL_FINISH_MAC,
                 ERR_R_INTERNAL_ERROR);
        ret = 0;
        goto err;
    }

    if ((sender != NULL && EVP_DigestUpdate(ctx, sender, len) <= 0)
        || EVP_MD_CTX_ctrl(ctx, EVP_CTRL_SSL3_MASTER_SECRET,
                           (int)s->session->master_key_length,
                           s->session->master_key) <= 0
        || EVP_DigestFinal_ex(ctx, p, NULL) <= 0) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_FINAL_FINISH_MAC,
                 ERR_R_INTERNAL_ERROR);
        ret = 0;
    }

 err:
    EVP_MD_CTX_free(ctx);

    return ret;
}

int ssl3_generate_master_secret(SSL *s, unsigned char *out, unsigned char *p,
                                size_t len, size_t *secret_size)
{
    static const unsigned char *salt[3] = {
#ifndef CHARSET_EBCDIC
        (const unsigned char *)"A",
        (const unsigned char *)"BB",
        (const unsigned char *)"CCC",
#else
        (const unsigned char *)"\x41",
        (const unsigned char *)"\x42\x42",
        (const unsigned char *)"\x43\x43\x43",
#endif
    };
    unsigned char buf[EVP_MAX_MD_SIZE];
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    int i, ret = 1;
    unsigned int n;
    size_t ret_secret_size = 0;

    if (ctx == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR, SSL_F_SSL3_GENERATE_MASTER_SECRET,
                 ERR_R_MALLOC_FAILURE);
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (EVP_DigestInit_ex(ctx, s->ctx->sha1, NULL) <= 0
            || EVP_DigestUpdate(ctx, salt[i],
                                strlen((const char *)salt[i])) <= 0
            || EVP_DigestUpdate(ctx, p, len) <= 0
            || EVP_DigestUpdate(ctx, &(s->s3.client_random[0]),
                                SSL3_RANDOM_SIZE) <= 0
            || EVP_DigestUpdate(ctx, &(s->s3.server_random[0]),
                                SSL3_RANDOM_SIZE) <= 0
               /* TODO(size_t) : convert me */
            || EVP_DigestFinal_ex(ctx, buf, &n) <= 0
            || EVP_DigestInit_ex(ctx, s->ctx->md5, NULL) <= 0
            || EVP_DigestUpdate(ctx, p, len) <= 0
            || EVP_DigestUpdate(ctx, buf, n) <= 0
            || EVP_DigestFinal_ex(ctx, out, &n) <= 0) {
            SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                     SSL_F_SSL3_GENERATE_MASTER_SECRET, ERR_R_INTERNAL_ERROR);
            ret = 0;
            break;
        }
        out += n;
        ret_secret_size += n;
    }
    EVP_MD_CTX_free(ctx);

    OPENSSL_cleanse(buf, sizeof(buf));
    if (ret)
        *secret_size = ret_secret_size;
    return ret;
}

int ssl3_alert_code(int code)
{
    switch (code) {
    case SSL_AD_CLOSE_NOTIFY:
        return SSL3_AD_CLOSE_NOTIFY;
    case SSL_AD_UNEXPECTED_MESSAGE:
        return SSL3_AD_UNEXPECTED_MESSAGE;
    case SSL_AD_BAD_RECORD_MAC:
        return SSL3_AD_BAD_RECORD_MAC;
    case SSL_AD_DECRYPTION_FAILED:
        return SSL3_AD_BAD_RECORD_MAC;
    case SSL_AD_RECORD_OVERFLOW:
        return SSL3_AD_BAD_RECORD_MAC;
    case SSL_AD_DECOMPRESSION_FAILURE:
        return SSL3_AD_DECOMPRESSION_FAILURE;
    case SSL_AD_HANDSHAKE_FAILURE:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_NO_CERTIFICATE:
        return SSL3_AD_NO_CERTIFICATE;
    case SSL_AD_BAD_CERTIFICATE:
        return SSL3_AD_BAD_CERTIFICATE;
    case SSL_AD_UNSUPPORTED_CERTIFICATE:
        return SSL3_AD_UNSUPPORTED_CERTIFICATE;
    case SSL_AD_CERTIFICATE_REVOKED:
        return SSL3_AD_CERTIFICATE_REVOKED;
    case SSL_AD_CERTIFICATE_EXPIRED:
        return SSL3_AD_CERTIFICATE_EXPIRED;
    case SSL_AD_CERTIFICATE_UNKNOWN:
        return SSL3_AD_CERTIFICATE_UNKNOWN;
    case SSL_AD_ILLEGAL_PARAMETER:
        return SSL3_AD_ILLEGAL_PARAMETER;
    case SSL_AD_UNKNOWN_CA:
        return SSL3_AD_BAD_CERTIFICATE;
    case SSL_AD_ACCESS_DENIED:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_DECODE_ERROR:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_DECRYPT_ERROR:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_EXPORT_RESTRICTION:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_PROTOCOL_VERSION:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_INSUFFICIENT_SECURITY:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_INTERNAL_ERROR:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_USER_CANCELLED:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_NO_RENEGOTIATION:
        return -1;            /* Don't send it :-) */
    case SSL_AD_UNSUPPORTED_EXTENSION:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_CERTIFICATE_UNOBTAINABLE:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_UNRECOGNIZED_NAME:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_BAD_CERTIFICATE_STATUS_RESPONSE:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_BAD_CERTIFICATE_HASH_VALUE:
        return SSL3_AD_HANDSHAKE_FAILURE;
    case SSL_AD_UNKNOWN_PSK_IDENTITY:
        return TLS1_AD_UNKNOWN_PSK_IDENTITY;
    case SSL_AD_INAPPROPRIATE_FALLBACK:
        return TLS1_AD_INAPPROPRIATE_FALLBACK;
    case SSL_AD_NO_APPLICATION_PROTOCOL:
        return TLS1_AD_NO_APPLICATION_PROTOCOL;
    case SSL_AD_CERTIFICATE_REQUIRED:
        return SSL_AD_HANDSHAKE_FAILURE;
    default:
        return -1;
    }
}

