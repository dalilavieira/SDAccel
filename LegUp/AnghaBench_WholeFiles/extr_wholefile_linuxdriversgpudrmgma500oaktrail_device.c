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
typedef  int uint32_t ;
typedef  int uint ;
typedef  int u32 ;
struct TYPE_3__ {int saveDSPARB; int saveDSPFW1; int saveDSPFW2; int saveDSPFW3; int saveDSPFW4; int saveDSPFW5; int saveDSPFW6; int saveCHICKENBIT; int saveBCLRPAT_A; int saveDSPACURSOR_CTRL; int saveDSPACURSOR_BASE; int saveDSPACURSOR_POS; int savePERF_MODE; int savePP_CONTROL; int savePFIT_PGM_RATIOS; int savePFIT_AUTO_RATIOS; int saveLVDS; int savePFIT_CONTROL; int savePP_ON_DELAYS; int savePP_OFF_DELAYS; int savePP_DIVISOR; int saveOV_OVADD; int saveOV_OGAMC0; int saveOV_OGAMC1; int saveOV_OGAMC2; int saveOV_OGAMC3; int saveOV_OGAMC4; int saveOV_OGAMC5; int saveHISTOGRAM_INT_CONTROL_REG; int saveHISTOGRAM_LOGIC_CONTROL_REG; int savePWM_CONTROL_LOGIC; } ;
struct psb_save_area {int saveBLC_PWM_CTL; int saveBLC_PWM_CTL2; TYPE_1__ psb; struct psb_pipe* pipe; } ;
struct psb_pipe {int conf; int src; int fp0; int fp1; int dpll; int htotal; int hblank; int hsync; int vtotal; int vblank; int vsync; int cntr; int stride; int surf; int linoff; int tileoff; int* palette; void* addr; } ;
struct pci_dev {int dummy; } ;
struct gma_encoder {int dummy; } ;
struct drm_psb_private {int vdc_reg; int aux_reg; int /*<<< orphan*/  has_gct; int /*<<< orphan*/  regmap; scalar_t__ ospm_base; scalar_t__ iLVDS_enable; scalar_t__ hdmi_priv; struct psb_save_area regs; int /*<<< orphan*/  mode_dev; } ;
struct drm_display_mode {int clock; int private_flags; } ;
struct drm_device {struct drm_psb_private* dev_private; int /*<<< orphan*/  dev; int /*<<< orphan*/  pdev; } ;
struct drm_connector {int dummy; } ;
struct TYPE_4__ {struct gma_encoder* encoder; } ;

/* Variables and functions */
 scalar_t__ BCLRPAT_A ; 
 scalar_t__ BLC_PWM_CTL ; 
 scalar_t__ BLC_PWM_CTL2 ; 
 scalar_t__ CURABASE ; 
 scalar_t__ CURACNTR ; 
 scalar_t__ CURAPOS ; 
 int /*<<< orphan*/  DRM_UDELAY (int) ; 
 scalar_t__ DSPABASE ; 
 scalar_t__ DSPACNTR ; 
 scalar_t__ DSPALINOFF ; 
 scalar_t__ DSPARB ; 
 scalar_t__ DSPASTRIDE ; 
 scalar_t__ DSPASURF ; 
 scalar_t__ DSPATILEOFF ; 
 scalar_t__ DSPCHICKENBIT ; 
 scalar_t__ DSPFW1 ; 
 scalar_t__ DSPFW2 ; 
 scalar_t__ DSPFW3 ; 
 scalar_t__ DSPFW4 ; 
 scalar_t__ DSPFW5 ; 
 scalar_t__ DSPFW6 ; 
 scalar_t__ HBLANK_A ; 
 scalar_t__ HISTOGRAM_INT_CONTROL ; 
 scalar_t__ HISTOGRAM_LOGIC_CONTROL ; 
 scalar_t__ HSYNC_A ; 
 scalar_t__ HTOTAL_A ; 
 int INTEL_MODE_PIXEL_MULTIPLIER_MASK ; 
 int INTEL_MODE_PIXEL_MULTIPLIER_SHIFT ; 
 scalar_t__ LVDS ; 
 scalar_t__ LVDSPP_OFF ; 
 scalar_t__ LVDSPP_ON ; 
 scalar_t__ MRST_DPLL_A ; 
 scalar_t__ MRST_FPA0 ; 
 scalar_t__ MRST_FPA1 ; 
 scalar_t__ MRST_PERF_MODE ; 
 scalar_t__ OV_OGAMC0 ; 
 scalar_t__ OV_OGAMC1 ; 
 scalar_t__ OV_OGAMC2 ; 
 scalar_t__ OV_OGAMC3 ; 
 scalar_t__ OV_OGAMC4 ; 
 scalar_t__ OV_OGAMC5 ; 
 scalar_t__ OV_OVADD ; 
 scalar_t__ PALETTE_A ; 
 scalar_t__ PFIT_AUTO_RATIOS ; 
 scalar_t__ PFIT_CONTROL ; 
 scalar_t__ PFIT_PGM_RATIOS ; 
 scalar_t__ PIPEACONF ; 
 scalar_t__ PIPEASRC ; 
 scalar_t__ PP_CONTROL ; 
 scalar_t__ PP_CYCLE ; 
 scalar_t__ PP_STATUS ; 
 scalar_t__ PSB_PM_SSC ; 
 scalar_t__ PSB_PM_SSS ; 
 int PSB_PWRGT_DISPLAY_MASK ; 
 void* PSB_RVDC32 (scalar_t__) ; 
 int /*<<< orphan*/  PSB_WVDC32 (int,scalar_t__) ; 
 scalar_t__ PWM_CONTROL_LOGIC ; 
 int REG_READ (int) ; 
 int REG_READ_AUX (int) ; 
 int /*<<< orphan*/  REG_WRITE (int,int) ; 
 int /*<<< orphan*/  REG_WRITE_AUX (int,int) ; 
 int /*<<< orphan*/  SDVOB ; 
 scalar_t__ VBLANK_A ; 
 scalar_t__ VGACNTRL ; 
 scalar_t__ VSYNC_A ; 
 scalar_t__ VTOTAL_A ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gma_intel_setup_gmbus (struct drm_device*) ; 
 int /*<<< orphan*/  gma_intel_teardown_gmbus (struct drm_device*) ; 
 int inl (scalar_t__) ; 
 int ioread32 (int) ; 
 int /*<<< orphan*/  iowrite16 (int,int) ; 
 int /*<<< orphan*/  iowrite32 (int,int) ; 
 int /*<<< orphan*/  iowrite8 (int,int) ; 
 int mid_chip_setup (struct drm_device*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  oaktrail_hdmi_init (struct drm_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  oaktrail_hdmi_restore (struct drm_device*) ; 
 int /*<<< orphan*/  oaktrail_hdmi_save (struct drm_device*) ; 
 int /*<<< orphan*/  oaktrail_hdmi_setup (struct drm_device*) ; 
 int /*<<< orphan*/  oaktrail_hdmi_teardown (struct drm_device*) ; 
 int /*<<< orphan*/  oaktrail_lvds_init (struct drm_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  oaktrail_regmap ; 
 int /*<<< orphan*/  outl (int,scalar_t__) ; 
 int /*<<< orphan*/  pci_dev_put (struct pci_dev*) ; 
 scalar_t__ pci_enable_msi (int /*<<< orphan*/ ) ; 
 struct pci_dev* pci_get_domain_bus_and_slot (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  psb_intel_destroy_bios (struct drm_device*) ; 
 int /*<<< orphan*/  psb_intel_init_bios (struct drm_device*) ; 
 int /*<<< orphan*/  psb_intel_sdvo_init (struct drm_device*,int /*<<< orphan*/ ) ; 
 TYPE_2__* to_gma_connector (struct drm_connector*) ; 
 int /*<<< orphan*/  udelay (int) ; 

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

__attribute__((used)) static int oaktrail_output_init(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	if (dev_priv->iLVDS_enable)
		oaktrail_lvds_init(dev, &dev_priv->mode_dev);
	else
		dev_err(dev->dev, "DSI is not supported\n");
	if (dev_priv->hdmi_priv)
		oaktrail_hdmi_init(dev, &dev_priv->mode_dev);

	psb_intel_sdvo_init(dev, SDVOB);

	return 0;
}

__attribute__((used)) static int oaktrail_save_display_registers(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	struct psb_save_area *regs = &dev_priv->regs;
	struct psb_pipe *p = &regs->pipe[0];
	int i;
	u32 pp_stat;

	/* Display arbitration control + watermarks */
	regs->psb.saveDSPARB = PSB_RVDC32(DSPARB);
	regs->psb.saveDSPFW1 = PSB_RVDC32(DSPFW1);
	regs->psb.saveDSPFW2 = PSB_RVDC32(DSPFW2);
	regs->psb.saveDSPFW3 = PSB_RVDC32(DSPFW3);
	regs->psb.saveDSPFW4 = PSB_RVDC32(DSPFW4);
	regs->psb.saveDSPFW5 = PSB_RVDC32(DSPFW5);
	regs->psb.saveDSPFW6 = PSB_RVDC32(DSPFW6);
	regs->psb.saveCHICKENBIT = PSB_RVDC32(DSPCHICKENBIT);

	/* Pipe & plane A info */
	p->conf = PSB_RVDC32(PIPEACONF);
	p->src = PSB_RVDC32(PIPEASRC);
	p->fp0 = PSB_RVDC32(MRST_FPA0);
	p->fp1 = PSB_RVDC32(MRST_FPA1);
	p->dpll = PSB_RVDC32(MRST_DPLL_A);
	p->htotal = PSB_RVDC32(HTOTAL_A);
	p->hblank = PSB_RVDC32(HBLANK_A);
	p->hsync = PSB_RVDC32(HSYNC_A);
	p->vtotal = PSB_RVDC32(VTOTAL_A);
	p->vblank = PSB_RVDC32(VBLANK_A);
	p->vsync = PSB_RVDC32(VSYNC_A);
	regs->psb.saveBCLRPAT_A = PSB_RVDC32(BCLRPAT_A);
	p->cntr = PSB_RVDC32(DSPACNTR);
	p->stride = PSB_RVDC32(DSPASTRIDE);
	p->addr = PSB_RVDC32(DSPABASE);
	p->surf = PSB_RVDC32(DSPASURF);
	p->linoff = PSB_RVDC32(DSPALINOFF);
	p->tileoff = PSB_RVDC32(DSPATILEOFF);

	/* Save cursor regs */
	regs->psb.saveDSPACURSOR_CTRL = PSB_RVDC32(CURACNTR);
	regs->psb.saveDSPACURSOR_BASE = PSB_RVDC32(CURABASE);
	regs->psb.saveDSPACURSOR_POS = PSB_RVDC32(CURAPOS);

	/* Save palette (gamma) */
	for (i = 0; i < 256; i++)
		p->palette[i] = PSB_RVDC32(PALETTE_A + (i << 2));

	if (dev_priv->hdmi_priv)
		oaktrail_hdmi_save(dev);

	/* Save performance state */
	regs->psb.savePERF_MODE = PSB_RVDC32(MRST_PERF_MODE);

	/* LVDS state */
	regs->psb.savePP_CONTROL = PSB_RVDC32(PP_CONTROL);
	regs->psb.savePFIT_PGM_RATIOS = PSB_RVDC32(PFIT_PGM_RATIOS);
	regs->psb.savePFIT_AUTO_RATIOS = PSB_RVDC32(PFIT_AUTO_RATIOS);
	regs->saveBLC_PWM_CTL = PSB_RVDC32(BLC_PWM_CTL);
	regs->saveBLC_PWM_CTL2 = PSB_RVDC32(BLC_PWM_CTL2);
	regs->psb.saveLVDS = PSB_RVDC32(LVDS);
	regs->psb.savePFIT_CONTROL = PSB_RVDC32(PFIT_CONTROL);
	regs->psb.savePP_ON_DELAYS = PSB_RVDC32(LVDSPP_ON);
	regs->psb.savePP_OFF_DELAYS = PSB_RVDC32(LVDSPP_OFF);
	regs->psb.savePP_DIVISOR = PSB_RVDC32(PP_CYCLE);

	/* HW overlay */
	regs->psb.saveOV_OVADD = PSB_RVDC32(OV_OVADD);
	regs->psb.saveOV_OGAMC0 = PSB_RVDC32(OV_OGAMC0);
	regs->psb.saveOV_OGAMC1 = PSB_RVDC32(OV_OGAMC1);
	regs->psb.saveOV_OGAMC2 = PSB_RVDC32(OV_OGAMC2);
	regs->psb.saveOV_OGAMC3 = PSB_RVDC32(OV_OGAMC3);
	regs->psb.saveOV_OGAMC4 = PSB_RVDC32(OV_OGAMC4);
	regs->psb.saveOV_OGAMC5 = PSB_RVDC32(OV_OGAMC5);

	/* DPST registers */
	regs->psb.saveHISTOGRAM_INT_CONTROL_REG =
					PSB_RVDC32(HISTOGRAM_INT_CONTROL);
	regs->psb.saveHISTOGRAM_LOGIC_CONTROL_REG =
					PSB_RVDC32(HISTOGRAM_LOGIC_CONTROL);
	regs->psb.savePWM_CONTROL_LOGIC = PSB_RVDC32(PWM_CONTROL_LOGIC);

	if (dev_priv->iLVDS_enable) {
		/* Shut down the panel */
		PSB_WVDC32(0, PP_CONTROL);

		do {
			pp_stat = PSB_RVDC32(PP_STATUS);
		} while (pp_stat & 0x80000000);

		/* Turn off the plane */
		PSB_WVDC32(0x58000000, DSPACNTR);
		/* Trigger the plane disable */
		PSB_WVDC32(0, DSPASURF);

		/* Wait ~4 ticks */
		msleep(4);

		/* Turn off pipe */
		PSB_WVDC32(0x0, PIPEACONF);
		/* Wait ~8 ticks */
		msleep(8);

		/* Turn off PLLs */
		PSB_WVDC32(0, MRST_DPLL_A);
	}
	return 0;
}

__attribute__((used)) static int oaktrail_restore_display_registers(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	struct psb_save_area *regs = &dev_priv->regs;
	struct psb_pipe *p = &regs->pipe[0];
	u32 pp_stat;
	int i;

	/* Display arbitration + watermarks */
	PSB_WVDC32(regs->psb.saveDSPARB, DSPARB);
	PSB_WVDC32(regs->psb.saveDSPFW1, DSPFW1);
	PSB_WVDC32(regs->psb.saveDSPFW2, DSPFW2);
	PSB_WVDC32(regs->psb.saveDSPFW3, DSPFW3);
	PSB_WVDC32(regs->psb.saveDSPFW4, DSPFW4);
	PSB_WVDC32(regs->psb.saveDSPFW5, DSPFW5);
	PSB_WVDC32(regs->psb.saveDSPFW6, DSPFW6);
	PSB_WVDC32(regs->psb.saveCHICKENBIT, DSPCHICKENBIT);

	/* Make sure VGA plane is off. it initializes to on after reset!*/
	PSB_WVDC32(0x80000000, VGACNTRL);

	/* set the plls */
	PSB_WVDC32(p->fp0, MRST_FPA0);
	PSB_WVDC32(p->fp1, MRST_FPA1);

	/* Actually enable it */
	PSB_WVDC32(p->dpll, MRST_DPLL_A);
	DRM_UDELAY(150);

	/* Restore mode */
	PSB_WVDC32(p->htotal, HTOTAL_A);
	PSB_WVDC32(p->hblank, HBLANK_A);
	PSB_WVDC32(p->hsync, HSYNC_A);
	PSB_WVDC32(p->vtotal, VTOTAL_A);
	PSB_WVDC32(p->vblank, VBLANK_A);
	PSB_WVDC32(p->vsync, VSYNC_A);
	PSB_WVDC32(p->src, PIPEASRC);
	PSB_WVDC32(regs->psb.saveBCLRPAT_A, BCLRPAT_A);

	/* Restore performance mode*/
	PSB_WVDC32(regs->psb.savePERF_MODE, MRST_PERF_MODE);

	/* Enable the pipe*/
	if (dev_priv->iLVDS_enable)
		PSB_WVDC32(p->conf, PIPEACONF);

	/* Set up the plane*/
	PSB_WVDC32(p->linoff, DSPALINOFF);
	PSB_WVDC32(p->stride, DSPASTRIDE);
	PSB_WVDC32(p->tileoff, DSPATILEOFF);

	/* Enable the plane */
	PSB_WVDC32(p->cntr, DSPACNTR);
	PSB_WVDC32(p->surf, DSPASURF);

	/* Enable Cursor A */
	PSB_WVDC32(regs->psb.saveDSPACURSOR_CTRL, CURACNTR);
	PSB_WVDC32(regs->psb.saveDSPACURSOR_POS, CURAPOS);
	PSB_WVDC32(regs->psb.saveDSPACURSOR_BASE, CURABASE);

	/* Restore palette (gamma) */
	for (i = 0; i < 256; i++)
		PSB_WVDC32(p->palette[i], PALETTE_A + (i << 2));

	if (dev_priv->hdmi_priv)
		oaktrail_hdmi_restore(dev);

	if (dev_priv->iLVDS_enable) {
		PSB_WVDC32(regs->saveBLC_PWM_CTL2, BLC_PWM_CTL2);
		PSB_WVDC32(regs->psb.saveLVDS, LVDS); /*port 61180h*/
		PSB_WVDC32(regs->psb.savePFIT_CONTROL, PFIT_CONTROL);
		PSB_WVDC32(regs->psb.savePFIT_PGM_RATIOS, PFIT_PGM_RATIOS);
		PSB_WVDC32(regs->psb.savePFIT_AUTO_RATIOS, PFIT_AUTO_RATIOS);
		PSB_WVDC32(regs->saveBLC_PWM_CTL, BLC_PWM_CTL);
		PSB_WVDC32(regs->psb.savePP_ON_DELAYS, LVDSPP_ON);
		PSB_WVDC32(regs->psb.savePP_OFF_DELAYS, LVDSPP_OFF);
		PSB_WVDC32(regs->psb.savePP_DIVISOR, PP_CYCLE);
		PSB_WVDC32(regs->psb.savePP_CONTROL, PP_CONTROL);
	}

	/* Wait for cycle delay */
	do {
		pp_stat = PSB_RVDC32(PP_STATUS);
	} while (pp_stat & 0x08000000);

	/* Wait for panel power up */
	do {
		pp_stat = PSB_RVDC32(PP_STATUS);
	} while (pp_stat & 0x10000000);

	/* Restore HW overlay */
	PSB_WVDC32(regs->psb.saveOV_OVADD, OV_OVADD);
	PSB_WVDC32(regs->psb.saveOV_OGAMC0, OV_OGAMC0);
	PSB_WVDC32(regs->psb.saveOV_OGAMC1, OV_OGAMC1);
	PSB_WVDC32(regs->psb.saveOV_OGAMC2, OV_OGAMC2);
	PSB_WVDC32(regs->psb.saveOV_OGAMC3, OV_OGAMC3);
	PSB_WVDC32(regs->psb.saveOV_OGAMC4, OV_OGAMC4);
	PSB_WVDC32(regs->psb.saveOV_OGAMC5, OV_OGAMC5);

	/* DPST registers */
	PSB_WVDC32(regs->psb.saveHISTOGRAM_INT_CONTROL_REG,
						HISTOGRAM_INT_CONTROL);
	PSB_WVDC32(regs->psb.saveHISTOGRAM_LOGIC_CONTROL_REG,
						HISTOGRAM_LOGIC_CONTROL);
	PSB_WVDC32(regs->psb.savePWM_CONTROL_LOGIC, PWM_CONTROL_LOGIC);

	return 0;
}

__attribute__((used)) static int oaktrail_power_down(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	u32 pwr_mask ;
	u32 pwr_sts;

	pwr_mask = PSB_PWRGT_DISPLAY_MASK;
	outl(pwr_mask, dev_priv->ospm_base + PSB_PM_SSC);

	while (true) {
		pwr_sts = inl(dev_priv->ospm_base + PSB_PM_SSS);
		if ((pwr_sts & pwr_mask) == pwr_mask)
			break;
		else
			udelay(10);
	}
	return 0;
}

__attribute__((used)) static int oaktrail_power_up(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	u32 pwr_mask = PSB_PWRGT_DISPLAY_MASK;
	u32 pwr_sts, pwr_cnt;

	pwr_cnt = inl(dev_priv->ospm_base + PSB_PM_SSC);
	pwr_cnt &= ~pwr_mask;
	outl(pwr_cnt, (dev_priv->ospm_base + PSB_PM_SSC));

	while (true) {
		pwr_sts = inl(dev_priv->ospm_base + PSB_PM_SSS);
		if ((pwr_sts & pwr_mask) == 0)
			break;
		else
			udelay(10);
	}
	return 0;
}

__attribute__((used)) static int oaktrail_chip_setup(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;
	int ret;
	
	if (pci_enable_msi(dev->pdev))
		dev_warn(dev->dev, "Enabling MSI failed!\n");

	dev_priv->regmap = oaktrail_regmap;

	ret = mid_chip_setup(dev);
	if (ret < 0)
		return ret;
	if (!dev_priv->has_gct) {
		/* Now pull the BIOS data */
		psb_intel_opregion_init(dev);
		psb_intel_init_bios(dev);
	}
	gma_intel_setup_gmbus(dev);
	oaktrail_hdmi_setup(dev);
	return 0;
}

__attribute__((used)) static void oaktrail_teardown(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;

	gma_intel_teardown_gmbus(dev);
	oaktrail_hdmi_teardown(dev);
	if (!dev_priv->has_gct)
		psb_intel_destroy_bios(dev);
}

