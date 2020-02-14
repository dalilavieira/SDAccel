#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct vo {struct priv* priv; int /*<<< orphan*/  input_ctx; } ;
struct priv {int image_width; int image_height; char* dither_antialias; char* dither_charset; char* dither_color; char* dither_algo; int /*<<< orphan*/ * display; int /*<<< orphan*/ * canvas; TYPE_4__* dither_buffer; int /*<<< orphan*/ * dither; int /*<<< orphan*/  screen_h; int /*<<< orphan*/  screen_w; int /*<<< orphan*/  image_format; } ;
struct mp_image_params {int h; int w; int /*<<< orphan*/  imgfmt; } ;
struct TYPE_15__ {int /*<<< orphan*/ * stride; int /*<<< orphan*/ * planes; } ;
typedef  TYPE_4__ mp_image_t ;
struct TYPE_13__ {int ch; } ;
struct TYPE_12__ {scalar_t__ button; int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_14__ {TYPE_2__ key; TYPE_1__ mouse; } ;
struct TYPE_16__ {int type; TYPE_3__ data; } ;
typedef  TYPE_5__ caca_event_t ;

/* Variables and functions */
 int /*<<< orphan*/  CACA_EVENT_ANY ; 
#define  CACA_EVENT_KEY_PRESS 134 
#define  CACA_EVENT_MOUSE_MOTION 133 
#define  CACA_EVENT_MOUSE_PRESS 132 
#define  CACA_EVENT_MOUSE_RELEASE 131 
#define  CACA_EVENT_QUIT 130 
#define  CACA_EVENT_RESIZE 129 
 int ENOSYS ; 
 int IMGFMT_BGR24 ; 
 int /*<<< orphan*/  MP_ERR (struct vo*,char*) ; 
 int /*<<< orphan*/  MP_FATAL (struct vo*,char*) ; 
 int MP_KEY_CLOSE_WIN ; 
 int MP_KEY_STATE_DOWN ; 
 int MP_KEY_STATE_UP ; 
 scalar_t__ MP_MBTN_BASE ; 
#define  VOCTRL_CHECK_EVENTS 128 
 int VO_NOTIMPL ; 
 int VO_TRUE ; 
 int /*<<< orphan*/  amask ; 
 int /*<<< orphan*/  bmask ; 
 int /*<<< orphan*/  bpp ; 
 int /*<<< orphan*/ * caca_create_canvas (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * caca_create_display (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * caca_create_dither (int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  caca_dither_bitmap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  caca_free_canvas (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  caca_free_display (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  caca_free_dither (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  caca_get_canvas_height (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  caca_get_canvas_width (int /*<<< orphan*/ *) ; 
 char** caca_get_dither_algorithm_list (int /*<<< orphan*/ *) ; 
 char** caca_get_dither_antialias_list (int /*<<< orphan*/ *) ; 
 char** caca_get_dither_charset_list (int /*<<< orphan*/ *) ; 
 char** caca_get_dither_color_list (int /*<<< orphan*/ *) ; 
 scalar_t__ caca_get_event (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  caca_refresh_display (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  caca_set_display_title (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  caca_set_dither_algorithm (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  caca_set_dither_antialias (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  caca_set_dither_charset (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  caca_set_dither_color (int /*<<< orphan*/ *,char*) ; 
 int depth ; 
 int /*<<< orphan*/  gmask ; 
 int /*<<< orphan*/  keysym_map ; 
 int lookup_keymap_table (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy_pic (TYPE_4__*,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_input_put_key (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mp_input_set_mouse_pos (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rmask ; 
 scalar_t__ strcmp (char const* const,char const*) ; 
 TYPE_4__* talloc_array (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  talloc_free (TYPE_4__*) ; 
 int /*<<< orphan*/  uint8_t ; 

__attribute__((used)) static int resize(struct vo *vo)
{
    struct priv *priv = vo->priv;
    priv->screen_w = caca_get_canvas_width(priv->canvas);
    priv->screen_h = caca_get_canvas_height(priv->canvas);

    caca_free_dither(priv->dither);
    talloc_free(priv->dither_buffer);

    priv->dither = caca_create_dither(bpp, priv->image_width, priv->image_height,
                                depth * priv->image_width,
                                rmask, gmask, bmask, amask);
    if (priv->dither == NULL) {
        MP_FATAL(vo, "caca_create_dither failed!\n");
        return -1;
    }
    priv->dither_buffer =
        talloc_array(NULL, uint8_t, depth * priv->image_width * priv->image_height);

    /* Default libcaca features */
    caca_set_dither_antialias(priv->dither, priv->dither_antialias);
    caca_set_dither_charset(priv->dither, priv->dither_charset);
    caca_set_dither_color(priv->dither, priv->dither_color);
    caca_set_dither_algorithm(priv->dither, priv->dither_algo);

    return 0;
}

__attribute__((used)) static int reconfig(struct vo *vo, struct mp_image_params *params)
{
    struct priv *priv = vo->priv;
    priv->image_height = params->h;
    priv->image_width  = params->w;
    priv->image_format = params->imgfmt;

    return resize(vo);
}

__attribute__((used)) static void draw_image(struct vo *vo, mp_image_t *mpi)
{
    struct priv *priv = vo->priv;
    memcpy_pic(priv->dither_buffer, mpi->planes[0], priv->image_width * depth, priv->image_height,
               priv->image_width * depth, mpi->stride[0]);
    caca_dither_bitmap(priv->canvas, 0, 0, priv->screen_w, priv->screen_h, priv->dither, priv->dither_buffer);
    talloc_free(mpi);
}

__attribute__((used)) static void flip_page(struct vo *vo)
{
    struct priv *priv = vo->priv;
    caca_refresh_display(priv->display);
}

__attribute__((used)) static void set_next_str(const char * const *list, const char **str,
                         const char **msg)
{
    int ind;
    for (ind = 0; list[ind]; ind += 2) {
        if (strcmp(list[ind], *str) == 0) {
            if (list[ind + 2] == NULL)
                ind = -2;
            *str = list[ind + 2];
            *msg = list[ind + 3];
            return;
        }
    }

    *str = list[0];
    *msg = list[1];
}

__attribute__((used)) static void check_events(struct vo *vo)
{
    struct priv *priv = vo->priv;

    caca_event_t cev;
    while (caca_get_event(priv->display, CACA_EVENT_ANY, &cev, 0)) {

        switch (cev.type) {
        case CACA_EVENT_RESIZE:
            caca_refresh_display(priv->display);
            resize(vo);
            break;
        case CACA_EVENT_QUIT:
            mp_input_put_key(vo->input_ctx, MP_KEY_CLOSE_WIN);
            break;
        case CACA_EVENT_MOUSE_MOTION:
            mp_input_set_mouse_pos(vo->input_ctx, cev.data.mouse.x, cev.data.mouse.y);
            break;
        case CACA_EVENT_MOUSE_PRESS:
            mp_input_put_key(vo->input_ctx,
                    (MP_MBTN_BASE + cev.data.mouse.button - 1) | MP_KEY_STATE_DOWN);
            break;
        case CACA_EVENT_MOUSE_RELEASE:
            mp_input_put_key(vo->input_ctx,
                    (MP_MBTN_BASE + cev.data.mouse.button - 1) | MP_KEY_STATE_UP);
            break;
        case CACA_EVENT_KEY_PRESS:
        {
            int key = cev.data.key.ch;
            int mpkey = lookup_keymap_table(keysym_map, key);
            const char *msg_name;

            if (mpkey)
                mp_input_put_key(vo->input_ctx, mpkey);
            else
            switch (key) {
            case 'd':
            case 'D':
                /* Toggle dithering algorithm */
                set_next_str(caca_get_dither_algorithm_list(priv->dither),
                             &priv->dither_algo, &msg_name);
                caca_set_dither_algorithm(priv->dither, priv->dither_algo);
                break;

            case 'a':
            case 'A':
                /* Toggle antialiasing method */
                set_next_str(caca_get_dither_antialias_list(priv->dither),
                             &priv->dither_antialias, &msg_name);
                caca_set_dither_antialias(priv->dither, priv->dither_antialias);
                break;

            case 'h':
            case 'H':
                /* Toggle charset method */
                set_next_str(caca_get_dither_charset_list(priv->dither),
                             &priv->dither_charset, &msg_name);
                caca_set_dither_charset(priv->dither, priv->dither_charset);
                break;

            case 'c':
            case 'C':
                /* Toggle color method */
                set_next_str(caca_get_dither_color_list(priv->dither),
                             &priv->dither_color, &msg_name);
                caca_set_dither_color(priv->dither, priv->dither_color);
                break;

            default:
                if (key <= 255)
                    mp_input_put_key(vo->input_ctx, key);
                break;
            }
        }
        }
    }
}

__attribute__((used)) static void uninit(struct vo *vo)
{
    struct priv *priv = vo->priv;
    caca_free_dither(priv->dither);
    priv->dither = NULL;
    talloc_free(priv->dither_buffer);
    priv->dither_buffer = NULL;
    caca_free_display(priv->display);
    caca_free_canvas(priv->canvas);
}

__attribute__((used)) static int preinit(struct vo *vo)
{
    struct priv *priv = vo->priv;

    priv->dither_antialias = "default";
    priv->dither_charset   = "default";
    priv->dither_color     = "default";
    priv->dither_algo      = "none";

    priv->canvas = caca_create_canvas(0, 0);
    if (priv->canvas == NULL) {
        MP_ERR(vo, "failed to create canvas\n");
        return ENOSYS;
    }

    priv->display = caca_create_display(priv->canvas);

    if (priv->display == NULL) {
        MP_ERR(vo, "failed to create display\n");
        caca_free_canvas(priv->canvas);
        return ENOSYS;
    }

    caca_set_display_title(priv->display, "mpv");

    return 0;
}

__attribute__((used)) static int query_format(struct vo *vo, int format)
{
    return format == IMGFMT_BGR24;
}

__attribute__((used)) static int control(struct vo *vo, uint32_t request, void *data)
{
    switch (request) {
    case VOCTRL_CHECK_EVENTS:
        check_events(vo);
        return VO_TRUE;
    }
    return VO_NOTIMPL;
}

