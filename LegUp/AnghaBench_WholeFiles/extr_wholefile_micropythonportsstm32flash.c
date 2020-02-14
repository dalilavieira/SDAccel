#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct TYPE_6__ {scalar_t__ base_address; int sector_count; int sector_size; } ;
struct TYPE_5__ {scalar_t__ Sector; scalar_t__ NbSectors; int /*<<< orphan*/  VoltageRange; int /*<<< orphan*/  TypeErase; } ;
typedef  TYPE_1__ FLASH_EraseInitTypeDef ;

/* Variables and functions */
 int FLASH_FLAG_EOP ; 
 int FLASH_FLAG_OPERR ; 
 int FLASH_FLAG_PGAERR ; 
 int FLASH_FLAG_PGPERR ; 
 int FLASH_FLAG_PGSERR ; 
 int FLASH_FLAG_WRPERR ; 
 int /*<<< orphan*/  FLASH_TYPEPROGRAM_WORD ; 
 scalar_t__ HAL_FLASHEx_Erase (TYPE_1__*,scalar_t__*) ; 
 int /*<<< orphan*/  HAL_FLASH_Lock () ; 
 scalar_t__ HAL_FLASH_Program (int /*<<< orphan*/ ,scalar_t__,scalar_t__ const) ; 
 int /*<<< orphan*/  HAL_FLASH_Unlock () ; 
 scalar_t__ HAL_OK ; 
 int MP_ARRAY_SIZE (TYPE_2__*) ; 
 int /*<<< orphan*/  TYPEERASE_SECTORS ; 
 int /*<<< orphan*/  VOLTAGE_RANGE_3 ; 
 int /*<<< orphan*/  __HAL_FLASH_CLEAR_FLAG (int) ; 
 TYPE_2__* flash_layout ; 

uint32_t flash_get_sector_info(uint32_t addr, uint32_t *start_addr, uint32_t *size) {
    if (addr >= flash_layout[0].base_address) {
        uint32_t sector_index = 0;
        for (int i = 0; i < MP_ARRAY_SIZE(flash_layout); ++i) {
            for (int j = 0; j < flash_layout[i].sector_count; ++j) {
                uint32_t sector_start_next = flash_layout[i].base_address
                    + (j + 1) * flash_layout[i].sector_size;
                if (addr < sector_start_next) {
                    if (start_addr != NULL) {
                        *start_addr = flash_layout[i].base_address
                            + j * flash_layout[i].sector_size;
                    }
                    if (size != NULL) {
                        *size = flash_layout[i].sector_size;
                    }
                    return sector_index;
                }
                ++sector_index;
            }
        }
    }
    return 0;
}

void flash_erase(uint32_t flash_dest, uint32_t num_word32) {
    // check there is something to write
    if (num_word32 == 0) {
        return;
    }

    // unlock
    HAL_FLASH_Unlock();

    FLASH_EraseInitTypeDef EraseInitStruct;

    #if defined(STM32F0)
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_WRPERR | FLASH_FLAG_PGERR);
    EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.PageAddress = flash_dest;
    EraseInitStruct.NbPages     = (4 * num_word32 + FLASH_PAGE_SIZE - 4) / FLASH_PAGE_SIZE;
    #elif  (defined(STM32L4) && !defined(SYSCFG_MEMRMP_FB_MODE))
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);
    EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.Page        = get_page(flash_dest);
    EraseInitStruct.NbPages     = (4 * num_word32 + FLASH_PAGE_SIZE - 4) / FLASH_PAGE_SIZE;
    #elif defined(STM32L4)
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

    // erase the sector(s)
    // The sector returned by flash_get_sector_info can not be used
    // as the flash has on each bank 0/1 pages 0..255
    EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.Banks       = get_bank(flash_dest);
    EraseInitStruct.Page        = get_page(flash_dest);
    EraseInitStruct.NbPages     = get_page(flash_dest + 4 * num_word32 - 1) - EraseInitStruct.Page + 1;;
    #else
    // Clear pending flags (if any)
    #if defined(STM32H7)
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS_BANK1 | FLASH_FLAG_ALL_ERRORS_BANK2);
    #else
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                           FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);
    #endif

    // erase the sector(s)
    EraseInitStruct.TypeErase = TYPEERASE_SECTORS;
    EraseInitStruct.VoltageRange = VOLTAGE_RANGE_3; // voltage range needs to be 2.7V to 3.6V
    #if defined(STM32H7)
    EraseInitStruct.Banks = get_bank(flash_dest);
    #endif
    EraseInitStruct.Sector = flash_get_sector_info(flash_dest, NULL, NULL);
    EraseInitStruct.NbSectors = flash_get_sector_info(flash_dest + 4 * num_word32 - 1, NULL, NULL) - EraseInitStruct.Sector + 1;
    #endif

    uint32_t SectorError = 0;
    if (HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError) != HAL_OK) {
        // error occurred during sector erase
        HAL_FLASH_Lock(); // lock the flash
        return;
    }
}

void flash_write(uint32_t flash_dest, const uint32_t *src, uint32_t num_word32) {
    #if defined(STM32L4)

    // program the flash uint64 by uint64
    for (int i = 0; i < num_word32 / 2; i++) {
        uint64_t val = *(uint64_t*)src;
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, flash_dest, val) != HAL_OK) {
            // error occurred during flash write
            HAL_FLASH_Lock(); // lock the flash
            return;
        }
        flash_dest += 8;
        src += 2;
    }
    if ((num_word32 & 0x01) == 1) {
        uint64_t val = *(uint64_t*)flash_dest;
        val = (val & 0xffffffff00000000uL) | (*src);
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, flash_dest, val) != HAL_OK) {
            // error occurred during flash write
            HAL_FLASH_Lock(); // lock the flash
            return;
        }
    }

    #elif defined(STM32H7)

    // program the flash 256 bits at a time
    for (int i = 0; i < num_word32 / 8; i++) {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, flash_dest, (uint64_t)(uint32_t)src) != HAL_OK) {
            // error occurred during flash write
            HAL_FLASH_Lock(); // lock the flash
            return;
        }
        flash_dest += 32;
        src += 8;
    }

    #else

    // program the flash word by word
    for (int i = 0; i < num_word32; i++) {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, flash_dest, *src) != HAL_OK) {
            // error occurred during flash write
            HAL_FLASH_Lock(); // lock the flash
            return;
        }
        flash_dest += 4;
        src += 1;
    }

    #endif

    // lock the flash
    HAL_FLASH_Lock();
}

