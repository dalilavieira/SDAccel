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
struct TYPE_4__ {void* (* finddevice ) (char const*) ;int (* getprop ) (void*,char const*,void*,int) ;int (* setprop ) (void*,char const*,void const*,int) ;int (* del_node ) (void const*) ;void* (* get_parent ) (char const*) ;void* (* create_node ) (void const*,char const*) ;void* (* find_node_by_prop_value ) (void const*,char const*,char const*,int) ;void* (* find_node_by_compatible ) (void const*,char const*) ;char* (* get_path ) (void const*,char*,int) ;unsigned long (* finalize ) () ;} ;
struct TYPE_3__ {void* (* malloc ) (unsigned long) ;void* (* realloc ) (void*,int) ;int /*<<< orphan*/  (* exit ) () ;int /*<<< orphan*/  (* free ) (void*) ;} ;

/* Variables and functions */
 int EXPAND_GRANULARITY ; 
 int FDT_ERR_NOSPACE ; 
 int MAX_PATH_LEN ; 
 int _ALIGN (int,int) ; 
 void* buf ; 
 int check_err (int) ; 
 int /*<<< orphan*/  devp_offset (void const*) ; 
 int /*<<< orphan*/  devp_offset_find (void const*) ; 
 TYPE_2__ dt_ops ; 
 int /*<<< orphan*/  fatal (char*,...) ; 
 void* fdt ; 
 int fdt_add_subnode (void*,int /*<<< orphan*/ ,char const*) ; 
 int fdt_del_node (void*,int /*<<< orphan*/ ) ; 
 int fdt_get_path (void*,int /*<<< orphan*/ ,char*,int) ; 
 void* fdt_getprop (void*,int /*<<< orphan*/ ,char const*,int*) ; 
 int fdt_node_offset_by_compatible (void*,int /*<<< orphan*/ ,char const*) ; 
 int fdt_node_offset_by_prop_value (void*,int /*<<< orphan*/ ,char const*,char const*,int) ; 
 int fdt_open_into (void*,void*,int) ; 
 int fdt_pack (void*) ; 
 int fdt_parent_offset (void*,int /*<<< orphan*/ ) ; 
 int fdt_path_offset (void*,char const*) ; 
 int fdt_setprop (void*,int /*<<< orphan*/ ,char const*,void const*,int const) ; 
 int fdt_strerror (int) ; 
 int fdt_totalsize (void*) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  min (int,int const) ; 
 void* offset_devp (int) ; 
 TYPE_1__ platform_ops ; 
 int strlen (char const*) ; 
 void* stub1 (char const*) ; 
 char* stub10 (void const*,char*,int) ; 
 void* stub11 (unsigned long) ; 
 int /*<<< orphan*/  stub12 (void*) ; 
 int /*<<< orphan*/  stub13 () ; 
 void* stub14 (void*,int) ; 
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

__attribute__((used)) static void expand_buf(int minexpand)
{
	int size = fdt_totalsize(fdt);
	int rc;

	size = _ALIGN(size + minexpand, EXPAND_GRANULARITY);
	buf = platform_ops.realloc(buf, size);
	if (!buf)
		fatal("Couldn't find %d bytes to expand device tree\n\r", size);
	rc = fdt_open_into(fdt, buf, size);
	if (rc != 0)
		fatal("Couldn't expand fdt into new buffer: %s\n\r",
		      fdt_strerror(rc));

	fdt = buf;
}

__attribute__((used)) static void *fdt_wrapper_finddevice(const char *path)
{
	return offset_devp(fdt_path_offset(fdt, path));
}

__attribute__((used)) static int fdt_wrapper_getprop(const void *devp, const char *name,
			       void *buf, const int buflen)
{
	const void *p;
	int len;

	p = fdt_getprop(fdt, devp_offset(devp), name, &len);
	if (!p)
		return check_err(len);
	memcpy(buf, p, min(len, buflen));
	return len;
}

__attribute__((used)) static int fdt_wrapper_setprop(const void *devp, const char *name,
			       const void *buf, const int len)
{
	int rc;

	rc = fdt_setprop(fdt, devp_offset(devp), name, buf, len);
	if (rc == -FDT_ERR_NOSPACE) {
		expand_buf(len + 16);
		rc = fdt_setprop(fdt, devp_offset(devp), name, buf, len);
	}

	return check_err(rc);
}

__attribute__((used)) static int fdt_wrapper_del_node(const void *devp)
{
	return fdt_del_node(fdt, devp_offset(devp));
}

__attribute__((used)) static void *fdt_wrapper_get_parent(const void *devp)
{
	return offset_devp(fdt_parent_offset(fdt, devp_offset(devp)));
}

__attribute__((used)) static void *fdt_wrapper_create_node(const void *devp, const char *name)
{
	int offset;

	offset = fdt_add_subnode(fdt, devp_offset(devp), name);
	if (offset == -FDT_ERR_NOSPACE) {
		expand_buf(strlen(name) + 16);
		offset = fdt_add_subnode(fdt, devp_offset(devp), name);
	}

	return offset_devp(offset);
}

__attribute__((used)) static void *fdt_wrapper_find_node_by_prop_value(const void *prev,
						 const char *name,
						 const char *val,
						 int len)
{
	int offset = fdt_node_offset_by_prop_value(fdt, devp_offset_find(prev),
	                                           name, val, len);
	return offset_devp(offset);
}

__attribute__((used)) static void *fdt_wrapper_find_node_by_compatible(const void *prev,
						 const char *val)
{
	int offset = fdt_node_offset_by_compatible(fdt, devp_offset_find(prev),
	                                           val);
	return offset_devp(offset);
}

__attribute__((used)) static char *fdt_wrapper_get_path(const void *devp, char *buf, int len)
{
	int rc;

	rc = fdt_get_path(fdt, devp_offset(devp), buf, len);
	if (check_err(rc))
		return NULL;
	return buf;
}

__attribute__((used)) static unsigned long fdt_wrapper_finalize(void)
{
	int rc;

	rc = fdt_pack(fdt);
	if (rc != 0)
		fatal("Couldn't pack flat tree: %s\n\r",
		      fdt_strerror(rc));
	return (unsigned long)fdt;
}

void fdt_init(void *blob)
{
	int err;
	int bufsize;

	dt_ops.finddevice = fdt_wrapper_finddevice;
	dt_ops.getprop = fdt_wrapper_getprop;
	dt_ops.setprop = fdt_wrapper_setprop;
	dt_ops.get_parent = fdt_wrapper_get_parent;
	dt_ops.create_node = fdt_wrapper_create_node;
	dt_ops.find_node_by_prop_value = fdt_wrapper_find_node_by_prop_value;
	dt_ops.find_node_by_compatible = fdt_wrapper_find_node_by_compatible;
	dt_ops.del_node = fdt_wrapper_del_node;
	dt_ops.get_path = fdt_wrapper_get_path;
	dt_ops.finalize = fdt_wrapper_finalize;

	/* Make sure the dt blob is the right version and so forth */
	fdt = blob;
	bufsize = fdt_totalsize(fdt) + EXPAND_GRANULARITY;
	buf = malloc(bufsize);
	if(!buf)
		fatal("malloc failed. can't relocate the device tree\n\r");

	err = fdt_open_into(fdt, buf, bufsize);

	if (err != 0)
		fatal("fdt_init(): %s\n\r", fdt_strerror(err));

	fdt = buf;
}

