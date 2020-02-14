#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct lp8788_irq_data {int* enabled; int /*<<< orphan*/  irq_lock; scalar_t__ domain; struct lp8788* lp; } ;
struct lp8788 {int irq; scalar_t__ irqdm; TYPE_1__* dev; } ;
struct irq_domain {struct lp8788_irq_data* host_data; } ;
struct irq_data {size_t hwirq; } ;
struct irq_chip {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;
typedef  enum lp8788_int_id { ____Placeholder_lp8788_int_id } lp8788_int_id ;
struct TYPE_4__ {int /*<<< orphan*/  of_node; } ;

/* Variables and functions */
 int BASE_INTEN_ADDR ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  LP8788_INT_1 ; 
 int LP8788_INT_MAX ; 
 int NUM_REGS ; 
 int SIZE_REG ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*,int) ; 
 struct lp8788_irq_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int,scalar_t__) ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int /*<<< orphan*/  handle_nested_irq (int /*<<< orphan*/ ) ; 
 struct lp8788_irq_data* irq_data_get_irq_chip_data (struct irq_data*) ; 
 scalar_t__ irq_domain_add_linear (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,struct lp8788_irq_data*) ; 
 int /*<<< orphan*/  irq_find_mapping (scalar_t__,int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,struct irq_chip*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,struct lp8788_irq_data*) ; 
 int /*<<< orphan*/  irq_set_nested_thread (unsigned int,int) ; 
 int /*<<< orphan*/  irq_set_noprobe (unsigned int) ; 
 int /*<<< orphan*/  lp8788_domain_ops ; 
 struct irq_chip lp8788_irq_chip ; 
 scalar_t__ lp8788_read_multi_bytes (struct lp8788*,int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  lp8788_update_bits (struct lp8788*,int,int,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int request_threaded_irq (int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct lp8788_irq_data*) ; 

__attribute__((used)) static inline u8 _irq_to_addr(enum lp8788_int_id id)
{
	return id / SIZE_REG;
}

__attribute__((used)) static inline u8 _irq_to_enable_addr(enum lp8788_int_id id)
{
	return _irq_to_addr(id) + BASE_INTEN_ADDR;
}

__attribute__((used)) static inline u8 _irq_to_mask(enum lp8788_int_id id)
{
	return 1 << (id % SIZE_REG);
}

__attribute__((used)) static inline u8 _irq_to_val(enum lp8788_int_id id, int enable)
{
	return enable << (id % SIZE_REG);
}

__attribute__((used)) static void lp8788_irq_enable(struct irq_data *data)
{
	struct lp8788_irq_data *irqd = irq_data_get_irq_chip_data(data);

	irqd->enabled[data->hwirq] = 1;
}

__attribute__((used)) static void lp8788_irq_disable(struct irq_data *data)
{
	struct lp8788_irq_data *irqd = irq_data_get_irq_chip_data(data);

	irqd->enabled[data->hwirq] = 0;
}

__attribute__((used)) static void lp8788_irq_bus_lock(struct irq_data *data)
{
	struct lp8788_irq_data *irqd = irq_data_get_irq_chip_data(data);

	mutex_lock(&irqd->irq_lock);
}

__attribute__((used)) static void lp8788_irq_bus_sync_unlock(struct irq_data *data)
{
	struct lp8788_irq_data *irqd = irq_data_get_irq_chip_data(data);
	enum lp8788_int_id irq = data->hwirq;
	u8 addr, mask, val;

	addr = _irq_to_enable_addr(irq);
	mask = _irq_to_mask(irq);
	val = _irq_to_val(irq, irqd->enabled[irq]);

	lp8788_update_bits(irqd->lp, addr, mask, val);

	mutex_unlock(&irqd->irq_lock);
}

__attribute__((used)) static irqreturn_t lp8788_irq_handler(int irq, void *ptr)
{
	struct lp8788_irq_data *irqd = ptr;
	struct lp8788 *lp = irqd->lp;
	u8 status[NUM_REGS], addr, mask;
	bool handled = false;
	int i;

	if (lp8788_read_multi_bytes(lp, LP8788_INT_1, status, NUM_REGS))
		return IRQ_NONE;

	for (i = 0 ; i < LP8788_INT_MAX ; i++) {
		addr = _irq_to_addr(i);
		mask = _irq_to_mask(i);

		/* reporting only if the irq is enabled */
		if (status[addr] & mask) {
			handle_nested_irq(irq_find_mapping(irqd->domain, i));
			handled = true;
		}
	}

	return handled ? IRQ_HANDLED : IRQ_NONE;
}

__attribute__((used)) static int lp8788_irq_map(struct irq_domain *d, unsigned int virq,
			irq_hw_number_t hwirq)
{
	struct lp8788_irq_data *irqd = d->host_data;
	struct irq_chip *chip = &lp8788_irq_chip;

	irq_set_chip_data(virq, irqd);
	irq_set_chip_and_handler(virq, chip, handle_edge_irq);
	irq_set_nested_thread(virq, 1);
	irq_set_noprobe(virq);

	return 0;
}

int lp8788_irq_init(struct lp8788 *lp, int irq)
{
	struct lp8788_irq_data *irqd;
	int ret;

	if (irq <= 0) {
		dev_warn(lp->dev, "invalid irq number: %d\n", irq);
		return 0;
	}

	irqd = devm_kzalloc(lp->dev, sizeof(*irqd), GFP_KERNEL);
	if (!irqd)
		return -ENOMEM;

	irqd->lp = lp;
	irqd->domain = irq_domain_add_linear(lp->dev->of_node, LP8788_INT_MAX,
					&lp8788_domain_ops, irqd);
	if (!irqd->domain) {
		dev_err(lp->dev, "failed to add irq domain err\n");
		return -EINVAL;
	}

	lp->irqdm = irqd->domain;
	mutex_init(&irqd->irq_lock);

	ret = request_threaded_irq(irq, NULL, lp8788_irq_handler,
				IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
				"lp8788-irq", irqd);
	if (ret) {
		dev_err(lp->dev, "failed to create a thread for IRQ_N\n");
		return ret;
	}

	lp->irq = irq;

	return 0;
}

void lp8788_irq_exit(struct lp8788 *lp)
{
	if (lp->irq)
		free_irq(lp->irq, lp->irqdm);
}

