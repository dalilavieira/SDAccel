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
 int toupper (char const) ; 

int strncasecmp( const char* s1, const char* s2, size_t c ) {
    int result = 0;

    while ( c ) {
        result = toupper( *s1 ) - toupper( *s2++ );

        if ( ( result != 0 ) || ( *s1++ == 0 ) ) {
            break;
        }

        c--;
    }

    return result;
}

