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
typedef  scalar_t__ u8 ;
typedef  int u64 ;
typedef  unsigned int u32 ;
typedef  size_t u16 ;
struct vio_device_id {int dummy; } ;
struct device {int dummy; } ;
struct vio_dev {int /*<<< orphan*/  unit_address; int /*<<< orphan*/  irq; struct device dev; } ;
struct tpm_input_header {void* length; void* tag; void* ordinal; } ;
struct tpm_chip {struct device dev; } ;
struct tpm_buf {int flags; int /*<<< orphan*/ * data; int /*<<< orphan*/  data_page; } ;
struct ibmvtpm_crq_queue {size_t index; size_t num_entry; struct ibmvtpm_dev* crq_addr; } ;
struct ibmvtpm_dev {int tpm_processing_cmd; size_t res_len; size_t rtce_size; unsigned int rtce_dma_handle; unsigned int crq_dma_handle; int valid; int msg; unsigned int vtpm_version; int /*<<< orphan*/  rtce_lock; int /*<<< orphan*/  wq; struct ibmvtpm_crq_queue crq_queue; struct vio_dev* vdev; struct device* dev; void* len; void* data; struct ibmvtpm_dev* rtce_buf; } ;
struct ibmvtpm_crq {int tpm_processing_cmd; size_t res_len; size_t rtce_size; unsigned int rtce_dma_handle; unsigned int crq_dma_handle; int valid; int msg; unsigned int vtpm_version; int /*<<< orphan*/  rtce_lock; int /*<<< orphan*/  wq; struct ibmvtpm_crq_queue crq_queue; struct vio_dev* vdev; struct device* dev; void* len; void* data; struct ibmvtpm_crq* rtce_buf; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  void* __be32 ;
typedef  void* __be16 ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 int CRQ_RES_BUF_SIZE ; 
 int /*<<< orphan*/  DMA_BIDIRECTIONAL ; 
 int EINTR ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_HIGHUSER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int H_BUSY ; 
 int /*<<< orphan*/  H_ENABLE_CRQ ; 
 int /*<<< orphan*/  H_FREE_CRQ ; 
 int H_IN_PROGRESS ; 
 scalar_t__ H_IS_LONG_BUSY (int) ; 
 int /*<<< orphan*/  H_REG_CRQ ; 
 int H_RESOURCE ; 
 int /*<<< orphan*/  H_SEND_CRQ ; 
 int H_SUCCESS ; 
#define  IBMVTPM_VALID_CMD 134 
 int INIT_CRQ_CMD ; 
 int INIT_CRQ_COMP_CMD ; 
#define  INIT_CRQ_COMP_RES 133 
#define  INIT_CRQ_RES 132 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct tpm_chip*) ; 
 unsigned int PAGE_SIZE ; 
 int PTR_ERR (struct tpm_chip*) ; 
 int TPM_BUF_OVERFLOW ; 
 scalar_t__ TPM_TIMEOUT_RANGE_US ; 
#define  VALID_INIT_CRQ 131 
 scalar_t__ VTPM_GET_RTCE_BUFFER_SIZE ; 
#define  VTPM_GET_RTCE_BUFFER_SIZE_RES 130 
 scalar_t__ VTPM_GET_VERSION ; 
#define  VTPM_GET_VERSION_RES 129 
 int VTPM_MSG_RES ; 
 scalar_t__ VTPM_PREPARE_TO_SUSPEND ; 
 scalar_t__ VTPM_TPM_COMMAND ; 
#define  VTPM_TPM_COMMAND_RES 128 
 int /*<<< orphan*/  WARN (int,char*) ; 
 int /*<<< orphan*/  __free_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alloc_page (int /*<<< orphan*/ ) ; 
 size_t be16_to_cpu (void*) ; 
 unsigned int be32_to_cpu (void*) ; 
 void* cpu_to_be16 (size_t const) ; 
 void* cpu_to_be32 (unsigned int const) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct ibmvtpm_dev*) ; 
 void* dma_map_single (struct device*,struct ibmvtpm_dev*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ dma_mapping_error (struct device*,unsigned int) ; 
 int /*<<< orphan*/  dma_unmap_single (struct device*,unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct ibmvtpm_dev*) ; 
 int /*<<< orphan*/  free_page (unsigned long) ; 
 scalar_t__ get_zeroed_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct ibmvtpm_dev*) ; 
 struct ibmvtpm_dev* kmalloc (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * kmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kunmap (int /*<<< orphan*/ ) ; 
 struct ibmvtpm_dev* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void*,void*,size_t) ; 
 int /*<<< orphan*/  memset (struct ibmvtpm_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int plpar_hcall_norets (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ibmvtpm_dev*) ; 
 int /*<<< orphan*/  smp_rmb () ; 
 int /*<<< orphan*/  smp_wmb () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int tpm_chip_register (struct tpm_chip*) ; 
 int /*<<< orphan*/  tpm_chip_unregister (struct tpm_chip*) ; 
 int /*<<< orphan*/  tpm_ibmvtpm ; 
 int /*<<< orphan*/  tpm_ibmvtpm_driver_name ; 
 struct tpm_chip* tpmm_chip_alloc (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usleep_range (scalar_t__,unsigned int) ; 
 int vio_enable_interrupts (struct vio_dev*) ; 
 int wait_event_interruptible (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 

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

__attribute__((used)) static int ibmvtpm_send_crq_word(struct vio_dev *vdev, u64 w1)
{
	return plpar_hcall_norets(H_SEND_CRQ, vdev->unit_address, w1, 0);
}

__attribute__((used)) static int ibmvtpm_send_crq(struct vio_dev *vdev,
		u8 valid, u8 msg, u16 len, u32 data)
{
	u64 w1 = ((u64)valid << 56) | ((u64)msg << 48) | ((u64)len << 32) |
		(u64)data;
	return ibmvtpm_send_crq_word(vdev, w1);
}

__attribute__((used)) static int tpm_ibmvtpm_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
	struct ibmvtpm_dev *ibmvtpm = dev_get_drvdata(&chip->dev);
	u16 len;
	int sig;

	if (!ibmvtpm->rtce_buf) {
		dev_err(ibmvtpm->dev, "ibmvtpm device is not ready\n");
		return 0;
	}

	sig = wait_event_interruptible(ibmvtpm->wq, !ibmvtpm->tpm_processing_cmd);
	if (sig)
		return -EINTR;

	len = ibmvtpm->res_len;

	if (count < len) {
		dev_err(ibmvtpm->dev,
			"Invalid size in recv: count=%zd, crq_size=%d\n",
			count, len);
		return -EIO;
	}

	spin_lock(&ibmvtpm->rtce_lock);
	memcpy((void *)buf, (void *)ibmvtpm->rtce_buf, len);
	memset(ibmvtpm->rtce_buf, 0, len);
	ibmvtpm->res_len = 0;
	spin_unlock(&ibmvtpm->rtce_lock);
	return len;
}

__attribute__((used)) static int tpm_ibmvtpm_send(struct tpm_chip *chip, u8 *buf, size_t count)
{
	struct ibmvtpm_dev *ibmvtpm = dev_get_drvdata(&chip->dev);
	int rc, sig;

	if (!ibmvtpm->rtce_buf) {
		dev_err(ibmvtpm->dev, "ibmvtpm device is not ready\n");
		return 0;
	}

	if (count > ibmvtpm->rtce_size) {
		dev_err(ibmvtpm->dev,
			"Invalid size in send: count=%zd, rtce_size=%d\n",
			count, ibmvtpm->rtce_size);
		return -EIO;
	}

	if (ibmvtpm->tpm_processing_cmd) {
		dev_info(ibmvtpm->dev,
		         "Need to wait for TPM to finish\n");
		/* wait for previous command to finish */
		sig = wait_event_interruptible(ibmvtpm->wq, !ibmvtpm->tpm_processing_cmd);
		if (sig)
			return -EINTR;
	}

	spin_lock(&ibmvtpm->rtce_lock);
	ibmvtpm->res_len = 0;
	memcpy((void *)ibmvtpm->rtce_buf, (void *)buf, count);

	/*
	 * set the processing flag before the Hcall, since we may get the
	 * result (interrupt) before even being able to check rc.
	 */
	ibmvtpm->tpm_processing_cmd = true;

	rc = ibmvtpm_send_crq(ibmvtpm->vdev,
			IBMVTPM_VALID_CMD, VTPM_TPM_COMMAND,
			count, ibmvtpm->rtce_dma_handle);
	if (rc != H_SUCCESS) {
		dev_err(ibmvtpm->dev, "tpm_ibmvtpm_send failed rc=%d\n", rc);
		rc = 0;
		ibmvtpm->tpm_processing_cmd = false;
	} else
		rc = 0;

	spin_unlock(&ibmvtpm->rtce_lock);
	return rc;
}

__attribute__((used)) static void tpm_ibmvtpm_cancel(struct tpm_chip *chip)
{
	return;
}

__attribute__((used)) static u8 tpm_ibmvtpm_status(struct tpm_chip *chip)
{
	return 0;
}

__attribute__((used)) static int ibmvtpm_crq_get_rtce_size(struct ibmvtpm_dev *ibmvtpm)
{
	int rc;

	rc = ibmvtpm_send_crq(ibmvtpm->vdev,
			IBMVTPM_VALID_CMD, VTPM_GET_RTCE_BUFFER_SIZE, 0, 0);
	if (rc != H_SUCCESS)
		dev_err(ibmvtpm->dev,
			"ibmvtpm_crq_get_rtce_size failed rc=%d\n", rc);

	return rc;
}

__attribute__((used)) static int ibmvtpm_crq_get_version(struct ibmvtpm_dev *ibmvtpm)
{
	int rc;

	rc = ibmvtpm_send_crq(ibmvtpm->vdev,
			IBMVTPM_VALID_CMD, VTPM_GET_VERSION, 0, 0);
	if (rc != H_SUCCESS)
		dev_err(ibmvtpm->dev,
			"ibmvtpm_crq_get_version failed rc=%d\n", rc);

	return rc;
}

__attribute__((used)) static int ibmvtpm_crq_send_init_complete(struct ibmvtpm_dev *ibmvtpm)
{
	int rc;

	rc = ibmvtpm_send_crq_word(ibmvtpm->vdev, INIT_CRQ_COMP_CMD);
	if (rc != H_SUCCESS)
		dev_err(ibmvtpm->dev,
			"ibmvtpm_crq_send_init_complete failed rc=%d\n", rc);

	return rc;
}

__attribute__((used)) static int ibmvtpm_crq_send_init(struct ibmvtpm_dev *ibmvtpm)
{
	int rc;

	rc = ibmvtpm_send_crq_word(ibmvtpm->vdev, INIT_CRQ_CMD);
	if (rc != H_SUCCESS)
		dev_err(ibmvtpm->dev,
			"ibmvtpm_crq_send_init failed rc=%d\n", rc);

	return rc;
}

__attribute__((used)) static int tpm_ibmvtpm_remove(struct vio_dev *vdev)
{
	struct tpm_chip *chip = dev_get_drvdata(&vdev->dev);
	struct ibmvtpm_dev *ibmvtpm = dev_get_drvdata(&chip->dev);
	int rc = 0;

	tpm_chip_unregister(chip);

	free_irq(vdev->irq, ibmvtpm);

	do {
		if (rc)
			msleep(100);
		rc = plpar_hcall_norets(H_FREE_CRQ, vdev->unit_address);
	} while (rc == H_BUSY || H_IS_LONG_BUSY(rc));

	dma_unmap_single(ibmvtpm->dev, ibmvtpm->crq_dma_handle,
			 CRQ_RES_BUF_SIZE, DMA_BIDIRECTIONAL);
	free_page((unsigned long)ibmvtpm->crq_queue.crq_addr);

	if (ibmvtpm->rtce_buf) {
		dma_unmap_single(ibmvtpm->dev, ibmvtpm->rtce_dma_handle,
				 ibmvtpm->rtce_size, DMA_BIDIRECTIONAL);
		kfree(ibmvtpm->rtce_buf);
	}

	kfree(ibmvtpm);
	/* For tpm_ibmvtpm_get_desired_dma */
	dev_set_drvdata(&vdev->dev, NULL);

	return 0;
}

__attribute__((used)) static unsigned long tpm_ibmvtpm_get_desired_dma(struct vio_dev *vdev)
{
	struct tpm_chip *chip = dev_get_drvdata(&vdev->dev);
	struct ibmvtpm_dev *ibmvtpm;

	/*
	 * ibmvtpm initializes at probe time, so the data we are
	 * asking for may not be set yet. Estimate that 4K required
	 * for TCE-mapped buffer in addition to CRQ.
	 */
	if (chip)
		ibmvtpm = dev_get_drvdata(&chip->dev);
	else
		return CRQ_RES_BUF_SIZE + PAGE_SIZE;

	return CRQ_RES_BUF_SIZE + ibmvtpm->rtce_size;
}

__attribute__((used)) static int tpm_ibmvtpm_suspend(struct device *dev)
{
	struct tpm_chip *chip = dev_get_drvdata(dev);
	struct ibmvtpm_dev *ibmvtpm = dev_get_drvdata(&chip->dev);
	int rc = 0;

	rc = ibmvtpm_send_crq(ibmvtpm->vdev,
			IBMVTPM_VALID_CMD, VTPM_PREPARE_TO_SUSPEND, 0, 0);
	if (rc != H_SUCCESS)
		dev_err(ibmvtpm->dev,
			"tpm_ibmvtpm_suspend failed rc=%d\n", rc);

	return rc;
}

__attribute__((used)) static int ibmvtpm_reset_crq(struct ibmvtpm_dev *ibmvtpm)
{
	int rc = 0;

	do {
		if (rc)
			msleep(100);
		rc = plpar_hcall_norets(H_FREE_CRQ,
					ibmvtpm->vdev->unit_address);
	} while (rc == H_BUSY || H_IS_LONG_BUSY(rc));

	memset(ibmvtpm->crq_queue.crq_addr, 0, CRQ_RES_BUF_SIZE);
	ibmvtpm->crq_queue.index = 0;

	return plpar_hcall_norets(H_REG_CRQ, ibmvtpm->vdev->unit_address,
				  ibmvtpm->crq_dma_handle, CRQ_RES_BUF_SIZE);
}

__attribute__((used)) static int tpm_ibmvtpm_resume(struct device *dev)
{
	struct tpm_chip *chip = dev_get_drvdata(dev);
	struct ibmvtpm_dev *ibmvtpm = dev_get_drvdata(&chip->dev);
	int rc = 0;

	do {
		if (rc)
			msleep(100);
		rc = plpar_hcall_norets(H_ENABLE_CRQ,
					ibmvtpm->vdev->unit_address);
	} while (rc == H_IN_PROGRESS || rc == H_BUSY || H_IS_LONG_BUSY(rc));

	if (rc) {
		dev_err(dev, "Error enabling ibmvtpm rc=%d\n", rc);
		return rc;
	}

	rc = vio_enable_interrupts(ibmvtpm->vdev);
	if (rc) {
		dev_err(dev, "Error vio_enable_interrupts rc=%d\n", rc);
		return rc;
	}

	rc = ibmvtpm_crq_send_init(ibmvtpm);
	if (rc)
		dev_err(dev, "Error send_init rc=%d\n", rc);

	return rc;
}

__attribute__((used)) static bool tpm_ibmvtpm_req_canceled(struct tpm_chip *chip, u8 status)
{
	return (status == 0);
}

__attribute__((used)) static struct ibmvtpm_crq *ibmvtpm_crq_get_next(struct ibmvtpm_dev *ibmvtpm)
{
	struct ibmvtpm_crq_queue *crq_q = &ibmvtpm->crq_queue;
	struct ibmvtpm_crq *crq = &crq_q->crq_addr[crq_q->index];

	if (crq->valid & VTPM_MSG_RES) {
		if (++crq_q->index == crq_q->num_entry)
			crq_q->index = 0;
		smp_rmb();
	} else
		crq = NULL;
	return crq;
}

__attribute__((used)) static void ibmvtpm_crq_process(struct ibmvtpm_crq *crq,
				struct ibmvtpm_dev *ibmvtpm)
{
	int rc = 0;

	switch (crq->valid) {
	case VALID_INIT_CRQ:
		switch (crq->msg) {
		case INIT_CRQ_RES:
			dev_info(ibmvtpm->dev, "CRQ initialized\n");
			rc = ibmvtpm_crq_send_init_complete(ibmvtpm);
			if (rc)
				dev_err(ibmvtpm->dev, "Unable to send CRQ init complete rc=%d\n", rc);
			return;
		case INIT_CRQ_COMP_RES:
			dev_info(ibmvtpm->dev,
				 "CRQ initialization completed\n");
			return;
		default:
			dev_err(ibmvtpm->dev, "Unknown crq message type: %d\n", crq->msg);
			return;
		}
	case IBMVTPM_VALID_CMD:
		switch (crq->msg) {
		case VTPM_GET_RTCE_BUFFER_SIZE_RES:
			if (be16_to_cpu(crq->len) <= 0) {
				dev_err(ibmvtpm->dev, "Invalid rtce size\n");
				return;
			}
			ibmvtpm->rtce_size = be16_to_cpu(crq->len);
			ibmvtpm->rtce_buf = kmalloc(ibmvtpm->rtce_size,
						    GFP_ATOMIC);
			if (!ibmvtpm->rtce_buf) {
				dev_err(ibmvtpm->dev, "Failed to allocate memory for rtce buffer\n");
				return;
			}

			ibmvtpm->rtce_dma_handle = dma_map_single(ibmvtpm->dev,
				ibmvtpm->rtce_buf, ibmvtpm->rtce_size,
				DMA_BIDIRECTIONAL);

			if (dma_mapping_error(ibmvtpm->dev,
					      ibmvtpm->rtce_dma_handle)) {
				kfree(ibmvtpm->rtce_buf);
				ibmvtpm->rtce_buf = NULL;
				dev_err(ibmvtpm->dev, "Failed to dma map rtce buffer\n");
			}

			return;
		case VTPM_GET_VERSION_RES:
			ibmvtpm->vtpm_version = be32_to_cpu(crq->data);
			return;
		case VTPM_TPM_COMMAND_RES:
			/* len of the data in rtce buffer */
			ibmvtpm->res_len = be16_to_cpu(crq->len);
			ibmvtpm->tpm_processing_cmd = false;
			wake_up_interruptible(&ibmvtpm->wq);
			return;
		default:
			return;
		}
	}
	return;
}

__attribute__((used)) static irqreturn_t ibmvtpm_interrupt(int irq, void *vtpm_instance)
{
	struct ibmvtpm_dev *ibmvtpm = (struct ibmvtpm_dev *) vtpm_instance;
	struct ibmvtpm_crq *crq;

	/* while loop is needed for initial setup (get version and
	 * get rtce_size). There should be only one tpm request at any
	 * given time.
	 */
	while ((crq = ibmvtpm_crq_get_next(ibmvtpm)) != NULL) {
		ibmvtpm_crq_process(crq, ibmvtpm);
		crq->valid = 0;
		smp_wmb();
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int tpm_ibmvtpm_probe(struct vio_dev *vio_dev,
				   const struct vio_device_id *id)
{
	struct ibmvtpm_dev *ibmvtpm;
	struct device *dev = &vio_dev->dev;
	struct ibmvtpm_crq_queue *crq_q;
	struct tpm_chip *chip;
	int rc = -ENOMEM, rc1;

	chip = tpmm_chip_alloc(dev, &tpm_ibmvtpm);
	if (IS_ERR(chip))
		return PTR_ERR(chip);

	ibmvtpm = kzalloc(sizeof(struct ibmvtpm_dev), GFP_KERNEL);
	if (!ibmvtpm) {
		dev_err(dev, "kzalloc for ibmvtpm failed\n");
		goto cleanup;
	}

	ibmvtpm->dev = dev;
	ibmvtpm->vdev = vio_dev;

	crq_q = &ibmvtpm->crq_queue;
	crq_q->crq_addr = (struct ibmvtpm_crq *)get_zeroed_page(GFP_KERNEL);
	if (!crq_q->crq_addr) {
		dev_err(dev, "Unable to allocate memory for crq_addr\n");
		goto cleanup;
	}

	crq_q->num_entry = CRQ_RES_BUF_SIZE / sizeof(*crq_q->crq_addr);
	ibmvtpm->crq_dma_handle = dma_map_single(dev, crq_q->crq_addr,
						 CRQ_RES_BUF_SIZE,
						 DMA_BIDIRECTIONAL);

	if (dma_mapping_error(dev, ibmvtpm->crq_dma_handle)) {
		dev_err(dev, "dma mapping failed\n");
		goto cleanup;
	}

	rc = plpar_hcall_norets(H_REG_CRQ, vio_dev->unit_address,
				ibmvtpm->crq_dma_handle, CRQ_RES_BUF_SIZE);
	if (rc == H_RESOURCE)
		rc = ibmvtpm_reset_crq(ibmvtpm);

	if (rc) {
		dev_err(dev, "Unable to register CRQ rc=%d\n", rc);
		goto reg_crq_cleanup;
	}

	rc = request_irq(vio_dev->irq, ibmvtpm_interrupt, 0,
			 tpm_ibmvtpm_driver_name, ibmvtpm);
	if (rc) {
		dev_err(dev, "Error %d register irq 0x%x\n", rc, vio_dev->irq);
		goto init_irq_cleanup;
	}

	rc = vio_enable_interrupts(vio_dev);
	if (rc) {
		dev_err(dev, "Error %d enabling interrupts\n", rc);
		goto init_irq_cleanup;
	}

	init_waitqueue_head(&ibmvtpm->wq);

	crq_q->index = 0;

	dev_set_drvdata(&chip->dev, ibmvtpm);

	spin_lock_init(&ibmvtpm->rtce_lock);

	rc = ibmvtpm_crq_send_init(ibmvtpm);
	if (rc)
		goto init_irq_cleanup;

	rc = ibmvtpm_crq_get_version(ibmvtpm);
	if (rc)
		goto init_irq_cleanup;

	rc = ibmvtpm_crq_get_rtce_size(ibmvtpm);
	if (rc)
		goto init_irq_cleanup;

	return tpm_chip_register(chip);
init_irq_cleanup:
	do {
		rc1 = plpar_hcall_norets(H_FREE_CRQ, vio_dev->unit_address);
	} while (rc1 == H_BUSY || H_IS_LONG_BUSY(rc1));
reg_crq_cleanup:
	dma_unmap_single(dev, ibmvtpm->crq_dma_handle, CRQ_RES_BUF_SIZE,
			 DMA_BIDIRECTIONAL);
cleanup:
	if (ibmvtpm) {
		if (crq_q->crq_addr)
			free_page((unsigned long)crq_q->crq_addr);
		kfree(ibmvtpm);
	}

	return rc;
}

