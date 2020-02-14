#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int uint32_t ;
typedef  int uLongf ;
typedef  int /*<<< orphan*/  ngx_pool_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_20__ {TYPE_4__* loc_conf; int /*<<< orphan*/  log; TYPE_8__* tfs_peer; } ;
typedef  TYPE_5__ ngx_http_tfs_t ;
struct TYPE_21__ {int /*<<< orphan*/  version; int /*<<< orphan*/  length; int /*<<< orphan*/  table; } ;
typedef  TYPE_6__ ngx_http_tfs_rs_response_t ;
struct TYPE_16__ {int len; int crc; int /*<<< orphan*/  id; int /*<<< orphan*/  version; int /*<<< orphan*/  type; void* flag; } ;
struct TYPE_22__ {TYPE_1__ header; } ;
typedef  TYPE_7__ ngx_http_tfs_rs_request_t ;
struct TYPE_17__ {scalar_t__ pos; } ;
struct TYPE_23__ {TYPE_2__ body_buffer; } ;
typedef  TYPE_8__ ngx_http_tfs_peer_connection_t ;
struct TYPE_24__ {int /*<<< orphan*/ * next; TYPE_10__* buf; } ;
typedef  TYPE_9__ ngx_chain_t ;
struct TYPE_15__ {int last; scalar_t__ pos; } ;
typedef  TYPE_10__ ngx_buf_t ;
struct TYPE_18__ {int /*<<< orphan*/  version; scalar_t__ table; } ;
struct TYPE_19__ {TYPE_3__ meta_server_table; } ;
typedef  int /*<<< orphan*/  Bytef ;

/* Variables and functions */
 scalar_t__ NGX_ERROR ; 
 int NGX_HTTP_TFS_METASERVER_COUNT ; 
 void* NGX_HTTP_TFS_PACKET_FLAG ; 
 int /*<<< orphan*/  NGX_HTTP_TFS_PACKET_VERSION ; 
 int /*<<< orphan*/  NGX_HTTP_TFS_REQ_RT_GET_TABLE_MESSAGE ; 
 int /*<<< orphan*/  NGX_LOG_ERR ; 
 scalar_t__ NGX_OK ; 
 scalar_t__ Z_OK ; 
 int /*<<< orphan*/  errno ; 
 TYPE_9__* ngx_alloc_chain_link (int /*<<< orphan*/ *) ; 
 int* ngx_crc32_table256 ; 
 TYPE_10__* ngx_create_temp_buf (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ngx_http_tfs_generate_packet_id () ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ uncompress (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint32_t
ngx_http_tfs_crc(uint32_t crc, const char *data, size_t len)
{
    size_t i;

    for (i = 0; i < len; ++i) {
        crc = (crc >> 8) ^ ngx_crc32_table256[(crc ^ *data++) & 0xff];
    }

    return crc;
}

ngx_chain_t *
ngx_http_tfs_root_server_create_message(ngx_pool_t *pool)
{
    ngx_buf_t                  *b;
    ngx_chain_t                *cl;
    ngx_http_tfs_rs_request_t  *req;

    b = ngx_create_temp_buf(pool, sizeof(ngx_http_tfs_rs_request_t));
    if (b == NULL) {
        return NULL;
    }

    req = (ngx_http_tfs_rs_request_t *) b->pos;
    req->header.flag = NGX_HTTP_TFS_PACKET_FLAG;
    req->header.len = sizeof(uint8_t);
    req->header.type = NGX_HTTP_TFS_REQ_RT_GET_TABLE_MESSAGE;
    req->header.version = NGX_HTTP_TFS_PACKET_VERSION;
    req->header.crc = ngx_http_tfs_crc(NGX_HTTP_TFS_PACKET_FLAG,
                                       (const char *) (&req->header + 1),
                                       req->header.len);
    req->header.id = ngx_http_tfs_generate_packet_id();

    b->last += sizeof(ngx_http_tfs_rs_request_t);

    cl = ngx_alloc_chain_link(pool);
    if (cl == NULL) {
        return NULL;
    }

    cl->buf = b;
    cl->next = NULL;

    return cl;
}

ngx_int_t
ngx_http_tfs_root_server_parse_message(ngx_http_tfs_t *t)
{
    uLongf                           table_length;
    ngx_int_t                        rc;
    ngx_http_tfs_rs_response_t      *resp;
    ngx_http_tfs_peer_connection_t  *tp;

    tp = t->tfs_peer;
    resp = (ngx_http_tfs_rs_response_t *) (tp->body_buffer.pos);
    table_length = NGX_HTTP_TFS_METASERVER_COUNT * sizeof(uint64_t);

    rc = uncompress((Bytef *) (t->loc_conf->meta_server_table.table),
                    &table_length, resp->table, resp->length);
    if (rc != Z_OK) {
        ngx_log_error(NGX_LOG_ERR, t->log, errno, "uncompress error");
        return NGX_ERROR;
    }

    t->loc_conf->meta_server_table.version = resp->version;

    return NGX_OK;
}

