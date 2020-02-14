#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct resource {int dummy; } ;
struct TYPE_4__ {struct device* parent; } ;
struct TYPE_3__ {scalar_t__ port; scalar_t__ type; } ;
struct intel_th_device {int num_resources; scalar_t__ type; TYPE_2__ dev; TYPE_1__ output; struct resource* resource; } ;
struct intel_th {struct intel_th_device* hub; } ;
struct device {int dummy; } ;

/* Variables and functions */
 scalar_t__ GTH_NONE ; 
 scalar_t__ INTEL_TH_OUTPUT ; 
 scalar_t__ INTEL_TH_SWITCH ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 struct intel_th* dev_get_drvdata (struct device*) ; 
 unsigned int resource_type (struct resource*) ; 
 struct intel_th_device* to_intel_th_device (struct device*) ; 

__attribute__((used)) static inline struct resource *
intel_th_device_get_resource(struct intel_th_device *thdev, unsigned int type,
			     unsigned int num)
{
	int i;

	for (i = 0; i < thdev->num_resources; i++)
		if (resource_type(&thdev->resource[i]) == type && !num--)
			return &thdev->resource[i];

	return NULL;
}

__attribute__((used)) static inline bool
intel_th_output_assigned(struct intel_th_device *thdev)
{
	return thdev->type == INTEL_TH_OUTPUT &&
		(thdev->output.port >= 0 ||
		 thdev->output.type == GTH_NONE);
}

__attribute__((used)) static inline struct intel_th_device *
to_intel_th_parent(struct intel_th_device *thdev)
{
	struct device *parent = thdev->dev.parent;

	if (!parent)
		return NULL;

	return to_intel_th_device(parent);
}

__attribute__((used)) static inline struct intel_th *to_intel_th(struct intel_th_device *thdev)
{
	if (thdev->type == INTEL_TH_OUTPUT)
		thdev = to_intel_th_parent(thdev);

	if (WARN_ON_ONCE(!thdev || thdev->type == INTEL_TH_OUTPUT))
		return NULL;

	return dev_get_drvdata(thdev->dev.parent);
}

__attribute__((used)) static inline struct intel_th_device *
to_intel_th_hub(struct intel_th_device *thdev)
{
	if (thdev->type == INTEL_TH_SWITCH)
		return thdev;
	else if (thdev->type == INTEL_TH_OUTPUT)
		return to_intel_th_parent(thdev);

	return to_intel_th(thdev)->hub;
}

