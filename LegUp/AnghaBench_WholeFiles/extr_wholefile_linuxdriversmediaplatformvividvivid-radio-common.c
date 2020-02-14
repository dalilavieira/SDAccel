#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_47__   TYPE_9__ ;
typedef  struct TYPE_46__   TYPE_8__ ;
typedef  struct TYPE_45__   TYPE_7__ ;
typedef  struct TYPE_44__   TYPE_6__ ;
typedef  struct TYPE_43__   TYPE_5__ ;
typedef  struct TYPE_42__   TYPE_4__ ;
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_23__ ;
typedef  struct TYPE_38__   TYPE_22__ ;
typedef  struct TYPE_37__   TYPE_21__ ;
typedef  struct TYPE_36__   TYPE_20__ ;
typedef  struct TYPE_35__   TYPE_1__ ;
typedef  struct TYPE_34__   TYPE_19__ ;
typedef  struct TYPE_33__   TYPE_18__ ;
typedef  struct TYPE_32__   TYPE_17__ ;
typedef  struct TYPE_31__   TYPE_16__ ;
typedef  struct TYPE_30__   TYPE_15__ ;
typedef  struct TYPE_29__   TYPE_14__ ;
typedef  struct TYPE_28__   TYPE_13__ ;
typedef  struct TYPE_27__   TYPE_12__ ;
typedef  struct TYPE_26__   TYPE_11__ ;
typedef  struct TYPE_25__   TYPE_10__ ;

/* Type definitions */
struct vivid_rds_gen {int /*<<< orphan*/  data; int /*<<< orphan*/  radiotext; int /*<<< orphan*/  psname; int /*<<< orphan*/  ms; int /*<<< orphan*/  tp; int /*<<< orphan*/  ta; int /*<<< orphan*/  pty; int /*<<< orphan*/  dyn_pty; int /*<<< orphan*/  compressed; int /*<<< orphan*/  art_head; int /*<<< orphan*/  mono_stereo; int /*<<< orphan*/  picode; } ;
struct vivid_dev {scalar_t__* input_type; size_t input; scalar_t__* output_type; size_t output; int radio_rx_rds_use_alternates; int radio_rds_loop; int radio_rx_freq; int radio_tx_freq; int radio_rx_sig_qual; struct vivid_rds_gen rds_gen; int /*<<< orphan*/  radio_tx_rds_controls; scalar_t__ has_radio_tx; int /*<<< orphan*/  radio_rx_rds_radiotext; int /*<<< orphan*/  radio_rx_rds_psname; int /*<<< orphan*/  radio_rx_rds_ms; int /*<<< orphan*/  radio_rx_rds_tp; int /*<<< orphan*/  radio_rx_rds_ta; int /*<<< orphan*/  radio_rx_rds_pty; scalar_t__ radio_rx_rds_controls; TYPE_23__* radio_tx_rds_pi; TYPE_21__* radio_tx_rds_radiotext; TYPE_19__* radio_tx_rds_psname; TYPE_17__* radio_tx_rds_ms; TYPE_15__* radio_tx_rds_tp; TYPE_13__* radio_tx_rds_ta; TYPE_11__* radio_tx_rds_dyn_pty; TYPE_9__* radio_tx_rds_compressed; TYPE_7__* radio_tx_rds_art_head; TYPE_5__* radio_tx_rds_mono_stereo; TYPE_3__* radio_tx_rds_pty; } ;
struct v4l2_frequency {scalar_t__ tuner; unsigned int frequency; } ;
struct file {int dummy; } ;
struct TYPE_46__ {int /*<<< orphan*/  val; } ;
struct TYPE_47__ {TYPE_8__ cur; } ;
struct TYPE_44__ {int /*<<< orphan*/  val; } ;
struct TYPE_45__ {TYPE_6__ cur; } ;
struct TYPE_42__ {int /*<<< orphan*/  val; } ;
struct TYPE_43__ {TYPE_4__ cur; } ;
struct TYPE_40__ {int /*<<< orphan*/  val; } ;
struct TYPE_41__ {TYPE_2__ cur; } ;
struct TYPE_35__ {int /*<<< orphan*/  val; } ;
struct TYPE_39__ {TYPE_1__ cur; } ;
struct TYPE_38__ {int /*<<< orphan*/  rangehigh; int /*<<< orphan*/  rangelow; } ;
struct TYPE_36__ {scalar_t__ p_char; } ;
struct TYPE_37__ {TYPE_20__ p_cur; } ;
struct TYPE_33__ {scalar_t__ p_char; } ;
struct TYPE_34__ {TYPE_18__ p_cur; } ;
struct TYPE_31__ {int /*<<< orphan*/  val; } ;
struct TYPE_32__ {TYPE_16__ cur; } ;
struct TYPE_29__ {int /*<<< orphan*/  val; } ;
struct TYPE_30__ {TYPE_14__ cur; } ;
struct TYPE_27__ {int /*<<< orphan*/  val; } ;
struct TYPE_28__ {TYPE_12__ cur; } ;
struct TYPE_25__ {int /*<<< orphan*/  val; } ;
struct TYPE_26__ {TYPE_10__ cur; } ;

/* Variables and functions */
 int AM_FREQ_RANGE_HIGH ; 
 unsigned int BAND_AM ; 
 unsigned int BAND_FM ; 
 unsigned int BAND_SW ; 
 int EINVAL ; 
 int FM_FREQ_RANGE_LOW ; 
 scalar_t__ HDMI ; 
 scalar_t__ SVID ; 
 int SW_FREQ_RANGE_HIGH ; 
 int SW_FREQ_RANGE_LOW ; 
 scalar_t__ TV ; 
 scalar_t__ WEBCAM ; 
 scalar_t__ abs (int) ; 
 unsigned int clamp_t (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,scalar_t__,int) ; 
 int /*<<< orphan*/  u32 ; 
 int /*<<< orphan*/  v4l2_ctrl_lock (TYPE_23__*) ; 
 int /*<<< orphan*/  v4l2_ctrl_s_ctrl (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  v4l2_ctrl_s_ctrl_string (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  v4l2_ctrl_unlock (TYPE_23__*) ; 
 struct vivid_dev* video_drvdata (struct file*) ; 
 TYPE_22__* vivid_radio_bands ; 
 int /*<<< orphan*/  vivid_rds_gen_fill (struct vivid_rds_gen*,int,int) ; 
 int /*<<< orphan*/  vivid_rds_generate (struct vivid_rds_gen*) ; 

__attribute__((used)) static inline bool vivid_is_webcam(const struct vivid_dev *dev)
{
	return dev->input_type[dev->input] == WEBCAM;
}

__attribute__((used)) static inline bool vivid_is_tv_cap(const struct vivid_dev *dev)
{
	return dev->input_type[dev->input] == TV;
}

__attribute__((used)) static inline bool vivid_is_svid_cap(const struct vivid_dev *dev)
{
	return dev->input_type[dev->input] == SVID;
}

__attribute__((used)) static inline bool vivid_is_hdmi_cap(const struct vivid_dev *dev)
{
	return dev->input_type[dev->input] == HDMI;
}

__attribute__((used)) static inline bool vivid_is_sdtv_cap(const struct vivid_dev *dev)
{
	return vivid_is_tv_cap(dev) || vivid_is_svid_cap(dev);
}

__attribute__((used)) static inline bool vivid_is_svid_out(const struct vivid_dev *dev)
{
	return dev->output_type[dev->output] == SVID;
}

__attribute__((used)) static inline bool vivid_is_hdmi_out(const struct vivid_dev *dev)
{
	return dev->output_type[dev->output] == HDMI;
}

void vivid_radio_rds_init(struct vivid_dev *dev)
{
	struct vivid_rds_gen *rds = &dev->rds_gen;
	bool alt = dev->radio_rx_rds_use_alternates;

	/* Do nothing, blocks will be filled by the transmitter */
	if (dev->radio_rds_loop && !dev->radio_tx_rds_controls)
		return;

	if (dev->radio_rds_loop) {
		v4l2_ctrl_lock(dev->radio_tx_rds_pi);
		rds->picode = dev->radio_tx_rds_pi->cur.val;
		rds->pty = dev->radio_tx_rds_pty->cur.val;
		rds->mono_stereo = dev->radio_tx_rds_mono_stereo->cur.val;
		rds->art_head = dev->radio_tx_rds_art_head->cur.val;
		rds->compressed = dev->radio_tx_rds_compressed->cur.val;
		rds->dyn_pty = dev->radio_tx_rds_dyn_pty->cur.val;
		rds->ta = dev->radio_tx_rds_ta->cur.val;
		rds->tp = dev->radio_tx_rds_tp->cur.val;
		rds->ms = dev->radio_tx_rds_ms->cur.val;
		strlcpy(rds->psname,
			dev->radio_tx_rds_psname->p_cur.p_char,
			sizeof(rds->psname));
		strlcpy(rds->radiotext,
			dev->radio_tx_rds_radiotext->p_cur.p_char + alt * 64,
			sizeof(rds->radiotext));
		v4l2_ctrl_unlock(dev->radio_tx_rds_pi);
	} else {
		vivid_rds_gen_fill(rds, dev->radio_rx_freq, alt);
	}
	if (dev->radio_rx_rds_controls) {
		v4l2_ctrl_s_ctrl(dev->radio_rx_rds_pty, rds->pty);
		v4l2_ctrl_s_ctrl(dev->radio_rx_rds_ta, rds->ta);
		v4l2_ctrl_s_ctrl(dev->radio_rx_rds_tp, rds->tp);
		v4l2_ctrl_s_ctrl(dev->radio_rx_rds_ms, rds->ms);
		v4l2_ctrl_s_ctrl_string(dev->radio_rx_rds_psname, rds->psname);
		v4l2_ctrl_s_ctrl_string(dev->radio_rx_rds_radiotext, rds->radiotext);
		if (!dev->radio_rds_loop)
			dev->radio_rx_rds_use_alternates = !dev->radio_rx_rds_use_alternates;
	}
	vivid_rds_generate(rds);
}

__attribute__((used)) static void vivid_radio_calc_sig_qual(struct vivid_dev *dev)
{
	int mod = 16000;
	int delta = 800;
	int sig_qual, sig_qual_tx = mod;

	/*
	 * For SW and FM there is a channel every 1000 kHz, for AM there is one
	 * every 100 kHz.
	 */
	if (dev->radio_rx_freq <= AM_FREQ_RANGE_HIGH) {
		mod /= 10;
		delta /= 10;
	}
	sig_qual = (dev->radio_rx_freq + delta) % mod - delta;
	if (dev->has_radio_tx)
		sig_qual_tx = dev->radio_rx_freq - dev->radio_tx_freq;
	if (abs(sig_qual_tx) <= abs(sig_qual)) {
		sig_qual = sig_qual_tx;
		/*
		 * Zero the internal rds buffer if we are going to loop
		 * rds blocks.
		 */
		if (!dev->radio_rds_loop && !dev->radio_tx_rds_controls)
			memset(dev->rds_gen.data, 0,
			       sizeof(dev->rds_gen.data));
		dev->radio_rds_loop = dev->radio_rx_freq >= FM_FREQ_RANGE_LOW;
	} else {
		dev->radio_rds_loop = false;
	}
	if (dev->radio_rx_freq <= AM_FREQ_RANGE_HIGH)
		sig_qual *= 10;
	dev->radio_rx_sig_qual = sig_qual;
}

int vivid_radio_g_frequency(struct file *file, const unsigned *pfreq, struct v4l2_frequency *vf)
{
	if (vf->tuner != 0)
		return -EINVAL;
	vf->frequency = *pfreq;
	return 0;
}

int vivid_radio_s_frequency(struct file *file, unsigned *pfreq, const struct v4l2_frequency *vf)
{
	struct vivid_dev *dev = video_drvdata(file);
	unsigned freq;
	unsigned band;

	if (vf->tuner != 0)
		return -EINVAL;

	if (vf->frequency >= (FM_FREQ_RANGE_LOW + SW_FREQ_RANGE_HIGH) / 2)
		band = BAND_FM;
	else if (vf->frequency <= (AM_FREQ_RANGE_HIGH + SW_FREQ_RANGE_LOW) / 2)
		band = BAND_AM;
	else
		band = BAND_SW;

	freq = clamp_t(u32, vf->frequency, vivid_radio_bands[band].rangelow,
					   vivid_radio_bands[band].rangehigh);
	*pfreq = freq;

	/*
	 * For both receiver and transmitter recalculate the signal quality
	 * (since that depends on both frequencies) and re-init the rds
	 * generator.
	 */
	vivid_radio_calc_sig_qual(dev);
	vivid_radio_rds_init(dev);
	return 0;
}

