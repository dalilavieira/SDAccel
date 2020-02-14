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
 int /*<<< orphan*/  const null_md ; 

__attribute__((used)) static int init(EVP_MD_CTX *ctx)
{
    return 1;
}

__attribute__((used)) static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
    return 1;
}

__attribute__((used)) static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
    return 1;
}

const EVP_MD *EVP_md_null(void)
{
    return &null_md;
}

