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
typedef  int u32 ;
typedef  int u16 ;
struct mtk_eth {int* link; TYPE_1__* phy; struct mt7620_gsw* sw_priv; } ;
struct mt7620_gsw {int /*<<< orphan*/  dev; scalar_t__ piac_offset; } ;
struct mii_bus {struct mtk_eth* priv; } ;
struct TYPE_2__ {int* speed; scalar_t__* duplex; } ;

/* Variables and functions */
 scalar_t__ DUPLEX_FULL ; 
 int GSW_MDIO_ACCESS ; 
 int GSW_MDIO_ADDR_SHIFT ; 
 int GSW_MDIO_READ ; 
 int GSW_MDIO_REG_SHIFT ; 
 int GSW_MDIO_START ; 
 int GSW_MDIO_WRITE ; 
 int GSW_PORT6 ; 
 scalar_t__ GSW_REG_PHY_TIMEOUT ; 
 int GSW_REG_PORT_STATUS (int) ; 
 scalar_t__ MT7620_GSW_REG_PIAC ; 
#define  SPEED_10 130 
#define  SPEED_100 129 
#define  SPEED_1000 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int,...) ; 
 unsigned long jiffies ; 
 int mtk_switch_r32 (struct mt7620_gsw*,scalar_t__) ; 
 int /*<<< orphan*/  mtk_switch_w32 (struct mt7620_gsw*,int,scalar_t__) ; 
 scalar_t__ time_after (unsigned long,scalar_t__) ; 

__attribute__((used)) static inline int mtk_mdio_init(struct mtk_eth *eth) { return 0; }

__attribute__((used)) static inline void mtk_mdio_cleanup(struct mtk_eth *eth) {}

__attribute__((used)) static int mt7620_mii_busy_wait(struct mt7620_gsw *gsw)
{
	unsigned long t_start = jiffies;

	while (1) {
		if (!(mtk_switch_r32(gsw,
				     gsw->piac_offset + MT7620_GSW_REG_PIAC) &
				     GSW_MDIO_ACCESS))
			return 0;
		if (time_after(jiffies, t_start + GSW_REG_PHY_TIMEOUT))
			break;
	}

	dev_err(gsw->dev, "mdio: MDIO timeout\n");
	return -1;
}

u32 _mt7620_mii_write(struct mt7620_gsw *gsw, u32 phy_addr,
		      u32 phy_register, u32 write_data)
{
	if (mt7620_mii_busy_wait(gsw))
		return -1;

	write_data &= 0xffff;

	mtk_switch_w32(gsw, GSW_MDIO_ACCESS | GSW_MDIO_START | GSW_MDIO_WRITE |
		(phy_register << GSW_MDIO_REG_SHIFT) |
		(phy_addr << GSW_MDIO_ADDR_SHIFT) | write_data,
		MT7620_GSW_REG_PIAC);

	if (mt7620_mii_busy_wait(gsw))
		return -1;

	return 0;
}

u32 _mt7620_mii_read(struct mt7620_gsw *gsw, int phy_addr, int phy_reg)
{
	u32 d;

	if (mt7620_mii_busy_wait(gsw))
		return 0xffff;

	mtk_switch_w32(gsw, GSW_MDIO_ACCESS | GSW_MDIO_START | GSW_MDIO_READ |
		(phy_reg << GSW_MDIO_REG_SHIFT) |
		(phy_addr << GSW_MDIO_ADDR_SHIFT),
		MT7620_GSW_REG_PIAC);

	if (mt7620_mii_busy_wait(gsw))
		return 0xffff;

	d = mtk_switch_r32(gsw, MT7620_GSW_REG_PIAC) & 0xffff;

	return d;
}

int mt7620_mdio_write(struct mii_bus *bus, int phy_addr, int phy_reg, u16 val)
{
	struct mtk_eth *eth = bus->priv;
	struct mt7620_gsw *gsw = (struct mt7620_gsw *)eth->sw_priv;

	return _mt7620_mii_write(gsw, phy_addr, phy_reg, val);
}

int mt7620_mdio_read(struct mii_bus *bus, int phy_addr, int phy_reg)
{
	struct mtk_eth *eth = bus->priv;
	struct mt7620_gsw *gsw = (struct mt7620_gsw *)eth->sw_priv;

	return _mt7620_mii_read(gsw, phy_addr, phy_reg);
}

void mt7530_mdio_w32(struct mt7620_gsw *gsw, u32 reg, u32 val)
{
	_mt7620_mii_write(gsw, 0x1f, 0x1f, (reg >> 6) & 0x3ff);
	_mt7620_mii_write(gsw, 0x1f, (reg >> 2) & 0xf,  val & 0xffff);
	_mt7620_mii_write(gsw, 0x1f, 0x10, val >> 16);
}

u32 mt7530_mdio_r32(struct mt7620_gsw *gsw, u32 reg)
{
	u16 high, low;

	_mt7620_mii_write(gsw, 0x1f, 0x1f, (reg >> 6) & 0x3ff);
	low = _mt7620_mii_read(gsw, 0x1f, (reg >> 2) & 0xf);
	high = _mt7620_mii_read(gsw, 0x1f, 0x10);

	return (high << 16) | (low & 0xffff);
}

void mt7530_mdio_m32(struct mt7620_gsw *gsw, u32 mask, u32 set, u32 reg)
{
	u32 val = mt7530_mdio_r32(gsw, reg);

	val &= ~mask;
	val |= set;
	mt7530_mdio_w32(gsw, reg, val);
}

__attribute__((used)) static unsigned char *mtk_speed_str(int speed)
{
	switch (speed) {
	case 2:
	case SPEED_1000:
		return "1000";
	case 1:
	case SPEED_100:
		return "100";
	case 0:
	case SPEED_10:
		return "10";
	}

	return "? ";
}

int mt7620_has_carrier(struct mtk_eth *eth)
{
	struct mt7620_gsw *gsw = (struct mt7620_gsw *)eth->sw_priv;
	int i;

	for (i = 0; i < GSW_PORT6; i++)
		if (mt7530_mdio_r32(gsw, GSW_REG_PORT_STATUS(i)) & 0x1)
			return 1;
	return 0;
}

void mt7620_print_link_state(struct mtk_eth *eth, int port, int link,
			     int speed, int duplex)
{
	struct mt7620_gsw *gsw = eth->sw_priv;

	if (link)
		dev_info(gsw->dev, "port %d link up (%sMbps/%s duplex)\n",
			 port, mtk_speed_str(speed),
			 (duplex) ? "Full" : "Half");
	else
		dev_info(gsw->dev, "port %d link down\n", port);
}

void mt7620_mdio_link_adjust(struct mtk_eth *eth, int port)
{
	mt7620_print_link_state(eth, port, eth->link[port],
				eth->phy->speed[port],
				(eth->phy->duplex[port] == DUPLEX_FULL));
}

