#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ USBH_StatusTypeDef ;
struct TYPE_10__ {int is_connected; } ;
struct TYPE_11__ {scalar_t__ gState; TYPE_1__ device; } ;
typedef  TYPE_2__ USBH_HandleTypeDef ;

/* Variables and functions */
 scalar_t__ HOST_CLASS ; 
 scalar_t__ USBH_BUSY ; 
 scalar_t__ USBH_FAIL ; 
 scalar_t__ USBH_OK ; 
 int /*<<< orphan*/  USBH_Process (TYPE_2__*) ; 

__attribute__((used)) static USBH_StatusTypeDef USBH_TEMPLATE_InterfaceInit (USBH_HandleTypeDef *phost)
{	

  return USBH_OK;
}

USBH_StatusTypeDef USBH_TEMPLATE_InterfaceDeInit (USBH_HandleTypeDef *phost)
{

  return USBH_OK;
}

__attribute__((used)) static USBH_StatusTypeDef USBH_TEMPLATE_ClassRequest (USBH_HandleTypeDef *phost)
{   

  return USBH_OK; 
}

__attribute__((used)) static USBH_StatusTypeDef USBH_TEMPLATE_Process (USBH_HandleTypeDef *phost)
{
 
  return USBH_OK;
}

USBH_StatusTypeDef USBH_TEMPLATE_Init (USBH_HandleTypeDef *phost)
{
  USBH_StatusTypeDef Status = USBH_BUSY;
#if (USBH_USE_OS == 1)
  osEvent event;
  
  event = osMessageGet( phost->class_ready_event, osWaitForever );
  
  if( event.status == osEventMessage )      
  {
    if(event.value.v == USBH_CLASS_EVENT)
    {
#else 
      
  while ((Status == USBH_BUSY) || (Status == USBH_FAIL))
  {
    /* Host background process */
    USBH_Process(phost);
    if(phost->gState == HOST_CLASS)
    {
#endif        
      Status = USBH_OK;
    }
  }
  return Status;   
}

USBH_StatusTypeDef USBH_TEMPLATE_IOProcess (USBH_HandleTypeDef *phost)
{
  if (phost->device.is_connected == 1)
  {
    if(phost->gState == HOST_CLASS)
    {
      USBH_TEMPLATE_Process(phost);
    }
  }
  
  return USBH_OK;
}

