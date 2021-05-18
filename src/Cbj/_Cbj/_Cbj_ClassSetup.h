#ifndef _CBJ_CLASSSETUP_H
#define _CBJ_CLASSSETUP_H
#include "../Cbj_Settings.h"
#include "_Cbj_DeleteObjectImpl.h"
#include "_Cbj_GetObjectImpl.h"
#include "_Cbj_NewObjectImpl.h"

#if Cbj_Settings_useHeap == true
    #include <stdlib.h>
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                  \
            _Cbj_GetObjectImpl(cbjType);                                 \
            _Cbj_NewObjectImpl(cbjType);                                 \
            _Cbj_DeleteObjectImpl(cbjType)
    #else
        #define _Cbj_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                  \
            _Cbj_NewObjectImpl(cbjType);                                 \
            _Cbj_DeleteObjectImpl(cbjType)
    #endif
#else
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                  \
            _Cbj_GetObjectImpl(cbjType)
    #else
        #define _Cbj_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);
    #endif
#endif

#endif // _CBJ_CLASSSETUP_H
