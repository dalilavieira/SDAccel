#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct resource {int /*<<< orphan*/  start; } ;
struct reserved_mem {int base; int size; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_3__ {int mask; int /*<<< orphan*/  txt; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int BMAN_ERRS_TO_DISABLE ; 
 int /*<<< orphan*/  BMAN_REV10 ; 
 int /*<<< orphan*/  BMAN_REV20 ; 
 int /*<<< orphan*/  BMAN_REV21 ; 
 int BM_EIRQ_BSCN ; 
 int BM_POOL_MAX ; 
 int /*<<< orphan*/  DPAA_ASSERT (int) ; 
 int /*<<< orphan*/  DPAA_GENALLOC_OFF ; 
 int ENODEV ; 
 int ENXIO ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int REG_ECSR ; 
 int REG_ERR_IER ; 
 int REG_ERR_ISDR ; 
 int REG_ERR_ISR ; 
 int REG_FBPR_AR ; 
 int REG_FBPR_BAR ; 
 int REG_FBPR_BARE ; 
 int REG_IP_REV_1 ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int __bman_probed ; 
 int /*<<< orphan*/  bm_bpalloc ; 
 scalar_t__ bm_ccsr_start ; 
 TYPE_1__* bman_hwerr_txts ; 
 int /*<<< orphan*/  bman_ip_rev ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,...) ; 
 int /*<<< orphan*/  dev_err_ratelimited (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,struct device_node*) ; 
 int /*<<< orphan*/  devm_gen_pool_create (struct device*,int /*<<< orphan*/ ,int,char*) ; 
 scalar_t__ devm_ioremap (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct device*) ; 
 int /*<<< orphan*/  dpaa_invalidate (void*) ; 
 int fbpr_a ; 
 int fbpr_sz ; 
 int gen_pool_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int ilog2 (int) ; 
 int ioread32be (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32be (int,scalar_t__) ; 
 scalar_t__ is_power_of_2 (int) ; 
 int lower_32_bits (int) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  prefetch (void*) ; 
 int qbman_init_private_mem (struct device*,int /*<<< orphan*/ ,int*,int*) ; 
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

__attribute__((used)) static inline u32 bm_ccsr_in(u32 offset)
{
	return ioread32be(bm_ccsr_start + offset/4);
}

__attribute__((used)) static inline void bm_ccsr_out(u32 offset, u32 val)
{
	iowrite32be(val, bm_ccsr_start + offset/4);
}

__attribute__((used)) static void bm_get_version(u16 *id, u8 *major, u8 *minor)
{
	u32 v = bm_ccsr_in(REG_IP_REV_1);
	*id = (v >> 16);
	*major = (v >> 8) & 0xff;
	*minor = v & 0xff;
}

__attribute__((used)) static void bm_set_memory(u64 ba, u32 size)
{
	u32 exp = ilog2(size);
	/* choke if size isn't within range */
	DPAA_ASSERT(size >= 4096 && size <= 1024*1024*1024 &&
		   is_power_of_2(size));
	/* choke if '[e]ba' has lower-alignment than 'size' */
	DPAA_ASSERT(!(ba & (size - 1)));
	bm_ccsr_out(REG_FBPR_BARE, upper_32_bits(ba));
	bm_ccsr_out(REG_FBPR_BAR, lower_32_bits(ba));
	bm_ccsr_out(REG_FBPR_AR, exp - 1);
}

__attribute__((used)) static int bman_fbpr(struct reserved_mem *rmem)
{
	fbpr_a = rmem->base;
	fbpr_sz = rmem->size;

	WARN_ON(!(fbpr_a && fbpr_sz));

	return 0;
}

__attribute__((used)) static irqreturn_t bman_isr(int irq, void *ptr)
{
	u32 isr_val, ier_val, ecsr_val, isr_mask, i;
	struct device *dev = ptr;

	ier_val = bm_ccsr_in(REG_ERR_IER);
	isr_val = bm_ccsr_in(REG_ERR_ISR);
	ecsr_val = bm_ccsr_in(REG_ECSR);
	isr_mask = isr_val & ier_val;

	if (!isr_mask)
		return IRQ_NONE;

	for (i = 0; i < ARRAY_SIZE(bman_hwerr_txts); i++) {
		if (bman_hwerr_txts[i].mask & isr_mask) {
			dev_err_ratelimited(dev, "ErrInt: %s\n",
					    bman_hwerr_txts[i].txt);
			if (bman_hwerr_txts[i].mask & ecsr_val) {
				/* Re-arm error capture registers */
				bm_ccsr_out(REG_ECSR, ecsr_val);
			}
			if (bman_hwerr_txts[i].mask & BMAN_ERRS_TO_DISABLE) {
				dev_dbg(dev, "Disabling error 0x%x\n",
					bman_hwerr_txts[i].mask);
				ier_val &= ~bman_hwerr_txts[i].mask;
				bm_ccsr_out(REG_ERR_IER, ier_val);
			}
		}
	}
	bm_ccsr_out(REG_ERR_ISR, isr_val);

	return IRQ_HANDLED;
}

int bman_is_probed(void)
{
	return __bman_probed;
}

__attribute__((used)) static int fsl_bman_probe(struct platform_device *pdev)
{
	int ret, err_irq;
	struct device *dev = &pdev->dev;
	struct device_node *node = dev->of_node;
	struct resource *res;
	u16 id, bm_pool_cnt;
	u8 major, minor;

	__bman_probed = -1;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(dev, "Can't get %pOF property 'IORESOURCE_MEM'\n",
			node);
		return -ENXIO;
	}
	bm_ccsr_start = devm_ioremap(dev, res->start, resource_size(res));
	if (!bm_ccsr_start)
		return -ENXIO;

	bm_get_version(&id, &major, &minor);
	if (major == 1 && minor == 0) {
		bman_ip_rev = BMAN_REV10;
		bm_pool_cnt = BM_POOL_MAX;
	} else if (major == 2 && minor == 0) {
		bman_ip_rev = BMAN_REV20;
		bm_pool_cnt = 8;
	} else if (major == 2 && minor == 1) {
		bman_ip_rev = BMAN_REV21;
		bm_pool_cnt = BM_POOL_MAX;
	} else {
		dev_err(dev, "Unknown Bman version:%04x,%02x,%02x\n",
			id, major, minor);
		return -ENODEV;
	}

	/*
	 * If FBPR memory wasn't defined using the qbman compatible string
	 * try using the of_reserved_mem_device method
	 */
	if (!fbpr_a) {
		ret = qbman_init_private_mem(dev, 0, &fbpr_a, &fbpr_sz);
		if (ret) {
			dev_err(dev, "qbman_init_private_mem() failed 0x%x\n",
				ret);
			return -ENODEV;
		}
	}

	dev_dbg(dev, "Allocated FBPR 0x%llx 0x%zx\n", fbpr_a, fbpr_sz);

	bm_set_memory(fbpr_a, fbpr_sz);

	err_irq = platform_get_irq(pdev, 0);
	if (err_irq <= 0) {
		dev_info(dev, "Can't get %pOF IRQ\n", node);
		return -ENODEV;
	}
	ret = devm_request_irq(dev, err_irq, bman_isr, IRQF_SHARED, "bman-err",
			       dev);
	if (ret)  {
		dev_err(dev, "devm_request_irq() failed %d for '%pOF'\n",
			ret, node);
		return ret;
	}
	/* Disable Buffer Pool State Change */
	bm_ccsr_out(REG_ERR_ISDR, BM_EIRQ_BSCN);
	/*
	 * Write-to-clear any stale bits, (eg. starvation being asserted prior
	 * to resource allocation during driver init).
	 */
	bm_ccsr_out(REG_ERR_ISR, 0xffffffff);
	/* Enable Error Interrupts */
	bm_ccsr_out(REG_ERR_IER, 0xffffffff);

	bm_bpalloc = devm_gen_pool_create(dev, 0, -1, "bman-bpalloc");
	if (IS_ERR(bm_bpalloc)) {
		ret = PTR_ERR(bm_bpalloc);
		dev_err(dev, "bman-bpalloc pool init failed (%d)\n", ret);
		return ret;
	}

	/* seed BMan resource pool */
	ret = gen_pool_add(bm_bpalloc, DPAA_GENALLOC_OFF, bm_pool_cnt, -1);
	if (ret) {
		dev_err(dev, "Failed to seed BPID range [%d..%d] (%d)\n",
			0, bm_pool_cnt - 1, ret);
		return ret;
	}

	__bman_probed = 1;

	return 0;
}

