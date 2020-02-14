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
typedef  int u8 ;
struct zc_device {unsigned int* last_key; int /*<<< orphan*/  input_ep81; } ;
struct hid_usage {int hid; } ;
struct hid_report {int id; } ;
struct hid_input {int /*<<< orphan*/  input; } ;
struct hid_field {int dummy; } ;
struct hid_device_id {int dummy; } ;
struct hid_device {int /*<<< orphan*/  dev; } ;
typedef  int __u8 ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_CONNECT_DEFAULT ; 
 int HID_UP_CONSUMER ; 
 int HID_USAGE ; 
 int HID_USAGE_PAGE ; 
 unsigned int KEY_AUDIO ; 
 unsigned int KEY_AUX ; 
 unsigned int KEY_DVD ; 
 unsigned int KEY_INFO ; 
 unsigned int KEY_MENU ; 
 unsigned int KEY_MODE ; 
 unsigned int KEY_PVR ; 
 unsigned int KEY_RADIO ; 
 unsigned int KEY_SCREEN ; 
 unsigned int KEY_TEXT ; 
 unsigned int KEY_TV ; 
 unsigned int KEY_VIDEO ; 
 int /*<<< orphan*/  dbg_hid (char*,int) ; 
 struct zc_device* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 struct zc_device* hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_start (struct hid_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_info (struct hid_device*,char*) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,struct zc_device*) ; 
 int /*<<< orphan*/  input_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int) ; 
 int /*<<< orphan*/  zc_map_key_clear (unsigned int) ; 

__attribute__((used)) static __u8 *zc_report_fixup(struct hid_device *hdev, __u8 *rdesc,
	unsigned int *rsize)
{
	if (*rsize >= 253 &&
		rdesc[0x96] == 0xbc && rdesc[0x97] == 0xff &&
		rdesc[0xca] == 0xbc && rdesc[0xcb] == 0xff &&
		rdesc[0xe1] == 0xbc && rdesc[0xe2] == 0xff) {
			hid_info(hdev,
				"fixing up zydacron remote control report descriptor\n");
			rdesc[0x96] = rdesc[0xca] = rdesc[0xe1] = 0x0c;
			rdesc[0x97] = rdesc[0xcb] = rdesc[0xe2] = 0x00;
		}
	return rdesc;
}

__attribute__((used)) static int zc_input_mapping(struct hid_device *hdev, struct hid_input *hi,
	struct hid_field *field, struct hid_usage *usage,
	unsigned long **bit, int *max)
{
	int i;
	struct zc_device *zc = hid_get_drvdata(hdev);
	zc->input_ep81 = hi->input;

	if ((usage->hid & HID_USAGE_PAGE) != HID_UP_CONSUMER)
		return 0;

	dbg_hid("zynacron input mapping event [0x%x]\n",
		usage->hid & HID_USAGE);

	switch (usage->hid & HID_USAGE) {
	/* report 2 */
	case 0x10:
		zc_map_key_clear(KEY_MODE);
		break;
	case 0x30:
		zc_map_key_clear(KEY_SCREEN);
		break;
	case 0x70:
		zc_map_key_clear(KEY_INFO);
		break;
	/* report 3 */
	case 0x04:
		zc_map_key_clear(KEY_RADIO);
		break;
	/* report 4 */
	case 0x0d:
		zc_map_key_clear(KEY_PVR);
		break;
	case 0x25:
		zc_map_key_clear(KEY_TV);
		break;
	case 0x47:
		zc_map_key_clear(KEY_AUDIO);
		break;
	case 0x49:
		zc_map_key_clear(KEY_AUX);
		break;
	case 0x4a:
		zc_map_key_clear(KEY_VIDEO);
		break;
	case 0x48:
		zc_map_key_clear(KEY_DVD);
		break;
	case 0x24:
		zc_map_key_clear(KEY_MENU);
		break;
	case 0x32:
		zc_map_key_clear(KEY_TEXT);
		break;
	default:
		return 0;
	}

	for (i = 0; i < 4; i++)
		zc->last_key[i] = 0;

	return 1;
}

__attribute__((used)) static int zc_raw_event(struct hid_device *hdev, struct hid_report *report,
	 u8 *data, int size)
{
	struct zc_device *zc = hid_get_drvdata(hdev);
	int ret = 0;
	unsigned key;
	unsigned short index;

	if (report->id == data[0]) {

		/* break keys */
		for (index = 0; index < 4; index++) {
			key = zc->last_key[index];
			if (key) {
				input_event(zc->input_ep81, EV_KEY, key, 0);
				zc->last_key[index] = 0;
			}
		}

		key = 0;
		switch (report->id) {
		case 0x02:
		case 0x03:
			switch (data[1]) {
			case 0x10:
				key = KEY_MODE;
				index = 0;
				break;
			case 0x30:
				key = KEY_SCREEN;
				index = 1;
				break;
			case 0x70:
				key = KEY_INFO;
				index = 2;
				break;
			case 0x04:
				key = KEY_RADIO;
				index = 3;
				break;
			}

			if (key) {
				input_event(zc->input_ep81, EV_KEY, key, 1);
				zc->last_key[index] = key;
			}

			ret = 1;
			break;
		}
	}

	return ret;
}

__attribute__((used)) static int zc_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
	int ret;
	struct zc_device *zc;

	zc = devm_kzalloc(&hdev->dev, sizeof(*zc), GFP_KERNEL);
	if (zc == NULL) {
		hid_err(hdev, "can't alloc descriptor\n");
		return -ENOMEM;
	}

	hid_set_drvdata(hdev, zc);

	ret = hid_parse(hdev);
	if (ret) {
		hid_err(hdev, "parse failed\n");
		return ret;
	}

	ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
	if (ret) {
		hid_err(hdev, "hw start failed\n");
		return ret;
	}

	return 0;
}

