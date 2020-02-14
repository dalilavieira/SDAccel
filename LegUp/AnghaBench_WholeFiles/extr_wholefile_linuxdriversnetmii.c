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
typedef  int u32 ;
typedef  int u16 ;
struct net_device {int dummy; } ;
struct mii_ioctl_data {int reg_num; int val_out; int val_in; int /*<<< orphan*/  phy_id; } ;
struct mii_if_info {int (* mdio_read ) (struct net_device*,int /*<<< orphan*/ ,int) ;int full_duplex; int advertising; int force_media; int reg_num_mask; struct net_device* dev; int /*<<< orphan*/  (* mdio_write ) (struct net_device*,int /*<<< orphan*/ ,int,int) ;int /*<<< orphan*/  phy_id; int /*<<< orphan*/  phy_id_mask; scalar_t__ supports_gmii; } ;
struct TYPE_4__ {scalar_t__ port; scalar_t__ autoneg; int speed; int duplex; int /*<<< orphan*/  phy_address; void* mdio_support; } ;
struct TYPE_3__ {int /*<<< orphan*/  advertising; int /*<<< orphan*/  lp_advertising; int /*<<< orphan*/  supported; } ;
struct ethtool_link_ksettings {TYPE_2__ base; TYPE_1__ link_modes; } ;
struct ethtool_cmd {int supported; scalar_t__ port; scalar_t__ transceiver; int advertising; scalar_t__ autoneg; int lp_advertising; int duplex; int /*<<< orphan*/  phy_address; void* mdio_support; } ;

/* Variables and functions */
 int ADVERTISED_1000baseT_Full ; 
 int ADVERTISED_1000baseT_Half ; 
 int ADVERTISED_100baseT_Full ; 
 int ADVERTISED_100baseT_Half ; 
 int ADVERTISED_10baseT_Full ; 
 int ADVERTISED_10baseT_Half ; 
 int ADVERTISED_Autoneg ; 
 int ADVERTISED_MII ; 
 int ADVERTISED_TP ; 
 int ADVERTISE_1000FULL ; 
 int ADVERTISE_1000HALF ; 
 int ADVERTISE_100BASE4 ; 
 int ADVERTISE_100FULL ; 
 int ADVERTISE_100HALF ; 
 int ADVERTISE_ALL ; 
 int ADVERTISE_FULL ; 
 scalar_t__ AUTONEG_DISABLE ; 
 scalar_t__ AUTONEG_ENABLE ; 
 int BMCR_ANENABLE ; 
 int BMCR_ANRESTART ; 
 int BMCR_FULLDPLX ; 
 int BMCR_RESET ; 
 int BMCR_SPEED100 ; 
 int BMCR_SPEED1000 ; 
 int BMSR_ANEGCOMPLETE ; 
 int BMSR_ESTATEN ; 
 int BMSR_LSTATUS ; 
 void* DUPLEX_FULL ; 
 void* DUPLEX_HALF ; 
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int ESTATUS_1000_TFULL ; 
 int ESTATUS_1000_THALF ; 
 void* ETH_MDIO_SUPPORTS_C22 ; 
 int LPA_1000FULL ; 
 int LPA_1000HALF ; 
#define  MII_ADVERTISE 132 
#define  MII_BMCR 131 
 int MII_BMSR ; 
 int MII_CTRL1000 ; 
 int MII_ESTATUS ; 
 int MII_LPA ; 
 int MII_STAT1000 ; 
 scalar_t__ PORT_MII ; 
#define  SIOCGMIIPHY 130 
#define  SIOCGMIIREG 129 
#define  SIOCSMIIREG 128 
 int SPEED_10 ; 
 int SPEED_100 ; 
 int SPEED_1000 ; 
 int SUPPORTED_1000baseT_Full ; 
 int SUPPORTED_1000baseT_Half ; 
 int SUPPORTED_100baseT_Full ; 
 int SUPPORTED_100baseT_Half ; 
 int SUPPORTED_10baseT_Full ; 
 int SUPPORTED_10baseT_Half ; 
 int SUPPORTED_Autoneg ; 
 int SUPPORTED_MII ; 
 int SUPPORTED_TP ; 
 scalar_t__ XCVR_INTERNAL ; 
 int ethtool_adv_to_mii_adv_t (int) ; 
 int ethtool_adv_to_mii_ctrl1000_t (int) ; 
 int ethtool_cmd_speed (struct ethtool_cmd*) ; 
 int /*<<< orphan*/  ethtool_cmd_speed_set (struct ethtool_cmd*,int) ; 
 int /*<<< orphan*/  ethtool_convert_legacy_u32_to_link_mode (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ethtool_convert_link_mode_to_legacy_u32 (int*,int /*<<< orphan*/ ) ; 
 int mii_ctrl1000_to_ethtool_adv_t (int) ; 
 int mii_lpa_to_ethtool_lpa_t (int) ; 
 int mii_nway_result (int) ; 
 int mii_stat1000_to_ethtool_lpa_t (int) ; 
 int /*<<< orphan*/  netdev_info (struct net_device*,char*,...) ; 
 int /*<<< orphan*/  netif_carrier_off (struct net_device*) ; 
 int netif_carrier_ok (struct net_device*) ; 
 int /*<<< orphan*/  netif_carrier_on (struct net_device*) ; 
 int stub1 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub10 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub11 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub12 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  stub13 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int stub14 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub15 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int stub16 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub17 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int stub18 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub19 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub2 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub20 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  stub21 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int stub22 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub23 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int stub24 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub25 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int stub26 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub27 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub28 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub29 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub3 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub30 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub31 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int stub32 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub33 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub34 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub35 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub36 (struct net_device*,int /*<<< orphan*/ ,int,int) ; 
 int stub4 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub5 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub6 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub7 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub8 (struct net_device*,int /*<<< orphan*/ ,int) ; 
 int stub9 (struct net_device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static u32 mii_get_an(struct mii_if_info *mii, u16 addr)
{
	int advert;

	advert = mii->mdio_read(mii->dev, mii->phy_id, addr);

	return mii_lpa_to_ethtool_lpa_t(advert);
}

int mii_ethtool_gset(struct mii_if_info *mii, struct ethtool_cmd *ecmd)
{
	struct net_device *dev = mii->dev;
	u16 bmcr, bmsr, ctrl1000 = 0, stat1000 = 0;
	u32 nego;

	ecmd->supported =
	    (SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full |
	     SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full |
	     SUPPORTED_Autoneg | SUPPORTED_TP | SUPPORTED_MII);
	if (mii->supports_gmii)
		ecmd->supported |= SUPPORTED_1000baseT_Half |
			SUPPORTED_1000baseT_Full;

	/* only supports twisted-pair */
	ecmd->port = PORT_MII;

	/* only supports internal transceiver */
	ecmd->transceiver = XCVR_INTERNAL;

	/* this isn't fully supported at higher layers */
	ecmd->phy_address = mii->phy_id;
	ecmd->mdio_support = ETH_MDIO_SUPPORTS_C22;

	ecmd->advertising = ADVERTISED_TP | ADVERTISED_MII;

	bmcr = mii->mdio_read(dev, mii->phy_id, MII_BMCR);
	bmsr = mii->mdio_read(dev, mii->phy_id, MII_BMSR);
	if (mii->supports_gmii) {
 		ctrl1000 = mii->mdio_read(dev, mii->phy_id, MII_CTRL1000);
		stat1000 = mii->mdio_read(dev, mii->phy_id, MII_STAT1000);
	}
	if (bmcr & BMCR_ANENABLE) {
		ecmd->advertising |= ADVERTISED_Autoneg;
		ecmd->autoneg = AUTONEG_ENABLE;

		ecmd->advertising |= mii_get_an(mii, MII_ADVERTISE);
		if (mii->supports_gmii)
			ecmd->advertising |=
					mii_ctrl1000_to_ethtool_adv_t(ctrl1000);

		if (bmsr & BMSR_ANEGCOMPLETE) {
			ecmd->lp_advertising = mii_get_an(mii, MII_LPA);
			ecmd->lp_advertising |=
					mii_stat1000_to_ethtool_lpa_t(stat1000);
		} else {
			ecmd->lp_advertising = 0;
		}

		nego = ecmd->advertising & ecmd->lp_advertising;

		if (nego & (ADVERTISED_1000baseT_Full |
			    ADVERTISED_1000baseT_Half)) {
			ethtool_cmd_speed_set(ecmd, SPEED_1000);
			ecmd->duplex = !!(nego & ADVERTISED_1000baseT_Full);
		} else if (nego & (ADVERTISED_100baseT_Full |
				   ADVERTISED_100baseT_Half)) {
			ethtool_cmd_speed_set(ecmd, SPEED_100);
			ecmd->duplex = !!(nego & ADVERTISED_100baseT_Full);
		} else {
			ethtool_cmd_speed_set(ecmd, SPEED_10);
			ecmd->duplex = !!(nego & ADVERTISED_10baseT_Full);
		}
	} else {
		ecmd->autoneg = AUTONEG_DISABLE;

		ethtool_cmd_speed_set(ecmd,
				      ((bmcr & BMCR_SPEED1000 &&
					(bmcr & BMCR_SPEED100) == 0) ?
				       SPEED_1000 :
				       ((bmcr & BMCR_SPEED100) ?
					SPEED_100 : SPEED_10)));
		ecmd->duplex = (bmcr & BMCR_FULLDPLX) ? DUPLEX_FULL : DUPLEX_HALF;
	}

	mii->full_duplex = ecmd->duplex;

	/* ignore maxtxpkt, maxrxpkt for now */

	return 0;
}

void mii_ethtool_get_link_ksettings(struct mii_if_info *mii,
				    struct ethtool_link_ksettings *cmd)
{
	struct net_device *dev = mii->dev;
	u16 bmcr, bmsr, ctrl1000 = 0, stat1000 = 0;
	u32 nego, supported, advertising, lp_advertising;

	supported = (SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full |
		     SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full |
		     SUPPORTED_Autoneg | SUPPORTED_TP | SUPPORTED_MII);
	if (mii->supports_gmii)
		supported |= SUPPORTED_1000baseT_Half |
			SUPPORTED_1000baseT_Full;

	/* only supports twisted-pair */
	cmd->base.port = PORT_MII;

	/* this isn't fully supported at higher layers */
	cmd->base.phy_address = mii->phy_id;
	cmd->base.mdio_support = ETH_MDIO_SUPPORTS_C22;

	advertising = ADVERTISED_TP | ADVERTISED_MII;

	bmcr = mii->mdio_read(dev, mii->phy_id, MII_BMCR);
	bmsr = mii->mdio_read(dev, mii->phy_id, MII_BMSR);
	if (mii->supports_gmii) {
		ctrl1000 = mii->mdio_read(dev, mii->phy_id, MII_CTRL1000);
		stat1000 = mii->mdio_read(dev, mii->phy_id, MII_STAT1000);
	}
	if (bmcr & BMCR_ANENABLE) {
		advertising |= ADVERTISED_Autoneg;
		cmd->base.autoneg = AUTONEG_ENABLE;

		advertising |= mii_get_an(mii, MII_ADVERTISE);
		if (mii->supports_gmii)
			advertising |= mii_ctrl1000_to_ethtool_adv_t(ctrl1000);

		if (bmsr & BMSR_ANEGCOMPLETE) {
			lp_advertising = mii_get_an(mii, MII_LPA);
			lp_advertising |=
					mii_stat1000_to_ethtool_lpa_t(stat1000);
		} else {
			lp_advertising = 0;
		}

		nego = advertising & lp_advertising;

		if (nego & (ADVERTISED_1000baseT_Full |
			    ADVERTISED_1000baseT_Half)) {
			cmd->base.speed = SPEED_1000;
			cmd->base.duplex = !!(nego & ADVERTISED_1000baseT_Full);
		} else if (nego & (ADVERTISED_100baseT_Full |
				   ADVERTISED_100baseT_Half)) {
			cmd->base.speed = SPEED_100;
			cmd->base.duplex = !!(nego & ADVERTISED_100baseT_Full);
		} else {
			cmd->base.speed = SPEED_10;
			cmd->base.duplex = !!(nego & ADVERTISED_10baseT_Full);
		}
	} else {
		cmd->base.autoneg = AUTONEG_DISABLE;

		cmd->base.speed = ((bmcr & BMCR_SPEED1000 &&
				    (bmcr & BMCR_SPEED100) == 0) ?
				   SPEED_1000 :
				   ((bmcr & BMCR_SPEED100) ?
				    SPEED_100 : SPEED_10));
		cmd->base.duplex = (bmcr & BMCR_FULLDPLX) ?
			DUPLEX_FULL : DUPLEX_HALF;

		lp_advertising = 0;
	}

	mii->full_duplex = cmd->base.duplex;

	ethtool_convert_legacy_u32_to_link_mode(cmd->link_modes.supported,
						supported);
	ethtool_convert_legacy_u32_to_link_mode(cmd->link_modes.advertising,
						advertising);
	ethtool_convert_legacy_u32_to_link_mode(cmd->link_modes.lp_advertising,
						lp_advertising);

	/* ignore maxtxpkt, maxrxpkt for now */
}

int mii_ethtool_sset(struct mii_if_info *mii, struct ethtool_cmd *ecmd)
{
	struct net_device *dev = mii->dev;
	u32 speed = ethtool_cmd_speed(ecmd);

	if (speed != SPEED_10 &&
	    speed != SPEED_100 &&
	    speed != SPEED_1000)
		return -EINVAL;
	if (ecmd->duplex != DUPLEX_HALF && ecmd->duplex != DUPLEX_FULL)
		return -EINVAL;
	if (ecmd->port != PORT_MII)
		return -EINVAL;
	if (ecmd->transceiver != XCVR_INTERNAL)
		return -EINVAL;
	if (ecmd->phy_address != mii->phy_id)
		return -EINVAL;
	if (ecmd->autoneg != AUTONEG_DISABLE && ecmd->autoneg != AUTONEG_ENABLE)
		return -EINVAL;
	if ((speed == SPEED_1000) && (!mii->supports_gmii))
		return -EINVAL;

	/* ignore supported, maxtxpkt, maxrxpkt */

	if (ecmd->autoneg == AUTONEG_ENABLE) {
		u32 bmcr, advert, tmp;
		u32 advert2 = 0, tmp2 = 0;

		if ((ecmd->advertising & (ADVERTISED_10baseT_Half |
					  ADVERTISED_10baseT_Full |
					  ADVERTISED_100baseT_Half |
					  ADVERTISED_100baseT_Full |
					  ADVERTISED_1000baseT_Half |
					  ADVERTISED_1000baseT_Full)) == 0)
			return -EINVAL;

		/* advertise only what has been requested */
		advert = mii->mdio_read(dev, mii->phy_id, MII_ADVERTISE);
		tmp = advert & ~(ADVERTISE_ALL | ADVERTISE_100BASE4);
		if (mii->supports_gmii) {
			advert2 = mii->mdio_read(dev, mii->phy_id, MII_CTRL1000);
			tmp2 = advert2 & ~(ADVERTISE_1000HALF | ADVERTISE_1000FULL);
		}
		tmp |= ethtool_adv_to_mii_adv_t(ecmd->advertising);

		if (mii->supports_gmii)
			tmp2 |=
			      ethtool_adv_to_mii_ctrl1000_t(ecmd->advertising);
		if (advert != tmp) {
			mii->mdio_write(dev, mii->phy_id, MII_ADVERTISE, tmp);
			mii->advertising = tmp;
		}
		if ((mii->supports_gmii) && (advert2 != tmp2))
			mii->mdio_write(dev, mii->phy_id, MII_CTRL1000, tmp2);

		/* turn on autonegotiation, and force a renegotiate */
		bmcr = mii->mdio_read(dev, mii->phy_id, MII_BMCR);
		bmcr |= (BMCR_ANENABLE | BMCR_ANRESTART);
		mii->mdio_write(dev, mii->phy_id, MII_BMCR, bmcr);

		mii->force_media = 0;
	} else {
		u32 bmcr, tmp;

		/* turn off auto negotiation, set speed and duplexity */
		bmcr = mii->mdio_read(dev, mii->phy_id, MII_BMCR);
		tmp = bmcr & ~(BMCR_ANENABLE | BMCR_SPEED100 |
			       BMCR_SPEED1000 | BMCR_FULLDPLX);
		if (speed == SPEED_1000)
			tmp |= BMCR_SPEED1000;
		else if (speed == SPEED_100)
			tmp |= BMCR_SPEED100;
		if (ecmd->duplex == DUPLEX_FULL) {
			tmp |= BMCR_FULLDPLX;
			mii->full_duplex = 1;
		} else
			mii->full_duplex = 0;
		if (bmcr != tmp)
			mii->mdio_write(dev, mii->phy_id, MII_BMCR, tmp);

		mii->force_media = 1;
	}
	return 0;
}

int mii_ethtool_set_link_ksettings(struct mii_if_info *mii,
				   const struct ethtool_link_ksettings *cmd)
{
	struct net_device *dev = mii->dev;
	u32 speed = cmd->base.speed;

	if (speed != SPEED_10 &&
	    speed != SPEED_100 &&
	    speed != SPEED_1000)
		return -EINVAL;
	if (cmd->base.duplex != DUPLEX_HALF && cmd->base.duplex != DUPLEX_FULL)
		return -EINVAL;
	if (cmd->base.port != PORT_MII)
		return -EINVAL;
	if (cmd->base.phy_address != mii->phy_id)
		return -EINVAL;
	if (cmd->base.autoneg != AUTONEG_DISABLE &&
	    cmd->base.autoneg != AUTONEG_ENABLE)
		return -EINVAL;
	if ((speed == SPEED_1000) && (!mii->supports_gmii))
		return -EINVAL;

	/* ignore supported, maxtxpkt, maxrxpkt */

	if (cmd->base.autoneg == AUTONEG_ENABLE) {
		u32 bmcr, advert, tmp;
		u32 advert2 = 0, tmp2 = 0;
		u32 advertising;

		ethtool_convert_link_mode_to_legacy_u32(
			&advertising, cmd->link_modes.advertising);

		if ((advertising & (ADVERTISED_10baseT_Half |
				    ADVERTISED_10baseT_Full |
				    ADVERTISED_100baseT_Half |
				    ADVERTISED_100baseT_Full |
				    ADVERTISED_1000baseT_Half |
				    ADVERTISED_1000baseT_Full)) == 0)
			return -EINVAL;

		/* advertise only what has been requested */
		advert = mii->mdio_read(dev, mii->phy_id, MII_ADVERTISE);
		tmp = advert & ~(ADVERTISE_ALL | ADVERTISE_100BASE4);
		if (mii->supports_gmii) {
			advert2 = mii->mdio_read(dev, mii->phy_id,
						 MII_CTRL1000);
			tmp2 = advert2 &
				~(ADVERTISE_1000HALF | ADVERTISE_1000FULL);
		}
		tmp |= ethtool_adv_to_mii_adv_t(advertising);

		if (mii->supports_gmii)
			tmp2 |= ethtool_adv_to_mii_ctrl1000_t(advertising);
		if (advert != tmp) {
			mii->mdio_write(dev, mii->phy_id, MII_ADVERTISE, tmp);
			mii->advertising = tmp;
		}
		if ((mii->supports_gmii) && (advert2 != tmp2))
			mii->mdio_write(dev, mii->phy_id, MII_CTRL1000, tmp2);

		/* turn on autonegotiation, and force a renegotiate */
		bmcr = mii->mdio_read(dev, mii->phy_id, MII_BMCR);
		bmcr |= (BMCR_ANENABLE | BMCR_ANRESTART);
		mii->mdio_write(dev, mii->phy_id, MII_BMCR, bmcr);

		mii->force_media = 0;
	} else {
		u32 bmcr, tmp;

		/* turn off auto negotiation, set speed and duplexity */
		bmcr = mii->mdio_read(dev, mii->phy_id, MII_BMCR);
		tmp = bmcr & ~(BMCR_ANENABLE | BMCR_SPEED100 |
			       BMCR_SPEED1000 | BMCR_FULLDPLX);
		if (speed == SPEED_1000)
			tmp |= BMCR_SPEED1000;
		else if (speed == SPEED_100)
			tmp |= BMCR_SPEED100;
		if (cmd->base.duplex == DUPLEX_FULL) {
			tmp |= BMCR_FULLDPLX;
			mii->full_duplex = 1;
		} else {
			mii->full_duplex = 0;
		}
		if (bmcr != tmp)
			mii->mdio_write(dev, mii->phy_id, MII_BMCR, tmp);

		mii->force_media = 1;
	}
	return 0;
}

int mii_check_gmii_support(struct mii_if_info *mii)
{
	int reg;

	reg = mii->mdio_read(mii->dev, mii->phy_id, MII_BMSR);
	if (reg & BMSR_ESTATEN) {
		reg = mii->mdio_read(mii->dev, mii->phy_id, MII_ESTATUS);
		if (reg & (ESTATUS_1000_TFULL | ESTATUS_1000_THALF))
			return 1;
	}

	return 0;
}

int mii_link_ok (struct mii_if_info *mii)
{
	/* first, a dummy read, needed to latch some MII phys */
	mii->mdio_read(mii->dev, mii->phy_id, MII_BMSR);
	if (mii->mdio_read(mii->dev, mii->phy_id, MII_BMSR) & BMSR_LSTATUS)
		return 1;
	return 0;
}

int mii_nway_restart (struct mii_if_info *mii)
{
	int bmcr;
	int r = -EINVAL;

	/* if autoneg is off, it's an error */
	bmcr = mii->mdio_read(mii->dev, mii->phy_id, MII_BMCR);

	if (bmcr & BMCR_ANENABLE) {
		bmcr |= BMCR_ANRESTART;
		mii->mdio_write(mii->dev, mii->phy_id, MII_BMCR, bmcr);
		r = 0;
	}

	return r;
}

void mii_check_link (struct mii_if_info *mii)
{
	int cur_link = mii_link_ok(mii);
	int prev_link = netif_carrier_ok(mii->dev);

	if (cur_link && !prev_link)
		netif_carrier_on(mii->dev);
	else if (prev_link && !cur_link)
		netif_carrier_off(mii->dev);
}

unsigned int mii_check_media (struct mii_if_info *mii,
			      unsigned int ok_to_print,
			      unsigned int init_media)
{
	unsigned int old_carrier, new_carrier;
	int advertise, lpa, media, duplex;
	int lpa2 = 0;

	/* check current and old link status */
	old_carrier = netif_carrier_ok(mii->dev) ? 1 : 0;
	new_carrier = (unsigned int) mii_link_ok(mii);

	/* if carrier state did not change, this is a "bounce",
	 * just exit as everything is already set correctly
	 */
	if ((!init_media) && (old_carrier == new_carrier))
		return 0; /* duplex did not change */

	/* no carrier, nothing much to do */
	if (!new_carrier) {
		netif_carrier_off(mii->dev);
		if (ok_to_print)
			netdev_info(mii->dev, "link down\n");
		return 0; /* duplex did not change */
	}

	/*
	 * we have carrier, see who's on the other end
	 */
	netif_carrier_on(mii->dev);

	if (mii->force_media) {
		if (ok_to_print)
			netdev_info(mii->dev, "link up\n");
		return 0; /* duplex did not change */
	}

	/* get MII advertise and LPA values */
	if ((!init_media) && (mii->advertising))
		advertise = mii->advertising;
	else {
		advertise = mii->mdio_read(mii->dev, mii->phy_id, MII_ADVERTISE);
		mii->advertising = advertise;
	}
	lpa = mii->mdio_read(mii->dev, mii->phy_id, MII_LPA);
	if (mii->supports_gmii)
		lpa2 = mii->mdio_read(mii->dev, mii->phy_id, MII_STAT1000);

	/* figure out media and duplex from advertise and LPA values */
	media = mii_nway_result(lpa & advertise);
	duplex = (media & ADVERTISE_FULL) ? 1 : 0;
	if (lpa2 & LPA_1000FULL)
		duplex = 1;

	if (ok_to_print)
		netdev_info(mii->dev, "link up, %uMbps, %s-duplex, lpa 0x%04X\n",
			    lpa2 & (LPA_1000FULL | LPA_1000HALF) ? 1000 :
			    media & (ADVERTISE_100FULL | ADVERTISE_100HALF) ?
			    100 : 10,
			    duplex ? "full" : "half",
			    lpa);

	if ((init_media) || (mii->full_duplex != duplex)) {
		mii->full_duplex = duplex;
		return 1; /* duplex changed */
	}

	return 0; /* duplex did not change */
}

int generic_mii_ioctl(struct mii_if_info *mii_if,
		      struct mii_ioctl_data *mii_data, int cmd,
		      unsigned int *duplex_chg_out)
{
	int rc = 0;
	unsigned int duplex_changed = 0;

	if (duplex_chg_out)
		*duplex_chg_out = 0;

	mii_data->phy_id &= mii_if->phy_id_mask;
	mii_data->reg_num &= mii_if->reg_num_mask;

	switch(cmd) {
	case SIOCGMIIPHY:
		mii_data->phy_id = mii_if->phy_id;
		/* fall through */

	case SIOCGMIIREG:
		mii_data->val_out =
			mii_if->mdio_read(mii_if->dev, mii_data->phy_id,
					  mii_data->reg_num);
		break;

	case SIOCSMIIREG: {
		u16 val = mii_data->val_in;

		if (mii_data->phy_id == mii_if->phy_id) {
			switch(mii_data->reg_num) {
			case MII_BMCR: {
				unsigned int new_duplex = 0;
				if (val & (BMCR_RESET|BMCR_ANENABLE))
					mii_if->force_media = 0;
				else
					mii_if->force_media = 1;
				if (mii_if->force_media &&
				    (val & BMCR_FULLDPLX))
					new_duplex = 1;
				if (mii_if->full_duplex != new_duplex) {
					duplex_changed = 1;
					mii_if->full_duplex = new_duplex;
				}
				break;
			}
			case MII_ADVERTISE:
				mii_if->advertising = val;
				break;
			default:
				/* do nothing */
				break;
			}
		}

		mii_if->mdio_write(mii_if->dev, mii_data->phy_id,
				   mii_data->reg_num, val);
		break;
	}

	default:
		rc = -EOPNOTSUPP;
		break;
	}

	if ((rc == 0) && (duplex_chg_out) && (duplex_changed))
		*duplex_chg_out = 1;

	return rc;
}

