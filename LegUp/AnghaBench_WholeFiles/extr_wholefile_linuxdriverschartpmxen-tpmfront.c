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
typedef  int /*<<< orphan*/  wait_queue_head_t ;
typedef  int u8 ;
typedef  unsigned int u32 ;
typedef  int /*<<< orphan*/  const u16 ;
struct xenbus_transaction {int dummy; } ;
struct xenbus_device_id {int dummy; } ;
struct device {int dummy; } ;
struct xenbus_device {int const state; struct device dev; int /*<<< orphan*/  otherend; int /*<<< orphan*/  nodename; } ;
struct vtpm_shared_page {int state; int nr_extra_pages; size_t length; } ;
struct tpm_private {int irq; struct tpm_chip* chip; struct vtpm_shared_page* shr; scalar_t__ ring_ref; int /*<<< orphan*/  evtchn; int /*<<< orphan*/  read_queue; } ;
struct tpm_input_header {void* ordinal; void* length; void* tag; } ;
struct tpm_chip {int flags; unsigned long timeout_c; struct device dev; TYPE_1__* ops; } ;
struct tpm_buf {int* data; int flags; int /*<<< orphan*/  data_page; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  scalar_t__ grant_ref_t ;
typedef  enum xenbus_state { ____Placeholder_xenbus_state } xenbus_state ;
typedef  void* __be32 ;
typedef  void* __be16 ;
struct TYPE_2__ {int (* status ) (struct tpm_chip*) ;scalar_t__ (* req_canceled ) (struct tpm_chip*,int) ;} ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 int EAGAIN ; 
 int ECANCELED ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 long ERESTARTSYS ; 
 int ETIME ; 
 int /*<<< orphan*/  GFP_HIGHUSER ; 
 int GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct tpm_chip*) ; 
 unsigned int PAGE_SIZE ; 
 int PTR_ERR (struct tpm_chip*) ; 
 int /*<<< orphan*/  TIF_SIGPENDING ; 
 int TPM_BUF_OVERFLOW ; 
 int TPM_CHIP_FLAG_IRQ ; 
 unsigned int TPM_TIMEOUT ; 
 scalar_t__ TPM_TIMEOUT_RANGE_US ; 
#define  VTPM_STATE_CANCEL 135 
#define  VTPM_STATE_FINISH 134 
#define  VTPM_STATE_IDLE 133 
#define  VTPM_STATE_SUBMIT 132 
 int VTPM_STATUS_CANCELED ; 
 int VTPM_STATUS_IDLE ; 
 int VTPM_STATUS_RESULT ; 
 int VTPM_STATUS_RUNNING ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
#define  XenbusStateClosed 131 
#define  XenbusStateClosing 130 
#define  XenbusStateConnected 129 
#define  XenbusStateInitialised 128 
 int __GFP_ZERO ; 
 int /*<<< orphan*/  __free_page (int /*<<< orphan*/ ) ; 
 scalar_t__ __get_free_page (int) ; 
 int /*<<< orphan*/  alloc_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  barrier () ; 
 int /*<<< orphan*/  const be16_to_cpu (void*) ; 
 unsigned int be32_to_cpu (void*) ; 
 int bind_evtchn_to_irqhandler (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct tpm_private*) ; 
 int /*<<< orphan*/  clear_thread_flag (int /*<<< orphan*/ ) ; 
 void* cpu_to_be16 (int /*<<< orphan*/  const) ; 
 void* cpu_to_be32 (unsigned int const) ; 
 int /*<<< orphan*/  current ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct tpm_private*) ; 
 int /*<<< orphan*/  device_unregister (struct device*) ; 
 int /*<<< orphan*/  free_page (unsigned long) ; 
 scalar_t__ freezing (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gnttab_end_foreign_access (scalar_t__,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  kfree (struct tpm_private*) ; 
 int* kmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kunmap (int /*<<< orphan*/ ) ; 
 struct tpm_private* kzalloc (int,int) ; 
 int /*<<< orphan*/  memcpy (int*,...) ; 
 int /*<<< orphan*/  notify_remote_via_evtchn (int /*<<< orphan*/ ) ; 
 int stub1 (struct tpm_chip*) ; 
 scalar_t__ stub2 (struct tpm_chip*,int) ; 
 int stub3 (struct tpm_chip*) ; 
 int stub4 (struct tpm_chip*) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 
 unsigned long tpm_calc_ordinal_duration (struct tpm_chip*,unsigned int) ; 
 int tpm_chip_register (struct tpm_chip*) ; 
 int /*<<< orphan*/  tpm_chip_unregister (struct tpm_chip*) ; 
 int /*<<< orphan*/  tpm_get_timeouts (struct tpm_chip*) ; 
 int /*<<< orphan*/  tpm_vtpm ; 
 struct tpm_chip* tpmm_chip_alloc (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unbind_from_irqhandler (int,struct tpm_private*) ; 
 int /*<<< orphan*/  usleep_range (scalar_t__,unsigned int) ; 
 long wait_event_interruptible_timeout (int /*<<< orphan*/ ,int,unsigned long) ; 
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wmb () ; 
 int xenbus_alloc_evtchn (struct xenbus_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xenbus_dev_error (struct xenbus_device*,int,char*,char const*) ; 
 int /*<<< orphan*/  xenbus_dev_fatal (struct xenbus_device*,int,char*) ; 
 int /*<<< orphan*/  xenbus_frontend_closed (struct xenbus_device*) ; 
 int xenbus_grant_ring (struct xenbus_device*,struct vtpm_shared_page*,int,scalar_t__*) ; 
 int xenbus_printf (struct xenbus_transaction,int /*<<< orphan*/ ,char*,char*,...) ; 
 int /*<<< orphan*/  xenbus_read_unsigned (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xenbus_switch_state (struct xenbus_device*,int const) ; 
 int xenbus_transaction_end (struct xenbus_transaction,int) ; 
 int xenbus_transaction_start (struct xenbus_transaction*) ; 

__attribute__((used)) static inline void tpm_buf_reset(struct tpm_buf *buf, u16 tag, u32 ordinal)
{
	struct tpm_input_header *head;
	head = (struct tpm_input_header *)buf->data;
	head->tag = cpu_to_be16(tag);
	head->length = cpu_to_be32(sizeof(*head));
	head->ordinal = cpu_to_be32(ordinal);
}

__attribute__((used)) static inline int tpm_buf_init(struct tpm_buf *buf, u16 tag, u32 ordinal)
{
	buf->data_page = alloc_page(GFP_HIGHUSER);
	if (!buf->data_page)
		return -ENOMEM;

	buf->flags = 0;
	buf->data = kmap(buf->data_page);
	tpm_buf_reset(buf, tag, ordinal);
	return 0;
}

__attribute__((used)) static inline void tpm_buf_destroy(struct tpm_buf *buf)
{
	kunmap(buf->data_page);
	__free_page(buf->data_page);
}

__attribute__((used)) static inline u32 tpm_buf_length(struct tpm_buf *buf)
{
	struct tpm_input_header *head = (struct tpm_input_header *) buf->data;

	return be32_to_cpu(head->length);
}

__attribute__((used)) static inline u16 tpm_buf_tag(struct tpm_buf *buf)
{
	struct tpm_input_header *head = (struct tpm_input_header *) buf->data;

	return be16_to_cpu(head->tag);
}

__attribute__((used)) static inline void tpm_buf_append(struct tpm_buf *buf,
				  const unsigned char *new_data,
				  unsigned int new_len)
{
	struct tpm_input_header *head = (struct tpm_input_header *) buf->data;
	u32 len = tpm_buf_length(buf);

	/* Return silently if overflow has already happened. */
	if (buf->flags & TPM_BUF_OVERFLOW)
		return;

	if ((len + new_len) > PAGE_SIZE) {
		WARN(1, "tpm_buf: overflow\n");
		buf->flags |= TPM_BUF_OVERFLOW;
		return;
	}

	memcpy(&buf->data[len], new_data, new_len);
	head->length = cpu_to_be32(len + new_len);
}

__attribute__((used)) static inline void tpm_buf_append_u8(struct tpm_buf *buf, const u8 value)
{
	tpm_buf_append(buf, &value, 1);
}

__attribute__((used)) static inline void tpm_buf_append_u16(struct tpm_buf *buf, const u16 value)
{
	__be16 value2 = cpu_to_be16(value);

	tpm_buf_append(buf, (u8 *) &value2, 2);
}

__attribute__((used)) static inline void tpm_buf_append_u32(struct tpm_buf *buf, const u32 value)
{
	__be32 value2 = cpu_to_be32(value);

	tpm_buf_append(buf, (u8 *) &value2, 4);
}

__attribute__((used)) static inline void tpm_msleep(unsigned int delay_msec)
{
	usleep_range((delay_msec * 1000) - TPM_TIMEOUT_RANGE_US,
		     delay_msec * 1000);
}

__attribute__((used)) static inline void tpm_add_ppi(struct tpm_chip *chip)
{
}

__attribute__((used)) static inline u32 tpm2_rc_value(u32 rc)
{
	return (rc & BIT(7)) ? rc & 0xff : rc;
}

__attribute__((used)) static bool wait_for_tpm_stat_cond(struct tpm_chip *chip, u8 mask,
					bool check_cancel, bool *canceled)
{
	u8 status = chip->ops->status(chip);

	*canceled = false;
	if ((status & mask) == mask)
		return true;
	if (check_cancel && chip->ops->req_canceled(chip, status)) {
		*canceled = true;
		return true;
	}
	return false;
}

__attribute__((used)) static int wait_for_tpm_stat(struct tpm_chip *chip, u8 mask,
		unsigned long timeout, wait_queue_head_t *queue,
		bool check_cancel)
{
	unsigned long stop;
	long rc;
	u8 status;
	bool canceled = false;

	/* check current status */
	status = chip->ops->status(chip);
	if ((status & mask) == mask)
		return 0;

	stop = jiffies + timeout;

	if (chip->flags & TPM_CHIP_FLAG_IRQ) {
again:
		timeout = stop - jiffies;
		if ((long)timeout <= 0)
			return -ETIME;
		rc = wait_event_interruptible_timeout(*queue,
			wait_for_tpm_stat_cond(chip, mask, check_cancel,
					       &canceled),
			timeout);
		if (rc > 0) {
			if (canceled)
				return -ECANCELED;
			return 0;
		}
		if (rc == -ERESTARTSYS && freezing(current)) {
			clear_thread_flag(TIF_SIGPENDING);
			goto again;
		}
	} else {
		do {
			tpm_msleep(TPM_TIMEOUT);
			status = chip->ops->status(chip);
			if ((status & mask) == mask)
				return 0;
		} while (time_before(jiffies, stop));
	}
	return -ETIME;
}

__attribute__((used)) static u8 vtpm_status(struct tpm_chip *chip)
{
	struct tpm_private *priv = dev_get_drvdata(&chip->dev);
	switch (priv->shr->state) {
	case VTPM_STATE_IDLE:
		return VTPM_STATUS_IDLE | VTPM_STATUS_CANCELED;
	case VTPM_STATE_FINISH:
		return VTPM_STATUS_IDLE | VTPM_STATUS_RESULT;
	case VTPM_STATE_SUBMIT:
	case VTPM_STATE_CANCEL: /* cancel requested, not yet canceled */
		return VTPM_STATUS_RUNNING;
	default:
		return 0;
	}
}

__attribute__((used)) static bool vtpm_req_canceled(struct tpm_chip *chip, u8 status)
{
	return status & VTPM_STATUS_CANCELED;
}

__attribute__((used)) static void vtpm_cancel(struct tpm_chip *chip)
{
	struct tpm_private *priv = dev_get_drvdata(&chip->dev);
	priv->shr->state = VTPM_STATE_CANCEL;
	wmb();
	notify_remote_via_evtchn(priv->evtchn);
}

__attribute__((used)) static unsigned int shr_data_offset(struct vtpm_shared_page *shr)
{
	return sizeof(*shr) + sizeof(u32) * shr->nr_extra_pages;
}

__attribute__((used)) static int vtpm_send(struct tpm_chip *chip, u8 *buf, size_t count)
{
	struct tpm_private *priv = dev_get_drvdata(&chip->dev);
	struct vtpm_shared_page *shr = priv->shr;
	unsigned int offset = shr_data_offset(shr);

	u32 ordinal;
	unsigned long duration;

	if (offset > PAGE_SIZE)
		return -EINVAL;

	if (offset + count > PAGE_SIZE)
		return -EINVAL;

	/* Wait for completion of any existing command or cancellation */
	if (wait_for_tpm_stat(chip, VTPM_STATUS_IDLE, chip->timeout_c,
			&priv->read_queue, true) < 0) {
		vtpm_cancel(chip);
		return -ETIME;
	}

	memcpy(offset + (u8 *)shr, buf, count);
	shr->length = count;
	barrier();
	shr->state = VTPM_STATE_SUBMIT;
	wmb();
	notify_remote_via_evtchn(priv->evtchn);

	ordinal = be32_to_cpu(((struct tpm_input_header*)buf)->ordinal);
	duration = tpm_calc_ordinal_duration(chip, ordinal);

	if (wait_for_tpm_stat(chip, VTPM_STATUS_IDLE, duration,
			&priv->read_queue, true) < 0) {
		/* got a signal or timeout, try to cancel */
		vtpm_cancel(chip);
		return -ETIME;
	}

	return 0;
}

__attribute__((used)) static int vtpm_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
	struct tpm_private *priv = dev_get_drvdata(&chip->dev);
	struct vtpm_shared_page *shr = priv->shr;
	unsigned int offset = shr_data_offset(shr);
	size_t length = shr->length;

	if (shr->state == VTPM_STATE_IDLE)
		return -ECANCELED;

	/* In theory the wait at the end of _send makes this one unnecessary */
	if (wait_for_tpm_stat(chip, VTPM_STATUS_RESULT, chip->timeout_c,
			&priv->read_queue, true) < 0) {
		vtpm_cancel(chip);
		return -ETIME;
	}

	if (offset > PAGE_SIZE)
		return -EIO;

	if (offset + length > PAGE_SIZE)
		length = PAGE_SIZE - offset;

	if (length > count)
		length = count;

	memcpy(buf, offset + (u8 *)shr, length);

	return length;
}

__attribute__((used)) static irqreturn_t tpmif_interrupt(int dummy, void *dev_id)
{
	struct tpm_private *priv = dev_id;

	switch (priv->shr->state) {
	case VTPM_STATE_IDLE:
	case VTPM_STATE_FINISH:
		wake_up_interruptible(&priv->read_queue);
		break;
	case VTPM_STATE_SUBMIT:
	case VTPM_STATE_CANCEL:
	default:
		break;
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static int setup_chip(struct device *dev, struct tpm_private *priv)
{
	struct tpm_chip *chip;

	chip = tpmm_chip_alloc(dev, &tpm_vtpm);
	if (IS_ERR(chip))
		return PTR_ERR(chip);

	init_waitqueue_head(&priv->read_queue);

	priv->chip = chip;
	dev_set_drvdata(&chip->dev, priv);

	return 0;
}

__attribute__((used)) static int setup_ring(struct xenbus_device *dev, struct tpm_private *priv)
{
	struct xenbus_transaction xbt;
	const char *message = NULL;
	int rv;
	grant_ref_t gref;

	priv->shr = (void *)__get_free_page(GFP_KERNEL|__GFP_ZERO);
	if (!priv->shr) {
		xenbus_dev_fatal(dev, -ENOMEM, "allocating shared ring");
		return -ENOMEM;
	}

	rv = xenbus_grant_ring(dev, priv->shr, 1, &gref);
	if (rv < 0)
		return rv;

	priv->ring_ref = gref;

	rv = xenbus_alloc_evtchn(dev, &priv->evtchn);
	if (rv)
		return rv;

	rv = bind_evtchn_to_irqhandler(priv->evtchn, tpmif_interrupt, 0,
				       "tpmif", priv);
	if (rv <= 0) {
		xenbus_dev_fatal(dev, rv, "allocating TPM irq");
		return rv;
	}
	priv->irq = rv;

 again:
	rv = xenbus_transaction_start(&xbt);
	if (rv) {
		xenbus_dev_fatal(dev, rv, "starting transaction");
		return rv;
	}

	rv = xenbus_printf(xbt, dev->nodename,
			"ring-ref", "%u", priv->ring_ref);
	if (rv) {
		message = "writing ring-ref";
		goto abort_transaction;
	}

	rv = xenbus_printf(xbt, dev->nodename, "event-channel", "%u",
			priv->evtchn);
	if (rv) {
		message = "writing event-channel";
		goto abort_transaction;
	}

	rv = xenbus_printf(xbt, dev->nodename, "feature-protocol-v2", "1");
	if (rv) {
		message = "writing feature-protocol-v2";
		goto abort_transaction;
	}

	rv = xenbus_transaction_end(xbt, 0);
	if (rv == -EAGAIN)
		goto again;
	if (rv) {
		xenbus_dev_fatal(dev, rv, "completing transaction");
		return rv;
	}

	xenbus_switch_state(dev, XenbusStateInitialised);

	return 0;

 abort_transaction:
	xenbus_transaction_end(xbt, 1);
	if (message)
		xenbus_dev_error(dev, rv, "%s", message);

	return rv;
}

__attribute__((used)) static void ring_free(struct tpm_private *priv)
{
	if (!priv)
		return;

	if (priv->ring_ref)
		gnttab_end_foreign_access(priv->ring_ref, 0,
				(unsigned long)priv->shr);
	else
		free_page((unsigned long)priv->shr);

	if (priv->irq)
		unbind_from_irqhandler(priv->irq, priv);

	kfree(priv);
}

__attribute__((used)) static int tpmfront_probe(struct xenbus_device *dev,
		const struct xenbus_device_id *id)
{
	struct tpm_private *priv;
	int rv;

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv) {
		xenbus_dev_fatal(dev, -ENOMEM, "allocating priv structure");
		return -ENOMEM;
	}

	rv = setup_chip(&dev->dev, priv);
	if (rv) {
		kfree(priv);
		return rv;
	}

	rv = setup_ring(dev, priv);
	if (rv) {
		ring_free(priv);
		return rv;
	}

	tpm_get_timeouts(priv->chip);

	return tpm_chip_register(priv->chip);
}

__attribute__((used)) static int tpmfront_remove(struct xenbus_device *dev)
{
	struct tpm_chip *chip = dev_get_drvdata(&dev->dev);
	struct tpm_private *priv = dev_get_drvdata(&chip->dev);
	tpm_chip_unregister(chip);
	ring_free(priv);
	dev_set_drvdata(&chip->dev, NULL);
	return 0;
}

__attribute__((used)) static int tpmfront_resume(struct xenbus_device *dev)
{
	/* A suspend/resume/migrate will interrupt a vTPM anyway */
	tpmfront_remove(dev);
	return tpmfront_probe(dev, NULL);
}

__attribute__((used)) static void backend_changed(struct xenbus_device *dev,
		enum xenbus_state backend_state)
{
	switch (backend_state) {
	case XenbusStateInitialised:
	case XenbusStateConnected:
		if (dev->state == XenbusStateConnected)
			break;

		if (!xenbus_read_unsigned(dev->otherend, "feature-protocol-v2",
					  0)) {
			xenbus_dev_fatal(dev, -EINVAL,
					"vTPM protocol 2 required");
			return;
		}
		xenbus_switch_state(dev, XenbusStateConnected);
		break;

	case XenbusStateClosing:
	case XenbusStateClosed:
		device_unregister(&dev->dev);
		xenbus_frontend_closed(dev);
		break;
	default:
		break;
	}
}

