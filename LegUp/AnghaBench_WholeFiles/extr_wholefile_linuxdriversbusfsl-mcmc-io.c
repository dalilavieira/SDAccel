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
struct fsl_mc_resource {scalar_t__ type; struct fsl_mc_device* data; } ;
struct fsl_mc_io {struct fsl_mc_device* dpmcp_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  id; } ;
struct fsl_mc_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  mc_handle; struct fsl_mc_resource* resource; struct fsl_mc_io* mc_io; TYPE_1__ obj_desc; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ FSL_MC_POOL_DPMCP ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int dpmcp_close (struct fsl_mc_io*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dpmcp_open (struct fsl_mc_io*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int dpmcp_reset (struct fsl_mc_io*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fsl_destroy_mc_io (struct fsl_mc_io*) ; 
 int /*<<< orphan*/  fsl_mc_resource_free (struct fsl_mc_resource*) ; 

__attribute__((used)) static int fsl_mc_io_set_dpmcp(struct fsl_mc_io *mc_io,
			       struct fsl_mc_device *dpmcp_dev)
{
	int error;

	if (mc_io->dpmcp_dev)
		return -EINVAL;

	if (dpmcp_dev->mc_io)
		return -EINVAL;

	error = dpmcp_open(mc_io,
			   0,
			   dpmcp_dev->obj_desc.id,
			   &dpmcp_dev->mc_handle);
	if (error < 0)
		return error;

	mc_io->dpmcp_dev = dpmcp_dev;
	dpmcp_dev->mc_io = mc_io;
	return 0;
}

__attribute__((used)) static void fsl_mc_io_unset_dpmcp(struct fsl_mc_io *mc_io)
{
	int error;
	struct fsl_mc_device *dpmcp_dev = mc_io->dpmcp_dev;

	error = dpmcp_close(mc_io,
			    0,
			    dpmcp_dev->mc_handle);
	if (error < 0) {
		dev_err(&dpmcp_dev->dev, "dpmcp_close() failed: %d\n",
			error);
	}

	mc_io->dpmcp_dev = NULL;
	dpmcp_dev->mc_io = NULL;
}

void fsl_mc_portal_free(struct fsl_mc_io *mc_io)
{
	struct fsl_mc_device *dpmcp_dev;
	struct fsl_mc_resource *resource;

	/*
	 * Every mc_io obtained by calling fsl_mc_portal_allocate() is supposed
	 * to have a DPMCP object associated with.
	 */
	dpmcp_dev = mc_io->dpmcp_dev;

	resource = dpmcp_dev->resource;
	if (!resource || resource->type != FSL_MC_POOL_DPMCP)
		return;

	if (resource->data != dpmcp_dev)
		return;

	fsl_destroy_mc_io(mc_io);
	fsl_mc_resource_free(resource);
}

int fsl_mc_portal_reset(struct fsl_mc_io *mc_io)
{
	int error;
	struct fsl_mc_device *dpmcp_dev = mc_io->dpmcp_dev;

	error = dpmcp_reset(mc_io, 0, dpmcp_dev->mc_handle);
	if (error < 0) {
		dev_err(&dpmcp_dev->dev, "dpmcp_reset() failed: %d\n", error);
		return error;
	}

	return 0;
}

