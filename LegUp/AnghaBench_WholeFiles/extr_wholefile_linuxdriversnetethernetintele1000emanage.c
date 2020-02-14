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
typedef  scalar_t__ u8 ;
typedef  size_t u32 ;
typedef  int u16 ;
struct TYPE_7__ {scalar_t__ (* read_mac_addr ) (struct e1000_hw*) ;int /*<<< orphan*/  (* check_mng_mode ) (struct e1000_hw*) ;} ;
struct TYPE_8__ {int tx_pkt_filtering; scalar_t__ type; scalar_t__ has_fwsm; TYPE_1__ ops; int /*<<< orphan*/  arc_subsystem_valid; } ;
struct e1000_host_mng_dhcp_cookie {scalar_t__ checksum; scalar_t__ signature; int status; } ;
struct TYPE_11__ {scalar_t__ (* reset ) (struct e1000_hw*) ;scalar_t__ (* read_reg ) (struct e1000_hw*,size_t,int*) ;scalar_t__ (* read_reg_locked ) (struct e1000_hw*,size_t,int*) ;scalar_t__ (* write_reg ) (struct e1000_hw*,size_t,int) ;scalar_t__ (* write_reg_locked ) (struct e1000_hw*,size_t,int) ;scalar_t__ (* get_info ) (struct e1000_hw*) ;} ;
struct TYPE_12__ {TYPE_5__ ops; } ;
struct TYPE_9__ {scalar_t__ (* validate ) (struct e1000_hw*) ;scalar_t__ (* update ) (struct e1000_hw*) ;scalar_t__ (* read ) (struct e1000_hw*,int,int,int*) ;scalar_t__ (* write ) (struct e1000_hw*,int,int,int*) ;} ;
struct TYPE_10__ {TYPE_3__ ops; } ;
struct e1000_hw {TYPE_2__ mac; struct e1000_host_mng_dhcp_cookie mng_cookie; scalar_t__ hw_addr; TYPE_6__ phy; TYPE_4__ nvm; } ;
struct e1000_host_mng_command_header {scalar_t__ checksum; int command_length; scalar_t__ reserved2; scalar_t__ reserved1; int /*<<< orphan*/  command_id; } ;
typedef  scalar_t__ s32 ;
typedef  int /*<<< orphan*/  hdr ;

/* Variables and functions */
 scalar_t__ E1000_ERR_HOST_INTERFACE_COMMAND ; 
 scalar_t__ E1000_ERR_PARAM ; 
 size_t E1000_FACTPS_MNGCG ; 
 size_t E1000_FWSM_MODE_MASK ; 
 size_t E1000_FWSM_MODE_SHIFT ; 
 size_t E1000_HICR_C ; 
 size_t E1000_HICR_EN ; 
 int E1000_HI_MAX_MNG_DATA_LENGTH ; 
 int /*<<< orphan*/  E1000_HOST_IF ; 
 scalar_t__ E1000_IAMT_SIGNATURE ; 
 size_t E1000_MANC_ASF_EN ; 
 size_t E1000_MANC_RCV_TCO_EN ; 
 size_t E1000_MANC_SMBUS_EN ; 
 scalar_t__ E1000_MNG_DHCP_COMMAND_TIMEOUT ; 
 int E1000_MNG_DHCP_COOKIE_LENGTH ; 
 int E1000_MNG_DHCP_COOKIE_OFFSET ; 
 int E1000_MNG_DHCP_COOKIE_STATUS_PARSING ; 
 int /*<<< orphan*/  E1000_MNG_DHCP_TX_PAYLOAD_CMD ; 
 size_t E1000_MNG_IAMT_MODE ; 
 int E1000_NVM_INIT_CTRL2_MNGM ; 
 size_t E1000_READ_REG_ARRAY (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  E1000_WRITE_REG_ARRAY (struct e1000_hw*,int /*<<< orphan*/ ,int,size_t) ; 
 int /*<<< orphan*/  FACTPS ; 
 int /*<<< orphan*/  FWSM ; 
 int /*<<< orphan*/  HICR ; 
 int /*<<< orphan*/  MANC ; 
 int NVM_INIT_CONTROL2_REG ; 
 scalar_t__ e1000_82574 ; 
 scalar_t__ e1000_82583 ; 
 size_t e1000_mng_mode_pt ; 
 scalar_t__ e1000_read_mac_addr_generic (struct e1000_hw*) ; 
 int /*<<< orphan*/  e1e_flush () ; 
 int /*<<< orphan*/  e_dbg (char*) ; 
 size_t er32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ew32 (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 size_t readl (scalar_t__) ; 
 scalar_t__ stub1 (struct e1000_hw*) ; 
 scalar_t__ stub10 (struct e1000_hw*,int,int,int*) ; 
 scalar_t__ stub11 (struct e1000_hw*) ; 
 int /*<<< orphan*/  stub12 (struct e1000_hw*) ; 
 scalar_t__ stub2 (struct e1000_hw*,size_t,int*) ; 
 scalar_t__ stub3 (struct e1000_hw*,size_t,int*) ; 
 scalar_t__ stub4 (struct e1000_hw*,size_t,int) ; 
 scalar_t__ stub5 (struct e1000_hw*,size_t,int) ; 
 scalar_t__ stub6 (struct e1000_hw*) ; 
 scalar_t__ stub7 (struct e1000_hw*) ; 
 scalar_t__ stub8 (struct e1000_hw*) ; 
 scalar_t__ stub9 (struct e1000_hw*,int,int,int*) ; 

__attribute__((used)) static inline s32 e1000_phy_hw_reset(struct e1000_hw *hw)
{
	return hw->phy.ops.reset(hw);
}

__attribute__((used)) static inline s32 e1e_rphy(struct e1000_hw *hw, u32 offset, u16 *data)
{
	return hw->phy.ops.read_reg(hw, offset, data);
}

__attribute__((used)) static inline s32 e1e_rphy_locked(struct e1000_hw *hw, u32 offset, u16 *data)
{
	return hw->phy.ops.read_reg_locked(hw, offset, data);
}

__attribute__((used)) static inline s32 e1e_wphy(struct e1000_hw *hw, u32 offset, u16 data)
{
	return hw->phy.ops.write_reg(hw, offset, data);
}

__attribute__((used)) static inline s32 e1e_wphy_locked(struct e1000_hw *hw, u32 offset, u16 data)
{
	return hw->phy.ops.write_reg_locked(hw, offset, data);
}

__attribute__((used)) static inline s32 e1000e_read_mac_addr(struct e1000_hw *hw)
{
	if (hw->mac.ops.read_mac_addr)
		return hw->mac.ops.read_mac_addr(hw);

	return e1000_read_mac_addr_generic(hw);
}

__attribute__((used)) static inline s32 e1000_validate_nvm_checksum(struct e1000_hw *hw)
{
	return hw->nvm.ops.validate(hw);
}

__attribute__((used)) static inline s32 e1000e_update_nvm_checksum(struct e1000_hw *hw)
{
	return hw->nvm.ops.update(hw);
}

__attribute__((used)) static inline s32 e1000_read_nvm(struct e1000_hw *hw, u16 offset, u16 words,
				 u16 *data)
{
	return hw->nvm.ops.read(hw, offset, words, data);
}

__attribute__((used)) static inline s32 e1000_write_nvm(struct e1000_hw *hw, u16 offset, u16 words,
				  u16 *data)
{
	return hw->nvm.ops.write(hw, offset, words, data);
}

__attribute__((used)) static inline s32 e1000_get_phy_info(struct e1000_hw *hw)
{
	return hw->phy.ops.get_info(hw);
}

__attribute__((used)) static inline u32 __er32(struct e1000_hw *hw, unsigned long reg)
{
	return readl(hw->hw_addr + reg);
}

__attribute__((used)) static u8 e1000_calculate_checksum(u8 *buffer, u32 length)
{
	u32 i;
	u8 sum = 0;

	if (!buffer)
		return 0;

	for (i = 0; i < length; i++)
		sum += buffer[i];

	return (u8)(0 - sum);
}

__attribute__((used)) static s32 e1000_mng_enable_host_if(struct e1000_hw *hw)
{
	u32 hicr;
	u8 i;

	if (!hw->mac.arc_subsystem_valid) {
		e_dbg("ARC subsystem not valid.\n");
		return -E1000_ERR_HOST_INTERFACE_COMMAND;
	}

	/* Check that the host interface is enabled. */
	hicr = er32(HICR);
	if (!(hicr & E1000_HICR_EN)) {
		e_dbg("E1000_HOST_EN bit disabled.\n");
		return -E1000_ERR_HOST_INTERFACE_COMMAND;
	}
	/* check the previous command is completed */
	for (i = 0; i < E1000_MNG_DHCP_COMMAND_TIMEOUT; i++) {
		hicr = er32(HICR);
		if (!(hicr & E1000_HICR_C))
			break;
		mdelay(1);
	}

	if (i == E1000_MNG_DHCP_COMMAND_TIMEOUT) {
		e_dbg("Previous command timeout failed.\n");
		return -E1000_ERR_HOST_INTERFACE_COMMAND;
	}

	return 0;
}

bool e1000e_check_mng_mode_generic(struct e1000_hw *hw)
{
	u32 fwsm = er32(FWSM);

	return (fwsm & E1000_FWSM_MODE_MASK) ==
	    (E1000_MNG_IAMT_MODE << E1000_FWSM_MODE_SHIFT);
}

bool e1000e_enable_tx_pkt_filtering(struct e1000_hw *hw)
{
	struct e1000_host_mng_dhcp_cookie *hdr = &hw->mng_cookie;
	u32 *buffer = (u32 *)&hw->mng_cookie;
	u32 offset;
	s32 ret_val, hdr_csum, csum;
	u8 i, len;

	hw->mac.tx_pkt_filtering = true;

	/* No manageability, no filtering */
	if (!hw->mac.ops.check_mng_mode(hw)) {
		hw->mac.tx_pkt_filtering = false;
		return hw->mac.tx_pkt_filtering;
	}

	/* If we can't read from the host interface for whatever
	 * reason, disable filtering.
	 */
	ret_val = e1000_mng_enable_host_if(hw);
	if (ret_val) {
		hw->mac.tx_pkt_filtering = false;
		return hw->mac.tx_pkt_filtering;
	}

	/* Read in the header.  Length and offset are in dwords. */
	len = E1000_MNG_DHCP_COOKIE_LENGTH >> 2;
	offset = E1000_MNG_DHCP_COOKIE_OFFSET >> 2;
	for (i = 0; i < len; i++)
		*(buffer + i) = E1000_READ_REG_ARRAY(hw, E1000_HOST_IF,
						     offset + i);
	hdr_csum = hdr->checksum;
	hdr->checksum = 0;
	csum = e1000_calculate_checksum((u8 *)hdr,
					E1000_MNG_DHCP_COOKIE_LENGTH);
	/* If either the checksums or signature don't match, then
	 * the cookie area isn't considered valid, in which case we
	 * take the safe route of assuming Tx filtering is enabled.
	 */
	if ((hdr_csum != csum) || (hdr->signature != E1000_IAMT_SIGNATURE)) {
		hw->mac.tx_pkt_filtering = true;
		return hw->mac.tx_pkt_filtering;
	}

	/* Cookie area is valid, make the final check for filtering. */
	if (!(hdr->status & E1000_MNG_DHCP_COOKIE_STATUS_PARSING))
		hw->mac.tx_pkt_filtering = false;

	return hw->mac.tx_pkt_filtering;
}

__attribute__((used)) static s32 e1000_mng_write_cmd_header(struct e1000_hw *hw,
				      struct e1000_host_mng_command_header *hdr)
{
	u16 i, length = sizeof(struct e1000_host_mng_command_header);

	/* Write the whole command header structure with new checksum. */

	hdr->checksum = e1000_calculate_checksum((u8 *)hdr, length);

	length >>= 2;
	/* Write the relevant command block into the ram area. */
	for (i = 0; i < length; i++) {
		E1000_WRITE_REG_ARRAY(hw, E1000_HOST_IF, i, *((u32 *)hdr + i));
		e1e_flush();
	}

	return 0;
}

__attribute__((used)) static s32 e1000_mng_host_if_write(struct e1000_hw *hw, u8 *buffer,
				   u16 length, u16 offset, u8 *sum)
{
	u8 *tmp;
	u8 *bufptr = buffer;
	u32 data = 0;
	u16 remaining, i, j, prev_bytes;

	/* sum = only sum of the data and it is not checksum */

	if (length == 0 || offset + length > E1000_HI_MAX_MNG_DATA_LENGTH)
		return -E1000_ERR_PARAM;

	tmp = (u8 *)&data;
	prev_bytes = offset & 0x3;
	offset >>= 2;

	if (prev_bytes) {
		data = E1000_READ_REG_ARRAY(hw, E1000_HOST_IF, offset);
		for (j = prev_bytes; j < sizeof(u32); j++) {
			*(tmp + j) = *bufptr++;
			*sum += *(tmp + j);
		}
		E1000_WRITE_REG_ARRAY(hw, E1000_HOST_IF, offset, data);
		length -= j - prev_bytes;
		offset++;
	}

	remaining = length & 0x3;
	length -= remaining;

	/* Calculate length in DWORDs */
	length >>= 2;

	/* The device driver writes the relevant command block into the
	 * ram area.
	 */
	for (i = 0; i < length; i++) {
		for (j = 0; j < sizeof(u32); j++) {
			*(tmp + j) = *bufptr++;
			*sum += *(tmp + j);
		}

		E1000_WRITE_REG_ARRAY(hw, E1000_HOST_IF, offset + i, data);
	}
	if (remaining) {
		for (j = 0; j < sizeof(u32); j++) {
			if (j < remaining)
				*(tmp + j) = *bufptr++;
			else
				*(tmp + j) = 0;

			*sum += *(tmp + j);
		}
		E1000_WRITE_REG_ARRAY(hw, E1000_HOST_IF, offset + i, data);
	}

	return 0;
}

s32 e1000e_mng_write_dhcp_info(struct e1000_hw *hw, u8 *buffer, u16 length)
{
	struct e1000_host_mng_command_header hdr;
	s32 ret_val;
	u32 hicr;

	hdr.command_id = E1000_MNG_DHCP_TX_PAYLOAD_CMD;
	hdr.command_length = length;
	hdr.reserved1 = 0;
	hdr.reserved2 = 0;
	hdr.checksum = 0;

	/* Enable the host interface */
	ret_val = e1000_mng_enable_host_if(hw);
	if (ret_val)
		return ret_val;

	/* Populate the host interface with the contents of "buffer". */
	ret_val = e1000_mng_host_if_write(hw, buffer, length,
					  sizeof(hdr), &(hdr.checksum));
	if (ret_val)
		return ret_val;

	/* Write the manageability command header */
	ret_val = e1000_mng_write_cmd_header(hw, &hdr);
	if (ret_val)
		return ret_val;

	/* Tell the ARC a new command is pending. */
	hicr = er32(HICR);
	ew32(HICR, hicr | E1000_HICR_C);

	return 0;
}

bool e1000e_enable_mng_pass_thru(struct e1000_hw *hw)
{
	u32 manc;
	u32 fwsm, factps;

	manc = er32(MANC);

	if (!(manc & E1000_MANC_RCV_TCO_EN))
		return false;

	if (hw->mac.has_fwsm) {
		fwsm = er32(FWSM);
		factps = er32(FACTPS);

		if (!(factps & E1000_FACTPS_MNGCG) &&
		    ((fwsm & E1000_FWSM_MODE_MASK) ==
		     (e1000_mng_mode_pt << E1000_FWSM_MODE_SHIFT)))
			return true;
	} else if ((hw->mac.type == e1000_82574) ||
		   (hw->mac.type == e1000_82583)) {
		u16 data;
		s32 ret_val;

		factps = er32(FACTPS);
		ret_val = e1000_read_nvm(hw, NVM_INIT_CONTROL2_REG, 1, &data);
		if (ret_val)
			return false;

		if (!(factps & E1000_FACTPS_MNGCG) &&
		    ((data & E1000_NVM_INIT_CTRL2_MNGM) ==
		     (e1000_mng_mode_pt << 13)))
			return true;
	} else if ((manc & E1000_MANC_SMBUS_EN) &&
		   !(manc & E1000_MANC_ASF_EN)) {
		return true;
	}

	return false;
}

