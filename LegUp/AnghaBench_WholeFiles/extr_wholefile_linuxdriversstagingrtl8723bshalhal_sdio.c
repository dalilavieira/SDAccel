#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  size_t u8 ;
typedef  size_t u32 ;
struct hal_com_data {int SdioTxOQTMaxFreeSpace; size_t* SdioTxFIFOFreePage; size_t* sdio_tx_max_len; } ;
struct dvobj_priv {int dummy; } ;
struct adapter {int dummy; } ;

/* Variables and functions */
 struct hal_com_data* GET_HAL_DATA (struct adapter*) ; 
 int /*<<< orphan*/  HAL_DEF_TX_PAGE_SIZE ; 
 size_t HI_QUEUE_IDX ; 
 size_t LOW_QUEUE_IDX ; 
 size_t MAX_XMITBUF_SZ ; 
 size_t MID_QUEUE_IDX ; 
 size_t PUBLIC_QUEUE_IDX ; 
#define  WLAN_TX_HIQ_DEVICE_ID 130 
#define  WLAN_TX_LOQ_DEVICE_ID 129 
#define  WLAN_TX_MIQ_DEVICE_ID 128 
 struct dvobj_priv* adapter_to_dvobj (struct adapter*) ; 
 size_t ffaddr2deviceId (struct dvobj_priv*,size_t) ; 
 int /*<<< orphan*/  rtw_hal_get_def_var (struct adapter*,int /*<<< orphan*/ ,size_t*) ; 

u8 rtw_hal_sdio_max_txoqt_free_space(struct adapter *padapter)
{
	struct hal_com_data	*pHalData = GET_HAL_DATA(padapter);

	if (pHalData->SdioTxOQTMaxFreeSpace < 8)
		pHalData->SdioTxOQTMaxFreeSpace = 8;

	return pHalData->SdioTxOQTMaxFreeSpace;
}

u8 rtw_hal_sdio_query_tx_freepage(
	struct adapter *padapter, u8 PageIdx, u8 RequiredPageNum
)
{
	struct hal_com_data	*pHalData = GET_HAL_DATA(padapter);

	if ((pHalData->SdioTxFIFOFreePage[PageIdx]+pHalData->SdioTxFIFOFreePage[PUBLIC_QUEUE_IDX]) >= (RequiredPageNum))
		return true;
	else
		return false;
}

void rtw_hal_sdio_update_tx_freepage(
	struct adapter *padapter, u8 PageIdx, u8 RequiredPageNum
)
{
	struct hal_com_data	*pHalData = GET_HAL_DATA(padapter);
	u8 DedicatedPgNum = 0;
	u8 RequiredPublicFreePgNum = 0;
	/* _irqL irql; */

	/* spin_lock_bh(&pHalData->SdioTxFIFOFreePageLock); */

	DedicatedPgNum = pHalData->SdioTxFIFOFreePage[PageIdx];
	if (RequiredPageNum <= DedicatedPgNum) {
		pHalData->SdioTxFIFOFreePage[PageIdx] -= RequiredPageNum;
	} else {
		pHalData->SdioTxFIFOFreePage[PageIdx] = 0;
		RequiredPublicFreePgNum = RequiredPageNum - DedicatedPgNum;
		pHalData->SdioTxFIFOFreePage[PUBLIC_QUEUE_IDX] -= RequiredPublicFreePgNum;
	}

	/* spin_unlock_bh(&pHalData->SdioTxFIFOFreePageLock); */
}

void rtw_hal_set_sdio_tx_max_length(
	struct adapter *padapter, u8 numHQ, u8 numNQ, u8 numLQ, u8 numPubQ
)
{
	struct hal_com_data	*pHalData = GET_HAL_DATA(padapter);
	u32 page_size;
	u32 lenHQ, lenNQ, lenLQ;

	rtw_hal_get_def_var(padapter, HAL_DEF_TX_PAGE_SIZE, &page_size);

	lenHQ = ((numHQ + numPubQ) >> 1) * page_size;
	lenNQ = ((numNQ + numPubQ) >> 1) * page_size;
	lenLQ = ((numLQ + numPubQ) >> 1) * page_size;

	pHalData->sdio_tx_max_len[HI_QUEUE_IDX] =
		(lenHQ > MAX_XMITBUF_SZ) ? MAX_XMITBUF_SZ : lenHQ;
	pHalData->sdio_tx_max_len[MID_QUEUE_IDX] =
		(lenNQ > MAX_XMITBUF_SZ) ? MAX_XMITBUF_SZ : lenNQ;
	pHalData->sdio_tx_max_len[LOW_QUEUE_IDX] =
		(lenLQ > MAX_XMITBUF_SZ) ? MAX_XMITBUF_SZ : lenLQ;
}

u32 rtw_hal_get_sdio_tx_max_length(struct adapter *padapter, u8 queue_idx)
{
	struct dvobj_priv *pdvobjpriv = adapter_to_dvobj(padapter);
	struct hal_com_data	*pHalData = GET_HAL_DATA(padapter);
	u32 deviceId, max_len;


	deviceId = ffaddr2deviceId(pdvobjpriv, queue_idx);
	switch (deviceId) {
	case WLAN_TX_HIQ_DEVICE_ID:
		max_len = pHalData->sdio_tx_max_len[HI_QUEUE_IDX];
		break;

	case WLAN_TX_MIQ_DEVICE_ID:
		max_len = pHalData->sdio_tx_max_len[MID_QUEUE_IDX];
		break;

	case WLAN_TX_LOQ_DEVICE_ID:
		max_len = pHalData->sdio_tx_max_len[LOW_QUEUE_IDX];
		break;

	default:
		max_len = pHalData->sdio_tx_max_len[MID_QUEUE_IDX];
		break;
	}

	return max_len;
}

