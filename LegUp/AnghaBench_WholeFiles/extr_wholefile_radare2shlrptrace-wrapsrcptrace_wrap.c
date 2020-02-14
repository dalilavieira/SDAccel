#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ptrace_wrap_ptrace_request ;
struct TYPE_18__ {void* (* func ) (void*) ;void* user; } ;
struct TYPE_17__ {void (* child_callback ) (void*) ;void* child_callback_user; int* _errno; } ;
struct TYPE_16__ {scalar_t__ pid; void* addr; void* data; int* _errno; int /*<<< orphan*/  request; } ;
struct TYPE_19__ {int type; TYPE_3__ func; TYPE_2__ fork; TYPE_1__ ptrace; } ;
struct TYPE_20__ {scalar_t__ th; long ptrace_result; scalar_t__ fork_result; void* func_result; int /*<<< orphan*/  result_sem; int /*<<< orphan*/  request_sem; TYPE_4__ request; } ;
typedef  TYPE_5__ ptrace_wrap_instance ;
typedef  void* (* ptrace_wrap_func_func ) (void*) ;
typedef  scalar_t__ pid_t ;

/* Variables and functions */
#define  PTRACE_WRAP_REQUEST_TYPE_FORK 131 
#define  PTRACE_WRAP_REQUEST_TYPE_FUNC 130 
#define  PTRACE_WRAP_REQUEST_TYPE_PTRACE 129 
#define  PTRACE_WRAP_REQUEST_TYPE_STOP 128 
 int errno ; 
 scalar_t__ fork () ; 
 int pthread_create (scalar_t__*,int /*<<< orphan*/ *,void* (*) (void*),TYPE_5__*) ; 
 int /*<<< orphan*/  pthread_join (scalar_t__,int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_self () ; 
 long ptrace (int /*<<< orphan*/ ,scalar_t__,void*,void*) ; 
 int /*<<< orphan*/  sem_destroy (int /*<<< orphan*/ *) ; 
 int sem_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sem_post (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sem_wait (int /*<<< orphan*/ *) ; 
 void stub1 (void*) ; 
 void* stub2 (void*) ; 
static  void* th_run (TYPE_5__*) ; 

int ptrace_wrap_instance_start(ptrace_wrap_instance *inst) {
	int r = sem_init (&inst->request_sem, 0, 0);
	if (r != 0) {
		return r;
	}

	r = sem_init (&inst->result_sem, 0, 0);
	if (r != 0) {
		sem_destroy (&inst->request_sem);
		return r;
	}

	r = pthread_create (&inst->th, NULL, (void *(*)(void *)) th_run, inst);
	if (r != 0) {
		sem_destroy (&inst->request_sem);
		sem_destroy (&inst->result_sem);
		return r;
	}

	return 0;
}

void ptrace_wrap_instance_stop(ptrace_wrap_instance *inst) {
	inst->request.type = PTRACE_WRAP_REQUEST_TYPE_STOP;
	sem_post (&inst->request_sem);
	pthread_join (inst->th, NULL);
	sem_destroy (&inst->request_sem);
	sem_destroy (&inst->result_sem);
}

__attribute__((used)) static void wrap_ptrace(ptrace_wrap_instance *inst) {
	inst->ptrace_result = ptrace (
			inst->request.ptrace.request,
			inst->request.ptrace.pid,
			inst->request.ptrace.addr,
			inst->request.ptrace.data);
	if (inst->request.ptrace._errno) {
		*inst->request.ptrace._errno = errno;
	}
}

__attribute__((used)) static void wrap_fork(ptrace_wrap_instance *inst) {
	pid_t r = fork();
	if (r == 0) {
		inst->request.fork.child_callback (inst->request.fork.child_callback_user);
	} else {
		inst->fork_result = r;
	}
}

__attribute__((used)) static void wrap_func(ptrace_wrap_instance *inst) {
	inst->func_result = inst->request.func.func (inst->request.func.user);
}

__attribute__((used)) static void *th_run(ptrace_wrap_instance *inst) {
	while (1) {
		sem_wait (&inst->request_sem);
		switch (inst->request.type) {
		case PTRACE_WRAP_REQUEST_TYPE_STOP:
			goto stop;
		case PTRACE_WRAP_REQUEST_TYPE_PTRACE:
			wrap_ptrace (inst);
			break;
		case PTRACE_WRAP_REQUEST_TYPE_FORK:
			wrap_fork (inst);
			break;
		case PTRACE_WRAP_REQUEST_TYPE_FUNC:
			wrap_func (inst);
			break;
		}
		sem_post (&inst->result_sem);
	}
stop:
	return NULL;
}

long ptrace_wrap(ptrace_wrap_instance *inst, ptrace_wrap_ptrace_request request, pid_t pid, void *addr, void *data) {
	if (inst->th == pthread_self ()) {
		return ptrace (request, pid, addr, data);
	}

	int _errno = 0;
	inst->request.type = PTRACE_WRAP_REQUEST_TYPE_PTRACE;
	inst->request.ptrace.request = request;
	inst->request.ptrace.pid = pid;
	inst->request.ptrace.addr = addr;
	inst->request.ptrace.data = data;
	inst->request.ptrace._errno = &_errno;
	sem_post (&inst->request_sem);
	sem_wait (&inst->result_sem);
	errno = _errno;
	return inst->ptrace_result;
}

pid_t ptrace_wrap_fork(ptrace_wrap_instance *inst, void (*child_callback)(void *), void *child_callback_user) {
	if (inst->th == pthread_self ()) {
		pid_t r = fork ();
		if (r == 0) {
			child_callback (child_callback_user);
			return 0;
		} else {
			return r;
		}
	}

	int _errno = 0;
	inst->request.type = PTRACE_WRAP_REQUEST_TYPE_FORK;
	inst->request.fork.child_callback = child_callback;
	inst->request.fork.child_callback_user = child_callback_user;
	inst->request.fork._errno = &_errno;
	sem_post (&inst->request_sem);
	sem_wait (&inst->result_sem);
	errno = _errno;
	return inst->fork_result;
}

void *ptrace_wrap_func(ptrace_wrap_instance *inst, ptrace_wrap_func_func func, void *user) {
	if (inst->th == pthread_self ()) {
		return func (user);
	}

	inst->request.type = PTRACE_WRAP_REQUEST_TYPE_FUNC;
	inst->request.func.func = func;
	inst->request.func.user = user;
	sem_post (&inst->request_sem);
	sem_wait (&inst->result_sem);
	return inst->func_result;
}

