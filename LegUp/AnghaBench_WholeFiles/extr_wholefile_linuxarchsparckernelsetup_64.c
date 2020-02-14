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
struct seq_file {int dummy; } ;
struct console {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (scalar_t__*) ; 
 unsigned long HWCAP_SPARC_CRYPTO ; 
 scalar_t__* crypto_hwcaps ; 
 int /*<<< orphan*/  flush_user_windows () ; 
 scalar_t__* hwcaps ; 
 int /*<<< orphan*/  prom_cmdline () ; 
 int /*<<< orphan*/  prom_printf (char*) ; 
 int /*<<< orphan*/  prom_write (char const*,unsigned int) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,char*,scalar_t__) ; 
 int /*<<< orphan*/  seq_putc (struct seq_file*,char) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
 unsigned long sparc64_elf_hwcap ; 
 int /*<<< orphan*/  stop_a_enabled ; 

__attribute__((used)) static void
prom_console_write(struct console *con, const char *s, unsigned int n)
{
	prom_write(s, n);
}

void cpucap_info(struct seq_file *m)
{
	unsigned long caps = sparc64_elf_hwcap;
	int i, printed = 0;

	seq_puts(m, "cpucaps\t\t: ");
	for (i = 0; i < ARRAY_SIZE(hwcaps); i++) {
		unsigned long bit = 1UL << i;
		if (hwcaps[i] && (caps & bit)) {
			seq_printf(m, "%s%s",
				   printed ? "," : "", hwcaps[i]);
			printed++;
		}
	}
	if (caps & HWCAP_SPARC_CRYPTO) {
		unsigned long cfr;

		__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
		for (i = 0; i < ARRAY_SIZE(crypto_hwcaps); i++) {
			unsigned long bit = 1UL << i;
			if (cfr & bit) {
				seq_printf(m, "%s%s",
					   printed ? "," : "", crypto_hwcaps[i]);
				printed++;
			}
		}
	}
	seq_putc(m, '\n');
}

void sun_do_break(void)
{
	if (!stop_a_enabled)
		return;

	prom_printf("\n");
	flush_user_windows();

	prom_cmdline();
}

