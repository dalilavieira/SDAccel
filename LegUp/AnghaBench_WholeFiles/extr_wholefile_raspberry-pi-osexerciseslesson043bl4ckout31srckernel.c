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

/* Variables and functions */
 int copy_process (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  delay (int) ; 
 int /*<<< orphan*/  enable_interrupt_controller () ; 
 int /*<<< orphan*/  enable_irq () ; 
 unsigned int get_fpsimd_reg0 () ; 
 unsigned int get_fpsimd_reg2 () ; 
 unsigned int get_fpsimd_reg31 () ; 
 int /*<<< orphan*/  init_printf (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_vector_init () ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  putc ; 
 int /*<<< orphan*/  schedule () ; 
 int /*<<< orphan*/  set_fpsimd_reg0 (int) ; 
 int /*<<< orphan*/  set_fpsimd_reg2 (int) ; 
 int /*<<< orphan*/  set_fpsimd_reg31 (int) ; 
 int /*<<< orphan*/  timer_init () ; 
 int /*<<< orphan*/  uart_init () ; 
 int /*<<< orphan*/  uart_send (unsigned int) ; 

void process(char *array)
{
	if(array[0] == '1') {
		set_fpsimd_reg0(1);
		set_fpsimd_reg2(2);
		set_fpsimd_reg31(3);
	} else {
		set_fpsimd_reg0(5);
		set_fpsimd_reg2(6);
		set_fpsimd_reg31(7);
	}

	while (1) {
		for (int i = 0; i < 5; i++){
			unsigned int a = get_fpsimd_reg0();
			unsigned int b = get_fpsimd_reg2();
			unsigned int c = get_fpsimd_reg31();
			uart_send(a + '0');
			delay(100000);
			uart_send(b + '0');
			delay(100000);
			uart_send(c + '0');
			delay(100000);
		}
	}
}

void kernel_main(void)
{
	uart_init();
	init_printf(0, putc);
	irq_vector_init();
	timer_init();
	enable_interrupt_controller();
	enable_irq();

	int res = copy_process((unsigned long)&process, (unsigned long)"12345");
	if (res != 0) {
		printf("error while starting process 1");
		return;
	}
	res = copy_process((unsigned long)&process, (unsigned long)"abcde");
	if (res != 0) {
		printf("error while starting process 2");
		return;
	}

	while (1){
		schedule();
	}	
}

