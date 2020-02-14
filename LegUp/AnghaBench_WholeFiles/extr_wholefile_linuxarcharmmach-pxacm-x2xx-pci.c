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
struct TYPE_4__ {TYPE_1__* chip; } ;
struct irq_desc {TYPE_2__ irq_data; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* irq_ack ) (TYPE_2__*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_TYPE_EDGE_RISING ; 
 int cmx2xx_it8152_irq_gpio ; 
 int /*<<< orphan*/  gpio_to_irq (int) ; 
 int /*<<< orphan*/  irq_set_chained_handler (int /*<<< orphan*/ ,void (*) (struct irq_desc*)) ; 
 int /*<<< orphan*/  irq_set_irq_type (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  it8152_init_irq () ; 
 int /*<<< orphan*/  it8152_irq_demux (struct irq_desc*) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 

__attribute__((used)) static void cmx2xx_it8152_irq_demux(struct irq_desc *desc)
{
	/* clear our parent irq */
	desc->irq_data.chip->irq_ack(&desc->irq_data);

	it8152_irq_demux(desc);
}

void __cmx2xx_pci_init_irq(int irq_gpio)
{
	it8152_init_irq();

	cmx2xx_it8152_irq_gpio = irq_gpio;

	irq_set_irq_type(gpio_to_irq(irq_gpio), IRQ_TYPE_EDGE_RISING);

	irq_set_chained_handler(gpio_to_irq(irq_gpio),
				cmx2xx_it8152_irq_demux);
}

void cmx2xx_pci_suspend(void) {}

void cmx2xx_pci_resume(void) {}

