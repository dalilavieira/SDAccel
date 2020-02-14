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
struct TYPE_3__ {char const* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_4__ {struct platform_device ofdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int of_device_modalias (struct device*,char*,int /*<<< orphan*/ ) ; 
 char* of_get_property (char const*,char*,int*) ; 
 int sprintf (char*,char*,char const*) ; 
 int strlen (char const*) ; 
 TYPE_2__* to_macio_device (struct device*) ; 
 struct platform_device* to_platform_device (struct device*) ; 

__attribute__((used)) static ssize_t
compatible_show (struct device *dev, struct device_attribute *attr, char *buf)
{
	struct platform_device *of;
	const char *compat;
	int cplen;
	int length = 0;

	of = &to_macio_device (dev)->ofdev;
	compat = of_get_property(of->dev.of_node, "compatible", &cplen);
	if (!compat) {
		*buf = '\0';
		return 0;
	}
	while (cplen > 0) {
		int l;
		length += sprintf (buf, "%s\n", compat);
		buf += length;
		l = strlen (compat) + 1;
		compat += l;
		cplen -= l;
	}

	return length;
}

__attribute__((used)) static ssize_t modalias_show (struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	return of_device_modalias(dev, buf, PAGE_SIZE);
}

__attribute__((used)) static ssize_t devspec_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct platform_device *ofdev;

	ofdev = to_platform_device(dev);
	return sprintf(buf, "%pOF\n", ofdev->dev.of_node);
}

