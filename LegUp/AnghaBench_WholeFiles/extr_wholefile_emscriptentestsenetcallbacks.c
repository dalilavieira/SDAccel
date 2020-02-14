#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  (* free ) (void*) ;int /*<<< orphan*/  (* no_memory ) () ;void* (* malloc ) (size_t) ;} ;
struct TYPE_4__ {int /*<<< orphan*/  (* no_memory ) () ;int /*<<< orphan*/  (* free ) (void*) ;void* (* malloc ) (size_t) ;} ;
typedef  scalar_t__ ENetVersion ;
typedef  TYPE_1__ ENetCallbacks ;

/* Variables and functions */
 scalar_t__ ENET_VERSION_CREATE (int,int,int /*<<< orphan*/ ) ; 
 TYPE_3__ callbacks ; 
 int enet_initialize () ; 
 void* stub1 (size_t) ; 
 int /*<<< orphan*/  stub2 () ; 
 int /*<<< orphan*/  stub3 (void*) ; 

int
enet_initialize_with_callbacks (ENetVersion version, const ENetCallbacks * inits)
{
   if (version < ENET_VERSION_CREATE (1, 3, 0))
     return -1;

   if (inits -> malloc != NULL || inits -> free != NULL)
   {
      if (inits -> malloc == NULL || inits -> free == NULL)
        return -1;

      callbacks.malloc = inits -> malloc;
      callbacks.free = inits -> free;
   }
      
   if (inits -> no_memory != NULL)
     callbacks.no_memory = inits -> no_memory;

   return enet_initialize ();
}

void *
enet_malloc (size_t size)
{
   void * memory = callbacks.malloc (size);

   if (memory == NULL)
     callbacks.no_memory ();

   return memory;
}

void
enet_free (void * memory)
{
   callbacks.free (memory);
}

