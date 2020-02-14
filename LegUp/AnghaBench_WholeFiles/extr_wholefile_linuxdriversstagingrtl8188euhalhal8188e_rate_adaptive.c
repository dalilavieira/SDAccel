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
typedef  int u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct odm_ra_info {scalar_t__ RptTime; int PreRate; int LowestRate; int HighestRate; int RateSGI; int RAUseRate; int RAWaitingCounter; int RAPendingCounter; int DecisionRate; int PreRssiStaRA; int RssiStaRA; int SGIEnable; int NscUp; int NscDown; int Active; scalar_t__ TOTAL; int* RTY; scalar_t__ DROP; int RateID; int RateMask; int PTModeSS; int PTTryState; int PTStage; int PTStopCount; int PTPreRssi; scalar_t__ PTPreRate; int RAstage; int PTSmoothFactor; int PTActive; } ;
struct odm_dm_struct {scalar_t__ CurrminRptTime; int* pWirelessMode; struct odm_ra_info* RAInfo; struct adapter* Adapter; } ;
struct adapter {int dummy; } ;
typedef  scalar_t__ s8 ;

/* Variables and functions */
 int ASSOCIATE_ENTRY_NUM ; 
 int BIT (scalar_t__) ; 
 scalar_t__* DROPING_NECESSARY ; 
 scalar_t__* DynamicTxRPTTiming ; 
 scalar_t__ GET_TX_REPORT_TYPE1_DROP_0 (int*) ; 
 scalar_t__ GET_TX_REPORT_TYPE1_RERTY_0 (int*) ; 
 scalar_t__ GET_TX_REPORT_TYPE1_RERTY_1 (int*) ; 
 scalar_t__ GET_TX_REPORT_TYPE1_RERTY_2 (int*) ; 
 scalar_t__ GET_TX_REPORT_TYPE1_RERTY_3 (int*) ; 
 scalar_t__ GET_TX_REPORT_TYPE1_RERTY_4 (int*) ; 
 int* N_THRESHOLD_HIGH ; 
 int* N_THRESHOLD_LOW ; 
 int ODM_ASSOCIATE_ENTRY_NUM ; 
 int ODM_COMP_INIT ; 
 int ODM_COMP_RATE_ADAPTIVE ; 
 int /*<<< orphan*/  ODM_DBG_LOUD ; 
 int /*<<< orphan*/  ODM_DBG_TRACE ; 
 int /*<<< orphan*/  ODM_RT_TRACE (struct odm_dm_struct*,int,int /*<<< orphan*/ ,char*) ; 
 int ODM_WM_B ; 
 int ODM_WM_G ; 
 int ODM_WM_N24G ; 
 int* PT_PENALTY ; 
 int* PendingForRateUpFail ; 
 scalar_t__ RATESIZE ; 
#define  RATR_INX_WIRELESS_B 134 
#define  RATR_INX_WIRELESS_G 133 
#define  RATR_INX_WIRELESS_GB 132 
#define  RATR_INX_WIRELESS_N 131 
#define  RATR_INX_WIRELESS_NB 130 
#define  RATR_INX_WIRELESS_NG 129 
#define  RATR_INX_WIRELESS_NGB 128 
 int /*<<< orphan*/  REG_ARFR0 ; 
 int /*<<< orphan*/  REG_ARFR1 ; 
 int /*<<< orphan*/  REG_ARFR2 ; 
 int /*<<< orphan*/  REG_ARFR3 ; 
 int /*<<< orphan*/  REG_TX_RPT_TIME ; 
 int** RETRY_PENALTY ; 
 int** RETRY_PENALTY_IDX ; 
 int* RETRY_PENALTY_UP_IDX ; 
 int* RSSI_THRESHOLD ; 
 int /*<<< orphan*/  TX_RPT2_ITEM_SIZE ; 
 int /*<<< orphan*/  rtw_rpt_timer_cfg_cmd (struct adapter*,scalar_t__) ; 
 int usb_read32 (struct adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_write16 (struct adapter*,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void odm_SetTxRPTTiming_8188E(
		struct odm_dm_struct *dm_odm,
		struct odm_ra_info *pRaInfo,
		u8 extend
	)
{
	u8 idx = 0;

	for (idx = 0; idx < 5; idx++)
		if (DynamicTxRPTTiming[idx] == pRaInfo->RptTime)
			break;

	if (extend == 0) { /*  back to default timing */
		idx = 0;  /* 200ms */
	} else if (extend == 1) {/*  increase the timing */
		idx += 1;
		if (idx > 5)
			idx = 5;
	} else if (extend == 2) {/*  decrease the timing */
		if (idx != 0)
			idx -= 1;
	}
	pRaInfo->RptTime = DynamicTxRPTTiming[idx];

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
			("pRaInfo->RptTime = 0x%x\n", pRaInfo->RptTime));
}

__attribute__((used)) static int odm_RateDown_8188E(struct odm_dm_struct *dm_odm,
				struct odm_ra_info *pRaInfo)
{
	u8 RateID, LowestRate, HighestRate;
	u8 i;

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE,
			ODM_DBG_TRACE, ("=====>odm_RateDown_8188E()\n"));
	if (!pRaInfo) {
		ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
				("odm_RateDown_8188E(): pRaInfo is NULL\n"));
		return -1;
	}
	RateID = pRaInfo->PreRate;
	LowestRate = pRaInfo->LowestRate;
	HighestRate = pRaInfo->HighestRate;

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
		     (" RateID =%d LowestRate =%d HighestRate =%d RateSGI =%d\n",
		     RateID, LowestRate, HighestRate, pRaInfo->RateSGI));
	if (RateID > HighestRate) {
		RateID = HighestRate;
	} else if (pRaInfo->RateSGI) {
		pRaInfo->RateSGI = 0;
	} else if (RateID > LowestRate) {
		if (RateID > 0) {
			for (i = RateID-1; i > LowestRate; i--) {
				if (pRaInfo->RAUseRate & BIT(i)) {
					RateID = i;
					goto RateDownFinish;
				}
			}
		}
	} else if (RateID <= LowestRate) {
		RateID = LowestRate;
	}
RateDownFinish:
	if (pRaInfo->RAWaitingCounter == 1) {
		pRaInfo->RAWaitingCounter += 1;
		pRaInfo->RAPendingCounter += 1;
	} else if (pRaInfo->RAWaitingCounter == 0) {
		;
	} else {
		pRaInfo->RAWaitingCounter = 0;
		pRaInfo->RAPendingCounter = 0;
	}

	if (pRaInfo->RAPendingCounter >= 4)
		pRaInfo->RAPendingCounter = 4;

	pRaInfo->DecisionRate = RateID;
	odm_SetTxRPTTiming_8188E(dm_odm, pRaInfo, 2);
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE,
			ODM_DBG_LOUD, ("Rate down, RPT Timing default\n"));
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
			("RAWaitingCounter %d, RAPendingCounter %d",
			 pRaInfo->RAWaitingCounter, pRaInfo->RAPendingCounter));
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
			("Rate down to RateID %d RateSGI %d\n", RateID, pRaInfo->RateSGI));
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
			("<===== odm_RateDown_8188E()\n"));
	return 0;
}

__attribute__((used)) static int odm_RateUp_8188E(
		struct odm_dm_struct *dm_odm,
		struct odm_ra_info *pRaInfo
	)
{
	u8 RateID, HighestRate;
	u8 i;

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE,
			ODM_DBG_TRACE, ("=====>odm_RateUp_8188E()\n"));
	if (!pRaInfo) {
		ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
				("odm_RateUp_8188E(): pRaInfo is NULL\n"));
		return -1;
	}
	RateID = pRaInfo->PreRate;
	HighestRate = pRaInfo->HighestRate;
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
		     (" RateID =%d HighestRate =%d\n",
		     RateID, HighestRate));
	if (pRaInfo->RAWaitingCounter == 1) {
		pRaInfo->RAWaitingCounter = 0;
		pRaInfo->RAPendingCounter = 0;
	} else if (pRaInfo->RAWaitingCounter > 1) {
		pRaInfo->PreRssiStaRA = pRaInfo->RssiStaRA;
		goto RateUpfinish;
	}
	odm_SetTxRPTTiming_8188E(dm_odm, pRaInfo, 0);
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
			("odm_RateUp_8188E():Decrease RPT Timing\n"));

	if (RateID < HighestRate) {
		for (i = RateID+1; i <= HighestRate; i++) {
			if (pRaInfo->RAUseRate & BIT(i)) {
				RateID = i;
				goto RateUpfinish;
			}
		}
	} else if (RateID == HighestRate) {
		if (pRaInfo->SGIEnable && (pRaInfo->RateSGI != 1))
			pRaInfo->RateSGI = 1;
		else if ((pRaInfo->SGIEnable) != 1)
			pRaInfo->RateSGI = 0;
	} else {
		RateID = HighestRate;
	}
RateUpfinish:
	if (pRaInfo->RAWaitingCounter ==
		(4+PendingForRateUpFail[pRaInfo->RAPendingCounter]))
		pRaInfo->RAWaitingCounter = 0;
	else
		pRaInfo->RAWaitingCounter++;

	pRaInfo->DecisionRate = RateID;
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
			("Rate up to RateID %d\n", RateID));
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
			("RAWaitingCounter %d, RAPendingCounter %d",
			 pRaInfo->RAWaitingCounter, pRaInfo->RAPendingCounter));
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE,
			ODM_DBG_TRACE, ("<===== odm_RateUp_8188E()\n"));
	return 0;
}

__attribute__((used)) static void odm_ResetRaCounter_8188E(struct odm_ra_info *pRaInfo)
{
	u8 RateID;

	RateID = pRaInfo->DecisionRate;
	pRaInfo->NscUp = (N_THRESHOLD_HIGH[RateID]+N_THRESHOLD_LOW[RateID])>>1;
	pRaInfo->NscDown = (N_THRESHOLD_HIGH[RateID]+N_THRESHOLD_LOW[RateID])>>1;
}

__attribute__((used)) static void odm_RateDecision_8188E(struct odm_dm_struct *dm_odm,
		struct odm_ra_info *pRaInfo
	)
{
	u8 RateID = 0, RtyPtID = 0, PenaltyID1 = 0, PenaltyID2 = 0, i = 0;
	/* u32 pool_retry; */
	static u8 DynamicTxRPTTimingCounter;

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
			("=====>odm_RateDecision_8188E()\n"));

	if (pRaInfo->Active && (pRaInfo->TOTAL > 0)) { /*  STA used and data packet exits */
		if ((pRaInfo->RssiStaRA < (pRaInfo->PreRssiStaRA - 3)) ||
		    (pRaInfo->RssiStaRA > (pRaInfo->PreRssiStaRA + 3))) {
			pRaInfo->RAWaitingCounter = 0;
			pRaInfo->RAPendingCounter = 0;
		}
		/*  Start RA decision */
		if (pRaInfo->PreRate > pRaInfo->HighestRate)
			RateID = pRaInfo->HighestRate;
		else
			RateID = pRaInfo->PreRate;
		if (pRaInfo->RssiStaRA > RSSI_THRESHOLD[RateID])
			RtyPtID = 0;
		else
			RtyPtID = 1;
		PenaltyID1 = RETRY_PENALTY_IDX[RtyPtID][RateID]; /* TODO by page */

		ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
			     (" NscDown init is %d\n", pRaInfo->NscDown));

		for (i = 0 ; i <= 4 ; i++)
			pRaInfo->NscDown += pRaInfo->RTY[i] * RETRY_PENALTY[PenaltyID1][i];

		ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
			     (" NscDown is %d, total*penalty[5] is %d\n", pRaInfo->NscDown,
			      (pRaInfo->TOTAL * RETRY_PENALTY[PenaltyID1][5])));

		if (pRaInfo->NscDown > (pRaInfo->TOTAL * RETRY_PENALTY[PenaltyID1][5]))
			pRaInfo->NscDown -= pRaInfo->TOTAL * RETRY_PENALTY[PenaltyID1][5];
		else
			pRaInfo->NscDown = 0;

		/*  rate up */
		PenaltyID2 = RETRY_PENALTY_UP_IDX[RateID];
		ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
			     (" NscUp init is %d\n", pRaInfo->NscUp));

		for (i = 0 ; i <= 4 ; i++)
			pRaInfo->NscUp += pRaInfo->RTY[i] * RETRY_PENALTY[PenaltyID2][i];

		ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
			     ("NscUp is %d, total*up[5] is %d\n",
			     pRaInfo->NscUp, (pRaInfo->TOTAL * RETRY_PENALTY[PenaltyID2][5])));

		if (pRaInfo->NscUp > (pRaInfo->TOTAL * RETRY_PENALTY[PenaltyID2][5]))
			pRaInfo->NscUp -= pRaInfo->TOTAL * RETRY_PENALTY[PenaltyID2][5];
		else
			pRaInfo->NscUp = 0;

		ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE|ODM_COMP_INIT, ODM_DBG_LOUD,
			     (" RssiStaRa = %d RtyPtID =%d PenaltyID1 = 0x%x  PenaltyID2 = 0x%x RateID =%d NscDown =%d NscUp =%d SGI =%d\n",
			     pRaInfo->RssiStaRA, RtyPtID, PenaltyID1, PenaltyID2, RateID, pRaInfo->NscDown, pRaInfo->NscUp, pRaInfo->RateSGI));
		if ((pRaInfo->NscDown < N_THRESHOLD_LOW[RateID]) ||
		    (pRaInfo->DROP > DROPING_NECESSARY[RateID]))
			odm_RateDown_8188E(dm_odm, pRaInfo);
		else if (pRaInfo->NscUp > N_THRESHOLD_HIGH[RateID])
			odm_RateUp_8188E(dm_odm, pRaInfo);

		if (pRaInfo->DecisionRate > pRaInfo->HighestRate)
			pRaInfo->DecisionRate = pRaInfo->HighestRate;

		if ((pRaInfo->DecisionRate) == (pRaInfo->PreRate))
			DynamicTxRPTTimingCounter += 1;
		else
			DynamicTxRPTTimingCounter = 0;

		if (DynamicTxRPTTimingCounter >= 4) {
			odm_SetTxRPTTiming_8188E(dm_odm, pRaInfo, 1);
			ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE,
				     ODM_DBG_LOUD, ("<===== Rate don't change 4 times, Extend RPT Timing\n"));
			DynamicTxRPTTimingCounter = 0;
		}

		pRaInfo->PreRate = pRaInfo->DecisionRate;  /* YJ, add, 120120 */

		odm_ResetRaCounter_8188E(pRaInfo);
	}
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE, ("<===== odm_RateDecision_8188E()\n"));
}

__attribute__((used)) static int odm_ARFBRefresh_8188E(struct odm_dm_struct *dm_odm, struct odm_ra_info *pRaInfo)
{  /*  Wilson 2011/10/26 */
	struct adapter *adapt = dm_odm->Adapter;
	u32 MaskFromReg;
	s8 i;

	switch (pRaInfo->RateID) {
	case RATR_INX_WIRELESS_NGB:
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&0x0f8ff015;
		break;
	case RATR_INX_WIRELESS_NG:
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&0x0f8ff010;
		break;
	case RATR_INX_WIRELESS_NB:
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&0x0f8ff005;
		break;
	case RATR_INX_WIRELESS_N:
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&0x0f8ff000;
		break;
	case RATR_INX_WIRELESS_GB:
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&0x00000ff5;
		break;
	case RATR_INX_WIRELESS_G:
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&0x00000ff0;
		break;
	case RATR_INX_WIRELESS_B:
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&0x0000000d;
		break;
	case 12:
		MaskFromReg = usb_read32(adapt, REG_ARFR0);
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&MaskFromReg;
		break;
	case 13:
		MaskFromReg = usb_read32(adapt, REG_ARFR1);
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&MaskFromReg;
		break;
	case 14:
		MaskFromReg = usb_read32(adapt, REG_ARFR2);
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&MaskFromReg;
		break;
	case 15:
		MaskFromReg = usb_read32(adapt, REG_ARFR3);
		pRaInfo->RAUseRate = (pRaInfo->RateMask)&MaskFromReg;
		break;
	default:
		pRaInfo->RAUseRate = (pRaInfo->RateMask);
		break;
	}
	/*  Highest rate */
	if (pRaInfo->RAUseRate) {
		for (i = RATESIZE; i >= 0; i--) {
			if ((pRaInfo->RAUseRate)&BIT(i)) {
				pRaInfo->HighestRate = i;
				break;
			}
		}
	} else {
		pRaInfo->HighestRate = 0;
	}
	/*  Lowest rate */
	if (pRaInfo->RAUseRate) {
		for (i = 0; i < RATESIZE; i++) {
			if ((pRaInfo->RAUseRate) & BIT(i)) {
				pRaInfo->LowestRate = i;
				break;
			}
		}
	} else {
		pRaInfo->LowestRate = 0;
	}
		if (pRaInfo->HighestRate > 0x13)
			pRaInfo->PTModeSS = 3;
		else if (pRaInfo->HighestRate > 0x0b)
			pRaInfo->PTModeSS = 2;
		else if (pRaInfo->HighestRate > 0x0b)
			pRaInfo->PTModeSS = 1;
		else
			pRaInfo->PTModeSS = 0;
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
		     ("ODM_ARFBRefresh_8188E(): PTModeSS =%d\n", pRaInfo->PTModeSS));

	if (pRaInfo->DecisionRate > pRaInfo->HighestRate)
		pRaInfo->DecisionRate = pRaInfo->HighestRate;

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
		     ("ODM_ARFBRefresh_8188E(): RateID =%d RateMask =%8.8x RAUseRate =%8.8x HighestRate =%d, DecisionRate =%d\n",
		     pRaInfo->RateID, pRaInfo->RateMask, pRaInfo->RAUseRate, pRaInfo->HighestRate, pRaInfo->DecisionRate));
	return 0;
}

__attribute__((used)) static void odm_PTTryState_8188E(struct odm_ra_info *pRaInfo)
{
	pRaInfo->PTTryState = 0;
	switch (pRaInfo->PTModeSS) {
	case 3:
		if (pRaInfo->DecisionRate >= 0x19)
			pRaInfo->PTTryState = 1;
		break;
	case 2:
		if (pRaInfo->DecisionRate >= 0x11)
			pRaInfo->PTTryState = 1;
		break;
	case 1:
		if (pRaInfo->DecisionRate >= 0x0a)
			pRaInfo->PTTryState = 1;
		break;
	case 0:
		if (pRaInfo->DecisionRate >= 0x03)
			pRaInfo->PTTryState = 1;
		break;
	default:
		pRaInfo->PTTryState = 0;
		break;
	}

	if (pRaInfo->RssiStaRA < 48) {
		pRaInfo->PTStage = 0;
	} else if (pRaInfo->PTTryState == 1) {
		if ((pRaInfo->PTStopCount >= 10) ||
		    (pRaInfo->PTPreRssi > pRaInfo->RssiStaRA + 5) ||
		    (pRaInfo->PTPreRssi < pRaInfo->RssiStaRA - 5) ||
		    (pRaInfo->DecisionRate != pRaInfo->PTPreRate)) {
			if (pRaInfo->PTStage == 0)
				pRaInfo->PTStage = 1;
			else if (pRaInfo->PTStage == 1)
				pRaInfo->PTStage = 3;
			else
				pRaInfo->PTStage = 5;

			pRaInfo->PTPreRssi = pRaInfo->RssiStaRA;
			pRaInfo->PTStopCount = 0;
		} else {
			pRaInfo->RAstage = 0;
			pRaInfo->PTStopCount++;
		}
	} else {
		pRaInfo->PTStage = 0;
		pRaInfo->RAstage = 0;
	}
	pRaInfo->PTPreRate = pRaInfo->DecisionRate;
}

__attribute__((used)) static void odm_PTDecision_8188E(struct odm_ra_info *pRaInfo)
{
	u8 j;
	u8 temp_stage;
	u32 numsc;
	u32 num_total;
	u8 stage_id;

	numsc  = 0;
	num_total = pRaInfo->TOTAL * PT_PENALTY[5];
	for (j = 0; j <= 4; j++) {
		numsc += pRaInfo->RTY[j] * PT_PENALTY[j];
		if (numsc > num_total)
			break;
	}

	j >>= 1;
	temp_stage = (pRaInfo->PTStage + 1) >> 1;
	if (temp_stage > j)
		stage_id = temp_stage-j;
	else
		stage_id = 0;

	pRaInfo->PTSmoothFactor = (pRaInfo->PTSmoothFactor>>1) + (pRaInfo->PTSmoothFactor>>2) + stage_id*16+2;
	if (pRaInfo->PTSmoothFactor > 192)
		pRaInfo->PTSmoothFactor = 192;
	stage_id = pRaInfo->PTSmoothFactor >> 6;
	temp_stage = stage_id*2;
	if (temp_stage != 0)
		temp_stage -= 1;
	if (pRaInfo->DROP > 3)
		temp_stage = 0;
	pRaInfo->PTStage = temp_stage;
}

__attribute__((used)) static void
odm_RATxRPTTimerSetting(
		struct odm_dm_struct *dm_odm,
		u16 minRptTime
)
{
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE, (" =====>odm_RATxRPTTimerSetting()\n"));

	if (dm_odm->CurrminRptTime != minRptTime) {
		ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
			     (" CurrminRptTime = 0x%04x minRptTime = 0x%04x\n", dm_odm->CurrminRptTime, minRptTime));
		rtw_rpt_timer_cfg_cmd(dm_odm->Adapter, minRptTime);
		dm_odm->CurrminRptTime = minRptTime;
	}
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE, (" <===== odm_RATxRPTTimerSetting()\n"));
}

int ODM_RAInfo_Init(struct odm_dm_struct *dm_odm, u8 macid)
{
	struct odm_ra_info *pRaInfo = &dm_odm->RAInfo[macid];
	u8 WirelessMode = 0xFF; /* invalid value */
	u8 max_rate_idx = 0x13; /* MCS7 */

	if (dm_odm->pWirelessMode)
		WirelessMode = *(dm_odm->pWirelessMode);

	if (WirelessMode != 0xFF) {
		if (WirelessMode & ODM_WM_N24G)
			max_rate_idx = 0x13;
		else if (WirelessMode & ODM_WM_G)
			max_rate_idx = 0x0b;
		else if (WirelessMode & ODM_WM_B)
			max_rate_idx = 0x03;
	}

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
		     ("ODM_RAInfo_Init(): WirelessMode:0x%08x , max_raid_idx:0x%02x\n",
		     WirelessMode, max_rate_idx));

	pRaInfo->DecisionRate = max_rate_idx;
	pRaInfo->PreRate = max_rate_idx;
	pRaInfo->HighestRate = max_rate_idx;
	pRaInfo->LowestRate = 0;
	pRaInfo->RateID = 0;
	pRaInfo->RateMask = 0xffffffff;
	pRaInfo->RssiStaRA = 0;
	pRaInfo->PreRssiStaRA = 0;
	pRaInfo->SGIEnable = 0;
	pRaInfo->RAUseRate = 0xffffffff;
	pRaInfo->NscDown = (N_THRESHOLD_HIGH[0x13]+N_THRESHOLD_LOW[0x13])/2;
	pRaInfo->NscUp = (N_THRESHOLD_HIGH[0x13]+N_THRESHOLD_LOW[0x13])/2;
	pRaInfo->RateSGI = 0;
	pRaInfo->Active = 1;	/* Active is not used at present. by page, 110819 */
	pRaInfo->RptTime = 0x927c;
	pRaInfo->DROP = 0;
	pRaInfo->RTY[0] = 0;
	pRaInfo->RTY[1] = 0;
	pRaInfo->RTY[2] = 0;
	pRaInfo->RTY[3] = 0;
	pRaInfo->RTY[4] = 0;
	pRaInfo->TOTAL = 0;
	pRaInfo->RAWaitingCounter = 0;
	pRaInfo->RAPendingCounter = 0;
	pRaInfo->PTActive = 1;   /*  Active when this STA is use */
	pRaInfo->PTTryState = 0;
	pRaInfo->PTStage = 5; /*  Need to fill into HW_PWR_STATUS */
	pRaInfo->PTSmoothFactor = 192;
	pRaInfo->PTStopCount = 0;
	pRaInfo->PTPreRate = 0;
	pRaInfo->PTPreRssi = 0;
	pRaInfo->PTModeSS = 0;
	pRaInfo->RAstage = 0;
	return 0;
}

int ODM_RAInfo_Init_all(struct odm_dm_struct *dm_odm)
{
	u8 macid = 0;

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD, ("=====>\n"));
	dm_odm->CurrminRptTime = 0;

	for (macid = 0; macid < ODM_ASSOCIATE_ENTRY_NUM; macid++)
		ODM_RAInfo_Init(dm_odm, macid);

	return 0;
}

u8 ODM_RA_GetShortGI_8188E(struct odm_dm_struct *dm_odm, u8 macid)
{
	if ((!dm_odm) || (macid >= ASSOCIATE_ENTRY_NUM))
		return 0;
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
		     ("macid =%d SGI =%d\n", macid, dm_odm->RAInfo[macid].RateSGI));
	return dm_odm->RAInfo[macid].RateSGI;
}

u8 ODM_RA_GetDecisionRate_8188E(struct odm_dm_struct *dm_odm, u8 macid)
{
	u8 DecisionRate = 0;

	if ((!dm_odm) || (macid >= ASSOCIATE_ENTRY_NUM))
		return 0;
	DecisionRate = dm_odm->RAInfo[macid].DecisionRate;
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
		(" macid =%d DecisionRate = 0x%x\n", macid, DecisionRate));
	return DecisionRate;
}

u8 ODM_RA_GetHwPwrStatus_8188E(struct odm_dm_struct *dm_odm, u8 macid)
{
	u8 PTStage = 5;

	if ((!dm_odm) || (macid >= ASSOCIATE_ENTRY_NUM))
		return 0;
	PTStage = dm_odm->RAInfo[macid].PTStage;
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
		     ("macid =%d PTStage = 0x%x\n", macid, PTStage));
	return PTStage;
}

void ODM_RA_UpdateRateInfo_8188E(struct odm_dm_struct *dm_odm, u8 macid, u8 RateID, u32 RateMask, u8 SGIEnable)
{
	struct odm_ra_info *pRaInfo = NULL;

	if ((!dm_odm) || (macid >= ASSOCIATE_ENTRY_NUM))
		return;
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
		     ("macid =%d RateID = 0x%x RateMask = 0x%x SGIEnable =%d\n",
		     macid, RateID, RateMask, SGIEnable));

	pRaInfo = &(dm_odm->RAInfo[macid]);
	pRaInfo->RateID = RateID;
	pRaInfo->RateMask = RateMask;
	pRaInfo->SGIEnable = SGIEnable;
	odm_ARFBRefresh_8188E(dm_odm, pRaInfo);
}

void ODM_RA_SetRSSI_8188E(struct odm_dm_struct *dm_odm, u8 macid, u8 Rssi)
{
	struct odm_ra_info *pRaInfo = NULL;

	if ((!dm_odm) || (macid >= ASSOCIATE_ENTRY_NUM))
		return;
	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_TRACE,
		     (" macid =%d Rssi =%d\n", macid, Rssi));

	pRaInfo = &(dm_odm->RAInfo[macid]);
	pRaInfo->RssiStaRA = Rssi;
}

void ODM_RA_Set_TxRPT_Time(struct odm_dm_struct *dm_odm, u16 minRptTime)
{
	struct adapter *adapt = dm_odm->Adapter;

	usb_write16(adapt, REG_TX_RPT_TIME, minRptTime);
}

void ODM_RA_TxRPT2Handle_8188E(struct odm_dm_struct *dm_odm, u8 *TxRPT_Buf, u16 TxRPT_Len, u32 macid_entry0, u32 macid_entry1)
{
	struct odm_ra_info *pRAInfo = NULL;
	u8 MacId = 0;
	u8 *pBuffer = NULL;
	u32 valid = 0, ItemNum = 0;
	u16 minRptTime = 0x927c;

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
		     ("=====>ODM_RA_TxRPT2Handle_8188E(): valid0 =%d valid1 =%d BufferLength =%d\n",
		     macid_entry0, macid_entry1, TxRPT_Len));

	ItemNum = TxRPT_Len >> 3;
	pBuffer = TxRPT_Buf;

	do {
		if (MacId >= ASSOCIATE_ENTRY_NUM)
			valid = 0;
		else if (MacId >= 32)
			valid = (1 << (MacId - 32)) & macid_entry1;
		else
			valid = (1 << MacId) & macid_entry0;

		pRAInfo = &(dm_odm->RAInfo[MacId]);
		if (valid) {
			pRAInfo->RTY[0] = (u16)GET_TX_REPORT_TYPE1_RERTY_0(pBuffer);
			pRAInfo->RTY[1] = (u16)GET_TX_REPORT_TYPE1_RERTY_1(pBuffer);
			pRAInfo->RTY[2] = (u16)GET_TX_REPORT_TYPE1_RERTY_2(pBuffer);
			pRAInfo->RTY[3] = (u16)GET_TX_REPORT_TYPE1_RERTY_3(pBuffer);
			pRAInfo->RTY[4] = (u16)GET_TX_REPORT_TYPE1_RERTY_4(pBuffer);
			pRAInfo->DROP =   (u16)GET_TX_REPORT_TYPE1_DROP_0(pBuffer);
			pRAInfo->TOTAL = pRAInfo->RTY[0] + pRAInfo->RTY[1] +
					 pRAInfo->RTY[2] + pRAInfo->RTY[3] +
					 pRAInfo->RTY[4] + pRAInfo->DROP;
			if (pRAInfo->TOTAL != 0) {
				ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD,
					     ("macid =%d Total =%d R0 =%d R1 =%d R2 =%d R3 =%d R4 =%d D0 =%d valid0 =%x valid1 =%x\n",
					     MacId, pRAInfo->TOTAL,
					     pRAInfo->RTY[0], pRAInfo->RTY[1],
					     pRAInfo->RTY[2], pRAInfo->RTY[3],
					     pRAInfo->RTY[4], pRAInfo->DROP,
					     macid_entry0, macid_entry1));
				if (pRAInfo->PTActive) {
					if (pRAInfo->RAstage < 5)
						odm_RateDecision_8188E(dm_odm, pRAInfo);
					else if (pRAInfo->RAstage == 5) /*  Power training try state */
						odm_PTTryState_8188E(pRAInfo);
					else /*  RAstage == 6 */
						odm_PTDecision_8188E(pRAInfo);

					/*  Stage_RA counter */
					if (pRAInfo->RAstage <= 5)
						pRAInfo->RAstage++;
					else
						pRAInfo->RAstage = 0;
				} else {
					odm_RateDecision_8188E(dm_odm, pRAInfo);
				}
				ODM_RT_TRACE(dm_odm, ODM_COMP_INIT, ODM_DBG_LOUD,
					     ("macid =%d R0 =%d R1 =%d R2 =%d R3 =%d R4 =%d drop =%d valid0 =%x RateID =%d SGI =%d\n",
					     MacId,
					     pRAInfo->RTY[0],
					     pRAInfo->RTY[1],
					     pRAInfo->RTY[2],
					     pRAInfo->RTY[3],
					     pRAInfo->RTY[4],
					     pRAInfo->DROP,
					     macid_entry0,
					     pRAInfo->DecisionRate,
					     pRAInfo->RateSGI));
			} else {
				ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD, (" TOTAL = 0!!!!\n"));
			}
		}

		if (minRptTime > pRAInfo->RptTime)
			minRptTime = pRAInfo->RptTime;

		pBuffer += TX_RPT2_ITEM_SIZE;
		MacId++;
	} while (MacId < ItemNum);

	odm_RATxRPTTimerSetting(dm_odm, minRptTime);

	ODM_RT_TRACE(dm_odm, ODM_COMP_RATE_ADAPTIVE, ODM_DBG_LOUD, ("<===== ODM_RA_TxRPT2Handle_8188E()\n"));
}

