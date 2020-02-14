#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_55__   TYPE_9__ ;
typedef  struct TYPE_54__   TYPE_8__ ;
typedef  struct TYPE_53__   TYPE_7__ ;
typedef  struct TYPE_52__   TYPE_6__ ;
typedef  struct TYPE_51__   TYPE_5__ ;
typedef  struct TYPE_50__   TYPE_4__ ;
typedef  struct TYPE_49__   TYPE_3__ ;
typedef  struct TYPE_48__   TYPE_2__ ;
typedef  struct TYPE_47__   TYPE_1__ ;
typedef  struct TYPE_46__   TYPE_14__ ;
typedef  struct TYPE_45__   TYPE_13__ ;
typedef  struct TYPE_44__   TYPE_11__ ;
typedef  struct TYPE_43__   TYPE_10__ ;

/* Type definitions */
typedef  void* uint64_t ;
typedef  int uint32_t ;
typedef  void* u_char ;
typedef  scalar_t__ ngx_uint_t ;
typedef  int /*<<< orphan*/  ngx_str_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
typedef  int /*<<< orphan*/  ngx_log_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_52__ {size_t segment_index; int segment_count; int /*<<< orphan*/  curr_batch_count; TYPE_8__* segment_data; } ;
struct TYPE_50__ {int use_cache; int /*<<< orphan*/  local_ctx; } ;
struct TYPE_53__ {int state; int /*<<< orphan*/ * log; int /*<<< orphan*/  decline_handler; TYPE_6__ file; int /*<<< orphan*/ * pool; int /*<<< orphan*/  name_server_addr_text; TYPE_4__ block_cache_ctx; int /*<<< orphan*/  data; int /*<<< orphan*/ * tfs_peer_servers; } ;
typedef  TYPE_7__ ngx_http_tfs_t ;
struct TYPE_51__ {int block_id; } ;
struct TYPE_49__ {int ds_count; void** ds_addrs; } ;
struct TYPE_54__ {TYPE_5__ segment_info; void* cache_hit; TYPE_3__ block_info; } ;
typedef  TYPE_8__ ngx_http_tfs_segment_data_t ;
struct TYPE_55__ {TYPE_7__* data; int /*<<< orphan*/  tair_instance; } ;
typedef  TYPE_9__ ngx_http_tfs_remote_block_cache_ctx_t ;
typedef  int /*<<< orphan*/  ngx_http_tfs_inet_t ;
struct TYPE_43__ {int ds_count; void** ds_addrs; } ;
typedef  TYPE_10__ ngx_http_tfs_block_cache_value_t ;
struct TYPE_47__ {void** data; void* len; void* type; } ;
struct TYPE_44__ {int block_id; scalar_t__ rc; int /*<<< orphan*/ * ns_addr; TYPE_2__* value; TYPE_1__ key; } ;
typedef  TYPE_11__ ngx_http_tfs_block_cache_key_t ;
typedef  TYPE_11__ ngx_http_tair_key_value_t ;
struct TYPE_45__ {void** data; int len; void* type; } ;
typedef  TYPE_13__ ngx_http_tair_data_t ;
struct TYPE_46__ {scalar_t__ nelts; TYPE_11__* elts; } ;
typedef  TYPE_14__ ngx_array_t ;
struct TYPE_48__ {void** data; scalar_t__ len; } ;

/* Variables and functions */
 scalar_t__ NGX_DECLINED ; 
 scalar_t__ NGX_ERROR ; 
 scalar_t__ NGX_HTTP_ETAIR_SUCCESS ; 
 int /*<<< orphan*/  NGX_HTTP_INTERNAL_SERVER_ERROR ; 
 void* NGX_HTTP_TAIR_INT ; 
 void* NGX_HTTP_TFS_BLOCK_CACHE_KEY_SIZE ; 
 size_t NGX_HTTP_TFS_DATA_SERVER ; 
 int NGX_HTTP_TFS_LOCAL_BLOCK_CACHE ; 
 int NGX_HTTP_TFS_MAX_BATCH_COUNT ; 
 void* NGX_HTTP_TFS_REMOTE_BLOCK_CACHE ; 
 scalar_t__ NGX_HTTP_TFS_REMOTE_BLOCK_CACHE_VALUE_BASE_SIZE ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_HTTP ; 
 scalar_t__ NGX_OK ; 
 TYPE_14__* ngx_array_create (int /*<<< orphan*/ *,scalar_t__,int) ; 
 scalar_t__ ngx_array_init (TYPE_14__*,int /*<<< orphan*/ *,int,int) ; 
 scalar_t__ ngx_array_push (TYPE_14__*) ; 
 int* ngx_crc32_table256 ; 
 int /*<<< orphan*/ * ngx_create_pool (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_destroy_pool (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_http_tfs_batch_process_start ; 
 int /*<<< orphan*/  ngx_http_tfs_finalize_request (int /*<<< orphan*/ ,TYPE_7__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_http_tfs_finalize_state (TYPE_7__*,scalar_t__) ; 
 int /*<<< orphan*/  ngx_http_tfs_local_block_cache_insert (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_11__*,TYPE_10__*) ; 
 int /*<<< orphan*/  ngx_http_tfs_peer_set_addr (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
static  void ngx_http_tfs_remote_block_cache_dummy_handler (scalar_t__,void*) ; 
static  void ngx_http_tfs_remote_block_cache_get_handler (TYPE_11__*,scalar_t__,void*) ; 
static  void ngx_http_tfs_remote_block_cache_mget_handler (TYPE_14__*,scalar_t__,void*) ; 
 void ngx_http_tfs_remote_block_cache_remove (TYPE_9__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_11__*) ; 
 int /*<<< orphan*/ * ngx_http_tfs_select_data_server (TYPE_7__*,TYPE_8__*) ; 
 int /*<<< orphan*/  ngx_http_tfs_tair_delete_helper (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_14__*,void (*) (scalar_t__,void*),void*) ; 
 scalar_t__ ngx_http_tfs_tair_get_helper (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_13__*,void (*) (TYPE_11__*,scalar_t__,void*),void*) ; 
 scalar_t__ ngx_http_tfs_tair_mget_helper (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_14__*,void (*) (TYPE_14__*,scalar_t__,void*),void*) ; 
 scalar_t__ ngx_http_tfs_tair_put_helper (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_13__*,TYPE_13__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (scalar_t__,void*),void*) ; 
 int /*<<< orphan*/  ngx_log_debug0 (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ngx_log_debug1 (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,scalar_t__) ; 
 int /*<<< orphan*/  ngx_log_debug2 (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ngx_memcpy (void**,void**,int) ; 
 void* ngx_pcalloc (int /*<<< orphan*/ *,int) ; 

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
ngx_http_tfs_remote_block_cache_lookup(
    ngx_http_tfs_remote_block_cache_ctx_t *ctx,
    ngx_pool_t *pool, ngx_log_t *log, ngx_http_tfs_block_cache_key_t* key)
{
    ngx_int_t             rc;
    ngx_http_tair_data_t  tair_key;

    ngx_log_debug2(NGX_LOG_DEBUG_HTTP, log, 0,
                   "lookup remote block cache, ns addr: %uL, block id: %uD",
                   key->ns_addr, key->block_id);

    tair_key.type = NGX_HTTP_TAIR_INT;
    tair_key.data = (u_char *)key;
    tair_key.len = NGX_HTTP_TFS_BLOCK_CACHE_KEY_SIZE;

    rc = ngx_http_tfs_tair_get_helper(
                                    ctx->tair_instance,
                                    pool, log,
                                    &tair_key,
                                    ngx_http_tfs_remote_block_cache_get_handler,
                                    (void *)ctx);

    return rc;
}

__attribute__((used)) static void
ngx_http_tfs_remote_block_cache_get_handler(ngx_http_tair_key_value_t *kv,
    ngx_int_t rc, void *data)
{
    u_char                                 *p, *q;
    uint32_t                                ds_count;
    ngx_http_tfs_t                         *t;
    ngx_http_tfs_inet_t                    *addr;
    ngx_http_tfs_segment_data_t            *segment_data;
    ngx_http_tfs_block_cache_key_t          key;
    ngx_http_tfs_block_cache_value_t        value;
    ngx_http_tfs_remote_block_cache_ctx_t  *ctx = data;

    t = ctx->data;
    segment_data = &t->file.segment_data[t->file.segment_index];
    if (rc == NGX_HTTP_ETAIR_SUCCESS) {
        q = kv->key.data;
        p = kv->value->data;
        if (p != NULL
            && (kv->value->len
                > NGX_HTTP_TFS_REMOTE_BLOCK_CACHE_VALUE_BASE_SIZE))
        {
            key.ns_addr = *(uint64_t *)q;
            q += sizeof(uint64_t);
            key.block_id = *(uint32_t *)q;

            ds_count = *(uint32_t *)p;
            p += sizeof(uint32_t);

            if (ds_count > 0) {
                segment_data->block_info.ds_count = ds_count;
                segment_data->block_info.ds_addrs = ngx_pcalloc(t->pool,
                                       sizeof(ngx_http_tfs_inet_t) * ds_count);
                if (segment_data->block_info.ds_addrs == NULL) {
                    ngx_http_tfs_finalize_request(t->data, t,
                                                NGX_HTTP_INTERNAL_SERVER_ERROR);
                    return;
                }
                ngx_memcpy(segment_data->block_info.ds_addrs, p,
                           ds_count * sizeof(ngx_http_tfs_inet_t));

                /* insert local block cache */
                if (t->block_cache_ctx.use_cache
                    & NGX_HTTP_TFS_LOCAL_BLOCK_CACHE)
                {
                    value.ds_count = ds_count;
                    value.ds_addrs =
                        (uint64_t *)segment_data->block_info.ds_addrs;
                    ngx_http_tfs_local_block_cache_insert(
                                                   t->block_cache_ctx.local_ctx,
                                                   t->log, &key, &value);
                }

                /* skip GET_BLK_INFO state */
                t->state += 1;

                segment_data->cache_hit = NGX_HTTP_TFS_REMOTE_BLOCK_CACHE;

                /* select data server */
                addr = ngx_http_tfs_select_data_server(t, segment_data);

                ngx_http_tfs_peer_set_addr(t->pool,
                                           &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER],
                                           addr);

            } else {
                /* remote block cache invalid, need remove it */
                ngx_http_tfs_remote_block_cache_remove(ctx, t->pool, t->log,
                                                       &key);
            }
        }

    } else {
        ngx_log_debug2(NGX_LOG_DEBUG_HTTP, t->log, 0,
                       "lookup remote block cache, "
                       "ns addr: %V, block id: %uD not found",
                       &t->name_server_addr_text,
                       segment_data->segment_info.block_id);
    }

    ngx_http_tfs_finalize_state(t, NGX_OK);
}

ngx_int_t
ngx_http_tfs_remote_block_cache_insert(
    ngx_http_tfs_remote_block_cache_ctx_t *ctx,
    ngx_pool_t *pool, ngx_log_t *log,
    ngx_http_tfs_block_cache_key_t *key,
    ngx_http_tfs_block_cache_value_t *value)
{
    ngx_int_t             rc;
    ngx_pool_t           *tmp_pool;
    ngx_http_tair_data_t  tair_key, tair_value;

    ngx_log_debug2(NGX_LOG_DEBUG_HTTP, log, 0,
                   "insert remote block cache, "
                   "ns addr: %uL, block id: %uD",
                   key->ns_addr, key->block_id);

    tair_key.type = NGX_HTTP_TAIR_INT;
    tair_key.data = (u_char *)key;
    tair_key.len = NGX_HTTP_TFS_BLOCK_CACHE_KEY_SIZE;

    tair_value.len = NGX_HTTP_TFS_REMOTE_BLOCK_CACHE_VALUE_BASE_SIZE
                      + value->ds_count * sizeof(uint64_t);
    tair_value.data = ngx_pcalloc(pool, tair_value.len);
    if (tair_value.data == NULL) {
        return NGX_ERROR;
    }
    *(uint32_t*)tair_value.data = value->ds_count;
    ngx_memcpy(tair_value.data+ NGX_HTTP_TFS_REMOTE_BLOCK_CACHE_VALUE_BASE_SIZE,
               value->ds_addrs, value->ds_count * sizeof(uint64_t));
    tair_value.type = NGX_HTTP_TAIR_INT;

    /* since we do not care returns,
     * we make a tmp pool and destroy it in callback
     */
    tmp_pool = ngx_create_pool(4096, log);
    if (tmp_pool == NULL) {
        return NGX_ERROR;
    }

    rc = ngx_http_tfs_tair_put_helper(
                                  ctx->tair_instance,
                                  tmp_pool, log,
                                  &tair_key, &tair_value,
                                  0/*expire*/, 0/* do not care version */,
                                  ngx_http_tfs_remote_block_cache_dummy_handler,
                                  (void *)tmp_pool);

    return rc;
}

__attribute__((used)) static void
ngx_http_tfs_remote_block_cache_dummy_handler(ngx_int_t rc, void *data)
{
    ngx_destroy_pool((ngx_pool_t *)data);
}

void
ngx_http_tfs_remote_block_cache_remove(
    ngx_http_tfs_remote_block_cache_ctx_t *ctx,
    ngx_pool_t *pool, ngx_log_t *log, ngx_http_tfs_block_cache_key_t* key)
{
    ngx_int_t              rc;
    ngx_pool_t            *tmp_pool;
    ngx_array_t            tair_keys;
    ngx_http_tair_data_t  *tair_key;

    ngx_log_debug2(NGX_LOG_DEBUG_HTTP, log, 0,
                   "remove remote block cache, ns addr: %uL, block id: %uD",
                   key->ns_addr, key->block_id);

    rc = ngx_array_init(&tair_keys, pool, 1, sizeof(ngx_http_tair_data_t));
    if (rc == NGX_ERROR) {
        return;
    }
    tair_key = (ngx_http_tair_data_t*) ngx_array_push(&tair_keys);

    tair_key->type = NGX_HTTP_TAIR_INT;
    tair_key->data = (u_char *)key;
    tair_key->len = NGX_HTTP_TFS_BLOCK_CACHE_KEY_SIZE;

    /* since we do not care returns,
     * we make a tmp pool and destroy it in callback
     */
    tmp_pool = ngx_create_pool(4096, log);
    if (tmp_pool == NULL) {
        return;
    }

    (void) ngx_http_tfs_tair_delete_helper(
                                  ctx->tair_instance,
                                  tmp_pool, log,
                                  &tair_keys,
                                  ngx_http_tfs_remote_block_cache_dummy_handler,
                                  (void *)tmp_pool);

}

ngx_int_t
ngx_http_tfs_remote_block_cache_batch_lookup(
    ngx_http_tfs_remote_block_cache_ctx_t *ctx,
    ngx_pool_t *pool, ngx_log_t *log, ngx_array_t* keys)
{
    ngx_int_t                        rc;
    ngx_uint_t                       i;
    ngx_array_t                     *tair_kvs;
    ngx_http_tair_key_value_t       *tair_kv;
    ngx_http_tfs_block_cache_key_t  *key;

    tair_kvs = ngx_array_create(pool, keys->nelts,
                                sizeof(ngx_http_tair_key_value_t));
    if (tair_kvs == NULL) {
        return NGX_ERROR;
    }

    key = keys->elts;
    for (i = 0; i < keys->nelts; i++, key++) {
        ngx_log_debug2(NGX_LOG_DEBUG_HTTP, log, 0,
                       "batch lookup remote block cache, "
                       "ns addr: %uL, block id: %uD",
                       key->ns_addr, key->block_id);

        tair_kv = (ngx_http_tair_key_value_t *)ngx_array_push(tair_kvs);
        if (tair_kv == NULL) {
            return NGX_ERROR;
        }

        tair_kv->key.type = NGX_HTTP_TAIR_INT;
        tair_kv->key.data = (u_char *)key;
        tair_kv->key.len = NGX_HTTP_TFS_BLOCK_CACHE_KEY_SIZE;
    }

    rc = ngx_http_tfs_tair_mget_helper(
                                   ctx->tair_instance,
                                   pool, log,
                                   tair_kvs,
                                   ngx_http_tfs_remote_block_cache_mget_handler,
                                   (void *)ctx);
    return rc;
}

__attribute__((used)) static void
ngx_http_tfs_remote_block_cache_mget_handler(ngx_array_t *kvs, ngx_int_t rc,
    void *data)
{
    u_char                                 *p, *q;
    uint32_t                                ds_count, block_count;
    ngx_uint_t                              i, j, hit_count;
    ngx_http_tfs_t                         *t;
    ngx_http_tair_key_value_t              *kv;
    ngx_http_tfs_segment_data_t            *segment_data;
    ngx_http_tfs_block_cache_key_t          key;
    ngx_http_tfs_block_cache_value_t        value;
    ngx_http_tfs_remote_block_cache_ctx_t  *ctx = data;

    t = ctx->data;

    segment_data = &t->file.segment_data[t->file.segment_index];
    block_count = t->file.segment_count - t->file.segment_index;
    if (block_count > NGX_HTTP_TFS_MAX_BATCH_COUNT) {
        block_count = NGX_HTTP_TFS_MAX_BATCH_COUNT;
    }

    if (rc == NGX_OK) {
        kv = kvs->elts;
        hit_count = 0;
        for (i = 0; i < kvs->nelts; i++, kv++) {
            if (kv->rc != NGX_HTTP_ETAIR_SUCCESS) {
                continue;
            }
            q = kv->key.data;
            p = kv->value->data;
            if (p != NULL
                && (kv->value->len
                    > NGX_HTTP_TFS_REMOTE_BLOCK_CACHE_VALUE_BASE_SIZE))
            {
                key.ns_addr = *(uint64_t *)q;
                q += sizeof(uint64_t);
                key.block_id = *(uint32_t *)q;

                ds_count = *(uint32_t *)p;
                p += sizeof(uint32_t);

                if (ds_count > 0) {
                    /* find out segment */
                    for (j = 0; j < block_count; j++) {
                        if(segment_data[j].segment_info.block_id == key.block_id
                           && segment_data[j].block_info.ds_addrs == NULL)
                        {
                            break;
                        }
                    }
                    /* not found, some error happen */
                    if (j == block_count) {
                        continue;
                    }

                    segment_data[j].block_info.ds_count = ds_count;
                    segment_data[j].block_info.ds_addrs = ngx_pcalloc(t->pool,
                                        ds_count * sizeof(ngx_http_tfs_inet_t));
                    if (segment_data[j].block_info.ds_addrs == NULL) {
                        ngx_http_tfs_finalize_request(t->data, t,
                                                NGX_HTTP_INTERNAL_SERVER_ERROR);
                        return;
                    }
                    ngx_memcpy(segment_data[j].block_info.ds_addrs, p,
                               ds_count * sizeof(ngx_http_tfs_inet_t));

                    if (t->block_cache_ctx.use_cache
                        & NGX_HTTP_TFS_LOCAL_BLOCK_CACHE)
                    {
                        value.ds_count = ds_count;
                        value.ds_addrs =
                            (uint64_t *)segment_data[j].block_info.ds_addrs;
                        ngx_http_tfs_local_block_cache_insert(
                            t->block_cache_ctx.local_ctx, t->log, &key, &value);
                    }

                    hit_count++;
                    segment_data[j].cache_hit = NGX_HTTP_TFS_REMOTE_BLOCK_CACHE;

                    ngx_log_debug2(NGX_LOG_DEBUG_HTTP, t->log, 0,
                                   "remote block cache hit, "
                                   "ns addr: %V, block id: %uD",
                                   &t->name_server_addr_text,
                                   segment_data[j].segment_info.block_id);

                } else {
                    /* remote block cache invalid, need remove it */
                    ngx_http_tfs_remote_block_cache_remove(ctx, t->pool, t->log,
                                                           &key);
                }
            }
        }

        if (hit_count > 0) {
            ngx_log_debug1(NGX_LOG_DEBUG_HTTP, t->log, 0,
                           "batch lookup remote block cache, hit_count: %ui",
                           hit_count);

            /* remote block cache hit count */
            t->file.curr_batch_count += hit_count;

            if (hit_count == kvs->nelts) {
                /* all cache hit, start batch process */
                t->decline_handler = ngx_http_tfs_batch_process_start;
                rc = NGX_DECLINED;
            }
        }

    } else {
        rc = NGX_OK;
        ngx_log_debug0(NGX_LOG_DEBUG_HTTP, t->log, 0,
                       "remote block cache miss");
    }

    ngx_http_tfs_finalize_state(t, rc);
}

ngx_int_t
ngx_http_tfs_get_remote_block_cache_instance(
    ngx_http_tfs_remote_block_cache_ctx_t *ctx,
    ngx_str_t *server_addr)
{
    return NGX_ERROR;
}

