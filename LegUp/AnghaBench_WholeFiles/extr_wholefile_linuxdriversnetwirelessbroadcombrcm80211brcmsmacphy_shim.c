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
typedef  int /*<<< orphan*/  uint ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct wlapi_timer {int dummy; } ;
struct sk_buff {int dummy; } ;
struct phy_shim_info {struct brcms_hardware* wlc_hw; struct brcms_c_info* wlc; struct brcms_info* wl; } ;
struct brcms_timer {int dummy; } ;
struct brcms_info {int dummy; } ;
struct brcms_hardware {int dummy; } ;
struct brcms_c_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BRCMS_WAKE_OVERRIDE_PHYREG ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  brcms_add_timer (struct brcms_timer*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  brcms_b_bw_set (struct brcms_hardware*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_b_copyfrom_objmem (struct brcms_hardware*,int /*<<< orphan*/ ,void*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_b_copyto_objmem (struct brcms_hardware*,int /*<<< orphan*/ ,void const*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_b_core_phypll_ctl (struct brcms_hardware*,int) ; 
 int /*<<< orphan*/  brcms_b_core_phypll_reset (struct brcms_hardware*) ; 
 int /*<<< orphan*/  brcms_b_corereset (struct brcms_hardware*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_b_get_txant (struct brcms_hardware*) ; 
 int /*<<< orphan*/  brcms_b_macphyclk_set (struct brcms_hardware*,int) ; 
 int /*<<< orphan*/  brcms_b_mctrl (struct brcms_hardware*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_b_mhf (struct brcms_hardware*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  brcms_b_phy_reset (struct brcms_hardware*) ; 
 int /*<<< orphan*/  brcms_b_phyclk_fgc (struct brcms_hardware*,int) ; 
 int /*<<< orphan*/  brcms_b_rate_shm_offset (struct brcms_hardware*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_b_read_shm (struct brcms_hardware*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_b_switch_macfreq (struct brcms_hardware*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_b_write_shm (struct brcms_hardware*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_b_write_template_ram (struct brcms_hardware*,int,int,void*) ; 
 int /*<<< orphan*/  brcms_c_enable_mac (struct brcms_c_info*) ; 
 int /*<<< orphan*/  brcms_c_suspend_mac_and_wait (struct brcms_c_info*) ; 
 int /*<<< orphan*/  brcms_c_ucode_wake_override_clear (struct brcms_hardware*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_c_ucode_wake_override_set (struct brcms_hardware*,int /*<<< orphan*/ ) ; 
 int brcms_del_timer (struct brcms_timer*) ; 
 int /*<<< orphan*/  brcms_free_timer (struct brcms_timer*) ; 
 scalar_t__ brcms_init_timer (struct brcms_info*,void (*) (void*),void*,char const*) ; 
 int /*<<< orphan*/  brcms_intrsoff (struct brcms_info*) ; 
 int /*<<< orphan*/  brcms_intrson (struct brcms_info*) ; 
 int /*<<< orphan*/  brcms_intrsrestore (struct brcms_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct phy_shim_info*) ; 
 struct phy_shim_info* kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void dma_spin_for_len(uint len, struct sk_buff *head)
{
#if defined(CONFIG_BCM47XX)
	if (!len) {
		while (!(len = *(u16 *) KSEG1ADDR(head->data)))
			udelay(1);

		*(u16 *) (head->data) = cpu_to_le16((u16) len);
	}
#endif				/* defined(CONFIG_BCM47XX) */
}

__attribute__((used)) static inline void brcms_led_unregister(struct brcms_info *wl) {}

__attribute__((used)) static inline int brcms_led_register(struct brcms_info *wl)
{
	return -ENOTSUPP;
}

struct phy_shim_info *wlc_phy_shim_attach(struct brcms_hardware *wlc_hw,
					  struct brcms_info *wl,
					  struct brcms_c_info *wlc) {
	struct phy_shim_info *physhim = NULL;

	physhim = kzalloc(sizeof(struct phy_shim_info), GFP_ATOMIC);
	if (!physhim)
		return NULL;

	physhim->wlc_hw = wlc_hw;
	physhim->wlc = wlc;
	physhim->wl = wl;

	return physhim;
}

void wlc_phy_shim_detach(struct phy_shim_info *physhim)
{
	kfree(physhim);
}

struct wlapi_timer *wlapi_init_timer(struct phy_shim_info *physhim,
				     void (*fn)(struct brcms_phy *pi),
				     void *arg, const char *name)
{
	return (struct wlapi_timer *)
			brcms_init_timer(physhim->wl, (void (*)(void *))fn,
					 arg, name);
}

void wlapi_free_timer(struct wlapi_timer *t)
{
	brcms_free_timer((struct brcms_timer *)t);
}

void
wlapi_add_timer(struct wlapi_timer *t, uint ms, int periodic)
{
	brcms_add_timer((struct brcms_timer *)t, ms, periodic);
}

bool wlapi_del_timer(struct wlapi_timer *t)
{
	return brcms_del_timer((struct brcms_timer *)t);
}

void wlapi_intrson(struct phy_shim_info *physhim)
{
	brcms_intrson(physhim->wl);
}

u32 wlapi_intrsoff(struct phy_shim_info *physhim)
{
	return brcms_intrsoff(physhim->wl);
}

void wlapi_intrsrestore(struct phy_shim_info *physhim, u32 macintmask)
{
	brcms_intrsrestore(physhim->wl, macintmask);
}

void wlapi_bmac_write_shm(struct phy_shim_info *physhim, uint offset, u16 v)
{
	brcms_b_write_shm(physhim->wlc_hw, offset, v);
}

u16 wlapi_bmac_read_shm(struct phy_shim_info *physhim, uint offset)
{
	return brcms_b_read_shm(physhim->wlc_hw, offset);
}

void
wlapi_bmac_mhf(struct phy_shim_info *physhim, u8 idx, u16 mask,
	       u16 val, int bands)
{
	brcms_b_mhf(physhim->wlc_hw, idx, mask, val, bands);
}

void wlapi_bmac_corereset(struct phy_shim_info *physhim, u32 flags)
{
	brcms_b_corereset(physhim->wlc_hw, flags);
}

void wlapi_suspend_mac_and_wait(struct phy_shim_info *physhim)
{
	brcms_c_suspend_mac_and_wait(physhim->wlc);
}

void wlapi_switch_macfreq(struct phy_shim_info *physhim, u8 spurmode)
{
	brcms_b_switch_macfreq(physhim->wlc_hw, spurmode);
}

void wlapi_enable_mac(struct phy_shim_info *physhim)
{
	brcms_c_enable_mac(physhim->wlc);
}

void wlapi_bmac_mctrl(struct phy_shim_info *physhim, u32 mask, u32 val)
{
	brcms_b_mctrl(physhim->wlc_hw, mask, val);
}

void wlapi_bmac_phy_reset(struct phy_shim_info *physhim)
{
	brcms_b_phy_reset(physhim->wlc_hw);
}

void wlapi_bmac_bw_set(struct phy_shim_info *physhim, u16 bw)
{
	brcms_b_bw_set(physhim->wlc_hw, bw);
}

u16 wlapi_bmac_get_txant(struct phy_shim_info *physhim)
{
	return brcms_b_get_txant(physhim->wlc_hw);
}

void wlapi_bmac_phyclk_fgc(struct phy_shim_info *physhim, bool clk)
{
	brcms_b_phyclk_fgc(physhim->wlc_hw, clk);
}

void wlapi_bmac_macphyclk_set(struct phy_shim_info *physhim, bool clk)
{
	brcms_b_macphyclk_set(physhim->wlc_hw, clk);
}

void wlapi_bmac_core_phypll_ctl(struct phy_shim_info *physhim, bool on)
{
	brcms_b_core_phypll_ctl(physhim->wlc_hw, on);
}

void wlapi_bmac_core_phypll_reset(struct phy_shim_info *physhim)
{
	brcms_b_core_phypll_reset(physhim->wlc_hw);
}

void wlapi_bmac_ucode_wake_override_phyreg_set(struct phy_shim_info *physhim)
{
	brcms_c_ucode_wake_override_set(physhim->wlc_hw,
					BRCMS_WAKE_OVERRIDE_PHYREG);
}

void wlapi_bmac_ucode_wake_override_phyreg_clear(struct phy_shim_info *physhim)
{
	brcms_c_ucode_wake_override_clear(physhim->wlc_hw,
					  BRCMS_WAKE_OVERRIDE_PHYREG);
}

void
wlapi_bmac_write_template_ram(struct phy_shim_info *physhim, int offset,
			      int len, void *buf)
{
	brcms_b_write_template_ram(physhim->wlc_hw, offset, len, buf);
}

u16 wlapi_bmac_rate_shm_offset(struct phy_shim_info *physhim, u8 rate)
{
	return brcms_b_rate_shm_offset(physhim->wlc_hw, rate);
}

void wlapi_ucode_sample_init(struct phy_shim_info *physhim)
{
}

void
wlapi_copyfrom_objmem(struct phy_shim_info *physhim, uint offset, void *buf,
		      int len, u32 sel)
{
	brcms_b_copyfrom_objmem(physhim->wlc_hw, offset, buf, len, sel);
}

void
wlapi_copyto_objmem(struct phy_shim_info *physhim, uint offset, const void *buf,
		    int l, u32 sel)
{
	brcms_b_copyto_objmem(physhim->wlc_hw, offset, buf, l, sel);
}

