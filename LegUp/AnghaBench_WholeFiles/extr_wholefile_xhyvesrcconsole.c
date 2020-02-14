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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct bhyvegc_image {int dummy; } ;
typedef  int /*<<< orphan*/  (* ptr_event_func_t ) (int /*<<< orphan*/ ,int,int,void*) ;
typedef  int /*<<< orphan*/  (* kbd_event_func_t ) (int,int /*<<< orphan*/ ,void*) ;
typedef  int /*<<< orphan*/  (* fb_render_func_t ) (int /*<<< orphan*/ ,void*) ;
struct TYPE_2__ {int kbd_priority; int ptr_priority; void* ptr_arg; int /*<<< orphan*/  (* ptr_event_cb ) (int /*<<< orphan*/ ,int,int,void*) ;void* kbd_arg; int /*<<< orphan*/  (* kbd_event_cb ) (int,int /*<<< orphan*/ ,void*) ;void* fb_arg; int /*<<< orphan*/  gc; int /*<<< orphan*/  (* fb_render_cb ) (int /*<<< orphan*/ ,void*) ;} ;

/* Variables and functions */
 struct bhyvegc_image* bhyvegc_get_image (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bhyvegc_init (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  bhyvegc_set_fbaddr (int /*<<< orphan*/ ,void*) ; 
 TYPE_1__ console ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub2 (int,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,int,int,void*) ; 

void
console_init(uint16_t w, uint16_t h, void *fbaddr)
{
	console.gc = bhyvegc_init(w, h, fbaddr);
}

void
console_set_fbaddr(void *fbaddr)
{
	bhyvegc_set_fbaddr(console.gc, fbaddr);
}

struct bhyvegc_image *
console_get_image(void)
{
	struct bhyvegc_image *bhyvegc_image;

	bhyvegc_image = bhyvegc_get_image(console.gc);

	return (bhyvegc_image);
}

void
console_fb_register(fb_render_func_t render_cb, void *arg)
{
	console.fb_render_cb = render_cb;
	console.fb_arg = arg;
}

void
console_refresh(void)
{
	if (console.fb_render_cb)
		(*console.fb_render_cb)(console.gc, console.fb_arg);
}

void
console_kbd_register(kbd_event_func_t event_cb, void *arg, int pri)
{
	if (pri > console.kbd_priority) {
		console.kbd_event_cb = event_cb;
		console.kbd_arg = arg;
		console.kbd_priority = pri;
	}
}

void
console_ptr_register(ptr_event_func_t event_cb, void *arg, int pri)
{
	if (pri > console.ptr_priority) {
		console.ptr_event_cb = event_cb;
		console.ptr_arg = arg;
		console.ptr_priority = pri;
	}
}

void
console_key_event(int down, uint32_t keysym)
{
	if (console.kbd_event_cb)
		(*console.kbd_event_cb)(down, keysym, console.kbd_arg);
}

void
console_ptr_event(uint8_t button, int x, int y)
{
	if (console.ptr_event_cb)
		(*console.ptr_event_cb)(button, x, y, console.ptr_arg);
}

