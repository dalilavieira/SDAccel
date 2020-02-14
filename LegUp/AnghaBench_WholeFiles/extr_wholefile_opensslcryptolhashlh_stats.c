#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {unsigned int num_nodes; TYPE_1__** b; int /*<<< orphan*/  num_hash_comps; int /*<<< orphan*/  num_retrieve_miss; int /*<<< orphan*/  num_retrieve; int /*<<< orphan*/  num_no_delete; int /*<<< orphan*/  num_delete; int /*<<< orphan*/  num_replace; int /*<<< orphan*/  num_insert; int /*<<< orphan*/  num_comp_calls; int /*<<< orphan*/  num_hash_calls; int /*<<< orphan*/  num_contract_reallocs; int /*<<< orphan*/  num_contracts; int /*<<< orphan*/  num_expand_reallocs; int /*<<< orphan*/  num_expands; int /*<<< orphan*/  num_alloc_nodes; int /*<<< orphan*/  num_items; } ;
struct TYPE_9__ {struct TYPE_9__* next; } ;
typedef  TYPE_1__ OPENSSL_LH_NODE ;
typedef  TYPE_2__ OPENSSL_LHASH ;
typedef  int /*<<< orphan*/  FILE ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_NOCLOSE ; 
 int /*<<< orphan*/  BIO_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * BIO_new (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_printf (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  BIO_s_file () ; 
 int /*<<< orphan*/  BIO_set_fp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 void OPENSSL_LH_node_stats_bio (TYPE_2__ const*,int /*<<< orphan*/ *) ; 
 void OPENSSL_LH_node_usage_stats_bio (TYPE_2__ const*,int /*<<< orphan*/ *) ; 
 void OPENSSL_LH_stats_bio (TYPE_2__ const*,int /*<<< orphan*/ *) ; 

void OPENSSL_LH_stats(const OPENSSL_LHASH *lh, FILE *fp)
{
    BIO *bp;

    bp = BIO_new(BIO_s_file());
    if (bp == NULL)
        return;
    BIO_set_fp(bp, fp, BIO_NOCLOSE);
    OPENSSL_LH_stats_bio(lh, bp);
    BIO_free(bp);
}

void OPENSSL_LH_node_stats(const OPENSSL_LHASH *lh, FILE *fp)
{
    BIO *bp;

    bp = BIO_new(BIO_s_file());
    if (bp == NULL)
        return;
    BIO_set_fp(bp, fp, BIO_NOCLOSE);
    OPENSSL_LH_node_stats_bio(lh, bp);
    BIO_free(bp);
}

void OPENSSL_LH_node_usage_stats(const OPENSSL_LHASH *lh, FILE *fp)
{
    BIO *bp;

    bp = BIO_new(BIO_s_file());
    if (bp == NULL)
        return;
    BIO_set_fp(bp, fp, BIO_NOCLOSE);
    OPENSSL_LH_node_usage_stats_bio(lh, bp);
    BIO_free(bp);
}

void OPENSSL_LH_stats_bio(const OPENSSL_LHASH *lh, BIO *out)
{
    BIO_printf(out, "num_items             = %lu\n", lh->num_items);
    BIO_printf(out, "num_nodes             = %u\n",  lh->num_nodes);
    BIO_printf(out, "num_alloc_nodes       = %u\n",  lh->num_alloc_nodes);
    BIO_printf(out, "num_expands           = %lu\n", lh->num_expands);
    BIO_printf(out, "num_expand_reallocs   = %lu\n", lh->num_expand_reallocs);
    BIO_printf(out, "num_contracts         = %lu\n", lh->num_contracts);
    BIO_printf(out, "num_contract_reallocs = %lu\n", lh->num_contract_reallocs);
    BIO_printf(out, "num_hash_calls        = %lu\n", lh->num_hash_calls);
    BIO_printf(out, "num_comp_calls        = %lu\n", lh->num_comp_calls);
    BIO_printf(out, "num_insert            = %lu\n", lh->num_insert);
    BIO_printf(out, "num_replace           = %lu\n", lh->num_replace);
    BIO_printf(out, "num_delete            = %lu\n", lh->num_delete);
    BIO_printf(out, "num_no_delete         = %lu\n", lh->num_no_delete);
    BIO_printf(out, "num_retrieve          = %lu\n", lh->num_retrieve);
    BIO_printf(out, "num_retrieve_miss     = %lu\n", lh->num_retrieve_miss);
    BIO_printf(out, "num_hash_comps        = %lu\n", lh->num_hash_comps);
}

void OPENSSL_LH_node_stats_bio(const OPENSSL_LHASH *lh, BIO *out)
{
    OPENSSL_LH_NODE *n;
    unsigned int i, num;

    for (i = 0; i < lh->num_nodes; i++) {
        for (n = lh->b[i], num = 0; n != NULL; n = n->next)
            num++;
        BIO_printf(out, "node %6u -> %3u\n", i, num);
    }
}

void OPENSSL_LH_node_usage_stats_bio(const OPENSSL_LHASH *lh, BIO *out)
{
    OPENSSL_LH_NODE *n;
    unsigned long num;
    unsigned int i;
    unsigned long total = 0, n_used = 0;

    for (i = 0; i < lh->num_nodes; i++) {
        for (n = lh->b[i], num = 0; n != NULL; n = n->next)
            num++;
        if (num != 0) {
            n_used++;
            total += num;
        }
    }
    BIO_printf(out, "%lu nodes used out of %u\n", n_used, lh->num_nodes);
    BIO_printf(out, "%lu items\n", total);
    if (n_used == 0)
        return;
    BIO_printf(out, "load %d.%02d  actual load %d.%02d\n",
               (int)(total / lh->num_nodes),
               (int)((total % lh->num_nodes) * 100 / lh->num_nodes),
               (int)(total / n_used), (int)((total % n_used) * 100 / n_used));
}

