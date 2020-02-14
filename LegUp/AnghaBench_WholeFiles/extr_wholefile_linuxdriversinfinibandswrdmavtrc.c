#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct rvt_rwq {scalar_t__ head; scalar_t__ tail; } ;
struct TYPE_5__ {int /*<<< orphan*/  device; scalar_t__ srq; } ;
struct TYPE_4__ {scalar_t__ size; struct rvt_rwq* wq; } ;
struct rvt_qp {scalar_t__ r_msn; int s_flags; scalar_t__ s_lsn; int /*<<< orphan*/  s_lock; TYPE_2__ ibqp; TYPE_1__ r_rq; } ;
struct TYPE_6__ {int /*<<< orphan*/  (* schedule_send ) (struct rvt_qp*) ;} ;
struct rvt_dev_info {TYPE_3__ driver_f; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 scalar_t__ IB_AETH_CREDIT_INVAL ; 
 scalar_t__ IB_AETH_CREDIT_MASK ; 
 scalar_t__ IB_AETH_CREDIT_SHIFT ; 
 scalar_t__ IB_MSN_MASK ; 
 int RVT_S_UNLIMITED_CREDIT ; 
 int RVT_S_WAIT_SSN_CREDIT ; 
 int /*<<< orphan*/  cpu_to_be32 (scalar_t__) ; 
 scalar_t__* credit_table ; 
 struct rvt_dev_info* ib_to_rvt (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 
 scalar_t__ rvt_cmp_msn (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  stub1 (struct rvt_qp*) ; 
 int /*<<< orphan*/  stub2 (struct rvt_qp*) ; 

__be32 rvt_compute_aeth(struct rvt_qp *qp)
{
	u32 aeth = qp->r_msn & IB_MSN_MASK;

	if (qp->ibqp.srq) {
		/*
		 * Shared receive queues don't generate credits.
		 * Set the credit field to the invalid value.
		 */
		aeth |= IB_AETH_CREDIT_INVAL << IB_AETH_CREDIT_SHIFT;
	} else {
		u32 min, max, x;
		u32 credits;
		struct rvt_rwq *wq = qp->r_rq.wq;
		u32 head;
		u32 tail;

		/* sanity check pointers before trusting them */
		head = wq->head;
		if (head >= qp->r_rq.size)
			head = 0;
		tail = wq->tail;
		if (tail >= qp->r_rq.size)
			tail = 0;
		/*
		 * Compute the number of credits available (RWQEs).
		 * There is a small chance that the pair of reads are
		 * not atomic, which is OK, since the fuzziness is
		 * resolved as further ACKs go out.
		 */
		credits = head - tail;
		if ((int)credits < 0)
			credits += qp->r_rq.size;
		/*
		 * Binary search the credit table to find the code to
		 * use.
		 */
		min = 0;
		max = 31;
		for (;;) {
			x = (min + max) / 2;
			if (credit_table[x] == credits)
				break;
			if (credit_table[x] > credits) {
				max = x;
			} else {
				if (min == x)
					break;
				min = x;
			}
		}
		aeth |= x << IB_AETH_CREDIT_SHIFT;
	}
	return cpu_to_be32(aeth);
}

void rvt_get_credit(struct rvt_qp *qp, u32 aeth)
{
	struct rvt_dev_info *rdi = ib_to_rvt(qp->ibqp.device);
	u32 credit = (aeth >> IB_AETH_CREDIT_SHIFT) & IB_AETH_CREDIT_MASK;

	lockdep_assert_held(&qp->s_lock);
	/*
	 * If the credit is invalid, we can send
	 * as many packets as we like.  Otherwise, we have to
	 * honor the credit field.
	 */
	if (credit == IB_AETH_CREDIT_INVAL) {
		if (!(qp->s_flags & RVT_S_UNLIMITED_CREDIT)) {
			qp->s_flags |= RVT_S_UNLIMITED_CREDIT;
			if (qp->s_flags & RVT_S_WAIT_SSN_CREDIT) {
				qp->s_flags &= ~RVT_S_WAIT_SSN_CREDIT;
				rdi->driver_f.schedule_send(qp);
			}
		}
	} else if (!(qp->s_flags & RVT_S_UNLIMITED_CREDIT)) {
		/* Compute new LSN (i.e., MSN + credit) */
		credit = (aeth + credit_table[credit]) & IB_MSN_MASK;
		if (rvt_cmp_msn(credit, qp->s_lsn) > 0) {
			qp->s_lsn = credit;
			if (qp->s_flags & RVT_S_WAIT_SSN_CREDIT) {
				qp->s_flags &= ~RVT_S_WAIT_SSN_CREDIT;
				rdi->driver_f.schedule_send(qp);
			}
		}
	}
}

