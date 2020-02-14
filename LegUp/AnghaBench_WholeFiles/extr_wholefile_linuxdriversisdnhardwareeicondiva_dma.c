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
struct _diva_dma_map_entry {void* addr_handle; int busy; void* local_ram_addr; int /*<<< orphan*/  phys_bus_addr; } ;
typedef  int /*<<< orphan*/  spinlock_t ;
typedef  int /*<<< orphan*/  dword ;
typedef  int /*<<< orphan*/  diva_os_spin_lock_t ;
typedef  int /*<<< orphan*/  diva_os_spin_lock_magic_t ;
typedef  int diva_os_atomic_t ;
typedef  struct _diva_dma_map_entry diva_dma_map_entry_t ;
typedef  int /*<<< orphan*/  __u32 ;
typedef  int /*<<< orphan*/  __u16 ;
typedef  int /*<<< orphan*/  __le32 ;
typedef  int /*<<< orphan*/  __le16 ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct _diva_dma_map_entry*,int /*<<< orphan*/ ,int) ; 
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

struct _diva_dma_map_entry *diva_alloc_dma_map(void *os_context, int nentries) {
	diva_dma_map_entry_t *pmap = diva_os_malloc(0, sizeof(*pmap) * (nentries + 1));
	if (pmap)
		memset(pmap, 0, sizeof(*pmap) * (nentries + 1));
	return pmap;
}

void diva_free_dma_mapping(struct _diva_dma_map_entry *pmap) {
	if (pmap) {
		diva_os_free(0, pmap);
	}
}

void diva_init_dma_map_entry(struct _diva_dma_map_entry *pmap,
			     int nr, void *virt, dword phys,
			     void *addr_handle) {
	pmap[nr].phys_bus_addr  = phys;
	pmap[nr].local_ram_addr = virt;
	pmap[nr].addr_handle    = addr_handle;
}

int diva_alloc_dma_map_entry(struct _diva_dma_map_entry *pmap) {
	int i;
	for (i = 0; (pmap && pmap[i].local_ram_addr); i++) {
		if (!pmap[i].busy) {
			pmap[i].busy = 1;
			return (i);
		}
	}
	return (-1);
}

void diva_free_dma_map_entry(struct _diva_dma_map_entry *pmap, int nr) {
	pmap[nr].busy = 0;
}

void diva_get_dma_map_entry(struct _diva_dma_map_entry *pmap, int nr,
			    void **pvirt, dword *pphys) {
	*pphys = pmap[nr].phys_bus_addr;
	*pvirt = pmap[nr].local_ram_addr;
}

void *diva_get_entry_handle(struct _diva_dma_map_entry *pmap, int nr) {
	return (pmap[nr].addr_handle);
}

