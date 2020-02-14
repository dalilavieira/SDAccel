#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  int u32 ;
struct tp_params {int /*<<< orphan*/  use_5tuple_mode; int /*<<< orphan*/  pm_size; } ;
struct petp {TYPE_2__* adapter; } ;
struct TYPE_14__ {int is_asic; int chip_version; int chip_revision; int nports; } ;
struct TYPE_15__ {scalar_t__ regs; TYPE_1__ params; } ;
typedef  TYPE_2__ adapter_t ;
struct TYPE_13__ {int clock_core; } ;

/* Variables and functions */
 scalar_t__ A_PL_CAUSE ; 
 scalar_t__ A_PL_ENABLE ; 
 scalar_t__ A_TP_GLOBAL_CONFIG ; 
 scalar_t__ A_TP_INT_CAUSE ; 
 scalar_t__ A_TP_INT_ENABLE ; 
 scalar_t__ A_TP_IN_CONFIG ; 
 scalar_t__ A_TP_OUT_CONFIG ; 
 scalar_t__ A_TP_RESET ; 
 scalar_t__ A_TP_TX_DROP_CONFIG ; 
 unsigned int DROP_MSEC ; 
 int /*<<< orphan*/  DROP_PKTS_CNT ; 
 int F_ENABLE_TX_DROP ; 
 int F_ENABLE_TX_ERROR ; 
 int F_IP_CSUM ; 
 int F_OFFLOAD_DISABLE ; 
 int F_PATH_MTU ; 
 int F_PL_INTR_TP ; 
 int F_TCP_CSUM ; 
 int F_TP_IN_CSPI_CHECK_IP_CSUM ; 
 int F_TP_IN_CSPI_CHECK_TCP_CSUM ; 
 int F_TP_IN_CSPI_CPL ; 
 int F_TP_IN_ESPI_CHECK_IP_CSUM ; 
 int F_TP_IN_ESPI_CHECK_TCP_CSUM ; 
 int F_TP_IN_ESPI_ETHERNET ; 
 int F_TP_OUT_CSPI_CPL ; 
 int F_TP_OUT_ESPI_ETHERNET ; 
 int F_TP_OUT_ESPI_GENERATE_IP_CSUM ; 
 int F_TP_OUT_ESPI_GENERATE_TCP_CSUM ; 
 int F_TP_RESET ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int V_5TUPLE_LOOKUP (int /*<<< orphan*/ ) ; 
 int V_DROP_TICKS_CNT (int) ; 
 int V_IP_TTL (int) ; 
 int V_NUM_PKTS_DROPPED (int /*<<< orphan*/ ) ; 
 int V_SYN_COOKIE_PARAMETER (int) ; 
 TYPE_10__* board_info (TYPE_2__ const*) ; 
 scalar_t__ is_T2 (TYPE_2__*) ; 
 int /*<<< orphan*/  kfree (struct petp*) ; 
 struct petp* kzalloc (int,int /*<<< orphan*/ ) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  t1_is_T1B (TYPE_2__ const*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static inline int t1_is_asic(const adapter_t *adapter)
{
	return adapter->params.is_asic;
}

__attribute__((used)) static inline int adapter_matches_type(const adapter_t *adapter,
				       int version, int revision)
{
	return adapter->params.chip_version == version &&
	       adapter->params.chip_revision == revision;
}

__attribute__((used)) static inline int vlan_tso_capable(const adapter_t *adapter)
{
	return !t1_is_T1B(adapter);
}

__attribute__((used)) static inline unsigned int core_ticks_per_usec(const adapter_t *adap)
{
	return board_info(adap)->clock_core / 1000000;
}

__attribute__((used)) static void tp_init(adapter_t * ap, const struct tp_params *p,
		    unsigned int tp_clk)
{
	u32 val;

	if (!t1_is_asic(ap))
		return;

	val = F_TP_IN_CSPI_CPL | F_TP_IN_CSPI_CHECK_IP_CSUM |
		F_TP_IN_CSPI_CHECK_TCP_CSUM | F_TP_IN_ESPI_ETHERNET;
	if (!p->pm_size)
		val |= F_OFFLOAD_DISABLE;
	else
		val |= F_TP_IN_ESPI_CHECK_IP_CSUM | F_TP_IN_ESPI_CHECK_TCP_CSUM;
	writel(val, ap->regs + A_TP_IN_CONFIG);
	writel(F_TP_OUT_CSPI_CPL |
	       F_TP_OUT_ESPI_ETHERNET |
	       F_TP_OUT_ESPI_GENERATE_IP_CSUM |
	       F_TP_OUT_ESPI_GENERATE_TCP_CSUM, ap->regs + A_TP_OUT_CONFIG);
	writel(V_IP_TTL(64) |
	       F_PATH_MTU /* IP DF bit */  |
	       V_5TUPLE_LOOKUP(p->use_5tuple_mode) |
	       V_SYN_COOKIE_PARAMETER(29), ap->regs + A_TP_GLOBAL_CONFIG);
	/*
	 * Enable pause frame deadlock prevention.
	 */
	if (is_T2(ap) && ap->params.nports > 1) {
		u32 drop_ticks = DROP_MSEC * (tp_clk / 1000);

		writel(F_ENABLE_TX_DROP | F_ENABLE_TX_ERROR |
		       V_DROP_TICKS_CNT(drop_ticks) |
		       V_NUM_PKTS_DROPPED(DROP_PKTS_CNT),
		       ap->regs + A_TP_TX_DROP_CONFIG);
	}
}

void t1_tp_destroy(struct petp *tp)
{
	kfree(tp);
}

struct petp *t1_tp_create(adapter_t *adapter, struct tp_params *p)
{
	struct petp *tp = kzalloc(sizeof(*tp), GFP_KERNEL);

	if (!tp)
		return NULL;

	tp->adapter = adapter;

	return tp;
}

void t1_tp_intr_enable(struct petp *tp)
{
	u32 tp_intr = readl(tp->adapter->regs + A_PL_ENABLE);

#ifdef CONFIG_CHELSIO_T1_1G
	if (!t1_is_asic(tp->adapter)) {
		/* FPGA */
		writel(0xffffffff,
		       tp->adapter->regs + FPGA_TP_ADDR_INTERRUPT_ENABLE);
		writel(tp_intr | FPGA_PCIX_INTERRUPT_TP,
		       tp->adapter->regs + A_PL_ENABLE);
	} else
#endif
	{
		/* We don't use any TP interrupts */
		writel(0, tp->adapter->regs + A_TP_INT_ENABLE);
		writel(tp_intr | F_PL_INTR_TP,
		       tp->adapter->regs + A_PL_ENABLE);
	}
}

void t1_tp_intr_disable(struct petp *tp)
{
	u32 tp_intr = readl(tp->adapter->regs + A_PL_ENABLE);

#ifdef CONFIG_CHELSIO_T1_1G
	if (!t1_is_asic(tp->adapter)) {
		/* FPGA */
		writel(0, tp->adapter->regs + FPGA_TP_ADDR_INTERRUPT_ENABLE);
		writel(tp_intr & ~FPGA_PCIX_INTERRUPT_TP,
		       tp->adapter->regs + A_PL_ENABLE);
	} else
#endif
	{
		writel(0, tp->adapter->regs + A_TP_INT_ENABLE);
		writel(tp_intr & ~F_PL_INTR_TP,
		       tp->adapter->regs + A_PL_ENABLE);
	}
}

void t1_tp_intr_clear(struct petp *tp)
{
#ifdef CONFIG_CHELSIO_T1_1G
	if (!t1_is_asic(tp->adapter)) {
		writel(0xffffffff,
		       tp->adapter->regs + FPGA_TP_ADDR_INTERRUPT_CAUSE);
		writel(FPGA_PCIX_INTERRUPT_TP, tp->adapter->regs + A_PL_CAUSE);
		return;
	}
#endif
	writel(0xffffffff, tp->adapter->regs + A_TP_INT_CAUSE);
	writel(F_PL_INTR_TP, tp->adapter->regs + A_PL_CAUSE);
}

int t1_tp_intr_handler(struct petp *tp)
{
	u32 cause;

#ifdef CONFIG_CHELSIO_T1_1G
	/* FPGA doesn't support TP interrupts. */
	if (!t1_is_asic(tp->adapter))
		return 1;
#endif

	cause = readl(tp->adapter->regs + A_TP_INT_CAUSE);
	writel(cause, tp->adapter->regs + A_TP_INT_CAUSE);
	return 0;
}

__attribute__((used)) static void set_csum_offload(struct petp *tp, u32 csum_bit, int enable)
{
	u32 val = readl(tp->adapter->regs + A_TP_GLOBAL_CONFIG);

	if (enable)
		val |= csum_bit;
	else
		val &= ~csum_bit;
	writel(val, tp->adapter->regs + A_TP_GLOBAL_CONFIG);
}

void t1_tp_set_ip_checksum_offload(struct petp *tp, int enable)
{
	set_csum_offload(tp, F_IP_CSUM, enable);
}

void t1_tp_set_tcp_checksum_offload(struct petp *tp, int enable)
{
	set_csum_offload(tp, F_TCP_CSUM, enable);
}

int t1_tp_reset(struct petp *tp, struct tp_params *p, unsigned int tp_clk)
{
	adapter_t *adapter = tp->adapter;

	tp_init(adapter, p, tp_clk);
	writel(F_TP_RESET, adapter->regs +  A_TP_RESET);
	return 0;
}

