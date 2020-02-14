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
typedef  int /*<<< orphan*/  crypto_aead_aes256gcm_state ;

/* Variables and functions */
 int /*<<< orphan*/  ENOSYS ; 
 size_t crypto_aead_aes256gcm_ABYTES ; 
 size_t crypto_aead_aes256gcm_KEYBYTES ; 
 size_t crypto_aead_aes256gcm_MESSAGEBYTES_MAX ; 
 size_t crypto_aead_aes256gcm_NPUBBYTES ; 
 size_t crypto_aead_aes256gcm_NSECBYTES ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 

int
crypto_aead_aes256gcm_encrypt_detached(unsigned char *c,
                                       unsigned char *mac,
                                       unsigned long long *maclen_p,
                                       const unsigned char *m,
                                       unsigned long long mlen,
                                       const unsigned char *ad,
                                       unsigned long long adlen,
                                       const unsigned char *nsec,
                                       const unsigned char *npub,
                                       const unsigned char *k)
{
    errno = ENOSYS;
    return -1;
}

int
crypto_aead_aes256gcm_encrypt(unsigned char *c, unsigned long long *clen_p,
                              const unsigned char *m, unsigned long long mlen,
                              const unsigned char *ad, unsigned long long adlen,
                              const unsigned char *nsec, const unsigned char *npub,
                              const unsigned char *k)
{
    errno = ENOSYS;
    return -1;
}

int
crypto_aead_aes256gcm_decrypt_detached(unsigned char *m,
                                       unsigned char *nsec,
                                       const unsigned char *c,
                                       unsigned long long clen,
                                       const unsigned char *mac,
                                       const unsigned char *ad,
                                       unsigned long long adlen,
                                       const unsigned char *npub,
                                       const unsigned char *k)
{
    errno = ENOSYS;
    return -1;
}

int
crypto_aead_aes256gcm_decrypt(unsigned char *m, unsigned long long *mlen_p,
                              unsigned char *nsec, const unsigned char *c,
                              unsigned long long clen, const unsigned char *ad,
                              unsigned long long adlen, const unsigned char *npub,
                              const unsigned char *k)
{
    errno = ENOSYS;
    return -1;
}

int
crypto_aead_aes256gcm_beforenm(crypto_aead_aes256gcm_state *ctx_,
                               const unsigned char *k)
{
    errno = ENOSYS;
    return -1;
}

int
crypto_aead_aes256gcm_encrypt_detached_afternm(unsigned char *c,
                                               unsigned char *mac, unsigned long long *maclen_p,
                                               const unsigned char *m, unsigned long long mlen,
                                               const unsigned char *ad, unsigned long long adlen,
                                               const unsigned char *nsec,
                                               const unsigned char *npub,
                                               const crypto_aead_aes256gcm_state *ctx_)
{
    errno = ENOSYS;
    return -1;
}

int
crypto_aead_aes256gcm_encrypt_afternm(unsigned char *c, unsigned long long *clen_p,
                                      const unsigned char *m, unsigned long long mlen,
                                      const unsigned char *ad, unsigned long long adlen,
                                      const unsigned char *nsec, const unsigned char *npub,
                                      const crypto_aead_aes256gcm_state *ctx_)
{
    errno = ENOSYS;
    return -1;
}

int
crypto_aead_aes256gcm_decrypt_detached_afternm(unsigned char *m, unsigned char *nsec,
                                               const unsigned char *c, unsigned long long clen,
                                               const unsigned char *mac,
                                               const unsigned char *ad, unsigned long long adlen,
                                               const unsigned char *npub,
                                               const crypto_aead_aes256gcm_state *ctx_)
{
    errno = ENOSYS;
    return -1;
}

int
crypto_aead_aes256gcm_decrypt_afternm(unsigned char *m, unsigned long long *mlen_p,
                                      unsigned char *nsec,
                                      const unsigned char *c, unsigned long long clen,
                                      const unsigned char *ad, unsigned long long adlen,
                                      const unsigned char *npub,
                                      const crypto_aead_aes256gcm_state *ctx_)
{
    errno = ENOSYS;
    return -1;
}

int
crypto_aead_aes256gcm_is_available(void)
{
    return 0;
}

size_t
crypto_aead_aes256gcm_keybytes(void)
{
    return crypto_aead_aes256gcm_KEYBYTES;
}

size_t
crypto_aead_aes256gcm_nsecbytes(void)
{
    return crypto_aead_aes256gcm_NSECBYTES;
}

size_t
crypto_aead_aes256gcm_npubbytes(void)
{
    return crypto_aead_aes256gcm_NPUBBYTES;
}

size_t
crypto_aead_aes256gcm_abytes(void)
{
    return crypto_aead_aes256gcm_ABYTES;
}

size_t
crypto_aead_aes256gcm_statebytes(void)
{
    return (sizeof(crypto_aead_aes256gcm_state) + (size_t) 15U) & ~(size_t) 15U;
}

size_t
crypto_aead_aes256gcm_messagebytes_max(void)
{
    return crypto_aead_aes256gcm_MESSAGEBYTES_MAX;
}

void
crypto_aead_aes256gcm_keygen(unsigned char k[crypto_aead_aes256gcm_KEYBYTES])
{
    randombytes_buf(k, crypto_aead_aes256gcm_KEYBYTES);
}

