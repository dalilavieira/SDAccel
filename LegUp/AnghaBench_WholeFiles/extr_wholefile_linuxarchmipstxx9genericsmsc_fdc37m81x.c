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
typedef  unsigned char u8 ;

/* Variables and functions */
 scalar_t__ SMSC_FDC37M81X_CONFIG_DATA ; 
 unsigned char SMSC_FDC37M81X_CONFIG_ENTER ; 
 unsigned char SMSC_FDC37M81X_CONFIG_EXIT ; 
 scalar_t__ SMSC_FDC37M81X_CONFIG_INDEX ; 
 scalar_t__ g_smsc_fdc37m81x_base ; 
 unsigned char inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (unsigned char,scalar_t__) ; 

__attribute__((used)) static inline unsigned char smsc_fdc37m81x_rd(unsigned char index)
{
	outb(index, g_smsc_fdc37m81x_base + SMSC_FDC37M81X_CONFIG_INDEX);

	return inb(g_smsc_fdc37m81x_base + SMSC_FDC37M81X_CONFIG_DATA);
}

__attribute__((used)) static inline void smsc_dc37m81x_wr(unsigned char index, unsigned char data)
{
	outb(index, g_smsc_fdc37m81x_base + SMSC_FDC37M81X_CONFIG_INDEX);
	outb(data, g_smsc_fdc37m81x_base + SMSC_FDC37M81X_CONFIG_DATA);
}

void smsc_fdc37m81x_config_beg(void)
{
	if (g_smsc_fdc37m81x_base) {
		outb(SMSC_FDC37M81X_CONFIG_ENTER,
		     g_smsc_fdc37m81x_base + SMSC_FDC37M81X_CONFIG_INDEX);
	}
}

void smsc_fdc37m81x_config_end(void)
{
	if (g_smsc_fdc37m81x_base)
		outb(SMSC_FDC37M81X_CONFIG_EXIT,
		     g_smsc_fdc37m81x_base + SMSC_FDC37M81X_CONFIG_INDEX);
}

u8 smsc_fdc37m81x_config_get(u8 reg)
{
	u8 val = 0;

	if (g_smsc_fdc37m81x_base)
		val = smsc_fdc37m81x_rd(reg);

	return val;
}

void smsc_fdc37m81x_config_set(u8 reg, u8 val)
{
	if (g_smsc_fdc37m81x_base)
		smsc_dc37m81x_wr(reg, val);
}

