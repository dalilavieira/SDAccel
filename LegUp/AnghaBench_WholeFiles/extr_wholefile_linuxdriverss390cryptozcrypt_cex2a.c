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
struct zcrypt_queue {int online; int /*<<< orphan*/  reply; int /*<<< orphan*/  load; struct ap_queue* queue; int /*<<< orphan*/  ops; } ;
struct zcrypt_card {char* type_string; int online; int /*<<< orphan*/  user_space_type; int /*<<< orphan*/  speed_rating; void* max_exp_bit_length; void* max_mod_size; void* min_mod_size; struct ap_card* card; } ;
struct error_hdr {int reply_code; } ;
struct ap_queue {struct zcrypt_queue* private; int /*<<< orphan*/  request_timeout; int /*<<< orphan*/  qid; } ;
struct ap_message {struct error_hdr* message; struct error_hdr* private; } ;
struct ap_device {int device_type; int /*<<< orphan*/  device; } ;
struct TYPE_2__ {scalar_t__ device_type; } ;
struct ap_card {unsigned int functions; struct zcrypt_card* private; TYPE_1__ ap_dev; } ;
typedef  int /*<<< orphan*/  CEX3A_SPEED_IDX ;
typedef  int /*<<< orphan*/  CEX2A_SPEED_IDX ;

/* Variables and functions */
#define  AP_DEVICE_TYPE_CEX2A 139 
#define  AP_DEVICE_TYPE_CEX3A 138 
 unsigned int AP_FUNC_CRT4K ; 
 unsigned int AP_FUNC_MEX4K ; 
 int AP_QID_CARD (int /*<<< orphan*/ ) ; 
 int AP_QID_QUEUE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CEX2A_CLEANUP_TIME ; 
 void* CEX2A_MAX_MOD_SIZE ; 
 int /*<<< orphan*/  CEX2A_MAX_RESPONSE_SIZE ; 
 void* CEX2A_MIN_MOD_SIZE ; 
 void* CEX3A_MAX_MOD_SIZE ; 
 int /*<<< orphan*/  CEX3A_MAX_RESPONSE_SIZE ; 
 int /*<<< orphan*/  DBF_ERR ; 
 int /*<<< orphan*/  DBF_WARN ; 
 int EAGAIN ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  MSGTYPE50_NAME ; 
 int /*<<< orphan*/  MSGTYPE50_VARIANT_DEFAULT ; 
#define  REP82_ERROR_EVEN_MOD_IN_OPND 137 
#define  REP82_ERROR_INVALID_DOMAIN_PENDING 136 
#define  REP82_ERROR_INVALID_DOMAIN_PRECHECK 135 
#define  REP82_ERROR_INVALID_SPECIAL_CMD 134 
#define  REP82_ERROR_MACHINE_FAILURE 133 
#define  REP82_ERROR_MESSAGE_TYPE 132 
#define  REP82_ERROR_OPERAND_INVALID 131 
#define  REP82_ERROR_OPERAND_SIZE 130 
#define  REP82_ERROR_TRANSPORT_FAIL 129 
#define  REP88_ERROR_MESSAGE_MALFORMD 128 
 int /*<<< orphan*/  ZCRYPT_CEX2A ; 
 int /*<<< orphan*/  ZCRYPT_CEX3A ; 
 int /*<<< orphan*/  ZCRYPT_DBF (int /*<<< orphan*/ ,char*,int,int,int) ; 
 int /*<<< orphan*/  ap_queue_init_reply (struct ap_queue*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ap_queue_remove (struct ap_queue*) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  kzfree (struct error_hdr*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int const*,int) ; 
 int /*<<< orphan*/  memset (struct ap_message*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_err (char*,int,int) ; 
 struct ap_card* to_ap_card (int /*<<< orphan*/ *) ; 
 struct ap_queue* to_ap_queue (int /*<<< orphan*/ *) ; 
 struct zcrypt_card* zcrypt_card_alloc () ; 
 int /*<<< orphan*/  zcrypt_card_free (struct zcrypt_card*) ; 
 int zcrypt_card_register (struct zcrypt_card*) ; 
 int /*<<< orphan*/  zcrypt_card_unregister (struct zcrypt_card*) ; 
 int /*<<< orphan*/  zcrypt_msgtype (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct zcrypt_queue* zcrypt_queue_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zcrypt_queue_free (struct zcrypt_queue*) ; 
 int zcrypt_queue_register (struct zcrypt_queue*) ; 
 int /*<<< orphan*/  zcrypt_queue_unregister (struct zcrypt_queue*) ; 
 int /*<<< orphan*/  zcrypt_rescan_req ; 

__attribute__((used)) static inline int ap_test_bit(unsigned int *ptr, unsigned int nr)
{
	return (*ptr & (0x80000000u >> nr)) != 0;
}

__attribute__((used)) static inline void ap_init_message(struct ap_message *ap_msg)
{
	memset(ap_msg, 0, sizeof(*ap_msg));
}

__attribute__((used)) static inline void ap_release_message(struct ap_message *ap_msg)
{
	kzfree(ap_msg->message);
	kzfree(ap_msg->private);
}

__attribute__((used)) static inline int convert_error(struct zcrypt_queue *zq,
				struct ap_message *reply)
{
	struct error_hdr *ehdr = reply->message;
	int card = AP_QID_CARD(zq->queue->qid);
	int queue = AP_QID_QUEUE(zq->queue->qid);

	switch (ehdr->reply_code) {
	case REP82_ERROR_OPERAND_INVALID:
	case REP82_ERROR_OPERAND_SIZE:
	case REP82_ERROR_EVEN_MOD_IN_OPND:
	case REP88_ERROR_MESSAGE_MALFORMD:
	case REP82_ERROR_INVALID_DOMAIN_PRECHECK:
	case REP82_ERROR_INVALID_DOMAIN_PENDING:
	case REP82_ERROR_INVALID_SPECIAL_CMD:
	//   REP88_ERROR_INVALID_KEY		// '82' CEX2A
	//   REP88_ERROR_OPERAND		// '84' CEX2A
	//   REP88_ERROR_OPERAND_EVEN_MOD	// '85' CEX2A
		/* Invalid input data. */
		ZCRYPT_DBF(DBF_WARN,
			   "device=%02x.%04x reply=0x%02x => rc=EINVAL\n",
			   card, queue, ehdr->reply_code);
		return -EINVAL;
	case REP82_ERROR_MESSAGE_TYPE:
	//   REP88_ERROR_MESSAGE_TYPE		// '20' CEX2A
		/*
		 * To sent a message of the wrong type is a bug in the
		 * device driver. Send error msg, disable the device
		 * and then repeat the request.
		 */
		atomic_set(&zcrypt_rescan_req, 1);
		zq->online = 0;
		pr_err("Cryptographic device %02x.%04x failed and was set offline\n",
		       card, queue);
		ZCRYPT_DBF(DBF_ERR,
			   "device=%02x.%04x reply=0x%02x => online=0 rc=EAGAIN\n",
			   card, queue, ehdr->reply_code);
		return -EAGAIN;
	case REP82_ERROR_TRANSPORT_FAIL:
	case REP82_ERROR_MACHINE_FAILURE:
	//   REP88_ERROR_MODULE_FAILURE		// '10' CEX2A
		/* If a card fails disable it and repeat the request. */
		atomic_set(&zcrypt_rescan_req, 1);
		zq->online = 0;
		pr_err("Cryptographic device %02x.%04x failed and was set offline\n",
		       card, queue);
		ZCRYPT_DBF(DBF_ERR,
			   "device=%02x.%04x reply=0x%02x => online=0 rc=EAGAIN\n",
			   card, queue, ehdr->reply_code);
		return -EAGAIN;
	default:
		zq->online = 0;
		pr_err("Cryptographic device %02x.%04x failed and was set offline\n",
		       card, queue);
		ZCRYPT_DBF(DBF_ERR,
			   "device=%02x.%04x reply=0x%02x => online=0 rc=EAGAIN\n",
			   card, queue, ehdr->reply_code);
		return -EAGAIN;	/* repeat the request on a different device. */
	}
}

__attribute__((used)) static int zcrypt_cex2a_card_probe(struct ap_device *ap_dev)
{
	/*
	 * Normalized speed ratings per crypto adapter
	 * MEX_1k, MEX_2k, MEX_4k, CRT_1k, CRT_2k, CRT_4k, RNG, SECKEY
	 */
	static const int CEX2A_SPEED_IDX[] = {
		800, 1000, 2000,  900, 1200, 2400, 0, 0};
	static const int CEX3A_SPEED_IDX[] = {
		400,  500, 1000,  450,	550, 1200, 0, 0};

	struct ap_card *ac = to_ap_card(&ap_dev->device);
	struct zcrypt_card *zc;
	int rc = 0;

	zc = zcrypt_card_alloc();
	if (!zc)
		return -ENOMEM;
	zc->card = ac;
	ac->private = zc;

	if (ac->ap_dev.device_type == AP_DEVICE_TYPE_CEX2A) {
		zc->min_mod_size = CEX2A_MIN_MOD_SIZE;
		zc->max_mod_size = CEX2A_MAX_MOD_SIZE;
		memcpy(zc->speed_rating, CEX2A_SPEED_IDX,
		       sizeof(CEX2A_SPEED_IDX));
		zc->max_exp_bit_length = CEX2A_MAX_MOD_SIZE;
		zc->type_string = "CEX2A";
		zc->user_space_type = ZCRYPT_CEX2A;
	} else if (ac->ap_dev.device_type == AP_DEVICE_TYPE_CEX3A) {
		zc->min_mod_size = CEX2A_MIN_MOD_SIZE;
		zc->max_mod_size = CEX2A_MAX_MOD_SIZE;
		zc->max_exp_bit_length = CEX2A_MAX_MOD_SIZE;
		if (ap_test_bit(&ac->functions, AP_FUNC_MEX4K) &&
		    ap_test_bit(&ac->functions, AP_FUNC_CRT4K)) {
			zc->max_mod_size = CEX3A_MAX_MOD_SIZE;
			zc->max_exp_bit_length = CEX3A_MAX_MOD_SIZE;
		}
		memcpy(zc->speed_rating, CEX3A_SPEED_IDX,
		       sizeof(CEX3A_SPEED_IDX));
		zc->type_string = "CEX3A";
		zc->user_space_type = ZCRYPT_CEX3A;
	} else {
		zcrypt_card_free(zc);
		return -ENODEV;
	}
	zc->online = 1;

	rc = zcrypt_card_register(zc);
	if (rc) {
		ac->private = NULL;
		zcrypt_card_free(zc);
	}

	return rc;
}

__attribute__((used)) static void zcrypt_cex2a_card_remove(struct ap_device *ap_dev)
{
	struct zcrypt_card *zc = to_ap_card(&ap_dev->device)->private;

	if (zc)
		zcrypt_card_unregister(zc);
}

__attribute__((used)) static int zcrypt_cex2a_queue_probe(struct ap_device *ap_dev)
{
	struct ap_queue *aq = to_ap_queue(&ap_dev->device);
	struct zcrypt_queue *zq = NULL;
	int rc;

	switch (ap_dev->device_type) {
	case AP_DEVICE_TYPE_CEX2A:
		zq = zcrypt_queue_alloc(CEX2A_MAX_RESPONSE_SIZE);
		if (!zq)
			return -ENOMEM;
		break;
	case AP_DEVICE_TYPE_CEX3A:
		zq = zcrypt_queue_alloc(CEX3A_MAX_RESPONSE_SIZE);
		if (!zq)
			return -ENOMEM;
		break;
	}
	if (!zq)
		return -ENODEV;
	zq->ops = zcrypt_msgtype(MSGTYPE50_NAME, MSGTYPE50_VARIANT_DEFAULT);
	zq->queue = aq;
	zq->online = 1;
	atomic_set(&zq->load, 0);
	ap_queue_init_reply(aq, &zq->reply);
	aq->request_timeout = CEX2A_CLEANUP_TIME,
	aq->private = zq;
	rc = zcrypt_queue_register(zq);
	if (rc) {
		aq->private = NULL;
		zcrypt_queue_free(zq);
	}

	return rc;
}

__attribute__((used)) static void zcrypt_cex2a_queue_remove(struct ap_device *ap_dev)
{
	struct ap_queue *aq = to_ap_queue(&ap_dev->device);
	struct zcrypt_queue *zq = aq->private;

	ap_queue_remove(aq);
	if (zq)
		zcrypt_queue_unregister(zq);
}

