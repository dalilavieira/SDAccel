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
struct notifier_block {int dummy; } ;
struct TYPE_2__ {unsigned int fib_seq; } ;
struct net {TYPE_1__ ipv4; } ;
struct fib_notifier_info {void* family; } ;
typedef  enum fib_event_type { ____Placeholder_fib_event_type } fib_event_type ;

/* Variables and functions */
 void* AF_INET ; 
 int /*<<< orphan*/  ASSERT_RTNL () ; 
 int call_fib_notifier (struct notifier_block*,struct net*,int,struct fib_notifier_info*) ; 
 int call_fib_notifiers (struct net*,int,struct fib_notifier_info*) ; 
 int fib4_rules_dump (struct net*,struct notifier_block*) ; 
 unsigned int fib4_rules_seq_read (struct net*) ; 
 int /*<<< orphan*/  fib_notify (struct net*,struct notifier_block*) ; 

int call_fib4_notifier(struct notifier_block *nb, struct net *net,
		       enum fib_event_type event_type,
		       struct fib_notifier_info *info)
{
	info->family = AF_INET;
	return call_fib_notifier(nb, net, event_type, info);
}

int call_fib4_notifiers(struct net *net, enum fib_event_type event_type,
			struct fib_notifier_info *info)
{
	ASSERT_RTNL();

	info->family = AF_INET;
	net->ipv4.fib_seq++;
	return call_fib_notifiers(net, event_type, info);
}

__attribute__((used)) static unsigned int fib4_seq_read(struct net *net)
{
	ASSERT_RTNL();

	return net->ipv4.fib_seq + fib4_rules_seq_read(net);
}

__attribute__((used)) static int fib4_dump(struct net *net, struct notifier_block *nb)
{
	int err;

	err = fib4_rules_dump(net, nb);
	if (err)
		return err;

	fib_notify(net, nb);

	return 0;
}

