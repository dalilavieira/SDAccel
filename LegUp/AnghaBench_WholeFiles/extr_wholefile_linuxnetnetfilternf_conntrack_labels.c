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
typedef  int u32 ;
struct nf_conn_labels {scalar_t__ bits; } ;
struct nf_conn {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  labels_used; } ;
struct net {TYPE_1__ ct; } ;

/* Variables and functions */
 int BIT_WORD (unsigned int) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int ENOSPC ; 
 int ERANGE ; 
 int /*<<< orphan*/  IPCT_LABEL ; 
 int NF_CT_LABELS_MAX_SIZE ; 
 int U8_MAX ; 
 int cmpxchg (int*,int,int) ; 
 int /*<<< orphan*/  labels_extend ; 
 int /*<<< orphan*/  nf_connlabels_lock ; 
 int /*<<< orphan*/  nf_conntrack_event_cache (int /*<<< orphan*/ ,struct nf_conn*) ; 
 int nf_ct_extend_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nf_ct_extend_unregister (int /*<<< orphan*/ *) ; 
 struct nf_conn_labels* nf_ct_labels_find (struct nf_conn*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int replace_u32(u32 *address, u32 mask, u32 new)
{
	u32 old, tmp;

	do {
		old = *address;
		tmp = (old & mask) ^ new;
		if (old == tmp)
			return 0;
	} while (cmpxchg(address, old, tmp) != old);

	return 1;
}

int nf_connlabels_replace(struct nf_conn *ct,
			  const u32 *data,
			  const u32 *mask, unsigned int words32)
{
	struct nf_conn_labels *labels;
	unsigned int size, i;
	int changed = 0;
	u32 *dst;

	labels = nf_ct_labels_find(ct);
	if (!labels)
		return -ENOSPC;

	size = sizeof(labels->bits);
	if (size < (words32 * sizeof(u32)))
		words32 = size / sizeof(u32);

	dst = (u32 *) labels->bits;
	for (i = 0; i < words32; i++)
		changed |= replace_u32(&dst[i], mask ? ~mask[i] : 0, data[i]);

	size /= sizeof(u32);
	for (i = words32; i < size; i++) /* pad */
		replace_u32(&dst[i], 0, 0);

	if (changed)
		nf_conntrack_event_cache(IPCT_LABEL, ct);
	return 0;
}

int nf_connlabels_get(struct net *net, unsigned int bits)
{
	if (BIT_WORD(bits) >= NF_CT_LABELS_MAX_SIZE / sizeof(long))
		return -ERANGE;

	spin_lock(&nf_connlabels_lock);
	net->ct.labels_used++;
	spin_unlock(&nf_connlabels_lock);

	return 0;
}

void nf_connlabels_put(struct net *net)
{
	spin_lock(&nf_connlabels_lock);
	net->ct.labels_used--;
	spin_unlock(&nf_connlabels_lock);
}

int nf_conntrack_labels_init(void)
{
	BUILD_BUG_ON(NF_CT_LABELS_MAX_SIZE / sizeof(long) >= U8_MAX);

	spin_lock_init(&nf_connlabels_lock);
	return nf_ct_extend_register(&labels_extend);
}

void nf_conntrack_labels_fini(void)
{
	nf_ct_extend_unregister(&labels_extend);
}

