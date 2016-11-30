

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Nov 30 11:33:12 2016
 */
/* Compiler settings for C:\Users\ashresth\AppData\Local\Temp\Component.idl-4a15b4e3:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "Component.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   31                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _Component_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } Component_MIDL_TYPE_FORMAT_STRING;

typedef struct _Component_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } Component_MIDL_PROC_FORMAT_STRING;

typedef struct _Component_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } Component_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const Component_MIDL_TYPE_FORMAT_STRING Component__MIDL_TypeFormatString;
extern const Component_MIDL_PROC_FORMAT_STRING Component__MIDL_ProcFormatString;
extern const Component_MIDL_EXPR_FORMAT_STRING Component__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO __x_ABI_CComponent_CIHen_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO __x_ABI_CComponent_CIHen_ProxyInfo;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const Component_MIDL_PROC_FORMAT_STRING Component__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Cluck */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x6 ),	/* 6 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 24 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const Component_MIDL_TYPE_FORMAT_STRING Component__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_Component_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IInspectable, ver. 0.0,
   GUID={0xAF86E2E0,0xB12D,0x4c6a,{0x9C,0x5A,0xD7,0xAA,0x65,0x10,0x1E,0x90}} */


/* Object interface: __x_ABI_CComponent_CIHen, ver. 0.0,
   GUID={0xd259c600,0x6ec0,0x4b17,{0x97,0x9d,0x5e,0x04,0xee,0x84,0xc3,0xfa}} */

#pragma code_seg(".orpc")
static const unsigned short __x_ABI_CComponent_CIHen_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO __x_ABI_CComponent_CIHen_ProxyInfo =
    {
    &Object_StubDesc,
    Component__MIDL_ProcFormatString.Format,
    &__x_ABI_CComponent_CIHen_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO __x_ABI_CComponent_CIHen_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Component__MIDL_ProcFormatString.Format,
    &__x_ABI_CComponent_CIHen_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) ___x_ABI_CComponent_CIHenProxyVtbl = 
{
    &__x_ABI_CComponent_CIHen_ProxyInfo,
    &IID___x_ABI_CComponent_CIHen,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IInspectable::GetIids */ ,
    0 /* IInspectable::GetRuntimeClassName */ ,
    0 /* IInspectable::GetTrustLevel */ ,
    (void *) (INT_PTR) -1 /* __x_ABI_CComponent_CIHen::Cluck */
};


static const PRPC_STUB_FUNCTION __x_ABI_CComponent_CIHen_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl ___x_ABI_CComponent_CIHenStubVtbl =
{
    &IID___x_ABI_CComponent_CIHen,
    &__x_ABI_CComponent_CIHen_ServerInfo,
    7,
    &__x_ABI_CComponent_CIHen_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_Component_0000_0001, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    Component__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _Component_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &___x_ABI_CComponent_CIHenProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _Component_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &___x_ABI_CComponent_CIHenStubVtbl,
    0
};

PCInterfaceName const _Component_InterfaceNamesList[] = 
{
    "__x_ABI_CComponent_CIHen",
    0
};

const IID *  const _Component_BaseIIDList[] = 
{
    &IID_IInspectable,
    0
};


#define _Component_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _Component, pIID, n)

int __stdcall _Component_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_Component_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo Component_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _Component_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _Component_StubVtblList,
    (const PCInterfaceName * ) & _Component_InterfaceNamesList,
    (const IID ** ) & _Component_BaseIIDList,
    & _Component_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

