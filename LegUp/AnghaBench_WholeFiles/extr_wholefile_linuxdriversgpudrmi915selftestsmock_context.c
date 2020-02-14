#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct intel_context {struct i915_gem_context* gem_context; } ;
struct i915_gem_context {int hw_id; int /*<<< orphan*/  ppgtt; int /*<<< orphan*/  name; struct intel_context* __engine; int /*<<< orphan*/  handles_list; int /*<<< orphan*/  handles_vma; struct drm_i915_private* i915; int /*<<< orphan*/  link; int /*<<< orphan*/  ref; } ;
struct TYPE_4__ {int /*<<< orphan*/  struct_mutex; } ;
struct TYPE_3__ {int /*<<< orphan*/  free_list; int /*<<< orphan*/  free_work; int /*<<< orphan*/  hw_ida; int /*<<< orphan*/  list; } ;
struct drm_i915_private {TYPE_2__ drm; TYPE_1__ contexts; } ;
struct drm_file {int /*<<< orphan*/  driver_priv; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct intel_context*) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I915_PRIORITY_NORMAL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  INIT_RADIX_TREE (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  INIT_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX_CONTEXT_HW_ID ; 
 int /*<<< orphan*/  context_close (struct i915_gem_context*) ; 
 int /*<<< orphan*/  contexts_free_worker ; 
 struct i915_gem_context* i915_gem_context_create_kernel (struct drm_i915_private*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i915_gem_context_put (struct i915_gem_context*) ; 
 int /*<<< orphan*/  i915_gem_context_set_closed (struct i915_gem_context*) ; 
 struct i915_gem_context* i915_gem_create_context (struct drm_i915_private*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ida_init (int /*<<< orphan*/ *) ; 
 int ida_simple_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_llist_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct i915_gem_context*) ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kstrdup (char const*,int /*<<< orphan*/ ) ; 
 struct i915_gem_context* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mock_ppgtt (struct drm_i915_private*,char const*) ; 

struct i915_gem_context *
mock_context(struct drm_i915_private *i915,
	     const char *name)
{
	struct i915_gem_context *ctx;
	unsigned int n;
	int ret;

	ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return NULL;

	kref_init(&ctx->ref);
	INIT_LIST_HEAD(&ctx->link);
	ctx->i915 = i915;

	INIT_RADIX_TREE(&ctx->handles_vma, GFP_KERNEL);
	INIT_LIST_HEAD(&ctx->handles_list);

	for (n = 0; n < ARRAY_SIZE(ctx->__engine); n++) {
		struct intel_context *ce = &ctx->__engine[n];

		ce->gem_context = ctx;
	}

	ret = ida_simple_get(&i915->contexts.hw_ida,
			     0, MAX_CONTEXT_HW_ID, GFP_KERNEL);
	if (ret < 0)
		goto err_handles;
	ctx->hw_id = ret;

	if (name) {
		ctx->name = kstrdup(name, GFP_KERNEL);
		if (!ctx->name)
			goto err_put;

		ctx->ppgtt = mock_ppgtt(i915, name);
		if (!ctx->ppgtt)
			goto err_put;
	}

	return ctx;

err_handles:
	kfree(ctx);
	return NULL;

err_put:
	i915_gem_context_set_closed(ctx);
	i915_gem_context_put(ctx);
	return NULL;
}

void mock_context_close(struct i915_gem_context *ctx)
{
	context_close(ctx);
}

void mock_init_contexts(struct drm_i915_private *i915)
{
	INIT_LIST_HEAD(&i915->contexts.list);
	ida_init(&i915->contexts.hw_ida);

	INIT_WORK(&i915->contexts.free_work, contexts_free_worker);
	init_llist_head(&i915->contexts.free_list);
}

struct i915_gem_context *
live_context(struct drm_i915_private *i915, struct drm_file *file)
{
	lockdep_assert_held(&i915->drm.struct_mutex);

	return i915_gem_create_context(i915, file->driver_priv);
}

struct i915_gem_context *
kernel_context(struct drm_i915_private *i915)
{
	return i915_gem_context_create_kernel(i915, I915_PRIORITY_NORMAL);
}

void kernel_context_close(struct i915_gem_context *ctx)
{
	context_close(ctx);
}

