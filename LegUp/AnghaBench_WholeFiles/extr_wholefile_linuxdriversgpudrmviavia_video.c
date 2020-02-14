#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_6__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct drm_file {int dummy; } ;
struct drm_device {scalar_t__ dev_private; } ;
typedef  int /*<<< orphan*/  drm_via_sarea_t ;
struct TYPE_7__ {int /*<<< orphan*/ * decoder_queue; int /*<<< orphan*/ * sarea_priv; } ;
typedef  TYPE_1__ drm_via_private_t ;
struct TYPE_8__ {unsigned int lock; int func; int ms; int volatile val; } ;
typedef  TYPE_2__ drm_via_futex_t ;
struct TYPE_9__ {scalar_t__ lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG (char*) ; 
 int /*<<< orphan*/  DRM_WAIT_ON (int,int /*<<< orphan*/ ,int,int) ; 
 int EFAULT ; 
 int HZ ; 
#define  VIA_FUTEX_WAIT 129 
#define  VIA_FUTEX_WAKE 128 
 unsigned int VIA_NR_XVMC_LOCKS ; 
 TYPE_6__* XVMCLOCKPTR (int /*<<< orphan*/ *,unsigned int) ; 
 int _DRM_LOCKING_CONTEXT (int volatile) ; 
 int volatile _DRM_LOCK_CONT ; 
 scalar_t__ _DRM_LOCK_IS_HELD (int volatile) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

void via_init_futex(drm_via_private_t *dev_priv)
{
	unsigned int i;

	DRM_DEBUG("\n");

	for (i = 0; i < VIA_NR_XVMC_LOCKS; ++i) {
		init_waitqueue_head(&(dev_priv->decoder_queue[i]));
		XVMCLOCKPTR(dev_priv->sarea_priv, i)->lock = 0;
	}
}

void via_cleanup_futex(drm_via_private_t *dev_priv)
{
}

void via_release_futex(drm_via_private_t *dev_priv, int context)
{
	unsigned int i;
	volatile int *lock;

	if (!dev_priv->sarea_priv)
		return;

	for (i = 0; i < VIA_NR_XVMC_LOCKS; ++i) {
		lock = (volatile int *)XVMCLOCKPTR(dev_priv->sarea_priv, i);
		if ((_DRM_LOCKING_CONTEXT(*lock) == context)) {
			if (_DRM_LOCK_IS_HELD(*lock)
			    && (*lock & _DRM_LOCK_CONT)) {
				wake_up(&(dev_priv->decoder_queue[i]));
			}
			*lock = 0;
		}
	}
}

int via_decoder_futex(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
	drm_via_futex_t *fx = data;
	volatile int *lock;
	drm_via_private_t *dev_priv = (drm_via_private_t *) dev->dev_private;
	drm_via_sarea_t *sAPriv = dev_priv->sarea_priv;
	int ret = 0;

	DRM_DEBUG("\n");

	if (fx->lock >= VIA_NR_XVMC_LOCKS)
		return -EFAULT;

	lock = (volatile int *)XVMCLOCKPTR(sAPriv, fx->lock);

	switch (fx->func) {
	case VIA_FUTEX_WAIT:
		DRM_WAIT_ON(ret, dev_priv->decoder_queue[fx->lock],
			    (fx->ms / 10) * (HZ / 100), *lock != fx->val);
		return ret;
	case VIA_FUTEX_WAKE:
		wake_up(&(dev_priv->decoder_queue[fx->lock]));
		return 0;
	}
	return 0;
}

