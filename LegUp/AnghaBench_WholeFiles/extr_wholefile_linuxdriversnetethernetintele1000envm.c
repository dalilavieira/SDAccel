#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_9__ {int /*<<< orphan*/  (* release ) (struct e1000_hw*) ;scalar_t__ (* acquire ) (struct e1000_hw*) ;scalar_t__ (* write ) (struct e1000_hw*,int,int,int*) ;scalar_t__ (* read ) (struct e1000_hw*,int,int,int*) ;scalar_t__ (* update ) (struct e1000_hw*) ;scalar_t__ (* validate ) (struct e1000_hw*) ;} ;
struct e1000_nvm_info {int delay_usec; scalar_t__ type; int opcode_bits; int word_size; int address_bits; int page_size; TYPE_4__ ops; } ;
struct TYPE_6__ {scalar_t__ (* read_mac_addr ) (struct e1000_hw*) ;} ;
struct TYPE_10__ {int* perm_addr; int* addr; TYPE_1__ ops; } ;
struct TYPE_7__ {scalar_t__ (* get_info ) (struct e1000_hw*) ;scalar_t__ (* write_reg_locked ) (struct e1000_hw*,int,int) ;scalar_t__ (* write_reg ) (struct e1000_hw*,int,int) ;scalar_t__ (* read_reg_locked ) (struct e1000_hw*,int,int*) ;scalar_t__ (* read_reg ) (struct e1000_hw*,int,int*) ;scalar_t__ (* reset ) (struct e1000_hw*) ;} ;
struct TYPE_8__ {TYPE_2__ ops; } ;
struct e1000_hw {TYPE_5__ mac; struct e1000_nvm_info nvm; scalar_t__ hw_addr; TYPE_3__ phy; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  CTRL_EXT ; 
 int E1000_CTRL_EXT_EE_RST ; 
 int E1000_EECD_CS ; 
 int E1000_EECD_DI ; 
 int E1000_EECD_DO ; 
 int E1000_EECD_GNT ; 
 int E1000_EECD_REQ ; 
 int E1000_EECD_SK ; 
 scalar_t__ E1000_ERR_INVALID_ARGUMENT ; 
 scalar_t__ E1000_ERR_NO_SPACE ; 
 scalar_t__ E1000_ERR_NVM ; 
 scalar_t__ E1000_ERR_NVM_PBA_SECTION ; 
 scalar_t__ E1000_NVM_GRANT_ATTEMPTS ; 
 int E1000_NVM_POLL_READ ; 
 int E1000_NVM_RW_ADDR_SHIFT ; 
 int E1000_NVM_RW_REG_DATA ; 
 int E1000_NVM_RW_REG_DONE ; 
 int E1000_NVM_RW_REG_START ; 
 int E1000_PBANUM_LENGTH ; 
 int E1000_RAH_MAC_ADDR_LEN ; 
 int E1000_RAL_MAC_ADDR_LEN ; 
 int /*<<< orphan*/  EECD ; 
 int /*<<< orphan*/  EERD ; 
 int /*<<< orphan*/  EEWR ; 
 int ETH_ALEN ; 
 int NVM_A8_OPCODE_SPI ; 
 int NVM_CHECKSUM_REG ; 
 int NVM_MAX_RETRY_SPI ; 
 int NVM_PBA_OFFSET_0 ; 
 int NVM_PBA_OFFSET_1 ; 
 int NVM_PBA_PTR_GUARD ; 
 int NVM_RDSR_OPCODE_SPI ; 
 int NVM_STATUS_RDY_SPI ; 
 scalar_t__ NVM_SUM ; 
 int NVM_WREN_OPCODE_SPI ; 
 int NVM_WRITE_OPCODE_SPI ; 
 int /*<<< orphan*/  RAH (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RAL (int /*<<< orphan*/ ) ; 
 scalar_t__ e1000_nvm_eeprom_spi ; 
 scalar_t__ e1000_read_mac_addr_generic (struct e1000_hw*) ; 
 int /*<<< orphan*/  e1e_flush () ; 
 int /*<<< orphan*/  e_dbg (char*,...) ; 
 int er32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ew32 (int /*<<< orphan*/ ,int) ; 
 int readl (scalar_t__) ; 
 scalar_t__ stub1 (struct e1000_hw*) ; 
 scalar_t__ stub10 (struct e1000_hw*,int,int,int*) ; 
 scalar_t__ stub11 (struct e1000_hw*) ; 
 scalar_t__ stub12 (struct e1000_hw*) ; 
 int /*<<< orphan*/  stub13 (struct e1000_hw*) ; 
 int /*<<< orphan*/  stub14 (struct e1000_hw*) ; 
 scalar_t__ stub2 (struct e1000_hw*,int,int*) ; 
 scalar_t__ stub3 (struct e1000_hw*,int,int*) ; 
 scalar_t__ stub4 (struct e1000_hw*,int,int) ; 
 scalar_t__ stub5 (struct e1000_hw*,int,int) ; 
 scalar_t__ stub6 (struct e1000_hw*) ; 
 scalar_t__ stub7 (struct e1000_hw*) ; 
 scalar_t__ stub8 (struct e1000_hw*) ; 
 scalar_t__ stub9 (struct e1000_hw*,int,int,int*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

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

__attribute__((used)) static void e1000_raise_eec_clk(struct e1000_hw *hw, u32 *eecd)
{
	*eecd = *eecd | E1000_EECD_SK;
	ew32(EECD, *eecd);
	e1e_flush();
	udelay(hw->nvm.delay_usec);
}

__attribute__((used)) static void e1000_lower_eec_clk(struct e1000_hw *hw, u32 *eecd)
{
	*eecd = *eecd & ~E1000_EECD_SK;
	ew32(EECD, *eecd);
	e1e_flush();
	udelay(hw->nvm.delay_usec);
}

__attribute__((used)) static void e1000_shift_out_eec_bits(struct e1000_hw *hw, u16 data, u16 count)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	u32 eecd = er32(EECD);
	u32 mask;

	mask = BIT(count - 1);
	if (nvm->type == e1000_nvm_eeprom_spi)
		eecd |= E1000_EECD_DO;

	do {
		eecd &= ~E1000_EECD_DI;

		if (data & mask)
			eecd |= E1000_EECD_DI;

		ew32(EECD, eecd);
		e1e_flush();

		udelay(nvm->delay_usec);

		e1000_raise_eec_clk(hw, &eecd);
		e1000_lower_eec_clk(hw, &eecd);

		mask >>= 1;
	} while (mask);

	eecd &= ~E1000_EECD_DI;
	ew32(EECD, eecd);
}

__attribute__((used)) static u16 e1000_shift_in_eec_bits(struct e1000_hw *hw, u16 count)
{
	u32 eecd;
	u32 i;
	u16 data;

	eecd = er32(EECD);
	eecd &= ~(E1000_EECD_DO | E1000_EECD_DI);
	data = 0;

	for (i = 0; i < count; i++) {
		data <<= 1;
		e1000_raise_eec_clk(hw, &eecd);

		eecd = er32(EECD);

		eecd &= ~E1000_EECD_DI;
		if (eecd & E1000_EECD_DO)
			data |= 1;

		e1000_lower_eec_clk(hw, &eecd);
	}

	return data;
}

s32 e1000e_poll_eerd_eewr_done(struct e1000_hw *hw, int ee_reg)
{
	u32 attempts = 100000;
	u32 i, reg = 0;

	for (i = 0; i < attempts; i++) {
		if (ee_reg == E1000_NVM_POLL_READ)
			reg = er32(EERD);
		else
			reg = er32(EEWR);

		if (reg & E1000_NVM_RW_REG_DONE)
			return 0;

		udelay(5);
	}

	return -E1000_ERR_NVM;
}

s32 e1000e_acquire_nvm(struct e1000_hw *hw)
{
	u32 eecd = er32(EECD);
	s32 timeout = E1000_NVM_GRANT_ATTEMPTS;

	ew32(EECD, eecd | E1000_EECD_REQ);
	eecd = er32(EECD);

	while (timeout) {
		if (eecd & E1000_EECD_GNT)
			break;
		udelay(5);
		eecd = er32(EECD);
		timeout--;
	}

	if (!timeout) {
		eecd &= ~E1000_EECD_REQ;
		ew32(EECD, eecd);
		e_dbg("Could not acquire NVM grant\n");
		return -E1000_ERR_NVM;
	}

	return 0;
}

__attribute__((used)) static void e1000_standby_nvm(struct e1000_hw *hw)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	u32 eecd = er32(EECD);

	if (nvm->type == e1000_nvm_eeprom_spi) {
		/* Toggle CS to flush commands */
		eecd |= E1000_EECD_CS;
		ew32(EECD, eecd);
		e1e_flush();
		udelay(nvm->delay_usec);
		eecd &= ~E1000_EECD_CS;
		ew32(EECD, eecd);
		e1e_flush();
		udelay(nvm->delay_usec);
	}
}

__attribute__((used)) static void e1000_stop_nvm(struct e1000_hw *hw)
{
	u32 eecd;

	eecd = er32(EECD);
	if (hw->nvm.type == e1000_nvm_eeprom_spi) {
		/* Pull CS high */
		eecd |= E1000_EECD_CS;
		e1000_lower_eec_clk(hw, &eecd);
	}
}

void e1000e_release_nvm(struct e1000_hw *hw)
{
	u32 eecd;

	e1000_stop_nvm(hw);

	eecd = er32(EECD);
	eecd &= ~E1000_EECD_REQ;
	ew32(EECD, eecd);
}

__attribute__((used)) static s32 e1000_ready_nvm_eeprom(struct e1000_hw *hw)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	u32 eecd = er32(EECD);
	u8 spi_stat_reg;

	if (nvm->type == e1000_nvm_eeprom_spi) {
		u16 timeout = NVM_MAX_RETRY_SPI;

		/* Clear SK and CS */
		eecd &= ~(E1000_EECD_CS | E1000_EECD_SK);
		ew32(EECD, eecd);
		e1e_flush();
		udelay(1);

		/* Read "Status Register" repeatedly until the LSB is cleared.
		 * The EEPROM will signal that the command has been completed
		 * by clearing bit 0 of the internal status register.  If it's
		 * not cleared within 'timeout', then error out.
		 */
		while (timeout) {
			e1000_shift_out_eec_bits(hw, NVM_RDSR_OPCODE_SPI,
						 hw->nvm.opcode_bits);
			spi_stat_reg = (u8)e1000_shift_in_eec_bits(hw, 8);
			if (!(spi_stat_reg & NVM_STATUS_RDY_SPI))
				break;

			udelay(5);
			e1000_standby_nvm(hw);
			timeout--;
		}

		if (!timeout) {
			e_dbg("SPI NVM Status error\n");
			return -E1000_ERR_NVM;
		}
	}

	return 0;
}

s32 e1000e_read_nvm_eerd(struct e1000_hw *hw, u16 offset, u16 words, u16 *data)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	u32 i, eerd = 0;
	s32 ret_val = 0;

	/* A check for invalid values:  offset too large, too many words,
	 * too many words for the offset, and not enough words.
	 */
	if ((offset >= nvm->word_size) || (words > (nvm->word_size - offset)) ||
	    (words == 0)) {
		e_dbg("nvm parameter(s) out of bounds\n");
		return -E1000_ERR_NVM;
	}

	for (i = 0; i < words; i++) {
		eerd = ((offset + i) << E1000_NVM_RW_ADDR_SHIFT) +
		    E1000_NVM_RW_REG_START;

		ew32(EERD, eerd);
		ret_val = e1000e_poll_eerd_eewr_done(hw, E1000_NVM_POLL_READ);
		if (ret_val) {
			e_dbg("NVM read error: %d\n", ret_val);
			break;
		}

		data[i] = (er32(EERD) >> E1000_NVM_RW_REG_DATA);
	}

	return ret_val;
}

s32 e1000e_write_nvm_spi(struct e1000_hw *hw, u16 offset, u16 words, u16 *data)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	s32 ret_val = -E1000_ERR_NVM;
	u16 widx = 0;

	/* A check for invalid values:  offset too large, too many words,
	 * and not enough words.
	 */
	if ((offset >= nvm->word_size) || (words > (nvm->word_size - offset)) ||
	    (words == 0)) {
		e_dbg("nvm parameter(s) out of bounds\n");
		return -E1000_ERR_NVM;
	}

	while (widx < words) {
		u8 write_opcode = NVM_WRITE_OPCODE_SPI;

		ret_val = nvm->ops.acquire(hw);
		if (ret_val)
			return ret_val;

		ret_val = e1000_ready_nvm_eeprom(hw);
		if (ret_val) {
			nvm->ops.release(hw);
			return ret_val;
		}

		e1000_standby_nvm(hw);

		/* Send the WRITE ENABLE command (8 bit opcode) */
		e1000_shift_out_eec_bits(hw, NVM_WREN_OPCODE_SPI,
					 nvm->opcode_bits);

		e1000_standby_nvm(hw);

		/* Some SPI eeproms use the 8th address bit embedded in the
		 * opcode
		 */
		if ((nvm->address_bits == 8) && (offset >= 128))
			write_opcode |= NVM_A8_OPCODE_SPI;

		/* Send the Write command (8-bit opcode + addr) */
		e1000_shift_out_eec_bits(hw, write_opcode, nvm->opcode_bits);
		e1000_shift_out_eec_bits(hw, (u16)((offset + widx) * 2),
					 nvm->address_bits);

		/* Loop to allow for up to whole page write of eeprom */
		while (widx < words) {
			u16 word_out = data[widx];

			word_out = (word_out >> 8) | (word_out << 8);
			e1000_shift_out_eec_bits(hw, word_out, 16);
			widx++;

			if ((((offset + widx) * 2) % nvm->page_size) == 0) {
				e1000_standby_nvm(hw);
				break;
			}
		}
		usleep_range(10000, 20000);
		nvm->ops.release(hw);
	}

	return ret_val;
}

s32 e1000_read_pba_string_generic(struct e1000_hw *hw, u8 *pba_num,
				  u32 pba_num_size)
{
	s32 ret_val;
	u16 nvm_data;
	u16 pba_ptr;
	u16 offset;
	u16 length;

	if (pba_num == NULL) {
		e_dbg("PBA string buffer was null\n");
		return -E1000_ERR_INVALID_ARGUMENT;
	}

	ret_val = e1000_read_nvm(hw, NVM_PBA_OFFSET_0, 1, &nvm_data);
	if (ret_val) {
		e_dbg("NVM Read Error\n");
		return ret_val;
	}

	ret_val = e1000_read_nvm(hw, NVM_PBA_OFFSET_1, 1, &pba_ptr);
	if (ret_val) {
		e_dbg("NVM Read Error\n");
		return ret_val;
	}

	/* if nvm_data is not ptr guard the PBA must be in legacy format which
	 * means pba_ptr is actually our second data word for the PBA number
	 * and we can decode it into an ascii string
	 */
	if (nvm_data != NVM_PBA_PTR_GUARD) {
		e_dbg("NVM PBA number is not stored as string\n");

		/* make sure callers buffer is big enough to store the PBA */
		if (pba_num_size < E1000_PBANUM_LENGTH) {
			e_dbg("PBA string buffer too small\n");
			return E1000_ERR_NO_SPACE;
		}

		/* extract hex string from data and pba_ptr */
		pba_num[0] = (nvm_data >> 12) & 0xF;
		pba_num[1] = (nvm_data >> 8) & 0xF;
		pba_num[2] = (nvm_data >> 4) & 0xF;
		pba_num[3] = nvm_data & 0xF;
		pba_num[4] = (pba_ptr >> 12) & 0xF;
		pba_num[5] = (pba_ptr >> 8) & 0xF;
		pba_num[6] = '-';
		pba_num[7] = 0;
		pba_num[8] = (pba_ptr >> 4) & 0xF;
		pba_num[9] = pba_ptr & 0xF;

		/* put a null character on the end of our string */
		pba_num[10] = '\0';

		/* switch all the data but the '-' to hex char */
		for (offset = 0; offset < 10; offset++) {
			if (pba_num[offset] < 0xA)
				pba_num[offset] += '0';
			else if (pba_num[offset] < 0x10)
				pba_num[offset] += 'A' - 0xA;
		}

		return 0;
	}

	ret_val = e1000_read_nvm(hw, pba_ptr, 1, &length);
	if (ret_val) {
		e_dbg("NVM Read Error\n");
		return ret_val;
	}

	if (length == 0xFFFF || length == 0) {
		e_dbg("NVM PBA number section invalid length\n");
		return -E1000_ERR_NVM_PBA_SECTION;
	}
	/* check if pba_num buffer is big enough */
	if (pba_num_size < (((u32)length * 2) - 1)) {
		e_dbg("PBA string buffer too small\n");
		return -E1000_ERR_NO_SPACE;
	}

	/* trim pba length from start of string */
	pba_ptr++;
	length--;

	for (offset = 0; offset < length; offset++) {
		ret_val = e1000_read_nvm(hw, pba_ptr + offset, 1, &nvm_data);
		if (ret_val) {
			e_dbg("NVM Read Error\n");
			return ret_val;
		}
		pba_num[offset * 2] = (u8)(nvm_data >> 8);
		pba_num[(offset * 2) + 1] = (u8)(nvm_data & 0xFF);
	}
	pba_num[offset * 2] = '\0';

	return 0;
}

s32 e1000_read_mac_addr_generic(struct e1000_hw *hw)
{
	u32 rar_high;
	u32 rar_low;
	u16 i;

	rar_high = er32(RAH(0));
	rar_low = er32(RAL(0));

	for (i = 0; i < E1000_RAL_MAC_ADDR_LEN; i++)
		hw->mac.perm_addr[i] = (u8)(rar_low >> (i * 8));

	for (i = 0; i < E1000_RAH_MAC_ADDR_LEN; i++)
		hw->mac.perm_addr[i + 4] = (u8)(rar_high >> (i * 8));

	for (i = 0; i < ETH_ALEN; i++)
		hw->mac.addr[i] = hw->mac.perm_addr[i];

	return 0;
}

s32 e1000e_validate_nvm_checksum_generic(struct e1000_hw *hw)
{
	s32 ret_val;
	u16 checksum = 0;
	u16 i, nvm_data;

	for (i = 0; i < (NVM_CHECKSUM_REG + 1); i++) {
		ret_val = e1000_read_nvm(hw, i, 1, &nvm_data);
		if (ret_val) {
			e_dbg("NVM Read Error\n");
			return ret_val;
		}
		checksum += nvm_data;
	}

	if (checksum != (u16)NVM_SUM) {
		e_dbg("NVM Checksum Invalid\n");
		return -E1000_ERR_NVM;
	}

	return 0;
}

s32 e1000e_update_nvm_checksum_generic(struct e1000_hw *hw)
{
	s32 ret_val;
	u16 checksum = 0;
	u16 i, nvm_data;

	for (i = 0; i < NVM_CHECKSUM_REG; i++) {
		ret_val = e1000_read_nvm(hw, i, 1, &nvm_data);
		if (ret_val) {
			e_dbg("NVM Read Error while updating checksum.\n");
			return ret_val;
		}
		checksum += nvm_data;
	}
	checksum = (u16)NVM_SUM - checksum;
	ret_val = e1000_write_nvm(hw, NVM_CHECKSUM_REG, 1, &checksum);
	if (ret_val)
		e_dbg("NVM Write Error while updating checksum.\n");

	return ret_val;
}

void e1000e_reload_nvm_generic(struct e1000_hw *hw)
{
	u32 ctrl_ext;

	usleep_range(10, 20);
	ctrl_ext = er32(CTRL_EXT);
	ctrl_ext |= E1000_CTRL_EXT_EE_RST;
	ew32(CTRL_EXT, ctrl_ext);
	e1e_flush();
}

