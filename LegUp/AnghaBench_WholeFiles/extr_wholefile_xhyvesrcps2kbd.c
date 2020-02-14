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
typedef  int uint8_t ;
typedef  int uint32_t ;
struct fifo {int size; scalar_t__ num; int* buf; size_t windex; size_t rindex; } ;
struct ps2kbd_softc {int curcmd; int enabled; struct atkbdc_softc* atkbdc_sc; int /*<<< orphan*/  mtx; struct fifo fifo; } ;
struct atkbdc_softc {int dummy; } ;

/* Variables and functions */
 scalar_t__ PS2KBD_FIFOSZ ; 
 int PS2KC_ACK ; 
 int PS2KC_BAT_SUCCESS ; 
#define  PS2KC_DISABLE 135 
#define  PS2KC_ECHO 134 
#define  PS2KC_ENABLE 133 
#define  PS2KC_RESET_DEV 132 
#define  PS2KC_SEND_DEV_ID 131 
#define  PS2KC_SET_LEDS 130 
#define  PS2KC_SET_SCANCODE_SET 129 
#define  PS2KC_SET_TYPEMATIC 128 
 int /*<<< orphan*/  atkbdc_event (struct atkbdc_softc*,int) ; 
 int /*<<< orphan*/  bzero (struct fifo*,int) ; 
 struct ps2kbd_softc* calloc (int,int) ; 
 int /*<<< orphan*/  console_kbd_register (void (*) (int,int,void*),struct ps2kbd_softc*,int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void
fifo_init(struct ps2kbd_softc *sc)
{
	struct fifo *fifo;

	fifo = &sc->fifo;
	fifo->size = sizeof(((struct fifo *)0)->buf);
}

__attribute__((used)) static void
fifo_reset(struct ps2kbd_softc *sc)
{
	struct fifo *fifo;

	fifo = &sc->fifo;
	bzero(fifo, sizeof(struct fifo));
	fifo->size = sizeof(((struct fifo *)0)->buf);
}

__attribute__((used)) static void
fifo_put(struct ps2kbd_softc *sc, uint8_t val)
{
	struct fifo *fifo;

	fifo = &sc->fifo;
	if (fifo->num < fifo->size) {
		fifo->buf[fifo->windex] = val;
		fifo->windex = (fifo->windex + 1) % fifo->size;
		fifo->num++;
	}
}

__attribute__((used)) static int
fifo_get(struct ps2kbd_softc *sc, uint8_t *val)
{
	struct fifo *fifo;

	fifo = &sc->fifo;
	if (fifo->num > 0) {
		*val = fifo->buf[fifo->rindex];
		fifo->rindex = (fifo->rindex + 1) % fifo->size;
		fifo->num--;
		return (0);
	}

	return (-1);
}

int
ps2kbd_read(struct ps2kbd_softc *sc, uint8_t *val)
{
	int retval;

	pthread_mutex_lock(&sc->mtx);
	retval = fifo_get(sc, val);
	pthread_mutex_unlock(&sc->mtx);

	return (retval);
}

void
ps2kbd_write(struct ps2kbd_softc *sc, uint8_t val)
{
	pthread_mutex_lock(&sc->mtx);
	if (sc->curcmd) {
		switch (sc->curcmd) {
		case PS2KC_SET_TYPEMATIC:
			fifo_put(sc, PS2KC_ACK);
			break;
		case PS2KC_SET_SCANCODE_SET:
			fifo_put(sc, PS2KC_ACK);
			break;
		case PS2KC_SET_LEDS:
			fifo_put(sc, PS2KC_ACK);
			break;
		default:
			fprintf(stderr, "Unhandled ps2 keyboard current "
			    "command byte 0x%02x\n", val);
			break;
		}
		sc->curcmd = 0;
	} else {
		switch (val) {
		case 0x00:
			fifo_put(sc, PS2KC_ACK);
			break;
		case PS2KC_RESET_DEV:
			fifo_reset(sc);
			fifo_put(sc, PS2KC_ACK);
			fifo_put(sc, PS2KC_BAT_SUCCESS);
			break;
		case PS2KC_DISABLE:
			sc->enabled = false;
			fifo_put(sc, PS2KC_ACK);
			break;
		case PS2KC_ENABLE:
			sc->enabled = true;
			fifo_reset(sc);
			fifo_put(sc, PS2KC_ACK);
			break;
		case PS2KC_SET_TYPEMATIC:
			sc->curcmd = val;
			fifo_put(sc, PS2KC_ACK);
			break;
		case PS2KC_SEND_DEV_ID:
			fifo_put(sc, PS2KC_ACK);
			fifo_put(sc, 0xab);
			fifo_put(sc, 0x83);
			break;
		case PS2KC_SET_SCANCODE_SET:
			sc->curcmd = val;
			fifo_put(sc, PS2KC_ACK);
			break;
		case PS2KC_ECHO:
			fifo_put(sc, PS2KC_ECHO);
			break;
		case PS2KC_SET_LEDS:
			sc->curcmd = val;
			fifo_put(sc, PS2KC_ACK);
			break;
		default:
			fprintf(stderr, "Unhandled ps2 keyboard command "
			    "0x%02x\n", val);
			break;
		}
	}
	pthread_mutex_unlock(&sc->mtx);
}

__attribute__((used)) static void
ps2kbd_keysym_queue(struct ps2kbd_softc *sc,
    int down, uint32_t keysym)
{
	/* ASCII to type 2 scancode lookup table */
	const uint8_t translation[128] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x29, 0x16, 0x52, 0x26, 0x25, 0x2e, 0x3d, 0x52,
		0x46, 0x45, 0x3e, 0x55, 0x41, 0x4e, 0x49, 0x4a,
		0x45, 0x16, 0x1e, 0x26, 0x25, 0x2e, 0x36, 0x3d,
		0x3e, 0x46, 0x4c, 0x4c, 0x41, 0x55, 0x49, 0x4a,
		0x1e, 0x1c, 0x32, 0x21, 0x23, 0x24, 0x2b, 0x34,
		0x33, 0x43, 0x3b, 0x42, 0x4b, 0x3a, 0x31, 0x44,
		0x4d, 0x15, 0x2d, 0x1b, 0x2c, 0x3c, 0x2a, 0x1d,
		0x22, 0x35, 0x1a, 0x54, 0x5d, 0x5b, 0x36, 0x4e,
		0x0e, 0x1c, 0x32, 0x21, 0x23, 0x24, 0x2b, 0x34,
		0x33, 0x43, 0x3b, 0x42, 0x4b, 0x3a, 0x31, 0x44,
		0x4d, 0x15, 0x2d, 0x1b, 0x2c, 0x3c, 0x2a, 0x1d,
		0x22, 0x35, 0x1a, 0x54, 0x5d, 0x5b, 0x0e, 0x00,
	};

    if (keysym <= 0x7f) {
        if (!down)
            fifo_put(sc, 0xf0);
        fifo_put(sc, translation[keysym]);
    } else {
        switch (keysym) {
        case 0xff08:	/* Back space */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x66);
            break;
        case 0xff09:	/* Tab */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x0d);
            break;
        case 0xff0d:	/* Return  */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x5a);
            break;
        case 0xff1b:	/* Escape */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x76);
            break;
        case 0xff50:	/* Home */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x6c);
            break;
        case 0xff51:	/* Left arrow */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x6b);
            break;
        case 0xff52:	/* Up arrow */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x75);
            break;
        case 0xff53:	/* Right arrow */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x74);
            break;
        case 0xff54:	/* Down arrow */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x72);
            break;
        case 0xff55:	/* PgUp */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x7d);
            break;
        case 0xff56:	/* PgDwn */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x7a);
            break;
        case 0xff57:	/* End */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x69);
            break;
        case 0xff63:	/* Ins */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x70);
            break;
        case 0xff8d:	/* Keypad Enter */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x5a);
            break;
        case 0xffe1:	/* Left shift */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x12);
            break;
        case 0xffe2:	/* Right shift */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x59);
            break;
        case 0xffe3:	/* Left control */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x14);
            break;
        case 0xffe4:	/* Right control */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x14);
            break;
        case 0xffe7:	/* Left meta */
            /* XXX */
            break;
        case 0xffe8:	/* Right meta */
            /* XXX */
            break;
        case 0xffe9:	/* Left alt */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x11);
            break;
        case 0xfe03:	/* AltGr */
        case 0xffea:	/* Right alt */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x11);
            break;
        case 0xffeb:	/* Left Windows */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x1f);
            break;
        case 0xffec:	/* Right Windows */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x27);
            break;
        case 0xffbe:    /* F1 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x05);
            break;
        case 0xffbf:    /* F2 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x06);
            break;
        case 0xffc0:    /* F3 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x04);
            break;
        case 0xffc1:    /* F4 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x0C);
            break;
        case 0xffc2:    /* F5 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x03);
            break;
        case 0xffc3:    /* F6 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x0B);
            break;
        case 0xffc4:    /* F7 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x83);
            break;
        case 0xffc5:    /* F8 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x0A);
            break;
        case 0xffc6:    /* F9 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x01);
            break;
        case 0xffc7:    /* F10 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x09);
            break;
        case 0xffc8:    /* F11 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x78);
            break;
        case 0xffc9:    /* F12 */
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x07);
            break;
        case 0xffff:    /* Del */
            fifo_put(sc, 0xe0);
            if (!down)
                fifo_put(sc, 0xf0);
            fifo_put(sc, 0x71);
            break;
        default:
            fprintf(stderr, "Unhandled ps2 keyboard keysym 0x%x\n",
                 keysym);
            break;
        }
    }
}

__attribute__((used)) static void
ps2kbd_event(int down, uint32_t keysym, void *arg)
{
	struct ps2kbd_softc *sc = arg;
	int fifo_full;

	pthread_mutex_lock(&sc->mtx);
	if (!sc->enabled) {
		pthread_mutex_unlock(&sc->mtx);
		return;
	}
	fifo_full = sc->fifo.num == PS2KBD_FIFOSZ;
	ps2kbd_keysym_queue(sc, down, keysym);
	pthread_mutex_unlock(&sc->mtx);

	if (!fifo_full)
		atkbdc_event(sc->atkbdc_sc, 1);
}

struct ps2kbd_softc *
ps2kbd_init(struct atkbdc_softc *atkbdc_sc)
{
	struct ps2kbd_softc *sc;

	sc = calloc(1, sizeof (struct ps2kbd_softc));
	pthread_mutex_init(&sc->mtx, NULL);
	fifo_init(sc);
	sc->atkbdc_sc = atkbdc_sc;

	console_kbd_register(ps2kbd_event, sc, 1);

	return (sc);
}

