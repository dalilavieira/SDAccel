#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  scalar_t__ uint32_t ;
struct TYPE_8__ {scalar_t__ cpsr; scalar_t__ pc; scalar_t__ sp; scalar_t__ lr; scalar_t__ fp; scalar_t__* x; } ;
typedef  TYPE_1__ dbgwrap_thread_state_t ;
typedef  scalar_t__ dbgwrap_status_t ;
typedef  int dbgwrap_reg_t ;
struct TYPE_9__ {scalar_t__* coresight_base; } ;
typedef  TYPE_2__ cpu_data_t ;
typedef  int boolean_t ;

/* Variables and functions */
 scalar_t__ ARM_DBG_LOCK_ACCESS_KEY ; 
 scalar_t__ ARM_DEBUG_OFFSET_DBGLAR ; 
 size_t CORESIGHT_ED ; 
 size_t CORESIGHT_UTT ; 
 int volatile DBGWRAP_DBGACK ; 
 int DBGWRAP_DBGHALT ; 
 scalar_t__ DBGWRAP_ERR_HALT_TIMEOUT ; 
 scalar_t__ DBGWRAP_ERR_INPROGRESS ; 
 scalar_t__ DBGWRAP_ERR_INSTR_ERROR ; 
 scalar_t__ DBGWRAP_ERR_INSTR_TIMEOUT ; 
 scalar_t__ DBGWRAP_ERR_SELF_HALT ; 
 scalar_t__ DBGWRAP_ERR_UNSUPPORTED ; 
 scalar_t__ DBGWRAP_REG_OFFSET ; 
 scalar_t__ DBGWRAP_SUCCESS ; 
 scalar_t__ DBGWRAP_WARN_ALREADY_HALTED ; 
 scalar_t__ DBGWRAP_WARN_CPU_OFFLINE ; 
 scalar_t__ EDDTRRX_REG_OFFSET ; 
 scalar_t__ EDDTRTX_REG_OFFSET ; 
 scalar_t__ EDITR_REG_OFFSET ; 
 scalar_t__ volatile EDPRSR_OSLK ; 
 scalar_t__ EDPRSR_REG_OFFSET ; 
 scalar_t__ EDRCR_CSE ; 
 scalar_t__ EDRCR_REG_OFFSET ; 
 scalar_t__ volatile EDSCR_ERR ; 
 scalar_t__ volatile EDSCR_ITE ; 
 scalar_t__ volatile EDSCR_MA ; 
 scalar_t__ EDSCR_REG_OFFSET ; 
 scalar_t__ volatile EDSCR_TXFULL ; 
 int FALSE ; 
 int MAX_EDITR_RETRIES ; 
 int /*<<< orphan*/  bzero (TYPE_1__*,int) ; 
 TYPE_2__* cpu_datap (int) ; 
 int cpu_number () ; 
 scalar_t__ halt_from_cpu ; 
 int /*<<< orphan*/  hw_compare_and_store (scalar_t__,unsigned int,scalar_t__*) ; 
 scalar_t__ mach_absolute_time () ; 
 int /*<<< orphan*/  nanoseconds_to_absolutetime (scalar_t__,scalar_t__*) ; 

boolean_t
ml_dbgwrap_cpu_is_halted(int cpu_index)
{
	cpu_data_t *cdp = cpu_datap(cpu_index);
	if ((cdp == NULL) || (cdp->coresight_base[CORESIGHT_UTT] == 0))
		return FALSE;

	return ((*(volatile dbgwrap_reg_t *)(cdp->coresight_base[CORESIGHT_UTT] + DBGWRAP_REG_OFFSET) & DBGWRAP_DBGACK) != 0);
}

dbgwrap_status_t
ml_dbgwrap_wait_cpu_halted(int cpu_index, uint64_t timeout_ns)
{
	cpu_data_t *cdp = cpu_datap(cpu_index);
	if ((cdp == NULL) || (cdp->coresight_base[CORESIGHT_UTT] == 0))
		return DBGWRAP_ERR_UNSUPPORTED;

	volatile dbgwrap_reg_t *dbgWrapReg = (volatile dbgwrap_reg_t *)(cdp->coresight_base[CORESIGHT_UTT] + DBGWRAP_REG_OFFSET);

	uint64_t interval;
	nanoseconds_to_absolutetime(timeout_ns, &interval);
	uint64_t deadline = mach_absolute_time() + interval;
	while (!(*dbgWrapReg & DBGWRAP_DBGACK)) {
		if (mach_absolute_time() > deadline)
			return DBGWRAP_ERR_HALT_TIMEOUT; 
	}

	return DBGWRAP_SUCCESS;
}

dbgwrap_status_t
ml_dbgwrap_halt_cpu(int cpu_index, uint64_t timeout_ns)
{
	cpu_data_t *cdp = cpu_datap(cpu_index);
	if ((cdp == NULL) || (cdp->coresight_base[CORESIGHT_UTT] == 0))
		return DBGWRAP_ERR_UNSUPPORTED;

	/* Only one cpu is allowed to initiate the halt sequence, to prevent cpus from cross-halting
	 * each other.  The first cpu to request a halt may then halt any and all other cpus besides itself. */
	int curcpu = cpu_number();
	if (cpu_index == curcpu)
		return DBGWRAP_ERR_SELF_HALT;

	if (!hw_compare_and_store((uint32_t)-1, (unsigned int)curcpu, &halt_from_cpu) &&
	    (halt_from_cpu != (uint32_t)curcpu))
		return DBGWRAP_ERR_INPROGRESS;

	volatile dbgwrap_reg_t *dbgWrapReg = (volatile dbgwrap_reg_t *)(cdp->coresight_base[CORESIGHT_UTT] + DBGWRAP_REG_OFFSET);

	if (ml_dbgwrap_cpu_is_halted(cpu_index))
		return DBGWRAP_WARN_ALREADY_HALTED;

	/* Clear all other writable bits besides dbgHalt; none of the power-down or reset bits must be set. */
	*dbgWrapReg = DBGWRAP_DBGHALT;

	if (timeout_ns != 0) {
		dbgwrap_status_t stat = ml_dbgwrap_wait_cpu_halted(cpu_index, timeout_ns);
		return stat;
	}
	else
		return DBGWRAP_SUCCESS;
}

__attribute__((used)) static void
ml_dbgwrap_stuff_instr(cpu_data_t *cdp, uint32_t instr, uint64_t timeout_ns, dbgwrap_status_t *status)
{
	if (*status < 0)
		return;

	volatile uint32_t *editr = (volatile uint32_t *)(cdp->coresight_base[CORESIGHT_ED] + EDITR_REG_OFFSET);
	volatile uint32_t *edscr = (volatile uint32_t *)(cdp->coresight_base[CORESIGHT_ED] + EDSCR_REG_OFFSET);
	volatile uint32_t *edrcr = (volatile uint32_t *)(cdp->coresight_base[CORESIGHT_ED] + EDRCR_REG_OFFSET);

	int retries = 0;

	uint64_t interval;
	nanoseconds_to_absolutetime(timeout_ns, &interval);
	uint64_t deadline = mach_absolute_time() + interval;

#if DEVELOPMENT || DEBUG
	uint32_t stuffed_instr_index = hw_atomic_add(&stuffed_instr_count, 1);
	stuffed_instrs[(stuffed_instr_index - 1) % MAX_STUFFED_INSTRS] = instr;
#endif

	do {
		*editr = instr;
		volatile uint32_t edscr_val;
		while (!((edscr_val = *edscr) & EDSCR_ITE)) {
			if (mach_absolute_time() > deadline) {
				*status = DBGWRAP_ERR_INSTR_TIMEOUT;
				return;
			}
			if (edscr_val & EDSCR_ERR)
				break;
		}
		if (edscr_val & EDSCR_ERR) {
			/* If memory access mode was enable by a debugger, clear it.
			 * This will cause ERR to be set on any attempt to use EDITR. */	
			if (edscr_val & EDSCR_MA)
				*edscr = edscr_val & ~EDSCR_MA;
			*edrcr = EDRCR_CSE;
			++retries;
		} else
			break;
	} while (retries < MAX_EDITR_RETRIES);

	if (retries >= MAX_EDITR_RETRIES) {
		*status = DBGWRAP_ERR_INSTR_ERROR;
		return;
	}
}

__attribute__((used)) static uint64_t
ml_dbgwrap_read_dtr(cpu_data_t *cdp, uint64_t timeout_ns, dbgwrap_status_t *status)
{
	if (*status < 0)
		return 0;

	uint64_t interval;
	nanoseconds_to_absolutetime(timeout_ns, &interval);
	uint64_t deadline = mach_absolute_time() + interval;

	/* Per armv8 debug spec, writes to DBGDTR_EL0 on target cpu will set EDSCR.TXFull, 
	 * with bits 63:32 available in EDDTRRX and bits 31:0 availabe in EDDTRTX. */
	volatile uint32_t *edscr = (volatile uint32_t *)(cdp->coresight_base[CORESIGHT_ED] + EDSCR_REG_OFFSET);

	while (!(*edscr & EDSCR_TXFULL)) {
		if (*edscr & EDSCR_ERR) {
			*status = DBGWRAP_ERR_INSTR_ERROR;
			return 0;
		}
		if (mach_absolute_time() > deadline) {
			*status = DBGWRAP_ERR_INSTR_TIMEOUT;
			return 0;
		}
	}

	uint32_t dtrrx = *((volatile uint32_t*)(cdp->coresight_base[CORESIGHT_ED] + EDDTRRX_REG_OFFSET));
	uint32_t dtrtx = *((volatile uint32_t*)(cdp->coresight_base[CORESIGHT_ED] + EDDTRTX_REG_OFFSET));

	return (((uint64_t)dtrrx << 32) | dtrtx);
}

dbgwrap_status_t
ml_dbgwrap_halt_cpu_with_state(int cpu_index, uint64_t timeout_ns, dbgwrap_thread_state_t *state)
{
	cpu_data_t *cdp = cpu_datap(cpu_index);
	if ((cdp == NULL) || (cdp->coresight_base[CORESIGHT_ED] == 0))
		return DBGWRAP_ERR_UNSUPPORTED;

	/* Ensure memory-mapped coresight registers can be written */
	*((volatile uint32_t *)(cdp->coresight_base[CORESIGHT_ED] + ARM_DEBUG_OFFSET_DBGLAR)) = ARM_DBG_LOCK_ACCESS_KEY;

	dbgwrap_status_t status = ml_dbgwrap_halt_cpu(cpu_index, timeout_ns);

	/* A core that is not fully powered (e.g. idling in wfi) can still be halted; the dbgwrap
	 * register and certain coresight registers such EDPRSR are in the always-on domain.
	 * However, EDSCR/EDITR are not in the always-on domain and will generate a parity abort
	 * on read.  EDPRSR can be safely read in all cases, and the OS lock defaults to being set
	 * but we clear it first thing, so use that to detect the offline state. */
	if (*((volatile uint32_t *)(cdp->coresight_base[CORESIGHT_ED] + EDPRSR_REG_OFFSET)) & EDPRSR_OSLK) {
		bzero(state, sizeof(*state));
		return DBGWRAP_WARN_CPU_OFFLINE;
	}

	uint32_t instr;

	for (unsigned int i = 0; i < (sizeof(state->x) / sizeof(state->x[0])); ++i) {
		instr = (0xD51U << 20) | (2 << 19) | (3 << 16) | (4 << 8) | i; // msr DBGDTR0, x<i>
		ml_dbgwrap_stuff_instr(cdp, instr, timeout_ns, &status);
		state->x[i] = ml_dbgwrap_read_dtr(cdp, timeout_ns, &status);
	}

	instr = (0xD51U << 20) | (2 << 19) | (3 << 16) | (4 << 8) | 29; // msr DBGDTR0, fp
	ml_dbgwrap_stuff_instr(cdp, instr, timeout_ns, &status);
	state->fp = ml_dbgwrap_read_dtr(cdp, timeout_ns, &status);

	instr = (0xD51U << 20) | (2 << 19) | (3 << 16) | (4 << 8) | 30; // msr DBGDTR0, lr
	ml_dbgwrap_stuff_instr(cdp, instr, timeout_ns, &status);
	state->lr = ml_dbgwrap_read_dtr(cdp, timeout_ns, &status);

	/* Stack pointer (x31) can't be used as a register operand for msr; register 31 is treated as xzr
	 * rather than sp when used as the transfer operand there.  Instead, load sp into a GPR
	 * we've already saved off and then store that register in the DTR.  I've chosen x18
	 * as the temporary GPR since it's reserved by the arm64 ABI and unused by xnu, so overwriting
	 * it poses the least risk of causing trouble for external debuggers. */ 

	instr = (0x91U << 24) | (31 << 5) | 18; // mov x18, sp
	ml_dbgwrap_stuff_instr(cdp, instr, timeout_ns, &status);
	instr = (0xD51U << 20) | (2 << 19) | (3 << 16) | (4 << 8) | 18; // msr DBGDTR0, x18
	ml_dbgwrap_stuff_instr(cdp, instr, timeout_ns, &status);
	state->sp = ml_dbgwrap_read_dtr(cdp, timeout_ns, &status);

	/* reading PC (e.g. through adr) is undefined in debug state.  Instead use DLR_EL0,
	 * which contains PC at time of entry into debug state.*/

	instr = (0xD53U << 20) | (1 << 19) | (3 << 16) | (4 << 12) | (5 << 8) | (1 << 5) | 18; // mrs    x18, DLR_EL0
	ml_dbgwrap_stuff_instr(cdp, instr, timeout_ns, &status);
	instr = (0xD51U << 20) | (2 << 19) | (3 << 16) | (4 << 8) | 18; // msr DBGDTR0, x18
	ml_dbgwrap_stuff_instr(cdp, instr, timeout_ns, &status);
	state->pc = ml_dbgwrap_read_dtr(cdp, timeout_ns, &status);

	/* reading CPSR is undefined in debug state.  Instead use DSPSR_EL0,
	 * which contains CPSR at time of entry into debug state.*/
	instr = (0xD53U << 20) | (1 << 19) | (3 << 16) | (4 << 12) | (5 << 8) | 18; // mrs    x18, DSPSR_EL0
	ml_dbgwrap_stuff_instr(cdp, instr, timeout_ns, &status);
	instr = (0xD51U << 20) | (2 << 19) | (3 << 16) | (4 << 8) | 18; // msr DBGDTR0, x18
	ml_dbgwrap_stuff_instr(cdp, instr, timeout_ns, &status);
	state->cpsr = (uint32_t)ml_dbgwrap_read_dtr(cdp, timeout_ns, &status);

	return status;
}

