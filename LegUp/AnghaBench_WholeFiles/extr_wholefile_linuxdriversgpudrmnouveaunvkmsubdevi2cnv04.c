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
struct nvkm_i2c {int dummy; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv04_i2c ; 
 int nvkm_i2c_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_i2c**) ; 

int
nv04_i2c_new(struct nvkm_device *device, int index, struct nvkm_i2c **pi2c)
{
	return nvkm_i2c_new_(&nv04_i2c, device, index, pi2c);
}

