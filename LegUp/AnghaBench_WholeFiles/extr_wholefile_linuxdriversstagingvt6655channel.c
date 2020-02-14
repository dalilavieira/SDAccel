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
struct vnt_private {int byRFType; scalar_t__ byBBVGACurrent; scalar_t__* abyBBVGA; scalar_t__ byLocalID; scalar_t__ byBBType; int /*<<< orphan*/  byCurrentCh; int /*<<< orphan*/  lock; scalar_t__ PortOffset; int /*<<< orphan*/  byCurPwr; scalar_t__ bEnablePSMode; scalar_t__ bUpdateBBVGA; TYPE_2__* hw; } ;
struct ieee80211_channel {int max_power; int /*<<< orphan*/  hw_value; void* flags; } ;
struct TYPE_4__ {TYPE_1__* wiphy; } ;
struct TYPE_3__ {int /*<<< orphan*/ ** bands; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct ieee80211_channel*) ; 
 scalar_t__ BB_TYPE_11B ; 
 int /*<<< orphan*/  BBvSetVGAGainOffset (struct vnt_private*,scalar_t__) ; 
 int /*<<< orphan*/  BBvSoftwareReset (struct vnt_private*) ; 
 void* IEEE80211_CHAN_NO_HT40 ; 
 int /*<<< orphan*/  MACCR_CLRNAV ; 
 int /*<<< orphan*/  MAC_REG_MACCR ; 
 scalar_t__ MAC_REG_PWRCCK ; 
 scalar_t__ MAC_REG_PWROFDM ; 
 int /*<<< orphan*/  MACvRegBitsOn (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MACvSelectPage0 (scalar_t__) ; 
 int /*<<< orphan*/  MACvSelectPage1 (scalar_t__) ; 
 size_t NL80211_BAND_2GHZ ; 
 size_t NL80211_BAND_5GHZ ; 
 int /*<<< orphan*/  RATE_1M ; 
 int /*<<< orphan*/  RATE_6M ; 
 scalar_t__ REV_ID_VT3253_B1 ; 
#define  RF_AIROHA 135 
#define  RF_AIROHA7230 134 
#define  RF_AL2230S 133 
#define  RF_NOTHING 132 
#define  RF_RFMD2959 131 
#define  RF_UW2451 130 
#define  RF_UW2452 129 
#define  RF_VT3226 128 
 int /*<<< orphan*/  RFbAL7230SelectChannelPostProcess (struct vnt_private*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int RFbSelectChannel (struct vnt_private*,int const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RFbSetPower (struct vnt_private*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RFvWriteWakeProgSyn (struct vnt_private*,int const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VNSvOutPortB (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct ieee80211_channel* vnt_channels_2ghz ; 
 struct ieee80211_channel* vnt_channels_5ghz ; 
 int /*<<< orphan*/  vnt_supported_2ghz_band ; 
 int /*<<< orphan*/  vnt_supported_5ghz_band ; 

void vnt_init_bands(struct vnt_private *priv)
{
	struct ieee80211_channel *ch;
	int i;

	switch (priv->byRFType) {
	case RF_AIROHA7230:
	case RF_UW2452:
	case RF_NOTHING:
	default:
		ch = vnt_channels_5ghz;

		for (i = 0; i < ARRAY_SIZE(vnt_channels_5ghz); i++) {
			ch[i].max_power = 0x3f;
			ch[i].flags = IEEE80211_CHAN_NO_HT40;
		}

		priv->hw->wiphy->bands[NL80211_BAND_5GHZ] =
						&vnt_supported_5ghz_band;
	/* fallthrough */
	case RF_RFMD2959:
	case RF_AIROHA:
	case RF_AL2230S:
	case RF_UW2451:
	case RF_VT3226:
		ch = vnt_channels_2ghz;

		for (i = 0; i < ARRAY_SIZE(vnt_channels_2ghz); i++) {
			ch[i].max_power = 0x3f;
			ch[i].flags = IEEE80211_CHAN_NO_HT40;
		}

		priv->hw->wiphy->bands[NL80211_BAND_2GHZ] =
						&vnt_supported_2ghz_band;
		break;
	}
}

bool set_channel(struct vnt_private *priv, struct ieee80211_channel *ch)
{
	bool ret = true;

	if (priv->byCurrentCh == ch->hw_value)
		return ret;

	/* Set VGA to max sensitivity */
	if (priv->bUpdateBBVGA &&
	    priv->byBBVGACurrent != priv->abyBBVGA[0]) {
		priv->byBBVGACurrent = priv->abyBBVGA[0];

		BBvSetVGAGainOffset(priv, priv->byBBVGACurrent);
	}

	/* clear NAV */
	MACvRegBitsOn(priv->PortOffset, MAC_REG_MACCR, MACCR_CLRNAV);

	/* TX_PE will reserve 3 us for MAX2829 A mode only,
	 * it is for better TX throughput
	 */

	if (priv->byRFType == RF_AIROHA7230)
		RFbAL7230SelectChannelPostProcess(priv, priv->byCurrentCh,
						  ch->hw_value);

	priv->byCurrentCh = ch->hw_value;
	ret &= RFbSelectChannel(priv, priv->byRFType,
				ch->hw_value);

	/* Init Synthesizer Table */
	if (priv->bEnablePSMode)
		RFvWriteWakeProgSyn(priv, priv->byRFType, ch->hw_value);

	BBvSoftwareReset(priv);

	if (priv->byLocalID > REV_ID_VT3253_B1) {
		unsigned long flags;

		spin_lock_irqsave(&priv->lock, flags);

		/* set HW default power register */
		MACvSelectPage1(priv->PortOffset);
		RFbSetPower(priv, RATE_1M, priv->byCurrentCh);
		VNSvOutPortB(priv->PortOffset + MAC_REG_PWRCCK,
			     priv->byCurPwr);
		RFbSetPower(priv, RATE_6M, priv->byCurrentCh);
		VNSvOutPortB(priv->PortOffset + MAC_REG_PWROFDM,
			     priv->byCurPwr);
		MACvSelectPage0(priv->PortOffset);

		spin_unlock_irqrestore(&priv->lock, flags);
	}

	if (priv->byBBType == BB_TYPE_11B)
		RFbSetPower(priv, RATE_1M, priv->byCurrentCh);
	else
		RFbSetPower(priv, RATE_6M, priv->byCurrentCh);

	return ret;
}

