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

/* Variables and functions */
 int atomic_notifier_call_chain (int /*<<< orphan*/ *,unsigned long,void*) ; 
 int atomic_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int atomic_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  netevent_notif_chain ; 

int register_netevent_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_register(&netevent_notif_chain, nb);
}

int unregister_netevent_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_unregister(&netevent_notif_chain, nb);
}

int call_netevent_notifiers(unsigned long val, void *v)
{
	return atomic_notifier_call_chain(&netevent_notif_chain, val, v);
}

