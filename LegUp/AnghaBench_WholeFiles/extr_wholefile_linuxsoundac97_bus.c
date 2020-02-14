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
struct snd_ac97_bus_ops {int (* read ) (struct snd_ac97*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* warm_reset ) (struct snd_ac97*) ;int /*<<< orphan*/  (* reset ) (struct snd_ac97*) ;} ;
struct snd_ac97 {int id; TYPE_1__* bus; } ;
struct device_driver {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_2__ {struct snd_ac97_bus_ops* ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC97_VENDOR_ID1 ; 
 int /*<<< orphan*/  AC97_VENDOR_ID2 ; 
 int ENODEV ; 
 int stub1 (struct snd_ac97*,int /*<<< orphan*/ ) ; 
 int stub2 (struct snd_ac97*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (struct snd_ac97*) ; 
 int /*<<< orphan*/  stub4 (struct snd_ac97*) ; 
 int /*<<< orphan*/  stub5 (struct snd_ac97*) ; 

__attribute__((used)) static bool snd_ac97_check_id(struct snd_ac97 *ac97, unsigned int id,
	unsigned int id_mask)
{
	ac97->id = ac97->bus->ops->read(ac97, AC97_VENDOR_ID1) << 16;
	ac97->id |= ac97->bus->ops->read(ac97, AC97_VENDOR_ID2);

	if (ac97->id == 0x0 || ac97->id == 0xffffffff)
		return false;

	if (id != 0 && id != (ac97->id & id_mask))
		return false;

	return true;
}

int snd_ac97_reset(struct snd_ac97 *ac97, bool try_warm, unsigned int id,
	unsigned int id_mask)
{
	struct snd_ac97_bus_ops *ops = ac97->bus->ops;

	if (try_warm && ops->warm_reset) {
		ops->warm_reset(ac97);
		if (snd_ac97_check_id(ac97, id, id_mask))
			return 1;
	}

	if (ops->reset)
		ops->reset(ac97);
	if (ops->warm_reset)
		ops->warm_reset(ac97);

	if (snd_ac97_check_id(ac97, id, id_mask))
		return 0;

	return -ENODEV;
}

__attribute__((used)) static int ac97_bus_match(struct device *dev, struct device_driver *drv)
{
	return 1;
}

