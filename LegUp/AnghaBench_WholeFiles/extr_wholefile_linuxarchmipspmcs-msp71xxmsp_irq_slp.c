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
struct irq_data {unsigned int irq; } ;

/* Variables and functions */
 unsigned int MSP_PER_INTBASE ; 
 unsigned int MSP_SLP_INTBASE ; 
 int* PER_INT_MSK_REG ; 
 int* PER_INT_STS_REG ; 
 int* SLP_INT_MSK_REG ; 
 int* SLP_INT_STS_REG ; 

__attribute__((used)) static inline void unmask_msp_slp_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	/* check for PER interrupt range */
	if (irq < MSP_PER_INTBASE)
		*SLP_INT_MSK_REG |= (1 << (irq - MSP_SLP_INTBASE));
	else
		*PER_INT_MSK_REG |= (1 << (irq - MSP_PER_INTBASE));
}

__attribute__((used)) static inline void mask_msp_slp_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	/* check for PER interrupt range */
	if (irq < MSP_PER_INTBASE)
		*SLP_INT_MSK_REG &= ~(1 << (irq - MSP_SLP_INTBASE));
	else
		*PER_INT_MSK_REG &= ~(1 << (irq - MSP_PER_INTBASE));
}

__attribute__((used)) static inline void ack_msp_slp_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	/* check for PER interrupt range */
	if (irq < MSP_PER_INTBASE)
		*SLP_INT_STS_REG = (1 << (irq - MSP_SLP_INTBASE));
	else
		*PER_INT_STS_REG = (1 << (irq - MSP_PER_INTBASE));
}

