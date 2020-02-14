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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  acpi_status ;
struct TYPE_2__ {char* argument; int /*<<< orphan*/  to_be_done; } ;

/* Variables and functions */
 char* ACPI_COMMON_BUILD_TIME ; 
 char* ACPI_COMMON_SIGNON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_OPTION (char*,char*) ; 
 int ACPI_OPT_END ; 
 int /*<<< orphan*/  ACPI_USAGE_HEADER (char*) ; 
 int /*<<< orphan*/  ACPI_USAGE_TEXT (char*) ; 
 int /*<<< orphan*/  AP_DUMP_ALL_TABLES ; 
 int /*<<< orphan*/  AP_DUMP_TABLE_BY_ADDRESS ; 
 int /*<<< orphan*/  AP_DUMP_TABLE_BY_FILE ; 
 int /*<<< orphan*/  AP_DUMP_TABLE_BY_NAME ; 
 size_t AP_MAX_ACTIONS ; 
 int /*<<< orphan*/  AP_SUPPORTED_OPTIONS ; 
 int /*<<< orphan*/  AP_UTILITY_NAME ; 
 void* FALSE ; 
 void* TRUE ; 
 void* acpi_gbl_do_not_use_xsdt ; 
 char* acpi_gbl_optarg ; 
 int acpi_getopt (int,char**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ut_strtoul64 (char*,int /*<<< orphan*/ *) ; 
 TYPE_1__* action_table ; 
 int /*<<< orphan*/  ap_open_output_file (char*) ; 
 size_t current_action ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 void* gbl_binary_mode ; 
 void* gbl_do_not_dump_xsdt ; 
 void* gbl_dump_customized_tables ; 
 int /*<<< orphan*/  gbl_rsdp_base ; 
 void* gbl_summary_mode ; 
 void* gbl_verbose_mode ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 

__attribute__((used)) static void ap_display_usage(void)
{

	ACPI_USAGE_HEADER("acpidump [options]");

	ACPI_OPTION("-b", "Dump tables to binary files");
	ACPI_OPTION("-h -?", "This help message");
	ACPI_OPTION("-o <File>", "Redirect output to file");
	ACPI_OPTION("-r <Address>", "Dump tables from specified RSDP");
	ACPI_OPTION("-s", "Print table summaries only");
	ACPI_OPTION("-v", "Display version information");
	ACPI_OPTION("-vd", "Display build date and time");
	ACPI_OPTION("-z", "Verbose mode");

	ACPI_USAGE_TEXT("\nTable Options:\n");

	ACPI_OPTION("-a <Address>", "Get table via a physical address");
	ACPI_OPTION("-c <on|off>", "Turning on/off customized table dumping");
	ACPI_OPTION("-f <BinaryFile>", "Get table via a binary file");
	ACPI_OPTION("-n <Signature>", "Get table via a name/signature");
	ACPI_OPTION("-x", "Do not use but dump XSDT");
	ACPI_OPTION("-x -x", "Do not use or dump XSDT");

	ACPI_USAGE_TEXT("\n"
			"Invocation without parameters dumps all available tables\n"
			"Multiple mixed instances of -a, -f, and -n are supported\n\n");
}

__attribute__((used)) static int ap_insert_action(char *argument, u32 to_be_done)
{

	/* Insert action and check for table overflow */

	action_table[current_action].argument = argument;
	action_table[current_action].to_be_done = to_be_done;

	current_action++;
	if (current_action > AP_MAX_ACTIONS) {
		fprintf(stderr, "Too many table options (max %u)\n",
			AP_MAX_ACTIONS);
		return (-1);
	}

	return (0);
}

__attribute__((used)) static int ap_do_options(int argc, char **argv)
{
	int j;
	acpi_status status;

	/* Command line options */

	while ((j =
		acpi_getopt(argc, argv, AP_SUPPORTED_OPTIONS)) != ACPI_OPT_END)
		switch (j) {
			/*
			 * Global options
			 */
		case 'b':	/* Dump all input tables to binary files */

			gbl_binary_mode = TRUE;
			continue;

		case 'c':	/* Dump customized tables */

			if (!strcmp(acpi_gbl_optarg, "on")) {
				gbl_dump_customized_tables = TRUE;
			} else if (!strcmp(acpi_gbl_optarg, "off")) {
				gbl_dump_customized_tables = FALSE;
			} else {
				fprintf(stderr,
					"%s: Cannot handle this switch, please use on|off\n",
					acpi_gbl_optarg);
				return (-1);
			}
			continue;

		case 'h':
		case '?':

			ap_display_usage();
			return (1);

		case 'o':	/* Redirect output to a single file */

			if (ap_open_output_file(acpi_gbl_optarg)) {
				return (-1);
			}
			continue;

		case 'r':	/* Dump tables from specified RSDP */

			status =
			    acpi_ut_strtoul64(acpi_gbl_optarg, &gbl_rsdp_base);
			if (ACPI_FAILURE(status)) {
				fprintf(stderr,
					"%s: Could not convert to a physical address\n",
					acpi_gbl_optarg);
				return (-1);
			}
			continue;

		case 's':	/* Print table summaries only */

			gbl_summary_mode = TRUE;
			continue;

		case 'x':	/* Do not use XSDT */

			if (!acpi_gbl_do_not_use_xsdt) {
				acpi_gbl_do_not_use_xsdt = TRUE;
			} else {
				gbl_do_not_dump_xsdt = TRUE;
			}
			continue;

		case 'v':	/* -v: (Version): signon already emitted, just exit */

			switch (acpi_gbl_optarg[0]) {
			case '^':	/* -v: (Version) */

				fprintf(stderr,
					ACPI_COMMON_SIGNON(AP_UTILITY_NAME));
				return (1);

			case 'd':

				fprintf(stderr,
					ACPI_COMMON_SIGNON(AP_UTILITY_NAME));
				printf(ACPI_COMMON_BUILD_TIME);
				return (1);

			default:

				printf("Unknown option: -v%s\n",
				       acpi_gbl_optarg);
				return (-1);
			}
			break;

		case 'z':	/* Verbose mode */

			gbl_verbose_mode = TRUE;
			fprintf(stderr, ACPI_COMMON_SIGNON(AP_UTILITY_NAME));
			continue;

			/*
			 * Table options
			 */
		case 'a':	/* Get table by physical address */

			if (ap_insert_action
			    (acpi_gbl_optarg, AP_DUMP_TABLE_BY_ADDRESS)) {
				return (-1);
			}
			break;

		case 'f':	/* Get table from a file */

			if (ap_insert_action
			    (acpi_gbl_optarg, AP_DUMP_TABLE_BY_FILE)) {
				return (-1);
			}
			break;

		case 'n':	/* Get table by input name (signature) */

			if (ap_insert_action
			    (acpi_gbl_optarg, AP_DUMP_TABLE_BY_NAME)) {
				return (-1);
			}
			break;

		default:

			ap_display_usage();
			return (-1);
		}

	/* If there are no actions, this means "get/dump all tables" */

	if (current_action == 0) {
		if (ap_insert_action(NULL, AP_DUMP_ALL_TABLES)) {
			return (-1);
		}
	}

	return (0);
}

