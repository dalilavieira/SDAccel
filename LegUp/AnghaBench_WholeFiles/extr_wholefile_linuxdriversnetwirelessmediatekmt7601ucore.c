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
typedef  int u32 ;
struct mt7601u_dev {int /*<<< orphan*/  dev; int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  MT7601U_STATE_REMOVED ; 
 int MT_MAC_CSR0 ; 
 int /*<<< orphan*/  MT_TX_BAND_CFG ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int mt7601u_rmc (struct mt7601u_dev*,int /*<<< orphan*/ ,int,int) ; 
 int mt7601u_rmw (struct mt7601u_dev*,int,int,int) ; 
 int mt7601u_rr (struct mt7601u_dev*,int) ; 
 void mt7601u_wr (struct mt7601u_dev*,int,int) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline u32 mt76_rr(struct mt7601u_dev *dev, u32 offset)
{
	return mt7601u_rr(dev, offset);
}

__attribute__((used)) static inline void mt76_wr(struct mt7601u_dev *dev, u32 offset, u32 val)
{
	return mt7601u_wr(dev, offset, val);
}

__attribute__((used)) static inline u32
mt76_rmw(struct mt7601u_dev *dev, u32 offset, u32 mask, u32 val)
{
	return mt7601u_rmw(dev, offset, mask, val);
}

__attribute__((used)) static inline u32 mt76_set(struct mt7601u_dev *dev, u32 offset, u32 val)
{
	return mt76_rmw(dev, offset, 0, val);
}

__attribute__((used)) static inline u32 mt76_clear(struct mt7601u_dev *dev, u32 offset, u32 val)
{
	return mt76_rmw(dev, offset, val, 0);
}

__attribute__((used)) static inline u32 mt7601u_mac_set_ctrlch(struct mt7601u_dev *dev, bool below)
{
	return mt7601u_rmc(dev, MT_TX_BAND_CFG, 1, below);
}

int mt7601u_wait_asic_ready(struct mt7601u_dev *dev)
{
	int i = 100;
	u32 val;

	do {
		if (test_bit(MT7601U_STATE_REMOVED, &dev->state))
			return -EIO;

		val = mt7601u_rr(dev, MT_MAC_CSR0);
		if (val && ~val)
			return 0;

		udelay(10);
	} while (i--);

	return -EIO;
}

bool mt76_poll(struct mt7601u_dev *dev, u32 offset, u32 mask, u32 val,
	       int timeout)
{
	u32 cur;

	timeout /= 10;
	do {
		if (test_bit(MT7601U_STATE_REMOVED, &dev->state))
			return false;

		cur = mt7601u_rr(dev, offset) & mask;
		if (cur == val)
			return true;

		udelay(10);
	} while (timeout-- > 0);

	dev_err(dev->dev, "Error: Time out with reg %08x\n", offset);

	return false;
}

bool mt76_poll_msec(struct mt7601u_dev *dev, u32 offset, u32 mask, u32 val,
		    int timeout)
{
	u32 cur;

	timeout /= 10;
	do {
		if (test_bit(MT7601U_STATE_REMOVED, &dev->state))
			return false;

		cur = mt7601u_rr(dev, offset) & mask;
		if (cur == val)
			return true;

		msleep(10);
	} while (timeout-- > 0);

	dev_err(dev->dev, "Error: Time out with reg %08x\n", offset);

	return false;
}

