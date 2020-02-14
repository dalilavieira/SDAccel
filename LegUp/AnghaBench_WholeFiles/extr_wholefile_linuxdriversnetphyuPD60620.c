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
struct TYPE_2__ {int addr; } ;
struct phy_device {int link; int pause; int asym_pause; scalar_t__ duplex; int /*<<< orphan*/  lp_advertising; int /*<<< orphan*/  speed; TYPE_1__ mdio; } ;

/* Variables and functions */
 int BMSR_ANEGCOMPLETE ; 
 int BMSR_LSTATUS ; 
 scalar_t__ DUPLEX_FULL ; 
 scalar_t__ DUPLEX_HALF ; 
 int LPA_PAUSE_ASYM ; 
 int LPA_PAUSE_CAP ; 
 int /*<<< orphan*/  MII_BMSR ; 
 int /*<<< orphan*/  MII_LPA ; 
 int /*<<< orphan*/  PHY_PHYSCR ; 
 int PHY_PHYSCR_100MB ; 
 int PHY_PHYSCR_10MB ; 
 int PHY_PHYSCR_DUPLEX ; 
 int /*<<< orphan*/  PHY_SPM ; 
 int /*<<< orphan*/  SPEED_10 ; 
 int /*<<< orphan*/  SPEED_100 ; 
 int /*<<< orphan*/  mii_lpa_to_ethtool_lpa_t (int) ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int upd60620_config_init(struct phy_device *phydev)
{
	/* Enable support for passive HUBs (could be a strap option) */
	/* PHYMODE: All speeds, HD in parallel detect */
	return phy_write(phydev, PHY_SPM, 0x0180 | phydev->mdio.addr);
}

__attribute__((used)) static int upd60620_read_status(struct phy_device *phydev)
{
	int phy_state;

	/* Read negotiated state */
	phy_state = phy_read(phydev, MII_BMSR);
	if (phy_state < 0)
		return phy_state;

	phydev->link = 0;
	phydev->lp_advertising = 0;
	phydev->pause = 0;
	phydev->asym_pause = 0;

	if (phy_state & (BMSR_ANEGCOMPLETE | BMSR_LSTATUS)) {
		phy_state = phy_read(phydev, PHY_PHYSCR);
		if (phy_state < 0)
			return phy_state;

		if (phy_state & (PHY_PHYSCR_10MB | PHY_PHYSCR_100MB)) {
			phydev->link = 1;
			phydev->speed = SPEED_10;
			phydev->duplex = DUPLEX_HALF;

			if (phy_state & PHY_PHYSCR_100MB)
				phydev->speed = SPEED_100;
			if (phy_state & PHY_PHYSCR_DUPLEX)
				phydev->duplex = DUPLEX_FULL;

			phy_state = phy_read(phydev, MII_LPA);
			if (phy_state < 0)
				return phy_state;

			phydev->lp_advertising
				= mii_lpa_to_ethtool_lpa_t(phy_state);

			if (phydev->duplex == DUPLEX_FULL) {
				if (phy_state & LPA_PAUSE_CAP)
					phydev->pause = 1;
				if (phy_state & LPA_PAUSE_ASYM)
					phydev->asym_pause = 1;
			}
		}
	}
	return 0;
}

