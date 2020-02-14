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
typedef  int /*<<< orphan*/  VOID ;

/* Variables and functions */
 int /*<<< orphan*/  KdPrint (char*) ; 
 int /*<<< orphan*/  LOAD_NLS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UNLOAD_NLS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exit_nls_utf8 ; 
 int /*<<< orphan*/  init_nls_utf8 ; 
 int /*<<< orphan*/  nls_lock ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * tables ; 

int
RfsdLoadAllNls()
{
    int rc;

    tables = NULL;
    spin_lock_init(&nls_lock);

    //
    // Loading nls for utf8 ...
    //

    LOAD_NLS(init_nls_utf8);

#ifdef FULL_CODEPAGES_SUPPORT

    //
    // Loading nls for chinese gb2312 ...
    //

    LOAD_NLS(init_nls_cp936);
    LOAD_NLS(init_nls_gb2312);


    LOAD_NLS(init_nls_cp1251);
    LOAD_NLS(init_nls_cp1255);
    LOAD_NLS(init_nls_cp437);
    LOAD_NLS(init_nls_cp737);
    LOAD_NLS(init_nls_cp775);
    LOAD_NLS(init_nls_cp850);
    LOAD_NLS(init_nls_cp852);
    LOAD_NLS(init_nls_cp855);
    LOAD_NLS(init_nls_cp857);
    LOAD_NLS(init_nls_cp860);
    LOAD_NLS(init_nls_cp861);
    LOAD_NLS(init_nls_cp862);
    LOAD_NLS(init_nls_cp863);
    LOAD_NLS(init_nls_cp864);
    LOAD_NLS(init_nls_cp865);
    LOAD_NLS(init_nls_cp866);
    LOAD_NLS(init_nls_cp869);
    LOAD_NLS(init_nls_cp874);

    //
    // Loading nls for chinese big5
    //

    LOAD_NLS(init_nls_cp950);
    LOAD_NLS(init_nls_big5);

    //
    // Loading jp codepage
    //

    LOAD_NLS(init_nls_cp932);
    LOAD_NLS(init_nls_euc_jp);
    LOAD_NLS(init_nls_sjis);

    //
    // Loading korean nls codepage
    //

    LOAD_NLS(init_nls_cp949);
    LOAD_NLS(init_nls_euc_kr);

    LOAD_NLS(init_nls_iso8859_1);
    LOAD_NLS(init_nls_iso8859_13);
    LOAD_NLS(init_nls_iso8859_14);
    LOAD_NLS(init_nls_iso8859_15);
    LOAD_NLS(init_nls_iso8859_2);
    LOAD_NLS(init_nls_iso8859_3);
    LOAD_NLS(init_nls_iso8859_4);
    LOAD_NLS(init_nls_iso8859_5);
    LOAD_NLS(init_nls_iso8859_6);
    LOAD_NLS(init_nls_iso8859_7);
    LOAD_NLS(init_nls_iso8859_8);
    LOAD_NLS(init_nls_iso8859_9);
    LOAD_NLS(init_nls_koi8_r);
    LOAD_NLS(init_nls_koi8_u);

    LOAD_NLS(init_nls_koi8_ru);
    LOAD_NLS(init_nls_tis_620);

#endif //FULL_CODEPAGES_SUPPORT


    KdPrint(("RfsdLoadAllNls: succeed to load all codepages ...\n"));

errorout:

    return rc;
}

VOID
RfsdUnloadAllNls()
{
#ifdef FULL_CODEPAGES_SUPPORT

    UNLOAD_NLS(exit_nls_cp1251);
    UNLOAD_NLS(exit_nls_cp1255);
    UNLOAD_NLS(exit_nls_cp437);
    UNLOAD_NLS(exit_nls_cp737);
    UNLOAD_NLS(exit_nls_cp775);
    UNLOAD_NLS(exit_nls_cp850);
    UNLOAD_NLS(exit_nls_cp852);
    UNLOAD_NLS(exit_nls_cp855);
    UNLOAD_NLS(exit_nls_cp857);
    UNLOAD_NLS(exit_nls_cp860);
    UNLOAD_NLS(exit_nls_cp861);
    UNLOAD_NLS(exit_nls_cp862);
    UNLOAD_NLS(exit_nls_cp863);
    UNLOAD_NLS(exit_nls_cp864);
    UNLOAD_NLS(exit_nls_cp865);
    UNLOAD_NLS(exit_nls_cp866);
    UNLOAD_NLS(exit_nls_cp869);
    UNLOAD_NLS(exit_nls_cp874);
    UNLOAD_NLS(exit_nls_cp949);
    UNLOAD_NLS(exit_nls_cp950);
    UNLOAD_NLS(exit_nls_cp932);
    UNLOAD_NLS(exit_nls_euc_jp);
    UNLOAD_NLS(exit_nls_big5);
    UNLOAD_NLS(exit_nls_euc_kr);
    UNLOAD_NLS(exit_nls_iso8859_1);
    UNLOAD_NLS(exit_nls_iso8859_13);
    UNLOAD_NLS(exit_nls_iso8859_14);
    UNLOAD_NLS(exit_nls_iso8859_15);
    UNLOAD_NLS(exit_nls_iso8859_2);
    UNLOAD_NLS(exit_nls_iso8859_3);
    UNLOAD_NLS(exit_nls_iso8859_4);
    UNLOAD_NLS(exit_nls_iso8859_5);
    UNLOAD_NLS(exit_nls_iso8859_6);
    UNLOAD_NLS(exit_nls_iso8859_7);
    UNLOAD_NLS(exit_nls_iso8859_8);
    UNLOAD_NLS(exit_nls_iso8859_9);
    UNLOAD_NLS(exit_nls_koi8_r);
    UNLOAD_NLS(exit_nls_koi8_ru);
    UNLOAD_NLS(exit_nls_koi8_u);
    UNLOAD_NLS(exit_nls_sjis);
    UNLOAD_NLS(exit_nls_tis_620);

    //
    // Unloading nls of chinese ...
    //

    UNLOAD_NLS(exit_nls_gb2312);
    UNLOAD_NLS(exit_nls_cp936);

#endif //FULL_CODEPAGES_SUPPORT

    //
    // Unloading nls of utf8 ...
    //

    UNLOAD_NLS(exit_nls_utf8);
}

