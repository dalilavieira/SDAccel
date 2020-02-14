#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
struct TYPE_6__ {int reg_offset; scalar_t__ base; } ;
struct TYPE_7__ {int /*<<< orphan*/  core_if; int /*<<< orphan*/  hcd; int /*<<< orphan*/  pcd; TYPE_1__ os_dep; } ;
typedef  TYPE_2__ dwc_otg_device_t ;
struct TYPE_8__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DWC_OTG_GETDRVDEV (TYPE_2__*,struct device*) ; 
 int /*<<< orphan*/  DWC_PRINTF (char*,...) ; 
 int DWC_READ_REG32 (int volatile*) ; 
 int /*<<< orphan*/  DWC_WRITE_REG32 (int volatile*,int) ; 
 int /*<<< orphan*/  HZ ; 
 int MSEC_PER_JIFFIE ; 
 int RW_REG_COUNT ; 
 TYPE_4__* dev ; 
 int /*<<< orphan*/  dev_attr_busconnected ; 
 int /*<<< orphan*/  dev_attr_buspower ; 
 int /*<<< orphan*/  dev_attr_bussuspend ; 
 int /*<<< orphan*/  dev_attr_devspeed ; 
 int /*<<< orphan*/  dev_attr_disconnect_us ; 
 int /*<<< orphan*/  dev_attr_enumspeed ; 
 int /*<<< orphan*/  dev_attr_fr_interval ; 
 int /*<<< orphan*/  dev_attr_ggpio ; 
 int /*<<< orphan*/  dev_attr_gnptxfsiz ; 
 int /*<<< orphan*/  dev_attr_gotgctl ; 
 int /*<<< orphan*/  dev_attr_gpvndctl ; 
 int /*<<< orphan*/  dev_attr_grxfsiz ; 
 int /*<<< orphan*/  dev_attr_gsnpsid ; 
 int /*<<< orphan*/  dev_attr_guid ; 
 int /*<<< orphan*/  dev_attr_gusbcfg ; 
 int /*<<< orphan*/  dev_attr_hcd_frrem ; 
 int /*<<< orphan*/  dev_attr_hcddump ; 
 int /*<<< orphan*/  dev_attr_hnp ; 
 int /*<<< orphan*/  dev_attr_hnpcapable ; 
 int /*<<< orphan*/  dev_attr_hprt0 ; 
 int /*<<< orphan*/  dev_attr_hptxfsiz ; 
 int /*<<< orphan*/  dev_attr_hsic_connect ; 
 int /*<<< orphan*/  dev_attr_inv_sel_hsic ; 
 int /*<<< orphan*/  dev_attr_mode ; 
 int /*<<< orphan*/  dev_attr_mode_ch_tim_en ; 
 int /*<<< orphan*/  dev_attr_rd_reg_test ; 
 int /*<<< orphan*/  dev_attr_regdump ; 
 int /*<<< orphan*/  dev_attr_regoffset ; 
 int /*<<< orphan*/  dev_attr_regvalue ; 
 int /*<<< orphan*/  dev_attr_rem_wakeup_pwrdn ; 
 int /*<<< orphan*/  dev_attr_remote_wakeup ; 
 int /*<<< orphan*/  dev_attr_spramdump ; 
 int /*<<< orphan*/  dev_attr_srp ; 
 int /*<<< orphan*/  dev_attr_srpcapable ; 
 int /*<<< orphan*/  dev_attr_wr_reg_test ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 int device_create_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dwc_otg_device_hibernation_restore (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc_otg_dump_dev_registers (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc_otg_dump_global_registers (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc_otg_dump_host_registers (int /*<<< orphan*/ ) ; 
 scalar_t__ dwc_otg_get_core_state (int /*<<< orphan*/ ) ; 
 int dwc_otg_get_fr_interval (int /*<<< orphan*/ ) ; 
 int dwc_otg_get_gnptxfsiz (int /*<<< orphan*/ ) ; 
 int dwc_otg_get_hnpstatus (int /*<<< orphan*/ ) ; 
 int dwc_otg_get_lpm_remotewakeenabled (int /*<<< orphan*/ ) ; 
 int dwc_otg_get_mode_ch_tim (int /*<<< orphan*/ ) ; 
 int dwc_otg_get_prtpower (int /*<<< orphan*/ ) ; 
 int dwc_otg_get_prtsuspend (int /*<<< orphan*/ ) ; 
 int dwc_otg_get_remotewakesig (int /*<<< orphan*/ ) ; 
 int dwc_otg_get_srpstatus (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc_otg_hcd_dump_frrem (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc_otg_hcd_dump_state (int /*<<< orphan*/ ) ; 
 scalar_t__ dwc_otg_is_host_mode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc_otg_pcd_disconnect_us (int /*<<< orphan*/ ,int) ; 
 int dwc_otg_pcd_get_rmwkup_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc_otg_pcd_initiate_srp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc_otg_pcd_remote_wakeup (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dwc_otg_set_fr_interval (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dwc_otg_set_gnptxfsiz (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dwc_otg_set_hnpreq (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dwc_otg_set_mode_ch_tim (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dwc_otg_set_prtpower (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dwc_otg_set_prtsuspend (int /*<<< orphan*/ ,int) ; 
 int jiffies ; 
 int /*<<< orphan*/  loops_per_jiffy ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int simple_strtoul (char const*,int /*<<< orphan*/ *,int) ; 
 size_t snprintf (char*,int,char*,int,...) ; 
 size_t sprintf (char*,char*,...) ; 

__attribute__((used)) static dwc_otg_device_t *dwc_otg_drvdev(struct device *_dev)
{
        dwc_otg_device_t *otg_dev;
        DWC_OTG_GETDRVDEV(otg_dev, _dev);
        return otg_dev;
}

__attribute__((used)) static ssize_t regoffset_show(struct device *_dev,
			      struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	return snprintf(buf, sizeof("0xFFFFFFFF\n") + 1, "0x%08x\n",
			otg_dev->os_dep.reg_offset);
}

__attribute__((used)) static ssize_t regoffset_store(struct device *_dev,
			       struct device_attribute *attr,
			       const char *buf, size_t count)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t offset = simple_strtoul(buf, NULL, 16);
#if defined(LM_INTERFACE) || defined(PLATFORM_INTERFACE)
	if (offset < SZ_256K) {
#elif  defined(PCI_INTERFACE)
	if (offset < 0x00040000) {
#endif
		otg_dev->os_dep.reg_offset = offset;
	}

__attribute__((used)) static ssize_t regvalue_show(struct device *_dev,
			     struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t val;
	volatile uint32_t *addr;

	if (otg_dev->os_dep.reg_offset != 0xFFFFFFFF && 0 != otg_dev->os_dep.base) {
		/* Calculate the address */
		addr = (uint32_t *) (otg_dev->os_dep.reg_offset +
				     (uint8_t *) otg_dev->os_dep.base);
		val = DWC_READ_REG32(addr);
		return snprintf(buf,
				sizeof("Reg@0xFFFFFFFF = 0xFFFFFFFF\n") + 1,
				"Reg@0x%06x = 0x%08x\n", otg_dev->os_dep.reg_offset,
				val);
	} else {
		dev_err(_dev, "Invalid offset (0x%0x)\n", otg_dev->os_dep.reg_offset);
		return sprintf(buf, "invalid offset\n");
	}
}

__attribute__((used)) static ssize_t regvalue_store(struct device *_dev,
			      struct device_attribute *attr,
			      const char *buf, size_t count)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	volatile uint32_t *addr;
	uint32_t val = simple_strtoul(buf, NULL, 16);
	//dev_dbg(_dev, "Offset=0x%08x Val=0x%08x\n", otg_dev->reg_offset, val);
	if (otg_dev->os_dep.reg_offset != 0xFFFFFFFF && 0 != otg_dev->os_dep.base) {
		/* Calculate the address */
		addr = (uint32_t *) (otg_dev->os_dep.reg_offset +
				     (uint8_t *) otg_dev->os_dep.base);
		DWC_WRITE_REG32(addr, val);
	} else {
		dev_err(_dev, "Invalid Register Offset (0x%08x)\n",
			otg_dev->os_dep.reg_offset);
	}
	return count;
}

__attribute__((used)) static ssize_t hnp_show(struct device *_dev,
			struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	return sprintf(buf, "HstNegScs = 0x%x\n",
		       dwc_otg_get_hnpstatus(otg_dev->core_if));
}

__attribute__((used)) static ssize_t hnp_store(struct device *_dev,
			 struct device_attribute *attr,
			 const char *buf, size_t count)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t in = simple_strtoul(buf, NULL, 16);
	dwc_otg_set_hnpreq(otg_dev->core_if, in);
	return count;
}

__attribute__((used)) static ssize_t srp_show(struct device *_dev,
			struct device_attribute *attr, char *buf)
{
#ifndef DWC_HOST_ONLY
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	return sprintf(buf, "SesReqScs = 0x%x\n",
		       dwc_otg_get_srpstatus(otg_dev->core_if));
#else
	return sprintf(buf, "Host Only Mode!\n");
#endif
}

__attribute__((used)) static ssize_t srp_store(struct device *_dev,
			 struct device_attribute *attr,
			 const char *buf, size_t count)
{
#ifndef DWC_HOST_ONLY
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	dwc_otg_pcd_initiate_srp(otg_dev->pcd);
#endif
	return count;
}

__attribute__((used)) static ssize_t buspower_show(struct device *_dev,
			     struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	return sprintf(buf, "Bus Power = 0x%x\n",
		       dwc_otg_get_prtpower(otg_dev->core_if));
}

__attribute__((used)) static ssize_t buspower_store(struct device *_dev,
			      struct device_attribute *attr,
			      const char *buf, size_t count)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t on = simple_strtoul(buf, NULL, 16);
	dwc_otg_set_prtpower(otg_dev->core_if, on);
	return count;
}

__attribute__((used)) static ssize_t bussuspend_show(struct device *_dev,
			       struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	return sprintf(buf, "Bus Suspend = 0x%x\n",
		       dwc_otg_get_prtsuspend(otg_dev->core_if));
}

__attribute__((used)) static ssize_t bussuspend_store(struct device *_dev,
				struct device_attribute *attr,
				const char *buf, size_t count)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t in = simple_strtoul(buf, NULL, 16);
	dwc_otg_set_prtsuspend(otg_dev->core_if, in);
	return count;
}

__attribute__((used)) static ssize_t mode_ch_tim_en_show(struct device *_dev,
				   struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	return sprintf(buf, "Mode Change Ready Timer Enable = 0x%x\n",
		       dwc_otg_get_mode_ch_tim(otg_dev->core_if));
}

__attribute__((used)) static ssize_t mode_ch_tim_en_store(struct device *_dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t in = simple_strtoul(buf, NULL, 16);
	dwc_otg_set_mode_ch_tim(otg_dev->core_if, in);
	return count;
}

__attribute__((used)) static ssize_t fr_interval_show(struct device *_dev,
				struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	return sprintf(buf, "Frame Interval = 0x%x\n",
		       dwc_otg_get_fr_interval(otg_dev->core_if));
}

__attribute__((used)) static ssize_t fr_interval_store(struct device *_dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t in = simple_strtoul(buf, NULL, 10);
	dwc_otg_set_fr_interval(otg_dev->core_if, in);
	return count;
}

__attribute__((used)) static ssize_t remote_wakeup_show(struct device *_dev,
				  struct device_attribute *attr, char *buf)
{
#ifndef DWC_HOST_ONLY
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);

	return sprintf(buf,
		       "Remote Wakeup Sig = %d Enabled = %d LPM Remote Wakeup = %d\n",
		       dwc_otg_get_remotewakesig(otg_dev->core_if),
		       dwc_otg_pcd_get_rmwkup_enable(otg_dev->pcd),
		       dwc_otg_get_lpm_remotewakeenabled(otg_dev->core_if));
#else
	return sprintf(buf, "Host Only Mode!\n");
#endif /* DWC_HOST_ONLY */
}

__attribute__((used)) static ssize_t remote_wakeup_store(struct device *_dev,
				   struct device_attribute *attr,
				   const char *buf, size_t count)
{
#ifndef DWC_HOST_ONLY
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t val = simple_strtoul(buf, NULL, 16);

	if (val & 1) {
		dwc_otg_pcd_remote_wakeup(otg_dev->pcd, 1);
	} else {
		dwc_otg_pcd_remote_wakeup(otg_dev->pcd, 0);
	}
#endif /* DWC_HOST_ONLY */
	return count;
}

__attribute__((used)) static ssize_t rem_wakeup_pwrdn_show(struct device *_dev,
				     struct device_attribute *attr, char *buf)
{
#ifndef DWC_HOST_ONLY
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);

	if (dwc_otg_get_core_state(otg_dev->core_if)) {
		DWC_PRINTF("Core is in hibernation\n");
	} else {
		DWC_PRINTF("Core is not in hibernation\n");
	}
#endif /* DWC_HOST_ONLY */
	return 0;
}

__attribute__((used)) static ssize_t rem_wakeup_pwrdn_store(struct device *_dev,
				      struct device_attribute *attr,
				      const char *buf, size_t count)
{
#ifndef DWC_HOST_ONLY
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	dwc_otg_device_hibernation_restore(otg_dev->core_if, 1, 0);
#endif
	return count;
}

__attribute__((used)) static ssize_t disconnect_us(struct device *_dev,
			     struct device_attribute *attr,
			     const char *buf, size_t count)
{

#ifndef DWC_HOST_ONLY
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t val = simple_strtoul(buf, NULL, 16);
	DWC_PRINTF("The Passed value is %04x\n", val);

	dwc_otg_pcd_disconnect_us(otg_dev->pcd, 50);

#endif /* DWC_HOST_ONLY */
	return count;
}

__attribute__((used)) static ssize_t regdump_show(struct device *_dev,
			    struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);

	dwc_otg_dump_global_registers(otg_dev->core_if);
	if (dwc_otg_is_host_mode(otg_dev->core_if)) {
		dwc_otg_dump_host_registers(otg_dev->core_if);
	} else {
		dwc_otg_dump_dev_registers(otg_dev->core_if);

	}
	return sprintf(buf, "Register Dump\n");
}

__attribute__((used)) static ssize_t spramdump_show(struct device *_dev,
			      struct device_attribute *attr, char *buf)
{
#if 0
	dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);

	dwc_otg_dump_spram(otg_dev->core_if);
#endif

	return sprintf(buf, "SPRAM Dump\n");
}

__attribute__((used)) static ssize_t hcddump_show(struct device *_dev,
			    struct device_attribute *attr, char *buf)
{
#ifndef DWC_DEVICE_ONLY
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	dwc_otg_hcd_dump_state(otg_dev->hcd);
#endif /* DWC_DEVICE_ONLY */
	return sprintf(buf, "HCD Dump\n");
}

__attribute__((used)) static ssize_t hcd_frrem_show(struct device *_dev,
			      struct device_attribute *attr, char *buf)
{
#ifndef DWC_DEVICE_ONLY
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);

	dwc_otg_hcd_dump_frrem(otg_dev->hcd);
#endif /* DWC_DEVICE_ONLY */
	return sprintf(buf, "HCD Dump Frame Remaining\n");
}

__attribute__((used)) static ssize_t rd_reg_test_show(struct device *_dev,
				struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	int i;
	int time;
	int start_jiffies;

	printk("HZ %d, MSEC_PER_JIFFIE %d, loops_per_jiffy %lu\n",
	       HZ, MSEC_PER_JIFFIE, loops_per_jiffy);
	start_jiffies = jiffies;
	for (i = 0; i < RW_REG_COUNT; i++) {
		dwc_otg_get_gnptxfsiz(otg_dev->core_if);
	}
	time = jiffies - start_jiffies;
	return sprintf(buf,
		       "Time to read GNPTXFSIZ reg %d times: %d msecs (%d jiffies)\n",
		       RW_REG_COUNT, time * MSEC_PER_JIFFIE, time);
}

__attribute__((used)) static ssize_t wr_reg_test_show(struct device *_dev,
				struct device_attribute *attr, char *buf)
{
        dwc_otg_device_t *otg_dev = dwc_otg_drvdev(_dev);
	uint32_t reg_val;
	int i;
	int time;
	int start_jiffies;

	printk("HZ %d, MSEC_PER_JIFFIE %d, loops_per_jiffy %lu\n",
	       HZ, MSEC_PER_JIFFIE, loops_per_jiffy);
	reg_val = dwc_otg_get_gnptxfsiz(otg_dev->core_if);
	start_jiffies = jiffies;
	for (i = 0; i < RW_REG_COUNT; i++) {
		dwc_otg_set_gnptxfsiz(otg_dev->core_if, reg_val);
	}
	time = jiffies - start_jiffies;
	return sprintf(buf,
		       "Time to write GNPTXFSIZ reg %d times: %d msecs (%d jiffies)\n",
		       RW_REG_COUNT, time * MSEC_PER_JIFFIE, time);
}

void dwc_otg_attr_create(
#ifdef LM_INTERFACE
	struct lm_device *dev
#elif  defined(PCI_INTERFACE)
	struct pci_dev *dev
#elif  defined(PLATFORM_INTERFACE)
        struct platform_device *dev
#endif
    )
{
	int error;

	error = device_create_file(&dev->dev, &dev_attr_regoffset);
	error = device_create_file(&dev->dev, &dev_attr_regvalue);
	error = device_create_file(&dev->dev, &dev_attr_mode);
	error = device_create_file(&dev->dev, &dev_attr_hnpcapable);
	error = device_create_file(&dev->dev, &dev_attr_srpcapable);
	error = device_create_file(&dev->dev, &dev_attr_hsic_connect);
	error = device_create_file(&dev->dev, &dev_attr_inv_sel_hsic);
	error = device_create_file(&dev->dev, &dev_attr_hnp);
	error = device_create_file(&dev->dev, &dev_attr_srp);
	error = device_create_file(&dev->dev, &dev_attr_buspower);
	error = device_create_file(&dev->dev, &dev_attr_bussuspend);
	error = device_create_file(&dev->dev, &dev_attr_mode_ch_tim_en);
	error = device_create_file(&dev->dev, &dev_attr_fr_interval);
	error = device_create_file(&dev->dev, &dev_attr_busconnected);
	error = device_create_file(&dev->dev, &dev_attr_gotgctl);
	error = device_create_file(&dev->dev, &dev_attr_gusbcfg);
	error = device_create_file(&dev->dev, &dev_attr_grxfsiz);
	error = device_create_file(&dev->dev, &dev_attr_gnptxfsiz);
	error = device_create_file(&dev->dev, &dev_attr_gpvndctl);
	error = device_create_file(&dev->dev, &dev_attr_ggpio);
	error = device_create_file(&dev->dev, &dev_attr_guid);
	error = device_create_file(&dev->dev, &dev_attr_gsnpsid);
	error = device_create_file(&dev->dev, &dev_attr_devspeed);
	error = device_create_file(&dev->dev, &dev_attr_enumspeed);
	error = device_create_file(&dev->dev, &dev_attr_hptxfsiz);
	error = device_create_file(&dev->dev, &dev_attr_hprt0);
	error = device_create_file(&dev->dev, &dev_attr_remote_wakeup);
	error = device_create_file(&dev->dev, &dev_attr_rem_wakeup_pwrdn);
	error = device_create_file(&dev->dev, &dev_attr_disconnect_us);
	error = device_create_file(&dev->dev, &dev_attr_regdump);
	error = device_create_file(&dev->dev, &dev_attr_spramdump);
	error = device_create_file(&dev->dev, &dev_attr_hcddump);
	error = device_create_file(&dev->dev, &dev_attr_hcd_frrem);
	error = device_create_file(&dev->dev, &dev_attr_rd_reg_test);
	error = device_create_file(&dev->dev, &dev_attr_wr_reg_test);
#ifdef CONFIG_USB_DWC_OTG_LPM
	error = device_create_file(&dev->dev, &dev_attr_lpm_response);
	error = device_create_file(&dev->dev, &dev_attr_sleep_status);
#endif
}

void dwc_otg_attr_remove(
#ifdef LM_INTERFACE
	struct lm_device *dev
#elif  defined(PCI_INTERFACE)
	struct pci_dev *dev
#elif  defined(PLATFORM_INTERFACE)
	struct platform_device *dev
#endif
    )
{
	device_remove_file(&dev->dev, &dev_attr_regoffset);
	device_remove_file(&dev->dev, &dev_attr_regvalue);
	device_remove_file(&dev->dev, &dev_attr_mode);
	device_remove_file(&dev->dev, &dev_attr_hnpcapable);
	device_remove_file(&dev->dev, &dev_attr_srpcapable);
	device_remove_file(&dev->dev, &dev_attr_hsic_connect);
	device_remove_file(&dev->dev, &dev_attr_inv_sel_hsic);
	device_remove_file(&dev->dev, &dev_attr_hnp);
	device_remove_file(&dev->dev, &dev_attr_srp);
	device_remove_file(&dev->dev, &dev_attr_buspower);
	device_remove_file(&dev->dev, &dev_attr_bussuspend);
	device_remove_file(&dev->dev, &dev_attr_mode_ch_tim_en);
	device_remove_file(&dev->dev, &dev_attr_fr_interval);
	device_remove_file(&dev->dev, &dev_attr_busconnected);
	device_remove_file(&dev->dev, &dev_attr_gotgctl);
	device_remove_file(&dev->dev, &dev_attr_gusbcfg);
	device_remove_file(&dev->dev, &dev_attr_grxfsiz);
	device_remove_file(&dev->dev, &dev_attr_gnptxfsiz);
	device_remove_file(&dev->dev, &dev_attr_gpvndctl);
	device_remove_file(&dev->dev, &dev_attr_ggpio);
	device_remove_file(&dev->dev, &dev_attr_guid);
	device_remove_file(&dev->dev, &dev_attr_gsnpsid);
	device_remove_file(&dev->dev, &dev_attr_devspeed);
	device_remove_file(&dev->dev, &dev_attr_enumspeed);
	device_remove_file(&dev->dev, &dev_attr_hptxfsiz);
	device_remove_file(&dev->dev, &dev_attr_hprt0);
	device_remove_file(&dev->dev, &dev_attr_remote_wakeup);
	device_remove_file(&dev->dev, &dev_attr_rem_wakeup_pwrdn);
	device_remove_file(&dev->dev, &dev_attr_disconnect_us);
	device_remove_file(&dev->dev, &dev_attr_regdump);
	device_remove_file(&dev->dev, &dev_attr_spramdump);
	device_remove_file(&dev->dev, &dev_attr_hcddump);
	device_remove_file(&dev->dev, &dev_attr_hcd_frrem);
	device_remove_file(&dev->dev, &dev_attr_rd_reg_test);
	device_remove_file(&dev->dev, &dev_attr_wr_reg_test);
#ifdef CONFIG_USB_DWC_OTG_LPM
	device_remove_file(&dev->dev, &dev_attr_lpm_response);
	device_remove_file(&dev->dev, &dev_attr_sleep_status);
#endif
}

