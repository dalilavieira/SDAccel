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
typedef  int u32 ;
struct hwicap_drvdata {scalar_t__ base_address; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EBUSY ; 
 int EIO ; 
 int XHI_CR_FIFO_CLR_MASK ; 
 scalar_t__ XHI_CR_OFFSET ; 
 int XHI_CR_READ_MASK ; 
 int XHI_CR_SW_RESET_MASK ; 
 int XHI_CR_WRITE_MASK ; 
 int XHI_MAX_READ_TRANSACTION_WORDS ; 
 int XHI_MAX_RETRIES ; 
 int XHI_OP_READ ; 
 int XHI_OP_SHIFT ; 
 int XHI_OP_WRITE ; 
 int XHI_REGISTER_SHIFT ; 
 scalar_t__ XHI_RFO_OFFSET ; 
 scalar_t__ XHI_RF_OFFSET ; 
 int XHI_SR_DONE_MASK ; 
 scalar_t__ XHI_SR_OFFSET ; 
 scalar_t__ XHI_SZ_OFFSET ; 
 int XHI_TYPE_1 ; 
 int XHI_TYPE_SHIFT ; 
 scalar_t__ XHI_WFV_OFFSET ; 
 scalar_t__ XHI_WF_OFFSET ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int in_be32 (scalar_t__) ; 
 int /*<<< orphan*/  out_be32 (scalar_t__,int) ; 

__attribute__((used)) static inline u32 hwicap_type_1_read(u32 reg)
{
	return (XHI_TYPE_1 << XHI_TYPE_SHIFT) |
		(reg << XHI_REGISTER_SHIFT) |
		(XHI_OP_READ << XHI_OP_SHIFT);
}

__attribute__((used)) static inline u32 hwicap_type_1_write(u32 reg)
{
	return (XHI_TYPE_1 << XHI_TYPE_SHIFT) |
		(reg << XHI_REGISTER_SHIFT) |
		(XHI_OP_WRITE << XHI_OP_SHIFT);
}

__attribute__((used)) static inline void fifo_icap_fifo_write(struct hwicap_drvdata *drvdata,
		u32 data)
{
	dev_dbg(drvdata->dev, "fifo_write: %x\n", data);
	out_be32(drvdata->base_address + XHI_WF_OFFSET, data);
}

__attribute__((used)) static inline u32 fifo_icap_fifo_read(struct hwicap_drvdata *drvdata)
{
	u32 data = in_be32(drvdata->base_address + XHI_RF_OFFSET);
	dev_dbg(drvdata->dev, "fifo_read: %x\n", data);
	return data;
}

__attribute__((used)) static inline void fifo_icap_set_read_size(struct hwicap_drvdata *drvdata,
		u32 data)
{
	out_be32(drvdata->base_address + XHI_SZ_OFFSET, data);
}

__attribute__((used)) static inline void fifo_icap_start_config(struct hwicap_drvdata *drvdata)
{
	out_be32(drvdata->base_address + XHI_CR_OFFSET, XHI_CR_WRITE_MASK);
	dev_dbg(drvdata->dev, "configuration started\n");
}

__attribute__((used)) static inline void fifo_icap_start_readback(struct hwicap_drvdata *drvdata)
{
	out_be32(drvdata->base_address + XHI_CR_OFFSET, XHI_CR_READ_MASK);
	dev_dbg(drvdata->dev, "readback started\n");
}

u32 fifo_icap_get_status(struct hwicap_drvdata *drvdata)
{
	u32 status = in_be32(drvdata->base_address + XHI_SR_OFFSET);
	dev_dbg(drvdata->dev, "Getting status = %x\n", status);
	return status;
}

__attribute__((used)) static inline u32 fifo_icap_busy(struct hwicap_drvdata *drvdata)
{
	u32 status = in_be32(drvdata->base_address + XHI_SR_OFFSET);
	return (status & XHI_SR_DONE_MASK) ? 0 : 1;
}

__attribute__((used)) static inline u32 fifo_icap_write_fifo_vacancy(
		struct hwicap_drvdata *drvdata)
{
	return in_be32(drvdata->base_address + XHI_WFV_OFFSET);
}

__attribute__((used)) static inline u32 fifo_icap_read_fifo_occupancy(
		struct hwicap_drvdata *drvdata)
{
	return in_be32(drvdata->base_address + XHI_RFO_OFFSET);
}

int fifo_icap_set_configuration(struct hwicap_drvdata *drvdata,
		u32 *frame_buffer, u32 num_words)
{

	u32 write_fifo_vacancy = 0;
	u32 retries = 0;
	u32 remaining_words;

	dev_dbg(drvdata->dev, "fifo_set_configuration\n");

	/*
	 * Check if the ICAP device is Busy with the last Read/Write
	 */
	if (fifo_icap_busy(drvdata))
		return -EBUSY;

	/*
	 * Set up the buffer pointer and the words to be transferred.
	 */
	remaining_words = num_words;

	while (remaining_words > 0) {
		/*
		 * Wait until we have some data in the fifo.
		 */
		while (write_fifo_vacancy == 0) {
			write_fifo_vacancy =
				fifo_icap_write_fifo_vacancy(drvdata);
			retries++;
			if (retries > XHI_MAX_RETRIES)
				return -EIO;
		}

		/*
		 * Write data into the Write FIFO.
		 */
		while ((write_fifo_vacancy != 0) &&
				(remaining_words > 0)) {
			fifo_icap_fifo_write(drvdata, *frame_buffer);

			remaining_words--;
			write_fifo_vacancy--;
			frame_buffer++;
		}
		/* Start pushing whatever is in the FIFO into the ICAP. */
		fifo_icap_start_config(drvdata);
	}

	/* Wait until the write has finished. */
	while (fifo_icap_busy(drvdata)) {
		retries++;
		if (retries > XHI_MAX_RETRIES)
			break;
	}

	dev_dbg(drvdata->dev, "done fifo_set_configuration\n");

	/*
	 * If the requested number of words have not been read from
	 * the device then indicate failure.
	 */
	if (remaining_words != 0)
		return -EIO;

	return 0;
}

int fifo_icap_get_configuration(struct hwicap_drvdata *drvdata,
		u32 *frame_buffer, u32 num_words)
{

	u32 read_fifo_occupancy = 0;
	u32 retries = 0;
	u32 *data = frame_buffer;
	u32 remaining_words;
	u32 words_to_read;

	dev_dbg(drvdata->dev, "fifo_get_configuration\n");

	/*
	 * Check if the ICAP device is Busy with the last Write/Read
	 */
	if (fifo_icap_busy(drvdata))
		return -EBUSY;

	remaining_words = num_words;

	while (remaining_words > 0) {
		words_to_read = remaining_words;
		/* The hardware has a limit on the number of words
		   that can be read at one time.  */
		if (words_to_read > XHI_MAX_READ_TRANSACTION_WORDS)
			words_to_read = XHI_MAX_READ_TRANSACTION_WORDS;

		remaining_words -= words_to_read;

		fifo_icap_set_read_size(drvdata, words_to_read);
		fifo_icap_start_readback(drvdata);

		while (words_to_read > 0) {
			/* Wait until we have some data in the fifo. */
			while (read_fifo_occupancy == 0) {
				read_fifo_occupancy =
					fifo_icap_read_fifo_occupancy(drvdata);
				retries++;
				if (retries > XHI_MAX_RETRIES)
					return -EIO;
			}

			if (read_fifo_occupancy > words_to_read)
				read_fifo_occupancy = words_to_read;

			words_to_read -= read_fifo_occupancy;

			/* Read the data from the Read FIFO. */
			while (read_fifo_occupancy != 0) {
				*data++ = fifo_icap_fifo_read(drvdata);
				read_fifo_occupancy--;
			}
		}
	}

	dev_dbg(drvdata->dev, "done fifo_get_configuration\n");

	return 0;
}

void fifo_icap_reset(struct hwicap_drvdata *drvdata)
{
	u32 reg_data;
	/*
	 * Reset the device by setting/clearing the RESET bit in the
	 * Control Register.
	 */
	reg_data = in_be32(drvdata->base_address + XHI_CR_OFFSET);

	out_be32(drvdata->base_address + XHI_CR_OFFSET,
				reg_data | XHI_CR_SW_RESET_MASK);

	out_be32(drvdata->base_address + XHI_CR_OFFSET,
				reg_data & (~XHI_CR_SW_RESET_MASK));

}

void fifo_icap_flush_fifo(struct hwicap_drvdata *drvdata)
{
	u32 reg_data;
	/*
	 * Flush the FIFO by setting/clearing the FIFO Clear bit in the
	 * Control Register.
	 */
	reg_data = in_be32(drvdata->base_address + XHI_CR_OFFSET);

	out_be32(drvdata->base_address + XHI_CR_OFFSET,
				reg_data | XHI_CR_FIFO_CLR_MASK);

	out_be32(drvdata->base_address + XHI_CR_OFFSET,
				reg_data & (~XHI_CR_FIFO_CLR_MASK));
}

