#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint32_t ;
struct i2caux {int /*<<< orphan*/ * aux_engines; int /*<<< orphan*/  aux_timeout_period; struct i2c_engine** i2c_hw_engines; int /*<<< orphan*/  default_i2c_hw_speed; int /*<<< orphan*/ * i2c_sw_engines; int /*<<< orphan*/  default_i2c_sw_speed; int /*<<< orphan*/ * funcs; struct i2c_engine* i2c_generic_hw_engine; } ;
struct i2caux_dce80 {int i2c_hw_buffer_in_use; struct i2caux base; } ;
struct i2c_sw_engine_dce80_create_arg {size_t engine_id; struct dc_context* ctx; int /*<<< orphan*/  default_speed; } ;
struct i2c_hw_engine_dce80_create_arg {size_t engine_id; size_t reference_frequency; struct dc_context* ctx; int /*<<< orphan*/  default_speed; } ;
struct TYPE_9__ {TYPE_2__* funcs; } ;
struct i2c_engine {TYPE_4__ base; } ;
struct engine {TYPE_3__* funcs; } ;
struct TYPE_6__ {scalar_t__ hw_supported; } ;
struct ddc {TYPE_1__ hw_info; } ;
struct dc_context {int /*<<< orphan*/  dc_bios; } ;
struct aux_engine_dce110_init_data {size_t engine_id; int /*<<< orphan*/ * regs; struct dc_context* ctx; int /*<<< orphan*/  timeout_period; } ;
typedef  enum gpio_ddc_line { ____Placeholder_gpio_ddc_line } gpio_ddc_line ;
struct TYPE_8__ {scalar_t__ (* get_engine_type ) (struct engine*) ;} ;
struct TYPE_7__ {scalar_t__ (* acquire ) (TYPE_4__*,struct ddc*) ;} ;

/* Variables and functions */
 size_t ARRAY_SIZE (int*) ; 
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
 struct i2caux_dce80* FROM_I2C_AUX (struct i2caux*) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIO_DDC_LINE_COUNT ; 
 scalar_t__ I2CAUX_ENGINE_TYPE_I2C_DDC_HW ; 
 int /*<<< orphan*/  dal_aux_engine_dce110_create (struct aux_engine_dce110_init_data*) ; 
 int dal_ddc_get_line (struct ddc*) ; 
 struct i2c_engine* dal_i2c_hw_engine_dce80_create (struct i2c_hw_engine_dce80_create_arg*) ; 
 int /*<<< orphan*/  dal_i2c_sw_engine_dce80_create (struct i2c_sw_engine_dce80_create_arg*) ; 
 int /*<<< orphan*/  dal_i2caux_construct (struct i2caux*,struct dc_context*) ; 
 int /*<<< orphan*/  dal_i2caux_destruct (struct i2caux*) ; 
 int dal_i2caux_get_reference_clock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dal_i2caux_release_engine (struct i2caux*,struct engine*) ; 
 int /*<<< orphan*/ * dce80_aux_regs ; 
 int* hw_aux_lines ; 
 int* hw_ddc_lines ; 
 int /*<<< orphan*/  i2caux_funcs ; 
 int /*<<< orphan*/  kfree (struct i2caux_dce80*) ; 
 struct i2caux_dce80* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ stub1 (TYPE_4__*,struct ddc*) ; 
 scalar_t__ stub2 (TYPE_4__*,struct ddc*) ; 
 scalar_t__ stub3 (struct engine*) ; 

__attribute__((used)) static void destruct(
	struct i2caux_dce80 *i2caux_dce80)
{
	dal_i2caux_destruct(&i2caux_dce80->base);
}

__attribute__((used)) static void destroy(
	struct i2caux **i2c_engine)
{
	struct i2caux_dce80 *i2caux_dce80 = FROM_I2C_AUX(*i2c_engine);

	destruct(i2caux_dce80);

	kfree(i2caux_dce80);

	*i2c_engine = NULL;
}

__attribute__((used)) static struct i2c_engine *acquire_i2c_hw_engine(
	struct i2caux *i2caux,
	struct ddc *ddc)
{
	struct i2caux_dce80 *i2caux_dce80 = FROM_I2C_AUX(i2caux);

	struct i2c_engine *engine = NULL;
	bool non_generic;

	if (!ddc)
		return NULL;

	if (ddc->hw_info.hw_supported) {
		enum gpio_ddc_line line = dal_ddc_get_line(ddc);

		if (line < GPIO_DDC_LINE_COUNT) {
			non_generic = true;
			engine = i2caux->i2c_hw_engines[line];
		}
	}

	if (!engine) {
		non_generic = false;
		engine = i2caux->i2c_generic_hw_engine;
	}

	if (!engine)
		return NULL;

	if (non_generic) {
		if (!i2caux_dce80->i2c_hw_buffer_in_use &&
			engine->base.funcs->acquire(&engine->base, ddc)) {
			i2caux_dce80->i2c_hw_buffer_in_use = true;
			return engine;
		}
	} else {
		if (engine->base.funcs->acquire(&engine->base, ddc))
			return engine;
	}

	return NULL;
}

__attribute__((used)) static void release_engine(
	struct i2caux *i2caux,
	struct engine *engine)
{
	if (engine->funcs->get_engine_type(engine) ==
		I2CAUX_ENGINE_TYPE_I2C_DDC_HW)
		FROM_I2C_AUX(i2caux)->i2c_hw_buffer_in_use = false;

	dal_i2caux_release_engine(i2caux, engine);
}

__attribute__((used)) static void construct(
	struct i2caux_dce80 *i2caux_dce80,
	struct dc_context *ctx)
{
	/* Entire family have I2C engine reference clock frequency
	 * changed from XTALIN (27) to XTALIN/2 (13.5) */

	struct i2caux *base = &i2caux_dce80->base;

	uint32_t reference_frequency =
		dal_i2caux_get_reference_clock(ctx->dc_bios) >> 1;

	/*bool use_i2c_sw_engine = dal_adapter_service_is_feature_supported(as,
		FEATURE_RESTORE_USAGE_I2C_SW_ENGINE);*/

	/* Use SWI2C for dce8 currently, sicne we have bug with hwi2c */
	bool use_i2c_sw_engine = true;

	uint32_t i;

	dal_i2caux_construct(base, ctx);

	i2caux_dce80->base.funcs = &i2caux_funcs;
	i2caux_dce80->i2c_hw_buffer_in_use = false;

	/* Create I2C HW engines (HW + SW pairs)
	 * for all lines which has assisted HW DDC
	 * 'i' (loop counter) used as DDC/AUX engine_id */

	i = 0;

	do {
		enum gpio_ddc_line line_id = hw_ddc_lines[i];

		struct i2c_hw_engine_dce80_create_arg hw_arg;

		if (use_i2c_sw_engine) {
			struct i2c_sw_engine_dce80_create_arg sw_arg;

			sw_arg.engine_id = i;
			sw_arg.default_speed = base->default_i2c_sw_speed;
			sw_arg.ctx = ctx;
			base->i2c_sw_engines[line_id] =
				dal_i2c_sw_engine_dce80_create(&sw_arg);
		}

		hw_arg.engine_id = i;
		hw_arg.reference_frequency = reference_frequency;
		hw_arg.default_speed = base->default_i2c_hw_speed;
		hw_arg.ctx = ctx;

		base->i2c_hw_engines[line_id] =
			dal_i2c_hw_engine_dce80_create(&hw_arg);

		++i;
	} while (i < ARRAY_SIZE(hw_ddc_lines));

	/* Create AUX engines for all lines which has assisted HW AUX
	 * 'i' (loop counter) used as DDC/AUX engine_id */

	i = 0;

	do {
		enum gpio_ddc_line line_id = hw_aux_lines[i];

		struct aux_engine_dce110_init_data arg;

		arg.engine_id = i;
		arg.timeout_period = base->aux_timeout_period;
		arg.ctx = ctx;
		arg.regs = &dce80_aux_regs[i];

		base->aux_engines[line_id] =
			dal_aux_engine_dce110_create(&arg);

		++i;
	} while (i < ARRAY_SIZE(hw_aux_lines));

	/* TODO Generic I2C SW and HW */
}

struct i2caux *dal_i2caux_dce80_create(
	struct dc_context *ctx)
{
	struct i2caux_dce80 *i2caux_dce80 =
		kzalloc(sizeof(struct i2caux_dce80), GFP_KERNEL);

	if (!i2caux_dce80) {
		BREAK_TO_DEBUGGER();
		return NULL;
	}

	construct(i2caux_dce80, ctx);
	return &i2caux_dce80->base;
}

