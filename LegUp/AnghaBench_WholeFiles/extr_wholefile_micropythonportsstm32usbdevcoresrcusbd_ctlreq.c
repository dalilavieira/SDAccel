#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_57__   TYPE_5__ ;
typedef  struct TYPE_56__   TYPE_4__ ;
typedef  struct TYPE_55__   TYPE_3__ ;
typedef  struct TYPE_54__   TYPE_2__ ;
typedef  struct TYPE_53__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  scalar_t__ uint16_t ;
typedef  int /*<<< orphan*/  USBD_StatusTypeDef ;
struct TYPE_55__ {int bRequest; scalar_t__ wIndex; scalar_t__ wLength; int wValue; int bmRequest; } ;
typedef  TYPE_3__ USBD_SetupReqTypedef ;
struct TYPE_56__ {int dev_state; int dev_address; int dev_config; int dev_remote_wakeup; TYPE_2__* pClass; int /*<<< orphan*/  dev_config_status; int /*<<< orphan*/  dev_default_config; int /*<<< orphan*/  dev_speed; TYPE_1__* pDesc; TYPE_5__* ep_out; TYPE_5__* ep_in; } ;
typedef  TYPE_4__ USBD_HandleTypeDef ;
struct TYPE_57__ {int status; } ;
typedef  TYPE_5__ USBD_EndpointTypeDef ;
struct TYPE_54__ {int /*<<< orphan*/  (* Setup ) (TYPE_4__*,TYPE_3__*) ;scalar_t__ (* GetOtherSpeedConfigDescriptor ) (TYPE_4__*,scalar_t__*) ;scalar_t__ (* GetDeviceQualifierDescriptor ) (TYPE_4__*,scalar_t__*) ;scalar_t__ (* GetFSConfigDescriptor ) (TYPE_4__*,scalar_t__*) ;scalar_t__ (* GetHSConfigDescriptor ) (TYPE_4__*,scalar_t__*) ;} ;
struct TYPE_53__ {int* (* GetDeviceDescriptor ) (TYPE_4__*,scalar_t__*) ;int* (* GetStrDescriptor ) (TYPE_4__*,int,scalar_t__*) ;} ;

/* Variables and functions */
 int LOBYTE (scalar_t__) ; 
 scalar_t__ MIN (scalar_t__,scalar_t__) ; 
 void* SWAPBYTE (int*) ; 
 int /*<<< orphan*/  USBD_ClrClassConfig (TYPE_4__*,int) ; 
static  void USBD_ClrFeature (TYPE_4__*,TYPE_3__*) ; 
 void USBD_CtlError (TYPE_4__*,TYPE_3__*) ; 
 int /*<<< orphan*/  USBD_CtlSendData (TYPE_4__*,int*,int) ; 
 int /*<<< orphan*/  USBD_CtlSendStatus (TYPE_4__*) ; 
 int /*<<< orphan*/  USBD_FAIL ; 
static  void USBD_GetConfig (TYPE_4__*,TYPE_3__*) ; 
static  void USBD_GetDescriptor (TYPE_4__*,TYPE_3__*) ; 
static  int USBD_GetLen (int*) ; 
static  void USBD_GetStatus (TYPE_4__*,TYPE_3__*) ; 
 int /*<<< orphan*/  USBD_LL_ClearStallEP (TYPE_4__*,int) ; 
 int /*<<< orphan*/  USBD_LL_IsStallEP (TYPE_4__*,int) ; 
 int /*<<< orphan*/  USBD_LL_SetUSBAddress (TYPE_4__*,int) ; 
 int /*<<< orphan*/  USBD_LL_StallEP (TYPE_4__*,int) ; 
 int USBD_MAX_NUM_CONFIGURATION ; 
 int USBD_MAX_NUM_INTERFACES ; 
 int /*<<< orphan*/  USBD_OK ; 
 int /*<<< orphan*/  USBD_SPEED_HIGH ; 
#define  USBD_STATE_ADDRESSED 141 
#define  USBD_STATE_CONFIGURED 140 
 int USBD_STATE_DEFAULT ; 
static  void USBD_SetAddress (TYPE_4__*,TYPE_3__*) ; 
 int /*<<< orphan*/  USBD_SetClassConfig (TYPE_4__*,int) ; 
static  void USBD_SetConfig (TYPE_4__*,TYPE_3__*) ; 
static  void USBD_SetFeature (TYPE_4__*,TYPE_3__*) ; 
 int /*<<< orphan*/  USB_CONFIG_REMOTE_WAKEUP ; 
#define  USB_DESC_TYPE_CONFIGURATION 139 
#define  USB_DESC_TYPE_DEVICE 138 
#define  USB_DESC_TYPE_DEVICE_QUALIFIER 137 
#define  USB_DESC_TYPE_OTHER_SPEED_CONFIGURATION 136 
#define  USB_DESC_TYPE_STRING 135 
 int USB_FEATURE_EP_HALT ; 
 scalar_t__ USB_FEATURE_REMOTE_WAKEUP ; 
#define  USB_REQ_CLEAR_FEATURE 134 
#define  USB_REQ_GET_CONFIGURATION 133 
#define  USB_REQ_GET_DESCRIPTOR 132 
#define  USB_REQ_GET_STATUS 131 
#define  USB_REQ_SET_ADDRESS 130 
#define  USB_REQ_SET_CONFIGURATION 129 
#define  USB_REQ_SET_FEATURE 128 
 int /*<<< orphan*/  stub1 (TYPE_4__*,TYPE_3__*) ; 
 int /*<<< orphan*/  stub10 (TYPE_4__*,TYPE_3__*) ; 
 int /*<<< orphan*/  stub11 (TYPE_4__*,TYPE_3__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_4__*,TYPE_3__*) ; 
 int /*<<< orphan*/  stub3 (TYPE_4__*,TYPE_3__*) ; 
 int* stub4 (TYPE_4__*,scalar_t__*) ; 
 scalar_t__ stub5 (TYPE_4__*,scalar_t__*) ; 
 scalar_t__ stub6 (TYPE_4__*,scalar_t__*) ; 
 int* stub7 (TYPE_4__*,int,scalar_t__*) ; 
 scalar_t__ stub8 (TYPE_4__*,scalar_t__*) ; 
 scalar_t__ stub9 (TYPE_4__*,scalar_t__*) ; 

USBD_StatusTypeDef  USBD_StdDevReq (USBD_HandleTypeDef *pdev , USBD_SetupReqTypedef  *req)
{
  USBD_StatusTypeDef ret = USBD_OK;

  switch (req->bRequest)
  {
  case USB_REQ_GET_DESCRIPTOR:

    USBD_GetDescriptor (pdev, req) ;
    break;

  case USB_REQ_SET_ADDRESS:
    USBD_SetAddress(pdev, req);
    break;

  case USB_REQ_SET_CONFIGURATION:
    USBD_SetConfig (pdev , req);
    break;

  case USB_REQ_GET_CONFIGURATION:
    USBD_GetConfig (pdev , req);
    break;

  case USB_REQ_GET_STATUS:
    USBD_GetStatus (pdev , req);
    break;


  case USB_REQ_SET_FEATURE:
    USBD_SetFeature (pdev , req);
    break;

  case USB_REQ_CLEAR_FEATURE:
    USBD_ClrFeature (pdev , req);
    break;

  default:
    USBD_CtlError(pdev , req);
    break;
  }

  return ret;
}

USBD_StatusTypeDef  USBD_StdItfReq (USBD_HandleTypeDef *pdev , USBD_SetupReqTypedef  *req)
{
  USBD_StatusTypeDef ret = USBD_OK;

  switch (pdev->dev_state)
  {
  case USBD_STATE_CONFIGURED:

    if (LOBYTE(req->wIndex) <= USBD_MAX_NUM_INTERFACES)
    {
      pdev->pClass->Setup (pdev, req);

      if((req->wLength == 0)&& (ret == USBD_OK))
      {
         USBD_CtlSendStatus(pdev);
      }
    }
    else
    {
       USBD_CtlError(pdev , req);
    }
    break;

  default:
     USBD_CtlError(pdev , req);
    break;
  }
  return USBD_OK;
}

USBD_StatusTypeDef  USBD_StdEPReq (USBD_HandleTypeDef *pdev , USBD_SetupReqTypedef  *req)
{

  uint8_t   ep_addr;
  USBD_StatusTypeDef ret = USBD_OK;
  USBD_EndpointTypeDef   *pep;
  ep_addr  = LOBYTE(req->wIndex);

  switch (req->bRequest)
  {

  case USB_REQ_SET_FEATURE :

    switch (pdev->dev_state)
    {
    case USBD_STATE_ADDRESSED:
      if ((ep_addr != 0x00) && (ep_addr != 0x80))
      {
        USBD_LL_StallEP(pdev , ep_addr);
      }
      break;

    case USBD_STATE_CONFIGURED:
      if (req->wValue == USB_FEATURE_EP_HALT)
      {
        if ((ep_addr != 0x00) && (ep_addr != 0x80))
        {
          USBD_LL_StallEP(pdev , ep_addr);

        }
      }
      pdev->pClass->Setup (pdev, req);
      USBD_CtlSendStatus(pdev);

      break;

    default:
      USBD_CtlError(pdev , req);
      break;
    }
    break;

  case USB_REQ_CLEAR_FEATURE :

    switch (pdev->dev_state)
    {
    case USBD_STATE_ADDRESSED:
      if ((ep_addr != 0x00) && (ep_addr != 0x80))
      {
        USBD_LL_StallEP(pdev , ep_addr);
      }
      break;

    case USBD_STATE_CONFIGURED:
      if (req->wValue == USB_FEATURE_EP_HALT)
      {
        if ((ep_addr & 0x7F) != 0x00)
        {
          USBD_LL_ClearStallEP(pdev , ep_addr);
          pdev->pClass->Setup (pdev, req);
        }
        USBD_CtlSendStatus(pdev);
      }
      break;

    default:
      USBD_CtlError(pdev , req);
      break;
    }
    break;

  case USB_REQ_GET_STATUS:
    switch (pdev->dev_state)
    {
    case USBD_STATE_ADDRESSED:
      if ((ep_addr & 0x7F) != 0x00)
      {
        USBD_LL_StallEP(pdev , ep_addr);
      }
      break;

    case USBD_STATE_CONFIGURED:
      pep = ((ep_addr & 0x80) == 0x80) ? &pdev->ep_in[ep_addr & 0x7F]:\
                                         &pdev->ep_out[ep_addr & 0x7F];
      if(USBD_LL_IsStallEP(pdev, ep_addr))
      {
        pep->status = 0x0001;
      }
      else
      {
        pep->status = 0x0000;
      }

      USBD_CtlSendData (pdev,
                        (uint8_t *)&pep->status,
                        2);
      break;

    default:
      USBD_CtlError(pdev , req);
      break;
    }
    break;

  default:
    break;
  }
  return ret;
}

__attribute__((used)) static void USBD_GetDescriptor(USBD_HandleTypeDef *pdev ,
                               USBD_SetupReqTypedef *req)
{
  uint16_t len;
  uint8_t *pbuf;


  switch (req->wValue >> 8)
  {
  case USB_DESC_TYPE_DEVICE:
    pbuf = pdev->pDesc->GetDeviceDescriptor(pdev, &len);
    break;

  case USB_DESC_TYPE_CONFIGURATION:
    if(pdev->dev_speed == USBD_SPEED_HIGH )
    {
      pbuf   = (uint8_t *)pdev->pClass->GetHSConfigDescriptor(pdev, &len);
      pbuf[1] = USB_DESC_TYPE_CONFIGURATION;
    }
    else
    {
      pbuf   = (uint8_t *)pdev->pClass->GetFSConfigDescriptor(pdev, &len);
      pbuf[1] = USB_DESC_TYPE_CONFIGURATION;
    }
    break;

  case USB_DESC_TYPE_STRING:
    pbuf = pdev->pDesc->GetStrDescriptor(pdev, req->wValue & 0xff, &len);
    if (pbuf == NULL) {
      USBD_CtlError(pdev, req);
      return;
    }
    break;

  case USB_DESC_TYPE_DEVICE_QUALIFIER:

    if(pdev->dev_speed == USBD_SPEED_HIGH  )
    {
      pbuf   = (uint8_t *)pdev->pClass->GetDeviceQualifierDescriptor(pdev, &len);
      break;
    }
    else
    {
      USBD_CtlError(pdev , req);
      return;
    }

  case USB_DESC_TYPE_OTHER_SPEED_CONFIGURATION:
    if(pdev->dev_speed == USBD_SPEED_HIGH  )
    {
      pbuf   = (uint8_t *)pdev->pClass->GetOtherSpeedConfigDescriptor(pdev, &len);
      pbuf[1] = USB_DESC_TYPE_OTHER_SPEED_CONFIGURATION;
      break;
    }
    else
    {
      USBD_CtlError(pdev , req);
      return;
    }

  default:
     USBD_CtlError(pdev , req);
    return;
  }

  if((len != 0)&& (req->wLength != 0))
  {

    len = MIN(len , req->wLength);

    USBD_CtlSendData (pdev,
                      pbuf,
                      len);
  }

}

__attribute__((used)) static void USBD_SetAddress(USBD_HandleTypeDef *pdev ,
                            USBD_SetupReqTypedef *req)
{
  uint8_t  dev_addr;

  if ((req->wIndex == 0) && (req->wLength == 0))
  {
    dev_addr = (uint8_t)(req->wValue) & 0x7F;

    if (pdev->dev_state == USBD_STATE_CONFIGURED)
    {
      USBD_CtlError(pdev , req);
    }
    else
    {
      pdev->dev_address = dev_addr;
      USBD_LL_SetUSBAddress(pdev, dev_addr);
      USBD_CtlSendStatus(pdev);

      if (dev_addr != 0)
      {
        pdev->dev_state  = USBD_STATE_ADDRESSED;
      }
      else
      {
        pdev->dev_state  = USBD_STATE_DEFAULT;
      }
    }
  }
  else
  {
     USBD_CtlError(pdev , req);
  }
}

__attribute__((used)) static void USBD_SetConfig(USBD_HandleTypeDef *pdev ,
                           USBD_SetupReqTypedef *req)
{

  uint8_t cfgidx;

  cfgidx = (uint8_t)(req->wValue);

  if (cfgidx > USBD_MAX_NUM_CONFIGURATION )
  {
     USBD_CtlError(pdev , req);
  }
  else
  {
    switch (pdev->dev_state)
    {
    case USBD_STATE_ADDRESSED:
      if (cfgidx)
      {
        pdev->dev_config = cfgidx;
        pdev->dev_state = USBD_STATE_CONFIGURED;
        if(USBD_SetClassConfig(pdev , cfgidx) == USBD_FAIL)
        {
          USBD_CtlError(pdev , req);
          return;
        }
        USBD_CtlSendStatus(pdev);
      }
      else
      {
         USBD_CtlSendStatus(pdev);
      }
      break;

    case USBD_STATE_CONFIGURED:
      if (cfgidx == 0)
      {
        pdev->dev_state = USBD_STATE_ADDRESSED;
        pdev->dev_config = cfgidx;
        USBD_ClrClassConfig(pdev , cfgidx);
        USBD_CtlSendStatus(pdev);

      }
      else  if (cfgidx != pdev->dev_config)
      {
        /* Clear old configuration */
        USBD_ClrClassConfig(pdev , pdev->dev_config);

        /* set new configuration */
        pdev->dev_config = cfgidx;
        if(USBD_SetClassConfig(pdev , cfgidx) == USBD_FAIL)
        {
          USBD_CtlError(pdev , req);
          return;
        }
        USBD_CtlSendStatus(pdev);
      }
      else
      {
        USBD_CtlSendStatus(pdev);
      }
      break;

    default:
       USBD_CtlError(pdev , req);
      break;
    }
  }
}

__attribute__((used)) static void USBD_GetConfig(USBD_HandleTypeDef *pdev ,
                           USBD_SetupReqTypedef *req)
{

  if (req->wLength != 1)
  {
     USBD_CtlError(pdev , req);
  }
  else
  {
    switch (pdev->dev_state )
    {
    case USBD_STATE_ADDRESSED:
      pdev->dev_default_config = 0;
      USBD_CtlSendData (pdev,
                        (uint8_t *)&pdev->dev_default_config,
                        1);
      break;

    case USBD_STATE_CONFIGURED:

      USBD_CtlSendData (pdev,
                        (uint8_t *)&pdev->dev_config,
                        1);
      break;

    default:
       USBD_CtlError(pdev , req);
      break;
    }
  }
}

__attribute__((used)) static void USBD_GetStatus(USBD_HandleTypeDef *pdev ,
                           USBD_SetupReqTypedef *req)
{


  switch (pdev->dev_state)
  {
  case USBD_STATE_ADDRESSED:
  case USBD_STATE_CONFIGURED:

#if ( USBD_SELF_POWERED == 1)
    pdev->dev_config_status = USB_CONFIG_SELF_POWERED;
#else
    pdev->dev_config_status = 0;
#endif

    if (pdev->dev_remote_wakeup)
    {
       pdev->dev_config_status |= USB_CONFIG_REMOTE_WAKEUP;
    }

    USBD_CtlSendData (pdev,
                      (uint8_t *)& pdev->dev_config_status,
                      2);
    break;

  default :
    USBD_CtlError(pdev , req);
    break;
  }
}

__attribute__((used)) static void USBD_SetFeature(USBD_HandleTypeDef *pdev ,
                            USBD_SetupReqTypedef *req)
{

  if (req->wValue == USB_FEATURE_REMOTE_WAKEUP)
  {
    pdev->dev_remote_wakeup = 1;
    pdev->pClass->Setup (pdev, req);
    USBD_CtlSendStatus(pdev);
  }

}

__attribute__((used)) static void USBD_ClrFeature(USBD_HandleTypeDef *pdev ,
                            USBD_SetupReqTypedef *req)
{
  switch (pdev->dev_state)
  {
  case USBD_STATE_ADDRESSED:
  case USBD_STATE_CONFIGURED:
    if (req->wValue == USB_FEATURE_REMOTE_WAKEUP)
    {
      pdev->dev_remote_wakeup = 0;
      pdev->pClass->Setup (pdev, req);
      USBD_CtlSendStatus(pdev);
    }
    break;

  default :
     USBD_CtlError(pdev , req);
    break;
  }
}

void USBD_ParseSetupRequest(USBD_SetupReqTypedef *req, uint8_t *pdata)
{
  req->bmRequest     = *(uint8_t *)  (pdata);
  req->bRequest      = *(uint8_t *)  (pdata +  1);
  req->wValue        = SWAPBYTE      (pdata +  2);
  req->wIndex        = SWAPBYTE      (pdata +  4);
  req->wLength       = SWAPBYTE      (pdata +  6);

}

void USBD_CtlError( USBD_HandleTypeDef *pdev ,
                            USBD_SetupReqTypedef *req)
{
  USBD_LL_StallEP(pdev , 0x80);
  USBD_LL_StallEP(pdev , 0);
}

void USBD_GetString(uint8_t *desc, uint8_t *unicode, uint16_t *len)
{
  uint8_t idx = 0;

  if (desc != NULL)
  {
    *len =  USBD_GetLen(desc) * 2 + 2;
    unicode[idx++] = *len;
    unicode[idx++] =  USB_DESC_TYPE_STRING;

    while (*desc != '\0')
    {
      unicode[idx++] = *desc++;
      unicode[idx++] =  0x00;
    }
  }
}

__attribute__((used)) static uint8_t USBD_GetLen(uint8_t *buf)
{
    uint8_t  len = 0;

    while (*buf != '\0')
    {
        len++;
        buf++;
    }

    return len;
}

