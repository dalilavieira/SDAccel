#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int sec_err; int ded_err; scalar_t__ intr_sec_ena; scalar_t__ intr_ded_ena; int /*<<< orphan*/  ecc_ena; } ;
union cvmx_lmcx_mem_cfg0 {void* u64; TYPE_6__ s; } ;
struct TYPE_10__ {scalar_t__ intr_sec_ena; scalar_t__ intr_ded_ena; } ;
union cvmx_lmcx_int_en {void* u64; TYPE_4__ s; } ;
struct TYPE_8__ {int sec_err; int ded_err; } ;
union cvmx_lmcx_int {void* u64; TYPE_2__ s; } ;
struct TYPE_7__ {int fdimm; int fbunk; int fbank; int frow; int fcol; } ;
struct TYPE_11__ {int fdimm; int fbunk; int fbank; int frow; int fcol; } ;
union cvmx_lmcx_fadr {TYPE_1__ cn61xx; void* u64; TYPE_5__ cn30xx; } ;
struct TYPE_9__ {int /*<<< orphan*/  ecc_ena; } ;
union cvmx_lmcx_config {TYPE_3__ s; void* u64; } ;
typedef  int /*<<< orphan*/  umode_t ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct platform_device {int id; int /*<<< orphan*/  dev; } ;
struct octeon_lmc_pvt {int error_type; int dimm; int rank; int bank; int row; int col; scalar_t__ inject; } ;
struct mem_ctl_info {int mc_idx; char* mod_name; char* ctl_name; void (* edac_check ) (struct mem_ctl_info*) ;void* dev_name; int /*<<< orphan*/ * pdev; struct octeon_lmc_pvt* pvt_info; } ;
struct file_operations {int dummy; } ;
struct edac_mc_layer {int size; int is_virt_csrow; int /*<<< orphan*/  type; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct dentry {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  msg ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (struct edac_mc_layer*) ; 
 int /*<<< orphan*/  CVMX_LMCX_CONFIG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CVMX_LMCX_FADR (int) ; 
 int /*<<< orphan*/  CVMX_LMCX_INT (int) ; 
 int /*<<< orphan*/  CVMX_LMCX_MEM_CFG0 (int) ; 
 int /*<<< orphan*/  EDAC_MC_LAYER_CHANNEL ; 
 int ENODEV ; 
 int ENXIO ; 
 int /*<<< orphan*/  HW_EVENT_ERR_CORRECTED ; 
 int /*<<< orphan*/  HW_EVENT_ERR_UNCORRECTED ; 
 scalar_t__ OCTEON_IS_OCTEON1PLUS () ; 
 void* cvmx_read_csr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_write_csr (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 void* dev_name (int /*<<< orphan*/ *) ; 
 scalar_t__ edac_mc_add_mc_with_groups (struct mem_ctl_info*,int /*<<< orphan*/ ) ; 
 struct mem_ctl_info* edac_mc_alloc (int,int /*<<< orphan*/ ,struct edac_mc_layer*,int) ; 
 int /*<<< orphan*/  edac_mc_del_mc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  edac_mc_free (struct mem_ctl_info*) ; 
 int /*<<< orphan*/  edac_mc_handle_error (int /*<<< orphan*/ ,struct mem_ctl_info*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,char*,char*) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  octeon_dev_groups ; 
 int /*<<< orphan*/  opstate_init () ; 
 struct mem_ctl_info* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mem_ctl_info*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int,int,int,int,int) ; 
 size_t sprintf (char*,char*) ; 
 int /*<<< orphan*/  strncmp (char const*,char*,int) ; 
 struct mem_ctl_info* to_mci (struct device*) ; 

__attribute__((used)) static inline int edac_debugfs_init(void)					{ return -ENODEV; }

__attribute__((used)) static inline void edac_debugfs_exit(void)					{ }

__attribute__((used)) static inline int edac_create_debugfs_nodes(struct mem_ctl_info *mci)		{ return 0; }

__attribute__((used)) static inline struct dentry *edac_debugfs_create_dir(const char *dirname)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_dir_at(const char *dirname, struct dentry *parent)		{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_file(const char *name, umode_t mode, struct dentry *parent,
			 void *data, const struct file_operations *fops)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x8(const char *name, umode_t mode,
		       struct dentry *parent, u8 *value)			{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x16(const char *name, umode_t mode,
		       struct dentry *parent, u16 *value)			{ return NULL; }

__attribute__((used)) static void octeon_lmc_edac_poll(struct mem_ctl_info *mci)
{
	union cvmx_lmcx_mem_cfg0 cfg0;
	bool do_clear = false;
	char msg[64];

	cfg0.u64 = cvmx_read_csr(CVMX_LMCX_MEM_CFG0(mci->mc_idx));
	if (cfg0.s.sec_err || cfg0.s.ded_err) {
		union cvmx_lmcx_fadr fadr;
		fadr.u64 = cvmx_read_csr(CVMX_LMCX_FADR(mci->mc_idx));
		snprintf(msg, sizeof(msg),
			 "DIMM %d rank %d bank %d row %d col %d",
			 fadr.cn30xx.fdimm, fadr.cn30xx.fbunk,
			 fadr.cn30xx.fbank, fadr.cn30xx.frow, fadr.cn30xx.fcol);
	}

	if (cfg0.s.sec_err) {
		edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1, 0, 0, 0,
				     -1, -1, -1, msg, "");
		cfg0.s.sec_err = -1;	/* Done, re-arm */
		do_clear = true;
	}

	if (cfg0.s.ded_err) {
		edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
				     -1, -1, -1, msg, "");
		cfg0.s.ded_err = -1;	/* Done, re-arm */
		do_clear = true;
	}
	if (do_clear)
		cvmx_write_csr(CVMX_LMCX_MEM_CFG0(mci->mc_idx), cfg0.u64);
}

__attribute__((used)) static void octeon_lmc_edac_poll_o2(struct mem_ctl_info *mci)
{
	struct octeon_lmc_pvt *pvt = mci->pvt_info;
	union cvmx_lmcx_int int_reg;
	bool do_clear = false;
	char msg[64];

	if (!pvt->inject)
		int_reg.u64 = cvmx_read_csr(CVMX_LMCX_INT(mci->mc_idx));
	else {
		int_reg.u64 = 0;
		if (pvt->error_type == 1)
			int_reg.s.sec_err = 1;
		if (pvt->error_type == 2)
			int_reg.s.ded_err = 1;
	}

	if (int_reg.s.sec_err || int_reg.s.ded_err) {
		union cvmx_lmcx_fadr fadr;
		if (likely(!pvt->inject))
			fadr.u64 = cvmx_read_csr(CVMX_LMCX_FADR(mci->mc_idx));
		else {
			fadr.cn61xx.fdimm = pvt->dimm;
			fadr.cn61xx.fbunk = pvt->rank;
			fadr.cn61xx.fbank = pvt->bank;
			fadr.cn61xx.frow = pvt->row;
			fadr.cn61xx.fcol = pvt->col;
		}
		snprintf(msg, sizeof(msg),
			 "DIMM %d rank %d bank %d row %d col %d",
			 fadr.cn61xx.fdimm, fadr.cn61xx.fbunk,
			 fadr.cn61xx.fbank, fadr.cn61xx.frow, fadr.cn61xx.fcol);
	}

	if (int_reg.s.sec_err) {
		edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1, 0, 0, 0,
				     -1, -1, -1, msg, "");
		int_reg.s.sec_err = -1;	/* Done, re-arm */
		do_clear = true;
	}

	if (int_reg.s.ded_err) {
		edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
				     -1, -1, -1, msg, "");
		int_reg.s.ded_err = -1;	/* Done, re-arm */
		do_clear = true;
	}

	if (do_clear) {
		if (likely(!pvt->inject))
			cvmx_write_csr(CVMX_LMCX_INT(mci->mc_idx), int_reg.u64);
		else
			pvt->inject = 0;
	}
}

__attribute__((used)) static ssize_t octeon_mc_inject_error_type_store(struct device *dev,
					  struct device_attribute *attr,
					  const char *data,
					  size_t count)
{
	struct mem_ctl_info *mci = to_mci(dev);
	struct octeon_lmc_pvt *pvt = mci->pvt_info;

	if (!strncmp(data, "single", 6))
		pvt->error_type = 1;
	else if (!strncmp(data, "double", 6))
		pvt->error_type = 2;

	return count;
}

__attribute__((used)) static ssize_t octeon_mc_inject_error_type_show(struct device *dev,
					 struct device_attribute *attr,
					 char *data)
{
	struct mem_ctl_info *mci = to_mci(dev);
	struct octeon_lmc_pvt *pvt = mci->pvt_info;
	if (pvt->error_type == 1)
		return sprintf(data, "single");
	else if (pvt->error_type == 2)
		return sprintf(data, "double");

	return 0;
}

__attribute__((used)) static int octeon_lmc_edac_probe(struct platform_device *pdev)
{
	struct mem_ctl_info *mci;
	struct edac_mc_layer layers[1];
	int mc = pdev->id;

	opstate_init();

	layers[0].type = EDAC_MC_LAYER_CHANNEL;
	layers[0].size = 1;
	layers[0].is_virt_csrow = false;

	if (OCTEON_IS_OCTEON1PLUS()) {
		union cvmx_lmcx_mem_cfg0 cfg0;

		cfg0.u64 = cvmx_read_csr(CVMX_LMCX_MEM_CFG0(0));
		if (!cfg0.s.ecc_ena) {
			dev_info(&pdev->dev, "Disabled (ECC not enabled)\n");
			return 0;
		}

		mci = edac_mc_alloc(mc, ARRAY_SIZE(layers), layers, sizeof(struct octeon_lmc_pvt));
		if (!mci)
			return -ENXIO;

		mci->pdev = &pdev->dev;
		mci->dev_name = dev_name(&pdev->dev);

		mci->mod_name = "octeon-lmc";
		mci->ctl_name = "octeon-lmc-err";
		mci->edac_check = octeon_lmc_edac_poll;

		if (edac_mc_add_mc_with_groups(mci, octeon_dev_groups)) {
			dev_err(&pdev->dev, "edac_mc_add_mc() failed\n");
			edac_mc_free(mci);
			return -ENXIO;
		}

		cfg0.u64 = cvmx_read_csr(CVMX_LMCX_MEM_CFG0(mc));
		cfg0.s.intr_ded_ena = 0;	/* We poll */
		cfg0.s.intr_sec_ena = 0;
		cvmx_write_csr(CVMX_LMCX_MEM_CFG0(mc), cfg0.u64);
	} else {
		/* OCTEON II */
		union cvmx_lmcx_int_en en;
		union cvmx_lmcx_config config;

		config.u64 = cvmx_read_csr(CVMX_LMCX_CONFIG(0));
		if (!config.s.ecc_ena) {
			dev_info(&pdev->dev, "Disabled (ECC not enabled)\n");
			return 0;
		}

		mci = edac_mc_alloc(mc, ARRAY_SIZE(layers), layers, sizeof(struct octeon_lmc_pvt));
		if (!mci)
			return -ENXIO;

		mci->pdev = &pdev->dev;
		mci->dev_name = dev_name(&pdev->dev);

		mci->mod_name = "octeon-lmc";
		mci->ctl_name = "co_lmc_err";
		mci->edac_check = octeon_lmc_edac_poll_o2;

		if (edac_mc_add_mc_with_groups(mci, octeon_dev_groups)) {
			dev_err(&pdev->dev, "edac_mc_add_mc() failed\n");
			edac_mc_free(mci);
			return -ENXIO;
		}

		en.u64 = cvmx_read_csr(CVMX_LMCX_MEM_CFG0(mc));
		en.s.intr_ded_ena = 0;	/* We poll */
		en.s.intr_sec_ena = 0;
		cvmx_write_csr(CVMX_LMCX_MEM_CFG0(mc), en.u64);
	}
	platform_set_drvdata(pdev, mci);

	return 0;
}

__attribute__((used)) static int octeon_lmc_edac_remove(struct platform_device *pdev)
{
	struct mem_ctl_info *mci = platform_get_drvdata(pdev);

	edac_mc_del_mc(&pdev->dev);
	edac_mc_free(mci);
	return 0;
}

