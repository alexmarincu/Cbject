#ifndef CBJECT_CLASS_H
#define CBJECT_CLASS_H
#include "Cbject_DeleteObjectFun.h"
#include "Cbject_GetObjectFunPrototype.h"
#include "Cbject_GetObjectImpl.h"
#include "Cbject_NewObjectFunPrototype.h"
#include "Cbject_NewObjectImpl.h"
#include "Cbject_NewOnStackFunImpl.h"
#include "Cbject_NewOnStackFunPrototype.h"
#include "Cbject_Settings.h"

#if Cbject_Settings_useHeap == true
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class(typeName, parent, params, data, virtFuns) \
            AbstractClass(params, data, virtFuns);                     \
            Cbject_NewOnStackFunPrototype(typeName);                   \
            Cbject_GetObjectFunPrototype(typeName);                    \
            Cbject_NewObjectFunPrototype(typeName);                    \
            Cbject_DeleteObjectFun_Prototype(typeName)
    #else
        #define Cbject_Class(typeName, parent, params, data, virtFuns) \
            AbstractClass(params, data, virtFuns);                     \
            Cbject_NewOnStackFunPrototype(typeName);                   \
            Cbject_NewObjectFunPrototype(typeName);                    \
            Cbject_DeleteObjectFun_Prototype(typeName)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class(typeName, parent, params, data, virtFuns) \
            AbstractClass(params, data, virtFuns);                     \
            Cbject_NewOnStackFunPrototype(typeName);                   \
            Cbject_GetObjectFunPrototype(typeName)
    #else
        #define Cbject_Class(typeName, parent, params, data, virtFuns) \
            AbstractClass(params, data, virtFuns);                     \
            Cbject_NewOnStackFunPrototype(typeName)
    #endif
#endif

#if Cbject_Settings_useHeap == true
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class_Setup(typeName, parent, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                      \
            Cbject_NewOnStackFunImpl(typeName);                              \
            Cbject_GetObjectImpl(typeName);                                  \
            Cbject_NewObjectImpl(typeName);                                  \
            Cbject_DeleteObjectFun_Impl(typeName)
    #else
        #define Cbject_Class_Setup(typeName, parent, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                      \
            Cbject_NewOnStackFunImpl(typeName);                              \
            Cbject_NewObjectImpl(typeName);                                  \
            Cbject_DeleteObjectFun_Impl(typeName)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class_Setup(typeName, parent, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                      \
            Cbject_NewOnStackFunImpl(typeName);                              \
            Cbject_GetObjectImpl(typeName)
    #else
        #define Cbject_Class_Setup(typeName, parent, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                      \
            Cbject_NewOnStackFunImpl(typeName)
    #endif
#endif

#endif // CBJECT_CLASS_H
