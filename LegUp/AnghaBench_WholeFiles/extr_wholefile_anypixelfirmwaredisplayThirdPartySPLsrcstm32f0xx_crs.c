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
typedef  scalar_t__ uint8_t ;
typedef  int uint32_t ;
struct TYPE_2__ {int CR; int CFGR; int ISR; int ICR; } ;
typedef  int /*<<< orphan*/  ITStatus ;
typedef  scalar_t__ FunctionalState ;
typedef  int /*<<< orphan*/  FlagStatus ;

/* Variables and functions */
 TYPE_1__* CRS ; 
 int CRS_CFGR_FELIM ; 
 int CRS_CFGR_RELOAD ; 
 int CRS_CFGR_SYNCDIV ; 
 int CRS_CFGR_SYNCPOL ; 
 int CRS_CFGR_SYNCSRC ; 
 int CRS_CR_AUTOTRIMEN ; 
 int CRS_CR_CEN ; 
 int CRS_CR_SWSYNC ; 
 int CRS_CR_TRIM ; 
 int CRS_ICR_ERRC ; 
 int CRS_ISR_FECAP ; 
 int CRS_ISR_FEDIR ; 
 scalar_t__ DISABLE ; 
 scalar_t__ ENABLE ; 
 int FLAG_MASK ; 
 int /*<<< orphan*/  IS_CRS_CLEAR_IT (int) ; 
 int /*<<< orphan*/  IS_CRS_FLAG (int) ; 
 int /*<<< orphan*/  IS_CRS_GET_IT (int) ; 
 int /*<<< orphan*/  IS_CRS_IT (int) ; 
 int /*<<< orphan*/  IS_CRS_SYNC_DIV (int) ; 
 int /*<<< orphan*/  IS_CRS_SYNC_POLARITY (int) ; 
 int /*<<< orphan*/  IS_CRS_SYNC_SOURCE (int) ; 
 int /*<<< orphan*/  IS_FUNCTIONAL_STATE (scalar_t__) ; 
 int /*<<< orphan*/  RCC_APB1PeriphResetCmd (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  RCC_APB1Periph_CRS ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void CRS_DeInit(void)
{
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_CRS, ENABLE);
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_CRS, DISABLE);
}

void CRS_AdjustHSI48CalibrationValue(uint8_t CRS_HSI48CalibrationValue)
{
  /* Clear TRIM[5:0] bits */
  CRS->CR &= ~CRS_CR_TRIM;
  
  /* Set the TRIM[5:0] bits according to CRS_HSI48CalibrationValue value */
  CRS->CR |= (uint32_t)((uint32_t)CRS_HSI48CalibrationValue << 8);

}

void CRS_FrequencyErrorCounterCmd(FunctionalState NewState)
{
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
     CRS->CR |= CRS_CR_CEN;
  }
  else
  {
    CRS->CR &= ~CRS_CR_CEN;
  }
}

void CRS_AutomaticCalibrationCmd(FunctionalState NewState)
{
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    CRS->CR |= CRS_CR_AUTOTRIMEN;
  }
else
  {
    CRS->CR &= ~CRS_CR_AUTOTRIMEN;
  }
}

void CRS_SoftwareSynchronizationGenerate(void)
{
  CRS->CR |= CRS_CR_SWSYNC;
}

void CRS_FrequencyErrorCounterReload(uint32_t CRS_ReloadValue)
{
 
  /* Clear RELOAD[15:0] bits */
  CRS->CFGR &= ~CRS_CFGR_RELOAD;
  
  /* Set the RELOAD[15:0] bits according to CRS_ReloadValue value */
  CRS->CFGR |= (uint32_t)CRS_ReloadValue;

}

void CRS_FrequencyErrorLimitConfig(uint8_t CRS_ErrorLimitValue)
{
  /* Clear FELIM[7:0] bits */
  CRS->CFGR &= ~CRS_CFGR_FELIM;
  
  /* Set the FELIM[7:0] bits according to CRS_ErrorLimitValue value */
  CRS->CFGR |= (uint32_t)CRS_ErrorLimitValue;
}

void CRS_SynchronizationPrescalerConfig(uint32_t CRS_Prescaler)
{
  /* Check the parameters */
  assert_param(IS_CRS_SYNC_DIV(CRS_Prescaler));
  
  /* Clear SYNCDIV[2:0] bits */
  CRS->CFGR &= ~CRS_CFGR_SYNCDIV;
  
  /* Set the CRS_CFGR_SYNCDIV[2:0] bits according to CRS_Prescaler value */
  CRS->CFGR |= CRS_Prescaler;
}

void CRS_SynchronizationSourceConfig(uint32_t CRS_Source)
{
  /* Check the parameters */
  assert_param(IS_CRS_SYNC_SOURCE(CRS_Source));
  
  /* Clear SYNCSRC[1:0] bits */
  CRS->CFGR &= ~CRS_CFGR_SYNCSRC;
  
  /* Set the SYNCSRC[1:0] bits according to CRS_Source value */
  CRS->CFGR |= CRS_Source;
}

void CRS_SynchronizationPolarityConfig(uint32_t CRS_Polarity)
{
  /* Check the parameters */
  assert_param(IS_CRS_SYNC_POLARITY(CRS_Polarity));
  
  /* Clear SYNCSPOL bit */
  CRS->CFGR &= ~CRS_CFGR_SYNCPOL;
  
  /* Set the SYNCSPOL bits according to CRS_Polarity value */
  CRS->CFGR |= CRS_Polarity;
}

uint32_t CRS_GetReloadValue(void)
{
  return ((uint32_t)(CRS->CFGR & CRS_CFGR_RELOAD));
}

uint32_t CRS_GetHSI48CalibrationValue(void)
{
  return (((uint32_t)(CRS->CR & CRS_CR_TRIM)) >> 8);
}

uint32_t CRS_GetFrequencyErrorValue(void)
{
  return ((uint32_t)(CRS->ISR & CRS_ISR_FECAP));
}

uint32_t CRS_GetFrequencyErrorDirection(void)
{
  return ((uint32_t)(CRS->ISR & CRS_ISR_FEDIR));
}

void CRS_ITConfig(uint32_t CRS_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_CRS_IT(CRS_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    CRS->CR |= CRS_IT;
  }
  else
  {
    CRS->CR &= ~CRS_IT;
  }
}

FlagStatus CRS_GetFlagStatus(uint32_t CRS_FLAG)
{
  /* Check the parameters */
  assert_param(IS_CRS_FLAG(CRS_FLAG));

  return ((FlagStatus)(CRS->ISR & CRS_FLAG));
}

void CRS_ClearFlag(uint32_t CRS_FLAG)
{
  /* Check the parameters */
  assert_param(IS_CRS_FLAG(CRS_FLAG));
  
  if ((CRS_FLAG & FLAG_MASK)!= 0)
  {
    CRS->ICR |= CRS_ICR_ERRC;  
  }
  else
  {
    CRS->ICR |= CRS_FLAG;
  }
}

ITStatus CRS_GetITStatus(uint32_t CRS_IT)
{
  /* Check the parameters */
  assert_param(IS_CRS_GET_IT(CRS_IT));

  return ((ITStatus)(CRS->ISR & CRS_IT));
}

void CRS_ClearITPendingBit(uint32_t CRS_IT)
{
  /* Check the parameters */
  assert_param(IS_CRS_CLEAR_IT(CRS_IT));
  
  if ((CRS_IT & FLAG_MASK)!= 0)
  {
    CRS->ICR |= CRS_ICR_ERRC;  
  }
  else
  {
    CRS->ICR |= CRS_IT;
  }
}

