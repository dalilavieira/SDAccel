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
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int v4l2_std_id ;
typedef  scalar_t__ u32 ;
struct vivid_fmt {scalar_t__ fourcc; int buffers; } ;
struct v4l2_dv_timings {int dummy; } ;
struct TYPE_9__ {scalar_t__ width; scalar_t__ height; } ;
struct TYPE_8__ {scalar_t__ width; scalar_t__ height; } ;
struct vivid_dev {scalar_t__* input_type; size_t input; scalar_t__* output_type; size_t output; scalar_t__ field_cap; scalar_t__ field_out; int std_cap; int std_out; unsigned int num_inputs; size_t num_outputs; unsigned int* cec_output2bus_map; int edid_blocks; scalar_t__ edid; struct cec_adapter** cec_tx_adap; struct cec_adapter* cec_rx_adap; struct v4l2_dv_timings dv_timings_out; struct v4l2_dv_timings dv_timings_cap; scalar_t__ multiplanar; int /*<<< orphan*/  vbi_cap_dev; scalar_t__ has_vbi_cap; int /*<<< orphan*/  vid_cap_dev; scalar_t__ has_vid_cap; TYPE_4__* fmt_out; TYPE_3__* fmt_cap; TYPE_2__ sink_rect; TYPE_1__ src_rect; } ;
struct video_device {scalar_t__ vfl_dir; } ;
struct v4l2_rect {unsigned int width; unsigned int height; int top; int left; } ;
struct v4l2_plane_pix_format {int /*<<< orphan*/  bytesperline; int /*<<< orphan*/  sizeimage; int /*<<< orphan*/  reserved; } ;
struct v4l2_pix_format_mplane {int num_planes; int /*<<< orphan*/  flags; int /*<<< orphan*/  quantization; int /*<<< orphan*/  ycbcr_enc; int /*<<< orphan*/  xfer_func; int /*<<< orphan*/  colorspace; int /*<<< orphan*/  field; int /*<<< orphan*/  pixelformat; int /*<<< orphan*/  height; int /*<<< orphan*/  width; struct v4l2_plane_pix_format* plane_fmt; int /*<<< orphan*/  reserved; } ;
struct v4l2_pix_format {int /*<<< orphan*/  flags; int /*<<< orphan*/  bytesperline; int /*<<< orphan*/  sizeimage; int /*<<< orphan*/  quantization; int /*<<< orphan*/  ycbcr_enc; int /*<<< orphan*/  xfer_func; int /*<<< orphan*/  colorspace; int /*<<< orphan*/  field; int /*<<< orphan*/  pixelformat; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct TYPE_14__ {struct v4l2_pix_format pix; struct v4l2_pix_format_mplane pix_mp; } ;
struct v4l2_format {scalar_t__ type; TYPE_7__ fmt; } ;
struct v4l2_fmtdesc {unsigned int index; scalar_t__ pixelformat; } ;
struct TYPE_12__ {int /*<<< orphan*/  changes; } ;
struct TYPE_13__ {TYPE_5__ src_change; } ;
struct v4l2_event {unsigned int id; TYPE_6__ u; int /*<<< orphan*/  type; } ;
struct v4l2_enum_dv_timings {int dummy; } ;
struct v4l2_edid {unsigned int pad; int start_block; int blocks; int /*<<< orphan*/  edid; int /*<<< orphan*/  reserved; } ;
struct v4l2_dv_timings_cap {int dummy; } ;
struct file {int dummy; } ;
struct cec_adapter {int /*<<< orphan*/  phys_addr; } ;
typedef  int (* fmtfunc ) (struct file*,void*,struct v4l2_format*) ;
struct TYPE_11__ {scalar_t__ fourcc; } ;
struct TYPE_10__ {scalar_t__ fourcc; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct vivid_fmt*) ; 
 int EINVAL ; 
 int ENODATA ; 
 int ENOTTY ; 
 int ERANGE ; 
 scalar_t__ HDMI ; 
 unsigned int MAX_HEIGHT ; 
 unsigned int MAX_WIDTH ; 
 scalar_t__ SVID ; 
 scalar_t__ TV ; 
 scalar_t__ V4L2_BUF_TYPE_VIDEO_OUTPUT ; 
 scalar_t__ V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE ; 
 scalar_t__ V4L2_CAP_VIDEO_CAPTURE_MPLANE ; 
 int /*<<< orphan*/  V4L2_EVENT_SOURCE_CHANGE ; 
 int /*<<< orphan*/  V4L2_EVENT_SRC_CH_RESOLUTION ; 
 scalar_t__ V4L2_FIELD_SEQ_BT ; 
 scalar_t__ V4L2_FIELD_SEQ_TB ; 
 unsigned int V4L2_SEL_FLAG_GE ; 
 unsigned int V4L2_SEL_FLAG_LE ; 
 int V4L2_STD_525_60 ; 
 scalar_t__ VFL_DIR_RX ; 
 unsigned int VIVID_MPLANAR_FORMATS ; 
 scalar_t__ WEBCAM ; 
 int /*<<< orphan*/  cec_set_edid_phys_addr (scalar_t__,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,scalar_t__,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int v4l2_enum_dv_timings_cap (struct v4l2_enum_dv_timings*,struct v4l2_dv_timings_cap*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  v4l2_event_queue (int /*<<< orphan*/ *,struct v4l2_event*) ; 
 struct video_device* video_devdata (struct file*) ; 
 struct vivid_dev* video_drvdata (struct file*) ; 
 scalar_t__ video_is_registered (int /*<<< orphan*/ *) ; 
 struct v4l2_dv_timings_cap vivid_dv_timings_cap ; 
 struct vivid_fmt* vivid_formats ; 

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

const struct vivid_fmt *vivid_get_format(struct vivid_dev *dev, u32 pixelformat)
{
	const struct vivid_fmt *fmt;
	unsigned k;

	for (k = 0; k < ARRAY_SIZE(vivid_formats); k++) {
		fmt = &vivid_formats[k];
		if (fmt->fourcc == pixelformat)
			if (fmt->buffers == 1 || dev->multiplanar)
				return fmt;
	}

	return NULL;
}

bool vivid_vid_can_loop(struct vivid_dev *dev)
{
	if (dev->src_rect.width != dev->sink_rect.width ||
	    dev->src_rect.height != dev->sink_rect.height)
		return false;
	if (dev->fmt_cap->fourcc != dev->fmt_out->fourcc)
		return false;
	if (dev->field_cap != dev->field_out)
		return false;
	/*
	 * While this can be supported, it is just too much work
	 * to actually implement.
	 */
	if (dev->field_cap == V4L2_FIELD_SEQ_TB ||
	    dev->field_cap == V4L2_FIELD_SEQ_BT)
		return false;
	if (vivid_is_svid_cap(dev) && vivid_is_svid_out(dev)) {
		if (!(dev->std_cap & V4L2_STD_525_60) !=
		    !(dev->std_out & V4L2_STD_525_60))
			return false;
		return true;
	}
	if (vivid_is_hdmi_cap(dev) && vivid_is_hdmi_out(dev))
		return true;
	return false;
}

void vivid_send_source_change(struct vivid_dev *dev, unsigned type)
{
	struct v4l2_event ev = {
		.type = V4L2_EVENT_SOURCE_CHANGE,
		.u.src_change.changes = V4L2_EVENT_SRC_CH_RESOLUTION,
	};
	unsigned i;

	for (i = 0; i < dev->num_inputs; i++) {
		ev.id = i;
		if (dev->input_type[i] == type) {
			if (video_is_registered(&dev->vid_cap_dev) && dev->has_vid_cap)
				v4l2_event_queue(&dev->vid_cap_dev, &ev);
			if (video_is_registered(&dev->vbi_cap_dev) && dev->has_vbi_cap)
				v4l2_event_queue(&dev->vbi_cap_dev, &ev);
		}
	}
}

void fmt_sp2mp(const struct v4l2_format *sp_fmt, struct v4l2_format *mp_fmt)
{
	struct v4l2_pix_format_mplane *mp = &mp_fmt->fmt.pix_mp;
	struct v4l2_plane_pix_format *ppix = &mp->plane_fmt[0];
	const struct v4l2_pix_format *pix = &sp_fmt->fmt.pix;
	bool is_out = sp_fmt->type == V4L2_BUF_TYPE_VIDEO_OUTPUT;

	memset(mp->reserved, 0, sizeof(mp->reserved));
	mp_fmt->type = is_out ? V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE :
			   V4L2_CAP_VIDEO_CAPTURE_MPLANE;
	mp->width = pix->width;
	mp->height = pix->height;
	mp->pixelformat = pix->pixelformat;
	mp->field = pix->field;
	mp->colorspace = pix->colorspace;
	mp->xfer_func = pix->xfer_func;
	/* Also copies hsv_enc */
	mp->ycbcr_enc = pix->ycbcr_enc;
	mp->quantization = pix->quantization;
	mp->num_planes = 1;
	mp->flags = pix->flags;
	ppix->sizeimage = pix->sizeimage;
	ppix->bytesperline = pix->bytesperline;
	memset(ppix->reserved, 0, sizeof(ppix->reserved));
}

int fmt_sp2mp_func(struct file *file, void *priv,
		struct v4l2_format *f, fmtfunc func)
{
	struct v4l2_format fmt;
	struct v4l2_pix_format_mplane *mp = &fmt.fmt.pix_mp;
	struct v4l2_plane_pix_format *ppix = &mp->plane_fmt[0];
	struct v4l2_pix_format *pix = &f->fmt.pix;
	int ret;

	/* Converts to a mplane format */
	fmt_sp2mp(f, &fmt);
	/* Passes it to the generic mplane format function */
	ret = func(file, priv, &fmt);
	/* Copies back the mplane data to the single plane format */
	pix->width = mp->width;
	pix->height = mp->height;
	pix->pixelformat = mp->pixelformat;
	pix->field = mp->field;
	pix->colorspace = mp->colorspace;
	pix->xfer_func = mp->xfer_func;
	/* Also copies hsv_enc */
	pix->ycbcr_enc = mp->ycbcr_enc;
	pix->quantization = mp->quantization;
	pix->sizeimage = ppix->sizeimage;
	pix->bytesperline = ppix->bytesperline;
	pix->flags = mp->flags;
	return ret;
}

int vivid_vid_adjust_sel(unsigned flags, struct v4l2_rect *r)
{
	unsigned w = r->width;
	unsigned h = r->height;

	/* sanitize w and h in case someone passes ~0 as the value */
	w &= 0xffff;
	h &= 0xffff;
	if (!(flags & V4L2_SEL_FLAG_LE)) {
		w++;
		h++;
		if (w < 2)
			w = 2;
		if (h < 2)
			h = 2;
	}
	if (!(flags & V4L2_SEL_FLAG_GE)) {
		if (w > MAX_WIDTH)
			w = MAX_WIDTH;
		if (h > MAX_HEIGHT)
			h = MAX_HEIGHT;
	}
	w = w & ~1;
	h = h & ~1;
	if (w < 2 || h < 2)
		return -ERANGE;
	if (w > MAX_WIDTH || h > MAX_HEIGHT)
		return -ERANGE;
	if (r->top < 0)
		r->top = 0;
	if (r->left < 0)
		r->left = 0;
	/* sanitize left and top in case someone passes ~0 as the value */
	r->left &= 0xfffe;
	r->top &= 0xfffe;
	if (r->left + w > MAX_WIDTH)
		r->left = MAX_WIDTH - w;
	if (r->top + h > MAX_HEIGHT)
		r->top = MAX_HEIGHT - h;
	if ((flags & (V4L2_SEL_FLAG_GE | V4L2_SEL_FLAG_LE)) ==
			(V4L2_SEL_FLAG_GE | V4L2_SEL_FLAG_LE) &&
	    (r->width != w || r->height != h))
		return -ERANGE;
	r->width = w;
	r->height = h;
	return 0;
}

int vivid_enum_fmt_vid(struct file *file, void  *priv,
					struct v4l2_fmtdesc *f)
{
	struct vivid_dev *dev = video_drvdata(file);
	const struct vivid_fmt *fmt;

	if (f->index >= ARRAY_SIZE(vivid_formats) -
	    (dev->multiplanar ? 0 : VIVID_MPLANAR_FORMATS))
		return -EINVAL;

	fmt = &vivid_formats[f->index];

	f->pixelformat = fmt->fourcc;
	return 0;
}

int vidioc_enum_fmt_vid_mplane(struct file *file, void  *priv,
					struct v4l2_fmtdesc *f)
{
	struct vivid_dev *dev = video_drvdata(file);

	if (!dev->multiplanar)
		return -ENOTTY;
	return vivid_enum_fmt_vid(file, priv, f);
}

int vidioc_enum_fmt_vid(struct file *file, void  *priv,
					struct v4l2_fmtdesc *f)
{
	struct vivid_dev *dev = video_drvdata(file);

	if (dev->multiplanar)
		return -ENOTTY;
	return vivid_enum_fmt_vid(file, priv, f);
}

int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
	struct vivid_dev *dev = video_drvdata(file);
	struct video_device *vdev = video_devdata(file);

	if (vdev->vfl_dir == VFL_DIR_RX) {
		if (!vivid_is_sdtv_cap(dev))
			return -ENODATA;
		*id = dev->std_cap;
	} else {
		if (!vivid_is_svid_out(dev))
			return -ENODATA;
		*id = dev->std_out;
	}
	return 0;
}

int vidioc_g_dv_timings(struct file *file, void *_fh,
				    struct v4l2_dv_timings *timings)
{
	struct vivid_dev *dev = video_drvdata(file);
	struct video_device *vdev = video_devdata(file);

	if (vdev->vfl_dir == VFL_DIR_RX) {
		if (!vivid_is_hdmi_cap(dev))
			return -ENODATA;
		*timings = dev->dv_timings_cap;
	} else {
		if (!vivid_is_hdmi_out(dev))
			return -ENODATA;
		*timings = dev->dv_timings_out;
	}
	return 0;
}

int vidioc_enum_dv_timings(struct file *file, void *_fh,
				    struct v4l2_enum_dv_timings *timings)
{
	struct vivid_dev *dev = video_drvdata(file);
	struct video_device *vdev = video_devdata(file);

	if (vdev->vfl_dir == VFL_DIR_RX) {
		if (!vivid_is_hdmi_cap(dev))
			return -ENODATA;
	} else {
		if (!vivid_is_hdmi_out(dev))
			return -ENODATA;
	}
	return v4l2_enum_dv_timings_cap(timings, &vivid_dv_timings_cap,
			NULL, NULL);
}

int vidioc_dv_timings_cap(struct file *file, void *_fh,
				    struct v4l2_dv_timings_cap *cap)
{
	struct vivid_dev *dev = video_drvdata(file);
	struct video_device *vdev = video_devdata(file);

	if (vdev->vfl_dir == VFL_DIR_RX) {
		if (!vivid_is_hdmi_cap(dev))
			return -ENODATA;
	} else {
		if (!vivid_is_hdmi_out(dev))
			return -ENODATA;
	}
	*cap = vivid_dv_timings_cap;
	return 0;
}

int vidioc_g_edid(struct file *file, void *_fh,
			 struct v4l2_edid *edid)
{
	struct vivid_dev *dev = video_drvdata(file);
	struct video_device *vdev = video_devdata(file);
	struct cec_adapter *adap;

	memset(edid->reserved, 0, sizeof(edid->reserved));
	if (vdev->vfl_dir == VFL_DIR_RX) {
		if (edid->pad >= dev->num_inputs)
			return -EINVAL;
		if (dev->input_type[edid->pad] != HDMI)
			return -EINVAL;
		adap = dev->cec_rx_adap;
	} else {
		unsigned int bus_idx;

		if (edid->pad >= dev->num_outputs)
			return -EINVAL;
		if (dev->output_type[edid->pad] != HDMI)
			return -EINVAL;
		bus_idx = dev->cec_output2bus_map[edid->pad];
		adap = dev->cec_tx_adap[bus_idx];
	}
	if (edid->start_block == 0 && edid->blocks == 0) {
		edid->blocks = dev->edid_blocks;
		return 0;
	}
	if (dev->edid_blocks == 0)
		return -ENODATA;
	if (edid->start_block >= dev->edid_blocks)
		return -EINVAL;
	if (edid->blocks > dev->edid_blocks - edid->start_block)
		edid->blocks = dev->edid_blocks - edid->start_block;
	if (adap)
		cec_set_edid_phys_addr(dev->edid, dev->edid_blocks * 128, adap->phys_addr);
	memcpy(edid->edid, dev->edid + edid->start_block * 128, edid->blocks * 128);
	return 0;
}

