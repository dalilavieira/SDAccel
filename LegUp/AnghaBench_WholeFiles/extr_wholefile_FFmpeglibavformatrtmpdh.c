#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
struct TYPE_6__ {int /*<<< orphan*/ * priv_key; int /*<<< orphan*/ * pub_key; int /*<<< orphan*/ * g; int /*<<< orphan*/ * p; } ;
typedef  TYPE_1__ FF_DH ;
typedef  int /*<<< orphan*/ * FFBigNum ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 int MAX_BYTES ; 
 int /*<<< orphan*/  av_free (TYPE_1__*) ; 
 int /*<<< orphan*/  bn_bn2bin (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bn_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ bn_cmp_1 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bn_copy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bn_free (int /*<<< orphan*/ *) ; 
 scalar_t__ bn_modexp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bn_new (int /*<<< orphan*/ *) ; 
 int bn_num_bytes (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bn_random (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bn_set_word (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bn_sub_word (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static FFBigNum dh_generate_key(FF_DH *dh)
{
    int num_bytes;

    num_bytes = bn_num_bytes(dh->p) - 1;
    if (num_bytes <= 0 || num_bytes > MAX_BYTES)
        return NULL;

    bn_new(dh->priv_key);
    if (!dh->priv_key)
        return NULL;
    bn_random(dh->priv_key, 8 * num_bytes);

    bn_new(dh->pub_key);
    if (!dh->pub_key) {
        bn_free(dh->priv_key);
        return NULL;
    }

    if (bn_modexp(dh->pub_key, dh->g, dh->priv_key, dh->p) < 0)
        return NULL;

    return dh->pub_key;
}

__attribute__((used)) static int dh_compute_key(FF_DH *dh, FFBigNum pub_key_bn,
                          uint32_t secret_key_len, uint8_t *secret_key)
{
    FFBigNum k;
    int ret;

    bn_new(k);
    if (!k)
        return -1;

    if ((ret = bn_modexp(k, pub_key_bn, dh->priv_key, dh->p)) < 0) {
        bn_free(k);
        return ret;
    }
    bn_bn2bin(k, secret_key, secret_key_len);
    bn_free(k);

    /* return the length of the shared secret key like DH_compute_key */
    return secret_key_len;
}

void ff_dh_free(FF_DH *dh)
{
    if (!dh)
        return;
    bn_free(dh->p);
    bn_free(dh->g);
    bn_free(dh->pub_key);
    bn_free(dh->priv_key);
    av_free(dh);
}

__attribute__((used)) static int dh_is_valid_public_key(FFBigNum y, FFBigNum p, FFBigNum q)
{
    FFBigNum bn = NULL;
    int ret = AVERROR(EINVAL);

    bn_new(bn);
    if (!bn)
        return AVERROR(ENOMEM);

    /* y must lie in [2, p - 1] */
    bn_set_word(bn, 1);
    if (!bn_cmp(y, bn))
        goto fail;

    /* bn = p - 2 */
    bn_copy(bn, p);
    bn_sub_word(bn, 1);
    if (!bn_cmp(y, bn))
        goto fail;

    /* Verify with Sophie-Germain prime
     *
     * This is a nice test to make sure the public key position is calculated
     * correctly. This test will fail in about 50% of the cases if applied to
     * random data.
     */
    /* y must fulfill y^q mod p = 1 */
    if ((ret = bn_modexp(bn, y, q, p)) < 0)
        goto fail;

    ret = AVERROR(EINVAL);
    if (bn_cmp_1(bn))
        goto fail;

    ret = 0;
fail:
    bn_free(bn);

    return ret;
}

