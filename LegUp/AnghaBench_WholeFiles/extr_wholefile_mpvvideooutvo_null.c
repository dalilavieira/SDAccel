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
typedef  int uint32_t ;
struct vo {struct priv* priv; } ;
struct priv {int cfg_fps; } ;
struct mp_image_params {int dummy; } ;
typedef  int /*<<< orphan*/  mp_image_t ;
typedef  int int64_t ;

/* Variables and functions */
#define  VOCTRL_GET_DISPLAY_FPS 128 
 int VO_NOTIMPL ; 
 int VO_TRUE ; 
 int /*<<< orphan*/  mp_sleep_us (int) ; 
 int mp_time_us () ; 
 int /*<<< orphan*/  talloc_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void draw_image(struct vo *vo, mp_image_t *mpi)
{
    talloc_free(mpi);
}

__attribute__((used)) static void flip_page(struct vo *vo)
{
    struct priv *p = vo->priv;
    if (p->cfg_fps) {
        int64_t ft = 1e6 / p->cfg_fps;
        int64_t prev_vsync = mp_time_us() / ft;
        int64_t target_time = (prev_vsync + 1) * ft;
        for (;;) {
            int64_t now = mp_time_us();
            if (now >= target_time)
                break;
            mp_sleep_us(target_time - now);
        }
    }
}

__attribute__((used)) static int query_format(struct vo *vo, int format)
{
    return 1;
}

__attribute__((used)) static int reconfig(struct vo *vo, struct mp_image_params *params)
{
    return 0;
}

__attribute__((used)) static void uninit(struct vo *vo)
{
}

__attribute__((used)) static int preinit(struct vo *vo)
{
    return 0;
}

__attribute__((used)) static int control(struct vo *vo, uint32_t request, void *data)
{
    struct priv *p = vo->priv;
    switch (request) {
    case VOCTRL_GET_DISPLAY_FPS:
        if (!p->cfg_fps)
            break;
        *(double *)data = p->cfg_fps;
        return VO_TRUE;
    }
    return VO_NOTIMPL;
}

