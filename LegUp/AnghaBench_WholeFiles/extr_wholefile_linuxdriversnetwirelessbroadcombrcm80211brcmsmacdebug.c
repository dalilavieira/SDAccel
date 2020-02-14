#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint ;
typedef  int /*<<< orphan*/  u32 ;
struct sk_buff {int dummy; } ;
struct seq_file {struct brcms_pub* private; } ;
struct macstat {int /*<<< orphan*/  bphy_badplcp; int /*<<< orphan*/  phywatchdog; int /*<<< orphan*/  bphy_rxcrsglitch; int /*<<< orphan*/  txburst; int /*<<< orphan*/  txglitch_nack; int /*<<< orphan*/  txnack; int /*<<< orphan*/  frmscons; int /*<<< orphan*/  rxnack; int /*<<< orphan*/  prs_timeout; int /*<<< orphan*/  txcgprssuc; int /*<<< orphan*/  txcgprsfail; int /*<<< orphan*/  rxcgprsqovfl; int /*<<< orphan*/  rxcgprqfrm; int /*<<< orphan*/  pmqovfl; int /*<<< orphan*/  txsfovfl; int /*<<< orphan*/  rxf2ovfl; int /*<<< orphan*/  rxf1ovfl; int /*<<< orphan*/  rxf0ovfl; int /*<<< orphan*/  bcntxcancl; int /*<<< orphan*/  rxrsptmout; int /*<<< orphan*/  rxbeaconobss; int /*<<< orphan*/  rxdfrmucastobss; int /*<<< orphan*/  rxbeaconmbss; int /*<<< orphan*/  rxcfrmmcast; int /*<<< orphan*/  rxmfrmmcast; int /*<<< orphan*/  rxdfrmmcast; int /*<<< orphan*/  rxctsocast; int /*<<< orphan*/  rxrtsocast; int /*<<< orphan*/  rxcfrmocast; int /*<<< orphan*/  rxmfrmocast; int /*<<< orphan*/  rxdfrmocast; int /*<<< orphan*/  rxackucast; int /*<<< orphan*/  rxctsucast; int /*<<< orphan*/  rxrtsucast; int /*<<< orphan*/  rxcfrmucast; int /*<<< orphan*/  rxmfrmucastmbss; int /*<<< orphan*/  rxdfrmucastmbss; int /*<<< orphan*/  rxstrt; int /*<<< orphan*/  rxcrsglitch; int /*<<< orphan*/  rxbadplcp; int /*<<< orphan*/  rxbadfcs; int /*<<< orphan*/  rxinvmachdr; int /*<<< orphan*/  rxfrmtooshrt; int /*<<< orphan*/  rxfrmtoolong; int /*<<< orphan*/  pktengrxdmcast; int /*<<< orphan*/  pktengrxducast; int /*<<< orphan*/  txphyerr; int /*<<< orphan*/  txtplunfl; int /*<<< orphan*/ * txfunfl; int /*<<< orphan*/  txbcnfrm; int /*<<< orphan*/  txdnlfrm; int /*<<< orphan*/  txackfrm; int /*<<< orphan*/  txctsfrm; int /*<<< orphan*/  txrtsfrm; int /*<<< orphan*/  txallfrm; } ;
struct inode {struct brcms_debugfs_entry* i_private; } ;
struct file {int dummy; } ;
struct device {int dummy; } ;
struct dentry {int dummy; } ;
struct brcms_pub {struct dentry* dbgfs_dir; TYPE_8__* wlc; TYPE_6__* ieee_hw; } ;
struct brcms_info {int /*<<< orphan*/  lock; } ;
struct brcms_hardware {struct bcma_device* d11core; int /*<<< orphan*/  sromrev; TYPE_5__* band; int /*<<< orphan*/  boardflags2; int /*<<< orphan*/  boardflags; int /*<<< orphan*/  boardrev; } ;
struct brcms_debugfs_entry {int (* read ) (struct seq_file*,void*) ;struct brcms_pub* drvr; } ;
struct TYPE_10__ {int /*<<< orphan*/  rev; } ;
struct bcma_device {struct device dev; TYPE_2__ id; struct bcma_bus* bus; } ;
struct TYPE_11__ {int /*<<< orphan*/  vendor; int /*<<< orphan*/  type; } ;
struct TYPE_9__ {int /*<<< orphan*/  pkg; int /*<<< orphan*/  rev; int /*<<< orphan*/  id; } ;
struct bcma_bus {TYPE_3__ boardinfo; TYPE_1__ chipinfo; } ;
struct TYPE_16__ {struct brcms_hardware* hw; TYPE_7__* core; int /*<<< orphan*/  ucode_rev; } ;
struct TYPE_15__ {struct macstat* macstat_snapshot; } ;
struct TYPE_14__ {struct brcms_info* priv; } ;
struct TYPE_13__ {TYPE_4__* pi; int /*<<< orphan*/  phyrev; int /*<<< orphan*/  phytype; int /*<<< orphan*/  radiorev; } ;
struct TYPE_12__ {int /*<<< orphan*/  ana_rev; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int BRCMU_BOARDREV_LEN ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct dentry*) ; 
 scalar_t__ IS_ERR_OR_NULL (struct dentry*) ; 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int PTR_ERR_OR_ZERO (struct dentry*) ; 
 int /*<<< orphan*/  brcms_debugfs_def_ops ; 
 int /*<<< orphan*/  brcmu_boardrev_str (int /*<<< orphan*/ ,char*) ; 
 void* debugfs_create_dir (int /*<<< orphan*/ ,struct dentry*) ; 
 struct dentry* debugfs_create_file (char const*,int,struct dentry*,struct brcms_debugfs_entry*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debugfs_remove_recursive (struct dentry*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct brcms_debugfs_entry* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct dentry* root_folder ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),struct brcms_pub*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void dma_spin_for_len(uint len, struct sk_buff *head)
{
#if defined(CONFIG_BCM47XX)
	if (!len) {
		while (!(len = *(u16 *) KSEG1ADDR(head->data)))
			udelay(1);

		*(u16 *) (head->data) = cpu_to_le16((u16) len);
	}
#endif				/* defined(CONFIG_BCM47XX) */
}

__attribute__((used)) static inline void brcms_led_unregister(struct brcms_info *wl) {}

__attribute__((used)) static inline int brcms_led_register(struct brcms_info *wl)
{
	return -ENOTSUPP;
}

void __brcms_dbg(struct device *dev, u32 level, const char *func,
		 const char *fmt, ...)
{
}

void brcms_debugfs_init(void)
{
	root_folder = debugfs_create_dir(KBUILD_MODNAME, NULL);
	if (IS_ERR(root_folder))
		root_folder = NULL;
}

void brcms_debugfs_exit(void)
{
	if (!root_folder)
		return;

	debugfs_remove_recursive(root_folder);
	root_folder = NULL;
}

int brcms_debugfs_attach(struct brcms_pub *drvr)
{
	if (!root_folder)
		return -ENODEV;

	drvr->dbgfs_dir = debugfs_create_dir(
		 dev_name(&drvr->wlc->hw->d11core->dev), root_folder);
	return PTR_ERR_OR_ZERO(drvr->dbgfs_dir);
}

void brcms_debugfs_detach(struct brcms_pub *drvr)
{
	if (!IS_ERR_OR_NULL(drvr->dbgfs_dir))
		debugfs_remove_recursive(drvr->dbgfs_dir);
}

struct dentry *brcms_debugfs_get_devdir(struct brcms_pub *drvr)
{
	return drvr->dbgfs_dir;
}

__attribute__((used)) static
int brcms_debugfs_hardware_read(struct seq_file *s, void *data)
{
	struct brcms_pub *drvr = s->private;
	struct brcms_hardware *hw = drvr->wlc->hw;
	struct bcma_device *core = hw->d11core;
	struct bcma_bus *bus = core->bus;
	char boardrev[BRCMU_BOARDREV_LEN];

	seq_printf(s, "chipnum 0x%x\n"
		   "chiprev 0x%x\n"
		   "chippackage 0x%x\n"
		   "corerev 0x%x\n"
		   "boardid 0x%x\n"
		   "boardvendor 0x%x\n"
		   "boardrev %s\n"
		   "boardflags 0x%x\n"
		   "boardflags2 0x%x\n"
		   "ucoderev 0x%x\n"
		   "radiorev 0x%x\n"
		   "phytype 0x%x\n"
		   "phyrev 0x%x\n"
		   "anarev 0x%x\n"
		   "nvramrev %d\n",
		   bus->chipinfo.id, bus->chipinfo.rev, bus->chipinfo.pkg,
		   core->id.rev, bus->boardinfo.type, bus->boardinfo.vendor,
		   brcmu_boardrev_str(hw->boardrev, boardrev),
		   drvr->wlc->hw->boardflags, drvr->wlc->hw->boardflags2,
		   drvr->wlc->ucode_rev, hw->band->radiorev,
		   hw->band->phytype, hw->band->phyrev, hw->band->pi->ana_rev,
		   hw->sromrev);
	return 0;
}

__attribute__((used)) static int brcms_debugfs_macstat_read(struct seq_file *s, void *data)
{
	struct brcms_pub *drvr = s->private;
	struct brcms_info *wl = drvr->ieee_hw->priv;
	struct macstat stats;
	int i;

	spin_lock_bh(&wl->lock);
	stats = *(drvr->wlc->core->macstat_snapshot);
	spin_unlock_bh(&wl->lock);

	seq_printf(s, "txallfrm: %d\n", stats.txallfrm);
	seq_printf(s, "txrtsfrm: %d\n", stats.txrtsfrm);
	seq_printf(s, "txctsfrm: %d\n", stats.txctsfrm);
	seq_printf(s, "txackfrm: %d\n", stats.txackfrm);
	seq_printf(s, "txdnlfrm: %d\n", stats.txdnlfrm);
	seq_printf(s, "txbcnfrm: %d\n", stats.txbcnfrm);
	seq_printf(s, "txfunfl[8]:");
	for (i = 0; i < ARRAY_SIZE(stats.txfunfl); i++)
		seq_printf(s, " %d", stats.txfunfl[i]);
	seq_printf(s, "\ntxtplunfl: %d\n", stats.txtplunfl);
	seq_printf(s, "txphyerr: %d\n", stats.txphyerr);
	seq_printf(s, "pktengrxducast: %d\n", stats.pktengrxducast);
	seq_printf(s, "pktengrxdmcast: %d\n", stats.pktengrxdmcast);
	seq_printf(s, "rxfrmtoolong: %d\n", stats.rxfrmtoolong);
	seq_printf(s, "rxfrmtooshrt: %d\n", stats.rxfrmtooshrt);
	seq_printf(s, "rxinvmachdr: %d\n", stats.rxinvmachdr);
	seq_printf(s, "rxbadfcs: %d\n", stats.rxbadfcs);
	seq_printf(s, "rxbadplcp: %d\n", stats.rxbadplcp);
	seq_printf(s, "rxcrsglitch: %d\n", stats.rxcrsglitch);
	seq_printf(s, "rxstrt: %d\n", stats.rxstrt);
	seq_printf(s, "rxdfrmucastmbss: %d\n", stats.rxdfrmucastmbss);
	seq_printf(s, "rxmfrmucastmbss: %d\n", stats.rxmfrmucastmbss);
	seq_printf(s, "rxcfrmucast: %d\n", stats.rxcfrmucast);
	seq_printf(s, "rxrtsucast: %d\n", stats.rxrtsucast);
	seq_printf(s, "rxctsucast: %d\n", stats.rxctsucast);
	seq_printf(s, "rxackucast: %d\n", stats.rxackucast);
	seq_printf(s, "rxdfrmocast: %d\n", stats.rxdfrmocast);
	seq_printf(s, "rxmfrmocast: %d\n", stats.rxmfrmocast);
	seq_printf(s, "rxcfrmocast: %d\n", stats.rxcfrmocast);
	seq_printf(s, "rxrtsocast: %d\n", stats.rxrtsocast);
	seq_printf(s, "rxctsocast: %d\n", stats.rxctsocast);
	seq_printf(s, "rxdfrmmcast: %d\n", stats.rxdfrmmcast);
	seq_printf(s, "rxmfrmmcast: %d\n", stats.rxmfrmmcast);
	seq_printf(s, "rxcfrmmcast: %d\n", stats.rxcfrmmcast);
	seq_printf(s, "rxbeaconmbss: %d\n", stats.rxbeaconmbss);
	seq_printf(s, "rxdfrmucastobss: %d\n", stats.rxdfrmucastobss);
	seq_printf(s, "rxbeaconobss: %d\n", stats.rxbeaconobss);
	seq_printf(s, "rxrsptmout: %d\n", stats.rxrsptmout);
	seq_printf(s, "bcntxcancl: %d\n", stats.bcntxcancl);
	seq_printf(s, "rxf0ovfl: %d\n", stats.rxf0ovfl);
	seq_printf(s, "rxf1ovfl: %d\n", stats.rxf1ovfl);
	seq_printf(s, "rxf2ovfl: %d\n", stats.rxf2ovfl);
	seq_printf(s, "txsfovfl: %d\n", stats.txsfovfl);
	seq_printf(s, "pmqovfl: %d\n", stats.pmqovfl);
	seq_printf(s, "rxcgprqfrm: %d\n", stats.rxcgprqfrm);
	seq_printf(s, "rxcgprsqovfl: %d\n", stats.rxcgprsqovfl);
	seq_printf(s, "txcgprsfail: %d\n", stats.txcgprsfail);
	seq_printf(s, "txcgprssuc: %d\n", stats.txcgprssuc);
	seq_printf(s, "prs_timeout: %d\n", stats.prs_timeout);
	seq_printf(s, "rxnack: %d\n", stats.rxnack);
	seq_printf(s, "frmscons: %d\n", stats.frmscons);
	seq_printf(s, "txnack: %d\n", stats.txnack);
	seq_printf(s, "txglitch_nack: %d\n", stats.txglitch_nack);
	seq_printf(s, "txburst: %d\n", stats.txburst);
	seq_printf(s, "bphy_rxcrsglitch: %d\n", stats.bphy_rxcrsglitch);
	seq_printf(s, "phywatchdog: %d\n", stats.phywatchdog);
	seq_printf(s, "bphy_badplcp: %d\n", stats.bphy_badplcp);
	return 0;
}

__attribute__((used)) static int brcms_debugfs_entry_open(struct inode *inode, struct file *f)
{
	struct brcms_debugfs_entry *entry = inode->i_private;

	return single_open(f, entry->read, entry->drvr);
}

__attribute__((used)) static int
brcms_debugfs_add_entry(struct brcms_pub *drvr, const char *fn,
			int (*read_fn)(struct seq_file *seq, void *data))
{
	struct device *dev = &drvr->wlc->hw->d11core->dev;
	struct dentry *dentry =  drvr->dbgfs_dir;
	struct brcms_debugfs_entry *entry;

	if (IS_ERR_OR_NULL(dentry))
		return -ENOENT;

	entry = devm_kzalloc(dev, sizeof(*entry), GFP_KERNEL);
	if (!entry)
		return -ENOMEM;

	entry->read = read_fn;
	entry->drvr = drvr;

	dentry = debugfs_create_file(fn, 0444, dentry, entry,
				     &brcms_debugfs_def_ops);

	return PTR_ERR_OR_ZERO(dentry);
}

void brcms_debugfs_create_files(struct brcms_pub *drvr)
{
	if (IS_ERR_OR_NULL(drvr->dbgfs_dir))
		return;

	brcms_debugfs_add_entry(drvr, "hardware", brcms_debugfs_hardware_read);
	brcms_debugfs_add_entry(drvr, "macstat", brcms_debugfs_macstat_read);
}

