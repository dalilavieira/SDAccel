#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mfptimerbase {int mfptimer_irq; unsigned char int_mask; } ;
struct irq_data {unsigned int irq; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int int_mask; } ;

/* Variables and functions */
 scalar_t__ ATARI_ETHERNAT_PHYS_ADDR ; 
 unsigned int IRQ_AUTO_4 ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned int IRQ_MFP_TIMD ; 
 int IRQ_MFP_TIMER1 ; 
 size_t VEC_INT4 ; 
 unsigned int VME_MAX_SOURCES ; 
 unsigned int VME_SOURCE_BASE ; 
 int /*<<< orphan*/  atari_disable_irq (unsigned int) ; 
 int /*<<< orphan*/  atari_enable_irq (unsigned int) ; 
 int /*<<< orphan*/  atari_turnoff_irq (unsigned int) ; 
 int /*<<< orphan*/  atari_turnon_irq (unsigned int) ; 
 int* enat_cpld ; 
 int /*<<< orphan*/  falcon_hblhandler ; 
 int free_vme_vec_bitmap ; 
 int /*<<< orphan*/  generic_handle_irq (int) ; 
 scalar_t__ ioremap (scalar_t__,int) ; 
 int /*<<< orphan*/  iounmap (int*) ; 
 int /*<<< orphan*/  m68k_irq_shutdown (struct irq_data*) ; 
 int /*<<< orphan*/  m68k_irq_startup (struct irq_data*) ; 
 TYPE_1__ stmfp_base ; 
 int /*<<< orphan*/ * vectors ; 

__attribute__((used)) static unsigned int atari_irq_startup(struct irq_data *data)
{
	unsigned int irq = data->irq;

	m68k_irq_startup(data);
	atari_turnon_irq(irq);
	atari_enable_irq(irq);
	return 0;
}

__attribute__((used)) static void atari_irq_shutdown(struct irq_data *data)
{
	unsigned int irq = data->irq;

	atari_disable_irq(irq);
	atari_turnoff_irq(irq);
	m68k_irq_shutdown(data);

	if (irq == IRQ_AUTO_4)
	    vectors[VEC_INT4] = falcon_hblhandler;
}

__attribute__((used)) static void atari_irq_enable(struct irq_data *data)
{
	atari_enable_irq(data->irq);
}

__attribute__((used)) static void atari_irq_disable(struct irq_data *data)
{
	atari_disable_irq(data->irq);
}

__attribute__((used)) static irqreturn_t mfptimer_handler(int irq, void *dev_id)
{
	struct mfptimerbase *base = dev_id;
	int mach_irq;
	unsigned char ints;

	mach_irq = base->mfptimer_irq;
	ints = base->int_mask;
	for (; ints; mach_irq++, ints >>= 1) {
		if (ints & 1)
			generic_handle_irq(mach_irq);
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static void atari_mfptimer_enable(struct irq_data *data)
{
	int mfp_num = data->irq - IRQ_MFP_TIMER1;
	stmfp_base.int_mask |= 1 << mfp_num;
	atari_enable_irq(IRQ_MFP_TIMD);
}

__attribute__((used)) static void atari_mfptimer_disable(struct irq_data *data)
{
	int mfp_num = data->irq - IRQ_MFP_TIMER1;
	stmfp_base.int_mask &= ~(1 << mfp_num);
	if (!stmfp_base.int_mask)
		atari_disable_irq(IRQ_MFP_TIMD);
}

__attribute__((used)) static unsigned int atari_ethernat_startup(struct irq_data *data)
{
	int enat_num = 140 - data->irq + 1;

	m68k_irq_startup(data);
	/*
	* map CPLD interrupt register
	*/
	if (!enat_cpld)
		enat_cpld = (unsigned char *)ioremap((ATARI_ETHERNAT_PHYS_ADDR+0x23), 0x2);
	/*
	 * do _not_ enable the USB chip interrupt here - causes interrupt storm
	 * and triggers dead interrupt watchdog
	 * Need to reset the USB chip to a sane state in early startup before
	 * removing this hack
	 */
	if (enat_num == 1)
		*enat_cpld |= 1 << enat_num;

	return 0;
}

__attribute__((used)) static void atari_ethernat_enable(struct irq_data *data)
{
	int enat_num = 140 - data->irq + 1;
	/*
	* map CPLD interrupt register
	*/
	if (!enat_cpld)
		enat_cpld = (unsigned char *)ioremap((ATARI_ETHERNAT_PHYS_ADDR+0x23), 0x2);
	*enat_cpld |= 1 << enat_num;
}

__attribute__((used)) static void atari_ethernat_disable(struct irq_data *data)
{
	int enat_num = 140 - data->irq + 1;
	/*
	* map CPLD interrupt register
	*/
	if (!enat_cpld)
		enat_cpld = (unsigned char *)ioremap((ATARI_ETHERNAT_PHYS_ADDR+0x23), 0x2);
	*enat_cpld &= ~(1 << enat_num);
}

__attribute__((used)) static void atari_ethernat_shutdown(struct irq_data *data)
{
	int enat_num = 140 - data->irq + 1;
	if (enat_cpld) {
		*enat_cpld &= ~(1 << enat_num);
		iounmap(enat_cpld);
		enat_cpld = NULL;
	}
}

void atari_unregister_vme_int(unsigned int irq)
{
	if (irq >= VME_SOURCE_BASE && irq < VME_SOURCE_BASE + VME_MAX_SOURCES) {
		irq -= VME_SOURCE_BASE;
		free_vme_vec_bitmap &= ~(1 << irq);
	}
}

