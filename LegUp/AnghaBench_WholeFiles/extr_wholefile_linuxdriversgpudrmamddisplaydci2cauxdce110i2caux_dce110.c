#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint32_t ;
struct i2caux {int /*<<< orphan*/ * aux_engines; int /*<<< orphan*/  aux_timeout_period; struct i2c_engine** i2c_hw_engines; int /*<<< orphan*/  default_i2c_hw_speed; int /*<<< orphan*/ * i2c_sw_engines; int /*<<< orphan*/  default_i2c_sw_speed; int /*<<< orphan*/ * funcs; } ;
struct i2caux_dce110 {int i2c_hw_buffer_in_use; struct i2caux base; } ;
struct i2c_sw_engine_dce110_create_arg {size_t engine_id; struct dc_context* ctx; int /*<<< orphan*/  default_speed; } ;
struct i2c_hw_engine_dce110_create_arg {size_t engine_id; size_t reference_frequency; struct dce110_i2c_hw_engine_mask const* i2c_mask; struct dce110_i2c_hw_engine_shift const* i2c_shift; struct dce110_i2c_hw_engine_registers const* regs; struct dc_context* ctx; int /*<<< orphan*/  default_speed; } ;
struct TYPE_8__ {TYPE_2__* funcs; } ;
struct i2c_engine {int /*<<< orphan*/  send_reset_length; int /*<<< orphan*/  setup_limit; TYPE_4__ base; } ;
struct engine {TYPE_3__* funcs; } ;
struct TYPE_5__ {scalar_t__ hw_supported; } ;
struct ddc {TYPE_1__ hw_info; } ;
struct dce110_i2c_hw_engine_shift {int dummy; } ;
struct dce110_i2c_hw_engine_registers {int dummy; } ;
struct dce110_i2c_hw_engine_mask {int dummy; } ;
struct dce110_aux_registers {int dummy; } ;
struct dc_link {int dummy; } ;
struct dc_context {int dce_version; int /*<<< orphan*/  dc_bios; } ;
struct dc {struct dc_link** links; } ;
struct aux_engine_dce110_init_data {size_t engine_id; struct dce110_aux_registers const* regs; struct dc_context* ctx; int /*<<< orphan*/  timeout_period; } ;
typedef  enum gpio_ddc_line { ____Placeholder_gpio_ddc_line } gpio_ddc_line ;
struct TYPE_7__ {scalar_t__ (* get_engine_type ) (struct engine*) ;} ;
struct TYPE_6__ {scalar_t__ (* acquire ) (TYPE_4__*,struct ddc*) ;} ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct dce110_aux_registers*) ; 
 int /*<<< orphan*/  ASSERT_CRITICAL (int) ; 
#define  DCN_VERSION_1_0 128 
 struct i2caux_dce110* FROM_I2C_AUX (struct i2caux*) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIO_DDC_LINE_COUNT ; 
 scalar_t__ I2CAUX_ENGINE_TYPE_I2C_DDC_HW ; 
 int /*<<< orphan*/  I2C_SETUP_TIME_LIMIT_DCE ; 
 int /*<<< orphan*/  I2C_SETUP_TIME_LIMIT_DCN ; 
 int /*<<< orphan*/  dal_aux_engine_dce110_create (struct aux_engine_dce110_init_data*) ; 
 int dal_ddc_get_line (struct ddc*) ; 
 struct i2c_engine* dal_i2c_hw_engine_dce110_create (struct i2c_hw_engine_dce110_create_arg*) ; 
 int /*<<< orphan*/  dal_i2c_sw_engine_dce110_create (struct i2c_sw_engine_dce110_create_arg*) ; 
 int /*<<< orphan*/  dal_i2caux_construct (struct i2caux*,struct dc_context*) ; 
 int /*<<< orphan*/  dal_i2caux_destruct (struct i2caux*) ; 
 int dal_i2caux_get_reference_clock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dal_i2caux_release_engine (struct i2caux*,struct engine*) ; 
 struct dce110_aux_registers* dce110_aux_regs ; 
 int* hw_aux_lines ; 
 int* hw_ddc_lines ; 
 struct dce110_i2c_hw_engine_registers* i2c_hw_engine_regs ; 
 struct dce110_i2c_hw_engine_mask i2c_mask ; 
 struct dce110_i2c_hw_engine_shift i2c_shift ; 
 int /*<<< orphan*/  i2caux_funcs ; 
 int /*<<< orphan*/  kfree (struct i2caux_dce110*) ; 
 struct i2caux_dce110* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ stub1 (TYPE_4__*,struct ddc*) ; 
 scalar_t__ stub2 (struct engine*) ; 

__attribute__((used)) static inline struct dc_link *dc_get_link_at_index(struct dc *dc, uint32_t link_index)
{
	return dc->links[link_index];
}

__attribute__((used)) static void destruct(
	struct i2caux_dce110 *i2caux_dce110)
{
	dal_i2caux_destruct(&i2caux_dce110->base);
}

__attribute__((used)) static void destroy(
	struct i2caux **i2c_engine)
{
	struct i2caux_dce110 *i2caux_dce110 = FROM_I2C_AUX(*i2c_engine);

	destruct(i2caux_dce110);

	kfree(i2caux_dce110);

	*i2c_engine = NULL;
}

__attribute__((used)) static struct i2c_engine *acquire_i2c_hw_engine(
	struct i2caux *i2caux,
	struct ddc *ddc)
{
	struct i2caux_dce110 *i2caux_dce110 = FROM_I2C_AUX(i2caux);

	struct i2c_engine *engine = NULL;
	/* generic hw engine is not used for EDID read
	 * It may be needed for external i2c device, like thermal chip,
	 * TODO will be implemented when needed.
	 * check dce80 bool non_generic for generic hw engine;
	 */

	if (!ddc)
		return NULL;

	if (ddc->hw_info.hw_supported) {
		enum gpio_ddc_line line = dal_ddc_get_line(ddc);

		if (line < GPIO_DDC_LINE_COUNT)
			engine = i2caux->i2c_hw_engines[line];
	}

	if (!engine)
		return NULL;

	if (!i2caux_dce110->i2c_hw_buffer_in_use &&
		engine->base.funcs->acquire(&engine->base, ddc)) {
		i2caux_dce110->i2c_hw_buffer_in_use = true;
		return engine;
	}

	return NULL;
}

__attribute__((used)) static void release_engine(
	struct i2caux *i2caux,
	struct engine *engine)
{
	struct i2caux_dce110 *i2caux_dce110 = FROM_I2C_AUX(i2caux);

	if (engine->funcs->get_engine_type(engine) ==
		I2CAUX_ENGINE_TYPE_I2C_DDC_HW)
		i2caux_dce110->i2c_hw_buffer_in_use = false;

	dal_i2caux_release_engine(i2caux, engine);
}

void dal_i2caux_dce110_construct(
	struct i2caux_dce110 *i2caux_dce110,
	struct dc_context *ctx,
	unsigned int num_i2caux_inst,
	const struct dce110_aux_registers aux_regs[],
	const struct dce110_i2c_hw_engine_registers i2c_hw_engine_regs[],
	const struct dce110_i2c_hw_engine_shift *i2c_shift,
	const struct dce110_i2c_hw_engine_mask *i2c_mask)
{
	uint32_t i = 0;
	uint32_t reference_frequency = 0;
	bool use_i2c_sw_engine = false;
	struct i2caux *base = NULL;
	/*TODO: For CZ bring up, if dal_i2caux_get_reference_clock
	 * does not return 48KHz, we need hard coded for 48Khz.
	 * Some BIOS setting incorrect cause this
	 * For production, we always get value from BIOS*/
	reference_frequency =
		dal_i2caux_get_reference_clock(ctx->dc_bios) >> 1;

	base = &i2caux_dce110->base;

	dal_i2caux_construct(base, ctx);

	i2caux_dce110->base.funcs = &i2caux_funcs;
	i2caux_dce110->i2c_hw_buffer_in_use = false;
	/* Create I2C engines (DDC lines per connector)
	 * different I2C/AUX usage cases, DDC, Generic GPIO, AUX.
	 */
	do {
		enum gpio_ddc_line line_id = hw_ddc_lines[i];

		struct i2c_hw_engine_dce110_create_arg hw_arg_dce110;

		if (use_i2c_sw_engine) {
			struct i2c_sw_engine_dce110_create_arg sw_arg;

			sw_arg.engine_id = i;
			sw_arg.default_speed = base->default_i2c_sw_speed;
			sw_arg.ctx = ctx;
			base->i2c_sw_engines[line_id] =
				dal_i2c_sw_engine_dce110_create(&sw_arg);
		}

		hw_arg_dce110.engine_id = i;
		hw_arg_dce110.reference_frequency = reference_frequency;
		hw_arg_dce110.default_speed = base->default_i2c_hw_speed;
		hw_arg_dce110.ctx = ctx;
		hw_arg_dce110.regs = &i2c_hw_engine_regs[i];
		hw_arg_dce110.i2c_shift = i2c_shift;
		hw_arg_dce110.i2c_mask = i2c_mask;

		base->i2c_hw_engines[line_id] =
			dal_i2c_hw_engine_dce110_create(&hw_arg_dce110);
		if (base->i2c_hw_engines[line_id] != NULL) {
			switch (ctx->dce_version) {
			case DCN_VERSION_1_0:
				base->i2c_hw_engines[line_id]->setup_limit =
					I2C_SETUP_TIME_LIMIT_DCN;
				base->i2c_hw_engines[line_id]->send_reset_length  = 0;
			break;
			default:
				base->i2c_hw_engines[line_id]->setup_limit =
					I2C_SETUP_TIME_LIMIT_DCE;
				base->i2c_hw_engines[line_id]->send_reset_length  = 0;
				break;
			}
		}
		++i;
	} while (i < num_i2caux_inst);

	/* Create AUX engines for all lines which has assisted HW AUX
	 * 'i' (loop counter) used as DDC/AUX engine_id */

	i = 0;

	do {
		enum gpio_ddc_line line_id = hw_aux_lines[i];

		struct aux_engine_dce110_init_data aux_init_data;

		aux_init_data.engine_id = i;
		aux_init_data.timeout_period = base->aux_timeout_period;
		aux_init_data.ctx = ctx;
		aux_init_data.regs = &aux_regs[i];

		base->aux_engines[line_id] =
			dal_aux_engine_dce110_create(&aux_init_data);

		++i;
	} while (i < num_i2caux_inst);

	/*TODO Generic I2C SW and HW*/
}

struct i2caux *dal_i2caux_dce110_create(
	struct dc_context *ctx)
{
	struct i2caux_dce110 *i2caux_dce110 =
		kzalloc(sizeof(struct i2caux_dce110), GFP_KERNEL);

	if (!i2caux_dce110) {
		ASSERT_CRITICAL(false);
		return NULL;
	}

	dal_i2caux_dce110_construct(i2caux_dce110,
				    ctx,
				    ARRAY_SIZE(dce110_aux_regs),
				    dce110_aux_regs,
				    i2c_hw_engine_regs,
				    &i2c_shift,
				    &i2c_mask);
	return &i2caux_dce110->base;
}

