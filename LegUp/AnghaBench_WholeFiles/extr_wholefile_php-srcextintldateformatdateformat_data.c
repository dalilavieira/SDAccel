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
struct TYPE_6__ {int /*<<< orphan*/  error; int /*<<< orphan*/ * udatf; } ;
typedef  TYPE_1__ dateformat_data ;

/* Variables and functions */
 TYPE_1__* ecalloc (int,int) ; 
 int /*<<< orphan*/  intl_error_reset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  udat_close (int /*<<< orphan*/ *) ; 

void dateformat_data_init( dateformat_data* datef_data )
{
	if( !datef_data )
		return;

	datef_data->udatf = NULL;
	intl_error_reset( &datef_data->error );
}

void dateformat_data_free( dateformat_data* datef_data )
{
	if( !datef_data )
		return;

	if( datef_data->udatf )
		udat_close( datef_data->udatf );

	datef_data->udatf = NULL;
	intl_error_reset( &datef_data->error );
}

dateformat_data* dateformat_data_create( void )
{
	dateformat_data* datef_data = ecalloc( 1, sizeof(dateformat_data) );

	dateformat_data_init( datef_data );

	return datef_data;
}

