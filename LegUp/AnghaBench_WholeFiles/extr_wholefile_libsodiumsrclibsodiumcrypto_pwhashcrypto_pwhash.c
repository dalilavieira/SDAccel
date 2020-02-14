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

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
#define  crypto_pwhash_ALG_ARGON2I13 129 
#define  crypto_pwhash_ALG_ARGON2ID13 128 
 int crypto_pwhash_ALG_DEFAULT ; 
 size_t crypto_pwhash_BYTES_MAX ; 
 size_t crypto_pwhash_BYTES_MIN ; 
 size_t crypto_pwhash_MEMLIMIT_INTERACTIVE ; 
 size_t crypto_pwhash_MEMLIMIT_MAX ; 
 size_t crypto_pwhash_MEMLIMIT_MIN ; 
 size_t crypto_pwhash_MEMLIMIT_MODERATE ; 
 size_t crypto_pwhash_MEMLIMIT_SENSITIVE ; 
 size_t crypto_pwhash_OPSLIMIT_INTERACTIVE ; 
 size_t crypto_pwhash_OPSLIMIT_MAX ; 
 size_t crypto_pwhash_OPSLIMIT_MIN ; 
 size_t crypto_pwhash_OPSLIMIT_MODERATE ; 
 size_t crypto_pwhash_OPSLIMIT_SENSITIVE ; 
 size_t crypto_pwhash_PASSWD_MAX ; 
 size_t crypto_pwhash_PASSWD_MIN ; 
 char const* crypto_pwhash_PRIMITIVE ; 
 size_t crypto_pwhash_SALTBYTES ; 
 size_t crypto_pwhash_STRBYTES ; 
 char const* crypto_pwhash_STRPREFIX ; 
 int crypto_pwhash_argon2i (unsigned char* const,unsigned long long,char const* const,unsigned long long,unsigned char const* const,unsigned long long,size_t,int) ; 
 int /*<<< orphan*/  crypto_pwhash_argon2i_STRPREFIX ; 
 int crypto_pwhash_argon2i_str (char*,char const* const,unsigned long long,unsigned long long,size_t) ; 
 int crypto_pwhash_argon2i_str_needs_rehash (char const*,unsigned long long,size_t) ; 
 int crypto_pwhash_argon2i_str_verify (char const*,char const* const,unsigned long long) ; 
 int crypto_pwhash_argon2id (unsigned char* const,unsigned long long,char const* const,unsigned long long,unsigned char const* const,unsigned long long,size_t,int) ; 
 int /*<<< orphan*/  crypto_pwhash_argon2id_STRPREFIX ; 
 int crypto_pwhash_argon2id_str (char*,char const* const,unsigned long long,unsigned long long,size_t) ; 
 int crypto_pwhash_argon2id_str_needs_rehash (char const*,unsigned long long,size_t) ; 
 int crypto_pwhash_argon2id_str_verify (char const*,char const* const,unsigned long long) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  sodium_misuse () ; 
 scalar_t__ strncmp (char const*,int /*<<< orphan*/ ,int) ; 

int
crypto_pwhash_alg_argon2i13(void)
{
    return crypto_pwhash_ALG_ARGON2I13;
}

int
crypto_pwhash_alg_argon2id13(void)
{
    return crypto_pwhash_ALG_ARGON2ID13;
}

int
crypto_pwhash_alg_default(void)
{
    return crypto_pwhash_ALG_DEFAULT;
}

size_t
crypto_pwhash_bytes_min(void)
{
    return crypto_pwhash_BYTES_MIN;
}

size_t
crypto_pwhash_bytes_max(void)
{
    return crypto_pwhash_BYTES_MAX;
}

size_t
crypto_pwhash_passwd_min(void)
{
    return crypto_pwhash_PASSWD_MIN;
}

size_t
crypto_pwhash_passwd_max(void)
{
    return crypto_pwhash_PASSWD_MAX;
}

size_t
crypto_pwhash_saltbytes(void)
{
    return crypto_pwhash_SALTBYTES;
}

size_t
crypto_pwhash_strbytes(void)
{
    return crypto_pwhash_STRBYTES;
}

const char *
crypto_pwhash_strprefix(void)
{
    return crypto_pwhash_STRPREFIX;
}

size_t
crypto_pwhash_opslimit_min(void)
{
    return crypto_pwhash_OPSLIMIT_MIN;
}

size_t
crypto_pwhash_opslimit_max(void)
{
    return crypto_pwhash_OPSLIMIT_MAX;
}

size_t
crypto_pwhash_memlimit_min(void)
{
    return crypto_pwhash_MEMLIMIT_MIN;
}

size_t
crypto_pwhash_memlimit_max(void)
{
    return crypto_pwhash_MEMLIMIT_MAX;
}

size_t
crypto_pwhash_opslimit_interactive(void)
{
    return crypto_pwhash_OPSLIMIT_INTERACTIVE;
}

size_t
crypto_pwhash_memlimit_interactive(void)
{
    return crypto_pwhash_MEMLIMIT_INTERACTIVE;
}

size_t
crypto_pwhash_opslimit_moderate(void)
{
    return crypto_pwhash_OPSLIMIT_MODERATE;
}

size_t
crypto_pwhash_memlimit_moderate(void)
{
    return crypto_pwhash_MEMLIMIT_MODERATE;
}

size_t
crypto_pwhash_opslimit_sensitive(void)
{
    return crypto_pwhash_OPSLIMIT_SENSITIVE;
}

size_t
crypto_pwhash_memlimit_sensitive(void)
{
    return crypto_pwhash_MEMLIMIT_SENSITIVE;
}

int
crypto_pwhash(unsigned char * const out, unsigned long long outlen,
              const char * const passwd, unsigned long long passwdlen,
              const unsigned char * const salt,
              unsigned long long opslimit, size_t memlimit, int alg)
{
    switch (alg) {
    case crypto_pwhash_ALG_ARGON2I13:
        return crypto_pwhash_argon2i(out, outlen, passwd, passwdlen, salt,
                                     opslimit, memlimit, alg);
    case crypto_pwhash_ALG_ARGON2ID13:
        return crypto_pwhash_argon2id(out, outlen, passwd, passwdlen, salt,
                                      opslimit, memlimit, alg);
    default:
        errno = EINVAL;
        return -1;
    }
}

int
crypto_pwhash_str(char out[crypto_pwhash_STRBYTES],
                  const char * const passwd, unsigned long long passwdlen,
                  unsigned long long opslimit, size_t memlimit)
{
    return crypto_pwhash_argon2id_str(out, passwd, passwdlen,
                                      opslimit, memlimit);
}

int
crypto_pwhash_str_alg(char out[crypto_pwhash_STRBYTES],
                      const char * const passwd, unsigned long long passwdlen,
                      unsigned long long opslimit, size_t memlimit, int alg)
{
    switch (alg) {
    case crypto_pwhash_ALG_ARGON2I13:
        return crypto_pwhash_argon2i_str(out, passwd, passwdlen,
                                         opslimit, memlimit);
    case crypto_pwhash_ALG_ARGON2ID13:
        return crypto_pwhash_argon2id_str(out, passwd, passwdlen,
                                          opslimit, memlimit);
    }
    sodium_misuse();
    /* NOTREACHED */
    return -1;
}

int
crypto_pwhash_str_verify(const char str[crypto_pwhash_STRBYTES],
                         const char * const passwd,
                         unsigned long long passwdlen)
{
    if (strncmp(str, crypto_pwhash_argon2id_STRPREFIX,
                sizeof crypto_pwhash_argon2id_STRPREFIX - 1) == 0) {
        return crypto_pwhash_argon2id_str_verify(str, passwd, passwdlen);
    }
    if (strncmp(str, crypto_pwhash_argon2i_STRPREFIX,
                sizeof crypto_pwhash_argon2i_STRPREFIX - 1) == 0) {
        return crypto_pwhash_argon2i_str_verify(str, passwd, passwdlen);
    }
    errno = EINVAL;

    return -1;
}

int
crypto_pwhash_str_needs_rehash(const char str[crypto_pwhash_STRBYTES],
                               unsigned long long opslimit, size_t memlimit)
{
    if (strncmp(str, crypto_pwhash_argon2id_STRPREFIX,
                sizeof crypto_pwhash_argon2id_STRPREFIX - 1) == 0) {
        return crypto_pwhash_argon2id_str_needs_rehash(str, opslimit, memlimit);
    }
    if (strncmp(str, crypto_pwhash_argon2i_STRPREFIX,
                sizeof crypto_pwhash_argon2i_STRPREFIX - 1) == 0) {
        return crypto_pwhash_argon2i_str_needs_rehash(str, opslimit, memlimit);
    }
    errno = EINVAL;

    return -1;
}

const char *
crypto_pwhash_primitive(void) {
    return crypto_pwhash_PRIMITIVE;
}

