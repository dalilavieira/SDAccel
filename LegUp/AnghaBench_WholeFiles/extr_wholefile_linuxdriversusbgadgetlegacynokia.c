#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct usb_gadget {int /*<<< orphan*/  dev; } ;
struct usb_function {int dummy; } ;
struct usb_configuration {int iConfiguration; } ;
struct usb_composite_dev {struct usb_gadget* gadget; } ;
struct fsg_opts {int no_configfs; int /*<<< orphan*/  common; } ;
struct fsg_config {char* vendor_name; char* product_name; int /*<<< orphan*/  can_stall; } ;
struct TYPE_5__ {int iManufacturer; int iProduct; } ;
struct TYPE_4__ {int id; } ;

/* Variables and functions */
 int ENODEV ; 
 scalar_t__ IS_ERR (struct usb_function*) ; 
 int /*<<< orphan*/  IS_ERR_OR_NULL (struct usb_function*) ; 
 int /*<<< orphan*/  NOKIA_LONG_NAME ; 
 int PTR_ERR (struct usb_function*) ; 
 size_t STRING_DESCRIPTION_IDX ; 
 size_t USB_GADGET_MANUFACTURER_IDX ; 
 size_t USB_GADGET_PRODUCT_IDX ; 
 int /*<<< orphan*/  coverwrite ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 TYPE_3__ device_desc ; 
 struct usb_function* f_acm_cfg1 ; 
 struct usb_function* f_acm_cfg2 ; 
 struct usb_function* f_ecm_cfg1 ; 
 struct usb_function* f_ecm_cfg2 ; 
 struct usb_function* f_msg_cfg1 ; 
 struct usb_function* f_msg_cfg2 ; 
 struct usb_function* f_obex1_cfg1 ; 
 struct usb_function* f_obex1_cfg2 ; 
 struct usb_function* f_obex2_cfg1 ; 
 struct usb_function* f_obex2_cfg2 ; 
 struct usb_function* f_phonet_cfg1 ; 
 struct usb_function* f_phonet_cfg2 ; 
 struct usb_function* fi_acm ; 
 struct usb_function* fi_ecm ; 
 struct usb_function* fi_msg ; 
 struct usb_function* fi_obex1 ; 
 struct usb_function* fi_obex2 ; 
 struct usb_function* fi_phonet ; 
 int fsg_common_create_luns (int /*<<< orphan*/ ,struct fsg_config*) ; 
 int /*<<< orphan*/  fsg_common_free_buffers (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fsg_common_remove_luns (int /*<<< orphan*/ ) ; 
 int fsg_common_set_cdev (int /*<<< orphan*/ ,struct usb_composite_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fsg_common_set_inquiry_string (int /*<<< orphan*/ ,char*,char*) ; 
 int fsg_common_set_num_buffers (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fsg_common_set_sysfs (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  fsg_config_from_params (struct fsg_config*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fsg_mod_data ; 
 int /*<<< orphan*/  fsg_num_buffers ; 
 struct fsg_opts* fsg_opts_from_func_inst (struct usb_function*) ; 
 int /*<<< orphan*/  gadget_is_altset_supported (struct usb_gadget*) ; 
 struct usb_configuration nokia_config_100ma_driver ; 
 struct usb_configuration nokia_config_500ma_driver ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 TYPE_1__* strings_dev ; 
 int usb_add_config (struct usb_composite_dev*,struct usb_configuration*,int (*) (struct usb_configuration*)) ; 
 int usb_add_function (struct usb_configuration*,struct usb_function*) ; 
 int /*<<< orphan*/  usb_composite_overwrite_options (struct usb_composite_dev*,int /*<<< orphan*/ *) ; 
 struct usb_function* usb_get_function (struct usb_function*) ; 
 struct usb_function* usb_get_function_instance (char*) ; 
 int /*<<< orphan*/  usb_put_function (struct usb_function*) ; 
 int /*<<< orphan*/  usb_put_function_instance (struct usb_function*) ; 
 int /*<<< orphan*/  usb_remove_function (struct usb_configuration*,struct usb_function*) ; 
 int usb_string_ids_tab (struct usb_composite_dev*,TYPE_1__*) ; 

__attribute__((used)) static int nokia_bind_config(struct usb_configuration *c)
{
	struct usb_function *f_acm;
	struct usb_function *f_phonet = NULL;
	struct usb_function *f_obex1 = NULL;
	struct usb_function *f_ecm;
	struct usb_function *f_obex2 = NULL;
	struct usb_function *f_msg;
	int status = 0;
	int obex1_stat = -1;
	int obex2_stat = -1;
	int phonet_stat = -1;

	if (!IS_ERR(fi_phonet)) {
		f_phonet = usb_get_function(fi_phonet);
		if (IS_ERR(f_phonet))
			pr_debug("could not get phonet function\n");
	}

	if (!IS_ERR(fi_obex1)) {
		f_obex1 = usb_get_function(fi_obex1);
		if (IS_ERR(f_obex1))
			pr_debug("could not get obex function 0\n");
	}

	if (!IS_ERR(fi_obex2)) {
		f_obex2 = usb_get_function(fi_obex2);
		if (IS_ERR(f_obex2))
			pr_debug("could not get obex function 1\n");
	}

	f_acm = usb_get_function(fi_acm);
	if (IS_ERR(f_acm)) {
		status = PTR_ERR(f_acm);
		goto err_get_acm;
	}

	f_ecm = usb_get_function(fi_ecm);
	if (IS_ERR(f_ecm)) {
		status = PTR_ERR(f_ecm);
		goto err_get_ecm;
	}

	f_msg = usb_get_function(fi_msg);
	if (IS_ERR(f_msg)) {
		status = PTR_ERR(f_msg);
		goto err_get_msg;
	}

	if (!IS_ERR_OR_NULL(f_phonet)) {
		phonet_stat = usb_add_function(c, f_phonet);
		if (phonet_stat)
			pr_debug("could not add phonet function\n");
	}

	if (!IS_ERR_OR_NULL(f_obex1)) {
		obex1_stat = usb_add_function(c, f_obex1);
		if (obex1_stat)
			pr_debug("could not add obex function 0\n");
	}

	if (!IS_ERR_OR_NULL(f_obex2)) {
		obex2_stat = usb_add_function(c, f_obex2);
		if (obex2_stat)
			pr_debug("could not add obex function 1\n");
	}

	status = usb_add_function(c, f_acm);
	if (status)
		goto err_conf;

	status = usb_add_function(c, f_ecm);
	if (status) {
		pr_debug("could not bind ecm config %d\n", status);
		goto err_ecm;
	}

	status = usb_add_function(c, f_msg);
	if (status)
		goto err_msg;

	if (c == &nokia_config_500ma_driver) {
		f_acm_cfg1 = f_acm;
		f_ecm_cfg1 = f_ecm;
		f_phonet_cfg1 = f_phonet;
		f_obex1_cfg1 = f_obex1;
		f_obex2_cfg1 = f_obex2;
		f_msg_cfg1 = f_msg;
	} else {
		f_acm_cfg2 = f_acm;
		f_ecm_cfg2 = f_ecm;
		f_phonet_cfg2 = f_phonet;
		f_obex1_cfg2 = f_obex1;
		f_obex2_cfg2 = f_obex2;
		f_msg_cfg2 = f_msg;
	}

	return status;
err_msg:
	usb_remove_function(c, f_ecm);
err_ecm:
	usb_remove_function(c, f_acm);
err_conf:
	if (!obex2_stat)
		usb_remove_function(c, f_obex2);
	if (!obex1_stat)
		usb_remove_function(c, f_obex1);
	if (!phonet_stat)
		usb_remove_function(c, f_phonet);
	usb_put_function(f_msg);
err_get_msg:
	usb_put_function(f_ecm);
err_get_ecm:
	usb_put_function(f_acm);
err_get_acm:
	if (!IS_ERR_OR_NULL(f_obex2))
		usb_put_function(f_obex2);
	if (!IS_ERR_OR_NULL(f_obex1))
		usb_put_function(f_obex1);
	if (!IS_ERR_OR_NULL(f_phonet))
		usb_put_function(f_phonet);
	return status;
}

__attribute__((used)) static int nokia_bind(struct usb_composite_dev *cdev)
{
	struct usb_gadget	*gadget = cdev->gadget;
	struct fsg_opts		*fsg_opts;
	struct fsg_config	fsg_config;
	int			status;

	status = usb_string_ids_tab(cdev, strings_dev);
	if (status < 0)
		goto err_usb;
	device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
	device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
	status = strings_dev[STRING_DESCRIPTION_IDX].id;
	nokia_config_500ma_driver.iConfiguration = status;
	nokia_config_100ma_driver.iConfiguration = status;

	if (!gadget_is_altset_supported(gadget)) {
		status = -ENODEV;
		goto err_usb;
	}

	fi_phonet = usb_get_function_instance("phonet");
	if (IS_ERR(fi_phonet))
		pr_debug("could not find phonet function\n");

	fi_obex1 = usb_get_function_instance("obex");
	if (IS_ERR(fi_obex1))
		pr_debug("could not find obex function 1\n");

	fi_obex2 = usb_get_function_instance("obex");
	if (IS_ERR(fi_obex2))
		pr_debug("could not find obex function 2\n");

	fi_acm = usb_get_function_instance("acm");
	if (IS_ERR(fi_acm)) {
		status = PTR_ERR(fi_acm);
		goto err_obex2_inst;
	}

	fi_ecm = usb_get_function_instance("ecm");
	if (IS_ERR(fi_ecm)) {
		status = PTR_ERR(fi_ecm);
		goto err_acm_inst;
	}

	fi_msg = usb_get_function_instance("mass_storage");
	if (IS_ERR(fi_msg)) {
		status = PTR_ERR(fi_msg);
		goto err_ecm_inst;
	}

	/* set up mass storage function */
	fsg_config_from_params(&fsg_config, &fsg_mod_data, fsg_num_buffers);
	fsg_config.vendor_name = "Nokia";
	fsg_config.product_name = "N900";

	fsg_opts = fsg_opts_from_func_inst(fi_msg);
	fsg_opts->no_configfs = true;

	status = fsg_common_set_num_buffers(fsg_opts->common, fsg_num_buffers);
	if (status)
		goto err_msg_inst;

	status = fsg_common_set_cdev(fsg_opts->common, cdev, fsg_config.can_stall);
	if (status)
		goto err_msg_buf;

	fsg_common_set_sysfs(fsg_opts->common, true);

	status = fsg_common_create_luns(fsg_opts->common, &fsg_config);
	if (status)
		goto err_msg_buf;

	fsg_common_set_inquiry_string(fsg_opts->common, fsg_config.vendor_name,
				      fsg_config.product_name);

	/* finally register the configuration */
	status = usb_add_config(cdev, &nokia_config_500ma_driver,
			nokia_bind_config);
	if (status < 0)
		goto err_msg_luns;

	status = usb_add_config(cdev, &nokia_config_100ma_driver,
			nokia_bind_config);
	if (status < 0)
		goto err_put_cfg1;

	usb_composite_overwrite_options(cdev, &coverwrite);
	dev_info(&gadget->dev, "%s\n", NOKIA_LONG_NAME);

	return 0;

err_put_cfg1:
	usb_put_function(f_acm_cfg1);
	if (!IS_ERR_OR_NULL(f_obex1_cfg1))
		usb_put_function(f_obex1_cfg1);
	if (!IS_ERR_OR_NULL(f_obex2_cfg1))
		usb_put_function(f_obex2_cfg1);
	if (!IS_ERR_OR_NULL(f_phonet_cfg1))
		usb_put_function(f_phonet_cfg1);
	usb_put_function(f_ecm_cfg1);
err_msg_luns:
	fsg_common_remove_luns(fsg_opts->common);
err_msg_buf:
	fsg_common_free_buffers(fsg_opts->common);
err_msg_inst:
	usb_put_function_instance(fi_msg);
err_ecm_inst:
	usb_put_function_instance(fi_ecm);
err_acm_inst:
	usb_put_function_instance(fi_acm);
err_obex2_inst:
	if (!IS_ERR(fi_obex2))
		usb_put_function_instance(fi_obex2);
	if (!IS_ERR(fi_obex1))
		usb_put_function_instance(fi_obex1);
	if (!IS_ERR(fi_phonet))
		usb_put_function_instance(fi_phonet);
err_usb:
	return status;
}

__attribute__((used)) static int nokia_unbind(struct usb_composite_dev *cdev)
{
	if (!IS_ERR_OR_NULL(f_obex1_cfg2))
		usb_put_function(f_obex1_cfg2);
	if (!IS_ERR_OR_NULL(f_obex2_cfg2))
		usb_put_function(f_obex2_cfg2);
	if (!IS_ERR_OR_NULL(f_obex1_cfg1))
		usb_put_function(f_obex1_cfg1);
	if (!IS_ERR_OR_NULL(f_obex2_cfg1))
		usb_put_function(f_obex2_cfg1);
	if (!IS_ERR_OR_NULL(f_phonet_cfg1))
		usb_put_function(f_phonet_cfg1);
	if (!IS_ERR_OR_NULL(f_phonet_cfg2))
		usb_put_function(f_phonet_cfg2);
	usb_put_function(f_acm_cfg1);
	usb_put_function(f_acm_cfg2);
	usb_put_function(f_ecm_cfg1);
	usb_put_function(f_ecm_cfg2);
	usb_put_function(f_msg_cfg1);
	usb_put_function(f_msg_cfg2);

	usb_put_function_instance(fi_msg);
	usb_put_function_instance(fi_ecm);
	if (!IS_ERR(fi_obex2))
		usb_put_function_instance(fi_obex2);
	if (!IS_ERR(fi_obex1))
		usb_put_function_instance(fi_obex1);
	if (!IS_ERR(fi_phonet))
		usb_put_function_instance(fi_phonet);
	usb_put_function_instance(fi_acm);

	return 0;
}

