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
typedef  int u8 ;
typedef  int u16 ;
struct mv88e6060_priv {int sw_addr; struct mii_bus* bus; } ;
struct mii_bus {int dummy; } ;
struct dsa_switch {struct mv88e6060_priv* priv; } ;
struct device {int dummy; } ;
typedef  enum dsa_tag_protocol { ____Placeholder_dsa_tag_protocol } dsa_tag_protocol ;
struct TYPE_4__ {TYPE_1__* cpu_dp; } ;
struct TYPE_3__ {int index; } ;

/* Variables and functions */
 int BIT (int) ; 
 int DSA_TAG_PROTO_TRAILER ; 
 int ETH_ALEN ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GLOBAL_ATU_CONTROL ; 
 int GLOBAL_ATU_CONTROL_LEARNDIS ; 
 int GLOBAL_ATU_CONTROL_SWRESET ; 
 int /*<<< orphan*/  GLOBAL_CONTROL ; 
 int GLOBAL_CONTROL_MAX_FRAME_1536 ; 
 int /*<<< orphan*/  GLOBAL_MAC_01 ; 
 int /*<<< orphan*/  GLOBAL_MAC_23 ; 
 int /*<<< orphan*/  GLOBAL_MAC_45 ; 
 int /*<<< orphan*/  GLOBAL_STATUS ; 
 int GLOBAL_STATUS_INIT_READY ; 
 int HZ ; 
 int MV88E6060_PORTS ; 
 int /*<<< orphan*/  PORT_ASSOC_VECTOR ; 
 int /*<<< orphan*/  PORT_CONTROL ; 
 int PORT_CONTROL_INGRESS_MODE ; 
 int PORT_CONTROL_STATE_FORWARDING ; 
 int PORT_CONTROL_STATE_MASK ; 
 int PORT_CONTROL_TRAILER ; 
 int /*<<< orphan*/  PORT_SWITCH_ID ; 
 int PORT_SWITCH_ID_6060 ; 
 int PORT_SWITCH_ID_6060_MASK ; 
 int PORT_SWITCH_ID_6060_R1 ; 
 int PORT_SWITCH_ID_6060_R2 ; 
 int /*<<< orphan*/  PORT_VLAN_MAP ; 
 int PORT_VLAN_MAP_DBNUM_SHIFT ; 
 int REG_GLOBAL ; 
 int REG_PORT (int) ; 
 int REG_READ (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_WRITE (int,int /*<<< orphan*/ ,int) ; 
 struct mv88e6060_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct mii_bus* dsa_host_dev_to_mii_bus (struct device*) ; 
 scalar_t__ dsa_is_cpu_port (struct dsa_switch*,int) ; 
 TYPE_2__* dsa_to_port (struct dsa_switch*,int) ; 
 int dsa_user_ports (struct dsa_switch*) ; 
 int /*<<< orphan*/  eth_random_addr (int*) ; 
 int jiffies ; 
 int mdiobus_read (struct mii_bus*,int,int /*<<< orphan*/ ) ; 
 int mdiobus_read_nested (struct mii_bus*,int,int) ; 
 int mdiobus_write_nested (struct mii_bus*,int,int,int) ; 
 scalar_t__ time_after (int,unsigned long) ; 
 scalar_t__ time_before (int,unsigned long) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int reg_read(struct dsa_switch *ds, int addr, int reg)
{
	struct mv88e6060_priv *priv = ds->priv;

	return mdiobus_read_nested(priv->bus, priv->sw_addr + addr, reg);
}

__attribute__((used)) static int reg_write(struct dsa_switch *ds, int addr, int reg, u16 val)
{
	struct mv88e6060_priv *priv = ds->priv;

	return mdiobus_write_nested(priv->bus, priv->sw_addr + addr, reg, val);
}

__attribute__((used)) static const char *mv88e6060_get_name(struct mii_bus *bus, int sw_addr)
{
	int ret;

	ret = mdiobus_read(bus, sw_addr + REG_PORT(0), PORT_SWITCH_ID);
	if (ret >= 0) {
		if (ret == PORT_SWITCH_ID_6060)
			return "Marvell 88E6060 (A0)";
		if (ret == PORT_SWITCH_ID_6060_R1 ||
		    ret == PORT_SWITCH_ID_6060_R2)
			return "Marvell 88E6060 (B0)";
		if ((ret & PORT_SWITCH_ID_6060_MASK) == PORT_SWITCH_ID_6060)
			return "Marvell 88E6060";
	}

	return NULL;
}

__attribute__((used)) static enum dsa_tag_protocol mv88e6060_get_tag_protocol(struct dsa_switch *ds,
							int port)
{
	return DSA_TAG_PROTO_TRAILER;
}

__attribute__((used)) static const char *mv88e6060_drv_probe(struct device *dsa_dev,
				       struct device *host_dev, int sw_addr,
				       void **_priv)
{
	struct mii_bus *bus = dsa_host_dev_to_mii_bus(host_dev);
	struct mv88e6060_priv *priv;
	const char *name;

	name = mv88e6060_get_name(bus, sw_addr);
	if (name) {
		priv = devm_kzalloc(dsa_dev, sizeof(*priv), GFP_KERNEL);
		if (!priv)
			return NULL;
		*_priv = priv;
		priv->bus = bus;
		priv->sw_addr = sw_addr;
	}

	return name;
}

__attribute__((used)) static int mv88e6060_switch_reset(struct dsa_switch *ds)
{
	int i;
	int ret;
	unsigned long timeout;

	/* Set all ports to the disabled state. */
	for (i = 0; i < MV88E6060_PORTS; i++) {
		ret = REG_READ(REG_PORT(i), PORT_CONTROL);
		REG_WRITE(REG_PORT(i), PORT_CONTROL,
			  ret & ~PORT_CONTROL_STATE_MASK);
	}

	/* Wait for transmit queues to drain. */
	usleep_range(2000, 4000);

	/* Reset the switch. */
	REG_WRITE(REG_GLOBAL, GLOBAL_ATU_CONTROL,
		  GLOBAL_ATU_CONTROL_SWRESET |
		  GLOBAL_ATU_CONTROL_LEARNDIS);

	/* Wait up to one second for reset to complete. */
	timeout = jiffies + 1 * HZ;
	while (time_before(jiffies, timeout)) {
		ret = REG_READ(REG_GLOBAL, GLOBAL_STATUS);
		if (ret & GLOBAL_STATUS_INIT_READY)
			break;

		usleep_range(1000, 2000);
	}
	if (time_after(jiffies, timeout))
		return -ETIMEDOUT;

	return 0;
}

__attribute__((used)) static int mv88e6060_setup_global(struct dsa_switch *ds)
{
	/* Disable discarding of frames with excessive collisions,
	 * set the maximum frame size to 1536 bytes, and mask all
	 * interrupt sources.
	 */
	REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL, GLOBAL_CONTROL_MAX_FRAME_1536);

	/* Disable automatic address learning.
	 */
	REG_WRITE(REG_GLOBAL, GLOBAL_ATU_CONTROL,
		  GLOBAL_ATU_CONTROL_LEARNDIS);

	return 0;
}

__attribute__((used)) static int mv88e6060_setup_port(struct dsa_switch *ds, int p)
{
	int addr = REG_PORT(p);

	/* Do not force flow control, disable Ingress and Egress
	 * Header tagging, disable VLAN tunneling, and set the port
	 * state to Forwarding.  Additionally, if this is the CPU
	 * port, enable Ingress and Egress Trailer tagging mode.
	 */
	REG_WRITE(addr, PORT_CONTROL,
		  dsa_is_cpu_port(ds, p) ?
			PORT_CONTROL_TRAILER |
			PORT_CONTROL_INGRESS_MODE |
			PORT_CONTROL_STATE_FORWARDING :
			PORT_CONTROL_STATE_FORWARDING);

	/* Port based VLAN map: give each port its own address
	 * database, allow the CPU port to talk to each of the 'real'
	 * ports, and allow each of the 'real' ports to only talk to
	 * the CPU port.
	 */
	REG_WRITE(addr, PORT_VLAN_MAP,
		  ((p & 0xf) << PORT_VLAN_MAP_DBNUM_SHIFT) |
		   (dsa_is_cpu_port(ds, p) ? dsa_user_ports(ds) :
		    BIT(dsa_to_port(ds, p)->cpu_dp->index)));

	/* Port Association Vector: when learning source addresses
	 * of packets, add the address to the address database using
	 * a port bitmap that has only the bit for this port set and
	 * the other bits clear.
	 */
	REG_WRITE(addr, PORT_ASSOC_VECTOR, BIT(p));

	return 0;
}

__attribute__((used)) static int mv88e6060_setup_addr(struct dsa_switch *ds)
{
	u8 addr[ETH_ALEN];
	u16 val;

	eth_random_addr(addr);

	val = addr[0] << 8 | addr[1];

	/* The multicast bit is always transmitted as a zero, so the switch uses
	 * bit 8 for "DiffAddr", where 0 means all ports transmit the same SA.
	 */
	val &= 0xfeff;

	REG_WRITE(REG_GLOBAL, GLOBAL_MAC_01, val);
	REG_WRITE(REG_GLOBAL, GLOBAL_MAC_23, (addr[2] << 8) | addr[3]);
	REG_WRITE(REG_GLOBAL, GLOBAL_MAC_45, (addr[4] << 8) | addr[5]);

	return 0;
}

__attribute__((used)) static int mv88e6060_setup(struct dsa_switch *ds)
{
	int ret;
	int i;

	ret = mv88e6060_switch_reset(ds);
	if (ret < 0)
		return ret;

	/* @@@ initialise atu */

	ret = mv88e6060_setup_global(ds);
	if (ret < 0)
		return ret;

	ret = mv88e6060_setup_addr(ds);
	if (ret < 0)
		return ret;

	for (i = 0; i < MV88E6060_PORTS; i++) {
		ret = mv88e6060_setup_port(ds, i);
		if (ret < 0)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int mv88e6060_port_to_phy_addr(int port)
{
	if (port >= 0 && port < MV88E6060_PORTS)
		return port;
	return -1;
}

__attribute__((used)) static int mv88e6060_phy_read(struct dsa_switch *ds, int port, int regnum)
{
	int addr;

	addr = mv88e6060_port_to_phy_addr(port);
	if (addr == -1)
		return 0xffff;

	return reg_read(ds, addr, regnum);
}

__attribute__((used)) static int
mv88e6060_phy_write(struct dsa_switch *ds, int port, int regnum, u16 val)
{
	int addr;

	addr = mv88e6060_port_to_phy_addr(port);
	if (addr == -1)
		return 0xffff;

	return reg_write(ds, addr, regnum, val);
}

