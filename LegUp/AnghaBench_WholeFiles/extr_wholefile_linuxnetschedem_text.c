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
typedef  int /*<<< orphan*/  u8 ;
struct ts_config {TYPE_1__* ops; } ;
struct text_match {scalar_t__ from_layer; scalar_t__ from_offset; scalar_t__ to_layer; scalar_t__ to_offset; struct ts_config* config; } ;
struct tcf_pkt_info {int dummy; } ;
struct tcf_ematch {int datalen; unsigned long data; } ;
struct tcf_em_text {int pattern_len; scalar_t__ from_layer; scalar_t__ to_layer; scalar_t__ from_offset; scalar_t__ to_offset; scalar_t__ pad; int /*<<< orphan*/  algo; } ;
struct sk_buff {int data; } ;
struct net {int dummy; } ;
typedef  int /*<<< orphan*/  conf ;
struct TYPE_2__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int EAGAIN ; 
 int EINVAL ; 
 struct text_match* EM_TEXT_PRIV (struct tcf_ematch*) ; 
 int ENOBUFS ; 
 int ENOENT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct ts_config*) ; 
 int PTR_ERR (struct ts_config*) ; 
 int TS_AUTOLOAD ; 
 scalar_t__ UINT_MAX ; 
 struct text_match* kmalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ nla_append (struct sk_buff*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ nla_put_nohdr (struct sk_buff*,int,struct tcf_em_text*) ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 
 scalar_t__ skb_find_text (struct sk_buff*,int,int,struct ts_config*) ; 
 int /*<<< orphan*/  strncpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int tcf_get_base_ptr (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  textsearch_destroy (struct ts_config*) ; 
 int /*<<< orphan*/  textsearch_get_pattern (struct ts_config*) ; 
 int textsearch_get_pattern_len (struct ts_config*) ; 
 struct ts_config* textsearch_prepare (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int em_text_match(struct sk_buff *skb, struct tcf_ematch *m,
			 struct tcf_pkt_info *info)
{
	struct text_match *tm = EM_TEXT_PRIV(m);
	int from, to;

	from = tcf_get_base_ptr(skb, tm->from_layer) - skb->data;
	from += tm->from_offset;

	to = tcf_get_base_ptr(skb, tm->to_layer) - skb->data;
	to += tm->to_offset;

	return skb_find_text(skb, from, to, tm->config) != UINT_MAX;
}

__attribute__((used)) static int em_text_change(struct net *net, void *data, int len,
			  struct tcf_ematch *m)
{
	struct text_match *tm;
	struct tcf_em_text *conf = data;
	struct ts_config *ts_conf;
	int flags = 0;

	if (len < sizeof(*conf) || len < (sizeof(*conf) + conf->pattern_len))
		return -EINVAL;

	if (conf->from_layer > conf->to_layer)
		return -EINVAL;

	if (conf->from_layer == conf->to_layer &&
	    conf->from_offset > conf->to_offset)
		return -EINVAL;

retry:
	ts_conf = textsearch_prepare(conf->algo, (u8 *) conf + sizeof(*conf),
				     conf->pattern_len, GFP_KERNEL, flags);

	if (flags & TS_AUTOLOAD)
		rtnl_lock();

	if (IS_ERR(ts_conf)) {
		if (PTR_ERR(ts_conf) == -ENOENT && !(flags & TS_AUTOLOAD)) {
			rtnl_unlock();
			flags |= TS_AUTOLOAD;
			goto retry;
		} else
			return PTR_ERR(ts_conf);
	} else if (flags & TS_AUTOLOAD) {
		textsearch_destroy(ts_conf);
		return -EAGAIN;
	}

	tm = kmalloc(sizeof(*tm), GFP_KERNEL);
	if (tm == NULL) {
		textsearch_destroy(ts_conf);
		return -ENOBUFS;
	}

	tm->from_offset = conf->from_offset;
	tm->to_offset   = conf->to_offset;
	tm->from_layer  = conf->from_layer;
	tm->to_layer    = conf->to_layer;
	tm->config      = ts_conf;

	m->datalen = sizeof(*tm);
	m->data = (unsigned long) tm;

	return 0;
}

__attribute__((used)) static void em_text_destroy(struct tcf_ematch *m)
{
	if (EM_TEXT_PRIV(m) && EM_TEXT_PRIV(m)->config)
		textsearch_destroy(EM_TEXT_PRIV(m)->config);
}

__attribute__((used)) static int em_text_dump(struct sk_buff *skb, struct tcf_ematch *m)
{
	struct text_match *tm = EM_TEXT_PRIV(m);
	struct tcf_em_text conf;

	strncpy(conf.algo, tm->config->ops->name, sizeof(conf.algo) - 1);
	conf.from_offset = tm->from_offset;
	conf.to_offset = tm->to_offset;
	conf.from_layer = tm->from_layer;
	conf.to_layer = tm->to_layer;
	conf.pattern_len = textsearch_get_pattern_len(tm->config);
	conf.pad = 0;

	if (nla_put_nohdr(skb, sizeof(conf), &conf) < 0)
		goto nla_put_failure;
	if (nla_append(skb, conf.pattern_len,
		       textsearch_get_pattern(tm->config)) < 0)
		goto nla_put_failure;
	return 0;

nla_put_failure:
	return -1;
}

