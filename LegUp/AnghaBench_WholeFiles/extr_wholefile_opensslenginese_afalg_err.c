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
 int /*<<< orphan*/  AFALG_str_functs ; 
 int /*<<< orphan*/  AFALG_str_reasons ; 
 int /*<<< orphan*/  ERR_PUT_error (scalar_t__,int,int,char*,int) ; 
 scalar_t__ ERR_get_next_error_library () ; 
 int /*<<< orphan*/  ERR_load_strings (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_unload_strings (scalar_t__,int /*<<< orphan*/ ) ; 
 int error_loaded ; 
 scalar_t__ lib_code ; 

__attribute__((used)) static int ERR_load_AFALG_strings(void)
{
    if (lib_code == 0)
        lib_code = ERR_get_next_error_library();

    if (!error_loaded) {
#ifndef OPENSSL_NO_ERR
        ERR_load_strings(lib_code, AFALG_str_functs);
        ERR_load_strings(lib_code, AFALG_str_reasons);
#endif
        error_loaded = 1;
    }
    return 1;
}

__attribute__((used)) static void ERR_unload_AFALG_strings(void)
{
    if (error_loaded) {
#ifndef OPENSSL_NO_ERR
        ERR_unload_strings(lib_code, AFALG_str_functs);
        ERR_unload_strings(lib_code, AFALG_str_reasons);
#endif
        error_loaded = 0;
    }
}

__attribute__((used)) static void ERR_AFALG_error(int function, int reason, char *file, int line)
{
    if (lib_code == 0)
        lib_code = ERR_get_next_error_library();
    ERR_PUT_error(lib_code, function, reason, file, line);
}

