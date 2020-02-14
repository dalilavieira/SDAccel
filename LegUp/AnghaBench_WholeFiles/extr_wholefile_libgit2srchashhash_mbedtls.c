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
struct TYPE_9__ {int /*<<< orphan*/  id; } ;
typedef  TYPE_1__ git_oid ;
struct TYPE_10__ {int /*<<< orphan*/  c; } ;
typedef  TYPE_2__ git_hash_ctx ;

/* Variables and functions */
 int /*<<< orphan*/  assert (TYPE_2__*) ; 
 int /*<<< orphan*/  mbedtls_sha1_finish (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mbedtls_sha1_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mbedtls_sha1_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mbedtls_sha1_starts (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mbedtls_sha1_update (int /*<<< orphan*/ *,void const*,size_t) ; 

void git_hash_ctx_cleanup(git_hash_ctx *ctx)
{
    assert(ctx);
    mbedtls_sha1_free(&ctx->c);
}

int git_hash_init(git_hash_ctx *ctx)
{
    assert(ctx);
    mbedtls_sha1_init(&ctx->c);
    mbedtls_sha1_starts(&ctx->c);
    return 0;
}

int git_hash_update(git_hash_ctx *ctx, const void *data, size_t len)
{
    assert(ctx);
    mbedtls_sha1_update(&ctx->c, data, len);
    return 0;
}

int git_hash_final(git_oid *out, git_hash_ctx *ctx)
{
    assert(ctx);
    mbedtls_sha1_finish(&ctx->c, out->id);
    return 0;
}

