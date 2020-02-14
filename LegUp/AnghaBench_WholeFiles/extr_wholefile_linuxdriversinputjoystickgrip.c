#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {size_t product; int version; int /*<<< orphan*/  vendor; int /*<<< orphan*/  bustype; } ;
struct input_dev {int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int* evbit; int /*<<< orphan*/  keybit; TYPE_2__ dev; TYPE_1__ id; int /*<<< orphan*/  phys; int /*<<< orphan*/  name; } ;
struct grip {int* mode; struct input_dev** dev; int /*<<< orphan*/ * phys; struct gameport* gameport; int /*<<< orphan*/  bads; int /*<<< orphan*/  reads; } ;
struct gameport_driver {int dummy; } ;
struct gameport {char* phys; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_BRAKE ; 
 int /*<<< orphan*/  ABS_GAS ; 
 int /*<<< orphan*/  ABS_HAT0X ; 
 int /*<<< orphan*/  ABS_HAT0Y ; 
 int /*<<< orphan*/  ABS_HAT1X ; 
 int /*<<< orphan*/  ABS_HAT1Y ; 
 int /*<<< orphan*/  ABS_RX ; 
 int /*<<< orphan*/  ABS_RY ; 
 int /*<<< orphan*/  ABS_THROTTLE ; 
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int BIT_MASK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUS_GAMEPORT ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GAMEPORT_ID_VENDOR_GRAVIS ; 
 int /*<<< orphan*/  GAMEPORT_MODE_RAW ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GRIP_LENGTH_GPP ; 
 int GRIP_LENGTH_XT ; 
 unsigned int GRIP_MAX_BITS_XT ; 
 unsigned int GRIP_MAX_CHUNKS_XT ; 
#define  GRIP_MODE_BD 131 
#define  GRIP_MODE_DC 130 
#define  GRIP_MODE_GPP 129 
#define  GRIP_MODE_XT 128 
 int /*<<< orphan*/  GRIP_STROBE_GPP ; 
 int /*<<< orphan*/  GRIP_STROBE_XT ; 
 int /*<<< orphan*/  gameport_close (struct gameport*) ; 
 struct grip* gameport_get_drvdata (struct gameport*) ; 
 int gameport_open (struct gameport*,struct gameport_driver*,int /*<<< orphan*/ ) ; 
 int gameport_read (struct gameport*) ; 
 int /*<<< orphan*/  gameport_set_drvdata (struct gameport*,struct grip*) ; 
 int /*<<< orphan*/  gameport_set_poll_handler (struct gameport*,void (*) (struct gameport*)) ; 
 int /*<<< orphan*/  gameport_set_poll_interval (struct gameport*,int) ; 
 int /*<<< orphan*/  gameport_start_polling (struct gameport*) ; 
 int /*<<< orphan*/  gameport_stop_polling (struct gameport*) ; 
 int gameport_time (struct gameport*,int /*<<< orphan*/ ) ; 
 int** grip_abs ; 
 int* grip_anx ; 
 int** grip_btn ; 
 int /*<<< orphan*/ * grip_btn_bd ; 
 int /*<<< orphan*/ * grip_btn_dc ; 
 int /*<<< orphan*/ * grip_btn_gpp ; 
 int /*<<< orphan*/ * grip_btn_xt ; 
 int* grip_cen ; 
 int /*<<< orphan*/ * grip_name ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 struct grip* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int,int,int,int,int) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct grip*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct grip*) ; 
 struct grip* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  set_bit (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*,int) ; 

__attribute__((used)) static int grip_gpp_read_packet(struct gameport *gameport, int shift, unsigned int *data)
{
	unsigned long flags;
	unsigned char u, v;
	unsigned int t;
	int i;

	int strobe = gameport_time(gameport, GRIP_STROBE_GPP);

	data[0] = 0;
	t = strobe;
	i = 0;

	local_irq_save(flags);

	v = gameport_read(gameport) >> shift;

	do {
		t--;
		u = v; v = (gameport_read(gameport) >> shift) & 3;
		if (~v & u & 1) {
			data[0] |= (v >> 1) << i++;
			t = strobe;
		}
	} while (i < GRIP_LENGTH_GPP && t > 0);

	local_irq_restore(flags);

	if (i < GRIP_LENGTH_GPP) return -1;

	for (i = 0; i < GRIP_LENGTH_GPP && (data[0] & 0xfe4210) ^ 0x7c0000; i++)
		data[0] = data[0] >> 1 | (data[0] & 1) << (GRIP_LENGTH_GPP - 1);

	return -(i == GRIP_LENGTH_GPP);
}

__attribute__((used)) static int grip_xt_read_packet(struct gameport *gameport, int shift, unsigned int *data)
{
	unsigned int i, j, buf, crc;
	unsigned char u, v, w;
	unsigned long flags;
	unsigned int t;
	char status;

	int strobe = gameport_time(gameport, GRIP_STROBE_XT);

	data[0] = data[1] = data[2] = data[3] = 0;
	status = buf = i = j = 0;
	t = strobe;

	local_irq_save(flags);

	v = w = (gameport_read(gameport) >> shift) & 3;

	do {
		t--;
		u = (gameport_read(gameport) >> shift) & 3;

		if (u ^ v) {

			if ((u ^ v) & 1) {
				buf = (buf << 1) | (u >> 1);
				t = strobe;
				i++;
			} else

			if ((((u ^ v) & (v ^ w)) >> 1) & ~(u | v | w) & 1) {
				if (i == 20) {
					crc = buf ^ (buf >> 7) ^ (buf >> 14);
					if (!((crc ^ (0x25cb9e70 >> ((crc >> 2) & 0x1c))) & 0xf)) {
						data[buf >> 18] = buf >> 4;
						status |= 1 << (buf >> 18);
					}
					j++;
				}
				t = strobe;
				buf = 0;
				i = 0;
			}
			w = v;
			v = u;
		}

	} while (status != 0xf && i < GRIP_MAX_BITS_XT && j < GRIP_MAX_CHUNKS_XT && t > 0);

	local_irq_restore(flags);

	return -(status != 0xf);
}

__attribute__((used)) static void grip_poll(struct gameport *gameport)
{
	struct grip *grip = gameport_get_drvdata(gameport);
	unsigned int data[GRIP_LENGTH_XT];
	struct input_dev *dev;
	int i, j;

	for (i = 0; i < 2; i++) {

		dev = grip->dev[i];
		if (!dev)
			continue;

		grip->reads++;

		switch (grip->mode[i]) {

			case GRIP_MODE_GPP:

				if (grip_gpp_read_packet(grip->gameport, (i << 1) + 4, data)) {
					grip->bads++;
					break;
				}

				input_report_abs(dev, ABS_X, ((*data >> 15) & 1) - ((*data >> 16) & 1));
				input_report_abs(dev, ABS_Y, ((*data >> 13) & 1) - ((*data >> 12) & 1));

				for (j = 0; j < 12; j++)
					if (grip_btn_gpp[j])
						input_report_key(dev, grip_btn_gpp[j], (*data >> j) & 1);

				break;

			case GRIP_MODE_BD:

				if (grip_xt_read_packet(grip->gameport, (i << 1) + 4, data)) {
					grip->bads++;
					break;
				}

				input_report_abs(dev, ABS_X,        (data[0] >> 2) & 0x3f);
				input_report_abs(dev, ABS_Y,  63 - ((data[0] >> 8) & 0x3f));
				input_report_abs(dev, ABS_THROTTLE, (data[2] >> 8) & 0x3f);

				input_report_abs(dev, ABS_HAT0X, ((data[2] >> 1) & 1) - ( data[2]       & 1));
				input_report_abs(dev, ABS_HAT0Y, ((data[2] >> 2) & 1) - ((data[2] >> 3) & 1));

				for (j = 0; j < 5; j++)
					input_report_key(dev, grip_btn_bd[j], (data[3] >> (j + 4)) & 1);

				break;

			case GRIP_MODE_XT:

				if (grip_xt_read_packet(grip->gameport, (i << 1) + 4, data)) {
					grip->bads++;
					break;
				}

				input_report_abs(dev, ABS_X,        (data[0] >> 2) & 0x3f);
				input_report_abs(dev, ABS_Y,  63 - ((data[0] >> 8) & 0x3f));
				input_report_abs(dev, ABS_BRAKE,    (data[1] >> 2) & 0x3f);
				input_report_abs(dev, ABS_GAS,	    (data[1] >> 8) & 0x3f);
				input_report_abs(dev, ABS_THROTTLE, (data[2] >> 8) & 0x3f);

				input_report_abs(dev, ABS_HAT0X, ((data[2] >> 1) & 1) - ( data[2]       & 1));
				input_report_abs(dev, ABS_HAT0Y, ((data[2] >> 2) & 1) - ((data[2] >> 3) & 1));
				input_report_abs(dev, ABS_HAT1X, ((data[2] >> 5) & 1) - ((data[2] >> 4) & 1));
				input_report_abs(dev, ABS_HAT1Y, ((data[2] >> 6) & 1) - ((data[2] >> 7) & 1));

				for (j = 0; j < 11; j++)
					input_report_key(dev, grip_btn_xt[j], (data[3] >> (j + 3)) & 1);
				break;

			case GRIP_MODE_DC:

				if (grip_xt_read_packet(grip->gameport, (i << 1) + 4, data)) {
					grip->bads++;
					break;
				}

				input_report_abs(dev, ABS_X,        (data[0] >> 2) & 0x3f);
				input_report_abs(dev, ABS_Y,        (data[0] >> 8) & 0x3f);
				input_report_abs(dev, ABS_RX,       (data[1] >> 2) & 0x3f);
				input_report_abs(dev, ABS_RY,	    (data[1] >> 8) & 0x3f);
				input_report_abs(dev, ABS_THROTTLE, (data[2] >> 8) & 0x3f);

				input_report_abs(dev, ABS_HAT0X, ((data[2] >> 1) & 1) - ( data[2]       & 1));
				input_report_abs(dev, ABS_HAT0Y, ((data[2] >> 2) & 1) - ((data[2] >> 3) & 1));

				for (j = 0; j < 9; j++)
					input_report_key(dev, grip_btn_dc[j], (data[3] >> (j + 3)) & 1);
				break;


		}

		input_sync(dev);
	}
}

__attribute__((used)) static int grip_open(struct input_dev *dev)
{
	struct grip *grip = input_get_drvdata(dev);

	gameport_start_polling(grip->gameport);
	return 0;
}

__attribute__((used)) static void grip_close(struct input_dev *dev)
{
	struct grip *grip = input_get_drvdata(dev);

	gameport_stop_polling(grip->gameport);
}

__attribute__((used)) static int grip_connect(struct gameport *gameport, struct gameport_driver *drv)
{
	struct grip *grip;
	struct input_dev *input_dev;
	unsigned int data[GRIP_LENGTH_XT];
	int i, j, t;
	int err;

	if (!(grip = kzalloc(sizeof(struct grip), GFP_KERNEL)))
		return -ENOMEM;

	grip->gameport = gameport;

	gameport_set_drvdata(gameport, grip);

	err = gameport_open(gameport, drv, GAMEPORT_MODE_RAW);
	if (err)
		goto fail1;

	for (i = 0; i < 2; i++) {
		if (!grip_gpp_read_packet(gameport, (i << 1) + 4, data)) {
			grip->mode[i] = GRIP_MODE_GPP;
			continue;
		}
		if (!grip_xt_read_packet(gameport, (i << 1) + 4, data)) {
			if (!(data[3] & 7)) {
				grip->mode[i] = GRIP_MODE_BD;
				continue;
			}
			if (!(data[2] & 0xf0)) {
				grip->mode[i] = GRIP_MODE_XT;
				continue;
			}
			grip->mode[i] = GRIP_MODE_DC;
			continue;
		}
	}

	if (!grip->mode[0] && !grip->mode[1]) {
		err = -ENODEV;
		goto fail2;
	}

	gameport_set_poll_handler(gameport, grip_poll);
	gameport_set_poll_interval(gameport, 20);

	for (i = 0; i < 2; i++) {
		if (!grip->mode[i])
			continue;

		grip->dev[i] = input_dev = input_allocate_device();
		if (!input_dev) {
			err = -ENOMEM;
			goto fail3;
		}

		snprintf(grip->phys[i], sizeof(grip->phys[i]),
			 "%s/input%d", gameport->phys, i);

		input_dev->name = grip_name[grip->mode[i]];
		input_dev->phys = grip->phys[i];
		input_dev->id.bustype = BUS_GAMEPORT;
		input_dev->id.vendor = GAMEPORT_ID_VENDOR_GRAVIS;
		input_dev->id.product = grip->mode[i];
		input_dev->id.version = 0x0100;
		input_dev->dev.parent = &gameport->dev;

		input_set_drvdata(input_dev, grip);

		input_dev->open = grip_open;
		input_dev->close = grip_close;

		input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);

		for (j = 0; (t = grip_abs[grip->mode[i]][j]) >= 0; j++) {

			if (j < grip_cen[grip->mode[i]])
				input_set_abs_params(input_dev, t, 14, 52, 1, 2);
			else if (j < grip_anx[grip->mode[i]])
				input_set_abs_params(input_dev, t, 3, 57, 1, 0);
			else
				input_set_abs_params(input_dev, t, -1, 1, 0, 0);
		}

		for (j = 0; (t = grip_btn[grip->mode[i]][j]) >= 0; j++)
			if (t > 0)
				set_bit(t, input_dev->keybit);

		err = input_register_device(grip->dev[i]);
		if (err)
			goto fail4;
	}

	return 0;

 fail4:	input_free_device(grip->dev[i]);
 fail3:	while (--i >= 0)
		if (grip->dev[i])
			input_unregister_device(grip->dev[i]);
 fail2:	gameport_close(gameport);
 fail1:	gameport_set_drvdata(gameport, NULL);
	kfree(grip);
	return err;
}

__attribute__((used)) static void grip_disconnect(struct gameport *gameport)
{
	struct grip *grip = gameport_get_drvdata(gameport);
	int i;

	for (i = 0; i < 2; i++)
		if (grip->dev[i])
			input_unregister_device(grip->dev[i]);
	gameport_close(gameport);
	gameport_set_drvdata(gameport, NULL);
	kfree(grip);
}

