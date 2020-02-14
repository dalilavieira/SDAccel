#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct rtc_time {int tm_year; int tm_mon; int tm_mday; int tm_hour; int tm_min; int tm_sec; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int (* send_event ) (struct hid_sensor_hub_device*,unsigned int,void*) ;int (* capture_sample ) (struct hid_sensor_hub_device*,unsigned int,size_t,char*,void*) ;struct platform_device* pdev; } ;
struct TYPE_6__ {struct platform_device* pdev; struct hid_sensor_hub_device* hsdev; } ;
struct hid_time_state {int /*<<< orphan*/ * rtc; TYPE_1__ callbacks; TYPE_3__ common_attributes; int /*<<< orphan*/  comp_last_time; int /*<<< orphan*/  lock_last_time; struct rtc_time last_time; TYPE_2__* info; struct rtc_time time_buf; } ;
struct hid_sensor_hub_device {int /*<<< orphan*/  hdev; } ;
struct device {int dummy; } ;
struct TYPE_5__ {int report_id; int size; scalar_t__ attrib_id; scalar_t__ units; scalar_t__ unit_expo; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_INPUT_REPORT ; 
 unsigned int HID_USAGE_SENSOR_TIME ; 
#define  HID_USAGE_SENSOR_TIME_DAY 133 
#define  HID_USAGE_SENSOR_TIME_HOUR 132 
#define  HID_USAGE_SENSOR_TIME_MINUTE 131 
#define  HID_USAGE_SENSOR_TIME_MONTH 130 
#define  HID_USAGE_SENSOR_TIME_SECOND 129 
#define  HID_USAGE_SENSOR_TIME_YEAR 128 
 scalar_t__ HID_USAGE_SENSOR_UNITS_NOT_SPECIFIED ; 
 scalar_t__ HID_USAGE_SENSOR_UNITS_SECOND ; 
 int HZ ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SENSOR_HUB_SYNC ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 unsigned int TIME_RTC_CHANNEL_MAX ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct hid_sensor_hub_device* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct hid_time_state* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * devm_rtc_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_device_io_start (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_device_io_stop (int /*<<< orphan*/ ) ; 
 int hid_sensor_parse_common_attributes (struct hid_sensor_hub_device*,unsigned int,TYPE_3__*) ; 
 scalar_t__* hid_time_addresses ; 
 char const** hid_time_channel_names ; 
 int /*<<< orphan*/  hid_time_rtc_ops ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 struct hid_time_state* platform_get_drvdata (void*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct hid_time_state*) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sensor_hub_device_close (struct hid_sensor_hub_device*) ; 
 int sensor_hub_device_open (struct hid_sensor_hub_device*) ; 
 int /*<<< orphan*/  sensor_hub_input_attr_get_raw_value (struct hid_sensor_hub_device*,unsigned int,scalar_t__,int,int /*<<< orphan*/ ,int) ; 
 scalar_t__ sensor_hub_input_get_attribute_info (struct hid_sensor_hub_device*,int /*<<< orphan*/ ,unsigned int,scalar_t__,TYPE_2__*) ; 
 int sensor_hub_register_callback (struct hid_sensor_hub_device*,unsigned int,TYPE_1__*) ; 
 int /*<<< orphan*/  sensor_hub_remove_callback (struct hid_sensor_hub_device*,unsigned int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 void* to_platform_device (struct device*) ; 
 int wait_for_completion_killable_timeout (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int hid_time_proc_event(struct hid_sensor_hub_device *hsdev,
				unsigned usage_id, void *priv)
{
	unsigned long flags;
	struct hid_time_state *time_state = platform_get_drvdata(priv);

	spin_lock_irqsave(&time_state->lock_last_time, flags);
	time_state->last_time = time_state->time_buf;
	spin_unlock_irqrestore(&time_state->lock_last_time, flags);
	complete(&time_state->comp_last_time);
	return 0;
}

__attribute__((used)) static u32 hid_time_value(size_t raw_len, char *raw_data)
{
	switch (raw_len) {
	case 1:
		return *(u8 *)raw_data;
	case 2:
		return *(u16 *)raw_data;
	case 4:
		return *(u32 *)raw_data;
	default:
		return (u32)(~0U); /* 0xff... or -1 to denote an error */
	}
}

__attribute__((used)) static int hid_time_capture_sample(struct hid_sensor_hub_device *hsdev,
				unsigned usage_id, size_t raw_len,
				char *raw_data, void *priv)
{
	struct hid_time_state *time_state = platform_get_drvdata(priv);
	struct rtc_time *time_buf = &time_state->time_buf;

	switch (usage_id) {
	case HID_USAGE_SENSOR_TIME_YEAR:
		/*
		 * The draft for HID-sensors (HUTRR39) currently doesn't define
		 * the range for the year attribute. Therefor we support
		 * 8 bit (0-99) and 16 or 32 bits (full) as size for the year.
		 */
		if (raw_len == 1) {
			time_buf->tm_year = *(u8 *)raw_data;
			if (time_buf->tm_year < 70)
				/* assume we are in 1970...2069 */
				time_buf->tm_year += 100;
		} else
			time_buf->tm_year =
				(int)hid_time_value(raw_len, raw_data)-1900;
		break;
	case HID_USAGE_SENSOR_TIME_MONTH:
		/* sensors are sending the month as 1-12, we need 0-11 */
		time_buf->tm_mon = (int)hid_time_value(raw_len, raw_data)-1;
		break;
	case HID_USAGE_SENSOR_TIME_DAY:
		time_buf->tm_mday = (int)hid_time_value(raw_len, raw_data);
		break;
	case HID_USAGE_SENSOR_TIME_HOUR:
		time_buf->tm_hour = (int)hid_time_value(raw_len, raw_data);
		break;
	case HID_USAGE_SENSOR_TIME_MINUTE:
		time_buf->tm_min = (int)hid_time_value(raw_len, raw_data);
		break;
	case HID_USAGE_SENSOR_TIME_SECOND:
		time_buf->tm_sec = (int)hid_time_value(raw_len, raw_data);
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static const char *hid_time_attrib_name(u32 attrib_id)
{
	static const char unknown[] = "unknown";
	unsigned i;

	for (i = 0; i < TIME_RTC_CHANNEL_MAX; ++i) {
		if (hid_time_addresses[i] == attrib_id)
			return hid_time_channel_names[i];
	}
	return unknown; /* should never happen */
}

__attribute__((used)) static int hid_time_parse_report(struct platform_device *pdev,
				struct hid_sensor_hub_device *hsdev,
				unsigned usage_id,
				struct hid_time_state *time_state)
{
	int report_id, i;

	for (i = 0; i < TIME_RTC_CHANNEL_MAX; ++i)
		if (sensor_hub_input_get_attribute_info(hsdev,
				HID_INPUT_REPORT, usage_id,
				hid_time_addresses[i],
				&time_state->info[i]) < 0)
			return -EINVAL;
	/* Check the (needed) attributes for sanity */
	report_id = time_state->info[0].report_id;
	if (report_id < 0) {
		dev_err(&pdev->dev, "bad report ID!\n");
		return -EINVAL;
	}
	for (i = 0; i < TIME_RTC_CHANNEL_MAX; ++i) {
		if (time_state->info[i].report_id != report_id) {
			dev_err(&pdev->dev,
				"not all needed attributes inside the same report!\n");
			return -EINVAL;
		}
		if (time_state->info[i].size == 3 ||
				time_state->info[i].size > 4) {
			dev_err(&pdev->dev,
				"attribute '%s' not 8, 16 or 32 bits wide!\n",
				hid_time_attrib_name(
					time_state->info[i].attrib_id));
			return -EINVAL;
		}
		if (time_state->info[i].units !=
				HID_USAGE_SENSOR_UNITS_NOT_SPECIFIED &&
				/* allow attribute seconds with unit seconds */
				!(time_state->info[i].attrib_id ==
				HID_USAGE_SENSOR_TIME_SECOND &&
				time_state->info[i].units ==
				HID_USAGE_SENSOR_UNITS_SECOND)) {
			dev_err(&pdev->dev,
				"attribute '%s' hasn't a unit of type 'none'!\n",
				hid_time_attrib_name(
					time_state->info[i].attrib_id));
			return -EINVAL;
		}
		if (time_state->info[i].unit_expo) {
			dev_err(&pdev->dev,
				"attribute '%s' hasn't a unit exponent of 1!\n",
				hid_time_attrib_name(
					time_state->info[i].attrib_id));
			return -EINVAL;
		}
	}

	return 0;
}

__attribute__((used)) static int hid_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	unsigned long flags;
	struct hid_time_state *time_state =
		platform_get_drvdata(to_platform_device(dev));
	int ret;

	reinit_completion(&time_state->comp_last_time);
	/* get a report with all values through requesting one value */
	sensor_hub_input_attr_get_raw_value(time_state->common_attributes.hsdev,
			HID_USAGE_SENSOR_TIME, hid_time_addresses[0],
			time_state->info[0].report_id, SENSOR_HUB_SYNC, false);
	/* wait for all values (event) */
	ret = wait_for_completion_killable_timeout(
			&time_state->comp_last_time, HZ*6);
	if (ret > 0) {
		/* no error */
		spin_lock_irqsave(&time_state->lock_last_time, flags);
		*tm = time_state->last_time;
		spin_unlock_irqrestore(&time_state->lock_last_time, flags);
		return 0;
	}
	if (!ret)
		return -EIO; /* timeouted */
	return ret; /* killed (-ERESTARTSYS) */
}

__attribute__((used)) static int hid_time_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct hid_sensor_hub_device *hsdev = dev_get_platdata(&pdev->dev);
	struct hid_time_state *time_state = devm_kzalloc(&pdev->dev,
		sizeof(struct hid_time_state), GFP_KERNEL);

	if (time_state == NULL)
		return -ENOMEM;

	platform_set_drvdata(pdev, time_state);

	spin_lock_init(&time_state->lock_last_time);
	init_completion(&time_state->comp_last_time);
	time_state->common_attributes.hsdev = hsdev;
	time_state->common_attributes.pdev = pdev;

	ret = hid_sensor_parse_common_attributes(hsdev,
				HID_USAGE_SENSOR_TIME,
				&time_state->common_attributes);
	if (ret) {
		dev_err(&pdev->dev, "failed to setup common attributes!\n");
		return ret;
	}

	ret = hid_time_parse_report(pdev, hsdev, HID_USAGE_SENSOR_TIME,
					time_state);
	if (ret) {
		dev_err(&pdev->dev, "failed to setup attributes!\n");
		return ret;
	}

	time_state->callbacks.send_event = hid_time_proc_event;
	time_state->callbacks.capture_sample = hid_time_capture_sample;
	time_state->callbacks.pdev = pdev;
	ret = sensor_hub_register_callback(hsdev, HID_USAGE_SENSOR_TIME,
					&time_state->callbacks);
	if (ret < 0) {
		dev_err(&pdev->dev, "register callback failed!\n");
		return ret;
	}

	ret = sensor_hub_device_open(hsdev);
	if (ret) {
		dev_err(&pdev->dev, "failed to open sensor hub device!\n");
		goto err_open;
	}

	/*
	 * Enable HID input processing early in order to be able to read the
	 * clock already in devm_rtc_device_register().
	 */
	hid_device_io_start(hsdev->hdev);

	time_state->rtc = devm_rtc_device_register(&pdev->dev,
					"hid-sensor-time", &hid_time_rtc_ops,
					THIS_MODULE);

	if (IS_ERR(time_state->rtc)) {
		hid_device_io_stop(hsdev->hdev);
		ret = PTR_ERR(time_state->rtc);
		time_state->rtc = NULL;
		dev_err(&pdev->dev, "rtc device register failed!\n");
		goto err_rtc;
	}

	return ret;

err_rtc:
	sensor_hub_device_close(hsdev);
err_open:
	sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_TIME);
	return ret;
}

__attribute__((used)) static int hid_time_remove(struct platform_device *pdev)
{
	struct hid_sensor_hub_device *hsdev = dev_get_platdata(&pdev->dev);

	sensor_hub_device_close(hsdev);
	sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_TIME);

	return 0;
}

