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
typedef  int u32 ;
struct dm_buffer {int dummy; } ;
struct dm_block_validator {int (* check ) (struct dm_block_validator*,struct dm_block*,int) ;char* name; int /*<<< orphan*/  (* prepare_for_write ) (struct dm_block_validator*,struct dm_block*,int) ;} ;
struct dm_block_manager {void* bufio; int read_only; } ;
struct dm_block {int dummy; } ;
struct buffer_aux {int write_locked; int /*<<< orphan*/  lock; struct dm_block_validator* validator; } ;
struct block_device {int dummy; } ;
typedef  scalar_t__ dm_block_t ;

/* Variables and functions */
 int /*<<< orphan*/  DMERR_LIMIT (char*,char*,...) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPERM ; 
 struct dm_block_manager* ERR_PTR (int) ; 
 int EWOULDBLOCK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int bl_down_read (int /*<<< orphan*/ *) ; 
 int bl_down_read_nonblock (int /*<<< orphan*/ *) ; 
 int bl_down_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bl_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bl_up_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bl_up_write (int /*<<< orphan*/ *) ; 
 int crc32c (int,void const*,size_t) ; 
 void* dm_bufio_client_create (struct block_device*,unsigned int,unsigned int,int,void (*) (struct dm_buffer*),void (*) (struct dm_buffer*)) ; 
 int /*<<< orphan*/  dm_bufio_client_destroy (void*) ; 
 void* dm_bufio_get (void*,scalar_t__,struct dm_buffer**) ; 
 struct buffer_aux* dm_bufio_get_aux_data (struct dm_buffer*) ; 
 void* dm_bufio_get_block_data (struct dm_buffer*) ; 
 scalar_t__ dm_bufio_get_block_number (struct dm_buffer*) ; 
 int dm_bufio_get_block_size (void*) ; 
 void* dm_bufio_get_client (struct dm_buffer*) ; 
 scalar_t__ dm_bufio_get_device_size (void*) ; 
 int /*<<< orphan*/  dm_bufio_mark_buffer_dirty (struct dm_buffer*) ; 
 void* dm_bufio_new (void*,scalar_t__,struct dm_buffer**) ; 
 int /*<<< orphan*/  dm_bufio_prefetch (void*,scalar_t__,int) ; 
 void* dm_bufio_read (void*,scalar_t__,struct dm_buffer**) ; 
 int /*<<< orphan*/  dm_bufio_release (struct dm_buffer*) ; 
 int dm_bufio_write_dirty_buffers (void*) ; 
 int /*<<< orphan*/  kfree (struct dm_block_manager*) ; 
 struct dm_block_manager* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  report_recursive_bug (scalar_t__,int) ; 
 int /*<<< orphan*/  stub1 (struct dm_block_validator*,struct dm_block*,int) ; 
 int stub2 (struct dm_block_validator*,struct dm_block*,int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline unsigned dm_hash_block(dm_block_t b, unsigned hash_mask)
{
	const unsigned BIG_PRIME = 4294967291UL;

	return (((unsigned) b) * BIG_PRIME) & hash_mask;
}

__attribute__((used)) static struct dm_buffer *to_buffer(struct dm_block *b)
{
	return (struct dm_buffer *) b;
}

dm_block_t dm_block_location(struct dm_block *b)
{
	return dm_bufio_get_block_number(to_buffer(b));
}

void *dm_block_data(struct dm_block *b)
{
	return dm_bufio_get_block_data(to_buffer(b));
}

__attribute__((used)) static void dm_block_manager_alloc_callback(struct dm_buffer *buf)
{
	struct buffer_aux *aux = dm_bufio_get_aux_data(buf);
	aux->validator = NULL;
	bl_init(&aux->lock);
}

__attribute__((used)) static void dm_block_manager_write_callback(struct dm_buffer *buf)
{
	struct buffer_aux *aux = dm_bufio_get_aux_data(buf);
	if (aux->validator) {
		aux->validator->prepare_for_write(aux->validator, (struct dm_block *) buf,
			 dm_bufio_get_block_size(dm_bufio_get_client(buf)));
	}
}

struct dm_block_manager *dm_block_manager_create(struct block_device *bdev,
						 unsigned block_size,
						 unsigned max_held_per_thread)
{
	int r;
	struct dm_block_manager *bm;

	bm = kmalloc(sizeof(*bm), GFP_KERNEL);
	if (!bm) {
		r = -ENOMEM;
		goto bad;
	}

	bm->bufio = dm_bufio_client_create(bdev, block_size, max_held_per_thread,
					   sizeof(struct buffer_aux),
					   dm_block_manager_alloc_callback,
					   dm_block_manager_write_callback);
	if (IS_ERR(bm->bufio)) {
		r = PTR_ERR(bm->bufio);
		kfree(bm);
		goto bad;
	}

	bm->read_only = false;

	return bm;

bad:
	return ERR_PTR(r);
}

void dm_block_manager_destroy(struct dm_block_manager *bm)
{
	dm_bufio_client_destroy(bm->bufio);
	kfree(bm);
}

unsigned dm_bm_block_size(struct dm_block_manager *bm)
{
	return dm_bufio_get_block_size(bm->bufio);
}

dm_block_t dm_bm_nr_blocks(struct dm_block_manager *bm)
{
	return dm_bufio_get_device_size(bm->bufio);
}

__attribute__((used)) static int dm_bm_validate_buffer(struct dm_block_manager *bm,
				 struct dm_buffer *buf,
				 struct buffer_aux *aux,
				 struct dm_block_validator *v)
{
	if (unlikely(!aux->validator)) {
		int r;
		if (!v)
			return 0;
		r = v->check(v, (struct dm_block *) buf, dm_bufio_get_block_size(bm->bufio));
		if (unlikely(r)) {
			DMERR_LIMIT("%s validator check failed for block %llu", v->name,
				    (unsigned long long) dm_bufio_get_block_number(buf));
			return r;
		}
		aux->validator = v;
	} else {
		if (unlikely(aux->validator != v)) {
			DMERR_LIMIT("validator mismatch (old=%s vs new=%s) for block %llu",
				    aux->validator->name, v ? v->name : "NULL",
				    (unsigned long long) dm_bufio_get_block_number(buf));
			return -EINVAL;
		}
	}

	return 0;
}

int dm_bm_read_lock(struct dm_block_manager *bm, dm_block_t b,
		    struct dm_block_validator *v,
		    struct dm_block **result)
{
	struct buffer_aux *aux;
	void *p;
	int r;

	p = dm_bufio_read(bm->bufio, b, (struct dm_buffer **) result);
	if (unlikely(IS_ERR(p)))
		return PTR_ERR(p);

	aux = dm_bufio_get_aux_data(to_buffer(*result));
	r = bl_down_read(&aux->lock);
	if (unlikely(r)) {
		dm_bufio_release(to_buffer(*result));
		report_recursive_bug(b, r);
		return r;
	}

	aux->write_locked = 0;

	r = dm_bm_validate_buffer(bm, to_buffer(*result), aux, v);
	if (unlikely(r)) {
		bl_up_read(&aux->lock);
		dm_bufio_release(to_buffer(*result));
		return r;
	}

	return 0;
}

int dm_bm_write_lock(struct dm_block_manager *bm,
		     dm_block_t b, struct dm_block_validator *v,
		     struct dm_block **result)
{
	struct buffer_aux *aux;
	void *p;
	int r;

	if (bm->read_only)
		return -EPERM;

	p = dm_bufio_read(bm->bufio, b, (struct dm_buffer **) result);
	if (unlikely(IS_ERR(p)))
		return PTR_ERR(p);

	aux = dm_bufio_get_aux_data(to_buffer(*result));
	r = bl_down_write(&aux->lock);
	if (r) {
		dm_bufio_release(to_buffer(*result));
		report_recursive_bug(b, r);
		return r;
	}

	aux->write_locked = 1;

	r = dm_bm_validate_buffer(bm, to_buffer(*result), aux, v);
	if (unlikely(r)) {
		bl_up_write(&aux->lock);
		dm_bufio_release(to_buffer(*result));
		return r;
	}

	return 0;
}

int dm_bm_read_try_lock(struct dm_block_manager *bm,
			dm_block_t b, struct dm_block_validator *v,
			struct dm_block **result)
{
	struct buffer_aux *aux;
	void *p;
	int r;

	p = dm_bufio_get(bm->bufio, b, (struct dm_buffer **) result);
	if (unlikely(IS_ERR(p)))
		return PTR_ERR(p);
	if (unlikely(!p))
		return -EWOULDBLOCK;

	aux = dm_bufio_get_aux_data(to_buffer(*result));
	r = bl_down_read_nonblock(&aux->lock);
	if (r < 0) {
		dm_bufio_release(to_buffer(*result));
		report_recursive_bug(b, r);
		return r;
	}
	aux->write_locked = 0;

	r = dm_bm_validate_buffer(bm, to_buffer(*result), aux, v);
	if (unlikely(r)) {
		bl_up_read(&aux->lock);
		dm_bufio_release(to_buffer(*result));
		return r;
	}

	return 0;
}

int dm_bm_write_lock_zero(struct dm_block_manager *bm,
			  dm_block_t b, struct dm_block_validator *v,
			  struct dm_block **result)
{
	int r;
	struct buffer_aux *aux;
	void *p;

	if (bm->read_only)
		return -EPERM;

	p = dm_bufio_new(bm->bufio, b, (struct dm_buffer **) result);
	if (unlikely(IS_ERR(p)))
		return PTR_ERR(p);

	memset(p, 0, dm_bm_block_size(bm));

	aux = dm_bufio_get_aux_data(to_buffer(*result));
	r = bl_down_write(&aux->lock);
	if (r) {
		dm_bufio_release(to_buffer(*result));
		return r;
	}

	aux->write_locked = 1;
	aux->validator = v;

	return 0;
}

void dm_bm_unlock(struct dm_block *b)
{
	struct buffer_aux *aux;
	aux = dm_bufio_get_aux_data(to_buffer(b));

	if (aux->write_locked) {
		dm_bufio_mark_buffer_dirty(to_buffer(b));
		bl_up_write(&aux->lock);
	} else
		bl_up_read(&aux->lock);

	dm_bufio_release(to_buffer(b));
}

int dm_bm_flush(struct dm_block_manager *bm)
{
	if (bm->read_only)
		return -EPERM;

	return dm_bufio_write_dirty_buffers(bm->bufio);
}

void dm_bm_prefetch(struct dm_block_manager *bm, dm_block_t b)
{
	dm_bufio_prefetch(bm->bufio, b, 1);
}

bool dm_bm_is_read_only(struct dm_block_manager *bm)
{
	return bm->read_only;
}

void dm_bm_set_read_only(struct dm_block_manager *bm)
{
	bm->read_only = true;
}

void dm_bm_set_read_write(struct dm_block_manager *bm)
{
	bm->read_only = false;
}

u32 dm_bm_checksum(const void *data, size_t len, u32 init_xor)
{
	return crc32c(~(u32) 0, data, len) ^ init_xor;
}

