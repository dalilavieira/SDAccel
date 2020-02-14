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
typedef  enum r_range { ____Placeholder_r_range } r_range ;
typedef  int /*<<< orphan*/  CONF ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_printf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  ERR_clear_error () ; 
 int /*<<< orphan*/  ERR_print_errors (int /*<<< orphan*/ ) ; 
 char LIST_SEPARATOR_CHAR ; 
 char* NCONF_get_string (int /*<<< orphan*/ *,char const*,char*) ; 
 int /*<<< orphan*/  OPENSSL_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * OPENSSL_strdup (char const*) ; 
#define  OPT_R_RAND 131 
#define  OPT_R_WRITERAND 130 
#define  OPT_R__FIRST 129 
#define  OPT_R__LAST 128 
 scalar_t__ RAND_load_file (char const*,int) ; 
 int RAND_write_file (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bio_err ; 
 char const* opt_arg () ; 
 int /*<<< orphan*/ * save_rand_file ; 

void app_RAND_load_conf(CONF *c, const char *section)
{
    const char *randfile = NCONF_get_string(c, section, "RANDFILE");

    if (randfile == NULL) {
        ERR_clear_error();
        return;
    }
    if (RAND_load_file(randfile, -1) < 0) {
        BIO_printf(bio_err, "Can't load %s into RNG\n", randfile);
        ERR_print_errors(bio_err);
    }
    if (save_rand_file == NULL)
        save_rand_file = OPENSSL_strdup(randfile);
}

__attribute__((used)) static int loadfiles(char *name)
{
    char *p;
    int last, ret = 1;

    for ( ; ; ) {
        last = 0;
        for (p = name; *p != '\0' && *p != LIST_SEPARATOR_CHAR; p++)
            continue;
        if (*p == '\0')
            last = 1;
        *p = '\0';
        if (RAND_load_file(name, -1) < 0) {
            BIO_printf(bio_err, "Can't load %s into RNG\n", name);
            ERR_print_errors(bio_err);
            ret = 0;
        }
        if (last)
            break;
        name = p + 1;
        if (*name == '\0')
            break;
    }
    return ret;
}

void app_RAND_write(void)
{
    if (save_rand_file == NULL)
        return;
    if (RAND_write_file(save_rand_file) == -1) {
        BIO_printf(bio_err, "Cannot write random bytes:\n");
        ERR_print_errors(bio_err);
    }
    OPENSSL_free(save_rand_file);
    save_rand_file =  NULL;
}

int opt_rand(int opt)
{
    switch ((enum r_range)opt) {
    case OPT_R__FIRST:
    case OPT_R__LAST:
        break;
    case OPT_R_RAND:
        return loadfiles(opt_arg());
        break;
    case OPT_R_WRITERAND:
        OPENSSL_free(save_rand_file);
        save_rand_file = OPENSSL_strdup(opt_arg());
        break;
    }
    return 1;
}

