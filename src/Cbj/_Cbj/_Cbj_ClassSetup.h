#ifndef _CBJ_CLASSSETUP_H
#define _CBJ_CLASSSETUP_H
#include "../Cbj_Settings.h"
#include "_Cbj_DeleteObjectImpl.h"
#include "_Cbj_GetObjectImpl.h"
#include "_Cbj_NewObjectImpl.h"

#if Cbj_Settings_useHeap == true
    #include <stdlib.h>
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_ClassSetup(m_cbjType, mParent, mVirtFunCalls, mBindSuperFuns) \
            AbstractClassSetup(mVirtFunCalls, mBindSuperFuns);                  \
            _Cbj_GetObjectImpl(m_cbjType);                                 \
            _Cbj_NewObjectImpl(m_cbjType);                                 \
            _Cbj_DeleteObjectImpl(m_cbjType)
    #else
        #define _Cbj_ClassSetup(m_cbjType, mParent, mVirtFunCalls, mBindSuperFuns) \
            AbstractClassSetup(mVirtFunCalls, mBindSuperFuns);                  \
            _Cbj_NewObjectImpl(m_cbjType);                                 \
            _Cbj_DeleteObjectImpl(m_cbjType)
    #endif
#else
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_ClassSetup(m_cbjType, mParent, mVirtFunCalls, mBindSuperFuns) \
            AbstractClassSetup(mVirtFunCalls, mBindSuperFuns);                  \
            _Cbj_GetObjectImpl(m_cbjType)
    #else
        #define _Cbj_ClassSetup(m_cbjType, mParent, mVirtFunCalls, mBindSuperFuns) \
            AbstractClassSetup(mVirtFunCalls, mBindSuperFuns);
    #endif
#endif

#endif // _CBJ_CLASSSETUP_H
