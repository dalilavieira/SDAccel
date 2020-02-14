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
 unsigned int NUM_ADC ; 
 unsigned int NUM_CAN ; 
 unsigned int NUM_GPIO ; 
 unsigned int NUM_I2C ; 
 unsigned int NUM_OW ; 
 unsigned int NUM_PWM ; 
 unsigned int NUM_SPI ; 
 unsigned int NUM_TMR ; 
 unsigned int NUM_UART ; 

__attribute__((used)) static inline int platform_gpio_exists( unsigned pin ) { return pin < NUM_GPIO; }

__attribute__((used)) static inline int platform_can_exists( unsigned id ) { return NUM_CAN && (id < NUM_CAN); }

__attribute__((used)) static inline int platform_spi_exists( unsigned id ) { return id < NUM_SPI; }

__attribute__((used)) static inline int platform_uart_exists( unsigned id ) { return id < NUM_UART; }

__attribute__((used)) static inline int platform_pwm_exists( unsigned id ) { return ((id < NUM_PWM) && (id > 0)); }

__attribute__((used)) static inline int platform_adc_exists( unsigned id ) { return id < NUM_ADC; }

__attribute__((used)) static inline int platform_ow_exists( unsigned id ) { return ((id < NUM_OW) && (id > 0)); }

__attribute__((used)) static inline int platform_tmr_exists( unsigned id ) { return id < NUM_TMR; }

__attribute__((used)) static inline int platform_sigma_delta_exists( unsigned id ) {return ((id < NUM_GPIO) && (id > 0)); }

__attribute__((used)) static inline int platform_i2c_exists( unsigned id ) { return id < NUM_I2C; }

