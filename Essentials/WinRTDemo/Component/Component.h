

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


#ifndef ____x_ABI_CComponent_CILayer_FWD_DEFINED__
#define ____x_ABI_CComponent_CILayer_FWD_DEFINED__
typedef interface __x_ABI_CComponent_CILayer __x_ABI_CComponent_CILayer;

#ifdef __cplusplus
namespace ABI {
    namespace Component {
        interface ILayer;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CComponent_CILayer_FWD_DEFINED__ */


#ifndef ____x_ABI_CComponent_CIHenFactory_FWD_DEFINED__
#define ____x_ABI_CComponent_CIHenFactory_FWD_DEFINED__
typedef interface __x_ABI_CComponent_CIHenFactory __x_ABI_CComponent_CIHenFactory;

#ifdef __cplusplus
namespace ABI {
    namespace Component {
        interface IHenFactory;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CComponent_CIHenFactory_FWD_DEFINED__ */


#ifndef ____x_ABI_CComponent_CIHenStatics_FWD_DEFINED__
#define ____x_ABI_CComponent_CIHenStatics_FWD_DEFINED__
typedef interface __x_ABI_CComponent_CIHenStatics __x_ABI_CComponent_CIHenStatics;

#ifdef __cplusplus
namespace ABI {
    namespace Component {
        interface IHenStatics;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CComponent_CIHenStatics_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_Component_0000_0000 */
/* [local] */ 

#ifdef __cplusplus
namespace ABI {
namespace Component {
class Hen;
} /*Component*/
}
#endif

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

#if !defined(____x_ABI_CComponent_CILayer_INTERFACE_DEFINED__)
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Component_ILayer[] = L"Component.ILayer";
#endif /* !defined(____x_ABI_CComponent_CILayer_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_Component_0000_0001 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0001_v0_0_s_ifspec;

#ifndef ____x_ABI_CComponent_CILayer_INTERFACE_DEFINED__
#define ____x_ABI_CComponent_CILayer_INTERFACE_DEFINED__

/* interface __x_ABI_CComponent_CILayer */
/* [uuid][object] */ 



/* interface ABI::Component::ILayer */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CComponent_CILayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace Component {
            
            MIDL_INTERFACE("6d5d2b7b-7760-47af-8aac-30167556aa7d")
            ILayer : public IInspectable
            {
            public:
                virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Eggs( 
                    /* [out][retval] */ INT32 *value) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_ILayer = __uuidof(ILayer);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CComponent_CILayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CComponent_CILayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CComponent_CILayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CComponent_CILayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CComponent_CILayer * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CComponent_CILayer * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CComponent_CILayer * This,
            /* [out] */ TrustLevel *trustLevel);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Eggs )( 
            __x_ABI_CComponent_CILayer * This,
            /* [out][retval] */ INT32 *value);
        
        END_INTERFACE
    } __x_ABI_CComponent_CILayerVtbl;

    interface __x_ABI_CComponent_CILayer
    {
        CONST_VTBL struct __x_ABI_CComponent_CILayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CComponent_CILayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CComponent_CILayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CComponent_CILayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CComponent_CILayer_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CComponent_CILayer_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CComponent_CILayer_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CComponent_CILayer_get_Eggs(This,value)	\
    ( (This)->lpVtbl -> get_Eggs(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CComponent_CILayer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_Component_0000_0002 */
/* [local] */ 

#if !defined(____x_ABI_CComponent_CIHenFactory_INTERFACE_DEFINED__)
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Component_IHenFactory[] = L"Component.IHenFactory";
#endif /* !defined(____x_ABI_CComponent_CIHenFactory_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_Component_0000_0002 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0002_v0_0_s_ifspec;

#ifndef ____x_ABI_CComponent_CIHenFactory_INTERFACE_DEFINED__
#define ____x_ABI_CComponent_CIHenFactory_INTERFACE_DEFINED__

/* interface __x_ABI_CComponent_CIHenFactory */
/* [uuid][object] */ 



/* interface ABI::Component::IHenFactory */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CComponent_CIHenFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace Component {
            
            MIDL_INTERFACE("186f373e-4901-48d7-b3dd-8b209c913342")
            IHenFactory : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE CreateHen( 
                    /* [in] */ INT32 eggs,
                    /* [out][retval] */ ABI::Component::IHen **instance) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_IHenFactory = __uuidof(IHenFactory);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CComponent_CIHenFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CComponent_CIHenFactory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CComponent_CIHenFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CComponent_CIHenFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CComponent_CIHenFactory * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CComponent_CIHenFactory * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CComponent_CIHenFactory * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *CreateHen )( 
            __x_ABI_CComponent_CIHenFactory * This,
            /* [in] */ INT32 eggs,
            /* [out][retval] */ __x_ABI_CComponent_CIHen **instance);
        
        END_INTERFACE
    } __x_ABI_CComponent_CIHenFactoryVtbl;

    interface __x_ABI_CComponent_CIHenFactory
    {
        CONST_VTBL struct __x_ABI_CComponent_CIHenFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CComponent_CIHenFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CComponent_CIHenFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CComponent_CIHenFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CComponent_CIHenFactory_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CComponent_CIHenFactory_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CComponent_CIHenFactory_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CComponent_CIHenFactory_CreateHen(This,eggs,instance)	\
    ( (This)->lpVtbl -> CreateHen(This,eggs,instance) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CComponent_CIHenFactory_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_Component_0000_0003 */
/* [local] */ 

#if !defined(____x_ABI_CComponent_CIHenStatics_INTERFACE_DEFINED__)
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Component_IHenStatics[] = L"Component.IHenStatics";
#endif /* !defined(____x_ABI_CComponent_CIHenStatics_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_Component_0000_0003 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0003_v0_0_s_ifspec;

#ifndef ____x_ABI_CComponent_CIHenStatics_INTERFACE_DEFINED__
#define ____x_ABI_CComponent_CIHenStatics_INTERFACE_DEFINED__

/* interface __x_ABI_CComponent_CIHenStatics */
/* [uuid][object] */ 



/* interface ABI::Component::IHenStatics */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CComponent_CIHenStatics;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace Component {
            
            MIDL_INTERFACE("b15199db-9db9-47af-a0a5-4b2a7be29494")
            IHenStatics : public IInspectable
            {
            public:
                virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Layers( 
                    /* [out][retval] */ INT32 *value) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_IHenStatics = __uuidof(IHenStatics);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CComponent_CIHenStaticsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CComponent_CIHenStatics * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CComponent_CIHenStatics * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CComponent_CIHenStatics * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CComponent_CIHenStatics * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CComponent_CIHenStatics * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CComponent_CIHenStatics * This,
            /* [out] */ TrustLevel *trustLevel);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Layers )( 
            __x_ABI_CComponent_CIHenStatics * This,
            /* [out][retval] */ INT32 *value);
        
        END_INTERFACE
    } __x_ABI_CComponent_CIHenStaticsVtbl;

    interface __x_ABI_CComponent_CIHenStatics
    {
        CONST_VTBL struct __x_ABI_CComponent_CIHenStaticsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CComponent_CIHenStatics_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CComponent_CIHenStatics_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CComponent_CIHenStatics_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CComponent_CIHenStatics_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CComponent_CIHenStatics_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CComponent_CIHenStatics_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CComponent_CIHenStatics_get_Layers(This,value)	\
    ( (This)->lpVtbl -> get_Layers(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CComponent_CIHenStatics_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_Component_0000_0004 */
/* [local] */ 

#ifndef RUNTIMECLASS_Component_Hen_DEFINED
#define RUNTIMECLASS_Component_Hen_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Component_Hen[] = L"Component.Hen";
#endif


/* interface __MIDL_itf_Component_0000_0004 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Component_0000_0004_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


