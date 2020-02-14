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
typedef  int /*<<< orphan*/  u8 ;
struct ath79_pci_irq {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void
ath79_pci_set_irq_map(unsigned nr_irqs, const struct ath79_pci_irq *map) {}

__attribute__((used)) static inline void
ath79_pci_set_plat_dev_init(int (*func)(struct pci_dev *)) {}

__attribute__((used)) static inline int ath79_register_pci(void) { return 0; }

__attribute__((used)) static inline void db120_pci_init(u8 *eeprom) {}

