#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
struct video_device {int device_caps; } ;
struct v4l2_subdev_frame_interval {int /*<<< orphan*/  interval; int /*<<< orphan*/  member_0; } ;
struct v4l2_subdev {int dummy; } ;
struct TYPE_3__ {int readbuffers; int /*<<< orphan*/  timeperframe; void* capability; } ;
struct TYPE_4__ {TYPE_1__ capture; } ;
struct v4l2_streamparm {scalar_t__ type; TYPE_2__ parm; } ;
struct v4l2_queryctrl {scalar_t__ step; int /*<<< orphan*/  name; scalar_t__* reserved; void* default_value; void* maximum; void* minimum; int /*<<< orphan*/  flags; int /*<<< orphan*/  type; int /*<<< orphan*/  id; } ;
struct timeval {int tv_usec; int /*<<< orphan*/  tv_sec; } ;
struct timespec {int tv_nsec; int /*<<< orphan*/  tv_sec; } ;
typedef  void* s64 ;
typedef  scalar_t__ const s32 ;

/* Variables and functions */
 int EINVAL ; 
 int NSEC_PER_USEC ; 
 scalar_t__ U32_MAX ; 
 scalar_t__ V4L2_BUF_TYPE_VIDEO_CAPTURE ; 
 scalar_t__ V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE ; 
 int V4L2_CAP_READWRITE ; 
 void* V4L2_CAP_TIMEPERFRAME ; 
 unsigned int __ffs (scalar_t__) ; 
 unsigned int __fls (unsigned int) ; 
 scalar_t__ abs (scalar_t__ const) ; 
 unsigned int clamp (unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  g_frame_interval ; 
 int /*<<< orphan*/  ktime_get_ts (struct timespec*) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  s_frame_interval ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  v4l2_ctrl_fill (int /*<<< orphan*/ ,char const**,int /*<<< orphan*/ *,void**,void**,scalar_t__*,void**,int /*<<< orphan*/ *) ; 
 int v4l2_subdev_call (struct v4l2_subdev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct v4l2_subdev_frame_interval*) ; 
 scalar_t__ v4l2_subdev_has_op (struct v4l2_subdev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  video ; 

int v4l2_ctrl_query_fill(struct v4l2_queryctrl *qctrl, s32 _min, s32 _max, s32 _step, s32 _def)
{
	const char *name;
	s64 min = _min;
	s64 max = _max;
	u64 step = _step;
	s64 def = _def;

	v4l2_ctrl_fill(qctrl->id, &name, &qctrl->type,
		       &min, &max, &step, &def, &qctrl->flags);

	if (name == NULL)
		return -EINVAL;

	qctrl->minimum = min;
	qctrl->maximum = max;
	qctrl->step = step;
	qctrl->default_value = def;
	qctrl->reserved[0] = qctrl->reserved[1] = 0;
	strlcpy(qctrl->name, name, sizeof(qctrl->name));
	return 0;
}

__attribute__((used)) static unsigned int clamp_align(unsigned int x, unsigned int min,
				unsigned int max, unsigned int align)
{
	/* Bits that must be zero to be aligned */
	unsigned int mask = ~((1 << align) - 1);

	/* Clamp to aligned min and max */
	x = clamp(x, (min + ~mask) & mask, max & mask);

	/* Round to nearest aligned value */
	if (align)
		x = (x + (1 << (align - 1))) & mask;

	return x;
}

void v4l_bound_align_image(u32 *w, unsigned int wmin, unsigned int wmax,
			   unsigned int walign,
			   u32 *h, unsigned int hmin, unsigned int hmax,
			   unsigned int halign, unsigned int salign)
{
	*w = clamp_align(*w, wmin, wmax, walign);
	*h = clamp_align(*h, hmin, hmax, halign);

	/* Usually we don't need to align the size and are done now. */
	if (!salign)
		return;

	/* How much alignment do we have? */
	walign = __ffs(*w);
	halign = __ffs(*h);
	/* Enough to satisfy the image alignment? */
	if (walign + halign < salign) {
		/* Max walign where there is still a valid width */
		unsigned int wmaxa = __fls(wmax ^ (wmin - 1));
		/* Max halign where there is still a valid height */
		unsigned int hmaxa = __fls(hmax ^ (hmin - 1));

		/* up the smaller alignment until we have enough */
		do {
			if (halign >= hmaxa ||
			    (walign <= halign && walign < wmaxa)) {
				*w = clamp_align(*w, wmin, wmax, walign + 1);
				walign = __ffs(*w);
			} else {
				*h = clamp_align(*h, hmin, hmax, halign + 1);
				halign = __ffs(*h);
			}
		} while (halign + walign < salign);
	}
}

const void *
__v4l2_find_nearest_size(const void *array, size_t array_size,
			 size_t entry_size, size_t width_offset,
			 size_t height_offset, s32 width, s32 height)
{
	u32 error, min_error = U32_MAX;
	const void *best = NULL;
	unsigned int i;

	if (!array)
		return NULL;

	for (i = 0; i < array_size; i++, array += entry_size) {
		const u32 *entry_width = array + width_offset;
		const u32 *entry_height = array + height_offset;

		error = abs(*entry_width - width) + abs(*entry_height - height);
		if (error > min_error)
			continue;

		min_error = error;
		best = array;
		if (!error)
			break;
	}

	return best;
}

void v4l2_get_timestamp(struct timeval *tv)
{
	struct timespec ts;

	ktime_get_ts(&ts);
	tv->tv_sec = ts.tv_sec;
	tv->tv_usec = ts.tv_nsec / NSEC_PER_USEC;
}

int v4l2_g_parm_cap(struct video_device *vdev,
		    struct v4l2_subdev *sd, struct v4l2_streamparm *a)
{
	struct v4l2_subdev_frame_interval ival = { 0 };
	int ret;

	if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
	    a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE)
		return -EINVAL;

	if (vdev->device_caps & V4L2_CAP_READWRITE)
		a->parm.capture.readbuffers = 2;
	if (v4l2_subdev_has_op(sd, video, g_frame_interval))
		a->parm.capture.capability = V4L2_CAP_TIMEPERFRAME;
	ret = v4l2_subdev_call(sd, video, g_frame_interval, &ival);
	if (!ret)
		a->parm.capture.timeperframe = ival.interval;
	return ret;
}

int v4l2_s_parm_cap(struct video_device *vdev,
		    struct v4l2_subdev *sd, struct v4l2_streamparm *a)
{
	struct v4l2_subdev_frame_interval ival = {
		.interval = a->parm.capture.timeperframe
	};
	int ret;

	if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
	    a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE)
		return -EINVAL;

	memset(&a->parm, 0, sizeof(a->parm));
	if (vdev->device_caps & V4L2_CAP_READWRITE)
		a->parm.capture.readbuffers = 2;
	else
		a->parm.capture.readbuffers = 0;

	if (v4l2_subdev_has_op(sd, video, g_frame_interval))
		a->parm.capture.capability = V4L2_CAP_TIMEPERFRAME;
	ret = v4l2_subdev_call(sd, video, s_frame_interval, &ival);
	if (!ret)
		a->parm.capture.timeperframe = ival.interval;
	return ret;
}

