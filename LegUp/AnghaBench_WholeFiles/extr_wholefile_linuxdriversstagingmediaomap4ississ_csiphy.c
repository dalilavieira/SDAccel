#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_9__ ;
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;
typedef  struct TYPE_11__   TYPE_10__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct v4l2_subdev {int /*<<< orphan*/  entity; } ;
struct TYPE_20__ {int pol; int pos; } ;
struct iss_csiphy_lanes_cfg {TYPE_9__ clk; TYPE_8__* data; } ;
struct TYPE_17__ {struct iss_csiphy_lanes_cfg lanecfg; } ;
struct TYPE_18__ {TYPE_6__ csi2; } ;
struct iss_v4l2_subdevs_group {scalar_t__ interface; TYPE_7__ bus; } ;
struct iss_pipeline {int state; int external_rate; int external_bpp; TYPE_5__* external; } ;
struct TYPE_15__ {int ths_term; int ths_settle; int tclk_term; int tclk_miss; int tclk_settle; } ;
struct TYPE_13__ {int pos; scalar_t__ pol; } ;
struct TYPE_14__ {TYPE_2__ clk; TYPE_1__* data; } ;
struct iss_csiphy {int cfg_regs; unsigned int max_data_lanes; int phy_regs; int phy_in_use; int /*<<< orphan*/  mutex; scalar_t__ used_data_lanes; int /*<<< orphan*/ * csi2; struct iss_device* iss; TYPE_4__ dphy; TYPE_3__ lanes; } ;
struct iss_device {int* regs; int /*<<< orphan*/  csi2b; int /*<<< orphan*/  csi2a; struct iss_csiphy csiphy2; struct iss_csiphy csiphy1; int /*<<< orphan*/  syscon; int /*<<< orphan*/  dev; } ;
struct iss_csiphy_dphy_cfg {int /*<<< orphan*/  tclk_settle; int /*<<< orphan*/  tclk_miss; int /*<<< orphan*/  tclk_term; void* ths_settle; void* ths_term; } ;
struct iss_csi2_device {TYPE_10__* phy; } ;
typedef  enum iss_mem_resources { ____Placeholder_iss_mem_resources } iss_mem_resources ;
struct TYPE_19__ {int pos; int pol; } ;
struct TYPE_16__ {struct iss_v4l2_subdevs_group* host_priv; } ;
struct TYPE_12__ {int pos; scalar_t__ pol; } ;
struct TYPE_11__ {int used_data_lanes; unsigned int max_data_lanes; int /*<<< orphan*/  mutex; struct iss_csiphy_lanes_cfg lanes; struct iss_csiphy_dphy_cfg dphy; } ;

/* Variables and functions */
 int CSI2_COMPLEXIO_CFG ; 
 int CSI2_COMPLEXIO_CFG_CLOCK_POL ; 
 int CSI2_COMPLEXIO_CFG_CLOCK_POSITION_MASK ; 
 int CSI2_COMPLEXIO_CFG_CLOCK_POSITION_SHIFT ; 
 int CSI2_COMPLEXIO_CFG_DATA_POL (unsigned int) ; 
 int CSI2_COMPLEXIO_CFG_DATA_POSITION_MASK (unsigned int) ; 
 int CSI2_COMPLEXIO_CFG_DATA_POSITION_SHIFT (unsigned int) ; 
 int CSI2_COMPLEXIO_CFG_PWD_CMD_MASK ; 
 int CSI2_COMPLEXIO_CFG_PWD_CMD_OFF ; 
 int CSI2_COMPLEXIO_CFG_PWD_CMD_ON ; 
 int CSI2_COMPLEXIO_CFG_PWD_STATUS_MASK ; 
 int CSI2_COMPLEXIO_CFG_PWR_AUTO ; 
 void* DIV_ROUND_UP (int,int) ; 
 int EBUSY ; 
 int EINVAL ; 
 unsigned int ISS_CSIPHY1_NUM_DATA_LANES ; 
 unsigned int ISS_CSIPHY2_NUM_DATA_LANES ; 
 scalar_t__ ISS_INTERFACE_CSI2A_PHY1 ; 
 scalar_t__ ISS_INTERFACE_CSI2B_PHY2 ; 
 int ISS_PIPELINE_IDLE_INPUT ; 
 int ISS_PIPELINE_IDLE_OUTPUT ; 
 int ISS_PIPELINE_QUEUE_INPUT ; 
 int ISS_PIPELINE_QUEUE_OUTPUT ; 
 int ISS_PIPELINE_STREAM_INPUT ; 
 int ISS_PIPELINE_STREAM_OUTPUT ; 
 int OMAP4_CAMERARX_CSI21_CAMMODE_MASK ; 
 int OMAP4_CAMERARX_CSI21_CTRLCLKEN_MASK ; 
 int OMAP4_CAMERARX_CSI21_LANEENABLE_MASK ; 
 int OMAP4_CAMERARX_CSI21_LANEENABLE_SHIFT ; 
 int OMAP4_CAMERARX_CSI22_CAMMODE_MASK ; 
 int OMAP4_CAMERARX_CSI22_CTRLCLKEN_MASK ; 
 int OMAP4_CAMERARX_CSI22_LANEENABLE_MASK ; 
 int OMAP4_CAMERARX_CSI22_LANEENABLE_SHIFT ; 
 int OMAP4_ISS_MEM_CAMERARX_CORE1 ; 
 int OMAP4_ISS_MEM_CAMERARX_CORE2 ; 
 int OMAP4_ISS_MEM_CSI2_A_REGS1 ; 
 int OMAP4_ISS_MEM_CSI2_B_REGS1 ; 
 int REGISTER0 ; 
 int REGISTER0_THS_SETTLE_SHIFT ; 
 int REGISTER0_THS_TERM_SHIFT ; 
 int REGISTER1 ; 
 int REGISTER1_CTRLCLK_DIV_FACTOR_SHIFT ; 
 int REGISTER1_DPHY_HS_SYNC_PATTERN_SHIFT ; 
 int REGISTER1_TCLK_SETTLE_SHIFT ; 
 int REGISTER1_TCLK_TERM_SHIFT ; 
 int /*<<< orphan*/  TCLK_MISS ; 
 int /*<<< orphan*/  TCLK_SETTLE ; 
 int /*<<< orphan*/  TCLK_TERM ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int omap4iss_csi2_reset (int /*<<< orphan*/ *) ; 
 int readl (int) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int,int) ; 
 struct iss_pipeline* to_iss_pipeline (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  udelay (int) ; 
 struct iss_csi2_device* v4l2_get_subdevdata (struct v4l2_subdev*) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static inline int iss_pipeline_ready(struct iss_pipeline *pipe)
{
	return pipe->state == (ISS_PIPELINE_STREAM_INPUT |
			       ISS_PIPELINE_STREAM_OUTPUT |
			       ISS_PIPELINE_QUEUE_INPUT |
			       ISS_PIPELINE_QUEUE_OUTPUT |
			       ISS_PIPELINE_IDLE_INPUT |
			       ISS_PIPELINE_IDLE_OUTPUT);
}

__attribute__((used)) static inline
u32 iss_reg_read(struct iss_device *iss, enum iss_mem_resources res,
		 u32 offset)
{
	return readl(iss->regs[res] + offset);
}

__attribute__((used)) static inline
void iss_reg_write(struct iss_device *iss, enum iss_mem_resources res,
		   u32 offset, u32 value)
{
	writel(value, iss->regs[res] + offset);
}

__attribute__((used)) static inline
void iss_reg_clr(struct iss_device *iss, enum iss_mem_resources res,
		 u32 offset, u32 clr)
{
	u32 v = iss_reg_read(iss, res, offset);

	iss_reg_write(iss, res, offset, v & ~clr);
}

__attribute__((used)) static inline
void iss_reg_set(struct iss_device *iss, enum iss_mem_resources res,
		 u32 offset, u32 set)
{
	u32 v = iss_reg_read(iss, res, offset);

	iss_reg_write(iss, res, offset, v | set);
}

__attribute__((used)) static inline
void iss_reg_update(struct iss_device *iss, enum iss_mem_resources res,
		    u32 offset, u32 clr, u32 set)
{
	u32 v = iss_reg_read(iss, res, offset);

	iss_reg_write(iss, res, offset, (v & ~clr) | set);
}

__attribute__((used)) static void csiphy_lanes_config(struct iss_csiphy *phy)
{
	unsigned int i;
	u32 reg;

	reg = iss_reg_read(phy->iss, phy->cfg_regs, CSI2_COMPLEXIO_CFG);

	for (i = 0; i < phy->max_data_lanes; i++) {
		reg &= ~(CSI2_COMPLEXIO_CFG_DATA_POL(i + 1) |
			 CSI2_COMPLEXIO_CFG_DATA_POSITION_MASK(i + 1));
		reg |= (phy->lanes.data[i].pol ?
			CSI2_COMPLEXIO_CFG_DATA_POL(i + 1) : 0);
		reg |= (phy->lanes.data[i].pos <<
			CSI2_COMPLEXIO_CFG_DATA_POSITION_SHIFT(i + 1));
	}

	reg &= ~(CSI2_COMPLEXIO_CFG_CLOCK_POL |
		 CSI2_COMPLEXIO_CFG_CLOCK_POSITION_MASK);
	reg |= phy->lanes.clk.pol ? CSI2_COMPLEXIO_CFG_CLOCK_POL : 0;
	reg |= phy->lanes.clk.pos << CSI2_COMPLEXIO_CFG_CLOCK_POSITION_SHIFT;

	iss_reg_write(phy->iss, phy->cfg_regs, CSI2_COMPLEXIO_CFG, reg);
}

__attribute__((used)) static int csiphy_set_power(struct iss_csiphy *phy, u32 power)
{
	u32 reg;
	u8 retry_count;

	iss_reg_update(phy->iss, phy->cfg_regs, CSI2_COMPLEXIO_CFG,
		       CSI2_COMPLEXIO_CFG_PWD_CMD_MASK,
		       power | CSI2_COMPLEXIO_CFG_PWR_AUTO);

	retry_count = 0;
	do {
		udelay(1);
		reg = iss_reg_read(phy->iss, phy->cfg_regs, CSI2_COMPLEXIO_CFG)
		    & CSI2_COMPLEXIO_CFG_PWD_STATUS_MASK;

		if (reg != power >> 2)
			retry_count++;

	} while ((reg != power >> 2) && (retry_count < 250));

	if (retry_count == 250) {
		dev_err(phy->iss->dev, "CSI2 CIO set power failed!\n");
		return -EBUSY;
	}

	return 0;
}

__attribute__((used)) static void csiphy_dphy_config(struct iss_csiphy *phy)
{
	u32 reg;

	/* Set up REGISTER0 */
	reg = phy->dphy.ths_term << REGISTER0_THS_TERM_SHIFT;
	reg |= phy->dphy.ths_settle << REGISTER0_THS_SETTLE_SHIFT;

	iss_reg_write(phy->iss, phy->phy_regs, REGISTER0, reg);

	/* Set up REGISTER1 */
	reg = phy->dphy.tclk_term << REGISTER1_TCLK_TERM_SHIFT;
	reg |= phy->dphy.tclk_miss << REGISTER1_CTRLCLK_DIV_FACTOR_SHIFT;
	reg |= phy->dphy.tclk_settle << REGISTER1_TCLK_SETTLE_SHIFT;
	reg |= 0xb8 << REGISTER1_DPHY_HS_SYNC_PATTERN_SHIFT;

	iss_reg_write(phy->iss, phy->phy_regs, REGISTER1, reg);
}

int omap4iss_csiphy_config(struct iss_device *iss,
			   struct v4l2_subdev *csi2_subdev)
{
	struct iss_csi2_device *csi2 = v4l2_get_subdevdata(csi2_subdev);
	struct iss_pipeline *pipe = to_iss_pipeline(&csi2_subdev->entity);
	struct iss_v4l2_subdevs_group *subdevs = pipe->external->host_priv;
	struct iss_csiphy_dphy_cfg csi2phy;
	int csi2_ddrclk_khz;
	struct iss_csiphy_lanes_cfg *lanes;
	unsigned int used_lanes = 0;
	u32 cam_rx_ctrl;
	unsigned int i;

	lanes = &subdevs->bus.csi2.lanecfg;

	/*
	 * SCM.CONTROL_CAMERA_RX
	 * - bit [31] : CSIPHY2 lane 2 enable (4460+ only)
	 * - bit [30:29] : CSIPHY2 per-lane enable (1 to 0)
	 * - bit [28:24] : CSIPHY1 per-lane enable (4 to 0)
	 * - bit [21] : CSIPHY2 CTRLCLK enable
	 * - bit [20:19] : CSIPHY2 config: 00 d-phy, 01/10 ccp2
	 * - bit [18] : CSIPHY1 CTRLCLK enable
	 * - bit [17:16] : CSIPHY1 config: 00 d-phy, 01/10 ccp2
	 */
	/*
	 * TODO: When implementing DT support specify the CONTROL_CAMERA_RX
	 * register offset in the syscon property instead of hardcoding it.
	 */
	regmap_read(iss->syscon, 0x68, &cam_rx_ctrl);

	if (subdevs->interface == ISS_INTERFACE_CSI2A_PHY1) {
		cam_rx_ctrl &= ~(OMAP4_CAMERARX_CSI21_LANEENABLE_MASK |
				OMAP4_CAMERARX_CSI21_CAMMODE_MASK);
		/* NOTE: Leave CSIPHY1 config to 0x0: D-PHY mode */
		/* Enable all lanes for now */
		cam_rx_ctrl |=
			0x1f << OMAP4_CAMERARX_CSI21_LANEENABLE_SHIFT;
		/* Enable CTRLCLK */
		cam_rx_ctrl |= OMAP4_CAMERARX_CSI21_CTRLCLKEN_MASK;
	}

	if (subdevs->interface == ISS_INTERFACE_CSI2B_PHY2) {
		cam_rx_ctrl &= ~(OMAP4_CAMERARX_CSI22_LANEENABLE_MASK |
				OMAP4_CAMERARX_CSI22_CAMMODE_MASK);
		/* NOTE: Leave CSIPHY2 config to 0x0: D-PHY mode */
		/* Enable all lanes for now */
		cam_rx_ctrl |=
			0x3 << OMAP4_CAMERARX_CSI22_LANEENABLE_SHIFT;
		/* Enable CTRLCLK */
		cam_rx_ctrl |= OMAP4_CAMERARX_CSI22_CTRLCLKEN_MASK;
	}

	regmap_write(iss->syscon, 0x68, cam_rx_ctrl);

	/* Reset used lane count */
	csi2->phy->used_data_lanes = 0;

	/* Clock and data lanes verification */
	for (i = 0; i < csi2->phy->max_data_lanes; i++) {
		if (lanes->data[i].pos == 0)
			continue;

		if (lanes->data[i].pol > 1 ||
		    lanes->data[i].pos > (csi2->phy->max_data_lanes + 1))
			return -EINVAL;

		if (used_lanes & (1 << lanes->data[i].pos))
			return -EINVAL;

		used_lanes |= 1 << lanes->data[i].pos;
		csi2->phy->used_data_lanes++;
	}

	if (lanes->clk.pol > 1 ||
	    lanes->clk.pos > (csi2->phy->max_data_lanes + 1))
		return -EINVAL;

	if (lanes->clk.pos == 0 || used_lanes & (1 << lanes->clk.pos))
		return -EINVAL;

	csi2_ddrclk_khz = pipe->external_rate / 1000
		/ (2 * csi2->phy->used_data_lanes)
		* pipe->external_bpp;

	/*
	 * THS_TERM: Programmed value = ceil(12.5 ns/DDRClk period) - 1.
	 * THS_SETTLE: Programmed value = ceil(90 ns/DDRClk period) + 3.
	 */
	csi2phy.ths_term = DIV_ROUND_UP(25 * csi2_ddrclk_khz, 2000000) - 1;
	csi2phy.ths_settle = DIV_ROUND_UP(90 * csi2_ddrclk_khz, 1000000) + 3;
	csi2phy.tclk_term = TCLK_TERM;
	csi2phy.tclk_miss = TCLK_MISS;
	csi2phy.tclk_settle = TCLK_SETTLE;

	mutex_lock(&csi2->phy->mutex);
	csi2->phy->dphy = csi2phy;
	csi2->phy->lanes = *lanes;
	mutex_unlock(&csi2->phy->mutex);

	return 0;
}

int omap4iss_csiphy_acquire(struct iss_csiphy *phy)
{
	int rval;

	mutex_lock(&phy->mutex);

	rval = omap4iss_csi2_reset(phy->csi2);
	if (rval)
		goto done;

	csiphy_dphy_config(phy);
	csiphy_lanes_config(phy);

	rval = csiphy_set_power(phy, CSI2_COMPLEXIO_CFG_PWD_CMD_ON);
	if (rval)
		goto done;

	phy->phy_in_use = 1;

done:
	mutex_unlock(&phy->mutex);
	return rval;
}

void omap4iss_csiphy_release(struct iss_csiphy *phy)
{
	mutex_lock(&phy->mutex);
	if (phy->phy_in_use) {
		csiphy_set_power(phy, CSI2_COMPLEXIO_CFG_PWD_CMD_OFF);
		phy->phy_in_use = 0;
	}
	mutex_unlock(&phy->mutex);
}

int omap4iss_csiphy_init(struct iss_device *iss)
{
	struct iss_csiphy *phy1 = &iss->csiphy1;
	struct iss_csiphy *phy2 = &iss->csiphy2;

	phy1->iss = iss;
	phy1->csi2 = &iss->csi2a;
	phy1->max_data_lanes = ISS_CSIPHY1_NUM_DATA_LANES;
	phy1->used_data_lanes = 0;
	phy1->cfg_regs = OMAP4_ISS_MEM_CSI2_A_REGS1;
	phy1->phy_regs = OMAP4_ISS_MEM_CAMERARX_CORE1;
	mutex_init(&phy1->mutex);

	phy2->iss = iss;
	phy2->csi2 = &iss->csi2b;
	phy2->max_data_lanes = ISS_CSIPHY2_NUM_DATA_LANES;
	phy2->used_data_lanes = 0;
	phy2->cfg_regs = OMAP4_ISS_MEM_CSI2_B_REGS1;
	phy2->phy_regs = OMAP4_ISS_MEM_CAMERARX_CORE2;
	mutex_init(&phy2->mutex);

	return 0;
}

