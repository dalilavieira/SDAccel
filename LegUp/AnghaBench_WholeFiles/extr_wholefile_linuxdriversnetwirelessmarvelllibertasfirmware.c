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
typedef  scalar_t__ u32 ;
struct lbs_private {scalar_t__ fw_model; int /*<<< orphan*/  driver_lock; struct lbs_fw_table const* fw_iter; struct lbs_fw_table const* fw_table; int /*<<< orphan*/  (* fw_callback ) (struct lbs_private*,int,struct firmware const*,struct firmware const*) ;struct device* fw_device; int /*<<< orphan*/  fw_waitq; struct firmware const* helper_fw; scalar_t__ mesh_dev; scalar_t__ dev; } ;
typedef  struct lbs_fw_table {char* fwname; char* helper; scalar_t__ model; } const lbs_fw_table ;
typedef  struct firmware const firmware ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  (* lbs_fw_cb ) (struct lbs_private*,int,struct firmware const*,struct firmware const*) ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 int EBUSY ; 
 int ENOENT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  lbs_deb_fw (char*,...) ; 
static  void load_next_firmware_from_table (struct lbs_private*) ; 
 int netif_running (scalar_t__) ; 
 int /*<<< orphan*/  release_firmware (struct firmware const*) ; 
 int request_firmware (struct firmware const**,char*,struct device*) ; 
 int request_firmware_nowait (int /*<<< orphan*/ ,int,char const*,struct device*,int /*<<< orphan*/ ,struct lbs_private*,void (*) (struct firmware const*,void*)) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct lbs_private*,int,struct firmware const*,struct firmware const*) ; 
 int /*<<< orphan*/  wait_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int lbs_iface_active(struct lbs_private *priv)
{
	int r;

	r = netif_running(priv->dev);
	if (priv->mesh_dev)
		r |= netif_running(priv->mesh_dev);

	return r;
}

__attribute__((used)) static void lbs_fw_loaded(struct lbs_private *priv, int ret,
	const struct firmware *helper, const struct firmware *mainfw)
{
	unsigned long flags;

	lbs_deb_fw("firmware load complete, code %d\n", ret);

	/* User must free helper/mainfw */
	priv->fw_callback(priv, ret, helper, mainfw);

	spin_lock_irqsave(&priv->driver_lock, flags);
	priv->fw_callback = NULL;
	wake_up(&priv->fw_waitq);
	spin_unlock_irqrestore(&priv->driver_lock, flags);
}

__attribute__((used)) static void do_load_firmware(struct lbs_private *priv, const char *name,
	void (*cb)(const struct firmware *fw, void *context))
{
	int ret;

	lbs_deb_fw("Requesting %s\n", name);
	ret = request_firmware_nowait(THIS_MODULE, true, name,
			priv->fw_device, GFP_KERNEL, priv, cb);
	if (ret) {
		lbs_deb_fw("request_firmware_nowait error %d\n", ret);
		lbs_fw_loaded(priv, ret, NULL, NULL);
	}
}

__attribute__((used)) static void main_firmware_cb(const struct firmware *firmware, void *context)
{
	struct lbs_private *priv = context;

	if (!firmware) {
		/* Failed to find firmware: try next table entry */
		load_next_firmware_from_table(priv);
		return;
	}

	/* Firmware found! */
	lbs_fw_loaded(priv, 0, priv->helper_fw, firmware);
	if (priv->helper_fw) {
		release_firmware (priv->helper_fw);
		priv->helper_fw = NULL;
	}
	release_firmware (firmware);
}

__attribute__((used)) static void helper_firmware_cb(const struct firmware *firmware, void *context)
{
	struct lbs_private *priv = context;

	if (!firmware) {
		/* Failed to find firmware: try next table entry */
		load_next_firmware_from_table(priv);
		return;
	}

	/* Firmware found! */
	if (priv->fw_iter->fwname) {
		priv->helper_fw = firmware;
		do_load_firmware(priv, priv->fw_iter->fwname, main_firmware_cb);
	} else {
		/* No main firmware needed for this helper --> success! */
		lbs_fw_loaded(priv, 0, firmware, NULL);
	}
}

__attribute__((used)) static void load_next_firmware_from_table(struct lbs_private *priv)
{
	const struct lbs_fw_table *iter;

	if (!priv->fw_iter)
		iter = priv->fw_table;
	else
		iter = ++priv->fw_iter;

	if (priv->helper_fw) {
		release_firmware(priv->helper_fw);
		priv->helper_fw = NULL;
	}

next:
	if (!iter->helper) {
		/* End of table hit. */
		lbs_fw_loaded(priv, -ENOENT, NULL, NULL);
		return;
	}

	if (iter->model != priv->fw_model) {
		iter++;
		goto next;
	}

	priv->fw_iter = iter;
	do_load_firmware(priv, iter->helper, helper_firmware_cb);
}

void lbs_wait_for_firmware_load(struct lbs_private *priv)
{
	wait_event(priv->fw_waitq, priv->fw_callback == NULL);
}

int lbs_get_firmware_async(struct lbs_private *priv, struct device *device,
			    u32 card_model, const struct lbs_fw_table *fw_table,
			    lbs_fw_cb callback)
{
	unsigned long flags;

	spin_lock_irqsave(&priv->driver_lock, flags);
	if (priv->fw_callback) {
		lbs_deb_fw("firmware load already in progress\n");
		spin_unlock_irqrestore(&priv->driver_lock, flags);
		return -EBUSY;
	}

	priv->fw_device = device;
	priv->fw_callback = callback;
	priv->fw_table = fw_table;
	priv->fw_iter = NULL;
	priv->fw_model = card_model;
	spin_unlock_irqrestore(&priv->driver_lock, flags);

	lbs_deb_fw("Starting async firmware load\n");
	load_next_firmware_from_table(priv);
	return 0;
}

int lbs_get_firmware(struct device *dev, u32 card_model,
			const struct lbs_fw_table *fw_table,
			const struct firmware **helper,
			const struct firmware **mainfw)
{
	const struct lbs_fw_table *iter;
	int ret;

	BUG_ON(helper == NULL);
	BUG_ON(mainfw == NULL);

	/* Search for firmware to use from the table. */
	iter = fw_table;
	while (iter && iter->helper) {
		if (iter->model != card_model)
			goto next;

		if (*helper == NULL) {
			ret = request_firmware(helper, iter->helper, dev);
			if (ret)
				goto next;

			/* If the device has one-stage firmware (ie cf8305) and
			 * we've got it then we don't need to bother with the
			 * main firmware.
			 */
			if (iter->fwname == NULL)
				return 0;
		}

		if (*mainfw == NULL) {
			ret = request_firmware(mainfw, iter->fwname, dev);
			if (ret) {
				/* Clear the helper to ensure we don't have
				 * mismatched firmware pairs.
				 */
				release_firmware(*helper);
				*helper = NULL;
			}
		}

		if (*helper && *mainfw)
			return 0;

  next:
		iter++;
	}

	/* Failed */
	release_firmware(*helper);
	*helper = NULL;
	release_firmware(*mainfw);
	*mainfw = NULL;

	return -ENOENT;
}

