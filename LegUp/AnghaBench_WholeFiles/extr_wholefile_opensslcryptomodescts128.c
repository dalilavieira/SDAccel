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
typedef  int /*<<< orphan*/  tmp ;
typedef  int /*<<< orphan*/  (* cbc128_f ) (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ;
typedef  int /*<<< orphan*/  (* block128_f ) (unsigned char const*,unsigned char*,void const*) ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_cbc128_decrypt (unsigned char const*,unsigned char*,size_t,void const*,unsigned char*,int /*<<< orphan*/  (*) (unsigned char const*,unsigned char*,void const*)) ; 
 int /*<<< orphan*/  CRYPTO_cbc128_encrypt (unsigned char const*,unsigned char*,size_t,void const*,unsigned char*,int /*<<< orphan*/  (*) (unsigned char const*,unsigned char*,void const*)) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char const*,int) ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (unsigned char const*,unsigned char*,void const*) ; 
 int /*<<< orphan*/  stub10 (unsigned char const*,unsigned char*,void const*) ; 
 int /*<<< orphan*/  stub11 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub12 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub13 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub14 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub15 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub16 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub17 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub2 (unsigned char const*,unsigned char*,void const*) ; 
 int /*<<< orphan*/  stub3 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub4 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub5 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub6 (unsigned char const*,unsigned char*,int,void const*,unsigned char*,int) ; 
 int /*<<< orphan*/  stub7 (unsigned char const*,unsigned char*,void const*) ; 
 int /*<<< orphan*/  stub8 (unsigned char const*,unsigned char*,void const*) ; 
 int /*<<< orphan*/  stub9 (unsigned char const*,unsigned char*,void const*) ; 

size_t CRYPTO_cts128_encrypt_block(const unsigned char *in,
                                   unsigned char *out, size_t len,
                                   const void *key, unsigned char ivec[16],
                                   block128_f block)
{
    size_t residue, n;

    if (len <= 16)
        return 0;

    if ((residue = len % 16) == 0)
        residue = 16;

    len -= residue;

    CRYPTO_cbc128_encrypt(in, out, len, key, ivec, block);

    in += len;
    out += len;

    for (n = 0; n < residue; ++n)
        ivec[n] ^= in[n];
    (*block) (ivec, ivec, key);
    memcpy(out, out - 16, residue);
    memcpy(out - 16, ivec, 16);

    return len + residue;
}

size_t CRYPTO_nistcts128_encrypt_block(const unsigned char *in,
                                       unsigned char *out, size_t len,
                                       const void *key,
                                       unsigned char ivec[16],
                                       block128_f block)
{
    size_t residue, n;

    if (len < 16)
        return 0;

    residue = len % 16;

    len -= residue;

    CRYPTO_cbc128_encrypt(in, out, len, key, ivec, block);

    if (residue == 0)
        return len;

    in += len;
    out += len;

    for (n = 0; n < residue; ++n)
        ivec[n] ^= in[n];
    (*block) (ivec, ivec, key);
    memcpy(out - 16 + residue, ivec, 16);

    return len + residue;
}

size_t CRYPTO_cts128_encrypt(const unsigned char *in, unsigned char *out,
                             size_t len, const void *key,
                             unsigned char ivec[16], cbc128_f cbc)
{
    size_t residue;
    union {
        size_t align;
        unsigned char c[16];
    } tmp;

    if (len <= 16)
        return 0;

    if ((residue = len % 16) == 0)
        residue = 16;

    len -= residue;

    (*cbc) (in, out, len, key, ivec, 1);

    in += len;
    out += len;

#if defined(CBC_HANDLES_TRUNCATED_IO)
    memcpy(tmp.c, out - 16, 16);
    (*cbc) (in, out - 16, residue, key, ivec, 1);
    memcpy(out, tmp.c, residue);
#else
    memset(tmp.c, 0, sizeof(tmp));
    memcpy(tmp.c, in, residue);
    memcpy(out, out - 16, residue);
    (*cbc) (tmp.c, out - 16, 16, key, ivec, 1);
#endif
    return len + residue;
}

size_t CRYPTO_nistcts128_encrypt(const unsigned char *in, unsigned char *out,
                                 size_t len, const void *key,
                                 unsigned char ivec[16], cbc128_f cbc)
{
    size_t residue;
    union {
        size_t align;
        unsigned char c[16];
    } tmp;

    if (len < 16)
        return 0;

    residue = len % 16;

    len -= residue;

    (*cbc) (in, out, len, key, ivec, 1);

    if (residue == 0)
        return len;

    in += len;
    out += len;

#if defined(CBC_HANDLES_TRUNCATED_IO)
    (*cbc) (in, out - 16 + residue, residue, key, ivec, 1);
#else
    memset(tmp.c, 0, sizeof(tmp));
    memcpy(tmp.c, in, residue);
    (*cbc) (tmp.c, out - 16 + residue, 16, key, ivec, 1);
#endif
    return len + residue;
}

size_t CRYPTO_cts128_decrypt_block(const unsigned char *in,
                                   unsigned char *out, size_t len,
                                   const void *key, unsigned char ivec[16],
                                   block128_f block)
{
    size_t residue, n;
    union {
        size_t align;
        unsigned char c[32];
    } tmp;

    if (len <= 16)
        return 0;

    if ((residue = len % 16) == 0)
        residue = 16;

    len -= 16 + residue;

    if (len) {
        CRYPTO_cbc128_decrypt(in, out, len, key, ivec, block);
        in += len;
        out += len;
    }

    (*block) (in, tmp.c + 16, key);

    memcpy(tmp.c, tmp.c + 16, 16);
    memcpy(tmp.c, in + 16, residue);
    (*block) (tmp.c, tmp.c, key);

    for (n = 0; n < 16; ++n) {
        unsigned char c = in[n];
        out[n] = tmp.c[n] ^ ivec[n];
        ivec[n] = c;
    }
    for (residue += 16; n < residue; ++n)
        out[n] = tmp.c[n] ^ in[n];

    return 16 + len + residue;
}

size_t CRYPTO_nistcts128_decrypt_block(const unsigned char *in,
                                       unsigned char *out, size_t len,
                                       const void *key,
                                       unsigned char ivec[16],
                                       block128_f block)
{
    size_t residue, n;
    union {
        size_t align;
        unsigned char c[32];
    } tmp;

    if (len < 16)
        return 0;

    residue = len % 16;

    if (residue == 0) {
        CRYPTO_cbc128_decrypt(in, out, len, key, ivec, block);
        return len;
    }

    len -= 16 + residue;

    if (len) {
        CRYPTO_cbc128_decrypt(in, out, len, key, ivec, block);
        in += len;
        out += len;
    }

    (*block) (in + residue, tmp.c + 16, key);

    memcpy(tmp.c, tmp.c + 16, 16);
    memcpy(tmp.c, in, residue);
    (*block) (tmp.c, tmp.c, key);

    for (n = 0; n < 16; ++n) {
        unsigned char c = in[n];
        out[n] = tmp.c[n] ^ ivec[n];
        ivec[n] = in[n + residue];
        tmp.c[n] = c;
    }
    for (residue += 16; n < residue; ++n)
        out[n] = tmp.c[n] ^ tmp.c[n - 16];

    return 16 + len + residue;
}

size_t CRYPTO_cts128_decrypt(const unsigned char *in, unsigned char *out,
                             size_t len, const void *key,
                             unsigned char ivec[16], cbc128_f cbc)
{
    size_t residue;
    union {
        size_t align;
        unsigned char c[32];
    } tmp;

    if (len <= 16)
        return 0;

    if ((residue = len % 16) == 0)
        residue = 16;

    len -= 16 + residue;

    if (len) {
        (*cbc) (in, out, len, key, ivec, 0);
        in += len;
        out += len;
    }

    memset(tmp.c, 0, sizeof(tmp));
    /*
     * this places in[16] at &tmp.c[16] and decrypted block at &tmp.c[0]
     */
    (*cbc) (in, tmp.c, 16, key, tmp.c + 16, 0);

    memcpy(tmp.c, in + 16, residue);
#if defined(CBC_HANDLES_TRUNCATED_IO)
    (*cbc) (tmp.c, out, 16 + residue, key, ivec, 0);
#else
    (*cbc) (tmp.c, tmp.c, 32, key, ivec, 0);
    memcpy(out, tmp.c, 16 + residue);
#endif
    return 16 + len + residue;
}

size_t CRYPTO_nistcts128_decrypt(const unsigned char *in, unsigned char *out,
                                 size_t len, const void *key,
                                 unsigned char ivec[16], cbc128_f cbc)
{
    size_t residue;
    union {
        size_t align;
        unsigned char c[32];
    } tmp;

    if (len < 16)
        return 0;

    residue = len % 16;

    if (residue == 0) {
        (*cbc) (in, out, len, key, ivec, 0);
        return len;
    }

    len -= 16 + residue;

    if (len) {
        (*cbc) (in, out, len, key, ivec, 0);
        in += len;
        out += len;
    }

    memset(tmp.c, 0, sizeof(tmp));
    /*
     * this places in[16] at &tmp.c[16] and decrypted block at &tmp.c[0]
     */
    (*cbc) (in + residue, tmp.c, 16, key, tmp.c + 16, 0);

    memcpy(tmp.c, in, residue);
#if defined(CBC_HANDLES_TRUNCATED_IO)
    (*cbc) (tmp.c, out, 16 + residue, key, ivec, 0);
#else
    (*cbc) (tmp.c, tmp.c, 32, key, ivec, 0);
    memcpy(out, tmp.c, 16 + residue);
#endif
    return 16 + len + residue;
}

