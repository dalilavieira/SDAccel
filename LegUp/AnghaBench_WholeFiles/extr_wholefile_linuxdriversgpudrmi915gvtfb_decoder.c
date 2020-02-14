#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_9__ ;
typedef  struct TYPE_22__   TYPE_8__ ;
typedef  struct TYPE_21__   TYPE_7__ ;
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct intel_vgpu_sprite_plane_format {int enabled; int tiled; int hw_format; int drm_format; int base; scalar_t__ base_gpa; int stride; int height; int width; int x_pos; int y_pos; int x_offset; int y_offset; scalar_t__ bpp; } ;
struct intel_vgpu_primary_plane_format {int enabled; int tiled; int bpp; int hw_format; int base; scalar_t__ base_gpa; int stride; int width; int height; int x_offset; int y_offset; int /*<<< orphan*/  drm_format; } ;
struct intel_vgpu_mm {int /*<<< orphan*/  ref; } ;
struct intel_vgpu_cursor_plane_format {int enabled; int mode; int base; scalar_t__ base_gpa; int x_pos; int x_sign; int y_pos; int y_sign; int x_hot; int y_hot; int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  drm_format; scalar_t__ bpp; } ;
struct TYPE_20__ {int /*<<< orphan*/  ggtt_mm; } ;
struct TYPE_15__ {scalar_t__ virtual_cfg_space; } ;
struct intel_vgpu {TYPE_6__ gtt; TYPE_5__* gvt; int /*<<< orphan*/  handle; int /*<<< orphan*/  id; TYPE_1__ cfg_space; } ;
struct TYPE_16__ {int* mmio_attribute; } ;
struct intel_gvt {TYPE_2__ mmio; int /*<<< orphan*/  service_thread_wq; int /*<<< orphan*/  service_request; } ;
struct drm_i915_private {struct intel_gvt* gvt; } ;
struct device {int dummy; } ;
typedef  enum intel_vgpu_edid { ____Placeholder_intel_vgpu_edid } intel_vgpu_edid ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_23__ {TYPE_4__* mpt; } ;
struct TYPE_22__ {int bpp; int /*<<< orphan*/  drm_format; } ;
struct TYPE_21__ {int drm_format; scalar_t__ bpp; } ;
struct TYPE_17__ {unsigned long msi_cap_offset; } ;
struct TYPE_19__ {struct drm_i915_private* dev_priv; TYPE_3__ device_info; } ;
struct TYPE_18__ {int (* host_init ) (struct device*,void*,void const*) ;int (* attach_vgpu ) (struct intel_vgpu*,int /*<<< orphan*/ *) ;int (* inject_msi ) (int /*<<< orphan*/ ,int,int) ;unsigned long (* from_virt_to_mfn ) (void*) ;int (* enable_page_track ) (int /*<<< orphan*/ ,unsigned long) ;int (* disable_page_track ) (int /*<<< orphan*/ ,unsigned long) ;int (* read_gpa ) (int /*<<< orphan*/ ,unsigned long,void*,unsigned long) ;int (* write_gpa ) (int /*<<< orphan*/ ,unsigned long,void*,unsigned long) ;unsigned long (* gfn_to_mfn ) (int /*<<< orphan*/ ,unsigned long) ;int (* dma_map_guest_page ) (int /*<<< orphan*/ ,unsigned long,unsigned long,int /*<<< orphan*/ *) ;int (* map_gfn_to_mfn ) (int /*<<< orphan*/ ,unsigned long,unsigned long,unsigned int,int) ;int (* set_trap_area ) (int /*<<< orphan*/ ,int,int,int) ;int (* set_opregion ) (struct intel_vgpu*) ;int (* get_vfio_device ) (struct intel_vgpu*) ;int (* is_valid_gfn ) (int /*<<< orphan*/ ,unsigned long) ;int /*<<< orphan*/  (* put_vfio_device ) (struct intel_vgpu*) ;int /*<<< orphan*/  (* dma_unmap_guest_page ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* detach_vgpu ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* host_exit ) (struct device*,void*) ;} ;
struct TYPE_14__ {int bpp; int /*<<< orphan*/  drm_format; } ;
struct TYPE_13__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  drm_format; scalar_t__ bpp; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_8__*) ; 
 int /*<<< orphan*/  CURBASE (int) ; 
 int /*<<< orphan*/  CURCNTR (int) ; 
 int /*<<< orphan*/  CURPOS (int) ; 
 int DISPLAY_PLANE_ENABLE ; 
#define  DISPPLANE_8BPP 148 
#define  DISPPLANE_BGRX101010 147 
#define  DISPPLANE_BGRX565 146 
#define  DISPPLANE_BGRX888 145 
 int DISPPLANE_PIXFORMAT_MASK ; 
#define  DISPPLANE_RGBX101010 144 
#define  DISPPLANE_RGBX888 143 
 int DISPPLANE_TILED ; 
 int DRM_FORMAT_UYVY ; 
 int DRM_FORMAT_VYUY ; 
 int DRM_FORMAT_XBGR2101010 ; 
 int DRM_FORMAT_XBGR8888 ; 
 int DRM_FORMAT_XRGB2101010 ; 
 int DRM_FORMAT_XRGB8888 ; 
 int DRM_FORMAT_YUV422 ; 
 int DRM_FORMAT_YUYV ; 
 int DRM_FORMAT_YVYU ; 
 int /*<<< orphan*/  DSPCNTR (int) ; 
 int /*<<< orphan*/  DSPSTRIDE (int) ; 
 int /*<<< orphan*/  DSPSURF (int) ; 
 int /*<<< orphan*/  DSPTILEOFF (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int F_ACCESSED ; 
 int F_CMD_ACCESS ; 
 int F_CMD_ACCESSED ; 
 int F_IN_CTX ; 
 int F_MODE_MASK ; 
 int F_UNALIGN ; 
 int GENMASK (int,int) ; 
#define  GVT_EDID_1024_768 142 
#define  GVT_EDID_1920_1200 141 
 int I915_GTT_PAGE_MASK ; 
 int I915_MAX_PIPES ; 
 scalar_t__ INTEL_GVT_INVALID_ADDR ; 
 scalar_t__ IS_BROXTON (struct drm_i915_private*) ; 
 scalar_t__ IS_KABYLAKE (struct drm_i915_private*) ; 
 scalar_t__ IS_SKYLAKE (struct drm_i915_private*) ; 
 int MCURSOR_MODE ; 
#define  MCURSOR_MODE_128_ARGB_AX 140 
#define  MCURSOR_MODE_256_ARGB_AX 139 
#define  MCURSOR_MODE_64_32B_AX 138 
#define  MCURSOR_MODE_64_ARGB_AX 137 
 int MCURSOR_MODE_DISABLE ; 
 int MSI_CAP_ADDRESS (unsigned long) ; 
 int MSI_CAP_CONTROL (unsigned long) ; 
 int MSI_CAP_DATA (unsigned long) ; 
 int MSI_CAP_EN ; 
 int PCI_BASE_ADDRESS_MEM_MASK ; 
 int /*<<< orphan*/  PIPESRC (int) ; 
 int PLANE_CTL_ALPHA_MASK ; 
#define  PLANE_CTL_FORMAT_INDEXED 136 
 int PLANE_CTL_FORMAT_MASK ; 
#define  PLANE_CTL_FORMAT_RGB_565 135 
#define  PLANE_CTL_FORMAT_XRGB_2101010 134 
#define  PLANE_CTL_FORMAT_XRGB_8888 133 
#define  PLANE_CTL_FORMAT_YUV422 132 
 int PLANE_CTL_ORDER_RGBX ; 
#define  PLANE_CTL_TILED_LINEAR 131 
 int PLANE_CTL_TILED_MASK ; 
#define  PLANE_CTL_TILED_X 130 
#define  PLANE_CTL_TILED_Y 129 
#define  PLANE_CTL_TILED_YF 128 
 int PLANE_CTL_YUV422_ORDER_MASK ; 
 int /*<<< orphan*/  SPRCTL (int) ; 
 int SPRITE_ENABLE ; 
 int SPRITE_PIXFORMAT_MASK ; 
 int SPRITE_RGB_ORDER_RGBX ; 
 int SPRITE_TILED ; 
 int SPRITE_YUV_BYTE_ORDER_MASK ; 
 int /*<<< orphan*/  SPROFFSET (int) ; 
 int /*<<< orphan*/  SPRPOS (int) ; 
 int /*<<< orphan*/  SPRSIZE (int) ; 
 int /*<<< orphan*/  SPRSTRIDE (int) ; 
 int /*<<< orphan*/  SPRSURF (int) ; 
 scalar_t__ WARN (int,char*) ; 
 int _CURSOR_ALPHA_FORCE_MASK ; 
 int _CURSOR_ALPHA_FORCE_SHIFT ; 
 int _CURSOR_ALPHA_PLANE_MASK ; 
 int _CURSOR_ALPHA_PLANE_SHIFT ; 
 int _CURSOR_POS_X_MASK ; 
 int _CURSOR_POS_X_SHIFT ; 
 int _CURSOR_POS_Y_MASK ; 
 int _CURSOR_POS_Y_SHIFT ; 
 int _CURSOR_SIGN_X_MASK ; 
 int _CURSOR_SIGN_X_SHIFT ; 
 int _CURSOR_SIGN_Y_MASK ; 
 int _CURSOR_SIGN_Y_SHIFT ; 
 int _PIPE_H_SRCSZ_MASK ; 
 int _PIPE_H_SRCSZ_SHIFT ; 
 int _PIPE_V_SRCSZ_MASK ; 
 int _PIPE_V_SRCSZ_SHIFT ; 
 int _PRI_PLANE_STRIDE_MASK ; 
 int _PRI_PLANE_X_OFF_MASK ; 
 int _PRI_PLANE_X_OFF_SHIFT ; 
 int _PRI_PLANE_Y_OFF_MASK ; 
 int _PRI_PLANE_Y_OFF_SHIFT ; 
 int _SPRITE_FMT_SHIFT ; 
 int _SPRITE_OFFSET_START_X_MASK ; 
 int _SPRITE_OFFSET_START_X_SHIFT ; 
 int _SPRITE_OFFSET_START_Y_MASK ; 
 int _SPRITE_OFFSET_START_Y_SHIFT ; 
 int _SPRITE_POS_X_MASK ; 
 int _SPRITE_POS_X_SHIFT ; 
 int _SPRITE_POS_Y_MASK ; 
 int _SPRITE_POS_Y_SHIFT ; 
 int _SPRITE_SIZE_HEIGHT_MASK ; 
 int _SPRITE_SIZE_HEIGHT_SHIFT ; 
 int _SPRITE_SIZE_WIDTH_MASK ; 
 int _SPRITE_SIZE_WIDTH_SHIFT ; 
 int _SPRITE_STRIDE_MASK ; 
 int _SPRITE_YUV_ORDER_SHIFT ; 
 int /*<<< orphan*/  _intel_vgpu_mm_release ; 
 TYPE_11__* bdw_pixel_formats ; 
 TYPE_10__* cursor_pixel_formats ; 
 int /*<<< orphan*/  cursor_x_hot ; 
 int /*<<< orphan*/  cursor_y_hot ; 
 int /*<<< orphan*/  gvt_dbg_core (char*,int,...) ; 
 int /*<<< orphan*/  gvt_vgpu_err (char*,...) ; 
 int /*<<< orphan*/  intel_gvt_ggtt_validate_range (struct intel_vgpu*,int,int /*<<< orphan*/ ) ; 
 TYPE_9__ intel_gvt_host ; 
 int /*<<< orphan*/  intel_runtime_pm_get (struct drm_i915_private*) ; 
 int /*<<< orphan*/  intel_runtime_pm_put (struct drm_i915_private*) ; 
 void* intel_vgpu_gma_to_gpa (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ pipe_is_enabled (struct intel_vgpu*,int) ; 
 int rounddown (int,int) ; 
 int /*<<< orphan*/  set_bit (int,void*) ; 
 TYPE_8__* skl_pixel_formats ; 
 TYPE_7__* sprite_pixel_formats ; 
 int stub1 (struct device*,void*,void const*) ; 
 int stub10 (int /*<<< orphan*/ ,unsigned long,void*,unsigned long) ; 
 unsigned long stub11 (int /*<<< orphan*/ ,unsigned long) ; 
 int stub12 (int /*<<< orphan*/ ,unsigned long,unsigned long,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub13 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub14 (int /*<<< orphan*/ ,unsigned long,unsigned long,unsigned int,int) ; 
 int stub15 (int /*<<< orphan*/ ,int,int,int) ; 
 int stub16 (struct intel_vgpu*) ; 
 int stub17 (struct intel_vgpu*) ; 
 int /*<<< orphan*/  stub18 (struct intel_vgpu*) ; 
 int stub19 (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  stub2 (struct device*,void*) ; 
 int stub3 (struct intel_vgpu*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ) ; 
 int stub5 (int /*<<< orphan*/ ,int,int) ; 
 unsigned long stub6 (void*) ; 
 int stub7 (int /*<<< orphan*/ ,unsigned long) ; 
 int stub8 (int /*<<< orphan*/ ,unsigned long) ; 
 int stub9 (int /*<<< orphan*/ ,unsigned long,void*,unsigned long) ; 
 int /*<<< orphan*/  trace_inject_msi (int /*<<< orphan*/ ,int,int) ; 
 int vgpu_cfg_space (struct intel_vgpu*) ; 
 int vgpu_vreg_t (struct intel_vgpu*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vgtif_reg (int /*<<< orphan*/ ) ; 
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

__attribute__((used)) static int bdw_format_to_drm(int format)
{
	int bdw_pixel_formats_index = 6;

	switch (format) {
	case DISPPLANE_8BPP:
		bdw_pixel_formats_index = 0;
		break;
	case DISPPLANE_BGRX565:
		bdw_pixel_formats_index = 1;
		break;
	case DISPPLANE_BGRX888:
		bdw_pixel_formats_index = 2;
		break;
	case DISPPLANE_RGBX101010:
		bdw_pixel_formats_index = 3;
		break;
	case DISPPLANE_BGRX101010:
		bdw_pixel_formats_index = 4;
		break;
	case DISPPLANE_RGBX888:
		bdw_pixel_formats_index = 5;
		break;

	default:
		break;
	}

	return bdw_pixel_formats_index;
}

__attribute__((used)) static int skl_format_to_drm(int format, bool rgb_order, bool alpha,
	int yuv_order)
{
	int skl_pixel_formats_index = 12;

	switch (format) {
	case PLANE_CTL_FORMAT_INDEXED:
		skl_pixel_formats_index = 4;
		break;
	case PLANE_CTL_FORMAT_RGB_565:
		skl_pixel_formats_index = 5;
		break;
	case PLANE_CTL_FORMAT_XRGB_8888:
		if (rgb_order)
			skl_pixel_formats_index = alpha ? 6 : 7;
		else
			skl_pixel_formats_index = alpha ? 8 : 9;
		break;
	case PLANE_CTL_FORMAT_XRGB_2101010:
		skl_pixel_formats_index = rgb_order ? 10 : 11;
		break;
	case PLANE_CTL_FORMAT_YUV422:
		skl_pixel_formats_index = yuv_order >> 16;
		if (skl_pixel_formats_index > 3)
			return -EINVAL;
		break;

	default:
		break;
	}

	return skl_pixel_formats_index;
}

__attribute__((used)) static u32 intel_vgpu_get_stride(struct intel_vgpu *vgpu, int pipe,
	u32 tiled, int stride_mask, int bpp)
{
	struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;

	u32 stride_reg = vgpu_vreg_t(vgpu, DSPSTRIDE(pipe)) & stride_mask;
	u32 stride = stride_reg;

	if (IS_SKYLAKE(dev_priv)
		|| IS_KABYLAKE(dev_priv)
		|| IS_BROXTON(dev_priv)) {
		switch (tiled) {
		case PLANE_CTL_TILED_LINEAR:
			stride = stride_reg * 64;
			break;
		case PLANE_CTL_TILED_X:
			stride = stride_reg * 512;
			break;
		case PLANE_CTL_TILED_Y:
			stride = stride_reg * 128;
			break;
		case PLANE_CTL_TILED_YF:
			if (bpp == 8)
				stride = stride_reg * 64;
			else if (bpp == 16 || bpp == 32 || bpp == 64)
				stride = stride_reg * 128;
			else
				gvt_dbg_core("skl: unsupported bpp:%d\n", bpp);
			break;
		default:
			gvt_dbg_core("skl: unsupported tile format:%x\n",
				tiled);
		}
	}

	return stride;
}

__attribute__((used)) static int get_active_pipe(struct intel_vgpu *vgpu)
{
	int i;

	for (i = 0; i < I915_MAX_PIPES; i++)
		if (pipe_is_enabled(vgpu, i))
			break;

	return i;
}

int intel_vgpu_decode_primary_plane(struct intel_vgpu *vgpu,
	struct intel_vgpu_primary_plane_format *plane)
{
	u32 val, fmt;
	struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
	int pipe;

	pipe = get_active_pipe(vgpu);
	if (pipe >= I915_MAX_PIPES)
		return -ENODEV;

	val = vgpu_vreg_t(vgpu, DSPCNTR(pipe));
	plane->enabled = !!(val & DISPLAY_PLANE_ENABLE);
	if (!plane->enabled)
		return -ENODEV;

	if (IS_SKYLAKE(dev_priv)
		|| IS_KABYLAKE(dev_priv)
		|| IS_BROXTON(dev_priv)) {
		plane->tiled = val & PLANE_CTL_TILED_MASK;
		fmt = skl_format_to_drm(
			val & PLANE_CTL_FORMAT_MASK,
			val & PLANE_CTL_ORDER_RGBX,
			val & PLANE_CTL_ALPHA_MASK,
			val & PLANE_CTL_YUV422_ORDER_MASK);

		if (fmt >= ARRAY_SIZE(skl_pixel_formats)) {
			gvt_vgpu_err("Out-of-bounds pixel format index\n");
			return -EINVAL;
		}

		plane->bpp = skl_pixel_formats[fmt].bpp;
		plane->drm_format = skl_pixel_formats[fmt].drm_format;
	} else {
		plane->tiled = val & DISPPLANE_TILED;
		fmt = bdw_format_to_drm(val & DISPPLANE_PIXFORMAT_MASK);
		plane->bpp = bdw_pixel_formats[fmt].bpp;
		plane->drm_format = bdw_pixel_formats[fmt].drm_format;
	}

	if (!plane->bpp) {
		gvt_vgpu_err("Non-supported pixel format (0x%x)\n", fmt);
		return -EINVAL;
	}

	plane->hw_format = fmt;

	plane->base = vgpu_vreg_t(vgpu, DSPSURF(pipe)) & I915_GTT_PAGE_MASK;
	if (!intel_gvt_ggtt_validate_range(vgpu, plane->base, 0))
		return  -EINVAL;

	plane->base_gpa = intel_vgpu_gma_to_gpa(vgpu->gtt.ggtt_mm, plane->base);
	if (plane->base_gpa == INTEL_GVT_INVALID_ADDR) {
		gvt_vgpu_err("Translate primary plane gma 0x%x to gpa fail\n",
				plane->base);
		return  -EINVAL;
	}

	plane->stride = intel_vgpu_get_stride(vgpu, pipe, plane->tiled,
		(IS_SKYLAKE(dev_priv)
		|| IS_KABYLAKE(dev_priv)
		|| IS_BROXTON(dev_priv)) ?
			(_PRI_PLANE_STRIDE_MASK >> 6) :
				_PRI_PLANE_STRIDE_MASK, plane->bpp);

	plane->width = (vgpu_vreg_t(vgpu, PIPESRC(pipe)) & _PIPE_H_SRCSZ_MASK) >>
		_PIPE_H_SRCSZ_SHIFT;
	plane->width += 1;
	plane->height = (vgpu_vreg_t(vgpu, PIPESRC(pipe)) &
			_PIPE_V_SRCSZ_MASK) >> _PIPE_V_SRCSZ_SHIFT;
	plane->height += 1;	/* raw height is one minus the real value */

	val = vgpu_vreg_t(vgpu, DSPTILEOFF(pipe));
	plane->x_offset = (val & _PRI_PLANE_X_OFF_MASK) >>
		_PRI_PLANE_X_OFF_SHIFT;
	plane->y_offset = (val & _PRI_PLANE_Y_OFF_MASK) >>
		_PRI_PLANE_Y_OFF_SHIFT;

	return 0;
}

__attribute__((used)) static int cursor_mode_to_drm(int mode)
{
	int cursor_pixel_formats_index = 4;

	switch (mode) {
	case MCURSOR_MODE_128_ARGB_AX:
		cursor_pixel_formats_index = 0;
		break;
	case MCURSOR_MODE_256_ARGB_AX:
		cursor_pixel_formats_index = 1;
		break;
	case MCURSOR_MODE_64_ARGB_AX:
		cursor_pixel_formats_index = 2;
		break;
	case MCURSOR_MODE_64_32B_AX:
		cursor_pixel_formats_index = 3;
		break;

	default:
		break;
	}

	return cursor_pixel_formats_index;
}

int intel_vgpu_decode_cursor_plane(struct intel_vgpu *vgpu,
	struct intel_vgpu_cursor_plane_format *plane)
{
	u32 val, mode, index;
	u32 alpha_plane, alpha_force;
	struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
	int pipe;

	pipe = get_active_pipe(vgpu);
	if (pipe >= I915_MAX_PIPES)
		return -ENODEV;

	val = vgpu_vreg_t(vgpu, CURCNTR(pipe));
	mode = val & MCURSOR_MODE;
	plane->enabled = (mode != MCURSOR_MODE_DISABLE);
	if (!plane->enabled)
		return -ENODEV;

	index = cursor_mode_to_drm(mode);

	if (!cursor_pixel_formats[index].bpp) {
		gvt_vgpu_err("Non-supported cursor mode (0x%x)\n", mode);
		return -EINVAL;
	}
	plane->mode = mode;
	plane->bpp = cursor_pixel_formats[index].bpp;
	plane->drm_format = cursor_pixel_formats[index].drm_format;
	plane->width = cursor_pixel_formats[index].width;
	plane->height = cursor_pixel_formats[index].height;

	alpha_plane = (val & _CURSOR_ALPHA_PLANE_MASK) >>
				_CURSOR_ALPHA_PLANE_SHIFT;
	alpha_force = (val & _CURSOR_ALPHA_FORCE_MASK) >>
				_CURSOR_ALPHA_FORCE_SHIFT;
	if (alpha_plane || alpha_force)
		gvt_dbg_core("alpha_plane=0x%x, alpha_force=0x%x\n",
			alpha_plane, alpha_force);

	plane->base = vgpu_vreg_t(vgpu, CURBASE(pipe)) & I915_GTT_PAGE_MASK;
	if (!intel_gvt_ggtt_validate_range(vgpu, plane->base, 0))
		return  -EINVAL;

	plane->base_gpa = intel_vgpu_gma_to_gpa(vgpu->gtt.ggtt_mm, plane->base);
	if (plane->base_gpa == INTEL_GVT_INVALID_ADDR) {
		gvt_vgpu_err("Translate cursor plane gma 0x%x to gpa fail\n",
				plane->base);
		return  -EINVAL;
	}

	val = vgpu_vreg_t(vgpu, CURPOS(pipe));
	plane->x_pos = (val & _CURSOR_POS_X_MASK) >> _CURSOR_POS_X_SHIFT;
	plane->x_sign = (val & _CURSOR_SIGN_X_MASK) >> _CURSOR_SIGN_X_SHIFT;
	plane->y_pos = (val & _CURSOR_POS_Y_MASK) >> _CURSOR_POS_Y_SHIFT;
	plane->y_sign = (val & _CURSOR_SIGN_Y_MASK) >> _CURSOR_SIGN_Y_SHIFT;

	plane->x_hot = vgpu_vreg_t(vgpu, vgtif_reg(cursor_x_hot));
	plane->y_hot = vgpu_vreg_t(vgpu, vgtif_reg(cursor_y_hot));
	return 0;
}

int intel_vgpu_decode_sprite_plane(struct intel_vgpu *vgpu,
	struct intel_vgpu_sprite_plane_format *plane)
{
	u32 val, fmt;
	u32 color_order, yuv_order;
	int drm_format;
	int pipe;

	pipe = get_active_pipe(vgpu);
	if (pipe >= I915_MAX_PIPES)
		return -ENODEV;

	val = vgpu_vreg_t(vgpu, SPRCTL(pipe));
	plane->enabled = !!(val & SPRITE_ENABLE);
	if (!plane->enabled)
		return -ENODEV;

	plane->tiled = !!(val & SPRITE_TILED);
	color_order = !!(val & SPRITE_RGB_ORDER_RGBX);
	yuv_order = (val & SPRITE_YUV_BYTE_ORDER_MASK) >>
				_SPRITE_YUV_ORDER_SHIFT;

	fmt = (val & SPRITE_PIXFORMAT_MASK) >> _SPRITE_FMT_SHIFT;
	if (!sprite_pixel_formats[fmt].bpp) {
		gvt_vgpu_err("Non-supported pixel format (0x%x)\n", fmt);
		return -EINVAL;
	}
	plane->hw_format = fmt;
	plane->bpp = sprite_pixel_formats[fmt].bpp;
	drm_format = sprite_pixel_formats[fmt].drm_format;

	/* Order of RGB values in an RGBxxx buffer may be ordered RGB or
	 * BGR depending on the state of the color_order field
	 */
	if (!color_order) {
		if (drm_format == DRM_FORMAT_XRGB2101010)
			drm_format = DRM_FORMAT_XBGR2101010;
		else if (drm_format == DRM_FORMAT_XRGB8888)
			drm_format = DRM_FORMAT_XBGR8888;
	}

	if (drm_format == DRM_FORMAT_YUV422) {
		switch (yuv_order) {
		case 0:
			drm_format = DRM_FORMAT_YUYV;
			break;
		case 1:
			drm_format = DRM_FORMAT_UYVY;
			break;
		case 2:
			drm_format = DRM_FORMAT_YVYU;
			break;
		case 3:
			drm_format = DRM_FORMAT_VYUY;
			break;
		default:
			/* yuv_order has only 2 bits */
			break;
		}
	}

	plane->drm_format = drm_format;

	plane->base = vgpu_vreg_t(vgpu, SPRSURF(pipe)) & I915_GTT_PAGE_MASK;
	if (!intel_gvt_ggtt_validate_range(vgpu, plane->base, 0))
		return  -EINVAL;

	plane->base_gpa = intel_vgpu_gma_to_gpa(vgpu->gtt.ggtt_mm, plane->base);
	if (plane->base_gpa == INTEL_GVT_INVALID_ADDR) {
		gvt_vgpu_err("Translate sprite plane gma 0x%x to gpa fail\n",
				plane->base);
		return  -EINVAL;
	}

	plane->stride = vgpu_vreg_t(vgpu, SPRSTRIDE(pipe)) &
				_SPRITE_STRIDE_MASK;

	val = vgpu_vreg_t(vgpu, SPRSIZE(pipe));
	plane->height = (val & _SPRITE_SIZE_HEIGHT_MASK) >>
		_SPRITE_SIZE_HEIGHT_SHIFT;
	plane->width = (val & _SPRITE_SIZE_WIDTH_MASK) >>
		_SPRITE_SIZE_WIDTH_SHIFT;
	plane->height += 1;	/* raw height is one minus the real value */
	plane->width += 1;	/* raw width is one minus the real value */

	val = vgpu_vreg_t(vgpu, SPRPOS(pipe));
	plane->x_pos = (val & _SPRITE_POS_X_MASK) >> _SPRITE_POS_X_SHIFT;
	plane->y_pos = (val & _SPRITE_POS_Y_MASK) >> _SPRITE_POS_Y_SHIFT;

	val = vgpu_vreg_t(vgpu, SPROFFSET(pipe));
	plane->x_offset = (val & _SPRITE_OFFSET_START_X_MASK) >>
			   _SPRITE_OFFSET_START_X_SHIFT;
	plane->y_offset = (val & _SPRITE_OFFSET_START_Y_MASK) >>
			   _SPRITE_OFFSET_START_Y_SHIFT;

	return 0;
}

