#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  int int64_t ;
struct TYPE_14__ {TYPE_2__* priv_data; } ;
typedef  TYPE_1__ URLContext ;
struct TYPE_17__ {int /*<<< orphan*/  bdplus_handled; scalar_t__ bdplus_detected; int /*<<< orphan*/  libaacs_detected; int /*<<< orphan*/  aacs_handled; scalar_t__ aacs_detected; int /*<<< orphan*/  bluray_detected; } ;
struct TYPE_16__ {int playlist; int duration; } ;
struct TYPE_15__ {int playlist; scalar_t__ angle; int chapter; scalar_t__ bd; } ;
typedef  TYPE_2__ BlurayContext ;
typedef  TYPE_3__ BLURAY_TITLE_INFO ;
typedef  TYPE_4__ BLURAY_DISC_INFO ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
#define  AVSEEK_SIZE 131 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  BLURAY_PROTO_PREFIX ; 
 int /*<<< orphan*/  EFAULT ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  MIN_PLAYLIST_LENGTH ; 
#define  SEEK_CUR 130 
#define  SEEK_END 129 
#define  SEEK_SET 128 
 int /*<<< orphan*/  TITLES_RELEVANT ; 
 int /*<<< orphan*/  av_log (TYPE_1__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  av_strstart (char const*,int /*<<< orphan*/ ,char const**) ; 
 int /*<<< orphan*/  bd_close (scalar_t__) ; 
 int /*<<< orphan*/  bd_free_title_info (TYPE_3__*) ; 
 TYPE_4__* bd_get_disc_info (scalar_t__) ; 
 TYPE_3__* bd_get_title_info (scalar_t__,int,int /*<<< orphan*/ ) ; 
 int bd_get_title_size (scalar_t__) ; 
 int bd_get_titles (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ bd_open (char const*,int /*<<< orphan*/ *) ; 
 int bd_read (scalar_t__,unsigned char*,int) ; 
 int bd_seek (scalar_t__,int) ; 
 int /*<<< orphan*/  bd_seek_chapter (scalar_t__,int) ; 
 int /*<<< orphan*/  bd_select_angle (scalar_t__,scalar_t__) ; 
 scalar_t__ bd_select_playlist (scalar_t__,int) ; 

__attribute__((used)) static int check_disc_info(URLContext *h)
{
    BlurayContext *bd = h->priv_data;
    const BLURAY_DISC_INFO *disc_info;

    disc_info = bd_get_disc_info(bd->bd);
    if (!disc_info) {
        av_log(h, AV_LOG_ERROR, "bd_get_disc_info() failed\n");
        return -1;
    }

    if (!disc_info->bluray_detected) {
        av_log(h, AV_LOG_ERROR, "BluRay disc not detected\n");
        return -1;
    }

    /* AACS */
    if (disc_info->aacs_detected && !disc_info->aacs_handled) {
        if (!disc_info->libaacs_detected) {
            av_log(h, AV_LOG_ERROR,
                   "Media stream encrypted with AACS, install and configure libaacs\n");
        } else {
            av_log(h, AV_LOG_ERROR, "Your libaacs can't decrypt this media\n");
        }
        return -1;
    }

    /* BD+ */
    if (disc_info->bdplus_detected && !disc_info->bdplus_handled) {
        /*
        if (!disc_info->libbdplus_detected) {
            av_log(h, AV_LOG_ERROR,
                   "Media stream encrypted with BD+, install and configure libbdplus");
        } else {
        */
            av_log(h, AV_LOG_ERROR, "Unable to decrypt BD+ encrypted media\n");
        /*}*/
        return -1;
    }

    return 0;
}

__attribute__((used)) static int bluray_close(URLContext *h)
{
    BlurayContext *bd = h->priv_data;
    if (bd->bd) {
        bd_close(bd->bd);
    }

    return 0;
}

__attribute__((used)) static int bluray_open(URLContext *h, const char *path, int flags)
{
    BlurayContext *bd = h->priv_data;
    int num_title_idx;
    const char *diskname = path;

    av_strstart(path, BLURAY_PROTO_PREFIX, &diskname);

    bd->bd = bd_open(diskname, NULL);
    if (!bd->bd) {
        av_log(h, AV_LOG_ERROR, "bd_open() failed\n");
        return AVERROR(EIO);
    }

    /* check if disc can be played */
    if (check_disc_info(h) < 0) {
        return AVERROR(EIO);
    }

    /* setup player registers */
    /* region code has no effect without menus
    if (bd->region > 0 && bd->region < 5) {
        av_log(h, AV_LOG_INFO, "setting region code to %d (%c)\n", bd->region, 'A' + (bd->region - 1));
        bd_set_player_setting(bd->bd, BLURAY_PLAYER_SETTING_REGION_CODE, bd->region);
    }
    */

    /* load title list */
    num_title_idx = bd_get_titles(bd->bd, TITLES_RELEVANT, MIN_PLAYLIST_LENGTH);
    av_log(h, AV_LOG_INFO, "%d usable playlists:\n", num_title_idx);
    if (num_title_idx < 1) {
        return AVERROR(EIO);
    }

    /* if playlist was not given, select longest playlist */
    if (bd->playlist < 0) {
        uint64_t duration = 0;
        int i;
        for (i = 0; i < num_title_idx; i++) {
            BLURAY_TITLE_INFO *info = bd_get_title_info(bd->bd, i, 0);

            av_log(h, AV_LOG_INFO, "playlist %05d.mpls (%d:%02d:%02d)\n",
                   info->playlist,
                   ((int)(info->duration / 90000) / 3600),
                   ((int)(info->duration / 90000) % 3600) / 60,
                   ((int)(info->duration / 90000) % 60));

            if (info->duration > duration) {
                bd->playlist = info->playlist;
                duration = info->duration;
            }

            bd_free_title_info(info);
        }
        av_log(h, AV_LOG_INFO, "selected %05d.mpls\n", bd->playlist);
    }

    /* select playlist */
    if (bd_select_playlist(bd->bd, bd->playlist) <= 0) {
        av_log(h, AV_LOG_ERROR, "bd_select_playlist(%05d.mpls) failed\n", bd->playlist);
        return AVERROR(EIO);
    }

    /* select angle */
    if (bd->angle >= 0) {
        bd_select_angle(bd->bd, bd->angle);
    }

    /* select chapter */
    if (bd->chapter > 1) {
        bd_seek_chapter(bd->bd, bd->chapter - 1);
    }

    return 0;
}

__attribute__((used)) static int bluray_read(URLContext *h, unsigned char *buf, int size)
{
    BlurayContext *bd = h->priv_data;
    int len;

    if (!bd || !bd->bd) {
        return AVERROR(EFAULT);
    }

    len = bd_read(bd->bd, buf, size);

    return len == 0 ? AVERROR_EOF : len;
}

__attribute__((used)) static int64_t bluray_seek(URLContext *h, int64_t pos, int whence)
{
    BlurayContext *bd = h->priv_data;

    if (!bd || !bd->bd) {
        return AVERROR(EFAULT);
    }

    switch (whence) {
    case SEEK_SET:
    case SEEK_CUR:
    case SEEK_END:
        return bd_seek(bd->bd, pos);

    case AVSEEK_SIZE:
        return bd_get_title_size(bd->bd);
    }

    av_log(h, AV_LOG_ERROR, "Unsupported whence operation %d\n", whence);
    return AVERROR(EINVAL);
}

