#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  int uint32_t ;
struct TYPE_14__ {int sc_pid; int sc_flags; scalar_t__ sc_buffer; int sc_size; uintptr_t sc_out_buffer_addr; uintptr_t sc_out_size_addr; scalar_t__ sc_delta_timestamp; } ;
typedef  TYPE_1__ stackshot_config_t ;
typedef  int /*<<< orphan*/  mach_vm_size_t ;
typedef  int /*<<< orphan*/  mach_vm_offset_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  STACKSHOT_CONFIG_TYPE ; 
 int __stack_snapshot_with_config (int /*<<< orphan*/ ,uintptr_t,int) ; 
 int errno ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  mach_task_self () ; 
 int /*<<< orphan*/  mach_vm_deallocate (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__* malloc (int) ; 

stackshot_config_t *
stackshot_config_create(void)
{
	stackshot_config_t *s_config;

	s_config = malloc(sizeof(stackshot_config_t));
	if (s_config == NULL) {
		return NULL;
	}

	s_config->sc_pid = -1;
	s_config->sc_flags = 0;
	s_config->sc_delta_timestamp = 0;
	s_config->sc_buffer = 0;
	s_config->sc_size = 0;

	return s_config;
}

int
stackshot_config_set_pid(stackshot_config_t *stackshot_config, int pid)
{
	stackshot_config_t *s_config;

	if (stackshot_config == NULL) {
		return EINVAL;
	}

	s_config = (stackshot_config_t *) stackshot_config;
	s_config->sc_pid = pid;

	return 0;
}

int
stackshot_config_set_flags(stackshot_config_t *stackshot_config, uint32_t flags)
{
	stackshot_config_t *s_config;

	if (stackshot_config == NULL) {
		return EINVAL;
	}

	s_config = (stackshot_config_t *) stackshot_config;
	s_config->sc_flags = flags;

	return 0;
}

int
stackshot_capture_with_config(stackshot_config_t *stackshot_config)
{
	int ret;
	stackshot_config_t *s_config;

	if (stackshot_config == NULL) {
		return EINVAL;
	}

	s_config = (stackshot_config_t *) stackshot_config;
	if (s_config->sc_buffer != 0)  {
		return EINVAL;
	}

	s_config->sc_out_buffer_addr = (uintptr_t)&s_config->sc_buffer;
	s_config->sc_out_size_addr = (uintptr_t)&s_config->sc_size;
	ret = __stack_snapshot_with_config(STACKSHOT_CONFIG_TYPE, (uintptr_t)s_config, sizeof(stackshot_config_t));
	
	if (ret != 0) {
		ret = errno;
		s_config->sc_buffer = 0;
		s_config->sc_size = 0;
	}

	return ret;
}

void *
stackshot_config_get_stackshot_buffer(stackshot_config_t *stackshot_config)
{
	stackshot_config_t *s_config;

	if (stackshot_config == NULL) {
		return NULL;
	}
	s_config = (stackshot_config_t *) stackshot_config;

	return ((void *)s_config->sc_buffer);
}

uint32_t
stackshot_config_get_stackshot_size(stackshot_config_t * stackshot_config)
{
	if (stackshot_config == NULL || (void *)stackshot_config->sc_buffer == NULL) {
		return -1;
	}

	return stackshot_config->sc_size;
}

int
stackshot_config_set_size_hint(stackshot_config_t *stackshot_config, uint32_t suggested_size)
{
	if (stackshot_config == NULL || (void *)stackshot_config->sc_buffer != NULL) {
		return -1;
	}

	stackshot_config->sc_size = suggested_size;

	return 0;
}

int
stackshot_config_set_delta_timestamp(stackshot_config_t *stackshot_config, uint64_t delta_timestamp)
{
	if (stackshot_config == NULL || (void *)stackshot_config->sc_buffer != NULL) {
		return -1;
	}

	stackshot_config->sc_delta_timestamp = delta_timestamp;

	return 0;
}

int
stackshot_config_dealloc_buffer(stackshot_config_t *stackshot_config)
{
	stackshot_config_t *s_config;

	if (stackshot_config == NULL) {
		return EINVAL;
	}
	s_config = (stackshot_config_t *) stackshot_config;

	if (s_config->sc_size && s_config->sc_buffer) {
		mach_vm_deallocate(mach_task_self(), (mach_vm_offset_t)s_config->sc_buffer, (mach_vm_size_t)s_config->sc_size);
	}

	s_config->sc_buffer = 0;
	s_config->sc_size = 0;

	return 0;
}

int
stackshot_config_dealloc(stackshot_config_t *stackshot_config)
{
	stackshot_config_t *s_config;

	if (stackshot_config == NULL) {
		return EINVAL;
	}
	s_config = (stackshot_config_t *) stackshot_config;

	if (s_config->sc_size && s_config->sc_buffer) {
		mach_vm_deallocate(mach_task_self(), (mach_vm_offset_t)s_config->sc_buffer, (mach_vm_size_t)s_config->sc_size);
	}

	s_config->sc_buffer = 0;
	s_config->sc_size = 0;

	free(s_config);
	return 0;
}

