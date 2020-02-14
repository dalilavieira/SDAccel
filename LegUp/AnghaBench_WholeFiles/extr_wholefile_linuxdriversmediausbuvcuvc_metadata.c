#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct video_device {int /*<<< orphan*/ * queue; } ;
struct v4l2_meta_format {scalar_t__ dataformat; scalar_t__ index; scalar_t__ type; scalar_t__ pixelformat; void* buffersize; } ;
struct TYPE_5__ {struct v4l2_meta_format meta; } ;
struct v4l2_format {scalar_t__ type; TYPE_1__ fmt; } ;
struct v4l2_fmtdesc {scalar_t__ dataformat; scalar_t__ index; scalar_t__ type; scalar_t__ pixelformat; void* buffersize; } ;
struct v4l2_fh {TYPE_4__* vdev; } ;
struct v4l2_ext_control {int dummy; } ;
struct v4l2_capability {int capabilities; int /*<<< orphan*/  bus_info; int /*<<< orphan*/  card; int /*<<< orphan*/  driver; } ;
struct uvc_video_queue {int /*<<< orphan*/  queue; } ;
struct uvc_video_chain {int caps; } ;
struct TYPE_7__ {scalar_t__ format; struct uvc_video_queue queue; struct video_device vdev; } ;
struct uvc_streaming {TYPE_3__ meta; struct uvc_device* dev; int /*<<< orphan*/  mutex; int /*<<< orphan*/  queue; struct uvc_video_chain* chain; } ;
struct uvc_fh {int dummy; } ;
struct uvc_device {scalar_t__ meta_format; int /*<<< orphan*/  udev; } ;
struct file {struct v4l2_fh* private_data; } ;
struct TYPE_8__ {char* name; TYPE_2__* queue; } ;
struct TYPE_6__ {scalar_t__ type; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 void* UVC_METATADA_BUF_SIZE ; 
 int /*<<< orphan*/  V4L2_BUF_TYPE_META_CAPTURE ; 
 int V4L2_CAP_DEVICE_CAPS ; 
 int V4L2_CAP_STREAMING ; 
 scalar_t__ V4L2_META_FMT_UVC ; 
 int __uvc_ctrl_commit (struct uvc_fh*,int,struct v4l2_ext_control const*,unsigned int) ; 
 int /*<<< orphan*/  memset (struct v4l2_meta_format*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  usb_make_path (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uvc_meta_fops ; 
 int /*<<< orphan*/  uvc_meta_ioctl_ops ; 
 scalar_t__ uvc_queue_allocated (int /*<<< orphan*/ *) ; 
 int uvc_register_video_device (struct uvc_device*,struct uvc_streaming*,struct video_device*,struct uvc_video_queue*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int vb2_is_streaming (int /*<<< orphan*/ *) ; 
 struct uvc_streaming* video_get_drvdata (TYPE_4__*) ; 

__attribute__((used)) static inline int uvc_queue_streaming(struct uvc_video_queue *queue)
{
	return vb2_is_streaming(&queue->queue);
}

__attribute__((used)) static inline int uvc_ctrl_commit(struct uvc_fh *handle,
				  const struct v4l2_ext_control *xctrls,
				  unsigned int xctrls_count)
{
	return __uvc_ctrl_commit(handle, 0, xctrls, xctrls_count);
}

__attribute__((used)) static inline int uvc_ctrl_rollback(struct uvc_fh *handle)
{
	return __uvc_ctrl_commit(handle, 1, NULL, 0);
}

__attribute__((used)) static int uvc_meta_v4l2_querycap(struct file *file, void *fh,
				  struct v4l2_capability *cap)
{
	struct v4l2_fh *vfh = file->private_data;
	struct uvc_streaming *stream = video_get_drvdata(vfh->vdev);
	struct uvc_video_chain *chain = stream->chain;

	strlcpy(cap->driver, "uvcvideo", sizeof(cap->driver));
	strlcpy(cap->card, vfh->vdev->name, sizeof(cap->card));
	usb_make_path(stream->dev->udev, cap->bus_info, sizeof(cap->bus_info));
	cap->capabilities = V4L2_CAP_DEVICE_CAPS | V4L2_CAP_STREAMING
			  | chain->caps;

	return 0;
}

__attribute__((used)) static int uvc_meta_v4l2_get_format(struct file *file, void *fh,
				    struct v4l2_format *format)
{
	struct v4l2_fh *vfh = file->private_data;
	struct uvc_streaming *stream = video_get_drvdata(vfh->vdev);
	struct v4l2_meta_format *fmt = &format->fmt.meta;

	if (format->type != vfh->vdev->queue->type)
		return -EINVAL;

	memset(fmt, 0, sizeof(*fmt));

	fmt->dataformat = stream->meta.format;
	fmt->buffersize = UVC_METATADA_BUF_SIZE;

	return 0;
}

__attribute__((used)) static int uvc_meta_v4l2_try_format(struct file *file, void *fh,
				    struct v4l2_format *format)
{
	struct v4l2_fh *vfh = file->private_data;
	struct uvc_streaming *stream = video_get_drvdata(vfh->vdev);
	struct uvc_device *dev = stream->dev;
	struct v4l2_meta_format *fmt = &format->fmt.meta;
	u32 fmeta = fmt->dataformat;

	if (format->type != vfh->vdev->queue->type)
		return -EINVAL;

	memset(fmt, 0, sizeof(*fmt));

	fmt->dataformat = fmeta == dev->meta_format ? fmeta : V4L2_META_FMT_UVC;
	fmt->buffersize = UVC_METATADA_BUF_SIZE;

	return 0;
}

__attribute__((used)) static int uvc_meta_v4l2_set_format(struct file *file, void *fh,
				    struct v4l2_format *format)
{
	struct v4l2_fh *vfh = file->private_data;
	struct uvc_streaming *stream = video_get_drvdata(vfh->vdev);
	struct v4l2_meta_format *fmt = &format->fmt.meta;
	int ret;

	ret = uvc_meta_v4l2_try_format(file, fh, format);
	if (ret < 0)
		return ret;

	/*
	 * We could in principle switch at any time, also during streaming.
	 * Metadata buffers would still be perfectly parseable, but it's more
	 * consistent and cleaner to disallow that.
	 */
	mutex_lock(&stream->mutex);

	if (uvc_queue_allocated(&stream->queue))
		ret = -EBUSY;
	else
		stream->meta.format = fmt->dataformat;

	mutex_unlock(&stream->mutex);

	return ret;
}

__attribute__((used)) static int uvc_meta_v4l2_enum_formats(struct file *file, void *fh,
				      struct v4l2_fmtdesc *fdesc)
{
	struct v4l2_fh *vfh = file->private_data;
	struct uvc_streaming *stream = video_get_drvdata(vfh->vdev);
	struct uvc_device *dev = stream->dev;
	u32 index = fdesc->index;

	if (fdesc->type != vfh->vdev->queue->type ||
	    index > 1U || (index && !dev->meta_format))
		return -EINVAL;

	memset(fdesc, 0, sizeof(*fdesc));

	fdesc->type = vfh->vdev->queue->type;
	fdesc->index = index;
	fdesc->pixelformat = index ? dev->meta_format : V4L2_META_FMT_UVC;

	return 0;
}

int uvc_meta_register(struct uvc_streaming *stream)
{
	struct uvc_device *dev = stream->dev;
	struct video_device *vdev = &stream->meta.vdev;
	struct uvc_video_queue *queue = &stream->meta.queue;

	stream->meta.format = V4L2_META_FMT_UVC;

	/*
	 * The video interface queue uses manual locking and thus does not set
	 * the queue pointer. Set it manually here.
	 */
	vdev->queue = &queue->queue;

	return uvc_register_video_device(dev, stream, vdev, queue,
					 V4L2_BUF_TYPE_META_CAPTURE,
					 &uvc_meta_fops, &uvc_meta_ioctl_ops);
}

