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
typedef  int /*<<< orphan*/  zone_t ;
typedef  int /*<<< orphan*/  vm_size_t ;
typedef  int /*<<< orphan*/  boolean_t ;

/* Variables and functions */
 int /*<<< orphan*/  CAST_USER_ADDR_T (void*) ; 
 int /*<<< orphan*/  FALSE ; 
 int M_WAITOK ; 
 int /*<<< orphan*/  VM_KERN_MEMORY_SECURITY ; 
 int VM_PROT_READ ; 
 int VM_PROT_WRITE ; 
 void* kalloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kalloc_map ; 
 void* kalloc_noblock (int /*<<< orphan*/ ) ; 
 void kfree (void*,int /*<<< orphan*/ ) ; 
 int vm_map_unwire (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int vm_map_wire_kernel (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* zalloc (int /*<<< orphan*/ ) ; 
 void* zalloc_noblock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zfree (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  zinit (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  zone_change (int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 

void *
mac_kalloc(vm_size_t size, int how)
{

	if (how == M_WAITOK)
		return kalloc(size);
	else
		return kalloc_noblock(size);
}

void *
mac_kalloc_noblock(vm_size_t size)
{
	return kalloc_noblock(size);
}

void
mac_kfree(void * data, vm_size_t size)
{

	return kfree(data, size);
}

void *
mac_mbuf_alloc(int len, int wait)
{
#if CONFIG_MACF_SOCKET_SUBSET
	struct m_tag *t;

	t = m_tag_alloc(KERNEL_MODULE_TAG_ID, KERNEL_TAG_TYPE_MAC_POLICY_LABEL,
			len, wait);
	if (t == NULL)
		return (NULL);

	return ((void *)(t + 1));
#else
#pragma unused(len, wait)
	return NULL;
#endif
}

void
mac_mbuf_free(void *data)
{
#if CONFIG_MACF_SOCKET_SUBSET
	struct m_tag *t;

	t = (struct m_tag *)((char *)data - sizeof(struct m_tag));
	m_tag_free(t);
#else
#pragma unused(data)
#endif
}

int
mac_wire(void *start, void *end)
{

	return (vm_map_wire_kernel(kalloc_map, CAST_USER_ADDR_T(start),
		CAST_USER_ADDR_T(end), VM_PROT_READ|VM_PROT_WRITE, VM_KERN_MEMORY_SECURITY, FALSE));
}

int
mac_unwire(void *start, void *end)
{

	return (vm_map_unwire(kalloc_map, CAST_USER_ADDR_T(start),
		CAST_USER_ADDR_T(end), FALSE));
}

zone_t
mac_zinit(vm_size_t size, vm_size_t maxmem, vm_size_t alloc, const char *name)
{

	return zinit(size, maxmem, alloc, name);
}

void
mac_zone_change(zone_t zone, unsigned int item, boolean_t value)
{

	zone_change(zone, item, value);
}

void *
mac_zalloc(zone_t zone, int how)
{

	if (how == M_WAITOK)
		return zalloc(zone);
	else
		return zalloc_noblock(zone);
}

void
mac_zfree(zone_t zone, void *elem)
{

	zfree(zone, elem);
}

