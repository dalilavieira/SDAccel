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
typedef  int /*<<< orphan*/  u8 ;
struct device {int dummy; } ;
struct da9052_pdata {int /*<<< orphan*/  (* init ) (struct da9052*) ;} ;
struct da9052 {int /*<<< orphan*/  dev; int /*<<< orphan*/  chip_id; int /*<<< orphan*/  done; int /*<<< orphan*/  auxadc_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
#define  DA9052_ADCIN4_RES_REG 254 
#define  DA9052_ADCIN5_RES_REG 253 
#define  DA9052_ADCIN6_RES_REG 252 
#define  DA9052_ADC_CONT_REG 251 
 unsigned char DA9052_ADC_MAN_MAN_CONV ; 
#define  DA9052_ADC_MAN_REG 250 
#define  DA9052_ADC_RES_H_REG 249 
 int DA9052_ADC_RES_LSB ; 
#define  DA9052_ADC_RES_L_REG 248 
 unsigned char DA9052_ADC_VBBAT ; 
#define  DA9052_ALARM_D_REG 247 
#define  DA9052_ALARM_H_REG 246 
#define  DA9052_ALARM_MI_REG 245 
#define  DA9052_ALARM_MO_REG 244 
#define  DA9052_ALARM_Y_REG 243 
#define  DA9052_AUTO4_HIGH_REG 242 
#define  DA9052_AUTO4_LOW_REG 241 
#define  DA9052_AUTO5_HIGH_REG 240 
#define  DA9052_AUTO5_LOW_REG 239 
#define  DA9052_AUTO6_HIGH_REG 238 
#define  DA9052_AUTO6_LOW_REG 237 
#define  DA9052_BATCHG_REG 236 
#define  DA9052_BBAT_CONT_REG 235 
#define  DA9052_BOOST_REG 234 
#define  DA9052_BUCKA_REG 233 
#define  DA9052_BUCKB_REG 232 
#define  DA9052_BUCKCORE_REG 231 
#define  DA9052_BUCKMEM_REG 230 
#define  DA9052_BUCKPERI_REG 229 
#define  DA9052_BUCKPRO_REG 228 
#define  DA9052_CHGBUCK_REG 227 
#define  DA9052_CHG_CONT_REG 226 
#define  DA9052_CHG_TIME_REG 225 
#define  DA9052_CONTROL_A_REG 224 
#define  DA9052_CONTROL_B_REG 223 
#define  DA9052_CONTROL_C_REG 222 
#define  DA9052_CONTROL_D_REG 221 
#define  DA9052_COUNT_D_REG 220 
#define  DA9052_COUNT_H_REG 219 
#define  DA9052_COUNT_MI_REG 218 
#define  DA9052_COUNT_MO_REG 217 
#define  DA9052_COUNT_S_REG 216 
#define  DA9052_COUNT_Y_REG 215 
#define  DA9052_EVENT_A_REG 214 
#define  DA9052_EVENT_B_REG 213 
#define  DA9052_EVENT_C_REG 212 
#define  DA9052_EVENT_D_REG 211 
 int DA9052_FAULTLOG_KEYSHUT ; 
 int DA9052_FAULTLOG_NSDSET ; 
#define  DA9052_FAULTLOG_REG 210 
 int DA9052_FAULTLOG_TEMPOVER ; 
 int DA9052_FAULTLOG_TWDERROR ; 
 int DA9052_FAULTLOG_VDDFAULT ; 
 int DA9052_FAULTLOG_VDDSTART ; 
 int DA9052_FAULTLOG_WAITSET ; 
#define  DA9052_GPIO_0_1_REG 209 
#define  DA9052_GPIO_10_11_REG 208 
#define  DA9052_GPIO_12_13_REG 207 
#define  DA9052_GPIO_14_15_REG 206 
#define  DA9052_GPIO_2_3_REG 205 
#define  DA9052_GPIO_4_5_REG 204 
#define  DA9052_GPIO_6_7_REG 203 
#define  DA9052_GPIO_8_9_REG 202 
#define  DA9052_ICHG_AV_REG 201 
#define  DA9052_ICHG_END_REG 200 
#define  DA9052_ICHG_THD_REG 199 
#define  DA9052_ID_0_1_REG 198 
#define  DA9052_ID_10_11_REG 197 
#define  DA9052_ID_12_13_REG 196 
#define  DA9052_ID_14_15_REG 195 
#define  DA9052_ID_16_17_REG 194 
#define  DA9052_ID_18_19_REG 193 
#define  DA9052_ID_20_21_REG 192 
#define  DA9052_ID_2_3_REG 191 
#define  DA9052_ID_4_5_REG 190 
#define  DA9052_ID_6_7_REG 189 
#define  DA9052_ID_8_9_REG 188 
#define  DA9052_INPUT_CONT_REG 187 
#define  DA9052_INTERFACE_REG 186 
#define  DA9052_IRQ_MASK_A_REG 185 
#define  DA9052_IRQ_MASK_B_REG 184 
#define  DA9052_IRQ_MASK_C_REG 183 
#define  DA9052_IRQ_MASK_D_REG 182 
#define  DA9052_ISET_REG 181 
#define  DA9052_LDO10_REG 180 
#define  DA9052_LDO1_REG 179 
#define  DA9052_LDO2_REG 178 
#define  DA9052_LDO3_REG 177 
#define  DA9052_LDO4_REG 176 
#define  DA9052_LDO5_REG 175 
#define  DA9052_LDO6_REG 174 
#define  DA9052_LDO7_REG 173 
#define  DA9052_LDO8_REG 172 
#define  DA9052_LDO9_REG 171 
#define  DA9052_LED1CONT_REG 170 
#define  DA9052_LED1_CONF_REG 169 
#define  DA9052_LED2CONT_REG 168 
#define  DA9052_LED2_CONF_REG 167 
#define  DA9052_LED3CONT_REG 166 
#define  DA9052_LED3_CONF_REG 165 
#define  DA9052_LEDMIN123_REG 164 
#define  DA9052_LED_CONT_4_REG 163 
#define  DA9052_LED_CONT_5_REG 162 
#define  DA9052_LED_CONT_REG 161 
#define  DA9052_PAGE0_CON_REG 160 
#define  DA9052_PAGE1_CON_REG 159 
#define  DA9052_PDDIS_REG 158 
#define  DA9052_PULLDOWN_REG 157 
#define  DA9052_RESET_REG 156 
#define  DA9052_SECOND_A_REG 155 
#define  DA9052_SECOND_B_REG 154 
#define  DA9052_SECOND_C_REG 153 
#define  DA9052_SECOND_D_REG 152 
#define  DA9052_SEQ_A_REG 151 
#define  DA9052_SEQ_B_REG 150 
#define  DA9052_SEQ_STATUS_REG 149 
#define  DA9052_SEQ_TIMER_REG 148 
#define  DA9052_STATUS_A_REG 147 
#define  DA9052_STATUS_B_REG 146 
#define  DA9052_STATUS_C_REG 145 
#define  DA9052_STATUS_D_REG 144 
#define  DA9052_SUPPLY_REG 143 
#define  DA9052_TBAT_HIGHN_REG 142 
#define  DA9052_TBAT_HIGHP_REG 141 
#define  DA9052_TBAT_LOW_REG 140 
#define  DA9052_TBAT_RES_REG 139 
#define  DA9052_TJUNC_RES_REG 138 
#define  DA9052_TSI_CONT_A_REG 137 
#define  DA9052_TSI_CONT_B_REG 136 
#define  DA9052_TSI_LSB_REG 135 
#define  DA9052_TSI_X_MSB_REG 134 
#define  DA9052_TSI_Y_MSB_REG 133 
#define  DA9052_TSI_Z_MSB_REG 132 
#define  DA9052_T_OFFSET_REG 131 
#define  DA9052_VDD_MON_REG 130 
#define  DA9052_VDD_RES_REG 129 
#define  DA9052_WAITCONT_REG 128 
 int EINVAL ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  PLATFORM_DEVID_AUTO ; 
 unsigned char* chan_mux ; 
 int /*<<< orphan*/  da9052_irq_exit (struct da9052*) ; 
 int da9052_irq_init (struct da9052*) ; 
 int da9052_reg_read (struct da9052*,int const) ; 
 int da9052_reg_write (struct da9052*,int const,int) ; 
 int /*<<< orphan*/  da9052_subdev_info ; 
 int /*<<< orphan*/  da9052_tsi_subdev_info ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 struct da9052_pdata* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  device_property_read_bool (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int mfd_add_devices (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct da9052*) ; 
 int* tbat_lookup ; 
 int /*<<< orphan*/  wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool da9052_reg_readable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case DA9052_PAGE0_CON_REG:
	case DA9052_STATUS_A_REG:
	case DA9052_STATUS_B_REG:
	case DA9052_STATUS_C_REG:
	case DA9052_STATUS_D_REG:
	case DA9052_EVENT_A_REG:
	case DA9052_EVENT_B_REG:
	case DA9052_EVENT_C_REG:
	case DA9052_EVENT_D_REG:
	case DA9052_FAULTLOG_REG:
	case DA9052_IRQ_MASK_A_REG:
	case DA9052_IRQ_MASK_B_REG:
	case DA9052_IRQ_MASK_C_REG:
	case DA9052_IRQ_MASK_D_REG:
	case DA9052_CONTROL_A_REG:
	case DA9052_CONTROL_B_REG:
	case DA9052_CONTROL_C_REG:
	case DA9052_CONTROL_D_REG:
	case DA9052_PDDIS_REG:
	case DA9052_INTERFACE_REG:
	case DA9052_RESET_REG:
	case DA9052_GPIO_0_1_REG:
	case DA9052_GPIO_2_3_REG:
	case DA9052_GPIO_4_5_REG:
	case DA9052_GPIO_6_7_REG:
	case DA9052_GPIO_8_9_REG:
	case DA9052_GPIO_10_11_REG:
	case DA9052_GPIO_12_13_REG:
	case DA9052_GPIO_14_15_REG:
	case DA9052_ID_0_1_REG:
	case DA9052_ID_2_3_REG:
	case DA9052_ID_4_5_REG:
	case DA9052_ID_6_7_REG:
	case DA9052_ID_8_9_REG:
	case DA9052_ID_10_11_REG:
	case DA9052_ID_12_13_REG:
	case DA9052_ID_14_15_REG:
	case DA9052_ID_16_17_REG:
	case DA9052_ID_18_19_REG:
	case DA9052_ID_20_21_REG:
	case DA9052_SEQ_STATUS_REG:
	case DA9052_SEQ_A_REG:
	case DA9052_SEQ_B_REG:
	case DA9052_SEQ_TIMER_REG:
	case DA9052_BUCKA_REG:
	case DA9052_BUCKB_REG:
	case DA9052_BUCKCORE_REG:
	case DA9052_BUCKPRO_REG:
	case DA9052_BUCKMEM_REG:
	case DA9052_BUCKPERI_REG:
	case DA9052_LDO1_REG:
	case DA9052_LDO2_REG:
	case DA9052_LDO3_REG:
	case DA9052_LDO4_REG:
	case DA9052_LDO5_REG:
	case DA9052_LDO6_REG:
	case DA9052_LDO7_REG:
	case DA9052_LDO8_REG:
	case DA9052_LDO9_REG:
	case DA9052_LDO10_REG:
	case DA9052_SUPPLY_REG:
	case DA9052_PULLDOWN_REG:
	case DA9052_CHGBUCK_REG:
	case DA9052_WAITCONT_REG:
	case DA9052_ISET_REG:
	case DA9052_BATCHG_REG:
	case DA9052_CHG_CONT_REG:
	case DA9052_INPUT_CONT_REG:
	case DA9052_CHG_TIME_REG:
	case DA9052_BBAT_CONT_REG:
	case DA9052_BOOST_REG:
	case DA9052_LED_CONT_REG:
	case DA9052_LEDMIN123_REG:
	case DA9052_LED1_CONF_REG:
	case DA9052_LED2_CONF_REG:
	case DA9052_LED3_CONF_REG:
	case DA9052_LED1CONT_REG:
	case DA9052_LED2CONT_REG:
	case DA9052_LED3CONT_REG:
	case DA9052_LED_CONT_4_REG:
	case DA9052_LED_CONT_5_REG:
	case DA9052_ADC_MAN_REG:
	case DA9052_ADC_CONT_REG:
	case DA9052_ADC_RES_L_REG:
	case DA9052_ADC_RES_H_REG:
	case DA9052_VDD_RES_REG:
	case DA9052_VDD_MON_REG:
	case DA9052_ICHG_AV_REG:
	case DA9052_ICHG_THD_REG:
	case DA9052_ICHG_END_REG:
	case DA9052_TBAT_RES_REG:
	case DA9052_TBAT_HIGHP_REG:
	case DA9052_TBAT_HIGHN_REG:
	case DA9052_TBAT_LOW_REG:
	case DA9052_T_OFFSET_REG:
	case DA9052_ADCIN4_RES_REG:
	case DA9052_AUTO4_HIGH_REG:
	case DA9052_AUTO4_LOW_REG:
	case DA9052_ADCIN5_RES_REG:
	case DA9052_AUTO5_HIGH_REG:
	case DA9052_AUTO5_LOW_REG:
	case DA9052_ADCIN6_RES_REG:
	case DA9052_AUTO6_HIGH_REG:
	case DA9052_AUTO6_LOW_REG:
	case DA9052_TJUNC_RES_REG:
	case DA9052_TSI_CONT_A_REG:
	case DA9052_TSI_CONT_B_REG:
	case DA9052_TSI_X_MSB_REG:
	case DA9052_TSI_Y_MSB_REG:
	case DA9052_TSI_LSB_REG:
	case DA9052_TSI_Z_MSB_REG:
	case DA9052_COUNT_S_REG:
	case DA9052_COUNT_MI_REG:
	case DA9052_COUNT_H_REG:
	case DA9052_COUNT_D_REG:
	case DA9052_COUNT_MO_REG:
	case DA9052_COUNT_Y_REG:
	case DA9052_ALARM_MI_REG:
	case DA9052_ALARM_H_REG:
	case DA9052_ALARM_D_REG:
	case DA9052_ALARM_MO_REG:
	case DA9052_ALARM_Y_REG:
	case DA9052_SECOND_A_REG:
	case DA9052_SECOND_B_REG:
	case DA9052_SECOND_C_REG:
	case DA9052_SECOND_D_REG:
	case DA9052_PAGE1_CON_REG:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool da9052_reg_writeable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case DA9052_PAGE0_CON_REG:
	case DA9052_EVENT_A_REG:
	case DA9052_EVENT_B_REG:
	case DA9052_EVENT_C_REG:
	case DA9052_EVENT_D_REG:
	case DA9052_FAULTLOG_REG:
	case DA9052_IRQ_MASK_A_REG:
	case DA9052_IRQ_MASK_B_REG:
	case DA9052_IRQ_MASK_C_REG:
	case DA9052_IRQ_MASK_D_REG:
	case DA9052_CONTROL_A_REG:
	case DA9052_CONTROL_B_REG:
	case DA9052_CONTROL_C_REG:
	case DA9052_CONTROL_D_REG:
	case DA9052_PDDIS_REG:
	case DA9052_RESET_REG:
	case DA9052_GPIO_0_1_REG:
	case DA9052_GPIO_2_3_REG:
	case DA9052_GPIO_4_5_REG:
	case DA9052_GPIO_6_7_REG:
	case DA9052_GPIO_8_9_REG:
	case DA9052_GPIO_10_11_REG:
	case DA9052_GPIO_12_13_REG:
	case DA9052_GPIO_14_15_REG:
	case DA9052_ID_0_1_REG:
	case DA9052_ID_2_3_REG:
	case DA9052_ID_4_5_REG:
	case DA9052_ID_6_7_REG:
	case DA9052_ID_8_9_REG:
	case DA9052_ID_10_11_REG:
	case DA9052_ID_12_13_REG:
	case DA9052_ID_14_15_REG:
	case DA9052_ID_16_17_REG:
	case DA9052_ID_18_19_REG:
	case DA9052_ID_20_21_REG:
	case DA9052_SEQ_STATUS_REG:
	case DA9052_SEQ_A_REG:
	case DA9052_SEQ_B_REG:
	case DA9052_SEQ_TIMER_REG:
	case DA9052_BUCKA_REG:
	case DA9052_BUCKB_REG:
	case DA9052_BUCKCORE_REG:
	case DA9052_BUCKPRO_REG:
	case DA9052_BUCKMEM_REG:
	case DA9052_BUCKPERI_REG:
	case DA9052_LDO1_REG:
	case DA9052_LDO2_REG:
	case DA9052_LDO3_REG:
	case DA9052_LDO4_REG:
	case DA9052_LDO5_REG:
	case DA9052_LDO6_REG:
	case DA9052_LDO7_REG:
	case DA9052_LDO8_REG:
	case DA9052_LDO9_REG:
	case DA9052_LDO10_REG:
	case DA9052_SUPPLY_REG:
	case DA9052_PULLDOWN_REG:
	case DA9052_CHGBUCK_REG:
	case DA9052_WAITCONT_REG:
	case DA9052_ISET_REG:
	case DA9052_BATCHG_REG:
	case DA9052_CHG_CONT_REG:
	case DA9052_INPUT_CONT_REG:
	case DA9052_BBAT_CONT_REG:
	case DA9052_BOOST_REG:
	case DA9052_LED_CONT_REG:
	case DA9052_LEDMIN123_REG:
	case DA9052_LED1_CONF_REG:
	case DA9052_LED2_CONF_REG:
	case DA9052_LED3_CONF_REG:
	case DA9052_LED1CONT_REG:
	case DA9052_LED2CONT_REG:
	case DA9052_LED3CONT_REG:
	case DA9052_LED_CONT_4_REG:
	case DA9052_LED_CONT_5_REG:
	case DA9052_ADC_MAN_REG:
	case DA9052_ADC_CONT_REG:
	case DA9052_ADC_RES_L_REG:
	case DA9052_ADC_RES_H_REG:
	case DA9052_VDD_RES_REG:
	case DA9052_VDD_MON_REG:
	case DA9052_ICHG_THD_REG:
	case DA9052_ICHG_END_REG:
	case DA9052_TBAT_HIGHP_REG:
	case DA9052_TBAT_HIGHN_REG:
	case DA9052_TBAT_LOW_REG:
	case DA9052_T_OFFSET_REG:
	case DA9052_AUTO4_HIGH_REG:
	case DA9052_AUTO4_LOW_REG:
	case DA9052_AUTO5_HIGH_REG:
	case DA9052_AUTO5_LOW_REG:
	case DA9052_AUTO6_HIGH_REG:
	case DA9052_AUTO6_LOW_REG:
	case DA9052_TSI_CONT_A_REG:
	case DA9052_TSI_CONT_B_REG:
	case DA9052_COUNT_S_REG:
	case DA9052_COUNT_MI_REG:
	case DA9052_COUNT_H_REG:
	case DA9052_COUNT_D_REG:
	case DA9052_COUNT_MO_REG:
	case DA9052_COUNT_Y_REG:
	case DA9052_ALARM_MI_REG:
	case DA9052_ALARM_H_REG:
	case DA9052_ALARM_D_REG:
	case DA9052_ALARM_MO_REG:
	case DA9052_ALARM_Y_REG:
	case DA9052_PAGE1_CON_REG:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool da9052_reg_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case DA9052_STATUS_A_REG:
	case DA9052_STATUS_B_REG:
	case DA9052_STATUS_C_REG:
	case DA9052_STATUS_D_REG:
	case DA9052_EVENT_A_REG:
	case DA9052_EVENT_B_REG:
	case DA9052_EVENT_C_REG:
	case DA9052_EVENT_D_REG:
	case DA9052_CONTROL_B_REG:
	case DA9052_CONTROL_D_REG:
	case DA9052_SUPPLY_REG:
	case DA9052_FAULTLOG_REG:
	case DA9052_CHG_TIME_REG:
	case DA9052_ADC_RES_L_REG:
	case DA9052_ADC_RES_H_REG:
	case DA9052_VDD_RES_REG:
	case DA9052_ICHG_AV_REG:
	case DA9052_TBAT_RES_REG:
	case DA9052_ADCIN4_RES_REG:
	case DA9052_ADCIN5_RES_REG:
	case DA9052_ADCIN6_RES_REG:
	case DA9052_TJUNC_RES_REG:
	case DA9052_TSI_X_MSB_REG:
	case DA9052_TSI_Y_MSB_REG:
	case DA9052_TSI_LSB_REG:
	case DA9052_TSI_Z_MSB_REG:
	case DA9052_COUNT_S_REG:
	case DA9052_COUNT_MI_REG:
	case DA9052_COUNT_H_REG:
	case DA9052_COUNT_D_REG:
	case DA9052_COUNT_MO_REG:
	case DA9052_COUNT_Y_REG:
	case DA9052_ALARM_MI_REG:
		return true;
	default:
		return false;
	}
}

int da9052_adc_manual_read(struct da9052 *da9052, unsigned char channel)
{
	int ret;
	unsigned short calc_data;
	unsigned short data;
	unsigned char mux_sel;

	if (channel > DA9052_ADC_VBBAT)
		return -EINVAL;

	mutex_lock(&da9052->auxadc_lock);

	reinit_completion(&da9052->done);

	/* Channel gets activated on enabling the Conversion bit */
	mux_sel = chan_mux[channel] | DA9052_ADC_MAN_MAN_CONV;

	ret = da9052_reg_write(da9052, DA9052_ADC_MAN_REG, mux_sel);
	if (ret < 0)
		goto err;

	/* Wait for an interrupt */
	if (!wait_for_completion_timeout(&da9052->done,
					 msecs_to_jiffies(500))) {
		dev_err(da9052->dev,
			"timeout waiting for ADC conversion interrupt\n");
		ret = -ETIMEDOUT;
		goto err;
	}

	ret = da9052_reg_read(da9052, DA9052_ADC_RES_H_REG);
	if (ret < 0)
		goto err;

	calc_data = (unsigned short)ret;
	data = calc_data << 2;

	ret = da9052_reg_read(da9052, DA9052_ADC_RES_L_REG);
	if (ret < 0)
		goto err;

	calc_data = (unsigned short)(ret & DA9052_ADC_RES_LSB);
	data |= calc_data;

	ret = data;

err:
	mutex_unlock(&da9052->auxadc_lock);
	return ret;
}

int da9052_adc_read_temp(struct da9052 *da9052)
{
	int tbat;

	tbat = da9052_reg_read(da9052, DA9052_TBAT_RES_REG);
	if (tbat <= 0)
		return tbat;

	/* ARRAY_SIZE check is not needed since TBAT is a 8-bit register */
	return tbat_lookup[tbat - 1];
}

__attribute__((used)) static int da9052_clear_fault_log(struct da9052 *da9052)
{
	int ret = 0;
	int fault_log = 0;

	fault_log = da9052_reg_read(da9052, DA9052_FAULTLOG_REG);
	if (fault_log < 0) {
		dev_err(da9052->dev,
			"Cannot read FAULT_LOG %d\n", fault_log);
		return fault_log;
	}

	if (fault_log) {
		if (fault_log & DA9052_FAULTLOG_TWDERROR)
			dev_dbg(da9052->dev,
				"Fault log entry detected: TWD_ERROR\n");
		if (fault_log & DA9052_FAULTLOG_VDDFAULT)
			dev_dbg(da9052->dev,
				"Fault log entry detected: VDD_FAULT\n");
		if (fault_log & DA9052_FAULTLOG_VDDSTART)
			dev_dbg(da9052->dev,
				"Fault log entry detected: VDD_START\n");
		if (fault_log & DA9052_FAULTLOG_TEMPOVER)
			dev_dbg(da9052->dev,
				"Fault log entry detected: TEMP_OVER\n");
		if (fault_log & DA9052_FAULTLOG_KEYSHUT)
			dev_dbg(da9052->dev,
				"Fault log entry detected: KEY_SHUT\n");
		if (fault_log & DA9052_FAULTLOG_NSDSET)
			dev_dbg(da9052->dev,
				"Fault log entry detected: nSD_SHUT\n");
		if (fault_log & DA9052_FAULTLOG_WAITSET)
			dev_dbg(da9052->dev,
				"Fault log entry detected: WAIT_SHUT\n");

		ret = da9052_reg_write(da9052,
					DA9052_FAULTLOG_REG,
					0xFF);
		if (ret < 0)
			dev_err(da9052->dev,
				"Cannot reset FAULT_LOG values %d\n", ret);
	}

	return ret;
}

int da9052_device_init(struct da9052 *da9052, u8 chip_id)
{
	struct da9052_pdata *pdata = dev_get_platdata(da9052->dev);
	int ret;

	mutex_init(&da9052->auxadc_lock);
	init_completion(&da9052->done);

	ret = da9052_clear_fault_log(da9052);
	if (ret < 0)
		dev_warn(da9052->dev, "Cannot clear FAULT_LOG\n");

	if (pdata && pdata->init != NULL)
		pdata->init(da9052);

	da9052->chip_id = chip_id;

	ret = da9052_irq_init(da9052);
	if (ret != 0) {
		dev_err(da9052->dev, "da9052_irq_init failed: %d\n", ret);
		return ret;
	}

	ret = mfd_add_devices(da9052->dev, PLATFORM_DEVID_AUTO,
			      da9052_subdev_info,
			      ARRAY_SIZE(da9052_subdev_info), NULL, 0, NULL);
	if (ret) {
		dev_err(da9052->dev, "mfd_add_devices failed: %d\n", ret);
		goto err;
	}

	/*
	 * Check if touchscreen pins are used are analogue input instead
	 * of having a touchscreen connected to them. The analogue input
	 * functionality will be provided by hwmon driver (if enabled).
	 */
	if (!device_property_read_bool(da9052->dev, "dlg,tsi-as-adc")) {
		ret = mfd_add_devices(da9052->dev, PLATFORM_DEVID_AUTO,
				      da9052_tsi_subdev_info,
				      ARRAY_SIZE(da9052_tsi_subdev_info),
				      NULL, 0, NULL);
		if (ret) {
			dev_err(da9052->dev, "failed to add TSI subdev: %d\n",
				ret);
			goto err;
		}
	}

	return 0;

err:
	mfd_remove_devices(da9052->dev);
	da9052_irq_exit(da9052);

	return ret;
}

void da9052_device_exit(struct da9052 *da9052)
{
	mfd_remove_devices(da9052->dev);
	da9052_irq_exit(da9052);
}

