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
struct TYPE_2__ {unsigned int eeprom; int* bbram; } ;

/* Variables and functions */
 int BITS_IN_COMMAND ; 
 int EEPROM_DATI ; 
 int EEPROM_DATO ; 
 int EEPROM_ECLK ; 
 int EEPROM_EPROT ; 
 unsigned int EEPROM_READ ; 
 int __raw_readl (unsigned int*) ; 
 int /*<<< orphan*/  __raw_writel (int,unsigned int*) ; 
 int /*<<< orphan*/  delay () ; 
 int /*<<< orphan*/  eeprom_cs_off (unsigned int*) ; 
 int /*<<< orphan*/  eeprom_cs_on (unsigned int*) ; 
 TYPE_1__* hpc3c0 ; 
 scalar_t__ ip22_is_fullhouse () ; 

__attribute__((used)) static inline void eeprom_cmd(unsigned int *ctrl, unsigned cmd, unsigned reg)
{
	unsigned short ser_cmd;
	int i;

	ser_cmd = cmd | (reg << (16 - BITS_IN_COMMAND));
	for (i = 0; i < BITS_IN_COMMAND; i++) {
		if (ser_cmd & (1<<15))	/* if high order bit set */
			__raw_writel(__raw_readl(ctrl) | EEPROM_DATO, ctrl);
		else
			__raw_writel(__raw_readl(ctrl) & ~EEPROM_DATO, ctrl);
		__raw_writel(__raw_readl(ctrl) & ~EEPROM_ECLK, ctrl);
		delay();
		__raw_writel(__raw_readl(ctrl) | EEPROM_ECLK, ctrl);
		delay();
		ser_cmd <<= 1;
	}
	/* see data sheet timing diagram */
	__raw_writel(__raw_readl(ctrl) & ~EEPROM_DATO, ctrl);
}

unsigned short ip22_eeprom_read(unsigned int *ctrl, int reg)
{
	unsigned short res = 0;
	int i;

	__raw_writel(__raw_readl(ctrl) & ~EEPROM_EPROT, ctrl);
	eeprom_cs_on(ctrl);
	eeprom_cmd(ctrl, EEPROM_READ, reg);

	/* clock the data ouf of serial mem */
	for (i = 0; i < 16; i++) {
		__raw_writel(__raw_readl(ctrl) & ~EEPROM_ECLK, ctrl);
		delay();
		__raw_writel(__raw_readl(ctrl) | EEPROM_ECLK, ctrl);
		delay();
		res <<= 1;
		if (__raw_readl(ctrl) & EEPROM_DATI)
			res |= 1;
	}

	eeprom_cs_off(ctrl);

	return res;
}

unsigned short ip22_nvram_read(int reg)
{
	if (ip22_is_fullhouse())
		/* IP22 (Indigo2 aka FullHouse) stores env variables into
		 * 93CS56 Microwire Bus EEPROM 2048 Bit (128x16) */
		return ip22_eeprom_read(&hpc3c0->eeprom, reg);
	else {
		unsigned short tmp;
		/* IP24 (Indy aka Guiness) uses DS1386 8K version */
		reg <<= 1;
		tmp = hpc3c0->bbram[reg++] & 0xff;
		return (tmp << 8) | (hpc3c0->bbram[reg] & 0xff);
	}
}

