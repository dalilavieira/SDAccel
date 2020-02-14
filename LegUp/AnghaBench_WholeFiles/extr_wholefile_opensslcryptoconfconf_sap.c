#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  settings ;
struct TYPE_5__ {char* appname; void* flags; char* filename; } ;
typedef  TYPE_1__ OPENSSL_INIT_SETTINGS ;

/* Variables and functions */
 int CONF_modules_load_file (char const*,char const*,unsigned long) ; 
 void* DEFAULT_CONF_MFLAGS ; 
 int /*<<< orphan*/  ENGINE_load_builtin_engines () ; 
 int /*<<< orphan*/  ERR_clear_error () ; 
 int /*<<< orphan*/  OPENSSL_INIT_LOAD_CONFIG ; 
 int /*<<< orphan*/  OPENSSL_init_crypto (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  OPENSSL_load_builtin_modules () ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int openssl_configured ; 
 char* strdup (char const*) ; 

void OPENSSL_config(const char *appname)
{
    OPENSSL_INIT_SETTINGS settings;

    memset(&settings, 0, sizeof(settings));
    if (appname != NULL)
        settings.appname = strdup(appname);
    settings.flags = DEFAULT_CONF_MFLAGS;
    OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CONFIG, &settings);
}

int openssl_config_int(const OPENSSL_INIT_SETTINGS *settings)
{
    int ret;
    const char *filename;
    const char *appname;
    unsigned long flags;

    if (openssl_configured)
        return 1;

    filename = settings ? settings->filename : NULL;
    appname = settings ? settings->appname : NULL;
    flags = settings ? settings->flags : DEFAULT_CONF_MFLAGS;

#ifdef OPENSSL_INIT_DEBUG
    fprintf(stderr, "OPENSSL_INIT: openssl_config_int(%s, %s, %lu)\n",
            filename, appname, flags);
#endif

    OPENSSL_load_builtin_modules();
#ifndef OPENSSL_NO_ENGINE
    /* Need to load ENGINEs */
    ENGINE_load_builtin_engines();
#endif
    ERR_clear_error();
#ifndef OPENSSL_SYS_UEFI
    ret = CONF_modules_load_file(filename, appname, flags);
#endif
    openssl_configured = 1;
    return ret;
}

void openssl_no_config_int(void)
{
    openssl_configured = 1;
}

