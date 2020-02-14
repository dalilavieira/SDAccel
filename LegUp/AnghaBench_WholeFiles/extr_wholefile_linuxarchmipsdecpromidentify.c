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
 scalar_t__ CKSEG1ADDR (scalar_t__) ; 
 scalar_t__ IOASIC_IOCTL ; 
 int /*<<< orphan*/  IOASIC_SLOT_SIZE ; 
 scalar_t__ IOASIC_TOY ; 
 scalar_t__ KN01_RTC ; 
 scalar_t__ KN01_SLOT_BASE ; 
 int /*<<< orphan*/  KN01_SLOT_SIZE ; 
 scalar_t__ KN02XA_SLOT_BASE ; 
 scalar_t__ KN02_RTC ; 
 scalar_t__ KN02_SLOT_BASE ; 
 int /*<<< orphan*/  KN02_SLOT_SIZE ; 
 scalar_t__ KN03_SLOT_BASE ; 
 scalar_t__ dec_kn_slot_base ; 
 int /*<<< orphan*/  dec_kn_slot_size ; 
 void* dec_rtc_base ; 
 char** dec_system_strings ; 
 int dec_tc_bus ; 
 void* ioasic_base ; 
 size_t mips_machtype ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*) ; 

const char *get_system_type(void)
{
#define STR_BUF_LEN	64
	static char system[STR_BUF_LEN];
	static int called = 0;

	if (called == 0) {
		called = 1;
		snprintf(system, STR_BUF_LEN, "Digital %s",
			 dec_system_strings[mips_machtype]);
	}

	return system;
}

__attribute__((used)) static inline void prom_init_kn01(void)
{
	dec_kn_slot_base = KN01_SLOT_BASE;
	dec_kn_slot_size = KN01_SLOT_SIZE;

	dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + KN01_RTC);
}

__attribute__((used)) static inline void prom_init_kn230(void)
{
	dec_kn_slot_base = KN01_SLOT_BASE;
	dec_kn_slot_size = KN01_SLOT_SIZE;

	dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + KN01_RTC);
}

__attribute__((used)) static inline void prom_init_kn02(void)
{
	dec_kn_slot_base = KN02_SLOT_BASE;
	dec_kn_slot_size = KN02_SLOT_SIZE;
	dec_tc_bus = 1;

	dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + KN02_RTC);
}

__attribute__((used)) static inline void prom_init_kn02xa(void)
{
	dec_kn_slot_base = KN02XA_SLOT_BASE;
	dec_kn_slot_size = IOASIC_SLOT_SIZE;
	dec_tc_bus = 1;

	ioasic_base = (void *)CKSEG1ADDR(dec_kn_slot_base + IOASIC_IOCTL);
	dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + IOASIC_TOY);
}

__attribute__((used)) static inline void prom_init_kn03(void)
{
	dec_kn_slot_base = KN03_SLOT_BASE;
	dec_kn_slot_size = IOASIC_SLOT_SIZE;
	dec_tc_bus = 1;

	ioasic_base = (void *)CKSEG1ADDR(dec_kn_slot_base + IOASIC_IOCTL);
	dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + IOASIC_TOY);
}

