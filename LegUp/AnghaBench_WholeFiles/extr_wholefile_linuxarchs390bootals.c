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
typedef  int u64 ;
typedef  int u16 ;
struct cpuid {int machine; } ;
struct TYPE_2__ {unsigned long* stfle_fac_list; int stfl_fac_list; } ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned long*) ; 
 int BITS_PER_LONG ; 
 TYPE_1__ S390_lowcore ; 
 unsigned long* als ; 
 int /*<<< orphan*/  disabled_wait (int) ; 
 int /*<<< orphan*/  get_cpu_id (struct cpuid*) ; 
 int /*<<< orphan*/  sclp_early_printk (char*) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int strlen (char*) ; 

__attribute__((used)) static void u16_to_hex(char *str, u16 val)
{
	int i, num;

	for (i = 1; i <= 4; i++) {
		num = (val >> (16 - 4 * i)) & 0xf;
		if (num >= 10)
			num += 7;
		*str++ = '0' + num;
	}
	*str = '\0';
}

__attribute__((used)) static void print_machine_type(void)
{
	static char mach_str[80] = "Detected machine-type number: ";
	char type_str[5];
	struct cpuid id;

	get_cpu_id(&id);
	u16_to_hex(type_str, id.machine);
	strcat(mach_str, type_str);
	strcat(mach_str, "\n");
	sclp_early_printk(mach_str);
}

__attribute__((used)) static void u16_to_decimal(char *str, u16 val)
{
	int div = 1;

	while (div * 10 <= val)
		div *= 10;
	while (div) {
		*str++ = '0' + val / div;
		val %= div;
		div /= 10;
	}
	*str = '\0';
}

__attribute__((used)) static void print_missing_facilities(void)
{
	static char als_str[80] = "Missing facilities: ";
	unsigned long val;
	char val_str[6];
	int i, j, first;

	first = 1;
	for (i = 0; i < ARRAY_SIZE(als); i++) {
		val = ~S390_lowcore.stfle_fac_list[i] & als[i];
		for (j = 0; j < BITS_PER_LONG; j++) {
			if (!(val & (1UL << (BITS_PER_LONG - 1 - j))))
				continue;
			if (!first)
				strcat(als_str, ",");
			/*
			 * Make sure we stay within one line. Consider that
			 * each facility bit adds up to five characters and
			 * z/VM adds a four character prefix.
			 */
			if (strlen(als_str) > 70) {
				strcat(als_str, "\n");
				sclp_early_printk(als_str);
				*als_str = '\0';
			}
			u16_to_decimal(val_str, i * BITS_PER_LONG + j);
			strcat(als_str, val_str);
			first = 0;
		}
	}
	strcat(als_str, "\n");
	sclp_early_printk(als_str);
	sclp_early_printk("See Principles of Operations for facility bits\n");
}

__attribute__((used)) static void facility_mismatch(void)
{
	sclp_early_printk("The Linux kernel requires more recent processor hardware\n");
	print_machine_type();
	print_missing_facilities();
	disabled_wait(0x8badcccc);
}

void verify_facilities(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(S390_lowcore.stfle_fac_list); i++)
		S390_lowcore.stfle_fac_list[i] = 0;
	asm volatile(
		"	stfl	0(0)\n"
		: "=m" (S390_lowcore.stfl_fac_list));
	S390_lowcore.stfle_fac_list[0] = (u64)S390_lowcore.stfl_fac_list << 32;
	if (S390_lowcore.stfl_fac_list & 0x01000000) {
		register unsigned long reg0 asm("0") = ARRAY_SIZE(als) - 1;

		asm volatile(".insn s,0xb2b00000,0(%1)" /* stfle */
			     : "+d" (reg0)
			     : "a" (&S390_lowcore.stfle_fac_list)
			     : "memory", "cc");
	}
	for (i = 0; i < ARRAY_SIZE(als); i++) {
		if ((S390_lowcore.stfle_fac_list[i] & als[i]) != als[i])
			facility_mismatch();
	}
}

