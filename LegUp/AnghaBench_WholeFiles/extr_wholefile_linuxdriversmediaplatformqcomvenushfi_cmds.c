#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_64__   TYPE_9__ ;
typedef  struct TYPE_63__   TYPE_8__ ;
typedef  struct TYPE_62__   TYPE_7__ ;
typedef  struct TYPE_61__   TYPE_6__ ;
typedef  struct TYPE_60__   TYPE_5__ ;
typedef  struct TYPE_59__   TYPE_4__ ;
typedef  struct TYPE_58__   TYPE_3__ ;
typedef  struct TYPE_57__   TYPE_32__ ;
typedef  struct TYPE_56__   TYPE_31__ ;
typedef  struct TYPE_55__   TYPE_30__ ;
typedef  struct TYPE_54__   TYPE_2__ ;
typedef  struct TYPE_53__   TYPE_29__ ;
typedef  struct TYPE_52__   TYPE_28__ ;
typedef  struct TYPE_51__   TYPE_27__ ;
typedef  struct TYPE_50__   TYPE_26__ ;
typedef  struct TYPE_49__   TYPE_25__ ;
typedef  struct TYPE_48__   TYPE_24__ ;
typedef  struct TYPE_47__   TYPE_23__ ;
typedef  struct TYPE_46__   TYPE_22__ ;
typedef  struct TYPE_45__   TYPE_21__ ;
typedef  struct TYPE_44__   TYPE_20__ ;
typedef  struct TYPE_43__   TYPE_1__ ;
typedef  struct TYPE_42__   TYPE_19__ ;
typedef  struct TYPE_41__   TYPE_18__ ;
typedef  struct TYPE_40__   TYPE_17__ ;
typedef  struct TYPE_39__   TYPE_16__ ;
typedef  struct TYPE_38__   TYPE_15__ ;
typedef  struct TYPE_37__   TYPE_14__ ;
typedef  struct TYPE_36__   TYPE_13__ ;
typedef  struct TYPE_35__   TYPE_12__ ;
typedef  struct TYPE_34__   TYPE_11__ ;
typedef  struct TYPE_33__   TYPE_10__ ;

/* Type definitions */
typedef  int u32 ;
struct hfi_vpe_color_space_conversion {int /*<<< orphan*/  csc_limit; int /*<<< orphan*/  csc_bias; int /*<<< orphan*/  csc_matrix; } ;
struct hfi_videocores_usage_type {int /*<<< orphan*/  video_core_enable_mask; } ;
struct hfi_video_work_mode {int /*<<< orphan*/  video_work_mode; } ;
struct hfi_vc1e_perf_cfg_type {int /*<<< orphan*/  search_range_y_subsampled; int /*<<< orphan*/  search_range_x_subsampled; } ;
struct hfi_uncompressed_format_select {int /*<<< orphan*/  format; int /*<<< orphan*/  buffer_type; } ;
struct TYPE_62__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct hfi_sys_test_ssr_pkt {int trigger_type; TYPE_7__ hdr; } ;
struct TYPE_58__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct hfi_sys_set_resource_pkt {TYPE_3__ hdr; void* resource_type; int /*<<< orphan*/ * resource_data; void* resource_handle; } ;
struct TYPE_61__ {int size; void* pkt_type; } ;
struct hfi_sys_set_property_pkt {int* data; int num_properties; TYPE_6__ hdr; } ;
struct TYPE_59__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct hfi_sys_release_resource_pkt {void* resource_type; void* resource_handle; TYPE_4__ hdr; } ;
struct TYPE_60__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct hfi_sys_ping_pkt {int client_data; TYPE_5__ hdr; } ;
struct TYPE_54__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct hfi_sys_pc_prep_pkt {TYPE_2__ hdr; } ;
struct TYPE_43__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct hfi_sys_init_pkt {int arch_type; TYPE_1__ hdr; } ;
struct TYPE_63__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct hfi_sys_get_property_pkt {int num_properties; int /*<<< orphan*/ * data; TYPE_8__ hdr; } ;
struct TYPE_56__ {int size; void* pkt_type; } ;
struct TYPE_57__ {TYPE_31__ hdr; void* session_id; } ;
struct hfi_session_set_property_pkt {int* data; int num_properties; TYPE_32__ shdr; } ;
struct TYPE_36__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct TYPE_37__ {TYPE_13__ hdr; void* session_id; } ;
struct hfi_session_set_buffers_pkt {unsigned int num_buffers; scalar_t__ buffer_type; int /*<<< orphan*/ * buffer_info; TYPE_14__ shdr; scalar_t__ extradata_size; int /*<<< orphan*/  min_buffer_size; int /*<<< orphan*/  buffer_size; } ;
struct TYPE_38__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct TYPE_39__ {TYPE_15__ hdr; void* session_id; } ;
struct hfi_session_release_buffer_pkt {unsigned int num_buffers; scalar_t__ buffer_type; int /*<<< orphan*/  response_req; TYPE_16__ shdr; scalar_t__ extradata_size; int /*<<< orphan*/ * buffer_info; int /*<<< orphan*/  buffer_size; } ;
struct TYPE_34__ {int size; int pkt_type; } ;
struct TYPE_35__ {void* session_id; TYPE_11__ hdr; } ;
struct hfi_session_pkt {TYPE_12__ shdr; } ;
struct TYPE_47__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct TYPE_48__ {void* session_id; TYPE_23__ hdr; } ;
struct hfi_session_parse_sequence_header_pkt {int header_len; int packet_buffer; TYPE_24__ shdr; } ;
struct TYPE_64__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct TYPE_33__ {void* session_id; TYPE_9__ hdr; } ;
struct hfi_session_init_pkt {int session_domain; int session_codec; TYPE_10__ shdr; } ;
struct TYPE_49__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct TYPE_50__ {void* session_id; TYPE_25__ hdr; } ;
struct hfi_session_get_sequence_header_pkt {int buffer_len; int packet_buffer; TYPE_26__ shdr; } ;
struct TYPE_53__ {int size; void* pkt_type; } ;
struct TYPE_55__ {void* session_id; TYPE_29__ hdr; } ;
struct hfi_session_get_property_pkt {int num_properties; int* data; TYPE_30__ shdr; } ;
struct TYPE_51__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct TYPE_52__ {void* session_id; TYPE_27__ hdr; } ;
struct hfi_session_flush_pkt {int flush_type; TYPE_28__ shdr; } ;
struct TYPE_45__ {int size; int /*<<< orphan*/  pkt_type; } ;
struct TYPE_46__ {void* session_id; TYPE_21__ hdr; } ;
struct hfi_session_fill_buffer_pkt {int stream_id; int /*<<< orphan*/ * data; int /*<<< orphan*/  offset; int /*<<< orphan*/  filled_len; int /*<<< orphan*/  alloc_len; int /*<<< orphan*/  extradata_buffer; scalar_t__ packet_buffer; int /*<<< orphan*/  output_tag; TYPE_22__ shdr; } ;
struct TYPE_42__ {int size; void* pkt_type; } ;
struct TYPE_44__ {void* session_id; TYPE_19__ hdr; } ;
struct hfi_session_empty_buffer_uncompressed_plane0_pkt {int /*<<< orphan*/  extradata_buffer; scalar_t__ packet_buffer; int /*<<< orphan*/  input_tag; int /*<<< orphan*/  filled_len; int /*<<< orphan*/  alloc_len; int /*<<< orphan*/  offset; int /*<<< orphan*/  mark_data; int /*<<< orphan*/  mark_target; int /*<<< orphan*/  flags; void* time_stamp_lo; void* time_stamp_hi; scalar_t__ view_id; TYPE_20__ shdr; } ;
struct TYPE_40__ {int size; void* pkt_type; } ;
struct TYPE_41__ {void* session_id; TYPE_17__ hdr; } ;
struct hfi_session_empty_buffer_compressed_pkt {scalar_t__ packet_buffer; int /*<<< orphan*/  input_tag; int /*<<< orphan*/  filled_len; int /*<<< orphan*/  alloc_len; int /*<<< orphan*/  offset; int /*<<< orphan*/  mark_data; int /*<<< orphan*/  mark_target; int /*<<< orphan*/  flags; void* time_stamp_lo; void* time_stamp_hi; TYPE_18__ shdr; } ;
struct hfi_scs_threshold {int threshold_value; } ;
struct hfi_resource_ocmem {int size; int mem; } ;
struct hfi_quantization_range {int min_qp; int max_qp; int /*<<< orphan*/  layer_id; } ;
struct hfi_quantization {int /*<<< orphan*/  layer_id; int /*<<< orphan*/  qp_b; int /*<<< orphan*/  qp_p; int /*<<< orphan*/  qp_i; } ;
struct hfi_profile_level {int level; int /*<<< orphan*/  profile; } ;
struct hfi_operations_type {int /*<<< orphan*/  flip; int /*<<< orphan*/  rotation; } ;
struct hfi_nal_stream_format_select {int /*<<< orphan*/  format; } ;
struct hfi_mvc_buffer_layout_descp_type {int /*<<< orphan*/  ngap; int /*<<< orphan*/  bright_view_first; int /*<<< orphan*/  layout_type; } ;
struct hfi_multi_stream_3x {int /*<<< orphan*/  enable; int /*<<< orphan*/  buffer_type; } ;
struct hfi_multi_stream {int /*<<< orphan*/  enable; int /*<<< orphan*/  buffer_type; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct hfi_multi_slice_control {int /*<<< orphan*/  slice_size; int /*<<< orphan*/  multi_slice; } ;
struct hfi_mpeg4_time_resolution {int /*<<< orphan*/  time_increment_resolution; } ;
struct hfi_mpeg4_header_extension {int /*<<< orphan*/  header_extension; } ;
struct hfi_max_num_b_frames {int max_num_b_frames; } ;
struct hfi_ltr_use {int /*<<< orphan*/  use_constrnt; int /*<<< orphan*/  ref_ltr; int /*<<< orphan*/  frames; } ;
struct hfi_ltr_mode {int /*<<< orphan*/  trust_mode; int /*<<< orphan*/  ltr_count; int /*<<< orphan*/  ltr_mode; } ;
struct hfi_ltr_mark {int /*<<< orphan*/  mark_frame; } ;
struct hfi_intra_refresh_3x {int /*<<< orphan*/  mbs; int /*<<< orphan*/  mode; } ;
struct hfi_intra_refresh {int /*<<< orphan*/  cir_mbs; int /*<<< orphan*/  mode; int /*<<< orphan*/  air_ref; int /*<<< orphan*/  air_mbs; } ;
struct hfi_intra_period {int /*<<< orphan*/  bframes; int /*<<< orphan*/  pframes; } ;
struct hfi_initial_quantization {int /*<<< orphan*/  qp_b; int /*<<< orphan*/  qp_p; int /*<<< orphan*/  qp_i; int /*<<< orphan*/  init_qp_enable; } ;
struct hfi_idr_period {int /*<<< orphan*/  idr_period; } ;
struct hfi_hybrid_hierp {int /*<<< orphan*/  layers; } ;
struct hfi_h264_vui_timing_info {int /*<<< orphan*/  time_scale; int /*<<< orphan*/  fixed_framerate; int /*<<< orphan*/  enable; } ;
struct hfi_h264_entropy_control {int /*<<< orphan*/  cabac_model; int /*<<< orphan*/  entropy_mode; } ;
struct hfi_h264_db_control {int /*<<< orphan*/  slice_beta_offset; int /*<<< orphan*/  slice_alpha_offset; int /*<<< orphan*/  mode; } ;
struct hfi_framesize {int /*<<< orphan*/  width; int /*<<< orphan*/  height; int /*<<< orphan*/  buffer_type; } ;
struct hfi_framerate {int /*<<< orphan*/  framerate; int /*<<< orphan*/  buffer_type; } ;
struct hfi_frame_data {scalar_t__ buffer_type; int /*<<< orphan*/  extradata_size; int /*<<< orphan*/  offset; int /*<<< orphan*/  filled_len; int /*<<< orphan*/  alloc_len; int /*<<< orphan*/  extradata_addr; scalar_t__ device_addr; int /*<<< orphan*/  clnt_data; int /*<<< orphan*/  mark_data; int /*<<< orphan*/  mark_target; int /*<<< orphan*/  flags; int /*<<< orphan*/  timestamp; } ;
struct hfi_enable_picture {int /*<<< orphan*/  picture_type; } ;
struct hfi_enable {int enable; } ;
struct hfi_display_picture_buffer_count {int /*<<< orphan*/  enable; int /*<<< orphan*/  count; } ;
struct hfi_debug_config {int config; int mode; } ;
struct hfi_conceal_color {int conceal_color; } ;
struct hfi_buffer_size_actual {int /*<<< orphan*/  type; int /*<<< orphan*/  size; } ;
struct hfi_buffer_info {int /*<<< orphan*/  extradata_addr; int /*<<< orphan*/  buffer_addr; } ;
struct hfi_buffer_display_hold_count_actual {int /*<<< orphan*/  type; int /*<<< orphan*/  hold_count; } ;
struct hfi_buffer_desc {unsigned int num_buffers; scalar_t__ buffer_type; int /*<<< orphan*/  response_required; int /*<<< orphan*/  device_addr; int /*<<< orphan*/  extradata_addr; int /*<<< orphan*/  buffer_size; scalar_t__ extradata_size; } ;
struct hfi_buffer_count_actual_4xx {int /*<<< orphan*/  count_min_host; int /*<<< orphan*/  type; int /*<<< orphan*/  count_actual; } ;
struct hfi_buffer_count_actual {int /*<<< orphan*/  count_actual; int /*<<< orphan*/  type; } ;
struct hfi_buffer_alloc_mode {int /*<<< orphan*/  mode; int /*<<< orphan*/  type; } ;
struct hfi_bitrate {int /*<<< orphan*/  layer_id; int /*<<< orphan*/  bitrate; } ;
typedef  enum hfi_version { ____Placeholder_hfi_version } hfi_version ;

/* Variables and functions */
 int EINVAL ; 
 int ENOTSUPP ; 
 int ERANGE ; 
 scalar_t__ HFI_BUFFER_OUTPUT ; 
 scalar_t__ HFI_BUFFER_OUTPUT2 ; 
 void* HFI_CMD_SESSION_EMPTY_BUFFER ; 
 int /*<<< orphan*/  HFI_CMD_SESSION_FILL_BUFFER ; 
 int /*<<< orphan*/  HFI_CMD_SESSION_FLUSH ; 
 void* HFI_CMD_SESSION_GET_PROPERTY ; 
 int /*<<< orphan*/  HFI_CMD_SESSION_GET_SEQUENCE_HEADER ; 
 int /*<<< orphan*/  HFI_CMD_SESSION_PARSE_SEQUENCE_HEADER ; 
 int /*<<< orphan*/  HFI_CMD_SESSION_RELEASE_BUFFERS ; 
 int /*<<< orphan*/  HFI_CMD_SESSION_SET_BUFFERS ; 
 void* HFI_CMD_SESSION_SET_PROPERTY ; 
 int /*<<< orphan*/  HFI_CMD_SYS_GET_PROPERTY ; 
 int /*<<< orphan*/  HFI_CMD_SYS_INIT ; 
 int /*<<< orphan*/  HFI_CMD_SYS_PC_PREP ; 
 int /*<<< orphan*/  HFI_CMD_SYS_PING ; 
 int /*<<< orphan*/  HFI_CMD_SYS_RELEASE_RESOURCE ; 
 int /*<<< orphan*/  HFI_CMD_SYS_SESSION_INIT ; 
 void* HFI_CMD_SYS_SET_PROPERTY ; 
 int /*<<< orphan*/  HFI_CMD_SYS_SET_RESOURCE ; 
 int /*<<< orphan*/  HFI_CMD_SYS_TEST_SSR ; 
#define  HFI_DIVX_FORMAT_4 257 
#define  HFI_DIVX_FORMAT_5 256 
#define  HFI_DIVX_FORMAT_6 255 
#define  HFI_FLIP_HORIZONTAL 254 
#define  HFI_FLIP_NONE 253 
#define  HFI_FLIP_VERTICAL 252 
#define  HFI_FLUSH_ALL 251 
#define  HFI_FLUSH_INPUT 250 
#define  HFI_FLUSH_OUTPUT 249 
#define  HFI_FLUSH_OUTPUT2 248 
#define  HFI_H264_DB_MODE_ALL_BOUNDARY 247 
#define  HFI_H264_DB_MODE_DISABLE 246 
#define  HFI_H264_DB_MODE_SKIP_SLICE_BOUNDARY 245 
 int /*<<< orphan*/  HFI_H264_ENTROPY_CABAC ; 
 int /*<<< orphan*/  HFI_H264_PROFILE_HIGH ; 
#define  HFI_INTRA_REFRESH_ADAPTIVE 244 
#define  HFI_INTRA_REFRESH_CYCLIC 243 
#define  HFI_INTRA_REFRESH_CYCLIC_ADAPTIVE 242 
#define  HFI_INTRA_REFRESH_NONE 241 
#define  HFI_INTRA_REFRESH_RANDOM 240 
#define  HFI_LTR_MODE_DISABLE 239 
#define  HFI_LTR_MODE_MANUAL 238 
#define  HFI_LTR_MODE_PERIODIC 237 
#define  HFI_MULTI_SLICE_BY_BYTE_COUNT 236 
#define  HFI_MULTI_SLICE_BY_MB_COUNT 235 
#define  HFI_MULTI_SLICE_GOB 234 
#define  HFI_MULTI_SLICE_OFF 233 
#define  HFI_MVC_BUFFER_LAYOUT_SEQ 232 
#define  HFI_MVC_BUFFER_LAYOUT_TOP_BOTTOM 231 
#define  HFI_OUTPUT_ORDER_DECODE 230 
#define  HFI_OUTPUT_ORDER_DISPLAY 229 
#define  HFI_PROPERTY_CONFIG_BATCH_INFO 228 
#define  HFI_PROPERTY_CONFIG_BUFFER_REQUIREMENTS 227 
#define  HFI_PROPERTY_CONFIG_FRAME_RATE 226 
#define  HFI_PROPERTY_CONFIG_PRIORITY 225 
#define  HFI_PROPERTY_CONFIG_REALTIME 224 
#define  HFI_PROPERTY_CONFIG_VDEC_ENTROPY 223 
#define  HFI_PROPERTY_CONFIG_VDEC_MB_ERROR_MAP_REPORTING 222 
#define  HFI_PROPERTY_CONFIG_VDEC_POST_LOOP_DEBLOCKER 221 
#define  HFI_PROPERTY_CONFIG_VENC_HIER_P_ENH_LAYER 220 
#define  HFI_PROPERTY_CONFIG_VENC_IDR_PERIOD 219 
#define  HFI_PROPERTY_CONFIG_VENC_INTRA_PERIOD 218 
#define  HFI_PROPERTY_CONFIG_VENC_MARKLTRFRAME 217 
#define  HFI_PROPERTY_CONFIG_VENC_MAX_BITRATE 216 
#define  HFI_PROPERTY_CONFIG_VENC_PERF_MODE 215 
#define  HFI_PROPERTY_CONFIG_VENC_REQUEST_SYNC_FRAME 214 
#define  HFI_PROPERTY_CONFIG_VENC_SYNC_FRAME_SEQUENCE_HEADER 213 
#define  HFI_PROPERTY_CONFIG_VENC_TARGET_BITRATE 212 
#define  HFI_PROPERTY_CONFIG_VENC_USELTRFRAME 211 
#define  HFI_PROPERTY_CONFIG_VIDEOCORES_USAGE 210 
#define  HFI_PROPERTY_CONFIG_VPE_DEINTERLACE 209 
#define  HFI_PROPERTY_CONFIG_VPE_OPERATIONS 208 
#define  HFI_PROPERTY_PARAM_BUFFER_ALLOC_MODE 207 
#define  HFI_PROPERTY_PARAM_BUFFER_COUNT_ACTUAL 206 
#define  HFI_PROPERTY_PARAM_BUFFER_DISPLAY_HOLD_COUNT_ACTUAL 205 
#define  HFI_PROPERTY_PARAM_BUFFER_SIZE_ACTUAL 204 
#define  HFI_PROPERTY_PARAM_CAPABILITY_SUPPORTED 203 
#define  HFI_PROPERTY_PARAM_CHROMA_SITE 202 
#define  HFI_PROPERTY_PARAM_CODEC_SUPPORTED 201 
#define  HFI_PROPERTY_PARAM_DIVX_FORMAT 200 
#define  HFI_PROPERTY_PARAM_FRAME_SIZE 199 
#define  HFI_PROPERTY_PARAM_INTERLACE_FORMAT_SUPPORTED 198 
#define  HFI_PROPERTY_PARAM_MAX_SEQUENCE_HEADER_SIZE 197 
#define  HFI_PROPERTY_PARAM_MULTI_VIEW_FORMAT 196 
#define  HFI_PROPERTY_PARAM_MVC_BUFFER_LAYOUT 195 
#define  HFI_PROPERTY_PARAM_NAL_STREAM_FORMAT_SELECT 194 
#define  HFI_PROPERTY_PARAM_NAL_STREAM_FORMAT_SUPPORTED 193 
#define  HFI_PROPERTY_PARAM_PROFILE_LEVEL_CURRENT 192 
#define  HFI_PROPERTY_PARAM_PROFILE_LEVEL_SUPPORTED 191 
#define  HFI_PROPERTY_PARAM_PROPERTIES_SUPPORTED 190 
#define  HFI_PROPERTY_PARAM_UNCOMPRESSED_FORMAT_SELECT 189 
#define  HFI_PROPERTY_PARAM_UNCOMPRESSED_FORMAT_SUPPORTED 188 
#define  HFI_PROPERTY_PARAM_VDEC_CONCEAL_COLOR 187 
#define  HFI_PROPERTY_PARAM_VDEC_CONTINUE_DATA_TRANSFER 186 
#define  HFI_PROPERTY_PARAM_VDEC_DISPLAY_PICTURE_BUFFER_COUNT 185 
#define  HFI_PROPERTY_PARAM_VDEC_FRAME_ASSEMBLY 184 
#define  HFI_PROPERTY_PARAM_VDEC_H264_ENTROPY_SWITCHING 183 
#define  HFI_PROPERTY_PARAM_VDEC_MB_QUANTIZATION 182 
#define  HFI_PROPERTY_PARAM_VDEC_MULTI_STREAM 181 
#define  HFI_PROPERTY_PARAM_VDEC_MULTI_VIEW_SELECT 180 
#define  HFI_PROPERTY_PARAM_VDEC_NONCP_OUTPUT2 179 
#define  HFI_PROPERTY_PARAM_VDEC_NUM_CONCEALED_MB 178 
#define  HFI_PROPERTY_PARAM_VDEC_OUTPUT2_KEEP_ASPECT_RATIO 177 
#define  HFI_PROPERTY_PARAM_VDEC_OUTPUT_ORDER 176 
#define  HFI_PROPERTY_PARAM_VDEC_PICTURE_TYPE_DECODE 175 
#define  HFI_PROPERTY_PARAM_VDEC_SCS_THRESHOLD 174 
#define  HFI_PROPERTY_PARAM_VDEC_THUMBNAIL_MODE 173 
#define  HFI_PROPERTY_PARAM_VENC_DISABLE_RC_TIMESTAMP 172 
#define  HFI_PROPERTY_PARAM_VENC_H264_DEBLOCK_CONTROL 171 
#define  HFI_PROPERTY_PARAM_VENC_H264_ENTROPY_CONTROL 170 
#define  HFI_PROPERTY_PARAM_VENC_H264_GENERATE_AUDNAL 169 
#define  HFI_PROPERTY_PARAM_VENC_H264_NAL_SVC_EXT 168 
#define  HFI_PROPERTY_PARAM_VENC_H264_VUI_BITSTREAM_RESTRC 167 
#define  HFI_PROPERTY_PARAM_VENC_H264_VUI_TIMING_INFO 166 
#define  HFI_PROPERTY_PARAM_VENC_HIER_B_MAX_NUM_ENH_LAYER 165 
#define  HFI_PROPERTY_PARAM_VENC_HIER_P_HYBRID_MODE 164 
#define  HFI_PROPERTY_PARAM_VENC_HIER_P_MAX_NUM_ENH_LAYER 163 
#define  HFI_PROPERTY_PARAM_VENC_INITIAL_QP 162 
#define  HFI_PROPERTY_PARAM_VENC_INTRA_REFRESH 161 
#define  HFI_PROPERTY_PARAM_VENC_LTRMODE 160 
#define  HFI_PROPERTY_PARAM_VENC_MAX_NUM_B_FRAMES 159 
#define  HFI_PROPERTY_PARAM_VENC_MPEG4_AC_PREDICTION 158 
#define  HFI_PROPERTY_PARAM_VENC_MPEG4_HEADER_EXTENSION 157 
#define  HFI_PROPERTY_PARAM_VENC_MPEG4_SHORT_HEADER 156 
#define  HFI_PROPERTY_PARAM_VENC_MPEG4_TIME_RESOLUTION 155 
#define  HFI_PROPERTY_PARAM_VENC_MULTI_SLICE_CONTROL 154 
#define  HFI_PROPERTY_PARAM_VENC_MULTI_SLICE_INFO 153 
#define  HFI_PROPERTY_PARAM_VENC_PRESERVE_TEXT_QUALITY 152 
#define  HFI_PROPERTY_PARAM_VENC_RATE_CONTROL 151 
#define  HFI_PROPERTY_PARAM_VENC_SESSION_QP 150 
#define  HFI_PROPERTY_PARAM_VENC_SESSION_QP_RANGE 149 
#define  HFI_PROPERTY_PARAM_VENC_SLICE_DELIVERY_MODE 148 
#define  HFI_PROPERTY_PARAM_VENC_VC1_PERF_CFG 147 
#define  HFI_PROPERTY_PARAM_VENC_VPX_ERROR_RESILIENCE_MODE 146 
#define  HFI_PROPERTY_PARAM_VPE_COLOR_SPACE_CONVERSION 145 
#define  HFI_PROPERTY_PARAM_WORK_MODE 144 
 int HFI_PROPERTY_SYS_CODEC_POWER_PLANE_CTRL ; 
 int HFI_PROPERTY_SYS_CONFIG_COVERAGE ; 
 int HFI_PROPERTY_SYS_DEBUG_CONFIG ; 
#define  HFI_PROPERTY_SYS_IDLE_INDICATOR 143 
 int /*<<< orphan*/  HFI_PROPERTY_SYS_IMAGE_VERSION ; 
#define  HFI_RATE_CONTROL_CBR_CFR 142 
#define  HFI_RATE_CONTROL_CBR_VFR 141 
#define  HFI_RATE_CONTROL_OFF 140 
#define  HFI_RATE_CONTROL_VBR_CFR 139 
#define  HFI_RATE_CONTROL_VBR_VFR 138 
 void* HFI_RESOURCE_OCMEM ; 
#define  HFI_ROTATE_180 137 
#define  HFI_ROTATE_270 136 
#define  HFI_ROTATE_90 135 
#define  HFI_ROTATE_NONE 134 
#define  HFI_TEST_SSR_HW_WDOG_IRQ 133 
#define  HFI_TEST_SSR_SW_DIV_BY_ZERO 132 
#define  HFI_TEST_SSR_SW_ERR_FATAL 131 
 scalar_t__ HFI_VERSION_1XX ; 
 scalar_t__ HFI_VERSION_3XX ; 
#define  VIDC_RESOURCE_NONE 130 
#define  VIDC_RESOURCE_OCMEM 129 
#define  VIDC_RESOURCE_VMEM 128 
 void* hash32_ptr (void*) ; 
 scalar_t__ hfi_ver ; 
 void* lower_32_bits (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 void* upper_32_bits (int /*<<< orphan*/ ) ; 

void pkt_sys_init(struct hfi_sys_init_pkt *pkt, u32 arch_type)
{
	pkt->hdr.size = sizeof(*pkt);
	pkt->hdr.pkt_type = HFI_CMD_SYS_INIT;
	pkt->arch_type = arch_type;
}

void pkt_sys_pc_prep(struct hfi_sys_pc_prep_pkt *pkt)
{
	pkt->hdr.size = sizeof(*pkt);
	pkt->hdr.pkt_type = HFI_CMD_SYS_PC_PREP;
}

void pkt_sys_idle_indicator(struct hfi_sys_set_property_pkt *pkt, u32 enable)
{
	struct hfi_enable *hfi = (struct hfi_enable *)&pkt->data[1];

	pkt->hdr.size = sizeof(*pkt) + sizeof(*hfi) + sizeof(u32);
	pkt->hdr.pkt_type = HFI_CMD_SYS_SET_PROPERTY;
	pkt->num_properties = 1;
	pkt->data[0] = HFI_PROPERTY_SYS_IDLE_INDICATOR;
	hfi->enable = enable;
}

void pkt_sys_debug_config(struct hfi_sys_set_property_pkt *pkt, u32 mode,
			  u32 config)
{
	struct hfi_debug_config *hfi;

	pkt->hdr.size = sizeof(*pkt) + sizeof(*hfi) + sizeof(u32);
	pkt->hdr.pkt_type = HFI_CMD_SYS_SET_PROPERTY;
	pkt->num_properties = 1;
	pkt->data[0] = HFI_PROPERTY_SYS_DEBUG_CONFIG;
	hfi = (struct hfi_debug_config *)&pkt->data[1];
	hfi->config = config;
	hfi->mode = mode;
}

void pkt_sys_coverage_config(struct hfi_sys_set_property_pkt *pkt, u32 mode)
{
	pkt->hdr.size = sizeof(*pkt) + sizeof(u32);
	pkt->hdr.pkt_type = HFI_CMD_SYS_SET_PROPERTY;
	pkt->num_properties = 1;
	pkt->data[0] = HFI_PROPERTY_SYS_CONFIG_COVERAGE;
	pkt->data[1] = mode;
}

int pkt_sys_set_resource(struct hfi_sys_set_resource_pkt *pkt, u32 id, u32 size,
			 u32 addr, void *cookie)
{
	pkt->hdr.size = sizeof(*pkt);
	pkt->hdr.pkt_type = HFI_CMD_SYS_SET_RESOURCE;
	pkt->resource_handle = hash32_ptr(cookie);

	switch (id) {
	case VIDC_RESOURCE_OCMEM:
	case VIDC_RESOURCE_VMEM: {
		struct hfi_resource_ocmem *res =
			(struct hfi_resource_ocmem *)&pkt->resource_data[0];

		res->size = size;
		res->mem = addr;
		pkt->resource_type = HFI_RESOURCE_OCMEM;
		pkt->hdr.size += sizeof(*res) - sizeof(u32);
		break;
	}
	case VIDC_RESOURCE_NONE:
	default:
		return -ENOTSUPP;
	}

	return 0;
}

int pkt_sys_unset_resource(struct hfi_sys_release_resource_pkt *pkt, u32 id,
			   u32 size, void *cookie)
{
	pkt->hdr.size = sizeof(*pkt);
	pkt->hdr.pkt_type = HFI_CMD_SYS_RELEASE_RESOURCE;
	pkt->resource_handle = hash32_ptr(cookie);

	switch (id) {
	case VIDC_RESOURCE_OCMEM:
	case VIDC_RESOURCE_VMEM:
		pkt->resource_type = HFI_RESOURCE_OCMEM;
		break;
	case VIDC_RESOURCE_NONE:
		break;
	default:
		return -ENOTSUPP;
	}

	return 0;
}

void pkt_sys_ping(struct hfi_sys_ping_pkt *pkt, u32 cookie)
{
	pkt->hdr.size = sizeof(*pkt);
	pkt->hdr.pkt_type = HFI_CMD_SYS_PING;
	pkt->client_data = cookie;
}

void pkt_sys_power_control(struct hfi_sys_set_property_pkt *pkt, u32 enable)
{
	struct hfi_enable *hfi = (struct hfi_enable *)&pkt->data[1];

	pkt->hdr.size = sizeof(*pkt) + sizeof(*hfi) + sizeof(u32);
	pkt->hdr.pkt_type = HFI_CMD_SYS_SET_PROPERTY;
	pkt->num_properties = 1;
	pkt->data[0] = HFI_PROPERTY_SYS_CODEC_POWER_PLANE_CTRL;
	hfi->enable = enable;
}

int pkt_sys_ssr_cmd(struct hfi_sys_test_ssr_pkt *pkt, u32 trigger_type)
{
	switch (trigger_type) {
	case HFI_TEST_SSR_SW_ERR_FATAL:
	case HFI_TEST_SSR_SW_DIV_BY_ZERO:
	case HFI_TEST_SSR_HW_WDOG_IRQ:
		break;
	default:
		return -EINVAL;
	}

	pkt->hdr.size = sizeof(*pkt);
	pkt->hdr.pkt_type = HFI_CMD_SYS_TEST_SSR;
	pkt->trigger_type = trigger_type;

	return 0;
}

void pkt_sys_image_version(struct hfi_sys_get_property_pkt *pkt)
{
	pkt->hdr.size = sizeof(*pkt);
	pkt->hdr.pkt_type = HFI_CMD_SYS_GET_PROPERTY;
	pkt->num_properties = 1;
	pkt->data[0] = HFI_PROPERTY_SYS_IMAGE_VERSION;
}

int pkt_session_init(struct hfi_session_init_pkt *pkt, void *cookie,
		     u32 session_type, u32 codec)
{
	if (!pkt || !cookie || !codec)
		return -EINVAL;

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SYS_SESSION_INIT;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->session_domain = session_type;
	pkt->session_codec = codec;

	return 0;
}

void pkt_session_cmd(struct hfi_session_pkt *pkt, u32 pkt_type, void *cookie)
{
	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = pkt_type;
	pkt->shdr.session_id = hash32_ptr(cookie);
}

int pkt_session_set_buffers(struct hfi_session_set_buffers_pkt *pkt,
			    void *cookie, struct hfi_buffer_desc *bd)
{
	unsigned int i;

	if (!cookie || !pkt || !bd)
		return -EINVAL;

	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_SET_BUFFERS;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->buffer_size = bd->buffer_size;
	pkt->min_buffer_size = bd->buffer_size;
	pkt->num_buffers = bd->num_buffers;

	if (bd->buffer_type == HFI_BUFFER_OUTPUT ||
	    bd->buffer_type == HFI_BUFFER_OUTPUT2) {
		struct hfi_buffer_info *bi;

		pkt->extradata_size = bd->extradata_size;
		pkt->shdr.hdr.size = sizeof(*pkt) - sizeof(u32) +
			(bd->num_buffers * sizeof(*bi));
		bi = (struct hfi_buffer_info *)pkt->buffer_info;
		for (i = 0; i < pkt->num_buffers; i++) {
			bi->buffer_addr = bd->device_addr;
			bi->extradata_addr = bd->extradata_addr;
		}
	} else {
		pkt->extradata_size = 0;
		pkt->shdr.hdr.size = sizeof(*pkt) +
			((bd->num_buffers - 1) * sizeof(u32));
		for (i = 0; i < pkt->num_buffers; i++)
			pkt->buffer_info[i] = bd->device_addr;
	}

	pkt->buffer_type = bd->buffer_type;

	return 0;
}

int pkt_session_unset_buffers(struct hfi_session_release_buffer_pkt *pkt,
			      void *cookie, struct hfi_buffer_desc *bd)
{
	unsigned int i;

	if (!cookie || !pkt || !bd)
		return -EINVAL;

	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_RELEASE_BUFFERS;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->buffer_size = bd->buffer_size;
	pkt->num_buffers = bd->num_buffers;

	if (bd->buffer_type == HFI_BUFFER_OUTPUT ||
	    bd->buffer_type == HFI_BUFFER_OUTPUT2) {
		struct hfi_buffer_info *bi;

		bi = (struct hfi_buffer_info *)pkt->buffer_info;
		for (i = 0; i < pkt->num_buffers; i++) {
			bi->buffer_addr = bd->device_addr;
			bi->extradata_addr = bd->extradata_addr;
		}
		pkt->shdr.hdr.size =
				sizeof(struct hfi_session_set_buffers_pkt) -
				sizeof(u32) + (bd->num_buffers * sizeof(*bi));
	} else {
		for (i = 0; i < pkt->num_buffers; i++)
			pkt->buffer_info[i] = bd->device_addr;

		pkt->extradata_size = 0;
		pkt->shdr.hdr.size =
				sizeof(struct hfi_session_set_buffers_pkt) +
				((bd->num_buffers - 1) * sizeof(u32));
	}

	pkt->response_req = bd->response_required;
	pkt->buffer_type = bd->buffer_type;

	return 0;
}

int pkt_session_etb_decoder(struct hfi_session_empty_buffer_compressed_pkt *pkt,
			    void *cookie, struct hfi_frame_data *in_frame)
{
	if (!cookie || !in_frame->device_addr)
		return -EINVAL;

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_EMPTY_BUFFER;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->time_stamp_hi = upper_32_bits(in_frame->timestamp);
	pkt->time_stamp_lo = lower_32_bits(in_frame->timestamp);
	pkt->flags = in_frame->flags;
	pkt->mark_target = in_frame->mark_target;
	pkt->mark_data = in_frame->mark_data;
	pkt->offset = in_frame->offset;
	pkt->alloc_len = in_frame->alloc_len;
	pkt->filled_len = in_frame->filled_len;
	pkt->input_tag = in_frame->clnt_data;
	pkt->packet_buffer = in_frame->device_addr;

	return 0;
}

int pkt_session_etb_encoder(
		struct hfi_session_empty_buffer_uncompressed_plane0_pkt *pkt,
		void *cookie, struct hfi_frame_data *in_frame)
{
	if (!cookie || !in_frame->device_addr)
		return -EINVAL;

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_EMPTY_BUFFER;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->view_id = 0;
	pkt->time_stamp_hi = upper_32_bits(in_frame->timestamp);
	pkt->time_stamp_lo = lower_32_bits(in_frame->timestamp);
	pkt->flags = in_frame->flags;
	pkt->mark_target = in_frame->mark_target;
	pkt->mark_data = in_frame->mark_data;
	pkt->offset = in_frame->offset;
	pkt->alloc_len = in_frame->alloc_len;
	pkt->filled_len = in_frame->filled_len;
	pkt->input_tag = in_frame->clnt_data;
	pkt->packet_buffer = in_frame->device_addr;
	pkt->extradata_buffer = in_frame->extradata_addr;

	return 0;
}

int pkt_session_ftb(struct hfi_session_fill_buffer_pkt *pkt, void *cookie,
		    struct hfi_frame_data *out_frame)
{
	if (!cookie || !out_frame || !out_frame->device_addr)
		return -EINVAL;

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_FILL_BUFFER;
	pkt->shdr.session_id = hash32_ptr(cookie);

	if (out_frame->buffer_type == HFI_BUFFER_OUTPUT)
		pkt->stream_id = 0;
	else if (out_frame->buffer_type == HFI_BUFFER_OUTPUT2)
		pkt->stream_id = 1;

	pkt->output_tag = out_frame->clnt_data;
	pkt->packet_buffer = out_frame->device_addr;
	pkt->extradata_buffer = out_frame->extradata_addr;
	pkt->alloc_len = out_frame->alloc_len;
	pkt->filled_len = out_frame->filled_len;
	pkt->offset = out_frame->offset;
	pkt->data[0] = out_frame->extradata_size;

	return 0;
}

int pkt_session_parse_seq_header(
		struct hfi_session_parse_sequence_header_pkt *pkt,
		void *cookie, u32 seq_hdr, u32 seq_hdr_len)
{
	if (!cookie || !seq_hdr || !seq_hdr_len)
		return -EINVAL;

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_PARSE_SEQUENCE_HEADER;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->header_len = seq_hdr_len;
	pkt->packet_buffer = seq_hdr;

	return 0;
}

int pkt_session_get_seq_hdr(struct hfi_session_get_sequence_header_pkt *pkt,
			    void *cookie, u32 seq_hdr, u32 seq_hdr_len)
{
	if (!cookie || !seq_hdr || !seq_hdr_len)
		return -EINVAL;

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_GET_SEQUENCE_HEADER;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->buffer_len = seq_hdr_len;
	pkt->packet_buffer = seq_hdr;

	return 0;
}

int pkt_session_flush(struct hfi_session_flush_pkt *pkt, void *cookie, u32 type)
{
	switch (type) {
	case HFI_FLUSH_INPUT:
	case HFI_FLUSH_OUTPUT:
	case HFI_FLUSH_OUTPUT2:
	case HFI_FLUSH_ALL:
		break;
	default:
		return -EINVAL;
	}

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_FLUSH;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->flush_type = type;

	return 0;
}

__attribute__((used)) static int pkt_session_get_property_1x(struct hfi_session_get_property_pkt *pkt,
				       void *cookie, u32 ptype)
{
	switch (ptype) {
	case HFI_PROPERTY_PARAM_PROFILE_LEVEL_CURRENT:
	case HFI_PROPERTY_CONFIG_BUFFER_REQUIREMENTS:
		break;
	default:
		return -EINVAL;
	}

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_GET_PROPERTY;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->num_properties = 1;
	pkt->data[0] = ptype;

	return 0;
}

__attribute__((used)) static int pkt_session_set_property_1x(struct hfi_session_set_property_pkt *pkt,
				       void *cookie, u32 ptype, void *pdata)
{
	void *prop_data;
	int ret = 0;

	if (!pkt || !cookie || !pdata)
		return -EINVAL;

	prop_data = &pkt->data[1];

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_SET_PROPERTY;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->num_properties = 1;
	pkt->data[0] = ptype;

	switch (ptype) {
	case HFI_PROPERTY_CONFIG_FRAME_RATE: {
		struct hfi_framerate *in = pdata, *frate = prop_data;

		frate->buffer_type = in->buffer_type;
		frate->framerate = in->framerate;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*frate);
		break;
	}
	case HFI_PROPERTY_PARAM_UNCOMPRESSED_FORMAT_SELECT: {
		struct hfi_uncompressed_format_select *in = pdata;
		struct hfi_uncompressed_format_select *hfi = prop_data;

		hfi->buffer_type = in->buffer_type;
		hfi->format = in->format;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*hfi);
		break;
	}
	case HFI_PROPERTY_PARAM_FRAME_SIZE: {
		struct hfi_framesize *in = pdata, *fsize = prop_data;

		fsize->buffer_type = in->buffer_type;
		fsize->height = in->height;
		fsize->width = in->width;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*fsize);
		break;
	}
	case HFI_PROPERTY_CONFIG_REALTIME: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) * 2;
		break;
	}
	case HFI_PROPERTY_PARAM_BUFFER_COUNT_ACTUAL: {
		struct hfi_buffer_count_actual *in = pdata, *count = prop_data;

		count->count_actual = in->count_actual;
		count->type = in->type;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*count);
		break;
	}
	case HFI_PROPERTY_PARAM_BUFFER_SIZE_ACTUAL: {
		struct hfi_buffer_size_actual *in = pdata, *sz = prop_data;

		sz->size = in->size;
		sz->type = in->type;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*sz);
		break;
	}
	case HFI_PROPERTY_PARAM_BUFFER_DISPLAY_HOLD_COUNT_ACTUAL: {
		struct hfi_buffer_display_hold_count_actual *in = pdata;
		struct hfi_buffer_display_hold_count_actual *count = prop_data;

		count->hold_count = in->hold_count;
		count->type = in->type;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*count);
		break;
	}
	case HFI_PROPERTY_PARAM_NAL_STREAM_FORMAT_SELECT: {
		struct hfi_nal_stream_format_select *in = pdata;
		struct hfi_nal_stream_format_select *fmt = prop_data;

		fmt->format = in->format;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*fmt);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_OUTPUT_ORDER: {
		u32 *in = pdata;

		switch (*in) {
		case HFI_OUTPUT_ORDER_DECODE:
		case HFI_OUTPUT_ORDER_DISPLAY:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		pkt->data[1] = *in;
		pkt->shdr.hdr.size += sizeof(u32) * 2;
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_PICTURE_TYPE_DECODE: {
		struct hfi_enable_picture *in = pdata, *en = prop_data;

		en->picture_type = in->picture_type;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_OUTPUT2_KEEP_ASPECT_RATIO: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_CONFIG_VDEC_POST_LOOP_DEBLOCKER: {
		struct hfi_enable *in = pdata;
		struct hfi_enable *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_MULTI_STREAM: {
		struct hfi_multi_stream *in = pdata, *multi = prop_data;

		multi->buffer_type = in->buffer_type;
		multi->enable = in->enable;
		multi->width = in->width;
		multi->height = in->height;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*multi);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_DISPLAY_PICTURE_BUFFER_COUNT: {
		struct hfi_display_picture_buffer_count *in = pdata;
		struct hfi_display_picture_buffer_count *count = prop_data;

		count->count = in->count;
		count->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*count);
		break;
	}
	case HFI_PROPERTY_PARAM_DIVX_FORMAT: {
		u32 *in = pdata;

		switch (*in) {
		case HFI_DIVX_FORMAT_4:
		case HFI_DIVX_FORMAT_5:
		case HFI_DIVX_FORMAT_6:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		pkt->data[1] = *in;
		pkt->shdr.hdr.size += sizeof(u32) * 2;
		break;
	}
	case HFI_PROPERTY_CONFIG_VDEC_MB_ERROR_MAP_REPORTING: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_CONTINUE_DATA_TRANSFER: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_THUMBNAIL_MODE: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_SYNC_FRAME_SEQUENCE_HEADER: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_REQUEST_SYNC_FRAME:
		pkt->shdr.hdr.size += sizeof(u32);
		break;
	case HFI_PROPERTY_PARAM_VENC_MPEG4_SHORT_HEADER:
		break;
	case HFI_PROPERTY_PARAM_VENC_MPEG4_AC_PREDICTION:
		break;
	case HFI_PROPERTY_CONFIG_VENC_TARGET_BITRATE: {
		struct hfi_bitrate *in = pdata, *brate = prop_data;

		brate->bitrate = in->bitrate;
		brate->layer_id = in->layer_id;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*brate);
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_MAX_BITRATE: {
		struct hfi_bitrate *in = pdata, *hfi = prop_data;

		hfi->bitrate = in->bitrate;
		hfi->layer_id = in->layer_id;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*hfi);
		break;
	}
	case HFI_PROPERTY_PARAM_PROFILE_LEVEL_CURRENT: {
		struct hfi_profile_level *in = pdata, *pl = prop_data;

		pl->level = in->level;
		pl->profile = in->profile;
		if (pl->profile <= 0)
			/* Profile not supported, falling back to high */
			pl->profile = HFI_H264_PROFILE_HIGH;

		if (!pl->level)
			/* Level not supported, falling back to 1 */
			pl->level = 1;

		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*pl);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_H264_ENTROPY_CONTROL: {
		struct hfi_h264_entropy_control *in = pdata, *hfi = prop_data;

		hfi->entropy_mode = in->entropy_mode;
		if (hfi->entropy_mode == HFI_H264_ENTROPY_CABAC)
			hfi->cabac_model = in->cabac_model;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*hfi);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_RATE_CONTROL: {
		u32 *in = pdata;

		switch (*in) {
		case HFI_RATE_CONTROL_OFF:
		case HFI_RATE_CONTROL_CBR_CFR:
		case HFI_RATE_CONTROL_CBR_VFR:
		case HFI_RATE_CONTROL_VBR_CFR:
		case HFI_RATE_CONTROL_VBR_VFR:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		pkt->data[1] = *in;
		pkt->shdr.hdr.size += sizeof(u32) * 2;
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_MPEG4_TIME_RESOLUTION: {
		struct hfi_mpeg4_time_resolution *in = pdata, *res = prop_data;

		res->time_increment_resolution = in->time_increment_resolution;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*res);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_MPEG4_HEADER_EXTENSION: {
		struct hfi_mpeg4_header_extension *in = pdata, *ext = prop_data;

		ext->header_extension = in->header_extension;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*ext);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_H264_DEBLOCK_CONTROL: {
		struct hfi_h264_db_control *in = pdata, *db = prop_data;

		switch (in->mode) {
		case HFI_H264_DB_MODE_DISABLE:
		case HFI_H264_DB_MODE_SKIP_SLICE_BOUNDARY:
		case HFI_H264_DB_MODE_ALL_BOUNDARY:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		db->mode = in->mode;
		db->slice_alpha_offset = in->slice_alpha_offset;
		db->slice_beta_offset = in->slice_beta_offset;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*db);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_SESSION_QP: {
		struct hfi_quantization *in = pdata, *quant = prop_data;

		quant->qp_i = in->qp_i;
		quant->qp_p = in->qp_p;
		quant->qp_b = in->qp_b;
		quant->layer_id = in->layer_id;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*quant);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_SESSION_QP_RANGE: {
		struct hfi_quantization_range *in = pdata, *range = prop_data;
		u32 min_qp, max_qp;

		min_qp = in->min_qp;
		max_qp = in->max_qp;

		/* We'll be packing in the qp, so make sure we
		 * won't be losing data when masking
		 */
		if (min_qp > 0xff || max_qp > 0xff) {
			ret = -ERANGE;
			break;
		}

		/* When creating the packet, pack the qp value as
		 * 0xiippbb, where ii = qp range for I-frames,
		 * pp = qp range for P-frames, etc.
		 */
		range->min_qp = min_qp | min_qp << 8 | min_qp << 16;
		range->max_qp = max_qp | max_qp << 8 | max_qp << 16;
		range->layer_id = in->layer_id;

		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*range);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_VC1_PERF_CFG: {
		struct hfi_vc1e_perf_cfg_type *in = pdata, *perf = prop_data;

		memcpy(perf->search_range_x_subsampled,
		       in->search_range_x_subsampled,
		       sizeof(perf->search_range_x_subsampled));
		memcpy(perf->search_range_y_subsampled,
		       in->search_range_y_subsampled,
		       sizeof(perf->search_range_y_subsampled));

		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*perf);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_MAX_NUM_B_FRAMES: {
		struct hfi_max_num_b_frames *bframes = prop_data;
		u32 *in = pdata;

		bframes->max_num_b_frames = *in;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*bframes);
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_INTRA_PERIOD: {
		struct hfi_intra_period *in = pdata, *intra = prop_data;

		intra->pframes = in->pframes;
		intra->bframes = in->bframes;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*intra);
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_IDR_PERIOD: {
		struct hfi_idr_period *in = pdata, *idr = prop_data;

		idr->idr_period = in->idr_period;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*idr);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_CONCEAL_COLOR: {
		struct hfi_conceal_color *color = prop_data;
		u32 *in = pdata;

		color->conceal_color = *in;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*color);
		break;
	}
	case HFI_PROPERTY_CONFIG_VPE_OPERATIONS: {
		struct hfi_operations_type *in = pdata, *ops = prop_data;

		switch (in->rotation) {
		case HFI_ROTATE_NONE:
		case HFI_ROTATE_90:
		case HFI_ROTATE_180:
		case HFI_ROTATE_270:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		switch (in->flip) {
		case HFI_FLIP_NONE:
		case HFI_FLIP_HORIZONTAL:
		case HFI_FLIP_VERTICAL:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		ops->rotation = in->rotation;
		ops->flip = in->flip;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*ops);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_INTRA_REFRESH: {
		struct hfi_intra_refresh *in = pdata, *intra = prop_data;

		switch (in->mode) {
		case HFI_INTRA_REFRESH_NONE:
		case HFI_INTRA_REFRESH_ADAPTIVE:
		case HFI_INTRA_REFRESH_CYCLIC:
		case HFI_INTRA_REFRESH_CYCLIC_ADAPTIVE:
		case HFI_INTRA_REFRESH_RANDOM:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		intra->mode = in->mode;
		intra->air_mbs = in->air_mbs;
		intra->air_ref = in->air_ref;
		intra->cir_mbs = in->cir_mbs;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*intra);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_MULTI_SLICE_CONTROL: {
		struct hfi_multi_slice_control *in = pdata, *multi = prop_data;

		switch (in->multi_slice) {
		case HFI_MULTI_SLICE_OFF:
		case HFI_MULTI_SLICE_GOB:
		case HFI_MULTI_SLICE_BY_MB_COUNT:
		case HFI_MULTI_SLICE_BY_BYTE_COUNT:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		multi->multi_slice = in->multi_slice;
		multi->slice_size = in->slice_size;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*multi);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_SLICE_DELIVERY_MODE: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_H264_VUI_TIMING_INFO: {
		struct hfi_h264_vui_timing_info *in = pdata, *vui = prop_data;

		vui->enable = in->enable;
		vui->fixed_framerate = in->fixed_framerate;
		vui->time_scale = in->time_scale;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*vui);
		break;
	}
	case HFI_PROPERTY_CONFIG_VPE_DEINTERLACE: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_H264_GENERATE_AUDNAL: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_BUFFER_ALLOC_MODE: {
		struct hfi_buffer_alloc_mode *in = pdata, *mode = prop_data;

		mode->type = in->type;
		mode->mode = in->mode;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*mode);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_FRAME_ASSEMBLY: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_H264_VUI_BITSTREAM_RESTRC: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_PRESERVE_TEXT_QUALITY: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_SCS_THRESHOLD: {
		struct hfi_scs_threshold *thres = prop_data;
		u32 *in = pdata;

		thres->threshold_value = *in;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*thres);
		break;
	}
	case HFI_PROPERTY_PARAM_MVC_BUFFER_LAYOUT: {
		struct hfi_mvc_buffer_layout_descp_type *in = pdata;
		struct hfi_mvc_buffer_layout_descp_type *mvc = prop_data;

		switch (in->layout_type) {
		case HFI_MVC_BUFFER_LAYOUT_TOP_BOTTOM:
		case HFI_MVC_BUFFER_LAYOUT_SEQ:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		mvc->layout_type = in->layout_type;
		mvc->bright_view_first = in->bright_view_first;
		mvc->ngap = in->ngap;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*mvc);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_LTRMODE: {
		struct hfi_ltr_mode *in = pdata, *ltr = prop_data;

		switch (in->ltr_mode) {
		case HFI_LTR_MODE_DISABLE:
		case HFI_LTR_MODE_MANUAL:
		case HFI_LTR_MODE_PERIODIC:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		ltr->ltr_mode = in->ltr_mode;
		ltr->ltr_count = in->ltr_count;
		ltr->trust_mode = in->trust_mode;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*ltr);
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_USELTRFRAME: {
		struct hfi_ltr_use *in = pdata, *ltr_use = prop_data;

		ltr_use->frames = in->frames;
		ltr_use->ref_ltr = in->ref_ltr;
		ltr_use->use_constrnt = in->use_constrnt;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*ltr_use);
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_MARKLTRFRAME: {
		struct hfi_ltr_mark *in = pdata, *ltr_mark = prop_data;

		ltr_mark->mark_frame = in->mark_frame;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*ltr_mark);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_HIER_P_MAX_NUM_ENH_LAYER: {
		u32 *in = pdata;

		pkt->data[1] = *in;
		pkt->shdr.hdr.size += sizeof(u32) * 2;
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_HIER_P_ENH_LAYER: {
		u32 *in = pdata;

		pkt->data[1] = *in;
		pkt->shdr.hdr.size += sizeof(u32) * 2;
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_DISABLE_RC_TIMESTAMP: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_INITIAL_QP: {
		struct hfi_initial_quantization *in = pdata, *quant = prop_data;

		quant->init_qp_enable = in->init_qp_enable;
		quant->qp_i = in->qp_i;
		quant->qp_p = in->qp_p;
		quant->qp_b = in->qp_b;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*quant);
		break;
	}
	case HFI_PROPERTY_PARAM_VPE_COLOR_SPACE_CONVERSION: {
		struct hfi_vpe_color_space_conversion *in = pdata;
		struct hfi_vpe_color_space_conversion *csc = prop_data;

		memcpy(csc->csc_matrix, in->csc_matrix,
		       sizeof(csc->csc_matrix));
		memcpy(csc->csc_bias, in->csc_bias, sizeof(csc->csc_bias));
		memcpy(csc->csc_limit, in->csc_limit, sizeof(csc->csc_limit));
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*csc);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_VPX_ERROR_RESILIENCE_MODE: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_H264_NAL_SVC_EXT: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_PERF_MODE: {
		u32 *in = pdata;

		pkt->data[1] = *in;
		pkt->shdr.hdr.size += sizeof(u32) * 2;
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_HIER_B_MAX_NUM_ENH_LAYER: {
		u32 *in = pdata;

		pkt->data[1] = *in;
		pkt->shdr.hdr.size += sizeof(u32) * 2;
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_NONCP_OUTPUT2: {
		struct hfi_enable *in = pdata, *en = prop_data;

		en->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*en);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_HIER_P_HYBRID_MODE: {
		struct hfi_hybrid_hierp *in = pdata, *hierp = prop_data;

		hierp->layers = in->layers;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*hierp);
		break;
	}

	/* FOLLOWING PROPERTIES ARE NOT IMPLEMENTED IN CORE YET */
	case HFI_PROPERTY_CONFIG_BUFFER_REQUIREMENTS:
	case HFI_PROPERTY_CONFIG_PRIORITY:
	case HFI_PROPERTY_CONFIG_BATCH_INFO:
	case HFI_PROPERTY_SYS_IDLE_INDICATOR:
	case HFI_PROPERTY_PARAM_UNCOMPRESSED_FORMAT_SUPPORTED:
	case HFI_PROPERTY_PARAM_INTERLACE_FORMAT_SUPPORTED:
	case HFI_PROPERTY_PARAM_CHROMA_SITE:
	case HFI_PROPERTY_PARAM_PROPERTIES_SUPPORTED:
	case HFI_PROPERTY_PARAM_PROFILE_LEVEL_SUPPORTED:
	case HFI_PROPERTY_PARAM_CAPABILITY_SUPPORTED:
	case HFI_PROPERTY_PARAM_NAL_STREAM_FORMAT_SUPPORTED:
	case HFI_PROPERTY_PARAM_MULTI_VIEW_FORMAT:
	case HFI_PROPERTY_PARAM_MAX_SEQUENCE_HEADER_SIZE:
	case HFI_PROPERTY_PARAM_CODEC_SUPPORTED:
	case HFI_PROPERTY_PARAM_VDEC_MULTI_VIEW_SELECT:
	case HFI_PROPERTY_PARAM_VDEC_MB_QUANTIZATION:
	case HFI_PROPERTY_PARAM_VDEC_NUM_CONCEALED_MB:
	case HFI_PROPERTY_PARAM_VDEC_H264_ENTROPY_SWITCHING:
	case HFI_PROPERTY_PARAM_VENC_MULTI_SLICE_INFO:
	default:
		return -EINVAL;
	}

	return ret;
}

__attribute__((used)) static int
pkt_session_get_property_3xx(struct hfi_session_get_property_pkt *pkt,
			     void *cookie, u32 ptype)
{
	int ret = 0;

	if (!pkt || !cookie)
		return -EINVAL;

	pkt->shdr.hdr.size = sizeof(struct hfi_session_get_property_pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_GET_PROPERTY;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->num_properties = 1;

	switch (ptype) {
	case HFI_PROPERTY_CONFIG_VDEC_ENTROPY:
		pkt->data[0] = HFI_PROPERTY_CONFIG_VDEC_ENTROPY;
		break;
	default:
		ret = pkt_session_get_property_1x(pkt, cookie, ptype);
		break;
	}

	return ret;
}

__attribute__((used)) static int
pkt_session_set_property_3xx(struct hfi_session_set_property_pkt *pkt,
			     void *cookie, u32 ptype, void *pdata)
{
	void *prop_data;
	int ret = 0;

	if (!pkt || !cookie || !pdata)
		return -EINVAL;

	prop_data = &pkt->data[1];

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_SET_PROPERTY;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->num_properties = 1;
	pkt->data[0] = ptype;

	/*
	 * Any session set property which is different in 3XX packetization
	 * should be added as a new case below. All unchanged session set
	 * properties will be handled in the default case.
	 */
	switch (ptype) {
	case HFI_PROPERTY_PARAM_VDEC_MULTI_STREAM: {
		struct hfi_multi_stream *in = pdata;
		struct hfi_multi_stream_3x *multi = prop_data;

		multi->buffer_type = in->buffer_type;
		multi->enable = in->enable;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*multi);
		break;
	}
	case HFI_PROPERTY_PARAM_VENC_INTRA_REFRESH: {
		struct hfi_intra_refresh *in = pdata;
		struct hfi_intra_refresh_3x *intra = prop_data;

		switch (in->mode) {
		case HFI_INTRA_REFRESH_NONE:
		case HFI_INTRA_REFRESH_ADAPTIVE:
		case HFI_INTRA_REFRESH_CYCLIC:
		case HFI_INTRA_REFRESH_CYCLIC_ADAPTIVE:
		case HFI_INTRA_REFRESH_RANDOM:
			break;
		default:
			ret = -EINVAL;
			break;
		}

		intra->mode = in->mode;
		intra->mbs = in->cir_mbs;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*intra);
		break;
	}
	case HFI_PROPERTY_PARAM_VDEC_CONTINUE_DATA_TRANSFER:
		/* for 3xx fw version session_continue is used */
		break;
	default:
		ret = pkt_session_set_property_1x(pkt, cookie, ptype, pdata);
		break;
	}

	return ret;
}

__attribute__((used)) static int
pkt_session_set_property_4xx(struct hfi_session_set_property_pkt *pkt,
			     void *cookie, u32 ptype, void *pdata)
{
	void *prop_data;

	if (!pkt || !cookie || !pdata)
		return -EINVAL;

	prop_data = &pkt->data[1];

	pkt->shdr.hdr.size = sizeof(*pkt);
	pkt->shdr.hdr.pkt_type = HFI_CMD_SESSION_SET_PROPERTY;
	pkt->shdr.session_id = hash32_ptr(cookie);
	pkt->num_properties = 1;
	pkt->data[0] = ptype;

	/*
	 * Any session set property which is different in 3XX packetization
	 * should be added as a new case below. All unchanged session set
	 * properties will be handled in the default case.
	 */
	switch (ptype) {
	case HFI_PROPERTY_PARAM_BUFFER_COUNT_ACTUAL: {
		struct hfi_buffer_count_actual *in = pdata;
		struct hfi_buffer_count_actual_4xx *count = prop_data;

		count->count_actual = in->count_actual;
		count->type = in->type;
		count->count_min_host = in->count_actual;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*count);
		break;
	}
	case HFI_PROPERTY_PARAM_WORK_MODE: {
		struct hfi_video_work_mode *in = pdata, *wm = prop_data;

		wm->video_work_mode = in->video_work_mode;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*wm);
		break;
	}
	case HFI_PROPERTY_CONFIG_VIDEOCORES_USAGE: {
		struct hfi_videocores_usage_type *in = pdata, *cu = prop_data;

		cu->video_core_enable_mask = in->video_core_enable_mask;
		pkt->shdr.hdr.size += sizeof(u32) + sizeof(*cu);
		break;
	}
	case HFI_PROPERTY_CONFIG_VENC_MAX_BITRATE:
		/* not implemented on Venus 4xx */
		break;
	default:
		return pkt_session_set_property_3xx(pkt, cookie, ptype, pdata);
	}

	return 0;
}

int pkt_session_get_property(struct hfi_session_get_property_pkt *pkt,
			     void *cookie, u32 ptype)
{
	if (hfi_ver == HFI_VERSION_1XX)
		return pkt_session_get_property_1x(pkt, cookie, ptype);

	return pkt_session_get_property_3xx(pkt, cookie, ptype);
}

int pkt_session_set_property(struct hfi_session_set_property_pkt *pkt,
			     void *cookie, u32 ptype, void *pdata)
{
	if (hfi_ver == HFI_VERSION_1XX)
		return pkt_session_set_property_1x(pkt, cookie, ptype, pdata);

	if (hfi_ver == HFI_VERSION_3XX)
		return pkt_session_set_property_3xx(pkt, cookie, ptype, pdata);

	return pkt_session_set_property_4xx(pkt, cookie, ptype, pdata);
}

void pkt_set_version(enum hfi_version version)
{
	hfi_ver = version;
}

