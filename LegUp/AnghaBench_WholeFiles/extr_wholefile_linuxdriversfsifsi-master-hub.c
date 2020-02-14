#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  int uint32_t ;
typedef  int u32 ;
struct TYPE_5__ {void (* release ) (struct device*) ;int /*<<< orphan*/  of_node; struct device* parent; } ;
struct TYPE_6__ {int n_links; int (* read ) (struct fsi_master*,int,scalar_t__,int,void*,size_t) ;int (* write ) (struct fsi_master*,int,scalar_t__,int,void const*,size_t) ;int (* send_break ) (struct fsi_master*,int) ;int (* link_enable ) (struct fsi_master*,int) ;TYPE_1__ dev; } ;
struct fsi_master_hub {int size; TYPE_3__ master; scalar_t__ addr; struct fsi_device* upstream; } ;
struct fsi_master {int dummy; } ;
struct fsi_device {int /*<<< orphan*/  slave; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  reg ;
typedef  int /*<<< orphan*/  cmd ;
typedef  int /*<<< orphan*/  __reg ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ FSI_HUB_LINK_OFFSET ; 
 int FSI_HUB_LINK_SIZE ; 
 int /*<<< orphan*/  FSI_LINK_ENABLE_SETUP_TIME ; 
 scalar_t__ FSI_MAEB ; 
 scalar_t__ FSI_MCENP0 ; 
 scalar_t__ FSI_MDLYR ; 
 scalar_t__ FSI_MECTRL ; 
 int FSI_MECTRL_EOAE ; 
 int FSI_MECTRL_P8_AUTO_TERM ; 
 scalar_t__ FSI_MENP0 ; 
 scalar_t__ FSI_MLEVP0 ; 
 scalar_t__ FSI_MMODE ; 
 int FSI_MMODE_CRS0MASK ; 
 int FSI_MMODE_CRS0SHFT ; 
 int FSI_MMODE_CRS1MASK ; 
 int FSI_MMODE_CRS1SHFT ; 
 int FSI_MMODE_ECRC ; 
 int FSI_MMODE_EIP ; 
 int FSI_MMODE_EPC ; 
 int FSI_MMODE_P8_TO_LSB ; 
 scalar_t__ FSI_MRESB0 ; 
 int FSI_MRESB_RST_ERR ; 
 int FSI_MRESB_RST_GEN ; 
 scalar_t__ FSI_MRESP0 ; 
 int FSI_MRESP_RST_ALL_LINK ; 
 int FSI_MRESP_RST_ALL_MASTER ; 
 int FSI_MRESP_RST_MCR ; 
 int FSI_MRESP_RST_PYE ; 
 scalar_t__ FSI_MSENP0 ; 
 scalar_t__ FSI_MVER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct fsi_master_hub* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_of_node (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct fsi_master_hub*) ; 
 struct fsi_master* dev_to_fsi_master (struct device*) ; 
 int fsi_device_read (struct fsi_device*,scalar_t__,int /*<<< orphan*/ *,int) ; 
 int fsi_device_write (struct fsi_device*,scalar_t__,int /*<<< orphan*/ *,int) ; 
 int fsi_master_register (TYPE_3__*) ; 
 int /*<<< orphan*/  fsi_master_unregister (TYPE_3__*) ; 
 int fsi_slave_claim_range (int /*<<< orphan*/ ,scalar_t__,int) ; 
 int fsi_slave_read (int /*<<< orphan*/ ,int,void*,size_t) ; 
 int /*<<< orphan*/  fsi_slave_release_range (int /*<<< orphan*/ ,scalar_t__,int) ; 
 int fsi_slave_write (int /*<<< orphan*/ ,int,void const*,size_t) ; 
 int /*<<< orphan*/  get_device (TYPE_1__*) ; 
 int /*<<< orphan*/  kfree (struct fsi_master_hub*) ; 
 struct fsi_master_hub* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_device (TYPE_1__*) ; 
 struct fsi_device* to_fsi_dev (struct device*) ; 
 struct fsi_master_hub* to_fsi_master_hub (struct fsi_master*) ; 

__attribute__((used)) static int hub_master_read(struct fsi_master *master, int link,
			uint8_t id, uint32_t addr, void *val, size_t size)
{
	struct fsi_master_hub *hub = to_fsi_master_hub(master);

	if (id != 0)
		return -EINVAL;

	addr += hub->addr + (link * FSI_HUB_LINK_SIZE);
	return fsi_slave_read(hub->upstream->slave, addr, val, size);
}

__attribute__((used)) static int hub_master_write(struct fsi_master *master, int link,
			uint8_t id, uint32_t addr, const void *val, size_t size)
{
	struct fsi_master_hub *hub = to_fsi_master_hub(master);

	if (id != 0)
		return -EINVAL;

	addr += hub->addr + (link * FSI_HUB_LINK_SIZE);
	return fsi_slave_write(hub->upstream->slave, addr, val, size);
}

__attribute__((used)) static int hub_master_break(struct fsi_master *master, int link)
{
	uint32_t addr;
	__be32 cmd;

	addr = 0x4;
	cmd = cpu_to_be32(0xc0de0000);

	return hub_master_write(master, link, 0, addr, &cmd, sizeof(cmd));
}

__attribute__((used)) static int hub_master_link_enable(struct fsi_master *master, int link)
{
	struct fsi_master_hub *hub = to_fsi_master_hub(master);
	int idx, bit;
	__be32 reg;
	int rc;

	idx = link / 32;
	bit = link % 32;

	reg = cpu_to_be32(0x80000000 >> bit);

	rc = fsi_device_write(hub->upstream, FSI_MSENP0 + (4 * idx), &reg, 4);

	mdelay(FSI_LINK_ENABLE_SETUP_TIME);

	fsi_device_read(hub->upstream, FSI_MENP0 + (4 * idx), &reg, 4);

	return rc;
}

__attribute__((used)) static void hub_master_release(struct device *dev)
{
	struct fsi_master_hub *hub = to_fsi_master_hub(dev_to_fsi_master(dev));

	kfree(hub);
}

__attribute__((used)) static inline u32 fsi_mmode_crs0(u32 x)
{
	return (x & FSI_MMODE_CRS0MASK) << FSI_MMODE_CRS0SHFT;
}

__attribute__((used)) static inline u32 fsi_mmode_crs1(u32 x)
{
	return (x & FSI_MMODE_CRS1MASK) << FSI_MMODE_CRS1SHFT;
}

__attribute__((used)) static int hub_master_init(struct fsi_master_hub *hub)
{
	struct fsi_device *dev = hub->upstream;
	__be32 reg;
	int rc;

	reg = cpu_to_be32(FSI_MRESP_RST_ALL_MASTER | FSI_MRESP_RST_ALL_LINK
			| FSI_MRESP_RST_MCR | FSI_MRESP_RST_PYE);
	rc = fsi_device_write(dev, FSI_MRESP0, &reg, sizeof(reg));
	if (rc)
		return rc;

	/* Initialize the MFSI (hub master) engine */
	reg = cpu_to_be32(FSI_MRESP_RST_ALL_MASTER | FSI_MRESP_RST_ALL_LINK
			| FSI_MRESP_RST_MCR | FSI_MRESP_RST_PYE);
	rc = fsi_device_write(dev, FSI_MRESP0, &reg, sizeof(reg));
	if (rc)
		return rc;

	reg = cpu_to_be32(FSI_MECTRL_EOAE | FSI_MECTRL_P8_AUTO_TERM);
	rc = fsi_device_write(dev, FSI_MECTRL, &reg, sizeof(reg));
	if (rc)
		return rc;

	reg = cpu_to_be32(FSI_MMODE_EIP | FSI_MMODE_ECRC | FSI_MMODE_EPC
			| fsi_mmode_crs0(1) | fsi_mmode_crs1(1)
			| FSI_MMODE_P8_TO_LSB);
	rc = fsi_device_write(dev, FSI_MMODE, &reg, sizeof(reg));
	if (rc)
		return rc;

	reg = cpu_to_be32(0xffff0000);
	rc = fsi_device_write(dev, FSI_MDLYR, &reg, sizeof(reg));
	if (rc)
		return rc;

	reg = cpu_to_be32(~0);
	rc = fsi_device_write(dev, FSI_MSENP0, &reg, sizeof(reg));
	if (rc)
		return rc;

	/* Leave enabled long enough for master logic to set up */
	mdelay(FSI_LINK_ENABLE_SETUP_TIME);

	rc = fsi_device_write(dev, FSI_MCENP0, &reg, sizeof(reg));
	if (rc)
		return rc;

	rc = fsi_device_read(dev, FSI_MAEB, &reg, sizeof(reg));
	if (rc)
		return rc;

	reg = cpu_to_be32(FSI_MRESP_RST_ALL_MASTER | FSI_MRESP_RST_ALL_LINK);
	rc = fsi_device_write(dev, FSI_MRESP0, &reg, sizeof(reg));
	if (rc)
		return rc;

	rc = fsi_device_read(dev, FSI_MLEVP0, &reg, sizeof(reg));
	if (rc)
		return rc;

	/* Reset the master bridge */
	reg = cpu_to_be32(FSI_MRESB_RST_GEN);
	rc = fsi_device_write(dev, FSI_MRESB0, &reg, sizeof(reg));
	if (rc)
		return rc;

	reg = cpu_to_be32(FSI_MRESB_RST_ERR);
	return fsi_device_write(dev, FSI_MRESB0, &reg, sizeof(reg));
}

__attribute__((used)) static int hub_master_probe(struct device *dev)
{
	struct fsi_device *fsi_dev = to_fsi_dev(dev);
	struct fsi_master_hub *hub;
	uint32_t reg, links;
	__be32 __reg;
	int rc;

	rc = fsi_device_read(fsi_dev, FSI_MVER, &__reg, sizeof(__reg));
	if (rc)
		return rc;

	reg = be32_to_cpu(__reg);
	links = (reg >> 8) & 0xff;
	dev_dbg(dev, "hub version %08x (%d links)\n", reg, links);

	rc = fsi_slave_claim_range(fsi_dev->slave, FSI_HUB_LINK_OFFSET,
			FSI_HUB_LINK_SIZE * links);
	if (rc) {
		dev_err(dev, "can't claim slave address range for links");
		return rc;
	}

	hub = kzalloc(sizeof(*hub), GFP_KERNEL);
	if (!hub) {
		rc = -ENOMEM;
		goto err_release;
	}

	hub->addr = FSI_HUB_LINK_OFFSET;
	hub->size = FSI_HUB_LINK_SIZE * links;
	hub->upstream = fsi_dev;

	hub->master.dev.parent = dev;
	hub->master.dev.release = hub_master_release;
	hub->master.dev.of_node = of_node_get(dev_of_node(dev));

	hub->master.n_links = links;
	hub->master.read = hub_master_read;
	hub->master.write = hub_master_write;
	hub->master.send_break = hub_master_break;
	hub->master.link_enable = hub_master_link_enable;

	dev_set_drvdata(dev, hub);

	hub_master_init(hub);

	rc = fsi_master_register(&hub->master);
	if (rc)
		goto err_release;

	/* At this point, fsi_master_register performs the device_initialize(),
	 * and holds the sole reference on master.dev. This means the device
	 * will be freed (via ->release) during any subsequent call to
	 * fsi_master_unregister.  We add our own reference to it here, so we
	 * can perform cleanup (in _remove()) without it being freed before
	 * we're ready.
	 */
	get_device(&hub->master.dev);
	return 0;

err_release:
	fsi_slave_release_range(fsi_dev->slave, FSI_HUB_LINK_OFFSET,
			FSI_HUB_LINK_SIZE * links);
	return rc;
}

__attribute__((used)) static int hub_master_remove(struct device *dev)
{
	struct fsi_master_hub *hub = dev_get_drvdata(dev);

	fsi_master_unregister(&hub->master);
	fsi_slave_release_range(hub->upstream->slave, hub->addr, hub->size);
	of_node_put(hub->master.dev.of_node);

	/*
	 * master.dev will likely be ->release()ed after this, which free()s
	 * the hub
	 */
	put_device(&hub->master.dev);

	return 0;
}

