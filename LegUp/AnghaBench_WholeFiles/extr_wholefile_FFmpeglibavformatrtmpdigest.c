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
typedef  scalar_t__ uint8_t ;
typedef  int /*<<< orphan*/  AVHMAC ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AV_HMAC_SHA256 ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/ * av_hmac_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_hmac_final (int /*<<< orphan*/ *,scalar_t__*,int) ; 
 int /*<<< orphan*/  av_hmac_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_hmac_init (int /*<<< orphan*/ *,scalar_t__ const*,int) ; 
 int /*<<< orphan*/  av_hmac_update (int /*<<< orphan*/ *,scalar_t__ const*,int) ; 

int ff_rtmp_calc_digest(const uint8_t *src, int len, int gap,
                        const uint8_t *key, int keylen, uint8_t *dst)
{
    AVHMAC *hmac;

    hmac = av_hmac_alloc(AV_HMAC_SHA256);
    if (!hmac)
        return AVERROR(ENOMEM);

    av_hmac_init(hmac, key, keylen);
    if (gap <= 0) {
        av_hmac_update(hmac, src, len);
    } else { //skip 32 bytes used for storing digest
        av_hmac_update(hmac, src, gap);
        av_hmac_update(hmac, src + gap + 32, len - gap - 32);
    }
    av_hmac_final(hmac, dst, 32);

    av_hmac_free(hmac);

    return 0;
}

int ff_rtmp_calc_digest_pos(const uint8_t *buf, int off, int mod_val,
                            int add_val)
{
    int i, digest_pos = 0;

    for (i = 0; i < 4; i++)
        digest_pos += buf[i + off];
    digest_pos = digest_pos % mod_val + add_val;

    return digest_pos;
}

