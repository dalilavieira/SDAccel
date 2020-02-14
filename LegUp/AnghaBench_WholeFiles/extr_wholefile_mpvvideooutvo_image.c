#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_5__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct vo {int /*<<< orphan*/  global; struct priv* priv; int /*<<< orphan*/  log; int /*<<< orphan*/  osd; int /*<<< orphan*/  params; } ;
struct stat {int /*<<< orphan*/  st_mode; } ;
struct priv {TYPE_5__* opts; TYPE_1__* current; int /*<<< orphan*/  frame; } ;
struct mp_osd_res {int dummy; } ;
struct mp_image_params {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  pts; } ;
typedef  TYPE_1__ mp_image_t ;
struct TYPE_8__ {char* outdir; int /*<<< orphan*/  opts; } ;

/* Variables and functions */
 scalar_t__ EEXIST ; 
 int /*<<< orphan*/  MP_ERR (struct vo*,char*,char*) ; 
 int /*<<< orphan*/  MP_INFO (struct vo*,char*,char const*) ; 
 int /*<<< orphan*/  OSD_DRAW_SUB_ONLY ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 int VO_NOTIMPL ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  image_writer_file_ext (int /*<<< orphan*/ ) ; 
 scalar_t__ mkdir (char const*,int) ; 
 TYPE_5__* mp_get_config_group (struct vo*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_image_unrefp (TYPE_1__**) ; 
 char* mp_path_join (void*,char*,char*) ; 
 char* mp_strerror (scalar_t__) ; 
 scalar_t__ mp_sws_supported_format (int) ; 
 int /*<<< orphan*/  osd_draw_on_image (int /*<<< orphan*/ ,struct mp_osd_res,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 struct mp_osd_res osd_res_from_image_params (int /*<<< orphan*/ ) ; 
 scalar_t__ stat (char const*,struct stat*) ; 
 scalar_t__ strlen (char*) ; 
 char* talloc_asprintf (void*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  talloc_free (void*) ; 
 void* talloc_new (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vo_image_conf ; 
 int /*<<< orphan*/  write_image (TYPE_1__*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool checked_mkdir(struct vo *vo, const char *buf)
{
    MP_INFO(vo, "Creating output directory '%s'...\n", buf);
    if (mkdir(buf, 0755) < 0) {
        char *errstr = mp_strerror(errno);
        if (errno == EEXIST) {
            struct stat stat_p;
            if (stat(buf, &stat_p ) == 0 && S_ISDIR(stat_p.st_mode))
                return true;
        }
        MP_ERR(vo, "Error creating output directory: %s\n", errstr);
        return false;
    }
    return true;
}

__attribute__((used)) static int reconfig(struct vo *vo, struct mp_image_params *params)
{
    struct priv *p = vo->priv;
    mp_image_unrefp(&p->current);

    return 0;
}

__attribute__((used)) static void draw_image(struct vo *vo, mp_image_t *mpi)
{
    struct priv *p = vo->priv;

    p->current = mpi;

    struct mp_osd_res dim = osd_res_from_image_params(vo->params);
    osd_draw_on_image(vo->osd, dim, mpi->pts, OSD_DRAW_SUB_ONLY, p->current);
}

__attribute__((used)) static void flip_page(struct vo *vo)
{
    struct priv *p = vo->priv;
    if (!p->current)
        return;

    (p->frame)++;

    void *t = talloc_new(NULL);
    char *filename = talloc_asprintf(t, "%08d.%s", p->frame,
                                     image_writer_file_ext(p->opts->opts));

    if (p->opts->outdir && strlen(p->opts->outdir))
        filename = mp_path_join(t, p->opts->outdir, filename);

    MP_INFO(vo, "Saving %s\n", filename);
    write_image(p->current, p->opts->opts, filename, vo->log);

    talloc_free(t);
    mp_image_unrefp(&p->current);
}

__attribute__((used)) static int query_format(struct vo *vo, int fmt)
{
    if (mp_sws_supported_format(fmt))
        return 1;
    return 0;
}

__attribute__((used)) static void uninit(struct vo *vo)
{
    struct priv *p = vo->priv;

    mp_image_unrefp(&p->current);
}

__attribute__((used)) static int preinit(struct vo *vo)
{
    struct priv *p = vo->priv;
    p->opts = mp_get_config_group(vo, vo->global, &vo_image_conf);
    if (p->opts->outdir && !checked_mkdir(vo, p->opts->outdir))
        return -1;
    return 0;
}

__attribute__((used)) static int control(struct vo *vo, uint32_t request, void *data)
{
    return VO_NOTIMPL;
}

