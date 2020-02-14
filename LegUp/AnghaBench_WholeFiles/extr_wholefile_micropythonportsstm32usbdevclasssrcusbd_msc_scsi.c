#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_39__   TYPE_9__ ;
typedef  struct TYPE_38__   TYPE_8__ ;
typedef  struct TYPE_37__   TYPE_7__ ;
typedef  struct TYPE_36__   TYPE_6__ ;
typedef  struct TYPE_35__   TYPE_5__ ;
typedef  struct TYPE_34__   TYPE_4__ ;
typedef  struct TYPE_33__   TYPE_3__ ;
typedef  struct TYPE_32__   TYPE_2__ ;
typedef  struct TYPE_31__   TYPE_1__ ;

/* Type definitions */
struct TYPE_36__ {int dDataResidue; } ;
struct TYPE_34__ {scalar_t__ dDataLength; int bLUN; int bmFlags; } ;
struct TYPE_38__ {scalar_t__ bot_state; int bot_data_length; int* bot_data; int scsi_blk_nbr; int scsi_blk_size; size_t scsi_sense_head; size_t scsi_sense_tail; int scsi_blk_addr_in_blks; int scsi_blk_len; TYPE_6__ csw; TYPE_5__* bdev_ops; TYPE_4__ cbw; TYPE_3__* scsi_sense; } ;
struct TYPE_37__ {TYPE_8__ MSC_BOT_ClassData; } ;
typedef  TYPE_7__ usbd_cdc_msc_hid_state_t ;
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int int8_t ;
typedef  TYPE_8__ USBD_MSC_BOT_HandleTypeDef ;
struct TYPE_39__ {scalar_t__ pClassData; } ;
typedef  TYPE_9__ USBD_HandleTypeDef ;
struct TYPE_35__ {scalar_t__ (* IsReady ) (int) ;scalar_t__ (* GetCapacity ) (int,int*,int*) ;scalar_t__ (* IsWriteProtected ) (int) ;scalar_t__ (* Read ) (int,int*,int,int) ;scalar_t__ (* Write ) (int,int*,int,int) ;int /*<<< orphan*/  (* PreventAllowMediumRemoval ) (int,int) ;int /*<<< orphan*/  (* StartStopUnit ) (int,int) ;int /*<<< orphan*/ * pInquiry; } ;
struct TYPE_31__ {int ASCQ; int ASC; } ;
struct TYPE_32__ {int ASC; TYPE_1__ b; } ;
struct TYPE_33__ {int Skey; TYPE_2__ w; } ;

/* Variables and functions */
 int ADDRESS_OUT_OF_RANGE ; 
 int HARDWARE_ERROR ; 
 int ILLEGAL_REQUEST ; 
 int INVALID_CDB ; 
 int INVALID_FIELED_IN_COMMAND ; 
 int LENGTH_INQUIRY_PAGE00 ; 
 int MEDIUM_NOT_PRESENT ; 
 int MIN (int,int) ; 
 int /*<<< orphan*/  MSC_BOT_SendCSW (TYPE_9__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MSC_IN_EP ; 
 int MSC_MEDIA_PACKET ; 
 int* MSC_Mode_Sense10_data ; 
 int* MSC_Mode_Sense6_data ; 
 int /*<<< orphan*/  MSC_OUT_EP ; 
 scalar_t__ MSC_Page00_Inquiry_Data ; 
 int NOT_READY ; 
 int REQUEST_SENSE_DATA_LEN ; 
#define  SCSI_ALLOW_MEDIUM_REMOVAL 141 
static  int SCSI_AllowMediumRemoval (TYPE_9__*,int,int*) ; 
static  int SCSI_CheckAddressRange (TYPE_9__*,int,int,int) ; 
#define  SCSI_INQUIRY 140 
static  int SCSI_Inquiry (TYPE_9__*,int,int*) ; 
#define  SCSI_MODE_SENSE10 139 
#define  SCSI_MODE_SENSE6 138 
static  int SCSI_ModeSense10 (TYPE_9__*,int,int*) ; 
static  int SCSI_ModeSense6 (TYPE_9__*,int,int*) ; 
static  int SCSI_ProcessRead (TYPE_9__*,int) ; 
static  int SCSI_ProcessWrite (TYPE_9__*,int) ; 
#define  SCSI_READ10 137 
#define  SCSI_READ_CAPACITY10 136 
#define  SCSI_READ_FORMAT_CAPACITIES 135 
#define  SCSI_REQUEST_SENSE 134 
static  int SCSI_Read10 (TYPE_9__*,int,int*) ; 
static  int SCSI_ReadCapacity10 (TYPE_9__*,int,int*) ; 
static  int SCSI_ReadFormatCapacity (TYPE_9__*,int,int*) ; 
static  int SCSI_RequestSense (TYPE_9__*,int,int*) ; 
#define  SCSI_START_STOP_UNIT 133 
#define  SCSI_SYNCHRONIZE_CACHE10 132 
#define  SCSI_SYNCHRONIZE_CACHE16 131 
 void SCSI_SenseCode (TYPE_9__*,int,int,int) ; 
static  int SCSI_StartStopUnit (TYPE_9__*,int,int*) ; 
static  int SCSI_SynchronizeCache (TYPE_9__*,int,int*) ; 
#define  SCSI_TEST_UNIT_READY 130 
static  int SCSI_TestUnitReady (TYPE_9__*,int,int*) ; 
#define  SCSI_VERIFY10 129 
static  int SCSI_Verify10 (TYPE_9__*,int,int*) ; 
#define  SCSI_WRITE10 128 
static  int SCSI_Write10 (TYPE_9__*,int,int*) ; 
 size_t SENSE_LIST_DEEPTH ; 
 int STANDARD_INQUIRY_DATA_LEN ; 
 int UNRECOVERED_READ_ERROR ; 
 scalar_t__ USBD_BOT_DATA_IN ; 
 scalar_t__ USBD_BOT_DATA_OUT ; 
 scalar_t__ USBD_BOT_IDLE ; 
 scalar_t__ USBD_BOT_LAST_DATA_IN ; 
 scalar_t__ USBD_BOT_NO_DATA ; 
 int /*<<< orphan*/  USBD_CSW_CMD_PASSED ; 
 int /*<<< orphan*/  USBD_LL_PrepareReceive (TYPE_9__*,int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  USBD_LL_Transmit (TYPE_9__*,int /*<<< orphan*/ ,int*,int) ; 
 int WRITE_FAULT ; 
 int WRITE_PROTECTED ; 
 scalar_t__ stub1 (int) ; 
 scalar_t__ stub10 (int,int*,int,int) ; 
 scalar_t__ stub2 (int,int*,int*) ; 
 scalar_t__ stub3 (int,int*,int*) ; 
 int /*<<< orphan*/  stub4 (int,int) ; 
 int /*<<< orphan*/  stub5 (int,int) ; 
 scalar_t__ stub6 (int) ; 
 scalar_t__ stub7 (int) ; 
 scalar_t__ stub8 (int) ; 
 scalar_t__ stub9 (int,int*,int,int) ; 

int8_t SCSI_ProcessCmd(USBD_HandleTypeDef  *pdev,
                           uint8_t lun,
                           uint8_t *params)
{
    /*
    if (params[0] != SCSI_READ10 && params[0] != SCSI_WRITE10) {
        printf("SCSI_ProcessCmd(lun=%d, params=%x, %x)\n", lun, params[0], params[1]);
    }
    */

  switch (params[0])
  {
  case SCSI_TEST_UNIT_READY:
    return SCSI_TestUnitReady(pdev, lun, params);

  case SCSI_REQUEST_SENSE:
    return SCSI_RequestSense (pdev, lun, params);
  case SCSI_INQUIRY:
    return SCSI_Inquiry(pdev, lun, params);

  case SCSI_START_STOP_UNIT:
    return SCSI_StartStopUnit(pdev, lun, params);

  case SCSI_ALLOW_MEDIUM_REMOVAL:
    return SCSI_AllowMediumRemoval(pdev, lun, params);

  case SCSI_MODE_SENSE6:
    return SCSI_ModeSense6 (pdev, lun, params);

  case SCSI_MODE_SENSE10:
    return SCSI_ModeSense10 (pdev, lun, params);

  case SCSI_SYNCHRONIZE_CACHE10:
  case SCSI_SYNCHRONIZE_CACHE16:
    return SCSI_SynchronizeCache(pdev, lun, params);

  case SCSI_READ_FORMAT_CAPACITIES:
    return SCSI_ReadFormatCapacity(pdev, lun, params);

  case SCSI_READ_CAPACITY10:
    return SCSI_ReadCapacity10(pdev, lun, params);

  case SCSI_READ10:
    return SCSI_Read10(pdev, lun, params);

  case SCSI_WRITE10:
    return SCSI_Write10(pdev, lun, params);

  case SCSI_VERIFY10:
    return SCSI_Verify10(pdev, lun, params);

  default:
    SCSI_SenseCode(pdev,
                   lun,
                   ILLEGAL_REQUEST,
                   INVALID_CDB);
    return -1;
  }
}

__attribute__((used)) static int8_t SCSI_TestUnitReady(USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  /* case 9 : Hi > D0 */
  if (hmsc->cbw.dDataLength != 0)
  {
    SCSI_SenseCode(pdev,
                   hmsc->cbw.bLUN,
                   ILLEGAL_REQUEST,
                   INVALID_CDB);
    return -1;
  }

  if(hmsc->bdev_ops->IsReady(lun) !=0 )
  {
    SCSI_SenseCode(pdev,
                   lun,
                   NOT_READY,
                   MEDIUM_NOT_PRESENT);

    hmsc->bot_state = USBD_BOT_NO_DATA;
    return -1;
  }
  hmsc->bot_data_length = 0;
  return 0;
}

__attribute__((used)) static int8_t  SCSI_Inquiry(USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params)
{
  uint8_t* pPage;
  uint16_t len;
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  if (params[1] & 0x01)/*Evpd is set*/
  {
    pPage = (uint8_t *)MSC_Page00_Inquiry_Data;
    len = LENGTH_INQUIRY_PAGE00;
  }
  else
  {

    pPage = (uint8_t *)&hmsc->bdev_ops->pInquiry[lun * STANDARD_INQUIRY_DATA_LEN];
    len = pPage[4] + 5;

    if (params[4] <= len)
    {
      len = params[4];
    }
  }
  hmsc->bot_data_length = len;

  while (len)
  {
    len--;
    hmsc->bot_data[len] = pPage[len];
  }
  return 0;
}

__attribute__((used)) static int8_t SCSI_ReadCapacity10(USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  if(hmsc->bdev_ops->GetCapacity(lun, &hmsc->scsi_blk_nbr, &hmsc->scsi_blk_size) != 0)
  {
    SCSI_SenseCode(pdev,
                   lun,
                   NOT_READY,
                   MEDIUM_NOT_PRESENT);
    return -1;
  }
  else
  {

    hmsc->bot_data[0] = (uint8_t)((hmsc->scsi_blk_nbr - 1) >> 24);
    hmsc->bot_data[1] = (uint8_t)((hmsc->scsi_blk_nbr - 1) >> 16);
    hmsc->bot_data[2] = (uint8_t)((hmsc->scsi_blk_nbr - 1) >>  8);
    hmsc->bot_data[3] = (uint8_t)(hmsc->scsi_blk_nbr - 1);

    hmsc->bot_data[4] = (uint8_t)(hmsc->scsi_blk_size >>  24);
    hmsc->bot_data[5] = (uint8_t)(hmsc->scsi_blk_size >>  16);
    hmsc->bot_data[6] = (uint8_t)(hmsc->scsi_blk_size >>  8);
    hmsc->bot_data[7] = (uint8_t)(hmsc->scsi_blk_size);

    hmsc->bot_data_length = 8;
    return 0;
  }
}

__attribute__((used)) static int8_t SCSI_ReadFormatCapacity(USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  uint16_t blk_size;
  uint32_t blk_nbr;
  uint16_t i;

  for(i=0 ; i < 12 ; i++)
  {
    hmsc->bot_data[i] = 0;
  }

  if(hmsc->bdev_ops->GetCapacity(lun, &blk_nbr, &blk_size) != 0)
  {
    SCSI_SenseCode(pdev,
                   lun,
                   NOT_READY,
                   MEDIUM_NOT_PRESENT);
    return -1;
  }
  else
  {
    hmsc->bot_data[3] = 0x08;
    hmsc->bot_data[4] = (uint8_t)((blk_nbr - 1) >> 24);
    hmsc->bot_data[5] = (uint8_t)((blk_nbr - 1) >> 16);
    hmsc->bot_data[6] = (uint8_t)((blk_nbr - 1) >>  8);
    hmsc->bot_data[7] = (uint8_t)(blk_nbr - 1);

    hmsc->bot_data[8] = 0x02;
    hmsc->bot_data[9] = (uint8_t)(blk_size >>  16);
    hmsc->bot_data[10] = (uint8_t)(blk_size >>  8);
    hmsc->bot_data[11] = (uint8_t)(blk_size);

    hmsc->bot_data_length = 12;
    return 0;
  }
}

__attribute__((used)) static int8_t SCSI_ModeSense6 (USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;
  uint16_t len = 8 ;
  hmsc->bot_data_length = len;

  while (len)
  {
    len--;
    hmsc->bot_data[len] = MSC_Mode_Sense6_data[len];
  }
  return 0;
}

__attribute__((used)) static int8_t SCSI_ModeSense10 (USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params)
{
  uint16_t len = 8;
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  hmsc->bot_data_length = len;

  while (len)
  {
    len--;
    hmsc->bot_data[len] = MSC_Mode_Sense10_data[len];
  }
  return 0;
}

__attribute__((used)) static int8_t SCSI_SynchronizeCache(USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params) {
    // nothing to synchronize, so just return "success"
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;
    hmsc->bot_data_length = 0;
    return 0;
}

__attribute__((used)) static int8_t SCSI_RequestSense (USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params)
{
  uint8_t i;
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  for(i=0 ; i < REQUEST_SENSE_DATA_LEN ; i++)
  {
    hmsc->bot_data[i] = 0;
  }

  hmsc->bot_data[0]     = 0x70;
  hmsc->bot_data[7]     = REQUEST_SENSE_DATA_LEN - 6;

  if((hmsc->scsi_sense_head != hmsc->scsi_sense_tail)) {

    hmsc->bot_data[2]     = hmsc->scsi_sense[hmsc->scsi_sense_head].Skey;
    hmsc->bot_data[12]    = hmsc->scsi_sense[hmsc->scsi_sense_head].w.b.ASCQ;
    hmsc->bot_data[13]    = hmsc->scsi_sense[hmsc->scsi_sense_head].w.b.ASC;
    hmsc->scsi_sense_head++;

    if (hmsc->scsi_sense_head == SENSE_LIST_DEEPTH)
    {
      hmsc->scsi_sense_head = 0;
    }
  }
  hmsc->bot_data_length = REQUEST_SENSE_DATA_LEN;

  if (params[4] <= REQUEST_SENSE_DATA_LEN)
  {
    hmsc->bot_data_length = params[4];
  }
  return 0;
}

void SCSI_SenseCode(USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t sKey, uint8_t ASC)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  hmsc->scsi_sense[hmsc->scsi_sense_tail].Skey  = sKey;
  hmsc->scsi_sense[hmsc->scsi_sense_tail].w.ASC = ASC << 8;
  hmsc->scsi_sense_tail++;
  if (hmsc->scsi_sense_tail == SENSE_LIST_DEEPTH)
  {
    hmsc->scsi_sense_tail = 0;
  }
}

__attribute__((used)) static int8_t SCSI_StartStopUnit(USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;
  hmsc->bot_data_length = 0;

  // On Mac OS X, when the device is ejected a SCSI_START_STOP_UNIT command is sent.
  // Bit 0 of params[4] is the START bit.
  // If we get a stop, we must really stop the device so that the Mac does not
  // automatically remount it.
  hmsc->bdev_ops->StartStopUnit(lun, params[4] & 1);

  return 0;
}

__attribute__((used)) static int8_t SCSI_AllowMediumRemoval(USBD_HandleTypeDef  *pdev, uint8_t lun, uint8_t *params)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;
  hmsc->bot_data_length = 0;
  hmsc->bdev_ops->PreventAllowMediumRemoval(lun, params[4]);
  return 0;
}

__attribute__((used)) static int8_t SCSI_Read10(USBD_HandleTypeDef  *pdev, uint8_t lun , uint8_t *params)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  if(hmsc->bot_state == USBD_BOT_IDLE)  /* Idle */
  {

    /* case 10 : Ho <> Di */

    if ((hmsc->cbw.bmFlags & 0x80) != 0x80)
    {
      SCSI_SenseCode(pdev,
                     hmsc->cbw.bLUN,
                     ILLEGAL_REQUEST,
                     INVALID_CDB);
      return -1;
    }

    if(hmsc->bdev_ops->IsReady(lun) !=0 )
    {
      SCSI_SenseCode(pdev,
                     lun,
                     NOT_READY,
                     MEDIUM_NOT_PRESENT);
      return -1;
    }

    hmsc->scsi_blk_addr_in_blks = (params[2] << 24) | \
      (params[3] << 16) | \
        (params[4] <<  8) | \
          params[5];

    hmsc->scsi_blk_len =  (params[7] <<  8) | \
      params[8];



    if( SCSI_CheckAddressRange(pdev, lun, hmsc->scsi_blk_addr_in_blks, hmsc->scsi_blk_len) < 0)
    {
      return -1; /* error */
    }

    hmsc->bot_state = USBD_BOT_DATA_IN;
    hmsc->scsi_blk_len  *= hmsc->scsi_blk_size;

    /* cases 4,5 : Hi <> Dn */
    if (hmsc->cbw.dDataLength != hmsc->scsi_blk_len)
    {
      SCSI_SenseCode(pdev,
                     hmsc->cbw.bLUN,
                     ILLEGAL_REQUEST,
                     INVALID_CDB);
      return -1;
    }
  }
  hmsc->bot_data_length = MSC_MEDIA_PACKET;

  return SCSI_ProcessRead(pdev, lun);
}

__attribute__((used)) static int8_t SCSI_Write10 (USBD_HandleTypeDef  *pdev, uint8_t lun , uint8_t *params)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  if (hmsc->bot_state == USBD_BOT_IDLE) /* Idle */
  {

    /* case 8 : Hi <> Do */

    if ((hmsc->cbw.bmFlags & 0x80) == 0x80)
    {
      SCSI_SenseCode(pdev,
                     hmsc->cbw.bLUN,
                     ILLEGAL_REQUEST,
                     INVALID_CDB);
      return -1;
    }

    /* Check whether Media is ready */
    if(hmsc->bdev_ops->IsReady(lun) !=0 )
    {
      SCSI_SenseCode(pdev,
                     lun,
                     NOT_READY,
                     MEDIUM_NOT_PRESENT);
      return -1;
    }

    /* Check If media is write-protected */
    if(hmsc->bdev_ops->IsWriteProtected(lun) !=0 )
    {
      SCSI_SenseCode(pdev,
                     lun,
                     NOT_READY,
                     WRITE_PROTECTED);
      return -1;
    }


    hmsc->scsi_blk_addr_in_blks = (params[2] << 24) | \
      (params[3] << 16) | \
        (params[4] <<  8) | \
          params[5];
    hmsc->scsi_blk_len = (params[7] <<  8) | \
      params[8];

    /* check if LBA address is in the right range */
    if(SCSI_CheckAddressRange(pdev,
                              lun,
                              hmsc->scsi_blk_addr_in_blks,
                              hmsc->scsi_blk_len) < 0)
    {
      return -1; /* error */
    }

    hmsc->scsi_blk_len  *= hmsc->scsi_blk_size;

    /* cases 3,11,13 : Hn,Ho <> D0 */
    if (hmsc->cbw.dDataLength != hmsc->scsi_blk_len)
    {
      SCSI_SenseCode(pdev,
                     hmsc->cbw.bLUN,
                     ILLEGAL_REQUEST,
                     INVALID_CDB);
      return -1;
    }

    /* Prepare EP to receive first data packet */
    hmsc->bot_state = USBD_BOT_DATA_OUT;
    USBD_LL_PrepareReceive (pdev,
                      MSC_OUT_EP,
                      hmsc->bot_data,
                      MIN (hmsc->scsi_blk_len, MSC_MEDIA_PACKET));
  }
  else /* Write Process ongoing */
  {
    return SCSI_ProcessWrite(pdev, lun);
  }
  return 0;
}

__attribute__((used)) static int8_t SCSI_Verify10(USBD_HandleTypeDef  *pdev, uint8_t lun , uint8_t *params)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  if ((params[1]& 0x02) == 0x02)
  {
    SCSI_SenseCode (pdev,
                    lun,
                    ILLEGAL_REQUEST,
                    INVALID_FIELED_IN_COMMAND);
    return -1; /* Error, Verify Mode Not supported*/
  }

  hmsc->scsi_blk_addr_in_blks = (params[2] << 24) | (params[3] << 16) | (params[4] << 8) | params[5];
  hmsc->scsi_blk_len = (params[7] << 8) | params[8];

  if(SCSI_CheckAddressRange(pdev,
                            lun,
                            hmsc->scsi_blk_addr_in_blks,
                            hmsc->scsi_blk_len) < 0)
  {
    return -1; /* error */
  }
  hmsc->bot_data_length = 0;
  return 0;
}

__attribute__((used)) static int8_t SCSI_CheckAddressRange (USBD_HandleTypeDef  *pdev, uint8_t lun , uint32_t blk_offset , uint16_t blk_nbr)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  if ((blk_offset + blk_nbr) > hmsc->scsi_blk_nbr )
  {
    SCSI_SenseCode(pdev,
                   lun,
                   ILLEGAL_REQUEST,
                   ADDRESS_OUT_OF_RANGE);
    return -1;
  }
  return 0;
}

__attribute__((used)) static int8_t SCSI_ProcessRead (USBD_HandleTypeDef  *pdev, uint8_t lun)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;
  uint32_t len;

  len = MIN(hmsc->scsi_blk_len , MSC_MEDIA_PACKET);

  if( hmsc->bdev_ops->Read(lun ,
                              hmsc->bot_data,
                              hmsc->scsi_blk_addr_in_blks,
                              len / hmsc->scsi_blk_size) < 0)
  {

    SCSI_SenseCode(pdev,
                   lun,
                   HARDWARE_ERROR,
                   UNRECOVERED_READ_ERROR);
    return -1;
  }


  USBD_LL_Transmit (pdev,
             MSC_IN_EP,
             hmsc->bot_data,
             len);


  hmsc->scsi_blk_addr_in_blks += len / hmsc->scsi_blk_size;
  hmsc->scsi_blk_len    -= len;

  /* case 6 : Hi = Di */
  hmsc->csw.dDataResidue -= len;

  if (hmsc->scsi_blk_len == 0)
  {
    hmsc->bot_state = USBD_BOT_LAST_DATA_IN;
  }
  return 0;
}

__attribute__((used)) static int8_t SCSI_ProcessWrite (USBD_HandleTypeDef  *pdev, uint8_t lun)
{
  uint32_t len;
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((usbd_cdc_msc_hid_state_t*)pdev->pClassData)->MSC_BOT_ClassData;

  len = MIN(hmsc->scsi_blk_len , MSC_MEDIA_PACKET);

  if(hmsc->bdev_ops->Write(lun ,
                              hmsc->bot_data,
                              hmsc->scsi_blk_addr_in_blks,
                              len / hmsc->scsi_blk_size) < 0)
  {
    SCSI_SenseCode(pdev,
                   lun,
                   HARDWARE_ERROR,
                   WRITE_FAULT);
    return -1;
  }


  hmsc->scsi_blk_addr_in_blks += len / hmsc->scsi_blk_size;
  hmsc->scsi_blk_len   -= len;

  /* case 12 : Ho = Do */
  hmsc->csw.dDataResidue -= len;

  if (hmsc->scsi_blk_len == 0)
  {
    MSC_BOT_SendCSW (pdev, USBD_CSW_CMD_PASSED);
  }
  else
  {
    /* Prapare EP to Receive next packet */
    USBD_LL_PrepareReceive (pdev,
                            MSC_OUT_EP,
                            hmsc->bot_data,
                            MIN (hmsc->scsi_blk_len, MSC_MEDIA_PACKET));
  }

  return 0;
}

