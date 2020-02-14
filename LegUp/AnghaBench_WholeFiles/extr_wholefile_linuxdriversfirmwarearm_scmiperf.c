#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_8__ {struct scmi_perf_get_limits* buf; } ;
struct TYPE_7__ {struct scmi_perf_set_limits* buf; } ;
struct TYPE_6__ {int poll_completion; } ;
struct scmi_xfer {TYPE_4__ rx; TYPE_3__ tx; TYPE_2__ hdr; } ;
struct scmi_perf_set_limits {void* level; void* domain; void* min_level; void* max_level; void* level_index; } ;
struct scmi_perf_set_level {void* level; void* domain; void* min_level; void* max_level; void* level_index; } ;
struct scmi_perf_info {int num_domains; int stats_addr; int stats_size; struct perf_dom_info* dom_info; int /*<<< orphan*/  power_scale_mw; } ;
struct scmi_perf_get_limits {void* min_level; void* max_level; TYPE_1__* opp; void* num_remaining; void* num_returned; int /*<<< orphan*/  name; void* sustained_perf_level; void* sustained_freq_khz; void* flags; void* stats_size; void* stats_addr_high; void* stats_addr_low; void* num_domains; } ;
struct scmi_opp {int perf; int power; int trans_latency_us; } ;
struct scmi_msg_resp_perf_domain_attributes {void* min_level; void* max_level; TYPE_1__* opp; void* num_remaining; void* num_returned; int /*<<< orphan*/  name; void* sustained_perf_level; void* sustained_freq_khz; void* flags; void* stats_size; void* stats_addr_high; void* stats_addr_low; void* num_domains; } ;
struct scmi_msg_resp_perf_describe_levels {void* min_level; void* max_level; TYPE_1__* opp; void* num_remaining; void* num_returned; int /*<<< orphan*/  name; void* sustained_perf_level; void* sustained_freq_khz; void* flags; void* stats_size; void* stats_addr_high; void* stats_addr_low; void* num_domains; } ;
struct scmi_msg_resp_perf_attributes {void* min_level; void* max_level; TYPE_1__* opp; void* num_remaining; void* num_returned; int /*<<< orphan*/  name; void* sustained_perf_level; void* sustained_freq_khz; void* flags; void* stats_size; void* stats_addr_high; void* stats_addr_low; void* num_domains; } ;
struct scmi_msg_perf_describe_levels {void* level; void* domain; void* min_level; void* max_level; void* level_index; } ;
struct scmi_handle {struct scmi_perf_info* perf_priv; int /*<<< orphan*/ * perf_ops; int /*<<< orphan*/  dev; } ;
struct perf_dom_info {int sustained_freq_khz; int sustained_perf_level; int mult_factor; int opp_count; struct scmi_opp* opp; int /*<<< orphan*/  name; int /*<<< orphan*/  perf_level_notify; int /*<<< orphan*/  perf_limit_notify; int /*<<< orphan*/  set_perf; int /*<<< orphan*/  set_limits; } ;
struct of_phandle_args {int* args; } ;
struct device {int /*<<< orphan*/  of_node; } ;
typedef  int /*<<< orphan*/  domain ;
typedef  void* __le32 ;
struct TYPE_5__ {void* transition_latency_us; void* power; void* perf_val; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ MAX_OPPS ; 
 int /*<<< orphan*/  PERF_DESCRIBE_LEVELS ; 
 int /*<<< orphan*/  PERF_DOMAIN_ATTRIBUTES ; 
 int /*<<< orphan*/  PERF_LEVEL_GET ; 
 int /*<<< orphan*/  PERF_LEVEL_SET ; 
 int /*<<< orphan*/  PERF_LIMITS_GET ; 
 int /*<<< orphan*/  PERF_LIMITS_SET ; 
 int /*<<< orphan*/  POWER_SCALE_IN_MILLIWATT (scalar_t__) ; 
 int /*<<< orphan*/  PROTOCOL_ATTRIBUTES ; 
 int /*<<< orphan*/  PROTOCOL_REV_MAJOR (scalar_t__) ; 
 int /*<<< orphan*/  PROTOCOL_REV_MINOR (scalar_t__) ; 
 int /*<<< orphan*/  SCMI_MAX_STR_SIZE ; 
 int /*<<< orphan*/  SCMI_PROTOCOL_PERF ; 
 int /*<<< orphan*/  SUPPORTS_PERF_LEVEL_NOTIFY (scalar_t__) ; 
 int /*<<< orphan*/  SUPPORTS_PERF_LIMIT_NOTIFY (scalar_t__) ; 
 int /*<<< orphan*/  SUPPORTS_SET_LIMITS (scalar_t__) ; 
 int /*<<< orphan*/  SUPPORTS_SET_PERF_LVL (scalar_t__) ; 
 void* cpu_to_le32 (scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,int,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int dev_pm_opp_add (struct device*,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_pm_opp_remove (struct device*,unsigned long) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,unsigned long) ; 
 struct perf_dom_info* devm_kcalloc (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 struct scmi_perf_info* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ le16_to_cpu (void*) ; 
 int le32_to_cpu (void*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ of_parse_phandle_with_args (int /*<<< orphan*/ ,char*,char*,int /*<<< orphan*/ ,struct of_phandle_args*) ; 
 int /*<<< orphan*/  perf_ops ; 
 int scmi_do_xfer (struct scmi_handle const*,struct scmi_xfer*) ; 
 int /*<<< orphan*/  scmi_version_get (struct scmi_handle*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int scmi_xfer_get_init (struct scmi_handle const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,struct scmi_xfer**) ; 
 int /*<<< orphan*/  scmi_xfer_put (struct scmi_handle const*,struct scmi_xfer*) ; 
 int /*<<< orphan*/  sort (struct scmi_opp*,scalar_t__,int,int (*) (void const*,void const*),int /*<<< orphan*/ *) ; 

__attribute__((used)) static int scmi_perf_attributes_get(const struct scmi_handle *handle,
				    struct scmi_perf_info *pi)
{
	int ret;
	struct scmi_xfer *t;
	struct scmi_msg_resp_perf_attributes *attr;

	ret = scmi_xfer_get_init(handle, PROTOCOL_ATTRIBUTES,
				 SCMI_PROTOCOL_PERF, 0, sizeof(*attr), &t);
	if (ret)
		return ret;

	attr = t->rx.buf;

	ret = scmi_do_xfer(handle, t);
	if (!ret) {
		u16 flags = le16_to_cpu(attr->flags);

		pi->num_domains = le16_to_cpu(attr->num_domains);
		pi->power_scale_mw = POWER_SCALE_IN_MILLIWATT(flags);
		pi->stats_addr = le32_to_cpu(attr->stats_addr_low) |
				(u64)le32_to_cpu(attr->stats_addr_high) << 32;
		pi->stats_size = le32_to_cpu(attr->stats_size);
	}

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int
scmi_perf_domain_attributes_get(const struct scmi_handle *handle, u32 domain,
				struct perf_dom_info *dom_info)
{
	int ret;
	struct scmi_xfer *t;
	struct scmi_msg_resp_perf_domain_attributes *attr;

	ret = scmi_xfer_get_init(handle, PERF_DOMAIN_ATTRIBUTES,
				 SCMI_PROTOCOL_PERF, sizeof(domain),
				 sizeof(*attr), &t);
	if (ret)
		return ret;

	*(__le32 *)t->tx.buf = cpu_to_le32(domain);
	attr = t->rx.buf;

	ret = scmi_do_xfer(handle, t);
	if (!ret) {
		u32 flags = le32_to_cpu(attr->flags);

		dom_info->set_limits = SUPPORTS_SET_LIMITS(flags);
		dom_info->set_perf = SUPPORTS_SET_PERF_LVL(flags);
		dom_info->perf_limit_notify = SUPPORTS_PERF_LIMIT_NOTIFY(flags);
		dom_info->perf_level_notify = SUPPORTS_PERF_LEVEL_NOTIFY(flags);
		dom_info->sustained_freq_khz =
					le32_to_cpu(attr->sustained_freq_khz);
		dom_info->sustained_perf_level =
					le32_to_cpu(attr->sustained_perf_level);
		if (!dom_info->sustained_freq_khz ||
		    !dom_info->sustained_perf_level)
			/* CPUFreq converts to kHz, hence default 1000 */
			dom_info->mult_factor =	1000;
		else
			dom_info->mult_factor =
					(dom_info->sustained_freq_khz * 1000) /
					dom_info->sustained_perf_level;
		memcpy(dom_info->name, attr->name, SCMI_MAX_STR_SIZE);
	}

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int opp_cmp_func(const void *opp1, const void *opp2)
{
	const struct scmi_opp *t1 = opp1, *t2 = opp2;

	return t1->perf - t2->perf;
}

__attribute__((used)) static int
scmi_perf_describe_levels_get(const struct scmi_handle *handle, u32 domain,
			      struct perf_dom_info *perf_dom)
{
	int ret, cnt;
	u32 tot_opp_cnt = 0;
	u16 num_returned, num_remaining;
	struct scmi_xfer *t;
	struct scmi_opp *opp;
	struct scmi_msg_perf_describe_levels *dom_info;
	struct scmi_msg_resp_perf_describe_levels *level_info;

	ret = scmi_xfer_get_init(handle, PERF_DESCRIBE_LEVELS,
				 SCMI_PROTOCOL_PERF, sizeof(*dom_info), 0, &t);
	if (ret)
		return ret;

	dom_info = t->tx.buf;
	level_info = t->rx.buf;

	do {
		dom_info->domain = cpu_to_le32(domain);
		/* Set the number of OPPs to be skipped/already read */
		dom_info->level_index = cpu_to_le32(tot_opp_cnt);

		ret = scmi_do_xfer(handle, t);
		if (ret)
			break;

		num_returned = le16_to_cpu(level_info->num_returned);
		num_remaining = le16_to_cpu(level_info->num_remaining);
		if (tot_opp_cnt + num_returned > MAX_OPPS) {
			dev_err(handle->dev, "No. of OPPs exceeded MAX_OPPS");
			break;
		}

		opp = &perf_dom->opp[tot_opp_cnt];
		for (cnt = 0; cnt < num_returned; cnt++, opp++) {
			opp->perf = le32_to_cpu(level_info->opp[cnt].perf_val);
			opp->power = le32_to_cpu(level_info->opp[cnt].power);
			opp->trans_latency_us = le16_to_cpu
				(level_info->opp[cnt].transition_latency_us);

			dev_dbg(handle->dev, "Level %d Power %d Latency %dus\n",
				opp->perf, opp->power, opp->trans_latency_us);
		}

		tot_opp_cnt += num_returned;
		/*
		 * check for both returned and remaining to avoid infinite
		 * loop due to buggy firmware
		 */
	} while (num_returned && num_remaining);

	perf_dom->opp_count = tot_opp_cnt;
	scmi_xfer_put(handle, t);

	sort(perf_dom->opp, tot_opp_cnt, sizeof(*opp), opp_cmp_func, NULL);
	return ret;
}

__attribute__((used)) static int scmi_perf_limits_set(const struct scmi_handle *handle, u32 domain,
				u32 max_perf, u32 min_perf)
{
	int ret;
	struct scmi_xfer *t;
	struct scmi_perf_set_limits *limits;

	ret = scmi_xfer_get_init(handle, PERF_LIMITS_SET, SCMI_PROTOCOL_PERF,
				 sizeof(*limits), 0, &t);
	if (ret)
		return ret;

	limits = t->tx.buf;
	limits->domain = cpu_to_le32(domain);
	limits->max_level = cpu_to_le32(max_perf);
	limits->min_level = cpu_to_le32(min_perf);

	ret = scmi_do_xfer(handle, t);

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int scmi_perf_limits_get(const struct scmi_handle *handle, u32 domain,
				u32 *max_perf, u32 *min_perf)
{
	int ret;
	struct scmi_xfer *t;
	struct scmi_perf_get_limits *limits;

	ret = scmi_xfer_get_init(handle, PERF_LIMITS_GET, SCMI_PROTOCOL_PERF,
				 sizeof(__le32), 0, &t);
	if (ret)
		return ret;

	*(__le32 *)t->tx.buf = cpu_to_le32(domain);

	ret = scmi_do_xfer(handle, t);
	if (!ret) {
		limits = t->rx.buf;

		*max_perf = le32_to_cpu(limits->max_level);
		*min_perf = le32_to_cpu(limits->min_level);
	}

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int scmi_perf_level_set(const struct scmi_handle *handle, u32 domain,
			       u32 level, bool poll)
{
	int ret;
	struct scmi_xfer *t;
	struct scmi_perf_set_level *lvl;

	ret = scmi_xfer_get_init(handle, PERF_LEVEL_SET, SCMI_PROTOCOL_PERF,
				 sizeof(*lvl), 0, &t);
	if (ret)
		return ret;

	t->hdr.poll_completion = poll;
	lvl = t->tx.buf;
	lvl->domain = cpu_to_le32(domain);
	lvl->level = cpu_to_le32(level);

	ret = scmi_do_xfer(handle, t);

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int scmi_perf_level_get(const struct scmi_handle *handle, u32 domain,
			       u32 *level, bool poll)
{
	int ret;
	struct scmi_xfer *t;

	ret = scmi_xfer_get_init(handle, PERF_LEVEL_GET, SCMI_PROTOCOL_PERF,
				 sizeof(u32), sizeof(u32), &t);
	if (ret)
		return ret;

	t->hdr.poll_completion = poll;
	*(__le32 *)t->tx.buf = cpu_to_le32(domain);

	ret = scmi_do_xfer(handle, t);
	if (!ret)
		*level = le32_to_cpu(*(__le32 *)t->rx.buf);

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int scmi_dev_domain_id(struct device *dev)
{
	struct of_phandle_args clkspec;

	if (of_parse_phandle_with_args(dev->of_node, "clocks", "#clock-cells",
				       0, &clkspec))
		return -EINVAL;

	return clkspec.args[0];
}

__attribute__((used)) static int scmi_dvfs_device_opps_add(const struct scmi_handle *handle,
				     struct device *dev)
{
	int idx, ret, domain;
	unsigned long freq;
	struct scmi_opp *opp;
	struct perf_dom_info *dom;
	struct scmi_perf_info *pi = handle->perf_priv;

	domain = scmi_dev_domain_id(dev);
	if (domain < 0)
		return domain;

	dom = pi->dom_info + domain;

	for (opp = dom->opp, idx = 0; idx < dom->opp_count; idx++, opp++) {
		freq = opp->perf * dom->mult_factor;

		ret = dev_pm_opp_add(dev, freq, 0);
		if (ret) {
			dev_warn(dev, "failed to add opp %luHz\n", freq);

			while (idx-- > 0) {
				freq = (--opp)->perf * dom->mult_factor;
				dev_pm_opp_remove(dev, freq);
			}
			return ret;
		}
	}
	return 0;
}

__attribute__((used)) static int scmi_dvfs_transition_latency_get(const struct scmi_handle *handle,
					    struct device *dev)
{
	struct perf_dom_info *dom;
	struct scmi_perf_info *pi = handle->perf_priv;
	int domain = scmi_dev_domain_id(dev);

	if (domain < 0)
		return domain;

	dom = pi->dom_info + domain;
	/* uS to nS */
	return dom->opp[dom->opp_count - 1].trans_latency_us * 1000;
}

__attribute__((used)) static int scmi_dvfs_freq_set(const struct scmi_handle *handle, u32 domain,
			      unsigned long freq, bool poll)
{
	struct scmi_perf_info *pi = handle->perf_priv;
	struct perf_dom_info *dom = pi->dom_info + domain;

	return scmi_perf_level_set(handle, domain, freq / dom->mult_factor,
				   poll);
}

__attribute__((used)) static int scmi_dvfs_freq_get(const struct scmi_handle *handle, u32 domain,
			      unsigned long *freq, bool poll)
{
	int ret;
	u32 level;
	struct scmi_perf_info *pi = handle->perf_priv;
	struct perf_dom_info *dom = pi->dom_info + domain;

	ret = scmi_perf_level_get(handle, domain, &level, poll);
	if (!ret)
		*freq = level * dom->mult_factor;

	return ret;
}

__attribute__((used)) static int scmi_perf_protocol_init(struct scmi_handle *handle)
{
	int domain;
	u32 version;
	struct scmi_perf_info *pinfo;

	scmi_version_get(handle, SCMI_PROTOCOL_PERF, &version);

	dev_dbg(handle->dev, "Performance Version %d.%d\n",
		PROTOCOL_REV_MAJOR(version), PROTOCOL_REV_MINOR(version));

	pinfo = devm_kzalloc(handle->dev, sizeof(*pinfo), GFP_KERNEL);
	if (!pinfo)
		return -ENOMEM;

	scmi_perf_attributes_get(handle, pinfo);

	pinfo->dom_info = devm_kcalloc(handle->dev, pinfo->num_domains,
				       sizeof(*pinfo->dom_info), GFP_KERNEL);
	if (!pinfo->dom_info)
		return -ENOMEM;

	for (domain = 0; domain < pinfo->num_domains; domain++) {
		struct perf_dom_info *dom = pinfo->dom_info + domain;

		scmi_perf_domain_attributes_get(handle, domain, dom);
		scmi_perf_describe_levels_get(handle, domain, dom);
	}

	handle->perf_ops = &perf_ops;
	handle->perf_priv = pinfo;

	return 0;
}

