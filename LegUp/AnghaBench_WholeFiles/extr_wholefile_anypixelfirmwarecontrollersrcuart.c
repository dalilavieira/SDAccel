#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_5__ ;
typedef  struct TYPE_25__   TYPE_4__ ;
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  int uint16_t ;
struct TYPE_22__ {int USART_Mode; int /*<<< orphan*/  USART_HardwareFlowControl; int /*<<< orphan*/  USART_Parity; int /*<<< orphan*/  USART_StopBits; int /*<<< orphan*/  USART_WordLength; int /*<<< orphan*/  USART_BaudRate; } ;
typedef  TYPE_1__ USART_InitTypeDef ;
struct TYPE_26__ {int SR; int /*<<< orphan*/  DR; } ;
struct TYPE_25__ {int configured; int frame_available; int tx_buf_size; int TX_active; char* tx_buf; int /*<<< orphan*/  rx_fifo; TYPE_5__* USARTx; int /*<<< orphan*/  DMA_stream; int /*<<< orphan*/  DR_ADDR; int /*<<< orphan*/  DMA_channel; int /*<<< orphan*/  DMA_IntFlags; int /*<<< orphan*/  baud; int /*<<< orphan*/  IRQn; int /*<<< orphan*/  num_pins; int /*<<< orphan*/  pins; int /*<<< orphan*/  apb2; int /*<<< orphan*/  apb1; int /*<<< orphan*/  ahb1; int /*<<< orphan*/  rx_buf_size; int /*<<< orphan*/  rx_buf; } ;
struct TYPE_24__ {int DMA_BufferSize; int /*<<< orphan*/  DMA_PeripheralBurst; int /*<<< orphan*/  DMA_MemoryBurst; int /*<<< orphan*/  DMA_FIFOThreshold; int /*<<< orphan*/  DMA_FIFOMode; int /*<<< orphan*/  DMA_Priority; int /*<<< orphan*/  DMA_Mode; int /*<<< orphan*/  DMA_MemoryDataSize; int /*<<< orphan*/  DMA_PeripheralDataSize; int /*<<< orphan*/  DMA_MemoryInc; int /*<<< orphan*/  DMA_PeripheralInc; int /*<<< orphan*/  DMA_DIR; scalar_t__ DMA_Memory0BaseAddr; int /*<<< orphan*/  DMA_PeripheralBaseAddr; int /*<<< orphan*/  DMA_Channel; } ;
struct TYPE_23__ {int /*<<< orphan*/  NVIC_IRQChannelCmd; scalar_t__ NVIC_IRQChannelSubPriority; scalar_t__ NVIC_IRQChannelPreemptionPriority; int /*<<< orphan*/  NVIC_IRQChannel; } ;
typedef  TYPE_2__ NVIC_InitTypeDef ;
typedef  TYPE_3__ DMA_InitTypeDef ;
typedef  TYPE_4__ CONFIG_USART_ConfigState ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_pins (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DEBUGPIN_CLR (int) ; 
 int /*<<< orphan*/  DEBUGPIN_SET (int) ; 
 int /*<<< orphan*/  DEBUGPIN_TGL (int) ; 
 int /*<<< orphan*/  DISABLE ; 
 int /*<<< orphan*/  DMA_ClearITPendingBit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DMA_Cmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DMA_DIR_MemoryToPeripheral ; 
 int /*<<< orphan*/  DMA_DeInit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DMA_FIFOMode_Disable ; 
 int /*<<< orphan*/  DMA_FIFOThreshold_3QuartersFull ; 
 int /*<<< orphan*/  DMA_Init (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  DMA_MemoryBurst_Single ; 
 int /*<<< orphan*/  DMA_MemoryDataSize_Byte ; 
 int /*<<< orphan*/  DMA_MemoryInc_Enable ; 
 int /*<<< orphan*/  DMA_Mode_Normal ; 
 int /*<<< orphan*/  DMA_PeripheralBurst_Single ; 
 int /*<<< orphan*/  DMA_PeripheralDataSize_Byte ; 
 int /*<<< orphan*/  DMA_PeripheralInc_Disable ; 
 int /*<<< orphan*/  DMA_Priority_VeryHigh ; 
 int /*<<< orphan*/  ENABLE ; 
 int /*<<< orphan*/  FIFO_InitStruct (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int FIFO_available (int /*<<< orphan*/ ) ; 
 char FIFO_peek (int /*<<< orphan*/ ) ; 
 int FIFO_read (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int FIFO_read_until (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,char*,int) ; 
 int /*<<< orphan*/  FIFO_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NVIC_Init (TYPE_2__*) ; 
 int /*<<< orphan*/  RCC_AHB1PeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RCC_APB1PeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RCC_APB2PeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USART_ClearFlag (TYPE_5__*,int) ; 
 int /*<<< orphan*/  USART_Cmd (TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USART_DMACmd (TYPE_5__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USART_DMAReq_Tx ; 
 int /*<<< orphan*/  USART_DeInit (TYPE_5__*) ; 
 int USART_FLAG_IDLE ; 
 int USART_FLAG_RXNE ; 
 int USART_FLAG_TC ; 
 int /*<<< orphan*/  USART_HardwareFlowControl_None ; 
 int /*<<< orphan*/  USART_ITConfig (TYPE_5__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USART_IT_IDLE ; 
 int /*<<< orphan*/  USART_IT_RXNE ; 
 int /*<<< orphan*/  USART_IT_TC ; 
 int /*<<< orphan*/  USART_Init (TYPE_5__*,TYPE_1__*) ; 
 int USART_Mode_Rx ; 
 int USART_Mode_Tx ; 
 int /*<<< orphan*/  USART_Parity_No ; 
 int /*<<< orphan*/  USART_ReceiveData (TYPE_5__*) ; 
 int /*<<< orphan*/  USART_StopBits_1 ; 
 int /*<<< orphan*/  USART_WordLength_8b ; 
 int __LDREXH (int*) ; 
 scalar_t__ __STREXH (int,int*) ; 
 int /*<<< orphan*/  assert (int) ; 

void UART_Config(CONFIG_USART_ConfigState *cfg) {
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;

	FIFO_InitStruct(cfg->rx_fifo, cfg->rx_buf, cfg->rx_buf_size);

	// turn on peripheral clocks
	RCC_AHB1PeriphClockCmd(cfg->ahb1, ENABLE);
	RCC_APB1PeriphClockCmd(cfg->apb1, ENABLE);
	RCC_APB2PeriphClockCmd(cfg->apb2, ENABLE);

	// configure pins
	CONFIG_pins(cfg->pins, cfg->num_pins);

	// configure interrupts
	NVIC_InitStructure.NVIC_IRQChannel = cfg->IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	// configure USART
	USART_DeInit(cfg->USARTx);
	USART_InitStructure.USART_BaudRate = cfg->baud;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(cfg->USARTx, &USART_InitStructure);

	// enable RX interrupt
	USART_ITConfig(cfg->USARTx, USART_IT_RXNE, ENABLE);
    USART_ITConfig(cfg->USARTx, USART_IT_IDLE, ENABLE);

	// enable the USART
	USART_Cmd(cfg->USARTx, ENABLE);
	cfg->configured = true;
	cfg->frame_available = 0;
}

bool UART_SendBytes(CONFIG_USART_ConfigState *cfg, const char *buf, uint16_t length) {
	DMA_InitTypeDef DMA_InitStructure;
	int i;

	assert(cfg->configured == true);
	assert(buf != NULL);
	assert(length <= cfg->tx_buf_size);

    DEBUGPIN_SET(2);

	if(cfg->TX_active) {
        DEBUGPIN_CLR(2);
        DEBUGPIN_TGL(9);
		return false;
	}

	for(i = 0; i < length; i++)
		cfg->tx_buf[i] = buf[i];

	// clear transmission complete flag and enable TC interrupt to
	// allow fast response to switch back to RX mode
	USART_ClearFlag(cfg->USARTx, USART_FLAG_TC);
	USART_ITConfig(cfg->USARTx, USART_IT_TC, ENABLE);
	DMA_ClearITPendingBit(cfg->DMA_stream, cfg->DMA_IntFlags);

	// configure DMA
    DMA_DeInit(cfg->DMA_stream);
	DMA_InitStructure.DMA_Channel = cfg->DMA_channel;
	DMA_InitStructure.DMA_PeripheralBaseAddr = cfg->DR_ADDR;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)cfg->tx_buf;
	DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
	DMA_InitStructure.DMA_BufferSize = length;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_3QuartersFull;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_Init(cfg->DMA_stream, &DMA_InitStructure);

	// start the transfer
	USART_DMACmd(cfg->USARTx, USART_DMAReq_Tx, ENABLE);
	DMA_Cmd(cfg->DMA_stream, ENABLE);

    cfg->TX_active = true;

    DEBUGPIN_CLR(2);
	return true;
}

void USART_IRQ_Handler(CONFIG_USART_ConfigState *cfg) {
	uint8_t workByte;
	uint16_t status = cfg->USARTx->SR;

	assert(cfg->configured == true);
    DEBUGPIN_SET(3);
	if(status & USART_FLAG_RXNE) {
        DEBUGPIN_TGL(4);
		// we have a new byte to receive
		//workByte = USART_ReceiveData(cfg->USARTx); // bypass wrapper function to speed up ISR
		workByte = cfg->USARTx->DR;

		FIFO_write(cfg->rx_fifo, workByte);
	}
	if( (cfg->TX_active) && (status & USART_FLAG_TC) ) {
        DEBUGPIN_TGL(5);
		// disable the interrupt since transmission will remain complete until we start a new one
		USART_ITConfig(cfg->USARTx, USART_IT_TC, DISABLE);

		// transmission has completed so disable DMA and update TX_active flag
		DMA_Cmd(cfg->DMA_stream, DISABLE);
		DMA_DeInit(cfg->DMA_stream);
		USART_DMACmd(cfg->USARTx, USART_DMAReq_Tx, DISABLE);
		cfg->TX_active = false;
	}
    if(status & USART_FLAG_IDLE) {
        DEBUGPIN_TGL(6);
        // got idle state so next byte will be start of packet
        cfg->frame_available = FIFO_available(cfg->rx_fifo);
        // need to read from the data register to clear this interrupt flag
        workByte = USART_ReceiveData(cfg->USARTx);
	}
	DEBUGPIN_CLR(3);
}

uint16_t UART_RX_available(CONFIG_USART_ConfigState *cfg) {
	assert(cfg->configured == true);

	return FIFO_available(cfg->rx_fifo);
}

uint16_t UART_RX_frame_available(CONFIG_USART_ConfigState *cfg) {
    assert(cfg->configured == true);
    return cfg->frame_available;
}

bool UART_RX_read(CONFIG_USART_ConfigState *cfg, char *outBuffer, uint16_t count) {
	bool retval;
	uint16_t workAvail;

	assert(cfg->configured == true);

    retval = FIFO_read(cfg->rx_fifo, (uint8_t*)outBuffer, count);
	if(retval) {
        /*cfg->frame_available -= count;
	    if(cfg->frame_available < 0)
	        cfg->frame_available = 0;*/
        // make sure writes to frame_available counter are thread safe
        do {
            workAvail = __LDREXH(&cfg->frame_available);
            if(workAvail < count)
                workAvail = 0;
            else
                workAvail -= count;
        } while( __STREXH(workAvail, &cfg->frame_available));


	}
	return retval;
}

uint16_t UART_RX_readline(CONFIG_USART_ConfigState *cfg, char *outBuffer, uint16_t max) {
	int retval;

	assert(cfg->configured == true);

	retval = FIFO_read_until(cfg->rx_fifo, (uint8_t*)outBuffer, max-1, "\r\n", 2);
	if(retval == 0)
	    return 0;

	if(outBuffer[retval-1] == '\r') {
		retval--;
		// see if next character is a \n
		if( FIFO_available(cfg->rx_fifo)  &&  FIFO_peek(cfg->rx_fifo) == '\n' ) {
			// it is, so remove it from the queue
			char buf[2];
			UART_RX_read(cfg, buf, 1);
		}
	}
	if(outBuffer[retval-1] == '\n')
		retval--;
    outBuffer[retval++] = 0;
	return retval;
}

