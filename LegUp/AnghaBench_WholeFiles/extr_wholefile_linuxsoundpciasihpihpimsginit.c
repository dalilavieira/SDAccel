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
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct hpios_spinlock {scalar_t__ lock_context; int /*<<< orphan*/  lock; } ;
struct hpi_response_header {int size; int object; int function; int version; int error; void* type; scalar_t__ specific_error; int /*<<< orphan*/  adapter_index; } ;
struct hpi_response {int size; int object; int function; int version; int error; void* type; scalar_t__ specific_error; int /*<<< orphan*/  adapter_index; } ;
struct hpi_message_header {int size; int object; int function; int version; int error; void* type; scalar_t__ specific_error; int /*<<< orphan*/  adapter_index; } ;
struct hpi_message {int size; int object; int function; int version; int error; void* type; scalar_t__ specific_error; int /*<<< orphan*/  adapter_index; } ;
struct consistent_dma_area {scalar_t__ size; void* vaddr; int /*<<< orphan*/  dma_handle; } ;

/* Variables and functions */
 int /*<<< orphan*/  HPI_ADAPTER_INDEX_INVALID ; 
 void* HPI_ERROR_PROCESSING_MESSAGE ; 
 int HPI_OBJ_MAXINDEX ; 
 void* HPI_TYPE_REQUEST ; 
 void* HPI_TYPE_RESPONSE ; 
 void* HPI_TYPE_SSX2BYPASS_MESSAGE ; 
 scalar_t__ IN_LOCK_BH ; 
 scalar_t__ IN_LOCK_IRQ ; 
 int array_index_nospec (int,int) ; 
 scalar_t__ gwSSX2_bypass ; 
 scalar_t__ irqs_disabled () ; 
 int /*<<< orphan*/  memset (struct hpi_response_header*,int /*<<< orphan*/ ,int) ; 
 int* msg_size ; 
 int* res_size ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline u16 hpios_locked_mem_get_phys_addr(struct consistent_dma_area
	*locked_mem_handle, u32 *p_physical_addr)
{
	*p_physical_addr = locked_mem_handle->dma_handle;
	return 0;
}

__attribute__((used)) static inline u16 hpios_locked_mem_get_virt_addr(struct consistent_dma_area
	*locked_mem_handle, void **pp_virtual_addr)
{
	*pp_virtual_addr = locked_mem_handle->vaddr;
	return 0;
}

__attribute__((used)) static inline u16 hpios_locked_mem_valid(struct consistent_dma_area
	*locked_mem_handle)
{
	return locked_mem_handle->size != 0;
}

__attribute__((used)) static inline void cond_lock(struct hpios_spinlock *l)
{
	if (irqs_disabled()) {
		/* NO bh or isr can execute on this processor,
		   so ordinary lock will do
		 */
		spin_lock(&((l)->lock));
		l->lock_context = IN_LOCK_IRQ;
	} else {
		spin_lock_bh(&((l)->lock));
		l->lock_context = IN_LOCK_BH;
	}
}

__attribute__((used)) static inline void cond_unlock(struct hpios_spinlock *l)
{
	if (l->lock_context == IN_LOCK_BH)
		spin_unlock_bh(&((l)->lock));
	else
		spin_unlock(&((l)->lock));
}

__attribute__((used)) static void hpi_init_message(struct hpi_message *phm, u16 object,
	u16 function)
{
	u16 size;

	if ((object > 0) && (object <= HPI_OBJ_MAXINDEX)) {
		object = array_index_nospec(object, HPI_OBJ_MAXINDEX + 1);
		size = msg_size[object];
	} else {
		size = sizeof(*phm);
	}

	memset(phm, 0, size);
	phm->size = size;

	if (gwSSX2_bypass)
		phm->type = HPI_TYPE_SSX2BYPASS_MESSAGE;
	else
		phm->type = HPI_TYPE_REQUEST;
	phm->object = object;
	phm->function = function;
	phm->version = 0;
	phm->adapter_index = HPI_ADAPTER_INDEX_INVALID;
	/* Expect actual adapter index to be set by caller */
}

void hpi_init_response(struct hpi_response *phr, u16 object, u16 function,
	u16 error)
{
	u16 size;

	if ((object > 0) && (object <= HPI_OBJ_MAXINDEX)) {
		object = array_index_nospec(object, HPI_OBJ_MAXINDEX + 1);
		size = res_size[object];
	} else {
		size = sizeof(*phr);
	}

	memset(phr, 0, sizeof(*phr));
	phr->size = size;
	phr->type = HPI_TYPE_RESPONSE;
	phr->object = object;
	phr->function = function;
	phr->error = error;
	phr->specific_error = 0;
	phr->version = 0;
}

void hpi_init_message_response(struct hpi_message *phm,
	struct hpi_response *phr, u16 object, u16 function)
{
	hpi_init_message(phm, object, function);
	/* default error return if the response is
	   not filled in by the callee */
	hpi_init_response(phr, object, function,
		HPI_ERROR_PROCESSING_MESSAGE);
}

__attribute__((used)) static void hpi_init_messageV1(struct hpi_message_header *phm, u16 size,
	u16 object, u16 function)
{
	memset(phm, 0, size);
	if ((object > 0) && (object <= HPI_OBJ_MAXINDEX)) {
		phm->size = size;
		phm->type = HPI_TYPE_REQUEST;
		phm->object = object;
		phm->function = function;
		phm->version = 1;
		/* Expect adapter index to be set by caller */
	}
}

void hpi_init_responseV1(struct hpi_response_header *phr, u16 size,
	u16 object, u16 function)
{
	(void)object;
	(void)function;
	memset(phr, 0, size);
	phr->size = size;
	phr->version = 1;
	phr->type = HPI_TYPE_RESPONSE;
	phr->error = HPI_ERROR_PROCESSING_MESSAGE;
}

void hpi_init_message_responseV1(struct hpi_message_header *phm, u16 msg_size,
	struct hpi_response_header *phr, u16 res_size, u16 object,
	u16 function)
{
	hpi_init_messageV1(phm, msg_size, object, function);
	hpi_init_responseV1(phr, res_size, object, function);
}

