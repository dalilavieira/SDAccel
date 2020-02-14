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
typedef  int uint32_t ;
typedef  int uint ;
typedef  int u32 ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct gma_encoder {int dummy; } ;
struct TYPE_5__ {int saveBSM; int saveVBT; } ;
struct drm_psb_private {int vdc_reg; int aux_reg; int apm_base; int apm_reg; int ospm_base; int display_power; scalar_t__ display_count; int suspended; int pge_ctl; int gmch_ctrl; int msi_addr; int msi_data; TYPE_2__ regs; TYPE_1__* ops; } ;
struct drm_display_mode {int clock; int private_flags; } ;
struct drm_device {struct drm_psb_private* dev_private; struct pci_dev* pdev; int /*<<< orphan*/  dev; } ;
struct drm_connector {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_6__ {struct gma_encoder* encoder; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* restore_regs ) (struct drm_device*) ;int /*<<< orphan*/  (* power_up ) (struct drm_device*) ;int /*<<< orphan*/  (* power_down ) (struct drm_device*) ;int /*<<< orphan*/  (* save_regs ) (struct drm_device*) ;int /*<<< orphan*/  (* init_pm ) (struct drm_device*) ;} ;

/* Variables and functions */
 int EBUSY ; 
 int INTEL_MODE_PIXEL_MULTIPLIER_MASK ; 
 int INTEL_MODE_PIXEL_MULTIPLIER_SHIFT ; 
 int /*<<< orphan*/  PCI_D0 ; 
 int /*<<< orphan*/  PCI_D3hot ; 
 int /*<<< orphan*/  PSB_GMCH_CTRL ; 
 int PSB_PCIx_MSI_ADDR_LOC ; 
 int PSB_PCIx_MSI_DATA_LOC ; 
 int /*<<< orphan*/  PSB_PGETBL_CTL ; 
 int /*<<< orphan*/  PSB_WVDC32 (int,int /*<<< orphan*/ ) ; 
 int REG_READ (int) ; 
 int REG_READ_AUX (int) ; 
 int /*<<< orphan*/  REG_WRITE (int,int) ; 
 int /*<<< orphan*/  REG_WRITE_AUX (int,int) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int _PSB_GMCH_ENABLED ; 
 int _PSB_PGETBL_ENABLED ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int ioread32 (int) ; 
 int /*<<< orphan*/  iowrite16 (int,int) ; 
 int /*<<< orphan*/  iowrite32 (int,int) ; 
 int /*<<< orphan*/  iowrite8 (int,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_dev_put (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 struct pci_dev* pci_get_domain_bus_and_slot (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct drm_device* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_restore_state (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_save_state (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_set_power_state (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_set_suspended (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  power_ctrl_lock ; 
 int /*<<< orphan*/  power_mutex ; 
 int /*<<< orphan*/  psb_gtt_restore (struct drm_device*) ; 
 int /*<<< orphan*/  psb_irq_postinstall (struct drm_device*) ; 
 int /*<<< orphan*/  psb_irq_preinstall (struct drm_device*) ; 
 int /*<<< orphan*/  psb_irq_uninstall (struct drm_device*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct drm_device*) ; 
 int /*<<< orphan*/  stub2 (struct drm_device*) ; 
 int /*<<< orphan*/  stub3 (struct drm_device*) ; 
 int /*<<< orphan*/  stub4 (struct drm_device*) ; 
 int /*<<< orphan*/  stub5 (struct drm_device*) ; 
 TYPE_3__* to_gma_connector (struct drm_connector*) ; 
 struct pci_dev* to_pci_dev (struct device*) ; 

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

void gma_power_init(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;

	/* FIXME: Move APM/OSPM base into relevant device code */
	dev_priv->apm_base = dev_priv->apm_reg & 0xffff;
	dev_priv->ospm_base &= 0xffff;

	dev_priv->display_power = true;	/* We start active */
	dev_priv->display_count = 0;	/* Currently no users */
	dev_priv->suspended = false;	/* And not suspended */
	spin_lock_init(&power_ctrl_lock);
	mutex_init(&power_mutex);

	if (dev_priv->ops->init_pm)
		dev_priv->ops->init_pm(dev);
}

void gma_power_uninit(struct drm_device *dev)
{
	pm_runtime_disable(&dev->pdev->dev);
	pm_runtime_set_suspended(&dev->pdev->dev);
}

__attribute__((used)) static void gma_suspend_display(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;

	if (dev_priv->suspended)
		return;
	dev_priv->ops->save_regs(dev);
	dev_priv->ops->power_down(dev);
	dev_priv->display_power = false;
}

__attribute__((used)) static void gma_resume_display(struct pci_dev *pdev)
{
	struct drm_device *dev = pci_get_drvdata(pdev);
	struct drm_psb_private *dev_priv = dev->dev_private;

	/* turn on the display power island */
	dev_priv->ops->power_up(dev);
	dev_priv->suspended = false;
	dev_priv->display_power = true;

	PSB_WVDC32(dev_priv->pge_ctl | _PSB_PGETBL_ENABLED, PSB_PGETBL_CTL);
	pci_write_config_word(pdev, PSB_GMCH_CTRL,
			dev_priv->gmch_ctrl | _PSB_GMCH_ENABLED);

	psb_gtt_restore(dev); /* Rebuild our GTT mappings */
	dev_priv->ops->restore_regs(dev);
}

__attribute__((used)) static void gma_suspend_pci(struct pci_dev *pdev)
{
	struct drm_device *dev = pci_get_drvdata(pdev);
	struct drm_psb_private *dev_priv = dev->dev_private;
	int bsm, vbt;

	if (dev_priv->suspended)
		return;

	pci_save_state(pdev);
	pci_read_config_dword(pdev, 0x5C, &bsm);
	dev_priv->regs.saveBSM = bsm;
	pci_read_config_dword(pdev, 0xFC, &vbt);
	dev_priv->regs.saveVBT = vbt;
	pci_read_config_dword(pdev, PSB_PCIx_MSI_ADDR_LOC, &dev_priv->msi_addr);
	pci_read_config_dword(pdev, PSB_PCIx_MSI_DATA_LOC, &dev_priv->msi_data);

	pci_disable_device(pdev);
	pci_set_power_state(pdev, PCI_D3hot);

	dev_priv->suspended = true;
}

__attribute__((used)) static bool gma_resume_pci(struct pci_dev *pdev)
{
	struct drm_device *dev = pci_get_drvdata(pdev);
	struct drm_psb_private *dev_priv = dev->dev_private;
	int ret;

	if (!dev_priv->suspended)
		return true;

	pci_set_power_state(pdev, PCI_D0);
	pci_restore_state(pdev);
	pci_write_config_dword(pdev, 0x5c, dev_priv->regs.saveBSM);
	pci_write_config_dword(pdev, 0xFC, dev_priv->regs.saveVBT);
	/* restoring MSI address and data in PCIx space */
	pci_write_config_dword(pdev, PSB_PCIx_MSI_ADDR_LOC, dev_priv->msi_addr);
	pci_write_config_dword(pdev, PSB_PCIx_MSI_DATA_LOC, dev_priv->msi_data);
	ret = pci_enable_device(pdev);

	if (ret != 0)
		dev_err(&pdev->dev, "pci_enable failed: %d\n", ret);
	else
		dev_priv->suspended = false;
	return !dev_priv->suspended;
}

int gma_power_suspend(struct device *_dev)
{
	struct pci_dev *pdev = to_pci_dev(_dev);
	struct drm_device *dev = pci_get_drvdata(pdev);
	struct drm_psb_private *dev_priv = dev->dev_private;

	mutex_lock(&power_mutex);
	if (!dev_priv->suspended) {
		if (dev_priv->display_count) {
			mutex_unlock(&power_mutex);
			dev_err(dev->dev, "GPU hardware busy, cannot suspend\n");
			return -EBUSY;
		}
		psb_irq_uninstall(dev);
		gma_suspend_display(dev);
		gma_suspend_pci(pdev);
	}
	mutex_unlock(&power_mutex);
	return 0;
}

int gma_power_resume(struct device *_dev)
{
	struct pci_dev *pdev = to_pci_dev(_dev);
	struct drm_device *dev = pci_get_drvdata(pdev);

	mutex_lock(&power_mutex);
	gma_resume_pci(pdev);
	gma_resume_display(pdev);
	psb_irq_preinstall(dev);
	psb_irq_postinstall(dev);
	mutex_unlock(&power_mutex);
	return 0;
}

bool gma_power_is_on(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	return dev_priv->display_power;
}

bool gma_power_begin(struct drm_device *dev, bool force_on)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	int ret;
	unsigned long flags;

	spin_lock_irqsave(&power_ctrl_lock, flags);
	/* Power already on ? */
	if (dev_priv->display_power) {
		dev_priv->display_count++;
		pm_runtime_get(&dev->pdev->dev);
		spin_unlock_irqrestore(&power_ctrl_lock, flags);
		return true;
	}
	if (force_on == false)
		goto out_false;

	/* Ok power up needed */
	ret = gma_resume_pci(dev->pdev);
	if (ret == 0) {
		psb_irq_preinstall(dev);
		psb_irq_postinstall(dev);
		pm_runtime_get(&dev->pdev->dev);
		dev_priv->display_count++;
		spin_unlock_irqrestore(&power_ctrl_lock, flags);
		return true;
	}
out_false:
	spin_unlock_irqrestore(&power_ctrl_lock, flags);
	return false;
}

void gma_power_end(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	unsigned long flags;
	spin_lock_irqsave(&power_ctrl_lock, flags);
	dev_priv->display_count--;
	WARN_ON(dev_priv->display_count < 0);
	spin_unlock_irqrestore(&power_ctrl_lock, flags);
	pm_runtime_put(&dev->pdev->dev);
}

int psb_runtime_suspend(struct device *dev)
{
	return gma_power_suspend(dev);
}

int psb_runtime_resume(struct device *dev)
{
	return gma_power_resume(dev);
}

int psb_runtime_idle(struct device *dev)
{
	struct drm_device *drmdev = pci_get_drvdata(to_pci_dev(dev));
	struct drm_psb_private *dev_priv = drmdev->dev_private;
	if (dev_priv->display_count)
		return 0;
	else
		return 1;
}

int gma_power_thaw(struct device *_dev)
{
	return gma_power_resume(_dev);
}

int gma_power_freeze(struct device *_dev)
{
	return gma_power_suspend(_dev);
}

int gma_power_restore(struct device *_dev)
{
	return gma_power_resume(_dev);
}

