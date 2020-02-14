#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_7__ ;
typedef  struct TYPE_35__   TYPE_4__ ;
typedef  struct TYPE_34__   TYPE_1__ ;

/* Type definitions */
struct doall_md {void (* fn ) (TYPE_1__ const*,char const*,char const*,void*) ;void* arg; } ;
struct doall_mac {void (* fn ) (TYPE_1__ const*,char const*,char const*,void*) ;void* arg; } ;
struct doall_cipher {void (* fn ) (TYPE_1__ const*,char const*,char const*,void*) ;void* arg; } ;
struct TYPE_36__ {scalar_t__ type; } ;
struct TYPE_35__ {char const* name; char const* data; scalar_t__ alias; } ;
struct TYPE_34__ {scalar_t__ nid; scalar_t__ type; scalar_t__ pkey_type; } ;
typedef  TYPE_4__ OBJ_NAME ;
typedef  TYPE_1__ EVP_MD ;
typedef  TYPE_1__ EVP_MAC ;
typedef  TYPE_7__ EVP_KDF ;
typedef  TYPE_1__ EVP_CIPHER ;

/* Variables and functions */
 int /*<<< orphan*/  EVP_PBE_cleanup () ; 
 int OBJ_NAME_ALIAS ; 
 int OBJ_NAME_TYPE_CIPHER_METH ; 
 int OBJ_NAME_TYPE_KDF_METH ; 
 int OBJ_NAME_TYPE_MAC_METH ; 
 int OBJ_NAME_TYPE_MD_METH ; 
 int OBJ_NAME_add (char const*,int,char const*) ; 
 int /*<<< orphan*/  OBJ_NAME_cleanup (int) ; 
 int /*<<< orphan*/  OBJ_NAME_do_all (int,void (*) (TYPE_4__ const*,void*),struct doall_md*) ; 
 int /*<<< orphan*/  OBJ_NAME_do_all_sorted (int,void (*) (TYPE_4__ const*,void*),struct doall_md*) ; 
 scalar_t__ OBJ_NAME_get (char const*,int) ; 
 char const* OBJ_nid2ln (scalar_t__) ; 
 char const* OBJ_nid2sn (scalar_t__) ; 
 int /*<<< orphan*/  OBJ_sigid_free () ; 
 int /*<<< orphan*/  OPENSSL_INIT_ADD_ALL_CIPHERS ; 
 int /*<<< orphan*/  OPENSSL_INIT_ADD_ALL_DIGESTS ; 
 int /*<<< orphan*/  OPENSSL_INIT_ADD_ALL_KDFS ; 
 int /*<<< orphan*/  OPENSSL_INIT_ADD_ALL_MACS ; 
 int /*<<< orphan*/  OPENSSL_init_crypto (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  evp_app_cleanup_int () ; 
 void stub1 (TYPE_1__ const*,char const*,char const*,void*) ; 
 void stub2 (TYPE_1__ const*,char const*,char const*,void*) ; 
 void stub3 (TYPE_1__ const*,char const*,char const*,void*) ; 
 void stub4 (TYPE_1__ const*,char const*,char const*,void*) ; 
 void stub5 (TYPE_1__ const*,char const*,char const*,void*) ; 
 void stub6 (TYPE_1__ const*,char const*,char const*,void*) ; 

int EVP_add_cipher(const EVP_CIPHER *c)
{
    int r;

    if (c == NULL)
        return 0;

    r = OBJ_NAME_add(OBJ_nid2sn(c->nid), OBJ_NAME_TYPE_CIPHER_METH,
                     (const char *)c);
    if (r == 0)
        return 0;
    r = OBJ_NAME_add(OBJ_nid2ln(c->nid), OBJ_NAME_TYPE_CIPHER_METH,
                     (const char *)c);
    return r;
}

int EVP_add_digest(const EVP_MD *md)
{
    int r;
    const char *name;

    name = OBJ_nid2sn(md->type);
    r = OBJ_NAME_add(name, OBJ_NAME_TYPE_MD_METH, (const char *)md);
    if (r == 0)
        return 0;
    r = OBJ_NAME_add(OBJ_nid2ln(md->type), OBJ_NAME_TYPE_MD_METH,
                     (const char *)md);
    if (r == 0)
        return 0;

    if (md->pkey_type && md->type != md->pkey_type) {
        r = OBJ_NAME_add(OBJ_nid2sn(md->pkey_type),
                         OBJ_NAME_TYPE_MD_METH | OBJ_NAME_ALIAS, name);
        if (r == 0)
            return 0;
        r = OBJ_NAME_add(OBJ_nid2ln(md->pkey_type),
                         OBJ_NAME_TYPE_MD_METH | OBJ_NAME_ALIAS, name);
    }
    return r;
}

int EVP_add_mac(const EVP_MAC *m)
{
    int r;

    if (m == NULL)
        return 0;

    r = OBJ_NAME_add(OBJ_nid2sn(m->type), OBJ_NAME_TYPE_MAC_METH,
                     (const char *)m);
    if (r == 0)
        return 0;
    r = OBJ_NAME_add(OBJ_nid2ln(m->type), OBJ_NAME_TYPE_MAC_METH,
                     (const char *)m);
    return r;
}

int EVP_add_kdf(const EVP_KDF *k)
{
    int r;

    if (k == NULL)
        return 0;

    r = OBJ_NAME_add(OBJ_nid2sn(k->type), OBJ_NAME_TYPE_KDF_METH,
                     (const char *)k);
    if (r == 0)
        return 0;
    r = OBJ_NAME_add(OBJ_nid2ln(k->type), OBJ_NAME_TYPE_KDF_METH,
                     (const char *)k);
    return r;
}

const EVP_CIPHER *EVP_get_cipherbyname(const char *name)
{
    const EVP_CIPHER *cp;

    if (!OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS, NULL))
        return NULL;

    cp = (const EVP_CIPHER *)OBJ_NAME_get(name, OBJ_NAME_TYPE_CIPHER_METH);
    return cp;
}

const EVP_MD *EVP_get_digestbyname(const char *name)
{
    const EVP_MD *cp;

    if (!OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_DIGESTS, NULL))
        return NULL;

    cp = (const EVP_MD *)OBJ_NAME_get(name, OBJ_NAME_TYPE_MD_METH);
    return cp;
}

const EVP_MAC *EVP_get_macbyname(const char *name)
{
    const EVP_MAC *mp;

    if (!OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_MACS, NULL))
        return NULL;

    mp = (const EVP_MAC *)OBJ_NAME_get(name, OBJ_NAME_TYPE_MAC_METH);
    return mp;
}

const EVP_KDF *EVP_get_kdfbyname(const char *name)
{
    const EVP_KDF *kdf;

    if (!OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_KDFS, NULL))
        return NULL;

    kdf = (const EVP_KDF *)OBJ_NAME_get(name, OBJ_NAME_TYPE_KDF_METH);
    return kdf;
}

void evp_cleanup_int(void)
{
    OBJ_NAME_cleanup(OBJ_NAME_TYPE_MAC_METH);
    OBJ_NAME_cleanup(OBJ_NAME_TYPE_KDF_METH);
    OBJ_NAME_cleanup(OBJ_NAME_TYPE_CIPHER_METH);
    OBJ_NAME_cleanup(OBJ_NAME_TYPE_MD_METH);
    /*
     * The above calls will only clean out the contents of the name hash
     * table, but not the hash table itself.  The following line does that
     * part.  -- Richard Levitte
     */
    OBJ_NAME_cleanup(-1);

    EVP_PBE_cleanup();
    OBJ_sigid_free();

    evp_app_cleanup_int();
}

__attribute__((used)) static void do_all_cipher_fn(const OBJ_NAME *nm, void *arg)
{
    struct doall_cipher *dc = arg;
    if (nm->alias)
        dc->fn(NULL, nm->name, nm->data, dc->arg);
    else
        dc->fn((const EVP_CIPHER *)nm->data, nm->name, NULL, dc->arg);
}

void EVP_CIPHER_do_all(void (*fn) (const EVP_CIPHER *ciph,
                                   const char *from, const char *to, void *x),
                       void *arg)
{
    struct doall_cipher dc;

    /* Ignore errors */
    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS, NULL);

    dc.fn = fn;
    dc.arg = arg;
    OBJ_NAME_do_all(OBJ_NAME_TYPE_CIPHER_METH, do_all_cipher_fn, &dc);
}

void EVP_CIPHER_do_all_sorted(void (*fn) (const EVP_CIPHER *ciph,
                                          const char *from, const char *to,
                                          void *x), void *arg)
{
    struct doall_cipher dc;

    /* Ignore errors */
    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS, NULL);

    dc.fn = fn;
    dc.arg = arg;
    OBJ_NAME_do_all_sorted(OBJ_NAME_TYPE_CIPHER_METH, do_all_cipher_fn, &dc);
}

__attribute__((used)) static void do_all_md_fn(const OBJ_NAME *nm, void *arg)
{
    struct doall_md *dc = arg;
    if (nm->alias)
        dc->fn(NULL, nm->name, nm->data, dc->arg);
    else
        dc->fn((const EVP_MD *)nm->data, nm->name, NULL, dc->arg);
}

void EVP_MD_do_all(void (*fn) (const EVP_MD *md,
                               const char *from, const char *to, void *x),
                   void *arg)
{
    struct doall_md dc;

    /* Ignore errors */
    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_DIGESTS, NULL);

    dc.fn = fn;
    dc.arg = arg;
    OBJ_NAME_do_all(OBJ_NAME_TYPE_MD_METH, do_all_md_fn, &dc);
}

void EVP_MD_do_all_sorted(void (*fn) (const EVP_MD *md,
                                      const char *from, const char *to,
                                      void *x), void *arg)
{
    struct doall_md dc;

    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_DIGESTS, NULL);

    dc.fn = fn;
    dc.arg = arg;
    OBJ_NAME_do_all_sorted(OBJ_NAME_TYPE_MD_METH, do_all_md_fn, &dc);
}

__attribute__((used)) static void do_all_mac_fn(const OBJ_NAME *nm, void *arg)
{
    struct doall_mac *dc = arg;

    if (nm->alias)
        dc->fn(NULL, nm->name, nm->data, dc->arg);
    else
        dc->fn((const EVP_MAC *)nm->data, nm->name, NULL, dc->arg);
}

void EVP_MAC_do_all(void (*fn)
                    (const EVP_MAC *ciph, const char *from, const char *to,
                     void *x), void *arg)
{
    struct doall_mac dc;

    /* Ignore errors */
    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_MACS, NULL);

    dc.fn = fn;
    dc.arg = arg;
    OBJ_NAME_do_all(OBJ_NAME_TYPE_MAC_METH, do_all_mac_fn, &dc);
}

void EVP_MAC_do_all_sorted(void (*fn)
                           (const EVP_MAC *ciph, const char *from,
                            const char *to, void *x), void *arg)
{
    struct doall_mac dc;

    /* Ignore errors */
    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_MACS, NULL);

    dc.fn = fn;
    dc.arg = arg;
    OBJ_NAME_do_all_sorted(OBJ_NAME_TYPE_MAC_METH, do_all_mac_fn, &dc);
}

