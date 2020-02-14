#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct alloc_info {int flags; unsigned long base; unsigned long size; } ;
struct TYPE_4__ {void* (* finddevice ) (char const*) ;int (* getprop ) (void*,char const*,void*,int) ;int (* setprop ) (void*,char const*,void const*,int) ;int (* del_node ) (void const*) ;void* (* get_parent ) (char const*) ;void* (* create_node ) (void const*,char const*) ;void* (* find_node_by_prop_value ) (void const*,char const*,char const*,int) ;void* (* find_node_by_compatible ) (void const*,char const*) ;char* (* get_path ) (void const*,char*,int) ;} ;
struct TYPE_3__ {void* (* malloc ) (unsigned long) ;void (* free ) (void*) ;void* (* realloc ) (void*,unsigned long) ;int /*<<< orphan*/  (* exit ) () ;} ;

/* Variables and functions */
 int ENTRY_BEEN_USED ; 
 int ENTRY_IN_USE ; 
 int MAX_PATH_LEN ; 
 unsigned long _ALIGN_UP (unsigned long,int) ; 
 int alloc_min ; 
 struct alloc_info* alloc_tbl ; 
 TYPE_2__ dt_ops ; 
 int /*<<< orphan*/  memcpy (void*,void*,unsigned long) ; 
 int /*<<< orphan*/  memset (struct alloc_info*,int /*<<< orphan*/ ,unsigned long) ; 
 unsigned long next_base ; 
 TYPE_1__ platform_ops ; 
 unsigned long space_left ; 
 int strlen (char const*) ; 
 void* stub1 (char const*) ; 
 char* stub10 (void const*,char*,int) ; 
 void* stub11 (unsigned long) ; 
 void stub12 (void*) ; 
 int /*<<< orphan*/  stub13 () ; 
 int stub2 (void*,char const*,void*,int) ; 
 int stub3 (void*,char const*,void const*,int) ; 
 int stub4 (void*,char const*,char const*,int) ; 
 int stub5 (void const*) ; 
 void* stub6 (char const*) ; 
 void* stub7 (void const*,char const*) ; 
 void* stub8 (void const*,char const*,char const*,int) ; 
 void* stub9 (void const*,char const*) ; 
 unsigned long tbl_entries ; 

__attribute__((used)) static inline void *finddevice(const char *name)
{
	return (dt_ops.finddevice) ? dt_ops.finddevice(name) : NULL;
}

__attribute__((used)) static inline int getprop(void *devp, const char *name, void *buf, int buflen)
{
	return (dt_ops.getprop) ? dt_ops.getprop(devp, name, buf, buflen) : -1;
}

__attribute__((used)) static inline int setprop(void *devp, const char *name,
                          const void *buf, int buflen)
{
	return (dt_ops.setprop) ? dt_ops.setprop(devp, name, buf, buflen) : -1;
}

__attribute__((used)) static inline int setprop_str(void *devp, const char *name, const char *buf)
{
	if (dt_ops.setprop)
		return dt_ops.setprop(devp, name, buf, strlen(buf) + 1);

	return -1;
}

__attribute__((used)) static inline int del_node(const void *devp)
{
	return dt_ops.del_node ? dt_ops.del_node(devp) : -1;
}

__attribute__((used)) static inline void *get_parent(const char *devp)
{
	return dt_ops.get_parent ? dt_ops.get_parent(devp) : NULL;
}

__attribute__((used)) static inline void *create_node(const void *parent, const char *name)
{
	return dt_ops.create_node ? dt_ops.create_node(parent, name) : NULL;
}

__attribute__((used)) static inline void *find_node_by_prop_value(const void *prev,
                                            const char *propname,
                                            const char *propval, int proplen)
{
	if (dt_ops.find_node_by_prop_value)
		return dt_ops.find_node_by_prop_value(prev, propname,
		                                      propval, proplen);

	return NULL;
}

__attribute__((used)) static inline void *find_node_by_prop_value_str(const void *prev,
                                                const char *propname,
                                                const char *propval)
{
	return find_node_by_prop_value(prev, propname, propval,
	                               strlen(propval) + 1);
}

__attribute__((used)) static inline void *find_node_by_devtype(const void *prev,
                                         const char *type)
{
	return find_node_by_prop_value_str(prev, "device_type", type);
}

__attribute__((used)) static inline void *find_node_by_alias(const char *alias)
{
	void *devp = finddevice("/aliases");

	if (devp) {
		char path[MAX_PATH_LEN];
		if (getprop(devp, alias, path, MAX_PATH_LEN) > 0)
			return finddevice(path);
	}

	return NULL;
}

__attribute__((used)) static inline void *find_node_by_compatible(const void *prev,
                                            const char *compat)
{
	if (dt_ops.find_node_by_compatible)
		return dt_ops.find_node_by_compatible(prev, compat);

	return NULL;
}

__attribute__((used)) static inline void *find_node_by_linuxphandle(const u32 linuxphandle)
{
	return find_node_by_prop_value(NULL, "linux,phandle",
			(char *)&linuxphandle, sizeof(u32));
}

__attribute__((used)) static inline char *get_path(const void *phandle, char *buf, int len)
{
	if (dt_ops.get_path)
		return dt_ops.get_path(phandle, buf, len);

	return NULL;
}

__attribute__((used)) static inline void *malloc(unsigned long size)
{
	return (platform_ops.malloc) ? platform_ops.malloc(size) : NULL;
}

__attribute__((used)) static inline void free(void *ptr)
{
	if (platform_ops.free)
		platform_ops.free(ptr);
}

__attribute__((used)) static inline void exit(void)
{
	if (platform_ops.exit)
		platform_ops.exit();
	for(;;);
}

__attribute__((used)) static inline __attribute__((const))
int __ilog2_u32(u32 n)
{
	int bit;
	asm ("cntlzw %0,%1" : "=r" (bit) : "r" (n));
	return 31 - bit;
}

__attribute__((used)) static void *simple_malloc(unsigned long size)
{
	unsigned long i;
	struct alloc_info *p = alloc_tbl;

	if (size == 0)
		goto err_out;

	size = _ALIGN_UP(size, alloc_min);

	for (i=0; i<tbl_entries; i++, p++)
		if (!(p->flags & ENTRY_BEEN_USED)) { /* never been used */
			if (size <= space_left) {
				p->base = next_base;
				p->size = size;
				p->flags = ENTRY_BEEN_USED | ENTRY_IN_USE;
				next_base += size;
				space_left -= size;
				return (void *)p->base;
			}
			goto err_out; /* not enough space left */
		}
		/* reuse an entry keeping same base & size */
		else if (!(p->flags & ENTRY_IN_USE) && (size <= p->size)) {
			p->flags |= ENTRY_IN_USE;
			return (void *)p->base;
		}
err_out:
	return NULL;
}

__attribute__((used)) static struct alloc_info *simple_find_entry(void *ptr)
{
	unsigned long i;
	struct alloc_info *p = alloc_tbl;

	for (i=0; i<tbl_entries; i++,p++) {
		if (!(p->flags & ENTRY_BEEN_USED))
			break;
		if ((p->flags & ENTRY_IN_USE) &&
		    (p->base == (unsigned long)ptr))
			return p;
	}
	return NULL;
}

__attribute__((used)) static void simple_free(void *ptr)
{
	struct alloc_info *p = simple_find_entry(ptr);

	if (p != NULL)
		p->flags &= ~ENTRY_IN_USE;
}

__attribute__((used)) static void *simple_realloc(void *ptr, unsigned long size)
{
	struct alloc_info *p;
	void *new;

	if (size == 0) {
		simple_free(ptr);
		return NULL;
	}

	if (ptr == NULL)
		return simple_malloc(size);

	p = simple_find_entry(ptr);
	if (p == NULL) /* ptr not from simple_malloc/simple_realloc */
		return NULL;
	if (size <= p->size) /* fits in current block */
		return ptr;

	new = simple_malloc(size);
	memcpy(new, ptr, p->size);
	simple_free(ptr);
	return new;
}

void *simple_alloc_init(char *base, unsigned long heap_size,
			unsigned long granularity, unsigned long max_allocs)
{
	unsigned long heap_base, tbl_size;

	heap_size = _ALIGN_UP(heap_size, granularity);
	alloc_min = granularity;
	tbl_entries = max_allocs;

	tbl_size = tbl_entries * sizeof(struct alloc_info);

	alloc_tbl = (struct alloc_info *)_ALIGN_UP((unsigned long)base, 8);
	memset(alloc_tbl, 0, tbl_size);

	heap_base = _ALIGN_UP((unsigned long)alloc_tbl + tbl_size, alloc_min);

	next_base = heap_base;
	space_left = heap_size;

	platform_ops.malloc = simple_malloc;
	platform_ops.free = simple_free;
	platform_ops.realloc = simple_realloc;

	return (void *)(heap_base + heap_size);
}

