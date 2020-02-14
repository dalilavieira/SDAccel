#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {scalar_t__ funct_ref; int (* init ) (TYPE_1__*) ;int (* finish ) (TYPE_1__*) ;int /*<<< orphan*/  struct_ref; } ;
typedef  TYPE_1__ ENGINE ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_THREAD_unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRYPTO_THREAD_write_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENGINE_F_ENGINE_FINISH ; 
 int /*<<< orphan*/  ENGINE_F_ENGINE_INIT ; 
 int /*<<< orphan*/  ENGINE_F_ENGINE_UNLOCKED_FINISH ; 
 int /*<<< orphan*/  ENGINE_R_FINISH_FAILED ; 
 int /*<<< orphan*/  ENGINEerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  ERR_R_PASSED_NULL_PARAMETER ; 
 int /*<<< orphan*/  REF_ASSERT_ISNT (int) ; 
 int /*<<< orphan*/  RUN_ONCE (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_engine_lock_init ; 
 int /*<<< orphan*/  engine_free_util (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  engine_lock_init ; 
 int /*<<< orphan*/  engine_ref_debug (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  global_engine_lock ; 
 int stub1 (TYPE_1__*) ; 
 int stub2 (TYPE_1__*) ; 

int engine_unlocked_init(ENGINE *e)
{
    int to_return = 1;

    if ((e->funct_ref == 0) && e->init)
        /*
         * This is the first functional reference and the engine requires
         * initialisation so we do it now.
         */
        to_return = e->init(e);
    if (to_return) {
        /*
         * OK, we return a functional reference which is also a structural
         * reference.
         */
        e->struct_ref++;
        e->funct_ref++;
        engine_ref_debug(e, 0, 1);
        engine_ref_debug(e, 1, 1);
    }
    return to_return;
}

int engine_unlocked_finish(ENGINE *e, int unlock_for_handlers)
{
    int to_return = 1;

    /*
     * Reduce the functional reference count here so if it's the terminating
     * case, we can release the lock safely and call the finish() handler
     * without risk of a race. We get a race if we leave the count until
     * after and something else is calling "finish" at the same time -
     * there's a chance that both threads will together take the count from 2
     * to 0 without either calling finish().
     */
    e->funct_ref--;
    engine_ref_debug(e, 1, -1);
    if ((e->funct_ref == 0) && e->finish) {
        if (unlock_for_handlers)
            CRYPTO_THREAD_unlock(global_engine_lock);
        to_return = e->finish(e);
        if (unlock_for_handlers)
            CRYPTO_THREAD_write_lock(global_engine_lock);
        if (!to_return)
            return 0;
    }
    REF_ASSERT_ISNT(e->funct_ref < 0);
    /* Release the structural reference too */
    if (!engine_free_util(e, 0)) {
        ENGINEerr(ENGINE_F_ENGINE_UNLOCKED_FINISH, ENGINE_R_FINISH_FAILED);
        return 0;
    }
    return to_return;
}

int ENGINE_init(ENGINE *e)
{
    int ret;
    if (e == NULL) {
        ENGINEerr(ENGINE_F_ENGINE_INIT, ERR_R_PASSED_NULL_PARAMETER);
        return 0;
    }
    if (!RUN_ONCE(&engine_lock_init, do_engine_lock_init)) {
        ENGINEerr(ENGINE_F_ENGINE_INIT, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    CRYPTO_THREAD_write_lock(global_engine_lock);
    ret = engine_unlocked_init(e);
    CRYPTO_THREAD_unlock(global_engine_lock);
    return ret;
}

int ENGINE_finish(ENGINE *e)
{
    int to_return = 1;

    if (e == NULL)
        return 1;
    CRYPTO_THREAD_write_lock(global_engine_lock);
    to_return = engine_unlocked_finish(e, 1);
    CRYPTO_THREAD_unlock(global_engine_lock);
    if (!to_return) {
        ENGINEerr(ENGINE_F_ENGINE_FINISH, ENGINE_R_FINISH_FAILED);
        return 0;
    }
    return to_return;
}

