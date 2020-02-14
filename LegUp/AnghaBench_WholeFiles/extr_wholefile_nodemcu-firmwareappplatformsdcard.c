#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  int uint16_t ;
struct TYPE_4__ {scalar_t__ start; scalar_t__ target; } ;
typedef  TYPE_1__ to_t ;

/* Variables and functions */
 int ACMD23 ; 
 int ACMD41 ; 
 int /*<<< orphan*/  CHECK_SSPIN (int) ; 
 int CMD0 ; 
 int CMD10 ; 
 int CMD12 ; 
 int CMD17 ; 
 int CMD18 ; 
 int CMD24 ; 
 int CMD25 ; 
 int CMD55 ; 
 int CMD58 ; 
 int CMD8 ; 
 int CMD9 ; 
 int DATA_RES_ACCEPTED ; 
 int DATA_RES_MASK ; 
 int DATA_START_BLOCK ; 
 int FALSE ; 
 unsigned int NUM_ADC ; 
 unsigned int NUM_CAN ; 
 unsigned int NUM_GPIO ; 
 unsigned int NUM_I2C ; 
 unsigned int NUM_OW ; 
 unsigned int NUM_PWM ; 
 unsigned int NUM_SPI ; 
 unsigned int NUM_TMR ; 
 unsigned int NUM_UART ; 
 int /*<<< orphan*/  PLATFORM_GPIO_FLOAT ; 
 int /*<<< orphan*/  PLATFORM_GPIO_HIGH ; 
 int /*<<< orphan*/  PLATFORM_GPIO_LOW ; 
 int /*<<< orphan*/  PLATFORM_GPIO_OUTPUT ; 
 int R1_IDLE_STATE ; 
 int R1_ILLEGAL_COMMAND ; 
 scalar_t__ R1_READY_STATE ; 
 int SD_CARD_ERROR_ACMD23 ; 
 int SD_CARD_ERROR_CMD12 ; 
 int SD_CARD_ERROR_CMD17 ; 
 int SD_CARD_ERROR_CMD18 ; 
 int SD_CARD_ERROR_CMD24 ; 
 int SD_CARD_ERROR_CMD25 ; 
 int SD_CARD_ERROR_CMD58 ; 
 int SD_CARD_ERROR_READ ; 
 int SD_CARD_ERROR_READ_REG ; 
 int SD_CARD_ERROR_STOP_TRAN ; 
 int SD_CARD_ERROR_WRITE ; 
 int SD_CARD_ERROR_WRITE_MULTIPLE ; 
 scalar_t__ SD_CARD_TYPE_INVALID ; 
 scalar_t__ SD_CARD_TYPE_SD1 ; 
 scalar_t__ SD_CARD_TYPE_SD2 ; 
 scalar_t__ SD_CARD_TYPE_SDHC ; 
 int STOP_TRAN_TOKEN ; 
 int TRUE ; 
 int WRITE_MULTIPLE_TOKEN ; 
 int m_error ; 
 int m_spi_no ; 
 int /*<<< orphan*/  m_ss_pin ; 
 int m_status ; 
 scalar_t__ m_type ; 
 int /*<<< orphan*/  platform_gpio_mode (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_gpio_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_spi_blkread (int,size_t,void*) ; 
 int /*<<< orphan*/  platform_spi_blkwrite (int,int,int const*) ; 
 int platform_spi_send_recv (int,int,int) ; 
 int /*<<< orphan*/  platform_spi_transaction (int,int,int,int,scalar_t__,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ spi_set_clkdiv (int,scalar_t__) ; 
 void* system_get_time () ; 

__attribute__((used)) static inline int platform_gpio_exists( unsigned pin ) { return pin < NUM_GPIO; }

__attribute__((used)) static inline int platform_can_exists( unsigned id ) { return NUM_CAN && (id < NUM_CAN); }

__attribute__((used)) static inline int platform_spi_exists( unsigned id ) { return id < NUM_SPI; }

__attribute__((used)) static inline int platform_uart_exists( unsigned id ) { return id < NUM_UART; }

__attribute__((used)) static inline int platform_pwm_exists( unsigned id ) { return ((id < NUM_PWM) && (id > 0)); }

__attribute__((used)) static inline int platform_adc_exists( unsigned id ) { return id < NUM_ADC; }

__attribute__((used)) static inline int platform_ow_exists( unsigned id ) { return ((id < NUM_OW) && (id > 0)); }

__attribute__((used)) static inline int platform_tmr_exists( unsigned id ) { return id < NUM_TMR; }

__attribute__((used)) static inline int platform_sigma_delta_exists( unsigned id ) {return ((id < NUM_GPIO) && (id > 0)); }

__attribute__((used)) static inline int platform_i2c_exists( unsigned id ) { return id < NUM_I2C; }

__attribute__((used)) static void sdcard_chipselect_low( void ) {
  platform_gpio_write( m_ss_pin, PLATFORM_GPIO_LOW );
}

__attribute__((used)) static void sdcard_chipselect_high( void ) {
  platform_gpio_write( m_ss_pin, PLATFORM_GPIO_HIGH );
  // send some cc to ensure that MISO returns to high
  platform_spi_send_recv( m_spi_no, 8, 0xff );
}

__attribute__((used)) static void set_timeout( to_t *to, uint32_t us )
{
  uint32_t offset;

  to->start = system_get_time();

  offset = 0xffffffff - to->start;
  if (offset > us) {
    to->target = us - offset;
  } else {
    to->target = to->start + us;
  }
}

__attribute__((used)) static uint8_t timed_out( to_t *to )
{
  uint32_t now = system_get_time();

  if (to->start < to->target) {
    if ((now >= to->start) && (now <= to->target)) {
      return FALSE;
    } else {
      return TRUE;
    }
  } else {
    if ((now >= to->start) || (now <= to->target)) {
      return FALSE;
    } else {
      return TRUE;
    }
  }
}

__attribute__((used)) static int sdcard_wait_not_busy( uint32_t us )
{
  to_t to;

  set_timeout( &to, us );
  while (platform_spi_send_recv( m_spi_no, 8, 0xff ) != 0xff) {
    if (timed_out( &to )) {
      goto fail;
    }
  }
  return TRUE;

  fail:
  return FALSE;
}

__attribute__((used)) static uint8_t sdcard_command( uint8_t cmd, uint32_t arg )
{
  sdcard_chipselect_low();

  // wait until card is busy
  sdcard_wait_not_busy( 100 * 1000 );

  // send command
  // with precalculated CRC - correct for CMD0 with arg zero or CMD8 with arg 0x1AA
  const uint8_t crc = cmd == CMD0 ? 0x95 : 0x87;
  platform_spi_transaction( m_spi_no, 16, (cmd | 0x40) << 8 | arg >> 24, 32, arg << 8 | crc, 0, 0, 0 );

  // skip dangling byte of data transfer
  if (cmd == CMD12) {
    platform_spi_transaction( m_spi_no, 8, 0xff, 0, 0, 0, 0, 0 );
  }

  // wait for response
  for (uint8_t i = 0; ((m_status = platform_spi_send_recv( m_spi_no, 8, 0xff )) & 0x80) && i != 0xFF; i++) ;

  return m_status;
}

__attribute__((used)) static uint8_t sdcard_acmd( uint8_t cmd, uint32_t arg ) {
  sdcard_command( CMD55, 0 );
  return sdcard_command( cmd, arg );
}

__attribute__((used)) static int sdcard_write_data( uint8_t token, const uint8_t *src)
{
  uint16_t crc = 0xffff;

  platform_spi_transaction( m_spi_no, 8, token, 0, 0, 0, 0, 0 );
  platform_spi_blkwrite( m_spi_no, 512, src );
  platform_spi_transaction( m_spi_no, 16, crc, 0, 0, 0, 0, 0 );

  m_status = platform_spi_send_recv( m_spi_no, 8, 0xff );
  if ((m_status & DATA_RES_MASK) != DATA_RES_ACCEPTED) {
    m_error = SD_CARD_ERROR_WRITE;
    goto fail;
  }
  return TRUE;

  fail:
  sdcard_chipselect_high();
  return FALSE;
}

__attribute__((used)) static int sdcard_read_data( uint8_t *dst, size_t count )
{
  to_t to;

  // wait for start block token
  set_timeout( &to, 100 * 1000 );
  while ((m_status = platform_spi_send_recv( m_spi_no, 8, 0xff)) == 0xff) {
    if (timed_out( &to )) {
      goto fail;
    }
  }

  if (m_status != DATA_START_BLOCK) {
    m_error = SD_CARD_ERROR_READ;
    goto fail;
  }
  // transfer data
  platform_spi_blkread( m_spi_no, count, (void *)dst );

  // discard crc
  platform_spi_transaction( m_spi_no, 16, 0xffff, 0, 0, 0, 0, 0 );

  sdcard_chipselect_high();
  return TRUE;

  fail:
  sdcard_chipselect_high();
  return FALSE;
}

__attribute__((used)) static int sdcard_read_register( uint8_t cmd, uint8_t *buf )
{
  if (sdcard_command( cmd, 0 )) {
    m_error = SD_CARD_ERROR_READ_REG;
    goto fail;
  }
  return sdcard_read_data( buf, 16 );

  fail:
  sdcard_chipselect_high();
  return FALSE;
}

int platform_sdcard_init( uint8_t spi_no, uint8_t ss_pin )
{
  uint32_t arg, user_spi_clkdiv;
  to_t to;

  m_type = SD_CARD_TYPE_INVALID;
  m_error = 0;

  if (spi_no > 1) {
    return FALSE;
  }
  m_spi_no = spi_no;
  CHECK_SSPIN(ss_pin);

  platform_gpio_write( m_ss_pin, PLATFORM_GPIO_HIGH );
  platform_gpio_mode( m_ss_pin, PLATFORM_GPIO_OUTPUT, PLATFORM_GPIO_FLOAT );

  // set SPI clock to 400 kHz for init phase
  user_spi_clkdiv = spi_set_clkdiv( m_spi_no, 200 );

  // apply initialization sequence:
  // keep ss and io high, apply clock for max(1ms; 74cc)
  // 1ms requires 400cc @ 400kHz
  for (int i = 0; i < 2; i++) {
    platform_spi_transaction( m_spi_no, 0, 0, 0, 0, 0, 200, 0 );
  }

  // command to go idle in SPI mode
  set_timeout( &to, 500 * 1000 );
  while (sdcard_command( CMD0, 0 ) != R1_IDLE_STATE) {
    if (timed_out( &to )) {
      goto fail;
    }
  }

  set_timeout( &to, 500 * 1000 );
  while (1) {
    if (sdcard_command( CMD8, 0x1aa) == (R1_ILLEGAL_COMMAND | R1_IDLE_STATE)) {
      m_type = SD_CARD_TYPE_SD1;
      break;
    }
    for (uint8_t i = 0; i < 4; i++) {
      m_status = platform_spi_send_recv( m_spi_no, 8, 0xff );
    }
    if (m_status == 0xaa) {
      m_type = SD_CARD_TYPE_SD2;
      break;
    }
    if (timed_out( &to )) {
      goto fail;
    }
  }
  // initialize card and send host supports SDHC if SD2
  arg = m_type == SD_CARD_TYPE_SD2 ? 0x40000000 : 0;

  set_timeout( &to, 500 * 1000 );
  while (sdcard_acmd( ACMD41, arg ) != R1_READY_STATE) {
    if (timed_out( &to )) {
      goto fail;
    }
  }
  // if SD2 read OCR register to check for SDHC card
  if (m_type == SD_CARD_TYPE_SD2) {
    if (sdcard_command( CMD58, 0 )) {
      m_error = SD_CARD_ERROR_CMD58;
      goto fail;
    }
    if ((platform_spi_send_recv( m_spi_no, 8, 0xff ) & 0xC0) == 0xC0) {
      m_type = SD_CARD_TYPE_SDHC;
    }
    // Discard rest of ocr - contains allowed voltage range.
    for (uint8_t i = 0; i < 3; i++) {
      platform_spi_send_recv( m_spi_no, 8, 0xff);
    }
  }
  sdcard_chipselect_high();

  // re-apply user's spi clock divider
  spi_set_clkdiv( m_spi_no, user_spi_clkdiv );

  return TRUE;

  fail:
  sdcard_chipselect_high();
  return FALSE;
}

int platform_sdcard_status( void )
{
  return m_status;
}

int platform_sdcard_error( void )
{
  return m_error;
}

int platform_sdcard_type( void )
{
  return m_type;
}

int platform_sdcard_read_block( uint8_t ss_pin, uint32_t block, uint8_t *dst )
{
  CHECK_SSPIN(ss_pin);

  // generate byte address for pre-SDHC types
  if (m_type != SD_CARD_TYPE_SDHC) {
    block <<= 9;
  }
  if (sdcard_command( CMD17, block )) {
    m_error = SD_CARD_ERROR_CMD17;
    goto fail;
  }
  return sdcard_read_data( dst, 512 );

  fail:
  sdcard_chipselect_high();
  return FALSE;
}

int platform_sdcard_read_blocks( uint8_t ss_pin, uint32_t block, size_t num, uint8_t *dst )
{
  CHECK_SSPIN(ss_pin);

  if (num == 0) {
    return TRUE;
  }
  if (num == 1) {
    return platform_sdcard_read_block( ss_pin, block, dst );
  }

  // generate byte address for pre-SDHC types
  if (m_type != SD_CARD_TYPE_SDHC) {
    block <<= 9;
  }

  // command READ_MULTIPLE_BLOCKS
  if (sdcard_command( CMD18, block )) {
    m_error = SD_CARD_ERROR_CMD18;
    goto fail;
  }

  // read required blocks
  while (num > 0) {
    sdcard_chipselect_low();
    if (sdcard_read_data( dst, 512 )) {
      num--;
      dst = &(dst[512]);
    } else {
      break;
    }
  }

  // issue command STOP_TRANSMISSION
  if (sdcard_command( CMD12, 0 )) {
    m_error = SD_CARD_ERROR_CMD12;
    goto fail;
  }
  sdcard_chipselect_high();
  return TRUE;

  fail:
  sdcard_chipselect_high();
  return FALSE;
}

int platform_sdcard_read_csd( uint8_t ss_pin, uint8_t *csd )
{
  CHECK_SSPIN(ss_pin);

  return sdcard_read_register( CMD9, csd );
}

int platform_sdcard_read_cid( uint8_t ss_pin, uint8_t *cid )
{
  CHECK_SSPIN(ss_pin);

  return sdcard_read_register( CMD10, cid );
}

int platform_sdcard_write_block( uint8_t ss_pin, uint32_t block, const uint8_t *src )
{
  CHECK_SSPIN(ss_pin);

  // generate byte address for pre-SDHC types
  if (m_type != SD_CARD_TYPE_SDHC) {
    block <<= 9;
  }
  if (sdcard_command( CMD24, block )) {
    m_error = SD_CARD_ERROR_CMD24;
    goto fail;
  }
  if (! sdcard_write_data( DATA_START_BLOCK, src )) {
    goto fail;
  }

  sdcard_chipselect_high();
  return TRUE;

  fail:
  sdcard_chipselect_high();
  return FALSE;
}

__attribute__((used)) static int sdcard_write_stop( void )
{
  sdcard_chipselect_low();

  if (! sdcard_wait_not_busy( 100 * 1000 )) {
    goto fail;
  }
  platform_spi_transaction( m_spi_no, 8, STOP_TRAN_TOKEN, 0, 0, 0, 0, 0 );
  if (! sdcard_wait_not_busy( 100 * 1000 )) {
    goto fail;
  }

  sdcard_chipselect_high();
  return TRUE;

  fail:
  m_error = SD_CARD_ERROR_STOP_TRAN;
  sdcard_chipselect_high();
  return FALSE;
}

int platform_sdcard_write_blocks( uint8_t ss_pin, uint32_t block, size_t num, const uint8_t *src )
{
  CHECK_SSPIN(ss_pin);

  if (sdcard_acmd( ACMD23, num )) {
    m_error = SD_CARD_ERROR_ACMD23;
    goto fail;
  }
  // generate byte address for pre-SDHC types
  if (m_type != SD_CARD_TYPE_SDHC) {
    block <<= 9;
  }
  if (sdcard_command( CMD25, block )) {
    m_error = SD_CARD_ERROR_CMD25;
    goto fail;
  }
  sdcard_chipselect_high();

  for (size_t b = 0; b < num; b++, src += 512) {
    sdcard_chipselect_low();

    // wait for previous write to finish
    if (! sdcard_wait_not_busy( 100 * 1000 )) {
      goto fail_write;
    }
    if (! sdcard_write_data( WRITE_MULTIPLE_TOKEN, src )) {
      goto fail_write;
    }

    sdcard_chipselect_high();
  }

  return sdcard_write_stop();

  fail_write:
  m_error = SD_CARD_ERROR_WRITE_MULTIPLE;
  fail:
  sdcard_chipselect_high();
  return FALSE;
}

