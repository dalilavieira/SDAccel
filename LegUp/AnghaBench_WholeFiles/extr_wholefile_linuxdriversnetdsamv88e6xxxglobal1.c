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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct mv88e6xxx_chip {TYPE_1__* info; } ;
struct TYPE_2__ {int pvt; unsigned int num_databases; unsigned int num_ports; unsigned int num_gpio; int global1_addr; } ;

/* Variables and functions */
 int ETIMEDOUT ; 
 int GENMASK (unsigned int,int /*<<< orphan*/ ) ; 
 int HZ ; 
 int MV88E6085_G1_CTL2_P10RM ; 
 int MV88E6085_G1_CTL2_RM_ENABLE ; 
 int MV88E6185_G1_CTL2_CASCADE_PORT_MASK ; 
 int MV88E6185_G1_MONITOR_CTL ; 
 int MV88E6185_G1_MONITOR_CTL_ARP_DEST_MASK ; 
 int MV88E6185_G1_MONITOR_CTL_EGRESS_DEST_MASK ; 
 int MV88E6185_G1_MONITOR_CTL_INGRESS_DEST_MASK ; 
 int MV88E6185_G1_STS_PPU_STATE_MASK ; 
 int MV88E6185_G1_STS_PPU_STATE_POLLING ; 
 int MV88E6352_G1_CTL2_RMU_MODE_DISABLED ; 
 int MV88E6352_G1_CTL2_RMU_MODE_MASK ; 
 int MV88E6352_G1_STS_PPU_STATE ; 
 int MV88E6390_G1_CTL2_HIST_MODE_MASK ; 
 int MV88E6390_G1_CTL2_HIST_MODE_RX ; 
 int MV88E6390_G1_CTL2_HIST_MODE_TX ; 
 int MV88E6390_G1_CTL2_RMU_MODE_DISABLED ; 
 int MV88E6390_G1_CTL2_RMU_MODE_MASK ; 
 int MV88E6390_G1_MONITOR_MGMT_CTL ; 
 int MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000000XHI ; 
 int MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000000XLO ; 
 int MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000002XHI ; 
 int MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000002XLO ; 
 int MV88E6390_G1_MONITOR_MGMT_CTL_PTR_CPU_DEST ; 
 int MV88E6390_G1_MONITOR_MGMT_CTL_PTR_EGRESS_DEST ; 
 int MV88E6390_G1_MONITOR_MGMT_CTL_PTR_INGRESS_DEST ; 
 int MV88E6390_G1_MONITOR_MGMT_CTL_UPDATE ; 
 int MV88E6XXX_G1_CTL1 ; 
 int MV88E6XXX_G1_CTL1_PPU_ENABLE ; 
 int MV88E6XXX_G1_CTL1_SW_RESET ; 
 int MV88E6XXX_G1_CTL2 ; 
 int MV88E6XXX_G1_CTL2_DEVICE_NUMBER_MASK ; 
 int MV88E6XXX_G1_IEEE_PRI ; 
 int MV88E6XXX_G1_IP_PRI_0 ; 
 int MV88E6XXX_G1_IP_PRI_1 ; 
 int MV88E6XXX_G1_IP_PRI_2 ; 
 int MV88E6XXX_G1_IP_PRI_3 ; 
 int MV88E6XXX_G1_IP_PRI_4 ; 
 int MV88E6XXX_G1_IP_PRI_5 ; 
 int MV88E6XXX_G1_IP_PRI_6 ; 
 int MV88E6XXX_G1_IP_PRI_7 ; 
 int MV88E6XXX_G1_MAC_01 ; 
 int MV88E6XXX_G1_MAC_23 ; 
 int MV88E6XXX_G1_MAC_45 ; 
 int MV88E6XXX_G1_STATS_COUNTER_01 ; 
 int MV88E6XXX_G1_STATS_COUNTER_32 ; 
 int MV88E6XXX_G1_STATS_OP ; 
 int MV88E6XXX_G1_STATS_OP_BUSY ; 
 int MV88E6XXX_G1_STATS_OP_CAPTURE_PORT ; 
 int MV88E6XXX_G1_STATS_OP_FLUSH_ALL ; 
 int MV88E6XXX_G1_STATS_OP_HIST_RX_TX ; 
 int MV88E6XXX_G1_STATS_OP_READ_CAPTURED ; 
 int MV88E6XXX_G1_STS ; 
 int MV88E6XXX_G1_STS_INIT_READY ; 
 int __bf_shf (int const) ; 
 int jiffies ; 
 int mv88e6xxx_read (struct mv88e6xxx_chip*,int,int,int*) ; 
 int mv88e6xxx_wait (struct mv88e6xxx_chip*,int,int,int) ; 
 int mv88e6xxx_write (struct mv88e6xxx_chip*,int,int,int) ; 
 scalar_t__ time_after (int,unsigned long const) ; 
 scalar_t__ time_before (int,unsigned long const) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

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

int mv88e6xxx_g1_read(struct mv88e6xxx_chip *chip, int reg, u16 *val)
{
	int addr = chip->info->global1_addr;

	return mv88e6xxx_read(chip, addr, reg, val);
}

int mv88e6xxx_g1_write(struct mv88e6xxx_chip *chip, int reg, u16 val)
{
	int addr = chip->info->global1_addr;

	return mv88e6xxx_write(chip, addr, reg, val);
}

int mv88e6xxx_g1_wait(struct mv88e6xxx_chip *chip, int reg, u16 mask)
{
	return mv88e6xxx_wait(chip, chip->info->global1_addr, reg, mask);
}

__attribute__((used)) static int mv88e6185_g1_wait_ppu_disabled(struct mv88e6xxx_chip *chip)
{
	u16 state;
	int i, err;

	for (i = 0; i < 16; i++) {
		err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STS, &state);
		if (err)
			return err;

		/* Check the value of the PPUState bits 15:14 */
		state &= MV88E6185_G1_STS_PPU_STATE_MASK;
		if (state != MV88E6185_G1_STS_PPU_STATE_POLLING)
			return 0;

		usleep_range(1000, 2000);
	}

	return -ETIMEDOUT;
}

__attribute__((used)) static int mv88e6185_g1_wait_ppu_polling(struct mv88e6xxx_chip *chip)
{
	u16 state;
	int i, err;

	for (i = 0; i < 16; ++i) {
		err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STS, &state);
		if (err)
			return err;

		/* Check the value of the PPUState bits 15:14 */
		state &= MV88E6185_G1_STS_PPU_STATE_MASK;
		if (state == MV88E6185_G1_STS_PPU_STATE_POLLING)
			return 0;

		usleep_range(1000, 2000);
	}

	return -ETIMEDOUT;
}

__attribute__((used)) static int mv88e6352_g1_wait_ppu_polling(struct mv88e6xxx_chip *chip)
{
	u16 state;
	int i, err;

	for (i = 0; i < 16; ++i) {
		err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STS, &state);
		if (err)
			return err;

		/* Check the value of the PPUState (or InitState) bit 15 */
		if (state & MV88E6352_G1_STS_PPU_STATE)
			return 0;

		usleep_range(1000, 2000);
	}

	return -ETIMEDOUT;
}

__attribute__((used)) static int mv88e6xxx_g1_wait_init_ready(struct mv88e6xxx_chip *chip)
{
	const unsigned long timeout = jiffies + 1 * HZ;
	u16 val;
	int err;

	/* Wait up to 1 second for the switch to be ready. The InitReady bit 11
	 * is set to a one when all units inside the device (ATU, VTU, etc.)
	 * have finished their initialization and are ready to accept frames.
	 */
	while (time_before(jiffies, timeout)) {
		err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STS, &val);
		if (err)
			return err;

		if (val & MV88E6XXX_G1_STS_INIT_READY)
			break;

		usleep_range(1000, 2000);
	}

	if (time_after(jiffies, timeout))
		return -ETIMEDOUT;

	return 0;
}

int mv88e6xxx_g1_set_switch_mac(struct mv88e6xxx_chip *chip, u8 *addr)
{
	u16 reg;
	int err;

	reg = (addr[0] << 8) | addr[1];
	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_MAC_01, reg);
	if (err)
		return err;

	reg = (addr[2] << 8) | addr[3];
	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_MAC_23, reg);
	if (err)
		return err;

	reg = (addr[4] << 8) | addr[5];
	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_MAC_45, reg);
	if (err)
		return err;

	return 0;
}

int mv88e6185_g1_reset(struct mv88e6xxx_chip *chip)
{
	u16 val;
	int err;

	/* Set the SWReset bit 15 along with the PPUEn bit 14, to also restart
	 * the PPU, including re-doing PHY detection and initialization
	 */
	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL1, &val);
	if (err)
		return err;

	val |= MV88E6XXX_G1_CTL1_SW_RESET;
	val |= MV88E6XXX_G1_CTL1_PPU_ENABLE;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL1, val);
	if (err)
		return err;

	err = mv88e6xxx_g1_wait_init_ready(chip);
	if (err)
		return err;

	return mv88e6185_g1_wait_ppu_polling(chip);
}

int mv88e6352_g1_reset(struct mv88e6xxx_chip *chip)
{
	u16 val;
	int err;

	/* Set the SWReset bit 15 */
	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL1, &val);
	if (err)
		return err;

	val |= MV88E6XXX_G1_CTL1_SW_RESET;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL1, val);
	if (err)
		return err;

	err = mv88e6xxx_g1_wait_init_ready(chip);
	if (err)
		return err;

	return mv88e6352_g1_wait_ppu_polling(chip);
}

int mv88e6185_g1_ppu_enable(struct mv88e6xxx_chip *chip)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL1, &val);
	if (err)
		return err;

	val |= MV88E6XXX_G1_CTL1_PPU_ENABLE;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL1, val);
	if (err)
		return err;

	return mv88e6185_g1_wait_ppu_polling(chip);
}

int mv88e6185_g1_ppu_disable(struct mv88e6xxx_chip *chip)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL1, &val);
	if (err)
		return err;

	val &= ~MV88E6XXX_G1_CTL1_PPU_ENABLE;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL1, val);
	if (err)
		return err;

	return mv88e6185_g1_wait_ppu_disabled(chip);
}

int mv88e6085_g1_ip_pri_map(struct mv88e6xxx_chip *chip)
{
	int err;

	/* Reset the IP TOS/DiffServ/Traffic priorities to defaults */
	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_IP_PRI_0, 0x0000);
	if (err)
		return err;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_IP_PRI_1, 0x0000);
	if (err)
		return err;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_IP_PRI_2, 0x5555);
	if (err)
		return err;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_IP_PRI_3, 0x5555);
	if (err)
		return err;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_IP_PRI_4, 0xaaaa);
	if (err)
		return err;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_IP_PRI_5, 0xaaaa);
	if (err)
		return err;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_IP_PRI_6, 0xffff);
	if (err)
		return err;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_IP_PRI_7, 0xffff);
	if (err)
		return err;

	return 0;
}

int mv88e6085_g1_ieee_pri_map(struct mv88e6xxx_chip *chip)
{
	/* Reset the IEEE Tag priorities to defaults */
	return mv88e6xxx_g1_write(chip, MV88E6XXX_G1_IEEE_PRI, 0xfa41);
}

int mv88e6095_g1_set_egress_port(struct mv88e6xxx_chip *chip, int port)
{
	u16 reg;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6185_G1_MONITOR_CTL, &reg);
	if (err)
		return err;

	reg &= ~(MV88E6185_G1_MONITOR_CTL_INGRESS_DEST_MASK |
		 MV88E6185_G1_MONITOR_CTL_EGRESS_DEST_MASK);

	reg |= port << __bf_shf(MV88E6185_G1_MONITOR_CTL_INGRESS_DEST_MASK) |
		port << __bf_shf(MV88E6185_G1_MONITOR_CTL_EGRESS_DEST_MASK);

	return mv88e6xxx_g1_write(chip, MV88E6185_G1_MONITOR_CTL, reg);
}

int mv88e6095_g1_set_cpu_port(struct mv88e6xxx_chip *chip, int port)
{
	u16 reg;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6185_G1_MONITOR_CTL, &reg);
	if (err)
		return err;

	reg &= ~MV88E6185_G1_MONITOR_CTL_ARP_DEST_MASK;
	reg |= port << __bf_shf(MV88E6185_G1_MONITOR_CTL_ARP_DEST_MASK);

	return mv88e6xxx_g1_write(chip, MV88E6185_G1_MONITOR_CTL, reg);
}

__attribute__((used)) static int mv88e6390_g1_monitor_write(struct mv88e6xxx_chip *chip,
				      u16 pointer, u8 data)
{
	u16 reg;

	reg = MV88E6390_G1_MONITOR_MGMT_CTL_UPDATE | pointer | data;

	return mv88e6xxx_g1_write(chip, MV88E6390_G1_MONITOR_MGMT_CTL, reg);
}

int mv88e6390_g1_set_egress_port(struct mv88e6xxx_chip *chip, int port)
{
	u16 ptr;
	int err;

	ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_INGRESS_DEST;
	err = mv88e6390_g1_monitor_write(chip, ptr, port);
	if (err)
		return err;

	ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_EGRESS_DEST;
	err = mv88e6390_g1_monitor_write(chip, ptr, port);
	if (err)
		return err;

	return 0;
}

int mv88e6390_g1_set_cpu_port(struct mv88e6xxx_chip *chip, int port)
{
	u16 ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_CPU_DEST;

	return mv88e6390_g1_monitor_write(chip, ptr, port);
}

int mv88e6390_g1_mgmt_rsvd2cpu(struct mv88e6xxx_chip *chip)
{
	u16 ptr;
	int err;

	/* 01:c2:80:00:00:00:00-01:c2:80:00:00:00:07 are Management */
	ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000000XLO;
	err = mv88e6390_g1_monitor_write(chip, ptr, 0xff);
	if (err)
		return err;

	/* 01:c2:80:00:00:00:08-01:c2:80:00:00:00:0f are Management */
	ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000000XHI;
	err = mv88e6390_g1_monitor_write(chip, ptr, 0xff);
	if (err)
		return err;

	/* 01:c2:80:00:00:00:20-01:c2:80:00:00:00:27 are Management */
	ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000002XLO;
	err = mv88e6390_g1_monitor_write(chip, ptr, 0xff);
	if (err)
		return err;

	/* 01:c2:80:00:00:00:28-01:c2:80:00:00:00:2f are Management */
	ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000002XHI;
	err = mv88e6390_g1_monitor_write(chip, ptr, 0xff);
	if (err)
		return err;

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g1_ctl2_mask(struct mv88e6xxx_chip *chip, u16 mask,
				  u16 val)
{
	u16 reg;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL2, &reg);
	if (err)
		return err;

	reg &= ~mask;
	reg |= val & mask;

	return mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL2, reg);
}

int mv88e6185_g1_set_cascade_port(struct mv88e6xxx_chip *chip, int port)
{
	const u16 mask = MV88E6185_G1_CTL2_CASCADE_PORT_MASK;

	return mv88e6xxx_g1_ctl2_mask(chip, mask, port << __bf_shf(mask));
}

int mv88e6085_g1_rmu_disable(struct mv88e6xxx_chip *chip)
{
	return mv88e6xxx_g1_ctl2_mask(chip, MV88E6085_G1_CTL2_P10RM |
				      MV88E6085_G1_CTL2_RM_ENABLE, 0);
}

int mv88e6352_g1_rmu_disable(struct mv88e6xxx_chip *chip)
{
	return mv88e6xxx_g1_ctl2_mask(chip, MV88E6352_G1_CTL2_RMU_MODE_MASK,
				      MV88E6352_G1_CTL2_RMU_MODE_DISABLED);
}

int mv88e6390_g1_rmu_disable(struct mv88e6xxx_chip *chip)
{
	return mv88e6xxx_g1_ctl2_mask(chip, MV88E6390_G1_CTL2_RMU_MODE_MASK,
				      MV88E6390_G1_CTL2_RMU_MODE_DISABLED);
}

int mv88e6390_g1_stats_set_histogram(struct mv88e6xxx_chip *chip)
{
	return mv88e6xxx_g1_ctl2_mask(chip, MV88E6390_G1_CTL2_HIST_MODE_MASK,
				      MV88E6390_G1_CTL2_HIST_MODE_RX |
				      MV88E6390_G1_CTL2_HIST_MODE_TX);
}

int mv88e6xxx_g1_set_device_number(struct mv88e6xxx_chip *chip, int index)
{
	return mv88e6xxx_g1_ctl2_mask(chip,
				      MV88E6XXX_G1_CTL2_DEVICE_NUMBER_MASK,
				      index);
}

int mv88e6xxx_g1_stats_wait(struct mv88e6xxx_chip *chip)
{
	return mv88e6xxx_g1_wait(chip, MV88E6XXX_G1_STATS_OP,
				 MV88E6XXX_G1_STATS_OP_BUSY);
}

int mv88e6095_g1_stats_set_histogram(struct mv88e6xxx_chip *chip)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STATS_OP, &val);
	if (err)
		return err;

	val |= MV88E6XXX_G1_STATS_OP_HIST_RX_TX;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_STATS_OP, val);

	return err;
}

int mv88e6xxx_g1_stats_snapshot(struct mv88e6xxx_chip *chip, int port)
{
	int err;

	/* Snapshot the hardware statistics counters for this port. */
	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_STATS_OP,
				 MV88E6XXX_G1_STATS_OP_BUSY |
				 MV88E6XXX_G1_STATS_OP_CAPTURE_PORT |
				 MV88E6XXX_G1_STATS_OP_HIST_RX_TX | port);
	if (err)
		return err;

	/* Wait for the snapshotting to complete. */
	return mv88e6xxx_g1_stats_wait(chip);
}

int mv88e6320_g1_stats_snapshot(struct mv88e6xxx_chip *chip, int port)
{
	port = (port + 1) << 5;

	return mv88e6xxx_g1_stats_snapshot(chip, port);
}

int mv88e6390_g1_stats_snapshot(struct mv88e6xxx_chip *chip, int port)
{
	int err;

	port = (port + 1) << 5;

	/* Snapshot the hardware statistics counters for this port. */
	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_STATS_OP,
				 MV88E6XXX_G1_STATS_OP_BUSY |
				 MV88E6XXX_G1_STATS_OP_CAPTURE_PORT | port);
	if (err)
		return err;

	/* Wait for the snapshotting to complete. */
	return mv88e6xxx_g1_stats_wait(chip);
}

void mv88e6xxx_g1_stats_read(struct mv88e6xxx_chip *chip, int stat, u32 *val)
{
	u32 value;
	u16 reg;
	int err;

	*val = 0;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_STATS_OP,
				 MV88E6XXX_G1_STATS_OP_BUSY |
				 MV88E6XXX_G1_STATS_OP_READ_CAPTURED | stat);
	if (err)
		return;

	err = mv88e6xxx_g1_stats_wait(chip);
	if (err)
		return;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STATS_COUNTER_32, &reg);
	if (err)
		return;

	value = reg << 16;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STATS_COUNTER_01, &reg);
	if (err)
		return;

	*val = value | reg;
}

int mv88e6xxx_g1_stats_clear(struct mv88e6xxx_chip *chip)
{
	int err;
	u16 val;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STATS_OP, &val);
	if (err)
		return err;

	/* Keep the histogram mode bits */
	val &= MV88E6XXX_G1_STATS_OP_HIST_RX_TX;
	val |= MV88E6XXX_G1_STATS_OP_BUSY | MV88E6XXX_G1_STATS_OP_FLUSH_ALL;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_STATS_OP, val);
	if (err)
		return err;

	/* Wait for the flush to complete. */
	return mv88e6xxx_g1_stats_wait(chip);
}

