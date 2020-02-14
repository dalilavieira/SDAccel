#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  void* u16 ;
struct sta_priv {int dummy; } ;
struct sta_info {int mac_id; } ;
struct signal_stat {int total_num; int total_val; int avg_val; scalar_t__ update_req; } ;
struct TYPE_14__ {scalar_t__ SignalQuality; scalar_t__ SignalStrength; } ;
struct rx_pkt_attrib {int crc_err; int pkt_rpt_type; int drvinfo_sz; int physt; int bdecrypted; int encrypt; int qos; int priority; int amsdu; int frag_num; int mfrag; int mdata; int mcs_rate; int rxht; int icv_err; int shift_sz; int* MacIDValidEntry; TYPE_6__ phy_info; void* pkt_len; void* seq_num; } ;
struct recv_stat {int /*<<< orphan*/  rxdw0; int /*<<< orphan*/  rxdw5; int /*<<< orphan*/  rxdw4; int /*<<< orphan*/  rxdw3; int /*<<< orphan*/  rxdw1; int /*<<< orphan*/  rxdw2; } ;
struct recv_frame {struct sta_info* psta; TYPE_1__* pkt; struct rx_pkt_attrib attrib; struct adapter* adapter; } ;
struct phy_stat {int dummy; } ;
struct odm_phy_status_info {int dummy; } ;
struct odm_per_pkt_info {int bPacketMatchBSSID; int bPacketToSelf; int bPacketBeacon; int StationID; int Rate; } ;
struct TYPE_10__ {int* MacAddress; } ;
struct TYPE_11__ {TYPE_2__ network; } ;
struct TYPE_15__ {TYPE_3__ cur_network; } ;
struct TYPE_13__ {struct signal_stat signal_qual_data; struct signal_stat signal_strength_data; } ;
struct adapter {TYPE_7__ mlmepriv; TYPE_4__* HalData; struct sta_priv stapriv; int /*<<< orphan*/  eeprompriv; TYPE_5__ recvpriv; } ;
struct TYPE_12__ {int /*<<< orphan*/  odmpriv; } ;
struct TYPE_9__ {int* data; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  ETH_ALEN ; 
 scalar_t__ GetFrameSubType (int*) ; 
 scalar_t__ HIS_REPORT ; 
 int /*<<< orphan*/  IsFrameTypeCtrl (int*) ; 
 scalar_t__ NORMAL_RX ; 
 int /*<<< orphan*/  ODM_PhyStatusQuery (int /*<<< orphan*/ *,struct odm_phy_status_info*,int*,struct odm_per_pkt_info*) ; 
 scalar_t__ TX_REPORT1 ; 
 scalar_t__ TX_REPORT2 ; 
 void* TX_RPT1_PKT_LEN ; 
 int WIFI_ADHOC_MASTER_STATE ; 
 int WIFI_ADHOC_STATE ; 
 int WIFI_AP_STATE ; 
 scalar_t__ WIFI_BEACON ; 
 int WIFI_STATION_STATE ; 
 scalar_t__ check_fwstate (TYPE_7__*,int) ; 
 int /*<<< orphan*/  get_bssid (TYPE_7__*) ; 
 int /*<<< orphan*/  get_da (int*) ; 
 int /*<<< orphan*/  get_hdr_bssid (int*) ; 
 int* get_sa (int*) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct rx_pkt_attrib*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  myid (int /*<<< orphan*/ *) ; 
 struct sta_info* rtw_get_stainfo (struct sta_priv*,int*) ; 

__attribute__((used)) static void process_rssi(struct adapter *padapter, struct recv_frame *prframe)
{
	struct rx_pkt_attrib *pattrib = &prframe->attrib;
	struct signal_stat *signal_stat = &padapter->recvpriv.signal_strength_data;

	if (signal_stat->update_req) {
		signal_stat->total_num = 0;
		signal_stat->total_val = 0;
		signal_stat->update_req = 0;
	}

	signal_stat->total_num++;
	signal_stat->total_val  += pattrib->phy_info.SignalStrength;
	signal_stat->avg_val = signal_stat->total_val / signal_stat->total_num;
}

__attribute__((used)) static void process_link_qual(struct adapter *padapter,
			      struct recv_frame *prframe)
{
	struct rx_pkt_attrib *pattrib;
	struct signal_stat *signal_stat;

	if (!prframe || !padapter)
		return;

	pattrib = &prframe->attrib;
	signal_stat = &padapter->recvpriv.signal_qual_data;

	if (signal_stat->update_req) {
		signal_stat->total_num = 0;
		signal_stat->total_val = 0;
		signal_stat->update_req = 0;
	}

	signal_stat->total_num++;
	signal_stat->total_val  += pattrib->phy_info.SignalQuality;
	signal_stat->avg_val = signal_stat->total_val / signal_stat->total_num;
}

void rtl8188e_process_phy_info(struct adapter *padapter,
			       struct recv_frame *precvframe)
{
	/*  Check RSSI */
	process_rssi(padapter, precvframe);
	/*  Check EVM */
	process_link_qual(padapter,  precvframe);
}

void update_recvframe_attrib_88e(struct recv_frame *precvframe,
				 struct recv_stat *prxstat)
{
	struct rx_pkt_attrib	*pattrib;
	struct recv_stat	report;

	report.rxdw0 = prxstat->rxdw0;
	report.rxdw1 = prxstat->rxdw1;
	report.rxdw2 = prxstat->rxdw2;
	report.rxdw3 = prxstat->rxdw3;
	report.rxdw4 = prxstat->rxdw4;
	report.rxdw5 = prxstat->rxdw5;

	pattrib = &precvframe->attrib;
	memset(pattrib, 0, sizeof(struct rx_pkt_attrib));

	pattrib->crc_err = (u8)((le32_to_cpu(report.rxdw0) >> 14) & 0x1);/* u8)prxreport->crc32; */

	/*  update rx report to recv_frame attribute */
	pattrib->pkt_rpt_type = (u8)((le32_to_cpu(report.rxdw3) >> 14) & 0x3);/* prxreport->rpt_sel; */

	if (pattrib->pkt_rpt_type == NORMAL_RX) { /* Normal rx packet */
		pattrib->pkt_len = (u16)(le32_to_cpu(report.rxdw0) & 0x00003fff);/* u16)prxreport->pktlen; */
		pattrib->drvinfo_sz = (u8)((le32_to_cpu(report.rxdw0) >> 16) & 0xf) * 8;/* u8)(prxreport->drvinfosize << 3); */

		pattrib->physt =  (u8)((le32_to_cpu(report.rxdw0) >> 26) & 0x1);/* u8)prxreport->physt; */

		pattrib->bdecrypted = (le32_to_cpu(report.rxdw0) & BIT(27)) ? 0 : 1;/* u8)(prxreport->swdec ? 0 : 1); */
		pattrib->encrypt = (u8)((le32_to_cpu(report.rxdw0) >> 20) & 0x7);/* u8)prxreport->security; */

		pattrib->qos = (u8)((le32_to_cpu(report.rxdw0) >> 23) & 0x1);/* u8)prxreport->qos; */
		pattrib->priority = (u8)((le32_to_cpu(report.rxdw1) >> 8) & 0xf);/* u8)prxreport->tid; */

		pattrib->amsdu = (u8)((le32_to_cpu(report.rxdw1) >> 13) & 0x1);/* u8)prxreport->amsdu; */

		pattrib->seq_num = (u16)(le32_to_cpu(report.rxdw2) & 0x00000fff);/* u16)prxreport->seq; */
		pattrib->frag_num = (u8)((le32_to_cpu(report.rxdw2) >> 12) & 0xf);/* u8)prxreport->frag; */
		pattrib->mfrag = (u8)((le32_to_cpu(report.rxdw1) >> 27) & 0x1);/* u8)prxreport->mf; */
		pattrib->mdata = (u8)((le32_to_cpu(report.rxdw1) >> 26) & 0x1);/* u8)prxreport->md; */

		pattrib->mcs_rate = (u8)(le32_to_cpu(report.rxdw3) & 0x3f);/* u8)prxreport->rxmcs; */
		pattrib->rxht = (u8)((le32_to_cpu(report.rxdw3) >> 6) & 0x1);/* u8)prxreport->rxht; */

		pattrib->icv_err = (u8)((le32_to_cpu(report.rxdw0) >> 15) & 0x1);/* u8)prxreport->icverr; */
		pattrib->shift_sz = (u8)((le32_to_cpu(report.rxdw0) >> 24) & 0x3);
	} else if (pattrib->pkt_rpt_type == TX_REPORT1) { /* CCX */
		pattrib->pkt_len = TX_RPT1_PKT_LEN;
		pattrib->drvinfo_sz = 0;
	} else if (pattrib->pkt_rpt_type == TX_REPORT2) { /*  TX RPT */
		pattrib->pkt_len = (u16)(le32_to_cpu(report.rxdw0) & 0x3FF);/* Rx length[9:0] */
		pattrib->drvinfo_sz = 0;

		/*  */
		/*  Get TX report MAC ID valid. */
		/*  */
		pattrib->MacIDValidEntry[0] = le32_to_cpu(report.rxdw4);
		pattrib->MacIDValidEntry[1] = le32_to_cpu(report.rxdw5);

	} else if (pattrib->pkt_rpt_type == HIS_REPORT) { /*  USB HISR RPT */
		pattrib->pkt_len = (u16)(le32_to_cpu(report.rxdw0) & 0x00003fff);/* u16)prxreport->pktlen; */
	}
}

void update_recvframe_phyinfo_88e(struct recv_frame *precvframe,
				  struct phy_stat *pphy_status)
{
	struct adapter *padapter = precvframe->adapter;
	struct rx_pkt_attrib *pattrib = &precvframe->attrib;
	struct odm_phy_status_info *pPHYInfo  = (struct odm_phy_status_info *)(&pattrib->phy_info);
	u8 *wlanhdr;
	struct odm_per_pkt_info	pkt_info;
	u8 *sa = NULL;
	struct sta_priv *pstapriv;
	struct sta_info *psta;

	pkt_info.bPacketMatchBSSID = false;
	pkt_info.bPacketToSelf = false;
	pkt_info.bPacketBeacon = false;

	wlanhdr = precvframe->pkt->data;

	pkt_info.bPacketMatchBSSID = ((!IsFrameTypeCtrl(wlanhdr)) &&
		!pattrib->icv_err && !pattrib->crc_err &&
		!memcmp(get_hdr_bssid(wlanhdr),
		 get_bssid(&padapter->mlmepriv), ETH_ALEN));

	pkt_info.bPacketToSelf = pkt_info.bPacketMatchBSSID &&
				 (!memcmp(get_da(wlanhdr),
				  myid(&padapter->eeprompriv), ETH_ALEN));

	pkt_info.bPacketBeacon = pkt_info.bPacketMatchBSSID &&
				 (GetFrameSubType(wlanhdr) == WIFI_BEACON);

	if (pkt_info.bPacketBeacon) {
		if (check_fwstate(&padapter->mlmepriv, WIFI_STATION_STATE))
			sa = padapter->mlmepriv.cur_network.network.MacAddress;
		/* to do Ad-hoc */
	} else {
		sa = get_sa(wlanhdr);
	}

	pstapriv = &padapter->stapriv;
	pkt_info.StationID = 0xFF;
	psta = rtw_get_stainfo(pstapriv, sa);
	if (psta)
		pkt_info.StationID = psta->mac_id;
	pkt_info.Rate = pattrib->mcs_rate;

	ODM_PhyStatusQuery(&padapter->HalData->odmpriv, pPHYInfo,
			   (u8 *)pphy_status, &(pkt_info));

	precvframe->psta = NULL;
	if (pkt_info.bPacketMatchBSSID &&
	    (check_fwstate(&padapter->mlmepriv, WIFI_AP_STATE))) {
		if (psta) {
			precvframe->psta = psta;
			rtl8188e_process_phy_info(padapter, precvframe);
		}
	} else if (pkt_info.bPacketToSelf || pkt_info.bPacketBeacon) {
		if (check_fwstate(&padapter->mlmepriv, WIFI_ADHOC_STATE|WIFI_ADHOC_MASTER_STATE)) {
			if (psta)
				precvframe->psta = psta;
		}
		rtl8188e_process_phy_info(padapter, precvframe);
	}
}

