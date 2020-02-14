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
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct wlandevice {int* wep_keylens; int** wep_keys; } ;
struct sk_buff {scalar_t__ cb; } ;
struct p80211_rxmeta {int dummy; } ;
struct p80211_frmmeta {scalar_t__ magic; struct p80211_rxmeta* rx; } ;

/* Variables and functions */
 int ETH_ALEN ; 
 int MAX_KEYLEN ; 
 int NUM_WEPKEYS ; 
 scalar_t__ P80211_FRMMETA_MAGIC ; 
 int WEP_KEY (int) ; 
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
 int /*<<< orphan*/  get_random_bytes (int*,int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,scalar_t__) ; 
 int /*<<< orphan*/  swap (scalar_t__,scalar_t__) ; 
 scalar_t__* wep_crc32_table ; 

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

int wep_change_key(struct wlandevice *wlandev, int keynum, u8 *key, int keylen)
{
	if (keylen < 0)
		return -1;
	if (keylen >= MAX_KEYLEN)
		return -1;
	if (!key)
		return -1;
	if (keynum < 0)
		return -1;
	if (keynum >= NUM_WEPKEYS)
		return -1;

	wlandev->wep_keylens[keynum] = keylen;
	memcpy(wlandev->wep_keys[keynum], key, keylen);

	return 0;
}

int wep_decrypt(struct wlandevice *wlandev, u8 *buf, u32 len, int key_override,
		u8 *iv, u8 *icv)
{
	u32 i, j, k, crc, keylen;
	u8 s[256], key[64], c_crc[4];
	u8 keyidx;

	/* Needs to be at least 8 bytes of payload */
	if (len <= 0)
		return -1;

	/* initialize the first bytes of the key from the IV */
	key[0] = iv[0];
	key[1] = iv[1];
	key[2] = iv[2];
	keyidx = WEP_KEY(iv[3]);

	if (key_override >= 0)
		keyidx = key_override;

	if (keyidx >= NUM_WEPKEYS)
		return -2;

	keylen = wlandev->wep_keylens[keyidx];

	if (keylen == 0)
		return -3;

	/* copy the rest of the key over from the designated key */
	memcpy(key + 3, wlandev->wep_keys[keyidx], keylen);

	keylen += 3;		/* add in IV bytes */

	/* set up the RC4 state */
	for (i = 0; i < 256; i++)
		s[i] = i;
	j = 0;
	for (i = 0; i < 256; i++) {
		j = (j + s[i] + key[i % keylen]) & 0xff;
		swap(i, j);
	}

	/* Apply the RC4 to the data, update the CRC32 */
	crc = ~0;
	i = 0;
	j = 0;
	for (k = 0; k < len; k++) {
		i = (i + 1) & 0xff;
		j = (j + s[i]) & 0xff;
		swap(i, j);
		buf[k] ^= s[(s[i] + s[j]) & 0xff];
		crc = wep_crc32_table[(crc ^ buf[k]) & 0xff] ^ (crc >> 8);
	}
	crc = ~crc;

	/* now let's check the crc */
	c_crc[0] = crc;
	c_crc[1] = crc >> 8;
	c_crc[2] = crc >> 16;
	c_crc[3] = crc >> 24;

	for (k = 0; k < 4; k++) {
		i = (i + 1) & 0xff;
		j = (j + s[i]) & 0xff;
		swap(i, j);
		if ((c_crc[k] ^ s[(s[i] + s[j]) & 0xff]) != icv[k])
			return -(4 | (k << 4));	/* ICV mismatch */
	}

	return 0;
}

int wep_encrypt(struct wlandevice *wlandev, u8 *buf,
		u8 *dst, u32 len, int keynum, u8 *iv, u8 *icv)
{
	u32 i, j, k, crc, keylen;
	u8 s[256], key[64];

	/* no point in WEPping an empty frame */
	if (len <= 0)
		return -1;

	/* we need to have a real key.. */
	if (keynum >= NUM_WEPKEYS)
		return -2;
	keylen = wlandev->wep_keylens[keynum];
	if (keylen <= 0)
		return -3;

	/* use a random IV.  And skip known weak ones. */
	get_random_bytes(iv, 3);
	while ((iv[1] == 0xff) && (iv[0] >= 3) && (iv[0] < keylen))
		get_random_bytes(iv, 3);

	iv[3] = (keynum & 0x03) << 6;

	key[0] = iv[0];
	key[1] = iv[1];
	key[2] = iv[2];

	/* copy the rest of the key over from the designated key */
	memcpy(key + 3, wlandev->wep_keys[keynum], keylen);

	keylen += 3;		/* add in IV bytes */

	/* set up the RC4 state */
	for (i = 0; i < 256; i++)
		s[i] = i;
	j = 0;
	for (i = 0; i < 256; i++) {
		j = (j + s[i] + key[i % keylen]) & 0xff;
		swap(i, j);
	}

	/* Update CRC32 then apply RC4 to the data */
	crc = ~0;
	i = 0;
	j = 0;
	for (k = 0; k < len; k++) {
		crc = wep_crc32_table[(crc ^ buf[k]) & 0xff] ^ (crc >> 8);
		i = (i + 1) & 0xff;
		j = (j + s[i]) & 0xff;
		swap(i, j);
		dst[k] = buf[k] ^ s[(s[i] + s[j]) & 0xff];
	}
	crc = ~crc;

	/* now let's encrypt the crc */
	icv[0] = crc;
	icv[1] = crc >> 8;
	icv[2] = crc >> 16;
	icv[3] = crc >> 24;

	for (k = 0; k < 4; k++) {
		i = (i + 1) & 0xff;
		j = (j + s[i]) & 0xff;
		swap(i, j);
		icv[k] ^= s[(s[i] + s[j]) & 0xff];
	}

	return 0;
}

