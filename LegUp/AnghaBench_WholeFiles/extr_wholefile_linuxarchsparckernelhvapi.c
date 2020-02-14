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
struct api_info {unsigned long group; scalar_t__ refcnt; unsigned long major; unsigned long minor; int flags; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct api_info*) ; 
 int EINVAL ; 
 int FLAG_PRE_API ; 
 unsigned long HV_EBADTRAP ; 
 unsigned long HV_ENOTSUPPORTED ; 
 unsigned long HV_EOK ; 
 struct api_info* api_table ; 
 int /*<<< orphan*/  hvapi_lock ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned long sun4v_set_version (unsigned long,unsigned long,unsigned long,unsigned long*) ; 

__attribute__((used)) static struct api_info *__get_info(unsigned long group)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(api_table); i++) {
		if (api_table[i].group == group)
			return &api_table[i];
	}
	return NULL;
}

__attribute__((used)) static void __get_ref(struct api_info *p)
{
	p->refcnt++;
}

__attribute__((used)) static void __put_ref(struct api_info *p)
{
	if (--p->refcnt == 0) {
		unsigned long ignore;

		sun4v_set_version(p->group, 0, 0, &ignore);
		p->major = p->minor = 0;
	}
}

int sun4v_hvapi_register(unsigned long group, unsigned long major,
			 unsigned long *minor)
{
	struct api_info *p;
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&hvapi_lock, flags);
	p = __get_info(group);
	ret = -EINVAL;
	if (p) {
		if (p->refcnt) {
			ret = -EINVAL;
			if (p->major == major) {
				*minor = p->minor;
				ret = 0;
			}
		} else {
			unsigned long actual_minor;
			unsigned long hv_ret;

			hv_ret = sun4v_set_version(group, major, *minor,
						   &actual_minor);
			ret = -EINVAL;
			if (hv_ret == HV_EOK) {
				*minor = actual_minor;
				p->major = major;
				p->minor = actual_minor;
				ret = 0;
			} else if (hv_ret == HV_EBADTRAP ||
				   hv_ret == HV_ENOTSUPPORTED) {
				if (p->flags & FLAG_PRE_API) {
					if (major == 1) {
						p->major = 1;
						p->minor = 0;
						*minor = 0;
						ret = 0;
					}
				}
			}
		}

		if (ret == 0)
			__get_ref(p);
	}
	spin_unlock_irqrestore(&hvapi_lock, flags);

	return ret;
}

void sun4v_hvapi_unregister(unsigned long group)
{
	struct api_info *p;
	unsigned long flags;

	spin_lock_irqsave(&hvapi_lock, flags);
	p = __get_info(group);
	if (p)
		__put_ref(p);
	spin_unlock_irqrestore(&hvapi_lock, flags);
}

int sun4v_hvapi_get(unsigned long group,
		    unsigned long *major,
		    unsigned long *minor)
{
	struct api_info *p;
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&hvapi_lock, flags);
	ret = -EINVAL;
	p = __get_info(group);
	if (p && p->refcnt) {
		*major = p->major;
		*minor = p->minor;
		ret = 0;
	}
	spin_unlock_irqrestore(&hvapi_lock, flags);

	return ret;
}

