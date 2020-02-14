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
typedef  int uint32_t ;
struct TYPE_6__ {int ACR; } ;
struct TYPE_5__ {int CR; int CFGR; int CFGR2; int CR2; int CIR; } ;
struct TYPE_4__ {int /*<<< orphan*/  CCR; } ;

/* Variables and functions */
 int* AHBPrescTable ; 
 TYPE_3__* FLASH ; 
 int HAL_RCC_GetHCLKFreq () ; 
 int /*<<< orphan*/  HAL_SYSTICK_CLKSourceConfig (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HAL_SYSTICK_Config (int) ; 
 int HSE_VALUE ; 
 int HSI48_VALUE ; 
 int HSI_VALUE ; 
 TYPE_2__* RCC ; 
 int RCC_CFGR2_PREDIV ; 
 int RCC_CFGR_HPRE ; 
 int RCC_CFGR_PLLMUL ; 
 int RCC_CFGR_PLLMUL_Pos ; 
 int RCC_CFGR_PLLSRC ; 
 int RCC_CFGR_PLLSRC_HSE_PREDIV ; 
 int RCC_CFGR_PLLSRC_Pos ; 
 int RCC_CFGR_SWS ; 
#define  RCC_CFGR_SWS_HSE 131 
#define  RCC_CFGR_SWS_HSI 130 
#define  RCC_CFGR_SWS_HSI48 129 
#define  RCC_CFGR_SWS_PLL 128 
 int RCC_CFGR_SWS_Pos ; 
 int const RCC_CFGR_SW_Pos ; 
 int RCC_CR_HSEON ; 
 int RCC_CR_HSERDY ; 
 int RCC_CR_PLLON ; 
 int RCC_CR_PLLRDY ; 
 TYPE_1__* SCB ; 
 int /*<<< orphan*/  SCB_CCR_STKALIGN_Msk ; 
 int /*<<< orphan*/  SYSTICK_CLKSOURCE_HCLK ; 
 int SystemCoreClock ; 
 void SystemCoreClockUpdate () ; 
 int /*<<< orphan*/  __HAL_RCC_PWR_CLK_ENABLE () ; 

void SystemInit(void) {
    // Set HSION bit
    RCC->CR |= (uint32_t)0x00000001U;

    #if defined(STM32F051x8) || defined(STM32F058x8)
    // Reset SW[1:0], HPRE[3:0], PPRE[2:0], ADCPRE and MCOSEL[2:0] bits
    RCC->CFGR &= (uint32_t)0xF8FFB80CU;
    #else
    // Reset SW[1:0], HPRE[3:0], PPRE[2:0], ADCPRE, MCOSEL[2:0], MCOPRE[2:0] and PLLNODIV bits
    RCC->CFGR &= (uint32_t)0x08FFB80CU;
    #endif

    // Reset HSEON, CSSON and PLLON bits
    RCC->CR &= (uint32_t)0xFEF6FFFFU;

    // Reset HSEBYP bit
    RCC->CR &= (uint32_t)0xFFFBFFFFU;

    // Reset PLLSRC, PLLXTPRE and PLLMUL[3:0] bits
    RCC->CFGR &= (uint32_t)0xFFC0FFFFU;

    // Reset PREDIV[3:0] bits
    RCC->CFGR2 &= (uint32_t)0xFFFFFFF0U;

    #if defined(STM32F072xB) || defined(STM32F078xx)
    // Reset USART2SW[1:0], USART1SW[1:0], I2C1SW, CECSW, USBSW and ADCSW bits
    RCC->CFGR3 &= (uint32_t)0xFFFCFE2CU;
    #elif defined(STM32F071xB)
    // Reset USART2SW[1:0], USART1SW[1:0], I2C1SW, CECSW and ADCSW bits
    RCC->CFGR3 &= (uint32_t)0xFFFFCEACU;
    #elif defined(STM32F091xC) || defined(STM32F098xx)
    // Reset USART3SW[1:0], USART2SW[1:0], USART1SW[1:0], I2C1SW, CECSW and ADCSW bits
    RCC->CFGR3 &= (uint32_t)0xFFF0FEACU;
    #elif defined(STM32F030x6) || defined(STM32F030x8) || defined(STM32F031x6) || defined(STM32F038xx) || defined(STM32F030xC)
    // Reset USART1SW[1:0], I2C1SW and ADCSW bits
    RCC->CFGR3 &= (uint32_t)0xFFFFFEECU;
    #elif defined(STM32F051x8) || defined(STM32F058xx)
    // Reset USART1SW[1:0], I2C1SW, CECSW and ADCSW bits
    RCC->CFGR3 &= (uint32_t)0xFFFFFEACU;
    #elif defined(STM32F042x6) || defined(STM32F048xx)
    // Reset USART1SW[1:0], I2C1SW, CECSW, USBSW and ADCSW bits
    RCC->CFGR3 &= (uint32_t)0xFFFFFE2CU;
    #elif defined(STM32F070x6) || defined(STM32F070xB)
    // Reset USART1SW[1:0], I2C1SW, USBSW and ADCSW bits
    RCC->CFGR3 &= (uint32_t)0xFFFFFE6CU;
    // Set default USB clock to PLLCLK, since there is no HSI48
    RCC->CFGR3 |= (uint32_t)0x00000080U;
    #else
    #warning "No target selected"
    #endif

    // Reset HSI14 bit
    RCC->CR2 &= (uint32_t)0xFFFFFFFEU;

    // Disable all interrupts
    RCC->CIR = 0x00000000U;

    // dpgeorge: enable 8-byte stack alignment for IRQ handlers, in accord with EABI
    SCB->CCR |= SCB_CCR_STKALIGN_Msk;
}

void SystemClock_Config(void) {
    // Enable power control peripheral
    __HAL_RCC_PWR_CLK_ENABLE();

    // Set flash latency to 1 because SYSCLK > 24MHz
    FLASH->ACR = (FLASH->ACR & ~0x7) | 0x1;

    #if MICROPY_HW_CLK_USE_HSI48
    // Use the 48MHz internal oscillator

    RCC->CR2 |= RCC_CR2_HSI48ON;
    while ((RCC->CR2 & RCC_CR2_HSI48RDY) == 0) {
    }
    const uint32_t sysclk_src = 3;

    #else
    // Use HSE and the PLL to get a 48MHz SYSCLK

    #if MICROPY_HW_CLK_USE_BYPASS
    RCC->CR |= RCC_CR_HSEBYP;
    #endif
    RCC->CR |= RCC_CR_HSEON;
    while ((RCC->CR & RCC_CR_HSERDY) == 0) {
        // Wait for HSE to be ready
    }
    RCC->CFGR = ((48000000 / HSE_VALUE) - 2) << RCC_CFGR_PLLMUL_Pos | 2 << RCC_CFGR_PLLSRC_Pos;
    RCC->CFGR2 = 0; // Input clock not divided
    RCC->CR |= RCC_CR_PLLON; // Turn PLL on
    while ((RCC->CR & RCC_CR_PLLRDY) == 0) {
        // Wait for PLL to lock
    }
    const uint32_t sysclk_src = 2;

    #endif

    // Select SYSCLK source
    RCC->CFGR |= sysclk_src << RCC_CFGR_SW_Pos;
    while (((RCC->CFGR >> RCC_CFGR_SWS_Pos) & 0x3) != sysclk_src) {
        // Wait for SYSCLK source to change
    }

    SystemCoreClockUpdate();

    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
}

void SystemCoreClockUpdate(void) {
    // Get SYSCLK source
    uint32_t tmp = RCC->CFGR & RCC_CFGR_SWS;

    switch (tmp) {
        case RCC_CFGR_SWS_HSI:
            SystemCoreClock = HSI_VALUE;
            break;
        case RCC_CFGR_SWS_HSE:
            SystemCoreClock = HSE_VALUE;
            break;
        case RCC_CFGR_SWS_PLL: {
            /* Get PLL clock source and multiplication factor */
            uint32_t pllmull = RCC->CFGR & RCC_CFGR_PLLMUL;
            uint32_t pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;
            pllmull = (pllmull >> 18) + 2;
            uint32_t predivfactor = (RCC->CFGR2 & RCC_CFGR2_PREDIV) + 1;

            if (pllsource == RCC_CFGR_PLLSRC_HSE_PREDIV) {
                /* HSE used as PLL clock source : SystemCoreClock = HSE/PREDIV * PLLMUL */
                SystemCoreClock = (HSE_VALUE/predivfactor) * pllmull;
            #if defined(STM32F042x6) || defined(STM32F048xx) || defined(STM32F072xB) \
                || defined(STM32F078xx) || defined(STM32F091xC) || defined(STM32F098xx)
            } else if (pllsource == RCC_CFGR_PLLSRC_HSI48_PREDIV) {
                /* HSI48 used as PLL clock source : SystemCoreClock = HSI48/PREDIV * PLLMUL */
                SystemCoreClock = (HSI48_VALUE/predivfactor) * pllmull;
            #endif
            } else {
                #if defined(STM32F042x6) || defined(STM32F048xx)  || defined(STM32F070x6) \
                    || defined(STM32F078xx) || defined(STM32F071xB)  || defined(STM32F072xB) \
                    || defined(STM32F070xB) || defined(STM32F091xC) || defined(STM32F098xx)  || defined(STM32F030xC)
                /* HSI used as PLL clock source : SystemCoreClock = HSI/PREDIV * PLLMUL */
                SystemCoreClock = (HSI_VALUE / predivfactor) * pllmull;
                #else
                /* HSI used as PLL clock source : SystemCoreClock = HSI/2 * PLLMUL */
                SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
                #endif
            }
            break;
        }
        case RCC_CFGR_SWS_HSI48:
            SystemCoreClock = HSI48_VALUE;
            break;
        default:
            SystemCoreClock = HSI_VALUE;
            break;
    }

    // Compute HCLK clock frequency
    tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
    SystemCoreClock >>= tmp;
}

