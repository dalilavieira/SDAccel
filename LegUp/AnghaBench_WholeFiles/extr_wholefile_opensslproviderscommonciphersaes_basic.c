#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_31__   TYPE_3__ ;
typedef  struct TYPE_30__   TYPE_2__ ;
typedef  struct TYPE_29__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  (* cbc128_f ) (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,scalar_t__) ;
typedef  void* block128_f ;
struct TYPE_30__ {int /*<<< orphan*/  ks; } ;
struct TYPE_29__ {int /*<<< orphan*/  ctr; int /*<<< orphan*/  (* cbc ) (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,scalar_t__) ;} ;
struct TYPE_31__ {scalar_t__ mode; int num; int flags; int /*<<< orphan*/  (* block ) (unsigned char const*,unsigned char*,TYPE_2__*) ;int /*<<< orphan*/  buf; int /*<<< orphan*/  iv; TYPE_2__ ks; TYPE_1__ stream; scalar_t__ enc; } ;
typedef  TYPE_3__ PROV_AES_KEY ;

/* Variables and functions */
 size_t AES_BLOCK_SIZE ; 
 scalar_t__ AES_cbc_encrypt ; 
 scalar_t__ AES_decrypt ; 
 scalar_t__ AES_encrypt ; 
 int AES_set_decrypt_key (unsigned char const*,size_t,int /*<<< orphan*/ *) ; 
 int AES_set_encrypt_key (unsigned char const*,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CRYPTO_cbc128_decrypt (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (unsigned char const*,unsigned char*,TYPE_2__*)) ; 
 int /*<<< orphan*/  CRYPTO_cbc128_encrypt (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (unsigned char const*,unsigned char*,TYPE_2__*)) ; 
 int /*<<< orphan*/  CRYPTO_cfb128_1_encrypt (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,int*,scalar_t__,int /*<<< orphan*/  (*) (unsigned char const*,unsigned char*,TYPE_2__*)) ; 
 int /*<<< orphan*/  CRYPTO_cfb128_8_encrypt (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,int*,scalar_t__,int /*<<< orphan*/  (*) (unsigned char const*,unsigned char*,TYPE_2__*)) ; 
 int /*<<< orphan*/  CRYPTO_cfb128_encrypt (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,int*,scalar_t__,int /*<<< orphan*/  (*) (unsigned char const*,unsigned char*,TYPE_2__*)) ; 
 int /*<<< orphan*/  CRYPTO_ctr128_encrypt (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*,int /*<<< orphan*/  (*) (unsigned char const*,unsigned char*,TYPE_2__*)) ; 
 int /*<<< orphan*/  CRYPTO_ctr128_encrypt_ctr32 (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRYPTO_ofb128_encrypt (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,int*,int /*<<< orphan*/  (*) (unsigned char const*,unsigned char*,TYPE_2__*)) ; 
 scalar_t__ EVP_CIPH_CBC_MODE ; 
 scalar_t__ EVP_CIPH_ECB_MODE ; 
 int EVP_CIPH_FLAG_LENGTH_BITS ; 
 size_t MAXBITCHUNK ; 
 int /*<<< orphan*/  PROV_F_AES_INIT_KEY ; 
 int /*<<< orphan*/  PROV_R_AES_KEY_SETUP_FAILED ; 
 int /*<<< orphan*/  PROVerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (unsigned char const*,unsigned char*,size_t,TYPE_2__*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  stub2 (unsigned char const*,unsigned char*,TYPE_2__*) ; 

__attribute__((used)) static int aes_init_key(PROV_AES_KEY *dat, const unsigned char *key,
                        size_t keylen)
{
    int ret;

    if ((dat->mode == EVP_CIPH_ECB_MODE || dat->mode == EVP_CIPH_CBC_MODE)
        && !dat->enc) {
#ifdef HWAES_CAPABLE
        if (HWAES_CAPABLE) {
            ret = HWAES_set_decrypt_key(key, keylen * 8, &dat->ks.ks);
            dat->block = (block128_f)HWAES_decrypt;
            dat->stream.cbc = NULL;
# ifdef HWAES_cbc_encrypt
            if (dat->mode == EVP_CIPH_CBC_MODE)
                dat->stream.cbc = (cbc128_f)HWAES_cbc_encrypt;
# endif
        } else
#endif
#ifdef BSAES_CAPABLE
        if (BSAES_CAPABLE && dat->mode == EVP_CIPH_CBC_MODE) {
            ret = AES_set_decrypt_key(key, keylen * 8, &dat->ks.ks);
            dat->block = (block128_f)AES_decrypt;
            dat->stream.cbc = (cbc128_f)bsaes_cbc_encrypt;
        } else
#endif
#ifdef VPAES_CAPABLE
        if (VPAES_CAPABLE) {
            ret = vpaes_set_decrypt_key(key, keylen * 8, &dat->ks.ks);
            dat->block = (block128_f)vpaes_decrypt;
            dat->stream.cbc = (dat->mode == EVP_CIPH_CBC_MODE)
                              ?(cbc128_f)vpaes_cbc_encrypt : NULL;
        } else
#endif
        {
            ret = AES_set_decrypt_key(key, keylen * 8, &dat->ks.ks);
            dat->block = (block128_f)AES_decrypt;
            dat->stream.cbc = (dat->mode == EVP_CIPH_CBC_MODE)
                              ? (cbc128_f)AES_cbc_encrypt : NULL;
        }
    } else
#ifdef HWAES_CAPABLE
    if (HWAES_CAPABLE) {
        ret = HWAES_set_encrypt_key(key, keylen * 8, &dat->ks.ks);
        dat->block = (block128_f)HWAES_encrypt;
        dat->stream.cbc = NULL;
# ifdef HWAES_cbc_encrypt
        if (dat->mode == EVP_CIPH_CBC_MODE)
            dat->stream.cbc = (cbc128_f)HWAES_cbc_encrypt;
        else
# endif
# ifdef HWAES_ctr32_encrypt_blocks
        if (dat->mode == EVP_CIPH_CTR_MODE)
            dat->stream.ctr = (ctr128_f)HWAES_ctr32_encrypt_blocks;
        else
# endif
            (void)0;            /* terminate potentially open 'else' */
    } else
#endif
#ifdef BSAES_CAPABLE
    if (BSAES_CAPABLE && dat->mode == EVP_CIPH_CTR_MODE) {
        ret = AES_set_encrypt_key(key, keylen * 8, &dat->ks.ks);
        dat->block = (block128_f)AES_encrypt;
        dat->stream.ctr = (ctr128_f)bsaes_ctr32_encrypt_blocks;
    } else
#endif
#ifdef VPAES_CAPABLE
    if (VPAES_CAPABLE) {
        ret = vpaes_set_encrypt_key(key, keylen * 8, &dat->ks.ks);
        dat->block = (block128_f)vpaes_encrypt;
        dat->stream.cbc = (dat->mode == EVP_CIPH_CBC_MODE)
                          ? (cbc128_f)vpaes_cbc_encrypt : NULL;
    } else
#endif
    {
        ret = AES_set_encrypt_key(key, keylen * 8, &dat->ks.ks);
        dat->block = (block128_f)AES_encrypt;
        dat->stream.cbc = (dat->mode == EVP_CIPH_CBC_MODE)
                          ? (cbc128_f)AES_cbc_encrypt : NULL;
#ifdef AES_CTR_ASM
        if (dat->mode == EVP_CIPH_CTR_MODE)
            dat->stream.ctr = (ctr128_f)AES_ctr32_encrypt;
#endif
    }

    if (ret < 0) {
        PROVerr(PROV_F_AES_INIT_KEY, PROV_R_AES_KEY_SETUP_FAILED);
        return 0;
    }

    return 1;
}

__attribute__((used)) static int aes_cbc_cipher(PROV_AES_KEY *dat, unsigned char *out,
                          const unsigned char *in, size_t len)
{
    if (dat->stream.cbc)
        (*dat->stream.cbc) (in, out, len, &dat->ks, dat->iv, dat->enc);
    else if (dat->enc)
        CRYPTO_cbc128_encrypt(in, out, len, &dat->ks, dat->iv, dat->block);
    else
        CRYPTO_cbc128_decrypt(in, out, len, &dat->ks, dat->iv, dat->block);

    return 1;
}

__attribute__((used)) static int aes_ecb_cipher(PROV_AES_KEY *dat, unsigned char *out,
                          const unsigned char *in, size_t len)
{
    size_t i;

    if (len < AES_BLOCK_SIZE)
        return 1;

    for (i = 0, len -= AES_BLOCK_SIZE; i <= len; i += AES_BLOCK_SIZE)
        (*dat->block) (in + i, out + i, &dat->ks);

    return 1;
}

__attribute__((used)) static int aes_ofb_cipher(PROV_AES_KEY *dat, unsigned char *out,
                          const unsigned char *in, size_t len)
{
    int num = dat->num;
    CRYPTO_ofb128_encrypt(in, out, len, &dat->ks, dat->iv, &num, dat->block);
    dat->num = num;

    return 1;
}

__attribute__((used)) static int aes_cfb_cipher(PROV_AES_KEY *dat, unsigned char *out,
                          const unsigned char *in, size_t len)
{
    int num = dat->num;
    CRYPTO_cfb128_encrypt(in, out, len, &dat->ks, dat->iv, &num, dat->enc,
                          dat->block);
    dat->num = num;

    return 1;
}

__attribute__((used)) static int aes_cfb8_cipher(PROV_AES_KEY *dat, unsigned char *out,
                           const unsigned char *in, size_t len)
{
    int num = dat->num;
    CRYPTO_cfb128_8_encrypt(in, out, len, &dat->ks, dat->iv, &num, dat->enc,
                            dat->block);
    dat->num = num;

    return 1;
}

__attribute__((used)) static int aes_cfb1_cipher(PROV_AES_KEY *dat, unsigned char *out,
                           const unsigned char *in, size_t len)
{
    int num = dat->num;

    if ((dat->flags & EVP_CIPH_FLAG_LENGTH_BITS) != 0) {
        CRYPTO_cfb128_1_encrypt(in, out, len, &dat->ks, dat->iv, &num,
                                dat->enc, dat->block);
        dat->num = num;
        return 1;
    }

    while (len >= MAXBITCHUNK) {
        CRYPTO_cfb128_1_encrypt(in, out, MAXBITCHUNK * 8, &dat->ks,
                                dat->iv, &num, dat->enc, dat->block);
        len -= MAXBITCHUNK;
        out += MAXBITCHUNK;
        in  += MAXBITCHUNK;
    }
    if (len)
        CRYPTO_cfb128_1_encrypt(in, out, len * 8, &dat->ks, dat->iv, &num,
                                dat->enc, dat->block);

    dat->num = num;

    return 1;
}

__attribute__((used)) static int aes_ctr_cipher(PROV_AES_KEY *dat, unsigned char *out,
                          const unsigned char *in, size_t len)
{
    unsigned int num = dat->num;

    if (dat->stream.ctr)
        CRYPTO_ctr128_encrypt_ctr32(in, out, len, &dat->ks, dat->iv, dat->buf,
                                    &num, dat->stream.ctr);
    else
        CRYPTO_ctr128_encrypt(in, out, len, &dat->ks, dat->iv, dat->buf,
                              &num, dat->block);
    dat->num = num;

    return 1;
}

