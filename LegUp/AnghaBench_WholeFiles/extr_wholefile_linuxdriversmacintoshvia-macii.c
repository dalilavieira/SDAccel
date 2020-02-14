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
struct adb_request {int sent; int complete; int reply_len; int nbytes; scalar_t__* data; int* reply; int /*<<< orphan*/  (* done ) (struct adb_request*) ;struct adb_request* next; int /*<<< orphan*/  reply_expected; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {scalar_t__ adb_type; } ;

/* Variables and functions */
 size_t ACR ; 
 int /*<<< orphan*/  ADBREQ_NOSEND ; 
 int /*<<< orphan*/  ADB_BUSRESET ; 
 scalar_t__ ADB_PACKET ; 
 int /*<<< orphan*/  ADB_READREG (int,int /*<<< orphan*/ ) ; 
 size_t B ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int CTLR_IRQ ; 
 size_t DIRB ; 
 int EINVAL ; 
 int ENODEV ; 
 size_t IFR ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_MAC_ADB ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ MAC_ADB_II ; 
 size_t SR ; 
 int SR_CTRL ; 
 int SR_EXT ; 
 int SR_INT ; 
 int SR_OUT ; 
 int ST_CMD ; 
 int ST_EVEN ; 
 int ST_IDLE ; 
 int ST_MASK ; 
 int ST_ODD ; 
 int /*<<< orphan*/  adb_input (int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  adb_request (struct adb_request*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int autopoll_devs ; 
 int command_byte ; 
 struct adb_request* current_req ; 
 int data_index ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int ffs (int) ; 
#define  idle 131 
 struct adb_request* last_req ; 
 int last_status ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
static  int macii_init_via () ; 
static  int /*<<< orphan*/  macii_interrupt (int,void*) ; 
static  void macii_poll () ; 
static  void macii_start () ; 
 int macii_state ; 
static  int macii_write (struct adb_request*) ; 
 TYPE_1__* macintosh_config ; 
 int /*<<< orphan*/  printk (char*) ; 
#define  read_done 130 
#define  reading 129 
 int reading_reply ; 
 int* reply_buf ; 
 int reply_len ; 
 int* reply_ptr ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,int /*<<< orphan*/  (*) (int,void*)) ; 
#define  sending 128 
 int srq_asserted ; 
 int status ; 
 int /*<<< orphan*/  stub1 (struct adb_request*) ; 
 int /*<<< orphan*/  stub2 (struct adb_request*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int* via ; 
 int* via1 ; 

__attribute__((used)) static int request_is_queued(struct adb_request *req) {
	struct adb_request *cur;
	unsigned long flags;
	local_irq_save(flags);
	cur = current_req;
	while (cur) {
		if (cur == req) {
			local_irq_restore(flags);
			return 1;
		}
		cur = cur->next;
	}
	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int macii_probe(void)
{
	if (macintosh_config->adb_type != MAC_ADB_II) return -ENODEV;

	via = via1;

	printk("adb: Mac II ADB Driver v1.0 for Unified ADB\n");
	return 0;
}

int macii_init(void)
{
	unsigned long flags;
	int err;
	
	local_irq_save(flags);
	
	err = macii_init_via();
	if (err) goto out;

	err = request_irq(IRQ_MAC_ADB, macii_interrupt, 0, "ADB",
			  macii_interrupt);
	if (err) goto out;

	macii_state = idle;
out:
	local_irq_restore(flags);
	return err;
}

__attribute__((used)) static int macii_init_via(void)
{
	unsigned char x;

	/* We want CTLR_IRQ as input and ST_EVEN | ST_ODD as output lines. */
	via[DIRB] = (via[DIRB] | ST_EVEN | ST_ODD) & ~CTLR_IRQ;

	/* Set up state: idle */
	via[B] |= ST_IDLE;
	last_status = via[B] & (ST_MASK|CTLR_IRQ);

	/* Shift register on input */
	via[ACR] = (via[ACR] & ~SR_CTRL) | SR_EXT;

	/* Wipe any pending data and int */
	x = via[SR];

	return 0;
}

__attribute__((used)) static void macii_queue_poll(void)
{
	/* No point polling the active device as it will never assert SRQ, so
	 * poll the next device in the autopoll list. This could leave us
	 * stuck in a polling loop if an unprobed device is asserting SRQ.
	 * In theory, that could only happen if a device was plugged in after
	 * probing started. Unplugging it again will break the cycle.
	 * (Simply polling the next higher device often ends up polling almost
	 * every device (after wrapping around), which takes too long.)
	 */
	int device_mask;
	int next_device;
	static struct adb_request req;

	if (!autopoll_devs) return;

	device_mask = (1 << (((command_byte & 0xF0) >> 4) + 1)) - 1;
	if (autopoll_devs & ~device_mask)
		next_device = ffs(autopoll_devs & ~device_mask) - 1;
	else
		next_device = ffs(autopoll_devs) - 1;

	BUG_ON(request_is_queued(&req));

	adb_request(&req, NULL, ADBREQ_NOSEND, 1,
	            ADB_READREG(next_device, 0));

	req.sent = 0;
	req.complete = 0;
	req.reply_len = 0;
	req.next = current_req;

	if (current_req != NULL) {
		current_req = &req;
	} else {
		current_req = &req;
		last_req = &req;
	}
}

__attribute__((used)) static int macii_send_request(struct adb_request *req, int sync)
{
	int err;
	unsigned long flags;

	BUG_ON(request_is_queued(req));

	local_irq_save(flags);
	err = macii_write(req);
	local_irq_restore(flags);

	if (!err && sync) {
		while (!req->complete) {
			macii_poll();
		}
		BUG_ON(request_is_queued(req));
	}

	return err;
}

__attribute__((used)) static int macii_write(struct adb_request *req)
{
	if (req->nbytes < 2 || req->data[0] != ADB_PACKET || req->nbytes > 15) {
		req->complete = 1;
		return -EINVAL;
	}
	
	req->next = NULL;
	req->sent = 0;
	req->complete = 0;
	req->reply_len = 0;

	if (current_req != NULL) {
		last_req->next = req;
		last_req = req;
	} else {
		current_req = req;
		last_req = req;
		if (macii_state == idle) macii_start();
	}
	return 0;
}

__attribute__((used)) static int macii_autopoll(int devs)
{
	static struct adb_request req;
	unsigned long flags;
	int err = 0;

	/* bit 1 == device 1, and so on. */
	autopoll_devs = devs & 0xFFFE;

	if (!autopoll_devs) return 0;

	local_irq_save(flags);

	if (current_req == NULL) {
		/* Send a Talk Reg 0. The controller will repeatedly transmit
		 * this as long as it is idle.
		 */
		adb_request(&req, NULL, ADBREQ_NOSEND, 1,
		            ADB_READREG(ffs(autopoll_devs) - 1, 0));
		err = macii_write(&req);
	}

	local_irq_restore(flags);
	return err;
}

__attribute__((used)) static inline int need_autopoll(void) {
	/* Was the last command Talk Reg 0
	 * and is the target on the autopoll list?
	 */
	if ((command_byte & 0x0F) == 0x0C &&
	    ((1 << ((command_byte & 0xF0) >> 4)) & autopoll_devs))
		return 0;
	return 1;
}

__attribute__((used)) static void macii_poll(void)
{
	disable_irq(IRQ_MAC_ADB);
	macii_interrupt(0, NULL);
	enable_irq(IRQ_MAC_ADB);
}

__attribute__((used)) static int macii_reset_bus(void)
{
	static struct adb_request req;
	
	if (request_is_queued(&req))
		return 0;

	/* Command = 0, Address = ignored */
	adb_request(&req, NULL, 0, 1, ADB_BUSRESET);

	/* Don't want any more requests during the Global Reset low time. */
	udelay(3000);

	return 0;
}

__attribute__((used)) static void macii_start(void)
{
	struct adb_request *req;

	req = current_req;

	BUG_ON(req == NULL);

	BUG_ON(macii_state != idle);

	/* Now send it. Be careful though, that first byte of the request
	 * is actually ADB_PACKET; the real data begins at index 1!
	 * And req->nbytes is the number of bytes of real data plus one.
	 */

	/* store command byte */
	command_byte = req->data[1];
	/* Output mode */
	via[ACR] |= SR_OUT;
	/* Load data */
	via[SR] = req->data[1];
	/* set ADB state to 'command' */
	via[B] = (via[B] & ~ST_MASK) | ST_CMD;

	macii_state = sending;
	data_index = 2;
}

__attribute__((used)) static irqreturn_t macii_interrupt(int irq, void *arg)
{
	int x;
	static int entered;
	struct adb_request *req;

	if (!arg) {
		/* Clear the SR IRQ flag when polling. */
		if (via[IFR] & SR_INT)
			via[IFR] = SR_INT;
		else
			return IRQ_NONE;
	}

	BUG_ON(entered++);

	last_status = status;
	status = via[B] & (ST_MASK|CTLR_IRQ);

	switch (macii_state) {
		case idle:
			if (reading_reply) {
				reply_ptr = current_req->reply;
			} else {
				BUG_ON(current_req != NULL);
				reply_ptr = reply_buf;
			}

			x = via[SR];

			if ((status & CTLR_IRQ) && (x == 0xFF)) {
				/* Bus timeout without SRQ sequence:
				 *     data is "FF" while CTLR_IRQ is "H"
				 */
				reply_len = 0;
				srq_asserted = 0;
				macii_state = read_done;
			} else {
				macii_state = reading;
				*reply_ptr = x;
				reply_len = 1;
			}

			/* set ADB state = even for first data byte */
			via[B] = (via[B] & ~ST_MASK) | ST_EVEN;
			break;

		case sending:
			req = current_req;
			if (data_index >= req->nbytes) {
				req->sent = 1;
				macii_state = idle;

				if (req->reply_expected) {
					reading_reply = 1;
				} else {
					req->complete = 1;
					current_req = req->next;
					if (req->done) (*req->done)(req);

					if (current_req)
						macii_start();
					else
						if (need_autopoll())
							macii_autopoll(autopoll_devs);
				}

				if (macii_state == idle) {
					/* reset to shift in */
					via[ACR] &= ~SR_OUT;
					x = via[SR];
					/* set ADB state idle - might get SRQ */
					via[B] = (via[B] & ~ST_MASK) | ST_IDLE;
				}
			} else {
				via[SR] = req->data[data_index++];

				if ( (via[B] & ST_MASK) == ST_CMD ) {
					/* just sent the command byte, set to EVEN */
					via[B] = (via[B] & ~ST_MASK) | ST_EVEN;
				} else {
					/* invert state bits, toggle ODD/EVEN */
					via[B] ^= ST_MASK;
				}
			}
			break;

		case reading:
			x = via[SR];
			BUG_ON((status & ST_MASK) == ST_CMD ||
			       (status & ST_MASK) == ST_IDLE);

			/* Bus timeout with SRQ sequence:
			 *     data is "XX FF"      while CTLR_IRQ is "L L"
			 * End of packet without SRQ sequence:
			 *     data is "XX...YY 00" while CTLR_IRQ is "L...H L"
			 * End of packet SRQ sequence:
			 *     data is "XX...YY 00" while CTLR_IRQ is "L...L L"
			 * (where XX is the first response byte and
			 * YY is the last byte of valid response data.)
			 */

			srq_asserted = 0;
			if (!(status & CTLR_IRQ)) {
				if (x == 0xFF) {
					if (!(last_status & CTLR_IRQ)) {
						macii_state = read_done;
						reply_len = 0;
						srq_asserted = 1;
					}
				} else if (x == 0x00) {
					macii_state = read_done;
					if (!(last_status & CTLR_IRQ))
						srq_asserted = 1;
				}
			}

			if (macii_state == reading) {
				BUG_ON(reply_len > 15);
				reply_ptr++;
				*reply_ptr = x;
				reply_len++;
			}

			/* invert state bits, toggle ODD/EVEN */
			via[B] ^= ST_MASK;
			break;

		case read_done:
			x = via[SR];

			if (reading_reply) {
				reading_reply = 0;
				req = current_req;
				req->reply_len = reply_len;
				req->complete = 1;
				current_req = req->next;
				if (req->done) (*req->done)(req);
			} else if (reply_len && autopoll_devs)
				adb_input(reply_buf, reply_len, 0);

			macii_state = idle;

			/* SRQ seen before, initiate poll now */
			if (srq_asserted)
				macii_queue_poll();

			if (current_req)
				macii_start();
			else
				if (need_autopoll())
					macii_autopoll(autopoll_devs);

			if (macii_state == idle)
				via[B] = (via[B] & ~ST_MASK) | ST_IDLE;
			break;

		default:
		break;
	}

	entered--;
	return IRQ_HANDLED;
}

