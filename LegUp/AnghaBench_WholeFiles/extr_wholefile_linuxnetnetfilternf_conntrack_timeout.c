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
struct nf_ct_timeout {int dummy; } ;
struct nf_conn_timeout {void* timeout; } ;
struct nf_conn {int dummy; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RCU_INIT_POINTER (void*,int /*<<< orphan*/ *) ; 
 int nf_ct_extend_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nf_ct_extend_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nf_ct_iterate_cleanup_net (struct net*,int (*) (struct nf_conn*,void*),struct nf_ct_timeout*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct nf_conn_timeout* nf_ct_timeout_find (struct nf_conn*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  timeout_extend ; 

__attribute__((used)) static int untimeout(struct nf_conn *ct, void *timeout)
{
	struct nf_conn_timeout *timeout_ext = nf_ct_timeout_find(ct);

	if (timeout_ext && (!timeout || timeout_ext->timeout == timeout))
		RCU_INIT_POINTER(timeout_ext->timeout, NULL);

	/* We are not intended to delete this conntrack. */
	return 0;
}

void nf_ct_untimeout(struct net *net, struct nf_ct_timeout *timeout)
{
	nf_ct_iterate_cleanup_net(net, untimeout, timeout, 0, 0);
}

int nf_conntrack_timeout_init(void)
{
	int ret = nf_ct_extend_register(&timeout_extend);
	if (ret < 0)
		pr_err("nf_ct_timeout: Unable to register timeout extension.\n");
	return ret;
}

void nf_conntrack_timeout_fini(void)
{
	nf_ct_extend_unregister(&timeout_extend);
}

