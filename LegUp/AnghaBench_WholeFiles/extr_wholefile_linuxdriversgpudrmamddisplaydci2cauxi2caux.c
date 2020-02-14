#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_9__ ;
typedef  struct TYPE_35__   TYPE_8__ ;
typedef  struct TYPE_34__   TYPE_7__ ;
typedef  struct TYPE_33__   TYPE_6__ ;
typedef  struct TYPE_32__   TYPE_5__ ;
typedef  struct TYPE_31__   TYPE_4__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;
typedef  struct TYPE_27__   TYPE_17__ ;
typedef  struct TYPE_26__   TYPE_16__ ;
typedef  struct TYPE_25__   TYPE_13__ ;
typedef  struct TYPE_24__   TYPE_12__ ;
typedef  struct TYPE_23__   TYPE_11__ ;
typedef  struct TYPE_22__   TYPE_10__ ;

/* Type definitions */
typedef  union aux_config {int dummy; } aux_config ;
typedef  int uint8_t ;
typedef  int uint32_t ;
struct TYPE_28__ {int address; int /*<<< orphan*/  data; int /*<<< orphan*/  length; void* address_space; } ;
struct i2caux_transaction_request {TYPE_1__ payload; void* operation; int /*<<< orphan*/  member_0; } ;
struct i2caux {int aux_timeout_period; struct i2c_engine** i2c_sw_engines; TYPE_16__** i2c_hw_engines; struct aux_engine** aux_engines; struct i2c_engine* i2c_generic_sw_engine; TYPE_17__* i2c_generic_hw_engine; int /*<<< orphan*/  default_i2c_sw_speed; int /*<<< orphan*/  default_i2c_hw_speed; struct dc_context* ctx; TYPE_11__* funcs; } ;
struct i2c_payload {int address; int /*<<< orphan*/  data; int /*<<< orphan*/  length; scalar_t__ write; } ;
struct TYPE_25__ {TYPE_6__* funcs; } ;
struct i2c_engine {TYPE_12__* funcs; TYPE_13__ base; } ;
struct i2c_command {int engine; int number_of_payloads; struct i2c_payload* payloads; int /*<<< orphan*/  speed; } ;
struct engine {int /*<<< orphan*/ * ddc; TYPE_7__* funcs; } ;
struct TYPE_29__ {int /*<<< orphan*/  hw_supported; } ;
struct ddc {TYPE_2__ hw_info; } ;
struct TYPE_32__ {int crystal_frequency; } ;
struct TYPE_30__ {int /*<<< orphan*/  member_0; } ;
struct dc_firmware_info {TYPE_5__ pll_info; TYPE_3__ member_0; } ;
struct dc_context {int dce_version; int /*<<< orphan*/  dce_environment; } ;
struct dc_bios {TYPE_4__* funcs; } ;
struct aux_payload {int address; int /*<<< orphan*/  data; int /*<<< orphan*/  length; scalar_t__ write; scalar_t__ i2c_over_aux; } ;
struct aux_engine {TYPE_9__* funcs; TYPE_13__ base; int /*<<< orphan*/  max_defer_write_retry; int /*<<< orphan*/  delay; } ;
struct aux_command {int number_of_payloads; scalar_t__ mot; struct aux_payload* payloads; int /*<<< orphan*/  max_defer_write_retry; int /*<<< orphan*/  defer_delay; } ;
typedef  enum gpio_ddc_line { ____Placeholder_gpio_ddc_line } gpio_ddc_line ;
struct TYPE_36__ {int /*<<< orphan*/  (* destroy ) (struct aux_engine**) ;int /*<<< orphan*/  (* configure ) (struct aux_engine*,union aux_config) ;} ;
struct TYPE_35__ {int /*<<< orphan*/  (* destroy ) (TYPE_17__**) ;} ;
struct TYPE_34__ {int /*<<< orphan*/  (* release_engine ) (struct engine*) ;} ;
struct TYPE_33__ {int /*<<< orphan*/  (* acquire ) (TYPE_13__*,struct ddc*) ;int /*<<< orphan*/  (* submit_request ) (TYPE_13__*,struct i2caux_transaction_request*,int) ;} ;
struct TYPE_31__ {scalar_t__ (* get_firmware_info ) (struct dc_bios*,struct dc_firmware_info*) ;} ;
struct TYPE_27__ {TYPE_8__* funcs; } ;
struct TYPE_26__ {TYPE_10__* funcs; } ;
struct TYPE_24__ {int /*<<< orphan*/  (* destroy ) (struct i2c_engine**) ;int /*<<< orphan*/  (* set_speed ) (struct i2c_engine*,int /*<<< orphan*/ ) ;} ;
struct TYPE_23__ {int /*<<< orphan*/  (* destroy ) (struct i2caux**) ;int /*<<< orphan*/  (* release_engine ) (struct i2caux*,TYPE_13__*) ;struct aux_engine* (* acquire_aux_engine ) (struct i2caux*,struct ddc*) ;struct i2c_engine* (* acquire_i2c_sw_engine ) (struct i2caux*,struct ddc*) ;struct i2c_engine* (* acquire_i2c_hw_engine ) (struct i2caux*,struct ddc*) ;} ;
struct TYPE_22__ {int /*<<< orphan*/  (* destroy ) (TYPE_16__**) ;} ;

/* Variables and functions */
 int AUX_TIMEOUT_PERIOD ; 
 scalar_t__ BP_RESULT_OK ; 
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
#define  DCE_VERSION_10_0 138 
#define  DCE_VERSION_11_0 137 
#define  DCE_VERSION_11_2 136 
#define  DCE_VERSION_11_22 135 
#define  DCE_VERSION_12_0 134 
#define  DCE_VERSION_8_0 133 
#define  DCE_VERSION_8_1 132 
#define  DCE_VERSION_8_3 131 
 int /*<<< orphan*/  DEFAULT_I2C_HW_SPEED ; 
 int /*<<< orphan*/  DEFAULT_I2C_HW_SPEED_100KHZ ; 
 int /*<<< orphan*/  DEFAULT_I2C_SW_SPEED ; 
 int /*<<< orphan*/  DEFAULT_I2C_SW_SPEED_100KHZ ; 
 int GPIO_DDC_LINE_COUNT ; 
 int GPIO_DDC_LINE_UNKNOWN ; 
 void* I2CAUX_TRANSACTION_ADDRESS_SPACE_DPCD ; 
 void* I2CAUX_TRANSACTION_ADDRESS_SPACE_I2C ; 
 void* I2CAUX_TRANSACTION_READ ; 
 void* I2CAUX_TRANSACTION_WRITE ; 
#define  I2C_COMMAND_ENGINE_DEFAULT 130 
#define  I2C_COMMAND_ENGINE_HW 129 
#define  I2C_COMMAND_ENGINE_SW 128 
 scalar_t__ I2C_MOT_TRUE ; 
 scalar_t__ I2C_MOT_UNDEF ; 
 scalar_t__ IS_FPGA_MAXIMUS_DC (int /*<<< orphan*/ ) ; 
 int SW_AUX_TIMEOUT_PERIOD_MULTIPLIER ; 
 int /*<<< orphan*/  dal_ddc_close (int /*<<< orphan*/ *) ; 
 int dal_ddc_get_line (struct ddc*) ; 
 struct i2caux* dal_i2caux_dce100_create (struct dc_context*) ; 
 struct i2caux* dal_i2caux_dce110_create (struct dc_context*) ; 
 struct i2caux* dal_i2caux_dce112_create (struct dc_context*) ; 
 struct i2caux* dal_i2caux_dce120_create (struct dc_context*) ; 
 struct i2caux* dal_i2caux_dce80_create (struct dc_context*) ; 
 struct i2caux* dal_i2caux_diag_fpga_create (struct dc_context*) ; 
 struct i2c_engine* stub1 (struct i2caux*,struct ddc*) ; 
 int /*<<< orphan*/  stub10 (struct i2caux*,TYPE_13__*) ; 
 struct aux_engine* stub11 (struct i2caux*,struct ddc*) ; 
 int /*<<< orphan*/  stub12 (struct aux_engine*,union aux_config) ; 
 int /*<<< orphan*/  stub13 (struct i2caux*,TYPE_13__*) ; 
 int /*<<< orphan*/  stub14 (struct i2caux**) ; 
 scalar_t__ stub15 (struct dc_bios*,struct dc_firmware_info*) ; 
 int /*<<< orphan*/  stub16 (TYPE_13__*,struct ddc*) ; 
 int /*<<< orphan*/  stub17 (TYPE_13__*,struct ddc*) ; 
 int /*<<< orphan*/  stub18 (struct engine*) ; 
 int /*<<< orphan*/  stub19 (TYPE_17__**) ; 
 struct i2c_engine* stub2 (struct i2caux*,struct ddc*) ; 
 int /*<<< orphan*/  stub20 (struct i2c_engine**) ; 
 int /*<<< orphan*/  stub21 (struct aux_engine**) ; 
 int /*<<< orphan*/  stub22 (TYPE_16__**) ; 
 int /*<<< orphan*/  stub23 (struct i2c_engine**) ; 
 struct i2c_engine* stub3 (struct i2caux*,struct ddc*) ; 
 struct i2c_engine* stub4 (struct i2caux*,struct ddc*) ; 
 int /*<<< orphan*/  stub5 (struct i2c_engine*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (TYPE_13__*,struct i2caux_transaction_request*,int) ; 
 int /*<<< orphan*/  stub7 (struct i2caux*,TYPE_13__*) ; 
 struct aux_engine* stub8 (struct i2caux*,struct ddc*) ; 
 int /*<<< orphan*/  stub9 (TYPE_13__*,struct i2caux_transaction_request*,int) ; 

struct i2caux *dal_i2caux_create(
	struct dc_context *ctx)
{
	if (IS_FPGA_MAXIMUS_DC(ctx->dce_environment)) {
		return dal_i2caux_diag_fpga_create(ctx);
	}

	switch (ctx->dce_version) {
	case DCE_VERSION_8_0:
	case DCE_VERSION_8_1:
	case DCE_VERSION_8_3:
		return dal_i2caux_dce80_create(ctx);
	case DCE_VERSION_11_2:
	case DCE_VERSION_11_22:
		return dal_i2caux_dce112_create(ctx);
	case DCE_VERSION_11_0:
		return dal_i2caux_dce110_create(ctx);
	case DCE_VERSION_10_0:
		return dal_i2caux_dce100_create(ctx);
	case DCE_VERSION_12_0:
		return dal_i2caux_dce120_create(ctx);
#if defined(CONFIG_DRM_AMD_DC_DCN1_0)
	case DCN_VERSION_1_0:
		return dal_i2caux_dcn10_create(ctx);
#endif

	default:
		BREAK_TO_DEBUGGER();
		return NULL;
	}
}

bool dal_i2caux_submit_i2c_command(
	struct i2caux *i2caux,
	struct ddc *ddc,
	struct i2c_command *cmd)
{
	struct i2c_engine *engine;
	uint8_t index_of_payload = 0;
	bool result;

	if (!ddc) {
		BREAK_TO_DEBUGGER();
		return false;
	}

	if (!cmd) {
		BREAK_TO_DEBUGGER();
		return false;
	}

	/*
	 * default will be SW, however there is a feature flag in adapter
	 * service that determines whether SW i2c_engine will be available or
	 * not, if sw i2c is not available we will fallback to hw. This feature
	 * flag is set to not creating sw i2c engine for every dce except dce80
	 * currently
	 */
	switch (cmd->engine) {
	case I2C_COMMAND_ENGINE_DEFAULT:
	case I2C_COMMAND_ENGINE_SW:
		/* try to acquire SW engine first,
		 * acquire HW engine if SW engine not available */
		engine = i2caux->funcs->acquire_i2c_sw_engine(i2caux, ddc);

		if (!engine)
			engine = i2caux->funcs->acquire_i2c_hw_engine(
				i2caux, ddc);
	break;
	case I2C_COMMAND_ENGINE_HW:
	default:
		/* try to acquire HW engine first,
		 * acquire SW engine if HW engine not available */
		engine = i2caux->funcs->acquire_i2c_hw_engine(i2caux, ddc);

		if (!engine)
			engine = i2caux->funcs->acquire_i2c_sw_engine(
				i2caux, ddc);
	}

	if (!engine)
		return false;

	engine->funcs->set_speed(engine, cmd->speed);

	result = true;

	while (index_of_payload < cmd->number_of_payloads) {
		bool mot = (index_of_payload != cmd->number_of_payloads - 1);

		struct i2c_payload *payload = cmd->payloads + index_of_payload;

		struct i2caux_transaction_request request = { 0 };

		request.operation = payload->write ?
			I2CAUX_TRANSACTION_WRITE :
			I2CAUX_TRANSACTION_READ;

		request.payload.address_space =
			I2CAUX_TRANSACTION_ADDRESS_SPACE_I2C;
		request.payload.address = (payload->address << 1) |
			!payload->write;
		request.payload.length = payload->length;
		request.payload.data = payload->data;

		if (!engine->base.funcs->submit_request(
			&engine->base, &request, mot)) {
			result = false;
			break;
		}

		++index_of_payload;
	}

	i2caux->funcs->release_engine(i2caux, &engine->base);

	return result;
}

bool dal_i2caux_submit_aux_command(
	struct i2caux *i2caux,
	struct ddc *ddc,
	struct aux_command *cmd)
{
	struct aux_engine *engine;
	uint8_t index_of_payload = 0;
	bool result;
	bool mot;

	if (!ddc) {
		BREAK_TO_DEBUGGER();
		return false;
	}

	if (!cmd) {
		BREAK_TO_DEBUGGER();
		return false;
	}

	engine = i2caux->funcs->acquire_aux_engine(i2caux, ddc);

	if (!engine)
		return false;

	engine->delay = cmd->defer_delay;
	engine->max_defer_write_retry = cmd->max_defer_write_retry;

	result = true;

	while (index_of_payload < cmd->number_of_payloads) {
		struct aux_payload *payload = cmd->payloads + index_of_payload;
		struct i2caux_transaction_request request = { 0 };

		if (cmd->mot == I2C_MOT_UNDEF)
			mot = (index_of_payload != cmd->number_of_payloads - 1);
		else
			mot = (cmd->mot == I2C_MOT_TRUE);

		request.operation = payload->write ?
			I2CAUX_TRANSACTION_WRITE :
			I2CAUX_TRANSACTION_READ;

		if (payload->i2c_over_aux) {
			request.payload.address_space =
				I2CAUX_TRANSACTION_ADDRESS_SPACE_I2C;

			request.payload.address = (payload->address << 1) |
				!payload->write;
		} else {
			request.payload.address_space =
				I2CAUX_TRANSACTION_ADDRESS_SPACE_DPCD;

			request.payload.address = payload->address;
		}

		request.payload.length = payload->length;
		request.payload.data = payload->data;

		if (!engine->base.funcs->submit_request(
			&engine->base, &request, mot)) {
			result = false;
			break;
		}

		++index_of_payload;
	}

	i2caux->funcs->release_engine(i2caux, &engine->base);

	return result;
}

__attribute__((used)) static bool get_hw_supported_ddc_line(
	struct ddc *ddc,
	enum gpio_ddc_line *line)
{
	enum gpio_ddc_line line_found;

	*line = GPIO_DDC_LINE_UNKNOWN;

	if (!ddc) {
		BREAK_TO_DEBUGGER();
		return false;
	}

	if (!ddc->hw_info.hw_supported)
		return false;

	line_found = dal_ddc_get_line(ddc);

	if (line_found >= GPIO_DDC_LINE_COUNT)
		return false;

	*line = line_found;

	return true;
}

void dal_i2caux_configure_aux(
	struct i2caux *i2caux,
	struct ddc *ddc,
	union aux_config cfg)
{
	struct aux_engine *engine =
		i2caux->funcs->acquire_aux_engine(i2caux, ddc);

	if (!engine)
		return;

	engine->funcs->configure(engine, cfg);

	i2caux->funcs->release_engine(i2caux, &engine->base);
}

void dal_i2caux_destroy(
	struct i2caux **i2caux)
{
	if (!i2caux || !*i2caux) {
		BREAK_TO_DEBUGGER();
		return;
	}

	(*i2caux)->funcs->destroy(i2caux);

	*i2caux = NULL;
}

uint32_t dal_i2caux_get_reference_clock(
		struct dc_bios *bios)
{
	struct dc_firmware_info info = { { 0 } };

	if (bios->funcs->get_firmware_info(bios, &info) != BP_RESULT_OK)
		return 0;

	return info.pll_info.crystal_frequency;
}

struct i2c_engine *dal_i2caux_acquire_i2c_sw_engine(
	struct i2caux *i2caux,
	struct ddc *ddc)
{
	enum gpio_ddc_line line;
	struct i2c_engine *engine = NULL;

	if (get_hw_supported_ddc_line(ddc, &line))
		engine = i2caux->i2c_sw_engines[line];

	if (!engine)
		engine = i2caux->i2c_generic_sw_engine;

	if (!engine)
		return NULL;

	if (!engine->base.funcs->acquire(&engine->base, ddc))
		return NULL;

	return engine;
}

struct aux_engine *dal_i2caux_acquire_aux_engine(
	struct i2caux *i2caux,
	struct ddc *ddc)
{
	enum gpio_ddc_line line;
	struct aux_engine *engine;

	if (!get_hw_supported_ddc_line(ddc, &line))
		return NULL;

	engine = i2caux->aux_engines[line];

	if (!engine)
		return NULL;

	if (!engine->base.funcs->acquire(&engine->base, ddc))
		return NULL;

	return engine;
}

void dal_i2caux_release_engine(
	struct i2caux *i2caux,
	struct engine *engine)
{
	engine->funcs->release_engine(engine);

	dal_ddc_close(engine->ddc);

	engine->ddc = NULL;
}

void dal_i2caux_construct(
	struct i2caux *i2caux,
	struct dc_context *ctx)
{
	uint32_t i = 0;

	i2caux->ctx = ctx;
	do {
		i2caux->i2c_sw_engines[i] = NULL;
		i2caux->i2c_hw_engines[i] = NULL;
		i2caux->aux_engines[i] = NULL;

		++i;
	} while (i < GPIO_DDC_LINE_COUNT);

	i2caux->i2c_generic_sw_engine = NULL;
	i2caux->i2c_generic_hw_engine = NULL;

	i2caux->aux_timeout_period =
		SW_AUX_TIMEOUT_PERIOD_MULTIPLIER * AUX_TIMEOUT_PERIOD;

	if (ctx->dce_version >= DCE_VERSION_11_2) {
		i2caux->default_i2c_hw_speed = DEFAULT_I2C_HW_SPEED_100KHZ;
		i2caux->default_i2c_sw_speed = DEFAULT_I2C_SW_SPEED_100KHZ;
	} else {
		i2caux->default_i2c_hw_speed = DEFAULT_I2C_HW_SPEED;
		i2caux->default_i2c_sw_speed = DEFAULT_I2C_SW_SPEED;
	}
}

void dal_i2caux_destruct(
	struct i2caux *i2caux)
{
	uint32_t i = 0;

	if (i2caux->i2c_generic_hw_engine)
		i2caux->i2c_generic_hw_engine->funcs->destroy(
			&i2caux->i2c_generic_hw_engine);

	if (i2caux->i2c_generic_sw_engine)
		i2caux->i2c_generic_sw_engine->funcs->destroy(
			&i2caux->i2c_generic_sw_engine);

	do {
		if (i2caux->aux_engines[i])
			i2caux->aux_engines[i]->funcs->destroy(
				&i2caux->aux_engines[i]);

		if (i2caux->i2c_hw_engines[i])
			i2caux->i2c_hw_engines[i]->funcs->destroy(
				&i2caux->i2c_hw_engines[i]);

		if (i2caux->i2c_sw_engines[i])
			i2caux->i2c_sw_engines[i]->funcs->destroy(
				&i2caux->i2c_sw_engines[i]);

		++i;
	} while (i < GPIO_DDC_LINE_COUNT);
}

