#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct i2c_sw_engine_dce110_create_arg {int /*<<< orphan*/  engine_id; int /*<<< orphan*/  default_speed; int /*<<< orphan*/  ctx; } ;
struct TYPE_4__ {int /*<<< orphan*/ * funcs; } ;
struct i2c_engine {int /*<<< orphan*/ * funcs; TYPE_1__ base; } ;
struct TYPE_5__ {struct i2c_engine base; int /*<<< orphan*/  default_speed; } ;
struct i2c_sw_engine_dce110 {TYPE_2__ base; int /*<<< orphan*/  engine_id; } ;
struct i2c_sw_engine_create_arg {int /*<<< orphan*/  default_speed; int /*<<< orphan*/  ctx; } ;
struct engine {int dummy; } ;
struct ddc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_CRITICAL (int) ; 
 struct i2c_sw_engine_dce110* FROM_I2C_ENGINE (struct i2c_engine*) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dal_i2c_sw_engine_construct (TYPE_2__*,struct i2c_sw_engine_create_arg*) ; 
 int /*<<< orphan*/  dal_i2c_sw_engine_destruct (TYPE_2__*) ; 
 int dal_i2caux_i2c_sw_engine_acquire_engine (struct i2c_engine*,struct ddc*) ; 
 int /*<<< orphan*/  engine_funcs ; 
 int /*<<< orphan*/  i2c_engine_funcs ; 
 int /*<<< orphan*/  kfree (struct i2c_sw_engine_dce110*) ; 
 struct i2c_sw_engine_dce110* kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void release_engine(
	struct engine *engine)
{
}

__attribute__((used)) static void destruct(
	struct i2c_sw_engine_dce110 *engine)
{
	dal_i2c_sw_engine_destruct(&engine->base);
}

__attribute__((used)) static void destroy(
	struct i2c_engine **engine)
{
	struct i2c_sw_engine_dce110 *sw_engine = FROM_I2C_ENGINE(*engine);

	destruct(sw_engine);

	kfree(sw_engine);

	*engine = NULL;
}

__attribute__((used)) static bool acquire_engine(
	struct i2c_engine *engine,
	struct ddc *ddc_handle)
{
	return dal_i2caux_i2c_sw_engine_acquire_engine(engine, ddc_handle);
}

__attribute__((used)) static void construct(
	struct i2c_sw_engine_dce110 *engine_dce110,
	const struct i2c_sw_engine_dce110_create_arg *arg_dce110)
{
	struct i2c_sw_engine_create_arg arg_base;

	arg_base.ctx = arg_dce110->ctx;
	arg_base.default_speed = arg_dce110->default_speed;

	dal_i2c_sw_engine_construct(&engine_dce110->base, &arg_base);

	/*struct engine   struct engine_funcs*/
	engine_dce110->base.base.base.funcs = &engine_funcs;
	/*struct i2c_engine  struct i2c_engine_funcs*/
	engine_dce110->base.base.funcs = &i2c_engine_funcs;
	engine_dce110->base.default_speed = arg_dce110->default_speed;
	engine_dce110->engine_id = arg_dce110->engine_id;
}

struct i2c_engine *dal_i2c_sw_engine_dce110_create(
	const struct i2c_sw_engine_dce110_create_arg *arg)
{
	struct i2c_sw_engine_dce110 *engine_dce110;

	if (!arg) {
		ASSERT_CRITICAL(false);
		return NULL;
	}

	engine_dce110 = kzalloc(sizeof(struct i2c_sw_engine_dce110),
				GFP_KERNEL);

	if (!engine_dce110) {
		ASSERT_CRITICAL(false);
		return NULL;
	}

	construct(engine_dce110, arg);
	return &engine_dce110->base.base;
}

