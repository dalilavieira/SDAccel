#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  u_char ;
struct TYPE_11__ {scalar_t__ len; int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ ngx_str_t ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_12__ {int oper_app_id; int oper_type; int /*<<< orphan*/  oper_succ; int /*<<< orphan*/  oper_rt; int /*<<< orphan*/  oper_size; int /*<<< orphan*/  oper_times; } ;
typedef  TYPE_2__ ngx_http_tfs_stat_rcs_t ;
struct TYPE_13__ {TYPE_2__* stat_rcs; } ;
typedef  TYPE_3__ ngx_http_tfs_rcs_info_t ;

/* Variables and functions */
 scalar_t__ NGX_ERROR ; 
 scalar_t__ NGX_HTTP_TFS_OPER_COUNT ; 
 scalar_t__ NGX_OK ; 
 int* ngx_crc32_table256 ; 
 int /*<<< orphan*/  ngx_memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  ngx_memzero (TYPE_1__*,int) ; 
 void* ngx_pcalloc (int /*<<< orphan*/ *,int) ; 
 TYPE_1__* ngx_prealloc (int /*<<< orphan*/ *,TYPE_1__*,int,int) ; 

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
ngx_http_tfs_serialize_string(u_char **p,
    ngx_str_t *string)
{
    if (p == NULL || *p == NULL || string == NULL) {
        return NGX_ERROR;
    }

    if (string->len == 0) {
        *((uint32_t *)*p) = 0;

    } else {
        *((uint32_t *)*p) = string->len + 1;
    }
    *p += sizeof(uint32_t);

    if (string->len > 0) {
        ngx_memcpy(*p, string->data, string->len);
        *p += string->len + 1;
    }

    return NGX_OK;
}

ngx_int_t
ngx_http_tfs_deserialize_string(u_char **p, ngx_pool_t *pool,
    ngx_str_t *string)
{
    if (p == NULL || *p == NULL || pool == NULL || string == NULL) {
        return NGX_ERROR;
    }

    string->len = *((uint32_t *)*p);
    (*p) += sizeof(uint32_t);

    if (string->len > 0) {
        /* this length includes '/0' */
        string->len -= 1;
        string->data = ngx_pcalloc(pool, string->len);
        if (string->data == NULL) {
            return NGX_ERROR;
        }
        ngx_memcpy(string->data, (*p), string->len);
        (*p) += string->len + 1;
    }

    return NGX_OK;
}

ngx_int_t
ngx_http_tfs_deserialize_vstring(u_char **p, ngx_pool_t *pool,
    uint32_t *count, ngx_str_t **string)
{
    uint32_t   new_count, i;
    ngx_int_t  rc;

    /* count */
    new_count = *((uint32_t *)*p);
    (*p) += sizeof(uint32_t);

    /* string */
    if (new_count > 0) {
        if (*string == NULL) {
            *string = ngx_pcalloc(pool, sizeof(ngx_str_t) * new_count);
            if (*string == NULL) {
                return NGX_ERROR;
            }

        } else if (new_count > *count) {
            *string = ngx_prealloc(pool, *string, sizeof(ngx_str_t) * (*count),
                                   sizeof(ngx_str_t) * new_count);
            if (*string == NULL) {
                return NGX_ERROR;
            }
            ngx_memzero(*string, sizeof(ngx_str_t) * new_count);
        }
        for (i = 0; i < new_count; i++) {
            rc = ngx_http_tfs_deserialize_string(p, pool, (*string) + i);
            if (rc == NGX_ERROR) {
                return NGX_ERROR;
            }
        }
    }
    *count = new_count;

    return NGX_OK;
}

ngx_int_t
ngx_http_tfs_serialize_rcs_stat(u_char **p,
    ngx_http_tfs_rcs_info_t  *rc_info, ngx_int_t *count)
{
    ngx_int_t                    i;
    ngx_http_tfs_stat_rcs_t     *stat_rcs;

    if (p == NULL || rc_info == NULL || count == NULL) {
        return NGX_ERROR;
    }

    *count = 0;
    stat_rcs = rc_info->stat_rcs;

    for (i = 0; i < NGX_HTTP_TFS_OPER_COUNT; ++i) {
        if (stat_rcs[i].oper_app_id == 0) {
            continue;
        }

        *((uint32_t *)*p) = (stat_rcs[i].oper_app_id << 16) | stat_rcs[i].oper_type;
        (*p) += sizeof(uint32_t);

        *((uint32_t *)*p) = (stat_rcs[i].oper_app_id << 16) | stat_rcs[i].oper_type;
        (*p) += sizeof(uint32_t);
        *((uint64_t *)*p) = stat_rcs[i].oper_times;
        (*p) += sizeof(uint64_t);
        *((uint64_t *)*p) = stat_rcs[i].oper_size;
        (*p) += sizeof(uint64_t);
        *((uint64_t *)*p) = stat_rcs[i].oper_rt;
        (*p) += sizeof(uint64_t);
        *((uint64_t *)*p) = stat_rcs[i].oper_succ;
        (*p) += sizeof(uint64_t);

        ++(*count);
    }

    return NGX_OK;
}

