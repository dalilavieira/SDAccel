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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 unsigned long ENAC97 ; 
 unsigned long ENI2C0 ; 
 unsigned long ENI2C1 ; 
 unsigned long ENKPI ; 
 unsigned long ENNAND ; 
 unsigned long ENSD0 ; 
 int ENSD1 ; 
 unsigned long ENSPI ; 
 unsigned long GPIOG0TO1 ; 
 unsigned long GPIOG18TO20 ; 
 unsigned long GPIOG22TO23 ; 
 unsigned long GPIOG2TO3 ; 
 unsigned long GPSELC ; 
 unsigned long GPSELD ; 
 unsigned long GPSELEI0 ; 
 unsigned long GPSELEI1 ; 
 unsigned long GPSELF ; 
 int /*<<< orphan*/  REG_MFSEL ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,int /*<<< orphan*/ ) ; 
 char* dev_name (struct device*) ; 
 int /*<<< orphan*/  mfp_mutex ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ strcmp (char const*,char*) ; 

void mfp_set_groupf(struct device *dev)
{
	unsigned long mfpen;
	const char *dev_id;

	BUG_ON(!dev);

	mutex_lock(&mfp_mutex);

	dev_id = dev_name(dev);

	mfpen = __raw_readl(REG_MFSEL);

	if (strcmp(dev_id, "nuc900-emc") == 0)
		mfpen |= GPSELF;/*enable mac*/
	else
		mfpen &= ~GPSELF;/*GPIOF[9:0]*/

	__raw_writel(mfpen, REG_MFSEL);

	mutex_unlock(&mfp_mutex);
}

void mfp_set_groupc(struct device *dev)
{
	unsigned long mfpen;
	const char *dev_id;

	BUG_ON(!dev);

	mutex_lock(&mfp_mutex);

	dev_id = dev_name(dev);

	mfpen = __raw_readl(REG_MFSEL);

	if (strcmp(dev_id, "nuc900-lcd") == 0)
		mfpen |= GPSELC;/*enable lcd*/
	else if (strcmp(dev_id, "nuc900-kpi") == 0) {
		mfpen &= (~GPSELC);/*enable kpi*/
		mfpen |= ENKPI;
	} else if (strcmp(dev_id, "nuc900-nand") == 0) {
		mfpen &= (~GPSELC);/*enable nand*/
		mfpen |= ENNAND;
	} else
		mfpen &= (~GPSELC);/*GPIOC[14:0]*/

	__raw_writel(mfpen, REG_MFSEL);

	mutex_unlock(&mfp_mutex);
}

void mfp_set_groupi(struct device *dev)
{
	unsigned long mfpen;
	const char *dev_id;

	BUG_ON(!dev);

	mutex_lock(&mfp_mutex);

	dev_id = dev_name(dev);

	mfpen = __raw_readl(REG_MFSEL);

	mfpen &= ~GPSELEI1;/*default gpio16*/

	if (strcmp(dev_id, "nuc900-wdog") == 0)
		mfpen |= GPSELEI1;/*enable wdog*/
	else if (strcmp(dev_id, "nuc900-atapi") == 0)
		mfpen |= GPSELEI0;/*enable atapi*/
	else if (strcmp(dev_id, "nuc900-keypad") == 0)
		mfpen &= ~GPSELEI0;/*enable keypad*/

	__raw_writel(mfpen, REG_MFSEL);

	mutex_unlock(&mfp_mutex);
}

void mfp_set_groupg(struct device *dev, const char *subname)
{
	unsigned long mfpen;
	const char *dev_id;

	BUG_ON((!dev) && (!subname));

	mutex_lock(&mfp_mutex);

	if (subname != NULL)
		dev_id = subname;
	else
		dev_id = dev_name(dev);

	mfpen = __raw_readl(REG_MFSEL);

	if (strcmp(dev_id, "nuc900-spi") == 0) {
		mfpen &= ~(GPIOG0TO1 | GPIOG2TO3);
		mfpen |= ENSPI;/*enable spi*/
	} else if (strcmp(dev_id, "nuc900-i2c0") == 0) {
		mfpen &= ~(GPIOG0TO1);
		mfpen |= ENI2C0;/*enable i2c0*/
	} else if (strcmp(dev_id, "nuc900-i2c1") == 0) {
		mfpen &= ~(GPIOG2TO3);
		mfpen |= ENI2C1;/*enable i2c1*/
	} else if (strcmp(dev_id, "nuc900-ac97") == 0) {
		mfpen &= ~(GPIOG22TO23);
		mfpen |= ENAC97;/*enable AC97*/
	} else if (strcmp(dev_id, "nuc900-mmc-port1") == 0) {
		mfpen &= ~(GPIOG18TO20);
		mfpen |= (ENSD1 | 0x01);/*enable sd1*/
	} else {
		mfpen &= ~(GPIOG0TO1 | GPIOG2TO3);/*GPIOG[3:0]*/
	}

	__raw_writel(mfpen, REG_MFSEL);

	mutex_unlock(&mfp_mutex);
}

void mfp_set_groupd(struct device *dev, const char *subname)
{
	unsigned long mfpen;
	const char *dev_id;

	BUG_ON((!dev) && (!subname));

	mutex_lock(&mfp_mutex);

	if (subname != NULL)
		dev_id = subname;
	else
		dev_id = dev_name(dev);

	mfpen = __raw_readl(REG_MFSEL);

	if (strcmp(dev_id, "nuc900-mmc-port0") == 0) {
		mfpen &= ~GPSELD;/*enable sd0*/
		mfpen |= ENSD0;
	} else
		mfpen &= (~GPSELD);

	__raw_writel(mfpen, REG_MFSEL);

	mutex_unlock(&mfp_mutex);
}

