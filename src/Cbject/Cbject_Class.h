#ifndef CBJECT_CLASS_H
#define CBJECT_CLASS_H
#include "Cbject_AbstractClass.h"
#include "Cbject_Settings.h"
#include "Cbject_StackCreateObjectFun.h"

/*
Cbject_Class
*/
#if Cbject_Settings_useHeap == true
    #include "Cbject_CreateObjectFun.h"
    #include "Cbject_DeleteObjectFun.h"
    #if Cbject_Settings_useStaticPool == true
        #include "Cbject_GetObjectFun.h"
        #define Cbject_Class(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack)      \
            Cbject_AbstractClass(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack); \
            Cbject_StackCreateObjectFun_Prototype(class);                                          \
            Cbject_GetObjectFun_Prototype(class);                                                  \
            Cbject_CreateObjectFun_Prototype(class);                                               \
            Cbject_DeleteObjectFun_Prototype(class)
    #else
        #define Cbject_Class(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack)      \
            Cbject_AbstractClass(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack); \
            Cbject_StackCreateObjectFun_Prototype(class);                                          \
            Cbject_CreateObjectFun_Prototype(class);                                               \
            Cbject_DeleteObjectFun_Prototype(class)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #include "Cbject_GetObjectFun.h"
        #define Cbject_Class(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack)      \
            Cbject_AbstractClass(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack); \
            Cbject_StackCreateObjectFun_Prototype(class);                                          \
            Cbject_GetObjectFun_Prototype(class)
    #else
        #define Cbject_Class(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack)      \
            Cbject_AbstractClass(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack); \
            Cbject_StackCreateObjectFun_Prototype(class)
    #endif
#endif

/*
Cbject_Class_Setup
*/
#if Cbject_Settings_useHeap == true
    #include "Cbject_CreateObjectFun.h"
    #include "Cbject_DeleteObjectFun.h"
    #if Cbject_Settings_useStaticPool == true
        #include "Cbject_GetObjectFun.h"
        #define Cbject_Class_Setup(class, superClass, virtFunSetup, funOverrideSetupPack)      \
            Cbject_AbstractClass_Setup(class, superClass, virtFunSetup, funOverrideSetupPack); \
            Cbject_StackCreateObjectFun_Impl(class);                                           \
            Cbject_GetObjectFun_Impl(class);                                                   \
            Cbject_CreateObjectFun_Impl(class);                                                \
            Cbject_DeleteObjectFun_Impl(class)
    #else
        #define Cbject_Class_Setup(class, superClass, virtFunSetup, funOverrideSetupPack)      \
            Cbject_AbstractClass_Setup(class, superClass, virtFunSetup, funOverrideSetupPack); \
            Cbject_StackCreateObjectFun_Impl(class);                                           \
            Cbject_CreateObjectFun_Impl(class);                                                \
            Cbject_DeleteObjectFun_Impl(class)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #include "Cbject_GetObjectFun.h"
        #define Cbject_Class_Setup(class, superClass, virtFunSetup, funOverrideSetupPack)      \
            Cbject_AbstractClass_Setup(class, superClass, virtFunSetup, funOverrideSetupPack); \
            Cbject_StackCreateObjectFun_Impl(class);                                           \
            Cbject_GetObjectFun_Impl(class)
    #else
        #define Cbject_Class_Setup(class, superClass, virtFunSetup, funOverrideSetupPack)      \
            Cbject_AbstractClass_Setup(class, superClass, virtFunSetup, funOverrideSetupPack); \
            Cbject_StackCreateObjectFun_Impl(class)
    #endif
#endif

#endif // CBJECT_CLASS_H
