#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_9__ ;
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
union nf_inet_addr {int /*<<< orphan*/  ip6; int /*<<< orphan*/  ip; } ;
typedef  scalar_t__ u_int16_t ;
typedef  int u16 ;
struct sk_buff {int dummy; } ;
struct TYPE_15__ {int /*<<< orphan*/  port; } ;
struct TYPE_16__ {TYPE_6__ tcp; } ;
struct TYPE_17__ {TYPE_7__ u; } ;
struct TYPE_18__ {TYPE_8__ dst; } ;
struct TYPE_13__ {int /*<<< orphan*/  port; } ;
struct TYPE_14__ {TYPE_4__ tcp; } ;
struct nf_conntrack_expect {int dir; TYPE_9__ tuple; TYPE_5__ saved_proto; int /*<<< orphan*/  expectfn; struct nf_conn* master; } ;
struct nf_conn {TYPE_3__* tuplehash; } ;
typedef  enum nf_ct_ftp_type { ____Placeholder_nf_ct_ftp_type } nf_ct_ftp_type ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;
typedef  int /*<<< orphan*/  buffer ;
struct TYPE_10__ {union nf_inet_addr u3; } ;
struct TYPE_11__ {TYPE_1__ dst; } ;
struct TYPE_12__ {TYPE_2__ tuple; } ;

/* Variables and functions */
 int CTINFO2DIR (int) ; 
 int EBUSY ; 
 int /*<<< orphan*/  INET6_ADDRSTRLEN ; 
 int /*<<< orphan*/  NFPROTO_IPV4 ; 
 unsigned int NF_ACCEPT ; 
#define  NF_CT_FTP_EPRT 131 
#define  NF_CT_FTP_EPSV 130 
#define  NF_CT_FTP_PASV 129 
#define  NF_CT_FTP_PORT 128 
 unsigned int NF_DROP ; 
 int /*<<< orphan*/  htons (scalar_t__) ; 
 int nf_ct_expect_related (struct nf_conntrack_expect*) ; 
 int /*<<< orphan*/  nf_ct_helper_log (struct sk_buff*,struct nf_conn*,char*) ; 
 int /*<<< orphan*/  nf_ct_l3num (struct nf_conn*) ; 
 int /*<<< orphan*/  nf_ct_unexpect_related (struct nf_conntrack_expect*) ; 
 int /*<<< orphan*/  nf_nat_follow_master ; 
 int /*<<< orphan*/  nf_nat_mangle_tcp_packet (struct sk_buff*,struct nf_conn*,int,unsigned int,unsigned int,unsigned int,char*,unsigned int) ; 
 scalar_t__ ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int snprintf (char*,size_t,char*,int,...) ; 

__attribute__((used)) static int nf_nat_ftp_fmt_cmd(struct nf_conn *ct, enum nf_ct_ftp_type type,
			      char *buffer, size_t buflen,
			      union nf_inet_addr *addr, u16 port)
{
	switch (type) {
	case NF_CT_FTP_PORT:
	case NF_CT_FTP_PASV:
		return snprintf(buffer, buflen, "%u,%u,%u,%u,%u,%u",
				((unsigned char *)&addr->ip)[0],
				((unsigned char *)&addr->ip)[1],
				((unsigned char *)&addr->ip)[2],
				((unsigned char *)&addr->ip)[3],
				port >> 8,
				port & 0xFF);
	case NF_CT_FTP_EPRT:
		if (nf_ct_l3num(ct) == NFPROTO_IPV4)
			return snprintf(buffer, buflen, "|1|%pI4|%u|",
					&addr->ip, port);
		else
			return snprintf(buffer, buflen, "|2|%pI6|%u|",
					&addr->ip6, port);
	case NF_CT_FTP_EPSV:
		return snprintf(buffer, buflen, "|||%u|", port);
	}

	return 0;
}

__attribute__((used)) static unsigned int nf_nat_ftp(struct sk_buff *skb,
			       enum ip_conntrack_info ctinfo,
			       enum nf_ct_ftp_type type,
			       unsigned int protoff,
			       unsigned int matchoff,
			       unsigned int matchlen,
			       struct nf_conntrack_expect *exp)
{
	union nf_inet_addr newaddr;
	u_int16_t port;
	int dir = CTINFO2DIR(ctinfo);
	struct nf_conn *ct = exp->master;
	char buffer[sizeof("|1||65535|") + INET6_ADDRSTRLEN];
	unsigned int buflen;

	pr_debug("type %i, off %u len %u\n", type, matchoff, matchlen);

	/* Connection will come from wherever this packet goes, hence !dir */
	newaddr = ct->tuplehash[!dir].tuple.dst.u3;
	exp->saved_proto.tcp.port = exp->tuple.dst.u.tcp.port;
	exp->dir = !dir;

	/* When you see the packet, we need to NAT it the same as the
	 * this one. */
	exp->expectfn = nf_nat_follow_master;

	/* Try to get same port: if not, try to change it. */
	for (port = ntohs(exp->saved_proto.tcp.port); port != 0; port++) {
		int ret;

		exp->tuple.dst.u.tcp.port = htons(port);
		ret = nf_ct_expect_related(exp);
		if (ret == 0)
			break;
		else if (ret != -EBUSY) {
			port = 0;
			break;
		}
	}

	if (port == 0) {
		nf_ct_helper_log(skb, ct, "all ports in use");
		return NF_DROP;
	}

	buflen = nf_nat_ftp_fmt_cmd(ct, type, buffer, sizeof(buffer),
				    &newaddr, port);
	if (!buflen)
		goto out;

	pr_debug("calling nf_nat_mangle_tcp_packet\n");

	if (!nf_nat_mangle_tcp_packet(skb, ct, ctinfo, protoff, matchoff,
				      matchlen, buffer, buflen))
		goto out;

	return NF_ACCEPT;

out:
	nf_ct_helper_log(skb, ct, "cannot mangle packet");
	nf_ct_unexpect_related(exp);
	return NF_DROP;
}

