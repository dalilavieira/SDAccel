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
struct xt_mtchk_param {struct ip6t_mh* matchinfo; } ;
struct xt_action_param {scalar_t__ fragoff; int hotdrop; int /*<<< orphan*/  thoff; struct ip6t_mh* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct ip6t_mh {scalar_t__* types; int invflags; } ;
struct ip6_mh {scalar_t__ ip6mh_proto; scalar_t__ ip6mh_type; } ;
typedef  int /*<<< orphan*/  _mh ;

/* Variables and functions */
 int EINVAL ; 
 int IP6T_MH_INV_MASK ; 
 int IP6T_MH_INV_TYPE ; 
 scalar_t__ IPPROTO_NONE ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 struct ip6_mh* skb_header_pointer (struct sk_buff const*,int /*<<< orphan*/ ,int,struct ip6_mh*) ; 

__attribute__((used)) static inline bool
type_match(u_int8_t min, u_int8_t max, u_int8_t type, bool invert)
{
	return (type >= min && type <= max) ^ invert;
}

__attribute__((used)) static bool mh_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
	struct ip6_mh _mh;
	const struct ip6_mh *mh;
	const struct ip6t_mh *mhinfo = par->matchinfo;

	/* Must not be a fragment. */
	if (par->fragoff != 0)
		return false;

	mh = skb_header_pointer(skb, par->thoff, sizeof(_mh), &_mh);
	if (mh == NULL) {
		/* We've been asked to examine this packet, and we
		   can't.  Hence, no choice but to drop. */
		pr_debug("Dropping evil MH tinygram.\n");
		par->hotdrop = true;
		return false;
	}

	if (mh->ip6mh_proto != IPPROTO_NONE) {
		pr_debug("Dropping invalid MH Payload Proto: %u\n",
			 mh->ip6mh_proto);
		par->hotdrop = true;
		return false;
	}

	return type_match(mhinfo->types[0], mhinfo->types[1], mh->ip6mh_type,
			  !!(mhinfo->invflags & IP6T_MH_INV_TYPE));
}

__attribute__((used)) static int mh_mt6_check(const struct xt_mtchk_param *par)
{
	const struct ip6t_mh *mhinfo = par->matchinfo;

	/* Must specify no unknown invflags */
	return (mhinfo->invflags & ~IP6T_MH_INV_MASK) ? -EINVAL : 0;
}

