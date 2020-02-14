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
typedef  enum MessageType { ____Placeholder_MessageType } MessageType ;

/* Variables and functions */
 int /*<<< orphan*/  LoadStringA (int /*<<< orphan*/ ,int,char*,int) ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int MESSAGE_OFFSET_EN ; 
 int MESSAGE_OFFSET_JP ; 
 int _e_msgAppTitle ; 
 int _e_msgBadInfFile ; 
 int _e_msgButtonForVpnClient ; 
 int _e_msgButtonForVpnServer ; 
 int _e_msgDownloading ; 
 int _e_msgInfDownload ; 
 int _e_msgInfDownloadFailed ; 
 int _e_msgNoParam ; 
 int _e_msgNotSupported ; 
 int _e_msgProcessCreated ; 
 int _e_msgProcessCreatedForVpnServer ; 
 int _e_msgProcessCreating ; 
 int _e_msgProcessFailed ; 
 int _e_msgStartTextForVpnClient ; 
 int _e_msgStartTextForVpnServer ; 
 int _e_msgUserCancel ; 
 int _e_msgWarning ; 
 int _e_msgWarningTitle ; 
 int _e_msgWriteFailed ; 
 scalar_t__ calloc (int,int) ; 
 int currentPage ; 
 int /*<<< orphan*/  free (void*) ; 
 int /*<<< orphan*/  hDllInstance ; 
 int /*<<< orphan*/ * msgAppTitle ; 
 int /*<<< orphan*/ * msgBadInfFile ; 
 int /*<<< orphan*/ * msgButtonForVpnClient ; 
 int /*<<< orphan*/ * msgButtonForVpnServer ; 
 int /*<<< orphan*/ * msgDownloading ; 
 int /*<<< orphan*/ * msgInfDownload ; 
 int /*<<< orphan*/ * msgInfDownloadFailed ; 
 char* msgNoParam ; 
 char* msgNotSupported ; 
 int /*<<< orphan*/ * msgProcessCreated ; 
 int /*<<< orphan*/ * msgProcessCreatedForVpnServer ; 
 int /*<<< orphan*/ * msgProcessCreating ; 
 int /*<<< orphan*/ * msgProcessFailed ; 
 int /*<<< orphan*/ * msgStartTextForVpnClient ; 
 int /*<<< orphan*/ * msgStartTextForVpnServer ; 
 int /*<<< orphan*/ * msgUserCancel ; 
 int /*<<< orphan*/ * msgWarning ; 
 int /*<<< orphan*/ * msgWarningTitle ; 
 int /*<<< orphan*/ * msgWriteFailed ; 
 scalar_t__ stricmp (char*,char*) ; 

int GetLocalizedMessageOffset(){
	return currentPage;
}

wchar_t *LoadMessageW(enum MessageType e){
	wchar_t *pTmp=(wchar_t*)calloc(sizeof(wchar_t),1024);
	LoadStringW(hDllInstance,GetLocalizedMessageOffset()+e,pTmp,1024);
	return pTmp;
}

char *LoadMessageA(enum MessageType e){
	char *pTmp=(char*)calloc(sizeof(char),1024);
	LoadStringA(hDllInstance,GetLocalizedMessageOffset()+e,pTmp,1024);
	return pTmp;
}

void FreeMessage(void *p){
	free(p);
}

int LoadTables(char *pTag){
	if( stricmp(pTag,"JP")==0 || stricmp(pTag,"JA")==0){
		currentPage=MESSAGE_OFFSET_JP;
		
	}else if( stricmp(pTag,"EN")==0)
	{
		currentPage=MESSAGE_OFFSET_EN;
	}
//		currentPage=MESSAGE_OFFSET_EN;

	msgAppTitle=LoadMessageW(_e_msgAppTitle);
	msgNotSupported=LoadMessageA(_e_msgNotSupported);
	msgInfDownload=LoadMessageW(_e_msgInfDownload);
	msgInfDownloadFailed=LoadMessageW(_e_msgInfDownloadFailed);
	msgBadInfFile=LoadMessageW(_e_msgBadInfFile);
	msgWriteFailed=LoadMessageW(_e_msgWriteFailed);
	msgDownloading=LoadMessageW(_e_msgDownloading);
	msgProcessFailed=LoadMessageW(_e_msgProcessFailed);
	msgProcessCreating=LoadMessageW(_e_msgProcessCreating);
	msgProcessCreated=LoadMessageW(_e_msgProcessCreated);
	msgWarning=LoadMessageW(_e_msgWarning);
	msgWarningTitle=LoadMessageW(_e_msgWarningTitle);
	msgUserCancel=LoadMessageW(_e_msgUserCancel);
	msgStartTextForVpnServer=LoadMessageW(_e_msgStartTextForVpnServer);
	msgButtonForVpnServer=LoadMessageW(_e_msgButtonForVpnServer);
	msgProcessCreatedForVpnServer=LoadMessageW(_e_msgProcessCreatedForVpnServer);
	msgNoParam=LoadMessageA(_e_msgNoParam);
	msgStartTextForVpnClient=LoadMessageW(_e_msgStartTextForVpnClient);
	msgButtonForVpnClient=LoadMessageW(_e_msgButtonForVpnClient);
	return 0;

}

