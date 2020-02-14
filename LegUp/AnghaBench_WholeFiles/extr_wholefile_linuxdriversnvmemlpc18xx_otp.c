#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u32 ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct nvmem_device {int dummy; } ;
struct lpc18xx_otp {scalar_t__ base; } ;
struct TYPE_3__ {unsigned int size; struct lpc18xx_otp* priv; int /*<<< orphan*/ * dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 unsigned int LPC18XX_OTP_SIZE ; 
 int LPC18XX_OTP_WORD_SIZE ; 
 int PTR_ERR (scalar_t__) ; 
 int PTR_ERR_OR_ZERO (struct nvmem_device*) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct lpc18xx_otp* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct nvmem_device* devm_nvmem_register (int /*<<< orphan*/ *,TYPE_1__*) ; 
 TYPE_1__ lpc18xx_otp_nvmem_config ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 

__attribute__((used)) static int lpc18xx_otp_read(void *context, unsigned int offset,
			    void *val, size_t bytes)
{
	struct lpc18xx_otp *otp = context;
	unsigned int count = bytes >> 2;
	u32 index = offset >> 2;
	u32 *buf = val;
	int i;

	if (count > (LPC18XX_OTP_SIZE - index))
		count = LPC18XX_OTP_SIZE - index;

	for (i = index; i < (index + count); i++)
		*buf++ = readl(otp->base + i * LPC18XX_OTP_WORD_SIZE);

	return 0;
}

__attribute__((used)) static int lpc18xx_otp_probe(struct platform_device *pdev)
{
	struct nvmem_device *nvmem;
	struct lpc18xx_otp *otp;
	struct resource *res;

	otp = devm_kzalloc(&pdev->dev, sizeof(*otp), GFP_KERNEL);
	if (!otp)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	otp->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(otp->base))
		return PTR_ERR(otp->base);

	lpc18xx_otp_nvmem_config.size = LPC18XX_OTP_SIZE;
	lpc18xx_otp_nvmem_config.dev = &pdev->dev;
	lpc18xx_otp_nvmem_config.priv = otp;

	nvmem = devm_nvmem_register(&pdev->dev, &lpc18xx_otp_nvmem_config);

	return PTR_ERR_OR_ZERO(nvmem);
}

