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
typedef  scalar_t__ u_short ;
typedef  scalar_t__ u_long ;
struct TYPE_2__ {scalar_t__ t_start; long t_stop; void* timer_activ; } ;
struct s_smc {TYPE_1__ hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  B2_TI_CRTL ; 
 int /*<<< orphan*/  B2_TI_INI ; 
 int /*<<< orphan*/  B2_TI_VAL ; 
 void* FALSE ; 
 scalar_t__ GET_ISR () ; 
 scalar_t__ HWT_MAX ; 
 scalar_t__ IS_TIMINT ; 
 int /*<<< orphan*/  TIM_CL_IRQ ; 
 int /*<<< orphan*/  TIM_START ; 
 int /*<<< orphan*/  TIM_STOP ; 
 void* TRUE ; 
 void hwt_restart (struct s_smc*) ; 
 int inpd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outpd (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  outpw (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void hwt_start(struct s_smc *smc, u_long time)
{
	u_short	cnt ;

	if (time > HWT_MAX)
		time = HWT_MAX ;

	smc->hw.t_start = time ;
	smc->hw.t_stop = 0L ;

	cnt = (u_short)time ;
	/*
	 * if time < 16 us
	 *	time = 16 us
	 */
	if (!cnt)
		cnt++ ;

	outpd(ADDR(B2_TI_INI), (u_long) cnt * 200) ;	/* Load timer value. */
	outpw(ADDR(B2_TI_CRTL), TIM_START) ;		/* Start timer. */

	smc->hw.timer_activ = TRUE ;
}

void hwt_stop(struct s_smc *smc)
{
	outpw(ADDR(B2_TI_CRTL), TIM_STOP) ;
	outpw(ADDR(B2_TI_CRTL), TIM_CL_IRQ) ;

	smc->hw.timer_activ = FALSE ;
}

void hwt_init(struct s_smc *smc)
{
	smc->hw.t_start = 0 ;
	smc->hw.t_stop	= 0 ;
	smc->hw.timer_activ = FALSE ;

	hwt_restart(smc) ;
}

void hwt_restart(struct s_smc *smc)
{
	hwt_stop(smc) ;
}

u_long hwt_read(struct s_smc *smc)
{
	u_short	tr ;
	u_long	is ;

	if (smc->hw.timer_activ) {
		hwt_stop(smc) ;
		tr = (u_short)((inpd(ADDR(B2_TI_VAL))/200) & 0xffff) ;

		is = GET_ISR() ;
		/* Check if timer expired (or wraparound). */
		if ((tr > smc->hw.t_start) || (is & IS_TIMINT)) {
			hwt_restart(smc) ;
			smc->hw.t_stop = smc->hw.t_start ;
		}
		else
			smc->hw.t_stop = smc->hw.t_start - tr ;
	}
	return smc->hw.t_stop;
}

