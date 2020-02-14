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
struct TYPE_2__ {int /*<<< orphan*/  ndef_bio; int /*<<< orphan*/  out; int /*<<< orphan*/  boundary; } ;
typedef  int /*<<< orphan*/  PKCS7 ;
typedef  int /*<<< orphan*/  ASN1_VALUE ;
typedef  TYPE_1__ ASN1_STREAM_ARG ;
typedef  int /*<<< orphan*/  ASN1_ITEM ;

/* Variables and functions */
#define  ASN1_OP_DETACHED_POST 131 
#define  ASN1_OP_DETACHED_PRE 130 
#define  ASN1_OP_STREAM_POST 129 
#define  ASN1_OP_STREAM_PRE 128 
 int /*<<< orphan*/  PKCS7_dataFinal (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PKCS7_dataInit (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PKCS7_stream (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int pk7_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
                  void *exarg)
{
    ASN1_STREAM_ARG *sarg = exarg;
    PKCS7 **pp7 = (PKCS7 **)pval;

    switch (operation) {

    case ASN1_OP_STREAM_PRE:
        if (PKCS7_stream(&sarg->boundary, *pp7) <= 0)
            return 0;
        /* fall thru */
    case ASN1_OP_DETACHED_PRE:
        sarg->ndef_bio = PKCS7_dataInit(*pp7, sarg->out);
        if (!sarg->ndef_bio)
            return 0;
        break;

    case ASN1_OP_STREAM_POST:
    case ASN1_OP_DETACHED_POST:
        if (PKCS7_dataFinal(*pp7, sarg->ndef_bio) <= 0)
            return 0;
        break;

    }
    return 1;
}

