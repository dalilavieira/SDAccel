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
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
struct acpi_generic_address {int bit_offset; int bit_width; int access_width; scalar_t__ space_id; int address; } ;
struct acpi_bit_register_info {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  scalar_t__ acpi_physical_address ;
typedef  scalar_t__ acpi_io_address ;
typedef  int /*<<< orphan*/  acpi_cpu_flags ;
struct TYPE_2__ {scalar_t__ smi_command; struct acpi_generic_address xpm_timer_block; struct acpi_generic_address xpm2_control_block; struct acpi_generic_address xpm1b_control_block; struct acpi_generic_address xpm1a_control_block; } ;

/* Variables and functions */
 int ACPI_ACCESS_BIT_WIDTH (int) ; 
 scalar_t__ ACPI_ADR_SPACE_SYSTEM_IO ; 
 scalar_t__ ACPI_ADR_SPACE_SYSTEM_MEMORY ; 
 int ACPI_BITMASK_ALL_FIXED_STATUS ; 
 int ACPI_BITREG_MAX ; 
 int /*<<< orphan*/  ACPI_DB_IO ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int ACPI_DIV_8 (int) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FORMAT_UINT64 (int) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int ACPI_GET_BITS (int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_INSERT_BITS (int,int /*<<< orphan*/ ,int) ; 
 scalar_t__ ACPI_IS_ALIGNED (int,int) ; 
 scalar_t__ ACPI_IS_POWER_OF_TWO (int) ; 
 int /*<<< orphan*/  ACPI_MASK_BITS_ABOVE_64 (int) ; 
 int /*<<< orphan*/  ACPI_MOVE_64_TO_64 (int*,int*) ; 
 int /*<<< orphan*/  ACPI_PM1_CONTROL_PRESERVED_BITS ; 
 int ACPI_PM1_CONTROL_WRITEONLY_BITS ; 
 int ACPI_PM1_STATUS_PRESERVED_BITS ; 
 int /*<<< orphan*/  ACPI_PM2_CONTROL_PRESERVED_BITS ; 
#define  ACPI_REGISTER_PM1_CONTROL 133 
#define  ACPI_REGISTER_PM1_ENABLE 132 
#define  ACPI_REGISTER_PM1_STATUS 131 
#define  ACPI_REGISTER_PM2_CONTROL 130 
#define  ACPI_REGISTER_PM_TIMER 129 
#define  ACPI_REGISTER_SMI_COMMAND_BLOCK 128 
 int ACPI_ROUND_UP (int,int) ; 
 int ACPI_ROUND_UP_POWER_OF_TWO_8 (int) ; 
 int /*<<< orphan*/  ACPI_SET_BITS (int*,int,int /*<<< orphan*/ ,int) ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_WARNING (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_BAD_ADDRESS ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AE_SUPPORT ; 
 int /*<<< orphan*/  acpi_ev_walk_gpe_list (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_1__ acpi_gbl_FADT ; 
 struct acpi_bit_register_info* acpi_gbl_bit_register_info ; 
 int /*<<< orphan*/  acpi_gbl_hardware_lock ; 
 struct acpi_generic_address acpi_gbl_xpm1a_enable ; 
 struct acpi_generic_address acpi_gbl_xpm1a_status ; 
 struct acpi_generic_address acpi_gbl_xpm1b_enable ; 
 struct acpi_generic_address acpi_gbl_xpm1b_status ; 
 int /*<<< orphan*/  acpi_hw_clear_gpe_block ; 
static  int /*<<< orphan*/  acpi_hw_read_multiple (int*,struct acpi_generic_address*,struct acpi_generic_address*) ; 
 int /*<<< orphan*/  acpi_hw_read_port (scalar_t__,int*,int) ; 
 int /*<<< orphan*/  acpi_hw_register_write (int,int) ; 
static  int /*<<< orphan*/  acpi_hw_write_multiple (int,struct acpi_generic_address*,struct acpi_generic_address*) ; 
 int /*<<< orphan*/  acpi_hw_write_port (scalar_t__,int,int) ; 
 int /*<<< orphan*/  acpi_os_acquire_raw_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_os_read_memory (scalar_t__,int*,int) ; 
 int /*<<< orphan*/  acpi_os_release_raw_lock (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_os_write_memory (scalar_t__,int,int) ; 
 int /*<<< orphan*/  acpi_ut_get_region_name (scalar_t__) ; 
 int /*<<< orphan*/  hw_clear_acpi_status ; 
 int /*<<< orphan*/  hw_read ; 
 int /*<<< orphan*/  hw_register_read ; 
 int /*<<< orphan*/  hw_register_write ; 
 int /*<<< orphan*/  hw_write ; 
 int /*<<< orphan*/  hw_write_pm1_control ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u8
acpi_hw_get_access_bit_width(u64 address,
			     struct acpi_generic_address *reg, u8 max_bit_width)
{
	u8 access_bit_width;

	/*
	 * GAS format "register", used by FADT:
	 *  1. Detected if bit_offset is 0 and bit_width is 8/16/32/64;
	 *  2. access_size field is ignored and bit_width field is used for
	 *     determining the boundary of the IO accesses.
	 * GAS format "region", used by APEI registers:
	 *  1. Detected if bit_offset is not 0 or bit_width is not 8/16/32/64;
	 *  2. access_size field is used for determining the boundary of the
	 *     IO accesses;
	 *  3. bit_offset/bit_width fields are used to describe the "region".
	 *
	 * Note: This algorithm assumes that the "Address" fields should always
	 *       contain aligned values.
	 */
	if (!reg->bit_offset && reg->bit_width &&
	    ACPI_IS_POWER_OF_TWO(reg->bit_width) &&
	    ACPI_IS_ALIGNED(reg->bit_width, 8)) {
		access_bit_width = reg->bit_width;
	} else if (reg->access_width) {
		access_bit_width = ACPI_ACCESS_BIT_WIDTH(reg->access_width);
	} else {
		access_bit_width =
		    ACPI_ROUND_UP_POWER_OF_TWO_8(reg->bit_offset +
						 reg->bit_width);
		if (access_bit_width <= 8) {
			access_bit_width = 8;
		} else {
			while (!ACPI_IS_ALIGNED(address, access_bit_width >> 3)) {
				access_bit_width >>= 1;
			}
		}
	}

	/* Maximum IO port access bit width is 32 */

	if (reg->space_id == ACPI_ADR_SPACE_SYSTEM_IO) {
		max_bit_width = 32;
	}

	/*
	 * Return access width according to the requested maximum access bit width,
	 * as the caller should know the format of the register and may enforce
	 * a 32-bit accesses.
	 */
	if (access_bit_width < max_bit_width) {
		return (access_bit_width);
	}
	return (max_bit_width);
}

acpi_status
acpi_hw_validate_register(struct acpi_generic_address *reg,
			  u8 max_bit_width, u64 *address)
{
	u8 bit_width;
	u8 access_width;

	/* Must have a valid pointer to a GAS structure */

	if (!reg) {
		return (AE_BAD_PARAMETER);
	}

	/*
	 * Copy the target address. This handles possible alignment issues.
	 * Address must not be null. A null address also indicates an optional
	 * ACPI register that is not supported, so no error message.
	 */
	ACPI_MOVE_64_TO_64(address, &reg->address);
	if (!(*address)) {
		return (AE_BAD_ADDRESS);
	}

	/* Validate the space_ID */

	if ((reg->space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY) &&
	    (reg->space_id != ACPI_ADR_SPACE_SYSTEM_IO)) {
		ACPI_ERROR((AE_INFO,
			    "Unsupported address space: 0x%X", reg->space_id));
		return (AE_SUPPORT);
	}

	/* Validate the access_width */

	if (reg->access_width > 4) {
		ACPI_ERROR((AE_INFO,
			    "Unsupported register access width: 0x%X",
			    reg->access_width));
		return (AE_SUPPORT);
	}

	/* Validate the bit_width, convert access_width into number of bits */

	access_width =
	    acpi_hw_get_access_bit_width(*address, reg, max_bit_width);
	bit_width =
	    ACPI_ROUND_UP(reg->bit_offset + reg->bit_width, access_width);
	if (max_bit_width < bit_width) {
		ACPI_WARNING((AE_INFO,
			      "Requested bit width 0x%X is smaller than register bit width 0x%X",
			      max_bit_width, bit_width));
		return (AE_SUPPORT);
	}

	return (AE_OK);
}

acpi_status acpi_hw_read(u64 *value, struct acpi_generic_address *reg)
{
	u64 address;
	u8 access_width;
	u32 bit_width;
	u8 bit_offset;
	u64 value64;
	u32 value32;
	u8 index;
	acpi_status status;

	ACPI_FUNCTION_NAME(hw_read);

	/* Validate contents of the GAS register */

	status = acpi_hw_validate_register(reg, 64, &address);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	/*
	 * Initialize entire 64-bit return value to zero, convert access_width
	 * into number of bits based
	 */
	*value = 0;
	access_width = acpi_hw_get_access_bit_width(address, reg, 64);
	bit_width = reg->bit_offset + reg->bit_width;
	bit_offset = reg->bit_offset;

	/*
	 * Two address spaces supported: Memory or IO. PCI_Config is
	 * not supported here because the GAS structure is insufficient
	 */
	index = 0;
	while (bit_width) {
		if (bit_offset >= access_width) {
			value64 = 0;
			bit_offset -= access_width;
		} else {
			if (reg->space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY) {
				status =
				    acpi_os_read_memory((acpi_physical_address)
							address +
							index *
							ACPI_DIV_8
							(access_width),
							&value64, access_width);
			} else {	/* ACPI_ADR_SPACE_SYSTEM_IO, validated earlier */

				status = acpi_hw_read_port((acpi_io_address)
							   address +
							   index *
							   ACPI_DIV_8
							   (access_width),
							   &value32,
							   access_width);
				value64 = (u64)value32;
			}
		}

		/*
		 * Use offset style bit writes because "Index * AccessWidth" is
		 * ensured to be less than 64-bits by acpi_hw_validate_register().
		 */
		ACPI_SET_BITS(value, index * access_width,
			      ACPI_MASK_BITS_ABOVE_64(access_width), value64);

		bit_width -=
		    bit_width > access_width ? access_width : bit_width;
		index++;
	}

	ACPI_DEBUG_PRINT((ACPI_DB_IO,
			  "Read:  %8.8X%8.8X width %2d from %8.8X%8.8X (%s)\n",
			  ACPI_FORMAT_UINT64(*value), access_width,
			  ACPI_FORMAT_UINT64(address),
			  acpi_ut_get_region_name(reg->space_id)));

	return (status);
}

acpi_status acpi_hw_write(u64 value, struct acpi_generic_address *reg)
{
	u64 address;
	u8 access_width;
	u32 bit_width;
	u8 bit_offset;
	u64 value64;
	u8 index;
	acpi_status status;

	ACPI_FUNCTION_NAME(hw_write);

	/* Validate contents of the GAS register */

	status = acpi_hw_validate_register(reg, 64, &address);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	/* Convert access_width into number of bits based */

	access_width = acpi_hw_get_access_bit_width(address, reg, 64);
	bit_width = reg->bit_offset + reg->bit_width;
	bit_offset = reg->bit_offset;

	/*
	 * Two address spaces supported: Memory or IO. PCI_Config is
	 * not supported here because the GAS structure is insufficient
	 */
	index = 0;
	while (bit_width) {
		/*
		 * Use offset style bit reads because "Index * AccessWidth" is
		 * ensured to be less than 64-bits by acpi_hw_validate_register().
		 */
		value64 = ACPI_GET_BITS(&value, index * access_width,
					ACPI_MASK_BITS_ABOVE_64(access_width));

		if (bit_offset >= access_width) {
			bit_offset -= access_width;
		} else {
			if (reg->space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY) {
				status =
				    acpi_os_write_memory((acpi_physical_address)
							 address +
							 index *
							 ACPI_DIV_8
							 (access_width),
							 value64, access_width);
			} else {	/* ACPI_ADR_SPACE_SYSTEM_IO, validated earlier */

				status = acpi_hw_write_port((acpi_io_address)
							    address +
							    index *
							    ACPI_DIV_8
							    (access_width),
							    (u32)value64,
							    access_width);
			}
		}

		/*
		 * Index * access_width is ensured to be less than 32-bits by
		 * acpi_hw_validate_register().
		 */
		bit_width -=
		    bit_width > access_width ? access_width : bit_width;
		index++;
	}

	ACPI_DEBUG_PRINT((ACPI_DB_IO,
			  "Wrote: %8.8X%8.8X width %2d   to %8.8X%8.8X (%s)\n",
			  ACPI_FORMAT_UINT64(value), access_width,
			  ACPI_FORMAT_UINT64(address),
			  acpi_ut_get_region_name(reg->space_id)));

	return (status);
}

acpi_status acpi_hw_clear_acpi_status(void)
{
	acpi_status status;
	acpi_cpu_flags lock_flags = 0;

	ACPI_FUNCTION_TRACE(hw_clear_acpi_status);

	ACPI_DEBUG_PRINT((ACPI_DB_IO, "About to write %04X to %8.8X%8.8X\n",
			  ACPI_BITMASK_ALL_FIXED_STATUS,
			  ACPI_FORMAT_UINT64(acpi_gbl_xpm1a_status.address)));

	lock_flags = acpi_os_acquire_raw_lock(acpi_gbl_hardware_lock);

	/* Clear the fixed events in PM1 A/B */

	status = acpi_hw_register_write(ACPI_REGISTER_PM1_STATUS,
					ACPI_BITMASK_ALL_FIXED_STATUS);

	acpi_os_release_raw_lock(acpi_gbl_hardware_lock, lock_flags);

	if (ACPI_FAILURE(status)) {
		goto exit;
	}

	/* Clear the GPE Bits in all GPE registers in all GPE blocks */

	status = acpi_ev_walk_gpe_list(acpi_hw_clear_gpe_block, NULL);

exit:
	return_ACPI_STATUS(status);
}

struct acpi_bit_register_info *acpi_hw_get_bit_register_info(u32 register_id)
{
	ACPI_FUNCTION_ENTRY();

	if (register_id > ACPI_BITREG_MAX) {
		ACPI_ERROR((AE_INFO, "Invalid BitRegister ID: 0x%X",
			    register_id));
		return (NULL);
	}

	return (&acpi_gbl_bit_register_info[register_id]);
}

acpi_status acpi_hw_write_pm1_control(u32 pm1a_control, u32 pm1b_control)
{
	acpi_status status;

	ACPI_FUNCTION_TRACE(hw_write_pm1_control);

	status =
	    acpi_hw_write(pm1a_control, &acpi_gbl_FADT.xpm1a_control_block);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	if (acpi_gbl_FADT.xpm1b_control_block.address) {
		status =
		    acpi_hw_write(pm1b_control,
				  &acpi_gbl_FADT.xpm1b_control_block);
	}
	return_ACPI_STATUS(status);
}

acpi_status acpi_hw_register_read(u32 register_id, u32 *return_value)
{
	u32 value = 0;
	u64 value64;
	acpi_status status;

	ACPI_FUNCTION_TRACE(hw_register_read);

	switch (register_id) {
	case ACPI_REGISTER_PM1_STATUS:	/* PM1 A/B: 16-bit access each */

		status = acpi_hw_read_multiple(&value,
					       &acpi_gbl_xpm1a_status,
					       &acpi_gbl_xpm1b_status);
		break;

	case ACPI_REGISTER_PM1_ENABLE:	/* PM1 A/B: 16-bit access each */

		status = acpi_hw_read_multiple(&value,
					       &acpi_gbl_xpm1a_enable,
					       &acpi_gbl_xpm1b_enable);
		break;

	case ACPI_REGISTER_PM1_CONTROL:	/* PM1 A/B: 16-bit access each */

		status = acpi_hw_read_multiple(&value,
					       &acpi_gbl_FADT.
					       xpm1a_control_block,
					       &acpi_gbl_FADT.
					       xpm1b_control_block);

		/*
		 * Zero the write-only bits. From the ACPI specification, "Hardware
		 * Write-Only Bits": "Upon reads to registers with write-only bits,
		 * software masks out all write-only bits."
		 */
		value &= ~ACPI_PM1_CONTROL_WRITEONLY_BITS;
		break;

	case ACPI_REGISTER_PM2_CONTROL:	/* 8-bit access */

		status =
		    acpi_hw_read(&value64, &acpi_gbl_FADT.xpm2_control_block);
		if (ACPI_SUCCESS(status)) {
			value = (u32)value64;
		}
		break;

	case ACPI_REGISTER_PM_TIMER:	/* 32-bit access */

		status = acpi_hw_read(&value64, &acpi_gbl_FADT.xpm_timer_block);
		if (ACPI_SUCCESS(status)) {
			value = (u32)value64;
		}

		break;

	case ACPI_REGISTER_SMI_COMMAND_BLOCK:	/* 8-bit access */

		status =
		    acpi_hw_read_port(acpi_gbl_FADT.smi_command, &value, 8);
		break;

	default:

		ACPI_ERROR((AE_INFO, "Unknown Register ID: 0x%X", register_id));
		status = AE_BAD_PARAMETER;
		break;
	}

	if (ACPI_SUCCESS(status)) {
		*return_value = (u32)value;
	}

	return_ACPI_STATUS(status);
}

acpi_status acpi_hw_register_write(u32 register_id, u32 value)
{
	acpi_status status;
	u32 read_value;
	u64 read_value64;

	ACPI_FUNCTION_TRACE(hw_register_write);

	switch (register_id) {
	case ACPI_REGISTER_PM1_STATUS:	/* PM1 A/B: 16-bit access each */
		/*
		 * Handle the "ignored" bit in PM1 Status. According to the ACPI
		 * specification, ignored bits are to be preserved when writing.
		 * Normally, this would mean a read/modify/write sequence. However,
		 * preserving a bit in the status register is different. Writing a
		 * one clears the status, and writing a zero preserves the status.
		 * Therefore, we must always write zero to the ignored bit.
		 *
		 * This behavior is clarified in the ACPI 4.0 specification.
		 */
		value &= ~ACPI_PM1_STATUS_PRESERVED_BITS;

		status = acpi_hw_write_multiple(value,
						&acpi_gbl_xpm1a_status,
						&acpi_gbl_xpm1b_status);
		break;

	case ACPI_REGISTER_PM1_ENABLE:	/* PM1 A/B: 16-bit access each */

		status = acpi_hw_write_multiple(value,
						&acpi_gbl_xpm1a_enable,
						&acpi_gbl_xpm1b_enable);
		break;

	case ACPI_REGISTER_PM1_CONTROL:	/* PM1 A/B: 16-bit access each */
		/*
		 * Perform a read first to preserve certain bits (per ACPI spec)
		 * Note: This includes SCI_EN, we never want to change this bit
		 */
		status = acpi_hw_read_multiple(&read_value,
					       &acpi_gbl_FADT.
					       xpm1a_control_block,
					       &acpi_gbl_FADT.
					       xpm1b_control_block);
		if (ACPI_FAILURE(status)) {
			goto exit;
		}

		/* Insert the bits to be preserved */

		ACPI_INSERT_BITS(value, ACPI_PM1_CONTROL_PRESERVED_BITS,
				 read_value);

		/* Now we can write the data */

		status = acpi_hw_write_multiple(value,
						&acpi_gbl_FADT.
						xpm1a_control_block,
						&acpi_gbl_FADT.
						xpm1b_control_block);
		break;

	case ACPI_REGISTER_PM2_CONTROL:	/* 8-bit access */
		/*
		 * For control registers, all reserved bits must be preserved,
		 * as per the ACPI spec.
		 */
		status =
		    acpi_hw_read(&read_value64,
				 &acpi_gbl_FADT.xpm2_control_block);
		if (ACPI_FAILURE(status)) {
			goto exit;
		}
		read_value = (u32)read_value64;

		/* Insert the bits to be preserved */

		ACPI_INSERT_BITS(value, ACPI_PM2_CONTROL_PRESERVED_BITS,
				 read_value);

		status =
		    acpi_hw_write(value, &acpi_gbl_FADT.xpm2_control_block);
		break;

	case ACPI_REGISTER_PM_TIMER:	/* 32-bit access */

		status = acpi_hw_write(value, &acpi_gbl_FADT.xpm_timer_block);
		break;

	case ACPI_REGISTER_SMI_COMMAND_BLOCK:	/* 8-bit access */

		/* SMI_CMD is currently always in IO space */

		status =
		    acpi_hw_write_port(acpi_gbl_FADT.smi_command, value, 8);
		break;

	default:

		ACPI_ERROR((AE_INFO, "Unknown Register ID: 0x%X", register_id));
		status = AE_BAD_PARAMETER;
		break;
	}

exit:
	return_ACPI_STATUS(status);
}

__attribute__((used)) static acpi_status
acpi_hw_read_multiple(u32 *value,
		      struct acpi_generic_address *register_a,
		      struct acpi_generic_address *register_b)
{
	u32 value_a = 0;
	u32 value_b = 0;
	u64 value64;
	acpi_status status;

	/* The first register is always required */

	status = acpi_hw_read(&value64, register_a);
	if (ACPI_FAILURE(status)) {
		return (status);
	}
	value_a = (u32)value64;

	/* Second register is optional */

	if (register_b->address) {
		status = acpi_hw_read(&value64, register_b);
		if (ACPI_FAILURE(status)) {
			return (status);
		}
		value_b = (u32)value64;
	}

	/*
	 * OR the two return values together. No shifting or masking is necessary,
	 * because of how the PM1 registers are defined in the ACPI specification:
	 *
	 * "Although the bits can be split between the two register blocks (each
	 * register block has a unique pointer within the FADT), the bit positions
	 * are maintained. The register block with unimplemented bits (that is,
	 * those implemented in the other register block) always returns zeros,
	 * and writes have no side effects"
	 */
	*value = (value_a | value_b);
	return (AE_OK);
}

__attribute__((used)) static acpi_status
acpi_hw_write_multiple(u32 value,
		       struct acpi_generic_address *register_a,
		       struct acpi_generic_address *register_b)
{
	acpi_status status;

	/* The first register is always required */

	status = acpi_hw_write(value, register_a);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	/*
	 * Second register is optional
	 *
	 * No bit shifting or clearing is necessary, because of how the PM1
	 * registers are defined in the ACPI specification:
	 *
	 * "Although the bits can be split between the two register blocks (each
	 * register block has a unique pointer within the FADT), the bit positions
	 * are maintained. The register block with unimplemented bits (that is,
	 * those implemented in the other register block) always returns zeros,
	 * and writes have no side effects"
	 */
	if (register_b->address) {
		status = acpi_hw_write(value, register_b);
	}

	return (status);
}

