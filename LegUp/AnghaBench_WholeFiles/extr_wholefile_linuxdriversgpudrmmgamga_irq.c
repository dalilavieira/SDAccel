#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct drm_device {int irq_enabled; scalar_t__ dev_private; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_3__ {int /*<<< orphan*/  fence_queue; int /*<<< orphan*/  last_fence_retired; int /*<<< orphan*/  vbl_received; } ;
typedef  TYPE_1__ drm_mga_private_t ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_ERROR (char*,unsigned int) ; 
 int /*<<< orphan*/  DRM_WAIT_ON (int,int /*<<< orphan*/ ,int,int) ; 
 int HZ ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ MGA_ENDPRDMASTS ; 
 int MGA_ENGINE_IDLE_MASK ; 
 int /*<<< orphan*/  MGA_ICLEAR ; 
 int /*<<< orphan*/  MGA_IEN ; 
 int /*<<< orphan*/  MGA_PRIMADDRESS ; 
 int /*<<< orphan*/  MGA_PRIMEND ; 
 int MGA_READ (int /*<<< orphan*/ ) ; 
 int MGA_SOFTRAPEN ; 
 int MGA_SOFTRAPICLR ; 
 int /*<<< orphan*/  MGA_STATUS ; 
 int MGA_VLINEICLR ; 
 int MGA_VLINEIEN ; 
 int MGA_VLINEPEN ; 
 int /*<<< orphan*/  MGA_WRITE (int /*<<< orphan*/ ,scalar_t__ const) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_handle_vblank (struct drm_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static __inline__ int mga_is_idle(drm_mga_private_t *dev_priv)
{
	u32 status = MGA_READ(MGA_STATUS) & MGA_ENGINE_IDLE_MASK;
	return (status == MGA_ENDPRDMASTS);
}

u32 mga_get_vblank_counter(struct drm_device *dev, unsigned int pipe)
{
	const drm_mga_private_t *const dev_priv =
		(drm_mga_private_t *) dev->dev_private;

	if (pipe != 0)
		return 0;

	return atomic_read(&dev_priv->vbl_received);
}

irqreturn_t mga_driver_irq_handler(int irq, void *arg)
{
	struct drm_device *dev = (struct drm_device *) arg;
	drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
	int status;
	int handled = 0;

	status = MGA_READ(MGA_STATUS);

	/* VBLANK interrupt */
	if (status & MGA_VLINEPEN) {
		MGA_WRITE(MGA_ICLEAR, MGA_VLINEICLR);
		atomic_inc(&dev_priv->vbl_received);
		drm_handle_vblank(dev, 0);
		handled = 1;
	}

	/* SOFTRAP interrupt */
	if (status & MGA_SOFTRAPEN) {
		const u32 prim_start = MGA_READ(MGA_PRIMADDRESS);
		const u32 prim_end = MGA_READ(MGA_PRIMEND);


		MGA_WRITE(MGA_ICLEAR, MGA_SOFTRAPICLR);

		/* In addition to clearing the interrupt-pending bit, we
		 * have to write to MGA_PRIMEND to re-start the DMA operation.
		 */
		if ((prim_start & ~0x03) != (prim_end & ~0x03))
			MGA_WRITE(MGA_PRIMEND, prim_end);

		atomic_inc(&dev_priv->last_fence_retired);
		wake_up(&dev_priv->fence_queue);
		handled = 1;
	}

	if (handled)
		return IRQ_HANDLED;
	return IRQ_NONE;
}

int mga_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
	drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;

	if (pipe != 0) {
		DRM_ERROR("tried to enable vblank on non-existent crtc %u\n",
			  pipe);
		return 0;
	}

	MGA_WRITE(MGA_IEN, MGA_VLINEIEN | MGA_SOFTRAPEN);
	return 0;
}

void mga_disable_vblank(struct drm_device *dev, unsigned int pipe)
{
	if (pipe != 0) {
		DRM_ERROR("tried to disable vblank on non-existent crtc %u\n",
			  pipe);
	}

	/* Do *NOT* disable the vertical refresh interrupt.  MGA doesn't have
	 * a nice hardware counter that tracks the number of refreshes when
	 * the interrupt is disabled, and the kernel doesn't know the refresh
	 * rate to calculate an estimate.
	 */
	/* MGA_WRITE(MGA_IEN, MGA_VLINEIEN | MGA_SOFTRAPEN); */
}

int mga_driver_fence_wait(struct drm_device *dev, unsigned int *sequence)
{
	drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
	unsigned int cur_fence;
	int ret = 0;

	/* Assume that the user has missed the current sequence number
	 * by about a day rather than she wants to wait for years
	 * using fences.
	 */
	DRM_WAIT_ON(ret, dev_priv->fence_queue, 3 * HZ,
		    (((cur_fence = atomic_read(&dev_priv->last_fence_retired))
		      - *sequence) <= (1 << 23)));

	*sequence = cur_fence;

	return ret;
}

void mga_driver_irq_preinstall(struct drm_device *dev)
{
	drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;

	/* Disable *all* interrupts */
	MGA_WRITE(MGA_IEN, 0);
	/* Clear bits if they're already high */
	MGA_WRITE(MGA_ICLEAR, ~0);
}

int mga_driver_irq_postinstall(struct drm_device *dev)
{
	drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;

	init_waitqueue_head(&dev_priv->fence_queue);

	/* Turn on soft trap interrupt.  Vertical blank interrupts are enabled
	 * in mga_enable_vblank.
	 */
	MGA_WRITE(MGA_IEN, MGA_SOFTRAPEN);
	return 0;
}

void mga_driver_irq_uninstall(struct drm_device *dev)
{
	drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
	if (!dev_priv)
		return;

	/* Disable *all* interrupts */
	MGA_WRITE(MGA_IEN, 0);

	dev->irq_enabled = false;
}

