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
typedef  int u32 ;
struct michael_mic_ctx {int l; int r; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;

/* Variables and functions */
 int get_unaligned_le16 (int*) ; 
 void* get_unaligned_le32 (int const*) ; 
 int* ieee80211_get_DA (struct ieee80211_hdr*) ; 
 int* ieee80211_get_SA (struct ieee80211_hdr*) ; 
 int ieee80211_get_tid (struct ieee80211_hdr*) ; 
 scalar_t__ ieee80211_is_data_qos (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_unaligned_le32 (int,int*) ; 
 int rol32 (int,int) ; 
 int ror32 (int,int) ; 

__attribute__((used)) static void michael_block(struct michael_mic_ctx *mctx, u32 val)
{
	mctx->l ^= val;
	mctx->r ^= rol32(mctx->l, 17);
	mctx->l += mctx->r;
	mctx->r ^= ((mctx->l & 0xff00ff00) >> 8) |
		   ((mctx->l & 0x00ff00ff) << 8);
	mctx->l += mctx->r;
	mctx->r ^= rol32(mctx->l, 3);
	mctx->l += mctx->r;
	mctx->r ^= ror32(mctx->l, 2);
	mctx->l += mctx->r;
}

__attribute__((used)) static void michael_mic_hdr(struct michael_mic_ctx *mctx, const u8 *key,
			    struct ieee80211_hdr *hdr)
{
	u8 *da, *sa, tid;

	da = ieee80211_get_DA(hdr);
	sa = ieee80211_get_SA(hdr);
	if (ieee80211_is_data_qos(hdr->frame_control))
		tid = ieee80211_get_tid(hdr);
	else
		tid = 0;

	mctx->l = get_unaligned_le32(key);
	mctx->r = get_unaligned_le32(key + 4);

	/*
	 * A pseudo header (DA, SA, Priority, 0, 0, 0) is used in Michael MIC
	 * calculation, but it is _not_ transmitted
	 */
	michael_block(mctx, get_unaligned_le32(da));
	michael_block(mctx, get_unaligned_le16(&da[4]) |
			    (get_unaligned_le16(sa) << 16));
	michael_block(mctx, get_unaligned_le32(&sa[2]));
	michael_block(mctx, tid);
}

void michael_mic(const u8 *key, struct ieee80211_hdr *hdr,
		 const u8 *data, size_t data_len, u8 *mic)
{
	u32 val;
	size_t block, blocks, left;
	struct michael_mic_ctx mctx;

	michael_mic_hdr(&mctx, key, hdr);

	/* Real data */
	blocks = data_len / 4;
	left = data_len % 4;

	for (block = 0; block < blocks; block++)
		michael_block(&mctx, get_unaligned_le32(&data[block * 4]));

	/* Partial block of 0..3 bytes and padding: 0x5a + 4..7 zeros to make
	 * total length a multiple of 4. */
	val = 0x5a;
	while (left > 0) {
		val <<= 8;
		left--;
		val |= data[blocks * 4 + left];
	}

	michael_block(&mctx, val);
	michael_block(&mctx, 0);

	put_unaligned_le32(mctx.l, mic);
	put_unaligned_le32(mctx.r, mic + 4);
}

