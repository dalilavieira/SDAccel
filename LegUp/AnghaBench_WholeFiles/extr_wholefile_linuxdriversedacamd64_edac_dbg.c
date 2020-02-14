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
typedef  int /*<<< orphan*/  umode_t ;
typedef  size_t u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct mem_ctl_info {int dummy; } ;
struct file_operations {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct dentry {int dummy; } ;
struct amd64_pvt {int fam; int model; int dct_sel_hi; int dct_sel_lo; size_t dhar; int /*<<< orphan*/  F1; TYPE_3__* ranges; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_8__ {int x86; } ;
struct TYPE_6__ {int lo; scalar_t__ hi; } ;
struct TYPE_5__ {scalar_t__ hi; scalar_t__ lo; } ;
struct TYPE_7__ {TYPE_2__ base; TYPE_1__ lim; } ;

/* Variables and functions */
 size_t BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DRAM_CONT_BASE ; 
 int /*<<< orphan*/  DRAM_CONT_LIMIT ; 
 int ENODEV ; 
 int X86_CR0_CD ; 
 int /*<<< orphan*/  amd64_get_dram_hole_info (struct mem_ctl_info*,int*,int*,int*) ; 
 int /*<<< orphan*/  amd64_read_pci_cfg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 TYPE_4__ boot_cpu_data ; 
 int read_cr0 () ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int,int) ; 
 struct mem_ctl_info* to_mci (struct device*) ; 
 int /*<<< orphan*/  wbinvd () ; 
 int /*<<< orphan*/  write_cr0 (int) ; 

__attribute__((used)) static inline int edac_debugfs_init(void)					{ return -ENODEV; }

__attribute__((used)) static inline void edac_debugfs_exit(void)					{ }

__attribute__((used)) static inline int edac_create_debugfs_nodes(struct mem_ctl_info *mci)		{ return 0; }

__attribute__((used)) static inline struct dentry *edac_debugfs_create_dir(const char *dirname)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_dir_at(const char *dirname, struct dentry *parent)		{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_file(const char *name, umode_t mode, struct dentry *parent,
			 void *data, const struct file_operations *fops)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x8(const char *name, umode_t mode,
		       struct dentry *parent, u8 *value)			{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x16(const char *name, umode_t mode,
		       struct dentry *parent, u16 *value)			{ return NULL; }

__attribute__((used)) static inline u32 get_umc_base(u8 channel)
{
	/* ch0: 0x50000, ch1: 0x150000 */
	return 0x50000 + (!!channel << 20);
}

__attribute__((used)) static inline u64 get_dram_base(struct amd64_pvt *pvt, u8 i)
{
	u64 addr = ((u64)pvt->ranges[i].base.lo & 0xffff0000) << 8;

	if (boot_cpu_data.x86 == 0xf)
		return addr;

	return (((u64)pvt->ranges[i].base.hi & 0x000000ff) << 40) | addr;
}

__attribute__((used)) static inline u64 get_dram_limit(struct amd64_pvt *pvt, u8 i)
{
	u64 lim = (((u64)pvt->ranges[i].lim.lo & 0xffff0000) << 8) | 0x00ffffff;

	if (boot_cpu_data.x86 == 0xf)
		return lim;

	return (((u64)pvt->ranges[i].lim.hi & 0x000000ff) << 40) | lim;
}

__attribute__((used)) static inline u16 extract_syndrome(u64 status)
{
	return ((status >> 47) & 0xff) | ((status >> 16) & 0xff00);
}

__attribute__((used)) static inline u8 dct_sel_interleave_addr(struct amd64_pvt *pvt)
{
	if (pvt->fam == 0x15 && pvt->model >= 0x30)
		return (((pvt->dct_sel_hi >> 9) & 0x1) << 2) |
			((pvt->dct_sel_lo >> 6) & 0x3);

	return	((pvt)->dct_sel_lo >> 6) & 0x3;
}

__attribute__((used)) static inline void disable_caches(void *dummy)
{
	write_cr0(read_cr0() | X86_CR0_CD);
	wbinvd();
}

__attribute__((used)) static inline void enable_caches(void *dummy)
{
	write_cr0(read_cr0() & ~X86_CR0_CD);
}

__attribute__((used)) static inline u8 dram_intlv_en(struct amd64_pvt *pvt, unsigned int i)
{
	if (pvt->fam == 0x15 && pvt->model >= 0x30) {
		u32 tmp;
		amd64_read_pci_cfg(pvt->F1, DRAM_CONT_LIMIT, &tmp);
		return (u8) tmp & 0xF;
	}
	return (u8) (pvt->ranges[i].base.lo >> 8) & 0x7;
}

__attribute__((used)) static inline u8 dhar_valid(struct amd64_pvt *pvt)
{
	if (pvt->fam == 0x15 && pvt->model >= 0x30) {
		u32 tmp;
		amd64_read_pci_cfg(pvt->F1, DRAM_CONT_BASE, &tmp);
		return (tmp >> 1) & BIT(0);
	}
	return (pvt)->dhar & BIT(0);
}

__attribute__((used)) static inline u32 dct_sel_baseaddr(struct amd64_pvt *pvt)
{
	if (pvt->fam == 0x15 && pvt->model >= 0x30) {
		u32 tmp;
		amd64_read_pci_cfg(pvt->F1, DRAM_CONT_BASE, &tmp);
		return (tmp >> 11) & 0x1FFF;
	}
	return (pvt)->dct_sel_lo & 0xFFFFF800;
}

__attribute__((used)) static ssize_t amd64_hole_show(struct device *dev,
			       struct device_attribute *mattr,
			       char *data)
{
	struct mem_ctl_info *mci = to_mci(dev);

	u64 hole_base = 0;
	u64 hole_offset = 0;
	u64 hole_size = 0;

	amd64_get_dram_hole_info(mci, &hole_base, &hole_offset, &hole_size);

	return sprintf(data, "%llx %llx %llx\n", hole_base, hole_offset,
						 hole_size);
}

