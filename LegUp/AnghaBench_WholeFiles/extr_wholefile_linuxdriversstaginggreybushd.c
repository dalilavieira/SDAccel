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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct ida {int dummy; } ;
struct device {int /*<<< orphan*/  dma_mask; struct device* parent; int /*<<< orphan*/  groups; int /*<<< orphan*/ * type; int /*<<< orphan*/ * bus; } ;
struct gb_host_device {int bus_id; int num_cports; size_t buffer_size_max; struct device dev; scalar_t__ svc; struct ida cport_id_map; int /*<<< orphan*/  connections; int /*<<< orphan*/  modules; struct gb_hd_driver* driver; } ;
struct gb_hd_driver {int (* output ) (struct gb_host_device*,void*,int,int /*<<< orphan*/ ,int) ;int (* cport_allocate ) (struct gb_host_device*,int,unsigned long) ;scalar_t__ hd_priv_size; int /*<<< orphan*/  message_cancel; int /*<<< orphan*/  message_send; int /*<<< orphan*/  (* cport_release ) (struct gb_host_device*,int) ;} ;
struct device_attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int CPORT_ID_MAX ; 
 int EINVAL ; 
 int ENOMEM ; 
 struct gb_host_device* ERR_PTR (int) ; 
 size_t GB_OPERATION_MESSAGE_SIZE_MAX ; 
 size_t GB_OPERATION_MESSAGE_SIZE_MIN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_groups ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_set_name (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,size_t) ; 
 int device_add (struct device*) ; 
 int /*<<< orphan*/  device_del (struct device*) ; 
 int /*<<< orphan*/  device_initialize (struct device*) ; 
 struct ida gb_hd_bus_id_map ; 
 int gb_svc_add (scalar_t__) ; 
 scalar_t__ gb_svc_create (struct gb_host_device*) ; 
 int /*<<< orphan*/  gb_svc_del (scalar_t__) ; 
 int /*<<< orphan*/  gb_svc_put (scalar_t__) ; 
 int /*<<< orphan*/  greybus_bus_type ; 
 int /*<<< orphan*/  greybus_hd_type ; 
 int /*<<< orphan*/  ida_destroy (struct ida*) ; 
 int /*<<< orphan*/  ida_init (struct ida*) ; 
 int ida_simple_get (struct ida*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ida_simple_remove (struct ida*,int) ; 
 int /*<<< orphan*/  kfree (struct gb_host_device*) ; 
 struct gb_host_device* kzalloc (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int stub1 (struct gb_host_device*,void*,int,int /*<<< orphan*/ ,int) ; 
 int stub2 (struct gb_host_device*,int,unsigned long) ; 
 int /*<<< orphan*/  stub3 (struct gb_host_device*,int) ; 
 struct gb_host_device* to_gb_host_device (struct device*) ; 
 int /*<<< orphan*/  trace_gb_hd_add (struct gb_host_device*) ; 
 int /*<<< orphan*/  trace_gb_hd_create (struct gb_host_device*) ; 
 int /*<<< orphan*/  trace_gb_hd_del (struct gb_host_device*) ; 
 int /*<<< orphan*/  trace_gb_hd_release (struct gb_host_device*) ; 

int gb_hd_output(struct gb_host_device *hd, void *req, u16 size, u8 cmd,
		 bool async)
{
	if (!hd || !hd->driver || !hd->driver->output)
		return -EINVAL;
	return hd->driver->output(hd, req, size, cmd, async);
}

__attribute__((used)) static ssize_t bus_id_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct gb_host_device *hd = to_gb_host_device(dev);

	return sprintf(buf, "%d\n", hd->bus_id);
}

int gb_hd_cport_reserve(struct gb_host_device *hd, u16 cport_id)
{
	struct ida *id_map = &hd->cport_id_map;
	int ret;

	ret = ida_simple_get(id_map, cport_id, cport_id + 1, GFP_KERNEL);
	if (ret < 0) {
		dev_err(&hd->dev, "failed to reserve cport %u\n", cport_id);
		return ret;
	}

	return 0;
}

void gb_hd_cport_release_reserved(struct gb_host_device *hd, u16 cport_id)
{
	struct ida *id_map = &hd->cport_id_map;

	ida_simple_remove(id_map, cport_id);
}

int gb_hd_cport_allocate(struct gb_host_device *hd, int cport_id,
				unsigned long flags)
{
	struct ida *id_map = &hd->cport_id_map;
	int ida_start, ida_end;

	if (hd->driver->cport_allocate)
		return hd->driver->cport_allocate(hd, cport_id, flags);

	if (cport_id < 0) {
		ida_start = 0;
		ida_end = hd->num_cports;
	} else if (cport_id < hd->num_cports) {
		ida_start = cport_id;
		ida_end = cport_id + 1;
	} else {
		dev_err(&hd->dev, "cport %d not available\n", cport_id);
		return -EINVAL;
	}

	return ida_simple_get(id_map, ida_start, ida_end, GFP_KERNEL);
}

void gb_hd_cport_release(struct gb_host_device *hd, u16 cport_id)
{
	if (hd->driver->cport_release) {
		hd->driver->cport_release(hd, cport_id);
		return;
	}

	ida_simple_remove(&hd->cport_id_map, cport_id);
}

__attribute__((used)) static void gb_hd_release(struct device *dev)
{
	struct gb_host_device *hd = to_gb_host_device(dev);

	trace_gb_hd_release(hd);

	if (hd->svc)
		gb_svc_put(hd->svc);
	ida_simple_remove(&gb_hd_bus_id_map, hd->bus_id);
	ida_destroy(&hd->cport_id_map);
	kfree(hd);
}

struct gb_host_device *gb_hd_create(struct gb_hd_driver *driver,
					struct device *parent,
					size_t buffer_size_max,
					size_t num_cports)
{
	struct gb_host_device *hd;
	int ret;

	/*
	 * Validate that the driver implements all of the callbacks
	 * so that we don't have to every time we make them.
	 */
	if ((!driver->message_send) || (!driver->message_cancel)) {
		dev_err(parent, "mandatory hd-callbacks missing\n");
		return ERR_PTR(-EINVAL);
	}

	if (buffer_size_max < GB_OPERATION_MESSAGE_SIZE_MIN) {
		dev_err(parent, "greybus host-device buffers too small\n");
		return ERR_PTR(-EINVAL);
	}

	if (num_cports == 0 || num_cports > CPORT_ID_MAX + 1) {
		dev_err(parent, "Invalid number of CPorts: %zu\n", num_cports);
		return ERR_PTR(-EINVAL);
	}

	/*
	 * Make sure to never allocate messages larger than what the Greybus
	 * protocol supports.
	 */
	if (buffer_size_max > GB_OPERATION_MESSAGE_SIZE_MAX) {
		dev_warn(parent, "limiting buffer size to %u\n",
			 GB_OPERATION_MESSAGE_SIZE_MAX);
		buffer_size_max = GB_OPERATION_MESSAGE_SIZE_MAX;
	}

	hd = kzalloc(sizeof(*hd) + driver->hd_priv_size, GFP_KERNEL);
	if (!hd)
		return ERR_PTR(-ENOMEM);

	ret = ida_simple_get(&gb_hd_bus_id_map, 1, 0, GFP_KERNEL);
	if (ret < 0) {
		kfree(hd);
		return ERR_PTR(ret);
	}
	hd->bus_id = ret;

	hd->driver = driver;
	INIT_LIST_HEAD(&hd->modules);
	INIT_LIST_HEAD(&hd->connections);
	ida_init(&hd->cport_id_map);
	hd->buffer_size_max = buffer_size_max;
	hd->num_cports = num_cports;

	hd->dev.parent = parent;
	hd->dev.bus = &greybus_bus_type;
	hd->dev.type = &greybus_hd_type;
	hd->dev.groups = bus_groups;
	hd->dev.dma_mask = hd->dev.parent->dma_mask;
	device_initialize(&hd->dev);
	dev_set_name(&hd->dev, "greybus%d", hd->bus_id);

	trace_gb_hd_create(hd);

	hd->svc = gb_svc_create(hd);
	if (!hd->svc) {
		dev_err(&hd->dev, "failed to create svc\n");
		put_device(&hd->dev);
		return ERR_PTR(-ENOMEM);
	}

	return hd;
}

int gb_hd_add(struct gb_host_device *hd)
{
	int ret;

	ret = device_add(&hd->dev);
	if (ret)
		return ret;

	ret = gb_svc_add(hd->svc);
	if (ret) {
		device_del(&hd->dev);
		return ret;
	}

	trace_gb_hd_add(hd);

	return 0;
}

void gb_hd_del(struct gb_host_device *hd)
{
	trace_gb_hd_del(hd);

	/*
	 * Tear down the svc and flush any on-going hotplug processing before
	 * removing the remaining interfaces.
	 */
	gb_svc_del(hd->svc);

	device_del(&hd->dev);
}

void gb_hd_shutdown(struct gb_host_device *hd)
{
	gb_svc_del(hd->svc);
}

void gb_hd_put(struct gb_host_device *hd)
{
	put_device(&hd->dev);
}

