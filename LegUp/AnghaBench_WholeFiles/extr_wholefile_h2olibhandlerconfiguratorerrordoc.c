#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_41__   TYPE_6__ ;
typedef  struct TYPE_40__   TYPE_5__ ;
typedef  struct TYPE_39__   TYPE_4__ ;
typedef  struct TYPE_38__   TYPE_3__ ;
typedef  struct TYPE_37__   TYPE_30__ ;
typedef  struct TYPE_36__   TYPE_2__ ;
typedef  struct TYPE_35__   TYPE_1__ ;
typedef  struct TYPE_34__   TYPE_17__ ;

/* Type definitions */
struct TYPE_35__ {size_t size; TYPE_3__** elements; } ;
struct TYPE_36__ {TYPE_1__ sequence; int /*<<< orphan*/  scalar; } ;
struct TYPE_38__ {int type; TYPE_2__ data; } ;
typedef  TYPE_3__ yoml_t ;
struct TYPE_37__ {int (* enter ) (int /*<<< orphan*/ *,TYPE_5__*,TYPE_3__*) ;int (* exit ) (int /*<<< orphan*/ *,TYPE_5__*,TYPE_3__*) ;} ;
struct errordoc_configurator_t {TYPE_30__ super; TYPE_17__* _vars_stack; TYPE_17__* vars; int /*<<< orphan*/  pool; } ;
typedef  int /*<<< orphan*/  h2o_iovec_t ;
typedef  int /*<<< orphan*/  h2o_globalconf_t ;
struct TYPE_39__ {int status; int /*<<< orphan*/  url; } ;
typedef  TYPE_4__ h2o_errordoc_t ;
typedef  int /*<<< orphan*/  h2o_configurator_t ;
struct TYPE_40__ {int /*<<< orphan*/ * pathconf; } ;
typedef  TYPE_5__ h2o_configurator_context_t ;
struct TYPE_41__ {scalar_t__ configurator; } ;
typedef  TYPE_6__ h2o_configurator_command_t ;
struct TYPE_34__ {int size; TYPE_4__* entries; } ;

/* Variables and functions */
 int /*<<< orphan*/  H2O_CONFIGURATOR_FLAG_ALL_LEVELS ; 
 int /*<<< orphan*/  SIZE_MAX ; 
#define  YOML_TYPE_MAPPING 130 
#define  YOML_TYPE_SCALAR 129 
#define  YOML_TYPE_SEQUENCE 128 
 int* alloca (int) ; 
 scalar_t__ h2o_configurator_create (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_configurator_define_command (TYPE_30__*,char*,int /*<<< orphan*/ ,int (*) (TYPE_6__*,TYPE_5__*,TYPE_3__*)) ; 
 int /*<<< orphan*/  h2o_configurator_errprintf (TYPE_6__*,TYPE_3__*,char*,...) ; 
 scalar_t__ h2o_configurator_parse_mapping (TYPE_6__*,TYPE_3__*,char*,int /*<<< orphan*/ *,TYPE_3__***,TYPE_3__***) ; 
 scalar_t__ h2o_configurator_scanf (TYPE_6__*,TYPE_3__*,char*,int*) ; 
 int /*<<< orphan*/  h2o_errordoc_register (int /*<<< orphan*/ *,TYPE_4__*,scalar_t__) ; 
 int /*<<< orphan*/  h2o_mem_clear_pool (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  h2o_mem_init_pool (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  h2o_memcpy (TYPE_4__*,TYPE_4__*,int) ; 
 int /*<<< orphan*/  h2o_strdup (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  h2o_vector_reserve (int /*<<< orphan*/ *,TYPE_17__*,int) ; 
 int /*<<< orphan*/  memset (TYPE_17__*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int register_errordoc(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *hash)
{
    struct errordoc_configurator_t *self = (void *)cmd->configurator;
    yoml_t **url_node, **status_nodes;
    size_t i, j, num_status;

    /* extract the nodes to handle */
    if (h2o_configurator_parse_mapping(cmd, hash, "url:s,status:*", NULL, &url_node, &status_nodes) != 0)
        return -1;
    switch ((*status_nodes)->type) {
    case YOML_TYPE_SCALAR:
        num_status = 1;
        break;
    case YOML_TYPE_SEQUENCE:
        if ((*status_nodes)->data.sequence.size == 0) {
            h2o_configurator_errprintf(cmd, *status_nodes, "status cannot be an empty sequence");
            return -1;
        }
        num_status = (*status_nodes)->data.sequence.size;
        status_nodes = (*status_nodes)->data.sequence.elements;
        break;
    default:
        h2o_configurator_errprintf(cmd, *status_nodes, "status must be a 3-digit scalar or a sequence of 3-digit scalars");
        return -1;
    }

    /* convert list of status_nodes (in string) to list of 3-digit codes */
    int *status_codes = alloca(sizeof(*status_codes) * num_status);
    for (i = 0; i != num_status; ++i) {
        if (h2o_configurator_scanf(cmd, status_nodes[i], "%d", &status_codes[i]) != 0)
            return -1;
        if (!(400 <= status_codes[i] && status_codes[i] <= 599)) {
            h2o_configurator_errprintf(cmd, status_nodes[i], "status must be within range of 400 to 599");
            return -1;
        }
        /* check the scanned status hasn't already appeared */
        for (j = 0; j != i; ++j) {
            if (status_codes[j] == status_codes[i]) {
                h2o_configurator_errprintf(cmd, status_nodes[i], "status %d appears multiple times", status_codes[i]);
                return -1;
            }
        }
    }

    h2o_iovec_t url = h2o_strdup(&self->pool, (*url_node)->data.scalar, SIZE_MAX);
    for (i = 0; i != num_status; ++i) {
        /* register */
        h2o_vector_reserve(&self->pool, self->vars, self->vars->size + 1);
        h2o_errordoc_t *errordoc = self->vars->entries + self->vars->size++;
        errordoc->status = status_codes[i];
        errordoc->url = url;
    }

    return 0;
}

__attribute__((used)) static int on_config_errordoc(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    switch (node->type) {
    case YOML_TYPE_SEQUENCE: {
        size_t i;
        for (i = 0; i != node->data.sequence.size; ++i) {
            yoml_t *e = node->data.sequence.elements[i];
            if (e->type != YOML_TYPE_MAPPING) {
                h2o_configurator_errprintf(cmd, e, "element must be a mapping");
                return -1;
            }
            if (register_errordoc(cmd, ctx, e) != 0)
                return -1;
        }
        return 0;
    }
    case YOML_TYPE_MAPPING:
        return register_errordoc(cmd, ctx, node);
    default:
        break;
    }

    h2o_configurator_errprintf(cmd, node, "argument must be either of: sequence, mapping");
    return -1;
}

__attribute__((used)) static int on_config_enter(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct errordoc_configurator_t *self = (void *)_self;

    if (self->vars == self->_vars_stack) {
        /* entering global level */
        h2o_mem_init_pool(&self->pool);
    }

    /* copy vars */
    memset(&self->vars[1], 0, sizeof(self->vars[1]));
    h2o_vector_reserve(&self->pool, &self->vars[1], self->vars[0].size);
    h2o_memcpy(self->vars[1].entries, self->vars[0].entries, sizeof(self->vars[0].entries[0]) * self->vars[0].size);
    self->vars[1].size = self->vars[0].size;

    ++self->vars;
    return 0;
}

__attribute__((used)) static int on_config_exit(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct errordoc_configurator_t *self = (void *)_self;

    if (ctx->pathconf != NULL && self->vars->size != 0)
        h2o_errordoc_register(ctx->pathconf, self->vars->entries, self->vars->size);

    --self->vars;
    if (self->vars == self->_vars_stack) {
        /* exitting global level */
        h2o_mem_clear_pool(&self->pool);
    }

    return 0;
}

void h2o_errordoc_register_configurator(h2o_globalconf_t *conf)
{
    struct errordoc_configurator_t *c = (void *)h2o_configurator_create(conf, sizeof(*c));

    /* set default vars */
    c->vars = c->_vars_stack;

    /* setup handlers */
    c->super.enter = on_config_enter;
    c->super.exit = on_config_exit;

    /* reproxy: ON | OFF */
    h2o_configurator_define_command(&c->super, "error-doc", H2O_CONFIGURATOR_FLAG_ALL_LEVELS, on_config_errordoc);
}

