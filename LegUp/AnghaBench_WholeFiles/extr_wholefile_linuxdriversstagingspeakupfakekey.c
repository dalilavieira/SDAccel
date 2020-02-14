#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_10__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_12__ {char* name; char* phys; int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; TYPE_2__ dev; TYPE_1__ id; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_VIRTUAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  KEY_DOWN ; 
 int /*<<< orphan*/  PRESSED ; 
 int /*<<< orphan*/  RELEASED ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __this_cpu_write (int /*<<< orphan*/ ,int) ; 
 TYPE_3__* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (TYPE_3__*) ; 
 int input_register_device (TYPE_3__*) ; 
 int /*<<< orphan*/  input_report_key (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (TYPE_3__*) ; 
 int /*<<< orphan*/  input_unregister_device (TYPE_3__*) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  reporting_keystroke ; 
 int this_cpu_read (int /*<<< orphan*/ ) ; 
 TYPE_3__* virt_keyboard ; 

int speakup_add_virtual_keyboard(void)
{
	int err;

	virt_keyboard = input_allocate_device();

	if (!virt_keyboard)
		return -ENOMEM;

	virt_keyboard->name = "Speakup";
	virt_keyboard->id.bustype = BUS_VIRTUAL;
	virt_keyboard->phys = "speakup/input0";
	virt_keyboard->dev.parent = NULL;

	__set_bit(EV_KEY, virt_keyboard->evbit);
	__set_bit(KEY_DOWN, virt_keyboard->keybit);

	err = input_register_device(virt_keyboard);
	if (err) {
		input_free_device(virt_keyboard);
		virt_keyboard = NULL;
	}

	return err;
}

void speakup_remove_virtual_keyboard(void)
{
	if (virt_keyboard) {
		input_unregister_device(virt_keyboard);
		virt_keyboard = NULL;
	}
}

void speakup_fake_down_arrow(void)
{
	unsigned long flags;

	/* disable keyboard interrupts */
	local_irq_save(flags);
	/* don't change CPU */
	preempt_disable();

	__this_cpu_write(reporting_keystroke, true);
	input_report_key(virt_keyboard, KEY_DOWN, PRESSED);
	input_report_key(virt_keyboard, KEY_DOWN, RELEASED);
	input_sync(virt_keyboard);
	__this_cpu_write(reporting_keystroke, false);

	/* reenable preemption */
	preempt_enable();
	/* reenable keyboard interrupts */
	local_irq_restore(flags);
}

bool speakup_fake_key_pressed(void)
{
	return this_cpu_read(reporting_keystroke);
}

