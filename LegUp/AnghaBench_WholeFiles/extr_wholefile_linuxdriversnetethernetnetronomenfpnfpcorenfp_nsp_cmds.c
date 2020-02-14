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
typedef  int u8 ;
typedef  int u32 ;
struct nsp_identify {int /*<<< orphan*/  sensor_mask; int /*<<< orphan*/  nsp; int /*<<< orphan*/  secondary; int /*<<< orphan*/  primary; int /*<<< orphan*/  br_nsp; int /*<<< orphan*/  br_secondary; int /*<<< orphan*/  br_primary; int /*<<< orphan*/  flags; int /*<<< orphan*/  version; } ;
struct nfp_sensors {int /*<<< orphan*/  assembly_3v3_power; int /*<<< orphan*/  assembly_12v_power; int /*<<< orphan*/  assembly_power; int /*<<< orphan*/  chip_temp; } ;
struct nfp_nsp_identify {char* version; int /*<<< orphan*/  sensor_mask; void* nsp; void* secondary; void* primary; int /*<<< orphan*/  br_nsp; int /*<<< orphan*/  br_secondary; int /*<<< orphan*/  br_primary; int /*<<< orphan*/  flags; } ;
struct nfp_nsp {int dummy; } ;
struct nfp_eth_table_port {unsigned int fec_modes_supported; } ;
struct nfp_cpp {int dummy; } ;
typedef  int /*<<< orphan*/  s ;
typedef  enum nfp_nsp_sensor_id { ____Placeholder_nfp_nsp_sensor_id } nfp_nsp_sensor_id ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int) ; 
 int EINVAL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct nfp_nsp*) ; 
 int NFP_CPP_INTERFACE_UNIT_of (int /*<<< orphan*/ ) ; 
 int NFP_CPP_TARGET_ID_MASK ; 
#define  NFP_SENSOR_ASSEMBLY_12V_POWER 131 
#define  NFP_SENSOR_ASSEMBLY_3V3_POWER 130 
#define  NFP_SENSOR_ASSEMBLY_POWER 129 
#define  NFP_SENSOR_CHIP_TEMPERATURE 128 
 int PTR_ERR (struct nfp_nsp*) ; 
 int /*<<< orphan*/  kfree (struct nsp_identify*) ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 void* le16_to_cpu (int /*<<< orphan*/ ) ; 
 long le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nfp_cpp_interface (struct nfp_cpp*) ; 
 int /*<<< orphan*/  nfp_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  nfp_nsp_close (struct nfp_nsp*) ; 
 int /*<<< orphan*/  nfp_nsp_cpp (struct nfp_nsp*) ; 
 int nfp_nsp_get_abi_ver_minor (struct nfp_nsp*) ; 
 struct nfp_nsp* nfp_nsp_open (struct nfp_cpp*) ; 
 int nfp_nsp_read_identify (struct nfp_nsp*,struct nsp_identify*,int) ; 
 int nfp_nsp_read_sensors (struct nfp_nsp*,int /*<<< orphan*/ ,struct nfp_sensors*,int) ; 

__attribute__((used)) static inline u8 NFP_CPP_ID_TARGET_of(u32 id)
{
	return (id >> 24) & NFP_CPP_TARGET_ID_MASK;
}

__attribute__((used)) static inline u8 NFP_CPP_ID_TOKEN_of(u32 id)
{
	return (id >> 16) & 0xff;
}

__attribute__((used)) static inline u8 NFP_CPP_ID_ACTION_of(u32 id)
{
	return (id >> 8) & 0xff;
}

__attribute__((used)) static inline u8 NFP_CPP_ID_ISLAND_of(u32 id)
{
	return (id >> 0) & 0xff;
}

__attribute__((used)) static inline u8 nfp_cppcore_pcie_unit(struct nfp_cpp *cpp)
{
	return NFP_CPP_INTERFACE_UNIT_of(nfp_cpp_interface(cpp));
}

__attribute__((used)) static inline bool nfp_nsp_has_mac_reinit(struct nfp_nsp *state)
{
	return nfp_nsp_get_abi_ver_minor(state) > 20;
}

__attribute__((used)) static inline bool nfp_eth_can_support_fec(struct nfp_eth_table_port *eth_port)
{
	return !!eth_port->fec_modes_supported;
}

__attribute__((used)) static inline unsigned int
nfp_eth_supported_fec_modes(struct nfp_eth_table_port *eth_port)
{
	return eth_port->fec_modes_supported;
}

struct nfp_nsp_identify *__nfp_nsp_identify(struct nfp_nsp *nsp)
{
	struct nfp_nsp_identify *nspi = NULL;
	struct nsp_identify *ni;
	int ret;

	if (nfp_nsp_get_abi_ver_minor(nsp) < 15)
		return NULL;

	ni = kzalloc(sizeof(*ni), GFP_KERNEL);
	if (!ni)
		return NULL;

	ret = nfp_nsp_read_identify(nsp, ni, sizeof(*ni));
	if (ret < 0) {
		nfp_err(nfp_nsp_cpp(nsp), "reading bsp version failed %d\n",
			ret);
		goto exit_free;
	}

	nspi = kzalloc(sizeof(*nspi), GFP_KERNEL);
	if (!nspi)
		goto exit_free;

	memcpy(nspi->version, ni->version, sizeof(nspi->version));
	nspi->version[sizeof(nspi->version) - 1] = '\0';
	nspi->flags = ni->flags;
	nspi->br_primary = ni->br_primary;
	nspi->br_secondary = ni->br_secondary;
	nspi->br_nsp = ni->br_nsp;
	nspi->primary = le16_to_cpu(ni->primary);
	nspi->secondary = le16_to_cpu(ni->secondary);
	nspi->nsp = le16_to_cpu(ni->nsp);
	nspi->sensor_mask = le64_to_cpu(ni->sensor_mask);

exit_free:
	kfree(ni);
	return nspi;
}

int nfp_hwmon_read_sensor(struct nfp_cpp *cpp, enum nfp_nsp_sensor_id id,
			  long *val)
{
	struct nfp_sensors s;
	struct nfp_nsp *nsp;
	int ret;

	nsp = nfp_nsp_open(cpp);
	if (IS_ERR(nsp))
		return PTR_ERR(nsp);

	ret = nfp_nsp_read_sensors(nsp, BIT(id), &s, sizeof(s));
	nfp_nsp_close(nsp);

	if (ret < 0)
		return ret;

	switch (id) {
	case NFP_SENSOR_CHIP_TEMPERATURE:
		*val = le32_to_cpu(s.chip_temp);
		break;
	case NFP_SENSOR_ASSEMBLY_POWER:
		*val = le32_to_cpu(s.assembly_power);
		break;
	case NFP_SENSOR_ASSEMBLY_12V_POWER:
		*val = le32_to_cpu(s.assembly_12v_power);
		break;
	case NFP_SENSOR_ASSEMBLY_3V3_POWER:
		*val = le32_to_cpu(s.assembly_3v3_power);
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

