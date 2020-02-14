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
typedef  unsigned int uint32_t ;
typedef  int uint16_t ;
typedef  int uint ;
typedef  unsigned int u32 ;
struct TYPE_10__ {struct drm_device* dev; } ;
struct psb_framebuffer {TYPE_4__ base; } ;
struct TYPE_8__ {struct drm_framebuffer* fb; } ;
struct psb_fbdev {struct psb_framebuffer pfb; TYPE_2__ psb_fb_helper; } ;
struct pci_dev {int dummy; } ;
struct gma_encoder {int dummy; } ;
struct fb_info {scalar_t__ state; int flags; struct psb_fbdev* par; } ;
struct fb_copyarea {int sx; int sy; int dx; int dy; int width; int height; } ;
struct TYPE_7__ {unsigned int gatt_start; } ;
struct drm_psb_private {unsigned int vdc_reg; unsigned int aux_reg; int /*<<< orphan*/  lock_2d; TYPE_1__ gtt; } ;
struct drm_framebuffer {unsigned int* pitches; TYPE_3__* format; int /*<<< orphan*/ * obj; } ;
struct drm_display_mode {int clock; int private_flags; } ;
struct drm_device {struct drm_psb_private* dev_private; } ;
struct drm_connector {int dummy; } ;
struct TYPE_12__ {struct gma_encoder* encoder; } ;
struct TYPE_11__ {unsigned int offset; } ;
struct TYPE_9__ {int depth; } ;

/* Variables and functions */
 int EBUSY ; 
 int EIO ; 
 int FBINFO_HWACCEL_DISABLED ; 
 scalar_t__ FBINFO_STATE_RUNNING ; 
 unsigned long HZ ; 
 int INTEL_MODE_PIXEL_MULTIPLIER_MASK ; 
 int INTEL_MODE_PIXEL_MULTIPLIER_SHIFT ; 
 unsigned int PSB_2D_BLIT_BH ; 
 unsigned int PSB_2D_COPYORDER_BL2TR ; 
 unsigned int PSB_2D_COPYORDER_BR2TL ; 
 unsigned int PSB_2D_COPYORDER_TL2BR ; 
 unsigned int PSB_2D_COPYORDER_TR2BL ; 
 unsigned int PSB_2D_DSTCK_DISABLE ; 
 unsigned int PSB_2D_DST_332RGB ; 
 unsigned int PSB_2D_DST_555RGB ; 
 unsigned int PSB_2D_DST_565RGB ; 
 unsigned int PSB_2D_DST_8888ARGB ; 
 unsigned int PSB_2D_DST_STRIDE_SHIFT ; 
 unsigned int PSB_2D_DST_SURF_BH ; 
 int PSB_2D_DST_XSIZE_SHIFT ; 
 int PSB_2D_DST_XSTART_SHIFT ; 
 int PSB_2D_DST_YSIZE_SHIFT ; 
 int PSB_2D_DST_YSTART_SHIFT ; 
 int /*<<< orphan*/  PSB_2D_FENCE_BH ; 
 int /*<<< orphan*/  PSB_2D_FLUSH_BH ; 
 unsigned int PSB_2D_ROP3_SRCCOPY ; 
 unsigned int PSB_2D_ROT_NONE ; 
 unsigned int PSB_2D_SRCCK_DISABLE ; 
 int PSB_2D_SRCOFF_XSTART_SHIFT ; 
 int PSB_2D_SRCOFF_YSTART_SHIFT ; 
 unsigned int PSB_2D_SRC_332RGB ; 
 unsigned int PSB_2D_SRC_555RGB ; 
 unsigned int PSB_2D_SRC_565RGB ; 
 unsigned int PSB_2D_SRC_8888ARGB ; 
 int PSB_2D_SRC_OFF_BH ; 
 unsigned int PSB_2D_SRC_STRIDE_SHIFT ; 
 unsigned int PSB_2D_SRC_SURF_BH ; 
 unsigned int PSB_2D_USE_PAT ; 
 scalar_t__ PSB_CR_2D_BLIT_STATUS ; 
 scalar_t__ PSB_CR_2D_SOCIF ; 
 scalar_t__ PSB_CR_BIF_CTRL ; 
 scalar_t__ PSB_CR_BIF_TWOD_REQ_BASE ; 
 scalar_t__ PSB_CR_SOFT_RESET ; 
 unsigned int PSB_RSGX32 (scalar_t__) ; 
 scalar_t__ PSB_SGX_2D_SLAVE_PORT ; 
 int /*<<< orphan*/  PSB_WSGX32 (unsigned int,scalar_t__) ; 
 unsigned int REG_READ (unsigned int) ; 
 unsigned int REG_READ_AUX (unsigned int) ; 
 int /*<<< orphan*/  REG_WRITE (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  REG_WRITE_AUX (unsigned int,unsigned int) ; 
 unsigned int _PSB_C2B_STATUS_BUSY ; 
 unsigned int _PSB_C2_SOCIF_EMPTY ; 
 unsigned int _PSB_CB_CTRL_CLEAR_FAULT ; 
 unsigned int _PSB_CS_RESET_BIF_RESET ; 
 unsigned int _PSB_CS_RESET_DPM_RESET ; 
 unsigned int _PSB_CS_RESET_ISP_RESET ; 
 unsigned int _PSB_CS_RESET_TA_RESET ; 
 unsigned int _PSB_CS_RESET_TSP_RESET ; 
 unsigned int _PSB_CS_RESET_TWOD_RESET ; 
 unsigned int _PSB_CS_RESET_USE_RESET ; 
 int /*<<< orphan*/  cpu_relax () ; 
 void drm_fb_helper_cfb_copyarea (struct fb_info*,struct fb_copyarea const*) ; 
 int /*<<< orphan*/  gma_power_begin (struct drm_device*,int) ; 
 int /*<<< orphan*/  gma_power_end (struct drm_device*) ; 
 unsigned int ioread32 (unsigned int) ; 
 int /*<<< orphan*/  iowrite16 (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  iowrite8 (unsigned int,unsigned int) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  pci_dev_put (struct pci_dev*) ; 
 struct pci_dev* pci_get_domain_bus_and_slot (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int,unsigned int*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  time_after_eq (unsigned long,unsigned long) ; 
 TYPE_6__* to_gma_connector (struct drm_connector*) ; 
 TYPE_5__* to_gtt_range (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static inline void
psb_intel_mode_set_pixel_multiplier(struct drm_display_mode *mode,
				int multiplier)
{
	mode->clock *= multiplier;
	mode->private_flags |= multiplier;
}

__attribute__((used)) static inline int
psb_intel_mode_get_pixel_multiplier(const struct drm_display_mode *mode)
{
	return (mode->private_flags & INTEL_MODE_PIXEL_MULTIPLIER_MASK)
	       >> INTEL_MODE_PIXEL_MULTIPLIER_SHIFT;
}

__attribute__((used)) static inline struct gma_encoder *gma_attached_encoder(
						struct drm_connector *connector)
{
	return to_gma_connector(connector)->encoder;
}

extern inline void psb_intel_opregion_asle_intr(struct drm_device *dev)
{
}

extern inline void psb_intel_opregion_init(struct drm_device *dev)
{
}

extern inline void psb_intel_opregion_fini(struct drm_device *dev)
{
}

extern inline int psb_intel_opregion_setup(struct drm_device *dev)
{
	return 0;
}

extern inline void psb_intel_opregion_enable_asle(struct drm_device *dev)
{
}

__attribute__((used)) static inline struct drm_psb_private *psb_priv(struct drm_device *dev)
{
	return (struct drm_psb_private *) dev->dev_private;
}

__attribute__((used)) static inline u32 MRST_MSG_READ32(int domain, uint port, uint offset)
{
	int mcr = (0xD0<<24) | (port << 16) | (offset << 8);
	uint32_t ret_val = 0;
	struct pci_dev *pci_root = pci_get_domain_bus_and_slot(domain, 0, 0);
	pci_write_config_dword(pci_root, 0xD0, mcr);
	pci_read_config_dword(pci_root, 0xD4, &ret_val);
	pci_dev_put(pci_root);
	return ret_val;
}

__attribute__((used)) static inline void MRST_MSG_WRITE32(int domain, uint port, uint offset,
				    u32 value)
{
	int mcr = (0xE0<<24) | (port << 16) | (offset << 8) | 0xF0;
	struct pci_dev *pci_root = pci_get_domain_bus_and_slot(domain, 0, 0);
	pci_write_config_dword(pci_root, 0xD4, value);
	pci_write_config_dword(pci_root, 0xD0, mcr);
	pci_dev_put(pci_root);
}

__attribute__((used)) static inline u32 MDFLD_MSG_READ32(int domain, uint port, uint offset)
{
	int mcr = (0x10<<24) | (port << 16) | (offset << 8);
	uint32_t ret_val = 0;
	struct pci_dev *pci_root = pci_get_domain_bus_and_slot(domain, 0, 0);
	pci_write_config_dword(pci_root, 0xD0, mcr);
	pci_read_config_dword(pci_root, 0xD4, &ret_val);
	pci_dev_put(pci_root);
	return ret_val;
}

__attribute__((used)) static inline void MDFLD_MSG_WRITE32(int domain, uint port, uint offset,
				     u32 value)
{
	int mcr = (0x11<<24) | (port << 16) | (offset << 8) | 0xF0;
	struct pci_dev *pci_root = pci_get_domain_bus_and_slot(domain, 0, 0);
	pci_write_config_dword(pci_root, 0xD4, value);
	pci_write_config_dword(pci_root, 0xD0, mcr);
	pci_dev_put(pci_root);
}

__attribute__((used)) static inline uint32_t REGISTER_READ(struct drm_device *dev, uint32_t reg)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	return ioread32(dev_priv->vdc_reg + reg);
}

__attribute__((used)) static inline uint32_t REGISTER_READ_AUX(struct drm_device *dev, uint32_t reg)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	return ioread32(dev_priv->aux_reg + reg);
}

__attribute__((used)) static inline uint32_t REGISTER_READ_WITH_AUX(struct drm_device *dev,
					      uint32_t reg, int aux)
{
	uint32_t val;

	if (aux)
		val = REG_READ_AUX(reg);
	else
		val = REG_READ(reg);

	return val;
}

__attribute__((used)) static inline void REGISTER_WRITE(struct drm_device *dev, uint32_t reg,
				  uint32_t val)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	iowrite32((val), dev_priv->vdc_reg + (reg));
}

__attribute__((used)) static inline void REGISTER_WRITE_AUX(struct drm_device *dev, uint32_t reg,
				      uint32_t val)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	iowrite32((val), dev_priv->aux_reg + (reg));
}

__attribute__((used)) static inline void REGISTER_WRITE_WITH_AUX(struct drm_device *dev, uint32_t reg,
				      uint32_t val, int aux)
{
	if (aux)
		REG_WRITE_AUX(reg, val);
	else
		REG_WRITE(reg, val);
}

__attribute__((used)) static inline void REGISTER_WRITE16(struct drm_device *dev,
					uint32_t reg, uint32_t val)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	iowrite16((val), dev_priv->vdc_reg + (reg));
}

__attribute__((used)) static inline void REGISTER_WRITE8(struct drm_device *dev,
				       uint32_t reg, uint32_t val)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	iowrite8((val), dev_priv->vdc_reg + (reg));
}

void psb_spank(struct drm_psb_private *dev_priv)
{
	PSB_WSGX32(_PSB_CS_RESET_BIF_RESET | _PSB_CS_RESET_DPM_RESET |
		_PSB_CS_RESET_TA_RESET | _PSB_CS_RESET_USE_RESET |
		_PSB_CS_RESET_ISP_RESET | _PSB_CS_RESET_TSP_RESET |
		_PSB_CS_RESET_TWOD_RESET, PSB_CR_SOFT_RESET);
	PSB_RSGX32(PSB_CR_SOFT_RESET);

	msleep(1);

	PSB_WSGX32(0, PSB_CR_SOFT_RESET);
	wmb();
	PSB_WSGX32(PSB_RSGX32(PSB_CR_BIF_CTRL) | _PSB_CB_CTRL_CLEAR_FAULT,
		   PSB_CR_BIF_CTRL);
	wmb();
	(void) PSB_RSGX32(PSB_CR_BIF_CTRL);

	msleep(1);
	PSB_WSGX32(PSB_RSGX32(PSB_CR_BIF_CTRL) & ~_PSB_CB_CTRL_CLEAR_FAULT,
		   PSB_CR_BIF_CTRL);
	(void) PSB_RSGX32(PSB_CR_BIF_CTRL);
	PSB_WSGX32(dev_priv->gtt.gatt_start, PSB_CR_BIF_TWOD_REQ_BASE);
}

__attribute__((used)) static int psb_2d_wait_available(struct drm_psb_private *dev_priv,
			  unsigned size)
{
	uint32_t avail = PSB_RSGX32(PSB_CR_2D_SOCIF);
	unsigned long t = jiffies + HZ;

	while (avail < size) {
		avail = PSB_RSGX32(PSB_CR_2D_SOCIF);
		if (time_after(jiffies, t)) {
			psb_spank(dev_priv);
			return -EIO;
		}
	}
	return 0;
}

__attribute__((used)) static int psbfb_2d_submit(struct drm_psb_private *dev_priv, uint32_t *cmdbuf,
								unsigned size)
{
	int ret = 0;
	int i;
	unsigned submit_size;
	unsigned long flags;

	spin_lock_irqsave(&dev_priv->lock_2d, flags);
	while (size > 0) {
		submit_size = (size < 0x60) ? size : 0x60;
		size -= submit_size;
		ret = psb_2d_wait_available(dev_priv, submit_size);
		if (ret)
			break;

		submit_size <<= 2;

		for (i = 0; i < submit_size; i += 4)
			PSB_WSGX32(*cmdbuf++, PSB_SGX_2D_SLAVE_PORT + i);

		(void)PSB_RSGX32(PSB_SGX_2D_SLAVE_PORT + i - 4);
	}
	spin_unlock_irqrestore(&dev_priv->lock_2d, flags);
	return ret;
}

__attribute__((used)) static u32 psb_accel_2d_copy_direction(int xdir, int ydir)
{
	if (xdir < 0)
		return (ydir < 0) ? PSB_2D_COPYORDER_BR2TL :
						PSB_2D_COPYORDER_TR2BL;
	else
		return (ydir < 0) ? PSB_2D_COPYORDER_BL2TR :
						PSB_2D_COPYORDER_TL2BR;
}

__attribute__((used)) static int psb_accel_2d_copy(struct drm_psb_private *dev_priv,
			     uint32_t src_offset, uint32_t src_stride,
			     uint32_t src_format, uint32_t dst_offset,
			     uint32_t dst_stride, uint32_t dst_format,
			     uint16_t src_x, uint16_t src_y,
			     uint16_t dst_x, uint16_t dst_y,
			     uint16_t size_x, uint16_t size_y)
{
	uint32_t blit_cmd;
	uint32_t buffer[10];
	uint32_t *buf;
	uint32_t direction;

	buf = buffer;

	direction =
	    psb_accel_2d_copy_direction(src_x - dst_x, src_y - dst_y);

	if (direction == PSB_2D_COPYORDER_BR2TL ||
	    direction == PSB_2D_COPYORDER_TR2BL) {
		src_x += size_x - 1;
		dst_x += size_x - 1;
	}
	if (direction == PSB_2D_COPYORDER_BR2TL ||
	    direction == PSB_2D_COPYORDER_BL2TR) {
		src_y += size_y - 1;
		dst_y += size_y - 1;
	}

	blit_cmd =
	    PSB_2D_BLIT_BH |
	    PSB_2D_ROT_NONE |
	    PSB_2D_DSTCK_DISABLE |
	    PSB_2D_SRCCK_DISABLE |
	    PSB_2D_USE_PAT | PSB_2D_ROP3_SRCCOPY | direction;

	*buf++ = PSB_2D_FENCE_BH;
	*buf++ =
	    PSB_2D_DST_SURF_BH | dst_format | (dst_stride <<
					       PSB_2D_DST_STRIDE_SHIFT);
	*buf++ = dst_offset;
	*buf++ =
	    PSB_2D_SRC_SURF_BH | src_format | (src_stride <<
					       PSB_2D_SRC_STRIDE_SHIFT);
	*buf++ = src_offset;
	*buf++ =
	    PSB_2D_SRC_OFF_BH | (src_x << PSB_2D_SRCOFF_XSTART_SHIFT) |
	    (src_y << PSB_2D_SRCOFF_YSTART_SHIFT);
	*buf++ = blit_cmd;
	*buf++ =
	    (dst_x << PSB_2D_DST_XSTART_SHIFT) | (dst_y <<
						  PSB_2D_DST_YSTART_SHIFT);
	*buf++ =
	    (size_x << PSB_2D_DST_XSIZE_SHIFT) | (size_y <<
						  PSB_2D_DST_YSIZE_SHIFT);
	*buf++ = PSB_2D_FLUSH_BH;

	return psbfb_2d_submit(dev_priv, buffer, buf - buffer);
}

__attribute__((used)) static void psbfb_copyarea_accel(struct fb_info *info,
				 const struct fb_copyarea *a)
{
	struct psb_fbdev *fbdev = info->par;
	struct psb_framebuffer *psbfb = &fbdev->pfb;
	struct drm_device *dev = psbfb->base.dev;
	struct drm_framebuffer *fb = fbdev->psb_fb_helper.fb;
	struct drm_psb_private *dev_priv = dev->dev_private;
	uint32_t offset;
	uint32_t stride;
	uint32_t src_format;
	uint32_t dst_format;

	if (!fb)
		return;

	offset = to_gtt_range(fb->obj[0])->offset;
	stride = fb->pitches[0];

	switch (fb->format->depth) {
	case 8:
		src_format = PSB_2D_SRC_332RGB;
		dst_format = PSB_2D_DST_332RGB;
		break;
	case 15:
		src_format = PSB_2D_SRC_555RGB;
		dst_format = PSB_2D_DST_555RGB;
		break;
	case 16:
		src_format = PSB_2D_SRC_565RGB;
		dst_format = PSB_2D_DST_565RGB;
		break;
	case 24:
	case 32:
		/* this is wrong but since we don't do blending its okay */
		src_format = PSB_2D_SRC_8888ARGB;
		dst_format = PSB_2D_DST_8888ARGB;
		break;
	default:
		/* software fallback */
		drm_fb_helper_cfb_copyarea(info, a);
		return;
	}

	if (!gma_power_begin(dev, false)) {
		drm_fb_helper_cfb_copyarea(info, a);
		return;
	}
	psb_accel_2d_copy(dev_priv,
			  offset, stride, src_format,
			  offset, stride, dst_format,
			  a->sx, a->sy, a->dx, a->dy, a->width, a->height);
	gma_power_end(dev);
}

void psbfb_copyarea(struct fb_info *info,
			   const struct fb_copyarea *region)
{
	if (unlikely(info->state != FBINFO_STATE_RUNNING))
		return;

	/* Avoid the 8 pixel erratum */
	if (region->width == 8 || region->height == 8 ||
		(info->flags & FBINFO_HWACCEL_DISABLED))
		return drm_fb_helper_cfb_copyarea(info, region);

	psbfb_copyarea_accel(info, region);
}

int psbfb_sync(struct fb_info *info)
{
	struct psb_fbdev *fbdev = info->par;
	struct psb_framebuffer *psbfb = &fbdev->pfb;
	struct drm_device *dev = psbfb->base.dev;
	struct drm_psb_private *dev_priv = dev->dev_private;
	unsigned long _end = jiffies + HZ;
	int busy = 0;
	unsigned long flags;

	spin_lock_irqsave(&dev_priv->lock_2d, flags);
	/*
	 * First idle the 2D engine.
	 */

	if ((PSB_RSGX32(PSB_CR_2D_SOCIF) == _PSB_C2_SOCIF_EMPTY) &&
	    ((PSB_RSGX32(PSB_CR_2D_BLIT_STATUS) & _PSB_C2B_STATUS_BUSY) == 0))
		goto out;

	do {
		busy = (PSB_RSGX32(PSB_CR_2D_SOCIF) != _PSB_C2_SOCIF_EMPTY);
		cpu_relax();
	} while (busy && !time_after_eq(jiffies, _end));

	if (busy)
		busy = (PSB_RSGX32(PSB_CR_2D_SOCIF) != _PSB_C2_SOCIF_EMPTY);
	if (busy)
		goto out;

	do {
		busy = ((PSB_RSGX32(PSB_CR_2D_BLIT_STATUS) &
						_PSB_C2B_STATUS_BUSY) != 0);
		cpu_relax();
	} while (busy && !time_after_eq(jiffies, _end));
	if (busy)
		busy = ((PSB_RSGX32(PSB_CR_2D_BLIT_STATUS) &
					_PSB_C2B_STATUS_BUSY) != 0);

out:
	spin_unlock_irqrestore(&dev_priv->lock_2d, flags);
	return (busy) ? -EBUSY : 0;
}

