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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct qede_dev {int /*<<< orphan*/  cdev; TYPE_1__* ops; } ;
struct net_device {int /*<<< orphan*/ * dcbnl_ops; int /*<<< orphan*/  addr_len; int /*<<< orphan*/  dev_addr; } ;
struct ieee_pfc {int dummy; } ;
struct ieee_ets {int dummy; } ;
struct dcb_peer_app_info {int dummy; } ;
struct dcb_app {int dummy; } ;
struct cee_pg {int dummy; } ;
struct cee_pfc {int dummy; } ;
struct TYPE_4__ {int (* getnumtcs ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ;int (* getapp ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;void (* setpgtccfgtx ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;void (* setpgtccfgrx ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;void (* setpgbwgcfgtx ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ;void (* setpgbwgcfgrx ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ;int (* setnumtcs ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ;void (* setpfcstate ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int (* setapp ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int (* peer_getappinfo ) (int /*<<< orphan*/ ,struct dcb_peer_app_info*,int /*<<< orphan*/ *) ;int (* peer_getapptable ) (int /*<<< orphan*/ ,struct dcb_app*) ;int (* cee_peer_getpfc ) (int /*<<< orphan*/ ,struct cee_pfc*) ;int (* cee_peer_getpg ) (int /*<<< orphan*/ ,struct cee_pg*) ;int (* ieee_getpfc ) (int /*<<< orphan*/ ,struct ieee_pfc*) ;int (* ieee_setpfc ) (int /*<<< orphan*/ ,struct ieee_pfc*) ;int (* ieee_getets ) (int /*<<< orphan*/ ,struct ieee_ets*) ;int (* ieee_setets ) (int /*<<< orphan*/ ,struct ieee_ets*) ;int (* ieee_getapp ) (int /*<<< orphan*/ ,struct dcb_app*) ;int (* ieee_setapp ) (int /*<<< orphan*/ ,struct dcb_app*) ;int (* ieee_peer_getpfc ) (int /*<<< orphan*/ ,struct ieee_pfc*) ;int (* ieee_peer_getets ) (int /*<<< orphan*/ ,struct ieee_ets*) ;int /*<<< orphan*/  (* setfeatcfg ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* getfeatcfg ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* setdcbx ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* setall ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* getdcbx ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* getpfcstate ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* getcap ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* setpfccfg ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* getpfccfg ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* getpgbwgcfgrx ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* getpgtccfgrx ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* getpgbwgcfgtx ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* getpgtccfgtx ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* setstate ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* getstate ) (int /*<<< orphan*/ ) ;} ;
struct TYPE_3__ {TYPE_2__* dcb; } ;

/* Variables and functions */
 int dcb_ieee_setapp (struct net_device*,struct dcb_app*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct qede_dev* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  qede_dcbnl_ops ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 
 int stub10 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub11 (int /*<<< orphan*/ ) ; 
 int stub12 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub13 (int /*<<< orphan*/ ) ; 
 void stub14 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void stub15 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void stub16 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 void stub17 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub18 (int /*<<< orphan*/ ) ; 
 int stub19 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void stub20 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub21 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub22 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub23 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub24 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int stub25 (int /*<<< orphan*/ ,struct dcb_peer_app_info*,int /*<<< orphan*/ *) ; 
 int stub26 (int /*<<< orphan*/ ,struct dcb_app*) ; 
 int stub27 (int /*<<< orphan*/ ,struct cee_pfc*) ; 
 int stub28 (int /*<<< orphan*/ ,struct cee_pg*) ; 
 int stub29 (int /*<<< orphan*/ ,struct ieee_pfc*) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub30 (int /*<<< orphan*/ ,struct ieee_pfc*) ; 
 int stub31 (int /*<<< orphan*/ ,struct ieee_ets*) ; 
 int stub32 (int /*<<< orphan*/ ,struct ieee_ets*) ; 
 int stub33 (int /*<<< orphan*/ ,struct dcb_app*) ; 
 int stub34 (int /*<<< orphan*/ ,struct dcb_app*) ; 
 int stub35 (int /*<<< orphan*/ ,struct ieee_pfc*) ; 
 int stub36 (int /*<<< orphan*/ ,struct ieee_ets*) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub5 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub6 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub7 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub8 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static u8 qede_dcbnl_getstate(struct net_device *netdev)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->getstate(edev->cdev);
}

__attribute__((used)) static u8 qede_dcbnl_setstate(struct net_device *netdev, u8 state)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setstate(edev->cdev, state);
}

__attribute__((used)) static void qede_dcbnl_getpermhwaddr(struct net_device *netdev,
				     u8 *perm_addr)
{
	memcpy(perm_addr, netdev->dev_addr, netdev->addr_len);
}

__attribute__((used)) static void qede_dcbnl_getpgtccfgtx(struct net_device *netdev, int prio,
				    u8 *prio_type, u8 *pgid, u8 *bw_pct,
				    u8 *up_map)
{
	struct qede_dev *edev = netdev_priv(netdev);

	edev->ops->dcb->getpgtccfgtx(edev->cdev, prio, prio_type,
				     pgid, bw_pct, up_map);
}

__attribute__((used)) static void qede_dcbnl_getpgbwgcfgtx(struct net_device *netdev,
				     int pgid, u8 *bw_pct)
{
	struct qede_dev *edev = netdev_priv(netdev);

	edev->ops->dcb->getpgbwgcfgtx(edev->cdev, pgid, bw_pct);
}

__attribute__((used)) static void qede_dcbnl_getpgtccfgrx(struct net_device *netdev, int prio,
				    u8 *prio_type, u8 *pgid, u8 *bw_pct,
				    u8 *up_map)
{
	struct qede_dev *edev = netdev_priv(netdev);

	edev->ops->dcb->getpgtccfgrx(edev->cdev, prio, prio_type, pgid, bw_pct,
				     up_map);
}

__attribute__((used)) static void qede_dcbnl_getpgbwgcfgrx(struct net_device *netdev,
				     int pgid, u8 *bw_pct)
{
	struct qede_dev *edev = netdev_priv(netdev);

	edev->ops->dcb->getpgbwgcfgrx(edev->cdev, pgid, bw_pct);
}

__attribute__((used)) static void qede_dcbnl_getpfccfg(struct net_device *netdev, int prio,
				 u8 *setting)
{
	struct qede_dev *edev = netdev_priv(netdev);

	edev->ops->dcb->getpfccfg(edev->cdev, prio, setting);
}

__attribute__((used)) static void qede_dcbnl_setpfccfg(struct net_device *netdev, int prio,
				 u8 setting)
{
	struct qede_dev *edev = netdev_priv(netdev);

	edev->ops->dcb->setpfccfg(edev->cdev, prio, setting);
}

__attribute__((used)) static u8 qede_dcbnl_getcap(struct net_device *netdev, int capid, u8 *cap)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->getcap(edev->cdev, capid, cap);
}

__attribute__((used)) static int qede_dcbnl_getnumtcs(struct net_device *netdev, int tcid, u8 *num)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->getnumtcs(edev->cdev, tcid, num);
}

__attribute__((used)) static u8 qede_dcbnl_getpfcstate(struct net_device *netdev)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->getpfcstate(edev->cdev);
}

__attribute__((used)) static int qede_dcbnl_getapp(struct net_device *netdev, u8 idtype, u16 id)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->getapp(edev->cdev, idtype, id);
}

__attribute__((used)) static u8 qede_dcbnl_getdcbx(struct net_device *netdev)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->getdcbx(edev->cdev);
}

__attribute__((used)) static void qede_dcbnl_setpgtccfgtx(struct net_device *netdev, int prio,
				    u8 pri_type, u8 pgid, u8 bw_pct, u8 up_map)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setpgtccfgtx(edev->cdev, prio, pri_type, pgid,
					    bw_pct, up_map);
}

__attribute__((used)) static void qede_dcbnl_setpgtccfgrx(struct net_device *netdev, int prio,
				    u8 pri_type, u8 pgid, u8 bw_pct, u8 up_map)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setpgtccfgrx(edev->cdev, prio, pri_type, pgid,
					    bw_pct, up_map);
}

__attribute__((used)) static void qede_dcbnl_setpgbwgcfgtx(struct net_device *netdev, int pgid,
				     u8 bw_pct)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setpgbwgcfgtx(edev->cdev, pgid, bw_pct);
}

__attribute__((used)) static void qede_dcbnl_setpgbwgcfgrx(struct net_device *netdev, int pgid,
				     u8 bw_pct)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setpgbwgcfgrx(edev->cdev, pgid, bw_pct);
}

__attribute__((used)) static u8 qede_dcbnl_setall(struct net_device *netdev)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setall(edev->cdev);
}

__attribute__((used)) static int qede_dcbnl_setnumtcs(struct net_device *netdev, int tcid, u8 num)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setnumtcs(edev->cdev, tcid, num);
}

__attribute__((used)) static void qede_dcbnl_setpfcstate(struct net_device *netdev, u8 state)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setpfcstate(edev->cdev, state);
}

__attribute__((used)) static int qede_dcbnl_setapp(struct net_device *netdev, u8 idtype, u16 idval,
			     u8 up)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setapp(edev->cdev, idtype, idval, up);
}

__attribute__((used)) static u8 qede_dcbnl_setdcbx(struct net_device *netdev, u8 state)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setdcbx(edev->cdev, state);
}

__attribute__((used)) static u8 qede_dcbnl_getfeatcfg(struct net_device *netdev, int featid,
				u8 *flags)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->getfeatcfg(edev->cdev, featid, flags);
}

__attribute__((used)) static u8 qede_dcbnl_setfeatcfg(struct net_device *netdev, int featid, u8 flags)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->setfeatcfg(edev->cdev, featid, flags);
}

__attribute__((used)) static int qede_dcbnl_peer_getappinfo(struct net_device *netdev,
				      struct dcb_peer_app_info *info,
				      u16 *count)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->peer_getappinfo(edev->cdev, info, count);
}

__attribute__((used)) static int qede_dcbnl_peer_getapptable(struct net_device *netdev,
				       struct dcb_app *app)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->peer_getapptable(edev->cdev, app);
}

__attribute__((used)) static int qede_dcbnl_cee_peer_getpfc(struct net_device *netdev,
				      struct cee_pfc *pfc)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->cee_peer_getpfc(edev->cdev, pfc);
}

__attribute__((used)) static int qede_dcbnl_cee_peer_getpg(struct net_device *netdev,
				     struct cee_pg *pg)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->cee_peer_getpg(edev->cdev, pg);
}

__attribute__((used)) static int qede_dcbnl_ieee_getpfc(struct net_device *netdev,
				  struct ieee_pfc *pfc)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->ieee_getpfc(edev->cdev, pfc);
}

__attribute__((used)) static int qede_dcbnl_ieee_setpfc(struct net_device *netdev,
				  struct ieee_pfc *pfc)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->ieee_setpfc(edev->cdev, pfc);
}

__attribute__((used)) static int qede_dcbnl_ieee_getets(struct net_device *netdev,
				  struct ieee_ets *ets)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->ieee_getets(edev->cdev, ets);
}

__attribute__((used)) static int qede_dcbnl_ieee_setets(struct net_device *netdev,
				  struct ieee_ets *ets)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->ieee_setets(edev->cdev, ets);
}

__attribute__((used)) static int qede_dcbnl_ieee_getapp(struct net_device *netdev,
				  struct dcb_app *app)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->ieee_getapp(edev->cdev, app);
}

__attribute__((used)) static int qede_dcbnl_ieee_setapp(struct net_device *netdev,
				  struct dcb_app *app)
{
	struct qede_dev *edev = netdev_priv(netdev);
	int err;

	err = dcb_ieee_setapp(netdev, app);
	if (err)
		return err;

	return edev->ops->dcb->ieee_setapp(edev->cdev, app);
}

__attribute__((used)) static int qede_dcbnl_ieee_peer_getpfc(struct net_device *netdev,
				       struct ieee_pfc *pfc)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->ieee_peer_getpfc(edev->cdev, pfc);
}

__attribute__((used)) static int qede_dcbnl_ieee_peer_getets(struct net_device *netdev,
				       struct ieee_ets *ets)
{
	struct qede_dev *edev = netdev_priv(netdev);

	return edev->ops->dcb->ieee_peer_getets(edev->cdev, ets);
}

void qede_set_dcbnl_ops(struct net_device *dev)
{
	dev->dcbnl_ops = &qede_dcbnl_ops;
}

