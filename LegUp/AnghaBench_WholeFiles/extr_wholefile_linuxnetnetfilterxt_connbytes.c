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
typedef  scalar_t__ u_int64_t ;
struct xt_mtdtor_param {int /*<<< orphan*/  family; int /*<<< orphan*/  net; } ;
struct xt_mtchk_param {int /*<<< orphan*/  net; int /*<<< orphan*/  family; struct xt_connbytes_info* matchinfo; } ;
struct TYPE_2__ {scalar_t__ to; scalar_t__ from; } ;
struct xt_connbytes_info {int what; int const direction; TYPE_1__ count; } ;
struct xt_action_param {struct xt_connbytes_info* matchinfo; } ;
struct sk_buff {int dummy; } ;
struct nf_conn_counter {int /*<<< orphan*/  packets; int /*<<< orphan*/  bytes; } ;
struct nf_conn_acct {struct nf_conn_counter* counter; } ;
struct nf_conn {int dummy; } ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;

/* Variables and functions */
 int EINVAL ; 
 size_t IP_CT_DIR_ORIGINAL ; 
 size_t IP_CT_DIR_REPLY ; 
#define  XT_CONNBYTES_AVGPKT 133 
#define  XT_CONNBYTES_BYTES 132 
#define  XT_CONNBYTES_DIR_BOTH 131 
#define  XT_CONNBYTES_DIR_ORIGINAL 130 
#define  XT_CONNBYTES_DIR_REPLY 129 
#define  XT_CONNBYTES_PKTS 128 
 scalar_t__ atomic64_read (int /*<<< orphan*/ *) ; 
 scalar_t__ div64_u64 (scalar_t__,scalar_t__) ; 
 struct nf_conn_acct* nf_conn_acct_find (struct nf_conn const*) ; 
 int /*<<< orphan*/  nf_ct_acct_enabled (int /*<<< orphan*/ ) ; 
 struct nf_conn* nf_ct_get (struct sk_buff const*,int*) ; 
 int nf_ct_netns_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_netns_put (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_ct_set_acct (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 

__attribute__((used)) static bool
connbytes_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_connbytes_info *sinfo = par->matchinfo;
	const struct nf_conn *ct;
	enum ip_conntrack_info ctinfo;
	u_int64_t what = 0;	/* initialize to make gcc happy */
	u_int64_t bytes = 0;
	u_int64_t pkts = 0;
	const struct nf_conn_acct *acct;
	const struct nf_conn_counter *counters;

	ct = nf_ct_get(skb, &ctinfo);
	if (!ct)
		return false;

	acct = nf_conn_acct_find(ct);
	if (!acct)
		return false;

	counters = acct->counter;
	switch (sinfo->what) {
	case XT_CONNBYTES_PKTS:
		switch (sinfo->direction) {
		case XT_CONNBYTES_DIR_ORIGINAL:
			what = atomic64_read(&counters[IP_CT_DIR_ORIGINAL].packets);
			break;
		case XT_CONNBYTES_DIR_REPLY:
			what = atomic64_read(&counters[IP_CT_DIR_REPLY].packets);
			break;
		case XT_CONNBYTES_DIR_BOTH:
			what = atomic64_read(&counters[IP_CT_DIR_ORIGINAL].packets);
			what += atomic64_read(&counters[IP_CT_DIR_REPLY].packets);
			break;
		}
		break;
	case XT_CONNBYTES_BYTES:
		switch (sinfo->direction) {
		case XT_CONNBYTES_DIR_ORIGINAL:
			what = atomic64_read(&counters[IP_CT_DIR_ORIGINAL].bytes);
			break;
		case XT_CONNBYTES_DIR_REPLY:
			what = atomic64_read(&counters[IP_CT_DIR_REPLY].bytes);
			break;
		case XT_CONNBYTES_DIR_BOTH:
			what = atomic64_read(&counters[IP_CT_DIR_ORIGINAL].bytes);
			what += atomic64_read(&counters[IP_CT_DIR_REPLY].bytes);
			break;
		}
		break;
	case XT_CONNBYTES_AVGPKT:
		switch (sinfo->direction) {
		case XT_CONNBYTES_DIR_ORIGINAL:
			bytes = atomic64_read(&counters[IP_CT_DIR_ORIGINAL].bytes);
			pkts  = atomic64_read(&counters[IP_CT_DIR_ORIGINAL].packets);
			break;
		case XT_CONNBYTES_DIR_REPLY:
			bytes = atomic64_read(&counters[IP_CT_DIR_REPLY].bytes);
			pkts  = atomic64_read(&counters[IP_CT_DIR_REPLY].packets);
			break;
		case XT_CONNBYTES_DIR_BOTH:
			bytes = atomic64_read(&counters[IP_CT_DIR_ORIGINAL].bytes) +
				atomic64_read(&counters[IP_CT_DIR_REPLY].bytes);
			pkts  = atomic64_read(&counters[IP_CT_DIR_ORIGINAL].packets) +
				atomic64_read(&counters[IP_CT_DIR_REPLY].packets);
			break;
		}
		if (pkts != 0)
			what = div64_u64(bytes, pkts);
		break;
	}

	if (sinfo->count.to >= sinfo->count.from)
		return what <= sinfo->count.to && what >= sinfo->count.from;
	else /* inverted */
		return what < sinfo->count.to || what > sinfo->count.from;
}

__attribute__((used)) static int connbytes_mt_check(const struct xt_mtchk_param *par)
{
	const struct xt_connbytes_info *sinfo = par->matchinfo;
	int ret;

	if (sinfo->what != XT_CONNBYTES_PKTS &&
	    sinfo->what != XT_CONNBYTES_BYTES &&
	    sinfo->what != XT_CONNBYTES_AVGPKT)
		return -EINVAL;

	if (sinfo->direction != XT_CONNBYTES_DIR_ORIGINAL &&
	    sinfo->direction != XT_CONNBYTES_DIR_REPLY &&
	    sinfo->direction != XT_CONNBYTES_DIR_BOTH)
		return -EINVAL;

	ret = nf_ct_netns_get(par->net, par->family);
	if (ret < 0)
		pr_info_ratelimited("cannot load conntrack support for proto=%u\n",
				    par->family);

	/*
	 * This filter cannot function correctly unless connection tracking
	 * accounting is enabled, so complain in the hope that someone notices.
	 */
	if (!nf_ct_acct_enabled(par->net)) {
		pr_warn("Forcing CT accounting to be enabled\n");
		nf_ct_set_acct(par->net, true);
	}

	return ret;
}

__attribute__((used)) static void connbytes_mt_destroy(const struct xt_mtdtor_param *par)
{
	nf_ct_netns_put(par->net, par->family);
}

