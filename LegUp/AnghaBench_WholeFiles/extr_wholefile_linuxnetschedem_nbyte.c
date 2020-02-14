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
struct tcf_pkt_info {int dummy; } ;
struct tcf_ematch {int datalen; unsigned long data; } ;
struct tcf_em_nbyte {int len; } ;
struct sk_buff {int dummy; } ;
struct net {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  len; int /*<<< orphan*/  off; int /*<<< orphan*/  layer; } ;
struct nbyte_data {TYPE_1__ hdr; int /*<<< orphan*/  pattern; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOBUFS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ kmemdup (void*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcmp (unsigned char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned char* tcf_get_base_ptr (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tcf_valid_offset (struct sk_buff*,unsigned char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int em_nbyte_change(struct net *net, void *data, int data_len,
			   struct tcf_ematch *em)
{
	struct tcf_em_nbyte *nbyte = data;

	if (data_len < sizeof(*nbyte) ||
	    data_len < (sizeof(*nbyte) + nbyte->len))
		return -EINVAL;

	em->datalen = sizeof(*nbyte) + nbyte->len;
	em->data = (unsigned long)kmemdup(data, em->datalen, GFP_KERNEL);
	if (em->data == 0UL)
		return -ENOBUFS;

	return 0;
}

__attribute__((used)) static int em_nbyte_match(struct sk_buff *skb, struct tcf_ematch *em,
			  struct tcf_pkt_info *info)
{
	struct nbyte_data *nbyte = (struct nbyte_data *) em->data;
	unsigned char *ptr = tcf_get_base_ptr(skb, nbyte->hdr.layer);

	ptr += nbyte->hdr.off;

	if (!tcf_valid_offset(skb, ptr, nbyte->hdr.len))
		return 0;

	return !memcmp(ptr, nbyte->pattern, nbyte->hdr.len);
}

