#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  t ;
struct drbg_kat_pr_true {int /*<<< orphan*/  retbytes; int /*<<< orphan*/  addin2; scalar_t__ entropyinpr2; int /*<<< orphan*/  addin1; scalar_t__ entropyinpr1; int /*<<< orphan*/  persstr; scalar_t__ entropyin; scalar_t__ nonce; } ;
struct drbg_kat_pr_false {int /*<<< orphan*/  retbytes; int /*<<< orphan*/  addin2; int /*<<< orphan*/  addin1; int /*<<< orphan*/  addinreseed; scalar_t__ entropyinreseed; int /*<<< orphan*/  persstr; scalar_t__ nonce; scalar_t__ entropyin; } ;
struct drbg_kat_no_reseed {int /*<<< orphan*/  retbytes; int /*<<< orphan*/  addin2; int /*<<< orphan*/  addin1; int /*<<< orphan*/  persstr; scalar_t__ nonce; scalar_t__ entropyin; } ;
struct drbg_kat {int flags; size_t entropyinlen; size_t noncelen; int type; int /*<<< orphan*/  retbyteslen; int /*<<< orphan*/  addinlen; int /*<<< orphan*/  persstrlen; int /*<<< orphan*/  nid; scalar_t__ t; } ;
struct TYPE_4__ {size_t entropylen; size_t noncelen; scalar_t__ entropy; scalar_t__ nonce; int /*<<< orphan*/  noncecnt; int /*<<< orphan*/  entropycnt; } ;
typedef  TYPE_1__ TEST_CTX ;
typedef  int /*<<< orphan*/  RAND_DRBG ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_ALL_TESTS (int (*) (int),int /*<<< orphan*/ ) ; 
#define  NO_RESEED 130 
 int /*<<< orphan*/  OPENSSL_free (unsigned char*) ; 
 unsigned char* OPENSSL_malloc (int /*<<< orphan*/ ) ; 
#define  PR_FALSE 129 
#define  PR_TRUE 128 
 unsigned int RAND_DRBG_FLAG_CTR_NO_DF ; 
 unsigned int RAND_DRBG_FLAG_HMAC ; 
 int /*<<< orphan*/  RAND_DRBG_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RAND_DRBG_generate (int /*<<< orphan*/ *,unsigned char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ RAND_DRBG_get_ex_data (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RAND_DRBG_get_ex_new_index (long,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RAND_DRBG_instantiate (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * RAND_DRBG_new (int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RAND_DRBG_reseed (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RAND_DRBG_set_callbacks (int /*<<< orphan*/ *,size_t (*) (int /*<<< orphan*/ *,unsigned char**,int,size_t,size_t,int),int /*<<< orphan*/ *,size_t (*) (int /*<<< orphan*/ *,unsigned char**,int,size_t,size_t),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RAND_DRBG_set_ex_data (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  RAND_DRBG_uninstantiate (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TEST_mem_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_ptr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TEST_true (int /*<<< orphan*/ ) ; 
 int USE_DF ; 
 int USE_HMAC ; 
 int /*<<< orphan*/  app_data_index ; 
 int /*<<< orphan*/  drbg_ctr_nelem ; 
 struct drbg_kat** drbg_ctr_test ; 
 int /*<<< orphan*/  drbg_hash_nelem ; 
 struct drbg_kat** drbg_hash_test ; 
 int /*<<< orphan*/  drbg_hmac_nelem ; 
 struct drbg_kat** drbg_hmac_test ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static size_t kat_entropy(RAND_DRBG *drbg, unsigned char **pout,
                          int entropy, size_t min_len, size_t max_len,
                          int prediction_resistance)
{
    TEST_CTX *t = (TEST_CTX *)RAND_DRBG_get_ex_data(drbg, app_data_index);

    t->entropycnt++;
    *pout = (unsigned char *)t->entropy;
    return t->entropylen;
}

__attribute__((used)) static size_t kat_nonce(RAND_DRBG *drbg, unsigned char **pout,
                        int entropy, size_t min_len, size_t max_len)
{
    TEST_CTX *t = (TEST_CTX *)RAND_DRBG_get_ex_data(drbg, app_data_index);

    t->noncecnt++;
    *pout = (unsigned char *)t->nonce;
    return t->noncelen;
}

__attribute__((used)) static int single_kat_no_reseed(const struct drbg_kat *td)
{
    struct drbg_kat_no_reseed *data = (struct drbg_kat_no_reseed *)td->t;
    RAND_DRBG *drbg = NULL;
    unsigned char *buff = NULL;
    unsigned int flags = 0;
    int failures = 0;
    TEST_CTX t;

    if ((td->flags & USE_DF) == 0)
        flags |= RAND_DRBG_FLAG_CTR_NO_DF;
    if ((td->flags & USE_HMAC) != 0)
        flags |= RAND_DRBG_FLAG_HMAC;

    if (!TEST_ptr(drbg = RAND_DRBG_new(td->nid, flags, NULL)))
        return 0;

    if (!TEST_true(RAND_DRBG_set_callbacks(drbg, kat_entropy, NULL,
                                           kat_nonce, NULL))) {
        failures++;
        goto err;
    }
    memset(&t, 0, sizeof(t));
    t.entropy = data->entropyin;
    t.entropylen = td->entropyinlen;
    t.nonce = data->nonce;
    t.noncelen = td->noncelen;
    RAND_DRBG_set_ex_data(drbg, app_data_index, &t);

    buff = OPENSSL_malloc(td->retbyteslen);
    if (buff == NULL)
        goto err;

    if (!TEST_true(RAND_DRBG_instantiate(drbg, data->persstr, td->persstrlen))
        || !TEST_true(RAND_DRBG_generate(drbg, buff, td->retbyteslen, 0,
                                         data->addin1, td->addinlen))
        || !TEST_true(RAND_DRBG_generate(drbg, buff, td->retbyteslen, 0,
                                         data->addin2, td->addinlen))
        || !TEST_true(RAND_DRBG_uninstantiate(drbg))
        || !TEST_mem_eq(data->retbytes, td->retbyteslen, buff,
                        td->retbyteslen))
        failures++;

err:
    OPENSSL_free(buff);
    RAND_DRBG_uninstantiate(drbg);
    RAND_DRBG_free(drbg);
    return failures == 0;
}

__attribute__((used)) static int single_kat_pr_false(const struct drbg_kat *td)
{
    struct drbg_kat_pr_false *data = (struct drbg_kat_pr_false *)td->t;
    RAND_DRBG *drbg = NULL;
    unsigned char *buff = NULL;
    unsigned int flags = 0;
    int failures = 0;
    TEST_CTX t;

    if ((td->flags & USE_DF) == 0)
        flags |= RAND_DRBG_FLAG_CTR_NO_DF;
    if ((td->flags & USE_HMAC) != 0)
        flags |= RAND_DRBG_FLAG_HMAC;

    if (!TEST_ptr(drbg = RAND_DRBG_new(td->nid, flags, NULL)))
        return 0;

    if (!TEST_true(RAND_DRBG_set_callbacks(drbg, kat_entropy, NULL,
                                           kat_nonce, NULL))) {
        failures++;
        goto err;
    }
    memset(&t, 0, sizeof(t));
    t.entropy = data->entropyin;
    t.entropylen = td->entropyinlen;
    t.nonce = data->nonce;
    t.noncelen = td->noncelen;
    RAND_DRBG_set_ex_data(drbg, app_data_index, &t);

    buff = OPENSSL_malloc(td->retbyteslen);
    if (buff == NULL)
        goto err;

    if (!TEST_true(RAND_DRBG_instantiate(drbg, data->persstr, td->persstrlen)))
        failures++;

    t.entropy = data->entropyinreseed;
    t.entropylen = td->entropyinlen;

    if (!TEST_true(RAND_DRBG_reseed(drbg, data->addinreseed, td->addinlen, 0))
        || !TEST_true(RAND_DRBG_generate(drbg, buff, td->retbyteslen, 0,
                                         data->addin1, td->addinlen))
        || !TEST_true(RAND_DRBG_generate(drbg, buff, td->retbyteslen, 0,
                                         data->addin2, td->addinlen))
        || !TEST_true(RAND_DRBG_uninstantiate(drbg))
        || !TEST_mem_eq(data->retbytes, td->retbyteslen, buff,
                        td->retbyteslen))
        failures++;

err:
    OPENSSL_free(buff);
    RAND_DRBG_uninstantiate(drbg);
    RAND_DRBG_free(drbg);
    return failures == 0;
}

__attribute__((used)) static int single_kat_pr_true(const struct drbg_kat *td)
{
    struct drbg_kat_pr_true *data = (struct drbg_kat_pr_true *)td->t;
    RAND_DRBG *drbg = NULL;
    unsigned char *buff = NULL;
    unsigned int flags = 0;
    int failures = 0;
    TEST_CTX t;

    if ((td->flags & USE_DF) == 0)
        flags |= RAND_DRBG_FLAG_CTR_NO_DF;
    if ((td->flags & USE_HMAC) != 0)
        flags |= RAND_DRBG_FLAG_HMAC;

    if (!TEST_ptr(drbg = RAND_DRBG_new(td->nid, flags, NULL)))
        return 0;

    if (!TEST_true(RAND_DRBG_set_callbacks(drbg, kat_entropy, NULL,
                                           kat_nonce, NULL))) {
        failures++;
        goto err;
    }
    memset(&t, 0, sizeof(t));
    t.nonce = data->nonce;
    t.noncelen = td->noncelen;
    t.entropy = data->entropyin;
    t.entropylen = td->entropyinlen;
    RAND_DRBG_set_ex_data(drbg, app_data_index, &t);

    buff = OPENSSL_malloc(td->retbyteslen);
    if (buff == NULL)
        goto err;

    if (!TEST_true(RAND_DRBG_instantiate(drbg, data->persstr, td->persstrlen)))
        failures++;

    t.entropy = data->entropyinpr1;
    t.entropylen = td->entropyinlen;

    if (!TEST_true(RAND_DRBG_generate(drbg, buff, td->retbyteslen, 1,
                                      data->addin1, td->addinlen)))
        failures++;

    t.entropy = data->entropyinpr2;
    t.entropylen = td->entropyinlen;

    if (!TEST_true(RAND_DRBG_generate(drbg, buff, td->retbyteslen, 1,
                                      data->addin2, td->addinlen))
        || !TEST_true(RAND_DRBG_uninstantiate(drbg))
        || !TEST_mem_eq(data->retbytes, td->retbyteslen, buff,
                        td->retbyteslen))
        failures++;

err:
    OPENSSL_free(buff);
    RAND_DRBG_uninstantiate(drbg);
    RAND_DRBG_free(drbg);
    return failures == 0;
}

__attribute__((used)) static int test_cavs_kats(const struct drbg_kat *test[], int i)
{
    const struct drbg_kat *td = test[i];
    int rv = 0;

#ifdef FIPS_MODE
    /* FIPS mode doesn't support instantiating without a derivation function */
    if ((td->flags & USE_DF) == 0)
        return 1;
#endif
    switch (td->type) {
    case NO_RESEED:
        if (!single_kat_no_reseed(td))
            goto err;
        break;
    case PR_FALSE:
        if (!single_kat_pr_false(td))
            goto err;
        break;
    case PR_TRUE:
        if (!single_kat_pr_true(td))
            goto err;
        break;
    default:	/* cant happen */
        goto err;
    }
    rv = 1;
err:
    return rv;
}

__attribute__((used)) static int test_cavs_ctr(int i)
{
    return test_cavs_kats(drbg_ctr_test, i);
}

__attribute__((used)) static int test_cavs_hmac(int i)
{
    return test_cavs_kats(drbg_hmac_test, i);
}

__attribute__((used)) static int test_cavs_hash(int i)
{
    return test_cavs_kats(drbg_hash_test, i);
}

int setup_tests(void)
{
    app_data_index = RAND_DRBG_get_ex_new_index(0L, NULL, NULL, NULL, NULL);

    ADD_ALL_TESTS(test_cavs_ctr,  drbg_ctr_nelem);
    ADD_ALL_TESTS(test_cavs_hmac, drbg_hmac_nelem);
    ADD_ALL_TESTS(test_cavs_hash, drbg_hash_nelem);

    return 1;
}

