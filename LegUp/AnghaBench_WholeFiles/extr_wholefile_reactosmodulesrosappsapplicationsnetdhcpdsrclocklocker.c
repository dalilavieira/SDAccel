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
typedef  int /*<<< orphan*/  DHCPLIST ;

/* Variables and functions */
 int TRUE ; 
 int /*<<< orphan*/  sleep (int) ; 

int check_leased_list()
{
  DHCPLIST *temp, *ntemp;
  int count = 1, i;

  /*  fprintf( stdout, "checking list! \n" ); */

  return 0;
}

__attribute__((used)) static int test_and_set()
{
  /* Test lock, if it's locked return FALSE */

  return TRUE;
}

int lock_list()
{
  int count = 1;

  while( !test_and_set() )
    {
      sleep( 1 );
      count++;
    }

  return count;
}

int unlock_list()
{
  return TRUE;
}

