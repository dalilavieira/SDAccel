#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct rgb_pixfmt_map_entry {scalar_t__ bits_per_pixel; scalar_t__ red_offset; scalar_t__ green_offset; scalar_t__ blue_offset; int pixfmt; } ;
struct TYPE_13__ {scalar_t__ offset; } ;
struct TYPE_12__ {scalar_t__ offset; } ;
struct TYPE_11__ {scalar_t__ offset; } ;
struct fb_var_screeninfo {scalar_t__ bits_per_pixel; char* id; TYPE_3__ blue; TYPE_2__ green; TYPE_1__ red; } ;
struct fb_fix_screeninfo {scalar_t__ bits_per_pixel; char* id; TYPE_3__ blue; TYPE_2__ green; TYPE_1__ red; } ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;
typedef  int /*<<< orphan*/  device_file ;
struct TYPE_15__ {struct TYPE_15__* device_description; struct TYPE_15__* device_name; } ;
struct TYPE_14__ {scalar_t__ nb_devices; scalar_t__ default_device; int /*<<< orphan*/  devices; } ;
typedef  TYPE_4__ AVDeviceInfoList ;
typedef  TYPE_5__ AVDeviceInfo ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int AV_PIX_FMT_NONE ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOENT ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  FBIOGET_FSCREENINFO ; 
 int /*<<< orphan*/  FBIOGET_VSCREENINFO ; 
 int FF_ARRAY_ELEMS (struct rgb_pixfmt_map_entry*) ; 
 int /*<<< orphan*/  O_RDWR ; 
 int av_dynarray_add_nofree (int /*<<< orphan*/ *,scalar_t__*,TYPE_5__*) ; 
 int /*<<< orphan*/  av_err2str (int) ; 
 int /*<<< orphan*/  av_freep (TYPE_5__**) ; 
 int /*<<< orphan*/  av_log (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,char*,int /*<<< orphan*/ ) ; 
 TYPE_5__* av_mallocz (int) ; 
 void* av_strdup (char*) ; 
 int avpriv_open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  errno ; 
 char* getenv (char*) ; 
 int ioctl (int,int /*<<< orphan*/ ,struct fb_var_screeninfo*) ; 
 struct rgb_pixfmt_map_entry* rgb_pixfmt_map ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 int /*<<< orphan*/  strcmp (TYPE_5__*,char const*) ; 

enum AVPixelFormat ff_get_pixfmt_from_fb_varinfo(struct fb_var_screeninfo *varinfo)
{
    int i;

    for (i = 0; i < FF_ARRAY_ELEMS(rgb_pixfmt_map); i++) {
        const struct rgb_pixfmt_map_entry *entry = &rgb_pixfmt_map[i];
        if (entry->bits_per_pixel == varinfo->bits_per_pixel &&
            entry->red_offset     == varinfo->red.offset     &&
            entry->green_offset   == varinfo->green.offset   &&
            entry->blue_offset    == varinfo->blue.offset)
            return entry->pixfmt;
    }

    return AV_PIX_FMT_NONE;
}

const char* ff_fbdev_default_device()
{
    const char *dev = getenv("FRAMEBUFFER");
    if (!dev)
        dev = "/dev/fb0";
    return dev;
}

int ff_fbdev_get_device_list(AVDeviceInfoList *device_list)
{
    struct fb_var_screeninfo varinfo;
    struct fb_fix_screeninfo fixinfo;
    char device_file[12];
    AVDeviceInfo *device = NULL;
    int i, fd, ret = 0;
    const char *default_device = ff_fbdev_default_device();

    if (!device_list)
        return AVERROR(EINVAL);

    for (i = 0; i <= 31; i++) {
        snprintf(device_file, sizeof(device_file), "/dev/fb%d", i);

        if ((fd = avpriv_open(device_file, O_RDWR)) < 0) {
            int err = AVERROR(errno);
            if (err != AVERROR(ENOENT))
                av_log(NULL, AV_LOG_ERROR, "Could not open framebuffer device '%s': %s\n",
                       device_file, av_err2str(err));
            continue;
        }
        if (ioctl(fd, FBIOGET_VSCREENINFO, &varinfo) == -1)
            goto fail_device;
        if (ioctl(fd, FBIOGET_FSCREENINFO, &fixinfo) == -1)
            goto fail_device;

        device = av_mallocz(sizeof(AVDeviceInfo));
        if (!device) {
            ret = AVERROR(ENOMEM);
            goto fail_device;
        }
        device->device_name = av_strdup(device_file);
        device->device_description = av_strdup(fixinfo.id);
        if (!device->device_name || !device->device_description) {
            ret = AVERROR(ENOMEM);
            goto fail_device;
        }

        if ((ret = av_dynarray_add_nofree(&device_list->devices,
                                          &device_list->nb_devices, device)) < 0)
            goto fail_device;

        if (default_device && !strcmp(device->device_name, default_device)) {
            device_list->default_device = device_list->nb_devices - 1;
            default_device = NULL;
        }
        close(fd);
        continue;

      fail_device:
        if (device) {
            av_freep(&device->device_name);
            av_freep(&device->device_description);
            av_freep(&device);
        }
        if (fd >= 0)
            close(fd);
        if (ret < 0)
            return ret;
    }
    return 0;
}

