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
typedef  scalar_t__ sfunc_t ;
struct TYPE_3__ {int /*<<< orphan*/  (* v2_eval ) (char*) ;int /*<<< orphan*/  (* v0_eval ) (int /*<<< orphan*/ ,char*) ;} ;
struct TYPE_4__ {int pv_romvers; scalar_t__* pv_synchook; int /*<<< orphan*/  (* pv_abort ) () ;TYPE_1__ pv_fortheval; int /*<<< orphan*/  (* pv_reboot ) (char*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  AUXIO_LED ; 
 scalar_t__ PROM_V0 ; 
 int /*<<< orphan*/  prom_getproperty (int /*<<< orphan*/ ,char*,char*,int) ; 
 int prom_getproplen (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  prom_lock ; 
 int prom_prev ; 
 int prom_rev ; 
 int /*<<< orphan*/  prom_root_node ; 
 scalar_t__ prom_vers ; 
 int /*<<< orphan*/  restore_current () ; 
 TYPE_2__* romvec ; 
 int /*<<< orphan*/  set_auxio (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 int /*<<< orphan*/  stub1 (char*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  stub3 (char*) ; 
 int /*<<< orphan*/  stub4 () ; 

void
prom_reboot(char *bcommand)
{
	unsigned long flags;
	spin_lock_irqsave(&prom_lock, flags);
	(*(romvec->pv_reboot))(bcommand);
	/* Never get here. */
	restore_current();
	spin_unlock_irqrestore(&prom_lock, flags);
}

void
prom_feval(char *fstring)
{
	unsigned long flags;
	if(!fstring || fstring[0] == 0)
		return;
	spin_lock_irqsave(&prom_lock, flags);
	if(prom_vers == PROM_V0)
		(*(romvec->pv_fortheval.v0_eval))(strlen(fstring), fstring);
	else
		(*(romvec->pv_fortheval.v2_eval))(fstring);
	restore_current();
	spin_unlock_irqrestore(&prom_lock, flags);
}

void
prom_cmdline(void)
{
	unsigned long flags;

	spin_lock_irqsave(&prom_lock, flags);
	(*(romvec->pv_abort))();
	restore_current();
	spin_unlock_irqrestore(&prom_lock, flags);
	set_auxio(AUXIO_LED, 0);
}

void
prom_setsync(sfunc_t funcp)
{
	if(!funcp) return;
	*romvec->pv_synchook = funcp;
}

unsigned char
prom_get_idprom(char *idbuf, int num_bytes)
{
	int len;

	len = prom_getproplen(prom_root_node, "idprom");
	if((len>num_bytes) || (len==-1)) return 0xff;
	if(!prom_getproperty(prom_root_node, "idprom", idbuf, num_bytes))
		return idbuf[0];

	return 0xff;
}

int
prom_version(void)
{
	return romvec->pv_romvers;
}

int
prom_getrev(void)
{
	return prom_rev;
}

int
prom_getprev(void)
{
	return prom_prev;
}

