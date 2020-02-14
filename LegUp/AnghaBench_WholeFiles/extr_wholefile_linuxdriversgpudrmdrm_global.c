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
struct drm_global_reference {size_t global_type; int (* init ) (struct drm_global_reference*) ;int /*<<< orphan*/  (* release ) (struct drm_global_reference*) ;int /*<<< orphan*/ * object; int /*<<< orphan*/  size; } ;
struct drm_global_item {scalar_t__ refcount; int /*<<< orphan*/  mutex; int /*<<< orphan*/ * object; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int DRM_GLOBAL_NUM ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct drm_global_item* glob ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kzalloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int stub1 (struct drm_global_reference*) ; 
 int /*<<< orphan*/  stub2 (struct drm_global_reference*) ; 
 scalar_t__ unlikely (int) ; 

void drm_global_init(void)
{
	int i;

	for (i = 0; i < DRM_GLOBAL_NUM; ++i) {
		struct drm_global_item *item = &glob[i];
		mutex_init(&item->mutex);
		item->object = NULL;
		item->refcount = 0;
	}
}

void drm_global_release(void)
{
	int i;
	for (i = 0; i < DRM_GLOBAL_NUM; ++i) {
		struct drm_global_item *item = &glob[i];
		BUG_ON(item->object != NULL);
		BUG_ON(item->refcount != 0);
	}
}

int drm_global_item_ref(struct drm_global_reference *ref)
{
	int ret = 0;
	struct drm_global_item *item = &glob[ref->global_type];

	mutex_lock(&item->mutex);
	if (item->refcount == 0) {
		ref->object = kzalloc(ref->size, GFP_KERNEL);
		if (unlikely(ref->object == NULL)) {
			ret = -ENOMEM;
			goto error_unlock;
		}
		ret = ref->init(ref);
		if (unlikely(ret != 0))
			goto error_free;

		item->object = ref->object;
	} else {
		ref->object = item->object;
	}

	++item->refcount;
	mutex_unlock(&item->mutex);
	return 0;

error_free:
	kfree(ref->object);
	ref->object = NULL;
error_unlock:
	mutex_unlock(&item->mutex);
	return ret;
}

void drm_global_item_unref(struct drm_global_reference *ref)
{
	struct drm_global_item *item = &glob[ref->global_type];

	mutex_lock(&item->mutex);
	BUG_ON(item->refcount == 0);
	BUG_ON(ref->object != item->object);
	if (--item->refcount == 0) {
		ref->release(ref);
		item->object = NULL;
	}
	mutex_unlock(&item->mutex);
}

