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
typedef  size_t u32 ;
struct qedi_ctx {int /*<<< orphan*/  cdev; int /*<<< orphan*/  link_state; } ;
struct qed_link_output {int speed; } ;
struct qed_iscsi_tid {void** blocks; size_t num_tids_per_block; size_t size; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct Scsi_Host {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_4__ {TYPE_1__* common; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* get_link ) (int /*<<< orphan*/ ,struct qed_link_output*) ;} ;

/* Variables and functions */
 scalar_t__ QEDI_LINK_UP ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 struct Scsi_Host* class_to_shost (struct device*) ; 
 struct qedi_ctx* iscsi_host_priv (struct Scsi_Host*) ; 
 TYPE_2__* qedi_ops ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,struct qed_link_output*) ; 

__attribute__((used)) static inline void *qedi_get_task_mem(struct qed_iscsi_tid *info, u32 tid)
{
	return (info->blocks[tid / info->num_tids_per_block] +
		(tid % info->num_tids_per_block) * info->size);
}

__attribute__((used)) static inline struct qedi_ctx *qedi_dev_to_hba(struct device *dev)
{
	struct Scsi_Host *shost = class_to_shost(dev);

	return iscsi_host_priv(shost);
}

__attribute__((used)) static ssize_t qedi_show_port_state(struct device *dev,
				    struct device_attribute *attr,
				    char *buf)
{
	struct qedi_ctx *qedi = qedi_dev_to_hba(dev);

	if (atomic_read(&qedi->link_state) == QEDI_LINK_UP)
		return sprintf(buf, "Online\n");
	else
		return sprintf(buf, "Linkdown\n");
}

__attribute__((used)) static ssize_t qedi_show_speed(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct qedi_ctx *qedi = qedi_dev_to_hba(dev);
	struct qed_link_output if_link;

	qedi_ops->common->get_link(qedi->cdev, &if_link);

	return sprintf(buf, "%d Gbit\n", if_link.speed / 1000);
}

