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
typedef  unsigned int u8 ;
typedef  unsigned int u32 ;
typedef  unsigned int u16 ;
struct TYPE_4__ {unsigned int* _8; void** _32; void** _16; } ;
struct oxygen {unsigned int** saved_ac97_registers; TYPE_1__* card; int /*<<< orphan*/  ac97_waitqueue; TYPE_2__ saved_registers; scalar_t__ addr; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EIO ; 
 unsigned int MPU401_ENTER_UART ; 
 unsigned int MPU401_RESET ; 
 int MPU401_TX_FULL ; 
 unsigned int OXYGEN_2WIRE_CONTROL ; 
 unsigned int OXYGEN_2WIRE_DATA ; 
 unsigned int OXYGEN_2WIRE_DIR_WRITE ; 
 unsigned int OXYGEN_2WIRE_MAP ; 
 unsigned int OXYGEN_AC97_INTERRUPT_STATUS ; 
 unsigned int OXYGEN_AC97_INT_READ_DONE ; 
 unsigned int OXYGEN_AC97_INT_WRITE_DONE ; 
 unsigned int OXYGEN_AC97_REGS ; 
 unsigned int OXYGEN_AC97_REG_ADDR_SHIFT ; 
 unsigned int OXYGEN_AC97_REG_CODEC_SHIFT ; 
 unsigned int OXYGEN_AC97_REG_DIR_READ ; 
 unsigned int OXYGEN_AC97_REG_DIR_WRITE ; 
 int OXYGEN_EEPROM_BUSY ; 
 unsigned int OXYGEN_EEPROM_CONTROL ; 
 unsigned int OXYGEN_EEPROM_DATA ; 
 unsigned int OXYGEN_EEPROM_DIR_READ ; 
 unsigned int OXYGEN_EEPROM_DIR_WRITE ; 
 unsigned int OXYGEN_EEPROM_STATUS ; 
 int OXYGEN_MPU401 ; 
 int OXYGEN_SPI_BUSY ; 
 unsigned int OXYGEN_SPI_CONTROL ; 
 unsigned int OXYGEN_SPI_DATA1 ; 
 unsigned int OXYGEN_SPI_DATA2 ; 
 unsigned int OXYGEN_SPI_DATA3 ; 
 unsigned int OXYGEN_SPI_DATA_LENGTH_3 ; 
 unsigned int UINT_MAX ; 
 void* cpu_to_le16 (unsigned int) ; 
 void* cpu_to_le32 (unsigned int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 unsigned int inb (scalar_t__) ; 
 unsigned int inl (scalar_t__) ; 
 unsigned int inw (scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  outb (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  outl (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  outw (unsigned int,scalar_t__) ; 
 void oxygen_write16_masked (struct oxygen*,unsigned int,unsigned int,unsigned int) ; 
 void oxygen_write32_masked (struct oxygen*,unsigned int,unsigned int,unsigned int) ; 
 void oxygen_write8_masked (struct oxygen*,unsigned int,unsigned int,unsigned int) ; 
 void oxygen_write_ac97_masked (struct oxygen*,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wait_event_timeout (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void oxygen_set_bits8(struct oxygen *chip,
				    unsigned int reg, u8 value)
{
	oxygen_write8_masked(chip, reg, value, value);
}

__attribute__((used)) static inline void oxygen_set_bits16(struct oxygen *chip,
				     unsigned int reg, u16 value)
{
	oxygen_write16_masked(chip, reg, value, value);
}

__attribute__((used)) static inline void oxygen_set_bits32(struct oxygen *chip,
				     unsigned int reg, u32 value)
{
	oxygen_write32_masked(chip, reg, value, value);
}

__attribute__((used)) static inline void oxygen_clear_bits8(struct oxygen *chip,
				      unsigned int reg, u8 value)
{
	oxygen_write8_masked(chip, reg, 0, value);
}

__attribute__((used)) static inline void oxygen_clear_bits16(struct oxygen *chip,
				       unsigned int reg, u16 value)
{
	oxygen_write16_masked(chip, reg, 0, value);
}

__attribute__((used)) static inline void oxygen_clear_bits32(struct oxygen *chip,
				       unsigned int reg, u32 value)
{
	oxygen_write32_masked(chip, reg, 0, value);
}

__attribute__((used)) static inline void oxygen_ac97_set_bits(struct oxygen *chip, unsigned int codec,
					unsigned int index, u16 value)
{
	oxygen_write_ac97_masked(chip, codec, index, value, value);
}

__attribute__((used)) static inline void oxygen_ac97_clear_bits(struct oxygen *chip,
					  unsigned int codec,
					  unsigned int index, u16 value)
{
	oxygen_write_ac97_masked(chip, codec, index, 0, value);
}

u8 oxygen_read8(struct oxygen *chip, unsigned int reg)
{
	return inb(chip->addr + reg);
}

u16 oxygen_read16(struct oxygen *chip, unsigned int reg)
{
	return inw(chip->addr + reg);
}

u32 oxygen_read32(struct oxygen *chip, unsigned int reg)
{
	return inl(chip->addr + reg);
}

void oxygen_write8(struct oxygen *chip, unsigned int reg, u8 value)
{
	outb(value, chip->addr + reg);
	chip->saved_registers._8[reg] = value;
}

void oxygen_write16(struct oxygen *chip, unsigned int reg, u16 value)
{
	outw(value, chip->addr + reg);
	chip->saved_registers._16[reg / 2] = cpu_to_le16(value);
}

void oxygen_write32(struct oxygen *chip, unsigned int reg, u32 value)
{
	outl(value, chip->addr + reg);
	chip->saved_registers._32[reg / 4] = cpu_to_le32(value);
}

void oxygen_write8_masked(struct oxygen *chip, unsigned int reg,
			  u8 value, u8 mask)
{
	u8 tmp = inb(chip->addr + reg);
	tmp &= ~mask;
	tmp |= value & mask;
	outb(tmp, chip->addr + reg);
	chip->saved_registers._8[reg] = tmp;
}

void oxygen_write16_masked(struct oxygen *chip, unsigned int reg,
			   u16 value, u16 mask)
{
	u16 tmp = inw(chip->addr + reg);
	tmp &= ~mask;
	tmp |= value & mask;
	outw(tmp, chip->addr + reg);
	chip->saved_registers._16[reg / 2] = cpu_to_le16(tmp);
}

void oxygen_write32_masked(struct oxygen *chip, unsigned int reg,
			   u32 value, u32 mask)
{
	u32 tmp = inl(chip->addr + reg);
	tmp &= ~mask;
	tmp |= value & mask;
	outl(tmp, chip->addr + reg);
	chip->saved_registers._32[reg / 4] = cpu_to_le32(tmp);
}

__attribute__((used)) static int oxygen_ac97_wait(struct oxygen *chip, unsigned int mask)
{
	u8 status = 0;

	/*
	 * Reading the status register also clears the bits, so we have to save
	 * the read bits in status.
	 */
	wait_event_timeout(chip->ac97_waitqueue,
			   ({ status |= oxygen_read8(chip, OXYGEN_AC97_INTERRUPT_STATUS);
			      status & mask; }),
			   msecs_to_jiffies(1) + 1);
	/*
	 * Check even after a timeout because this function should not require
	 * the AC'97 interrupt to be enabled.
	 */
	status |= oxygen_read8(chip, OXYGEN_AC97_INTERRUPT_STATUS);
	return status & mask ? 0 : -EIO;
}

void oxygen_write_ac97(struct oxygen *chip, unsigned int codec,
		       unsigned int index, u16 data)
{
	unsigned int count, succeeded;
	u32 reg;

	reg = data;
	reg |= index << OXYGEN_AC97_REG_ADDR_SHIFT;
	reg |= OXYGEN_AC97_REG_DIR_WRITE;
	reg |= codec << OXYGEN_AC97_REG_CODEC_SHIFT;
	succeeded = 0;
	for (count = 5; count > 0; --count) {
		udelay(5);
		oxygen_write32(chip, OXYGEN_AC97_REGS, reg);
		/* require two "completed" writes, just to be sure */
		if (oxygen_ac97_wait(chip, OXYGEN_AC97_INT_WRITE_DONE) >= 0 &&
		    ++succeeded >= 2) {
			chip->saved_ac97_registers[codec][index / 2] = data;
			return;
		}
	}
	dev_err(chip->card->dev, "AC'97 write timeout\n");
}

u16 oxygen_read_ac97(struct oxygen *chip, unsigned int codec,
		     unsigned int index)
{
	unsigned int count;
	unsigned int last_read = UINT_MAX;
	u32 reg;

	reg = index << OXYGEN_AC97_REG_ADDR_SHIFT;
	reg |= OXYGEN_AC97_REG_DIR_READ;
	reg |= codec << OXYGEN_AC97_REG_CODEC_SHIFT;
	for (count = 5; count > 0; --count) {
		udelay(5);
		oxygen_write32(chip, OXYGEN_AC97_REGS, reg);
		udelay(10);
		if (oxygen_ac97_wait(chip, OXYGEN_AC97_INT_READ_DONE) >= 0) {
			u16 value = oxygen_read16(chip, OXYGEN_AC97_REGS);
			/* we require two consecutive reads of the same value */
			if (value == last_read)
				return value;
			last_read = value;
			/*
			 * Invert the register value bits to make sure that two
			 * consecutive unsuccessful reads do not return the same
			 * value.
			 */
			reg ^= 0xffff;
		}
	}
	dev_err(chip->card->dev, "AC'97 read timeout on codec %u\n", codec);
	return 0;
}

void oxygen_write_ac97_masked(struct oxygen *chip, unsigned int codec,
			      unsigned int index, u16 data, u16 mask)
{
	u16 value = oxygen_read_ac97(chip, codec, index);
	value &= ~mask;
	value |= data & mask;
	oxygen_write_ac97(chip, codec, index, value);
}

__attribute__((used)) static int oxygen_wait_spi(struct oxygen *chip)
{
	unsigned int count;

	/*
	 * Higher timeout to be sure: 200 us;
	 * actual transaction should not need more than 40 us.
	 */
	for (count = 50; count > 0; count--) {
		udelay(4);
		if ((oxygen_read8(chip, OXYGEN_SPI_CONTROL) &
						OXYGEN_SPI_BUSY) == 0)
			return 0;
	}
	dev_err(chip->card->dev, "oxygen: SPI wait timeout\n");
	return -EIO;
}

int oxygen_write_spi(struct oxygen *chip, u8 control, unsigned int data)
{
	/*
	 * We need to wait AFTER initiating the SPI transaction,
	 * otherwise read operations will not work.
	 */
	oxygen_write8(chip, OXYGEN_SPI_DATA1, data);
	oxygen_write8(chip, OXYGEN_SPI_DATA2, data >> 8);
	if (control & OXYGEN_SPI_DATA_LENGTH_3)
		oxygen_write8(chip, OXYGEN_SPI_DATA3, data >> 16);
	oxygen_write8(chip, OXYGEN_SPI_CONTROL, control);
	return oxygen_wait_spi(chip);
}

void oxygen_write_i2c(struct oxygen *chip, u8 device, u8 map, u8 data)
{
	/* should not need more than about 300 us */
	msleep(1);

	oxygen_write8(chip, OXYGEN_2WIRE_MAP, map);
	oxygen_write8(chip, OXYGEN_2WIRE_DATA, data);
	oxygen_write8(chip, OXYGEN_2WIRE_CONTROL,
		      device | OXYGEN_2WIRE_DIR_WRITE);
}

__attribute__((used)) static void _write_uart(struct oxygen *chip, unsigned int port, u8 data)
{
	if (oxygen_read8(chip, OXYGEN_MPU401 + 1) & MPU401_TX_FULL)
		msleep(1);
	oxygen_write8(chip, OXYGEN_MPU401 + port, data);
}

void oxygen_reset_uart(struct oxygen *chip)
{
	_write_uart(chip, 1, MPU401_RESET);
	msleep(1); /* wait for ACK */
	_write_uart(chip, 1, MPU401_ENTER_UART);
}

void oxygen_write_uart(struct oxygen *chip, u8 data)
{
	_write_uart(chip, 0, data);
}

u16 oxygen_read_eeprom(struct oxygen *chip, unsigned int index)
{
	unsigned int timeout;

	oxygen_write8(chip, OXYGEN_EEPROM_CONTROL,
		      index | OXYGEN_EEPROM_DIR_READ);
	for (timeout = 0; timeout < 100; ++timeout) {
		udelay(1);
		if (!(oxygen_read8(chip, OXYGEN_EEPROM_STATUS)
		      & OXYGEN_EEPROM_BUSY))
			break;
	}
	return oxygen_read16(chip, OXYGEN_EEPROM_DATA);
}

void oxygen_write_eeprom(struct oxygen *chip, unsigned int index, u16 value)
{
	unsigned int timeout;

	oxygen_write16(chip, OXYGEN_EEPROM_DATA, value);
	oxygen_write8(chip, OXYGEN_EEPROM_CONTROL,
		      index | OXYGEN_EEPROM_DIR_WRITE);
	for (timeout = 0; timeout < 10; ++timeout) {
		msleep(1);
		if (!(oxygen_read8(chip, OXYGEN_EEPROM_STATUS)
		      & OXYGEN_EEPROM_BUSY))
			return;
	}
	dev_err(chip->card->dev, "EEPROM write timeout\n");
}

