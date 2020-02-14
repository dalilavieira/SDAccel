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
typedef  void* u32 ;
typedef  int /*<<< orphan*/  trans_delay ;
typedef  int /*<<< orphan*/  trans ;
struct spi_transfer {int cs_change; scalar_t__* rx_buf; int len; scalar_t__* tx_buf; void* delay_usecs; } ;
struct spi_message {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct spi_device {int bits_per_word; struct device dev; int /*<<< orphan*/  irq; int /*<<< orphan*/  mode; int /*<<< orphan*/  master; } ;
struct ec_response_get_protocol_info {int dummy; } ;
struct ec_host_response {int data_len; scalar_t__ result; } ;
struct ec_host_request {int dummy; } ;
struct device_node {int dummy; } ;
struct cros_ec_spi {void* last_transfer_ns; struct spi_device* spi; void* end_of_msg_delay; void* start_of_msg_delay; } ;
struct cros_ec_device {scalar_t__* din; int din_size; int (* cmd_xfer ) (struct cros_ec_device*,struct cros_ec_command*) ;int (* pkt_xfer ) (struct cros_ec_device*,struct cros_ec_command*) ;int dout_size; int /*<<< orphan*/  phys_name; int /*<<< orphan*/  irq; struct cros_ec_spi* priv; struct device* dev; scalar_t__* dout; } ;
struct cros_ec_command {int insize; scalar_t__ command; scalar_t__* data; scalar_t__ result; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EAGAIN ; 
 int EBADMSG ; 
 scalar_t__ EC_CMD_REBOOT_EC ; 
 int /*<<< orphan*/  EC_MSG_DEADLINE_MS ; 
 int EC_MSG_PREAMBLE_COUNT ; 
 int /*<<< orphan*/  EC_MSG_TX_PROTO_BYTES ; 
 int /*<<< orphan*/  EC_REBOOT_DELAY_MS ; 
 scalar_t__ EC_SPI_FRAME_START ; 
 scalar_t__ EC_SPI_NOT_READY ; 
 scalar_t__ EC_SPI_PAST_END ; 
 unsigned long EC_SPI_RECOVERY_TIME_NS ; 
 scalar_t__ EC_SPI_RX_BAD_DATA ; 
 int EMSGSIZE ; 
 int ENOMEM ; 
 int ENOSPC ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  SPI_MODE_0 ; 
 int cros_ec_check_result (struct cros_ec_device*,struct cros_ec_command*) ; 
 int cros_ec_prepare_tx (struct cros_ec_device*,struct cros_ec_command*) ; 
 int cros_ec_register (struct cros_ec_device*) ; 
 int /*<<< orphan*/  cros_ec_remove (struct cros_ec_device*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  kfree (scalar_t__*) ; 
 void* ktime_get_ns () ; 
 scalar_t__* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  memmove (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  memset (struct spi_transfer*,int /*<<< orphan*/ ,int) ; 
 int min (int,int) ; 
 unsigned long msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ndelay (unsigned long) ; 
 int of_property_read_u32 (struct device_node*,char*,void**) ; 
 int /*<<< orphan*/  spi_bus_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spi_bus_unlock (int /*<<< orphan*/ ) ; 
 struct cros_ec_device* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct cros_ec_device*) ; 
 int spi_setup (struct spi_device*) ; 
 int spi_sync_locked (struct spi_device*,struct spi_message*) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 

__attribute__((used)) static void debug_packet(struct device *dev, const char *name, u8 *ptr,
			 int len)
{
#ifdef DEBUG
	int i;

	dev_dbg(dev, "%s: ", name);
	for (i = 0; i < len; i++)
		pr_cont(" %02x", ptr[i]);

	pr_cont("\n");
#endif
}

__attribute__((used)) static int terminate_request(struct cros_ec_device *ec_dev)
{
	struct cros_ec_spi *ec_spi = ec_dev->priv;
	struct spi_message msg;
	struct spi_transfer trans;
	int ret;

	/*
	 * Turn off CS, possibly adding a delay to ensure the rising edge
	 * doesn't come too soon after the end of the data.
	 */
	spi_message_init(&msg);
	memset(&trans, 0, sizeof(trans));
	trans.delay_usecs = ec_spi->end_of_msg_delay;
	spi_message_add_tail(&trans, &msg);

	ret = spi_sync_locked(ec_spi->spi, &msg);

	/* Reset end-of-response timer */
	ec_spi->last_transfer_ns = ktime_get_ns();
	if (ret < 0) {
		dev_err(ec_dev->dev,
			"cs-deassert spi transfer failed: %d\n",
			ret);
	}

	return ret;
}

__attribute__((used)) static int receive_n_bytes(struct cros_ec_device *ec_dev, u8 *buf, int n)
{
	struct cros_ec_spi *ec_spi = ec_dev->priv;
	struct spi_transfer trans;
	struct spi_message msg;
	int ret;

	BUG_ON(buf - ec_dev->din + n > ec_dev->din_size);

	memset(&trans, 0, sizeof(trans));
	trans.cs_change = 1;
	trans.rx_buf = buf;
	trans.len = n;

	spi_message_init(&msg);
	spi_message_add_tail(&trans, &msg);
	ret = spi_sync_locked(ec_spi->spi, &msg);
	if (ret < 0)
		dev_err(ec_dev->dev, "spi transfer failed: %d\n", ret);

	return ret;
}

__attribute__((used)) static int cros_ec_spi_receive_packet(struct cros_ec_device *ec_dev,
				      int need_len)
{
	struct ec_host_response *response;
	u8 *ptr, *end;
	int ret;
	unsigned long deadline;
	int todo;

	BUG_ON(ec_dev->din_size < EC_MSG_PREAMBLE_COUNT);

	/* Receive data until we see the header byte */
	deadline = jiffies + msecs_to_jiffies(EC_MSG_DEADLINE_MS);
	while (true) {
		unsigned long start_jiffies = jiffies;

		ret = receive_n_bytes(ec_dev,
				      ec_dev->din,
				      EC_MSG_PREAMBLE_COUNT);
		if (ret < 0)
			return ret;

		ptr = ec_dev->din;
		for (end = ptr + EC_MSG_PREAMBLE_COUNT; ptr != end; ptr++) {
			if (*ptr == EC_SPI_FRAME_START) {
				dev_dbg(ec_dev->dev, "msg found at %zd\n",
					ptr - ec_dev->din);
				break;
			}
		}
		if (ptr != end)
			break;

		/*
		 * Use the time at the start of the loop as a timeout.  This
		 * gives us one last shot at getting the transfer and is useful
		 * in case we got context switched out for a while.
		 */
		if (time_after(start_jiffies, deadline)) {
			dev_warn(ec_dev->dev, "EC failed to respond in time\n");
			return -ETIMEDOUT;
		}
	}

	/*
	 * ptr now points to the header byte. Copy any valid data to the
	 * start of our buffer
	 */
	todo = end - ++ptr;
	BUG_ON(todo < 0 || todo > ec_dev->din_size);
	todo = min(todo, need_len);
	memmove(ec_dev->din, ptr, todo);
	ptr = ec_dev->din + todo;
	dev_dbg(ec_dev->dev, "need %d, got %d bytes from preamble\n",
		need_len, todo);
	need_len -= todo;

	/* If the entire response struct wasn't read, get the rest of it. */
	if (todo < sizeof(*response)) {
		ret = receive_n_bytes(ec_dev, ptr, sizeof(*response) - todo);
		if (ret < 0)
			return -EBADMSG;
		ptr += (sizeof(*response) - todo);
		todo = sizeof(*response);
	}

	response = (struct ec_host_response *)ec_dev->din;

	/* Abort if data_len is too large. */
	if (response->data_len > ec_dev->din_size)
		return -EMSGSIZE;

	/* Receive data until we have it all */
	while (need_len > 0) {
		/*
		 * We can't support transfers larger than the SPI FIFO size
		 * unless we have DMA. We don't have DMA on the ISP SPI ports
		 * for Exynos. We need a way of asking SPI driver for
		 * maximum-supported transfer size.
		 */
		todo = min(need_len, 256);
		dev_dbg(ec_dev->dev, "loop, todo=%d, need_len=%d, ptr=%zd\n",
			todo, need_len, ptr - ec_dev->din);

		ret = receive_n_bytes(ec_dev, ptr, todo);
		if (ret < 0)
			return ret;

		ptr += todo;
		need_len -= todo;
	}

	dev_dbg(ec_dev->dev, "loop done, ptr=%zd\n", ptr - ec_dev->din);

	return 0;
}

__attribute__((used)) static int cros_ec_spi_receive_response(struct cros_ec_device *ec_dev,
					int need_len)
{
	u8 *ptr, *end;
	int ret;
	unsigned long deadline;
	int todo;

	BUG_ON(ec_dev->din_size < EC_MSG_PREAMBLE_COUNT);

	/* Receive data until we see the header byte */
	deadline = jiffies + msecs_to_jiffies(EC_MSG_DEADLINE_MS);
	while (true) {
		unsigned long start_jiffies = jiffies;

		ret = receive_n_bytes(ec_dev,
				      ec_dev->din,
				      EC_MSG_PREAMBLE_COUNT);
		if (ret < 0)
			return ret;

		ptr = ec_dev->din;
		for (end = ptr + EC_MSG_PREAMBLE_COUNT; ptr != end; ptr++) {
			if (*ptr == EC_SPI_FRAME_START) {
				dev_dbg(ec_dev->dev, "msg found at %zd\n",
					ptr - ec_dev->din);
				break;
			}
		}
		if (ptr != end)
			break;

		/*
		 * Use the time at the start of the loop as a timeout.  This
		 * gives us one last shot at getting the transfer and is useful
		 * in case we got context switched out for a while.
		 */
		if (time_after(start_jiffies, deadline)) {
			dev_warn(ec_dev->dev, "EC failed to respond in time\n");
			return -ETIMEDOUT;
		}
	}

	/*
	 * ptr now points to the header byte. Copy any valid data to the
	 * start of our buffer
	 */
	todo = end - ++ptr;
	BUG_ON(todo < 0 || todo > ec_dev->din_size);
	todo = min(todo, need_len);
	memmove(ec_dev->din, ptr, todo);
	ptr = ec_dev->din + todo;
	dev_dbg(ec_dev->dev, "need %d, got %d bytes from preamble\n",
		 need_len, todo);
	need_len -= todo;

	/* Receive data until we have it all */
	while (need_len > 0) {
		/*
		 * We can't support transfers larger than the SPI FIFO size
		 * unless we have DMA. We don't have DMA on the ISP SPI ports
		 * for Exynos. We need a way of asking SPI driver for
		 * maximum-supported transfer size.
		 */
		todo = min(need_len, 256);
		dev_dbg(ec_dev->dev, "loop, todo=%d, need_len=%d, ptr=%zd\n",
			todo, need_len, ptr - ec_dev->din);

		ret = receive_n_bytes(ec_dev, ptr, todo);
		if (ret < 0)
			return ret;

		debug_packet(ec_dev->dev, "interim", ptr, todo);
		ptr += todo;
		need_len -= todo;
	}

	dev_dbg(ec_dev->dev, "loop done, ptr=%zd\n", ptr - ec_dev->din);

	return 0;
}

__attribute__((used)) static int cros_ec_pkt_xfer_spi(struct cros_ec_device *ec_dev,
				struct cros_ec_command *ec_msg)
{
	struct ec_host_response *response;
	struct cros_ec_spi *ec_spi = ec_dev->priv;
	struct spi_transfer trans, trans_delay;
	struct spi_message msg;
	int i, len;
	u8 *ptr;
	u8 *rx_buf;
	u8 sum;
	u8 rx_byte;
	int ret = 0, final_ret;
	unsigned long delay;

	len = cros_ec_prepare_tx(ec_dev, ec_msg);
	dev_dbg(ec_dev->dev, "prepared, len=%d\n", len);

	/* If it's too soon to do another transaction, wait */
	delay = ktime_get_ns() - ec_spi->last_transfer_ns;
	if (delay < EC_SPI_RECOVERY_TIME_NS)
		ndelay(EC_SPI_RECOVERY_TIME_NS - delay);

	rx_buf = kzalloc(len, GFP_KERNEL);
	if (!rx_buf)
		return -ENOMEM;

	spi_bus_lock(ec_spi->spi->master);

	/*
	 * Leave a gap between CS assertion and clocking of data to allow the
	 * EC time to wakeup.
	 */
	spi_message_init(&msg);
	if (ec_spi->start_of_msg_delay) {
		memset(&trans_delay, 0, sizeof(trans_delay));
		trans_delay.delay_usecs = ec_spi->start_of_msg_delay;
		spi_message_add_tail(&trans_delay, &msg);
	}

	/* Transmit phase - send our message */
	memset(&trans, 0, sizeof(trans));
	trans.tx_buf = ec_dev->dout;
	trans.rx_buf = rx_buf;
	trans.len = len;
	trans.cs_change = 1;
	spi_message_add_tail(&trans, &msg);
	ret = spi_sync_locked(ec_spi->spi, &msg);

	/* Get the response */
	if (!ret) {
		/* Verify that EC can process command */
		for (i = 0; i < len; i++) {
			rx_byte = rx_buf[i];
			/*
			 * Seeing the PAST_END, RX_BAD_DATA, or NOT_READY
			 * markers are all signs that the EC didn't fully
			 * receive our command. e.g., if the EC is flashing
			 * itself, it can't respond to any commands and instead
			 * clocks out EC_SPI_PAST_END from its SPI hardware
			 * buffer. Similar occurrences can happen if the AP is
			 * too slow to clock out data after asserting CS -- the
			 * EC will abort and fill its buffer with
			 * EC_SPI_RX_BAD_DATA.
			 *
			 * In all cases, these errors should be safe to retry.
			 * Report -EAGAIN and let the caller decide what to do
			 * about that.
			 */
			if (rx_byte == EC_SPI_PAST_END  ||
			    rx_byte == EC_SPI_RX_BAD_DATA ||
			    rx_byte == EC_SPI_NOT_READY) {
				ret = -EAGAIN;
				break;
			}
		}
	}

	if (!ret)
		ret = cros_ec_spi_receive_packet(ec_dev,
				ec_msg->insize + sizeof(*response));
	else if (ret != -EAGAIN)
		dev_err(ec_dev->dev, "spi transfer failed: %d\n", ret);

	final_ret = terminate_request(ec_dev);

	spi_bus_unlock(ec_spi->spi->master);

	if (!ret)
		ret = final_ret;
	if (ret < 0)
		goto exit;

	ptr = ec_dev->din;

	/* check response error code */
	response = (struct ec_host_response *)ptr;
	ec_msg->result = response->result;

	ret = cros_ec_check_result(ec_dev, ec_msg);
	if (ret)
		goto exit;

	len = response->data_len;
	sum = 0;
	if (len > ec_msg->insize) {
		dev_err(ec_dev->dev, "packet too long (%d bytes, expected %d)",
			len, ec_msg->insize);
		ret = -EMSGSIZE;
		goto exit;
	}

	for (i = 0; i < sizeof(*response); i++)
		sum += ptr[i];

	/* copy response packet payload and compute checksum */
	memcpy(ec_msg->data, ptr + sizeof(*response), len);
	for (i = 0; i < len; i++)
		sum += ec_msg->data[i];

	if (sum) {
		dev_err(ec_dev->dev,
			"bad packet checksum, calculated %x\n",
			sum);
		ret = -EBADMSG;
		goto exit;
	}

	ret = len;
exit:
	kfree(rx_buf);
	if (ec_msg->command == EC_CMD_REBOOT_EC)
		msleep(EC_REBOOT_DELAY_MS);

	return ret;
}

__attribute__((used)) static int cros_ec_cmd_xfer_spi(struct cros_ec_device *ec_dev,
				struct cros_ec_command *ec_msg)
{
	struct cros_ec_spi *ec_spi = ec_dev->priv;
	struct spi_transfer trans;
	struct spi_message msg;
	int i, len;
	u8 *ptr;
	u8 *rx_buf;
	u8 rx_byte;
	int sum;
	int ret = 0, final_ret;
	unsigned long delay;

	len = cros_ec_prepare_tx(ec_dev, ec_msg);
	dev_dbg(ec_dev->dev, "prepared, len=%d\n", len);

	/* If it's too soon to do another transaction, wait */
	delay = ktime_get_ns() - ec_spi->last_transfer_ns;
	if (delay < EC_SPI_RECOVERY_TIME_NS)
		ndelay(EC_SPI_RECOVERY_TIME_NS - delay);

	rx_buf = kzalloc(len, GFP_KERNEL);
	if (!rx_buf)
		return -ENOMEM;

	spi_bus_lock(ec_spi->spi->master);

	/* Transmit phase - send our message */
	debug_packet(ec_dev->dev, "out", ec_dev->dout, len);
	memset(&trans, 0, sizeof(trans));
	trans.tx_buf = ec_dev->dout;
	trans.rx_buf = rx_buf;
	trans.len = len;
	trans.cs_change = 1;
	spi_message_init(&msg);
	spi_message_add_tail(&trans, &msg);
	ret = spi_sync_locked(ec_spi->spi, &msg);

	/* Get the response */
	if (!ret) {
		/* Verify that EC can process command */
		for (i = 0; i < len; i++) {
			rx_byte = rx_buf[i];
			/* See comments in cros_ec_pkt_xfer_spi() */
			if (rx_byte == EC_SPI_PAST_END  ||
			    rx_byte == EC_SPI_RX_BAD_DATA ||
			    rx_byte == EC_SPI_NOT_READY) {
				ret = -EAGAIN;
				break;
			}
		}
	}

	if (!ret)
		ret = cros_ec_spi_receive_response(ec_dev,
				ec_msg->insize + EC_MSG_TX_PROTO_BYTES);
	else if (ret != -EAGAIN)
		dev_err(ec_dev->dev, "spi transfer failed: %d\n", ret);

	final_ret = terminate_request(ec_dev);

	spi_bus_unlock(ec_spi->spi->master);

	if (!ret)
		ret = final_ret;
	if (ret < 0)
		goto exit;

	ptr = ec_dev->din;

	/* check response error code */
	ec_msg->result = ptr[0];
	ret = cros_ec_check_result(ec_dev, ec_msg);
	if (ret)
		goto exit;

	len = ptr[1];
	sum = ptr[0] + ptr[1];
	if (len > ec_msg->insize) {
		dev_err(ec_dev->dev, "packet too long (%d bytes, expected %d)",
			len, ec_msg->insize);
		ret = -ENOSPC;
		goto exit;
	}

	/* copy response packet payload and compute checksum */
	for (i = 0; i < len; i++) {
		sum += ptr[i + 2];
		if (ec_msg->insize)
			ec_msg->data[i] = ptr[i + 2];
	}
	sum &= 0xff;

	debug_packet(ec_dev->dev, "in", ptr, len + 3);

	if (sum != ptr[len + 2]) {
		dev_err(ec_dev->dev,
			"bad packet checksum, expected %02x, got %02x\n",
			sum, ptr[len + 2]);
		ret = -EBADMSG;
		goto exit;
	}

	ret = len;
exit:
	kfree(rx_buf);
	if (ec_msg->command == EC_CMD_REBOOT_EC)
		msleep(EC_REBOOT_DELAY_MS);

	return ret;
}

__attribute__((used)) static void cros_ec_spi_dt_probe(struct cros_ec_spi *ec_spi, struct device *dev)
{
	struct device_node *np = dev->of_node;
	u32 val;
	int ret;

	ret = of_property_read_u32(np, "google,cros-ec-spi-pre-delay", &val);
	if (!ret)
		ec_spi->start_of_msg_delay = val;

	ret = of_property_read_u32(np, "google,cros-ec-spi-msg-delay", &val);
	if (!ret)
		ec_spi->end_of_msg_delay = val;
}

__attribute__((used)) static int cros_ec_spi_probe(struct spi_device *spi)
{
	struct device *dev = &spi->dev;
	struct cros_ec_device *ec_dev;
	struct cros_ec_spi *ec_spi;
	int err;

	spi->bits_per_word = 8;
	spi->mode = SPI_MODE_0;
	err = spi_setup(spi);
	if (err < 0)
		return err;

	ec_spi = devm_kzalloc(dev, sizeof(*ec_spi), GFP_KERNEL);
	if (ec_spi == NULL)
		return -ENOMEM;
	ec_spi->spi = spi;
	ec_dev = devm_kzalloc(dev, sizeof(*ec_dev), GFP_KERNEL);
	if (!ec_dev)
		return -ENOMEM;

	/* Check for any DT properties */
	cros_ec_spi_dt_probe(ec_spi, dev);

	spi_set_drvdata(spi, ec_dev);
	ec_dev->dev = dev;
	ec_dev->priv = ec_spi;
	ec_dev->irq = spi->irq;
	ec_dev->cmd_xfer = cros_ec_cmd_xfer_spi;
	ec_dev->pkt_xfer = cros_ec_pkt_xfer_spi;
	ec_dev->phys_name = dev_name(&ec_spi->spi->dev);
	ec_dev->din_size = EC_MSG_PREAMBLE_COUNT +
			   sizeof(struct ec_host_response) +
			   sizeof(struct ec_response_get_protocol_info);
	ec_dev->dout_size = sizeof(struct ec_host_request);

	ec_spi->last_transfer_ns = ktime_get_ns();

	err = cros_ec_register(ec_dev);
	if (err) {
		dev_err(dev, "cannot register EC\n");
		return err;
	}

	device_init_wakeup(&spi->dev, true);

	return 0;
}

__attribute__((used)) static int cros_ec_spi_remove(struct spi_device *spi)
{
	struct cros_ec_device *ec_dev;

	ec_dev = spi_get_drvdata(spi);
	cros_ec_remove(ec_dev);

	return 0;
}

