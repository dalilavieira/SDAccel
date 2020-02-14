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
struct transient_c {scalar_t__ next_free; } ;
struct dm_exception_store {scalar_t__ chunk_shift; scalar_t__ chunk_size; struct transient_c* context; int /*<<< orphan*/  snap; } ;
struct dm_exception {scalar_t__ new_chunk; } ;
struct block_device {int /*<<< orphan*/  bd_inode; } ;
typedef  int status_type_t ;
typedef  scalar_t__ sector_t ;
typedef  scalar_t__ chunk_t ;
struct TYPE_2__ {struct block_device* bdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMEMIT (char*,unsigned long long) ; 
 int /*<<< orphan*/  DMWARN (char*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ SECTOR_SHIFT ; 
#define  STATUSTYPE_INFO 129 
#define  STATUSTYPE_TABLE 128 
 int /*<<< orphan*/  _transient_compat_type ; 
 int /*<<< orphan*/  _transient_type ; 
 int dm_exception_store_type_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dm_exception_store_type_unregister (int /*<<< orphan*/ *) ; 
 TYPE_1__* dm_snap_cow (int /*<<< orphan*/ ) ; 
 scalar_t__ i_size_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct transient_c*) ; 
 struct transient_c* kmalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline chunk_t dm_chunk_number(chunk_t chunk)
{
	return chunk;
}

__attribute__((used)) static inline unsigned dm_consecutive_chunk_count(struct dm_exception *e)
{
	return 0;
}

__attribute__((used)) static inline void dm_consecutive_chunk_count_inc(struct dm_exception *e)
{
}

__attribute__((used)) static inline void dm_consecutive_chunk_count_dec(struct dm_exception *e)
{
}

__attribute__((used)) static inline sector_t get_dev_size(struct block_device *bdev)
{
	return i_size_read(bdev->bd_inode) >> SECTOR_SHIFT;
}

__attribute__((used)) static inline chunk_t sector_to_chunk(struct dm_exception_store *store,
				      sector_t sector)
{
	return sector >> store->chunk_shift;
}

__attribute__((used)) static void transient_dtr(struct dm_exception_store *store)
{
	kfree(store->context);
}

__attribute__((used)) static int transient_read_metadata(struct dm_exception_store *store,
				   int (*callback)(void *callback_context,
						   chunk_t old, chunk_t new),
				   void *callback_context)
{
	return 0;
}

__attribute__((used)) static int transient_prepare_exception(struct dm_exception_store *store,
				       struct dm_exception *e)
{
	struct transient_c *tc = store->context;
	sector_t size = get_dev_size(dm_snap_cow(store->snap)->bdev);

	if (size < (tc->next_free + store->chunk_size))
		return -1;

	e->new_chunk = sector_to_chunk(store, tc->next_free);
	tc->next_free += store->chunk_size;

	return 0;
}

__attribute__((used)) static void transient_commit_exception(struct dm_exception_store *store,
				       struct dm_exception *e, int valid,
				       void (*callback) (void *, int success),
				       void *callback_context)
{
	/* Just succeed */
	callback(callback_context, valid);
}

__attribute__((used)) static void transient_usage(struct dm_exception_store *store,
			    sector_t *total_sectors,
			    sector_t *sectors_allocated,
			    sector_t *metadata_sectors)
{
	*sectors_allocated = ((struct transient_c *) store->context)->next_free;
	*total_sectors = get_dev_size(dm_snap_cow(store->snap)->bdev);
	*metadata_sectors = 0;
}

__attribute__((used)) static int transient_ctr(struct dm_exception_store *store, char *options)
{
	struct transient_c *tc;

	tc = kmalloc(sizeof(struct transient_c), GFP_KERNEL);
	if (!tc)
		return -ENOMEM;

	tc->next_free = 0;
	store->context = tc;

	return 0;
}

__attribute__((used)) static unsigned transient_status(struct dm_exception_store *store,
				 status_type_t status, char *result,
				 unsigned maxlen)
{
	unsigned sz = 0;

	switch (status) {
	case STATUSTYPE_INFO:
		break;
	case STATUSTYPE_TABLE:
		DMEMIT(" N %llu", (unsigned long long)store->chunk_size);
	}

	return sz;
}

int dm_transient_snapshot_init(void)
{
	int r;

	r = dm_exception_store_type_register(&_transient_type);
	if (r) {
		DMWARN("Unable to register transient exception store type");
		return r;
	}

	r = dm_exception_store_type_register(&_transient_compat_type);
	if (r) {
		DMWARN("Unable to register old-style transient "
		       "exception store type");
		dm_exception_store_type_unregister(&_transient_type);
		return r;
	}

	return r;
}

void dm_transient_snapshot_exit(void)
{
	dm_exception_store_type_unregister(&_transient_type);
	dm_exception_store_type_unregister(&_transient_compat_type);
}

