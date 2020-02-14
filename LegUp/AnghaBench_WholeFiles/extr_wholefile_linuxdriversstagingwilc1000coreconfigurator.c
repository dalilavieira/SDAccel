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
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct network_info {int rssi; int cap_info; int tsf_lo; int tsf_hi; int* ssid; int ssid_len; int* bssid; int ch; int beacon_period; int dtim_period; int ies_len; void* ies; } ;
struct connect_info {int status; int resp_ies_len; void* resp_ies; } ;
typedef  int /*<<< orphan*/  s32 ;
typedef  enum sub_frame_type { ____Placeholder_sub_frame_type } sub_frame_type ;

/* Variables and functions */
 size_t AID_LEN ; 
 int BEACON ; 
 int BEACON_INTERVAL_LEN ; 
 size_t CAP_INFO_LEN ; 
 int /*<<< orphan*/  EFAULT ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FCS_LEN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IE_HDR_LEN ; 
 int MAC_HDR_LEN ; 
 int MAKE_WORD16 (int,int) ; 
 int MAX_SSID_LEN ; 
 int PROBE_RSP ; 
 size_t STATUS_CODE_LEN ; 
 int TAG_PARAM_OFFSET ; 
 int TIME_STAMP_LEN ; 
 int WLAN_EID_DS_PARAMS ; 
 int WLAN_EID_TIM ; 
 scalar_t__ WLAN_STATUS_SUCCESS ; 
 int /*<<< orphan*/  kfree (struct network_info*) ; 
 void* kmemdup (int*,int,int /*<<< orphan*/ ) ; 
 struct network_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 

__attribute__((used)) static inline u16 get_beacon_period(u8 *data)
{
	u16 bcn_per;

	bcn_per  = data[0];
	bcn_per |= (data[1] << 8);

	return bcn_per;
}

__attribute__((used)) static inline u32 get_beacon_timestamp_lo(u8 *data)
{
	u32 time_stamp = 0;
	u32 index    = MAC_HDR_LEN;

	time_stamp |= data[index++];
	time_stamp |= (data[index++] << 8);
	time_stamp |= (data[index++] << 16);
	time_stamp |= (data[index]   << 24);

	return time_stamp;
}

__attribute__((used)) static inline u32 get_beacon_timestamp_hi(u8 *data)
{
	u32 time_stamp = 0;
	u32 index    = (MAC_HDR_LEN + 4);

	time_stamp |= data[index++];
	time_stamp |= (data[index++] << 8);
	time_stamp |= (data[index++] << 16);
	time_stamp |= (data[index]   << 24);

	return time_stamp;
}

__attribute__((used)) static inline enum sub_frame_type get_sub_type(u8 *header)
{
	return ((enum sub_frame_type)(header[0] & 0xFC));
}

__attribute__((used)) static inline u8 get_to_ds(u8 *header)
{
	return (header[1] & 0x01);
}

__attribute__((used)) static inline u8 get_from_ds(u8 *header)
{
	return ((header[1] & 0x02) >> 1);
}

__attribute__((used)) static inline void get_address1(u8 *msa, u8 *addr)
{
	memcpy(addr, msa + 4, 6);
}

__attribute__((used)) static inline void get_address2(u8 *msa, u8 *addr)
{
	memcpy(addr, msa + 10, 6);
}

__attribute__((used)) static inline void get_address3(u8 *msa, u8 *addr)
{
	memcpy(addr, msa + 16, 6);
}

__attribute__((used)) static inline void get_BSSID(u8 *data, u8 *bssid)
{
	if (get_from_ds(data) == 1)
		get_address2(data, bssid);
	else if (get_to_ds(data) == 1)
		get_address1(data, bssid);
	else
		get_address3(data, bssid);
}

__attribute__((used)) static inline void get_ssid(u8 *data, u8 *ssid, u8 *p_ssid_len)
{
	u8 i, j, len;

	len = data[TAG_PARAM_OFFSET + 1];
	j   = TAG_PARAM_OFFSET + 2;

	if (len >= MAX_SSID_LEN)
		len = 0;

	for (i = 0; i < len; i++, j++)
		ssid[i] = data[j];

	ssid[len] = '\0';

	*p_ssid_len = len;
}

__attribute__((used)) static inline u16 get_cap_info(u8 *data)
{
	u16 cap_info = 0;
	u16 index    = MAC_HDR_LEN;
	enum sub_frame_type st;

	st = get_sub_type(data);

	if (st == BEACON || st == PROBE_RSP)
		index += TIME_STAMP_LEN + BEACON_INTERVAL_LEN;

	cap_info  = data[index];
	cap_info |= (data[index + 1] << 8);

	return cap_info;
}

__attribute__((used)) static inline u16 get_asoc_status(u8 *data)
{
	u16 asoc_status;

	asoc_status = data[3];
	return (asoc_status << 8) | data[2];
}

__attribute__((used)) static u8 *get_tim_elm(u8 *msa, u16 rx_len, u16 tag_param_offset)
{
	u16 index;

	index = tag_param_offset;

	while (index < (rx_len - FCS_LEN)) {
		if (msa[index] == WLAN_EID_TIM)
			return &msa[index];
		index += (IE_HDR_LEN + msa[index + 1]);
	}

	return NULL;
}

__attribute__((used)) static u8 get_current_channel_802_11n(u8 *msa, u16 rx_len)
{
	u16 index;

	index = TAG_PARAM_OFFSET;
	while (index < (rx_len - FCS_LEN)) {
		if (msa[index] == WLAN_EID_DS_PARAMS)
			return msa[index + 2];
		index += msa[index + 1] + IE_HDR_LEN;
	}

	return 0;
}

s32 wilc_parse_network_info(u8 *msg_buffer,
			    struct network_info **ret_network_info)
{
	struct network_info *network_info;
	u8 *wid_val, *msa, *tim_elm, *ies;
	u32 tsf_lo, tsf_hi;
	u16 wid_len, rx_len, ies_len;
	u8 msg_type, index;

	msg_type = msg_buffer[0];

	if ('N' != msg_type)
		return -EFAULT;

	wid_len = MAKE_WORD16(msg_buffer[6], msg_buffer[7]);
	wid_val = &msg_buffer[8];

	network_info = kzalloc(sizeof(*network_info), GFP_KERNEL);
	if (!network_info)
		return -ENOMEM;

	network_info->rssi = wid_val[0];

	msa = &wid_val[1];

	rx_len = wid_len - 1;
	network_info->cap_info = get_cap_info(msa);
	network_info->tsf_lo = get_beacon_timestamp_lo(msa);

	tsf_lo = get_beacon_timestamp_lo(msa);
	tsf_hi = get_beacon_timestamp_hi(msa);

	network_info->tsf_hi = tsf_lo | ((u64)tsf_hi << 32);

	get_ssid(msa, network_info->ssid, &network_info->ssid_len);
	get_BSSID(msa, network_info->bssid);

	network_info->ch = get_current_channel_802_11n(msa, rx_len
						       + FCS_LEN);

	index = MAC_HDR_LEN + TIME_STAMP_LEN;

	network_info->beacon_period = get_beacon_period(msa + index);

	index += BEACON_INTERVAL_LEN + CAP_INFO_LEN;

	tim_elm = get_tim_elm(msa, rx_len + FCS_LEN, index);
	if (tim_elm)
		network_info->dtim_period = tim_elm[3];
	ies = &msa[TAG_PARAM_OFFSET];
	ies_len = rx_len - TAG_PARAM_OFFSET;

	if (ies_len > 0) {
		network_info->ies = kmemdup(ies, ies_len, GFP_KERNEL);
		if (!network_info->ies) {
			kfree(network_info);
			return -ENOMEM;
		}
	}
	network_info->ies_len = ies_len;

	*ret_network_info = network_info;

	return 0;
}

s32 wilc_parse_assoc_resp_info(u8 *buffer, u32 buffer_len,
			       struct connect_info *ret_conn_info)
{
	u8 *ies;
	u16 ies_len;

	ret_conn_info->status = get_asoc_status(buffer);
	if (ret_conn_info->status == WLAN_STATUS_SUCCESS) {
		ies = &buffer[CAP_INFO_LEN + STATUS_CODE_LEN + AID_LEN];
		ies_len = buffer_len - (CAP_INFO_LEN + STATUS_CODE_LEN +
					AID_LEN);

		ret_conn_info->resp_ies = kmemdup(ies, ies_len, GFP_KERNEL);
		if (!ret_conn_info->resp_ies)
			return -ENOMEM;

		ret_conn_info->resp_ies_len = ies_len;
	}

	return 0;
}

