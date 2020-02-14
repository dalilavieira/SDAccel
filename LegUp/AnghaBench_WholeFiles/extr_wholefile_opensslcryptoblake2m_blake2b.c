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
typedef  int /*<<< orphan*/  BLAKE2B_PARAM ;

/* Variables and functions */
 int BLAKE2b_Final (unsigned char*,int /*<<< orphan*/ ) ; 
 int BLAKE2b_Init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int BLAKE2b_Update (int /*<<< orphan*/ ,void const*,size_t) ; 
 int /*<<< orphan*/  EVP_MD_CTX_md_data (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const blake2b_md ; 
 int /*<<< orphan*/  blake2b_param_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int init(EVP_MD_CTX *ctx)
{
    BLAKE2B_PARAM P;
    blake2b_param_init(&P);
    return BLAKE2b_Init(EVP_MD_CTX_md_data(ctx), &P);
}

__attribute__((used)) static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
    return BLAKE2b_Update(EVP_MD_CTX_md_data(ctx), data, count);
}

__attribute__((used)) static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
    return BLAKE2b_Final(md, EVP_MD_CTX_md_data(ctx));
}

const EVP_MD *EVP_blake2b512(void)
{
    return &blake2b_md;
}

