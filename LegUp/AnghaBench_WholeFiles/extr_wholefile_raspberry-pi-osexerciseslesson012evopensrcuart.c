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
 int /*<<< orphan*/  UART_CR ; 
 int /*<<< orphan*/  UART_DR ; 
 int /*<<< orphan*/  UART_FBRD ; 
 int /*<<< orphan*/  UART_FR ; 
 int /*<<< orphan*/  UART_IBRD ; 
 int /*<<< orphan*/  UART_LCRH ; 
 int /*<<< orphan*/  delay (int) ; 
 int get32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put32 (int /*<<< orphan*/ ,char) ; 

void uart_init(void) {
    unsigned int selector;  // 32 bits

    selector = get32(GPFSEL1);
    selector &= ~(7 << 12);
    selector |= 4 << 12;
    selector &= ~(7 << 15);
    selector |= 4 << 15;
    put32(GPFSEL1, selector);

    put32(GPPUD, 0);
    delay(150);
    put32(GPPUDCLK0, (1 << 14) | (1 << 15));
    delay(150);
    put32(GPPUDCLK0, 0);

    put32(UART_CR, 0);
    put32(UART_IBRD, 26);
    put32(UART_FBRD, 3);
    put32(UART_LCRH, (1 << 4) | (3 << 5));
    // put32(UART_IMSC, 0);
    put32(UART_CR, 1 | (1 << 8) | (1 << 9));
}

void uart_send(char c) {
    while (1) {
        if (!(get32(UART_FR) & (1 << 5))) break;
    }
    put32(UART_DR, c);
}

char uart_recv(void) {
    while (1) {
        if (!(get32(UART_FR) & (1 << 4))) break;
    }
    return (get32(UART_DR) & 0xFF);
}

void uart_send_string(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        uart_send((char)str[i]);
    }
}

