#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_ac97 {int /*<<< orphan*/  dev; TYPE_2__* bus; } ;
struct regmap_config {int dummy; } ;
struct regmap {int dummy; } ;
struct lock_class_key {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_4__ {TYPE_1__* ops; } ;
struct TYPE_3__ {unsigned int (* read ) (struct snd_ac97*,unsigned int) ;int /*<<< orphan*/  (* write ) (struct snd_ac97*,unsigned int,unsigned int) ;} ;

/* Variables and functions */
#define  AC97_CODEC_CLASS_REV 144 
#define  AC97_EXTENDED_ID 143 
#define  AC97_EXTENDED_MID 142 
#define  AC97_EXTENDED_MSTATUS 141 
#define  AC97_EXTENDED_STATUS 140 
#define  AC97_FUNC_INFO 139 
#define  AC97_FUNC_SELECT 138 
#define  AC97_GPIO_STATUS 137 
#define  AC97_INT_PAGING 136 
#define  AC97_MISC_AFE 135 
#define  AC97_PCI_SID 134 
#define  AC97_PCI_SVID 133 
#define  AC97_POWERDOWN 132 
#define  AC97_RESET 131 
#define  AC97_SENSE_INFO 130 
#define  AC97_VENDOR_ID1 129 
#define  AC97_VENDOR_ID2 128 
 struct regmap* __devm_regmap_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct snd_ac97*,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 struct regmap* __regmap_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct snd_ac97*,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 int /*<<< orphan*/  ac97_regmap_bus ; 
 unsigned int stub1 (struct snd_ac97*,unsigned int) ; 
 int /*<<< orphan*/  stub2 (struct snd_ac97*,unsigned int,unsigned int) ; 

bool regmap_ac97_default_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case AC97_RESET:
	case AC97_POWERDOWN:
	case AC97_INT_PAGING:
	case AC97_EXTENDED_ID:
	case AC97_EXTENDED_STATUS:
	case AC97_EXTENDED_MID:
	case AC97_EXTENDED_MSTATUS:
	case AC97_GPIO_STATUS:
	case AC97_MISC_AFE:
	case AC97_VENDOR_ID1:
	case AC97_VENDOR_ID2:
	case AC97_CODEC_CLASS_REV:
	case AC97_PCI_SVID:
	case AC97_PCI_SID:
	case AC97_FUNC_SELECT:
	case AC97_FUNC_INFO:
	case AC97_SENSE_INFO:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int regmap_ac97_reg_read(void *context, unsigned int reg,
	unsigned int *val)
{
	struct snd_ac97 *ac97 = context;

	*val = ac97->bus->ops->read(ac97, reg);

	return 0;
}

__attribute__((used)) static int regmap_ac97_reg_write(void *context, unsigned int reg,
	unsigned int val)
{
	struct snd_ac97 *ac97 = context;

	ac97->bus->ops->write(ac97, reg, val);

	return 0;
}

struct regmap *__regmap_init_ac97(struct snd_ac97 *ac97,
				  const struct regmap_config *config,
				  struct lock_class_key *lock_key,
				  const char *lock_name)
{
	return __regmap_init(&ac97->dev, &ac97_regmap_bus, ac97, config,
			     lock_key, lock_name);
}

struct regmap *__devm_regmap_init_ac97(struct snd_ac97 *ac97,
				       const struct regmap_config *config,
				       struct lock_class_key *lock_key,
				       const char *lock_name)
{
	return __devm_regmap_init(&ac97->dev, &ac97_regmap_bus, ac97, config,
				  lock_key, lock_name);
}

