#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  ks; } ;
typedef  int /*<<< orphan*/  EVP_CIPHER_CTX ;

/* Variables and functions */
 TYPE_1__* EVP_C_DATA (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_SEED_KEY ; 
 int /*<<< orphan*/  SEED_set_key (unsigned char const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int seed_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
                         const unsigned char *iv, int enc)
{
    SEED_set_key(key, &EVP_C_DATA(EVP_SEED_KEY,ctx)->ks);
    return 1;
}

