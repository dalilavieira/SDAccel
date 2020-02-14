#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct sigevent {int sigev_notify; int /*<<< orphan*/ * sigev_notify_attributes; int /*<<< orphan*/  sigev_value; int /*<<< orphan*/  (* sigev_notify_function ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  sigev_signo; } ;
struct aiocb {int aio_fildes; size_t aio_nbytes; int aio_lio_opcode; int /*<<< orphan*/  __td; int /*<<< orphan*/  __err; struct sigevent aio_sigevent; scalar_t__ __ret; int /*<<< orphan*/  aio_offset; scalar_t__ aio_buf; } ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  sigset_t ;
struct TYPE_4__ {int /*<<< orphan*/  si_signo; int /*<<< orphan*/  si_pid; int /*<<< orphan*/  si_uid; int /*<<< orphan*/  si_code; int /*<<< orphan*/  si_value; } ;
typedef  TYPE_1__ siginfo_t ;
typedef  int /*<<< orphan*/  pthread_t ;
typedef  int /*<<< orphan*/  pthread_attr_t ;
typedef  int /*<<< orphan*/  off_t ;
struct TYPE_5__ {int /*<<< orphan*/  pid; } ;

/* Variables and functions */
 scalar_t__ EAGAIN ; 
 int /*<<< orphan*/  EINPROGRESS ; 
 scalar_t__ ESPIPE ; 
 int /*<<< orphan*/  F_GETFL ; 
 int LIO_READ ; 
 int LIO_WRITE ; 
 int O_APPEND ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PTHREAD_CREATE_DETACHED ; 
#define  SIGEV_SIGNAL 129 
#define  SIGEV_THREAD 128 
 int /*<<< orphan*/  SIG_BLOCK ; 
 int /*<<< orphan*/  SIG_SETMASK ; 
 int /*<<< orphan*/  SI_ASYNCIO ; 
 int /*<<< orphan*/  SYS_rt_sigqueueinfo ; 
 int /*<<< orphan*/  __aio_wake () ; 
 TYPE_3__* __pthread_self () ; 
 int /*<<< orphan*/  __syscall (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  a_store (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ errno ; 
 int fcntl (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  getuid () ; 
 scalar_t__ pread (int,void*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_attr_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_attr_setdetachstate (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_attr_setguardsize (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_attr_setstacksize (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),struct aiocb*) ; 
 int /*<<< orphan*/  pthread_sigmask (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ pwrite (int,void*,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ read (int,void*,size_t) ; 
 int /*<<< orphan*/  sigfillset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 
 scalar_t__ write (int,void*,size_t) ; 

__attribute__((used)) static void dummy(void)
{
}

__attribute__((used)) static void notify_signal(struct sigevent *sev)
{
	siginfo_t si = {
		.si_signo = sev->sigev_signo,
		.si_value = sev->sigev_value,
		.si_code = SI_ASYNCIO,
		.si_pid = __pthread_self()->pid,
		.si_uid = getuid()
	};
	__syscall(SYS_rt_sigqueueinfo, si.si_pid, si.si_signo, &si);
}

__attribute__((used)) static void *io_thread(void *p)
{
	struct aiocb *cb = p;
	int fd = cb->aio_fildes;
	void *buf = (void *)cb->aio_buf;
	size_t len = cb->aio_nbytes;
	off_t off = cb->aio_offset;
	int op = cb->aio_lio_opcode;
	struct sigevent sev = cb->aio_sigevent;
	ssize_t ret;

	if (op == LIO_WRITE) {
		if (  (fcntl(fd, F_GETFL) & O_APPEND)
		    ||((ret = pwrite(fd, buf, len, off))<0 && errno==ESPIPE) )
			ret = write(fd, buf, len);
	} else if (op == LIO_READ) {
		if ( (ret = pread(fd, buf, len, off))<0 && errno==ESPIPE )
			ret = read(fd, buf, len);
	} else {
		ret = 0;
	}
	cb->__ret = ret;

	if (ret < 0) a_store(&cb->__err, errno);
	else a_store(&cb->__err, 0);

	__aio_wake();

	switch (sev.sigev_notify) {
	case SIGEV_SIGNAL:
		notify_signal(&sev);
		break;
	case SIGEV_THREAD:
		sev.sigev_notify_function(sev.sigev_value);
		break;
	}

	return 0;
}

__attribute__((used)) static int new_req(struct aiocb *cb)
{
	int ret = 0;
	pthread_attr_t a;
	sigset_t set;
	pthread_t td;

	if (cb->aio_sigevent.sigev_notify == SIGEV_THREAD) {
		if (cb->aio_sigevent.sigev_notify_attributes)
			a = *cb->aio_sigevent.sigev_notify_attributes;
		else
			pthread_attr_init(&a);
	} else {
		pthread_attr_init(&a);
		pthread_attr_setstacksize(&a, PAGE_SIZE);
		pthread_attr_setguardsize(&a, 0);
	}
	pthread_attr_setdetachstate(&a, PTHREAD_CREATE_DETACHED);
	sigfillset(&set);
	pthread_sigmask(SIG_BLOCK, &set, &set);
	cb->__err = EINPROGRESS;
	if (pthread_create(&td, &a, io_thread, cb)) {
		errno = EAGAIN;
		ret = -1;
	}
	pthread_sigmask(SIG_SETMASK, &set, 0);
	cb->__td = td;

	return ret;
}

int aio_read(struct aiocb *cb)
{
	cb->aio_lio_opcode = LIO_READ;
	return new_req(cb);
}

int aio_write(struct aiocb *cb)
{
	cb->aio_lio_opcode = LIO_WRITE;
	return new_req(cb);
}

