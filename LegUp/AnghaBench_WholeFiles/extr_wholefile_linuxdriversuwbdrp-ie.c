#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct uwb_mas_bm {int unsafe; scalar_t__* bm; } ;
struct uwb_rsv_move {struct uwb_mas_bm companion_mas; struct uwb_ie_drp* companion_drp_ie; } ;
struct TYPE_6__ {int type; int /*<<< orphan*/  devaddr; TYPE_1__* dev; } ;
struct uwb_rsv {size_t state; int ie_valid; struct uwb_ie_drp* drp_ie; struct uwb_rsv_move mv; struct uwb_mas_bm mas; TYPE_3__* owner; TYPE_2__ target; int /*<<< orphan*/  type; int /*<<< orphan*/  stream; int /*<<< orphan*/  tiebreaker; } ;
struct uwb_rc {int /*<<< orphan*/  uwb_dev; } ;
struct uwb_ie_hdr {int dummy; } ;
struct TYPE_8__ {int length; int /*<<< orphan*/  element_id; } ;
struct uwb_ie_drp {struct uwb_drp_alloc* allocs; TYPE_4__ hdr; int /*<<< orphan*/  dev_addr; } ;
struct uwb_drp_alloc {int mas_bm; int zone_bm; } ;
struct uwb_dev {int /*<<< orphan*/  dev; } ;
struct uwb_beca_e {int /*<<< orphan*/  refcnt; } ;
typedef  int __le16 ;
struct TYPE_7__ {int /*<<< orphan*/  dev_addr; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  DECLARE_BITMAP (scalar_t__*,int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  UWB_DRP_REASON_ACCEPTED 151 
#define  UWB_DRP_REASON_CONFLICT 150 
#define  UWB_DRP_REASON_DENIED 149 
#define  UWB_DRP_REASON_MODIFIED 148 
#define  UWB_DRP_REASON_PENDING 147 
 int /*<<< orphan*/  UWB_IE_DRP ; 
 int UWB_MAS_PER_ZONE ; 
 int UWB_NUM_MAS ; 
 int UWB_NUM_ZONES ; 
 scalar_t__ UWB_RSV_STATE_NONE ; 
#define  UWB_RSV_STATE_O_ESTABLISHED 146 
#define  UWB_RSV_STATE_O_INITIATED 145 
#define  UWB_RSV_STATE_O_MODIFIED 144 
#define  UWB_RSV_STATE_O_MOVE_COMBINING 143 
#define  UWB_RSV_STATE_O_MOVE_EXPANDING 142 
#define  UWB_RSV_STATE_O_MOVE_REDUCING 141 
#define  UWB_RSV_STATE_O_PENDING 140 
#define  UWB_RSV_STATE_O_TO_BE_MOVED 139 
#define  UWB_RSV_STATE_T_ACCEPTED 138 
#define  UWB_RSV_STATE_T_CONFLICT 137 
#define  UWB_RSV_STATE_T_DENIED 136 
#define  UWB_RSV_STATE_T_EXPANDING_ACCEPTED 135 
#define  UWB_RSV_STATE_T_EXPANDING_CONFLICT 134 
#define  UWB_RSV_STATE_T_EXPANDING_DENIED 133 
#define  UWB_RSV_STATE_T_EXPANDING_PENDING 132 
#define  UWB_RSV_STATE_T_PENDING 131 
#define  UWB_RSV_STATE_T_RESIZED 130 
#define  UWB_RSV_TARGET_DEV 129 
#define  UWB_RSV_TARGET_DEVADDR 128 
 int /*<<< orphan*/  bitmap_copy (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  bitmap_shift_right (scalar_t__*,scalar_t__*,int,int) ; 
 scalar_t__ bitmap_weight (scalar_t__*,int) ; 
 int /*<<< orphan*/  bitmap_zero (scalar_t__*,int) ; 
 void* cpu_to_le16 (int) ; 
 int /*<<< orphan*/  device_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct uwb_ie_drp*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct uwb_ie_drp* kzalloc (int,int /*<<< orphan*/ ) ; 
 int le16_to_cpu (int) ; 
 int /*<<< orphan*/  memcpy (struct uwb_ie_drp*,struct uwb_ie_drp*,int) ; 
 int /*<<< orphan*/  set_bit (int,scalar_t__*) ; 
 scalar_t__* tmp_bmp ; 
 scalar_t__* tmp_mas_bm ; 
 int /*<<< orphan*/  uwb_bce_kfree ; 
 int /*<<< orphan*/  uwb_dev_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uwb_dev_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uwb_ie_drp_set_owner (struct uwb_ie_drp*,scalar_t__) ; 
 int /*<<< orphan*/  uwb_ie_drp_set_reason_code (struct uwb_ie_drp*,int) ; 
 int /*<<< orphan*/  uwb_ie_drp_set_status (struct uwb_ie_drp*,int) ; 
 int /*<<< orphan*/  uwb_ie_drp_set_stream_index (struct uwb_ie_drp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uwb_ie_drp_set_tiebreaker (struct uwb_ie_drp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uwb_ie_drp_set_type (struct uwb_ie_drp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uwb_ie_drp_set_unsafe (struct uwb_ie_drp*,int) ; 
 scalar_t__ uwb_rsv_has_two_drp_ies (struct uwb_rsv*) ; 
 scalar_t__ uwb_rsv_is_owner (struct uwb_rsv*) ; 

__attribute__((used)) static inline struct uwb_rc *__uwb_rc_get(struct uwb_rc *rc)
{
	uwb_dev_get(&rc->uwb_dev);
	return rc;
}

__attribute__((used)) static inline void __uwb_rc_put(struct uwb_rc *rc)
{
	if (rc)
		uwb_dev_put(&rc->uwb_dev);
}

__attribute__((used)) static inline void uwb_bce_get(struct uwb_beca_e *bce)
{
	kref_get(&bce->refcnt);
}

__attribute__((used)) static inline void uwb_bce_put(struct uwb_beca_e *bce)
{
	kref_put(&bce->refcnt, uwb_bce_kfree);
}

__attribute__((used)) static inline void uwb_dev_lock(struct uwb_dev *uwb_dev)
{
	device_lock(&uwb_dev->dev);
}

__attribute__((used)) static inline void uwb_dev_unlock(struct uwb_dev *uwb_dev)
{
	device_unlock(&uwb_dev->dev);
}

__attribute__((used)) static int uwb_rsv_reason_code(struct uwb_rsv *rsv)
{
	static const int reason_codes[] = {
		[UWB_RSV_STATE_O_INITIATED]          = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_O_PENDING]            = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_O_MODIFIED]           = UWB_DRP_REASON_MODIFIED,
		[UWB_RSV_STATE_O_ESTABLISHED]        = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_O_TO_BE_MOVED]        = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_O_MOVE_COMBINING]     = UWB_DRP_REASON_MODIFIED,
		[UWB_RSV_STATE_O_MOVE_REDUCING]      = UWB_DRP_REASON_MODIFIED,
		[UWB_RSV_STATE_O_MOVE_EXPANDING]     = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_T_ACCEPTED]           = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_T_CONFLICT]           = UWB_DRP_REASON_CONFLICT,
		[UWB_RSV_STATE_T_PENDING]            = UWB_DRP_REASON_PENDING,
		[UWB_RSV_STATE_T_DENIED]             = UWB_DRP_REASON_DENIED,
		[UWB_RSV_STATE_T_RESIZED]            = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_T_EXPANDING_ACCEPTED] = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_T_EXPANDING_CONFLICT] = UWB_DRP_REASON_CONFLICT,
		[UWB_RSV_STATE_T_EXPANDING_PENDING]  = UWB_DRP_REASON_PENDING,
		[UWB_RSV_STATE_T_EXPANDING_DENIED]   = UWB_DRP_REASON_DENIED,
	};

	return reason_codes[rsv->state];
}

__attribute__((used)) static int uwb_rsv_companion_reason_code(struct uwb_rsv *rsv)
{
	static const int companion_reason_codes[] = {
		[UWB_RSV_STATE_O_MOVE_EXPANDING]     = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_T_EXPANDING_ACCEPTED] = UWB_DRP_REASON_ACCEPTED,
		[UWB_RSV_STATE_T_EXPANDING_CONFLICT] = UWB_DRP_REASON_CONFLICT,
		[UWB_RSV_STATE_T_EXPANDING_PENDING]  = UWB_DRP_REASON_PENDING,
		[UWB_RSV_STATE_T_EXPANDING_DENIED]   = UWB_DRP_REASON_DENIED,
	};

	return companion_reason_codes[rsv->state];
}

int uwb_rsv_status(struct uwb_rsv *rsv)
{
	static const int statuses[] = {
		[UWB_RSV_STATE_O_INITIATED]          = 0,
		[UWB_RSV_STATE_O_PENDING]            = 0,
		[UWB_RSV_STATE_O_MODIFIED]           = 1,
		[UWB_RSV_STATE_O_ESTABLISHED]        = 1,
		[UWB_RSV_STATE_O_TO_BE_MOVED]        = 0,
		[UWB_RSV_STATE_O_MOVE_COMBINING]     = 1,
		[UWB_RSV_STATE_O_MOVE_REDUCING]      = 1,
		[UWB_RSV_STATE_O_MOVE_EXPANDING]     = 1,
		[UWB_RSV_STATE_T_ACCEPTED]           = 1,
		[UWB_RSV_STATE_T_CONFLICT]           = 0,
		[UWB_RSV_STATE_T_PENDING]            = 0,
		[UWB_RSV_STATE_T_DENIED]             = 0,
		[UWB_RSV_STATE_T_RESIZED]            = 1,
		[UWB_RSV_STATE_T_EXPANDING_ACCEPTED] = 1,
		[UWB_RSV_STATE_T_EXPANDING_CONFLICT] = 1,
		[UWB_RSV_STATE_T_EXPANDING_PENDING]  = 1,
		[UWB_RSV_STATE_T_EXPANDING_DENIED]   = 1,

	};

	return statuses[rsv->state];
}

int uwb_rsv_companion_status(struct uwb_rsv *rsv)
{
	static const int companion_statuses[] = {
		[UWB_RSV_STATE_O_MOVE_EXPANDING]     = 0,
		[UWB_RSV_STATE_T_EXPANDING_ACCEPTED] = 1,
		[UWB_RSV_STATE_T_EXPANDING_CONFLICT] = 0,
		[UWB_RSV_STATE_T_EXPANDING_PENDING]  = 0,
		[UWB_RSV_STATE_T_EXPANDING_DENIED]   = 0,
	};

	return companion_statuses[rsv->state];
}

__attribute__((used)) static struct uwb_ie_drp *uwb_drp_ie_alloc(void)
{
	struct uwb_ie_drp *drp_ie;

	drp_ie = kzalloc(sizeof(struct uwb_ie_drp) +
			UWB_NUM_ZONES * sizeof(struct uwb_drp_alloc),
			GFP_KERNEL);
	if (drp_ie)
		drp_ie->hdr.element_id = UWB_IE_DRP;
	return drp_ie;
}

__attribute__((used)) static void uwb_drp_ie_from_bm(struct uwb_ie_drp *drp_ie,
			       struct uwb_mas_bm *mas)
{
	int z, i, num_fields = 0, next = 0;
	struct uwb_drp_alloc *zones;
	__le16 current_bmp;
	DECLARE_BITMAP(tmp_bmp, UWB_NUM_MAS);
	DECLARE_BITMAP(tmp_mas_bm, UWB_MAS_PER_ZONE);

	zones = drp_ie->allocs;

	bitmap_copy(tmp_bmp, mas->bm, UWB_NUM_MAS);

	/* Determine unique MAS bitmaps in zones from bitmap. */
	for (z = 0; z < UWB_NUM_ZONES; z++) {
		bitmap_copy(tmp_mas_bm, tmp_bmp, UWB_MAS_PER_ZONE);
		if (bitmap_weight(tmp_mas_bm, UWB_MAS_PER_ZONE) > 0) {
			bool found = false;
			current_bmp = (__le16) *tmp_mas_bm;
			for (i = 0; i < next; i++) {
				if (current_bmp == zones[i].mas_bm) {
					zones[i].zone_bm |= 1 << z;
					found = true;
					break;
				}
			}
			if (!found)  {
				num_fields++;
				zones[next].zone_bm = 1 << z;
				zones[next].mas_bm = current_bmp;
				next++;
			}
		}
		bitmap_shift_right(tmp_bmp, tmp_bmp, UWB_MAS_PER_ZONE, UWB_NUM_MAS);
	}

	/* Store in format ready for transmission (le16). */
	for (i = 0; i < num_fields; i++) {
		drp_ie->allocs[i].zone_bm = cpu_to_le16(zones[i].zone_bm);
		drp_ie->allocs[i].mas_bm = cpu_to_le16(zones[i].mas_bm);
	}

	drp_ie->hdr.length = sizeof(struct uwb_ie_drp) - sizeof(struct uwb_ie_hdr)
		+ num_fields * sizeof(struct uwb_drp_alloc);
}

int uwb_drp_ie_update(struct uwb_rsv *rsv)
{
	struct uwb_ie_drp *drp_ie;
	struct uwb_rsv_move *mv;
	int unsafe;

	if (rsv->state == UWB_RSV_STATE_NONE) {
		kfree(rsv->drp_ie);
		rsv->drp_ie = NULL;
		return 0;
	}

	unsafe = rsv->mas.unsafe ? 1 : 0;

	if (rsv->drp_ie == NULL) {
		rsv->drp_ie = uwb_drp_ie_alloc();
		if (rsv->drp_ie == NULL)
			return -ENOMEM;
	}
	drp_ie = rsv->drp_ie;

	uwb_ie_drp_set_unsafe(drp_ie,       unsafe);
	uwb_ie_drp_set_tiebreaker(drp_ie,   rsv->tiebreaker);
	uwb_ie_drp_set_owner(drp_ie,        uwb_rsv_is_owner(rsv));
	uwb_ie_drp_set_status(drp_ie,       uwb_rsv_status(rsv));
	uwb_ie_drp_set_reason_code(drp_ie,  uwb_rsv_reason_code(rsv));
	uwb_ie_drp_set_stream_index(drp_ie, rsv->stream);
	uwb_ie_drp_set_type(drp_ie,         rsv->type);

	if (uwb_rsv_is_owner(rsv)) {
		switch (rsv->target.type) {
		case UWB_RSV_TARGET_DEV:
			drp_ie->dev_addr = rsv->target.dev->dev_addr;
			break;
		case UWB_RSV_TARGET_DEVADDR:
			drp_ie->dev_addr = rsv->target.devaddr;
			break;
		}
	} else
		drp_ie->dev_addr = rsv->owner->dev_addr;

	uwb_drp_ie_from_bm(drp_ie, &rsv->mas);

	if (uwb_rsv_has_two_drp_ies(rsv)) {
		mv = &rsv->mv;
		if (mv->companion_drp_ie == NULL) {
			mv->companion_drp_ie = uwb_drp_ie_alloc();
			if (mv->companion_drp_ie == NULL)
				return -ENOMEM;
		}
		drp_ie = mv->companion_drp_ie;

		/* keep all the same configuration of the main drp_ie */
		memcpy(drp_ie, rsv->drp_ie, sizeof(struct uwb_ie_drp));


		/* FIXME: handle properly the unsafe bit */
		uwb_ie_drp_set_unsafe(drp_ie,       1);
		uwb_ie_drp_set_status(drp_ie,       uwb_rsv_companion_status(rsv));
		uwb_ie_drp_set_reason_code(drp_ie,  uwb_rsv_companion_reason_code(rsv));

		uwb_drp_ie_from_bm(drp_ie, &mv->companion_mas);
	}

	rsv->ie_valid = true;
	return 0;
}

__attribute__((used)) static
void uwb_drp_ie_single_zone_to_bm(struct uwb_mas_bm *bm, u8 zone, u16 mas_bm)
{
	int mas;
	u16 mas_mask;

	for (mas = 0; mas < UWB_MAS_PER_ZONE; mas++) {
		mas_mask = 1 << mas;
		if (mas_bm & mas_mask)
			set_bit(zone * UWB_NUM_ZONES + mas, bm->bm);
	}
}

void uwb_drp_ie_to_bm(struct uwb_mas_bm *bm, const struct uwb_ie_drp *drp_ie)
{
	int numallocs = (drp_ie->hdr.length - 4) / 4;
	const struct uwb_drp_alloc *alloc;
	int cnt;
	u16 zone_bm, mas_bm;
	u8 zone;
	u16 zone_mask;

	bitmap_zero(bm->bm, UWB_NUM_MAS);

	for (cnt = 0; cnt < numallocs; cnt++) {
		alloc = &drp_ie->allocs[cnt];
		zone_bm = le16_to_cpu(alloc->zone_bm);
		mas_bm = le16_to_cpu(alloc->mas_bm);
		for (zone = 0; zone < UWB_NUM_ZONES; zone++)   {
			zone_mask = 1 << zone;
			if (zone_bm & zone_mask)
				uwb_drp_ie_single_zone_to_bm(bm, zone, mas_bm);
		}
	}
}

