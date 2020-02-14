#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_9__ ;
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  mp_obj_t ;
typedef  int /*<<< orphan*/  gcSpiHandleRx ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_20__ {int /*<<< orphan*/  pin_mask; int /*<<< orphan*/  gpio; } ;
struct TYPE_19__ {int /*<<< orphan*/  pin_mask; int /*<<< orphan*/  gpio; } ;
struct TYPE_18__ {int /*<<< orphan*/  pin; int /*<<< orphan*/  pin_mask; int /*<<< orphan*/  gpio; } ;
struct TYPE_17__ {unsigned char* pRxPacket; scalar_t__ ulSpiState; unsigned short usTxPacketLength; unsigned char* pTxPacket; scalar_t__ usRxPacketLength; int /*<<< orphan*/  SPIRxHandler; } ;
struct TYPE_16__ {TYPE_10__* spi; } ;
struct TYPE_15__ {scalar_t__ (* ReadWlanInterruptPin ) () ;int /*<<< orphan*/  (* WlanInterruptEnable ) () ;int /*<<< orphan*/  (* WlanInterruptDisable ) () ;} ;
struct TYPE_14__ {int /*<<< orphan*/  Pin; scalar_t__ Alternate; int /*<<< orphan*/  Pull; int /*<<< orphan*/  Mode; int /*<<< orphan*/  Speed; } ;
struct TYPE_13__ {int CRCPolynomial; int /*<<< orphan*/  CRCCalculation; int /*<<< orphan*/  TIMode; int /*<<< orphan*/  FirstBit; int /*<<< orphan*/  BaudRatePrescaler; int /*<<< orphan*/  NSS; int /*<<< orphan*/  CLKPhase; int /*<<< orphan*/  CLKPolarity; int /*<<< orphan*/  DataSize; int /*<<< orphan*/  Direction; int /*<<< orphan*/  Mode; } ;
struct TYPE_12__ {TYPE_1__ Init; } ;
typedef  TYPE_1__ SPI_InitTypeDef ;
typedef  TYPE_2__ GPIO_InitTypeDef ;

/* Variables and functions */
 scalar_t__ CC3000_BUFFER_MAGIC_NUMBER ; 
 int CC3000_RX_BUFFER_SIZE ; 
 int CC3000_TX_BUFFER_SIZE ; 
 int /*<<< orphan*/  CS_HIGH () ; 
 int /*<<< orphan*/  CS_LOW () ; 
 int /*<<< orphan*/  DEBUG_printf (char*,...) ; 
 int /*<<< orphan*/  GPIO_MODE_IT_FALLING ; 
 int /*<<< orphan*/  GPIO_MODE_OUTPUT_PP ; 
 int /*<<< orphan*/  GPIO_NOPULL ; 
 int /*<<< orphan*/  GPIO_PIN_RESET ; 
 int /*<<< orphan*/  GPIO_PIN_SET ; 
 int /*<<< orphan*/  GPIO_PULLUP ; 
 int /*<<< orphan*/  GPIO_SPEED_FAST ; 
 int /*<<< orphan*/  HAL_GPIO_Init (int /*<<< orphan*/ ,TYPE_2__*) ; 
 long HAL_GPIO_ReadPin (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HAL_GPIO_WritePin (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HAL_SPI_Receive (TYPE_10__*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 unsigned char HI (unsigned short) ; 
 unsigned char LO (unsigned short) ; 
 TYPE_9__* PIN_CS ; 
 TYPE_8__* PIN_EN ; 
 TYPE_7__* PIN_IRQ ; 
 int /*<<< orphan*/  SPI_BAUDRATEPRESCALER_8 ; 
 int /*<<< orphan*/  SPI_CRCCALCULATION_DISABLED ; 
 int /*<<< orphan*/  SPI_DATASIZE_8BIT ; 
 int /*<<< orphan*/  SPI_DIRECTION_2LINES ; 
 int /*<<< orphan*/  SPI_FIRSTBIT_MSB ; 
 TYPE_4__* SPI_HANDLE ; 
 scalar_t__ SPI_HEADER_SIZE ; 
 int /*<<< orphan*/  SPI_MODE_MASTER ; 
 int /*<<< orphan*/  SPI_NSS_SOFT ; 
 int /*<<< orphan*/  SPI_PHASE_2EDGE ; 
 int /*<<< orphan*/  SPI_POLARITY_LOW ; 
 int /*<<< orphan*/  SPI_TIMEOUT ; 
 int /*<<< orphan*/  SPI_TIMODE_DISABLED ; 
 int /*<<< orphan*/  SpiFirstWrite (unsigned char*,unsigned short) ; 
 int /*<<< orphan*/  SpiWriteDataSynchronous (unsigned char*,unsigned short) ; 
 scalar_t__ WLAN_ENABLE ; 
 unsigned char WRITE ; 
 scalar_t__ eSPI_STATE_IDLE ; 
 scalar_t__ eSPI_STATE_INITIALIZED ; 
 scalar_t__ eSPI_STATE_POWERUP ; 
 scalar_t__ eSPI_STATE_WRITE_IRQ ; 
 int /*<<< orphan*/  extint_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  extint_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  extint_register (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  irq_callback_obj ; 
 TYPE_5__ sSpiInformation ; 
 scalar_t__* spi_buffer ; 
 int /*<<< orphan*/  spi_init (TYPE_4__*,int) ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  stub2 () ; 
 int /*<<< orphan*/  stub3 () ; 
 scalar_t__ stub4 () ; 
 TYPE_3__ tSLInformation ; 
 scalar_t__* wlan_tx_buffer ; 

void SpiInit(void *spi, const void *pin_cs, const void *pin_en, const void *pin_irq) {
    SPI_HANDLE = spi;
    PIN_CS = pin_cs;
    PIN_EN = pin_en;
    PIN_IRQ = pin_irq;
}

void SpiClose(void)
{
    if (sSpiInformation.pRxPacket) {
        sSpiInformation.pRxPacket = 0;
    }

    tSLInformation.WlanInterruptDisable();

    //HAL_SPI_DeInit(SPI_HANDLE);
}

void SpiOpen(gcSpiHandleRx pfRxHandler)
{
    DEBUG_printf("SpiOpen\n");

    /* initialize SPI state */
    sSpiInformation.ulSpiState = eSPI_STATE_POWERUP;
    sSpiInformation.SPIRxHandler = pfRxHandler;
    sSpiInformation.usTxPacketLength = 0;
    sSpiInformation.pTxPacket = NULL;
    sSpiInformation.pRxPacket = (unsigned char *)spi_buffer;
    sSpiInformation.usRxPacketLength = 0;
    spi_buffer[CC3000_RX_BUFFER_SIZE - 1] = CC3000_BUFFER_MAGIC_NUMBER;
    wlan_tx_buffer[CC3000_TX_BUFFER_SIZE - 1] = CC3000_BUFFER_MAGIC_NUMBER;

    /* SPI configuration */
    SPI_InitTypeDef *init = &SPI_HANDLE->spi->Init;
    init->Mode              = SPI_MODE_MASTER;
    init->Direction         = SPI_DIRECTION_2LINES;
    init->DataSize          = SPI_DATASIZE_8BIT;
    init->CLKPolarity       = SPI_POLARITY_LOW;
    init->CLKPhase          = SPI_PHASE_2EDGE;
    init->NSS               = SPI_NSS_SOFT;
    init->BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
    init->FirstBit          = SPI_FIRSTBIT_MSB;
    init->TIMode            = SPI_TIMODE_DISABLED;
    init->CRCCalculation    = SPI_CRCCALCULATION_DISABLED;
    init->CRCPolynomial     = 7;
    spi_init(SPI_HANDLE, false);

    // configure wlan CS and EN pins
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Alternate = 0;

    GPIO_InitStructure.Pin = PIN_CS->pin_mask;
    HAL_GPIO_Init(PIN_CS->gpio, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = PIN_EN->pin_mask;
    HAL_GPIO_Init(PIN_EN->gpio, &GPIO_InitStructure);

    HAL_GPIO_WritePin(PIN_CS->gpio, PIN_CS->pin_mask, GPIO_PIN_SET);
    HAL_GPIO_WritePin(PIN_EN->gpio, PIN_EN->pin_mask, GPIO_PIN_RESET);

    /* do a dummy read, this ensures SCLK is low before
       actual communications start, it might be required */
    CS_LOW();
    uint8_t buf[1];
    HAL_SPI_Receive(SPI_HANDLE->spi, buf, sizeof(buf), SPI_TIMEOUT);
    CS_HIGH();

    // register EXTI
    extint_register((mp_obj_t)PIN_IRQ, GPIO_MODE_IT_FALLING, GPIO_PULLUP, (mp_obj_t)&irq_callback_obj, true);
    extint_enable(PIN_IRQ->pin);

    DEBUG_printf("SpiOpen finished; IRQ.pin=%d IRQ_LINE=%d\n", PIN_IRQ->pin, PIN_IRQ->pin);
}

long ReadWlanInterruptPin(void)
{
    return HAL_GPIO_ReadPin(PIN_IRQ->gpio, PIN_IRQ->pin_mask);
}

void WriteWlanPin(unsigned char val)
{
    HAL_GPIO_WritePin(PIN_EN->gpio, PIN_EN->pin_mask,
            (WLAN_ENABLE)? GPIO_PIN_SET:GPIO_PIN_RESET);
}

long SpiWrite(unsigned char *pUserBuffer, unsigned short usLength)
{
    DEBUG_printf("SpiWrite %lu\n", sSpiInformation.ulSpiState);

    unsigned char ucPad = 0;

    // Figure out the total length of the packet in order to figure out if there 
    // is padding or not
    if(!(usLength & 0x0001)) {
        ucPad++;
    }

    pUserBuffer[0] = WRITE;
    pUserBuffer[1] = HI(usLength + ucPad);
    pUserBuffer[2] = LO(usLength + ucPad);
    pUserBuffer[3] = 0;
    pUserBuffer[4] = 0;

    usLength += (SPI_HEADER_SIZE + ucPad);

    // The magic number that resides at the end of the TX/RX buffer (1 byte after the allocated size)
    // for the purpose of detection of the overrun. If the magic number is overriten - buffer overrun
    // occurred - and we will stuck here forever!
    if (wlan_tx_buffer[CC3000_TX_BUFFER_SIZE - 1] != CC3000_BUFFER_MAGIC_NUMBER) {
        while (1);
    }

    if (sSpiInformation.ulSpiState == eSPI_STATE_POWERUP) {
        while (sSpiInformation.ulSpiState != eSPI_STATE_INITIALIZED);
    }

    if (sSpiInformation.ulSpiState == eSPI_STATE_INITIALIZED) {
        // This is time for first TX/RX transactions over SPI:
        // the IRQ is down - so need to send read buffer size command
        SpiFirstWrite(pUserBuffer, usLength);
    } else {
        //
        // We need to prevent here race that can occur in case 2 back to back packets are sent to the
        // device, so the state will move to IDLE and once again to not IDLE due to IRQ
        //
        tSLInformation.WlanInterruptDisable();

        while (sSpiInformation.ulSpiState != eSPI_STATE_IDLE);

        sSpiInformation.ulSpiState = eSPI_STATE_WRITE_IRQ;
        sSpiInformation.pTxPacket = pUserBuffer;
        sSpiInformation.usTxPacketLength = usLength;

        // Assert the CS line and wait till SSI IRQ line is active and then initialize write operation
        CS_LOW();

        // Re-enable IRQ - if it was not disabled - this is not a problem...
        tSLInformation.WlanInterruptEnable();

        // check for a missing interrupt between the CS assertion and enabling back the interrupts
        if (tSLInformation.ReadWlanInterruptPin() == 0) {
            SpiWriteDataSynchronous(sSpiInformation.pTxPacket, sSpiInformation.usTxPacketLength);

            sSpiInformation.ulSpiState = eSPI_STATE_IDLE;

            CS_HIGH();
        }
    }

    // Due to the fact that we are currently implementing a blocking situation
    // here we will wait till end of transaction
    while (eSPI_STATE_IDLE != sSpiInformation.ulSpiState);

    return(0);
}

void SpiPauseSpi(void) {
    DEBUG_printf("SpiPauseSpi\n");
    extint_disable(PIN_IRQ->pin);
}

void SpiResumeSpi(void) {
    DEBUG_printf("SpiResumeSpi\n");
    extint_enable(PIN_IRQ->pin);
}

