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
typedef  int /*<<< orphan*/  trash ;
typedef  int /*<<< orphan*/  rounds_prefix ;
typedef  scalar_t__ passwd_modes ;
typedef  int /*<<< orphan*/  out_buf ;
typedef  int /*<<< orphan*/  buf_perm ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  ascii_salt ;
typedef  int /*<<< orphan*/  ascii_magic ;
typedef  int OPTION_CHOICE ;
typedef  int /*<<< orphan*/  EVP_MD_CTX ;
typedef  int /*<<< orphan*/  EVP_MD ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_free (int /*<<< orphan*/ *) ; 
 int BIO_gets (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  BIO_printf (int /*<<< orphan*/ *,char*,...) ; 
 int BUFSIZ ; 
 char* DES_crypt (char*,char*) ; 
 int /*<<< orphan*/  EVP_DigestFinal_ex (int /*<<< orphan*/ *,unsigned char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_DigestInit_ex (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_DigestUpdate (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  EVP_MD_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * EVP_MD_CTX_new () ; 
 int /*<<< orphan*/  const* EVP_md5 () ; 
 scalar_t__ EVP_read_pw_string (char*,size_t,char*,int) ; 
 int /*<<< orphan*/ * EVP_sha256 () ; 
 int /*<<< orphan*/ * EVP_sha512 () ; 
 int /*<<< orphan*/  FORMAT_TEXT ; 
 int MD5_DIGEST_LENGTH ; 
 int /*<<< orphan*/  OPENSSL_free (char*) ; 
 int /*<<< orphan*/  OPENSSL_strlcat (char*,char*,int) ; 
 int /*<<< orphan*/  OPENSSL_strlcpy (char*,char const*,int) ; 
 char* OPENSSL_zalloc (size_t) ; 
#define  OPT_1 144 
#define  OPT_5 143 
#define  OPT_6 142 
#define  OPT_AIXMD5 141 
#define  OPT_APR1 140 
#define  OPT_CRYPT 139 
#define  OPT_EOF 138 
#define  OPT_ERR 137 
#define  OPT_HELP 136 
#define  OPT_IN 135 
#define  OPT_NOVERIFY 134 
#define  OPT_QUIET 133 
#define  OPT_REVERSE 132 
#define  OPT_R_CASES 131 
#define  OPT_SALT 130 
#define  OPT_STDIN 129 
#define  OPT_TABLE 128 
 scalar_t__ RAND_bytes (unsigned char*,size_t) ; 
 int SHA512_DIGEST_LENGTH ; 
 char* app_malloc (size_t,char*) ; 
 char* ascii_dollar ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/ * bio_err ; 
 int /*<<< orphan*/ * bio_open_default (char*,char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * bio_out ; 
 void** cov_2char ; 
static  int do_passwd (int,char**,char**,char*,int /*<<< orphan*/ *,int,int,int,size_t,scalar_t__) ; 
 int /*<<< orphan*/  memcpy (char*,unsigned char*,size_t) ; 
 char* opt_arg () ; 
 int /*<<< orphan*/  opt_help (int /*<<< orphan*/ ) ; 
 char* opt_init (int,char**,int /*<<< orphan*/ ) ; 
 int opt_next () ; 
 int opt_num_rest () ; 
 int /*<<< orphan*/  opt_rand (int) ; 
 char** opt_rest () ; 
 scalar_t__ passwd_aixmd5 ; 
 scalar_t__ passwd_apr1 ; 
 scalar_t__ passwd_crypt ; 
 scalar_t__ passwd_md5 ; 
 int /*<<< orphan*/  passwd_options ; 
 scalar_t__ passwd_sha256 ; 
 scalar_t__ passwd_sha512 ; 
 scalar_t__ passwd_unset ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned int) ; 
 char* strchr (char*,char) ; 
 size_t strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char const*,int) ; 
 unsigned long strtoul (char const*,char**,int) ; 

int passwd_main(int argc, char **argv)
{
    BIO *in = NULL;
    char *infile = NULL, *salt = NULL, *passwd = NULL, **passwds = NULL;
    char *salt_malloc = NULL, *passwd_malloc = NULL, *prog;
    OPTION_CHOICE o;
    int in_stdin = 0, pw_source_defined = 0;
#ifndef OPENSSL_NO_UI_CONSOLE
    int in_noverify = 0;
#endif
    int passed_salt = 0, quiet = 0, table = 0, reverse = 0;
    int ret = 1;
    passwd_modes mode = passwd_unset;
    size_t passwd_malloc_size = 0;
    size_t pw_maxlen = 256; /* arbitrary limit, should be enough for most
                             * passwords */

    prog = opt_init(argc, argv, passwd_options);
    while ((o = opt_next()) != OPT_EOF) {
        switch (o) {
        case OPT_EOF:
        case OPT_ERR:
 opthelp:
            BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
            goto end;
        case OPT_HELP:
            opt_help(passwd_options);
            ret = 0;
            goto end;
        case OPT_IN:
            if (pw_source_defined)
                goto opthelp;
            infile = opt_arg();
            pw_source_defined = 1;
            break;
        case OPT_NOVERIFY:
#ifndef OPENSSL_NO_UI_CONSOLE
            in_noverify = 1;
#endif
            break;
        case OPT_QUIET:
            quiet = 1;
            break;
        case OPT_TABLE:
            table = 1;
            break;
        case OPT_REVERSE:
            reverse = 1;
            break;
        case OPT_1:
            if (mode != passwd_unset)
                goto opthelp;
            mode = passwd_md5;
            break;
        case OPT_5:
            if (mode != passwd_unset)
                goto opthelp;
            mode = passwd_sha256;
            break;
        case OPT_6:
            if (mode != passwd_unset)
                goto opthelp;
            mode = passwd_sha512;
            break;
        case OPT_APR1:
            if (mode != passwd_unset)
                goto opthelp;
            mode = passwd_apr1;
            break;
        case OPT_AIXMD5:
            if (mode != passwd_unset)
                goto opthelp;
            mode = passwd_aixmd5;
            break;
        case OPT_CRYPT:
#ifndef OPENSSL_NO_DES
            if (mode != passwd_unset)
                goto opthelp;
            mode = passwd_crypt;
#endif
            break;
        case OPT_SALT:
            passed_salt = 1;
            salt = opt_arg();
            break;
        case OPT_STDIN:
            if (pw_source_defined)
                goto opthelp;
            in_stdin = 1;
            pw_source_defined = 1;
            break;
        case OPT_R_CASES:
            if (!opt_rand(o))
                goto end;
            break;
        }
    }
    argc = opt_num_rest();
    argv = opt_rest();

    if (*argv != NULL) {
        if (pw_source_defined)
            goto opthelp;
        pw_source_defined = 1;
        passwds = argv;
    }

    if (mode == passwd_unset) {
        /* use default */
        mode = passwd_crypt;
    }

#ifdef OPENSSL_NO_DES
    if (mode == passwd_crypt)
        goto opthelp;
#endif

    if (infile != NULL && in_stdin) {
        BIO_printf(bio_err, "%s: Can't combine -in and -stdin\n", prog);
        goto end;
    }

    if (infile != NULL || in_stdin) {
        /*
         * If in_stdin is true, we know that infile is NULL, and that
         * bio_open_default() will give us back an alias for stdin.
         */
        in = bio_open_default(infile, 'r', FORMAT_TEXT);
        if (in == NULL)
            goto end;
    }

    if (mode == passwd_crypt)
        pw_maxlen = 8;

    if (passwds == NULL) {
        /* no passwords on the command line */

        passwd_malloc_size = pw_maxlen + 2;
        /* longer than necessary so that we can warn about truncation */
        passwd = passwd_malloc =
            app_malloc(passwd_malloc_size, "password buffer");
    }

    if ((in == NULL) && (passwds == NULL)) {
        /*
         * we use the following method to make sure what
         * in the 'else' section is always compiled, to
         * avoid rot of not-frequently-used code.
         */
        if (1) {
#ifndef OPENSSL_NO_UI_CONSOLE
            /* build a null-terminated list */
            static char *passwds_static[2] = { NULL, NULL };

            passwds = passwds_static;
            if (in == NULL) {
                if (EVP_read_pw_string
                    (passwd_malloc, passwd_malloc_size, "Password: ",
                     !(passed_salt || in_noverify)) != 0)
                    goto end;
            }
            passwds[0] = passwd_malloc;
        } else {
#endif
            BIO_printf(bio_err, "password required\n");
            goto end;
        }
    }

    if (in == NULL) {
        assert(passwds != NULL);
        assert(*passwds != NULL);

        do {                    /* loop over list of passwords */
            passwd = *passwds++;
            if (!do_passwd(passed_salt, &salt, &salt_malloc, passwd, bio_out,
                           quiet, table, reverse, pw_maxlen, mode))
                goto end;
        } while (*passwds != NULL);
    } else {
        /* in != NULL */
        int done;

        assert(passwd != NULL);
        do {
            int r = BIO_gets(in, passwd, pw_maxlen + 1);
            if (r > 0) {
                char *c = (strchr(passwd, '\n'));
                if (c != NULL) {
                    *c = 0;     /* truncate at newline */
                } else {
                    /* ignore rest of line */
                    char trash[BUFSIZ];
                    do
                        r = BIO_gets(in, trash, sizeof(trash));
                    while ((r > 0) && (!strchr(trash, '\n')));
                }

                if (!do_passwd
                    (passed_salt, &salt, &salt_malloc, passwd, bio_out, quiet,
                     table, reverse, pw_maxlen, mode))
                    goto end;
            }
            done = (r <= 0);
        } while (!done);
    }
    ret = 0;

 end:
#if 0
    ERR_print_errors(bio_err);
#endif
    OPENSSL_free(salt_malloc);
    OPENSSL_free(passwd_malloc);
    BIO_free(in);
    return ret;
}

__attribute__((used)) static char *md5crypt(const char *passwd, const char *magic, const char *salt)
{
    /* "$apr1$..salt..$.......md5hash..........\0" */
    static char out_buf[6 + 9 + 24 + 2];
    unsigned char buf[MD5_DIGEST_LENGTH];
    char ascii_magic[5];         /* "apr1" plus '\0' */
    char ascii_salt[9];          /* Max 8 chars plus '\0' */
    char *ascii_passwd = NULL;
    char *salt_out;
    int n;
    unsigned int i;
    EVP_MD_CTX *md = NULL, *md2 = NULL;
    size_t passwd_len, salt_len, magic_len;

    passwd_len = strlen(passwd);

    out_buf[0] = 0;
    magic_len = strlen(magic);
    OPENSSL_strlcpy(ascii_magic, magic, sizeof(ascii_magic));
#ifdef CHARSET_EBCDIC
    if ((magic[0] & 0x80) != 0)    /* High bit is 1 in EBCDIC alnums */
        ebcdic2ascii(ascii_magic, ascii_magic, magic_len);
#endif

    /* The salt gets truncated to 8 chars */
    OPENSSL_strlcpy(ascii_salt, salt, sizeof(ascii_salt));
    salt_len = strlen(ascii_salt);
#ifdef CHARSET_EBCDIC
    ebcdic2ascii(ascii_salt, ascii_salt, salt_len);
#endif

#ifdef CHARSET_EBCDIC
    ascii_passwd = OPENSSL_strdup(passwd);
    if (ascii_passwd == NULL)
        return NULL;
    ebcdic2ascii(ascii_passwd, ascii_passwd, passwd_len);
    passwd = ascii_passwd;
#endif

    if (magic_len > 0) {
        OPENSSL_strlcat(out_buf, ascii_dollar, sizeof(out_buf));

        if (magic_len > 4)    /* assert it's  "1" or "apr1" */
            goto err;

        OPENSSL_strlcat(out_buf, ascii_magic, sizeof(out_buf));
        OPENSSL_strlcat(out_buf, ascii_dollar, sizeof(out_buf));
    }

    OPENSSL_strlcat(out_buf, ascii_salt, sizeof(out_buf));

    if (strlen(out_buf) > 6 + 8) /* assert "$apr1$..salt.." */
        goto err;

    salt_out = out_buf;
    if (magic_len > 0)
        salt_out += 2 + magic_len;

    if (salt_len > 8)
        goto err;

    md = EVP_MD_CTX_new();
    if (md == NULL
        || !EVP_DigestInit_ex(md, EVP_md5(), NULL)
        || !EVP_DigestUpdate(md, passwd, passwd_len))
        goto err;

    if (magic_len > 0)
        if (!EVP_DigestUpdate(md, ascii_dollar, 1)
            || !EVP_DigestUpdate(md, ascii_magic, magic_len)
            || !EVP_DigestUpdate(md, ascii_dollar, 1))
          goto err;

    if (!EVP_DigestUpdate(md, ascii_salt, salt_len))
        goto err;

    md2 = EVP_MD_CTX_new();
    if (md2 == NULL
        || !EVP_DigestInit_ex(md2, EVP_md5(), NULL)
        || !EVP_DigestUpdate(md2, passwd, passwd_len)
        || !EVP_DigestUpdate(md2, ascii_salt, salt_len)
        || !EVP_DigestUpdate(md2, passwd, passwd_len)
        || !EVP_DigestFinal_ex(md2, buf, NULL))
        goto err;

    for (i = passwd_len; i > sizeof(buf); i -= sizeof(buf)) {
        if (!EVP_DigestUpdate(md, buf, sizeof(buf)))
            goto err;
    }
    if (!EVP_DigestUpdate(md, buf, i))
        goto err;

    n = passwd_len;
    while (n) {
        if (!EVP_DigestUpdate(md, (n & 1) ? "\0" : passwd, 1))
            goto err;
        n >>= 1;
    }
    if (!EVP_DigestFinal_ex(md, buf, NULL))
        return NULL;

    for (i = 0; i < 1000; i++) {
        if (!EVP_DigestInit_ex(md2, EVP_md5(), NULL))
            goto err;
        if (!EVP_DigestUpdate(md2,
                              (i & 1) ? (unsigned const char *)passwd : buf,
                              (i & 1) ? passwd_len : sizeof(buf)))
            goto err;
        if (i % 3) {
            if (!EVP_DigestUpdate(md2, ascii_salt, salt_len))
                goto err;
        }
        if (i % 7) {
            if (!EVP_DigestUpdate(md2, passwd, passwd_len))
                goto err;
        }
        if (!EVP_DigestUpdate(md2,
                              (i & 1) ? buf : (unsigned const char *)passwd,
                              (i & 1) ? sizeof(buf) : passwd_len))
                goto err;
        if (!EVP_DigestFinal_ex(md2, buf, NULL))
                goto err;
    }
    EVP_MD_CTX_free(md2);
    EVP_MD_CTX_free(md);
    md2 = NULL;
    md = NULL;

    {
        /* transform buf into output string */
        unsigned char buf_perm[sizeof(buf)];
        int dest, source;
        char *output;

        /* silly output permutation */
        for (dest = 0, source = 0; dest < 14;
             dest++, source = (source + 6) % 17)
            buf_perm[dest] = buf[source];
        buf_perm[14] = buf[5];
        buf_perm[15] = buf[11];
# ifndef PEDANTIC              /* Unfortunately, this generates a "no
                                 * effect" warning */
        assert(16 == sizeof(buf_perm));
# endif

        output = salt_out + salt_len;
        assert(output == out_buf + strlen(out_buf));

        *output++ = ascii_dollar[0];

        for (i = 0; i < 15; i += 3) {
            *output++ = cov_2char[buf_perm[i + 2] & 0x3f];
            *output++ = cov_2char[((buf_perm[i + 1] & 0xf) << 2) |
                                  (buf_perm[i + 2] >> 6)];
            *output++ = cov_2char[((buf_perm[i] & 3) << 4) |
                                  (buf_perm[i + 1] >> 4)];
            *output++ = cov_2char[buf_perm[i] >> 2];
        }
        assert(i == 15);
        *output++ = cov_2char[buf_perm[i] & 0x3f];
        *output++ = cov_2char[buf_perm[i] >> 6];
        *output = 0;
        assert(strlen(out_buf) < sizeof(out_buf));
#ifdef CHARSET_EBCDIC
        ascii2ebcdic(out_buf, out_buf, strlen(out_buf));
#endif
    }

    return out_buf;

 err:
    OPENSSL_free(ascii_passwd);
    EVP_MD_CTX_free(md2);
    EVP_MD_CTX_free(md);
    return NULL;
}

__attribute__((used)) static char *shacrypt(const char *passwd, const char *magic, const char *salt)
{
    /* Prefix for optional rounds specification.  */
    static const char rounds_prefix[] = "rounds=";
    /* Maximum salt string length.  */
# define SALT_LEN_MAX 16
    /* Default number of rounds if not explicitly specified.  */
# define ROUNDS_DEFAULT 5000
    /* Minimum number of rounds.  */
# define ROUNDS_MIN 1000
    /* Maximum number of rounds.  */
# define ROUNDS_MAX 999999999

    /* "$6$rounds=<N>$......salt......$...shahash(up to 86 chars)...\0" */
    static char out_buf[3 + 17 + 17 + 86 + 1];
    unsigned char buf[SHA512_DIGEST_LENGTH];
    unsigned char temp_buf[SHA512_DIGEST_LENGTH];
    size_t buf_size = 0;
    char ascii_magic[2];
    char ascii_salt[17];          /* Max 16 chars plus '\0' */
    char *ascii_passwd = NULL;
    size_t n;
    EVP_MD_CTX *md = NULL, *md2 = NULL;
    const EVP_MD *sha = NULL;
    size_t passwd_len, salt_len, magic_len;
    unsigned int rounds = 5000;        /* Default */
    char rounds_custom = 0;
    char *p_bytes = NULL;
    char *s_bytes = NULL;
    char *cp = NULL;

    passwd_len = strlen(passwd);
    magic_len = strlen(magic);

    /* assert it's "5" or "6" */
    if (magic_len != 1)
        return NULL;

    switch (magic[0]) {
    case '5':
        sha = EVP_sha256();
        buf_size = 32;
        break;
    case '6':
        sha = EVP_sha512();
        buf_size = 64;
        break;
    default:
        return NULL;
    }

    if (strncmp(salt, rounds_prefix, sizeof(rounds_prefix) - 1) == 0) {
        const char *num = salt + sizeof(rounds_prefix) - 1;
        char *endp;
        unsigned long int srounds = strtoul (num, &endp, 10);
        if (*endp == '$') {
            salt = endp + 1;
            if (srounds > ROUNDS_MAX)
                rounds = ROUNDS_MAX;
            else if (srounds < ROUNDS_MIN)
                rounds = ROUNDS_MIN;
            else
                rounds = (unsigned int)srounds;
            rounds_custom = 1;
        } else {
            return NULL;
        }
    }

    OPENSSL_strlcpy(ascii_magic, magic, sizeof(ascii_magic));
#ifdef CHARSET_EBCDIC
    if ((magic[0] & 0x80) != 0)    /* High bit is 1 in EBCDIC alnums */
        ebcdic2ascii(ascii_magic, ascii_magic, magic_len);
#endif

    /* The salt gets truncated to 16 chars */
    OPENSSL_strlcpy(ascii_salt, salt, sizeof(ascii_salt));
    salt_len = strlen(ascii_salt);
#ifdef CHARSET_EBCDIC
    ebcdic2ascii(ascii_salt, ascii_salt, salt_len);
#endif

#ifdef CHARSET_EBCDIC
    ascii_passwd = OPENSSL_strdup(passwd);
    if (ascii_passwd == NULL)
        return NULL;
    ebcdic2ascii(ascii_passwd, ascii_passwd, passwd_len);
    passwd = ascii_passwd;
#endif

    out_buf[0] = 0;
    OPENSSL_strlcat(out_buf, ascii_dollar, sizeof(out_buf));
    OPENSSL_strlcat(out_buf, ascii_magic, sizeof(out_buf));
    OPENSSL_strlcat(out_buf, ascii_dollar, sizeof(out_buf));
    if (rounds_custom) {
        char tmp_buf[80]; /* "rounds=999999999" */
        sprintf(tmp_buf, "rounds=%u", rounds);
#ifdef CHARSET_EBCDIC
        /* In case we're really on a ASCII based platform and just pretend */
        if (tmp_buf[0] != 0x72)  /* ASCII 'r' */
            ebcdic2ascii(tmp_buf, tmp_buf, strlen(tmp_buf));
#endif
        OPENSSL_strlcat(out_buf, tmp_buf, sizeof(out_buf));
        OPENSSL_strlcat(out_buf, ascii_dollar, sizeof(out_buf));
    }
    OPENSSL_strlcat(out_buf, ascii_salt, sizeof(out_buf));

    /* assert "$5$rounds=999999999$......salt......" */
    if (strlen(out_buf) > 3 + 17 * rounds_custom + salt_len )
        goto err;

    md = EVP_MD_CTX_new();
    if (md == NULL
        || !EVP_DigestInit_ex(md, sha, NULL)
        || !EVP_DigestUpdate(md, passwd, passwd_len)
        || !EVP_DigestUpdate(md, ascii_salt, salt_len))
        goto err;

    md2 = EVP_MD_CTX_new();
    if (md2 == NULL
        || !EVP_DigestInit_ex(md2, sha, NULL)
        || !EVP_DigestUpdate(md2, passwd, passwd_len)
        || !EVP_DigestUpdate(md2, ascii_salt, salt_len)
        || !EVP_DigestUpdate(md2, passwd, passwd_len)
        || !EVP_DigestFinal_ex(md2, buf, NULL))
        goto err;

    for (n = passwd_len; n > buf_size; n -= buf_size) {
        if (!EVP_DigestUpdate(md, buf, buf_size))
            goto err;
    }
    if (!EVP_DigestUpdate(md, buf, n))
        goto err;

    n = passwd_len;
    while (n) {
        if (!EVP_DigestUpdate(md,
                              (n & 1) ? buf : (unsigned const char *)passwd,
                              (n & 1) ? buf_size : passwd_len))
            goto err;
        n >>= 1;
    }
    if (!EVP_DigestFinal_ex(md, buf, NULL))
        return NULL;

    /* P sequence */
    if (!EVP_DigestInit_ex(md2, sha, NULL))
        goto err;

    for (n = passwd_len; n > 0; n--)
        if (!EVP_DigestUpdate(md2, passwd, passwd_len))
            goto err;

    if (!EVP_DigestFinal_ex(md2, temp_buf, NULL))
        return NULL;

    if ((p_bytes = OPENSSL_zalloc(passwd_len)) == NULL)
        goto err;
    for (cp = p_bytes, n = passwd_len; n > buf_size; n -= buf_size, cp += buf_size)
        memcpy(cp, temp_buf, buf_size);
    memcpy(cp, temp_buf, n);

    /* S sequence */
    if (!EVP_DigestInit_ex(md2, sha, NULL))
        goto err;

    for (n = 16 + buf[0]; n > 0; n--)
        if (!EVP_DigestUpdate(md2, ascii_salt, salt_len))
            goto err;

    if (!EVP_DigestFinal_ex(md2, temp_buf, NULL))
        return NULL;

    if ((s_bytes = OPENSSL_zalloc(salt_len)) == NULL)
        goto err;
    for (cp = s_bytes, n = salt_len; n > buf_size; n -= buf_size, cp += buf_size)
        memcpy(cp, temp_buf, buf_size);
    memcpy(cp, temp_buf, n);

    for (n = 0; n < rounds; n++) {
        if (!EVP_DigestInit_ex(md2, sha, NULL))
            goto err;
        if (!EVP_DigestUpdate(md2,
                              (n & 1) ? (unsigned const char *)p_bytes : buf,
                              (n & 1) ? passwd_len : buf_size))
            goto err;
        if (n % 3) {
            if (!EVP_DigestUpdate(md2, s_bytes, salt_len))
                goto err;
        }
        if (n % 7) {
            if (!EVP_DigestUpdate(md2, p_bytes, passwd_len))
                goto err;
        }
        if (!EVP_DigestUpdate(md2,
                              (n & 1) ? buf : (unsigned const char *)p_bytes,
                              (n & 1) ? buf_size : passwd_len))
                goto err;
        if (!EVP_DigestFinal_ex(md2, buf, NULL))
                goto err;
    }
    EVP_MD_CTX_free(md2);
    EVP_MD_CTX_free(md);
    md2 = NULL;
    md = NULL;
    OPENSSL_free(p_bytes);
    OPENSSL_free(s_bytes);
    p_bytes = NULL;
    s_bytes = NULL;

    cp = out_buf + strlen(out_buf);
    *cp++ = ascii_dollar[0];

# define b64_from_24bit(B2, B1, B0, N)                                   \
    do {                                                                \
        unsigned int w = ((B2) << 16) | ((B1) << 8) | (B0);             \
        int i = (N);                                                    \
        while (i-- > 0)                                                 \
            {                                                           \
                *cp++ = cov_2char[w & 0x3f];                            \
                w >>= 6;                                                \
            }                                                           \
    } while (0)

    switch (magic[0]) {
    case '5':
        b64_from_24bit (buf[0], buf[10], buf[20], 4);
        b64_from_24bit (buf[21], buf[1], buf[11], 4);
        b64_from_24bit (buf[12], buf[22], buf[2], 4);
        b64_from_24bit (buf[3], buf[13], buf[23], 4);
        b64_from_24bit (buf[24], buf[4], buf[14], 4);
        b64_from_24bit (buf[15], buf[25], buf[5], 4);
        b64_from_24bit (buf[6], buf[16], buf[26], 4);
        b64_from_24bit (buf[27], buf[7], buf[17], 4);
        b64_from_24bit (buf[18], buf[28], buf[8], 4);
        b64_from_24bit (buf[9], buf[19], buf[29], 4);
        b64_from_24bit (0, buf[31], buf[30], 3);
        break;
    case '6':
        b64_from_24bit (buf[0], buf[21], buf[42], 4);
        b64_from_24bit (buf[22], buf[43], buf[1], 4);
        b64_from_24bit (buf[44], buf[2], buf[23], 4);
        b64_from_24bit (buf[3], buf[24], buf[45], 4);
        b64_from_24bit (buf[25], buf[46], buf[4], 4);
        b64_from_24bit (buf[47], buf[5], buf[26], 4);
        b64_from_24bit (buf[6], buf[27], buf[48], 4);
        b64_from_24bit (buf[28], buf[49], buf[7], 4);
        b64_from_24bit (buf[50], buf[8], buf[29], 4);
        b64_from_24bit (buf[9], buf[30], buf[51], 4);
        b64_from_24bit (buf[31], buf[52], buf[10], 4);
        b64_from_24bit (buf[53], buf[11], buf[32], 4);
        b64_from_24bit (buf[12], buf[33], buf[54], 4);
        b64_from_24bit (buf[34], buf[55], buf[13], 4);
        b64_from_24bit (buf[56], buf[14], buf[35], 4);
        b64_from_24bit (buf[15], buf[36], buf[57], 4);
        b64_from_24bit (buf[37], buf[58], buf[16], 4);
        b64_from_24bit (buf[59], buf[17], buf[38], 4);
        b64_from_24bit (buf[18], buf[39], buf[60], 4);
        b64_from_24bit (buf[40], buf[61], buf[19], 4);
        b64_from_24bit (buf[62], buf[20], buf[41], 4);
        b64_from_24bit (0, 0, buf[63], 2);
        break;
    default:
        goto err;
    }
    *cp = '\0';
#ifdef CHARSET_EBCDIC
    ascii2ebcdic(out_buf, out_buf, strlen(out_buf));
#endif

    return out_buf;

 err:
    EVP_MD_CTX_free(md2);
    EVP_MD_CTX_free(md);
    OPENSSL_free(p_bytes);
    OPENSSL_free(s_bytes);
    OPENSSL_free(ascii_passwd);
    return NULL;
}

__attribute__((used)) static int do_passwd(int passed_salt, char **salt_p, char **salt_malloc_p,
                     char *passwd, BIO *out, int quiet, int table,
                     int reverse, size_t pw_maxlen, passwd_modes mode)
{
    char *hash = NULL;

    assert(salt_p != NULL);
    assert(salt_malloc_p != NULL);

    /* first make sure we have a salt */
    if (!passed_salt) {
        size_t saltlen = 0;
        size_t i;

#ifndef OPENSSL_NO_DES
        if (mode == passwd_crypt)
            saltlen = 2;
#endif                         /* !OPENSSL_NO_DES */

        if (mode == passwd_md5 || mode == passwd_apr1 || mode == passwd_aixmd5)
            saltlen = 8;

        if (mode == passwd_sha256 || mode == passwd_sha512)
            saltlen = 16;

        assert(saltlen != 0);

        if (*salt_malloc_p == NULL)
            *salt_p = *salt_malloc_p = app_malloc(saltlen + 1, "salt buffer");
        if (RAND_bytes((unsigned char *)*salt_p, saltlen) <= 0)
            goto end;

        for (i = 0; i < saltlen; i++)
            (*salt_p)[i] = cov_2char[(*salt_p)[i] & 0x3f]; /* 6 bits */
        (*salt_p)[i] = 0;
# ifdef CHARSET_EBCDIC
        /* The password encryption funtion will convert back to ASCII */
        ascii2ebcdic(*salt_p, *salt_p, saltlen);
# endif
    }

    assert(*salt_p != NULL);

    /* truncate password if necessary */
    if ((strlen(passwd) > pw_maxlen)) {
        if (!quiet)
            /*
             * XXX: really we should know how to print a size_t, not cast it
             */
            BIO_printf(bio_err,
                       "Warning: truncating password to %u characters\n",
                       (unsigned)pw_maxlen);
        passwd[pw_maxlen] = 0;
    }
    assert(strlen(passwd) <= pw_maxlen);

    /* now compute password hash */
#ifndef OPENSSL_NO_DES
    if (mode == passwd_crypt)
        hash = DES_crypt(passwd, *salt_p);
#endif
    if (mode == passwd_md5 || mode == passwd_apr1)
        hash = md5crypt(passwd, (mode == passwd_md5 ? "1" : "apr1"), *salt_p);
    if (mode == passwd_aixmd5)
        hash = md5crypt(passwd, "", *salt_p);
    if (mode == passwd_sha256 || mode == passwd_sha512)
        hash = shacrypt(passwd, (mode == passwd_sha256 ? "5" : "6"), *salt_p);
    assert(hash != NULL);

    if (table && !reverse)
        BIO_printf(out, "%s\t%s\n", passwd, hash);
    else if (table && reverse)
        BIO_printf(out, "%s\t%s\n", hash, passwd);
    else
        BIO_printf(out, "%s\n", hash);
    return 1;

 end:
    return 0;
}

