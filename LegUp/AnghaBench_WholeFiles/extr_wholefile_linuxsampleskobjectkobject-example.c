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
struct kobject {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  name; } ;
struct kobj_attribute {TYPE_1__ attr; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int bar ; 
 int baz ; 
 int foo ; 
 int kstrtoint (char const*,int,int*) ; 
 int sprintf (char*,char*,int) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr,
			char *buf)
{
	return sprintf(buf, "%d\n", foo);
}

__attribute__((used)) static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
	int ret;

	ret = kstrtoint(buf, 10, &foo);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t b_show(struct kobject *kobj, struct kobj_attribute *attr,
		      char *buf)
{
	int var;

	if (strcmp(attr->attr.name, "baz") == 0)
		var = baz;
	else
		var = bar;
	return sprintf(buf, "%d\n", var);
}

__attribute__((used)) static ssize_t b_store(struct kobject *kobj, struct kobj_attribute *attr,
		       const char *buf, size_t count)
{
	int var, ret;

	ret = kstrtoint(buf, 10, &var);
	if (ret < 0)
		return ret;

	if (strcmp(attr->attr.name, "baz") == 0)
		baz = var;
	else
		bar = var;
	return count;
}

