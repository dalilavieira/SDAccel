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
struct console {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  Q40_LED_ON () ; 
 unsigned int _cpleft ; 
 int halted ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/ * q40_mem_cptr ; 
 int /*<<< orphan*/  sprintf (char*,char*) ; 

__attribute__((used)) static void q40_mem_console_write(struct console *co, const char *s,
				  unsigned int count)
{
	const char *p = s;

	if (count < _cpleft) {
		while (count-- > 0) {
			*q40_mem_cptr = *p++;
			q40_mem_cptr += 4;
			_cpleft--;
		}
	}
}

__attribute__((used)) static void q40_reset(void)
{
	halted = 1;
	pr_info("*******************************************\n"
		"Called q40_reset : press the RESET button!!\n"
		"*******************************************\n");
	Q40_LED_ON();
	while (1)
		;
}

__attribute__((used)) static void q40_halt(void)
{
	halted = 1;
	pr_info("*******************\n"
		"  Called q40_halt\n"
		"*******************\n");
	Q40_LED_ON();
	while (1)
		;
}

__attribute__((used)) static void q40_get_model(char *model)
{
	sprintf(model, "Q40");
}

