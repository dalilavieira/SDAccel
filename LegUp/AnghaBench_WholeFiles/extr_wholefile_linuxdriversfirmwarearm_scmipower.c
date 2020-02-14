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
typedef  int u64 ;
typedef  int u32 ;
struct TYPE_4__ {struct scmi_msg_resp_power_domain_attributes* buf; } ;
struct TYPE_3__ {struct scmi_power_set_state* buf; } ;
struct scmi_xfer {TYPE_2__ rx; TYPE_1__ tx; } ;
struct scmi_power_set_state {void* state; void* domain; void* flags; } ;
struct scmi_power_info {int num_domains; int stats_addr; int stats_size; struct power_dom_info* dom_info; } ;
struct scmi_msg_resp_power_domain_attributes {int /*<<< orphan*/  name; void* flags; void* stats_size; void* stats_addr_high; void* stats_addr_low; int /*<<< orphan*/  num_domains; } ;
struct scmi_msg_resp_power_attributes {int /*<<< orphan*/  name; void* flags; void* stats_size; void* stats_addr_high; void* stats_addr_low; int /*<<< orphan*/  num_domains; } ;
struct scmi_handle {struct scmi_power_info* power_priv; int /*<<< orphan*/ * power_ops; int /*<<< orphan*/  dev; } ;
struct power_dom_info {char* name; int /*<<< orphan*/  state_set_sync; int /*<<< orphan*/  state_set_async; int /*<<< orphan*/  state_set_notify; } ;
typedef  int /*<<< orphan*/  domain ;
typedef  void* __le32 ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  POWER_DOMAIN_ATTRIBUTES ; 
 int /*<<< orphan*/  POWER_STATE_GET ; 
 int /*<<< orphan*/  POWER_STATE_SET ; 
 int /*<<< orphan*/  PROTOCOL_ATTRIBUTES ; 
 int /*<<< orphan*/  PROTOCOL_REV_MAJOR (int) ; 
 int /*<<< orphan*/  PROTOCOL_REV_MINOR (int) ; 
 int /*<<< orphan*/  SCMI_MAX_STR_SIZE ; 
 int /*<<< orphan*/  SCMI_PROTOCOL_POWER ; 
 int /*<<< orphan*/  SUPPORTS_STATE_SET_ASYNC (int) ; 
 int /*<<< orphan*/  SUPPORTS_STATE_SET_NOTIFY (int) ; 
 int /*<<< orphan*/  SUPPORTS_STATE_SET_SYNC (int) ; 
 void* cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct power_dom_info* devm_kcalloc (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 struct scmi_power_info* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int le32_to_cpu (void*) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  power_ops ; 
 int scmi_do_xfer (struct scmi_handle const*,struct scmi_xfer*) ; 
 int /*<<< orphan*/  scmi_version_get (struct scmi_handle*,int /*<<< orphan*/ ,int*) ; 
 int scmi_xfer_get_init (struct scmi_handle const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,struct scmi_xfer**) ; 
 int /*<<< orphan*/  scmi_xfer_put (struct scmi_handle const*,struct scmi_xfer*) ; 

__attribute__((used)) static int scmi_power_attributes_get(const struct scmi_handle *handle,
				     struct scmi_power_info *pi)
{
	int ret;
	struct scmi_xfer *t;
	struct scmi_msg_resp_power_attributes *attr;

	ret = scmi_xfer_get_init(handle, PROTOCOL_ATTRIBUTES,
				 SCMI_PROTOCOL_POWER, 0, sizeof(*attr), &t);
	if (ret)
		return ret;

	attr = t->rx.buf;

	ret = scmi_do_xfer(handle, t);
	if (!ret) {
		pi->num_domains = le16_to_cpu(attr->num_domains);
		pi->stats_addr = le32_to_cpu(attr->stats_addr_low) |
				(u64)le32_to_cpu(attr->stats_addr_high) << 32;
		pi->stats_size = le32_to_cpu(attr->stats_size);
	}

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int
scmi_power_domain_attributes_get(const struct scmi_handle *handle, u32 domain,
				 struct power_dom_info *dom_info)
{
	int ret;
	struct scmi_xfer *t;
	struct scmi_msg_resp_power_domain_attributes *attr;

	ret = scmi_xfer_get_init(handle, POWER_DOMAIN_ATTRIBUTES,
				 SCMI_PROTOCOL_POWER, sizeof(domain),
				 sizeof(*attr), &t);
	if (ret)
		return ret;

	*(__le32 *)t->tx.buf = cpu_to_le32(domain);
	attr = t->rx.buf;

	ret = scmi_do_xfer(handle, t);
	if (!ret) {
		u32 flags = le32_to_cpu(attr->flags);

		dom_info->state_set_notify = SUPPORTS_STATE_SET_NOTIFY(flags);
		dom_info->state_set_async = SUPPORTS_STATE_SET_ASYNC(flags);
		dom_info->state_set_sync = SUPPORTS_STATE_SET_SYNC(flags);
		memcpy(dom_info->name, attr->name, SCMI_MAX_STR_SIZE);
	}

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int
scmi_power_state_set(const struct scmi_handle *handle, u32 domain, u32 state)
{
	int ret;
	struct scmi_xfer *t;
	struct scmi_power_set_state *st;

	ret = scmi_xfer_get_init(handle, POWER_STATE_SET, SCMI_PROTOCOL_POWER,
				 sizeof(*st), 0, &t);
	if (ret)
		return ret;

	st = t->tx.buf;
	st->flags = cpu_to_le32(0);
	st->domain = cpu_to_le32(domain);
	st->state = cpu_to_le32(state);

	ret = scmi_do_xfer(handle, t);

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int
scmi_power_state_get(const struct scmi_handle *handle, u32 domain, u32 *state)
{
	int ret;
	struct scmi_xfer *t;

	ret = scmi_xfer_get_init(handle, POWER_STATE_GET, SCMI_PROTOCOL_POWER,
				 sizeof(u32), sizeof(u32), &t);
	if (ret)
		return ret;

	*(__le32 *)t->tx.buf = cpu_to_le32(domain);

	ret = scmi_do_xfer(handle, t);
	if (!ret)
		*state = le32_to_cpu(*(__le32 *)t->rx.buf);

	scmi_xfer_put(handle, t);
	return ret;
}

__attribute__((used)) static int scmi_power_num_domains_get(const struct scmi_handle *handle)
{
	struct scmi_power_info *pi = handle->power_priv;

	return pi->num_domains;
}

__attribute__((used)) static char *scmi_power_name_get(const struct scmi_handle *handle, u32 domain)
{
	struct scmi_power_info *pi = handle->power_priv;
	struct power_dom_info *dom = pi->dom_info + domain;

	return dom->name;
}

__attribute__((used)) static int scmi_power_protocol_init(struct scmi_handle *handle)
{
	int domain;
	u32 version;
	struct scmi_power_info *pinfo;

	scmi_version_get(handle, SCMI_PROTOCOL_POWER, &version);

	dev_dbg(handle->dev, "Power Version %d.%d\n",
		PROTOCOL_REV_MAJOR(version), PROTOCOL_REV_MINOR(version));

	pinfo = devm_kzalloc(handle->dev, sizeof(*pinfo), GFP_KERNEL);
	if (!pinfo)
		return -ENOMEM;

	scmi_power_attributes_get(handle, pinfo);

	pinfo->dom_info = devm_kcalloc(handle->dev, pinfo->num_domains,
				       sizeof(*pinfo->dom_info), GFP_KERNEL);
	if (!pinfo->dom_info)
		return -ENOMEM;

	for (domain = 0; domain < pinfo->num_domains; domain++) {
		struct power_dom_info *dom = pinfo->dom_info + domain;

		scmi_power_domain_attributes_get(handle, domain, dom);
	}

	handle->power_ops = &power_ops;
	handle->power_priv = pinfo;

	return 0;
}

