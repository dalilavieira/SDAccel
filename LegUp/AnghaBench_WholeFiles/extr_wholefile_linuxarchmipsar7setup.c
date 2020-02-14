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
typedef  int u32 ;
typedef  int u16 ;

/* Variables and functions */
#define  AR7_CHIP_7100 135 
#define  AR7_CHIP_7200 134 
#define  AR7_CHIP_7300 133 
#define  AR7_CHIP_TITAN 132 
 scalar_t__ AR7_REGS_POWER ; 
 scalar_t__ AR7_REGS_RESET ; 
 scalar_t__ AR7_RESET_SOFTWARE ; 
#define  TITAN_CHIP_1050 131 
#define  TITAN_CHIP_1055 130 
#define  TITAN_CHIP_1056 129 
#define  TITAN_CHIP_1060 128 
 int ar7_chip_id () ; 
 int* ioremap (scalar_t__,int) ; 
 int readl (int*) ; 
 int titan_chip_id () ; 
 int /*<<< orphan*/  writel (int,int*) ; 

__attribute__((used)) static void ar7_machine_restart(char *command)
{
	u32 *softres_reg = ioremap(AR7_REGS_RESET + AR7_RESET_SOFTWARE, 1);

	writel(1, softres_reg);
}

__attribute__((used)) static void ar7_machine_halt(void)
{
	while (1)
		;
}

__attribute__((used)) static void ar7_machine_power_off(void)
{
	u32 *power_reg = (u32 *)ioremap(AR7_REGS_POWER, 1);
	u32 power_state = readl(power_reg) | (3 << 30);

	writel(power_state, power_reg);
	ar7_machine_halt();
}

const char *get_system_type(void)
{
	u16 chip_id = ar7_chip_id();
	u16 titan_variant_id = titan_chip_id();

	switch (chip_id) {
	case AR7_CHIP_7100:
		return "TI AR7 (TNETD7100)";
	case AR7_CHIP_7200:
		return "TI AR7 (TNETD7200)";
	case AR7_CHIP_7300:
		return "TI AR7 (TNETD7300)";
	case AR7_CHIP_TITAN:
		switch (titan_variant_id) {
		case TITAN_CHIP_1050:
			return "TI AR7 (TNETV1050)";
		case TITAN_CHIP_1055:
			return "TI AR7 (TNETV1055)";
		case TITAN_CHIP_1056:
			return "TI AR7 (TNETV1056)";
		case TITAN_CHIP_1060:
			return "TI AR7 (TNETV1060)";
		}
	default:
		return "TI AR7 (unknown)";
	}
}

