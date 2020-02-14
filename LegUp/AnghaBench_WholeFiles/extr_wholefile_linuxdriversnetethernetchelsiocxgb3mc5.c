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
typedef  int u32 ;
struct TYPE_7__ {int (* mdio_read ) (int /*<<< orphan*/ ,int,int,int) ;int prtad; int (* mdio_write ) (int /*<<< orphan*/ ,int,int,int,unsigned int) ;int /*<<< orphan*/  mode_support; int /*<<< orphan*/  mmds; int /*<<< orphan*/  dev; } ;
struct cphy {unsigned int caps; char const* desc; struct adapter* adapter; TYPE_1__ mdio; struct cphy_ops const* ops; } ;
struct port_info {struct cphy phy; } ;
struct mdio_ops {int (* read ) (int /*<<< orphan*/ ,int,int,int) ;int (* write ) (int /*<<< orphan*/ ,int,int,int,unsigned int) ;int /*<<< orphan*/  mode_support; } ;
struct mc7 {unsigned int size; } ;
struct TYPE_11__ {int /*<<< orphan*/  del_act_empty; int /*<<< orphan*/  unknown_cmd; int /*<<< orphan*/  nfa_srch_err; int /*<<< orphan*/  active_rgn_full; int /*<<< orphan*/  dispq_parity_err; int /*<<< orphan*/  reqq_parity_err; int /*<<< orphan*/  parity_err; } ;
struct mc5 {unsigned int tcam_size; int mode; int parity_enabled; int part_type; struct adapter* adapter; TYPE_5__ stats; } ;
struct cphy_ops {int /*<<< orphan*/  mmds; } ;
struct TYPE_9__ {scalar_t__ variant; } ;
struct TYPE_8__ {int cclk; } ;
struct TYPE_10__ {int offload; scalar_t__ rev; TYPE_3__ pci; TYPE_2__ vpd; } ;
struct adapter {int regs; TYPE_4__ params; int /*<<< orphan*/  open_device_map; int /*<<< orphan*/ * port; } ;
struct TYPE_12__ {int caps; } ;

/* Variables and functions */
 int A_MC5_DB_ACK_LRN_CMD ; 
 int A_MC5_DB_ACK_SRCH_CMD ; 
 int A_MC5_DB_AOPEN_LRN_CMD ; 
 int A_MC5_DB_AOPEN_SRCH_CMD ; 
 int A_MC5_DB_CONFIG ; 
 int A_MC5_DB_DATA_READ_CMD ; 
 int A_MC5_DB_DATA_WRITE_CMD ; 
 int A_MC5_DB_DBGI_CONFIG ; 
 int A_MC5_DB_DBGI_REQ_ADDR0 ; 
 int A_MC5_DB_DBGI_REQ_ADDR1 ; 
 int A_MC5_DB_DBGI_REQ_ADDR2 ; 
 int A_MC5_DB_DBGI_REQ_CMD ; 
 int A_MC5_DB_DBGI_REQ_DATA0 ; 
 int A_MC5_DB_DBGI_REQ_DATA1 ; 
 int A_MC5_DB_DBGI_REQ_DATA2 ; 
 int A_MC5_DB_DBGI_RSP_STATUS ; 
 int A_MC5_DB_ELOOKUP_CMD ; 
 int A_MC5_DB_FILTER_TABLE ; 
 int A_MC5_DB_ILOOKUP_CMD ; 
 int A_MC5_DB_INT_CAUSE ; 
 int A_MC5_DB_PART_ID_INDEX ; 
 int A_MC5_DB_POPEN_DATA_WR_CMD ; 
 int A_MC5_DB_POPEN_MASK_WR_CMD ; 
 int A_MC5_DB_ROUTING_TABLE_INDEX ; 
 int A_MC5_DB_RSP_LATENCY ; 
 int A_MC5_DB_SERVER_INDEX ; 
 int A_MC5_DB_SYN_LRN_CMD ; 
 int A_MC5_DB_SYN_SRCH_CMD ; 
 int /*<<< orphan*/  CH_ALERT (struct adapter*,char*) ; 
 int /*<<< orphan*/  CH_DBG (struct adapter*,int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  CH_ERR (struct adapter*,char*,...) ; 
 int DBGI_MODE_IDT52100 ; 
 int EINVAL ; 
 int EIO ; 
 int F_ACTRGNFULL ; 
 int F_DBGIEN ; 
 int F_DBGIRSPVALID ; 
 int F_DELACTEMPTY ; 
 int F_DISPQPARERR ; 
 int F_MBUSEN ; 
 int F_NFASRCHFAIL ; 
 int F_PARITYERR ; 
 int F_REQQPARERR ; 
 int F_TMMODE ; 
 int F_TMRDY ; 
 int F_TMRST ; 
 int F_TMTYPEHI ; 
 int F_UNKNOWNCMD ; 
 size_t G_TMPARTSIZE (int) ; 
 scalar_t__ G_TMTYPE (int) ; 
 int IDT4_CMD_READ ; 
 int IDT4_CMD_SEARCH144 ; 
 int IDT4_CMD_WRITE ; 
 int IDT4_DATARY_BASE_ADR0 ; 
 int IDT4_GMR_BASE0 ; 
 int IDT4_GMR_BASE1 ; 
 int IDT4_GMR_BASE2 ; 
 int IDT4_MSKARY_BASE_ADR0 ; 
 int IDT4_SCR_ADR0 ; 
#define  IDT75N43102 129 
#define  IDT75P52100 128 
 int IDT_CMD_LEARN ; 
 int IDT_CMD_READ ; 
 int IDT_CMD_SEARCH ; 
 int IDT_CMD_WRITE ; 
 int IDT_DATARY_BASE_ADR0 ; 
 int IDT_GMR_BASE_ADR0 ; 
 int IDT_LAR_ADR0 ; 
 int IDT_LAR_MODE144 ; 
 int IDT_MSKARY_BASE_ADR0 ; 
 int IDT_SCR_ADR0 ; 
 int IDT_SSR0_ADR0 ; 
 int IDT_SSR1_ADR0 ; 
 unsigned int MAX_ROUTES ; 
 int MAX_WRITE_ATTEMPTS ; 
 int MC5_INT_FATAL ; 
 int MC5_MODE_144_BIT ; 
 scalar_t__ MC5_MODE_72_BIT ; 
 int /*<<< orphan*/  MMIO ; 
 int /*<<< orphan*/  OFFLOAD_DEVMAP_BIT ; 
 scalar_t__ PCI_VARIANT_PCIE ; 
 int SUPPORTED_10000baseT_Full ; 
 int SUPPORTED_AUI ; 
 int V_COMPEN (int) ; 
 int V_LRNLAT (int) ; 
 int V_PRTYEN (int) ; 
 int V_RDLAT (int) ; 
 int V_SRCHLAT (int) ; 
 int V_TMMODE (int) ; 
 TYPE_6__* adapter_info (struct adapter const*) ; 
 struct port_info* netdev_priv (int /*<<< orphan*/ ) ; 
 int readl (int) ; 
 int stub1 (int /*<<< orphan*/ ,int,int,int) ; 
 int stub2 (int /*<<< orphan*/ ,int,int,int,unsigned int) ; 
 int /*<<< orphan*/  t3_fatal_err (struct adapter*) ; 
 int t3_wait_op_done_val (struct adapter*,int,int,int,int,int,int /*<<< orphan*/ *) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static inline unsigned int t3_mc5_size(const struct mc5 *p)
{
	return p->tcam_size;
}

__attribute__((used)) static inline unsigned int t3_mc7_size(const struct mc7 *p)
{
	return p->size;
}

__attribute__((used)) static inline int t3_mdio_read(struct cphy *phy, int mmd, int reg,
			       unsigned int *valp)
{
	int rc = phy->mdio.mdio_read(phy->mdio.dev, phy->mdio.prtad, mmd, reg);
	*valp = (rc >= 0) ? rc : -1;
	return (rc >= 0) ? 0 : rc;
}

__attribute__((used)) static inline int t3_mdio_write(struct cphy *phy, int mmd, int reg,
				unsigned int val)
{
	return phy->mdio.mdio_write(phy->mdio.dev, phy->mdio.prtad, mmd,
				    reg, val);
}

__attribute__((used)) static inline void cphy_init(struct cphy *phy, struct adapter *adapter,
			     int phy_addr, const struct cphy_ops *phy_ops,
			     const struct mdio_ops *mdio_ops,
			      unsigned int caps, const char *desc)
{
	phy->caps = caps;
	phy->adapter = adapter;
	phy->desc = desc;
	phy->ops = phy_ops;
	if (mdio_ops) {
		phy->mdio.prtad = phy_addr;
		phy->mdio.mmds = phy_ops->mmds;
		phy->mdio.mode_support = mdio_ops->mode_support;
		phy->mdio.mdio_read = mdio_ops->read;
		phy->mdio.mdio_write = mdio_ops->write;
	}
}

__attribute__((used)) static inline u32 t3_read_reg(struct adapter *adapter, u32 reg_addr)
{
	u32 val = readl(adapter->regs + reg_addr);

	CH_DBG(adapter, MMIO, "read register 0x%x value 0x%x\n", reg_addr, val);
	return val;
}

__attribute__((used)) static inline void t3_write_reg(struct adapter *adapter, u32 reg_addr, u32 val)
{
	CH_DBG(adapter, MMIO, "setting register 0x%x to 0x%x\n", reg_addr, val);
	writel(val, adapter->regs + reg_addr);
}

__attribute__((used)) static inline struct port_info *adap2pinfo(struct adapter *adap, int idx)
{
	return netdev_priv(adap->port[idx]);
}

__attribute__((used)) static inline int phy2portid(struct cphy *phy)
{
	struct adapter *adap = phy->adapter;
	struct port_info *port0 = adap2pinfo(adap, 0);

	return &port0->phy == phy ? 0 : 1;
}

__attribute__((used)) static inline int offload_running(struct adapter *adapter)
{
	return test_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map);
}

__attribute__((used)) static inline int uses_xaui(const struct adapter *adap)
{
	return adapter_info(adap)->caps & SUPPORTED_AUI;
}

__attribute__((used)) static inline int is_10G(const struct adapter *adap)
{
	return adapter_info(adap)->caps & SUPPORTED_10000baseT_Full;
}

__attribute__((used)) static inline int is_offload(const struct adapter *adap)
{
	return adap->params.offload;
}

__attribute__((used)) static inline unsigned int core_ticks_per_usec(const struct adapter *adap)
{
	return adap->params.vpd.cclk / 1000;
}

__attribute__((used)) static inline unsigned int is_pcie(const struct adapter *adap)
{
	return adap->params.pci.variant == PCI_VARIANT_PCIE;
}

__attribute__((used)) static inline int t3_wait_op_done(struct adapter *adapter, int reg, u32 mask,
				  int polarity, int attempts, int delay)
{
	return t3_wait_op_done_val(adapter, reg, mask, polarity, attempts,
				   delay, NULL);
}

__attribute__((used)) static int mc5_cmd_write(struct adapter *adapter, u32 cmd)
{
	t3_write_reg(adapter, A_MC5_DB_DBGI_REQ_CMD, cmd);
	return t3_wait_op_done(adapter, A_MC5_DB_DBGI_RSP_STATUS,
			       F_DBGIRSPVALID, 1, MAX_WRITE_ATTEMPTS, 1);
}

__attribute__((used)) static inline void dbgi_wr_data3(struct adapter *adapter, u32 v1, u32 v2,
				 u32 v3)
{
	t3_write_reg(adapter, A_MC5_DB_DBGI_REQ_DATA0, v1);
	t3_write_reg(adapter, A_MC5_DB_DBGI_REQ_DATA1, v2);
	t3_write_reg(adapter, A_MC5_DB_DBGI_REQ_DATA2, v3);
}

__attribute__((used)) static int mc5_write(struct adapter *adapter, u32 addr_lo, u32 cmd)
{
	t3_write_reg(adapter, A_MC5_DB_DBGI_REQ_ADDR0, addr_lo);
	if (mc5_cmd_write(adapter, cmd) == 0)
		return 0;
	CH_ERR(adapter, "MC5 timeout writing to TCAM address 0x%x\n",
	       addr_lo);
	return -1;
}

__attribute__((used)) static int init_mask_data_array(struct mc5 *mc5, u32 mask_array_base,
				u32 data_array_base, u32 write_cmd,
				int addr_shift)
{
	unsigned int i;
	struct adapter *adap = mc5->adapter;

	/*
	 * We need the size of the TCAM data and mask arrays in terms of
	 * 72-bit entries.
	 */
	unsigned int size72 = mc5->tcam_size;
	unsigned int server_base = t3_read_reg(adap, A_MC5_DB_SERVER_INDEX);

	if (mc5->mode == MC5_MODE_144_BIT) {
		size72 *= 2;	/* 1 144-bit entry is 2 72-bit entries */
		server_base *= 2;
	}

	/* Clear the data array */
	dbgi_wr_data3(adap, 0, 0, 0);
	for (i = 0; i < size72; i++)
		if (mc5_write(adap, data_array_base + (i << addr_shift),
			      write_cmd))
			return -1;

	/* Initialize the mask array. */
	dbgi_wr_data3(adap, 0xffffffff, 0xffffffff, 0xff);
	for (i = 0; i < size72; i++) {
		if (i == server_base)	/* entering server or routing region */
			t3_write_reg(adap, A_MC5_DB_DBGI_REQ_DATA0,
				     mc5->mode == MC5_MODE_144_BIT ?
				     0xfffffff9 : 0xfffffffd);
		if (mc5_write(adap, mask_array_base + (i << addr_shift),
			      write_cmd))
			return -1;
	}
	return 0;
}

__attribute__((used)) static int init_idt52100(struct mc5 *mc5)
{
	int i;
	struct adapter *adap = mc5->adapter;

	t3_write_reg(adap, A_MC5_DB_RSP_LATENCY,
		     V_RDLAT(0x15) | V_LRNLAT(0x15) | V_SRCHLAT(0x15));
	t3_write_reg(adap, A_MC5_DB_PART_ID_INDEX, 2);

	/*
	 * Use GMRs 14-15 for ELOOKUP, GMRs 12-13 for SYN lookups, and
	 * GMRs 8-9 for ACK- and AOPEN searches.
	 */
	t3_write_reg(adap, A_MC5_DB_POPEN_DATA_WR_CMD, IDT_CMD_WRITE);
	t3_write_reg(adap, A_MC5_DB_POPEN_MASK_WR_CMD, IDT_CMD_WRITE);
	t3_write_reg(adap, A_MC5_DB_AOPEN_SRCH_CMD, IDT_CMD_SEARCH);
	t3_write_reg(adap, A_MC5_DB_AOPEN_LRN_CMD, IDT_CMD_LEARN);
	t3_write_reg(adap, A_MC5_DB_SYN_SRCH_CMD, IDT_CMD_SEARCH | 0x6000);
	t3_write_reg(adap, A_MC5_DB_SYN_LRN_CMD, IDT_CMD_LEARN);
	t3_write_reg(adap, A_MC5_DB_ACK_SRCH_CMD, IDT_CMD_SEARCH);
	t3_write_reg(adap, A_MC5_DB_ACK_LRN_CMD, IDT_CMD_LEARN);
	t3_write_reg(adap, A_MC5_DB_ILOOKUP_CMD, IDT_CMD_SEARCH);
	t3_write_reg(adap, A_MC5_DB_ELOOKUP_CMD, IDT_CMD_SEARCH | 0x7000);
	t3_write_reg(adap, A_MC5_DB_DATA_WRITE_CMD, IDT_CMD_WRITE);
	t3_write_reg(adap, A_MC5_DB_DATA_READ_CMD, IDT_CMD_READ);

	/* Set DBGI command mode for IDT TCAM. */
	t3_write_reg(adap, A_MC5_DB_DBGI_CONFIG, DBGI_MODE_IDT52100);

	/* Set up LAR */
	dbgi_wr_data3(adap, IDT_LAR_MODE144, 0, 0);
	if (mc5_write(adap, IDT_LAR_ADR0, IDT_CMD_WRITE))
		goto err;

	/* Set up SSRs */
	dbgi_wr_data3(adap, 0xffffffff, 0xffffffff, 0);
	if (mc5_write(adap, IDT_SSR0_ADR0, IDT_CMD_WRITE) ||
	    mc5_write(adap, IDT_SSR1_ADR0, IDT_CMD_WRITE))
		goto err;

	/* Set up GMRs */
	for (i = 0; i < 32; ++i) {
		if (i >= 12 && i < 15)
			dbgi_wr_data3(adap, 0xfffffff9, 0xffffffff, 0xff);
		else if (i == 15)
			dbgi_wr_data3(adap, 0xfffffff9, 0xffff8007, 0xff);
		else
			dbgi_wr_data3(adap, 0xffffffff, 0xffffffff, 0xff);

		if (mc5_write(adap, IDT_GMR_BASE_ADR0 + i, IDT_CMD_WRITE))
			goto err;
	}

	/* Set up SCR */
	dbgi_wr_data3(adap, 1, 0, 0);
	if (mc5_write(adap, IDT_SCR_ADR0, IDT_CMD_WRITE))
		goto err;

	return init_mask_data_array(mc5, IDT_MSKARY_BASE_ADR0,
				    IDT_DATARY_BASE_ADR0, IDT_CMD_WRITE, 0);
err:
	return -EIO;
}

__attribute__((used)) static int init_idt43102(struct mc5 *mc5)
{
	int i;
	struct adapter *adap = mc5->adapter;

	t3_write_reg(adap, A_MC5_DB_RSP_LATENCY,
		     adap->params.rev == 0 ? V_RDLAT(0xd) | V_SRCHLAT(0x11) :
		     V_RDLAT(0xd) | V_SRCHLAT(0x12));

	/*
	 * Use GMRs 24-25 for ELOOKUP, GMRs 20-21 for SYN lookups, and no mask
	 * for ACK- and AOPEN searches.
	 */
	t3_write_reg(adap, A_MC5_DB_POPEN_DATA_WR_CMD, IDT4_CMD_WRITE);
	t3_write_reg(adap, A_MC5_DB_POPEN_MASK_WR_CMD, IDT4_CMD_WRITE);
	t3_write_reg(adap, A_MC5_DB_AOPEN_SRCH_CMD,
		     IDT4_CMD_SEARCH144 | 0x3800);
	t3_write_reg(adap, A_MC5_DB_SYN_SRCH_CMD, IDT4_CMD_SEARCH144);
	t3_write_reg(adap, A_MC5_DB_ACK_SRCH_CMD, IDT4_CMD_SEARCH144 | 0x3800);
	t3_write_reg(adap, A_MC5_DB_ILOOKUP_CMD, IDT4_CMD_SEARCH144 | 0x3800);
	t3_write_reg(adap, A_MC5_DB_ELOOKUP_CMD, IDT4_CMD_SEARCH144 | 0x800);
	t3_write_reg(adap, A_MC5_DB_DATA_WRITE_CMD, IDT4_CMD_WRITE);
	t3_write_reg(adap, A_MC5_DB_DATA_READ_CMD, IDT4_CMD_READ);

	t3_write_reg(adap, A_MC5_DB_PART_ID_INDEX, 3);

	/* Set DBGI command mode for IDT TCAM. */
	t3_write_reg(adap, A_MC5_DB_DBGI_CONFIG, DBGI_MODE_IDT52100);

	/* Set up GMRs */
	dbgi_wr_data3(adap, 0xffffffff, 0xffffffff, 0xff);
	for (i = 0; i < 7; ++i)
		if (mc5_write(adap, IDT4_GMR_BASE0 + i, IDT4_CMD_WRITE))
			goto err;

	for (i = 0; i < 4; ++i)
		if (mc5_write(adap, IDT4_GMR_BASE2 + i, IDT4_CMD_WRITE))
			goto err;

	dbgi_wr_data3(adap, 0xfffffff9, 0xffffffff, 0xff);
	if (mc5_write(adap, IDT4_GMR_BASE1, IDT4_CMD_WRITE) ||
	    mc5_write(adap, IDT4_GMR_BASE1 + 1, IDT4_CMD_WRITE) ||
	    mc5_write(adap, IDT4_GMR_BASE1 + 4, IDT4_CMD_WRITE))
		goto err;

	dbgi_wr_data3(adap, 0xfffffff9, 0xffff8007, 0xff);
	if (mc5_write(adap, IDT4_GMR_BASE1 + 5, IDT4_CMD_WRITE))
		goto err;

	/* Set up SCR */
	dbgi_wr_data3(adap, 0xf0000000, 0, 0);
	if (mc5_write(adap, IDT4_SCR_ADR0, IDT4_CMD_WRITE))
		goto err;

	return init_mask_data_array(mc5, IDT4_MSKARY_BASE_ADR0,
				    IDT4_DATARY_BASE_ADR0, IDT4_CMD_WRITE, 1);
err:
	return -EIO;
}

__attribute__((used)) static inline void mc5_dbgi_mode_enable(const struct mc5 *mc5)
{
	t3_write_reg(mc5->adapter, A_MC5_DB_CONFIG,
		     V_TMMODE(mc5->mode == MC5_MODE_72_BIT) | F_DBGIEN);
}

__attribute__((used)) static void mc5_dbgi_mode_disable(const struct mc5 *mc5)
{
	t3_write_reg(mc5->adapter, A_MC5_DB_CONFIG,
		     V_TMMODE(mc5->mode == MC5_MODE_72_BIT) |
		     V_COMPEN(mc5->mode == MC5_MODE_72_BIT) |
		     V_PRTYEN(mc5->parity_enabled) | F_MBUSEN);
}

int t3_mc5_init(struct mc5 *mc5, unsigned int nservers, unsigned int nfilters,
		unsigned int nroutes)
{
	u32 cfg;
	int err;
	unsigned int tcam_size = mc5->tcam_size;
	struct adapter *adap = mc5->adapter;

	if (!tcam_size)
		return 0;

	if (nroutes > MAX_ROUTES || nroutes + nservers + nfilters > tcam_size)
		return -EINVAL;

	/* Reset the TCAM */
	cfg = t3_read_reg(adap, A_MC5_DB_CONFIG) & ~F_TMMODE;
	cfg |= V_TMMODE(mc5->mode == MC5_MODE_72_BIT) | F_TMRST;
	t3_write_reg(adap, A_MC5_DB_CONFIG, cfg);
	if (t3_wait_op_done(adap, A_MC5_DB_CONFIG, F_TMRDY, 1, 500, 0)) {
		CH_ERR(adap, "TCAM reset timed out\n");
		return -1;
	}

	t3_write_reg(adap, A_MC5_DB_ROUTING_TABLE_INDEX, tcam_size - nroutes);
	t3_write_reg(adap, A_MC5_DB_FILTER_TABLE,
		     tcam_size - nroutes - nfilters);
	t3_write_reg(adap, A_MC5_DB_SERVER_INDEX,
		     tcam_size - nroutes - nfilters - nservers);

	mc5->parity_enabled = 1;

	/* All the TCAM addresses we access have only the low 32 bits non 0 */
	t3_write_reg(adap, A_MC5_DB_DBGI_REQ_ADDR1, 0);
	t3_write_reg(adap, A_MC5_DB_DBGI_REQ_ADDR2, 0);

	mc5_dbgi_mode_enable(mc5);

	switch (mc5->part_type) {
	case IDT75P52100:
		err = init_idt52100(mc5);
		break;
	case IDT75N43102:
		err = init_idt43102(mc5);
		break;
	default:
		CH_ERR(adap, "Unsupported TCAM type %d\n", mc5->part_type);
		err = -EINVAL;
		break;
	}

	mc5_dbgi_mode_disable(mc5);
	return err;
}

void t3_mc5_intr_handler(struct mc5 *mc5)
{
	struct adapter *adap = mc5->adapter;
	u32 cause = t3_read_reg(adap, A_MC5_DB_INT_CAUSE);

	if ((cause & F_PARITYERR) && mc5->parity_enabled) {
		CH_ALERT(adap, "MC5 parity error\n");
		mc5->stats.parity_err++;
	}

	if (cause & F_REQQPARERR) {
		CH_ALERT(adap, "MC5 request queue parity error\n");
		mc5->stats.reqq_parity_err++;
	}

	if (cause & F_DISPQPARERR) {
		CH_ALERT(adap, "MC5 dispatch queue parity error\n");
		mc5->stats.dispq_parity_err++;
	}

	if (cause & F_ACTRGNFULL)
		mc5->stats.active_rgn_full++;
	if (cause & F_NFASRCHFAIL)
		mc5->stats.nfa_srch_err++;
	if (cause & F_UNKNOWNCMD)
		mc5->stats.unknown_cmd++;
	if (cause & F_DELACTEMPTY)
		mc5->stats.del_act_empty++;
	if (cause & MC5_INT_FATAL)
		t3_fatal_err(adap);

	t3_write_reg(adap, A_MC5_DB_INT_CAUSE, cause);
}

void t3_mc5_prep(struct adapter *adapter, struct mc5 *mc5, int mode)
{
#define K * 1024

	static unsigned int tcam_part_size[] = {	/* in K 72-bit entries */
		64 K, 128 K, 256 K, 32 K
	};

#undef K

	u32 cfg = t3_read_reg(adapter, A_MC5_DB_CONFIG);

	mc5->adapter = adapter;
	mc5->mode = (unsigned char)mode;
	mc5->part_type = (unsigned char)G_TMTYPE(cfg);
	if (cfg & F_TMTYPEHI)
		mc5->part_type |= 4;

	mc5->tcam_size = tcam_part_size[G_TMPARTSIZE(cfg)];
	if (mode == MC5_MODE_144_BIT)
		mc5->tcam_size /= 2;
}

