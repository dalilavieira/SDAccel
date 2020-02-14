#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ vm_offset_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  dccmode ;
struct TYPE_3__ {int (* rd0 ) () ;int /*<<< orphan*/  (* rr0 ) () ;int /*<<< orphan*/  (* td0 ) (char) ;int /*<<< orphan*/  (* tr0 ) () ;int /*<<< orphan*/  (* uart_init ) () ;} ;
typedef  int /*<<< orphan*/ * DTEntry ;

/* Variables and functions */
 scalar_t__ DTFindEntry (char*,char*,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  DTGetProperty (int /*<<< orphan*/ *,char*,void**,scalar_t__*) ; 
 scalar_t__ PE_parse_boot_argn (char*,scalar_t__*,int) ; 
 TYPE_1__ dcc_serial_functions ; 
 TYPE_1__* gPESF ; 
 scalar_t__ kSuccess ; 
 int /*<<< orphan*/  kprintf (char*) ; 
 int /*<<< orphan*/  ml_io_map (scalar_t__,uintptr_t) ; 
 int /*<<< orphan*/  panic_unimplemented () ; 
 scalar_t__ pe_arm_get_soc_base_phys () ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  stub2 () ; 
 int /*<<< orphan*/  stub3 () ; 
 int /*<<< orphan*/  stub4 (char) ; 
 int /*<<< orphan*/  stub5 () ; 
 int stub6 () ; 
 int /*<<< orphan*/  uart_base ; 
 int uart_initted ; 

__attribute__((used)) static unsigned int
read_dtr(void)
{
#ifdef __arm__
	unsigned int	c;
	__asm__ volatile(
		"mrc p14, 0, %0, c0, c5\n"
:		"=r"(c));
	return c;
#else
	/* ARM64_TODO */
	panic_unimplemented();
	return 0;
#endif
}

__attribute__((used)) static void
write_dtr(unsigned int c)
{
#ifdef __arm__
	__asm__ volatile(
		"mcr p14, 0, %0, c0, c5\n"
		:
		:"r"(c));
#else
	/* ARM64_TODO */
	(void)c;
	panic_unimplemented();
#endif
}

__attribute__((used)) static int
dcc_tr0(void)
{
#ifdef __arm__
	return !(arm_debug_read_dscr() & ARM_DBGDSCR_TXFULL);
#else
	/* ARM64_TODO */
	panic_unimplemented();
	return 0;
#endif
}

__attribute__((used)) static void
dcc_td0(int c)
{
	write_dtr(c);
}

__attribute__((used)) static int
dcc_rr0(void)
{
#ifdef __arm__
	return arm_debug_read_dscr() & ARM_DBGDSCR_RXFULL;
#else
	/* ARM64_TODO */
	panic_unimplemented();
	return 0;
#endif
}

__attribute__((used)) static int
dcc_rd0(void)
{
	return read_dtr();
}

int
serial_init(void)
{
	DTEntry		entryP = NULL;
	uint32_t	prop_size, dccmode;
	vm_offset_t	soc_base;
	uintptr_t	*reg_prop;
	uint32_t 	*prop_value = NULL;
	char		*serial_compat = 0;
#ifdef SHMCON
	uint32_t	jconmode;
#endif
#ifdef DOCKFIFO_UART
	uint32_t	no_dockfifo_uart;
#endif
#ifdef DOCKCHANNEL_UART
	uint32_t	no_dockchannel_uart;
#endif
#ifdef PI3_UART
	uint32_t	is_pi3;
#endif

	if (uart_initted && gPESF) {
		gPESF->uart_init();
		kprintf("reinit serial\n");
		return 1;
	}

	dccmode = 0;
	if (PE_parse_boot_argn("dcc", &dccmode, sizeof (dccmode))) {
		gPESF = &dcc_serial_functions;
		uart_initted = 1;
		return 1;
	}
#ifdef SHMCON
	jconmode = 0;
	if (PE_parse_boot_argn("jcon", &jconmode, sizeof jconmode)) {
		gPESF = &shmcon_serial_functions;
		gPESF->uart_init();
		uart_initted = 1;
		return 1;
	}
#endif /* SHMCON */

#ifdef PI3_UART
#pragma unused(prop_value)
	is_pi3 = 0;
	if (PE_parse_boot_argn("-pi3", &is_pi3, sizeof(is_pi3))) { // FIXME: remove the not operator after boot args are set up.
		pi3_gpio_base_vaddr = ml_io_map((vm_offset_t)BCM2837_GPIO_BASE, BCM2837_GPIO_SIZE);
		pi3_aux_base_vaddr = ml_io_map((vm_offset_t)BCM2837_AUX_BASE, BCM2837_AUX_SIZE);
		gPESF = &pi3_uart_serial_functions;
		gPESF->uart_init();
		uart_initted = 1;
		return 1;
	}
#endif /* PI3_UART */

	soc_base = pe_arm_get_soc_base_phys();

	if (soc_base == 0)
		return 0;

#ifdef DOCKFIFO_UART
	no_dockfifo_uart = 0;
	PE_parse_boot_argn("no-dockfifo-uart", &no_dockfifo_uart, sizeof(no_dockfifo_uart));
	if (no_dockfifo_uart == 0) {
		if (DTFindEntry("name", "dockfifo-uart", &entryP) == kSuccess) {
			DTGetProperty(entryP, "reg", (void **)&reg_prop, &prop_size);
			uart_base = ml_io_map(soc_base + *reg_prop, *(reg_prop + 1));
		}
		else {
			return 0;
		}
		gPESF = &dockfifo_uart_serial_functions;
		gPESF->uart_init();
		uart_initted = 1;
		return 1;
	}
#endif /* DOCKFIFO_UART */

#ifdef DOCKCHANNEL_UART
	no_dockchannel_uart = 0;
	// Keep the old name for boot-arg
	PE_parse_boot_argn("no-dockfifo-uart", &no_dockchannel_uart, sizeof(no_dockchannel_uart));
	if (no_dockchannel_uart == 0) {
		if (DTFindEntry("name", "dockchannel-uart", &entryP) == kSuccess) {
			DTGetProperty(entryP, "reg", (void **)&reg_prop, &prop_size);
			// Should be two reg entries
			if (prop_size/sizeof(uintptr_t) != 4)
				panic("Malformed dockchannel-uart property");
			uart_base = ml_io_map(soc_base + *reg_prop, *(reg_prop + 1));
			dock_agent_base = ml_io_map(soc_base + *(reg_prop + 2), *(reg_prop + 3));
			gPESF = &dockchannel_uart_serial_functions;
			DTGetProperty(entryP, "max-aop-clk", (void **)&prop_value, &prop_size);
			max_dockchannel_drain_period = (uint32_t)((prop_value)?  (*prop_value * 0.03) : DOCKCHANNEL_DRAIN_PERIOD);
			DTGetProperty(entryP, "enable-sw-drain", (void **)&prop_value, &prop_size);
			use_sw_drain = (prop_value)?  *prop_value : 0;
			gPESF->uart_init();
			uart_initted = 1;
			return 1;
		}
		// If no dockchannel-uart is found in the device tree, fall back
		// to looking for the traditional UART serial console.
	}
#endif /* DOCKCHANNEL_UART */

	/*
	 * The boot serial port should have a property named "boot-console".
	 * If we don't find it there, look for "uart0" and "uart1".
	 */

	if (DTFindEntry("boot-console", NULL, &entryP) == kSuccess) {
		DTGetProperty(entryP, "reg", (void **)&reg_prop, &prop_size);
		uart_base = ml_io_map(soc_base + *reg_prop, *(reg_prop + 1));
		if (serial_compat == 0)
			DTGetProperty(entryP, "compatible", (void **)&serial_compat, &prop_size);
	} else if (DTFindEntry("name", "uart0", &entryP) == kSuccess) {
		DTGetProperty(entryP, "reg", (void **)&reg_prop, &prop_size);
		uart_base = ml_io_map(soc_base + *reg_prop, *(reg_prop + 1));
		if (serial_compat == 0)
			DTGetProperty(entryP, "compatible", (void **)&serial_compat, &prop_size);
	} else if (DTFindEntry("name", "uart1", &entryP) == kSuccess) {
		DTGetProperty(entryP, "reg", (void **)&reg_prop, &prop_size);
		uart_base = ml_io_map(soc_base + *reg_prop, *(reg_prop + 1));
		if (serial_compat == 0)
			DTGetProperty(entryP, "compatible", (void **)&serial_compat, &prop_size);
	}
#ifdef	S3CUART
	if (NULL != entryP) {
		DTGetProperty(entryP, "pclk", (void **)&prop_value, &prop_size);
		if (prop_value) dt_pclk = *prop_value;

		prop_value = NULL;
		DTGetProperty(entryP, "sampling", (void **)&prop_value, &prop_size);
		if (prop_value) dt_sampling = *prop_value;

		prop_value = NULL;
		DTGetProperty(entryP, "ubrdiv", (void **)&prop_value, &prop_size);
		if (prop_value) dt_ubrdiv = *prop_value;
	}
	if (!strcmp(serial_compat, "uart,16550"))
		gPESF = &ln2410_serial_functions;
	else if (!strcmp(serial_compat, "uart-16550"))
		gPESF = &ln2410_serial_functions;
	else if (!strcmp(serial_compat, "uart,s5i3000"))
		gPESF = &ln2410_serial_functions;
	else if (!strcmp(serial_compat, "uart-1,samsung"))
		gPESF = &ln2410_serial_functions;
#elif	defined (ARM_BOARD_CONFIG_MV88F6710)
	if (!strcmp(serial_compat, "uart16x50,mmio"))
		gPESF = &uart16x50_serial_functions;
#endif
	else
		return 0;

	gPESF->uart_init();

	uart_initted = 1;

	return 1;
}

void
uart_putc(char c)
{
	if (uart_initted) {
		while (!gPESF->tr0());	/* Wait until THR is empty. */
		gPESF->td0(c);
	}
}

int
uart_getc(void)
{				/* returns -1 if no data available */
	if (uart_initted) {
		if (!gPESF->rr0())
			return -1;	/* Receive data read */
		return gPESF->rd0();
	}
	return -1;
}

