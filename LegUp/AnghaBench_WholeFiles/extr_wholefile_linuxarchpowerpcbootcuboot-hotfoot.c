#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int /*<<< orphan*/  regs ;
struct TYPE_6__ {int bi_procfreq; int bi_plb_busfreq; int bi_opbfreq; int bi_pci_busfreq; scalar_t__* bi_enetaddr; scalar_t__* bi_enet1addr; int bi_flashsize; int /*<<< orphan*/  bi_memsize; int /*<<< orphan*/  bi_memstart; } ;
struct TYPE_5__ {void* (* finddevice ) (char const*) ;int (* getprop ) (void*,char const*,void*,int) ;int (* setprop ) (void*,char const*,void const*,int) ;int (* del_node ) (void const*) ;void* (* get_parent ) (char const*) ;void* (* create_node ) (void const*,char const*) ;void* (* find_node_by_prop_value ) (void const*,char const*,char const*,int) ;void* (* find_node_by_compatible ) (void const*,char const*) ;char* (* get_path ) (void const*,char*,int) ;} ;
struct TYPE_4__ {void* (* malloc ) (unsigned long) ;void (* fixups ) () ;int /*<<< orphan*/  (* exit ) () ;int /*<<< orphan*/  (* free ) (void*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  CUBOOT_INIT () ; 
 int /*<<< orphan*/  DCRN_CPC0_UCR ; 
 int MAX_PATH_LEN ; 
 int NUM_REGS ; 
 int /*<<< orphan*/  _dtb_start ; 
 TYPE_3__ bd ; 
 int /*<<< orphan*/  dt_fixup_clock (char*,int) ; 
 int /*<<< orphan*/  dt_fixup_cpu_clocks (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dt_fixup_mac_address_by_alias (char*,scalar_t__*) ; 
 int /*<<< orphan*/  dt_fixup_memory (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__ dt_ops ; 
 int /*<<< orphan*/  fatal (char*) ; 
 int /*<<< orphan*/  fdt_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ibm40x_dbcr_reset () ; 
 int /*<<< orphan*/  ibm4xx_quiesce_eth (int*,int*) ; 
 int mfdcr (int /*<<< orphan*/ ) ; 
 TYPE_1__ platform_ops ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  serial_console_init () ; 
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

__attribute__((used)) static inline u32 mfpvr(void)
{
	u32 pvr;
	asm volatile ("mfpvr	%0" : "=r"(pvr));
	return pvr;
}

__attribute__((used)) static void hotfoot_fixups(void)
{
	u32 uart = mfdcr(DCRN_CPC0_UCR) & 0x7f;

	dt_fixup_memory(bd.bi_memstart, bd.bi_memsize); 

	dt_fixup_cpu_clocks(bd.bi_procfreq, bd.bi_procfreq, 0);
	dt_fixup_clock("/plb", bd.bi_plb_busfreq);
	dt_fixup_clock("/plb/opb", bd.bi_opbfreq);
	dt_fixup_clock("/plb/ebc", bd.bi_pci_busfreq);
	dt_fixup_clock("/plb/opb/serial@ef600300", bd.bi_procfreq / uart); 
	dt_fixup_clock("/plb/opb/serial@ef600400", bd.bi_procfreq / uart); 
	
	dt_fixup_mac_address_by_alias("ethernet0", bd.bi_enetaddr);
	dt_fixup_mac_address_by_alias("ethernet1", bd.bi_enet1addr);

	/* Is this a single eth/serial board? */
	if ((bd.bi_enet1addr[0] == 0) && 
	    (bd.bi_enet1addr[1] == 0) &&
	    (bd.bi_enet1addr[2] == 0) &&
	    (bd.bi_enet1addr[3] == 0) &&
	    (bd.bi_enet1addr[4] == 0) &&
	    (bd.bi_enet1addr[5] == 0)) {
		void *devp;

		printf("Trimming devtree for single serial/eth board\n");

		devp = finddevice("/plb/opb/serial@ef600300");
		if (!devp)
			fatal("Can't find node for /plb/opb/serial@ef600300");
		del_node(devp);

		devp = finddevice("/plb/opb/ethernet@ef600900");
		if (!devp)
			fatal("Can't find node for /plb/opb/ethernet@ef600900");
		del_node(devp);
	}

	ibm4xx_quiesce_eth((u32 *)0xef600800, (u32 *)0xef600900);

	/* Fix up flash size in fdt for 4M boards. */
	if (bd.bi_flashsize < 0x800000) {
		u32 regs[NUM_REGS];
		void *devp = finddevice("/plb/ebc/nor_flash@0");
		if (!devp)
			fatal("Can't find FDT node for nor_flash!??");

		printf("Fixing devtree for 4M Flash\n");
		
		/* First fix up the base addresse */
		getprop(devp, "reg", regs, sizeof(regs));
		regs[0] = 0;
		regs[1] = 0xffc00000;
		regs[2] = 0x00400000;
		setprop(devp, "reg", regs, sizeof(regs));
		
		/* Then the offsets */
		devp = finddevice("/plb/ebc/nor_flash@0/partition@0");
		if (!devp)
			fatal("Can't find FDT node for partition@0");
		getprop(devp, "reg", regs, 2*sizeof(u32));
		regs[0] -= 0x400000;
		setprop(devp, "reg", regs,  2*sizeof(u32));

		devp = finddevice("/plb/ebc/nor_flash@0/partition@1");
		if (!devp)
			fatal("Can't find FDT node for partition@1");
		getprop(devp, "reg", regs, 2*sizeof(u32));
		regs[0] -= 0x400000;
		setprop(devp, "reg", regs,  2*sizeof(u32));

		devp = finddevice("/plb/ebc/nor_flash@0/partition@2");
		if (!devp)
			fatal("Can't find FDT node for partition@2");
		getprop(devp, "reg", regs, 2*sizeof(u32));
		regs[0] -= 0x400000;
		setprop(devp, "reg", regs,  2*sizeof(u32));

		devp = finddevice("/plb/ebc/nor_flash@0/partition@3");
		if (!devp)
			fatal("Can't find FDT node for partition@3");
		getprop(devp, "reg", regs, 2*sizeof(u32));
		regs[0] -= 0x400000;
		setprop(devp, "reg", regs,  2*sizeof(u32));

		devp = finddevice("/plb/ebc/nor_flash@0/partition@4");
		if (!devp)
			fatal("Can't find FDT node for partition@4");
		getprop(devp, "reg", regs, 2*sizeof(u32));
		regs[0] -= 0x400000;
		setprop(devp, "reg", regs,  2*sizeof(u32));

		devp = finddevice("/plb/ebc/nor_flash@0/partition@6");
		if (!devp)
			fatal("Can't find FDT node for partition@6");
		getprop(devp, "reg", regs, 2*sizeof(u32));
		regs[0] -= 0x400000;
		setprop(devp, "reg", regs,  2*sizeof(u32));

		/* Delete the FeatFS node */
		devp = finddevice("/plb/ebc/nor_flash@0/partition@5");
		if (!devp)
			fatal("Can't find FDT node for partition@5");
		del_node(devp);
	}
}

void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
		   unsigned long r6, unsigned long r7)
{
	CUBOOT_INIT();
	platform_ops.fixups = hotfoot_fixups;
        platform_ops.exit = ibm40x_dbcr_reset;
	fdt_init(_dtb_start);
	serial_console_init();
}

