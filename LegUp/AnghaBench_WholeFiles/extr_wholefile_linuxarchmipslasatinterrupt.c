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
 unsigned long LASATINT_MASK_SHIFT_200 ; 
 unsigned int LASAT_IRQ_BASE ; 
 int* lasat_int_mask ; 
 int lasat_int_mask_shift ; 
 int* lasat_int_status ; 

void disable_lasat_irq(struct irq_data *d)
{
	unsigned int irq_nr = d->irq - LASAT_IRQ_BASE;

	*lasat_int_mask &= ~(1 << irq_nr) << lasat_int_mask_shift;
}

void enable_lasat_irq(struct irq_data *d)
{
	unsigned int irq_nr = d->irq - LASAT_IRQ_BASE;

	*lasat_int_mask |= (1 << irq_nr) << lasat_int_mask_shift;
}

__attribute__((used)) static inline int ls1bit32(unsigned int x)
{
	int b = 31, s;

	s = 16; if (x << 16 == 0) s = 0; b -= s; x <<= s;
	s =  8; if (x <<  8 == 0) s = 0; b -= s; x <<= s;
	s =  4; if (x <<  4 == 0) s = 0; b -= s; x <<= s;
	s =  2; if (x <<  2 == 0) s = 0; b -= s; x <<= s;
	s =  1; if (x <<  1 == 0) s = 0; b -= s;

	return b;
}

__attribute__((used)) static unsigned long get_int_status_100(void)
{
	return *lasat_int_status & *lasat_int_mask;
}

__attribute__((used)) static unsigned long get_int_status_200(void)
{
	unsigned long int_status;

	int_status = *lasat_int_status;
	int_status &= (int_status >> LASATINT_MASK_SHIFT_200) & 0xffff;
	return int_status;
}

