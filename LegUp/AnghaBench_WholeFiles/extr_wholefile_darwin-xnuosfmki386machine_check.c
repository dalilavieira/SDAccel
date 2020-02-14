#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_9__ ;
typedef  struct TYPE_28__   TYPE_8__ ;
typedef  struct TYPE_27__   TYPE_7__ ;
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;
typedef  struct TYPE_20__   TYPE_16__ ;
typedef  struct TYPE_19__   TYPE_15__ ;

/* Type definitions */
typedef  int vm_size_t ;
typedef  scalar_t__ uint64_t ;
typedef  scalar_t__ uint32_t ;
struct TYPE_26__ {unsigned long long u64; } ;
struct TYPE_23__ {unsigned long long mca_mcg_ctl; scalar_t__ mca_is_saved; TYPE_6__ mca_mcg_status; void* mca_is_valid; TYPE_4__* mca_error_bank; } ;
typedef  TYPE_3__ mca_state_t ;
struct TYPE_22__ {scalar_t__ miscv; scalar_t__ addrv; int /*<<< orphan*/  val; } ;
struct TYPE_25__ {unsigned long long u64; TYPE_2__ bits; } ;
struct TYPE_24__ {unsigned long long mca_mci_ctl; unsigned long long mca_mci_misc; unsigned long long mca_mci_addr; TYPE_5__ mca_mci_status; } ;
typedef  TYPE_4__ mca_mci_bank_t ;
typedef  TYPE_5__ ia32_mci_status_t ;
typedef  TYPE_6__ ia32_mcg_status_t ;
struct TYPE_27__ {scalar_t__ cpuid_features; scalar_t__ cpuid_family; scalar_t__ cpuid_model; scalar_t__ cpuid_stepping; int /*<<< orphan*/  cpuid_brand_string; int /*<<< orphan*/  cpuid_signature; int /*<<< orphan*/  cpuid_microcode_version; } ;
typedef  TYPE_7__ i386_cpu_info_t ;
struct TYPE_28__ {int cpu_number; TYPE_3__* cpu_mca_state; } ;
typedef  TYPE_8__ cpu_data_t ;
typedef  int /*<<< orphan*/  boolean_t ;
struct TYPE_29__ {TYPE_3__* mca_state; } ;
struct TYPE_21__ {unsigned int count; int /*<<< orphan*/  mcg_ext_corr_err_p; scalar_t__ mcg_ctl_p; } ;
struct TYPE_20__ {TYPE_3__* cpu_mca_state; } ;
struct TYPE_19__ {unsigned long long u64; TYPE_1__ bits; } ;

/* Variables and functions */
 scalar_t__ CLEAR ; 
 scalar_t__ CPUID_FEATURE_MCA ; 
 scalar_t__ CPUID_FEATURE_MCE ; 
 scalar_t__ CPUID_MODEL_CRYSTALWELL ; 
 scalar_t__ CPUID_MODEL_HASWELL ; 
 scalar_t__ CPUID_MODEL_HASWELL_ULT ; 
 int CR4_MCE ; 
 scalar_t__ DUMPED ; 
 scalar_t__ DUMPING ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  IA32_MCG_CAP ; 
 int /*<<< orphan*/  IA32_MCG_CTL ; 
 unsigned long long IA32_MCG_CTL_ENABLE ; 
 int /*<<< orphan*/  IA32_MCG_STATUS ; 
 int /*<<< orphan*/  IA32_MCi_ADDR (int) ; 
 int /*<<< orphan*/  IA32_MCi_CTL (unsigned int) ; 
 int /*<<< orphan*/  IA32_MCi_MISC (int) ; 
 int /*<<< orphan*/  IA32_MCi_STATUS (int) ; 
 scalar_t__ LockTimeOut ; 
 void* TRUE ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  bzero (void*,int) ; 
 TYPE_8__* cpu_datap (unsigned int) ; 
 int /*<<< orphan*/  cpu_pause () ; 
 TYPE_7__* cpuid_info () ; 
 TYPE_16__* current_cpu_datap () ; 
 int get_cr4 () ; 
 scalar_t__ get_preemption_level () ; 
 TYPE_15__ ia32_mcg_cap ; 
 TYPE_3__* kalloc (int) ; 
 scalar_t__ mach_absolute_time () ; 
 unsigned int master_cpu ; 
 int mca_MCA_present ; 
 int mca_MCE_present ; 
 int /*<<< orphan*/  mca_cmci_present ; 
 scalar_t__ mca_control_MSR_present ; 
 scalar_t__ mca_dump_state ; 
 unsigned int mca_error_bank_count ; 
 int mca_family ; 
 void* mca_initialized ; 
 int /*<<< orphan*/  mca_lock ; 
 int /*<<< orphan*/  ml_get_interrupts_enabled () ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  paniclog_append_noflush (char*,unsigned int,...) ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 unsigned long long rdmsr64 (int /*<<< orphan*/ ) ; 
 unsigned int real_ncpus ; 
 int /*<<< orphan*/  set_cr4 (int) ; 
 int /*<<< orphan*/  simple_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  simple_lock_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  simple_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wrmsr64 (int /*<<< orphan*/ ,unsigned long long) ; 
 TYPE_9__* x86_package () ; 

__attribute__((used)) static void
mca_get_availability(void)
{
	uint64_t	features = cpuid_info()->cpuid_features;
	uint32_t	family =   cpuid_info()->cpuid_family;
	uint32_t	model =    cpuid_info()->cpuid_model;
	uint32_t	stepping = cpuid_info()->cpuid_stepping;

	if ((model == CPUID_MODEL_HASWELL     && stepping < 3) ||
	    (model == CPUID_MODEL_HASWELL_ULT && stepping < 1) ||
	    (model == CPUID_MODEL_CRYSTALWELL && stepping < 1))
		panic("Haswell pre-C0 steppings are not supported");

	mca_MCE_present = (features & CPUID_FEATURE_MCE) != 0;
	mca_MCA_present = (features & CPUID_FEATURE_MCA) != 0;
	mca_family = family;

	/*
	 * If MCA, the number of banks etc is reported by the IA32_MCG_CAP MSR.
	 */
	if (mca_MCA_present) {
		ia32_mcg_cap.u64 = rdmsr64(IA32_MCG_CAP);
		mca_error_bank_count = ia32_mcg_cap.bits.count;
		mca_control_MSR_present = ia32_mcg_cap.bits.mcg_ctl_p;
		mca_cmci_present = ia32_mcg_cap.bits.mcg_ext_corr_err_p;
	}
}

void
mca_cpu_init(void)
{
	unsigned int	i;

	/*
	 * The first (boot) processor is responsible for discovering the
	 * machine check architecture present on this machine.
	 */
	if (!mca_initialized) {
		mca_get_availability();
		mca_initialized = TRUE;
		simple_lock_init(&mca_lock, 0);
	}

	if (mca_MCA_present) {

		/* Enable all MCA features */
		if (mca_control_MSR_present)
			wrmsr64(IA32_MCG_CTL, IA32_MCG_CTL_ENABLE);
	
		switch (mca_family) {
		case 0x06:
			/* Enable all but mc0 */
			for (i = 1; i < mca_error_bank_count; i++)
				wrmsr64(IA32_MCi_CTL(i),0xFFFFFFFFFFFFFFFFULL); 
			
			/* Clear all errors */
			for (i = 0; i < mca_error_bank_count; i++)
				wrmsr64(IA32_MCi_STATUS(i), 0ULL);
			break;
		case 0x0F:
			/* Enable all banks */
			for (i = 0; i < mca_error_bank_count; i++)
				wrmsr64(IA32_MCi_CTL(i),0xFFFFFFFFFFFFFFFFULL); 
			
			/* Clear all errors */
			for (i = 0; i < mca_error_bank_count; i++)
				wrmsr64(IA32_MCi_STATUS(i), 0ULL);
			break;
		}
	}

	/* Enable machine check exception handling if available */
	if (mca_MCE_present) {
		set_cr4(get_cr4()|CR4_MCE);
	}
}

boolean_t
mca_is_cmci_present(void)
{
	if (!mca_initialized)
		mca_cpu_init();
	return mca_cmci_present;
}

void
mca_cpu_alloc(cpu_data_t	*cdp)
{
	vm_size_t	mca_state_size;

	/*
	 * Allocate space for an array of error banks.
	 */
	mca_state_size = sizeof(mca_state_t) +
				sizeof(mca_mci_bank_t) * mca_error_bank_count;
	cdp->cpu_mca_state = kalloc(mca_state_size);
	if (cdp->cpu_mca_state == NULL) {
		printf("mca_cpu_alloc() failed for cpu %d\n", cdp->cpu_number);
		return;
	}
	bzero((void *) cdp->cpu_mca_state, mca_state_size);

	/*
	 * If the boot processor is yet have its allocation made,
	 * do this now.
	 */
	if (cpu_datap(master_cpu)->cpu_mca_state == NULL)
		mca_cpu_alloc(cpu_datap(master_cpu));
}

__attribute__((used)) static void
mca_save_state(mca_state_t *mca_state)
{
	mca_mci_bank_t  *bank;
	unsigned int	i;

	assert(!ml_get_interrupts_enabled() || get_preemption_level() > 0);

	if  (mca_state == NULL)
		return;

	mca_state->mca_mcg_ctl = mca_control_MSR_present ?
					rdmsr64(IA32_MCG_CTL) : 0ULL;	
	mca_state->mca_mcg_status.u64 = rdmsr64(IA32_MCG_STATUS);

 	bank = (mca_mci_bank_t *) &mca_state->mca_error_bank[0];
	for (i = 0; i < mca_error_bank_count; i++, bank++) {
		bank->mca_mci_ctl        = rdmsr64(IA32_MCi_CTL(i));	
		bank->mca_mci_status.u64 = rdmsr64(IA32_MCi_STATUS(i));	
		if (!bank->mca_mci_status.bits.val)
			continue;
		bank->mca_mci_misc = (bank->mca_mci_status.bits.miscv)?
					rdmsr64(IA32_MCi_MISC(i)) : 0ULL;	
		bank->mca_mci_addr = (bank->mca_mci_status.bits.addrv)?
					rdmsr64(IA32_MCi_ADDR(i)) : 0ULL;	
		mca_state->mca_is_valid = TRUE;
	} 

	/*
	 * If we're the first thread with MCA state, point our package to it
	 * and don't care about races
	 */
	if (x86_package()->mca_state == NULL)
		x86_package()->mca_state = mca_state;

	mca_state->mca_is_saved = TRUE;
}

void
mca_check_save(void)
{
	if (mca_dump_state > CLEAR)
		mca_save_state(current_cpu_datap()->cpu_mca_state);
}

__attribute__((used)) static void
mca_report_cpu_info(void)
{
	i386_cpu_info_t *infop = cpuid_info();

	paniclog_append_noflush(" family: %d model: %d stepping: %d microcode: %d\n",
		infop->cpuid_family,
		infop->cpuid_model,
		infop->cpuid_stepping,
		infop->cpuid_microcode_version);
	paniclog_append_noflush(" signature: 0x%x\n",
		infop->cpuid_signature);
	paniclog_append_noflush(" %s\n",
		infop->cpuid_brand_string);

}

__attribute__((used)) static void
mca_dump_bank(mca_state_t *state, int i)
{
	mca_mci_bank_t		*bank;
	ia32_mci_status_t	status;

	bank = &state->mca_error_bank[i];
	status = bank->mca_mci_status;
	if (!status.bits.val)
		return;

	paniclog_append_noflush(" IA32_MC%d_STATUS(0x%x): 0x%016qx\n",
		i, IA32_MCi_STATUS(i), status.u64);

	if (status.bits.addrv)
		paniclog_append_noflush(" IA32_MC%d_ADDR(0x%x):   0x%016qx\n",
			i, IA32_MCi_ADDR(i), bank->mca_mci_addr);

	if (status.bits.miscv)
		paniclog_append_noflush(" IA32_MC%d_MISC(0x%x):   0x%016qx\n",
			i, IA32_MCi_MISC(i), bank->mca_mci_misc);
}

__attribute__((used)) static void
mca_cpu_dump_error_banks(mca_state_t *state)
{
	unsigned int 		i;

	if (!state->mca_is_valid)
		return;

	for (i = 0; i < mca_error_bank_count; i++ ) {
		mca_dump_bank(state, i);
	}
}

void
mca_dump(void)
{
	mca_state_t	*mca_state = current_cpu_datap()->cpu_mca_state;
	uint64_t	deadline;
	unsigned int	i = 0;

	/*
	 * Capture local MCA registers to per-cpu data.
	 */
	mca_save_state(mca_state);

	/*
	 * Serialize: the first caller controls dumping MCA registers,
	 * other threads spin meantime.
	 */
	simple_lock(&mca_lock);
	if (mca_dump_state > CLEAR) {
		simple_unlock(&mca_lock);
		while (mca_dump_state == DUMPING)
			cpu_pause();
		return;
	}
	mca_dump_state = DUMPING;
	simple_unlock(&mca_lock);

	/*
	 * Wait for all other hardware threads to save their state.
	 * Or timeout.
	 */
	deadline = mach_absolute_time() + LockTimeOut;
	while (mach_absolute_time() < deadline && i < real_ncpus) {
		if (!cpu_datap(i)->cpu_mca_state->mca_is_saved) {
			cpu_pause();
			continue;
		}
		i += 1;
	}

	/*
	 * Report machine-check capabilities:
	 */
	paniclog_append_noflush("Machine-check capabilities: 0x%016qx\n", ia32_mcg_cap.u64);

	mca_report_cpu_info();

	paniclog_append_noflush(" %d error-reporting banks\n", mca_error_bank_count);
 
	/*
	 * Dump all processor state:
	 */
	for (i = 0; i < real_ncpus; i++) {
		mca_state_t		*mcsp = cpu_datap(i)->cpu_mca_state;
		ia32_mcg_status_t	status;

		if (mcsp == NULL ||
		    mcsp->mca_is_saved == FALSE ||
		    mcsp->mca_mcg_status.u64 == 0 ||
		    !mcsp->mca_is_valid) {
			continue;
		}
		status = mcsp->mca_mcg_status;
		paniclog_append_noflush("Processor %d: IA32_MCG_STATUS: 0x%016qx\n",
			i, status.u64);
		mca_cpu_dump_error_banks(mcsp);
	}

	/* Update state to release any other threads. */
	mca_dump_state = DUMPED;
}

