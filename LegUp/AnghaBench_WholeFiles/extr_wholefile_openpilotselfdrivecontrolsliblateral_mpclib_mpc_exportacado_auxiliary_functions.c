#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_5__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct timeval {scalar_t__ tv_usec; scalar_t__ tv_sec; } ;
typedef  int real_t ;
struct TYPE_7__ {scalar_t__ tv_usec; scalar_t__ tv_sec; } ;
struct TYPE_6__ {TYPE_2__ tic; TYPE_2__ toc; } ;
typedef  TYPE_1__ acado_timer ;
struct TYPE_8__ {int* x; int* u; int* y; int* yN; } ;

/* Variables and functions */
 int ACADO_N ; 
 int ACADO_NU ; 
 int ACADO_NX ; 
 TYPE_5__ acadoVariables ; 
 int /*<<< orphan*/  gettimeofday (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 

real_t* acado_getVariablesX( )
{
	return acadoVariables.x;
}

real_t* acado_getVariablesU( )
{
	return acadoVariables.u;
}

real_t* acado_getVariablesY( )
{
	return acadoVariables.y;
}

real_t* acado_getVariablesYN( )
{
	return acadoVariables.yN;
}

real_t* acado_getVariablesX0( )
{
#if ACADO_INITIAL_VALUE_FIXED
	return acadoVariables.x0;
#else
	return 0;
#endif
}

void acado_printDifferentialVariables( )
{
	int i, j;
	printf("\nDifferential variables:\n[\n");
	for (i = 0; i < ACADO_N + 1; ++i)
	{
		for (j = 0; j < ACADO_NX; ++j)
			printf("\t%e", acadoVariables.x[i * ACADO_NX + j]);
		printf("\n");
	}
	printf("]\n\n");
}

void acado_printControlVariables( )
{
	int i, j;
	printf("\nControl variables:\n[\n");
	for (i = 0; i < ACADO_N; ++i)
	{
		for (j = 0; j < ACADO_NU; ++j)
			printf("\t%e", acadoVariables.u[i * ACADO_NU + j]);
		printf("\n");
	}
	printf("]\n\n");
}

void acado_printHeader( )
{
	printf(
		"\nACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.\n"
		"Copyright (C) 2008-2015 by Boris Houska, Hans Joachim Ferreau,\n" 
		"Milan Vukov and Rien Quirynen, KU Leuven.\n"
	);
	
	printf(
		"Developed within the Optimization in Engineering Center (OPTEC) under\n"
		"supervision of Moritz Diehl. All rights reserved.\n\n"
		"ACADO Toolkit is distributed under the terms of the GNU Lesser\n"
		"General Public License 3 in the hope that it will be useful,\n"
		"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
		"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n"
		"GNU Lesser General Public License for more details.\n\n"
	);
}

void acado_tic( acado_timer* t )
{
	gettimeofday(&t->tic, 0);
}

real_t acado_toc( acado_timer* t )
{
	struct timeval temp;
	
	gettimeofday(&t->toc, 0);
    
	if ((t->toc.tv_usec - t->tic.tv_usec) < 0)
	{
		temp.tv_sec = t->toc.tv_sec - t->tic.tv_sec - 1;
		temp.tv_usec = 1000000 + t->toc.tv_usec - t->tic.tv_usec;
	}
	else
	{
		temp.tv_sec = t->toc.tv_sec - t->tic.tv_sec;
		temp.tv_usec = t->toc.tv_usec - t->tic.tv_usec;
	}
	
	return (real_t)temp.tv_sec + (real_t)temp.tv_usec / 1e6;
}

