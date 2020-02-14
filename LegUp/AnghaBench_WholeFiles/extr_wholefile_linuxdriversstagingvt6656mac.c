#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct vnt_private {TYPE_3__* usb; } ;
struct TYPE_4__ {int /*<<< orphan*/  addr; int /*<<< orphan*/  key_ctl; } ;
struct TYPE_5__ {int /*<<< orphan*/ * swap; TYPE_1__ write; } ;
struct vnt_mac_set_key {int /*<<< orphan*/  key; TYPE_2__ u; } ;
typedef  int /*<<< orphan*/  le_mc ;
typedef  int /*<<< orphan*/  entry_idx ;
typedef  int /*<<< orphan*/  __le64 ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int ETH_ALEN ; 
 int EnCFG_BBType_MASK ; 
 int EnCFG_BarkerPream ; 
 int EnCFG_ProtectMd ; 
 int MAC_REG_BI ; 
 int MAC_REG_BSSID0 ; 
 int MAC_REG_ENCFG0 ; 
 int MAC_REG_ENCFG2 ; 
 int MAC_REG_MAR0 ; 
 int MAC_REG_PAPEDELAY ; 
 int MESSAGE_REQUEST_MACREG ; 
 int /*<<< orphan*/  MESSAGE_TYPE_CLRKEYENTRY ; 
 int /*<<< orphan*/  MESSAGE_TYPE_MACSHUTDOWN ; 
 int /*<<< orphan*/  MESSAGE_TYPE_SETKEY ; 
 int /*<<< orphan*/  MESSAGE_TYPE_WRITE ; 
 int /*<<< orphan*/  MESSAGE_TYPE_WRITE_MASK ; 
 int MISCFIFO_KEYENTRYSIZE ; 
 int MISCFIFO_KEYETRY0 ; 
 int /*<<< orphan*/  WLAN_KEY_LEN_CCMP ; 
 int /*<<< orphan*/  cpu_to_le16 (int) ; 
 int /*<<< orphan*/  cpu_to_le64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int,int*) ; 
 int /*<<< orphan*/  ether_addr_copy (int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  swap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vnt_control_out (struct vnt_private*,int /*<<< orphan*/ ,int,int,int,int*) ; 

void vnt_mac_set_filter(struct vnt_private *priv, u64 mc_filter)
{
	__le64 le_mc = cpu_to_le64(mc_filter);

	vnt_control_out(priv, MESSAGE_TYPE_WRITE, MAC_REG_MAR0,
			MESSAGE_REQUEST_MACREG, sizeof(le_mc), (u8 *)&le_mc);
}

void vnt_mac_shutdown(struct vnt_private *priv)
{
	vnt_control_out(priv, MESSAGE_TYPE_MACSHUTDOWN, 0, 0, 0, NULL);
}

void vnt_mac_set_bb_type(struct vnt_private *priv, u8 type)
{
	u8 data[2];

	data[0] = type;
	data[1] = EnCFG_BBType_MASK;

	vnt_control_out(priv, MESSAGE_TYPE_WRITE_MASK, MAC_REG_ENCFG0,
			MESSAGE_REQUEST_MACREG,	ARRAY_SIZE(data), data);
}

void vnt_mac_disable_keyentry(struct vnt_private *priv, u8 entry_idx)
{
	vnt_control_out(priv, MESSAGE_TYPE_CLRKEYENTRY, 0, 0,
			sizeof(entry_idx), &entry_idx);
}

void vnt_mac_set_keyentry(struct vnt_private *priv, u16 key_ctl, u32 entry_idx,
			  u32 key_idx, u8 *addr, u8 *key)
{
	struct vnt_mac_set_key set_key;
	u16 offset;

	offset = MISCFIFO_KEYETRY0;
	offset += entry_idx * MISCFIFO_KEYENTRYSIZE;

	set_key.u.write.key_ctl = cpu_to_le16(key_ctl);
	ether_addr_copy(set_key.u.write.addr, addr);

	/* swap over swap[0] and swap[1] to get correct write order */
	swap(set_key.u.swap[0], set_key.u.swap[1]);

	memcpy(set_key.key, key, WLAN_KEY_LEN_CCMP);

	dev_dbg(&priv->usb->dev, "offset %d key ctl %d set key %24ph\n",
		offset, key_ctl, (u8 *)&set_key);

	vnt_control_out(priv, MESSAGE_TYPE_SETKEY, offset,
			(u16)key_idx, sizeof(struct vnt_mac_set_key),
			(u8 *)&set_key);
}

void vnt_mac_reg_bits_off(struct vnt_private *priv, u8 reg_ofs, u8 bits)
{
	u8 data[2];

	data[0] = 0;
	data[1] = bits;

	vnt_control_out(priv, MESSAGE_TYPE_WRITE_MASK,
			reg_ofs, MESSAGE_REQUEST_MACREG, ARRAY_SIZE(data),
			data);
}

void vnt_mac_reg_bits_on(struct vnt_private *priv, u8 reg_ofs, u8 bits)
{
	u8 data[2];

	data[0] = bits;
	data[1] = bits;

	vnt_control_out(priv, MESSAGE_TYPE_WRITE_MASK, reg_ofs,
			MESSAGE_REQUEST_MACREG, ARRAY_SIZE(data), data);
}

void vnt_mac_write_word(struct vnt_private *priv, u8 reg_ofs, u16 word)
{
	u8 data[2];

	data[0] = (u8)(word & 0xff);
	data[1] = (u8)(word >> 8);

	vnt_control_out(priv, MESSAGE_TYPE_WRITE, reg_ofs,
			MESSAGE_REQUEST_MACREG, ARRAY_SIZE(data), data);
}

void vnt_mac_set_bssid_addr(struct vnt_private *priv, u8 *addr)
{
	vnt_control_out(priv, MESSAGE_TYPE_WRITE, MAC_REG_BSSID0,
			MESSAGE_REQUEST_MACREG, ETH_ALEN, addr);
}

void vnt_mac_enable_protect_mode(struct vnt_private *priv)
{
	u8 data[2];

	data[0] = EnCFG_ProtectMd;
	data[1] = EnCFG_ProtectMd;

	vnt_control_out(priv, MESSAGE_TYPE_WRITE_MASK, MAC_REG_ENCFG0,
			MESSAGE_REQUEST_MACREG, ARRAY_SIZE(data), data);
}

void vnt_mac_disable_protect_mode(struct vnt_private *priv)
{
	u8 data[2];

	data[0] = 0;
	data[1] = EnCFG_ProtectMd;

	vnt_control_out(priv, MESSAGE_TYPE_WRITE_MASK, MAC_REG_ENCFG0,
			MESSAGE_REQUEST_MACREG, ARRAY_SIZE(data), data);
}

void vnt_mac_enable_barker_preamble_mode(struct vnt_private *priv)
{
	u8 data[2];

	data[0] = EnCFG_BarkerPream;
	data[1] = EnCFG_BarkerPream;

	vnt_control_out(priv, MESSAGE_TYPE_WRITE_MASK, MAC_REG_ENCFG2,
			MESSAGE_REQUEST_MACREG, ARRAY_SIZE(data), data);
}

void vnt_mac_disable_barker_preamble_mode(struct vnt_private *priv)
{
	u8 data[2];

	data[0] = 0;
	data[1] = EnCFG_BarkerPream;

	vnt_control_out(priv, MESSAGE_TYPE_WRITE_MASK, MAC_REG_ENCFG2,
			MESSAGE_REQUEST_MACREG, ARRAY_SIZE(data), data);
}

void vnt_mac_set_beacon_interval(struct vnt_private *priv, u16 interval)
{
	u8 data[2];

	data[0] = (u8)(interval & 0xff);
	data[1] = (u8)(interval >> 8);

	vnt_control_out(priv, MESSAGE_TYPE_WRITE, MAC_REG_BI,
			MESSAGE_REQUEST_MACREG, ARRAY_SIZE(data), data);
}

void vnt_mac_set_led(struct vnt_private *priv, u8 state, u8 led)
{
	u8 data[2];

	data[0] = led;
	data[1] = state;

	vnt_control_out(priv, MESSAGE_TYPE_WRITE_MASK, MAC_REG_PAPEDELAY,
			MESSAGE_REQUEST_MACREG, ARRAY_SIZE(data), data);
}

