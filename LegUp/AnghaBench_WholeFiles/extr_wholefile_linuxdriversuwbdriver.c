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
struct uwb_rc {int /*<<< orphan*/  uwb_dev; } ;
struct uwb_dev {int /*<<< orphan*/  dev; } ;
struct uwb_beca_e {int /*<<< orphan*/  refcnt; } ;
struct class_attribute {int dummy; } ;
struct class {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 unsigned long beacon_timeout_ms ; 
 int /*<<< orphan*/  device_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int scnprintf (char*,int /*<<< orphan*/ ,char*,unsigned long) ; 
 int sscanf (char const*,char*,unsigned long*) ; 
 int /*<<< orphan*/  uwb_bce_kfree ; 
 int /*<<< orphan*/  uwb_dev_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uwb_dev_put (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline struct uwb_rc *__uwb_rc_get(struct uwb_rc *rc)
{
	uwb_dev_get(&rc->uwb_dev);
	return rc;
}

__attribute__((used)) static inline void __uwb_rc_put(struct uwb_rc *rc)
{
	if (rc)
		uwb_dev_put(&rc->uwb_dev);
}

__attribute__((used)) static inline void uwb_bce_get(struct uwb_beca_e *bce)
{
	kref_get(&bce->refcnt);
}

__attribute__((used)) static inline void uwb_bce_put(struct uwb_beca_e *bce)
{
	kref_put(&bce->refcnt, uwb_bce_kfree);
}

__attribute__((used)) static inline void uwb_dev_lock(struct uwb_dev *uwb_dev)
{
	device_lock(&uwb_dev->dev);
}

__attribute__((used)) static inline void uwb_dev_unlock(struct uwb_dev *uwb_dev)
{
	device_unlock(&uwb_dev->dev);
}

__attribute__((used)) static
ssize_t beacon_timeout_ms_show(struct class *class,
				struct class_attribute *attr,
				char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "%lu\n", beacon_timeout_ms);
}

__attribute__((used)) static
ssize_t beacon_timeout_ms_store(struct class *class,
				struct class_attribute *attr,
				const char *buf, size_t size)
{
	unsigned long bt;
	ssize_t result;
	result = sscanf(buf, "%lu", &bt);
	if (result != 1)
		return -EINVAL;
	beacon_timeout_ms = bt;
	return size;
}

