#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct video_device {int /*<<< orphan*/  fh_lock; int /*<<< orphan*/  prio; int /*<<< orphan*/  fh_list; int /*<<< orphan*/ * valid_ioctls; int /*<<< orphan*/  flags; int /*<<< orphan*/  ctrl_handler; } ;
struct v4l2_fh {int sequence; struct video_device* vdev; int /*<<< orphan*/  list; int /*<<< orphan*/  subscribe_lock; int /*<<< orphan*/  prio; int /*<<< orphan*/  subscribed; int /*<<< orphan*/  available; int /*<<< orphan*/  wait; int /*<<< orphan*/  ctrl_handler; } ;
struct file {struct v4l2_fh* private_data; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  V4L2_FL_USES_V4L2_FH ; 
 int /*<<< orphan*/  V4L2_PRIORITY_UNSET ; 
 int /*<<< orphan*/  VIDIOC_G_PRIORITY ; 
 int /*<<< orphan*/  VIDIOC_S_PRIORITY ; 
 int /*<<< orphan*/  _IOC_NR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct v4l2_fh*) ; 
 struct v4l2_fh* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 
 int list_is_singular (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  v4l2_event_unsubscribe_all (struct v4l2_fh*) ; 
 int /*<<< orphan*/  v4l2_prio_close (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  v4l2_prio_open (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  v4l_disable_media_source (struct video_device*) ; 
 struct video_device* video_devdata (struct file*) ; 

void v4l2_fh_init(struct v4l2_fh *fh, struct video_device *vdev)
{
	fh->vdev = vdev;
	/* Inherit from video_device. May be overridden by the driver. */
	fh->ctrl_handler = vdev->ctrl_handler;
	INIT_LIST_HEAD(&fh->list);
	set_bit(V4L2_FL_USES_V4L2_FH, &fh->vdev->flags);
	/*
	 * determine_valid_ioctls() does not know if struct v4l2_fh
	 * is used by this driver, but here we do. So enable the
	 * prio ioctls here.
	 */
	set_bit(_IOC_NR(VIDIOC_G_PRIORITY), vdev->valid_ioctls);
	set_bit(_IOC_NR(VIDIOC_S_PRIORITY), vdev->valid_ioctls);
	fh->prio = V4L2_PRIORITY_UNSET;
	init_waitqueue_head(&fh->wait);
	INIT_LIST_HEAD(&fh->available);
	INIT_LIST_HEAD(&fh->subscribed);
	fh->sequence = -1;
	mutex_init(&fh->subscribe_lock);
}

void v4l2_fh_add(struct v4l2_fh *fh)
{
	unsigned long flags;

	v4l2_prio_open(fh->vdev->prio, &fh->prio);
	spin_lock_irqsave(&fh->vdev->fh_lock, flags);
	list_add(&fh->list, &fh->vdev->fh_list);
	spin_unlock_irqrestore(&fh->vdev->fh_lock, flags);
}

int v4l2_fh_open(struct file *filp)
{
	struct video_device *vdev = video_devdata(filp);
	struct v4l2_fh *fh = kzalloc(sizeof(*fh), GFP_KERNEL);

	filp->private_data = fh;
	if (fh == NULL)
		return -ENOMEM;
	v4l2_fh_init(fh, vdev);
	v4l2_fh_add(fh);
	return 0;
}

void v4l2_fh_del(struct v4l2_fh *fh)
{
	unsigned long flags;

	spin_lock_irqsave(&fh->vdev->fh_lock, flags);
	list_del_init(&fh->list);
	spin_unlock_irqrestore(&fh->vdev->fh_lock, flags);
	v4l2_prio_close(fh->vdev->prio, fh->prio);
}

void v4l2_fh_exit(struct v4l2_fh *fh)
{
	if (fh->vdev == NULL)
		return;
	v4l_disable_media_source(fh->vdev);
	v4l2_event_unsubscribe_all(fh);
	mutex_destroy(&fh->subscribe_lock);
	fh->vdev = NULL;
}

int v4l2_fh_release(struct file *filp)
{
	struct v4l2_fh *fh = filp->private_data;

	if (fh) {
		v4l2_fh_del(fh);
		v4l2_fh_exit(fh);
		kfree(fh);
	}
	return 0;
}

int v4l2_fh_is_singular(struct v4l2_fh *fh)
{
	unsigned long flags;
	int is_singular;

	if (fh == NULL || fh->vdev == NULL)
		return 0;
	spin_lock_irqsave(&fh->vdev->fh_lock, flags);
	is_singular = list_is_singular(&fh->list);
	spin_unlock_irqrestore(&fh->vdev->fh_lock, flags);
	return is_singular;
}

