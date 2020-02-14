#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  umode_t ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int u64 ;
typedef  int /*<<< orphan*/  u16 ;
struct pci_dev {int dummy; } ;
struct mem_ctl_info {int /*<<< orphan*/  mc_idx; int /*<<< orphan*/  pdev; struct ie31200_priv* pvt_info; } ;
struct ie31200_priv {int /*<<< orphan*/  c1errlog; int /*<<< orphan*/  c0errlog; } ;
struct ie31200_error_info {int errsts; int* eccerrlog; int errsts2; } ;
struct file_operations {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  HW_EVENT_ERR_CORRECTED ; 
 int /*<<< orphan*/  HW_EVENT_ERR_UNCORRECTED ; 
 scalar_t__ IE31200_CAPID0 ; 
 unsigned char IE31200_CAPID0_DDPCD ; 
 unsigned char IE31200_CAPID0_ECC ; 
 unsigned char IE31200_CAPID0_PDCD ; 
 int IE31200_ECCERRLOG_CE ; 
 int IE31200_ECCERRLOG_RANK_BITS ; 
 int IE31200_ECCERRLOG_RANK_SHIFT ; 
 int /*<<< orphan*/  IE31200_ECCERRLOG_SYNDROME (int) ; 
 int IE31200_ECCERRLOG_UE ; 
 int /*<<< orphan*/  IE31200_ERRSTS ; 
 int IE31200_ERRSTS_BITS ; 
 int /*<<< orphan*/  edac_dbg (int,char*,...) ; 
 int /*<<< orphan*/  edac_mc_handle_error (int /*<<< orphan*/ ,struct mem_ctl_info*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,char*,char*) ; 
 void* lo_hi_readq (int /*<<< orphan*/ ) ; 
 int nr_channels ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,scalar_t__,unsigned char*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_write_bits16 (struct pci_dev*,int /*<<< orphan*/ ,int,int) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static int how_many_channels(struct pci_dev *pdev)
{
	int n_channels;
	unsigned char capid0_2b; /* 2nd byte of CAPID0 */

	pci_read_config_byte(pdev, IE31200_CAPID0 + 1, &capid0_2b);

	/* check PDCD: Dual Channel Disable */
	if (capid0_2b & IE31200_CAPID0_PDCD) {
		edac_dbg(0, "In single channel mode\n");
		n_channels = 1;
	} else {
		edac_dbg(0, "In dual channel mode\n");
		n_channels = 2;
	}

	/* check DDPCD - check if both channels are filled */
	if (capid0_2b & IE31200_CAPID0_DDPCD)
		edac_dbg(0, "2 DIMMS per channel disabled\n");
	else
		edac_dbg(0, "2 DIMMS per channel enabled\n");

	return n_channels;
}

__attribute__((used)) static bool ecc_capable(struct pci_dev *pdev)
{
	unsigned char capid0_4b; /* 4th byte of CAPID0 */

	pci_read_config_byte(pdev, IE31200_CAPID0 + 3, &capid0_4b);
	if (capid0_4b & IE31200_CAPID0_ECC)
		return false;
	return true;
}

__attribute__((used)) static int eccerrlog_row(u64 log)
{
	return ((log & IE31200_ECCERRLOG_RANK_BITS) >>
				IE31200_ECCERRLOG_RANK_SHIFT);
}

__attribute__((used)) static void ie31200_clear_error_info(struct mem_ctl_info *mci)
{
	/*
	 * Clear any error bits.
	 * (Yes, we really clear bits by writing 1 to them.)
	 */
	pci_write_bits16(to_pci_dev(mci->pdev), IE31200_ERRSTS,
			 IE31200_ERRSTS_BITS, IE31200_ERRSTS_BITS);
}

__attribute__((used)) static void ie31200_get_and_clear_error_info(struct mem_ctl_info *mci,
					     struct ie31200_error_info *info)
{
	struct pci_dev *pdev;
	struct ie31200_priv *priv = mci->pvt_info;

	pdev = to_pci_dev(mci->pdev);

	/*
	 * This is a mess because there is no atomic way to read all the
	 * registers at once and the registers can transition from CE being
	 * overwritten by UE.
	 */
	pci_read_config_word(pdev, IE31200_ERRSTS, &info->errsts);
	if (!(info->errsts & IE31200_ERRSTS_BITS))
		return;

	info->eccerrlog[0] = lo_hi_readq(priv->c0errlog);
	if (nr_channels == 2)
		info->eccerrlog[1] = lo_hi_readq(priv->c1errlog);

	pci_read_config_word(pdev, IE31200_ERRSTS, &info->errsts2);

	/*
	 * If the error is the same for both reads then the first set
	 * of reads is valid.  If there is a change then there is a CE
	 * with no info and the second set of reads is valid and
	 * should be UE info.
	 */
	if ((info->errsts ^ info->errsts2) & IE31200_ERRSTS_BITS) {
		info->eccerrlog[0] = lo_hi_readq(priv->c0errlog);
		if (nr_channels == 2)
			info->eccerrlog[1] =
				lo_hi_readq(priv->c1errlog);
	}

	ie31200_clear_error_info(mci);
}

__attribute__((used)) static void ie31200_process_error_info(struct mem_ctl_info *mci,
				       struct ie31200_error_info *info)
{
	int channel;
	u64 log;

	if (!(info->errsts & IE31200_ERRSTS_BITS))
		return;

	if ((info->errsts ^ info->errsts2) & IE31200_ERRSTS_BITS) {
		edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
				     -1, -1, -1, "UE overwrote CE", "");
		info->errsts = info->errsts2;
	}

	for (channel = 0; channel < nr_channels; channel++) {
		log = info->eccerrlog[channel];
		if (log & IE31200_ECCERRLOG_UE) {
			edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
					     0, 0, 0,
					     eccerrlog_row(log),
					     channel, -1,
					     "ie31200 UE", "");
		} else if (log & IE31200_ECCERRLOG_CE) {
			edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
					     0, 0,
					     IE31200_ECCERRLOG_SYNDROME(log),
					     eccerrlog_row(log),
					     channel, -1,
					     "ie31200 CE", "");
		}
	}
}

__attribute__((used)) static void ie31200_check(struct mem_ctl_info *mci)
{
	struct ie31200_error_info info;

	edac_dbg(1, "MC%d\n", mci->mc_idx);
	ie31200_get_and_clear_error_info(mci, &info);
	ie31200_process_error_info(mci, &info);
}

