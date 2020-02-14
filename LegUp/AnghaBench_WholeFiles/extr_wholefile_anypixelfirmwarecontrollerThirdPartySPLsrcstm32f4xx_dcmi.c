#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_8__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int uint16_t ;
struct TYPE_12__ {int CR; int IER; int ICR; int ESCR; int ESUR; int CWSTRTR; int CWSIZER; int DR; int RISR; int SR; int MISR; } ;
struct TYPE_11__ {int DCMI_CaptureCount; scalar_t__ DCMI_VerticalLineCount; scalar_t__ DCMI_VerticalStartLine; scalar_t__ DCMI_HorizontalOffsetCount; } ;
struct TYPE_10__ {int DCMI_FrameStartCode; scalar_t__ DCMI_FrameEndCode; scalar_t__ DCMI_LineEndCode; scalar_t__ DCMI_LineStartCode; } ;
struct TYPE_9__ {int DCMI_SynchroMode; int DCMI_PCKPolarity; int DCMI_VSPolarity; int DCMI_HSPolarity; int DCMI_CaptureRate; int DCMI_ExtendedDataMode; scalar_t__ DCMI_CaptureMode; } ;
typedef  void* ITStatus ;
typedef  scalar_t__ FunctionalState ;
typedef  void* FlagStatus ;
typedef  TYPE_1__ DCMI_InitTypeDef ;
typedef  TYPE_2__ DCMI_CodesInitTypeDef ;
typedef  TYPE_3__ DCMI_CROPInitTypeDef ;

/* Variables and functions */
 TYPE_8__* DCMI ; 
 int DCMI_CR_CAPTURE ; 
 scalar_t__ DCMI_CR_CM ; 
 scalar_t__ DCMI_CR_CROP ; 
 int DCMI_CR_EDM_0 ; 
 int DCMI_CR_EDM_1 ; 
 int DCMI_CR_ENABLE ; 
 int DCMI_CR_ESS ; 
 int DCMI_CR_FCRC_0 ; 
 int DCMI_CR_FCRC_1 ; 
 int DCMI_CR_HSPOL ; 
 scalar_t__ DCMI_CR_JPEG ; 
 int DCMI_CR_PCKPOL ; 
 int DCMI_CR_VSPOL ; 
 scalar_t__ DCMI_CaptureMode_Continuous ; 
 int DCMI_CaptureRate_All_Frame ; 
 int DCMI_ExtendedDataMode_8b ; 
 int DCMI_HSPolarity_Low ; 
 int DCMI_PCKPolarity_Falling ; 
 int DCMI_SynchroMode_Hardware ; 
 int DCMI_VSPolarity_Low ; 
 scalar_t__ DISABLE ; 
 int /*<<< orphan*/  IS_DCMI_CAPTURE_MODE (scalar_t__) ; 
 int /*<<< orphan*/  IS_DCMI_CAPTURE_RATE (int) ; 
 int /*<<< orphan*/  IS_DCMI_CLEAR_FLAG (int) ; 
 int /*<<< orphan*/  IS_DCMI_CONFIG_IT (int) ; 
 int /*<<< orphan*/  IS_DCMI_EXTENDED_DATA (int) ; 
 int /*<<< orphan*/  IS_DCMI_GET_FLAG (int) ; 
 int /*<<< orphan*/  IS_DCMI_GET_IT (int) ; 
 int /*<<< orphan*/  IS_DCMI_HSPOLARITY (int) ; 
 int /*<<< orphan*/  IS_DCMI_PCKPOLARITY (int) ; 
 int /*<<< orphan*/  IS_DCMI_SYNCHRO (int) ; 
 int /*<<< orphan*/  IS_DCMI_VSPOLARITY (int) ; 
 int /*<<< orphan*/  IS_FUNCTIONAL_STATE (scalar_t__) ; 
 void* RESET ; 
 void* SET ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void DCMI_DeInit(void)
{
  DCMI->CR = 0x0;
  DCMI->IER = 0x0;
  DCMI->ICR = 0x1F;
  DCMI->ESCR = 0x0;
  DCMI->ESUR = 0x0;
  DCMI->CWSTRTR = 0x0;
  DCMI->CWSIZER = 0x0;
}

void DCMI_Init(DCMI_InitTypeDef* DCMI_InitStruct)
{
  uint32_t temp = 0x0;
  
  /* Check the parameters */
  assert_param(IS_DCMI_CAPTURE_MODE(DCMI_InitStruct->DCMI_CaptureMode));
  assert_param(IS_DCMI_SYNCHRO(DCMI_InitStruct->DCMI_SynchroMode));
  assert_param(IS_DCMI_PCKPOLARITY(DCMI_InitStruct->DCMI_PCKPolarity));
  assert_param(IS_DCMI_VSPOLARITY(DCMI_InitStruct->DCMI_VSPolarity));
  assert_param(IS_DCMI_HSPOLARITY(DCMI_InitStruct->DCMI_HSPolarity));
  assert_param(IS_DCMI_CAPTURE_RATE(DCMI_InitStruct->DCMI_CaptureRate));
  assert_param(IS_DCMI_EXTENDED_DATA(DCMI_InitStruct->DCMI_ExtendedDataMode));

  /* The DCMI configuration registers should be programmed correctly before 
  enabling the CR_ENABLE Bit and the CR_CAPTURE Bit */
  DCMI->CR &= ~(DCMI_CR_ENABLE | DCMI_CR_CAPTURE);
   
  /* Reset the old DCMI configuration */
  temp = DCMI->CR;
  
  temp &= ~((uint32_t)DCMI_CR_CM     | DCMI_CR_ESS   | DCMI_CR_PCKPOL |
                      DCMI_CR_HSPOL  | DCMI_CR_VSPOL | DCMI_CR_FCRC_0 | 
                      DCMI_CR_FCRC_1 | DCMI_CR_EDM_0 | DCMI_CR_EDM_1); 
                  
  /* Sets the new configuration of the DCMI peripheral */
  temp |= ((uint32_t)DCMI_InitStruct->DCMI_CaptureMode |
                     DCMI_InitStruct->DCMI_SynchroMode |
                     DCMI_InitStruct->DCMI_PCKPolarity |
                     DCMI_InitStruct->DCMI_VSPolarity |
                     DCMI_InitStruct->DCMI_HSPolarity |
                     DCMI_InitStruct->DCMI_CaptureRate |
                     DCMI_InitStruct->DCMI_ExtendedDataMode);

  DCMI->CR = temp;                              
}

void DCMI_StructInit(DCMI_InitTypeDef* DCMI_InitStruct)
{
  /* Set the default configuration */
  DCMI_InitStruct->DCMI_CaptureMode = DCMI_CaptureMode_Continuous;
  DCMI_InitStruct->DCMI_SynchroMode = DCMI_SynchroMode_Hardware;
  DCMI_InitStruct->DCMI_PCKPolarity = DCMI_PCKPolarity_Falling;
  DCMI_InitStruct->DCMI_VSPolarity = DCMI_VSPolarity_Low;
  DCMI_InitStruct->DCMI_HSPolarity = DCMI_HSPolarity_Low;
  DCMI_InitStruct->DCMI_CaptureRate = DCMI_CaptureRate_All_Frame;
  DCMI_InitStruct->DCMI_ExtendedDataMode = DCMI_ExtendedDataMode_8b;
}

void DCMI_CROPConfig(DCMI_CROPInitTypeDef* DCMI_CROPInitStruct)
{  
  /* Sets the CROP window coordinates */
  DCMI->CWSTRTR = (uint32_t)((uint32_t)DCMI_CROPInitStruct->DCMI_HorizontalOffsetCount |
                  ((uint32_t)DCMI_CROPInitStruct->DCMI_VerticalStartLine << 16));

  /* Sets the CROP window size */
  DCMI->CWSIZER = (uint32_t)(DCMI_CROPInitStruct->DCMI_CaptureCount |
                  ((uint32_t)DCMI_CROPInitStruct->DCMI_VerticalLineCount << 16));
}

void DCMI_CROPCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
    
  if (NewState != DISABLE)
  {
    /* Enable the DCMI Crop feature */
    DCMI->CR |= (uint32_t)DCMI_CR_CROP;
  }
  else
  {
    /* Disable the DCMI Crop feature */
    DCMI->CR &= ~(uint32_t)DCMI_CR_CROP;
  }
}

void DCMI_SetEmbeddedSynchroCodes(DCMI_CodesInitTypeDef* DCMI_CodesInitStruct)
{
  DCMI->ESCR = (uint32_t)(DCMI_CodesInitStruct->DCMI_FrameStartCode |
                          ((uint32_t)DCMI_CodesInitStruct->DCMI_LineStartCode << 8)|
                          ((uint32_t)DCMI_CodesInitStruct->DCMI_LineEndCode << 16)|
                          ((uint32_t)DCMI_CodesInitStruct->DCMI_FrameEndCode << 24));
}

void DCMI_JPEGCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
 
  if (NewState != DISABLE)
  {
    /* Enable the DCMI JPEG format */
    DCMI->CR |= (uint32_t)DCMI_CR_JPEG;
  }
  else
  {
    /* Disable the DCMI JPEG format */
    DCMI->CR &= ~(uint32_t)DCMI_CR_JPEG;
  }
}

void DCMI_Cmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the DCMI by setting ENABLE bit */
    DCMI->CR |= (uint32_t)DCMI_CR_ENABLE;
  }
  else
  {
    /* Disable the DCMI by clearing ENABLE bit */
    DCMI->CR &= ~(uint32_t)DCMI_CR_ENABLE;
  }
}

void DCMI_CaptureCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
    
  if (NewState != DISABLE)
  {
    /* Enable the DCMI Capture */
    DCMI->CR |= (uint32_t)DCMI_CR_CAPTURE;
  }
  else
  {
    /* Disable the DCMI Capture */
    DCMI->CR &= ~(uint32_t)DCMI_CR_CAPTURE;
  }
}

uint32_t DCMI_ReadData(void)
{
  return DCMI->DR;
}

void DCMI_ITConfig(uint16_t DCMI_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_DCMI_CONFIG_IT(DCMI_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the Interrupt sources */
    DCMI->IER |= DCMI_IT;
  }
  else
  {
    /* Disable the Interrupt sources */
    DCMI->IER &= (uint16_t)(~DCMI_IT);
  }  
}

FlagStatus DCMI_GetFlagStatus(uint16_t DCMI_FLAG)
{
  FlagStatus bitstatus = RESET;
  uint32_t dcmireg, tempreg = 0;

  /* Check the parameters */
  assert_param(IS_DCMI_GET_FLAG(DCMI_FLAG));
  
  /* Get the DCMI register index */
  dcmireg = (((uint16_t)DCMI_FLAG) >> 12);
  
  if (dcmireg == 0x01) /* The FLAG is in RISR register */
  {
    tempreg= DCMI->RISR;
  }
  else if (dcmireg == 0x02) /* The FLAG is in SR register */
  {
    tempreg = DCMI->SR;
  }
  else /* The FLAG is in MISR register */
  {
    tempreg = DCMI->MISR;
  }
  
  if ((tempreg & DCMI_FLAG) != (uint16_t)RESET )
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  /* Return the DCMI_FLAG status */
  return  bitstatus;
}

void DCMI_ClearFlag(uint16_t DCMI_FLAG)
{
  /* Check the parameters */
  assert_param(IS_DCMI_CLEAR_FLAG(DCMI_FLAG));
  
  /* Clear the flag by writing in the ICR register 1 in the corresponding 
  Flag position*/
  
  DCMI->ICR = DCMI_FLAG;
}

ITStatus DCMI_GetITStatus(uint16_t DCMI_IT)
{
  ITStatus bitstatus = RESET;
  uint32_t itstatus = 0;
  
  /* Check the parameters */
  assert_param(IS_DCMI_GET_IT(DCMI_IT));
  
  itstatus = DCMI->MISR & DCMI_IT; /* Only masked interrupts are checked */
  
  if ((itstatus != (uint16_t)RESET))
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}

void DCMI_ClearITPendingBit(uint16_t DCMI_IT)
{
  /* Clear the interrupt pending Bit by writing in the ICR register 1 in the 
  corresponding pending Bit position*/
  
  DCMI->ICR = DCMI_IT;
}

