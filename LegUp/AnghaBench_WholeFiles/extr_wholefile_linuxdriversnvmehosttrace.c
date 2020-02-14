#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  union nvme_result {int dummy; } nvme_result ;
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct trace_seq {int dummy; } ;
struct request {int /*<<< orphan*/  rq_disk; } ;
struct nvme_request {int status; union nvme_result result; } ;
struct nvme_ns_head {int dummy; } ;
struct nvme_ns {int lba_shift; TYPE_2__* head; } ;
struct nvme_id_ns {int dummy; } ;
struct nvme_id_ctrl {int dummy; } ;
struct nvme_ctrl {int instance; int /*<<< orphan*/  device; TYPE_3__* subsys; TYPE_1__* ops; int /*<<< orphan*/  subsystem; } ;
struct gendisk {int /*<<< orphan*/  disk_name; } ;
struct device {int dummy; } ;
typedef  int sector_t ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_8__ {struct nvme_ns* private_data; } ;
struct TYPE_7__ {int cmic; } ;
struct TYPE_6__ {int instance; } ;
struct TYPE_5__ {int (* reg_write32 ) (struct nvme_ctrl*,int /*<<< orphan*/ ,int) ;scalar_t__ (* reg_read32 ) (struct nvme_ctrl*,int /*<<< orphan*/ ,int*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DISK_NAME_LEN ; 
 int ENOTTY ; 
 int NVME_CSTS_RDY ; 
 int /*<<< orphan*/  NVME_REG_CSTS ; 
 int /*<<< orphan*/  NVME_REG_NSSR ; 
 int /*<<< orphan*/  blk_mq_complete_request (struct request*) ; 
 struct nvme_request* blk_mq_rq_to_pdu (struct request*) ; 
 int /*<<< orphan*/  blk_mq_unique_tag (struct request*) ; 
 scalar_t__ blk_mq_unique_tag_to_hwq (int /*<<< orphan*/ ) ; 
 TYPE_4__* dev_to_disk (struct device*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  get_device (int /*<<< orphan*/ ) ; 
 scalar_t__ get_unaligned_le16 (int*) ; 
 int get_unaligned_le32 (int*) ; 
 int get_unaligned_le64 (int*) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  nvme_admin_create_cq 134 
#define  nvme_admin_create_sq 133 
#define  nvme_admin_identify 132 
#define  nvme_cmd_dsm 131 
#define  nvme_cmd_read 130 
#define  nvme_cmd_write 129 
#define  nvme_cmd_write_zeroes 128 
 int /*<<< orphan*/  put_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int) ; 
 scalar_t__ stub1 (struct nvme_ctrl*,int /*<<< orphan*/ ,int*) ; 
 int stub2 (struct nvme_ctrl*,int /*<<< orphan*/ ,int) ; 
 char* trace_seq_buffer_ptr (struct trace_seq*) ; 
 int /*<<< orphan*/  trace_seq_printf (struct trace_seq*,char*,...) ; 
 int /*<<< orphan*/  trace_seq_putc (struct trace_seq*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct nvme_request *nvme_req(struct request *req)
{
	return blk_mq_rq_to_pdu(req);
}

__attribute__((used)) static inline u16 nvme_req_qid(struct request *req)
{
	if (!req->rq_disk)
		return 0;
	return blk_mq_unique_tag_to_hwq(blk_mq_unique_tag(req)) + 1;
}

__attribute__((used)) static inline void nvme_fault_inject_init(struct nvme_ns *ns) {}

__attribute__((used)) static inline void nvme_fault_inject_fini(struct nvme_ns *ns) {}

__attribute__((used)) static inline void nvme_should_fail(struct request *req) {}

__attribute__((used)) static inline bool nvme_ctrl_ready(struct nvme_ctrl *ctrl)
{
	u32 val = 0;

	if (ctrl->ops->reg_read32(ctrl, NVME_REG_CSTS, &val))
		return false;
	return val & NVME_CSTS_RDY;
}

__attribute__((used)) static inline int nvme_reset_subsystem(struct nvme_ctrl *ctrl)
{
	if (!ctrl->subsystem)
		return -ENOTTY;
	return ctrl->ops->reg_write32(ctrl, NVME_REG_NSSR, 0x4E564D65);
}

__attribute__((used)) static inline u64 nvme_block_nr(struct nvme_ns *ns, sector_t sector)
{
	return (sector >> (ns->lba_shift - 9));
}

__attribute__((used)) static inline void nvme_end_request(struct request *req, __le16 status,
		union nvme_result result)
{
	struct nvme_request *rq = nvme_req(req);

	rq->status = le16_to_cpu(status) >> 1;
	rq->result = result;
	/* inject error when permitted by fault injection framework */
	nvme_should_fail(req);
	blk_mq_complete_request(req);
}

__attribute__((used)) static inline void nvme_get_ctrl(struct nvme_ctrl *ctrl)
{
	get_device(ctrl->device);
}

__attribute__((used)) static inline void nvme_put_ctrl(struct nvme_ctrl *ctrl)
{
	put_device(ctrl->device);
}

__attribute__((used)) static inline bool nvme_ctrl_use_ana(struct nvme_ctrl *ctrl)
{
	return false;
}

__attribute__((used)) static inline void nvme_set_disk_name(char *disk_name, struct nvme_ns *ns,
				      struct nvme_ctrl *ctrl, int *flags)
{
	sprintf(disk_name, "nvme%dn%d", ctrl->instance, ns->head->instance);
}

__attribute__((used)) static inline void nvme_failover_req(struct request *req)
{
}

__attribute__((used)) static inline void nvme_kick_requeue_lists(struct nvme_ctrl *ctrl)
{
}

__attribute__((used)) static inline int nvme_mpath_alloc_disk(struct nvme_ctrl *ctrl,
		struct nvme_ns_head *head)
{
	return 0;
}

__attribute__((used)) static inline void nvme_mpath_add_disk(struct nvme_ns *ns,
		struct nvme_id_ns *id)
{
}

__attribute__((used)) static inline void nvme_mpath_remove_disk(struct nvme_ns_head *head)
{
}

__attribute__((used)) static inline void nvme_mpath_clear_current_path(struct nvme_ns *ns)
{
}

__attribute__((used)) static inline void nvme_mpath_check_last_path(struct nvme_ns *ns)
{
}

__attribute__((used)) static inline int nvme_mpath_init(struct nvme_ctrl *ctrl,
		struct nvme_id_ctrl *id)
{
	if (ctrl->subsys->cmic & (1 << 3))
		dev_warn(ctrl->device,
"Please enable CONFIG_NVME_MULTIPATH for full support of multi-port devices.\n");
	return 0;
}

__attribute__((used)) static inline void nvme_mpath_uninit(struct nvme_ctrl *ctrl)
{
}

__attribute__((used)) static inline void nvme_mpath_stop(struct nvme_ctrl *ctrl)
{
}

__attribute__((used)) static inline void nvme_nvm_update_nvm_info(struct nvme_ns *ns) {}

__attribute__((used)) static inline int nvme_nvm_register(struct nvme_ns *ns, char *disk_name,
				    int node)
{
	return 0;
}

__attribute__((used)) static inline void nvme_nvm_unregister(struct nvme_ns *ns) {}

__attribute__((used)) static inline int nvme_nvm_register_sysfs(struct nvme_ns *ns)
{
	return 0;
}

__attribute__((used)) static inline void nvme_nvm_unregister_sysfs(struct nvme_ns *ns) {}

__attribute__((used)) static inline int nvme_nvm_ioctl(struct nvme_ns *ns, unsigned int cmd,
							unsigned long arg)
{
	return -ENOTTY;
}

__attribute__((used)) static inline struct nvme_ns *nvme_get_ns_from_dev(struct device *dev)
{
	return dev_to_disk(dev)->private_data;
}

__attribute__((used)) static inline void __assign_disk_name(char *name, struct gendisk *disk)
{
	if (disk)
		memcpy(name, disk->disk_name, DISK_NAME_LEN);
	else
		memset(name, 0, DISK_NAME_LEN);
}

__attribute__((used)) static const char *nvme_trace_create_sq(struct trace_seq *p, u8 *cdw10)
{
	const char *ret = trace_seq_buffer_ptr(p);
	u16 sqid = get_unaligned_le16(cdw10);
	u16 qsize = get_unaligned_le16(cdw10 + 2);
	u16 sq_flags = get_unaligned_le16(cdw10 + 4);
	u16 cqid = get_unaligned_le16(cdw10 + 6);


	trace_seq_printf(p, "sqid=%u, qsize=%u, sq_flags=0x%x, cqid=%u",
			 sqid, qsize, sq_flags, cqid);
	trace_seq_putc(p, 0);

	return ret;
}

__attribute__((used)) static const char *nvme_trace_create_cq(struct trace_seq *p, u8 *cdw10)
{
	const char *ret = trace_seq_buffer_ptr(p);
	u16 cqid = get_unaligned_le16(cdw10);
	u16 qsize = get_unaligned_le16(cdw10 + 2);
	u16 cq_flags = get_unaligned_le16(cdw10 + 4);
	u16 irq_vector = get_unaligned_le16(cdw10 + 6);

	trace_seq_printf(p, "cqid=%u, qsize=%u, cq_flags=0x%x, irq_vector=%u",
			 cqid, qsize, cq_flags, irq_vector);
	trace_seq_putc(p, 0);

	return ret;
}

__attribute__((used)) static const char *nvme_trace_admin_identify(struct trace_seq *p, u8 *cdw10)
{
	const char *ret = trace_seq_buffer_ptr(p);
	u8 cns = cdw10[0];
	u16 ctrlid = get_unaligned_le16(cdw10 + 2);

	trace_seq_printf(p, "cns=%u, ctrlid=%u", cns, ctrlid);
	trace_seq_putc(p, 0);

	return ret;
}

__attribute__((used)) static const char *nvme_trace_read_write(struct trace_seq *p, u8 *cdw10)
{
	const char *ret = trace_seq_buffer_ptr(p);
	u64 slba = get_unaligned_le64(cdw10);
	u16 length = get_unaligned_le16(cdw10 + 8);
	u16 control = get_unaligned_le16(cdw10 + 10);
	u32 dsmgmt = get_unaligned_le32(cdw10 + 12);
	u32 reftag = get_unaligned_le32(cdw10 +  16);

	trace_seq_printf(p,
			 "slba=%llu, len=%u, ctrl=0x%x, dsmgmt=%u, reftag=%u",
			 slba, length, control, dsmgmt, reftag);
	trace_seq_putc(p, 0);

	return ret;
}

__attribute__((used)) static const char *nvme_trace_dsm(struct trace_seq *p, u8 *cdw10)
{
	const char *ret = trace_seq_buffer_ptr(p);

	trace_seq_printf(p, "nr=%u, attributes=%u",
			 get_unaligned_le32(cdw10),
			 get_unaligned_le32(cdw10 + 4));
	trace_seq_putc(p, 0);

	return ret;
}

__attribute__((used)) static const char *nvme_trace_common(struct trace_seq *p, u8 *cdw10)
{
	const char *ret = trace_seq_buffer_ptr(p);

	trace_seq_printf(p, "cdw10=%*ph", 24, cdw10);
	trace_seq_putc(p, 0);

	return ret;
}

const char *nvme_trace_parse_admin_cmd(struct trace_seq *p,
				       u8 opcode, u8 *cdw10)
{
	switch (opcode) {
	case nvme_admin_create_sq:
		return nvme_trace_create_sq(p, cdw10);
	case nvme_admin_create_cq:
		return nvme_trace_create_cq(p, cdw10);
	case nvme_admin_identify:
		return nvme_trace_admin_identify(p, cdw10);
	default:
		return nvme_trace_common(p, cdw10);
	}
}

const char *nvme_trace_parse_nvm_cmd(struct trace_seq *p,
				     u8 opcode, u8 *cdw10)
{
	switch (opcode) {
	case nvme_cmd_read:
	case nvme_cmd_write:
	case nvme_cmd_write_zeroes:
		return nvme_trace_read_write(p, cdw10);
	case nvme_cmd_dsm:
		return nvme_trace_dsm(p, cdw10);
	default:
		return nvme_trace_common(p, cdw10);
	}
}

const char *nvme_trace_disk_name(struct trace_seq *p, char *name)
{
	const char *ret = trace_seq_buffer_ptr(p);

	if (*name)
		trace_seq_printf(p, "disk=%s, ", name);
	trace_seq_putc(p, 0);

	return ret;
}

