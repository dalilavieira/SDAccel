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
union kvm_mmu_page_role {int word; size_t access; scalar_t__ smm; scalar_t__ smap_and_not_wp; scalar_t__ smep_and_not_wp; scalar_t__ cr0_wp; scalar_t__ nxe; scalar_t__ cr4_pae; scalar_t__ invalid; scalar_t__ direct; int /*<<< orphan*/  quadrant; int /*<<< orphan*/  level; } ;
typedef  unsigned char uint8_t ;
typedef  unsigned long long uint64_t ;
struct trace_seq {int dummy; } ;
struct tep_record {int dummy; } ;
struct tep_handle {int flags; scalar_t__ host_bigendian; scalar_t__ file_bigendian; int cpus; int long_size; int page_size; int latency_format; } ;
struct str_values {int val; char const* str; } ;
struct event_format {struct tep_handle* pevent; } ;
struct TYPE_2__ {unsigned int isa; struct str_values* strings; } ;

/* Variables and functions */
 unsigned long long KVM_EMUL_INSN_F_CR0_PE ; 
 unsigned long long KVM_EMUL_INSN_F_CS_D ; 
 unsigned long long KVM_EMUL_INSN_F_CS_L ; 
 unsigned long long KVM_EMUL_INSN_F_EFL_VM ; 
 unsigned long PT_WRITABLE_MASK ; 
 int /*<<< orphan*/  TEP_FUNC_ARG_INT ; 
 int /*<<< orphan*/  TEP_FUNC_ARG_LONG ; 
 int /*<<< orphan*/  TEP_FUNC_ARG_VOID ; 
 TYPE_1__* isa_exit_reasons ; 
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned char*,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned char) ; 
 unsigned char* tep_get_field_raw (struct trace_seq*,struct event_format*,char*,struct tep_record*,int*,int) ; 
 scalar_t__ tep_get_field_val (struct trace_seq*,struct event_format*,char const*,struct tep_record*,unsigned long long*,int) ; 
 int /*<<< orphan*/  tep_print_num_field (struct trace_seq*,char*,struct event_format*,char*,struct tep_record*,int) ; 
 int /*<<< orphan*/  tep_register_event_handler (struct tep_handle*,int,char*,char*,int (*) (struct trace_seq*,struct tep_record*,struct event_format*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tep_register_print_function (struct tep_handle*,unsigned long long (*) (struct trace_seq*,unsigned long long*),int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tep_unregister_event_handler (struct tep_handle*,int,char*,char*,int (*) (struct trace_seq*,struct tep_record*,struct event_format*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tep_unregister_print_function (struct tep_handle*,unsigned long long (*) (struct trace_seq*,unsigned long long*),char*) ; 
 int /*<<< orphan*/  trace_seq_printf (struct trace_seq*,char*,...) ; 

__attribute__((used)) static inline void tep_set_flag(struct tep_handle *pevent, int flag)
{
	pevent->flags |= flag;
}

__attribute__((used)) static inline unsigned short
__data2host2(struct tep_handle *pevent, unsigned short data)
{
	unsigned short swap;

	if (pevent->host_bigendian == pevent->file_bigendian)
		return data;

	swap = ((data & 0xffULL) << 8) |
		((data & (0xffULL << 8)) >> 8);

	return swap;
}

__attribute__((used)) static inline unsigned int
__data2host4(struct tep_handle *pevent, unsigned int data)
{
	unsigned int swap;

	if (pevent->host_bigendian == pevent->file_bigendian)
		return data;

	swap = ((data & 0xffULL) << 24) |
		((data & (0xffULL << 8)) << 8) |
		((data & (0xffULL << 16)) >> 8) |
		((data & (0xffULL << 24)) >> 24);

	return swap;
}

__attribute__((used)) static inline unsigned long long
__data2host8(struct tep_handle *pevent, unsigned long long data)
{
	unsigned long long swap;

	if (pevent->host_bigendian == pevent->file_bigendian)
		return data;

	swap = ((data & 0xffULL) << 56) |
		((data & (0xffULL << 8)) << 40) |
		((data & (0xffULL << 16)) << 24) |
		((data & (0xffULL << 24)) << 8) |
		((data & (0xffULL << 32)) >> 8) |
		((data & (0xffULL << 40)) >> 24) |
		((data & (0xffULL << 48)) >> 40) |
		((data & (0xffULL << 56)) >> 56);

	return swap;
}

__attribute__((used)) static inline int tep_host_bigendian(void)
{
	unsigned char str[] = { 0x1, 0x2, 0x3, 0x4 };
	unsigned int val;

	memcpy(&val, str, 4);
	return val == 0x01020304;
}

__attribute__((used)) static inline int tep_get_cpus(struct tep_handle *pevent)
{
	return pevent->cpus;
}

__attribute__((used)) static inline void tep_set_cpus(struct tep_handle *pevent, int cpus)
{
	pevent->cpus = cpus;
}

__attribute__((used)) static inline int tep_get_long_size(struct tep_handle *pevent)
{
	return pevent->long_size;
}

__attribute__((used)) static inline void tep_set_long_size(struct tep_handle *pevent, int long_size)
{
	pevent->long_size = long_size;
}

__attribute__((used)) static inline int tep_get_page_size(struct tep_handle *pevent)
{
	return pevent->page_size;
}

__attribute__((used)) static inline void tep_set_page_size(struct tep_handle *pevent, int _page_size)
{
	pevent->page_size = _page_size;
}

__attribute__((used)) static inline int tep_is_file_bigendian(struct tep_handle *pevent)
{
	return pevent->file_bigendian;
}

__attribute__((used)) static inline void tep_set_file_bigendian(struct tep_handle *pevent, int endian)
{
	pevent->file_bigendian = endian;
}

__attribute__((used)) static inline int tep_is_host_bigendian(struct tep_handle *pevent)
{
	return pevent->host_bigendian;
}

__attribute__((used)) static inline void tep_set_host_bigendian(struct tep_handle *pevent, int endian)
{
	pevent->host_bigendian = endian;
}

__attribute__((used)) static inline int tep_is_latency_format(struct tep_handle *pevent)
{
	return pevent->latency_format;
}

__attribute__((used)) static inline void tep_set_latency_format(struct tep_handle *pevent, int lat)
{
	pevent->latency_format = lat;
}

__attribute__((used)) static void init_disassembler(void)
{
}

__attribute__((used)) static const char *disassemble(unsigned char *insn, int len, uint64_t rip,
			       int cr0_pe, int eflags_vm,
			       int cs_d, int cs_l)
{
	static char out[15*3+1];
	int i;

	for (i = 0; i < len; ++i)
		sprintf(out + i * 3, "%02x ", insn[i]);
	out[len*3-1] = '\0';
	return out;
}

__attribute__((used)) static const char *find_exit_reason(unsigned isa, int val)
{
	struct str_values *strings = NULL;
	int i;

	for (i = 0; isa_exit_reasons[i].strings; ++i)
		if (isa_exit_reasons[i].isa == isa) {
			strings = isa_exit_reasons[i].strings;
			break;
		}
	if (!strings)
		return "UNKNOWN-ISA";
	for (i = 0; strings[i].val >= 0; i++)
		if (strings[i].val == val)
			break;

	return strings[i].str;
}

__attribute__((used)) static int print_exit_reason(struct trace_seq *s, struct tep_record *record,
			     struct event_format *event, const char *field)
{
	unsigned long long isa;
	unsigned long long val;
	const char *reason;

	if (tep_get_field_val(s, event, field, record, &val, 1) < 0)
		return -1;

	if (tep_get_field_val(s, event, "isa", record, &isa, 0) < 0)
		isa = 1;

	reason = find_exit_reason(isa, val);
	if (reason)
		trace_seq_printf(s, "reason %s", reason);
	else
		trace_seq_printf(s, "reason UNKNOWN (%llu)", val);
	return 0;
}

__attribute__((used)) static int kvm_exit_handler(struct trace_seq *s, struct tep_record *record,
			    struct event_format *event, void *context)
{
	unsigned long long info1 = 0, info2 = 0;

	if (print_exit_reason(s, record, event, "exit_reason") < 0)
		return -1;

	tep_print_num_field(s, " rip 0x%lx", event, "guest_rip", record, 1);

	if (tep_get_field_val(s, event, "info1", record, &info1, 0) >= 0
	    && tep_get_field_val(s, event, "info2", record, &info2, 0) >= 0)
		trace_seq_printf(s, " info %llx %llx", info1, info2);

	return 0;
}

__attribute__((used)) static int kvm_emulate_insn_handler(struct trace_seq *s,
				    struct tep_record *record,
				    struct event_format *event, void *context)
{
	unsigned long long rip, csbase, len, flags, failed;
	int llen;
	uint8_t *insn;
	const char *disasm;

	if (tep_get_field_val(s, event, "rip", record, &rip, 1) < 0)
		return -1;

	if (tep_get_field_val(s, event, "csbase", record, &csbase, 1) < 0)
		return -1;

	if (tep_get_field_val(s, event, "len", record, &len, 1) < 0)
		return -1;

	if (tep_get_field_val(s, event, "flags", record, &flags, 1) < 0)
		return -1;

	if (tep_get_field_val(s, event, "failed", record, &failed, 1) < 0)
		return -1;

	insn = tep_get_field_raw(s, event, "insn", record, &llen, 1);
	if (!insn)
		return -1;

	disasm = disassemble(insn, len, rip,
			     flags & KVM_EMUL_INSN_F_CR0_PE,
			     flags & KVM_EMUL_INSN_F_EFL_VM,
			     flags & KVM_EMUL_INSN_F_CS_D,
			     flags & KVM_EMUL_INSN_F_CS_L);

	trace_seq_printf(s, "%llx:%llx: %s%s", csbase, rip, disasm,
			 failed ? " FAIL" : "");
	return 0;
}

__attribute__((used)) static int kvm_nested_vmexit_inject_handler(struct trace_seq *s, struct tep_record *record,
					    struct event_format *event, void *context)
{
	if (print_exit_reason(s, record, event, "exit_code") < 0)
		return -1;

	tep_print_num_field(s, " info1 %llx", event, "exit_info1", record, 1);
	tep_print_num_field(s, " info2 %llx", event, "exit_info2", record, 1);
	tep_print_num_field(s, " int_info %llx", event, "exit_int_info", record, 1);
	tep_print_num_field(s, " int_info_err %llx", event, "exit_int_info_err", record, 1);

	return 0;
}

__attribute__((used)) static int kvm_nested_vmexit_handler(struct trace_seq *s, struct tep_record *record,
				     struct event_format *event, void *context)
{
	tep_print_num_field(s, "rip %llx ", event, "rip", record, 1);

	return kvm_nested_vmexit_inject_handler(s, record, event, context);
}

__attribute__((used)) static int kvm_mmu_print_role(struct trace_seq *s, struct tep_record *record,
			      struct event_format *event, void *context)
{
	unsigned long long val;
	static const char *access_str[] = {
		"---", "--x", "w--", "w-x", "-u-", "-ux", "wu-", "wux"
	};
	union kvm_mmu_page_role role;

	if (tep_get_field_val(s, event, "role", record, &val, 1) < 0)
		return -1;

	role.word = (int)val;

	/*
	 * We can only use the structure if file is of the same
	 * endianess.
	 */
	if (tep_is_file_bigendian(event->pevent) ==
	    tep_is_host_bigendian(event->pevent)) {

		trace_seq_printf(s, "%u q%u%s %s%s %spae %snxe %swp%s%s%s",
				 role.level,
				 role.quadrant,
				 role.direct ? " direct" : "",
				 access_str[role.access],
				 role.invalid ? " invalid" : "",
				 role.cr4_pae ? "" : "!",
				 role.nxe ? "" : "!",
				 role.cr0_wp ? "" : "!",
				 role.smep_and_not_wp ? " smep" : "",
				 role.smap_and_not_wp ? " smap" : "",
				 role.smm ? " smm" : "");
	} else
		trace_seq_printf(s, "WORD: %08x", role.word);

	tep_print_num_field(s, " root %u ",  event,
			    "root_count", record, 1);

	if (tep_get_field_val(s, event, "unsync", record, &val, 1) < 0)
		return -1;

	trace_seq_printf(s, "%s%c",  val ? "unsync" : "sync", 0);
	return 0;
}

__attribute__((used)) static int kvm_mmu_get_page_handler(struct trace_seq *s,
				    struct tep_record *record,
				    struct event_format *event, void *context)
{
	unsigned long long val;

	if (tep_get_field_val(s, event, "created", record, &val, 1) < 0)
		return -1;

	trace_seq_printf(s, "%s ", val ? "new" : "existing");

	if (tep_get_field_val(s, event, "gfn", record, &val, 1) < 0)
		return -1;

	trace_seq_printf(s, "sp gfn %llx ", val);
	return kvm_mmu_print_role(s, record, event, context);
}

__attribute__((used)) static unsigned long long
process_is_writable_pte(struct trace_seq *s, unsigned long long *args)
{
	unsigned long pte = args[0];
	return pte & PT_WRITABLE_MASK;
}

int TEP_PLUGIN_LOADER(struct tep_handle *pevent)
{
	init_disassembler();

	tep_register_event_handler(pevent, -1, "kvm", "kvm_exit",
				   kvm_exit_handler, NULL);

	tep_register_event_handler(pevent, -1, "kvm", "kvm_emulate_insn",
				   kvm_emulate_insn_handler, NULL);

	tep_register_event_handler(pevent, -1, "kvm", "kvm_nested_vmexit",
				   kvm_nested_vmexit_handler, NULL);

	tep_register_event_handler(pevent, -1, "kvm", "kvm_nested_vmexit_inject",
				   kvm_nested_vmexit_inject_handler, NULL);

	tep_register_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_get_page",
				   kvm_mmu_get_page_handler, NULL);

	tep_register_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_sync_page",
				   kvm_mmu_print_role, NULL);

	tep_register_event_handler(pevent, -1,
				   "kvmmmu", "kvm_mmu_unsync_page",
				   kvm_mmu_print_role, NULL);

	tep_register_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_zap_page",
				   kvm_mmu_print_role, NULL);

	tep_register_event_handler(pevent, -1, "kvmmmu",
			"kvm_mmu_prepare_zap_page", kvm_mmu_print_role,
			NULL);

	tep_register_print_function(pevent,
				    process_is_writable_pte,
				    TEP_FUNC_ARG_INT,
				    "is_writable_pte",
				    TEP_FUNC_ARG_LONG,
				    TEP_FUNC_ARG_VOID);
	return 0;
}

void TEP_PLUGIN_UNLOADER(struct tep_handle *pevent)
{
	tep_unregister_event_handler(pevent, -1, "kvm", "kvm_exit",
				     kvm_exit_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kvm", "kvm_emulate_insn",
				     kvm_emulate_insn_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kvm", "kvm_nested_vmexit",
				     kvm_nested_vmexit_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kvm", "kvm_nested_vmexit_inject",
				     kvm_nested_vmexit_inject_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_get_page",
				     kvm_mmu_get_page_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_sync_page",
				     kvm_mmu_print_role, NULL);

	tep_unregister_event_handler(pevent, -1,
				     "kvmmmu", "kvm_mmu_unsync_page",
				     kvm_mmu_print_role, NULL);

	tep_unregister_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_zap_page",
				     kvm_mmu_print_role, NULL);

	tep_unregister_event_handler(pevent, -1, "kvmmmu",
			"kvm_mmu_prepare_zap_page", kvm_mmu_print_role,
			NULL);

	tep_unregister_print_function(pevent, process_is_writable_pte,
				      "is_writable_pte");
}

