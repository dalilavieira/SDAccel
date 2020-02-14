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
struct TYPE_4__ {int (* acquire ) (struct e1000_hw*) ;int (* read ) (struct e1000_hw*,int,int,int*) ;int (* write ) (struct e1000_hw*,int,int,int*) ;int /*<<< orphan*/  (* release ) (struct e1000_hw*) ;} ;
struct e1000_nvm_info {int delay_usec; scalar_t__ type; int opcode_bits; int word_size; int address_bits; int page_size; TYPE_2__ ops; } ;
struct TYPE_3__ {int* perm_addr; int* addr; int type; } ;
struct e1000_hw {struct e1000_nvm_info nvm; TYPE_1__ mac; } ;
struct e1000_fw_version {int eep_major; int eep_minor; int eep_build; int or_valid; int or_major; int or_build; int or_patch; int etrack_id; } ;
typedef  int s32 ;

/* Variables and functions */
 int /*<<< orphan*/  E1000_EECD ; 
 int E1000_EECD_CS ; 
 int E1000_EECD_DI ; 
 int E1000_EECD_DO ; 
 int E1000_EECD_GNT ; 
 int E1000_EECD_REQ ; 
 int E1000_EECD_SK ; 
 int /*<<< orphan*/  E1000_EERD ; 
 int /*<<< orphan*/  E1000_EEWR ; 
 int E1000_ERR_INVALID_ARGUMENT ; 
 int E1000_ERR_NO_SPACE ; 
 int E1000_ERR_NVM ; 
 int E1000_ERR_NVM_PBA_SECTION ; 
 int E1000_NVM_GRANT_ATTEMPTS ; 
 int E1000_NVM_POLL_READ ; 
 int E1000_NVM_RW_ADDR_SHIFT ; 
 int E1000_NVM_RW_REG_DATA ; 
 int E1000_NVM_RW_REG_DONE ; 
 int E1000_NVM_RW_REG_START ; 
 int /*<<< orphan*/  E1000_RAH (int /*<<< orphan*/ ) ; 
 int E1000_RAH_MAC_ADDR_LEN ; 
 int /*<<< orphan*/  E1000_RAL (int /*<<< orphan*/ ) ; 
 int E1000_RAL_MAC_ADDR_LEN ; 
 int ETH_ALEN ; 
 int NVM_A8_OPCODE_SPI ; 
 int NVM_CHECKSUM_REG ; 
 int NVM_COMB_VER_MASK ; 
 int NVM_COMB_VER_OFF ; 
 int NVM_COMB_VER_PTR ; 
 int NVM_COMB_VER_SHFT ; 
 int NVM_ETRACK_HIWORD ; 
 int NVM_ETRACK_SHIFT ; 
 int NVM_ETRACK_VALID ; 
 int NVM_ETRACK_WORD ; 
 int NVM_HEX_CONV ; 
 int NVM_HEX_TENS ; 
 int NVM_IMAGE_ID_MASK ; 
 int NVM_MAJOR_MASK ; 
 int NVM_MAJOR_SHIFT ; 
 int NVM_MAX_RETRY_SPI ; 
 int NVM_MINOR_MASK ; 
 int NVM_MINOR_SHIFT ; 
 int NVM_NEW_DEC_MASK ; 
 int NVM_PBA_OFFSET_0 ; 
 int NVM_PBA_OFFSET_1 ; 
 int NVM_PBA_PTR_GUARD ; 
 int NVM_RDSR_OPCODE_SPI ; 
 int NVM_READ_OPCODE_SPI ; 
 int NVM_STATUS_RDY_SPI ; 
 scalar_t__ NVM_SUM ; 
 int NVM_VERSION ; 
 int NVM_VER_INVALID ; 
 int NVM_WREN_OPCODE_SPI ; 
 int NVM_WRITE_OPCODE_SPI ; 
#define  e1000_82575 133 
#define  e1000_82576 132 
#define  e1000_82580 131 
#define  e1000_i210 130 
#define  e1000_i211 129 
#define  e1000_i350 128 
 scalar_t__ e1000_nvm_eeprom_spi ; 
 int /*<<< orphan*/  hw_dbg (char*) ; 
 int /*<<< orphan*/  igb_get_flash_presence_i210 (struct e1000_hw*) ; 
 int /*<<< orphan*/  igb_read_invm_version (struct e1000_hw*,struct e1000_fw_version*) ; 
 int /*<<< orphan*/  memset (struct e1000_fw_version*,int /*<<< orphan*/ ,int) ; 
 int rd32 (int /*<<< orphan*/ ) ; 
 int stub1 (struct e1000_hw*) ; 
 int stub10 (struct e1000_hw*,int,int,int*) ; 
 int stub11 (struct e1000_hw*,int,int,int*) ; 
 int stub12 (struct e1000_hw*,int,int,int*) ; 
 int stub13 (struct e1000_hw*,int,int,int*) ; 
 int stub14 (struct e1000_hw*,int,int,int*) ; 
 int stub15 (struct e1000_hw*,int,int,int*) ; 
 int stub16 (struct e1000_hw*,int,int,int*) ; 
 int stub17 (struct e1000_hw*,int,int,int*) ; 
 int stub18 (struct e1000_hw*,int,int,int*) ; 
 int stub19 (struct e1000_hw*,int,int,int*) ; 
 int /*<<< orphan*/  stub2 (struct e1000_hw*) ; 
 int stub20 (struct e1000_hw*,int,int,int*) ; 
 int stub3 (struct e1000_hw*) ; 
 int /*<<< orphan*/  stub4 (struct e1000_hw*) ; 
 int /*<<< orphan*/  stub5 (struct e1000_hw*) ; 
 int stub6 (struct e1000_hw*,int,int,int*) ; 
 int stub7 (struct e1000_hw*,int,int,int*) ; 
 int stub8 (struct e1000_hw*,int,int,int*) ; 
 int stub9 (struct e1000_hw*,int,int,int*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  wr32 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  wrfl () ; 

__attribute__((used)) static void igb_raise_eec_clk(struct e1000_hw *hw, u32 *eecd)
{
	*eecd = *eecd | E1000_EECD_SK;
	wr32(E1000_EECD, *eecd);
	wrfl();
	udelay(hw->nvm.delay_usec);
}

__attribute__((used)) static void igb_lower_eec_clk(struct e1000_hw *hw, u32 *eecd)
{
	*eecd = *eecd & ~E1000_EECD_SK;
	wr32(E1000_EECD, *eecd);
	wrfl();
	udelay(hw->nvm.delay_usec);
}

__attribute__((used)) static void igb_shift_out_eec_bits(struct e1000_hw *hw, u16 data, u16 count)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	u32 eecd = rd32(E1000_EECD);
	u32 mask;

	mask = 1u << (count - 1);
	if (nvm->type == e1000_nvm_eeprom_spi)
		eecd |= E1000_EECD_DO;

	do {
		eecd &= ~E1000_EECD_DI;

		if (data & mask)
			eecd |= E1000_EECD_DI;

		wr32(E1000_EECD, eecd);
		wrfl();

		udelay(nvm->delay_usec);

		igb_raise_eec_clk(hw, &eecd);
		igb_lower_eec_clk(hw, &eecd);

		mask >>= 1;
	} while (mask);

	eecd &= ~E1000_EECD_DI;
	wr32(E1000_EECD, eecd);
}

__attribute__((used)) static u16 igb_shift_in_eec_bits(struct e1000_hw *hw, u16 count)
{
	u32 eecd;
	u32 i;
	u16 data;

	eecd = rd32(E1000_EECD);

	eecd &= ~(E1000_EECD_DO | E1000_EECD_DI);
	data = 0;

	for (i = 0; i < count; i++) {
		data <<= 1;
		igb_raise_eec_clk(hw, &eecd);

		eecd = rd32(E1000_EECD);

		eecd &= ~E1000_EECD_DI;
		if (eecd & E1000_EECD_DO)
			data |= 1;

		igb_lower_eec_clk(hw, &eecd);
	}

	return data;
}

__attribute__((used)) static s32 igb_poll_eerd_eewr_done(struct e1000_hw *hw, int ee_reg)
{
	u32 attempts = 100000;
	u32 i, reg = 0;
	s32 ret_val = -E1000_ERR_NVM;

	for (i = 0; i < attempts; i++) {
		if (ee_reg == E1000_NVM_POLL_READ)
			reg = rd32(E1000_EERD);
		else
			reg = rd32(E1000_EEWR);

		if (reg & E1000_NVM_RW_REG_DONE) {
			ret_val = 0;
			break;
		}

		udelay(5);
	}

	return ret_val;
}

s32 igb_acquire_nvm(struct e1000_hw *hw)
{
	u32 eecd = rd32(E1000_EECD);
	s32 timeout = E1000_NVM_GRANT_ATTEMPTS;
	s32 ret_val = 0;


	wr32(E1000_EECD, eecd | E1000_EECD_REQ);
	eecd = rd32(E1000_EECD);

	while (timeout) {
		if (eecd & E1000_EECD_GNT)
			break;
		udelay(5);
		eecd = rd32(E1000_EECD);
		timeout--;
	}

	if (!timeout) {
		eecd &= ~E1000_EECD_REQ;
		wr32(E1000_EECD, eecd);
		hw_dbg("Could not acquire NVM grant\n");
		ret_val = -E1000_ERR_NVM;
	}

	return ret_val;
}

__attribute__((used)) static void igb_standby_nvm(struct e1000_hw *hw)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	u32 eecd = rd32(E1000_EECD);

	if (nvm->type == e1000_nvm_eeprom_spi) {
		/* Toggle CS to flush commands */
		eecd |= E1000_EECD_CS;
		wr32(E1000_EECD, eecd);
		wrfl();
		udelay(nvm->delay_usec);
		eecd &= ~E1000_EECD_CS;
		wr32(E1000_EECD, eecd);
		wrfl();
		udelay(nvm->delay_usec);
	}
}

__attribute__((used)) static void e1000_stop_nvm(struct e1000_hw *hw)
{
	u32 eecd;

	eecd = rd32(E1000_EECD);
	if (hw->nvm.type == e1000_nvm_eeprom_spi) {
		/* Pull CS high */
		eecd |= E1000_EECD_CS;
		igb_lower_eec_clk(hw, &eecd);
	}
}

void igb_release_nvm(struct e1000_hw *hw)
{
	u32 eecd;

	e1000_stop_nvm(hw);

	eecd = rd32(E1000_EECD);
	eecd &= ~E1000_EECD_REQ;
	wr32(E1000_EECD, eecd);
}

__attribute__((used)) static s32 igb_ready_nvm_eeprom(struct e1000_hw *hw)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	u32 eecd = rd32(E1000_EECD);
	s32 ret_val = 0;
	u16 timeout = 0;
	u8 spi_stat_reg;


	if (nvm->type == e1000_nvm_eeprom_spi) {
		/* Clear SK and CS */
		eecd &= ~(E1000_EECD_CS | E1000_EECD_SK);
		wr32(E1000_EECD, eecd);
		wrfl();
		udelay(1);
		timeout = NVM_MAX_RETRY_SPI;

		/* Read "Status Register" repeatedly until the LSB is cleared.
		 * The EEPROM will signal that the command has been completed
		 * by clearing bit 0 of the internal status register.  If it's
		 * not cleared within 'timeout', then error out.
		 */
		while (timeout) {
			igb_shift_out_eec_bits(hw, NVM_RDSR_OPCODE_SPI,
					       hw->nvm.opcode_bits);
			spi_stat_reg = (u8)igb_shift_in_eec_bits(hw, 8);
			if (!(spi_stat_reg & NVM_STATUS_RDY_SPI))
				break;

			udelay(5);
			igb_standby_nvm(hw);
			timeout--;
		}

		if (!timeout) {
			hw_dbg("SPI NVM Status error\n");
			ret_val = -E1000_ERR_NVM;
			goto out;
		}
	}

out:
	return ret_val;
}

s32 igb_read_nvm_spi(struct e1000_hw *hw, u16 offset, u16 words, u16 *data)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	u32 i = 0;
	s32 ret_val;
	u16 word_in;
	u8 read_opcode = NVM_READ_OPCODE_SPI;

	/* A check for invalid values:  offset too large, too many words,
	 * and not enough words.
	 */
	if ((offset >= nvm->word_size) || (words > (nvm->word_size - offset)) ||
	    (words == 0)) {
		hw_dbg("nvm parameter(s) out of bounds\n");
		ret_val = -E1000_ERR_NVM;
		goto out;
	}

	ret_val = nvm->ops.acquire(hw);
	if (ret_val)
		goto out;

	ret_val = igb_ready_nvm_eeprom(hw);
	if (ret_val)
		goto release;

	igb_standby_nvm(hw);

	if ((nvm->address_bits == 8) && (offset >= 128))
		read_opcode |= NVM_A8_OPCODE_SPI;

	/* Send the READ command (opcode + addr) */
	igb_shift_out_eec_bits(hw, read_opcode, nvm->opcode_bits);
	igb_shift_out_eec_bits(hw, (u16)(offset*2), nvm->address_bits);

	/* Read the data.  SPI NVMs increment the address with each byte
	 * read and will roll over if reading beyond the end.  This allows
	 * us to read the whole NVM from any offset
	 */
	for (i = 0; i < words; i++) {
		word_in = igb_shift_in_eec_bits(hw, 16);
		data[i] = (word_in >> 8) | (word_in << 8);
	}

release:
	nvm->ops.release(hw);

out:
	return ret_val;
}

s32 igb_read_nvm_eerd(struct e1000_hw *hw, u16 offset, u16 words, u16 *data)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	u32 i, eerd = 0;
	s32 ret_val = 0;

	/* A check for invalid values:  offset too large, too many words,
	 * and not enough words.
	 */
	if ((offset >= nvm->word_size) || (words > (nvm->word_size - offset)) ||
	    (words == 0)) {
		hw_dbg("nvm parameter(s) out of bounds\n");
		ret_val = -E1000_ERR_NVM;
		goto out;
	}

	for (i = 0; i < words; i++) {
		eerd = ((offset+i) << E1000_NVM_RW_ADDR_SHIFT) +
			E1000_NVM_RW_REG_START;

		wr32(E1000_EERD, eerd);
		ret_val = igb_poll_eerd_eewr_done(hw, E1000_NVM_POLL_READ);
		if (ret_val)
			break;

		data[i] = (rd32(E1000_EERD) >>
			E1000_NVM_RW_REG_DATA);
	}

out:
	return ret_val;
}

s32 igb_write_nvm_spi(struct e1000_hw *hw, u16 offset, u16 words, u16 *data)
{
	struct e1000_nvm_info *nvm = &hw->nvm;
	s32 ret_val = -E1000_ERR_NVM;
	u16 widx = 0;

	/* A check for invalid values:  offset too large, too many words,
	 * and not enough words.
	 */
	if ((offset >= nvm->word_size) || (words > (nvm->word_size - offset)) ||
	    (words == 0)) {
		hw_dbg("nvm parameter(s) out of bounds\n");
		return ret_val;
	}

	while (widx < words) {
		u8 write_opcode = NVM_WRITE_OPCODE_SPI;

		ret_val = nvm->ops.acquire(hw);
		if (ret_val)
			return ret_val;

		ret_val = igb_ready_nvm_eeprom(hw);
		if (ret_val) {
			nvm->ops.release(hw);
			return ret_val;
		}

		igb_standby_nvm(hw);

		/* Send the WRITE ENABLE command (8 bit opcode) */
		igb_shift_out_eec_bits(hw, NVM_WREN_OPCODE_SPI,
					 nvm->opcode_bits);

		igb_standby_nvm(hw);

		/* Some SPI eeproms use the 8th address bit embedded in the
		 * opcode
		 */
		if ((nvm->address_bits == 8) && (offset >= 128))
			write_opcode |= NVM_A8_OPCODE_SPI;

		/* Send the Write command (8-bit opcode + addr) */
		igb_shift_out_eec_bits(hw, write_opcode, nvm->opcode_bits);
		igb_shift_out_eec_bits(hw, (u16)((offset + widx) * 2),
					 nvm->address_bits);

		/* Loop to allow for up to whole page write of eeprom */
		while (widx < words) {
			u16 word_out = data[widx];

			word_out = (word_out >> 8) | (word_out << 8);
			igb_shift_out_eec_bits(hw, word_out, 16);
			widx++;

			if ((((offset + widx) * 2) % nvm->page_size) == 0) {
				igb_standby_nvm(hw);
				break;
			}
		}
		usleep_range(1000, 2000);
		nvm->ops.release(hw);
	}

	return ret_val;
}

s32 igb_read_part_string(struct e1000_hw *hw, u8 *part_num, u32 part_num_size)
{
	s32 ret_val;
	u16 nvm_data;
	u16 pointer;
	u16 offset;
	u16 length;

	if (part_num == NULL) {
		hw_dbg("PBA string buffer was null\n");
		ret_val = E1000_ERR_INVALID_ARGUMENT;
		goto out;
	}

	ret_val = hw->nvm.ops.read(hw, NVM_PBA_OFFSET_0, 1, &nvm_data);
	if (ret_val) {
		hw_dbg("NVM Read Error\n");
		goto out;
	}

	ret_val = hw->nvm.ops.read(hw, NVM_PBA_OFFSET_1, 1, &pointer);
	if (ret_val) {
		hw_dbg("NVM Read Error\n");
		goto out;
	}

	/* if nvm_data is not ptr guard the PBA must be in legacy format which
	 * means pointer is actually our second data word for the PBA number
	 * and we can decode it into an ascii string
	 */
	if (nvm_data != NVM_PBA_PTR_GUARD) {
		hw_dbg("NVM PBA number is not stored as string\n");

		/* we will need 11 characters to store the PBA */
		if (part_num_size < 11) {
			hw_dbg("PBA string buffer too small\n");
			return E1000_ERR_NO_SPACE;
		}

		/* extract hex string from data and pointer */
		part_num[0] = (nvm_data >> 12) & 0xF;
		part_num[1] = (nvm_data >> 8) & 0xF;
		part_num[2] = (nvm_data >> 4) & 0xF;
		part_num[3] = nvm_data & 0xF;
		part_num[4] = (pointer >> 12) & 0xF;
		part_num[5] = (pointer >> 8) & 0xF;
		part_num[6] = '-';
		part_num[7] = 0;
		part_num[8] = (pointer >> 4) & 0xF;
		part_num[9] = pointer & 0xF;

		/* put a null character on the end of our string */
		part_num[10] = '\0';

		/* switch all the data but the '-' to hex char */
		for (offset = 0; offset < 10; offset++) {
			if (part_num[offset] < 0xA)
				part_num[offset] += '0';
			else if (part_num[offset] < 0x10)
				part_num[offset] += 'A' - 0xA;
		}

		goto out;
	}

	ret_val = hw->nvm.ops.read(hw, pointer, 1, &length);
	if (ret_val) {
		hw_dbg("NVM Read Error\n");
		goto out;
	}

	if (length == 0xFFFF || length == 0) {
		hw_dbg("NVM PBA number section invalid length\n");
		ret_val = E1000_ERR_NVM_PBA_SECTION;
		goto out;
	}
	/* check if part_num buffer is big enough */
	if (part_num_size < (((u32)length * 2) - 1)) {
		hw_dbg("PBA string buffer too small\n");
		ret_val = E1000_ERR_NO_SPACE;
		goto out;
	}

	/* trim pba length from start of string */
	pointer++;
	length--;

	for (offset = 0; offset < length; offset++) {
		ret_val = hw->nvm.ops.read(hw, pointer + offset, 1, &nvm_data);
		if (ret_val) {
			hw_dbg("NVM Read Error\n");
			goto out;
		}
		part_num[offset * 2] = (u8)(nvm_data >> 8);
		part_num[(offset * 2) + 1] = (u8)(nvm_data & 0xFF);
	}
	part_num[offset * 2] = '\0';

out:
	return ret_val;
}

s32 igb_read_mac_addr(struct e1000_hw *hw)
{
	u32 rar_high;
	u32 rar_low;
	u16 i;

	rar_high = rd32(E1000_RAH(0));
	rar_low = rd32(E1000_RAL(0));

	for (i = 0; i < E1000_RAL_MAC_ADDR_LEN; i++)
		hw->mac.perm_addr[i] = (u8)(rar_low >> (i*8));

	for (i = 0; i < E1000_RAH_MAC_ADDR_LEN; i++)
		hw->mac.perm_addr[i+4] = (u8)(rar_high >> (i*8));

	for (i = 0; i < ETH_ALEN; i++)
		hw->mac.addr[i] = hw->mac.perm_addr[i];

	return 0;
}

s32 igb_validate_nvm_checksum(struct e1000_hw *hw)
{
	s32 ret_val = 0;
	u16 checksum = 0;
	u16 i, nvm_data;

	for (i = 0; i < (NVM_CHECKSUM_REG + 1); i++) {
		ret_val = hw->nvm.ops.read(hw, i, 1, &nvm_data);
		if (ret_val) {
			hw_dbg("NVM Read Error\n");
			goto out;
		}
		checksum += nvm_data;
	}

	if (checksum != (u16) NVM_SUM) {
		hw_dbg("NVM Checksum Invalid\n");
		ret_val = -E1000_ERR_NVM;
		goto out;
	}

out:
	return ret_val;
}

s32 igb_update_nvm_checksum(struct e1000_hw *hw)
{
	s32  ret_val;
	u16 checksum = 0;
	u16 i, nvm_data;

	for (i = 0; i < NVM_CHECKSUM_REG; i++) {
		ret_val = hw->nvm.ops.read(hw, i, 1, &nvm_data);
		if (ret_val) {
			hw_dbg("NVM Read Error while updating checksum.\n");
			goto out;
		}
		checksum += nvm_data;
	}
	checksum = (u16) NVM_SUM - checksum;
	ret_val = hw->nvm.ops.write(hw, NVM_CHECKSUM_REG, 1, &checksum);
	if (ret_val)
		hw_dbg("NVM Write Error while updating checksum.\n");

out:
	return ret_val;
}

void igb_get_fw_version(struct e1000_hw *hw, struct e1000_fw_version *fw_vers)
{
	u16 eeprom_verh, eeprom_verl, etrack_test, fw_version;
	u8 q, hval, rem, result;
	u16 comb_verh, comb_verl, comb_offset;

	memset(fw_vers, 0, sizeof(struct e1000_fw_version));

	/* basic eeprom version numbers and bits used vary by part and by tool
	 * used to create the nvm images. Check which data format we have.
	 */
	hw->nvm.ops.read(hw, NVM_ETRACK_HIWORD, 1, &etrack_test);
	switch (hw->mac.type) {
	case e1000_i211:
		igb_read_invm_version(hw, fw_vers);
		return;
	case e1000_82575:
	case e1000_82576:
	case e1000_82580:
		/* Use this format, unless EETRACK ID exists,
		 * then use alternate format
		 */
		if ((etrack_test &  NVM_MAJOR_MASK) != NVM_ETRACK_VALID) {
			hw->nvm.ops.read(hw, NVM_VERSION, 1, &fw_version);
			fw_vers->eep_major = (fw_version & NVM_MAJOR_MASK)
					      >> NVM_MAJOR_SHIFT;
			fw_vers->eep_minor = (fw_version & NVM_MINOR_MASK)
					      >> NVM_MINOR_SHIFT;
			fw_vers->eep_build = (fw_version & NVM_IMAGE_ID_MASK);
			goto etrack_id;
		}
		break;
	case e1000_i210:
		if (!(igb_get_flash_presence_i210(hw))) {
			igb_read_invm_version(hw, fw_vers);
			return;
		}
		/* fall through */
	case e1000_i350:
		/* find combo image version */
		hw->nvm.ops.read(hw, NVM_COMB_VER_PTR, 1, &comb_offset);
		if ((comb_offset != 0x0) &&
		    (comb_offset != NVM_VER_INVALID)) {

			hw->nvm.ops.read(hw, (NVM_COMB_VER_OFF + comb_offset
					 + 1), 1, &comb_verh);
			hw->nvm.ops.read(hw, (NVM_COMB_VER_OFF + comb_offset),
					 1, &comb_verl);

			/* get Option Rom version if it exists and is valid */
			if ((comb_verh && comb_verl) &&
			    ((comb_verh != NVM_VER_INVALID) &&
			     (comb_verl != NVM_VER_INVALID))) {

				fw_vers->or_valid = true;
				fw_vers->or_major =
					comb_verl >> NVM_COMB_VER_SHFT;
				fw_vers->or_build =
					(comb_verl << NVM_COMB_VER_SHFT)
					| (comb_verh >> NVM_COMB_VER_SHFT);
				fw_vers->or_patch =
					comb_verh & NVM_COMB_VER_MASK;
			}
		}
		break;
	default:
		return;
	}
	hw->nvm.ops.read(hw, NVM_VERSION, 1, &fw_version);
	fw_vers->eep_major = (fw_version & NVM_MAJOR_MASK)
			      >> NVM_MAJOR_SHIFT;

	/* check for old style version format in newer images*/
	if ((fw_version & NVM_NEW_DEC_MASK) == 0x0) {
		eeprom_verl = (fw_version & NVM_COMB_VER_MASK);
	} else {
		eeprom_verl = (fw_version & NVM_MINOR_MASK)
				>> NVM_MINOR_SHIFT;
	}
	/* Convert minor value to hex before assigning to output struct
	 * Val to be converted will not be higher than 99, per tool output
	 */
	q = eeprom_verl / NVM_HEX_CONV;
	hval = q * NVM_HEX_TENS;
	rem = eeprom_verl % NVM_HEX_CONV;
	result = hval + rem;
	fw_vers->eep_minor = result;

etrack_id:
	if ((etrack_test &  NVM_MAJOR_MASK) == NVM_ETRACK_VALID) {
		hw->nvm.ops.read(hw, NVM_ETRACK_WORD, 1, &eeprom_verl);
		hw->nvm.ops.read(hw, (NVM_ETRACK_WORD + 1), 1, &eeprom_verh);
		fw_vers->etrack_id = (eeprom_verh << NVM_ETRACK_SHIFT)
			| eeprom_verl;
	}
}

