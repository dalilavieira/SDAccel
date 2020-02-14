#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  u_char ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  ngx_slab_pool_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
typedef  int /*<<< orphan*/  ngx_log_t ;
typedef  size_t ngx_int_t ;
struct TYPE_5__ {size_t area; TYPE_1__* server; } ;
typedef  TYPE_2__ ngx_http_tfs_tair_server_addr_info_t ;
typedef  int /*<<< orphan*/  ngx_http_tfs_tair_instance_t ;
typedef  int /*<<< orphan*/  ngx_http_tair_mget_handler_pt ;
typedef  int /*<<< orphan*/  ngx_http_tair_handler_pt ;
typedef  int /*<<< orphan*/  ngx_http_tair_get_handler_pt ;
typedef  int /*<<< orphan*/  ngx_http_tair_data_t ;
typedef  int /*<<< orphan*/  ngx_array_t ;
struct TYPE_4__ {int len; int /*<<< orphan*/ * data; } ;

/* Variables and functions */
 size_t NGX_ERROR ; 
 size_t NGX_HTTP_TFS_TAIR_SERVER_ADDR_PART_COUNT ; 
 size_t NGX_OK ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 size_t ngx_atoi (int /*<<< orphan*/ *,int) ; 
 int* ngx_crc32_table256 ; 
 int /*<<< orphan*/ * ngx_pcalloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * ngx_slab_alloc_locked (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * ngx_strlchr (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char) ; 

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
ngx_http_tfs_tair_get_helper(ngx_http_tfs_tair_instance_t *instance,
    ngx_pool_t *pool, ngx_log_t *log,
    ngx_http_tair_data_t *key, ngx_http_tair_get_handler_pt callback,
    void *data)
{
    return NGX_ERROR;
}

ngx_int_t ngx_http_tfs_tair_mget_helper(ngx_http_tfs_tair_instance_t *instance,
    ngx_pool_t *pool, ngx_log_t *log,
    ngx_array_t *kvs, ngx_http_tair_mget_handler_pt callback, void *data)
{
    return NGX_ERROR;
}

ngx_int_t
ngx_http_tfs_tair_put_helper(ngx_http_tfs_tair_instance_t *instance,
    ngx_pool_t *pool, ngx_log_t *log,
    ngx_http_tair_data_t *key, ngx_http_tair_data_t *value,
    ngx_int_t expire, ngx_int_t version,
    ngx_http_tair_handler_pt callback, void *data)
{
    return NGX_ERROR;
}

ngx_int_t
ngx_http_tfs_tair_delete_helper(ngx_http_tfs_tair_instance_t *instance,
    ngx_pool_t *pool, ngx_log_t *log,
    ngx_array_t *keys, ngx_http_tair_handler_pt callback, void *data)
{
    return NGX_ERROR;
}

ngx_int_t
ngx_http_tfs_parse_tair_server_addr_info(
    ngx_http_tfs_tair_server_addr_info_t *info,
    u_char *addr, uint32_t len, void *pool, uint8_t shared_memory)
{
    u_char    *temp, *p;
    ssize_t    info_size;
    ngx_int_t  i;

    p = addr;

    for (i = 0; i < NGX_HTTP_TFS_TAIR_SERVER_ADDR_PART_COUNT; i++) {
        temp = ngx_strlchr(p, p + len, ';');
        if (temp == NULL) {
            return NGX_ERROR;
        }

        info_size = temp - p;
        if (shared_memory) {
            info->server[i].data =
                ngx_slab_alloc_locked((ngx_slab_pool_t *)pool, info_size);
        } else {
            info->server[i].data = ngx_pcalloc((ngx_pool_t *)pool, info_size);
        }
        if (info->server[i].data == NULL) {
            return NGX_ERROR;
        }
        info->server[i].len = info_size;
        memcpy(info->server[i].data, p, info_size);

        p += info_size + 1;
        len -= (info_size + 1);
        if (len <= 0) {
            return NGX_ERROR;
        }
    }

    info->area = ngx_atoi(p, len);
    if (info->area == NGX_ERROR) {
        return NGX_ERROR;
    }

    return NGX_OK;
}

