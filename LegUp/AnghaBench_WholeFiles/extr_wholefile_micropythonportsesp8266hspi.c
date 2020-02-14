#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;

/* Variables and functions */
 int /*<<< orphan*/  CLEAR_PERI_REG_MASK (int /*<<< orphan*/ ,int) ; 
 scalar_t__ HSPI ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_MTCK_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_MTDI_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_MTMS_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_SD_CLK_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_SD_CMD_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_SD_DATA0_U ; 
 int /*<<< orphan*/  PERIPHS_IO_MUX_SD_DATA1_U ; 
 int /*<<< orphan*/  PIN_FUNC_SELECT (int /*<<< orphan*/ ,int) ; 
 int READ_PERI_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SET_PERI_REG_MASK (int /*<<< orphan*/ ,int) ; 
 scalar_t__ SPI ; 
 int /*<<< orphan*/  SPI_ADDR (scalar_t__) ; 
 scalar_t__ SPI_BYTE_ORDER_HIGH_TO_LOW ; 
 int SPI_CK_I_EDGE ; 
 int SPI_CK_OUT_EDGE ; 
 scalar_t__ SPI_CLKCNT_H ; 
 scalar_t__ SPI_CLKCNT_H_S ; 
 int SPI_CLKCNT_L ; 
 int SPI_CLKCNT_L_S ; 
 scalar_t__ SPI_CLKCNT_N ; 
 scalar_t__ SPI_CLKCNT_N_S ; 
 int SPI_CLKDIV_PRE ; 
 int SPI_CLKDIV_PRE_S ; 
 scalar_t__ SPI_CLK_CNTDIV ; 
 scalar_t__ SPI_CLK_EQU_SYSCLK ; 
 int SPI_CLK_PREDIV ; 
 scalar_t__ SPI_CLK_USE_DIV ; 
 int /*<<< orphan*/  SPI_CLOCK (scalar_t__) ; 
 int /*<<< orphan*/  SPI_CMD (scalar_t__) ; 
 int SPI_CS_HOLD ; 
 int SPI_CS_SETUP ; 
 int SPI_DOUTDIN ; 
 int SPI_FLASH_MODE ; 
 int SPI_IDLE_EDGE ; 
 int /*<<< orphan*/  SPI_PIN (scalar_t__) ; 
 int SPI_RD_BYTE_ORDER ; 
 int /*<<< orphan*/  SPI_USER (scalar_t__) ; 
 int /*<<< orphan*/  SPI_USER1 (scalar_t__) ; 
 int /*<<< orphan*/  SPI_USER2 (scalar_t__) ; 
 int SPI_USR ; 
 int SPI_USR_ADDR ; 
 int SPI_USR_ADDR_BITLEN ; 
 int SPI_USR_ADDR_BITLEN_S ; 
 int SPI_USR_COMMAND ; 
 scalar_t__ SPI_USR_COMMAND_BITLEN ; 
 scalar_t__ SPI_USR_COMMAND_BITLEN_S ; 
 int SPI_USR_COMMAND_VALUE ; 
 int SPI_USR_DUMMY ; 
 int SPI_USR_DUMMY_CYCLELEN ; 
 int SPI_USR_DUMMY_CYCLELEN_S ; 
 int SPI_USR_MISO ; 
 int SPI_USR_MISO_BITLEN ; 
 int SPI_USR_MISO_BITLEN_S ; 
 int SPI_USR_MOSI ; 
 int SPI_USR_MOSI_BITLEN ; 
 int SPI_USR_MOSI_BITLEN_S ; 
 int /*<<< orphan*/  SPI_W0 (scalar_t__) ; 
 int SPI_WR_BYTE_ORDER ; 
 int /*<<< orphan*/  WRITE_PERI_REG (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ spi_busy (scalar_t__) ; 
 void spi_clock (scalar_t__,int,scalar_t__) ; 
 void spi_init_gpio (scalar_t__,scalar_t__) ; 
 void spi_rx_byte_order (scalar_t__,scalar_t__) ; 
 void spi_tx_byte_order (scalar_t__,scalar_t__) ; 

void spi_init(uint8_t spi_no) {
    spi_init_gpio(spi_no, SPI_CLK_USE_DIV);
    spi_clock(spi_no, SPI_CLK_PREDIV, SPI_CLK_CNTDIV);
    spi_tx_byte_order(spi_no, SPI_BYTE_ORDER_HIGH_TO_LOW);
    spi_rx_byte_order(spi_no, SPI_BYTE_ORDER_HIGH_TO_LOW);

    SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_CS_SETUP|SPI_CS_HOLD);
    CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_FLASH_MODE);
}

void spi_mode(uint8_t spi_no, uint8_t spi_cpha, uint8_t spi_cpol) {
    if (spi_cpol) {
        SET_PERI_REG_MASK(SPI_PIN(HSPI), SPI_IDLE_EDGE);
    } else {
        CLEAR_PERI_REG_MASK(SPI_PIN(HSPI), SPI_IDLE_EDGE);
    }
    if (spi_cpha == spi_cpol) {
        // Mode 3 - MOSI is set on falling edge of clock
        // Mode 0 - MOSI is set on falling edge of clock
        CLEAR_PERI_REG_MASK(SPI_USER(HSPI), SPI_CK_OUT_EDGE);
        SET_PERI_REG_MASK(SPI_USER(HSPI), SPI_CK_I_EDGE);
    } else {
        // Mode 2 - MOSI is set on rising edge of clock
        // Mode 1 - MOSI is set on rising edge of clock
        SET_PERI_REG_MASK(SPI_USER(HSPI), SPI_CK_OUT_EDGE);
        CLEAR_PERI_REG_MASK(SPI_USER(HSPI), SPI_CK_I_EDGE);
    }
}

void spi_init_gpio(uint8_t spi_no, uint8_t sysclk_as_spiclk) {
    uint32_t clock_div_flag = 0;
    if (sysclk_as_spiclk) {
        clock_div_flag = 0x0001;
    }
    if (spi_no == SPI) {
        // Set bit 8 if 80MHz sysclock required
        WRITE_PERI_REG(PERIPHS_IO_MUX, 0x005 | (clock_div_flag<<8));
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_CLK_U, 1);
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_CMD_U, 1);
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA0_U, 1);
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_SD_DATA1_U, 1);
    } else if (spi_no == HSPI) {
        // Set bit 9 if 80MHz sysclock required
        WRITE_PERI_REG(PERIPHS_IO_MUX, 0x105 | (clock_div_flag<<9));
        // GPIO12 is HSPI MISO pin (Master Data In)
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, 2);
        // GPIO13 is HSPI MOSI pin (Master Data Out)
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, 2);
        // GPIO14 is HSPI CLK pin (Clock)
        PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U, 2);
        // GPIO15 is HSPI CS pin (Chip Select / Slave Select)
        // In MicroPython, we are handling CS ourself in drivers.
        // PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, 2);
    }
}

void spi_clock(uint8_t spi_no, uint16_t prediv, uint8_t cntdiv) {
    if (prediv == 0 || cntdiv == 0) {
        WRITE_PERI_REG(SPI_CLOCK(spi_no), SPI_CLK_EQU_SYSCLK);
    } else {
        WRITE_PERI_REG(SPI_CLOCK(spi_no),
           (((prediv - 1) & SPI_CLKDIV_PRE) << SPI_CLKDIV_PRE_S) |
           (((cntdiv - 1) & SPI_CLKCNT_N) << SPI_CLKCNT_N_S) |
           (((cntdiv >> 1) & SPI_CLKCNT_H) << SPI_CLKCNT_H_S) |
           ((0 & SPI_CLKCNT_L) << SPI_CLKCNT_L_S)
        );
    }
}

void spi_tx_byte_order(uint8_t spi_no, uint8_t byte_order) {
    if (byte_order) {
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_WR_BYTE_ORDER);
    } else {
        CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_WR_BYTE_ORDER);
    }
}

void spi_rx_byte_order(uint8_t spi_no, uint8_t byte_order) {
    if (byte_order) {
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_RD_BYTE_ORDER);
    } else {
        CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_RD_BYTE_ORDER);
    }
}

uint32_t spi_transaction(uint8_t spi_no, uint8_t cmd_bits, uint16_t cmd_data,
                         uint32_t addr_bits, uint32_t addr_data,
                         uint32_t dout_bits, uint32_t dout_data,
                         uint32_t din_bits, uint32_t dummy_bits) {
    while (spi_busy(spi_no)) {};  // Wait for SPI to be ready

// Enable SPI Functions
    // Disable MOSI, MISO, ADDR, COMMAND, DUMMY in case previously set.
    CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MOSI | SPI_USR_MISO |
                        SPI_USR_COMMAND | SPI_USR_ADDR | SPI_USR_DUMMY);

    // Enable functions based on number of bits. 0 bits = disabled.
    // This is rather inefficient but allows for a very generic function.
    // CMD ADDR and MOSI are set below to save on an extra if statement.
    if (din_bits) {
        if (dout_bits) {
            SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_DOUTDIN);
        } else {
            SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MISO);
        }
    }
    if (dummy_bits) {
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_DUMMY);
    }

// Setup Bitlengths
    WRITE_PERI_REG(SPI_USER1(spi_no),
        // Number of bits in Address
        ((addr_bits - 1) & SPI_USR_ADDR_BITLEN) << SPI_USR_ADDR_BITLEN_S |
        // Number of bits to Send
        ((dout_bits - 1) & SPI_USR_MOSI_BITLEN) << SPI_USR_MOSI_BITLEN_S |
        // Number of bits to receive
        ((din_bits - 1) & SPI_USR_MISO_BITLEN) << SPI_USR_MISO_BITLEN_S |
        // Number of Dummy bits to insert
        ((dummy_bits - 1) & SPI_USR_DUMMY_CYCLELEN) << SPI_USR_DUMMY_CYCLELEN_S);

// Setup Command Data
    if (cmd_bits) {
        // Enable COMMAND function in SPI module
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_COMMAND);
        // Align command data to high bits
        uint16_t command = cmd_data << (16-cmd_bits);
        // Swap byte order
        command = ((command>>8)&0xff) | ((command<<8)&0xff00);
        WRITE_PERI_REG(SPI_USER2(spi_no), (
            (((cmd_bits - 1) & SPI_USR_COMMAND_BITLEN) << SPI_USR_COMMAND_BITLEN_S) |
            (command & SPI_USR_COMMAND_VALUE)
        ));
    }

// Setup Address Data
    if (addr_bits) {
        // Enable ADDRess function in SPI module
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_ADDR);
        // Align address data to high bits
        WRITE_PERI_REG(SPI_ADDR(spi_no), addr_data << (32 - addr_bits));
    }

// Setup DOUT data
    if (dout_bits) {
        // Enable MOSI function in SPI module
        SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MOSI);
    // Copy data to W0
    if (READ_PERI_REG(SPI_USER(spi_no))&SPI_WR_BYTE_ORDER) {
        WRITE_PERI_REG(SPI_W0(spi_no), dout_data << (32 - dout_bits));
    } else {
        uint8_t dout_extra_bits = dout_bits%8;

        if (dout_extra_bits) {
            // If your data isn't a byte multiple (8/16/24/32 bits) and you
            // don't have SPI_WR_BYTE_ORDER set, you need this to move the
            // non-8bit remainder to the MSBs. Not sure if there's even a use
            // case for this, but it's here if you need it... For example,
            // 0xDA4 12 bits without SPI_WR_BYTE_ORDER would usually be output
            // as if it were 0x0DA4, of which 0xA4, and then 0x0 would be
            // shifted out (first 8 bits of low byte, then 4 MSB bits of high
            // byte - ie reverse byte order).
            // The code below shifts it out as 0xA4 followed by 0xD as you
            // might require.
            WRITE_PERI_REG(SPI_W0(spi_no), (
                (0xFFFFFFFF << (dout_bits - dout_extra_bits) & dout_data)
                    << (8-dout_extra_bits) |
                ((0xFFFFFFFF >> (32 - (dout_bits - dout_extra_bits)))
                    & dout_data)
            ));
        } else {
            WRITE_PERI_REG(SPI_W0(spi_no), dout_data);
        }
    }
}

// Begin SPI Transaction
    SET_PERI_REG_MASK(SPI_CMD(spi_no), SPI_USR);

// Return DIN data
    if (din_bits) {
        while (spi_busy(spi_no)) {}; // Wait for SPI transaction to complete
        if (READ_PERI_REG(SPI_USER(spi_no))&SPI_RD_BYTE_ORDER) {
            // Assuming data in is written to MSB. TBC
            return READ_PERI_REG(SPI_W0(spi_no)) >> (32 - din_bits);
        } else {
            // Read in the same way as DOUT is sent. Note existing contents of
            // SPI_W0 remain unless overwritten!
            return READ_PERI_REG(SPI_W0(spi_no));
        }
        return 0; // Something went wrong
    }

    // Transaction completed
    return 1; // Success
}

inline void spi_tx8fast(uint8_t spi_no, uint8_t dout_data) {
    while (spi_busy(spi_no)) {};  // Wait for SPI to be ready

// Enable SPI Functions
    // Disable MOSI, MISO, ADDR, COMMAND, DUMMY in case previously set.
    CLEAR_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MOSI | SPI_USR_MISO |
                        SPI_USR_COMMAND | SPI_USR_ADDR | SPI_USR_DUMMY);

// Setup Bitlengths
    WRITE_PERI_REG(SPI_USER1(spi_no),
        // Number of bits to Send
        ((8 - 1) & SPI_USR_MOSI_BITLEN) << SPI_USR_MOSI_BITLEN_S |
        // Number of bits to receive
        ((8 - 1) & SPI_USR_MISO_BITLEN) << SPI_USR_MISO_BITLEN_S);


// Setup DOUT data
    // Enable MOSI function in SPI module
    SET_PERI_REG_MASK(SPI_USER(spi_no), SPI_USR_MOSI);
    // Copy data to W0
    if (READ_PERI_REG(SPI_USER(spi_no)) & SPI_WR_BYTE_ORDER) {
        WRITE_PERI_REG(SPI_W0(spi_no), dout_data << (32 - 8));
    } else {
        WRITE_PERI_REG(SPI_W0(spi_no), dout_data);
    }

// Begin SPI Transaction
    SET_PERI_REG_MASK(SPI_CMD(spi_no), SPI_USR);
}

