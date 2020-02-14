#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_99__   TYPE_43__ ;
typedef  struct TYPE_98__   TYPE_3__ ;
typedef  struct TYPE_97__   TYPE_2__ ;
typedef  struct TYPE_96__   TYPE_1__ ;

/* Type definitions */
typedef  void* point_conversion_form_t ;
struct TYPE_99__ {scalar_t__ (* keycopy ) (TYPE_2__*,TYPE_2__ const*) ;int (* keygen ) (TYPE_2__*) ;int (* keycheck ) (TYPE_2__ const*) ;scalar_t__ (* set_private ) (TYPE_2__*,int /*<<< orphan*/  const*) ;int flags; size_t (* priv2oct ) (TYPE_2__ const*,unsigned char*,size_t) ;int (* oct2priv ) (TYPE_2__*,unsigned char const*,size_t) ;int /*<<< orphan*/  (* keyfinish ) (TYPE_2__*) ;} ;
struct TYPE_98__ {TYPE_43__* meth; int /*<<< orphan*/  const* order; int /*<<< orphan*/  const* field; } ;
struct TYPE_97__ {unsigned int enc_flag; void* conv_form; int flags; TYPE_3__ const* group; int /*<<< orphan*/  const* priv_key; int /*<<< orphan*/  const* pub_key; TYPE_1__* meth; int /*<<< orphan*/ * engine; int /*<<< orphan*/  lock; int /*<<< orphan*/  references; int /*<<< orphan*/  ex_data; int /*<<< orphan*/  version; } ;
struct TYPE_96__ {scalar_t__ (* set_group ) (TYPE_2__*,TYPE_3__ const*) ;scalar_t__ (* copy ) (TYPE_2__*,TYPE_2__ const*) ;int (* keygen ) (TYPE_2__*) ;scalar_t__ (* set_private ) (TYPE_2__*,int /*<<< orphan*/  const*) ;scalar_t__ (* set_public ) (TYPE_2__*,int /*<<< orphan*/  const*) ;int /*<<< orphan*/  (* finish ) (TYPE_2__*) ;} ;
typedef  int /*<<< orphan*/  ENGINE ;
typedef  int /*<<< orphan*/  const EC_POINT ;
typedef  int /*<<< orphan*/  EC_METHOD ;
typedef  TYPE_2__ EC_KEY ;
typedef  TYPE_3__ const EC_GROUP ;
typedef  int /*<<< orphan*/  BN_CTX ;
typedef  int /*<<< orphan*/  const BIGNUM ;

/* Variables and functions */
 int /*<<< orphan*/  BN_CTX_end (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BN_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* BN_CTX_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * BN_CTX_new () ; 
 int /*<<< orphan*/  BN_CTX_start (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* BN_bin2bn (unsigned char const*,size_t,int /*<<< orphan*/  const*) ; 
 int BN_bn2binpad (int /*<<< orphan*/  const*,unsigned char*,size_t) ; 
 int /*<<< orphan*/  BN_clear (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BN_clear_free (int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_cmp (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BN_copy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* BN_dup (int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_is_negative (int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_is_zero (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* BN_new () ; 
 int BN_num_bits (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BN_priv_rand_range (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 void* BN_secure_new () ; 
 int /*<<< orphan*/  const* BN_value_one () ; 
 int /*<<< orphan*/  CRYPTO_DOWN_REF (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRYPTO_EX_INDEX_EC_KEY ; 
 int /*<<< orphan*/  CRYPTO_THREAD_lock_free (int /*<<< orphan*/ ) ; 
 scalar_t__ CRYPTO_UP_REF (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRYPTO_dup_ex_data (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CRYPTO_free_ex_data (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ *) ; 
 int EC_FLAGS_CUSTOM_CURVE ; 
 int EC_FLAGS_NO_SIGN ; 
 int /*<<< orphan*/  EC_F_EC_KEY_CHECK_KEY ; 
 int /*<<< orphan*/  EC_F_EC_KEY_COPY ; 
 int /*<<< orphan*/  EC_F_EC_KEY_GENERATE_KEY ; 
 int /*<<< orphan*/  EC_F_EC_KEY_OCT2PRIV ; 
 int /*<<< orphan*/  EC_F_EC_KEY_PRIV2BUF ; 
 int /*<<< orphan*/  EC_F_EC_KEY_PRIV2OCT ; 
 int /*<<< orphan*/  EC_F_EC_KEY_SET_PUBLIC_KEY_AFFINE_COORDINATES ; 
 int /*<<< orphan*/  EC_F_EC_KEY_SIMPLE_CHECK_KEY ; 
 int /*<<< orphan*/  EC_F_EC_KEY_SIMPLE_OCT2PRIV ; 
 int /*<<< orphan*/  EC_F_EC_KEY_SIMPLE_PRIV2OCT ; 
 int /*<<< orphan*/  EC_GROUP_copy (TYPE_3__ const*,TYPE_3__ const*) ; 
 TYPE_3__ const* EC_GROUP_dup (TYPE_3__ const*) ; 
 int /*<<< orphan*/  EC_GROUP_free (TYPE_3__ const*) ; 
 int /*<<< orphan*/  const* EC_GROUP_get0_order (TYPE_3__ const*) ; 
 int EC_GROUP_get_degree (TYPE_3__ const*) ; 
 int /*<<< orphan*/ * EC_GROUP_method_of (TYPE_3__ const*) ; 
 TYPE_3__ const* EC_GROUP_new (int /*<<< orphan*/  const*) ; 
 TYPE_3__ const* EC_GROUP_new_by_curve_name (int) ; 
 int EC_GROUP_order_bits (TYPE_3__ const*) ; 
 int EC_GROUP_precompute_mult (TYPE_3__ const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EC_GROUP_set_asn1_flag (TYPE_3__ const*,int) ; 
 int /*<<< orphan*/  EC_GROUP_set_point_conversion_form (TYPE_3__ const*,void*) ; 
 void EC_KEY_free (TYPE_2__*) ; 
 TYPE_2__* EC_KEY_new_method (int /*<<< orphan*/ *) ; 
 int EC_KEY_set_public_key (TYPE_2__*,int /*<<< orphan*/  const*) ; 
 scalar_t__ EC_METHOD_get_field_type (TYPE_43__*) ; 
 scalar_t__ EC_POINT_cmp (TYPE_3__ const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EC_POINT_copy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* EC_POINT_dup (int /*<<< orphan*/  const*,TYPE_3__ const*) ; 
 int /*<<< orphan*/  EC_POINT_free (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  EC_POINT_get_affine_coordinates (TYPE_3__ const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 scalar_t__ EC_POINT_is_at_infinity (TYPE_3__ const*,int /*<<< orphan*/  const*) ; 
 scalar_t__ EC_POINT_is_on_curve (TYPE_3__ const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int EC_POINT_mul (TYPE_3__ const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 void* EC_POINT_new (TYPE_3__ const*) ; 
 scalar_t__ EC_POINT_oct2point (TYPE_3__ const*,int /*<<< orphan*/  const*,unsigned char const*,size_t,int /*<<< orphan*/ *) ; 
 size_t EC_POINT_point2buf (TYPE_3__ const*,int /*<<< orphan*/  const*,void*,unsigned char**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EC_POINT_set_affine_coordinates (TYPE_3__ const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EC_POINT_set_to_infinity (TYPE_3__ const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  EC_R_BUFFER_TOO_SMALL ; 
 int /*<<< orphan*/  EC_R_COORDINATES_OUT_OF_RANGE ; 
 int /*<<< orphan*/  EC_R_INVALID_GROUP_ORDER ; 
 int /*<<< orphan*/  EC_R_INVALID_PRIVATE_KEY ; 
 int /*<<< orphan*/  EC_R_OPERATION_NOT_SUPPORTED ; 
 int /*<<< orphan*/  EC_R_POINT_AT_INFINITY ; 
 int /*<<< orphan*/  EC_R_POINT_IS_NOT_ON_CURVE ; 
 int /*<<< orphan*/  EC_R_WRONG_ORDER ; 
 int /*<<< orphan*/  ECerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ENGINE_finish (int /*<<< orphan*/ *) ; 
 scalar_t__ ENGINE_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ERR_R_BN_LIB ; 
 int /*<<< orphan*/  ERR_R_EC_LIB ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  ERR_R_PASSED_NULL_PARAMETER ; 
 int /*<<< orphan*/  ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED ; 
 scalar_t__ NID_X9_62_prime_field ; 
 int /*<<< orphan*/  OPENSSL_clear_free (void*,int) ; 
 int /*<<< orphan*/  OPENSSL_free (unsigned char*) ; 
 unsigned char* OPENSSL_malloc (size_t) ; 
 int /*<<< orphan*/  REF_ASSERT_ISNT (int) ; 
 int /*<<< orphan*/  REF_PRINT_COUNT (char*,TYPE_2__*) ; 
 scalar_t__ stub1 (TYPE_2__*,TYPE_3__ const*) ; 
 int stub10 (TYPE_2__ const*) ; 
 scalar_t__ stub11 (TYPE_2__*,TYPE_3__ const*) ; 
 scalar_t__ stub12 (TYPE_2__*,int /*<<< orphan*/  const*) ; 
 scalar_t__ stub13 (TYPE_2__*,int /*<<< orphan*/  const*) ; 
 scalar_t__ stub14 (TYPE_2__*,int /*<<< orphan*/  const*) ; 
 size_t stub15 (TYPE_2__ const*,unsigned char*,size_t) ; 
 int stub16 (TYPE_2__*,unsigned char const*,size_t) ; 
 int /*<<< orphan*/  stub2 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub3 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub5 (TYPE_2__*) ; 
 scalar_t__ stub6 (TYPE_2__*,TYPE_2__ const*) ; 
 scalar_t__ stub7 (TYPE_2__*,TYPE_2__ const*) ; 
 int stub8 (TYPE_2__*) ; 
 int stub9 (TYPE_2__*) ; 

EC_KEY *EC_KEY_new(void)
{
    return EC_KEY_new_method(NULL);
}

EC_KEY *EC_KEY_new_by_curve_name(int nid)
{
    EC_KEY *ret = EC_KEY_new();
    if (ret == NULL)
        return NULL;
    ret->group = EC_GROUP_new_by_curve_name(nid);
    if (ret->group == NULL) {
        EC_KEY_free(ret);
        return NULL;
    }
    if (ret->meth->set_group != NULL
        && ret->meth->set_group(ret, ret->group) == 0) {
        EC_KEY_free(ret);
        return NULL;
    }
    return ret;
}

void EC_KEY_free(EC_KEY *r)
{
    int i;

    if (r == NULL)
        return;

    CRYPTO_DOWN_REF(&r->references, &i, r->lock);
    REF_PRINT_COUNT("EC_KEY", r);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    if (r->meth != NULL && r->meth->finish != NULL)
        r->meth->finish(r);

#ifndef OPENSSL_NO_ENGINE
    ENGINE_finish(r->engine);
#endif

    if (r->group && r->group->meth->keyfinish)
        r->group->meth->keyfinish(r);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EC_KEY, r, &r->ex_data);
    CRYPTO_THREAD_lock_free(r->lock);
    EC_GROUP_free(r->group);
    EC_POINT_free(r->pub_key);
    BN_clear_free(r->priv_key);

    OPENSSL_clear_free((void *)r, sizeof(EC_KEY));
}

EC_KEY *EC_KEY_copy(EC_KEY *dest, const EC_KEY *src)
{
    if (dest == NULL || src == NULL) {
        ECerr(EC_F_EC_KEY_COPY, ERR_R_PASSED_NULL_PARAMETER);
        return NULL;
    }
    if (src->meth != dest->meth) {
        if (dest->meth->finish != NULL)
            dest->meth->finish(dest);
        if (dest->group && dest->group->meth->keyfinish)
            dest->group->meth->keyfinish(dest);
#ifndef OPENSSL_NO_ENGINE
        if (ENGINE_finish(dest->engine) == 0)
            return 0;
        dest->engine = NULL;
#endif
    }
    /* copy the parameters */
    if (src->group != NULL) {
        const EC_METHOD *meth = EC_GROUP_method_of(src->group);
        /* clear the old group */
        EC_GROUP_free(dest->group);
        dest->group = EC_GROUP_new(meth);
        if (dest->group == NULL)
            return NULL;
        if (!EC_GROUP_copy(dest->group, src->group))
            return NULL;

        /*  copy the public key */
        if (src->pub_key != NULL) {
            EC_POINT_free(dest->pub_key);
            dest->pub_key = EC_POINT_new(src->group);
            if (dest->pub_key == NULL)
                return NULL;
            if (!EC_POINT_copy(dest->pub_key, src->pub_key))
                return NULL;
        }
        /* copy the private key */
        if (src->priv_key != NULL) {
            if (dest->priv_key == NULL) {
                dest->priv_key = BN_new();
                if (dest->priv_key == NULL)
                    return NULL;
            }
            if (!BN_copy(dest->priv_key, src->priv_key))
                return NULL;
            if (src->group->meth->keycopy
                && src->group->meth->keycopy(dest, src) == 0)
                return NULL;
        }
    }


    /* copy the rest */
    dest->enc_flag = src->enc_flag;
    dest->conv_form = src->conv_form;
    dest->version = src->version;
    dest->flags = src->flags;
    if (!CRYPTO_dup_ex_data(CRYPTO_EX_INDEX_EC_KEY,
                            &dest->ex_data, &src->ex_data))
        return NULL;

    if (src->meth != dest->meth) {
#ifndef OPENSSL_NO_ENGINE
        if (src->engine != NULL && ENGINE_init(src->engine) == 0)
            return NULL;
        dest->engine = src->engine;
#endif
        dest->meth = src->meth;
    }

    if (src->meth->copy != NULL && src->meth->copy(dest, src) == 0)
        return NULL;

    return dest;
}

EC_KEY *EC_KEY_dup(const EC_KEY *ec_key)
{
    EC_KEY *ret = EC_KEY_new_method(ec_key->engine);

    if (ret == NULL)
        return NULL;

    if (EC_KEY_copy(ret, ec_key) == NULL) {
        EC_KEY_free(ret);
        return NULL;
    }
    return ret;
}

int EC_KEY_up_ref(EC_KEY *r)
{
    int i;

    if (CRYPTO_UP_REF(&r->references, &i, r->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("EC_KEY", r);
    REF_ASSERT_ISNT(i < 2);
    return ((i > 1) ? 1 : 0);
}

ENGINE *EC_KEY_get0_engine(const EC_KEY *eckey)
{
    return eckey->engine;
}

int EC_KEY_generate_key(EC_KEY *eckey)
{
    if (eckey == NULL || eckey->group == NULL) {
        ECerr(EC_F_EC_KEY_GENERATE_KEY, ERR_R_PASSED_NULL_PARAMETER);
        return 0;
    }
    if (eckey->meth->keygen != NULL)
        return eckey->meth->keygen(eckey);
    ECerr(EC_F_EC_KEY_GENERATE_KEY, EC_R_OPERATION_NOT_SUPPORTED);
    return 0;
}

int ossl_ec_key_gen(EC_KEY *eckey)
{
    return eckey->group->meth->keygen(eckey);
}

int ec_key_simple_generate_key(EC_KEY *eckey)
{
    int ok = 0;
    BIGNUM *priv_key = NULL;
    const BIGNUM *order = NULL;
    EC_POINT *pub_key = NULL;
    const EC_GROUP *group = eckey->group;

    if (eckey->priv_key == NULL) {
        priv_key = BN_secure_new();
        if (priv_key == NULL)
            goto err;
    } else
        priv_key = eckey->priv_key;

    /*
     * Steps (1-2): Check domain parameters and security strength.
     * These steps must be done by the user. This would need to be
     * stated in the security policy.
     */

    order = EC_GROUP_get0_order(group);
    if (order == NULL)
        goto err;

    /*
     * Steps (3-7): priv_key = DRBG_RAND(order_n_bits) (range [1, n-1]).
     * Although this is slightly different from the standard, it is effectively
     * equivalent as it gives an unbiased result ranging from 1..n-1. It is also
     * faster as the standard needs to retry more often. Also doing
     * 1 + rand[0..n-2] would effect the way that tests feed dummy entropy into
     * rand so the simpler backward compatible method has been used here.
     */
    do
        if (!BN_priv_rand_range(priv_key, order))
            goto err;
    while (BN_is_zero(priv_key)) ;

    if (eckey->pub_key == NULL) {
        pub_key = EC_POINT_new(group);
        if (pub_key == NULL)
            goto err;
    } else
        pub_key = eckey->pub_key;

    /* Step (8) : pub_key = priv_key * G (where G is a point on the curve) */
    if (!EC_POINT_mul(group, pub_key, priv_key, NULL, NULL, NULL))
        goto err;

    eckey->priv_key = priv_key;
    eckey->pub_key = pub_key;
    priv_key = NULL;
    pub_key = NULL;

    ok = 1;

err:
    /* Step (9): If there is an error return an invalid keypair. */
    if (!ok) {
        BN_clear(eckey->priv_key);
        if (eckey->pub_key != NULL)
            EC_POINT_set_to_infinity(group, eckey->pub_key);
    }

    EC_POINT_free(pub_key);
    BN_clear_free(priv_key);
    return ok;
}

int ec_key_simple_generate_public_key(EC_KEY *eckey)
{
    /*
     * See SP800-56AR3 5.6.1.2.2: Step (8)
     * pub_key = priv_key * G (where G is a point on the curve)
     */
    return EC_POINT_mul(eckey->group, eckey->pub_key, eckey->priv_key, NULL,
                        NULL, NULL);
}

int EC_KEY_check_key(const EC_KEY *eckey)
{
    if (eckey == NULL || eckey->group == NULL || eckey->pub_key == NULL) {
        ECerr(EC_F_EC_KEY_CHECK_KEY, ERR_R_PASSED_NULL_PARAMETER);
        return 0;
    }

    if (eckey->group->meth->keycheck == NULL) {
        ECerr(EC_F_EC_KEY_CHECK_KEY, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
        return 0;
    }

    return eckey->group->meth->keycheck(eckey);
}

__attribute__((used)) static int ec_key_public_range_check(BN_CTX *ctx, const EC_KEY *key)
{
    int ret = 0;
    BIGNUM *x, *y;

    BN_CTX_start(ctx);
    x = BN_CTX_get(ctx);
    y = BN_CTX_get(ctx);
    if (y == NULL)
        goto err;

    if (!EC_POINT_get_affine_coordinates(key->group, key->pub_key, x, y, ctx))
        goto err;

    if (EC_METHOD_get_field_type(key->group->meth) == NID_X9_62_prime_field) {
        if (BN_is_negative(x)
            || BN_cmp(x, key->group->field) >= 0
            || BN_is_negative(y)
            || BN_cmp(y, key->group->field) >= 0) {
            goto err;
        }
    } else {
        int m = EC_GROUP_get_degree(key->group);
        if (BN_num_bits(x) > m || BN_num_bits(y) > m) {
            goto err;
        }
    }
    ret = 1;
err:
    BN_CTX_end(ctx);
    return ret;
}

int ec_key_simple_check_key(const EC_KEY *eckey)
{
    int ok = 0;
    BN_CTX *ctx = NULL;
    const BIGNUM *order = NULL;
    EC_POINT *point = NULL;

    if (eckey == NULL || eckey->group == NULL || eckey->pub_key == NULL) {
        ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, ERR_R_PASSED_NULL_PARAMETER);
        return 0;
    }

    /* 5.6.2.3.3 (Step 1): Q != infinity */
    if (EC_POINT_is_at_infinity(eckey->group, eckey->pub_key)) {
        ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, EC_R_POINT_AT_INFINITY);
        goto err;
    }

    if ((ctx = BN_CTX_new()) == NULL)
        goto err;

    if ((point = EC_POINT_new(eckey->group)) == NULL)
        goto err;

    /* 5.6.2.3.3 (Step 2) Test if the public key is in range */
    if (!ec_key_public_range_check(ctx, eckey)) {
        ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, EC_R_COORDINATES_OUT_OF_RANGE);
        goto err;
    }

    /* 5.6.2.3.3 (Step 3) is the pub_key on the elliptic curve */
    if (EC_POINT_is_on_curve(eckey->group, eckey->pub_key, ctx) <= 0) {
        ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, EC_R_POINT_IS_NOT_ON_CURVE);
        goto err;
    }

    order = eckey->group->order;
    if (BN_is_zero(order)) {
        ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, EC_R_INVALID_GROUP_ORDER);
        goto err;
    }
    /* 5.6.2.3.3 (Step 4) : pub_key * order is the point at infinity. */
    if (!EC_POINT_mul(eckey->group, point, NULL, eckey->pub_key, order, ctx)) {
        ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, ERR_R_EC_LIB);
        goto err;
    }
    if (!EC_POINT_is_at_infinity(eckey->group, point)) {
        ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, EC_R_WRONG_ORDER);
        goto err;
    }

    if (eckey->priv_key != NULL) {
        /*
         * 5.6.2.1.2 Owner Assurance of Private-Key Validity
         * The private key is in the range [1, order-1]
         */
        if (BN_cmp(eckey->priv_key, BN_value_one()) < 0
                || BN_cmp(eckey->priv_key, order) >= 0) {
            ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, EC_R_WRONG_ORDER);
            goto err;
        }
        /*
         * Section 5.6.2.1.4 Owner Assurance of Pair-wise Consistency (b)
         * Check if generator * priv_key = pub_key
         */
        if (!EC_POINT_mul(eckey->group, point, eckey->priv_key,
                          NULL, NULL, ctx)) {
            ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, ERR_R_EC_LIB);
            goto err;
        }
        if (EC_POINT_cmp(eckey->group, point, eckey->pub_key, ctx) != 0) {
            ECerr(EC_F_EC_KEY_SIMPLE_CHECK_KEY, EC_R_INVALID_PRIVATE_KEY);
            goto err;
        }
    }
    ok = 1;
 err:
    BN_CTX_free(ctx);
    EC_POINT_free(point);
    return ok;
}

int EC_KEY_set_public_key_affine_coordinates(EC_KEY *key, BIGNUM *x,
                                             BIGNUM *y)
{
    BN_CTX *ctx = NULL;
    BIGNUM *tx, *ty;
    EC_POINT *point = NULL;
    int ok = 0;

    if (key == NULL || key->group == NULL || x == NULL || y == NULL) {
        ECerr(EC_F_EC_KEY_SET_PUBLIC_KEY_AFFINE_COORDINATES,
              ERR_R_PASSED_NULL_PARAMETER);
        return 0;
    }
    ctx = BN_CTX_new();
    if (ctx == NULL)
        return 0;

    BN_CTX_start(ctx);
    point = EC_POINT_new(key->group);

    if (point == NULL)
        goto err;

    tx = BN_CTX_get(ctx);
    ty = BN_CTX_get(ctx);
    if (ty == NULL)
        goto err;

    if (!EC_POINT_set_affine_coordinates(key->group, point, x, y, ctx))
        goto err;
    if (!EC_POINT_get_affine_coordinates(key->group, point, tx, ty, ctx))
        goto err;

    /*
     * Check if retrieved coordinates match originals. The range check is done
     * inside EC_KEY_check_key().
     */
    if (BN_cmp(x, tx) || BN_cmp(y, ty)) {
        ECerr(EC_F_EC_KEY_SET_PUBLIC_KEY_AFFINE_COORDINATES,
              EC_R_COORDINATES_OUT_OF_RANGE);
        goto err;
    }

    if (!EC_KEY_set_public_key(key, point))
        goto err;

    if (EC_KEY_check_key(key) == 0)
        goto err;

    ok = 1;

 err:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    EC_POINT_free(point);
    return ok;

}

const EC_GROUP *EC_KEY_get0_group(const EC_KEY *key)
{
    return key->group;
}

int EC_KEY_set_group(EC_KEY *key, const EC_GROUP *group)
{
    if (key->meth->set_group != NULL && key->meth->set_group(key, group) == 0)
        return 0;
    EC_GROUP_free(key->group);
    key->group = EC_GROUP_dup(group);
    return (key->group == NULL) ? 0 : 1;
}

const BIGNUM *EC_KEY_get0_private_key(const EC_KEY *key)
{
    return key->priv_key;
}

int EC_KEY_set_private_key(EC_KEY *key, const BIGNUM *priv_key)
{
    if (key->group == NULL || key->group->meth == NULL)
        return 0;
    if (key->group->meth->set_private != NULL
        && key->group->meth->set_private(key, priv_key) == 0)
        return 0;
    if (key->meth->set_private != NULL
        && key->meth->set_private(key, priv_key) == 0)
        return 0;
    BN_clear_free(key->priv_key);
    key->priv_key = BN_dup(priv_key);
    return (key->priv_key == NULL) ? 0 : 1;
}

const EC_POINT *EC_KEY_get0_public_key(const EC_KEY *key)
{
    return key->pub_key;
}

int EC_KEY_set_public_key(EC_KEY *key, const EC_POINT *pub_key)
{
    if (key->meth->set_public != NULL
        && key->meth->set_public(key, pub_key) == 0)
        return 0;
    EC_POINT_free(key->pub_key);
    key->pub_key = EC_POINT_dup(pub_key, key->group);
    return (key->pub_key == NULL) ? 0 : 1;
}

unsigned int EC_KEY_get_enc_flags(const EC_KEY *key)
{
    return key->enc_flag;
}

void EC_KEY_set_enc_flags(EC_KEY *key, unsigned int flags)
{
    key->enc_flag = flags;
}

point_conversion_form_t EC_KEY_get_conv_form(const EC_KEY *key)
{
    return key->conv_form;
}

void EC_KEY_set_conv_form(EC_KEY *key, point_conversion_form_t cform)
{
    key->conv_form = cform;
    if (key->group != NULL)
        EC_GROUP_set_point_conversion_form(key->group, cform);
}

void EC_KEY_set_asn1_flag(EC_KEY *key, int flag)
{
    if (key->group != NULL)
        EC_GROUP_set_asn1_flag(key->group, flag);
}

int EC_KEY_precompute_mult(EC_KEY *key, BN_CTX *ctx)
{
    if (key->group == NULL)
        return 0;
    return EC_GROUP_precompute_mult(key->group, ctx);
}

int EC_KEY_get_flags(const EC_KEY *key)
{
    return key->flags;
}

void EC_KEY_set_flags(EC_KEY *key, int flags)
{
    key->flags |= flags;
}

void EC_KEY_clear_flags(EC_KEY *key, int flags)
{
    key->flags &= ~flags;
}

size_t EC_KEY_key2buf(const EC_KEY *key, point_conversion_form_t form,
                        unsigned char **pbuf, BN_CTX *ctx)
{
    if (key == NULL || key->pub_key == NULL || key->group == NULL)
        return 0;
    return EC_POINT_point2buf(key->group, key->pub_key, form, pbuf, ctx);
}

int EC_KEY_oct2key(EC_KEY *key, const unsigned char *buf, size_t len,
                   BN_CTX *ctx)
{
    if (key == NULL || key->group == NULL)
        return 0;
    if (key->pub_key == NULL)
        key->pub_key = EC_POINT_new(key->group);
    if (key->pub_key == NULL)
        return 0;
    if (EC_POINT_oct2point(key->group, key->pub_key, buf, len, ctx) == 0)
        return 0;
    /*
     * Save the point conversion form.
     * For non-custom curves the first octet of the buffer (excluding
     * the last significant bit) contains the point conversion form.
     * EC_POINT_oct2point() has already performed sanity checking of
     * the buffer so we know it is valid.
     */
    if ((key->group->meth->flags & EC_FLAGS_CUSTOM_CURVE) == 0)
        key->conv_form = (point_conversion_form_t)(buf[0] & ~0x01);
    return 1;
}

size_t EC_KEY_priv2oct(const EC_KEY *eckey,
                       unsigned char *buf, size_t len)
{
    if (eckey->group == NULL || eckey->group->meth == NULL)
        return 0;
    if (eckey->group->meth->priv2oct == NULL) {
        ECerr(EC_F_EC_KEY_PRIV2OCT, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
        return 0;
    }

    return eckey->group->meth->priv2oct(eckey, buf, len);
}

size_t ec_key_simple_priv2oct(const EC_KEY *eckey,
                              unsigned char *buf, size_t len)
{
    size_t buf_len;

    buf_len = (EC_GROUP_order_bits(eckey->group) + 7) / 8;
    if (eckey->priv_key == NULL)
        return 0;
    if (buf == NULL)
        return buf_len;
    else if (len < buf_len)
        return 0;

    /* Octetstring may need leading zeros if BN is to short */

    if (BN_bn2binpad(eckey->priv_key, buf, buf_len) == -1) {
        ECerr(EC_F_EC_KEY_SIMPLE_PRIV2OCT, EC_R_BUFFER_TOO_SMALL);
        return 0;
    }

    return buf_len;
}

int EC_KEY_oct2priv(EC_KEY *eckey, const unsigned char *buf, size_t len)
{
    if (eckey->group == NULL || eckey->group->meth == NULL)
        return 0;
    if (eckey->group->meth->oct2priv == NULL) {
        ECerr(EC_F_EC_KEY_OCT2PRIV, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
        return 0;
    }
    return eckey->group->meth->oct2priv(eckey, buf, len);
}

int ec_key_simple_oct2priv(EC_KEY *eckey, const unsigned char *buf, size_t len)
{
    if (eckey->priv_key == NULL)
        eckey->priv_key = BN_secure_new();
    if (eckey->priv_key == NULL) {
        ECerr(EC_F_EC_KEY_SIMPLE_OCT2PRIV, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    eckey->priv_key = BN_bin2bn(buf, len, eckey->priv_key);
    if (eckey->priv_key == NULL) {
        ECerr(EC_F_EC_KEY_SIMPLE_OCT2PRIV, ERR_R_BN_LIB);
        return 0;
    }
    return 1;
}

size_t EC_KEY_priv2buf(const EC_KEY *eckey, unsigned char **pbuf)
{
    size_t len;
    unsigned char *buf;

    len = EC_KEY_priv2oct(eckey, NULL, 0);
    if (len == 0)
        return 0;
    if ((buf = OPENSSL_malloc(len)) == NULL) {
        ECerr(EC_F_EC_KEY_PRIV2BUF, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    len = EC_KEY_priv2oct(eckey, buf, len);
    if (len == 0) {
        OPENSSL_free(buf);
        return 0;
    }
    *pbuf = buf;
    return len;
}

int EC_KEY_can_sign(const EC_KEY *eckey)
{
    if (eckey->group == NULL || eckey->group->meth == NULL
        || (eckey->group->meth->flags & EC_FLAGS_NO_SIGN))
        return 0;
    return 1;
}

