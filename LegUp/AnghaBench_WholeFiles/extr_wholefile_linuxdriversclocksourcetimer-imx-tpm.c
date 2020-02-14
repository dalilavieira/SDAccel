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

/* Variables and functions */
 scalar_t__ TPM_C0SC ; 
 unsigned int TPM_C0SC_CHIE ; 
 unsigned int TPM_C0SC_MODE_MASK ; 
 unsigned int TPM_C0SC_MODE_SHIFT ; 
 unsigned int TPM_C0SC_MODE_SW_COMPARE ; 
 scalar_t__ TPM_CNT ; 
 scalar_t__ TPM_STATUS ; 
 unsigned int TPM_STATUS_CH0F ; 
 unsigned long readl (scalar_t__) ; 
 scalar_t__ timer_base ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static inline void tpm_timer_disable(void)
{
	unsigned int val;

	/* channel disable */
	val = readl(timer_base + TPM_C0SC);
	val &= ~(TPM_C0SC_MODE_MASK | TPM_C0SC_CHIE);
	writel(val, timer_base + TPM_C0SC);
}

__attribute__((used)) static inline void tpm_timer_enable(void)
{
	unsigned int val;

	/* channel enabled in sw compare mode */
	val = readl(timer_base + TPM_C0SC);
	val |= (TPM_C0SC_MODE_SW_COMPARE << TPM_C0SC_MODE_SHIFT) |
	       TPM_C0SC_CHIE;
	writel(val, timer_base + TPM_C0SC);
}

__attribute__((used)) static inline void tpm_irq_acknowledge(void)
{
	writel(TPM_STATUS_CH0F, timer_base + TPM_STATUS);
}

__attribute__((used)) static inline unsigned long tpm_read_counter(void)
{
	return readl(timer_base + TPM_CNT);
}

__attribute__((used)) static unsigned long tpm_read_current_timer(void)
{
	return tpm_read_counter();
}

