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
typedef  void* uint32_t ;
struct skynet_monitor {scalar_t__ version; scalar_t__ check_version; void* destination; void* source; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATOM_INC (scalar_t__*) ; 
 int /*<<< orphan*/  memset (struct skynet_monitor*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  skynet_context_endless (void*) ; 
 int /*<<< orphan*/  skynet_error (int /*<<< orphan*/ *,char*,void*,void*,scalar_t__) ; 
 int /*<<< orphan*/  skynet_free (struct skynet_monitor*) ; 
 struct skynet_monitor* skynet_malloc (int) ; 

struct skynet_monitor * 
skynet_monitor_new() {
	struct skynet_monitor * ret = skynet_malloc(sizeof(*ret));
	memset(ret, 0, sizeof(*ret));
	return ret;
}

void 
skynet_monitor_delete(struct skynet_monitor *sm) {
	skynet_free(sm);
}

void 
skynet_monitor_trigger(struct skynet_monitor *sm, uint32_t source, uint32_t destination) {
	sm->source = source;
	sm->destination = destination;
	ATOM_INC(&sm->version);
}

void 
skynet_monitor_check(struct skynet_monitor *sm) {
	if (sm->version == sm->check_version) {
		if (sm->destination) {
			skynet_context_endless(sm->destination);
			skynet_error(NULL, "A message from [ :%08x ] to [ :%08x ] maybe in an endless loop (version = %d)", sm->source , sm->destination, sm->version);
		}
	} else {
		sm->check_version = sm->version;
	}
}

