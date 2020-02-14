#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
struct rtc_time {int tm_year; int tm_mon; int tm_mday; int tm_hour; int tm_min; int tm_sec; int tm_wday; } ;
struct rtc_wkalrm {scalar_t__ enabled; struct rtc_time time; } ;
struct rtc_device {int uie_unsupported; } ;
struct TYPE_6__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct opal_msg {int dummy; } ;
struct device {int dummy; } ;
typedef  scalar_t__ s64 ;
typedef  int /*<<< orphan*/  __be64 ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_5__ {int (* read_alarm ) (struct device*,struct rtc_wkalrm*) ;int (* set_alarm ) (struct device*,struct rtc_wkalrm*) ;int (* alarm_irq_enable ) (struct device*,unsigned int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DRVNAME ; 
 int EIO ; 
 int ENOENT ; 
 int ERESTARTSYS ; 
 scalar_t__ IS_ERR (struct rtc_device*) ; 
 int OPAL_ASYNC_COMPLETION ; 
 scalar_t__ OPAL_BUSY ; 
 int OPAL_BUSY_DELAY_MS ; 
 scalar_t__ OPAL_BUSY_EVENT ; 
 scalar_t__ OPAL_HARDWARE ; 
 scalar_t__ OPAL_INTERNAL_ERROR ; 
 scalar_t__ OPAL_SUCCESS ; 
 int PTR_ERR (struct rtc_device*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int bcd2bin (int) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int be64_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ bin2bcd (int) ; 
 int /*<<< orphan*/  device_set_wakeup_capable (TYPE_2__*,int) ; 
 struct rtc_device* devm_rtc_device_register (TYPE_2__*,int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ of_property_read_bool (scalar_t__,char*) ; 
 int opal_async_get_token_interruptible () ; 
 int /*<<< orphan*/  opal_async_release_token (int) ; 
 int opal_async_wait_response (int,struct opal_msg*) ; 
 int opal_get_async_rc (struct opal_msg) ; 
 int /*<<< orphan*/  opal_poll_events (int /*<<< orphan*/ *) ; 
 TYPE_1__ opal_rtc_ops ; 
 scalar_t__ opal_rtc_read (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ opal_rtc_write (int,int) ; 
 int opal_tpo_read (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int opal_tpo_write (int,int,int) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*) ; 

__attribute__((used)) static void opal_to_tm(u32 y_m_d, u64 h_m_s_ms, struct rtc_time *tm)
{
	tm->tm_year = ((bcd2bin(y_m_d >> 24) * 100) +
		       bcd2bin((y_m_d >> 16) & 0xff)) - 1900;
	tm->tm_mon  = bcd2bin((y_m_d >> 8) & 0xff) - 1;
	tm->tm_mday = bcd2bin(y_m_d & 0xff);
	tm->tm_hour = bcd2bin((h_m_s_ms >> 56) & 0xff);
	tm->tm_min  = bcd2bin((h_m_s_ms >> 48) & 0xff);
	tm->tm_sec  = bcd2bin((h_m_s_ms >> 40) & 0xff);

	tm->tm_wday = -1;
}

__attribute__((used)) static void tm_to_opal(struct rtc_time *tm, u32 *y_m_d, u64 *h_m_s_ms)
{
	*y_m_d |= ((u32)bin2bcd((tm->tm_year + 1900) / 100)) << 24;
	*y_m_d |= ((u32)bin2bcd((tm->tm_year + 1900) % 100)) << 16;
	*y_m_d |= ((u32)bin2bcd((tm->tm_mon + 1))) << 8;
	*y_m_d |= ((u32)bin2bcd(tm->tm_mday));

	*h_m_s_ms |= ((u64)bin2bcd(tm->tm_hour)) << 56;
	*h_m_s_ms |= ((u64)bin2bcd(tm->tm_min)) << 48;
	*h_m_s_ms |= ((u64)bin2bcd(tm->tm_sec)) << 40;
}

__attribute__((used)) static int opal_get_rtc_time(struct device *dev, struct rtc_time *tm)
{
	s64 rc = OPAL_BUSY;
	int retries = 10;
	u32 y_m_d;
	u64 h_m_s_ms;
	__be32 __y_m_d;
	__be64 __h_m_s_ms;

	while (rc == OPAL_BUSY || rc == OPAL_BUSY_EVENT) {
		rc = opal_rtc_read(&__y_m_d, &__h_m_s_ms);
		if (rc == OPAL_BUSY_EVENT) {
			msleep(OPAL_BUSY_DELAY_MS);
			opal_poll_events(NULL);
		} else if (rc == OPAL_BUSY) {
			msleep(OPAL_BUSY_DELAY_MS);
		} else if (rc == OPAL_HARDWARE || rc == OPAL_INTERNAL_ERROR) {
			if (retries--) {
				msleep(10); /* Wait 10ms before retry */
				rc = OPAL_BUSY; /* go around again */
			}
		}
	}

	if (rc != OPAL_SUCCESS)
		return -EIO;

	y_m_d = be32_to_cpu(__y_m_d);
	h_m_s_ms = be64_to_cpu(__h_m_s_ms);
	opal_to_tm(y_m_d, h_m_s_ms, tm);

	return 0;
}

__attribute__((used)) static int opal_set_rtc_time(struct device *dev, struct rtc_time *tm)
{
	s64 rc = OPAL_BUSY;
	int retries = 10;
	u32 y_m_d = 0;
	u64 h_m_s_ms = 0;

	tm_to_opal(tm, &y_m_d, &h_m_s_ms);

	while (rc == OPAL_BUSY || rc == OPAL_BUSY_EVENT) {
		rc = opal_rtc_write(y_m_d, h_m_s_ms);
		if (rc == OPAL_BUSY_EVENT) {
			msleep(OPAL_BUSY_DELAY_MS);
			opal_poll_events(NULL);
		} else if (rc == OPAL_BUSY) {
			msleep(OPAL_BUSY_DELAY_MS);
		} else if (rc == OPAL_HARDWARE || rc == OPAL_INTERNAL_ERROR) {
			if (retries--) {
				msleep(10); /* Wait 10ms before retry */
				rc = OPAL_BUSY; /* go around again */
			}
		}
	}

	return rc == OPAL_SUCCESS ? 0 : -EIO;
}

__attribute__((used)) static int opal_get_tpo_time(struct device *dev, struct rtc_wkalrm *alarm)
{
	__be32 __y_m_d, __h_m;
	struct opal_msg msg;
	int rc, token;
	u64 h_m_s_ms;
	u32 y_m_d;

	token = opal_async_get_token_interruptible();
	if (token < 0) {
		if (token != -ERESTARTSYS)
			pr_err("Failed to get the async token\n");

		return token;
	}

	rc = opal_tpo_read(token, &__y_m_d, &__h_m);
	if (rc != OPAL_ASYNC_COMPLETION) {
		rc = -EIO;
		goto exit;
	}

	rc = opal_async_wait_response(token, &msg);
	if (rc) {
		rc = -EIO;
		goto exit;
	}

	rc = opal_get_async_rc(msg);
	if (rc != OPAL_SUCCESS) {
		rc = -EIO;
		goto exit;
	}

	y_m_d = be32_to_cpu(__y_m_d);
	h_m_s_ms = ((u64)be32_to_cpu(__h_m) << 32);

	/* check if no alarm is set */
	if (y_m_d == 0 && h_m_s_ms == 0) {
		pr_debug("No alarm is set\n");
		rc = -ENOENT;
		goto exit;
	} else {
		pr_debug("Alarm set to %x %llx\n", y_m_d, h_m_s_ms);
	}

	opal_to_tm(y_m_d, h_m_s_ms, &alarm->time);

exit:
	opal_async_release_token(token);
	return rc;
}

__attribute__((used)) static int opal_set_tpo_time(struct device *dev, struct rtc_wkalrm *alarm)
{
	u64 h_m_s_ms = 0;
	struct opal_msg msg;
	u32 y_m_d = 0;
	int token, rc;

	/* if alarm is enabled */
	if (alarm->enabled) {
		tm_to_opal(&alarm->time, &y_m_d, &h_m_s_ms);
		pr_debug("Alarm set to %x %llx\n", y_m_d, h_m_s_ms);

	} else {
		pr_debug("Alarm getting disabled\n");
	}

	token = opal_async_get_token_interruptible();
	if (token < 0) {
		if (token != -ERESTARTSYS)
			pr_err("Failed to get the async token\n");

		return token;
	}

	/* TPO, we care about hour and minute */
	rc = opal_tpo_write(token, y_m_d,
			    (u32)((h_m_s_ms >> 32) & 0xffff0000));
	if (rc != OPAL_ASYNC_COMPLETION) {
		rc = -EIO;
		goto exit;
	}

	rc = opal_async_wait_response(token, &msg);
	if (rc) {
		rc = -EIO;
		goto exit;
	}

	rc = opal_get_async_rc(msg);
	if (rc != OPAL_SUCCESS)
		rc = -EIO;

exit:
	opal_async_release_token(token);
	return rc;
}

int opal_tpo_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct rtc_wkalrm alarm = { .enabled = 0 };

	/*
	 * TPO is automatically enabled when opal_set_tpo_time() is called with
	 * non-zero rtc-time. We only handle disable case which needs to be
	 * explicitly told to opal.
	 */
	return enabled ? 0 : opal_set_tpo_time(dev, &alarm);
}

__attribute__((used)) static int opal_rtc_probe(struct platform_device *pdev)
{
	struct rtc_device *rtc;

	if (pdev->dev.of_node &&
	    (of_property_read_bool(pdev->dev.of_node, "wakeup-source") ||
	     of_property_read_bool(pdev->dev.of_node, "has-tpo")/* legacy */)) {
		device_set_wakeup_capable(&pdev->dev, true);
		opal_rtc_ops.read_alarm	= opal_get_tpo_time;
		opal_rtc_ops.set_alarm = opal_set_tpo_time;
		opal_rtc_ops.alarm_irq_enable = opal_tpo_alarm_irq_enable;
	}

	rtc = devm_rtc_device_register(&pdev->dev, DRVNAME, &opal_rtc_ops,
				       THIS_MODULE);
	if (IS_ERR(rtc))
		return PTR_ERR(rtc);

	rtc->uie_unsupported = 1;

	return 0;
}

