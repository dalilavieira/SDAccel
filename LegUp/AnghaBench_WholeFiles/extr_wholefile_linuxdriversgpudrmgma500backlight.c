#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int uint ;
typedef  int u32 ;
struct pci_dev {int dummy; } ;
struct gma_encoder {int dummy; } ;
struct drm_psb_private {int vdc_reg; int aux_reg; } ;
struct drm_display_mode {int clock; int private_flags; } ;
struct drm_device {struct drm_psb_private* dev_private; } ;
struct drm_connector {int dummy; } ;
struct TYPE_2__ {struct gma_encoder* encoder; } ;

/* Variables and functions */
 int INTEL_MODE_PIXEL_MULTIPLIER_MASK ; 
 int INTEL_MODE_PIXEL_MULTIPLIER_SHIFT ; 
 int REG_READ (int) ; 
 int REG_READ_AUX (int) ; 
 int /*<<< orphan*/  REG_WRITE (int,int) ; 
 int /*<<< orphan*/  REG_WRITE_AUX (int,int) ; 
 int ioread32 (int) ; 
 int /*<<< orphan*/  iowrite16 (int,int) ; 
 int /*<<< orphan*/  iowrite32 (int,int) ; 
 int /*<<< orphan*/  iowrite8 (int,int) ; 
 int /*<<< orphan*/  pci_dev_put (struct pci_dev*) ; 
 struct pci_dev* pci_get_domain_bus_and_slot (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,int) ; 
 TYPE_1__* to_gma_connector (struct drm_connector*) ; 

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

void gma_backlight_enable(struct drm_device *dev)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
	struct drm_psb_private *dev_priv = dev->dev_private;
	dev_priv->backlight_enabled = true;
	if (dev_priv->backlight_device) {
		dev_priv->backlight_device->props.brightness = dev_priv->backlight_level;
		do_gma_backlight_set(dev);
	}
#endif	
}

void gma_backlight_disable(struct drm_device *dev)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
	struct drm_psb_private *dev_priv = dev->dev_private;
	dev_priv->backlight_enabled = false;
	if (dev_priv->backlight_device) {
		dev_priv->backlight_device->props.brightness = 0;
		do_gma_backlight_set(dev);
	}
#endif	
}

void gma_backlight_set(struct drm_device *dev, int v)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
	struct drm_psb_private *dev_priv = dev->dev_private;
	dev_priv->backlight_level = v;
	if (dev_priv->backlight_device && dev_priv->backlight_enabled) {
		dev_priv->backlight_device->props.brightness = v;
		do_gma_backlight_set(dev);
	}
#endif	
}

int gma_backlight_init(struct drm_device *dev)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
	struct drm_psb_private *dev_priv = dev->dev_private;
	dev_priv->backlight_enabled = true;
	return dev_priv->ops->backlight_init(dev);
#else
	return 0;
#endif
}

void gma_backlight_exit(struct drm_device *dev)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
	struct drm_psb_private *dev_priv = dev->dev_private;
	if (dev_priv->backlight_device) {
		dev_priv->backlight_device->props.brightness = 0;
		backlight_update_status(dev_priv->backlight_device);
		backlight_device_unregister(dev_priv->backlight_device);
	}
#endif
}

