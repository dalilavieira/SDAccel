#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct tty_driver {int dummy; } ;
struct console {struct console* next; struct tty_driver* (* device ) (struct console*,int*) ;} ;
struct TYPE_6__ {int is_console; } ;
struct TYPE_5__ {int /*<<< orphan*/  d; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  con_debug_enter (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  con_debug_leave () ; 
 char* config ; 
 int configured ; 
 struct console* console_drivers ; 
 int dbg_restore_graphics ; 
 size_t fg_console ; 
 scalar_t__ isspace (char) ; 
 int /*<<< orphan*/  kgdb_connected ; 
 int kgdb_register_io_module (TYPE_2__*) ; 
 int kgdb_register_nmi_console () ; 
 struct tty_driver* kgdb_tty_driver ; 
 int kgdb_tty_line ; 
 int /*<<< orphan*/  kgdb_unregister_io_module (TYPE_2__*) ; 
 scalar_t__ kgdb_unregister_nmi_console () ; 
 TYPE_2__ kgdboc_io_ops ; 
 scalar_t__ kgdboc_register_kbd (char**) ; 
 int /*<<< orphan*/  kgdboc_restore_input () ; 
 int /*<<< orphan*/  kgdboc_unregister_kbd () ; 
 int kgdboc_use_kms ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 scalar_t__ strncmp (char*,char*,int) ; 
 struct tty_driver* stub1 (struct console*,int*) ; 
 int /*<<< orphan*/  try_module_get (int /*<<< orphan*/ ) ; 
 struct tty_driver* tty_find_polling_driver (char*,int*) ; 
 TYPE_1__* vc_cons ; 

__attribute__((used)) static void cleanup_kgdboc(void)
{
	if (kgdb_unregister_nmi_console())
		return;
	kgdboc_unregister_kbd();
	if (configured == 1)
		kgdb_unregister_io_module(&kgdboc_io_ops);
}

__attribute__((used)) static int configure_kgdboc(void)
{
	struct tty_driver *p;
	int tty_line = 0;
	int err = -ENODEV;
	char *cptr = config;
	struct console *cons;

	if (!strlen(config) || isspace(config[0])) {
		err = 0;
		goto noconfig;
	}

	kgdboc_io_ops.is_console = 0;
	kgdb_tty_driver = NULL;

	kgdboc_use_kms = 0;
	if (strncmp(cptr, "kms,", 4) == 0) {
		cptr += 4;
		kgdboc_use_kms = 1;
	}

	if (kgdboc_register_kbd(&cptr))
		goto do_register;

	p = tty_find_polling_driver(cptr, &tty_line);
	if (!p)
		goto noconfig;

	cons = console_drivers;
	while (cons) {
		int idx;
		if (cons->device && cons->device(cons, &idx) == p &&
		    idx == tty_line) {
			kgdboc_io_ops.is_console = 1;
			break;
		}
		cons = cons->next;
	}

	kgdb_tty_driver = p;
	kgdb_tty_line = tty_line;

do_register:
	err = kgdb_register_io_module(&kgdboc_io_ops);
	if (err)
		goto noconfig;

	err = kgdb_register_nmi_console();
	if (err)
		goto nmi_con_failed;

	configured = 1;

	return 0;

nmi_con_failed:
	kgdb_unregister_io_module(&kgdboc_io_ops);
noconfig:
	kgdboc_unregister_kbd();
	config[0] = 0;
	configured = 0;
	cleanup_kgdboc();

	return err;
}

__attribute__((used)) static void kgdboc_pre_exp_handler(void)
{
	if (!dbg_restore_graphics && kgdboc_use_kms) {
		dbg_restore_graphics = 1;
		con_debug_enter(vc_cons[fg_console].d);
	}
	/* Increment the module count when the debugger is active */
	if (!kgdb_connected)
		try_module_get(THIS_MODULE);
}

__attribute__((used)) static void kgdboc_post_exp_handler(void)
{
	/* decrement the module count when the debugger detaches */
	if (!kgdb_connected)
		module_put(THIS_MODULE);
	if (kgdboc_use_kms && dbg_restore_graphics) {
		dbg_restore_graphics = 0;
		con_debug_leave();
	}
	kgdboc_restore_input();
}

