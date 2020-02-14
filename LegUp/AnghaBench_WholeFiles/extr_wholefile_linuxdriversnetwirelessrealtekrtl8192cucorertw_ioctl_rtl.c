#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint ;
typedef  scalar_t__ u64 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct oid_par_priv {scalar_t__ type_of_oid; int information_buf_len; int* bytes_rw; int /*<<< orphan*/  adapter_context; scalar_t__ information_buf; } ;
struct TYPE_17__ {int DSConfig; } ;
struct TYPE_12__ {TYPE_8__ Configuration; } ;
struct TYPE_13__ {TYPE_3__ network; } ;
struct mlme_priv {TYPE_4__ cur_network; } ;
struct eeprom_priv {int /*<<< orphan*/  channel_plan; } ;
typedef  int /*<<< orphan*/  _irqL ;
typedef  int ULONG ;
struct TYPE_14__ {TYPE_8__ Configuration; } ;
struct TYPE_15__ {scalar_t__ preamble; TYPE_5__ dev_network; } ;
struct TYPE_11__ {int rx_smallpacket_crcerr; int rx_middlepacket_crcerr; int rx_largepacket_crcerr; scalar_t__ rx_bytes; int /*<<< orphan*/  rx_icv_err; scalar_t__ rx_drop; scalar_t__ rx_pkts; } ;
struct TYPE_10__ {scalar_t__ tx_bytes; } ;
struct TYPE_16__ {struct mlme_priv mlmepriv; TYPE_6__ registrypriv; TYPE_2__ recvpriv; TYPE_1__ xmitpriv; struct eeprom_priv eeprompriv; } ;
typedef  TYPE_7__* PADAPTER ;
typedef  int /*<<< orphan*/  NDIS_STATUS ;
typedef  TYPE_8__ NDIS_802_11_CONFIGURATION ;

/* Variables and functions */
 int ADHOCMODE ; 
 int ASSOCIATED ; 
 int CHECKINGSTATUS ; 
 int /*<<< orphan*/  LOWER ; 
 int /*<<< orphan*/  NDIS_STATUS_INVALID_LENGTH ; 
 int /*<<< orphan*/  NDIS_STATUS_NOT_ACCEPTED ; 
 int /*<<< orphan*/  NDIS_STATUS_SUCCESS ; 
 int NOTASSOCIATED ; 
 scalar_t__ PREAMBLE_AUTO ; 
 scalar_t__ PREAMBLE_LONG ; 
 scalar_t__ PREAMBLE_SHORT ; 
 scalar_t__ QUERY_OID ; 
 int /*<<< orphan*/  RAISE ; 
 scalar_t__ SET_OID ; 
 int /*<<< orphan*/  WIFI_ADHOC_MASTER_STATE ; 
 int /*<<< orphan*/  WIFI_ADHOC_STATE ; 
 int /*<<< orphan*/  _FW_LINKED ; 
 int /*<<< orphan*/  _FW_UNDER_LINKING ; 
 scalar_t__ _TRUE ; 
 int /*<<< orphan*/  _func_enter_ ; 
 int /*<<< orphan*/  _func_exit_ ; 
 int /*<<< orphan*/  _irqlevel_changed_ (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ check_fwstate (struct mlme_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtw_setrfreg_cmd (TYPE_7__*,unsigned char,unsigned long) ; 

NDIS_STATUS oid_rt_pro_set_fw_dig_state_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS		status = NDIS_STATUS_SUCCESS;
#if 0
	PADAPTER		Adapter = (PADAPTER)(poid_par_priv->adapter_context);
	_irqL			oldirql;
	
	_func_enter_;
	
	if(poid_par_priv->type_of_oid != SET_OID) 
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}
			
	_irqlevel_changed_(&oldirql,LOWER);
	if(poid_par_priv->information_buf_len >= sizeof(struct setdig_parm))
	{
		//DEBUG_ERR(("===> oid_rt_pro_set_fw_dig_state_hdl. type:0x%02x.\n",*((unsigned char*)poid_par_priv->information_buf )));	
		if(!rtw_setfwdig_cmd(Adapter,*((unsigned char*)poid_par_priv->information_buf )))			
		{
			status = NDIS_STATUS_NOT_ACCEPTED;
		}
		                   
	}
	else{
		status = NDIS_STATUS_NOT_ACCEPTED;
	}  
	_irqlevel_changed_(&oldirql,RAISE);
	_func_exit_;
#endif
	return status;
}

NDIS_STATUS oid_rt_pro_set_fw_ra_state_hdl(struct oid_par_priv* poid_par_priv)
{

	NDIS_STATUS		status = NDIS_STATUS_SUCCESS;
#if 0
	PADAPTER		Adapter = (PADAPTER)(poid_par_priv->adapter_context);
	_irqL			oldirql;
	
	_func_enter_;	
	if(poid_par_priv->type_of_oid != SET_OID) 
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}

					
	_irqlevel_changed_(&oldirql,LOWER);
	
	if(poid_par_priv->information_buf_len >= sizeof(struct setra_parm))
	{
		//DEBUG_ERR(("===> oid_rt_pro_set_fw_ra_state_hdl. type:0x%02x.\n",*((unsigned char*)poid_par_priv->information_buf )));	
		if(!rtw_setfwra_cmd(Adapter,*((unsigned char*)poid_par_priv->information_buf )))			
		{
			status = NDIS_STATUS_NOT_ACCEPTED;
		}
		                   
	}
	else{
		status = NDIS_STATUS_NOT_ACCEPTED;
	}  
	_irqlevel_changed_(&oldirql,RAISE);
	_func_exit_;
#endif
	return status;
}

NDIS_STATUS oid_rt_get_signal_quality_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	//DEBUG_ERR(("<**********************oid_rt_get_signal_quality_hdl \n"));
	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

#if 0
		if(pMgntInfo->mAssoc || pMgntInfo->mIbss)
		{
			ulInfo = pAdapter->RxStats.SignalQuality;
			*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;
		}
		else
		{
			ulInfo = 0xffffffff; // It stands for -1 in 4-byte integer.
		}
		break;
#endif

	return status;
}

NDIS_STATUS oid_rt_get_small_packet_crc_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		
		
	if(poid_par_priv->information_buf_len >=  sizeof(ULONG) )
	{		
		*(ULONG *)poid_par_priv->information_buf = padapter->recvpriv.rx_smallpacket_crcerr;
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;		
	}
	else
	{
		status = NDIS_STATUS_INVALID_LENGTH;
	}

	return status;
}

NDIS_STATUS oid_rt_get_middle_packet_crc_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	if(poid_par_priv->information_buf_len >=  sizeof(ULONG) )
	{		
		*(ULONG *)poid_par_priv->information_buf = padapter->recvpriv.rx_middlepacket_crcerr;
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;		
	}
	else
	{
		status = NDIS_STATUS_INVALID_LENGTH;
	}


	return status;
}

NDIS_STATUS oid_rt_get_large_packet_crc_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}	

	if(poid_par_priv->information_buf_len >=  sizeof(ULONG) )
	{		
		*(ULONG *)poid_par_priv->information_buf = padapter->recvpriv.rx_largepacket_crcerr;
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;		
	}
	else
	{
		status = NDIS_STATUS_INVALID_LENGTH;
	}


	return status;
}

NDIS_STATUS oid_rt_get_tx_retry_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_get_rx_retry_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		
	*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;
	return status;
}

NDIS_STATUS oid_rt_get_rx_total_packet_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS		status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}	
	if(poid_par_priv->information_buf_len >=  sizeof(ULONG) )
	{		
		*(u64 *)poid_par_priv->information_buf = padapter->recvpriv.rx_pkts + padapter->recvpriv.rx_drop;
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;		
	}
	else
	{
		status = NDIS_STATUS_INVALID_LENGTH;
	}


	return status;
}

NDIS_STATUS oid_rt_get_tx_beacon_ok_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_get_tx_beacon_err_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_get_rx_icv_err_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}
	if(poid_par_priv->information_buf_len>= sizeof(u32))
	{
		//_rtw_memcpy(*(uint *)poid_par_priv->information_buf,padapter->recvpriv.rx_icv_err,sizeof(u32));
		*(uint *)poid_par_priv->information_buf = padapter->recvpriv.rx_icv_err;
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;
	}
	else
	{
		status = NDIS_STATUS_INVALID_LENGTH ;
	}
	

	return status;
}

NDIS_STATUS oid_rt_set_encryption_algorithm_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != SET_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}	

	return status;
}

NDIS_STATUS oid_rt_get_preamble_mode_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);
	ULONG			preamblemode = 0 ;			
		
	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		
	if(poid_par_priv->information_buf_len>= sizeof(ULONG))
	{		
		if(padapter->registrypriv.preamble == PREAMBLE_LONG)
			preamblemode = 0;
		else if (padapter->registrypriv.preamble == PREAMBLE_AUTO)
			preamblemode = 1;
		else if (padapter->registrypriv.preamble == PREAMBLE_SHORT)
			preamblemode = 2;
		
			
		*(ULONG *)poid_par_priv->information_buf = preamblemode ;
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;
	}
	else
	{
		status = NDIS_STATUS_INVALID_LENGTH ;
	}
	return status;
}

NDIS_STATUS oid_rt_get_ap_ip_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_get_channelplan_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);
	struct eeprom_priv*	peeprompriv = &padapter->eeprompriv;	

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		
	*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;
	*(u16 *)poid_par_priv->information_buf = peeprompriv->channel_plan ;

	return status;
}

NDIS_STATUS oid_rt_set_channelplan_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);
	struct eeprom_priv*	peeprompriv = &padapter->eeprompriv;	
	
	if(poid_par_priv->type_of_oid != SET_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		
	
	peeprompriv->channel_plan = *(u16 *)poid_par_priv->information_buf ;

	return status;
}

NDIS_STATUS oid_rt_set_preamble_mode_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);
	ULONG			preamblemode = 0;
	if(poid_par_priv->type_of_oid != SET_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}
	 
	if(poid_par_priv->information_buf_len>= sizeof(ULONG))
	{		
		preamblemode = *(ULONG *)poid_par_priv->information_buf ;
		if( preamblemode == 0)
			padapter->registrypriv.preamble = PREAMBLE_LONG;
		else if (preamblemode==1 )
			padapter->registrypriv.preamble = PREAMBLE_AUTO;
		else if ( preamblemode==2 )
			padapter->registrypriv.preamble = PREAMBLE_SHORT;		
			
		*(ULONG *)poid_par_priv->information_buf = preamblemode ;
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;
	}
	else
	{
		status = NDIS_STATUS_INVALID_LENGTH ;
	}	

	return status;
}

NDIS_STATUS oid_rt_set_bcn_intvl_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != SET_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}

	return status;
}

NDIS_STATUS oid_rt_dedicate_probe_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	return status;
}

NDIS_STATUS oid_rt_get_total_tx_bytes_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}	
	if(poid_par_priv->information_buf_len>= sizeof(ULONG))
	{		
		*(u64 *)poid_par_priv->information_buf = padapter->xmitpriv.tx_bytes;
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;
	}
	else
	{
		status = NDIS_STATUS_INVALID_LENGTH ;
	}
	

	return status;
}

NDIS_STATUS oid_rt_get_total_rx_bytes_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS		status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}
	if(poid_par_priv->information_buf_len>= sizeof(ULONG))
	{
		//_rtw_memcpy(*(uint *)poid_par_priv->information_buf,padapter->recvpriv.rx_icv_err,sizeof(u32));
		*(u64 *)poid_par_priv->information_buf = padapter->recvpriv.rx_bytes;
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;
	}
	else
	{
		status = NDIS_STATUS_INVALID_LENGTH ;
	}
	return status;
}

NDIS_STATUS oid_rt_current_tx_power_level_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	return status;
}

NDIS_STATUS oid_rt_get_enc_key_mismatch_count_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_get_enc_key_match_count_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_get_channel_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);
	struct	mlme_priv	*pmlmepriv = &padapter->mlmepriv;
	NDIS_802_11_CONFIGURATION		*pnic_Config;

	ULONG   channelnum;

	_func_enter_;
	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	if ( (check_fwstate(pmlmepriv, _FW_LINKED) == _TRUE) ||
		(check_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE) == _TRUE))
		pnic_Config = &pmlmepriv->cur_network.network.Configuration;
	else
		pnic_Config = &padapter->registrypriv.dev_network.Configuration;

	channelnum = pnic_Config->DSConfig;
	*(ULONG *)poid_par_priv->information_buf = channelnum;
	
	*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;

	_func_exit_;



	return status;
}

NDIS_STATUS oid_rt_get_hardware_radio_off_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_get_key_mismatch_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_supported_wireless_mode_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);
	ULONG 			ulInfo = 0 ;
	//DEBUG_ERR(("<**********************oid_rt_supported_wireless_mode_hdl \n"));	
	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		
	if(poid_par_priv->information_buf_len >= sizeof(ULONG)){
		ulInfo |= 0x0100; //WIRELESS_MODE_B
		ulInfo |= 0x0200; //WIRELESS_MODE_G
		ulInfo |= 0x0400; //WIRELESS_MODE_A

		*(ULONG *) poid_par_priv->information_buf = ulInfo;		
		//DEBUG_ERR(("<===oid_rt_supported_wireless_mode %x\n",ulInfo));	
		*poid_par_priv->bytes_rw = poid_par_priv->information_buf_len;
	}
	else{
		status = NDIS_STATUS_INVALID_LENGTH;
	}		

	return status;
}

NDIS_STATUS oid_rt_get_channel_list_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_get_scan_in_progress_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_forced_data_rate_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	return status;
}

NDIS_STATUS oid_rt_wireless_mode_for_scan_list_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	return status;
}

NDIS_STATUS oid_rt_get_bss_wireless_mode_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_scan_with_magic_packet_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	return status;
}

NDIS_STATUS oid_rt_ap_get_associated_station_list_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_ap_switch_into_ap_mode_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	return status;
}

NDIS_STATUS oid_rt_ap_supported_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	return status;
}

NDIS_STATUS oid_rt_ap_set_passphrase_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != SET_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	return status;
}

NDIS_STATUS oid_rt_pro_rf_write_registry_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS		status = NDIS_STATUS_SUCCESS;
	PADAPTER		Adapter = (PADAPTER)(poid_par_priv->adapter_context);
	_irqL			oldirql;
	_func_enter_;
	//DEBUG_ERR(("<**********************oid_rt_pro_rf_write_registry_hdl \n"));
	if(poid_par_priv->type_of_oid != SET_OID) //QUERY_OID
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}
	
	_irqlevel_changed_(&oldirql,LOWER);
	if(poid_par_priv->information_buf_len== (sizeof(unsigned long)*3))
	{      
		//RegOffsetValue	- The offset of RF register to write.
		//RegDataWidth	- The data width of RF register to write.
		//RegDataValue	- The value to write. 
		//RegOffsetValue = *((unsigned long*)InformationBuffer);
		//RegDataWidth = *((unsigned long*)InformationBuffer+1);	   
		//RegDataValue =  *((unsigned long*)InformationBuffer+2);	
		if(!rtw_setrfreg_cmd(Adapter, 
						*(unsigned char*)poid_par_priv->information_buf, 
						(unsigned long)(*((unsigned long*)poid_par_priv->information_buf+2))))
		{
			status = NDIS_STATUS_NOT_ACCEPTED;
		}
	                   
	}
	else{
		status = NDIS_STATUS_INVALID_LENGTH;
	}   
	_irqlevel_changed_(&oldirql,RAISE);
	_func_exit_;

	return status;
}

NDIS_STATUS oid_rt_pro_rf_read_registry_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS		status = NDIS_STATUS_SUCCESS;
#if 0
	PADAPTER		Adapter = (PADAPTER)(poid_par_priv->adapter_context);
	_irqL	oldirql;
	_func_enter_;

	//DEBUG_ERR(("<**********************oid_rt_pro_rf_read_registry_hdl \n"));
	if(poid_par_priv->type_of_oid != SET_OID) //QUERY_OID
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}	
	
	_irqlevel_changed_(&oldirql,LOWER);
	if(poid_par_priv->information_buf_len== (sizeof(unsigned long)*3))
	{
		if(Adapter->mppriv.act_in_progress == _TRUE)
		{
			status = NDIS_STATUS_NOT_ACCEPTED;
		}
		else
		{
			//init workparam
			Adapter->mppriv.act_in_progress = _TRUE;
			Adapter->mppriv.workparam.bcompleted= _FALSE;
			Adapter->mppriv.workparam.act_type = MPT_READ_RF;
			Adapter->mppriv.workparam.io_offset = *(unsigned long*)poid_par_priv->information_buf;		
			Adapter->mppriv.workparam.io_value = 0xcccccccc;
				       
			//RegOffsetValue	- The offset of RF register to read.
			//RegDataWidth	- The data width of RF register to read.
			//RegDataValue	- The value to read. 
			//RegOffsetValue = *((unsigned long*)InformationBuffer);
			//RegDataWidth = *((unsigned long*)InformationBuffer+1);	   
			//RegDataValue =  *((unsigned long*)InformationBuffer+2);	   	 	                   
			if(!rtw_getrfreg_cmd(Adapter, 
							*(unsigned char*)poid_par_priv->information_buf, 
							(unsigned char*)&Adapter->mppriv.workparam.io_value))
			{
				status = NDIS_STATUS_NOT_ACCEPTED;
			}
		}
				      		   
		                   
	}
	else	{
		status = NDIS_STATUS_INVALID_LENGTH;
	}
	_irqlevel_changed_(&oldirql,RAISE);
	_func_exit_;
#endif
	return status;
}

NDIS_STATUS oid_rt_get_connect_state_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS		status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	struct mlme_priv	*pmlmepriv = &(padapter->mlmepriv);

	ULONG ulInfo;
		
	if(poid_par_priv->type_of_oid != QUERY_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}		

	// nStatus==0	CheckingStatus
	// nStatus==1	Associated
	// nStatus==2	AdHocMode
	// nStatus==3	NotAssociated
	
	if(check_fwstate(pmlmepriv, _FW_UNDER_LINKING) == _TRUE)
		ulInfo = CHECKINGSTATUS;
	else if(check_fwstate(pmlmepriv, _FW_LINKED) == _TRUE)	
		ulInfo = ASSOCIATED;
	else if(check_fwstate(pmlmepriv, WIFI_ADHOC_STATE)== _TRUE)
		ulInfo = ADHOCMODE;
	else
		ulInfo = NOTASSOCIATED ;

	*(ULONG *)poid_par_priv->information_buf = ulInfo;
	*poid_par_priv->bytes_rw =  poid_par_priv->information_buf_len;

#if 0
	// Rearrange the order to let the UI still shows connection when scan is in progress
	RT_TRACE(COMP_OID_QUERY, DBG_LOUD, ("===> Query OID_RT_GET_CONNECT_STATE.\n"));
	if(pMgntInfo->mAssoc)
		ulInfo = 1;
	else if(pMgntInfo->mIbss)
		ulInfo = 2;
	else if(pMgntInfo->bScanInProgress)
		ulInfo = 0;
	else
		ulInfo = 3;
	ulInfoLen = sizeof(ULONG);
	RT_TRACE(COMP_OID_QUERY, DBG_LOUD, ("<=== Query OID_RT_GET_CONNECT_STATE: %d\n", ulInfo));
#endif

	return status;
}

NDIS_STATUS oid_rt_set_default_key_id_hdl(struct oid_par_priv* poid_par_priv)
{
	NDIS_STATUS	 	status = NDIS_STATUS_SUCCESS;
	PADAPTER		padapter = (PADAPTER)(poid_par_priv->adapter_context);

	if(poid_par_priv->type_of_oid != SET_OID)
	{
		status = NDIS_STATUS_NOT_ACCEPTED;
		return status;
	}
	
	return status;
}

