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
typedef  size_t uint32_t ;
typedef  scalar_t__ uint16_t ;
struct TYPE_2__ {int DR; int POL; int IDR; int INIT; size_t CR; } ;
typedef  scalar_t__ FunctionalState ;

/* Variables and functions */
 TYPE_1__* CRC ; 
 scalar_t__ CRC_BASE ; 
 scalar_t__ CRC_CR_POLSIZE ; 
 size_t CRC_CR_RESET ; 
 scalar_t__ CRC_CR_REV_IN ; 
 size_t CRC_CR_REV_OUT ; 
 scalar_t__ DISABLE ; 
 int /*<<< orphan*/  IS_CRC_POL_SIZE (size_t) ; 
 int /*<<< orphan*/  IS_CRC_REVERSE_INPUT_DATA (size_t) ; 
 int /*<<< orphan*/  IS_FUNCTIONAL_STATE (scalar_t__) ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void CRC_DeInit(void)
{
  /* Set DR register to reset value */
  CRC->DR = 0xFFFFFFFF;
  
  /* Set the POL register to the reset value: 0x04C11DB7 */
  CRC->POL = 0x04C11DB7;
  
  /* Reset IDR register */
  CRC->IDR = 0x00;
  
  /* Set INIT register to reset value */
  CRC->INIT = 0xFFFFFFFF;
  
  /* Reset the CRC calculation unit */
  CRC->CR = CRC_CR_RESET;
}

void CRC_ResetDR(void)
{
  /* Reset CRC generator */
  CRC->CR |= CRC_CR_RESET;
}

void CRC_PolynomialSizeSelect(uint32_t CRC_PolSize)
{
  uint32_t tmpcr = 0;

  /* Check the parameter */
  assert_param(IS_CRC_POL_SIZE(CRC_PolSize));

  /* Get CR register value */
  tmpcr = CRC->CR;

  /* Reset POL_SIZE bits */
  tmpcr &= (uint32_t)~((uint32_t)CRC_CR_POLSIZE);
  /* Set the polynomial size */
  tmpcr |= (uint32_t)CRC_PolSize;

  /* Write to CR register */
  CRC->CR = (uint32_t)tmpcr;
}

void CRC_ReverseInputDataSelect(uint32_t CRC_ReverseInputData)
{
  uint32_t tmpcr = 0;

  /* Check the parameter */
  assert_param(IS_CRC_REVERSE_INPUT_DATA(CRC_ReverseInputData));

  /* Get CR register value */
  tmpcr = CRC->CR;

  /* Reset REV_IN bits */
  tmpcr &= (uint32_t)~((uint32_t)CRC_CR_REV_IN);
  /* Set the reverse operation */
  tmpcr |= (uint32_t)CRC_ReverseInputData;

  /* Write to CR register */
  CRC->CR = (uint32_t)tmpcr;
}

void CRC_ReverseOutputDataCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable reverse operation on output data */
    CRC->CR |= CRC_CR_REV_OUT;
  }
  else
  {
    /* Disable reverse operation on output data */
    CRC->CR &= (uint32_t)~((uint32_t)CRC_CR_REV_OUT);
  }
}

void CRC_SetInitRegister(uint32_t CRC_InitValue)
{
  CRC->INIT = CRC_InitValue;
}

void CRC_SetPolynomial(uint32_t CRC_Pol)
{
  CRC->POL = CRC_Pol;
}

uint32_t CRC_CalcCRC(uint32_t CRC_Data)
{
  CRC->DR = CRC_Data;
  
  return (CRC->DR);
}

uint32_t CRC_CalcCRC16bits(uint16_t CRC_Data)
{
  *(uint16_t*)(CRC_BASE) = (uint16_t) CRC_Data;
  
  return (CRC->DR);
}

uint32_t CRC_CalcCRC8bits(uint8_t CRC_Data)
{
  *(uint8_t*)(CRC_BASE) = (uint8_t) CRC_Data;

  return (CRC->DR);
}

uint32_t CRC_CalcBlockCRC(uint32_t pBuffer[], uint32_t BufferLength)
{
  uint32_t index = 0;
  
  for(index = 0; index < BufferLength; index++)
  {
    CRC->DR = pBuffer[index];
  }
  return (CRC->DR);
}

uint32_t CRC_GetCRC(void)
{
  return (CRC->DR);
}

void CRC_SetIDRegister(uint8_t CRC_IDValue)
{
  CRC->IDR = CRC_IDValue;
}

uint8_t CRC_GetIDRegister(void)
{
  return (CRC->IDR);
}

