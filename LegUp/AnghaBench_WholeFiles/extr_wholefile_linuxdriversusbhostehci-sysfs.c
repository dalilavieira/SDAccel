#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u8 ;
struct ehci_hcd {int uframe_periodic_max; int /*<<< orphan*/  lock; int /*<<< orphan*/ * bandwidth; int /*<<< orphan*/  companion_ports; int /*<<< orphan*/  hcs_params; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_3__ {struct device* controller; } ;
struct TYPE_4__ {TYPE_1__ self; } ;

/* Variables and functions */
 unsigned int EHCI_BANDWIDTH_SIZE ; 
 int EINVAL ; 
 int ENOENT ; 
 int HCS_N_PORTS (int /*<<< orphan*/ ) ; 
 int PAGE_SIZE ; 
 int PORT_OWNER ; 
 int /*<<< orphan*/  clear_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_attr_companion ; 
 int /*<<< orphan*/  dev_attr_uframe_periodic_max ; 
 int /*<<< orphan*/  dev_get_drvdata (struct device*) ; 
 int device_create_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ehci_info (struct ehci_hcd*,char*,int,...) ; 
 int /*<<< orphan*/  ehci_is_TDI (struct ehci_hcd*) ; 
 TYPE_2__* ehci_to_hcd (struct ehci_hcd*) ; 
 int /*<<< orphan*/  ehci_warn (struct ehci_hcd*,char*) ; 
 struct ehci_hcd* hcd_to_ehci (int /*<<< orphan*/ ) ; 
 scalar_t__ kstrtouint (char const*,int /*<<< orphan*/ ,unsigned int*) ; 
 unsigned int max (unsigned int,int /*<<< orphan*/ ) ; 
 int scnprintf (char*,int,char*,int) ; 
 int /*<<< orphan*/  set_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_owner (struct ehci_hcd*,int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int sscanf (char const*,char*,int*) ; 
 scalar_t__ test_bit (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t companion_show(struct device *dev,
			      struct device_attribute *attr,
			      char *buf)
{
	struct ehci_hcd		*ehci;
	int			nports, index, n;
	int			count = PAGE_SIZE;
	char			*ptr = buf;

	ehci = hcd_to_ehci(dev_get_drvdata(dev));
	nports = HCS_N_PORTS(ehci->hcs_params);

	for (index = 0; index < nports; ++index) {
		if (test_bit(index, &ehci->companion_ports)) {
			n = scnprintf(ptr, count, "%d\n", index + 1);
			ptr += n;
			count -= n;
		}
	}
	return ptr - buf;
}

__attribute__((used)) static ssize_t companion_store(struct device *dev,
			       struct device_attribute *attr,
			       const char *buf, size_t count)
{
	struct ehci_hcd		*ehci;
	int			portnum, new_owner;

	ehci = hcd_to_ehci(dev_get_drvdata(dev));
	new_owner = PORT_OWNER;		/* Owned by companion */
	if (sscanf(buf, "%d", &portnum) != 1)
		return -EINVAL;
	if (portnum < 0) {
		portnum = - portnum;
		new_owner = 0;		/* Owned by EHCI */
	}
	if (portnum <= 0 || portnum > HCS_N_PORTS(ehci->hcs_params))
		return -ENOENT;
	portnum--;
	if (new_owner)
		set_bit(portnum, &ehci->companion_ports);
	else
		clear_bit(portnum, &ehci->companion_ports);
	set_owner(ehci, portnum, new_owner);
	return count;
}

__attribute__((used)) static ssize_t uframe_periodic_max_show(struct device *dev,
					struct device_attribute *attr,
					char *buf)
{
	struct ehci_hcd		*ehci;
	int			n;

	ehci = hcd_to_ehci(dev_get_drvdata(dev));
	n = scnprintf(buf, PAGE_SIZE, "%d\n", ehci->uframe_periodic_max);
	return n;
}

__attribute__((used)) static ssize_t uframe_periodic_max_store(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	struct ehci_hcd		*ehci;
	unsigned		uframe_periodic_max;
	unsigned		uframe;
	unsigned long		flags;
	ssize_t			ret;

	ehci = hcd_to_ehci(dev_get_drvdata(dev));
	if (kstrtouint(buf, 0, &uframe_periodic_max) < 0)
		return -EINVAL;

	if (uframe_periodic_max < 100 || uframe_periodic_max >= 125) {
		ehci_info(ehci, "rejecting invalid request for "
				"uframe_periodic_max=%u\n", uframe_periodic_max);
		return -EINVAL;
	}

	ret = -EINVAL;

	/*
	 * lock, so that our checking does not race with possible periodic
	 * bandwidth allocation through submitting new urbs.
	 */
	spin_lock_irqsave (&ehci->lock, flags);

	/*
	 * for request to decrease max periodic bandwidth, we have to check
	 * to see whether the decrease is possible.
	 */
	if (uframe_periodic_max < ehci->uframe_periodic_max) {
		u8		allocated_max = 0;

		for (uframe = 0; uframe < EHCI_BANDWIDTH_SIZE; ++uframe)
			allocated_max = max(allocated_max,
					ehci->bandwidth[uframe]);

		if (allocated_max > uframe_periodic_max) {
			ehci_info(ehci,
				"cannot decrease uframe_periodic_max because "
				"periodic bandwidth is already allocated "
				"(%u > %u)\n",
				allocated_max, uframe_periodic_max);
			goto out_unlock;
		}
	}

	/* increasing is always ok */

	ehci_info(ehci, "setting max periodic bandwidth to %u%% "
			"(== %u usec/uframe)\n",
			100*uframe_periodic_max/125, uframe_periodic_max);

	if (uframe_periodic_max != 100)
		ehci_warn(ehci, "max periodic bandwidth set is non-standard\n");

	ehci->uframe_periodic_max = uframe_periodic_max;
	ret = count;

out_unlock:
	spin_unlock_irqrestore (&ehci->lock, flags);
	return ret;
}

__attribute__((used)) static inline int create_sysfs_files(struct ehci_hcd *ehci)
{
	struct device	*controller = ehci_to_hcd(ehci)->self.controller;
	int	i = 0;

	/* with integrated TT there is no companion! */
	if (!ehci_is_TDI(ehci))
		i = device_create_file(controller, &dev_attr_companion);
	if (i)
		goto out;

	i = device_create_file(controller, &dev_attr_uframe_periodic_max);
out:
	return i;
}

__attribute__((used)) static inline void remove_sysfs_files(struct ehci_hcd *ehci)
{
	struct device	*controller = ehci_to_hcd(ehci)->self.controller;

	/* with integrated TT there is no companion! */
	if (!ehci_is_TDI(ehci))
		device_remove_file(controller, &dev_attr_companion);

	device_remove_file(controller, &dev_attr_uframe_periodic_max);
}

