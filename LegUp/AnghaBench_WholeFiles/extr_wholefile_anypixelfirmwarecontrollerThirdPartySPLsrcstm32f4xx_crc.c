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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  size_t uint32_t ;
struct TYPE_2__ {size_t DR; int /*<<< orphan*/  IDR; int /*<<< orphan*/  CR; } ;

/* Variables and functions */
 TYPE_1__* CRC ; 
 int /*<<< orphan*/  CRC_CR_RESET ; 

void CRC_ResetDR(void)
{
  /* Reset CRC generator */
  CRC->CR = CRC_CR_RESET;
}

uint32_t CRC_CalcCRC(uint32_t Data)
{
  CRC->DR = Data;
  
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

void CRC_SetIDRegister(uint8_t IDValue)
{
  CRC->IDR = IDValue;
}

uint8_t CRC_GetIDRegister(void)
{
  return (CRC->IDR);
}

