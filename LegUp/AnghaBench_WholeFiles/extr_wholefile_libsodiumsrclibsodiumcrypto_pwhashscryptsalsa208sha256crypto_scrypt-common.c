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
typedef  char uint8_t ;
typedef  scalar_t__ uint64_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  hash ;
typedef  int /*<<< orphan*/  escrypt_local_t ;
typedef  int (* escrypt_kdf_t ) (int /*<<< orphan*/ *,char const*,size_t,char const*,size_t,scalar_t__,scalar_t__,scalar_t__,char*,size_t) ;

/* Variables and functions */
 size_t BYTES2CHARS (size_t) ; 
 int crypto_pwhash_scryptsalsa208sha256_STRHASHBYTES ; 
 size_t crypto_pwhash_scryptsalsa208sha256_STRHASHBYTES_ENCODED ; 
 scalar_t__ escrypt_free_local (int /*<<< orphan*/ *) ; 
 scalar_t__ escrypt_init_local (int /*<<< orphan*/ *) ; 
 int escrypt_kdf_nosse (int /*<<< orphan*/ *,char const*,size_t,char const*,size_t,scalar_t__,scalar_t__,scalar_t__,char*,size_t) ; 
 char const* itoa64 ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 int /*<<< orphan*/  sodium_memzero (char*,int) ; 
 char* strchr (char const*,char) ; 
 size_t strlen (char const*) ; 
 scalar_t__ strrchr (char const*,char) ; 

__attribute__((used)) static uint8_t *
encode64_uint32(uint8_t *dst, size_t dstlen, uint32_t src, uint32_t srcbits)
{
    uint32_t bit;

    for (bit = 0; bit < srcbits; bit += 6) {
        if (dstlen < 1) {
            return NULL; /* LCOV_EXCL_LINE */
        }
        *dst++ = itoa64[src & 0x3f];
        dstlen--;
        src >>= 6;
    }
    return dst;
}

__attribute__((used)) static uint8_t *
encode64(uint8_t *dst, size_t dstlen, const uint8_t *src, size_t srclen)
{
    size_t i;

    for (i = 0; i < srclen;) {
        uint8_t *dnext;
        uint32_t value = 0, bits = 0;

        do {
            value |= (uint32_t) src[i++] << bits;
            bits += 8;
        } while (bits < 24 && i < srclen);

        dnext = encode64_uint32(dst, dstlen, value, bits);
        if (!dnext) {
            return NULL; /* LCOV_EXCL_LINE */
        }
        dstlen -= dnext - dst;
        dst = dnext;
    }
    return dst;
}

__attribute__((used)) static int
decode64_one(uint32_t *dst, uint8_t src)
{
    const char *ptr = strchr(itoa64, src);

    if (ptr) {
        *dst = (uint32_t)(ptr - itoa64);
        return 0;
    }
    *dst = 0;

    return -1;
}

__attribute__((used)) static const uint8_t *
decode64_uint32(uint32_t *dst, uint32_t dstbits, const uint8_t *src)
{
    uint32_t bit;
    uint32_t value;

    value = 0;
    for (bit = 0; bit < dstbits; bit += 6) {
        uint32_t one;
        if (decode64_one(&one, *src)) {
            *dst = 0;
            return NULL;
        }
        src++;
        value |= one << bit;
    }
    *dst = value;

    return src;
}

const uint8_t *
escrypt_parse_setting(const uint8_t *setting,
                      uint32_t *N_log2_p, uint32_t *r_p, uint32_t *p_p)
{
    const uint8_t *src;

    if (setting[0] != '$' || setting[1] != '7' || setting[2] != '$') {
        return NULL;
    }
    src = setting + 3;

    if (decode64_one(N_log2_p, *src)) {
        return NULL;
    }
    src++;

    src = decode64_uint32(r_p, 30, src);
    if (!src) {
        return NULL;
    }

    src = decode64_uint32(p_p, 30, src);
    if (!src) {
        return NULL;
    }
    return src;
}

uint8_t *
escrypt_r(escrypt_local_t *local, const uint8_t *passwd, size_t passwdlen,
          const uint8_t *setting, uint8_t *buf, size_t buflen)
{
    uint8_t        hash[crypto_pwhash_scryptsalsa208sha256_STRHASHBYTES];
    escrypt_kdf_t  escrypt_kdf;
    const uint8_t *src;
    const uint8_t *salt;
    uint8_t       *dst;
    size_t         prefixlen;
    size_t         saltlen;
    size_t         need;
    uint64_t       N;
    uint32_t       N_log2;
    uint32_t       r;
    uint32_t       p;

    src = escrypt_parse_setting(setting, &N_log2, &r, &p);
    if (!src) {
        return NULL;
    }
    N = (uint64_t) 1 << N_log2;
    prefixlen = src - setting;

    salt = src;
    src  = (const uint8_t *) strrchr((const char *) salt, '$');
    if (src) {
        saltlen = src - salt;
    } else {
        saltlen = strlen((const char *) salt);
    }
    need = prefixlen + saltlen + 1 +
           crypto_pwhash_scryptsalsa208sha256_STRHASHBYTES_ENCODED + 1;
    if (need > buflen || need < saltlen) {
        return NULL;
    }
#ifdef HAVE_EMMINTRIN_H
    escrypt_kdf =
        sodium_runtime_has_sse2() ? escrypt_kdf_sse : escrypt_kdf_nosse;
#else
    escrypt_kdf = escrypt_kdf_nosse;
#endif
    if (escrypt_kdf(local, passwd, passwdlen, salt, saltlen, N, r, p, hash,
                    sizeof(hash))) {
        return NULL;
    }
    dst = buf;
    memcpy(dst, setting, prefixlen + saltlen);
    dst += prefixlen + saltlen;
    *dst++ = '$';

    dst = encode64(dst, buflen - (dst - buf), hash, sizeof(hash));
    sodium_memzero(hash, sizeof hash);
    if (!dst || dst >= buf + buflen) {
        return NULL; /* Can't happen LCOV_EXCL_LINE */
    }
    *dst = 0; /* NUL termination */

    return buf;
}

uint8_t *
escrypt_gensalt_r(uint32_t N_log2, uint32_t r, uint32_t p, const uint8_t *src,
                  size_t srclen, uint8_t *buf, size_t buflen)
{
    uint8_t *dst;
    size_t   prefixlen =
        (sizeof "$7$" - 1U) + (1U /* N_log2 */) + (5U /* r */) + (5U /* p */);
    size_t saltlen = BYTES2CHARS(srclen);
    size_t need;

    need = prefixlen + saltlen + 1;
    if (need > buflen || need < saltlen || saltlen < srclen) {
        return NULL; /* LCOV_EXCL_LINE */
    }
    if (N_log2 > 63 || ((uint64_t) r * (uint64_t) p >= (1U << 30))) {
        return NULL; /* LCOV_EXCL_LINE */
    }
    dst    = buf;
    *dst++ = '$';
    *dst++ = '7';
    *dst++ = '$';

    *dst++ = itoa64[N_log2];

    dst = encode64_uint32(dst, buflen - (dst - buf), r, 30);
    if (!dst) {
        return NULL; /* Can't happen LCOV_EXCL_LINE */
    }
    dst = encode64_uint32(dst, buflen - (dst - buf), p, 30);
    if (!dst) {
        return NULL; /* Can't happen LCOV_EXCL_LINE */
    }
    dst = encode64(dst, buflen - (dst - buf), src, srclen);
    if (!dst || dst >= buf + buflen) {
        return NULL; /* Can't happen LCOV_EXCL_LINE */
    }
    *dst = 0; /* NUL termination */

    return buf;
}

int
crypto_pwhash_scryptsalsa208sha256_ll(const uint8_t *passwd, size_t passwdlen,
                                      const uint8_t *salt, size_t saltlen,
                                      uint64_t N, uint32_t r, uint32_t p,
                                      uint8_t *buf, size_t buflen)
{
    escrypt_kdf_t   escrypt_kdf;
    escrypt_local_t local;
    int             retval;

    if (escrypt_init_local(&local)) {
        return -1; /* LCOV_EXCL_LINE */
    }
#if defined(HAVE_EMMINTRIN_H)
    escrypt_kdf =
        sodium_runtime_has_sse2() ? escrypt_kdf_sse : escrypt_kdf_nosse;
#else
    escrypt_kdf = escrypt_kdf_nosse;
#endif
    retval = escrypt_kdf(&local, passwd, passwdlen, salt, saltlen, N, r, p, buf,
                         buflen);
    if (escrypt_free_local(&local)) {
        return -1; /* LCOV_EXCL_LINE */
    }
    return retval;
}

