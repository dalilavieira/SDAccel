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
typedef  int uint8 ;
typedef  int uint64 ;
typedef  int uint32_t ;
typedef  int uint32 ;
typedef  int uint16 ;
struct TYPE_2__ {int* word; unsigned long long dword; } ;
typedef  TYPE_1__ spi_buf_t ;
typedef  int sint16 ;

/* Variables and functions */
 int BIT15 ; 
 int BIT19 ; 
 int /*<<< orphan*/  CLEAR_PERI_REG_MASK (scalar_t__,int) ; 
 int /*<<< orphan*/  ETS_SPI_INTR_ATTACH (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ETS_SPI_INTR_ENABLE () ; 
 scalar_t__ PERIPHS_IO_MUX ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_MTCK_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_MTDI_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_MTDO_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_MTMS_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_SD_CLK_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_SD_CMD_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_SD_DATA0_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_SD_DATA1_U ; 
 int /*<<< orphan*/  PIN_FUNC_SELECT (int /*<<< orphan*/ ,int) ; 
 int READ_PERI_REG (scalar_t__) ; 
 int /*<<< orphan*/  SET_PERI_REG_MASK (scalar_t__,int) ; 
 scalar_t__ SPI_ADDR (int) ; 
 int SPI_CK_OUT_EDGE ; 
 int SPI_CLKCNT_H ; 
 int SPI_CLKCNT_H_S ; 
 int SPI_CLKCNT_L ; 
 int SPI_CLKCNT_L_S ; 
 int SPI_CLKCNT_N ; 
 int SPI_CLKCNT_N_S ; 
 int SPI_CLKDIV_PRE ; 
 int SPI_CLKDIV_PRE_S ; 
 int SPI_CLK_EQU_SYSCLK ; 
 scalar_t__ SPI_CLOCK (int) ; 
 scalar_t__ SPI_CMD (int) ; 
 int SPI_CS_HOLD ; 
 int SPI_CS_SETUP ; 
 scalar_t__ SPI_CTRL (int) ; 
 scalar_t__ SPI_CTRL2 (int) ; 
 int SPI_DIO_MODE ; 
 int SPI_DOUTDIN ; 
 int SPI_DOUT_MODE ; 
 int SPI_FLASH_MODE ; 
 int SPI_HSPI ; 
 int SPI_IDLE_EDGE ; 
 int SPI_MOSI_DELAY_NUM ; 
 int SPI_MOSI_DELAY_NUM_S ; 
 int SPI_ORDER_LSB ; 
 int SPI_ORDER_MSB ; 
 scalar_t__ SPI_PIN (int) ; 
 int SPI_QIO_MODE ; 
 int SPI_QOUT_MODE ; 
 int SPI_RD_BYTE_ORDER ; 
 scalar_t__ SPI_SLAVE (int) ; 
 scalar_t__ SPI_SLAVE1 (int) ; 
 int SPI_SLAVE_MODE ; 
 int SPI_SLV_BUF_BITLEN ; 
 int SPI_SLV_BUF_BITLEN_S ; 
 int SPI_SLV_RD_ADDR_BITLEN ; 
 int SPI_SLV_RD_ADDR_BITLEN_S ; 
 int SPI_SLV_RD_BUF_DONE_EN ; 
 int SPI_SLV_RD_STA_DONE_EN ; 
 int SPI_SLV_STATUS_BITLEN ; 
 int SPI_SLV_STATUS_BITLEN_S ; 
 int SPI_SLV_WR_ADDR_BITLEN ; 
 int SPI_SLV_WR_ADDR_BITLEN_S ; 
 int SPI_SLV_WR_BUF_DONE_EN ; 
 int SPI_SLV_WR_RD_BUF_EN ; 
 int SPI_SLV_WR_STA_DONE_EN ; 
 int SPI_SPI ; 
 int SPI_TRANS_DONE_EN ; 
 scalar_t__ SPI_USER (int) ; 
 scalar_t__ SPI_USER1 (int) ; 
 scalar_t__ SPI_USER2 (int) ; 
 int SPI_USR ; 
 int SPI_USR_ADDR ; 
 int SPI_USR_ADDR_BITLEN ; 
 int SPI_USR_ADDR_BITLEN_S ; 
 int SPI_USR_COMMAND ; 
 int SPI_USR_COMMAND_BITLEN ; 
 int SPI_USR_COMMAND_BITLEN_S ; 
 int SPI_USR_COMMAND_VALUE ; 
 int SPI_USR_DUMMY ; 
 int SPI_USR_DUMMY_CYCLELEN ; 
 int SPI_USR_DUMMY_CYCLELEN_S ; 
 int SPI_USR_MISO ; 
 int SPI_USR_MISO_BITLEN ; 
 int SPI_USR_MISO_BITLEN_S ; 
 int SPI_USR_MISO_HIGHPART ; 
 int SPI_USR_MOSI ; 
 int SPI_USR_MOSI_BITLEN ; 
 int SPI_USR_MOSI_BITLEN_S ; 
 scalar_t__ SPI_W0 (int) ; 
 int SPI_WR_BYTE_ORDER ; 
 int /*<<< orphan*/  WRITE_PERI_REG (scalar_t__,int) ; 
 int /*<<< orphan*/  os_memcpy (void*,void*,size_t) ; 
 int /*<<< orphan*/  os_printf (char*,int) ; 
 int* spi_clkdiv ; 
 int /*<<< orphan*/  spi_slave_isr_handler ; 

void spi_lcd_mode_init(uint8 spi_no)
{
	uint32 regvalue;
	if(spi_no>1) 		return; //handle invalid input number
	//bit9 of PERIPHS_IO_MUX should be cleared when HSPI clock doesn't equal CPU clock
	//bit8 of PERIPHS_IO_MUX should be cleared when SPI clock doesn't equal CPU clock
	if(spi_no==SPI_SPI){
		WRITE_PERI_REG(PERIPHS_IO_MUX, 0x005); //clear bit9,and bit8
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_CLK_U, 1);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_CMD_U, 1);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA0_U, 1);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA1_U, 1);//configure io to spi mode
	}else if(spi_no==SPI_HSPI){
		WRITE_PERI_REG(PERIPHS_IO_MUX, 0x105); //clear bit9
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, 2);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, 2);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U, 2);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, 2);//configure io to spi mode
	}

	SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_CS_SETUP|SPI_CS_HOLD|SPI_USR_COMMAND);
	CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_FLASH_MODE);
	// SPI clock=CPU clock/8
	WRITE_PERI_REG(SPI_CLOCK(spi_no),
					((1&SPI_CLKDIV_PRE)<<SPI_CLKDIV_PRE_S)|
					((3&SPI_CLKCNT_N)<<SPI_CLKCNT_N_S)|
					((1&SPI_CLKCNT_H)<<SPI_CLKCNT_H_S)|
					((3&SPI_CLKCNT_L)<<SPI_CLKCNT_L_S)); //clear bit 31,set SPI clock div

}

void spi_lcd_9bit_write(uint8 spi_no,uint8 high_bit,uint8 low_8bit)
{
	uint32 regvalue;
	uint8 bytetemp;
	if(spi_no>1) 		return; //handle invalid input number

	if(high_bit)		bytetemp=(low_8bit>>1)|0x80;
	else				bytetemp=(low_8bit>>1)&0x7f;

	regvalue= ((8&SPI_USR_COMMAND_BITLEN)<<SPI_USR_COMMAND_BITLEN_S)|((uint32)bytetemp);		//configure transmission variable,9bit transmission length and first 8 command bit
	if(low_8bit&0x01) 	regvalue|=BIT15;        //write the 9th bit
	while(READ_PERI_REG(SPI_CMD(spi_no))&SPI_USR);		//waiting for spi module available
	WRITE_PERI_REG(SPI_USER2(spi_no), regvalue);				//write  command and command length into spi reg
	SET_PERI_REG_MASK(SPI_CMD(spi_no), SPI_USR);		//transmission start
}

uint32_t spi_set_clkdiv(uint8 spi_no, uint32_t clock_div)
{
	uint32_t tmp_clkdiv;

	if (spi_no > 1) return 0; //handle invalid input number
	tmp_clkdiv = spi_clkdiv[spi_no];

	if (clock_div > 1) {
		uint8 i, k;
		i = (clock_div / 40) ? (clock_div / 40) : 1;
		k = clock_div / i;
		WRITE_PERI_REG(SPI_CLOCK(spi_no),
			       (((i - 1) & SPI_CLKDIV_PRE) << SPI_CLKDIV_PRE_S) |
			       (((k - 1) & SPI_CLKCNT_N) << SPI_CLKCNT_N_S) |
			       ((((k + 1) / 2 - 1) & SPI_CLKCNT_H) << SPI_CLKCNT_H_S) |
			       (((k - 1) & SPI_CLKCNT_L) << SPI_CLKCNT_L_S)); //clear bit 31,set SPI clock div
	} else {
		WRITE_PERI_REG(SPI_CLOCK(spi_no), SPI_CLK_EQU_SYSCLK); // 80Mhz speed
	}

	if(spi_no==SPI_SPI){
		WRITE_PERI_REG(PERIPHS_IO_MUX, 0x005 | (clock_div <= 1 ? 0x100 : 0));
	}
	else if(spi_no==SPI_HSPI){
		WRITE_PERI_REG(PERIPHS_IO_MUX, 0x105 | (clock_div <= 1 ? 0x200 : 0));
	}

	spi_clkdiv[spi_no] = clock_div;

	return tmp_clkdiv;
}

void spi_master_init(uint8 spi_no, unsigned cpol, unsigned cpha, uint32_t clock_div)
{
	uint32 regvalue;

	if(spi_no>1) 		return; //handle invalid input number

	SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_CS_SETUP|SPI_CS_HOLD|SPI_RD_BYTE_ORDER|SPI_WR_BYTE_ORDER);

	// set clock polarity (Reference: http://bbs.espressif.com/viewtopic.php?f=49&t=1570)
	// phase is dependent on polarity. See Issue #1161
	if (cpol == 1) {
		SET_PERI_REG_MASK(SPI_PIN(spi_no), SPI_IDLE_EDGE);
	} else {
		CLEAR_PERI_REG_MASK(SPI_PIN(spi_no), SPI_IDLE_EDGE);
	}

	//set clock phase
	if (cpha == cpol) {
		// Mode 3: MOSI is set on falling edge of clock
		// Mode 0: MOSI is set on falling edge of clock
		CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_CK_OUT_EDGE);
	} else {
		// Mode 2: MOSI is set on rising edge of clock
		// Mode 1: MOSI is set on rising edge of clock
		SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_CK_OUT_EDGE);
	}

	CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_FLASH_MODE|SPI_USR_MISO|SPI_USR_ADDR|SPI_USR_COMMAND|SPI_USR_DUMMY);

	//clear Dual or Quad lines transmission mode
	CLEAR_PERI_REG_MASK(SPI_CTRL(spi_no), SPI_QIO_MODE|SPI_DIO_MODE|SPI_DOUT_MODE|SPI_QOUT_MODE);

	spi_set_clkdiv(spi_no, clock_div);

	if(spi_no==SPI_SPI){
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_CLK_U, 1);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_CMD_U, 1);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA0_U, 1);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA1_U, 1);//configure io to spi mode
	}
	else if(spi_no==SPI_HSPI){
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, 2);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, 2);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U, 2);//configure io to spi mode
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, 2);//configure io to spi mode
	}
}

void spi_mast_byte_order(uint8 spi_no, uint8 order)
{
    if(spi_no > 1)
        return;

    if (order == SPI_ORDER_MSB) {
	SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_RD_BYTE_ORDER | SPI_WR_BYTE_ORDER);
    } else if (order == SPI_ORDER_LSB) {
	CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_RD_BYTE_ORDER | SPI_WR_BYTE_ORDER);
    }
}

void spi_mast_blkset(uint8 spi_no, size_t bitlen, const uint8 *data)
{
    size_t aligned_len = bitlen >> 3;

    while(READ_PERI_REG(SPI_CMD(spi_no)) & SPI_USR);

    if (aligned_len % 4) {
        // length for memcpy needs to be aligned to uint32 bounday
        // otherwise single byte writes are issued to the register and corrupt data
        aligned_len += 4 - (aligned_len % 4);
    }
    os_memcpy((void *)SPI_W0(spi_no), (const void *)data, aligned_len);
}

void spi_mast_blkget(uint8 spi_no, size_t bitlen, uint8 *data)
{
    size_t aligned_len = bitlen >> 3;

    while(READ_PERI_REG(SPI_CMD(spi_no)) & SPI_USR);

    if (aligned_len % 4) {
        // length for memcpy needs to be aligned to uint32 bounday
        // otherwise single byte reads are issued to the register and corrupt data
        aligned_len += 4 - (aligned_len % 4);
    }
    os_memcpy((void *)data, (void *)SPI_W0(spi_no), aligned_len);
}

__attribute__((used)) static uint32 swap_endianess(uint32 n)
{
    return ((n & 0xff) << 24) |
            ((n & 0xff00) << 8) |
            ((n & 0xff0000UL) >> 8) |
            ((n & 0xff000000UL) >> 24);
}

void spi_mast_set_mosi(uint8 spi_no, uint16 offset, uint8 bitlen, uint32 data)
{
    spi_buf_t spi_buf;
    uint8     wn, shift;

    if (spi_no > 1)
        return; // handle invalid input number
    if (bitlen > 32)
        return; // handle invalid input number

    // determine which SPI_Wn register is addressed
    wn = offset >> 5;
    if (wn > 15) {
        return; // out of range
    }

    while(READ_PERI_REG(SPI_CMD(spi_no)) & SPI_USR);

    // transfer Wn to buf
    spi_buf.word[1] = READ_PERI_REG(SPI_W0(spi_no) + wn*4);
    spi_buf.word[1] = swap_endianess(spi_buf.word[1]);
    if (wn < 15) {
        spi_buf.word[0] = READ_PERI_REG(SPI_W0(spi_no) + (wn+1)*4);
        spi_buf.word[0] = swap_endianess(spi_buf.word[0]);
    }

    shift = 64 - (offset & 0x1f) - bitlen;
    spi_buf.dword &= ~((1ULL << bitlen)-1 << shift);
    spi_buf.dword |= (uint64)data << shift;

    if (wn < 15) {
        WRITE_PERI_REG(SPI_W0(spi_no) + (wn+1)*4, swap_endianess(spi_buf.word[0]));
    }
    WRITE_PERI_REG(SPI_W0(spi_no) + wn*4, swap_endianess(spi_buf.word[1]));

    return;
}

uint32 spi_mast_get_miso(uint8 spi_no, uint16 offset, uint8 bitlen)
{
    uint8     wn;
    spi_buf_t spi_buf;
    uint32    result;

    if (spi_no > 1)
        return 0; // handle invalid input number

    // determine which SPI_Wn register is addressed
    wn = offset >> 5;
    if (wn > 15)
        return 0; // out of range

    while(READ_PERI_REG(SPI_CMD(spi_no)) & SPI_USR);

    // transfer Wn to buf
    spi_buf.word[1] = READ_PERI_REG(SPI_W0(spi_no) + wn*4);
    spi_buf.word[1] = swap_endianess(spi_buf.word[1]);
    if (wn < 15) {
        spi_buf.word[0] = READ_PERI_REG(SPI_W0(spi_no) + (wn+1)*4);
        spi_buf.word[0] = swap_endianess(spi_buf.word[0]);
    }

    result = (uint32)(spi_buf.dword >> (64 - ((offset & 0x1f) + bitlen)));
    result &= (1UL << bitlen)-1;

    return result;
}

void spi_mast_transaction(uint8 spi_no, uint8 cmd_bitlen, uint16 cmd_data, uint8 addr_bitlen, uint32 addr_data,
                          uint16 mosi_bitlen, uint8 dummy_bitlen, sint16 miso_bitlen)
{
    if (spi_no > 1)
        return; // handle invalid input number

    while(READ_PERI_REG(SPI_CMD(spi_no)) & SPI_USR);

    // default disable COMMAND, ADDR, MOSI, DUMMY, MISO, and DOUTDIN (aka full-duplex)
    CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_COMMAND|SPI_USR_ADDR|SPI_USR_MOSI|SPI_USR_DUMMY|SPI_USR_MISO|SPI_DOUTDIN);
    // default set bit lengths
    WRITE_PERI_REG(SPI_USER1(spi_no),
                   ((addr_bitlen - 1)  & SPI_USR_ADDR_BITLEN)    << SPI_USR_ADDR_BITLEN_S    |
                   ((mosi_bitlen - 1)  & SPI_USR_MOSI_BITLEN)    << SPI_USR_MOSI_BITLEN_S    |
                   ((dummy_bitlen - 1) & SPI_USR_DUMMY_CYCLELEN) << SPI_USR_DUMMY_CYCLELEN_S |
                   ((miso_bitlen - 1)  & SPI_USR_MISO_BITLEN)    << SPI_USR_MISO_BITLEN_S);

    // handle the transaction components
    if (cmd_bitlen > 0)
    {
        uint16 cmd = cmd_data << (16 - cmd_bitlen); // align to MSB
        cmd = (cmd >> 8) | (cmd << 8);              // swap byte order
        WRITE_PERI_REG(SPI_USER2(spi_no),
                       ((cmd_bitlen - 1 & SPI_USR_COMMAND_BITLEN) << SPI_USR_COMMAND_BITLEN_S) |
                       (cmd & SPI_USR_COMMAND_VALUE));
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_COMMAND);
    }
    if (addr_bitlen > 0)
    {
        WRITE_PERI_REG(SPI_ADDR(spi_no), addr_data << (32 - addr_bitlen));
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_ADDR);
    }
    if (mosi_bitlen > 0)
    {
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MOSI);
    }
    if (dummy_bitlen > 0)
    {
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_DUMMY);
    }
    if (miso_bitlen > 0)
    {
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MISO);
    }
    else if (miso_bitlen < 0)
    {
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_DOUTDIN);
    }

    // start transaction
    SET_PERI_REG_MASK(SPI_CMD(spi_no), SPI_USR);

    while(READ_PERI_REG(SPI_CMD(spi_no)) & SPI_USR);
}

void spi_byte_write_espslave(uint8 spi_no,uint8 data)
 {
	uint32 regvalue;

	if(spi_no>1) 		return; //handle invalid input number

	while(READ_PERI_REG(SPI_CMD(spi_no))&SPI_USR);
	SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MOSI);
	CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MISO|SPI_USR_ADDR|SPI_USR_DUMMY);

	//SPI_FLASH_USER2 bit28-31 is cmd length,cmd bit length is value(0-15)+1,
	// bit15-0 is cmd value.
	//0x70000000 is for 8bits cmd, 0x04 is eps8266 slave write cmd value
	WRITE_PERI_REG(SPI_USER2(spi_no),
					((7&SPI_USR_COMMAND_BITLEN)<<SPI_USR_COMMAND_BITLEN_S)|4);
	WRITE_PERI_REG(SPI_W0(spi_no), (uint32)(data));
	SET_PERI_REG_MASK(SPI_CMD(spi_no), SPI_USR);
 }

void spi_byte_read_espslave(uint8 spi_no,uint8 *data)
 {
	uint32 regvalue;

	if(spi_no>1) 		return; //handle invalid input number

	while(READ_PERI_REG(SPI_CMD(spi_no))&SPI_USR);

	SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MISO);
	CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MOSI|SPI_USR_ADDR|SPI_USR_DUMMY);
		//SPI_FLASH_USER2 bit28-31 is cmd length,cmd bit length is value(0-15)+1,
	// bit15-0 is cmd value.
	//0x70000000 is for 8bits cmd, 0x06 is eps8266 slave read cmd value
	WRITE_PERI_REG(SPI_USER2(spi_no),
					((7&SPI_USR_COMMAND_BITLEN)<<SPI_USR_COMMAND_BITLEN_S)|6);
	SET_PERI_REG_MASK(SPI_CMD(spi_no), SPI_USR);

	while(READ_PERI_REG(SPI_CMD(spi_no))&SPI_USR);
	*data=(uint8)(READ_PERI_REG(SPI_W0(spi_no))&0xff);
 }

void spi_slave_init(uint8 spi_no)
{
    uint32 regvalue;
    if(spi_no>1)
        return; //handle invalid input number

    //clear bit9,bit8 of reg PERIPHS_IO_MUX
    //bit9 should be cleared when HSPI clock doesn't equal CPU clock
    //bit8 should be cleared when SPI clock doesn't equal CPU clock
    ////WRITE_PERI_REG(PERIPHS_IO_MUX, 0x105); //clear bit9//TEST
    if(spi_no==SPI_SPI){
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_CLK_U, 1);//configure io to spi mode
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_CMD_U, 1);//configure io to spi mode
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA0_U, 1);//configure io to spi mode
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA1_U, 1);//configure io to spi mode
    }else if(spi_no==SPI_HSPI){
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, 2);//configure io to spi mode
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, 2);//configure io to spi mode
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U, 2);//configure io to spi mode
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, 2);//configure io to spi mode
    }

    //regvalue=READ_PERI_REG(SPI_FLASH_SLAVE(spi_no));
    //slave mode,slave use buffers which are register "SPI_FLASH_C0~C15", enable trans done isr
    //set bit 30 bit 29 bit9,bit9 is trans done isr mask
    SET_PERI_REG_MASK(	SPI_SLAVE(spi_no),
    						SPI_SLAVE_MODE|SPI_SLV_WR_RD_BUF_EN|
                                         	SPI_SLV_WR_BUF_DONE_EN|SPI_SLV_RD_BUF_DONE_EN|
                                         	SPI_SLV_WR_STA_DONE_EN|SPI_SLV_RD_STA_DONE_EN|
                                         	SPI_TRANS_DONE_EN);
    //disable general trans intr
    //CLEAR_PERI_REG_MASK(SPI_SLAVE(spi_no),SPI_TRANS_DONE_EN);

    CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_FLASH_MODE);//disable flash operation mode
    SET_PERI_REG_MASK(SPI_USER(spi_no),SPI_USR_MISO_HIGHPART);//SLAVE SEND DATA BUFFER IN C8-C15


//////**************RUN WHEN SLAVE RECIEVE*******************///////
   //tow lines below is to configure spi timing.
    SET_PERI_REG_MASK(SPI_CTRL2(spi_no),(0x2&SPI_MOSI_DELAY_NUM)<<SPI_MOSI_DELAY_NUM_S) ;//delay num
    os_printf("SPI_CTRL2 is %08x\n",READ_PERI_REG(SPI_CTRL2(spi_no)));
    WRITE_PERI_REG(SPI_CLOCK(spi_no), 0);



/////***************************************************//////

    //set 8 bit slave command length, because slave must have at least one bit addr,
    //8 bit slave+8bit addr, so master device first 2 bytes can be regarded as a command
    //and the  following bytes are datas,
    //32 bytes input wil be stored in SPI_FLASH_C0-C7
    //32 bytes output data should be set to SPI_FLASH_C8-C15
    WRITE_PERI_REG(SPI_USER2(spi_no), (0x7&SPI_USR_COMMAND_BITLEN)<<SPI_USR_COMMAND_BITLEN_S); //0x70000000

    //set 8 bit slave recieve buffer length, the buffer is SPI_FLASH_C0-C7
    //set 8 bit slave status register, which is the low 8 bit of register "SPI_FLASH_STATUS"
    SET_PERI_REG_MASK(SPI_SLAVE1(spi_no),  ((0xff&SPI_SLV_BUF_BITLEN)<< SPI_SLV_BUF_BITLEN_S)|
                                                                                        ((0x7&SPI_SLV_STATUS_BITLEN)<<SPI_SLV_STATUS_BITLEN_S)|
                                                                                       ((0x7&SPI_SLV_WR_ADDR_BITLEN)<<SPI_SLV_WR_ADDR_BITLEN_S)|
                                                                                       ((0x7&SPI_SLV_RD_ADDR_BITLEN)<<SPI_SLV_RD_ADDR_BITLEN_S));

    SET_PERI_REG_MASK(SPI_PIN(spi_no),BIT19);//BIT19

    //maybe enable slave transmission liston
    SET_PERI_REG_MASK(SPI_CMD(spi_no),SPI_USR);
    //register level2 isr function, which contains spi, hspi and i2s events
    ETS_SPI_INTR_ATTACH(spi_slave_isr_handler,NULL);
    //enable level2 isr, which contains spi, hspi and i2s events
    ETS_SPI_INTR_ENABLE();
}

