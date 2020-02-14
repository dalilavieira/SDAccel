#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct pps_source_info {char* path; int mode; int /*<<< orphan*/ * dev; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; } ;
struct pps_event_time {int dummy; } ;
struct pps_client_pp {unsigned int cw; scalar_t__ cw_err; int index; TYPE_2__* pps; struct pardevice* pardev; } ;
struct parport {TYPE_1__* ops; struct pardevice* cad; int /*<<< orphan*/  name; } ;
struct pardevice {struct pps_client_pp* private; int /*<<< orphan*/  name; struct parport* port; } ;
struct pardev_cb {void (* irq_func ) (void*) ;int /*<<< orphan*/  flags; struct pps_client_pp* private; } ;
typedef  int /*<<< orphan*/  pps_client_cb ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {int (* read_status ) (struct parport*) ;int /*<<< orphan*/  (* disable_irq ) (struct parport*) ;int /*<<< orphan*/  (* enable_irq ) (struct parport*) ;} ;

/* Variables and functions */
 scalar_t__ CLEAR_WAIT_MAX_ERRORS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int /*<<< orphan*/  PARPORT_FLAG_EXCL ; 
 int PARPORT_STATUS_ACK ; 
 int PPS_CANWAIT ; 
 int /*<<< orphan*/  PPS_CAPTUREASSERT ; 
 int PPS_CAPTUREBOTH ; 
 int /*<<< orphan*/  PPS_CAPTURECLEAR ; 
 int PPS_ECHOASSERT ; 
 int PPS_ECHOCLEAR ; 
 int PPS_OFFSETASSERT ; 
 int PPS_OFFSETCLEAR ; 
 int PPS_TSFMT_TSPEC ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 unsigned int clear_wait ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int ida_simple_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ida_simple_remove (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  kfree (struct pps_client_pp*) ; 
 struct pps_client_pp* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  memset (struct pardev_cb*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ parport_claim_or_block (struct pardevice*) ; 
 struct pardevice* parport_register_dev_model (struct parport*,int /*<<< orphan*/ ,struct pardev_cb*,int) ; 
 int /*<<< orphan*/  parport_release (struct pardevice*) ; 
 int /*<<< orphan*/  parport_unregister_device (struct pardevice*) ; 
 int /*<<< orphan*/  pps_client_index ; 
 int /*<<< orphan*/  pps_event (TYPE_2__*,struct pps_event_time*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pps_get_ts (struct pps_event_time*) ; 
 TYPE_2__* pps_register_source (struct pps_source_info*,int) ; 
 int /*<<< orphan*/  pps_unregister_source (TYPE_2__*) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (struct parport*) ; 
 int /*<<< orphan*/  stub2 (struct parport*) ; 
 int /*<<< orphan*/  stub3 (struct parport*) ; 

__attribute__((used)) static inline int signal_is_set(struct parport *port)
{
	return (port->ops->read_status(port) & PARPORT_STATUS_ACK) != 0;
}

__attribute__((used)) static void parport_irq(void *handle)
{
	struct pps_event_time ts_assert, ts_clear;
	struct pps_client_pp *dev = handle;
	struct parport *port = dev->pardev->port;
	unsigned int i;
	unsigned long flags;

	/* first of all we get the time stamp... */
	pps_get_ts(&ts_assert);

	if (dev->cw == 0)
		/* clear edge capture disabled */
		goto out_assert;

	/* try capture the clear edge */

	/* We have to disable interrupts here. The idea is to prevent
	 * other interrupts on the same processor to introduce random
	 * lags while polling the port. Reading from IO port is known
	 * to take approximately 1us while other interrupt handlers can
	 * take much more potentially.
	 *
	 * Interrupts won't be disabled for a long time because the
	 * number of polls is limited by clear_wait parameter which is
	 * kept rather low. So it should never be an issue.
	 */
	local_irq_save(flags);
	/* check the signal (no signal means the pulse is lost this time) */
	if (!signal_is_set(port)) {
		local_irq_restore(flags);
		dev_err(dev->pps->dev, "lost the signal\n");
		goto out_assert;
	}

	/* poll the port until the signal is unset */
	for (i = dev->cw; i; i--)
		if (!signal_is_set(port)) {
			pps_get_ts(&ts_clear);
			local_irq_restore(flags);
			dev->cw_err = 0;
			goto out_both;
		}
	local_irq_restore(flags);

	/* timeout */
	dev->cw_err++;
	if (dev->cw_err >= CLEAR_WAIT_MAX_ERRORS) {
		dev_err(dev->pps->dev, "disabled clear edge capture after %d"
				" timeouts\n", dev->cw_err);
		dev->cw = 0;
		dev->cw_err = 0;
	}

out_assert:
	/* fire assert event */
	pps_event(dev->pps, &ts_assert,
			PPS_CAPTUREASSERT, NULL);
	return;

out_both:
	/* fire assert event */
	pps_event(dev->pps, &ts_assert,
			PPS_CAPTUREASSERT, NULL);
	/* fire clear event */
	pps_event(dev->pps, &ts_clear,
			PPS_CAPTURECLEAR, NULL);
	return;
}

__attribute__((used)) static void parport_attach(struct parport *port)
{
	struct pardev_cb pps_client_cb;
	int index;
	struct pps_client_pp *device;
	struct pps_source_info info = {
		.name		= KBUILD_MODNAME,
		.path		= "",
		.mode		= PPS_CAPTUREBOTH | \
				  PPS_OFFSETASSERT | PPS_OFFSETCLEAR | \
				  PPS_ECHOASSERT | PPS_ECHOCLEAR | \
				  PPS_CANWAIT | PPS_TSFMT_TSPEC,
		.owner		= THIS_MODULE,
		.dev		= NULL
	};

	device = kzalloc(sizeof(struct pps_client_pp), GFP_KERNEL);
	if (!device) {
		pr_err("memory allocation failed, not attaching\n");
		return;
	}

	index = ida_simple_get(&pps_client_index, 0, 0, GFP_KERNEL);
	memset(&pps_client_cb, 0, sizeof(pps_client_cb));
	pps_client_cb.private = device;
	pps_client_cb.irq_func = parport_irq;
	pps_client_cb.flags = PARPORT_FLAG_EXCL;
	device->pardev = parport_register_dev_model(port,
						    KBUILD_MODNAME,
						    &pps_client_cb,
						    index);
	if (!device->pardev) {
		pr_err("couldn't register with %s\n", port->name);
		goto err_free;
	}

	if (parport_claim_or_block(device->pardev) < 0) {
		pr_err("couldn't claim %s\n", port->name);
		goto err_unregister_dev;
	}

	device->pps = pps_register_source(&info,
			PPS_CAPTUREBOTH | PPS_OFFSETASSERT | PPS_OFFSETCLEAR);
	if (device->pps == NULL) {
		pr_err("couldn't register PPS source\n");
		goto err_release_dev;
	}

	device->cw = clear_wait;

	port->ops->enable_irq(port);
	device->index = index;

	pr_info("attached to %s\n", port->name);

	return;

err_release_dev:
	parport_release(device->pardev);
err_unregister_dev:
	parport_unregister_device(device->pardev);
err_free:
	ida_simple_remove(&pps_client_index, index);
	kfree(device);
}

__attribute__((used)) static void parport_detach(struct parport *port)
{
	struct pardevice *pardev = port->cad;
	struct pps_client_pp *device;

	/* FIXME: oooh, this is ugly! */
	if (!pardev || strcmp(pardev->name, KBUILD_MODNAME))
		/* not our port */
		return;

	device = pardev->private;

	port->ops->disable_irq(port);
	pps_unregister_source(device->pps);
	parport_release(pardev);
	parport_unregister_device(pardev);
	ida_simple_remove(&pps_client_index, device->index);
	kfree(device);
}

