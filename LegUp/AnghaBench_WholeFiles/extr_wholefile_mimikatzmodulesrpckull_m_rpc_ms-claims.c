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
typedef  int /*<<< orphan*/  handle_t ;
struct TYPE_2__ {int /*<<< orphan*/ * Format; } ;
typedef  int /*<<< orphan*/  PMIDL_TYPE_PICKLING_INFO ;
typedef  int /*<<< orphan*/  PFORMAT_STRING ;
typedef  int /*<<< orphan*/  PCLAIMS_SET_METADATA ;
typedef  int /*<<< orphan*/  PCLAIMS_SET ;

/* Variables and functions */
 int /*<<< orphan*/  Claims_StubDesc ; 
 TYPE_1__ Claims__MIDL_TypeFormatString ; 
 size_t NdrMesTypeAlignSize2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NdrMesTypeDecode2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NdrMesTypeEncode2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NdrMesTypeFree2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 size_t _Claims_MIDL_TYPE_FORMAT_OFFSET ; 
 int /*<<< orphan*/  __MIDL_TypePicklingInfo ; 

size_t PCLAIMS_SET_AlignSize(handle_t _MidlEsHandle, PCLAIMS_SET * _pType)
{
    return NdrMesTypeAlignSize2(_MidlEsHandle, (PMIDL_TYPE_PICKLING_INFO) &__MIDL_TypePicklingInfo, &Claims_StubDesc, (PFORMAT_STRING ) &Claims__MIDL_TypeFormatString.Format[2], _pType);
}

void PCLAIMS_SET_Encode(handle_t _MidlEsHandle, PCLAIMS_SET * _pType)
{
    NdrMesTypeEncode2(_MidlEsHandle, (PMIDL_TYPE_PICKLING_INFO) &__MIDL_TypePicklingInfo, &Claims_StubDesc, (PFORMAT_STRING) &Claims__MIDL_TypeFormatString.Format[2], _pType);
}

void PCLAIMS_SET_Decode(handle_t _MidlEsHandle, PCLAIMS_SET * _pType)
{
    NdrMesTypeDecode2(_MidlEsHandle, (PMIDL_TYPE_PICKLING_INFO) &__MIDL_TypePicklingInfo, &Claims_StubDesc, (PFORMAT_STRING) &Claims__MIDL_TypeFormatString.Format[2], _pType);
}

void PCLAIMS_SET_Free(handle_t _MidlEsHandle, PCLAIMS_SET * _pType)
{
    NdrMesTypeFree2(_MidlEsHandle, (PMIDL_TYPE_PICKLING_INFO) &__MIDL_TypePicklingInfo, &Claims_StubDesc, (PFORMAT_STRING) &Claims__MIDL_TypeFormatString.Format[2], _pType);
}

size_t PCLAIMS_SET_METADATA_AlignSize(handle_t _MidlEsHandle, PCLAIMS_SET_METADATA * _pType)
{
    return NdrMesTypeAlignSize2(_MidlEsHandle, (PMIDL_TYPE_PICKLING_INFO) &__MIDL_TypePicklingInfo, &Claims_StubDesc, (PFORMAT_STRING) &Claims__MIDL_TypeFormatString.Format[_Claims_MIDL_TYPE_FORMAT_OFFSET], _pType);
}

void PCLAIMS_SET_METADATA_Encode(handle_t _MidlEsHandle, PCLAIMS_SET_METADATA * _pType)
{
    NdrMesTypeEncode2(_MidlEsHandle, (PMIDL_TYPE_PICKLING_INFO) &__MIDL_TypePicklingInfo, &Claims_StubDesc, (PFORMAT_STRING) &Claims__MIDL_TypeFormatString.Format[_Claims_MIDL_TYPE_FORMAT_OFFSET], _pType);
}

void PCLAIMS_SET_METADATA_Decode(handle_t _MidlEsHandle, PCLAIMS_SET_METADATA * _pType)
{
    NdrMesTypeDecode2(_MidlEsHandle, (PMIDL_TYPE_PICKLING_INFO) &__MIDL_TypePicklingInfo, &Claims_StubDesc, (PFORMAT_STRING) &Claims__MIDL_TypeFormatString.Format[_Claims_MIDL_TYPE_FORMAT_OFFSET], _pType);
}

void PCLAIMS_SET_METADATA_Free(handle_t _MidlEsHandle, PCLAIMS_SET_METADATA * _pType)
{
    NdrMesTypeFree2(_MidlEsHandle, (PMIDL_TYPE_PICKLING_INFO) &__MIDL_TypePicklingInfo, &Claims_StubDesc, (PFORMAT_STRING) &Claims__MIDL_TypeFormatString.Format[_Claims_MIDL_TYPE_FORMAT_OFFSET], _pType);
}

