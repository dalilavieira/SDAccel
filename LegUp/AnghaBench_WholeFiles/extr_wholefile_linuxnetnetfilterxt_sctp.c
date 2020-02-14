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
typedef  scalar_t__ u_int8_t ;
typedef  int /*<<< orphan*/  u_int32_t ;
struct xt_sctp_info {int chunk_match_type; int flag_count; unsigned int* spts; int flags; int invflags; unsigned int* dpts; int /*<<< orphan*/  chunkmap; struct xt_sctp_flag_info* flag_info; } ;
struct xt_sctp_flag_info {scalar_t__ chunktype; scalar_t__ flag_mask; scalar_t__ flag; } ;
struct xt_mtchk_param {struct xt_sctp_info* matchinfo; } ;
struct xt_action_param {scalar_t__ fragoff; unsigned int thoff; int hotdrop; struct xt_sctp_info* matchinfo; } ;
struct sk_buff {unsigned int len; } ;
struct sctphdr {scalar_t__ length; scalar_t__ type; scalar_t__ flags; scalar_t__ source; scalar_t__ dest; } ;
struct sctp_chunkhdr {scalar_t__ length; scalar_t__ type; scalar_t__ flags; scalar_t__ source; scalar_t__ dest; } ;
typedef  int /*<<< orphan*/  _sh ;
typedef  int /*<<< orphan*/  _sch ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ SCCHECK (int,int,int,int) ; 
 int /*<<< orphan*/  SCTP_CHUNKMAP_CLEAR (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  SCTP_CHUNKMAP_COPY (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int SCTP_CHUNKMAP_IS_CLEAR (int /*<<< orphan*/ *) ; 
 scalar_t__ SCTP_CHUNKMAP_IS_SET (int /*<<< orphan*/ ,scalar_t__) ; 
#define  SCTP_CHUNK_MATCH_ALL 130 
#define  SCTP_CHUNK_MATCH_ANY 129 
#define  SCTP_CHUNK_MATCH_ONLY 128 
 scalar_t__ SCTP_PAD4 (unsigned int) ; 
 int XT_SCTP_CHUNK_TYPES ; 
 int XT_SCTP_DEST_PORTS ; 
 int XT_SCTP_SRC_PORTS ; 
 int XT_SCTP_VALID_FLAGS ; 
 unsigned int ntohs (scalar_t__) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 struct sctphdr* skb_header_pointer (struct sk_buff const*,unsigned int,int,struct sctphdr*) ; 

__attribute__((used)) static bool
match_flags(const struct xt_sctp_flag_info *flag_info,
	    const int flag_count,
	    u_int8_t chunktype,
	    u_int8_t chunkflags)
{
	int i;

	for (i = 0; i < flag_count; i++)
		if (flag_info[i].chunktype == chunktype)
			return (chunkflags & flag_info[i].flag_mask) == flag_info[i].flag;

	return true;
}

__attribute__((used)) static inline bool
match_packet(const struct sk_buff *skb,
	     unsigned int offset,
	     const struct xt_sctp_info *info,
	     bool *hotdrop)
{
	u_int32_t chunkmapcopy[256 / sizeof (u_int32_t)];
	const struct sctp_chunkhdr *sch;
	struct sctp_chunkhdr _sch;
	int chunk_match_type = info->chunk_match_type;
	const struct xt_sctp_flag_info *flag_info = info->flag_info;
	int flag_count = info->flag_count;

#ifdef DEBUG
	int i = 0;
#endif

	if (chunk_match_type == SCTP_CHUNK_MATCH_ALL)
		SCTP_CHUNKMAP_COPY(chunkmapcopy, info->chunkmap);

	do {
		sch = skb_header_pointer(skb, offset, sizeof(_sch), &_sch);
		if (sch == NULL || sch->length == 0) {
			pr_debug("Dropping invalid SCTP packet.\n");
			*hotdrop = true;
			return false;
		}
#ifdef DEBUG
		pr_debug("Chunk num: %d\toffset: %d\ttype: %d\tlength: %d"
			 "\tflags: %x\n",
			 ++i, offset, sch->type, htons(sch->length),
			 sch->flags);
#endif
		offset += SCTP_PAD4(ntohs(sch->length));

		pr_debug("skb->len: %d\toffset: %d\n", skb->len, offset);

		if (SCTP_CHUNKMAP_IS_SET(info->chunkmap, sch->type)) {
			switch (chunk_match_type) {
			case SCTP_CHUNK_MATCH_ANY:
				if (match_flags(flag_info, flag_count,
					sch->type, sch->flags)) {
					return true;
				}
				break;

			case SCTP_CHUNK_MATCH_ALL:
				if (match_flags(flag_info, flag_count,
				    sch->type, sch->flags))
					SCTP_CHUNKMAP_CLEAR(chunkmapcopy, sch->type);
				break;

			case SCTP_CHUNK_MATCH_ONLY:
				if (!match_flags(flag_info, flag_count,
				    sch->type, sch->flags))
					return false;
				break;
			}
		} else {
			switch (chunk_match_type) {
			case SCTP_CHUNK_MATCH_ONLY:
				return false;
			}
		}
	} while (offset < skb->len);

	switch (chunk_match_type) {
	case SCTP_CHUNK_MATCH_ALL:
		return SCTP_CHUNKMAP_IS_CLEAR(chunkmapcopy);
	case SCTP_CHUNK_MATCH_ANY:
		return false;
	case SCTP_CHUNK_MATCH_ONLY:
		return true;
	}

	/* This will never be reached, but required to stop compiler whine */
	return false;
}

__attribute__((used)) static bool
sctp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_sctp_info *info = par->matchinfo;
	const struct sctphdr *sh;
	struct sctphdr _sh;

	if (par->fragoff != 0) {
		pr_debug("Dropping non-first fragment.. FIXME\n");
		return false;
	}

	sh = skb_header_pointer(skb, par->thoff, sizeof(_sh), &_sh);
	if (sh == NULL) {
		pr_debug("Dropping evil TCP offset=0 tinygram.\n");
		par->hotdrop = true;
		return false;
	}
	pr_debug("spt: %d\tdpt: %d\n", ntohs(sh->source), ntohs(sh->dest));

	return  SCCHECK(ntohs(sh->source) >= info->spts[0]
			&& ntohs(sh->source) <= info->spts[1],
			XT_SCTP_SRC_PORTS, info->flags, info->invflags) &&
		SCCHECK(ntohs(sh->dest) >= info->dpts[0]
			&& ntohs(sh->dest) <= info->dpts[1],
			XT_SCTP_DEST_PORTS, info->flags, info->invflags) &&
		SCCHECK(match_packet(skb, par->thoff + sizeof(_sh),
				     info, &par->hotdrop),
			XT_SCTP_CHUNK_TYPES, info->flags, info->invflags);
}

__attribute__((used)) static int sctp_mt_check(const struct xt_mtchk_param *par)
{
	const struct xt_sctp_info *info = par->matchinfo;

	if (info->flags & ~XT_SCTP_VALID_FLAGS)
		return -EINVAL;
	if (info->invflags & ~XT_SCTP_VALID_FLAGS)
		return -EINVAL;
	if (info->invflags & ~info->flags)
		return -EINVAL;
	if (!(info->flags & XT_SCTP_CHUNK_TYPES))
		return 0;
	if (info->chunk_match_type & (SCTP_CHUNK_MATCH_ALL |
	    SCTP_CHUNK_MATCH_ANY | SCTP_CHUNK_MATCH_ONLY))
		return 0;
	return -EINVAL;
}

