#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_4__ ;
typedef  struct TYPE_34__   TYPE_3__ ;
typedef  struct TYPE_33__   TYPE_2__ ;
typedef  struct TYPE_32__   TYPE_1__ ;

/* Type definitions */
struct st_h2o_mruby_channel_context_t {int /*<<< orphan*/  receivers; int /*<<< orphan*/ * ctx; } ;
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
struct TYPE_33__ {TYPE_3__* ud; } ;
typedef  TYPE_2__ mrb_state ;
struct TYPE_34__ {int /*<<< orphan*/  constants; TYPE_2__* mrb; int /*<<< orphan*/ * current_context; } ;
typedef  TYPE_3__ h2o_mruby_shared_context_t ;
struct TYPE_35__ {TYPE_1__* shared; } ;
typedef  TYPE_4__ h2o_mruby_context_t ;
struct TYPE_32__ {TYPE_2__* mrb; } ;

/* Variables and functions */
 int /*<<< orphan*/  E_ARGUMENT_ERROR ; 
 int /*<<< orphan*/  H2O_MRUBY_CHANNEL_CLASS ; 
 int /*<<< orphan*/  H2O_MRUBY_CODE_CHANNEL ; 
 int /*<<< orphan*/  MRB_ARGS_NONE () ; 
 int /*<<< orphan*/  MRB_SET_INSTANCE_TT (struct RClass*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MRB_TT_DATA ; 
 scalar_t__ RARRAY_LEN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  channel_type ; 
 int /*<<< orphan*/  free (struct st_h2o_mruby_channel_context_t*) ; 
 struct st_h2o_mruby_channel_context_t* h2o_mem_alloc (int) ; 
 int /*<<< orphan*/  h2o_mruby_assert (TYPE_2__*) ; 
 int /*<<< orphan*/  h2o_mruby_define_callback (TYPE_2__*,char*,int /*<<< orphan*/  (*) (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*)) ; 
 int /*<<< orphan*/  h2o_mruby_eval_expr_location (TYPE_2__*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  h2o_mruby_run_fiber (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (struct st_h2o_mruby_channel_context_t*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mrb_ary_entry (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_ary_new (TYPE_2__*) ; 
 int /*<<< orphan*/  mrb_ary_push (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_ary_set (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_ary_shift (TYPE_2__*,int /*<<< orphan*/ ) ; 
 struct RClass* mrb_class_get_under (TYPE_2__*,struct RClass*,char*) ; 
 struct st_h2o_mruby_channel_context_t* mrb_data_check_get_ptr (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct st_h2o_mruby_channel_context_t* mrb_data_get_ptr (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_data_init (int /*<<< orphan*/ ,struct st_h2o_mruby_channel_context_t*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_define_method (TYPE_2__*,struct RClass*,char*,int /*<<< orphan*/  (*) (TYPE_2__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ; 
 struct RClass* mrb_define_module (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  mrb_exc_new_str_lit (TYPE_2__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mrb_gc_arena_restore (TYPE_2__*,int) ; 
 int mrb_gc_arena_save (TYPE_2__*) ; 
 int /*<<< orphan*/  mrb_gc_protect (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_gc_register (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_gc_unregister (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_intern_lit (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  mrb_iv_set (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_nil_value () ; 
 int /*<<< orphan*/  mrb_obj_value (struct RClass*) ; 

__attribute__((used)) static void on_gc_dispose_channel(mrb_state *mrb, void *_ctx)
{
    struct st_h2o_mruby_channel_context_t *ctx = _ctx;
    assert(ctx != NULL); /* ctx can only be disposed by gc, so data binding has been never removed */
    mrb_gc_unregister(mrb, ctx->receivers);
    free(ctx);
}

__attribute__((used)) static mrb_value channel_initialize_method(mrb_state *mrb, mrb_value self)
{
    h2o_mruby_shared_context_t *shared_ctx = mrb->ud;

    struct st_h2o_mruby_channel_context_t *ctx;
    ctx = h2o_mem_alloc(sizeof(*ctx));

    memset(ctx, 0, sizeof(*ctx));
    assert(shared_ctx->current_context != NULL);
    ctx->ctx = shared_ctx->current_context;
    ctx->receivers = mrb_ary_new(mrb);
    mrb_gc_register(mrb, ctx->receivers);

    mrb_iv_set(mrb, self, mrb_intern_lit(mrb, "@queue"), mrb_ary_new(mrb));

    mrb_data_init(self, ctx, &channel_type);

    return self;
}

__attribute__((used)) static mrb_value channel_notify_method(mrb_state *mrb, mrb_value self)
{
    struct st_h2o_mruby_channel_context_t *ctx;
    ctx = mrb_data_get_ptr(mrb, self, &channel_type);

    if (RARRAY_LEN(ctx->receivers) != 0) {
        int gc_arena = mrb_gc_arena_save(mrb);
        mrb_value receiver = mrb_ary_shift(mrb, ctx->receivers);
        mrb_gc_protect(mrb, receiver);
        h2o_mruby_run_fiber(ctx->ctx, receiver, mrb_nil_value(), NULL);
        mrb_gc_arena_restore(mrb, gc_arena);
    }

    return mrb_nil_value();
}

__attribute__((used)) static mrb_value wait_callback(h2o_mruby_context_t *mctx, mrb_value input, mrb_value *receiver, mrb_value args, int *run_again)
{
    mrb_state *mrb = mctx->shared->mrb;

    struct st_h2o_mruby_channel_context_t *ctx;

    if ((ctx = mrb_data_check_get_ptr(mrb, mrb_ary_entry(args, 0), &channel_type)) == NULL)
        return mrb_exc_new_str_lit(mrb, E_ARGUMENT_ERROR, "Channel#shift wrong self");

    mrb_ary_push(mrb, ctx->receivers, *receiver);

    return mrb_nil_value();
}

void h2o_mruby_channel_init_context(h2o_mruby_shared_context_t *shared_ctx)
{
    mrb_state *mrb = shared_ctx->mrb;

    h2o_mruby_eval_expr_location(mrb, H2O_MRUBY_CODE_CHANNEL, "(h2o)lib/handler/mruby/embedded/channel.rb", 1);
    h2o_mruby_assert(mrb);

    struct RClass *module, *klass;
    module = mrb_define_module(mrb, "H2O");

    klass = mrb_class_get_under(mrb, module, "Channel");
    MRB_SET_INSTANCE_TT(klass, MRB_TT_DATA);
    mrb_ary_set(mrb, shared_ctx->constants, H2O_MRUBY_CHANNEL_CLASS, mrb_obj_value(klass));
    mrb_define_method(mrb, klass, "initialize", channel_initialize_method, MRB_ARGS_NONE());
    mrb_define_method(mrb, klass, "_notify", channel_notify_method, MRB_ARGS_NONE());
    h2o_mruby_define_callback(mrb, "_h2o__channel_wait", wait_callback);
}

