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
typedef  int u32 ;
struct ath_ps_ops {int dummy; } ;
struct ath_cycle_counters {int cycles; int rx_busy; int rx_frame; int tx_frame; } ;
struct TYPE_2__ {int cycles; int rx_busy; int rx_frame; int tx_frame; } ;
struct ath_common {int clockrate; struct ath_cycle_counters cc_ani; TYPE_1__ cc_survey; void* ah; scalar_t__ bssidmask; scalar_t__ macaddr; struct ath_ps_ops const* ps_ops; } ;
typedef  int int32_t ;
typedef  enum nl80211_iftype { ____Placeholder_nl80211_iftype } nl80211_iftype ;
typedef  enum ath_bus_type { ____Placeholder_ath_bus_type } ath_bus_type ;
typedef  enum ATH_DEBUG { ____Placeholder_ATH_DEBUG } ATH_DEBUG ;

/* Variables and functions */
 int /*<<< orphan*/  AR_BSSMSKL ; 
 int /*<<< orphan*/  AR_BSSMSKU ; 
 int /*<<< orphan*/  AR_CCCNT ; 
 int /*<<< orphan*/  AR_MIBC ; 
 int AR_MIBC_FMC ; 
 int /*<<< orphan*/  AR_RCCNT ; 
 int /*<<< orphan*/  AR_RFCNT ; 
 int /*<<< orphan*/  AR_STA_ID0 ; 
 int /*<<< orphan*/  AR_STA_ID1 ; 
 int AR_STA_ID1_SADH_MASK ; 
 int /*<<< orphan*/  AR_TFCNT ; 
 int REG_READ (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_WRITE (void*,int /*<<< orphan*/ ,int) ; 
 char const** ath_bus_type_strings ; 
 int get_unaligned_le16 (scalar_t__) ; 
 int get_unaligned_le32 (scalar_t__) ; 
 int /*<<< orphan*/  memset (struct ath_cycle_counters*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline const struct ath_ps_ops *ath_ps_ops(struct ath_common *common)
{
	return common->ps_ops;
}

__attribute__((used)) static inline  __attribute__ ((format (printf, 3, 4)))
void _ath_dbg(struct ath_common *common, enum ATH_DEBUG dbg_mask,
	     const char *fmt, ...)
{
}

__attribute__((used)) static inline const char *ath_opmode_to_string(enum nl80211_iftype opmode)
{
	return "UNKNOWN";
}

__attribute__((used)) static inline const char *ath_bus_type_to_string(enum ath_bus_type bustype)
{
	return ath_bus_type_strings[bustype];
}

void ath_hw_setbssidmask(struct ath_common *common)
{
	void *ah = common->ah;
	u32 id1;

	REG_WRITE(ah, AR_STA_ID0, get_unaligned_le32(common->macaddr));
	id1 = REG_READ(ah, AR_STA_ID1) & ~AR_STA_ID1_SADH_MASK;
	id1 |= get_unaligned_le16(common->macaddr + 4);
	REG_WRITE(ah, AR_STA_ID1, id1);

	REG_WRITE(ah, AR_BSSMSKL, get_unaligned_le32(common->bssidmask));
	REG_WRITE(ah, AR_BSSMSKU, get_unaligned_le16(common->bssidmask + 4));
}

void ath_hw_cycle_counters_update(struct ath_common *common)
{
	u32 cycles, busy, rx, tx;
	void *ah = common->ah;

	/* freeze */
	REG_WRITE(ah, AR_MIBC, AR_MIBC_FMC);

	/* read */
	cycles = REG_READ(ah, AR_CCCNT);
	busy = REG_READ(ah, AR_RCCNT);
	rx = REG_READ(ah, AR_RFCNT);
	tx = REG_READ(ah, AR_TFCNT);

	/* clear */
	REG_WRITE(ah, AR_CCCNT, 0);
	REG_WRITE(ah, AR_RFCNT, 0);
	REG_WRITE(ah, AR_RCCNT, 0);
	REG_WRITE(ah, AR_TFCNT, 0);

	/* unfreeze */
	REG_WRITE(ah, AR_MIBC, 0);

	/* update all cycle counters here */
	common->cc_ani.cycles += cycles;
	common->cc_ani.rx_busy += busy;
	common->cc_ani.rx_frame += rx;
	common->cc_ani.tx_frame += tx;

	common->cc_survey.cycles += cycles;
	common->cc_survey.rx_busy += busy;
	common->cc_survey.rx_frame += rx;
	common->cc_survey.tx_frame += tx;
}

int32_t ath_hw_get_listen_time(struct ath_common *common)
{
	struct ath_cycle_counters *cc = &common->cc_ani;
	int32_t listen_time;

	listen_time = (cc->cycles - cc->rx_frame - cc->tx_frame) /
		      (common->clockrate * 1000);

	memset(cc, 0, sizeof(*cc));

	return listen_time;
}

