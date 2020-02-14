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
typedef  size_t u64 ;
typedef  size_t u32 ;
struct resource {size_t start; } ;
struct reset_controller_dev {int dummy; } ;
struct qcom_scm_vmperm {int vmid; int perm; } ;
struct qcom_scm_mem_map_info {void* mem_size; void* mem_addr; } ;
struct qcom_scm_hdcp_req {int dummy; } ;
struct qcom_scm_current_perm_info {scalar_t__ ctx_size; scalar_t__ ctx; void* perm; void* vmid; } ;
struct TYPE_2__ {int nr_resets; struct device_node* of_node; int /*<<< orphan*/ * ops; } ;
struct qcom_scm {size_t dload_mode_addr; struct device* dev; void* core_clk; TYPE_1__ reset; void* bus_clk; void* iface_clk; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
typedef  size_t phys_addr_t ;
typedef  size_t dma_addr_t ;
typedef  int /*<<< orphan*/  cpumask_t ;
typedef  void* __le32 ;

/* Variables and functions */
 size_t ALIGN (size_t,int /*<<< orphan*/ ) ; 
 int BIT (int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INT_MAX ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 unsigned int QCOM_SCM_CMD_HDCP ; 
#define  QCOM_SCM_EINVAL_ADDR 133 
#define  QCOM_SCM_EINVAL_ARG 132 
#define  QCOM_SCM_ENOMEM 131 
#define  QCOM_SCM_EOPNOTSUPP 130 
#define  QCOM_SCM_ERROR 129 
 unsigned int QCOM_SCM_PAS_IS_SUPPORTED_CMD ; 
 unsigned int QCOM_SCM_SET_DLOAD_MODE ; 
 int /*<<< orphan*/  QCOM_SCM_SVC_BOOT ; 
 int /*<<< orphan*/  QCOM_SCM_SVC_HDCP ; 
 int /*<<< orphan*/  QCOM_SCM_SVC_PIL ; 
#define  QCOM_SCM_V2_EBUSY 128 
 unsigned long SCM_HAS_BUS_CLK ; 
 unsigned long SCM_HAS_CORE_CLK ; 
 unsigned long SCM_HAS_IFACE_CLK ; 
 int /*<<< orphan*/  SZ_64 ; 
 int __qcom_scm_assign_mem (struct device*,size_t,size_t,size_t,size_t,size_t,size_t) ; 
 int /*<<< orphan*/  __qcom_scm_cpu_power_down (size_t) ; 
 int __qcom_scm_hdcp_req (struct device*,struct qcom_scm_hdcp_req*,size_t,size_t*) ; 
 int /*<<< orphan*/  __qcom_scm_init () ; 
 int __qcom_scm_io_readl (struct device*,size_t,unsigned int*) ; 
 int __qcom_scm_io_writel (struct device*,size_t,unsigned int) ; 
 int __qcom_scm_iommu_secure_ptbl_init (struct device*,size_t,size_t,size_t) ; 
 int __qcom_scm_iommu_secure_ptbl_size (struct device*,size_t,size_t*) ; 
 int __qcom_scm_is_call_available (struct device*,int /*<<< orphan*/ ,unsigned int) ; 
 int __qcom_scm_pas_auth_and_reset (struct device*,size_t) ; 
 int __qcom_scm_pas_init_image (struct device*,size_t,size_t) ; 
 int __qcom_scm_pas_mem_setup (struct device*,size_t,size_t,size_t) ; 
 int __qcom_scm_pas_mss_reset (struct device*,int) ; 
 int __qcom_scm_pas_shutdown (struct device*,size_t) ; 
 int __qcom_scm_pas_supported (struct device*,size_t) ; 
 int __qcom_scm_restore_sec_cfg (struct device*,size_t,size_t) ; 
 int __qcom_scm_set_cold_boot_addr (void*,int /*<<< orphan*/  const*) ; 
 int __qcom_scm_set_dload_mode (struct device*,int) ; 
 int __qcom_scm_set_remote_state (struct device*,size_t,size_t) ; 
 int __qcom_scm_set_warm_boot_addr (struct device*,void*,int /*<<< orphan*/  const*) ; 
 struct qcom_scm* __scm ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_prepare_enable (void*) ; 
 int clk_set_rate (void*,int /*<<< orphan*/ ) ; 
 void* cpu_to_le32 (int) ; 
 void* cpu_to_le64 (size_t) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 void* devm_clk_get (struct device*,char*) ; 
 struct qcom_scm* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_reset_controller_register (struct device*,TYPE_1__*) ; 
 void* dma_alloc_coherent (struct device*,size_t,size_t*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (struct device*,size_t,void*,size_t) ; 
 scalar_t__ download_mode ; 
 int ffs (unsigned int) ; 
 int hweight_long (unsigned int) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,size_t) ; 
 int of_address_to_resource (struct device_node*,int /*<<< orphan*/ ,struct resource*) ; 
 scalar_t__ of_device_get_match_data (struct device*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int of_property_read_u32_index (struct device_node*,char*,int,size_t*) ; 
 int /*<<< orphan*/  qcom_scm_pas_reset_ops ; 

__attribute__((used)) static inline int qcom_scm_remap_error(int err)
{
	switch (err) {
	case QCOM_SCM_ERROR:
		return -EIO;
	case QCOM_SCM_EINVAL_ADDR:
	case QCOM_SCM_EINVAL_ARG:
		return -EINVAL;
	case QCOM_SCM_EOPNOTSUPP:
		return -EOPNOTSUPP;
	case QCOM_SCM_ENOMEM:
		return -ENOMEM;
	case QCOM_SCM_V2_EBUSY:
		return -EBUSY;
	}
	return -EINVAL;
}

__attribute__((used)) static int qcom_scm_clk_enable(void)
{
	int ret;

	ret = clk_prepare_enable(__scm->core_clk);
	if (ret)
		goto bail;

	ret = clk_prepare_enable(__scm->iface_clk);
	if (ret)
		goto disable_core;

	ret = clk_prepare_enable(__scm->bus_clk);
	if (ret)
		goto disable_iface;

	return 0;

disable_iface:
	clk_disable_unprepare(__scm->iface_clk);
disable_core:
	clk_disable_unprepare(__scm->core_clk);
bail:
	return ret;
}

__attribute__((used)) static void qcom_scm_clk_disable(void)
{
	clk_disable_unprepare(__scm->core_clk);
	clk_disable_unprepare(__scm->iface_clk);
	clk_disable_unprepare(__scm->bus_clk);
}

int qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus)
{
	return __qcom_scm_set_cold_boot_addr(entry, cpus);
}

int qcom_scm_set_warm_boot_addr(void *entry, const cpumask_t *cpus)
{
	return __qcom_scm_set_warm_boot_addr(__scm->dev, entry, cpus);
}

void qcom_scm_cpu_power_down(u32 flags)
{
	__qcom_scm_cpu_power_down(flags);
}

bool qcom_scm_hdcp_available(void)
{
	int ret = qcom_scm_clk_enable();

	if (ret)
		return ret;

	ret = __qcom_scm_is_call_available(__scm->dev, QCOM_SCM_SVC_HDCP,
						QCOM_SCM_CMD_HDCP);

	qcom_scm_clk_disable();

	return ret > 0 ? true : false;
}

int qcom_scm_hdcp_req(struct qcom_scm_hdcp_req *req, u32 req_cnt, u32 *resp)
{
	int ret = qcom_scm_clk_enable();

	if (ret)
		return ret;

	ret = __qcom_scm_hdcp_req(__scm->dev, req, req_cnt, resp);
	qcom_scm_clk_disable();
	return ret;
}

bool qcom_scm_pas_supported(u32 peripheral)
{
	int ret;

	ret = __qcom_scm_is_call_available(__scm->dev, QCOM_SCM_SVC_PIL,
					   QCOM_SCM_PAS_IS_SUPPORTED_CMD);
	if (ret <= 0)
		return false;

	return __qcom_scm_pas_supported(__scm->dev, peripheral);
}

int qcom_scm_pas_init_image(u32 peripheral, const void *metadata, size_t size)
{
	dma_addr_t mdata_phys;
	void *mdata_buf;
	int ret;

	/*
	 * During the scm call memory protection will be enabled for the meta
	 * data blob, so make sure it's physically contiguous, 4K aligned and
	 * non-cachable to avoid XPU violations.
	 */
	mdata_buf = dma_alloc_coherent(__scm->dev, size, &mdata_phys,
				       GFP_KERNEL);
	if (!mdata_buf) {
		dev_err(__scm->dev, "Allocation of metadata buffer failed.\n");
		return -ENOMEM;
	}
	memcpy(mdata_buf, metadata, size);

	ret = qcom_scm_clk_enable();
	if (ret)
		goto free_metadata;

	ret = __qcom_scm_pas_init_image(__scm->dev, peripheral, mdata_phys);

	qcom_scm_clk_disable();

free_metadata:
	dma_free_coherent(__scm->dev, size, mdata_buf, mdata_phys);

	return ret;
}

int qcom_scm_pas_mem_setup(u32 peripheral, phys_addr_t addr, phys_addr_t size)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;

	ret = __qcom_scm_pas_mem_setup(__scm->dev, peripheral, addr, size);
	qcom_scm_clk_disable();

	return ret;
}

int qcom_scm_pas_auth_and_reset(u32 peripheral)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;

	ret = __qcom_scm_pas_auth_and_reset(__scm->dev, peripheral);
	qcom_scm_clk_disable();

	return ret;
}

int qcom_scm_pas_shutdown(u32 peripheral)
{
	int ret;

	ret = qcom_scm_clk_enable();
	if (ret)
		return ret;

	ret = __qcom_scm_pas_shutdown(__scm->dev, peripheral);
	qcom_scm_clk_disable();

	return ret;
}

__attribute__((used)) static int qcom_scm_pas_reset_assert(struct reset_controller_dev *rcdev,
				     unsigned long idx)
{
	if (idx != 0)
		return -EINVAL;

	return __qcom_scm_pas_mss_reset(__scm->dev, 1);
}

__attribute__((used)) static int qcom_scm_pas_reset_deassert(struct reset_controller_dev *rcdev,
				       unsigned long idx)
{
	if (idx != 0)
		return -EINVAL;

	return __qcom_scm_pas_mss_reset(__scm->dev, 0);
}

int qcom_scm_restore_sec_cfg(u32 device_id, u32 spare)
{
	return __qcom_scm_restore_sec_cfg(__scm->dev, device_id, spare);
}

int qcom_scm_iommu_secure_ptbl_size(u32 spare, size_t *size)
{
	return __qcom_scm_iommu_secure_ptbl_size(__scm->dev, spare, size);
}

int qcom_scm_iommu_secure_ptbl_init(u64 addr, u32 size, u32 spare)
{
	return __qcom_scm_iommu_secure_ptbl_init(__scm->dev, addr, size, spare);
}

int qcom_scm_io_readl(phys_addr_t addr, unsigned int *val)
{
	return __qcom_scm_io_readl(__scm->dev, addr, val);
}

int qcom_scm_io_writel(phys_addr_t addr, unsigned int val)
{
	return __qcom_scm_io_writel(__scm->dev, addr, val);
}

__attribute__((used)) static void qcom_scm_set_download_mode(bool enable)
{
	bool avail;
	int ret = 0;

	avail = __qcom_scm_is_call_available(__scm->dev,
					     QCOM_SCM_SVC_BOOT,
					     QCOM_SCM_SET_DLOAD_MODE);
	if (avail) {
		ret = __qcom_scm_set_dload_mode(__scm->dev, enable);
	} else if (__scm->dload_mode_addr) {
		ret = __qcom_scm_io_writel(__scm->dev, __scm->dload_mode_addr,
					   enable ? QCOM_SCM_SET_DLOAD_MODE : 0);
	} else {
		dev_err(__scm->dev,
			"No available mechanism for setting download mode\n");
	}

	if (ret)
		dev_err(__scm->dev, "failed to set download mode: %d\n", ret);
}

__attribute__((used)) static int qcom_scm_find_dload_address(struct device *dev, u64 *addr)
{
	struct device_node *tcsr;
	struct device_node *np = dev->of_node;
	struct resource res;
	u32 offset;
	int ret;

	tcsr = of_parse_phandle(np, "qcom,dload-mode", 0);
	if (!tcsr)
		return 0;

	ret = of_address_to_resource(tcsr, 0, &res);
	of_node_put(tcsr);
	if (ret)
		return ret;

	ret = of_property_read_u32_index(np, "qcom,dload-mode", 1, &offset);
	if (ret < 0)
		return ret;

	*addr = res.start + offset;

	return 0;
}

bool qcom_scm_is_available(void)
{
	return !!__scm;
}

int qcom_scm_set_remote_state(u32 state, u32 id)
{
	return __qcom_scm_set_remote_state(__scm->dev, state, id);
}

int qcom_scm_assign_mem(phys_addr_t mem_addr, size_t mem_sz,
			unsigned int *srcvm,
			struct qcom_scm_vmperm *newvm, int dest_cnt)
{
	struct qcom_scm_current_perm_info *destvm;
	struct qcom_scm_mem_map_info *mem_to_map;
	phys_addr_t mem_to_map_phys;
	phys_addr_t dest_phys;
	phys_addr_t ptr_phys;
	size_t mem_to_map_sz;
	size_t dest_sz;
	size_t src_sz;
	size_t ptr_sz;
	int next_vm;
	__le32 *src;
	void *ptr;
	int ret;
	int len;
	int i;

	src_sz = hweight_long(*srcvm) * sizeof(*src);
	mem_to_map_sz = sizeof(*mem_to_map);
	dest_sz = dest_cnt * sizeof(*destvm);
	ptr_sz = ALIGN(src_sz, SZ_64) + ALIGN(mem_to_map_sz, SZ_64) +
			ALIGN(dest_sz, SZ_64);

	ptr = dma_alloc_coherent(__scm->dev, ptr_sz, &ptr_phys, GFP_KERNEL);
	if (!ptr)
		return -ENOMEM;

	/* Fill source vmid detail */
	src = ptr;
	len = hweight_long(*srcvm);
	for (i = 0; i < len; i++) {
		src[i] = cpu_to_le32(ffs(*srcvm) - 1);
		*srcvm ^= 1 << (ffs(*srcvm) - 1);
	}

	/* Fill details of mem buff to map */
	mem_to_map = ptr + ALIGN(src_sz, SZ_64);
	mem_to_map_phys = ptr_phys + ALIGN(src_sz, SZ_64);
	mem_to_map[0].mem_addr = cpu_to_le64(mem_addr);
	mem_to_map[0].mem_size = cpu_to_le64(mem_sz);

	next_vm = 0;
	/* Fill details of next vmid detail */
	destvm = ptr + ALIGN(mem_to_map_sz, SZ_64) + ALIGN(src_sz, SZ_64);
	dest_phys = ptr_phys + ALIGN(mem_to_map_sz, SZ_64) + ALIGN(src_sz, SZ_64);
	for (i = 0; i < dest_cnt; i++) {
		destvm[i].vmid = cpu_to_le32(newvm[i].vmid);
		destvm[i].perm = cpu_to_le32(newvm[i].perm);
		destvm[i].ctx = 0;
		destvm[i].ctx_size = 0;
		next_vm |= BIT(newvm[i].vmid);
	}

	ret = __qcom_scm_assign_mem(__scm->dev, mem_to_map_phys, mem_to_map_sz,
				    ptr_phys, src_sz, dest_phys, dest_sz);
	dma_free_coherent(__scm->dev, ALIGN(ptr_sz, SZ_64), ptr, ptr_phys);
	if (ret) {
		dev_err(__scm->dev,
			"Assign memory protection call failed %d.\n", ret);
		return -EINVAL;
	}

	*srcvm = next_vm;
	return 0;
}

__attribute__((used)) static int qcom_scm_probe(struct platform_device *pdev)
{
	struct qcom_scm *scm;
	unsigned long clks;
	int ret;

	scm = devm_kzalloc(&pdev->dev, sizeof(*scm), GFP_KERNEL);
	if (!scm)
		return -ENOMEM;

	ret = qcom_scm_find_dload_address(&pdev->dev, &scm->dload_mode_addr);
	if (ret < 0)
		return ret;

	clks = (unsigned long)of_device_get_match_data(&pdev->dev);
	if (clks & SCM_HAS_CORE_CLK) {
		scm->core_clk = devm_clk_get(&pdev->dev, "core");
		if (IS_ERR(scm->core_clk)) {
			if (PTR_ERR(scm->core_clk) != -EPROBE_DEFER)
				dev_err(&pdev->dev,
					"failed to acquire core clk\n");
			return PTR_ERR(scm->core_clk);
		}
	}

	if (clks & SCM_HAS_IFACE_CLK) {
		scm->iface_clk = devm_clk_get(&pdev->dev, "iface");
		if (IS_ERR(scm->iface_clk)) {
			if (PTR_ERR(scm->iface_clk) != -EPROBE_DEFER)
				dev_err(&pdev->dev,
					"failed to acquire iface clk\n");
			return PTR_ERR(scm->iface_clk);
		}
	}

	if (clks & SCM_HAS_BUS_CLK) {
		scm->bus_clk = devm_clk_get(&pdev->dev, "bus");
		if (IS_ERR(scm->bus_clk)) {
			if (PTR_ERR(scm->bus_clk) != -EPROBE_DEFER)
				dev_err(&pdev->dev,
					"failed to acquire bus clk\n");
			return PTR_ERR(scm->bus_clk);
		}
	}

	scm->reset.ops = &qcom_scm_pas_reset_ops;
	scm->reset.nr_resets = 1;
	scm->reset.of_node = pdev->dev.of_node;
	ret = devm_reset_controller_register(&pdev->dev, &scm->reset);
	if (ret)
		return ret;

	/* vote for max clk rate for highest performance */
	ret = clk_set_rate(scm->core_clk, INT_MAX);
	if (ret)
		return ret;

	__scm = scm;
	__scm->dev = &pdev->dev;

	__qcom_scm_init();

	/*
	 * If requested enable "download mode", from this point on warmboot
	 * will cause the the boot stages to enter download mode, unless
	 * disabled below by a clean shutdown/reboot.
	 */
	if (download_mode)
		qcom_scm_set_download_mode(true);

	return 0;
}

__attribute__((used)) static void qcom_scm_shutdown(struct platform_device *pdev)
{
	/* Clean shutdown, disable download mode to allow normal restart */
	if (download_mode)
		qcom_scm_set_download_mode(false);
}

