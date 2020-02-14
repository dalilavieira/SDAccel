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

/* Variables and functions */
 int FreeLibrary (void*) ; 
 void* GetProcAddress (void*,char const*) ; 
 void* LoadLibraryA (char const*) ; 

void *wine_dlsym( void *handle, const char *symbol, char *error, size_t errorsize )
{
    return GetProcAddress(handle, symbol);
}

void *wine_dlopen( const char *filename, int flag, char *error, size_t errorsize )
{
    return LoadLibraryA(filename);
}

int wine_dlclose( void *handle, char *error, size_t errorsize )
{
    return FreeLibrary(handle);
}

