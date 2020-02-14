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
typedef  scalar_t__ u32 ;
struct platform_device {int dummy; } ;
struct msm_dsi_pll {int dummy; } ;
struct msm_dsi_cfg_handler {scalar_t__ major; scalar_t__ minor; } ;
struct msm_dsi {scalar_t__ external_bridge; scalar_t__ panel; } ;
struct clk {int dummy; } ;
typedef  enum msm_dsi_phy_usecase { ____Placeholder_msm_dsi_phy_usecase } msm_dsi_phy_usecase ;
typedef  enum msm_dsi_phy_type { ____Placeholder_msm_dsi_phy_type } msm_dsi_phy_type ;

/* Variables and functions */
 int ARRAY_SIZE (struct msm_dsi_cfg_handler*) ; 
 int ENODEV ; 
 struct msm_dsi_pll* ERR_PTR (int) ; 
 struct msm_dsi_cfg_handler* dsi_cfg_handlers ; 

__attribute__((used)) static inline bool msm_dsi_device_connected(struct msm_dsi *msm_dsi)
{
	return msm_dsi->panel || msm_dsi->external_bridge;
}

__attribute__((used)) static inline struct msm_dsi_pll *msm_dsi_pll_init(struct platform_device *pdev,
			 enum msm_dsi_phy_type type, int id) {
	return ERR_PTR(-ENODEV);
}

__attribute__((used)) static inline void msm_dsi_pll_destroy(struct msm_dsi_pll *pll)
{
}

__attribute__((used)) static inline int msm_dsi_pll_get_clk_provider(struct msm_dsi_pll *pll,
	struct clk **byte_clk_provider, struct clk **pixel_clk_provider)
{
	return -ENODEV;
}

__attribute__((used)) static inline void msm_dsi_pll_save_state(struct msm_dsi_pll *pll)
{
}

__attribute__((used)) static inline int msm_dsi_pll_restore_state(struct msm_dsi_pll *pll)
{
	return 0;
}

__attribute__((used)) static inline int msm_dsi_pll_set_usecase(struct msm_dsi_pll *pll,
					  enum msm_dsi_phy_usecase uc)
{
	return -ENODEV;
}

const struct msm_dsi_cfg_handler *msm_dsi_cfg_get(u32 major, u32 minor)
{
	const struct msm_dsi_cfg_handler *cfg_hnd = NULL;
	int i;

	for (i = ARRAY_SIZE(dsi_cfg_handlers) - 1; i >= 0; i--) {
		if ((dsi_cfg_handlers[i].major == major) &&
			(dsi_cfg_handlers[i].minor == minor)) {
			cfg_hnd = &dsi_cfg_handlers[i];
			break;
		}
	}

	return cfg_hnd;
}

