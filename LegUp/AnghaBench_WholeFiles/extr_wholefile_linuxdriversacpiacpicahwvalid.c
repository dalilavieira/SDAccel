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
typedef  int u32 ;
struct acpi_port_info {int end; int start; scalar_t__ osi_dependency; int /*<<< orphan*/  name; } ;
typedef  scalar_t__ acpi_status ;
typedef  int acpi_io_address ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_IO ; 
 int /*<<< orphan*/  ACPI_DB_VALUES ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int ACPI_DIV_8 (int) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (scalar_t__) ; 
 int /*<<< orphan*/  ACPI_FORMAT_UINT64 (int) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int ACPI_PORT_INFO_ENTRIES ; 
 scalar_t__ ACPI_SUCCESS (scalar_t__) ; 
 int ACPI_UINT16_MAX ; 
 scalar_t__ AE_AML_ILLEGAL_ADDRESS ; 
 scalar_t__ AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_INFO ; 
 scalar_t__ AE_LIMIT ; 
 scalar_t__ AE_OK ; 
 scalar_t__ acpi_gbl_osi_data ; 
 scalar_t__ acpi_gbl_truncate_io_addresses ; 
 scalar_t__ acpi_os_read_port (int,int*,int) ; 
 scalar_t__ acpi_os_write_port (int,int,int) ; 
 struct acpi_port_info* acpi_protected_ports ; 
 int /*<<< orphan*/  hw_validate_io_request ; 
 int /*<<< orphan*/  return_ACPI_STATUS (scalar_t__) ; 

__attribute__((used)) static acpi_status
acpi_hw_validate_io_request(acpi_io_address address, u32 bit_width)
{
	u32 i;
	u32 byte_width;
	acpi_io_address last_address;
	const struct acpi_port_info *port_info;

	ACPI_FUNCTION_TRACE(hw_validate_io_request);

	/* Supported widths are 8/16/32 */

	if ((bit_width != 8) && (bit_width != 16) && (bit_width != 32)) {
		ACPI_ERROR((AE_INFO,
			    "Bad BitWidth parameter: %8.8X", bit_width));
		return_ACPI_STATUS(AE_BAD_PARAMETER);
	}

	port_info = acpi_protected_ports;
	byte_width = ACPI_DIV_8(bit_width);
	last_address = address + byte_width - 1;

	ACPI_DEBUG_PRINT((ACPI_DB_IO,
			  "Address %8.8X%8.8X LastAddress %8.8X%8.8X Length %X",
			  ACPI_FORMAT_UINT64(address),
			  ACPI_FORMAT_UINT64(last_address), byte_width));

	/* Maximum 16-bit address in I/O space */

	if (last_address > ACPI_UINT16_MAX) {
		ACPI_ERROR((AE_INFO,
			    "Illegal I/O port address/length above 64K: %8.8X%8.8X/0x%X",
			    ACPI_FORMAT_UINT64(address), byte_width));
		return_ACPI_STATUS(AE_LIMIT);
	}

	/* Exit if requested address is not within the protected port table */

	if (address > acpi_protected_ports[ACPI_PORT_INFO_ENTRIES - 1].end) {
		return_ACPI_STATUS(AE_OK);
	}

	/* Check request against the list of protected I/O ports */

	for (i = 0; i < ACPI_PORT_INFO_ENTRIES; i++, port_info++) {
		/*
		 * Check if the requested address range will write to a reserved
		 * port. There are four cases to consider:
		 *
		 * 1) Address range is contained completely in the port address range
		 * 2) Address range overlaps port range at the port range start
		 * 3) Address range overlaps port range at the port range end
		 * 4) Address range completely encompasses the port range
		 */
		if ((address <= port_info->end)
		    && (last_address >= port_info->start)) {

			/* Port illegality may depend on the _OSI calls made by the BIOS */

			if (acpi_gbl_osi_data >= port_info->osi_dependency) {
				ACPI_DEBUG_PRINT((ACPI_DB_VALUES,
						  "Denied AML access to port 0x%8.8X%8.8X/%X (%s 0x%.4X-0x%.4X)\n",
						  ACPI_FORMAT_UINT64(address),
						  byte_width, port_info->name,
						  port_info->start,
						  port_info->end));

				return_ACPI_STATUS(AE_AML_ILLEGAL_ADDRESS);
			}
		}

		/* Finished if address range ends before the end of this port */

		if (last_address <= port_info->end) {
			break;
		}
	}

	return_ACPI_STATUS(AE_OK);
}

acpi_status acpi_hw_read_port(acpi_io_address address, u32 *value, u32 width)
{
	acpi_status status;
	u32 one_byte;
	u32 i;

	/* Truncate address to 16 bits if requested */

	if (acpi_gbl_truncate_io_addresses) {
		address &= ACPI_UINT16_MAX;
	}

	/* Validate the entire request and perform the I/O */

	status = acpi_hw_validate_io_request(address, width);
	if (ACPI_SUCCESS(status)) {
		status = acpi_os_read_port(address, value, width);
		return (status);
	}

	if (status != AE_AML_ILLEGAL_ADDRESS) {
		return (status);
	}

	/*
	 * There has been a protection violation within the request. Fall
	 * back to byte granularity port I/O and ignore the failing bytes.
	 * This provides compatibility with other ACPI implementations.
	 */
	for (i = 0, *value = 0; i < width; i += 8) {

		/* Validate and read one byte */

		if (acpi_hw_validate_io_request(address, 8) == AE_OK) {
			status = acpi_os_read_port(address, &one_byte, 8);
			if (ACPI_FAILURE(status)) {
				return (status);
			}

			*value |= (one_byte << i);
		}

		address++;
	}

	return (AE_OK);
}

acpi_status acpi_hw_write_port(acpi_io_address address, u32 value, u32 width)
{
	acpi_status status;
	u32 i;

	/* Truncate address to 16 bits if requested */

	if (acpi_gbl_truncate_io_addresses) {
		address &= ACPI_UINT16_MAX;
	}

	/* Validate the entire request and perform the I/O */

	status = acpi_hw_validate_io_request(address, width);
	if (ACPI_SUCCESS(status)) {
		status = acpi_os_write_port(address, value, width);
		return (status);
	}

	if (status != AE_AML_ILLEGAL_ADDRESS) {
		return (status);
	}

	/*
	 * There has been a protection violation within the request. Fall
	 * back to byte granularity port I/O and ignore the failing bytes.
	 * This provides compatibility with other ACPI implementations.
	 */
	for (i = 0; i < width; i += 8) {

		/* Validate and write one byte */

		if (acpi_hw_validate_io_request(address, 8) == AE_OK) {
			status =
			    acpi_os_write_port(address, (value >> i) & 0xFF, 8);
			if (ACPI_FAILURE(status)) {
				return (status);
			}
		}

		address++;
	}

	return (AE_OK);
}

