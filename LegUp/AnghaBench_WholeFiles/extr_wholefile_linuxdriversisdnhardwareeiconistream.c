#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  word ;
typedef  int /*<<< orphan*/  spinlock_t ;
typedef  int /*<<< orphan*/  dword ;
struct TYPE_12__ {scalar_t__ provided_service; } ;
typedef  TYPE_1__ diva_xdi_stream_interface_t ;
typedef  int /*<<< orphan*/  diva_os_spin_lock_t ;
typedef  int /*<<< orphan*/  diva_os_spin_lock_magic_t ;
typedef  int diva_os_atomic_t ;
typedef  char byte ;
typedef  int /*<<< orphan*/  __u32 ;
typedef  int /*<<< orphan*/  __u16 ;
typedef  int /*<<< orphan*/  __le32 ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_13__ {scalar_t__* rx_pos; scalar_t__* rx_stream; int /*<<< orphan*/  (* ram_out_dw ) (TYPE_2__*,void*,int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* ram_in_buffer ) (TYPE_2__*,void*,char*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* ram_in_dw ) (TYPE_2__*,void*,int /*<<< orphan*/ *,int) ;scalar_t__* tx_pos; scalar_t__* tx_stream; int /*<<< orphan*/  (* ram_out_buffer ) (TYPE_2__*,void*,char*,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_2__ ADAPTER ;

/* Variables and functions */
 int DIVA_DFIFO_DATA_SZ ; 
 char DIVA_DFIFO_LAST ; 
 char DIVA_DFIFO_READY ; 
 scalar_t__ DIVA_DFIFO_STEP ; 
 char DIVA_DFIFO_WRAP ; 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int /*<<< orphan*/ ) ; 
 int min (int,int) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,void*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_2__*,void*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (TYPE_2__*,void*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__*,void*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  stub5 (TYPE_2__*,void*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (TYPE_2__*,void*,int /*<<< orphan*/ *,int) ; 
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

void diva_xdi_provide_istream_info(ADAPTER *a,
				   diva_xdi_stream_interface_t *pi) {
	pi->provided_service = 0;
}

int diva_istream_write(void *context,
		       int Id,
		       void *data,
		       int length,
		       int final,
		       byte usr1,
		       byte usr2) {
	ADAPTER *a = (ADAPTER *)context;
	int written = 0, to_write = -1;
	char tmp[4];
	byte *data_ptr = (byte *)data;
	for (;;) {
		a->ram_in_dw(a,
#ifdef PLATFORM_GT_32BIT
			      ULongToPtr(a->tx_stream[Id] + a->tx_pos[Id]),
#else
			      (void *)(a->tx_stream[Id] + a->tx_pos[Id]),
#endif
			      (dword *)&tmp[0],
			      1);
		if (tmp[0] & DIVA_DFIFO_READY) { /* No free blocks more */
			if (to_write < 0)
				return (-1); /* was not able to write       */
			break;     /* only part of message was written */
		}
		to_write = min(length, DIVA_DFIFO_DATA_SZ);
		if (to_write) {
			a->ram_out_buffer(a,
#ifdef PLATFORM_GT_32BIT
					   ULongToPtr(a->tx_stream[Id] + a->tx_pos[Id] + 4),
#else
					   (void *)(a->tx_stream[Id] + a->tx_pos[Id] + 4),
#endif
					   data_ptr,
					   (word)to_write);
			length  -= to_write;
			written  += to_write;
			data_ptr += to_write;
		}
		tmp[1] = (char)to_write;
		tmp[0] = (tmp[0] & DIVA_DFIFO_WRAP) |
			DIVA_DFIFO_READY |
			((!length && final) ? DIVA_DFIFO_LAST : 0);
		if (tmp[0] & DIVA_DFIFO_LAST) {
			tmp[2] = usr1;
			tmp[3] = usr2;
		}
		a->ram_out_dw(a,
#ifdef PLATFORM_GT_32BIT
			       ULongToPtr(a->tx_stream[Id] + a->tx_pos[Id]),
#else
			       (void *)(a->tx_stream[Id] + a->tx_pos[Id]),
#endif
			       (dword *)&tmp[0],
			       1);
		if (tmp[0] & DIVA_DFIFO_WRAP) {
			a->tx_pos[Id]  = 0;
		} else {
			a->tx_pos[Id] += DIVA_DFIFO_STEP;
		}
		if (!length) {
			break;
		}
	}
	return (written);
}

int diva_istream_read(void *context,
		      int Id,
		      void *data,
		      int max_length,
		      int *final,
		      byte *usr1,
		      byte *usr2) {
	ADAPTER *a = (ADAPTER *)context;
	int read = 0, to_read = -1;
	char tmp[4];
	byte *data_ptr = (byte *)data;
	*final = 0;
	for (;;) {
		a->ram_in_dw(a,
#ifdef PLATFORM_GT_32BIT
			      ULongToPtr(a->rx_stream[Id] + a->rx_pos[Id]),
#else
			      (void *)(a->rx_stream[Id] + a->rx_pos[Id]),
#endif
			      (dword *)&tmp[0],
			      1);
		if (tmp[1] > max_length) {
			if (to_read < 0)
				return (-2); /* was not able to read */
			break;
		}
		if (!(tmp[0] & DIVA_DFIFO_READY)) {
			if (to_read < 0)
				return (-1); /* was not able to read */
			break;
		}
		to_read = min(max_length, (int)tmp[1]);
		if (to_read) {
			a->ram_in_buffer(a,
#ifdef PLATFORM_GT_32BIT
					 ULongToPtr(a->rx_stream[Id] + a->rx_pos[Id] + 4),
#else
					 (void *)(a->rx_stream[Id] + a->rx_pos[Id] + 4),
#endif
					 data_ptr,
					 (word)to_read);
			max_length -= to_read;
			read     += to_read;
			data_ptr  += to_read;
		}
		if (tmp[0] & DIVA_DFIFO_LAST) {
			*final = 1;
		}
		tmp[0] &= DIVA_DFIFO_WRAP;
		a->ram_out_dw(a,
#ifdef PLATFORM_GT_32BIT
			      ULongToPtr(a->rx_stream[Id] + a->rx_pos[Id]),
#else
			      (void *)(a->rx_stream[Id] + a->rx_pos[Id]),
#endif
			      (dword *)&tmp[0],
			      1);
		if (tmp[0] & DIVA_DFIFO_WRAP) {
			a->rx_pos[Id]  = 0;
		} else {
			a->rx_pos[Id] += DIVA_DFIFO_STEP;
		}
		if (*final) {
			if (usr1)
				*usr1 = tmp[2];
			if (usr2)
				*usr2 = tmp[3];
			break;
		}
	}
	return (read);
}

void pr_stream(ADAPTER *a) {
}

