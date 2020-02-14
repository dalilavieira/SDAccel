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
typedef  int /*<<< orphan*/  EVP_CIPHER ;

/* Variables and functions */
 int /*<<< orphan*/  const* EVP_aes_128_cfb128 () ; 
 int /*<<< orphan*/  const* EVP_aes_192_cfb128 () ; 
 int /*<<< orphan*/  const* EVP_aes_256_cfb128 () ; 
 int /*<<< orphan*/  const* EVP_bf_cfb64 () ; 
 int /*<<< orphan*/  const* EVP_cast5_cfb64 () ; 
 int /*<<< orphan*/  const* EVP_des_cfb64 () ; 
 int /*<<< orphan*/  const* EVP_des_ede3_cfb64 () ; 
 int /*<<< orphan*/  const* EVP_des_ede_cfb64 () ; 
 int /*<<< orphan*/  const* EVP_idea_cfb64 () ; 
 int /*<<< orphan*/  const* EVP_rc2_cfb64 () ; 
 int /*<<< orphan*/  const* EVP_rc5_32_12_16_cfb64 () ; 

const EVP_CIPHER *EVP_bf_cfb(void)
{
    return EVP_bf_cfb64();
}

const EVP_CIPHER *EVP_des_cfb(void)
{
    return EVP_des_cfb64();
}

const EVP_CIPHER *EVP_des_ede3_cfb(void)
{
    return EVP_des_ede3_cfb64();
}

const EVP_CIPHER *EVP_des_ede_cfb(void)
{
    return EVP_des_ede_cfb64();
}

const EVP_CIPHER *EVP_idea_cfb(void)
{
    return EVP_idea_cfb64();
}

const EVP_CIPHER *EVP_rc2_cfb(void)
{
    return EVP_rc2_cfb64();
}

const EVP_CIPHER *EVP_cast5_cfb(void)
{
    return EVP_cast5_cfb64();
}

const EVP_CIPHER *EVP_rc5_32_12_16_cfb(void)
{
    return EVP_rc5_32_12_16_cfb64();
}

const EVP_CIPHER *EVP_aes_128_cfb(void)
{
    return EVP_aes_128_cfb128();
}

const EVP_CIPHER *EVP_aes_192_cfb(void)
{
    return EVP_aes_192_cfb128();
}

const EVP_CIPHER *EVP_aes_256_cfb(void)
{
    return EVP_aes_256_cfb128();
}

