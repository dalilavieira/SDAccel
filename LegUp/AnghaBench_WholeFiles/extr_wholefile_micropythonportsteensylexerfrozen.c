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
typedef  int /*<<< orphan*/  mp_lexer_t ;
typedef  int /*<<< orphan*/  mp_import_stat_t ;

/* Variables and functions */
 int /*<<< orphan*/  MP_ENOENT ; 
 int /*<<< orphan*/  MP_IMPORT_STAT_NO_EXIST ; 
 int /*<<< orphan*/  mp_raise_OSError (int /*<<< orphan*/ ) ; 

mp_import_stat_t mp_import_stat(const char *path) {
    return MP_IMPORT_STAT_NO_EXIST;
}

mp_lexer_t *mp_lexer_new_from_file(const char *filename) {
    mp_raise_OSError(MP_ENOENT);
}

