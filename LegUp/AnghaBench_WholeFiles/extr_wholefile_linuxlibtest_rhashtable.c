#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct test_obj_val {int id; } ;
struct TYPE_2__ {int id; } ;
struct test_obj_rhl {TYPE_1__ value; } ;
struct test_obj {int /*<<< orphan*/  node; } ;
struct rhashtable_params {int dummy; } ;
struct rhashtable_compare_arg {struct test_obj_val* key; } ;
struct rhashtable {int dummy; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  cond_resched () ; 
 scalar_t__ enomem_retry ; 
 int /*<<< orphan*/  pr_info (char*,int) ; 
 int rhashtable_insert_fast (struct rhashtable*,int /*<<< orphan*/ *,struct rhashtable_params const) ; 

__attribute__((used)) static u32 my_hashfn(const void *data, u32 len, u32 seed)
{
	const struct test_obj_rhl *obj = data;

	return (obj->value.id % 10);
}

__attribute__((used)) static int my_cmpfn(struct rhashtable_compare_arg *arg, const void *obj)
{
	const struct test_obj_rhl *test_obj = obj;
	const struct test_obj_val *val = arg->key;

	return test_obj->value.id - val->id;
}

__attribute__((used)) static int insert_retry(struct rhashtable *ht, struct test_obj *obj,
                        const struct rhashtable_params params)
{
	int err, retries = -1, enomem_retries = 0;

	do {
		retries++;
		cond_resched();
		err = rhashtable_insert_fast(ht, &obj->node, params);
		if (err == -ENOMEM && enomem_retry) {
			enomem_retries++;
			err = -EBUSY;
		}
	} while (err == -EBUSY);

	if (enomem_retries)
		pr_info(" %u insertions retried after -ENOMEM\n",
			enomem_retries);

	return err ? : retries;
}

