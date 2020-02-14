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
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  PCWSTR ;
typedef  scalar_t__ PBYTE ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  int /*<<< orphan*/ * LPBYTE ;
typedef  int /*<<< orphan*/  IXMLDOMNodeList ;
typedef  int /*<<< orphan*/  IXMLDOMNode ;
typedef  int /*<<< orphan*/  IXMLDOMDocument ;
typedef  int /*<<< orphan*/  GUID ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  DOMNodeType ;
typedef  int /*<<< orphan*/  BSTR ;

/* Variables and functions */
 scalar_t__ IXMLDOMDocument_selectSingleNode (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 scalar_t__ IXMLDOMNodeList_get_item (int /*<<< orphan*/ *,long,int /*<<< orphan*/ **) ; 
 scalar_t__ IXMLDOMNodeList_get_length (int /*<<< orphan*/ *,long*) ; 
 int /*<<< orphan*/  IXMLDOMNode_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ IXMLDOMNode_get_nodeType (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ IXMLDOMNode_selectNodes (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ **) ; 
 scalar_t__ IXMLDOMNode_selectSingleNode (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  KULL_M_DPAPI_GUID_PROVIDER ; 
 int /*<<< orphan*/  LocalFree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NODE_ELEMENT ; 
 int /*<<< orphan*/  PRINT_ERROR (char*,...) ; 
 scalar_t__ RtlEqualGuid (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  kprintf (char*,...) ; 
 void kuhl_m_dpapi_rdg_Groups (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **) ; 
 void kuhl_m_dpapi_rdg_LogonCredentials (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **) ; 
 void kuhl_m_dpapi_rdg_Servers (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **) ; 
 scalar_t__ kuhl_m_dpapi_unprotect_raw_or_blob (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ *) ; 
 scalar_t__ kull_m_string_args_byName (int,int /*<<< orphan*/ **,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ kull_m_string_quick_base64_to_Binary (int /*<<< orphan*/ *,int /*<<< orphan*/ **,int*) ; 
 int /*<<< orphan*/ * kull_m_xml_CreateAndInitDOM () ; 
 scalar_t__ kull_m_xml_LoadXMLFile (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kull_m_xml_ReleaseDom (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kull_m_xml_getTextValue (int /*<<< orphan*/ *,char*) ; 

NTSTATUS kuhl_m_dpapi_rdg(int argc, wchar_t * argv[])
{
	PCWSTR filename;
	IXMLDOMDocument *pXMLDom;
	IXMLDOMNode *pNode;

	if(kull_m_string_args_byName(argc, argv, L"in", &filename, NULL))
	{
		if(pXMLDom = kull_m_xml_CreateAndInitDOM())
		{
			if(kull_m_xml_LoadXMLFile(pXMLDom, filename))
			{
				if((IXMLDOMDocument_selectSingleNode(pXMLDom, (BSTR) L"//RDCMan/file", &pNode) == S_OK) && pNode)
				{
					kprintf(L"<ROOT>\n");
					kuhl_m_dpapi_rdg_Groups(1, pNode, argc, argv);
				}
			}
			kull_m_xml_ReleaseDom(pXMLDom);
		}
	}
	else PRINT_ERROR(L"Missing /in:filename.rdg\n");
	return STATUS_SUCCESS;
}

void kuhl_m_dpapi_rdg_Groups(DWORD level, IXMLDOMNode *pNode, int argc, wchar_t * argv[])
{
	IXMLDOMNodeList *pGroups;
	IXMLDOMNode *pGroup, *pProperties;
	DOMNodeType type;
	long lengthGroups, i;
	wchar_t *name;

	kuhl_m_dpapi_rdg_LogonCredentials(level, pNode, argc, argv);
	kuhl_m_dpapi_rdg_Servers(level, pNode, argc, argv);
	if((IXMLDOMNode_selectNodes(pNode, L"group", &pGroups) == S_OK) && pGroups)
	{
		if(IXMLDOMNodeList_get_length(pGroups, &lengthGroups) == S_OK)
		{
			for(i = 0; i < lengthGroups; i++)
			{
				if((IXMLDOMNodeList_get_item(pGroups, i, &pGroup) == S_OK) && pGroup)
				{
					if((IXMLDOMNode_get_nodeType(pGroup, &type) == S_OK) && (type == NODE_ELEMENT))
					{
						if((IXMLDOMNode_selectSingleNode(pGroup, L"properties", &pProperties) == S_OK) && pProperties)
						{
							if(name = kull_m_xml_getTextValue(pProperties, L"name"))
							{
								kprintf(L"%*s" L"<%s>\n", level << 1, L"", name);
								LocalFree(name);
							}
						}
						kuhl_m_dpapi_rdg_Groups(level + 1, pGroup, argc, argv);
					}
					IXMLDOMNode_Release(pGroup);
				}
			}
		}
	}
}

void kuhl_m_dpapi_rdg_Servers(DWORD level, IXMLDOMNode *pNode, int argc, wchar_t * argv[])
{
	IXMLDOMNodeList *pServers;
	IXMLDOMNode *pServer, *pProperties;
	DOMNodeType type;
	long lengthServers, i;
	wchar_t *name;

	if((IXMLDOMNode_selectNodes(pNode, L"server", &pServers) == S_OK) && pServers)
	{
		if(IXMLDOMNodeList_get_length(pServers, &lengthServers) == S_OK)
		{
			for(i = 0; i < lengthServers; i++)
			{
				if((IXMLDOMNodeList_get_item(pServers, i, &pServer) == S_OK) && pServer)
				{
					if((IXMLDOMNode_get_nodeType(pServer, &type) == S_OK) && (type == NODE_ELEMENT))
					{
						if((IXMLDOMNode_selectSingleNode(pServer, L"properties", &pProperties) == S_OK) && pProperties)
						{
							if(name = kull_m_xml_getTextValue(pProperties, L"name"))
							{
								kprintf(L"%*s" L"| %s\n", level << 1, L"", name);
								LocalFree(name);
							}
						}
						kuhl_m_dpapi_rdg_LogonCredentials(level + 1, pServer, argc, argv);
					}
					IXMLDOMNode_Release(pServer);
				}
			}
		}
	}
}

void kuhl_m_dpapi_rdg_LogonCredentials(DWORD level, IXMLDOMNode *pNode, int argc, wchar_t * argv[])
{
	IXMLDOMNode *pLogonCredentialsNode;
	wchar_t *userName, *domain, *password;
	LPBYTE data;
	LPVOID pDataOut;
	DWORD szData, dwDataOutLen;

	if((IXMLDOMNode_selectSingleNode(pNode, L"logonCredentials", &pLogonCredentialsNode) == S_OK) && pLogonCredentialsNode)
	{
		if(userName = kull_m_xml_getTextValue(pLogonCredentialsNode, L"userName"))
		{
			if(domain = kull_m_xml_getTextValue(pLogonCredentialsNode, L"domain"))
			{
				if(password = kull_m_xml_getTextValue(pLogonCredentialsNode, L"password"))
				{
					kprintf(L"%*s" L"* %s \\ %s : %s\n", level << 1, L"", domain, userName, password);
					if(kull_m_string_quick_base64_to_Binary(password, &data, &szData))
					{
						if(szData >= (sizeof(DWORD) + sizeof(GUID)))
						{
							if(RtlEqualGuid((PBYTE) data + sizeof(DWORD), &KULL_M_DPAPI_GUID_PROVIDER))
							{
								if(kuhl_m_dpapi_unprotect_raw_or_blob(data, szData, NULL, argc, argv, NULL, 0, &pDataOut, &dwDataOutLen, NULL))
									kprintf(L"%*s" L">> cleartext password: %.*s\n", level << 1, L"", dwDataOutLen / sizeof(wchar_t), pDataOut);
							}
							else PRINT_ERROR(L"Maybe certificate encryption (todo)\n");
						}
						else PRINT_ERROR(L"szData: %u\n", szData);
						LocalFree(data);
					}
					LocalFree(password);
				}
				LocalFree(domain);
			}
			LocalFree(userName);
		}
	}
}

