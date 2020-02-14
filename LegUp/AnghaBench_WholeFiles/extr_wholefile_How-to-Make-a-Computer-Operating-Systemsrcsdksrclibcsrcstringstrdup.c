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
 scalar_t__ malloc (size_t) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 size_t strlen (char const*) ; 

char* strdup( const char* s ) {
    char* s2;
    size_t length;

    length = strlen( s );
    s2 = ( char* )malloc( length + 1 );

    if ( s2 == NULL ) {
        return NULL;
    }

    memcpy( s2, s, length + 1 );

    return s2;
}

