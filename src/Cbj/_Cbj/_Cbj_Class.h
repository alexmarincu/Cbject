#ifndef _CBJ_CLASS_H
#define _CBJ_CLASS_H
#include "../Cbj_Settings.h"
#include "_Cbj_DeleteObjectFunPrototype.h"
#include "_Cbj_GetObjectFunPrototype.h"
#include "_Cbj_NewObjectFunPrototype.h"

#if Cbj_Settings_useHeap == true
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_Class(m_cbjType, mParent, mParams, mProps, mVirtFuns) \
            AbstractClass(mParams, mProps, mVirtFuns);                  \
            _Cbj_GetObjectFunPrototype(m_cbjType);                     \
            _Cbj_NewObjectFunPrototype(m_cbjType);                     \
            _Cbj_DeleteObjectFunPrototype(m_cbjType)
    #else
        #define _Cbj_Class(m_cbjType, mParent, mParams, mProps, mVirtFuns) \
            AbstractClass(mParams, mProps, mVirtFuns);                  \
            _Cbj_NewObjectFunPrototype(m_cbjType);                     \
            _Cbj_DeleteObjectFunPrototype(m_cbjType)
    #endif
#else
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_Class(m_cbjType, mParent, mParams, mProps, mVirtFuns) \
            AbstractClass(mParams, mProps, mVirtFuns);                  \
            _Cbj_GetObjectFunPrototype(m_cbjType)
    #else
        #define _Cbj_Class(m_cbjType, mParent, mParams, mProps, mVirtFuns) \
            AbstractClass(mParams, mProps, mVirtFuns)
    #endif
#endif

#endif // _CBJ_CLASS_H
