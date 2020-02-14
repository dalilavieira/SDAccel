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
typedef  int /*<<< orphan*/  X509_STORE ;
typedef  int /*<<< orphan*/  X509_LOOKUP ;

/* Variables and functions */
 int /*<<< orphan*/  ERR_clear_error () ; 
 int /*<<< orphan*/  X509_FILETYPE_DEFAULT ; 
 int /*<<< orphan*/  X509_FILETYPE_PEM ; 
 int X509_LOOKUP_add_dir (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  X509_LOOKUP_file () ; 
 int /*<<< orphan*/  X509_LOOKUP_hash_dir () ; 
 int X509_LOOKUP_load_file (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * X509_STORE_add_lookup (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int X509_STORE_set_default_paths(X509_STORE *ctx)
{
    X509_LOOKUP *lookup;

    lookup = X509_STORE_add_lookup(ctx, X509_LOOKUP_file());
    if (lookup == NULL)
        return 0;
    X509_LOOKUP_load_file(lookup, NULL, X509_FILETYPE_DEFAULT);

    lookup = X509_STORE_add_lookup(ctx, X509_LOOKUP_hash_dir());
    if (lookup == NULL)
        return 0;
    X509_LOOKUP_add_dir(lookup, NULL, X509_FILETYPE_DEFAULT);

    /* clear any errors */
    ERR_clear_error();

    return 1;
}

int X509_STORE_load_locations(X509_STORE *ctx, const char *file,
                              const char *path)
{
    X509_LOOKUP *lookup;

    if (file != NULL) {
        lookup = X509_STORE_add_lookup(ctx, X509_LOOKUP_file());
        if (lookup == NULL)
            return 0;
        if (X509_LOOKUP_load_file(lookup, file, X509_FILETYPE_PEM) != 1)
            return 0;
    }
    if (path != NULL) {
        lookup = X509_STORE_add_lookup(ctx, X509_LOOKUP_hash_dir());
        if (lookup == NULL)
            return 0;
        if (X509_LOOKUP_add_dir(lookup, path, X509_FILETYPE_PEM) != 1)
            return 0;
    }
    if ((path == NULL) && (file == NULL))
        return 0;
    return 1;
}

