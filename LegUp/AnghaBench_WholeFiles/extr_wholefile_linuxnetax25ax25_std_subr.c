#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_13__ {int condition; scalar_t__ modulus; scalar_t__ n2count; } ;
typedef  TYPE_1__ ax25_cb ;

/* Variables and functions */
 int /*<<< orphan*/  AX25_COMMAND ; 
 int AX25_COND_ACK_PENDING ; 
 int AX25_COND_OWN_RX_BUSY ; 
 scalar_t__ AX25_MODULUS ; 
 int /*<<< orphan*/  AX25_POLLOFF ; 
 int /*<<< orphan*/  AX25_POLLON ; 
 int /*<<< orphan*/  AX25_RESPONSE ; 
 int /*<<< orphan*/  AX25_RNR ; 
 int /*<<< orphan*/  AX25_RR ; 
 int /*<<< orphan*/  AX25_SABM ; 
 int /*<<< orphan*/  AX25_SABME ; 
 int /*<<< orphan*/  ax25_calculate_t1 (TYPE_1__*) ; 
 int /*<<< orphan*/  ax25_send_control (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ax25_start_t1timer (TYPE_1__*) ; 
 void ax25_std_establish_data_link (TYPE_1__*) ; 
 int /*<<< orphan*/  ax25_stop_idletimer (TYPE_1__*) ; 
 int /*<<< orphan*/  ax25_stop_t2timer (TYPE_1__*) ; 
 int /*<<< orphan*/  ax25_stop_t3timer (TYPE_1__*) ; 

void ax25_std_nr_error_recovery(ax25_cb *ax25)
{
	ax25_std_establish_data_link(ax25);
}

void ax25_std_establish_data_link(ax25_cb *ax25)
{
	ax25->condition = 0x00;
	ax25->n2count   = 0;

	if (ax25->modulus == AX25_MODULUS)
		ax25_send_control(ax25, AX25_SABM, AX25_POLLON, AX25_COMMAND);
	else
		ax25_send_control(ax25, AX25_SABME, AX25_POLLON, AX25_COMMAND);

	ax25_calculate_t1(ax25);
	ax25_stop_idletimer(ax25);
	ax25_stop_t3timer(ax25);
	ax25_stop_t2timer(ax25);
	ax25_start_t1timer(ax25);
}

void ax25_std_transmit_enquiry(ax25_cb *ax25)
{
	if (ax25->condition & AX25_COND_OWN_RX_BUSY)
		ax25_send_control(ax25, AX25_RNR, AX25_POLLON, AX25_COMMAND);
	else
		ax25_send_control(ax25, AX25_RR, AX25_POLLON, AX25_COMMAND);

	ax25->condition &= ~AX25_COND_ACK_PENDING;

	ax25_calculate_t1(ax25);
	ax25_start_t1timer(ax25);
}

void ax25_std_enquiry_response(ax25_cb *ax25)
{
	if (ax25->condition & AX25_COND_OWN_RX_BUSY)
		ax25_send_control(ax25, AX25_RNR, AX25_POLLON, AX25_RESPONSE);
	else
		ax25_send_control(ax25, AX25_RR, AX25_POLLON, AX25_RESPONSE);

	ax25->condition &= ~AX25_COND_ACK_PENDING;
}

void ax25_std_timeout_response(ax25_cb *ax25)
{
	if (ax25->condition & AX25_COND_OWN_RX_BUSY)
		ax25_send_control(ax25, AX25_RNR, AX25_POLLOFF, AX25_RESPONSE);
	else
		ax25_send_control(ax25, AX25_RR, AX25_POLLOFF, AX25_RESPONSE);

	ax25->condition &= ~AX25_COND_ACK_PENDING;
}

