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
struct serio {int /*<<< orphan*/  dev; int /*<<< orphan*/  depth; scalar_t__ ps2_cmd_mutex; } ;
struct mutex {int dummy; } ;
struct ps2dev {int flags; size_t cmdcnt; int* cmdbuf; int nak; int /*<<< orphan*/  wait; struct serio* serio; struct mutex cmd_mutex; } ;
typedef  int /*<<< orphan*/  keyboard_ids ;

/* Variables and functions */
 int EAGAIN ; 
 int EINVAL ; 
 int EPROTO ; 
#define  PS2_CMD_GETID 132 
#define  PS2_CMD_RESET_BAT 131 
 unsigned int PS2_CMD_SETRES ; 
 unsigned int PS2_CMD_SETSCALE11 ; 
 int PS2_FLAG_ACK ; 
 int PS2_FLAG_ACK_CMD ; 
 int PS2_FLAG_CMD ; 
 int PS2_FLAG_CMD1 ; 
 int PS2_FLAG_NAK ; 
 int PS2_FLAG_WAITID ; 
#define  PS2_RET_ACK 130 
#define  PS2_RET_ERR 129 
#define  PS2_RET_NAK 128 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lockdep_set_subclass (struct mutex*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * memchr (int const*,int,int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,unsigned int) ; 
 unsigned int msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_init (struct mutex*) ; 
 int /*<<< orphan*/  mutex_lock (struct mutex*) ; 
 int /*<<< orphan*/  mutex_unlock (struct mutex*) ; 
 int ps2_do_sendbyte (struct ps2dev*,int,int,int) ; 
 int ps2_handle_response (struct ps2dev*,int) ; 
 int /*<<< orphan*/  serio_continue_rx (struct serio*) ; 
 int /*<<< orphan*/  serio_pause_rx (struct serio*) ; 
 unsigned int wait_event_timeout (int /*<<< orphan*/ ,int,unsigned int) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

void ps2_begin_command(struct ps2dev *ps2dev)
{
	struct mutex *m = ps2dev->serio->ps2_cmd_mutex ?: &ps2dev->cmd_mutex;

	mutex_lock(m);
}

void ps2_end_command(struct ps2dev *ps2dev)
{
	struct mutex *m = ps2dev->serio->ps2_cmd_mutex ?: &ps2dev->cmd_mutex;

	mutex_unlock(m);
}

void ps2_drain(struct ps2dev *ps2dev, size_t maxbytes, unsigned int timeout)
{
	if (maxbytes > sizeof(ps2dev->cmdbuf)) {
		WARN_ON(1);
		maxbytes = sizeof(ps2dev->cmdbuf);
	}

	ps2_begin_command(ps2dev);

	serio_pause_rx(ps2dev->serio);
	ps2dev->flags = PS2_FLAG_CMD;
	ps2dev->cmdcnt = maxbytes;
	serio_continue_rx(ps2dev->serio);

	wait_event_timeout(ps2dev->wait,
			   !(ps2dev->flags & PS2_FLAG_CMD),
			   msecs_to_jiffies(timeout));

	ps2_end_command(ps2dev);
}

bool ps2_is_keyboard_id(u8 id_byte)
{
	static const u8 keyboard_ids[] = {
		0xab,	/* Regular keyboards		*/
		0xac,	/* NCD Sun keyboard		*/
		0x2b,	/* Trust keyboard, translated	*/
		0x5d,	/* Trust keyboard		*/
		0x60,	/* NMB SGI keyboard, translated */
		0x47,	/* NMB SGI keyboard		*/
	};

	return memchr(keyboard_ids, id_byte, sizeof(keyboard_ids)) != NULL;
}

__attribute__((used)) static int ps2_adjust_timeout(struct ps2dev *ps2dev,
			      unsigned int command, unsigned int timeout)
{
	switch (command) {
	case PS2_CMD_RESET_BAT:
		/*
		 * Device has sent the first response byte after
		 * reset command, reset is thus done, so we can
		 * shorten the timeout.
		 * The next byte will come soon (keyboard) or not
		 * at all (mouse).
		 */
		if (timeout > msecs_to_jiffies(100))
			timeout = msecs_to_jiffies(100);
		break;

	case PS2_CMD_GETID:
		/*
		 * Microsoft Natural Elite keyboard responds to
		 * the GET ID command as it were a mouse, with
		 * a single byte. Fail the command so atkbd will
		 * use alternative probe to detect it.
		 */
		if (ps2dev->cmdbuf[1] == 0xaa) {
			serio_pause_rx(ps2dev->serio);
			ps2dev->flags = 0;
			serio_continue_rx(ps2dev->serio);
			timeout = 0;
		}

		/*
		 * If device behind the port is not a keyboard there
		 * won't be 2nd byte of ID response.
		 */
		if (!ps2_is_keyboard_id(ps2dev->cmdbuf[1])) {
			serio_pause_rx(ps2dev->serio);
			ps2dev->flags = ps2dev->cmdcnt = 0;
			serio_continue_rx(ps2dev->serio);
			timeout = 0;
		}
		break;

	default:
		break;
	}

	return timeout;
}

int __ps2_command(struct ps2dev *ps2dev, u8 *param, unsigned int command)
{
	unsigned int timeout;
	unsigned int send = (command >> 12) & 0xf;
	unsigned int receive = (command >> 8) & 0xf;
	int rc;
	int i;
	u8 send_param[16];

	if (receive > sizeof(ps2dev->cmdbuf)) {
		WARN_ON(1);
		return -EINVAL;
	}

	if (send && !param) {
		WARN_ON(1);
		return -EINVAL;
	}

	memcpy(send_param, param, send);

	serio_pause_rx(ps2dev->serio);

	ps2dev->flags = command == PS2_CMD_GETID ? PS2_FLAG_WAITID : 0;
	ps2dev->cmdcnt = receive;
	if (receive && param)
		for (i = 0; i < receive; i++)
			ps2dev->cmdbuf[(receive - 1) - i] = param[i];

	/* Signal that we are sending the command byte */
	ps2dev->flags |= PS2_FLAG_ACK_CMD;

	/*
	 * Some devices (Synaptics) peform the reset before
	 * ACKing the reset command, and so it can take a long
	 * time before the ACK arrives.
	 */
	timeout = command == PS2_CMD_RESET_BAT ? 1000 : 200;

	rc = ps2_do_sendbyte(ps2dev, command & 0xff, timeout, 2);
	if (rc)
		goto out_reset_flags;

	/* Now we are sending command parameters, if any */
	ps2dev->flags &= ~PS2_FLAG_ACK_CMD;

	for (i = 0; i < send; i++) {
		rc = ps2_do_sendbyte(ps2dev, param[i], 200, 2);
		if (rc)
			goto out_reset_flags;
	}

	serio_continue_rx(ps2dev->serio);

	/*
	 * The reset command takes a long time to execute.
	 */
	timeout = msecs_to_jiffies(command == PS2_CMD_RESET_BAT ? 4000 : 500);

	timeout = wait_event_timeout(ps2dev->wait,
				     !(ps2dev->flags & PS2_FLAG_CMD1), timeout);

	if (ps2dev->cmdcnt && !(ps2dev->flags & PS2_FLAG_CMD1)) {

		timeout = ps2_adjust_timeout(ps2dev, command, timeout);
		wait_event_timeout(ps2dev->wait,
				   !(ps2dev->flags & PS2_FLAG_CMD), timeout);
	}

	serio_pause_rx(ps2dev->serio);

	if (param)
		for (i = 0; i < receive; i++)
			param[i] = ps2dev->cmdbuf[(receive - 1) - i];

	if (ps2dev->cmdcnt &&
	    (command != PS2_CMD_RESET_BAT || ps2dev->cmdcnt != 1)) {
		rc = -EPROTO;
		goto out_reset_flags;
	}

	rc = 0;

 out_reset_flags:
	ps2dev->flags = 0;
	serio_continue_rx(ps2dev->serio);

	dev_dbg(&ps2dev->serio->dev,
		"%02x [%*ph] - %x/%08lx [%*ph]\n",
		command & 0xff, send, send_param,
		ps2dev->nak, ps2dev->flags,
		receive, param ?: send_param);

	/*
	 * ps_command() handles resends itself, so do not leak -EAGAIN
	 * to the callers.
	 */
	return rc != -EAGAIN ? rc : -EPROTO;
}

int ps2_command(struct ps2dev *ps2dev, u8 *param, unsigned int command)
{
	int rc;

	ps2_begin_command(ps2dev);
	rc = __ps2_command(ps2dev, param, command);
	ps2_end_command(ps2dev);

	return rc;
}

int ps2_sliced_command(struct ps2dev *ps2dev, u8 command)
{
	int i;
	int retval;

	ps2_begin_command(ps2dev);

	retval = __ps2_command(ps2dev, NULL, PS2_CMD_SETSCALE11);
	if (retval)
		goto out;

	for (i = 6; i >= 0; i -= 2) {
		u8 d = (command >> i) & 3;
		retval = __ps2_command(ps2dev, &d, PS2_CMD_SETRES);
		if (retval)
			break;
	}

out:
	dev_dbg(&ps2dev->serio->dev, "%02x - %d\n", command, retval);
	ps2_end_command(ps2dev);
	return retval;
}

void ps2_init(struct ps2dev *ps2dev, struct serio *serio)
{
	mutex_init(&ps2dev->cmd_mutex);
	lockdep_set_subclass(&ps2dev->cmd_mutex, serio->depth);
	init_waitqueue_head(&ps2dev->wait);
	ps2dev->serio = serio;
}

bool ps2_handle_ack(struct ps2dev *ps2dev, u8 data)
{
	switch (data) {
	case PS2_RET_ACK:
		ps2dev->nak = 0;
		break;

	case PS2_RET_NAK:
		ps2dev->flags |= PS2_FLAG_NAK;
		ps2dev->nak = PS2_RET_NAK;
		break;

	case PS2_RET_ERR:
		if (ps2dev->flags & PS2_FLAG_NAK) {
			ps2dev->flags &= ~PS2_FLAG_NAK;
			ps2dev->nak = PS2_RET_ERR;
			break;
		}

	/*
	 * Workaround for mice which don't ACK the Get ID command.
	 * These are valid mouse IDs that we recognize.
	 */
	case 0x00:
	case 0x03:
	case 0x04:
		if (ps2dev->flags & PS2_FLAG_WAITID) {
			ps2dev->nak = 0;
			break;
		}
		/* Fall through */
	default:
		/*
		 * Do not signal errors if we get unexpected reply while
		 * waiting for an ACK to the initial (first) command byte:
		 * the device might not be quiesced yet and continue
		 * delivering data.
		 * Note that we reset PS2_FLAG_WAITID flag, so the workaround
		 * for mice not acknowledging the Get ID command only triggers
		 * on the 1st byte; if device spews data we really want to see
		 * a real ACK from it.
		 */
		dev_dbg(&ps2dev->serio->dev, "unexpected %#02x\n", data);
		ps2dev->flags &= ~PS2_FLAG_WAITID;
		return ps2dev->flags & PS2_FLAG_ACK_CMD;
	}

	if (!ps2dev->nak) {
		ps2dev->flags &= ~PS2_FLAG_NAK;
		if (ps2dev->cmdcnt)
			ps2dev->flags |= PS2_FLAG_CMD | PS2_FLAG_CMD1;
	}

	ps2dev->flags &= ~PS2_FLAG_ACK;
	wake_up(&ps2dev->wait);

	if (data != PS2_RET_ACK)
		ps2_handle_response(ps2dev, data);

	return true;
}

bool ps2_handle_response(struct ps2dev *ps2dev, u8 data)
{
	if (ps2dev->cmdcnt)
		ps2dev->cmdbuf[--ps2dev->cmdcnt] = data;

	if (ps2dev->flags & PS2_FLAG_CMD1) {
		ps2dev->flags &= ~PS2_FLAG_CMD1;
		if (ps2dev->cmdcnt)
			wake_up(&ps2dev->wait);
	}

	if (!ps2dev->cmdcnt) {
		ps2dev->flags &= ~PS2_FLAG_CMD;
		wake_up(&ps2dev->wait);
	}

	return true;
}

void ps2_cmd_aborted(struct ps2dev *ps2dev)
{
	if (ps2dev->flags & PS2_FLAG_ACK)
		ps2dev->nak = 1;

	if (ps2dev->flags & (PS2_FLAG_ACK | PS2_FLAG_CMD))
		wake_up(&ps2dev->wait);

	/* reset all flags except last nack */
	ps2dev->flags &= PS2_FLAG_NAK;
}

