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
struct seq_file {int dummy; } ;
struct cred {int dummy; } ;
struct cachefiles_cache {int /*<<< orphan*/  cache_cred; int /*<<< orphan*/  daemon_pollwq; int /*<<< orphan*/  flags; } ;
typedef  int loff_t ;

/* Variables and functions */
 int /*<<< orphan*/  CACHEFILES_STATE_CHANGED ; 
 unsigned long HZ ; 
 unsigned int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * cachefiles_create_histogram ; 
 int /*<<< orphan*/ * cachefiles_lookup_histogram ; 
 int /*<<< orphan*/ * cachefiles_mkdir_histogram ; 
 struct cred* override_creds (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  revert_creds (struct cred const*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,unsigned long,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
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

__attribute__((used)) static int cachefiles_histogram_show(struct seq_file *m, void *v)
{
	unsigned long index;
	unsigned x, y, z, t;

	switch ((unsigned long) v) {
	case 1:
		seq_puts(m, "JIFS  SECS  LOOKUPS   MKDIRS    CREATES\n");
		return 0;
	case 2:
		seq_puts(m, "===== ===== ========= ========= =========\n");
		return 0;
	default:
		index = (unsigned long) v - 3;
		x = atomic_read(&cachefiles_lookup_histogram[index]);
		y = atomic_read(&cachefiles_mkdir_histogram[index]);
		z = atomic_read(&cachefiles_create_histogram[index]);
		if (x == 0 && y == 0 && z == 0)
			return 0;

		t = (index * 1000) / HZ;

		seq_printf(m, "%4lu  0.%03u %9u %9u %9u\n", index, t, x, y, z);
		return 0;
	}
}

__attribute__((used)) static void *cachefiles_histogram_start(struct seq_file *m, loff_t *_pos)
{
	if ((unsigned long long)*_pos >= HZ + 2)
		return NULL;
	if (*_pos == 0)
		*_pos = 1;
	return (void *)(unsigned long) *_pos;
}

__attribute__((used)) static void *cachefiles_histogram_next(struct seq_file *m, void *v, loff_t *pos)
{
	(*pos)++;
	return (unsigned long long)*pos > HZ + 2 ?
		NULL : (void *)(unsigned long) *pos;
}

__attribute__((used)) static void cachefiles_histogram_stop(struct seq_file *m, void *v)
{
}

