#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int example_hashes; int keyspace; int left; int opencl_info; int show; int usage; int version; } ;
typedef  TYPE_1__ user_options_t ;
struct TYPE_11__ {TYPE_3__* cpt_ctx; TYPE_1__* user_options; } ;
typedef  TYPE_2__ hashcat_ctx_t ;
struct TYPE_12__ {int enabled; void* cpt_start; scalar_t__ cpt_pos; scalar_t__ cpt_total; struct TYPE_12__* cpt_buf; } ;
typedef  TYPE_3__ cpt_t ;
typedef  TYPE_3__ cpt_ctx_t ;

/* Variables and functions */
 int CPT_CACHE ; 
 scalar_t__ hccalloc (int,int) ; 
 int /*<<< orphan*/  hcfree (TYPE_3__*) ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 void* time (int /*<<< orphan*/ *) ; 

int cpt_ctx_init (hashcat_ctx_t *hashcat_ctx)
{
  cpt_ctx_t      *cpt_ctx      = hashcat_ctx->cpt_ctx;
  user_options_t *user_options = hashcat_ctx->user_options;

  cpt_ctx->enabled = false;

  if (user_options->example_hashes == true) return 0;
  if (user_options->keyspace       == true) return 0;
  if (user_options->left           == true) return 0;
  if (user_options->opencl_info    == true) return 0;
  if (user_options->show           == true) return 0;
  if (user_options->usage          == true) return 0;
  if (user_options->version        == true) return 0;

  cpt_ctx->enabled = true;

  cpt_ctx->cpt_buf = (cpt_t *) hccalloc (CPT_CACHE, sizeof (cpt_t));

  cpt_ctx->cpt_total = 0;
  cpt_ctx->cpt_pos   = 0;
  cpt_ctx->cpt_start = time (NULL);

  return 0;
}

void cpt_ctx_destroy (hashcat_ctx_t *hashcat_ctx)
{
  cpt_ctx_t *cpt_ctx = hashcat_ctx->cpt_ctx;

  if (cpt_ctx->enabled == false) return;

  hcfree (cpt_ctx->cpt_buf);

  memset (cpt_ctx, 0, sizeof (cpt_ctx_t));
}

void cpt_ctx_reset (hashcat_ctx_t *hashcat_ctx)
{
  cpt_ctx_t *cpt_ctx = hashcat_ctx->cpt_ctx;

  if (cpt_ctx->enabled == false) return;

  memset (cpt_ctx->cpt_buf, 0, CPT_CACHE * sizeof (cpt_t));

  cpt_ctx->cpt_total = 0;
  cpt_ctx->cpt_pos   = 0;
  cpt_ctx->cpt_start = time (NULL);
}

