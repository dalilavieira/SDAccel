#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct vnt_usb_send_context {scalar_t__ fb_option; int in_use; int /*<<< orphan*/  skb; } ;
struct TYPE_16__ {int in_use; scalar_t__ data_buf; } ;
struct ieee80211_low_level_stats {int /*<<< orphan*/  dot11FCSErrorCount; int /*<<< orphan*/  dot11ACKFailureCount; int /*<<< orphan*/  dot11RTSFailureCount; int /*<<< orphan*/  dot11RTSSuccessCount; } ;
struct vnt_private {int num_tx_context; scalar_t__ op_mode; int wake_up_count; TYPE_7__ int_buf; int /*<<< orphan*/  current_tsf; TYPE_8__* hw; TYPE_5__* usb; struct ieee80211_low_level_stats low_stats; struct vnt_usb_send_context** tx_context; int /*<<< orphan*/  lock; } ;
struct vnt_interrupt_data {int tsr0; int pkt0; int tsr1; int pkt1; int tsr2; int pkt2; int tsr3; int pkt3; int isr0; scalar_t__ fcs_err; scalar_t__ ack_fail; scalar_t__ rts_fail; scalar_t__ rts_success; int /*<<< orphan*/  tsf; } ;
struct TYPE_13__ {TYPE_3__* rates; } ;
struct TYPE_11__ {TYPE_1__* rates; } ;
struct ieee80211_tx_info {scalar_t__ band; int /*<<< orphan*/  flags; TYPE_4__ status; TYPE_2__ control; } ;
struct ieee80211_rate {int hw_value; } ;
typedef  int s8 ;
struct TYPE_15__ {int flags; int listen_interval; } ;
struct TYPE_17__ {TYPE_6__ conf; } ;
struct TYPE_14__ {int /*<<< orphan*/  dev; } ;
struct TYPE_12__ {int count; int idx; } ;
struct TYPE_10__ {int idx; } ;

/* Variables and functions */
 scalar_t__ AUTO_FB_0 ; 
 scalar_t__ AUTO_FB_1 ; 
 int EINVAL ; 
 int IEEE80211_CONF_PS ; 
 struct ieee80211_tx_info* IEEE80211_SKB_CB (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IEEE80211_TX_STAT_ACK ; 
 int ISR_BNTX ; 
 int ISR_TBTT ; 
 scalar_t__ NL80211_BAND_5GHZ ; 
 scalar_t__ NL80211_IFTYPE_AP ; 
 int RATE_18M ; 
 int RATE_6M ; 
 int TSR_RETRYTMO ; 
 int TSR_TMO ; 
 int TSR_VALID ; 
 int /*<<< orphan*/  WLAN_CMD_BECON_SEND ; 
 int /*<<< orphan*/  WLAN_CMD_TBTT_WAKEUP ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int** fallback_rate0 ; 
 int** fallback_rate1 ; 
 struct ieee80211_rate* ieee80211_get_tx_rate (TYPE_8__*,struct ieee80211_tx_info*) ; 
 int /*<<< orphan*/  ieee80211_tx_info_clear_status (struct ieee80211_tx_info*) ; 
 int /*<<< orphan*/  ieee80211_tx_status_irqsafe (TYPE_8__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  vnt_schedule_command (struct vnt_private*,int /*<<< orphan*/ ) ; 
 int vnt_start_interrupt_urb (struct vnt_private*) ; 

void vnt_int_start_interrupt(struct vnt_private *priv)
{
	unsigned long flags;
	int status;

	dev_dbg(&priv->usb->dev, "---->Interrupt Polling Thread\n");

	spin_lock_irqsave(&priv->lock, flags);

	status = vnt_start_interrupt_urb(priv);

	spin_unlock_irqrestore(&priv->lock, flags);
}

__attribute__((used)) static int vnt_int_report_rate(struct vnt_private *priv, u8 pkt_no, u8 tsr)
{
	struct vnt_usb_send_context *context;
	struct ieee80211_tx_info *info;
	struct ieee80211_rate *rate;
	u8 tx_retry = (tsr & 0xf0) >> 4;
	s8 idx;

	if (pkt_no >= priv->num_tx_context)
		return -EINVAL;

	context = priv->tx_context[pkt_no];

	if (!context->skb)
		return -EINVAL;

	info = IEEE80211_SKB_CB(context->skb);
	idx = info->control.rates[0].idx;

	if (context->fb_option && !(tsr & (TSR_TMO | TSR_RETRYTMO))) {
		u8 tx_rate;
		u8 retry = tx_retry;

		rate = ieee80211_get_tx_rate(priv->hw, info);
		tx_rate = rate->hw_value - RATE_18M;

		if (retry > 4)
			retry = 4;

		if (context->fb_option == AUTO_FB_0)
			tx_rate = fallback_rate0[tx_rate][retry];
		else if (context->fb_option == AUTO_FB_1)
			tx_rate = fallback_rate1[tx_rate][retry];

		if (info->band == NL80211_BAND_5GHZ)
			idx = tx_rate - RATE_6M;
		else
			idx = tx_rate;
	}

	ieee80211_tx_info_clear_status(info);

	info->status.rates[0].count = tx_retry;

	if (!(tsr & (TSR_TMO | TSR_RETRYTMO))) {
		info->status.rates[0].idx = idx;
		info->flags |= IEEE80211_TX_STAT_ACK;
	}

	ieee80211_tx_status_irqsafe(priv->hw, context->skb);

	context->in_use = false;

	return 0;
}

void vnt_int_process_data(struct vnt_private *priv)
{
	struct vnt_interrupt_data *int_data;
	struct ieee80211_low_level_stats *low_stats = &priv->low_stats;

	dev_dbg(&priv->usb->dev, "---->s_nsInterruptProcessData\n");

	int_data = (struct vnt_interrupt_data *)priv->int_buf.data_buf;

	if (int_data->tsr0 & TSR_VALID)
		vnt_int_report_rate(priv, int_data->pkt0, int_data->tsr0);

	if (int_data->tsr1 & TSR_VALID)
		vnt_int_report_rate(priv, int_data->pkt1, int_data->tsr1);

	if (int_data->tsr2 & TSR_VALID)
		vnt_int_report_rate(priv, int_data->pkt2, int_data->tsr2);

	if (int_data->tsr3 & TSR_VALID)
		vnt_int_report_rate(priv, int_data->pkt3, int_data->tsr3);

	if (int_data->isr0 != 0) {
		if (int_data->isr0 & ISR_BNTX &&
		    priv->op_mode == NL80211_IFTYPE_AP)
			vnt_schedule_command(priv, WLAN_CMD_BECON_SEND);

		if (int_data->isr0 & ISR_TBTT &&
		    priv->hw->conf.flags & IEEE80211_CONF_PS) {
			if (!priv->wake_up_count)
				priv->wake_up_count =
					priv->hw->conf.listen_interval;

			--priv->wake_up_count;

			/* Turn on wake up to listen next beacon */
			if (priv->wake_up_count == 1)
				vnt_schedule_command(priv,
						     WLAN_CMD_TBTT_WAKEUP);
		}
		priv->current_tsf = le64_to_cpu(int_data->tsf);

		low_stats->dot11RTSSuccessCount += int_data->rts_success;
		low_stats->dot11RTSFailureCount += int_data->rts_fail;
		low_stats->dot11ACKFailureCount += int_data->ack_fail;
		low_stats->dot11FCSErrorCount += int_data->fcs_err;
	}

	priv->int_buf.in_use = false;
}

