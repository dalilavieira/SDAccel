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
struct TYPE_2__ {int rounds; int /*<<< orphan*/  ks; } ;
typedef  int /*<<< orphan*/  EVP_CIPHER_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  EVP_CIPHER_CTX_key_length (int /*<<< orphan*/ *) ; 
#define  EVP_CTRL_GET_RC5_ROUNDS 133 
#define  EVP_CTRL_INIT 132 
#define  EVP_CTRL_SET_RC5_ROUNDS 131 
 int /*<<< orphan*/  EVP_F_RC5_CTRL ; 
 int /*<<< orphan*/  EVP_R_UNSUPPORTED_NUMBER_OF_ROUNDS ; 
 int /*<<< orphan*/  EVPerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  RC5_12_ROUNDS 130 
#define  RC5_16_ROUNDS 129 
 int /*<<< orphan*/  RC5_32_set_key (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned char const*,int) ; 
#define  RC5_8_ROUNDS 128 
 TYPE_1__* data (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int rc5_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
    switch (type) {
    case EVP_CTRL_INIT:
        data(c)->rounds = RC5_12_ROUNDS;
        return 1;

    case EVP_CTRL_GET_RC5_ROUNDS:
        *(int *)ptr = data(c)->rounds;
        return 1;

    case EVP_CTRL_SET_RC5_ROUNDS:
        switch (arg) {
        case RC5_8_ROUNDS:
        case RC5_12_ROUNDS:
        case RC5_16_ROUNDS:
            data(c)->rounds = arg;
            return 1;

        default:
            EVPerr(EVP_F_RC5_CTRL, EVP_R_UNSUPPORTED_NUMBER_OF_ROUNDS);
            return 0;
        }

    default:
        return -1;
    }
}

__attribute__((used)) static int r_32_12_16_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
                               const unsigned char *iv, int enc)
{
    RC5_32_set_key(&data(ctx)->ks, EVP_CIPHER_CTX_key_length(ctx),
                   key, data(ctx)->rounds);
    return 1;
}

