#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  void* u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_8__ {int total_pkt_len; } ;
struct TYPE_14__ {int tcp_payload_len; TYPE_1__ pkt_len; } ;
struct TYPE_12__ {int own_bit; int buf1_size; int tcp_hdr_len; int vlan_tag_ctl; int last_desc; int int_on_com; int timestmp_enable; int /*<<< orphan*/  cksum_ctl; TYPE_7__ tx_pkt_len; void* first_desc; void* tse_bit; } ;
struct TYPE_13__ {TYPE_5__ tx_rd_des23; } ;
struct sxgbe_tx_norm_desc {TYPE_6__ tdes23; } ;
struct sxgbe_tx_ctxt_desc {int ctxt_bit; int own_bit; int maxseg_size; int tcmssv; int ivlan_tag_valid; int ivlan_tag; int ivlan_tag_ctl; int vltag_valid; int vlan_tag; int tstamp_lo; int tstamp_hi; int ctxt_desc_err; void* ostc; } ;
struct TYPE_10__ {int pkt_len; int first_desc; int last_desc; int err_l2_type; int layer34_pkt_type; scalar_t__ l4_filter_match; scalar_t__ l3_filter_match; scalar_t__ hash_filter_pass; scalar_t__ da_filter_fail; scalar_t__ sa_filter_fail; scalar_t__ vlan_filter_match; scalar_t__ err_summary; } ;
struct TYPE_9__ {int own_bit; int int_on_com; } ;
struct TYPE_11__ {TYPE_3__ rx_wb_des23; TYPE_2__ rx_rd_des23; } ;
struct sxgbe_rx_norm_desc {TYPE_4__ rdes23; } ;
struct sxgbe_rx_ctxt_desc {int own_bit; scalar_t__ ptp_msgtype; int tstamp_hi; int tstamp_lo; int tstamp_available; scalar_t__ tstamp_dropped; } ;
struct sxgbe_extra_stats {int /*<<< orphan*/  rx_ptp_resv_msg_type; int /*<<< orphan*/  rx_ptp_signal; int /*<<< orphan*/  rx_ptp_mgmt; int /*<<< orphan*/  rx_ptp_announce; int /*<<< orphan*/  rx_ptp_type_pdelay_follow_up; int /*<<< orphan*/  rx_ptp_type_pdelay_resp; int /*<<< orphan*/  rx_ptp_type_pdelay_req; int /*<<< orphan*/  rx_ptp_type_delay_resp; int /*<<< orphan*/  rx_ptp_type_delay_req; int /*<<< orphan*/  rx_ptp_type_follow_up; int /*<<< orphan*/  rx_ptp_type_sync; int /*<<< orphan*/  rx_msg_type_no_ptp; int /*<<< orphan*/  timestamp_dropped; int /*<<< orphan*/  l4_filter_match; int /*<<< orphan*/  l3_filter_match; int /*<<< orphan*/  hash_filter_pass; int /*<<< orphan*/  da_filter_fail; int /*<<< orphan*/  sa_filter_fail; int /*<<< orphan*/  vlan_filter_match; int /*<<< orphan*/  ip6_unknown_pkt; int /*<<< orphan*/  ip6_icmp_pkt; int /*<<< orphan*/  ip6_udp_pkt; int /*<<< orphan*/  ip6_tcp_pkt; int /*<<< orphan*/  ip4_unknown_pkt; int /*<<< orphan*/  ip4_icmp_pkt; int /*<<< orphan*/  ip4_udp_pkt; int /*<<< orphan*/  ip4_tcp_pkt; int /*<<< orphan*/  not_ip_pkt; int /*<<< orphan*/  dvlan_ocvlan_icvlan_pkt; int /*<<< orphan*/  dvlan_osvlan_icvlan_pkt; int /*<<< orphan*/  dvlan_osvlan_isvlan_pkt; int /*<<< orphan*/  cvlan_tag_pkt; int /*<<< orphan*/  svlan_tag_pkt; int /*<<< orphan*/  other_pkt; int /*<<< orphan*/  untag_okt; int /*<<< orphan*/  oam_pkt; int /*<<< orphan*/  arp_pkt; int /*<<< orphan*/  dcb_ctl_pkt; int /*<<< orphan*/  mac_ctl_pkt; int /*<<< orphan*/  len_pkt; int /*<<< orphan*/  overflow_error; int /*<<< orphan*/  ip_payload_err; int /*<<< orphan*/  ip_hdr_err; int /*<<< orphan*/  rx_gaint_pkt_err; int /*<<< orphan*/  rx_crc_err; int /*<<< orphan*/  rx_watchdog_err; int /*<<< orphan*/  rx_code_gmii_err; } ;
struct sxgbe_desc_ops {int dummy; } ;

/* Variables and functions */
 int CHECKSUM_NONE ; 
 int CHECKSUM_UNNECESSARY ; 
 int EINVAL ; 
#define  RX_ARP_PKT 156 
#define  RX_CRC_ERR 155 
#define  RX_CVLAN_PKT 154 
#define  RX_DCBCTL_PKT 153 
#define  RX_DVLAN_OCVLAN_ICVLAN_PKT 152 
#define  RX_DVLAN_OCVLAN_ISVLAN_PKT 151 
#define  RX_DVLAN_OSVLAN_ICVLAN_PKT 150 
#define  RX_DVLAN_OSVLAN_ISVLAN_PKT 149 
#define  RX_GAINT_ERR 148 
#define  RX_GMII_ERR 147 
#define  RX_IPV4_ICMP_PKT 146 
#define  RX_IPV4_TCP_PKT 145 
#define  RX_IPV4_UDP_PKT 144 
#define  RX_IPV4_UNKNOWN_PKT 143 
#define  RX_IPV6_ICMP_PKT 142 
#define  RX_IPV6_TCP_PKT 141 
#define  RX_IPV6_UDP_PKT 140 
#define  RX_IPV6_UNKNOWN_PKT 139 
#define  RX_IP_HDR_ERR 138 
#define  RX_LEN_PKT 137 
#define  RX_MACCTL_PKT 136 
#define  RX_NOT_IP_PKT 135 
 scalar_t__ RX_NO_PTP ; 
#define  RX_OAM_PKT 134 
#define  RX_OTHER_PKT 133 
#define  RX_OVERFLOW_ERR 132 
#define  RX_PAYLOAD_ERR 131 
 scalar_t__ RX_PTP_ANNOUNCE ; 
 scalar_t__ RX_PTP_DELAY_REQ ; 
 scalar_t__ RX_PTP_DELAY_RESP ; 
 scalar_t__ RX_PTP_FOLLOW_UP ; 
 scalar_t__ RX_PTP_MGMT ; 
 scalar_t__ RX_PTP_PDELAY_FOLLOW_UP ; 
 scalar_t__ RX_PTP_PDELAY_REQ ; 
 scalar_t__ RX_PTP_PDELAY_RESP ; 
 scalar_t__ RX_PTP_RESV_MSG ; 
 scalar_t__ RX_PTP_SIGNAL ; 
 scalar_t__ RX_PTP_SYNC ; 
#define  RX_SVLAN_PKT 130 
#define  RX_UNTAG_PKT 129 
#define  RX_WATCHDOG_ERR 128 
 int /*<<< orphan*/  cic_full ; 
 struct sxgbe_desc_ops const desc_ops ; 
 int /*<<< orphan*/  memset (struct sxgbe_tx_norm_desc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 

__attribute__((used)) static void sxgbe_init_tx_desc(struct sxgbe_tx_norm_desc *p)
{
	p->tdes23.tx_rd_des23.own_bit = 0;
}

__attribute__((used)) static void sxgbe_tx_desc_enable_tse(struct sxgbe_tx_norm_desc *p, u8 is_tse,
				     u32 total_hdr_len, u32 tcp_hdr_len,
				     u32 tcp_payload_len)
{
	p->tdes23.tx_rd_des23.tse_bit = is_tse;
	p->tdes23.tx_rd_des23.buf1_size = total_hdr_len;
	p->tdes23.tx_rd_des23.tcp_hdr_len = tcp_hdr_len / 4;
	p->tdes23.tx_rd_des23.tx_pkt_len.tcp_payload_len  = tcp_payload_len;
}

__attribute__((used)) static void sxgbe_prepare_tx_desc(struct sxgbe_tx_norm_desc *p, u8 is_fd,
				  int buf1_len, int pkt_len, int cksum)
{
	p->tdes23.tx_rd_des23.first_desc = is_fd;
	p->tdes23.tx_rd_des23.buf1_size = buf1_len;

	p->tdes23.tx_rd_des23.tx_pkt_len.pkt_len.total_pkt_len = pkt_len;

	if (cksum)
		p->tdes23.tx_rd_des23.cksum_ctl = cic_full;
}

__attribute__((used)) static void sxgbe_tx_vlanctl_desc(struct sxgbe_tx_norm_desc *p, int vlan_ctl)
{
	p->tdes23.tx_rd_des23.vlan_tag_ctl = vlan_ctl;
}

__attribute__((used)) static void sxgbe_set_tx_owner(struct sxgbe_tx_norm_desc *p)
{
	p->tdes23.tx_rd_des23.own_bit = 1;
}

__attribute__((used)) static int sxgbe_get_tx_owner(struct sxgbe_tx_norm_desc *p)
{
	return p->tdes23.tx_rd_des23.own_bit;
}

__attribute__((used)) static void sxgbe_close_tx_desc(struct sxgbe_tx_norm_desc *p)
{
	p->tdes23.tx_rd_des23.last_desc = 1;
	p->tdes23.tx_rd_des23.int_on_com = 1;
}

__attribute__((used)) static void sxgbe_release_tx_desc(struct sxgbe_tx_norm_desc *p)
{
	memset(p, 0, sizeof(*p));
}

__attribute__((used)) static void sxgbe_clear_tx_ic(struct sxgbe_tx_norm_desc *p)
{
	p->tdes23.tx_rd_des23.int_on_com = 0;
}

__attribute__((used)) static int sxgbe_get_tx_ls(struct sxgbe_tx_norm_desc *p)
{
	return p->tdes23.tx_rd_des23.last_desc;
}

__attribute__((used)) static int sxgbe_get_tx_len(struct sxgbe_tx_norm_desc *p)
{
	return p->tdes23.tx_rd_des23.buf1_size;
}

__attribute__((used)) static void sxgbe_tx_enable_tstamp(struct sxgbe_tx_norm_desc *p)
{
	p->tdes23.tx_rd_des23.timestmp_enable = 1;
}

__attribute__((used)) static int sxgbe_get_tx_timestamp_status(struct sxgbe_tx_norm_desc *p)
{
	return p->tdes23.tx_rd_des23.timestmp_enable;
}

__attribute__((used)) static void sxgbe_tx_ctxt_desc_set_ctxt(struct sxgbe_tx_ctxt_desc *p)
{
	p->ctxt_bit = 1;
}

__attribute__((used)) static void sxgbe_tx_ctxt_desc_set_owner(struct sxgbe_tx_ctxt_desc *p)
{
	p->own_bit = 1;
}

__attribute__((used)) static int sxgbe_tx_ctxt_desc_get_owner(struct sxgbe_tx_ctxt_desc *p)
{
	return p->own_bit;
}

__attribute__((used)) static void sxgbe_tx_ctxt_desc_set_mss(struct sxgbe_tx_ctxt_desc *p, u16 mss)
{
	p->maxseg_size = mss;
}

__attribute__((used)) static int sxgbe_tx_ctxt_desc_get_mss(struct sxgbe_tx_ctxt_desc *p)
{
	return p->maxseg_size;
}

__attribute__((used)) static void sxgbe_tx_ctxt_desc_set_tcmssv(struct sxgbe_tx_ctxt_desc *p)
{
	p->tcmssv = 1;
}

__attribute__((used)) static void sxgbe_tx_ctxt_desc_reset_ostc(struct sxgbe_tx_ctxt_desc *p)
{
	p->ostc = 0;
}

__attribute__((used)) static void sxgbe_tx_ctxt_desc_set_ivlantag(struct sxgbe_tx_ctxt_desc *p,
					    int is_ivlanvalid, int ivlan_tag,
					    int ivlan_ctl)
{
	if (is_ivlanvalid) {
		p->ivlan_tag_valid = is_ivlanvalid;
		p->ivlan_tag = ivlan_tag;
		p->ivlan_tag_ctl = ivlan_ctl;
	}
}

__attribute__((used)) static int sxgbe_tx_ctxt_desc_get_ivlantag(struct sxgbe_tx_ctxt_desc *p)
{
	return p->ivlan_tag;
}

__attribute__((used)) static void sxgbe_tx_ctxt_desc_set_vlantag(struct sxgbe_tx_ctxt_desc *p,
					   int is_vlanvalid, int vlan_tag)
{
	if (is_vlanvalid) {
		p->vltag_valid = is_vlanvalid;
		p->vlan_tag = vlan_tag;
	}
}

__attribute__((used)) static int sxgbe_tx_ctxt_desc_get_vlantag(struct sxgbe_tx_ctxt_desc *p)
{
	return p->vlan_tag;
}

__attribute__((used)) static void sxgbe_tx_ctxt_desc_set_tstamp(struct sxgbe_tx_ctxt_desc *p,
					  u8 ostc_enable, u64 tstamp)
{
	if (ostc_enable) {
		p->ostc = ostc_enable;
		p->tstamp_lo = (u32) tstamp;
		p->tstamp_hi = (u32) (tstamp>>32);
	}
}

__attribute__((used)) static void sxgbe_tx_ctxt_desc_close(struct sxgbe_tx_ctxt_desc *p)
{
	p->own_bit = 1;
}

__attribute__((used)) static int sxgbe_tx_ctxt_desc_get_cde(struct sxgbe_tx_ctxt_desc *p)
{
	return p->ctxt_desc_err;
}

__attribute__((used)) static void sxgbe_init_rx_desc(struct sxgbe_rx_norm_desc *p, int disable_rx_ic,
			       int mode, int end)
{
	p->rdes23.rx_rd_des23.own_bit = 1;
	if (disable_rx_ic)
		p->rdes23.rx_rd_des23.int_on_com = disable_rx_ic;
}

__attribute__((used)) static int sxgbe_get_rx_owner(struct sxgbe_rx_norm_desc *p)
{
	return p->rdes23.rx_rd_des23.own_bit;
}

__attribute__((used)) static void sxgbe_set_rx_owner(struct sxgbe_rx_norm_desc *p)
{
	p->rdes23.rx_rd_des23.own_bit = 1;
}

__attribute__((used)) static void sxgbe_set_rx_int_on_com(struct sxgbe_rx_norm_desc *p)
{
	p->rdes23.rx_rd_des23.int_on_com = 1;
}

__attribute__((used)) static int sxgbe_get_rx_frame_len(struct sxgbe_rx_norm_desc *p)
{
	return p->rdes23.rx_wb_des23.pkt_len;
}

__attribute__((used)) static int sxgbe_get_rx_fd_status(struct sxgbe_rx_norm_desc *p)
{
	return p->rdes23.rx_wb_des23.first_desc;
}

__attribute__((used)) static int sxgbe_get_rx_ld_status(struct sxgbe_rx_norm_desc *p)
{
	return p->rdes23.rx_wb_des23.last_desc;
}

__attribute__((used)) static int sxgbe_rx_wbstatus(struct sxgbe_rx_norm_desc *p,
			     struct sxgbe_extra_stats *x, int *checksum)
{
	int status = 0;

	*checksum = CHECKSUM_UNNECESSARY;
	if (p->rdes23.rx_wb_des23.err_summary) {
		switch (p->rdes23.rx_wb_des23.err_l2_type) {
		case RX_GMII_ERR:
			status = -EINVAL;
			x->rx_code_gmii_err++;
			break;
		case RX_WATCHDOG_ERR:
			status = -EINVAL;
			x->rx_watchdog_err++;
			break;
		case RX_CRC_ERR:
			status = -EINVAL;
			x->rx_crc_err++;
			break;
		case RX_GAINT_ERR:
			status = -EINVAL;
			x->rx_gaint_pkt_err++;
			break;
		case RX_IP_HDR_ERR:
			*checksum = CHECKSUM_NONE;
			x->ip_hdr_err++;
			break;
		case RX_PAYLOAD_ERR:
			*checksum = CHECKSUM_NONE;
			x->ip_payload_err++;
			break;
		case RX_OVERFLOW_ERR:
			status = -EINVAL;
			x->overflow_error++;
			break;
		default:
			pr_err("Invalid Error type\n");
			break;
		}
	} else {
		switch (p->rdes23.rx_wb_des23.err_l2_type) {
		case RX_LEN_PKT:
			x->len_pkt++;
			break;
		case RX_MACCTL_PKT:
			x->mac_ctl_pkt++;
			break;
		case RX_DCBCTL_PKT:
			x->dcb_ctl_pkt++;
			break;
		case RX_ARP_PKT:
			x->arp_pkt++;
			break;
		case RX_OAM_PKT:
			x->oam_pkt++;
			break;
		case RX_UNTAG_PKT:
			x->untag_okt++;
			break;
		case RX_OTHER_PKT:
			x->other_pkt++;
			break;
		case RX_SVLAN_PKT:
			x->svlan_tag_pkt++;
			break;
		case RX_CVLAN_PKT:
			x->cvlan_tag_pkt++;
			break;
		case RX_DVLAN_OCVLAN_ICVLAN_PKT:
			x->dvlan_ocvlan_icvlan_pkt++;
			break;
		case RX_DVLAN_OSVLAN_ISVLAN_PKT:
			x->dvlan_osvlan_isvlan_pkt++;
			break;
		case RX_DVLAN_OSVLAN_ICVLAN_PKT:
			x->dvlan_osvlan_icvlan_pkt++;
			break;
		case RX_DVLAN_OCVLAN_ISVLAN_PKT:
			x->dvlan_ocvlan_icvlan_pkt++;
			break;
		default:
			pr_err("Invalid L2 Packet type\n");
			break;
		}
	}

	/* L3/L4 Pkt type */
	switch (p->rdes23.rx_wb_des23.layer34_pkt_type) {
	case RX_NOT_IP_PKT:
		x->not_ip_pkt++;
		break;
	case RX_IPV4_TCP_PKT:
		x->ip4_tcp_pkt++;
		break;
	case RX_IPV4_UDP_PKT:
		x->ip4_udp_pkt++;
		break;
	case RX_IPV4_ICMP_PKT:
		x->ip4_icmp_pkt++;
		break;
	case RX_IPV4_UNKNOWN_PKT:
		x->ip4_unknown_pkt++;
		break;
	case RX_IPV6_TCP_PKT:
		x->ip6_tcp_pkt++;
		break;
	case RX_IPV6_UDP_PKT:
		x->ip6_udp_pkt++;
		break;
	case RX_IPV6_ICMP_PKT:
		x->ip6_icmp_pkt++;
		break;
	case RX_IPV6_UNKNOWN_PKT:
		x->ip6_unknown_pkt++;
		break;
	default:
		pr_err("Invalid L3/L4 Packet type\n");
		break;
	}

	/* Filter */
	if (p->rdes23.rx_wb_des23.vlan_filter_match)
		x->vlan_filter_match++;

	if (p->rdes23.rx_wb_des23.sa_filter_fail) {
		status = -EINVAL;
		x->sa_filter_fail++;
	}
	if (p->rdes23.rx_wb_des23.da_filter_fail) {
		status = -EINVAL;
		x->da_filter_fail++;
	}
	if (p->rdes23.rx_wb_des23.hash_filter_pass)
		x->hash_filter_pass++;

	if (p->rdes23.rx_wb_des23.l3_filter_match)
		x->l3_filter_match++;

	if (p->rdes23.rx_wb_des23.l4_filter_match)
		x->l4_filter_match++;

	return status;
}

__attribute__((used)) static int sxgbe_get_rx_ctxt_owner(struct sxgbe_rx_ctxt_desc *p)
{
	return p->own_bit;
}

__attribute__((used)) static void sxgbe_set_ctxt_rx_owner(struct sxgbe_rx_ctxt_desc *p)
{
	p->own_bit = 1;
}

__attribute__((used)) static void sxgbe_rx_ctxt_wbstatus(struct sxgbe_rx_ctxt_desc *p,
				   struct sxgbe_extra_stats *x)
{
	if (p->tstamp_dropped)
		x->timestamp_dropped++;

	/* ptp */
	if (p->ptp_msgtype == RX_NO_PTP)
		x->rx_msg_type_no_ptp++;
	else if (p->ptp_msgtype == RX_PTP_SYNC)
		x->rx_ptp_type_sync++;
	else if (p->ptp_msgtype == RX_PTP_FOLLOW_UP)
		x->rx_ptp_type_follow_up++;
	else if (p->ptp_msgtype == RX_PTP_DELAY_REQ)
		x->rx_ptp_type_delay_req++;
	else if (p->ptp_msgtype == RX_PTP_DELAY_RESP)
		x->rx_ptp_type_delay_resp++;
	else if (p->ptp_msgtype == RX_PTP_PDELAY_REQ)
		x->rx_ptp_type_pdelay_req++;
	else if (p->ptp_msgtype == RX_PTP_PDELAY_RESP)
		x->rx_ptp_type_pdelay_resp++;
	else if (p->ptp_msgtype == RX_PTP_PDELAY_FOLLOW_UP)
		x->rx_ptp_type_pdelay_follow_up++;
	else if (p->ptp_msgtype == RX_PTP_ANNOUNCE)
		x->rx_ptp_announce++;
	else if (p->ptp_msgtype == RX_PTP_MGMT)
		x->rx_ptp_mgmt++;
	else if (p->ptp_msgtype == RX_PTP_SIGNAL)
		x->rx_ptp_signal++;
	else if (p->ptp_msgtype == RX_PTP_RESV_MSG)
		x->rx_ptp_resv_msg_type++;
}

__attribute__((used)) static int sxgbe_get_rx_ctxt_tstamp_status(struct sxgbe_rx_ctxt_desc *p)
{
	if ((p->tstamp_hi == 0xffffffff) && (p->tstamp_lo == 0xffffffff)) {
		pr_err("Time stamp corrupted\n");
		return 0;
	}

	return p->tstamp_available;
}

__attribute__((used)) static u64 sxgbe_get_rx_timestamp(struct sxgbe_rx_ctxt_desc *p)
{
	u64 ns;

	ns = p->tstamp_lo;
	ns |= ((u64)p->tstamp_hi) << 32;

	return ns;
}

const struct sxgbe_desc_ops *sxgbe_get_desc_ops(void)
{
	return &desc_ops;
}

