#ifndef CBJECT_CLASSTYPEINFOINSTANCEFUN_H
#define CBJECT_CLASSTYPEINFOINSTANCEFUN_H
#include "Cbject_FunOverride.h"

/*
Cbject_ClassTypeInfoInstanceFun_Prototype
*/
#define Cbject_ClassTypeInfoInstanceFun_Prototype(class) \
    class##Type const * const class##Type_instance()

/*
Cbject_ClassTypeInfoInstanceFun_Impl
*/
#define Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride_x1(funPrototypePack, superClass) \
    Cbject_FunOverride(Type, superClass, funPrototypePack);

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride_x0(...) \
    Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride_x1(__VA_ARGS__);

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride(funPrototypeWithSuperClassPack) \
    Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride_x0(Cbject_Utils_unpack(funPrototypeWithSuperClassPack));

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseNA(class, superClass, ...)                                      \
    Cbject_ClassTypeInfoInstanceFun_Prototype(class)                                                             \
    {                                                                                                            \
        static class##Type type;                                                                                 \
                                                                                                                 \
        typedef struct ObjectTypeT                                                                               \
        {                                                                                                        \
            Cbject_Settings_maxAlign align;                                                                      \
            char const * name;                                                                                   \
            ObjectType * superType;                                                                              \
            ObjectVirtFuns virtFuns;                                                                             \
        } ObjectTypeT;                                                                                           \
                                                                                                                 \
        if (((ObjectTypeT *)&type)->name == NULL)                                                                \
        {                                                                                                        \
            /*static char const * const name = #class;  */                                                       \
            *((superClass##TypeContainer *)&type) = *((superClass##TypeContainer *)superClass##Type_instance()); \
            ((ObjectTypeT *)&type)->name = NULL;                                                                 \
            ((ObjectTypeT *)&type)->virtFuns.size = (UInt8(*)(Object const * const me))super_##class##_size;     \
            ((ObjectTypeT *)&type)->name = #class;                                                               \
            ((ObjectTypeT *)&type)->superType = (ObjectType *)superClass##Type_instance();                       \
        }                                                                                                        \
                                                                                                                 \
        return &type;                                                                                            \
    }

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup(class, superClass, ...)                             \
    Cbject_ClassTypeInfoInstanceFun_Prototype(class)                                                                  \
    {                                                                                                                 \
        static class##Type type;                                                                                      \
                                                                                                                      \
        typedef struct ObjectTypeT                                                                                    \
        {                                                                                                             \
            Cbject_Settings_maxAlign align;                                                                           \
            char const * name;                                                                                        \
            ObjectType * superType;                                                                                   \
            ObjectVirtFuns virtFuns;                                                                                  \
        } ObjectTypeT;                                                                                                \
                                                                                                                      \
        if (((ObjectTypeT *)&type)->name == NULL)                                                                     \
        {                                                                                                             \
            /*static char const * const name = #class;  */                                                            \
            *((superClass##TypeContainer *)&type) = *((superClass##TypeContainer *)superClass##Type_instance());      \
            ((ObjectTypeT *)&type)->name = NULL;                                                                      \
            ((ObjectTypeT *)&type)->virtFuns.size = (UInt8(*)(Object const * const me))super_##class##_size;          \
            Cbject_Utils_forEach(Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride, __VA_ARGS__); \
            ((ObjectTypeT *)&type)->name = #class;                                                                    \
            ((ObjectTypeT *)&type)->superType = (ObjectType *)superClass##Type_instance();                            \
        }                                                                                                             \
                                                                                                                      \
        return &type;                                                                                                 \
    }

#define Cbject_ClassTypeInfoInstanceFun_Impl_x1(class, superClass, funOverrideSetupCase, ...) \
    Cbject_ClassTypeInfoInstanceFun_Impl_case##funOverrideSetupCase(class, superClass, __VA_ARGS__)

#define Cbject_ClassTypeInfoInstanceFun_Impl_x0(class, superClass, ...) \
    Cbject_ClassTypeInfoInstanceFun_Impl_x1(class, superClass, __VA_ARGS__)

#define Cbject_ClassTypeInfoInstanceFun_Impl(class, superClass, funOverrideSetupPack) \
    Cbject_ClassTypeInfoInstanceFun_Impl_x0(class, superClass, Cbject_Utils_unpack(funOverrideSetupPack))

#endif // CBJECT_CLASSTYPEINFOINSTANCEFUN_H
