#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  unsigned int u32 ;
typedef  int /*<<< orphan*/  const u16 ;
struct tpm_readpubek_out {int* algorithm; int* encscheme; int* sigscheme; int* parameters; int* modulus; void* keysize; } ;
struct tpm_input_header {void* length; void* tag; void* ordinal; } ;
struct tpm_chip {scalar_t__* duration; scalar_t__ timeout_a; scalar_t__ timeout_b; scalar_t__ timeout_c; scalar_t__ timeout_d; int flags; scalar_t__ groups_cnt; int /*<<< orphan*/ ** groups; scalar_t__ timeout_adjusted; scalar_t__ duration_adjusted; TYPE_5__* ops; } ;
struct tpm_buf {int flags; int /*<<< orphan*/ * data; int /*<<< orphan*/  data_page; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_11__ {int Major; int Minor; int revMajor; int revMinor; } ;
struct TYPE_10__ {int Major; int Minor; int revMajor; int revMinor; } ;
struct TYPE_9__ {int deactivated; } ;
struct TYPE_8__ {int /*<<< orphan*/  deactivated; int /*<<< orphan*/  disable; } ;
struct TYPE_13__ {int owned; TYPE_4__ tpm_version; TYPE_3__ tpm_version_1_2; void* manufacturer_id; TYPE_2__ stclear_flags; TYPE_1__ perm_flags; void* num_pcrs; } ;
typedef  TYPE_6__ cap_t ;
typedef  int /*<<< orphan*/  anti_replay ;
typedef  void* __be32 ;
typedef  void* __be16 ;
struct TYPE_12__ {int /*<<< orphan*/  (* cancel ) (struct tpm_chip*) ;} ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_HIGHUSER ; 
 unsigned int PAGE_SIZE ; 
 int /*<<< orphan*/  READ_PUBEK_RESULT_MIN_BODY_SIZE ; 
 int TPM_BUF_OVERFLOW ; 
 int /*<<< orphan*/  TPM_CAP_FLAG_PERM ; 
 int /*<<< orphan*/  TPM_CAP_FLAG_VOL ; 
 int /*<<< orphan*/  TPM_CAP_PROP_MANUFACTURER ; 
 int /*<<< orphan*/  TPM_CAP_PROP_OWNER ; 
 int /*<<< orphan*/  TPM_CAP_PROP_PCR ; 
 int /*<<< orphan*/  TPM_CAP_VERSION_1_1 ; 
 int /*<<< orphan*/  TPM_CAP_VERSION_1_2 ; 
 int TPM_CHIP_FLAG_TPM2 ; 
 int TPM_DIGEST_SIZE ; 
 size_t TPM_LONG ; 
 size_t TPM_MEDIUM ; 
 unsigned int TPM_ORD_READPUBEK ; 
 size_t TPM_SHORT ; 
 int /*<<< orphan*/  const TPM_TAG_RQU_COMMAND ; 
 scalar_t__ TPM_TIMEOUT_RANGE_US ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  __free_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alloc_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  const be16_to_cpu (void*) ; 
 int be32_to_cpu (void*) ; 
 void* cpu_to_be16 (int /*<<< orphan*/  const) ; 
 void* cpu_to_be32 (unsigned int const) ; 
 int jiffies_to_usecs (scalar_t__) ; 
 int /*<<< orphan*/ * kmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kunmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,unsigned char const*,unsigned int) ; 
 int /*<<< orphan*/  memset (char**,int /*<<< orphan*/ ,int) ; 
 int sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  stub1 (struct tpm_chip*) ; 
 struct tpm_chip* to_tpm_chip (struct device*) ; 
 int /*<<< orphan*/  tpm_dev_group ; 
 int tpm_getcap (struct tpm_chip*,int /*<<< orphan*/ ,TYPE_6__*,char*,int) ; 
 int tpm_pcr_read_dev (struct tpm_chip*,int,int*) ; 
 int tpm_transmit_cmd (struct tpm_chip*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  usleep_range (scalar_t__,unsigned int) ; 

__attribute__((used)) static inline void tpm_buf_reset(struct tpm_buf *buf, u16 tag, u32 ordinal)
{
	struct tpm_input_header *head;
	head = (struct tpm_input_header *)buf->data;
	head->tag = cpu_to_be16(tag);
	head->length = cpu_to_be32(sizeof(*head));
	head->ordinal = cpu_to_be32(ordinal);
}

__attribute__((used)) static inline int tpm_buf_init(struct tpm_buf *buf, u16 tag, u32 ordinal)
{
	buf->data_page = alloc_page(GFP_HIGHUSER);
	if (!buf->data_page)
		return -ENOMEM;

	buf->flags = 0;
	buf->data = kmap(buf->data_page);
	tpm_buf_reset(buf, tag, ordinal);
	return 0;
}

__attribute__((used)) static inline void tpm_buf_destroy(struct tpm_buf *buf)
{
	kunmap(buf->data_page);
	__free_page(buf->data_page);
}

__attribute__((used)) static inline u32 tpm_buf_length(struct tpm_buf *buf)
{
	struct tpm_input_header *head = (struct tpm_input_header *) buf->data;

	return be32_to_cpu(head->length);
}

__attribute__((used)) static inline u16 tpm_buf_tag(struct tpm_buf *buf)
{
	struct tpm_input_header *head = (struct tpm_input_header *) buf->data;

	return be16_to_cpu(head->tag);
}

__attribute__((used)) static inline void tpm_buf_append(struct tpm_buf *buf,
				  const unsigned char *new_data,
				  unsigned int new_len)
{
	struct tpm_input_header *head = (struct tpm_input_header *) buf->data;
	u32 len = tpm_buf_length(buf);

	/* Return silently if overflow has already happened. */
	if (buf->flags & TPM_BUF_OVERFLOW)
		return;

	if ((len + new_len) > PAGE_SIZE) {
		WARN(1, "tpm_buf: overflow\n");
		buf->flags |= TPM_BUF_OVERFLOW;
		return;
	}

	memcpy(&buf->data[len], new_data, new_len);
	head->length = cpu_to_be32(len + new_len);
}

__attribute__((used)) static inline void tpm_buf_append_u8(struct tpm_buf *buf, const u8 value)
{
	tpm_buf_append(buf, &value, 1);
}

__attribute__((used)) static inline void tpm_buf_append_u16(struct tpm_buf *buf, const u16 value)
{
	__be16 value2 = cpu_to_be16(value);

	tpm_buf_append(buf, (u8 *) &value2, 2);
}

__attribute__((used)) static inline void tpm_buf_append_u32(struct tpm_buf *buf, const u32 value)
{
	__be32 value2 = cpu_to_be32(value);

	tpm_buf_append(buf, (u8 *) &value2, 4);
}

__attribute__((used)) static inline void tpm_msleep(unsigned int delay_msec)
{
	usleep_range((delay_msec * 1000) - TPM_TIMEOUT_RANGE_US,
		     delay_msec * 1000);
}

__attribute__((used)) static inline void tpm_add_ppi(struct tpm_chip *chip)
{
}

__attribute__((used)) static inline u32 tpm2_rc_value(u32 rc)
{
	return (rc & BIT(7)) ? rc & 0xff : rc;
}

__attribute__((used)) static ssize_t pubek_show(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	struct tpm_buf tpm_buf;
	struct tpm_readpubek_out *out;
	ssize_t rc;
	int i;
	char *str = buf;
	struct tpm_chip *chip = to_tpm_chip(dev);
	char anti_replay[20];

	memset(&anti_replay, 0, sizeof(anti_replay));

	rc = tpm_buf_init(&tpm_buf, TPM_TAG_RQU_COMMAND, TPM_ORD_READPUBEK);
	if (rc)
		return rc;

	tpm_buf_append(&tpm_buf, anti_replay, sizeof(anti_replay));

	rc = tpm_transmit_cmd(chip, NULL, tpm_buf.data, PAGE_SIZE,
			      READ_PUBEK_RESULT_MIN_BODY_SIZE, 0,
			      "attempting to read the PUBEK");
	if (rc) {
		tpm_buf_destroy(&tpm_buf);
		return 0;
	}

	out = (struct tpm_readpubek_out *)&tpm_buf.data[10];
	str +=
	    sprintf(str,
		    "Algorithm: %02X %02X %02X %02X\n"
		    "Encscheme: %02X %02X\n"
		    "Sigscheme: %02X %02X\n"
		    "Parameters: %02X %02X %02X %02X "
		    "%02X %02X %02X %02X "
		    "%02X %02X %02X %02X\n"
		    "Modulus length: %d\n"
		    "Modulus:\n",
		    out->algorithm[0], out->algorithm[1], out->algorithm[2],
		    out->algorithm[3],
		    out->encscheme[0], out->encscheme[1],
		    out->sigscheme[0], out->sigscheme[1],
		    out->parameters[0], out->parameters[1],
		    out->parameters[2], out->parameters[3],
		    out->parameters[4], out->parameters[5],
		    out->parameters[6], out->parameters[7],
		    out->parameters[8], out->parameters[9],
		    out->parameters[10], out->parameters[11],
		    be32_to_cpu(out->keysize));

	for (i = 0; i < 256; i++) {
		str += sprintf(str, "%02X ", out->modulus[i]);
		if ((i + 1) % 16 == 0)
			str += sprintf(str, "\n");
	}

	rc = str - buf;
	tpm_buf_destroy(&tpm_buf);
	return rc;
}

__attribute__((used)) static ssize_t pcrs_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	cap_t cap;
	u8 digest[TPM_DIGEST_SIZE];
	ssize_t rc;
	int i, j, num_pcrs;
	char *str = buf;
	struct tpm_chip *chip = to_tpm_chip(dev);

	rc = tpm_getcap(chip, TPM_CAP_PROP_PCR, &cap,
			"attempting to determine the number of PCRS",
			sizeof(cap.num_pcrs));
	if (rc)
		return 0;

	num_pcrs = be32_to_cpu(cap.num_pcrs);
	for (i = 0; i < num_pcrs; i++) {
		rc = tpm_pcr_read_dev(chip, i, digest);
		if (rc)
			break;
		str += sprintf(str, "PCR-%02d: ", i);
		for (j = 0; j < TPM_DIGEST_SIZE; j++)
			str += sprintf(str, "%02X ", digest[j]);
		str += sprintf(str, "\n");
	}
	return str - buf;
}

__attribute__((used)) static ssize_t enabled_show(struct device *dev, struct device_attribute *attr,
		     char *buf)
{
	cap_t cap;
	ssize_t rc;

	rc = tpm_getcap(to_tpm_chip(dev), TPM_CAP_FLAG_PERM, &cap,
			"attempting to determine the permanent enabled state",
			sizeof(cap.perm_flags));
	if (rc)
		return 0;

	rc = sprintf(buf, "%d\n", !cap.perm_flags.disable);
	return rc;
}

__attribute__((used)) static ssize_t active_show(struct device *dev, struct device_attribute *attr,
		    char *buf)
{
	cap_t cap;
	ssize_t rc;

	rc = tpm_getcap(to_tpm_chip(dev), TPM_CAP_FLAG_PERM, &cap,
			"attempting to determine the permanent active state",
			sizeof(cap.perm_flags));
	if (rc)
		return 0;

	rc = sprintf(buf, "%d\n", !cap.perm_flags.deactivated);
	return rc;
}

__attribute__((used)) static ssize_t owned_show(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	cap_t cap;
	ssize_t rc;

	rc = tpm_getcap(to_tpm_chip(dev), TPM_CAP_PROP_OWNER, &cap,
			"attempting to determine the owner state",
			sizeof(cap.owned));
	if (rc)
		return 0;

	rc = sprintf(buf, "%d\n", cap.owned);
	return rc;
}

__attribute__((used)) static ssize_t temp_deactivated_show(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	cap_t cap;
	ssize_t rc;

	rc = tpm_getcap(to_tpm_chip(dev), TPM_CAP_FLAG_VOL, &cap,
			"attempting to determine the temporary state",
			sizeof(cap.stclear_flags));
	if (rc)
		return 0;

	rc = sprintf(buf, "%d\n", cap.stclear_flags.deactivated);
	return rc;
}

__attribute__((used)) static ssize_t caps_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	struct tpm_chip *chip = to_tpm_chip(dev);
	cap_t cap;
	ssize_t rc;
	char *str = buf;

	rc = tpm_getcap(chip, TPM_CAP_PROP_MANUFACTURER, &cap,
			"attempting to determine the manufacturer",
			sizeof(cap.manufacturer_id));
	if (rc)
		return 0;
	str += sprintf(str, "Manufacturer: 0x%x\n",
		       be32_to_cpu(cap.manufacturer_id));

	/* Try to get a TPM version 1.2 TPM_CAP_VERSION_INFO */
	rc = tpm_getcap(chip, TPM_CAP_VERSION_1_2, &cap,
			"attempting to determine the 1.2 version",
			sizeof(cap.tpm_version_1_2));
	if (!rc) {
		str += sprintf(str,
			       "TCG version: %d.%d\nFirmware version: %d.%d\n",
			       cap.tpm_version_1_2.Major,
			       cap.tpm_version_1_2.Minor,
			       cap.tpm_version_1_2.revMajor,
			       cap.tpm_version_1_2.revMinor);
	} else {
		/* Otherwise just use TPM_STRUCT_VER */
		rc = tpm_getcap(chip, TPM_CAP_VERSION_1_1, &cap,
				"attempting to determine the 1.1 version",
				sizeof(cap.tpm_version));
		if (rc)
			return 0;
		str += sprintf(str,
			       "TCG version: %d.%d\nFirmware version: %d.%d\n",
			       cap.tpm_version.Major,
			       cap.tpm_version.Minor,
			       cap.tpm_version.revMajor,
			       cap.tpm_version.revMinor);
	}

	return str - buf;
}

__attribute__((used)) static ssize_t cancel_store(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	struct tpm_chip *chip = to_tpm_chip(dev);
	if (chip == NULL)
		return 0;

	chip->ops->cancel(chip);
	return count;
}

__attribute__((used)) static ssize_t durations_show(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	struct tpm_chip *chip = to_tpm_chip(dev);

	if (chip->duration[TPM_LONG] == 0)
		return 0;

	return sprintf(buf, "%d %d %d [%s]\n",
		       jiffies_to_usecs(chip->duration[TPM_SHORT]),
		       jiffies_to_usecs(chip->duration[TPM_MEDIUM]),
		       jiffies_to_usecs(chip->duration[TPM_LONG]),
		       chip->duration_adjusted
		       ? "adjusted" : "original");
}

__attribute__((used)) static ssize_t timeouts_show(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	struct tpm_chip *chip = to_tpm_chip(dev);

	return sprintf(buf, "%d %d %d %d [%s]\n",
		       jiffies_to_usecs(chip->timeout_a),
		       jiffies_to_usecs(chip->timeout_b),
		       jiffies_to_usecs(chip->timeout_c),
		       jiffies_to_usecs(chip->timeout_d),
		       chip->timeout_adjusted
		       ? "adjusted" : "original");
}

void tpm_sysfs_add_device(struct tpm_chip *chip)
{
	/* XXX: If you wish to remove this restriction, you must first update
	 * tpm_sysfs to explicitly lock chip->ops.
	 */
	if (chip->flags & TPM_CHIP_FLAG_TPM2)
		return;

	/* The sysfs routines rely on an implicit tpm_try_get_ops, device_del
	 * is called before ops is null'd and the sysfs core synchronizes this
	 * removal so that no callbacks are running or can run again
	 */
	WARN_ON(chip->groups_cnt != 0);
	chip->groups[chip->groups_cnt++] = &tpm_dev_group;
}

