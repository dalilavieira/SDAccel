#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_4__ ;
typedef  struct TYPE_31__   TYPE_3__ ;
typedef  struct TYPE_30__   TYPE_2__ ;
typedef  struct TYPE_29__   TYPE_23__ ;
typedef  struct TYPE_28__   TYPE_1__ ;
typedef  struct TYPE_27__   TYPE_12__ ;

/* Type definitions */
struct TYPE_28__ {int /*<<< orphan*/ * scalar; } ;
struct TYPE_30__ {int type; TYPE_1__ data; } ;
typedef  TYPE_2__ yoml_t ;
struct TYPE_29__ {int (* enter ) (int /*<<< orphan*/ *,TYPE_3__*,TYPE_2__*) ;int (* exit ) (int /*<<< orphan*/ *,TYPE_3__*,TYPE_2__*) ;} ;
struct st_h2o_access_log_configurator_t {TYPE_23__ super; TYPE_12__* _handles_stack; TYPE_12__* handles; } ;
typedef  int /*<<< orphan*/  h2o_globalconf_t ;
typedef  int /*<<< orphan*/  h2o_configurator_t ;
struct TYPE_31__ {int /*<<< orphan*/ * pathconf; int /*<<< orphan*/  dry_run; } ;
typedef  TYPE_3__ h2o_configurator_context_t ;
struct TYPE_32__ {scalar_t__ configurator; } ;
typedef  TYPE_4__ h2o_configurator_command_t ;
typedef  int /*<<< orphan*/  h2o_access_log_filehandle_t ;
struct TYPE_27__ {int size; int /*<<< orphan*/ ** entries; } ;

/* Variables and functions */
 int /*<<< orphan*/  H2O_CONFIGURATOR_FLAG_ALL_LEVELS ; 
 int H2O_LOGCONF_ESCAPE_APACHE ; 
 int H2O_LOGCONF_ESCAPE_JSON ; 
#define  YOML_TYPE_MAPPING 129 
#define  YOML_TYPE_SCALAR 128 
 int /*<<< orphan*/  free (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/ * h2o_access_log_open_handle (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_access_log_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ h2o_configurator_create (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_configurator_define_command (TYPE_23__*,char*,int /*<<< orphan*/ ,int (*) (TYPE_4__*,TYPE_3__*,TYPE_2__*)) ; 
 int /*<<< orphan*/  h2o_configurator_errprintf (TYPE_4__*,TYPE_2__*,char*) ; 
 int h2o_configurator_get_one_of (TYPE_4__*,TYPE_2__*,char*) ; 
 int /*<<< orphan*/  h2o_configurator_parse_mapping (TYPE_4__*,TYPE_2__*,char*,char*,TYPE_2__***,TYPE_2__***,TYPE_2__***) ; 
 int /*<<< orphan*/  h2o_mem_addref_shared (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  h2o_mem_release_shared (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  h2o_vector_reserve (int /*<<< orphan*/ *,TYPE_12__*,int) ; 
 int /*<<< orphan*/  memset (TYPE_12__*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int on_config(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_access_log_configurator_t *self = (void *)cmd->configurator;
    yoml_t **path, **format = NULL, **escape_node = NULL;
    int escape = H2O_LOGCONF_ESCAPE_APACHE;
    h2o_access_log_filehandle_t *fh;

    switch (node->type) {
    case YOML_TYPE_SCALAR:
        path = &node;
        break;
    case YOML_TYPE_MAPPING:
        if (h2o_configurator_parse_mapping(cmd, node, "path:s", "format:s,escape:*", &path, &format, &escape_node) != 0)
            return -1;
        break;
    default:
        h2o_configurator_errprintf(cmd, node, "node must be a scalar or a mapping");
        return -1;
    }

    if (escape_node != NULL) {
        switch (h2o_configurator_get_one_of(cmd, *escape_node, "apache,json")) {
        case 0:
            escape = H2O_LOGCONF_ESCAPE_APACHE;
            break;
        case 1:
            escape = H2O_LOGCONF_ESCAPE_JSON;
            break;
        default:
            return -1;
        }
    }

    if (!ctx->dry_run) {
        if ((fh = h2o_access_log_open_handle((*path)->data.scalar, format != NULL ? (*format)->data.scalar : NULL, escape)) == NULL)
            return -1;
        h2o_vector_reserve(NULL, self->handles, self->handles->size + 1);
        self->handles->entries[self->handles->size++] = fh;
    }

    return 0;
}

__attribute__((used)) static int on_config_enter(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_access_log_configurator_t *self = (void *)_self;
    size_t i;

    /* push the stack pointer */
    ++self->handles;

    /* link the handles */
    memset(self->handles, 0, sizeof(*self->handles));
    h2o_vector_reserve(NULL, self->handles, self->handles[-1].size + 1);
    for (i = 0; i != self->handles[-1].size; ++i) {
        h2o_access_log_filehandle_t *fh = self->handles[-1].entries[i];
        self->handles[0].entries[self->handles[0].size++] = fh;
        h2o_mem_addref_shared(fh);
    }

    return 0;
}

__attribute__((used)) static int on_config_exit(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_access_log_configurator_t *self = (void *)_self;
    size_t i;

    /* register all handles, and decref them */
    for (i = 0; i != self->handles->size; ++i) {
        h2o_access_log_filehandle_t *fh = self->handles->entries[i];
        if (ctx->pathconf != NULL)
            h2o_access_log_register(ctx->pathconf, fh);
        h2o_mem_release_shared(fh);
    }
    /* free the vector */
    free(self->handles->entries);

    /* pop the stack pointer */
    --self->handles;

    return 0;
}

void h2o_access_log_register_configurator(h2o_globalconf_t *conf)
{
    struct st_h2o_access_log_configurator_t *self = (void *)h2o_configurator_create(conf, sizeof(*self));

    self->super.enter = on_config_enter;
    self->super.exit = on_config_exit;
    self->handles = self->_handles_stack;

    h2o_configurator_define_command(&self->super, "access-log", H2O_CONFIGURATOR_FLAG_ALL_LEVELS, on_config);
}

