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
typedef  int u32 ;
struct TYPE_2__ {int link; } ;
struct nvkm_ior {int id; TYPE_1__ asy; } ;
struct nvkm_disp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SOR ; 
 int /*<<< orphan*/  gk104_sor ; 
 int nvkm_ior_new_ (int /*<<< orphan*/ *,struct nvkm_disp*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline u32
nv50_ior_base(struct nvkm_ior *ior)
{
	return ior->id * 0x800;
}

__attribute__((used)) static inline u32
nv50_sor_link(struct nvkm_ior *ior)
{
	return nv50_ior_base(ior) + ((ior->asy.link == 2) * 0x80);
}

int
gk104_sor_new(struct nvkm_disp *disp, int id)
{
	return nvkm_ior_new_(&gk104_sor, disp, SOR, id);
}

