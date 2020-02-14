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
 int _strnicmp (char const*,char const*,size_t) ; 
 int strncmp (char const*,char const*,size_t) ; 

int _strncoll(const char* s1, const char* s2, size_t c)
{
    return strncmp(s1, s2, c);
}

int _strnicoll(const char* s1, const char* s2, size_t c)
{
    return _strnicmp(s1, s2, c);
}

