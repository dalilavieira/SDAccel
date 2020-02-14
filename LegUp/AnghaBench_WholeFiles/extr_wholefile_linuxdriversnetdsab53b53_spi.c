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
typedef  int u64 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
typedef  int /*<<< orphan*/  txbuf ;
struct TYPE_2__ {scalar_t__ platform_data; } ;
struct spi_device {TYPE_1__ dev; } ;
struct b53_device {scalar_t__ chip_id; scalar_t__ pdata; struct spi_device* priv; int /*<<< orphan*/  ds; } ;
struct b53_arl_entry {int port; int is_valid; int is_age; int is_static; int vid; int /*<<< orphan*/  mac; } ;

/* Variables and functions */
 int ARLTBL_AGE ; 
 int ARLTBL_DATA_PORT_ID_MASK ; 
 int ARLTBL_STATIC ; 
 int ARLTBL_VALID ; 
 int ARLTBL_VID_MASK ; 
 int ARLTBL_VID_S ; 
 int B53_SPI_CMD_NORMAL ; 
 int B53_SPI_CMD_RACK ; 
 int B53_SPI_CMD_READ ; 
 int B53_SPI_CMD_SPIF ; 
 int B53_SPI_CMD_WRITE ; 
 int B53_SPI_DATA ; 
 int B53_SPI_PAGE_SELECT ; 
 int B53_SPI_STATUS ; 
 scalar_t__ BCM53010_DEVICE_ID ; 
 scalar_t__ BCM53011_DEVICE_ID ; 
 scalar_t__ BCM53012_DEVICE_ID ; 
 scalar_t__ BCM53018_DEVICE_ID ; 
 scalar_t__ BCM53019_DEVICE_ID ; 
 scalar_t__ BCM53115_DEVICE_ID ; 
 scalar_t__ BCM53125_DEVICE_ID ; 
 scalar_t__ BCM53128_DEVICE_ID ; 
 scalar_t__ BCM5325_DEVICE_ID ; 
 scalar_t__ BCM5395_DEVICE_ID ; 
 scalar_t__ BCM5397_DEVICE_ID ; 
 scalar_t__ BCM5398_DEVICE_ID ; 
 scalar_t__ BCM583XX_DEVICE_ID ; 
 scalar_t__ BCM58XX_DEVICE_ID ; 
 scalar_t__ BCM7278_DEVICE_ID ; 
 scalar_t__ BCM7445_DEVICE_ID ; 
 int EIO ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  b53_spi_ops ; 
 struct b53_device* b53_switch_alloc (TYPE_1__*,int /*<<< orphan*/ *,struct spi_device*) ; 
 int b53_switch_register (struct b53_device*) ; 
 int /*<<< orphan*/  dsa_unregister_switch (int /*<<< orphan*/ ) ; 
 int ether_addr_to_u64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int) ; 
 int le64_to_cpu (int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memset (struct b53_arl_entry*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  put_unaligned_le16 (int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  put_unaligned_le32 (int,int*) ; 
 int /*<<< orphan*/  put_unaligned_le64 (int,int*) ; 
 struct b53_device* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct b53_device*) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 int spi_write_then_read (struct spi_device*,int*,int,int*,unsigned int) ; 
 int /*<<< orphan*/  u64_to_ether_addr (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int is5325(struct b53_device *dev)
{
	return dev->chip_id == BCM5325_DEVICE_ID;
}

__attribute__((used)) static inline int is5365(struct b53_device *dev)
{
#ifdef CONFIG_BCM47XX
	return dev->chip_id == BCM5365_DEVICE_ID;
#else
	return 0;
#endif
}

__attribute__((used)) static inline int is5397_98(struct b53_device *dev)
{
	return dev->chip_id == BCM5397_DEVICE_ID ||
		dev->chip_id == BCM5398_DEVICE_ID;
}

__attribute__((used)) static inline int is539x(struct b53_device *dev)
{
	return dev->chip_id == BCM5395_DEVICE_ID ||
		dev->chip_id == BCM5397_DEVICE_ID ||
		dev->chip_id == BCM5398_DEVICE_ID;
}

__attribute__((used)) static inline int is531x5(struct b53_device *dev)
{
	return dev->chip_id == BCM53115_DEVICE_ID ||
		dev->chip_id == BCM53125_DEVICE_ID ||
		dev->chip_id == BCM53128_DEVICE_ID;
}

__attribute__((used)) static inline int is63xx(struct b53_device *dev)
{
#ifdef CONFIG_BCM63XX
	return dev->chip_id == BCM63XX_DEVICE_ID;
#else
	return 0;
#endif
}

__attribute__((used)) static inline int is5301x(struct b53_device *dev)
{
	return dev->chip_id == BCM53010_DEVICE_ID ||
		dev->chip_id == BCM53011_DEVICE_ID ||
		dev->chip_id == BCM53012_DEVICE_ID ||
		dev->chip_id == BCM53018_DEVICE_ID ||
		dev->chip_id == BCM53019_DEVICE_ID;
}

__attribute__((used)) static inline int is58xx(struct b53_device *dev)
{
	return dev->chip_id == BCM58XX_DEVICE_ID ||
		dev->chip_id == BCM583XX_DEVICE_ID ||
		dev->chip_id == BCM7445_DEVICE_ID ||
		dev->chip_id == BCM7278_DEVICE_ID;
}

__attribute__((used)) static inline void b53_switch_remove(struct b53_device *dev)
{
	dsa_unregister_switch(dev->ds);
}

__attribute__((used)) static inline void b53_arl_to_entry(struct b53_arl_entry *ent,
				    u64 mac_vid, u32 fwd_entry)
{
	memset(ent, 0, sizeof(*ent));
	ent->port = fwd_entry & ARLTBL_DATA_PORT_ID_MASK;
	ent->is_valid = !!(fwd_entry & ARLTBL_VALID);
	ent->is_age = !!(fwd_entry & ARLTBL_AGE);
	ent->is_static = !!(fwd_entry & ARLTBL_STATIC);
	u64_to_ether_addr(mac_vid, ent->mac);
	ent->vid = mac_vid >> ARLTBL_VID_S;
}

__attribute__((used)) static inline void b53_arl_from_entry(u64 *mac_vid, u32 *fwd_entry,
				      const struct b53_arl_entry *ent)
{
	*mac_vid = ether_addr_to_u64(ent->mac);
	*mac_vid |= (u64)(ent->vid & ARLTBL_VID_MASK) << ARLTBL_VID_S;
	*fwd_entry = ent->port & ARLTBL_DATA_PORT_ID_MASK;
	if (ent->is_valid)
		*fwd_entry |= ARLTBL_VALID;
	if (ent->is_static)
		*fwd_entry |= ARLTBL_STATIC;
	if (ent->is_age)
		*fwd_entry |= ARLTBL_AGE;
}

__attribute__((used)) static inline int b53_switch_get_reset_gpio(struct b53_device *dev)
{
	return -ENOENT;
}

__attribute__((used)) static inline int b53_spi_read_reg(struct spi_device *spi, u8 reg, u8 *val,
				   unsigned int len)
{
	u8 txbuf[2];

	txbuf[0] = B53_SPI_CMD_NORMAL | B53_SPI_CMD_READ;
	txbuf[1] = reg;

	return spi_write_then_read(spi, txbuf, 2, val, len);
}

__attribute__((used)) static inline int b53_spi_clear_status(struct spi_device *spi)
{
	unsigned int i;
	u8 rxbuf;
	int ret;

	for (i = 0; i < 10; i++) {
		ret = b53_spi_read_reg(spi, B53_SPI_STATUS, &rxbuf, 1);
		if (ret)
			return ret;

		if (!(rxbuf & B53_SPI_CMD_SPIF))
			break;

		mdelay(1);
	}

	if (i == 10)
		return -EIO;

	return 0;
}

__attribute__((used)) static inline int b53_spi_set_page(struct spi_device *spi, u8 page)
{
	u8 txbuf[3];

	txbuf[0] = B53_SPI_CMD_NORMAL | B53_SPI_CMD_WRITE;
	txbuf[1] = B53_SPI_PAGE_SELECT;
	txbuf[2] = page;

	return spi_write(spi, txbuf, sizeof(txbuf));
}

__attribute__((used)) static inline int b53_prepare_reg_access(struct spi_device *spi, u8 page)
{
	int ret = b53_spi_clear_status(spi);

	if (ret)
		return ret;

	return b53_spi_set_page(spi, page);
}

__attribute__((used)) static int b53_spi_prepare_reg_read(struct spi_device *spi, u8 reg)
{
	u8 rxbuf;
	int retry_count;
	int ret;

	ret = b53_spi_read_reg(spi, reg, &rxbuf, 1);
	if (ret)
		return ret;

	for (retry_count = 0; retry_count < 10; retry_count++) {
		ret = b53_spi_read_reg(spi, B53_SPI_STATUS, &rxbuf, 1);
		if (ret)
			return ret;

		if (rxbuf & B53_SPI_CMD_RACK)
			break;

		mdelay(1);
	}

	if (retry_count == 10)
		return -EIO;

	return 0;
}

__attribute__((used)) static int b53_spi_read(struct b53_device *dev, u8 page, u8 reg, u8 *data,
			unsigned int len)
{
	struct spi_device *spi = dev->priv;
	int ret;

	ret = b53_prepare_reg_access(spi, page);
	if (ret)
		return ret;

	ret = b53_spi_prepare_reg_read(spi, reg);
	if (ret)
		return ret;

	return b53_spi_read_reg(spi, B53_SPI_DATA, data, len);
}

__attribute__((used)) static int b53_spi_read8(struct b53_device *dev, u8 page, u8 reg, u8 *val)
{
	return b53_spi_read(dev, page, reg, val, 1);
}

__attribute__((used)) static int b53_spi_read16(struct b53_device *dev, u8 page, u8 reg, u16 *val)
{
	int ret = b53_spi_read(dev, page, reg, (u8 *)val, 2);

	if (!ret)
		*val = le16_to_cpu(*val);

	return ret;
}

__attribute__((used)) static int b53_spi_read32(struct b53_device *dev, u8 page, u8 reg, u32 *val)
{
	int ret = b53_spi_read(dev, page, reg, (u8 *)val, 4);

	if (!ret)
		*val = le32_to_cpu(*val);

	return ret;
}

__attribute__((used)) static int b53_spi_read48(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
	int ret;

	*val = 0;
	ret = b53_spi_read(dev, page, reg, (u8 *)val, 6);
	if (!ret)
		*val = le64_to_cpu(*val);

	return ret;
}

__attribute__((used)) static int b53_spi_read64(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
	int ret = b53_spi_read(dev, page, reg, (u8 *)val, 8);

	if (!ret)
		*val = le64_to_cpu(*val);

	return ret;
}

__attribute__((used)) static int b53_spi_write8(struct b53_device *dev, u8 page, u8 reg, u8 value)
{
	struct spi_device *spi = dev->priv;
	int ret;
	u8 txbuf[3];

	ret = b53_prepare_reg_access(spi, page);
	if (ret)
		return ret;

	txbuf[0] = B53_SPI_CMD_NORMAL | B53_SPI_CMD_WRITE;
	txbuf[1] = reg;
	txbuf[2] = value;

	return spi_write(spi, txbuf, sizeof(txbuf));
}

__attribute__((used)) static int b53_spi_write16(struct b53_device *dev, u8 page, u8 reg, u16 value)
{
	struct spi_device *spi = dev->priv;
	int ret;
	u8 txbuf[4];

	ret = b53_prepare_reg_access(spi, page);
	if (ret)
		return ret;

	txbuf[0] = B53_SPI_CMD_NORMAL | B53_SPI_CMD_WRITE;
	txbuf[1] = reg;
	put_unaligned_le16(value, &txbuf[2]);

	return spi_write(spi, txbuf, sizeof(txbuf));
}

__attribute__((used)) static int b53_spi_write32(struct b53_device *dev, u8 page, u8 reg, u32 value)
{
	struct spi_device *spi = dev->priv;
	int ret;
	u8 txbuf[6];

	ret = b53_prepare_reg_access(spi, page);
	if (ret)
		return ret;

	txbuf[0] = B53_SPI_CMD_NORMAL | B53_SPI_CMD_WRITE;
	txbuf[1] = reg;
	put_unaligned_le32(value, &txbuf[2]);

	return spi_write(spi, txbuf, sizeof(txbuf));
}

__attribute__((used)) static int b53_spi_write48(struct b53_device *dev, u8 page, u8 reg, u64 value)
{
	struct spi_device *spi = dev->priv;
	int ret;
	u8 txbuf[10];

	ret = b53_prepare_reg_access(spi, page);
	if (ret)
		return ret;

	txbuf[0] = B53_SPI_CMD_NORMAL | B53_SPI_CMD_WRITE;
	txbuf[1] = reg;
	put_unaligned_le64(value, &txbuf[2]);

	return spi_write(spi, txbuf, sizeof(txbuf) - 2);
}

__attribute__((used)) static int b53_spi_write64(struct b53_device *dev, u8 page, u8 reg, u64 value)
{
	struct spi_device *spi = dev->priv;
	int ret;
	u8 txbuf[10];

	ret = b53_prepare_reg_access(spi, page);
	if (ret)
		return ret;

	txbuf[0] = B53_SPI_CMD_NORMAL | B53_SPI_CMD_WRITE;
	txbuf[1] = reg;
	put_unaligned_le64(value, &txbuf[2]);

	return spi_write(spi, txbuf, sizeof(txbuf));
}

__attribute__((used)) static int b53_spi_probe(struct spi_device *spi)
{
	struct b53_device *dev;
	int ret;

	dev = b53_switch_alloc(&spi->dev, &b53_spi_ops, spi);
	if (!dev)
		return -ENOMEM;

	if (spi->dev.platform_data)
		dev->pdata = spi->dev.platform_data;

	ret = b53_switch_register(dev);
	if (ret)
		return ret;

	spi_set_drvdata(spi, dev);

	return 0;
}

__attribute__((used)) static int b53_spi_remove(struct spi_device *spi)
{
	struct b53_device *dev = spi_get_drvdata(spi);

	if (dev)
		b53_switch_remove(dev);

	return 0;
}

