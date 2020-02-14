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
typedef  int const u_int8_t ;
typedef  scalar_t__ u_int16_t ;
struct xt_multiport_v1 {unsigned int count; scalar_t__* ports; int flags; int invert; scalar_t__* pflags; } ;
struct xt_mtchk_param {struct xt_multiport_v1* matchinfo; struct ipt_ip* entryinfo; } ;
struct xt_action_param {scalar_t__ fragoff; int hotdrop; int /*<<< orphan*/  thoff; struct xt_multiport_v1* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct ipt_ip {scalar_t__ proto; int invflags; } ;
struct ip6t_ip6 {scalar_t__ proto; int invflags; } ;
typedef  int /*<<< orphan*/  _ports ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IPPROTO_DCCP ; 
 scalar_t__ IPPROTO_SCTP ; 
 scalar_t__ IPPROTO_TCP ; 
 scalar_t__ IPPROTO_UDP ; 
 scalar_t__ IPPROTO_UDPLITE ; 
 int const XT_INV_PROTO ; 
#define  XT_MULTIPORT_DESTINATION 130 
#define  XT_MULTIPORT_EITHER 129 
#define  XT_MULTIPORT_SOURCE 128 
 int const XT_MULTI_PORTS ; 
 scalar_t__ ntohs (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/ * skb_header_pointer (struct sk_buff const*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool
ports_match_v1(const struct xt_multiport_v1 *minfo,
	       u_int16_t src, u_int16_t dst)
{
	unsigned int i;
	u_int16_t s, e;

	for (i = 0; i < minfo->count; i++) {
		s = minfo->ports[i];

		if (minfo->pflags[i]) {
			/* range port matching */
			e = minfo->ports[++i];
			pr_debug("src or dst matches with %d-%d?\n", s, e);

			switch (minfo->flags) {
			case XT_MULTIPORT_SOURCE:
				if (src >= s && src <= e)
					return true ^ minfo->invert;
				break;
			case XT_MULTIPORT_DESTINATION:
				if (dst >= s && dst <= e)
					return true ^ minfo->invert;
				break;
			case XT_MULTIPORT_EITHER:
				if ((dst >= s && dst <= e) ||
				    (src >= s && src <= e))
					return true ^ minfo->invert;
				break;
			default:
				break;
			}
		} else {
			/* exact port matching */
			pr_debug("src or dst matches with %d?\n", s);

			switch (minfo->flags) {
			case XT_MULTIPORT_SOURCE:
				if (src == s)
					return true ^ minfo->invert;
				break;
			case XT_MULTIPORT_DESTINATION:
				if (dst == s)
					return true ^ minfo->invert;
				break;
			case XT_MULTIPORT_EITHER:
				if (src == s || dst == s)
					return true ^ minfo->invert;
				break;
			default:
				break;
			}
		}
	}

	return minfo->invert;
}

__attribute__((used)) static bool
multiport_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const __be16 *pptr;
	__be16 _ports[2];
	const struct xt_multiport_v1 *multiinfo = par->matchinfo;

	if (par->fragoff != 0)
		return false;

	pptr = skb_header_pointer(skb, par->thoff, sizeof(_ports), _ports);
	if (pptr == NULL) {
		/* We've been asked to examine this packet, and we
		 * can't.  Hence, no choice but to drop.
		 */
		pr_debug("Dropping evil offset=0 tinygram.\n");
		par->hotdrop = true;
		return false;
	}

	return ports_match_v1(multiinfo, ntohs(pptr[0]), ntohs(pptr[1]));
}

__attribute__((used)) static inline bool
check(u_int16_t proto,
      u_int8_t ip_invflags,
      u_int8_t match_flags,
      u_int8_t count)
{
	/* Must specify supported protocol, no unknown flags or bad count */
	return (proto == IPPROTO_TCP || proto == IPPROTO_UDP
		|| proto == IPPROTO_UDPLITE
		|| proto == IPPROTO_SCTP || proto == IPPROTO_DCCP)
		&& !(ip_invflags & XT_INV_PROTO)
		&& (match_flags == XT_MULTIPORT_SOURCE
		    || match_flags == XT_MULTIPORT_DESTINATION
		    || match_flags == XT_MULTIPORT_EITHER)
		&& count <= XT_MULTI_PORTS;
}

__attribute__((used)) static int multiport_mt_check(const struct xt_mtchk_param *par)
{
	const struct ipt_ip *ip = par->entryinfo;
	const struct xt_multiport_v1 *multiinfo = par->matchinfo;

	return check(ip->proto, ip->invflags, multiinfo->flags,
		     multiinfo->count) ? 0 : -EINVAL;
}

__attribute__((used)) static int multiport_mt6_check(const struct xt_mtchk_param *par)
{
	const struct ip6t_ip6 *ip = par->entryinfo;
	const struct xt_multiport_v1 *multiinfo = par->matchinfo;

	return check(ip->proto, ip->invflags, multiinfo->flags,
		     multiinfo->count) ? 0 : -EINVAL;
}

