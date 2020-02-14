#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct mlme_priv {int dummy; } ;
typedef  int /*<<< orphan*/  s8 ;
struct TYPE_9__ {int asoc_sta_count; } ;
struct TYPE_10__ {TYPE_1__ stapriv; struct mlme_priv mlmepriv; } ;
typedef  TYPE_2__ _adapter ;

/* Variables and functions */
 int WIFI_ADHOC_MASTER_STATE ; 
 int WIFI_ADHOC_STATE ; 
 int WIFI_AP_STATE ; 
 int _FALSE ; 
 int _FW_LINKED ; 
 int _TRUE ; 
 int check_fwstate (struct mlme_priv*,int) ; 

bool rtw_adapter_linked(_adapter *adapter)
{
	bool linked = _FALSE;
	struct mlme_priv	*mlmepriv = &adapter->mlmepriv;

	if(	(check_fwstate(mlmepriv, WIFI_AP_STATE) == _TRUE) ||
		(check_fwstate(mlmepriv, WIFI_ADHOC_STATE|WIFI_ADHOC_MASTER_STATE) == _TRUE))
	{				
		if(adapter->stapriv.asoc_sta_count > 2)
			linked = _TRUE;
	}
	else{//Station mode
		if(check_fwstate(mlmepriv, _FW_LINKED)== _TRUE)
			linked = _TRUE;
	}

	return linked;
}

bool dm_linked(_adapter *adapter)
{
	bool linked;

	if ((linked = rtw_adapter_linked(adapter)))
		goto exit;

#ifdef CONFIG_CONCURRENT_MODE
	if ((adapter =  adapter->pbuddy_adapter) == NULL)
		goto exit;
	linked = rtw_adapter_linked(adapter);
#endif

exit:
	return linked;
}

int dm_adaptivity_get_parm_str(_adapter *pAdapter, char *buf, int len)
{
#ifdef CONFIG_DM_ADAPTIVITY
	HAL_DATA_TYPE *pHalData = GET_HAL_DATA(pAdapter);
	struct dm_priv *dmpriv = &pHalData->dmpriv;

	return snprintf(buf, len, DM_ADAPTIVITY_VER"\n"
		"TH_L2H_ini\tTH_EDCCA_HL_diff\tIGI_Base\tForceEDCCA\tAdapEn_RSSI\tIGI_LowerBound\n"
		"0x%02x\t%d\t0x%02x\t%d\t%u\t%u\n",
		(u8)dmpriv->TH_L2H_ini,
		dmpriv->TH_EDCCA_HL_diff,
		dmpriv->IGI_Base,
		dmpriv->ForceEDCCA,
		dmpriv->AdapEn_RSSI,
		dmpriv->IGI_LowerBound
	);
#endif /* CONFIG_DM_ADAPTIVITY */
	return 0;
}

void dm_adaptivity_set_parm(_adapter *pAdapter, s8 TH_L2H_ini, s8 TH_EDCCA_HL_diff,
	s8 IGI_Base, bool ForceEDCCA, u8 AdapEn_RSSI, u8 IGI_LowerBound)
{
#ifdef CONFIG_DM_ADAPTIVITY
	HAL_DATA_TYPE *pHalData = GET_HAL_DATA(pAdapter);
	struct dm_priv *dmpriv = &pHalData->dmpriv;

	dmpriv->TH_L2H_ini = TH_L2H_ini;
	dmpriv->TH_EDCCA_HL_diff = TH_EDCCA_HL_diff;
	dmpriv->IGI_Base = IGI_Base;
	dmpriv->ForceEDCCA = ForceEDCCA;
	dmpriv->AdapEn_RSSI = AdapEn_RSSI;
	dmpriv->IGI_LowerBound = IGI_LowerBound;

#endif /* CONFIG_DM_ADAPTIVITY */
}

void dm_adaptivity_init(_adapter *pAdapter)
{
#ifdef CONFIG_DM_ADAPTIVITY
	HAL_DATA_TYPE *pHalData = GET_HAL_DATA(pAdapter);
	struct dm_priv *dmpriv = &pHalData->dmpriv;

	/*
	if(pDM_Odm->SupportICType == ODM_RTL8723B)
	{
		pDM_Odm->TH_L2H_ini = 0xf8; // -8
	}
	if((pDM_Odm->SupportICType == ODM_RTL8192E)&&(pDM_Odm->SupportInterface == ODM_ITRF_PCIE))
	{
		pDM_Odm->TH_L2H_ini = 0xf0; // -16
	}
	else */
	{
		dmpriv->TH_L2H_ini = 0xf9; // -7
	}

	dmpriv->TH_EDCCA_HL_diff = 7;
	dmpriv->IGI_Base = 0x32;
	dmpriv->IGI_target = 0x1c;
	dmpriv->ForceEDCCA = 0;
	dmpriv->AdapEn_RSSI = 20;
	dmpriv->IGI_LowerBound = 0;

	//Reg524[11]=0 is easily to transmit packets during adaptivity test
	PHY_SetBBReg(pAdapter, 0x524, BIT11, 1); // stop counting if EDCCA is asserted

#endif /* CONFIG_DM_ADAPTIVITY */
}

void dm_adaptivity(_adapter *pAdapter)
{
#ifdef CONFIG_DM_ADAPTIVITY
	s8 TH_L2H_dmc, TH_H2L_dmc;
	s8 TH_L2H, TH_H2L, Diff, IGI_target;
	u32 value32;
	BOOLEAN EDCCA_State;

	HAL_DATA_TYPE *pHalData = GET_HAL_DATA(pAdapter);
	struct dm_priv *dmpriv = &pHalData->dmpriv;
	DIG_T *pDigTable = &dmpriv->DM_DigTable;
	u8 IGI = pDigTable->CurIGValue;
	u8 RSSI_Min = pDigTable->Rssi_val_min;
	HT_CHANNEL_WIDTH BandWidth = pHalData->CurrentChannelBW;

	if (!(dmpriv->DMFlag & DYNAMIC_FUNC_ADAPTIVITY))
	{
		LOG_LEVEL(_drv_info_, "Go to odm_DynamicEDCCA() \n");
		// Add by Neil Chen to enable edcca to MP Platform 
		// Adjust EDCCA.
		/*if(pDM_Odm->SupportICType & ODM_IC_11N_SERIES)
			dm_dynamic_EDCCA(pAdapter);
		*/
		return;
	}
	LOG_LEVEL(_drv_info_, "odm_Adaptivity() =====> \n");

	LOG_LEVEL(_drv_info_, "ForceEDCCA=%d, IGI_Base=0x%x, TH_L2H_ini = %d, TH_EDCCA_HL_diff = %d, AdapEn_RSSI = %d\n", 
		dmpriv->ForceEDCCA, dmpriv->IGI_Base, dmpriv->TH_L2H_ini, dmpriv->TH_EDCCA_HL_diff, dmpriv->AdapEn_RSSI);

	/*if(pDM_Odm->SupportICType & ODM_IC_11AC_SERIES)
		PHY_SetBBReg(0x800, BIT10, 0); //ADC_mask enable
	*/
	
	if(!dm_linked(pAdapter) || pHalData->CurrentChannel > 149) /* Band4 doesn't need adaptivity */
	{
		/*if(pDM_Odm->SupportICType & ODM_IC_11N_SERIES)*/
		{
			PHY_SetBBReg(pAdapter,rOFDM0_ECCAThreshold, bMaskByte0, 0x7f);
			PHY_SetBBReg(pAdapter,rOFDM0_ECCAThreshold, bMaskByte2, 0x7f);
		}
		/*else
		{
			ODM_SetBBReg(pDM_Odm, rFPGA0_XB_LSSIReadBack, 0xFFFF, (0x7f<<8) | 0x7f);
		}*/
		return;
	}

	if(!dmpriv->ForceEDCCA)
	{
		if(RSSI_Min > dmpriv->AdapEn_RSSI)
			EDCCA_State = 1;
		else if(RSSI_Min < (dmpriv->AdapEn_RSSI - 5))
			EDCCA_State = 0;
	}
	else
		EDCCA_State = 1;
	//if((pDM_Odm->SupportICType & ODM_IC_11AC_SERIES) && (*pDM_Odm->pBandType == BAND_ON_5G))
		//IGI_target = pDM_Odm->IGI_Base;
	//else
	{

		if(BandWidth == HT_CHANNEL_WIDTH_20) //CHANNEL_WIDTH_20
			IGI_target = dmpriv->IGI_Base;
		else if(BandWidth == HT_CHANNEL_WIDTH_40)
			IGI_target = dmpriv->IGI_Base + 2;
		/*else if(*pDM_Odm->pBandWidth == ODM_BW80M)
			IGI_target = pDM_Odm->IGI_Base + 6;*/
		else
			IGI_target = dmpriv->IGI_Base;
	}

	dmpriv->IGI_target = (u8)IGI_target;

	LOG_LEVEL(_drv_info_, "BandWidth=%s, IGI_target=0x%x, EDCCA_State=%d\n",
		(BandWidth==HT_CHANNEL_WIDTH_40)?"40M":"20M", IGI_target, EDCCA_State);

	if(EDCCA_State == 1)
	{
		Diff = IGI_target -(s8)IGI;
		TH_L2H_dmc = dmpriv->TH_L2H_ini + Diff;
		if(TH_L2H_dmc > 10) 	TH_L2H_dmc = 10;
		TH_H2L_dmc = TH_L2H_dmc - dmpriv->TH_EDCCA_HL_diff;
	}
	else
	{
		TH_L2H_dmc = 0x7f;
		TH_H2L_dmc = 0x7f;
	}

	LOG_LEVEL(_drv_info_, "IGI=0x%x, TH_L2H_dmc = %d, TH_H2L_dmc = %d\n", 
		IGI, TH_L2H_dmc, TH_H2L_dmc);

	/*if(pDM_Odm->SupportICType & ODM_IC_11N_SERIES)*/
	{
		PHY_SetBBReg(pAdapter,rOFDM0_ECCAThreshold, bMaskByte0, (u8)TH_L2H_dmc);
		PHY_SetBBReg(pAdapter,rOFDM0_ECCAThreshold, bMaskByte2, (u8)TH_H2L_dmc);
	}
	/*else
		PHY_SetBBReg(pAdapter, rFPGA0_XB_LSSIReadBack, 0xFFFF, ((u8)TH_H2L_dmc<<8) | (u8)TH_L2H_dmc);*/

skip_dm:
	return;
#endif /* CONFIG_DM_ADAPTIVITY */
}

