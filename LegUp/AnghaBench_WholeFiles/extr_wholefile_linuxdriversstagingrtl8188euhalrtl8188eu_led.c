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
typedef  int u8 ;
struct led_priv {int /*<<< orphan*/  SwLed0; } ;
struct adapter {struct led_priv ledpriv; scalar_t__ bDriverStopped; scalar_t__ bSurpriseRemoved; } ;
struct LED_871x {int bLedOn; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  DeInitLed871x (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InitLed871x (struct adapter*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  REG_LEDCFG2 ; 
 int /*<<< orphan*/  REG_MAC_PINMUX_CFG ; 
 int usb_read8 (struct adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_write8 (struct adapter*,int /*<<< orphan*/ ,int) ; 

void SwLedOn(struct adapter *padapter, struct LED_871x *pLed)
{
	u8	LedCfg;

	if (padapter->bSurpriseRemoved || padapter->bDriverStopped)
		return;
	LedCfg = usb_read8(padapter, REG_LEDCFG2);
	usb_write8(padapter, REG_LEDCFG2, (LedCfg&0xf0) | BIT(5) | BIT(6)); /*  SW control led0 on. */
	pLed->bLedOn = true;
}

void SwLedOff(struct adapter *padapter, struct LED_871x *pLed)
{
	u8	LedCfg;

	if (padapter->bSurpriseRemoved || padapter->bDriverStopped)
		goto exit;

	LedCfg = usb_read8(padapter, REG_LEDCFG2);/* 0x4E */

	/*  Open-drain arrangement for controlling the LED) */
	LedCfg &= 0x90; /*  Set to software control. */
	usb_write8(padapter, REG_LEDCFG2, (LedCfg | BIT(3)));
	LedCfg = usb_read8(padapter, REG_MAC_PINMUX_CFG);
	LedCfg &= 0xFE;
	usb_write8(padapter, REG_MAC_PINMUX_CFG, LedCfg);
exit:
	pLed->bLedOn = false;
}

void rtw_hal_sw_led_init(struct adapter *padapter)
{
	struct led_priv *pledpriv = &(padapter->ledpriv);

	InitLed871x(padapter, &(pledpriv->SwLed0));
}

void rtw_hal_sw_led_deinit(struct adapter *padapter)
{
	struct led_priv	*ledpriv = &(padapter->ledpriv);

	DeInitLed871x(&(ledpriv->SwLed0));
}

