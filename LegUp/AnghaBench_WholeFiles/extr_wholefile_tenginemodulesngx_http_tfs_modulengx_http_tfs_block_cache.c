#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_41__   TYPE_8__ ;
typedef  struct TYPE_40__   TYPE_7__ ;
typedef  struct TYPE_39__   TYPE_6__ ;
typedef  struct TYPE_38__   TYPE_5__ ;
typedef  struct TYPE_37__   TYPE_4__ ;
typedef  struct TYPE_36__   TYPE_3__ ;
typedef  struct TYPE_35__   TYPE_2__ ;
typedef  struct TYPE_34__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  scalar_t__ uint64_t ;
typedef  int uint32_t ;
typedef  int ngx_uint_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
typedef  int /*<<< orphan*/  ngx_log_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_34__ {size_t segment_index; TYPE_4__* segment_data; } ;
struct TYPE_36__ {int /*<<< orphan*/  name_server_addr; TYPE_1__ file; int /*<<< orphan*/  pool; } ;
typedef  TYPE_3__ ngx_http_tfs_t ;
struct TYPE_35__ {scalar_t__ block_id; } ;
struct TYPE_37__ {int cache_hit; TYPE_2__ segment_info; } ;
typedef  TYPE_4__ ngx_http_tfs_segment_data_t ;
typedef  int /*<<< orphan*/  ngx_http_tfs_block_cache_value_t ;
struct TYPE_38__ {scalar_t__ ns_addr; scalar_t__ block_id; } ;
typedef  TYPE_5__ ngx_http_tfs_block_cache_key_t ;
struct TYPE_41__ {TYPE_3__* data; } ;
struct TYPE_39__ {int curr_lookup_cache; int use_cache; TYPE_8__ remote_ctx; int /*<<< orphan*/  local_ctx; } ;
typedef  TYPE_6__ ngx_http_tfs_block_cache_ctx_t ;
struct TYPE_40__ {int nelts; } ;
typedef  TYPE_7__ ngx_array_t ;

/* Variables and functions */
 scalar_t__ NGX_DECLINED ; 
 scalar_t__ NGX_ERROR ; 
 int NGX_HTTP_TFS_LOCAL_BLOCK_CACHE ; 
 int NGX_HTTP_TFS_NO_BLOCK_CACHE ; 
 int NGX_HTTP_TFS_REMOTE_BLOCK_CACHE ; 
 scalar_t__ NGX_OK ; 
 scalar_t__ ngx_array_init (TYPE_7__*,int /*<<< orphan*/ ,int,int) ; 
 scalar_t__ ngx_array_push (TYPE_7__*) ; 
 int* ngx_crc32_table256 ; 
 scalar_t__ ngx_http_tfs_local_block_cache_batch_lookup (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_7__*,TYPE_7__*) ; 
 int /*<<< orphan*/  ngx_http_tfs_local_block_cache_insert (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_5__*,int /*<<< orphan*/ *) ; 
 scalar_t__ ngx_http_tfs_local_block_cache_lookup (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_5__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_http_tfs_local_block_cache_remove (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_5__*) ; 
 scalar_t__ ngx_http_tfs_remote_block_cache_batch_lookup (TYPE_8__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_7__*) ; 
 int /*<<< orphan*/  ngx_http_tfs_remote_block_cache_insert (TYPE_8__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_5__*,int /*<<< orphan*/ *) ; 
 scalar_t__ ngx_http_tfs_remote_block_cache_lookup (TYPE_8__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_5__*) ; 
 int /*<<< orphan*/  ngx_http_tfs_remote_block_cache_remove (TYPE_8__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_5__*) ; 

__attribute__((used)) static inline uint32_t
ngx_http_tfs_crc(uint32_t crc, const char *data, size_t len)
{
    size_t i;

    for (i = 0; i < len; ++i) {
        crc = (crc >> 8) ^ ngx_crc32_table256[(crc ^ *data++) & 0xff];
    }

    return crc;
}

ngx_int_t
ngx_http_tfs_block_cache_lookup(ngx_http_tfs_block_cache_ctx_t *ctx,
    ngx_pool_t *pool, ngx_log_t *log, ngx_http_tfs_block_cache_key_t *key,
    ngx_http_tfs_block_cache_value_t *value)
{
    ngx_int_t  rc = NGX_DECLINED;

    if (ctx->curr_lookup_cache == NGX_HTTP_TFS_LOCAL_BLOCK_CACHE) {

        ctx->curr_lookup_cache = NGX_HTTP_TFS_REMOTE_BLOCK_CACHE;

        if (ctx->use_cache & NGX_HTTP_TFS_LOCAL_BLOCK_CACHE) {
            rc = ngx_http_tfs_local_block_cache_lookup(ctx->local_ctx,
                                                       pool, log, key, value);

            if (rc == NGX_OK) {
                return rc;
            }
        }
    }

    if (ctx->curr_lookup_cache == NGX_HTTP_TFS_REMOTE_BLOCK_CACHE) {

        ctx->curr_lookup_cache = NGX_HTTP_TFS_NO_BLOCK_CACHE;

        if (ctx->use_cache & NGX_HTTP_TFS_REMOTE_BLOCK_CACHE) {
            rc = ngx_http_tfs_remote_block_cache_lookup(&ctx->remote_ctx,
                                                        pool, log, key);
        }
    }

    return rc;
}

void
ngx_http_tfs_block_cache_insert(ngx_http_tfs_block_cache_ctx_t *ctx,
    ngx_pool_t *pool, ngx_log_t *log, ngx_http_tfs_block_cache_key_t *key,
    ngx_http_tfs_block_cache_value_t *value)
{
    if (ctx->use_cache & NGX_HTTP_TFS_REMOTE_BLOCK_CACHE) {
        ngx_http_tfs_remote_block_cache_insert(&ctx->remote_ctx,
                                               pool, log, key, value);
    }

    if (ctx->use_cache & NGX_HTTP_TFS_LOCAL_BLOCK_CACHE) {
        ngx_http_tfs_local_block_cache_insert(ctx->local_ctx, log, key, value);
    }
}

void
ngx_http_tfs_block_cache_remove(ngx_http_tfs_block_cache_ctx_t *ctx,
    ngx_pool_t *pool, ngx_log_t *log, ngx_http_tfs_block_cache_key_t* key,
    uint8_t hit_status)
{
    if (hit_status != NGX_HTTP_TFS_NO_BLOCK_CACHE
        && (ctx->use_cache & NGX_HTTP_TFS_LOCAL_BLOCK_CACHE))
    {
        ngx_http_tfs_local_block_cache_remove(ctx->local_ctx, log, key);
    }

    if (hit_status == NGX_HTTP_TFS_REMOTE_BLOCK_CACHE) {
        ngx_http_tfs_remote_block_cache_remove(&ctx->remote_ctx,
                                               pool, log, key);
    }
}

ngx_int_t
ngx_http_tfs_block_cache_batch_lookup(ngx_http_tfs_block_cache_ctx_t *ctx,
    ngx_pool_t *pool, ngx_log_t *log, ngx_array_t *keys,
    ngx_array_t *kvs)
{
    uint32_t                        i;
    ngx_int_t                       rc;
    ngx_uint_t                      local_miss_count;
    ngx_array_t                     local_miss_keys;
    ngx_http_tfs_t                 *t;
    ngx_http_tfs_segment_data_t    *segment_data;
    ngx_http_tfs_block_cache_key_t *key;

    rc = NGX_DECLINED;

    if (ctx->curr_lookup_cache == NGX_HTTP_TFS_LOCAL_BLOCK_CACHE) {

        ctx->curr_lookup_cache = NGX_HTTP_TFS_REMOTE_BLOCK_CACHE;

        if (ctx->use_cache & NGX_HTTP_TFS_LOCAL_BLOCK_CACHE) {
            rc = ngx_http_tfs_local_block_cache_batch_lookup(ctx->local_ctx,
                                                             pool, log, keys,
                                                             kvs);

            if (rc == NGX_OK || rc == NGX_ERROR) {
                return rc;
            }
        }
    }

    /* rc == NGX_DECLIEND */
    if (ctx->curr_lookup_cache == NGX_HTTP_TFS_REMOTE_BLOCK_CACHE) {

        ctx->curr_lookup_cache = NGX_HTTP_TFS_NO_BLOCK_CACHE;

        if (ctx->use_cache & NGX_HTTP_TFS_REMOTE_BLOCK_CACHE) {
            t = ctx->remote_ctx.data;
            local_miss_count = keys->nelts - kvs->nelts;

            rc = ngx_array_init(&local_miss_keys, t->pool, local_miss_count,
                                sizeof(ngx_http_tfs_block_cache_key_t));
            if (rc == NGX_ERROR) {
                return rc;
            }

            segment_data = &t->file.segment_data[t->file.segment_index];
            for (i = 0; i < keys->nelts; i++, segment_data++) {
                if (segment_data->cache_hit == NGX_HTTP_TFS_NO_BLOCK_CACHE) {
                    key = (ngx_http_tfs_block_cache_key_t *)
                           ngx_array_push(&local_miss_keys);
                    key->ns_addr = *((uint64_t*)(&t->name_server_addr));
                    key->block_id = segment_data->segment_info.block_id;
                }
            }

            rc = ngx_http_tfs_remote_block_cache_batch_lookup(&ctx->remote_ctx,
                                                              pool, log,
                                                              &local_miss_keys);
        }
    }

    return rc;
}

ngx_int_t
ngx_http_tfs_block_cache_cmp(ngx_http_tfs_block_cache_key_t *left,
    ngx_http_tfs_block_cache_key_t *right)
{
    if (left->ns_addr == right->ns_addr) {

        if (left->block_id == right->block_id) {
            return 0;
        }

        if (left->block_id < right->block_id) {
            return -1;
        }

        return 1;
    }

    if (left->ns_addr < right->ns_addr) {
        return -1;
    }

    return 1;
}

