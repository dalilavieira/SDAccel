#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct blkcg {int dummy; } ;
struct bio {int dummy; } ;
struct bfq_queue {TYPE_1__* bfqd; int /*<<< orphan*/  new_ioprio_class; int /*<<< orphan*/  ioprio_class; int /*<<< orphan*/  new_ioprio; int /*<<< orphan*/  ioprio; } ;
struct bfq_io_cq {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/ * service_tree; } ;
struct bfq_group {TYPE_2__ sched_data; } ;
struct bfq_entity {TYPE_2__* sched_data; int /*<<< orphan*/  new_weight; int /*<<< orphan*/  orig_weight; int /*<<< orphan*/  weight; } ;
struct bfq_data {struct bfq_group* root_group; } ;
struct TYPE_3__ {struct bfq_group* root_group; } ;

/* Variables and functions */
 int BFQ_IOPRIO_CLASSES ; 
 int /*<<< orphan*/  BFQ_SERVICE_TREE_INIT ; 
 int GFP_KERNEL ; 
 int __GFP_ZERO ; 
 int /*<<< orphan*/  bfq_end_wr_async_queues (struct bfq_data*,struct bfq_group*) ; 
 struct bfq_queue* bfq_entity_to_bfqq (struct bfq_entity*) ; 
 struct bfq_group* kmalloc_node (int,int,int) ; 

void bfqg_stats_update_io_add(struct bfq_group *bfqg, struct bfq_queue *bfqq,
			      unsigned int op) { }

void bfqg_stats_update_io_remove(struct bfq_group *bfqg, unsigned int op) { }

void bfqg_stats_update_io_merged(struct bfq_group *bfqg, unsigned int op) { }

void bfqg_stats_update_completion(struct bfq_group *bfqg, u64 start_time_ns,
				  u64 io_start_time_ns, unsigned int op) { }

void bfqg_stats_update_dequeue(struct bfq_group *bfqg) { }

void bfqg_stats_set_start_empty_time(struct bfq_group *bfqg) { }

void bfqg_stats_update_idle_time(struct bfq_group *bfqg) { }

void bfqg_stats_set_start_idle_time(struct bfq_group *bfqg) { }

void bfqg_stats_update_avg_queue_size(struct bfq_group *bfqg) { }

void bfq_bfqq_move(struct bfq_data *bfqd, struct bfq_queue *bfqq,
		   struct bfq_group *bfqg) {}

void bfq_init_entity(struct bfq_entity *entity, struct bfq_group *bfqg)
{
	struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);

	entity->weight = entity->new_weight;
	entity->orig_weight = entity->new_weight;
	if (bfqq) {
		bfqq->ioprio = bfqq->new_ioprio;
		bfqq->ioprio_class = bfqq->new_ioprio_class;
	}
	entity->sched_data = &bfqg->sched_data;
}

void bfq_bic_update_cgroup(struct bfq_io_cq *bic, struct bio *bio) {}

void bfq_end_wr_async(struct bfq_data *bfqd)
{
	bfq_end_wr_async_queues(bfqd, bfqd->root_group);
}

struct bfq_group *bfq_find_set_group(struct bfq_data *bfqd, struct blkcg *blkcg)
{
	return bfqd->root_group;
}

struct bfq_group *bfqq_group(struct bfq_queue *bfqq)
{
	return bfqq->bfqd->root_group;
}

struct bfq_group *bfq_create_group_hierarchy(struct bfq_data *bfqd, int node)
{
	struct bfq_group *bfqg;
	int i;

	bfqg = kmalloc_node(sizeof(*bfqg), GFP_KERNEL | __GFP_ZERO, node);
	if (!bfqg)
		return NULL;

	for (i = 0; i < BFQ_IOPRIO_CLASSES; i++)
		bfqg->sched_data.service_tree[i] = BFQ_SERVICE_TREE_INIT;

	return bfqg;
}

