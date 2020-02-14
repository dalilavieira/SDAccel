#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_56__   TYPE_3__ ;
typedef  struct TYPE_55__   TYPE_2__ ;
typedef  struct TYPE_54__   TYPE_1__ ;
typedef  struct TYPE_53__   TYPE_17__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  int /*<<< orphan*/  USBD_StatusTypeDef ;
typedef  int /*<<< orphan*/  USBD_SpeedTypeDef ;
struct TYPE_53__ {int wLength; int bmRequest; } ;
struct TYPE_54__ {scalar_t__ dev_state; scalar_t__ dev_config; scalar_t__ ep0_state; int ep0_data_len; int dev_test_mode; scalar_t__ dev_old_state; TYPE_3__ const* pClass; int /*<<< orphan*/  dev_speed; scalar_t__ pClassData; TYPE_2__* ep_in; TYPE_2__* ep_out; TYPE_17__ request; scalar_t__ id; int /*<<< orphan*/ * pDesc; } ;
typedef  TYPE_1__ USBD_HandleTypeDef ;
struct TYPE_55__ {scalar_t__ rem_length; scalar_t__ maxpacket; int total_length; } ;
typedef  TYPE_2__ USBD_EndpointTypeDef ;
typedef  int /*<<< orphan*/  USBD_DescriptorsTypeDef ;
struct TYPE_56__ {scalar_t__ (* Init ) (TYPE_1__*,scalar_t__) ;int /*<<< orphan*/  (* DeInit ) (TYPE_1__*,scalar_t__) ;int /*<<< orphan*/  (* SOF ) (TYPE_1__*) ;int /*<<< orphan*/  (* DataIn ) (TYPE_1__*,scalar_t__) ;int /*<<< orphan*/  (* EP0_TxSent ) (TYPE_1__*) ;int /*<<< orphan*/  (* DataOut ) (TYPE_1__*,scalar_t__) ;int /*<<< orphan*/  (* EP0_RxReady ) (TYPE_1__*) ;} ;
typedef  TYPE_3__ USBD_ClassTypeDef ;

/* Variables and functions */
 int /*<<< orphan*/  MIN (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  USBD_CtlContinueRx (TYPE_1__*,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USBD_CtlContinueSendData (TYPE_1__*,scalar_t__*,scalar_t__) ; 
 int /*<<< orphan*/  USBD_CtlReceiveStatus (TYPE_1__*) ; 
 int /*<<< orphan*/  USBD_CtlSendStatus (TYPE_1__*) ; 
 scalar_t__ USBD_EP0_DATA_IN ; 
 scalar_t__ USBD_EP0_DATA_OUT ; 
 scalar_t__ USBD_EP0_SETUP ; 
 int /*<<< orphan*/  USBD_EP_TYPE_CTRL ; 
 int /*<<< orphan*/  USBD_FAIL ; 
 int /*<<< orphan*/  USBD_LL_DeInit (TYPE_1__*) ; 
 int /*<<< orphan*/  USBD_LL_Init (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USBD_LL_OpenEP (TYPE_1__*,int,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  USBD_LL_StallEP (TYPE_1__*,int) ; 
 int /*<<< orphan*/  USBD_LL_Start (TYPE_1__*) ; 
 int /*<<< orphan*/  USBD_LL_Stop (TYPE_1__*) ; 
 int /*<<< orphan*/  USBD_OK ; 
 int /*<<< orphan*/  USBD_ParseSetupRequest (TYPE_17__*,scalar_t__*) ; 
 scalar_t__ USBD_STATE_CONFIGURED ; 
 void* USBD_STATE_DEFAULT ; 
 scalar_t__ USBD_STATE_SUSPENDED ; 
 int /*<<< orphan*/  USBD_StdDevReq (TYPE_1__*,TYPE_17__*) ; 
 int /*<<< orphan*/  USBD_StdEPReq (TYPE_1__*,TYPE_17__*) ; 
 int /*<<< orphan*/  USBD_StdItfReq (TYPE_1__*,TYPE_17__*) ; 
 void* USB_MAX_EP0_SIZE ; 
#define  USB_REQ_RECIPIENT_DEVICE 130 
#define  USB_REQ_RECIPIENT_ENDPOINT 129 
#define  USB_REQ_RECIPIENT_INTERFACE 128 
 int /*<<< orphan*/  stub1 (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  stub10 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub11 (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,scalar_t__) ; 
 scalar_t__ stub3 (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  stub4 (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  stub5 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub6 (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  stub7 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub8 (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  stub9 (TYPE_1__*,scalar_t__) ; 

USBD_StatusTypeDef USBD_Init(USBD_HandleTypeDef *pdev, USBD_DescriptorsTypeDef *pdesc, uint8_t id)
{
  /* Check whether the USB Host handle is valid */
  if(pdev == NULL)
  {
    return USBD_FAIL;
  }

  /* Unlink previous class*/
  if(pdev->pClass != NULL)
  {
    pdev->pClass = NULL;
  }

  /* Assign USBD Descriptors */
  if(pdesc != NULL)
  {
    pdev->pDesc = pdesc;
  }

  /* Set Device initial State */
  pdev->dev_state  = USBD_STATE_DEFAULT;
  pdev->id = id;
  /* Initialize low level driver */
  USBD_LL_Init(pdev, 0);

  return USBD_OK;
}

USBD_StatusTypeDef USBD_DeInit(USBD_HandleTypeDef *pdev)
{
  /* Set Default State */
  pdev->dev_state  = USBD_STATE_DEFAULT;

  /* Free Class Resources */
  pdev->pClass->DeInit(pdev, pdev->dev_config);

    /* Stop the low level driver  */
  USBD_LL_Stop(pdev);

  /* Initialize low level driver */
  USBD_LL_DeInit(pdev);

  return USBD_OK;
}

USBD_StatusTypeDef  USBD_RegisterClass(USBD_HandleTypeDef *pdev, const USBD_ClassTypeDef *pclass)
{
  USBD_StatusTypeDef   status = USBD_OK;
  if(pclass != 0)
  {
    /* link the class tgo the USB Device handle */
    pdev->pClass = pclass;
    status = USBD_OK;
  }
  else
  {
    status = USBD_FAIL;
  }

  return status;
}

USBD_StatusTypeDef  USBD_Start  (USBD_HandleTypeDef *pdev)
{

  /* Start the low level driver  */
  USBD_LL_Start(pdev);

  return USBD_OK;
}

USBD_StatusTypeDef  USBD_Stop   (USBD_HandleTypeDef *pdev)
{
  /* Free Class Resources */
  pdev->pClass->DeInit(pdev, pdev->dev_config);

  /* Stop the low level driver  */
  USBD_LL_Stop(pdev);

  return USBD_OK;
}

USBD_StatusTypeDef  USBD_RunTestMode (USBD_HandleTypeDef  *pdev)
{
  return USBD_OK;
}

USBD_StatusTypeDef USBD_SetClassConfig(USBD_HandleTypeDef  *pdev, uint8_t cfgidx)
{
  USBD_StatusTypeDef   ret = USBD_FAIL;

  if(pdev->pClass != NULL)
  {
    /* Set configuration  and Start the Class*/
    if(pdev->pClass->Init(pdev, cfgidx) == 0)
    {
      ret = USBD_OK;
    }
  }
  return ret;
}

USBD_StatusTypeDef USBD_ClrClassConfig(USBD_HandleTypeDef  *pdev, uint8_t cfgidx)
{
  /* Clear configuration  and Deinitialize the Class process*/
  pdev->pClass->DeInit(pdev, cfgidx);
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_SetupStage(USBD_HandleTypeDef *pdev, uint8_t *psetup)
{

  USBD_ParseSetupRequest(&pdev->request, psetup);

  pdev->ep0_state = USBD_EP0_SETUP;
  pdev->ep0_data_len = pdev->request.wLength;

  switch (pdev->request.bmRequest & 0x1F)
  {
  case USB_REQ_RECIPIENT_DEVICE:
    USBD_StdDevReq (pdev, &pdev->request);
    break;

  case USB_REQ_RECIPIENT_INTERFACE:
    USBD_StdItfReq(pdev, &pdev->request);
    break;

  case USB_REQ_RECIPIENT_ENDPOINT:
    USBD_StdEPReq(pdev, &pdev->request);
    break;

  default:
    USBD_LL_StallEP(pdev , pdev->request.bmRequest & 0x80);
    break;
  }
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_DataOutStage(USBD_HandleTypeDef *pdev , uint8_t epnum, uint8_t *pdata)
{
  USBD_EndpointTypeDef    *pep;

  if(epnum == 0)
  {
    pep = &pdev->ep_out[0];

    if ( pdev->ep0_state == USBD_EP0_DATA_OUT)
    {
      if(pep->rem_length > pep->maxpacket)
      {
        pep->rem_length -=  pep->maxpacket;

        USBD_CtlContinueRx (pdev,
                            pdata,
                            MIN(pep->rem_length ,pep->maxpacket));
      }
      else
      {
        if((pdev->pClass->EP0_RxReady != NULL)&&
           (pdev->dev_state == USBD_STATE_CONFIGURED))
        {
          pdev->pClass->EP0_RxReady(pdev);
        }
        USBD_CtlSendStatus(pdev);
      }
    }
  }
  else if((pdev->pClass->DataOut != NULL)&&
          (pdev->dev_state == USBD_STATE_CONFIGURED))
  {
    pdev->pClass->DataOut(pdev, epnum);
  }
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_DataInStage(USBD_HandleTypeDef *pdev ,uint8_t epnum, uint8_t *pdata)
{
  USBD_EndpointTypeDef    *pep;

  if(epnum == 0)
  {
    pep = &pdev->ep_in[0];

    if ( pdev->ep0_state == USBD_EP0_DATA_IN)
    {
      if(pep->rem_length > pep->maxpacket)
      {
        pep->rem_length -=  pep->maxpacket;

        USBD_CtlContinueSendData (pdev,
                                  pdata,
                                  pep->rem_length);
      }
      else
      { /* last packet is MPS multiple, so send ZLP packet */
        if((pep->total_length % pep->maxpacket == 0) &&
           (pep->total_length >= pep->maxpacket) &&
             (pep->total_length < pdev->ep0_data_len ))
        {

          USBD_CtlContinueSendData(pdev , NULL, 0);
          pdev->ep0_data_len = 0;
        }
        else
        {
          if((pdev->pClass->EP0_TxSent != NULL)&&
             (pdev->dev_state == USBD_STATE_CONFIGURED))
          {
            pdev->pClass->EP0_TxSent(pdev);
          }
          USBD_CtlReceiveStatus(pdev);
        }
      }
    }
    if (pdev->dev_test_mode == 1)
    {
      USBD_RunTestMode(pdev);
      pdev->dev_test_mode = 0;
    }
  }
  else if((pdev->pClass->DataIn != NULL)&&
          (pdev->dev_state == USBD_STATE_CONFIGURED))
  {
    pdev->pClass->DataIn(pdev, epnum);
  }
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_Reset(USBD_HandleTypeDef  *pdev)
{
  /* Open EP0 OUT */
  USBD_LL_OpenEP(pdev,
              0x00,
              USBD_EP_TYPE_CTRL,
              USB_MAX_EP0_SIZE);

  pdev->ep_out[0].maxpacket = USB_MAX_EP0_SIZE;

  /* Open EP0 IN */
  USBD_LL_OpenEP(pdev,
              0x80,
              USBD_EP_TYPE_CTRL,
              USB_MAX_EP0_SIZE);

  pdev->ep_in[0].maxpacket = USB_MAX_EP0_SIZE;
  /* Upon Reset call usr call back */
  pdev->dev_state = USBD_STATE_DEFAULT;

  if (pdev->pClassData)
    pdev->pClass->DeInit(pdev, pdev->dev_config);


  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_SetSpeed(USBD_HandleTypeDef  *pdev, USBD_SpeedTypeDef speed)
{
  pdev->dev_speed = speed;
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_Suspend(USBD_HandleTypeDef  *pdev)
{
  pdev->dev_old_state =  pdev->dev_state;
  pdev->dev_state  = USBD_STATE_SUSPENDED;
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_Resume(USBD_HandleTypeDef  *pdev)
{
  pdev->dev_state = pdev->dev_old_state;
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_SOF(USBD_HandleTypeDef  *pdev)
{
  if(pdev->dev_state == USBD_STATE_CONFIGURED)
  {
    if(pdev->pClass->SOF != NULL)
    {
      pdev->pClass->SOF(pdev);
    }
  }
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_IsoINIncomplete(USBD_HandleTypeDef  *pdev, uint8_t epnum)
{
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_IsoOUTIncomplete(USBD_HandleTypeDef  *pdev, uint8_t epnum)
{
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_DevConnected(USBD_HandleTypeDef  *pdev)
{
  return USBD_OK;
}

USBD_StatusTypeDef USBD_LL_DevDisconnected(USBD_HandleTypeDef  *pdev)
{
  /* Free Class Resources */
  pdev->dev_state = USBD_STATE_DEFAULT;
  pdev->pClass->DeInit(pdev, pdev->dev_config);

  return USBD_OK;
}

