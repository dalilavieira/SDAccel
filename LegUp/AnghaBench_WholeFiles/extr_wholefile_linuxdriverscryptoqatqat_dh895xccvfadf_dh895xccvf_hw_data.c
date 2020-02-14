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
typedef  void* u32 ;
struct adf_hw_device_data {int num_logical_accel; void (* enable_error_correction ) (struct adf_accel_dev*) ;int (* init_admin_comms ) (struct adf_accel_dev*) ;void (* exit_admin_comms ) (struct adf_accel_dev*) ;int (* init_arb ) (struct adf_accel_dev*) ;void (* exit_arb ) (struct adf_accel_dev*) ;void* (* get_accel_mask ) (void*) ;void* (* get_ae_mask ) (void*) ;void* (* get_num_accels ) (struct adf_hw_device_data*) ;void* (* get_num_aes ) (struct adf_hw_device_data*) ;void* (* get_etr_bar_id ) (struct adf_hw_device_data*) ;void* (* get_misc_bar_id ) (struct adf_hw_device_data*) ;void* (* get_pf2vf_offset ) (void*) ;void* (* get_vintmsk_offset ) (void*) ;int (* get_sku ) (struct adf_hw_device_data*) ;void (* enable_ints ) (struct adf_accel_dev*) ;TYPE_1__* dev_class; int /*<<< orphan*/  min_iov_compat_ver; int /*<<< orphan*/  enable_vf2pf_comms; int /*<<< orphan*/  disable_iov; int /*<<< orphan*/  send_admin_init; int /*<<< orphan*/  free_irq; int /*<<< orphan*/  alloc_irq; int /*<<< orphan*/  tx_rings_mask; int /*<<< orphan*/  tx_rx_gap; void* num_engines; void* num_accel; int /*<<< orphan*/  num_banks; } ;
struct adf_accel_dev {int dummy; } ;
typedef  enum dev_sku_info { ____Placeholder_dev_sku_info } dev_sku_info ;
struct TYPE_2__ {int /*<<< orphan*/  instances; } ;

/* Variables and functions */
 void* ADF_DH895XCCIOV_ACCELENGINES_MASK ; 
 void* ADF_DH895XCCIOV_ACCELERATORS_MASK ; 
 void* ADF_DH895XCCIOV_ETR_BAR ; 
 int /*<<< orphan*/  ADF_DH895XCCIOV_ETR_MAX_BANKS ; 
 void* ADF_DH895XCCIOV_MAX_ACCELENGINES ; 
 void* ADF_DH895XCCIOV_MAX_ACCELERATORS ; 
 void* ADF_DH895XCCIOV_PF2VF_OFFSET ; 
 void* ADF_DH895XCCIOV_PMISC_BAR ; 
 int /*<<< orphan*/  ADF_DH895XCCIOV_RX_RINGS_OFFSET ; 
 int /*<<< orphan*/  ADF_DH895XCCIOV_TX_RINGS_MASK ; 
 void* ADF_DH895XCCIOV_VINTMSK_OFFSET ; 
 int /*<<< orphan*/  ADF_PFVF_COMPATIBILITY_VERSION ; 
 int DEV_SKU_VF ; 
 int /*<<< orphan*/  adf_devmgr_update_class_index (struct adf_hw_device_data*) ; 
 int /*<<< orphan*/  adf_enable_vf2pf_comms ; 
 int /*<<< orphan*/  adf_vf2pf_init ; 
 int /*<<< orphan*/  adf_vf2pf_shutdown ; 
 int /*<<< orphan*/  adf_vf_isr_resource_alloc ; 
 int /*<<< orphan*/  adf_vf_isr_resource_free ; 
 TYPE_1__ dh895xcciov_class ; 

__attribute__((used)) static u32 get_accel_mask(u32 fuse)
{
	return ADF_DH895XCCIOV_ACCELERATORS_MASK;
}

__attribute__((used)) static u32 get_ae_mask(u32 fuse)
{
	return ADF_DH895XCCIOV_ACCELENGINES_MASK;
}

__attribute__((used)) static u32 get_num_accels(struct adf_hw_device_data *self)
{
	return ADF_DH895XCCIOV_MAX_ACCELERATORS;
}

__attribute__((used)) static u32 get_num_aes(struct adf_hw_device_data *self)
{
	return ADF_DH895XCCIOV_MAX_ACCELENGINES;
}

__attribute__((used)) static u32 get_misc_bar_id(struct adf_hw_device_data *self)
{
	return ADF_DH895XCCIOV_PMISC_BAR;
}

__attribute__((used)) static u32 get_etr_bar_id(struct adf_hw_device_data *self)
{
	return ADF_DH895XCCIOV_ETR_BAR;
}

__attribute__((used)) static enum dev_sku_info get_sku(struct adf_hw_device_data *self)
{
	return DEV_SKU_VF;
}

__attribute__((used)) static u32 get_pf2vf_offset(u32 i)
{
	return ADF_DH895XCCIOV_PF2VF_OFFSET;
}

__attribute__((used)) static u32 get_vintmsk_offset(u32 i)
{
	return ADF_DH895XCCIOV_VINTMSK_OFFSET;
}

__attribute__((used)) static int adf_vf_int_noop(struct adf_accel_dev *accel_dev)
{
	return 0;
}

__attribute__((used)) static void adf_vf_void_noop(struct adf_accel_dev *accel_dev)
{
}

void adf_init_hw_data_dh895xcciov(struct adf_hw_device_data *hw_data)
{
	hw_data->dev_class = &dh895xcciov_class;
	hw_data->num_banks = ADF_DH895XCCIOV_ETR_MAX_BANKS;
	hw_data->num_accel = ADF_DH895XCCIOV_MAX_ACCELERATORS;
	hw_data->num_logical_accel = 1;
	hw_data->num_engines = ADF_DH895XCCIOV_MAX_ACCELENGINES;
	hw_data->tx_rx_gap = ADF_DH895XCCIOV_RX_RINGS_OFFSET;
	hw_data->tx_rings_mask = ADF_DH895XCCIOV_TX_RINGS_MASK;
	hw_data->alloc_irq = adf_vf_isr_resource_alloc;
	hw_data->free_irq = adf_vf_isr_resource_free;
	hw_data->enable_error_correction = adf_vf_void_noop;
	hw_data->init_admin_comms = adf_vf_int_noop;
	hw_data->exit_admin_comms = adf_vf_void_noop;
	hw_data->send_admin_init = adf_vf2pf_init;
	hw_data->init_arb = adf_vf_int_noop;
	hw_data->exit_arb = adf_vf_void_noop;
	hw_data->disable_iov = adf_vf2pf_shutdown;
	hw_data->get_accel_mask = get_accel_mask;
	hw_data->get_ae_mask = get_ae_mask;
	hw_data->get_num_accels = get_num_accels;
	hw_data->get_num_aes = get_num_aes;
	hw_data->get_etr_bar_id = get_etr_bar_id;
	hw_data->get_misc_bar_id = get_misc_bar_id;
	hw_data->get_pf2vf_offset = get_pf2vf_offset;
	hw_data->get_vintmsk_offset = get_vintmsk_offset;
	hw_data->get_sku = get_sku;
	hw_data->enable_ints = adf_vf_void_noop;
	hw_data->enable_vf2pf_comms = adf_enable_vf2pf_comms;
	hw_data->min_iov_compat_ver = ADF_PFVF_COMPATIBILITY_VERSION;
	hw_data->dev_class->instances++;
	adf_devmgr_update_class_index(hw_data);
}

void adf_clean_hw_data_dh895xcciov(struct adf_hw_device_data *hw_data)
{
	hw_data->dev_class->instances--;
	adf_devmgr_update_class_index(hw_data);
}

