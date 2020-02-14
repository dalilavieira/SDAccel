#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_15__ ;

/* Type definitions */
typedef  TYPE_1__* zone_t ;
typedef  int vm_size_t ;
typedef  uintptr_t vm_offset_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct zone_cache {int zcc_depot_index; struct zcc_magazine** zcc_depot_list; int /*<<< orphan*/  zcc_depot_lock; struct zcc_per_cpu_cache* zcc_per_cpu_caches; } ;
struct zcc_per_cpu_cache {struct zcc_magazine* current; struct zcc_magazine* previous; } ;
struct zcc_magazine {scalar_t__ zcc_magazine_index; int zcc_magazine_capacity; void** zcc_elements; } ;
struct TYPE_17__ {int cpu_cache_enable_when_ready; int cpu_cache_enabled; uintptr_t elem_size; struct zone_cache* zcache; } ;
struct TYPE_16__ {int cpu_id; } ;

/* Variables and functions */
 int DEFAULT_DEPOT_SIZE ; 
 int DEFAULT_MAGAZINE_SIZE ; 
 int FALSE ; 
 int /*<<< orphan*/  LCK_ATTR_NULL ; 
 int /*<<< orphan*/  LCK_GRP_ATTR_NULL ; 
 int MAX_CPUS ; 
 int /*<<< orphan*/  PE_parse_boot_argn (char*,int*,int) ; 
 int TRUE ; 
 int ZCACHE_DEPOT_INVALID ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_15__* current_processor () ; 
 int depot_element_count ; 
 int /*<<< orphan*/  disable_preemption () ; 
 scalar_t__ early_random () ; 
 int /*<<< orphan*/  enable_preemption () ; 
 scalar_t__ kalloc (int) ; 
 int /*<<< orphan*/  lck_grp_init (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_mtx_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_mtx_lock_spin_always (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lock_zone (TYPE_1__*) ; 
 int magazine_element_count ; 
 int /*<<< orphan*/ * magazine_zone ; 
 unsigned int num_zones ; 
 int /*<<< orphan*/  panic (char*,void*,void*,void*,void*) ; 
 int /*<<< orphan*/  unlock_zone (TYPE_1__*) ; 
 scalar_t__ zalloc (int /*<<< orphan*/ *) ; 
 void* zalloc_attempt (TYPE_1__*) ; 
 uintptr_t zcache_canary ; 
 void zcache_canary_add (TYPE_1__*,void*) ; 
 void zcache_canary_validate (TYPE_1__*,void*) ; 
 int zcache_depot_available (struct zone_cache*) ; 
 void zcache_init (TYPE_1__*) ; 
 int /*<<< orphan*/  zcache_locks_grp ; 
 void zcache_mag_depot_swap_for_alloc (struct zone_cache*,struct zcc_per_cpu_cache*) ; 
 void zcache_mag_depot_swap_for_free (struct zone_cache*,struct zcc_per_cpu_cache*) ; 
 void zcache_mag_drain (TYPE_1__*,struct zcc_magazine*) ; 
 int zcache_mag_fill (TYPE_1__*,struct zcc_magazine*) ; 
 int zcache_mag_has_elements (struct zcc_magazine*) ; 
 int zcache_mag_has_space (struct zcc_magazine*) ; 
 void zcache_mag_init (struct zcc_magazine*,int) ; 
 void* zcache_mag_pop (struct zcc_magazine*) ; 
 void zcache_mag_push (struct zcc_magazine*,void*) ; 
 void zcache_swap_magazines (struct zcc_magazine**,struct zcc_magazine**) ; 
 int /*<<< orphan*/  zfree_direct (TYPE_1__*,uintptr_t) ; 
 int /*<<< orphan*/ * zinit (int,int,int,char*) ; 
 TYPE_1__* zone_array ; 
 int zone_cache_ready ; 

bool zcache_ready(void){
	return zone_cache_ready;
}

void zcache_init_marked_zones(void){
	unsigned int i;
	for(i = 0; i < num_zones; i ++){
		if(zone_array[i].cpu_cache_enable_when_ready){
			zcache_init(&zone_array[i]);
			zone_array[i].cpu_cache_enable_when_ready = FALSE;
		}
	}
}

void zcache_bootstrap(void)
{
	/* use boot-arg for custom magazine size*/
	if (! PE_parse_boot_argn("zcc_magazine_element_count", &magazine_element_count, sizeof (uint16_t)))
		magazine_element_count = DEFAULT_MAGAZINE_SIZE;

	int magazine_size = sizeof(struct zcc_magazine) + magazine_element_count * sizeof(void *);

	magazine_zone = zinit(magazine_size, 100000 * magazine_size , magazine_size, "zcc_magazine_zone");

	assert(magazine_zone != NULL);

	/* use boot-arg for custom depot size*/
	if (! PE_parse_boot_argn("zcc_depot_element_count", &depot_element_count, sizeof (uint16_t)))
		depot_element_count = DEFAULT_DEPOT_SIZE;

	lck_grp_init(&zcache_locks_grp, "zcc_depot_lock", LCK_GRP_ATTR_NULL);

	/* Generate the canary value for zone caches */
	zcache_canary = (uintptr_t) early_random();

	zone_cache_ready = TRUE;

	zcache_init_marked_zones();
}

void zcache_init(zone_t zone)
 {
 	int 	i;			/* used as index in for loops */
	vm_size_t	total_size;		/* Used for allocating the zone_cache struct with the proper size of depot list */
	struct zone_cache *temp_cache;	/* Temporary variable to initialize a zone_cache before assigning to the specified zone */

	/* Allocate chunk of memory for all structs */
	total_size = sizeof(struct zone_cache) + (depot_element_count * sizeof(void *));
	
	temp_cache = (struct zone_cache *) kalloc(total_size);


 	/* Initialize a cache for every CPU */
 	for (i = 0; i < MAX_CPUS; i++) {
 		temp_cache->zcc_per_cpu_caches[i].current = (struct zcc_magazine *)zalloc(magazine_zone);
 		temp_cache->zcc_per_cpu_caches[i].previous = (struct zcc_magazine *)zalloc(magazine_zone);

 		assert(temp_cache->zcc_per_cpu_caches[i].current != NULL && temp_cache->zcc_per_cpu_caches[i].previous != NULL);

 		zcache_mag_init(temp_cache->zcc_per_cpu_caches[i].current, magazine_element_count);
 		zcache_mag_init(temp_cache->zcc_per_cpu_caches[i].previous, magazine_element_count);
 	}

 	/* Initialize the lock on the depot layer */
 	lck_mtx_init(&(temp_cache->zcc_depot_lock), &zcache_locks_grp, LCK_ATTR_NULL);

	/* Initialize empty magazines in the depot list */
	for (i = 0; i < depot_element_count; i++) {
		temp_cache->zcc_depot_list[i] = (struct zcc_magazine *)zalloc(magazine_zone);

		assert(temp_cache->zcc_depot_list[i] != NULL);

		zcache_mag_init(temp_cache->zcc_depot_list[i], magazine_element_count);
	}

	temp_cache->zcc_depot_index = 0;

 	lock_zone(zone);
	zone->zcache = temp_cache;
 	/* Set flag to know caching is enabled */
 	zone->cpu_cache_enabled = TRUE;
 	unlock_zone(zone);
 	return;
 }

void zcache_drain_depot(zone_t zone)
{
	struct zone_cache *zcache = zone->zcache;
	int drain_depot_index = 0;

	/*
	 * Grab the current depot list from the zone cache. If it has full magazines, 
	 * mark the depot as invalid and drain it.
	 */
	lck_mtx_lock_spin_always(&(zcache->zcc_depot_lock));
	if (!zcache_depot_available(zcache) || (zcache->zcc_depot_index == 0)) {
		/* no full magazines in the depot or depot unavailable; nothing to drain here */
		lck_mtx_unlock(&(zcache->zcc_depot_lock));
		return;
	}
	drain_depot_index = zcache->zcc_depot_index;
	/* Mark the depot as unavailable */
	zcache->zcc_depot_index = ZCACHE_DEPOT_INVALID;
	lck_mtx_unlock(&(zcache->zcc_depot_lock));

	/* Now drain the full magazines in the depot */
	for (int i = 0; i < drain_depot_index; i++)
		zcache_mag_drain(zone, zcache->zcc_depot_list[i]);

	lck_mtx_lock_spin_always(&(zcache->zcc_depot_lock));
	/* Mark the depot as available again */
	zcache->zcc_depot_index = 0;
	lck_mtx_unlock(&(zcache->zcc_depot_lock));
}

bool zcache_free_to_cpu_cache(zone_t zone, void *addr)
{
	int	curcpu;					/* Current cpu is used to index into array of zcc_per_cpu_cache structs */
	struct	zone_cache *zcache;			/* local storage of the zone's cache */
	struct zcc_per_cpu_cache *per_cpu_cache;	/* locally store the current per_cpu_cache */

	disable_preemption();
	curcpu = current_processor()->cpu_id;
	zcache = zone->zcache;
	per_cpu_cache = &zcache->zcc_per_cpu_caches[curcpu];

	if (zcache_mag_has_space(per_cpu_cache->current)) {
		/* If able, free into current magazine */
		goto free_to_current;
	} else if (zcache_mag_has_space(per_cpu_cache->previous)) {
		/* If able, swap current and previous magazine and retry */
		zcache_swap_magazines(&per_cpu_cache->previous, &per_cpu_cache->current);
		goto free_to_current;
	} else{
		lck_mtx_lock_spin_always(&(zcache->zcc_depot_lock));
		if (zcache_depot_available(zcache) && (zcache->zcc_depot_index < depot_element_count)) {
			/* If able, rotate in a new empty magazine from the depot and retry */
			zcache_mag_depot_swap_for_free(zcache, per_cpu_cache);
			lck_mtx_unlock(&(zcache->zcc_depot_lock));
			goto free_to_current;
		}
		lck_mtx_unlock(&(zcache->zcc_depot_lock));
		/* Attempt to free an entire magazine of elements */
		zcache_mag_drain(zone, per_cpu_cache->current);
		if(zcache_mag_has_space(per_cpu_cache->current)){
			goto free_to_current;
		}
	}

	/* If not able to use cache return FALSE and fall through to zfree */
	enable_preemption();
	return FALSE;

free_to_current:
	assert(zcache_mag_has_space(per_cpu_cache->current));
	zcache_canary_add(zone, addr);
	zcache_mag_push(per_cpu_cache->current, addr);

#if KASAN_ZALLOC
	kasan_poison_range((vm_offset_t)addr, zone->elem_size, ASAN_HEAP_FREED);
#endif

	enable_preemption();
	return TRUE;
}

vm_offset_t zcache_alloc_from_cpu_cache(zone_t zone)
{
	int curcpu;					/* Current cpu is used to index into array of zcc_per_cpu_cache structs */
	void *ret = NULL;				/* Points to the element which will be returned */
	struct	zone_cache *zcache;			/* local storage of the zone's cache */
	struct zcc_per_cpu_cache *per_cpu_cache; 	/* locally store the current per_cpu_cache */

	disable_preemption();
	curcpu = current_processor()->cpu_id;
	zcache = zone->zcache;
	per_cpu_cache = &zcache->zcc_per_cpu_caches[curcpu];

	if (zcache_mag_has_elements(per_cpu_cache->current)) {
		/* If able, allocate from current magazine */
		goto allocate_from_current;
	} else if (zcache_mag_has_elements(per_cpu_cache->previous)) {
		/* If able, swap current and previous magazine and retry */
		zcache_swap_magazines(&per_cpu_cache->previous, &per_cpu_cache->current);
		goto allocate_from_current;
	} else {
		lck_mtx_lock_spin_always(&(zcache->zcc_depot_lock));
		if (zcache_depot_available(zcache) && (zcache->zcc_depot_index > 0)) {
			/* If able, rotate in a full magazine from the depot */
			zcache_mag_depot_swap_for_alloc(zcache, per_cpu_cache);
			lck_mtx_unlock(&(zcache->zcc_depot_lock));
			goto allocate_from_current;
		}
		lck_mtx_unlock(&(zcache->zcc_depot_lock));
		/* Attempt to allocate an entire magazine of elements */
		if(zcache_mag_fill(zone, per_cpu_cache->current)){
			goto allocate_from_current;
		}
	}

	/* If unable to allocate from cache return NULL and fall through to zalloc */
	enable_preemption();
	return (vm_offset_t) NULL;

allocate_from_current:
	ret = zcache_mag_pop(per_cpu_cache->current);
	assert(ret != NULL);
	zcache_canary_validate(zone, ret);

#if KASAN_ZALLOC
	kasan_poison_range((vm_offset_t)ret, zone->elem_size, ASAN_VALID);
#endif

	enable_preemption();
	return (vm_offset_t) ret;
}

void zcache_mag_init(struct zcc_magazine *mag, int count)
{
	mag->zcc_magazine_index = 0;
	mag->zcc_magazine_capacity = count;
}

bool zcache_mag_fill(zone_t zone, struct zcc_magazine *mag)
{
	assert(mag->zcc_magazine_index == 0);
	void* elem = NULL;
	uint32_t i;
	lock_zone(zone);
	for(i = mag->zcc_magazine_index; i < mag->zcc_magazine_capacity; i ++){
		elem = zalloc_attempt(zone);
		if(elem) {
			zcache_canary_add(zone, elem);
			zcache_mag_push(mag, elem);
#if KASAN_ZALLOC
			kasan_poison_range((vm_offset_t)elem, zone->elem_size, ASAN_HEAP_FREED);
#endif
		} else {
			break;
		}
	}
	unlock_zone(zone);
	if (i == 0){
		return FALSE;
	}
	return TRUE;
}

void zcache_mag_drain(zone_t zone, struct zcc_magazine *mag)
{
	assert(mag->zcc_magazine_index == mag->zcc_magazine_capacity);
	lock_zone(zone);
	while(mag->zcc_magazine_index > 0){
		uint32_t index = --mag->zcc_magazine_index;
		zcache_canary_validate(zone, mag->zcc_elements[index]);
		zfree_direct(zone,(vm_offset_t)mag->zcc_elements[index]);
		mag->zcc_elements[mag->zcc_magazine_index] = 0;
	}
	unlock_zone(zone);
}

void *zcache_mag_pop(struct zcc_magazine *mag)
{
	void	*elem;
	assert(zcache_mag_has_elements(mag));
	elem =  mag->zcc_elements[--mag->zcc_magazine_index];
	/* Ensure pointer to element cannot be accessed after we pop it */
	mag->zcc_elements[mag->zcc_magazine_index] = NULL;
	assert(elem != NULL);
	return elem;
}

void zcache_mag_push(struct zcc_magazine *mag, void *elem)
{
	assert(zcache_mag_has_space(mag));
	mag->zcc_elements[mag->zcc_magazine_index ++] = elem;
}

bool zcache_mag_has_space(struct zcc_magazine *mag)
{
	return (mag->zcc_magazine_index < mag->zcc_magazine_capacity);
}

bool zcache_mag_has_elements(struct zcc_magazine *mag)
{
	return (mag->zcc_magazine_index > 0);
}

void zcache_swap_magazines(struct zcc_magazine **a, struct zcc_magazine **b)
{
	struct zcc_magazine *temp = *a;
	*a = *b;
	*b = temp;
}

void zcache_mag_depot_swap_for_alloc(struct zone_cache *zcache, struct zcc_per_cpu_cache *cache)
{
	/* Loads a full magazine from which we can allocate */
	assert(zcache_depot_available(zcache));
	assert(zcache->zcc_depot_index > 0);
	zcache->zcc_depot_index --;
	zcache_swap_magazines(&cache->current, &zcache->zcc_depot_list[zcache->zcc_depot_index]);
}

void zcache_mag_depot_swap_for_free(struct zone_cache *zcache, struct zcc_per_cpu_cache *cache)
{
	/* Loads an empty magazine into which we can free */
	assert(zcache_depot_available(zcache));
	assert(zcache->zcc_depot_index < depot_element_count);
	zcache_swap_magazines(&cache->current, &zcache->zcc_depot_list[zcache->zcc_depot_index]);
	zcache->zcc_depot_index ++;
}

void zcache_canary_add(zone_t zone, void *element)
{
	vm_offset_t *primary = (vm_offset_t *)element;
	vm_offset_t *backup = (vm_offset_t *)((vm_offset_t)primary + zone->elem_size - sizeof(vm_offset_t));
	*primary = *backup = (zcache_canary ^ (uintptr_t)element);
}

void zcache_canary_validate(zone_t zone, void *element)
{
	vm_offset_t *primary = (vm_offset_t *)element;
	vm_offset_t *backup = (vm_offset_t *)((vm_offset_t)primary + zone->elem_size - sizeof(vm_offset_t));

	vm_offset_t primary_value = (*primary ^ (uintptr_t)element);
	if (primary_value != zcache_canary) {
		panic("Zone cache element was used after free! Element %p was corrupted at beginning; Expected %p but found %p; canary %p",
			element, (void *)(zcache_canary ^ (uintptr_t)element) , (void *)(*primary), (void *)zcache_canary);
	}
	
	vm_offset_t backup_value = (*backup ^ (uintptr_t)element);
	if (backup_value != zcache_canary) {
		panic("Zone cache element was used after free! Element %p was corrupted at end; Expected %p but found %p; canary %p",
			element, (void *)(zcache_canary ^ (uintptr_t)element), (void *)(*backup), (void *)zcache_canary);
	}
}

