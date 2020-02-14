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
typedef  int u32 ;
struct TYPE_9__ {int flushed; } ;
struct TYPE_6__ {int condition; int send_phantom; int single; int flushed; } ;
struct bnxt_qplib_qp {TYPE_4__ rq; int /*<<< orphan*/  rq_flush; int /*<<< orphan*/  srq; TYPE_1__ sq; int /*<<< orphan*/  sq_flush; struct bnxt_qplib_cq* rcq; struct bnxt_qplib_cq* scq; } ;
struct TYPE_10__ {scalar_t__ cons; scalar_t__ prod; } ;
struct bnxt_qplib_q {TYPE_5__ hwq; scalar_t__ q_full_delta; } ;
struct TYPE_8__ {TYPE_2__* pdev; } ;
struct bnxt_qplib_cq {int /*<<< orphan*/  rqf_head; TYPE_3__ hwq; int /*<<< orphan*/  sqf_head; } ;
struct TYPE_7__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int BNXT_QPLIB_CMDQE_CNT_PER_PG ; 
 int BNXT_QPLIB_CREQE_CNT_PER_PG ; 
 scalar_t__ HWQ_CMP (scalar_t__,TYPE_5__*) ; 
 int MAX_CMDQ_IDX_PER_PG ; 
 int MAX_CREQ_IDX_PER_PG ; 
 int PSNE_CNT_PER_PG ; 
 int PSNE_MAX_IDX_PER_PG ; 
 int SQE_CNT_PER_PG ; 
 int SQE_MAX_IDX_PER_PG ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,struct bnxt_qplib_qp*) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

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

__attribute__((used)) static void bnxt_qplib_cancel_phantom_processing(struct bnxt_qplib_qp *qp)
{
	qp->sq.condition = false;
	qp->sq.send_phantom = false;
	qp->sq.single = false;
}

__attribute__((used)) static void __bnxt_qplib_add_flush_qp(struct bnxt_qplib_qp *qp)
{
	struct bnxt_qplib_cq *scq, *rcq;

	scq = qp->scq;
	rcq = qp->rcq;

	if (!qp->sq.flushed) {
		dev_dbg(&scq->hwq.pdev->dev,
			"QPLIB: FP: Adding to SQ Flush list = %p",
			qp);
		bnxt_qplib_cancel_phantom_processing(qp);
		list_add_tail(&qp->sq_flush, &scq->sqf_head);
		qp->sq.flushed = true;
	}
	if (!qp->srq) {
		if (!qp->rq.flushed) {
			dev_dbg(&rcq->hwq.pdev->dev,
				"QPLIB: FP: Adding to RQ Flush list = %p",
				qp);
			list_add_tail(&qp->rq_flush, &rcq->rqf_head);
			qp->rq.flushed = true;
		}
	}
}

