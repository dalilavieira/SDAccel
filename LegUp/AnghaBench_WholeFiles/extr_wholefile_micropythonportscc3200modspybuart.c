#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int uint ;
struct TYPE_6__ {scalar_t__ read_buf_tail; scalar_t__ read_buf_head; int* read_buf; int /*<<< orphan*/  baudrate; int /*<<< orphan*/  reg; } ;
typedef  TYPE_1__ pyb_uart_obj_t ;

/* Variables and functions */
 int MAP_UARTCharGetNonBlocking (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAP_UARTCharPutNonBlocking (int /*<<< orphan*/ ,int) ; 
 scalar_t__ MAP_UARTCharsAvail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ ** MP_STATE_PORT (int /*<<< orphan*/ ) ; 
 int PYBUART_RX_BUFFER_LEN ; 
 int PYBUART_TX_MAX_TIMEOUT_MS ; 
 int PYBUART_TX_WAIT_US (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UTILS_DELAY_US_TO_COUNT (int) ; 
 int /*<<< orphan*/  UtilsDelay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pyb_uart_obj ; 
 int /*<<< orphan*/  pyb_uart_objs ; 

void uart_init0 (void) {
    // save references of the UART objects, to prevent the read buffers from being trashed by the gc
    MP_STATE_PORT(pyb_uart_objs)[0] = &pyb_uart_obj[0];
    MP_STATE_PORT(pyb_uart_objs)[1] = &pyb_uart_obj[1];
}

uint32_t uart_rx_any(pyb_uart_obj_t *self) {
    if (self->read_buf_tail != self->read_buf_head) {
        // buffering  via irq
        return (self->read_buf_head > self->read_buf_tail) ? self->read_buf_head - self->read_buf_tail :
                PYBUART_RX_BUFFER_LEN - self->read_buf_tail + self->read_buf_head;
    }
    return MAP_UARTCharsAvail(self->reg) ? 1 : 0;
}

int uart_rx_char(pyb_uart_obj_t *self) {
    if (self->read_buf_tail != self->read_buf_head) {
        // buffering via irq
        int data = self->read_buf[self->read_buf_tail];
        self->read_buf_tail = (self->read_buf_tail + 1) % PYBUART_RX_BUFFER_LEN;
        return data;
    } else {
        // no buffering
        return MAP_UARTCharGetNonBlocking(self->reg);
    }
}

bool uart_tx_char(pyb_uart_obj_t *self, int c) {
    uint32_t timeout = 0;
    while (!MAP_UARTCharPutNonBlocking(self->reg, c)) {
        if (timeout++ > ((PYBUART_TX_MAX_TIMEOUT_MS * 1000) / PYBUART_TX_WAIT_US(self->baudrate))) {
            return false;
        }
        UtilsDelay(UTILS_DELAY_US_TO_COUNT(PYBUART_TX_WAIT_US(self->baudrate)));
    }
    return true;
}

bool uart_tx_strn(pyb_uart_obj_t *self, const char *str, uint len) {
    for (const char *top = str + len; str < top; str++) {
        if (!uart_tx_char(self, *str)) {
            return false;
        }
    }
    return true;
}

