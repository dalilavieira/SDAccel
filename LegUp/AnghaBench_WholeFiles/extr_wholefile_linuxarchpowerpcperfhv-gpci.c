#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  size_t u64 ;
typedef  size_t u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_10__ {scalar_t__ type; scalar_t__ exclude_guest; scalar_t__ exclude_host; scalar_t__ exclude_idle; scalar_t__ exclude_hv; scalar_t__ exclude_kernel; scalar_t__ exclude_user; scalar_t__ config2; } ;
struct TYPE_8__ {int /*<<< orphan*/  prev_count; } ;
struct perf_event {TYPE_4__ attr; TYPE_3__* pmu; TYPE_2__ hw; int /*<<< orphan*/  count; } ;
struct hv_perf_caps {int dummy; } ;
struct TYPE_7__ {size_t counter_info_version_in; int /*<<< orphan*/  secondary_index; void* starting_index; void* counter_request; } ;
struct hv_gpci_request_buffer {size_t* bytes; TYPE_1__ params; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  size_t s64 ;
struct TYPE_11__ {int /*<<< orphan*/  name; int /*<<< orphan*/  capabilities; } ;
struct TYPE_9__ {scalar_t__ type; } ;

/* Variables and functions */
 int COUNTER_INFO_VERSION_CURRENT ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  FW_FEATURE_LPAR ; 
 scalar_t__ HGPCI_MAX_DATA_BYTES ; 
 int /*<<< orphan*/  HGPCI_REQ_BUFFER_SIZE ; 
 int /*<<< orphan*/  H_GET_PERF_COUNTER_INFO ; 
 int PERF_EF_START ; 
 int /*<<< orphan*/  PERF_PMU_CAP_NO_INTERRUPT ; 
 int /*<<< orphan*/  cpu_to_be16 (int /*<<< orphan*/ ) ; 
 void* cpu_to_be32 (size_t) ; 
 size_t event_get_counter_info_version (struct perf_event*) ; 
 size_t event_get_length (struct perf_event*) ; 
 scalar_t__ event_get_offset (struct perf_event*) ; 
 size_t event_get_request (struct perf_event*) ; 
 int /*<<< orphan*/  event_get_secondary_index (struct perf_event*) ; 
 size_t event_get_starting_index (struct perf_event*) ; 
 int /*<<< orphan*/  firmware_has_feature (int /*<<< orphan*/ ) ; 
 scalar_t__ get_cpu_var (int /*<<< orphan*/ ) ; 
 TYPE_5__ h_gpci_pmu ; 
 scalar_t__ has_branch_stack (struct perf_event*) ; 
 int /*<<< orphan*/  hv_gpci_assert_offsets_correct () ; 
 int /*<<< orphan*/  hv_gpci_reqb ; 
 unsigned long hv_perf_caps_get (struct hv_perf_caps*) ; 
 int /*<<< orphan*/  local64_add (size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  local64_set (int /*<<< orphan*/ *,size_t) ; 
 size_t local64_xchg (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  memset (struct hv_gpci_request_buffer*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int perf_pmu_register (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 unsigned long plpar_hcall_norets (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_devel (char*,...) ; 
 int /*<<< orphan*/  put_cpu_var (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  virt_to_phys (struct hv_gpci_request_buffer*) ; 

__attribute__((used)) static ssize_t kernel_version_show(struct device *dev,
				   struct device_attribute *attr,
				   char *page)
{
	return sprintf(page, "0x%x\n", COUNTER_INFO_VERSION_CURRENT);
}

__attribute__((used)) static unsigned long single_gpci_request(u32 req, u32 starting_index,
		u16 secondary_index, u8 version_in, u32 offset, u8 length,
		u64 *value)
{
	unsigned long ret;
	size_t i;
	u64 count;
	struct hv_gpci_request_buffer *arg;

	arg = (void *)get_cpu_var(hv_gpci_reqb);
	memset(arg, 0, HGPCI_REQ_BUFFER_SIZE);

	arg->params.counter_request = cpu_to_be32(req);
	arg->params.starting_index = cpu_to_be32(starting_index);
	arg->params.secondary_index = cpu_to_be16(secondary_index);
	arg->params.counter_info_version_in = version_in;

	ret = plpar_hcall_norets(H_GET_PERF_COUNTER_INFO,
			virt_to_phys(arg), HGPCI_REQ_BUFFER_SIZE);
	if (ret) {
		pr_devel("hcall failed: 0x%lx\n", ret);
		goto out;
	}

	/*
	 * we verify offset and length are within the zeroed buffer at event
	 * init.
	 */
	count = 0;
	for (i = offset; i < offset + length; i++)
		count |= arg->bytes[i] << (i - offset);

	*value = count;
out:
	put_cpu_var(hv_gpci_reqb);
	return ret;
}

__attribute__((used)) static u64 h_gpci_get_value(struct perf_event *event)
{
	u64 count;
	unsigned long ret = single_gpci_request(event_get_request(event),
					event_get_starting_index(event),
					event_get_secondary_index(event),
					event_get_counter_info_version(event),
					event_get_offset(event),
					event_get_length(event),
					&count);
	if (ret)
		return 0;
	return count;
}

__attribute__((used)) static void h_gpci_event_update(struct perf_event *event)
{
	s64 prev;
	u64 now = h_gpci_get_value(event);
	prev = local64_xchg(&event->hw.prev_count, now);
	local64_add(now - prev, &event->count);
}

__attribute__((used)) static void h_gpci_event_start(struct perf_event *event, int flags)
{
	local64_set(&event->hw.prev_count, h_gpci_get_value(event));
}

__attribute__((used)) static void h_gpci_event_stop(struct perf_event *event, int flags)
{
	h_gpci_event_update(event);
}

__attribute__((used)) static int h_gpci_event_add(struct perf_event *event, int flags)
{
	if (flags & PERF_EF_START)
		h_gpci_event_start(event, flags);

	return 0;
}

__attribute__((used)) static int h_gpci_event_init(struct perf_event *event)
{
	u64 count;
	u8 length;

	/* Not our event */
	if (event->attr.type != event->pmu->type)
		return -ENOENT;

	/* config2 is unused */
	if (event->attr.config2) {
		pr_devel("config2 set when reserved\n");
		return -EINVAL;
	}

	/* unsupported modes and filters */
	if (event->attr.exclude_user   ||
	    event->attr.exclude_kernel ||
	    event->attr.exclude_hv     ||
	    event->attr.exclude_idle   ||
	    event->attr.exclude_host   ||
	    event->attr.exclude_guest)
		return -EINVAL;

	/* no branch sampling */
	if (has_branch_stack(event))
		return -EOPNOTSUPP;

	length = event_get_length(event);
	if (length < 1 || length > 8) {
		pr_devel("length invalid\n");
		return -EINVAL;
	}

	/* last byte within the buffer? */
	if ((event_get_offset(event) + length) > HGPCI_MAX_DATA_BYTES) {
		pr_devel("request outside of buffer: %zu > %zu\n",
				(size_t)event_get_offset(event) + length,
				HGPCI_MAX_DATA_BYTES);
		return -EINVAL;
	}

	/* check if the request works... */
	if (single_gpci_request(event_get_request(event),
				event_get_starting_index(event),
				event_get_secondary_index(event),
				event_get_counter_info_version(event),
				event_get_offset(event),
				length,
				&count)) {
		pr_devel("gpci hcall failed\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int hv_gpci_init(void)
{
	int r;
	unsigned long hret;
	struct hv_perf_caps caps;

	hv_gpci_assert_offsets_correct();

	if (!firmware_has_feature(FW_FEATURE_LPAR)) {
		pr_debug("not a virtualized system, not enabling\n");
		return -ENODEV;
	}

	hret = hv_perf_caps_get(&caps);
	if (hret) {
		pr_debug("could not obtain capabilities, not enabling, rc=%ld\n",
				hret);
		return -ENODEV;
	}

	/* sampling not supported */
	h_gpci_pmu.capabilities |= PERF_PMU_CAP_NO_INTERRUPT;

	r = perf_pmu_register(&h_gpci_pmu, h_gpci_pmu.name, -1);
	if (r)
		return r;

	return 0;
}

