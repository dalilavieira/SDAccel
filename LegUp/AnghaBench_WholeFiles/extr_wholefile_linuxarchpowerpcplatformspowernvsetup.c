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
struct device_node {int dummy; } ;
typedef  enum l1d_flush_type { ____Placeholder_l1d_flush_type } l1d_flush_type ;

/* Variables and functions */
 int L1D_FLUSH_FALLBACK ; 
 int L1D_FLUSH_MTTRIG ; 
 int L1D_FLUSH_ORI ; 
 int /*<<< orphan*/  SEC_FTR_BCCTRL_SERIALISED ; 
 int /*<<< orphan*/  SEC_FTR_BCCTR_FLUSH_ASSIST ; 
 int /*<<< orphan*/  SEC_FTR_BNDS_CHK_SPEC_BAR ; 
 int /*<<< orphan*/  SEC_FTR_COUNT_CACHE_DISABLED ; 
 int /*<<< orphan*/  SEC_FTR_FAVOUR_SECURITY ; 
 int /*<<< orphan*/  SEC_FTR_FLUSH_COUNT_CACHE ; 
 int /*<<< orphan*/  SEC_FTR_L1D_FLUSH_HV ; 
 int /*<<< orphan*/  SEC_FTR_L1D_FLUSH_ORI30 ; 
 int /*<<< orphan*/  SEC_FTR_L1D_FLUSH_PR ; 
 int /*<<< orphan*/  SEC_FTR_L1D_FLUSH_TRIG2 ; 
 int /*<<< orphan*/  SEC_FTR_L1D_THREAD_PRIV ; 
 int /*<<< orphan*/  SEC_FTR_SPEC_BAR_ORI31 ; 
 struct device_node* of_find_node_by_name (int /*<<< orphan*/ *,char*) ; 
 struct device_node* of_get_child_by_name (struct device_node*,char const*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_property_read_bool (struct device_node*,char const*) ; 
 int /*<<< orphan*/  security_ftr_clear (int /*<<< orphan*/ ) ; 
 scalar_t__ security_ftr_enabled (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  security_ftr_set (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setup_count_cache_flush () ; 
 int /*<<< orphan*/  setup_rfi_flush (int,int) ; 

__attribute__((used)) static inline void pnv_smp_init(void) { }

__attribute__((used)) static inline void pnv_pci_init(void) { }

__attribute__((used)) static inline void pnv_pci_shutdown(void) { }

__attribute__((used)) static bool fw_feature_is(const char *state, const char *name,
			  struct device_node *fw_features)
{
	struct device_node *np;
	bool rc = false;

	np = of_get_child_by_name(fw_features, name);
	if (np) {
		rc = of_property_read_bool(np, state);
		of_node_put(np);
	}

	return rc;
}

__attribute__((used)) static void init_fw_feat_flags(struct device_node *np)
{
	if (fw_feature_is("enabled", "inst-spec-barrier-ori31,31,0", np))
		security_ftr_set(SEC_FTR_SPEC_BAR_ORI31);

	if (fw_feature_is("enabled", "fw-bcctrl-serialized", np))
		security_ftr_set(SEC_FTR_BCCTRL_SERIALISED);

	if (fw_feature_is("enabled", "inst-l1d-flush-ori30,30,0", np))
		security_ftr_set(SEC_FTR_L1D_FLUSH_ORI30);

	if (fw_feature_is("enabled", "inst-l1d-flush-trig2", np))
		security_ftr_set(SEC_FTR_L1D_FLUSH_TRIG2);

	if (fw_feature_is("enabled", "fw-l1d-thread-split", np))
		security_ftr_set(SEC_FTR_L1D_THREAD_PRIV);

	if (fw_feature_is("enabled", "fw-count-cache-disabled", np))
		security_ftr_set(SEC_FTR_COUNT_CACHE_DISABLED);

	if (fw_feature_is("enabled", "fw-count-cache-flush-bcctr2,0,0", np))
		security_ftr_set(SEC_FTR_BCCTR_FLUSH_ASSIST);

	if (fw_feature_is("enabled", "needs-count-cache-flush-on-context-switch", np))
		security_ftr_set(SEC_FTR_FLUSH_COUNT_CACHE);

	/*
	 * The features below are enabled by default, so we instead look to see
	 * if firmware has *disabled* them, and clear them if so.
	 */
	if (fw_feature_is("disabled", "speculation-policy-favor-security", np))
		security_ftr_clear(SEC_FTR_FAVOUR_SECURITY);

	if (fw_feature_is("disabled", "needs-l1d-flush-msr-pr-0-to-1", np))
		security_ftr_clear(SEC_FTR_L1D_FLUSH_PR);

	if (fw_feature_is("disabled", "needs-l1d-flush-msr-hv-1-to-0", np))
		security_ftr_clear(SEC_FTR_L1D_FLUSH_HV);

	if (fw_feature_is("disabled", "needs-spec-barrier-for-bound-checks", np))
		security_ftr_clear(SEC_FTR_BNDS_CHK_SPEC_BAR);
}

__attribute__((used)) static void pnv_setup_rfi_flush(void)
{
	struct device_node *np, *fw_features;
	enum l1d_flush_type type;
	bool enable;

	/* Default to fallback in case fw-features are not available */
	type = L1D_FLUSH_FALLBACK;

	np = of_find_node_by_name(NULL, "ibm,opal");
	fw_features = of_get_child_by_name(np, "fw-features");
	of_node_put(np);

	if (fw_features) {
		init_fw_feat_flags(fw_features);
		of_node_put(fw_features);

		if (security_ftr_enabled(SEC_FTR_L1D_FLUSH_TRIG2))
			type = L1D_FLUSH_MTTRIG;

		if (security_ftr_enabled(SEC_FTR_L1D_FLUSH_ORI30))
			type = L1D_FLUSH_ORI;
	}

	enable = security_ftr_enabled(SEC_FTR_FAVOUR_SECURITY) && \
		 (security_ftr_enabled(SEC_FTR_L1D_FLUSH_PR)   || \
		  security_ftr_enabled(SEC_FTR_L1D_FLUSH_HV));

	setup_rfi_flush(type, enable);
	setup_count_cache_flush();
}

