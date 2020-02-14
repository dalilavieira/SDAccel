#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int dummy; } ;
struct netns_ipvs {int dummy; } ;
struct ip_vs_proto_data {int dummy; } ;
struct ip_vs_iphdr {int /*<<< orphan*/  daddr; int /*<<< orphan*/  saddr; int /*<<< orphan*/  protocol; } ;
struct ip_vs_conn_param {int dummy; } ;
struct ip_vs_conn {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPPROTO_UDP ; 
 int /*<<< orphan*/  IP_VS_DBG_ADDR (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IP_VS_DBG_BUF (int,char*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int NF_ACCEPT ; 
 int /*<<< orphan*/  PORT_ISAKMP ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ip_vs_conn_fill_param (struct netns_ipvs*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct ip_vs_conn_param*) ; 
 struct ip_vs_conn* ip_vs_conn_in_get (struct ip_vs_conn_param*) ; 
 struct ip_vs_conn* ip_vs_conn_out_get (struct ip_vs_conn_param*) ; 
 scalar_t__ ip_vs_iph_icmp (struct ip_vs_iphdr const*) ; 
 int /*<<< orphan*/  ip_vs_iph_inverse (struct ip_vs_iphdr const*) ; 
 TYPE_1__* ip_vs_proto_get (int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int) ; 

__attribute__((used)) static void
ah_esp_conn_fill_param_proto(struct netns_ipvs *ipvs, int af,
			     const struct ip_vs_iphdr *iph,
			     struct ip_vs_conn_param *p)
{
	if (likely(!ip_vs_iph_inverse(iph)))
		ip_vs_conn_fill_param(ipvs, af, IPPROTO_UDP,
				      &iph->saddr, htons(PORT_ISAKMP),
				      &iph->daddr, htons(PORT_ISAKMP), p);
	else
		ip_vs_conn_fill_param(ipvs, af, IPPROTO_UDP,
				      &iph->daddr, htons(PORT_ISAKMP),
				      &iph->saddr, htons(PORT_ISAKMP), p);
}

__attribute__((used)) static struct ip_vs_conn *
ah_esp_conn_in_get(struct netns_ipvs *ipvs, int af, const struct sk_buff *skb,
		   const struct ip_vs_iphdr *iph)
{
	struct ip_vs_conn *cp;
	struct ip_vs_conn_param p;

	ah_esp_conn_fill_param_proto(ipvs, af, iph, &p);
	cp = ip_vs_conn_in_get(&p);
	if (!cp) {
		/*
		 * We are not sure if the packet is from our
		 * service, so our conn_schedule hook should return NF_ACCEPT
		 */
		IP_VS_DBG_BUF(12, "Unknown ISAKMP entry for outin packet "
			      "%s%s %s->%s\n",
			      ip_vs_iph_icmp(iph) ? "ICMP+" : "",
			      ip_vs_proto_get(iph->protocol)->name,
			      IP_VS_DBG_ADDR(af, &iph->saddr),
			      IP_VS_DBG_ADDR(af, &iph->daddr));
	}

	return cp;
}

__attribute__((used)) static struct ip_vs_conn *
ah_esp_conn_out_get(struct netns_ipvs *ipvs, int af, const struct sk_buff *skb,
		    const struct ip_vs_iphdr *iph)
{
	struct ip_vs_conn *cp;
	struct ip_vs_conn_param p;

	ah_esp_conn_fill_param_proto(ipvs, af, iph, &p);
	cp = ip_vs_conn_out_get(&p);
	if (!cp) {
		IP_VS_DBG_BUF(12, "Unknown ISAKMP entry for inout packet "
			      "%s%s %s->%s\n",
			      ip_vs_iph_icmp(iph) ? "ICMP+" : "",
			      ip_vs_proto_get(iph->protocol)->name,
			      IP_VS_DBG_ADDR(af, &iph->saddr),
			      IP_VS_DBG_ADDR(af, &iph->daddr));
	}

	return cp;
}

__attribute__((used)) static int
ah_esp_conn_schedule(struct netns_ipvs *ipvs, int af, struct sk_buff *skb,
		     struct ip_vs_proto_data *pd,
		     int *verdict, struct ip_vs_conn **cpp,
		     struct ip_vs_iphdr *iph)
{
	/*
	 * AH/ESP is only related traffic. Pass the packet to IP stack.
	 */
	*verdict = NF_ACCEPT;
	return 0;
}

