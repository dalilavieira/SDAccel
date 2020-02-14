#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char uint8_t ;
struct TYPE_2__ {int /*<<< orphan*/  spiObjectIdx0; } ;
typedef  int /*<<< orphan*/  P_EVENT_HANDLER ;
typedef  int /*<<< orphan*/  Fd_t ;

/* Variables and functions */
 int /*<<< orphan*/  CS_PIN ; 
 int /*<<< orphan*/  CS_PORT ; 
 int /*<<< orphan*/  DRV_SPI0_BufferAddWriteRead (unsigned char*,unsigned char*,int) ; 
 int /*<<< orphan*/  DRV_SPI_Tasks (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HIB_PIN ; 
 int /*<<< orphan*/  HIB_PORT ; 
 int /*<<< orphan*/  PLIB_PORTS_PinClear (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_PORTS_PinSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PORTS_ID_0 ; 
 int /*<<< orphan*/  SYS_PRINT (char*) ; 
 int /*<<< orphan*/  g_cc3100_IRQ_handler ; 
 int /*<<< orphan*/  memset (unsigned char*,int,int) ; 
 TYPE_1__ sysObj ; 

void AssertCS() {
  PLIB_PORTS_PinClear(PORTS_ID_0, CS_PORT, CS_PIN);
}

void DeassertCS() {
  PLIB_PORTS_PinSet(PORTS_ID_0, CS_PORT, CS_PIN);
}

void CC3100_enable() {
  PLIB_PORTS_PinSet(PORTS_ID_0, HIB_PORT, HIB_PIN);
}

void CC3100_disable() {
  PLIB_PORTS_PinClear(PORTS_ID_0, HIB_PORT, HIB_PIN);
}

Fd_t spi_Open(char *ifName, unsigned long flags) {
  CC3100_disable();

  return 0;
}

int spi_Write(Fd_t fd, unsigned char *pBuff, int len) {
  if (len > 512) {
    SYS_PRINT("BUFFER TOO SMALL");
    return 0;
  }

  AssertCS();
  uint8_t dummy[512];
  DRV_SPI0_BufferAddWriteRead(pBuff, dummy, len);
  DRV_SPI_Tasks(sysObj.spiObjectIdx0);
  DeassertCS();

  return len;
}

int spi_Read(Fd_t fd, unsigned char *pBuff, int len) {
  if (len > 512) {
    SYS_PRINT("BUFFER TOO SMALL");
    return 0;
  }
  uint8_t dummy[512];
  memset(dummy, 0xFF, len);
  AssertCS();
  DRV_SPI0_BufferAddWriteRead(dummy, pBuff, len);
  DRV_SPI_Tasks(sysObj.spiObjectIdx0);
  DeassertCS();
  return len;
}

int registerInterruptHandler(P_EVENT_HANDLER int_handler, void *pValue) {
  (void) pValue;
  g_cc3100_IRQ_handler = int_handler;
}

