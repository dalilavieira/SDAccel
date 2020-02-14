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
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_4__ {int (* write_posted ) (struct e1000_hw*,int*,int) ;int (* read_posted ) (struct e1000_hw*,int*,int) ;scalar_t__ (* read ) (struct e1000_hw*,int*,int) ;int /*<<< orphan*/  (* check_for_rst ) (struct e1000_hw*) ;int /*<<< orphan*/  init_params; } ;
struct e1000_mbx_info {int /*<<< orphan*/  timeout; TYPE_2__ ops; } ;
struct TYPE_3__ {int (* reset_hw ) (struct e1000_hw*) ;int (* init_hw ) (struct e1000_hw*) ;int (* check_for_link ) (struct e1000_hw*) ;int (* get_link_up_info ) (struct e1000_hw*,int*,int*) ;void (* update_mc_addr_list ) (struct e1000_hw*,int*,int,int,int) ;void (* rar_set ) (struct e1000_hw*,int*,int) ;int (* read_mac_addr ) (struct e1000_hw*) ;int (* set_uc_addr ) (struct e1000_hw*,int,int*) ;int (* set_vfta ) (struct e1000_hw*,int,int) ;int (* init_params ) (struct e1000_hw*) ;} ;
struct e1000_mac_info {int mta_reg_count; int rar_entry_count; int* perm_addr; int* addr; int get_link_status; TYPE_1__ ops; } ;
struct e1000_hw {struct e1000_mac_info mac; struct e1000_mbx_info mbx; } ;
typedef  int s32 ;
typedef  int /*<<< orphan*/  msgbuf ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  CTRL ; 
 int E1000_CTRL_RST ; 
 int E1000_ERR_MAC_INIT ; 
 int E1000_STATUS_FD ; 
 int E1000_STATUS_LU ; 
 int E1000_STATUS_SPEED_100 ; 
 int E1000_STATUS_SPEED_1000 ; 
 int E1000_SUCCESS ; 
 int E1000_VFMAILBOX_SIZE ; 
 int E1000_VF_INIT_TIMEOUT ; 
 int /*<<< orphan*/  E1000_VF_MBX_INIT_TIMEOUT ; 
 int E1000_VF_RESET ; 
 int E1000_VF_SET_LPE ; 
 int E1000_VF_SET_MAC_ADDR ; 
 int E1000_VF_SET_MULTICAST ; 
 int E1000_VF_SET_VLAN ; 
 int E1000_VT_MSGINFO_SHIFT ; 
 int E1000_VT_MSGTYPE_ACK ; 
 int E1000_VT_MSGTYPE_CTS ; 
 int E1000_VT_MSGTYPE_NACK ; 
 int ENOSPC ; 
 int /*<<< orphan*/  ETH_ALEN ; 
 int FULL_DUPLEX ; 
 int HALF_DUPLEX ; 
 int SPEED_10 ; 
 int SPEED_100 ; 
 int SPEED_1000 ; 
 int /*<<< orphan*/  STATUS ; 
static  int e1000_check_for_link_vf (struct e1000_hw*) ; 
static  int e1000_get_link_up_info_vf (struct e1000_hw*,int*,int*) ; 
static  int e1000_init_hw_vf (struct e1000_hw*) ; 
 int /*<<< orphan*/  e1000_init_mbx_params_vf ; 
static  void e1000_rar_set_vf (struct e1000_hw*,int*,int) ; 
static  int e1000_read_mac_addr_vf (struct e1000_hw*) ; 
static  int e1000_reset_hw_vf (struct e1000_hw*) ; 
static  int e1000_set_uc_addr_vf (struct e1000_hw*,int,int*) ; 
static  int e1000_set_vfta_vf (struct e1000_hw*,int,int) ; 
static  void e1000_update_mc_addr_list_vf (struct e1000_hw*,int*,int,int,int) ; 
 int er32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ew32 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct e1000_hw*) ; 
 int stub10 (struct e1000_hw*,int*,int) ; 
 int stub11 (struct e1000_hw*,int*,int) ; 
 int stub12 (struct e1000_hw*,int*,int) ; 
 int stub13 (struct e1000_hw*,int*,int) ; 
 int /*<<< orphan*/  stub14 (struct e1000_hw*) ; 
 scalar_t__ stub15 (struct e1000_hw*,int*,int) ; 
 int stub2 (struct e1000_hw*,int*,int) ; 
 int stub3 (struct e1000_hw*,int*,int) ; 
 int stub4 (struct e1000_hw*,int*,int) ; 
 int stub5 (struct e1000_hw*,int*,int) ; 
 int stub6 (struct e1000_hw*,int*,int) ; 
 int stub7 (struct e1000_hw*,int*,int) ; 
 int stub8 (struct e1000_hw*,int*,int) ; 
 int stub9 (struct e1000_hw*,int*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static s32 e1000_init_mac_params_vf(struct e1000_hw *hw)
{
	struct e1000_mac_info *mac = &hw->mac;

	/* VF's have no MTA Registers - PF feature only */
	mac->mta_reg_count = 128;
	/* VF's have no access to RAR entries  */
	mac->rar_entry_count = 1;

	/* Function pointers */
	/* reset */
	mac->ops.reset_hw = e1000_reset_hw_vf;
	/* hw initialization */
	mac->ops.init_hw = e1000_init_hw_vf;
	/* check for link */
	mac->ops.check_for_link = e1000_check_for_link_vf;
	/* link info */
	mac->ops.get_link_up_info = e1000_get_link_up_info_vf;
	/* multicast address update */
	mac->ops.update_mc_addr_list = e1000_update_mc_addr_list_vf;
	/* set mac address */
	mac->ops.rar_set = e1000_rar_set_vf;
	/* read mac address */
	mac->ops.read_mac_addr = e1000_read_mac_addr_vf;
	/* set mac filter */
	mac->ops.set_uc_addr = e1000_set_uc_addr_vf;
	/* set vlan filter table array */
	mac->ops.set_vfta = e1000_set_vfta_vf;

	return E1000_SUCCESS;
}

void e1000_init_function_pointers_vf(struct e1000_hw *hw)
{
	hw->mac.ops.init_params = e1000_init_mac_params_vf;
	hw->mbx.ops.init_params = e1000_init_mbx_params_vf;
}

__attribute__((used)) static s32 e1000_get_link_up_info_vf(struct e1000_hw *hw, u16 *speed,
				     u16 *duplex)
{
	s32 status;

	status = er32(STATUS);
	if (status & E1000_STATUS_SPEED_1000)
		*speed = SPEED_1000;
	else if (status & E1000_STATUS_SPEED_100)
		*speed = SPEED_100;
	else
		*speed = SPEED_10;

	if (status & E1000_STATUS_FD)
		*duplex = FULL_DUPLEX;
	else
		*duplex = HALF_DUPLEX;

	return E1000_SUCCESS;
}

__attribute__((used)) static s32 e1000_reset_hw_vf(struct e1000_hw *hw)
{
	struct e1000_mbx_info *mbx = &hw->mbx;
	u32 timeout = E1000_VF_INIT_TIMEOUT;
	u32 ret_val = -E1000_ERR_MAC_INIT;
	u32 msgbuf[3];
	u8 *addr = (u8 *)(&msgbuf[1]);
	u32 ctrl;

	/* assert VF queue/interrupt reset */
	ctrl = er32(CTRL);
	ew32(CTRL, ctrl | E1000_CTRL_RST);

	/* we cannot initialize while the RSTI / RSTD bits are asserted */
	while (!mbx->ops.check_for_rst(hw) && timeout) {
		timeout--;
		udelay(5);
	}

	if (timeout) {
		/* mailbox timeout can now become active */
		mbx->timeout = E1000_VF_MBX_INIT_TIMEOUT;

		/* notify PF of VF reset completion */
		msgbuf[0] = E1000_VF_RESET;
		mbx->ops.write_posted(hw, msgbuf, 1);

		mdelay(10);

		/* set our "perm_addr" based on info provided by PF */
		ret_val = mbx->ops.read_posted(hw, msgbuf, 3);
		if (!ret_val) {
			if (msgbuf[0] == (E1000_VF_RESET |
					  E1000_VT_MSGTYPE_ACK))
				memcpy(hw->mac.perm_addr, addr, ETH_ALEN);
			else
				ret_val = -E1000_ERR_MAC_INIT;
		}
	}

	return ret_val;
}

__attribute__((used)) static s32 e1000_init_hw_vf(struct e1000_hw *hw)
{
	/* attempt to set and restore our mac address */
	e1000_rar_set_vf(hw, hw->mac.addr, 0);

	return E1000_SUCCESS;
}

__attribute__((used)) static u32 e1000_hash_mc_addr_vf(struct e1000_hw *hw, u8 *mc_addr)
{
	u32 hash_value, hash_mask;
	u8 bit_shift = 0;

	/* Register count multiplied by bits per register */
	hash_mask = (hw->mac.mta_reg_count * 32) - 1;

	/* The bit_shift is the number of left-shifts
	 * where 0xFF would still fall within the hash mask.
	 */
	while (hash_mask >> bit_shift != 0xFF)
		bit_shift++;

	hash_value = hash_mask & (((mc_addr[4] >> (8 - bit_shift)) |
				  (((u16)mc_addr[5]) << bit_shift)));

	return hash_value;
}

__attribute__((used)) static void e1000_update_mc_addr_list_vf(struct e1000_hw *hw,
					 u8 *mc_addr_list, u32 mc_addr_count,
					 u32 rar_used_count, u32 rar_count)
{
	struct e1000_mbx_info *mbx = &hw->mbx;
	u32 msgbuf[E1000_VFMAILBOX_SIZE];
	u16 *hash_list = (u16 *)&msgbuf[1];
	u32 hash_value;
	u32 cnt, i;
	s32 ret_val;

	/* Each entry in the list uses 1 16 bit word.  We have 30
	 * 16 bit words available in our HW msg buffer (minus 1 for the
	 * msg type).  That's 30 hash values if we pack 'em right.  If
	 * there are more than 30 MC addresses to add then punt the
	 * extras for now and then add code to handle more than 30 later.
	 * It would be unusual for a server to request that many multi-cast
	 * addresses except for in large enterprise network environments.
	 */

	cnt = (mc_addr_count > 30) ? 30 : mc_addr_count;
	msgbuf[0] = E1000_VF_SET_MULTICAST;
	msgbuf[0] |= cnt << E1000_VT_MSGINFO_SHIFT;

	for (i = 0; i < cnt; i++) {
		hash_value = e1000_hash_mc_addr_vf(hw, mc_addr_list);
		hash_list[i] = hash_value & 0x0FFFF;
		mc_addr_list += ETH_ALEN;
	}

	ret_val = mbx->ops.write_posted(hw, msgbuf, E1000_VFMAILBOX_SIZE);
	if (!ret_val)
		mbx->ops.read_posted(hw, msgbuf, 1);
}

__attribute__((used)) static s32 e1000_set_vfta_vf(struct e1000_hw *hw, u16 vid, bool set)
{
	struct e1000_mbx_info *mbx = &hw->mbx;
	u32 msgbuf[2];
	s32 err;

	msgbuf[0] = E1000_VF_SET_VLAN;
	msgbuf[1] = vid;
	/* Setting the 8 bit field MSG INFO to true indicates "add" */
	if (set)
		msgbuf[0] |= BIT(E1000_VT_MSGINFO_SHIFT);

	mbx->ops.write_posted(hw, msgbuf, 2);

	err = mbx->ops.read_posted(hw, msgbuf, 2);

	msgbuf[0] &= ~E1000_VT_MSGTYPE_CTS;

	/* if nacked the vlan was rejected */
	if (!err && (msgbuf[0] == (E1000_VF_SET_VLAN | E1000_VT_MSGTYPE_NACK)))
		err = -E1000_ERR_MAC_INIT;

	return err;
}

void e1000_rlpml_set_vf(struct e1000_hw *hw, u16 max_size)
{
	struct e1000_mbx_info *mbx = &hw->mbx;
	u32 msgbuf[2];
	s32 ret_val;

	msgbuf[0] = E1000_VF_SET_LPE;
	msgbuf[1] = max_size;

	ret_val = mbx->ops.write_posted(hw, msgbuf, 2);
	if (!ret_val)
		mbx->ops.read_posted(hw, msgbuf, 1);
}

__attribute__((used)) static void e1000_rar_set_vf(struct e1000_hw *hw, u8 *addr, u32 index)
{
	struct e1000_mbx_info *mbx = &hw->mbx;
	u32 msgbuf[3];
	u8 *msg_addr = (u8 *)(&msgbuf[1]);
	s32 ret_val;

	memset(msgbuf, 0, 12);
	msgbuf[0] = E1000_VF_SET_MAC_ADDR;
	memcpy(msg_addr, addr, ETH_ALEN);
	ret_val = mbx->ops.write_posted(hw, msgbuf, 3);

	if (!ret_val)
		ret_val = mbx->ops.read_posted(hw, msgbuf, 3);

	msgbuf[0] &= ~E1000_VT_MSGTYPE_CTS;

	/* if nacked the address was rejected, use "perm_addr" */
	if (!ret_val &&
	    (msgbuf[0] == (E1000_VF_SET_MAC_ADDR | E1000_VT_MSGTYPE_NACK)))
		e1000_read_mac_addr_vf(hw);
}

__attribute__((used)) static s32 e1000_read_mac_addr_vf(struct e1000_hw *hw)
{
	memcpy(hw->mac.addr, hw->mac.perm_addr, ETH_ALEN);

	return E1000_SUCCESS;
}

__attribute__((used)) static s32 e1000_set_uc_addr_vf(struct e1000_hw *hw, u32 sub_cmd, u8 *addr)
{
	struct e1000_mbx_info *mbx = &hw->mbx;
	u32 msgbuf[3], msgbuf_chk;
	u8 *msg_addr = (u8 *)(&msgbuf[1]);
	s32 ret_val;

	memset(msgbuf, 0, sizeof(msgbuf));
	msgbuf[0] |= sub_cmd;
	msgbuf[0] |= E1000_VF_SET_MAC_ADDR;
	msgbuf_chk = msgbuf[0];

	if (addr)
		memcpy(msg_addr, addr, ETH_ALEN);

	ret_val = mbx->ops.write_posted(hw, msgbuf, 3);

	if (!ret_val)
		ret_val = mbx->ops.read_posted(hw, msgbuf, 3);

	msgbuf[0] &= ~E1000_VT_MSGTYPE_CTS;

	if (!ret_val) {
		msgbuf[0] &= ~E1000_VT_MSGTYPE_CTS;

		if (msgbuf[0] == (msgbuf_chk | E1000_VT_MSGTYPE_NACK))
			return -ENOSPC;
	}

	return ret_val;
}

__attribute__((used)) static s32 e1000_check_for_link_vf(struct e1000_hw *hw)
{
	struct e1000_mbx_info *mbx = &hw->mbx;
	struct e1000_mac_info *mac = &hw->mac;
	s32 ret_val = E1000_SUCCESS;
	u32 in_msg = 0;

	/* We only want to run this if there has been a rst asserted.
	 * in this case that could mean a link change, device reset,
	 * or a virtual function reset
	 */

	/* If we were hit with a reset or timeout drop the link */
	if (!mbx->ops.check_for_rst(hw) || !mbx->timeout)
		mac->get_link_status = true;

	if (!mac->get_link_status)
		goto out;

	/* if link status is down no point in checking to see if PF is up */
	if (!(er32(STATUS) & E1000_STATUS_LU))
		goto out;

	/* if the read failed it could just be a mailbox collision, best wait
	 * until we are called again and don't report an error
	 */
	if (mbx->ops.read(hw, &in_msg, 1))
		goto out;

	/* if incoming message isn't clear to send we are waiting on response */
	if (!(in_msg & E1000_VT_MSGTYPE_CTS)) {
		/* msg is not CTS and is NACK we must have lost CTS status */
		if (in_msg & E1000_VT_MSGTYPE_NACK)
			ret_val = -E1000_ERR_MAC_INIT;
		goto out;
	}

	/* the PF is talking, if we timed out in the past we reinit */
	if (!mbx->timeout) {
		ret_val = -E1000_ERR_MAC_INIT;
		goto out;
	}

	/* if we passed all the tests above then the link is up and we no
	 * longer need to check for link
	 */
	mac->get_link_status = false;

out:
	return ret_val;
}

