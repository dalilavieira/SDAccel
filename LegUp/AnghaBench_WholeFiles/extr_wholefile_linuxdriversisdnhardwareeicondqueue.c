#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  spinlock_t ;
typedef  int /*<<< orphan*/  dword ;
struct TYPE_10__ {int max_length; int segments; void** data; int* length; scalar_t__ read; scalar_t__ write; scalar_t__ count; scalar_t__ segment_pending; } ;
typedef  TYPE_1__ diva_um_idi_data_queue_t ;
typedef  int /*<<< orphan*/  diva_os_spin_lock_t ;
typedef  int /*<<< orphan*/  diva_os_spin_lock_magic_t ;
typedef  int diva_os_atomic_t ;
typedef  int /*<<< orphan*/  __u32 ;
typedef  int /*<<< orphan*/  __u16 ;
typedef  int /*<<< orphan*/  __le32 ;
typedef  int /*<<< orphan*/  __le16 ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int diva_data_q_finit (TYPE_1__*) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vfree (void*) ; 
 scalar_t__ vmalloc (unsigned int) ; 

__attribute__((used)) static __inline__ void *diva_os_malloc(unsigned long flags, unsigned long size)
{
	void *ret = NULL;

	if (size) {
		ret = (void *) vmalloc((unsigned int) size);
	}
	return (ret);
}

__attribute__((used)) static __inline__ void diva_os_free(unsigned long flags, void *ptr)
{
	vfree(ptr);
}

__attribute__((used)) static __inline__ void diva_os_sleep(dword mSec)
{
	msleep(mSec);
}

__attribute__((used)) static __inline__ void diva_os_wait(dword mSec)
{
	mdelay(mSec);
}

__attribute__((used)) static __inline__ int diva_os_initialize_spin_lock(spinlock_t *lock, void *unused) { \
	spin_lock_init(lock); return (0); }

__attribute__((used)) static __inline__ void diva_os_enter_spin_lock(diva_os_spin_lock_t *a, \
					       diva_os_spin_lock_magic_t *old_irql, \
					       void *dbg) { spin_lock_bh(a); }

__attribute__((used)) static __inline__ void diva_os_leave_spin_lock(diva_os_spin_lock_t *a, \
					       diva_os_spin_lock_magic_t *old_irql, \
					       void *dbg) { spin_unlock_bh(a); }

__attribute__((used)) static inline diva_os_atomic_t
diva_os_atomic_increment(diva_os_atomic_t *pv)
{
	*pv += 1;
	return (*pv);
}

__attribute__((used)) static inline diva_os_atomic_t
diva_os_atomic_decrement(diva_os_atomic_t *pv)
{
	*pv -= 1;
	return (*pv);
}

__attribute__((used)) static inline __u16 GET_WORD(void *addr)
{
	return le16_to_cpu(*(__le16 *)addr);
}

__attribute__((used)) static inline __u32 GET_DWORD(void *addr)
{
	return le32_to_cpu(*(__le32 *)addr);
}

__attribute__((used)) static inline void PUT_WORD(void *addr, __u16 v)
{
	*(__le16 *)addr = cpu_to_le16(v);
}

__attribute__((used)) static inline void PUT_DWORD(void *addr, __u32 v)
{
	*(__le32 *)addr = cpu_to_le32(v);
}

int
diva_data_q_init(diva_um_idi_data_queue_t *q,
		 int max_length, int max_segments)
{
	int i;

	q->max_length = max_length;
	q->segments = max_segments;

	for (i = 0; i < q->segments; i++) {
		q->data[i] = NULL;
		q->length[i] = 0;
	}
	q->read = q->write = q->count = q->segment_pending = 0;

	for (i = 0; i < q->segments; i++) {
		if (!(q->data[i] = diva_os_malloc(0, q->max_length))) {
			diva_data_q_finit(q);
			return (-1);
		}
	}

	return (0);
}

int diva_data_q_finit(diva_um_idi_data_queue_t *q)
{
	int i;

	for (i = 0; i < q->segments; i++) {
		if (q->data[i]) {
			diva_os_free(0, q->data[i]);
		}
		q->data[i] = NULL;
		q->length[i] = 0;
	}
	q->read = q->write = q->count = q->segment_pending = 0;

	return (0);
}

int diva_data_q_get_max_length(const diva_um_idi_data_queue_t *q)
{
	return (q->max_length);
}

void *diva_data_q_get_segment4write(diva_um_idi_data_queue_t *q)
{
	if ((!q->segment_pending) && (q->count < q->segments)) {
		q->segment_pending = 1;
		return (q->data[q->write]);
	}

	return NULL;
}

void
diva_data_q_ack_segment4write(diva_um_idi_data_queue_t *q, int length)
{
	if (q->segment_pending) {
		q->length[q->write] = length;
		q->count++;
		q->write++;
		if (q->write >= q->segments) {
			q->write = 0;
		}
		q->segment_pending = 0;
	}
}

const void *diva_data_q_get_segment4read(const diva_um_idi_data_queue_t *
					 q)
{
	if (q->count) {
		return (q->data[q->read]);
	}
	return NULL;
}

int diva_data_q_get_segment_length(const diva_um_idi_data_queue_t *q)
{
	return (q->length[q->read]);
}

void diva_data_q_ack_segment4read(diva_um_idi_data_queue_t *q)
{
	if (q->count) {
		q->length[q->read] = 0;
		q->count--;
		q->read++;
		if (q->read >= q->segments) {
			q->read = 0;
		}
	}
}

