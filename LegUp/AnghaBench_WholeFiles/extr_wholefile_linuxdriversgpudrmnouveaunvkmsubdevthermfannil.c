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
struct nvkm_therm {struct nvkm_fan* fan; } ;
struct nvkm_fan {char* type; int (* get ) (struct nvkm_therm*) ;int (* set ) (struct nvkm_therm*,int) ;} ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nvkm_fan* kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
nvkm_fannil_get(struct nvkm_therm *therm)
{
	return -ENODEV;
}

__attribute__((used)) static int
nvkm_fannil_set(struct nvkm_therm *therm, int percent)
{
	return -ENODEV;
}

int
nvkm_fannil_create(struct nvkm_therm *therm)
{
	struct nvkm_fan *priv;

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	therm->fan = priv;
	if (!priv)
		return -ENOMEM;

	priv->type = "none / external";
	priv->get = nvkm_fannil_get;
	priv->set = nvkm_fannil_set;
	return 0;
}

