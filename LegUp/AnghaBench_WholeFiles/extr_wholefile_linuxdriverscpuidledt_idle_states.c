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
typedef  scalar_t__ u32 ;
struct of_device_id {int /*<<< orphan*/  data; } ;
struct device_node {char* name; } ;
struct cpuidle_state {int /*<<< orphan*/  desc; int /*<<< orphan*/  name; int /*<<< orphan*/  flags; scalar_t__ target_residency; scalar_t__ exit_latency; int /*<<< orphan*/  enter_s2idle; int /*<<< orphan*/  enter; } ;
struct cpuidle_driver {unsigned int state_count; struct cpuidle_state* states; int /*<<< orphan*/  cpumask; } ;
typedef  int /*<<< orphan*/  cpumask_t ;

/* Variables and functions */
 scalar_t__ CPUIDLE_DESC_LEN ; 
 int /*<<< orphan*/  CPUIDLE_FLAG_TIMER_STOP ; 
 scalar_t__ CPUIDLE_NAME_LEN ; 
 unsigned int CPUIDLE_STATE_MAX ; 
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/ * cpu_possible_mask ; 
 int cpumask_first (int /*<<< orphan*/  const*) ; 
 int cpumask_next (int,int /*<<< orphan*/  const*) ; 
 int nr_cpu_ids ; 
 struct device_node* of_cpu_device_node_get (int) ; 
 int /*<<< orphan*/  of_device_is_available (struct device_node*) ; 
 struct of_device_id* of_match_node (struct of_device_id const*,struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_string (struct device_node*,char*,char const**) ; 
 int of_property_read_u32 (struct device_node*,char*,scalar_t__*) ; 
 int /*<<< orphan*/  pr_debug (char*,struct device_node*) ; 
 int /*<<< orphan*/  pr_err (char*,struct device_node*,int) ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  strncpy (int /*<<< orphan*/ ,char const*,scalar_t__) ; 

__attribute__((used)) static int init_state_node(struct cpuidle_state *idle_state,
			   const struct of_device_id *matches,
			   struct device_node *state_node)
{
	int err;
	const struct of_device_id *match_id;
	const char *desc;

	match_id = of_match_node(matches, state_node);
	if (!match_id)
		return -ENODEV;
	/*
	 * CPUidle drivers are expected to initialize the const void *data
	 * pointer of the passed in struct of_device_id array to the idle
	 * state enter function.
	 */
	idle_state->enter = match_id->data;
	/*
	 * Since this is not a "coupled" state, it's safe to assume interrupts
	 * won't be enabled when it exits allowing the tick to be frozen
	 * safely. So enter() can be also enter_s2idle() callback.
	 */
	idle_state->enter_s2idle = match_id->data;

	err = of_property_read_u32(state_node, "wakeup-latency-us",
				   &idle_state->exit_latency);
	if (err) {
		u32 entry_latency, exit_latency;

		err = of_property_read_u32(state_node, "entry-latency-us",
					   &entry_latency);
		if (err) {
			pr_debug(" * %pOF missing entry-latency-us property\n",
				 state_node);
			return -EINVAL;
		}

		err = of_property_read_u32(state_node, "exit-latency-us",
					   &exit_latency);
		if (err) {
			pr_debug(" * %pOF missing exit-latency-us property\n",
				 state_node);
			return -EINVAL;
		}
		/*
		 * If wakeup-latency-us is missing, default to entry+exit
		 * latencies as defined in idle states bindings
		 */
		idle_state->exit_latency = entry_latency + exit_latency;
	}

	err = of_property_read_u32(state_node, "min-residency-us",
				   &idle_state->target_residency);
	if (err) {
		pr_debug(" * %pOF missing min-residency-us property\n",
			     state_node);
		return -EINVAL;
	}

	err = of_property_read_string(state_node, "idle-state-name", &desc);
	if (err)
		desc = state_node->name;

	idle_state->flags = 0;
	if (of_property_read_bool(state_node, "local-timer-stop"))
		idle_state->flags |= CPUIDLE_FLAG_TIMER_STOP;
	/*
	 * TODO:
	 *	replace with kstrdup and pointer assignment when name
	 *	and desc become string pointers
	 */
	strncpy(idle_state->name, state_node->name, CPUIDLE_NAME_LEN - 1);
	strncpy(idle_state->desc, desc, CPUIDLE_DESC_LEN - 1);
	return 0;
}

__attribute__((used)) static bool idle_state_valid(struct device_node *state_node, unsigned int idx,
			     const cpumask_t *cpumask)
{
	int cpu;
	struct device_node *cpu_node, *curr_state_node;
	bool valid = true;

	/*
	 * Compare idle state phandles for index idx on all CPUs in the
	 * CPUidle driver cpumask. Start from next logical cpu following
	 * cpumask_first(cpumask) since that's the CPU state_node was
	 * retrieved from. If a mismatch is found bail out straight
	 * away since we certainly hit a firmware misconfiguration.
	 */
	for (cpu = cpumask_next(cpumask_first(cpumask), cpumask);
	     cpu < nr_cpu_ids; cpu = cpumask_next(cpu, cpumask)) {
		cpu_node = of_cpu_device_node_get(cpu);
		curr_state_node = of_parse_phandle(cpu_node, "cpu-idle-states",
						   idx);
		if (state_node != curr_state_node)
			valid = false;

		of_node_put(curr_state_node);
		of_node_put(cpu_node);
		if (!valid)
			break;
	}

	return valid;
}

int dt_init_idle_driver(struct cpuidle_driver *drv,
			const struct of_device_id *matches,
			unsigned int start_idx)
{
	struct cpuidle_state *idle_state;
	struct device_node *state_node, *cpu_node;
	int i, err = 0;
	const cpumask_t *cpumask;
	unsigned int state_idx = start_idx;

	if (state_idx >= CPUIDLE_STATE_MAX)
		return -EINVAL;
	/*
	 * We get the idle states for the first logical cpu in the
	 * driver mask (or cpu_possible_mask if the driver cpumask is not set)
	 * and we check through idle_state_valid() if they are uniform
	 * across CPUs, otherwise we hit a firmware misconfiguration.
	 */
	cpumask = drv->cpumask ? : cpu_possible_mask;
	cpu_node = of_cpu_device_node_get(cpumask_first(cpumask));

	for (i = 0; ; i++) {
		state_node = of_parse_phandle(cpu_node, "cpu-idle-states", i);
		if (!state_node)
			break;

		if (!of_device_is_available(state_node)) {
			of_node_put(state_node);
			continue;
		}

		if (!idle_state_valid(state_node, i, cpumask)) {
			pr_warn("%pOF idle state not valid, bailing out\n",
				state_node);
			err = -EINVAL;
			break;
		}

		if (state_idx == CPUIDLE_STATE_MAX) {
			pr_warn("State index reached static CPU idle driver states array size\n");
			break;
		}

		idle_state = &drv->states[state_idx++];
		err = init_state_node(idle_state, matches, state_node);
		if (err) {
			pr_err("Parsing idle state node %pOF failed with err %d\n",
			       state_node, err);
			err = -EINVAL;
			break;
		}
		of_node_put(state_node);
	}

	of_node_put(state_node);
	of_node_put(cpu_node);
	if (err)
		return err;
	/*
	 * Update the driver state count only if some valid DT idle states
	 * were detected
	 */
	if (i)
		drv->state_count = state_idx;

	/*
	 * Return the number of present and valid DT idle states, which can
	 * also be 0 on platforms with missing DT idle states or legacy DT
	 * configuration predating the DT idle states bindings.
	 */
	return i;
}

