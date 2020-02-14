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
struct TYPE_2__ {int /*<<< orphan*/  sysctl_tstamp; } ;
struct net {TYPE_1__ ct; } ;

/* Variables and functions */
 int nf_ct_extend_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nf_ct_extend_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nf_ct_tstamp ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  tstamp_extend ; 

__attribute__((used)) static int nf_conntrack_tstamp_init_sysctl(struct net *net)
{
	return 0;
}

__attribute__((used)) static void nf_conntrack_tstamp_fini_sysctl(struct net *net)
{
}

int nf_conntrack_tstamp_pernet_init(struct net *net)
{
	net->ct.sysctl_tstamp = nf_ct_tstamp;
	return nf_conntrack_tstamp_init_sysctl(net);
}

void nf_conntrack_tstamp_pernet_fini(struct net *net)
{
	nf_conntrack_tstamp_fini_sysctl(net);
}

int nf_conntrack_tstamp_init(void)
{
	int ret;
	ret = nf_ct_extend_register(&tstamp_extend);
	if (ret < 0)
		pr_err("Unable to register extension\n");
	return ret;
}

void nf_conntrack_tstamp_fini(void)
{
	nf_ct_extend_unregister(&tstamp_extend);
}

