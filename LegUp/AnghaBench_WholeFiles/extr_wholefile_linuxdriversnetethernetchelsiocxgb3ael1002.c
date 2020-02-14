#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  void* u8 ;
typedef  unsigned int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct reg_val {int mmd_addr; int clear_bits; int reg_addr; unsigned int set_bits; int const member_0; int member_1; int member_2; int member_3; } ;
struct TYPE_9__ {int (* mdio_read ) (int /*<<< orphan*/ ,int,int,int) ;int prtad; int (* mdio_write ) (int /*<<< orphan*/ ,int,int,int,unsigned int) ;int /*<<< orphan*/  mode_support; int /*<<< orphan*/  mmds; int /*<<< orphan*/  dev; } ;
struct cphy {unsigned int caps; char const* desc; void* priv; int* phy_cache; int modtype; struct adapter* adapter; TYPE_4__ mdio; struct cphy_ops const* ops; } ;
struct port_info {struct cphy phy; } ;
struct mdio_ops {int (* read ) (int /*<<< orphan*/ ,int,int,int) ;int (* write ) (int /*<<< orphan*/ ,int,int,int,unsigned int) ;int /*<<< orphan*/  mode_support; } ;
struct mc7 {unsigned int size; } ;
struct mc5 {unsigned int tcam_size; } ;
struct cphy_ops {int /*<<< orphan*/  mmds; } ;
struct TYPE_7__ {scalar_t__ variant; } ;
struct TYPE_6__ {int cclk; } ;
struct TYPE_8__ {int offload; TYPE_2__ pci; TYPE_1__ vpd; } ;
struct adapter {unsigned int regs; TYPE_3__ params; int /*<<< orphan*/  open_device_map; int /*<<< orphan*/ * port; } ;
struct TYPE_10__ {int caps; } ;

/* Variables and functions */
 int AEL1002_LB_EN ; 
 int AEL1002_PWR_DOWN_HI ; 
 int AEL1002_PWR_DOWN_LO ; 
 int AEL1002_XFI_EQL ; 
 int AEL100X_TX_CONFIG1 ; 
 int AEL2005_GPIO_CTRL ; 
 int AEL2005_GPIO_STAT ; 
 unsigned int AEL2005_MODDET_IRQ ; 
#define  AEL2020_GPIO_CFG 132 
#define  AEL2020_GPIO_CTRL 131 
 int AEL2020_GPIO_INTR ; 
#define  AEL2020_GPIO_LSTAT 130 
#define  AEL2020_GPIO_MODDET 129 
 int AEL2020_GPIO_STAT ; 
 int AEL_I2C_CTRL ; 
 int AEL_I2C_DATA ; 
 int AEL_I2C_STAT ; 
 int AEL_OPT_SETTINGS ; 
 int /*<<< orphan*/  A_T3DBG_GPIO_EN ; 
 int /*<<< orphan*/  A_XGM_SERDES_STAT0 ; 
 int /*<<< orphan*/  A_XGM_SERDES_STAT1 ; 
 int /*<<< orphan*/  A_XGM_SERDES_STAT2 ; 
 int /*<<< orphan*/  A_XGM_SERDES_STAT3 ; 
 int /*<<< orphan*/  CH_DBG (struct adapter*,int /*<<< orphan*/ ,char*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  CH_WARN (struct adapter*,char*,scalar_t__,int,int) ; 
 int DUPLEX_FULL ; 
 int /*<<< orphan*/  EDC_OPT_AEL2005 ; 
 int EDC_OPT_AEL2005_SIZE ; 
 int /*<<< orphan*/  EDC_TWX_AEL2005 ; 
 int EDC_TWX_AEL2005_SIZE ; 
 int /*<<< orphan*/  EDC_TWX_AEL2020 ; 
 int EDC_TWX_AEL2020_SIZE ; 
 int ETIMEDOUT ; 
 int F_GPIO2_OUT_VAL ; 
 int F_GPIO7_OUT_VAL ; 
 unsigned int F_LOWSIG0 ; 
 int /*<<< orphan*/  MDIO_CTRL1 ; 
 int /*<<< orphan*/  MDIO_CTRL1_LPOWER ; 
 int MDIO_MMD_PCS ; 
 int MDIO_MMD_PHYXS ; 
#define  MDIO_MMD_PMAPMD 128 
 int MDIO_PCS_10GBRT_STAT1 ; 
 int MDIO_PCS_10GBX_STAT1 ; 
 int MDIO_PHYXS_LNSTAT ; 
 int MDIO_PMA_LASI_CTRL ; 
 int MDIO_PMA_RXDET ; 
 int MDIO_PMA_TXDIS ; 
 int MDIO_STAT1 ; 
 int /*<<< orphan*/  MMIO ; 
 int MODULE_DEV_ADDR ; 
 int /*<<< orphan*/  OFFLOAD_DEVMAP_BIT ; 
 scalar_t__ PCI_VARIANT_PCIE ; 
 int SPEED_10000 ; 
 int SUPPORTED_10000baseT_Full ; 
 int SUPPORTED_AUI ; 
 int SUPPORTED_FIBRE ; 
 int SUPPORTED_IRQ ; 
 int SUPPORTED_TP ; 
 unsigned int XGM_REG (int /*<<< orphan*/ ,int) ; 
 TYPE_5__* adapter_info (struct adapter const*) ; 
 struct cphy_ops ael1002_ops ; 
 struct cphy_ops ael1006_ops ; 
 struct cphy_ops ael2005_ops ; 
 struct cphy_ops ael2020_ops ; 
 struct reg_val* ael2020_reset_regs ; 
 int cphy_cause_link_change ; 
 int cphy_cause_module_change ; 
 void* edc_none ; 
 void* edc_sr ; 
 void* edc_twinax ; 
 int mdio_set_flag (TYPE_4__*,scalar_t__,int const,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct port_info* netdev_priv (int /*<<< orphan*/ ) ; 
 int phy_modtype_lr ; 
 int phy_modtype_lrm ; 
 int phy_modtype_none ; 
 int phy_modtype_sr ; 
 int phy_modtype_twinax ; 
 int phy_modtype_twinax_long ; 
 int phy_modtype_unknown ; 
 struct cphy_ops qt2045_ops ; 
 unsigned int readl (unsigned int) ; 
 int stub1 (int /*<<< orphan*/ ,int,int,int) ; 
 int stub2 (int /*<<< orphan*/ ,int,int,int,unsigned int) ; 
 int t3_get_edc_fw (struct cphy*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  t3_link_changed (struct adapter*,int) ; 
 int t3_mdio_change_bits (struct cphy*,int const,int,int,int) ; 
 int t3_phy_lasi_intr_clear (struct cphy*) ; 
 int t3_phy_lasi_intr_disable (struct cphy*) ; 
 int t3_phy_lasi_intr_enable (struct cphy*) ; 
 int t3_phy_lasi_intr_handler (struct cphy*) ; 
 int t3_phy_reset (struct cphy*,int const,int) ; 
 int /*<<< orphan*/  t3_set_reg_field (struct adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int t3_wait_op_done_val (struct adapter*,int,unsigned int,int,int,int,int /*<<< orphan*/ *) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (unsigned int,unsigned int) ; 
 struct cphy_ops xaui_direct_ops ; 

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

__attribute__((used)) static int set_phy_regs(struct cphy *phy, const struct reg_val *rv)
{
	int err;

	for (err = 0; rv->mmd_addr && !err; rv++) {
		if (rv->clear_bits == 0xffff)
			err = t3_mdio_write(phy, rv->mmd_addr, rv->reg_addr,
					    rv->set_bits);
		else
			err = t3_mdio_change_bits(phy, rv->mmd_addr,
						  rv->reg_addr, rv->clear_bits,
						  rv->set_bits);
	}
	return err;
}

__attribute__((used)) static void ael100x_txon(struct cphy *phy)
{
	int tx_on_gpio =
		phy->mdio.prtad == 0 ? F_GPIO7_OUT_VAL : F_GPIO2_OUT_VAL;

	msleep(100);
	t3_set_reg_field(phy->adapter, A_T3DBG_GPIO_EN, 0, tx_on_gpio);
	msleep(30);
}

__attribute__((used)) static int ael_i2c_rd(struct cphy *phy, int dev_addr, int word_addr)
{
	int i, err;
	unsigned int stat, data;

	err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL_I2C_CTRL,
			    (dev_addr << 8) | (1 << 8) | word_addr);
	if (err)
		return err;

	for (i = 0; i < 200; i++) {
		msleep(1);
		err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL_I2C_STAT, &stat);
		if (err)
			return err;
		if ((stat & 3) == 1) {
			err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL_I2C_DATA,
					   &data);
			if (err)
				return err;
			return data >> 8;
		}
	}
	CH_WARN(phy->adapter, "PHY %u i2c read of dev.addr %#x.%#x timed out\n",
		phy->mdio.prtad, dev_addr, word_addr);
	return -ETIMEDOUT;
}

__attribute__((used)) static int ael1002_power_down(struct cphy *phy, int enable)
{
	int err;

	err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, MDIO_PMA_TXDIS, !!enable);
	if (!err)
		err = mdio_set_flag(&phy->mdio, phy->mdio.prtad,
				    MDIO_MMD_PMAPMD, MDIO_CTRL1,
				    MDIO_CTRL1_LPOWER, enable);
	return err;
}

__attribute__((used)) static int ael1002_reset(struct cphy *phy, int wait)
{
	int err;

	if ((err = ael1002_power_down(phy, 0)) ||
	    (err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL100X_TX_CONFIG1, 1)) ||
	    (err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL1002_PWR_DOWN_HI, 0)) ||
	    (err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL1002_PWR_DOWN_LO, 0)) ||
	    (err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL1002_XFI_EQL, 0x18)) ||
	    (err = t3_mdio_change_bits(phy, MDIO_MMD_PMAPMD, AEL1002_LB_EN,
				       0, 1 << 5)))
		return err;
	return 0;
}

__attribute__((used)) static int ael1002_intr_noop(struct cphy *phy)
{
	return 0;
}

__attribute__((used)) static int get_link_status_r(struct cphy *phy, int *link_ok, int *speed,
			     int *duplex, int *fc)
{
	if (link_ok) {
		unsigned int stat0, stat1, stat2;
		int err = t3_mdio_read(phy, MDIO_MMD_PMAPMD,
				       MDIO_PMA_RXDET, &stat0);

		if (!err)
			err = t3_mdio_read(phy, MDIO_MMD_PCS,
					   MDIO_PCS_10GBRT_STAT1, &stat1);
		if (!err)
			err = t3_mdio_read(phy, MDIO_MMD_PHYXS,
					   MDIO_PHYXS_LNSTAT, &stat2);
		if (err)
			return err;
		*link_ok = (stat0 & stat1 & (stat2 >> 12)) & 1;
	}
	if (speed)
		*speed = SPEED_10000;
	if (duplex)
		*duplex = DUPLEX_FULL;
	return 0;
}

int t3_ael1002_phy_prep(struct cphy *phy, struct adapter *adapter,
			int phy_addr, const struct mdio_ops *mdio_ops)
{
	cphy_init(phy, adapter, phy_addr, &ael1002_ops, mdio_ops,
		  SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_FIBRE,
		   "10GBASE-R");
	ael100x_txon(phy);
	return 0;
}

__attribute__((used)) static int ael1006_reset(struct cphy *phy, int wait)
{
	return t3_phy_reset(phy, MDIO_MMD_PMAPMD, wait);
}

int t3_ael1006_phy_prep(struct cphy *phy, struct adapter *adapter,
			     int phy_addr, const struct mdio_ops *mdio_ops)
{
	cphy_init(phy, adapter, phy_addr, &ael1006_ops, mdio_ops,
		  SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_FIBRE,
		   "10GBASE-SR");
	ael100x_txon(phy);
	return 0;
}

__attribute__((used)) static int ael2xxx_get_module_type(struct cphy *phy, int delay_ms)
{
	int v;

	if (delay_ms)
		msleep(delay_ms);

	/* see SFF-8472 for below */
	v = ael_i2c_rd(phy, MODULE_DEV_ADDR, 3);
	if (v < 0)
		return v;

	if (v == 0x10)
		return phy_modtype_sr;
	if (v == 0x20)
		return phy_modtype_lr;
	if (v == 0x40)
		return phy_modtype_lrm;

	v = ael_i2c_rd(phy, MODULE_DEV_ADDR, 6);
	if (v < 0)
		return v;
	if (v != 4)
		goto unknown;

	v = ael_i2c_rd(phy, MODULE_DEV_ADDR, 10);
	if (v < 0)
		return v;

	if (v & 0x80) {
		v = ael_i2c_rd(phy, MODULE_DEV_ADDR, 0x12);
		if (v < 0)
			return v;
		return v > 10 ? phy_modtype_twinax_long : phy_modtype_twinax;
	}
unknown:
	return phy_modtype_unknown;
}

__attribute__((used)) static int ael2005_setup_sr_edc(struct cphy *phy)
{
	static const struct reg_val regs[] = {
		{ MDIO_MMD_PMAPMD, 0xc003, 0xffff, 0x181 },
		{ MDIO_MMD_PMAPMD, 0xc010, 0xffff, 0x448a },
		{ MDIO_MMD_PMAPMD, 0xc04a, 0xffff, 0x5200 },
		{ 0, 0, 0, 0 }
	};

	int i, err;

	err = set_phy_regs(phy, regs);
	if (err)
		return err;

	msleep(50);

	if (phy->priv != edc_sr)
		err = t3_get_edc_fw(phy, EDC_OPT_AEL2005,
				    EDC_OPT_AEL2005_SIZE);
	if (err)
		return err;

	for (i = 0; i <  EDC_OPT_AEL2005_SIZE / sizeof(u16) && !err; i += 2)
		err = t3_mdio_write(phy, MDIO_MMD_PMAPMD,
				    phy->phy_cache[i],
				    phy->phy_cache[i + 1]);
	if (!err)
		phy->priv = edc_sr;
	return err;
}

__attribute__((used)) static int ael2005_setup_twinax_edc(struct cphy *phy, int modtype)
{
	static const struct reg_val regs[] = {
		{ MDIO_MMD_PMAPMD, 0xc04a, 0xffff, 0x5a00 },
		{ 0, 0, 0, 0 }
	};
	static const struct reg_val preemphasis[] = {
		{ MDIO_MMD_PMAPMD, 0xc014, 0xffff, 0xfe16 },
		{ MDIO_MMD_PMAPMD, 0xc015, 0xffff, 0xa000 },
		{ 0, 0, 0, 0 }
	};
	int i, err;

	err = set_phy_regs(phy, regs);
	if (!err && modtype == phy_modtype_twinax_long)
		err = set_phy_regs(phy, preemphasis);
	if (err)
		return err;

	msleep(50);

	if (phy->priv != edc_twinax)
		err = t3_get_edc_fw(phy, EDC_TWX_AEL2005,
				    EDC_TWX_AEL2005_SIZE);
	if (err)
		return err;

	for (i = 0; i <  EDC_TWX_AEL2005_SIZE / sizeof(u16) && !err; i += 2)
		err = t3_mdio_write(phy, MDIO_MMD_PMAPMD,
				    phy->phy_cache[i],
				    phy->phy_cache[i + 1]);
	if (!err)
		phy->priv = edc_twinax;
	return err;
}

__attribute__((used)) static int ael2005_get_module_type(struct cphy *phy, int delay_ms)
{
	int v;
	unsigned int stat;

	v = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL, &stat);
	if (v)
		return v;

	if (stat & (1 << 8))			/* module absent */
		return phy_modtype_none;

	return ael2xxx_get_module_type(phy, delay_ms);
}

__attribute__((used)) static int ael2005_intr_enable(struct cphy *phy)
{
	int err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL, 0x200);
	return err ? err : t3_phy_lasi_intr_enable(phy);
}

__attribute__((used)) static int ael2005_intr_disable(struct cphy *phy)
{
	int err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL, 0x100);
	return err ? err : t3_phy_lasi_intr_disable(phy);
}

__attribute__((used)) static int ael2005_intr_clear(struct cphy *phy)
{
	int err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL, 0xd00);
	return err ? err : t3_phy_lasi_intr_clear(phy);
}

__attribute__((used)) static int ael2005_reset(struct cphy *phy, int wait)
{
	static const struct reg_val regs0[] = {
		{ MDIO_MMD_PMAPMD, 0xc001, 0, 1 << 5 },
		{ MDIO_MMD_PMAPMD, 0xc017, 0, 1 << 5 },
		{ MDIO_MMD_PMAPMD, 0xc013, 0xffff, 0xf341 },
		{ MDIO_MMD_PMAPMD, 0xc210, 0xffff, 0x8000 },
		{ MDIO_MMD_PMAPMD, 0xc210, 0xffff, 0x8100 },
		{ MDIO_MMD_PMAPMD, 0xc210, 0xffff, 0x8000 },
		{ MDIO_MMD_PMAPMD, 0xc210, 0xffff, 0 },
		{ 0, 0, 0, 0 }
	};
	static const struct reg_val regs1[] = {
		{ MDIO_MMD_PMAPMD, 0xca00, 0xffff, 0x0080 },
		{ MDIO_MMD_PMAPMD, 0xca12, 0xffff, 0 },
		{ 0, 0, 0, 0 }
	};

	int err;
	unsigned int lasi_ctrl;

	err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_CTRL,
			   &lasi_ctrl);
	if (err)
		return err;

	err = t3_phy_reset(phy, MDIO_MMD_PMAPMD, 0);
	if (err)
		return err;

	msleep(125);
	phy->priv = edc_none;
	err = set_phy_regs(phy, regs0);
	if (err)
		return err;

	msleep(50);

	err = ael2005_get_module_type(phy, 0);
	if (err < 0)
		return err;
	phy->modtype = err;

	if (err == phy_modtype_twinax || err == phy_modtype_twinax_long)
		err = ael2005_setup_twinax_edc(phy, err);
	else
		err = ael2005_setup_sr_edc(phy);
	if (err)
		return err;

	err = set_phy_regs(phy, regs1);
	if (err)
		return err;

	/* reset wipes out interrupts, reenable them if they were on */
	if (lasi_ctrl & 1)
		err = ael2005_intr_enable(phy);
	return err;
}

__attribute__((used)) static int ael2005_intr_handler(struct cphy *phy)
{
	unsigned int stat;
	int ret, edc_needed, cause = 0;

	ret = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_STAT, &stat);
	if (ret)
		return ret;

	if (stat & AEL2005_MODDET_IRQ) {
		ret = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL,
				    0xd00);
		if (ret)
			return ret;

		/* modules have max 300 ms init time after hot plug */
		ret = ael2005_get_module_type(phy, 300);
		if (ret < 0)
			return ret;

		phy->modtype = ret;
		if (ret == phy_modtype_none)
			edc_needed = phy->priv;       /* on unplug retain EDC */
		else if (ret == phy_modtype_twinax ||
			 ret == phy_modtype_twinax_long)
			edc_needed = edc_twinax;
		else
			edc_needed = edc_sr;

		if (edc_needed != phy->priv) {
			ret = ael2005_reset(phy, 0);
			return ret ? ret : cphy_cause_module_change;
		}
		cause = cphy_cause_module_change;
	}

	ret = t3_phy_lasi_intr_handler(phy);
	if (ret < 0)
		return ret;

	ret |= cause;
	return ret ? ret : cphy_cause_link_change;
}

int t3_ael2005_phy_prep(struct cphy *phy, struct adapter *adapter,
			int phy_addr, const struct mdio_ops *mdio_ops)
{
	cphy_init(phy, adapter, phy_addr, &ael2005_ops, mdio_ops,
		  SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_FIBRE |
		  SUPPORTED_IRQ, "10GBASE-R");
	msleep(125);
	return t3_mdio_change_bits(phy, MDIO_MMD_PMAPMD, AEL_OPT_SETTINGS, 0,
				   1 << 5);
}

__attribute__((used)) static int ael2020_setup_sr_edc(struct cphy *phy)
{
	static const struct reg_val regs[] = {
		/* set CDR offset to 10 */
		{ MDIO_MMD_PMAPMD, 0xcc01, 0xffff, 0x488a },

		/* adjust 10G RX bias current */
		{ MDIO_MMD_PMAPMD, 0xcb1b, 0xffff, 0x0200 },
		{ MDIO_MMD_PMAPMD, 0xcb1c, 0xffff, 0x00f0 },
		{ MDIO_MMD_PMAPMD, 0xcc06, 0xffff, 0x00e0 },

		/* end */
		{ 0, 0, 0, 0 }
	};
	int err;

	err = set_phy_regs(phy, regs);
	msleep(50);
	if (err)
		return err;

	phy->priv = edc_sr;
	return 0;
}

__attribute__((used)) static int ael2020_setup_twinax_edc(struct cphy *phy, int modtype)
{
	/* set uC to 40MHz */
	static const struct reg_val uCclock40MHz[] = {
		{ MDIO_MMD_PMAPMD, 0xff28, 0xffff, 0x4001 },
		{ MDIO_MMD_PMAPMD, 0xff2a, 0xffff, 0x0002 },
		{ 0, 0, 0, 0 }
	};

	/* activate uC clock */
	static const struct reg_val uCclockActivate[] = {
		{ MDIO_MMD_PMAPMD, 0xd000, 0xffff, 0x5200 },
		{ 0, 0, 0, 0 }
	};

	/* set PC to start of SRAM and activate uC */
	static const struct reg_val uCactivate[] = {
		{ MDIO_MMD_PMAPMD, 0xd080, 0xffff, 0x0100 },
		{ MDIO_MMD_PMAPMD, 0xd092, 0xffff, 0x0000 },
		{ 0, 0, 0, 0 }
	};
	int i, err;

	/* set uC clock and activate it */
	err = set_phy_regs(phy, uCclock40MHz);
	msleep(500);
	if (err)
		return err;
	err = set_phy_regs(phy, uCclockActivate);
	msleep(500);
	if (err)
		return err;

	if (phy->priv != edc_twinax)
		err = t3_get_edc_fw(phy, EDC_TWX_AEL2020,
				    EDC_TWX_AEL2020_SIZE);
	if (err)
		return err;

	for (i = 0; i <  EDC_TWX_AEL2020_SIZE / sizeof(u16) && !err; i += 2)
		err = t3_mdio_write(phy, MDIO_MMD_PMAPMD,
				    phy->phy_cache[i],
				    phy->phy_cache[i + 1]);
	/* activate uC */
	err = set_phy_regs(phy, uCactivate);
	if (!err)
		phy->priv = edc_twinax;
	return err;
}

__attribute__((used)) static int ael2020_get_module_type(struct cphy *phy, int delay_ms)
{
	int v;
	unsigned int stat;

	v = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2020_GPIO_STAT, &stat);
	if (v)
		return v;

	if (stat & (0x1 << (AEL2020_GPIO_MODDET*4))) {
		/* module absent */
		return phy_modtype_none;
	}

	return ael2xxx_get_module_type(phy, delay_ms);
}

__attribute__((used)) static int ael2020_intr_enable(struct cphy *phy)
{
	static const struct reg_val regs[] = {
		/* output Module's Loss Of Signal (LOS) to LED */
		{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CFG+AEL2020_GPIO_LSTAT,
			0xffff, 0x4 },
		{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CTRL,
			0xffff, 0x8 << (AEL2020_GPIO_LSTAT*4) },

		 /* enable module detect status change interrupts */
		{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CTRL,
			0xffff, 0x2 << (AEL2020_GPIO_MODDET*4) },

		/* end */
		{ 0, 0, 0, 0 }
	};
	int err, link_ok = 0;

	/* set up "link status" LED and enable module change interrupts */
	err = set_phy_regs(phy, regs);
	if (err)
		return err;

	err = get_link_status_r(phy, &link_ok, NULL, NULL, NULL);
	if (err)
		return err;
	if (link_ok)
		t3_link_changed(phy->adapter,
				phy2portid(phy));

	err = t3_phy_lasi_intr_enable(phy);
	if (err)
		return err;

	return 0;
}

__attribute__((used)) static int ael2020_intr_disable(struct cphy *phy)
{
	static const struct reg_val regs[] = {
		/* reset "link status" LED to "off" */
		{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CTRL,
			0xffff, 0xb << (AEL2020_GPIO_LSTAT*4) },

		/* disable module detect status change interrupts */
		{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CTRL,
			0xffff, 0x1 << (AEL2020_GPIO_MODDET*4) },

		/* end */
		{ 0, 0, 0, 0 }
	};
	int err;

	/* turn off "link status" LED and disable module change interrupts */
	err = set_phy_regs(phy, regs);
	if (err)
		return err;

	return t3_phy_lasi_intr_disable(phy);
}

__attribute__((used)) static int ael2020_intr_clear(struct cphy *phy)
{
	/*
	 * The GPIO Interrupt register on the AEL2020 is a "Latching High"
	 * (LH) register which is cleared to the current state when it's read.
	 * Thus, we simply read the register and discard the result.
	 */
	unsigned int stat;
	int err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2020_GPIO_INTR, &stat);
	return err ? err : t3_phy_lasi_intr_clear(phy);
}

__attribute__((used)) static int ael2020_reset(struct cphy *phy, int wait)
{
	int err;
	unsigned int lasi_ctrl;

	/* grab current interrupt state */
	err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_CTRL,
			   &lasi_ctrl);
	if (err)
		return err;

	err = t3_phy_reset(phy, MDIO_MMD_PMAPMD, 125);
	if (err)
		return err;
	msleep(100);

	/* basic initialization for all module types */
	phy->priv = edc_none;
	err = set_phy_regs(phy, ael2020_reset_regs);
	if (err)
		return err;

	/* determine module type and perform appropriate initialization */
	err = ael2020_get_module_type(phy, 0);
	if (err < 0)
		return err;
	phy->modtype = (u8)err;
	if (err == phy_modtype_twinax || err == phy_modtype_twinax_long)
		err = ael2020_setup_twinax_edc(phy, err);
	else
		err = ael2020_setup_sr_edc(phy);
	if (err)
		return err;

	/* reset wipes out interrupts, reenable them if they were on */
	if (lasi_ctrl & 1)
		err = ael2005_intr_enable(phy);
	return err;
}

__attribute__((used)) static int ael2020_intr_handler(struct cphy *phy)
{
	unsigned int stat;
	int ret, edc_needed, cause = 0;

	ret = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2020_GPIO_INTR, &stat);
	if (ret)
		return ret;

	if (stat & (0x1 << AEL2020_GPIO_MODDET)) {
		/* modules have max 300 ms init time after hot plug */
		ret = ael2020_get_module_type(phy, 300);
		if (ret < 0)
			return ret;

		phy->modtype = (u8)ret;
		if (ret == phy_modtype_none)
			edc_needed = phy->priv;       /* on unplug retain EDC */
		else if (ret == phy_modtype_twinax ||
			 ret == phy_modtype_twinax_long)
			edc_needed = edc_twinax;
		else
			edc_needed = edc_sr;

		if (edc_needed != phy->priv) {
			ret = ael2020_reset(phy, 0);
			return ret ? ret : cphy_cause_module_change;
		}
		cause = cphy_cause_module_change;
	}

	ret = t3_phy_lasi_intr_handler(phy);
	if (ret < 0)
		return ret;

	ret |= cause;
	return ret ? ret : cphy_cause_link_change;
}

int t3_ael2020_phy_prep(struct cphy *phy, struct adapter *adapter, int phy_addr,
			const struct mdio_ops *mdio_ops)
{
	int err;

	cphy_init(phy, adapter, phy_addr, &ael2020_ops, mdio_ops,
		  SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_FIBRE |
		  SUPPORTED_IRQ, "10GBASE-R");
	msleep(125);

	err = set_phy_regs(phy, ael2020_reset_regs);
	if (err)
		return err;
	return 0;
}

__attribute__((used)) static int get_link_status_x(struct cphy *phy, int *link_ok, int *speed,
			     int *duplex, int *fc)
{
	if (link_ok) {
		unsigned int stat0, stat1, stat2;
		int err = t3_mdio_read(phy, MDIO_MMD_PMAPMD,
				       MDIO_PMA_RXDET, &stat0);

		if (!err)
			err = t3_mdio_read(phy, MDIO_MMD_PCS,
					   MDIO_PCS_10GBX_STAT1, &stat1);
		if (!err)
			err = t3_mdio_read(phy, MDIO_MMD_PHYXS,
					   MDIO_PHYXS_LNSTAT, &stat2);
		if (err)
			return err;
		*link_ok = (stat0 & (stat1 >> 12) & (stat2 >> 12)) & 1;
	}
	if (speed)
		*speed = SPEED_10000;
	if (duplex)
		*duplex = DUPLEX_FULL;
	return 0;
}

int t3_qt2045_phy_prep(struct cphy *phy, struct adapter *adapter,
		       int phy_addr, const struct mdio_ops *mdio_ops)
{
	unsigned int stat;

	cphy_init(phy, adapter, phy_addr, &qt2045_ops, mdio_ops,
		  SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_TP,
		  "10GBASE-CX4");

	/*
	 * Some cards where the PHY is supposed to be at address 0 actually
	 * have it at 1.
	 */
	if (!phy_addr &&
	    !t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_STAT1, &stat) &&
	    stat == 0xffff)
		phy->mdio.prtad = 1;
	return 0;
}

__attribute__((used)) static int xaui_direct_reset(struct cphy *phy, int wait)
{
	return 0;
}

__attribute__((used)) static int xaui_direct_get_link_status(struct cphy *phy, int *link_ok,
				       int *speed, int *duplex, int *fc)
{
	if (link_ok) {
		unsigned int status;
		int prtad = phy->mdio.prtad;

		status = t3_read_reg(phy->adapter,
				     XGM_REG(A_XGM_SERDES_STAT0, prtad)) |
		    t3_read_reg(phy->adapter,
				    XGM_REG(A_XGM_SERDES_STAT1, prtad)) |
		    t3_read_reg(phy->adapter,
				XGM_REG(A_XGM_SERDES_STAT2, prtad)) |
		    t3_read_reg(phy->adapter,
				XGM_REG(A_XGM_SERDES_STAT3, prtad));
		*link_ok = !(status & F_LOWSIG0);
	}
	if (speed)
		*speed = SPEED_10000;
	if (duplex)
		*duplex = DUPLEX_FULL;
	return 0;
}

__attribute__((used)) static int xaui_direct_power_down(struct cphy *phy, int enable)
{
	return 0;
}

int t3_xaui_direct_phy_prep(struct cphy *phy, struct adapter *adapter,
			    int phy_addr, const struct mdio_ops *mdio_ops)
{
	cphy_init(phy, adapter, phy_addr, &xaui_direct_ops, mdio_ops,
		  SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_TP,
		  "10GBASE-CX4");
	return 0;
}

