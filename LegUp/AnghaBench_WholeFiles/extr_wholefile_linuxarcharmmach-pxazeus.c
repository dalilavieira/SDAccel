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
typedef  int u8 ;
typedef  int u16 ;
struct TYPE_4__ {TYPE_1__* chip; } ;
struct irq_desc {TYPE_2__ irq_data; } ;
struct irq_data {unsigned int irq; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* irq_ack ) (TYPE_2__*) ;} ;

/* Variables and functions */
#define  PXA2XX_UDC_CMD_CONNECT 129 
#define  PXA2XX_UDC_CMD_DISCONNECT 128 
 unsigned int PXA_ISA_IRQ (int /*<<< orphan*/ ) ; 
 int UP2OCR ; 
 int UP2OCR_DMPDE ; 
 int UP2OCR_DPPDE ; 
 int UP2OCR_DPPUE ; 
 int UP2OCR_HXOE ; 
 int UP2OCR_HXS ; 
 int /*<<< orphan*/  ZEUS_CPLD_CONTROL ; 
 int ZEUS_CPLD_CONTROL_CF_RST ; 
 int /*<<< orphan*/  ZEUS_CPLD_ISA_IRQ ; 
 int __ffs (unsigned long) ; 
 unsigned long __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writew (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int,int) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 scalar_t__ gpio_direction_input (int) ; 
 int /*<<< orphan*/  gpio_free (int) ; 
 int /*<<< orphan*/  gpio_get_value (int) ; 
 scalar_t__ gpio_request (int,char*) ; 
 scalar_t__ likely (unsigned long) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 
 unsigned long zeus_irq_enabled_mask ; 
 int* zeus_isa_irq_map ; 
 int* zeus_isa_irqs ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static inline int zeus_irq_to_bitmask(unsigned int irq)
{
	return zeus_isa_irq_map[irq - PXA_ISA_IRQ(0)];
}

__attribute__((used)) static inline int zeus_bit_to_irq(int bit)
{
	return zeus_isa_irqs[bit] + PXA_ISA_IRQ(0);
}

__attribute__((used)) static void zeus_ack_irq(struct irq_data *d)
{
	__raw_writew(zeus_irq_to_bitmask(d->irq), ZEUS_CPLD_ISA_IRQ);
}

__attribute__((used)) static void zeus_mask_irq(struct irq_data *d)
{
	zeus_irq_enabled_mask &= ~(zeus_irq_to_bitmask(d->irq));
}

__attribute__((used)) static void zeus_unmask_irq(struct irq_data *d)
{
	zeus_irq_enabled_mask |= zeus_irq_to_bitmask(d->irq);
}

__attribute__((used)) static inline unsigned long zeus_irq_pending(void)
{
	return __raw_readw(ZEUS_CPLD_ISA_IRQ) & zeus_irq_enabled_mask;
}

__attribute__((used)) static void zeus_irq_handler(struct irq_desc *desc)
{
	unsigned int irq;
	unsigned long pending;

	pending = zeus_irq_pending();
	do {
		/* we're in a chained irq handler,
		 * so ack the interrupt by hand */
		desc->irq_data.chip->irq_ack(&desc->irq_data);

		if (likely(pending)) {
			irq = zeus_bit_to_irq(__ffs(pending));
			generic_handle_irq(irq);
		}
		pending = zeus_irq_pending();
	} while (pending);
}

__attribute__((used)) static void zeus_cf_reset(int state)
{
	u16 cpld_state = __raw_readw(ZEUS_CPLD_CONTROL);

	if (state)
		cpld_state |= ZEUS_CPLD_CONTROL_CF_RST;
	else
		cpld_state &= ~ZEUS_CPLD_CONTROL_CF_RST;

	__raw_writew(cpld_state, ZEUS_CPLD_CONTROL);
}

__attribute__((used)) static void zeus_udc_command(int cmd)
{
	switch (cmd) {
	case PXA2XX_UDC_CMD_DISCONNECT:
		pr_info("zeus: disconnecting USB client\n");
		UP2OCR = UP2OCR_HXOE | UP2OCR_HXS | UP2OCR_DMPDE | UP2OCR_DPPDE;
		break;

	case PXA2XX_UDC_CMD_CONNECT:
		pr_info("zeus: connecting USB client\n");
		UP2OCR = UP2OCR_HXOE | UP2OCR_DPPUE;
		break;
	}
}

__attribute__((used)) static inline void zeus_setup_apm(void)
{
}

__attribute__((used)) static int zeus_get_pcb_info(struct i2c_client *client, unsigned gpio,
			     unsigned ngpio, void *context)
{
	int i;
	u8 pcb_info = 0;

	for (i = 0; i < 8; i++) {
		int pcb_bit = gpio + i + 8;

		if (gpio_request(pcb_bit, "pcb info")) {
			dev_err(&client->dev, "Can't request pcb info %d\n", i);
			continue;
		}

		if (gpio_direction_input(pcb_bit)) {
			dev_err(&client->dev, "Can't read pcb info %d\n", i);
			gpio_free(pcb_bit);
			continue;
		}

		pcb_info |= !!gpio_get_value(pcb_bit) << i;

		gpio_free(pcb_bit);
	}

	dev_info(&client->dev, "Zeus PCB version %d issue %d\n",
		 pcb_info >> 4, pcb_info & 0xf);

	return 0;
}

