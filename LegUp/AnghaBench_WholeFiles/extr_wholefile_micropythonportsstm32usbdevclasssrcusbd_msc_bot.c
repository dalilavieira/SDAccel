#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_6__ ;
typedef  struct TYPE_28__   TYPE_5__ ;
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
struct TYPE_26__ {int bLUN; scalar_t__ dDataLength; scalar_t__ dSignature; int bCBLength; scalar_t__ bmFlags; int /*<<< orphan*/ * CB; int /*<<< orphan*/  dTag; } ;
struct TYPE_25__ {scalar_t__ dDataResidue; int bStatus; int /*<<< orphan*/  dSignature; int /*<<< orphan*/  dTag; } ;
struct TYPE_28__ {int bot_state; scalar_t__ bot_status; scalar_t__ bot_data_length; int* bot_data; TYPE_3__ cbw; TYPE_2__ csw; TYPE_1__* bdev_ops; scalar_t__ scsi_sense_head; scalar_t__ scsi_sense_tail; } ;
struct TYPE_27__ {TYPE_5__ MSC_BOT_ClassData; } ;
typedef  TYPE_4__ usbd_cdc_msc_hid_state_t ;
typedef  int uint8_t ;
typedef  scalar_t__ uint16_t ;
typedef  TYPE_5__ USBD_MSC_BOT_HandleTypeDef ;
struct TYPE_29__ {scalar_t__ pClassData; } ;
typedef  TYPE_6__ USBD_HandleTypeDef ;
struct TYPE_24__ {int /*<<< orphan*/  (* Init ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ILLEGAL_REQUEST ; 
 int /*<<< orphan*/  INVALID_CDB ; 
 scalar_t__ MIN (scalar_t__,scalar_t__) ; 
static  void MSC_BOT_Abort (TYPE_6__*) ; 
static  void MSC_BOT_CBW_Decode (TYPE_6__*) ; 
 void MSC_BOT_SendCSW (TYPE_6__*,int) ; 
static  void MSC_BOT_SendData (TYPE_6__*,int*,scalar_t__) ; 
 int /*<<< orphan*/  MSC_IN_EP ; 
 int /*<<< orphan*/  MSC_OUT_EP ; 
 scalar_t__ SCSI_ProcessCmd (TYPE_6__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SCSI_SenseCode (TYPE_6__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ USBD_BOT_CBW_LENGTH ; 
 scalar_t__ USBD_BOT_CBW_SIGNATURE ; 
 scalar_t__ USBD_BOT_CSW_LENGTH ; 
 int /*<<< orphan*/  USBD_BOT_CSW_SIGNATURE ; 
#define  USBD_BOT_DATA_IN 132 
#define  USBD_BOT_DATA_OUT 131 
#define  USBD_BOT_IDLE 130 
#define  USBD_BOT_LAST_DATA_IN 129 
 scalar_t__ USBD_BOT_NO_DATA ; 
#define  USBD_BOT_SEND_DATA 128 
 scalar_t__ USBD_BOT_STATUS_ERROR ; 
 scalar_t__ USBD_BOT_STATUS_NORMAL ; 
 scalar_t__ USBD_BOT_STATUS_RECOVERY ; 
 int USBD_CSW_CMD_FAILED ; 
 int USBD_CSW_CMD_PASSED ; 
 int /*<<< orphan*/  USBD_LL_FlushEP (TYPE_6__*,int /*<<< orphan*/ ) ; 
 scalar_t__ USBD_LL_GetRxDataSize (TYPE_6__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USBD_LL_PrepareReceive (TYPE_6__*,int /*<<< orphan*/ ,int*,scalar_t__) ; 
 int /*<<< orphan*/  USBD_LL_StallEP (TYPE_6__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USBD_LL_Transmit (TYPE_6__*,int /*<<< orphan*/ ,int*,scalar_t__) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 

void MSC_BOT_Init (USBD_HandleTypeDef  *pdev)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  hmsc->bot_state  = USBD_BOT_IDLE;
  hmsc->bot_status = USBD_BOT_STATUS_NORMAL;

  hmsc->scsi_sense_tail = 0;
  hmsc->scsi_sense_head = 0;

  hmsc->bdev_ops->Init(0);

  USBD_LL_FlushEP(pdev, MSC_OUT_EP);
  USBD_LL_FlushEP(pdev, MSC_IN_EP);

  /* Prapare EP to Receive First BOT Cmd */
  USBD_LL_PrepareReceive (pdev,
                          MSC_OUT_EP,
                          (uint8_t *)&hmsc->cbw,
                          USBD_BOT_CBW_LENGTH);
}

void MSC_BOT_Reset (USBD_HandleTypeDef  *pdev)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  hmsc->bot_state  = USBD_BOT_IDLE;
  hmsc->bot_status = USBD_BOT_STATUS_RECOVERY;

  /* Prapare EP to Receive First BOT Cmd */
  USBD_LL_PrepareReceive (pdev,
                          MSC_OUT_EP,
                          (uint8_t *)&hmsc->cbw,
                          USBD_BOT_CBW_LENGTH);
}

void MSC_BOT_DeInit (USBD_HandleTypeDef  *pdev)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;
  hmsc->bot_state  = USBD_BOT_IDLE;
}

void MSC_BOT_DataIn (USBD_HandleTypeDef  *pdev,
                     uint8_t epnum)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  switch (hmsc->bot_state)
  {
  case USBD_BOT_DATA_IN:
    if(SCSI_ProcessCmd(pdev,
                        hmsc->cbw.bLUN,
                        &hmsc->cbw.CB[0]) < 0)
    {
      MSC_BOT_SendCSW (pdev, USBD_CSW_CMD_FAILED);
    }
    break;

  case USBD_BOT_SEND_DATA:
  case USBD_BOT_LAST_DATA_IN:
    MSC_BOT_SendCSW (pdev, USBD_CSW_CMD_PASSED);

    break;

  default:
    break;
  }
}

void MSC_BOT_DataOut (USBD_HandleTypeDef  *pdev,
                      uint8_t epnum)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  switch (hmsc->bot_state)
  {
  case USBD_BOT_IDLE:
    MSC_BOT_CBW_Decode(pdev);
    break;

  case USBD_BOT_DATA_OUT:

    if(SCSI_ProcessCmd(pdev,
                        hmsc->cbw.bLUN,
                        &hmsc->cbw.CB[0]) < 0)
    {
      MSC_BOT_SendCSW (pdev, USBD_CSW_CMD_FAILED);
    }

    break;

  default:
    break;
  }
}

__attribute__((used)) static void  MSC_BOT_CBW_Decode (USBD_HandleTypeDef  *pdev)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  hmsc->csw.dTag = hmsc->cbw.dTag;
  hmsc->csw.dDataResidue = hmsc->cbw.dDataLength;

  if ((USBD_LL_GetRxDataSize (pdev ,MSC_OUT_EP) != USBD_BOT_CBW_LENGTH) ||
      (hmsc->cbw.dSignature != USBD_BOT_CBW_SIGNATURE)||
        (hmsc->cbw.bLUN > 1) ||
          (hmsc->cbw.bCBLength < 1) ||
            (hmsc->cbw.bCBLength > 16))
  {

    SCSI_SenseCode(pdev,
                   hmsc->cbw.bLUN,
                   ILLEGAL_REQUEST,
                   INVALID_CDB);

    hmsc->bot_status = USBD_BOT_STATUS_ERROR;
    MSC_BOT_Abort(pdev);

  }
  else
  {
    if(SCSI_ProcessCmd(pdev,
                       hmsc->cbw.bLUN,
                       &hmsc->cbw.CB[0]) < 0)
    {
      if(hmsc->bot_state == USBD_BOT_NO_DATA)
      {
       MSC_BOT_SendCSW (pdev,
                         USBD_CSW_CMD_FAILED);
      }
      else
      {
        MSC_BOT_Abort(pdev);
      }
    }
    /*Burst xfer handled internally*/
    else if ((hmsc->bot_state != USBD_BOT_DATA_IN) &&
             (hmsc->bot_state != USBD_BOT_DATA_OUT) &&
             (hmsc->bot_state != USBD_BOT_LAST_DATA_IN))
    {
      if (hmsc->bot_data_length > 0)
      {
        MSC_BOT_SendData(pdev,
                         hmsc->bot_data,
                         hmsc->bot_data_length);
      }
      else if (hmsc->bot_data_length == 0)
      {
        MSC_BOT_SendCSW (pdev,
                         USBD_CSW_CMD_PASSED);
      }
    }
  }
}

__attribute__((used)) static void  MSC_BOT_SendData(USBD_HandleTypeDef  *pdev,
                              uint8_t* buf,
                              uint16_t len)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  len = MIN (hmsc->cbw.dDataLength, len);
  hmsc->csw.dDataResidue -= len;
  hmsc->csw.bStatus = USBD_CSW_CMD_PASSED;
  hmsc->bot_state = USBD_BOT_SEND_DATA;

  USBD_LL_Transmit (pdev, MSC_IN_EP, buf, len);
}

void  MSC_BOT_SendCSW (USBD_HandleTypeDef  *pdev,
                              uint8_t CSW_Status)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  hmsc->csw.dSignature = USBD_BOT_CSW_SIGNATURE;
  hmsc->csw.bStatus = CSW_Status;
  hmsc->bot_state = USBD_BOT_IDLE;

  USBD_LL_Transmit (pdev,
             MSC_IN_EP,
             (uint8_t *)&hmsc->csw,
             USBD_BOT_CSW_LENGTH);

  /* Prapare EP to Receive next Cmd */
  USBD_LL_PrepareReceive (pdev,
                    MSC_OUT_EP,
                    (uint8_t *)&hmsc->cbw,
                    USBD_BOT_CBW_LENGTH);

}

__attribute__((used)) static void  MSC_BOT_Abort (USBD_HandleTypeDef  *pdev)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  if ((hmsc->cbw.bmFlags == 0) &&
      (hmsc->cbw.dDataLength != 0) &&
      (hmsc->bot_status == USBD_BOT_STATUS_NORMAL) )
  {
    USBD_LL_StallEP(pdev, MSC_OUT_EP );
  }
  USBD_LL_StallEP(pdev, MSC_IN_EP);

  if(hmsc->bot_status == USBD_BOT_STATUS_ERROR)
  {
    USBD_LL_PrepareReceive (pdev,
                      MSC_OUT_EP,
                      (uint8_t *)&hmsc->cbw,
                      USBD_BOT_CBW_LENGTH);
  }
}

void  MSC_BOT_CplClrFeature (USBD_HandleTypeDef  *pdev, uint8_t epnum)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  if(hmsc->bot_status == USBD_BOT_STATUS_ERROR )/* Bad CBW Signature */
  {
    USBD_LL_StallEP(pdev, MSC_IN_EP);
    hmsc->bot_status = USBD_BOT_STATUS_NORMAL;
  }
  else if(((epnum & 0x80) == 0x80) && ( hmsc->bot_status != USBD_BOT_STATUS_RECOVERY))
  {
    MSC_BOT_SendCSW (pdev, USBD_CSW_CMD_FAILED);
  }

}

