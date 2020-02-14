#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_20__ ;
typedef  struct TYPE_24__   TYPE_1__ ;
typedef  struct TYPE_23__   TYPE_18__ ;
typedef  struct TYPE_22__   TYPE_17__ ;

/* Type definitions */
struct TYPE_27__ {int capabilities; int (* add_frontend ) (TYPE_3__*,TYPE_4__*) ;int (* connect_frontend ) (TYPE_3__*,TYPE_4__*) ;int /*<<< orphan*/  (* remove_frontend ) (TYPE_3__*,TYPE_4__*) ;} ;
struct TYPE_25__ {TYPE_3__ dmx; void* filternum; int /*<<< orphan*/ * write_to_decoder; void* stop_feed; void* start_feed; void* feednum; struct stdemux* priv; } ;
struct TYPE_23__ {scalar_t__ capabilities; TYPE_3__* demux; void* filternum; } ;
struct TYPE_28__ {int source; } ;
struct stdemux {int tsin_index; struct c8sectpfei* c8sectpfei; TYPE_20__ dvb_demux; TYPE_18__ dmxdev; TYPE_4__ hw_frontend; TYPE_4__ mem_frontend; } ;
struct dvb_frontend {int dummy; } ;
struct dvb_adapter {struct c8sectpfei* priv; } ;
struct channel_info {struct dvb_frontend* frontend; TYPE_17__* i2c_client; int /*<<< orphan*/  i2c_adapter; } ;
struct c8sectpfei {int tsin_count; int /*<<< orphan*/  dev; struct channel_info** channel_data; } ;
struct c8sectpfe {int num_feeds; struct dvb_adapter adapter; struct stdemux* demux; int /*<<< orphan*/  device; int /*<<< orphan*/  lock; } ;
struct TYPE_26__ {TYPE_1__* driver; } ;
struct TYPE_24__ {int /*<<< orphan*/  owner; } ;
struct TYPE_22__ {TYPE_2__ dev; } ;

/* Variables and functions */
 void* C8SECTPFE_MAXCHANNEL ; 
 int DMX_FRONTEND_0 ; 
 int DMX_MEMORY_BASED_FILTERING ; 
 int DMX_MEMORY_FE ; 
 int DMX_SECTION_FILTERING ; 
 int DMX_TS_FILTERING ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int c8sectpfe_frontend_attach (struct dvb_frontend**,struct c8sectpfe*,struct channel_info*,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int,...) ; 
 int dvb_dmx_init (TYPE_20__*) ; 
 int /*<<< orphan*/  dvb_dmx_release (TYPE_20__*) ; 
 int dvb_dmxdev_init (TYPE_18__*,struct dvb_adapter*) ; 
 int /*<<< orphan*/  dvb_dmxdev_release (TYPE_18__*) ; 
 int /*<<< orphan*/  dvb_frontend_detach (struct dvb_frontend*) ; 
 int dvb_register_adapter (struct dvb_adapter*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,short*) ; 
 int dvb_register_frontend (struct dvb_adapter*,struct dvb_frontend*) ; 
 int /*<<< orphan*/  dvb_unregister_adapter (struct dvb_adapter*) ; 
 int /*<<< orphan*/  dvb_unregister_frontend (struct dvb_frontend*) ; 
 int /*<<< orphan*/  i2c_put_adapter (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_unregister_device (TYPE_17__*) ; 
 int /*<<< orphan*/  kfree (struct c8sectpfe*) ; 
 struct c8sectpfe* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int stub1 (TYPE_3__*,TYPE_4__*) ; 
 int stub2 (TYPE_3__*,TYPE_4__*) ; 
 int stub3 (TYPE_3__*,TYPE_4__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_3__*,TYPE_4__*) ; 
 int /*<<< orphan*/  stub5 (TYPE_3__*,TYPE_4__*) ; 
 int /*<<< orphan*/  stub6 (TYPE_3__*,TYPE_4__*) ; 
 int /*<<< orphan*/  stub7 (TYPE_3__*,TYPE_4__*) ; 

__attribute__((used)) static int register_dvb(struct stdemux *demux, struct dvb_adapter *adap,
				void *start_feed, void *stop_feed,
				struct c8sectpfei *fei)
{
	int result;

	demux->dvb_demux.dmx.capabilities = DMX_TS_FILTERING |
					DMX_SECTION_FILTERING |
					DMX_MEMORY_BASED_FILTERING;

	demux->dvb_demux.priv = demux;
	demux->dvb_demux.filternum = C8SECTPFE_MAXCHANNEL;
	demux->dvb_demux.feednum = C8SECTPFE_MAXCHANNEL;

	demux->dvb_demux.start_feed = start_feed;
	demux->dvb_demux.stop_feed = stop_feed;
	demux->dvb_demux.write_to_decoder = NULL;

	result = dvb_dmx_init(&demux->dvb_demux);
	if (result < 0) {
		dev_err(fei->dev, "dvb_dmx_init failed (errno = %d)\n",
			result);
		goto err_dmx;
	}

	demux->dmxdev.filternum = demux->dvb_demux.filternum;
	demux->dmxdev.demux = &demux->dvb_demux.dmx;
	demux->dmxdev.capabilities = 0;

	result = dvb_dmxdev_init(&demux->dmxdev, adap);
	if (result < 0) {
		dev_err(fei->dev, "dvb_dmxdev_init failed (errno = %d)\n",
			result);

		goto err_dmxdev;
	}

	demux->hw_frontend.source = DMX_FRONTEND_0 + demux->tsin_index;

	result = demux->dvb_demux.dmx.add_frontend(&demux->dvb_demux.dmx,
						&demux->hw_frontend);
	if (result < 0) {
		dev_err(fei->dev, "add_frontend failed (errno = %d)\n", result);
		goto err_fe_hw;
	}

	demux->mem_frontend.source = DMX_MEMORY_FE;
	result = demux->dvb_demux.dmx.add_frontend(&demux->dvb_demux.dmx,
						&demux->mem_frontend);
	if (result < 0) {
		dev_err(fei->dev, "add_frontend failed (%d)\n", result);
		goto err_fe_mem;
	}

	result = demux->dvb_demux.dmx.connect_frontend(&demux->dvb_demux.dmx,
							&demux->hw_frontend);
	if (result < 0) {
		dev_err(fei->dev, "connect_frontend (%d)\n", result);
		goto err_fe_con;
	}

	return 0;

err_fe_con:
	demux->dvb_demux.dmx.remove_frontend(&demux->dvb_demux.dmx,
						     &demux->mem_frontend);
err_fe_mem:
	demux->dvb_demux.dmx.remove_frontend(&demux->dvb_demux.dmx,
						     &demux->hw_frontend);
err_fe_hw:
	dvb_dmxdev_release(&demux->dmxdev);
err_dmxdev:
	dvb_dmx_release(&demux->dvb_demux);
err_dmx:
	return result;

}

__attribute__((used)) static void unregister_dvb(struct stdemux *demux)
{

	demux->dvb_demux.dmx.remove_frontend(&demux->dvb_demux.dmx,
						     &demux->mem_frontend);

	demux->dvb_demux.dmx.remove_frontend(&demux->dvb_demux.dmx,
						     &demux->hw_frontend);

	dvb_dmxdev_release(&demux->dmxdev);

	dvb_dmx_release(&demux->dvb_demux);
}

__attribute__((used)) static struct c8sectpfe *c8sectpfe_create(struct c8sectpfei *fei,
				void *start_feed,
				void *stop_feed)
{
	struct c8sectpfe *c8sectpfe;
	int result;
	int i, j;

	short int ids[] = { -1 };

	c8sectpfe = kzalloc(sizeof(struct c8sectpfe), GFP_KERNEL);
	if (!c8sectpfe)
		goto err1;

	mutex_init(&c8sectpfe->lock);

	c8sectpfe->device = fei->dev;

	result = dvb_register_adapter(&c8sectpfe->adapter, "STi c8sectpfe",
					THIS_MODULE, fei->dev, ids);
	if (result < 0) {
		dev_err(fei->dev, "dvb_register_adapter failed (errno = %d)\n",
			result);
		goto err2;
	}

	c8sectpfe->adapter.priv = fei;

	for (i = 0; i < fei->tsin_count; i++) {

		c8sectpfe->demux[i].tsin_index = i;
		c8sectpfe->demux[i].c8sectpfei = fei;

		result = register_dvb(&c8sectpfe->demux[i], &c8sectpfe->adapter,
				start_feed, stop_feed, fei);
		if (result < 0) {
			dev_err(fei->dev,
				"register_dvb feed=%d failed (errno = %d)\n",
				result, i);

			/* we take a all or nothing approach */
			for (j = 0; j < i; j++)
				unregister_dvb(&c8sectpfe->demux[j]);
			goto err3;
		}
	}

	c8sectpfe->num_feeds = fei->tsin_count;

	return c8sectpfe;
err3:
	dvb_unregister_adapter(&c8sectpfe->adapter);
err2:
	kfree(c8sectpfe);
err1:
	return NULL;
}

__attribute__((used)) static void c8sectpfe_delete(struct c8sectpfe *c8sectpfe)
{
	int i;

	if (!c8sectpfe)
		return;

	for (i = 0; i < c8sectpfe->num_feeds; i++)
		unregister_dvb(&c8sectpfe->demux[i]);

	dvb_unregister_adapter(&c8sectpfe->adapter);

	kfree(c8sectpfe);
}

void c8sectpfe_tuner_unregister_frontend(struct c8sectpfe *c8sectpfe,
					struct c8sectpfei *fei)
{
	int n;
	struct channel_info *tsin;

	for (n = 0; n < fei->tsin_count; n++) {

		tsin = fei->channel_data[n];

		if (tsin) {
			if (tsin->frontend) {
				dvb_unregister_frontend(tsin->frontend);
				dvb_frontend_detach(tsin->frontend);
			}

			i2c_put_adapter(tsin->i2c_adapter);

			if (tsin->i2c_client) {
				module_put(tsin->i2c_client->dev.driver->owner);
				i2c_unregister_device(tsin->i2c_client);
			}
		}
	}

	c8sectpfe_delete(c8sectpfe);
}

int c8sectpfe_tuner_register_frontend(struct c8sectpfe **c8sectpfe,
				struct c8sectpfei *fei,
				void *start_feed,
				void *stop_feed)
{
	struct channel_info *tsin;
	struct dvb_frontend *frontend;
	int n, res;

	*c8sectpfe = c8sectpfe_create(fei, start_feed, stop_feed);
	if (!*c8sectpfe)
		return -ENOMEM;

	for (n = 0; n < fei->tsin_count; n++) {
		tsin = fei->channel_data[n];

		res = c8sectpfe_frontend_attach(&frontend, *c8sectpfe, tsin, n);
		if (res)
			goto err;

		res = dvb_register_frontend(&c8sectpfe[0]->adapter, frontend);
		if (res < 0) {
			dev_err(fei->dev, "dvb_register_frontend failed (%d)\n",
				res);
			goto err;
		}

		tsin->frontend = frontend;
	}

	return 0;

err:
	c8sectpfe_tuner_unregister_frontend(*c8sectpfe, fei);
	return res;
}

