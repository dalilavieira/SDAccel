#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_9__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  yoml_t ;
struct TYPE_15__ {int (* enter ) (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ *) ;int (* exit ) (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ *) ;} ;
struct server_timing_configurator_t {TYPE_9__ super; TYPE_1__* _vars_stack; TYPE_1__* vars; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  h2o_globalconf_t ;
typedef  int /*<<< orphan*/  h2o_configurator_t ;
struct TYPE_13__ {int /*<<< orphan*/ * pathconf; } ;
typedef  TYPE_2__ h2o_configurator_context_t ;
struct TYPE_14__ {scalar_t__ configurator; } ;
typedef  TYPE_3__ h2o_configurator_command_t ;
struct TYPE_12__ {int mode; } ;

/* Variables and functions */
 int /*<<< orphan*/  H2O_CONFIGURATOR_FLAG_ALL_LEVELS ; 
 scalar_t__ SERVER_TIMING_MODE_ENFORCE ; 
 scalar_t__ SERVER_TIMING_MODE_OFF ; 
 scalar_t__ h2o_configurator_create (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_configurator_define_command (TYPE_9__*,char*,int /*<<< orphan*/ ,int (*) (TYPE_3__*,TYPE_2__*,int /*<<< orphan*/ *)) ; 
 int h2o_configurator_get_one_of (TYPE_3__*,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  h2o_server_timing_register (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int on_config_server_timing(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct server_timing_configurator_t *self = (void *)cmd->configurator;

    ssize_t ret = h2o_configurator_get_one_of(cmd, node, "OFF,ON,ENFORCE");
    if (ret == -1)
        return -1;
    self->vars->mode = (int)ret;

    return 0;
}

__attribute__((used)) static int on_config_enter(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct server_timing_configurator_t *self = (void *)_self;

    self->vars[1] = self->vars[0];
    ++self->vars;
    return 0;
}

__attribute__((used)) static int on_config_exit(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct server_timing_configurator_t *self = (void *)_self;

    if (ctx->pathconf != NULL && self->vars->mode != SERVER_TIMING_MODE_OFF)
        h2o_server_timing_register(ctx->pathconf, self->vars->mode == SERVER_TIMING_MODE_ENFORCE);

    --self->vars;
    return 0;
}

void h2o_server_timing_register_configurator(h2o_globalconf_t *conf)
{
    struct server_timing_configurator_t *c = (void *)h2o_configurator_create(conf, sizeof(*c));

    /* set default vars */
    c->vars = c->_vars_stack;

    /* setup handlers */
    c->super.enter = on_config_enter;
    c->super.exit = on_config_exit;

    /* server_timing: ON | OFF */
    h2o_configurator_define_command(&c->super, "server-timing", H2O_CONFIGURATOR_FLAG_ALL_LEVELS, on_config_server_timing);
}

