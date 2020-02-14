#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_38__   TYPE_6__ ;
typedef  struct TYPE_37__   TYPE_5__ ;
typedef  struct TYPE_36__   TYPE_4__ ;
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_2__ ;
typedef  struct TYPE_33__   TYPE_27__ ;
typedef  struct TYPE_32__   TYPE_1__ ;

/* Type definitions */
struct TYPE_32__ {int /*<<< orphan*/  scalar; } ;
struct TYPE_34__ {TYPE_1__ data; scalar_t__ line; int /*<<< orphan*/  filename; } ;
typedef  TYPE_2__ yoml_t ;
struct TYPE_33__ {int (* enter ) (int /*<<< orphan*/ *,TYPE_5__*,TYPE_2__*) ;int (* exit ) (int /*<<< orphan*/ *,TYPE_5__*,TYPE_2__*) ;} ;
struct mruby_configurator_t {TYPE_27__ super; TYPE_3__* _vars_stack; TYPE_3__* vars; int /*<<< orphan*/ * mrb; } ;
struct RProc {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_state ;
struct TYPE_36__ {int len; scalar_t__ base; int /*<<< orphan*/ * member_0; } ;
struct TYPE_35__ {int lineno; TYPE_4__ source; int /*<<< orphan*/  path; } ;
typedef  TYPE_3__ h2o_mruby_config_vars_t ;
typedef  TYPE_4__ h2o_iovec_t ;
typedef  int /*<<< orphan*/  h2o_globalconf_t ;
typedef  int /*<<< orphan*/  h2o_configurator_t ;
struct TYPE_37__ {int /*<<< orphan*/ * parent; int /*<<< orphan*/  pathconf; } ;
typedef  TYPE_5__ h2o_configurator_context_t ;
struct TYPE_38__ {scalar_t__ configurator; } ;
typedef  TYPE_6__ h2o_configurator_command_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int H2O_CONFIGURATOR_FLAG_DEFERRED ; 
 int H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR ; 
 int H2O_CONFIGURATOR_FLAG_PATH ; 
 int /*<<< orphan*/  H2O_MRUBY_MODULE_NAME ; 
 int /*<<< orphan*/  SIZE_MAX ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  feof (int /*<<< orphan*/ *) ; 
 scalar_t__ ferror (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (int /*<<< orphan*/ ,char*) ; 
 int fread (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 scalar_t__ h2o_configurator_create (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_configurator_define_command (TYPE_27__*,char*,int,int (*) (TYPE_6__*,TYPE_5__*,TYPE_2__*)) ; 
 int /*<<< orphan*/  h2o_configurator_errprintf (TYPE_6__*,TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  h2o_fatal (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * h2o_mem_realloc (int /*<<< orphan*/ *,int) ; 
 struct RProc* h2o_mruby_compile_code (int /*<<< orphan*/ *,TYPE_3__*,char*) ; 
 int /*<<< orphan*/  h2o_mruby_register (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  h2o_mruby_setup_globals (int /*<<< orphan*/ *) ; 
 TYPE_4__ h2o_strdup (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (TYPE_3__*,TYPE_3__*,int) ; 
 int /*<<< orphan*/  mrb_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * mrb_open () ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int compile_test(mrb_state *mrb, h2o_mruby_config_vars_t *config, char *errbuf)
{
    struct RProc *result = h2o_mruby_compile_code(mrb, config, errbuf);
    return result != NULL;
}

__attribute__((used)) static mrb_state *get_mrb(struct mruby_configurator_t *self)
{
    if (self->mrb == NULL) {
        self->mrb = mrb_open();
        if (self->mrb == NULL) {
            h2o_fatal("%s: no memory\n", H2O_MRUBY_MODULE_NAME);
        }
        h2o_mruby_setup_globals(self->mrb);
    }
    return self->mrb;
}

__attribute__((used)) static int on_config_mruby_handler(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct mruby_configurator_t *self = (void *)cmd->configurator;

    /* set source */
    self->vars->source = h2o_strdup(NULL, node->data.scalar, SIZE_MAX);
    self->vars->path = node->filename;
    self->vars->lineno = (int)node->line + 1;

    /* check if there is any error in source */
    char errbuf[1024];
    if (!compile_test(get_mrb(self), self->vars, errbuf)) {
        h2o_configurator_errprintf(cmd, node, "ruby compile error:%s", errbuf);
        return -1;
    }

    /* register */
    h2o_mruby_register(ctx->pathconf, self->vars);

    return 0;
}

__attribute__((used)) static int on_config_mruby_handler_file(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct mruby_configurator_t *self = (void *)cmd->configurator;
    FILE *fp = NULL;
    h2o_iovec_t buf = {NULL};
    int ret = -1;

    /* open and read file */
    if ((fp = fopen(node->data.scalar, "rt")) == NULL) {
        h2o_configurator_errprintf(cmd, node, "failed to open file: %s:%s", node->data.scalar, strerror(errno));
        goto Exit;
    }
    while (!feof(fp)) {
        buf.base = h2o_mem_realloc(buf.base, buf.len + 65536);
        buf.len += fread(buf.base + buf.len, 1, 65536, fp);
        if (ferror(fp)) {
            h2o_configurator_errprintf(cmd, node, "I/O error occurred while reading file:%s:%s", node->data.scalar,
                                       strerror(errno));
            goto Exit;
        }
    }

    /* set source */
    self->vars->source = buf;
    buf.base = NULL;
    self->vars->path = node->data.scalar; /* the value is retained until the end of the configuration phase */
    self->vars->lineno = 0;

    /* check if there is any error in source */
    char errbuf[1024];
    if (!compile_test(get_mrb(self), self->vars, errbuf)) {
        h2o_configurator_errprintf(cmd, node, "failed to compile file:%s:%s", node->data.scalar, errbuf);
        goto Exit;
    }

    /* register */
    h2o_mruby_register(ctx->pathconf, self->vars);

    ret = 0;

Exit:
    if (fp != NULL)
        fclose(fp);
    if (buf.base != NULL)
        free(buf.base);
    return ret;
}

__attribute__((used)) static int on_config_mruby_handler_path(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    h2o_configurator_errprintf(cmd, node, "the command has been removed; see https://github.com/h2o/h2o/pull/467");
    return -1;
}

__attribute__((used)) static int on_config_enter(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct mruby_configurator_t *self = (void *)_self;

    memcpy(self->vars + 1, self->vars, sizeof(*self->vars));
    ++self->vars;
    return 0;
}

__attribute__((used)) static int on_config_exit(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct mruby_configurator_t *self = (void *)_self;

    /* free if the to-be-exitted frame level contains a different source */
    if (self->vars[-1].source.base != self->vars[0].source.base)
        free(self->vars->source.base);

    --self->vars;

    /* release mrb only when global configuration exited */
    if (self->mrb != NULL && ctx->parent == NULL) {
        mrb_close(self->mrb);
        self->mrb = NULL;
    }

    return 0;
}

void h2o_mruby_register_configurator(h2o_globalconf_t *conf)
{
    struct mruby_configurator_t *c = (void *)h2o_configurator_create(conf, sizeof(*c));

    c->vars = c->_vars_stack;
    c->super.enter = on_config_enter;
    c->super.exit = on_config_exit;

    h2o_configurator_define_command(
        &c->super, "mruby.handler",
        H2O_CONFIGURATOR_FLAG_PATH | H2O_CONFIGURATOR_FLAG_DEFERRED | H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR, on_config_mruby_handler);
    h2o_configurator_define_command(&c->super, "mruby.handler-file",
                                    H2O_CONFIGURATOR_FLAG_PATH | H2O_CONFIGURATOR_FLAG_DEFERRED |
                                        H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR,
                                    on_config_mruby_handler_file);
    h2o_configurator_define_command(&c->super, "mruby.handler_path", H2O_CONFIGURATOR_FLAG_PATH | H2O_CONFIGURATOR_FLAG_DEFERRED,
                                    on_config_mruby_handler_path);
}

