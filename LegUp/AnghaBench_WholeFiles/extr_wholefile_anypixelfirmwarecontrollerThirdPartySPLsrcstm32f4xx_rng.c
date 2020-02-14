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
typedef  int uint8_t ;
typedef  int uint32_t ;
struct TYPE_2__ {int DR; int SR; int /*<<< orphan*/  CR; } ;
typedef  void* ITStatus ;
typedef  scalar_t__ FunctionalState ;
typedef  void* FlagStatus ;

/* Variables and functions */
 scalar_t__ DISABLE ; 
 scalar_t__ ENABLE ; 
 int /*<<< orphan*/  IS_FUNCTIONAL_STATE (scalar_t__) ; 
 int /*<<< orphan*/  IS_RNG_CLEAR_FLAG (int) ; 
 int /*<<< orphan*/  IS_RNG_GET_FLAG (int) ; 
 int /*<<< orphan*/  IS_RNG_GET_IT (int) ; 
 int /*<<< orphan*/  IS_RNG_IT (int) ; 
 int /*<<< orphan*/  RCC_AHB2PeriphResetCmd (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  RCC_AHB2Periph_RNG ; 
 void* RESET ; 
 TYPE_1__* RNG ; 
 int /*<<< orphan*/  RNG_CR_IE ; 
 int /*<<< orphan*/  RNG_CR_RNGEN ; 
 void* SET ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void RNG_DeInit(void)
{
  /* Enable RNG reset state */
  RCC_AHB2PeriphResetCmd(RCC_AHB2Periph_RNG, ENABLE);

  /* Release RNG from reset state */
  RCC_AHB2PeriphResetCmd(RCC_AHB2Periph_RNG, DISABLE);
}

void RNG_Cmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the RNG */
    RNG->CR |= RNG_CR_RNGEN;
  }
  else
  {
    /* Disable the RNG */
    RNG->CR &= ~RNG_CR_RNGEN;
  }
}

uint32_t RNG_GetRandomNumber(void)
{
  /* Return the 32 bit random number from the DR register */
  return RNG->DR;
}

void RNG_ITConfig(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the RNG interrupt */
    RNG->CR |= RNG_CR_IE;
  }
  else
  {
    /* Disable the RNG interrupt */
    RNG->CR &= ~RNG_CR_IE;
  }
}

FlagStatus RNG_GetFlagStatus(uint8_t RNG_FLAG)
{
  FlagStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_RNG_GET_FLAG(RNG_FLAG));

  /* Check the status of the specified RNG flag */
  if ((RNG->SR & RNG_FLAG) != (uint8_t)RESET)
  {
    /* RNG_FLAG is set */
    bitstatus = SET;
  }
  else
  {
    /* RNG_FLAG is reset */
    bitstatus = RESET;
  }
  /* Return the RNG_FLAG status */
  return  bitstatus;
}

void RNG_ClearFlag(uint8_t RNG_FLAG)
{
  /* Check the parameters */
  assert_param(IS_RNG_CLEAR_FLAG(RNG_FLAG));
  /* Clear the selected RNG flags */
  RNG->SR = ~(uint32_t)(((uint32_t)RNG_FLAG) << 4);
}

ITStatus RNG_GetITStatus(uint8_t RNG_IT)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_RNG_GET_IT(RNG_IT));

  /* Check the status of the specified RNG interrupt */
  if ((RNG->SR & RNG_IT) != (uint8_t)RESET)
  {
    /* RNG_IT is set */
    bitstatus = SET;
  }
  else
  {
    /* RNG_IT is reset */
    bitstatus = RESET;
  }
  /* Return the RNG_IT status */
  return bitstatus;
}

void RNG_ClearITPendingBit(uint8_t RNG_IT)
{
  /* Check the parameters */
  assert_param(IS_RNG_IT(RNG_IT));

  /* Clear the selected RNG interrupt pending bit */
  RNG->SR = (uint8_t)~RNG_IT;
}

