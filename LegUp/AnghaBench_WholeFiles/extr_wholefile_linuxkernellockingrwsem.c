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
struct rw_semaphore {scalar_t__ owner; int /*<<< orphan*/  dep_map; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG_RWSEMS_WARN_ON (int) ; 
 scalar_t__ RWSEM_READER_OWNED ; 
 int /*<<< orphan*/  _RET_IP_ ; 
 int __down_read_trylock (struct rw_semaphore*) ; 
 int __down_write_trylock (struct rw_semaphore*) ; 
 int /*<<< orphan*/  __downgrade_write (struct rw_semaphore*) ; 
 int /*<<< orphan*/  __up_read (struct rw_semaphore*) ; 
 int /*<<< orphan*/  __up_write (struct rw_semaphore*) ; 
 scalar_t__ current ; 
 int /*<<< orphan*/  lock_downgrade (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rwsem_acquire (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rwsem_acquire_read (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rwsem_release (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void rwsem_set_owner(struct rw_semaphore *sem)
{
}

__attribute__((used)) static inline void rwsem_clear_owner(struct rw_semaphore *sem)
{
}

__attribute__((used)) static inline void rwsem_set_reader_owned(struct rw_semaphore *sem)
{
}

int down_read_trylock(struct rw_semaphore *sem)
{
	int ret = __down_read_trylock(sem);

	if (ret == 1) {
		rwsem_acquire_read(&sem->dep_map, 0, 1, _RET_IP_);
		rwsem_set_reader_owned(sem);
	}
	return ret;
}

int down_write_trylock(struct rw_semaphore *sem)
{
	int ret = __down_write_trylock(sem);

	if (ret == 1) {
		rwsem_acquire(&sem->dep_map, 0, 1, _RET_IP_);
		rwsem_set_owner(sem);
	}

	return ret;
}

void up_read(struct rw_semaphore *sem)
{
	rwsem_release(&sem->dep_map, 1, _RET_IP_);
	DEBUG_RWSEMS_WARN_ON(sem->owner != RWSEM_READER_OWNED);

	__up_read(sem);
}

void up_write(struct rw_semaphore *sem)
{
	rwsem_release(&sem->dep_map, 1, _RET_IP_);
	DEBUG_RWSEMS_WARN_ON(sem->owner != current);

	rwsem_clear_owner(sem);
	__up_write(sem);
}

void downgrade_write(struct rw_semaphore *sem)
{
	lock_downgrade(&sem->dep_map, _RET_IP_);
	DEBUG_RWSEMS_WARN_ON(sem->owner != current);

	rwsem_set_reader_owned(sem);
	__downgrade_write(sem);
}

