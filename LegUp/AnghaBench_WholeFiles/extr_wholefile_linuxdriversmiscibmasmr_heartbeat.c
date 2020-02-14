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
struct timespec64 {int tv_nsec; scalar_t__ tv_sec; } ;
struct service_processor {int dummy; } ;
struct reverse_heartbeat {int stopped; int /*<<< orphan*/  wait; } ;
struct dot_command_header {size_t command_size; size_t data_size; } ;
struct command {scalar_t__ status; int /*<<< orphan*/  buffer; int /*<<< orphan*/  kref; int /*<<< orphan*/ * lock; } ;
typedef  int /*<<< orphan*/  spinlock_t ;

/* Variables and functions */
 int EINTR ; 
 int ENOMEM ; 
 int HZ ; 
 scalar_t__ IBMASM_CMD_COMPLETE ; 
 scalar_t__ IBMASM_CMD_PENDING ; 
 unsigned int IBMASM_CMD_TIMEOUT_EXTRA ; 
 unsigned int IBMASM_CMD_TIMEOUT_NORMAL ; 
 int NSEC_PER_USEC ; 
 int REVERSE_HEARTBEAT_TIMEOUT ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  ibmasm_exec_command (struct service_processor*,struct command*) ; 
 int /*<<< orphan*/  ibmasm_free_command ; 
 struct command* ibmasm_new_command (struct service_processor*,int) ; 
 int /*<<< orphan*/  ibmasm_wait_for_response (struct command*,unsigned int) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_get_real_ts64 (struct timespec64*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,void*,int) ; 
 int /*<<< orphan*/  rhb_dot_cmd ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  sprintf (char*,char*,long long,int) ; 
 int /*<<< orphan*/  wait_event_interruptible_timeout (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline char *get_timestamp(char *buf)
{
	struct timespec64 now;

	ktime_get_real_ts64(&now);
	sprintf(buf, "%llu.%.08lu", (long long)now.tv_sec,
				now.tv_nsec / NSEC_PER_USEC);
	return buf;
}

__attribute__((used)) static inline void command_put(struct command *cmd)
{
	unsigned long flags;
	spinlock_t *lock = cmd->lock;

	spin_lock_irqsave(lock, flags);
	kref_put(&cmd->kref, ibmasm_free_command);
	spin_unlock_irqrestore(lock, flags);
}

__attribute__((used)) static inline void command_get(struct command *cmd)
{
	kref_get(&cmd->kref);
}

__attribute__((used)) static inline size_t get_dot_command_size(void *buffer)
{
	struct dot_command_header *cmd = (struct dot_command_header *)buffer;
	return sizeof(struct dot_command_header) + cmd->command_size + cmd->data_size;
}

__attribute__((used)) static inline unsigned int get_dot_command_timeout(void *buffer)
{
	struct dot_command_header *header = (struct dot_command_header *)buffer;
	unsigned char *cmd = buffer + sizeof(struct dot_command_header);

	/* dot commands 6.3.1, 7.1 and 8.x need a longer timeout */

	if (header->command_size == 3) {
		if ((cmd[0] == 6) && (cmd[1] == 3) && (cmd[2] == 1))
			return IBMASM_CMD_TIMEOUT_EXTRA;
	} else if (header->command_size == 2) {
		if ((cmd[0] == 7) && (cmd[1] == 1))
			return IBMASM_CMD_TIMEOUT_EXTRA;
		if (cmd[0] == 8)
			return IBMASM_CMD_TIMEOUT_EXTRA;
	}
	return IBMASM_CMD_TIMEOUT_NORMAL;
}

void ibmasm_init_reverse_heartbeat(struct service_processor *sp, struct reverse_heartbeat *rhb)
{
	init_waitqueue_head(&rhb->wait);
	rhb->stopped = 0;
}

int ibmasm_start_reverse_heartbeat(struct service_processor *sp, struct reverse_heartbeat *rhb)
{
	struct command *cmd;
	int times_failed = 0;
	int result = 1;

	cmd = ibmasm_new_command(sp, sizeof rhb_dot_cmd);
	if (!cmd)
		return -ENOMEM;

	while (times_failed < 3) {
		memcpy(cmd->buffer, (void *)&rhb_dot_cmd, sizeof rhb_dot_cmd);
		cmd->status = IBMASM_CMD_PENDING;
		ibmasm_exec_command(sp, cmd);
		ibmasm_wait_for_response(cmd, IBMASM_CMD_TIMEOUT_NORMAL);

		if (cmd->status != IBMASM_CMD_COMPLETE)
			times_failed++;

		wait_event_interruptible_timeout(rhb->wait,
			rhb->stopped,
			REVERSE_HEARTBEAT_TIMEOUT * HZ);

		if (signal_pending(current) || rhb->stopped) {
			result = -EINTR;
			break;
		}
	}
	command_put(cmd);
	rhb->stopped = 0;

	return result;
}

void ibmasm_stop_reverse_heartbeat(struct reverse_heartbeat *rhb)
{
	rhb->stopped = 1;
	wake_up_interruptible(&rhb->wait);
}

