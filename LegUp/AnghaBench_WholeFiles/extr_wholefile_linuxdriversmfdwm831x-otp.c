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
typedef  int /*<<< orphan*/  uuid ;
struct wm831x {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 scalar_t__ WM831X_UNIQUE_ID_1 ; 
 int WM831X_UNIQUE_ID_LEN ; 
 int /*<<< orphan*/  add_device_randomness (char*,int) ; 
 int /*<<< orphan*/  dev_attr_unique_id ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 struct wm831x* dev_get_drvdata (struct device*) ; 
 int device_create_file (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,char*) ; 
 int wm831x_reg_read (struct wm831x*,scalar_t__) ; 

__attribute__((used)) static int wm831x_unique_id_read(struct wm831x *wm831x, char *id)
{
	int i, val;

	for (i = 0; i < WM831X_UNIQUE_ID_LEN / 2; i++) {
		val = wm831x_reg_read(wm831x, WM831X_UNIQUE_ID_1 + i);
		if (val < 0)
			return val;

		id[i * 2]       = (val >> 8) & 0xff;
		id[(i * 2) + 1] = val & 0xff;
	}

	return 0;
}

__attribute__((used)) static ssize_t wm831x_unique_id_show(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	struct wm831x *wm831x = dev_get_drvdata(dev);
	int rval;
	char id[WM831X_UNIQUE_ID_LEN];

	rval = wm831x_unique_id_read(wm831x, id);
	if (rval < 0)
		return 0;

	return sprintf(buf, "%*phN\n", WM831X_UNIQUE_ID_LEN, id);
}

int wm831x_otp_init(struct wm831x *wm831x)
{
	char uuid[WM831X_UNIQUE_ID_LEN];
	int ret;

	ret = device_create_file(wm831x->dev, &dev_attr_unique_id);
	if (ret != 0)
		dev_err(wm831x->dev, "Unique ID attribute not created: %d\n",
			ret);

	ret = wm831x_unique_id_read(wm831x, uuid);
	if (ret == 0)
		add_device_randomness(uuid, sizeof(uuid));
	else
		dev_err(wm831x->dev, "Failed to read UUID: %d\n", ret);

	return ret;
}

void wm831x_otp_exit(struct wm831x *wm831x)
{
	device_remove_file(wm831x->dev, &dev_attr_unique_id);
}

