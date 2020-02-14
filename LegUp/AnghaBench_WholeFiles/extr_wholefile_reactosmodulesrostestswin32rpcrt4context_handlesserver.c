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
typedef  int RPC_STATUS ;
typedef  int* PCTXTYPE ;
typedef  int /*<<< orphan*/  CTXTYPE ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int RpcServerListen (int,int,int /*<<< orphan*/ ) ; 
 int RpcServerRegisterIf (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int RpcServerUseProtseqEp (char*,int,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  hello_v1_0_s_ifspec ; 
 scalar_t__ midl_user_allocate (int) ; 
 int /*<<< orphan*/  midl_user_free (int*) ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  scanf (char*,int*) ; 

void CtxOpen( PCTXTYPE *pphContext,
	 long Value)
{
	printf("CtxOpen(): Value=%d\n",Value);
	*pphContext = (PCTXTYPE)midl_user_allocate( sizeof(CTXTYPE) );
	**pphContext = Value;
}

void CtxHello( PCTXTYPE phContext )
{
	printf("CtxHello(): Hello, World! Context value: %d\n", *phContext);
}

void CtxClose(PCTXTYPE *pphContext )
{
	printf("CtxClose(): %d\n", **pphContext);
	midl_user_free(*pphContext);
	*pphContext = NULL;
}

void main()
{
	RPC_STATUS status;
	unsigned int    cMinCalls      = 1;
	unsigned int    cMaxCalls      = 20;
	int i;

	status = RpcServerUseProtseqEp("ncacn_np", 20, "\\pipe\\hello", NULL);

	if (status)
	{
		printf("RpcServerUseProtseqEp %x\n", status);
		exit(status);
	}

	status = RpcServerRegisterIf(hello_v1_0_s_ifspec, NULL, NULL);

	if (status)
	{
		printf("RpcServerRegisterIf %x\n", status);
	exit(status);
	}

	status = RpcServerListen(1, 20, FALSE);

	if (status)
	{
		printf("RpcServerListen %x", status);
		exit(status);
	}

	scanf("%d", &i);
}

