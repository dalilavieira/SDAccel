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
struct _heapinfo {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_REALLOC_IN_PLACE_ONLY ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  HeapCompact (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 void* HeapReAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,size_t) ; 
 size_t HeapSize (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  HeapValidate (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 size_t ROUND_SIZE (size_t) ; 

void* malloc(size_t _size)
{
   size_t nSize = ROUND_SIZE(_size);

   if (nSize<_size)
       return NULL;

   return HeapAlloc(GetProcessHeap(), 0, nSize);
}

void free(void* _ptr)
{
   HeapFree(GetProcessHeap(),0,_ptr);
}

void* calloc(size_t _nmemb, size_t _size)
{
   size_t nSize = _nmemb * _size;
   size_t cSize = ROUND_SIZE(nSize);

   if ( (_nmemb > ((size_t)-1 / _size))  || (cSize<nSize))
      return NULL;

   return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, cSize );
}

void* realloc(void* _ptr, size_t _size)
{
   size_t nSize;

   if (_ptr == NULL)
      return malloc(_size);

   if (_size == 0)
   {
   	   free(_ptr);
       return NULL;
   }

   nSize = ROUND_SIZE(_size);

   /* check for integer overflow */
   if (nSize<_size)
       return NULL;

   return HeapReAlloc(GetProcessHeap(), 0, _ptr, nSize);
}

void* _expand(void* _ptr, size_t _size)
{
   size_t nSize;

   nSize = ROUND_SIZE(_size);

   if (nSize<_size)
       return NULL;

   return HeapReAlloc(GetProcessHeap(), HEAP_REALLOC_IN_PLACE_ONLY, _ptr, nSize);
}

size_t _msize(void* _ptr)
{
   return HeapSize(GetProcessHeap(), 0, _ptr);
}

int	_heapchk(void)
{
	if (!HeapValidate(GetProcessHeap(), 0, NULL))
		return -1;
	return 0;
}

int	_heapmin(void)
{
	if (!HeapCompact(GetProcessHeap(), 0))
		return -1;
	return 0;
}

int	_heapset(unsigned int unFill)
{
	if (_heapchk() == -1)
		return -1;
	return 0;

}

int _heapwalk(struct _heapinfo* entry)
{
	return 0;
}

