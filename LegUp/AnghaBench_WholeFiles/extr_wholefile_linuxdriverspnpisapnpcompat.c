#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {struct list_head* next; } ;
struct TYPE_5__ {struct list_head* next; } ;
struct pnp_dev {int /*<<< orphan*/  id; struct pnp_card* card; TYPE_3__ card_list; TYPE_2__ global_list; } ;
struct list_head {struct list_head* next; } ;
struct TYPE_4__ {struct list_head* next; } ;
struct pnp_card {struct list_head devices; int /*<<< orphan*/  id; TYPE_1__ global_list; } ;

/* Variables and functions */
 unsigned short ISAPNP_ANY_ID ; 
 struct pnp_dev* card_to_pnp_dev (struct list_head*) ; 
 scalar_t__ compare_pnp_id (int /*<<< orphan*/ ,char*) ; 
 struct pnp_card* global_to_pnp_card (struct list_head*) ; 
 struct pnp_dev* global_to_pnp_dev (struct list_head*) ; 
 scalar_t__ memcmp (char*,char*,int) ; 
 struct list_head pnp_cards ; 
 struct list_head pnp_global ; 
 int /*<<< orphan*/  sprintf (char*,char*,char,char,char,unsigned short,unsigned short,unsigned short,unsigned short) ; 

__attribute__((used)) static void pnp_convert_id(char *buf, unsigned short vendor,
			   unsigned short device)
{
	sprintf(buf, "%c%c%c%x%x%x%x",
		'A' + ((vendor >> 2) & 0x3f) - 1,
		'A' + (((vendor & 3) << 3) | ((vendor >> 13) & 7)) - 1,
		'A' + ((vendor >> 8) & 0x1f) - 1,
		(device >> 4) & 0x0f, device & 0x0f,
		(device >> 12) & 0x0f, (device >> 8) & 0x0f);
}

struct pnp_card *pnp_find_card(unsigned short vendor, unsigned short device,
			       struct pnp_card *from)
{
	char id[8];
	char any[8];
	struct list_head *list;

	pnp_convert_id(id, vendor, device);
	pnp_convert_id(any, ISAPNP_ANY_ID, ISAPNP_ANY_ID);

	list = from ? from->global_list.next : pnp_cards.next;

	while (list != &pnp_cards) {
		struct pnp_card *card = global_to_pnp_card(list);

		if (compare_pnp_id(card->id, id) || (memcmp(id, any, 7) == 0))
			return card;
		list = list->next;
	}
	return NULL;
}

struct pnp_dev *pnp_find_dev(struct pnp_card *card, unsigned short vendor,
			     unsigned short function, struct pnp_dev *from)
{
	char id[8];
	char any[8];

	pnp_convert_id(id, vendor, function);
	pnp_convert_id(any, ISAPNP_ANY_ID, ISAPNP_ANY_ID);
	if (card == NULL) {	/* look for a logical device from all cards */
		struct list_head *list;

		list = pnp_global.next;
		if (from)
			list = from->global_list.next;

		while (list != &pnp_global) {
			struct pnp_dev *dev = global_to_pnp_dev(list);

			if (compare_pnp_id(dev->id, id) ||
			    (memcmp(id, any, 7) == 0))
				return dev;
			list = list->next;
		}
	} else {
		struct list_head *list;

		list = card->devices.next;
		if (from) {
			list = from->card_list.next;
			if (from->card != card)	/* something is wrong */
				return NULL;
		}
		while (list != &card->devices) {
			struct pnp_dev *dev = card_to_pnp_dev(list);

			if (compare_pnp_id(dev->id, id))
				return dev;
			list = list->next;
		}
	}
	return NULL;
}

