#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint16_t ;
struct TYPE_10__ {int USART_Mode; int /*<<< orphan*/  USART_HardwareFlowControl; int /*<<< orphan*/  USART_Parity; int /*<<< orphan*/  USART_StopBits; int /*<<< orphan*/  USART_WordLength; int /*<<< orphan*/  USART_BaudRate; } ;
typedef  TYPE_1__ USART_InitTypeDef ;
struct TYPE_11__ {int configured; int tx_buf_size; int TX_active; char* tx_buf; int /*<<< orphan*/  rx_fifo; int /*<<< orphan*/  USARTx; int /*<<< orphan*/  baud; int /*<<< orphan*/  num_pins; int /*<<< orphan*/  pins; int /*<<< orphan*/  apb2; int /*<<< orphan*/  apb1; int /*<<< orphan*/  ahb1; int /*<<< orphan*/  rx_buf_size; int /*<<< orphan*/  rx_buf; } ;
typedef  TYPE_2__ CONFIG_USART_ConfigState ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_pins (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DISABLE ; 
 int /*<<< orphan*/  ENABLE ; 
 int /*<<< orphan*/  FIFO_InitStruct (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int FIFO_available (int /*<<< orphan*/ ) ; 
 char FIFO_peek (int /*<<< orphan*/ ) ; 
 int FIFO_read (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int FIFO_read_until (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,char*,int) ; 
 int /*<<< orphan*/  FIFO_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RCC_AHBPeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RCC_APB1PeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RCC_APB2PeriphClockCmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ RESET ; 
 int /*<<< orphan*/  USART_Cmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USART_DeInit (int /*<<< orphan*/ ) ; 
 scalar_t__ USART_GetITStatus (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USART_HardwareFlowControl_None ; 
 int /*<<< orphan*/  USART_ITConfig (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USART_IT_RXNE ; 
 int /*<<< orphan*/  USART_IT_TC ; 
 int /*<<< orphan*/  USART_Init (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int USART_Mode_Rx ; 
 int USART_Mode_Tx ; 
 int /*<<< orphan*/  USART_Parity_No ; 
 int /*<<< orphan*/  USART_ReceiveData (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USART_StopBits_1 ; 
 int /*<<< orphan*/  USART_WordLength_8b ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int) ; 

void UART_Config(CONFIG_USART_ConfigState *cfg) {
	USART_InitTypeDef USART_InitStructure;

	FIFO_InitStruct(cfg->rx_fifo, cfg->rx_buf, cfg->rx_buf_size);

	// turn on peripheral clocks
	RCC_AHBPeriphClockCmd(cfg->ahb1, ENABLE);
	RCC_APB1PeriphClockCmd(cfg->apb1, ENABLE);
	RCC_APB2PeriphClockCmd(cfg->apb2, ENABLE);

	// configure pins
	CONFIG_pins(cfg->pins, cfg->num_pins);

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
	//USART_ITConfig(cfg->USARTx, USART_IT_RXNE, ENABLE);

	// enable the USART
	USART_Cmd(cfg->USARTx, ENABLE);
	cfg->configured = true;
	cfg->configured = true;
	cfg->configured = true;
	cfg->configured = true;
}

bool UART_SendBytes(CONFIG_USART_ConfigState *cfg, const char *buf, uint16_t length, bool block) {
	int i;

	assert(cfg->configured == true);
	assert(buf != NULL);
	assert(length <= cfg->tx_buf_size);

    if(block)
        while(cfg->TX_active);
    else
        if(cfg->TX_active)
            return false;

	cfg->TX_active = true;

    memcpy(cfg->tx_buf, buf, length);

	for(i = 0; i < length; i++)
		cfg->tx_buf[i] = buf[i];

    return true;
}

void USART_IRQ_Handler(CONFIG_USART_ConfigState *cfg) {
	uint8_t workByte;

	assert(cfg->configured == true);

	if(USART_GetITStatus(cfg->USARTx, USART_IT_RXNE) != RESET) {
		// we have a new byte to receive
		workByte = USART_ReceiveData(cfg->USARTx);
		FIFO_write(cfg->rx_fifo, workByte);
	}
	if(USART_GetITStatus(cfg->USARTx, USART_IT_TC) != RESET) {
		// disable the interrupt since transmission will remain complete until we start a new one
		USART_ITConfig(cfg->USARTx, USART_IT_TC, DISABLE);

		cfg->TX_active = false;
	}
}

uint16_t UART_RX_available(CONFIG_USART_ConfigState *cfg) {
	assert(cfg->configured == true);

	return FIFO_available(cfg->rx_fifo);
}

bool UART_RX_read(CONFIG_USART_ConfigState *cfg, char *outBuffer, uint16_t count) {
	assert(cfg->configured == true);

	return FIFO_read(cfg->rx_fifo, (uint8_t*)outBuffer, count);
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

