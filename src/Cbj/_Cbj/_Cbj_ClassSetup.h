#ifndef _CBJ_CLASSSETUP_H
#define _CBJ_CLASSSETUP_H
#include "../Cbj_Settings.h"
#include "_Cbj_DeleteObjectImpl.h"
#include "_Cbj_GetObjectImpl.h"
#include "_Cbj_NewObjectImpl.h"

#if Cbj_Settings_useHeap == true
    #include <stdlib.h>
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_ClassSetup(typeName, Cbj_ParentName, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                              \
            _Cbj_GetObjectImpl(typeName);                                                     \
            _Cbj_NewObjectImpl(typeName);                                                     \
            _Cbj_DeleteObjectImpl(typeName)
    #else
        #define _Cbj_ClassSetup(typeName, Cbj_ParentName, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                              \
            _Cbj_NewObjectImpl(typeName);                                                     \
            _Cbj_DeleteObjectImpl(typeName)
    #endif
#else
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_ClassSetup(typeName, Cbj_ParentName, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                              \
            _Cbj_GetObjectImpl(typeName)
    #else
        #define _Cbj_ClassSetup(typeName, Cbj_ParentName, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);
    #endif
#endif

#endif // _CBJ_CLASSSETUP_H
