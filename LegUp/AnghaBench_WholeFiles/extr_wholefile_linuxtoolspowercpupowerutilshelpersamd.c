#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int did; int fid; int /*<<< orphan*/  en; } ;
struct TYPE_3__ {int did; int fid; int /*<<< orphan*/  en; } ;
union msr_pstate {int val; TYPE_2__ bits; TYPE_1__ fam17h_bits; } ;
typedef  int uint8_t ;
struct pci_dev {int dummy; } ;
struct pci_access {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int MAX_HW_PSTATES ; 
 scalar_t__ MSR_AMD_PSTATE ; 
 scalar_t__ MSR_AMD_PSTATE_LIMIT ; 
 scalar_t__ MSR_AMD_PSTATE_STATUS ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  pci_cleanup (struct pci_access*) ; 
 int pci_read_byte (struct pci_dev*,int) ; 
 struct pci_dev* pci_slot_func_init (struct pci_access**,int,int) ; 
 scalar_t__ read_msr (unsigned int,scalar_t__,unsigned long long*) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static int get_did(int family, union msr_pstate pstate)
{
	int t;

	if (family == 0x12)
		t = pstate.val & 0xf;
	else if (family == 0x17)
		t = pstate.fam17h_bits.did;
	else
		t = pstate.bits.did;

	return t;
}

__attribute__((used)) static int get_cof(int family, union msr_pstate pstate)
{
	int t;
	int fid, did, cof;

	did = get_did(family, pstate);
	if (family == 0x17) {
		fid = pstate.fam17h_bits.fid;
		cof = 200 * fid / did;
	} else {
		t = 0x10;
		fid = pstate.bits.fid;
		if (family == 0x11)
			t = 0x8;
		cof = (100 * (fid + t)) >> did;
	}
	return cof;
}

int decode_pstates(unsigned int cpu, unsigned int cpu_family,
		   int boost_states, unsigned long *pstates, int *no)
{
	int i, psmax, pscur;
	union msr_pstate pstate;
	unsigned long long val;

	/* Only read out frequencies from HW when CPU might be boostable
	   to keep the code as short and clean as possible.
	   Otherwise frequencies are exported via ACPI tables.
	*/
	if (cpu_family < 0x10 || cpu_family == 0x14)
		return -1;

	if (read_msr(cpu, MSR_AMD_PSTATE_LIMIT, &val))
		return -1;

	psmax = (val >> 4) & 0x7;

	if (read_msr(cpu, MSR_AMD_PSTATE_STATUS, &val))
		return -1;

	pscur = val & 0x7;

	pscur += boost_states;
	psmax += boost_states;
	for (i = 0; i <= psmax; i++) {
		if (i >= MAX_HW_PSTATES) {
			fprintf(stderr, "HW pstates [%d] exceeding max [%d]\n",
				psmax, MAX_HW_PSTATES);
			return -1;
		}
		if (read_msr(cpu, MSR_AMD_PSTATE + i, &pstate.val))
			return -1;
		if ((cpu_family == 0x17) && (!pstate.fam17h_bits.en))
			continue;
		else if (!pstate.bits.en)
			continue;

		pstates[i] = get_cof(cpu_family, pstate);
	}
	*no = i;
	return 0;
}

int amd_pci_get_num_boost_states(int *active, int *states)
{
	struct pci_access *pci_acc;
	struct pci_dev *device;
	uint8_t val = 0;

	*active = *states = 0;

	device = pci_slot_func_init(&pci_acc, 0x18, 4);

	if (device == NULL)
		return -ENODEV;

	val = pci_read_byte(device, 0x15c);
	if (val & 3)
		*active = 1;
	else
		*active = 0;
	*states = (val >> 2) & 7;

	pci_cleanup(pci_acc);
	return 0;
}

