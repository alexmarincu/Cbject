#ifndef CBJECT_CLASSTYPEINFOINSTANCEFUN_H
#define CBJECT_CLASSTYPEINFOINSTANCEFUN_H
#include "Cbject_FunOverride.h"

/*
Cbject_ClassTypeInfoInstanceFun_Prototype
*/
#define Cbject_ClassTypeInfoInstanceFun_Prototype(className) \
    className##Type const * const className##Type_instance()

/*
Cbject_ClassTypeInfoInstanceFun_Impl
*/
#define Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride_x1(funPrototype, superClassName) \
    Cbject_FunOverride(Type, superClassName, funPrototype);

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride_x0(...) \
    Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride_x1(__VA_ARGS__);

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride(funPrototypeWithSuperClassName) \
    Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride_x0(Cbject_Utils_unpack(funPrototypeWithSuperClassName));

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseNA(className, superClassName, ...)                                          \
    Cbject_ClassTypeInfoInstanceFun_Prototype(className)                                                                     \
    {                                                                                                                        \
        static className##Type type;                                                                                         \
                                                                                                                             \
        typedef struct ObjectTypeT                                                                                           \
        {                                                                                                                    \
            Cbject_Settings_maxAlign align;                                                                                  \
            char const * name;                                                                                               \
            ObjectType * superType;                                                                                          \
            ObjectVirtFuns virtFuns;                                                                                         \
        } ObjectTypeT;                                                                                                       \
                                                                                                                             \
        if (((ObjectTypeT *)&type)->name == NULL)                                                                            \
        {                                                                                                                    \
            /*static char const * const name = #className;  */                                                               \
            *((superClassName##TypeContainer *)&type) = *((superClassName##TypeContainer *)superClassName##Type_instance()); \
            ((ObjectTypeT *)&type)->name = NULL;                                                                             \
            ((ObjectTypeT *)&type)->virtFuns.size = (uint8(*)(Object const * const me))super_##className##_size;             \
            ((ObjectTypeT *)&type)->name = #className;                                                                       \
            ((ObjectTypeT *)&type)->superType = (ObjectType *)superClassName##Type_instance();                               \
        }                                                                                                                    \
                                                                                                                             \
        return &type;                                                                                                        \
    }

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup(className, superClassName, ...)                            \
    Cbject_ClassTypeInfoInstanceFun_Prototype(className)                                                                     \
    {                                                                                                                        \
        static className##Type type;                                                                                         \
                                                                                                                             \
        typedef struct ObjectTypeT                                                                                           \
        {                                                                                                                    \
            Cbject_Settings_maxAlign align;                                                                                  \
            char const * name;                                                                                               \
            ObjectType * superType;                                                                                          \
            ObjectVirtFuns virtFuns;                                                                                         \
        } ObjectTypeT;                                                                                                       \
                                                                                                                             \
        if (((ObjectTypeT *)&type)->name == NULL)                                                                            \
        {                                                                                                                    \
            /*static char const * const name = #className;  */                                                               \
            *((superClassName##TypeContainer *)&type) = *((superClassName##TypeContainer *)superClassName##Type_instance()); \
            ((ObjectTypeT *)&type)->name = NULL;                                                                             \
            ((ObjectTypeT *)&type)->virtFuns.size = (uint8(*)(Object const * const me))super_##className##_size;             \
            Cbject_Utils_forEach(Cbject_ClassTypeInfoInstanceFun_Impl_caseFunOverrideSetup_funOverride, __VA_ARGS__);        \
            ((ObjectTypeT *)&type)->name = #className;                                                                       \
            ((ObjectTypeT *)&type)->superType = (ObjectType *)superClassName##Type_instance();                               \
        }                                                                                                                    \
                                                                                                                             \
        return &type;                                                                                                        \
    }

#define Cbject_ClassTypeInfoInstanceFun_Impl_x1(className, superClassName, case, ...) \
    Cbject_ClassTypeInfoInstanceFun_Impl_case##case (className, superClassName, __VA_ARGS__)

#define Cbject_ClassTypeInfoInstanceFun_Impl_x0(className, superClassName, ...) \
    Cbject_ClassTypeInfoInstanceFun_Impl_x1(className, superClassName, __VA_ARGS__)

#define Cbject_ClassTypeInfoInstanceFun_Impl(className, superClassName, funOverrideSetup) \
    Cbject_ClassTypeInfoInstanceFun_Impl_x0(className, superClassName, Cbject_Utils_unpack(funOverrideSetup))

#endif // CBJECT_CLASSTYPEINFOINSTANCEFUN_H
