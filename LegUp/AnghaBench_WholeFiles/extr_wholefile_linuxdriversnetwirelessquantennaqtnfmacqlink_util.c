#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  value ;
typedef  int u8 ;
typedef  int u16 ;
typedef  int /*<<< orphan*/  tmp ;
struct wiphy {int dummy; } ;
struct sk_buff {int dummy; } ;
struct qlink_tlv_hdr {int* val; void* len; void* type; } ;
struct TYPE_2__ {void* flags; void* center_freq; void* hw_value; } ;
struct qlink_chandef {int width; void* center_freq2; void* center_freq1; TYPE_1__ chan; } ;
struct qlink_acl_data {int* mac_addrs; void* num_entries; void* policy; } ;
struct ieee80211_channel {int hw_value; int center_freq; int flags; } ;
struct cfg80211_chan_def {int center_freq1; int center_freq2; int width; struct ieee80211_channel* chan; } ;
struct cfg80211_acl_data {int acl_policy; int n_acl_entries; int const* mac_addrs; } ;
typedef  enum qlink_hidden_ssid { ____Placeholder_qlink_hidden_ssid } qlink_hidden_ssid ;
typedef  enum nl80211_hidden_ssid { ____Placeholder_nl80211_hidden_ssid } nl80211_hidden_ssid ;
typedef  enum nl80211_chan_width { ____Placeholder_nl80211_chan_width } nl80211_chan_width ;
typedef  int const __le16 ;

/* Variables and functions */
 int BIT (int) ; 
 unsigned int BITS_PER_BYTE ; 
#define  NL80211_ACL_POLICY_ACCEPT_UNLESS_LISTED 154 
#define  NL80211_ACL_POLICY_DENY_UNLESS_LISTED 153 
#define  NL80211_CHAN_WIDTH_10 152 
#define  NL80211_CHAN_WIDTH_160 151 
#define  NL80211_CHAN_WIDTH_20 150 
#define  NL80211_CHAN_WIDTH_20_NOHT 149 
#define  NL80211_CHAN_WIDTH_40 148 
#define  NL80211_CHAN_WIDTH_5 147 
#define  NL80211_CHAN_WIDTH_80 146 
#define  NL80211_CHAN_WIDTH_80P80 145 
#define  NL80211_HIDDEN_SSID_NOT_IN_USE 144 
#define  NL80211_HIDDEN_SSID_ZERO_CONTENTS 143 
#define  NL80211_HIDDEN_SSID_ZERO_LEN 142 
 int NL80211_IFTYPE_ADHOC ; 
 int NL80211_IFTYPE_AP ; 
 int NL80211_IFTYPE_AP_VLAN ; 
 int NL80211_IFTYPE_MONITOR ; 
 int NL80211_IFTYPE_STATION ; 
 int NL80211_IFTYPE_WDS ; 
 int QLINK_ACL_POLICY_ACCEPT_UNLESS_LISTED ; 
 int QLINK_ACL_POLICY_DENY_UNLESS_LISTED ; 
#define  QLINK_CHAN_WIDTH_10 141 
#define  QLINK_CHAN_WIDTH_160 140 
#define  QLINK_CHAN_WIDTH_20 139 
#define  QLINK_CHAN_WIDTH_20_NOHT 138 
#define  QLINK_CHAN_WIDTH_40 137 
#define  QLINK_CHAN_WIDTH_5 136 
#define  QLINK_CHAN_WIDTH_80 135 
#define  QLINK_CHAN_WIDTH_80P80 134 
 int QLINK_HIDDEN_SSID_NOT_IN_USE ; 
 int QLINK_HIDDEN_SSID_ZERO_CONTENTS ; 
 int QLINK_HIDDEN_SSID_ZERO_LEN ; 
#define  QLINK_IFTYPE_ADHOC 133 
#define  QLINK_IFTYPE_AP 132 
#define  QLINK_IFTYPE_AP_VLAN 131 
#define  QLINK_IFTYPE_MONITOR 130 
#define  QLINK_IFTYPE_STATION 129 
#define  QLINK_IFTYPE_WDS 128 
 void* cpu_to_le16 (int) ; 
 void* cpu_to_le32 (int) ; 
 struct ieee80211_channel* ieee80211_get_channel (struct wiphy*,void*) ; 
 void* le16_to_cpu (void*) ; 
 int /*<<< orphan*/  memcpy (int*,int const*,int) ; 
 struct qlink_tlv_hdr* skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_put_data (struct sk_buff*,int const*,size_t) ; 

__attribute__((used)) static inline void
qtnf_cmd_skb_put_buffer(struct sk_buff *skb, const u8 *buf_src, size_t len)
{
	skb_put_data(skb, buf_src, len);
}

__attribute__((used)) static inline void qtnf_cmd_skb_put_tlv_arr(struct sk_buff *skb,
					    u16 tlv_id, const u8 arr[],
					    size_t arr_len)
{
	struct qlink_tlv_hdr *hdr = skb_put(skb, sizeof(*hdr) + arr_len);

	hdr->type = cpu_to_le16(tlv_id);
	hdr->len = cpu_to_le16(arr_len);
	memcpy(hdr->val, arr, arr_len);
}

__attribute__((used)) static inline void qtnf_cmd_skb_put_tlv_u8(struct sk_buff *skb, u16 tlv_id,
					   u8 value)
{
	struct qlink_tlv_hdr *hdr = skb_put(skb, sizeof(*hdr) + sizeof(value));

	hdr->type = cpu_to_le16(tlv_id);
	hdr->len = cpu_to_le16(sizeof(value));
	*hdr->val = value;
}

__attribute__((used)) static inline void qtnf_cmd_skb_put_tlv_u16(struct sk_buff *skb,
					    u16 tlv_id, u16 value)
{
	struct qlink_tlv_hdr *hdr = skb_put(skb, sizeof(*hdr) + sizeof(value));
	__le16 tmp = cpu_to_le16(value);

	hdr->type = cpu_to_le16(tlv_id);
	hdr->len = cpu_to_le16(sizeof(value));
	memcpy(hdr->val, &tmp, sizeof(tmp));
}

u16 qlink_iface_type_to_nl_mask(u16 qlink_type)
{
	u16 result = 0;

	switch (qlink_type) {
	case QLINK_IFTYPE_AP:
		result |= BIT(NL80211_IFTYPE_AP);
		break;
	case QLINK_IFTYPE_STATION:
		result |= BIT(NL80211_IFTYPE_STATION);
		break;
	case QLINK_IFTYPE_ADHOC:
		result |= BIT(NL80211_IFTYPE_ADHOC);
		break;
	case QLINK_IFTYPE_MONITOR:
		result |= BIT(NL80211_IFTYPE_MONITOR);
		break;
	case QLINK_IFTYPE_WDS:
		result |= BIT(NL80211_IFTYPE_WDS);
		break;
	case QLINK_IFTYPE_AP_VLAN:
		result |= BIT(NL80211_IFTYPE_AP_VLAN);
		break;
	}

	return result;
}

u8 qlink_chan_width_mask_to_nl(u16 qlink_mask)
{
	u8 result = 0;

	if (qlink_mask & BIT(QLINK_CHAN_WIDTH_5))
		result |= BIT(NL80211_CHAN_WIDTH_5);

	if (qlink_mask & BIT(QLINK_CHAN_WIDTH_10))
		result |= BIT(NL80211_CHAN_WIDTH_10);

	if (qlink_mask & BIT(QLINK_CHAN_WIDTH_20_NOHT))
		result |= BIT(NL80211_CHAN_WIDTH_20_NOHT);

	if (qlink_mask & BIT(QLINK_CHAN_WIDTH_20))
		result |= BIT(NL80211_CHAN_WIDTH_20);

	if (qlink_mask & BIT(QLINK_CHAN_WIDTH_40))
		result |= BIT(NL80211_CHAN_WIDTH_40);

	if (qlink_mask & BIT(QLINK_CHAN_WIDTH_80))
		result |= BIT(NL80211_CHAN_WIDTH_80);

	if (qlink_mask & BIT(QLINK_CHAN_WIDTH_80P80))
		result |= BIT(NL80211_CHAN_WIDTH_80P80);

	if (qlink_mask & BIT(QLINK_CHAN_WIDTH_160))
		result |= BIT(NL80211_CHAN_WIDTH_160);

	return result;
}

__attribute__((used)) static enum nl80211_chan_width qlink_chanwidth_to_nl(u8 qlw)
{
	switch (qlw) {
	case QLINK_CHAN_WIDTH_20_NOHT:
		return NL80211_CHAN_WIDTH_20_NOHT;
	case QLINK_CHAN_WIDTH_20:
		return NL80211_CHAN_WIDTH_20;
	case QLINK_CHAN_WIDTH_40:
		return NL80211_CHAN_WIDTH_40;
	case QLINK_CHAN_WIDTH_80:
		return NL80211_CHAN_WIDTH_80;
	case QLINK_CHAN_WIDTH_80P80:
		return NL80211_CHAN_WIDTH_80P80;
	case QLINK_CHAN_WIDTH_160:
		return NL80211_CHAN_WIDTH_160;
	case QLINK_CHAN_WIDTH_5:
		return NL80211_CHAN_WIDTH_5;
	case QLINK_CHAN_WIDTH_10:
		return NL80211_CHAN_WIDTH_10;
	default:
		return -1;
	}
}

__attribute__((used)) static u8 qlink_chanwidth_nl_to_qlink(enum nl80211_chan_width nlwidth)
{
	switch (nlwidth) {
	case NL80211_CHAN_WIDTH_20_NOHT:
		return QLINK_CHAN_WIDTH_20_NOHT;
	case NL80211_CHAN_WIDTH_20:
		return QLINK_CHAN_WIDTH_20;
	case NL80211_CHAN_WIDTH_40:
		return QLINK_CHAN_WIDTH_40;
	case NL80211_CHAN_WIDTH_80:
		return QLINK_CHAN_WIDTH_80;
	case NL80211_CHAN_WIDTH_80P80:
		return QLINK_CHAN_WIDTH_80P80;
	case NL80211_CHAN_WIDTH_160:
		return QLINK_CHAN_WIDTH_160;
	case NL80211_CHAN_WIDTH_5:
		return QLINK_CHAN_WIDTH_5;
	case NL80211_CHAN_WIDTH_10:
		return QLINK_CHAN_WIDTH_10;
	default:
		return -1;
	}
}

void qlink_chandef_q2cfg(struct wiphy *wiphy,
			 const struct qlink_chandef *qch,
			 struct cfg80211_chan_def *chdef)
{
	struct ieee80211_channel *chan;

	chan = ieee80211_get_channel(wiphy, le16_to_cpu(qch->chan.center_freq));

	chdef->chan = chan;
	chdef->center_freq1 = le16_to_cpu(qch->center_freq1);
	chdef->center_freq2 = le16_to_cpu(qch->center_freq2);
	chdef->width = qlink_chanwidth_to_nl(qch->width);
}

void qlink_chandef_cfg2q(const struct cfg80211_chan_def *chdef,
			 struct qlink_chandef *qch)
{
	struct ieee80211_channel *chan = chdef->chan;

	qch->chan.hw_value = cpu_to_le16(chan->hw_value);
	qch->chan.center_freq = cpu_to_le16(chan->center_freq);
	qch->chan.flags = cpu_to_le32(chan->flags);

	qch->center_freq1 = cpu_to_le16(chdef->center_freq1);
	qch->center_freq2 = cpu_to_le16(chdef->center_freq2);
	qch->width = qlink_chanwidth_nl_to_qlink(chdef->width);
}

enum qlink_hidden_ssid qlink_hidden_ssid_nl2q(enum nl80211_hidden_ssid nl_val)
{
	switch (nl_val) {
	case NL80211_HIDDEN_SSID_ZERO_LEN:
		return QLINK_HIDDEN_SSID_ZERO_LEN;
	case NL80211_HIDDEN_SSID_ZERO_CONTENTS:
		return QLINK_HIDDEN_SSID_ZERO_CONTENTS;
	case NL80211_HIDDEN_SSID_NOT_IN_USE:
	default:
		return QLINK_HIDDEN_SSID_NOT_IN_USE;
	}
}

bool qtnf_utils_is_bit_set(const u8 *arr, unsigned int bit,
			   unsigned int arr_max_len)
{
	unsigned int idx = bit / BITS_PER_BYTE;
	u8 mask = 1 << (bit - (idx * BITS_PER_BYTE));

	if (idx >= arr_max_len)
		return false;

	return arr[idx] & mask;
}

void qlink_acl_data_cfg2q(const struct cfg80211_acl_data *acl,
			  struct qlink_acl_data *qacl)
{
	switch (acl->acl_policy) {
	case NL80211_ACL_POLICY_ACCEPT_UNLESS_LISTED:
		qacl->policy =
			cpu_to_le32(QLINK_ACL_POLICY_ACCEPT_UNLESS_LISTED);
		break;
	case NL80211_ACL_POLICY_DENY_UNLESS_LISTED:
		qacl->policy = cpu_to_le32(QLINK_ACL_POLICY_DENY_UNLESS_LISTED);
		break;
	}

	qacl->num_entries = cpu_to_le32(acl->n_acl_entries);
	memcpy(qacl->mac_addrs, acl->mac_addrs,
	       acl->n_acl_entries * sizeof(*qacl->mac_addrs));
}

