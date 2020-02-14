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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
typedef  int int8_t ;

/* Variables and functions */
 int flash_started ; 
 int /*<<< orphan*/  storage_flush () ; 
 int /*<<< orphan*/  storage_get_block_count () ; 
 int /*<<< orphan*/  storage_get_block_size () ; 
 int /*<<< orphan*/  storage_init () ; 
 int /*<<< orphan*/  storage_read_blocks (int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  storage_write_blocks (int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int8_t FLASH_STORAGE_Init(uint8_t lun) {
    storage_init();
    flash_started = 1;
    return 0;
}

int8_t FLASH_STORAGE_GetCapacity(uint8_t lun, uint32_t *block_num, uint16_t *block_size) {
    *block_size = storage_get_block_size();
    *block_num = storage_get_block_count();
    return 0;
}

int8_t FLASH_STORAGE_IsReady(uint8_t lun) {
    if (flash_started) {
        return 0;
    }
    return -1;
}

int8_t FLASH_STORAGE_IsWriteProtected(uint8_t lun) {
    return  0;
}

int8_t FLASH_STORAGE_StartStopUnit(uint8_t lun, uint8_t started) {
    flash_started = started;
    return 0;
}

int8_t FLASH_STORAGE_PreventAllowMediumRemoval(uint8_t lun, uint8_t param) {
    // sync the flash so that the cache is cleared and the device can be unplugged/turned off
    storage_flush();
    return 0;
}

int8_t FLASH_STORAGE_Read(uint8_t lun, uint8_t *buf, uint32_t blk_addr, uint16_t blk_len) {
    storage_read_blocks(buf, blk_addr, blk_len);
    return 0;
}

int8_t FLASH_STORAGE_Write (uint8_t lun, uint8_t *buf, uint32_t blk_addr, uint16_t blk_len) {
    storage_write_blocks(buf, blk_addr, blk_len);
    return 0;
}

int8_t FLASH_STORAGE_GetMaxLun(void) {
    return 0;
}

