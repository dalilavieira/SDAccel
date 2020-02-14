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
typedef  int /*<<< orphan*/  sid_users_buffer ;
typedef  int /*<<< orphan*/  sid_network_buffer ;
typedef  int /*<<< orphan*/  sid_local_buffer ;
typedef  int /*<<< orphan*/  sid_admin_buffer ;
typedef  int /*<<< orphan*/  acl_buffer ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VARIANT ;
typedef  int /*<<< orphan*/  SID ;
typedef  int /*<<< orphan*/  SECURITY_DESCRIPTOR ;
typedef  int /*<<< orphan*/  SAFEARRAY ;
typedef  int /*<<< orphan*/  IWbemClassObject ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  int /*<<< orphan*/  ACL ;
typedef  int /*<<< orphan*/  ACCESS_ALLOWED_ACE ;

/* Variables and functions */
 int /*<<< orphan*/  ACL_REVISION ; 
 int ADS_RIGHT_ACTRL_DS_LIST ; 
 int ADS_RIGHT_DS_CREATE_CHILD ; 
 int ADS_RIGHT_DS_DELETE_CHILD ; 
 int ADS_RIGHT_DS_READ_PROP ; 
 int ADS_RIGHT_DS_SELF ; 
 int ADS_RIGHT_DS_WRITE_PROP ; 
 int /*<<< orphan*/  AddAccessAllowedAceEx (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ *) ; 
 int CIM_FLAG_ARRAY ; 
 int CIM_UINT32 ; 
 int CIM_UINT8 ; 
 int CONTAINER_INHERIT_ACE ; 
 int /*<<< orphan*/  CreateWellKnownSid (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  E_FAIL ; 
 int /*<<< orphan*/  E_OUTOFMEMORY ; 
 int /*<<< orphan*/  FIXME (char*) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int GetSecurityDescriptorLength (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int INHERITED_ACE ; 
 int /*<<< orphan*/  IWbemClassObject_AddRef (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IWbemClassObject_Put (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  IWbemClassObject_Release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IWbemClassObject_SpawnInstance (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  InitializeAcl (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InitializeSecurityDescriptor (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MakeSelfRelativeSD (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  PARAM_OUT ; 
 int READ_CONTROL ; 
 int /*<<< orphan*/  SECURITY_DESCRIPTOR_REVISION ; 
 int SECURITY_MAX_SID_SIZE ; 
 scalar_t__ SUCCEEDED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  S_OK ; 
 int /*<<< orphan*/  SafeArrayAccessData (int /*<<< orphan*/ *,void**) ; 
 int /*<<< orphan*/ * SafeArrayCreateVector (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SafeArrayDestroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SafeArrayUnaccessData (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetSecurityDescriptorDacl (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetSecurityDescriptorGroup (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetSecurityDescriptorOwner (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  TRUE ; 
 int VT_ARRAY ; 
 int VT_UI1 ; 
 int VT_UI4 ; 
 int /*<<< orphan*/  VariantClear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  VariantInit (int /*<<< orphan*/ *) ; 
 int WRITE_DAC ; 
 int /*<<< orphan*/  WinAuthenticatedUserSid ; 
 int /*<<< orphan*/  WinBuiltinAdministratorsSid ; 
 int /*<<< orphan*/  WinLocalServiceSid ; 
 int /*<<< orphan*/  WinNetworkServiceSid ; 
 int /*<<< orphan*/  class_systemsecurityW ; 
 int /*<<< orphan*/  create_signature (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/ * heap_alloc (int) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 
 int /*<<< orphan*/  method_getsdW ; 
 int /*<<< orphan*/  method_setsdW ; 
 int /*<<< orphan*/  param_returnvalueW ; 
 int /*<<< orphan*/  param_sdW ; 
 int /*<<< orphan*/  set_variant (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcpyW (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int strlenW (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static inline WCHAR *heap_strdupW( const WCHAR *src )
{
    WCHAR *dst;
    if (!src) return NULL;
    if ((dst = heap_alloc( (strlenW( src ) + 1) * sizeof(WCHAR) ))) strcpyW( dst, src );
    return dst;
}

__attribute__((used)) static HRESULT to_byte_array( void *data, DWORD size, VARIANT *var )
{
    SAFEARRAY *sa;
    void *sadata;
    HRESULT hr;

    if (!(sa = SafeArrayCreateVector( VT_UI1, 0, size ))) return E_OUTOFMEMORY;

    hr = SafeArrayAccessData( sa, &sadata );

    if (SUCCEEDED(hr))
    {
        memcpy( sadata, data, size );

        SafeArrayUnaccessData( sa );
    }
    else
    {
        SafeArrayDestroy( sa );
        return hr;
    }

    set_variant( VT_UI1|VT_ARRAY, 0, sa, var );
    return S_OK;
}

__attribute__((used)) static HRESULT get_sd( SECURITY_DESCRIPTOR **sd, DWORD *size )
{
    BYTE sid_admin_buffer[SECURITY_MAX_SID_SIZE];
    SID *sid_admin = (SID*)sid_admin_buffer;
    BYTE sid_network_buffer[SECURITY_MAX_SID_SIZE];
    SID *sid_network = (SID*)sid_network_buffer;
    BYTE sid_local_buffer[SECURITY_MAX_SID_SIZE];
    SID *sid_local = (SID*)sid_local_buffer;
    BYTE sid_users_buffer[SECURITY_MAX_SID_SIZE];
    SID *sid_users = (SID*)sid_users_buffer;
    BYTE acl_buffer[sizeof(ACL) + 4 * (sizeof(ACCESS_ALLOWED_ACE) - sizeof(DWORD) + SECURITY_MAX_SID_SIZE)];
    ACL *acl = (ACL*)acl_buffer;
    DWORD sid_size;
    SECURITY_DESCRIPTOR absolute_sd;
    HRESULT hr = S_OK;

    sid_size = sizeof(sid_admin_buffer);
    CreateWellKnownSid( WinBuiltinAdministratorsSid, NULL, sid_admin, &sid_size );

    sid_size = sizeof(sid_network_buffer);
    CreateWellKnownSid( WinNetworkServiceSid, NULL, sid_network, &sid_size );

    sid_size = sizeof(sid_local_buffer);
    CreateWellKnownSid( WinLocalServiceSid, NULL, sid_local, &sid_size );

    sid_size = sizeof(sid_users_buffer);
    CreateWellKnownSid( WinAuthenticatedUserSid, NULL, sid_users, &sid_size );

    InitializeAcl( acl, sizeof(acl_buffer), ACL_REVISION );

    AddAccessAllowedAceEx( acl, ACL_REVISION, CONTAINER_INHERIT_ACE|INHERITED_ACE,
        ADS_RIGHT_DS_CREATE_CHILD|ADS_RIGHT_DS_DELETE_CHILD|ADS_RIGHT_ACTRL_DS_LIST|ADS_RIGHT_DS_SELF|
        ADS_RIGHT_DS_READ_PROP|ADS_RIGHT_DS_WRITE_PROP|READ_CONTROL|WRITE_DAC,
        sid_admin );

    AddAccessAllowedAceEx( acl, ACL_REVISION, CONTAINER_INHERIT_ACE|INHERITED_ACE,
        ADS_RIGHT_DS_CREATE_CHILD|ADS_RIGHT_DS_DELETE_CHILD|ADS_RIGHT_DS_READ_PROP,
        sid_network );

    AddAccessAllowedAceEx( acl, ACL_REVISION, CONTAINER_INHERIT_ACE|INHERITED_ACE,
        ADS_RIGHT_DS_CREATE_CHILD|ADS_RIGHT_DS_DELETE_CHILD|ADS_RIGHT_DS_READ_PROP,
        sid_local );

    AddAccessAllowedAceEx( acl, ACL_REVISION, CONTAINER_INHERIT_ACE|INHERITED_ACE,
        ADS_RIGHT_DS_CREATE_CHILD|ADS_RIGHT_DS_DELETE_CHILD|ADS_RIGHT_DS_READ_PROP,
        sid_users );

    InitializeSecurityDescriptor( &absolute_sd, SECURITY_DESCRIPTOR_REVISION );

    SetSecurityDescriptorOwner( &absolute_sd, sid_admin, TRUE );
    SetSecurityDescriptorGroup( &absolute_sd, sid_admin, TRUE );
    SetSecurityDescriptorDacl( &absolute_sd, TRUE, acl, TRUE );

    *size = GetSecurityDescriptorLength( &absolute_sd );

    *sd = HeapAlloc( GetProcessHeap(), 0, *size );
    if (!*sd)
        hr = E_OUTOFMEMORY;

    if (SUCCEEDED(hr))
    {
        if (!MakeSelfRelativeSD(&absolute_sd, *sd, size)) {
            HeapFree( GetProcessHeap(), 0, *sd );
	    *sd = NULL;
            hr = E_FAIL;
        }
    }

    return hr;
}

HRESULT security_get_sd( IWbemClassObject *obj, IWbemClassObject *in, IWbemClassObject **out )
{
    VARIANT var_sd, retval;
    IWbemClassObject *sig, *out_params = NULL;
    HRESULT hr, ret;
    SECURITY_DESCRIPTOR *sd;
    DWORD sd_size;

    TRACE("%p, %p\n", in, out);

    hr = create_signature( class_systemsecurityW, method_getsdW, PARAM_OUT, &sig );

    if (SUCCEEDED(hr))
    {
        hr = IWbemClassObject_SpawnInstance( sig, 0, &out_params );

        IWbemClassObject_Release( sig );
    }

    if (SUCCEEDED(hr))
    {
        ret = get_sd( &sd, &sd_size );

        if (SUCCEEDED(ret))
        {
            VariantInit( &var_sd );

            hr = to_byte_array( sd, sd_size, &var_sd );

            if (SUCCEEDED(hr))
                hr = IWbemClassObject_Put( out_params, param_sdW, 0, &var_sd, CIM_UINT8|CIM_FLAG_ARRAY );

            HeapFree( GetProcessHeap(), 0, sd );
            VariantClear( &var_sd );
        }

        if (SUCCEEDED(hr))
        {
            set_variant( VT_UI4, ret, NULL, &retval );
            hr = IWbemClassObject_Put( out_params, param_returnvalueW, 0, &retval, CIM_UINT32 );
        }

        if (SUCCEEDED(hr) && out)
        {
            *out = out_params;
            IWbemClassObject_AddRef( out_params );
        }

        IWbemClassObject_Release( out_params );
    }

    return hr;
}

HRESULT security_set_sd( IWbemClassObject *obj, IWbemClassObject *in, IWbemClassObject **out )
{
    VARIANT retval;
    IWbemClassObject *sig, *out_params = NULL;
    HRESULT hr;

    FIXME("stub\n");

    hr = create_signature( class_systemsecurityW, method_setsdW, PARAM_OUT, &sig );

    if (SUCCEEDED(hr))
    {
        hr = IWbemClassObject_SpawnInstance( sig, 0, &out_params );

        IWbemClassObject_Release( sig );
    }

    if (SUCCEEDED(hr))
    {
        set_variant( VT_UI4, S_OK, NULL, &retval );
        hr = IWbemClassObject_Put( out_params, param_returnvalueW, 0, &retval, CIM_UINT32 );

        if (SUCCEEDED(hr) && out)
        {
            *out = out_params;
            IWbemClassObject_AddRef( out_params );
        }

        IWbemClassObject_Release( out_params );
    }

    return hr;
}

