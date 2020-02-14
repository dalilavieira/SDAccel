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
struct platform_device {int dummy; } ;
struct hwrng {int dummy; } ;

/* Variables and functions */
 int EEXIST ; 
 int ENODEV ; 
 int hwrng_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hwrng_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  powernv_get_random_long (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  powernv_hwrng ; 
 int /*<<< orphan*/  pr_info (char*) ; 

__attribute__((used)) static int powernv_rng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
	unsigned long *buf;
	int i, len;

	/* We rely on rng_buffer_size() being >= sizeof(unsigned long) */
	len = max / sizeof(unsigned long);

	buf = (unsigned long *)data;

	for (i = 0; i < len; i++)
		powernv_get_random_long(buf++);

	return len * sizeof(unsigned long);
}

__attribute__((used)) static int powernv_rng_remove(struct platform_device *pdev)
{
	hwrng_unregister(&powernv_hwrng);

	return 0;
}

__attribute__((used)) static int powernv_rng_probe(struct platform_device *pdev)
{
	int rc;

	rc = hwrng_register(&powernv_hwrng);
	if (rc) {
		/* We only register one device, ignore any others */
		if (rc == -EEXIST)
			rc = -ENODEV;

		return rc;
	}

	pr_info("Registered powernv hwrng.\n");

	return 0;
}

