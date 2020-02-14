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
typedef  int uint64_t ;
typedef  int uint32_t ;
struct TYPE_10__ {int /*<<< orphan*/ * data; TYPE_1__* pmeth; } ;
struct TYPE_9__ {int /*<<< orphan*/  pkey_id; } ;
typedef  TYPE_2__ EVP_PKEY_CTX ;
typedef  int /*<<< orphan*/  EVP_MD ;
typedef  int /*<<< orphan*/  EVP_KDF_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  EVP_F_PKEY_KDF_CTRL ; 
#define  EVP_KDF_CTRL_ADD_HKDF_INFO 153 
#define  EVP_KDF_CTRL_ADD_TLS_SEED 152 
 int /*<<< orphan*/  EVP_KDF_CTRL_RESET_TLS_SEED ; 
#define  EVP_KDF_CTRL_SET_HKDF_MODE 151 
#define  EVP_KDF_CTRL_SET_KEY 150 
#define  EVP_KDF_CTRL_SET_MAXMEM_BYTES 149 
#define  EVP_KDF_CTRL_SET_MD 148 
#define  EVP_KDF_CTRL_SET_PASS 147 
#define  EVP_KDF_CTRL_SET_SALT 146 
#define  EVP_KDF_CTRL_SET_SCRYPT_N 145 
#define  EVP_KDF_CTRL_SET_SCRYPT_P 144 
#define  EVP_KDF_CTRL_SET_SCRYPT_R 143 
#define  EVP_KDF_CTRL_SET_TLS_SECRET 142 
 int /*<<< orphan*/  EVP_KDF_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * EVP_KDF_CTX_new_id (int /*<<< orphan*/ ) ; 
 int EVP_KDF_ctrl (int /*<<< orphan*/ *,int,...) ; 
 int EVP_KDF_ctrl_str (int /*<<< orphan*/ *,char const*,char const*) ; 
 int EVP_KDF_derive (int /*<<< orphan*/ *,unsigned char*,size_t) ; 
 int /*<<< orphan*/  EVP_KDF_reset (int /*<<< orphan*/ *) ; 
 size_t EVP_KDF_size (int /*<<< orphan*/ *) ; 
#define  EVP_PKEY_CTRL_HKDF_INFO 141 
#define  EVP_PKEY_CTRL_HKDF_KEY 140 
#define  EVP_PKEY_CTRL_HKDF_MD 139 
#define  EVP_PKEY_CTRL_HKDF_MODE 138 
#define  EVP_PKEY_CTRL_HKDF_SALT 137 
#define  EVP_PKEY_CTRL_PASS 136 
#define  EVP_PKEY_CTRL_SCRYPT_MAXMEM_BYTES 135 
#define  EVP_PKEY_CTRL_SCRYPT_N 134 
#define  EVP_PKEY_CTRL_SCRYPT_P 133 
#define  EVP_PKEY_CTRL_SCRYPT_R 132 
#define  EVP_PKEY_CTRL_SCRYPT_SALT 131 
#define  EVP_PKEY_CTRL_TLS_MD 130 
#define  EVP_PKEY_CTRL_TLS_SECRET 129 
#define  EVP_PKEY_CTRL_TLS_SEED 128 
 int /*<<< orphan*/  EVP_R_PARAMETER_TOO_LARGE ; 
 int /*<<< orphan*/  EVPerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 size_t SIZE_MAX ; 
 int UINT32_MAX ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static int pkey_kdf_init(EVP_PKEY_CTX *ctx)
{
    EVP_KDF_CTX *kctx;

    kctx = EVP_KDF_CTX_new_id(ctx->pmeth->pkey_id);
    if (kctx == NULL)
        return 0;

    ctx->data = kctx;
    return 1;
}

__attribute__((used)) static void pkey_kdf_cleanup(EVP_PKEY_CTX *ctx)
{
    EVP_KDF_CTX *kctx = ctx->data;

    EVP_KDF_CTX_free(kctx);
}

__attribute__((used)) static int pkey_kdf_ctrl(EVP_PKEY_CTX *ctx, int type, int p1, void *p2)
{
    EVP_KDF_CTX *kctx = ctx->data;
    uint64_t u64_value;
    int cmd;
    int ret;

    switch (type) {
    case EVP_PKEY_CTRL_PASS:
        cmd = EVP_KDF_CTRL_SET_PASS;
        break;
    case EVP_PKEY_CTRL_HKDF_SALT:
    case EVP_PKEY_CTRL_SCRYPT_SALT:
        cmd = EVP_KDF_CTRL_SET_SALT;
        break;
    case EVP_PKEY_CTRL_TLS_MD:
    case EVP_PKEY_CTRL_HKDF_MD:
        cmd = EVP_KDF_CTRL_SET_MD;
        break;
    case EVP_PKEY_CTRL_TLS_SECRET:
        cmd = EVP_KDF_CTRL_SET_TLS_SECRET;
        ret = EVP_KDF_ctrl(kctx, EVP_KDF_CTRL_RESET_TLS_SEED);
        if (ret < 1)
            return ret;
        break;
    case EVP_PKEY_CTRL_TLS_SEED:
        cmd = EVP_KDF_CTRL_ADD_TLS_SEED;
        break;
    case EVP_PKEY_CTRL_HKDF_KEY:
        cmd = EVP_KDF_CTRL_SET_KEY;
        break;
    case EVP_PKEY_CTRL_HKDF_INFO:
        cmd = EVP_KDF_CTRL_ADD_HKDF_INFO;
        break;
    case EVP_PKEY_CTRL_HKDF_MODE:
        cmd = EVP_KDF_CTRL_SET_HKDF_MODE;
        break;
    case EVP_PKEY_CTRL_SCRYPT_N:
        cmd = EVP_KDF_CTRL_SET_SCRYPT_N;
        break;
    case EVP_PKEY_CTRL_SCRYPT_R:
        cmd = EVP_KDF_CTRL_SET_SCRYPT_R;
        break;
    case EVP_PKEY_CTRL_SCRYPT_P:
        cmd = EVP_KDF_CTRL_SET_SCRYPT_P;
        break;
    case EVP_PKEY_CTRL_SCRYPT_MAXMEM_BYTES:
        cmd = EVP_KDF_CTRL_SET_MAXMEM_BYTES;
        break;
    default:
        return -2;
    }

    switch (cmd) {
    case EVP_KDF_CTRL_SET_PASS:
    case EVP_KDF_CTRL_SET_SALT:
    case EVP_KDF_CTRL_SET_KEY:
    case EVP_KDF_CTRL_SET_TLS_SECRET:
    case EVP_KDF_CTRL_ADD_TLS_SEED:
    case EVP_KDF_CTRL_ADD_HKDF_INFO:
        return EVP_KDF_ctrl(kctx, cmd, (const unsigned char *)p2, (size_t)p1);

    case EVP_KDF_CTRL_SET_MD:
        return EVP_KDF_ctrl(kctx, cmd, (const EVP_MD *)p2);

    case EVP_KDF_CTRL_SET_HKDF_MODE:
        return EVP_KDF_ctrl(kctx, cmd, (int)p1);

    case EVP_KDF_CTRL_SET_SCRYPT_R:
    case EVP_KDF_CTRL_SET_SCRYPT_P:
        u64_value = *(uint64_t *)p2;
        if (u64_value > UINT32_MAX) {
            EVPerr(EVP_F_PKEY_KDF_CTRL, EVP_R_PARAMETER_TOO_LARGE);
            return 0;
        }

        return EVP_KDF_ctrl(kctx, cmd, (uint32_t)u64_value);

    case EVP_KDF_CTRL_SET_SCRYPT_N:
    case EVP_KDF_CTRL_SET_MAXMEM_BYTES:
        return EVP_KDF_ctrl(kctx, cmd, *(uint64_t *)p2);

    default:
        return 0;
    }
}

__attribute__((used)) static int pkey_kdf_ctrl_str(EVP_PKEY_CTX *ctx, const char *type,
                             const char *value)
{
    EVP_KDF_CTX *kctx = ctx->data;

    if (strcmp(type, "md") == 0)
        return EVP_KDF_ctrl_str(kctx, "digest", value);
    return EVP_KDF_ctrl_str(kctx, type, value);
}

__attribute__((used)) static int pkey_kdf_derive_init(EVP_PKEY_CTX *ctx)
{
    EVP_KDF_CTX *kctx = ctx->data;

    EVP_KDF_reset(kctx);
    return 1;
}

__attribute__((used)) static int pkey_kdf_derive(EVP_PKEY_CTX *ctx, unsigned char *key,
                           size_t *keylen)
{
    EVP_KDF_CTX *kctx = ctx->data;
    size_t outlen = EVP_KDF_size(kctx);

    if (outlen == 0 || outlen == SIZE_MAX) {
        /* Variable-output algorithm */
        if (key == NULL)
            return 0;
    } else {
        /* Fixed-output algorithm */
        *keylen = outlen;
        if (key == NULL)
            return 1;
    }
    return EVP_KDF_derive(kctx, key, *keylen);
}

