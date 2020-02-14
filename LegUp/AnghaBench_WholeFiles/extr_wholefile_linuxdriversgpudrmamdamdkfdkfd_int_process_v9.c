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
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  scalar_t__ uint16_t ;
struct kfd_vm_fault_info {int page_addr; scalar_t__ prot_write; scalar_t__ prot_read; scalar_t__ prot_valid; scalar_t__ mc_id; scalar_t__ vmid; int /*<<< orphan*/  member_0; } ;
struct TYPE_2__ {scalar_t__ first_vmid_kfd; scalar_t__ last_vmid_kfd; } ;
struct kfd_dev {int /*<<< orphan*/  dqm; TYPE_1__ vm_info; } ;

/* Variables and functions */
 scalar_t__ SOC15_CLIENT_ID_FROM_IH_ENTRY (int const*) ; 
 int SOC15_CONTEXT_ID0_FROM_IH_ENTRY (int const*) ; 
 scalar_t__ SOC15_IH_CLIENTID_UTCL2 ; 
 scalar_t__ SOC15_IH_CLIENTID_VMC ; 
 scalar_t__ SOC15_INTSRC_CP_BAD_OPCODE ; 
 scalar_t__ SOC15_INTSRC_CP_END_OF_PIPE ; 
 scalar_t__ SOC15_INTSRC_SDMA_TRAP ; 
 scalar_t__ SOC15_INTSRC_SQ_INTERRUPT_MSG ; 
 scalar_t__ SOC15_PASID_FROM_IH_ENTRY (int const*) ; 
 scalar_t__ SOC15_RING_ID_FROM_IH_ENTRY (int const*) ; 
 scalar_t__ SOC15_SOURCE_ID_FROM_IH_ENTRY (int const*) ; 
 scalar_t__ SOC15_VMID_FROM_IH_ENTRY (int const*) ; 
 scalar_t__ WARN_ONCE (int,char*) ; 
 int /*<<< orphan*/  kfd_process_vm_fault (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  kfd_signal_event_interrupt (scalar_t__,int,int) ; 
 int /*<<< orphan*/  kfd_signal_hw_exception_event (scalar_t__) ; 
 int /*<<< orphan*/  kfd_signal_vm_fault_event (struct kfd_dev*,scalar_t__,struct kfd_vm_fault_info*) ; 
 int /*<<< orphan*/  pr_debug (char*,int const,int const,int const,...) ; 

__attribute__((used)) static inline void kfd_debugfs_init(void) {}

__attribute__((used)) static inline void kfd_debugfs_fini(void) {}

__attribute__((used)) static bool event_interrupt_isr_v9(struct kfd_dev *dev,
					const uint32_t *ih_ring_entry,
					uint32_t *patched_ihre,
					bool *patched_flag)
{
	uint16_t source_id, client_id, pasid, vmid;
	const uint32_t *data = ih_ring_entry;

	/* Only handle interrupts from KFD VMIDs */
	vmid = SOC15_VMID_FROM_IH_ENTRY(ih_ring_entry);
	if (vmid < dev->vm_info.first_vmid_kfd ||
	    vmid > dev->vm_info.last_vmid_kfd)
		return 0;

	/* If there is no valid PASID, it's likely a firmware bug */
	pasid = SOC15_PASID_FROM_IH_ENTRY(ih_ring_entry);
	if (WARN_ONCE(pasid == 0, "FW bug: No PASID in KFD interrupt"))
		return 0;

	source_id = SOC15_SOURCE_ID_FROM_IH_ENTRY(ih_ring_entry);
	client_id = SOC15_CLIENT_ID_FROM_IH_ENTRY(ih_ring_entry);

	pr_debug("client id 0x%x, source id %d, pasid 0x%x. raw data:\n",
		 client_id, source_id, pasid);
	pr_debug("%8X, %8X, %8X, %8X, %8X, %8X, %8X, %8X.\n",
		 data[0], data[1], data[2], data[3],
		 data[4], data[5], data[6], data[7]);

	/* Interrupt types we care about: various signals and faults.
	 * They will be forwarded to a work queue (see below).
	 */
	return source_id == SOC15_INTSRC_CP_END_OF_PIPE ||
		source_id == SOC15_INTSRC_SDMA_TRAP ||
		source_id == SOC15_INTSRC_SQ_INTERRUPT_MSG ||
		source_id == SOC15_INTSRC_CP_BAD_OPCODE ||
		client_id == SOC15_IH_CLIENTID_VMC ||
		client_id == SOC15_IH_CLIENTID_UTCL2;
}

__attribute__((used)) static void event_interrupt_wq_v9(struct kfd_dev *dev,
					const uint32_t *ih_ring_entry)
{
	uint16_t source_id, client_id, pasid, vmid;
	uint32_t context_id;

	source_id = SOC15_SOURCE_ID_FROM_IH_ENTRY(ih_ring_entry);
	client_id = SOC15_CLIENT_ID_FROM_IH_ENTRY(ih_ring_entry);
	pasid = SOC15_PASID_FROM_IH_ENTRY(ih_ring_entry);
	vmid = SOC15_VMID_FROM_IH_ENTRY(ih_ring_entry);
	context_id = SOC15_CONTEXT_ID0_FROM_IH_ENTRY(ih_ring_entry);

	if (source_id == SOC15_INTSRC_CP_END_OF_PIPE)
		kfd_signal_event_interrupt(pasid, context_id, 32);
	else if (source_id == SOC15_INTSRC_SDMA_TRAP)
		kfd_signal_event_interrupt(pasid, context_id & 0xfffffff, 28);
	else if (source_id == SOC15_INTSRC_SQ_INTERRUPT_MSG)
		kfd_signal_event_interrupt(pasid, context_id & 0xffffff, 24);
	else if (source_id == SOC15_INTSRC_CP_BAD_OPCODE)
		kfd_signal_hw_exception_event(pasid);
	else if (client_id == SOC15_IH_CLIENTID_VMC ||
		 client_id == SOC15_IH_CLIENTID_UTCL2) {
		struct kfd_vm_fault_info info = {0};
		uint16_t ring_id = SOC15_RING_ID_FROM_IH_ENTRY(ih_ring_entry);

		info.vmid = vmid;
		info.mc_id = client_id;
		info.page_addr = ih_ring_entry[4] |
			(uint64_t)(ih_ring_entry[5] & 0xf) << 32;
		info.prot_valid = ring_id & 0x08;
		info.prot_read  = ring_id & 0x10;
		info.prot_write = ring_id & 0x20;

		kfd_process_vm_fault(dev->dqm, pasid);
		kfd_signal_vm_fault_event(dev, pasid, &info);
	}
}

