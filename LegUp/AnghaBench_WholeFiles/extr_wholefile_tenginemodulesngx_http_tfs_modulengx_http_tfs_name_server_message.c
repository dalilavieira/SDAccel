#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_90__   TYPE_9__ ;
typedef  struct TYPE_89__   TYPE_8__ ;
typedef  struct TYPE_88__   TYPE_7__ ;
typedef  struct TYPE_87__   TYPE_6__ ;
typedef  struct TYPE_86__   TYPE_5__ ;
typedef  struct TYPE_85__   TYPE_4__ ;
typedef  struct TYPE_84__   TYPE_3__ ;
typedef  struct TYPE_83__   TYPE_35__ ;
typedef  struct TYPE_82__   TYPE_31__ ;
typedef  struct TYPE_81__   TYPE_30__ ;
typedef  struct TYPE_80__   TYPE_2__ ;
typedef  struct TYPE_79__   TYPE_29__ ;
typedef  struct TYPE_78__   TYPE_28__ ;
typedef  struct TYPE_77__   TYPE_27__ ;
typedef  struct TYPE_76__   TYPE_26__ ;
typedef  struct TYPE_75__   TYPE_25__ ;
typedef  struct TYPE_74__   TYPE_24__ ;
typedef  struct TYPE_73__   TYPE_23__ ;
typedef  struct TYPE_72__   TYPE_22__ ;
typedef  struct TYPE_71__   TYPE_21__ ;
typedef  struct TYPE_70__   TYPE_20__ ;
typedef  struct TYPE_69__   TYPE_1__ ;
typedef  struct TYPE_68__   TYPE_19__ ;
typedef  struct TYPE_67__   TYPE_18__ ;
typedef  struct TYPE_66__   TYPE_17__ ;
typedef  struct TYPE_65__   TYPE_16__ ;
typedef  struct TYPE_64__   TYPE_15__ ;
typedef  struct TYPE_63__   TYPE_14__ ;
typedef  struct TYPE_62__   TYPE_13__ ;
typedef  struct TYPE_61__   TYPE_12__ ;
typedef  struct TYPE_60__   TYPE_11__ ;
typedef  struct TYPE_59__   TYPE_10__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  void* uint64_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  u_char ;
typedef  size_t ngx_uint_t ;
struct TYPE_60__ {int /*<<< orphan*/  data; } ;
typedef  TYPE_11__ ngx_str_t ;
typedef  int ngx_int_t ;
struct TYPE_59__ {int cluster_id; int open_mode; size_t segment_index; int segment_count; size_t curr_batch_count; TYPE_14__* segment_data; } ;
struct TYPE_86__ {int block_id; } ;
struct TYPE_87__ {int cluster_id; TYPE_5__ file; } ;
struct TYPE_69__ {int code; } ;
struct TYPE_88__ {int version; TYPE_6__ fsname; TYPE_1__ action; int /*<<< orphan*/  is_raw_update; } ;
struct TYPE_61__ {size_t logical_cluster_index; size_t rw_cluster_index; int state; int group_count; int group_seq; int /*<<< orphan*/  log; TYPE_10__ file; TYPE_17__* tfs_peer; int /*<<< orphan*/  pool; int /*<<< orphan*/  block_cache_ctx; int /*<<< orphan*/  name_server_addr; int /*<<< orphan*/  name_server_addr_text; scalar_t__ header; TYPE_7__ r_ctx; int /*<<< orphan*/  is_process_meta_seg; int /*<<< orphan*/  is_large_file; int /*<<< orphan*/  is_rolling_back; int /*<<< orphan*/  parent; int /*<<< orphan*/  is_stat_dup_file; } ;
typedef  TYPE_12__ ngx_http_tfs_t ;
struct TYPE_62__ {int code; scalar_t__ error_len; int /*<<< orphan*/  error_str; } ;
typedef  TYPE_13__ ngx_http_tfs_status_msg_t ;
struct TYPE_77__ {int ds_count; TYPE_8__* ds_addrs; void* lease_id; void* version; } ;
struct TYPE_90__ {int block_id; } ;
struct TYPE_63__ {scalar_t__ cache_hit; scalar_t__ ds_retry; TYPE_27__ block_info; TYPE_9__ segment_info; } ;
typedef  TYPE_14__ ngx_http_tfs_segment_data_t ;
struct TYPE_64__ {size_t logical_cluster_count; size_t unlink_cluster_group_count; TYPE_23__* logical_clusters; TYPE_26__* unlink_cluster_groups; } ;
typedef  TYPE_15__ ngx_http_tfs_rcs_info_t ;
struct TYPE_65__ {int cluster_id; int /*<<< orphan*/  ns_vip; TYPE_11__ ns_vip_text; TYPE_11__ cluster_id_text; int /*<<< orphan*/  access_type; } ;
typedef  TYPE_16__ ngx_http_tfs_physical_cluster_t ;
struct TYPE_83__ {int /*<<< orphan*/ * pos; } ;
struct TYPE_66__ {TYPE_35__ body_buffer; } ;
typedef  TYPE_17__ ngx_http_tfs_peer_connection_t ;
struct TYPE_85__ {size_t len; int crc; void* id; void* version; void* flag; int /*<<< orphan*/  type; } ;
struct TYPE_67__ {int value2; TYPE_4__ header; int /*<<< orphan*/  cmd; } ;
typedef  TYPE_18__ ngx_http_tfs_ns_ctl_request_t ;
struct TYPE_68__ {int ds_count; int block_id; } ;
typedef  TYPE_19__ ngx_http_tfs_ns_block_info_response_t ;
struct TYPE_80__ {size_t len; int crc; void* id; void* version; void* flag; int /*<<< orphan*/  type; } ;
struct TYPE_70__ {int mode; int block_id; TYPE_2__ header; scalar_t__ fs_count; } ;
typedef  TYPE_20__ ngx_http_tfs_ns_block_info_request_t ;
struct TYPE_71__ {size_t block_count; } ;
typedef  TYPE_21__ ngx_http_tfs_ns_batch_block_info_response_t ;
struct TYPE_84__ {size_t len; int crc; void* id; void* version; void* flag; int /*<<< orphan*/  type; } ;
struct TYPE_72__ {int mode; int block_count; int* block_ids; TYPE_3__ header; } ;
typedef  TYPE_22__ ngx_http_tfs_ns_batch_block_info_request_t ;
struct TYPE_73__ {size_t rw_cluster_count; TYPE_16__* rw_clusters; } ;
typedef  TYPE_23__ ngx_http_tfs_logical_cluster_t ;
typedef  int /*<<< orphan*/  ngx_http_tfs_inet_t ;
struct TYPE_74__ {int type; } ;
typedef  TYPE_24__ ngx_http_tfs_header_t ;
struct TYPE_75__ {TYPE_11__ ns_vip_text; int /*<<< orphan*/  ns_vip; int /*<<< orphan*/  group_seq; } ;
typedef  TYPE_25__ ngx_http_tfs_group_info_t ;
struct TYPE_76__ {int cluster_id; int info_count; int group_count; TYPE_25__* group_info; } ;
typedef  TYPE_26__ ngx_http_tfs_cluster_group_info_t ;
typedef  TYPE_27__ ngx_http_tfs_block_info_t ;
struct TYPE_78__ {int ds_count; void** ds_addrs; } ;
typedef  TYPE_28__ ngx_http_tfs_block_cache_value_t ;
struct TYPE_79__ {int block_id; void* ns_addr; } ;
typedef  TYPE_29__ ngx_http_tfs_block_cache_key_t ;
struct TYPE_81__ {int /*<<< orphan*/ * next; TYPE_31__* buf; } ;
typedef  TYPE_30__ ngx_chain_t ;
struct TYPE_82__ {size_t last; scalar_t__ pos; } ;
typedef  TYPE_31__ ngx_buf_t ;
typedef  int /*<<< orphan*/  int64_t ;
typedef  void* int32_t ;
struct TYPE_89__ {int ip; int port; } ;

/* Variables and functions */
 int NGX_ERROR ; 
 int /*<<< orphan*/  NGX_HTTP_TFS_ACCESS_READ_AND_WRITE ; 
#define  NGX_HTTP_TFS_ACTION_READ_FILE 142 
#define  NGX_HTTP_TFS_ACTION_REMOVE_FILE 141 
#define  NGX_HTTP_TFS_ACTION_STAT_FILE 140 
#define  NGX_HTTP_TFS_ACTION_WRITE_FILE 139 
 int NGX_HTTP_TFS_AGAIN ; 
 int /*<<< orphan*/  NGX_HTTP_TFS_BATCH_GET_BLOCK_INFO_MESSAGE ; 
 int /*<<< orphan*/  NGX_HTTP_TFS_CLIENT_CMD_MESSAGE ; 
 int /*<<< orphan*/  NGX_HTTP_TFS_CLIENT_CMD_SET_PARAM ; 
#define  NGX_HTTP_TFS_CMD_GET_CLUSTER_ID_NS 138 
#define  NGX_HTTP_TFS_CMD_GET_GROUP_COUNT 137 
#define  NGX_HTTP_TFS_CMD_GET_GROUP_SEQ 136 
 int NGX_HTTP_TFS_EXIT_GENERAL_ERROR ; 
 int /*<<< orphan*/  NGX_HTTP_TFS_GET_BLOCK_INFO_MESSAGE ; 
 int NGX_HTTP_TFS_MAX_BATCH_COUNT ; 
 int /*<<< orphan*/  NGX_HTTP_TFS_NO ; 
 scalar_t__ NGX_HTTP_TFS_NO_BLOCK_CACHE ; 
 int NGX_HTTP_TFS_OPEN_MODE_CREATE ; 
 int NGX_HTTP_TFS_OPEN_MODE_READ ; 
 int NGX_HTTP_TFS_OPEN_MODE_STAT ; 
 int NGX_HTTP_TFS_OPEN_MODE_WRITE ; 
 void* NGX_HTTP_TFS_PACKET_FLAG ; 
 void* NGX_HTTP_TFS_PACKET_VERSION ; 
#define  NGX_HTTP_TFS_STATE_REMOVE_GET_BLK_INFO 135 
#define  NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_COUNT 134 
#define  NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_SEQ 133 
#define  NGX_HTTP_TFS_STATE_WRITE_CLUSTER_ID_NS 132 
#define  NGX_HTTP_TFS_STATE_WRITE_GET_BLK_INFO 131 
#define  NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_COUNT 130 
#define  NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_SEQ 129 
#define  NGX_HTTP_TFS_STATUS_MESSAGE 128 
 int NGX_HTTP_TFS_STATUS_MESSAGE_OK ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_HTTP ; 
 int /*<<< orphan*/  NGX_LOG_ERR ; 
 int /*<<< orphan*/  NGX_LOG_INFO ; 
 int /*<<< orphan*/  NGX_LOG_WARN ; 
 int NGX_OK ; 
 TYPE_30__* ngx_alloc_chain_link (int /*<<< orphan*/ ) ; 
 void* ngx_atoi (int /*<<< orphan*/ ,scalar_t__) ; 
 int* ngx_crc32_table256 ; 
 TYPE_31__* ngx_create_temp_buf (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  ngx_http_tfs_block_cache_insert (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_29__*,TYPE_28__*) ; 
static  TYPE_30__* ngx_http_tfs_create_batch_block_info_message (TYPE_12__*) ; 
static  TYPE_30__* ngx_http_tfs_create_block_info_message (TYPE_12__*,TYPE_14__*) ; 
static  TYPE_30__* ngx_http_tfs_create_ctl_message (TYPE_12__*,int) ; 
 void* ngx_http_tfs_generate_packet_id () ; 
 int ngx_http_tfs_get_cluster_id (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_http_tfs_group_seq_match (int,int,int /*<<< orphan*/ ) ; 
 int ngx_http_tfs_parse_batch_block_info_message (TYPE_12__*,TYPE_14__*) ; 
 int ngx_http_tfs_parse_block_info_message (TYPE_12__*,TYPE_14__*) ; 
static  int ngx_http_tfs_parse_ctl_message (TYPE_12__*,int) ; 
 int ngx_http_tfs_status_message (TYPE_35__*,TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_log_debug1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,TYPE_11__*) ; 
 int /*<<< orphan*/  ngx_log_debug3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,size_t,size_t,TYPE_11__*) ; 
 int /*<<< orphan*/  ngx_log_debug5 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int,int,void*,void*) ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,...) ; 
 void* ngx_pcalloc (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ngx_str_set (TYPE_11__*,char*) ; 

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
ngx_http_tfs_select_name_server(ngx_http_tfs_t *t,
    ngx_http_tfs_rcs_info_t *rc_info, ngx_http_tfs_inet_t *addr,
    ngx_str_t *addr_text)
{
    uint32_t                            cluster_id, curr_cluster_id, info_count,
                                        curr_block_id;
    ngx_str_t                          *cluster_id_text;
    ngx_uint_t                          i, j;
    ngx_http_tfs_group_info_t          *group_info;
    ngx_http_tfs_logical_cluster_t     *logical_cluster;
    ngx_http_tfs_physical_cluster_t    *physical_cluster;
    ngx_http_tfs_cluster_group_info_t  *cluster_group_info;

    curr_cluster_id = 0;

    if (rc_info == NULL) {
        return NGX_ERROR;
    }
    if (t->r_ctx.version == 1) {
        curr_cluster_id = t->r_ctx.fsname.cluster_id;

    } else if (t->r_ctx.version == 2){
        curr_cluster_id = t->file.cluster_id;
    }

    switch(t->r_ctx.action.code) {
    case NGX_HTTP_TFS_ACTION_STAT_FILE:
    case NGX_HTTP_TFS_ACTION_READ_FILE:
        for (;
             t->logical_cluster_index < rc_info->logical_cluster_count;
             t->logical_cluster_index++)
        {
            logical_cluster =
                           &rc_info->logical_clusters[t->logical_cluster_index];
            for (;
                 t->rw_cluster_index < logical_cluster->rw_cluster_count;
                 t->rw_cluster_index++)
            {
                physical_cluster =
                             &logical_cluster->rw_clusters[t->rw_cluster_index];
                cluster_id_text = &physical_cluster->cluster_id_text;
                cluster_id = ngx_http_tfs_get_cluster_id(cluster_id_text->data);
                if (curr_cluster_id > 0 && cluster_id != curr_cluster_id) {
                    continue;
                }
                ngx_log_debug3(NGX_LOG_DEBUG_HTTP, t->log, 0,
                               "read/stat, select logical cluster "
                               "index: %ui, rw_cluster_index: %ui, "
                               "nameserver: %V",
                               t->logical_cluster_index, t->rw_cluster_index,
                               &physical_cluster->ns_vip_text);
                (*addr) = physical_cluster->ns_vip;
                (*addr_text) = physical_cluster->ns_vip_text;
                return NGX_OK;
            }
            t->rw_cluster_index = 0;
        }

        break;

    case NGX_HTTP_TFS_ACTION_WRITE_FILE:
        if (t->r_ctx.is_raw_update == NGX_HTTP_TFS_NO) {
            for (;
                 t->logical_cluster_index < rc_info->logical_cluster_count;
                 t->logical_cluster_index++)
            {
                logical_cluster =
                               &rc_info->logical_clusters[t->logical_cluster_index];
                for (;
                     t->rw_cluster_index < logical_cluster->rw_cluster_count;
                     t->rw_cluster_index++)
                {
                    physical_cluster =
                                 &logical_cluster->rw_clusters[t->rw_cluster_index];
                    if (physical_cluster->access_type
                        == NGX_HTTP_TFS_ACCESS_READ_AND_WRITE)
                    {
                        /* custom file should ensure writing
                         * all frags in the same cluster */
                        if (curr_cluster_id > 0) {
                            cluster_id_text = &physical_cluster->cluster_id_text;
                            cluster_id =
                                ngx_http_tfs_get_cluster_id(cluster_id_text->data);
                            if (cluster_id != curr_cluster_id) {
                                continue;
                            }
                        }
                        ngx_log_debug3(NGX_LOG_DEBUG_HTTP, t->log, 0,
                                       "write, select logical cluster "
                                       "index: %ui, rw_cluster_index: %ui, "
                                       "nameserver: %V",
                                       t->logical_cluster_index,
                                       t->rw_cluster_index,
                                       &physical_cluster->ns_vip_text);
                        (*addr) = physical_cluster->ns_vip;
                        (*addr_text) = physical_cluster->ns_vip_text;

                        /* check if need get cluster id from ns */
                        if (t->state == NGX_HTTP_TFS_STATE_WRITE_GET_BLK_INFO) {
                            if (physical_cluster->cluster_id > 0) {
                                t->file.cluster_id = physical_cluster->cluster_id;

                            } else {
                                t->state = NGX_HTTP_TFS_STATE_WRITE_CLUSTER_ID_NS;
                            }
                        }

                        return NGX_OK;
                    }
                }
                t->rw_cluster_index = 0;
            }

            break;
        }

        /* update raw file */
    case NGX_HTTP_TFS_ACTION_REMOVE_FILE:
        for (i = 0; i < rc_info->unlink_cluster_group_count; i++) {
            cluster_group_info = &rc_info->unlink_cluster_groups[i];
            group_info = cluster_group_info->group_info;
            cluster_id = cluster_group_info->cluster_id;
            info_count = cluster_group_info->info_count;

            if ((curr_cluster_id > 0 && cluster_id != curr_cluster_id)
                || info_count < 1)
            {
                continue;
            }

            /* only one cluster, select it */
            if (info_count == 1) {
                (*addr) = group_info[0].ns_vip;
                (*addr_text) = group_info[0].ns_vip_text;
                if (t->r_ctx.action.code == NGX_HTTP_TFS_ACTION_REMOVE_FILE) {
                    t->state = NGX_HTTP_TFS_STATE_REMOVE_GET_BLK_INFO;

                } else if (t->r_ctx.action.code == NGX_HTTP_TFS_ACTION_WRITE_FILE) {
                    t->state = NGX_HTTP_TFS_STATE_WRITE_GET_BLK_INFO;
                }
                ngx_log_debug1(NGX_LOG_DEBUG_HTTP, t->log, 0,
                               "unlink, select nameserver: %V",
                               &group_info[0].ns_vip_text);
                goto find_logical_cluster_index;
            }

            /* two clusters or more */
            if (cluster_group_info->group_count <= 0) {
                (*addr) = group_info[0].ns_vip;
                (*addr_text) = group_info[0].ns_vip_text;
                if (t->r_ctx.action.code == NGX_HTTP_TFS_ACTION_REMOVE_FILE) {
                    t->state = NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_COUNT;

                } else if (t->r_ctx.action.code == NGX_HTTP_TFS_ACTION_WRITE_FILE) {
                    t->state = NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_COUNT;
                }
                return NGX_OK;
            }

            /* if there are two clusters or more but group count is 1, sth wrong in TFS cluster configure */
            if (cluster_group_info->group_count == 1) {
                ngx_log_error(NGX_LOG_ERR, t->log, 0,
                               "unlink, can not select nameserver.");
                return NGX_ERROR;
            }

            for (j = 0; j < info_count; j++) {
                if (group_info[j].group_seq < 0) {
                    (*addr) = group_info[j].ns_vip;
                    (*addr_text) = group_info[j].ns_vip_text;
                    if (t->r_ctx.action.code == NGX_HTTP_TFS_ACTION_REMOVE_FILE) {
                        t->state = NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_SEQ;

                    } else if (t->r_ctx.action.code == NGX_HTTP_TFS_ACTION_WRITE_FILE) {
                        t->state = NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_SEQ;
                    }
                    return NGX_OK;
                }

                if (t->r_ctx.version == 1) {
                    curr_block_id = t->r_ctx.fsname.file.block_id;
                } else {
                    curr_block_id =
                        t->file.segment_data[0].segment_info.block_id;
                }
                if (ngx_http_tfs_group_seq_match(curr_block_id,
                                              cluster_group_info->group_count,
                                              group_info[j].group_seq))
                {
                    (*addr) = group_info[j].ns_vip;
                    (*addr_text) = group_info[j].ns_vip_text;
                    if (t->r_ctx.action.code == NGX_HTTP_TFS_ACTION_REMOVE_FILE) {
                        t->state = NGX_HTTP_TFS_STATE_REMOVE_GET_BLK_INFO;

                    } else if (t->r_ctx.action.code == NGX_HTTP_TFS_ACTION_WRITE_FILE) {
                        t->state = NGX_HTTP_TFS_STATE_WRITE_GET_BLK_INFO;
                    }

                    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, t->log, 0,
                                   "unlink, select nameserver: %V",
                                   &group_info[j].ns_vip_text);
                    goto find_logical_cluster_index;
                }
            }
        }

        return NGX_ERROR;

find_logical_cluster_index:

        /* find out which logical cluster this addr belongs to
         * so that we can use the right de-dup addr
         */
        t->logical_cluster_index = 0;
        for ( ;
              t->logical_cluster_index < rc_info->logical_cluster_count;
              t->logical_cluster_index++)
        {
            logical_cluster =
                &rc_info->logical_clusters[t->logical_cluster_index];
            t->rw_cluster_index = 0;
            for ( ;
                  t->rw_cluster_index < logical_cluster->rw_cluster_count;
                  t->rw_cluster_index++)
            {
                physical_cluster =
                    &logical_cluster->rw_clusters[t->rw_cluster_index];
                if (*(uint64_t*)(&physical_cluster->ns_vip)
                    == *(uint64_t*)(addr))
                {
                    return NGX_OK;
                }
            }
        }
        ngx_log_error(NGX_LOG_ERR, t->log, 0,
                      "can not find logical cluster index of ns: %V",
                      addr_text);
        return NGX_ERROR;
    }

    return NGX_ERROR;
}

ngx_chain_t *
ngx_http_tfs_name_server_create_message(ngx_http_tfs_t *t)
{
    uint16_t      action;
    ngx_chain_t  *cl;
    ngx_http_tfs_segment_data_t  *segment_data;

    cl = NULL;
    t->file.open_mode = 0;
    action = t->r_ctx.action.code;
    segment_data = &t->file.segment_data[t->file.segment_index];

    switch (action) {
    case NGX_HTTP_TFS_ACTION_STAT_FILE:
        t->file.open_mode = NGX_HTTP_TFS_OPEN_MODE_STAT
                             | NGX_HTTP_TFS_OPEN_MODE_READ;
        ngx_log_error(NGX_LOG_INFO, t->log, 0, "get block info from ns");

        cl = ngx_http_tfs_create_block_info_message(t, segment_data);
        break;

    case NGX_HTTP_TFS_ACTION_READ_FILE:
        t->file.open_mode |= NGX_HTTP_TFS_OPEN_MODE_READ;
        ngx_log_error(NGX_LOG_INFO, t->log, 0, "get block info from ns");

        if (!t->parent
            && (t->r_ctx.version == 2
                || (t->is_large_file && !t->is_process_meta_seg)))
        {
            cl = ngx_http_tfs_create_batch_block_info_message(t);

        } else {
            cl = ngx_http_tfs_create_block_info_message(t, segment_data);
        }
        break;

    case NGX_HTTP_TFS_ACTION_WRITE_FILE:
        t->file.open_mode = NGX_HTTP_TFS_OPEN_MODE_WRITE
                             | NGX_HTTP_TFS_OPEN_MODE_CREATE;
        switch(t->state) {
        case NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_COUNT:
            ngx_log_error(NGX_LOG_INFO, t->log, 0, "get group count from ns");
            cl = ngx_http_tfs_create_ctl_message(t,
                NGX_HTTP_TFS_CMD_GET_GROUP_COUNT);
            break;

        case NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_SEQ:
            ngx_log_error(NGX_LOG_INFO, t->log, 0, "get group seq from ns");
            cl = ngx_http_tfs_create_ctl_message(t,
                NGX_HTTP_TFS_CMD_GET_GROUP_SEQ);
            break;

        case NGX_HTTP_TFS_STATE_WRITE_CLUSTER_ID_NS:
            ngx_log_error(NGX_LOG_INFO, t->log, 0, "get cluster id from ns");
            cl = ngx_http_tfs_create_ctl_message(t,
                NGX_HTTP_TFS_CMD_GET_CLUSTER_ID_NS);
            break;
        case NGX_HTTP_TFS_STATE_WRITE_GET_BLK_INFO:
            ngx_log_error(NGX_LOG_INFO, t->log, 0, "get block info from ns");
            if (t->is_stat_dup_file) {
                t->file.open_mode = NGX_HTTP_TFS_OPEN_MODE_STAT
                                     | NGX_HTTP_TFS_OPEN_MODE_READ;
            }
            if (!t->parent
                && !t->is_rolling_back
                && (t->r_ctx.version == 2
                 || (t->is_large_file && !t->is_process_meta_seg)))
            {
                cl = ngx_http_tfs_create_batch_block_info_message(t);

            } else {
                cl = ngx_http_tfs_create_block_info_message(t, segment_data);
            }
            break;
        }
        break;
    case NGX_HTTP_TFS_ACTION_REMOVE_FILE:
        switch(t->state) {
        case NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_COUNT:
            ngx_log_error(NGX_LOG_INFO, t->log, 0, "get group count from ns");
            cl = ngx_http_tfs_create_ctl_message(t,
                                              NGX_HTTP_TFS_CMD_GET_GROUP_COUNT);
            break;
        case NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_SEQ:
            ngx_log_error(NGX_LOG_INFO, t->log, 0, "get group seq from ns");
            cl = ngx_http_tfs_create_ctl_message(t,
                                                NGX_HTTP_TFS_CMD_GET_GROUP_SEQ);
            break;
        default:
            t->file.open_mode = NGX_HTTP_TFS_OPEN_MODE_WRITE;
            if (t->is_stat_dup_file) {
                t->file.open_mode = NGX_HTTP_TFS_OPEN_MODE_STAT
                                     | NGX_HTTP_TFS_OPEN_MODE_READ;
            }

            ngx_log_error(NGX_LOG_INFO, t->log, 0, "get block info from ns");
            cl = ngx_http_tfs_create_block_info_message(t, segment_data);
        }
        break;
    default:
        return NULL;
    }

    return cl;
}

ngx_int_t
ngx_http_tfs_name_server_parse_message(ngx_http_tfs_t *t)
{
    uint16_t                      action;
    ngx_int_t                     rc;
    ngx_http_tfs_segment_data_t  *segment_data;

    rc = NGX_ERROR;
    action = t->r_ctx.action.code;
    segment_data = &t->file.segment_data[t->file.segment_index];

    switch (action) {
    case NGX_HTTP_TFS_ACTION_STAT_FILE:
        return ngx_http_tfs_parse_block_info_message(t, segment_data);

    case NGX_HTTP_TFS_ACTION_READ_FILE:
        if (!t->parent
            && (t->r_ctx.version == 2
                || (t->is_large_file && !t->is_process_meta_seg)))
        {
            rc = ngx_http_tfs_parse_batch_block_info_message(t, segment_data);

        } else {
            rc = ngx_http_tfs_parse_block_info_message(t, segment_data);
        }
        return rc;

    case NGX_HTTP_TFS_ACTION_WRITE_FILE:
        switch(t->state) {
        case NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_COUNT:
            return ngx_http_tfs_parse_ctl_message(t,
                NGX_HTTP_TFS_CMD_GET_GROUP_COUNT);

        case NGX_HTTP_TFS_STATE_WRITE_GET_GROUP_SEQ:
            return ngx_http_tfs_parse_ctl_message(t,
                NGX_HTTP_TFS_CMD_GET_GROUP_SEQ);

        case NGX_HTTP_TFS_STATE_WRITE_CLUSTER_ID_NS:
            return ngx_http_tfs_parse_ctl_message(t,
                NGX_HTTP_TFS_CMD_GET_CLUSTER_ID_NS);

        case NGX_HTTP_TFS_STATE_WRITE_GET_BLK_INFO:
            if (!t->parent
                && !t->is_rolling_back
                && (t->r_ctx.version == 2
                    || (t->is_large_file && !t->is_process_meta_seg)))
            {
                rc = ngx_http_tfs_parse_batch_block_info_message(t,
                                                                 segment_data);

            } else {
                rc = ngx_http_tfs_parse_block_info_message(t, segment_data);
            }
        }
        return rc;

    case NGX_HTTP_TFS_ACTION_REMOVE_FILE:
        switch(t->state) {
        case NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_COUNT:
            rc = ngx_http_tfs_parse_ctl_message(t,
                                              NGX_HTTP_TFS_CMD_GET_GROUP_COUNT);
            return rc;

        case NGX_HTTP_TFS_STATE_REMOVE_GET_GROUP_SEQ:
            rc = ngx_http_tfs_parse_ctl_message(t,
                                                NGX_HTTP_TFS_CMD_GET_GROUP_SEQ);
            return rc;

        case NGX_HTTP_TFS_STATE_REMOVE_GET_BLK_INFO:
            return ngx_http_tfs_parse_block_info_message(t, segment_data);

        default:
            break;
        }
    }

    return NGX_ERROR;
}

__attribute__((used)) static ngx_chain_t *
ngx_http_tfs_create_block_info_message(ngx_http_tfs_t *t,
    ngx_http_tfs_segment_data_t *segment_data)
{
    size_t                                size;
    ngx_buf_t                             *b;
    ngx_chain_t                           *cl;
    ngx_http_tfs_ns_block_info_request_t  *req;

    size = sizeof(ngx_http_tfs_ns_block_info_request_t);

    b = ngx_create_temp_buf(t->pool, size);
    if (b == NULL) {
        return NULL;
    }

    req = (ngx_http_tfs_ns_block_info_request_t *) b->pos;

    req->header.type = NGX_HTTP_TFS_GET_BLOCK_INFO_MESSAGE;
    req->header.len = size - sizeof(ngx_http_tfs_header_t);
    req->header.flag = NGX_HTTP_TFS_PACKET_FLAG;
    req->header.version = NGX_HTTP_TFS_PACKET_VERSION;
    req->header.id = ngx_http_tfs_generate_packet_id();
    req->mode = t->file.open_mode;
    req->block_id = segment_data->segment_info.block_id;
    req->fs_count = 0;

    req->header.crc = ngx_http_tfs_crc(NGX_HTTP_TFS_PACKET_FLAG,
        (const char *) (&req->header + 1), req->header.len);

    b->last += size;

    cl = ngx_alloc_chain_link(t->pool);
    if (cl == NULL) {
        return NULL;
    }

    cl->buf = b;
    cl->next = NULL;

    return cl;
}

__attribute__((used)) static ngx_chain_t *
ngx_http_tfs_create_batch_block_info_message(ngx_http_tfs_t *t)
{
    size_t                                       size;
    uint32_t                                     block_count, real_block_count;
    ngx_uint_t                                   i, j;
    ngx_buf_t                                   *b;
    ngx_chain_t                                 *cl;
    ngx_http_tfs_segment_data_t                 *segment_data;
    ngx_http_tfs_ns_batch_block_info_request_t  *req;

    block_count = t->file.segment_count - t->file.segment_index;
    if (block_count > NGX_HTTP_TFS_MAX_BATCH_COUNT) {
        block_count = NGX_HTTP_TFS_MAX_BATCH_COUNT;
    }

    real_block_count = block_count;
    if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_READ) {
        segment_data = &t->file.segment_data[t->file.segment_index];
        for (i = 0; i < block_count; i++, segment_data++) {
            if (segment_data->cache_hit != NGX_HTTP_TFS_NO_BLOCK_CACHE) {
                real_block_count--;
            }
        }
    }

    size = sizeof(ngx_http_tfs_ns_batch_block_info_request_t)
            + real_block_count * sizeof(uint32_t);

    b = ngx_create_temp_buf(t->pool, size);
    if (b == NULL) {
        return NULL;
    }

    req = (ngx_http_tfs_ns_batch_block_info_request_t *) b->pos;

    req->header.type = NGX_HTTP_TFS_BATCH_GET_BLOCK_INFO_MESSAGE;
    req->header.len = size - sizeof(ngx_http_tfs_header_t);
    req->header.flag = NGX_HTTP_TFS_PACKET_FLAG;
    req->header.version = NGX_HTTP_TFS_PACKET_VERSION;
    req->header.id = ngx_http_tfs_generate_packet_id();
    req->mode = t->file.open_mode;
    req->block_count = real_block_count;
    segment_data = &t->file.segment_data[t->file.segment_index];
    for (i = 0, j = 0; i < block_count; i++, segment_data++) {
        if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_READ) {
            if (segment_data->cache_hit == NGX_HTTP_TFS_NO_BLOCK_CACHE) {
                req->block_ids[j++] = segment_data->segment_info.block_id;
            }

        } else {
            req->block_ids[i] = 0;
        }
    }
    req->header.crc = ngx_http_tfs_crc(NGX_HTTP_TFS_PACKET_FLAG,
                                       (const char *) (&req->header + 1),
                                       req->header.len);

    b->last += size;

    cl = ngx_alloc_chain_link(t->pool);
    if (cl == NULL) {
        return NULL;
    }

    cl->buf = b;
    cl->next = NULL;

    return cl;
}

__attribute__((used)) static ngx_chain_t *
ngx_http_tfs_create_ctl_message(ngx_http_tfs_t *t, uint8_t cmd)
{
    size_t                          size;
    ngx_buf_t                      *b;
    ngx_chain_t                    *cl;
    ngx_http_tfs_ns_ctl_request_t  *req;

    size = sizeof(ngx_http_tfs_ns_ctl_request_t);

    b = ngx_create_temp_buf(t->pool, size);
    if (b == NULL) {
        return NULL;
    }

    req = (ngx_http_tfs_ns_ctl_request_t *) b->pos;
    req->header.type = NGX_HTTP_TFS_CLIENT_CMD_MESSAGE;
    req->header.len = size - sizeof(ngx_http_tfs_header_t);
    req->header.flag = NGX_HTTP_TFS_PACKET_FLAG;
    req->header.version = NGX_HTTP_TFS_PACKET_VERSION;
    req->header.id = ngx_http_tfs_generate_packet_id();
    req->cmd = NGX_HTTP_TFS_CLIENT_CMD_SET_PARAM;
    req->value2 = cmd;

    req->header.crc = ngx_http_tfs_crc(NGX_HTTP_TFS_PACKET_FLAG,
                                       (const char *) (&req->header + 1),
                                       req->header.len);

    b->last += size;

    cl = ngx_alloc_chain_link(t->pool);
    if (cl == NULL) {
        return NULL;
    }

    cl->buf = b;
    cl->next = NULL;

    return cl;
}

ngx_int_t
ngx_http_tfs_parse_block_info_message(ngx_http_tfs_t *t,
    ngx_http_tfs_segment_data_t *segment_data)
{
    u_char                                 *p;
    uint16_t                                type;
    uint32_t                                ds_count;
    ngx_str_t                               err_msg;
    ngx_uint_t                              i;
    ngx_http_tfs_header_t                  *header;
    ngx_http_tfs_block_info_t              *block_info;
    ngx_http_tfs_block_cache_key_t          key;
    ngx_http_tfs_block_cache_value_t        value;
    ngx_http_tfs_peer_connection_t         *tp;
    ngx_http_tfs_ns_block_info_response_t  *resp;

    header = (ngx_http_tfs_header_t *) t->header;
    tp = t->tfs_peer;
    type = header->type;

    switch (type) {
    case NGX_HTTP_TFS_STATUS_MESSAGE:
        ngx_str_set(&err_msg, "get block info (name server)");
        return ngx_http_tfs_status_message(&tp->body_buffer, &err_msg, t->log);
    }

    resp = (ngx_http_tfs_ns_block_info_response_t *) tp->body_buffer.pos;

    p = tp->body_buffer.pos + sizeof(ngx_http_tfs_ns_block_info_response_t);

    if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_WRITE) {
        if (resp->ds_count <= 3) {
            return NGX_HTTP_TFS_EXIT_GENERAL_ERROR;
        }

        /* flag version leaseid */
        ds_count = resp->ds_count - 3;

    } else {
        ds_count = resp->ds_count;
    }

    t->r_ctx.fsname.file.block_id = resp->block_id;

    segment_data->segment_info.block_id = resp->block_id;
    block_info = &segment_data->block_info;

    block_info->ds_count = ds_count;
    block_info->ds_addrs = ngx_pcalloc(t->pool,
                                       sizeof(ngx_http_tfs_inet_t) * ds_count);
    if (block_info->ds_addrs == NULL) {
        return NGX_ERROR;
    }

    for (i = 0; i < ds_count; i++) {
        block_info->ds_addrs[i].ip = *(uint32_t *) p;
        block_info->ds_addrs[i].port = *(uint32_t *) (p + sizeof(uint32_t));

        p += sizeof(uint32_t) * 2;
    }

    /* insert block cache */
    if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_READ
        || t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_STAT)
    {
        key.ns_addr = *((uint64_t*)(&t->name_server_addr));
        key.block_id = resp->block_id;
        value.ds_count = block_info->ds_count;
        value.ds_addrs = (uint64_t *)block_info->ds_addrs;
        ngx_http_tfs_block_cache_insert(&t->block_cache_ctx,
                                        t->pool, t->log, &key, &value);
    }

    if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_WRITE) {
        /* flag */
        p += sizeof(uint64_t);
        /* version */
        block_info->version = *((int32_t *) p);
        p += sizeof(int64_t);
        /* lease id */
        block_info->lease_id = *((int32_t *) p);
    }

    segment_data->ds_retry = 0;

    ngx_log_debug5(NGX_LOG_DEBUG_HTTP, t->log, 0,
                   "get block info from "
                   "nameserver: %V, block id: %uD, ds count: %uD, "
                   "version: %D, lease id: %D",
                   &t->name_server_addr_text, resp->block_id,
                   block_info->ds_count,
                   block_info->version, block_info->lease_id);

    return NGX_OK;
}

ngx_int_t
ngx_http_tfs_parse_batch_block_info_message(ngx_http_tfs_t *t,
    ngx_http_tfs_segment_data_t *segment_data)
{
    u_char                                       *p;
    uint16_t                                      type;
    uint32_t                                      block_count, complete_count,
                                                  ds_count, block_id;
    ngx_str_t                                     err_msg;
    ngx_uint_t                                    i, j, k;
    ngx_http_tfs_header_t                        *header;
    ngx_http_tfs_block_info_t                    *block_info;
    ngx_http_tfs_peer_connection_t               *tp;
    ngx_http_tfs_block_cache_key_t                key;
    ngx_http_tfs_block_cache_value_t              value;
    ngx_http_tfs_ns_batch_block_info_response_t  *resp;

    header = (ngx_http_tfs_header_t *) t->header;
    tp = t->tfs_peer;
    type = header->type;

    switch (type) {
    case NGX_HTTP_TFS_STATUS_MESSAGE:
        ngx_str_set(&err_msg, "batch get block info (name server)");
        return ngx_http_tfs_status_message(&tp->body_buffer, &err_msg, t->log);
    }

    resp = (ngx_http_tfs_ns_batch_block_info_response_t *) tp->body_buffer.pos;

    p = tp->body_buffer.pos
         + sizeof(ngx_http_tfs_ns_batch_block_info_response_t);

    block_count = t->file.segment_count - t->file.segment_index;
    if (block_count > NGX_HTTP_TFS_MAX_BATCH_COUNT) {
        block_count = NGX_HTTP_TFS_MAX_BATCH_COUNT;
    }
    t->file.curr_batch_count = resp->block_count;

    for (i = 0; i < resp->block_count; i++) {
        j = i;
        /* block id */
        block_id = *(uint32_t *) p;
        p += sizeof(uint32_t);
        /* read need find the right segment according to block id */
        if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_READ) {
            for (j = 0; j < block_count; j++) {
                if (segment_data[j].segment_info.block_id == block_id) {
                    break;
                }
            }
            if (j == block_count) {
                return NGX_HTTP_TFS_AGAIN;
            }
        }
        segment_data[j].segment_info.block_id = block_id;

        block_info = &segment_data[j].block_info;

        /* ds count */
        ds_count = *(uint32_t *) p;
        p += sizeof(uint32_t);

        if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_WRITE) {
            if (ds_count <= 3) {
                return NGX_HTTP_TFS_EXIT_GENERAL_ERROR;
            }

            /* flag version leaseid */
            block_info->ds_count = ds_count - 3;

        } else {
            if (ds_count < 1) {
                return NGX_HTTP_TFS_EXIT_GENERAL_ERROR;
            }

            block_info->ds_count = ds_count;
        }

        block_info->ds_addrs = ngx_pcalloc(t->pool,
                                        sizeof(ngx_http_tfs_inet_t) * ds_count);
        if (block_info->ds_addrs == NULL) {
            return NGX_ERROR;
        }

        for (k = 0; k < block_info->ds_count; k++) {
            block_info->ds_addrs[k].ip = *(uint32_t *) p;
            block_info->ds_addrs[k].port = *(uint32_t *) (p + sizeof(uint32_t));

            p += sizeof(uint32_t) * 2;
        }

        if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_WRITE) {
            /* flag */
            p += sizeof(uint64_t);
            /* version */
            block_info->version = *((int32_t *) p);
            p += sizeof(int64_t);
            /* lease id */
            block_info->lease_id = *((int32_t *) p);
            p += sizeof(int64_t);
        }

        ngx_log_debug5(NGX_LOG_DEBUG_HTTP, t->log, 0,
                       "batch get block info from nameserver: "
                       "%V, block id: %uD, "
                       "ds count: %uD, version: %D, lease id: %D",
                       &t->name_server_addr_text, block_id,
                       block_info->ds_count,
                       block_info->version, block_info->lease_id);

        /* insert block cache  */
        if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_READ) {
            key.ns_addr = *((uint64_t *)(&t->name_server_addr));
            key.block_id = block_id;
            value.ds_count = block_info->ds_count;
            value.ds_addrs = (uint64_t *)block_info->ds_addrs;
            ngx_http_tfs_block_cache_insert(&t->block_cache_ctx,
                                            t->pool, t->log, &key, &value);
        }

        /* reset segment status */
        segment_data[j].ds_retry = 0;
    }

    /* check if all semgents complete */
    if (t->file.open_mode & NGX_HTTP_TFS_OPEN_MODE_READ) {
        complete_count = 0;
        for (i = 0; i < block_count; i++) {
            if (segment_data[i].block_info.ds_addrs != NULL) {
                complete_count++;
                continue;
            }

            /* maybe has duplicate block, find in already complete segment */
            for (j = 0; j < i; j++) {
                if (segment_data[i].segment_info.block_id
                    != segment_data[j].segment_info.block_id)
                {
                    continue;
                }

                /* TODO: check this */
                segment_data[i].block_info = segment_data[j].block_info;
                segment_data[i].ds_retry = 0;
                complete_count++;
                break;
            }
        }
        if (complete_count != block_count) {
            return NGX_HTTP_TFS_AGAIN;
        }
    }

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_http_tfs_parse_ctl_message(ngx_http_tfs_t *t, uint8_t cmd)
{
    uint32_t                         code;
    ngx_int_t                        cluster_id;
    ngx_http_tfs_status_msg_t       *res;
    ngx_http_tfs_peer_connection_t  *tp;

    tp = t->tfs_peer;
    res = (ngx_http_tfs_status_msg_t *) tp->body_buffer.pos;
    code = res->code;

    if (code == NGX_HTTP_TFS_STATUS_MESSAGE_OK && res->error_len > 0) {
        switch(cmd) {
        case NGX_HTTP_TFS_CMD_GET_CLUSTER_ID_NS:
            cluster_id = ngx_atoi(res->error_str, res->error_len - 1);
            cluster_id = cluster_id - '0';

            if (cluster_id == NGX_ERROR) {
                ngx_log_error(NGX_LOG_ERR, t->log, 0,
                              "invalid cluster id \"%s\" ", res->error_str);
                return NGX_ERROR;
            }

            t->file.cluster_id = cluster_id;
            break;
        case NGX_HTTP_TFS_CMD_GET_GROUP_COUNT:
            t->group_count = ngx_atoi(res->error_str, res->error_len - 1);
            if (t->group_count == NGX_ERROR || t->group_count <= 0) {
                ngx_log_error(NGX_LOG_WARN, t->log, 0,
                              "invalid  group count \"%s\" ", res->error_str);
                t->group_count = 1; /* compatible with old ns(1.3) */
            }
            break;
        case NGX_HTTP_TFS_CMD_GET_GROUP_SEQ:
            t->group_seq = ngx_atoi(res->error_str, res->error_len - 1);
            if (t->group_seq == NGX_ERROR || t->group_seq < 0) {
                ngx_log_error(NGX_LOG_WARN, t->log, 0,
                              "invalid  group seq \"%s\" ", res->error_str);
                t->group_seq = 0; /* compatible with old ns(1.3) */
            }
        }

    } else {
        ngx_log_error(NGX_LOG_ERR, t->log, 0,
                      "tfs name server ctl message invalid");
        return NGX_ERROR;
    }

    return NGX_OK;
}

