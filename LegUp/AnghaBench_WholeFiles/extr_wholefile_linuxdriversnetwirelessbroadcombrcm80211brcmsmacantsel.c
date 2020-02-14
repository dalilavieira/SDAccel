#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint ;
typedef  size_t u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct ssb_sprom {int antswitch; int ant_available_bg; int ant_available_a; } ;
struct sk_buff {int dummy; } ;
struct device {int dummy; } ;
struct brcms_info {int dummy; } ;
struct brcms_c_info {TYPE_4__* hw; TYPE_2__* pub; } ;
struct brcms_antselcfg {size_t* ant_config; scalar_t__ num_antcfg; } ;
struct antsel_info {scalar_t__ antsel_type; int antsel_avail; int antsel_antswitch; struct brcms_antselcfg antcfg_11n; struct brcms_antselcfg antcfg_cur; struct brcms_c_info* wlc; TYPE_2__* pub; } ;
struct TYPE_9__ {TYPE_3__* d11core; } ;
struct TYPE_8__ {TYPE_1__* bus; } ;
struct TYPE_7__ {int sromrev; int boardflags2; } ;
struct TYPE_6__ {struct ssb_sprom sprom; } ;

/* Variables and functions */
 scalar_t__ ANTSEL_2x3 ; 
 scalar_t__ ANTSEL_2x4 ; 
 scalar_t__ ANTSEL_NA ; 
#define  ANTSWITCH_TYPE_1 130 
#define  ANTSWITCH_TYPE_2 129 
#define  ANTSWITCH_TYPE_3 128 
 size_t ANT_SELCFG_AUTO ; 
 void* ANT_SELCFG_DEF_2x2 ; 
 size_t ANT_SELCFG_DEF_2x3 ; 
 void* ANT_SELCFG_DEF_2x4 ; 
 scalar_t__ ANT_SELCFG_NUM_2x3 ; 
 scalar_t__ ANT_SELCFG_NUM_2x4 ; 
 size_t ANT_SELCFG_RX_DEF ; 
 size_t ANT_SELCFG_RX_UNICAST ; 
 size_t ANT_SELCFG_TX_DEF ; 
 size_t ANT_SELCFG_TX_UNICAST ; 
 int BFL2_2X4_DIV ; 
 size_t BRCMS_ANTIDX_11N (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BRCMS_ANTSEL_11N (size_t) ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  M_MIMO_ANTSEL_RXDFLT ; 
 int /*<<< orphan*/  M_MIMO_ANTSEL_TXDFLT ; 
 int /*<<< orphan*/  brcms_b_antsel_type_set (TYPE_4__*,scalar_t__) ; 
 int /*<<< orphan*/  brcms_b_write_shm (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  brcms_err (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  kfree (struct antsel_info*) ; 
 struct antsel_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 size_t* mimo_2x3_div_antselid_tbl ; 
 int* mimo_2x3_div_antselpat_tbl ; 
 size_t* mimo_2x4_div_antselid_tbl ; 
 int* mimo_2x4_div_antselpat_tbl ; 

__attribute__((used)) static inline void dma_spin_for_len(uint len, struct sk_buff *head)
{
#if defined(CONFIG_BCM47XX)
	if (!len) {
		while (!(len = *(u16 *) KSEG1ADDR(head->data)))
			udelay(1);

		*(u16 *) (head->data) = cpu_to_le16((u16) len);
	}
#endif				/* defined(CONFIG_BCM47XX) */
}

__attribute__((used)) static inline void brcms_led_unregister(struct brcms_info *wl) {}

__attribute__((used)) static inline int brcms_led_register(struct brcms_info *wl)
{
	return -ENOTSUPP;
}

void __brcms_dbg(struct device *dev, u32 level, const char *func,
		 const char *fmt, ...)
{
}

__attribute__((used)) static void
brcms_c_antsel_init_cfg(struct antsel_info *asi, struct brcms_antselcfg *antsel,
		    bool auto_sel)
{
	if (asi->antsel_type == ANTSEL_2x3) {
		u8 antcfg_def = ANT_SELCFG_DEF_2x3 |
		    ((asi->antsel_avail && auto_sel) ? ANT_SELCFG_AUTO : 0);
		antsel->ant_config[ANT_SELCFG_TX_DEF] = antcfg_def;
		antsel->ant_config[ANT_SELCFG_TX_UNICAST] = antcfg_def;
		antsel->ant_config[ANT_SELCFG_RX_DEF] = antcfg_def;
		antsel->ant_config[ANT_SELCFG_RX_UNICAST] = antcfg_def;
		antsel->num_antcfg = ANT_SELCFG_NUM_2x3;

	} else if (asi->antsel_type == ANTSEL_2x4) {

		antsel->ant_config[ANT_SELCFG_TX_DEF] = ANT_SELCFG_DEF_2x4;
		antsel->ant_config[ANT_SELCFG_TX_UNICAST] = ANT_SELCFG_DEF_2x4;
		antsel->ant_config[ANT_SELCFG_RX_DEF] = ANT_SELCFG_DEF_2x4;
		antsel->ant_config[ANT_SELCFG_RX_UNICAST] = ANT_SELCFG_DEF_2x4;
		antsel->num_antcfg = ANT_SELCFG_NUM_2x4;

	} else {		/* no antenna selection available */

		antsel->ant_config[ANT_SELCFG_TX_DEF] = ANT_SELCFG_DEF_2x2;
		antsel->ant_config[ANT_SELCFG_TX_UNICAST] = ANT_SELCFG_DEF_2x2;
		antsel->ant_config[ANT_SELCFG_RX_DEF] = ANT_SELCFG_DEF_2x2;
		antsel->ant_config[ANT_SELCFG_RX_UNICAST] = ANT_SELCFG_DEF_2x2;
		antsel->num_antcfg = 0;
	}
}

struct antsel_info *brcms_c_antsel_attach(struct brcms_c_info *wlc)
{
	struct antsel_info *asi;
	struct ssb_sprom *sprom = &wlc->hw->d11core->bus->sprom;

	asi = kzalloc(sizeof(struct antsel_info), GFP_ATOMIC);
	if (!asi)
		return NULL;

	asi->wlc = wlc;
	asi->pub = wlc->pub;
	asi->antsel_type = ANTSEL_NA;
	asi->antsel_avail = false;
	asi->antsel_antswitch = sprom->antswitch;

	if ((asi->pub->sromrev >= 4) && (asi->antsel_antswitch != 0)) {
		switch (asi->antsel_antswitch) {
		case ANTSWITCH_TYPE_1:
		case ANTSWITCH_TYPE_2:
		case ANTSWITCH_TYPE_3:
			/* 4321/2 board with 2x3 switch logic */
			asi->antsel_type = ANTSEL_2x3;
			/* Antenna selection availability */
			if ((sprom->ant_available_bg == 7) ||
			    (sprom->ant_available_a == 7)) {
				asi->antsel_avail = true;
			} else if (
				sprom->ant_available_bg == 3 ||
				sprom->ant_available_a == 3) {
				asi->antsel_avail = false;
			} else {
				asi->antsel_avail = false;
				brcms_err(wlc->hw->d11core,
					  "antsel_attach: 2o3 "
					  "board cfg invalid\n");
			}

			break;
		default:
			break;
		}
	} else if ((asi->pub->sromrev == 4) &&
		   (sprom->ant_available_bg == 7) &&
		   (sprom->ant_available_a == 0)) {
		/* hack to match old 4321CB2 cards with 2of3 antenna switch */
		asi->antsel_type = ANTSEL_2x3;
		asi->antsel_avail = true;
	} else if (asi->pub->boardflags2 & BFL2_2X4_DIV) {
		asi->antsel_type = ANTSEL_2x4;
		asi->antsel_avail = true;
	}

	/* Set the antenna selection type for the low driver */
	brcms_b_antsel_type_set(wlc->hw, asi->antsel_type);

	/* Init (auto/manual) antenna selection */
	brcms_c_antsel_init_cfg(asi, &asi->antcfg_11n, true);
	brcms_c_antsel_init_cfg(asi, &asi->antcfg_cur, true);

	return asi;
}

void brcms_c_antsel_detach(struct antsel_info *asi)
{
	kfree(asi);
}

__attribute__((used)) static u16 brcms_c_antsel_antcfg2antsel(struct antsel_info *asi, u8 ant_cfg)
{
	u8 idx = BRCMS_ANTIDX_11N(BRCMS_ANTSEL_11N(ant_cfg));
	u16 mimo_antsel = 0;

	if (asi->antsel_type == ANTSEL_2x4) {
		/* 2x4 antenna diversity board, 4 cfgs: 0-2 0-3 1-2 1-3 */
		mimo_antsel = (mimo_2x4_div_antselpat_tbl[idx] & 0xf);
		return mimo_antsel;

	} else if (asi->antsel_type == ANTSEL_2x3) {
		/* 2x3 antenna selection, 3 cfgs: 0-1 0-2 2-1 */
		mimo_antsel = (mimo_2x3_div_antselpat_tbl[idx] & 0xf);
		return mimo_antsel;
	}

	return mimo_antsel;
}

__attribute__((used)) static int brcms_c_antsel_cfgupd(struct antsel_info *asi,
				 struct brcms_antselcfg *antsel)
{
	struct brcms_c_info *wlc = asi->wlc;
	u8 ant_cfg;
	u16 mimo_antsel;

	/* 1) Update TX antconfig for all frames that are not unicast data
	 *    (aka default TX)
	 */
	ant_cfg = antsel->ant_config[ANT_SELCFG_TX_DEF];
	mimo_antsel = brcms_c_antsel_antcfg2antsel(asi, ant_cfg);
	brcms_b_write_shm(wlc->hw, M_MIMO_ANTSEL_TXDFLT, mimo_antsel);
	/*
	 * Update driver stats for currently selected
	 * default tx/rx antenna config
	 */
	asi->antcfg_cur.ant_config[ANT_SELCFG_TX_DEF] = ant_cfg;

	/* 2) Update RX antconfig for all frames that are not unicast data
	 *    (aka default RX)
	 */
	ant_cfg = antsel->ant_config[ANT_SELCFG_RX_DEF];
	mimo_antsel = brcms_c_antsel_antcfg2antsel(asi, ant_cfg);
	brcms_b_write_shm(wlc->hw, M_MIMO_ANTSEL_RXDFLT, mimo_antsel);
	/*
	 * Update driver stats for currently selected
	 * default tx/rx antenna config
	 */
	asi->antcfg_cur.ant_config[ANT_SELCFG_RX_DEF] = ant_cfg;

	return 0;
}

void brcms_c_antsel_init(struct antsel_info *asi)
{
	if ((asi->antsel_type == ANTSEL_2x3) ||
	    (asi->antsel_type == ANTSEL_2x4))
		brcms_c_antsel_cfgupd(asi, &asi->antcfg_11n);
}

__attribute__((used)) static u8 brcms_c_antsel_id2antcfg(struct antsel_info *asi, u8 id)
{
	u8 antcfg = ANT_SELCFG_DEF_2x2;

	if (asi->antsel_type == ANTSEL_2x4) {
		/* 2x4 antenna diversity board, 4 cfgs: 0-2 0-3 1-2 1-3 */
		antcfg = (((id & 0x2) << 3) | ((id & 0x1) + 2));
		return antcfg;

	} else if (asi->antsel_type == ANTSEL_2x3) {
		/* 2x3 antenna selection, 3 cfgs: 0-1 0-2 2-1 */
		antcfg = (((id & 0x02) << 4) | ((id & 0x1) + 1));
		return antcfg;
	}

	return antcfg;
}

void
brcms_c_antsel_antcfg_get(struct antsel_info *asi, bool usedef, bool sel,
		      u8 antselid, u8 fbantselid, u8 *antcfg,
		      u8 *fbantcfg)
{
	u8 ant;

	/* if use default, assign it and return */
	if (usedef) {
		*antcfg = asi->antcfg_11n.ant_config[ANT_SELCFG_TX_DEF];
		*fbantcfg = *antcfg;
		return;
	}

	if (!sel) {
		*antcfg = asi->antcfg_11n.ant_config[ANT_SELCFG_TX_UNICAST];
		*fbantcfg = *antcfg;

	} else {
		ant = asi->antcfg_11n.ant_config[ANT_SELCFG_TX_UNICAST];
		if ((ant & ANT_SELCFG_AUTO) == ANT_SELCFG_AUTO) {
			*antcfg = brcms_c_antsel_id2antcfg(asi, antselid);
			*fbantcfg = brcms_c_antsel_id2antcfg(asi, fbantselid);
		} else {
			*antcfg =
			    asi->antcfg_11n.ant_config[ANT_SELCFG_TX_UNICAST];
			*fbantcfg = *antcfg;
		}
	}
	return;
}

u8 brcms_c_antsel_antsel2id(struct antsel_info *asi, u16 antsel)
{
	u8 antselid = 0;

	if (asi->antsel_type == ANTSEL_2x4) {
		/* 2x4 antenna diversity board, 4 cfgs: 0-2 0-3 1-2 1-3 */
		antselid = mimo_2x4_div_antselid_tbl[(antsel & 0xf)];
		return antselid;

	} else if (asi->antsel_type == ANTSEL_2x3) {
		/* 2x3 antenna selection, 3 cfgs: 0-1 0-2 2-1 */
		antselid = mimo_2x3_div_antselid_tbl[(antsel & 0xf)];
		return antselid;
	}

	return antselid;
}

