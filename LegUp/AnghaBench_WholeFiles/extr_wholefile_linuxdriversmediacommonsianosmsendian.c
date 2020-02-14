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
struct smscore_device_t {int dummy; } ;

/* Variables and functions */

__attribute__((used)) inline static int sms_ir_init(struct smscore_device_t *coredev) {
	return 0;
}

__attribute__((used)) inline static void sms_ir_exit(struct smscore_device_t *coredev) {}

__attribute__((used)) inline static void sms_ir_event(struct smscore_device_t *coredev,
			const char *buf, int len) {}

void smsendian_handle_tx_message(void *buffer)
{
#ifdef __BIG_ENDIAN
	struct sms_msg_data *msg = (struct sms_msg_data *)buffer;
	int i;
	int msg_words;

	switch (msg->x_msg_header.msg_type) {
	case MSG_SMS_DATA_DOWNLOAD_REQ:
	{
		msg->msg_data[0] = le32_to_cpu((__force __le32)(msg->msg_data[0]));
		break;
	}

	default:
		msg_words = (msg->x_msg_header.msg_length -
				sizeof(struct sms_msg_hdr))/4;

		for (i = 0; i < msg_words; i++)
			msg->msg_data[i] = le32_to_cpu((__force __le32)msg->msg_data[i]);

		break;
	}
#endif /* __BIG_ENDIAN */
}

void smsendian_handle_rx_message(void *buffer)
{
#ifdef __BIG_ENDIAN
	struct sms_msg_data *msg = (struct sms_msg_data *)buffer;
	int i;
	int msg_words;

	switch (msg->x_msg_header.msg_type) {
	case MSG_SMS_GET_VERSION_EX_RES:
	{
		struct sms_version_res *ver =
			(struct sms_version_res *) msg;
		ver->chip_model = le16_to_cpu((__force __le16)ver->chip_model);
		break;
	}

	case MSG_SMS_DVBT_BDA_DATA:
	case MSG_SMS_DAB_CHANNEL:
	case MSG_SMS_DATA_MSG:
	{
		break;
	}

	default:
	{
		msg_words = (msg->x_msg_header.msg_length -
				sizeof(struct sms_msg_hdr))/4;

		for (i = 0; i < msg_words; i++)
			msg->msg_data[i] = le32_to_cpu((__force __le32)msg->msg_data[i]);

		break;
	}
	}
#endif /* __BIG_ENDIAN */
}

void smsendian_handle_message_header(void *msg)
{
#ifdef __BIG_ENDIAN
	struct sms_msg_hdr *phdr = (struct sms_msg_hdr *)msg;

	phdr->msg_type = le16_to_cpu((__force __le16)phdr->msg_type);
	phdr->msg_length = le16_to_cpu((__force __le16)phdr->msg_length);
	phdr->msg_flags = le16_to_cpu((__force __le16)phdr->msg_flags);
#endif /* __BIG_ENDIAN */
}

