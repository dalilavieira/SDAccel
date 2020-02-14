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
struct fw_unit {int /*<<< orphan*/  device; } ;
struct fw_iso_resources {unsigned long long channels_mask; int allocated; unsigned int bandwidth; int bandwidth_overhead; int channel; int /*<<< orphan*/  mutex; struct fw_unit* unit; int /*<<< orphan*/  generation; } ;
struct fw_card {int gap_count; scalar_t__ reset_jiffies; int /*<<< orphan*/  lock; int /*<<< orphan*/  generation; } ;
typedef  scalar_t__ s64 ;
struct TYPE_2__ {struct fw_card* card; } ;

/* Variables and functions */
 int ALIGN (unsigned int,int) ; 
 unsigned int DIV_ROUND_UP (unsigned int,int) ; 
 int EAGAIN ; 
 int EBADFD ; 
 int EBUSY ; 
 int ERESTARTSYS ; 
 scalar_t__ HZ ; 
 int SCODE_400 ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  fw_iso_resource_manage (struct fw_card*,int /*<<< orphan*/ ,unsigned long long,int*,int*,int) ; 
 TYPE_1__* fw_parent_device (struct fw_unit*) ; 
 scalar_t__ get_jiffies_64 () ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ schedule_timeout_interruptible (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

int fw_iso_resources_init(struct fw_iso_resources *r, struct fw_unit *unit)
{
	r->channels_mask = ~0uLL;
	r->unit = unit;
	mutex_init(&r->mutex);
	r->allocated = false;

	return 0;
}

void fw_iso_resources_destroy(struct fw_iso_resources *r)
{
	WARN_ON(r->allocated);
	mutex_destroy(&r->mutex);
}

__attribute__((used)) static unsigned int packet_bandwidth(unsigned int max_payload_bytes, int speed)
{
	unsigned int bytes, s400_bytes;

	/* iso packets have three header quadlets and quadlet-aligned payload */
	bytes = 3 * 4 + ALIGN(max_payload_bytes, 4);

	/* convert to bandwidth units (quadlets at S1600 = bytes at S400) */
	if (speed <= SCODE_400)
		s400_bytes = bytes * (1 << (SCODE_400 - speed));
	else
		s400_bytes = DIV_ROUND_UP(bytes, 1 << (speed - SCODE_400));

	return s400_bytes;
}

__attribute__((used)) static int current_bandwidth_overhead(struct fw_card *card)
{
	/*
	 * Under the usual pessimistic assumption (cable length 4.5 m), the
	 * isochronous overhead for N cables is 1.797 µs + N * 0.494 µs, or
	 * 88.3 + N * 24.3 in bandwidth units.
	 *
	 * The calculation below tries to deduce N from the current gap count.
	 * If the gap count has been optimized by measuring the actual packet
	 * transmission time, this derived overhead should be near the actual
	 * overhead as well.
	 */
	return card->gap_count < 63 ? card->gap_count * 97 / 10 + 89 : 512;
}

__attribute__((used)) static int wait_isoch_resource_delay_after_bus_reset(struct fw_card *card)
{
	for (;;) {
		s64 delay = (card->reset_jiffies + HZ) - get_jiffies_64();
		if (delay <= 0)
			return 0;
		if (schedule_timeout_interruptible(delay) > 0)
			return -ERESTARTSYS;
	}
}

int fw_iso_resources_allocate(struct fw_iso_resources *r,
			      unsigned int max_payload_bytes, int speed)
{
	struct fw_card *card = fw_parent_device(r->unit)->card;
	int bandwidth, channel, err;

	if (WARN_ON(r->allocated))
		return -EBADFD;

	r->bandwidth = packet_bandwidth(max_payload_bytes, speed);

retry_after_bus_reset:
	spin_lock_irq(&card->lock);
	r->generation = card->generation;
	r->bandwidth_overhead = current_bandwidth_overhead(card);
	spin_unlock_irq(&card->lock);

	err = wait_isoch_resource_delay_after_bus_reset(card);
	if (err < 0)
		return err;

	mutex_lock(&r->mutex);

	bandwidth = r->bandwidth + r->bandwidth_overhead;
	fw_iso_resource_manage(card, r->generation, r->channels_mask,
			       &channel, &bandwidth, true);
	if (channel == -EAGAIN) {
		mutex_unlock(&r->mutex);
		goto retry_after_bus_reset;
	}
	if (channel >= 0) {
		r->channel = channel;
		r->allocated = true;
	} else {
		if (channel == -EBUSY)
			dev_err(&r->unit->device,
				"isochronous resources exhausted\n");
		else
			dev_err(&r->unit->device,
				"isochronous resource allocation failed\n");
	}

	mutex_unlock(&r->mutex);

	return channel;
}

int fw_iso_resources_update(struct fw_iso_resources *r)
{
	struct fw_card *card = fw_parent_device(r->unit)->card;
	int bandwidth, channel;

	mutex_lock(&r->mutex);

	if (!r->allocated) {
		mutex_unlock(&r->mutex);
		return 0;
	}

	spin_lock_irq(&card->lock);
	r->generation = card->generation;
	r->bandwidth_overhead = current_bandwidth_overhead(card);
	spin_unlock_irq(&card->lock);

	bandwidth = r->bandwidth + r->bandwidth_overhead;

	fw_iso_resource_manage(card, r->generation, 1uLL << r->channel,
			       &channel, &bandwidth, true);
	/*
	 * When another bus reset happens, pretend that the allocation
	 * succeeded; we will try again for the new generation later.
	 */
	if (channel < 0 && channel != -EAGAIN) {
		r->allocated = false;
		if (channel == -EBUSY)
			dev_err(&r->unit->device,
				"isochronous resources exhausted\n");
		else
			dev_err(&r->unit->device,
				"isochronous resource allocation failed\n");
	}

	mutex_unlock(&r->mutex);

	return channel;
}

void fw_iso_resources_free(struct fw_iso_resources *r)
{
	struct fw_card *card;
	int bandwidth, channel;

	/* Not initialized. */
	if (r->unit == NULL)
		return;
	card = fw_parent_device(r->unit)->card;

	mutex_lock(&r->mutex);

	if (r->allocated) {
		bandwidth = r->bandwidth + r->bandwidth_overhead;
		fw_iso_resource_manage(card, r->generation, 1uLL << r->channel,
				       &channel, &bandwidth, false);
		if (channel < 0)
			dev_err(&r->unit->device,
				"isochronous resource deallocation failed\n");

		r->allocated = false;
	}

	mutex_unlock(&r->mutex);
}

