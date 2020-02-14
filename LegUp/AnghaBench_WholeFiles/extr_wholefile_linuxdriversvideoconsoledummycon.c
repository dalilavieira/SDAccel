#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct vc_data {int vc_can_do_color; int /*<<< orphan*/  vc_rows; int /*<<< orphan*/  vc_cols; } ;
struct console_font {int dummy; } ;
typedef  enum con_scroll { ____Placeholder_con_scroll } con_scroll ;

/* Variables and functions */
 int /*<<< orphan*/  DUMMY_COLUMNS ; 
 int /*<<< orphan*/  DUMMY_ROWS ; 
 int /*<<< orphan*/  vc_resize (struct vc_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void dummycon_putc(struct vc_data *vc, int c, int ypos, int xpos) { }

__attribute__((used)) static void dummycon_putcs(struct vc_data *vc, const unsigned short *s,
			   int count, int ypos, int xpos) { }

__attribute__((used)) static int dummycon_blank(struct vc_data *vc, int blank, int mode_switch)
{
	return 0;
}

__attribute__((used)) static const char *dummycon_startup(void)
{
    return "dummy device";
}

__attribute__((used)) static void dummycon_init(struct vc_data *vc, int init)
{
    vc->vc_can_do_color = 1;
    if (init) {
	vc->vc_cols = DUMMY_COLUMNS;
	vc->vc_rows = DUMMY_ROWS;
    } else
	vc_resize(vc, DUMMY_COLUMNS, DUMMY_ROWS);
}

__attribute__((used)) static void dummycon_deinit(struct vc_data *vc) { }

__attribute__((used)) static void dummycon_clear(struct vc_data *vc, int sy, int sx, int height,
			   int width) { }

__attribute__((used)) static void dummycon_cursor(struct vc_data *vc, int mode) { }

__attribute__((used)) static bool dummycon_scroll(struct vc_data *vc, unsigned int top,
			    unsigned int bottom, enum con_scroll dir,
			    unsigned int lines)
{
	return false;
}

__attribute__((used)) static int dummycon_switch(struct vc_data *vc)
{
	return 0;
}

__attribute__((used)) static int dummycon_font_set(struct vc_data *vc, struct console_font *font,
			     unsigned int flags)
{
	return 0;
}

__attribute__((used)) static int dummycon_font_default(struct vc_data *vc,
				 struct console_font *font, char *name)
{
	return 0;
}

__attribute__((used)) static int dummycon_font_copy(struct vc_data *vc, int con)
{
	return 0;
}

