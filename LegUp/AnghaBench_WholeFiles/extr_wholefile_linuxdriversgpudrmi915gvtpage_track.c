#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct intel_vgpu_page_track {int (* handler ) (struct intel_vgpu_page_track*,unsigned long,void*,unsigned int) ;int tracked; void* priv_data; } ;
struct intel_vgpu_mm {int /*<<< orphan*/  ref; } ;
struct TYPE_10__ {scalar_t__ virtual_cfg_space; } ;
struct intel_vgpu {int /*<<< orphan*/  vgpu_lock; int /*<<< orphan*/  failsafe; int /*<<< orphan*/  page_track_tree; int /*<<< orphan*/  handle; int /*<<< orphan*/  id; TYPE_2__* gvt; TYPE_4__ cfg_space; } ;
struct TYPE_11__ {int* mmio_attribute; } ;
struct intel_gvt {TYPE_5__ mmio; int /*<<< orphan*/  service_thread_wq; int /*<<< orphan*/  service_request; } ;
struct drm_i915_private {struct intel_gvt* gvt; } ;
struct device {int dummy; } ;
typedef  int (* gvt_page_track_handler_t ) (struct intel_vgpu_page_track*,unsigned long,void*,unsigned int) ;
typedef  enum intel_vgpu_edid { ____Placeholder_intel_vgpu_edid } intel_vgpu_edid ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_12__ {TYPE_3__* mpt; } ;
struct TYPE_9__ {int (* host_init ) (struct device*,void*,void const*) ;int (* attach_vgpu ) (struct intel_vgpu*,int /*<<< orphan*/ *) ;int (* inject_msi ) (int /*<<< orphan*/ ,int,int) ;unsigned long (* from_virt_to_mfn ) (void*) ;int (* enable_page_track ) (int /*<<< orphan*/ ,unsigned long) ;int (* disable_page_track ) (int /*<<< orphan*/ ,unsigned long) ;int (* read_gpa ) (int /*<<< orphan*/ ,unsigned long,void*,unsigned long) ;int (* write_gpa ) (int /*<<< orphan*/ ,unsigned long,void*,unsigned long) ;unsigned long (* gfn_to_mfn ) (int /*<<< orphan*/ ,unsigned long) ;int (* dma_map_guest_page ) (int /*<<< orphan*/ ,unsigned long,unsigned long,int /*<<< orphan*/ *) ;int (* map_gfn_to_mfn ) (int /*<<< orphan*/ ,unsigned long,unsigned long,unsigned int,int) ;int (* set_trap_area ) (int /*<<< orphan*/ ,unsigned long,unsigned long,int) ;int (* set_opregion ) (struct intel_vgpu*) ;int (* get_vfio_device ) (struct intel_vgpu*) ;int (* is_valid_gfn ) (int /*<<< orphan*/ ,unsigned long) ;int /*<<< orphan*/  (* put_vfio_device ) (struct intel_vgpu*) ;int /*<<< orphan*/  (* dma_unmap_guest_page ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* detach_vgpu ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* host_exit ) (struct device*,void*) ;} ;
struct TYPE_7__ {unsigned long msi_cap_offset; } ;
struct TYPE_8__ {TYPE_1__ device_info; } ;

/* Variables and functions */
 int EEXIST ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int F_ACCESSED ; 
 int F_CMD_ACCESS ; 
 int F_CMD_ACCESSED ; 
 int F_IN_CTX ; 
 int F_MODE_MASK ; 
 int F_UNALIGN ; 
 int GENMASK (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  GVT_EDID_1024_768 129 
#define  GVT_EDID_1920_1200 128 
 int MSI_CAP_ADDRESS (unsigned long) ; 
 int MSI_CAP_CONTROL (unsigned long) ; 
 int MSI_CAP_DATA (unsigned long) ; 
 int MSI_CAP_EN ; 
 unsigned long PAGE_SHIFT ; 
 unsigned long PCI_BASE_ADDRESS_MEM_MASK ; 
 scalar_t__ WARN (int,char*) ; 
 int /*<<< orphan*/  _intel_vgpu_mm_release ; 
 int /*<<< orphan*/  gvt_err (char*,unsigned long) ; 
 TYPE_6__ intel_gvt_host ; 
 int /*<<< orphan*/  intel_runtime_pm_get (struct drm_i915_private*) ; 
 int /*<<< orphan*/  intel_runtime_pm_put (struct drm_i915_private*) ; 
 int /*<<< orphan*/  kfree (struct intel_vgpu_page_track*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct intel_vgpu_page_track* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct intel_vgpu_page_track* radix_tree_delete (int /*<<< orphan*/ *,unsigned long) ; 
 int radix_tree_insert (int /*<<< orphan*/ *,unsigned long,struct intel_vgpu_page_track*) ; 
 struct intel_vgpu_page_track* radix_tree_lookup (int /*<<< orphan*/ *,unsigned long) ; 
 int rounddown (int,int) ; 
 int /*<<< orphan*/  set_bit (int,void*) ; 
 int stub1 (struct device*,void*,void const*) ; 
 int stub10 (int /*<<< orphan*/ ,unsigned long,void*,unsigned long) ; 
 unsigned long stub11 (int /*<<< orphan*/ ,unsigned long) ; 
 int stub12 (int /*<<< orphan*/ ,unsigned long,unsigned long,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub13 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub14 (int /*<<< orphan*/ ,unsigned long,unsigned long,unsigned int,int) ; 
 int stub15 (int /*<<< orphan*/ ,unsigned long,unsigned long,int) ; 
 int stub16 (struct intel_vgpu*) ; 
 int stub17 (struct intel_vgpu*) ; 
 int /*<<< orphan*/  stub18 (struct intel_vgpu*) ; 
 int stub19 (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  stub2 (struct device*,void*) ; 
 int stub20 (struct intel_vgpu_page_track*,unsigned long,void*,unsigned int) ; 
 int stub3 (struct intel_vgpu*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ) ; 
 int stub5 (int /*<<< orphan*/ ,int,int) ; 
 unsigned long stub6 (void*) ; 
 int stub7 (int /*<<< orphan*/ ,unsigned long) ; 
 int stub8 (int /*<<< orphan*/ ,unsigned long) ; 
 int stub9 (int /*<<< orphan*/ ,unsigned long,void*,unsigned long) ; 
 int /*<<< orphan*/  trace_inject_msi (int /*<<< orphan*/ ,int,int) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 
 int vgpu_cfg_space (struct intel_vgpu*) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void intel_vgpu_mm_get(struct intel_vgpu_mm *mm)
{
	kref_get(&mm->ref);
}

__attribute__((used)) static inline void intel_vgpu_mm_put(struct intel_vgpu_mm *mm)
{
	kref_put(&mm->ref, _intel_vgpu_mm_release);
}

__attribute__((used)) static inline void intel_vgpu_destroy_mm(struct intel_vgpu_mm *mm)
{
	intel_vgpu_mm_put(mm);
}

__attribute__((used)) static inline char *vgpu_edid_str(enum intel_vgpu_edid id)
{
	switch (id) {
	case GVT_EDID_1024_768:
		return "1024x768";
	case GVT_EDID_1920_1200:
		return "1920x1200";
	default:
		return "";
	}
}

__attribute__((used)) static inline struct intel_gvt *to_gvt(struct drm_i915_private *i915)
{
	return i915->gvt;
}

__attribute__((used)) static inline void intel_gvt_request_service(struct intel_gvt *gvt,
		int service)
{
	set_bit(service, (void *)&gvt->service_request);
	wake_up(&gvt->service_thread_wq);
}

__attribute__((used)) static inline void intel_vgpu_write_pci_bar(struct intel_vgpu *vgpu,
					    u32 offset, u32 val, bool low)
{
	u32 *pval;

	/* BAR offset should be 32 bits algiend */
	offset = rounddown(offset, 4);
	pval = (u32 *)(vgpu_cfg_space(vgpu) + offset);

	if (low) {
		/*
		 * only update bit 31 - bit 4,
		 * leave the bit 3 - bit 0 unchanged.
		 */
		*pval = (val & GENMASK(31, 4)) | (*pval & GENMASK(3, 0));
	} else {
		*pval = val;
	}
}

__attribute__((used)) static inline u64 intel_vgpu_get_bar_gpa(struct intel_vgpu *vgpu, int bar)
{
	/* We are 64bit bar. */
	return (*(u64 *)(vgpu->cfg_space.virtual_cfg_space + bar)) &
			PCI_BASE_ADDRESS_MEM_MASK;
}

__attribute__((used)) static inline void mmio_hw_access_pre(struct drm_i915_private *dev_priv)
{
	intel_runtime_pm_get(dev_priv);
}

__attribute__((used)) static inline void mmio_hw_access_post(struct drm_i915_private *dev_priv)
{
	intel_runtime_pm_put(dev_priv);
}

__attribute__((used)) static inline void intel_gvt_mmio_set_accessed(
			struct intel_gvt *gvt, unsigned int offset)
{
	gvt->mmio.mmio_attribute[offset >> 2] |= F_ACCESSED;
}

__attribute__((used)) static inline bool intel_gvt_mmio_is_cmd_access(
			struct intel_gvt *gvt, unsigned int offset)
{
	return gvt->mmio.mmio_attribute[offset >> 2] & F_CMD_ACCESS;
}

__attribute__((used)) static inline bool intel_gvt_mmio_is_unalign(
			struct intel_gvt *gvt, unsigned int offset)
{
	return gvt->mmio.mmio_attribute[offset >> 2] & F_UNALIGN;
}

__attribute__((used)) static inline void intel_gvt_mmio_set_cmd_accessed(
			struct intel_gvt *gvt, unsigned int offset)
{
	gvt->mmio.mmio_attribute[offset >> 2] |= F_CMD_ACCESSED;
}

__attribute__((used)) static inline bool intel_gvt_mmio_has_mode_mask(
			struct intel_gvt *gvt, unsigned int offset)
{
	return gvt->mmio.mmio_attribute[offset >> 2] & F_MODE_MASK;
}

__attribute__((used)) static inline bool intel_gvt_mmio_is_in_ctx(
			struct intel_gvt *gvt, unsigned int offset)
{
	return gvt->mmio.mmio_attribute[offset >> 2] & F_IN_CTX;
}

__attribute__((used)) static inline void intel_gvt_mmio_set_in_ctx(
			struct intel_gvt *gvt, unsigned int offset)
{
	gvt->mmio.mmio_attribute[offset >> 2] |= F_IN_CTX;
}

__attribute__((used)) static inline int intel_gvt_hypervisor_host_init(struct device *dev,
			void *gvt, const void *ops)
{
	/* optional to provide */
	if (!intel_gvt_host.mpt->host_init)
		return 0;

	return intel_gvt_host.mpt->host_init(dev, gvt, ops);
}

__attribute__((used)) static inline void intel_gvt_hypervisor_host_exit(struct device *dev,
			void *gvt)
{
	/* optional to provide */
	if (!intel_gvt_host.mpt->host_exit)
		return;

	intel_gvt_host.mpt->host_exit(dev, gvt);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_attach_vgpu(struct intel_vgpu *vgpu)
{
	/* optional to provide */
	if (!intel_gvt_host.mpt->attach_vgpu)
		return 0;

	return intel_gvt_host.mpt->attach_vgpu(vgpu, &vgpu->handle);
}

__attribute__((used)) static inline void intel_gvt_hypervisor_detach_vgpu(struct intel_vgpu *vgpu)
{
	/* optional to provide */
	if (!intel_gvt_host.mpt->detach_vgpu)
		return;

	intel_gvt_host.mpt->detach_vgpu(vgpu->handle);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_inject_msi(struct intel_vgpu *vgpu)
{
	unsigned long offset = vgpu->gvt->device_info.msi_cap_offset;
	u16 control, data;
	u32 addr;
	int ret;

	control = *(u16 *)(vgpu_cfg_space(vgpu) + MSI_CAP_CONTROL(offset));
	addr = *(u32 *)(vgpu_cfg_space(vgpu) + MSI_CAP_ADDRESS(offset));
	data = *(u16 *)(vgpu_cfg_space(vgpu) + MSI_CAP_DATA(offset));

	/* Do not generate MSI if MSIEN is disable */
	if (!(control & MSI_CAP_EN))
		return 0;

	if (WARN(control & GENMASK(15, 1), "only support one MSI format\n"))
		return -EINVAL;

	trace_inject_msi(vgpu->id, addr, data);

	ret = intel_gvt_host.mpt->inject_msi(vgpu->handle, addr, data);
	if (ret)
		return ret;
	return 0;
}

__attribute__((used)) static inline unsigned long intel_gvt_hypervisor_virt_to_mfn(void *p)
{
	return intel_gvt_host.mpt->from_virt_to_mfn(p);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_enable_page_track(
		struct intel_vgpu *vgpu, unsigned long gfn)
{
	return intel_gvt_host.mpt->enable_page_track(vgpu->handle, gfn);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_disable_page_track(
		struct intel_vgpu *vgpu, unsigned long gfn)
{
	return intel_gvt_host.mpt->disable_page_track(vgpu->handle, gfn);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_read_gpa(struct intel_vgpu *vgpu,
		unsigned long gpa, void *buf, unsigned long len)
{
	return intel_gvt_host.mpt->read_gpa(vgpu->handle, gpa, buf, len);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_write_gpa(struct intel_vgpu *vgpu,
		unsigned long gpa, void *buf, unsigned long len)
{
	return intel_gvt_host.mpt->write_gpa(vgpu->handle, gpa, buf, len);
}

__attribute__((used)) static inline unsigned long intel_gvt_hypervisor_gfn_to_mfn(
		struct intel_vgpu *vgpu, unsigned long gfn)
{
	return intel_gvt_host.mpt->gfn_to_mfn(vgpu->handle, gfn);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_dma_map_guest_page(
		struct intel_vgpu *vgpu, unsigned long gfn, unsigned long size,
		dma_addr_t *dma_addr)
{
	return intel_gvt_host.mpt->dma_map_guest_page(vgpu->handle, gfn, size,
						      dma_addr);
}

__attribute__((used)) static inline void intel_gvt_hypervisor_dma_unmap_guest_page(
		struct intel_vgpu *vgpu, dma_addr_t dma_addr)
{
	intel_gvt_host.mpt->dma_unmap_guest_page(vgpu->handle, dma_addr);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_map_gfn_to_mfn(
		struct intel_vgpu *vgpu, unsigned long gfn,
		unsigned long mfn, unsigned int nr,
		bool map)
{
	/* a MPT implementation could have MMIO mapped elsewhere */
	if (!intel_gvt_host.mpt->map_gfn_to_mfn)
		return 0;

	return intel_gvt_host.mpt->map_gfn_to_mfn(vgpu->handle, gfn, mfn, nr,
						  map);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_set_trap_area(
		struct intel_vgpu *vgpu, u64 start, u64 end, bool map)
{
	/* a MPT implementation could have MMIO trapped elsewhere */
	if (!intel_gvt_host.mpt->set_trap_area)
		return 0;

	return intel_gvt_host.mpt->set_trap_area(vgpu->handle, start, end, map);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_set_opregion(struct intel_vgpu *vgpu)
{
	if (!intel_gvt_host.mpt->set_opregion)
		return 0;

	return intel_gvt_host.mpt->set_opregion(vgpu);
}

__attribute__((used)) static inline int intel_gvt_hypervisor_get_vfio_device(struct intel_vgpu *vgpu)
{
	if (!intel_gvt_host.mpt->get_vfio_device)
		return 0;

	return intel_gvt_host.mpt->get_vfio_device(vgpu);
}

__attribute__((used)) static inline void intel_gvt_hypervisor_put_vfio_device(struct intel_vgpu *vgpu)
{
	if (!intel_gvt_host.mpt->put_vfio_device)
		return;

	intel_gvt_host.mpt->put_vfio_device(vgpu);
}

__attribute__((used)) static inline bool intel_gvt_hypervisor_is_valid_gfn(
		struct intel_vgpu *vgpu, unsigned long gfn)
{
	if (!intel_gvt_host.mpt->is_valid_gfn)
		return true;

	return intel_gvt_host.mpt->is_valid_gfn(vgpu->handle, gfn);
}

struct intel_vgpu_page_track *intel_vgpu_find_page_track(
		struct intel_vgpu *vgpu, unsigned long gfn)
{
	return radix_tree_lookup(&vgpu->page_track_tree, gfn);
}

int intel_vgpu_register_page_track(struct intel_vgpu *vgpu, unsigned long gfn,
		gvt_page_track_handler_t handler, void *priv)
{
	struct intel_vgpu_page_track *track;
	int ret;

	track = intel_vgpu_find_page_track(vgpu, gfn);
	if (track)
		return -EEXIST;

	track = kzalloc(sizeof(*track), GFP_KERNEL);
	if (!track)
		return -ENOMEM;

	track->handler = handler;
	track->priv_data = priv;

	ret = radix_tree_insert(&vgpu->page_track_tree, gfn, track);
	if (ret) {
		kfree(track);
		return ret;
	}

	return 0;
}

void intel_vgpu_unregister_page_track(struct intel_vgpu *vgpu,
		unsigned long gfn)
{
	struct intel_vgpu_page_track *track;

	track = radix_tree_delete(&vgpu->page_track_tree, gfn);
	if (track) {
		if (track->tracked)
			intel_gvt_hypervisor_disable_page_track(vgpu, gfn);
		kfree(track);
	}
}

int intel_vgpu_enable_page_track(struct intel_vgpu *vgpu, unsigned long gfn)
{
	struct intel_vgpu_page_track *track;
	int ret;

	track = intel_vgpu_find_page_track(vgpu, gfn);
	if (!track)
		return -ENXIO;

	if (track->tracked)
		return 0;

	ret = intel_gvt_hypervisor_enable_page_track(vgpu, gfn);
	if (ret)
		return ret;
	track->tracked = true;
	return 0;
}

int intel_vgpu_disable_page_track(struct intel_vgpu *vgpu, unsigned long gfn)
{
	struct intel_vgpu_page_track *track;
	int ret;

	track = intel_vgpu_find_page_track(vgpu, gfn);
	if (!track)
		return -ENXIO;

	if (!track->tracked)
		return 0;

	ret = intel_gvt_hypervisor_disable_page_track(vgpu, gfn);
	if (ret)
		return ret;
	track->tracked = false;
	return 0;
}

int intel_vgpu_page_track_handler(struct intel_vgpu *vgpu, u64 gpa,
		void *data, unsigned int bytes)
{
	struct intel_vgpu_page_track *page_track;
	int ret = 0;

	mutex_lock(&vgpu->vgpu_lock);

	page_track = intel_vgpu_find_page_track(vgpu, gpa >> PAGE_SHIFT);
	if (!page_track) {
		ret = -ENXIO;
		goto out;
	}

	if (unlikely(vgpu->failsafe)) {
		/* Remove write protection to prevent furture traps. */
		intel_vgpu_disable_page_track(vgpu, gpa >> PAGE_SHIFT);
	} else {
		ret = page_track->handler(page_track, gpa, data, bytes);
		if (ret)
			gvt_err("guest page write error, gpa %llx\n", gpa);
	}

out:
	mutex_unlock(&vgpu->vgpu_lock);
	return ret;
}

