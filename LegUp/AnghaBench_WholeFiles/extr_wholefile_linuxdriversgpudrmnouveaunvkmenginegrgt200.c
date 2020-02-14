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
struct nvkm_gr {int dummy; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gt200_gr ; 
 int nv50_gr_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_gr**) ; 

int
gt200_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
	return nv50_gr_new_(&gt200_gr, device, index, pgr);
}

