#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int dummy; } ;
struct TYPE_31__ {int modulus; int va; int vr; int state; int condition; int /*<<< orphan*/  n2count; int /*<<< orphan*/  vs; TYPE_1__* ax25_dev; int /*<<< orphan*/  window; TYPE_3__* sk; } ;
typedef  TYPE_2__ ax25_cb ;
struct TYPE_32__ {int /*<<< orphan*/  (* sk_state_change ) (TYPE_3__*) ;int /*<<< orphan*/  sk_state; } ;
struct TYPE_30__ {int /*<<< orphan*/ * values; } ;

/* Variables and functions */
 int AX25_COMMAND ; 
 int AX25_COND_ACK_PENDING ; 
 int AX25_COND_OWN_RX_BUSY ; 
 int AX25_COND_PEER_RX_BUSY ; 
 int AX25_COND_REJECT ; 
#define  AX25_DISC 141 
#define  AX25_DM 140 
 void* AX25_EMODULUS ; 
#define  AX25_FRMR 139 
#define  AX25_I 138 
#define  AX25_ILLEGAL 137 
 void* AX25_MODULUS ; 
 int AX25_POLLON ; 
#define  AX25_REJ 136 
 int AX25_RESPONSE ; 
#define  AX25_RNR 135 
#define  AX25_RR 134 
#define  AX25_SABM 133 
#define  AX25_SABME 132 
#define  AX25_STATE_1 131 
#define  AX25_STATE_2 130 
#define  AX25_STATE_3 129 
#define  AX25_UA 128 
 size_t AX25_VALUES_EWINDOW ; 
 size_t AX25_VALUES_WINDOW ; 
 int /*<<< orphan*/  ECONNREFUSED ; 
 int /*<<< orphan*/  ECONNRESET ; 
 int /*<<< orphan*/  SOCK_DEAD ; 
 int /*<<< orphan*/  TCP_ESTABLISHED ; 
 int /*<<< orphan*/  ax25_calculate_rtt (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_check_iframes_acked (TYPE_2__*,int) ; 
 int /*<<< orphan*/  ax25_dama_off (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_dama_on (TYPE_2__*) ; 
 int ax25_decode (TYPE_2__*,struct sk_buff*,int*,int*,int*) ; 
 int /*<<< orphan*/  ax25_disconnect (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ax25_ds_enquiry_response (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_ds_establish_data_link (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_ds_nr_error_recovery (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_frames_acked (TYPE_2__*,int) ; 
 int /*<<< orphan*/  ax25_requeue_frames (TYPE_2__*) ; 
 int ax25_rx_iframe (TYPE_2__*,struct sk_buff*) ; 
 int /*<<< orphan*/  ax25_send_control (TYPE_2__*,int const,int,int) ; 
 int /*<<< orphan*/  ax25_start_idletimer (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_start_t2timer (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_start_t3timer (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_std_enquiry_response (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_stop_t1timer (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_validate_nr (TYPE_2__*,int) ; 
 int /*<<< orphan*/  bh_lock_sock (TYPE_3__*) ; 
 int /*<<< orphan*/  bh_unlock_sock (TYPE_3__*) ; 
 int /*<<< orphan*/  sock_flag (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (TYPE_3__*) ; 

__attribute__((used)) static int ax25_ds_state1_machine(ax25_cb *ax25, struct sk_buff *skb, int frametype, int pf, int type)
{
	switch (frametype) {
	case AX25_SABM:
		ax25->modulus = AX25_MODULUS;
		ax25->window  = ax25->ax25_dev->values[AX25_VALUES_WINDOW];
		ax25_send_control(ax25, AX25_UA, pf, AX25_RESPONSE);
		break;

	case AX25_SABME:
		ax25->modulus = AX25_EMODULUS;
		ax25->window  =  ax25->ax25_dev->values[AX25_VALUES_EWINDOW];
		ax25_send_control(ax25, AX25_UA, pf, AX25_RESPONSE);
		break;

	case AX25_DISC:
		ax25_send_control(ax25, AX25_DM, pf, AX25_RESPONSE);
		break;

	case AX25_UA:
		ax25_calculate_rtt(ax25);
		ax25_stop_t1timer(ax25);
		ax25_start_t3timer(ax25);
		ax25_start_idletimer(ax25);
		ax25->vs      = 0;
		ax25->va      = 0;
		ax25->vr      = 0;
		ax25->state   = AX25_STATE_3;
		ax25->n2count = 0;
		if (ax25->sk != NULL) {
			bh_lock_sock(ax25->sk);
			ax25->sk->sk_state = TCP_ESTABLISHED;
			/*
			 * For WAIT_SABM connections we will produce an accept
			 * ready socket here
			 */
			if (!sock_flag(ax25->sk, SOCK_DEAD))
				ax25->sk->sk_state_change(ax25->sk);
			bh_unlock_sock(ax25->sk);
		}
		ax25_dama_on(ax25);

		/* according to DK4EG's spec we are required to
		 * send a RR RESPONSE FINAL NR=0.
		 */

		ax25_std_enquiry_response(ax25);
		break;

	case AX25_DM:
		if (pf)
			ax25_disconnect(ax25, ECONNREFUSED);
		break;

	default:
		if (pf)
			ax25_send_control(ax25, AX25_SABM, AX25_POLLON, AX25_COMMAND);
		break;
	}

	return 0;
}

__attribute__((used)) static int ax25_ds_state2_machine(ax25_cb *ax25, struct sk_buff *skb, int frametype, int pf, int type)
{
	switch (frametype) {
	case AX25_SABM:
	case AX25_SABME:
		ax25_send_control(ax25, AX25_DISC, AX25_POLLON, AX25_COMMAND);
		ax25_dama_off(ax25);
		break;

	case AX25_DISC:
		ax25_send_control(ax25, AX25_UA, pf, AX25_RESPONSE);
		ax25_dama_off(ax25);
		ax25_disconnect(ax25, 0);
		break;

	case AX25_DM:
	case AX25_UA:
		if (pf) {
			ax25_dama_off(ax25);
			ax25_disconnect(ax25, 0);
		}
		break;

	case AX25_I:
	case AX25_REJ:
	case AX25_RNR:
	case AX25_RR:
		if (pf) {
			ax25_send_control(ax25, AX25_DISC, AX25_POLLON, AX25_COMMAND);
			ax25_dama_off(ax25);
		}
		break;

	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int ax25_ds_state3_machine(ax25_cb *ax25, struct sk_buff *skb, int frametype, int ns, int nr, int pf, int type)
{
	int queued = 0;

	switch (frametype) {
	case AX25_SABM:
	case AX25_SABME:
		if (frametype == AX25_SABM) {
			ax25->modulus   = AX25_MODULUS;
			ax25->window    = ax25->ax25_dev->values[AX25_VALUES_WINDOW];
		} else {
			ax25->modulus   = AX25_EMODULUS;
			ax25->window    = ax25->ax25_dev->values[AX25_VALUES_EWINDOW];
		}
		ax25_send_control(ax25, AX25_UA, pf, AX25_RESPONSE);
		ax25_stop_t1timer(ax25);
		ax25_start_t3timer(ax25);
		ax25_start_idletimer(ax25);
		ax25->condition = 0x00;
		ax25->vs        = 0;
		ax25->va        = 0;
		ax25->vr        = 0;
		ax25_requeue_frames(ax25);
		ax25_dama_on(ax25);
		break;

	case AX25_DISC:
		ax25_send_control(ax25, AX25_UA, pf, AX25_RESPONSE);
		ax25_dama_off(ax25);
		ax25_disconnect(ax25, 0);
		break;

	case AX25_DM:
		ax25_dama_off(ax25);
		ax25_disconnect(ax25, ECONNRESET);
		break;

	case AX25_RR:
	case AX25_RNR:
		if (frametype == AX25_RR)
			ax25->condition &= ~AX25_COND_PEER_RX_BUSY;
		else
			ax25->condition |= AX25_COND_PEER_RX_BUSY;

		if (ax25_validate_nr(ax25, nr)) {
			if (ax25_check_iframes_acked(ax25, nr))
				ax25->n2count=0;
			if (type == AX25_COMMAND && pf)
				ax25_ds_enquiry_response(ax25);
		} else {
			ax25_ds_nr_error_recovery(ax25);
			ax25->state = AX25_STATE_1;
		}
		break;

	case AX25_REJ:
		ax25->condition &= ~AX25_COND_PEER_RX_BUSY;

		if (ax25_validate_nr(ax25, nr)) {
			if (ax25->va != nr)
				ax25->n2count=0;

			ax25_frames_acked(ax25, nr);
			ax25_calculate_rtt(ax25);
			ax25_stop_t1timer(ax25);
			ax25_start_t3timer(ax25);
			ax25_requeue_frames(ax25);

			if (type == AX25_COMMAND && pf)
				ax25_ds_enquiry_response(ax25);
		} else {
			ax25_ds_nr_error_recovery(ax25);
			ax25->state = AX25_STATE_1;
		}
		break;

	case AX25_I:
		if (!ax25_validate_nr(ax25, nr)) {
			ax25_ds_nr_error_recovery(ax25);
			ax25->state = AX25_STATE_1;
			break;
		}
		if (ax25->condition & AX25_COND_PEER_RX_BUSY) {
			ax25_frames_acked(ax25, nr);
			ax25->n2count = 0;
		} else {
			if (ax25_check_iframes_acked(ax25, nr))
				ax25->n2count = 0;
		}
		if (ax25->condition & AX25_COND_OWN_RX_BUSY) {
			if (pf) ax25_ds_enquiry_response(ax25);
			break;
		}
		if (ns == ax25->vr) {
			ax25->vr = (ax25->vr + 1) % ax25->modulus;
			queued = ax25_rx_iframe(ax25, skb);
			if (ax25->condition & AX25_COND_OWN_RX_BUSY)
				ax25->vr = ns;	/* ax25->vr - 1 */
			ax25->condition &= ~AX25_COND_REJECT;
			if (pf) {
				ax25_ds_enquiry_response(ax25);
			} else {
				if (!(ax25->condition & AX25_COND_ACK_PENDING)) {
					ax25->condition |= AX25_COND_ACK_PENDING;
					ax25_start_t2timer(ax25);
				}
			}
		} else {
			if (ax25->condition & AX25_COND_REJECT) {
				if (pf) ax25_ds_enquiry_response(ax25);
			} else {
				ax25->condition |= AX25_COND_REJECT;
				ax25_ds_enquiry_response(ax25);
				ax25->condition &= ~AX25_COND_ACK_PENDING;
			}
		}
		break;

	case AX25_FRMR:
	case AX25_ILLEGAL:
		ax25_ds_establish_data_link(ax25);
		ax25->state = AX25_STATE_1;
		break;

	default:
		break;
	}

	return queued;
}

int ax25_ds_frame_in(ax25_cb *ax25, struct sk_buff *skb, int type)
{
	int queued = 0, frametype, ns, nr, pf;

	frametype = ax25_decode(ax25, skb, &ns, &nr, &pf);

	switch (ax25->state) {
	case AX25_STATE_1:
		queued = ax25_ds_state1_machine(ax25, skb, frametype, pf, type);
		break;
	case AX25_STATE_2:
		queued = ax25_ds_state2_machine(ax25, skb, frametype, pf, type);
		break;
	case AX25_STATE_3:
		queued = ax25_ds_state3_machine(ax25, skb, frametype, ns, nr, pf, type);
		break;
	}

	return queued;
}

