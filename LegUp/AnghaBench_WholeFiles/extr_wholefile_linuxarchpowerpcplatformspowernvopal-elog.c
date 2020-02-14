#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
struct kobject {int /*<<< orphan*/  kset; } ;
struct file {int dummy; } ;
struct TYPE_4__ {char* name; int mode; } ;
struct TYPE_5__ {size_t size; size_t (* read ) (struct file*,struct kobject*,struct bin_attribute*,char*,int,size_t) ;TYPE_1__ attr; } ;
struct elog_obj {int id; int type; int size; struct kobject kobj; TYPE_2__ raw_attr; struct elog_obj* buffer; } ;
struct elog_attribute {size_t (* show ) (struct elog_obj*,struct elog_attribute*,char*) ;size_t (* store ) (struct elog_obj*,struct elog_attribute*,char const*,size_t) ;int /*<<< orphan*/  attr; } ;
struct bin_attribute {int dummy; } ;
struct attribute {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int loff_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  __be64 ;

/* Variables and functions */
 size_t EIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  KOBJ_ADD ; 
 int OPAL_MAX_ERRLOG_SIZE ; 
 int OPAL_SUCCESS ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  __pa (struct elog_obj*) ; 
 int be64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  elog_kset ; 
 int /*<<< orphan*/  elog_ktype ; 
 int /*<<< orphan*/  kfree (struct elog_obj*) ; 
 int kobject_add (struct kobject*,int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  kobject_init (struct kobject*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kobject_put (struct kobject*) ; 
 int /*<<< orphan*/  kobject_uevent (struct kobject*,int /*<<< orphan*/ ) ; 
 struct kobject* kset_find_obj (int /*<<< orphan*/ ,char*) ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,struct elog_obj*,size_t) ; 
 int opal_get_elog_size (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int opal_read_elog (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  opal_send_ack_elog (int) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 size_t sprintf (char*,char*,...) ; 
 size_t stub1 (struct elog_obj*,struct elog_attribute*,char*) ; 
 size_t stub2 (struct elog_obj*,struct elog_attribute*,char const*,size_t) ; 
 int /*<<< orphan*/  sysfs_bin_attr_init (TYPE_2__*) ; 
 int sysfs_create_bin_file (struct kobject*,TYPE_2__*) ; 
 int /*<<< orphan*/  sysfs_remove_file_self (struct kobject*,int /*<<< orphan*/ *) ; 
 struct elog_attribute* to_elog_attr (struct attribute*) ; 
 struct elog_obj* to_elog_obj (struct kobject*) ; 

__attribute__((used)) static ssize_t elog_id_show(struct elog_obj *elog_obj,
			    struct elog_attribute *attr,
			    char *buf)
{
	return sprintf(buf, "0x%llx\n", elog_obj->id);
}

__attribute__((used)) static const char *elog_type_to_string(uint64_t type)
{
	switch (type) {
	case 0: return "PEL";
	default: return "unknown";
	}
}

__attribute__((used)) static ssize_t elog_type_show(struct elog_obj *elog_obj,
			      struct elog_attribute *attr,
			      char *buf)
{
	return sprintf(buf, "0x%llx %s\n",
		       elog_obj->type,
		       elog_type_to_string(elog_obj->type));
}

__attribute__((used)) static ssize_t elog_ack_show(struct elog_obj *elog_obj,
			     struct elog_attribute *attr,
			     char *buf)
{
	return sprintf(buf, "ack - acknowledge log message\n");
}

__attribute__((used)) static ssize_t elog_ack_store(struct elog_obj *elog_obj,
			      struct elog_attribute *attr,
			      const char *buf,
			      size_t count)
{
	opal_send_ack_elog(elog_obj->id);
	sysfs_remove_file_self(&elog_obj->kobj, &attr->attr);
	kobject_put(&elog_obj->kobj);
	return count;
}

__attribute__((used)) static ssize_t elog_attr_show(struct kobject *kobj,
			      struct attribute *attr,
			      char *buf)
{
	struct elog_attribute *attribute;
	struct elog_obj *elog;

	attribute = to_elog_attr(attr);
	elog = to_elog_obj(kobj);

	if (!attribute->show)
		return -EIO;

	return attribute->show(elog, attribute, buf);
}

__attribute__((used)) static ssize_t elog_attr_store(struct kobject *kobj,
			       struct attribute *attr,
			       const char *buf, size_t len)
{
	struct elog_attribute *attribute;
	struct elog_obj *elog;

	attribute = to_elog_attr(attr);
	elog = to_elog_obj(kobj);

	if (!attribute->store)
		return -EIO;

	return attribute->store(elog, attribute, buf, len);
}

__attribute__((used)) static void elog_release(struct kobject *kobj)
{
	struct elog_obj *elog;

	elog = to_elog_obj(kobj);
	kfree(elog->buffer);
	kfree(elog);
}

__attribute__((used)) static ssize_t raw_attr_read(struct file *filep, struct kobject *kobj,
			     struct bin_attribute *bin_attr,
			     char *buffer, loff_t pos, size_t count)
{
	int opal_rc;

	struct elog_obj *elog = to_elog_obj(kobj);

	/* We may have had an error reading before, so let's retry */
	if (!elog->buffer) {
		elog->buffer = kzalloc(elog->size, GFP_KERNEL);
		if (!elog->buffer)
			return -EIO;

		opal_rc = opal_read_elog(__pa(elog->buffer),
					 elog->size, elog->id);
		if (opal_rc != OPAL_SUCCESS) {
			pr_err("ELOG: log read failed for log-id=%llx\n",
			       elog->id);
			kfree(elog->buffer);
			elog->buffer = NULL;
			return -EIO;
		}
	}

	memcpy(buffer, elog->buffer + pos, count);

	return count;
}

__attribute__((used)) static struct elog_obj *create_elog_obj(uint64_t id, size_t size, uint64_t type)
{
	struct elog_obj *elog;
	int rc;

	elog = kzalloc(sizeof(*elog), GFP_KERNEL);
	if (!elog)
		return NULL;

	elog->kobj.kset = elog_kset;

	kobject_init(&elog->kobj, &elog_ktype);

	sysfs_bin_attr_init(&elog->raw_attr);

	elog->raw_attr.attr.name = "raw";
	elog->raw_attr.attr.mode = 0400;
	elog->raw_attr.size = size;
	elog->raw_attr.read = raw_attr_read;

	elog->id = id;
	elog->size = size;
	elog->type = type;

	elog->buffer = kzalloc(elog->size, GFP_KERNEL);

	if (elog->buffer) {
		rc = opal_read_elog(__pa(elog->buffer),
					 elog->size, elog->id);
		if (rc != OPAL_SUCCESS) {
			pr_err("ELOG: log read failed for log-id=%llx\n",
			       elog->id);
			kfree(elog->buffer);
			elog->buffer = NULL;
		}
	}

	rc = kobject_add(&elog->kobj, NULL, "0x%llx", id);
	if (rc) {
		kobject_put(&elog->kobj);
		return NULL;
	}

	rc = sysfs_create_bin_file(&elog->kobj, &elog->raw_attr);
	if (rc) {
		kobject_put(&elog->kobj);
		return NULL;
	}

	kobject_uevent(&elog->kobj, KOBJ_ADD);

	return elog;
}

__attribute__((used)) static irqreturn_t elog_event(int irq, void *data)
{
	__be64 size;
	__be64 id;
	__be64 type;
	uint64_t elog_size;
	uint64_t log_id;
	uint64_t elog_type;
	int rc;
	char name[2+16+1];
	struct kobject *kobj;

	rc = opal_get_elog_size(&id, &size, &type);
	if (rc != OPAL_SUCCESS) {
		pr_err("ELOG: OPAL log info read failed\n");
		return IRQ_HANDLED;
	}

	elog_size = be64_to_cpu(size);
	log_id = be64_to_cpu(id);
	elog_type = be64_to_cpu(type);

	WARN_ON(elog_size > OPAL_MAX_ERRLOG_SIZE);

	if (elog_size >= OPAL_MAX_ERRLOG_SIZE)
		elog_size  =  OPAL_MAX_ERRLOG_SIZE;

	sprintf(name, "0x%llx", log_id);

	/* we may get notified twice, let's handle
	 * that gracefully and not create two conflicting
	 * entries.
	 */
	kobj = kset_find_obj(elog_kset, name);
	if (kobj) {
		/* Drop reference added by kset_find_obj() */
		kobject_put(kobj);
		return IRQ_HANDLED;
	}

	create_elog_obj(log_id, elog_size, elog_type);

	return IRQ_HANDLED;
}

