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
typedef  int u8 ;
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct t4_input_report {int button; TYPE_1__* contact; } ;
struct hid_report {int dummy; } ;
struct hid_device {int product; int /*<<< orphan*/  dev; } ;
struct alps_dev {int max_fingers; unsigned int y_max; unsigned int y_min; int /*<<< orphan*/  input2; int /*<<< orphan*/  input; } ;
struct TYPE_2__ {int x_hi; int x_lo; int y_hi; int y_lo; int palm; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_MT_POSITION_X ; 
 int /*<<< orphan*/  ABS_MT_POSITION_Y ; 
 int /*<<< orphan*/  ABS_MT_PRESSURE ; 
 int /*<<< orphan*/  BTN_LEFT ; 
 int /*<<< orphan*/  BTN_MIDDLE ; 
 int /*<<< orphan*/  BTN_RIGHT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_FEATURE_REPORT ; 
#define  HID_PRODUCT_ID_T4_BTNLESS 132 
 int /*<<< orphan*/  HID_REQ_GET_REPORT ; 
 int /*<<< orphan*/  HID_REQ_SET_REPORT ; 
 int /*<<< orphan*/  MT_TOOL_FINGER ; 
 int /*<<< orphan*/  REL_X ; 
 int /*<<< orphan*/  REL_Y ; 
 int T4_CMD_REGISTER_READ ; 
 int T4_CMD_REGISTER_WRITE ; 
 int T4_FEATURE_REPORT_ID ; 
 int T4_FEATURE_REPORT_LEN ; 
#define  U1_ABSOLUTE_REPORT_ID 131 
 int U1_CMD_REGISTER_READ ; 
 int U1_CMD_REGISTER_WRITE ; 
#define  U1_FEATURE_REPORT_ID 130 
 int U1_FEATURE_REPORT_LEN ; 
 int U1_FEATURE_REPORT_LEN_ALL ; 
#define  U1_MOUSE_REPORT_ID 129 
#define  U1_SP_ABSOLUTE_REPORT_ID 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int,...) ; 
 void* get_unaligned_le16 (int*) ; 
 struct alps_dev* hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_raw_request (struct hid_device*,int,int*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_mt_report_slot_state (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_mt_slot (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_mt_sync_frame (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_report_abs (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  input_report_key (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_rel (int /*<<< orphan*/ ,int /*<<< orphan*/ ,short) ; 
 int /*<<< orphan*/  input_sync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_unaligned_le32 (scalar_t__,int*) ; 

__attribute__((used)) static u16 t4_calc_check_sum(u8 *buffer,
		unsigned long offset, unsigned long length)
{
	u16 sum1 = 0xFF, sum2 = 0xFF;
	unsigned long i = 0;

	if (offset + length >= 50)
		return 0;

	while (length > 0) {
		u32 tlen = length > 20 ? 20 : length;

		length -= tlen;

		do {
			sum1 += buffer[offset + i];
			sum2 += sum1;
			i++;
		} while (--tlen > 0);

		sum1 = (sum1 & 0xFF) + (sum1 >> 8);
		sum2 = (sum2 & 0xFF) + (sum2 >> 8);
	}

	sum1 = (sum1 & 0xFF) + (sum1 >> 8);
	sum2 = (sum2 & 0xFF) + (sum2 >> 8);

	return(sum2 << 8 | sum1);
}

__attribute__((used)) static int t4_read_write_register(struct hid_device *hdev, u32 address,
	u8 *read_val, u8 write_val, bool read_flag)
{
	int ret;
	u16 check_sum;
	u8 *input;
	u8 *readbuf = NULL;

	input = kzalloc(T4_FEATURE_REPORT_LEN, GFP_KERNEL);
	if (!input)
		return -ENOMEM;

	input[0] = T4_FEATURE_REPORT_ID;
	if (read_flag) {
		input[1] = T4_CMD_REGISTER_READ;
		input[8] = 0x00;
	} else {
		input[1] = T4_CMD_REGISTER_WRITE;
		input[8] = write_val;
	}
	put_unaligned_le32(address, input + 2);
	input[6] = 1;
	input[7] = 0;

	/* Calculate the checksum */
	check_sum = t4_calc_check_sum(input, 1, 8);
	input[9] = (u8)check_sum;
	input[10] = (u8)(check_sum >> 8);
	input[11] = 0;

	ret = hid_hw_raw_request(hdev, T4_FEATURE_REPORT_ID, input,
			T4_FEATURE_REPORT_LEN,
			HID_FEATURE_REPORT, HID_REQ_SET_REPORT);

	if (ret < 0) {
		dev_err(&hdev->dev, "failed to read command (%d)\n", ret);
		goto exit;
	}

	if (read_flag) {
		readbuf = kzalloc(T4_FEATURE_REPORT_LEN, GFP_KERNEL);
		if (!readbuf) {
			ret = -ENOMEM;
			goto exit;
		}

		ret = hid_hw_raw_request(hdev, T4_FEATURE_REPORT_ID, readbuf,
				T4_FEATURE_REPORT_LEN,
				HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
		if (ret < 0) {
			dev_err(&hdev->dev, "failed read register (%d)\n", ret);
			goto exit_readbuf;
		}

		ret = -EINVAL;

		if (*(u32 *)&readbuf[6] != address) {
			dev_err(&hdev->dev, "read register address error (%x,%x)\n",
				*(u32 *)&readbuf[6], address);
			goto exit_readbuf;
		}

		if (*(u16 *)&readbuf[10] != 1) {
			dev_err(&hdev->dev, "read register size error (%x)\n",
				*(u16 *)&readbuf[10]);
			goto exit_readbuf;
		}

		check_sum = t4_calc_check_sum(readbuf, 6, 7);
		if (*(u16 *)&readbuf[13] != check_sum) {
			dev_err(&hdev->dev, "read register checksum error (%x,%x)\n",
				*(u16 *)&readbuf[13], check_sum);
			goto exit_readbuf;
		}

		*read_val = readbuf[12];
	}

	ret = 0;

exit_readbuf:
	kfree(readbuf);
exit:
	kfree(input);
	return ret;
}

__attribute__((used)) static int u1_read_write_register(struct hid_device *hdev, u32 address,
	u8 *read_val, u8 write_val, bool read_flag)
{
	int ret, i;
	u8 check_sum;
	u8 *input;
	u8 *readbuf;

	input = kzalloc(U1_FEATURE_REPORT_LEN, GFP_KERNEL);
	if (!input)
		return -ENOMEM;

	input[0] = U1_FEATURE_REPORT_ID;
	if (read_flag) {
		input[1] = U1_CMD_REGISTER_READ;
		input[6] = 0x00;
	} else {
		input[1] = U1_CMD_REGISTER_WRITE;
		input[6] = write_val;
	}

	put_unaligned_le32(address, input + 2);

	/* Calculate the checksum */
	check_sum = U1_FEATURE_REPORT_LEN_ALL;
	for (i = 0; i < U1_FEATURE_REPORT_LEN - 1; i++)
		check_sum += input[i];

	input[7] = check_sum;
	ret = hid_hw_raw_request(hdev, U1_FEATURE_REPORT_ID, input,
			U1_FEATURE_REPORT_LEN,
			HID_FEATURE_REPORT, HID_REQ_SET_REPORT);

	if (ret < 0) {
		dev_err(&hdev->dev, "failed to read command (%d)\n", ret);
		goto exit;
	}

	if (read_flag) {
		readbuf = kzalloc(U1_FEATURE_REPORT_LEN, GFP_KERNEL);
		if (!readbuf) {
			ret = -ENOMEM;
			goto exit;
		}

		ret = hid_hw_raw_request(hdev, U1_FEATURE_REPORT_ID, readbuf,
				U1_FEATURE_REPORT_LEN,
				HID_FEATURE_REPORT, HID_REQ_GET_REPORT);

		if (ret < 0) {
			dev_err(&hdev->dev, "failed read register (%d)\n", ret);
			kfree(readbuf);
			goto exit;
		}

		*read_val = readbuf[6];

		kfree(readbuf);
	}

	ret = 0;

exit:
	kfree(input);
	return ret;
}

__attribute__((used)) static int t4_raw_event(struct alps_dev *hdata, u8 *data, int size)
{
	unsigned int x, y, z;
	int i;
	struct t4_input_report *p_report = (struct t4_input_report *)data;

	if (!data)
		return 0;
	for (i = 0; i < hdata->max_fingers; i++) {
		x = p_report->contact[i].x_hi << 8 | p_report->contact[i].x_lo;
		y = p_report->contact[i].y_hi << 8 | p_report->contact[i].y_lo;
		y = hdata->y_max - y + hdata->y_min;
		z = (p_report->contact[i].palm < 0x80 &&
			p_report->contact[i].palm > 0) * 62;
		if (x == 0xffff) {
			x = 0;
			y = 0;
			z = 0;
		}
		input_mt_slot(hdata->input, i);

		input_mt_report_slot_state(hdata->input,
			MT_TOOL_FINGER, z != 0);

		if (!z)
			continue;

		input_report_abs(hdata->input, ABS_MT_POSITION_X, x);
		input_report_abs(hdata->input, ABS_MT_POSITION_Y, y);
		input_report_abs(hdata->input, ABS_MT_PRESSURE, z);
	}
	input_mt_sync_frame(hdata->input);

	input_report_key(hdata->input, BTN_LEFT, p_report->button);

	input_sync(hdata->input);
	return 1;
}

__attribute__((used)) static int u1_raw_event(struct alps_dev *hdata, u8 *data, int size)
{
	unsigned int x, y, z;
	int i;
	short sp_x, sp_y;

	if (!data)
		return 0;
	switch (data[0]) {
	case U1_MOUSE_REPORT_ID:
		break;
	case U1_FEATURE_REPORT_ID:
		break;
	case U1_ABSOLUTE_REPORT_ID:
		for (i = 0; i < hdata->max_fingers; i++) {
			u8 *contact = &data[i * 5];

			x = get_unaligned_le16(contact + 3);
			y = get_unaligned_le16(contact + 5);
			z = contact[7] & 0x7F;

			input_mt_slot(hdata->input, i);

			if (z != 0) {
				input_mt_report_slot_state(hdata->input,
					MT_TOOL_FINGER, 1);
				input_report_abs(hdata->input,
					ABS_MT_POSITION_X, x);
				input_report_abs(hdata->input,
					ABS_MT_POSITION_Y, y);
				input_report_abs(hdata->input,
					ABS_MT_PRESSURE, z);
			} else {
				input_mt_report_slot_state(hdata->input,
					MT_TOOL_FINGER, 0);
			}
		}

		input_mt_sync_frame(hdata->input);

		input_report_key(hdata->input, BTN_LEFT,
			data[1] & 0x1);
		input_report_key(hdata->input, BTN_RIGHT,
			(data[1] & 0x2));
		input_report_key(hdata->input, BTN_MIDDLE,
			(data[1] & 0x4));

		input_sync(hdata->input);

		return 1;

	case U1_SP_ABSOLUTE_REPORT_ID:
		sp_x = get_unaligned_le16(data+2);
		sp_y = get_unaligned_le16(data+4);

		sp_x = sp_x / 8;
		sp_y = sp_y / 8;

		input_report_rel(hdata->input2, REL_X, sp_x);
		input_report_rel(hdata->input2, REL_Y, sp_y);

		input_report_key(hdata->input2, BTN_LEFT,
			data[1] & 0x1);
		input_report_key(hdata->input2, BTN_RIGHT,
			(data[1] & 0x2));
		input_report_key(hdata->input2, BTN_MIDDLE,
			(data[1] & 0x4));

		input_sync(hdata->input2);

		return 1;
	}

	return 0;
}

__attribute__((used)) static int alps_raw_event(struct hid_device *hdev,
		struct hid_report *report, u8 *data, int size)
{
	int ret = 0;
	struct alps_dev *hdata = hid_get_drvdata(hdev);

	switch (hdev->product) {
	case HID_PRODUCT_ID_T4_BTNLESS:
		ret = t4_raw_event(hdata, data, size);
		break;
	default:
		ret = u1_raw_event(hdata, data, size);
		break;
	}
	return ret;
}

