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
struct zip_entry {scalar_t__ deleted; int /*<<< orphan*/ * source; int /*<<< orphan*/ * changes; int /*<<< orphan*/ * orig; } ;

/* Variables and functions */
 int /*<<< orphan*/  _zip_dirent_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _zip_unchange_data (struct zip_entry*) ; 
 int tolower (unsigned char) ; 

__attribute__((used)) static inline int __strcasecmp(const char *s1, const char *s2) {
	int c1, c2;
	for(;;) {
		c1 = tolower ( (unsigned char) *s1++ );
		c2 = tolower ( (unsigned char) *s2++ );
		if (c1 == 0 || c1 != c2)
			return c1 - c2;
	}
}

void
_zip_entry_finalize(struct zip_entry *e)
{
    _zip_unchange_data(e);
    _zip_dirent_free(e->orig);
    _zip_dirent_free(e->changes);
}

void
_zip_entry_init(struct zip_entry *e)
{
    e->orig = NULL;
    e->changes = NULL;
    e->source = NULL;
    e->deleted = 0;
}

