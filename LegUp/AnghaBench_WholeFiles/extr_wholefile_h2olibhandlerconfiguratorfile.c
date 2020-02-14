#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_43__   TYPE_6__ ;
typedef  struct TYPE_42__   TYPE_5__ ;
typedef  struct TYPE_41__   TYPE_4__ ;
typedef  struct TYPE_40__   TYPE_3__ ;
typedef  struct TYPE_39__   TYPE_33__ ;
typedef  struct TYPE_38__   TYPE_2__ ;
typedef  struct TYPE_37__   TYPE_1__ ;

/* Type definitions */
struct TYPE_37__ {int size; TYPE_4__** elements; } ;
struct TYPE_38__ {char* scalar; TYPE_1__ sequence; } ;
struct TYPE_41__ {scalar_t__ type; TYPE_2__ data; } ;
typedef  TYPE_4__ yoml_t ;
struct TYPE_39__ {int (* enter ) (int /*<<< orphan*/ *,TYPE_5__*,TYPE_4__*) ;int (* exit ) (int /*<<< orphan*/ *,TYPE_5__*,TYPE_4__*) ;} ;
struct st_h2o_file_configurator_t {TYPE_33__ super; TYPE_3__* vars; TYPE_3__* _vars_stack; } ;
typedef  int /*<<< orphan*/  h2o_mimemap_type_t ;
typedef  int /*<<< orphan*/  h2o_globalconf_t ;
typedef  int /*<<< orphan*/  h2o_configurator_t ;
struct TYPE_42__ {int /*<<< orphan*/  pathconf; int /*<<< orphan*/ * mimemap; } ;
typedef  TYPE_5__ h2o_configurator_context_t ;
struct TYPE_43__ {scalar_t__ configurator; } ;
typedef  TYPE_6__ h2o_configurator_command_t ;
struct TYPE_40__ {char** index_files; int flags; } ;

/* Variables and functions */
 int H2O_CONFIGURATOR_FLAG_ALL_LEVELS ; 
 int H2O_CONFIGURATOR_FLAG_DEFERRED ; 
 int H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR ; 
 int H2O_CONFIGURATOR_FLAG_EXPECT_SEQUENCE ; 
 int H2O_CONFIGURATOR_FLAG_EXTENSION ; 
 int H2O_CONFIGURATOR_FLAG_PATH ; 
 int H2O_FILE_FLAG_DIR_LISTING ; 
 int H2O_FILE_FLAG_GUNZIP ; 
 int H2O_FILE_FLAG_NO_ETAG ; 
 int H2O_FILE_FLAG_SEND_COMPRESSED ; 
 scalar_t__ YOML_TYPE_SCALAR ; 
 int /*<<< orphan*/  free (char**) ; 
 scalar_t__ h2o_configurator_create (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_configurator_define_command (TYPE_33__*,char*,int,int (*) (TYPE_6__*,TYPE_5__*,TYPE_4__*)) ; 
 int /*<<< orphan*/  h2o_configurator_errprintf (TYPE_6__*,TYPE_4__*,char*) ; 
 int h2o_configurator_get_one_of (TYPE_6__*,TYPE_4__*,char*) ; 
 char** h2o_file_default_index_files ; 
 int /*<<< orphan*/  h2o_file_register (int /*<<< orphan*/ ,char*,char**,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  h2o_file_register_file (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_get_filext (char*,int /*<<< orphan*/ ) ; 
 void* h2o_mem_alloc (int) ; 
 int /*<<< orphan*/ * h2o_mimemap_get_type_by_extension (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char*) ; 

__attribute__((used)) static int on_config_dir(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_file_configurator_t *self = (void *)cmd->configurator;

    h2o_file_register(ctx->pathconf, node->data.scalar, self->vars->index_files, *ctx->mimemap, self->vars->flags);
    return 0;
}

__attribute__((used)) static int on_config_file(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_file_configurator_t *self = (void *)cmd->configurator;
    h2o_mimemap_type_t *mime_type =
        h2o_mimemap_get_type_by_extension(*ctx->mimemap, h2o_get_filext(node->data.scalar, strlen(node->data.scalar)));
    h2o_file_register_file(ctx->pathconf, node->data.scalar, mime_type, self->vars->flags);
    return 0;
}

__attribute__((used)) static int on_config_index(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_file_configurator_t *self = (void *)cmd->configurator;
    size_t i;

    free(self->vars->index_files);
    self->vars->index_files = h2o_mem_alloc(sizeof(self->vars->index_files[0]) * (node->data.sequence.size + 1));
    for (i = 0; i != node->data.sequence.size; ++i) {
        yoml_t *element = node->data.sequence.elements[i];
        if (element->type != YOML_TYPE_SCALAR) {
            h2o_configurator_errprintf(cmd, element, "argument must be a sequence of scalars");
            return -1;
        }
        self->vars->index_files[i] = element->data.scalar;
    }
    self->vars->index_files[i] = NULL;

    return 0;
}

__attribute__((used)) static int on_config_etag(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_file_configurator_t *self = (void *)cmd->configurator;

    switch (h2o_configurator_get_one_of(cmd, node, "OFF,ON")) {
    case 0: /* off */
        self->vars->flags |= H2O_FILE_FLAG_NO_ETAG;
        break;
    case 1: /* on */
        self->vars->flags &= ~H2O_FILE_FLAG_NO_ETAG;
        break;
    default: /* error */
        return -1;
    }

    return 0;
}

__attribute__((used)) static int on_config_send_compressed(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_file_configurator_t *self = (void *)cmd->configurator;

    switch (h2o_configurator_get_one_of(cmd, node, "OFF,ON,gunzip")) {
    case 0: /* off */
        self->vars->flags &= ~H2O_FILE_FLAG_SEND_COMPRESSED;
        break;
    case 1: /* on */
        self->vars->flags |= H2O_FILE_FLAG_SEND_COMPRESSED;
        break;
    case 2: /* gunzip */
        self->vars->flags |= (H2O_FILE_FLAG_SEND_COMPRESSED | H2O_FILE_FLAG_GUNZIP);
        break;
    default: /* error */
        return -1;
    }

    return 0;
}

__attribute__((used)) static int on_config_dir_listing(h2o_configurator_command_t *cmd, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_file_configurator_t *self = (void *)cmd->configurator;

    switch (h2o_configurator_get_one_of(cmd, node, "OFF,ON")) {
    case 0: /* off */
        self->vars->flags &= ~H2O_FILE_FLAG_DIR_LISTING;
        break;
    case 1: /* on */
        self->vars->flags |= H2O_FILE_FLAG_DIR_LISTING;
        break;
    default: /* error */
        return -1;
    }

    return 0;
}

__attribute__((used)) static const char **dup_strlist(const char **s)
{
    size_t i;
    const char **ret;

    for (i = 0; s[i] != NULL; ++i)
        ;
    ret = h2o_mem_alloc(sizeof(*ret) * (i + 1));
    for (i = 0; s[i] != NULL; ++i)
        ret[i] = s[i];
    ret[i] = NULL;

    return ret;
}

__attribute__((used)) static int on_config_enter(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_file_configurator_t *self = (void *)_self;
    ++self->vars;
    self->vars[0].index_files = dup_strlist(self->vars[-1].index_files);
    self->vars[0].flags = self->vars[-1].flags;
    return 0;
}

__attribute__((used)) static int on_config_exit(h2o_configurator_t *_self, h2o_configurator_context_t *ctx, yoml_t *node)
{
    struct st_h2o_file_configurator_t *self = (void *)_self;
    free(self->vars->index_files);
    --self->vars;
    return 0;
}

void h2o_file_register_configurator(h2o_globalconf_t *globalconf)
{
    struct st_h2o_file_configurator_t *self = (void *)h2o_configurator_create(globalconf, sizeof(*self));

    self->super.enter = on_config_enter;
    self->super.exit = on_config_exit;
    self->vars = self->_vars_stack;
    self->vars->index_files = h2o_file_default_index_files;

    h2o_configurator_define_command(
        &self->super, "file.dir", H2O_CONFIGURATOR_FLAG_PATH | H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR | H2O_CONFIGURATOR_FLAG_DEFERRED,
        on_config_dir);
    h2o_configurator_define_command(
        &self->super, "file.file",
        H2O_CONFIGURATOR_FLAG_PATH | H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR | H2O_CONFIGURATOR_FLAG_DEFERRED, on_config_file);
    h2o_configurator_define_command(&self->super, "file.index",
                                    (H2O_CONFIGURATOR_FLAG_ALL_LEVELS & ~H2O_CONFIGURATOR_FLAG_EXTENSION) |
                                        H2O_CONFIGURATOR_FLAG_EXPECT_SEQUENCE,
                                    on_config_index);
    h2o_configurator_define_command(&self->super, "file.etag",
                                    (H2O_CONFIGURATOR_FLAG_ALL_LEVELS & ~H2O_CONFIGURATOR_FLAG_EXTENSION) |
                                        H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR,
                                    on_config_etag);
    h2o_configurator_define_command(&self->super, "file.send-compressed",
                                    (H2O_CONFIGURATOR_FLAG_ALL_LEVELS & ~H2O_CONFIGURATOR_FLAG_EXTENSION) |
                                        H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR,
                                    on_config_send_compressed);
    h2o_configurator_define_command(&self->super, "file.send-gzip",
                                    (H2O_CONFIGURATOR_FLAG_ALL_LEVELS & ~H2O_CONFIGURATOR_FLAG_EXTENSION) |
                                        H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR,
                                    on_config_send_compressed);
    h2o_configurator_define_command(&self->super, "file.dirlisting",
                                    (H2O_CONFIGURATOR_FLAG_ALL_LEVELS & ~H2O_CONFIGURATOR_FLAG_EXTENSION) |
                                        H2O_CONFIGURATOR_FLAG_EXPECT_SCALAR,
                                    on_config_dir_listing);
}

