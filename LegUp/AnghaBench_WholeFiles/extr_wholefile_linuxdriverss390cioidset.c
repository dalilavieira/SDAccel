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
typedef  int /*<<< orphan*/  u8 ;
struct subchannel_id {int ssid; int sch_no; } ;
struct idset {int num_ssid; int num_id; int /*<<< orphan*/  bitmap; } ;
struct channel_subsystem {int dummy; } ;

/* Variables and functions */
 int BITS_TO_LONGS (int) ; 
 int __MAX_SUBCHANNEL ; 
 int /*<<< orphan*/  bitmap_clear (int /*<<< orphan*/ ,int,int) ; 
 int bitmap_empty (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bitmap_or (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct channel_subsystem** channel_subsystems ; 
 int /*<<< orphan*/  clear_bit (int,int /*<<< orphan*/ ) ; 
 int find_first_bit (int /*<<< orphan*/ ,int) ; 
 int max_ssid ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int,unsigned long) ; 
 int min (int,int) ; 
 int /*<<< orphan*/  set_bit (int,int /*<<< orphan*/ ) ; 
 int test_bit (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vfree (struct idset*) ; 
 struct idset* vmalloc (unsigned long) ; 

__attribute__((used)) static inline int scm_update_information(void) { return 0; }

__attribute__((used)) static inline int scm_process_availability_information(void) { return 0; }

__attribute__((used)) static inline void cio_register_early_subchannels(void) {}

__attribute__((used)) static inline struct channel_subsystem *css_by_id(u8 cssid)
{
	return channel_subsystems[0];
}

__attribute__((used)) static inline unsigned long bitmap_size(int num_ssid, int num_id)
{
	return BITS_TO_LONGS(num_ssid * num_id) * sizeof(unsigned long);
}

__attribute__((used)) static struct idset *idset_new(int num_ssid, int num_id)
{
	struct idset *set;

	set = vmalloc(sizeof(struct idset) + bitmap_size(num_ssid, num_id));
	if (set) {
		set->num_ssid = num_ssid;
		set->num_id = num_id;
		memset(set->bitmap, 0, bitmap_size(num_ssid, num_id));
	}
	return set;
}

void idset_free(struct idset *set)
{
	vfree(set);
}

void idset_fill(struct idset *set)
{
	memset(set->bitmap, 0xff, bitmap_size(set->num_ssid, set->num_id));
}

__attribute__((used)) static inline void idset_add(struct idset *set, int ssid, int id)
{
	set_bit(ssid * set->num_id + id, set->bitmap);
}

__attribute__((used)) static inline void idset_del(struct idset *set, int ssid, int id)
{
	clear_bit(ssid * set->num_id + id, set->bitmap);
}

__attribute__((used)) static inline int idset_contains(struct idset *set, int ssid, int id)
{
	return test_bit(ssid * set->num_id + id, set->bitmap);
}

__attribute__((used)) static inline int idset_get_first(struct idset *set, int *ssid, int *id)
{
	int bitnum;

	bitnum = find_first_bit(set->bitmap, set->num_ssid * set->num_id);
	if (bitnum >= set->num_ssid * set->num_id)
		return 0;
	*ssid = bitnum / set->num_id;
	*id = bitnum % set->num_id;
	return 1;
}

struct idset *idset_sch_new(void)
{
	return idset_new(max_ssid + 1, __MAX_SUBCHANNEL + 1);
}

void idset_sch_add(struct idset *set, struct subchannel_id schid)
{
	idset_add(set, schid.ssid, schid.sch_no);
}

void idset_sch_del(struct idset *set, struct subchannel_id schid)
{
	idset_del(set, schid.ssid, schid.sch_no);
}

void idset_sch_del_subseq(struct idset *set, struct subchannel_id schid)
{
	int pos = schid.ssid * set->num_id + schid.sch_no;

	bitmap_clear(set->bitmap, pos, set->num_id - schid.sch_no);
}

int idset_sch_contains(struct idset *set, struct subchannel_id schid)
{
	return idset_contains(set, schid.ssid, schid.sch_no);
}

int idset_is_empty(struct idset *set)
{
	return bitmap_empty(set->bitmap, set->num_ssid * set->num_id);
}

void idset_add_set(struct idset *to, struct idset *from)
{
	int len = min(to->num_ssid * to->num_id, from->num_ssid * from->num_id);

	bitmap_or(to->bitmap, to->bitmap, from->bitmap, len);
}

