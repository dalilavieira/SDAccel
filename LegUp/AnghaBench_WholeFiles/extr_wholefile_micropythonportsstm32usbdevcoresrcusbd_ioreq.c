#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  void* uint16_t ;
typedef  int /*<<< orphan*/  USBD_StatusTypeDef ;
struct TYPE_16__ {int /*<<< orphan*/  ep0_state; TYPE_2__* ep_out; TYPE_1__* ep_in; } ;
typedef  TYPE_3__ USBD_HandleTypeDef ;
struct TYPE_15__ {void* rem_length; void* total_length; } ;
struct TYPE_14__ {void* rem_length; void* total_length; } ;

/* Variables and functions */
 int /*<<< orphan*/  USBD_EP0_DATA_IN ; 
 int /*<<< orphan*/  USBD_EP0_DATA_OUT ; 
 int /*<<< orphan*/  USBD_EP0_STATUS_IN ; 
 int /*<<< orphan*/  USBD_EP0_STATUS_OUT ; 
 void* USBD_LL_GetRxDataSize (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USBD_LL_PrepareReceive (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  USBD_LL_Transmit (TYPE_3__*,int,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  USBD_OK ; 

USBD_StatusTypeDef  USBD_CtlSendData (USBD_HandleTypeDef  *pdev,
                               uint8_t *pbuf,
                               uint16_t len)
{
  /* Set EP0 State */
  pdev->ep0_state          = USBD_EP0_DATA_IN;
  pdev->ep_in[0].total_length = len;
  pdev->ep_in[0].rem_length   = len;
 /* Start the transfer */
  USBD_LL_Transmit (pdev, 0x00, pbuf, len);

  return USBD_OK;
}

USBD_StatusTypeDef  USBD_CtlContinueSendData (USBD_HandleTypeDef  *pdev,
                                       uint8_t *pbuf,
                                       uint16_t len)
{
 /* Start the next transfer */
  USBD_LL_Transmit (pdev, 0x00, pbuf, len);

  return USBD_OK;
}

USBD_StatusTypeDef  USBD_CtlPrepareRx (USBD_HandleTypeDef  *pdev,
                                  uint8_t *pbuf,
                                  uint16_t len)
{
  /* Set EP0 State */
  pdev->ep0_state = USBD_EP0_DATA_OUT;
  pdev->ep_out[0].total_length = len;
  pdev->ep_out[0].rem_length   = len;
  /* Start the transfer */
  USBD_LL_PrepareReceive (pdev,
                          0,
                          pbuf,
                         len);

  return USBD_OK;
}

USBD_StatusTypeDef  USBD_CtlContinueRx (USBD_HandleTypeDef  *pdev,
                                          uint8_t *pbuf,
                                          uint16_t len)
{

  USBD_LL_PrepareReceive (pdev,
                          0,
                          pbuf,
                          len);
  return USBD_OK;
}

USBD_StatusTypeDef  USBD_CtlSendStatus (USBD_HandleTypeDef  *pdev)
{

  /* Set EP0 State */
  pdev->ep0_state = USBD_EP0_STATUS_IN;

 /* Start the transfer */
  USBD_LL_Transmit (pdev, 0x00, NULL, 0);

  return USBD_OK;
}

USBD_StatusTypeDef  USBD_CtlReceiveStatus (USBD_HandleTypeDef  *pdev)
{
  /* Set EP0 State */
  pdev->ep0_state = USBD_EP0_STATUS_OUT;

 /* Start the transfer */
  USBD_LL_PrepareReceive ( pdev,
                    0,
                    NULL,
                    0);

  return USBD_OK;
}

uint16_t  USBD_GetRxCount (USBD_HandleTypeDef  *pdev , uint8_t ep_addr)
{
  return USBD_LL_GetRxDataSize(pdev, ep_addr);
}

