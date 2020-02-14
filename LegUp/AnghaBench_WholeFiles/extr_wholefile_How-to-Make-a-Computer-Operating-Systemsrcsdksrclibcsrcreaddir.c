#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct dirent {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  fd; struct dirent entry; } ;
typedef  TYPE_1__ DIR ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  errno ; 
 int getdents (int /*<<< orphan*/ ,struct dirent*,int) ; 

struct dirent* readdir( DIR* dir ) {
    int error;

    if ( dir == NULL ) {
        return NULL;
    }

    error = getdents( dir->fd, &dir->entry, sizeof( struct dirent ) );

    if ( error == 0 ) {
        return NULL;
    }

    return &dir->entry;
}

int readdir_r( DIR* dir, struct dirent* entry, struct dirent** result ) {
    int error;

    if ( ( dir == NULL ) ||
         ( entry == NULL ) ) {
        errno = -EINVAL;
        return -1;
    }

    error = getdents( dir->fd, entry, sizeof( struct dirent ) );

    if ( error == 0 ) {
        *result = NULL;
    } else {
        *result = entry;
    }

    return 0;
}

