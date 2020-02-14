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
typedef  scalar_t__ u64 ;
struct fw_unit {int /*<<< orphan*/  device; } ;
struct fw_device {int generation; TYPE_1__* card; int /*<<< orphan*/  max_speed; int /*<<< orphan*/  node_id; } ;
struct delayed_work {int dummy; } ;
struct TYPE_2__ {scalar_t__ reset_jiffies; } ;

/* Variables and functions */
 int EAGAIN ; 
 int EIO ; 
 int /*<<< orphan*/  ERROR_RETRY_DELAY_MS ; 
 unsigned int FW_FIXED_GENERATION ; 
 unsigned int FW_GENERATION_MASK ; 
 unsigned int FW_QUIET ; 
 int /*<<< orphan*/  PROBE_DELAY_MS ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_COMPLETE ; 
 int RCODE_GENERATION ; 
 int RCODE_TYPE_ERROR ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct fw_device* fw_parent_device (struct fw_unit*) ; 
 int /*<<< orphan*/  fw_rcode_string (int) ; 
 int fw_run_transaction (TYPE_1__*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,scalar_t__,void*,size_t) ; 
 scalar_t__ get_jiffies_64 () ; 
 int /*<<< orphan*/  mod_delayed_work (int /*<<< orphan*/ ,struct delayed_work*,scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_rmb () ; 
 int /*<<< orphan*/  system_wq ; 
 scalar_t__ time_after64 (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline bool rcode_is_permanent_error(int rcode)
{
	return rcode == RCODE_TYPE_ERROR || rcode == RCODE_ADDRESS_ERROR;
}

int snd_fw_transaction(struct fw_unit *unit, int tcode,
		       u64 offset, void *buffer, size_t length,
		       unsigned int flags)
{
	struct fw_device *device = fw_parent_device(unit);
	int generation, rcode, tries = 0;

	generation = flags & FW_GENERATION_MASK;
	for (;;) {
		if (!(flags & FW_FIXED_GENERATION)) {
			generation = device->generation;
			smp_rmb(); /* node_id vs. generation */
		}
		rcode = fw_run_transaction(device->card, tcode,
					   device->node_id, generation,
					   device->max_speed, offset,
					   buffer, length);

		if (rcode == RCODE_COMPLETE)
			return 0;

		if (rcode == RCODE_GENERATION && (flags & FW_FIXED_GENERATION))
			return -EAGAIN;

		if (rcode_is_permanent_error(rcode) || ++tries >= 3) {
			if (!(flags & FW_QUIET))
				dev_err(&unit->device,
					"transaction failed: %s\n",
					fw_rcode_string(rcode));
			return -EIO;
		}

		msleep(ERROR_RETRY_DELAY_MS);
	}
}

void snd_fw_schedule_registration(struct fw_unit *unit,
				  struct delayed_work *dwork)
{
	u64 now, delay;

	now = get_jiffies_64();
	delay = fw_parent_device(unit)->card->reset_jiffies
					+ msecs_to_jiffies(PROBE_DELAY_MS);

	if (time_after64(delay, now))
		delay -= now;
	else
		delay = 0;

	mod_delayed_work(system_wq, dwork, delay);
}

