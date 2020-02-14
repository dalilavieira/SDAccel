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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct mv88e6xxx_chip {int /*<<< orphan*/  dev; TYPE_1__* info; } ;
struct mii_bus {int dummy; } ;
struct ethtool_eeprom {int dummy; } ;
struct TYPE_2__ {int pvt; unsigned int num_databases; unsigned int num_ports; unsigned int num_gpio; scalar_t__ global2_addr; } ;

/* Variables and functions */
 int E2BIG ; 
 int EOPNOTSUPP ; 
 int GENMASK (unsigned int,int /*<<< orphan*/ ) ; 
 int MV88E6165_G2_AVB_CMD_PORT_PTPGLOBAL ; 
 int MV88E6352_G2_AVB_CMD ; 
 int MV88E6352_G2_AVB_CMD_BLOCK_PTP ; 
 int MV88E6352_G2_AVB_CMD_OP_READ ; 
 int MV88E6352_G2_AVB_CMD_OP_READ_INCR ; 
 int MV88E6352_G2_AVB_CMD_OP_WRITE ; 
 int MV88E6352_G2_AVB_CMD_PORT_PTPGLOBAL ; 
 int MV88E6352_G2_AVB_CMD_PORT_TAIGLOBAL ; 
 int MV88E6352_G2_AVB_DATA ; 
 int MV88E6390_G2_AVB_CMD_OP_READ ; 
 int MV88E6390_G2_AVB_CMD_OP_READ_INCR ; 
 int MV88E6390_G2_AVB_CMD_OP_WRITE ; 
 int MV88E6390_G2_AVB_CMD_PORT_PTPGLOBAL ; 
 int MV88E6390_G2_AVB_CMD_PORT_TAIGLOBAL ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 

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

__attribute__((used)) static inline int mv88e6xxx_g2_require(struct mv88e6xxx_chip *chip)
{
	if (chip->info->global2_addr) {
		dev_err(chip->dev, "this chip requires CONFIG_NET_DSA_MV88E6XXX_GLOBAL2 enabled\n");
		return -EOPNOTSUPP;
	}

	return 0;
}

__attribute__((used)) static inline int mv88e6xxx_g2_read(struct mv88e6xxx_chip *chip, int reg, u16 *val)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_write(struct mv88e6xxx_chip *chip, int reg, u16 val)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_update(struct mv88e6xxx_chip *chip, int reg, u16 update)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_wait(struct mv88e6xxx_chip *chip, int reg, u16 mask)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6352_g2_irl_init_all(struct mv88e6xxx_chip *chip,
					    int port)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6390_g2_irl_init_all(struct mv88e6xxx_chip *chip,
					    int port)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_smi_phy_read(struct mv88e6xxx_chip *chip,
					    struct mii_bus *bus,
					    int addr, int reg, u16 *val)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_smi_phy_write(struct mv88e6xxx_chip *chip,
					     struct mii_bus *bus,
					     int addr, int reg, u16 val)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_set_switch_mac(struct mv88e6xxx_chip *chip,
					      u8 *addr)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_get_eeprom8(struct mv88e6xxx_chip *chip,
					   struct ethtool_eeprom *eeprom,
					   u8 *data)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_set_eeprom8(struct mv88e6xxx_chip *chip,
					   struct ethtool_eeprom *eeprom,
					   u8 *data)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_get_eeprom16(struct mv88e6xxx_chip *chip,
					    struct ethtool_eeprom *eeprom,
					    u8 *data)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_set_eeprom16(struct mv88e6xxx_chip *chip,
					    struct ethtool_eeprom *eeprom,
					    u8 *data)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_pvt_write(struct mv88e6xxx_chip *chip,
					 int src_dev, int src_port, u16 data)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_misc_4_bit_port(struct mv88e6xxx_chip *chip)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_irq_setup(struct mv88e6xxx_chip *chip)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline void mv88e6xxx_g2_irq_free(struct mv88e6xxx_chip *chip)
{
}

__attribute__((used)) static inline int mv88e6xxx_g2_irq_mdio_setup(struct mv88e6xxx_chip *chip,
					      struct mii_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline void mv88e6xxx_g2_irq_mdio_free(struct mv88e6xxx_chip *chip,
					      struct mii_bus *bus)
{
}

__attribute__((used)) static inline int mv88e6185_g2_mgmt_rsvd2cpu(struct mv88e6xxx_chip *chip)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6352_g2_mgmt_rsvd2cpu(struct mv88e6xxx_chip *chip)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_pot_clear(struct mv88e6xxx_chip *chip)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_scratch_gpio_set_smi(struct mv88e6xxx_chip *chip,
						    bool external)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_trunk_clear(struct mv88e6xxx_chip *chip)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mv88e6xxx_g2_device_mapping_write(struct mv88e6xxx_chip *chip,
						    int target, int port)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static int mv88e6xxx_g2_avb_read(struct mv88e6xxx_chip *chip, u16 readop,
				 u16 *data, int len)
{
	int err;
	int i;

	/* Hardware can only snapshot four words. */
	if (len > 4)
		return -E2BIG;

	err = mv88e6xxx_g2_update(chip, MV88E6352_G2_AVB_CMD, readop);
	if (err)
		return err;

	for (i = 0; i < len; ++i) {
		err = mv88e6xxx_g2_read(chip, MV88E6352_G2_AVB_DATA,
					&data[i]);
		if (err)
			return err;
	}

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g2_avb_write(struct mv88e6xxx_chip *chip, u16 writeop,
				  u16 data)
{
	int err;

	err = mv88e6xxx_g2_write(chip, MV88E6352_G2_AVB_DATA, data);
	if (err)
		return err;

	return mv88e6xxx_g2_update(chip, MV88E6352_G2_AVB_CMD, writeop);
}

__attribute__((used)) static int mv88e6352_g2_avb_port_ptp_read(struct mv88e6xxx_chip *chip,
					  int port, int addr, u16 *data,
					  int len)
{
	u16 readop = (len == 1 ? MV88E6352_G2_AVB_CMD_OP_READ :
				 MV88E6352_G2_AVB_CMD_OP_READ_INCR) |
		     (port << 8) | (MV88E6352_G2_AVB_CMD_BLOCK_PTP << 5) |
		     addr;

	return mv88e6xxx_g2_avb_read(chip, readop, data, len);
}

__attribute__((used)) static int mv88e6352_g2_avb_port_ptp_write(struct mv88e6xxx_chip *chip,
					   int port, int addr, u16 data)
{
	u16 writeop = MV88E6352_G2_AVB_CMD_OP_WRITE | (port << 8) |
		      (MV88E6352_G2_AVB_CMD_BLOCK_PTP << 5) | addr;

	return mv88e6xxx_g2_avb_write(chip, writeop, data);
}

__attribute__((used)) static int mv88e6352_g2_avb_ptp_read(struct mv88e6xxx_chip *chip, int addr,
				     u16 *data, int len)
{
	return mv88e6352_g2_avb_port_ptp_read(chip,
					MV88E6352_G2_AVB_CMD_PORT_PTPGLOBAL,
					addr, data, len);
}

__attribute__((used)) static int mv88e6352_g2_avb_ptp_write(struct mv88e6xxx_chip *chip, int addr,
				      u16 data)
{
	return mv88e6352_g2_avb_port_ptp_write(chip,
					MV88E6352_G2_AVB_CMD_PORT_PTPGLOBAL,
					addr, data);
}

__attribute__((used)) static int mv88e6352_g2_avb_tai_read(struct mv88e6xxx_chip *chip, int addr,
				     u16 *data, int len)
{
	return mv88e6352_g2_avb_port_ptp_read(chip,
					MV88E6352_G2_AVB_CMD_PORT_TAIGLOBAL,
					addr, data, len);
}

__attribute__((used)) static int mv88e6352_g2_avb_tai_write(struct mv88e6xxx_chip *chip, int addr,
				      u16 data)
{
	return mv88e6352_g2_avb_port_ptp_write(chip,
					MV88E6352_G2_AVB_CMD_PORT_TAIGLOBAL,
					addr, data);
}

__attribute__((used)) static int mv88e6165_g2_avb_tai_read(struct mv88e6xxx_chip *chip, int addr,
				     u16 *data, int len)
{
	return mv88e6352_g2_avb_port_ptp_read(chip,
					MV88E6165_G2_AVB_CMD_PORT_PTPGLOBAL,
					addr, data, len);
}

__attribute__((used)) static int mv88e6165_g2_avb_tai_write(struct mv88e6xxx_chip *chip, int addr,
				      u16 data)
{
	return mv88e6352_g2_avb_port_ptp_write(chip,
					MV88E6165_G2_AVB_CMD_PORT_PTPGLOBAL,
					addr, data);
}

__attribute__((used)) static int mv88e6390_g2_avb_port_ptp_read(struct mv88e6xxx_chip *chip,
					  int port, int addr, u16 *data,
					  int len)
{
	u16 readop = (len == 1 ? MV88E6390_G2_AVB_CMD_OP_READ :
				 MV88E6390_G2_AVB_CMD_OP_READ_INCR) |
		     (port << 8) | (MV88E6352_G2_AVB_CMD_BLOCK_PTP << 5) |
		     addr;

	return mv88e6xxx_g2_avb_read(chip, readop, data, len);
}

__attribute__((used)) static int mv88e6390_g2_avb_port_ptp_write(struct mv88e6xxx_chip *chip,
					   int port, int addr, u16 data)
{
	u16 writeop = MV88E6390_G2_AVB_CMD_OP_WRITE | (port << 8) |
		      (MV88E6352_G2_AVB_CMD_BLOCK_PTP << 5) | addr;

	return mv88e6xxx_g2_avb_write(chip, writeop, data);
}

__attribute__((used)) static int mv88e6390_g2_avb_ptp_read(struct mv88e6xxx_chip *chip, int addr,
				     u16 *data, int len)
{
	return mv88e6390_g2_avb_port_ptp_read(chip,
					MV88E6390_G2_AVB_CMD_PORT_PTPGLOBAL,
					addr, data, len);
}

__attribute__((used)) static int mv88e6390_g2_avb_ptp_write(struct mv88e6xxx_chip *chip, int addr,
				      u16 data)
{
	return mv88e6390_g2_avb_port_ptp_write(chip,
					MV88E6390_G2_AVB_CMD_PORT_PTPGLOBAL,
					addr, data);
}

__attribute__((used)) static int mv88e6390_g2_avb_tai_read(struct mv88e6xxx_chip *chip, int addr,
				     u16 *data, int len)
{
	return mv88e6390_g2_avb_port_ptp_read(chip,
					MV88E6390_G2_AVB_CMD_PORT_TAIGLOBAL,
					addr, data, len);
}

__attribute__((used)) static int mv88e6390_g2_avb_tai_write(struct mv88e6xxx_chip *chip, int addr,
				      u16 data)
{
	return mv88e6390_g2_avb_port_ptp_write(chip,
					MV88E6390_G2_AVB_CMD_PORT_TAIGLOBAL,
					addr, data);
}

