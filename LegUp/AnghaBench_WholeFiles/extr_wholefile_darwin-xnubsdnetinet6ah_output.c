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
struct secasvar {int flags; int /*<<< orphan*/  alg_auth; } ;
struct newah {int dummy; } ;
struct TYPE_2__ {scalar_t__ proto; } ;
struct ipsecrequest {TYPE_1__ saidx; } ;
struct ah_algorithm {int (* sumsiz ) (struct secasvar*) ;} ;
struct ah {int dummy; } ;

/* Variables and functions */
 scalar_t__ IPPROTO_AH ; 
 int SADB_X_EXT_OLD ; 
 struct ah_algorithm* ah_algorithm_lookup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*) ; 
 int stub1 (struct secasvar*) ; 
 int stub2 (struct secasvar*) ; 

size_t
ah_hdrsiz(struct ipsecrequest *isr)
{

	/* sanity check */
	if (isr == NULL)
		panic("ah_hdrsiz: NULL was passed.\n");

	if (isr->saidx.proto != IPPROTO_AH)
		panic("unsupported mode passed to ah_hdrsiz");

#if 0
	{

		lck_mtx_lock(sadb_mutex);
		const struct ah_algorithm *algo;
		size_t hdrsiz;

		/*%%%%% this needs to change - no sav in ipsecrequest any more */
		if (isr->sav == NULL)
			goto estimate;
		if (isr->sav->state != SADB_SASTATE_MATURE
		 && isr->sav->state != SADB_SASTATE_DYING)
			goto estimate;
	
		/* we need transport mode AH. */
		algo = ah_algorithm_lookup(isr->sav->alg_auth);
		if (!algo)
			goto estimate;
	
		/*
		 * XXX
		 * right now we don't calcurate the padding size.  simply
		 * treat the padding size as constant, for simplicity.
		 *
		 * XXX variable size padding support
		 */
		hdrsiz = (((*algo->sumsiz)(isr->sav) + 3) & ~(4 - 1));
		if (isr->sav->flags & SADB_X_EXT_OLD)
			hdrsiz += sizeof(struct ah);
		else
			hdrsiz += sizeof(struct newah);
	
		lck_mtx_unlock(sadb_mutex);
		return hdrsiz;
	}

estimate:
#endif

    //lck_mtx_unlock(sadb_mutex);
	/* ASSUMING:
	 *	sizeof(struct newah) > sizeof(struct ah).
	 *	16 = (16 + 3) & ~(4 - 1).
	 */
	return sizeof(struct newah) + 16;
}

int
ah_hdrlen(struct secasvar *sav)
{
	const struct ah_algorithm *algo;
	int plen, ahlen;
	
	algo = ah_algorithm_lookup(sav->alg_auth);
	if (!algo)
		return 0;
	if (sav->flags & SADB_X_EXT_OLD) {
		/* RFC 1826 */
		plen = ((*algo->sumsiz)(sav) + 3) & ~(4 - 1);	/*XXX pad to 8byte?*/
		ahlen = plen + sizeof(struct ah);
	} else {
		/* RFC 2402 */
		plen = ((*algo->sumsiz)(sav) + 3) & ~(4 - 1);	/*XXX pad to 8byte?*/
		ahlen = plen + sizeof(struct newah);
	}

	return(ahlen);
}

