#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct rdma_hw_stats {void** value; } ;
struct ib_device {int dummy; } ;
struct device {int dummy; } ;
struct ctx_hw_stats {int /*<<< orphan*/  tx_ucast_bytes; int /*<<< orphan*/  tx_ucast_pkts; int /*<<< orphan*/  rx_ucast_bytes; int /*<<< orphan*/  rx_ucast_pkts; int /*<<< orphan*/  tx_bcast_pkts; } ;
struct TYPE_9__ {void* res_rx_pci_err; void* res_tx_pci_err; void* res_srq_load_err; void* res_cq_load_err; void* res_wqe_format_err; void* res_invalid_dup_rkey; void* res_cmp_err; void* res_srq_err; void* res_mem_error; void* res_rem_inv_err; void* res_unaligned_atomic; void* res_unsup_opcode; void* res_irrq_oflow; void* res_tx_range_err; void* res_tx_no_perm; void* res_tx_domain_err; void* res_tx_invalid_rkey; void* res_rx_range_err; void* res_rx_no_perm; void* res_rx_domain_err; void* res_rx_invalid_rkey; void* res_opcode_err; void* res_exceeds_wqe; void* res_length_mismatch; void* res_exceed_max; void* dup_req; void* remote_op_err; void* remote_access_err; void* remote_invalid_req_err; void* mem_mgmt_op_err; void* local_protection_err; void* local_qp_op_err; void* bad_resp_err; void* unrecoverable_err; void* missing_resp; void* rnr_naks_rcvd; void* max_retry_exceeded; void* seq_err_naks_rcvd; void* to_retransmits; } ;
struct TYPE_7__ {struct ctx_hw_stats* dma; } ;
struct TYPE_8__ {TYPE_2__ stats; } ;
struct TYPE_6__ {struct device dev; } ;
struct bnxt_re_dev {TYPE_4__ stats; int /*<<< orphan*/  flags; int /*<<< orphan*/  rcfw; int /*<<< orphan*/  mw_count; int /*<<< orphan*/  mr_count; int /*<<< orphan*/  cq_count; int /*<<< orphan*/  srq_count; int /*<<< orphan*/  qp_count; TYPE_3__ qplib_ctx; TYPE_1__ ibdev; } ;
struct TYPE_10__ {scalar_t__ cons; scalar_t__ prod; } ;
struct bnxt_qplib_q {TYPE_5__ hwq; scalar_t__ q_full_delta; } ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int BNXT_QPLIB_CMDQE_CNT_PER_PG ; 
 int BNXT_QPLIB_CREQE_CNT_PER_PG ; 
 size_t BNXT_RE_ACTIVE_CQ ; 
 size_t BNXT_RE_ACTIVE_MR ; 
 size_t BNXT_RE_ACTIVE_MW ; 
 size_t BNXT_RE_ACTIVE_QP ; 
 size_t BNXT_RE_ACTIVE_SRQ ; 
 size_t BNXT_RE_BAD_RESP_ERR ; 
 size_t BNXT_RE_DUP_REQ ; 
 int /*<<< orphan*/  BNXT_RE_FLAG_ISSUE_ROCE_STATS ; 
 size_t BNXT_RE_LOCAL_PROTECTION_ERR ; 
 size_t BNXT_RE_LOCAL_QP_OP_ERR ; 
 size_t BNXT_RE_MAX_RETRY_EXCEEDED ; 
 size_t BNXT_RE_MEM_MGMT_OP_ERR ; 
 size_t BNXT_RE_MISSING_RESP ; 
 scalar_t__ BNXT_RE_NUM_COUNTERS ; 
 size_t BNXT_RE_RECOVERABLE_ERRORS ; 
 size_t BNXT_RE_REMOTE_ACCESS_ERR ; 
 size_t BNXT_RE_REMOTE_INVALID_REQ_ERR ; 
 size_t BNXT_RE_REMOTE_OP_ERR ; 
 size_t BNXT_RE_RES_CMP_ERR ; 
 size_t BNXT_RE_RES_CQ_LOAD_ERR ; 
 size_t BNXT_RE_RES_EXCEEDS_WQE ; 
 size_t BNXT_RE_RES_EXCEED_MAX ; 
 size_t BNXT_RE_RES_INVALID_DUP_RKEY ; 
 size_t BNXT_RE_RES_IRRQ_OFLOW ; 
 size_t BNXT_RE_RES_LENGTH_MISMATCH ; 
 size_t BNXT_RE_RES_MEM_ERROR ; 
 size_t BNXT_RE_RES_OPCODE_ERR ; 
 size_t BNXT_RE_RES_REM_INV_ERR ; 
 size_t BNXT_RE_RES_RX_DOMAIN_ERR ; 
 size_t BNXT_RE_RES_RX_INVALID_RKEY ; 
 size_t BNXT_RE_RES_RX_NO_PERM ; 
 size_t BNXT_RE_RES_RX_PCI_ERR ; 
 size_t BNXT_RE_RES_RX_RANGE_ERR ; 
 size_t BNXT_RE_RES_SRQ_ERR ; 
 size_t BNXT_RE_RES_SRQ_LOAD_ERR ; 
 size_t BNXT_RE_RES_TX_DOMAIN_ERR ; 
 size_t BNXT_RE_RES_TX_INVALID_RKEY ; 
 size_t BNXT_RE_RES_TX_NO_PERM ; 
 size_t BNXT_RE_RES_TX_PCI_ERR ; 
 size_t BNXT_RE_RES_TX_RANGE_ERR ; 
 size_t BNXT_RE_RES_UNALIGNED_ATOMIC ; 
 size_t BNXT_RE_RES_UNSUP_OPCODE ; 
 size_t BNXT_RE_RES_WQE_FORMAT_ERR ; 
 size_t BNXT_RE_RNR_NAKS_RCVD ; 
 size_t BNXT_RE_RX_BYTES ; 
 size_t BNXT_RE_RX_PKTS ; 
 size_t BNXT_RE_SEQ_ERR_NAKS_RCVD ; 
 size_t BNXT_RE_TO_RETRANSMITS ; 
 size_t BNXT_RE_TX_BYTES ; 
 size_t BNXT_RE_TX_PKTS ; 
 size_t BNXT_RE_UNRECOVERABLE_ERR ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int EINVAL ; 
 scalar_t__ HWQ_CMP (scalar_t__,TYPE_5__*) ; 
 int MAX_CMDQ_IDX_PER_PG ; 
 int MAX_CREQ_IDX_PER_PG ; 
 int PSNE_CNT_PER_PG ; 
 int PSNE_MAX_IDX_PER_PG ; 
 int /*<<< orphan*/  RDMA_HW_STATS_DEFAULT_LIFESPAN ; 
 int SQE_CNT_PER_PG ; 
 int SQE_MAX_IDX_PER_PG ; 
 void* atomic_read (int /*<<< orphan*/ *) ; 
 int bnxt_qplib_get_roce_stats (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  bnxt_re_stat_name ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 void* le64_to_cpu (int /*<<< orphan*/ ) ; 
 struct rdma_hw_stats* rdma_alloc_hw_stats_struct (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct bnxt_re_dev* to_bnxt_re_dev (struct ib_device*,struct ib_device*) ; 

__attribute__((used)) static inline u32 get_sqe_pg(u32 val)
{
	return ((val & ~SQE_MAX_IDX_PER_PG) / SQE_CNT_PER_PG);
}

__attribute__((used)) static inline u32 get_sqe_idx(u32 val)
{
	return (val & SQE_MAX_IDX_PER_PG);
}

__attribute__((used)) static inline u32 get_psne_pg(u32 val)
{
	return ((val & ~PSNE_MAX_IDX_PER_PG) / PSNE_CNT_PER_PG);
}

__attribute__((used)) static inline u32 get_psne_idx(u32 val)
{
	return (val & PSNE_MAX_IDX_PER_PG);
}

__attribute__((used)) static inline bool bnxt_qplib_queue_full(struct bnxt_qplib_q *qplib_q)
{
	return HWQ_CMP((qplib_q->hwq.prod + qplib_q->q_full_delta),
		       &qplib_q->hwq) == HWQ_CMP(qplib_q->hwq.cons,
						 &qplib_q->hwq);
}

__attribute__((used)) static inline u32 get_cmdq_pg(u32 val)
{
	return (val & ~MAX_CMDQ_IDX_PER_PG) / BNXT_QPLIB_CMDQE_CNT_PER_PG;
}

__attribute__((used)) static inline u32 get_cmdq_idx(u32 val)
{
	return val & MAX_CMDQ_IDX_PER_PG;
}

__attribute__((used)) static inline u32 get_creq_pg(u32 val)
{
	return (val & ~MAX_CREQ_IDX_PER_PG) / BNXT_QPLIB_CREQE_CNT_PER_PG;
}

__attribute__((used)) static inline u32 get_creq_idx(u32 val)
{
	return val & MAX_CREQ_IDX_PER_PG;
}

__attribute__((used)) static inline struct device *rdev_to_dev(struct bnxt_re_dev *rdev)
{
	if (rdev)
		return  &rdev->ibdev.dev;
	return NULL;
}

int bnxt_re_ib_get_hw_stats(struct ib_device *ibdev,
			    struct rdma_hw_stats *stats,
			    u8 port, int index)
{
	struct bnxt_re_dev *rdev = to_bnxt_re_dev(ibdev, ibdev);
	struct ctx_hw_stats *bnxt_re_stats = rdev->qplib_ctx.stats.dma;
	int rc  = 0;

	if (!port || !stats)
		return -EINVAL;

	stats->value[BNXT_RE_ACTIVE_QP] = atomic_read(&rdev->qp_count);
	stats->value[BNXT_RE_ACTIVE_SRQ] = atomic_read(&rdev->srq_count);
	stats->value[BNXT_RE_ACTIVE_CQ] = atomic_read(&rdev->cq_count);
	stats->value[BNXT_RE_ACTIVE_MR] = atomic_read(&rdev->mr_count);
	stats->value[BNXT_RE_ACTIVE_MW] = atomic_read(&rdev->mw_count);
	if (bnxt_re_stats) {
		stats->value[BNXT_RE_RECOVERABLE_ERRORS] =
			le64_to_cpu(bnxt_re_stats->tx_bcast_pkts);
		stats->value[BNXT_RE_RX_PKTS] =
			le64_to_cpu(bnxt_re_stats->rx_ucast_pkts);
		stats->value[BNXT_RE_RX_BYTES] =
			le64_to_cpu(bnxt_re_stats->rx_ucast_bytes);
		stats->value[BNXT_RE_TX_PKTS] =
			le64_to_cpu(bnxt_re_stats->tx_ucast_pkts);
		stats->value[BNXT_RE_TX_BYTES] =
			le64_to_cpu(bnxt_re_stats->tx_ucast_bytes);
	}
	if (test_bit(BNXT_RE_FLAG_ISSUE_ROCE_STATS, &rdev->flags)) {
		rc = bnxt_qplib_get_roce_stats(&rdev->rcfw, &rdev->stats);
		if (rc)
			clear_bit(BNXT_RE_FLAG_ISSUE_ROCE_STATS,
				  &rdev->flags);
		stats->value[BNXT_RE_TO_RETRANSMITS] =
					rdev->stats.to_retransmits;
		stats->value[BNXT_RE_SEQ_ERR_NAKS_RCVD] =
					rdev->stats.seq_err_naks_rcvd;
		stats->value[BNXT_RE_MAX_RETRY_EXCEEDED] =
					rdev->stats.max_retry_exceeded;
		stats->value[BNXT_RE_RNR_NAKS_RCVD] =
					rdev->stats.rnr_naks_rcvd;
		stats->value[BNXT_RE_MISSING_RESP] =
					rdev->stats.missing_resp;
		stats->value[BNXT_RE_UNRECOVERABLE_ERR] =
					rdev->stats.unrecoverable_err;
		stats->value[BNXT_RE_BAD_RESP_ERR] =
					rdev->stats.bad_resp_err;
		stats->value[BNXT_RE_LOCAL_QP_OP_ERR]	=
				rdev->stats.local_qp_op_err;
		stats->value[BNXT_RE_LOCAL_PROTECTION_ERR] =
				rdev->stats.local_protection_err;
		stats->value[BNXT_RE_MEM_MGMT_OP_ERR] =
				rdev->stats.mem_mgmt_op_err;
		stats->value[BNXT_RE_REMOTE_INVALID_REQ_ERR] =
				rdev->stats.remote_invalid_req_err;
		stats->value[BNXT_RE_REMOTE_ACCESS_ERR] =
				rdev->stats.remote_access_err;
		stats->value[BNXT_RE_REMOTE_OP_ERR] =
				rdev->stats.remote_op_err;
		stats->value[BNXT_RE_DUP_REQ] =
				rdev->stats.dup_req;
		stats->value[BNXT_RE_RES_EXCEED_MAX] =
				rdev->stats.res_exceed_max;
		stats->value[BNXT_RE_RES_LENGTH_MISMATCH] =
				rdev->stats.res_length_mismatch;
		stats->value[BNXT_RE_RES_EXCEEDS_WQE] =
				rdev->stats.res_exceeds_wqe;
		stats->value[BNXT_RE_RES_OPCODE_ERR] =
				rdev->stats.res_opcode_err;
		stats->value[BNXT_RE_RES_RX_INVALID_RKEY] =
				rdev->stats.res_rx_invalid_rkey;
		stats->value[BNXT_RE_RES_RX_DOMAIN_ERR] =
				rdev->stats.res_rx_domain_err;
		stats->value[BNXT_RE_RES_RX_NO_PERM] =
				rdev->stats.res_rx_no_perm;
		stats->value[BNXT_RE_RES_RX_RANGE_ERR]  =
				rdev->stats.res_rx_range_err;
		stats->value[BNXT_RE_RES_TX_INVALID_RKEY] =
				rdev->stats.res_tx_invalid_rkey;
		stats->value[BNXT_RE_RES_TX_DOMAIN_ERR] =
				rdev->stats.res_tx_domain_err;
		stats->value[BNXT_RE_RES_TX_NO_PERM] =
				rdev->stats.res_tx_no_perm;
		stats->value[BNXT_RE_RES_TX_RANGE_ERR]  =
				rdev->stats.res_tx_range_err;
		stats->value[BNXT_RE_RES_IRRQ_OFLOW] =
				rdev->stats.res_irrq_oflow;
		stats->value[BNXT_RE_RES_UNSUP_OPCODE]  =
				rdev->stats.res_unsup_opcode;
		stats->value[BNXT_RE_RES_UNALIGNED_ATOMIC] =
				rdev->stats.res_unaligned_atomic;
		stats->value[BNXT_RE_RES_REM_INV_ERR]   =
				rdev->stats.res_rem_inv_err;
		stats->value[BNXT_RE_RES_MEM_ERROR] =
				rdev->stats.res_mem_error;
		stats->value[BNXT_RE_RES_SRQ_ERR] =
				rdev->stats.res_srq_err;
		stats->value[BNXT_RE_RES_CMP_ERR] =
				rdev->stats.res_cmp_err;
		stats->value[BNXT_RE_RES_INVALID_DUP_RKEY] =
				rdev->stats.res_invalid_dup_rkey;
		stats->value[BNXT_RE_RES_WQE_FORMAT_ERR] =
				rdev->stats.res_wqe_format_err;
		stats->value[BNXT_RE_RES_CQ_LOAD_ERR]   =
				rdev->stats.res_cq_load_err;
		stats->value[BNXT_RE_RES_SRQ_LOAD_ERR]  =
				rdev->stats.res_srq_load_err;
		stats->value[BNXT_RE_RES_TX_PCI_ERR]    =
				rdev->stats.res_tx_pci_err;
		stats->value[BNXT_RE_RES_RX_PCI_ERR]    =
				rdev->stats.res_rx_pci_err;
	}

	return ARRAY_SIZE(bnxt_re_stat_name);
}

struct rdma_hw_stats *bnxt_re_ib_alloc_hw_stats(struct ib_device *ibdev,
						u8 port_num)
{
	BUILD_BUG_ON(ARRAY_SIZE(bnxt_re_stat_name) != BNXT_RE_NUM_COUNTERS);
	/* We support only per port stats */
	if (!port_num)
		return NULL;

	return rdma_alloc_hw_stats_struct(bnxt_re_stat_name,
					  ARRAY_SIZE(bnxt_re_stat_name),
					  RDMA_HW_STATS_DEFAULT_LIFESPAN);
}

