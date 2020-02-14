#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_9__ ;
typedef  struct TYPE_27__   TYPE_8__ ;
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_6__ ;
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;
typedef  struct TYPE_19__   TYPE_10__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct sockaddr_in {int /*<<< orphan*/  sin_port; int /*<<< orphan*/  sin_addr; } ;
typedef  int /*<<< orphan*/  ngx_int_t ;
struct TYPE_25__ {int code; } ;
struct TYPE_26__ {int version; TYPE_6__ action; } ;
struct TYPE_27__ {int tfs_peer_count; TYPE_7__ r_ctx; TYPE_9__* tfs_peer; int /*<<< orphan*/ * input_filter; TYPE_9__* tfs_peer_servers; void* process_request_body; void* create_request; int /*<<< orphan*/  state; int /*<<< orphan*/ * retry_handler; int /*<<< orphan*/  log; TYPE_4__* loc_conf; int /*<<< orphan*/  pool; TYPE_1__* main_conf; } ;
typedef  TYPE_8__ ngx_http_tfs_t ;
struct TYPE_24__ {void* log_error; int /*<<< orphan*/  free; int /*<<< orphan*/  get; TYPE_10__* data; int /*<<< orphan*/ * name; int /*<<< orphan*/  log; scalar_t__ sockaddr; int /*<<< orphan*/  socklen; } ;
struct TYPE_28__ {TYPE_5__ peer; int /*<<< orphan*/  peer_addr_text; } ;
typedef  TYPE_9__ ngx_http_tfs_peer_connection_t ;
struct TYPE_19__ {int /*<<< orphan*/  free_peer; int /*<<< orphan*/  get_peer; } ;
typedef  TYPE_10__ ngx_http_connection_pool_t ;
struct TYPE_23__ {TYPE_3__* upstream; } ;
struct TYPE_22__ {TYPE_2__* ups_addr; scalar_t__ enable_rcs; } ;
struct TYPE_21__ {int /*<<< orphan*/  socklen; scalar_t__ sockaddr; } ;
struct TYPE_20__ {TYPE_10__* conn_pool; } ;

/* Variables and functions */
 int /*<<< orphan*/  NGX_ERROR ; 
 void* NGX_ERROR_ERR ; 
#define  NGX_HTTP_TFS_ACTION_CREATE_DIR 178 
#define  NGX_HTTP_TFS_ACTION_CREATE_FILE 177 
#define  NGX_HTTP_TFS_ACTION_GET_APPID 176 
#define  NGX_HTTP_TFS_ACTION_KEEPALIVE 175 
#define  NGX_HTTP_TFS_ACTION_LS_DIR 174 
#define  NGX_HTTP_TFS_ACTION_LS_FILE 173 
#define  NGX_HTTP_TFS_ACTION_MOVE_DIR 172 
#define  NGX_HTTP_TFS_ACTION_MOVE_FILE 171 
#define  NGX_HTTP_TFS_ACTION_READ_FILE 170 
#define  NGX_HTTP_TFS_ACTION_REMOVE_DIR 169 
#define  NGX_HTTP_TFS_ACTION_REMOVE_FILE 168 
#define  NGX_HTTP_TFS_ACTION_STAT_FILE 167 
#define  NGX_HTTP_TFS_ACTION_WRITE_FILE 166 
 size_t NGX_HTTP_TFS_DATA_SERVER ; 
 size_t NGX_HTTP_TFS_META_SERVER ; 
 size_t NGX_HTTP_TFS_NAME_SERVER ; 
 size_t NGX_HTTP_TFS_RC_SERVER ; 
 size_t NGX_HTTP_TFS_ROOT_SERVER ; 
 int NGX_HTTP_TFS_SERVER_COUNT ; 
#define  NGX_HTTP_TFS_STATE_ACTION_DONE 165 
#define  NGX_HTTP_TFS_STATE_ACTION_GET_META_TABLE 164 
#define  NGX_HTTP_TFS_STATE_ACTION_PROCESS 163 
#define  NGX_HTTP_TFS_STATE_ACTION_START 162 
#define  NGX_HTTP_TFS_STATE_READ_DONE 161 
#define  NGX_HTTP_TFS_STATE_READ_GET_BLK_INFO 160 
#define  NGX_HTTP_TFS_STATE_READ_GET_FRAG_INFO 159 
#define  NGX_HTTP_TFS_STATE_READ_GET_META_TABLE 158 
#define  NGX_HTTP_TFS_STATE_READ_READ_DATA 157 
#define  NGX_HTTP_TFS_STATE_READ_START 156 
#define  NGX_HTTP_TFS_STATE_REMOVE_DELETE_DATA 155 
#define  NGX_HTTP_TFS_STATE_REMOVE_DONE 154 
#define  NGX_HTTP_TFS_STATE_REMOVE_GET_BLK_INFO 153 
#define  NGX_HTTP_TFS_STATE_REMOVE_GET_FRAG_INFO 152 
#define  NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_COUNT 151 
#define  NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_SEQ 150 
#define  NGX_HTTP_TFS_STATE_REMOVE_GET_META_TABLE 149 
#define  NGX_HTTP_TFS_STATE_REMOVE_NOTIFY_MS 148 
#define  NGX_HTTP_TFS_STATE_REMOVE_READ_META_SEGMENT 147 
#define  NGX_HTTP_TFS_STATE_REMOVE_START 146 
#define  NGX_HTTP_TFS_STATE_REMOVE_STAT_FILE 145 
#define  NGX_HTTP_TFS_STATE_STAT_GET_BLK_INFO 144 
#define  NGX_HTTP_TFS_STATE_STAT_START 143 
#define  NGX_HTTP_TFS_STATE_STAT_STAT_FILE 142 
#define  NGX_HTTP_TFS_STATE_WRITE_CLOSE_FILE 141 
#define  NGX_HTTP_TFS_STATE_WRITE_CLUSTER_ID_MS 140 
#define  NGX_HTTP_TFS_STATE_WRITE_CLUSTER_ID_NS 139 
#define  NGX_HTTP_TFS_STATE_WRITE_CREATE_FILE_NAME 138 
#define  NGX_HTTP_TFS_STATE_WRITE_DELETE_DATA 137 
#define  NGX_HTTP_TFS_STATE_WRITE_DONE 136 
#define  NGX_HTTP_TFS_STATE_WRITE_GET_BLK_INFO 135 
#define  NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_COUNT 134 
#define  NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_SEQ 133 
#define  NGX_HTTP_TFS_STATE_WRITE_GET_META_TABLE 132 
#define  NGX_HTTP_TFS_STATE_WRITE_START 131 
#define  NGX_HTTP_TFS_STATE_WRITE_STAT_DUP_FILE 130 
#define  NGX_HTTP_TFS_STATE_WRITE_WRITE_DATA 129 
#define  NGX_HTTP_TFS_STATE_WRITE_WRITE_MS 128 
 int /*<<< orphan*/  NGX_OK ; 
 int /*<<< orphan*/  ds_name ; 
 char* inet_ntoa (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ms_name ; 
 int* ngx_crc32_table256 ; 
 void* ngx_http_tfs_create_ds_request ; 
 void* ngx_http_tfs_create_ms_request ; 
 void* ngx_http_tfs_create_ns_request ; 
 void* ngx_http_tfs_create_rcs_request ; 
 void* ngx_http_tfs_create_rs_request ; 
 void* ngx_http_tfs_process_ds ; 
 void* ngx_http_tfs_process_ds_input_filter ; 
 void* ngx_http_tfs_process_ds_read ; 
 void* ngx_http_tfs_process_ms ; 
 int /*<<< orphan*/ * ngx_http_tfs_process_ms_input_filter ; 
 void* ngx_http_tfs_process_ms_ls_dir ; 
 void* ngx_http_tfs_process_ns ; 
 void* ngx_http_tfs_process_rcs ; 
 void* ngx_http_tfs_process_rs ; 
 void* ngx_http_tfs_retry_ds ; 
 void* ngx_http_tfs_retry_ns ; 
 TYPE_9__* ngx_pcalloc (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ngx_sprintf (int /*<<< orphan*/ ,char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ns_name ; 
 int /*<<< orphan*/  ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcs_name ; 
 int /*<<< orphan*/  rs_name ; 

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
ngx_http_tfs_peer_init(ngx_http_tfs_t *t)
{
    char                            *addr;
    uint16_t                         port;
    ngx_http_connection_pool_t      *conn_pool;
    ngx_http_tfs_peer_connection_t  *rc_server, *name_server, *root_server,
                                    *meta_server, *data_server;

    conn_pool = t->main_conf->conn_pool;

    t->tfs_peer_servers = ngx_pcalloc(t->pool,
        sizeof(ngx_http_tfs_peer_connection_t) * NGX_HTTP_TFS_SERVER_COUNT);
    if (t->tfs_peer_servers == NULL) {
        return NGX_ERROR;
    }

    name_server = &t->tfs_peer_servers[NGX_HTTP_TFS_NAME_SERVER];
    data_server = &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];
    root_server = &t->tfs_peer_servers[NGX_HTTP_TFS_ROOT_SERVER];
    meta_server = &t->tfs_peer_servers[NGX_HTTP_TFS_META_SERVER];

    /* rc server */
    if (t->loc_conf->upstream->enable_rcs) {
        rc_server = &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];
        rc_server->peer.sockaddr = t->loc_conf->upstream->ups_addr->sockaddr;
        rc_server->peer.socklen = t->loc_conf->upstream->ups_addr->socklen;
        rc_server->peer.log = t->log;
        rc_server->peer.name = &rcs_name;
        rc_server->peer.data = conn_pool;
        rc_server->peer.get = conn_pool->get_peer;
        rc_server->peer.free = conn_pool->free_peer;
        rc_server->peer.log_error = NGX_ERROR_ERR;
        addr = inet_ntoa(((struct sockaddr_in*)
                          (rc_server->peer.sockaddr))->sin_addr);
        port = ntohs(((struct sockaddr_in*)
                      (rc_server->peer.sockaddr))->sin_port);
        ngx_sprintf(rc_server->peer_addr_text, "%s:%d", addr, port);

    } else {
        name_server->peer.sockaddr = t->loc_conf->upstream->ups_addr->sockaddr;
        name_server->peer.socklen = t->loc_conf->upstream->ups_addr->socklen;
        addr = inet_ntoa(((struct sockaddr_in*)
                          (name_server->peer.sockaddr))->sin_addr);
        port = ntohs(((struct sockaddr_in*)
                      (name_server->peer.sockaddr))->sin_port);
        ngx_sprintf(name_server->peer_addr_text, "%s:%d", addr, port);
    }

    /* name server */
    name_server->peer.log = t->log;
    name_server->peer.name = &ns_name;
    name_server->peer.data = conn_pool;
    name_server->peer.get = conn_pool->get_peer;
    name_server->peer.free = conn_pool->free_peer;
    name_server->peer.log_error = NGX_ERROR_ERR;

    /* data server */
    data_server->peer.log = t->log;
    data_server->peer.name = &ds_name;
    data_server->peer.data = conn_pool;
    data_server->peer.get = conn_pool->get_peer;
    data_server->peer.free = conn_pool->free_peer;
    data_server->peer.log_error = NGX_ERROR_ERR;

    if (t->r_ctx.version == 1) {
        t->tfs_peer_count = 3;

    } else {
        /* root server */
        root_server->peer.log = t->log;
        root_server->peer.name = &rs_name;
        root_server->peer.data = conn_pool;
        root_server->peer.get = conn_pool->get_peer;
        root_server->peer.free = conn_pool->free_peer;
        root_server->peer.log_error = NGX_ERROR_ERR;

        /* meta server */
        meta_server->peer.log = t->log;
        meta_server->peer.name = &ms_name;
        meta_server->peer.data = conn_pool;
        meta_server->peer.get = conn_pool->get_peer;
        meta_server->peer.free = conn_pool->free_peer;
        meta_server->peer.log_error = NGX_ERROR_ERR;

        t->tfs_peer_count = 5;
    }

    return NGX_OK;
}

__attribute__((used)) static ngx_http_tfs_peer_connection_t *
ngx_http_tfs_select_peer_v1(ngx_http_tfs_t *t)
{
    switch (t->r_ctx.action.code) {
    case NGX_HTTP_TFS_ACTION_REMOVE_FILE:
        switch (t->state) {
        case NGX_HTTP_TFS_STATE_REMOVE_START:
            t->create_request = ngx_http_tfs_create_rcs_request;
            t->process_request_body = ngx_http_tfs_process_rcs;
            t->input_filter = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_COUNT:
        case NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_SEQ:
        case NGX_HTTP_TFS_STATE_REMOVE_GET_BLK_INFO:
            t->create_request = ngx_http_tfs_create_ns_request;
            t->process_request_body = ngx_http_tfs_process_ns;
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_NAME_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_STAT_FILE:
            t->create_request = ngx_http_tfs_create_ds_request;
            t->process_request_body = ngx_http_tfs_process_ds;
            t->input_filter = NULL;
            t->retry_handler = ngx_http_tfs_retry_ds;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_READ_META_SEGMENT:
            t->create_request = ngx_http_tfs_create_ds_request;
            t->process_request_body = ngx_http_tfs_process_ds_read;
            t->input_filter = ngx_http_tfs_process_ds_input_filter;
            t->retry_handler = ngx_http_tfs_retry_ds;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_DELETE_DATA:
            t->create_request = ngx_http_tfs_create_ds_request;
            t->process_request_body = ngx_http_tfs_process_ds;
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_DONE:
            return t->tfs_peer;

        default:
            return NULL;
        }
        break;
    case NGX_HTTP_TFS_ACTION_READ_FILE:
        switch (t->state) {
        case NGX_HTTP_TFS_STATE_READ_START:
            t->create_request = ngx_http_tfs_create_rcs_request;
            t->process_request_body = ngx_http_tfs_process_rcs;
            t->input_filter = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

        case NGX_HTTP_TFS_STATE_READ_GET_BLK_INFO:
            t->create_request = ngx_http_tfs_create_ns_request;
            t->process_request_body = ngx_http_tfs_process_ns;
            t->input_filter = NULL;
            t->retry_handler = ngx_http_tfs_retry_ns;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_NAME_SERVER];

        case NGX_HTTP_TFS_STATE_READ_READ_DATA:
            t->create_request = ngx_http_tfs_create_ds_request;
            t->process_request_body = ngx_http_tfs_process_ds_read;
            t->input_filter = ngx_http_tfs_process_ds_input_filter;
            t->retry_handler = ngx_http_tfs_retry_ds;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];

        case NGX_HTTP_TFS_STATE_READ_DONE:
            t->input_filter = NULL;
            return t->tfs_peer;

        default:
            return NULL;
        }
        break;
    case NGX_HTTP_TFS_ACTION_WRITE_FILE:
        switch (t->state) {
        case NGX_HTTP_TFS_STATE_WRITE_START:
            t->create_request = ngx_http_tfs_create_rcs_request;
            t->process_request_body = ngx_http_tfs_process_rcs;
            t->input_filter = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

        case NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_COUNT:
        case NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_SEQ:
        case NGX_HTTP_TFS_STATE_WRITE_CLUSTER_ID_NS:
        case NGX_HTTP_TFS_STATE_WRITE_GET_BLK_INFO:
            t->create_request = ngx_http_tfs_create_ns_request;
            t->process_request_body = ngx_http_tfs_process_ns;
            t->input_filter = NULL;
            t->retry_handler = ngx_http_tfs_retry_ns;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_NAME_SERVER];

        case NGX_HTTP_TFS_STATE_WRITE_STAT_DUP_FILE:
        case NGX_HTTP_TFS_STATE_WRITE_CREATE_FILE_NAME:
        case NGX_HTTP_TFS_STATE_WRITE_WRITE_DATA:
        case NGX_HTTP_TFS_STATE_WRITE_CLOSE_FILE:
        case NGX_HTTP_TFS_STATE_WRITE_DELETE_DATA:
            t->create_request = ngx_http_tfs_create_ds_request;
            t->process_request_body = ngx_http_tfs_process_ds;
            t->input_filter = NULL;
            t->retry_handler = ngx_http_tfs_retry_ds;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];

        case NGX_HTTP_TFS_STATE_WRITE_DONE:
            t->input_filter = NULL;
            return t->tfs_peer;
        default:
            return NULL;
        }
        break;
    case NGX_HTTP_TFS_ACTION_STAT_FILE:
        switch (t->state) {
        case NGX_HTTP_TFS_STATE_STAT_START:
            t->create_request = ngx_http_tfs_create_rcs_request;
            t->process_request_body = ngx_http_tfs_process_rcs;
            t->input_filter = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

        case NGX_HTTP_TFS_STATE_STAT_GET_BLK_INFO:
            t->create_request = ngx_http_tfs_create_ns_request;
            t->process_request_body = ngx_http_tfs_process_ns;
            t->input_filter = NULL;
            t->retry_handler = ngx_http_tfs_retry_ns;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_NAME_SERVER];

        case NGX_HTTP_TFS_STATE_STAT_STAT_FILE:
            t->create_request = ngx_http_tfs_create_ds_request;
            t->process_request_body = ngx_http_tfs_process_ds;
            t->input_filter = NULL;
            t->retry_handler = ngx_http_tfs_retry_ds;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];

        default:
            return NULL;
        }
        break;

    case NGX_HTTP_TFS_ACTION_KEEPALIVE:
        t->create_request = ngx_http_tfs_create_rcs_request;
        t->process_request_body = ngx_http_tfs_process_rcs;
        t->input_filter = NULL;
        return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

    default:
        break;
    }

    return NULL;
}

__attribute__((used)) static ngx_http_tfs_peer_connection_t *
ngx_http_tfs_select_peer_v2(ngx_http_tfs_t *t)
{
    switch (t->r_ctx.action.code) {
    case NGX_HTTP_TFS_ACTION_GET_APPID:
            t->create_request = ngx_http_tfs_create_rcs_request;
            t->process_request_body = ngx_http_tfs_process_rcs;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

    case NGX_HTTP_TFS_ACTION_REMOVE_FILE:
        switch (t->state) {
        case NGX_HTTP_TFS_STATE_REMOVE_START:
            t->create_request = ngx_http_tfs_create_rcs_request;
            t->process_request_body = ngx_http_tfs_process_rcs;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_GET_META_TABLE:
            t->create_request = ngx_http_tfs_create_rs_request;
            t->process_request_body = ngx_http_tfs_process_rs;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_ROOT_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_NOTIFY_MS:
        case NGX_HTTP_TFS_STATE_REMOVE_GET_FRAG_INFO:
            t->create_request = ngx_http_tfs_create_ms_request;
            t->process_request_body = ngx_http_tfs_process_ms;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_META_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_COUNT:
        case NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_SEQ:
        case NGX_HTTP_TFS_STATE_REMOVE_GET_BLK_INFO:
            t->create_request = ngx_http_tfs_create_ns_request;
            t->process_request_body = ngx_http_tfs_process_ns;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_NAME_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_DELETE_DATA:
            t->create_request = ngx_http_tfs_create_ds_request;
            t->process_request_body = ngx_http_tfs_process_ds;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];

        case NGX_HTTP_TFS_STATE_REMOVE_DONE:
            return t->tfs_peer;
        default:
            return NULL;
        }
        break;
    case NGX_HTTP_TFS_ACTION_READ_FILE:
        switch (t->state) {
        case NGX_HTTP_TFS_STATE_READ_START:
            t->create_request = ngx_http_tfs_create_rcs_request;
            t->process_request_body = ngx_http_tfs_process_rcs;
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

        case NGX_HTTP_TFS_STATE_READ_GET_META_TABLE:
            t->create_request = ngx_http_tfs_create_rs_request;
            t->process_request_body = ngx_http_tfs_process_rs;
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_ROOT_SERVER];

        case NGX_HTTP_TFS_STATE_READ_GET_FRAG_INFO:
            t->create_request = ngx_http_tfs_create_ms_request;
            t->process_request_body = ngx_http_tfs_process_ms;
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_META_SERVER];

        case NGX_HTTP_TFS_STATE_READ_GET_BLK_INFO:
            t->create_request = ngx_http_tfs_create_ns_request;
            t->process_request_body = ngx_http_tfs_process_ns;
            t->input_filter = NULL;
            t->retry_handler = ngx_http_tfs_retry_ns;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_NAME_SERVER];

        case NGX_HTTP_TFS_STATE_READ_READ_DATA:
            t->create_request = ngx_http_tfs_create_ds_request;
            t->process_request_body = ngx_http_tfs_process_ds_read;
            t->input_filter = ngx_http_tfs_process_ds_input_filter;
            t->retry_handler = ngx_http_tfs_retry_ds;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];

        case NGX_HTTP_TFS_STATE_READ_DONE:
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return t->tfs_peer;
        default:
            return NULL;
        }
        break;
    case NGX_HTTP_TFS_ACTION_WRITE_FILE:
        switch (t->state) {
        case NGX_HTTP_TFS_STATE_WRITE_START:
            t->create_request = ngx_http_tfs_create_rcs_request;
            t->process_request_body = ngx_http_tfs_process_rcs;
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

        case NGX_HTTP_TFS_STATE_WRITE_GET_META_TABLE:
            t->create_request = ngx_http_tfs_create_rs_request;
            t->process_request_body = ngx_http_tfs_process_rs;
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_ROOT_SERVER];

        case NGX_HTTP_TFS_STATE_WRITE_CLUSTER_ID_MS:
        case NGX_HTTP_TFS_STATE_WRITE_WRITE_MS:
            t->create_request = ngx_http_tfs_create_ms_request;
            t->process_request_body = ngx_http_tfs_process_ms;
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_META_SERVER];

        case NGX_HTTP_TFS_STATE_WRITE_CLUSTER_ID_NS:
        case NGX_HTTP_TFS_STATE_WRITE_GET_BLK_INFO:
            t->create_request = ngx_http_tfs_create_ns_request;
            t->process_request_body = ngx_http_tfs_process_ns;
            t->input_filter = NULL;
            t->retry_handler = ngx_http_tfs_retry_ns;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_NAME_SERVER];

        case NGX_HTTP_TFS_STATE_WRITE_CREATE_FILE_NAME:
        case NGX_HTTP_TFS_STATE_WRITE_WRITE_DATA:
        case NGX_HTTP_TFS_STATE_WRITE_CLOSE_FILE:
            t->create_request = ngx_http_tfs_create_ds_request;
            t->process_request_body = ngx_http_tfs_process_ds;
            t->input_filter = NULL;
            /* FIXME: it's better to retry_ns instead of ds when write failed */
            t->retry_handler = ngx_http_tfs_retry_ds;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_DATA_SERVER];

        case NGX_HTTP_TFS_STATE_WRITE_DONE:
            t->input_filter = NULL;
            t->retry_handler = NULL;
            return t->tfs_peer;
        default:
            return NULL;
        }
        break;
    case NGX_HTTP_TFS_ACTION_CREATE_FILE:
    case NGX_HTTP_TFS_ACTION_CREATE_DIR:
    case NGX_HTTP_TFS_ACTION_LS_FILE:
    case NGX_HTTP_TFS_ACTION_LS_DIR:
    case NGX_HTTP_TFS_ACTION_MOVE_DIR:
    case NGX_HTTP_TFS_ACTION_MOVE_FILE:
    case NGX_HTTP_TFS_ACTION_REMOVE_DIR:
        switch (t->state) {
        case NGX_HTTP_TFS_STATE_ACTION_START:
            t->create_request = ngx_http_tfs_create_rcs_request;
            t->process_request_body = ngx_http_tfs_process_rcs;
            t->input_filter = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_RC_SERVER];

        case NGX_HTTP_TFS_STATE_ACTION_GET_META_TABLE:
            t->create_request = ngx_http_tfs_create_rs_request;
            t->process_request_body = ngx_http_tfs_process_rs;
            t->input_filter = NULL;
            return &t->tfs_peer_servers[NGX_HTTP_TFS_ROOT_SERVER];

        case NGX_HTTP_TFS_STATE_ACTION_PROCESS:
            t->create_request = ngx_http_tfs_create_ms_request;
            if (t->r_ctx.action.code == NGX_HTTP_TFS_ACTION_LS_DIR) {
                t->process_request_body = ngx_http_tfs_process_ms_ls_dir;
                t->input_filter = ngx_http_tfs_process_ms_input_filter;
            } else {
                t->process_request_body = ngx_http_tfs_process_ms;
                t->input_filter = NULL;
            }
            return &t->tfs_peer_servers[NGX_HTTP_TFS_META_SERVER];

        case NGX_HTTP_TFS_STATE_ACTION_DONE:
            t->input_filter = NULL;
            return t->tfs_peer;
        default:
            return NULL;
        }
        break;
    default:
        break;
    }

    return NULL;
}

ngx_http_tfs_peer_connection_t *
ngx_http_tfs_select_peer(ngx_http_tfs_t *t)
{
    if (t->r_ctx.version == 1) {
        return ngx_http_tfs_select_peer_v1(t);
    }

    if (t->r_ctx.version == 2) {
        return ngx_http_tfs_select_peer_v2(t);
    }

    return NULL;
}

