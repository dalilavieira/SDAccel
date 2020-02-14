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
typedef  int /*<<< orphan*/  EVP_MD_CTX ;
typedef  int /*<<< orphan*/  EVP_MD ;

/* Variables and functions */
 int /*<<< orphan*/  EVP_MD_CTX_md_data (int /*<<< orphan*/ *) ; 
 int WHIRLPOOL_Final (unsigned char*,int /*<<< orphan*/ ) ; 
 int WHIRLPOOL_Init (int /*<<< orphan*/ ) ; 
 int WHIRLPOOL_Update (int /*<<< orphan*/ ,void const*,size_t) ; 
 int /*<<< orphan*/  const whirlpool_md ; 

__attribute__((used)) static int init(EVP_MD_CTX *ctx)
{
    return WHIRLPOOL_Init(EVP_MD_CTX_md_data(ctx));
}

__attribute__((used)) static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
    return WHIRLPOOL_Update(EVP_MD_CTX_md_data(ctx), data, count);
}

__attribute__((used)) static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
    return WHIRLPOOL_Final(md, EVP_MD_CTX_md_data(ctx));
}

const EVP_MD *EVP_whirlpool(void)
{
    return &whirlpool_md;
}

