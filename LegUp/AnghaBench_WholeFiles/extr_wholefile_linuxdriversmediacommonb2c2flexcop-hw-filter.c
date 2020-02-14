#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_7__ ;
typedef  struct TYPE_23__   TYPE_6__ ;
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  void* u8 ;
typedef  int u16 ;
struct flexcop_device {int skip_6_hw_pid_filter; int has_32_hw_pid_filter; int fullts_streaming_state; int feedcount; scalar_t__ extra_feedcount; int /*<<< orphan*/  (* write_ibi_reg ) (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_7__) ;TYPE_7__ (* read_ibi_reg ) (struct flexcop_device*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* stream_control ) (struct flexcop_device*,int) ;scalar_t__ pid_filtering; } ;
struct dvb_demux_feed {int index; int pid; } ;
struct TYPE_18__ {int EMM_filter_4; scalar_t__ EMM_filter_6; } ;
struct TYPE_23__ {int PID; int PID_enable_bit; } ;
struct TYPE_22__ {int index_reg; } ;
struct TYPE_21__ {int Group_PID; int Group_mask; } ;
struct TYPE_20__ {void* MAC8; void* MAC7; } ;
struct TYPE_19__ {void* MAC6; void* MAC3; void* MAC2; void* MAC1; } ;
struct TYPE_24__ {TYPE_1__ pid_filter_308; TYPE_6__ pid_n_reg_314; TYPE_5__ index_reg_310; TYPE_4__ pid_filter_30c_ext_ind_0_7; TYPE_3__ mac_address_41c; TYPE_2__ mac_address_418; } ;
typedef  TYPE_7__ flexcop_ibi_value ;

/* Variables and functions */
 int /*<<< orphan*/  ECM_PID ; 
 int /*<<< orphan*/  ECM_filter_sig ; 
 int /*<<< orphan*/  ECM_trans ; 
 int /*<<< orphan*/  EMM_PID ; 
 int /*<<< orphan*/  EMM_filter_sig ; 
 int /*<<< orphan*/  EMM_trans ; 
 int /*<<< orphan*/  MAC_filter_Mode_sig ; 
 int /*<<< orphan*/  Mask_filter_sig ; 
 int /*<<< orphan*/  Null_filter_sig ; 
 int /*<<< orphan*/  PCR_PID ; 
 int /*<<< orphan*/  PCR_filter_sig ; 
 int /*<<< orphan*/  PCR_trans ; 
 int /*<<< orphan*/  PMT_PID ; 
 int /*<<< orphan*/  PMT_filter_sig ; 
 int /*<<< orphan*/  PMT_trans ; 
 int /*<<< orphan*/  Rcv_Data_sig ; 
 int /*<<< orphan*/  SMC_Enable_sig ; 
 int /*<<< orphan*/  Stream1_PID ; 
 int /*<<< orphan*/  Stream1_filter_sig ; 
 int /*<<< orphan*/  Stream1_trans ; 
 int /*<<< orphan*/  Stream2_PID ; 
 int /*<<< orphan*/  Stream2_filter_sig ; 
 int /*<<< orphan*/  Stream2_trans ; 
 int /*<<< orphan*/  ctrl_208 ; 
 int /*<<< orphan*/  deb_ts (char*,...) ; 
 void flexcop_hw_filter_init (struct flexcop_device*) ; 
 int /*<<< orphan*/  flexcop_reset_block_300 (struct flexcop_device*) ; 
 int /*<<< orphan*/  flexcop_set_ibi_value (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  index_reg_310 ; 
 int /*<<< orphan*/  mac_address_418 ; 
 int /*<<< orphan*/  mac_address_41c ; 
 int /*<<< orphan*/  pid_ctrl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pid_filter_300 ; 
 int /*<<< orphan*/  pid_filter_304 ; 
 int /*<<< orphan*/  pid_filter_308 ; 
 int /*<<< orphan*/  pid_filter_30c ; 
 int /*<<< orphan*/  pid_n_reg_314 ; 
 TYPE_7__ stub1 (struct flexcop_device*,int /*<<< orphan*/ ) ; 
 TYPE_7__ stub10 (struct flexcop_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_7__) ; 
 int /*<<< orphan*/  stub2 (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_7__) ; 
 int /*<<< orphan*/  stub3 (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_7__) ; 
 int /*<<< orphan*/  stub4 (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_7__) ; 
 TYPE_7__ stub5 (struct flexcop_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_7__) ; 
 TYPE_7__ stub7 (struct flexcop_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_7__) ; 
 int /*<<< orphan*/  stub9 (struct flexcop_device*,int) ; 

__attribute__((used)) static void flexcop_rcv_data_ctrl(struct flexcop_device *fc, int onoff)
{
	flexcop_set_ibi_value(ctrl_208, Rcv_Data_sig, onoff);
	deb_ts("rcv_data is now: '%s'\n", onoff ? "on" : "off");
}

void flexcop_smc_ctrl(struct flexcop_device *fc, int onoff)
{
	flexcop_set_ibi_value(ctrl_208, SMC_Enable_sig, onoff);
}

__attribute__((used)) static void flexcop_null_filter_ctrl(struct flexcop_device *fc, int onoff)
{
	flexcop_set_ibi_value(ctrl_208, Null_filter_sig, onoff);
}

void flexcop_set_mac_filter(struct flexcop_device *fc, u8 mac[6])
{
	flexcop_ibi_value v418, v41c;
	v41c = fc->read_ibi_reg(fc, mac_address_41c);

	v418.mac_address_418.MAC1 = mac[0];
	v418.mac_address_418.MAC2 = mac[1];
	v418.mac_address_418.MAC3 = mac[2];
	v418.mac_address_418.MAC6 = mac[3];
	v41c.mac_address_41c.MAC7 = mac[4];
	v41c.mac_address_41c.MAC8 = mac[5];

	fc->write_ibi_reg(fc, mac_address_418, v418);
	fc->write_ibi_reg(fc, mac_address_41c, v41c);
}

void flexcop_mac_filter_ctrl(struct flexcop_device *fc, int onoff)
{
	flexcop_set_ibi_value(ctrl_208, MAC_filter_Mode_sig, onoff);
}

__attribute__((used)) static void flexcop_pid_group_filter(struct flexcop_device *fc,
		u16 pid, u16 mask)
{
	/* index_reg_310.extra_index_reg need to 0 or 7 to work */
	flexcop_ibi_value v30c;
	v30c.pid_filter_30c_ext_ind_0_7.Group_PID = pid;
	v30c.pid_filter_30c_ext_ind_0_7.Group_mask = mask;
	fc->write_ibi_reg(fc, pid_filter_30c, v30c);
}

__attribute__((used)) static void flexcop_pid_group_filter_ctrl(struct flexcop_device *fc, int onoff)
{
	flexcop_set_ibi_value(ctrl_208, Mask_filter_sig, onoff);
}

__attribute__((used)) static void flexcop_pid_Stream1_PID_ctrl(struct flexcop_device *fc,
		u16 pid, int onoff)
{
	pid_ctrl(pid_filter_300, Stream1_PID, Stream1_filter_sig,
			Stream1_trans, 0);
}

__attribute__((used)) static void flexcop_pid_Stream2_PID_ctrl(struct flexcop_device *fc,
		u16 pid, int onoff)
{
	pid_ctrl(pid_filter_300, Stream2_PID, Stream2_filter_sig,
			Stream2_trans, 0);
}

__attribute__((used)) static void flexcop_pid_PCR_PID_ctrl(struct flexcop_device *fc,
		u16 pid, int onoff)
{
	pid_ctrl(pid_filter_304, PCR_PID, PCR_filter_sig, PCR_trans, 0);
}

__attribute__((used)) static void flexcop_pid_PMT_PID_ctrl(struct flexcop_device *fc,
		u16 pid, int onoff)
{
	pid_ctrl(pid_filter_304, PMT_PID, PMT_filter_sig, PMT_trans, 0);
}

__attribute__((used)) static void flexcop_pid_EMM_PID_ctrl(struct flexcop_device *fc,
		u16 pid, int onoff)
{
	pid_ctrl(pid_filter_308, EMM_PID, EMM_filter_sig, EMM_trans, 0);
}

__attribute__((used)) static void flexcop_pid_ECM_PID_ctrl(struct flexcop_device *fc,
		u16 pid, int onoff)
{
	pid_ctrl(pid_filter_308, ECM_PID, ECM_filter_sig, ECM_trans, 0);
}

__attribute__((used)) static void flexcop_pid_control(struct flexcop_device *fc,
		int index, u16 pid, int onoff)
{
	if (pid == 0x2000)
		return;

	deb_ts("setting pid: %5d %04x at index %d '%s'\n",
			pid, pid, index, onoff ? "on" : "off");

	/* First 6 can be buggy - skip over them if option set */
	if (fc->skip_6_hw_pid_filter)
		index += 6;

	/* We could use bit magic here to reduce source code size.
	 * I decided against it, but to use the real register names */
	switch (index) {
	case 0:
		flexcop_pid_Stream1_PID_ctrl(fc, pid, onoff);
		break;
	case 1:
		flexcop_pid_Stream2_PID_ctrl(fc, pid, onoff);
		break;
	case 2:
		flexcop_pid_PCR_PID_ctrl(fc, pid, onoff);
		break;
	case 3:
		flexcop_pid_PMT_PID_ctrl(fc, pid, onoff);
		break;
	case 4:
		flexcop_pid_EMM_PID_ctrl(fc, pid, onoff);
		break;
	case 5:
		flexcop_pid_ECM_PID_ctrl(fc, pid, onoff);
		break;
	default:
		if (fc->has_32_hw_pid_filter && index < 38) {
			flexcop_ibi_value vpid, vid;

			/* set the index */
			vid = fc->read_ibi_reg(fc, index_reg_310);
			vid.index_reg_310.index_reg = index - 6;
			fc->write_ibi_reg(fc, index_reg_310, vid);

			vpid = fc->read_ibi_reg(fc, pid_n_reg_314);
			vpid.pid_n_reg_314.PID = onoff ? pid : 0x1fff;
			vpid.pid_n_reg_314.PID_enable_bit = onoff;
			fc->write_ibi_reg(fc, pid_n_reg_314, vpid);
		}
		break;
	}
}

__attribute__((used)) static int flexcop_toggle_fullts_streaming(struct flexcop_device *fc, int onoff)
{
	if (fc->fullts_streaming_state != onoff) {
		deb_ts("%s full TS transfer\n",onoff ? "enabling" : "disabling");
		flexcop_pid_group_filter(fc, 0, 0x1fe0 * (!onoff));
		flexcop_pid_group_filter_ctrl(fc, onoff);
		fc->fullts_streaming_state = onoff;
	}
	return 0;
}

int flexcop_pid_feed_control(struct flexcop_device *fc,
		struct dvb_demux_feed *dvbdmxfeed, int onoff)
{
	int max_pid_filter = 6;

	max_pid_filter -= 6 * fc->skip_6_hw_pid_filter;
	max_pid_filter += 32 * fc->has_32_hw_pid_filter;

	fc->feedcount += onoff ? 1 : -1; /* the number of PIDs/Feed currently requested */
	if (dvbdmxfeed->index >= max_pid_filter)
		fc->extra_feedcount += onoff ? 1 : -1;

	/* toggle complete-TS-streaming when:
	 * - pid_filtering is not enabled and it is the first or last feed requested
	 * - pid_filtering is enabled,
	 *   - but the number of requested feeds is exceeded
	 *   - or the requested pid is 0x2000 */

	if (!fc->pid_filtering && fc->feedcount == onoff)
		flexcop_toggle_fullts_streaming(fc, onoff);

	if (fc->pid_filtering) {
		flexcop_pid_control \
			(fc, dvbdmxfeed->index, dvbdmxfeed->pid, onoff);

		if (fc->extra_feedcount > 0)
			flexcop_toggle_fullts_streaming(fc, 1);
		else if (dvbdmxfeed->pid == 0x2000)
			flexcop_toggle_fullts_streaming(fc, onoff);
		else
			flexcop_toggle_fullts_streaming(fc, 0);
	}

	/* if it was the first or last feed request change the stream-status */
	if (fc->feedcount == onoff) {
		flexcop_rcv_data_ctrl(fc, onoff);
		if (fc->stream_control) /* device specific stream control */
			fc->stream_control(fc, onoff);

		/* feeding stopped -> reset the flexcop filter*/
		if (onoff == 0) {
			flexcop_reset_block_300(fc);
			flexcop_hw_filter_init(fc);
		}
	}
	return 0;
}

void flexcop_hw_filter_init(struct flexcop_device *fc)
{
	int i;
	flexcop_ibi_value v;
	int max_pid_filter = 6;

	max_pid_filter -= 6 * fc->skip_6_hw_pid_filter;
	max_pid_filter += 32 * fc->has_32_hw_pid_filter;

	for (i = 0; i < max_pid_filter; i++)
		flexcop_pid_control(fc, i, 0x1fff, 0);

	flexcop_pid_group_filter(fc, 0, 0x1fe0);
	flexcop_pid_group_filter_ctrl(fc, 0);

	v = fc->read_ibi_reg(fc, pid_filter_308);
	v.pid_filter_308.EMM_filter_4 = 1;
	v.pid_filter_308.EMM_filter_6 = 0;
	fc->write_ibi_reg(fc, pid_filter_308, v);

	flexcop_null_filter_ctrl(fc, 1);
}

