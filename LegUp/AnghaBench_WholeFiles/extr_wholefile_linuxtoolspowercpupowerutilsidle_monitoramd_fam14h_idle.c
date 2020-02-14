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
typedef  int uint32_t ;
struct timespec {int dummy; } ;
struct cstate {int id; double name; } ;
struct cpuidle_monitor {unsigned int hw_states_num; int /*<<< orphan*/  name; int /*<<< orphan*/  name_len; } ;
typedef  struct cstate cstate_t ;
struct TYPE_2__ {scalar_t__ vendor; int family; } ;

/* Variables and functions */
 unsigned int AMD_FAM14H_STATE_NUM ; 
 int /*<<< orphan*/  CLOCK_REALTIME ; 
 scalar_t__ MONITOR_NAME_LEN ; 
#define  NBP1 131 
#define  NON_PC0 130 
 double OVERFLOW_MS ; 
#define  PC1 129 
#define  PC6 128 
 int PCI_MONITOR_ENABLE_REG ; 
 int PCI_NBP1_ACTIVE_BIT ; 
 int PCI_NBP1_CAP_OFFSET ; 
 int PCI_NBP1_ENTERED_BIT ; 
 unsigned int PCI_NBP1_STAT_OFFSET ; 
 unsigned int PCI_NON_PC0_ENABLE_BIT ; 
 unsigned int PCI_NON_PC0_OFFSET ; 
 unsigned int PCI_PC1_ENABLE_BIT ; 
 unsigned int PCI_PC1_OFFSET ; 
 unsigned int PCI_PC6_ENABLE_BIT ; 
 unsigned int PCI_PC6_OFFSET ; 
 scalar_t__ X86_VENDOR_AMD ; 
 struct cstate* amd_fam14h_cstates ; 
 struct cpuidle_monitor amd_fam14h_monitor ; 
 int /*<<< orphan*/ * amd_fam14h_pci_dev ; 
 unsigned long* calloc (int,int) ; 
 int /*<<< orphan*/  clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int cpu_count ; 
 TYPE_1__ cpupower_cpu_info ; 
 unsigned long** current_count ; 
 int /*<<< orphan*/  dprint (char*,...) ; 
 int /*<<< orphan*/  free (unsigned long*) ; 
 int nbp1_entered ; 
 int /*<<< orphan*/ * pci_acc ; 
 int /*<<< orphan*/  pci_cleanup (int /*<<< orphan*/ *) ; 
 int pci_read_long (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * pci_slot_func_init (int /*<<< orphan*/ **,int,int) ; 
 int pci_write_long (int /*<<< orphan*/ *,int,int) ; 
 unsigned long** previous_count ; 
 int /*<<< orphan*/  print_overflow_err (unsigned int,double) ; 
 struct timespec start_time ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strncpy (int /*<<< orphan*/ ,char*,scalar_t__) ; 
 double timediff ; 
 double timespec_diff_us (struct timespec,struct timespec) ; 

__attribute__((used)) static int amd_fam14h_get_pci_info(struct cstate *state,
				   unsigned int *pci_offset,
				   unsigned int *enable_bit,
				   unsigned int cpu)
{
	switch (state->id) {
	case NON_PC0:
		*enable_bit = PCI_NON_PC0_ENABLE_BIT;
		*pci_offset = PCI_NON_PC0_OFFSET;
		break;
	case PC1:
		*enable_bit = PCI_PC1_ENABLE_BIT;
		*pci_offset = PCI_PC1_OFFSET;
		break;
	case PC6:
		*enable_bit = PCI_PC6_ENABLE_BIT;
		*pci_offset = PCI_PC6_OFFSET;
		break;
	case NBP1:
		*enable_bit = PCI_NBP1_ENTERED_BIT;
		*pci_offset = PCI_NBP1_STAT_OFFSET;
		break;
	default:
		return -1;
	};
	return 0;
}

__attribute__((used)) static int amd_fam14h_init(cstate_t *state, unsigned int cpu)
{
	int enable_bit, pci_offset, ret;
	uint32_t val;

	ret = amd_fam14h_get_pci_info(state, &pci_offset, &enable_bit, cpu);
	if (ret)
		return ret;

	/* NBP1 needs extra treating -> write 1 to D18F6x98 bit 1 for init */
	if (state->id == NBP1) {
		val = pci_read_long(amd_fam14h_pci_dev, pci_offset);
		val |= 1 << enable_bit;
		val = pci_write_long(amd_fam14h_pci_dev, pci_offset, val);
		return ret;
	}

	/* Enable monitor */
	val = pci_read_long(amd_fam14h_pci_dev, PCI_MONITOR_ENABLE_REG);
	dprint("Init %s: read at offset: 0x%x val: %u\n", state->name,
	       PCI_MONITOR_ENABLE_REG, (unsigned int) val);
	val |= 1 << enable_bit;
	pci_write_long(amd_fam14h_pci_dev, PCI_MONITOR_ENABLE_REG, val);

	dprint("Init %s: offset: 0x%x enable_bit: %d - val: %u (%u)\n",
	       state->name, PCI_MONITOR_ENABLE_REG, enable_bit,
	       (unsigned int) val, cpu);

	/* Set counter to zero */
	pci_write_long(amd_fam14h_pci_dev, pci_offset, 0);
	previous_count[state->id][cpu] = 0;

	return 0;
}

__attribute__((used)) static int amd_fam14h_disable(cstate_t *state, unsigned int cpu)
{
	int enable_bit, pci_offset, ret;
	uint32_t val;

	ret = amd_fam14h_get_pci_info(state, &pci_offset, &enable_bit, cpu);
	if (ret)
		return ret;

	val = pci_read_long(amd_fam14h_pci_dev, pci_offset);
	dprint("%s: offset: 0x%x %u\n", state->name, pci_offset, val);
	if (state->id == NBP1) {
		/* was the bit whether NBP1 got entered set? */
		nbp1_entered = (val & (1 << PCI_NBP1_ACTIVE_BIT)) |
			(val & (1 << PCI_NBP1_ENTERED_BIT));

		dprint("NBP1 was %sentered - 0x%x - enable_bit: "
		       "%d - pci_offset: 0x%x\n",
		       nbp1_entered ? "" : "not ",
		       val, enable_bit, pci_offset);
		return ret;
	}
	current_count[state->id][cpu] = val;

	dprint("%s: Current -  %llu (%u)\n", state->name,
	       current_count[state->id][cpu], cpu);
	dprint("%s: Previous - %llu (%u)\n", state->name,
	       previous_count[state->id][cpu], cpu);

	val = pci_read_long(amd_fam14h_pci_dev, PCI_MONITOR_ENABLE_REG);
	val &= ~(1 << enable_bit);
	pci_write_long(amd_fam14h_pci_dev, PCI_MONITOR_ENABLE_REG, val);

	return 0;
}

__attribute__((used)) static int fam14h_nbp1_count(unsigned int id, unsigned long long *count,
			     unsigned int cpu)
{
	if (id == NBP1) {
		if (nbp1_entered)
			*count = 1;
		else
			*count = 0;
		return 0;
	}
	return -1;
}

__attribute__((used)) static int fam14h_get_count_percent(unsigned int id, double *percent,
				    unsigned int cpu)
{
	unsigned long diff;

	if (id >= AMD_FAM14H_STATE_NUM)
		return -1;
	/* residency count in 80ns -> divide through 12.5 to get us residency */
	diff = current_count[id][cpu] - previous_count[id][cpu];

	if (timediff == 0)
		*percent = 0.0;
	else
		*percent = 100.0 * diff / timediff / 12.5;

	dprint("Timediff: %llu - res~: %lu us - percent: %.2f %%\n",
	       timediff, diff * 10 / 125, *percent);

	return 0;
}

__attribute__((used)) static int amd_fam14h_start(void)
{
	int num, cpu;
	clock_gettime(CLOCK_REALTIME, &start_time);
	for (num = 0; num < AMD_FAM14H_STATE_NUM; num++) {
		for (cpu = 0; cpu < cpu_count; cpu++)
			amd_fam14h_init(&amd_fam14h_cstates[num], cpu);
	}
#ifdef DEBUG
	clock_gettime(CLOCK_REALTIME, &dbg_time);
	dbg_timediff = timespec_diff_us(start_time, dbg_time);
	dprint("Enabling counters took: %lu us\n",
	       dbg_timediff);
#endif
	return 0;
}

__attribute__((used)) static int amd_fam14h_stop(void)
{
	int num, cpu;
	struct timespec end_time;

	clock_gettime(CLOCK_REALTIME, &end_time);

	for (num = 0; num < AMD_FAM14H_STATE_NUM; num++) {
		for (cpu = 0; cpu < cpu_count; cpu++)
			amd_fam14h_disable(&amd_fam14h_cstates[num], cpu);
	}
#ifdef DEBUG
	clock_gettime(CLOCK_REALTIME, &dbg_time);
	dbg_timediff = timespec_diff_us(end_time, dbg_time);
	dprint("Disabling counters took: %lu ns\n", dbg_timediff);
#endif
	timediff = timespec_diff_us(start_time, end_time);
	if (timediff / 1000 > OVERFLOW_MS)
		print_overflow_err((unsigned int)timediff / 1000000,
				   OVERFLOW_MS / 1000);

	return 0;
}

__attribute__((used)) static int is_nbp1_capable(void)
{
	uint32_t val;
	val = pci_read_long(amd_fam14h_pci_dev, PCI_NBP1_CAP_OFFSET);
	return val & (1 << 31);
}

struct cpuidle_monitor *amd_fam14h_register(void)
{
	int num;

	if (cpupower_cpu_info.vendor != X86_VENDOR_AMD)
		return NULL;

	if (cpupower_cpu_info.family == 0x14)
		strncpy(amd_fam14h_monitor.name, "Fam_14h",
			MONITOR_NAME_LEN - 1);
	else if (cpupower_cpu_info.family == 0x12)
		strncpy(amd_fam14h_monitor.name, "Fam_12h",
			MONITOR_NAME_LEN - 1);
	else
		return NULL;

	/* We do not alloc for nbp1 machine wide counter */
	for (num = 0; num < AMD_FAM14H_STATE_NUM - 1; num++) {
		previous_count[num] = calloc(cpu_count,
					      sizeof(unsigned long long));
		current_count[num]  = calloc(cpu_count,
					      sizeof(unsigned long long));
	}

	/* We need PCI device: Slot 18, Func 6, compare with BKDG
	   for fam 12h/14h */
	amd_fam14h_pci_dev = pci_slot_func_init(&pci_acc, 0x18, 6);
	if (amd_fam14h_pci_dev == NULL || pci_acc == NULL)
		return NULL;

	if (!is_nbp1_capable())
		amd_fam14h_monitor.hw_states_num = AMD_FAM14H_STATE_NUM - 1;

	amd_fam14h_monitor.name_len = strlen(amd_fam14h_monitor.name);
	return &amd_fam14h_monitor;
}

__attribute__((used)) static void amd_fam14h_unregister(void)
{
	int num;
	for (num = 0; num < AMD_FAM14H_STATE_NUM - 1; num++) {
		free(previous_count[num]);
		free(current_count[num]);
	}
	pci_cleanup(pci_acc);
}

