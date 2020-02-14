#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_9__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct TYPE_13__ {int CR; int STR; int DIN; int IMR; int SR; int /*<<< orphan*/ * CSR; int /*<<< orphan*/ * HR; } ;
struct TYPE_12__ {int HASH_IMR; int HASH_STR; int HASH_CR; int /*<<< orphan*/ * HASH_CSR; } ;
struct TYPE_11__ {int HASH_AlgoSelection; int HASH_DataType; int HASH_AlgoMode; int HASH_HMACKeyType; } ;
struct TYPE_10__ {int /*<<< orphan*/ * Data; } ;
typedef  int ITStatus ;
typedef  TYPE_1__ HASH_MsgDigest ;
typedef  TYPE_2__ HASH_InitTypeDef ;
typedef  TYPE_3__ HASH_Context ;
typedef  scalar_t__ FunctionalState ;
typedef  int FlagStatus ;

/* Variables and functions */
 scalar_t__ DISABLE ; 
 scalar_t__ ENABLE ; 
 TYPE_9__* HASH ; 
 int HASH_AlgoMode_HASH ; 
 int HASH_AlgoMode_HMAC ; 
 int HASH_AlgoSelection_SHA1 ; 
 int HASH_CR_ALGO ; 
 int HASH_CR_DATATYPE ; 
 int HASH_CR_DMAE ; 
 int HASH_CR_INIT ; 
 int HASH_CR_LKEY ; 
 int HASH_CR_MODE ; 
 int HASH_CR_NBW ; 
 int HASH_DataType_32b ; 
 int HASH_FLAG_DINNE ; 
 int HASH_HMACKeyType_ShortKey ; 
 int HASH_STR_DCAL ; 
 int HASH_STR_NBW ; 
 int /*<<< orphan*/  IS_FUNCTIONAL_STATE (scalar_t__) ; 
 int /*<<< orphan*/  IS_HASH_ALGOMODE (int) ; 
 int /*<<< orphan*/  IS_HASH_ALGOSELECTION (int) ; 
 int /*<<< orphan*/  IS_HASH_CLEAR_FLAG (int) ; 
 int /*<<< orphan*/  IS_HASH_DATATYPE (int) ; 
 int /*<<< orphan*/  IS_HASH_GET_FLAG (int) ; 
 int /*<<< orphan*/  IS_HASH_GET_IT (int) ; 
 int /*<<< orphan*/  IS_HASH_HMAC_KEYTYPE (int) ; 
 int /*<<< orphan*/  IS_HASH_IT (int) ; 
 int /*<<< orphan*/  IS_HASH_VALIDBITSNUMBER (int) ; 
 int /*<<< orphan*/  RCC_AHB2PeriphResetCmd (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  RCC_AHB2Periph_HASH ; 
 int RESET ; 
 void* SET ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void HASH_DeInit(void)
{
  /* Enable HASH reset state */
  RCC_AHB2PeriphResetCmd(RCC_AHB2Periph_HASH, ENABLE);
  /* Release HASH from reset state */
  RCC_AHB2PeriphResetCmd(RCC_AHB2Periph_HASH, DISABLE);
}

void HASH_Init(HASH_InitTypeDef* HASH_InitStruct)
{
  /* Check the parameters */
  assert_param(IS_HASH_ALGOSELECTION(HASH_InitStruct->HASH_AlgoSelection));
  assert_param(IS_HASH_DATATYPE(HASH_InitStruct->HASH_DataType));
  assert_param(IS_HASH_ALGOMODE(HASH_InitStruct->HASH_AlgoMode));
  
  /* Configure the Algorithm used, algorithm mode and the datatype */
  HASH->CR &= ~ (HASH_CR_ALGO | HASH_CR_DATATYPE | HASH_CR_MODE);
  HASH->CR |= (HASH_InitStruct->HASH_AlgoSelection | \
               HASH_InitStruct->HASH_DataType | \
               HASH_InitStruct->HASH_AlgoMode);
  
  /* if algorithm mode is HMAC, set the Key */  
  if(HASH_InitStruct->HASH_AlgoMode == HASH_AlgoMode_HMAC) 
  {
    assert_param(IS_HASH_HMAC_KEYTYPE(HASH_InitStruct->HASH_HMACKeyType));
    HASH->CR &= ~HASH_CR_LKEY;
    HASH->CR |= HASH_InitStruct->HASH_HMACKeyType;
  }

  /* Reset the HASH processor core, so that the HASH will be ready to compute 
     the message digest of a new message */
  HASH->CR |= HASH_CR_INIT;  
}

void HASH_StructInit(HASH_InitTypeDef* HASH_InitStruct)
{
  /* Initialize the HASH_AlgoSelection member */
  HASH_InitStruct->HASH_AlgoSelection = HASH_AlgoSelection_SHA1;

  /* Initialize the HASH_AlgoMode member */
  HASH_InitStruct->HASH_AlgoMode = HASH_AlgoMode_HASH;

  /* Initialize the HASH_DataType member */
  HASH_InitStruct->HASH_DataType = HASH_DataType_32b;

  /* Initialize the HASH_HMACKeyType member */
  HASH_InitStruct->HASH_HMACKeyType = HASH_HMACKeyType_ShortKey;
}

void HASH_Reset(void)
{
  /* Reset the HASH processor core */
  HASH->CR |= HASH_CR_INIT;
}

void HASH_SetLastWordValidBitsNbr(uint16_t ValidNumber)
{
  /* Check the parameters */
  assert_param(IS_HASH_VALIDBITSNUMBER(ValidNumber));
  
  /* Configure the Number of valid bits in last word of the message */
  HASH->STR &= ~(HASH_STR_NBW);
  HASH->STR |= ValidNumber;
}

void HASH_DataIn(uint32_t Data)
{
  /* Write in the DIN register a new data */
  HASH->DIN = Data;
}

uint8_t HASH_GetInFIFOWordsNbr(void)
{
  /* Return the value of NBW bits */
  return ((HASH->CR & HASH_CR_NBW) >> 8);
}

void HASH_GetDigest(HASH_MsgDigest* HASH_MessageDigest)
{
  /* Get the data field */
  HASH_MessageDigest->Data[0] = HASH->HR[0];
  HASH_MessageDigest->Data[1] = HASH->HR[1];
  HASH_MessageDigest->Data[2] = HASH->HR[2];
  HASH_MessageDigest->Data[3] = HASH->HR[3];
  HASH_MessageDigest->Data[4] = HASH->HR[4];
}

void HASH_StartDigest(void)
{
  /* Start the Digest calculation */
  HASH->STR |= HASH_STR_DCAL;
}

void HASH_SaveContext(HASH_Context* HASH_ContextSave)
{
  uint8_t i = 0;
  
  /* save context registers */
  HASH_ContextSave->HASH_IMR = HASH->IMR;  
  HASH_ContextSave->HASH_STR = HASH->STR;      
  HASH_ContextSave->HASH_CR  = HASH->CR;     
  for(i=0; i<=50;i++)
  {
     HASH_ContextSave->HASH_CSR[i] = HASH->CSR[i];
  }   
}

void HASH_RestoreContext(HASH_Context* HASH_ContextRestore)  
{
  uint8_t i = 0;
  
  /* restore context registers */
  HASH->IMR = HASH_ContextRestore->HASH_IMR;   
  HASH->STR = HASH_ContextRestore->HASH_STR;     
  HASH->CR = HASH_ContextRestore->HASH_CR;
  
  /* Initialize the hash processor */
  HASH->CR |= HASH_CR_INIT; 
  
   /* continue restoring context registers */     
  for(i=0; i<=50;i++)
  {
     HASH->CSR[i] = HASH_ContextRestore->HASH_CSR[i];
  }   
}

void HASH_DMACmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the HASH DMA request */
    HASH->CR |= HASH_CR_DMAE;
  }
  else
  {
    /* Disable the HASH DMA request */
    HASH->CR &= ~HASH_CR_DMAE;
  }
}

void HASH_ITConfig(uint8_t HASH_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_HASH_IT(HASH_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the selected HASH interrupt */
    HASH->IMR |= HASH_IT;
  }
  else
  {
    /* Disable the selected HASH interrupt */
    HASH->IMR &= (uint8_t) ~HASH_IT;
  }
}

FlagStatus HASH_GetFlagStatus(uint16_t HASH_FLAG)
{
  FlagStatus bitstatus = RESET;
  uint32_t tempreg = 0;

  /* Check the parameters */
  assert_param(IS_HASH_GET_FLAG(HASH_FLAG));

  /* check if the FLAG is in CR register */
  if ((HASH_FLAG & HASH_FLAG_DINNE) != (uint16_t)RESET ) 
  {
    tempreg = HASH->CR;
  }
  else /* The FLAG is in SR register */
  {
    tempreg = HASH->SR;
  }

  /* Check the status of the specified HASH flag */
  if ((tempreg & HASH_FLAG) != (uint16_t)RESET)
  {
    /* HASH is set */
    bitstatus = SET;
  }
  else
  {
    /* HASH_FLAG is reset */
    bitstatus = RESET;
  }

  /* Return the HASH_FLAG status */
  return  bitstatus;
}

void HASH_ClearFlag(uint16_t HASH_FLAG)
{
  /* Check the parameters */
  assert_param(IS_HASH_CLEAR_FLAG(HASH_FLAG));
  
  /* Clear the selected HASH flags */
  HASH->SR = ~(uint32_t)HASH_FLAG;
}

ITStatus HASH_GetITStatus(uint8_t HASH_IT)
{
  ITStatus bitstatus = RESET;
  uint32_t tmpreg = 0;

  /* Check the parameters */
  assert_param(IS_HASH_GET_IT(HASH_IT));  


  /* Check the status of the specified HASH interrupt */
  tmpreg =  HASH->SR;

  if (((HASH->IMR & tmpreg) & HASH_IT) != RESET)
  {
    /* HASH_IT is set */
    bitstatus = SET;
  }
  else
  {
    /* HASH_IT is reset */
    bitstatus = RESET;
  }
  /* Return the HASH_IT status */
  return bitstatus;
}

void HASH_ClearITPendingBit(uint8_t HASH_IT)
{
  /* Check the parameters */
  assert_param(IS_HASH_IT(HASH_IT));

  /* Clear the selected HASH interrupt pending bit */
  HASH->SR = (uint8_t)~HASH_IT;
}

