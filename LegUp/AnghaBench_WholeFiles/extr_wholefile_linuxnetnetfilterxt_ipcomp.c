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
typedef  scalar_t__ u_int32_t ;
struct xt_mtchk_param {struct xt_ipcomp* matchinfo; } ;
struct xt_ipcomp {scalar_t__* spis; int invflags; } ;
struct xt_action_param {scalar_t__ fragoff; int hotdrop; int /*<<< orphan*/  thoff; struct xt_ipcomp* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct ip_comp_hdr {int /*<<< orphan*/  cpi; } ;
typedef  int /*<<< orphan*/  _comphdr ;

/* Variables and functions */
 int EINVAL ; 
 int XT_IPCOMP_INV_MASK ; 
 int XT_IPCOMP_INV_SPI ; 
 scalar_t__ ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int) ; 
 struct ip_comp_hdr* skb_header_pointer (struct sk_buff const*,int /*<<< orphan*/ ,int,struct ip_comp_hdr*) ; 

__attribute__((used)) static inline bool
spi_match(u_int32_t min, u_int32_t max, u_int32_t spi, bool invert)
{
	bool r;
	pr_debug("spi_match:%c 0x%x <= 0x%x <= 0x%x\n",
		 invert ? '!' : ' ', min, spi, max);
	r = (spi >= min && spi <= max) ^ invert;
	pr_debug(" result %s\n", r ? "PASS" : "FAILED");
	return r;
}

__attribute__((used)) static bool comp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	struct ip_comp_hdr _comphdr;
	const struct ip_comp_hdr *chdr;
	const struct xt_ipcomp *compinfo = par->matchinfo;

	/* Must not be a fragment. */
	if (par->fragoff != 0)
		return false;

	chdr = skb_header_pointer(skb, par->thoff, sizeof(_comphdr), &_comphdr);
	if (chdr == NULL) {
		/* We've been asked to examine this packet, and we
		 * can't.  Hence, no choice but to drop.
		 */
		pr_debug("Dropping evil IPComp tinygram.\n");
		par->hotdrop = true;
		return false;
	}

	return spi_match(compinfo->spis[0], compinfo->spis[1],
			 ntohs(chdr->cpi),
			 !!(compinfo->invflags & XT_IPCOMP_INV_SPI));
}

__attribute__((used)) static int comp_mt_check(const struct xt_mtchk_param *par)
{
	const struct xt_ipcomp *compinfo = par->matchinfo;

	/* Must specify no unknown invflags */
	if (compinfo->invflags & ~XT_IPCOMP_INV_MASK) {
		pr_info_ratelimited("unknown flags %X\n", compinfo->invflags);
		return -EINVAL;
	}
	return 0;
}

