#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_2__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int /*<<< orphan*/  evbit; TYPE_1__ id; } ;
struct device {int dummy; } ;
typedef  struct cma3000_platform_data {int mdthr; int mdfftmr; int ffthr; int mode; scalar_t__ g_range; int irqflags; int /*<<< orphan*/  fuzz_z; int /*<<< orphan*/  fuzz_y; int /*<<< orphan*/  fuzz_x; } const cma3000_platform_data ;
struct cma3000_bus_ops {int ctrl_mod; int /*<<< orphan*/  bustype; } ;
struct cma3000_accl_data {int bit_to_mg; scalar_t__ g_range; int mode; int suspended; int opened; int irq; struct input_dev* input_dev; int /*<<< orphan*/  mutex; struct cma3000_platform_data const* pdata; struct cma3000_bus_ops const* bus_ops; struct device* dev; } ;
typedef  int s8 ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_MISC ; 
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int /*<<< orphan*/  ABS_Z ; 
 int /*<<< orphan*/  CMA3000_CTRL ; 
 int /*<<< orphan*/  CMA3000_DOUTX ; 
 int /*<<< orphan*/  CMA3000_DOUTY ; 
 int /*<<< orphan*/  CMA3000_DOUTZ ; 
 int /*<<< orphan*/  CMA3000_FFTHR ; 
 int CMA3000_GRANGEMASK ; 
 int /*<<< orphan*/  CMA3000_INTSTATUS ; 
 int CMA3000_INTSTATUS_FFDET ; 
 int /*<<< orphan*/  CMA3000_MDFFTMR ; 
 int /*<<< orphan*/  CMA3000_MDTHR ; 
 int CMA3000_MODEMASK ; 
 int CMA3000_RANGE2G ; 
 int CMA3000_RANGE8G ; 
 int CMA3000_READ (struct cma3000_accl_data*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  CMA3000_REVID ; 
 int /*<<< orphan*/  CMA3000_RSTR ; 
 int CMA3000_SET (struct cma3000_accl_data*,int /*<<< orphan*/ ,int,char*) ; 
 int /*<<< orphan*/  CMA3000_SETDELAY ; 
 int /*<<< orphan*/  CMA3000_STATUS ; 
 int CMA3000_STATUS_PERR ; 
 int CMAMODE_MOTDET ; 
 int CMAMODE_POFF ; 
 scalar_t__ CMARANGE_2G ; 
 scalar_t__ CMARANGE_8G ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 struct cma3000_accl_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct cma3000_platform_data const* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  free_irq (int,struct cma3000_accl_data*) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 struct cma3000_accl_data* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct cma3000_accl_data*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct cma3000_accl_data*) ; 
 struct cma3000_accl_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int** mode_to_mg ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*,int) ; 
 int request_threaded_irq (int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct cma3000_accl_data*) ; 

__attribute__((used)) static void decode_mg(struct cma3000_accl_data *data, int *datax,
				int *datay, int *dataz)
{
	/* Data in 2's complement, convert to mg */
	*datax = ((s8)*datax) * data->bit_to_mg;
	*datay = ((s8)*datay) * data->bit_to_mg;
	*dataz = ((s8)*dataz) * data->bit_to_mg;
}

__attribute__((used)) static irqreturn_t cma3000_thread_irq(int irq, void *dev_id)
{
	struct cma3000_accl_data *data = dev_id;
	int datax, datay, dataz, intr_status;
	u8 ctrl, mode, range;

	intr_status = CMA3000_READ(data, CMA3000_INTSTATUS, "interrupt status");
	if (intr_status < 0)
		return IRQ_NONE;

	/* Check if free fall is detected, report immediately */
	if (intr_status & CMA3000_INTSTATUS_FFDET) {
		input_report_abs(data->input_dev, ABS_MISC, 1);
		input_sync(data->input_dev);
	} else {
		input_report_abs(data->input_dev, ABS_MISC, 0);
	}

	datax = CMA3000_READ(data, CMA3000_DOUTX, "X");
	datay = CMA3000_READ(data, CMA3000_DOUTY, "Y");
	dataz = CMA3000_READ(data, CMA3000_DOUTZ, "Z");

	ctrl = CMA3000_READ(data, CMA3000_CTRL, "ctrl");
	mode = (ctrl & CMA3000_MODEMASK) >> 1;
	range = (ctrl & CMA3000_GRANGEMASK) >> 7;

	data->bit_to_mg = mode_to_mg[mode][range];

	/* Interrupt not for this device */
	if (data->bit_to_mg == 0)
		return IRQ_NONE;

	/* Decode register values to milli g */
	decode_mg(data, &datax, &datay, &dataz);

	input_report_abs(data->input_dev, ABS_X, datax);
	input_report_abs(data->input_dev, ABS_Y, datay);
	input_report_abs(data->input_dev, ABS_Z, dataz);
	input_sync(data->input_dev);

	return IRQ_HANDLED;
}

__attribute__((used)) static int cma3000_reset(struct cma3000_accl_data *data)
{
	int val;

	/* Reset sequence */
	CMA3000_SET(data, CMA3000_RSTR, 0x02, "Reset");
	CMA3000_SET(data, CMA3000_RSTR, 0x0A, "Reset");
	CMA3000_SET(data, CMA3000_RSTR, 0x04, "Reset");

	/* Settling time delay */
	mdelay(10);

	val = CMA3000_READ(data, CMA3000_STATUS, "Status");
	if (val < 0) {
		dev_err(data->dev, "Reset failed\n");
		return val;
	}

	if (val & CMA3000_STATUS_PERR) {
		dev_err(data->dev, "Parity Error\n");
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int cma3000_poweron(struct cma3000_accl_data *data)
{
	const struct cma3000_platform_data *pdata = data->pdata;
	u8 ctrl = 0;
	int ret;

	if (data->g_range == CMARANGE_2G) {
		ctrl = (data->mode << 1) | CMA3000_RANGE2G;
	} else if (data->g_range == CMARANGE_8G) {
		ctrl = (data->mode << 1) | CMA3000_RANGE8G;
	} else {
		dev_info(data->dev,
			 "Invalid G range specified, assuming 8G\n");
		ctrl = (data->mode << 1) | CMA3000_RANGE8G;
	}

	ctrl |= data->bus_ops->ctrl_mod;

	CMA3000_SET(data, CMA3000_MDTHR, pdata->mdthr,
		    "Motion Detect Threshold");
	CMA3000_SET(data, CMA3000_MDFFTMR, pdata->mdfftmr,
		    "Time register");
	CMA3000_SET(data, CMA3000_FFTHR, pdata->ffthr,
		    "Free fall threshold");
	ret = CMA3000_SET(data, CMA3000_CTRL, ctrl, "Mode setting");
	if (ret < 0)
		return -EIO;

	msleep(CMA3000_SETDELAY);

	return 0;
}

__attribute__((used)) static int cma3000_poweroff(struct cma3000_accl_data *data)
{
	int ret;

	ret = CMA3000_SET(data, CMA3000_CTRL, CMAMODE_POFF, "Mode setting");
	msleep(CMA3000_SETDELAY);

	return ret;
}

__attribute__((used)) static int cma3000_open(struct input_dev *input_dev)
{
	struct cma3000_accl_data *data = input_get_drvdata(input_dev);

	mutex_lock(&data->mutex);

	if (!data->suspended)
		cma3000_poweron(data);

	data->opened = true;

	mutex_unlock(&data->mutex);

	return 0;
}

__attribute__((used)) static void cma3000_close(struct input_dev *input_dev)
{
	struct cma3000_accl_data *data = input_get_drvdata(input_dev);

	mutex_lock(&data->mutex);

	if (!data->suspended)
		cma3000_poweroff(data);

	data->opened = false;

	mutex_unlock(&data->mutex);
}

void cma3000_suspend(struct cma3000_accl_data *data)
{
	mutex_lock(&data->mutex);

	if (!data->suspended && data->opened)
		cma3000_poweroff(data);

	data->suspended = true;

	mutex_unlock(&data->mutex);
}

void cma3000_resume(struct cma3000_accl_data *data)
{
	mutex_lock(&data->mutex);

	if (data->suspended && data->opened)
		cma3000_poweron(data);

	data->suspended = false;

	mutex_unlock(&data->mutex);
}

struct cma3000_accl_data *cma3000_init(struct device *dev, int irq,
				       const struct cma3000_bus_ops *bops)
{
	const struct cma3000_platform_data *pdata = dev_get_platdata(dev);
	struct cma3000_accl_data *data;
	struct input_dev *input_dev;
	int rev;
	int error;

	if (!pdata) {
		dev_err(dev, "platform data not found\n");
		error = -EINVAL;
		goto err_out;
	}


	/* if no IRQ return error */
	if (irq == 0) {
		error = -EINVAL;
		goto err_out;
	}

	data = kzalloc(sizeof(struct cma3000_accl_data), GFP_KERNEL);
	input_dev = input_allocate_device();
	if (!data || !input_dev) {
		error = -ENOMEM;
		goto err_free_mem;
	}

	data->dev = dev;
	data->input_dev = input_dev;
	data->bus_ops = bops;
	data->pdata = pdata;
	data->irq = irq;
	mutex_init(&data->mutex);

	data->mode = pdata->mode;
	if (data->mode > CMAMODE_POFF) {
		data->mode = CMAMODE_MOTDET;
		dev_warn(dev,
			 "Invalid mode specified, assuming Motion Detect\n");
	}

	data->g_range = pdata->g_range;
	if (data->g_range != CMARANGE_2G && data->g_range != CMARANGE_8G) {
		dev_info(dev,
			 "Invalid G range specified, assuming 8G\n");
		data->g_range = CMARANGE_8G;
	}

	input_dev->name = "cma3000-accelerometer";
	input_dev->id.bustype = bops->bustype;
	input_dev->open = cma3000_open;
	input_dev->close = cma3000_close;

	 __set_bit(EV_ABS, input_dev->evbit);

	input_set_abs_params(input_dev, ABS_X,
			-data->g_range, data->g_range, pdata->fuzz_x, 0);
	input_set_abs_params(input_dev, ABS_Y,
			-data->g_range, data->g_range, pdata->fuzz_y, 0);
	input_set_abs_params(input_dev, ABS_Z,
			-data->g_range, data->g_range, pdata->fuzz_z, 0);
	input_set_abs_params(input_dev, ABS_MISC, 0, 1, 0, 0);

	input_set_drvdata(input_dev, data);

	error = cma3000_reset(data);
	if (error)
		goto err_free_mem;

	rev = CMA3000_READ(data, CMA3000_REVID, "Revid");
	if (rev < 0) {
		error = rev;
		goto err_free_mem;
	}

	pr_info("CMA3000 Accelerometer: Revision %x\n", rev);

	error = request_threaded_irq(irq, NULL, cma3000_thread_irq,
				     pdata->irqflags | IRQF_ONESHOT,
				     "cma3000_d0x", data);
	if (error) {
		dev_err(dev, "request_threaded_irq failed\n");
		goto err_free_mem;
	}

	error = input_register_device(data->input_dev);
	if (error) {
		dev_err(dev, "Unable to register input device\n");
		goto err_free_irq;
	}

	return data;

err_free_irq:
	free_irq(irq, data);
err_free_mem:
	input_free_device(input_dev);
	kfree(data);
err_out:
	return ERR_PTR(error);
}

void cma3000_exit(struct cma3000_accl_data *data)
{
	free_irq(data->irq, data);
	input_unregister_device(data->input_dev);
	kfree(data);
}

