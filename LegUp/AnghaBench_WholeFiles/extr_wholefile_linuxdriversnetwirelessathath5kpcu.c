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
typedef  size_t u8 ;
typedef  int u64 ;
typedef  unsigned int u32 ;
typedef  unsigned int u16 ;
struct ieee80211_rate {int bitrate; int flags; int /*<<< orphan*/  hw_value; } ;
struct ieee80211_channel {int /*<<< orphan*/  band; int /*<<< orphan*/  hw_value; } ;
struct ath_regulatory {int dummy; } ;
struct ath_ps_ops {int dummy; } ;
struct ath_common {size_t const* macaddr; size_t const* curbssid; int curaid; size_t const* bssidmask; TYPE_1__* bus_ops; struct ath_regulatory regulatory; struct ath_ps_ops const* ps_ops; } ;
struct ath5k_statistics {unsigned int ack_fail; unsigned int rts_fail; unsigned int rts_ok; unsigned int fcs_error; unsigned int beacons; } ;
struct ath5k_hw {unsigned int iobase; int ah_bwmode; scalar_t__ ah_version; int opmode; size_t ah_coverage_class; scalar_t__ ah_mac_srev; scalar_t__ ah_ack_bitrate_high; scalar_t__ nvifs; TYPE_2__* sbands; struct ath5k_statistics stats; struct ieee80211_channel* ah_current_channel; int /*<<< orphan*/  ah_short_slot; int /*<<< orphan*/  hw; struct ath_common common; } ;
struct ath5k_buf {int dummy; } ;
typedef  enum nl80211_iftype { ____Placeholder_nl80211_iftype } nl80211_iftype ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
typedef  enum ath_bus_type { ____Placeholder_ath_bus_type } ath_bus_type ;
typedef  enum ATH_DEBUG { ____Placeholder_ATH_DEBUG } ATH_DEBUG ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_4__ {unsigned int n_bitrates; struct ieee80211_rate* bitrates; } ;
struct TYPE_3__ {int ath_bus_type; int (* eeprom_read ) (struct ath_common*,unsigned int,unsigned int*) ;int /*<<< orphan*/  (* read_cachesize ) (struct ath_common*,int*) ;} ;

/* Variables and functions */
 unsigned int AR5K_ACK_FAIL ; 
 scalar_t__ AR5K_AR5210 ; 
 scalar_t__ AR5K_AR5212 ; 
 unsigned int AR5K_BCR ; 
 unsigned int AR5K_BCR_ADHOC ; 
 unsigned int AR5K_BCR_AP ; 
 unsigned int AR5K_BEACON ; 
 unsigned int AR5K_BEACON_CNT ; 
 unsigned int AR5K_BEACON_ENABLE ; 
 unsigned int AR5K_BEACON_PERIOD ; 
 unsigned int AR5K_BEACON_RESET_TSF ; 
 int /*<<< orphan*/  AR5K_BEACON_TIM ; 
 unsigned int AR5K_BSS_ID0 ; 
 unsigned int AR5K_BSS_ID1 ; 
 int AR5K_BSS_ID1_AID_S ; 
#define  AR5K_BWMODE_10MHZ 136 
#define  AR5K_BWMODE_40MHZ 135 
#define  AR5K_BWMODE_5MHZ 134 
#define  AR5K_BWMODE_DEFAULT 133 
 unsigned int AR5K_CFG ; 
 unsigned int AR5K_CFG_IBSS ; 
 unsigned int AR5K_DIAG_SW ; 
 unsigned int AR5K_DIAG_SW_DIS_RX ; 
 unsigned int AR5K_FCS_FAIL ; 
 int AR5K_INIT_OFDM_PLCP_BITS ; 
 int AR5K_INIT_OFDM_PREAMBLE_TIME_MIN ; 
 int AR5K_INIT_OFDM_PREAMPLE_TIME ; 
 int AR5K_INIT_OFDM_SYMBOL_TIME ; 
 unsigned int AR5K_INIT_SIFS_DEFAULT_A ; 
 void* AR5K_INIT_SIFS_DEFAULT_BG ; 
 void* AR5K_INIT_SIFS_HALF_RATE ; 
 void* AR5K_INIT_SIFS_QUARTER_RATE ; 
 void* AR5K_INIT_SIFS_TURBO ; 
 unsigned int AR5K_INIT_SLOT_TIME_B ; 
 unsigned int AR5K_INIT_SLOT_TIME_DEFAULT ; 
 unsigned int AR5K_INIT_SLOT_TIME_HALF_RATE ; 
 unsigned int AR5K_INIT_SLOT_TIME_QUARTER_RATE ; 
 unsigned int AR5K_INIT_SLOT_TIME_TURBO ; 
 unsigned int AR5K_ISR ; 
 unsigned int AR5K_ISR_BMISS ; 
 unsigned int AR5K_MCAST_FILTER0 ; 
 unsigned int AR5K_MCAST_FILTER1 ; 
 unsigned int AR5K_MIC_QOS_CTL ; 
 unsigned int AR5K_MIC_QOS_SEL ; 
 int /*<<< orphan*/  AR5K_MODE_11B ; 
 unsigned int AR5K_PHY_ERR_FIL ; 
 unsigned int AR5K_PHY_ERR_FIL_CCK ; 
 unsigned int AR5K_PHY_ERR_FIL_OFDM ; 
 unsigned int AR5K_PHY_ERR_FIL_RADAR ; 
 unsigned int AR5K_PISR ; 
 unsigned int AR5K_QOS_NOACK ; 
 int /*<<< orphan*/  AR5K_QOS_NOACK_2BIT_VALUES ; 
 int /*<<< orphan*/  AR5K_QOS_NOACK_BIT_OFFSET ; 
 int /*<<< orphan*/  AR5K_QOS_NOACK_BYTE_OFFSET ; 
 unsigned int AR5K_RATE_DUR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AR5K_REG_DISABLE_BITS (struct ath5k_hw*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  AR5K_REG_ENABLE_BITS (struct ath5k_hw*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  AR5K_REG_MS (int,int /*<<< orphan*/ ) ; 
 unsigned int AR5K_REG_SM (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AR5K_REG_WRITE_BITS (struct ath5k_hw*,unsigned int,int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int AR5K_RSSI_THR ; 
 unsigned int AR5K_RSSI_THR_BMISS_S ; 
 unsigned int AR5K_RTS_FAIL ; 
 unsigned int AR5K_RTS_OK ; 
 unsigned int AR5K_RXCFG ; 
 unsigned int AR5K_RXCFG_ZLFDMA ; 
 unsigned int AR5K_RX_FILTER ; 
 unsigned int AR5K_RX_FILTER_PHYERR ; 
 unsigned int AR5K_RX_FILTER_PROM ; 
 unsigned int AR5K_RX_FILTER_RADARERR ; 
 int AR5K_SET_SHORT_PREAMBLE ; 
 scalar_t__ AR5K_SREV_AR2413 ; 
 unsigned int AR5K_STA_ID0 ; 
 unsigned int AR5K_STA_ID1 ; 
 unsigned int AR5K_STA_ID1_ACKCTS_6MB ; 
 unsigned int AR5K_STA_ID1_ADHOC ; 
 unsigned int AR5K_STA_ID1_AP ; 
 unsigned int AR5K_STA_ID1_BASE_RATE_11B ; 
 unsigned int AR5K_STA_ID1_KEYSRCH_MODE ; 
 unsigned int AR5K_STA_ID1_NO_PSPOLL ; 
 unsigned int AR5K_STA_ID1_PCF ; 
 unsigned int AR5K_STA_ID1_PWR_SV ; 
 unsigned int AR5K_TIMER0 ; 
 unsigned int AR5K_TIMER1 ; 
 unsigned int AR5K_TIMER2 ; 
 unsigned int AR5K_TIMER3 ; 
 unsigned int AR5K_TIME_OUT ; 
 int /*<<< orphan*/  AR5K_TIME_OUT_ACK ; 
 int /*<<< orphan*/  AR5K_TIME_OUT_CTS ; 
 unsigned int AR5K_TSF_L32 ; 
 unsigned int AR5K_TSF_U32 ; 
 unsigned int AR5K_TUNE_BMISS_THRES ; 
 unsigned int AR5K_TUNE_DMA_BEACON_RESP ; 
 unsigned int AR5K_TUNE_RSSI_THRES ; 
 int /*<<< orphan*/  AR5K_TUNE_SW_BEACON_RESP ; 
 unsigned int AR5K_TXCFG ; 
 unsigned int AR5K_TXCFG_ADHOC_BCN_ATIM ; 
 unsigned int ATH5K_DEBUG_MODE ; 
 int ATH5K_MAX_TSF_READ ; 
 int DIV_ROUND_UP (int,int) ; 
 int EINVAL ; 
 int /*<<< orphan*/  ETH_ALEN ; 
 int IEEE80211_RATE_SHORT_PREAMBLE ; 
 size_t NL80211_BAND_2GHZ ; 
 int /*<<< orphan*/  NL80211_BAND_5GHZ ; 
#define  NL80211_IFTYPE_ADHOC 132 
#define  NL80211_IFTYPE_AP 131 
#define  NL80211_IFTYPE_MESH_POINT 130 
#define  NL80211_IFTYPE_MONITOR 129 
#define  NL80211_IFTYPE_STATION 128 
 int /*<<< orphan*/  WARN_ON (int) ; 
 size_t* ack_rates_high ; 
 unsigned int ath5k_hw_clocktoh (struct ath5k_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath5k_hw_disable_pspoll (struct ath5k_hw*) ; 
 int /*<<< orphan*/  ath5k_hw_enable_pspoll (struct ath5k_hw*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 unsigned int ath5k_hw_htoclock (struct ath5k_hw*,unsigned int) ; 
 int /*<<< orphan*/  ath5k_hw_set_ifs_intervals (struct ath5k_hw*,int) ; 
 char const** ath_bus_type_strings ; 
 int /*<<< orphan*/  ath_hw_setbssidmask (struct ath_common*) ; 
 int get_unaligned_le16 (size_t const*) ; 
 unsigned int get_unaligned_le32 (size_t const*) ; 
 int /*<<< orphan*/  ieee80211_generic_frame_duration (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int,struct ieee80211_rate*) ; 
 unsigned int ioread32 (unsigned int) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,unsigned int) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  memcpy (size_t const*,size_t const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct ath_common*,int*) ; 
 int stub2 (struct ath_common*,unsigned int,unsigned int*) ; 

void
ATH5K_DBG(struct ath5k_hw *ah, unsigned int m, const char *fmt, ...) {}

void
ATH5K_DBG_UNLIMIT(struct ath5k_hw *ah, unsigned int m, const char *fmt, ...)
{}

__attribute__((used)) static inline void
ath5k_debug_init_device(struct ath5k_hw *ah) {}

__attribute__((used)) static inline void
ath5k_debug_printrxbuffs(struct ath5k_hw *ah) {}

__attribute__((used)) static inline void
ath5k_debug_dump_bands(struct ath5k_hw *ah) {}

__attribute__((used)) static inline void
ath5k_debug_printtxbuf(struct ath5k_hw *ah, struct ath5k_buf *bf) {}

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

__attribute__((used)) static inline struct ath_common *ath5k_hw_common(struct ath5k_hw *ah)
{
	return &ah->common;
}

__attribute__((used)) static inline struct ath_regulatory *ath5k_hw_regulatory(struct ath5k_hw *ah)
{
	return &(ath5k_hw_common(ah)->regulatory);
}

__attribute__((used)) static inline u32 ath5k_hw_reg_read(struct ath5k_hw *ah, u16 reg)
{
	return ioread32(ah->iobase + reg);
}

__attribute__((used)) static inline void ath5k_hw_reg_write(struct ath5k_hw *ah, u32 val, u16 reg)
{
	iowrite32(val, ah->iobase + reg);
}

__attribute__((used)) static inline enum ath_bus_type ath5k_get_bus_type(struct ath5k_hw *ah)
{
	return ath5k_hw_common(ah)->bus_ops->ath_bus_type;
}

__attribute__((used)) static inline void ath5k_read_cachesize(struct ath_common *common, int *csz)
{
	common->bus_ops->read_cachesize(common, csz);
}

__attribute__((used)) static inline bool ath5k_hw_nvram_read(struct ath5k_hw *ah, u32 off, u16 *data)
{
	struct ath_common *common = ath5k_hw_common(ah);
	return common->bus_ops->eeprom_read(common, off, data);
}

__attribute__((used)) static inline u32 ath5k_hw_bitswap(u32 val, unsigned int bits)
{
	u32 retval = 0, bit, i;

	for (i = 0; i < bits; i++) {
		bit = (val >> i) & 1;
		retval = (retval << 1) | bit;
	}

	return retval;
}

int
ath5k_hw_get_frame_duration(struct ath5k_hw *ah, enum nl80211_band band,
		int len, struct ieee80211_rate *rate, bool shortpre)
{
	int sifs, preamble, plcp_bits, sym_time;
	int bitrate, bits, symbols, symbol_bits;
	int dur;

	/* Fallback */
	if (!ah->ah_bwmode) {
		__le16 raw_dur = ieee80211_generic_frame_duration(ah->hw,
					NULL, band, len, rate);

		/* subtract difference between long and short preamble */
		dur = le16_to_cpu(raw_dur);
		if (shortpre)
			dur -= 96;

		return dur;
	}

	bitrate = rate->bitrate;
	preamble = AR5K_INIT_OFDM_PREAMPLE_TIME;
	plcp_bits = AR5K_INIT_OFDM_PLCP_BITS;
	sym_time = AR5K_INIT_OFDM_SYMBOL_TIME;

	switch (ah->ah_bwmode) {
	case AR5K_BWMODE_40MHZ:
		sifs = AR5K_INIT_SIFS_TURBO;
		preamble = AR5K_INIT_OFDM_PREAMBLE_TIME_MIN;
		break;
	case AR5K_BWMODE_10MHZ:
		sifs = AR5K_INIT_SIFS_HALF_RATE;
		preamble *= 2;
		sym_time *= 2;
		bitrate = DIV_ROUND_UP(bitrate, 2);
		break;
	case AR5K_BWMODE_5MHZ:
		sifs = AR5K_INIT_SIFS_QUARTER_RATE;
		preamble *= 4;
		sym_time *= 4;
		bitrate = DIV_ROUND_UP(bitrate, 4);
		break;
	default:
		sifs = AR5K_INIT_SIFS_DEFAULT_BG;
		break;
	}

	bits = plcp_bits + (len << 3);
	/* Bit rate is in 100Kbits */
	symbol_bits = bitrate * sym_time;
	symbols = DIV_ROUND_UP(bits * 10, symbol_bits);

	dur = sifs + preamble + (sym_time * symbols);

	return dur;
}

unsigned int
ath5k_hw_get_default_slottime(struct ath5k_hw *ah)
{
	struct ieee80211_channel *channel = ah->ah_current_channel;
	unsigned int slot_time;

	switch (ah->ah_bwmode) {
	case AR5K_BWMODE_40MHZ:
		slot_time = AR5K_INIT_SLOT_TIME_TURBO;
		break;
	case AR5K_BWMODE_10MHZ:
		slot_time = AR5K_INIT_SLOT_TIME_HALF_RATE;
		break;
	case AR5K_BWMODE_5MHZ:
		slot_time = AR5K_INIT_SLOT_TIME_QUARTER_RATE;
		break;
	case AR5K_BWMODE_DEFAULT:
	default:
		slot_time = AR5K_INIT_SLOT_TIME_DEFAULT;
		if ((channel->hw_value == AR5K_MODE_11B) && !ah->ah_short_slot)
			slot_time = AR5K_INIT_SLOT_TIME_B;
		break;
	}

	return slot_time;
}

unsigned int
ath5k_hw_get_default_sifs(struct ath5k_hw *ah)
{
	struct ieee80211_channel *channel = ah->ah_current_channel;
	unsigned int sifs;

	switch (ah->ah_bwmode) {
	case AR5K_BWMODE_40MHZ:
		sifs = AR5K_INIT_SIFS_TURBO;
		break;
	case AR5K_BWMODE_10MHZ:
		sifs = AR5K_INIT_SIFS_HALF_RATE;
		break;
	case AR5K_BWMODE_5MHZ:
		sifs = AR5K_INIT_SIFS_QUARTER_RATE;
		break;
	case AR5K_BWMODE_DEFAULT:
	default:
		sifs = AR5K_INIT_SIFS_DEFAULT_BG;
		if (channel->band == NL80211_BAND_5GHZ)
			sifs = AR5K_INIT_SIFS_DEFAULT_A;
		break;
	}

	return sifs;
}

void
ath5k_hw_update_mib_counters(struct ath5k_hw *ah)
{
	struct ath5k_statistics *stats = &ah->stats;

	/* Read-And-Clear */
	stats->ack_fail += ath5k_hw_reg_read(ah, AR5K_ACK_FAIL);
	stats->rts_fail += ath5k_hw_reg_read(ah, AR5K_RTS_FAIL);
	stats->rts_ok += ath5k_hw_reg_read(ah, AR5K_RTS_OK);
	stats->fcs_error += ath5k_hw_reg_read(ah, AR5K_FCS_FAIL);
	stats->beacons += ath5k_hw_reg_read(ah, AR5K_BEACON_CNT);
}

__attribute__((used)) static inline void
ath5k_hw_write_rate_duration(struct ath5k_hw *ah)
{
	struct ieee80211_rate *rate;
	unsigned int i;
	/* 802.11g covers both OFDM and CCK */
	u8 band = NL80211_BAND_2GHZ;

	/* Write rate duration table */
	for (i = 0; i < ah->sbands[band].n_bitrates; i++) {
		u32 reg;
		u16 tx_time;

		if (ah->ah_ack_bitrate_high)
			rate = &ah->sbands[band].bitrates[ack_rates_high[i]];
		/* CCK -> 1Mb */
		else if (i < 4)
			rate = &ah->sbands[band].bitrates[0];
		/* OFDM -> 6Mb */
		else
			rate = &ah->sbands[band].bitrates[4];

		/* Set ACK timeout */
		reg = AR5K_RATE_DUR(rate->hw_value);

		/* An ACK frame consists of 10 bytes. If you add the FCS,
		 * which ieee80211_generic_frame_duration() adds,
		 * its 14 bytes. Note we use the control rate and not the
		 * actual rate for this rate. See mac80211 tx.c
		 * ieee80211_duration() for a brief description of
		 * what rate we should choose to TX ACKs. */
		tx_time = ath5k_hw_get_frame_duration(ah, band, 10,
					rate, false);

		ath5k_hw_reg_write(ah, tx_time, reg);

		if (!(rate->flags & IEEE80211_RATE_SHORT_PREAMBLE))
			continue;

		tx_time = ath5k_hw_get_frame_duration(ah, band, 10, rate, true);
		ath5k_hw_reg_write(ah, tx_time,
			reg + (AR5K_SET_SHORT_PREAMBLE << 2));
	}
}

__attribute__((used)) static int
ath5k_hw_set_ack_timeout(struct ath5k_hw *ah, unsigned int timeout)
{
	if (ath5k_hw_clocktoh(ah, AR5K_REG_MS(0xffffffff, AR5K_TIME_OUT_ACK))
			<= timeout)
		return -EINVAL;

	AR5K_REG_WRITE_BITS(ah, AR5K_TIME_OUT, AR5K_TIME_OUT_ACK,
		ath5k_hw_htoclock(ah, timeout));

	return 0;
}

__attribute__((used)) static int
ath5k_hw_set_cts_timeout(struct ath5k_hw *ah, unsigned int timeout)
{
	if (ath5k_hw_clocktoh(ah, AR5K_REG_MS(0xffffffff, AR5K_TIME_OUT_CTS))
			<= timeout)
		return -EINVAL;

	AR5K_REG_WRITE_BITS(ah, AR5K_TIME_OUT, AR5K_TIME_OUT_CTS,
			ath5k_hw_htoclock(ah, timeout));

	return 0;
}

int
ath5k_hw_set_lladdr(struct ath5k_hw *ah, const u8 *mac)
{
	struct ath_common *common = ath5k_hw_common(ah);
	u32 low_id, high_id;
	u32 pcu_reg;

	/* Set new station ID */
	memcpy(common->macaddr, mac, ETH_ALEN);

	pcu_reg = ath5k_hw_reg_read(ah, AR5K_STA_ID1) & 0xffff0000;

	low_id = get_unaligned_le32(mac);
	high_id = get_unaligned_le16(mac + 4);

	ath5k_hw_reg_write(ah, low_id, AR5K_STA_ID0);
	ath5k_hw_reg_write(ah, pcu_reg | high_id, AR5K_STA_ID1);

	return 0;
}

void
ath5k_hw_set_bssid(struct ath5k_hw *ah)
{
	struct ath_common *common = ath5k_hw_common(ah);
	u16 tim_offset = 0;

	/*
	 * Set BSSID mask on 5212
	 */
	if (ah->ah_version == AR5K_AR5212)
		ath_hw_setbssidmask(common);

	/*
	 * Set BSSID
	 */
	ath5k_hw_reg_write(ah,
			   get_unaligned_le32(common->curbssid),
			   AR5K_BSS_ID0);
	ath5k_hw_reg_write(ah,
			   get_unaligned_le16(common->curbssid + 4) |
			   ((common->curaid & 0x3fff) << AR5K_BSS_ID1_AID_S),
			   AR5K_BSS_ID1);

	if (common->curaid == 0) {
		ath5k_hw_disable_pspoll(ah);
		return;
	}

	AR5K_REG_WRITE_BITS(ah, AR5K_BEACON, AR5K_BEACON_TIM,
			    tim_offset ? tim_offset + 4 : 0);

	ath5k_hw_enable_pspoll(ah, NULL, 0);
}

void
ath5k_hw_set_bssid_mask(struct ath5k_hw *ah, const u8 *mask)
{
	struct ath_common *common = ath5k_hw_common(ah);

	/* Cache bssid mask so that we can restore it
	 * on reset */
	memcpy(common->bssidmask, mask, ETH_ALEN);
	if (ah->ah_version == AR5K_AR5212)
		ath_hw_setbssidmask(common);
}

void
ath5k_hw_set_mcast_filter(struct ath5k_hw *ah, u32 filter0, u32 filter1)
{
	ath5k_hw_reg_write(ah, filter0, AR5K_MCAST_FILTER0);
	ath5k_hw_reg_write(ah, filter1, AR5K_MCAST_FILTER1);
}

u32
ath5k_hw_get_rx_filter(struct ath5k_hw *ah)
{
	u32 data, filter = 0;

	filter = ath5k_hw_reg_read(ah, AR5K_RX_FILTER);

	/*Radar detection for 5212*/
	if (ah->ah_version == AR5K_AR5212) {
		data = ath5k_hw_reg_read(ah, AR5K_PHY_ERR_FIL);

		if (data & AR5K_PHY_ERR_FIL_RADAR)
			filter |= AR5K_RX_FILTER_RADARERR;
		if (data & (AR5K_PHY_ERR_FIL_OFDM | AR5K_PHY_ERR_FIL_CCK))
			filter |= AR5K_RX_FILTER_PHYERR;
	}

	return filter;
}

void
ath5k_hw_set_rx_filter(struct ath5k_hw *ah, u32 filter)
{
	u32 data = 0;

	/* Set PHY error filter register on 5212*/
	if (ah->ah_version == AR5K_AR5212) {
		if (filter & AR5K_RX_FILTER_RADARERR)
			data |= AR5K_PHY_ERR_FIL_RADAR;
		if (filter & AR5K_RX_FILTER_PHYERR)
			data |= AR5K_PHY_ERR_FIL_OFDM | AR5K_PHY_ERR_FIL_CCK;
	}

	/*
	 * The AR5210 uses promiscuous mode to detect radar activity
	 */
	if (ah->ah_version == AR5K_AR5210 &&
			(filter & AR5K_RX_FILTER_RADARERR)) {
		filter &= ~AR5K_RX_FILTER_RADARERR;
		filter |= AR5K_RX_FILTER_PROM;
	}

	/*Zero length DMA (phy error reporting) */
	if (data)
		AR5K_REG_ENABLE_BITS(ah, AR5K_RXCFG, AR5K_RXCFG_ZLFDMA);
	else
		AR5K_REG_DISABLE_BITS(ah, AR5K_RXCFG, AR5K_RXCFG_ZLFDMA);

	/*Write RX Filter register*/
	ath5k_hw_reg_write(ah, filter & 0xff, AR5K_RX_FILTER);

	/*Write PHY error filter register on 5212*/
	if (ah->ah_version == AR5K_AR5212)
		ath5k_hw_reg_write(ah, data, AR5K_PHY_ERR_FIL);

}

u64
ath5k_hw_get_tsf64(struct ath5k_hw *ah)
{
	u32 tsf_lower, tsf_upper1, tsf_upper2;
	int i;
	unsigned long flags;

	/* This code is time critical - we don't want to be interrupted here */
	local_irq_save(flags);

	/*
	 * While reading TSF upper and then lower part, the clock is still
	 * counting (or jumping in case of IBSS merge) so we might get
	 * inconsistent values. To avoid this, we read the upper part again
	 * and check it has not been changed. We make the hypothesis that a
	 * maximum of 3 changes can happens in a row (we use 10 as a safe
	 * value).
	 *
	 * Impact on performance is pretty small, since in most cases, only
	 * 3 register reads are needed.
	 */

	tsf_upper1 = ath5k_hw_reg_read(ah, AR5K_TSF_U32);
	for (i = 0; i < ATH5K_MAX_TSF_READ; i++) {
		tsf_lower = ath5k_hw_reg_read(ah, AR5K_TSF_L32);
		tsf_upper2 = ath5k_hw_reg_read(ah, AR5K_TSF_U32);
		if (tsf_upper2 == tsf_upper1)
			break;
		tsf_upper1 = tsf_upper2;
	}

	local_irq_restore(flags);

	WARN_ON(i == ATH5K_MAX_TSF_READ);

	return ((u64)tsf_upper1 << 32) | tsf_lower;
}

void
ath5k_hw_set_tsf64(struct ath5k_hw *ah, u64 tsf64)
{
	ath5k_hw_reg_write(ah, tsf64 & 0xffffffff, AR5K_TSF_L32);
	ath5k_hw_reg_write(ah, (tsf64 >> 32) & 0xffffffff, AR5K_TSF_U32);
}

void
ath5k_hw_reset_tsf(struct ath5k_hw *ah)
{
	u32 val;

	val = ath5k_hw_reg_read(ah, AR5K_BEACON) | AR5K_BEACON_RESET_TSF;

	/*
	 * Each write to the RESET_TSF bit toggles a hardware internal
	 * signal to reset TSF, but if left high it will cause a TSF reset
	 * on the next chip reset as well.  Thus we always write the value
	 * twice to clear the signal.
	 */
	ath5k_hw_reg_write(ah, val, AR5K_BEACON);
	ath5k_hw_reg_write(ah, val, AR5K_BEACON);
}

void
ath5k_hw_init_beacon_timers(struct ath5k_hw *ah, u32 next_beacon, u32 interval)
{
	u32 timer1, timer2, timer3;

	/*
	 * Set the additional timers by mode
	 */
	switch (ah->opmode) {
	case NL80211_IFTYPE_MONITOR:
	case NL80211_IFTYPE_STATION:
		/* In STA mode timer1 is used as next wakeup
		 * timer and timer2 as next CFP duration start
		 * timer. Both in 1/8TUs. */
		/* TODO: PCF handling */
		if (ah->ah_version == AR5K_AR5210) {
			timer1 = 0xffffffff;
			timer2 = 0xffffffff;
		} else {
			timer1 = 0x0000ffff;
			timer2 = 0x0007ffff;
		}
		/* Mark associated AP as PCF incapable for now */
		AR5K_REG_DISABLE_BITS(ah, AR5K_STA_ID1, AR5K_STA_ID1_PCF);
		break;
	case NL80211_IFTYPE_ADHOC:
		AR5K_REG_ENABLE_BITS(ah, AR5K_TXCFG, AR5K_TXCFG_ADHOC_BCN_ATIM);
		/* fall through */
	default:
		/* On non-STA modes timer1 is used as next DMA
		 * beacon alert (DBA) timer and timer2 as next
		 * software beacon alert. Both in 1/8TUs. */
		timer1 = (next_beacon - AR5K_TUNE_DMA_BEACON_RESP) << 3;
		timer2 = (next_beacon - AR5K_TUNE_SW_BEACON_RESP) << 3;
		break;
	}

	/* Timer3 marks the end of our ATIM window
	 * a zero length window is not allowed because
	 * we 'll get no beacons */
	timer3 = next_beacon + 1;

	/*
	 * Set the beacon register and enable all timers.
	 */
	/* When in AP or Mesh Point mode zero timer0 to start TSF */
	if (ah->opmode == NL80211_IFTYPE_AP ||
	    ah->opmode == NL80211_IFTYPE_MESH_POINT)
		ath5k_hw_reg_write(ah, 0, AR5K_TIMER0);

	ath5k_hw_reg_write(ah, next_beacon, AR5K_TIMER0);
	ath5k_hw_reg_write(ah, timer1, AR5K_TIMER1);
	ath5k_hw_reg_write(ah, timer2, AR5K_TIMER2);
	ath5k_hw_reg_write(ah, timer3, AR5K_TIMER3);

	/* Force a TSF reset if requested and enable beacons */
	if (interval & AR5K_BEACON_RESET_TSF)
		ath5k_hw_reset_tsf(ah);

	ath5k_hw_reg_write(ah, interval & (AR5K_BEACON_PERIOD |
					AR5K_BEACON_ENABLE),
						AR5K_BEACON);

	/* Flush any pending BMISS interrupts on ISR by
	 * performing a clear-on-write operation on PISR
	 * register for the BMISS bit (writing a bit on
	 * ISR toggles a reset for that bit and leaves
	 * the remaining bits intact) */
	if (ah->ah_version == AR5K_AR5210)
		ath5k_hw_reg_write(ah, AR5K_ISR_BMISS, AR5K_ISR);
	else
		ath5k_hw_reg_write(ah, AR5K_ISR_BMISS, AR5K_PISR);

	/* TODO: Set enhanced sleep registers on AR5212
	 * based on vif->bss_conf params, until then
	 * disable power save reporting.*/
	AR5K_REG_DISABLE_BITS(ah, AR5K_STA_ID1, AR5K_STA_ID1_PWR_SV);

}

__attribute__((used)) static inline bool
ath5k_check_timer_win(int a, int b, int window, int intval)
{
	/*
	 * 1.) usually B should be A + window
	 * 2.) A already updated, B not updated yet
	 * 3.) A already updated and has wrapped around
	 * 4.) B has wrapped around
	 */
	if ((b - a == window) ||				/* 1.) */
	    (a - b == intval - window) ||			/* 2.) */
	    ((a | 0x10000) - b == intval - window) ||		/* 3.) */
	    ((b | 0x10000) - a == window))			/* 4.) */
		return true; /* O.K. */
	return false;
}

bool
ath5k_hw_check_beacon_timers(struct ath5k_hw *ah, int intval)
{
	unsigned int nbtt, atim, dma;

	nbtt = ath5k_hw_reg_read(ah, AR5K_TIMER0);
	atim = ath5k_hw_reg_read(ah, AR5K_TIMER3);
	dma = ath5k_hw_reg_read(ah, AR5K_TIMER1) >> 3;

	/* NOTE: SWBA is different. Having a wrong window there does not
	 * stop us from sending data and this condition is caught by
	 * other means (SWBA interrupt) */

	if (ath5k_check_timer_win(nbtt, atim, 1, intval) &&
	    ath5k_check_timer_win(dma, nbtt, AR5K_TUNE_DMA_BEACON_RESP,
				  intval))
		return true; /* O.K. */
	return false;
}

void
ath5k_hw_set_coverage_class(struct ath5k_hw *ah, u8 coverage_class)
{
	/* As defined by IEEE 802.11-2007 17.3.8.6 */
	int slot_time = ath5k_hw_get_default_slottime(ah) + 3 * coverage_class;
	int ack_timeout = ath5k_hw_get_default_sifs(ah) + slot_time;
	int cts_timeout = ack_timeout;

	ath5k_hw_set_ifs_intervals(ah, slot_time);
	ath5k_hw_set_ack_timeout(ah, ack_timeout);
	ath5k_hw_set_cts_timeout(ah, cts_timeout);

	ah->ah_coverage_class = coverage_class;
}

void
ath5k_hw_start_rx_pcu(struct ath5k_hw *ah)
{
	AR5K_REG_DISABLE_BITS(ah, AR5K_DIAG_SW, AR5K_DIAG_SW_DIS_RX);
}

void
ath5k_hw_stop_rx_pcu(struct ath5k_hw *ah)
{
	AR5K_REG_ENABLE_BITS(ah, AR5K_DIAG_SW, AR5K_DIAG_SW_DIS_RX);
}

int
ath5k_hw_set_opmode(struct ath5k_hw *ah, enum nl80211_iftype op_mode)
{
	struct ath_common *common = ath5k_hw_common(ah);
	u32 pcu_reg, beacon_reg, low_id, high_id;

	ATH5K_DBG(ah, ATH5K_DEBUG_MODE, "mode %d\n", op_mode);

	/* Preserve rest settings */
	pcu_reg = ath5k_hw_reg_read(ah, AR5K_STA_ID1) & 0xffff0000;
	pcu_reg &= ~(AR5K_STA_ID1_ADHOC | AR5K_STA_ID1_AP
			| AR5K_STA_ID1_KEYSRCH_MODE
			| (ah->ah_version == AR5K_AR5210 ?
			(AR5K_STA_ID1_PWR_SV | AR5K_STA_ID1_NO_PSPOLL) : 0));

	beacon_reg = 0;

	switch (op_mode) {
	case NL80211_IFTYPE_ADHOC:
		pcu_reg |= AR5K_STA_ID1_ADHOC | AR5K_STA_ID1_KEYSRCH_MODE;
		beacon_reg |= AR5K_BCR_ADHOC;
		if (ah->ah_version == AR5K_AR5210)
			pcu_reg |= AR5K_STA_ID1_NO_PSPOLL;
		else
			AR5K_REG_ENABLE_BITS(ah, AR5K_CFG, AR5K_CFG_IBSS);
		break;

	case NL80211_IFTYPE_AP:
	case NL80211_IFTYPE_MESH_POINT:
		pcu_reg |= AR5K_STA_ID1_AP | AR5K_STA_ID1_KEYSRCH_MODE;
		beacon_reg |= AR5K_BCR_AP;
		if (ah->ah_version == AR5K_AR5210)
			pcu_reg |= AR5K_STA_ID1_NO_PSPOLL;
		else
			AR5K_REG_DISABLE_BITS(ah, AR5K_CFG, AR5K_CFG_IBSS);
		break;

	case NL80211_IFTYPE_STATION:
		pcu_reg |= AR5K_STA_ID1_KEYSRCH_MODE
			| (ah->ah_version == AR5K_AR5210 ?
				AR5K_STA_ID1_PWR_SV : 0);
		/* fall through */
	case NL80211_IFTYPE_MONITOR:
		pcu_reg |= AR5K_STA_ID1_KEYSRCH_MODE
			| (ah->ah_version == AR5K_AR5210 ?
				AR5K_STA_ID1_NO_PSPOLL : 0);
		break;

	default:
		return -EINVAL;
	}

	/*
	 * Set PCU registers
	 */
	low_id = get_unaligned_le32(common->macaddr);
	high_id = get_unaligned_le16(common->macaddr + 4);
	ath5k_hw_reg_write(ah, low_id, AR5K_STA_ID0);
	ath5k_hw_reg_write(ah, pcu_reg | high_id, AR5K_STA_ID1);

	/*
	 * Set Beacon Control Register on 5210
	 */
	if (ah->ah_version == AR5K_AR5210)
		ath5k_hw_reg_write(ah, beacon_reg, AR5K_BCR);

	return 0;
}

void
ath5k_hw_pcu_init(struct ath5k_hw *ah, enum nl80211_iftype op_mode)
{
	/* Set bssid and bssid mask */
	ath5k_hw_set_bssid(ah);

	/* Set PCU config */
	ath5k_hw_set_opmode(ah, op_mode);

	/* Write rate duration table only on AR5212 and if
	 * virtual interface has already been brought up
	 * XXX: rethink this after new mode changes to
	 * mac80211 are integrated */
	if (ah->ah_version == AR5K_AR5212 &&
		ah->nvifs)
		ath5k_hw_write_rate_duration(ah);

	/* Set RSSI/BRSSI thresholds
	 *
	 * Note: If we decide to set this value
	 * dynamically, have in mind that when AR5K_RSSI_THR
	 * register is read it might return 0x40 if we haven't
	 * wrote anything to it plus BMISS RSSI threshold is zeroed.
	 * So doing a save/restore procedure here isn't the right
	 * choice. Instead store it on ath5k_hw */
	ath5k_hw_reg_write(ah, (AR5K_TUNE_RSSI_THRES |
				AR5K_TUNE_BMISS_THRES <<
				AR5K_RSSI_THR_BMISS_S),
				AR5K_RSSI_THR);

	/* MIC QoS support */
	if (ah->ah_mac_srev >= AR5K_SREV_AR2413) {
		ath5k_hw_reg_write(ah, 0x000100aa, AR5K_MIC_QOS_CTL);
		ath5k_hw_reg_write(ah, 0x00003210, AR5K_MIC_QOS_SEL);
	}

	/* QoS NOACK Policy */
	if (ah->ah_version == AR5K_AR5212) {
		ath5k_hw_reg_write(ah,
			AR5K_REG_SM(2, AR5K_QOS_NOACK_2BIT_VALUES) |
			AR5K_REG_SM(5, AR5K_QOS_NOACK_BIT_OFFSET)  |
			AR5K_REG_SM(0, AR5K_QOS_NOACK_BYTE_OFFSET),
			AR5K_QOS_NOACK);
	}

	/* Restore slot time and ACK timeouts */
	if (ah->ah_coverage_class > 0)
		ath5k_hw_set_coverage_class(ah, ah->ah_coverage_class);

	/* Set ACK bitrate mode (see ack_rates_high) */
	if (ah->ah_version == AR5K_AR5212) {
		u32 val = AR5K_STA_ID1_BASE_RATE_11B | AR5K_STA_ID1_ACKCTS_6MB;
		if (ah->ah_ack_bitrate_high)
			AR5K_REG_DISABLE_BITS(ah, AR5K_STA_ID1, val);
		else
			AR5K_REG_ENABLE_BITS(ah, AR5K_STA_ID1, val);
	}
	return;
}

