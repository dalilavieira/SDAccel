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
struct TYPE_2__ {int /*<<< orphan*/  b_data; } ;
struct fileinfo {TYPE_1__ info; } ;

/* Variables and functions */
 int /*<<< orphan*/  Curl_safefree (int /*<<< orphan*/ ) ; 
 struct fileinfo* calloc (int,int) ; 
 int /*<<< orphan*/  free (struct fileinfo*) ; 

struct fileinfo *Curl_fileinfo_alloc(void)
{
  return calloc(1, sizeof(struct fileinfo));
}

void Curl_fileinfo_cleanup(struct fileinfo *finfo)
{
  if(!finfo)
    return;

  Curl_safefree(finfo->info.b_data);
  free(finfo);
}

