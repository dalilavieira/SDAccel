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
typedef  int /*<<< orphan*/  u8 ;
typedef  int acpi_size ;
typedef  int acpi_physical_address ;

/* Variables and functions */
 void* ACPI_CAST8 (int /*<<< orphan*/ *) ; 
 int ACPI_TO_INTEGER (void*) ; 
 int /*<<< orphan*/ * MAP_FAILED ; 
 int /*<<< orphan*/  MMAP_FLAGS ; 
 int O_BINARY ; 
 int O_RDONLY ; 
 int /*<<< orphan*/  PROT_READ ; 
 char* SYSTEM_MEMORY ; 
 int /*<<< orphan*/  _SC_PAGESIZE ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/ * mmap (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  munmap (int /*<<< orphan*/ *,int) ; 
 int open (char*,int) ; 
 int /*<<< orphan*/  stderr ; 
 int sysconf (int /*<<< orphan*/ ) ; 

__attribute__((used)) static acpi_size acpi_os_get_page_size(void)
{

#ifdef PAGE_SIZE
	return PAGE_SIZE;
#else
	return sysconf(_SC_PAGESIZE);
#endif
}

void *acpi_os_map_memory(acpi_physical_address where, acpi_size length)
{
	u8 *mapped_memory;
	acpi_physical_address offset;
	acpi_size page_size;
	int fd;

	fd = open(SYSTEM_MEMORY, O_RDONLY | O_BINARY);
	if (fd < 0) {
		fprintf(stderr, "Cannot open %s\n", SYSTEM_MEMORY);
		return (NULL);
	}

	/* Align the offset to use mmap */

	page_size = acpi_os_get_page_size();
	offset = where % page_size;

	/* Map the table header to get the length of the full table */

	mapped_memory = mmap(NULL, (length + offset), PROT_READ, MMAP_FLAGS,
			     fd, (where - offset));
	if (mapped_memory == MAP_FAILED) {
		fprintf(stderr, "Cannot map %s\n", SYSTEM_MEMORY);
		close(fd);
		return (NULL);
	}

	close(fd);
	return (ACPI_CAST8(mapped_memory + offset));
}

void acpi_os_unmap_memory(void *where, acpi_size length)
{
	acpi_physical_address offset;
	acpi_size page_size;

	page_size = acpi_os_get_page_size();
	offset = ACPI_TO_INTEGER(where) % page_size;
	munmap((u8 *)where - offset, (length + offset));
}

