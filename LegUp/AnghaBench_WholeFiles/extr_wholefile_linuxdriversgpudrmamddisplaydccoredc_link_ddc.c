#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_9__ ;
typedef  struct TYPE_25__   TYPE_8__ ;
typedef  struct TYPE_24__   TYPE_7__ ;
typedef  struct TYPE_23__   TYPE_6__ ;
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;
typedef  struct TYPE_17__   TYPE_12__ ;
typedef  struct TYPE_16__   TYPE_11__ ;
typedef  struct TYPE_15__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  write_buffer ;
struct TYPE_16__ {int /*<<< orphan*/  member_0; } ;
union hdmi_scdc_status_flags_data {scalar_t__* byte; TYPE_11__ member_0; } ;
typedef  scalar_t__ uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  type2_dongle_buf ;
typedef  int /*<<< orphan*/  tmds_config ;
struct TYPE_21__ {scalar_t__ raw; } ;
struct TYPE_20__ {int EDID_QUERY_DONE_ONCE; int FORCE_READ_REPEATED_START; int EDID_STRESS_READ; int IS_INTERNAL_DISPLAY; } ;
struct TYPE_17__ {scalar_t__ count; scalar_t__ container; } ;
struct i2c_payloads {int transaction_type; int dongle_type; struct ddc* ddc_pin; struct dc_context* ctx; struct dc_link* link; TYPE_4__ wa; TYPE_3__ flags; TYPE_12__ payloads; } ;
struct i2c_payload {int write; scalar_t__ address; int length; scalar_t__* data; int i2c_over_aux; } ;
struct i2c_command {int number_of_payloads; int /*<<< orphan*/  speed; int /*<<< orphan*/  engine; struct i2c_payload* payloads; } ;
struct TYPE_19__ {int clk_a_shift; int /*<<< orphan*/  clk_a_register_index; } ;
struct graphics_object_i2c_info {TYPE_2__ gpio_info; int /*<<< orphan*/  i2c_hw_assist; int /*<<< orphan*/  i2c_line; } ;
struct gpio_service {int dummy; } ;
struct gpio_ddc_hw_info {int /*<<< orphan*/  hw_supported; int /*<<< orphan*/  ddc_channel; } ;
struct dp_hdmi_dongle_signature_data {scalar_t__ eot; scalar_t__* id; } ;
struct display_sink_capability {int dongle_type; int max_hdmi_pixel_clock; } ;
struct ddc_service_init_data {int /*<<< orphan*/  id; struct dc_context* ctx; struct dc_link* link; } ;
struct ddc_service {int transaction_type; int dongle_type; struct ddc* ddc_pin; struct dc_context* ctx; struct dc_link* link; TYPE_4__ wa; TYPE_3__ flags; TYPE_12__ payloads; } ;
struct ddc {TYPE_9__* pin_data; } ;
struct TYPE_22__ {scalar_t__ branch_dev_id; int /*<<< orphan*/  branch_dev_name; } ;
struct dc_link {TYPE_5__ dpcd_caps; } ;
struct dc_context {TYPE_8__* dc; int /*<<< orphan*/  i2caux; struct dc_bios* dc_bios; struct gpio_service* gpio_service; } ;
struct dc_bios {TYPE_1__* funcs; } ;
struct aux_request_transaction_data {int type; int action; unsigned int address; unsigned int length; void* data; scalar_t__ delay; } ;
struct aux_reply_transaction_data {int type; int action; unsigned int address; unsigned int length; void* data; scalar_t__ delay; } ;
struct aux_payloads {int transaction_type; int dongle_type; struct ddc* ddc_pin; struct dc_context* ctx; struct dc_link* link; TYPE_4__ wa; TYPE_3__ flags; TYPE_12__ payloads; } ;
struct aux_payload {int write; scalar_t__ address; int length; scalar_t__* data; int i2c_over_aux; } ;
struct aux_engine {TYPE_10__* funcs; } ;
struct aux_command {scalar_t__ number_of_payloads; int /*<<< orphan*/  max_defer_write_retry; scalar_t__ defer_delay; struct i2c_payload* payloads; } ;
typedef  int /*<<< orphan*/  sink_version ;
typedef  int /*<<< orphan*/  scramble_status ;
typedef  int /*<<< orphan*/  offset ;
typedef  enum i2caux_transaction_action { ____Placeholder_i2caux_transaction_action } i2caux_transaction_action ;
typedef  enum display_dongle_type { ____Placeholder_display_dongle_type } display_dongle_type ;
typedef  enum ddc_transaction_type { ____Placeholder_ddc_transaction_type } ddc_transaction_type ;
typedef  enum ddc_service_type { ____Placeholder_ddc_service_type } ddc_service_type ;
typedef  enum connector_id { ____Placeholder_connector_id } connector_id ;
typedef  enum aux_transaction_type { ____Placeholder_aux_transaction_type } aux_transaction_type ;
typedef  enum aux_channel_operation_result { ____Placeholder_aux_channel_operation_result } aux_channel_operation_result ;
typedef  int /*<<< orphan*/  aux_req ;
typedef  int /*<<< orphan*/  aux_rep ;
struct TYPE_26__ {size_t en; } ;
struct TYPE_23__ {int /*<<< orphan*/  i2c_speed_in_khz; } ;
struct TYPE_25__ {TYPE_7__* res_pool; TYPE_6__ caps; } ;
struct TYPE_24__ {struct aux_engine** engines; } ;
struct TYPE_18__ {scalar_t__ (* get_i2c_info ) (struct dc_bios*,int /*<<< orphan*/ ,struct graphics_object_i2c_info*) ;} ;
struct TYPE_15__ {int (* get_channel_status ) (struct aux_engine*,scalar_t__*) ;int (* read_channel_reply ) (struct aux_engine*,unsigned int,void*,scalar_t__*,scalar_t__*) ;int /*<<< orphan*/  (* release_engine ) (struct aux_engine*) ;int /*<<< orphan*/  (* submit_channel_request ) (struct aux_engine*,struct aux_request_transaction_data*) ;int /*<<< orphan*/  (* acquire ) (struct aux_engine*,struct ddc*) ;} ;

/* Variables and functions */
#define  AUX_CHANNEL_OPERATION_FAILED_HPD_DISCON 135 
#define  AUX_CHANNEL_OPERATION_FAILED_INVALID_REPLY 134 
#define  AUX_CHANNEL_OPERATION_FAILED_REASON_UNKNOWN 133 
#define  AUX_CHANNEL_OPERATION_FAILED_TIMEOUT 132 
#define  AUX_CHANNEL_OPERATION_SUCCEEDED 131 
 scalar_t__ BP_RESULT_OK ; 
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
 int CONNECTOR_ID_EDP ; 
 int CONNECTOR_ID_LVDS ; 
 int /*<<< orphan*/  CONN_DATA_DETECT (struct dc_link*,scalar_t__*,int,char*,int) ; 
 int /*<<< orphan*/  DDC_I2C_COMMAND_ENGINE ; 
 int DDC_MIN (scalar_t__,scalar_t__) ; 
 int DDC_SERVICE_TYPE_CONNECTOR ; 
#define  DDC_TRANSACTION_TYPE_I2C_OVER_AUX 130 
#define  DDC_TRANSACTION_TYPE_I2C_OVER_AUX_RETRY_DEFER 129 
#define  DDC_TRANSACTION_TYPE_I2C_OVER_AUX_WITH_DEFER 128 
 scalar_t__ DEFAULT_AUX_MAX_DATA_SIZE ; 
 int DISPLAY_DONGLE_DP_DVI_CONVERTER ; 
 int DISPLAY_DONGLE_DP_DVI_DONGLE ; 
 int DISPLAY_DONGLE_DP_HDMI_CONVERTER ; 
 int DISPLAY_DONGLE_DP_HDMI_DONGLE ; 
 int DISPLAY_DONGLE_DP_HDMI_MISMATCHED_DONGLE ; 
 int DISPLAY_DONGLE_DP_VGA_CONVERTER ; 
 int DISPLAY_DONGLE_NONE ; 
 int DP_ADAPTOR_DVI_MAX_TMDS_CLK ; 
 int DP_ADAPTOR_HDMI_SAFE_MAX_TMDS_CLK ; 
 scalar_t__ DP_ADAPTOR_TYPE2_ID ; 
 scalar_t__ DP_ADAPTOR_TYPE2_MAX_TMDS_CLK ; 
 scalar_t__ DP_ADAPTOR_TYPE2_MIN_TMDS_CLK ; 
 size_t DP_ADAPTOR_TYPE2_REG_ID ; 
 size_t DP_ADAPTOR_TYPE2_REG_MAX_TMDS_CLK ; 
 int DP_ADAPTOR_TYPE2_SIZE ; 
 scalar_t__ DP_BRANCH_DEVICE_ID_4 ; 
 int /*<<< orphan*/  DP_DVI_CONVERTER_ID_4 ; 
 scalar_t__ DP_HDMI_DONGLE_ADDRESS ; 
 scalar_t__ DP_HDMI_DONGLE_SIGNATURE_EOT ; 
 scalar_t__ DP_TRANSLATOR_DELAY ; 
 scalar_t__ EDID_SEGMENT_SIZE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HDMI_SCDC_ADDRESS ; 
 scalar_t__ HDMI_SCDC_SCRAMBLER_STATUS ; 
 scalar_t__ HDMI_SCDC_SINK_VERSION ; 
 scalar_t__ HDMI_SCDC_SOURCE_VERSION ; 
 scalar_t__ HDMI_SCDC_STATUS_FLAGS ; 
 scalar_t__ HDMI_SCDC_TMDS_CONFIG ; 
 scalar_t__ I2C_OVER_AUX_DEFER_WA_DELAY ; 
 struct ddc* dal_gpio_create_ddc (struct gpio_service*,int /*<<< orphan*/ ,int,struct gpio_ddc_hw_info*) ; 
 int /*<<< orphan*/  dal_gpio_destroy_ddc (struct ddc**) ; 
 int dal_graphics_object_id_get_connector_id (int /*<<< orphan*/ ) ; 
 int dal_i2caux_submit_aux_command (int /*<<< orphan*/ ,struct ddc*,struct aux_command*) ; 
 int /*<<< orphan*/  dal_vector_append (TYPE_12__*,struct i2c_payload*) ; 
 scalar_t__ dal_vector_construct (TYPE_12__*,struct dc_context*,scalar_t__,int) ; 
 int /*<<< orphan*/  dal_vector_destruct (TYPE_12__*) ; 
 int dm_helpers_submit_i2c (struct dc_context*,struct dc_link*,struct i2c_command*) ; 
 scalar_t__* dp_hdmi_dongle_signature_str ; 
 int /*<<< orphan*/  kfree (struct i2c_payloads*) ; 
 struct i2c_payloads* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (struct aux_request_transaction_data*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub1 (struct dc_bios*,int /*<<< orphan*/ ,struct graphics_object_i2c_info*) ; 
 int /*<<< orphan*/  stub2 (struct aux_engine*,struct ddc*) ; 
 int /*<<< orphan*/  stub3 (struct aux_engine*,struct aux_request_transaction_data*) ; 
 int stub4 (struct aux_engine*,scalar_t__*) ; 
 int stub5 (struct aux_engine*,unsigned int,void*,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  stub6 (struct aux_engine*) ; 

__attribute__((used)) static struct i2c_payloads *dal_ddc_i2c_payloads_create(struct dc_context *ctx, uint32_t count)
{
	struct i2c_payloads *payloads;

	payloads = kzalloc(sizeof(struct i2c_payloads), GFP_KERNEL);

	if (!payloads)
		return NULL;

	if (dal_vector_construct(
		&payloads->payloads, ctx, count, sizeof(struct i2c_payload)))
		return payloads;

	kfree(payloads);
	return NULL;

}

__attribute__((used)) static struct i2c_payload *dal_ddc_i2c_payloads_get(struct i2c_payloads *p)
{
	return (struct i2c_payload *)p->payloads.container;
}

__attribute__((used)) static uint32_t dal_ddc_i2c_payloads_get_count(struct i2c_payloads *p)
{
	return p->payloads.count;
}

__attribute__((used)) static void dal_ddc_i2c_payloads_destroy(struct i2c_payloads **p)
{
	if (!p || !*p)
		return;
	dal_vector_destruct(&(*p)->payloads);
	kfree(*p);
	*p = NULL;

}

__attribute__((used)) static struct aux_payloads *dal_ddc_aux_payloads_create(struct dc_context *ctx, uint32_t count)
{
	struct aux_payloads *payloads;

	payloads = kzalloc(sizeof(struct aux_payloads), GFP_KERNEL);

	if (!payloads)
		return NULL;

	if (dal_vector_construct(
		&payloads->payloads, ctx, count, sizeof(struct aux_payload)))
		return payloads;

	kfree(payloads);
	return NULL;
}

__attribute__((used)) static struct aux_payload *dal_ddc_aux_payloads_get(struct aux_payloads *p)
{
	return (struct aux_payload *)p->payloads.container;
}

__attribute__((used)) static uint32_t  dal_ddc_aux_payloads_get_count(struct aux_payloads *p)
{
	return p->payloads.count;
}

__attribute__((used)) static void dal_ddc_aux_payloads_destroy(struct aux_payloads **p)
{
	if (!p || !*p)
		return;

	dal_vector_destruct(&(*p)->payloads);
	kfree(*p);
	*p = NULL;
}

void dal_ddc_i2c_payloads_add(
	struct i2c_payloads *payloads,
	uint32_t address,
	uint32_t len,
	uint8_t *data,
	bool write)
{
	uint32_t payload_size = EDID_SEGMENT_SIZE;
	uint32_t pos;

	for (pos = 0; pos < len; pos += payload_size) {
		struct i2c_payload payload = {
			.write = write,
			.address = address,
			.length = DDC_MIN(payload_size, len - pos),
			.data = data + pos };
		dal_vector_append(&payloads->payloads, &payload);
	}

}

void dal_ddc_aux_payloads_add(
	struct aux_payloads *payloads,
	uint32_t address,
	uint32_t len,
	uint8_t *data,
	bool write)
{
	uint32_t payload_size = DEFAULT_AUX_MAX_DATA_SIZE;
	uint32_t pos;

	for (pos = 0; pos < len; pos += payload_size) {
		struct aux_payload payload = {
			.i2c_over_aux = true,
			.write = write,
			.address = address,
			.length = DDC_MIN(payload_size, len - pos),
			.data = data + pos };
		dal_vector_append(&payloads->payloads, &payload);
	}
}

__attribute__((used)) static void construct(
	struct ddc_service *ddc_service,
	struct ddc_service_init_data *init_data)
{
	enum connector_id connector_id =
		dal_graphics_object_id_get_connector_id(init_data->id);

	struct gpio_service *gpio_service = init_data->ctx->gpio_service;
	struct graphics_object_i2c_info i2c_info;
	struct gpio_ddc_hw_info hw_info;
	struct dc_bios *dcb = init_data->ctx->dc_bios;

	ddc_service->link = init_data->link;
	ddc_service->ctx = init_data->ctx;

	if (BP_RESULT_OK != dcb->funcs->get_i2c_info(dcb, init_data->id, &i2c_info)) {
		ddc_service->ddc_pin = NULL;
	} else {
		hw_info.ddc_channel = i2c_info.i2c_line;
		hw_info.hw_supported = i2c_info.i2c_hw_assist;

		ddc_service->ddc_pin = dal_gpio_create_ddc(
			gpio_service,
			i2c_info.gpio_info.clk_a_register_index,
			1 << i2c_info.gpio_info.clk_a_shift,
			&hw_info);
	}

	ddc_service->flags.EDID_QUERY_DONE_ONCE = false;
	ddc_service->flags.FORCE_READ_REPEATED_START = false;
	ddc_service->flags.EDID_STRESS_READ = false;

	ddc_service->flags.IS_INTERNAL_DISPLAY =
		connector_id == CONNECTOR_ID_EDP ||
		connector_id == CONNECTOR_ID_LVDS;

	ddc_service->wa.raw = 0;
}

struct ddc_service *dal_ddc_service_create(
	struct ddc_service_init_data *init_data)
{
	struct ddc_service *ddc_service;

	ddc_service = kzalloc(sizeof(struct ddc_service), GFP_KERNEL);

	if (!ddc_service)
		return NULL;

	construct(ddc_service, init_data);
	return ddc_service;
}

__attribute__((used)) static void destruct(struct ddc_service *ddc)
{
	if (ddc->ddc_pin)
		dal_gpio_destroy_ddc(&ddc->ddc_pin);
}

void dal_ddc_service_destroy(struct ddc_service **ddc)
{
	if (!ddc || !*ddc) {
		BREAK_TO_DEBUGGER();
		return;
	}
	destruct(*ddc);
	kfree(*ddc);
	*ddc = NULL;
}

enum ddc_service_type dal_ddc_service_get_type(struct ddc_service *ddc)
{
	return DDC_SERVICE_TYPE_CONNECTOR;
}

void dal_ddc_service_set_transaction_type(
	struct ddc_service *ddc,
	enum ddc_transaction_type type)
{
	ddc->transaction_type = type;
}

bool dal_ddc_service_is_in_aux_transaction_mode(struct ddc_service *ddc)
{
	switch (ddc->transaction_type) {
	case DDC_TRANSACTION_TYPE_I2C_OVER_AUX:
	case DDC_TRANSACTION_TYPE_I2C_OVER_AUX_WITH_DEFER:
	case DDC_TRANSACTION_TYPE_I2C_OVER_AUX_RETRY_DEFER:
		return true;
	default:
		break;
	}
	return false;
}

void ddc_service_set_dongle_type(struct ddc_service *ddc,
		enum display_dongle_type dongle_type)
{
	ddc->dongle_type = dongle_type;
}

__attribute__((used)) static uint32_t defer_delay_converter_wa(
	struct ddc_service *ddc,
	uint32_t defer_delay)
{
	struct dc_link *link = ddc->link;

	if (link->dpcd_caps.branch_dev_id == DP_BRANCH_DEVICE_ID_4 &&
		!memcmp(link->dpcd_caps.branch_dev_name,
			DP_DVI_CONVERTER_ID_4,
			sizeof(link->dpcd_caps.branch_dev_name)))
		return defer_delay > I2C_OVER_AUX_DEFER_WA_DELAY ?
			defer_delay : I2C_OVER_AUX_DEFER_WA_DELAY;

	return defer_delay;
}

uint32_t get_defer_delay(struct ddc_service *ddc)
{
	uint32_t defer_delay = 0;

	switch (ddc->transaction_type) {
	case DDC_TRANSACTION_TYPE_I2C_OVER_AUX:
		if ((DISPLAY_DONGLE_DP_VGA_CONVERTER == ddc->dongle_type) ||
			(DISPLAY_DONGLE_DP_DVI_CONVERTER == ddc->dongle_type) ||
			(DISPLAY_DONGLE_DP_HDMI_CONVERTER ==
				ddc->dongle_type)) {

			defer_delay = DP_TRANSLATOR_DELAY;

			defer_delay =
				defer_delay_converter_wa(ddc, defer_delay);

		} else /*sink has a delay different from an Active Converter*/
			defer_delay = 0;
		break;
	case DDC_TRANSACTION_TYPE_I2C_OVER_AUX_WITH_DEFER:
		defer_delay = DP_TRANSLATOR_DELAY;
		break;
	default:
		break;
	}
	return defer_delay;
}

__attribute__((used)) static bool i2c_read(
	struct ddc_service *ddc,
	uint32_t address,
	uint8_t *buffer,
	uint32_t len)
{
	uint8_t offs_data = 0;
	struct i2c_payload payloads[2] = {
		{
		.write = true,
		.address = address,
		.length = 1,
		.data = &offs_data },
		{
		.write = false,
		.address = address,
		.length = len,
		.data = buffer } };

	struct i2c_command command = {
		.payloads = payloads,
		.number_of_payloads = 2,
		.engine = DDC_I2C_COMMAND_ENGINE,
		.speed = ddc->ctx->dc->caps.i2c_speed_in_khz };

	return dm_helpers_submit_i2c(
			ddc->ctx,
			ddc->link,
			&command);
}

void dal_ddc_service_i2c_query_dp_dual_mode_adaptor(
	struct ddc_service *ddc,
	struct display_sink_capability *sink_cap)
{
	uint8_t i;
	bool is_valid_hdmi_signature;
	enum display_dongle_type *dongle = &sink_cap->dongle_type;
	uint8_t type2_dongle_buf[DP_ADAPTOR_TYPE2_SIZE];
	bool is_type2_dongle = false;
	struct dp_hdmi_dongle_signature_data *dongle_signature;

	/* Assume we have no valid DP passive dongle connected */
	*dongle = DISPLAY_DONGLE_NONE;
	sink_cap->max_hdmi_pixel_clock = DP_ADAPTOR_HDMI_SAFE_MAX_TMDS_CLK;

	/* Read DP-HDMI dongle I2c (no response interpreted as DP-DVI dongle)*/
	if (!i2c_read(
		ddc,
		DP_HDMI_DONGLE_ADDRESS,
		type2_dongle_buf,
		sizeof(type2_dongle_buf))) {
		*dongle = DISPLAY_DONGLE_DP_DVI_DONGLE;
		sink_cap->max_hdmi_pixel_clock = DP_ADAPTOR_DVI_MAX_TMDS_CLK;

		CONN_DATA_DETECT(ddc->link, type2_dongle_buf, sizeof(type2_dongle_buf),
				"DP-DVI passive dongle %dMhz: ",
				DP_ADAPTOR_DVI_MAX_TMDS_CLK / 1000);
		return;
	}

	/* Check if Type 2 dongle.*/
	if (type2_dongle_buf[DP_ADAPTOR_TYPE2_REG_ID] == DP_ADAPTOR_TYPE2_ID)
		is_type2_dongle = true;

	dongle_signature =
		(struct dp_hdmi_dongle_signature_data *)type2_dongle_buf;

	is_valid_hdmi_signature = true;

	/* Check EOT */
	if (dongle_signature->eot != DP_HDMI_DONGLE_SIGNATURE_EOT) {
		is_valid_hdmi_signature = false;
	}

	/* Check signature */
	for (i = 0; i < sizeof(dongle_signature->id); ++i) {
		/* If its not the right signature,
		 * skip mismatch in subversion byte.*/
		if (dongle_signature->id[i] !=
			dp_hdmi_dongle_signature_str[i] && i != 3) {

			if (is_type2_dongle) {
				is_valid_hdmi_signature = false;
				break;
			}

		}
	}

	if (is_type2_dongle) {
		uint32_t max_tmds_clk =
			type2_dongle_buf[DP_ADAPTOR_TYPE2_REG_MAX_TMDS_CLK];

		max_tmds_clk = max_tmds_clk * 2 + max_tmds_clk / 2;

		if (0 == max_tmds_clk ||
				max_tmds_clk < DP_ADAPTOR_TYPE2_MIN_TMDS_CLK ||
				max_tmds_clk > DP_ADAPTOR_TYPE2_MAX_TMDS_CLK) {
			*dongle = DISPLAY_DONGLE_DP_DVI_DONGLE;

			CONN_DATA_DETECT(ddc->link, type2_dongle_buf,
					sizeof(type2_dongle_buf),
					"DP-DVI passive dongle %dMhz: ",
					DP_ADAPTOR_DVI_MAX_TMDS_CLK / 1000);
		} else {
			if (is_valid_hdmi_signature == true) {
				*dongle = DISPLAY_DONGLE_DP_HDMI_DONGLE;

				CONN_DATA_DETECT(ddc->link, type2_dongle_buf,
						sizeof(type2_dongle_buf),
						"Type 2 DP-HDMI passive dongle %dMhz: ",
						max_tmds_clk);
			} else {
				*dongle = DISPLAY_DONGLE_DP_HDMI_MISMATCHED_DONGLE;

				CONN_DATA_DETECT(ddc->link, type2_dongle_buf,
						sizeof(type2_dongle_buf),
						"Type 2 DP-HDMI passive dongle (no signature) %dMhz: ",
						max_tmds_clk);

			}

			/* Multiply by 1000 to convert to kHz. */
			sink_cap->max_hdmi_pixel_clock =
				max_tmds_clk * 1000;
		}

	} else {
		if (is_valid_hdmi_signature == true) {
			*dongle = DISPLAY_DONGLE_DP_HDMI_DONGLE;

			CONN_DATA_DETECT(ddc->link, type2_dongle_buf,
					sizeof(type2_dongle_buf),
					"Type 1 DP-HDMI passive dongle %dMhz: ",
					sink_cap->max_hdmi_pixel_clock / 1000);
		} else {
			*dongle = DISPLAY_DONGLE_DP_HDMI_MISMATCHED_DONGLE;

			CONN_DATA_DETECT(ddc->link, type2_dongle_buf,
					sizeof(type2_dongle_buf),
					"Type 1 DP-HDMI passive dongle (no signature) %dMhz: ",
					sink_cap->max_hdmi_pixel_clock / 1000);
		}
	}

	return;
}

bool dal_ddc_service_query_ddc_data(
	struct ddc_service *ddc,
	uint32_t address,
	uint8_t *write_buf,
	uint32_t write_size,
	uint8_t *read_buf,
	uint32_t read_size)
{
	bool ret;
	uint32_t payload_size =
		dal_ddc_service_is_in_aux_transaction_mode(ddc) ?
			DEFAULT_AUX_MAX_DATA_SIZE : EDID_SEGMENT_SIZE;

	uint32_t write_payloads =
		(write_size + payload_size - 1) / payload_size;

	uint32_t read_payloads =
		(read_size + payload_size - 1) / payload_size;

	uint32_t payloads_num = write_payloads + read_payloads;

	if (write_size > EDID_SEGMENT_SIZE || read_size > EDID_SEGMENT_SIZE)
		return false;

	/*TODO: len of payload data for i2c and aux is uint8!!!!,
	 *  but we want to read 256 over i2c!!!!*/
	if (dal_ddc_service_is_in_aux_transaction_mode(ddc)) {

		struct aux_payloads *payloads =
			dal_ddc_aux_payloads_create(ddc->ctx, payloads_num);

		struct aux_command command = {
			.payloads = dal_ddc_aux_payloads_get(payloads),
			.number_of_payloads = 0,
			.defer_delay = get_defer_delay(ddc),
			.max_defer_write_retry = 0 };

		dal_ddc_aux_payloads_add(
			payloads, address, write_size, write_buf, true);

		dal_ddc_aux_payloads_add(
			payloads, address, read_size, read_buf, false);

		command.number_of_payloads =
			dal_ddc_aux_payloads_get_count(payloads);

		ret = dal_i2caux_submit_aux_command(
				ddc->ctx->i2caux,
				ddc->ddc_pin,
				&command);

		dal_ddc_aux_payloads_destroy(&payloads);

	} else {
		struct i2c_payloads *payloads =
			dal_ddc_i2c_payloads_create(ddc->ctx, payloads_num);

		struct i2c_command command = {
			.payloads = dal_ddc_i2c_payloads_get(payloads),
			.number_of_payloads = 0,
			.engine = DDC_I2C_COMMAND_ENGINE,
			.speed = ddc->ctx->dc->caps.i2c_speed_in_khz };

		dal_ddc_i2c_payloads_add(
			payloads, address, write_size, write_buf, true);

		dal_ddc_i2c_payloads_add(
			payloads, address, read_size, read_buf, false);

		command.number_of_payloads =
			dal_ddc_i2c_payloads_get_count(payloads);

		ret = dm_helpers_submit_i2c(
				ddc->ctx,
				ddc->link,
				&command);

		dal_ddc_i2c_payloads_destroy(&payloads);
	}

	return ret;
}

int dc_link_aux_transfer(struct ddc_service *ddc,
			     unsigned int address,
			     uint8_t *reply,
			     void *buffer,
			     unsigned int size,
			     enum aux_transaction_type type,
			     enum i2caux_transaction_action action)
{
	struct ddc *ddc_pin = ddc->ddc_pin;
	struct aux_engine *aux_engine;
	enum aux_channel_operation_result operation_result;
	struct aux_request_transaction_data aux_req;
	struct aux_reply_transaction_data aux_rep;
	uint8_t returned_bytes = 0;
	int res = -1;
	uint32_t status;

	memset(&aux_req, 0, sizeof(aux_req));
	memset(&aux_rep, 0, sizeof(aux_rep));

	aux_engine = ddc->ctx->dc->res_pool->engines[ddc_pin->pin_data->en];
	aux_engine->funcs->acquire(aux_engine, ddc_pin);

	aux_req.type = type;
	aux_req.action = action;

	aux_req.address = address;
	aux_req.delay = 0;
	aux_req.length = size;
	aux_req.data = buffer;

	aux_engine->funcs->submit_channel_request(aux_engine, &aux_req);
	operation_result = aux_engine->funcs->get_channel_status(aux_engine, &returned_bytes);

	switch (operation_result) {
	case AUX_CHANNEL_OPERATION_SUCCEEDED:
		res = returned_bytes;

		if (res <= size && res >= 0)
			res = aux_engine->funcs->read_channel_reply(aux_engine, size,
								buffer, reply,
								&status);

		break;
	case AUX_CHANNEL_OPERATION_FAILED_HPD_DISCON:
		res = 0;
		break;
	case AUX_CHANNEL_OPERATION_FAILED_REASON_UNKNOWN:
	case AUX_CHANNEL_OPERATION_FAILED_INVALID_REPLY:
	case AUX_CHANNEL_OPERATION_FAILED_TIMEOUT:
		res = -1;
		break;
	}
	aux_engine->funcs->release_engine(aux_engine);
	return res;
}

void dal_ddc_service_set_ddc_pin(
	struct ddc_service *ddc_service,
	struct ddc *ddc)
{
	ddc_service->ddc_pin = ddc;
}

struct ddc *dal_ddc_service_get_ddc_pin(struct ddc_service *ddc_service)
{
	return ddc_service->ddc_pin;
}

void dal_ddc_service_write_scdc_data(struct ddc_service *ddc_service,
		uint32_t pix_clk,
		bool lte_340_scramble)
{
	bool over_340_mhz = pix_clk > 340000 ? 1 : 0;
	uint8_t slave_address = HDMI_SCDC_ADDRESS;
	uint8_t offset = HDMI_SCDC_SINK_VERSION;
	uint8_t sink_version = 0;
	uint8_t write_buffer[2] = {0};
	/*Lower than 340 Scramble bit from SCDC caps*/

	dal_ddc_service_query_ddc_data(ddc_service, slave_address, &offset,
			sizeof(offset), &sink_version, sizeof(sink_version));
	if (sink_version == 1) {
		/*Source Version = 1*/
		write_buffer[0] = HDMI_SCDC_SOURCE_VERSION;
		write_buffer[1] = 1;
		dal_ddc_service_query_ddc_data(ddc_service, slave_address,
				write_buffer, sizeof(write_buffer), NULL, 0);
		/*Read Request from SCDC caps*/
	}
	write_buffer[0] = HDMI_SCDC_TMDS_CONFIG;

	if (over_340_mhz) {
		write_buffer[1] = 3;
	} else if (lte_340_scramble) {
		write_buffer[1] = 1;
	} else {
		write_buffer[1] = 0;
	}
	dal_ddc_service_query_ddc_data(ddc_service, slave_address, write_buffer,
			sizeof(write_buffer), NULL, 0);
}

void dal_ddc_service_read_scdc_data(struct ddc_service *ddc_service)
{
	uint8_t slave_address = HDMI_SCDC_ADDRESS;
	uint8_t offset = HDMI_SCDC_TMDS_CONFIG;
	uint8_t tmds_config = 0;

	dal_ddc_service_query_ddc_data(ddc_service, slave_address, &offset,
			sizeof(offset), &tmds_config, sizeof(tmds_config));
	if (tmds_config & 0x1) {
		union hdmi_scdc_status_flags_data status_data = { {0} };
		uint8_t scramble_status = 0;

		offset = HDMI_SCDC_SCRAMBLER_STATUS;
		dal_ddc_service_query_ddc_data(ddc_service, slave_address,
				&offset, sizeof(offset), &scramble_status,
				sizeof(scramble_status));
		offset = HDMI_SCDC_STATUS_FLAGS;
		dal_ddc_service_query_ddc_data(ddc_service, slave_address,
				&offset, sizeof(offset), status_data.byte,
				sizeof(status_data.byte));
	}
}

