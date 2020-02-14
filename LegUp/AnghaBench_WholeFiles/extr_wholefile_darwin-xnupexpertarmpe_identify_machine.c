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
typedef  scalar_t__ vm_offset_t ;
typedef  int uint32_t ;
typedef  struct tbd_ops* tbd_ops_t ;
struct tbd_ops {int /*<<< orphan*/ * member_2; int /*<<< orphan*/ * member_1; int /*<<< orphan*/ * member_0; } ;
typedef  int /*<<< orphan*/  clock_frequency_info_t ;
typedef  int /*<<< orphan*/  boot_args ;
struct TYPE_2__ {int timebase_frequency_hz; int bus_clock_rate_hz; int cpu_clock_rate_hz; int dec_clock_rate_hz; unsigned long long bus_frequency_hz; unsigned long bus_frequency_min_hz; unsigned long bus_frequency_max_hz; unsigned long long mem_frequency_hz; unsigned long mem_frequency_min_hz; unsigned long mem_frequency_max_hz; unsigned long long prf_frequency_hz; unsigned long prf_frequency_min_hz; unsigned long prf_frequency_max_hz; unsigned long long fix_frequency_hz; unsigned long long cpu_frequency_hz; unsigned long cpu_frequency_min_hz; unsigned long cpu_frequency_max_hz; int bus_clock_rate_num; int bus_clock_rate_den; int bus_to_cpu_rate_num; int bus_to_cpu_rate_den; int bus_to_dec_rate_num; int bus_to_dec_rate_den; } ;
typedef  int /*<<< orphan*/  OpaqueDTEntryIterator ;
typedef  int /*<<< orphan*/  DTEntry ;

/* Variables and functions */
 int DTFindEntry (char*,char*,int /*<<< orphan*/ *) ; 
 int DTGetProperty (int /*<<< orphan*/ ,char*,void**,...) ; 
 int DTInitEntryIterator (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int DTIterateEntries (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int DTLookupEntry (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SOC_DEVICE_TYPE_BUFFER_SIZE ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  bzero (void*,int) ; 
 int /*<<< orphan*/  fleh_fiq_generic ; 
 TYPE_1__ gPEClockFrequencyInfo ; 
 scalar_t__ gPESoCBasePhys ; 
 scalar_t__ gPESoCDeviceType ; 
 scalar_t__ gPESoCDeviceTypeBuffer ; 
 scalar_t__ gPicBase ; 
 scalar_t__ gSocPhys ; 
 int gTCFG0Value ; 
 scalar_t__ gTimerBase ; 
 int kSuccess ; 
 int /*<<< orphan*/  kprintf (char*,...) ; 
 int /*<<< orphan*/  ml_init_arm_debug_interface (void*,scalar_t__) ; 
 int /*<<< orphan*/  ml_init_timebase (void*,struct tbd_ops*,scalar_t__,int) ; 
 scalar_t__ ml_io_map (scalar_t__,uintptr_t) ; 
 scalar_t__ pe_arm_get_soc_base_phys () ; 
static  int pe_arm_init_timer (void*) ; 
 int /*<<< orphan*/  strcmp (scalar_t__,char*) ; 
 int /*<<< orphan*/  strlcpy (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ strncmp (char*,char*,unsigned int) ; 

void
pe_identify_machine(boot_args * bootArgs)
{
	OpaqueDTEntryIterator iter;
	DTEntry		cpus, cpu;
	uint32_t	mclk = 0, hclk = 0, pclk = 0, tclk = 0, use_dt = 0;
	unsigned long  *value;
	unsigned int	size;
	int		err;

	(void)bootArgs;

	if (pe_arm_get_soc_base_phys() == 0)
		return;

	/* Clear the gPEClockFrequencyInfo struct */
	bzero((void *)&gPEClockFrequencyInfo, sizeof(clock_frequency_info_t));

	if (!strcmp(gPESoCDeviceType, "s3c2410-io")) {
		mclk = 192 << 23;
		hclk = mclk / 2;
		pclk = hclk / 2;
		tclk = (1 << (23 + 2)) / 10;
		tclk = pclk / tclk;

		gTCFG0Value = tclk - 1;

		tclk = pclk / (4 * tclk);	/* Calculate the "actual"
						 * Timer0 frequency in fixed
						 * point. */

		mclk = (mclk >> 17) * (125 * 125);
		hclk = (hclk >> 17) * (125 * 125);
		pclk = (pclk >> 17) * (125 * 125);
		tclk = (((((tclk * 125) + 2) >> 2) * 125) + (1 << 14)) >> 15;

	} else if (!strcmp(gPESoCDeviceType, "integratorcp-io")) {
		mclk = 200000000;
		hclk = mclk / 2;
		pclk = hclk / 2;
		tclk = 100000;
	} else if (!strcmp(gPESoCDeviceType, "olocreek-io")) {
		mclk = 1000000000;
		hclk = mclk / 8;
		pclk = hclk / 2;
		tclk = pclk;
	} else if (!strcmp(gPESoCDeviceType, "omap3430sdp-io")) {
		 mclk = 332000000;
		 hclk =  19200000;
		 pclk = hclk;
		 tclk = pclk;
	} else if (!strcmp(gPESoCDeviceType, "s5i3000-io")) {
		mclk = 400000000;
		hclk = mclk / 4;
		pclk = hclk / 2;
		tclk = 100000;	/* timer is at 100khz */

	} else if (!strcmp(gPESoCDeviceType, "bcm2837-io")) {
		mclk = 1200000000;
		hclk = mclk / 4;
		pclk = hclk / 2;
		tclk = 1000000;
	} else
		use_dt = 1;

	if (use_dt) {
		/* Start with default values. */
		gPEClockFrequencyInfo.timebase_frequency_hz = 24000000;
		gPEClockFrequencyInfo.bus_clock_rate_hz = 100000000;
		gPEClockFrequencyInfo.cpu_clock_rate_hz = 400000000;

		err = DTLookupEntry(NULL, "/cpus", &cpus);
		assert(err == kSuccess);

		err = DTInitEntryIterator(cpus, &iter);
		assert(err == kSuccess);

		while (kSuccess == DTIterateEntries(&iter, &cpu)) {
			if ((kSuccess != DTGetProperty(cpu, "state", (void **)&value, &size)) ||
			    (strncmp((char*)value, "running", size) != 0))
				continue;

			/* Find the time base frequency first. */
			if (DTGetProperty(cpu, "timebase-frequency", (void **)&value, &size) == kSuccess) {
				/*
				 * timebase_frequency_hz is only 32 bits, and
				 * the device tree should never provide 64
				 * bits so this if should never be taken.
				 */
				if (size == 8)
					gPEClockFrequencyInfo.timebase_frequency_hz = *(unsigned long long *)value;
				else
					gPEClockFrequencyInfo.timebase_frequency_hz = *value;
			}
			gPEClockFrequencyInfo.dec_clock_rate_hz = gPEClockFrequencyInfo.timebase_frequency_hz;

			/* Find the bus frequency next. */
			if (DTGetProperty(cpu, "bus-frequency", (void **)&value, &size) == kSuccess) {
				if (size == 8)
					gPEClockFrequencyInfo.bus_frequency_hz = *(unsigned long long *)value;
				else
					gPEClockFrequencyInfo.bus_frequency_hz = *value;
			}
			gPEClockFrequencyInfo.bus_frequency_min_hz = gPEClockFrequencyInfo.bus_frequency_hz;
			gPEClockFrequencyInfo.bus_frequency_max_hz = gPEClockFrequencyInfo.bus_frequency_hz;

			if (gPEClockFrequencyInfo.bus_frequency_hz < 0x100000000ULL)
				gPEClockFrequencyInfo.bus_clock_rate_hz = gPEClockFrequencyInfo.bus_frequency_hz;
			else
				gPEClockFrequencyInfo.bus_clock_rate_hz = 0xFFFFFFFF;

			/* Find the memory frequency next. */
			if (DTGetProperty(cpu, "memory-frequency", (void **)&value, &size) == kSuccess) {
				if (size == 8)
					gPEClockFrequencyInfo.mem_frequency_hz = *(unsigned long long *)value;
				else
					gPEClockFrequencyInfo.mem_frequency_hz = *value;
			}
			gPEClockFrequencyInfo.mem_frequency_min_hz = gPEClockFrequencyInfo.mem_frequency_hz;
			gPEClockFrequencyInfo.mem_frequency_max_hz = gPEClockFrequencyInfo.mem_frequency_hz;

			/* Find the peripheral frequency next. */
			if (DTGetProperty(cpu, "peripheral-frequency", (void **)&value, &size) == kSuccess) {
				if (size == 8)
					gPEClockFrequencyInfo.prf_frequency_hz = *(unsigned long long *)value;
				else
					gPEClockFrequencyInfo.prf_frequency_hz = *value;
			}
			gPEClockFrequencyInfo.prf_frequency_min_hz = gPEClockFrequencyInfo.prf_frequency_hz;
			gPEClockFrequencyInfo.prf_frequency_max_hz = gPEClockFrequencyInfo.prf_frequency_hz;

			/* Find the fixed frequency next. */
			if (DTGetProperty(cpu, "fixed-frequency", (void **)&value, &size) == kSuccess) {
				if (size == 8)
					gPEClockFrequencyInfo.fix_frequency_hz = *(unsigned long long *)value;
				else
					gPEClockFrequencyInfo.fix_frequency_hz = *value;
			}
			/* Find the cpu frequency last. */
			if (DTGetProperty(cpu, "clock-frequency", (void **)&value, &size) == kSuccess) {
				if (size == 8)
					gPEClockFrequencyInfo.cpu_frequency_hz = *(unsigned long long *)value;
				else
					gPEClockFrequencyInfo.cpu_frequency_hz = *value;
			}
			gPEClockFrequencyInfo.cpu_frequency_min_hz = gPEClockFrequencyInfo.cpu_frequency_hz;
			gPEClockFrequencyInfo.cpu_frequency_max_hz = gPEClockFrequencyInfo.cpu_frequency_hz;

			if (gPEClockFrequencyInfo.cpu_frequency_hz < 0x100000000ULL)
				gPEClockFrequencyInfo.cpu_clock_rate_hz = gPEClockFrequencyInfo.cpu_frequency_hz;
			else
				gPEClockFrequencyInfo.cpu_clock_rate_hz = 0xFFFFFFFF;
		}
	} else {
		/* Use the canned values. */
		gPEClockFrequencyInfo.timebase_frequency_hz = tclk;
		gPEClockFrequencyInfo.fix_frequency_hz = tclk;
		gPEClockFrequencyInfo.bus_frequency_hz = hclk;
		gPEClockFrequencyInfo.cpu_frequency_hz = mclk;
		gPEClockFrequencyInfo.prf_frequency_hz = pclk;

		gPEClockFrequencyInfo.bus_frequency_min_hz = gPEClockFrequencyInfo.bus_frequency_hz;
		gPEClockFrequencyInfo.bus_frequency_max_hz = gPEClockFrequencyInfo.bus_frequency_hz;
		gPEClockFrequencyInfo.cpu_frequency_min_hz = gPEClockFrequencyInfo.cpu_frequency_hz;
		gPEClockFrequencyInfo.cpu_frequency_max_hz = gPEClockFrequencyInfo.cpu_frequency_hz;
		gPEClockFrequencyInfo.prf_frequency_min_hz = gPEClockFrequencyInfo.prf_frequency_hz;
		gPEClockFrequencyInfo.prf_frequency_max_hz = gPEClockFrequencyInfo.prf_frequency_hz;

		gPEClockFrequencyInfo.dec_clock_rate_hz = gPEClockFrequencyInfo.timebase_frequency_hz;
		gPEClockFrequencyInfo.bus_clock_rate_hz = gPEClockFrequencyInfo.bus_frequency_hz;
		gPEClockFrequencyInfo.cpu_clock_rate_hz = gPEClockFrequencyInfo.cpu_frequency_hz;
	}

	/* Set the num / den pairs form the hz values. */
	gPEClockFrequencyInfo.bus_clock_rate_num = gPEClockFrequencyInfo.bus_clock_rate_hz;
	gPEClockFrequencyInfo.bus_clock_rate_den = 1;

	gPEClockFrequencyInfo.bus_to_cpu_rate_num =
		(2 * gPEClockFrequencyInfo.cpu_clock_rate_hz) / gPEClockFrequencyInfo.bus_clock_rate_hz;
	gPEClockFrequencyInfo.bus_to_cpu_rate_den = 2;

	gPEClockFrequencyInfo.bus_to_dec_rate_num = 1;
	gPEClockFrequencyInfo.bus_to_dec_rate_den =
		gPEClockFrequencyInfo.bus_clock_rate_hz / gPEClockFrequencyInfo.dec_clock_rate_hz;
}

vm_offset_t
pe_arm_get_soc_base_phys(void)
{
	DTEntry		entryP;
	uintptr_t 	*ranges_prop;
	uint32_t	prop_size;
	char           *tmpStr;

	if (DTFindEntry("name", "arm-io", &entryP) == kSuccess) {
		if (gPESoCDeviceType == 0) {
			DTGetProperty(entryP, "device_type", (void **)&tmpStr, &prop_size);
			strlcpy(gPESoCDeviceTypeBuffer, tmpStr, SOC_DEVICE_TYPE_BUFFER_SIZE);
			gPESoCDeviceType = gPESoCDeviceTypeBuffer;

			DTGetProperty(entryP, "ranges", (void **)&ranges_prop, &prop_size);
			gPESoCBasePhys = *(ranges_prop + 1);
		}
		return gPESoCBasePhys;
	}
	return 0;
}

uint32_t
pe_arm_get_soc_revision(void)
{
	DTEntry		entryP;
	uint32_t	*value;
	uint32_t	size;

	if ((DTFindEntry("name", "arm-io", &entryP) == kSuccess) 
	    && (DTGetProperty(entryP, "chip-revision", (void **)&value, &size) == kSuccess)) {
		if (size == 8)
			return((uint32_t)*(unsigned long long *)value);
		else
			return(*value);
	}
	return 0;
}

void
pe_arm_init_debug(void *args)
{
	DTEntry 	entryP;
	uintptr_t	*reg_prop;
	uint32_t	prop_size;

	if (gSocPhys == 0 ) {
		kprintf("pe_arm_init_debug: failed to initialize gSocPhys == 0\n");
	    return;
	}
	
	if ( DTFindEntry("device_type", "cpu-debug-interface", &entryP) == kSuccess ) {
		if (args != NULL) {
			if (DTGetProperty(entryP, "reg", (void **)&reg_prop, &prop_size) == kSuccess) {
				ml_init_arm_debug_interface(args, ml_io_map(gSocPhys + *reg_prop, *(reg_prop + 1)));
			}
#if DEVELOPMENT || DEBUG
			// When args != NULL, this means we're being called from arm_init on the boot CPU.
			// This controls one-time initialization of the Panic Trace infrastructure

			simple_lock_init(&panic_trace_lock, 0); //assuming single threaded mode
		
			// Panic_halt is deprecated. Please use panic_trace istead.
			unsigned int temp_bootarg_panic_trace;
			if (PE_parse_boot_argn("panic_trace", &temp_bootarg_panic_trace, sizeof(temp_bootarg_panic_trace)) ||
			    PE_parse_boot_argn("panic_halt", &temp_bootarg_panic_trace, sizeof(temp_bootarg_panic_trace))) {
		
				kprintf("pe_arm_init_debug: panic_trace=%d\n", temp_bootarg_panic_trace);

                // Prepare debug command buffers.
				pe_init_debug_command(entryP, &cpu_halt, "cpu_halt");
				pe_init_debug_command(entryP, &enable_trace, "enable_trace");
				pe_init_debug_command(entryP, &enable_alt_trace, "enable_alt_trace");
				pe_init_debug_command(entryP, &trace_halt, "trace_halt");
				
				// now that init's are done, enable the panic halt capture (allows pe_init_debug_command to panic normally if necessary)
				bootarg_panic_trace = temp_bootarg_panic_trace;

				// start tracing now if enabled
				PE_arm_debug_enable_trace();
			}
#endif
		}
	} else {
		kprintf("pe_arm_init_debug: failed to find cpu-debug-interface\n");
	}
}

__attribute__((used)) static uint32_t
pe_arm_map_interrupt_controller(void)
{
	DTEntry		entryP;
	uintptr_t	*reg_prop;
	uint32_t	prop_size;
	vm_offset_t	soc_phys = 0;

	gSocPhys = pe_arm_get_soc_base_phys();

	soc_phys = gSocPhys;
	kprintf("pe_arm_map_interrupt_controller: soc_phys:  0x%lx\n", (unsigned long)soc_phys);
	if (soc_phys == 0)
		return 0;

	if (DTFindEntry("interrupt-controller", "master", &entryP) == kSuccess) {
		kprintf("pe_arm_map_interrupt_controller: found interrupt-controller\n");
		DTGetProperty(entryP, "reg", (void **)&reg_prop, &prop_size);
		gPicBase = ml_io_map(soc_phys + *reg_prop, *(reg_prop + 1));
		kprintf("pe_arm_map_interrupt_controller: gPicBase: 0x%lx\n", (unsigned long)gPicBase);
	}
	if (gPicBase == 0) {
		kprintf("pe_arm_map_interrupt_controller: failed to find the interrupt-controller.\n");
		return 0;
	}

	if (DTFindEntry("device_type", "timer", &entryP) == kSuccess) {
		kprintf("pe_arm_map_interrupt_controller: found timer\n");
		DTGetProperty(entryP, "reg", (void **)&reg_prop, &prop_size);
		gTimerBase = ml_io_map(soc_phys + *reg_prop, *(reg_prop + 1));
		kprintf("pe_arm_map_interrupt_controller: gTimerBase: 0x%lx\n", (unsigned long)gTimerBase);
	}
	if (gTimerBase == 0) {
		kprintf("pe_arm_map_interrupt_controller: failed to find the timer.\n");
		return 0;
	}

	return 1;
}

uint32_t
pe_arm_init_interrupts(void *args)
{
	kprintf("pe_arm_init_interrupts: args: %p\n", args);

	/* Set up mappings for interrupt controller and possibly timers (if they haven't been set up already) */
	if (args != NULL) {
		if (!pe_arm_map_interrupt_controller()) {
			return 0;
		}
	}

	return pe_arm_init_timer(args);
}

__attribute__((used)) static uint32_t 
pe_arm_init_timer(void *args)
{
	vm_offset_t	pic_base = 0;
	vm_offset_t	timer_base = 0;
	vm_offset_t	soc_phys;
	vm_offset_t 	eoi_addr = 0;
	uint32_t 	eoi_value = 0;
	struct tbd_ops  generic_funcs = {&fleh_fiq_generic, NULL, NULL};
	tbd_ops_t	tbd_funcs = &generic_funcs;

	/* The SoC headers expect to use pic_base, timer_base, etc... */
	pic_base = gPicBase;
	timer_base = gTimerBase;
	soc_phys = gSocPhys;

#if defined(ARM_BOARD_CLASS_S5L8960X)
	if (!strcmp(gPESoCDeviceType, "s5l8960x-io")) {

		tbd_funcs = &s5l8960x_funcs;
	} else
#endif 
#if defined(ARM_BOARD_CLASS_T7000)
	if (!strcmp(gPESoCDeviceType, "t7000-io") ||
            !strcmp(gPESoCDeviceType, "t7001-io")) {
		tbd_funcs = &t7000_funcs;
	} else
#endif
#if defined(ARM_BOARD_CLASS_S7002)
	if (!strcmp(gPESoCDeviceType, "s7002-io")) {

#ifdef ARM_BOARD_WFE_TIMEOUT_NS
		// Enable the WFE Timer
		rPMGR_EVENT_TMR_PERIOD = ((uint64_t)(ARM_BOARD_WFE_TIMEOUT_NS) * gPEClockFrequencyInfo.timebase_frequency_hz) / NSEC_PER_SEC;
		rPMGR_EVENT_TMR = rPMGR_EVENT_TMR_PERIOD;
		rPMGR_EVENT_TMR_CTL = PMGR_EVENT_TMR_CTL_EN;
#endif /* ARM_BOARD_WFE_TIMEOUT_NS */

		rPMGR_INTERVAL_TMR = 0x7FFFFFFF;
		rPMGR_INTERVAL_TMR_CTL = PMGR_INTERVAL_TMR_CTL_EN | PMGR_INTERVAL_TMR_CTL_CLR_INT;

		eoi_addr = timer_base;
		eoi_value = PMGR_INTERVAL_TMR_CTL_EN | PMGR_INTERVAL_TMR_CTL_CLR_INT;
		tbd_funcs = &s7002_funcs;
	} else
#endif
#if defined(ARM_BOARD_CLASS_S8000)
	if (!strcmp(gPESoCDeviceType, "s8000-io") ||
	    !strcmp(gPESoCDeviceType, "s8001-io")) {
		tbd_funcs = &s8000_funcs;
	} else
#endif
#if defined(ARM_BOARD_CLASS_T8002)
	if (!strcmp(gPESoCDeviceType, "t8002-io") ||
	    !strcmp(gPESoCDeviceType, "t8004-io")) {

		/* Enable the Decrementer */
		aic_write32(kAICTmrCnt, 0x7FFFFFFF);
		aic_write32(kAICTmrCfg, kAICTmrCfgEn);
		aic_write32(kAICTmrIntStat, kAICTmrIntStatPct);
#ifdef ARM_BOARD_WFE_TIMEOUT_NS
		// Enable the WFE Timer
		rPMGR_EVENT_TMR_PERIOD = ((uint64_t)(ARM_BOARD_WFE_TIMEOUT_NS) * gPEClockFrequencyInfo.timebase_frequency_hz) / NSEC_PER_SEC;
		rPMGR_EVENT_TMR = rPMGR_EVENT_TMR_PERIOD;
		rPMGR_EVENT_TMR_CTL = PMGR_EVENT_TMR_CTL_EN;
#endif /* ARM_BOARD_WFE_TIMEOUT_NS */

		eoi_addr = pic_base;
		eoi_value = kAICTmrIntStatPct;
		tbd_funcs = &t8002_funcs;
	} else
#endif
#if defined(ARM_BOARD_CLASS_T8010)
	if (!strcmp(gPESoCDeviceType, "t8010-io")) {
		tbd_funcs = &t8010_funcs;
	} else
#endif
#if defined(ARM_BOARD_CLASS_T8011)
	if (!strcmp(gPESoCDeviceType, "t8011-io")) {
		tbd_funcs = &t8011_funcs;
	} else
#endif
#if defined(ARM_BOARD_CLASS_T8015)
	if (!strcmp(gPESoCDeviceType, "t8015-io")) {
		tbd_funcs = &t8015_funcs;
	} else
#endif
#if defined(ARM_BOARD_CLASS_BCM2837)
	if (!strcmp(gPESoCDeviceType, "bcm2837-io")) {
		tbd_funcs = &bcm2837_funcs;
	} else
#endif
		return 0;

	if (args != NULL)
		ml_init_timebase(args, tbd_funcs, eoi_addr, eoi_value);

	return 1;
}

