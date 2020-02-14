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
typedef  scalar_t__ u8 ;
struct TYPE_2__ {int (* get_exception ) () ;int /*<<< orphan*/  (* assert_event ) (unsigned int) ;} ;

/* Variables and functions */
 scalar_t__* c6x_fuse_mac ; 
 unsigned int c6x_num_cores ; 
 scalar_t__* cmdline_mac ; 
 int /*<<< orphan*/  eth_random_addr (scalar_t__*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__*,int) ; 
 TYPE_1__ soc_ops ; 
 int stub1 () ; 
 int /*<<< orphan*/  stub2 (unsigned int) ; 

int soc_get_exception(void)
{
	if (!soc_ops.get_exception)
		return -1;
	return soc_ops.get_exception();
}

void soc_assert_event(unsigned int evt)
{
	if (soc_ops.assert_event)
		soc_ops.assert_event(evt);
}

int soc_mac_addr(unsigned int index, u8 *addr)
{
	int i, have_dt_mac = 0, have_cmdline_mac = 0, have_fuse_mac = 0;

	for (i = 0; i < 6; i++) {
		if (cmdline_mac[i])
			have_cmdline_mac = 1;
		if (c6x_fuse_mac[i])
			have_fuse_mac = 1;
		if (addr[i])
			have_dt_mac = 1;
	}

	/* cmdline overrides all */
	if (have_cmdline_mac)
		memcpy(addr, cmdline_mac, 6);
	else if (!have_dt_mac) {
		if (have_fuse_mac)
			memcpy(addr, c6x_fuse_mac, 6);
		else
			eth_random_addr(addr);
	}

	/* adjust for specific EMAC device */
	addr[5] += index * c6x_num_cores;
	return 1;
}

