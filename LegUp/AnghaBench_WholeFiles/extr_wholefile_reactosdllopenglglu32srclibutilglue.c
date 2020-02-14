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
 unsigned char const** __gluNurbsErrors ; 
 unsigned char const** __gluTessErrors ; 

const unsigned char *__gluNURBSErrorString( int errnum )
{
    return __gluNurbsErrors[errnum];
}

const unsigned char *__gluTessErrorString( int errnum )
{
    return __gluTessErrors[errnum];
}

