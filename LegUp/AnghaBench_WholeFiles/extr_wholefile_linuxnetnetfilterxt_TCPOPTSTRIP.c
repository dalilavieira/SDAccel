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
typedef  scalar_t__ u_int8_t ;
typedef  int u_int16_t ;
struct xt_tcpoptstrip_target_info {int /*<<< orphan*/  strip_bmap; } ;
struct xt_action_param {scalar_t__ fragoff; struct xt_tcpoptstrip_target_info* targinfo; } ;
struct tcphdr {int doff; int /*<<< orphan*/  check; } ;
struct sk_buff {unsigned int len; } ;
struct iphdr {int dummy; } ;

/* Variables and functions */
 unsigned int NF_DROP ; 
 scalar_t__ const TCPOPT_NOP ; 
 unsigned int XT_CONTINUE ; 
 int /*<<< orphan*/  htons (int) ; 
 int /*<<< orphan*/  inet_proto_csum_replace2 (int /*<<< orphan*/ *,struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 unsigned int ip_hdrlen (struct sk_buff*) ; 
 int /*<<< orphan*/  memset (scalar_t__*,scalar_t__ const,unsigned int) ; 
 int /*<<< orphan*/  skb_make_writable (struct sk_buff*,unsigned int) ; 
 scalar_t__ skb_network_header (struct sk_buff*) ; 
 int /*<<< orphan*/  tcpoptstrip_test_bit (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline unsigned int optlen(const u_int8_t *opt, unsigned int offset)
{
	/* Beware zero-length options: make finite progress */
	if (opt[offset] <= TCPOPT_NOP || opt[offset+1] == 0)
		return 1;
	else
		return opt[offset+1];
}

__attribute__((used)) static unsigned int
tcpoptstrip_mangle_packet(struct sk_buff *skb,
			  const struct xt_action_param *par,
			  unsigned int tcphoff, unsigned int minlen)
{
	const struct xt_tcpoptstrip_target_info *info = par->targinfo;
	unsigned int optl, i, j;
	struct tcphdr *tcph;
	u_int16_t n, o;
	u_int8_t *opt;
	int len, tcp_hdrlen;

	/* This is a fragment, no TCP header is available */
	if (par->fragoff != 0)
		return XT_CONTINUE;

	if (!skb_make_writable(skb, skb->len))
		return NF_DROP;

	len = skb->len - tcphoff;
	if (len < (int)sizeof(struct tcphdr))
		return NF_DROP;

	tcph = (struct tcphdr *)(skb_network_header(skb) + tcphoff);
	tcp_hdrlen = tcph->doff * 4;

	if (len < tcp_hdrlen)
		return NF_DROP;

	opt  = (u_int8_t *)tcph;

	/*
	 * Walk through all TCP options - if we find some option to remove,
	 * set all octets to %TCPOPT_NOP and adjust checksum.
	 */
	for (i = sizeof(struct tcphdr); i < tcp_hdrlen - 1; i += optl) {
		optl = optlen(opt, i);

		if (i + optl > tcp_hdrlen)
			break;

		if (!tcpoptstrip_test_bit(info->strip_bmap, opt[i]))
			continue;

		for (j = 0; j < optl; ++j) {
			o = opt[i+j];
			n = TCPOPT_NOP;
			if ((i + j) % 2 == 0) {
				o <<= 8;
				n <<= 8;
			}
			inet_proto_csum_replace2(&tcph->check, skb, htons(o),
						 htons(n), false);
		}
		memset(opt + i, TCPOPT_NOP, optl);
	}

	return XT_CONTINUE;
}

__attribute__((used)) static unsigned int
tcpoptstrip_tg4(struct sk_buff *skb, const struct xt_action_param *par)
{
	return tcpoptstrip_mangle_packet(skb, par, ip_hdrlen(skb),
	       sizeof(struct iphdr) + sizeof(struct tcphdr));
}

