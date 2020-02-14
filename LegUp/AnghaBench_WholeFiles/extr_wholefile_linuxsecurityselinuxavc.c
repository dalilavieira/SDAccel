#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct selinux_state {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  lru_hint; int /*<<< orphan*/  active_nodes; int /*<<< orphan*/ * slots_lock; int /*<<< orphan*/ * slots; } ;
struct selinux_avc {unsigned int avc_cache_threshold; TYPE_1__ avc_cache; } ;
struct audit_buffer {int dummy; } ;
typedef  int /*<<< orphan*/  av ;
struct TYPE_5__ {char** perms; char* name; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int AVC_CACHE_SLOTS ; 
 unsigned int AVC_DEF_CACHE_THRESHOLD ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  INIT_HLIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  audit_log_format (struct audit_buffer*,char*,...) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 TYPE_2__* secclass_map ; 
 int security_sid_to_context (struct selinux_state*,int,char**,int*) ; 
 struct selinux_avc selinux_avc ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

void selinux_avc_init(struct selinux_avc **avc)
{
	int i;

	selinux_avc.avc_cache_threshold = AVC_DEF_CACHE_THRESHOLD;
	for (i = 0; i < AVC_CACHE_SLOTS; i++) {
		INIT_HLIST_HEAD(&selinux_avc.avc_cache.slots[i]);
		spin_lock_init(&selinux_avc.avc_cache.slots_lock[i]);
	}
	atomic_set(&selinux_avc.avc_cache.active_nodes, 0);
	atomic_set(&selinux_avc.avc_cache.lru_hint, 0);
	*avc = &selinux_avc;
}

unsigned int avc_get_cache_threshold(struct selinux_avc *avc)
{
	return avc->avc_cache_threshold;
}

void avc_set_cache_threshold(struct selinux_avc *avc,
			     unsigned int cache_threshold)
{
	avc->avc_cache_threshold = cache_threshold;
}

__attribute__((used)) static inline int avc_hash(u32 ssid, u32 tsid, u16 tclass)
{
	return (ssid ^ (tsid<<2) ^ (tclass<<4)) & (AVC_CACHE_SLOTS - 1);
}

__attribute__((used)) static void avc_dump_av(struct audit_buffer *ab, u16 tclass, u32 av)
{
	const char **perms;
	int i, perm;

	if (av == 0) {
		audit_log_format(ab, " null");
		return;
	}

	BUG_ON(!tclass || tclass >= ARRAY_SIZE(secclass_map));
	perms = secclass_map[tclass-1].perms;

	audit_log_format(ab, " {");
	i = 0;
	perm = 1;
	while (i < (sizeof(av) * 8)) {
		if ((perm & av) && perms[i]) {
			audit_log_format(ab, " %s", perms[i]);
			av &= ~perm;
		}
		i++;
		perm <<= 1;
	}

	if (av)
		audit_log_format(ab, " 0x%x", av);

	audit_log_format(ab, " }");
}

__attribute__((used)) static void avc_dump_query(struct audit_buffer *ab, struct selinux_state *state,
			   u32 ssid, u32 tsid, u16 tclass)
{
	int rc;
	char *scontext;
	u32 scontext_len;

	rc = security_sid_to_context(state, ssid, &scontext, &scontext_len);
	if (rc)
		audit_log_format(ab, "ssid=%d", ssid);
	else {
		audit_log_format(ab, "scontext=%s", scontext);
		kfree(scontext);
	}

	rc = security_sid_to_context(state, tsid, &scontext, &scontext_len);
	if (rc)
		audit_log_format(ab, " tsid=%d", tsid);
	else {
		audit_log_format(ab, " tcontext=%s", scontext);
		kfree(scontext);
	}

	BUG_ON(!tclass || tclass >= ARRAY_SIZE(secclass_map));
	audit_log_format(ab, " tclass=%s", secclass_map[tclass-1].name);
}

