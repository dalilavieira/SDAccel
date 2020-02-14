#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct TYPE_7__ {int /*<<< orphan*/  (* _deselect ) () ;int /*<<< orphan*/  (* _select ) () ;} ;
struct TYPE_5__ {int /*<<< orphan*/  (* _write_bytes ) (int*,int) ;int /*<<< orphan*/  (* _read_bytes ) (int*,int) ;} ;
struct TYPE_6__ {TYPE_1__ SPI; } ;
struct TYPE_8__ {TYPE_3__ CS; TYPE_2__ IF; } ;

/* Variables and functions */
 int RBASE (int) ; 
 int RMASK ; 
 int RSIZE ; 
 int SBASE (int) ; 
 int SMASK ; 
 int SSIZE ; 
 int Sn_RX_RSR (int) ; 
 int Sn_TX_FSR (int) ; 
 TYPE_4__ WIZCHIP ; 
 int /*<<< orphan*/  WIZCHIP_CRITICAL_ENTER () ; 
 int /*<<< orphan*/  WIZCHIP_CRITICAL_EXIT () ; 
 int getSn_RX_RD (int) ; 
 int getSn_TX_WR (int) ; 
 int /*<<< orphan*/  setSn_RX_RD (int,int) ; 
 int /*<<< orphan*/  setSn_TX_WR (int,int) ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  stub10 (int*,int) ; 
 int /*<<< orphan*/  stub11 () ; 
 int /*<<< orphan*/  stub12 () ; 
 int /*<<< orphan*/  stub13 (int*,int) ; 
 int /*<<< orphan*/  stub14 (int*,int) ; 
 int /*<<< orphan*/  stub15 () ; 
 int /*<<< orphan*/  stub2 (int*,int) ; 
 int /*<<< orphan*/  stub3 (int*,int) ; 
 int /*<<< orphan*/  stub4 () ; 
 int /*<<< orphan*/  stub5 () ; 
 int /*<<< orphan*/  stub6 (int*,int) ; 
 int /*<<< orphan*/  stub7 () ; 
 int /*<<< orphan*/  stub8 () ; 
 int /*<<< orphan*/  stub9 (int*,int) ; 

uint8_t WIZCHIP_READ(uint32_t AddrSel) {
    WIZCHIP_CRITICAL_ENTER();
    WIZCHIP.CS._select();

    uint8_t spi_data[4] = {
        AddrSel >> 8,
        AddrSel,
        0x00,
        0x01,
    };
    WIZCHIP.IF.SPI._write_bytes(spi_data, 4);
    uint8_t ret;
    WIZCHIP.IF.SPI._read_bytes(&ret, 1);

    WIZCHIP.CS._deselect();
    WIZCHIP_CRITICAL_EXIT();

    return ret;
}

void WIZCHIP_WRITE(uint32_t AddrSel, uint8_t wb) {
    WIZCHIP_CRITICAL_ENTER();
    WIZCHIP.CS._select();

    uint8_t spi_data[5] = {
        AddrSel >> 8,
        AddrSel,
        0x80,
        0x01,
        wb,
    };
    WIZCHIP.IF.SPI._write_bytes(spi_data, 5);

    WIZCHIP.CS._deselect();
    WIZCHIP_CRITICAL_EXIT();
}

void WIZCHIP_READ_BUF(uint32_t AddrSel, uint8_t* pBuf, uint16_t len) {
    WIZCHIP_CRITICAL_ENTER();
    WIZCHIP.CS._select();

    uint8_t spi_data[4] = {
        AddrSel >> 8,
        AddrSel,
        0x00 | ((len >> 8) & 0x7f),
        len & 0xff,
    };
    WIZCHIP.IF.SPI._write_bytes(spi_data, 4);
    WIZCHIP.IF.SPI._read_bytes(pBuf, len);

    WIZCHIP.CS._deselect();
    WIZCHIP_CRITICAL_EXIT();
}

void WIZCHIP_WRITE_BUF(uint32_t AddrSel, uint8_t* pBuf, uint16_t len) {
    WIZCHIP_CRITICAL_ENTER();
    WIZCHIP.CS._select();

    uint8_t spi_data[4] = {
        AddrSel >> 8,
        AddrSel,
        0x80 | ((len >> 8) & 0x7f),
        len & 0xff,
    };
    WIZCHIP.IF.SPI._write_bytes(spi_data, 4);
    WIZCHIP.IF.SPI._write_bytes(pBuf, len);

    WIZCHIP.CS._deselect();
    WIZCHIP_CRITICAL_EXIT();
}

uint16_t getSn_TX_FSR(uint8_t sn) {
    uint16_t val = 0, val1 = 0;
    do {
        val1 = (WIZCHIP_READ(Sn_TX_FSR(sn)) << 8) | WIZCHIP_READ(Sn_TX_FSR(sn) + 1);
        if (val1 != 0) {
            val = (WIZCHIP_READ(Sn_TX_FSR(sn)) << 8) | WIZCHIP_READ(Sn_TX_FSR(sn) + 1);
        }
    } while (val != val1);
    return val;
}

uint16_t getSn_RX_RSR(uint8_t sn) {
    uint16_t val = 0, val1 = 0;
    do {
        val1 = (WIZCHIP_READ(Sn_RX_RSR(sn)) << 8) | WIZCHIP_READ(Sn_RX_RSR(sn) + 1);
        if (val1 != 0) {
            val = (WIZCHIP_READ(Sn_RX_RSR(sn)) << 8) | WIZCHIP_READ(Sn_RX_RSR(sn) + 1);
        }
    } while (val != val1);
    return val;
}

void wiz_send_data(uint8_t sn, uint8_t *wizdata, uint16_t len) {
    if (len == 0) {
        return;
    }

    uint16_t ptr = getSn_TX_WR(sn);
    uint16_t offset = ptr & SMASK;
    uint32_t addr = offset + SBASE(sn);

    if (offset + len > SSIZE) {
        // implement wrap-around circular buffer
        uint16_t size = SSIZE - offset;
        WIZCHIP_WRITE_BUF(addr, wizdata, size);
        WIZCHIP_WRITE_BUF(SBASE(sn), wizdata + size, len - size);
    } else {
        WIZCHIP_WRITE_BUF(addr, wizdata, len);
    }

    ptr += len;
    setSn_TX_WR(sn, ptr);
}

void wiz_recv_data(uint8_t sn, uint8_t *wizdata, uint16_t len) {
    if (len == 0) {
        return;
    }

    uint16_t ptr = getSn_RX_RD(sn);
    uint16_t offset = ptr & RMASK;
    uint16_t addr = RBASE(sn) + offset;

    if (offset + len > RSIZE) {
        // implement wrap-around circular buffer
        uint16_t size = RSIZE - offset;
        WIZCHIP_READ_BUF(addr, wizdata, size);
        WIZCHIP_READ_BUF(RBASE(sn), wizdata + size, len - size);
    } else {
        WIZCHIP_READ_BUF(addr, wizdata, len);
    }

    ptr += len;
    setSn_RX_RD(sn, ptr);
}

void wiz_recv_ignore(uint8_t sn, uint16_t len) {
    uint16_t ptr = getSn_RX_RD(sn);
    ptr += len;
    setSn_RX_RD(sn, ptr);
}

