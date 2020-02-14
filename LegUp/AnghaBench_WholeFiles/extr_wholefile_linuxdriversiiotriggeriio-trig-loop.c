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
struct iio_trigger {int /*<<< orphan*/ * ops; int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct iio_sw_trigger {struct iio_trigger* trigger; } ;
struct iio_loop_info {struct iio_sw_trigger swt; int /*<<< orphan*/  task; } ;

/* Variables and functions */
 int ENOMEM ; 
 struct iio_sw_trigger* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  iio_loop_trigger_ops ; 
 int /*<<< orphan*/  iio_loop_type ; 
 int /*<<< orphan*/  iio_swt_group_init_type_name (struct iio_sw_trigger*,char const*,int /*<<< orphan*/ *) ; 
 struct iio_trigger* iio_trigger_alloc (char*,char const*) ; 
 int /*<<< orphan*/  iio_trigger_free (struct iio_trigger*) ; 
 struct iio_loop_info* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_poll_chained (struct iio_trigger*) ; 
 int iio_trigger_register (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (struct iio_trigger*,struct iio_loop_info*) ; 
 int /*<<< orphan*/  iio_trigger_unregister (struct iio_trigger*) ; 
 int /*<<< orphan*/  kfree (struct iio_loop_info*) ; 
 int /*<<< orphan*/  kthread_freezable_should_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kthread_run (int (*) (void*),struct iio_trigger*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kthread_stop (int /*<<< orphan*/ ) ; 
 struct iio_loop_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  set_freezable () ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int iio_loop_thread(void *data)
{
	struct iio_trigger *trig = data;

	set_freezable();

	do {
		iio_trigger_poll_chained(trig);
	} while (likely(!kthread_freezable_should_stop(NULL)));

	return 0;
}

__attribute__((used)) static int iio_loop_trigger_set_state(struct iio_trigger *trig, bool state)
{
	struct iio_loop_info *loop_trig = iio_trigger_get_drvdata(trig);

	if (state) {
		loop_trig->task = kthread_run(iio_loop_thread,
					      trig, trig->name);
		if (unlikely(IS_ERR(loop_trig->task))) {
			dev_err(&trig->dev,
				"failed to create trigger loop thread\n");
			return PTR_ERR(loop_trig->task);
		}
	} else {
		kthread_stop(loop_trig->task);
	}

	return 0;
}

__attribute__((used)) static struct iio_sw_trigger *iio_trig_loop_probe(const char *name)
{
	struct iio_loop_info *trig_info;
	int ret;

	trig_info = kzalloc(sizeof(*trig_info), GFP_KERNEL);
	if (!trig_info)
		return ERR_PTR(-ENOMEM);

	trig_info->swt.trigger = iio_trigger_alloc("%s", name);
	if (!trig_info->swt.trigger) {
		ret = -ENOMEM;
		goto err_free_trig_info;
	}

	iio_trigger_set_drvdata(trig_info->swt.trigger, trig_info);
	trig_info->swt.trigger->ops = &iio_loop_trigger_ops;

	ret = iio_trigger_register(trig_info->swt.trigger);
	if (ret)
		goto err_free_trigger;

	iio_swt_group_init_type_name(&trig_info->swt, name, &iio_loop_type);

	return &trig_info->swt;

err_free_trigger:
	iio_trigger_free(trig_info->swt.trigger);
err_free_trig_info:
	kfree(trig_info);

	return ERR_PTR(ret);
}

__attribute__((used)) static int iio_trig_loop_remove(struct iio_sw_trigger *swt)
{
	struct iio_loop_info *trig_info;

	trig_info = iio_trigger_get_drvdata(swt->trigger);

	iio_trigger_unregister(swt->trigger);
	iio_trigger_free(swt->trigger);
	kfree(trig_info);

	return 0;
}

