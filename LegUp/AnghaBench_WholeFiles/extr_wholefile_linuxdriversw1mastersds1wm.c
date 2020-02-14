#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  (* w1_slave_found_callback ) (struct w1_master*,int) ;
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct w1_master {int /*<<< orphan*/  bus_mutex; } ;
struct resource {int start; int flags; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct ds1wm_driver_data {int clock_rate; int bus_shift; int active_high; int reset_recover_delay; scalar_t__ is_hw_big_endian; } ;
struct ds1wm_data {int bus_shift; int map; int int_en_reg_none; int slave_present; int read_byte; int reset_recover_delay; int read_error; int irq; scalar_t__ is_hw_big_endian; struct platform_device* pdev; TYPE_3__* cell; int /*<<< orphan*/ * read_complete; int /*<<< orphan*/ * write_complete; int /*<<< orphan*/ * reset_complete; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_9__ {int freq; int divisor; } ;
struct TYPE_8__ {int /*<<< orphan*/  (* disable ) (struct platform_device*) ;int /*<<< orphan*/  (* enable ) (struct platform_device*) ;} ;
struct TYPE_7__ {void* data; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_4__*) ; 
 int /*<<< orphan*/  DECLARE_COMPLETION_ONSTACK (int /*<<< orphan*/ ) ; 
 int DS1WM_CLKDIV ; 
 int DS1WM_CMD ; 
 int DS1WM_CMD_1W_RESET ; 
 int DS1WM_CMD_SRA ; 
 int DS1WM_DATA ; 
 int DS1WM_INT ; 
 int DS1WM_INTEN_EPD ; 
 int DS1WM_INTEN_ERBF ; 
 int DS1WM_INTEN_ETMT ; 
 int DS1WM_INTEN_IAS ; 
 int DS1WM_INTEN_NOT_IAS ; 
 int DS1WM_INT_EN ; 
 int DS1WM_INT_PD ; 
 int DS1WM_INT_PDR ; 
 int DS1WM_INT_RBF ; 
 int DS1WM_INT_TSRE ; 
 int /*<<< orphan*/  DS1WM_TIMEOUT ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int IORESOURCE_IRQ_HIGHEDGE ; 
 int IORESOURCE_IRQ_HIGHLEVEL ; 
 int IORESOURCE_IRQ_LOWEDGE ; 
 int IORESOURCE_IRQ_LOWLEVEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IRQ_TYPE_EDGE_FALLING ; 
 int /*<<< orphan*/  IRQ_TYPE_EDGE_RISING ; 
 int /*<<< orphan*/  IRQ_TYPE_LEVEL_HIGH ; 
 int /*<<< orphan*/  IRQ_TYPE_LEVEL_LOW ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct ds1wm_driver_data* dev_get_platdata (struct device*) ; 
 int devm_ioremap (struct device*,int,int) ; 
 struct ds1wm_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct ds1wm_data*) ; 
 TYPE_1__ ds1wm_master ; 
 int fls64 (int) ; 
 TYPE_4__* freq ; 
 int ioread16 (int) ; 
 int ioread16be (int) ; 
 int ioread32 (int) ; 
 int ioread32be (int) ; 
 int ioread8 (int) ; 
 int /*<<< orphan*/  iowrite16 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  iowrite16be (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  iowrite32 (int,int) ; 
 int /*<<< orphan*/  iowrite32be (int,int) ; 
 int /*<<< orphan*/  iowrite8 (int,int) ; 
 int /*<<< orphan*/  irq_set_irq_type (int,int /*<<< orphan*/ ) ; 
 TYPE_3__* mfd_get_cell (struct platform_device*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct ds1wm_data* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ds1wm_data*) ; 
 int /*<<< orphan*/  read_done ; 
 int /*<<< orphan*/  reset_done ; 
 int resource_size (struct resource*) ; 
 int /*<<< orphan*/  stub1 (struct platform_device*) ; 
 int /*<<< orphan*/  stub2 (struct platform_device*) ; 
 int w1_add_master_device (TYPE_1__*) ; 
 int /*<<< orphan*/  w1_remove_master_device (TYPE_1__*) ; 
 unsigned long wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_done ; 

__attribute__((used)) static inline void ds1wm_write_register(struct ds1wm_data *ds1wm_data, u32 reg,
					u8 val)
{
	if (ds1wm_data->is_hw_big_endian) {
		switch (ds1wm_data->bus_shift) {
		case 0:
			iowrite8(val, ds1wm_data->map + (reg << 0));
			break;
		case 1:
			iowrite16be((u16)val, ds1wm_data->map + (reg << 1));
			break;
		case 2:
			iowrite32be((u32)val, ds1wm_data->map + (reg << 2));
			break;
		}
	} else {
		switch (ds1wm_data->bus_shift) {
		case 0:
			iowrite8(val, ds1wm_data->map + (reg << 0));
			break;
		case 1:
			iowrite16((u16)val, ds1wm_data->map + (reg << 1));
			break;
		case 2:
			iowrite32((u32)val, ds1wm_data->map + (reg << 2));
			break;
		}
	}
}

__attribute__((used)) static inline u8 ds1wm_read_register(struct ds1wm_data *ds1wm_data, u32 reg)
{
	u32 val = 0;

	if (ds1wm_data->is_hw_big_endian) {
		switch (ds1wm_data->bus_shift) {
		case 0:
			val = ioread8(ds1wm_data->map + (reg << 0));
			break;
		case 1:
			val = ioread16be(ds1wm_data->map + (reg << 1));
			break;
		case 2:
			val = ioread32be(ds1wm_data->map + (reg << 2));
			break;
		}
	} else {
		switch (ds1wm_data->bus_shift) {
		case 0:
			val = ioread8(ds1wm_data->map + (reg << 0));
			break;
		case 1:
			val = ioread16(ds1wm_data->map + (reg << 1));
			break;
		case 2:
			val = ioread32(ds1wm_data->map + (reg << 2));
			break;
		}
	}
	dev_dbg(&ds1wm_data->pdev->dev,
		"ds1wm_read_register reg: %d, 32 bit val:%x\n", reg, val);
	return (u8)val;
}

__attribute__((used)) static irqreturn_t ds1wm_isr(int isr, void *data)
{
	struct ds1wm_data *ds1wm_data = data;
	u8 intr;
	u8 inten = ds1wm_read_register(ds1wm_data, DS1WM_INT_EN);
	/* if no bits are set in int enable register (except the IAS)
	than go no further, reading the regs below has side effects */
	if (!(inten & DS1WM_INTEN_NOT_IAS))
		return IRQ_NONE;

	ds1wm_write_register(ds1wm_data,
		DS1WM_INT_EN, ds1wm_data->int_en_reg_none);

	/* this read action clears the INTR and certain flags in ds1wm */
	intr = ds1wm_read_register(ds1wm_data, DS1WM_INT);

	ds1wm_data->slave_present = (intr & DS1WM_INT_PDR) ? 0 : 1;

	if ((intr & DS1WM_INT_TSRE) && ds1wm_data->write_complete) {
		inten &= ~DS1WM_INTEN_ETMT;
		complete(ds1wm_data->write_complete);
	}
	if (intr & DS1WM_INT_RBF) {
		/* this read clears the RBF flag */
		ds1wm_data->read_byte = ds1wm_read_register(ds1wm_data,
		DS1WM_DATA);
		inten &= ~DS1WM_INTEN_ERBF;
		if (ds1wm_data->read_complete)
			complete(ds1wm_data->read_complete);
	}
	if ((intr & DS1WM_INT_PD) && ds1wm_data->reset_complete) {
		inten &= ~DS1WM_INTEN_EPD;
		complete(ds1wm_data->reset_complete);
	}

	ds1wm_write_register(ds1wm_data, DS1WM_INT_EN, inten);
	return IRQ_HANDLED;
}

__attribute__((used)) static int ds1wm_reset(struct ds1wm_data *ds1wm_data)
{
	unsigned long timeleft;
	DECLARE_COMPLETION_ONSTACK(reset_done);

	ds1wm_data->reset_complete = &reset_done;

	/* enable Presence detect only */
	ds1wm_write_register(ds1wm_data, DS1WM_INT_EN, DS1WM_INTEN_EPD |
	ds1wm_data->int_en_reg_none);

	ds1wm_write_register(ds1wm_data, DS1WM_CMD, DS1WM_CMD_1W_RESET);

	timeleft = wait_for_completion_timeout(&reset_done, DS1WM_TIMEOUT);
	ds1wm_data->reset_complete = NULL;
	if (!timeleft) {
		dev_err(&ds1wm_data->pdev->dev, "reset failed, timed out\n");
		return 1;
	}

	if (!ds1wm_data->slave_present) {
		dev_dbg(&ds1wm_data->pdev->dev, "reset: no devices found\n");
		return 1;
	}

	if (ds1wm_data->reset_recover_delay)
		msleep(ds1wm_data->reset_recover_delay);

	return 0;
}

__attribute__((used)) static int ds1wm_write(struct ds1wm_data *ds1wm_data, u8 data)
{
	unsigned long timeleft;
	DECLARE_COMPLETION_ONSTACK(write_done);
	ds1wm_data->write_complete = &write_done;

	ds1wm_write_register(ds1wm_data, DS1WM_INT_EN,
	ds1wm_data->int_en_reg_none | DS1WM_INTEN_ETMT);

	ds1wm_write_register(ds1wm_data, DS1WM_DATA, data);

	timeleft = wait_for_completion_timeout(&write_done, DS1WM_TIMEOUT);

	ds1wm_data->write_complete = NULL;
	if (!timeleft) {
		dev_err(&ds1wm_data->pdev->dev, "write failed, timed out\n");
		return -ETIMEDOUT;
	}

	return 0;
}

__attribute__((used)) static u8 ds1wm_read(struct ds1wm_data *ds1wm_data, unsigned char write_data)
{
	unsigned long timeleft;
	u8 intEnable = DS1WM_INTEN_ERBF | ds1wm_data->int_en_reg_none;
	DECLARE_COMPLETION_ONSTACK(read_done);

	ds1wm_read_register(ds1wm_data, DS1WM_DATA);

	ds1wm_data->read_complete = &read_done;
	ds1wm_write_register(ds1wm_data, DS1WM_INT_EN, intEnable);

	ds1wm_write_register(ds1wm_data, DS1WM_DATA, write_data);
	timeleft = wait_for_completion_timeout(&read_done, DS1WM_TIMEOUT);

	ds1wm_data->read_complete = NULL;
	if (!timeleft) {
		dev_err(&ds1wm_data->pdev->dev, "read failed, timed out\n");
		ds1wm_data->read_error = -ETIMEDOUT;
		return 0xFF;
	}
	ds1wm_data->read_error = 0;
	return ds1wm_data->read_byte;
}

__attribute__((used)) static int ds1wm_find_divisor(int gclk)
{
	int i;

	for (i = ARRAY_SIZE(freq)-1; i >= 0; --i)
		if (gclk >= freq[i].freq)
			return freq[i].divisor;

	return 0;
}

__attribute__((used)) static void ds1wm_up(struct ds1wm_data *ds1wm_data)
{
	int divisor;
	struct device *dev = &ds1wm_data->pdev->dev;
	struct ds1wm_driver_data *plat = dev_get_platdata(dev);

	if (ds1wm_data->cell->enable)
		ds1wm_data->cell->enable(ds1wm_data->pdev);

	divisor = ds1wm_find_divisor(plat->clock_rate);
	dev_dbg(dev, "found divisor 0x%x for clock %d\n",
		divisor, plat->clock_rate);
	if (divisor == 0) {
		dev_err(dev, "no suitable divisor for %dHz clock\n",
			plat->clock_rate);
		return;
	}
	ds1wm_write_register(ds1wm_data, DS1WM_CLKDIV, divisor);

	/* Let the w1 clock stabilize. */
	msleep(1);

	ds1wm_reset(ds1wm_data);
}

__attribute__((used)) static void ds1wm_down(struct ds1wm_data *ds1wm_data)
{
	ds1wm_reset(ds1wm_data);

	/* Disable interrupts. */
	ds1wm_write_register(ds1wm_data, DS1WM_INT_EN,
		ds1wm_data->int_en_reg_none);

	if (ds1wm_data->cell->disable)
		ds1wm_data->cell->disable(ds1wm_data->pdev);
}

__attribute__((used)) static u8 ds1wm_read_byte(void *data)
{
	struct ds1wm_data *ds1wm_data = data;

	return ds1wm_read(ds1wm_data, 0xff);
}

__attribute__((used)) static void ds1wm_write_byte(void *data, u8 byte)
{
	struct ds1wm_data *ds1wm_data = data;

	ds1wm_write(ds1wm_data, byte);
}

__attribute__((used)) static u8 ds1wm_reset_bus(void *data)
{
	struct ds1wm_data *ds1wm_data = data;

	ds1wm_reset(ds1wm_data);

	return 0;
}

__attribute__((used)) static void ds1wm_search(void *data, struct w1_master *master_dev,
			u8 search_type, w1_slave_found_callback slave_found)
{
	struct ds1wm_data *ds1wm_data = data;
	int i;
	int ms_discrep_bit = -1;
	u64 r = 0; /* holds the progress of the search */
	u64 r_prime, d;
	unsigned slaves_found = 0;
	unsigned int pass = 0;

	dev_dbg(&ds1wm_data->pdev->dev, "search begin\n");
	while (true) {
		++pass;
		if (pass > 100) {
			dev_dbg(&ds1wm_data->pdev->dev,
				"too many attempts (100), search aborted\n");
			return;
		}

		mutex_lock(&master_dev->bus_mutex);
		if (ds1wm_reset(ds1wm_data)) {
			mutex_unlock(&master_dev->bus_mutex);
			dev_dbg(&ds1wm_data->pdev->dev,
				"pass: %d reset error (or no slaves)\n", pass);
			break;
		}

		dev_dbg(&ds1wm_data->pdev->dev,
			"pass: %d r : %0#18llx writing SEARCH_ROM\n", pass, r);
		ds1wm_write(ds1wm_data, search_type);
		dev_dbg(&ds1wm_data->pdev->dev,
			"pass: %d entering ASM\n", pass);
		ds1wm_write_register(ds1wm_data, DS1WM_CMD, DS1WM_CMD_SRA);
		dev_dbg(&ds1wm_data->pdev->dev,
			"pass: %d beginning nibble loop\n", pass);

		r_prime = 0;
		d = 0;
		/* we work one nibble at a time */
		/* each nibble is interleaved to form a byte */
		for (i = 0; i < 16; i++) {

			unsigned char resp, _r, _r_prime, _d;

			_r = (r >> (4*i)) & 0xf;
			_r = ((_r & 0x1) << 1) |
			((_r & 0x2) << 2) |
			((_r & 0x4) << 3) |
			((_r & 0x8) << 4);

			/* writes _r, then reads back: */
			resp = ds1wm_read(ds1wm_data, _r);

			if (ds1wm_data->read_error) {
				dev_err(&ds1wm_data->pdev->dev,
				"pass: %d nibble: %d read error\n", pass, i);
				break;
			}

			_r_prime = ((resp & 0x02) >> 1) |
			((resp & 0x08) >> 2) |
			((resp & 0x20) >> 3) |
			((resp & 0x80) >> 4);

			_d = ((resp & 0x01) >> 0) |
			((resp & 0x04) >> 1) |
			((resp & 0x10) >> 2) |
			((resp & 0x40) >> 3);

			r_prime |= (unsigned long long) _r_prime << (i * 4);
			d |= (unsigned long long) _d << (i * 4);

		}
		if (ds1wm_data->read_error) {
			mutex_unlock(&master_dev->bus_mutex);
			dev_err(&ds1wm_data->pdev->dev,
				"pass: %d read error, retrying\n", pass);
			break;
		}
		dev_dbg(&ds1wm_data->pdev->dev,
			"pass: %d r\': %0#18llx d:%0#18llx\n",
			pass, r_prime, d);
		dev_dbg(&ds1wm_data->pdev->dev,
			"pass: %d nibble loop complete, exiting ASM\n", pass);
		ds1wm_write_register(ds1wm_data, DS1WM_CMD, ~DS1WM_CMD_SRA);
		dev_dbg(&ds1wm_data->pdev->dev,
			"pass: %d resetting bus\n", pass);
		ds1wm_reset(ds1wm_data);
		mutex_unlock(&master_dev->bus_mutex);
		if ((r_prime & ((u64)1 << 63)) && (d & ((u64)1 << 63))) {
			dev_err(&ds1wm_data->pdev->dev,
				"pass: %d bus error, retrying\n", pass);
			continue; /* start over */
		}


		dev_dbg(&ds1wm_data->pdev->dev,
			"pass: %d found %0#18llx\n", pass, r_prime);
		slave_found(master_dev, r_prime);
		++slaves_found;
		dev_dbg(&ds1wm_data->pdev->dev,
			"pass: %d complete, preparing next pass\n", pass);

		/* any discrepency found which we already choose the
		   '1' branch is now is now irrelevant we reveal the
		   next branch with this: */
		d &= ~r;
		/* find last bit set, i.e. the most signif. bit set */
		ms_discrep_bit = fls64(d) - 1;
		dev_dbg(&ds1wm_data->pdev->dev,
			"pass: %d new d:%0#18llx MS discrep bit:%d\n",
			pass, d, ms_discrep_bit);

		/* prev_ms_discrep_bit = ms_discrep_bit;
		   prepare for next ROM search:		    */
		if (ms_discrep_bit == -1)
			break;

		r = (r &  ~(~0ull << (ms_discrep_bit))) | 1 << ms_discrep_bit;
	} /* end while true */
	dev_dbg(&ds1wm_data->pdev->dev,
		"pass: %d total: %d search done ms d bit pos: %d\n", pass,
		slaves_found, ms_discrep_bit);
}

__attribute__((used)) static int ds1wm_probe(struct platform_device *pdev)
{
	struct ds1wm_data *ds1wm_data;
	struct ds1wm_driver_data *plat;
	struct resource *res;
	int ret;
	u8 inten;

	if (!pdev)
		return -ENODEV;

	ds1wm_data = devm_kzalloc(&pdev->dev, sizeof(*ds1wm_data), GFP_KERNEL);
	if (!ds1wm_data)
		return -ENOMEM;

	platform_set_drvdata(pdev, ds1wm_data);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return -ENXIO;
	ds1wm_data->map = devm_ioremap(&pdev->dev, res->start,
				       resource_size(res));
	if (!ds1wm_data->map)
		return -ENOMEM;

	ds1wm_data->pdev = pdev;
	ds1wm_data->cell = mfd_get_cell(pdev);
	if (!ds1wm_data->cell)
		return -ENODEV;
	plat = dev_get_platdata(&pdev->dev);
	if (!plat)
		return -ENODEV;

	/* how many bits to shift register number to get register offset */
	if (plat->bus_shift > 2) {
		dev_err(&ds1wm_data->pdev->dev,
			"illegal bus shift %d, not written",
			ds1wm_data->bus_shift);
		return -EINVAL;
	}

	ds1wm_data->bus_shift = plat->bus_shift;
	/* make sure resource has space for 8 registers */
	if ((8 << ds1wm_data->bus_shift) > resource_size(res)) {
		dev_err(&ds1wm_data->pdev->dev,
			"memory resource size %d to small, should be %d\n",
			(int)resource_size(res),
			8 << ds1wm_data->bus_shift);
		return -EINVAL;
	}

	ds1wm_data->is_hw_big_endian = plat->is_hw_big_endian;

	res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!res)
		return -ENXIO;
	ds1wm_data->irq = res->start;
	ds1wm_data->int_en_reg_none = (plat->active_high ? DS1WM_INTEN_IAS : 0);
	ds1wm_data->reset_recover_delay = plat->reset_recover_delay;

	/* Mask interrupts, set IAS before claiming interrupt */
	inten = ds1wm_read_register(ds1wm_data, DS1WM_INT_EN);
	ds1wm_write_register(ds1wm_data,
		DS1WM_INT_EN, ds1wm_data->int_en_reg_none);

	if (res->flags & IORESOURCE_IRQ_HIGHEDGE)
		irq_set_irq_type(ds1wm_data->irq, IRQ_TYPE_EDGE_RISING);
	if (res->flags & IORESOURCE_IRQ_LOWEDGE)
		irq_set_irq_type(ds1wm_data->irq, IRQ_TYPE_EDGE_FALLING);
	if (res->flags & IORESOURCE_IRQ_HIGHLEVEL)
		irq_set_irq_type(ds1wm_data->irq, IRQ_TYPE_LEVEL_HIGH);
	if (res->flags & IORESOURCE_IRQ_LOWLEVEL)
		irq_set_irq_type(ds1wm_data->irq, IRQ_TYPE_LEVEL_LOW);

	ret = devm_request_irq(&pdev->dev, ds1wm_data->irq, ds1wm_isr,
			IRQF_SHARED, "ds1wm", ds1wm_data);
	if (ret) {
		dev_err(&ds1wm_data->pdev->dev,
			"devm_request_irq %d failed with errno %d\n",
			ds1wm_data->irq,
			ret);

		return ret;
	}

	ds1wm_up(ds1wm_data);

	ds1wm_master.data = (void *)ds1wm_data;

	ret = w1_add_master_device(&ds1wm_master);
	if (ret)
		goto err;

	dev_dbg(&ds1wm_data->pdev->dev,
		"ds1wm: probe successful, IAS: %d, rec.delay: %d, clockrate: %d, bus-shift: %d, is Hw Big Endian: %d\n",
		plat->active_high,
		plat->reset_recover_delay,
		plat->clock_rate,
		ds1wm_data->bus_shift,
		ds1wm_data->is_hw_big_endian);
	return 0;

err:
	ds1wm_down(ds1wm_data);

	return ret;
}

__attribute__((used)) static int ds1wm_remove(struct platform_device *pdev)
{
	struct ds1wm_data *ds1wm_data = platform_get_drvdata(pdev);

	w1_remove_master_device(&ds1wm_master);
	ds1wm_down(ds1wm_data);

	return 0;
}

