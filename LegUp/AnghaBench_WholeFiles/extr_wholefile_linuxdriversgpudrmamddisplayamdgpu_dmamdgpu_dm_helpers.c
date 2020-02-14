#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_45__   TYPE_9__ ;
typedef  struct TYPE_44__   TYPE_8__ ;
typedef  struct TYPE_43__   TYPE_7__ ;
typedef  struct TYPE_42__   TYPE_6__ ;
typedef  struct TYPE_41__   TYPE_5__ ;
typedef  struct TYPE_40__   TYPE_4__ ;
typedef  struct TYPE_39__   TYPE_3__ ;
typedef  struct TYPE_38__   TYPE_2__ ;
typedef  struct TYPE_37__   TYPE_22__ ;
typedef  struct TYPE_36__   TYPE_21__ ;
typedef  struct TYPE_35__   TYPE_20__ ;
typedef  struct TYPE_34__   TYPE_1__ ;
typedef  struct TYPE_33__   TYPE_19__ ;
typedef  struct TYPE_32__   TYPE_18__ ;
typedef  struct TYPE_31__   TYPE_17__ ;
typedef  struct TYPE_30__   TYPE_16__ ;
typedef  struct TYPE_29__   TYPE_15__ ;
typedef  struct TYPE_28__   TYPE_14__ ;
typedef  struct TYPE_27__   TYPE_13__ ;
typedef  struct TYPE_26__   TYPE_12__ ;
typedef  struct TYPE_25__   TYPE_11__ ;
typedef  struct TYPE_24__   TYPE_10__ ;

/* Type definitions */
struct i2c_msg {int extensions; int /*<<< orphan*/  buf; int /*<<< orphan*/  len; int /*<<< orphan*/  addr; int /*<<< orphan*/  flags; int /*<<< orphan*/  byte2; int /*<<< orphan*/  freq; scalar_t__ channels; int /*<<< orphan*/  format; TYPE_5__* detailed_timings; int /*<<< orphan*/  mfg_year; int /*<<< orphan*/  mfg_week; int /*<<< orphan*/  serial; scalar_t__* prod_code; scalar_t__* mfg_id; } ;
struct TYPE_33__ {int EDID_CHECKSUM_WRITE; } ;
struct TYPE_31__ {int /*<<< orphan*/  member_0; } ;
union test_response {struct i2c_msg raw; TYPE_19__ bits; TYPE_17__ member_0; } ;
struct TYPE_32__ {int /*<<< orphan*/  EDID_READ; } ;
struct TYPE_30__ {int /*<<< orphan*/  member_0; } ;
union test_request {TYPE_18__ bits; struct i2c_msg raw; TYPE_16__ member_0; } ;
typedef  struct i2c_msg uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  test_response ;
struct i2c_command {int number_of_payloads; TYPE_13__* payloads; } ;
struct i2c_adapter {int dummy; } ;
struct edid {int extensions; int /*<<< orphan*/  buf; int /*<<< orphan*/  len; int /*<<< orphan*/  addr; int /*<<< orphan*/  flags; int /*<<< orphan*/  byte2; int /*<<< orphan*/  freq; scalar_t__ channels; int /*<<< orphan*/  format; TYPE_5__* detailed_timings; int /*<<< orphan*/  mfg_year; int /*<<< orphan*/  mfg_week; int /*<<< orphan*/  serial; scalar_t__* prod_code; scalar_t__* mfg_id; } ;
struct drm_dp_mst_topology_mgr {int max_payloads; int /*<<< orphan*/  mst_state; int /*<<< orphan*/  payload_lock; TYPE_8__** proposed_vcpis; TYPE_7__* payloads; } ;
struct drm_dp_mst_port {int dummy; } ;
struct dp_mst_stream_allocation_table {size_t stream_count; struct dp_mst_stream_allocation* stream_allocations; } ;
struct dp_mst_stream_allocation {scalar_t__ slot_count; int /*<<< orphan*/  vcp_id; } ;
struct TYPE_45__ {int pix_clk_khz; int display_color_depth; } ;
struct dc_stream_state {TYPE_10__* sink; TYPE_9__ timing; } ;
struct dc_edid {int length; struct i2c_msg* raw_edid; } ;
struct dc_edid_caps {int manufacturer_id; int product_id; char* display_name; int audio_mode_count; struct i2c_msg speaker_flags; TYPE_6__* audio_modes; int /*<<< orphan*/  edid_hdmi; int /*<<< orphan*/  manufacture_year; int /*<<< orphan*/  manufacture_week; int /*<<< orphan*/  serial_number; } ;
struct dc_sink {struct dc_edid dc_edid; struct dc_edid_caps edid_caps; } ;
struct dc_link {scalar_t__ aux_mode; struct amdgpu_dm_connector* priv; } ;
struct dc_context {int dummy; } ;
struct dc_clocks {int dummy; } ;
struct cea_sad {int extensions; int /*<<< orphan*/  buf; int /*<<< orphan*/  len; int /*<<< orphan*/  addr; int /*<<< orphan*/  flags; int /*<<< orphan*/  byte2; int /*<<< orphan*/  freq; scalar_t__ channels; int /*<<< orphan*/  format; TYPE_5__* detailed_timings; int /*<<< orphan*/  mfg_year; int /*<<< orphan*/  mfg_week; int /*<<< orphan*/  serial; scalar_t__* prod_code; scalar_t__* mfg_id; } ;
struct TYPE_26__ {int /*<<< orphan*/  id; } ;
struct TYPE_35__ {int /*<<< orphan*/  name; TYPE_12__ base; } ;
struct TYPE_37__ {struct i2c_adapter ddc; int /*<<< orphan*/  hw_mutex; } ;
struct TYPE_28__ {TYPE_22__ aux; } ;
struct TYPE_36__ {int mst_state; } ;
struct amdgpu_dm_connector {TYPE_20__ base; TYPE_15__* i2c; TYPE_14__ dm_dp_aux; TYPE_21__ mst_mgr; TYPE_11__* mst_port; struct drm_dp_mst_port* port; } ;
typedef  enum dc_edid_status { ____Placeholder_dc_edid_status } dc_edid_status ;
struct TYPE_44__ {int /*<<< orphan*/  vcpi; } ;
struct TYPE_43__ {scalar_t__ num_slots; scalar_t__ payload_state; } ;
struct TYPE_42__ {int /*<<< orphan*/  sample_size; int /*<<< orphan*/  sample_rate; scalar_t__ channel_count; int /*<<< orphan*/  format_code; } ;
struct TYPE_34__ {char* str; } ;
struct TYPE_38__ {TYPE_1__ str; } ;
struct TYPE_39__ {int type; TYPE_2__ data; } ;
struct TYPE_40__ {TYPE_3__ other_data; } ;
struct TYPE_41__ {TYPE_4__ data; } ;
struct TYPE_29__ {struct i2c_adapter base; } ;
struct TYPE_27__ {int /*<<< orphan*/  data; int /*<<< orphan*/  length; int /*<<< orphan*/  address; scalar_t__ write; } ;
struct TYPE_25__ {struct drm_dp_mst_topology_mgr mst_mgr; } ;
struct TYPE_24__ {struct amdgpu_dm_connector* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  BUG_ON (char*) ; 
#define  COLOR_DEPTH_101010 133 
#define  COLOR_DEPTH_121212 132 
#define  COLOR_DEPTH_141414 131 
#define  COLOR_DEPTH_161616 130 
#define  COLOR_DEPTH_666 129 
#define  COLOR_DEPTH_888 128 
 int DC_MAX_AUDIO_DESC_COUNT ; 
 struct i2c_msg DEFAULT_SPEAKER_LOCATION ; 
 scalar_t__ DP_PAYLOAD_DELETE_LOCAL ; 
 scalar_t__ DP_PAYLOAD_LOCAL ; 
 scalar_t__ DP_PAYLOAD_REMOTE ; 
 int DP_TEST_EDID_CHECKSUM ; 
 int DP_TEST_REQUEST ; 
 int DP_TEST_RESPONSE ; 
 int /*<<< orphan*/  DRM_ERROR (char*,...) ; 
 int /*<<< orphan*/  DRM_INFO (char*,...) ; 
 int EDID_BAD_CHECKSUM ; 
 int EDID_BAD_INPUT ; 
 int EDID_LENGTH ; 
 int EDID_NO_RESPONSE ; 
 int EDID_OK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_M_RD ; 
 int dc_link_is_dp_sink_present (struct dc_link*) ; 
 int /*<<< orphan*/  drm_detect_hdmi_monitor (struct i2c_msg*) ; 
 int drm_dp_calc_pbn_mode (int,int) ; 
 int drm_dp_check_act_status (struct drm_dp_mst_topology_mgr*) ; 
 scalar_t__ drm_dp_dpcd_read (TYPE_22__*,int,struct i2c_msg*,int) ; 
 scalar_t__ drm_dp_dpcd_write (TYPE_22__*,int,struct i2c_msg*,int) ; 
 int drm_dp_find_vcpi_slots (struct drm_dp_mst_topology_mgr*,int) ; 
 int drm_dp_mst_allocate_vcpi (struct drm_dp_mst_topology_mgr*,struct drm_dp_mst_port*,int,int) ; 
 int /*<<< orphan*/  drm_dp_mst_deallocate_vcpi (struct drm_dp_mst_topology_mgr*,struct drm_dp_mst_port*) ; 
 int /*<<< orphan*/  drm_dp_mst_reset_vcpi_slots (struct drm_dp_mst_topology_mgr*,struct drm_dp_mst_port*) ; 
 scalar_t__ drm_dp_mst_topology_mgr_set_mst (TYPE_21__*,int) ; 
 int drm_dp_update_payload_part1 (struct drm_dp_mst_topology_mgr*) ; 
 int drm_dp_update_payload_part2 (struct drm_dp_mst_topology_mgr*) ; 
 int /*<<< orphan*/  drm_edid_is_valid (struct i2c_msg*) ; 
 int drm_edid_to_sad (struct i2c_msg*,struct i2c_msg**) ; 
 int drm_edid_to_speaker_allocation (struct i2c_msg*,struct i2c_msg**) ; 
 struct i2c_msg* drm_get_edid (TYPE_20__*,struct i2c_adapter*) ; 
 int i2c_transfer (struct i2c_adapter*,struct i2c_msg*,int) ; 
 struct i2c_msg* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct i2c_msg*) ; 
 int /*<<< orphan*/  memmove (struct i2c_msg*,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

enum dc_edid_status dm_helpers_parse_edid_caps(
		struct dc_context *ctx,
		const struct dc_edid *edid,
		struct dc_edid_caps *edid_caps)
{
	struct edid *edid_buf = (struct edid *) edid->raw_edid;
	struct cea_sad *sads;
	int sad_count = -1;
	int sadb_count = -1;
	int i = 0;
	int j = 0;
	uint8_t *sadb = NULL;

	enum dc_edid_status result = EDID_OK;

	if (!edid_caps || !edid)
		return EDID_BAD_INPUT;

	if (!drm_edid_is_valid(edid_buf))
		result = EDID_BAD_CHECKSUM;

	edid_caps->manufacturer_id = (uint16_t) edid_buf->mfg_id[0] |
					((uint16_t) edid_buf->mfg_id[1])<<8;
	edid_caps->product_id = (uint16_t) edid_buf->prod_code[0] |
					((uint16_t) edid_buf->prod_code[1])<<8;
	edid_caps->serial_number = edid_buf->serial;
	edid_caps->manufacture_week = edid_buf->mfg_week;
	edid_caps->manufacture_year = edid_buf->mfg_year;

	/* One of the four detailed_timings stores the monitor name. It's
	 * stored in an array of length 13. */
	for (i = 0; i < 4; i++) {
		if (edid_buf->detailed_timings[i].data.other_data.type == 0xfc) {
			while (j < 13 && edid_buf->detailed_timings[i].data.other_data.data.str.str[j]) {
				if (edid_buf->detailed_timings[i].data.other_data.data.str.str[j] == '\n')
					break;

				edid_caps->display_name[j] =
					edid_buf->detailed_timings[i].data.other_data.data.str.str[j];
				j++;
			}
		}
	}

	edid_caps->edid_hdmi = drm_detect_hdmi_monitor(
			(struct edid *) edid->raw_edid);

	sad_count = drm_edid_to_sad((struct edid *) edid->raw_edid, &sads);
	if (sad_count <= 0) {
		DRM_INFO("SADs count is: %d, don't need to read it\n",
				sad_count);
		return result;
	}

	edid_caps->audio_mode_count = sad_count < DC_MAX_AUDIO_DESC_COUNT ? sad_count : DC_MAX_AUDIO_DESC_COUNT;
	for (i = 0; i < edid_caps->audio_mode_count; ++i) {
		struct cea_sad *sad = &sads[i];

		edid_caps->audio_modes[i].format_code = sad->format;
		edid_caps->audio_modes[i].channel_count = sad->channels + 1;
		edid_caps->audio_modes[i].sample_rate = sad->freq;
		edid_caps->audio_modes[i].sample_size = sad->byte2;
	}

	sadb_count = drm_edid_to_speaker_allocation((struct edid *) edid->raw_edid, &sadb);

	if (sadb_count < 0) {
		DRM_ERROR("Couldn't read Speaker Allocation Data Block: %d\n", sadb_count);
		sadb_count = 0;
	}

	if (sadb_count)
		edid_caps->speaker_flags = sadb[0];
	else
		edid_caps->speaker_flags = DEFAULT_SPEAKER_LOCATION;

	kfree(sads);
	kfree(sadb);

	return result;
}

__attribute__((used)) static void get_payload_table(
		struct amdgpu_dm_connector *aconnector,
		struct dp_mst_stream_allocation_table *proposed_table)
{
	int i;
	struct drm_dp_mst_topology_mgr *mst_mgr =
			&aconnector->mst_port->mst_mgr;

	mutex_lock(&mst_mgr->payload_lock);

	proposed_table->stream_count = 0;

	/* number of active streams */
	for (i = 0; i < mst_mgr->max_payloads; i++) {
		if (mst_mgr->payloads[i].num_slots == 0)
			break; /* end of vcp_id table */

		ASSERT(mst_mgr->payloads[i].payload_state !=
				DP_PAYLOAD_DELETE_LOCAL);

		if (mst_mgr->payloads[i].payload_state == DP_PAYLOAD_LOCAL ||
			mst_mgr->payloads[i].payload_state ==
					DP_PAYLOAD_REMOTE) {

			struct dp_mst_stream_allocation *sa =
					&proposed_table->stream_allocations[
						proposed_table->stream_count];

			sa->slot_count = mst_mgr->payloads[i].num_slots;
			sa->vcp_id = mst_mgr->proposed_vcpis[i]->vcpi;
			proposed_table->stream_count++;
		}
	}

	mutex_unlock(&mst_mgr->payload_lock);
}

void dm_helpers_dp_update_branch_info(
	struct dc_context *ctx,
	const struct dc_link *link)
{}

bool dm_helpers_dp_mst_write_payload_allocation_table(
		struct dc_context *ctx,
		const struct dc_stream_state *stream,
		struct dp_mst_stream_allocation_table *proposed_table,
		bool enable)
{
	struct amdgpu_dm_connector *aconnector;
	struct drm_dp_mst_topology_mgr *mst_mgr;
	struct drm_dp_mst_port *mst_port;
	int slots = 0;
	bool ret;
	int clock;
	int bpp = 0;
	int pbn = 0;

	aconnector = stream->sink->priv;

	if (!aconnector || !aconnector->mst_port)
		return false;

	mst_mgr = &aconnector->mst_port->mst_mgr;

	if (!mst_mgr->mst_state)
		return false;

	mst_port = aconnector->port;

	if (enable) {
		clock = stream->timing.pix_clk_khz;

		switch (stream->timing.display_color_depth) {

		case COLOR_DEPTH_666:
			bpp = 6;
			break;
		case COLOR_DEPTH_888:
			bpp = 8;
			break;
		case COLOR_DEPTH_101010:
			bpp = 10;
			break;
		case COLOR_DEPTH_121212:
			bpp = 12;
			break;
		case COLOR_DEPTH_141414:
			bpp = 14;
			break;
		case COLOR_DEPTH_161616:
			bpp = 16;
			break;
		default:
			ASSERT(bpp != 0);
			break;
		}

		bpp = bpp * 3;

		/* TODO need to know link rate */

		pbn = drm_dp_calc_pbn_mode(clock, bpp);

		slots = drm_dp_find_vcpi_slots(mst_mgr, pbn);
		ret = drm_dp_mst_allocate_vcpi(mst_mgr, mst_port, pbn, slots);

		if (!ret)
			return false;

	} else {
		drm_dp_mst_reset_vcpi_slots(mst_mgr, mst_port);
	}

	ret = drm_dp_update_payload_part1(mst_mgr);

	/* mst_mgr->->payloads are VC payload notify MST branch using DPCD or
	 * AUX message. The sequence is slot 1-63 allocated sequence for each
	 * stream. AMD ASIC stream slot allocation should follow the same
	 * sequence. copy DRM MST allocation to dc */

	get_payload_table(aconnector, proposed_table);

	if (ret)
		return false;

	return true;
}

void dm_helpers_dp_mst_clear_payload_allocation_table(
	struct dc_context *ctx,
	const struct dc_link *link)
{}

bool dm_helpers_dp_mst_poll_for_allocation_change_trigger(
		struct dc_context *ctx,
		const struct dc_stream_state *stream)
{
	struct amdgpu_dm_connector *aconnector;
	struct drm_dp_mst_topology_mgr *mst_mgr;
	int ret;

	aconnector = stream->sink->priv;

	if (!aconnector || !aconnector->mst_port)
		return false;

	mst_mgr = &aconnector->mst_port->mst_mgr;

	if (!mst_mgr->mst_state)
		return false;

	ret = drm_dp_check_act_status(mst_mgr);

	if (ret)
		return false;

	return true;
}

bool dm_helpers_dp_mst_send_payload_allocation(
		struct dc_context *ctx,
		const struct dc_stream_state *stream,
		bool enable)
{
	struct amdgpu_dm_connector *aconnector;
	struct drm_dp_mst_topology_mgr *mst_mgr;
	struct drm_dp_mst_port *mst_port;
	int ret;

	aconnector = stream->sink->priv;

	if (!aconnector || !aconnector->mst_port)
		return false;

	mst_port = aconnector->port;

	mst_mgr = &aconnector->mst_port->mst_mgr;

	if (!mst_mgr->mst_state)
		return false;

	ret = drm_dp_update_payload_part2(mst_mgr);

	if (ret)
		return false;

	if (!enable)
		drm_dp_mst_deallocate_vcpi(mst_mgr, mst_port);

	return true;
}

void dm_dtn_log_begin(struct dc_context *ctx)
{}

void dm_dtn_log_append_v(struct dc_context *ctx,
		const char *pMsg, ...)
{}

void dm_dtn_log_end(struct dc_context *ctx)
{}

bool dm_helpers_dp_mst_start_top_mgr(
		struct dc_context *ctx,
		const struct dc_link *link,
		bool boot)
{
	struct amdgpu_dm_connector *aconnector = link->priv;

	if (!aconnector) {
			DRM_ERROR("Failed to found connector for link!");
			return false;
	}

	if (boot) {
		DRM_INFO("DM_MST: Differing MST start on aconnector: %p [id: %d]\n",
					aconnector, aconnector->base.base.id);
		return true;
	}

	DRM_INFO("DM_MST: starting TM on aconnector: %p [id: %d]\n",
			aconnector, aconnector->base.base.id);

	return (drm_dp_mst_topology_mgr_set_mst(&aconnector->mst_mgr, true) == 0);
}

void dm_helpers_dp_mst_stop_top_mgr(
		struct dc_context *ctx,
		const struct dc_link *link)
{
	struct amdgpu_dm_connector *aconnector = link->priv;

	if (!aconnector) {
			DRM_ERROR("Failed to found connector for link!");
			return;
	}

	DRM_INFO("DM_MST: stopping TM on aconnector: %p [id: %d]\n",
			aconnector, aconnector->base.base.id);

	if (aconnector->mst_mgr.mst_state == true)
		drm_dp_mst_topology_mgr_set_mst(&aconnector->mst_mgr, false);
}

bool dm_helpers_dp_read_dpcd(
		struct dc_context *ctx,
		const struct dc_link *link,
		uint32_t address,
		uint8_t *data,
		uint32_t size)
{

	struct amdgpu_dm_connector *aconnector = link->priv;

	if (!aconnector) {
		DRM_ERROR("Failed to found connector for link!");
		return false;
	}

	return drm_dp_dpcd_read(&aconnector->dm_dp_aux.aux, address,
			data, size) > 0;
}

bool dm_helpers_dp_write_dpcd(
		struct dc_context *ctx,
		const struct dc_link *link,
		uint32_t address,
		const uint8_t *data,
		uint32_t size)
{
	struct amdgpu_dm_connector *aconnector = link->priv;

	if (!aconnector) {
		DRM_ERROR("Failed to found connector for link!");
		return false;
	}

	return drm_dp_dpcd_write(&aconnector->dm_dp_aux.aux,
			address, (uint8_t *)data, size) > 0;
}

bool dm_helpers_submit_i2c(
		struct dc_context *ctx,
		const struct dc_link *link,
		struct i2c_command *cmd)
{
	struct amdgpu_dm_connector *aconnector = link->priv;
	struct i2c_msg *msgs;
	int i = 0;
	int num = cmd->number_of_payloads;
	bool result;

	if (!aconnector) {
		DRM_ERROR("Failed to found connector for link!");
		return false;
	}

	msgs = kcalloc(num, sizeof(struct i2c_msg), GFP_KERNEL);

	if (!msgs)
		return false;

	for (i = 0; i < num; i++) {
		msgs[i].flags = cmd->payloads[i].write ? 0 : I2C_M_RD;
		msgs[i].addr = cmd->payloads[i].address;
		msgs[i].len = cmd->payloads[i].length;
		msgs[i].buf = cmd->payloads[i].data;
	}

	result = i2c_transfer(&aconnector->i2c->base, msgs, num) == num;

	kfree(msgs);

	return result;
}

bool dm_helpers_is_dp_sink_present(struct dc_link *link)
{
	bool dp_sink_present;
	struct amdgpu_dm_connector *aconnector = link->priv;

	if (!aconnector) {
		BUG_ON("Failed to found connector for link!");
		return true;
	}

	mutex_lock(&aconnector->dm_dp_aux.aux.hw_mutex);
	dp_sink_present = dc_link_is_dp_sink_present(link);
	mutex_unlock(&aconnector->dm_dp_aux.aux.hw_mutex);
	return dp_sink_present;
}

enum dc_edid_status dm_helpers_read_local_edid(
		struct dc_context *ctx,
		struct dc_link *link,
		struct dc_sink *sink)
{
	struct amdgpu_dm_connector *aconnector = link->priv;
	struct i2c_adapter *ddc;
	int retry = 3;
	enum dc_edid_status edid_status;
	struct edid *edid;

	if (link->aux_mode)
		ddc = &aconnector->dm_dp_aux.aux.ddc;
	else
		ddc = &aconnector->i2c->base;

	/* some dongles read edid incorrectly the first time,
	 * do check sum and retry to make sure read correct edid.
	 */
	do {

		edid = drm_get_edid(&aconnector->base, ddc);

		if (!edid)
			return EDID_NO_RESPONSE;

		sink->dc_edid.length = EDID_LENGTH * (edid->extensions + 1);
		memmove(sink->dc_edid.raw_edid, (uint8_t *)edid, sink->dc_edid.length);

		/* We don't need the original edid anymore */
		kfree(edid);

		edid_status = dm_helpers_parse_edid_caps(
						ctx,
						&sink->dc_edid,
						&sink->edid_caps);

	} while (edid_status == EDID_BAD_CHECKSUM && --retry > 0);

	if (edid_status != EDID_OK)
		DRM_ERROR("EDID err: %d, on connector: %s",
				edid_status,
				aconnector->base.name);
	if (link->aux_mode) {
		union test_request test_request = { {0} };
		union test_response test_response = { {0} };

		dm_helpers_dp_read_dpcd(ctx,
					link,
					DP_TEST_REQUEST,
					&test_request.raw,
					sizeof(union test_request));

		if (!test_request.bits.EDID_READ)
			return edid_status;

		test_response.bits.EDID_CHECKSUM_WRITE = 1;

		dm_helpers_dp_write_dpcd(ctx,
					link,
					DP_TEST_EDID_CHECKSUM,
					&sink->dc_edid.raw_edid[sink->dc_edid.length-1],
					1);

		dm_helpers_dp_write_dpcd(ctx,
					link,
					DP_TEST_RESPONSE,
					&test_response.raw,
					sizeof(test_response));

	}

	return edid_status;
}

void dm_set_dcn_clocks(struct dc_context *ctx, struct dc_clocks *clks)
{
	/* TODO: something */
}

