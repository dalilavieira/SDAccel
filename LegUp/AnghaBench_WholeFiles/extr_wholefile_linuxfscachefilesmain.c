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
struct cred {int dummy; } ;
struct cachefiles_object {int /*<<< orphan*/  work_lock; } ;
struct cachefiles_cache {int /*<<< orphan*/  cache_cred; int /*<<< orphan*/  daemon_pollwq; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  CACHEFILES_STATE_CHANGED ; 
 int /*<<< orphan*/  memset (struct cachefiles_object*,int /*<<< orphan*/ ,int) ; 
 struct cred* override_creds (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  revert_creds (struct cred const*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wake_up_all (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void cachefiles_state_changed(struct cachefiles_cache *cache)
{
	set_bit(CACHEFILES_STATE_CHANGED, &cache->flags);
	wake_up_all(&cache->daemon_pollwq);
}

__attribute__((used)) static inline void cachefiles_begin_secure(struct cachefiles_cache *cache,
					   const struct cred **_saved_cred)
{
	*_saved_cred = override_creds(cache->cache_cred);
}

__attribute__((used)) static inline void cachefiles_end_secure(struct cachefiles_cache *cache,
					 const struct cred *saved_cred)
{
	revert_creds(saved_cred);
}

__attribute__((used)) static void cachefiles_object_init_once(void *_object)
{
	struct cachefiles_object *object = _object;

	memset(object, 0, sizeof(*object));
	spin_lock_init(&object->work_lock);
}

