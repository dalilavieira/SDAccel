#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct iw_point {int length; int /*<<< orphan*/  pointer; } ;
union iwreq_data {struct iw_point data; } ;
struct net_device {TYPE_1__* wireless_handlers; } ;
struct iwreq {union iwreq_data u; } ;
struct iw_request_info {int dummy; } ;
struct iw_priv_args {unsigned int cmd; char* name; int set_args; int get_args; } ;
typedef  int (* iw_handler ) (struct net_device*,struct iw_request_info*,union iwreq_data*,char*) ;
typedef  int /*<<< orphan*/  __u32 ;
typedef  int __u16 ;
struct TYPE_2__ {scalar_t__ num_private_args; struct iw_priv_args* private_args; } ;

/* Variables and functions */
 int E2BIG ; 
 int EFAULT ; 
 int EINVAL ; 
 int EIWCOMMIT ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IFNAMSIZ ; 
 scalar_t__ IW_IS_GET (unsigned int) ; 
 scalar_t__ IW_IS_SET (unsigned int) ; 
 int IW_PRIV_SIZE_FIXED ; 
 int IW_PRIV_SIZE_MASK ; 
 int IW_PRIV_TYPE_MASK ; 
 int call_commit_handler (struct net_device*) ; 
 scalar_t__ copy_from_user (char*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ copy_to_user (int /*<<< orphan*/ ,char*,int) ; 
 int* iw_priv_type_size ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,struct iw_priv_args*,int) ; 

int iw_handler_get_private(struct net_device *		dev,
			   struct iw_request_info *	info,
			   union iwreq_data *		wrqu,
			   char *			extra)
{
	/* Check if the driver has something to export */
	if ((dev->wireless_handlers->num_private_args == 0) ||
	   (dev->wireless_handlers->private_args == NULL))
		return -EOPNOTSUPP;

	/* Check if there is enough buffer up there */
	if (wrqu->data.length < dev->wireless_handlers->num_private_args) {
		/* User space can't know in advance how large the buffer
		 * needs to be. Give it a hint, so that we can support
		 * any size buffer we want somewhat efficiently... */
		wrqu->data.length = dev->wireless_handlers->num_private_args;
		return -E2BIG;
	}

	/* Set the number of available ioctls. */
	wrqu->data.length = dev->wireless_handlers->num_private_args;

	/* Copy structure to the user buffer. */
	memcpy(extra, dev->wireless_handlers->private_args,
	       sizeof(struct iw_priv_args) * wrqu->data.length);

	return 0;
}

__attribute__((used)) static int get_priv_size(__u16 args)
{
	int	num = args & IW_PRIV_SIZE_MASK;
	int	type = (args & IW_PRIV_TYPE_MASK) >> 12;

	return num * iw_priv_type_size[type];
}

__attribute__((used)) static int adjust_priv_size(__u16 args, struct iw_point *iwp)
{
	int	num = iwp->length;
	int	max = args & IW_PRIV_SIZE_MASK;
	int	type = (args & IW_PRIV_TYPE_MASK) >> 12;

	/* Make sure the driver doesn't goof up */
	if (max < num)
		num = max;

	return num * iw_priv_type_size[type];
}

__attribute__((used)) static int get_priv_descr_and_size(struct net_device *dev, unsigned int cmd,
				   const struct iw_priv_args **descrp)
{
	const struct iw_priv_args *descr;
	int i, extra_size;

	descr = NULL;
	for (i = 0; i < dev->wireless_handlers->num_private_args; i++) {
		if (cmd == dev->wireless_handlers->private_args[i].cmd) {
			descr = &dev->wireless_handlers->private_args[i];
			break;
		}
	}

	extra_size = 0;
	if (descr) {
		if (IW_IS_SET(cmd)) {
			int	offset = 0;	/* For sub-ioctls */
			/* Check for sub-ioctl handler */
			if (descr->name[0] == '\0')
				/* Reserve one int for sub-ioctl index */
				offset = sizeof(__u32);

			/* Size of set arguments */
			extra_size = get_priv_size(descr->set_args);

			/* Does it fits in iwr ? */
			if ((descr->set_args & IW_PRIV_SIZE_FIXED) &&
			   ((extra_size + offset) <= IFNAMSIZ))
				extra_size = 0;
		} else {
			/* Size of get arguments */
			extra_size = get_priv_size(descr->get_args);

			/* Does it fits in iwr ? */
			if ((descr->get_args & IW_PRIV_SIZE_FIXED) &&
			   (extra_size <= IFNAMSIZ))
				extra_size = 0;
		}
	}
	*descrp = descr;
	return extra_size;
}

__attribute__((used)) static int ioctl_private_iw_point(struct iw_point *iwp, unsigned int cmd,
				  const struct iw_priv_args *descr,
				  iw_handler handler, struct net_device *dev,
				  struct iw_request_info *info, int extra_size)
{
	char *extra;
	int err;

	/* Check what user space is giving us */
	if (IW_IS_SET(cmd)) {
		if (!iwp->pointer && iwp->length != 0)
			return -EFAULT;

		if (iwp->length > (descr->set_args & IW_PRIV_SIZE_MASK))
			return -E2BIG;
	} else if (!iwp->pointer)
		return -EFAULT;

	extra = kzalloc(extra_size, GFP_KERNEL);
	if (!extra)
		return -ENOMEM;

	/* If it is a SET, get all the extra data in here */
	if (IW_IS_SET(cmd) && (iwp->length != 0)) {
		if (copy_from_user(extra, iwp->pointer, extra_size)) {
			err = -EFAULT;
			goto out;
		}
	}

	/* Call the handler */
	err = handler(dev, info, (union iwreq_data *) iwp, extra);

	/* If we have something to return to the user */
	if (!err && IW_IS_GET(cmd)) {
		/* Adjust for the actual length if it's variable,
		 * avoid leaking kernel bits outside.
		 */
		if (!(descr->get_args & IW_PRIV_SIZE_FIXED))
			extra_size = adjust_priv_size(descr->get_args, iwp);

		if (copy_to_user(iwp->pointer, extra, extra_size))
			err =  -EFAULT;
	}

out:
	kfree(extra);
	return err;
}

int ioctl_private_call(struct net_device *dev, struct iwreq *iwr,
		       unsigned int cmd, struct iw_request_info *info,
		       iw_handler handler)
{
	int extra_size = 0, ret = -EINVAL;
	const struct iw_priv_args *descr;

	extra_size = get_priv_descr_and_size(dev, cmd, &descr);

	/* Check if we have a pointer to user space data or not. */
	if (extra_size == 0) {
		/* No extra arguments. Trivial to handle */
		ret = handler(dev, info, &(iwr->u), (char *) &(iwr->u));
	} else {
		ret = ioctl_private_iw_point(&iwr->u.data, cmd, descr,
					     handler, dev, info, extra_size);
	}

	/* Call commit handler if needed and defined */
	if (ret == -EIWCOMMIT)
		ret = call_commit_handler(dev);

	return ret;
}

