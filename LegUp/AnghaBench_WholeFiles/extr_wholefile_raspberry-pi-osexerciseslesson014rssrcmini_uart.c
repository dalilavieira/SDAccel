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
 int AUX_BAUD_RATE ; 
 int /*<<< orphan*/  AUX_ENABLES ; 
 int /*<<< orphan*/  AUX_MU_BAUD_REG ; 
 int /*<<< orphan*/  AUX_MU_CNTL_REG ; 
 int /*<<< orphan*/  AUX_MU_IER_REG ; 
 int /*<<< orphan*/  AUX_MU_IO_REG ; 
 int /*<<< orphan*/  AUX_MU_LCR_REG ; 
 int /*<<< orphan*/  AUX_MU_LSR_REG ; 
 int /*<<< orphan*/  AUX_MU_MCR_REG ; 
 int /*<<< orphan*/  GPFSEL1 ; 
 int /*<<< orphan*/  GPPUD ; 
 int /*<<< orphan*/  GPPUDCLK0 ; 
 int SYS_CLOCK_FREQ ; 
 int /*<<< orphan*/  delay (int) ; 
 int get32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put32 (int /*<<< orphan*/ ,int) ; 

void uart_send(char c) {
  while (1) {
    if (get32(AUX_MU_LSR_REG) & 0x20)
      break;
  }
  put32(AUX_MU_IO_REG, c);
}

char uart_recv(void) {
  while (1) {
    if (get32(AUX_MU_LSR_REG) & 0x01)
      break;
  }
  return (get32(AUX_MU_IO_REG) & 0xFF);
}

void uart_send_string(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    uart_send((char)str[i]);
  }
}

void uart_init(void) {
  unsigned int selector;

  selector = get32(GPFSEL1);
  selector &= ~(7 << 12); // clean gpio14
  selector |= 2 << 12;    // set alt5 for gpio14
  selector &= ~(7 << 15); // clean gpio15
  selector |= 2 << 15;    // set alt5 for gpio15
  put32(GPFSEL1, selector);

  put32(GPPUD, 0);
  delay(150);
  put32(GPPUDCLK0, (1 << 14) | (1 << 15));
  delay(150);
  put32(GPPUDCLK0, 0);

  put32(AUX_ENABLES, 1);     // Enable mini uart
                             // (this also enables access to it registers)
  put32(AUX_MU_CNTL_REG, 0); // Disable auto flow control and disable receiver
                             // and transmitter (for now)
  put32(AUX_MU_IER_REG, 0);  // Disable receive and transmit interrupts
  put32(AUX_MU_LCR_REG, 3);  // Enable 8 bit mode
  put32(AUX_MU_MCR_REG, 0);  // Set RTS line to be always high

  put32(AUX_MU_BAUD_REG,
        SYS_CLOCK_FREQ / 8 / AUX_BAUD_RATE - 1); // Set baud rate

  put32(AUX_MU_CNTL_REG, 3); // Finally, enable transmitter and receiver
}

