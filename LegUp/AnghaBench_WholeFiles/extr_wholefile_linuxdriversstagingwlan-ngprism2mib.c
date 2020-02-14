#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wpa ;
typedef  void* u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct wlandevice {int hostwep; int /*<<< orphan*/  netdev; struct hfa384x* priv; } ;
struct sk_buff {scalar_t__ cb; } ;
struct p80211pstrd {void** data; int len; } ;
struct TYPE_3__ {scalar_t__ data; void* status; } ;
struct TYPE_4__ {void* status; scalar_t__ data; } ;
struct p80211msg_dot11req_mibset {scalar_t__ msgcode; TYPE_1__ resultcode; TYPE_2__ mibattribute; } ;
struct p80211itemd {scalar_t__ did; void* status; scalar_t__ data; } ;
struct p80211_rxmeta {int dummy; } ;
struct p80211_frmmeta {scalar_t__ magic; struct p80211_rxmeta* rx; } ;
struct mibrec {scalar_t__ did; int flag; int (* func ) (struct mibrec*,int,struct wlandevice*,struct hfa384x*,struct p80211msg_dot11req_mibset*,void*) ;int parm2; int /*<<< orphan*/  parm1; } ;
struct hfa384x_wpa_data {void** data; void* datalen; } ;
struct hfa384x_bytestr {void** data; void* len; } ;
struct hfa384x {int dummy; } ;

/* Variables and functions */
#define  DIDmib_lnx_lnxConfigTable_lnxRSNAIE 139 
 scalar_t__ DIDmsg_dot11req_mibget ; 
 int ETH_ALEN ; 
 int F_READ ; 
 int F_STA ; 
 int F_WRITE ; 
 int HFA384x_RID_CNFWEP128DEFAULTKEY_LEN ; 
 int HFA384x_RID_CNFWEPDEFAULTKEY_LEN ; 
 int /*<<< orphan*/  HFA384x_RID_CNFWPADATA ; 
 int HFA384x_WEPFLAGS_DISABLE_RXCRYPT ; 
 int HFA384x_WEPFLAGS_DISABLE_TXCRYPT ; 
 int HOSTWEP_DECRYPT ; 
 int HOSTWEP_ENCRYPT ; 
 int MIB_TMP_MAXLEN ; 
 void* P80211ENUM_msgitem_status_data_ok ; 
 scalar_t__ P80211ENUM_resultcode_cant_get_writeonly_mib ; 
 scalar_t__ P80211ENUM_resultcode_cant_set_readonly_mib ; 
 scalar_t__ P80211ENUM_resultcode_implementation_failure ; 
 void* P80211ENUM_resultcode_not_supported ; 
 scalar_t__ P80211ENUM_resultcode_success ; 
 int P80211ENUM_truth_false ; 
 int P80211ENUM_truth_true ; 
 scalar_t__ P80211_FRMMETA_MAGIC ; 
 int WLAN_FCS_LEN ; 
#define  WLAN_FSTYPE_ACK 138 
#define  WLAN_FSTYPE_BLOCKACK 137 
#define  WLAN_FSTYPE_BLOCKACKREQ 136 
#define  WLAN_FSTYPE_CFEND 135 
#define  WLAN_FSTYPE_CFENDCFACK 134 
#define  WLAN_FSTYPE_CTS 133 
#define  WLAN_FSTYPE_PSPOLL 132 
#define  WLAN_FSTYPE_RTS 131 
#define  WLAN_FTYPE_CTL 130 
#define  WLAN_FTYPE_DATA 129 
#define  WLAN_FTYPE_MGMT 128 
 int /*<<< orphan*/  WLAN_GET_FC_FROMDS (int) ; 
 int WLAN_GET_FC_FSTYPE (int) ; 
 int WLAN_GET_FC_FTYPE (int) ; 
 int /*<<< orphan*/  WLAN_GET_FC_TODS (int) ; 
 int WLAN_HDR_A3_LEN ; 
 void* cpu_to_le16 (int) ; 
 int hfa384x_drvr_getconfig (struct hfa384x*,int /*<<< orphan*/ ,void**,int) ; 
 int hfa384x_drvr_getconfig16 (struct hfa384x*,int /*<<< orphan*/ ,int*) ; 
 int hfa384x_drvr_setconfig (struct hfa384x*,int /*<<< orphan*/ ,void**,int) ; 
 int hfa384x_drvr_setconfig16 (struct hfa384x*,int /*<<< orphan*/ ,int) ; 
 int le16_to_cpu (void*) ; 
 int /*<<< orphan*/  memcpy (void**,void**,int) ; 
 int /*<<< orphan*/  memset (void**,int /*<<< orphan*/ ,int) ; 
 struct mibrec* mibtab ; 
 int /*<<< orphan*/  netdev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  netdev_warn (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 void prism2mgmt_bytearea2pstr (void**,struct p80211pstrd*,int) ; 
 int stub1 (struct mibrec*,int,struct wlandevice*,struct hfa384x*,struct p80211msg_dot11req_mibset*,void*) ; 

__attribute__((used)) static inline u16 wlan_ctl_framelen(u16 fstype)
{
	switch (fstype)	{
	case WLAN_FSTYPE_BLOCKACKREQ:
		return 24;
	case WLAN_FSTYPE_BLOCKACK:
		return 152;
	case WLAN_FSTYPE_PSPOLL:
	case WLAN_FSTYPE_RTS:
	case WLAN_FSTYPE_CFEND:
	case WLAN_FSTYPE_CFENDCFACK:
		return 20;
	case WLAN_FSTYPE_CTS:
	case WLAN_FSTYPE_ACK:
		return 14;
	default:
		return 4;
	}
}

__attribute__((used)) static inline u16 p80211_headerlen(u16 fctl)
{
	u16 hdrlen = 0;

	switch (WLAN_GET_FC_FTYPE(fctl)) {
	case WLAN_FTYPE_MGMT:
		hdrlen = WLAN_HDR_A3_LEN;
		break;
	case WLAN_FTYPE_DATA:
		hdrlen = WLAN_HDR_A3_LEN;
		if (WLAN_GET_FC_TODS(fctl) && WLAN_GET_FC_FROMDS(fctl))
			hdrlen += ETH_ALEN;
		break;
	case WLAN_FTYPE_CTL:
		hdrlen = wlan_ctl_framelen(WLAN_GET_FC_FSTYPE(fctl)) -
		    WLAN_FCS_LEN;
		break;
	default:
		hdrlen = WLAN_HDR_A3_LEN;
	}

	return hdrlen;
}

__attribute__((used)) static inline struct p80211_frmmeta *p80211skb_frmmeta(struct sk_buff *skb)
{
	struct p80211_frmmeta *frmmeta = (struct p80211_frmmeta *)skb->cb;

	return frmmeta->magic == P80211_FRMMETA_MAGIC ? frmmeta : NULL;
}

__attribute__((used)) static inline struct p80211_rxmeta *p80211skb_rxmeta(struct sk_buff *skb)
{
	struct p80211_frmmeta *frmmeta = p80211skb_frmmeta(skb);

	return frmmeta ? frmmeta->rx : NULL;
}

int prism2mgmt_mibset_mibget(struct wlandevice *wlandev, void *msgp)
{
	struct hfa384x *hw = wlandev->priv;
	int result, isget;
	struct mibrec *mib;

	u16 which;

	struct p80211msg_dot11req_mibset *msg = msgp;
	struct p80211itemd *mibitem;

	msg->resultcode.status = P80211ENUM_msgitem_status_data_ok;
	msg->resultcode.data = P80211ENUM_resultcode_success;

	/*
	 ** Determine if this is an Access Point or a station.
	 */

	which = F_STA;

	/*
	 ** Find the MIB in the MIB table.  Note that a MIB may be in the
	 ** table twice...once for an AP and once for a station.  Make sure
	 ** to get the correct one.  Note that DID=0 marks the end of the
	 ** MIB table.
	 */

	mibitem = (struct p80211itemd *)msg->mibattribute.data;

	for (mib = mibtab; mib->did != 0; mib++)
		if (mib->did == mibitem->did && (mib->flag & which))
			break;

	if (mib->did == 0) {
		msg->resultcode.data = P80211ENUM_resultcode_not_supported;
		goto done;
	}

	/*
	 ** Determine if this is a "mibget" or a "mibset".  If this is a
	 ** "mibget", then make sure that the MIB may be read.  Otherwise,
	 ** this is a "mibset" so make make sure that the MIB may be written.
	 */

	isget = (msg->msgcode == DIDmsg_dot11req_mibget);

	if (isget) {
		if (!(mib->flag & F_READ)) {
			msg->resultcode.data =
			    P80211ENUM_resultcode_cant_get_writeonly_mib;
			goto done;
		}
	} else {
		if (!(mib->flag & F_WRITE)) {
			msg->resultcode.data =
			    P80211ENUM_resultcode_cant_set_readonly_mib;
			goto done;
		}
	}

	/*
	 ** Execute the MIB function.  If things worked okay, then make
	 ** sure that the MIB function also worked okay.  If so, and this
	 ** is a "mibget", then the status value must be set for both the
	 ** "mibattribute" parameter and the mib item within the data
	 ** portion of the "mibattribute".
	 */

	result = mib->func(mib, isget, wlandev, hw, msg, (void *)mibitem->data);

	if (msg->resultcode.data == P80211ENUM_resultcode_success) {
		if (result != 0) {
			pr_debug("get/set failure, result=%d\n", result);
			msg->resultcode.data =
			    P80211ENUM_resultcode_implementation_failure;
		} else {
			if (isget) {
				msg->mibattribute.status =
				    P80211ENUM_msgitem_status_data_ok;
				mibitem->status =
				    P80211ENUM_msgitem_status_data_ok;
			}
		}
	}

done:
	return 0;
}

__attribute__((used)) static int prism2mib_bytearea2pstr(struct mibrec *mib,
				   int isget,
				   struct wlandevice *wlandev,
				   struct hfa384x *hw,
				   struct p80211msg_dot11req_mibset *msg,
				   void *data)
{
	int result;
	struct p80211pstrd *pstr = data;
	u8 bytebuf[MIB_TMP_MAXLEN];

	if (isget) {
		result =
		    hfa384x_drvr_getconfig(hw, mib->parm1, bytebuf, mib->parm2);
		prism2mgmt_bytearea2pstr(bytebuf, pstr, mib->parm2);
	} else {
		memset(bytebuf, 0, mib->parm2);
		memcpy(bytebuf, pstr->data, pstr->len);
		result =
		    hfa384x_drvr_setconfig(hw, mib->parm1, bytebuf, mib->parm2);
	}

	return result;
}

__attribute__((used)) static int prism2mib_uint32(struct mibrec *mib,
			    int isget,
			    struct wlandevice *wlandev,
			    struct hfa384x *hw,
			    struct p80211msg_dot11req_mibset *msg, void *data)
{
	int result;
	u32 *uint32 = data;
	u8 bytebuf[MIB_TMP_MAXLEN];
	u16 *wordbuf = (u16 *)bytebuf;

	if (isget) {
		result = hfa384x_drvr_getconfig16(hw, mib->parm1, wordbuf);
		*uint32 = *wordbuf;
	} else {
		*wordbuf = *uint32;
		result = hfa384x_drvr_setconfig16(hw, mib->parm1, *wordbuf);
	}

	return result;
}

__attribute__((used)) static int prism2mib_flag(struct mibrec *mib,
			  int isget,
			  struct wlandevice *wlandev,
			  struct hfa384x *hw,
			  struct p80211msg_dot11req_mibset *msg, void *data)
{
	int result;
	u32 *uint32 = data;
	u8 bytebuf[MIB_TMP_MAXLEN];
	u16 *wordbuf = (u16 *)bytebuf;
	u32 flags;

	result = hfa384x_drvr_getconfig16(hw, mib->parm1, wordbuf);
	if (result == 0) {
		flags = *wordbuf;
		if (isget) {
			*uint32 = (flags & mib->parm2) ?
			    P80211ENUM_truth_true : P80211ENUM_truth_false;
		} else {
			if ((*uint32) == P80211ENUM_truth_true)
				flags |= mib->parm2;
			else
				flags &= ~mib->parm2;
			*wordbuf = flags;
			result =
			    hfa384x_drvr_setconfig16(hw, mib->parm1, *wordbuf);
		}
	}

	return result;
}

__attribute__((used)) static int prism2mib_wepdefaultkey(struct mibrec *mib,
				   int isget,
				   struct wlandevice *wlandev,
				   struct hfa384x *hw,
				   struct p80211msg_dot11req_mibset *msg,
				   void *data)
{
	int result;
	struct p80211pstrd *pstr = data;
	u8 bytebuf[MIB_TMP_MAXLEN];
	u16 len;

	if (isget) {
		result = 0;	/* Should never happen. */
	} else {
		len = (pstr->len > 5) ? HFA384x_RID_CNFWEP128DEFAULTKEY_LEN :
		    HFA384x_RID_CNFWEPDEFAULTKEY_LEN;
		memset(bytebuf, 0, len);
		memcpy(bytebuf, pstr->data, pstr->len);
		result = hfa384x_drvr_setconfig(hw, mib->parm1, bytebuf, len);
	}

	return result;
}

__attribute__((used)) static int prism2mib_privacyinvoked(struct mibrec *mib,
				    int isget,
				    struct wlandevice *wlandev,
				    struct hfa384x *hw,
				    struct p80211msg_dot11req_mibset *msg,
				    void *data)
{
	if (wlandev->hostwep & HOSTWEP_DECRYPT) {
		if (wlandev->hostwep & HOSTWEP_DECRYPT)
			mib->parm2 |= HFA384x_WEPFLAGS_DISABLE_RXCRYPT;
		if (wlandev->hostwep & HOSTWEP_ENCRYPT)
			mib->parm2 |= HFA384x_WEPFLAGS_DISABLE_TXCRYPT;
	}

	return prism2mib_flag(mib, isget, wlandev, hw, msg, data);
}

__attribute__((used)) static int prism2mib_excludeunencrypted(struct mibrec *mib,
					int isget,
					struct wlandevice *wlandev,
					struct hfa384x *hw,
					struct p80211msg_dot11req_mibset *msg,
					void *data)
{
	return prism2mib_flag(mib, isget, wlandev, hw, msg, data);
}

__attribute__((used)) static int prism2mib_fragmentationthreshold(struct mibrec *mib,
					    int isget,
					    struct wlandevice *wlandev,
					    struct hfa384x *hw,
					    struct p80211msg_dot11req_mibset *msg,
					    void *data)
{
	u32 *uint32 = data;

	if (!isget)
		if ((*uint32) % 2) {
			netdev_warn(wlandev->netdev,
				    "Attempt to set odd number FragmentationThreshold\n");
			msg->resultcode.data =
			    P80211ENUM_resultcode_not_supported;
			return 0;
		}

	return prism2mib_uint32(mib, isget, wlandev, hw, msg, data);
}

__attribute__((used)) static int prism2mib_priv(struct mibrec *mib,
			  int isget,
			  struct wlandevice *wlandev,
			  struct hfa384x *hw,
			  struct p80211msg_dot11req_mibset *msg, void *data)
{
	struct p80211pstrd *pstr = data;

	switch (mib->did) {
	case DIDmib_lnx_lnxConfigTable_lnxRSNAIE:{
			struct hfa384x_wpa_data wpa;

			if (isget) {
				hfa384x_drvr_getconfig(hw,
						       HFA384x_RID_CNFWPADATA,
						       (u8 *)&wpa,
						       sizeof(wpa));
				pstr->len = le16_to_cpu(wpa.datalen);
				memcpy(pstr->data, wpa.data, pstr->len);
			} else {
				wpa.datalen = cpu_to_le16(pstr->len);
				memcpy(wpa.data, pstr->data, pstr->len);

				hfa384x_drvr_setconfig(hw,
						       HFA384x_RID_CNFWPADATA,
						       (u8 *)&wpa,
						       sizeof(wpa));
			}
			break;
		}
	default:
		netdev_err(wlandev->netdev, "Unhandled DID 0x%08x\n", mib->did);
	}

	return 0;
}

void prism2mgmt_pstr2bytestr(struct hfa384x_bytestr *bytestr,
			     struct p80211pstrd *pstr)
{
	bytestr->len = cpu_to_le16((u16)(pstr->len));
	memcpy(bytestr->data, pstr->data, pstr->len);
}

void prism2mgmt_bytestr2pstr(struct hfa384x_bytestr *bytestr,
			     struct p80211pstrd *pstr)
{
	pstr->len = (u8)(le16_to_cpu(bytestr->len));
	memcpy(pstr->data, bytestr->data, pstr->len);
}

void prism2mgmt_bytearea2pstr(u8 *bytearea, struct p80211pstrd *pstr, int len)
{
	pstr->len = (u8)len;
	memcpy(pstr->data, bytearea, len);
}

