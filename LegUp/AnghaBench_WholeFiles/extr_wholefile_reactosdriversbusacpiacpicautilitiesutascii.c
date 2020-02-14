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
typedef  scalar_t__ UINT8 ;
typedef  size_t UINT32 ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 size_t ACPI_NAMESEG_SIZE ; 
 int /*<<< orphan*/  AcpiUtValidNameChar (char,size_t) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  isprint (scalar_t__) ; 

BOOLEAN
AcpiUtValidNameseg (
    char                    *Name)
{
    UINT32                  i;


    /* Validate each character in the signature */

    for (i = 0; i < ACPI_NAMESEG_SIZE; i++)
    {
        if (!AcpiUtValidNameChar (Name[i], i))
        {
            return (FALSE);
        }
    }

    return (TRUE);
}

BOOLEAN
AcpiUtValidNameChar (
    char                    Character,
    UINT32                  Position)
{

    if (!((Character >= 'A' && Character <= 'Z') ||
          (Character >= '0' && Character <= '9') ||
          (Character == '_')))
    {
        /* Allow a '!' in the last position */

        if (Character == '!' && Position == 3)
        {
            return (TRUE);
        }

        return (FALSE);
    }

    return (TRUE);
}

void
AcpiUtCheckAndRepairAscii (
    UINT8                   *Name,
    char                    *RepairedName,
    UINT32                  Count)
{
    UINT32                  i;


    for (i = 0; i < Count; i++)
    {
        RepairedName[i] = (char) Name[i];

        if (!Name[i])
        {
            return;
        }
        if (!isprint (Name[i]))
        {
            RepairedName[i] = ' ';
        }
    }
}

