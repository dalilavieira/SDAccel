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
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct ufs_pa_layer_attr {scalar_t__ pwr_rx; scalar_t__ pwr_tx; } ;
struct ufs_hba_variant_ops {int dummy; } ;
struct ufs_hba {int caps; int quirks; void* priv; TYPE_1__* vops; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {scalar_t__ data; } ;
typedef  enum uic_cmd_dme { ____Placeholder_uic_cmd_dme } uic_cmd_dme ;
typedef  enum ufs_pm_op { ____Placeholder_ufs_pm_op } ufs_pm_op ;
typedef  enum ufs_notify_change_status { ____Placeholder_ufs_notify_change_status } ufs_notify_change_status ;
struct TYPE_2__ {char const* name; int (* init ) (struct ufs_hba*) ;void (* exit ) (struct ufs_hba*) ;int (* get_ufs_hci_version ) (struct ufs_hba*) ;int (* clk_scale_notify ) (struct ufs_hba*,int,int) ;int (* setup_clocks ) (struct ufs_hba*,int,int) ;int (* setup_regulators ) (struct ufs_hba*,int) ;int (* hce_enable_notify ) (struct ufs_hba*,int) ;int (* link_startup_notify ) (struct ufs_hba*,int) ;int (* pwr_change_notify ) (struct ufs_hba*,int,struct ufs_pa_layer_attr*,struct ufs_pa_layer_attr*) ;void (* setup_xfer_req ) (struct ufs_hba*,int,int) ;void (* setup_task_mgmt ) (struct ufs_hba*,int,scalar_t__) ;void (* hibern8_notify ) (struct ufs_hba*,int,int) ;int (* apply_dev_quirks ) (struct ufs_hba*) ;int (* suspend ) (struct ufs_hba*,int) ;int (* resume ) (struct ufs_hba*,int) ;int /*<<< orphan*/  (* dbg_register_dump ) (struct ufs_hba*) ;} ;

/* Variables and functions */
 scalar_t__ ALIGNED_UPIU_SIZE ; 
 int /*<<< orphan*/  ATTR_SET_NOR ; 
 int /*<<< orphan*/  ATTR_SET_ST ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  DME_LOCAL ; 
 int /*<<< orphan*/  DME_PEER ; 
 int ENOTSUPP ; 
 scalar_t__ FASTAUTO_MODE ; 
 scalar_t__ FAST_MODE ; 
 scalar_t__ GENERAL_UPIU_REQUEST_SIZE ; 
 scalar_t__ QUERY_DESC_MAX_SIZE ; 
 int REG_UFS_VERSION ; 
 int UFSHCD_CAP_AUTO_BKOPS_SUSPEND ; 
 int UFSHCD_CAP_CLK_GATING ; 
 int UFSHCD_CAP_CLK_SCALING ; 
 int UFSHCD_CAP_HIBERN8_WITH_CLK_GATING ; 
 int UFSHCD_CAP_INTR_AGGR ; 
 int UFSHCD_CAP_KEEP_AUTO_BKOPS_ENABLED_EXCEPT_SUSPEND ; 
 int UFSHCD_QUIRK_BROKEN_INTR_AGGR ; 
 scalar_t__ UFS_UPIU_MAX_GENERAL_LUN ; 
 unsigned int UFS_UPIU_MAX_UNIT_NUM_ID ; 
 scalar_t__ UFS_UPIU_RPMB_WLUN ; 
 unsigned int UFS_UPIU_WLUN_ID ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ufs_hba* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 scalar_t__ scsi_is_wlun (unsigned int) ; 
 int stub1 (struct ufs_hba*) ; 
 void stub10 (struct ufs_hba*,int,int) ; 
 void stub11 (struct ufs_hba*,int,scalar_t__) ; 
 void stub12 (struct ufs_hba*,int,int) ; 
 int stub13 (struct ufs_hba*) ; 
 int stub14 (struct ufs_hba*,int) ; 
 int stub15 (struct ufs_hba*,int) ; 
 int /*<<< orphan*/  stub16 (struct ufs_hba*) ; 
 void stub2 (struct ufs_hba*) ; 
 int stub3 (struct ufs_hba*) ; 
 int stub4 (struct ufs_hba*,int,int) ; 
 int stub5 (struct ufs_hba*,int,int) ; 
 int stub6 (struct ufs_hba*,int) ; 
 int stub7 (struct ufs_hba*,int) ; 
 int stub8 (struct ufs_hba*,int) ; 
 int stub9 (struct ufs_hba*,int,struct ufs_pa_layer_attr*,struct ufs_pa_layer_attr*) ; 
 int /*<<< orphan*/  tc_dwc_g210_pltfm_match ; 
 int ufshcd_dme_get_attr (struct ufs_hba*,int,int*,int /*<<< orphan*/ ) ; 
 int ufshcd_dme_set_attr (struct ufs_hba*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int ufshcd_pltfrm_init (struct platform_device*,struct ufs_hba_variant_ops*) ; 
 int ufshcd_readl (struct ufs_hba*,int) ; 
 int /*<<< orphan*/  ufshcd_remove (struct ufs_hba*) ; 
 int /*<<< orphan*/  ufshcd_writel (struct ufs_hba*,int,int) ; 

__attribute__((used)) static inline bool ufs_is_valid_unit_desc_lun(u8 lun)
{
	return lun == UFS_UPIU_RPMB_WLUN || (lun < UFS_UPIU_MAX_GENERAL_LUN);
}

__attribute__((used)) static inline bool ufshcd_is_clkgating_allowed(struct ufs_hba *hba)
{
	return hba->caps & UFSHCD_CAP_CLK_GATING;
}

__attribute__((used)) static inline bool ufshcd_can_hibern8_during_gating(struct ufs_hba *hba)
{
	return hba->caps & UFSHCD_CAP_HIBERN8_WITH_CLK_GATING;
}

__attribute__((used)) static inline int ufshcd_is_clkscaling_supported(struct ufs_hba *hba)
{
	return hba->caps & UFSHCD_CAP_CLK_SCALING;
}

__attribute__((used)) static inline bool ufshcd_can_autobkops_during_suspend(struct ufs_hba *hba)
{
	return hba->caps & UFSHCD_CAP_AUTO_BKOPS_SUSPEND;
}

__attribute__((used)) static inline bool ufshcd_is_intr_aggr_allowed(struct ufs_hba *hba)
{
/* DWC UFS Core has the Interrupt aggregation feature but is not detectable*/
#ifndef CONFIG_SCSI_UFS_DWC
	if ((hba->caps & UFSHCD_CAP_INTR_AGGR) &&
	    !(hba->quirks & UFSHCD_QUIRK_BROKEN_INTR_AGGR))
		return true;
	else
		return false;
#else
return true;
#endif
}

__attribute__((used)) static inline void ufshcd_rmwl(struct ufs_hba *hba, u32 mask, u32 val, u32 reg)
{
	u32 tmp;

	tmp = ufshcd_readl(hba, reg);
	tmp &= ~mask;
	tmp |= (val & mask);
	ufshcd_writel(hba, tmp, reg);
}

__attribute__((used)) static inline void check_upiu_size(void)
{
	BUILD_BUG_ON(ALIGNED_UPIU_SIZE <
		GENERAL_UPIU_REQUEST_SIZE + QUERY_DESC_MAX_SIZE);
}

__attribute__((used)) static inline void ufshcd_set_variant(struct ufs_hba *hba, void *variant)
{
	BUG_ON(!hba);
	hba->priv = variant;
}

__attribute__((used)) static inline void *ufshcd_get_variant(struct ufs_hba *hba)
{
	BUG_ON(!hba);
	return hba->priv;
}

__attribute__((used)) static inline bool ufshcd_keep_autobkops_enabled_except_suspend(
							struct ufs_hba *hba)
{
	return hba->caps & UFSHCD_CAP_KEEP_AUTO_BKOPS_ENABLED_EXCEPT_SUSPEND;
}

__attribute__((used)) static inline int ufshcd_dme_set(struct ufs_hba *hba, u32 attr_sel,
				 u32 mib_val)
{
	return ufshcd_dme_set_attr(hba, attr_sel, ATTR_SET_NOR,
				   mib_val, DME_LOCAL);
}

__attribute__((used)) static inline int ufshcd_dme_st_set(struct ufs_hba *hba, u32 attr_sel,
				    u32 mib_val)
{
	return ufshcd_dme_set_attr(hba, attr_sel, ATTR_SET_ST,
				   mib_val, DME_LOCAL);
}

__attribute__((used)) static inline int ufshcd_dme_peer_set(struct ufs_hba *hba, u32 attr_sel,
				      u32 mib_val)
{
	return ufshcd_dme_set_attr(hba, attr_sel, ATTR_SET_NOR,
				   mib_val, DME_PEER);
}

__attribute__((used)) static inline int ufshcd_dme_peer_st_set(struct ufs_hba *hba, u32 attr_sel,
					 u32 mib_val)
{
	return ufshcd_dme_set_attr(hba, attr_sel, ATTR_SET_ST,
				   mib_val, DME_PEER);
}

__attribute__((used)) static inline int ufshcd_dme_get(struct ufs_hba *hba,
				 u32 attr_sel, u32 *mib_val)
{
	return ufshcd_dme_get_attr(hba, attr_sel, mib_val, DME_LOCAL);
}

__attribute__((used)) static inline int ufshcd_dme_peer_get(struct ufs_hba *hba,
				      u32 attr_sel, u32 *mib_val)
{
	return ufshcd_dme_get_attr(hba, attr_sel, mib_val, DME_PEER);
}

__attribute__((used)) static inline bool ufshcd_is_hs_mode(struct ufs_pa_layer_attr *pwr_info)
{
	return (pwr_info->pwr_rx == FAST_MODE ||
		pwr_info->pwr_rx == FASTAUTO_MODE) &&
		(pwr_info->pwr_tx == FAST_MODE ||
		pwr_info->pwr_tx == FASTAUTO_MODE);
}

__attribute__((used)) static inline const char *ufshcd_get_var_name(struct ufs_hba *hba)
{
	if (hba->vops)
		return hba->vops->name;
	return "";
}

__attribute__((used)) static inline int ufshcd_vops_init(struct ufs_hba *hba)
{
	if (hba->vops && hba->vops->init)
		return hba->vops->init(hba);

	return 0;
}

__attribute__((used)) static inline void ufshcd_vops_exit(struct ufs_hba *hba)
{
	if (hba->vops && hba->vops->exit)
		return hba->vops->exit(hba);
}

__attribute__((used)) static inline u32 ufshcd_vops_get_ufs_hci_version(struct ufs_hba *hba)
{
	if (hba->vops && hba->vops->get_ufs_hci_version)
		return hba->vops->get_ufs_hci_version(hba);

	return ufshcd_readl(hba, REG_UFS_VERSION);
}

__attribute__((used)) static inline int ufshcd_vops_clk_scale_notify(struct ufs_hba *hba,
			bool up, enum ufs_notify_change_status status)
{
	if (hba->vops && hba->vops->clk_scale_notify)
		return hba->vops->clk_scale_notify(hba, up, status);
	return 0;
}

__attribute__((used)) static inline int ufshcd_vops_setup_clocks(struct ufs_hba *hba, bool on,
					enum ufs_notify_change_status status)
{
	if (hba->vops && hba->vops->setup_clocks)
		return hba->vops->setup_clocks(hba, on, status);
	return 0;
}

__attribute__((used)) static inline int ufshcd_vops_setup_regulators(struct ufs_hba *hba, bool status)
{
	if (hba->vops && hba->vops->setup_regulators)
		return hba->vops->setup_regulators(hba, status);

	return 0;
}

__attribute__((used)) static inline int ufshcd_vops_hce_enable_notify(struct ufs_hba *hba,
						bool status)
{
	if (hba->vops && hba->vops->hce_enable_notify)
		return hba->vops->hce_enable_notify(hba, status);

	return 0;
}

__attribute__((used)) static inline int ufshcd_vops_link_startup_notify(struct ufs_hba *hba,
						bool status)
{
	if (hba->vops && hba->vops->link_startup_notify)
		return hba->vops->link_startup_notify(hba, status);

	return 0;
}

__attribute__((used)) static inline int ufshcd_vops_pwr_change_notify(struct ufs_hba *hba,
				  bool status,
				  struct ufs_pa_layer_attr *dev_max_params,
				  struct ufs_pa_layer_attr *dev_req_params)
{
	if (hba->vops && hba->vops->pwr_change_notify)
		return hba->vops->pwr_change_notify(hba, status,
					dev_max_params, dev_req_params);

	return -ENOTSUPP;
}

__attribute__((used)) static inline void ufshcd_vops_setup_xfer_req(struct ufs_hba *hba, int tag,
					bool is_scsi_cmd)
{
	if (hba->vops && hba->vops->setup_xfer_req)
		return hba->vops->setup_xfer_req(hba, tag, is_scsi_cmd);
}

__attribute__((used)) static inline void ufshcd_vops_setup_task_mgmt(struct ufs_hba *hba,
					int tag, u8 tm_function)
{
	if (hba->vops && hba->vops->setup_task_mgmt)
		return hba->vops->setup_task_mgmt(hba, tag, tm_function);
}

__attribute__((used)) static inline void ufshcd_vops_hibern8_notify(struct ufs_hba *hba,
					enum uic_cmd_dme cmd,
					enum ufs_notify_change_status status)
{
	if (hba->vops && hba->vops->hibern8_notify)
		return hba->vops->hibern8_notify(hba, cmd, status);
}

__attribute__((used)) static inline int ufshcd_vops_apply_dev_quirks(struct ufs_hba *hba)
{
	if (hba->vops && hba->vops->apply_dev_quirks)
		return hba->vops->apply_dev_quirks(hba);
	return 0;
}

__attribute__((used)) static inline int ufshcd_vops_suspend(struct ufs_hba *hba, enum ufs_pm_op op)
{
	if (hba->vops && hba->vops->suspend)
		return hba->vops->suspend(hba, op);

	return 0;
}

__attribute__((used)) static inline int ufshcd_vops_resume(struct ufs_hba *hba, enum ufs_pm_op op)
{
	if (hba->vops && hba->vops->resume)
		return hba->vops->resume(hba, op);

	return 0;
}

__attribute__((used)) static inline void ufshcd_vops_dbg_register_dump(struct ufs_hba *hba)
{
	if (hba->vops && hba->vops->dbg_register_dump)
		hba->vops->dbg_register_dump(hba);
}

__attribute__((used)) static inline u8 ufshcd_scsi_to_upiu_lun(unsigned int scsi_lun)
{
	if (scsi_is_wlun(scsi_lun))
		return (scsi_lun & UFS_UPIU_MAX_UNIT_NUM_ID)
			| UFS_UPIU_WLUN_ID;
	else
		return scsi_lun & UFS_UPIU_MAX_UNIT_NUM_ID;
}

__attribute__((used)) static int tc_dwc_g210_pltfm_probe(struct platform_device *pdev)
{
	int err;
	const struct of_device_id *of_id;
	struct ufs_hba_variant_ops *vops;
	struct device *dev = &pdev->dev;

	of_id = of_match_node(tc_dwc_g210_pltfm_match, dev->of_node);
	vops = (struct ufs_hba_variant_ops *)of_id->data;

	/* Perform generic probe */
	err = ufshcd_pltfrm_init(pdev, vops);
	if (err)
		dev_err(dev, "ufshcd_pltfrm_init() failed %d\n", err);

	return err;
}

__attribute__((used)) static int tc_dwc_g210_pltfm_remove(struct platform_device *pdev)
{
	struct ufs_hba *hba =  platform_get_drvdata(pdev);

	pm_runtime_get_sync(&(pdev)->dev);
	ufshcd_remove(hba);

	return 0;
}

