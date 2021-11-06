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
        #define Cbject_Class(className, superClassName, params, data, virtFuns, funs) \
            AbstractClass(params, data, virtFuns, funs);                              \
            Cbject_NewOnStackFunPrototype(className);                                 \
            Cbject_GetObjectFunPrototype(className);                                  \
            Cbject_NewObjectFunPrototype(className);                                  \
            Cbject_DeleteObjectFun_Prototype(className)
    #else
        #define Cbject_Class(className, superClassName, params, data, virtFuns, funs) \
            AbstractClass(params, data, virtFuns, funs);                              \
            Cbject_NewOnStackFunPrototype(className);                                 \
            Cbject_NewObjectFunPrototype(className);                                  \
            Cbject_DeleteObjectFun_Prototype(className)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class(className, superClassName, params, data, virtFuns, funs) \
            AbstractClass(params, data, virtFuns, funs);                              \
            Cbject_NewOnStackFunPrototype(className);                                 \
            Cbject_GetObjectFunPrototype(className)
    #else
        #define Cbject_Class(className, superClassName, params, data, virtFuns, funs) \
            AbstractClass(params, data, virtFuns, funs);                              \
            Cbject_NewOnStackFunPrototype(className)
    #endif
#endif

#if Cbject_Settings_useHeap == true
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class_Setup(className, superClassName, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                               \
            Cbject_NewOnStackFunImpl(className);                                      \
            Cbject_GetObjectImpl(className);                                          \
            Cbject_NewObjectImpl(className);                                          \
            Cbject_DeleteObjectFun_Impl(className)
    #else
        #define Cbject_Class_Setup(className, superClassName, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                               \
            Cbject_NewOnStackFunImpl(className);                                      \
            Cbject_NewObjectImpl(className);                                          \
            Cbject_DeleteObjectFun_Impl(className)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class_Setup(className, superClassName, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                               \
            Cbject_NewOnStackFunImpl(className);                                      \
            Cbject_GetObjectImpl(className)
    #else
        #define Cbject_Class_Setup(className, superClassName, virtFunCalls, bindFuns) \
            AbstractClassSetup(virtFunCalls, bindFuns);                               \
            Cbject_NewOnStackFunImpl(className)
    #endif
#endif

#endif // CBJECT_CLASS_H
