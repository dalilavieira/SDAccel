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
typedef  int IOTYPE ;

/* Variables and functions */
 scalar_t__ PORT (int) ; 
 int UART_LSR ; 
 int UART_LSR_THRE ; 
 int UART_TX ; 

__attribute__((used)) static inline unsigned int serial_in(int offset)
{
	return *((volatile IOTYPE *)PORT(offset)) & 0xFF;
}

__attribute__((used)) static inline void serial_out(int offset, int value)
{
	*((volatile IOTYPE *)PORT(offset)) = value & 0xFF;
}

void putc(char c)
{
	int timeout = 1000000;

	while (((serial_in(UART_LSR) & UART_LSR_THRE) == 0) && (timeout-- > 0))
		;

	serial_out(UART_TX, c);
}

