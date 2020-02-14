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
struct wimax_dev {int state; int (* op_reset ) (struct wimax_dev*) ;int /*<<< orphan*/  net_dev; int /*<<< orphan*/  mutex_reset; int /*<<< orphan*/  mutex; } ;
struct sk_buff {int dummy; } ;
struct genl_info {int /*<<< orphan*/ ** attrs; } ;
struct device {int dummy; } ;
typedef  enum wimax_st { ____Placeholder_wimax_st } wimax_st ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 size_t WIMAX_GNL_RESET_IFIDX ; 
 int WIMAX_ST_DOWN ; 
 int /*<<< orphan*/  d_fnend (int,int /*<<< orphan*/ *,char*,struct wimax_dev*,...) ; 
 int /*<<< orphan*/  d_fnstart (int,int /*<<< orphan*/ *,char*,struct wimax_dev*,...) ; 
 int /*<<< orphan*/  dev_hold (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  might_sleep () ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int nla_get_u32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int stub1 (struct wimax_dev*) ; 
 struct wimax_dev* wimax_dev_get_by_genl_info (struct genl_info*,int) ; 
 struct device* wimax_dev_to_dev (struct wimax_dev*) ; 

int wimax_reset(struct wimax_dev *wimax_dev)
{
	int result = -EINVAL;
	struct device *dev = wimax_dev_to_dev(wimax_dev);
	enum wimax_st state;

	might_sleep();
	d_fnstart(3, dev, "(wimax_dev %p)\n", wimax_dev);
	mutex_lock(&wimax_dev->mutex);
	dev_hold(wimax_dev->net_dev);
	state = wimax_dev->state;
	mutex_unlock(&wimax_dev->mutex);

	if (state >= WIMAX_ST_DOWN) {
		mutex_lock(&wimax_dev->mutex_reset);
		result = wimax_dev->op_reset(wimax_dev);
		mutex_unlock(&wimax_dev->mutex_reset);
	}
	dev_put(wimax_dev->net_dev);

	d_fnend(3, dev, "(wimax_dev %p) = %d\n", wimax_dev, result);
	return result;
}

int wimax_gnl_doit_reset(struct sk_buff *skb, struct genl_info *info)
{
	int result, ifindex;
	struct wimax_dev *wimax_dev;

	d_fnstart(3, NULL, "(skb %p info %p)\n", skb, info);
	result = -ENODEV;
	if (info->attrs[WIMAX_GNL_RESET_IFIDX] == NULL) {
		pr_err("WIMAX_GNL_OP_RFKILL: can't find IFIDX attribute\n");
		goto error_no_wimax_dev;
	}
	ifindex = nla_get_u32(info->attrs[WIMAX_GNL_RESET_IFIDX]);
	wimax_dev = wimax_dev_get_by_genl_info(info, ifindex);
	if (wimax_dev == NULL)
		goto error_no_wimax_dev;
	/* Execute the operation and send the result back to user space */
	result = wimax_reset(wimax_dev);
	dev_put(wimax_dev->net_dev);
error_no_wimax_dev:
	d_fnend(3, NULL, "(skb %p info %p) = %d\n", skb, info, result);
	return result;
}

