#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_7__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct v4l2_subdev_pad_config {int dummy; } ;
struct v4l2_mbus_framefmt {int dummy; } ;
struct v4l2_subdev_format {unsigned int pad; scalar_t__ which; struct v4l2_mbus_framefmt format; } ;
struct v4l2_subdev {struct v4l2_device* v4l2_dev; int /*<<< orphan*/  name; int /*<<< orphan*/  entity; } ;
struct v4l2_device {int dummy; } ;
struct v4l2_ctrl {int id; } ;
struct media_pad {int /*<<< orphan*/  flags; int /*<<< orphan*/  entity; } ;
struct device_node {int dummy; } ;
struct TYPE_11__ {struct v4l2_subdev sd; } ;
struct TYPE_10__ {struct v4l2_subdev sd; } ;
struct TYPE_12__ {int error; } ;
struct TYPE_13__ {int /*<<< orphan*/  entity; int /*<<< orphan*/ * internal_ops; int /*<<< orphan*/  fwnode; TYPE_3__* ctrl_handler; } ;
struct adv748x_csi2 {TYPE_3__ ctrl_hdl; TYPE_7__ sd; struct media_pad* pads; int /*<<< orphan*/  page; struct adv748x_state* state; int /*<<< orphan*/  pixel_rate; struct v4l2_mbus_framefmt format; } ;
struct adv748x_state {struct device_node** endpoints; int /*<<< orphan*/  mutex; TYPE_2__ afe; TYPE_1__ hdmi; struct adv748x_csi2 txa; } ;
typedef  int /*<<< orphan*/  s64 ;

/* Variables and functions */
 unsigned int ADV748X_AFE_SOURCE ; 
 int /*<<< orphan*/  ADV748X_CSI2_NR_PADS ; 
 size_t ADV748X_CSI2_SINK ; 
 size_t ADV748X_CSI2_SOURCE ; 
 int /*<<< orphan*/  ADV748X_CSI_VC_REF ; 
 unsigned int ADV748X_CSI_VC_REF_SHIFT ; 
 unsigned int ADV748X_HDMI_SOURCE ; 
 int /*<<< orphan*/  ADV748X_PAGE_TXA ; 
 int /*<<< orphan*/  ADV748X_PAGE_TXB ; 
 size_t ADV748X_PORT_TXA ; 
 size_t ADV748X_PORT_TXB ; 
 int EINVAL ; 
 int ENODEV ; 
 int EPIPE ; 
 int /*<<< orphan*/  INT_MAX ; 
 int /*<<< orphan*/  MEDIA_ENT_F_VID_IF_BRIDGE ; 
 int MEDIA_LNK_FL_ENABLED ; 
 int MEDIA_LNK_FL_IMMUTABLE ; 
 int /*<<< orphan*/  MEDIA_PAD_FL_SINK ; 
 int /*<<< orphan*/  MEDIA_PAD_FL_SOURCE ; 
#define  V4L2_CID_PIXEL_RATE 128 
 scalar_t__ V4L2_SUBDEV_FORMAT_TRY ; 
 int /*<<< orphan*/  adv748x_csi2_ctrl_ops ; 
 int /*<<< orphan*/  adv748x_csi2_internal_ops ; 
 int /*<<< orphan*/  adv748x_csi2_ops ; 
 struct adv748x_csi2* adv748x_sd_to_csi2 (struct v4l2_subdev*) ; 
 int /*<<< orphan*/  adv748x_subdev_init (TYPE_7__*,struct adv748x_state*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  adv_dbg (struct adv748x_state*,char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  adv_err (struct adv748x_state*,char*,char*) ; 
 int media_create_pad_link (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ *,size_t,int) ; 
 int /*<<< orphan*/  media_entity_cleanup (int /*<<< orphan*/ *) ; 
 int media_entity_pads_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct media_pad*) ; 
 struct media_pad* media_entity_remote_pad (struct media_pad*) ; 
 struct v4l2_subdev* media_entity_to_v4l2_subdev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_fwnode_handle (struct device_node*) ; 
 int /*<<< orphan*/  s_stream ; 
 int tx_write (struct adv748x_csi2*,int /*<<< orphan*/ ,unsigned int) ; 
 int v4l2_async_register_subdev (TYPE_7__*) ; 
 int /*<<< orphan*/  v4l2_async_unregister_subdev (TYPE_7__*) ; 
 int /*<<< orphan*/  v4l2_ctrl_handler_free (TYPE_3__*) ; 
 int /*<<< orphan*/  v4l2_ctrl_handler_init (TYPE_3__*,int) ; 
 int v4l2_ctrl_handler_setup (TYPE_3__*) ; 
 int /*<<< orphan*/  v4l2_ctrl_new_std (TYPE_3__*,int /*<<< orphan*/ *,int const,int,int /*<<< orphan*/ ,int,int) ; 
 int v4l2_ctrl_s_ctrl_int64 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int v4l2_device_register_subdev (struct v4l2_device*,struct v4l2_subdev*) ; 
 int v4l2_subdev_call (struct v4l2_subdev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct v4l2_mbus_framefmt* v4l2_subdev_get_try_format (struct v4l2_subdev*,struct v4l2_subdev_pad_config*,unsigned int) ; 
 int /*<<< orphan*/  video ; 

__attribute__((used)) static inline struct v4l2_subdev *adv748x_get_remote_sd(struct media_pad *pad)
{
	pad = media_entity_remote_pad(pad);
	if (!pad)
		return NULL;

	return media_entity_to_v4l2_subdev(pad->entity);
}

__attribute__((used)) static bool is_txa(struct adv748x_csi2 *tx)
{
	return tx == &tx->state->txa;
}

__attribute__((used)) static int adv748x_csi2_set_virtual_channel(struct adv748x_csi2 *tx,
					    unsigned int vc)
{
	return tx_write(tx, ADV748X_CSI_VC_REF, vc << ADV748X_CSI_VC_REF_SHIFT);
}

__attribute__((used)) static int adv748x_csi2_register_link(struct adv748x_csi2 *tx,
				      struct v4l2_device *v4l2_dev,
				      struct v4l2_subdev *src,
				      unsigned int src_pad)
{
	int enabled = MEDIA_LNK_FL_ENABLED;
	int ret;

	/*
	 * Dynamic linking of the AFE is not supported.
	 * Register the links as immutable.
	 */
	enabled |= MEDIA_LNK_FL_IMMUTABLE;

	if (!src->v4l2_dev) {
		ret = v4l2_device_register_subdev(v4l2_dev, src);
		if (ret)
			return ret;
	}

	return media_create_pad_link(&src->entity, src_pad,
				     &tx->sd.entity, ADV748X_CSI2_SINK,
				     enabled);
}

__attribute__((used)) static int adv748x_csi2_registered(struct v4l2_subdev *sd)
{
	struct adv748x_csi2 *tx = adv748x_sd_to_csi2(sd);
	struct adv748x_state *state = tx->state;

	adv_dbg(state, "Registered %s (%s)", is_txa(tx) ? "TXA":"TXB",
			sd->name);

	/*
	 * The adv748x hardware allows the AFE to route through the TXA, however
	 * this is not currently supported in this driver.
	 *
	 * Link HDMI->TXA, and AFE->TXB directly.
	 */
	if (is_txa(tx)) {
		return adv748x_csi2_register_link(tx, sd->v4l2_dev,
						  &state->hdmi.sd,
						  ADV748X_HDMI_SOURCE);
	} else {
		return adv748x_csi2_register_link(tx, sd->v4l2_dev,
						  &state->afe.sd,
						  ADV748X_AFE_SOURCE);
	}
}

__attribute__((used)) static int adv748x_csi2_s_stream(struct v4l2_subdev *sd, int enable)
{
	struct adv748x_csi2 *tx = adv748x_sd_to_csi2(sd);
	struct v4l2_subdev *src;

	src = adv748x_get_remote_sd(&tx->pads[ADV748X_CSI2_SINK]);
	if (!src)
		return -EPIPE;

	return v4l2_subdev_call(src, video, s_stream, enable);
}

__attribute__((used)) static struct v4l2_mbus_framefmt *
adv748x_csi2_get_pad_format(struct v4l2_subdev *sd,
			    struct v4l2_subdev_pad_config *cfg,
			    unsigned int pad, u32 which)
{
	struct adv748x_csi2 *tx = adv748x_sd_to_csi2(sd);

	if (which == V4L2_SUBDEV_FORMAT_TRY)
		return v4l2_subdev_get_try_format(sd, cfg, pad);

	return &tx->format;
}

__attribute__((used)) static int adv748x_csi2_get_format(struct v4l2_subdev *sd,
				   struct v4l2_subdev_pad_config *cfg,
				   struct v4l2_subdev_format *sdformat)
{
	struct adv748x_csi2 *tx = adv748x_sd_to_csi2(sd);
	struct adv748x_state *state = tx->state;
	struct v4l2_mbus_framefmt *mbusformat;

	mbusformat = adv748x_csi2_get_pad_format(sd, cfg, sdformat->pad,
						 sdformat->which);
	if (!mbusformat)
		return -EINVAL;

	mutex_lock(&state->mutex);

	sdformat->format = *mbusformat;

	mutex_unlock(&state->mutex);

	return 0;
}

__attribute__((used)) static int adv748x_csi2_set_format(struct v4l2_subdev *sd,
				   struct v4l2_subdev_pad_config *cfg,
				   struct v4l2_subdev_format *sdformat)
{
	struct adv748x_csi2 *tx = adv748x_sd_to_csi2(sd);
	struct adv748x_state *state = tx->state;
	struct v4l2_mbus_framefmt *mbusformat;
	int ret = 0;

	mbusformat = adv748x_csi2_get_pad_format(sd, cfg, sdformat->pad,
						 sdformat->which);
	if (!mbusformat)
		return -EINVAL;

	mutex_lock(&state->mutex);

	if (sdformat->pad == ADV748X_CSI2_SOURCE) {
		const struct v4l2_mbus_framefmt *sink_fmt;

		sink_fmt = adv748x_csi2_get_pad_format(sd, cfg,
						       ADV748X_CSI2_SINK,
						       sdformat->which);

		if (!sink_fmt) {
			ret = -EINVAL;
			goto unlock;
		}

		sdformat->format = *sink_fmt;
	}

	*mbusformat = sdformat->format;

unlock:
	mutex_unlock(&state->mutex);

	return ret;
}

int adv748x_csi2_set_pixelrate(struct v4l2_subdev *sd, s64 rate)
{
	struct adv748x_csi2 *tx = adv748x_sd_to_csi2(sd);

	if (!tx->pixel_rate)
		return -EINVAL;

	return v4l2_ctrl_s_ctrl_int64(tx->pixel_rate, rate);
}

__attribute__((used)) static int adv748x_csi2_s_ctrl(struct v4l2_ctrl *ctrl)
{
	switch (ctrl->id) {
	case V4L2_CID_PIXEL_RATE:
		return 0;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int adv748x_csi2_init_controls(struct adv748x_csi2 *tx)
{

	v4l2_ctrl_handler_init(&tx->ctrl_hdl, 1);

	tx->pixel_rate = v4l2_ctrl_new_std(&tx->ctrl_hdl,
					   &adv748x_csi2_ctrl_ops,
					   V4L2_CID_PIXEL_RATE, 1, INT_MAX,
					   1, 1);

	tx->sd.ctrl_handler = &tx->ctrl_hdl;
	if (tx->ctrl_hdl.error) {
		v4l2_ctrl_handler_free(&tx->ctrl_hdl);
		return tx->ctrl_hdl.error;
	}

	return v4l2_ctrl_handler_setup(&tx->ctrl_hdl);
}

int adv748x_csi2_init(struct adv748x_state *state, struct adv748x_csi2 *tx)
{
	struct device_node *ep;
	int ret;

	/* We can not use container_of to get back to the state with two TXs */
	tx->state = state;
	tx->page = is_txa(tx) ? ADV748X_PAGE_TXA : ADV748X_PAGE_TXB;

	ep = state->endpoints[is_txa(tx) ? ADV748X_PORT_TXA : ADV748X_PORT_TXB];
	if (!ep) {
		adv_err(state, "No endpoint found for %s\n",
				is_txa(tx) ? "txa" : "txb");
		return -ENODEV;
	}

	/* Initialise the virtual channel */
	adv748x_csi2_set_virtual_channel(tx, 0);

	adv748x_subdev_init(&tx->sd, state, &adv748x_csi2_ops,
			    MEDIA_ENT_F_VID_IF_BRIDGE,
			    is_txa(tx) ? "txa" : "txb");

	/* Ensure that matching is based upon the endpoint fwnodes */
	tx->sd.fwnode = of_fwnode_handle(ep);

	/* Register internal ops for incremental subdev registration */
	tx->sd.internal_ops = &adv748x_csi2_internal_ops;

	tx->pads[ADV748X_CSI2_SINK].flags = MEDIA_PAD_FL_SINK;
	tx->pads[ADV748X_CSI2_SOURCE].flags = MEDIA_PAD_FL_SOURCE;

	ret = media_entity_pads_init(&tx->sd.entity, ADV748X_CSI2_NR_PADS,
				     tx->pads);
	if (ret)
		return ret;

	ret = adv748x_csi2_init_controls(tx);
	if (ret)
		goto err_free_media;

	ret = v4l2_async_register_subdev(&tx->sd);
	if (ret)
		goto err_free_ctrl;

	return 0;

err_free_ctrl:
	v4l2_ctrl_handler_free(&tx->ctrl_hdl);
err_free_media:
	media_entity_cleanup(&tx->sd.entity);

	return ret;
}

void adv748x_csi2_cleanup(struct adv748x_csi2 *tx)
{
	v4l2_async_unregister_subdev(&tx->sd);
	media_entity_cleanup(&tx->sd.entity);
	v4l2_ctrl_handler_free(&tx->ctrl_hdl);
}

