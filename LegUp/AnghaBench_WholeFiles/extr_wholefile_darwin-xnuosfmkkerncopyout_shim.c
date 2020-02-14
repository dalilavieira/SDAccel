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
typedef  int /*<<< orphan*/  kern_return_t ;

/* Variables and functions */
 int /*<<< orphan*/  KERN_FAILURE ; 
 int /*<<< orphan*/  UNUSED_IN_RELEASE (void const*) ; 

kern_return_t register_copyout_shim(void (*fn)(const void *,user_addr_t,vm_size_t,unsigned co_src),unsigned types)
{
#if (DEVELOPMENT || DEBUG)
    int copyout_shim_enabled=0;
    
    if(!fn)
    {
        /* unregistration is always allowed */
        copyout_shim_fn=NULL;
        return KERN_SUCCESS;
    }
    
    if(copyout_shim_fn)
    {
        //need to unregister first before registering a new one.
        return KERN_FAILURE;
    }
    
    if(!PE_parse_boot_argn("enable_copyout_shim",&copyout_shim_enabled,sizeof(copyout_shim_enabled)) || !copyout_shim_enabled)
    {
        return KERN_FAILURE;
    }
    

    co_src_flags=types;
    copyout_shim_fn=fn;
    return KERN_SUCCESS;
#else
    UNUSED_IN_RELEASE(fn);
    UNUSED_IN_RELEASE(types);
    return KERN_FAILURE;
#endif
}

void *cos_kernel_unslide(const void *ptr)
{
#if (DEVELOPMENT || DEBUG)
    return (void *)(VM_KERNEL_UNSLIDE(ptr));
#else
    UNUSED_IN_RELEASE(ptr);
    return NULL;
#endif
}

void *cos_kernel_reslide(const void *ptr)
{
#if (DEVELOPMENT || DEBUG)
    return (void *)(VM_KERNEL_SLIDE(ptr));
#else
    UNUSED_IN_RELEASE(ptr);
    return NULL;
#endif
}

