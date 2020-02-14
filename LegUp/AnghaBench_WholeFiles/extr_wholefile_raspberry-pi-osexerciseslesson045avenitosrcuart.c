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

/* Variables and functions */
 int /*<<< orphan*/  GPFSEL1 ; 
 int /*<<< orphan*/  GPPUD ; 
 int /*<<< orphan*/  GPPUDCLK0 ; 
 int /*<<< orphan*/  UARTLCR_LCRH ; 
 int /*<<< orphan*/  UART_CR ; 
 int /*<<< orphan*/  UART_DR ; 
 int /*<<< orphan*/  UART_FBRD ; 
 int /*<<< orphan*/  UART_FR ; 
 int /*<<< orphan*/  UART_IBRD ; 
 int /*<<< orphan*/  delay (int) ; 
 int get32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put32 (int /*<<< orphan*/ ,int) ; 

void uart_send ( char c )
{
	while(get32(UART_FR)&0x20) {}			// wait if TX is full
	put32(UART_DR,c);						// when TX is empty, send next char
}

char uart_recv ( void )
{
	while(get32(UART_FR)&0x10) {}			// wait if RX is empty
	return(get32(UART_DR)&0xFF);			// get recived char
}

void uart_send_string(char* str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}

void uart_init ( void )
{
	unsigned int selector;

	selector = get32(GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 4<<12;                      // set alt0 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 4<<15;                      // set alt0 for gpio15
	put32(GPFSEL1,selector);

	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	put32(GPPUDCLK0,0);

	put32(UART_CR,0);						// disable RX and TX to configure
	
	put32(UART_IBRD,26);					//PrimeCell UART (PL011) rev.r1p5 pag.3-9 BAUDDIV = (FUARTCLK/(16 Baud rate)) = 48MHz/(16*115200) = 26.041666
	put32(UART_FBRD,3);					
	put32(UARTLCR_LCRH,0x60);				//Enable 8 bit mode

	put32(UART_CR,0x301);					// enable UART, RX and TX
}

void putc ( void* p, char c)
{
	uart_send(c);
}

