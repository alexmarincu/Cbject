#ifndef ___CBJ_CLASSSETUP_H
#define ___CBJ_CLASSSETUP_H
#include "../Cbj_Settings.h"
#include "___Cbj_DeleteObjectImpl.h"
#include "___Cbj_GetObjectImpl.h"
#include "___Cbj_NewObjectImpl.h"

#if Cbj_Settings_useHeap == true
    #include <stdlib.h>
    #if Cbj_Settings_useStaticPool == true
        #define ___Cbj_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                    \
            ___Cbj_GetObjectImpl(cbjType);                                      \
            ___Cbj_NewObjectImpl(cbjType);                                      \
            ___Cbj_DeleteObjectImpl(cbjType)
    #else
        #define ___Cbj_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                    \
            ___Cbj_NewObjectImpl(cbjType);                                      \
            ___Cbj_DeleteObjectImpl(cbjType)
    #endif
#else
    #if Cbj_Settings_useStaticPool == true
        #define ___Cbj_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                    \
            ___Cbj_GetObjectImpl(cbjType)
    #else
        #define ___Cbj_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);
    #endif
#endif

#endif // ___CBJ_CLASSSETUP_H
