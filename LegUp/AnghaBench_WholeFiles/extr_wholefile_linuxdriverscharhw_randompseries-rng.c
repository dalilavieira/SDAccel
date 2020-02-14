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
typedef  int /*<<< orphan*/  u64 ;
struct vio_device_id {int dummy; } ;
struct vio_dev {int dummy; } ;
struct hwrng {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  H_RANDOM ; 
 int H_SUCCESS ; 
 int PLPAR_HCALL_BUFSIZE ; 
 int hwrng_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hwrng_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ *,int) ; 
 int plpar_hcall (int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  pr_err_ratelimited (char*,int) ; 
 int /*<<< orphan*/  pseries_rng ; 

__attribute__((used)) static int pseries_rng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
	u64 buffer[PLPAR_HCALL_BUFSIZE];
	int rc;

	rc = plpar_hcall(H_RANDOM, (unsigned long *)buffer);
	if (rc != H_SUCCESS) {
		pr_err_ratelimited("H_RANDOM call failed %d\n", rc);
		return -EIO;
	}
	memcpy(data, buffer, 8);

	/* The hypervisor interface returns 64 bits */
	return 8;
}

__attribute__((used)) static unsigned long pseries_rng_get_desired_dma(struct vio_dev *vdev)
{
	return 0;
}

__attribute__((used)) static int pseries_rng_probe(struct vio_dev *dev,
		const struct vio_device_id *id)
{
	return hwrng_register(&pseries_rng);
}

__attribute__((used)) static int pseries_rng_remove(struct vio_dev *dev)
{
	hwrng_unregister(&pseries_rng);
	return 0;
}

