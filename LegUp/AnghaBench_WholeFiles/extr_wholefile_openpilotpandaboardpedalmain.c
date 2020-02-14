#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  scalar_t__ uint16_t ;
typedef  int /*<<< orphan*/  uart_ring ;
struct TYPE_12__ {int KR; int RLR; scalar_t__ PR; } ;
struct TYPE_11__ {int TSR; int RF0R; TYPE_2__* sTxMailBox; TYPE_1__* sFIFOMailBox; } ;
struct TYPE_10__ {scalar_t__ SR; } ;
struct TYPE_9__ {int TDLR; int TDHR; int TDTR; int TIR; } ;
struct TYPE_8__ {int RIR; int RDLR; int RDHR; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADCCHAN_ACCEL0 ; 
 int /*<<< orphan*/  ADCCHAN_ACCEL1 ; 
 int /*<<< orphan*/  ALL_CAN_LIVE ; 
 TYPE_4__* CAN ; 
 scalar_t__ CAN_GAS_INPUT ; 
 int CAN_GAS_OUTPUT ; 
 int CAN_GAS_SIZE ; 
 int CAN_RF0R_FMP0 ; 
 int CAN_RF0R_RFOM0 ; 
 int CAN_TSR_RQCP0 ; 
 int CAN_TSR_TME0 ; 
 int COUNTER_CYCLE ; 
 int /*<<< orphan*/  ENTER_BOOTLOADER_MAGIC ; 
 int /*<<< orphan*/  ENTER_SOFTLOADER_MAGIC ; 
 int FAULT_BAD_CHECKSUM ; 
 int FAULT_INVALID ; 
 int FAULT_SCE ; 
 int FAULT_SEND ; 
 int FAULT_TIMEOUT ; 
 TYPE_6__* IWDG ; 
 int /*<<< orphan*/  LED_GREEN ; 
 scalar_t__ MAX_TIMEOUT ; 
 int NO_FAULT ; 
 int /*<<< orphan*/  NVIC_EnableIRQ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NVIC_SystemReset () ; 
 TYPE_3__* TIM3 ; 
 int /*<<< orphan*/  TIM3_IRQn ; 
 int /*<<< orphan*/  __disable_irq () ; 
 int /*<<< orphan*/  __enable_irq () ; 
 int adc_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  adc_init () ; 
 int /*<<< orphan*/  can_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  can_sce (TYPE_4__*) ; 
 int /*<<< orphan*/  can_silent ; 
 int /*<<< orphan*/  clock_init () ; 
 int current_index ; 
 int /*<<< orphan*/  dac_init () ; 
 int /*<<< orphan*/  dac_set (int,int) ; 
 int /*<<< orphan*/  early () ; 
 int /*<<< orphan*/  enter_bootloader_mode ; 
 scalar_t__ gas_set_0 ; 
 scalar_t__ gas_set_1 ; 
 scalar_t__ getc (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  gpio_init () ; 
 int led_value ; 
 int max (scalar_t__,int) ; 
 int pdl0 ; 
 int pdl1 ; 
 int /*<<< orphan*/  periph_init () ; 
 int pkt_idx ; 
 int /*<<< orphan*/  putc (int /*<<< orphan*/ *,char) ; 
 int /*<<< orphan*/  puts (char*) ; 
 int /*<<< orphan*/  set_led (int /*<<< orphan*/ ,int) ; 
 int state ; 
 scalar_t__ timeout ; 
 int /*<<< orphan*/  timer_init (TYPE_3__*,int) ; 

void __initialize_hardware_early() {
  early();
}

void debug_ring_callback(uart_ring *ring) {
  char rcv;
  while (getc(ring, &rcv)) {
    putc(ring, rcv);
  }
}

uint8_t pedal_checksum(uint8_t *dat, int len) {
  uint8_t crc = 0xFF;
  uint8_t poly = 0xD5; // standard crc8
  int i, j;
  for (i = len - 1; i >= 0; i--) {
    crc ^= dat[i];
    for (j = 0; j < 8; j++) {
      if ((crc & 0x80) != 0) {
        crc = (uint8_t)((crc << 1) ^ poly);
      }
      else {
        crc <<= 1;
      }
    }
  }
  return crc;
}

void CAN1_TX_IRQHandler() {
  // clear interrupt
  CAN->TSR |= CAN_TSR_RQCP0;
}

void CAN1_RX0_IRQHandler() {
  while (CAN->RF0R & CAN_RF0R_FMP0) {
    #ifdef DEBUG
      puts("CAN RX\n");
    #endif
    uint32_t address = CAN->sFIFOMailBox[0].RIR>>21;
    if (address == CAN_GAS_INPUT) {
      // softloader entry
      if (CAN->sFIFOMailBox[0].RDLR == 0xdeadface) {
        if (CAN->sFIFOMailBox[0].RDHR == 0x0ab00b1e) {
          enter_bootloader_mode = ENTER_SOFTLOADER_MAGIC;
          NVIC_SystemReset();
        } else if (CAN->sFIFOMailBox[0].RDHR == 0x02b00b1e) {
          enter_bootloader_mode = ENTER_BOOTLOADER_MAGIC;
          NVIC_SystemReset();
        }
      }

      // normal packet
      uint8_t dat[8];
      uint8_t *rdlr = (uint8_t *)&CAN->sFIFOMailBox[0].RDLR;
      uint8_t *rdhr = (uint8_t *)&CAN->sFIFOMailBox[0].RDHR;
      for (int i=0; i<4; i++) {
        dat[i] = rdlr[i];
        dat[i+4] = rdhr[i];
      }
      uint16_t value_0 = (dat[0] << 8) | dat[1];
      uint16_t value_1 = (dat[2] << 8) | dat[3];
      uint8_t enable = (dat[4] >> 7) & 1;
      uint8_t index = dat[4] & COUNTER_CYCLE;
      if (pedal_checksum(dat, CAN_GAS_SIZE - 1) == dat[5]) {
        if (((current_index + 1) & COUNTER_CYCLE) == index) {
          #ifdef DEBUG
            puts("setting gas ");
            puth(value);
            puts("\n");
          #endif
          if (enable) {
            gas_set_0 = value_0;
            gas_set_1 = value_1;
          } else {
            // clear the fault state if values are 0
            if (value_0 == 0 && value_1 == 0) {
              state = NO_FAULT;
            } else {
              state = FAULT_INVALID;
            }
            gas_set_0 = gas_set_1 = 0;
          }
          // clear the timeout
          timeout = 0;
        }
        current_index = index;
      } else {
        // wrong checksum = fault
        state = FAULT_BAD_CHECKSUM;
      }
    }
    // next
    CAN->RF0R |= CAN_RF0R_RFOM0;
  }
}

void CAN1_SCE_IRQHandler() {
  state = FAULT_SCE;
  can_sce(CAN);
}

void TIM3_IRQHandler() {
  #ifdef DEBUG
    puth(TIM3->CNT);
    puts(" ");
    puth(pdl0);
    puts(" ");
    puth(pdl1);
    puts("\n");
  #endif

  // check timer for sending the user pedal and clearing the CAN
  if ((CAN->TSR & CAN_TSR_TME0) == CAN_TSR_TME0) {
    uint8_t dat[8];
    dat[0] = (pdl0>>8) & 0xFF;
    dat[1] = (pdl0>>0) & 0xFF;
    dat[2] = (pdl1>>8) & 0xFF;
    dat[3] = (pdl1>>0) & 0xFF;
    dat[4] = (state & 0xF) << 4 | pkt_idx;
    dat[5] = pedal_checksum(dat, CAN_GAS_SIZE - 1);
    CAN->sTxMailBox[0].TDLR = dat[0] | (dat[1]<<8) | (dat[2]<<16) | (dat[3]<<24);
    CAN->sTxMailBox[0].TDHR = dat[4] | (dat[5]<<8);
    CAN->sTxMailBox[0].TDTR = 6;  // len of packet is 5
    CAN->sTxMailBox[0].TIR = (CAN_GAS_OUTPUT << 21) | 1;
    ++pkt_idx;
    pkt_idx &= COUNTER_CYCLE;
  } else {
    // old can packet hasn't sent!
    state = FAULT_SEND;
    #ifdef DEBUG
      puts("CAN MISS\n");
    #endif
  }

  // blink the LED
  set_led(LED_GREEN, led_value);
  led_value = !led_value;

  TIM3->SR = 0;

  // up timeout for gas set
  if (timeout == MAX_TIMEOUT) {
    state = FAULT_TIMEOUT;
  } else {
    timeout += 1;
  }
}

void pedal() {
  // read/write
  pdl0 = adc_get(ADCCHAN_ACCEL0);
  pdl1 = adc_get(ADCCHAN_ACCEL1);

  // write the pedal to the DAC
  if (state == NO_FAULT) {
    dac_set(0, max(gas_set_0, pdl0));
    dac_set(1, max(gas_set_1, pdl1));
  } else {
    dac_set(0, pdl0);
    dac_set(1, pdl1);
  }

  // feed the watchdog
  IWDG->KR = 0xAAAA;
}

int main() {
  __disable_irq();

  // init devices
  clock_init();
  periph_init();
  gpio_init();

#ifdef PEDAL_USB
  // enable USB
  usb_init();
#endif

  // pedal stuff
  dac_init();
  adc_init();

  // init can
  can_silent = ALL_CAN_LIVE;
  can_init(0);

  // 48mhz / 65536 ~= 732
  timer_init(TIM3, 15);
  NVIC_EnableIRQ(TIM3_IRQn);

  // setup watchdog
  IWDG->KR = 0x5555;
  IWDG->PR = 0;          // divider /4
  // 0 = 0.125 ms, let's have a 50ms watchdog
  IWDG->RLR = 400 - 1;
  IWDG->KR = 0xCCCC;

  puts("**** INTERRUPTS ON ****\n");
  __enable_irq();


  // main pedal loop
  while (1) {
    pedal();
  }

  return 0;
}

