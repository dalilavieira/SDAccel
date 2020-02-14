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
struct mbox_request {int cmd; scalar_t__ is_set; } ;
struct mbox_reply {int status; } ;
typedef  int /*<<< orphan*/  req ;
typedef  int /*<<< orphan*/  reply ;

/* Variables and functions */
 int ENOPROTOOPT ; 
 int /*<<< orphan*/  close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debug_fd ; 
 int /*<<< orphan*/  dprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  open (char*,int) ; 
 int read (int /*<<< orphan*/ ,struct mbox_request*,int) ; 
 int write (int,struct mbox_reply*,int) ; 

__attribute__((used)) static int handle_get_cmd(struct mbox_request *cmd)
{
	switch (cmd->cmd) {
	case 0:
		return 0;
	default:
		break;
	}
	return -ENOPROTOOPT;
}

__attribute__((used)) static int handle_set_cmd(struct mbox_request *cmd)
{
	return -ENOPROTOOPT;
}

__attribute__((used)) static void loop(void)
{
	while (1) {
		struct mbox_request req;
		struct mbox_reply reply;
		int n;

		n = read(0, &req, sizeof(req));
		if (n != sizeof(req)) {
			dprintf(debug_fd, "invalid request %d\n", n);
			return;
		}

		reply.status = req.is_set ?
			handle_set_cmd(&req) :
			handle_get_cmd(&req);

		n = write(1, &reply, sizeof(reply));
		if (n != sizeof(reply)) {
			dprintf(debug_fd, "reply failed %d\n", n);
			return;
		}
	}
}

int main(void)
{
	debug_fd = open("/dev/console", 00000002);
	dprintf(debug_fd, "Started bpfilter\n");
	loop();
	close(debug_fd);
	return 0;
}

