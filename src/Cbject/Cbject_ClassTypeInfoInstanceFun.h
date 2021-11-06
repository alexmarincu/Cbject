#ifndef CBJECT_CLASSTYPEINFOINSTANCEFUN_H
#define CBJECT_CLASSTYPEINFOINSTANCEFUN_H
#include "Cbject_BindFuns.h"

#define Cbject_ClassTypeInfoInstanceFun_Prototype(typeName) \
    typeName##Type const * const typeName##Type_instance()

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseBindFuns_bindFun(funPrototype) \
    Cbject_BindFun funPrototype;

#define Cbject_ClassTypeInfoInstanceFun_Impl_case(typeName, superTypeName, ...)                                           \
    Cbject_ClassTypeInfoInstanceFun_Prototype(typeName)                                                                   \
    {                                                                                                                     \
        static typeName##Type type;                                                                                       \
                                                                                                                          \
        typedef struct ObjectTypeT                                                                                        \
        {                                                                                                                 \
            Cbject_Settings_maxAlign align;                                                                               \
            char const * name;                                                                                            \
            ObjectType * superType;                                                                                       \
            ObjectVirtFuns virtFuns;                                                                                      \
        } ObjectTypeT;                                                                                                    \
                                                                                                                          \
        if (((ObjectTypeT *)&type)->name == NULL)                                                                         \
        {                                                                                                                 \
            /*static char const * const name = #typeName;  */                                                             \
            *((superTypeName##TypeContainer *)&type) = *((superTypeName##TypeContainer *)superTypeName##Type_instance()); \
            ((ObjectTypeT *)&type)->name = NULL;                                                                          \
            ((ObjectTypeT *)&type)->virtFuns.size = (uint8(*)(Object const * const me))super_##typeName##_size;           \
            ((ObjectTypeT *)&type)->name = #typeName;                                                                     \
            ((ObjectTypeT *)&type)->superType = (ObjectType *)superTypeName##Type_instance();                             \
        }                                                                                                                 \
                                                                                                                          \
        return &type;                                                                                                     \
    }

#define Cbject_ClassTypeInfoInstanceFun_Impl_caseBindFuns(typeName, superTypeName, ...)                                   \
    Cbject_ClassTypeInfoInstanceFun_Prototype(typeName)                                                                   \
    {                                                                                                                     \
        static typeName##Type type;                                                                                       \
                                                                                                                          \
        typedef struct ObjectTypeT                                                                                        \
        {                                                                                                                 \
            Cbject_Settings_maxAlign align;                                                                               \
            char const * name;                                                                                            \
            ObjectType * superType;                                                                                       \
            ObjectVirtFuns virtFuns;                                                                                      \
        } ObjectTypeT;                                                                                                    \
                                                                                                                          \
        if (((ObjectTypeT *)&type)->name == NULL)                                                                         \
        {                                                                                                                 \
            /*static char const * const name = #typeName;  */                                                             \
            *((superTypeName##TypeContainer *)&type) = *((superTypeName##TypeContainer *)superTypeName##Type_instance()); \
            ((ObjectTypeT *)&type)->name = NULL;                                                                          \
            ((ObjectTypeT *)&type)->virtFuns.size = (uint8(*)(Object const * const me))super_##typeName##_size;           \
            Cbject_Utils_forEach(Cbject_ClassTypeInfoInstanceFun_Impl_caseBindFuns_bindFun, __VA_ARGS__);                 \
            ((ObjectTypeT *)&type)->name = #typeName;                                                                     \
            ((ObjectTypeT *)&type)->superType = (ObjectType *)superTypeName##Type_instance();                             \
        }                                                                                                                 \
                                                                                                                          \
        return &type;                                                                                                     \
    }

#define Cbject_ClassTypeInfoInstanceFun_Impl_switch(typeName, superTypeName, case, ...) \
    Cbject_ClassTypeInfoInstanceFun_Impl_case##case (typeName, superTypeName, __VA_ARGS__)

#define Cbject_ClassTypeInfoInstanceFun_Impl_x(typeName, superTypeName, ...) \
    Cbject_ClassTypeInfoInstanceFun_Impl_switch(typeName, superTypeName, __VA_ARGS__)

#define Cbject_ClassTypeInfoInstanceFun_Impl(typeName, superTypeName, bindFuns) \
    Cbject_ClassTypeInfoInstanceFun_Impl_x(typeName, superTypeName, Cbject_Utils_unpack(bindFuns))

#endif // CBJECT_CLASSTYPEINFOINSTANCEFUN_H
