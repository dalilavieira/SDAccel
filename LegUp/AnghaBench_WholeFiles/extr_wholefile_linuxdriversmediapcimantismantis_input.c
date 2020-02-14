#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_7__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_6__ {int version; int /*<<< orphan*/  product; int /*<<< orphan*/  vendor; int /*<<< orphan*/  bustype; } ;
struct rc_dev {TYPE_3__ dev; int /*<<< orphan*/  map_name; int /*<<< orphan*/  driver_name; TYPE_2__ input_id; int /*<<< orphan*/  input_phys; int /*<<< orphan*/  device_name; } ;
struct mantis_pci {struct rc_dev* rc; TYPE_4__* pdev; scalar_t__ rc_map_name; int /*<<< orphan*/  device_id; int /*<<< orphan*/  vendor_id; int /*<<< orphan*/  input_phys; int /*<<< orphan*/  device_name; TYPE_1__* hwconfig; int /*<<< orphan*/  intmask_lock; } ;
struct TYPE_8__ {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {char* model_name; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_PCI ; 
 int ENOMEM ; 
 int /*<<< orphan*/  MANTIS_ERROR ; 
 int /*<<< orphan*/  MANTIS_INT_MASK ; 
 int /*<<< orphan*/  MODULE_NAME ; 
 int /*<<< orphan*/  RC_DRIVER_SCANCODE ; 
 int /*<<< orphan*/  RC_MAP_EMPTY ; 
 int /*<<< orphan*/  RC_PROTO_UNKNOWN ; 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int,char*,...) ; 
 int mmread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmwrite (int,int /*<<< orphan*/ ) ; 
 char* pci_name (TYPE_4__*) ; 
 struct rc_dev* rc_allocate_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rc_free_device (struct rc_dev*) ; 
 int /*<<< orphan*/  rc_keydown (struct rc_dev*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int rc_register_device (struct rc_dev*) ; 
 int /*<<< orphan*/  rc_unregister_device (struct rc_dev*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline void mantis_mask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) & ~mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

__attribute__((used)) static inline void mantis_unmask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) | mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

void mantis_input_process(struct mantis_pci *mantis, int scancode)
{
	if (mantis->rc)
		rc_keydown(mantis->rc, RC_PROTO_UNKNOWN, scancode, 0);
}

int mantis_input_init(struct mantis_pci *mantis)
{
	struct rc_dev *dev;
	int err;

	dev = rc_allocate_device(RC_DRIVER_SCANCODE);
	if (!dev) {
		dprintk(MANTIS_ERROR, 1, "Remote device allocation failed");
		err = -ENOMEM;
		goto out;
	}

	snprintf(mantis->device_name, sizeof(mantis->device_name),
		 "Mantis %s IR receiver", mantis->hwconfig->model_name);
	snprintf(mantis->input_phys, sizeof(mantis->input_phys),
		 "pci-%s/ir0", pci_name(mantis->pdev));

	dev->device_name        = mantis->device_name;
	dev->input_phys         = mantis->input_phys;
	dev->input_id.bustype   = BUS_PCI;
	dev->input_id.vendor    = mantis->vendor_id;
	dev->input_id.product   = mantis->device_id;
	dev->input_id.version   = 1;
	dev->driver_name        = MODULE_NAME;
	dev->map_name           = mantis->rc_map_name ? : RC_MAP_EMPTY;
	dev->dev.parent         = &mantis->pdev->dev;

	err = rc_register_device(dev);
	if (err) {
		dprintk(MANTIS_ERROR, 1, "IR device registration failed, ret = %d", err);
		goto out_dev;
	}

	mantis->rc = dev;
	return 0;

out_dev:
	rc_free_device(dev);
out:
	return err;
}

void mantis_input_exit(struct mantis_pci *mantis)
{
	rc_unregister_device(mantis->rc);
}

