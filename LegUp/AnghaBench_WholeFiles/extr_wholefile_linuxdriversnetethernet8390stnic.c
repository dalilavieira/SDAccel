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
typedef  int /*<<< orphan*/  vword ;
typedef  int vhalf ;
struct net_device {int dummy; } ;
typedef  int half ;
typedef  int byte ;

/* Variables and functions */
 scalar_t__ PA_83902 ; 
 struct net_device* __alloc_ei_netdev (int /*<<< orphan*/ ) ; 
 struct net_device* __alloc_eip_netdev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct net_device *alloc_ei_netdev(void)
{
	return __alloc_ei_netdev(0);
}

__attribute__((used)) static inline struct net_device *alloc_eip_netdev(void)
{
	return __alloc_eip_netdev(0);
}

__attribute__((used)) static inline void
STNIC_DELAY (void)
{
  vword trash;
  trash = *(vword *) 0xa0000000;
  trash = *(vword *) 0xa0000000;
  trash = *(vword *) 0xa0000000;
}

__attribute__((used)) static inline byte
STNIC_READ (int reg)
{
  byte val;

  val = (*(vhalf *) (PA_83902 + ((reg) << 1)) >> 8) & 0xff;
  STNIC_DELAY ();
  return val;
}

__attribute__((used)) static inline void
STNIC_WRITE (int reg, byte val)
{
  *(vhalf *) (PA_83902 + ((reg) << 1)) = ((half) (val) << 8);
  STNIC_DELAY ();
}

