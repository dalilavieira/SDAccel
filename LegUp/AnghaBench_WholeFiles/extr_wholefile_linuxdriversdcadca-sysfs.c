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
struct device {int dummy; } ;
struct dca_provider {int id; struct device* cd; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GFP_NOWAIT ; 
 scalar_t__ IS_ERR (struct device*) ; 
 int /*<<< orphan*/  MKDEV (int /*<<< orphan*/ ,int) ; 
 int PTR_ERR (struct device*) ; 
 int /*<<< orphan*/  dca_class ; 
 int /*<<< orphan*/  dca_idr ; 
 int /*<<< orphan*/  dca_idr_lock ; 
 struct device* device_create (int /*<<< orphan*/ ,struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  device_destroy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_unregister (struct device*) ; 
 int idr_alloc (int /*<<< orphan*/ *,struct dca_provider*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idr_preload (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idr_preload_end () ; 
 int /*<<< orphan*/  idr_remove (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

int dca_sysfs_add_req(struct dca_provider *dca, struct device *dev, int slot)
{
	struct device *cd;
	static int req_count;

	cd = device_create(dca_class, dca->cd, MKDEV(0, slot + 1), NULL,
			   "requester%d", req_count++);
	if (IS_ERR(cd))
		return PTR_ERR(cd);
	return 0;
}

void dca_sysfs_remove_req(struct dca_provider *dca, int slot)
{
	device_destroy(dca_class, MKDEV(0, slot + 1));
}

int dca_sysfs_add_provider(struct dca_provider *dca, struct device *dev)
{
	struct device *cd;
	int ret;

	idr_preload(GFP_KERNEL);
	spin_lock(&dca_idr_lock);

	ret = idr_alloc(&dca_idr, dca, 0, 0, GFP_NOWAIT);
	if (ret >= 0)
		dca->id = ret;

	spin_unlock(&dca_idr_lock);
	idr_preload_end();
	if (ret < 0)
		return ret;

	cd = device_create(dca_class, dev, MKDEV(0, 0), NULL, "dca%d", dca->id);
	if (IS_ERR(cd)) {
		spin_lock(&dca_idr_lock);
		idr_remove(&dca_idr, dca->id);
		spin_unlock(&dca_idr_lock);
		return PTR_ERR(cd);
	}
	dca->cd = cd;
	return 0;
}

void dca_sysfs_remove_provider(struct dca_provider *dca)
{
	device_unregister(dca->cd);
	dca->cd = NULL;
	spin_lock(&dca_idr_lock);
	idr_remove(&dca_idr, dca->id);
	spin_unlock(&dca_idr_lock);
}

