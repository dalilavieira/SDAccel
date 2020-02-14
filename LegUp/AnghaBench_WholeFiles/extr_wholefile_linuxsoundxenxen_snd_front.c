#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  void* u8 ;
typedef  void* u32 ;
struct TYPE_11__ {int type; } ;
struct TYPE_10__ {unsigned long length; unsigned long offset; } ;
struct TYPE_9__ {unsigned int pcm_channels; unsigned int pcm_rate; int /*<<< orphan*/  gref_directory; void* period_sz; void* buffer_sz; void* pcm_format; } ;
struct xensnd_query_hw_param {int dummy; } ;
struct TYPE_12__ {TYPE_3__ trigger; TYPE_2__ rw; TYPE_1__ open; struct xensnd_query_hw_param hw_param; } ;
struct xensnd_req {TYPE_4__ op; scalar_t__ id; void* operation; } ;
struct xenbus_device_id {int dummy; } ;
struct xenbus_device {unsigned int state; int /*<<< orphan*/  otherend; int /*<<< orphan*/  dev; } ;
struct xen_snd_front_shbuf {int dummy; } ;
struct xen_snd_front_info {struct xenbus_device* xb_dev; } ;
struct TYPE_13__ {struct xensnd_query_hw_param hw_param; } ;
struct TYPE_16__ {int /*<<< orphan*/  req_prod_pvt; } ;
struct TYPE_15__ {int resp_status; int /*<<< orphan*/  req_io_lock; TYPE_5__ resp; int /*<<< orphan*/  completion; TYPE_8__ ring; } ;
struct TYPE_14__ {TYPE_7__ req; } ;
struct xen_snd_front_evtchnl {scalar_t__ state; TYPE_6__ u; int /*<<< orphan*/  ring_io_lock; scalar_t__ evt_id; int /*<<< orphan*/  evt_next_id; } ;
typedef  enum xenbus_state { ____Placeholder_xenbus_state } xenbus_state ;

/* Variables and functions */
 int EIO ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 scalar_t__ EVTCHNL_STATE_CONNECTED ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct xensnd_req* RING_GET_REQUEST (TYPE_8__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VSND_WAIT_BACK_MS ; 
 void* XENSND_OP_CLOSE ; 
 void* XENSND_OP_HW_PARAM_QUERY ; 
 void* XENSND_OP_OPEN ; 
 void* XENSND_OP_READ ; 
 void* XENSND_OP_TRIGGER ; 
 void* XENSND_OP_WRITE ; 
#define  XenbusStateClosed 136 
#define  XenbusStateClosing 135 
#define  XenbusStateConnected 134 
#define  XenbusStateInitWait 133 
#define  XenbusStateInitialised 132 
#define  XenbusStateInitialising 131 
#define  XenbusStateReconfigured 130 
#define  XenbusStateReconfiguring 129 
#define  XenbusStateUnknown 128 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct xen_snd_front_info* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct xen_snd_front_info*) ; 
 struct xen_snd_front_info* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 
 scalar_t__ wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xen_snd_front_alsa_fini (struct xen_snd_front_info*) ; 
 int xen_snd_front_alsa_init (struct xen_snd_front_info*) ; 
 int xen_snd_front_cfg_card (struct xen_snd_front_info*,int*) ; 
 int xen_snd_front_evtchnl_create_all (struct xen_snd_front_info*,int) ; 
 int /*<<< orphan*/  xen_snd_front_evtchnl_flush (struct xen_snd_front_evtchnl*) ; 
 int /*<<< orphan*/  xen_snd_front_evtchnl_free_all (struct xen_snd_front_info*) ; 
 int xen_snd_front_evtchnl_publish_all (struct xen_snd_front_info*) ; 
 int /*<<< orphan*/  xen_snd_front_shbuf_get_dir_start (struct xen_snd_front_shbuf*) ; 
 int /*<<< orphan*/  xenbus_dev_fatal (struct xenbus_device*,int,char*) ; 
 int /*<<< orphan*/  xenbus_frontend_closed (struct xenbus_device*) ; 
 int const xenbus_read_unsigned (int /*<<< orphan*/ ,char*,int const) ; 
 int /*<<< orphan*/  xenbus_strstate (unsigned int) ; 
 int xenbus_switch_state (struct xenbus_device*,int const) ; 

__attribute__((used)) static struct xensnd_req *
be_stream_prepare_req(struct xen_snd_front_evtchnl *evtchnl, u8 operation)
{
	struct xensnd_req *req;

	req = RING_GET_REQUEST(&evtchnl->u.req.ring,
			       evtchnl->u.req.ring.req_prod_pvt);
	req->operation = operation;
	req->id = evtchnl->evt_next_id++;
	evtchnl->evt_id = req->id;
	return req;
}

__attribute__((used)) static int be_stream_do_io(struct xen_snd_front_evtchnl *evtchnl)
{
	if (unlikely(evtchnl->state != EVTCHNL_STATE_CONNECTED))
		return -EIO;

	reinit_completion(&evtchnl->u.req.completion);
	xen_snd_front_evtchnl_flush(evtchnl);
	return 0;
}

__attribute__((used)) static int be_stream_wait_io(struct xen_snd_front_evtchnl *evtchnl)
{
	if (wait_for_completion_timeout(&evtchnl->u.req.completion,
			msecs_to_jiffies(VSND_WAIT_BACK_MS)) <= 0)
		return -ETIMEDOUT;

	return evtchnl->u.req.resp_status;
}

int xen_snd_front_stream_query_hw_param(struct xen_snd_front_evtchnl *evtchnl,
					struct xensnd_query_hw_param *hw_param_req,
					struct xensnd_query_hw_param *hw_param_resp)
{
	struct xensnd_req *req;
	int ret;

	mutex_lock(&evtchnl->u.req.req_io_lock);

	mutex_lock(&evtchnl->ring_io_lock);
	req = be_stream_prepare_req(evtchnl, XENSND_OP_HW_PARAM_QUERY);
	req->op.hw_param = *hw_param_req;
	mutex_unlock(&evtchnl->ring_io_lock);

	ret = be_stream_do_io(evtchnl);

	if (ret == 0)
		ret = be_stream_wait_io(evtchnl);

	if (ret == 0)
		*hw_param_resp = evtchnl->u.req.resp.hw_param;

	mutex_unlock(&evtchnl->u.req.req_io_lock);
	return ret;
}

int xen_snd_front_stream_prepare(struct xen_snd_front_evtchnl *evtchnl,
				 struct xen_snd_front_shbuf *sh_buf,
				 u8 format, unsigned int channels,
				 unsigned int rate, u32 buffer_sz,
				 u32 period_sz)
{
	struct xensnd_req *req;
	int ret;

	mutex_lock(&evtchnl->u.req.req_io_lock);

	mutex_lock(&evtchnl->ring_io_lock);
	req = be_stream_prepare_req(evtchnl, XENSND_OP_OPEN);
	req->op.open.pcm_format = format;
	req->op.open.pcm_channels = channels;
	req->op.open.pcm_rate = rate;
	req->op.open.buffer_sz = buffer_sz;
	req->op.open.period_sz = period_sz;
	req->op.open.gref_directory = xen_snd_front_shbuf_get_dir_start(sh_buf);
	mutex_unlock(&evtchnl->ring_io_lock);

	ret = be_stream_do_io(evtchnl);

	if (ret == 0)
		ret = be_stream_wait_io(evtchnl);

	mutex_unlock(&evtchnl->u.req.req_io_lock);
	return ret;
}

int xen_snd_front_stream_close(struct xen_snd_front_evtchnl *evtchnl)
{
	struct xensnd_req *req;
	int ret;

	mutex_lock(&evtchnl->u.req.req_io_lock);

	mutex_lock(&evtchnl->ring_io_lock);
	req = be_stream_prepare_req(evtchnl, XENSND_OP_CLOSE);
	mutex_unlock(&evtchnl->ring_io_lock);

	ret = be_stream_do_io(evtchnl);

	if (ret == 0)
		ret = be_stream_wait_io(evtchnl);

	mutex_unlock(&evtchnl->u.req.req_io_lock);
	return ret;
}

int xen_snd_front_stream_write(struct xen_snd_front_evtchnl *evtchnl,
			       unsigned long pos, unsigned long count)
{
	struct xensnd_req *req;
	int ret;

	mutex_lock(&evtchnl->u.req.req_io_lock);

	mutex_lock(&evtchnl->ring_io_lock);
	req = be_stream_prepare_req(evtchnl, XENSND_OP_WRITE);
	req->op.rw.length = count;
	req->op.rw.offset = pos;
	mutex_unlock(&evtchnl->ring_io_lock);

	ret = be_stream_do_io(evtchnl);

	if (ret == 0)
		ret = be_stream_wait_io(evtchnl);

	mutex_unlock(&evtchnl->u.req.req_io_lock);
	return ret;
}

int xen_snd_front_stream_read(struct xen_snd_front_evtchnl *evtchnl,
			      unsigned long pos, unsigned long count)
{
	struct xensnd_req *req;
	int ret;

	mutex_lock(&evtchnl->u.req.req_io_lock);

	mutex_lock(&evtchnl->ring_io_lock);
	req = be_stream_prepare_req(evtchnl, XENSND_OP_READ);
	req->op.rw.length = count;
	req->op.rw.offset = pos;
	mutex_unlock(&evtchnl->ring_io_lock);

	ret = be_stream_do_io(evtchnl);

	if (ret == 0)
		ret = be_stream_wait_io(evtchnl);

	mutex_unlock(&evtchnl->u.req.req_io_lock);
	return ret;
}

int xen_snd_front_stream_trigger(struct xen_snd_front_evtchnl *evtchnl,
				 int type)
{
	struct xensnd_req *req;
	int ret;

	mutex_lock(&evtchnl->u.req.req_io_lock);

	mutex_lock(&evtchnl->ring_io_lock);
	req = be_stream_prepare_req(evtchnl, XENSND_OP_TRIGGER);
	req->op.trigger.type = type;
	mutex_unlock(&evtchnl->ring_io_lock);

	ret = be_stream_do_io(evtchnl);

	if (ret == 0)
		ret = be_stream_wait_io(evtchnl);

	mutex_unlock(&evtchnl->u.req.req_io_lock);
	return ret;
}

__attribute__((used)) static void xen_snd_drv_fini(struct xen_snd_front_info *front_info)
{
	xen_snd_front_alsa_fini(front_info);
	xen_snd_front_evtchnl_free_all(front_info);
}

__attribute__((used)) static int sndback_initwait(struct xen_snd_front_info *front_info)
{
	int num_streams;
	int ret;

	ret = xen_snd_front_cfg_card(front_info, &num_streams);
	if (ret < 0)
		return ret;

	/* create event channels for all streams and publish */
	ret = xen_snd_front_evtchnl_create_all(front_info, num_streams);
	if (ret < 0)
		return ret;

	return xen_snd_front_evtchnl_publish_all(front_info);
}

__attribute__((used)) static int sndback_connect(struct xen_snd_front_info *front_info)
{
	return xen_snd_front_alsa_init(front_info);
}

__attribute__((used)) static void sndback_disconnect(struct xen_snd_front_info *front_info)
{
	xen_snd_drv_fini(front_info);
	xenbus_switch_state(front_info->xb_dev, XenbusStateInitialising);
}

__attribute__((used)) static void sndback_changed(struct xenbus_device *xb_dev,
			    enum xenbus_state backend_state)
{
	struct xen_snd_front_info *front_info = dev_get_drvdata(&xb_dev->dev);
	int ret;

	dev_dbg(&xb_dev->dev, "Backend state is %s, front is %s\n",
		xenbus_strstate(backend_state),
		xenbus_strstate(xb_dev->state));

	switch (backend_state) {
	case XenbusStateReconfiguring:
		/* fall through */
	case XenbusStateReconfigured:
		/* fall through */
	case XenbusStateInitialised:
		/* fall through */
		break;

	case XenbusStateInitialising:
		/* Recovering after backend unexpected closure. */
		sndback_disconnect(front_info);
		break;

	case XenbusStateInitWait:
		/* Recovering after backend unexpected closure. */
		sndback_disconnect(front_info);

		ret = sndback_initwait(front_info);
		if (ret < 0)
			xenbus_dev_fatal(xb_dev, ret, "initializing frontend");
		else
			xenbus_switch_state(xb_dev, XenbusStateInitialised);
		break;

	case XenbusStateConnected:
		if (xb_dev->state != XenbusStateInitialised)
			break;

		ret = sndback_connect(front_info);
		if (ret < 0)
			xenbus_dev_fatal(xb_dev, ret, "initializing frontend");
		else
			xenbus_switch_state(xb_dev, XenbusStateConnected);
		break;

	case XenbusStateClosing:
		/*
		 * In this state backend starts freeing resources,
		 * so let it go into closed state first, so we can also
		 * remove ours.
		 */
		break;

	case XenbusStateUnknown:
		/* fall through */
	case XenbusStateClosed:
		if (xb_dev->state == XenbusStateClosed)
			break;

		sndback_disconnect(front_info);
		break;
	}
}

__attribute__((used)) static int xen_drv_probe(struct xenbus_device *xb_dev,
			 const struct xenbus_device_id *id)
{
	struct xen_snd_front_info *front_info;

	front_info = devm_kzalloc(&xb_dev->dev,
				  sizeof(*front_info), GFP_KERNEL);
	if (!front_info)
		return -ENOMEM;

	front_info->xb_dev = xb_dev;
	dev_set_drvdata(&xb_dev->dev, front_info);

	return xenbus_switch_state(xb_dev, XenbusStateInitialising);
}

__attribute__((used)) static int xen_drv_remove(struct xenbus_device *dev)
{
	struct xen_snd_front_info *front_info = dev_get_drvdata(&dev->dev);
	int to = 100;

	xenbus_switch_state(dev, XenbusStateClosing);

	/*
	 * On driver removal it is disconnected from XenBus,
	 * so no backend state change events come via .otherend_changed
	 * callback. This prevents us from exiting gracefully, e.g.
	 * signaling the backend to free event channels, waiting for its
	 * state to change to XenbusStateClosed and cleaning at our end.
	 * Normally when front driver removed backend will finally go into
	 * XenbusStateInitWait state.
	 *
	 * Workaround: read backend's state manually and wait with time-out.
	 */
	while ((xenbus_read_unsigned(front_info->xb_dev->otherend, "state",
				     XenbusStateUnknown) != XenbusStateInitWait) &&
	       --to)
		msleep(10);

	if (!to) {
		unsigned int state;

		state = xenbus_read_unsigned(front_info->xb_dev->otherend,
					     "state", XenbusStateUnknown);
		pr_err("Backend state is %s while removing driver\n",
		       xenbus_strstate(state));
	}

	xen_snd_drv_fini(front_info);
	xenbus_frontend_closed(dev);
	return 0;
}

