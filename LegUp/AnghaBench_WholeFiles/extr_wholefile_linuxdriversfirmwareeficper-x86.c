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
typedef  size_t u8 ;
typedef  int u64 ;
typedef  int u16 ;
struct cper_sec_proc_ia {int validation_bits; struct cper_ia_proc_ctx* cpuid; int /*<<< orphan*/  lapic_id; } ;
struct cper_ia_proc_ctx {int reg_arr_size; size_t reg_ctx_type; int /*<<< orphan*/  mm_reg_addr; int /*<<< orphan*/  msr_addr; } ;
struct cper_ia_err_info {int validation_bits; int check_info; int /*<<< orphan*/  ip; int /*<<< orphan*/  responder_id; int /*<<< orphan*/  requestor_id; int /*<<< orphan*/  target_id; int /*<<< orphan*/  err_type; } ;
typedef  int /*<<< orphan*/  newpfx ;
typedef  int /*<<< orphan*/  infopfx ;
typedef  int /*<<< orphan*/  guid_t ;
typedef  enum err_types { ____Placeholder_err_types } err_types ;

/* Variables and functions */
 size_t ARRAY_SIZE (char**) ; 
 size_t CHECK_BUS_ADDR_SPACE (int) ; 
 size_t CHECK_BUS_PART_TYPE (int) ; 
 int CHECK_BUS_TIME_OUT ; 
 int /*<<< orphan*/  CHECK_LEVEL (int) ; 
 size_t CHECK_MS_ERR_TYPE (int) ; 
 int CHECK_MS_OVERFLOW ; 
 int CHECK_MS_PCC ; 
 int CHECK_MS_PRECISE_IP ; 
 int CHECK_MS_RESTARTABLE_IP ; 
 int CHECK_MS_UNCORRECTED ; 
 size_t CHECK_OPERATION (int) ; 
 int CHECK_OVERFLOW ; 
 int CHECK_PCC ; 
 int CHECK_PRECISE_IP ; 
 int CHECK_RESTARTABLE_IP ; 
 size_t CHECK_TRANS_TYPE (int) ; 
 int CHECK_UNCORRECTED ; 
 int CHECK_VALID_BITS (int) ; 
 int CHECK_VALID_BUS_ADDR_SPACE ; 
 int CHECK_VALID_BUS_PART_TYPE ; 
 int CHECK_VALID_BUS_TIME_OUT ; 
 int CHECK_VALID_LEVEL ; 
 int CHECK_VALID_MS_ERR_TYPE ; 
 int CHECK_VALID_MS_OVERFLOW ; 
 int CHECK_VALID_MS_PCC ; 
 int CHECK_VALID_MS_PRECISE_IP ; 
 int CHECK_VALID_MS_RESTARTABLE_IP ; 
 int CHECK_VALID_MS_UNCORRECTED ; 
 int CHECK_VALID_OPERATION ; 
 int CHECK_VALID_OVERFLOW ; 
 int CHECK_VALID_PCC ; 
 int CHECK_VALID_PRECISE_IP ; 
 int CHECK_VALID_RESTARTABLE_IP ; 
 int CHECK_VALID_TRANS_TYPE ; 
 int CHECK_VALID_UNCORRECTED ; 
 size_t CTX_TYPE_MMREG ; 
 size_t CTX_TYPE_MSR ; 
 int /*<<< orphan*/  DUMP_PREFIX_OFFSET ; 
 int ERR_TYPE_BUS ; 
 int ERR_TYPE_CACHE ; 
 int ERR_TYPE_MS ; 
 int ERR_TYPE_TLB ; 
 int /*<<< orphan*/  INFO_ERR_STRUCT_TYPE_BUS ; 
 int /*<<< orphan*/  INFO_ERR_STRUCT_TYPE_CACHE ; 
 int /*<<< orphan*/  INFO_ERR_STRUCT_TYPE_MS ; 
 int /*<<< orphan*/  INFO_ERR_STRUCT_TYPE_TLB ; 
 int INFO_VALID_CHECK_INFO ; 
 int INFO_VALID_IP ; 
 int INFO_VALID_REQUESTOR_ID ; 
 int INFO_VALID_RESPONDER_ID ; 
 int INFO_VALID_TARGET_ID ; 
 int N_ERR_TYPES ; 
 int VALID_CPUID_INFO ; 
 int VALID_LAPIC_ID ; 
 int VALID_PROC_CXT_INFO_NUM (int) ; 
 int VALID_PROC_ERR_INFO_NUM (int) ; 
 char** cper_proc_error_type_strs ; 
 scalar_t__ guid_equal (int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 char** ia_check_bus_addr_space_strs ; 
 char** ia_check_bus_part_type_strs ; 
 char** ia_check_ms_error_type_strs ; 
 char** ia_check_op_strs ; 
 char** ia_check_trans_type_strs ; 
 char** ia_reg_ctx_strs ; 
 int /*<<< orphan*/  print_hex_dump (char const*,char*,int /*<<< orphan*/ ,int,int,struct cper_ia_proc_ctx*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*,char const*,...) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char const*) ; 

__attribute__((used)) static enum err_types cper_get_err_type(const guid_t *err_type)
{
	if (guid_equal(err_type, &INFO_ERR_STRUCT_TYPE_CACHE))
		return ERR_TYPE_CACHE;
	else if (guid_equal(err_type, &INFO_ERR_STRUCT_TYPE_TLB))
		return ERR_TYPE_TLB;
	else if (guid_equal(err_type, &INFO_ERR_STRUCT_TYPE_BUS))
		return ERR_TYPE_BUS;
	else if (guid_equal(err_type, &INFO_ERR_STRUCT_TYPE_MS))
		return ERR_TYPE_MS;
	else
		return N_ERR_TYPES;
}

__attribute__((used)) static inline void print_bool(char *str, const char *pfx, u64 check, u64 bit)
{
	printk("%s%s: %s\n", pfx, str, (check & bit) ? "true" : "false");
}

__attribute__((used)) static void print_err_info_ms(const char *pfx, u16 validation_bits, u64 check)
{
	if (validation_bits & CHECK_VALID_MS_ERR_TYPE) {
		u8 err_type = CHECK_MS_ERR_TYPE(check);

		printk("%sError Type: %u, %s\n", pfx, err_type,
		       err_type < ARRAY_SIZE(ia_check_ms_error_type_strs) ?
		       ia_check_ms_error_type_strs[err_type] : "unknown");
	}

	if (validation_bits & CHECK_VALID_MS_PCC)
		print_bool("Processor Context Corrupt", pfx, check, CHECK_MS_PCC);

	if (validation_bits & CHECK_VALID_MS_UNCORRECTED)
		print_bool("Uncorrected", pfx, check, CHECK_MS_UNCORRECTED);

	if (validation_bits & CHECK_VALID_MS_PRECISE_IP)
		print_bool("Precise IP", pfx, check, CHECK_MS_PRECISE_IP);

	if (validation_bits & CHECK_VALID_MS_RESTARTABLE_IP)
		print_bool("Restartable IP", pfx, check, CHECK_MS_RESTARTABLE_IP);

	if (validation_bits & CHECK_VALID_MS_OVERFLOW)
		print_bool("Overflow", pfx, check, CHECK_MS_OVERFLOW);
}

__attribute__((used)) static void print_err_info(const char *pfx, u8 err_type, u64 check)
{
	u16 validation_bits = CHECK_VALID_BITS(check);

	/*
	 * The MS Check structure varies a lot from the others, so use a
	 * separate function for decoding.
	 */
	if (err_type == ERR_TYPE_MS)
		return print_err_info_ms(pfx, validation_bits, check);

	if (validation_bits & CHECK_VALID_TRANS_TYPE) {
		u8 trans_type = CHECK_TRANS_TYPE(check);

		printk("%sTransaction Type: %u, %s\n", pfx, trans_type,
		       trans_type < ARRAY_SIZE(ia_check_trans_type_strs) ?
		       ia_check_trans_type_strs[trans_type] : "unknown");
	}

	if (validation_bits & CHECK_VALID_OPERATION) {
		u8 op = CHECK_OPERATION(check);

		/*
		 * CACHE has more operation types than TLB or BUS, though the
		 * name and the order are the same.
		 */
		u8 max_ops = (err_type == ERR_TYPE_CACHE) ? 9 : 7;

		printk("%sOperation: %u, %s\n", pfx, op,
		       op < max_ops ? ia_check_op_strs[op] : "unknown");
	}

	if (validation_bits & CHECK_VALID_LEVEL)
		printk("%sLevel: %llu\n", pfx, CHECK_LEVEL(check));

	if (validation_bits & CHECK_VALID_PCC)
		print_bool("Processor Context Corrupt", pfx, check, CHECK_PCC);

	if (validation_bits & CHECK_VALID_UNCORRECTED)
		print_bool("Uncorrected", pfx, check, CHECK_UNCORRECTED);

	if (validation_bits & CHECK_VALID_PRECISE_IP)
		print_bool("Precise IP", pfx, check, CHECK_PRECISE_IP);

	if (validation_bits & CHECK_VALID_RESTARTABLE_IP)
		print_bool("Restartable IP", pfx, check, CHECK_RESTARTABLE_IP);

	if (validation_bits & CHECK_VALID_OVERFLOW)
		print_bool("Overflow", pfx, check, CHECK_OVERFLOW);

	if (err_type != ERR_TYPE_BUS)
		return;

	if (validation_bits & CHECK_VALID_BUS_PART_TYPE) {
		u8 part_type = CHECK_BUS_PART_TYPE(check);

		printk("%sParticipation Type: %u, %s\n", pfx, part_type,
		       part_type < ARRAY_SIZE(ia_check_bus_part_type_strs) ?
		       ia_check_bus_part_type_strs[part_type] : "unknown");
	}

	if (validation_bits & CHECK_VALID_BUS_TIME_OUT)
		print_bool("Time Out", pfx, check, CHECK_BUS_TIME_OUT);

	if (validation_bits & CHECK_VALID_BUS_ADDR_SPACE) {
		u8 addr_space = CHECK_BUS_ADDR_SPACE(check);

		printk("%sAddress Space: %u, %s\n", pfx, addr_space,
		       addr_space < ARRAY_SIZE(ia_check_bus_addr_space_strs) ?
		       ia_check_bus_addr_space_strs[addr_space] : "unknown");
	}
}

void cper_print_proc_ia(const char *pfx, const struct cper_sec_proc_ia *proc)
{
	int i;
	struct cper_ia_err_info *err_info;
	struct cper_ia_proc_ctx *ctx_info;
	char newpfx[64], infopfx[64];
	u8 err_type;

	if (proc->validation_bits & VALID_LAPIC_ID)
		printk("%sLocal APIC_ID: 0x%llx\n", pfx, proc->lapic_id);

	if (proc->validation_bits & VALID_CPUID_INFO) {
		printk("%sCPUID Info:\n", pfx);
		print_hex_dump(pfx, "", DUMP_PREFIX_OFFSET, 16, 4, proc->cpuid,
			       sizeof(proc->cpuid), 0);
	}

	snprintf(newpfx, sizeof(newpfx), "%s ", pfx);

	err_info = (struct cper_ia_err_info *)(proc + 1);
	for (i = 0; i < VALID_PROC_ERR_INFO_NUM(proc->validation_bits); i++) {
		printk("%sError Information Structure %d:\n", pfx, i);

		err_type = cper_get_err_type(&err_info->err_type);
		printk("%sError Structure Type: %s\n", newpfx,
		       err_type < ARRAY_SIZE(cper_proc_error_type_strs) ?
		       cper_proc_error_type_strs[err_type] : "unknown");

		if (err_type >= N_ERR_TYPES) {
			printk("%sError Structure Type: %pUl\n", newpfx,
			       &err_info->err_type);
		}

		if (err_info->validation_bits & INFO_VALID_CHECK_INFO) {
			printk("%sCheck Information: 0x%016llx\n", newpfx,
			       err_info->check_info);

			if (err_type < N_ERR_TYPES) {
				snprintf(infopfx, sizeof(infopfx), "%s ",
					 newpfx);

				print_err_info(infopfx, err_type,
					       err_info->check_info);
			}
		}

		if (err_info->validation_bits & INFO_VALID_TARGET_ID) {
			printk("%sTarget Identifier: 0x%016llx\n",
			       newpfx, err_info->target_id);
		}

		if (err_info->validation_bits & INFO_VALID_REQUESTOR_ID) {
			printk("%sRequestor Identifier: 0x%016llx\n",
			       newpfx, err_info->requestor_id);
		}

		if (err_info->validation_bits & INFO_VALID_RESPONDER_ID) {
			printk("%sResponder Identifier: 0x%016llx\n",
			       newpfx, err_info->responder_id);
		}

		if (err_info->validation_bits & INFO_VALID_IP) {
			printk("%sInstruction Pointer: 0x%016llx\n",
			       newpfx, err_info->ip);
		}

		err_info++;
	}

	ctx_info = (struct cper_ia_proc_ctx *)err_info;
	for (i = 0; i < VALID_PROC_CXT_INFO_NUM(proc->validation_bits); i++) {
		int size = sizeof(*ctx_info) + ctx_info->reg_arr_size;
		int groupsize = 4;

		printk("%sContext Information Structure %d:\n", pfx, i);

		printk("%sRegister Context Type: %s\n", newpfx,
		       ctx_info->reg_ctx_type < ARRAY_SIZE(ia_reg_ctx_strs) ?
		       ia_reg_ctx_strs[ctx_info->reg_ctx_type] : "unknown");

		printk("%sRegister Array Size: 0x%04x\n", newpfx,
		       ctx_info->reg_arr_size);

		if (ctx_info->reg_ctx_type == CTX_TYPE_MSR) {
			groupsize = 8; /* MSRs are 8 bytes wide. */
			printk("%sMSR Address: 0x%08x\n", newpfx,
			       ctx_info->msr_addr);
		}

		if (ctx_info->reg_ctx_type == CTX_TYPE_MMREG) {
			printk("%sMM Register Address: 0x%016llx\n", newpfx,
			       ctx_info->mm_reg_addr);
		}

		printk("%sRegister Array:\n", newpfx);
		print_hex_dump(newpfx, "", DUMP_PREFIX_OFFSET, 16, groupsize,
			       (ctx_info + 1), ctx_info->reg_arr_size, 0);

		ctx_info = (struct cper_ia_proc_ctx *)((long)ctx_info + size);
	}
}

