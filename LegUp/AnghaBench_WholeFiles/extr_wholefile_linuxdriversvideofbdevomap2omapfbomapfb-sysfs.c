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
typedef  int u8 ;
struct omapfb_info {scalar_t__ num_overlays; unsigned int rotation_type; unsigned int mirror; int* rotation; struct omapfb2_mem_region* region; struct omap_overlay** overlays; struct omapfb2_device* fbdev; } ;
struct omapfb_display_data {struct omap_dss_device* dssdev; } ;
struct omapfb2_mem_region {unsigned long size; unsigned int paddr; unsigned int vaddr; int /*<<< orphan*/  lock; int /*<<< orphan*/  lock_count; int /*<<< orphan*/  type; int /*<<< orphan*/  map_count; int /*<<< orphan*/  id; } ;
struct omapfb2_device {int num_displays; int num_overlays; int num_fbs; struct fb_info** fbs; struct device* dev; struct omap_overlay** overlays; int /*<<< orphan*/  mtx; struct omapfb_display_data* displays; } ;
struct omap_overlay {int (* enable ) (struct omap_overlay*) ;int (* disable ) (struct omap_overlay*) ;scalar_t__ (* is_enabled ) (struct omap_overlay*) ;TYPE_2__* manager; int /*<<< orphan*/  id; struct omap_dss_device* (* get_device ) (struct omap_overlay*) ;} ;
struct omap_dss_device {TYPE_1__* driver; } ;
struct fb_var_screeninfo {int dummy; } ;
struct fb_info {int /*<<< orphan*/  dev; struct fb_var_screeninfo var; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  new_var ;
typedef  enum omapfb_update_mode { ____Placeholder_omapfb_update_mode } omapfb_update_mode ;
struct TYPE_4__ {int /*<<< orphan*/  (* apply ) (TYPE_2__*) ;} ;
struct TYPE_3__ {int /*<<< orphan*/  (* sync ) (struct omap_dss_device*) ;} ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  DBG (char*,...) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 struct omapfb_info* FB2OFB (struct fb_info*) ; 
 int OMAPFB_MAX_OVL_PER_FB ; 
 int OMAP_DSS_ROT_DMA ; 
 int OMAP_DSS_ROT_VRFB ; 
 unsigned long PAGE_ALIGN (unsigned long) ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int check_fb_var (struct fb_info*,struct fb_var_screeninfo*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct fb_info* dev_get_drvdata (struct device*) ; 
 int device_create_file (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  down_read_nested (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  down_write_nested (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int kstrtoint (char const*,int /*<<< orphan*/ ,int*) ; 
 int kstrtouint (char const*,int /*<<< orphan*/ ,unsigned int*) ; 
 int kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  lock_fb_info (struct fb_info*) ; 
 int /*<<< orphan*/  memcpy (struct fb_var_screeninfo*,struct fb_var_screeninfo*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int omapfb_apply_changes (struct fb_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * omapfb_attrs ; 
 int omapfb_get_update_mode (struct fb_info*,int*) ; 
 int omapfb_realloc_fbmem (struct fb_info*,unsigned long,int /*<<< orphan*/ ) ; 
 int omapfb_set_update_mode (struct fb_info*,unsigned int) ; 
 int /*<<< orphan*/  set_fb_fix (struct fb_info*) ; 
 int simple_strtoul (char*,char**,int /*<<< orphan*/ ) ; 
 int snprintf (char*,int,char*,...) ; 
 int strlen (char const*) ; 
 int strtobool (char const*,int*) ; 
 struct omap_dss_device* stub1 (struct omap_overlay*) ; 
 int stub2 (struct omap_overlay*) ; 
 int stub3 (struct omap_overlay*) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub5 (struct omap_dss_device*) ; 
 scalar_t__ stub6 (struct omap_overlay*) ; 
 int /*<<< orphan*/  unlock_fb_info (struct fb_info*) ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline struct omap_dss_device *fb2display(struct fb_info *fbi)
{
	struct omapfb_info *ofbi = FB2OFB(fbi);
	struct omap_overlay *ovl;

	/* XXX: returns the display connected to first attached overlay */

	if (ofbi->num_overlays == 0)
		return NULL;

	ovl = ofbi->overlays[0];

	return ovl->get_device(ovl);
}

__attribute__((used)) static inline struct omapfb_display_data *get_display_data(
		struct omapfb2_device *fbdev, struct omap_dss_device *dssdev)
{
	int i;

	for (i = 0; i < fbdev->num_displays; ++i)
		if (fbdev->displays[i].dssdev == dssdev)
			return &fbdev->displays[i];

	/* This should never happen */
	BUG();
	return NULL;
}

__attribute__((used)) static inline void omapfb_lock(struct omapfb2_device *fbdev)
{
	mutex_lock(&fbdev->mtx);
}

__attribute__((used)) static inline void omapfb_unlock(struct omapfb2_device *fbdev)
{
	mutex_unlock(&fbdev->mtx);
}

__attribute__((used)) static inline int omapfb_overlay_enable(struct omap_overlay *ovl,
		int enable)
{
	if (enable)
		return ovl->enable(ovl);
	else
		return ovl->disable(ovl);
}

__attribute__((used)) static inline struct omapfb2_mem_region *
omapfb_get_mem_region(struct omapfb2_mem_region *rg)
{
	down_read_nested(&rg->lock, rg->id);
	atomic_inc(&rg->lock_count);
	return rg;
}

__attribute__((used)) static inline void omapfb_put_mem_region(struct omapfb2_mem_region *rg)
{
	atomic_dec(&rg->lock_count);
	up_read(&rg->lock);
}

__attribute__((used)) static ssize_t show_rotate_type(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);

	return snprintf(buf, PAGE_SIZE, "%d\n", ofbi->rotation_type);
}

__attribute__((used)) static ssize_t store_rotate_type(struct device *dev,
		struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);
	struct omapfb2_mem_region *rg;
	int rot_type;
	int r;

	r = kstrtoint(buf, 0, &rot_type);
	if (r)
		return r;

	if (rot_type != OMAP_DSS_ROT_DMA && rot_type != OMAP_DSS_ROT_VRFB)
		return -EINVAL;

	if (!lock_fb_info(fbi))
		return -ENODEV;

	r = 0;
	if (rot_type == ofbi->rotation_type)
		goto out;

	rg = omapfb_get_mem_region(ofbi->region);

	if (rg->size) {
		r = -EBUSY;
		goto put_region;
	}

	ofbi->rotation_type = rot_type;

	/*
	 * Since the VRAM for this FB is not allocated at the moment we don't
	 * need to do any further parameter checking at this point.
	 */
put_region:
	omapfb_put_mem_region(rg);
out:
	unlock_fb_info(fbi);

	return r ? r : count;
}

__attribute__((used)) static ssize_t show_mirror(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);

	return snprintf(buf, PAGE_SIZE, "%d\n", ofbi->mirror);
}

__attribute__((used)) static ssize_t store_mirror(struct device *dev,
		struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);
	bool mirror;
	int r;
	struct fb_var_screeninfo new_var;

	r = strtobool(buf, &mirror);
	if (r)
		return r;

	if (!lock_fb_info(fbi))
		return -ENODEV;

	ofbi->mirror = mirror;

	omapfb_get_mem_region(ofbi->region);

	memcpy(&new_var, &fbi->var, sizeof(new_var));
	r = check_fb_var(fbi, &new_var);
	if (r)
		goto out;
	memcpy(&fbi->var, &new_var, sizeof(fbi->var));

	set_fb_fix(fbi);

	r = omapfb_apply_changes(fbi, 0);
	if (r)
		goto out;

	r = count;
out:
	omapfb_put_mem_region(ofbi->region);

	unlock_fb_info(fbi);

	return r;
}

__attribute__((used)) static ssize_t show_overlays(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);
	struct omapfb2_device *fbdev = ofbi->fbdev;
	ssize_t l = 0;
	int t;

	if (!lock_fb_info(fbi))
		return -ENODEV;
	omapfb_lock(fbdev);

	for (t = 0; t < ofbi->num_overlays; t++) {
		struct omap_overlay *ovl = ofbi->overlays[t];
		int ovlnum;

		for (ovlnum = 0; ovlnum < fbdev->num_overlays; ++ovlnum)
			if (ovl == fbdev->overlays[ovlnum])
				break;

		l += snprintf(buf + l, PAGE_SIZE - l, "%s%d",
				t == 0 ? "" : ",", ovlnum);
	}

	l += snprintf(buf + l, PAGE_SIZE - l, "\n");

	omapfb_unlock(fbdev);
	unlock_fb_info(fbi);

	return l;
}

__attribute__((used)) static struct omapfb_info *get_overlay_fb(struct omapfb2_device *fbdev,
		struct omap_overlay *ovl)
{
	int i, t;

	for (i = 0; i < fbdev->num_fbs; i++) {
		struct omapfb_info *ofbi = FB2OFB(fbdev->fbs[i]);

		for (t = 0; t < ofbi->num_overlays; t++) {
			if (ofbi->overlays[t] == ovl)
				return ofbi;
		}
	}

	return NULL;
}

__attribute__((used)) static ssize_t store_overlays(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);
	struct omapfb2_device *fbdev = ofbi->fbdev;
	struct omap_overlay *ovls[OMAPFB_MAX_OVL_PER_FB];
	struct omap_overlay *ovl;
	int num_ovls, r, i;
	int len;
	bool added = false;

	num_ovls = 0;

	len = strlen(buf);
	if (buf[len - 1] == '\n')
		len = len - 1;

	if (!lock_fb_info(fbi))
		return -ENODEV;
	omapfb_lock(fbdev);

	if (len > 0) {
		char *p = (char *)buf;
		int ovlnum;

		while (p < buf + len) {
			int found;
			if (num_ovls == OMAPFB_MAX_OVL_PER_FB) {
				r = -EINVAL;
				goto out;
			}

			ovlnum = simple_strtoul(p, &p, 0);
			if (ovlnum > fbdev->num_overlays) {
				r = -EINVAL;
				goto out;
			}

			found = 0;
			for (i = 0; i < num_ovls; ++i) {
				if (ovls[i] == fbdev->overlays[ovlnum]) {
					found = 1;
					break;
				}
			}

			if (!found)
				ovls[num_ovls++] = fbdev->overlays[ovlnum];

			p++;
		}
	}

	for (i = 0; i < num_ovls; ++i) {
		struct omapfb_info *ofbi2 = get_overlay_fb(fbdev, ovls[i]);
		if (ofbi2 && ofbi2 != ofbi) {
			dev_err(fbdev->dev, "overlay already in use\n");
			r = -EINVAL;
			goto out;
		}
	}

	/* detach unused overlays */
	for (i = 0; i < ofbi->num_overlays; ++i) {
		int t, found;

		ovl = ofbi->overlays[i];

		found = 0;

		for (t = 0; t < num_ovls; ++t) {
			if (ovl == ovls[t]) {
				found = 1;
				break;
			}
		}

		if (found)
			continue;

		DBG("detaching %d\n", ofbi->overlays[i]->id);

		omapfb_get_mem_region(ofbi->region);

		omapfb_overlay_enable(ovl, 0);

		if (ovl->manager)
			ovl->manager->apply(ovl->manager);

		omapfb_put_mem_region(ofbi->region);

		for (t = i + 1; t < ofbi->num_overlays; t++) {
			ofbi->rotation[t-1] = ofbi->rotation[t];
			ofbi->overlays[t-1] = ofbi->overlays[t];
		}

		ofbi->num_overlays--;
		i--;
	}

	for (i = 0; i < num_ovls; ++i) {
		int t, found;

		ovl = ovls[i];

		found = 0;

		for (t = 0; t < ofbi->num_overlays; ++t) {
			if (ovl == ofbi->overlays[t]) {
				found = 1;
				break;
			}
		}

		if (found)
			continue;
		ofbi->rotation[ofbi->num_overlays] = 0;
		ofbi->overlays[ofbi->num_overlays++] = ovl;

		added = true;
	}

	if (added) {
		omapfb_get_mem_region(ofbi->region);

		r = omapfb_apply_changes(fbi, 0);

		omapfb_put_mem_region(ofbi->region);

		if (r)
			goto out;
	}

	r = count;
out:
	omapfb_unlock(fbdev);
	unlock_fb_info(fbi);

	return r;
}

__attribute__((used)) static ssize_t show_overlays_rotate(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);
	ssize_t l = 0;
	int t;

	if (!lock_fb_info(fbi))
		return -ENODEV;

	for (t = 0; t < ofbi->num_overlays; t++) {
		l += snprintf(buf + l, PAGE_SIZE - l, "%s%d",
				t == 0 ? "" : ",", ofbi->rotation[t]);
	}

	l += snprintf(buf + l, PAGE_SIZE - l, "\n");

	unlock_fb_info(fbi);

	return l;
}

__attribute__((used)) static ssize_t store_overlays_rotate(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);
	int num_ovls = 0, r, i;
	int len;
	bool changed = false;
	u8 rotation[OMAPFB_MAX_OVL_PER_FB];

	len = strlen(buf);
	if (buf[len - 1] == '\n')
		len = len - 1;

	if (!lock_fb_info(fbi))
		return -ENODEV;

	if (len > 0) {
		char *p = (char *)buf;

		while (p < buf + len) {
			int rot;

			if (num_ovls == ofbi->num_overlays) {
				r = -EINVAL;
				goto out;
			}

			rot = simple_strtoul(p, &p, 0);
			if (rot < 0 || rot > 3) {
				r = -EINVAL;
				goto out;
			}

			if (ofbi->rotation[num_ovls] != rot)
				changed = true;

			rotation[num_ovls++] = rot;

			p++;
		}
	}

	if (num_ovls != ofbi->num_overlays) {
		r = -EINVAL;
		goto out;
	}

	if (changed) {
		for (i = 0; i < num_ovls; ++i)
			ofbi->rotation[i] = rotation[i];

		omapfb_get_mem_region(ofbi->region);

		r = omapfb_apply_changes(fbi, 0);

		omapfb_put_mem_region(ofbi->region);

		if (r)
			goto out;

		/* FIXME error handling? */
	}

	r = count;
out:
	unlock_fb_info(fbi);

	return r;
}

__attribute__((used)) static ssize_t show_size(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);

	return snprintf(buf, PAGE_SIZE, "%lu\n", ofbi->region->size);
}

__attribute__((used)) static ssize_t store_size(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);
	struct omapfb2_device *fbdev = ofbi->fbdev;
	struct omap_dss_device *display = fb2display(fbi);
	struct omapfb2_mem_region *rg;
	unsigned long size;
	int r;
	int i;

	r = kstrtoul(buf, 0, &size);
	if (r)
		return r;

	size = PAGE_ALIGN(size);

	if (!lock_fb_info(fbi))
		return -ENODEV;

	if (display && display->driver->sync)
		display->driver->sync(display);

	rg = ofbi->region;

	down_write_nested(&rg->lock, rg->id);
	atomic_inc(&rg->lock_count);

	if (atomic_read(&rg->map_count)) {
		r = -EBUSY;
		goto out;
	}

	for (i = 0; i < fbdev->num_fbs; i++) {
		struct omapfb_info *ofbi2 = FB2OFB(fbdev->fbs[i]);
		int j;

		if (ofbi2->region != rg)
			continue;

		for (j = 0; j < ofbi2->num_overlays; j++) {
			struct omap_overlay *ovl;
			ovl = ofbi2->overlays[j];
			if (ovl->is_enabled(ovl)) {
				r = -EBUSY;
				goto out;
			}
		}
	}

	if (size != ofbi->region->size) {
		r = omapfb_realloc_fbmem(fbi, size, ofbi->region->type);
		if (r) {
			dev_err(dev, "realloc fbmem failed\n");
			goto out;
		}
	}

	r = count;
out:
	atomic_dec(&rg->lock_count);
	up_write(&rg->lock);

	unlock_fb_info(fbi);

	return r;
}

__attribute__((used)) static ssize_t show_phys(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);

	return snprintf(buf, PAGE_SIZE, "%0x\n", ofbi->region->paddr);
}

__attribute__((used)) static ssize_t show_virt(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	struct omapfb_info *ofbi = FB2OFB(fbi);

	return snprintf(buf, PAGE_SIZE, "%p\n", ofbi->region->vaddr);
}

__attribute__((used)) static ssize_t show_upd_mode(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	enum omapfb_update_mode mode;
	int r;

	r = omapfb_get_update_mode(fbi, &mode);

	if (r)
		return r;

	return snprintf(buf, PAGE_SIZE, "%u\n", (unsigned)mode);
}

__attribute__((used)) static ssize_t store_upd_mode(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct fb_info *fbi = dev_get_drvdata(dev);
	unsigned mode;
	int r;

	r = kstrtouint(buf, 0, &mode);
	if (r)
		return r;

	r = omapfb_set_update_mode(fbi, mode);
	if (r)
		return r;

	return count;
}

int omapfb_create_sysfs(struct omapfb2_device *fbdev)
{
	int i;
	int r;

	DBG("create sysfs for fbs\n");
	for (i = 0; i < fbdev->num_fbs; i++) {
		int t;
		for (t = 0; t < ARRAY_SIZE(omapfb_attrs); t++) {
			r = device_create_file(fbdev->fbs[i]->dev,
					&omapfb_attrs[t]);

			if (r) {
				dev_err(fbdev->dev, "failed to create sysfs "
						"file\n");
				return r;
			}
		}
	}

	return 0;
}

void omapfb_remove_sysfs(struct omapfb2_device *fbdev)
{
	int i, t;

	DBG("remove sysfs for fbs\n");
	for (i = 0; i < fbdev->num_fbs; i++) {
		for (t = 0; t < ARRAY_SIZE(omapfb_attrs); t++)
			device_remove_file(fbdev->fbs[i]->dev,
					&omapfb_attrs[t]);
	}
}

