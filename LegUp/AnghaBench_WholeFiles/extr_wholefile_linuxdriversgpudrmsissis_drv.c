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
struct sis_file_private {unsigned long chipset; int /*<<< orphan*/  obj_list; int /*<<< orphan*/  object_idr; } ;
struct drm_file {struct sis_file_private* driver_priv; } ;
struct drm_device {struct sis_file_private* dev_private; int /*<<< orphan*/  pdev; } ;
typedef  struct sis_file_private drm_sis_private_t ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  idr_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  idr_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct sis_file_private*) ; 
 struct sis_file_private* kmalloc (int,int /*<<< orphan*/ ) ; 
 struct sis_file_private* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_master (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sis_driver_load(struct drm_device *dev, unsigned long chipset)
{
	drm_sis_private_t *dev_priv;

	pci_set_master(dev->pdev);

	dev_priv = kzalloc(sizeof(drm_sis_private_t), GFP_KERNEL);
	if (dev_priv == NULL)
		return -ENOMEM;

	idr_init(&dev_priv->object_idr);
	dev->dev_private = (void *)dev_priv;
	dev_priv->chipset = chipset;

	return 0;
}

__attribute__((used)) static void sis_driver_unload(struct drm_device *dev)
{
	drm_sis_private_t *dev_priv = dev->dev_private;

	idr_destroy(&dev_priv->object_idr);

	kfree(dev_priv);
}

__attribute__((used)) static int sis_driver_open(struct drm_device *dev, struct drm_file *file)
{
	struct sis_file_private *file_priv;

	DRM_DEBUG_DRIVER("\n");
	file_priv = kmalloc(sizeof(*file_priv), GFP_KERNEL);
	if (!file_priv)
		return -ENOMEM;

	file->driver_priv = file_priv;

	INIT_LIST_HEAD(&file_priv->obj_list);

	return 0;
}

__attribute__((used)) static void sis_driver_postclose(struct drm_device *dev, struct drm_file *file)
{
	struct sis_file_private *file_priv = file->driver_priv;

	kfree(file_priv);
}

