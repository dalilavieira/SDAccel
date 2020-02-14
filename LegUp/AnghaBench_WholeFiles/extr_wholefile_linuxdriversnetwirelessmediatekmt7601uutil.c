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
typedef  int /*<<< orphan*/  u32 ;
struct sk_buff {scalar_t__* data; } ;
struct mt7601u_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MT_TX_BAND_CFG ; 
 int ieee80211_get_hdrlen_from_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  memmove (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  mt7601u_rmc (struct mt7601u_dev*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  mt7601u_rmw (struct mt7601u_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mt7601u_rr (struct mt7601u_dev*,int /*<<< orphan*/ ) ; 
 void mt7601u_wr (struct mt7601u_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int skb_cow (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_push (struct sk_buff*,int) ; 

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

void mt76_remove_hdr_pad(struct sk_buff *skb)
{
	int len = ieee80211_get_hdrlen_from_skb(skb);

	memmove(skb->data + 2, skb->data, len);
	skb_pull(skb, 2);
}

int mt76_insert_hdr_pad(struct sk_buff *skb)
{
	int len = ieee80211_get_hdrlen_from_skb(skb);
	int ret;

	if (len % 4 == 0)
		return 0;

	ret = skb_cow(skb, 2);
	if (ret)
		return ret;

	skb_push(skb, 2);
	memmove(skb->data, skb->data + 2, len);

	skb->data[len] = 0;
	skb->data[len + 1] = 0;
	return 0;
}

