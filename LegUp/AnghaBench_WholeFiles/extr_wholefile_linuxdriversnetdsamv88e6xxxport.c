#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u16 ;
struct phylink_link_state {int duplex; int link; int an_enabled; int an_complete; int const interface; void* speed; } ;
struct mv88e6xxx_chip {int /*<<< orphan*/  dev; TYPE_2__* ports; TYPE_1__* info; } ;
typedef  int phy_interface_t ;
typedef  enum mv88e6xxx_frame_mode { ____Placeholder_mv88e6xxx_frame_mode } mv88e6xxx_frame_mode ;
typedef  enum mv88e6xxx_egress_mode { ____Placeholder_mv88e6xxx_egress_mode } mv88e6xxx_egress_mode ;
struct TYPE_4__ {int cmode; scalar_t__ serdes_irq; } ;
struct TYPE_3__ {int pvt; unsigned int num_databases; unsigned int num_ports; unsigned int num_gpio; int port_base_addr; } ;

/* Variables and functions */
#define  BR_STATE_BLOCKING 161 
#define  BR_STATE_DISABLED 160 
#define  BR_STATE_FORWARDING 159 
#define  BR_STATE_LEARNING 158 
#define  BR_STATE_LISTENING 157 
#define  DUPLEX_FULL 156 
#define  DUPLEX_HALF 155 
#define  DUPLEX_UNFORCED 154 
 int const DUPLEX_UNKNOWN ; 
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int ERANGE ; 
 int GENMASK (unsigned int,int /*<<< orphan*/ ) ; 
#define  LINK_FORCED_DOWN 153 
#define  LINK_FORCED_UP 152 
#define  LINK_UNFORCED 151 
 int MV88E6065_PORT_MAC_CTL_SPEED_200 ; 
 int MV88E6095_PORT_CTL2_CPU_PORT_MASK ; 
 int MV88E6095_PORT_IEEE_PRIO_REMAP_0123 ; 
 int MV88E6095_PORT_IEEE_PRIO_REMAP_4567 ; 
 int MV88E6097_PORT_JAM_CTL ; 
 int MV88E6185_PORT_CTL0_FORWARD_UNKNOWN ; 
 int MV88E6185_PORT_MAC_CTL_AN_DONE ; 
 int MV88E6185_PORT_MAC_CTL_SYNC_OK ; 
 int MV88E6185_PORT_STS_CMODE_MASK ; 
 scalar_t__ MV88E6185_PORT_STS_CMODE_SERDES ; 
 int MV88E6352_PORT_CTL0_EGRESS_FLOODS_ALL_UNKNOWN_DA ; 
 int MV88E6352_PORT_CTL0_EGRESS_FLOODS_MASK ; 
 int MV88E6352_PORT_CTL0_EGRESS_FLOODS_NO_UNKNOWN_DA ; 
 int MV88E6352_PORT_CTL0_EGRESS_FLOODS_NO_UNKNOWN_MC_DA ; 
 int MV88E6352_PORT_CTL0_EGRESS_FLOODS_NO_UNKNOWN_UC_DA ; 
 int MV88E6390_PORT_FLOW_CTL ; 
 scalar_t__ MV88E6390_PORT_FLOW_CTL_LIMIT_IN ; 
 scalar_t__ MV88E6390_PORT_FLOW_CTL_LIMIT_OUT ; 
 scalar_t__ MV88E6390_PORT_FLOW_CTL_UPDATE ; 
 int MV88E6390_PORT_IEEE_PRIO_MAP_TABLE ; 
 int MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_DATA_MASK ; 
 int MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_EGRESS_AVB_PCP ; 
 int MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_EGRESS_GREEN_PCP ; 
 int MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_EGRESS_YELLOW_PCP ; 
 int MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_INGRESS_PCP ; 
 int /*<<< orphan*/  MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_PTR_MASK ; 
 int MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_UPDATE ; 
 int MV88E6390_PORT_MAC_CTL_ALTSPEED ; 
 int MV88E6390_PORT_MAC_CTL_FORCE_SPEED ; 
 int MV88E6390_PORT_MAC_CTL_SPEED_10000 ; 
#define  MV88E6XXX_EGRESS_MODE_ETHERTYPE 150 
#define  MV88E6XXX_EGRESS_MODE_TAGGED 149 
#define  MV88E6XXX_EGRESS_MODE_UNMODIFIED 148 
#define  MV88E6XXX_EGRESS_MODE_UNTAGGED 147 
#define  MV88E6XXX_FRAME_MODE_DSA 146 
#define  MV88E6XXX_FRAME_MODE_ETHERTYPE 145 
#define  MV88E6XXX_FRAME_MODE_NORMAL 144 
#define  MV88E6XXX_FRAME_MODE_PROVIDER 143 
 int MV88E6XXX_PORT_ATU_CTL ; 
 int MV88E6XXX_PORT_BASE_VLAN ; 
 int MV88E6XXX_PORT_CTL0 ; 
 int MV88E6XXX_PORT_CTL0_EGRESS_MODE_ETHER_TYPE_DSA ; 
 int MV88E6XXX_PORT_CTL0_EGRESS_MODE_MASK ; 
 int MV88E6XXX_PORT_CTL0_EGRESS_MODE_TAGGED ; 
 int MV88E6XXX_PORT_CTL0_EGRESS_MODE_UNMODIFIED ; 
 int MV88E6XXX_PORT_CTL0_EGRESS_MODE_UNTAGGED ; 
 int MV88E6XXX_PORT_CTL0_FRAME_MODE_DSA ; 
 int MV88E6XXX_PORT_CTL0_FRAME_MODE_ETHER_TYPE_DSA ; 
 int MV88E6XXX_PORT_CTL0_FRAME_MODE_MASK ; 
 int MV88E6XXX_PORT_CTL0_FRAME_MODE_NORMAL ; 
 int MV88E6XXX_PORT_CTL0_FRAME_MODE_PROVIDER ; 
 scalar_t__ MV88E6XXX_PORT_CTL0_STATE_BLOCKING ; 
 scalar_t__ MV88E6XXX_PORT_CTL0_STATE_DISABLED ; 
 scalar_t__ MV88E6XXX_PORT_CTL0_STATE_FORWARDING ; 
 scalar_t__ MV88E6XXX_PORT_CTL0_STATE_LEARNING ; 
 int MV88E6XXX_PORT_CTL0_STATE_MASK ; 
 int MV88E6XXX_PORT_CTL1 ; 
 int MV88E6XXX_PORT_CTL1_MESSAGE_PORT ; 
 int MV88E6XXX_PORT_CTL2 ; 
 int MV88E6XXX_PORT_CTL2_8021Q_MODE_MASK ; 
 int MV88E6XXX_PORT_CTL2_DEFAULT_FORWARD ; 
 int MV88E6XXX_PORT_CTL2_JUMBO_MODE_10240 ; 
 int MV88E6XXX_PORT_CTL2_JUMBO_MODE_1522 ; 
 int MV88E6XXX_PORT_CTL2_JUMBO_MODE_2048 ; 
 int MV88E6XXX_PORT_CTL2_JUMBO_MODE_MASK ; 
 int MV88E6XXX_PORT_CTL2_MAP_DA ; 
 int MV88E6XXX_PORT_DEFAULT_VLAN ; 
 int MV88E6XXX_PORT_DEFAULT_VLAN_MASK ; 
 int MV88E6XXX_PORT_EGRESS_RATE_CTL1 ; 
 int MV88E6XXX_PORT_ETH_TYPE ; 
 int MV88E6XXX_PORT_MAC_CTL ; 
 int MV88E6XXX_PORT_MAC_CTL_DUPLEX_FULL ; 
 int MV88E6XXX_PORT_MAC_CTL_FORCE_DUPLEX ; 
 int MV88E6XXX_PORT_MAC_CTL_FORCE_LINK ; 
 int MV88E6XXX_PORT_MAC_CTL_LINK_UP ; 
 int MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_RXCLK ; 
 int MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_TXCLK ; 
 int MV88E6XXX_PORT_MAC_CTL_SPEED_10 ; 
 int MV88E6XXX_PORT_MAC_CTL_SPEED_100 ; 
 int MV88E6XXX_PORT_MAC_CTL_SPEED_1000 ; 
 int MV88E6XXX_PORT_MAC_CTL_SPEED_MASK ; 
 int MV88E6XXX_PORT_MAC_CTL_SPEED_UNFORCED ; 
 int MV88E6XXX_PORT_PRI_OVERRIDE ; 
 int MV88E6XXX_PORT_STS ; 
 int MV88E6XXX_PORT_STS_CMODE_1000BASE_X ; 
 int MV88E6XXX_PORT_STS_CMODE_2500BASEX ; 
 int MV88E6XXX_PORT_STS_CMODE_MASK ; 
 int MV88E6XXX_PORT_STS_CMODE_RXAUI ; 
 int MV88E6XXX_PORT_STS_CMODE_SGMII ; 
 int MV88E6XXX_PORT_STS_CMODE_XAUI ; 
 int MV88E6XXX_PORT_STS_DUPLEX ; 
 int MV88E6XXX_PORT_STS_LINK ; 
 int MV88E6XXX_PORT_STS_MY_PAUSE ; 
#define  MV88E6XXX_PORT_STS_SPEED_10 142 
#define  MV88E6XXX_PORT_STS_SPEED_100 141 
#define  MV88E6XXX_PORT_STS_SPEED_1000 140 
#define  MV88E6XXX_PORT_STS_SPEED_10000 139 
 int MV88E6XXX_PORT_STS_SPEED_MASK ; 
#define  PHY_INTERFACE_MODE_1000BASEX 138 
#define  PHY_INTERFACE_MODE_2500BASEX 137 
 int PHY_INTERFACE_MODE_NA ; 
#define  PHY_INTERFACE_MODE_RGMII 136 
#define  PHY_INTERFACE_MODE_RGMII_ID 135 
#define  PHY_INTERFACE_MODE_RGMII_RXID 134 
#define  PHY_INTERFACE_MODE_RGMII_TXID 133 
#define  PHY_INTERFACE_MODE_RXAUI 132 
#define  PHY_INTERFACE_MODE_SGMII 131 
#define  PHY_INTERFACE_MODE_XAUI 130 
#define  PHY_INTERFACE_MODE_XGMII 129 
 void* SPEED_10 ; 
 void* SPEED_100 ; 
 void* SPEED_1000 ; 
 void* SPEED_10000 ; 
 void* SPEED_2500 ; 
 int SPEED_MAX ; 
#define  SPEED_UNFORCED 128 
 void* SPEED_UNKNOWN ; 
 scalar_t__ __bf_shf (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,...) ; 
 int mv88e6390_serdes_irq_disable (struct mv88e6xxx_chip*,int,int) ; 
 int mv88e6390_serdes_irq_enable (struct mv88e6xxx_chip*,int,int) ; 
 int mv88e6390x_serdes_get_lane (struct mv88e6xxx_chip*,int) ; 
 int mv88e6390x_serdes_power (struct mv88e6xxx_chip*,int,int) ; 
 int* mv88e6xxx_port_8021q_mode_names ; 
 int* mv88e6xxx_port_state_names ; 
 int mv88e6xxx_read (struct mv88e6xxx_chip*,int,int,int*) ; 
 int mv88e6xxx_write (struct mv88e6xxx_chip*,int,int,int) ; 

__attribute__((used)) static inline bool mv88e6xxx_has_pvt(struct mv88e6xxx_chip *chip)
{
	return chip->info->pvt;
}

__attribute__((used)) static inline unsigned int mv88e6xxx_num_databases(struct mv88e6xxx_chip *chip)
{
	return chip->info->num_databases;
}

__attribute__((used)) static inline unsigned int mv88e6xxx_num_ports(struct mv88e6xxx_chip *chip)
{
	return chip->info->num_ports;
}

__attribute__((used)) static inline u16 mv88e6xxx_port_mask(struct mv88e6xxx_chip *chip)
{
	return GENMASK(mv88e6xxx_num_ports(chip) - 1, 0);
}

__attribute__((used)) static inline unsigned int mv88e6xxx_num_gpio(struct mv88e6xxx_chip *chip)
{
	return chip->info->num_gpio;
}

int mv88e6xxx_port_read(struct mv88e6xxx_chip *chip, int port, int reg,
			u16 *val)
{
	int addr = chip->info->port_base_addr + port;

	return mv88e6xxx_read(chip, addr, reg, val);
}

int mv88e6xxx_port_write(struct mv88e6xxx_chip *chip, int port, int reg,
			 u16 val)
{
	int addr = chip->info->port_base_addr + port;

	return mv88e6xxx_write(chip, addr, reg, val);
}

int mv88e6185_port_set_pause(struct mv88e6xxx_chip *chip, int port,
			     int pause)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_STS, &reg);
	if (err)
		return err;

	if (pause)
		reg |= MV88E6XXX_PORT_STS_MY_PAUSE;
	else
		reg &= ~MV88E6XXX_PORT_STS_MY_PAUSE;

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_STS, reg);
}

__attribute__((used)) static int mv88e6xxx_port_set_rgmii_delay(struct mv88e6xxx_chip *chip, int port,
					  phy_interface_t mode)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_MAC_CTL, &reg);
	if (err)
		return err;

	reg &= ~(MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_RXCLK |
		 MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_TXCLK);

	switch (mode) {
	case PHY_INTERFACE_MODE_RGMII_RXID:
		reg |= MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_RXCLK;
		break;
	case PHY_INTERFACE_MODE_RGMII_TXID:
		reg |= MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_TXCLK;
		break;
	case PHY_INTERFACE_MODE_RGMII_ID:
		reg |= MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_RXCLK |
			MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_TXCLK;
		break;
	case PHY_INTERFACE_MODE_RGMII:
		break;
	default:
		return 0;
	}

	err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_MAC_CTL, reg);
	if (err)
		return err;

	dev_dbg(chip->dev, "p%d: delay RXCLK %s, TXCLK %s\n", port,
		reg & MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_RXCLK ? "yes" : "no",
		reg & MV88E6XXX_PORT_MAC_CTL_RGMII_DELAY_TXCLK ? "yes" : "no");

	return 0;
}

int mv88e6352_port_set_rgmii_delay(struct mv88e6xxx_chip *chip, int port,
				   phy_interface_t mode)
{
	if (port < 5)
		return -EOPNOTSUPP;

	return mv88e6xxx_port_set_rgmii_delay(chip, port, mode);
}

int mv88e6390_port_set_rgmii_delay(struct mv88e6xxx_chip *chip, int port,
				   phy_interface_t mode)
{
	if (port != 0)
		return -EOPNOTSUPP;

	return mv88e6xxx_port_set_rgmii_delay(chip, port, mode);
}

int mv88e6xxx_port_set_link(struct mv88e6xxx_chip *chip, int port, int link)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_MAC_CTL, &reg);
	if (err)
		return err;

	reg &= ~(MV88E6XXX_PORT_MAC_CTL_FORCE_LINK |
		 MV88E6XXX_PORT_MAC_CTL_LINK_UP);

	switch (link) {
	case LINK_FORCED_DOWN:
		reg |= MV88E6XXX_PORT_MAC_CTL_FORCE_LINK;
		break;
	case LINK_FORCED_UP:
		reg |= MV88E6XXX_PORT_MAC_CTL_FORCE_LINK |
			MV88E6XXX_PORT_MAC_CTL_LINK_UP;
		break;
	case LINK_UNFORCED:
		/* normal link detection */
		break;
	default:
		return -EINVAL;
	}

	err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_MAC_CTL, reg);
	if (err)
		return err;

	dev_dbg(chip->dev, "p%d: %s link %s\n", port,
		reg & MV88E6XXX_PORT_MAC_CTL_FORCE_LINK ? "Force" : "Unforce",
		reg & MV88E6XXX_PORT_MAC_CTL_LINK_UP ? "up" : "down");

	return 0;
}

int mv88e6xxx_port_set_duplex(struct mv88e6xxx_chip *chip, int port, int dup)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_MAC_CTL, &reg);
	if (err)
		return err;

	reg &= ~(MV88E6XXX_PORT_MAC_CTL_FORCE_DUPLEX |
		 MV88E6XXX_PORT_MAC_CTL_DUPLEX_FULL);

	switch (dup) {
	case DUPLEX_HALF:
		reg |= MV88E6XXX_PORT_MAC_CTL_FORCE_DUPLEX;
		break;
	case DUPLEX_FULL:
		reg |= MV88E6XXX_PORT_MAC_CTL_FORCE_DUPLEX |
			MV88E6XXX_PORT_MAC_CTL_DUPLEX_FULL;
		break;
	case DUPLEX_UNFORCED:
		/* normal duplex detection */
		break;
	default:
		return -EOPNOTSUPP;
	}

	err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_MAC_CTL, reg);
	if (err)
		return err;

	dev_dbg(chip->dev, "p%d: %s %s duplex\n", port,
		reg & MV88E6XXX_PORT_MAC_CTL_FORCE_DUPLEX ? "Force" : "Unforce",
		reg & MV88E6XXX_PORT_MAC_CTL_DUPLEX_FULL ? "full" : "half");

	return 0;
}

__attribute__((used)) static int mv88e6xxx_port_set_speed(struct mv88e6xxx_chip *chip, int port,
				    int speed, bool alt_bit, bool force_bit)
{
	u16 reg, ctrl;
	int err;

	switch (speed) {
	case 10:
		ctrl = MV88E6XXX_PORT_MAC_CTL_SPEED_10;
		break;
	case 100:
		ctrl = MV88E6XXX_PORT_MAC_CTL_SPEED_100;
		break;
	case 200:
		if (alt_bit)
			ctrl = MV88E6XXX_PORT_MAC_CTL_SPEED_100 |
				MV88E6390_PORT_MAC_CTL_ALTSPEED;
		else
			ctrl = MV88E6065_PORT_MAC_CTL_SPEED_200;
		break;
	case 1000:
		ctrl = MV88E6XXX_PORT_MAC_CTL_SPEED_1000;
		break;
	case 2500:
		ctrl = MV88E6390_PORT_MAC_CTL_SPEED_10000 |
			MV88E6390_PORT_MAC_CTL_ALTSPEED;
		break;
	case 10000:
		/* all bits set, fall through... */
	case SPEED_UNFORCED:
		ctrl = MV88E6XXX_PORT_MAC_CTL_SPEED_UNFORCED;
		break;
	default:
		return -EOPNOTSUPP;
	}

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_MAC_CTL, &reg);
	if (err)
		return err;

	reg &= ~MV88E6XXX_PORT_MAC_CTL_SPEED_MASK;
	if (alt_bit)
		reg &= ~MV88E6390_PORT_MAC_CTL_ALTSPEED;
	if (force_bit) {
		reg &= ~MV88E6390_PORT_MAC_CTL_FORCE_SPEED;
		if (speed != SPEED_UNFORCED)
			ctrl |= MV88E6390_PORT_MAC_CTL_FORCE_SPEED;
	}
	reg |= ctrl;

	err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_MAC_CTL, reg);
	if (err)
		return err;

	if (speed)
		dev_dbg(chip->dev, "p%d: Speed set to %d Mbps\n", port, speed);
	else
		dev_dbg(chip->dev, "p%d: Speed unforced\n", port);

	return 0;
}

int mv88e6065_port_set_speed(struct mv88e6xxx_chip *chip, int port, int speed)
{
	if (speed == SPEED_MAX)
		speed = 200;

	if (speed > 200)
		return -EOPNOTSUPP;

	/* Setting 200 Mbps on port 0 to 3 selects 100 Mbps */
	return mv88e6xxx_port_set_speed(chip, port, speed, false, false);
}

int mv88e6185_port_set_speed(struct mv88e6xxx_chip *chip, int port, int speed)
{
	if (speed == SPEED_MAX)
		speed = 1000;

	if (speed == 200 || speed > 1000)
		return -EOPNOTSUPP;

	return mv88e6xxx_port_set_speed(chip, port, speed, false, false);
}

int mv88e6352_port_set_speed(struct mv88e6xxx_chip *chip, int port, int speed)
{
	if (speed == SPEED_MAX)
		speed = 1000;

	if (speed > 1000)
		return -EOPNOTSUPP;

	if (speed == 200 && port < 5)
		return -EOPNOTSUPP;

	return mv88e6xxx_port_set_speed(chip, port, speed, true, false);
}

int mv88e6390_port_set_speed(struct mv88e6xxx_chip *chip, int port, int speed)
{
	if (speed == SPEED_MAX)
		speed = port < 9 ? 1000 : 2500;

	if (speed > 2500)
		return -EOPNOTSUPP;

	if (speed == 200 && port != 0)
		return -EOPNOTSUPP;

	if (speed == 2500 && port < 9)
		return -EOPNOTSUPP;

	return mv88e6xxx_port_set_speed(chip, port, speed, true, true);
}

int mv88e6390x_port_set_speed(struct mv88e6xxx_chip *chip, int port, int speed)
{
	if (speed == SPEED_MAX)
		speed = port < 9 ? 1000 : 10000;

	if (speed == 200 && port != 0)
		return -EOPNOTSUPP;

	if (speed >= 2500 && port < 9)
		return -EOPNOTSUPP;

	return mv88e6xxx_port_set_speed(chip, port, speed, true, true);
}

int mv88e6390x_port_set_cmode(struct mv88e6xxx_chip *chip, int port,
			      phy_interface_t mode)
{
	int lane;
	u16 cmode;
	u16 reg;
	int err;

	if (mode == PHY_INTERFACE_MODE_NA)
		return 0;

	if (port != 9 && port != 10)
		return -EOPNOTSUPP;

	switch (mode) {
	case PHY_INTERFACE_MODE_1000BASEX:
		cmode = MV88E6XXX_PORT_STS_CMODE_1000BASE_X;
		break;
	case PHY_INTERFACE_MODE_SGMII:
		cmode = MV88E6XXX_PORT_STS_CMODE_SGMII;
		break;
	case PHY_INTERFACE_MODE_2500BASEX:
		cmode = MV88E6XXX_PORT_STS_CMODE_2500BASEX;
		break;
	case PHY_INTERFACE_MODE_XGMII:
	case PHY_INTERFACE_MODE_XAUI:
		cmode = MV88E6XXX_PORT_STS_CMODE_XAUI;
		break;
	case PHY_INTERFACE_MODE_RXAUI:
		cmode = MV88E6XXX_PORT_STS_CMODE_RXAUI;
		break;
	default:
		cmode = 0;
	}

	/* cmode doesn't change, nothing to do for us */
	if (cmode == chip->ports[port].cmode)
		return 0;

	lane = mv88e6390x_serdes_get_lane(chip, port);
	if (lane < 0)
		return lane;

	if (chip->ports[port].serdes_irq) {
		err = mv88e6390_serdes_irq_disable(chip, port, lane);
		if (err)
			return err;
	}

	err = mv88e6390x_serdes_power(chip, port, false);
	if (err)
		return err;

	if (cmode) {
		err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_STS, &reg);
		if (err)
			return err;

		reg &= ~MV88E6XXX_PORT_STS_CMODE_MASK;
		reg |= cmode;

		err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_STS, reg);
		if (err)
			return err;

		err = mv88e6390x_serdes_power(chip, port, true);
		if (err)
			return err;

		if (chip->ports[port].serdes_irq) {
			err = mv88e6390_serdes_irq_enable(chip, port, lane);
			if (err)
				return err;
		}
	}

	chip->ports[port].cmode = cmode;

	return 0;
}

int mv88e6185_port_get_cmode(struct mv88e6xxx_chip *chip, int port, u8 *cmode)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_STS, &reg);
	if (err)
		return err;

	*cmode = reg & MV88E6185_PORT_STS_CMODE_MASK;

	return 0;
}

int mv88e6352_port_get_cmode(struct mv88e6xxx_chip *chip, int port, u8 *cmode)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_STS, &reg);
	if (err)
		return err;

	*cmode = reg & MV88E6XXX_PORT_STS_CMODE_MASK;

	return 0;
}

int mv88e6352_port_link_state(struct mv88e6xxx_chip *chip, int port,
			      struct phylink_link_state *state)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_STS, &reg);
	if (err)
		return err;

	switch (reg & MV88E6XXX_PORT_STS_SPEED_MASK) {
	case MV88E6XXX_PORT_STS_SPEED_10:
		state->speed = SPEED_10;
		break;
	case MV88E6XXX_PORT_STS_SPEED_100:
		state->speed = SPEED_100;
		break;
	case MV88E6XXX_PORT_STS_SPEED_1000:
		state->speed = SPEED_1000;
		break;
	case MV88E6XXX_PORT_STS_SPEED_10000:
		if ((reg & MV88E6XXX_PORT_STS_CMODE_MASK) ==
		    MV88E6XXX_PORT_STS_CMODE_2500BASEX)
			state->speed = SPEED_2500;
		else
			state->speed = SPEED_10000;
		break;
	}

	state->duplex = reg & MV88E6XXX_PORT_STS_DUPLEX ?
			DUPLEX_FULL : DUPLEX_HALF;
	state->link = !!(reg & MV88E6XXX_PORT_STS_LINK);
	state->an_enabled = 1;
	state->an_complete = state->link;

	return 0;
}

int mv88e6185_port_link_state(struct mv88e6xxx_chip *chip, int port,
			      struct phylink_link_state *state)
{
	if (state->interface == PHY_INTERFACE_MODE_1000BASEX) {
		u8 cmode = chip->ports[port].cmode;

		/* When a port is in "Cross-chip serdes" mode, it uses
		 * 1000Base-X full duplex mode, but there is no automatic
		 * link detection. Use the sync OK status for link (as it
		 * would do for 1000Base-X mode.)
		 */
		if (cmode == MV88E6185_PORT_STS_CMODE_SERDES) {
			u16 mac;
			int err;

			err = mv88e6xxx_port_read(chip, port,
						  MV88E6XXX_PORT_MAC_CTL, &mac);
			if (err)
				return err;

			state->link = !!(mac & MV88E6185_PORT_MAC_CTL_SYNC_OK);
			state->an_enabled = 1;
			state->an_complete =
				!!(mac & MV88E6185_PORT_MAC_CTL_AN_DONE);
			state->duplex =
				state->link ? DUPLEX_FULL : DUPLEX_UNKNOWN;
			state->speed =
				state->link ? SPEED_1000 : SPEED_UNKNOWN;

			return 0;
		}
	}

	return mv88e6352_port_link_state(chip, port, state);
}

int mv88e6097_port_pause_limit(struct mv88e6xxx_chip *chip, int port, u8 in,
			       u8 out)
{
	return mv88e6xxx_port_write(chip, port, MV88E6097_PORT_JAM_CTL,
				    out << 8 | in);
}

int mv88e6390_port_pause_limit(struct mv88e6xxx_chip *chip, int port, u8 in,
			       u8 out)
{
	int err;

	err = mv88e6xxx_port_write(chip, port, MV88E6390_PORT_FLOW_CTL,
				   MV88E6390_PORT_FLOW_CTL_UPDATE |
				   MV88E6390_PORT_FLOW_CTL_LIMIT_IN | in);
	if (err)
		return err;

	return mv88e6xxx_port_write(chip, port, MV88E6390_PORT_FLOW_CTL,
				    MV88E6390_PORT_FLOW_CTL_UPDATE |
				    MV88E6390_PORT_FLOW_CTL_LIMIT_OUT | out);
}

int mv88e6xxx_port_set_state(struct mv88e6xxx_chip *chip, int port, u8 state)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL0, &reg);
	if (err)
		return err;

	reg &= ~MV88E6XXX_PORT_CTL0_STATE_MASK;

	switch (state) {
	case BR_STATE_DISABLED:
		state = MV88E6XXX_PORT_CTL0_STATE_DISABLED;
		break;
	case BR_STATE_BLOCKING:
	case BR_STATE_LISTENING:
		state = MV88E6XXX_PORT_CTL0_STATE_BLOCKING;
		break;
	case BR_STATE_LEARNING:
		state = MV88E6XXX_PORT_CTL0_STATE_LEARNING;
		break;
	case BR_STATE_FORWARDING:
		state = MV88E6XXX_PORT_CTL0_STATE_FORWARDING;
		break;
	default:
		return -EINVAL;
	}

	reg |= state;

	err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL0, reg);
	if (err)
		return err;

	dev_dbg(chip->dev, "p%d: PortState set to %s\n", port,
		mv88e6xxx_port_state_names[state]);

	return 0;
}

int mv88e6xxx_port_set_egress_mode(struct mv88e6xxx_chip *chip, int port,
				   enum mv88e6xxx_egress_mode mode)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL0, &reg);
	if (err)
		return err;

	reg &= ~MV88E6XXX_PORT_CTL0_EGRESS_MODE_MASK;

	switch (mode) {
	case MV88E6XXX_EGRESS_MODE_UNMODIFIED:
		reg |= MV88E6XXX_PORT_CTL0_EGRESS_MODE_UNMODIFIED;
		break;
	case MV88E6XXX_EGRESS_MODE_UNTAGGED:
		reg |= MV88E6XXX_PORT_CTL0_EGRESS_MODE_UNTAGGED;
		break;
	case MV88E6XXX_EGRESS_MODE_TAGGED:
		reg |= MV88E6XXX_PORT_CTL0_EGRESS_MODE_TAGGED;
		break;
	case MV88E6XXX_EGRESS_MODE_ETHERTYPE:
		reg |= MV88E6XXX_PORT_CTL0_EGRESS_MODE_ETHER_TYPE_DSA;
		break;
	default:
		return -EINVAL;
	}

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL0, reg);
}

int mv88e6085_port_set_frame_mode(struct mv88e6xxx_chip *chip, int port,
				  enum mv88e6xxx_frame_mode mode)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL0, &reg);
	if (err)
		return err;

	reg &= ~MV88E6XXX_PORT_CTL0_FRAME_MODE_MASK;

	switch (mode) {
	case MV88E6XXX_FRAME_MODE_NORMAL:
		reg |= MV88E6XXX_PORT_CTL0_FRAME_MODE_NORMAL;
		break;
	case MV88E6XXX_FRAME_MODE_DSA:
		reg |= MV88E6XXX_PORT_CTL0_FRAME_MODE_DSA;
		break;
	default:
		return -EINVAL;
	}

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL0, reg);
}

int mv88e6351_port_set_frame_mode(struct mv88e6xxx_chip *chip, int port,
				  enum mv88e6xxx_frame_mode mode)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL0, &reg);
	if (err)
		return err;

	reg &= ~MV88E6XXX_PORT_CTL0_FRAME_MODE_MASK;

	switch (mode) {
	case MV88E6XXX_FRAME_MODE_NORMAL:
		reg |= MV88E6XXX_PORT_CTL0_FRAME_MODE_NORMAL;
		break;
	case MV88E6XXX_FRAME_MODE_DSA:
		reg |= MV88E6XXX_PORT_CTL0_FRAME_MODE_DSA;
		break;
	case MV88E6XXX_FRAME_MODE_PROVIDER:
		reg |= MV88E6XXX_PORT_CTL0_FRAME_MODE_PROVIDER;
		break;
	case MV88E6XXX_FRAME_MODE_ETHERTYPE:
		reg |= MV88E6XXX_PORT_CTL0_FRAME_MODE_ETHER_TYPE_DSA;
		break;
	default:
		return -EINVAL;
	}

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL0, reg);
}

__attribute__((used)) static int mv88e6185_port_set_forward_unknown(struct mv88e6xxx_chip *chip,
					      int port, bool unicast)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL0, &reg);
	if (err)
		return err;

	if (unicast)
		reg |= MV88E6185_PORT_CTL0_FORWARD_UNKNOWN;
	else
		reg &= ~MV88E6185_PORT_CTL0_FORWARD_UNKNOWN;

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL0, reg);
}

int mv88e6352_port_set_egress_floods(struct mv88e6xxx_chip *chip, int port,
				     bool unicast, bool multicast)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL0, &reg);
	if (err)
		return err;

	reg &= ~MV88E6352_PORT_CTL0_EGRESS_FLOODS_MASK;

	if (unicast && multicast)
		reg |= MV88E6352_PORT_CTL0_EGRESS_FLOODS_ALL_UNKNOWN_DA;
	else if (unicast)
		reg |= MV88E6352_PORT_CTL0_EGRESS_FLOODS_NO_UNKNOWN_MC_DA;
	else if (multicast)
		reg |= MV88E6352_PORT_CTL0_EGRESS_FLOODS_NO_UNKNOWN_UC_DA;
	else
		reg |= MV88E6352_PORT_CTL0_EGRESS_FLOODS_NO_UNKNOWN_DA;

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL0, reg);
}

int mv88e6xxx_port_set_message_port(struct mv88e6xxx_chip *chip, int port,
				    bool message_port)
{
	u16 val;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL1, &val);
	if (err)
		return err;

	if (message_port)
		val |= MV88E6XXX_PORT_CTL1_MESSAGE_PORT;
	else
		val &= ~MV88E6XXX_PORT_CTL1_MESSAGE_PORT;

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL1, val);
}

int mv88e6xxx_port_set_vlan_map(struct mv88e6xxx_chip *chip, int port, u16 map)
{
	const u16 mask = mv88e6xxx_port_mask(chip);
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_BASE_VLAN, &reg);
	if (err)
		return err;

	reg &= ~mask;
	reg |= map & mask;

	err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_BASE_VLAN, reg);
	if (err)
		return err;

	dev_dbg(chip->dev, "p%d: VLANTable set to %.3x\n", port, map);

	return 0;
}

int mv88e6xxx_port_get_fid(struct mv88e6xxx_chip *chip, int port, u16 *fid)
{
	const u16 upper_mask = (mv88e6xxx_num_databases(chip) - 1) >> 4;
	u16 reg;
	int err;

	/* Port's default FID lower 4 bits are located in reg 0x06, offset 12 */
	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_BASE_VLAN, &reg);
	if (err)
		return err;

	*fid = (reg & 0xf000) >> 12;

	/* Port's default FID upper bits are located in reg 0x05, offset 0 */
	if (upper_mask) {
		err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL1,
					  &reg);
		if (err)
			return err;

		*fid |= (reg & upper_mask) << 4;
	}

	return 0;
}

int mv88e6xxx_port_set_fid(struct mv88e6xxx_chip *chip, int port, u16 fid)
{
	const u16 upper_mask = (mv88e6xxx_num_databases(chip) - 1) >> 4;
	u16 reg;
	int err;

	if (fid >= mv88e6xxx_num_databases(chip))
		return -EINVAL;

	/* Port's default FID lower 4 bits are located in reg 0x06, offset 12 */
	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_BASE_VLAN, &reg);
	if (err)
		return err;

	reg &= 0x0fff;
	reg |= (fid & 0x000f) << 12;

	err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_BASE_VLAN, reg);
	if (err)
		return err;

	/* Port's default FID upper bits are located in reg 0x05, offset 0 */
	if (upper_mask) {
		err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL1,
					  &reg);
		if (err)
			return err;

		reg &= ~upper_mask;
		reg |= (fid >> 4) & upper_mask;

		err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL1,
					   reg);
		if (err)
			return err;
	}

	dev_dbg(chip->dev, "p%d: FID set to %u\n", port, fid);

	return 0;
}

int mv88e6xxx_port_get_pvid(struct mv88e6xxx_chip *chip, int port, u16 *pvid)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_DEFAULT_VLAN,
				  &reg);
	if (err)
		return err;

	*pvid = reg & MV88E6XXX_PORT_DEFAULT_VLAN_MASK;

	return 0;
}

int mv88e6xxx_port_set_pvid(struct mv88e6xxx_chip *chip, int port, u16 pvid)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_DEFAULT_VLAN,
				  &reg);
	if (err)
		return err;

	reg &= ~MV88E6XXX_PORT_DEFAULT_VLAN_MASK;
	reg |= pvid & MV88E6XXX_PORT_DEFAULT_VLAN_MASK;

	err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_DEFAULT_VLAN,
				   reg);
	if (err)
		return err;

	dev_dbg(chip->dev, "p%d: DefaultVID set to %u\n", port, pvid);

	return 0;
}

__attribute__((used)) static int mv88e6185_port_set_default_forward(struct mv88e6xxx_chip *chip,
					      int port, bool multicast)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL2, &reg);
	if (err)
		return err;

	if (multicast)
		reg |= MV88E6XXX_PORT_CTL2_DEFAULT_FORWARD;
	else
		reg &= ~MV88E6XXX_PORT_CTL2_DEFAULT_FORWARD;

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL2, reg);
}

int mv88e6185_port_set_egress_floods(struct mv88e6xxx_chip *chip, int port,
				     bool unicast, bool multicast)
{
	int err;

	err = mv88e6185_port_set_forward_unknown(chip, port, unicast);
	if (err)
		return err;

	return mv88e6185_port_set_default_forward(chip, port, multicast);
}

int mv88e6095_port_set_upstream_port(struct mv88e6xxx_chip *chip, int port,
				     int upstream_port)
{
	int err;
	u16 reg;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL2, &reg);
	if (err)
		return err;

	reg &= ~MV88E6095_PORT_CTL2_CPU_PORT_MASK;
	reg |= upstream_port;

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL2, reg);
}

int mv88e6xxx_port_set_8021q_mode(struct mv88e6xxx_chip *chip, int port,
				  u16 mode)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL2, &reg);
	if (err)
		return err;

	reg &= ~MV88E6XXX_PORT_CTL2_8021Q_MODE_MASK;
	reg |= mode & MV88E6XXX_PORT_CTL2_8021Q_MODE_MASK;

	err = mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL2, reg);
	if (err)
		return err;

	dev_dbg(chip->dev, "p%d: 802.1QMode set to %s\n", port,
		mv88e6xxx_port_8021q_mode_names[mode]);

	return 0;
}

int mv88e6xxx_port_set_map_da(struct mv88e6xxx_chip *chip, int port)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL2, &reg);
	if (err)
		return err;

	reg |= MV88E6XXX_PORT_CTL2_MAP_DA;

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL2, reg);
}

int mv88e6165_port_set_jumbo_size(struct mv88e6xxx_chip *chip, int port,
				  size_t size)
{
	u16 reg;
	int err;

	err = mv88e6xxx_port_read(chip, port, MV88E6XXX_PORT_CTL2, &reg);
	if (err)
		return err;

	reg &= ~MV88E6XXX_PORT_CTL2_JUMBO_MODE_MASK;

	if (size <= 1522)
		reg |= MV88E6XXX_PORT_CTL2_JUMBO_MODE_1522;
	else if (size <= 2048)
		reg |= MV88E6XXX_PORT_CTL2_JUMBO_MODE_2048;
	else if (size <= 10240)
		reg |= MV88E6XXX_PORT_CTL2_JUMBO_MODE_10240;
	else
		return -ERANGE;

	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_CTL2, reg);
}

int mv88e6095_port_egress_rate_limiting(struct mv88e6xxx_chip *chip, int port)
{
	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_EGRESS_RATE_CTL1,
				    0x0000);
}

int mv88e6097_port_egress_rate_limiting(struct mv88e6xxx_chip *chip, int port)
{
	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_EGRESS_RATE_CTL1,
				    0x0001);
}

int mv88e6xxx_port_disable_learn_limit(struct mv88e6xxx_chip *chip, int port)
{
	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_ATU_CTL, 0);
}

int mv88e6xxx_port_disable_pri_override(struct mv88e6xxx_chip *chip, int port)
{
	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_PRI_OVERRIDE, 0);
}

int mv88e6351_port_set_ether_type(struct mv88e6xxx_chip *chip, int port,
				  u16 etype)
{
	return mv88e6xxx_port_write(chip, port, MV88E6XXX_PORT_ETH_TYPE, etype);
}

int mv88e6095_port_tag_remap(struct mv88e6xxx_chip *chip, int port)
{
	int err;

	/* Use a direct priority mapping for all IEEE tagged frames */
	err = mv88e6xxx_port_write(chip, port,
				   MV88E6095_PORT_IEEE_PRIO_REMAP_0123,
				   0x3210);
	if (err)
		return err;

	return mv88e6xxx_port_write(chip, port,
				    MV88E6095_PORT_IEEE_PRIO_REMAP_4567,
				    0x7654);
}

__attribute__((used)) static int mv88e6xxx_port_ieeepmt_write(struct mv88e6xxx_chip *chip,
					int port, u16 table, u8 ptr, u16 data)
{
	u16 reg;

	reg = MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_UPDATE | table |
		(ptr << __bf_shf(MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_PTR_MASK)) |
		(data & MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_DATA_MASK);

	return mv88e6xxx_port_write(chip, port,
				    MV88E6390_PORT_IEEE_PRIO_MAP_TABLE, reg);
}

int mv88e6390_port_tag_remap(struct mv88e6xxx_chip *chip, int port)
{
	int err, i;
	u16 table;

	for (i = 0; i <= 7; i++) {
		table = MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_INGRESS_PCP;
		err = mv88e6xxx_port_ieeepmt_write(chip, port, table, i,
						   (i | i << 4));
		if (err)
			return err;

		table = MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_EGRESS_GREEN_PCP;
		err = mv88e6xxx_port_ieeepmt_write(chip, port, table, i, i);
		if (err)
			return err;

		table = MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_EGRESS_YELLOW_PCP;
		err = mv88e6xxx_port_ieeepmt_write(chip, port, table, i, i);
		if (err)
			return err;

		table = MV88E6390_PORT_IEEE_PRIO_MAP_TABLE_EGRESS_AVB_PCP;
		err = mv88e6xxx_port_ieeepmt_write(chip, port, table, i, i);
		if (err)
			return err;
	}

	return 0;
}

