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
struct fifo {int size; scalar_t__ num; int* buf; size_t windex; size_t rindex; } ;
struct ps2mouse_softc {scalar_t__ delta_x; scalar_t__ delta_y; int cur_x; int cur_y; int status; int resolution; int sampling_rate; int ctrlenable; int curcmd; int /*<<< orphan*/  mtx; struct atkbdc_softc* atkbdc_sc; struct fifo fifo; } ;
struct atkbdc_softc {int dummy; } ;

/* Variables and functions */
 int PS2MC_ACK ; 
 int PS2MC_BAT_SUCCESS ; 
#define  PS2MC_DISABLE 140 
#define  PS2MC_ENABLE 139 
#define  PS2MC_RESET_DEV 138 
#define  PS2MC_SEND_DEV_DATA 137 
#define  PS2MC_SEND_DEV_ID 136 
#define  PS2MC_SEND_DEV_STATUS 135 
#define  PS2MC_SET_DEFAULTS 134 
#define  PS2MC_SET_REMOTE_MODE 133 
#define  PS2MC_SET_RESOLUTION 132 
#define  PS2MC_SET_SAMPLING_RATE 131 
#define  PS2MC_SET_SCALING1 130 
#define  PS2MC_SET_SCALING2 129 
#define  PS2MC_SET_STREAM_MODE 128 
 int PS2MOUSE_DEV_ID ; 
 int PS2M_DATA_AONE ; 
 int PS2M_DATA_LEFT_BUTTON ; 
 int PS2M_DATA_MID_BUTTON ; 
 int PS2M_DATA_RIGHT_BUTTON ; 
 int PS2M_DATA_X_OFLOW ; 
 int PS2M_DATA_X_SIGN ; 
 int PS2M_DATA_Y_OFLOW ; 
 int PS2M_DATA_Y_SIGN ; 
 int PS2M_STS_ENABLE_DEV ; 
 int PS2M_STS_LEFT_BUTTON ; 
 int PS2M_STS_MID_BUTTON ; 
 int PS2M_STS_REMOTE_MODE ; 
 int PS2M_STS_RIGHT_BUTTON ; 
 int /*<<< orphan*/  atkbdc_event (struct atkbdc_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bzero (struct fifo*,int) ; 
 struct ps2mouse_softc* calloc (int,int) ; 
 int /*<<< orphan*/  console_ptr_register (void (*) (int,int,int,void*),struct ps2mouse_softc*,int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void
fifo_init(struct ps2mouse_softc *sc)
{
	struct fifo *fifo;

	fifo = &sc->fifo;
	fifo->size = sizeof(((struct fifo *)0)->buf);
}

__attribute__((used)) static void
fifo_reset(struct ps2mouse_softc *sc)
{
	struct fifo *fifo;

	fifo = &sc->fifo;
	bzero(fifo, sizeof(struct fifo));
	fifo->size = sizeof(((struct fifo *)0)->buf);
}

__attribute__((used)) static void
fifo_put(struct ps2mouse_softc *sc, uint8_t val)
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
fifo_get(struct ps2mouse_softc *sc, uint8_t *val)
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

__attribute__((used)) static void
movement_reset(struct ps2mouse_softc *sc)
{
	sc->delta_x = 0;
	sc->delta_y = 0;
}

__attribute__((used)) static void
movement_update(struct ps2mouse_softc *sc, int x, int y)
{
	sc->delta_x += x - sc->cur_x;
	sc->delta_y += sc->cur_y - y;
	sc->cur_x = x;
	sc->cur_y = y;
}

__attribute__((used)) static void
movement_get(struct ps2mouse_softc *sc)
{
	uint8_t val0, val1, val2;

	val0 = PS2M_DATA_AONE;
	val0 |= sc->status & (PS2M_DATA_LEFT_BUTTON |
	    PS2M_DATA_RIGHT_BUTTON | PS2M_DATA_MID_BUTTON);

	if (sc->delta_x >= 0) {
		if (sc->delta_x > 255) {
			val0 |= PS2M_DATA_X_OFLOW;
			val1 = 255;
		} else
			val1 = (uint8_t)sc->delta_x;
	} else {
		val0 |= PS2M_DATA_X_SIGN;
		if (sc->delta_x < -255) {
			val0 |= PS2M_DATA_X_OFLOW;
			val1 = 255;
		} else
			val1 = (uint8_t)sc->delta_x;
	}
	sc->delta_x = 0;

	if (sc->delta_y >= 0) {
		if (sc->delta_y > 255) {
			val0 |= PS2M_DATA_Y_OFLOW;
			val2 = 255;
		} else
			val2 = (uint8_t)sc->delta_y;
	} else {
		val0 |= PS2M_DATA_Y_SIGN;
		if (sc->delta_y < -255) {
			val0 |= PS2M_DATA_Y_OFLOW;
			val2 = 255;
		} else
			val2 = (uint8_t)sc->delta_y;
	}
	sc->delta_y = 0;

	if (sc->fifo.num < (sc->fifo.size - 3)) {
		fifo_put(sc, val0);
		fifo_put(sc, val1);
		fifo_put(sc, val2);
	}
}

__attribute__((used)) static void
ps2mouse_reset(struct ps2mouse_softc *sc)
{
	fifo_reset(sc);
	movement_reset(sc);
	sc->status = PS2M_STS_ENABLE_DEV;
	sc->resolution = 4;
	sc->sampling_rate = 100;

	sc->cur_x = 0;
	sc->cur_y = 0;
	sc->delta_x = 0;
	sc->delta_y = 0;
}

int
ps2mouse_read(struct ps2mouse_softc *sc, uint8_t *val)
{
	int retval;

	pthread_mutex_lock(&sc->mtx);
	retval = fifo_get(sc, val);
	pthread_mutex_unlock(&sc->mtx);

	return (retval);
}

int
ps2mouse_fifocnt(struct ps2mouse_softc *sc)
{
	return (sc->fifo.num);
}

void
ps2mouse_toggle(struct ps2mouse_softc *sc, int enable)
{
	pthread_mutex_lock(&sc->mtx);
	if (enable)
		sc->ctrlenable = 1;
	else {
		sc->ctrlenable = 0;
		sc->fifo.rindex = 0;
		sc->fifo.windex = 0;
		sc->fifo.num = 0;
	}
	pthread_mutex_unlock(&sc->mtx);
}

void
ps2mouse_write(struct ps2mouse_softc *sc, uint8_t val, int insert)
{
	pthread_mutex_lock(&sc->mtx);
	fifo_reset(sc);
	if (sc->curcmd) {
		switch (sc->curcmd) {
		case PS2MC_SET_SAMPLING_RATE:
			sc->sampling_rate = val;
			fifo_put(sc, PS2MC_ACK);
			break;
		case PS2MC_SET_RESOLUTION:
			sc->resolution = val;
			fifo_put(sc, PS2MC_ACK);
			break;
		default:
			fprintf(stderr, "Unhandled ps2 mouse current "
			    "command byte 0x%02x\n", val);
			break;
		}
		sc->curcmd = 0;

	} else if (insert) {
		fifo_put(sc, val);
	} else {
		switch (val) {
		case 0x00:
			fifo_put(sc, PS2MC_ACK);
			break;
		case PS2MC_RESET_DEV:
			ps2mouse_reset(sc);
			fifo_put(sc, PS2MC_ACK);
			fifo_put(sc, PS2MC_BAT_SUCCESS);
			fifo_put(sc, PS2MOUSE_DEV_ID);
			break;
		case PS2MC_SET_DEFAULTS:
			ps2mouse_reset(sc);
			fifo_put(sc, PS2MC_ACK);
			break;
		case PS2MC_DISABLE:
			fifo_reset(sc);
			sc->status &= ~PS2M_STS_ENABLE_DEV;
			fifo_put(sc, PS2MC_ACK);
			break;
		case PS2MC_ENABLE:
			fifo_reset(sc);
			sc->status |= PS2M_STS_ENABLE_DEV;
			fifo_put(sc, PS2MC_ACK);
			break;
		case PS2MC_SET_SAMPLING_RATE:
			sc->curcmd = val;
			fifo_put(sc, PS2MC_ACK);
			break;
		case PS2MC_SEND_DEV_ID:
			fifo_put(sc, PS2MC_ACK);
			fifo_put(sc, PS2MOUSE_DEV_ID);
			break;
		case PS2MC_SET_REMOTE_MODE:
			sc->status |= PS2M_STS_REMOTE_MODE;
			fifo_put(sc, PS2MC_ACK);
			break;
		case PS2MC_SEND_DEV_DATA:
			fifo_put(sc, PS2MC_ACK);
			movement_get(sc);
			break;
		case PS2MC_SET_STREAM_MODE:
			sc->status &= ~PS2M_STS_REMOTE_MODE;
			fifo_put(sc, PS2MC_ACK);
			break;
		case PS2MC_SEND_DEV_STATUS:
			fifo_put(sc, PS2MC_ACK);
			fifo_put(sc, sc->status);
			fifo_put(sc, sc->resolution);
			fifo_put(sc, sc->sampling_rate);
			break;
		case PS2MC_SET_RESOLUTION:
			sc->curcmd = val;
			fifo_put(sc, PS2MC_ACK);
			break;
		case PS2MC_SET_SCALING1:
		case PS2MC_SET_SCALING2:
			fifo_put(sc, PS2MC_ACK);
			break;
		default:
			fifo_put(sc, PS2MC_ACK);
			fprintf(stderr, "Unhandled ps2 mouse command "
			    "0x%02x\n", val);
			break;
		}
	}
	pthread_mutex_unlock(&sc->mtx);
}

__attribute__((used)) static void
ps2mouse_event(uint8_t button, int x, int y, void *arg)
{
	struct ps2mouse_softc *sc = arg;

	pthread_mutex_lock(&sc->mtx);
	movement_update(sc, x, y);

	sc->status &= ~(PS2M_STS_LEFT_BUTTON |
	    PS2M_STS_RIGHT_BUTTON | PS2M_STS_MID_BUTTON);
	if (button & (1 << 0))
		sc->status |= PS2M_STS_LEFT_BUTTON;
	if (button & (1 << 1))
		sc->status |= PS2M_STS_MID_BUTTON;
	if (button & (1 << 2))
		sc->status |= PS2M_STS_RIGHT_BUTTON;

	if ((sc->status & PS2M_STS_ENABLE_DEV) == 0 || !sc->ctrlenable) {
		/* no data reporting */
		pthread_mutex_unlock(&sc->mtx);
		return;
	}

	movement_get(sc);
	pthread_mutex_unlock(&sc->mtx);

	if (sc->fifo.num > 0)
		atkbdc_event(sc->atkbdc_sc, 0);
}

struct ps2mouse_softc *
ps2mouse_init(struct atkbdc_softc *atkbdc_sc)
{
	struct ps2mouse_softc *sc;

	sc = calloc(1, sizeof (struct ps2mouse_softc));
	pthread_mutex_init(&sc->mtx, NULL);
	fifo_init(sc);
	sc->atkbdc_sc = atkbdc_sc;

	pthread_mutex_lock(&sc->mtx);
	ps2mouse_reset(sc);
	pthread_mutex_unlock(&sc->mtx);

	console_ptr_register(ps2mouse_event, sc, 1);

	return (sc);
}

