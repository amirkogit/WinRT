

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Dec 01 09:54:35 2016
 */
/* Compiler settings for C:\Users\ashresth\AppData\Local\Temp\Component.idl-fae660e4:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID___x_ABI_CComponent_CIHen,0xd259c600,0x6ec0,0x4b17,0x97,0x9d,0x5e,0x04,0xee,0x84,0xc3,0xfa);


MIDL_DEFINE_GUID(IID, IID___x_ABI_CComponent_CILayer,0x6d5d2b7b,0x7760,0x47af,0x8a,0xac,0x30,0x16,0x75,0x56,0xaa,0x7d);


MIDL_DEFINE_GUID(IID, IID___x_ABI_CComponent_CIHenFactory,0x186f373e,0x4901,0x48d7,0xb3,0xdd,0x8b,0x20,0x9c,0x91,0x33,0x42);


MIDL_DEFINE_GUID(IID, IID___x_ABI_CComponent_CIHenStatics,0xb15199db,0x9db9,0x47af,0xa0,0xa5,0x4b,0x2a,0x7b,0xe2,0x94,0x94);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



