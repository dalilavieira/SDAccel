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
typedef  scalar_t__ uint16_t ;
typedef  int /*<<< orphan*/  new_id ;
typedef  scalar_t__ bitstr_t ;

/* Variables and functions */
 int ARRAY_SIZE ; 
 int /*<<< orphan*/  M_TEMP ; 
 int M_WAITOK ; 
 int M_ZERO ; 
 int /*<<< orphan*/  VERIFY (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _CASSERT (int) ; 
 int /*<<< orphan*/  _FREE (scalar_t__*,int /*<<< orphan*/ ) ; 
 scalar_t__ _MALLOC (int,int /*<<< orphan*/ ,int) ; 
 size_t array_ptr ; 
 int /*<<< orphan*/  bitstr_clear (scalar_t__*,scalar_t__) ; 
 int /*<<< orphan*/  bitstr_set (scalar_t__*,scalar_t__) ; 
 int bitstr_size (int) ; 
 scalar_t__ bitstr_test (scalar_t__*,scalar_t__) ; 
 scalar_t__ htons (int /*<<< orphan*/ ) ; 
 scalar_t__* id_array ; 
 scalar_t__* id_bits ; 
 int /*<<< orphan*/  ip_id ; 
 scalar_t__ ip_use_randomid ; 
 int /*<<< orphan*/  ipid_lock ; 
 int /*<<< orphan*/  ipid_lock_attr ; 
 int /*<<< orphan*/  ipid_lock_grp ; 
 int /*<<< orphan*/  ipid_lock_grp_attr ; 
 int /*<<< orphan*/  lck_attr_alloc_init () ; 
 int /*<<< orphan*/  lck_grp_alloc_init (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_grp_attr_alloc_init () ; 
 int /*<<< orphan*/  lck_mtx_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_mtx_lock_spin (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  random_id_collisions ; 
 scalar_t__ random_id_statistics ; 
 int /*<<< orphan*/  random_id_total ; 
 int /*<<< orphan*/  read_random (scalar_t__*,int) ; 

void
ip_initid(void)
{
	VERIFY(id_array == NULL);
	VERIFY(id_bits == NULL);

	_CASSERT(ARRAY_SIZE >= 512 && ARRAY_SIZE <= 32768);

	ipid_lock_grp_attr  = lck_grp_attr_alloc_init();
	ipid_lock_grp = lck_grp_alloc_init("ipid", ipid_lock_grp_attr);
	ipid_lock_attr = lck_attr_alloc_init();
	lck_mtx_init(&ipid_lock, ipid_lock_grp, ipid_lock_attr);

	id_array = (uint16_t *)_MALLOC(ARRAY_SIZE * sizeof (uint16_t),
	    M_TEMP, M_WAITOK | M_ZERO);
	id_bits = (bitstr_t *)_MALLOC(bitstr_size(65536), M_TEMP,
	    M_WAITOK | M_ZERO);
	if (id_array == NULL || id_bits == NULL) {
		/* Just in case; neither or both. */
		if (id_array != NULL) {
			_FREE(id_array, M_TEMP);
			id_array = NULL;
		}
		if (id_bits != NULL) {
			_FREE(id_bits, M_TEMP);
			id_bits = NULL;
		}
	}
}

uint16_t
ip_randomid(void)
{
	uint16_t new_id;

	/*
	 * If net.inet.ip.random_id is disabled, revert to incrementing ip_id.
	 * Given that we don't allow the size of the array to change, accessing
	 * id_array and id_bits prior to acquiring the lock below is safe.
	 */
	if (id_array == NULL || ip_use_randomid == 0)
		return (htons(ip_id++));

	/*
	 * To avoid a conflict with the zeros that the array is initially
	 * filled with, we never hand out an id of zero.  bit_test() below
	 * uses single memory access, therefore no lock is needed.
	 */
	new_id = 0;
	do {
		if (random_id_statistics && new_id != 0)
			random_id_collisions++;
		read_random(&new_id, sizeof (new_id));
	} while (bitstr_test(id_bits, new_id) || new_id == 0);

	/*
	 * These require serialization to maintain correctness.
	 */
	lck_mtx_lock_spin(&ipid_lock);
	bitstr_clear(id_bits, id_array[array_ptr]);
	bitstr_set(id_bits, new_id);
	id_array[array_ptr] = new_id;
	if (++array_ptr == ARRAY_SIZE)
		array_ptr = 0;
	lck_mtx_unlock(&ipid_lock);

	if (random_id_statistics)
		random_id_total++;

	return (new_id);
}

