

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Component_h__
#define __Component_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ____x_ABI_CComponent_CIHen_FWD_DEFINED__
#define ____x_ABI_CComponent_CIHen_FWD_DEFINED__
typedef interface __x_ABI_CComponent_CIHen __x_ABI_CComponent_CIHen;

#ifdef __cplusplus
namespace ABI {
    namespace Component {
        interface IHen;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CComponent_CIHen_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_Component_0000_0000 */
/* [local] */ 

#if !defined(____x_ABI_CComponent_CIHen_INTERFACE_DEFINED__)
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Component_IHen[] = L"Component.IHen";
#endif /* !defined(____x_ABI_CComponent_CIHen_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_Component_0000_0000 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0000_v0_0_s_ifspec;

#ifndef ____x_ABI_CComponent_CIHen_INTERFACE_DEFINED__
#define ____x_ABI_CComponent_CIHen_INTERFACE_DEFINED__

/* interface __x_ABI_CComponent_CIHen */
/* [uuid][object] */ 



/* interface ABI::Component::IHen */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CComponent_CIHen;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace Component {
            
            MIDL_INTERFACE("d259c600-6ec0-4b17-979d-5e04ee84c3fa")
            IHen : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE Cluck( void) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_IHen = __uuidof(IHen);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CComponent_CIHenVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CComponent_CIHen * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CComponent_CIHen * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CComponent_CIHen * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CComponent_CIHen * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CComponent_CIHen * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CComponent_CIHen * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *Cluck )( 
            __x_ABI_CComponent_CIHen * This);
        
        END_INTERFACE
    } __x_ABI_CComponent_CIHenVtbl;

    interface __x_ABI_CComponent_CIHen
    {
        CONST_VTBL struct __x_ABI_CComponent_CIHenVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CComponent_CIHen_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CComponent_CIHen_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CComponent_CIHen_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CComponent_CIHen_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CComponent_CIHen_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CComponent_CIHen_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CComponent_CIHen_Cluck(This)	\
    ( (This)->lpVtbl -> Cluck(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CComponent_CIHen_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_Component_0000_0001 */
/* [local] */ 

#ifdef __cplusplus
namespace ABI {
namespace Component {
class Hen;
} /*Component*/
}
#endif

#ifndef RUNTIMECLASS_Component_Hen_DEFINED
#define RUNTIMECLASS_Component_Hen_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Component_Hen[] = L"Component.Hen";
#endif


/* interface __MIDL_itf_Component_0000_0001 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


