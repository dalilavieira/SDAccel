#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct usb_interface {TYPE_2__* altsetting; } ;
struct led_classdev {char* name; int (* brightness_get ) (struct led_classdev*) ;int (* brightness_set_blocking ) (struct led_classdev*,int) ;TYPE_6__* dev; int /*<<< orphan*/  max_brightness; } ;
struct TYPE_13__ {TYPE_6__* parent; } ;
struct TYPE_12__ {scalar_t__ bustype; int /*<<< orphan*/  version; int /*<<< orphan*/  product; int /*<<< orphan*/  vendor; } ;
struct input_dev {char* name; int /*<<< orphan*/  propbit; int /*<<< orphan*/  keybit; TYPE_5__ dev; TYPE_4__ id; int /*<<< orphan*/  uniq; int /*<<< orphan*/  phys; } ;
struct hid_usage {int dummy; } ;
struct hid_report {int dummy; } ;
struct hid_input {int dummy; } ;
struct hid_field {TYPE_3__* report; } ;
struct hid_device_id {int driver_data; } ;
struct TYPE_14__ {struct device* parent; } ;
struct hid_device {scalar_t__ bus; TYPE_6__ dev; int /*<<< orphan*/  version; int /*<<< orphan*/  product; int /*<<< orphan*/  vendor; int /*<<< orphan*/  uniq; int /*<<< orphan*/  phys; } ;
struct elan_drvdata {unsigned char max_x; unsigned char max_y; unsigned int res_x; unsigned int res_y; int* prev_report; int mute_led_state; struct input_dev* input; struct led_classdev mute_led; } ;
struct device {int dummy; } ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_11__ {scalar_t__ id; } ;
struct TYPE_9__ {scalar_t__ bInterfaceNumber; } ;
struct TYPE_10__ {TYPE_1__ desc; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_MT_POSITION_X ; 
 int /*<<< orphan*/  ABS_MT_POSITION_Y ; 
 int /*<<< orphan*/  ABS_MT_PRESSURE ; 
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int BIT (int) ; 
 int /*<<< orphan*/  BTN_LEFT ; 
 scalar_t__ BUS_USB ; 
 unsigned char ELAN_FEATURE_REPORT ; 
 int ELAN_FEATURE_SIZE ; 
 int /*<<< orphan*/  ELAN_FINGER_DATA_LEN ; 
 int ELAN_HAS_LED ; 
 int ELAN_I2C_REPORT_SIZE ; 
 int ELAN_INPUT_REPORT_SIZE ; 
 int ELAN_LED_REPORT_SIZE ; 
 int ELAN_MAX_FINGERS ; 
 unsigned char ELAN_MAX_PRESSURE ; 
 int ELAN_MT_FIRST_FINGER ; 
 int ELAN_MT_I2C ; 
 int ELAN_MT_SECOND_FINGER ; 
 unsigned char ELAN_MUTE_LED_REPORT ; 
 unsigned char ELAN_PARAM_MAX_X ; 
 unsigned char ELAN_PARAM_MAX_Y ; 
 unsigned char ELAN_PARAM_RES ; 
 scalar_t__ ELAN_SINGLE_FINGER ; 
 scalar_t__ ELAN_TP_USB_INTF ; 
 int ENAVAIL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_CONNECT_DEFAULT ; 
 int /*<<< orphan*/  HID_FEATURE_REPORT ; 
 int /*<<< orphan*/  HID_REQ_GET_REPORT ; 
 int /*<<< orphan*/  HID_REQ_SET_REPORT ; 
 int /*<<< orphan*/  INPUT_MT_POINTER ; 
 int /*<<< orphan*/  INPUT_PROP_BUTTONPAD ; 
 int /*<<< orphan*/  LED_ON ; 
 int /*<<< orphan*/  MT_TOOL_FINGER ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct input_dev* devm_input_allocate_device (TYPE_6__*) ; 
 struct elan_drvdata* devm_kzalloc (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 int devm_led_classdev_register (TYPE_6__*,struct led_classdev*) ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*,...) ; 
 struct elan_drvdata* hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_raw_request (struct hid_device*,unsigned char,unsigned char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int hid_hw_start (struct hid_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_hw_stop (struct hid_device*) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,struct elan_drvdata*) ; 
 int /*<<< orphan*/  input_abs_set_res (struct input_dev*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_mt_init_slots (struct input_dev*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_mt_report_slot_state (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_mt_slot (struct input_dev*,unsigned int) ; 
 int /*<<< orphan*/  input_mt_sync_frame (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (unsigned char*) ; 
 unsigned char* kmalloc (int,int /*<<< orphan*/ ) ; 
 unsigned char* kmemdup (unsigned char const*,int,int /*<<< orphan*/ ) ; 
 unsigned char* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 struct hid_device* to_hid_device (struct device*) ; 
 struct usb_interface* to_usb_interface (struct device*) ; 

__attribute__((used)) static int is_not_elan_touchpad(struct hid_device *hdev)
{
	if (hdev->bus == BUS_USB) {
		struct usb_interface *intf = to_usb_interface(hdev->dev.parent);

		return (intf->altsetting->desc.bInterfaceNumber !=
			ELAN_TP_USB_INTF);
	}

	return 0;
}

__attribute__((used)) static int elan_input_mapping(struct hid_device *hdev, struct hid_input *hi,
			      struct hid_field *field, struct hid_usage *usage,
			      unsigned long **bit, int *max)
{
	if (is_not_elan_touchpad(hdev))
		return 0;

	if (field->report->id == ELAN_SINGLE_FINGER ||
	    field->report->id == ELAN_MT_FIRST_FINGER ||
	    field->report->id == ELAN_MT_SECOND_FINGER ||
	    field->report->id == ELAN_MT_I2C)
		return -1;

	return 0;
}

__attribute__((used)) static int elan_get_device_param(struct hid_device *hdev,
				 unsigned char *dmabuf, unsigned char param)
{
	int ret;

	dmabuf[0] = ELAN_FEATURE_REPORT;
	dmabuf[1] = 0x05;
	dmabuf[2] = 0x03;
	dmabuf[3] = param;
	dmabuf[4] = 0x01;

	ret = hid_hw_raw_request(hdev, ELAN_FEATURE_REPORT, dmabuf,
				 ELAN_FEATURE_SIZE, HID_FEATURE_REPORT,
				 HID_REQ_SET_REPORT);
	if (ret != ELAN_FEATURE_SIZE) {
		hid_err(hdev, "Set report error for parm %d: %d\n", param, ret);
		return ret;
	}

	ret = hid_hw_raw_request(hdev, ELAN_FEATURE_REPORT, dmabuf,
				 ELAN_FEATURE_SIZE, HID_FEATURE_REPORT,
				 HID_REQ_GET_REPORT);
	if (ret != ELAN_FEATURE_SIZE) {
		hid_err(hdev, "Get report error for parm %d: %d\n", param, ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static unsigned int elan_convert_res(char val)
{
	/*
	 * (value from firmware) * 10 + 790 = dpi
	 * dpi * 10 / 254 = dots/mm
	 */
	return (val * 10 + 790) * 10 / 254;
}

__attribute__((used)) static int elan_get_device_params(struct hid_device *hdev)
{
	struct elan_drvdata *drvdata = hid_get_drvdata(hdev);
	unsigned char *dmabuf;
	int ret;

	dmabuf = kmalloc(ELAN_FEATURE_SIZE, GFP_KERNEL);
	if (!dmabuf)
		return -ENOMEM;

	ret = elan_get_device_param(hdev, dmabuf, ELAN_PARAM_MAX_X);
	if (ret)
		goto err;

	drvdata->max_x = (dmabuf[4] << 8) | dmabuf[3];

	ret = elan_get_device_param(hdev, dmabuf, ELAN_PARAM_MAX_Y);
	if (ret)
		goto err;

	drvdata->max_y = (dmabuf[4] << 8) | dmabuf[3];

	ret = elan_get_device_param(hdev, dmabuf, ELAN_PARAM_RES);
	if (ret)
		goto err;

	drvdata->res_x = elan_convert_res(dmabuf[3]);
	drvdata->res_y = elan_convert_res(dmabuf[4]);

err:
	kfree(dmabuf);
	return ret;
}

__attribute__((used)) static int elan_input_configured(struct hid_device *hdev, struct hid_input *hi)
{
	int ret;
	struct input_dev *input;
	struct elan_drvdata *drvdata = hid_get_drvdata(hdev);

	if (is_not_elan_touchpad(hdev))
		return 0;

	ret = elan_get_device_params(hdev);
	if (ret)
		return ret;

	input = devm_input_allocate_device(&hdev->dev);
	if (!input)
		return -ENOMEM;

	input->name = "Elan Touchpad";
	input->phys = hdev->phys;
	input->uniq = hdev->uniq;
	input->id.bustype = hdev->bus;
	input->id.vendor  = hdev->vendor;
	input->id.product = hdev->product;
	input->id.version = hdev->version;
	input->dev.parent = &hdev->dev;

	input_set_abs_params(input, ABS_MT_POSITION_X, 0, drvdata->max_x,
			     0, 0);
	input_set_abs_params(input, ABS_MT_POSITION_Y, 0, drvdata->max_y,
			     0, 0);
	input_set_abs_params(input, ABS_MT_PRESSURE, 0, ELAN_MAX_PRESSURE,
			     0, 0);

	__set_bit(BTN_LEFT, input->keybit);
	__set_bit(INPUT_PROP_BUTTONPAD, input->propbit);

	ret = input_mt_init_slots(input, ELAN_MAX_FINGERS, INPUT_MT_POINTER);
	if (ret) {
		hid_err(hdev, "Failed to init elan MT slots: %d\n", ret);
		return ret;
	}

	input_abs_set_res(input, ABS_X, drvdata->res_x);
	input_abs_set_res(input, ABS_Y, drvdata->res_y);

	ret = input_register_device(input);
	if (ret) {
		hid_err(hdev, "Failed to register elan input device: %d\n",
			ret);
		input_free_device(input);
		return ret;
	}

	drvdata->input = input;

	return 0;
}

__attribute__((used)) static void elan_report_mt_slot(struct elan_drvdata *drvdata, u8 *data,
				unsigned int slot_num)
{
	struct input_dev *input = drvdata->input;
	int x, y, p;

	bool active = !!data;

	input_mt_slot(input, slot_num);
	input_mt_report_slot_state(input, MT_TOOL_FINGER, active);
	if (active) {
		x = ((data[0] & 0xF0) << 4) | data[1];
		y = drvdata->max_y -
		    (((data[0] & 0x07) << 8) | data[2]);
		p = data[4];

		input_report_abs(input, ABS_MT_POSITION_X, x);
		input_report_abs(input, ABS_MT_POSITION_Y, y);
		input_report_abs(input, ABS_MT_PRESSURE, p);
	}
}

__attribute__((used)) static void elan_usb_report_input(struct elan_drvdata *drvdata, u8 *data)
{
	int i;
	struct input_dev *input = drvdata->input;

	/*
	 * There is 3 types of reports: for single touch,
	 * for multitouch - first finger and for multitouch - second finger
	 *
	 * packet structure for ELAN_SINGLE_FINGER and ELAN_MT_FIRST_FINGER:
	 *
	 * byte 1: 1   0   0   0   0   0   0   1  // 0x81 or 0x82
	 * byte 2: 0   0   0   0   0   0   0   0  // looks like unused
	 * byte 3: f5  f4  f3  f2  f1  0   0   L
	 * byte 4: x12 x11 x10 x9  0?  y11 y10 y9
	 * byte 5: x8  x7  x6  x5  x4  x3  x2  x1
	 * byte 6: y8  y7  y6  y5  y4  y3  y2  y1
	 * byte 7: sy4 sy3 sy2 sy1 sx4 sx3 sx2 sx1
	 * byte 8: p8  p7  p6  p5  p4  p3  p2  p1
	 *
	 * packet structure for ELAN_MT_SECOND_FINGER:
	 *
	 * byte 1: 1   0   0   0   0   0   1   1  // 0x83
	 * byte 2: x12 x11 x10 x9  0   y11 y10 y9
	 * byte 3: x8  x7  x6  x5  x4  x3  x2  x1
	 * byte 4: y8  y7  y6  y5  y4  y3  y2  y1
	 * byte 5: sy4 sy3 sy2 sy1 sx4 sx3 sx2 sx1
	 * byte 6: p8  p7  p6  p5  p4  p3  p2  p1
	 * byte 7: 0   0   0   0   0   0   0   0
	 * byte 8: 0   0   0   0   0   0   0   0
	 *
	 * f5-f1: finger touch bits
	 * L: clickpad button
	 * sy / sx: finger width / height expressed in traces, the total number
	 *          of traces can be queried by doing a HID_REQ_SET_REPORT
	 *          { 0x0d, 0x05, 0x03, 0x05, 0x01 } followed by a GET, in the
	 *          returned buf, buf[3]=no-x-traces, buf[4]=no-y-traces.
	 * p: pressure
	 */

	if (data[0] == ELAN_SINGLE_FINGER) {
		for (i = 0; i < ELAN_MAX_FINGERS; i++) {
			if (data[2] & BIT(i + 3))
				elan_report_mt_slot(drvdata, data + 3, i);
			else
				elan_report_mt_slot(drvdata, NULL, i);
		}
		input_report_key(input, BTN_LEFT, data[2] & 0x01);
	}
	/*
	 * When touched with two fingers Elan touchpad will emit two HID reports
	 * first is ELAN_MT_FIRST_FINGER and second is ELAN_MT_SECOND_FINGER
	 * we will save ELAN_MT_FIRST_FINGER report and wait for
	 * ELAN_MT_SECOND_FINGER to finish multitouch
	 */
	if (data[0] == ELAN_MT_FIRST_FINGER) {
		memcpy(drvdata->prev_report, data,
		       sizeof(drvdata->prev_report));
		return;
	}

	if (data[0] == ELAN_MT_SECOND_FINGER) {
		int first = 0;
		u8 *prev_report = drvdata->prev_report;

		if (prev_report[0] != ELAN_MT_FIRST_FINGER)
			return;

		for (i = 0; i < ELAN_MAX_FINGERS; i++) {
			if (prev_report[2] & BIT(i + 3)) {
				if (!first) {
					first = 1;
					elan_report_mt_slot(drvdata, prev_report + 3, i);
				} else {
					elan_report_mt_slot(drvdata, data + 1, i);
				}
			} else {
				elan_report_mt_slot(drvdata, NULL, i);
			}
		}
		input_report_key(input, BTN_LEFT, prev_report[2] & 0x01);
	}

	input_mt_sync_frame(input);
	input_sync(input);
}

__attribute__((used)) static void elan_i2c_report_input(struct elan_drvdata *drvdata, u8 *data)
{
	struct input_dev *input = drvdata->input;
	u8 *finger_data;
	int i;

	/*
	 * Elan MT touchpads in i2c mode send finger data in the same format
	 * as in USB mode, but then with all fingers in a single packet.
	 *
	 * packet structure for ELAN_MT_I2C:
	 *
	 * byte     1: 1   0   0   1   1   1   0   1   // 0x5d
	 * byte     2: f5  f4  f3  f2  f1  0   0   L
	 * byte     3: x12 x11 x10 x9  0?  y11 y10 y9
	 * byte     4: x8  x7  x6  x5  x4  x3  x2  x1
	 * byte     5: y8  y7  y6  y5  y4  y3  y2  y1
	 * byte     6: sy4 sy3 sy2 sy1 sx4 sx3 sx2 sx1
	 * byte     7: p8  p7  p6  p5  p4  p3  p2  p1
	 * byte  8-12: Same as byte 3-7 for second finger down
	 * byte 13-17: Same as byte 3-7 for third finger down
	 * byte 18-22: Same as byte 3-7 for fourth finger down
	 * byte 23-27: Same as byte 3-7 for fifth finger down
	 */

	finger_data = data + 2;
	for (i = 0; i < ELAN_MAX_FINGERS; i++) {
		if (data[1] & BIT(i + 3)) {
			elan_report_mt_slot(drvdata, finger_data, i);
			finger_data += ELAN_FINGER_DATA_LEN;
		} else {
			elan_report_mt_slot(drvdata, NULL, i);
		}
	}

	input_report_key(input, BTN_LEFT, data[1] & 0x01);
	input_mt_sync_frame(input);
	input_sync(input);
}

__attribute__((used)) static int elan_raw_event(struct hid_device *hdev,
			  struct hid_report *report, u8 *data, int size)
{
	struct elan_drvdata *drvdata = hid_get_drvdata(hdev);

	if (is_not_elan_touchpad(hdev))
		return 0;

	if (data[0] == ELAN_SINGLE_FINGER ||
	    data[0] == ELAN_MT_FIRST_FINGER ||
	    data[0] == ELAN_MT_SECOND_FINGER) {
		if (size == ELAN_INPUT_REPORT_SIZE) {
			elan_usb_report_input(drvdata, data);
			return 1;
		}
	}

	if (data[0] == ELAN_MT_I2C && size == ELAN_I2C_REPORT_SIZE) {
		elan_i2c_report_input(drvdata, data);
		return 1;
	}

	return 0;
}

__attribute__((used)) static int elan_start_multitouch(struct hid_device *hdev)
{
	int ret;

	/*
	 * This byte sequence will enable multitouch mode and disable
	 * mouse emulation
	 */
	const unsigned char buf[] = { 0x0D, 0x00, 0x03, 0x21, 0x00 };
	unsigned char *dmabuf = kmemdup(buf, sizeof(buf), GFP_KERNEL);

	if (!dmabuf)
		return -ENOMEM;

	ret = hid_hw_raw_request(hdev, dmabuf[0], dmabuf, sizeof(buf),
				 HID_FEATURE_REPORT, HID_REQ_SET_REPORT);

	kfree(dmabuf);

	if (ret != sizeof(buf)) {
		hid_err(hdev, "Failed to start multitouch: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static enum led_brightness elan_mute_led_get_brigtness(struct led_classdev *led_cdev)
{
	struct device *dev = led_cdev->dev->parent;
	struct hid_device *hdev = to_hid_device(dev);
	struct elan_drvdata *drvdata = hid_get_drvdata(hdev);

	return drvdata->mute_led_state;
}

__attribute__((used)) static int elan_mute_led_set_brigtness(struct led_classdev *led_cdev,
				       enum led_brightness value)
{
	int ret;
	u8 led_state;
	struct device *dev = led_cdev->dev->parent;
	struct hid_device *hdev = to_hid_device(dev);
	struct elan_drvdata *drvdata = hid_get_drvdata(hdev);

	unsigned char *dmabuf = kzalloc(ELAN_LED_REPORT_SIZE, GFP_KERNEL);

	if (!dmabuf)
		return -ENOMEM;

	led_state = !!value;

	dmabuf[0] = ELAN_MUTE_LED_REPORT;
	dmabuf[1] = 0x02;
	dmabuf[2] = led_state;

	ret = hid_hw_raw_request(hdev, dmabuf[0], dmabuf, ELAN_LED_REPORT_SIZE,
				 HID_FEATURE_REPORT, HID_REQ_SET_REPORT);

	kfree(dmabuf);

	if (ret != ELAN_LED_REPORT_SIZE) {
		hid_err(hdev, "Failed to set mute led brightness: %d\n", ret);
		return ret;
	}

	drvdata->mute_led_state = led_state;
	return 0;
}

__attribute__((used)) static int elan_init_mute_led(struct hid_device *hdev)
{
	struct elan_drvdata *drvdata = hid_get_drvdata(hdev);
	struct led_classdev *mute_led = &drvdata->mute_led;

	mute_led->name = "elan:red:mute";
	mute_led->brightness_get = elan_mute_led_get_brigtness;
	mute_led->brightness_set_blocking = elan_mute_led_set_brigtness;
	mute_led->max_brightness = LED_ON;
	mute_led->dev = &hdev->dev;

	return devm_led_classdev_register(&hdev->dev, mute_led);
}

__attribute__((used)) static int elan_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
	int ret;
	struct elan_drvdata *drvdata;

	drvdata = devm_kzalloc(&hdev->dev, sizeof(*drvdata), GFP_KERNEL);

	if (!drvdata)
		return -ENOMEM;

	hid_set_drvdata(hdev, drvdata);

	ret = hid_parse(hdev);
	if (ret) {
		hid_err(hdev, "Hid Parse failed\n");
		return ret;
	}

	ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
	if (ret) {
		hid_err(hdev, "Hid hw start failed\n");
		return ret;
	}

	if (is_not_elan_touchpad(hdev))
		return 0;

	if (!drvdata->input) {
		hid_err(hdev, "Input device is not registred\n");
		ret = -ENAVAIL;
		goto err;
	}

	ret = elan_start_multitouch(hdev);
	if (ret)
		goto err;

	if (id->driver_data & ELAN_HAS_LED) {
		ret = elan_init_mute_led(hdev);
		if (ret)
			goto err;
	}

	return 0;
err:
	hid_hw_stop(hdev);
	return ret;
}

__attribute__((used)) static void elan_remove(struct hid_device *hdev)
{
	hid_hw_stop(hdev);
}

