#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int /*<<< orphan*/  const* ec_meth; } ;
typedef  TYPE_1__ ENGINE ;
typedef  int /*<<< orphan*/  EC_KEY_METHOD ;

/* Variables and functions */
 TYPE_1__* ENGINE_get_first () ; 
 TYPE_1__* ENGINE_get_next (TYPE_1__*) ; 
 int /*<<< orphan*/  dh_table ; 
 int /*<<< orphan*/  dummy_nid ; 
 int /*<<< orphan*/  engine_table_cleanup (int /*<<< orphan*/ *) ; 
 int engine_table_register (int /*<<< orphan*/ *,void (*) (),TYPE_1__*,int /*<<< orphan*/ *,int,int) ; 
 TYPE_1__* engine_table_select (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  engine_table_unregister (int /*<<< orphan*/ *,TYPE_1__*) ; 

void ENGINE_unregister_EC(ENGINE *e)
{
    engine_table_unregister(&dh_table, e);
}

__attribute__((used)) static void engine_unregister_all_EC(void)
{
    engine_table_cleanup(&dh_table);
}

int ENGINE_register_EC(ENGINE *e)
{
    if (e->ec_meth != NULL)
        return engine_table_register(&dh_table,
                                     engine_unregister_all_EC, e, &dummy_nid,
                                     1, 0);
    return 1;
}

void ENGINE_register_all_EC(void)
{
    ENGINE *e;

    for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
        ENGINE_register_EC(e);
}

int ENGINE_set_default_EC(ENGINE *e)
{
    if (e->ec_meth != NULL)
        return engine_table_register(&dh_table,
                                     engine_unregister_all_EC, e, &dummy_nid,
                                     1, 1);
    return 1;
}

ENGINE *ENGINE_get_default_EC(void)
{
    return engine_table_select(&dh_table, dummy_nid);
}

const EC_KEY_METHOD *ENGINE_get_EC(const ENGINE *e)
{
    return e->ec_meth;
}

int ENGINE_set_EC(ENGINE *e, const EC_KEY_METHOD *ec_meth)
{
    e->ec_meth = ec_meth;
    return 1;
}

