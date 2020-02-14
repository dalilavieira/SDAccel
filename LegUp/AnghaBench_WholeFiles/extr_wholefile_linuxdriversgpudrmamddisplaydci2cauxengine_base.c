#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct engine {struct dc_context* ctx; int /*<<< orphan*/ * ddc; } ;
struct dc_context {int dummy; } ;

/* Variables and functions */

void dal_i2caux_construct_engine(
	struct engine *engine,
	struct dc_context *ctx)
{
	engine->ddc = NULL;
	engine->ctx = ctx;
}

void dal_i2caux_destruct_engine(
	struct engine *engine)
{
	/* nothing to do */
}

