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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct rc_map_table {int scancode; } ;
struct dvb_usb_device {int dummy; } ;
struct dvb_frontend_tune_settings {int min_delay_ms; scalar_t__ max_drift; scalar_t__ step_size; } ;
struct dvb_frontend_ops {int dummy; } ;
struct dtv_frontend_properties {int frequency; int bandwidth_hz; } ;
struct dvb_frontend {struct dtt200u_fe_state* demodulator_priv; struct dtv_frontend_properties ops; struct dtv_frontend_properties dtv_property_cache; } ;
struct dtt200u_fe_state {int* data; struct dvb_frontend frontend; int /*<<< orphan*/  data_mutex; struct dvb_usb_device* d; int /*<<< orphan*/  fep; } ;
typedef  enum fe_status { ____Placeholder_fe_status } fe_status ;

/* Variables and functions */
 int EINVAL ; 
 int FE_HAS_CARRIER ; 
 int FE_HAS_LOCK ; 
 int FE_HAS_SIGNAL ; 
 int FE_HAS_SYNC ; 
 int FE_HAS_VITERBI ; 
 int FE_TIMEDOUT ; 
 int GET_AGC ; 
 int GET_RS_UNCOR_BLK_CNT ; 
 int GET_SNR ; 
 int GET_TUNE_STATUS ; 
 int GET_VIT_ERR_CNT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int SET_BANDWIDTH ; 
 int SET_INIT ; 
 int SET_RF_FREQ ; 
 int /*<<< orphan*/  deb_info (char*) ; 
 int /*<<< orphan*/  dtt200u_fe_ops ; 
 int dvb_usb_generic_rw (struct dvb_usb_device*,int*,int,int*,int,int /*<<< orphan*/ ) ; 
 int dvb_usb_generic_write (struct dvb_usb_device*,int*,int) ; 
 int /*<<< orphan*/  kfree (struct dtt200u_fe_state*) ; 
 struct dtt200u_fe_state* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (struct dtv_frontend_properties*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline u8 rc5_custom(struct rc_map_table *key)
{
	return (key->scancode >> 8) & 0xff;
}

__attribute__((used)) static inline u8 rc5_data(struct rc_map_table *key)
{
	return key->scancode & 0xff;
}

__attribute__((used)) static inline u16 rc5_scan(struct rc_map_table *key)
{
	return key->scancode & 0xffff;
}

__attribute__((used)) static int dtt200u_fe_read_status(struct dvb_frontend *fe,
				  enum fe_status *stat)
{
	struct dtt200u_fe_state *state = fe->demodulator_priv;
	int ret;

	mutex_lock(&state->data_mutex);
	state->data[0] = GET_TUNE_STATUS;

	ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 3, 0);
	if (ret < 0) {
		*stat = 0;
		mutex_unlock(&state->data_mutex);
		return ret;
	}

	switch (state->data[0]) {
		case 0x01:
			*stat = FE_HAS_SIGNAL | FE_HAS_CARRIER |
				FE_HAS_VITERBI | FE_HAS_SYNC | FE_HAS_LOCK;
			break;
		case 0x00: /* pending */
			*stat = FE_TIMEDOUT; /* during set_frontend */
			break;
		default:
		case 0x02: /* failed */
			*stat = 0;
			break;
	}
	mutex_unlock(&state->data_mutex);
	return 0;
}

__attribute__((used)) static int dtt200u_fe_read_ber(struct dvb_frontend* fe, u32 *ber)
{
	struct dtt200u_fe_state *state = fe->demodulator_priv;
	int ret;

	mutex_lock(&state->data_mutex);
	state->data[0] = GET_VIT_ERR_CNT;

	ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 3, 0);
	if (ret >= 0)
		*ber = (state->data[0] << 16) | (state->data[1] << 8) | state->data[2];

	mutex_unlock(&state->data_mutex);
	return ret;
}

__attribute__((used)) static int dtt200u_fe_read_unc_blocks(struct dvb_frontend* fe, u32 *unc)
{
	struct dtt200u_fe_state *state = fe->demodulator_priv;
	int ret;

	mutex_lock(&state->data_mutex);
	state->data[0] = GET_RS_UNCOR_BLK_CNT;

	ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 2, 0);
	if (ret >= 0)
		*unc = (state->data[0] << 8) | state->data[1];

	mutex_unlock(&state->data_mutex);
	return ret;
}

__attribute__((used)) static int dtt200u_fe_read_signal_strength(struct dvb_frontend* fe, u16 *strength)
{
	struct dtt200u_fe_state *state = fe->demodulator_priv;
	int ret;

	mutex_lock(&state->data_mutex);
	state->data[0] = GET_AGC;

	ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 1, 0);
	if (ret >= 0)
		*strength = (state->data[0] << 8) | state->data[0];

	mutex_unlock(&state->data_mutex);
	return ret;
}

__attribute__((used)) static int dtt200u_fe_read_snr(struct dvb_frontend* fe, u16 *snr)
{
	struct dtt200u_fe_state *state = fe->demodulator_priv;
	int ret;

	mutex_lock(&state->data_mutex);
	state->data[0] = GET_SNR;

	ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 1, 0);
	if (ret >= 0)
		*snr = ~((state->data[0] << 8) | state->data[0]);

	mutex_unlock(&state->data_mutex);
	return ret;
}

__attribute__((used)) static int dtt200u_fe_init(struct dvb_frontend* fe)
{
	struct dtt200u_fe_state *state = fe->demodulator_priv;
	int ret;

	mutex_lock(&state->data_mutex);
	state->data[0] = SET_INIT;

	ret = dvb_usb_generic_write(state->d, state->data, 1);
	mutex_unlock(&state->data_mutex);

	return ret;
}

__attribute__((used)) static int dtt200u_fe_sleep(struct dvb_frontend* fe)
{
	return dtt200u_fe_init(fe);
}

__attribute__((used)) static int dtt200u_fe_get_tune_settings(struct dvb_frontend* fe, struct dvb_frontend_tune_settings *tune)
{
	tune->min_delay_ms = 1500;
	tune->step_size = 0;
	tune->max_drift = 0;
	return 0;
}

__attribute__((used)) static int dtt200u_fe_set_frontend(struct dvb_frontend *fe)
{
	struct dtv_frontend_properties *fep = &fe->dtv_property_cache;
	struct dtt200u_fe_state *state = fe->demodulator_priv;
	int ret;
	u16 freq = fep->frequency / 250000;

	mutex_lock(&state->data_mutex);
	state->data[0] = SET_BANDWIDTH;
	switch (fep->bandwidth_hz) {
	case 8000000:
		state->data[1] = 8;
		break;
	case 7000000:
		state->data[1] = 7;
		break;
	case 6000000:
		state->data[1] = 6;
		break;
	default:
		ret = -EINVAL;
		goto ret;
	}

	ret = dvb_usb_generic_write(state->d, state->data, 2);
	if (ret < 0)
		goto ret;

	state->data[0] = SET_RF_FREQ;
	state->data[1] = freq & 0xff;
	state->data[2] = (freq >> 8) & 0xff;
	ret = dvb_usb_generic_write(state->d, state->data, 3);
	if (ret < 0)
		goto ret;

ret:
	mutex_unlock(&state->data_mutex);
	return ret;
}

__attribute__((used)) static int dtt200u_fe_get_frontend(struct dvb_frontend* fe,
				   struct dtv_frontend_properties *fep)
{
	struct dtt200u_fe_state *state = fe->demodulator_priv;

	memcpy(fep, &state->fep, sizeof(struct dtv_frontend_properties));
	return 0;
}

__attribute__((used)) static void dtt200u_fe_release(struct dvb_frontend* fe)
{
	struct dtt200u_fe_state *state = (struct dtt200u_fe_state*) fe->demodulator_priv;
	kfree(state);
}

struct dvb_frontend* dtt200u_fe_attach(struct dvb_usb_device *d)
{
	struct dtt200u_fe_state* state = NULL;

	/* allocate memory for the internal state */
	state = kzalloc(sizeof(struct dtt200u_fe_state), GFP_KERNEL);
	if (state == NULL)
		goto error;

	deb_info("attaching frontend dtt200u\n");

	state->d = d;
	mutex_init(&state->data_mutex);

	memcpy(&state->frontend.ops,&dtt200u_fe_ops,sizeof(struct dvb_frontend_ops));
	state->frontend.demodulator_priv = state;

	return &state->frontend;
error:
	return NULL;
}

