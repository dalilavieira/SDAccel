#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_54__   TYPE_8__ ;
typedef  struct TYPE_53__   TYPE_7__ ;
typedef  struct TYPE_52__   TYPE_6__ ;
typedef  struct TYPE_51__   TYPE_5__ ;
typedef  struct TYPE_50__   TYPE_4__ ;
typedef  struct TYPE_49__   TYPE_3__ ;
typedef  struct TYPE_48__   TYPE_2__ ;
typedef  struct TYPE_47__   TYPE_26__ ;
typedef  struct TYPE_46__   TYPE_1__ ;
typedef  struct TYPE_45__   TYPE_11__ ;

/* Type definitions */
struct stat {int dummy; } ;
struct TYPE_47__ {TYPE_6__* crl; TYPE_7__* x509; } ;
struct TYPE_50__ {TYPE_26__ data; scalar_t__ type; } ;
typedef  TYPE_4__ X509_OBJECT ;
typedef  int /*<<< orphan*/  X509_NAME ;
typedef  scalar_t__ X509_LOOKUP_TYPE ;
typedef  int /*<<< orphan*/  X509_LOOKUP_METHOD ;
struct TYPE_51__ {TYPE_3__* store_ctx; TYPE_8__* method_data; } ;
typedef  TYPE_5__ X509_LOOKUP ;
struct TYPE_48__ {int /*<<< orphan*/ * issuer; } ;
struct TYPE_52__ {TYPE_2__ crl; } ;
typedef  TYPE_6__ X509_CRL ;
struct TYPE_46__ {int /*<<< orphan*/ * subject; } ;
struct TYPE_53__ {TYPE_1__ cert_info; } ;
typedef  TYPE_7__ X509 ;
struct TYPE_54__ {scalar_t__ hash; int dir_type; int suffix; int /*<<< orphan*/ * lock; int /*<<< orphan*/ * hashes; struct TYPE_54__* dir; int /*<<< orphan*/ * dirs; TYPE_11__* buffer; } ;
struct TYPE_49__ {int /*<<< orphan*/  objs; } ;
struct TYPE_45__ {int /*<<< orphan*/  data; int /*<<< orphan*/  max; } ;
typedef  TYPE_8__ BY_DIR_HASH ;
typedef  TYPE_8__ BY_DIR_ENTRY ;
typedef  TYPE_8__ BY_DIR ;
typedef  TYPE_11__ BUF_MEM ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,TYPE_8__*,char,...) ; 
 int /*<<< orphan*/  BUF_MEM_free (TYPE_11__*) ; 
 int /*<<< orphan*/  BUF_MEM_grow (TYPE_11__*,int) ; 
 void* BUF_MEM_new () ; 
 int /*<<< orphan*/  CRYPTO_THREAD_lock_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CRYPTO_THREAD_lock_new () ; 
 int /*<<< orphan*/  CRYPTO_THREAD_read_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CRYPTO_THREAD_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CRYPTO_THREAD_write_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ERR_R_BUF_LIB ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  ERR_clear_error () ; 
 char const LIST_SEPARATOR_CHAR ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_8__*) ; 
 TYPE_8__* OPENSSL_malloc (int) ; 
 TYPE_8__* OPENSSL_strndup (char const*,size_t) ; 
 long X509_FILETYPE_DEFAULT ; 
 int X509_FILETYPE_PEM ; 
 int /*<<< orphan*/  X509_F_ADD_CERT_DIR ; 
 int /*<<< orphan*/  X509_F_DIR_CTRL ; 
 int /*<<< orphan*/  X509_F_GET_CERT_BY_SUBJECT ; 
 int /*<<< orphan*/  X509_F_NEW_DIR ; 
 scalar_t__ X509_LU_CRL ; 
 scalar_t__ X509_LU_X509 ; 
#define  X509_L_ADD_DIR 128 
 unsigned long X509_NAME_hash (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  X509_R_INVALID_DIRECTORY ; 
 int /*<<< orphan*/  X509_R_LOADING_CERT_DIR ; 
 int /*<<< orphan*/  X509_R_WRONG_LOOKUP_TYPE ; 
 char const* X509_get_default_cert_dir () ; 
 int /*<<< orphan*/  X509_get_default_cert_dir_env () ; 
 scalar_t__ X509_load_cert_file (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ X509_load_crl_file (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  X509err (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
static  int add_cert_dir (TYPE_8__*,char const*,int) ; 
 int /*<<< orphan*/  memcpy (TYPE_26__*,TYPE_26__*,int) ; 
 char* ossl_safe_getenv (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * sk_BY_DIR_ENTRY_new_null () ; 
 int sk_BY_DIR_ENTRY_num (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sk_BY_DIR_ENTRY_pop_free (int /*<<< orphan*/ *,void (*) (TYPE_8__*)) ; 
 int /*<<< orphan*/  sk_BY_DIR_ENTRY_push (int /*<<< orphan*/ *,TYPE_8__*) ; 
 TYPE_8__* sk_BY_DIR_ENTRY_value (int /*<<< orphan*/ *,int) ; 
 int sk_BY_DIR_HASH_find (int /*<<< orphan*/ *,TYPE_8__*) ; 
 int /*<<< orphan*/ * sk_BY_DIR_HASH_new (int (*) (TYPE_8__ const* const*,TYPE_8__ const* const*)) ; 
 int /*<<< orphan*/  sk_BY_DIR_HASH_pop_free (int /*<<< orphan*/ *,void (*) (TYPE_8__*)) ; 
 int /*<<< orphan*/  sk_BY_DIR_HASH_push (int /*<<< orphan*/ *,TYPE_8__*) ; 
 TYPE_8__* sk_BY_DIR_HASH_value (int /*<<< orphan*/ *,int) ; 
 int sk_X509_OBJECT_find (int /*<<< orphan*/ ,TYPE_4__*) ; 
 TYPE_4__* sk_X509_OBJECT_value (int /*<<< orphan*/ ,int) ; 
 scalar_t__ stat (int /*<<< orphan*/ ,struct stat*) ; 
 int strlen (TYPE_8__*) ; 
 scalar_t__ strncmp (TYPE_8__*,char const*,size_t) ; 
 int /*<<< orphan*/  x509_dir_lookup ; 

X509_LOOKUP_METHOD *X509_LOOKUP_hash_dir(void)
{
    return &x509_dir_lookup;
}

__attribute__((used)) static int dir_ctrl(X509_LOOKUP *ctx, int cmd, const char *argp, long argl,
                    char **retp)
{
    int ret = 0;
    BY_DIR *ld = (BY_DIR *)ctx->method_data;

    switch (cmd) {
    case X509_L_ADD_DIR:
        if (argl == X509_FILETYPE_DEFAULT) {
            const char *dir = ossl_safe_getenv(X509_get_default_cert_dir_env());

            if (dir)
                ret = add_cert_dir(ld, dir, X509_FILETYPE_PEM);
            else
                ret = add_cert_dir(ld, X509_get_default_cert_dir(),
                                   X509_FILETYPE_PEM);
            if (!ret) {
                X509err(X509_F_DIR_CTRL, X509_R_LOADING_CERT_DIR);
            }
        } else
            ret = add_cert_dir(ld, argp, (int)argl);
        break;
    }
    return ret;
}

__attribute__((used)) static int new_dir(X509_LOOKUP *lu)
{
    BY_DIR *a = OPENSSL_malloc(sizeof(*a));

    if (a == NULL) {
        X509err(X509_F_NEW_DIR, ERR_R_MALLOC_FAILURE);
        return 0;
    }

    if ((a->buffer = BUF_MEM_new()) == NULL) {
        X509err(X509_F_NEW_DIR, ERR_R_MALLOC_FAILURE);
        goto err;
    }
    a->dirs = NULL;
    a->lock = CRYPTO_THREAD_lock_new();
    if (a->lock == NULL) {
        BUF_MEM_free(a->buffer);
        X509err(X509_F_NEW_DIR, ERR_R_MALLOC_FAILURE);
        goto err;
    }
    lu->method_data = a;
    return 1;

 err:
    OPENSSL_free(a);
    return 0;
}

__attribute__((used)) static void by_dir_hash_free(BY_DIR_HASH *hash)
{
    OPENSSL_free(hash);
}

__attribute__((used)) static int by_dir_hash_cmp(const BY_DIR_HASH *const *a,
                           const BY_DIR_HASH *const *b)
{
    if ((*a)->hash > (*b)->hash)
        return 1;
    if ((*a)->hash < (*b)->hash)
        return -1;
    return 0;
}

__attribute__((used)) static void by_dir_entry_free(BY_DIR_ENTRY *ent)
{
    OPENSSL_free(ent->dir);
    sk_BY_DIR_HASH_pop_free(ent->hashes, by_dir_hash_free);
    OPENSSL_free(ent);
}

__attribute__((used)) static void free_dir(X509_LOOKUP *lu)
{
    BY_DIR *a = (BY_DIR *)lu->method_data;

    sk_BY_DIR_ENTRY_pop_free(a->dirs, by_dir_entry_free);
    BUF_MEM_free(a->buffer);
    CRYPTO_THREAD_lock_free(a->lock);
    OPENSSL_free(a);
}

__attribute__((used)) static int add_cert_dir(BY_DIR *ctx, const char *dir, int type)
{
    int j;
    size_t len;
    const char *s, *ss, *p;

    if (dir == NULL || !*dir) {
        X509err(X509_F_ADD_CERT_DIR, X509_R_INVALID_DIRECTORY);
        return 0;
    }

    s = dir;
    p = s;
    do {
        if ((*p == LIST_SEPARATOR_CHAR) || (*p == '\0')) {
            BY_DIR_ENTRY *ent;

            ss = s;
            s = p + 1;
            len = p - ss;
            if (len == 0)
                continue;
            for (j = 0; j < sk_BY_DIR_ENTRY_num(ctx->dirs); j++) {
                ent = sk_BY_DIR_ENTRY_value(ctx->dirs, j);
                if (strlen(ent->dir) == len && strncmp(ent->dir, ss, len) == 0)
                    break;
            }
            if (j < sk_BY_DIR_ENTRY_num(ctx->dirs))
                continue;
            if (ctx->dirs == NULL) {
                ctx->dirs = sk_BY_DIR_ENTRY_new_null();
                if (!ctx->dirs) {
                    X509err(X509_F_ADD_CERT_DIR, ERR_R_MALLOC_FAILURE);
                    return 0;
                }
            }
            ent = OPENSSL_malloc(sizeof(*ent));
            if (ent == NULL) {
                X509err(X509_F_ADD_CERT_DIR, ERR_R_MALLOC_FAILURE);
                return 0;
            }
            ent->dir_type = type;
            ent->hashes = sk_BY_DIR_HASH_new(by_dir_hash_cmp);
            ent->dir = OPENSSL_strndup(ss, len);
            if (ent->dir == NULL || ent->hashes == NULL) {
                by_dir_entry_free(ent);
                return 0;
            }
            if (!sk_BY_DIR_ENTRY_push(ctx->dirs, ent)) {
                by_dir_entry_free(ent);
                X509err(X509_F_ADD_CERT_DIR, ERR_R_MALLOC_FAILURE);
                return 0;
            }
        }
    } while (*p++ != '\0');
    return 1;
}

__attribute__((used)) static int get_cert_by_subject(X509_LOOKUP *xl, X509_LOOKUP_TYPE type,
                               X509_NAME *name, X509_OBJECT *ret)
{
    BY_DIR *ctx;
    union {
        X509 st_x509;
        X509_CRL crl;
    } data;
    int ok = 0;
    int i, j, k;
    unsigned long h;
    BUF_MEM *b = NULL;
    X509_OBJECT stmp, *tmp;
    const char *postfix = "";

    if (name == NULL)
        return 0;

    stmp.type = type;
    if (type == X509_LU_X509) {
        data.st_x509.cert_info.subject = name;
        stmp.data.x509 = &data.st_x509;
        postfix = "";
    } else if (type == X509_LU_CRL) {
        data.crl.crl.issuer = name;
        stmp.data.crl = &data.crl;
        postfix = "r";
    } else {
        X509err(X509_F_GET_CERT_BY_SUBJECT, X509_R_WRONG_LOOKUP_TYPE);
        goto finish;
    }

    if ((b = BUF_MEM_new()) == NULL) {
        X509err(X509_F_GET_CERT_BY_SUBJECT, ERR_R_BUF_LIB);
        goto finish;
    }

    ctx = (BY_DIR *)xl->method_data;

    h = X509_NAME_hash(name);
    for (i = 0; i < sk_BY_DIR_ENTRY_num(ctx->dirs); i++) {
        BY_DIR_ENTRY *ent;
        int idx;
        BY_DIR_HASH htmp, *hent;

        ent = sk_BY_DIR_ENTRY_value(ctx->dirs, i);
        j = strlen(ent->dir) + 1 + 8 + 6 + 1 + 1;
        if (!BUF_MEM_grow(b, j)) {
            X509err(X509_F_GET_CERT_BY_SUBJECT, ERR_R_MALLOC_FAILURE);
            goto finish;
        }
        if (type == X509_LU_CRL && ent->hashes) {
            htmp.hash = h;
            CRYPTO_THREAD_read_lock(ctx->lock);
            idx = sk_BY_DIR_HASH_find(ent->hashes, &htmp);
            if (idx >= 0) {
                hent = sk_BY_DIR_HASH_value(ent->hashes, idx);
                k = hent->suffix;
            } else {
                hent = NULL;
                k = 0;
            }
            CRYPTO_THREAD_unlock(ctx->lock);
        } else {
            k = 0;
            hent = NULL;
        }
        for (;;) {
            char c = '/';
#ifdef OPENSSL_SYS_VMS
            c = ent->dir[strlen(ent->dir) - 1];
            if (c != ':' && c != '>' && c != ']') {
                /*
                 * If no separator is present, we assume the directory
                 * specifier is a logical name, and add a colon.  We really
                 * should use better VMS routines for merging things like
                 * this, but this will do for now... -- Richard Levitte
                 */
                c = ':';
            } else {
                c = '\0';
            }
#endif
            if (c == '\0') {
                /*
                 * This is special.  When c == '\0', no directory separator
                 * should be added.
                 */
                BIO_snprintf(b->data, b->max,
                             "%s%08lx.%s%d", ent->dir, h, postfix, k);
            } else {
                BIO_snprintf(b->data, b->max,
                             "%s%c%08lx.%s%d", ent->dir, c, h, postfix, k);
            }
#ifndef OPENSSL_NO_POSIX_IO
# ifdef _WIN32
#  define stat _stat
# endif
            {
                struct stat st;
                if (stat(b->data, &st) < 0)
                    break;
            }
#endif
            /* found one. */
            if (type == X509_LU_X509) {
                if ((X509_load_cert_file(xl, b->data, ent->dir_type)) == 0)
                    break;
            } else if (type == X509_LU_CRL) {
                if ((X509_load_crl_file(xl, b->data, ent->dir_type)) == 0)
                    break;
            }
            /* else case will caught higher up */
            k++;
        }

        /*
         * we have added it to the cache so now pull it out again
         */
        CRYPTO_THREAD_write_lock(ctx->lock);
        j = sk_X509_OBJECT_find(xl->store_ctx->objs, &stmp);
        tmp = sk_X509_OBJECT_value(xl->store_ctx->objs, j);
        CRYPTO_THREAD_unlock(ctx->lock);

        /* If a CRL, update the last file suffix added for this */

        if (type == X509_LU_CRL) {
            CRYPTO_THREAD_write_lock(ctx->lock);
            /*
             * Look for entry again in case another thread added an entry
             * first.
             */
            if (hent == NULL) {
                htmp.hash = h;
                idx = sk_BY_DIR_HASH_find(ent->hashes, &htmp);
                hent = sk_BY_DIR_HASH_value(ent->hashes, idx);
            }
            if (hent == NULL) {
                hent = OPENSSL_malloc(sizeof(*hent));
                if (hent == NULL) {
                    CRYPTO_THREAD_unlock(ctx->lock);
                    X509err(X509_F_GET_CERT_BY_SUBJECT, ERR_R_MALLOC_FAILURE);
                    ok = 0;
                    goto finish;
                }
                hent->hash = h;
                hent->suffix = k;
                if (!sk_BY_DIR_HASH_push(ent->hashes, hent)) {
                    CRYPTO_THREAD_unlock(ctx->lock);
                    OPENSSL_free(hent);
                    X509err(X509_F_GET_CERT_BY_SUBJECT, ERR_R_MALLOC_FAILURE);
                    ok = 0;
                    goto finish;
                }
            } else if (hent->suffix < k) {
                hent->suffix = k;
            }

            CRYPTO_THREAD_unlock(ctx->lock);

        }

        if (tmp != NULL) {
            ok = 1;
            ret->type = tmp->type;
            memcpy(&ret->data, &tmp->data, sizeof(ret->data));

            /*
             * Clear any errors that might have been raised processing empty
             * or malformed files.
             */
            ERR_clear_error();

            goto finish;
        }
    }
 finish:
    BUF_MEM_free(b);
    return ok;
}

