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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_4__ {void* (* finddevice ) (char const*) ;int (* getprop ) (void*,char const*,void*,int) ;int (* setprop ) (void*,char const*,void const*,int) ;int (* del_node ) (void const*) ;void* (* get_parent ) (char const*) ;void* (* create_node ) (void const*,char const*) ;void* (* find_node_by_prop_value ) (void const*,char const*,char const*,int) ;void* (* find_node_by_compatible ) (void const*,char const*) ;char* (* get_path ) (void const*,char*,int) ;} ;
struct TYPE_3__ {void* (* malloc ) (unsigned long) ;void (* fixups ) () ;int /*<<< orphan*/  (* exit ) () ;int /*<<< orphan*/  (* free ) (void*) ;} ;

/* Variables and functions */
 int MAX_PATH_LEN ; 
 int /*<<< orphan*/  PLANETCORE_KEY_CRYSTAL_HZ ; 
 int /*<<< orphan*/  PLANETCORE_KEY_MB_RAM ; 
 int /*<<< orphan*/  _dtb_start ; 
 scalar_t__ _end ; 
 int /*<<< orphan*/  dt_fixup_memory (int /*<<< orphan*/ ,int) ; 
 TYPE_2__ dt_ops ; 
 int /*<<< orphan*/  fdt_init (int /*<<< orphan*/ ) ; 
 int mem_size ; 
 int /*<<< orphan*/  mpc885_fixup_clocks (int) ; 
 int /*<<< orphan*/  planetcore_get_decimal (char*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  planetcore_prepare_table (char*) ; 
 int /*<<< orphan*/  planetcore_set_mac_addrs (char*) ; 
 int /*<<< orphan*/  planetcore_set_stdout_path (char*) ; 
 TYPE_1__ platform_ops ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  serial_console_init () ; 
 int /*<<< orphan*/  simple_alloc_init (scalar_t__,int,int,int) ; 
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
 char* table ; 

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

__attribute__((used)) static void platform_fixups(void)
{
	u64 val;

	dt_fixup_memory(0, mem_size);
	planetcore_set_mac_addrs(table);

	if (!planetcore_get_decimal(table, PLANETCORE_KEY_CRYSTAL_HZ, &val)) {
		printf("No PlanetCore crystal frequency key.\r\n");
		return;
	}

	mpc885_fixup_clocks(val);
}

void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
                   unsigned long r6, unsigned long r7)
{
	table = (char *)r3;
	planetcore_prepare_table(table);

	if (!planetcore_get_decimal(table, PLANETCORE_KEY_MB_RAM, &mem_size))
		return;

	mem_size *= 1024 * 1024;
	simple_alloc_init(_end, mem_size - (unsigned long)_end, 32, 64);

	fdt_init(_dtb_start);

	planetcore_set_stdout_path(table);

	serial_console_init();
	platform_ops.fixups = platform_fixups;
}

