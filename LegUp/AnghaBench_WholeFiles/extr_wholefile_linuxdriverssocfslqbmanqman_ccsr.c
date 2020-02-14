#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_5__ {int* state; } ;
struct qman_cgrs {TYPE_1__ q; } ;
struct qm_mcr_querywq {int channel_wq; } ;
struct qm_mcr_querycgr {int /*<<< orphan*/  a_bcnt_lo; scalar_t__ a_bcnt_hi; int /*<<< orphan*/  i_bcnt_lo; scalar_t__ i_bcnt_hi; } ;
struct qm_ecir2 {int info; } ;
struct qm_ecir {int info; } ;
struct qm_eadr {int info; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum qm_wq_class { ____Placeholder_qm_wq_class } qm_wq_class ;
typedef  enum qm_memory { ____Placeholder_qm_memory } qm_memory ;
typedef  enum qm_dc_portal { ____Placeholder_qm_dc_portal } qm_dc_portal ;
struct TYPE_7__ {char* txt; int addr_mask; int bits; } ;
struct TYPE_6__ {int mask; int /*<<< orphan*/  txt; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int BIT (int) ; 
 int CGR_BIT (scalar_t__) ; 
 size_t CGR_WORD (scalar_t__) ; 
 int /*<<< orphan*/  DPAA_ASSERT (int) ; 
 int DPAA_GENALLOC_OFF ; 
 int EACCES ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENXIO ; 
 int FQID_ECSR_ERR ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int IO_CFG_SDEST_MASK ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int LIO_CFG_LIODN_MASK ; 
 int MCR_INIT_PFDR ; 
 scalar_t__ MCR_get_rslt (int) ; 
 scalar_t__ MCR_rslt_eaccess (scalar_t__) ; 
 int /*<<< orphan*/  MCR_rslt_idle (scalar_t__) ; 
 scalar_t__ MCR_rslt_inval (scalar_t__) ; 
 scalar_t__ MCR_rslt_ok (scalar_t__) ; 
 int PFDR_AR_EN ; 
 int PORTAL_ECSR_ERR ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QMAN_CHANNEL_CAAM_REV3 ; 
 int QMAN_CHANNEL_POOL1_REV3 ; 
 int QMAN_ERRS_TO_DISABLE ; 
 int QMAN_REV11 ; 
 int QMAN_REV12 ; 
 int QMAN_REV20 ; 
 int QMAN_REV30 ; 
 int QMAN_REV31 ; 
 int QMAN_REV32 ; 
 int QM_CHANNEL_SWPORTAL0 ; 
 int QM_CI_SCHED_CFG_BMAN_W ; 
 int QM_CI_SCHED_CFG_RW_W ; 
 int QM_CI_SCHED_CFG_SRCCIV ; 
 int QM_CI_SCHED_CFG_SRCCIV_EN ; 
 int QM_CI_SCHED_CFG_SRQ_W ; 
 int QM_EIRQ_IECE ; 
 int QM_EIRQ_MBEI ; 
 int QM_EIRQ_PEBI ; 
 int QM_EIRQ_SBEI ; 
 int QM_FQID_RANGE_START ; 
 int QM_SDQCR_CHANNELS_POOL_CONV (int) ; 
 int REG_CI_SCHED_CFG ; 
 int REG_DCP_CFG (int) ; 
 int REG_EADR ; 
 int REG_ECIR ; 
 int REG_ECIR2 ; 
 int REG_ECSR ; 
 int REG_EDATA (int) ; 
 int REG_ERR_IER ; 
 int REG_ERR_ISR ; 
 int REG_FQD_BARE ; 
 int REG_HID_CFG ; 
 int REG_IP_REV_1 ; 
 int REG_MCP (int) ; 
 int REG_MCR ; 
 int REG_PFDR_BARE ; 
 int REG_PFDR_CFG ; 
 int REG_PFDR_FP_LWIT ; 
 int REG_QCSP_IO_CFG (int) ; 
 int REG_QCSP_LIO_CFG (int) ; 
 int REG_REV3_QCSP_IO_CFG (int) ; 
 int REG_REV3_QCSP_LIO_CFG (int) ; 
 int REG_SFDR_CFG ; 
 int REG_WQ_CS_CFG (int) ; 
 int REG_offset_AR ; 
 int REG_offset_BAR ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int __qman_probed ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_crit (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err_ratelimited (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,struct device_node*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int /*<<< orphan*/  devm_gen_pool_create (struct device*,int /*<<< orphan*/ ,int,char*) ; 
 scalar_t__ devm_ioremap (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct device*) ; 
 int /*<<< orphan*/  dma_wmb () ; 
 int /*<<< orphan*/  dpaa_invalidate (void*) ; 
 TYPE_3__* error_mdata ; 
 int fqd_a ; 
 int fqd_sz ; 
 int gen_pool_add (int /*<<< orphan*/ ,int,int,int) ; 
 int ilog2 (int) ; 
 int ioread32be (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32be (int,scalar_t__) ; 
 scalar_t__ is_power_of_2 (int) ; 
 int lower_32_bits (int) ; 
 int /*<<< orphan*/  memset (struct qman_cgrs*,int,int) ; 
 int pfdr_a ; 
 int pfdr_sz ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  prefetch (void*) ; 
 int qbman_init_private_mem (struct device*,int,int*,int*) ; 
 scalar_t__ qm_ccsr_start ; 
 int /*<<< orphan*/  qm_cgralloc ; 
 int /*<<< orphan*/  qm_channel_caam ; 
 int qm_channel_pool1 ; 
 int qm_dc_portal_fman0 ; 
 int qm_dc_portal_fman1 ; 
 int /*<<< orphan*/  qm_fqalloc ; 
 int qm_memory_fqd ; 
 int qm_memory_pfdr ; 
 int qm_pools_sdqcr ; 
 int /*<<< orphan*/  qm_qpalloc ; 
 int qm_wq_first ; 
 int qm_wq_last ; 
 int qman_alloc_fq_table (unsigned int) ; 
 TYPE_2__* qman_hwerr_txts ; 
 int qman_ip_rev ; 
 int qman_wq_alloc () ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int upper_32_bits (int) ; 

__attribute__((used)) static inline void dpaa_flush(void *p)
{
	/*
	 * Only PPC needs to flush the cache currently - on ARM the mapping
	 * is non cacheable
	 */
#ifdef CONFIG_PPC
	flush_dcache_range((unsigned long)p, (unsigned long)p+64);
#endif
}

__attribute__((used)) static inline void dpaa_touch_ro(void *p)
{
#if (L1_CACHE_BYTES == 32)
	prefetch(p+32);
#endif
	prefetch(p);
}

__attribute__((used)) static inline void dpaa_invalidate_touch_ro(void *p)
{
	dpaa_invalidate(p);
	dpaa_touch_ro(p);
}

__attribute__((used)) static inline u8 dpaa_cyc_diff(u8 ringsize, u8 first, u8 last)
{
	/* 'first' is included, 'last' is excluded */
	if (first <= last)
		return last - first;
	return ringsize + last - first;
}

__attribute__((used)) static inline u16 qm_mcr_querywq_get_chan(const struct qm_mcr_querywq *wq)
{
	return wq->channel_wq >> 3;
}

__attribute__((used)) static inline u64 qm_mcr_querycgr_i_get64(const struct qm_mcr_querycgr *q)
{
	return ((u64)q->i_bcnt_hi << 32) | be32_to_cpu(q->i_bcnt_lo);
}

__attribute__((used)) static inline u64 qm_mcr_querycgr_a_get64(const struct qm_mcr_querycgr *q)
{
	return ((u64)q->a_bcnt_hi << 32) | be32_to_cpu(q->a_bcnt_lo);
}

__attribute__((used)) static inline void qman_cgrs_init(struct qman_cgrs *c)
{
	memset(c, 0, sizeof(*c));
}

__attribute__((used)) static inline void qman_cgrs_fill(struct qman_cgrs *c)
{
	memset(c, 0xff, sizeof(*c));
}

__attribute__((used)) static inline int qman_cgrs_get(struct qman_cgrs *c, u8 cgr)
{
	return c->q.state[CGR_WORD(cgr)] & CGR_BIT(cgr);
}

__attribute__((used)) static inline void qman_cgrs_cp(struct qman_cgrs *dest,
				const struct qman_cgrs *src)
{
	*dest = *src;
}

__attribute__((used)) static inline void qman_cgrs_and(struct qman_cgrs *dest,
			const struct qman_cgrs *a, const struct qman_cgrs *b)
{
	int ret;
	u32 *_d = dest->q.state;
	const u32 *_a = a->q.state;
	const u32 *_b = b->q.state;

	for (ret = 0; ret < 8; ret++)
		*_d++ = *_a++ & *_b++;
}

__attribute__((used)) static inline void qman_cgrs_xor(struct qman_cgrs *dest,
			const struct qman_cgrs *a, const struct qman_cgrs *b)
{
	int ret;
	u32 *_d = dest->q.state;
	const u32 *_a = a->q.state;
	const u32 *_b = b->q.state;

	for (ret = 0; ret < 8; ret++)
		*_d++ = *_a++ ^ *_b++;
}

__attribute__((used)) static bool qm_ecir_is_dcp(const struct qm_ecir *p)
{
	return p->info & BIT(29);
}

__attribute__((used)) static int qm_ecir_get_pnum(const struct qm_ecir *p)
{
	return (p->info >> 24) & 0x1f;
}

__attribute__((used)) static int qm_ecir_get_fqid(const struct qm_ecir *p)
{
	return p->info & (BIT(24) - 1);
}

__attribute__((used)) static bool qm_ecir2_is_dcp(const struct qm_ecir2 *p)
{
	return p->info & BIT(31);
}

__attribute__((used)) static int qm_ecir2_get_pnum(const struct qm_ecir2 *p)
{
	return p->info & (BIT(10) - 1);
}

__attribute__((used)) static int qm_eadr_get_memid(const struct qm_eadr *p)
{
	return (p->info >> 24) & 0xf;
}

__attribute__((used)) static int qm_eadr_get_eadr(const struct qm_eadr *p)
{
	return p->info & (BIT(12) - 1);
}

__attribute__((used)) static int qm_eadr_v3_get_memid(const struct qm_eadr *p)
{
	return (p->info >> 24) & 0x1f;
}

__attribute__((used)) static int qm_eadr_v3_get_eadr(const struct qm_eadr *p)
{
	return p->info & (BIT(16) - 1);
}

__attribute__((used)) static inline u32 qm_ccsr_in(u32 offset)
{
	return ioread32be(qm_ccsr_start + offset/4);
}

__attribute__((used)) static inline void qm_ccsr_out(u32 offset, u32 val)
{
	iowrite32be(val, qm_ccsr_start + offset/4);
}

u32 qm_get_pools_sdqcr(void)
{
	return qm_pools_sdqcr;
}

__attribute__((used)) static void qm_set_dc(enum qm_dc_portal portal, int ed, u8 sernd)
{
	DPAA_ASSERT(!ed || portal == qm_dc_portal_fman0 ||
		    portal == qm_dc_portal_fman1);
	if ((qman_ip_rev & 0xFF00) >= QMAN_REV30)
		qm_ccsr_out(REG_DCP_CFG(portal),
			    (ed ? 0x1000 : 0) | (sernd & 0x3ff));
	else
		qm_ccsr_out(REG_DCP_CFG(portal),
			    (ed ? 0x100 : 0) | (sernd & 0x1f));
}

__attribute__((used)) static void qm_set_wq_scheduling(enum qm_wq_class wq_class,
				 u8 cs_elev, u8 csw2, u8 csw3, u8 csw4,
				 u8 csw5, u8 csw6, u8 csw7)
{
	qm_ccsr_out(REG_WQ_CS_CFG(wq_class), ((cs_elev & 0xff) << 24) |
		    ((csw2 & 0x7) << 20) | ((csw3 & 0x7) << 16) |
		    ((csw4 & 0x7) << 12) | ((csw5 & 0x7) << 8) |
		    ((csw6 & 0x7) << 4) | (csw7 & 0x7));
}

__attribute__((used)) static void qm_set_hid(void)
{
	qm_ccsr_out(REG_HID_CFG, 0);
}

__attribute__((used)) static void qm_set_corenet_initiator(void)
{
	qm_ccsr_out(REG_CI_SCHED_CFG, QM_CI_SCHED_CFG_SRCCIV_EN |
		    (QM_CI_SCHED_CFG_SRCCIV << 24) |
		    (QM_CI_SCHED_CFG_SRQ_W << 8) |
		    (QM_CI_SCHED_CFG_RW_W << 4) |
		    QM_CI_SCHED_CFG_BMAN_W);
}

__attribute__((used)) static void qm_get_version(u16 *id, u8 *major, u8 *minor)
{
	u32 v = qm_ccsr_in(REG_IP_REV_1);
	*id = (v >> 16);
	*major = (v >> 8) & 0xff;
	*minor = v & 0xff;
}

__attribute__((used)) static void qm_set_memory(enum qm_memory memory, u64 ba, u32 size)
{
	u32 offset = (memory == qm_memory_fqd) ? REG_FQD_BARE : REG_PFDR_BARE;
	u32 exp = ilog2(size);

	/* choke if size isn't within range */
	DPAA_ASSERT((size >= 4096) && (size <= 1024*1024*1024) &&
		    is_power_of_2(size));
	/* choke if 'ba' has lower-alignment than 'size' */
	DPAA_ASSERT(!(ba & (size - 1)));
	qm_ccsr_out(offset, upper_32_bits(ba));
	qm_ccsr_out(offset + REG_offset_BAR, lower_32_bits(ba));
	qm_ccsr_out(offset + REG_offset_AR, PFDR_AR_EN | (exp - 1));
}

__attribute__((used)) static void qm_set_pfdr_threshold(u32 th, u8 k)
{
	qm_ccsr_out(REG_PFDR_FP_LWIT, th & 0xffffff);
	qm_ccsr_out(REG_PFDR_CFG, k);
}

__attribute__((used)) static void qm_set_sfdr_threshold(u16 th)
{
	qm_ccsr_out(REG_SFDR_CFG, th & 0x3ff);
}

__attribute__((used)) static int qm_init_pfdr(struct device *dev, u32 pfdr_start, u32 num)
{
	u8 rslt = MCR_get_rslt(qm_ccsr_in(REG_MCR));

	DPAA_ASSERT(pfdr_start && !(pfdr_start & 7) && !(num & 7) && num);
	/* Make sure the command interface is 'idle' */
	if (!MCR_rslt_idle(rslt)) {
		dev_crit(dev, "QMAN_MCR isn't idle");
		WARN_ON(1);
	}

	/* Write the MCR command params then the verb */
	qm_ccsr_out(REG_MCP(0), pfdr_start);
	/*
	 * TODO: remove this - it's a workaround for a model bug that is
	 * corrected in more recent versions. We use the workaround until
	 * everyone has upgraded.
	 */
	qm_ccsr_out(REG_MCP(1), pfdr_start + num - 16);
	dma_wmb();
	qm_ccsr_out(REG_MCR, MCR_INIT_PFDR);
	/* Poll for the result */
	do {
		rslt = MCR_get_rslt(qm_ccsr_in(REG_MCR));
	} while (!MCR_rslt_idle(rslt));
	if (MCR_rslt_ok(rslt))
		return 0;
	if (MCR_rslt_eaccess(rslt))
		return -EACCES;
	if (MCR_rslt_inval(rslt))
		return -EINVAL;
	dev_crit(dev, "Unexpected result from MCR_INIT_PFDR: %02x\n", rslt);
	return -ENODEV;
}

__attribute__((used)) static unsigned int qm_get_fqid_maxcnt(void)
{
	return fqd_sz / 64;
}

__attribute__((used)) static void log_edata_bits(struct device *dev, u32 bit_count)
{
	u32 i, j, mask = 0xffffffff;

	dev_warn(dev, "ErrInt, EDATA:\n");
	i = bit_count / 32;
	if (bit_count % 32) {
		i++;
		mask = ~(mask << bit_count % 32);
	}
	j = 16 - i;
	dev_warn(dev, "  0x%08x\n", qm_ccsr_in(REG_EDATA(j)) & mask);
	j++;
	for (; j < 16; j++)
		dev_warn(dev, "  0x%08x\n", qm_ccsr_in(REG_EDATA(j)));
}

__attribute__((used)) static void log_additional_error_info(struct device *dev, u32 isr_val,
				      u32 ecsr_val)
{
	struct qm_ecir ecir_val;
	struct qm_eadr eadr_val;
	int memid;

	ecir_val.info = qm_ccsr_in(REG_ECIR);
	/* Is portal info valid */
	if ((qman_ip_rev & 0xFF00) >= QMAN_REV30) {
		struct qm_ecir2 ecir2_val;

		ecir2_val.info = qm_ccsr_in(REG_ECIR2);
		if (ecsr_val & PORTAL_ECSR_ERR) {
			dev_warn(dev, "ErrInt: %s id %d\n",
				 qm_ecir2_is_dcp(&ecir2_val) ? "DCP" : "SWP",
				 qm_ecir2_get_pnum(&ecir2_val));
		}
		if (ecsr_val & (FQID_ECSR_ERR | QM_EIRQ_IECE))
			dev_warn(dev, "ErrInt: ecir.fqid 0x%x\n",
				 qm_ecir_get_fqid(&ecir_val));

		if (ecsr_val & (QM_EIRQ_SBEI|QM_EIRQ_MBEI)) {
			eadr_val.info = qm_ccsr_in(REG_EADR);
			memid = qm_eadr_v3_get_memid(&eadr_val);
			dev_warn(dev, "ErrInt: EADR Memory: %s, 0x%x\n",
				 error_mdata[memid].txt,
				 error_mdata[memid].addr_mask
					& qm_eadr_v3_get_eadr(&eadr_val));
			log_edata_bits(dev, error_mdata[memid].bits);
		}
	} else {
		if (ecsr_val & PORTAL_ECSR_ERR) {
			dev_warn(dev, "ErrInt: %s id %d\n",
				 qm_ecir_is_dcp(&ecir_val) ? "DCP" : "SWP",
				 qm_ecir_get_pnum(&ecir_val));
		}
		if (ecsr_val & FQID_ECSR_ERR)
			dev_warn(dev, "ErrInt: ecir.fqid 0x%x\n",
				 qm_ecir_get_fqid(&ecir_val));

		if (ecsr_val & (QM_EIRQ_SBEI|QM_EIRQ_MBEI)) {
			eadr_val.info = qm_ccsr_in(REG_EADR);
			memid = qm_eadr_get_memid(&eadr_val);
			dev_warn(dev, "ErrInt: EADR Memory: %s, 0x%x\n",
				 error_mdata[memid].txt,
				 error_mdata[memid].addr_mask
					& qm_eadr_get_eadr(&eadr_val));
			log_edata_bits(dev, error_mdata[memid].bits);
		}
	}
}

__attribute__((used)) static irqreturn_t qman_isr(int irq, void *ptr)
{
	u32 isr_val, ier_val, ecsr_val, isr_mask, i;
	struct device *dev = ptr;

	ier_val = qm_ccsr_in(REG_ERR_IER);
	isr_val = qm_ccsr_in(REG_ERR_ISR);
	ecsr_val = qm_ccsr_in(REG_ECSR);
	isr_mask = isr_val & ier_val;

	if (!isr_mask)
		return IRQ_NONE;

	for (i = 0; i < ARRAY_SIZE(qman_hwerr_txts); i++) {
		if (qman_hwerr_txts[i].mask & isr_mask) {
			dev_err_ratelimited(dev, "ErrInt: %s\n",
					    qman_hwerr_txts[i].txt);
			if (qman_hwerr_txts[i].mask & ecsr_val) {
				log_additional_error_info(dev, isr_mask,
							  ecsr_val);
				/* Re-arm error capture registers */
				qm_ccsr_out(REG_ECSR, ecsr_val);
			}
			if (qman_hwerr_txts[i].mask & QMAN_ERRS_TO_DISABLE) {
				dev_dbg(dev, "Disabling error 0x%x\n",
					qman_hwerr_txts[i].mask);
				ier_val &= ~qman_hwerr_txts[i].mask;
				qm_ccsr_out(REG_ERR_IER, ier_val);
			}
		}
	}
	qm_ccsr_out(REG_ERR_ISR, isr_val);

	return IRQ_HANDLED;
}

__attribute__((used)) static int qman_init_ccsr(struct device *dev)
{
	int i, err;

	/* FQD memory */
	qm_set_memory(qm_memory_fqd, fqd_a, fqd_sz);
	/* PFDR memory */
	qm_set_memory(qm_memory_pfdr, pfdr_a, pfdr_sz);
	err = qm_init_pfdr(dev, 8, pfdr_sz / 64 - 8);
	if (err)
		return err;
	/* thresholds */
	qm_set_pfdr_threshold(512, 64);
	qm_set_sfdr_threshold(128);
	/* clear stale PEBI bit from interrupt status register */
	qm_ccsr_out(REG_ERR_ISR, QM_EIRQ_PEBI);
	/* corenet initiator settings */
	qm_set_corenet_initiator();
	/* HID settings */
	qm_set_hid();
	/* Set scheduling weights to defaults */
	for (i = qm_wq_first; i <= qm_wq_last; i++)
		qm_set_wq_scheduling(i, 0, 0, 0, 0, 0, 0, 0);
	/* We are not prepared to accept ERNs for hardware enqueues */
	qm_set_dc(qm_dc_portal_fman0, 1, 0);
	qm_set_dc(qm_dc_portal_fman1, 1, 0);
	return 0;
}

void qman_liodn_fixup(u16 channel)
{
	static int done;
	static u32 liodn_offset;
	u32 before, after;
	int idx = channel - QM_CHANNEL_SWPORTAL0;

	if ((qman_ip_rev & 0xFF00) >= QMAN_REV30)
		before = qm_ccsr_in(REG_REV3_QCSP_LIO_CFG(idx));
	else
		before = qm_ccsr_in(REG_QCSP_LIO_CFG(idx));
	if (!done) {
		liodn_offset = before & LIO_CFG_LIODN_MASK;
		done = 1;
		return;
	}
	after = (before & (~LIO_CFG_LIODN_MASK)) | liodn_offset;
	if ((qman_ip_rev & 0xFF00) >= QMAN_REV30)
		qm_ccsr_out(REG_REV3_QCSP_LIO_CFG(idx), after);
	else
		qm_ccsr_out(REG_QCSP_LIO_CFG(idx), after);
}

void qman_set_sdest(u16 channel, unsigned int cpu_idx)
{
	int idx = channel - QM_CHANNEL_SWPORTAL0;
	u32 before, after;

	if ((qman_ip_rev & 0xFF00) >= QMAN_REV30) {
		before = qm_ccsr_in(REG_REV3_QCSP_IO_CFG(idx));
		/* Each pair of vcpu share the same SRQ(SDEST) */
		cpu_idx /= 2;
		after = (before & (~IO_CFG_SDEST_MASK)) | (cpu_idx << 16);
		qm_ccsr_out(REG_REV3_QCSP_IO_CFG(idx), after);
	} else {
		before = qm_ccsr_in(REG_QCSP_IO_CFG(idx));
		after = (before & (~IO_CFG_SDEST_MASK)) | (cpu_idx << 16);
		qm_ccsr_out(REG_QCSP_IO_CFG(idx), after);
	}
}

__attribute__((used)) static int qman_resource_init(struct device *dev)
{
	int pool_chan_num, cgrid_num;
	int ret, i;

	switch (qman_ip_rev >> 8) {
	case 1:
		pool_chan_num = 15;
		cgrid_num = 256;
		break;
	case 2:
		pool_chan_num = 3;
		cgrid_num = 64;
		break;
	case 3:
		pool_chan_num = 15;
		cgrid_num = 256;
		break;
	default:
		return -ENODEV;
	}

	ret = gen_pool_add(qm_qpalloc, qm_channel_pool1 | DPAA_GENALLOC_OFF,
			   pool_chan_num, -1);
	if (ret) {
		dev_err(dev, "Failed to seed pool channels (%d)\n", ret);
		return ret;
	}

	ret = gen_pool_add(qm_cgralloc, DPAA_GENALLOC_OFF, cgrid_num, -1);
	if (ret) {
		dev_err(dev, "Failed to seed CGRID range (%d)\n", ret);
		return ret;
	}

	/* parse pool channels into the SDQCR mask */
	for (i = 0; i < cgrid_num; i++)
		qm_pools_sdqcr |= QM_SDQCR_CHANNELS_POOL_CONV(i);

	ret = gen_pool_add(qm_fqalloc, QM_FQID_RANGE_START | DPAA_GENALLOC_OFF,
			   qm_get_fqid_maxcnt() - QM_FQID_RANGE_START, -1);
	if (ret) {
		dev_err(dev, "Failed to seed FQID range (%d)\n", ret);
		return ret;
	}

	return 0;
}

int qman_is_probed(void)
{
	return __qman_probed;
}

__attribute__((used)) static int fsl_qman_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *node = dev->of_node;
	struct resource *res;
	int ret, err_irq;
	u16 id;
	u8 major, minor;

	__qman_probed = -1;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(dev, "Can't get %pOF property 'IORESOURCE_MEM'\n",
			node);
		return -ENXIO;
	}
	qm_ccsr_start = devm_ioremap(dev, res->start, resource_size(res));
	if (!qm_ccsr_start)
		return -ENXIO;

	qm_get_version(&id, &major, &minor);
	if (major == 1 && minor == 0) {
		dev_err(dev, "Rev1.0 on P4080 rev1 is not supported!\n");
			return -ENODEV;
	} else if (major == 1 && minor == 1)
		qman_ip_rev = QMAN_REV11;
	else if	(major == 1 && minor == 2)
		qman_ip_rev = QMAN_REV12;
	else if (major == 2 && minor == 0)
		qman_ip_rev = QMAN_REV20;
	else if (major == 3 && minor == 0)
		qman_ip_rev = QMAN_REV30;
	else if (major == 3 && minor == 1)
		qman_ip_rev = QMAN_REV31;
	else if (major == 3 && minor == 2)
		qman_ip_rev = QMAN_REV32;
	else {
		dev_err(dev, "Unknown QMan version\n");
		return -ENODEV;
	}

	if ((qman_ip_rev & 0xff00) >= QMAN_REV30) {
		qm_channel_pool1 = QMAN_CHANNEL_POOL1_REV3;
		qm_channel_caam = QMAN_CHANNEL_CAAM_REV3;
	}

	if (fqd_a) {
#ifdef CONFIG_PPC
		/*
		 * For PPC backward DT compatibility
		 * FQD memory MUST be zero'd by software
		 */
		zero_priv_mem(fqd_a, fqd_sz);
#else
		WARN(1, "Unexpected architecture using non shared-dma-mem reservations");
#endif
	} else {
		/*
		 * Order of memory regions is assumed as FQD followed by PFDR
		 * in order to ensure allocations from the correct regions the
		 * driver initializes then allocates each piece in order
		 */
		ret = qbman_init_private_mem(dev, 0, &fqd_a, &fqd_sz);
		if (ret) {
			dev_err(dev, "qbman_init_private_mem() for FQD failed 0x%x\n",
				ret);
			return -ENODEV;
		}
	}
	dev_dbg(dev, "Allocated FQD 0x%llx 0x%zx\n", fqd_a, fqd_sz);

	if (!pfdr_a) {
		/* Setup PFDR memory */
		ret = qbman_init_private_mem(dev, 1, &pfdr_a, &pfdr_sz);
		if (ret) {
			dev_err(dev, "qbman_init_private_mem() for PFDR failed 0x%x\n",
				ret);
			return -ENODEV;
		}
	}
	dev_dbg(dev, "Allocated PFDR 0x%llx 0x%zx\n", pfdr_a, pfdr_sz);

	ret = qman_init_ccsr(dev);
	if (ret) {
		dev_err(dev, "CCSR setup failed\n");
		return ret;
	}

	err_irq = platform_get_irq(pdev, 0);
	if (err_irq <= 0) {
		dev_info(dev, "Can't get %pOF property 'interrupts'\n",
			 node);
		return -ENODEV;
	}
	ret = devm_request_irq(dev, err_irq, qman_isr, IRQF_SHARED, "qman-err",
			       dev);
	if (ret)  {
		dev_err(dev, "devm_request_irq() failed %d for '%pOF'\n",
			ret, node);
		return ret;
	}

	/*
	 * Write-to-clear any stale bits, (eg. starvation being asserted prior
	 * to resource allocation during driver init).
	 */
	qm_ccsr_out(REG_ERR_ISR, 0xffffffff);
	/* Enable Error Interrupts */
	qm_ccsr_out(REG_ERR_IER, 0xffffffff);

	qm_fqalloc = devm_gen_pool_create(dev, 0, -1, "qman-fqalloc");
	if (IS_ERR(qm_fqalloc)) {
		ret = PTR_ERR(qm_fqalloc);
		dev_err(dev, "qman-fqalloc pool init failed (%d)\n", ret);
		return ret;
	}

	qm_qpalloc = devm_gen_pool_create(dev, 0, -1, "qman-qpalloc");
	if (IS_ERR(qm_qpalloc)) {
		ret = PTR_ERR(qm_qpalloc);
		dev_err(dev, "qman-qpalloc pool init failed (%d)\n", ret);
		return ret;
	}

	qm_cgralloc = devm_gen_pool_create(dev, 0, -1, "qman-cgralloc");
	if (IS_ERR(qm_cgralloc)) {
		ret = PTR_ERR(qm_cgralloc);
		dev_err(dev, "qman-cgralloc pool init failed (%d)\n", ret);
		return ret;
	}

	ret = qman_resource_init(dev);
	if (ret)
		return ret;

	ret = qman_alloc_fq_table(qm_get_fqid_maxcnt());
	if (ret)
		return ret;

	ret = qman_wq_alloc();
	if (ret)
		return ret;

	__qman_probed = 1;

	return 0;
}

