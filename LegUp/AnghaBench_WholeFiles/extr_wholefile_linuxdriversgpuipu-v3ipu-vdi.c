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
typedef  int v4l2_std_id ;
typedef  int u32 ;
struct ipu_vdi {unsigned int base; int module; struct ipu_soc* ipu; int /*<<< orphan*/  lock; scalar_t__ use_count; } ;
struct ipu_soc {unsigned int idmac_reg; struct ipu_vdi* vdi_priv; } ;
struct device {int dummy; } ;
typedef  enum ipu_motion_sel { ____Placeholder_ipu_motion_sel } ipu_motion_sel ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  HIGH_MOTION 135 
 int MEDIA_BUS_FMT_UYVY8_1X16 ; 
 int MEDIA_BUS_FMT_UYVY8_2X8 ; 
 int MEDIA_BUS_FMT_YUYV8_1X16 ; 
 int MEDIA_BUS_FMT_YUYV8_2X8 ; 
#define  MED_MOTION 134 
 int /*<<< orphan*/  PAGE_SIZE ; 
#define  V4L2_FIELD_BOTTOM 133 
#define  V4L2_FIELD_INTERLACED_BT 132 
#define  V4L2_FIELD_INTERLACED_TB 131 
#define  V4L2_FIELD_SEQ_BT 130 
#define  V4L2_FIELD_SEQ_TB 129 
#define  V4L2_FIELD_TOP 128 
 int V4L2_STD_525_60 ; 
 unsigned int VDI_C ; 
 int VDI_C_BURST_SIZE1_4 ; 
 int VDI_C_BURST_SIZE2_4 ; 
 int VDI_C_BURST_SIZE3_4 ; 
 int VDI_C_CH_420 ; 
 int VDI_C_CH_422 ; 
 int VDI_C_MOT_SEL_FULL ; 
 int VDI_C_MOT_SEL_LOW ; 
 int VDI_C_MOT_SEL_MASK ; 
 int VDI_C_MOT_SEL_MED ; 
 int VDI_C_TOP_FIELD_AUTO_1 ; 
 int VDI_C_TOP_FIELD_MAN_1 ; 
 int VDI_C_VWM1_CLR_2 ; 
 int VDI_C_VWM3_CLR_2 ; 
 unsigned int VDI_FSIZE ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned long,unsigned int) ; 
 unsigned int devm_ioremap (struct device*,unsigned long,int /*<<< orphan*/ ) ; 
 struct ipu_vdi* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipu_module_disable (struct ipu_soc*,int) ; 
 int /*<<< orphan*/  ipu_module_enable (struct ipu_soc*,int) ; 
 int readl (unsigned int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel (int,unsigned int) ; 

__attribute__((used)) static inline u32 ipu_idmac_read(struct ipu_soc *ipu, unsigned offset)
{
	return readl(ipu->idmac_reg + offset);
}

__attribute__((used)) static inline void ipu_idmac_write(struct ipu_soc *ipu, u32 value,
				   unsigned offset)
{
	writel(value, ipu->idmac_reg + offset);
}

__attribute__((used)) static inline u32 ipu_vdi_read(struct ipu_vdi *vdi, unsigned int offset)
{
	return readl(vdi->base + offset);
}

__attribute__((used)) static inline void ipu_vdi_write(struct ipu_vdi *vdi, u32 value,
				 unsigned int offset)
{
	writel(value, vdi->base + offset);
}

void ipu_vdi_set_field_order(struct ipu_vdi *vdi, v4l2_std_id std, u32 field)
{
	bool top_field_0 = false;
	unsigned long flags;
	u32 reg;

	switch (field) {
	case V4L2_FIELD_INTERLACED_TB:
	case V4L2_FIELD_SEQ_TB:
	case V4L2_FIELD_TOP:
		top_field_0 = true;
		break;
	case V4L2_FIELD_INTERLACED_BT:
	case V4L2_FIELD_SEQ_BT:
	case V4L2_FIELD_BOTTOM:
		top_field_0 = false;
		break;
	default:
		top_field_0 = (std & V4L2_STD_525_60) ? true : false;
		break;
	}

	spin_lock_irqsave(&vdi->lock, flags);

	reg = ipu_vdi_read(vdi, VDI_C);
	if (top_field_0)
		reg &= ~(VDI_C_TOP_FIELD_MAN_1 | VDI_C_TOP_FIELD_AUTO_1);
	else
		reg |= VDI_C_TOP_FIELD_MAN_1 | VDI_C_TOP_FIELD_AUTO_1;
	ipu_vdi_write(vdi, reg, VDI_C);

	spin_unlock_irqrestore(&vdi->lock, flags);
}

void ipu_vdi_set_motion(struct ipu_vdi *vdi, enum ipu_motion_sel motion_sel)
{
	unsigned long flags;
	u32 reg;

	spin_lock_irqsave(&vdi->lock, flags);

	reg = ipu_vdi_read(vdi, VDI_C);

	reg &= ~VDI_C_MOT_SEL_MASK;

	switch (motion_sel) {
	case MED_MOTION:
		reg |= VDI_C_MOT_SEL_MED;
		break;
	case HIGH_MOTION:
		reg |= VDI_C_MOT_SEL_FULL;
		break;
	default:
		reg |= VDI_C_MOT_SEL_LOW;
		break;
	}

	ipu_vdi_write(vdi, reg, VDI_C);

	spin_unlock_irqrestore(&vdi->lock, flags);
}

void ipu_vdi_setup(struct ipu_vdi *vdi, u32 code, int xres, int yres)
{
	unsigned long flags;
	u32 pixel_fmt, reg;

	spin_lock_irqsave(&vdi->lock, flags);

	reg = ((yres - 1) << 16) | (xres - 1);
	ipu_vdi_write(vdi, reg, VDI_FSIZE);

	/*
	 * Full motion, only vertical filter is used.
	 * Burst size is 4 accesses
	 */
	if (code == MEDIA_BUS_FMT_UYVY8_2X8 ||
	    code == MEDIA_BUS_FMT_UYVY8_1X16 ||
	    code == MEDIA_BUS_FMT_YUYV8_2X8 ||
	    code == MEDIA_BUS_FMT_YUYV8_1X16)
		pixel_fmt = VDI_C_CH_422;
	else
		pixel_fmt = VDI_C_CH_420;

	reg = ipu_vdi_read(vdi, VDI_C);
	reg |= pixel_fmt;
	reg |= VDI_C_BURST_SIZE2_4;
	reg |= VDI_C_BURST_SIZE1_4 | VDI_C_VWM1_CLR_2;
	reg |= VDI_C_BURST_SIZE3_4 | VDI_C_VWM3_CLR_2;
	ipu_vdi_write(vdi, reg, VDI_C);

	spin_unlock_irqrestore(&vdi->lock, flags);
}

void ipu_vdi_unsetup(struct ipu_vdi *vdi)
{
	unsigned long flags;

	spin_lock_irqsave(&vdi->lock, flags);
	ipu_vdi_write(vdi, 0, VDI_FSIZE);
	ipu_vdi_write(vdi, 0, VDI_C);
	spin_unlock_irqrestore(&vdi->lock, flags);
}

int ipu_vdi_enable(struct ipu_vdi *vdi)
{
	unsigned long flags;

	spin_lock_irqsave(&vdi->lock, flags);

	if (!vdi->use_count)
		ipu_module_enable(vdi->ipu, vdi->module);

	vdi->use_count++;

	spin_unlock_irqrestore(&vdi->lock, flags);

	return 0;
}

int ipu_vdi_disable(struct ipu_vdi *vdi)
{
	unsigned long flags;

	spin_lock_irqsave(&vdi->lock, flags);

	if (vdi->use_count) {
		if (!--vdi->use_count)
			ipu_module_disable(vdi->ipu, vdi->module);
	}

	spin_unlock_irqrestore(&vdi->lock, flags);

	return 0;
}

struct ipu_vdi *ipu_vdi_get(struct ipu_soc *ipu)
{
	return ipu->vdi_priv;
}

void ipu_vdi_put(struct ipu_vdi *vdi)
{
}

int ipu_vdi_init(struct ipu_soc *ipu, struct device *dev,
		 unsigned long base, u32 module)
{
	struct ipu_vdi *vdi;

	vdi = devm_kzalloc(dev, sizeof(*vdi), GFP_KERNEL);
	if (!vdi)
		return -ENOMEM;

	ipu->vdi_priv = vdi;

	spin_lock_init(&vdi->lock);
	vdi->module = module;
	vdi->base = devm_ioremap(dev, base, PAGE_SIZE);
	if (!vdi->base)
		return -ENOMEM;

	dev_dbg(dev, "VDI base: 0x%08lx remapped to %p\n", base, vdi->base);
	vdi->ipu = ipu;

	return 0;
}

void ipu_vdi_exit(struct ipu_soc *ipu)
{
}

