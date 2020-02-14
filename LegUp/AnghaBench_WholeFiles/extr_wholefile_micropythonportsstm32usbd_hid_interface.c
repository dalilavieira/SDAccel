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
typedef  int /*<<< orphan*/  usbd_hid_state_t ;
struct TYPE_4__ {scalar_t__ current_read_buffer; size_t last_read_len; size_t current_write_buffer; int /*<<< orphan*/  base; int /*<<< orphan*/ ** buffer; } ;
typedef  TYPE_1__ usbd_hid_itf_t ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  scalar_t__ mp_uint_t ;
typedef  int /*<<< orphan*/  int8_t ;

/* Variables and functions */
 scalar_t__ HAL_GetTick () ; 
 scalar_t__ IRQ_STATE_DISABLED ; 
 int /*<<< orphan*/  USBD_HID_ClearNAK (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  USBD_HID_ReceivePacket (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  USBD_HID_SetNAK (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  USBD_OK ; 
 int /*<<< orphan*/  __WFI () ; 
 scalar_t__ __get_PRIMASK () ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline mp_uint_t query_irq(void) {
    return __get_PRIMASK();
}

uint8_t *usbd_hid_init(usbd_hid_state_t *hid_in) {
    usbd_hid_itf_t *hid = (usbd_hid_itf_t*)hid_in;

    hid->current_read_buffer = 0;
    hid->last_read_len = 0;
    hid->current_write_buffer = 0;

    // Return the buffer to place the first USB OUT packet
    return hid->buffer[hid->current_write_buffer];
}

int8_t usbd_hid_receive(usbd_hid_state_t *hid_in, size_t len) {
    usbd_hid_itf_t *hid = (usbd_hid_itf_t*)hid_in;

    hid->current_write_buffer = !hid->current_write_buffer;
    hid->last_read_len = len;
    // initiate next USB packet transfer, to append to existing data in buffer
    USBD_HID_ReceivePacket(&hid->base, hid->buffer[hid->current_write_buffer]);
    // Set NAK to indicate we need to process read buffer
    USBD_HID_SetNAK(&hid->base);
    return USBD_OK;
}

int usbd_hid_rx_num(usbd_hid_itf_t *hid) {
    return hid->current_read_buffer != hid->current_write_buffer;
}

int usbd_hid_rx(usbd_hid_itf_t *hid, size_t len, uint8_t *buf, uint32_t timeout) {
    // Wait until we have buffer to read
    uint32_t start = HAL_GetTick();
    while (hid->current_read_buffer == hid->current_write_buffer) {
        // Wraparound of tick is taken care of by 2's complement arithmetic.
        if (HAL_GetTick() - start >= timeout) {
            // timeout
            return 0;
        }
        if (query_irq() == IRQ_STATE_DISABLED) {
            // IRQs disabled so buffer will never be filled; return immediately
            return 0;
        }
        __WFI(); // enter sleep mode, waiting for interrupt
    }

    // There is not enough space in buffer
    if (len < hid->last_read_len) {
        return 0;
    }

    // Copy bytes from device to user buffer
    int read_len = hid->last_read_len;
    memcpy(buf, hid->buffer[hid->current_read_buffer], read_len);
    hid->current_read_buffer = !hid->current_read_buffer;

    // Clear NAK to indicate we are ready to read more data
    USBD_HID_ClearNAK(&hid->base);

    // Success, return number of bytes read
    return read_len;
}

