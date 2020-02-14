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
typedef  int u32 ;
struct mantis_pci {int /*<<< orphan*/  num; int /*<<< orphan*/  intmask_lock; } ;
struct mantis_ca {scalar_t__ slot_state; struct mantis_pci* ca_priv; int /*<<< orphan*/  en50221; } ;

/* Variables and functions */
 int /*<<< orphan*/  DVB_CA_EN50221_CAMCHANGE_INSERTED ; 
 int /*<<< orphan*/  DVB_CA_EN50221_CAMCHANGE_REMOVED ; 
 int MANTIS_CARD_PLUGIN ; 
 int MANTIS_CARD_PLUGOUT ; 
 int /*<<< orphan*/  MANTIS_CARD_RESET ; 
 int /*<<< orphan*/  MANTIS_DEBUG ; 
 int MANTIS_GPIF_DETSTAT ; 
 int /*<<< orphan*/  MANTIS_GPIF_IRQCFG ; 
 int /*<<< orphan*/  MANTIS_GPIF_STATUS ; 
 int MANTIS_INT_IRQ0 ; 
 int /*<<< orphan*/  MANTIS_INT_MASK ; 
 int MANTIS_MASK_PLUGIN ; 
 int MANTIS_MASK_PLUGOUT ; 
 scalar_t__ MODULE_INSERTED ; 
 scalar_t__ MODULE_XTRACTED ; 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dvb_ca_en50221_camchange_irq (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mmread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmwrite (int,int /*<<< orphan*/ ) ; 
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

void mantis_event_cam_plugin(struct mantis_ca *ca)
{
	struct mantis_pci *mantis = ca->ca_priv;

	u32 gpif_irqcfg;

	if (ca->slot_state == MODULE_XTRACTED) {
		dprintk(MANTIS_DEBUG, 1, "Event: CAM Plugged IN: Adapter(%d) Slot(0)", mantis->num);
		udelay(50);
		mmwrite(0xda000000, MANTIS_CARD_RESET);
		gpif_irqcfg  = mmread(MANTIS_GPIF_IRQCFG);
		gpif_irqcfg |= MANTIS_MASK_PLUGOUT;
		gpif_irqcfg &= ~MANTIS_MASK_PLUGIN;
		mmwrite(gpif_irqcfg, MANTIS_GPIF_IRQCFG);
		udelay(500);
		ca->slot_state = MODULE_INSERTED;
	}
	udelay(100);
}

void mantis_event_cam_unplug(struct mantis_ca *ca)
{
	struct mantis_pci *mantis = ca->ca_priv;

	u32 gpif_irqcfg;

	if (ca->slot_state == MODULE_INSERTED) {
		dprintk(MANTIS_DEBUG, 1, "Event: CAM Unplugged: Adapter(%d) Slot(0)", mantis->num);
		udelay(50);
		mmwrite(0x00da0000, MANTIS_CARD_RESET);
		gpif_irqcfg  = mmread(MANTIS_GPIF_IRQCFG);
		gpif_irqcfg |= MANTIS_MASK_PLUGIN;
		gpif_irqcfg &= ~MANTIS_MASK_PLUGOUT;
		mmwrite(gpif_irqcfg, MANTIS_GPIF_IRQCFG);
		udelay(500);
		ca->slot_state = MODULE_XTRACTED;
	}
	udelay(100);
}

int mantis_pcmcia_init(struct mantis_ca *ca)
{
	struct mantis_pci *mantis = ca->ca_priv;

	u32 gpif_stat, card_stat;

	mantis_unmask_ints(mantis, MANTIS_INT_IRQ0);
	gpif_stat = mmread(MANTIS_GPIF_STATUS);
	card_stat = mmread(MANTIS_GPIF_IRQCFG);

	if (gpif_stat & MANTIS_GPIF_DETSTAT) {
		dprintk(MANTIS_DEBUG, 1, "CAM found on Adapter(%d) Slot(0)", mantis->num);
		mmwrite(card_stat | MANTIS_MASK_PLUGOUT, MANTIS_GPIF_IRQCFG);
		ca->slot_state = MODULE_INSERTED;
		dvb_ca_en50221_camchange_irq(&ca->en50221,
					     0,
					     DVB_CA_EN50221_CAMCHANGE_INSERTED);
	} else {
		dprintk(MANTIS_DEBUG, 1, "Empty Slot on Adapter(%d) Slot(0)", mantis->num);
		mmwrite(card_stat | MANTIS_MASK_PLUGIN, MANTIS_GPIF_IRQCFG);
		ca->slot_state = MODULE_XTRACTED;
		dvb_ca_en50221_camchange_irq(&ca->en50221,
					     0,
					     DVB_CA_EN50221_CAMCHANGE_REMOVED);
	}

	return 0;
}

void mantis_pcmcia_exit(struct mantis_ca *ca)
{
	struct mantis_pci *mantis = ca->ca_priv;

	mmwrite(mmread(MANTIS_GPIF_STATUS) & (~MANTIS_CARD_PLUGOUT | ~MANTIS_CARD_PLUGIN), MANTIS_GPIF_STATUS);
	mantis_mask_ints(mantis, MANTIS_INT_IRQ0);
}

