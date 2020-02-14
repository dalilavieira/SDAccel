#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_51__   TYPE_7__ ;
typedef  struct TYPE_50__   TYPE_6__ ;
typedef  struct TYPE_49__   TYPE_5__ ;
typedef  struct TYPE_48__   TYPE_4__ ;
typedef  struct TYPE_47__   TYPE_3__ ;
typedef  struct TYPE_46__   TYPE_35__ ;
typedef  struct TYPE_45__   TYPE_2__ ;
typedef  struct TYPE_44__   TYPE_1__ ;

/* Type definitions */
struct TYPE_47__ {int x; scalar_t__ y; } ;
struct TYPE_44__ {void* display; unsigned long xwin; int height; int width; TYPE_2__* state; TYPE_3__ scaled_offset; } ;
typedef  TYPE_1__ zbar_window_t ;
struct TYPE_45__ {unsigned long* colors; unsigned long* logo_colors; int logo_scale; void* gc; TYPE_6__* logo_z; int /*<<< orphan*/ * logo_zbars; int /*<<< orphan*/ * exposed; TYPE_5__* logo_bars; TYPE_35__* font; } ;
typedef  TYPE_2__ window_state_t ;
typedef  size_t uint32_t ;
typedef  TYPE_3__ point_t ;
typedef  int /*<<< orphan*/  black ;
struct TYPE_48__ {int width; int height; } ;
typedef  TYPE_4__ XWindowAttributes ;
struct TYPE_49__ {int x; int y; int width; int height; } ;
typedef  TYPE_5__ XRectangle ;
struct TYPE_50__ {int x; int y; } ;
typedef  TYPE_6__ XPoint ;
struct TYPE_51__ {unsigned short red; unsigned short green; unsigned short blue; unsigned long pixel; scalar_t__ flags; } ;
typedef  TYPE_7__ XColor ;
struct TYPE_46__ {int ascent; int descent; int /*<<< orphan*/  fid; } ;
typedef  unsigned long Pixmap ;
typedef  void* GC ;
typedef  int /*<<< orphan*/  Cursor ;
typedef  int /*<<< orphan*/  Colormap ;

/* Variables and functions */
 unsigned long BlackPixel (void*,int) ; 
 int /*<<< orphan*/  CapButt ; 
 int /*<<< orphan*/  CapRound ; 
 int /*<<< orphan*/  CoordModeOrigin ; 
 int /*<<< orphan*/  DefaultColormap (void*,int) ; 
 int DefaultScreen (void*) ; 
 int /*<<< orphan*/  JoinMiter ; 
 int /*<<< orphan*/  JoinRound ; 
 int /*<<< orphan*/  LineSolid ; 
 int /*<<< orphan*/  None ; 
 unsigned long WhitePixel (void*,int) ; 
 int /*<<< orphan*/  XAllocColor (void*,int /*<<< orphan*/ ,TYPE_7__*) ; 
 void* XCreateGC (void*,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 unsigned long XCreatePixmap (void*,unsigned long,int,int,int) ; 
 int /*<<< orphan*/  XCreatePixmapCursor (void*,unsigned long,unsigned long,TYPE_7__*,TYPE_7__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* XCreateRegion () ; 
 int /*<<< orphan*/  XDefineCursor (void*,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XDestroyRegion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  XDrawLine (void*,unsigned long,void*,int,scalar_t__,int,scalar_t__) ; 
 int /*<<< orphan*/  XDrawLines (void*,unsigned long,void*,TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XDrawPoint (void*,unsigned long,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XDrawRectangle (void*,unsigned long,void*,int,scalar_t__,int,int) ; 
 int /*<<< orphan*/  XDrawString (void*,unsigned long,void*,int,int,char const*,int) ; 
 int /*<<< orphan*/  XFillRectangle (void*,unsigned long,void*,int,int,int,int) ; 
 int /*<<< orphan*/  XFillRectangles (void*,unsigned long,void*,TYPE_5__*,int) ; 
 int /*<<< orphan*/  XFlush (void*) ; 
 int /*<<< orphan*/  XFreeCursor (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XFreeFont (void*,TYPE_35__*) ; 
 int /*<<< orphan*/  XFreeGC (void*,void*) ; 
 int /*<<< orphan*/  XFreePixmap (void*,unsigned long) ; 
 int /*<<< orphan*/  XGetWindowAttributes (void*,unsigned long,TYPE_4__*) ; 
 int /*<<< orphan*/  XIntersectRegion (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_35__* XLoadQueryFont (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XSetClipMask (void*,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XSetFont (void*,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XSetForeground (void*,void*,unsigned long) ; 
 int /*<<< orphan*/  XSetLineAttributes (void*,void*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XSetRegion (void*,void*,int /*<<< orphan*/ *) ; 
 int XTextWidth (TYPE_35__*,char const*,int) ; 
 int /*<<< orphan*/  XUnionRectWithRegion (TYPE_5__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZBAR_OVERLAY_FONT ; 
 int _zbar_window_probe_ximage (TYPE_1__*) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_2__* calloc (int,int) ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 scalar_t__ isprint (char const) ; 
 int /*<<< orphan*/  memset (TYPE_7__*,int /*<<< orphan*/ ,int) ; 
 TYPE_3__ window_scale_pt (TYPE_1__*,TYPE_3__ const) ; 
 int /*<<< orphan*/  zprintf (int,char*) ; 

__attribute__((used)) static inline unsigned long window_alloc_color (zbar_window_t *w,
                                                Colormap cmap,
                                                unsigned short r,
                                                unsigned short g,
                                                unsigned short b)
{
    XColor color;
    color.red = r;
    color.green = g;
    color.blue = b;
    color.flags = 0;
    XAllocColor(w->display, cmap, &color);
    return(color.pixel);
}

__attribute__((used)) static inline int window_alloc_colors (zbar_window_t *w)
{
    window_state_t *x = w->state;
    Colormap cmap = DefaultColormap(w->display, DefaultScreen(w->display));
    int i;
    for(i = 0; i < 8; i++)
        x->colors[i] = window_alloc_color(w, cmap,
                                          (i & 4) ? (0xcc * 0x101) : 0,
                                          (i & 2) ? (0xcc * 0x101) : 0,
                                          (i & 1) ? (0xcc * 0x101) : 0);

    x->logo_colors[0] = window_alloc_color(w, cmap, 0xd709, 0x3333, 0x3333);
    x->logo_colors[1] = window_alloc_color(w, cmap, 0xa3d6, 0x0000, 0x0000);
    return(0);
}

__attribute__((used)) static inline int window_hide_cursor (zbar_window_t *w)
{
    /* FIXME this seems lame...there must be a better way */
    Pixmap empty = XCreatePixmap(w->display, w->xwin, 1, 1, 1);
    GC gc = XCreateGC(w->display, empty, 0, NULL);
    XDrawPoint(w->display, empty, gc, 0, 0);
    XColor black;
    memset(&black, 0, sizeof(black));
    int screen = DefaultScreen(w->display);
    black.pixel = BlackPixel(w->display, screen);
    Cursor cursor =
        XCreatePixmapCursor(w->display, empty, empty, &black, &black, 0, 0);
    XDefineCursor(w->display, w->xwin, cursor);
    XFreeCursor(w->display, cursor);
    XFreeGC(w->display, gc);
    XFreePixmap(w->display, empty);
    return(0);
}

int _zbar_window_resize (zbar_window_t *w)
{
    window_state_t *x = w->state;
    if(!x)
        return(0);

    int lbw;
    if(w->height * 8 / 10 <= w->width)
        lbw = w->height / 36;
    else
        lbw = w->width * 5 / 144;
    if(lbw < 1)
        lbw = 1;
    x->logo_scale = lbw;
    if(x->logo_zbars)
        XDestroyRegion(x->logo_zbars);
    x->logo_zbars = XCreateRegion();

    int x0 = w->width / 2;
    int y0 = w->height / 2;
    int by0 = y0 - 54 * lbw / 5;
    int bh = 108 * lbw / 5;

    static const int bx[5] = { -6, -3, -1,  2,  5 };
    static const int bw[5] = {  1,  1,  2,  2,  1 };

    int i;
    for(i = 0; i < 5; i++) {
        XRectangle *bar = &x->logo_bars[i];
        bar->x = x0 + lbw * bx[i];
        bar->y = by0;
        bar->width = lbw * bw[i];
        bar->height = bh;
        XUnionRectWithRegion(bar, x->logo_zbars, x->logo_zbars);
    }

    static const int zx[4] = { -7,  7, -7,  7 };
    static const int zy[4] = { -8, -8,  8,  8 };

    for(i = 0; i < 4; i++) {
        x->logo_z[i].x = x0 + lbw * zx[i];
        x->logo_z[i].y = y0 + lbw * zy[i];
    }
    return(0);
}

int _zbar_window_attach (zbar_window_t *w,
                         void *display,
                         unsigned long win)
{
    window_state_t *x = w->state;
    if(w->display) {
        /* cleanup existing resources */
        if(x->gc)
            XFreeGC(w->display, x->gc);
        assert(!x->exposed);
        if(x->font) {
            XFreeFont(w->display, x->font);
            x->font = NULL;
        }
        if(x->logo_zbars) {
            XDestroyRegion(x->logo_zbars);
            x->logo_zbars = NULL;
        }
        if(x->exposed) {
            XDestroyRegion(x->exposed);
            x->exposed = NULL;
        }
        w->display = NULL;
    }
    w->xwin = 0;

    if(!display || !win) {
        if(x) {
            free(x);
            w->state = NULL;
        }
        return(0);
    }

    if(!x)
        x = w->state = calloc(1, sizeof(window_state_t));

    w->display = display;
    w->xwin = win;
    x->gc = XCreateGC(display, win, 0, NULL);

    XWindowAttributes attr;
    XGetWindowAttributes(w->display, w->xwin, &attr);
    w->width = attr.width;
    w->height = attr.height;
    _zbar_window_resize(w);

    window_alloc_colors(w);
    window_hide_cursor(w);

    /* load overlay font */
    x->font = XLoadQueryFont(w->display, ZBAR_OVERLAY_FONT);
    if(x->font)
        XSetFont(w->display, x->gc, x->font->fid);

    /* FIXME add interface preference override */
#ifdef HAVE_X11_EXTENSIONS_XVLIB_H
    if(!_zbar_window_probe_xv(w))
        return(0);
#endif

    zprintf(1, "falling back to XImage\n");
    return(_zbar_window_probe_ximage(w));
}

int _zbar_window_expose (zbar_window_t *w,
                         int x,
                         int y,
                         int width,
                         int height)
{
    window_state_t *xs = w->state;
    if(!xs->exposed)
        xs->exposed = XCreateRegion();
    XRectangle r;
    r.x = x;
    r.y = y;
    r.width = width;
    r.height = height;
    XUnionRectWithRegion(&r, xs->exposed, xs->exposed);
    return(0);
}

int _zbar_window_begin (zbar_window_t *w)
{
    window_state_t *xs = w->state;
    if(xs->exposed)
        XSetRegion(w->display, xs->gc, xs->exposed);

    return(0);
}

int _zbar_window_end (zbar_window_t *w)
{
    window_state_t *x = w->state;
    XSetClipMask(w->display, x->gc, None);
    if(x->exposed) {
        XDestroyRegion(x->exposed);
        x->exposed = NULL;
    }
    XFlush(w->display);
    return(0);
}

int _zbar_window_clear (zbar_window_t *w)
{
    if(!w->display)
        return(0);
    window_state_t *x = w->state;
    int screen = DefaultScreen(w->display);
    XSetForeground(w->display, x->gc, WhitePixel(w->display, screen));
    XFillRectangle(w->display, w->xwin, x->gc, 0, 0, w->width, w->height);
    return(0);
}

int _zbar_window_draw_polygon (zbar_window_t *w,
                               uint32_t rgb,
                               const point_t *pts,
                               int npts)
{
    window_state_t *xs = w->state;
    XSetForeground(w->display, xs->gc, xs->colors[rgb]);

    point_t org = w->scaled_offset;
    XPoint xpts[npts + 1];
    int i;
    for(i = 0; i < npts; i++) {
        point_t p = window_scale_pt(w, pts[i]);
        xpts[i].x = p.x + org.x;
        xpts[i].y = p.y + org.y;
    }
    xpts[npts] = xpts[0];

    XDrawLines(w->display, w->xwin, xs->gc, xpts, npts + 1, CoordModeOrigin);

    return(0);
}

int _zbar_window_draw_marker (zbar_window_t *w,
                              uint32_t rgb,
                              point_t p)
{
    window_state_t *xs = w->state;
    XSetForeground(w->display, xs->gc, xs->colors[rgb]);
    XDrawRectangle(w->display, w->xwin, xs->gc, p.x - 2, p.y - 2, 4, 4);
    XDrawLine(w->display, w->xwin, xs->gc, p.x, p.y - 3, p.x, p.y + 3);
    XDrawLine(w->display, w->xwin, xs->gc, p.x - 3, p.y, p.x + 3, p.y);
    return(0);
}

int _zbar_window_draw_text (zbar_window_t *w,
                            uint32_t rgb,
                            point_t p,
                            const char *text)
{
    window_state_t *xs = w->state;
    if(!xs->font)
        return(-1);

    XSetForeground(w->display, xs->gc, xs->colors[rgb]);

    int n = 0;
    while(n < 32 && text[n] && isprint(text[n]))
        n++;

    int width = XTextWidth(xs->font, text, n);
    if(p.x >= 0)
        p.x -= width / 2;
    else
        p.x += w->width - width;

    int dy = xs->font->ascent + xs->font->descent;
    if(p.y >= 0)
        p.y -= dy / 2;
    else
        p.y = w->height + p.y * dy * 5 / 4;

    XDrawString(w->display, w->xwin, xs->gc, p.x, p.y, text, n);
    return(0);
}

int _zbar_window_fill_rect (zbar_window_t *w,
                            uint32_t rgb,
                            point_t org,
                            point_t size)
{
    window_state_t *xs = w->state;
    XSetForeground(w->display, xs->gc, xs->colors[rgb]);
    XFillRectangle(w->display, w->xwin, xs->gc, org.x, org.y, size.x, size.y);
    return(0);
}

int _zbar_window_draw_logo (zbar_window_t *w)
{
    window_state_t *x = w->state;
    int screen = DefaultScreen(w->display);

    /* clear to white */
    XSetForeground(w->display, x->gc, WhitePixel(w->display, screen));
    XFillRectangle(w->display, w->xwin, x->gc, 0, 0, w->width, w->height);

    if(!x->logo_scale || !x->logo_zbars)
        return(0);

    XSetForeground(w->display, x->gc, BlackPixel(w->display, screen));
    XFillRectangles(w->display, w->xwin, x->gc, x->logo_bars, 5);

    XSetLineAttributes(w->display, x->gc, 2 * x->logo_scale,
                       LineSolid, CapRound, JoinRound);

    XSetForeground(w->display, x->gc, x->logo_colors[0]);
    XDrawLines(w->display, w->xwin, x->gc, x->logo_z, 4, CoordModeOrigin);

    if(x->exposed) {
        XIntersectRegion(x->logo_zbars, x->exposed, x->exposed);
        XSetRegion(w->display, x->gc, x->exposed);
    }
    else
        XSetRegion(w->display, x->gc, x->logo_zbars);

    XSetForeground(w->display, x->gc, x->logo_colors[1]);
    XDrawLines(w->display, w->xwin, x->gc, x->logo_z, 4, CoordModeOrigin);

    /* reset GC */
    XSetLineAttributes(w->display, x->gc, 0,
                       LineSolid, CapButt, JoinMiter);
    return(0);
}

