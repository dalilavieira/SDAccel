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
typedef  int u16 ;
struct vnt_private {int current_aid; scalar_t__ op_mode; int bEnablePSMode; int bPWBitOn; int wake_up_count; scalar_t__ PortOffset; struct ieee80211_hw* hw; } ;
struct ieee80211_conf {int listen_interval; } ;
struct ieee80211_hw {struct ieee80211_conf conf; } ;

/* Variables and functions */
 int BIT (int) ; 
 int C_PWBT ; 
 scalar_t__ MAC_REG_AIDATIM ; 
 int /*<<< orphan*/  MAC_REG_PSCFG ; 
 int /*<<< orphan*/  MAC_REG_PSCTL ; 
 scalar_t__ MAC_REG_PWBT ; 
 int /*<<< orphan*/  MAC_REG_TFTCTL ; 
 int /*<<< orphan*/  MACbPSWakeup (struct vnt_private*) ; 
 int /*<<< orphan*/  MACvRegBitsOff (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MACvRegBitsOn (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ NL80211_IFTYPE_ADHOC ; 
 int /*<<< orphan*/  PSCFG_AUTOSLEEP ; 
 int /*<<< orphan*/  PSCTL_ALBCN ; 
 int /*<<< orphan*/  PSCTL_LNBCN ; 
 int /*<<< orphan*/  PSCTL_PSEN ; 
 int /*<<< orphan*/  TFTCTL_HWUTSF ; 
 int /*<<< orphan*/  VNSvOutPortW (scalar_t__,int) ; 
 int /*<<< orphan*/  pr_debug (char*) ; 

void
PSvEnablePowerSaving(
	struct vnt_private *priv,
	unsigned short wListenInterval
)
{
	u16 wAID = priv->current_aid | BIT(14) | BIT(15);

	/* set period of power up before TBTT */
	VNSvOutPortW(priv->PortOffset + MAC_REG_PWBT, C_PWBT);
	if (priv->op_mode != NL80211_IFTYPE_ADHOC) {
		/* set AID */
		VNSvOutPortW(priv->PortOffset + MAC_REG_AIDATIM, wAID);
	} else {
		/* set ATIM Window */
#if 0 /* TODO atim window */
		MACvWriteATIMW(priv->PortOffset, pMgmt->wCurrATIMWindow);
#endif
	}
	/* Set AutoSleep */
	MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCFG, PSCFG_AUTOSLEEP);
	/* Set HWUTSF */
	MACvRegBitsOn(priv->PortOffset, MAC_REG_TFTCTL, TFTCTL_HWUTSF);

	if (wListenInterval >= 2) {
		/* clear always listen beacon */
		MACvRegBitsOff(priv->PortOffset, MAC_REG_PSCTL, PSCTL_ALBCN);
		/* first time set listen next beacon */
		MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCTL, PSCTL_LNBCN);
	} else {
		/* always listen beacon */
		MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCTL, PSCTL_ALBCN);
	}

	/* enable power saving hw function */
	MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCTL, PSCTL_PSEN);
	priv->bEnablePSMode = true;

	priv->bPWBitOn = true;
	pr_debug("PS:Power Saving Mode Enable...\n");
}

void
PSvDisablePowerSaving(
	struct vnt_private *priv
)
{
	/* disable power saving hw function */
	MACbPSWakeup(priv);
	/* clear AutoSleep */
	MACvRegBitsOff(priv->PortOffset, MAC_REG_PSCFG, PSCFG_AUTOSLEEP);
	/* clear HWUTSF */
	MACvRegBitsOff(priv->PortOffset, MAC_REG_TFTCTL, TFTCTL_HWUTSF);
	/* set always listen beacon */
	MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCTL, PSCTL_ALBCN);

	priv->bEnablePSMode = false;

	priv->bPWBitOn = false;
}

bool
PSbIsNextTBTTWakeUp(
	struct vnt_private *priv
)
{
	struct ieee80211_hw *hw = priv->hw;
	struct ieee80211_conf *conf = &hw->conf;
	bool wake_up = false;

	if (conf->listen_interval > 1) {
		if (!priv->wake_up_count)
			priv->wake_up_count = conf->listen_interval;

		--priv->wake_up_count;

		if (priv->wake_up_count == 1) {
			/* Turn on wake up to listen next beacon */
			MACvRegBitsOn(priv->PortOffset,
				      MAC_REG_PSCTL, PSCTL_LNBCN);
			wake_up = true;
		}
	}

	return wake_up;
}

