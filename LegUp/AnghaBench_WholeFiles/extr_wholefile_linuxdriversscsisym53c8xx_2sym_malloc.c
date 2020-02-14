#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
struct sym_quehead {struct sym_quehead* blink; struct sym_quehead* flink; } ;
struct sym_hcb {int dummy; } ;
struct sym_data {struct sym_hcb* ncb; } ;
struct sym_ccb {int ssss_status; } ;
struct scsi_cmnd {int result; } ;
struct Scsi_Host {scalar_t__ hostdata; } ;
typedef  TYPE_1__* m_vtob_p ;
typedef  TYPE_2__* m_pool_p ;
typedef  int /*<<< orphan*/  m_pool_ident_t ;
typedef  TYPE_3__* m_link_p ;
typedef  scalar_t__ dma_addr_t ;
struct TYPE_23__ {struct TYPE_23__* next; } ;
struct TYPE_22__ {void* (* get_mem_cluster ) (TYPE_2__*) ;TYPE_1__** vtob; struct TYPE_22__* next; int /*<<< orphan*/  dev_dmat; int /*<<< orphan*/  nump; TYPE_3__* h; } ;
struct TYPE_21__ {void* vaddr; scalar_t__ baddr; struct TYPE_21__* next; } ;

/* Variables and functions */
 int DEBUG_ALLOC ; 
 int DEBUG_FLAGS ; 
 int DID_OK ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 scalar_t__ M_GET_MEM_CLUSTER () ; 
 unsigned long SYM_MEM_CLUSTER_MASK ; 
 int SYM_MEM_CLUSTER_SIZE ; 
 int SYM_MEM_SHIFT ; 
 int SYM_MEM_WARN ; 
 int VTOB_HASH_CODE (void*) ; 
 void* __sym_calloc (TYPE_2__*,int,char*) ; 
 void* dma_alloc_coherent (int /*<<< orphan*/ ,int,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ ,int,void*,scalar_t__) ; 
 int host_byte (int) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 TYPE_2__ mp0 ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  printf (char*,char*,int,...) ; 
 int /*<<< orphan*/  scsi_set_resid (struct scsi_cmnd*,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  sym53c8xx_lock ; 
 int /*<<< orphan*/  sym_free_mem_cluster (void*) ; 
 void* sym_get_mem_cluster () ; 
 int /*<<< orphan*/  sym_m_pool_match (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct sym_quehead *sym_que_first(struct sym_quehead *head)
{
	return (head->flink == head) ? 0 : head->flink;
}

__attribute__((used)) static inline struct sym_quehead *sym_que_last(struct sym_quehead *head)
{
	return (head->blink == head) ? 0 : head->blink;
}

__attribute__((used)) static inline void __sym_que_add(struct sym_quehead * new,
	struct sym_quehead * blink,
	struct sym_quehead * flink)
{
	flink->blink	= new;
	new->flink	= flink;
	new->blink	= blink;
	blink->flink	= new;
}

__attribute__((used)) static inline void __sym_que_del(struct sym_quehead * blink,
	struct sym_quehead * flink)
{
	flink->blink = blink;
	blink->flink = flink;
}

__attribute__((used)) static inline int sym_que_empty(struct sym_quehead *head)
{
	return head->flink == head;
}

__attribute__((used)) static inline void sym_que_splice(struct sym_quehead *list,
	struct sym_quehead *head)
{
	struct sym_quehead *first = list->flink;

	if (first != list) {
		struct sym_quehead *last = list->blink;
		struct sym_quehead *at   = head->flink;

		first->blink = head;
		head->flink  = first;

		last->flink = at;
		at->blink   = last;
	}
}

__attribute__((used)) static inline void sym_que_move(struct sym_quehead *orig,
	struct sym_quehead *dest)
{
	struct sym_quehead *first, *last;

	first = orig->flink;
	if (first != orig) {
		first->blink = dest;
		dest->flink  = first;
		last = orig->blink;
		last->flink  = dest;
		dest->blink  = last;
		orig->flink  = orig;
		orig->blink  = orig;
	} else {
		dest->flink  = dest;
		dest->blink  = dest;
	}
}

__attribute__((used)) static inline struct sym_quehead *sym_remque_head(struct sym_quehead *head)
{
	struct sym_quehead *elem = head->flink;

	if (elem != head)
		__sym_que_del(head, elem->flink);
	else
		elem = NULL;
	return elem;
}

__attribute__((used)) static inline struct sym_quehead *sym_remque_tail(struct sym_quehead *head)
{
	struct sym_quehead *elem = head->blink;

	if (elem != head)
		__sym_que_del(elem->blink, head);
	else
		elem = 0;
	return elem;
}

__attribute__((used)) static inline struct sym_hcb * sym_get_hcb(struct Scsi_Host *host)
{
	return ((struct sym_data *)host->hostdata)->ncb;
}

__attribute__((used)) static inline void *sym_m_get_dma_mem_cluster(m_pool_p mp, m_vtob_p vbp)
{
	void *vaddr = NULL;
	dma_addr_t baddr = 0;

	vaddr = dma_alloc_coherent(mp->dev_dmat, SYM_MEM_CLUSTER_SIZE, &baddr,
			GFP_ATOMIC);
	if (vaddr) {
		vbp->vaddr = vaddr;
		vbp->baddr = baddr;
	}
	return vaddr;
}

__attribute__((used)) static inline void sym_m_free_dma_mem_cluster(m_pool_p mp, m_vtob_p vbp)
{
	dma_free_coherent(mp->dev_dmat, SYM_MEM_CLUSTER_SIZE, vbp->vaddr,
			vbp->baddr);
}

__attribute__((used)) static inline void
sym_set_cam_status(struct scsi_cmnd *cmd, int status)
{
	cmd->result &= ~(0xff  << 16);
	cmd->result |= (status << 16);
}

__attribute__((used)) static inline int
sym_get_cam_status(struct scsi_cmnd *cmd)
{
	return host_byte(cmd->result);
}

__attribute__((used)) static inline void sym_set_cam_result_ok(struct sym_ccb *cp, struct scsi_cmnd *cmd, int resid)
{
	scsi_set_resid(cmd, resid);
	cmd->result = (DID_OK << 16) | (cp->ssss_status & 0x7f);
}

__attribute__((used)) static void *___sym_malloc(m_pool_p mp, int size)
{
	int i = 0;
	int s = (1 << SYM_MEM_SHIFT);
	int j;
	void *a;
	m_link_p h = mp->h;

	if (size > SYM_MEM_CLUSTER_SIZE)
		return NULL;

	while (size > s) {
		s <<= 1;
		++i;
	}

	j = i;
	while (!h[j].next) {
		if (s == SYM_MEM_CLUSTER_SIZE) {
			h[j].next = (m_link_p) M_GET_MEM_CLUSTER();
			if (h[j].next)
				h[j].next->next = NULL;
			break;
		}
		++j;
		s <<= 1;
	}
	a = h[j].next;
	if (a) {
		h[j].next = h[j].next->next;
		while (j > i) {
			j -= 1;
			s >>= 1;
			h[j].next = (m_link_p) (a+s);
			h[j].next->next = NULL;
		}
	}
#ifdef DEBUG
	printf("___sym_malloc(%d) = %p\n", size, (void *) a);
#endif
	return a;
}

__attribute__((used)) static void ___sym_mfree(m_pool_p mp, void *ptr, int size)
{
	int i = 0;
	int s = (1 << SYM_MEM_SHIFT);
	m_link_p q;
	unsigned long a, b;
	m_link_p h = mp->h;

#ifdef DEBUG
	printf("___sym_mfree(%p, %d)\n", ptr, size);
#endif

	if (size > SYM_MEM_CLUSTER_SIZE)
		return;

	while (size > s) {
		s <<= 1;
		++i;
	}

	a = (unsigned long)ptr;

	while (1) {
		if (s == SYM_MEM_CLUSTER_SIZE) {
#ifdef SYM_MEM_FREE_UNUSED
			M_FREE_MEM_CLUSTER((void *)a);
#else
			((m_link_p) a)->next = h[i].next;
			h[i].next = (m_link_p) a;
#endif
			break;
		}
		b = a ^ s;
		q = &h[i];
		while (q->next && q->next != (m_link_p) b) {
			q = q->next;
		}
		if (!q->next) {
			((m_link_p) a)->next = h[i].next;
			h[i].next = (m_link_p) a;
			break;
		}
		q->next = q->next->next;
		a = a & b;
		s <<= 1;
		++i;
	}
}

__attribute__((used)) static void *__sym_calloc2(m_pool_p mp, int size, char *name, int uflags)
{
	void *p;

	p = ___sym_malloc(mp, size);

	if (DEBUG_FLAGS & DEBUG_ALLOC) {
		printf ("new %-10s[%4d] @%p.\n", name, size, p);
	}

	if (p)
		memset(p, 0, size);
	else if (uflags & SYM_MEM_WARN)
		printf ("__sym_calloc2: failed to allocate %s[%d]\n", name, size);
	return p;
}

__attribute__((used)) static void __sym_mfree(m_pool_p mp, void *ptr, int size, char *name)
{
	if (DEBUG_FLAGS & DEBUG_ALLOC)
		printf ("freeing %-10s[%4d] @%p.\n", name, size, ptr);

	___sym_mfree(mp, ptr, size);
}

__attribute__((used)) static void *___mp0_get_mem_cluster(m_pool_p mp)
{
	void *m = sym_get_mem_cluster();
	if (m)
		++mp->nump;
	return m;
}

__attribute__((used)) static void ___mp0_free_mem_cluster(m_pool_p mp, void *m)
{
	sym_free_mem_cluster(m);
	--mp->nump;
}

__attribute__((used)) static void * ___get_dma_mem_cluster(m_pool_p mp)
{
	m_vtob_p vbp;
	void *vaddr;

	vbp = __sym_calloc(&mp0, sizeof(*vbp), "VTOB");
	if (!vbp)
		goto out_err;

	vaddr = sym_m_get_dma_mem_cluster(mp, vbp);
	if (vaddr) {
		int hc = VTOB_HASH_CODE(vaddr);
		vbp->next = mp->vtob[hc];
		mp->vtob[hc] = vbp;
		++mp->nump;
	}
	return vaddr;
out_err:
	return NULL;
}

__attribute__((used)) static void ___free_dma_mem_cluster(m_pool_p mp, void *m)
{
	m_vtob_p *vbpp, vbp;
	int hc = VTOB_HASH_CODE(m);

	vbpp = &mp->vtob[hc];
	while (*vbpp && (*vbpp)->vaddr != m)
		vbpp = &(*vbpp)->next;
	if (*vbpp) {
		vbp = *vbpp;
		*vbpp = (*vbpp)->next;
		sym_m_free_dma_mem_cluster(mp, vbp);
		__sym_mfree(&mp0, vbp, sizeof(*vbp), "VTOB");
		--mp->nump;
	}
}

__attribute__((used)) static inline m_pool_p ___get_dma_pool(m_pool_ident_t dev_dmat)
{
	m_pool_p mp;
	for (mp = mp0.next;
		mp && !sym_m_pool_match(mp->dev_dmat, dev_dmat);
			mp = mp->next);
	return mp;
}

__attribute__((used)) static m_pool_p ___cre_dma_pool(m_pool_ident_t dev_dmat)
{
	m_pool_p mp = __sym_calloc(&mp0, sizeof(*mp), "MPOOL");
	if (mp) {
		mp->dev_dmat = dev_dmat;
		mp->get_mem_cluster = ___get_dma_mem_cluster;
#ifdef	SYM_MEM_FREE_UNUSED
		mp->free_mem_cluster = ___free_dma_mem_cluster;
#endif
		mp->next = mp0.next;
		mp0.next = mp;
		return mp;
	}
	return NULL;
}

__attribute__((used)) static void ___del_dma_pool(m_pool_p p)
{
	m_pool_p *pp = &mp0.next;

	while (*pp && *pp != p)
		pp = &(*pp)->next;
	if (*pp) {
		*pp = (*pp)->next;
		__sym_mfree(&mp0, p, sizeof(*p), "MPOOL");
	}
}

void *__sym_calloc_dma(m_pool_ident_t dev_dmat, int size, char *name)
{
	unsigned long flags;
	m_pool_p mp;
	void *m = NULL;

	spin_lock_irqsave(&sym53c8xx_lock, flags);
	mp = ___get_dma_pool(dev_dmat);
	if (!mp)
		mp = ___cre_dma_pool(dev_dmat);
	if (!mp)
		goto out;
	m = __sym_calloc(mp, size, name);
#ifdef	SYM_MEM_FREE_UNUSED
	if (!mp->nump)
		___del_dma_pool(mp);
#endif

 out:
	spin_unlock_irqrestore(&sym53c8xx_lock, flags);
	return m;
}

void __sym_mfree_dma(m_pool_ident_t dev_dmat, void *m, int size, char *name)
{
	unsigned long flags;
	m_pool_p mp;

	spin_lock_irqsave(&sym53c8xx_lock, flags);
	mp = ___get_dma_pool(dev_dmat);
	if (!mp)
		goto out;
	__sym_mfree(mp, m, size, name);
#ifdef	SYM_MEM_FREE_UNUSED
	if (!mp->nump)
		___del_dma_pool(mp);
#endif
 out:
	spin_unlock_irqrestore(&sym53c8xx_lock, flags);
}

dma_addr_t __vtobus(m_pool_ident_t dev_dmat, void *m)
{
	unsigned long flags;
	m_pool_p mp;
	int hc = VTOB_HASH_CODE(m);
	m_vtob_p vp = NULL;
	void *a = (void *)((unsigned long)m & ~SYM_MEM_CLUSTER_MASK);
	dma_addr_t b;

	spin_lock_irqsave(&sym53c8xx_lock, flags);
	mp = ___get_dma_pool(dev_dmat);
	if (mp) {
		vp = mp->vtob[hc];
		while (vp && vp->vaddr != a)
			vp = vp->next;
	}
	if (!vp)
		panic("sym: VTOBUS FAILED!\n");
	b = vp->baddr + (m - a);
	spin_unlock_irqrestore(&sym53c8xx_lock, flags);
	return b;
}

