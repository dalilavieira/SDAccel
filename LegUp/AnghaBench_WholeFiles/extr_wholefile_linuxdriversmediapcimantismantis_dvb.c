#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_41__   TYPE_5__ ;
typedef  struct TYPE_40__   TYPE_4__ ;
typedef  struct TYPE_39__   TYPE_3__ ;
typedef  struct TYPE_38__   TYPE_31__ ;
typedef  struct TYPE_37__   TYPE_2__ ;
typedef  struct TYPE_36__   TYPE_28__ ;
typedef  struct TYPE_35__   TYPE_21__ ;
typedef  struct TYPE_34__   TYPE_1__ ;
typedef  struct TYPE_33__   TYPE_12__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_35__ {struct mantis_pci* priv; } ;
struct TYPE_40__ {int capabilities; int (* add_frontend ) (TYPE_4__*,TYPE_5__*) ;int (* connect_frontend ) (TYPE_4__*,TYPE_5__*) ;int /*<<< orphan*/  (* remove_frontend ) (TYPE_4__*,TYPE_5__*) ;} ;
struct TYPE_38__ {int filternum; int feednum; int (* start_feed ) (struct dvb_demux_feed*) ;int (* stop_feed ) (struct dvb_demux_feed*) ;TYPE_4__ dmx; int /*<<< orphan*/ * write_to_decoder; struct mantis_pci* priv; } ;
struct TYPE_36__ {int filternum; scalar_t__ capabilities; TYPE_4__* demux; } ;
struct TYPE_41__ {int /*<<< orphan*/  source; } ;
struct mantis_pci {int feeds; TYPE_21__ dvb_adapter; TYPE_31__ demux; TYPE_28__ dmxdev; TYPE_5__ fe_hw; TYPE_5__ fe_mem; int /*<<< orphan*/  dvbnet; int /*<<< orphan*/  tasklet; TYPE_12__* fe; struct mantis_hwconfig* hwconfig; TYPE_2__* pdev; int /*<<< orphan*/  intmask_lock; } ;
struct mantis_hwconfig {int (* frontend_init ) (struct mantis_pci*,TYPE_12__*) ;int /*<<< orphan*/  reset; int /*<<< orphan*/  power; } ;
struct dvb_demux_feed {struct dvb_demux* demux; } ;
struct TYPE_34__ {int /*<<< orphan*/  frontend; } ;
struct dvb_demux {TYPE_1__ dmx; struct mantis_pci* priv; } ;
typedef  enum mantis_power { ____Placeholder_mantis_power } mantis_power ;
struct TYPE_39__ {int /*<<< orphan*/  (* release ) (TYPE_12__*) ;} ;
struct TYPE_37__ {int /*<<< orphan*/  dev; } ;
struct TYPE_33__ {TYPE_3__ ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMX_FRONTEND_0 ; 
 int DMX_MEMORY_BASED_FILTERING ; 
 int /*<<< orphan*/  DMX_MEMORY_FE ; 
 int DMX_SECTION_FILTERING ; 
 int DMX_TS_FILTERING ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  MANTIS_DEBUG ; 
 int /*<<< orphan*/  MANTIS_ERROR ; 
 int /*<<< orphan*/  MANTIS_INT_MASK ; 
#define  POWER_OFF 129 
#define  POWER_ON 128 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  adapter_nr ; 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int,char*,...) ; 
 int dvb_dmx_init (TYPE_31__*) ; 
 int /*<<< orphan*/  dvb_dmx_release (TYPE_31__*) ; 
 int dvb_dmxdev_init (TYPE_28__*,TYPE_21__*) ; 
 int /*<<< orphan*/  dvb_dmxdev_release (TYPE_28__*) ; 
 int /*<<< orphan*/  dvb_frontend_detach (TYPE_12__*) ; 
 int /*<<< orphan*/  dvb_net_init (TYPE_21__*,int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  dvb_net_release (int /*<<< orphan*/ *) ; 
 int dvb_register_adapter (TYPE_21__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int dvb_register_frontend (TYPE_21__*,TYPE_12__*) ; 
 int /*<<< orphan*/  dvb_unregister_adapter (TYPE_21__*) ; 
 int /*<<< orphan*/  dvb_unregister_frontend (TYPE_12__*) ; 
 int /*<<< orphan*/  mantis_dma_start (struct mantis_pci*) ; 
 int /*<<< orphan*/  mantis_dma_stop (struct mantis_pci*) ; 
 int /*<<< orphan*/  mantis_dma_xfer ; 
 int /*<<< orphan*/  mantis_gpio_set_bits (struct mantis_pci*,int /*<<< orphan*/ ,int const) ; 
 int mmread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmwrite (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int stub1 (TYPE_4__*,TYPE_5__*) ; 
 int stub2 (TYPE_4__*,TYPE_5__*) ; 
 int stub3 (TYPE_4__*,TYPE_5__*) ; 
 int stub4 (struct mantis_pci*,TYPE_12__*) ; 
 int /*<<< orphan*/  stub5 (TYPE_12__*) ; 
 int /*<<< orphan*/  stub6 (TYPE_4__*,TYPE_5__*) ; 
 int /*<<< orphan*/  stub7 (TYPE_4__*,TYPE_5__*) ; 
 int /*<<< orphan*/  stub8 (TYPE_4__*,TYPE_5__*) ; 
 int /*<<< orphan*/  stub9 (TYPE_4__*,TYPE_5__*) ; 
 int /*<<< orphan*/  tasklet_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tasklet_enable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tasklet_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  tasklet_kill (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void mantis_mask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) & ~mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

__attribute__((used)) static inline void mantis_unmask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) | mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

int mantis_frontend_power(struct mantis_pci *mantis, enum mantis_power power)
{
	struct mantis_hwconfig *config = mantis->hwconfig;

	switch (power) {
	case POWER_ON:
		dprintk(MANTIS_DEBUG, 1, "Power ON");
		mantis_gpio_set_bits(mantis, config->power, POWER_ON);
		msleep(100);
		mantis_gpio_set_bits(mantis, config->power, POWER_ON);
		msleep(100);
		break;

	case POWER_OFF:
		dprintk(MANTIS_DEBUG, 1, "Power OFF");
		mantis_gpio_set_bits(mantis, config->power, POWER_OFF);
		msleep(100);
		break;

	default:
		dprintk(MANTIS_DEBUG, 1, "Unknown state <%02x>", power);
		return -1;
	}

	return 0;
}

void mantis_frontend_soft_reset(struct mantis_pci *mantis)
{
	struct mantis_hwconfig *config = mantis->hwconfig;

	dprintk(MANTIS_DEBUG, 1, "Frontend RESET");
	mantis_gpio_set_bits(mantis, config->reset, 0);
	msleep(100);
	mantis_gpio_set_bits(mantis, config->reset, 0);
	msleep(100);
	mantis_gpio_set_bits(mantis, config->reset, 1);
	msleep(100);
	mantis_gpio_set_bits(mantis, config->reset, 1);
	msleep(100);

	return;
}

__attribute__((used)) static int mantis_frontend_shutdown(struct mantis_pci *mantis)
{
	int err;

	mantis_frontend_soft_reset(mantis);
	err = mantis_frontend_power(mantis, POWER_OFF);
	if (err != 0) {
		dprintk(MANTIS_ERROR, 1, "Frontend POWER OFF failed! <%d>", err);
		return 1;
	}

	return 0;
}

__attribute__((used)) static int mantis_dvb_start_feed(struct dvb_demux_feed *dvbdmxfeed)
{
	struct dvb_demux *dvbdmx = dvbdmxfeed->demux;
	struct mantis_pci *mantis = dvbdmx->priv;

	dprintk(MANTIS_DEBUG, 1, "Mantis DVB Start feed");
	if (!dvbdmx->dmx.frontend) {
		dprintk(MANTIS_DEBUG, 1, "no frontend ?");
		return -EINVAL;
	}

	mantis->feeds++;
	dprintk(MANTIS_DEBUG, 1, "mantis start feed, feeds=%d",	mantis->feeds);

	if (mantis->feeds == 1)	 {
		dprintk(MANTIS_DEBUG, 1, "mantis start feed & dma");
		mantis_dma_start(mantis);
		tasklet_enable(&mantis->tasklet);
	}

	return mantis->feeds;
}

__attribute__((used)) static int mantis_dvb_stop_feed(struct dvb_demux_feed *dvbdmxfeed)
{
	struct dvb_demux *dvbdmx = dvbdmxfeed->demux;
	struct mantis_pci *mantis = dvbdmx->priv;

	dprintk(MANTIS_DEBUG, 1, "Mantis DVB Stop feed");
	if (!dvbdmx->dmx.frontend) {
		dprintk(MANTIS_DEBUG, 1, "no frontend ?");
		return -EINVAL;
	}

	mantis->feeds--;
	if (mantis->feeds == 0) {
		dprintk(MANTIS_DEBUG, 1, "mantis stop feed and dma");
		tasklet_disable(&mantis->tasklet);
		mantis_dma_stop(mantis);
	}

	return 0;
}

int mantis_dvb_init(struct mantis_pci *mantis)
{
	struct mantis_hwconfig *config = mantis->hwconfig;
	int result = -1;

	dprintk(MANTIS_DEBUG, 1, "dvb_register_adapter");

	result = dvb_register_adapter(&mantis->dvb_adapter,
				      "Mantis DVB adapter",
				      THIS_MODULE,
				      &mantis->pdev->dev,
				      adapter_nr);

	if (result < 0) {

		dprintk(MANTIS_ERROR, 1, "Error registering adapter");
		return -ENODEV;
	}

	mantis->dvb_adapter.priv	= mantis;
	mantis->demux.dmx.capabilities	= DMX_TS_FILTERING	|
					 DMX_SECTION_FILTERING	|
					 DMX_MEMORY_BASED_FILTERING;

	mantis->demux.priv		= mantis;
	mantis->demux.filternum		= 256;
	mantis->demux.feednum		= 256;
	mantis->demux.start_feed	= mantis_dvb_start_feed;
	mantis->demux.stop_feed		= mantis_dvb_stop_feed;
	mantis->demux.write_to_decoder	= NULL;

	dprintk(MANTIS_DEBUG, 1, "dvb_dmx_init");
	result = dvb_dmx_init(&mantis->demux);
	if (result < 0) {
		dprintk(MANTIS_ERROR, 1, "dvb_dmx_init failed, ERROR=%d", result);

		goto err0;
	}

	mantis->dmxdev.filternum	= 256;
	mantis->dmxdev.demux		= &mantis->demux.dmx;
	mantis->dmxdev.capabilities	= 0;
	dprintk(MANTIS_DEBUG, 1, "dvb_dmxdev_init");

	result = dvb_dmxdev_init(&mantis->dmxdev, &mantis->dvb_adapter);
	if (result < 0) {

		dprintk(MANTIS_ERROR, 1, "dvb_dmxdev_init failed, ERROR=%d", result);
		goto err1;
	}

	mantis->fe_hw.source		= DMX_FRONTEND_0;
	result = mantis->demux.dmx.add_frontend(&mantis->demux.dmx, &mantis->fe_hw);
	if (result < 0) {

		dprintk(MANTIS_ERROR, 1, "dvb_dmx_init failed, ERROR=%d", result);
		goto err2;
	}

	mantis->fe_mem.source		= DMX_MEMORY_FE;
	result = mantis->demux.dmx.add_frontend(&mantis->demux.dmx, &mantis->fe_mem);
	if (result < 0) {
		dprintk(MANTIS_ERROR, 1, "dvb_dmx_init failed, ERROR=%d", result);
		goto err3;
	}

	result = mantis->demux.dmx.connect_frontend(&mantis->demux.dmx, &mantis->fe_hw);
	if (result < 0) {
		dprintk(MANTIS_ERROR, 1, "dvb_dmx_init failed, ERROR=%d", result);
		goto err4;
	}

	dvb_net_init(&mantis->dvb_adapter, &mantis->dvbnet, &mantis->demux.dmx);
	tasklet_init(&mantis->tasklet, mantis_dma_xfer, (unsigned long) mantis);
	tasklet_disable(&mantis->tasklet);
	if (mantis->hwconfig) {
		result = config->frontend_init(mantis, mantis->fe);
		if (result < 0) {
			dprintk(MANTIS_ERROR, 1, "!!! NO Frontends found !!!");
			goto err5;
		} else {
			if (mantis->fe == NULL) {
				result = -ENOMEM;
				dprintk(MANTIS_ERROR, 1, "FE <NULL>");
				goto err5;
			}
			result = dvb_register_frontend(&mantis->dvb_adapter, mantis->fe);
			if (result) {
				dprintk(MANTIS_ERROR, 1, "ERROR: Frontend registration failed");

				if (mantis->fe->ops.release)
					mantis->fe->ops.release(mantis->fe);

				mantis->fe = NULL;
				goto err5;
			}
		}
	}

	return 0;

	/* Error conditions ..	*/
err5:
	tasklet_kill(&mantis->tasklet);
	dvb_net_release(&mantis->dvbnet);
	if (mantis->fe) {
		dvb_unregister_frontend(mantis->fe);
		dvb_frontend_detach(mantis->fe);
	}
err4:
	mantis->demux.dmx.remove_frontend(&mantis->demux.dmx, &mantis->fe_mem);

err3:
	mantis->demux.dmx.remove_frontend(&mantis->demux.dmx, &mantis->fe_hw);

err2:
	dvb_dmxdev_release(&mantis->dmxdev);

err1:
	dvb_dmx_release(&mantis->demux);

err0:
	dvb_unregister_adapter(&mantis->dvb_adapter);

	return result;
}

int mantis_dvb_exit(struct mantis_pci *mantis)
{
	int err;

	if (mantis->fe) {
		/* mantis_ca_exit(mantis); */
		err = mantis_frontend_shutdown(mantis);
		if (err != 0)
			dprintk(MANTIS_ERROR, 1, "Frontend exit while POWER ON! <%d>", err);
		dvb_unregister_frontend(mantis->fe);
		dvb_frontend_detach(mantis->fe);
	}

	tasklet_kill(&mantis->tasklet);
	dvb_net_release(&mantis->dvbnet);

	mantis->demux.dmx.remove_frontend(&mantis->demux.dmx, &mantis->fe_mem);
	mantis->demux.dmx.remove_frontend(&mantis->demux.dmx, &mantis->fe_hw);

	dvb_dmxdev_release(&mantis->dmxdev);
	dvb_dmx_release(&mantis->demux);

	dprintk(MANTIS_DEBUG, 1, "dvb_unregister_adapter");
	dvb_unregister_adapter(&mantis->dvb_adapter);

	return 0;
}

