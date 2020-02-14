#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct nvif_ioctl_v0 {int dummy; } ;
struct nvif_ioctl_nop_v0 {int /*<<< orphan*/  version; } ;
struct nvif_client_v0 {int /*<<< orphan*/  name; int /*<<< orphan*/  device; } ;
struct TYPE_6__ {int /*<<< orphan*/  handle; struct nvif_client* client; int /*<<< orphan*/  priv; } ;
struct nvif_client {int super; int /*<<< orphan*/  version; TYPE_1__* driver; int /*<<< orphan*/  route; TYPE_2__ object; } ;
typedef  int /*<<< orphan*/  nop ;
typedef  int /*<<< orphan*/  args ;
struct TYPE_5__ {int (* ioctl ) (int /*<<< orphan*/ ,int,void*,int,int /*<<< orphan*/ *) ;int (* suspend ) (int /*<<< orphan*/ ) ;int (* resume ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* fini ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  NVIF_CLASS_CLIENT ; 
 int /*<<< orphan*/  NVIF_IOCTL_V0_ROUTE_NVIF ; 
 int /*<<< orphan*/  nvif_object_fini (TYPE_2__*) ; 
 int nvif_object_init (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nvif_client_v0*,int,TYPE_2__*) ; 
 int /*<<< orphan*/  strncpy (int /*<<< orphan*/ ,char const*,int) ; 
 int stub1 (int /*<<< orphan*/ ,int,void*,int,int /*<<< orphan*/ *) ; 
 int stub2 (int /*<<< orphan*/ ) ; 
 int stub3 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ) ; 

int
nvif_client_ioctl(struct nvif_client *client, void *data, u32 size)
{
	return client->driver->ioctl(client->object.priv, client->super, data, size, NULL);
}

int
nvif_client_suspend(struct nvif_client *client)
{
	return client->driver->suspend(client->object.priv);
}

int
nvif_client_resume(struct nvif_client *client)
{
	return client->driver->resume(client->object.priv);
}

void
nvif_client_fini(struct nvif_client *client)
{
	nvif_object_fini(&client->object);
	if (client->driver) {
		if (client->driver->fini)
			client->driver->fini(client->object.priv);
		client->driver = NULL;
	}
}

int
nvif_client_init(struct nvif_client *parent, const char *name, u64 device,
		 struct nvif_client *client)
{
	struct nvif_client_v0 args = { .device = device };
	struct {
		struct nvif_ioctl_v0 ioctl;
		struct nvif_ioctl_nop_v0 nop;
	} nop = {};
	int ret;

	strncpy(args.name, name, sizeof(args.name));
	ret = nvif_object_init(parent != client ? &parent->object : NULL,
			       0, NVIF_CLASS_CLIENT, &args, sizeof(args),
			       &client->object);
	if (ret)
		return ret;

	client->object.client = client;
	client->object.handle = ~0;
	client->route = NVIF_IOCTL_V0_ROUTE_NVIF;
	client->super = true;
	client->driver = parent->driver;

	if (ret == 0) {
		ret = nvif_client_ioctl(client, &nop, sizeof(nop));
		client->version = nop.nop.version;
	}

	if (ret)
		nvif_client_fini(client);
	return ret;
}

