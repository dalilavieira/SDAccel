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
struct iop_msg {int* message; int* reply; } ;
struct adb_request {int complete; int reply_len; int* reply; int nbytes; int* data; int sent; scalar_t__ reply_expected; struct adb_request* next; int /*<<< orphan*/  (* done ) (struct adb_request*) ;} ;
struct adb_iopmsg {int flags; int count; int cmd; } ;
typedef  int /*<<< orphan*/  amsg ;
typedef  int /*<<< orphan*/  __u8 ;

/* Variables and functions */
 int /*<<< orphan*/  ADB_CHAN ; 
 int /*<<< orphan*/  ADB_IOP ; 
 int ADB_IOP_AUTOPOLL ; 
 int ADB_IOP_EXPLICIT ; 
 int ADB_IOP_TIMEOUT ; 
 scalar_t__ ADB_PACKET ; 
 int EINVAL ; 
 int ENODEV ; 
 int IOP_MSG_LEN ; 
 int /*<<< orphan*/  adb_input (int*,int,int) ; 
 void adb_iop_poll () ; 
 int adb_iop_state ; 
static  int adb_iop_write (struct adb_request*) ; 
 int awaiting_reply ; 
 struct adb_request* current_req ; 
 int idle ; 
 int /*<<< orphan*/  iop_complete_message (struct iop_msg*) ; 
 int /*<<< orphan*/  iop_ism_irq_poll (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iop_ism_present ; 
 int /*<<< orphan*/  iop_listen (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (struct iop_msg*),char*) ; 
 int /*<<< orphan*/  iop_send_message (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct adb_request*,int,int /*<<< orphan*/ *,void (*) (struct iop_msg*)) ; 
 struct adb_request* last_req ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  printk (char*) ; 
 int /*<<< orphan*/  schedule () ; 
 int sending ; 
 int /*<<< orphan*/  stub1 (struct adb_request*) ; 

__attribute__((used)) static void adb_iop_end_req(struct adb_request *req, int state)
{
	req->complete = 1;
	current_req = req->next;
	if (req->done) (*req->done)(req);
	adb_iop_state = state;
}

__attribute__((used)) static void adb_iop_complete(struct iop_msg *msg)
{
	struct adb_request *req;
	unsigned long flags;

	local_irq_save(flags);

	req = current_req;
	if ((adb_iop_state == sending) && req && req->reply_expected) {
		adb_iop_state = awaiting_reply;
	}

	local_irq_restore(flags);
}

__attribute__((used)) static void adb_iop_listen(struct iop_msg *msg)
{
	struct adb_iopmsg *amsg = (struct adb_iopmsg *) msg->message;
	struct adb_request *req;
	unsigned long flags;
#ifdef DEBUG_ADB_IOP
	int i;
#endif

	local_irq_save(flags);

	req = current_req;

#ifdef DEBUG_ADB_IOP
	printk("adb_iop_listen %p: rcvd packet, %d bytes: %02X %02X", req,
		(uint) amsg->count + 2, (uint) amsg->flags, (uint) amsg->cmd);
	for (i = 0; i < amsg->count; i++)
		printk(" %02X", (uint) amsg->data[i]);
	printk("\n");
#endif

	/* Handle a timeout. Timeout packets seem to occur even after */
	/* we've gotten a valid reply to a TALK, so I'm assuming that */
	/* a "timeout" is actually more like an "end-of-data" signal. */
	/* We need to send back a timeout packet to the IOP to shut   */
	/* it up, plus complete the current request, if any.          */

	if (amsg->flags & ADB_IOP_TIMEOUT) {
		msg->reply[0] = ADB_IOP_TIMEOUT | ADB_IOP_AUTOPOLL;
		msg->reply[1] = 0;
		msg->reply[2] = 0;
		if (req && (adb_iop_state != idle)) {
			adb_iop_end_req(req, idle);
		}
	} else {
		/* TODO: is it possible for more than one chunk of data  */
		/*       to arrive before the timeout? If so we need to */
		/*       use reply_ptr here like the other drivers do.  */
		if ((adb_iop_state == awaiting_reply) &&
		    (amsg->flags & ADB_IOP_EXPLICIT)) {
			req->reply_len = amsg->count + 1;
			memcpy(req->reply, &amsg->cmd, req->reply_len);
		} else {
			adb_input(&amsg->cmd, amsg->count + 1,
				  amsg->flags & ADB_IOP_AUTOPOLL);
		}
		memcpy(msg->reply, msg->message, IOP_MSG_LEN);
	}
	iop_complete_message(msg);
	local_irq_restore(flags);
}

__attribute__((used)) static void adb_iop_start(void)
{
	unsigned long flags;
	struct adb_request *req;
	struct adb_iopmsg amsg;
#ifdef DEBUG_ADB_IOP
	int i;
#endif

	/* get the packet to send */
	req = current_req;
	if (!req) return;

	local_irq_save(flags);

#ifdef DEBUG_ADB_IOP
	printk("adb_iop_start %p: sending packet, %d bytes:", req, req->nbytes);
	for (i = 0 ; i < req->nbytes ; i++)
		printk(" %02X", (uint) req->data[i]);
	printk("\n");
#endif

	/* The IOP takes MacII-style packets, so */
	/* strip the initial ADB_PACKET byte.    */

	amsg.flags = ADB_IOP_EXPLICIT;
	amsg.count = req->nbytes - 2;

	/* amsg.data immediately follows amsg.cmd, effectively making */
	/* amsg.cmd a pointer to the beginning of a full ADB packet.  */
	memcpy(&amsg.cmd, req->data + 1, req->nbytes - 1);

	req->sent = 1;
	adb_iop_state = sending;
	local_irq_restore(flags);

	/* Now send it. The IOP manager will call adb_iop_complete */
	/* when the packet has been sent.                          */

	iop_send_message(ADB_IOP, ADB_CHAN, req,
			 sizeof(amsg), (__u8 *) &amsg, adb_iop_complete);
}

int adb_iop_probe(void)
{
	if (!iop_ism_present) return -ENODEV;
	return 0;
}

int adb_iop_init(void)
{
	printk("adb: IOP ISM driver v0.4 for Unified ADB.\n");
	iop_listen(ADB_IOP, ADB_CHAN, adb_iop_listen, "ADB");
	return 0;
}

int adb_iop_send_request(struct adb_request *req, int sync)
{
	int err;

	err = adb_iop_write(req);
	if (err) return err;

	if (sync) {
		while (!req->complete) adb_iop_poll();
	}
	return 0;
}

__attribute__((used)) static int adb_iop_write(struct adb_request *req)
{
	unsigned long flags;

	if ((req->nbytes < 2) || (req->data[0] != ADB_PACKET)) {
		req->complete = 1;
		return -EINVAL;
	}

	local_irq_save(flags);

	req->next = NULL;
	req->sent = 0;
	req->complete = 0;
	req->reply_len = 0;

	if (current_req != 0) {
		last_req->next = req;
		last_req = req;
	} else {
		current_req = req;
		last_req = req;
	}

	local_irq_restore(flags);
	if (adb_iop_state == idle) adb_iop_start();
	return 0;
}

int adb_iop_autopoll(int devs)
{
	/* TODO: how do we enable/disable autopoll? */
	return 0;
}

void adb_iop_poll(void)
{
	if (adb_iop_state == idle) adb_iop_start();
	iop_ism_irq_poll(ADB_IOP);
}

int adb_iop_reset_bus(void)
{
	struct adb_request req = {
		.reply_expected = 0,
		.nbytes = 2,
		.data = { ADB_PACKET, 0 },
	};

	adb_iop_write(&req);
	while (!req.complete) {
		adb_iop_poll();
		schedule();
	}

	return 0;
}

