#ifndef CBJECT_CLASSSETUP_H
#define CBJECT_CLASSSETUP_H
#include "Cbject_DeleteObjectImpl.h"
#include "Cbject_GetObjectImpl.h"
#include "Cbject_NewObjectImpl.h"
#include "Cbject_NewOnStackFunImpl.h"
#include "Cbject_Settings.h"

#if Cbject_Settings_useHeap == true
    #include <stdlib.h>
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                    \
            Cbject_NewOnStackFunImpl(cbjType);                                  \
            Cbject_GetObjectImpl(cbjType);                                      \
            Cbject_NewObjectImpl(cbjType);                                      \
            Cbject_DeleteObjectImpl(cbjType)
    #else
        #define Cbject_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                    \
            Cbject_NewOnStackFunImpl(cbjType);                                  \
            Cbject_NewObjectImpl(cbjType);                                      \
            Cbject_DeleteObjectImpl(cbjType)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                    \
            Cbject_NewOnStackFunImpl(cbjType);                                  \
            Cbject_GetObjectImpl(cbjType)
    #else
        #define Cbject_ClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns) \
            AbstractClassSetup(virtFunCalls, bindSuperFuns);                    \
            Cbject_NewOnStackFunImpl(cbjType)
    #endif
#endif

#endif // CBJECT_CLASSSETUP_H
