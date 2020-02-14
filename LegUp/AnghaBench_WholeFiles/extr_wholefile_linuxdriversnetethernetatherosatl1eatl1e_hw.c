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
typedef  scalar_t__ u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_dev {int dummy; } ;
struct atl1e_hw {int mii_autoneg_adv_reg; int media_type; int autoneg_advertised; scalar_t__ nic_type; int mii_1000t_ctrl_reg; int phy_configured; int re_autoneg; struct atl1e_adapter* adapter; scalar_t__* perm_mac_addr; scalar_t__* mac_addr; } ;
struct atl1e_adapter {int /*<<< orphan*/  netdev; struct pci_dev* pdev; } ;
typedef  int s32 ;

/* Variables and functions */
 int ADVERTISE_1000FULL ; 
 int ADVERTISE_1000_FULL ; 
 int ADVERTISE_100FULL ; 
 int ADVERTISE_100_FULL ; 
 int ADVERTISE_100_HALF ; 
 int ADVERTISE_10_FULL ; 
 int ADVERTISE_10_HALF ; 
 int ADVERTISE_ALL ; 
 int ADVERTISE_PAUSE_ASYM ; 
 int ADVERTISE_PAUSE_CAP ; 
 int AT_ERR_EEPROM ; 
 int AT_ERR_PHY ; 
 int AT_ERR_PHY_RES ; 
 int AT_ERR_PHY_SPEED ; 
 int AT_ERR_TIMEOUT ; 
 int AT_HW_MAX_IDLE_DELAY ; 
 int AT_READ_REG (struct atl1e_hw*,int) ; 
 int AT_READ_REGW (struct atl1e_hw*,int /*<<< orphan*/ ) ; 
 int AT_READ_REG_ARRAY (struct atl1e_hw*,int,int) ; 
 int AT_TWSI_EEPROM_TIMEOUT ; 
 int /*<<< orphan*/  AT_WRITE_REG (struct atl1e_hw*,int,int) ; 
 int /*<<< orphan*/  AT_WRITE_REGW (struct atl1e_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  AT_WRITE_REG_ARRAY (struct atl1e_hw*,int,int,int) ; 
 int BMCR_ANENABLE ; 
 int BMCR_ANRESTART ; 
 int BMCR_RESET ; 
 int CMD_BUS_MASTER ; 
 int CMD_IO_SPACE ; 
 int CMD_MEMORY_SPACE ; 
 int ETH_ALEN ; 
 int FULL_DUPLEX ; 
 int GPHY_CTRL_DEFAULT ; 
 int GPHY_CTRL_EXT_RESET ; 
 int GPHY_CTRL_PW_WOL_DIS ; 
 int HALF_DUPLEX ; 
 int MASTER_CTRL_LED_MODE ; 
 int MASTER_CTRL_SOFT_RST ; 
 int MDIO_BUSY ; 
 int MDIO_CLK_25_4 ; 
 int MDIO_CLK_SEL_SHIFT ; 
 int MDIO_DATA_MASK ; 
 int MDIO_DATA_SHIFT ; 
 int MDIO_REG_ADDR_MASK ; 
 int MDIO_REG_ADDR_SHIFT ; 
 int MDIO_RW ; 
 int MDIO_START ; 
 int MDIO_SUP_PREAMBLE ; 
 int MDIO_WAIT_TIMES ; 
#define  MEDIA_TYPE_100M_FULL 134 
#define  MEDIA_TYPE_100M_HALF 133 
#define  MEDIA_TYPE_10M_FULL 132 
#define  MEDIA_TYPE_AUTO_SENSOR 131 
 int MII_ADVERTISE ; 
 int MII_AR_DEFAULT_CAP_MASK ; 
 int MII_AT001_CR_1000T_DEFAULT_CAP_MASK ; 
 int MII_AT001_CR_1000T_SPEED_MASK ; 
 int MII_AT001_PSSR ; 
#define  MII_AT001_PSSR_1000MBS 130 
#define  MII_AT001_PSSR_100MBS 129 
#define  MII_AT001_PSSR_10MBS 128 
 int MII_AT001_PSSR_DPLX ; 
 int MII_AT001_PSSR_SPD_DPLX_RESOLVED ; 
 int MII_AT001_PSSR_SPEED ; 
 int MII_BMCR ; 
 int MII_CTRL1000 ; 
 int MII_DBG_ADDR ; 
 int MII_DBG_DATA ; 
 int MII_INT_CTRL ; 
 int /*<<< orphan*/  PCI_REG_COMMAND ; 
 int /*<<< orphan*/  REG_GPHY_CTRL ; 
 int REG_IDLE_STATUS ; 
 int REG_MAC_STA_ADDR ; 
 int REG_MASTER_CTRL ; 
 int REG_MDIO_CTRL ; 
 int /*<<< orphan*/  REG_PCIE_CAP_LIST ; 
 int REG_RX_HASH_TABLE ; 
 int REG_SPI_FLASH_CTRL ; 
 int REG_TWSI_CTRL ; 
 int REG_VPD_CAP ; 
 int REG_VPD_DATA ; 
 int SPEED_10 ; 
 int SPEED_100 ; 
 int SPEED_1000 ; 
 int SPI_FLASH_CTRL_EN_VPD ; 
 int TWSI_CTRL_SW_LDSTART ; 
 int VPD_CAP_VPD_ADDR_MASK ; 
 int VPD_CAP_VPD_ADDR_SHIFT ; 
 int VPD_CAP_VPD_FLAG ; 
 scalar_t__ athr_l1e ; 
 scalar_t__ athr_l2e_revA ; 
 int atl1e_restart_autoneg (struct atl1e_hw*) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int ether_crc_le (int,scalar_t__*) ; 
 scalar_t__ is_valid_ether_addr (scalar_t__*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  netdev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  netdev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int swab16 (int) ; 
 int swab32 (int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wmb () ; 

int atl1e_check_eeprom_exist(struct atl1e_hw *hw)
{
	u32 value;

	value = AT_READ_REG(hw, REG_SPI_FLASH_CTRL);
	if (value & SPI_FLASH_CTRL_EN_VPD) {
		value &= ~SPI_FLASH_CTRL_EN_VPD;
		AT_WRITE_REG(hw, REG_SPI_FLASH_CTRL, value);
	}
	value = AT_READ_REGW(hw, REG_PCIE_CAP_LIST);
	return ((value & 0xFF00) == 0x6C00) ? 0 : 1;
}

void atl1e_hw_set_mac_addr(struct atl1e_hw *hw)
{
	u32 value;
	/*
	 * 00-0B-6A-F6-00-DC
	 * 0:  6AF600DC 1: 000B
	 * low dword
	 */
	value = (((u32)hw->mac_addr[2]) << 24) |
		(((u32)hw->mac_addr[3]) << 16) |
		(((u32)hw->mac_addr[4]) << 8)  |
		(((u32)hw->mac_addr[5])) ;
	AT_WRITE_REG_ARRAY(hw, REG_MAC_STA_ADDR, 0, value);
	/* hight dword */
	value = (((u32)hw->mac_addr[0]) << 8) |
		(((u32)hw->mac_addr[1])) ;
	AT_WRITE_REG_ARRAY(hw, REG_MAC_STA_ADDR, 1, value);
}

__attribute__((used)) static int atl1e_get_permanent_address(struct atl1e_hw *hw)
{
	u32 addr[2];
	u32 i;
	u32 twsi_ctrl_data;
	u8  eth_addr[ETH_ALEN];

	if (is_valid_ether_addr(hw->perm_mac_addr))
		return 0;

	/* init */
	addr[0] = addr[1] = 0;

	if (!atl1e_check_eeprom_exist(hw)) {
		/* eeprom exist */
		twsi_ctrl_data = AT_READ_REG(hw, REG_TWSI_CTRL);
		twsi_ctrl_data |= TWSI_CTRL_SW_LDSTART;
		AT_WRITE_REG(hw, REG_TWSI_CTRL, twsi_ctrl_data);
		for (i = 0; i < AT_TWSI_EEPROM_TIMEOUT; i++) {
			msleep(10);
			twsi_ctrl_data = AT_READ_REG(hw, REG_TWSI_CTRL);
			if ((twsi_ctrl_data & TWSI_CTRL_SW_LDSTART) == 0)
				break;
		}
		if (i >= AT_TWSI_EEPROM_TIMEOUT)
			return AT_ERR_TIMEOUT;
	}

	/* maybe MAC-address is from BIOS */
	addr[0] = AT_READ_REG(hw, REG_MAC_STA_ADDR);
	addr[1] = AT_READ_REG(hw, REG_MAC_STA_ADDR + 4);
	*(u32 *) &eth_addr[2] = swab32(addr[0]);
	*(u16 *) &eth_addr[0] = swab16(*(u16 *)&addr[1]);

	if (is_valid_ether_addr(eth_addr)) {
		memcpy(hw->perm_mac_addr, eth_addr, ETH_ALEN);
		return 0;
	}

	return AT_ERR_EEPROM;
}

bool atl1e_write_eeprom(struct atl1e_hw *hw, u32 offset, u32 value)
{
	return true;
}

bool atl1e_read_eeprom(struct atl1e_hw *hw, u32 offset, u32 *p_value)
{
	int i;
	u32 control;

	if (offset & 3)
		return false; /* address do not align */

	AT_WRITE_REG(hw, REG_VPD_DATA, 0);
	control = (offset & VPD_CAP_VPD_ADDR_MASK) << VPD_CAP_VPD_ADDR_SHIFT;
	AT_WRITE_REG(hw, REG_VPD_CAP, control);

	for (i = 0; i < 10; i++) {
		msleep(2);
		control = AT_READ_REG(hw, REG_VPD_CAP);
		if (control & VPD_CAP_VPD_FLAG)
			break;
	}
	if (control & VPD_CAP_VPD_FLAG) {
		*p_value = AT_READ_REG(hw, REG_VPD_DATA);
		return true;
	}
	return false; /* timeout */
}

void atl1e_force_ps(struct atl1e_hw *hw)
{
	AT_WRITE_REGW(hw, REG_GPHY_CTRL,
			GPHY_CTRL_PW_WOL_DIS | GPHY_CTRL_EXT_RESET);
}

int atl1e_read_mac_addr(struct atl1e_hw *hw)
{
	int err = 0;

	err = atl1e_get_permanent_address(hw);
	if (err)
		return AT_ERR_EEPROM;
	memcpy(hw->mac_addr, hw->perm_mac_addr, sizeof(hw->perm_mac_addr));
	return 0;
}

u32 atl1e_hash_mc_addr(struct atl1e_hw *hw, u8 *mc_addr)
{
	u32 crc32;
	u32 value = 0;
	int i;

	crc32 = ether_crc_le(6, mc_addr);
	for (i = 0; i < 32; i++)
		value |= (((crc32 >> i) & 1) << (31 - i));

	return value;
}

void atl1e_hash_set(struct atl1e_hw *hw, u32 hash_value)
{
	u32 hash_bit, hash_reg;
	u32 mta;

	/*
	 * The HASH Table  is a register array of 2 32-bit registers.
	 * It is treated like an array of 64 bits.  We want to set
	 * bit BitArray[hash_value]. So we figure out what register
	 * the bit is in, read it, OR in the new bit, then write
	 * back the new value.  The register is determined by the
	 * upper 7 bits of the hash value and the bit within that
	 * register are determined by the lower 5 bits of the value.
	 */
	hash_reg = (hash_value >> 31) & 0x1;
	hash_bit = (hash_value >> 26) & 0x1F;

	mta = AT_READ_REG_ARRAY(hw, REG_RX_HASH_TABLE, hash_reg);

	mta |= (1 << hash_bit);

	AT_WRITE_REG_ARRAY(hw, REG_RX_HASH_TABLE, hash_reg, mta);
}

int atl1e_read_phy_reg(struct atl1e_hw *hw, u16 reg_addr, u16 *phy_data)
{
	u32 val;
	int i;

	val = ((u32)(reg_addr & MDIO_REG_ADDR_MASK)) << MDIO_REG_ADDR_SHIFT |
		MDIO_START | MDIO_SUP_PREAMBLE | MDIO_RW |
		MDIO_CLK_25_4 << MDIO_CLK_SEL_SHIFT;

	AT_WRITE_REG(hw, REG_MDIO_CTRL, val);

	wmb();

	for (i = 0; i < MDIO_WAIT_TIMES; i++) {
		udelay(2);
		val = AT_READ_REG(hw, REG_MDIO_CTRL);
		if (!(val & (MDIO_START | MDIO_BUSY)))
			break;
		wmb();
	}
	if (!(val & (MDIO_START | MDIO_BUSY))) {
		*phy_data = (u16)val;
		return 0;
	}

	return AT_ERR_PHY;
}

int atl1e_write_phy_reg(struct atl1e_hw *hw, u32 reg_addr, u16 phy_data)
{
	int i;
	u32 val;

	val = ((u32)(phy_data & MDIO_DATA_MASK)) << MDIO_DATA_SHIFT |
	       (reg_addr&MDIO_REG_ADDR_MASK) << MDIO_REG_ADDR_SHIFT |
	       MDIO_SUP_PREAMBLE |
	       MDIO_START |
	       MDIO_CLK_25_4 << MDIO_CLK_SEL_SHIFT;

	AT_WRITE_REG(hw, REG_MDIO_CTRL, val);
	wmb();

	for (i = 0; i < MDIO_WAIT_TIMES; i++) {
		udelay(2);
		val = AT_READ_REG(hw, REG_MDIO_CTRL);
		if (!(val & (MDIO_START | MDIO_BUSY)))
			break;
		wmb();
	}

	if (!(val & (MDIO_START | MDIO_BUSY)))
		return 0;

	return AT_ERR_PHY;
}

__attribute__((used)) static void atl1e_init_pcie(struct atl1e_hw *hw)
{
	u32 value;
	/* comment 2lines below to save more power when sususpend
	   value = LTSSM_TEST_MODE_DEF;
	   AT_WRITE_REG(hw, REG_LTSSM_TEST_MODE, value);
	 */

	/* pcie flow control mode change */
	value = AT_READ_REG(hw, 0x1008);
	value |= 0x8000;
	AT_WRITE_REG(hw, 0x1008, value);
}

__attribute__((used)) static int atl1e_phy_setup_autoneg_adv(struct atl1e_hw *hw)
{
	s32 ret_val;
	u16 mii_autoneg_adv_reg;
	u16 mii_1000t_ctrl_reg;

	if (0 != hw->mii_autoneg_adv_reg)
		return 0;
	/* Read the MII Auto-Neg Advertisement Register (Address 4/9). */
	mii_autoneg_adv_reg = MII_AR_DEFAULT_CAP_MASK;
	mii_1000t_ctrl_reg  = MII_AT001_CR_1000T_DEFAULT_CAP_MASK;

	/*
	 * Need to parse autoneg_advertised  and set up
	 * the appropriate PHY registers.  First we will parse for
	 * autoneg_advertised software override.  Since we can advertise
	 * a plethora of combinations, we need to check each bit
	 * individually.
	 */

	/*
	 * First we clear all the 10/100 mb speed bits in the Auto-Neg
	 * Advertisement Register (Address 4) and the 1000 mb speed bits in
	 * the  1000Base-T control Register (Address 9).
	 */
	mii_autoneg_adv_reg &= ~ADVERTISE_ALL;
	mii_1000t_ctrl_reg  &= ~MII_AT001_CR_1000T_SPEED_MASK;

	/*
	 * Need to parse MediaType and setup the
	 * appropriate PHY registers.
	 */
	switch (hw->media_type) {
	case MEDIA_TYPE_AUTO_SENSOR:
		mii_autoneg_adv_reg |= ADVERTISE_ALL;
		hw->autoneg_advertised = ADVERTISE_ALL;
		if (hw->nic_type == athr_l1e) {
			mii_1000t_ctrl_reg |= ADVERTISE_1000FULL;
			hw->autoneg_advertised |= ADVERTISE_1000_FULL;
		}
		break;

	case MEDIA_TYPE_100M_FULL:
		mii_autoneg_adv_reg   |= ADVERTISE_100FULL;
		hw->autoneg_advertised = ADVERTISE_100_FULL;
		break;

	case MEDIA_TYPE_100M_HALF:
		mii_autoneg_adv_reg   |= ADVERTISE_100_HALF;
		hw->autoneg_advertised = ADVERTISE_100_HALF;
		break;

	case MEDIA_TYPE_10M_FULL:
		mii_autoneg_adv_reg   |= ADVERTISE_10_FULL;
		hw->autoneg_advertised = ADVERTISE_10_FULL;
		break;

	default:
		mii_autoneg_adv_reg   |= ADVERTISE_10_HALF;
		hw->autoneg_advertised = ADVERTISE_10_HALF;
		break;
	}

	/* flow control fixed to enable all */
	mii_autoneg_adv_reg |= (ADVERTISE_PAUSE_ASYM | ADVERTISE_PAUSE_CAP);

	hw->mii_autoneg_adv_reg = mii_autoneg_adv_reg;
	hw->mii_1000t_ctrl_reg  = mii_1000t_ctrl_reg;

	ret_val = atl1e_write_phy_reg(hw, MII_ADVERTISE, mii_autoneg_adv_reg);
	if (ret_val)
		return ret_val;

	if (hw->nic_type == athr_l1e || hw->nic_type == athr_l2e_revA) {
		ret_val = atl1e_write_phy_reg(hw, MII_CTRL1000,
					   mii_1000t_ctrl_reg);
		if (ret_val)
			return ret_val;
	}

	return 0;
}

int atl1e_phy_commit(struct atl1e_hw *hw)
{
	struct atl1e_adapter *adapter = hw->adapter;
	int ret_val;
	u16 phy_data;

	phy_data = BMCR_RESET | BMCR_ANENABLE | BMCR_ANRESTART;

	ret_val = atl1e_write_phy_reg(hw, MII_BMCR, phy_data);
	if (ret_val) {
		u32 val;
		int i;
		/**************************************
		 * pcie serdes link may be down !
		 **************************************/
		for (i = 0; i < 25; i++) {
			msleep(1);
			val = AT_READ_REG(hw, REG_MDIO_CTRL);
			if (!(val & (MDIO_START | MDIO_BUSY)))
				break;
		}

		if (0 != (val & (MDIO_START | MDIO_BUSY))) {
			netdev_err(adapter->netdev,
				   "pcie linkdown at least for 25ms\n");
			return ret_val;
		}

		netdev_err(adapter->netdev, "pcie linkup after %d ms\n", i);
	}
	return 0;
}

int atl1e_phy_init(struct atl1e_hw *hw)
{
	struct atl1e_adapter *adapter = hw->adapter;
	s32 ret_val;
	u16 phy_val;

	if (hw->phy_configured) {
		if (hw->re_autoneg) {
			hw->re_autoneg = false;
			return atl1e_restart_autoneg(hw);
		}
		return 0;
	}

	/* RESET GPHY Core */
	AT_WRITE_REGW(hw, REG_GPHY_CTRL, GPHY_CTRL_DEFAULT);
	msleep(2);
	AT_WRITE_REGW(hw, REG_GPHY_CTRL, GPHY_CTRL_DEFAULT |
		      GPHY_CTRL_EXT_RESET);
	msleep(2);

	/* patches */
	/* p1. eable hibernation mode */
	ret_val = atl1e_write_phy_reg(hw, MII_DBG_ADDR, 0xB);
	if (ret_val)
		return ret_val;
	ret_val = atl1e_write_phy_reg(hw, MII_DBG_DATA, 0xBC00);
	if (ret_val)
		return ret_val;
	/* p2. set Class A/B for all modes */
	ret_val = atl1e_write_phy_reg(hw, MII_DBG_ADDR, 0);
	if (ret_val)
		return ret_val;
	phy_val = 0x02ef;
	/* remove Class AB */
	/* phy_val = hw->emi_ca ? 0x02ef : 0x02df; */
	ret_val = atl1e_write_phy_reg(hw, MII_DBG_DATA, phy_val);
	if (ret_val)
		return ret_val;
	/* p3. 10B ??? */
	ret_val = atl1e_write_phy_reg(hw, MII_DBG_ADDR, 0x12);
	if (ret_val)
		return ret_val;
	ret_val = atl1e_write_phy_reg(hw, MII_DBG_DATA, 0x4C04);
	if (ret_val)
		return ret_val;
	/* p4. 1000T power */
	ret_val = atl1e_write_phy_reg(hw, MII_DBG_ADDR, 0x4);
	if (ret_val)
		return ret_val;
	ret_val = atl1e_write_phy_reg(hw, MII_DBG_DATA, 0x8BBB);
	if (ret_val)
		return ret_val;

	ret_val = atl1e_write_phy_reg(hw, MII_DBG_ADDR, 0x5);
	if (ret_val)
		return ret_val;
	ret_val = atl1e_write_phy_reg(hw, MII_DBG_DATA, 0x2C46);
	if (ret_val)
		return ret_val;

	msleep(1);

	/*Enable PHY LinkChange Interrupt */
	ret_val = atl1e_write_phy_reg(hw, MII_INT_CTRL, 0xC00);
	if (ret_val) {
		netdev_err(adapter->netdev,
			   "Error enable PHY linkChange Interrupt\n");
		return ret_val;
	}
	/* setup AutoNeg parameters */
	ret_val = atl1e_phy_setup_autoneg_adv(hw);
	if (ret_val) {
		netdev_err(adapter->netdev,
			   "Error Setting up Auto-Negotiation\n");
		return ret_val;
	}
	/* SW.Reset & En-Auto-Neg to restart Auto-Neg*/
	netdev_dbg(adapter->netdev, "Restarting Auto-Negotiation\n");
	ret_val = atl1e_phy_commit(hw);
	if (ret_val) {
		netdev_err(adapter->netdev, "Error resetting the phy\n");
		return ret_val;
	}

	hw->phy_configured = true;

	return 0;
}

int atl1e_reset_hw(struct atl1e_hw *hw)
{
	struct atl1e_adapter *adapter = hw->adapter;
	struct pci_dev *pdev = adapter->pdev;

	u32 idle_status_data = 0;
	u16 pci_cfg_cmd_word = 0;
	int timeout = 0;

	/* Workaround for PCI problem when BIOS sets MMRBC incorrectly. */
	pci_read_config_word(pdev, PCI_REG_COMMAND, &pci_cfg_cmd_word);
	if ((pci_cfg_cmd_word & (CMD_IO_SPACE |
				CMD_MEMORY_SPACE | CMD_BUS_MASTER))
			!= (CMD_IO_SPACE | CMD_MEMORY_SPACE | CMD_BUS_MASTER)) {
		pci_cfg_cmd_word |= (CMD_IO_SPACE |
				     CMD_MEMORY_SPACE | CMD_BUS_MASTER);
		pci_write_config_word(pdev, PCI_REG_COMMAND, pci_cfg_cmd_word);
	}

	/*
	 * Issue Soft Reset to the MAC.  This will reset the chip's
	 * transmit, receive, DMA.  It will not effect
	 * the current PCI configuration.  The global reset bit is self-
	 * clearing, and should clear within a microsecond.
	 */
	AT_WRITE_REG(hw, REG_MASTER_CTRL,
			MASTER_CTRL_LED_MODE | MASTER_CTRL_SOFT_RST);
	wmb();
	msleep(1);

	/* Wait at least 10ms for All module to be Idle */
	for (timeout = 0; timeout < AT_HW_MAX_IDLE_DELAY; timeout++) {
		idle_status_data = AT_READ_REG(hw, REG_IDLE_STATUS);
		if (idle_status_data == 0)
			break;
		msleep(1);
		cpu_relax();
	}

	if (timeout >= AT_HW_MAX_IDLE_DELAY) {
		netdev_err(adapter->netdev,
			   "MAC state machine can't be idle since disabled for 10ms second\n");
		return AT_ERR_TIMEOUT;
	}

	return 0;
}

int atl1e_init_hw(struct atl1e_hw *hw)
{
	s32 ret_val = 0;

	atl1e_init_pcie(hw);

	/* Zero out the Multicast HASH table */
	/* clear the old settings from the multicast hash table */
	AT_WRITE_REG(hw, REG_RX_HASH_TABLE, 0);
	AT_WRITE_REG_ARRAY(hw, REG_RX_HASH_TABLE, 1, 0);

	ret_val = atl1e_phy_init(hw);

	return ret_val;
}

int atl1e_get_speed_and_duplex(struct atl1e_hw *hw, u16 *speed, u16 *duplex)
{
	int err;
	u16 phy_data;

	/* Read   PHY Specific Status Register (17) */
	err = atl1e_read_phy_reg(hw, MII_AT001_PSSR, &phy_data);
	if (err)
		return err;

	if (!(phy_data & MII_AT001_PSSR_SPD_DPLX_RESOLVED))
		return AT_ERR_PHY_RES;

	switch (phy_data & MII_AT001_PSSR_SPEED) {
	case MII_AT001_PSSR_1000MBS:
		*speed = SPEED_1000;
		break;
	case MII_AT001_PSSR_100MBS:
		*speed = SPEED_100;
		break;
	case MII_AT001_PSSR_10MBS:
		*speed = SPEED_10;
		break;
	default:
		return AT_ERR_PHY_SPEED;
	}

	if (phy_data & MII_AT001_PSSR_DPLX)
		*duplex = FULL_DUPLEX;
	else
		*duplex = HALF_DUPLEX;

	return 0;
}

int atl1e_restart_autoneg(struct atl1e_hw *hw)
{
	int err = 0;

	err = atl1e_write_phy_reg(hw, MII_ADVERTISE, hw->mii_autoneg_adv_reg);
	if (err)
		return err;

	if (hw->nic_type == athr_l1e || hw->nic_type == athr_l2e_revA) {
		err = atl1e_write_phy_reg(hw, MII_CTRL1000,
				       hw->mii_1000t_ctrl_reg);
		if (err)
			return err;
	}

	err = atl1e_write_phy_reg(hw, MII_BMCR,
			BMCR_RESET | BMCR_ANENABLE | BMCR_ANRESTART);
	return err;
}

