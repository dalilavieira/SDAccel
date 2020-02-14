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
typedef  int /*<<< orphan*/  sha1tmp ;
typedef  int /*<<< orphan*/  padtmp ;
typedef  int /*<<< orphan*/  SHA_CTX ;
typedef  int /*<<< orphan*/  EVP_MD_CTX ;
typedef  int /*<<< orphan*/  EVP_MD ;

/* Variables and functions */
 int EVP_CTRL_SSL3_MASTER_SECRET ; 
 int /*<<< orphan*/ * EVP_MD_CTX_md_data (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OPENSSL_cleanse (unsigned char*,int) ; 
 int SHA1_Final (unsigned char*,int /*<<< orphan*/ *) ; 
 int SHA1_Init (int /*<<< orphan*/ *) ; 
 scalar_t__ SHA1_Update (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int SHA224_Final (unsigned char*,int /*<<< orphan*/ *) ; 
 int SHA224_Init (int /*<<< orphan*/ *) ; 
 int SHA224_Update (int /*<<< orphan*/ *,void const*,size_t) ; 
 int SHA256_Final (unsigned char*,int /*<<< orphan*/ *) ; 
 int SHA256_Init (int /*<<< orphan*/ *) ; 
 int SHA256_Update (int /*<<< orphan*/ *,void const*,size_t) ; 
 int SHA384_Final (unsigned char*,int /*<<< orphan*/ *) ; 
 int SHA384_Init (int /*<<< orphan*/ *) ; 
 int SHA384_Update (int /*<<< orphan*/ *,void const*,size_t) ; 
 int SHA512_Final (unsigned char*,int /*<<< orphan*/ *) ; 
 int SHA512_Init (int /*<<< orphan*/ *) ; 
 int SHA512_Update (int /*<<< orphan*/ *,void const*,size_t) ; 
 int SHA_DIGEST_LENGTH ; 
 int /*<<< orphan*/  memset (unsigned char*,int,int) ; 
 int /*<<< orphan*/  const sha1_md ; 
 int /*<<< orphan*/  const sha224_md ; 
 int /*<<< orphan*/  const sha256_md ; 
 int /*<<< orphan*/  const sha384_md ; 
 int sha512_224_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const sha512_224_md ; 
 int sha512_256_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const sha512_256_md ; 
 int /*<<< orphan*/  const sha512_md ; 

__attribute__((used)) static int init(EVP_MD_CTX *ctx)
{
    return SHA1_Init(EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
    return SHA1_Update(EVP_MD_CTX_md_data(ctx), data, count);
}

__attribute__((used)) static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
    return SHA1_Final(md, EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int ctrl(EVP_MD_CTX *ctx, int cmd, int mslen, void *ms)
{
    unsigned char padtmp[40];
    unsigned char sha1tmp[SHA_DIGEST_LENGTH];

    SHA_CTX *sha1;

    if (cmd != EVP_CTRL_SSL3_MASTER_SECRET)
        return -2;

    if (ctx == NULL)
        return 0;

    sha1 = EVP_MD_CTX_md_data(ctx);

    /* SSLv3 client auth handling: see RFC-6101 5.6.8 */
    if (mslen != 48)
        return 0;

    /* At this point hash contains all handshake messages, update
     * with master secret and pad_1.
     */

    if (SHA1_Update(sha1, ms, mslen) <= 0)
        return 0;

    /* Set padtmp to pad_1 value */
    memset(padtmp, 0x36, sizeof(padtmp));

    if (!SHA1_Update(sha1, padtmp, sizeof(padtmp)))
        return 0;

    if (!SHA1_Final(sha1tmp, sha1))
        return 0;

    /* Reinitialise context */

    if (!SHA1_Init(sha1))
        return 0;

    if (SHA1_Update(sha1, ms, mslen) <= 0)
        return 0;

    /* Set padtmp to pad_2 value */
    memset(padtmp, 0x5c, sizeof(padtmp));

    if (!SHA1_Update(sha1, padtmp, sizeof(padtmp)))
        return 0;

    if (!SHA1_Update(sha1, sha1tmp, sizeof(sha1tmp)))
        return 0;

    /* Now when ctx is finalised it will return the SSL v3 hash value */
    OPENSSL_cleanse(sha1tmp, sizeof(sha1tmp));

    return 1;

}

const EVP_MD *EVP_sha1(void)
{
    return &sha1_md;
}

__attribute__((used)) static int init224(EVP_MD_CTX *ctx)
{
    return SHA224_Init(EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int update224(EVP_MD_CTX *ctx, const void *data, size_t count)
{
    return SHA224_Update(EVP_MD_CTX_md_data(ctx), data, count);
}

__attribute__((used)) static int final224(EVP_MD_CTX *ctx, unsigned char *md)
{
    return SHA224_Final(md, EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int init256(EVP_MD_CTX *ctx)
{
    return SHA256_Init(EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int update256(EVP_MD_CTX *ctx, const void *data, size_t count)
{
    return SHA256_Update(EVP_MD_CTX_md_data(ctx), data, count);
}

__attribute__((used)) static int final256(EVP_MD_CTX *ctx, unsigned char *md)
{
    return SHA256_Final(md, EVP_MD_CTX_md_data(ctx));
}

const EVP_MD *EVP_sha224(void)
{
    return &sha224_md;
}

const EVP_MD *EVP_sha256(void)
{
    return &sha256_md;
}

__attribute__((used)) static int init512_224(EVP_MD_CTX *ctx)
{
    return sha512_224_init(EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int init512_256(EVP_MD_CTX *ctx)
{
    return sha512_256_init(EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int init384(EVP_MD_CTX *ctx)
{
    return SHA384_Init(EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int update384(EVP_MD_CTX *ctx, const void *data, size_t count)
{
    return SHA384_Update(EVP_MD_CTX_md_data(ctx), data, count);
}

__attribute__((used)) static int final384(EVP_MD_CTX *ctx, unsigned char *md)
{
    return SHA384_Final(md, EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int init512(EVP_MD_CTX *ctx)
{
    return SHA512_Init(EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int update512(EVP_MD_CTX *ctx, const void *data, size_t count)
{
    return SHA512_Update(EVP_MD_CTX_md_data(ctx), data, count);
}

__attribute__((used)) static int final512(EVP_MD_CTX *ctx, unsigned char *md)
{
    return SHA512_Final(md, EVP_MD_CTX_md_data(ctx));
}

const EVP_MD *EVP_sha512_224(void)
{
    return &sha512_224_md;
}

const EVP_MD *EVP_sha512_256(void)
{
    return &sha512_256_md;
}

const EVP_MD *EVP_sha384(void)
{
    return &sha384_md;
}

const EVP_MD *EVP_sha512(void)
{
    return &sha512_md;
}

