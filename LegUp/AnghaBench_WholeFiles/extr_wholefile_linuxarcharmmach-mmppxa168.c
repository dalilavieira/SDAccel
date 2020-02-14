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
struct pxa_device_desc {int dummy; } ;
struct pxa3xx_nand_platform_data {int /*<<< orphan*/  clear_wakeup_event; } ;
struct pxa27x_keypad_platform_data {int /*<<< orphan*/  clear_wakeup_event; } ;
struct pxa168fb_mach_info {int /*<<< orphan*/  clear_wakeup_event; } ;
struct pxa168_eth_platform_data {int /*<<< orphan*/  clear_wakeup_event; } ;
struct i2c_pxa_platform_data {int /*<<< orphan*/  clear_wakeup_event; } ;
struct i2c_board_info {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ cpu_is_pxa168 () ; 
 int i2c_register_board_info (int,struct i2c_board_info*,unsigned int) ; 
 int /*<<< orphan*/  pxa168_clear_keypad_wakeup ; 
 struct pxa_device_desc pxa168_device_eth ; 
 struct pxa_device_desc pxa168_device_fb ; 
 struct pxa_device_desc pxa168_device_keypad ; 
 struct pxa_device_desc pxa168_device_nand ; 
 struct pxa_device_desc pxa168_device_pwm1 ; 
 struct pxa_device_desc pxa168_device_pwm2 ; 
 struct pxa_device_desc pxa168_device_pwm3 ; 
 struct pxa_device_desc pxa168_device_pwm4 ; 
 struct pxa_device_desc pxa168_device_ssp1 ; 
 struct pxa_device_desc pxa168_device_ssp2 ; 
 struct pxa_device_desc pxa168_device_ssp3 ; 
 struct pxa_device_desc pxa168_device_ssp4 ; 
 struct pxa_device_desc pxa168_device_ssp5 ; 
 struct pxa_device_desc pxa168_device_twsi0 ; 
 struct pxa_device_desc pxa168_device_twsi1 ; 
 struct pxa_device_desc pxa168_device_uart1 ; 
 struct pxa_device_desc pxa168_device_uart2 ; 
 struct pxa_device_desc pxa168_device_uart3 ; 
 int pxa_register_device (struct pxa_device_desc*,struct pxa3xx_nand_platform_data*,int) ; 

__attribute__((used)) static inline int pxa168_add_uart(int id)
{
	struct pxa_device_desc *d = NULL;

	switch (id) {
	case 1: d = &pxa168_device_uart1; break;
	case 2: d = &pxa168_device_uart2; break;
	case 3: d = &pxa168_device_uart3; break;
	}

	if (d == NULL)
		return -EINVAL;

	return pxa_register_device(d, NULL, 0);
}

__attribute__((used)) static inline int pxa168_add_twsi(int id, struct i2c_pxa_platform_data *data,
				  struct i2c_board_info *info, unsigned size)
{
	struct pxa_device_desc *d = NULL;
	int ret;

	switch (id) {
	case 0: d = &pxa168_device_twsi0; break;
	case 1: d = &pxa168_device_twsi1; break;
	default:
		return -EINVAL;
	}

	ret = i2c_register_board_info(id, info, size);
	if (ret)
		return ret;

	return pxa_register_device(d, data, sizeof(*data));
}

__attribute__((used)) static inline int pxa168_add_pwm(int id)
{
	struct pxa_device_desc *d = NULL;

	switch (id) {
	case 1: d = &pxa168_device_pwm1; break;
	case 2: d = &pxa168_device_pwm2; break;
	case 3: d = &pxa168_device_pwm3; break;
	case 4: d = &pxa168_device_pwm4; break;
	default:
		return -EINVAL;
	}

	return pxa_register_device(d, NULL, 0);
}

__attribute__((used)) static inline int pxa168_add_ssp(int id)
{
	struct pxa_device_desc *d = NULL;

	switch (id) {
	case 1: d = &pxa168_device_ssp1; break;
	case 2: d = &pxa168_device_ssp2; break;
	case 3: d = &pxa168_device_ssp3; break;
	case 4: d = &pxa168_device_ssp4; break;
	case 5: d = &pxa168_device_ssp5; break;
	default:
		return -EINVAL;
	}
	return pxa_register_device(d, NULL, 0);
}

__attribute__((used)) static inline int pxa168_add_nand(struct pxa3xx_nand_platform_data *info)
{
	return pxa_register_device(&pxa168_device_nand, info, sizeof(*info));
}

__attribute__((used)) static inline int pxa168_add_fb(struct pxa168fb_mach_info *mi)
{
	return pxa_register_device(&pxa168_device_fb, mi, sizeof(*mi));
}

__attribute__((used)) static inline int pxa168_add_keypad(struct pxa27x_keypad_platform_data *data)
{
	if (cpu_is_pxa168())
		data->clear_wakeup_event = pxa168_clear_keypad_wakeup;

	return pxa_register_device(&pxa168_device_keypad, data, sizeof(*data));
}

__attribute__((used)) static inline int pxa168_add_eth(struct pxa168_eth_platform_data *data)
{
	return pxa_register_device(&pxa168_device_eth, data, sizeof(*data));
}

