#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {unsigned char const* digest; } ;
struct TYPE_10__ {unsigned char* outer_padding; TYPE_1__ ctx; } ;
typedef  TYPE_1__ MD5_CTX ;
typedef  TYPE_2__ HMAC_MD5_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  MD5Final (TYPE_1__*) ; 
 int /*<<< orphan*/  MD5Init (TYPE_1__*) ; 
 int /*<<< orphan*/  MD5Update (TYPE_1__*,unsigned char const*,int) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char const*,int) ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 

void HMACMD5Init(HMAC_MD5_CTX *ctx, const unsigned char *key, unsigned int key_len)
{
    int i;
    unsigned char inner_padding[64];
    unsigned char temp_key[16];

    if(key_len > 64)
    {
        MD5_CTX temp_ctx;

        MD5Init(&temp_ctx);
        MD5Update(&temp_ctx, key, key_len);
        MD5Final(&temp_ctx);
        memcpy(temp_key, temp_ctx.digest, 16);

        key = temp_key;
        key_len = 16;
    }

    memset(inner_padding, 0, 64);
    memset(ctx->outer_padding, 0, 64);
    memcpy(inner_padding, key, key_len);
    memcpy(ctx->outer_padding, key, key_len);

    for(i = 0; i < 64; ++i)
    {
        inner_padding[i] ^= 0x36;
        ctx->outer_padding[i] ^= 0x5c;
    }

    MD5Init(&(ctx->ctx));
    MD5Update(&(ctx->ctx), inner_padding, 64);
}

void HMACMD5Update(HMAC_MD5_CTX *ctx, const unsigned char *data, unsigned int data_len)
{
    MD5Update(&(ctx->ctx), data, data_len);
}

void HMACMD5Final(HMAC_MD5_CTX *ctx, unsigned char *digest)
{
    MD5_CTX outer_ctx;
    unsigned char inner_digest[16];

    MD5Final(&(ctx->ctx));
    memcpy(inner_digest, ctx->ctx.digest, 16);

    MD5Init(&outer_ctx);
    MD5Update(&outer_ctx, ctx->outer_padding, 64);
    MD5Update(&outer_ctx, inner_digest, 16);
    MD5Final(&outer_ctx);

    memcpy(digest, outer_ctx.digest, 16);
}

