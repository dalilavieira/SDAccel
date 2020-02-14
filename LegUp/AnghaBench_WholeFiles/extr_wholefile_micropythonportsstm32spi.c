#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int uint ;
struct TYPE_11__ {TYPE_3__* spi; int /*<<< orphan*/  rx_dma_descr; int /*<<< orphan*/  tx_dma_descr; } ;
typedef  TYPE_1__ spi_t ;
typedef  int /*<<< orphan*/  pin_obj_t ;
typedef  int mp_uint_t ;
typedef  int /*<<< orphan*/  mp_obj_t ;
typedef  int int32_t ;
struct TYPE_12__ {scalar_t__ CLKPolarity; int FirstBit; int /*<<< orphan*/  DataSize; int /*<<< orphan*/  CLKPhase; int /*<<< orphan*/  BaudRatePrescaler; } ;
struct TYPE_13__ {scalar_t__ Instance; TYPE_2__ Init; } ;
typedef  TYPE_2__ SPI_InitTypeDef ;
typedef  TYPE_3__ SPI_HandleTypeDef ;

/* Variables and functions */
 int /*<<< orphan*/  AF_FN_SPI ; 
 scalar_t__ HAL_OK ; 
 int HAL_RCC_GetPCLK1Freq () ; 
 int HAL_RCC_GetPCLK2Freq () ; 
 int /*<<< orphan*/  HAL_SPI_DeInit (TYPE_3__*) ; 
 scalar_t__ HAL_SPI_Init (TYPE_3__*) ; 
 int MP_ARRAY_SIZE (TYPE_1__ const*) ; 
 int MP_HAL_PIN_MODE_ALT ; 
 int MP_HAL_PIN_PULL_DOWN ; 
 int MP_HAL_PIN_PULL_UP ; 
 scalar_t__ SPI3 ; 
 int /*<<< orphan*/  SPI_BAUDRATEPRESCALER_128 ; 
 int /*<<< orphan*/  SPI_BAUDRATEPRESCALER_16 ; 
 int /*<<< orphan*/  SPI_BAUDRATEPRESCALER_2 ; 
 int /*<<< orphan*/  SPI_BAUDRATEPRESCALER_256 ; 
 int /*<<< orphan*/  SPI_BAUDRATEPRESCALER_32 ; 
 int /*<<< orphan*/  SPI_BAUDRATEPRESCALER_4 ; 
 int /*<<< orphan*/  SPI_BAUDRATEPRESCALER_64 ; 
 int /*<<< orphan*/  SPI_BAUDRATEPRESCALER_8 ; 
 int /*<<< orphan*/  SPI_DATASIZE_16BIT ; 
 int /*<<< orphan*/  SPI_DATASIZE_8BIT ; 
 int /*<<< orphan*/  SPI_PHASE_1EDGE ; 
 int /*<<< orphan*/  SPI_PHASE_2EDGE ; 
 scalar_t__ SPI_POLARITY_HIGH ; 
 scalar_t__ SPI_POLARITY_LOW ; 
 int /*<<< orphan*/  dma_invalidate_channel (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_hal_pin_config_alt (int /*<<< orphan*/  const*,int,int,int /*<<< orphan*/ ,int) ; 
 int mp_obj_get_int (int /*<<< orphan*/ ) ; 
 scalar_t__ mp_obj_is_str (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_obj_new_exception_msg_varg (int /*<<< orphan*/ *,char*,...) ; 
 char* mp_obj_str_get_str (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_type_ValueError ; 
 int /*<<< orphan*/  nlr_raise (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*) ; 
 TYPE_1__ const* spi_obj ; 

void spi_init0(void) {
    // Initialise the SPI handles.
    // The structs live on the BSS so all other fields will be zero after a reset.
    #if defined(MICROPY_HW_SPI1_SCK)
    SPIHandle1.Instance = SPI1;
    #endif
    #if defined(MICROPY_HW_SPI2_SCK)
    SPIHandle2.Instance = SPI2;
    #endif
    #if defined(MICROPY_HW_SPI3_SCK)
    SPIHandle3.Instance = SPI3;
    #endif
    #if defined(MICROPY_HW_SPI4_SCK)
    SPIHandle4.Instance = SPI4;
    #endif
    #if defined(MICROPY_HW_SPI5_SCK)
    SPIHandle5.Instance = SPI5;
    #endif
    #if defined(MICROPY_HW_SPI6_SCK)
    SPIHandle6.Instance = SPI6;
    #endif
}

int spi_find_index(mp_obj_t id) {
    if (mp_obj_is_str(id)) {
        // given a string id
        const char *port = mp_obj_str_get_str(id);
        if (0) {
        #ifdef MICROPY_HW_SPI1_NAME
        } else if (strcmp(port, MICROPY_HW_SPI1_NAME) == 0) {
            return 1;
        #endif
        #ifdef MICROPY_HW_SPI2_NAME
        } else if (strcmp(port, MICROPY_HW_SPI2_NAME) == 0) {
            return 2;
        #endif
        #ifdef MICROPY_HW_SPI3_NAME
        } else if (strcmp(port, MICROPY_HW_SPI3_NAME) == 0) {
            return 3;
        #endif
        #ifdef MICROPY_HW_SPI4_NAME
        } else if (strcmp(port, MICROPY_HW_SPI4_NAME) == 0) {
            return 4;
        #endif
        #ifdef MICROPY_HW_SPI5_NAME
        } else if (strcmp(port, MICROPY_HW_SPI5_NAME) == 0) {
            return 5;
        #endif
        #ifdef MICROPY_HW_SPI6_NAME
        } else if (strcmp(port, MICROPY_HW_SPI6_NAME) == 0) {
            return 6;
        #endif
        }
        nlr_raise(mp_obj_new_exception_msg_varg(&mp_type_ValueError,
            "SPI(%s) doesn't exist", port));
    } else {
        // given an integer id
        int spi_id = mp_obj_get_int(id);
        if (spi_id >= 1 && spi_id <= MP_ARRAY_SIZE(spi_obj)
            && spi_obj[spi_id - 1].spi != NULL) {
            return spi_id;
        }
        nlr_raise(mp_obj_new_exception_msg_varg(&mp_type_ValueError,
            "SPI(%d) doesn't exist", spi_id));
    }
}

void spi_set_params(const spi_t *spi_obj, uint32_t prescale, int32_t baudrate,
    int32_t polarity, int32_t phase, int32_t bits, int32_t firstbit) {
    SPI_HandleTypeDef *spi = spi_obj->spi;
    SPI_InitTypeDef *init = &spi->Init;

    if (prescale != 0xffffffff || baudrate != -1) {
        if (prescale == 0xffffffff) {
            // prescaler not given, so select one that yields at most the requested baudrate
            mp_uint_t spi_clock;
            #if defined(STM32F0)
            spi_clock = HAL_RCC_GetPCLK1Freq();
            #elif defined(STM32H7)
            if (spi->Instance == SPI1 || spi->Instance == SPI2 || spi->Instance == SPI3) {
                spi_clock = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_SPI123);
            } else if (spi->Instance == SPI4 || spi->Instance == SPI5) {
                spi_clock = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_SPI45);
            } else {
                spi_clock = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_SPI6);
            }
            #else
            if (spi->Instance == SPI3) {
                // SPI3 is on APB1
                spi_clock = HAL_RCC_GetPCLK1Freq();
            #if defined(SPI2)
            } else if (spi->Instance == SPI2) {
                // SPI2 is on APB1
                spi_clock = HAL_RCC_GetPCLK1Freq();
            #endif
            } else {
                // SPI1, SPI4, SPI5 and SPI6 are on APB2
                spi_clock = HAL_RCC_GetPCLK2Freq();
            }
            #endif
            prescale = (spi_clock + baudrate - 1) / baudrate;
        }
        if (prescale <= 2) { init->BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2; }
        else if (prescale <= 4) { init->BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4; }
        else if (prescale <= 8) { init->BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8; }
        else if (prescale <= 16) { init->BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16; }
        else if (prescale <= 32) { init->BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32; }
        else if (prescale <= 64) { init->BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64; }
        else if (prescale <= 128) { init->BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128; }
        else { init->BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256; }
    }

    if (polarity != -1) {
        init->CLKPolarity = polarity == 0 ? SPI_POLARITY_LOW : SPI_POLARITY_HIGH;
    }

    if (phase != -1) {
        init->CLKPhase = phase == 0 ? SPI_PHASE_1EDGE : SPI_PHASE_2EDGE;
    }

    if (bits != -1) {
        init->DataSize = (bits == 16) ? SPI_DATASIZE_16BIT : SPI_DATASIZE_8BIT;
    }

    if (firstbit != -1) {
        init->FirstBit = firstbit;
    }
}

void spi_init(const spi_t *self, bool enable_nss_pin) {
    SPI_HandleTypeDef *spi = self->spi;
    const pin_obj_t *pins[4] = { NULL, NULL, NULL, NULL };

    if (0) {
    #if defined(MICROPY_HW_SPI1_SCK)
    } else if (spi->Instance == SPI1) {
        #if defined(MICROPY_HW_SPI1_NSS)
        pins[0] = MICROPY_HW_SPI1_NSS;
        #endif
        pins[1] = MICROPY_HW_SPI1_SCK;
        #if defined(MICROPY_HW_SPI1_MISO)
        pins[2] = MICROPY_HW_SPI1_MISO;
        #endif
        pins[3] = MICROPY_HW_SPI1_MOSI;
        // enable the SPI clock
        __HAL_RCC_SPI1_CLK_ENABLE();
    #endif
    #if defined(MICROPY_HW_SPI2_SCK)
    } else if (spi->Instance == SPI2) {
        #if defined(MICROPY_HW_SPI2_NSS)
        pins[0] = MICROPY_HW_SPI2_NSS;
        #endif
        pins[1] = MICROPY_HW_SPI2_SCK;
        #if defined(MICROPY_HW_SPI2_MISO)
        pins[2] = MICROPY_HW_SPI2_MISO;
        #endif
        pins[3] = MICROPY_HW_SPI2_MOSI;
        // enable the SPI clock
        __HAL_RCC_SPI2_CLK_ENABLE();
    #endif
    #if defined(MICROPY_HW_SPI3_SCK)
    } else if (spi->Instance == SPI3) {
        #if defined(MICROPY_HW_SPI3_NSS)
        pins[0] = MICROPY_HW_SPI3_NSS;
        #endif
        pins[1] = MICROPY_HW_SPI3_SCK;
        #if defined(MICROPY_HW_SPI3_MISO)
        pins[2] = MICROPY_HW_SPI3_MISO;
        #endif
        pins[3] = MICROPY_HW_SPI3_MOSI;
        // enable the SPI clock
        __HAL_RCC_SPI3_CLK_ENABLE();
    #endif
    #if defined(MICROPY_HW_SPI4_SCK)
    } else if (spi->Instance == SPI4) {
        #if defined(MICROPY_HW_SPI4_NSS)
        pins[0] = MICROPY_HW_SPI4_NSS;
        #endif
        pins[1] = MICROPY_HW_SPI4_SCK;
        #if defined(MICROPY_HW_SPI4_MISO)
        pins[2] = MICROPY_HW_SPI4_MISO;
        #endif
        pins[3] = MICROPY_HW_SPI4_MOSI;
        // enable the SPI clock
        __HAL_RCC_SPI4_CLK_ENABLE();
    #endif
    #if defined(MICROPY_HW_SPI5_SCK)
    } else if (spi->Instance == SPI5) {
        #if defined(MICROPY_HW_SPI5_NSS)
        pins[0] = MICROPY_HW_SPI5_NSS;
        #endif
        pins[1] = MICROPY_HW_SPI5_SCK;
        #if defined(MICROPY_HW_SPI5_MISO)
        pins[2] = MICROPY_HW_SPI5_MISO;
        #endif
        pins[3] = MICROPY_HW_SPI5_MOSI;
        // enable the SPI clock
        __HAL_RCC_SPI5_CLK_ENABLE();
    #endif
    #if defined(MICROPY_HW_SPI6_SCK)
    } else if (spi->Instance == SPI6) {
        #if defined(MICROPY_HW_SPI6_NSS)
        pins[0] = MICROPY_HW_SPI6_NSS;
        #endif
        pins[1] = MICROPY_HW_SPI6_SCK;
        #if defined(MICROPY_HW_SPI6_MISO)
        pins[2] = MICROPY_HW_SPI6_MISO;
        #endif
        pins[3] = MICROPY_HW_SPI6_MOSI;
        // enable the SPI clock
        __HAL_RCC_SPI6_CLK_ENABLE();
    #endif
    } else {
        // SPI does not exist for this board (shouldn't get here, should be checked by caller)
        return;
    }

    // init the GPIO lines
    uint32_t mode = MP_HAL_PIN_MODE_ALT;
    uint32_t pull = spi->Init.CLKPolarity == SPI_POLARITY_LOW ? MP_HAL_PIN_PULL_DOWN : MP_HAL_PIN_PULL_UP;
    for (uint i = (enable_nss_pin ? 0 : 1); i < 4; i++) {
        if (pins[i] == NULL) {
            continue;
        }
        mp_hal_pin_config_alt(pins[i], mode, pull, AF_FN_SPI, (self - &spi_obj[0]) + 1);
    }

    // init the SPI device
    if (HAL_SPI_Init(spi) != HAL_OK) {
        // init error
        // TODO should raise an exception, but this function is not necessarily going to be
        // called via Python, so may not be properly wrapped in an NLR handler
        printf("OSError: HAL_SPI_Init failed\n");
        return;
    }

    // After calling HAL_SPI_Init() it seems that the DMA gets disconnected if
    // it was previously configured.  So we invalidate the DMA channel to force
    // an initialisation the next time we use it.
    dma_invalidate_channel(self->tx_dma_descr);
    dma_invalidate_channel(self->rx_dma_descr);
}

void spi_deinit(const spi_t *spi_obj) {
    SPI_HandleTypeDef *spi = spi_obj->spi;
    HAL_SPI_DeInit(spi);
    if (0) {
    #if defined(MICROPY_HW_SPI1_SCK)
    } else if (spi->Instance == SPI1) {
        __HAL_RCC_SPI1_FORCE_RESET();
        __HAL_RCC_SPI1_RELEASE_RESET();
        __HAL_RCC_SPI1_CLK_DISABLE();
    #endif
    #if defined(MICROPY_HW_SPI2_SCK)
    } else if (spi->Instance == SPI2) {
        __HAL_RCC_SPI2_FORCE_RESET();
        __HAL_RCC_SPI2_RELEASE_RESET();
        __HAL_RCC_SPI2_CLK_DISABLE();
    #endif
    #if defined(MICROPY_HW_SPI3_SCK)
    } else if (spi->Instance == SPI3) {
        __HAL_RCC_SPI3_FORCE_RESET();
        __HAL_RCC_SPI3_RELEASE_RESET();
        __HAL_RCC_SPI3_CLK_DISABLE();
    #endif
    #if defined(MICROPY_HW_SPI4_SCK)
    } else if (spi->Instance == SPI4) {
        __HAL_RCC_SPI4_FORCE_RESET();
        __HAL_RCC_SPI4_RELEASE_RESET();
        __HAL_RCC_SPI4_CLK_DISABLE();
    #endif
    #if defined(MICROPY_HW_SPI5_SCK)
    } else if (spi->Instance == SPI5) {
        __HAL_RCC_SPI5_FORCE_RESET();
        __HAL_RCC_SPI5_RELEASE_RESET();
        __HAL_RCC_SPI5_CLK_DISABLE();
    #endif
    #if defined(MICROPY_HW_SPI6_SCK)
    } else if (spi->Instance == SPI6) {
        __HAL_RCC_SPI6_FORCE_RESET();
        __HAL_RCC_SPI6_RELEASE_RESET();
        __HAL_RCC_SPI6_CLK_DISABLE();
    #endif
    }
}

