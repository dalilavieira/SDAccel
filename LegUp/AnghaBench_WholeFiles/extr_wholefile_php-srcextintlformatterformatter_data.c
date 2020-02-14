#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  error; int /*<<< orphan*/ * unum; } ;
typedef  TYPE_1__ formatter_data ;

/* Variables and functions */
 TYPE_1__* ecalloc (int,int) ; 
 int /*<<< orphan*/  intl_error_reset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unum_close (int /*<<< orphan*/ *) ; 

void formatter_data_init( formatter_data* nf_data )
{
	if( !nf_data )
		return;

	nf_data->unum                = NULL;
	intl_error_reset( &nf_data->error );
}

void formatter_data_free( formatter_data* nf_data )
{
	if( !nf_data )
		return;

	if( nf_data->unum )
		unum_close( nf_data->unum );

	nf_data->unum = NULL;
	intl_error_reset( &nf_data->error );
}

formatter_data* formatter_data_create( void )
{
	formatter_data* nf_data = ecalloc( 1, sizeof(formatter_data) );

	formatter_data_init( nf_data );

	return nf_data;
}

