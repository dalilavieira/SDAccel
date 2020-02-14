#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  yoml_t ;
struct TYPE_13__ {int (* enter ) (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ;int (* exit ) (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ;} ;
struct st_status_configurator {int duration_stats; TYPE_10__ super; int /*<<< orphan*/  stack; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  h2o_globalconf_t ;
typedef  int /*<<< orphan*/  h2o_configurator_t ;
struct TYPE_14__ {int /*<<< orphan*/  globalconf; int /*<<< orphan*/  pathconf; } ;
typedef  TYPE_1__ h2o_configurator_context_t ;
struct TYPE_15__ {scalar_t__ configurator; } ;
typedef  TYPE_2__ h2o_configurator_command_t ;

/* Variables and functions */
 int H2O_CONFIGURATOR_FLAG_DEFERRED ; 
 int H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR ; 
 int H2O_CONFIGURATOR_FLAG_GLOBAL ; 
 int H2O_CONFIGURATOR_FLAG_PATH ; 
 scalar_t__ h2o_configurator_create (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_configurator_define_command (TYPE_10__*,char*,int,int (*) (TYPE_2__*,TYPE_1__*,int /*<<< orphan*/ *)) ; 
 int h2o_configurator_get_one_of (TYPE_2__*,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  h2o_duration_stats_register (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  h2o_status_register (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int on_config_status(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    switch (h2o_configurator_get_one_of(cmd, node, "OFF,ON")) {
    case 0: /* OFF */
        return 0;
    case 1: /* ON */
        h2o_status_register(ctx->pathconf);
        return 0;
    default: /* error */
        return -1;
    }
}

__attribute__((used)) static int on_config_duration_stats(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_status_configurator *c = (void *)cmd->configurator;
    ssize_t ret;
    switch (ret = h2o_configurator_get_one_of(cmd, node, "OFF,ON")) {
    case 0: /* OFF */
    case 1: /* ON */
        c->duration_stats = (int)ret;
        return 0;
    default: /* error */
        return -1;
    }
}

int on_enter_status(h2o_configurator_t *_conf, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_status_configurator *c = (void *)_conf;
    c->stack++;
    return 0;
}

int on_exit_status(h2o_configurator_t *_conf, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_status_configurator *c = (void *)_conf;
    c->stack--;
    if (!c->stack && c->duration_stats) {
        h2o_duration_stats_register(ctx->globalconf);
    }
    return 0;
}

void h2o_status_register_configurator(h2o_globalconf_t *conf)
{
    struct st_status_configurator *c = (void *)h2o_configurator_create(conf, sizeof(*c));
    c->super.enter = on_enter_status;
    c->super.exit = on_exit_status;

    h2o_configurator_define_command(
        &c->super, "status", H2O_CONFIGURATOR_FLAG_PATH | H2O_CONFIGURATOR_FLAG_DEFERRED | H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR,
        on_config_status);

    h2o_configurator_define_command(&c->super, "duration-stats", H2O_CONFIGURATOR_FLAG_GLOBAL | H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR,
                                    on_config_duration_stats);
}

