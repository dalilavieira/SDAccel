#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ PLLPRE; scalar_t__ PLLPOST; } ;
struct TYPE_5__ {int COSC; int /*<<< orphan*/  LOCK; } ;
struct TYPE_4__ {int uxbrg; int uxmode; int uxsta; int uxrxreg; int uxtxreg; } ;

/* Variables and functions */
 TYPE_3__ CLKDIVbits ; 
 int GREEN_LED ; 
 scalar_t__ GREEN_LED_TRIS ; 
 int LED_OFF ; 
 int LED_ON ; 
 TYPE_2__ OSCCONbits ; 
 scalar_t__ OSCTUN ; 
 int PLLFBD ; 
 int RED_LED ; 
 scalar_t__ RED_LED_TRIS ; 
 int SWITCH_S1 ; 
 int SWITCH_S1_TRIS ; 
 int SWITCH_S2 ; 
 int SWITCH_S2_TRIS ; 
 TYPE_1__ UART1 ; 
 int YELLOW_LED ; 
 scalar_t__ YELLOW_LED_TRIS ; 
 int /*<<< orphan*/  __builtin_write_OSCCONH (int) ; 
 int /*<<< orphan*/  __builtin_write_OSCCONL (int) ; 

void cpu_init(void) {
    // set oscillator to operate at 40MHz
    // Fosc = Fin*M/(N1*N2), Fcy = Fosc/2
    // Fosc = 7.37M*40/(2*2) = 80Mhz for 7.37M input clock
    PLLFBD = 41;            // M=39
    CLKDIVbits.PLLPOST = 0; // N1=2
    CLKDIVbits.PLLPRE = 0;  // N2=2
    OSCTUN = 0;

    // initiate clock switch to FRC with PLL
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);

    // wait for clock switch to occur
    while (OSCCONbits.COSC != 0x01) {
    }
    while (!OSCCONbits.LOCK) {
    }
}

void led_init(void) {
    // set led GPIO as outputs
    RED_LED_TRIS = 0;
    YELLOW_LED_TRIS = 0;
    GREEN_LED_TRIS = 0;

    // turn off the LEDs
    RED_LED = LED_OFF;
    YELLOW_LED = LED_OFF;
    GREEN_LED = LED_OFF;
}

void led_state(int led, int state) {
    int val = state ? LED_ON : LED_OFF;
    switch (led) {
        case 1: RED_LED = val; break;
        case 2: YELLOW_LED = val; break;
        case 3: GREEN_LED = val; break;
    }
}

void led_toggle(int led) {
    switch (led) {
        case 1: RED_LED ^= 1; break;
        case 2: YELLOW_LED ^= 1; break;
        case 3: GREEN_LED ^= 1; break;
    }
}

void switch_init(void) {
    // set switch GPIO as inputs
    SWITCH_S1_TRIS = 1;
    SWITCH_S2_TRIS = 1;
}

int switch_get(int sw) {
    int val = 1;
    switch (sw) {
        case 1: val = SWITCH_S1; break;
        case 2: val = SWITCH_S2; break;
    }
    return val == 0;
}

void uart_init(void) {
    // baudrate = F_CY / 16 (uxbrg + 1)
    // F_CY = 40MHz for us
    UART1.uxbrg = 64; // 38400 baud
    UART1.uxmode = 1 << 15; // UARTEN
    UART1.uxsta = 1 << 10;  // UTXEN
}

int uart_rx_any(void) {
    return UART1.uxsta & 1; // URXDA
}

int uart_rx_char(void) {
    return UART1.uxrxreg;
}

void uart_tx_char(int chr) {
    while (UART1.uxsta & (1 << 9)) {
        // tx fifo is full
    }
    UART1.uxtxreg = chr;
}

