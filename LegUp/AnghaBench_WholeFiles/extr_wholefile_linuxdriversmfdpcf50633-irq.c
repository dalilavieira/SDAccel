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
typedef  size_t u8 ;
struct pcf50633 {size_t* mask_regs; int onkey1s_held; size_t* resume_reason; int irq; int /*<<< orphan*/  dev; TYPE_1__* pdata; scalar_t__ is_suspended; TYPE_2__* irq_handler; int /*<<< orphan*/  lock; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_4__ {void (* handler ) (int,void*) ;void* data; } ;
struct TYPE_3__ {size_t* resumers; int /*<<< orphan*/  (* force_shutdown ) (struct pcf50633*) ;} ;

/* Variables and functions */
 int ARRAY_SIZE (size_t*) ; 
 int EBUSY ; 
 int EINVAL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 size_t PCF50633_INT1_ADPINS ; 
 size_t PCF50633_INT1_ADPREM ; 
 size_t PCF50633_INT1_SECOND ; 
 size_t PCF50633_INT1_USBINS ; 
 size_t PCF50633_INT1_USBREM ; 
 size_t PCF50633_INT2_ONKEYF ; 
 size_t PCF50633_INT2_ONKEYR ; 
 size_t PCF50633_INT3_ONKEY1S ; 
 int PCF50633_NUM_IRQ ; 
 scalar_t__ PCF50633_ONKEY1S_TIMEOUT ; 
 int /*<<< orphan*/  PCF50633_REG_INT1 ; 
 size_t PCF50633_REG_INT1M ; 
 size_t PCF50633_REG_INT2M ; 
 size_t PCF50633_REG_INT3M ; 
 size_t PCF50633_REG_INT4M ; 
 size_t PCF50633_REG_INT5M ; 
 int /*<<< orphan*/  PCF50633_REG_MBCS2 ; 
 size_t PCF50633_REG_OOCSHDWN ; 
 scalar_t__ WARN_ON (void (*) (int,void*)) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,size_t,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ enable_irq_wake (int) ; 
 int /*<<< orphan*/  free_irq (int,struct pcf50633*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int pcf50633_read_block (struct pcf50633*,int /*<<< orphan*/ ,int,size_t*) ; 
 int /*<<< orphan*/  pcf50633_reg_clear_bits (struct pcf50633*,size_t,size_t) ; 
 size_t pcf50633_reg_read (struct pcf50633*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcf50633_reg_set_bit_mask (struct pcf50633*,size_t,size_t,size_t) ; 
 int /*<<< orphan*/  pcf50633_reg_write (struct pcf50633*,size_t,int) ; 
 int request_threaded_irq (int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct pcf50633*) ; 
 void stub1 (int,void*) ; 
 int /*<<< orphan*/  stub2 (struct pcf50633*) ; 

int pcf50633_register_irq(struct pcf50633 *pcf, int irq,
			void (*handler) (int, void *), void *data)
{
	if (irq < 0 || irq >= PCF50633_NUM_IRQ || !handler)
		return -EINVAL;

	if (WARN_ON(pcf->irq_handler[irq].handler))
		return -EBUSY;

	mutex_lock(&pcf->lock);
	pcf->irq_handler[irq].handler = handler;
	pcf->irq_handler[irq].data = data;
	mutex_unlock(&pcf->lock);

	return 0;
}

int pcf50633_free_irq(struct pcf50633 *pcf, int irq)
{
	if (irq < 0 || irq >= PCF50633_NUM_IRQ)
		return -EINVAL;

	mutex_lock(&pcf->lock);
	pcf->irq_handler[irq].handler = NULL;
	mutex_unlock(&pcf->lock);

	return 0;
}

__attribute__((used)) static int __pcf50633_irq_mask_set(struct pcf50633 *pcf, int irq, u8 mask)
{
	u8 reg, bit;
	int idx;

	idx = irq >> 3;
	reg = PCF50633_REG_INT1M + idx;
	bit = 1 << (irq & 0x07);

	pcf50633_reg_set_bit_mask(pcf, reg, bit, mask ? bit : 0);

	mutex_lock(&pcf->lock);

	if (mask)
		pcf->mask_regs[idx] |= bit;
	else
		pcf->mask_regs[idx] &= ~bit;

	mutex_unlock(&pcf->lock);

	return 0;
}

int pcf50633_irq_mask(struct pcf50633 *pcf, int irq)
{
	dev_dbg(pcf->dev, "Masking IRQ %d\n", irq);

	return __pcf50633_irq_mask_set(pcf, irq, 1);
}

int pcf50633_irq_unmask(struct pcf50633 *pcf, int irq)
{
	dev_dbg(pcf->dev, "Unmasking IRQ %d\n", irq);

	return __pcf50633_irq_mask_set(pcf, irq, 0);
}

int pcf50633_irq_mask_get(struct pcf50633 *pcf, int irq)
{
	u8 reg, bits;

	reg =  irq >> 3;
	bits = 1 << (irq & 0x07);

	return pcf->mask_regs[reg] & bits;
}

__attribute__((used)) static void pcf50633_irq_call_handler(struct pcf50633 *pcf, int irq)
{
	if (pcf->irq_handler[irq].handler)
		pcf->irq_handler[irq].handler(irq, pcf->irq_handler[irq].data);
}

__attribute__((used)) static irqreturn_t pcf50633_irq(int irq, void *data)
{
	struct pcf50633 *pcf = data;
	int ret, i, j;
	u8 pcf_int[5], chgstat;

	/* Read the 5 INT regs in one transaction */
	ret = pcf50633_read_block(pcf, PCF50633_REG_INT1,
						ARRAY_SIZE(pcf_int), pcf_int);
	if (ret != ARRAY_SIZE(pcf_int)) {
		dev_err(pcf->dev, "Error reading INT registers\n");

		/*
		 * If this doesn't ACK the interrupt to the chip, we'll be
		 * called once again as we're level triggered.
		 */
		goto out;
	}

	/* defeat 8s death from lowsys on A5 */
	pcf50633_reg_write(pcf, PCF50633_REG_OOCSHDWN,  0x04);

	/* We immediately read the usb and adapter status. We thus make sure
	 * only of USBINS/USBREM IRQ handlers are called */
	if (pcf_int[0] & (PCF50633_INT1_USBINS | PCF50633_INT1_USBREM)) {
		chgstat = pcf50633_reg_read(pcf, PCF50633_REG_MBCS2);
		if (chgstat & (0x3 << 4))
			pcf_int[0] &= ~PCF50633_INT1_USBREM;
		else
			pcf_int[0] &= ~PCF50633_INT1_USBINS;
	}

	/* Make sure only one of ADPINS or ADPREM is set */
	if (pcf_int[0] & (PCF50633_INT1_ADPINS | PCF50633_INT1_ADPREM)) {
		chgstat = pcf50633_reg_read(pcf, PCF50633_REG_MBCS2);
		if (chgstat & (0x3 << 4))
			pcf_int[0] &= ~PCF50633_INT1_ADPREM;
		else
			pcf_int[0] &= ~PCF50633_INT1_ADPINS;
	}

	dev_dbg(pcf->dev, "INT1=0x%02x INT2=0x%02x INT3=0x%02x "
			"INT4=0x%02x INT5=0x%02x\n", pcf_int[0],
			pcf_int[1], pcf_int[2], pcf_int[3], pcf_int[4]);

	/* Some revisions of the chip don't have a 8s standby mode on
	 * ONKEY1S press. We try to manually do it in such cases. */
	if ((pcf_int[0] & PCF50633_INT1_SECOND) && pcf->onkey1s_held) {
		dev_info(pcf->dev, "ONKEY1S held for %d secs\n",
							pcf->onkey1s_held);
		if (pcf->onkey1s_held++ == PCF50633_ONKEY1S_TIMEOUT)
			if (pcf->pdata->force_shutdown)
				pcf->pdata->force_shutdown(pcf);
	}

	if (pcf_int[2] & PCF50633_INT3_ONKEY1S) {
		dev_info(pcf->dev, "ONKEY1S held\n");
		pcf->onkey1s_held = 1 ;

		/* Unmask IRQ_SECOND */
		pcf50633_reg_clear_bits(pcf, PCF50633_REG_INT1M,
						PCF50633_INT1_SECOND);

		/* Unmask IRQ_ONKEYR */
		pcf50633_reg_clear_bits(pcf, PCF50633_REG_INT2M,
						PCF50633_INT2_ONKEYR);
	}

	if ((pcf_int[1] & PCF50633_INT2_ONKEYR) && pcf->onkey1s_held) {
		pcf->onkey1s_held = 0;

		/* Mask SECOND and ONKEYR interrupts */
		if (pcf->mask_regs[0] & PCF50633_INT1_SECOND)
			pcf50633_reg_set_bit_mask(pcf,
					PCF50633_REG_INT1M,
					PCF50633_INT1_SECOND,
					PCF50633_INT1_SECOND);

		if (pcf->mask_regs[1] & PCF50633_INT2_ONKEYR)
			pcf50633_reg_set_bit_mask(pcf,
					PCF50633_REG_INT2M,
					PCF50633_INT2_ONKEYR,
					PCF50633_INT2_ONKEYR);
	}

	/* Have we just resumed ? */
	if (pcf->is_suspended) {
		pcf->is_suspended = 0;

		/* Set the resume reason filtering out non resumers */
		for (i = 0; i < ARRAY_SIZE(pcf_int); i++)
			pcf->resume_reason[i] = pcf_int[i] &
						pcf->pdata->resumers[i];

		/* Make sure we don't pass on any ONKEY events to
		 * userspace now */
		pcf_int[1] &= ~(PCF50633_INT2_ONKEYR | PCF50633_INT2_ONKEYF);
	}

	for (i = 0; i < ARRAY_SIZE(pcf_int); i++) {
		/* Unset masked interrupts */
		pcf_int[i] &= ~pcf->mask_regs[i];

		for (j = 0; j < 8 ; j++)
			if (pcf_int[i] & (1 << j))
				pcf50633_irq_call_handler(pcf, (i * 8) + j);
	}

out:
	return IRQ_HANDLED;
}

int pcf50633_irq_init(struct pcf50633 *pcf, int irq)
{
	int ret;

	pcf->irq = irq;

	/* Enable all interrupts except RTC SECOND */
	pcf->mask_regs[0] = 0x80;
	pcf50633_reg_write(pcf, PCF50633_REG_INT1M, pcf->mask_regs[0]);
	pcf50633_reg_write(pcf, PCF50633_REG_INT2M, 0x00);
	pcf50633_reg_write(pcf, PCF50633_REG_INT3M, 0x00);
	pcf50633_reg_write(pcf, PCF50633_REG_INT4M, 0x00);
	pcf50633_reg_write(pcf, PCF50633_REG_INT5M, 0x00);

	ret = request_threaded_irq(irq, NULL, pcf50633_irq,
					IRQF_TRIGGER_LOW | IRQF_ONESHOT,
					"pcf50633", pcf);

	if (ret)
		dev_err(pcf->dev, "Failed to request IRQ %d\n", ret);

	if (enable_irq_wake(irq) < 0)
		dev_err(pcf->dev, "IRQ %u cannot be enabled as wake-up source"
			"in this hardware revision", irq);

	return ret;
}

void pcf50633_irq_free(struct pcf50633 *pcf)
{
	free_irq(pcf->irq, pcf);
}

