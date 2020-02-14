#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  hmac_key ;
struct TYPE_3__ {size_t payload_length; int /*<<< orphan*/  md; int /*<<< orphan*/  head; int /*<<< orphan*/  tail; int /*<<< orphan*/  ks; } ;
typedef  TYPE_1__ EVP_RC4_HMAC_MD5 ;
typedef  int /*<<< orphan*/  EVP_CIPHER_CTX ;
typedef  int /*<<< orphan*/  EVP_CIPHER ;

/* Variables and functions */
 scalar_t__ CRYPTO_memcmp (unsigned char*,unsigned char*,size_t) ; 
 int EVP_AEAD_TLS1_AAD_LEN ; 
 scalar_t__ EVP_CIPHER_CTX_encrypting (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_CIPHER_CTX_key_length (int /*<<< orphan*/ *) ; 
#define  EVP_CTRL_AEAD_SET_MAC_KEY 129 
#define  EVP_CTRL_AEAD_TLS1_AAD 128 
 size_t MD5_DIGEST_LENGTH ; 
 int /*<<< orphan*/  MD5_Final (unsigned char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MD5_Init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MD5_Update (int /*<<< orphan*/ *,unsigned char const*,int) ; 
 size_t NO_PAYLOAD_LENGTH ; 
 int /*<<< orphan*/  OPENSSL_cleanse (unsigned char*,int) ; 
 int /*<<< orphan*/  RC4 (int /*<<< orphan*/ *,int,unsigned char const*,unsigned char*) ; 
 int /*<<< orphan*/  RC4_set_key (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned char const*) ; 
 TYPE_1__* data (int /*<<< orphan*/ *) ; 
 size_t md5_off ; 
 int /*<<< orphan*/  memcpy (unsigned char*,void*,int) ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  const r4_hmac_md5_cipher ; 
 int rc4_off ; 

__attribute__((used)) static int rc4_hmac_md5_init_key(EVP_CIPHER_CTX *ctx,
                                 const unsigned char *inkey,
                                 const unsigned char *iv, int enc)
{
    EVP_RC4_HMAC_MD5 *key = data(ctx);

    RC4_set_key(&key->ks, EVP_CIPHER_CTX_key_length(ctx), inkey);

    MD5_Init(&key->head);       /* handy when benchmarking */
    key->tail = key->head;
    key->md = key->head;

    key->payload_length = NO_PAYLOAD_LENGTH;

    return 1;
}

__attribute__((used)) static int rc4_hmac_md5_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
                               const unsigned char *in, size_t len)
{
    EVP_RC4_HMAC_MD5 *key = data(ctx);
# if defined(STITCHED_CALL)
    size_t rc4_off = 32 - 1 - (key->ks.x & (32 - 1)), /* 32 is $MOD from
                                                       * rc4_md5-x86_64.pl */
        md5_off = MD5_CBLOCK - key->md.num, blocks;
    unsigned int l;
    extern unsigned int OPENSSL_ia32cap_P[];
# endif
    size_t plen = key->payload_length;

    if (plen != NO_PAYLOAD_LENGTH && len != (plen + MD5_DIGEST_LENGTH))
        return 0;

    if (EVP_CIPHER_CTX_encrypting(ctx)) {
        if (plen == NO_PAYLOAD_LENGTH)
            plen = len;
# if defined(STITCHED_CALL)
        /* cipher has to "fall behind" */
        if (rc4_off > md5_off)
            md5_off += MD5_CBLOCK;

        if (plen > md5_off && (blocks = (plen - md5_off) / MD5_CBLOCK) &&
            (OPENSSL_ia32cap_P[0] & (1 << 20)) == 0) {
            MD5_Update(&key->md, in, md5_off);
            RC4(&key->ks, rc4_off, in, out);

            rc4_md5_enc(&key->ks, in + rc4_off, out + rc4_off,
                        &key->md, in + md5_off, blocks);
            blocks *= MD5_CBLOCK;
            rc4_off += blocks;
            md5_off += blocks;
            key->md.Nh += blocks >> 29;
            key->md.Nl += blocks <<= 3;
            if (key->md.Nl < (unsigned int)blocks)
                key->md.Nh++;
        } else {
            rc4_off = 0;
            md5_off = 0;
        }
# endif
        MD5_Update(&key->md, in + md5_off, plen - md5_off);

        if (plen != len) {      /* "TLS" mode of operation */
            if (in != out)
                memcpy(out + rc4_off, in + rc4_off, plen - rc4_off);

            /* calculate HMAC and append it to payload */
            MD5_Final(out + plen, &key->md);
            key->md = key->tail;
            MD5_Update(&key->md, out + plen, MD5_DIGEST_LENGTH);
            MD5_Final(out + plen, &key->md);
            /* encrypt HMAC at once */
            RC4(&key->ks, len - rc4_off, out + rc4_off, out + rc4_off);
        } else {
            RC4(&key->ks, len - rc4_off, in + rc4_off, out + rc4_off);
        }
    } else {
        unsigned char mac[MD5_DIGEST_LENGTH];
# if defined(STITCHED_CALL)
        /* digest has to "fall behind" */
        if (md5_off > rc4_off)
            rc4_off += 2 * MD5_CBLOCK;
        else
            rc4_off += MD5_CBLOCK;

        if (len > rc4_off && (blocks = (len - rc4_off) / MD5_CBLOCK) &&
            (OPENSSL_ia32cap_P[0] & (1 << 20)) == 0) {
            RC4(&key->ks, rc4_off, in, out);
            MD5_Update(&key->md, out, md5_off);

            rc4_md5_enc(&key->ks, in + rc4_off, out + rc4_off,
                        &key->md, out + md5_off, blocks);
            blocks *= MD5_CBLOCK;
            rc4_off += blocks;
            md5_off += blocks;
            l = (key->md.Nl + (blocks << 3)) & 0xffffffffU;
            if (l < key->md.Nl)
                key->md.Nh++;
            key->md.Nl = l;
            key->md.Nh += blocks >> 29;
        } else {
            md5_off = 0;
            rc4_off = 0;
        }
# endif
        /* decrypt HMAC at once */
        RC4(&key->ks, len - rc4_off, in + rc4_off, out + rc4_off);
        if (plen != NO_PAYLOAD_LENGTH) { /* "TLS" mode of operation */
            MD5_Update(&key->md, out + md5_off, plen - md5_off);

            /* calculate HMAC and verify it */
            MD5_Final(mac, &key->md);
            key->md = key->tail;
            MD5_Update(&key->md, mac, MD5_DIGEST_LENGTH);
            MD5_Final(mac, &key->md);

            if (CRYPTO_memcmp(out + plen, mac, MD5_DIGEST_LENGTH))
                return 0;
        } else {
            MD5_Update(&key->md, out + md5_off, len - md5_off);
        }
    }

    key->payload_length = NO_PAYLOAD_LENGTH;

    return 1;
}

__attribute__((used)) static int rc4_hmac_md5_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg,
                             void *ptr)
{
    EVP_RC4_HMAC_MD5 *key = data(ctx);

    switch (type) {
    case EVP_CTRL_AEAD_SET_MAC_KEY:
        {
            unsigned int i;
            unsigned char hmac_key[64];

            memset(hmac_key, 0, sizeof(hmac_key));

            if (arg > (int)sizeof(hmac_key)) {
                MD5_Init(&key->head);
                MD5_Update(&key->head, ptr, arg);
                MD5_Final(hmac_key, &key->head);
            } else {
                memcpy(hmac_key, ptr, arg);
            }

            for (i = 0; i < sizeof(hmac_key); i++)
                hmac_key[i] ^= 0x36; /* ipad */
            MD5_Init(&key->head);
            MD5_Update(&key->head, hmac_key, sizeof(hmac_key));

            for (i = 0; i < sizeof(hmac_key); i++)
                hmac_key[i] ^= 0x36 ^ 0x5c; /* opad */
            MD5_Init(&key->tail);
            MD5_Update(&key->tail, hmac_key, sizeof(hmac_key));

            OPENSSL_cleanse(hmac_key, sizeof(hmac_key));

            return 1;
        }
    case EVP_CTRL_AEAD_TLS1_AAD:
        {
            unsigned char *p = ptr;
            unsigned int len;

            if (arg != EVP_AEAD_TLS1_AAD_LEN)
                return -1;

            len = p[arg - 2] << 8 | p[arg - 1];

            if (!EVP_CIPHER_CTX_encrypting(ctx)) {
                if (len < MD5_DIGEST_LENGTH)
                    return -1;
                len -= MD5_DIGEST_LENGTH;
                p[arg - 2] = len >> 8;
                p[arg - 1] = len;
            }
            key->payload_length = len;
            key->md = key->head;
            MD5_Update(&key->md, p, arg);

            return MD5_DIGEST_LENGTH;
        }
    default:
        return -1;
    }
}

const EVP_CIPHER *EVP_rc4_hmac_md5(void)
{
    return &r4_hmac_md5_cipher;
}

