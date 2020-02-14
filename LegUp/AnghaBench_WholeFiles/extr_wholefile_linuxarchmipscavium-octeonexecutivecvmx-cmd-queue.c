#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int doorbell; } ;
union cvmx_pko_mem_debug9 {TYPE_2__ cn38xx; void* u64; } ;
struct TYPE_15__ {int doorbell; } ;
union cvmx_pko_mem_debug8 {TYPE_3__ cn58xx; void* u64; } ;
struct TYPE_16__ {int dbell; } ;
union cvmx_npei_dmax_counts {TYPE_4__ s; void* u64; } ;
struct TYPE_13__ {int /*<<< orphan*/  enb; } ;
union cvmx_fpa_ctl_status {TYPE_1__ s; void* u64; } ;
typedef  int uint64_t ;
struct cvmx_bootmem_named_block_desc {int base_addr; } ;
typedef  scalar_t__ cvmx_cmd_queue_result_t ;
typedef  int cvmx_cmd_queue_id_t ;
struct TYPE_17__ {int base_ptr_div128; int max_depth; int fpa_pool; int pool_size_m1; scalar_t__* ticket; } ;
typedef  TYPE_5__ __cvmx_cmd_queue_state_t ;

/* Variables and functions */
 scalar_t__ CVMX_CMD_QUEUE_ALREADY_SETUP ; 
#define  CVMX_CMD_QUEUE_DFA 133 
#define  CVMX_CMD_QUEUE_DMA_BASE 132 
 scalar_t__ CVMX_CMD_QUEUE_ENABLE_MAX_DEPTH ; 
#define  CVMX_CMD_QUEUE_END 131 
 scalar_t__ CVMX_CMD_QUEUE_FULL ; 
 scalar_t__ CVMX_CMD_QUEUE_INVALID_PARAM ; 
 scalar_t__ CVMX_CMD_QUEUE_NO_MEMORY ; 
#define  CVMX_CMD_QUEUE_PKO_BASE 130 
#define  CVMX_CMD_QUEUE_RAID 129 
 scalar_t__ CVMX_CMD_QUEUE_SUCCESS ; 
#define  CVMX_CMD_QUEUE_ZIP 128 
 scalar_t__ CVMX_ENABLE_PARAMETER_CHECKING ; 
 int /*<<< orphan*/  CVMX_FPA_CTL_STATUS ; 
 int /*<<< orphan*/  CVMX_PEXP_NPEI_DMAX_COUNTS (int) ; 
 int /*<<< orphan*/  CVMX_PKO_MEM_DEBUG8 ; 
 int /*<<< orphan*/  CVMX_PKO_MEM_DEBUG9 ; 
 int /*<<< orphan*/  CVMX_PKO_REG_READ_IDX ; 
 int /*<<< orphan*/  CVMX_SYNCWS ; 
 int /*<<< orphan*/  OCTEON_CN3XXX ; 
 int /*<<< orphan*/  OCTEON_IS_MODEL (int /*<<< orphan*/ ) ; 
 size_t __cvmx_cmd_queue_get_index (int) ; 
 TYPE_5__* __cvmx_cmd_queue_get_state (int) ; 
 int /*<<< orphan*/  __cvmx_cmd_queue_lock (int,TYPE_5__*) ; 
 TYPE_5__* __cvmx_cmd_queue_state_ptr ; 
 int /*<<< orphan*/  __cvmx_cmd_queue_unlock (TYPE_5__*) ; 
 TYPE_5__* cvmx_bootmem_alloc_named (int,int,char*) ; 
 struct cvmx_bootmem_named_block_desc* cvmx_bootmem_find_named_block (char*) ; 
 int cvmx_cmd_queue_length (int) ; 
 int /*<<< orphan*/  cvmx_dprintf (char*,...) ; 
 void* cvmx_fpa_alloc (int) ; 
 int /*<<< orphan*/  cvmx_fpa_free (void*,int,int /*<<< orphan*/ ) ; 
 void* cvmx_phys_to_ptr (int) ; 
 int cvmx_ptr_to_phys (void*) ; 
 void* cvmx_read_csr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_write_csr (int /*<<< orphan*/ ,int) ; 
 scalar_t__ likely (TYPE_5__*) ; 
 int /*<<< orphan*/  memset (TYPE_5__*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static cvmx_cmd_queue_result_t __cvmx_cmd_queue_init_state_ptr(void)
{
	char *alloc_name = "cvmx_cmd_queues";
#if defined(CONFIG_CAVIUM_RESERVE32) && CONFIG_CAVIUM_RESERVE32
	extern uint64_t octeon_reserve32_memory;
#endif

	if (likely(__cvmx_cmd_queue_state_ptr))
		return CVMX_CMD_QUEUE_SUCCESS;

#if defined(CONFIG_CAVIUM_RESERVE32) && CONFIG_CAVIUM_RESERVE32
	if (octeon_reserve32_memory)
		__cvmx_cmd_queue_state_ptr =
		    cvmx_bootmem_alloc_named_range(sizeof(*__cvmx_cmd_queue_state_ptr),
						   octeon_reserve32_memory,
						   octeon_reserve32_memory +
						   (CONFIG_CAVIUM_RESERVE32 <<
						    20) - 1, 128, alloc_name);
	else
#endif
		__cvmx_cmd_queue_state_ptr =
		    cvmx_bootmem_alloc_named(sizeof(*__cvmx_cmd_queue_state_ptr),
					    128,
					    alloc_name);
	if (__cvmx_cmd_queue_state_ptr)
		memset(__cvmx_cmd_queue_state_ptr, 0,
		       sizeof(*__cvmx_cmd_queue_state_ptr));
	else {
		struct cvmx_bootmem_named_block_desc *block_desc =
		    cvmx_bootmem_find_named_block(alloc_name);
		if (block_desc)
			__cvmx_cmd_queue_state_ptr =
			    cvmx_phys_to_ptr(block_desc->base_addr);
		else {
			cvmx_dprintf
			    ("ERROR: cvmx_cmd_queue_initialize: Unable to get named block %s.\n",
			     alloc_name);
			return CVMX_CMD_QUEUE_NO_MEMORY;
		}
	}
	return CVMX_CMD_QUEUE_SUCCESS;
}

cvmx_cmd_queue_result_t cvmx_cmd_queue_initialize(cvmx_cmd_queue_id_t queue_id,
						  int max_depth, int fpa_pool,
						  int pool_size)
{
	__cvmx_cmd_queue_state_t *qstate;
	cvmx_cmd_queue_result_t result = __cvmx_cmd_queue_init_state_ptr();
	if (result != CVMX_CMD_QUEUE_SUCCESS)
		return result;

	qstate = __cvmx_cmd_queue_get_state(queue_id);
	if (qstate == NULL)
		return CVMX_CMD_QUEUE_INVALID_PARAM;

	/*
	 * We artificially limit max_depth to 1<<20 words. It is an
	 * arbitrary limit.
	 */
	if (CVMX_CMD_QUEUE_ENABLE_MAX_DEPTH) {
		if ((max_depth < 0) || (max_depth > 1 << 20))
			return CVMX_CMD_QUEUE_INVALID_PARAM;
	} else if (max_depth != 0)
		return CVMX_CMD_QUEUE_INVALID_PARAM;

	if ((fpa_pool < 0) || (fpa_pool > 7))
		return CVMX_CMD_QUEUE_INVALID_PARAM;
	if ((pool_size < 128) || (pool_size > 65536))
		return CVMX_CMD_QUEUE_INVALID_PARAM;

	/* See if someone else has already initialized the queue */
	if (qstate->base_ptr_div128) {
		if (max_depth != (int)qstate->max_depth) {
			cvmx_dprintf("ERROR: cvmx_cmd_queue_initialize: "
				"Queue already initialized with different "
				"max_depth (%d).\n",
			     (int)qstate->max_depth);
			return CVMX_CMD_QUEUE_INVALID_PARAM;
		}
		if (fpa_pool != qstate->fpa_pool) {
			cvmx_dprintf("ERROR: cvmx_cmd_queue_initialize: "
				"Queue already initialized with different "
				"FPA pool (%u).\n",
			     qstate->fpa_pool);
			return CVMX_CMD_QUEUE_INVALID_PARAM;
		}
		if ((pool_size >> 3) - 1 != qstate->pool_size_m1) {
			cvmx_dprintf("ERROR: cvmx_cmd_queue_initialize: "
				"Queue already initialized with different "
				"FPA pool size (%u).\n",
			     (qstate->pool_size_m1 + 1) << 3);
			return CVMX_CMD_QUEUE_INVALID_PARAM;
		}
		CVMX_SYNCWS;
		return CVMX_CMD_QUEUE_ALREADY_SETUP;
	} else {
		union cvmx_fpa_ctl_status status;
		void *buffer;

		status.u64 = cvmx_read_csr(CVMX_FPA_CTL_STATUS);
		if (!status.s.enb) {
			cvmx_dprintf("ERROR: cvmx_cmd_queue_initialize: "
				     "FPA is not enabled.\n");
			return CVMX_CMD_QUEUE_NO_MEMORY;
		}
		buffer = cvmx_fpa_alloc(fpa_pool);
		if (buffer == NULL) {
			cvmx_dprintf("ERROR: cvmx_cmd_queue_initialize: "
				     "Unable to allocate initial buffer.\n");
			return CVMX_CMD_QUEUE_NO_MEMORY;
		}

		memset(qstate, 0, sizeof(*qstate));
		qstate->max_depth = max_depth;
		qstate->fpa_pool = fpa_pool;
		qstate->pool_size_m1 = (pool_size >> 3) - 1;
		qstate->base_ptr_div128 = cvmx_ptr_to_phys(buffer) / 128;
		/*
		 * We zeroed the now serving field so we need to also
		 * zero the ticket.
		 */
		__cvmx_cmd_queue_state_ptr->
		    ticket[__cvmx_cmd_queue_get_index(queue_id)] = 0;
		CVMX_SYNCWS;
		return CVMX_CMD_QUEUE_SUCCESS;
	}
}

cvmx_cmd_queue_result_t cvmx_cmd_queue_shutdown(cvmx_cmd_queue_id_t queue_id)
{
	__cvmx_cmd_queue_state_t *qptr = __cvmx_cmd_queue_get_state(queue_id);
	if (qptr == NULL) {
		cvmx_dprintf("ERROR: cvmx_cmd_queue_shutdown: Unable to "
			     "get queue information.\n");
		return CVMX_CMD_QUEUE_INVALID_PARAM;
	}

	if (cvmx_cmd_queue_length(queue_id) > 0) {
		cvmx_dprintf("ERROR: cvmx_cmd_queue_shutdown: Queue still "
			     "has data in it.\n");
		return CVMX_CMD_QUEUE_FULL;
	}

	__cvmx_cmd_queue_lock(queue_id, qptr);
	if (qptr->base_ptr_div128) {
		cvmx_fpa_free(cvmx_phys_to_ptr
			      ((uint64_t) qptr->base_ptr_div128 << 7),
			      qptr->fpa_pool, 0);
		qptr->base_ptr_div128 = 0;
	}
	__cvmx_cmd_queue_unlock(qptr);

	return CVMX_CMD_QUEUE_SUCCESS;
}

int cvmx_cmd_queue_length(cvmx_cmd_queue_id_t queue_id)
{
	if (CVMX_ENABLE_PARAMETER_CHECKING) {
		if (__cvmx_cmd_queue_get_state(queue_id) == NULL)
			return CVMX_CMD_QUEUE_INVALID_PARAM;
	}

	/*
	 * The cast is here so gcc with check that all values in the
	 * cvmx_cmd_queue_id_t enumeration are here.
	 */
	switch ((cvmx_cmd_queue_id_t) (queue_id & 0xff0000)) {
	case CVMX_CMD_QUEUE_PKO_BASE:
		/*
		 * FIXME: Need atomic lock on
		 * CVMX_PKO_REG_READ_IDX. Right now we are normally
		 * called with the queue lock, so that is a SLIGHT
		 * amount of protection.
		 */
		cvmx_write_csr(CVMX_PKO_REG_READ_IDX, queue_id & 0xffff);
		if (OCTEON_IS_MODEL(OCTEON_CN3XXX)) {
			union cvmx_pko_mem_debug9 debug9;
			debug9.u64 = cvmx_read_csr(CVMX_PKO_MEM_DEBUG9);
			return debug9.cn38xx.doorbell;
		} else {
			union cvmx_pko_mem_debug8 debug8;
			debug8.u64 = cvmx_read_csr(CVMX_PKO_MEM_DEBUG8);
			return debug8.cn58xx.doorbell;
		}
	case CVMX_CMD_QUEUE_ZIP:
	case CVMX_CMD_QUEUE_DFA:
	case CVMX_CMD_QUEUE_RAID:
		/* FIXME: Implement other lengths */
		return 0;
	case CVMX_CMD_QUEUE_DMA_BASE:
		{
			union cvmx_npei_dmax_counts dmax_counts;
			dmax_counts.u64 =
			    cvmx_read_csr(CVMX_PEXP_NPEI_DMAX_COUNTS
					  (queue_id & 0x7));
			return dmax_counts.s.dbell;
		}
	case CVMX_CMD_QUEUE_END:
		return CVMX_CMD_QUEUE_INVALID_PARAM;
	}
	return CVMX_CMD_QUEUE_INVALID_PARAM;
}

void *cvmx_cmd_queue_buffer(cvmx_cmd_queue_id_t queue_id)
{
	__cvmx_cmd_queue_state_t *qptr = __cvmx_cmd_queue_get_state(queue_id);
	if (qptr && qptr->base_ptr_div128)
		return cvmx_phys_to_ptr((uint64_t) qptr->base_ptr_div128 << 7);
	else
		return NULL;
}

