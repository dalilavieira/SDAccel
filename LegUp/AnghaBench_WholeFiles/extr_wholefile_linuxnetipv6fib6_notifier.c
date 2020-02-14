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
struct notifier_block {int dummy; } ;
struct net {int dummy; } ;
struct fib_notifier_info {void* family; } ;
typedef  enum fib_event_type { ____Placeholder_fib_event_type } fib_event_type ;

/* Variables and functions */
 void* AF_INET6 ; 
 int call_fib_notifier (struct notifier_block*,struct net*,int,struct fib_notifier_info*) ; 
 int call_fib_notifiers (struct net*,int,struct fib_notifier_info*) ; 
 int fib6_rules_dump (struct net*,struct notifier_block*) ; 
 unsigned int fib6_rules_seq_read (struct net*) ; 
 int fib6_tables_dump (struct net*,struct notifier_block*) ; 
 unsigned int fib6_tables_seq_read (struct net*) ; 

int call_fib6_notifier(struct notifier_block *nb, struct net *net,
		       enum fib_event_type event_type,
		       struct fib_notifier_info *info)
{
	info->family = AF_INET6;
	return call_fib_notifier(nb, net, event_type, info);
}

int call_fib6_notifiers(struct net *net, enum fib_event_type event_type,
			struct fib_notifier_info *info)
{
	info->family = AF_INET6;
	return call_fib_notifiers(net, event_type, info);
}

__attribute__((used)) static unsigned int fib6_seq_read(struct net *net)
{
	return fib6_tables_seq_read(net) + fib6_rules_seq_read(net);
}

__attribute__((used)) static int fib6_dump(struct net *net, struct notifier_block *nb)
{
	int err;

	err = fib6_rules_dump(net, nb);
	if (err)
		return err;

	return fib6_tables_dump(net, nb);
}

