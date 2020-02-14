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
typedef  int u8 ;
typedef  int u32 ;
struct timespec64 {int tv_nsec; scalar_t__ tv_sec; } ;
struct service_processor {int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int command_size; int data_size; scalar_t__ status; void* type; } ;
struct os_state_command {int* command; int data; TYPE_1__ header; } ;
struct dot_command_header {size_t command_size; size_t data_size; int type; scalar_t__ reserved; scalar_t__ status; } ;
struct command {int* buffer; scalar_t__ status; int /*<<< orphan*/  kref; int /*<<< orphan*/ * lock; } ;
typedef  int /*<<< orphan*/  spinlock_t ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ IBMASM_CMD_COMPLETE ; 
 unsigned int IBMASM_CMD_TIMEOUT_EXTRA ; 
 unsigned int IBMASM_CMD_TIMEOUT_NORMAL ; 
 int /*<<< orphan*/  IBMASM_DRIVER_VPD ; 
 int INIT_BUFFER_SIZE ; 
 int NSEC_PER_USEC ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ibmasm_exec_command (struct service_processor*,struct command*) ; 
 int /*<<< orphan*/  ibmasm_free_command ; 
 struct command* ibmasm_new_command (struct service_processor*,int) ; 
 int /*<<< orphan*/  ibmasm_receive_command_response (struct service_processor*,void*,int) ; 
 int /*<<< orphan*/  ibmasm_receive_event (struct service_processor*,void*,int) ; 
 int /*<<< orphan*/  ibmasm_receive_heartbeat (struct service_processor*,void*,int) ; 
 int /*<<< orphan*/  ibmasm_wait_for_response (struct command*,unsigned int) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_get_real_ts64 (struct timespec64*) ; 
#define  sp_command_response 130 
#define  sp_event 129 
#define  sp_heartbeat 128 
 void* sp_write ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  sprintf (char*,char*,long long,int) ; 
 int /*<<< orphan*/  strcat (int*,int /*<<< orphan*/ ) ; 

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

void ibmasm_receive_message(struct service_processor *sp, void *message, int message_size)
{
	u32 size;
	struct dot_command_header *header = (struct dot_command_header *)message;

	if (message_size == 0)
		return;

	size = get_dot_command_size(message);
	if (size == 0)
		return;

	if (size > message_size)
		size = message_size;

	switch (header->type) {
	case sp_event:
		ibmasm_receive_event(sp, message, size);
		break;
	case sp_command_response:
		ibmasm_receive_command_response(sp, message, size);
		break;
	case sp_heartbeat:
		ibmasm_receive_heartbeat(sp, message, size);
		break;
	default:
		dev_err(sp->dev, "Received unknown message from service processor\n");
	}
}

int ibmasm_send_driver_vpd(struct service_processor *sp)
{
	struct command *command;
	struct dot_command_header *header;
	u8 *vpd_command;
	u8 *vpd_data;
	int result = 0;

	command = ibmasm_new_command(sp, INIT_BUFFER_SIZE);
	if (command == NULL)
		return -ENOMEM;

	header = (struct dot_command_header *)command->buffer;
	header->type                = sp_write;
	header->command_size        = 4;
	header->data_size           = 16;
	header->status              = 0;
	header->reserved            = 0;

	vpd_command = command->buffer + sizeof(struct dot_command_header);
	vpd_command[0] = 0x4;
	vpd_command[1] = 0x3;
	vpd_command[2] = 0x5;
	vpd_command[3] = 0xa;

	vpd_data = vpd_command + header->command_size;
	vpd_data[0] = 0;
	strcat(vpd_data, IBMASM_DRIVER_VPD);
	vpd_data[10] = 0;
	vpd_data[15] = 0;

	ibmasm_exec_command(sp, command);
	ibmasm_wait_for_response(command, IBMASM_CMD_TIMEOUT_NORMAL);

	if (command->status != IBMASM_CMD_COMPLETE)
		result = -ENODEV;

	command_put(command);

	return result;
}

int ibmasm_send_os_state(struct service_processor *sp, int os_state)
{
	struct command *cmd;
	struct os_state_command *os_state_cmd;
	int result = 0;

	cmd = ibmasm_new_command(sp, sizeof(struct os_state_command));
	if (cmd == NULL)
		return -ENOMEM;

	os_state_cmd = (struct os_state_command *)cmd->buffer;
	os_state_cmd->header.type		= sp_write;
	os_state_cmd->header.command_size	= 3;
	os_state_cmd->header.data_size		= 1;
	os_state_cmd->header.status		= 0;
	os_state_cmd->command[0]		= 4;
	os_state_cmd->command[1]		= 3;
	os_state_cmd->command[2]		= 6;
	os_state_cmd->data			= os_state;

	ibmasm_exec_command(sp, cmd);
	ibmasm_wait_for_response(cmd, IBMASM_CMD_TIMEOUT_NORMAL);

	if (cmd->status != IBMASM_CMD_COMPLETE)
		result = -ENODEV;

	command_put(cmd);
	return result;
}

