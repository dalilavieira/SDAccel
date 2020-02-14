#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_4__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  yoml_t ;
struct TYPE_6__ {int (* enter ) (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ;int (* exit ) (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ;} ;
struct headers_configurator_t {int /*<<< orphan*/ ** _cmd_stack; int /*<<< orphan*/ ** cmds; TYPE_4__ super; } ;
typedef  int /*<<< orphan*/  h2o_headers_command_t ;
typedef  int /*<<< orphan*/  h2o_globalconf_t ;
typedef  int /*<<< orphan*/  h2o_configurator_t ;
struct TYPE_5__ {int /*<<< orphan*/ * pathconf; } ;
typedef  TYPE_1__ h2o_configurator_context_t ;

/* Variables and functions */
 scalar_t__ h2o_configurator_create (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_configurator_define_headers_commands (int /*<<< orphan*/ *,TYPE_4__*,char*,int /*<<< orphan*/ ** (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  h2o_headers_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  h2o_mem_addref_shared (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  h2o_mem_release_shared (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int on_config_enter(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct headers_configurator_t *self = (void *)_self;

    self->cmds[1] = self->cmds[0];
    if (self->cmds[1] != NULL)
        h2o_mem_addref_shared(self->cmds[1]);

    ++self->cmds;
    return 0;
}

__attribute__((used)) static int on_config_exit(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct headers_configurator_t *self = (void *)_self;

    if (ctx->pathconf != NULL && *self->cmds != NULL) {
        if (*self->cmds != NULL)
            h2o_mem_addref_shared(*self->cmds);
        h2o_headers_register(ctx->pathconf, *self->cmds);
    }

    if (*self->cmds != NULL)
        h2o_mem_release_shared(*self->cmds);
    --self->cmds;
    return 0;
}

__attribute__((used)) static h2o_headers_command_t **get_headers_commands(h2o_configurator_t *_self)
{
    struct headers_configurator_t *self = (void *)_self;
    return self->cmds;
}

void h2o_headers_register_configurator(h2o_globalconf_t *conf)
{
    struct headers_configurator_t *c = (void *)h2o_configurator_create(conf, sizeof(*c));

    c->super.enter = on_config_enter;
    c->super.exit = on_config_exit;

    h2o_configurator_define_headers_commands(conf, &c->super, "header", get_headers_commands);
    c->cmds = c->_cmd_stack;
}

