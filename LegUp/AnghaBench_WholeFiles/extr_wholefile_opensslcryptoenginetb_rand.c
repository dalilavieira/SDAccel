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
struct TYPE_14__ {int /*<<< orphan*/  const* rand_meth; } ;
typedef  int /*<<< orphan*/  RAND_METHOD ;
typedef  TYPE_1__ ENGINE ;

/* Variables and functions */
 TYPE_1__* ENGINE_get_first () ; 
 TYPE_1__* ENGINE_get_next (TYPE_1__*) ; 
 int /*<<< orphan*/  dummy_nid ; 
 int /*<<< orphan*/  engine_table_cleanup (int /*<<< orphan*/ *) ; 
 int engine_table_register (int /*<<< orphan*/ *,void (*) (),TYPE_1__*,int /*<<< orphan*/ *,int,int) ; 
 TYPE_1__* engine_table_select (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  engine_table_unregister (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  rand_table ; 

void ENGINE_unregister_RAND(ENGINE *e)
{
    engine_table_unregister(&rand_table, e);
}

__attribute__((used)) static void engine_unregister_all_RAND(void)
{
    engine_table_cleanup(&rand_table);
}

int ENGINE_register_RAND(ENGINE *e)
{
    if (e->rand_meth)
        return engine_table_register(&rand_table,
                                     engine_unregister_all_RAND, e,
                                     &dummy_nid, 1, 0);
    return 1;
}

void ENGINE_register_all_RAND(void)
{
    ENGINE *e;

    for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
        ENGINE_register_RAND(e);
}

int ENGINE_set_default_RAND(ENGINE *e)
{
    if (e->rand_meth)
        return engine_table_register(&rand_table,
                                     engine_unregister_all_RAND, e,
                                     &dummy_nid, 1, 1);
    return 1;
}

ENGINE *ENGINE_get_default_RAND(void)
{
    return engine_table_select(&rand_table, dummy_nid);
}

const RAND_METHOD *ENGINE_get_RAND(const ENGINE *e)
{
    return e->rand_meth;
}

int ENGINE_set_RAND(ENGINE *e, const RAND_METHOD *rand_meth)
{
    e->rand_meth = rand_meth;
    return 1;
}

