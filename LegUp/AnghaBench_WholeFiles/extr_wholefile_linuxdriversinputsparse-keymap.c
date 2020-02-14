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
struct TYPE_2__ {unsigned int code; unsigned int value; } ;
typedef  struct key_entry {scalar_t__ type; unsigned int code; unsigned int keycode; TYPE_1__ sw; } const key_entry ;
struct input_keymap_entry {int flags; unsigned int index; unsigned int keycode; int len; int /*<<< orphan*/  scancode; } ;
struct input_dev {size_t keycodemax; int (* getkeycode ) (struct input_dev*,struct input_keymap_entry*) ;int (* setkeycode ) (struct input_dev*,struct input_keymap_entry const*,unsigned int*) ;struct key_entry const* keycode; int /*<<< orphan*/  mscbit; int /*<<< orphan*/  evbit; int /*<<< orphan*/  keybit; int /*<<< orphan*/  swbit; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 unsigned int EV_KEY ; 
 unsigned int EV_MSC ; 
 unsigned int EV_SW ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INPUT_KEYMAP_BY_INDEX ; 
 unsigned int KEY_UNKNOWN ; 
 scalar_t__ KE_END ; 
#define  KE_KEY 130 
#define  KE_SW 129 
#define  KE_VSW 128 
 unsigned int MSC_SCAN ; 
 int /*<<< orphan*/  __set_bit (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_bit (unsigned int,int /*<<< orphan*/ ) ; 
 struct key_entry const* devm_kmemdup (int /*<<< orphan*/ *,struct key_entry const*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  input_report_switch (struct input_dev*,unsigned int,unsigned int) ; 
 scalar_t__ input_scancode_to_scalar (struct input_keymap_entry const*,unsigned int*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,unsigned int*,int) ; 
 int /*<<< orphan*/  set_bit (unsigned int,int /*<<< orphan*/ ) ; 
 scalar_t__ test_bit (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int sparse_keymap_get_key_index(struct input_dev *dev,
						const struct key_entry *k)
{
	struct key_entry *key;
	unsigned int idx = 0;

	for (key = dev->keycode; key->type != KE_END; key++) {
		if (key->type == KE_KEY) {
			if (key == k)
				break;
			idx++;
		}
	}

	return idx;
}

__attribute__((used)) static struct key_entry *sparse_keymap_entry_by_index(struct input_dev *dev,
						      unsigned int index)
{
	struct key_entry *key;
	unsigned int key_cnt = 0;

	for (key = dev->keycode; key->type != KE_END; key++)
		if (key->type == KE_KEY)
			if (key_cnt++ == index)
				return key;

	return NULL;
}

struct key_entry *sparse_keymap_entry_from_scancode(struct input_dev *dev,
						    unsigned int code)
{
	struct key_entry *key;

	for (key = dev->keycode; key->type != KE_END; key++)
		if (code == key->code)
			return key;

	return NULL;
}

struct key_entry *sparse_keymap_entry_from_keycode(struct input_dev *dev,
						   unsigned int keycode)
{
	struct key_entry *key;

	for (key = dev->keycode; key->type != KE_END; key++)
		if (key->type == KE_KEY && keycode == key->keycode)
			return key;

	return NULL;
}

__attribute__((used)) static struct key_entry *sparse_keymap_locate(struct input_dev *dev,
					const struct input_keymap_entry *ke)
{
	struct key_entry *key;
	unsigned int scancode;

	if (ke->flags & INPUT_KEYMAP_BY_INDEX)
		key = sparse_keymap_entry_by_index(dev, ke->index);
	else if (input_scancode_to_scalar(ke, &scancode) == 0)
		key = sparse_keymap_entry_from_scancode(dev, scancode);
	else
		key = NULL;

	return key;
}

__attribute__((used)) static int sparse_keymap_getkeycode(struct input_dev *dev,
				    struct input_keymap_entry *ke)
{
	const struct key_entry *key;

	if (dev->keycode) {
		key = sparse_keymap_locate(dev, ke);
		if (key && key->type == KE_KEY) {
			ke->keycode = key->keycode;
			if (!(ke->flags & INPUT_KEYMAP_BY_INDEX))
				ke->index =
					sparse_keymap_get_key_index(dev, key);
			ke->len = sizeof(key->code);
			memcpy(ke->scancode, &key->code, sizeof(key->code));
			return 0;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int sparse_keymap_setkeycode(struct input_dev *dev,
				    const struct input_keymap_entry *ke,
				    unsigned int *old_keycode)
{
	struct key_entry *key;

	if (dev->keycode) {
		key = sparse_keymap_locate(dev, ke);
		if (key && key->type == KE_KEY) {
			*old_keycode = key->keycode;
			key->keycode = ke->keycode;
			set_bit(ke->keycode, dev->keybit);
			if (!sparse_keymap_entry_from_keycode(dev, *old_keycode))
				clear_bit(*old_keycode, dev->keybit);
			return 0;
		}
	}

	return -EINVAL;
}

int sparse_keymap_setup(struct input_dev *dev,
			const struct key_entry *keymap,
			int (*setup)(struct input_dev *, struct key_entry *))
{
	size_t map_size = 1; /* to account for the last KE_END entry */
	const struct key_entry *e;
	struct key_entry *map, *entry;
	int i;
	int error;

	for (e = keymap; e->type != KE_END; e++)
		map_size++;

	map = devm_kmemdup(&dev->dev, keymap, map_size * sizeof(*map),
			   GFP_KERNEL);
	if (!map)
		return -ENOMEM;

	for (i = 0; i < map_size; i++) {
		entry = &map[i];

		if (setup) {
			error = setup(dev, entry);
			if (error)
				return error;
		}

		switch (entry->type) {
		case KE_KEY:
			__set_bit(EV_KEY, dev->evbit);
			__set_bit(entry->keycode, dev->keybit);
			break;

		case KE_SW:
		case KE_VSW:
			__set_bit(EV_SW, dev->evbit);
			__set_bit(entry->sw.code, dev->swbit);
			break;
		}
	}

	if (test_bit(EV_KEY, dev->evbit)) {
		__set_bit(KEY_UNKNOWN, dev->keybit);
		__set_bit(EV_MSC, dev->evbit);
		__set_bit(MSC_SCAN, dev->mscbit);
	}

	dev->keycode = map;
	dev->keycodemax = map_size;
	dev->getkeycode = sparse_keymap_getkeycode;
	dev->setkeycode = sparse_keymap_setkeycode;

	return 0;
}

void sparse_keymap_report_entry(struct input_dev *dev, const struct key_entry *ke,
				unsigned int value, bool autorelease)
{
	switch (ke->type) {
	case KE_KEY:
		input_event(dev, EV_MSC, MSC_SCAN, ke->code);
		input_report_key(dev, ke->keycode, value);
		input_sync(dev);
		if (value && autorelease) {
			input_report_key(dev, ke->keycode, 0);
			input_sync(dev);
		}
		break;

	case KE_SW:
		value = ke->sw.value;
		/* fall through */

	case KE_VSW:
		input_report_switch(dev, ke->sw.code, value);
		input_sync(dev);
		break;
	}
}

bool sparse_keymap_report_event(struct input_dev *dev, unsigned int code,
				unsigned int value, bool autorelease)
{
	const struct key_entry *ke =
		sparse_keymap_entry_from_scancode(dev, code);
	struct key_entry unknown_ke;

	if (ke) {
		sparse_keymap_report_entry(dev, ke, value, autorelease);
		return true;
	}

	/* Report an unknown key event as a debugging aid */
	unknown_ke.type = KE_KEY;
	unknown_ke.code = code;
	unknown_ke.keycode = KEY_UNKNOWN;
	sparse_keymap_report_entry(dev, &unknown_ke, value, true);

	return false;
}

