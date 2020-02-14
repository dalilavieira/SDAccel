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
struct in6_addr {int dummy; } ;
struct ila_identifier {int /*<<< orphan*/  csum_neutral; } ;
struct TYPE_2__ {scalar_t__ type; } ;
struct ila_addr {TYPE_1__ ident; } ;
typedef  int /*<<< orphan*/  diff ;
typedef  int /*<<< orphan*/  __wsum ;
typedef  int /*<<< orphan*/  const __be32 ;

/* Variables and functions */
 scalar_t__ ILA_ATYPE_IID ; 
 int /*<<< orphan*/  csum_partial (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct ila_addr *ila_a2i(struct in6_addr *addr)
{
	return (struct ila_addr *)addr;
}

__attribute__((used)) static inline bool ila_addr_is_ila(struct ila_addr *iaddr)
{
	return (iaddr->ident.type != ILA_ATYPE_IID);
}

__attribute__((used)) static inline __wsum compute_csum_diff8(const __be32 *from, const __be32 *to)
{
	__be32 diff[] = {
		~from[0], ~from[1], to[0], to[1],
	};

	return csum_partial(diff, sizeof(diff), 0);
}

__attribute__((used)) static inline bool ila_csum_neutral_set(struct ila_identifier ident)
{
	return !!(ident.csum_neutral);
}

