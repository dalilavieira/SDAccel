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
typedef  int /*<<< orphan*/  val ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct rtl818x_rf_ops {int dummy; } ;
struct rtl8187_priv {int txpwr_base; scalar_t__ hw_rev; int /*<<< orphan*/  is_rtl8187b; TYPE_6__* rf; TYPE_3__* map; TYPE_2__* channels; scalar_t__ asic_rev; int /*<<< orphan*/  io_mutex; TYPE_1__* io_dmabuf; int /*<<< orphan*/  udev; } ;
struct ieee80211_hw {struct rtl8187_priv* priv; int /*<<< orphan*/  wiphy; } ;
struct TYPE_11__ {TYPE_4__* chan; } ;
struct ieee80211_conf {TYPE_5__ chandef; } ;
typedef  int /*<<< orphan*/  data ;
typedef  int __le32 ;
typedef  int __le16 ;
struct TYPE_12__ {scalar_t__ init; } ;
struct TYPE_10__ {int /*<<< orphan*/  center_freq; } ;
struct TYPE_9__ {int RFPinsOutput; int RFPinsEnable; int RFPinsSelect; int RFPinsInput; int TX_GAIN_CCK; int EEPROM_CMD; int CONFIG3; int ANAPARAM2; int TX_GAIN_OFDM; int TESTR; int TX_ANTENNA; } ;
struct TYPE_8__ {int hw_value; } ;
struct TYPE_7__ {int bits8; int bits16; int bits32; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int HZ ; 
 scalar_t__ RTL8187BvB ; 
 int /*<<< orphan*/  RTL8187_REQT_READ ; 
 int /*<<< orphan*/  RTL8187_REQT_WRITE ; 
 int /*<<< orphan*/  RTL8187_REQ_GET_REG ; 
 int /*<<< orphan*/  RTL8187_REQ_SET_REG ; 
 int RTL8187_RTL8225_ANAPARAM2_ON ; 
 int RTL818X_CONFIG3_ANAPARAM_WRITE ; 
 int RTL818X_EEPROM_CMD_CONFIG ; 
 int RTL818X_EEPROM_CMD_NORMAL ; 
 void* cpu_to_le16 (int) ; 
 int cpu_to_le32 (int) ; 
 int ieee80211_frequency_to_channel (int /*<<< orphan*/ ) ; 
 int le16_to_cpu (int) ; 
 int le32_to_cpu (int) ; 
 int min (int,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rtl8187_write_phy (struct ieee80211_hw*,int,int) ; 
 int rtl818x_ioread16_idx (struct rtl8187_priv*,int*,int) ; 
 int rtl818x_ioread32_idx (struct rtl8187_priv*,int*,int) ; 
 int rtl818x_ioread8_idx (struct rtl8187_priv*,int*,int) ; 
 void rtl818x_iowrite16_idx (struct rtl8187_priv*,int*,int,int) ; 
 void rtl818x_iowrite32_idx (struct rtl8187_priv*,int*,int,int) ; 
 void rtl818x_iowrite8_idx (struct rtl8187_priv*,int*,int,int) ; 
 int* rtl8225_agc ; 
 int* rtl8225_chan ; 
 int* rtl8225_gain ; 
 struct rtl818x_rf_ops const rtl8225_ops ; 
 int* rtl8225_threshold ; 
 int* rtl8225_tx_gain_cck_ofdm ; 
 int* rtl8225_tx_power_cck ; 
 int* rtl8225_tx_power_cck_ch14 ; 
 int* rtl8225_tx_power_ofdm ; 
 int* rtl8225bcd_rxgain ; 
 int* rtl8225z2_agc ; 
 struct rtl818x_rf_ops const rtl8225z2_b_ops ; 
 int* rtl8225z2_gain_bg ; 
 int* rtl8225z2_ofdm ; 
 struct rtl818x_rf_ops const rtl8225z2_ops ; 
 int* rtl8225z2_rxgain ; 
 int* rtl8225z2_tx_gain_cck_ofdm ; 
 int* rtl8225z2_tx_power_cck ; 
 int* rtl8225z2_tx_power_cck_ch14 ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usb_control_msg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int*,int,int) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wiphy_warn (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static inline u8 rtl818x_ioread8(struct rtl8187_priv *priv, u8 *addr)
{
	return rtl818x_ioread8_idx(priv, addr, 0);
}

__attribute__((used)) static inline u16 rtl818x_ioread16(struct rtl8187_priv *priv, __le16 *addr)
{
	return rtl818x_ioread16_idx(priv, addr, 0);
}

__attribute__((used)) static inline u32 rtl818x_ioread32(struct rtl8187_priv *priv, __le32 *addr)
{
	return rtl818x_ioread32_idx(priv, addr, 0);
}

__attribute__((used)) static inline void rtl818x_iowrite8(struct rtl8187_priv *priv, u8 *addr, u8 val)
{
	rtl818x_iowrite8_idx(priv, addr, val, 0);
}

__attribute__((used)) static inline void rtl818x_iowrite16(struct rtl8187_priv *priv, __le16 *addr,
				     u16 val)
{
	rtl818x_iowrite16_idx(priv, addr, val, 0);
}

__attribute__((used)) static inline void rtl818x_iowrite32(struct rtl8187_priv *priv, __le32 *addr,
				     u32 val)
{
	rtl818x_iowrite32_idx(priv, addr, val, 0);
}

__attribute__((used)) static inline void rtl8225_write_phy_ofdm(struct ieee80211_hw *dev,
					  u8 addr, u32 data)
{
	rtl8187_write_phy(dev, addr, data);
}

__attribute__((used)) static inline void rtl8225_write_phy_cck(struct ieee80211_hw *dev,
					 u8 addr, u32 data)
{
	rtl8187_write_phy(dev, addr, data | 0x10000);
}

u8 rtl818x_ioread8_idx(struct rtl8187_priv *priv,
				u8 *addr, u8 idx)
{
	u8 val;

	mutex_lock(&priv->io_mutex);
	usb_control_msg(priv->udev, usb_rcvctrlpipe(priv->udev, 0),
			RTL8187_REQ_GET_REG, RTL8187_REQT_READ,
			(unsigned long)addr, idx & 0x03,
			&priv->io_dmabuf->bits8, sizeof(val), HZ / 2);

	val = priv->io_dmabuf->bits8;
	mutex_unlock(&priv->io_mutex);

	return val;
}

u16 rtl818x_ioread16_idx(struct rtl8187_priv *priv,
				__le16 *addr, u8 idx)
{
	__le16 val;

	mutex_lock(&priv->io_mutex);
	usb_control_msg(priv->udev, usb_rcvctrlpipe(priv->udev, 0),
			RTL8187_REQ_GET_REG, RTL8187_REQT_READ,
			(unsigned long)addr, idx & 0x03,
			&priv->io_dmabuf->bits16, sizeof(val), HZ / 2);

	val = priv->io_dmabuf->bits16;
	mutex_unlock(&priv->io_mutex);

	return le16_to_cpu(val);
}

u32 rtl818x_ioread32_idx(struct rtl8187_priv *priv,
				__le32 *addr, u8 idx)
{
	__le32 val;

	mutex_lock(&priv->io_mutex);
	usb_control_msg(priv->udev, usb_rcvctrlpipe(priv->udev, 0),
			RTL8187_REQ_GET_REG, RTL8187_REQT_READ,
			(unsigned long)addr, idx & 0x03,
			&priv->io_dmabuf->bits32, sizeof(val), HZ / 2);

	val = priv->io_dmabuf->bits32;
	mutex_unlock(&priv->io_mutex);

	return le32_to_cpu(val);
}

void rtl818x_iowrite8_idx(struct rtl8187_priv *priv,
				u8 *addr, u8 val, u8 idx)
{
	mutex_lock(&priv->io_mutex);

	priv->io_dmabuf->bits8 = val;
	usb_control_msg(priv->udev, usb_sndctrlpipe(priv->udev, 0),
			RTL8187_REQ_SET_REG, RTL8187_REQT_WRITE,
			(unsigned long)addr, idx & 0x03,
			&priv->io_dmabuf->bits8, sizeof(val), HZ / 2);

	mutex_unlock(&priv->io_mutex);
}

void rtl818x_iowrite16_idx(struct rtl8187_priv *priv,
				__le16 *addr, u16 val, u8 idx)
{
	mutex_lock(&priv->io_mutex);

	priv->io_dmabuf->bits16 = cpu_to_le16(val);
	usb_control_msg(priv->udev, usb_sndctrlpipe(priv->udev, 0),
			RTL8187_REQ_SET_REG, RTL8187_REQT_WRITE,
			(unsigned long)addr, idx & 0x03,
			&priv->io_dmabuf->bits16, sizeof(val), HZ / 2);

	mutex_unlock(&priv->io_mutex);
}

void rtl818x_iowrite32_idx(struct rtl8187_priv *priv,
				__le32 *addr, u32 val, u8 idx)
{
	mutex_lock(&priv->io_mutex);

	priv->io_dmabuf->bits32 = cpu_to_le32(val);
	usb_control_msg(priv->udev, usb_sndctrlpipe(priv->udev, 0),
			RTL8187_REQ_SET_REG, RTL8187_REQT_WRITE,
			(unsigned long)addr, idx & 0x03,
			&priv->io_dmabuf->bits32, sizeof(val), HZ / 2);

	mutex_unlock(&priv->io_mutex);
}

__attribute__((used)) static void rtl8225_write_bitbang(struct ieee80211_hw *dev, u8 addr, u16 data)
{
	struct rtl8187_priv *priv = dev->priv;
	u16 reg80, reg84, reg82;
	u32 bangdata;
	int i;

	bangdata = (data << 4) | (addr & 0xf);

	reg80 = rtl818x_ioread16(priv, &priv->map->RFPinsOutput) & 0xfff3;
	reg82 = rtl818x_ioread16(priv, &priv->map->RFPinsEnable);

	rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, reg82 | 0x7);

	reg84 = rtl818x_ioread16(priv, &priv->map->RFPinsSelect);
	rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84 | 0x7);
	udelay(10);

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
	udelay(2);
	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80);
	udelay(10);

	for (i = 15; i >= 0; i--) {
		u16 reg = reg80 | (bangdata & (1 << i)) >> i;

		if (i & 1)
			rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg);

		rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg | (1 << 1));
		rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg | (1 << 1));

		if (!(i & 1))
			rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg);
	}

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
	udelay(10);

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
	rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84);
}

__attribute__((used)) static void rtl8225_write_8051(struct ieee80211_hw *dev, u8 addr, __le16 data)
{
	struct rtl8187_priv *priv = dev->priv;
	u16 reg80, reg82, reg84;

	reg80 = rtl818x_ioread16(priv, &priv->map->RFPinsOutput);
	reg82 = rtl818x_ioread16(priv, &priv->map->RFPinsEnable);
	reg84 = rtl818x_ioread16(priv, &priv->map->RFPinsSelect);

	reg80 &= ~(0x3 << 2);
	reg84 &= ~0xF;

	rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, reg82 | 0x0007);
	rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84 | 0x0007);
	udelay(10);

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
	udelay(2);

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80);
	udelay(10);

	mutex_lock(&priv->io_mutex);

	priv->io_dmabuf->bits16 = data;
	usb_control_msg(priv->udev, usb_sndctrlpipe(priv->udev, 0),
			RTL8187_REQ_SET_REG, RTL8187_REQT_WRITE,
			addr, 0x8225, &priv->io_dmabuf->bits16, sizeof(data),
			HZ / 2);

	mutex_unlock(&priv->io_mutex);

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
	udelay(10);

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
	rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84);
}

__attribute__((used)) static void rtl8225_write(struct ieee80211_hw *dev, u8 addr, u16 data)
{
	struct rtl8187_priv *priv = dev->priv;

	if (priv->asic_rev)
		rtl8225_write_8051(dev, addr, cpu_to_le16(data));
	else
		rtl8225_write_bitbang(dev, addr, data);
}

__attribute__((used)) static u16 rtl8225_read(struct ieee80211_hw *dev, u8 addr)
{
	struct rtl8187_priv *priv = dev->priv;
	u16 reg80, reg82, reg84, out;
	int i;

	reg80 = rtl818x_ioread16(priv, &priv->map->RFPinsOutput);
	reg82 = rtl818x_ioread16(priv, &priv->map->RFPinsEnable);
	reg84 = rtl818x_ioread16(priv, &priv->map->RFPinsSelect);

	reg80 &= ~0xF;

	rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, reg82 | 0x000F);
	rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84 | 0x000F);

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
	udelay(4);
	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80);
	udelay(5);

	for (i = 4; i >= 0; i--) {
		u16 reg = reg80 | ((addr >> i) & 1);

		if (!(i & 1)) {
			rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg);
			udelay(1);
		}

		rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
				  reg | (1 << 1));
		udelay(2);
		rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
				  reg | (1 << 1));
		udelay(2);

		if (i & 1) {
			rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg);
			udelay(1);
		}
	}

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
			  reg80 | (1 << 3) | (1 << 1));
	udelay(2);
	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
			  reg80 | (1 << 3));
	udelay(2);
	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
			  reg80 | (1 << 3));
	udelay(2);

	out = 0;
	for (i = 11; i >= 0; i--) {
		rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
				  reg80 | (1 << 3));
		udelay(1);
		rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
				  reg80 | (1 << 3) | (1 << 1));
		udelay(2);
		rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
				  reg80 | (1 << 3) | (1 << 1));
		udelay(2);
		rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
				  reg80 | (1 << 3) | (1 << 1));
		udelay(2);

		if (rtl818x_ioread16(priv, &priv->map->RFPinsInput) & (1 << 1))
			out |= 1 << i;

		rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
				  reg80 | (1 << 3));
		udelay(2);
	}

	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
			  reg80 | (1 << 3) | (1 << 2));
	udelay(2);

	rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, reg82);
	rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84);
	rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, 0x03A0);

	return out;
}

__attribute__((used)) static void rtl8225_rf_set_tx_power(struct ieee80211_hw *dev, int channel)
{
	struct rtl8187_priv *priv = dev->priv;
	u8 cck_power, ofdm_power;
	const u8 *tmp;
	u32 reg;
	int i;

	cck_power = priv->channels[channel - 1].hw_value & 0xF;
	ofdm_power = priv->channels[channel - 1].hw_value >> 4;

	cck_power = min(cck_power, (u8)11);
	if (ofdm_power > (u8)15)
		ofdm_power = 25;
	else
		ofdm_power += 10;

	rtl818x_iowrite8(priv, &priv->map->TX_GAIN_CCK,
			 rtl8225_tx_gain_cck_ofdm[cck_power / 6] >> 1);

	if (channel == 14)
		tmp = &rtl8225_tx_power_cck_ch14[(cck_power % 6) * 8];
	else
		tmp = &rtl8225_tx_power_cck[(cck_power % 6) * 8];

	for (i = 0; i < 8; i++)
		rtl8225_write_phy_cck(dev, 0x44 + i, *tmp++);

	msleep(1); // FIXME: optional?

	/* anaparam2 on */
	rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
	reg = rtl818x_ioread8(priv, &priv->map->CONFIG3);
	rtl818x_iowrite8(priv, &priv->map->CONFIG3,
			reg | RTL818X_CONFIG3_ANAPARAM_WRITE);
	rtl818x_iowrite32(priv, &priv->map->ANAPARAM2,
			  RTL8187_RTL8225_ANAPARAM2_ON);
	rtl818x_iowrite8(priv, &priv->map->CONFIG3,
			reg & ~RTL818X_CONFIG3_ANAPARAM_WRITE);
	rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);

	rtl8225_write_phy_ofdm(dev, 2, 0x42);
	rtl8225_write_phy_ofdm(dev, 6, 0x00);
	rtl8225_write_phy_ofdm(dev, 8, 0x00);

	rtl818x_iowrite8(priv, &priv->map->TX_GAIN_OFDM,
			 rtl8225_tx_gain_cck_ofdm[ofdm_power / 6] >> 1);

	tmp = &rtl8225_tx_power_ofdm[ofdm_power % 6];

	rtl8225_write_phy_ofdm(dev, 5, *tmp);
	rtl8225_write_phy_ofdm(dev, 7, *tmp);

	msleep(1);
}

__attribute__((used)) static void rtl8225_rf_init(struct ieee80211_hw *dev)
{
	struct rtl8187_priv *priv = dev->priv;
	int i;

	rtl8225_write(dev, 0x0, 0x067);
	rtl8225_write(dev, 0x1, 0xFE0);
	rtl8225_write(dev, 0x2, 0x44D);
	rtl8225_write(dev, 0x3, 0x441);
	rtl8225_write(dev, 0x4, 0x486);
	rtl8225_write(dev, 0x5, 0xBC0);
	rtl8225_write(dev, 0x6, 0xAE6);
	rtl8225_write(dev, 0x7, 0x82A);
	rtl8225_write(dev, 0x8, 0x01F);
	rtl8225_write(dev, 0x9, 0x334);
	rtl8225_write(dev, 0xA, 0xFD4);
	rtl8225_write(dev, 0xB, 0x391);
	rtl8225_write(dev, 0xC, 0x050);
	rtl8225_write(dev, 0xD, 0x6DB);
	rtl8225_write(dev, 0xE, 0x029);
	rtl8225_write(dev, 0xF, 0x914); msleep(100);

	rtl8225_write(dev, 0x2, 0xC4D); msleep(200);
	rtl8225_write(dev, 0x2, 0x44D); msleep(200);

	if (!(rtl8225_read(dev, 6) & (1 << 7))) {
		rtl8225_write(dev, 0x02, 0x0c4d);
		msleep(200);
		rtl8225_write(dev, 0x02, 0x044d);
		msleep(100);
		if (!(rtl8225_read(dev, 6) & (1 << 7)))
			wiphy_warn(dev->wiphy, "RF Calibration Failed! %x\n",
				   rtl8225_read(dev, 6));
	}

	rtl8225_write(dev, 0x0, 0x127);

	for (i = 0; i < ARRAY_SIZE(rtl8225bcd_rxgain); i++) {
		rtl8225_write(dev, 0x1, i + 1);
		rtl8225_write(dev, 0x2, rtl8225bcd_rxgain[i]);
	}

	rtl8225_write(dev, 0x0, 0x027);
	rtl8225_write(dev, 0x0, 0x22F);

	for (i = 0; i < ARRAY_SIZE(rtl8225_agc); i++) {
		rtl8225_write_phy_ofdm(dev, 0xB, rtl8225_agc[i]);
		rtl8225_write_phy_ofdm(dev, 0xA, 0x80 + i);
	}

	msleep(1);

	rtl8225_write_phy_ofdm(dev, 0x00, 0x01);
	rtl8225_write_phy_ofdm(dev, 0x01, 0x02);
	rtl8225_write_phy_ofdm(dev, 0x02, 0x42);
	rtl8225_write_phy_ofdm(dev, 0x03, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x04, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x05, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x06, 0x40);
	rtl8225_write_phy_ofdm(dev, 0x07, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x08, 0x40);
	rtl8225_write_phy_ofdm(dev, 0x09, 0xfe);
	rtl8225_write_phy_ofdm(dev, 0x0a, 0x09);
	rtl8225_write_phy_ofdm(dev, 0x0b, 0x80);
	rtl8225_write_phy_ofdm(dev, 0x0c, 0x01);
	rtl8225_write_phy_ofdm(dev, 0x0e, 0xd3);
	rtl8225_write_phy_ofdm(dev, 0x0f, 0x38);
	rtl8225_write_phy_ofdm(dev, 0x10, 0x84);
	rtl8225_write_phy_ofdm(dev, 0x11, 0x06);
	rtl8225_write_phy_ofdm(dev, 0x12, 0x20);
	rtl8225_write_phy_ofdm(dev, 0x13, 0x20);
	rtl8225_write_phy_ofdm(dev, 0x14, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x15, 0x40);
	rtl8225_write_phy_ofdm(dev, 0x16, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x17, 0x40);
	rtl8225_write_phy_ofdm(dev, 0x18, 0xef);
	rtl8225_write_phy_ofdm(dev, 0x19, 0x19);
	rtl8225_write_phy_ofdm(dev, 0x1a, 0x20);
	rtl8225_write_phy_ofdm(dev, 0x1b, 0x76);
	rtl8225_write_phy_ofdm(dev, 0x1c, 0x04);
	rtl8225_write_phy_ofdm(dev, 0x1e, 0x95);
	rtl8225_write_phy_ofdm(dev, 0x1f, 0x75);
	rtl8225_write_phy_ofdm(dev, 0x20, 0x1f);
	rtl8225_write_phy_ofdm(dev, 0x21, 0x27);
	rtl8225_write_phy_ofdm(dev, 0x22, 0x16);
	rtl8225_write_phy_ofdm(dev, 0x24, 0x46);
	rtl8225_write_phy_ofdm(dev, 0x25, 0x20);
	rtl8225_write_phy_ofdm(dev, 0x26, 0x90);
	rtl8225_write_phy_ofdm(dev, 0x27, 0x88);

	rtl8225_write_phy_ofdm(dev, 0x0d, rtl8225_gain[2 * 4]);
	rtl8225_write_phy_ofdm(dev, 0x1b, rtl8225_gain[2 * 4 + 2]);
	rtl8225_write_phy_ofdm(dev, 0x1d, rtl8225_gain[2 * 4 + 3]);
	rtl8225_write_phy_ofdm(dev, 0x23, rtl8225_gain[2 * 4 + 1]);

	rtl8225_write_phy_cck(dev, 0x00, 0x98);
	rtl8225_write_phy_cck(dev, 0x03, 0x20);
	rtl8225_write_phy_cck(dev, 0x04, 0x7e);
	rtl8225_write_phy_cck(dev, 0x05, 0x12);
	rtl8225_write_phy_cck(dev, 0x06, 0xfc);
	rtl8225_write_phy_cck(dev, 0x07, 0x78);
	rtl8225_write_phy_cck(dev, 0x08, 0x2e);
	rtl8225_write_phy_cck(dev, 0x10, 0x9b);
	rtl8225_write_phy_cck(dev, 0x11, 0x88);
	rtl8225_write_phy_cck(dev, 0x12, 0x47);
	rtl8225_write_phy_cck(dev, 0x13, 0xd0);
	rtl8225_write_phy_cck(dev, 0x19, 0x00);
	rtl8225_write_phy_cck(dev, 0x1a, 0xa0);
	rtl8225_write_phy_cck(dev, 0x1b, 0x08);
	rtl8225_write_phy_cck(dev, 0x40, 0x86);
	rtl8225_write_phy_cck(dev, 0x41, 0x8d);
	rtl8225_write_phy_cck(dev, 0x42, 0x15);
	rtl8225_write_phy_cck(dev, 0x43, 0x18);
	rtl8225_write_phy_cck(dev, 0x44, 0x1f);
	rtl8225_write_phy_cck(dev, 0x45, 0x1e);
	rtl8225_write_phy_cck(dev, 0x46, 0x1a);
	rtl8225_write_phy_cck(dev, 0x47, 0x15);
	rtl8225_write_phy_cck(dev, 0x48, 0x10);
	rtl8225_write_phy_cck(dev, 0x49, 0x0a);
	rtl8225_write_phy_cck(dev, 0x4a, 0x05);
	rtl8225_write_phy_cck(dev, 0x4b, 0x02);
	rtl8225_write_phy_cck(dev, 0x4c, 0x05);

	rtl818x_iowrite8(priv, &priv->map->TESTR, 0x0D);

	rtl8225_rf_set_tx_power(dev, 1);

	/* RX antenna default to A */
	rtl8225_write_phy_cck(dev, 0x10, 0x9b);			/* B: 0xDB */
	rtl8225_write_phy_ofdm(dev, 0x26, 0x90);		/* B: 0x10 */

	rtl818x_iowrite8(priv, &priv->map->TX_ANTENNA, 0x03);	/* B: 0x00 */
	msleep(1);
	rtl818x_iowrite32(priv, (__le32 *)0xFF94, 0x3dc00002);

	/* set sensitivity */
	rtl8225_write(dev, 0x0c, 0x50);
	rtl8225_write_phy_ofdm(dev, 0x0d, rtl8225_gain[2 * 4]);
	rtl8225_write_phy_ofdm(dev, 0x1b, rtl8225_gain[2 * 4 + 2]);
	rtl8225_write_phy_ofdm(dev, 0x1d, rtl8225_gain[2 * 4 + 3]);
	rtl8225_write_phy_ofdm(dev, 0x23, rtl8225_gain[2 * 4 + 1]);
	rtl8225_write_phy_cck(dev, 0x41, rtl8225_threshold[2]);
}

__attribute__((used)) static void rtl8225z2_rf_set_tx_power(struct ieee80211_hw *dev, int channel)
{
	struct rtl8187_priv *priv = dev->priv;
	u8 cck_power, ofdm_power;
	const u8 *tmp;
	u32 reg;
	int i;

	cck_power = priv->channels[channel - 1].hw_value & 0xF;
	ofdm_power = priv->channels[channel - 1].hw_value >> 4;

	cck_power = min(cck_power, (u8)15);
	cck_power += priv->txpwr_base & 0xF;
	cck_power = min(cck_power, (u8)35);

	if (ofdm_power > (u8)15)
		ofdm_power = 25;
	else
		ofdm_power += 10;
	ofdm_power += priv->txpwr_base >> 4;
	ofdm_power = min(ofdm_power, (u8)35);

	if (channel == 14)
		tmp = rtl8225z2_tx_power_cck_ch14;
	else
		tmp = rtl8225z2_tx_power_cck;

	for (i = 0; i < 8; i++)
		rtl8225_write_phy_cck(dev, 0x44 + i, *tmp++);

	rtl818x_iowrite8(priv, &priv->map->TX_GAIN_CCK,
			 rtl8225z2_tx_gain_cck_ofdm[cck_power]);
	msleep(1);

	/* anaparam2 on */
	rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
	reg = rtl818x_ioread8(priv, &priv->map->CONFIG3);
	rtl818x_iowrite8(priv, &priv->map->CONFIG3,
			reg | RTL818X_CONFIG3_ANAPARAM_WRITE);
	rtl818x_iowrite32(priv, &priv->map->ANAPARAM2,
			  RTL8187_RTL8225_ANAPARAM2_ON);
	rtl818x_iowrite8(priv, &priv->map->CONFIG3,
			reg & ~RTL818X_CONFIG3_ANAPARAM_WRITE);
	rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);

	rtl8225_write_phy_ofdm(dev, 2, 0x42);
	rtl8225_write_phy_ofdm(dev, 5, 0x00);
	rtl8225_write_phy_ofdm(dev, 6, 0x40);
	rtl8225_write_phy_ofdm(dev, 7, 0x00);
	rtl8225_write_phy_ofdm(dev, 8, 0x40);

	rtl818x_iowrite8(priv, &priv->map->TX_GAIN_OFDM,
			 rtl8225z2_tx_gain_cck_ofdm[ofdm_power]);
	msleep(1);
}

__attribute__((used)) static void rtl8225z2_b_rf_set_tx_power(struct ieee80211_hw *dev, int channel)
{
	struct rtl8187_priv *priv = dev->priv;
	u8 cck_power, ofdm_power;
	const u8 *tmp;
	int i;

	cck_power = priv->channels[channel - 1].hw_value & 0xF;
	ofdm_power = priv->channels[channel - 1].hw_value >> 4;

	cck_power += (priv->hw_rev == RTL8187BvB) ? 0 : 7;
	cck_power += priv->txpwr_base & 0xF;
	cck_power = min(cck_power, (u8)35);

	if (ofdm_power > 15)
		ofdm_power = (priv->hw_rev == RTL8187BvB) ? 17 : 25;
	else
		ofdm_power += (priv->hw_rev == RTL8187BvB) ? 2 : 10;
	ofdm_power += (priv->txpwr_base >> 4) & 0xF;
	ofdm_power = min(ofdm_power, (u8)35);

	if (channel == 14)
		tmp = rtl8225z2_tx_power_cck_ch14;
	else
		tmp = rtl8225z2_tx_power_cck;

	if (priv->hw_rev == RTL8187BvB) {
		if (cck_power <= 6)
			; /* do nothing */
		else if (cck_power <= 11)
			tmp += 8;
		else
			tmp += 16;
	} else {
		if (cck_power <= 5)
			; /* do nothing */
		else if (cck_power <= 11)
			tmp += 8;
		else if (cck_power <= 17)
			tmp += 16;
		else
			tmp += 24;
	}

	for (i = 0; i < 8; i++)
		rtl8225_write_phy_cck(dev, 0x44 + i, *tmp++);

	rtl818x_iowrite8(priv, &priv->map->TX_GAIN_CCK,
			 rtl8225z2_tx_gain_cck_ofdm[cck_power] << 1);
	msleep(1);

	rtl818x_iowrite8(priv, &priv->map->TX_GAIN_OFDM,
			 rtl8225z2_tx_gain_cck_ofdm[ofdm_power] << 1);
	if (priv->hw_rev == RTL8187BvB) {
		if (ofdm_power <= 11) {
			rtl8225_write_phy_ofdm(dev, 0x87, 0x60);
			rtl8225_write_phy_ofdm(dev, 0x89, 0x60);
		} else {
			rtl8225_write_phy_ofdm(dev, 0x87, 0x5c);
			rtl8225_write_phy_ofdm(dev, 0x89, 0x5c);
		}
	} else {
		if (ofdm_power <= 11) {
			rtl8225_write_phy_ofdm(dev, 0x87, 0x5c);
			rtl8225_write_phy_ofdm(dev, 0x89, 0x5c);
		} else if (ofdm_power <= 17) {
			rtl8225_write_phy_ofdm(dev, 0x87, 0x54);
			rtl8225_write_phy_ofdm(dev, 0x89, 0x54);
		} else {
			rtl8225_write_phy_ofdm(dev, 0x87, 0x50);
			rtl8225_write_phy_ofdm(dev, 0x89, 0x50);
		}
	}
	msleep(1);
}

__attribute__((used)) static void rtl8225z2_rf_init(struct ieee80211_hw *dev)
{
	struct rtl8187_priv *priv = dev->priv;
	int i;

	rtl8225_write(dev, 0x0, 0x2BF);
	rtl8225_write(dev, 0x1, 0xEE0);
	rtl8225_write(dev, 0x2, 0x44D);
	rtl8225_write(dev, 0x3, 0x441);
	rtl8225_write(dev, 0x4, 0x8C3);
	rtl8225_write(dev, 0x5, 0xC72);
	rtl8225_write(dev, 0x6, 0x0E6);
	rtl8225_write(dev, 0x7, 0x82A);
	rtl8225_write(dev, 0x8, 0x03F);
	rtl8225_write(dev, 0x9, 0x335);
	rtl8225_write(dev, 0xa, 0x9D4);
	rtl8225_write(dev, 0xb, 0x7BB);
	rtl8225_write(dev, 0xc, 0x850);
	rtl8225_write(dev, 0xd, 0xCDF);
	rtl8225_write(dev, 0xe, 0x02B);
	rtl8225_write(dev, 0xf, 0x114);
	msleep(100);

	rtl8225_write(dev, 0x0, 0x1B7);

	for (i = 0; i < ARRAY_SIZE(rtl8225z2_rxgain); i++) {
		rtl8225_write(dev, 0x1, i + 1);
		rtl8225_write(dev, 0x2, rtl8225z2_rxgain[i]);
	}

	rtl8225_write(dev, 0x3, 0x080);
	rtl8225_write(dev, 0x5, 0x004);
	rtl8225_write(dev, 0x0, 0x0B7);
	rtl8225_write(dev, 0x2, 0xc4D);

	msleep(200);
	rtl8225_write(dev, 0x2, 0x44D);
	msleep(100);

	if (!(rtl8225_read(dev, 6) & (1 << 7))) {
		rtl8225_write(dev, 0x02, 0x0C4D);
		msleep(200);
		rtl8225_write(dev, 0x02, 0x044D);
		msleep(100);
		if (!(rtl8225_read(dev, 6) & (1 << 7)))
			wiphy_warn(dev->wiphy, "RF Calibration Failed! %x\n",
				   rtl8225_read(dev, 6));
	}

	msleep(200);

	rtl8225_write(dev, 0x0, 0x2BF);

	for (i = 0; i < ARRAY_SIZE(rtl8225_agc); i++) {
		rtl8225_write_phy_ofdm(dev, 0xB, rtl8225_agc[i]);
		rtl8225_write_phy_ofdm(dev, 0xA, 0x80 + i);
	}

	msleep(1);

	rtl8225_write_phy_ofdm(dev, 0x00, 0x01);
	rtl8225_write_phy_ofdm(dev, 0x01, 0x02);
	rtl8225_write_phy_ofdm(dev, 0x02, 0x42);
	rtl8225_write_phy_ofdm(dev, 0x03, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x04, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x05, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x06, 0x40);
	rtl8225_write_phy_ofdm(dev, 0x07, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x08, 0x40);
	rtl8225_write_phy_ofdm(dev, 0x09, 0xfe);
	rtl8225_write_phy_ofdm(dev, 0x0a, 0x08);
	rtl8225_write_phy_ofdm(dev, 0x0b, 0x80);
	rtl8225_write_phy_ofdm(dev, 0x0c, 0x01);
	rtl8225_write_phy_ofdm(dev, 0x0d, 0x43);
	rtl8225_write_phy_ofdm(dev, 0x0e, 0xd3);
	rtl8225_write_phy_ofdm(dev, 0x0f, 0x38);
	rtl8225_write_phy_ofdm(dev, 0x10, 0x84);
	rtl8225_write_phy_ofdm(dev, 0x11, 0x07);
	rtl8225_write_phy_ofdm(dev, 0x12, 0x20);
	rtl8225_write_phy_ofdm(dev, 0x13, 0x20);
	rtl8225_write_phy_ofdm(dev, 0x14, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x15, 0x40);
	rtl8225_write_phy_ofdm(dev, 0x16, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x17, 0x40);
	rtl8225_write_phy_ofdm(dev, 0x18, 0xef);
	rtl8225_write_phy_ofdm(dev, 0x19, 0x19);
	rtl8225_write_phy_ofdm(dev, 0x1a, 0x20);
	rtl8225_write_phy_ofdm(dev, 0x1b, 0x15);
	rtl8225_write_phy_ofdm(dev, 0x1c, 0x04);
	rtl8225_write_phy_ofdm(dev, 0x1d, 0xc5);
	rtl8225_write_phy_ofdm(dev, 0x1e, 0x95);
	rtl8225_write_phy_ofdm(dev, 0x1f, 0x75);
	rtl8225_write_phy_ofdm(dev, 0x20, 0x1f);
	rtl8225_write_phy_ofdm(dev, 0x21, 0x17);
	rtl8225_write_phy_ofdm(dev, 0x22, 0x16);
	rtl8225_write_phy_ofdm(dev, 0x23, 0x80);
	rtl8225_write_phy_ofdm(dev, 0x24, 0x46);
	rtl8225_write_phy_ofdm(dev, 0x25, 0x00);
	rtl8225_write_phy_ofdm(dev, 0x26, 0x90);
	rtl8225_write_phy_ofdm(dev, 0x27, 0x88);

	rtl8225_write_phy_ofdm(dev, 0x0b, rtl8225z2_gain_bg[4 * 3]);
	rtl8225_write_phy_ofdm(dev, 0x1b, rtl8225z2_gain_bg[4 * 3 + 1]);
	rtl8225_write_phy_ofdm(dev, 0x1d, rtl8225z2_gain_bg[4 * 3 + 2]);
	rtl8225_write_phy_ofdm(dev, 0x21, 0x37);

	rtl8225_write_phy_cck(dev, 0x00, 0x98);
	rtl8225_write_phy_cck(dev, 0x03, 0x20);
	rtl8225_write_phy_cck(dev, 0x04, 0x7e);
	rtl8225_write_phy_cck(dev, 0x05, 0x12);
	rtl8225_write_phy_cck(dev, 0x06, 0xfc);
	rtl8225_write_phy_cck(dev, 0x07, 0x78);
	rtl8225_write_phy_cck(dev, 0x08, 0x2e);
	rtl8225_write_phy_cck(dev, 0x10, 0x9b);
	rtl8225_write_phy_cck(dev, 0x11, 0x88);
	rtl8225_write_phy_cck(dev, 0x12, 0x47);
	rtl8225_write_phy_cck(dev, 0x13, 0xd0);
	rtl8225_write_phy_cck(dev, 0x19, 0x00);
	rtl8225_write_phy_cck(dev, 0x1a, 0xa0);
	rtl8225_write_phy_cck(dev, 0x1b, 0x08);
	rtl8225_write_phy_cck(dev, 0x40, 0x86);
	rtl8225_write_phy_cck(dev, 0x41, 0x8d);
	rtl8225_write_phy_cck(dev, 0x42, 0x15);
	rtl8225_write_phy_cck(dev, 0x43, 0x18);
	rtl8225_write_phy_cck(dev, 0x44, 0x36);
	rtl8225_write_phy_cck(dev, 0x45, 0x35);
	rtl8225_write_phy_cck(dev, 0x46, 0x2e);
	rtl8225_write_phy_cck(dev, 0x47, 0x25);
	rtl8225_write_phy_cck(dev, 0x48, 0x1c);
	rtl8225_write_phy_cck(dev, 0x49, 0x12);
	rtl8225_write_phy_cck(dev, 0x4a, 0x09);
	rtl8225_write_phy_cck(dev, 0x4b, 0x04);
	rtl8225_write_phy_cck(dev, 0x4c, 0x05);

	rtl818x_iowrite8(priv, (u8 *)0xFF5B, 0x0D); msleep(1);

	rtl8225z2_rf_set_tx_power(dev, 1);

	/* RX antenna default to A */
	rtl8225_write_phy_cck(dev, 0x10, 0x9b);			/* B: 0xDB */
	rtl8225_write_phy_ofdm(dev, 0x26, 0x90);		/* B: 0x10 */

	rtl818x_iowrite8(priv, &priv->map->TX_ANTENNA, 0x03);	/* B: 0x00 */
	msleep(1);
	rtl818x_iowrite32(priv, (__le32 *)0xFF94, 0x3dc00002);
}

__attribute__((used)) static void rtl8225z2_b_rf_init(struct ieee80211_hw *dev)
{
	struct rtl8187_priv *priv = dev->priv;
	int i;

	rtl8225_write(dev, 0x0, 0x0B7);
	rtl8225_write(dev, 0x1, 0xEE0);
	rtl8225_write(dev, 0x2, 0x44D);
	rtl8225_write(dev, 0x3, 0x441);
	rtl8225_write(dev, 0x4, 0x8C3);
	rtl8225_write(dev, 0x5, 0xC72);
	rtl8225_write(dev, 0x6, 0x0E6);
	rtl8225_write(dev, 0x7, 0x82A);
	rtl8225_write(dev, 0x8, 0x03F);
	rtl8225_write(dev, 0x9, 0x335);
	rtl8225_write(dev, 0xa, 0x9D4);
	rtl8225_write(dev, 0xb, 0x7BB);
	rtl8225_write(dev, 0xc, 0x850);
	rtl8225_write(dev, 0xd, 0xCDF);
	rtl8225_write(dev, 0xe, 0x02B);
	rtl8225_write(dev, 0xf, 0x114);

	rtl8225_write(dev, 0x0, 0x1B7);

	for (i = 0; i < ARRAY_SIZE(rtl8225z2_rxgain); i++) {
		rtl8225_write(dev, 0x1, i + 1);
		rtl8225_write(dev, 0x2, rtl8225z2_rxgain[i]);
	}

	rtl8225_write(dev, 0x3, 0x080);
	rtl8225_write(dev, 0x5, 0x004);
	rtl8225_write(dev, 0x0, 0x0B7);

	rtl8225_write(dev, 0x2, 0xC4D);

	rtl8225_write(dev, 0x2, 0x44D);
	rtl8225_write(dev, 0x0, 0x2BF);

	rtl818x_iowrite8(priv, &priv->map->TX_GAIN_CCK, 0x03);
	rtl818x_iowrite8(priv, &priv->map->TX_GAIN_OFDM, 0x07);
	rtl818x_iowrite8(priv, &priv->map->TX_ANTENNA, 0x03);

	rtl8225_write_phy_ofdm(dev, 0x80, 0x12);
	for (i = 0; i < ARRAY_SIZE(rtl8225z2_agc); i++) {
		rtl8225_write_phy_ofdm(dev, 0xF, rtl8225z2_agc[i]);
		rtl8225_write_phy_ofdm(dev, 0xE, 0x80 + i);
		rtl8225_write_phy_ofdm(dev, 0xE, 0);
	}
	rtl8225_write_phy_ofdm(dev, 0x80, 0x10);

	for (i = 0; i < ARRAY_SIZE(rtl8225z2_ofdm); i++)
		rtl8225_write_phy_ofdm(dev, i, rtl8225z2_ofdm[i]);

	rtl8225_write_phy_ofdm(dev, 0x97, 0x46);
	rtl8225_write_phy_ofdm(dev, 0xa4, 0xb6);
	rtl8225_write_phy_ofdm(dev, 0x85, 0xfc);
	rtl8225_write_phy_cck(dev, 0xc1, 0x88);
}

__attribute__((used)) static void rtl8225_rf_stop(struct ieee80211_hw *dev)
{
	rtl8225_write(dev, 0x4, 0x1f);
}

__attribute__((used)) static void rtl8225_rf_set_channel(struct ieee80211_hw *dev,
				   struct ieee80211_conf *conf)
{
	struct rtl8187_priv *priv = dev->priv;
	int chan =
		ieee80211_frequency_to_channel(conf->chandef.chan->center_freq);

	if (priv->rf->init == rtl8225_rf_init)
		rtl8225_rf_set_tx_power(dev, chan);
	else if (priv->rf->init == rtl8225z2_rf_init)
		rtl8225z2_rf_set_tx_power(dev, chan);
	else
		rtl8225z2_b_rf_set_tx_power(dev, chan);

	rtl8225_write(dev, 0x7, rtl8225_chan[chan - 1]);
	msleep(10);
}

const struct rtl818x_rf_ops * rtl8187_detect_rf(struct ieee80211_hw *dev)
{
	u16 reg8, reg9;
	struct rtl8187_priv *priv = dev->priv;

	if (!priv->is_rtl8187b) {
		rtl8225_write(dev, 0, 0x1B7);

		reg8 = rtl8225_read(dev, 8);
		reg9 = rtl8225_read(dev, 9);

		rtl8225_write(dev, 0, 0x0B7);

		if (reg8 != 0x588 || reg9 != 0x700)
			return &rtl8225_ops;

		return &rtl8225z2_ops;
	} else
		return &rtl8225z2_b_ops;
}

