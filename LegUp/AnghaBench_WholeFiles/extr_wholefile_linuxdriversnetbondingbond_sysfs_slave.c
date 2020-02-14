#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct slave_attribute {int /*<<< orphan*/  attr; int /*<<< orphan*/  (* show ) (struct slave*,char*) ;} ;
struct slave {int link_failure_count; int queue_id; int /*<<< orphan*/  kobj; TYPE_3__* dev; int /*<<< orphan*/  bond; int /*<<< orphan*/  perm_hwaddr; int /*<<< orphan*/  link; } ;
struct TYPE_5__ {int port_state; } ;
struct port {int actor_oper_port_state; TYPE_1__ partner_oper; struct aggregator* aggregator; } ;
struct kobject {int dummy; } ;
struct attribute {int dummy; } ;
struct aggregator {int aggregator_identifier; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_8__ {struct port port; } ;
struct TYPE_6__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_7__ {TYPE_2__ dev; } ;

/* Variables and functions */
 scalar_t__ BOND_MODE (int /*<<< orphan*/ ) ; 
 scalar_t__ BOND_MODE_8023AD ; 
#define  BOND_STATE_ACTIVE 129 
#define  BOND_STATE_BACKUP 128 
 TYPE_4__* SLAVE_AD_INFO (struct slave*) ; 
 char* bond_slave_link_status (int /*<<< orphan*/ ) ; 
 int bond_slave_state (struct slave*) ; 
 int kobject_init_and_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  kobject_put (int /*<<< orphan*/ *) ; 
 struct slave_attribute** slave_attrs ; 
 int /*<<< orphan*/  slave_ktype ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  stub1 (struct slave*,char*) ; 
 int sysfs_create_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct slave* to_slave (struct kobject*) ; 
 struct slave_attribute* to_slave_attr (struct attribute*) ; 

__attribute__((used)) static ssize_t state_show(struct slave *slave, char *buf)
{
	switch (bond_slave_state(slave)) {
	case BOND_STATE_ACTIVE:
		return sprintf(buf, "active\n");
	case BOND_STATE_BACKUP:
		return sprintf(buf, "backup\n");
	default:
		return sprintf(buf, "UNKNOWN\n");
	}
}

__attribute__((used)) static ssize_t mii_status_show(struct slave *slave, char *buf)
{
	return sprintf(buf, "%s\n", bond_slave_link_status(slave->link));
}

__attribute__((used)) static ssize_t link_failure_count_show(struct slave *slave, char *buf)
{
	return sprintf(buf, "%d\n", slave->link_failure_count);
}

__attribute__((used)) static ssize_t perm_hwaddr_show(struct slave *slave, char *buf)
{
	return sprintf(buf, "%pM\n", slave->perm_hwaddr);
}

__attribute__((used)) static ssize_t queue_id_show(struct slave *slave, char *buf)
{
	return sprintf(buf, "%d\n", slave->queue_id);
}

__attribute__((used)) static ssize_t ad_aggregator_id_show(struct slave *slave, char *buf)
{
	const struct aggregator *agg;

	if (BOND_MODE(slave->bond) == BOND_MODE_8023AD) {
		agg = SLAVE_AD_INFO(slave)->port.aggregator;
		if (agg)
			return sprintf(buf, "%d\n",
				       agg->aggregator_identifier);
	}

	return sprintf(buf, "N/A\n");
}

__attribute__((used)) static ssize_t ad_actor_oper_port_state_show(struct slave *slave, char *buf)
{
	const struct port *ad_port;

	if (BOND_MODE(slave->bond) == BOND_MODE_8023AD) {
		ad_port = &SLAVE_AD_INFO(slave)->port;
		if (ad_port->aggregator)
			return sprintf(buf, "%u\n",
				       ad_port->actor_oper_port_state);
	}

	return sprintf(buf, "N/A\n");
}

__attribute__((used)) static ssize_t ad_partner_oper_port_state_show(struct slave *slave, char *buf)
{
	const struct port *ad_port;

	if (BOND_MODE(slave->bond) == BOND_MODE_8023AD) {
		ad_port = &SLAVE_AD_INFO(slave)->port;
		if (ad_port->aggregator)
			return sprintf(buf, "%u\n",
				       ad_port->partner_oper.port_state);
	}

	return sprintf(buf, "N/A\n");
}

__attribute__((used)) static ssize_t slave_show(struct kobject *kobj,
			  struct attribute *attr, char *buf)
{
	struct slave_attribute *slave_attr = to_slave_attr(attr);
	struct slave *slave = to_slave(kobj);

	return slave_attr->show(slave, buf);
}

int bond_sysfs_slave_add(struct slave *slave)
{
	const struct slave_attribute **a;
	int err;

	err = kobject_init_and_add(&slave->kobj, &slave_ktype,
				   &(slave->dev->dev.kobj), "bonding_slave");
	if (err)
		return err;

	for (a = slave_attrs; *a; ++a) {
		err = sysfs_create_file(&slave->kobj, &((*a)->attr));
		if (err) {
			kobject_put(&slave->kobj);
			return err;
		}
	}

	return 0;
}

void bond_sysfs_slave_del(struct slave *slave)
{
	const struct slave_attribute **a;

	for (a = slave_attrs; *a; ++a)
		sysfs_remove_file(&slave->kobj, &((*a)->attr));

	kobject_put(&slave->kobj);
}

