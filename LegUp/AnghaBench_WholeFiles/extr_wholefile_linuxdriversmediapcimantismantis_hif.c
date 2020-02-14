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
typedef  int u8 ;
typedef  int u32 ;
struct mantis_slot {int slave_cfg; } ;
struct mantis_pci {int num; int gpif_status; int /*<<< orphan*/  intmask_lock; } ;
struct mantis_ca {int hif_event; int /*<<< orphan*/  ca_lock; struct mantis_pci* ca_priv; struct mantis_slot* slot; int /*<<< orphan*/  hif_write_wq; int /*<<< orphan*/  hif_opdone_wq; } ;

/* Variables and functions */
 int EREMOTEIO ; 
 int /*<<< orphan*/  ERESTARTSYS ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  MANTIS_DEBUG ; 
 int /*<<< orphan*/  MANTIS_ERROR ; 
 int /*<<< orphan*/  MANTIS_GPIF_ADDR ; 
 int /*<<< orphan*/  MANTIS_GPIF_BRADDR ; 
 int /*<<< orphan*/  MANTIS_GPIF_BRBYTES ; 
 int /*<<< orphan*/  MANTIS_GPIF_CFGSLA ; 
 int /*<<< orphan*/  MANTIS_GPIF_DIN ; 
 int /*<<< orphan*/  MANTIS_GPIF_DOUT ; 
 int MANTIS_GPIF_HIFRDWRN ; 
 int /*<<< orphan*/  MANTIS_GPIF_IRQCFG ; 
 int MANTIS_GPIF_PCMCIAIOM ; 
 int MANTIS_GPIF_PCMCIAREG ; 
 int /*<<< orphan*/  MANTIS_GPIF_STATUS ; 
 int MANTIS_GPIF_WRACK ; 
 int MANTIS_HIF_STATUS ; 
 int /*<<< orphan*/  MANTIS_INT_MASK ; 
 int MANTIS_MASK_BRRDY ; 
 int MANTIS_MASK_EXTIRQ ; 
 int MANTIS_MASK_OTHERR ; 
 int MANTIS_MASK_OVFLW ; 
 int MANTIS_MASK_WRACK ; 
 int MANTIS_MASK_WSTO ; 
 int MANTIS_SBUF_OPDONE ; 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int,char*,...) ; 
 int mmread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmwrite (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static int mantis_hif_sbuf_opdone_wait(struct mantis_ca *ca)
{
	struct mantis_pci *mantis = ca->ca_priv;
	int rc = 0;

	if (wait_event_timeout(ca->hif_opdone_wq,
			       ca->hif_event & MANTIS_SBUF_OPDONE,
			       msecs_to_jiffies(500)) == -ERESTARTSYS) {

		dprintk(MANTIS_ERROR, 1, "Adapter(%d) Slot(0): Smart buffer operation timeout !", mantis->num);
		rc = -EREMOTEIO;
	}
	dprintk(MANTIS_DEBUG, 1, "Smart Buffer Operation complete");
	ca->hif_event &= ~MANTIS_SBUF_OPDONE;
	return rc;
}

__attribute__((used)) static int mantis_hif_write_wait(struct mantis_ca *ca)
{
	struct mantis_pci *mantis = ca->ca_priv;
	u32 opdone = 0, timeout = 0;
	int rc = 0;

	if (wait_event_timeout(ca->hif_write_wq,
			       mantis->gpif_status & MANTIS_GPIF_WRACK,
			       msecs_to_jiffies(500)) == -ERESTARTSYS) {

		dprintk(MANTIS_ERROR, 1, "Adapter(%d) Slot(0): Write ACK timed out !", mantis->num);
		rc = -EREMOTEIO;
	}
	dprintk(MANTIS_DEBUG, 1, "Write Acknowledged");
	mantis->gpif_status &= ~MANTIS_GPIF_WRACK;
	while (!opdone) {
		opdone = (mmread(MANTIS_GPIF_STATUS) & MANTIS_SBUF_OPDONE);
		udelay(500);
		timeout++;
		if (timeout > 100) {
			dprintk(MANTIS_ERROR, 1, "Adapter(%d) Slot(0): Write operation timed out!", mantis->num);
			rc = -ETIMEDOUT;
			break;
		}
	}
	dprintk(MANTIS_DEBUG, 1, "HIF Write success");
	return rc;
}

int mantis_hif_read_mem(struct mantis_ca *ca, u32 addr)
{
	struct mantis_pci *mantis = ca->ca_priv;
	u32 hif_addr = 0, data, count = 4;

	dprintk(MANTIS_DEBUG, 1, "Adapter(%d) Slot(0): Request HIF Mem Read", mantis->num);
	mutex_lock(&ca->ca_lock);
	hif_addr &= ~MANTIS_GPIF_PCMCIAREG;
	hif_addr &= ~MANTIS_GPIF_PCMCIAIOM;
	hif_addr |=  MANTIS_HIF_STATUS;
	hif_addr |=  addr;

	mmwrite(hif_addr, MANTIS_GPIF_BRADDR);
	mmwrite(count, MANTIS_GPIF_BRBYTES);
	udelay(20);
	mmwrite(hif_addr | MANTIS_GPIF_HIFRDWRN, MANTIS_GPIF_ADDR);

	if (mantis_hif_sbuf_opdone_wait(ca) != 0) {
		dprintk(MANTIS_ERROR, 1, "Adapter(%d) Slot(0): GPIF Smart Buffer operation failed", mantis->num);
		mutex_unlock(&ca->ca_lock);
		return -EREMOTEIO;
	}
	data = mmread(MANTIS_GPIF_DIN);
	mutex_unlock(&ca->ca_lock);
	dprintk(MANTIS_DEBUG, 1, "Mem Read: 0x%02x", data);
	return (data >> 24) & 0xff;
}

int mantis_hif_write_mem(struct mantis_ca *ca, u32 addr, u8 data)
{
	struct mantis_slot *slot = ca->slot;
	struct mantis_pci *mantis = ca->ca_priv;
	u32 hif_addr = 0;

	dprintk(MANTIS_DEBUG, 1, "Adapter(%d) Slot(0): Request HIF Mem Write", mantis->num);
	mutex_lock(&ca->ca_lock);
	hif_addr &= ~MANTIS_GPIF_HIFRDWRN;
	hif_addr &= ~MANTIS_GPIF_PCMCIAREG;
	hif_addr &= ~MANTIS_GPIF_PCMCIAIOM;
	hif_addr |=  MANTIS_HIF_STATUS;
	hif_addr |=  addr;

	mmwrite(slot->slave_cfg, MANTIS_GPIF_CFGSLA); /* Slot0 alone for now */
	mmwrite(hif_addr, MANTIS_GPIF_ADDR);
	mmwrite(data, MANTIS_GPIF_DOUT);

	if (mantis_hif_write_wait(ca) != 0) {
		dprintk(MANTIS_ERROR, 1, "Adapter(%d) Slot(0): HIF Smart Buffer operation failed", mantis->num);
		mutex_unlock(&ca->ca_lock);
		return -EREMOTEIO;
	}
	dprintk(MANTIS_DEBUG, 1, "Mem Write: (0x%02x to 0x%02x)", data, addr);
	mutex_unlock(&ca->ca_lock);

	return 0;
}

int mantis_hif_read_iom(struct mantis_ca *ca, u32 addr)
{
	struct mantis_pci *mantis = ca->ca_priv;
	u32 data, hif_addr = 0;

	dprintk(MANTIS_DEBUG, 1, "Adapter(%d) Slot(0): Request HIF I/O Read", mantis->num);
	mutex_lock(&ca->ca_lock);
	hif_addr &= ~MANTIS_GPIF_PCMCIAREG;
	hif_addr |=  MANTIS_GPIF_PCMCIAIOM;
	hif_addr |=  MANTIS_HIF_STATUS;
	hif_addr |=  addr;

	mmwrite(hif_addr, MANTIS_GPIF_BRADDR);
	mmwrite(1, MANTIS_GPIF_BRBYTES);
	udelay(20);
	mmwrite(hif_addr | MANTIS_GPIF_HIFRDWRN, MANTIS_GPIF_ADDR);

	if (mantis_hif_sbuf_opdone_wait(ca) != 0) {
		dprintk(MANTIS_ERROR, 1, "Adapter(%d) Slot(0): HIF Smart Buffer operation failed", mantis->num);
		mutex_unlock(&ca->ca_lock);
		return -EREMOTEIO;
	}
	data = mmread(MANTIS_GPIF_DIN);
	dprintk(MANTIS_DEBUG, 1, "I/O Read: 0x%02x", data);
	udelay(50);
	mutex_unlock(&ca->ca_lock);

	return (u8) data;
}

int mantis_hif_write_iom(struct mantis_ca *ca, u32 addr, u8 data)
{
	struct mantis_pci *mantis = ca->ca_priv;
	u32 hif_addr = 0;

	dprintk(MANTIS_DEBUG, 1, "Adapter(%d) Slot(0): Request HIF I/O Write", mantis->num);
	mutex_lock(&ca->ca_lock);
	hif_addr &= ~MANTIS_GPIF_PCMCIAREG;
	hif_addr &= ~MANTIS_GPIF_HIFRDWRN;
	hif_addr |=  MANTIS_GPIF_PCMCIAIOM;
	hif_addr |=  MANTIS_HIF_STATUS;
	hif_addr |=  addr;

	mmwrite(hif_addr, MANTIS_GPIF_ADDR);
	mmwrite(data, MANTIS_GPIF_DOUT);

	if (mantis_hif_write_wait(ca) != 0) {
		dprintk(MANTIS_ERROR, 1, "Adapter(%d) Slot(0): HIF Smart Buffer operation failed", mantis->num);
		mutex_unlock(&ca->ca_lock);
		return -EREMOTEIO;
	}
	dprintk(MANTIS_DEBUG, 1, "I/O Write: (0x%02x to 0x%02x)", data, addr);
	mutex_unlock(&ca->ca_lock);
	udelay(50);

	return 0;
}

int mantis_hif_init(struct mantis_ca *ca)
{
	struct mantis_slot *slot = ca->slot;
	struct mantis_pci *mantis = ca->ca_priv;
	u32 irqcfg;

	slot[0].slave_cfg = 0x70773028;
	dprintk(MANTIS_ERROR, 1, "Adapter(%d) Initializing Mantis Host Interface", mantis->num);

	mutex_lock(&ca->ca_lock);
	irqcfg = mmread(MANTIS_GPIF_IRQCFG);
	irqcfg = MANTIS_MASK_BRRDY	|
		 MANTIS_MASK_WRACK	|
		 MANTIS_MASK_EXTIRQ	|
		 MANTIS_MASK_WSTO	|
		 MANTIS_MASK_OTHERR	|
		 MANTIS_MASK_OVFLW;

	mmwrite(irqcfg, MANTIS_GPIF_IRQCFG);
	mutex_unlock(&ca->ca_lock);

	return 0;
}

void mantis_hif_exit(struct mantis_ca *ca)
{
	struct mantis_pci *mantis = ca->ca_priv;
	u32 irqcfg;

	dprintk(MANTIS_ERROR, 1, "Adapter(%d) Exiting Mantis Host Interface", mantis->num);
	mutex_lock(&ca->ca_lock);
	irqcfg = mmread(MANTIS_GPIF_IRQCFG);
	irqcfg &= ~MANTIS_MASK_BRRDY;
	mmwrite(irqcfg, MANTIS_GPIF_IRQCFG);
	mutex_unlock(&ca->ca_lock);
}

