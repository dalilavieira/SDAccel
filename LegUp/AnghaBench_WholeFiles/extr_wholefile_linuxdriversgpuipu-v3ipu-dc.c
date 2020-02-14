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
typedef  int u32 ;
struct ipu_soc {unsigned int idmac_reg; struct ipu_dc_priv* dc_priv; } ;
struct ipu_di {int dummy; } ;
struct ipu_dc_priv {unsigned int dc_tmpl_reg; unsigned int dc_reg; scalar_t__ use_count; struct ipu_dc* channels; struct ipu_soc* ipu; struct device* dev; int /*<<< orphan*/  mutex; } ;
struct ipu_dc {unsigned int base; int in_use; int chno; struct ipu_dc_priv* priv; scalar_t__ di; } ;
struct device {int dummy; } ;
typedef  enum ipu_dc_map { ____Placeholder_ipu_dc_map } ipu_dc_map ;

/* Variables and functions */
 unsigned int DC_DISP_CONF2 (scalar_t__) ; 
 int DC_EVT_EOF ; 
 int DC_EVT_EOFIELD ; 
 int DC_EVT_EOL ; 
 int DC_EVT_NEW_ADDR ; 
 int DC_EVT_NEW_CHAN ; 
 int DC_EVT_NEW_DATA ; 
 int DC_EVT_NF ; 
 int DC_EVT_NFIELD ; 
 int DC_EVT_NL ; 
 unsigned int DC_GEN ; 
 int DC_GEN_SYNC_1_6_SYNC ; 
 int DC_GEN_SYNC_PRIORITY_1 ; 
 unsigned int DC_MAP_CONF_PTR (int) ; 
 unsigned int DC_MAP_CONF_VAL (int) ; 
 unsigned int DC_RL_CH (int) ; 
 unsigned int DC_WR_CH_ADDR ; 
 unsigned int DC_WR_CH_CONF ; 
 int DC_WR_CH_CONF_DISP_ID_PARALLEL (int) ; 
 int DC_WR_CH_CONF_FIELD_MODE ; 
 int DC_WR_CH_CONF_PROG_DI_ID ; 
 int DC_WR_CH_CONF_PROG_TYPE_MASK ; 
 int DC_WR_CH_CONF_PROG_TYPE_NORMAL ; 
 int DC_WR_CH_CONF_WORD_SIZE_24 ; 
 int /*<<< orphan*/  EBUSY ; 
 int /*<<< orphan*/  ENODEV ; 
 int ENOMEM ; 
 struct ipu_dc* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IPU_CONF_DC_EN ; 
 int IPU_DC_MAP_BGR24 ; 
 int IPU_DC_MAP_BGR666 ; 
 int IPU_DC_MAP_GBR24 ; 
 int IPU_DC_MAP_LVDS666 ; 
 int IPU_DC_MAP_RGB24 ; 
 int IPU_DC_MAP_RGB565 ; 
 int IPU_DC_NUM_CHANNELS ; 
#define  MEDIA_BUS_FMT_BGR888_1X24 133 
#define  MEDIA_BUS_FMT_GBR888_1X24 132 
#define  MEDIA_BUS_FMT_RGB565_1X16 131 
#define  MEDIA_BUS_FMT_RGB666_1X18 130 
#define  MEDIA_BUS_FMT_RGB666_1X24_CPADHI 129 
#define  MEDIA_BUS_FMT_RGB888_1X24 128 
 int NULL_WAVE ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int SYNC_WAVE ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int WCLK ; 
 int WRG ; 
 int WROD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned long,unsigned long) ; 
 void* devm_ioremap (struct device*,unsigned long,int /*<<< orphan*/ ) ; 
 struct ipu_dc_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ ipu_di_get_num (struct ipu_di*) ; 
 int /*<<< orphan*/  ipu_module_disable (struct ipu_soc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipu_module_enable (struct ipu_soc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int readl (unsigned int) ; 
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

__attribute__((used)) static void dc_link_event(struct ipu_dc *dc, int event, int addr, int priority)
{
	u32 reg;

	reg = readl(dc->base + DC_RL_CH(event));
	reg &= ~(0xffff << (16 * (event & 0x1)));
	reg |= ((addr << 8) | priority) << (16 * (event & 0x1));
	writel(reg, dc->base + DC_RL_CH(event));
}

__attribute__((used)) static void dc_write_tmpl(struct ipu_dc *dc, int word, u32 opcode, u32 operand,
		int map, int wave, int glue, int sync, int stop)
{
	struct ipu_dc_priv *priv = dc->priv;
	u32 reg1, reg2;

	if (opcode == WCLK) {
		reg1 = (operand << 20) & 0xfff00000;
		reg2 = operand >> 12 | opcode << 1 | stop << 9;
	} else if (opcode == WRG) {
		reg1 = sync | glue << 4 | ++wave << 11 | ((operand << 15) & 0xffff8000);
		reg2 = operand >> 17 | opcode << 7 | stop << 9;
	} else {
		reg1 = sync | glue << 4 | ++wave << 11 | ++map << 15 | ((operand << 20) & 0xfff00000);
		reg2 = operand >> 12 | opcode << 4 | stop << 9;
	}
	writel(reg1, priv->dc_tmpl_reg + word * 8);
	writel(reg2, priv->dc_tmpl_reg + word * 8 + 4);
}

__attribute__((used)) static int ipu_bus_format_to_map(u32 fmt)
{
	switch (fmt) {
	default:
		WARN_ON(1);
		/* fall-through */
	case MEDIA_BUS_FMT_RGB888_1X24:
		return IPU_DC_MAP_RGB24;
	case MEDIA_BUS_FMT_RGB565_1X16:
		return IPU_DC_MAP_RGB565;
	case MEDIA_BUS_FMT_GBR888_1X24:
		return IPU_DC_MAP_GBR24;
	case MEDIA_BUS_FMT_RGB666_1X18:
		return IPU_DC_MAP_BGR666;
	case MEDIA_BUS_FMT_RGB666_1X24_CPADHI:
		return IPU_DC_MAP_LVDS666;
	case MEDIA_BUS_FMT_BGR888_1X24:
		return IPU_DC_MAP_BGR24;
	}
}

int ipu_dc_init_sync(struct ipu_dc *dc, struct ipu_di *di, bool interlaced,
		u32 bus_format, u32 width)
{
	struct ipu_dc_priv *priv = dc->priv;
	int addr, sync;
	u32 reg = 0;
	int map;

	dc->di = ipu_di_get_num(di);

	map = ipu_bus_format_to_map(bus_format);

	/*
	 * In interlaced mode we need more counters to create the asymmetric
	 * per-field VSYNC signals. The pixel active signal synchronising DC
	 * to DI moves to signal generator #6 (see ipu-di.c). In progressive
	 * mode counter #5 is used.
	 */
	sync = interlaced ? 6 : 5;

	/* Reserve 5 microcode template words for each DI */
	if (dc->di)
		addr = 5;
	else
		addr = 0;

	if (interlaced) {
		dc_link_event(dc, DC_EVT_NL, addr, 3);
		dc_link_event(dc, DC_EVT_EOL, addr, 2);
		dc_link_event(dc, DC_EVT_NEW_DATA, addr, 1);

		/* Init template microcode */
		dc_write_tmpl(dc, addr, WROD(0), 0, map, SYNC_WAVE, 0, sync, 1);
	} else {
		dc_link_event(dc, DC_EVT_NL, addr + 2, 3);
		dc_link_event(dc, DC_EVT_EOL, addr + 3, 2);
		dc_link_event(dc, DC_EVT_NEW_DATA, addr + 1, 1);

		/* Init template microcode */
		dc_write_tmpl(dc, addr + 2, WROD(0), 0, map, SYNC_WAVE, 8, sync, 1);
		dc_write_tmpl(dc, addr + 3, WROD(0), 0, map, SYNC_WAVE, 4, sync, 0);
		dc_write_tmpl(dc, addr + 4, WRG, 0, map, NULL_WAVE, 0, 0, 1);
		dc_write_tmpl(dc, addr + 1, WROD(0), 0, map, SYNC_WAVE, 0, sync, 1);
	}

	dc_link_event(dc, DC_EVT_NF, 0, 0);
	dc_link_event(dc, DC_EVT_NFIELD, 0, 0);
	dc_link_event(dc, DC_EVT_EOF, 0, 0);
	dc_link_event(dc, DC_EVT_EOFIELD, 0, 0);
	dc_link_event(dc, DC_EVT_NEW_CHAN, 0, 0);
	dc_link_event(dc, DC_EVT_NEW_ADDR, 0, 0);

	reg = readl(dc->base + DC_WR_CH_CONF);
	if (interlaced)
		reg |= DC_WR_CH_CONF_FIELD_MODE;
	else
		reg &= ~DC_WR_CH_CONF_FIELD_MODE;
	writel(reg, dc->base + DC_WR_CH_CONF);

	writel(0x0, dc->base + DC_WR_CH_ADDR);
	writel(width, priv->dc_reg + DC_DISP_CONF2(dc->di));

	return 0;
}

void ipu_dc_enable(struct ipu_soc *ipu)
{
	struct ipu_dc_priv *priv = ipu->dc_priv;

	mutex_lock(&priv->mutex);

	if (!priv->use_count)
		ipu_module_enable(priv->ipu, IPU_CONF_DC_EN);

	priv->use_count++;

	mutex_unlock(&priv->mutex);
}

void ipu_dc_enable_channel(struct ipu_dc *dc)
{
	u32 reg;

	reg = readl(dc->base + DC_WR_CH_CONF);
	reg |= DC_WR_CH_CONF_PROG_TYPE_NORMAL;
	writel(reg, dc->base + DC_WR_CH_CONF);
}

void ipu_dc_disable_channel(struct ipu_dc *dc)
{
	u32 val;

	val = readl(dc->base + DC_WR_CH_CONF);
	val &= ~DC_WR_CH_CONF_PROG_TYPE_MASK;
	writel(val, dc->base + DC_WR_CH_CONF);
}

void ipu_dc_disable(struct ipu_soc *ipu)
{
	struct ipu_dc_priv *priv = ipu->dc_priv;

	mutex_lock(&priv->mutex);

	priv->use_count--;
	if (!priv->use_count)
		ipu_module_disable(priv->ipu, IPU_CONF_DC_EN);

	if (priv->use_count < 0)
		priv->use_count = 0;

	mutex_unlock(&priv->mutex);
}

__attribute__((used)) static void ipu_dc_map_config(struct ipu_dc_priv *priv, enum ipu_dc_map map,
		int byte_num, int offset, int mask)
{
	int ptr = map * 3 + byte_num;
	u32 reg;

	reg = readl(priv->dc_reg + DC_MAP_CONF_VAL(ptr));
	reg &= ~(0xffff << (16 * (ptr & 0x1)));
	reg |= ((offset << 8) | mask) << (16 * (ptr & 0x1));
	writel(reg, priv->dc_reg + DC_MAP_CONF_VAL(ptr));

	reg = readl(priv->dc_reg + DC_MAP_CONF_PTR(map));
	reg &= ~(0x1f << ((16 * (map & 0x1)) + (5 * byte_num)));
	reg |= ptr << ((16 * (map & 0x1)) + (5 * byte_num));
	writel(reg, priv->dc_reg + DC_MAP_CONF_PTR(map));
}

__attribute__((used)) static void ipu_dc_map_clear(struct ipu_dc_priv *priv, int map)
{
	u32 reg = readl(priv->dc_reg + DC_MAP_CONF_PTR(map));

	writel(reg & ~(0xffff << (16 * (map & 0x1))),
		     priv->dc_reg + DC_MAP_CONF_PTR(map));
}

struct ipu_dc *ipu_dc_get(struct ipu_soc *ipu, int channel)
{
	struct ipu_dc_priv *priv = ipu->dc_priv;
	struct ipu_dc *dc;

	if (channel >= IPU_DC_NUM_CHANNELS)
		return ERR_PTR(-ENODEV);

	dc = &priv->channels[channel];

	mutex_lock(&priv->mutex);

	if (dc->in_use) {
		mutex_unlock(&priv->mutex);
		return ERR_PTR(-EBUSY);
	}

	dc->in_use = true;

	mutex_unlock(&priv->mutex);

	return dc;
}

void ipu_dc_put(struct ipu_dc *dc)
{
	struct ipu_dc_priv *priv = dc->priv;

	mutex_lock(&priv->mutex);
	dc->in_use = false;
	mutex_unlock(&priv->mutex);
}

int ipu_dc_init(struct ipu_soc *ipu, struct device *dev,
		unsigned long base, unsigned long template_base)
{
	struct ipu_dc_priv *priv;
	static int channel_offsets[] = { 0, 0x1c, 0x38, 0x54, 0x58, 0x5c,
		0x78, 0, 0x94, 0xb4};
	int i;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	mutex_init(&priv->mutex);

	priv->dev = dev;
	priv->ipu = ipu;
	priv->dc_reg = devm_ioremap(dev, base, PAGE_SIZE);
	priv->dc_tmpl_reg = devm_ioremap(dev, template_base, PAGE_SIZE);
	if (!priv->dc_reg || !priv->dc_tmpl_reg)
		return -ENOMEM;

	for (i = 0; i < IPU_DC_NUM_CHANNELS; i++) {
		priv->channels[i].chno = i;
		priv->channels[i].priv = priv;
		priv->channels[i].base = priv->dc_reg + channel_offsets[i];
	}

	writel(DC_WR_CH_CONF_WORD_SIZE_24 | DC_WR_CH_CONF_DISP_ID_PARALLEL(1) |
			DC_WR_CH_CONF_PROG_DI_ID,
			priv->channels[1].base + DC_WR_CH_CONF);
	writel(DC_WR_CH_CONF_WORD_SIZE_24 | DC_WR_CH_CONF_DISP_ID_PARALLEL(0),
			priv->channels[5].base + DC_WR_CH_CONF);

	writel(DC_GEN_SYNC_1_6_SYNC | DC_GEN_SYNC_PRIORITY_1,
		priv->dc_reg + DC_GEN);

	ipu->dc_priv = priv;

	dev_dbg(dev, "DC base: 0x%08lx template base: 0x%08lx\n",
			base, template_base);

	/* rgb24 */
	ipu_dc_map_clear(priv, IPU_DC_MAP_RGB24);
	ipu_dc_map_config(priv, IPU_DC_MAP_RGB24, 0, 7, 0xff); /* blue */
	ipu_dc_map_config(priv, IPU_DC_MAP_RGB24, 1, 15, 0xff); /* green */
	ipu_dc_map_config(priv, IPU_DC_MAP_RGB24, 2, 23, 0xff); /* red */

	/* rgb565 */
	ipu_dc_map_clear(priv, IPU_DC_MAP_RGB565);
	ipu_dc_map_config(priv, IPU_DC_MAP_RGB565, 0, 4, 0xf8); /* blue */
	ipu_dc_map_config(priv, IPU_DC_MAP_RGB565, 1, 10, 0xfc); /* green */
	ipu_dc_map_config(priv, IPU_DC_MAP_RGB565, 2, 15, 0xf8); /* red */

	/* gbr24 */
	ipu_dc_map_clear(priv, IPU_DC_MAP_GBR24);
	ipu_dc_map_config(priv, IPU_DC_MAP_GBR24, 2, 15, 0xff); /* green */
	ipu_dc_map_config(priv, IPU_DC_MAP_GBR24, 1, 7, 0xff); /* blue */
	ipu_dc_map_config(priv, IPU_DC_MAP_GBR24, 0, 23, 0xff); /* red */

	/* bgr666 */
	ipu_dc_map_clear(priv, IPU_DC_MAP_BGR666);
	ipu_dc_map_config(priv, IPU_DC_MAP_BGR666, 0, 5, 0xfc); /* blue */
	ipu_dc_map_config(priv, IPU_DC_MAP_BGR666, 1, 11, 0xfc); /* green */
	ipu_dc_map_config(priv, IPU_DC_MAP_BGR666, 2, 17, 0xfc); /* red */

	/* lvds666 */
	ipu_dc_map_clear(priv, IPU_DC_MAP_LVDS666);
	ipu_dc_map_config(priv, IPU_DC_MAP_LVDS666, 0, 5, 0xfc); /* blue */
	ipu_dc_map_config(priv, IPU_DC_MAP_LVDS666, 1, 13, 0xfc); /* green */
	ipu_dc_map_config(priv, IPU_DC_MAP_LVDS666, 2, 21, 0xfc); /* red */

	/* bgr24 */
	ipu_dc_map_clear(priv, IPU_DC_MAP_BGR24);
	ipu_dc_map_config(priv, IPU_DC_MAP_BGR24, 2, 7, 0xff); /* red */
	ipu_dc_map_config(priv, IPU_DC_MAP_BGR24, 1, 15, 0xff); /* green */
	ipu_dc_map_config(priv, IPU_DC_MAP_BGR24, 0, 23, 0xff); /* blue */

	return 0;
}

void ipu_dc_exit(struct ipu_soc *ipu)
{
}

