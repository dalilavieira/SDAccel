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
struct sk_buff {int dummy; } ;
struct llc_sap_state_ev {scalar_t__ type; scalar_t__ prim_type; scalar_t__ prim; } ;
struct llc_sap {int dummy; } ;
struct llc_pdu_un {int dummy; } ;

/* Variables and functions */
 scalar_t__ LLC_1_PDU_CMD_TEST ; 
 scalar_t__ LLC_1_PDU_CMD_UI ; 
 scalar_t__ LLC_1_PDU_CMD_XID ; 
 scalar_t__ LLC_DATAUNIT_PRIM ; 
 scalar_t__ LLC_PDU_IS_CMD (struct llc_pdu_un*) ; 
 scalar_t__ LLC_PDU_IS_RSP (struct llc_pdu_un*) ; 
 scalar_t__ LLC_PDU_TYPE_IS_U (struct llc_pdu_un*) ; 
 scalar_t__ LLC_PRIM_TYPE_REQ ; 
 scalar_t__ LLC_SAP_EV_ACTIVATION_REQ ; 
 scalar_t__ LLC_SAP_EV_DEACTIVATION_REQ ; 
 scalar_t__ LLC_SAP_EV_TYPE_PDU ; 
 scalar_t__ LLC_SAP_EV_TYPE_PRIM ; 
 scalar_t__ LLC_SAP_EV_TYPE_SIMPLE ; 
 scalar_t__ LLC_TEST_PRIM ; 
 scalar_t__ LLC_U_PDU_CMD (struct llc_pdu_un*) ; 
 scalar_t__ LLC_U_PDU_RSP (struct llc_pdu_un*) ; 
 scalar_t__ LLC_XID_PRIM ; 
 struct llc_pdu_un* llc_pdu_un_hdr (struct sk_buff*) ; 
 struct llc_sap_state_ev* llc_sap_ev (struct sk_buff*) ; 

int llc_sap_ev_activation_req(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);

	return ev->type == LLC_SAP_EV_TYPE_SIMPLE &&
	       ev->prim_type == LLC_SAP_EV_ACTIVATION_REQ ? 0 : 1;
}

int llc_sap_ev_rx_ui(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);
	struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);

	return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_CMD(pdu) &&
	       LLC_PDU_TYPE_IS_U(pdu) &&
	       LLC_U_PDU_CMD(pdu) == LLC_1_PDU_CMD_UI ? 0 : 1;
}

int llc_sap_ev_unitdata_req(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);

	return ev->type == LLC_SAP_EV_TYPE_PRIM &&
	       ev->prim == LLC_DATAUNIT_PRIM &&
	       ev->prim_type == LLC_PRIM_TYPE_REQ ? 0 : 1;

}

int llc_sap_ev_xid_req(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);

	return ev->type == LLC_SAP_EV_TYPE_PRIM &&
	       ev->prim == LLC_XID_PRIM &&
	       ev->prim_type == LLC_PRIM_TYPE_REQ ? 0 : 1;
}

int llc_sap_ev_rx_xid_c(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);
	struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);

	return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_CMD(pdu) &&
	       LLC_PDU_TYPE_IS_U(pdu) &&
	       LLC_U_PDU_CMD(pdu) == LLC_1_PDU_CMD_XID ? 0 : 1;
}

int llc_sap_ev_rx_xid_r(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);
	struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);

	return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_RSP(pdu) &&
	       LLC_PDU_TYPE_IS_U(pdu) &&
	       LLC_U_PDU_RSP(pdu) == LLC_1_PDU_CMD_XID ? 0 : 1;
}

int llc_sap_ev_test_req(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);

	return ev->type == LLC_SAP_EV_TYPE_PRIM &&
	       ev->prim == LLC_TEST_PRIM &&
	       ev->prim_type == LLC_PRIM_TYPE_REQ ? 0 : 1;
}

int llc_sap_ev_rx_test_c(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);
	struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);

	return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_CMD(pdu) &&
	       LLC_PDU_TYPE_IS_U(pdu) &&
	       LLC_U_PDU_CMD(pdu) == LLC_1_PDU_CMD_TEST ? 0 : 1;
}

int llc_sap_ev_rx_test_r(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);
	struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);

	return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_RSP(pdu) &&
	       LLC_PDU_TYPE_IS_U(pdu) &&
	       LLC_U_PDU_RSP(pdu) == LLC_1_PDU_CMD_TEST ? 0 : 1;
}

int llc_sap_ev_deactivation_req(struct llc_sap *sap, struct sk_buff *skb)
{
	struct llc_sap_state_ev *ev = llc_sap_ev(skb);

	return ev->type == LLC_SAP_EV_TYPE_SIMPLE &&
	       ev->prim_type == LLC_SAP_EV_DEACTIVATION_REQ ? 0 : 1;
}

