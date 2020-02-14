#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_9__ ;
typedef  struct TYPE_20__   TYPE_8__ ;
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_10__ ;

/* Type definitions */
typedef  int u64 ;
struct timer_list {int dummy; } ;
struct nodepda_s {struct bteinfo_s* bte_if; int /*<<< orphan*/  bte_recovery_lock; struct timer_list bte_recovery_timer; } ;
struct bteinfo_s {scalar_t__ bh_error; int cleanup_active; int* most_rcnt_na; int /*<<< orphan*/  bte_num; int /*<<< orphan*/  bte_cnode; int /*<<< orphan*/  bte_error_count; int /*<<< orphan*/  spinlock; } ;
typedef  int /*<<< orphan*/  spinlock_t ;
typedef  int /*<<< orphan*/  nasid_t ;
struct TYPE_17__ {scalar_t__ ie_errortype; } ;
typedef  TYPE_5__ ioerror_t ;
struct TYPE_14__ {int i_b0_esd; int i_b1_esd; } ;
struct TYPE_18__ {void* ii_imem_regval; TYPE_2__ ii_imem_fld_s; } ;
typedef  TYPE_6__ ii_imem_u_t ;
struct TYPE_15__ {int i_e_bte_0; int i_e_bte_1; } ;
struct TYPE_19__ {void* ii_ieclr_regval; TYPE_3__ ii_ieclr_fld_s; } ;
typedef  TYPE_7__ ii_ieclr_u_t ;
struct TYPE_20__ {scalar_t__ d_bteop; void* ii_icrb0_d_regval; } ;
typedef  TYPE_8__ ii_icrb0_d_u_t ;
struct TYPE_13__ {scalar_t__ i_crb_mark; int i_crb_vld; } ;
struct TYPE_21__ {TYPE_1__ ii_icmr_fld_s; void* ii_icmr_regval; } ;
typedef  TYPE_9__ ii_icmr_u_t ;
struct TYPE_16__ {int i_soft_reset; } ;
struct TYPE_12__ {void* ii_ibcr_regval; TYPE_4__ ii_ibcr_fld_s; } ;
typedef  TYPE_10__ ii_ibcr_u_t ;
typedef  int /*<<< orphan*/  cnodeid_t ;
typedef  scalar_t__ bte_result_t ;

/* Variables and functions */
 scalar_t__ BTEFAIL_OFFSET ; 
 int BTES_PER_NODE ; 
 int BTE_LNSTAT_LOAD (struct bteinfo_s*) ; 
 int /*<<< orphan*/  BTE_PRINTK (char*) ; 
 scalar_t__ BTE_SHUB2_ERROR (int) ; 
 scalar_t__ BTE_SUCCESS ; 
 int HZ ; 
 int IBLS_BUSY ; 
 int IBLS_ERROR ; 
 int /*<<< orphan*/  IIO_IBCR ; 
 int /*<<< orphan*/  IIO_ICMR ; 
 int /*<<< orphan*/  IIO_ICRB_D (int) ; 
 int /*<<< orphan*/  IIO_IECLR ; 
 int /*<<< orphan*/  IIO_IMEM ; 
 int IIO_NUM_CRBS ; 
 struct nodepda_s* NODEPDA (int /*<<< orphan*/ ) ; 
 void* REMOTE_HUB_L (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REMOTE_HUB_S (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  cnodeid_to_nasid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  del_timer (struct timer_list*) ; 
 scalar_t__ ia64_sn_bte_recovery (int /*<<< orphan*/ ) ; 
 scalar_t__ is_shub1 () ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (struct timer_list*,scalar_t__) ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int shub1_bte_error_handler(struct nodepda_s *err_nodepda)
{
	struct timer_list *recovery_timer = &err_nodepda->bte_recovery_timer;
	nasid_t nasid;
	int i;
	int valid_crbs;
	ii_imem_u_t imem;	/* II IMEM Register */
	ii_icrb0_d_u_t icrbd;	/* II CRB Register D */
	ii_ibcr_u_t ibcr;
	ii_icmr_u_t icmr;
	ii_ieclr_u_t ieclr;

	BTE_PRINTK(("shub1_bte_error_handler(%p) - %d\n", err_nodepda,
		    smp_processor_id()));

	if ((err_nodepda->bte_if[0].bh_error == BTE_SUCCESS) &&
	    (err_nodepda->bte_if[1].bh_error == BTE_SUCCESS)) {
		BTE_PRINTK(("eh:%p:%d Nothing to do.\n", err_nodepda,
			    smp_processor_id()));
		return 1;
	}

	/* Determine information about our hub */
	nasid = cnodeid_to_nasid(err_nodepda->bte_if[0].bte_cnode);

	/*
	 * A BTE transfer can use multiple CRBs.  We need to make sure
	 * that all the BTE CRBs are complete (or timed out) before
	 * attempting to clean up the error.  Resetting the BTE while
	 * there are still BTE CRBs active will hang the BTE.
	 * We should look at all the CRBs to see if they are allocated
	 * to the BTE and see if they are still active.  When none
	 * are active, we can continue with the cleanup.
	 *
	 * We also want to make sure that the local NI port is up.
	 * When a router resets the NI port can go down, while it
	 * goes through the LLP handshake, but then comes back up.
	 */
	icmr.ii_icmr_regval = REMOTE_HUB_L(nasid, IIO_ICMR);
	if (icmr.ii_icmr_fld_s.i_crb_mark != 0) {
		/*
		 * There are errors which still need to be cleaned up by
		 * hubiio_crb_error_handler
		 */
		mod_timer(recovery_timer, jiffies + (HZ * 5));
		BTE_PRINTK(("eh:%p:%d Marked Giving up\n", err_nodepda,
			    smp_processor_id()));
		return 1;
	}
	if (icmr.ii_icmr_fld_s.i_crb_vld != 0) {

		valid_crbs = icmr.ii_icmr_fld_s.i_crb_vld;

		for (i = 0; i < IIO_NUM_CRBS; i++) {
			if (!((1 << i) & valid_crbs)) {
				/* This crb was not marked as valid, ignore */
				continue;
			}
			icrbd.ii_icrb0_d_regval =
			    REMOTE_HUB_L(nasid, IIO_ICRB_D(i));
			if (icrbd.d_bteop) {
				mod_timer(recovery_timer, jiffies + (HZ * 5));
				BTE_PRINTK(("eh:%p:%d Valid %d, Giving up\n",
					    err_nodepda, smp_processor_id(),
					    i));
				return 1;
			}
		}
	}

	BTE_PRINTK(("eh:%p:%d Cleaning up\n", err_nodepda, smp_processor_id()));
	/* Re-enable both bte interfaces */
	imem.ii_imem_regval = REMOTE_HUB_L(nasid, IIO_IMEM);
	imem.ii_imem_fld_s.i_b0_esd = imem.ii_imem_fld_s.i_b1_esd = 1;
	REMOTE_HUB_S(nasid, IIO_IMEM, imem.ii_imem_regval);

	/* Clear BTE0/1 error bits */
	ieclr.ii_ieclr_regval = 0;
	if (err_nodepda->bte_if[0].bh_error != BTE_SUCCESS)
		ieclr.ii_ieclr_fld_s.i_e_bte_0 = 1;
	if (err_nodepda->bte_if[1].bh_error != BTE_SUCCESS)
		ieclr.ii_ieclr_fld_s.i_e_bte_1 = 1;
	REMOTE_HUB_S(nasid, IIO_IECLR, ieclr.ii_ieclr_regval);

	/* Reinitialize both BTE state machines. */
	ibcr.ii_ibcr_regval = REMOTE_HUB_L(nasid, IIO_IBCR);
	ibcr.ii_ibcr_fld_s.i_soft_reset = 1;
	REMOTE_HUB_S(nasid, IIO_IBCR, ibcr.ii_ibcr_regval);

	del_timer(recovery_timer);
	return 0;
}

__attribute__((used)) static int shub2_bte_error_handler(struct nodepda_s *err_nodepda)
{
	struct timer_list *recovery_timer = &err_nodepda->bte_recovery_timer;
	struct bteinfo_s *bte;
	nasid_t nasid;
	u64 status;
	int i;

	nasid = cnodeid_to_nasid(err_nodepda->bte_if[0].bte_cnode);

	/*
	 * Verify that all the BTEs are complete
	 */
	for (i = 0; i < BTES_PER_NODE; i++) {
		bte = &err_nodepda->bte_if[i];
		status = BTE_LNSTAT_LOAD(bte);
		if (status & IBLS_ERROR) {
			bte->bh_error = BTE_SHUB2_ERROR(status);
			continue;
		}
		if (!(status & IBLS_BUSY))
			continue;
		mod_timer(recovery_timer, jiffies + (HZ * 5));
		BTE_PRINTK(("eh:%p:%d Marked Giving up\n", err_nodepda,
			    smp_processor_id()));
		return 1;
	}
	if (ia64_sn_bte_recovery(nasid))
		panic("bte_error_handler(): Fatal BTE Error");

	del_timer(recovery_timer);
	return 0;
}

void bte_error_handler(struct nodepda_s *err_nodepda)
{
	spinlock_t *recovery_lock = &err_nodepda->bte_recovery_lock;
	int i;
	unsigned long irq_flags;
	volatile u64 *notify;
	bte_result_t bh_error;

	BTE_PRINTK(("bte_error_handler(%p) - %d\n", err_nodepda,
		    smp_processor_id()));

	spin_lock_irqsave(recovery_lock, irq_flags);

	/*
	 * Lock all interfaces on this node to prevent new transfers
	 * from being queued.
	 */
	for (i = 0; i < BTES_PER_NODE; i++) {
		if (err_nodepda->bte_if[i].cleanup_active) {
			continue;
		}
		spin_lock(&err_nodepda->bte_if[i].spinlock);
		BTE_PRINTK(("eh:%p:%d locked %d\n", err_nodepda,
			    smp_processor_id(), i));
		err_nodepda->bte_if[i].cleanup_active = 1;
	}

	if (is_shub1()) {
		if (shub1_bte_error_handler(err_nodepda)) {
			spin_unlock_irqrestore(recovery_lock, irq_flags);
			return;
		}
	} else {
		if (shub2_bte_error_handler(err_nodepda)) {
			spin_unlock_irqrestore(recovery_lock, irq_flags);
			return;
		}
	}

	for (i = 0; i < BTES_PER_NODE; i++) {
		bh_error = err_nodepda->bte_if[i].bh_error;
		if (bh_error != BTE_SUCCESS) {
			/* There is an error which needs to be notified */
			notify = err_nodepda->bte_if[i].most_rcnt_na;
			BTE_PRINTK(("cnode %d bte %d error=0x%lx\n",
				    err_nodepda->bte_if[i].bte_cnode,
				    err_nodepda->bte_if[i].bte_num,
				    IBLS_ERROR | (u64) bh_error));
			*notify = IBLS_ERROR | bh_error;
			err_nodepda->bte_if[i].bh_error = BTE_SUCCESS;
		}

		err_nodepda->bte_if[i].cleanup_active = 0;
		BTE_PRINTK(("eh:%p:%d Unlocked %d\n", err_nodepda,
			    smp_processor_id(), i));
		spin_unlock(&err_nodepda->bte_if[i].spinlock);
	}

	spin_unlock_irqrestore(recovery_lock, irq_flags);
}

void
bte_crb_error_handler(cnodeid_t cnode, int btenum,
                      int crbnum, ioerror_t * ioe, int bteop)
{
	struct bteinfo_s *bte;


	bte = &(NODEPDA(cnode)->bte_if[btenum]);

	/*
	 * The caller has already figured out the error type, we save that
	 * in the bte handle structure for the thread exercising the
	 * interface to consume.
	 */
	bte->bh_error = ioe->ie_errortype + BTEFAIL_OFFSET;
	bte->bte_error_count++;

	BTE_PRINTK(("Got an error on cnode %d bte %d: HW error type 0x%x\n",
		bte->bte_cnode, bte->bte_num, ioe->ie_errortype));
	bte_error_handler(NODEPDA(cnode));
}

