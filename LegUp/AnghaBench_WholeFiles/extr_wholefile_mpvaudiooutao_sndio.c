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
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int bits; int sig; scalar_t__ le; int bps; int rate; int appbufsz; int round; int bufsz; scalar_t__ msb; int /*<<< orphan*/  pchan; } ;
struct priv {int vol; int delay; int playing; TYPE_2__ par; int /*<<< orphan*/  pfd; int /*<<< orphan*/ * hdl; int /*<<< orphan*/  havevol; } ;
struct pollfd {int dummy; } ;
struct mp_chmap_sel {int /*<<< orphan*/  member_0; } ;
struct TYPE_8__ {int /*<<< orphan*/  num; } ;
struct ao {scalar_t__ format; int samplerate; int period_size; int sstride; struct priv* priv; TYPE_5__ channels; } ;
typedef  enum aocontrol { ____Placeholder_aocontrol } aocontrol ;
struct TYPE_6__ {int left; int right; } ;
typedef  TYPE_1__ ao_control_vol_t ;
typedef  int /*<<< orphan*/  af_to_par ;

/* Variables and functions */
#define  AF_FORMAT_S16 133 
#define  AF_FORMAT_S32 132 
#define  AF_FORMAT_U8 131 
#define  AOCONTROL_GET_VOLUME 130 
#define  AOCONTROL_HAS_SOFT_VOLUME 129 
#define  AOCONTROL_SET_VOLUME 128 
 int CONTROL_FALSE ; 
 int CONTROL_OK ; 
 int CONTROL_TRUE ; 
 int CONTROL_UNKNOWN ; 
 scalar_t__ EINTR ; 
 int /*<<< orphan*/  MP_ERR (struct ao*,char*,...) ; 
 int MP_NUM_CHANNELS ; 
 int /*<<< orphan*/  MP_VERBOSE (struct ao*,char*) ; 
 int /*<<< orphan*/  MP_WARN (struct ao*,char*) ; 
 int /*<<< orphan*/  POLLOUT ; 
 int SIO_BPS (int) ; 
 int /*<<< orphan*/  SIO_DEVANY ; 
 scalar_t__ SIO_LE_NATIVE ; 
 int SIO_MAXVOL ; 
 int /*<<< orphan*/  SIO_PLAY ; 
 scalar_t__ af_fmt_from_planar (scalar_t__) ; 
 int /*<<< orphan*/  ao_chmap_sel_adjust (struct ao*,struct mp_chmap_sel*,TYPE_5__*) ; 
 int /*<<< orphan*/  calloc (int /*<<< orphan*/ ,int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_chmap_sel_add_map (struct mp_chmap_sel*,int /*<<< orphan*/ *) ; 
 scalar_t__ poll (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sio_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sio_getpar (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  sio_initpar (TYPE_2__*) ; 
 int /*<<< orphan*/  sio_nfds (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sio_onmove (int /*<<< orphan*/ *,void (*) (void*,int),struct priv*) ; 
 int /*<<< orphan*/  sio_onvol (int /*<<< orphan*/ *,void (*) (void*,unsigned int),struct priv*) ; 
 int /*<<< orphan*/ * sio_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sio_pollfd (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sio_revents (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sio_setpar (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  sio_setvol (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sio_start (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sio_stop (int /*<<< orphan*/ *) ; 
 int sio_write (int /*<<< orphan*/ *,void*,int) ; 
 int /*<<< orphan*/ * sndio_layouts ; 

__attribute__((used)) static int control(struct ao *ao, enum aocontrol cmd, void *arg)
{
    struct priv *p = ao->priv;
    ao_control_vol_t *vol = arg;

    switch (cmd) {
    case AOCONTROL_GET_VOLUME:
        if (!p->havevol)
            return CONTROL_FALSE;
        vol->left = vol->right = p->vol * 100 / SIO_MAXVOL;
        break;
    case AOCONTROL_SET_VOLUME:
        if (!p->havevol)
            return CONTROL_FALSE;
        sio_setvol(p->hdl, vol->left * SIO_MAXVOL / 100);
        break;
    case AOCONTROL_HAS_SOFT_VOLUME:
        return CONTROL_TRUE;
    default:
        return CONTROL_UNKNOWN;
    }
    return CONTROL_OK;
}

__attribute__((used)) static void movecb(void *addr, int delta)
{
    struct priv *p = addr;
    p->delay -= delta;
}

__attribute__((used)) static void volcb(void *addr, unsigned newvol)
{
    struct priv *p = addr;
    p->vol = newvol;
}

__attribute__((used)) static int init(struct ao *ao)
{
    struct priv *p = ao->priv;

    struct af_to_par {
        int format, bits, sig;
    };
    static const struct af_to_par af_to_par[] = {
        {AF_FORMAT_U8,   8, 0},
        {AF_FORMAT_S16, 16, 1},
        {AF_FORMAT_S32, 32, 1},
    };
    const struct af_to_par *ap;
    int i;

    p->hdl = sio_open(SIO_DEVANY, SIO_PLAY, 0);
    if (p->hdl == NULL) {
        MP_ERR(ao, "can't open sndio %s\n", SIO_DEVANY);
        goto error;
    }

    ao->format = af_fmt_from_planar(ao->format);

    sio_initpar(&p->par);
    for (i = 0, ap = af_to_par;; i++, ap++) {
        if (i == sizeof(af_to_par) / sizeof(struct af_to_par)) {
            MP_VERBOSE(ao, "unsupported format\n");
            p->par.bits = 16;
            p->par.sig = 1;
            p->par.le = SIO_LE_NATIVE;
            break;
        }
        if (ap->format == ao->format) {
            p->par.bits = ap->bits;
            p->par.sig = ap->sig;
            if (ap->bits > 8)
                p->par.le = SIO_LE_NATIVE;
            if (ap->bits != SIO_BPS(ap->bits))
                p->par.bps = ap->bits / 8;
            break;
        }
    }
    p->par.rate = ao->samplerate;

    struct mp_chmap_sel sel = {0};
    for (int n = 0; n < MP_NUM_CHANNELS+1; n++)
        mp_chmap_sel_add_map(&sel, &sndio_layouts[n]);

    if (!ao_chmap_sel_adjust(ao, &sel, &ao->channels))
        goto error;

    p->par.pchan = ao->channels.num;
    p->par.appbufsz = p->par.rate * 250 / 1000;    /* 250ms buffer */
    p->par.round = p->par.rate * 10 / 1000;    /*  10ms block size */
    if (!sio_setpar(p->hdl, &p->par)) {
        MP_ERR(ao, "couldn't set params\n");
        goto error;
    }
    if (!sio_getpar(p->hdl, &p->par)) {
        MP_ERR(ao, "couldn't get params\n");
        goto error;
    }
    if (p->par.bps > 1 && p->par.le != SIO_LE_NATIVE) {
        MP_ERR(ao, "swapped endian output not supported\n");
        goto error;
    }
    if (p->par.bits == 8 && p->par.bps == 1 && !p->par.sig) {
        ao->format = AF_FORMAT_U8;
    } else if (p->par.bits == 16 && p->par.bps == 2 && p->par.sig) {
        ao->format = AF_FORMAT_S16;
    } else if ((p->par.bits == 32 || p->par.msb) && p->par.bps == 4 && p->par.sig) {
        ao->format = AF_FORMAT_S32;
    } else {
        MP_ERR(ao, "couldn't set format\n");
        goto error;
    }

    p->havevol = sio_onvol(p->hdl, volcb, p);
    sio_onmove(p->hdl, movecb, p);
    if (!sio_start(p->hdl))
        MP_ERR(ao, "init: couldn't start\n");

    p->pfd = calloc (sio_nfds(p->hdl), sizeof (struct pollfd));
    if (!p->pfd)
        goto error;

    ao->period_size = p->par.round;

    return 0;

error:
    if (p->hdl)
      sio_close(p->hdl);

    return -1;
}

__attribute__((used)) static void uninit(struct ao *ao)
{
    struct priv *p = ao->priv;

    if (p->hdl)
        sio_close(p->hdl);

    free(p->pfd);
}

__attribute__((used)) static void reset(struct ao *ao)
{
    struct priv *p = ao->priv;

    if (p->playing) {
        MP_WARN(ao, "Blocking until remaining audio is played... (sndio design bug).\n");

        p->playing = false;

        if (!sio_stop(p->hdl))
            MP_ERR(ao, "reset: couldn't stop\n");
        p->delay = 0;
        if (!sio_start(p->hdl))
            MP_ERR(ao, "reset: couldn't start\n");
    }
}

__attribute__((used)) static int play(struct ao *ao, void **data, int samples, int flags)
{
    struct priv *p = ao->priv;
    int n;

    n = sio_write(p->hdl, data[0], samples * ao->sstride) / ao->sstride;
    p->delay += n;
    p->playing = true;
    /* on AOPLAY_FINAL_CHUNK, just let it underrun */
    return n;
}

__attribute__((used)) static void update(struct ao *ao)
{
    struct priv *p = ao->priv;
    int n = sio_pollfd(p->hdl, p->pfd, POLLOUT);
    while (poll(p->pfd, n, 0) < 0 && errno == EINTR) {}
    sio_revents(p->hdl, p->pfd);
}

__attribute__((used)) static int get_space(struct ao *ao)
{
    struct priv *p = ao->priv;

    update(ao);

    int samples = p->par.bufsz - p->delay;
    return samples / p->par.round * p->par.round;
}

__attribute__((used)) static double get_delay(struct ao *ao)
{
    struct priv *p = ao->priv;

    update(ao);

    return p->delay / (double)p->par.rate;
}

__attribute__((used)) static void audio_pause(struct ao *ao)
{
    reset(ao);
}

__attribute__((used)) static void audio_resume(struct ao *ao)
{
    return;
}

