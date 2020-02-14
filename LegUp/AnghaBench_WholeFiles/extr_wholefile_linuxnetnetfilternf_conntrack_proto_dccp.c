#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u_int8_t ;
typedef  int /*<<< orphan*/  u_int16_t ;
typedef  int u64 ;
typedef  struct sk_buff {unsigned int len; } const sk_buff ;
struct nf_proto_net {int /*<<< orphan*/  users; } ;
struct nf_dccp_net {int dccp_loose; unsigned int* dccp_timeout; struct nf_proto_net pn; } ;
struct TYPE_7__ {size_t* role; size_t state; int last_pkt; size_t last_dir; int handshake_seq; } ;
struct TYPE_8__ {TYPE_3__ dccp; } ;
struct nf_conn {TYPE_4__ proto; int /*<<< orphan*/  lock; int /*<<< orphan*/  status; } ;
struct TYPE_5__ {struct nf_dccp_net dccp; } ;
struct TYPE_6__ {TYPE_1__ nf_ct_proto; scalar_t__ sysctl_checksum; } ;
struct net {TYPE_2__ ct; } ;
struct dccp_hdr_ack_bits {int /*<<< orphan*/  dccph_ack_nr_low; int /*<<< orphan*/  dccph_ack_nr_high; } ;
struct dccp_hdr {size_t dccph_type; int dccph_doff; int dccph_cscov; } ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;
typedef  enum ip_conntrack_dir { ____Placeholder_ip_conntrack_dir } ip_conntrack_dir ;
typedef  enum ct_dccp_roles { ____Placeholder_ct_dccp_roles } ct_dccp_roles ;
typedef  int /*<<< orphan*/  _dh ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 int CTINFO2DIR (int) ; 
#define  CT_DCCP_CLOSEREQ 135 
#define  CT_DCCP_CLOSING 134 
#define  CT_DCCP_IGNORE 133 
#define  CT_DCCP_INVALID 132 
 size_t CT_DCCP_NONE ; 
 size_t CT_DCCP_OPEN ; 
#define  CT_DCCP_PARTOPEN 131 
#define  CT_DCCP_REQUEST 130 
#define  CT_DCCP_RESPOND 129 
 size_t CT_DCCP_ROLE_CLIENT ; 
 int CT_DCCP_ROLE_SERVER ; 
#define  CT_DCCP_TIMEWAIT 128 
 int DCCP_MSL ; 
 int DCCP_PKT_ACK ; 
 scalar_t__ DCCP_PKT_INVALID ; 
 int DCCP_PKT_REQUEST ; 
 int DCCP_PKT_RESET ; 
 int DCCP_PKT_RESPONSE ; 
 int HZ ; 
 int /*<<< orphan*/  IPCT_PROTOINFO ; 
 int /*<<< orphan*/  IPPROTO_DCCP ; 
 int /*<<< orphan*/  IPS_ASSURED_BIT ; 
 int /*<<< orphan*/  IPS_SEEN_REPLY_BIT ; 
 size_t IP_CT_DIR_ORIGINAL ; 
 size_t IP_CT_DIR_REPLY ; 
 int NF_ACCEPT ; 
 unsigned int NF_INET_PRE_ROUTING ; 
 int __dccp_basic_hdr_len (struct dccp_hdr const*) ; 
 void* dccp_hdr_seq (struct dccp_hdr*) ; 
 int*** dccp_state_table ; 
 scalar_t__ nf_checksum_partial (struct sk_buff const*,unsigned int,unsigned int,unsigned int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nf_conntrack_event_cache (int /*<<< orphan*/ ,struct nf_conn*) ; 
 int /*<<< orphan*/  nf_ct_kill_acct (struct nf_conn*,int,struct sk_buff const*) ; 
 int /*<<< orphan*/  nf_ct_l4proto_log_invalid (struct sk_buff const*,struct nf_conn*,char*,char const*) ; 
 struct net* nf_ct_net (struct nf_conn*) ; 
 int /*<<< orphan*/  nf_ct_refresh_acct (struct nf_conn*,int,struct sk_buff const*,unsigned int) ; 
 unsigned int* nf_ct_timeout_lookup (struct nf_conn*) ; 
 int /*<<< orphan*/  nf_l4proto_log_invalid (struct sk_buff const*,struct net*,int,int /*<<< orphan*/ ,char*,char const*) ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 scalar_t__ ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct dccp_hdr* skb_header_pointer (struct sk_buff const*,unsigned int,int,struct dccp_hdr*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline struct nf_dccp_net *dccp_pernet(struct net *net)
{
	return &net->ct.nf_ct_proto.dccp;
}

__attribute__((used)) static bool dccp_new(struct nf_conn *ct, const struct sk_buff *skb,
		     unsigned int dataoff)
{
	struct net *net = nf_ct_net(ct);
	struct nf_dccp_net *dn;
	struct dccp_hdr _dh, *dh;
	const char *msg;
	u_int8_t state;

	dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &_dh);
	BUG_ON(dh == NULL);

	state = dccp_state_table[CT_DCCP_ROLE_CLIENT][dh->dccph_type][CT_DCCP_NONE];
	switch (state) {
	default:
		dn = dccp_pernet(net);
		if (dn->dccp_loose == 0) {
			msg = "not picking up existing connection ";
			goto out_invalid;
		}
	case CT_DCCP_REQUEST:
		break;
	case CT_DCCP_INVALID:
		msg = "invalid state transition ";
		goto out_invalid;
	}

	ct->proto.dccp.role[IP_CT_DIR_ORIGINAL] = CT_DCCP_ROLE_CLIENT;
	ct->proto.dccp.role[IP_CT_DIR_REPLY] = CT_DCCP_ROLE_SERVER;
	ct->proto.dccp.state = CT_DCCP_NONE;
	ct->proto.dccp.last_pkt = DCCP_PKT_REQUEST;
	ct->proto.dccp.last_dir = IP_CT_DIR_ORIGINAL;
	ct->proto.dccp.handshake_seq = 0;
	return true;

out_invalid:
	nf_ct_l4proto_log_invalid(skb, ct, "%s", msg);
	return false;
}

__attribute__((used)) static u64 dccp_ack_seq(const struct dccp_hdr *dh)
{
	const struct dccp_hdr_ack_bits *dhack;

	dhack = (void *)dh + __dccp_basic_hdr_len(dh);
	return ((u64)ntohs(dhack->dccph_ack_nr_high) << 32) +
		     ntohl(dhack->dccph_ack_nr_low);
}

__attribute__((used)) static int dccp_packet(struct nf_conn *ct, const struct sk_buff *skb,
		       unsigned int dataoff, enum ip_conntrack_info ctinfo)
{
	enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
	struct dccp_hdr _dh, *dh;
	u_int8_t type, old_state, new_state;
	enum ct_dccp_roles role;
	unsigned int *timeouts;

	dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &_dh);
	BUG_ON(dh == NULL);
	type = dh->dccph_type;

	if (type == DCCP_PKT_RESET &&
	    !test_bit(IPS_SEEN_REPLY_BIT, &ct->status)) {
		/* Tear down connection immediately if only reply is a RESET */
		nf_ct_kill_acct(ct, ctinfo, skb);
		return NF_ACCEPT;
	}

	spin_lock_bh(&ct->lock);

	role = ct->proto.dccp.role[dir];
	old_state = ct->proto.dccp.state;
	new_state = dccp_state_table[role][type][old_state];

	switch (new_state) {
	case CT_DCCP_REQUEST:
		if (old_state == CT_DCCP_TIMEWAIT &&
		    role == CT_DCCP_ROLE_SERVER) {
			/* Reincarnation in the reverse direction: reopen and
			 * reverse client/server roles. */
			ct->proto.dccp.role[dir] = CT_DCCP_ROLE_CLIENT;
			ct->proto.dccp.role[!dir] = CT_DCCP_ROLE_SERVER;
		}
		break;
	case CT_DCCP_RESPOND:
		if (old_state == CT_DCCP_REQUEST)
			ct->proto.dccp.handshake_seq = dccp_hdr_seq(dh);
		break;
	case CT_DCCP_PARTOPEN:
		if (old_state == CT_DCCP_RESPOND &&
		    type == DCCP_PKT_ACK &&
		    dccp_ack_seq(dh) == ct->proto.dccp.handshake_seq)
			set_bit(IPS_ASSURED_BIT, &ct->status);
		break;
	case CT_DCCP_IGNORE:
		/*
		 * Connection tracking might be out of sync, so we ignore
		 * packets that might establish a new connection and resync
		 * if the server responds with a valid Response.
		 */
		if (ct->proto.dccp.last_dir == !dir &&
		    ct->proto.dccp.last_pkt == DCCP_PKT_REQUEST &&
		    type == DCCP_PKT_RESPONSE) {
			ct->proto.dccp.role[!dir] = CT_DCCP_ROLE_CLIENT;
			ct->proto.dccp.role[dir] = CT_DCCP_ROLE_SERVER;
			ct->proto.dccp.handshake_seq = dccp_hdr_seq(dh);
			new_state = CT_DCCP_RESPOND;
			break;
		}
		ct->proto.dccp.last_dir = dir;
		ct->proto.dccp.last_pkt = type;

		spin_unlock_bh(&ct->lock);
		nf_ct_l4proto_log_invalid(skb, ct, "%s", "invalid packet");
		return NF_ACCEPT;
	case CT_DCCP_INVALID:
		spin_unlock_bh(&ct->lock);
		nf_ct_l4proto_log_invalid(skb, ct, "%s", "invalid state transition");
		return -NF_ACCEPT;
	}

	ct->proto.dccp.last_dir = dir;
	ct->proto.dccp.last_pkt = type;
	ct->proto.dccp.state = new_state;
	spin_unlock_bh(&ct->lock);

	if (new_state != old_state)
		nf_conntrack_event_cache(IPCT_PROTOINFO, ct);

	timeouts = nf_ct_timeout_lookup(ct);
	if (!timeouts)
		timeouts = dccp_pernet(nf_ct_net(ct))->dccp_timeout;
	nf_ct_refresh_acct(ct, ctinfo, skb, timeouts[new_state]);

	return NF_ACCEPT;
}

__attribute__((used)) static int dccp_error(struct net *net, struct nf_conn *tmpl,
		      struct sk_buff *skb, unsigned int dataoff,
		      u_int8_t pf, unsigned int hooknum)
{
	struct dccp_hdr _dh, *dh;
	unsigned int dccp_len = skb->len - dataoff;
	unsigned int cscov;
	const char *msg;

	dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &_dh);
	if (dh == NULL) {
		msg = "nf_ct_dccp: short packet ";
		goto out_invalid;
	}

	if (dh->dccph_doff * 4 < sizeof(struct dccp_hdr) ||
	    dh->dccph_doff * 4 > dccp_len) {
		msg = "nf_ct_dccp: truncated/malformed packet ";
		goto out_invalid;
	}

	cscov = dccp_len;
	if (dh->dccph_cscov) {
		cscov = (dh->dccph_cscov - 1) * 4;
		if (cscov > dccp_len) {
			msg = "nf_ct_dccp: bad checksum coverage ";
			goto out_invalid;
		}
	}

	if (net->ct.sysctl_checksum && hooknum == NF_INET_PRE_ROUTING &&
	    nf_checksum_partial(skb, hooknum, dataoff, cscov, IPPROTO_DCCP,
				pf)) {
		msg = "nf_ct_dccp: bad checksum ";
		goto out_invalid;
	}

	if (dh->dccph_type >= DCCP_PKT_INVALID) {
		msg = "nf_ct_dccp: reserved packet type ";
		goto out_invalid;
	}

	return NF_ACCEPT;

out_invalid:
	nf_l4proto_log_invalid(skb, net, pf, IPPROTO_DCCP, "%s", msg);
	return -NF_ACCEPT;
}

__attribute__((used)) static bool dccp_can_early_drop(const struct nf_conn *ct)
{
	switch (ct->proto.dccp.state) {
	case CT_DCCP_CLOSEREQ:
	case CT_DCCP_CLOSING:
	case CT_DCCP_TIMEWAIT:
		return true;
	default:
		break;
	}

	return false;
}

__attribute__((used)) static int dccp_kmemdup_sysctl_table(struct net *net, struct nf_proto_net *pn,
				     struct nf_dccp_net *dn)
{
#ifdef CONFIG_SYSCTL
	if (pn->ctl_table)
		return 0;

	pn->ctl_table = kmemdup(dccp_sysctl_table,
				sizeof(dccp_sysctl_table),
				GFP_KERNEL);
	if (!pn->ctl_table)
		return -ENOMEM;

	pn->ctl_table[0].data = &dn->dccp_timeout[CT_DCCP_REQUEST];
	pn->ctl_table[1].data = &dn->dccp_timeout[CT_DCCP_RESPOND];
	pn->ctl_table[2].data = &dn->dccp_timeout[CT_DCCP_PARTOPEN];
	pn->ctl_table[3].data = &dn->dccp_timeout[CT_DCCP_OPEN];
	pn->ctl_table[4].data = &dn->dccp_timeout[CT_DCCP_CLOSEREQ];
	pn->ctl_table[5].data = &dn->dccp_timeout[CT_DCCP_CLOSING];
	pn->ctl_table[6].data = &dn->dccp_timeout[CT_DCCP_TIMEWAIT];
	pn->ctl_table[7].data = &dn->dccp_loose;

	/* Don't export sysctls to unprivileged users */
	if (net->user_ns != &init_user_ns)
		pn->ctl_table[0].procname = NULL;
#endif
	return 0;
}

__attribute__((used)) static int dccp_init_net(struct net *net, u_int16_t proto)
{
	struct nf_dccp_net *dn = dccp_pernet(net);
	struct nf_proto_net *pn = &dn->pn;

	if (!pn->users) {
		/* default values */
		dn->dccp_loose = 1;
		dn->dccp_timeout[CT_DCCP_REQUEST]	= 2 * DCCP_MSL;
		dn->dccp_timeout[CT_DCCP_RESPOND]	= 4 * DCCP_MSL;
		dn->dccp_timeout[CT_DCCP_PARTOPEN]	= 4 * DCCP_MSL;
		dn->dccp_timeout[CT_DCCP_OPEN]		= 12 * 3600 * HZ;
		dn->dccp_timeout[CT_DCCP_CLOSEREQ]	= 64 * HZ;
		dn->dccp_timeout[CT_DCCP_CLOSING]	= 64 * HZ;
		dn->dccp_timeout[CT_DCCP_TIMEWAIT]	= 2 * DCCP_MSL;

		/* timeouts[0] is unused, make it same as SYN_SENT so
		 * ->timeouts[0] contains 'new' timeout, like udp or icmp.
		 */
		dn->dccp_timeout[CT_DCCP_NONE] = dn->dccp_timeout[CT_DCCP_REQUEST];
	}

	return dccp_kmemdup_sysctl_table(net, pn, dn);
}

__attribute__((used)) static struct nf_proto_net *dccp_get_net_proto(struct net *net)
{
	return &net->ct.nf_ct_proto.dccp.pn;
}

