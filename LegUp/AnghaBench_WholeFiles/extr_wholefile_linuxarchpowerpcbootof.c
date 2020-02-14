#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_8__ {void* (* finddevice ) (char const*) ;int (* getprop ) (void*,char const*,void*,int) ;int (* setprop ) (void*,char const*,void const*,int) ;int (* del_node ) (void const*) ;void* (* get_parent ) (char const*) ;void* (* create_node ) (void const*,char const*) ;void* (* find_node_by_prop_value ) (void const*,char const*,char const*,int) ;void* (* find_node_by_compatible ) (void const*,char const*) ;char* (* get_path ) (void const*,char*,int) ;} ;
struct TYPE_7__ {unsigned long initrd_addr; unsigned long initrd_size; void* promptr; } ;
struct TYPE_6__ {void* (* malloc ) (unsigned long) ;void (* image_hdr ) (void const*) ;int /*<<< orphan*/  vmlinux_alloc; int /*<<< orphan*/  (* exit ) () ;int /*<<< orphan*/  (* free ) (void*) ;} ;
struct TYPE_5__ {scalar_t__* e_ident; } ;
typedef  TYPE_1__ Elf64_Ehdr ;

/* Variables and functions */
 size_t EI_CLASS ; 
 scalar_t__ ELFCLASS64 ; 
 int MAX_PATH_LEN ; 
 scalar_t__ ONE_MB ; 
 scalar_t__ PAGE_ALIGN (scalar_t__) ; 
 scalar_t__ PROG_START ; 
 unsigned long PROM_ERROR ; 
 scalar_t__ RAM_END ; 
 scalar_t__ _ALIGN_UP (unsigned long,scalar_t__) ; 
 scalar_t__ _end ; 
 scalar_t__ claim_base ; 
 TYPE_4__ dt_ops ; 
 int /*<<< orphan*/  epapr_platform_init (unsigned long,unsigned long,unsigned long,unsigned long,unsigned long) ; 
 TYPE_3__ loader_info ; 
 scalar_t__ of_claim (scalar_t__,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_console_init () ; 
 int /*<<< orphan*/  of_exit () ; 
 void* of_finddevice (char const*) ; 
 int of_getprop (void*,char const*,void*,int) ; 
 int /*<<< orphan*/  of_init (void*) ; 
 int of_setprop (void*,char const*,char const*,int) ; 
 int /*<<< orphan*/  of_vmlinux_alloc ; 
 TYPE_2__ platform_ops ; 
 int strlen (char const*) ; 
 void* stub1 (char const*) ; 
 char* stub10 (void const*,char*,int) ; 
 void* stub11 (unsigned long) ; 
 int /*<<< orphan*/  stub12 (void*) ; 
 int /*<<< orphan*/  stub13 () ; 
 int stub2 (void*,char const*,void*,int) ; 
 int stub3 (void*,char const*,void const*,int) ; 
 int stub4 (void*,char const*,char const*,int) ; 
 int stub5 (void const*) ; 
 void* stub6 (char const*) ; 
 void* stub7 (void const*,char const*) ; 
 void* stub8 (void const*,char const*,char const*,int) ; 
 void* stub9 (void const*,char const*) ; 

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

__attribute__((used)) static inline u16 swab16(u16 x)
{
	return  ((x & (u16)0x00ffU) << 8) |
		((x & (u16)0xff00U) >> 8);
}

__attribute__((used)) static inline u32 swab32(u32 x)
{
	return  ((x & (u32)0x000000ffUL) << 24) |
		((x & (u32)0x0000ff00UL) <<  8) |
		((x & (u32)0x00ff0000UL) >>  8) |
		((x & (u32)0xff000000UL) >> 24);
}

__attribute__((used)) static inline u64 swab64(u64 x)
{
	return  (u64)((x & (u64)0x00000000000000ffULL) << 56) |
		(u64)((x & (u64)0x000000000000ff00ULL) << 40) |
		(u64)((x & (u64)0x0000000000ff0000ULL) << 24) |
		(u64)((x & (u64)0x00000000ff000000ULL) <<  8) |
		(u64)((x & (u64)0x000000ff00000000ULL) >>  8) |
		(u64)((x & (u64)0x0000ff0000000000ULL) >> 24) |
		(u64)((x & (u64)0x00ff000000000000ULL) >> 40) |
		(u64)((x & (u64)0xff00000000000000ULL) >> 56);
}

__attribute__((used)) static void *of_try_claim(unsigned long size)
{
	unsigned long addr = 0;

	if (claim_base == 0)
		claim_base = _ALIGN_UP((unsigned long)_end, ONE_MB);

	for(; claim_base < RAM_END; claim_base += ONE_MB) {
#ifdef DEBUG
		printf("    trying: 0x%08lx\n\r", claim_base);
#endif
		addr = (unsigned long) of_claim(claim_base, size, 0);
		if (addr != PROM_ERROR)
			break;
	}
	if (addr == 0)
		return NULL;
	claim_base = PAGE_ALIGN(claim_base + size);
	return (void *)addr;
}

__attribute__((used)) static void of_image_hdr(const void *hdr)
{
	const Elf64_Ehdr *elf64 = hdr;

	if (elf64->e_ident[EI_CLASS] == ELFCLASS64) {
		/*
		 * Maintain a "magic" minimum address. This keeps some older
		 * firmware platforms running.
		 */
		if (claim_base < PROG_START)
			claim_base = PROG_START;
	}
}

__attribute__((used)) static void of_platform_init(unsigned long a1, unsigned long a2, void *promptr)
{
	platform_ops.image_hdr = of_image_hdr;
	platform_ops.malloc = of_try_claim;
	platform_ops.exit = of_exit;
	platform_ops.vmlinux_alloc = of_vmlinux_alloc;

	dt_ops.finddevice = of_finddevice;
	dt_ops.getprop = of_getprop;
	dt_ops.setprop = of_setprop;

	of_console_init();

	of_init(promptr);
	loader_info.promptr = promptr;
	if (a1 && a2 && a2 != 0xdeadbeef) {
		loader_info.initrd_addr = a1;
		loader_info.initrd_size = a2;
	}
}

void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
		   unsigned long r6, unsigned long r7)
{
	/* Detect OF vs. ePAPR boot */
	if (r5)
		of_platform_init(r3, r4, (void *)r5);
	else
		epapr_platform_init(r3, r4, r5, r6, r7);
}

