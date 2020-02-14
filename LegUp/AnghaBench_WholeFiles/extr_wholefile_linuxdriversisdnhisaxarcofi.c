#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct timer_list {int dummy; } ;
struct TYPE_13__ {scalar_t__ expires; } ;
struct TYPE_12__ {int* mon_tx; int arcofi_bc; int mocr; int arcofi_state; int /*<<< orphan*/  arcofi_wait; TYPE_5__ arcofitimer; TYPE_3__* arcofi_list; scalar_t__ mon_txp; int /*<<< orphan*/  mon_txc; } ;
struct TYPE_10__ {TYPE_4__ isac; } ;
struct IsdnCardState {int debug; int /*<<< orphan*/  HW_Flags; TYPE_2__ dc; int /*<<< orphan*/  (* writeisac ) (struct IsdnCardState*,int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* readisac ) (struct IsdnCardState*,int /*<<< orphan*/ ) ;} ;
struct TYPE_9__ {int /*<<< orphan*/  arcofitimer; } ;
struct TYPE_14__ {TYPE_1__ isac; } ;
struct TYPE_11__ {struct TYPE_11__* next; int /*<<< orphan*/  receive; int /*<<< orphan*/  msg; int /*<<< orphan*/  len; } ;

/* Variables and functions */
#define  ARCOFI_NOP 130 
#define  ARCOFI_RECEIVE 129 
 int ARCOFI_RX_END ; 
 int ARCOFI_START ; 
 int ARCOFI_TIMEOUT ; 
 int ARCOFI_TIMER_VALUE ; 
#define  ARCOFI_TRANSMIT 128 
 int ARCOFI_TX_END ; 
 int /*<<< orphan*/  FLG_ARCOFI_ERROR ; 
 int /*<<< orphan*/  FLG_ARCOFI_TIMER ; 
 int /*<<< orphan*/  HW_ARCOFI ; 
 int HZ ; 
 int /*<<< orphan*/  ISAC_MOCR ; 
 int /*<<< orphan*/  ISAC_MOSR ; 
 int /*<<< orphan*/  ISAC_MOX1 ; 
 int L1_DEB_MONITOR ; 
 int /*<<< orphan*/  add_timer (TYPE_5__*) ; 
 struct IsdnCardState* cs ; 
 TYPE_7__ dc ; 
 int /*<<< orphan*/  debugl1 (struct IsdnCardState*,char*,int,...) ; 
 int /*<<< orphan*/  del_timer (TYPE_5__*) ; 
 struct IsdnCardState* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  memcpy (int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct IsdnCardState*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub2 (struct IsdnCardState*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (struct IsdnCardState*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub4 (struct IsdnCardState*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ test_and_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timer_setup (TYPE_5__*,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
add_arcofi_timer(struct IsdnCardState *cs) {
	if (test_and_set_bit(FLG_ARCOFI_TIMER, &cs->HW_Flags)) {
		del_timer(&cs->dc.isac.arcofitimer);
	}
	cs->dc.isac.arcofitimer.expires = jiffies + ((ARCOFI_TIMER_VALUE * HZ) / 1000);
	add_timer(&cs->dc.isac.arcofitimer);
}

__attribute__((used)) static void
send_arcofi(struct IsdnCardState *cs) {
	add_arcofi_timer(cs);
	cs->dc.isac.mon_txp = 0;
	cs->dc.isac.mon_txc = cs->dc.isac.arcofi_list->len;
	memcpy(cs->dc.isac.mon_tx, cs->dc.isac.arcofi_list->msg, cs->dc.isac.mon_txc);
	switch (cs->dc.isac.arcofi_bc) {
	case 0: break;
	case 1: cs->dc.isac.mon_tx[1] |= 0x40;
		break;
	default: break;
	}
	cs->dc.isac.mocr &= 0x0f;
	cs->dc.isac.mocr |= 0xa0;
	cs->writeisac(cs, ISAC_MOCR, cs->dc.isac.mocr);
	(void) cs->readisac(cs, ISAC_MOSR);
	cs->writeisac(cs, ISAC_MOX1, cs->dc.isac.mon_tx[cs->dc.isac.mon_txp++]);
	cs->dc.isac.mocr |= 0x10;
	cs->writeisac(cs, ISAC_MOCR, cs->dc.isac.mocr);
}

int
arcofi_fsm(struct IsdnCardState *cs, int event, void *data) {
	if (cs->debug & L1_DEB_MONITOR) {
		debugl1(cs, "arcofi state %d event %d", cs->dc.isac.arcofi_state, event);
	}
	if (event == ARCOFI_TIMEOUT) {
		cs->dc.isac.arcofi_state = ARCOFI_NOP;
		test_and_set_bit(FLG_ARCOFI_ERROR, &cs->HW_Flags);
		wake_up(&cs->dc.isac.arcofi_wait);
		return (1);
	}
	switch (cs->dc.isac.arcofi_state) {
	case ARCOFI_NOP:
		if (event == ARCOFI_START) {
			cs->dc.isac.arcofi_list = data;
			cs->dc.isac.arcofi_state = ARCOFI_TRANSMIT;
			send_arcofi(cs);
		}
		break;
	case ARCOFI_TRANSMIT:
		if (event == ARCOFI_TX_END) {
			if (cs->dc.isac.arcofi_list->receive) {
				add_arcofi_timer(cs);
				cs->dc.isac.arcofi_state = ARCOFI_RECEIVE;
			} else {
				if (cs->dc.isac.arcofi_list->next) {
					cs->dc.isac.arcofi_list =
						cs->dc.isac.arcofi_list->next;
					send_arcofi(cs);
				} else {
					if (test_and_clear_bit(FLG_ARCOFI_TIMER, &cs->HW_Flags)) {
						del_timer(&cs->dc.isac.arcofitimer);
					}
					cs->dc.isac.arcofi_state = ARCOFI_NOP;
					wake_up(&cs->dc.isac.arcofi_wait);
				}
			}
		}
		break;
	case ARCOFI_RECEIVE:
		if (event == ARCOFI_RX_END) {
			if (cs->dc.isac.arcofi_list->next) {
				cs->dc.isac.arcofi_list =
					cs->dc.isac.arcofi_list->next;
				cs->dc.isac.arcofi_state = ARCOFI_TRANSMIT;
				send_arcofi(cs);
			} else {
				if (test_and_clear_bit(FLG_ARCOFI_TIMER, &cs->HW_Flags)) {
					del_timer(&cs->dc.isac.arcofitimer);
				}
				cs->dc.isac.arcofi_state = ARCOFI_NOP;
				wake_up(&cs->dc.isac.arcofi_wait);
			}
		}
		break;
	default:
		debugl1(cs, "Arcofi unknown state %x", cs->dc.isac.arcofi_state);
		return (2);
	}
	return (0);
}

__attribute__((used)) static void
arcofi_timer(struct timer_list *t) {
	struct IsdnCardState *cs = from_timer(cs, t, dc.isac.arcofitimer);
	arcofi_fsm(cs, ARCOFI_TIMEOUT, NULL);
}

void
clear_arcofi(struct IsdnCardState *cs) {
	if (test_and_clear_bit(FLG_ARCOFI_TIMER, &cs->HW_Flags)) {
		del_timer(&cs->dc.isac.arcofitimer);
	}
}

void
init_arcofi(struct IsdnCardState *cs) {
	timer_setup(&cs->dc.isac.arcofitimer, arcofi_timer, 0);
	init_waitqueue_head(&cs->dc.isac.arcofi_wait);
	test_and_set_bit(HW_ARCOFI, &cs->HW_Flags);
}

