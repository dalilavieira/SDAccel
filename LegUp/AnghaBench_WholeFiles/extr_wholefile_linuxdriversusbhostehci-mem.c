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
typedef  int /*<<< orphan*/  u32 ;
struct ehci_sitd {int dummy; } ;
struct ehci_qtd {void* hw_alt_next; void* hw_qtd_next; void* hw_next; void* qtd_dma; int /*<<< orphan*/  qtd_list; void* hw_token; } ;
struct ehci_qh_hw {void* hw_alt_next; void* hw_qtd_next; void* hw_next; void* qtd_dma; int /*<<< orphan*/  qtd_list; void* hw_token; } ;
struct TYPE_4__ {scalar_t__ ptr; } ;
struct ehci_qh {void* qh_dma; struct ehci_qtd* hw; struct ehci_qtd* dummy; int /*<<< orphan*/  unlink_node; int /*<<< orphan*/  qtd_list; TYPE_1__ qh_next; } ;
struct ehci_itd {int dummy; } ;
struct ehci_hcd {int periodic_size; struct ehci_qh* pshadow; void** periodic; struct ehci_qh* dummy; scalar_t__ use_dummy_qh; int /*<<< orphan*/  periodic_dma; int /*<<< orphan*/ * sitd_pool; int /*<<< orphan*/ * itd_pool; struct ehci_qh* async; int /*<<< orphan*/ * qh_pool; int /*<<< orphan*/ * qtd_pool; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  void* dma_addr_t ;
typedef  void* __le32 ;
struct TYPE_5__ {int /*<<< orphan*/  sysdev; } ;
struct TYPE_6__ {TYPE_2__ self; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 void* EHCI_LIST_END (struct ehci_hcd*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 void* QTD_STS_HALT ; 
 void* cpu_to_hc32 (struct ehci_hcd*,void*) ; 
 scalar_t__ dma_alloc_coherent (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ ,int,void**,int /*<<< orphan*/ ) ; 
 struct ehci_qtd* dma_pool_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void**) ; 
 void* dma_pool_create (char*,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  dma_pool_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dma_pool_free (int /*<<< orphan*/ *,struct ehci_qtd*,void*) ; 
 int /*<<< orphan*/  ehci_dbg (struct ehci_hcd*,char*) ; 
 TYPE_3__* ehci_to_hcd (struct ehci_hcd*) ; 
 struct ehci_qh* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct ehci_qh*) ; 
 struct ehci_qh* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (struct ehci_qtd*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void ehci_qtd_init(struct ehci_hcd *ehci, struct ehci_qtd *qtd,
				  dma_addr_t dma)
{
	memset (qtd, 0, sizeof *qtd);
	qtd->qtd_dma = dma;
	qtd->hw_token = cpu_to_hc32(ehci, QTD_STS_HALT);
	qtd->hw_next = EHCI_LIST_END(ehci);
	qtd->hw_alt_next = EHCI_LIST_END(ehci);
	INIT_LIST_HEAD (&qtd->qtd_list);
}

__attribute__((used)) static struct ehci_qtd *ehci_qtd_alloc (struct ehci_hcd *ehci, gfp_t flags)
{
	struct ehci_qtd		*qtd;
	dma_addr_t		dma;

	qtd = dma_pool_alloc (ehci->qtd_pool, flags, &dma);
	if (qtd != NULL) {
		ehci_qtd_init(ehci, qtd, dma);
	}
	return qtd;
}

__attribute__((used)) static inline void ehci_qtd_free (struct ehci_hcd *ehci, struct ehci_qtd *qtd)
{
	dma_pool_free (ehci->qtd_pool, qtd, qtd->qtd_dma);
}

__attribute__((used)) static void qh_destroy(struct ehci_hcd *ehci, struct ehci_qh *qh)
{
	/* clean qtds first, and know this is not linked */
	if (!list_empty (&qh->qtd_list) || qh->qh_next.ptr) {
		ehci_dbg (ehci, "unused qh not empty!\n");
		BUG ();
	}
	if (qh->dummy)
		ehci_qtd_free (ehci, qh->dummy);
	dma_pool_free(ehci->qh_pool, qh->hw, qh->qh_dma);
	kfree(qh);
}

__attribute__((used)) static struct ehci_qh *ehci_qh_alloc (struct ehci_hcd *ehci, gfp_t flags)
{
	struct ehci_qh		*qh;
	dma_addr_t		dma;

	qh = kzalloc(sizeof *qh, GFP_ATOMIC);
	if (!qh)
		goto done;
	qh->hw = (struct ehci_qh_hw *)
		dma_pool_alloc(ehci->qh_pool, flags, &dma);
	if (!qh->hw)
		goto fail;
	memset(qh->hw, 0, sizeof *qh->hw);
	qh->qh_dma = dma;
	// INIT_LIST_HEAD (&qh->qh_list);
	INIT_LIST_HEAD (&qh->qtd_list);
	INIT_LIST_HEAD(&qh->unlink_node);

	/* dummy td enables safe urb queuing */
	qh->dummy = ehci_qtd_alloc (ehci, flags);
	if (qh->dummy == NULL) {
		ehci_dbg (ehci, "no dummy td\n");
		goto fail1;
	}
done:
	return qh;
fail1:
	dma_pool_free(ehci->qh_pool, qh->hw, qh->qh_dma);
fail:
	kfree(qh);
	return NULL;
}

__attribute__((used)) static void ehci_mem_cleanup (struct ehci_hcd *ehci)
{
	if (ehci->async)
		qh_destroy(ehci, ehci->async);
	ehci->async = NULL;

	if (ehci->dummy)
		qh_destroy(ehci, ehci->dummy);
	ehci->dummy = NULL;

	/* DMA consistent memory and pools */
	dma_pool_destroy(ehci->qtd_pool);
	ehci->qtd_pool = NULL;
	dma_pool_destroy(ehci->qh_pool);
	ehci->qh_pool = NULL;
	dma_pool_destroy(ehci->itd_pool);
	ehci->itd_pool = NULL;
	dma_pool_destroy(ehci->sitd_pool);
	ehci->sitd_pool = NULL;

	if (ehci->periodic)
		dma_free_coherent(ehci_to_hcd(ehci)->self.sysdev,
			ehci->periodic_size * sizeof (u32),
			ehci->periodic, ehci->periodic_dma);
	ehci->periodic = NULL;

	/* shadow periodic table */
	kfree(ehci->pshadow);
	ehci->pshadow = NULL;
}

__attribute__((used)) static int ehci_mem_init (struct ehci_hcd *ehci, gfp_t flags)
{
	int i;

	/* QTDs for control/bulk/intr transfers */
	ehci->qtd_pool = dma_pool_create ("ehci_qtd",
			ehci_to_hcd(ehci)->self.sysdev,
			sizeof (struct ehci_qtd),
			32 /* byte alignment (for hw parts) */,
			4096 /* can't cross 4K */);
	if (!ehci->qtd_pool) {
		goto fail;
	}

	/* QHs for control/bulk/intr transfers */
	ehci->qh_pool = dma_pool_create ("ehci_qh",
			ehci_to_hcd(ehci)->self.sysdev,
			sizeof(struct ehci_qh_hw),
			32 /* byte alignment (for hw parts) */,
			4096 /* can't cross 4K */);
	if (!ehci->qh_pool) {
		goto fail;
	}
	ehci->async = ehci_qh_alloc (ehci, flags);
	if (!ehci->async) {
		goto fail;
	}

	/* ITD for high speed ISO transfers */
	ehci->itd_pool = dma_pool_create ("ehci_itd",
			ehci_to_hcd(ehci)->self.sysdev,
			sizeof (struct ehci_itd),
			32 /* byte alignment (for hw parts) */,
			4096 /* can't cross 4K */);
	if (!ehci->itd_pool) {
		goto fail;
	}

	/* SITD for full/low speed split ISO transfers */
	ehci->sitd_pool = dma_pool_create ("ehci_sitd",
			ehci_to_hcd(ehci)->self.sysdev,
			sizeof (struct ehci_sitd),
			32 /* byte alignment (for hw parts) */,
			4096 /* can't cross 4K */);
	if (!ehci->sitd_pool) {
		goto fail;
	}

	/* Hardware periodic table */
	ehci->periodic = (__le32 *)
		dma_alloc_coherent(ehci_to_hcd(ehci)->self.sysdev,
			ehci->periodic_size * sizeof(__le32),
			&ehci->periodic_dma, flags);
	if (ehci->periodic == NULL) {
		goto fail;
	}

	if (ehci->use_dummy_qh) {
		struct ehci_qh_hw	*hw;
		ehci->dummy = ehci_qh_alloc(ehci, flags);
		if (!ehci->dummy)
			goto fail;

		hw = ehci->dummy->hw;
		hw->hw_next = EHCI_LIST_END(ehci);
		hw->hw_qtd_next = EHCI_LIST_END(ehci);
		hw->hw_alt_next = EHCI_LIST_END(ehci);
		ehci->dummy->hw = hw;

		for (i = 0; i < ehci->periodic_size; i++)
			ehci->periodic[i] = cpu_to_hc32(ehci,
					ehci->dummy->qh_dma);
	} else {
		for (i = 0; i < ehci->periodic_size; i++)
			ehci->periodic[i] = EHCI_LIST_END(ehci);
	}

	/* software shadow of hardware table */
	ehci->pshadow = kcalloc(ehci->periodic_size, sizeof(void *), flags);
	if (ehci->pshadow != NULL)
		return 0;

fail:
	ehci_dbg (ehci, "couldn't init memory\n");
	ehci_mem_cleanup (ehci);
	return -ENOMEM;
}

