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
struct label {int l_flags; TYPE_1__* l_perpolicy; } ;
struct TYPE_2__ {void* l_ptr; } ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  KASSERT (int /*<<< orphan*/ ,char*) ; 
 int MAC_FLAG_INITIALIZED ; 
 int MAC_NOWAIT ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  Z_CALLERACCT ; 
 int /*<<< orphan*/  Z_EXHAUST ; 
 int /*<<< orphan*/  Z_EXPAND ; 
 int /*<<< orphan*/  bzero (struct label*,int) ; 
 int /*<<< orphan*/  panic (char*) ; 
 scalar_t__ zalloc (int /*<<< orphan*/ ) ; 
 scalar_t__ zalloc_noblock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zfree (int /*<<< orphan*/ ,struct label*) ; 
 int /*<<< orphan*/  zinit (int,int,int,char*) ; 
 int /*<<< orphan*/  zone_change (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zone_label ; 

void
mac_labelzone_init(void)
{

	zone_label = zinit(sizeof(struct label),
	    8192 * sizeof(struct label),
	    sizeof(struct label), "MAC Labels");
	zone_change(zone_label, Z_EXPAND, TRUE);
	zone_change(zone_label, Z_EXHAUST, FALSE);
	zone_change(zone_label, Z_CALLERACCT, FALSE);
}

struct label *
mac_labelzone_alloc(int flags)
{
	struct label *l;

	if (flags & MAC_NOWAIT) 
		l = (struct label *) zalloc_noblock(zone_label);
	else
		l = (struct label *) zalloc(zone_label);
	if (l == NULL)
		return (NULL);

	bzero(l, sizeof(struct label));
	l->l_flags = MAC_FLAG_INITIALIZED;
	return (l);
}

void
mac_labelzone_free(struct label *l)
{

	if (l == NULL)
		panic("Free of NULL MAC label\n");

	if ((l->l_flags & MAC_FLAG_INITIALIZED) == 0)
		panic("Free of uninitialized label\n");
	bzero(l, sizeof(struct label));
	zfree(zone_label, l);
}

intptr_t
mac_label_get(struct label *l, int slot)
{
	KASSERT(l != NULL, ("mac_label_get: NULL label"));

	return ((intptr_t) (l->l_perpolicy[slot].l_ptr));
}

void
mac_label_set(struct label *l, int slot, intptr_t v)
{
	KASSERT(l != NULL, ("mac_label_set: NULL label"));

	l->l_perpolicy[slot].l_ptr = (void *) v;
}

