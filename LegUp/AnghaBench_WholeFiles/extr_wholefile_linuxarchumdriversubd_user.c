#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int fd; void* events; } ;

/* Variables and functions */
 int CLONE_FILES ; 
 int CLONE_VM ; 
 void* POLLIN ; 
 void* POLLOUT ; 
 int clone (int /*<<< orphan*/ ,void*,int,int /*<<< orphan*/ *) ; 
 int errno ; 
 int /*<<< orphan*/  io_thread ; 
 int kernel_fd ; 
 TYPE_1__ kernel_pollfd ; 
 int /*<<< orphan*/  os_close_file (int) ; 
 int os_pipe (int*,int,int) ; 
 int os_set_fd_block (int,int /*<<< orphan*/ ) ; 
 int poll (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  printk (char*,...) ; 

int start_io_thread(unsigned long sp, int *fd_out)
{
	int pid, fds[2], err;

	err = os_pipe(fds, 1, 1);
	if(err < 0){
		printk("start_io_thread - os_pipe failed, err = %d\n", -err);
		goto out;
	}

	kernel_fd = fds[0];
	kernel_pollfd.fd = kernel_fd;
	kernel_pollfd.events = POLLIN;
	*fd_out = fds[1];

	err = os_set_fd_block(*fd_out, 0);
	err = os_set_fd_block(kernel_fd, 0);
	if (err) {
		printk("start_io_thread - failed to set nonblocking I/O.\n");
		goto out_close;
	}

	pid = clone(io_thread, (void *) sp, CLONE_FILES | CLONE_VM, NULL);
	if(pid < 0){
		err = -errno;
		printk("start_io_thread - clone failed : errno = %d\n", errno);
		goto out_close;
	}

	return(pid);

 out_close:
	os_close_file(fds[0]);
	os_close_file(fds[1]);
	kernel_fd = -1;
	*fd_out = -1;
 out:
	return err;
}

int ubd_read_poll(int timeout)
{
	kernel_pollfd.events = POLLIN;
	return poll(&kernel_pollfd, 1, timeout);
}

int ubd_write_poll(int timeout)
{
	kernel_pollfd.events = POLLOUT;
	return poll(&kernel_pollfd, 1, timeout);
}

