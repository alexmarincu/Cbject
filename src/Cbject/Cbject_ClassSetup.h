#ifndef CBJECT_CLASSSETUP_H
#define CBJECT_CLASSSETUP_H
#include "Cbject_DeleteObjectImpl.h"
#include "Cbject_GetObjectImpl.h"
#include "Cbject_NewObjectImpl.h"
#include "Cbject_NewOnStackFunImpl.h"
#include "Cbject_Settings.h"

#if Cbject_Settings_useHeap == true
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_ClassSetup(typeName, parent, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                     \
            Cbject_NewOnStackFunImpl(typeName);                             \
            Cbject_GetObjectImpl(typeName);                                 \
            Cbject_NewObjectImpl(typeName);                                 \
            Cbject_DeleteObjectImpl(typeName)
    #else
        #define Cbject_ClassSetup(typeName, parent, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                     \
            Cbject_NewOnStackFunImpl(typeName);                             \
            Cbject_NewObjectImpl(typeName);                                 \
            Cbject_DeleteObjectImpl(typeName)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_ClassSetup(typeName, parent, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                     \
            Cbject_NewOnStackFunImpl(typeName);                             \
            Cbject_GetObjectImpl(typeName)
    #else
        #define Cbject_ClassSetup(typeName, parent, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                     \
            Cbject_NewOnStackFunImpl(typeName)
    #endif
#endif

#endif // CBJECT_CLASSSETUP_H
