#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_5__ ;
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  void* UINT8 ;
typedef  size_t UINT32 ;
struct TYPE_30__ {scalar_t__ Type; } ;
struct TYPE_28__ {TYPE_5__* Handler; } ;
struct TYPE_27__ {scalar_t__ SpaceId; int HandlerFlags; scalar_t__ Handler; TYPE_5__* Next; int /*<<< orphan*/ * Setup; void* Context; TYPE_6__* Node; int /*<<< orphan*/ * RegionList; } ;
struct TYPE_26__ {scalar_t__ Type; } ;
struct TYPE_25__ {scalar_t__ SpaceId; } ;
struct TYPE_29__ {TYPE_4__ CommonNotify; TYPE_3__ AddressSpace; TYPE_2__ Common; TYPE_1__ Region; } ;
typedef  int /*<<< orphan*/  BOOLEAN ;
typedef  int ACPI_STATUS ;
typedef  TYPE_5__ ACPI_OPERAND_OBJECT ;
typedef  scalar_t__ ACPI_OBJECT_TYPE ;
typedef  TYPE_6__ ACPI_NAMESPACE_NODE ;
typedef  int /*<<< orphan*/  ACPI_HANDLE ;
typedef  scalar_t__ ACPI_ADR_SPACE_TYPE ;
typedef  int /*<<< orphan*/ * ACPI_ADR_SPACE_SETUP ;
typedef  scalar_t__ ACPI_ADR_SPACE_HANDLER ;

/* Variables and functions */
 int ACPI_ADDR_HANDLER_DEFAULT_INSTALLED ; 
#define  ACPI_ADR_SPACE_CMOS 136 
#define  ACPI_ADR_SPACE_DATA_TABLE 135 
#define  ACPI_ADR_SPACE_PCI_BAR_TARGET 134 
#define  ACPI_ADR_SPACE_PCI_CONFIG 133 
#define  ACPI_ADR_SPACE_SYSTEM_IO 132 
#define  ACPI_ADR_SPACE_SYSTEM_MEMORY 131 
 int /*<<< orphan*/  ACPI_DB_OPREGION ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_DEFAULT_HANDLER ; 
 scalar_t__ ACPI_FAILURE (int) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_MTX_NAMESPACE ; 
 int /*<<< orphan*/  ACPI_NS_WALK_UNLOCK ; 
 size_t ACPI_NUM_DEFAULT_SPACES ; 
 scalar_t__ ACPI_TYPE_ANY ; 
 scalar_t__ ACPI_TYPE_DEVICE ; 
 scalar_t__ ACPI_TYPE_LOCAL_ADDRESS_HANDLER ; 
 scalar_t__ ACPI_TYPE_PROCESSOR ; 
 scalar_t__ ACPI_TYPE_REGION ; 
 scalar_t__ ACPI_TYPE_THERMAL ; 
 int /*<<< orphan*/  ACPI_UINT32_MAX ; 
#define  AE_ALREADY_EXISTS 130 
 int AE_BAD_PARAMETER ; 
 int AE_CTRL_DEPTH ; 
 int AE_NO_MEMORY ; 
#define  AE_OK 129 
#define  AE_SAME_HANDLER 128 
 int AcpiEvAttachRegion (TYPE_5__*,TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * AcpiEvCmosRegionSetup ; 
 int /*<<< orphan*/ * AcpiEvDefaultRegionSetup ; 
 int /*<<< orphan*/  AcpiEvDetachRegion (TYPE_5__*,int /*<<< orphan*/ ) ; 
 TYPE_5__* AcpiEvFindRegionHandler (scalar_t__,TYPE_5__*) ; 
 int AcpiEvInstallSpaceHandler (TYPE_6__*,scalar_t__,scalar_t__,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/ * AcpiEvIoSpaceRegionSetup ; 
 int /*<<< orphan*/ * AcpiEvPciBarRegionSetup ; 
 int /*<<< orphan*/ * AcpiEvPciConfigRegionSetup ; 
 int /*<<< orphan*/ * AcpiEvSystemMemoryRegionSetup ; 
 scalar_t__ AcpiExCmosSpaceHandler ; 
 scalar_t__ AcpiExDataTableSpaceHandler ; 
 scalar_t__ AcpiExPciBarSpaceHandler ; 
 scalar_t__ AcpiExPciConfigSpaceHandler ; 
 scalar_t__ AcpiExSystemIoSpaceHandler ; 
 scalar_t__ AcpiExSystemMemorySpaceHandler ; 
 scalar_t__* AcpiGbl_DefaultAddressSpaces ; 
 TYPE_6__* AcpiGbl_RootNode ; 
 int AcpiNsAttachObject (TYPE_6__*,TYPE_5__*,scalar_t__) ; 
 TYPE_5__* AcpiNsGetAttachedObject (TYPE_6__*) ; 
 TYPE_6__* AcpiNsValidateHandle (int /*<<< orphan*/ ) ; 
 int AcpiNsWalkNamespace (scalar_t__,TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (int /*<<< orphan*/ ,size_t,void*,void**),int /*<<< orphan*/ *,TYPE_5__*,int /*<<< orphan*/ *) ; 
 int AcpiUtAcquireMutex (int /*<<< orphan*/ ) ; 
 TYPE_5__* AcpiUtCreateInternalObject (scalar_t__) ; 
 int /*<<< orphan*/  AcpiUtGetNodeName (TYPE_6__*) ; 
 int /*<<< orphan*/  AcpiUtGetRegionName (scalar_t__) ; 
 int /*<<< orphan*/  AcpiUtReleaseMutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiUtRemoveReference (TYPE_5__*) ; 
 int /*<<< orphan*/  EvInstallHandler ; 
 int /*<<< orphan*/  EvInstallRegionHandlers ; 
 int /*<<< orphan*/  EvInstallSpaceHandler ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int) ; 

ACPI_STATUS
AcpiEvInstallRegionHandlers (
    void)
{
    ACPI_STATUS             Status;
    UINT32                  i;


    ACPI_FUNCTION_TRACE (EvInstallRegionHandlers);


    Status = AcpiUtAcquireMutex (ACPI_MTX_NAMESPACE);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /*
     * All address spaces (PCI Config, EC, SMBus) are scope dependent and
     * registration must occur for a specific device.
     *
     * In the case of the system memory and IO address spaces there is
     * currently no device associated with the address space. For these we
     * use the root.
     *
     * We install the default PCI config space handler at the root so that
     * this space is immediately available even though the we have not
     * enumerated all the PCI Root Buses yet. This is to conform to the ACPI
     * specification which states that the PCI config space must be always
     * available -- even though we are nowhere near ready to find the PCI root
     * buses at this point.
     *
     * NOTE: We ignore AE_ALREADY_EXISTS because this means that a handler
     * has already been installed (via AcpiInstallAddressSpaceHandler).
     * Similar for AE_SAME_HANDLER.
     */
    for (i = 0; i < ACPI_NUM_DEFAULT_SPACES; i++)
    {
        Status = AcpiEvInstallSpaceHandler (AcpiGbl_RootNode,
            AcpiGbl_DefaultAddressSpaces[i],
            ACPI_DEFAULT_HANDLER, NULL, NULL);
        switch (Status)
        {
        case AE_OK:
        case AE_SAME_HANDLER:
        case AE_ALREADY_EXISTS:

            /* These exceptions are all OK */

            Status = AE_OK;
            break;

        default:

            goto UnlockAndExit;
        }
    }

UnlockAndExit:
    (void) AcpiUtReleaseMutex (ACPI_MTX_NAMESPACE);
    return_ACPI_STATUS (Status);
}

BOOLEAN
AcpiEvHasDefaultHandler (
    ACPI_NAMESPACE_NODE     *Node,
    ACPI_ADR_SPACE_TYPE     SpaceId)
{
    ACPI_OPERAND_OBJECT     *ObjDesc;
    ACPI_OPERAND_OBJECT     *HandlerObj;


    /* Must have an existing internal object */

    ObjDesc = AcpiNsGetAttachedObject (Node);
    if (ObjDesc)
    {
        HandlerObj = ObjDesc->CommonNotify.Handler;

        /* Walk the linked list of handlers for this object */

        while (HandlerObj)
        {
            if (HandlerObj->AddressSpace.SpaceId == SpaceId)
            {
                if (HandlerObj->AddressSpace.HandlerFlags &
                    ACPI_ADDR_HANDLER_DEFAULT_INSTALLED)
                {
                    return (TRUE);
                }
            }

            HandlerObj = HandlerObj->AddressSpace.Next;
        }
    }

    return (FALSE);
}

__attribute__((used)) static ACPI_STATUS
AcpiEvInstallHandler (
    ACPI_HANDLE             ObjHandle,
    UINT32                  Level,
    void                    *Context,
    void                    **ReturnValue)
{
    ACPI_OPERAND_OBJECT     *HandlerObj;
    ACPI_OPERAND_OBJECT     *NextHandlerObj;
    ACPI_OPERAND_OBJECT     *ObjDesc;
    ACPI_NAMESPACE_NODE     *Node;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_NAME (EvInstallHandler);


    HandlerObj = (ACPI_OPERAND_OBJECT  *) Context;

    /* Parameter validation */

    if (!HandlerObj)
    {
        return (AE_OK);
    }

    /* Convert and validate the device handle */

    Node = AcpiNsValidateHandle (ObjHandle);
    if (!Node)
    {
        return (AE_BAD_PARAMETER);
    }

    /*
     * We only care about regions and objects that are allowed to have
     * address space handlers
     */
    if ((Node->Type != ACPI_TYPE_DEVICE) &&
        (Node->Type != ACPI_TYPE_REGION) &&
        (Node != AcpiGbl_RootNode))
    {
        return (AE_OK);
    }

    /* Check for an existing internal object */

    ObjDesc = AcpiNsGetAttachedObject (Node);
    if (!ObjDesc)
    {
        /* No object, just exit */

        return (AE_OK);
    }

    /* Devices are handled different than regions */

    if (ObjDesc->Common.Type == ACPI_TYPE_DEVICE)
    {
        /* Check if this Device already has a handler for this address space */

        NextHandlerObj = AcpiEvFindRegionHandler (
            HandlerObj->AddressSpace.SpaceId, ObjDesc->CommonNotify.Handler);
        if (NextHandlerObj)
        {
            /* Found a handler, is it for the same address space? */

            ACPI_DEBUG_PRINT ((ACPI_DB_OPREGION,
                "Found handler for region [%s] in device %p(%p) handler %p\n",
                AcpiUtGetRegionName (HandlerObj->AddressSpace.SpaceId),
                ObjDesc, NextHandlerObj, HandlerObj));

            /*
             * Since the object we found it on was a device, then it means
             * that someone has already installed a handler for the branch
             * of the namespace from this device on. Just bail out telling
             * the walk routine to not traverse this branch. This preserves
             * the scoping rule for handlers.
             */
            return (AE_CTRL_DEPTH);
        }

        /*
         * As long as the device didn't have a handler for this space we
         * don't care about it. We just ignore it and proceed.
         */
        return (AE_OK);
    }

    /* Object is a Region */

    if (ObjDesc->Region.SpaceId != HandlerObj->AddressSpace.SpaceId)
    {
        /* This region is for a different address space, just ignore it */

        return (AE_OK);
    }

    /*
     * Now we have a region and it is for the handler's address space type.
     *
     * First disconnect region for any previous handler (if any)
     */
    AcpiEvDetachRegion (ObjDesc, FALSE);

    /* Connect the region to the new handler */

    Status = AcpiEvAttachRegion (HandlerObj, ObjDesc, FALSE);
    return (Status);
}

ACPI_OPERAND_OBJECT *
AcpiEvFindRegionHandler (
    ACPI_ADR_SPACE_TYPE     SpaceId,
    ACPI_OPERAND_OBJECT     *HandlerObj)
{

    /* Walk the handler list for this device */

    while (HandlerObj)
    {
        /* Same SpaceId indicates a handler is installed */

        if (HandlerObj->AddressSpace.SpaceId == SpaceId)
        {
            return (HandlerObj);
        }

        /* Next handler object */

        HandlerObj = HandlerObj->AddressSpace.Next;
    }

    return (NULL);
}

ACPI_STATUS
AcpiEvInstallSpaceHandler (
    ACPI_NAMESPACE_NODE     *Node,
    ACPI_ADR_SPACE_TYPE     SpaceId,
    ACPI_ADR_SPACE_HANDLER  Handler,
    ACPI_ADR_SPACE_SETUP    Setup,
    void                    *Context)
{
    ACPI_OPERAND_OBJECT     *ObjDesc;
    ACPI_OPERAND_OBJECT     *HandlerObj;
    ACPI_STATUS             Status = AE_OK;
    ACPI_OBJECT_TYPE        Type;
    UINT8                   Flags = 0;


    ACPI_FUNCTION_TRACE (EvInstallSpaceHandler);


    /*
     * This registration is valid for only the types below and the root.
     * The root node is where the default handlers get installed.
     */
    if ((Node->Type != ACPI_TYPE_DEVICE)     &&
        (Node->Type != ACPI_TYPE_PROCESSOR)  &&
        (Node->Type != ACPI_TYPE_THERMAL)    &&
        (Node != AcpiGbl_RootNode))
    {
        Status = AE_BAD_PARAMETER;
        goto UnlockAndExit;
    }

    if (Handler == ACPI_DEFAULT_HANDLER)
    {
        Flags = ACPI_ADDR_HANDLER_DEFAULT_INSTALLED;

        switch (SpaceId)
        {
        case ACPI_ADR_SPACE_SYSTEM_MEMORY:

            Handler = AcpiExSystemMemorySpaceHandler;
            Setup   = AcpiEvSystemMemoryRegionSetup;
            break;

        case ACPI_ADR_SPACE_SYSTEM_IO:

            Handler = AcpiExSystemIoSpaceHandler;
            Setup   = AcpiEvIoSpaceRegionSetup;
            break;

        case ACPI_ADR_SPACE_PCI_CONFIG:

            Handler = AcpiExPciConfigSpaceHandler;
            Setup   = AcpiEvPciConfigRegionSetup;
            break;

        case ACPI_ADR_SPACE_CMOS:

            Handler = AcpiExCmosSpaceHandler;
            Setup   = AcpiEvCmosRegionSetup;
            break;

        case ACPI_ADR_SPACE_PCI_BAR_TARGET:

            Handler = AcpiExPciBarSpaceHandler;
            Setup   = AcpiEvPciBarRegionSetup;
            break;

        case ACPI_ADR_SPACE_DATA_TABLE:

            Handler = AcpiExDataTableSpaceHandler;
            Setup   = NULL;
            break;

        default:

            Status = AE_BAD_PARAMETER;
            goto UnlockAndExit;
        }
    }

    /* If the caller hasn't specified a setup routine, use the default */

    if (!Setup)
    {
        Setup = AcpiEvDefaultRegionSetup;
    }

    /* Check for an existing internal object */

    ObjDesc = AcpiNsGetAttachedObject (Node);
    if (ObjDesc)
    {
        /*
         * The attached device object already exists. Now make sure
         * the handler is not already installed.
         */
        HandlerObj = AcpiEvFindRegionHandler (SpaceId,
            ObjDesc->CommonNotify.Handler);

        if (HandlerObj)
        {
            if (HandlerObj->AddressSpace.Handler == Handler)
            {
                /*
                 * It is (relatively) OK to attempt to install the SAME
                 * handler twice. This can easily happen with the
                 * PCI_Config space.
                 */
                Status = AE_SAME_HANDLER;
                goto UnlockAndExit;
            }
            else
            {
                /* A handler is already installed */

                Status = AE_ALREADY_EXISTS;
            }

            goto UnlockAndExit;
        }
    }
    else
    {
        ACPI_DEBUG_PRINT ((ACPI_DB_OPREGION,
            "Creating object on Device %p while installing handler\n",
            Node));

        /* ObjDesc does not exist, create one */

        if (Node->Type == ACPI_TYPE_ANY)
        {
            Type = ACPI_TYPE_DEVICE;
        }
        else
        {
            Type = Node->Type;
        }

        ObjDesc = AcpiUtCreateInternalObject (Type);
        if (!ObjDesc)
        {
            Status = AE_NO_MEMORY;
            goto UnlockAndExit;
        }

        /* Init new descriptor */

        ObjDesc->Common.Type = (UINT8) Type;

        /* Attach the new object to the Node */

        Status = AcpiNsAttachObject (Node, ObjDesc, Type);

        /* Remove local reference to the object */

        AcpiUtRemoveReference (ObjDesc);

        if (ACPI_FAILURE (Status))
        {
            goto UnlockAndExit;
        }
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_OPREGION,
        "Installing address handler for region %s(%X) "
        "on Device %4.4s %p(%p)\n",
        AcpiUtGetRegionName (SpaceId), SpaceId,
        AcpiUtGetNodeName (Node), Node, ObjDesc));

    /*
     * Install the handler
     *
     * At this point there is no existing handler. Just allocate the object
     * for the handler and link it into the list.
     */
    HandlerObj = AcpiUtCreateInternalObject (ACPI_TYPE_LOCAL_ADDRESS_HANDLER);
    if (!HandlerObj)
    {
        Status = AE_NO_MEMORY;
        goto UnlockAndExit;
    }

    /* Init handler obj */

    HandlerObj->AddressSpace.SpaceId = (UINT8) SpaceId;
    HandlerObj->AddressSpace.HandlerFlags = Flags;
    HandlerObj->AddressSpace.RegionList = NULL;
    HandlerObj->AddressSpace.Node = Node;
    HandlerObj->AddressSpace.Handler = Handler;
    HandlerObj->AddressSpace.Context = Context;
    HandlerObj->AddressSpace.Setup = Setup;

    /* Install at head of Device.AddressSpace list */

    HandlerObj->AddressSpace.Next = ObjDesc->CommonNotify.Handler;

    /*
     * The Device object is the first reference on the HandlerObj.
     * Each region that uses the handler adds a reference.
     */
    ObjDesc->CommonNotify.Handler = HandlerObj;

    /*
     * Walk the namespace finding all of the regions this handler will
     * manage.
     *
     * Start at the device and search the branch toward the leaf nodes
     * until either the leaf is encountered or a device is detected that
     * has an address handler of the same type.
     *
     * In either case, back up and search down the remainder of the branch
     */
    Status = AcpiNsWalkNamespace (ACPI_TYPE_ANY, Node,
        ACPI_UINT32_MAX, ACPI_NS_WALK_UNLOCK,
        AcpiEvInstallHandler, NULL, HandlerObj, NULL);

UnlockAndExit:
    return_ACPI_STATUS (Status);
}

