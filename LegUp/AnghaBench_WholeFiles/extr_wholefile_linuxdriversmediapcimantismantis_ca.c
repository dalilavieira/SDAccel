#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct dvb_adapter {int dummy; } ;
struct mantis_pci {struct mantis_ca* mantis_ca; struct dvb_adapter dvb_adapter; int /*<<< orphan*/  intmask_lock; } ;
struct TYPE_4__ {int (* read_attribute_mem ) (struct dvb_ca_en50221*,int,int) ;int (* write_attribute_mem ) (struct dvb_ca_en50221*,int,int,int /*<<< orphan*/ ) ;int (* read_cam_control ) (struct dvb_ca_en50221*,int,int /*<<< orphan*/ ) ;int (* write_cam_control ) (struct dvb_ca_en50221*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int (* slot_reset ) (struct dvb_ca_en50221*,int) ;int (* slot_shutdown ) (struct dvb_ca_en50221*,int) ;int (* slot_ts_enable ) (struct dvb_ca_en50221*,int) ;int (* poll_slot_status ) (struct dvb_ca_en50221*,int,int) ;struct mantis_ca* data; int /*<<< orphan*/  owner; } ;
struct mantis_ca {scalar_t__ slot_state; TYPE_1__ en50221; int /*<<< orphan*/  hif_write_wq; int /*<<< orphan*/  hif_opdone_wq; int /*<<< orphan*/  hif_data_wq; int /*<<< orphan*/  ca_lock; struct mantis_pci* ca_priv; } ;
struct dvb_ca_en50221 {struct mantis_ca* data; } ;

/* Variables and functions */
 int DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE ; 
 int DVB_CA_EN50221_POLL_CAM_PRESENT ; 
 int DVB_CA_EN50221_POLL_CAM_READY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MANTIS_DEBUG ; 
 int /*<<< orphan*/  MANTIS_ERROR ; 
 int /*<<< orphan*/  MANTIS_INT_MASK ; 
 int /*<<< orphan*/  MANTIS_PCMCIA_RESET ; 
 scalar_t__ MODULE_INSERTED ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int,char*,...) ; 
 int /*<<< orphan*/  dvb_ca_en50221_camready_irq (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int dvb_ca_en50221_init (struct dvb_adapter*,TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  dvb_ca_en50221_release (TYPE_1__*) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct mantis_ca*) ; 
 struct mantis_ca* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mantis_evmgr_exit (struct mantis_ca*) ; 
 int /*<<< orphan*/  mantis_evmgr_init (struct mantis_ca*) ; 
 int mantis_hif_read_iom (struct mantis_ca*,int /*<<< orphan*/ ) ; 
 int mantis_hif_read_mem (struct mantis_ca*,int) ; 
 int mantis_hif_write_iom (struct mantis_ca*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mantis_hif_write_mem (struct mantis_ca*,int,int /*<<< orphan*/ ) ; 
 int mmread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmwrite (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 

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

__attribute__((used)) static int mantis_ca_read_attr_mem(struct dvb_ca_en50221 *en50221, int slot, int addr)
{
	struct mantis_ca *ca = en50221->data;
	struct mantis_pci *mantis = ca->ca_priv;

	dprintk(MANTIS_DEBUG, 1, "Slot(%d): Request Attribute Mem Read", slot);

	if (slot != 0)
		return -EINVAL;

	return mantis_hif_read_mem(ca, addr);
}

__attribute__((used)) static int mantis_ca_write_attr_mem(struct dvb_ca_en50221 *en50221, int slot, int addr, u8 data)
{
	struct mantis_ca *ca = en50221->data;
	struct mantis_pci *mantis = ca->ca_priv;

	dprintk(MANTIS_DEBUG, 1, "Slot(%d): Request Attribute Mem Write", slot);

	if (slot != 0)
		return -EINVAL;

	return mantis_hif_write_mem(ca, addr, data);
}

__attribute__((used)) static int mantis_ca_read_cam_ctl(struct dvb_ca_en50221 *en50221, int slot, u8 addr)
{
	struct mantis_ca *ca = en50221->data;
	struct mantis_pci *mantis = ca->ca_priv;

	dprintk(MANTIS_DEBUG, 1, "Slot(%d): Request CAM control Read", slot);

	if (slot != 0)
		return -EINVAL;

	return mantis_hif_read_iom(ca, addr);
}

__attribute__((used)) static int mantis_ca_write_cam_ctl(struct dvb_ca_en50221 *en50221, int slot, u8 addr, u8 data)
{
	struct mantis_ca *ca = en50221->data;
	struct mantis_pci *mantis = ca->ca_priv;

	dprintk(MANTIS_DEBUG, 1, "Slot(%d): Request CAM control Write", slot);

	if (slot != 0)
		return -EINVAL;

	return mantis_hif_write_iom(ca, addr, data);
}

__attribute__((used)) static int mantis_ca_slot_reset(struct dvb_ca_en50221 *en50221, int slot)
{
	struct mantis_ca *ca = en50221->data;
	struct mantis_pci *mantis = ca->ca_priv;

	dprintk(MANTIS_DEBUG, 1, "Slot(%d): Slot RESET", slot);
	udelay(500); /* Wait.. */
	mmwrite(0xda, MANTIS_PCMCIA_RESET); /* Leading edge assert */
	udelay(500);
	mmwrite(0x00, MANTIS_PCMCIA_RESET); /* Trailing edge deassert */
	msleep(1000);
	dvb_ca_en50221_camready_irq(&ca->en50221, 0);

	return 0;
}

__attribute__((used)) static int mantis_ca_slot_shutdown(struct dvb_ca_en50221 *en50221, int slot)
{
	struct mantis_ca *ca = en50221->data;
	struct mantis_pci *mantis = ca->ca_priv;

	dprintk(MANTIS_DEBUG, 1, "Slot(%d): Slot shutdown", slot);

	return 0;
}

__attribute__((used)) static int mantis_ts_control(struct dvb_ca_en50221 *en50221, int slot)
{
	struct mantis_ca *ca = en50221->data;
	struct mantis_pci *mantis = ca->ca_priv;

	dprintk(MANTIS_DEBUG, 1, "Slot(%d): TS control", slot);
/*	mantis_set_direction(mantis, 1); */ /* Enable TS through CAM */

	return 0;
}

__attribute__((used)) static int mantis_slot_status(struct dvb_ca_en50221 *en50221, int slot, int open)
{
	struct mantis_ca *ca = en50221->data;
	struct mantis_pci *mantis = ca->ca_priv;

	dprintk(MANTIS_DEBUG, 1, "Slot(%d): Poll Slot status", slot);

	if (ca->slot_state == MODULE_INSERTED) {
		dprintk(MANTIS_DEBUG, 1, "CA Module present and ready");
		return DVB_CA_EN50221_POLL_CAM_PRESENT | DVB_CA_EN50221_POLL_CAM_READY;
	} else {
		dprintk(MANTIS_DEBUG, 1, "CA Module not present or not ready");
	}

	return 0;
}

int mantis_ca_init(struct mantis_pci *mantis)
{
	struct dvb_adapter *dvb_adapter	= &mantis->dvb_adapter;
	struct mantis_ca *ca;
	int ca_flags = 0, result;

	dprintk(MANTIS_DEBUG, 1, "Initializing Mantis CA");
	ca = kzalloc(sizeof(struct mantis_ca), GFP_KERNEL);
	if (!ca) {
		dprintk(MANTIS_ERROR, 1, "Out of memory!, exiting ..");
		result = -ENOMEM;
		goto err;
	}

	ca->ca_priv		= mantis;
	mantis->mantis_ca	= ca;
	ca_flags		= DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE;
	/* register CA interface */
	ca->en50221.owner		= THIS_MODULE;
	ca->en50221.read_attribute_mem	= mantis_ca_read_attr_mem;
	ca->en50221.write_attribute_mem	= mantis_ca_write_attr_mem;
	ca->en50221.read_cam_control	= mantis_ca_read_cam_ctl;
	ca->en50221.write_cam_control	= mantis_ca_write_cam_ctl;
	ca->en50221.slot_reset		= mantis_ca_slot_reset;
	ca->en50221.slot_shutdown	= mantis_ca_slot_shutdown;
	ca->en50221.slot_ts_enable	= mantis_ts_control;
	ca->en50221.poll_slot_status	= mantis_slot_status;
	ca->en50221.data		= ca;

	mutex_init(&ca->ca_lock);

	init_waitqueue_head(&ca->hif_data_wq);
	init_waitqueue_head(&ca->hif_opdone_wq);
	init_waitqueue_head(&ca->hif_write_wq);

	dprintk(MANTIS_ERROR, 1, "Registering EN50221 device");
	result = dvb_ca_en50221_init(dvb_adapter, &ca->en50221, ca_flags, 1);
	if (result != 0) {
		dprintk(MANTIS_ERROR, 1, "EN50221: Initialization failed <%d>", result);
		goto err;
	}
	dprintk(MANTIS_ERROR, 1, "Registered EN50221 device");
	mantis_evmgr_init(ca);
	return 0;
err:
	kfree(ca);
	return result;
}

void mantis_ca_exit(struct mantis_pci *mantis)
{
	struct mantis_ca *ca = mantis->mantis_ca;

	dprintk(MANTIS_DEBUG, 1, "Mantis CA exit");
	if (!ca)
		return;

	mantis_evmgr_exit(ca);
	dprintk(MANTIS_ERROR, 1, "Unregistering EN50221 device");
	dvb_ca_en50221_release(&ca->en50221);

	kfree(ca);
}

